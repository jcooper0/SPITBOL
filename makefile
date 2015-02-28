# SPITBOL makefile using tcc
host?=unix_64
HOST=$(host)

DEBUG:=$(debug)

debug?=0

gas?=as
GAS:=$(gas)

nasm?=nasm
NASM:=$(nasm)

os?=unix
OS:=$(os)

ws?=64
WS=$(ws)

TARGET=$(OS)_$(WS)

it?=0
IT:=$(it)
ifneq ($(IT),0)
ITOPT:=:it
ITDEF:=-Dit_trace
endif

NMFLAGS:=-p
# basebol determines which spitbol to use to compile
spitbol?=./bin/spitbol.$(HOST)

BASEBOL:=$(spitbol)

cc?=gcc
CC:=$(cc)

ifeq	($(DEBUG),1)
GFLAG=-g
endif

ARCH=-D$(TARGET)  -m$(WS)

CCOPTS:= $(ARCH) $(ITDEF) $(GFLAG) 
LDOPTS:= -lm $(GFLAG) $(ARCH)
LMOPT:=-lm

GASOPTS= --$(WS)

ifeq ($(OS),unix)
ELF:=elf$(WS)
else
EL:F=macho$(WS)
endif

# spitbol source file
MIN=s

OSINT=./osint

vpath %.c $(OSINT)

# Assembler info -- Intel 32-bit syntax
ifeq	($(DEBUG),0)
NASMOPTS = -f $(ELF) -D$(TARGET) $(ITDEF)
ASMOPTS = -f $(ELF) -D$(TARGET) $(ITDEF)
else
NASMOPTS = -g -f $(ELF) -D$(TARGET) $(ITDEF)
ASMOPTS = -g -f $(ELF) -D$(TARGET) $(ITDEF)
endif

# tools for processing Minimal source file.
LEX=	lex.sbl
ERR=    err.sbl

# implicit rule for building objects from C files.
./%.o: %.c
#.c.o:
	$(CC)  $(CCOPTS) -c  -o$@ $(OSINT)/$*.c

# implicit rule for building objects from nasm assembly language files.
.asm.o:
	$(NASM) $(ASMOPTS) -l $*.lst -o$@ $*.asm

# c headers common to all versions and all source files of SPITBOL:
CHDRS =	$(OSINT)/osint.h $(OSINT)/port.h $(OSINT)/sproto.h $(OSINT)/spitio.h $(OSINT)/spitblks.h $(OSINT)/globals.h 

# c headers unique to this version of SPITBOL:
UHDRS=	$(OSINT)/systype.h $(OSINT)/extern32.h $(OSINT)/blocks32.h $(OSINT)/system.h

# headers common to all C files.
HDRS=	$(CHDRS) $(UHDRS)

OBJS=sysax.o sysbs.o sysbx.o syscm.o sysdc.o sysdt.o sysea.o \
	sysef.o sysej.o sysem.o sysen.o sysep.o sysex.o sysfc.o \
	sysgc.o syshs.o sysid.o sysif.o sysil.o sysin.o sysio.o \
	sysld.o sysmm.o sysmx.o sysou.o syspl.o syspp.o sysrw.o \
	sysst.o sysstdio.o systm.o systty.o sysul.o sysxi.o  \
	break.o checkfpu.o compress.o cpys2sc.o \
	doset.o dosys.o fakexit.o float.o flush.o gethost.o getshell.o \
	int.o lenfnm.o math.o optfile.o osclose.o \
	osopen.o ospipe.o osread.o oswait.o oswrite.o prompt.o rdenv.o \
	st2d.o stubs.o swcinp.o swcoup.o syslinux.o testty.o\
	trypath.o wrtaout.o zz.o getargs.o it.o main.o 

GOBJS=s-gas.o s-gas-err.o gas-sys.o
AOBJS=s-asm.o s-asm-err.o asm-sys.o


# build spitbol using nasm, build spitbol using as.
# link asm spitbol with static linking
spitbol: $(OBJS) $(AOBJS)
	$(CC) $(LDOPTS)  $(OBJS) $(AOBJS) $(LMOPT) -static -ospitbol

# link spitbol with dynamic linking
spitbol-dynamic: $(OBJS) $(AOBJS)
	$(CC) $(LDOPTS) $(OBJS) $(AOBJS) $(LMOPT)  -ospitbol 

# build gasbol, the asm variant  targeting gas format assembler
# link gasbol with static linking
gasbol: $(OBJS) $(GOBJS) $(GOBJS)
	$(CC) $(LDOPTS) $(OBJS) $(GOBJS) $(LMOPT) -ogasbol

# link gasbol with dynamic linking
gasbol-dynamic: $(OBJS) $(GOBJS) $(GOBJS)
	$(CC) $(LDOPTS) $(OBJS) $(GOBJS) $(LMOPT)  -ogasbol 

# bootbol is for bootstrapping just link with what's at hand
#bootbol: $(OBJS)
# no dependencies so can link for osx bootstrap
bootbol: 
	$(CC) $(LDOPTS)  $(OBJS) $(LMOPT) -obootbol

s.lex: s.min s.cnd $(LEX)
	 $(BASEBOL) -u $(TARGET)_$(ASM) $(LEX)

# asm - nasm, the netwide assembler

asm-sys.o: asm-sys.s
	$(NASM) $(ASMOPTS) -oasm-sys.o asm-sys.s

asm.spt: asm.sbl
	$(BASEBOL) -u N pp.sbl <asm.sbl >asm.spt

s-asm.o: s-asm.s
	$(NASM) $(ASMOPTS) -os-asm.o s-asm.s

s-asm.s: s.lex asm.spt
	$(BASEBOL) -r -u $(TARGET):$(ITOPT) -1=s.lex -2=s-asm.s -3=s-asm-err.err -4=asm.hdr -6=s.equ	asm.spt

asm.hdr: s-asm.s asm.spt
#	touch s-asm.hdr.done
#	$(BASEBOL) -u $(TARGET) r.sbl <asm.hdr.r >asm.hdr
#	cp <asm.hdr.r >asm.hdr

s-asm-err.err: s.cnd $(ERR) s-asm.s
	touch s-asm-err.err

s-asm-err.s: s-asm-err.err
	$(BASEBOL) -u $(TARGET)_asm -1=s-asm-err.err -2=s-asm-err.s $(ERR)

s-asm-err.o: s-asm-err.s 
	$(NASM) $(ASMOPTS) -os-asm-err.o s-asm-err.s

# gas - GNU assembler 'as'
gas.spt: asm.sbl
	$(BASEBOL) -u G pp.sbl <asm.sbl >gas.spt

gas.h:	gas.h.r
	$(BASEBOL) -u $(TARGET) r.sbl <gas.h.r >gas.h

s-gas.asm: s.lex gas.sbl asm.sbl
	$(BASEBOL) -r -u $(TARGET):$(ITOPT) -1=s.lex -2=s-gas.gas -3=s-gas.err -4=gas.hdr.r -6=s.equ	gas.spt

gas.hdr: gas.hdr.r 
	$(BASEBOL) -u $(TARGET) r.sbl <gas.hdr.r >gas.hdr

s-gas-err.gas: s.cnd $(ERR) s-gas.gas
	$(BASEBOL) -u $(TARGET)_gas -1=s-gas.err -2=s-gas-err.gas $(ERR)

s-gas-err.o: s-gas-err.gas s-gas.gas
	$(GAS) $(GASOPTS) -os-gas-err.o s-gas-err.gas

s-gas.gas: s.lex gas.spt gas.hdr gas.h
	$(BASEBOL) -r -u $(TARGET):$(ITOPT) -1=s.lex -2=s-gas.tmp -3=s-gas.err -4=gas.hdr.r -5=s.lex -6=s.equ	gas.spt
	$(BASEBOL) -u $(TARGET) r.sbl <s-gas.tmp >s-gas.gas

s-gas.o: s-gas.gas
	$(GAS) $(GASOPTS) -os-gas.o s-gas.gas

gas-sys.gas: gas-sys.gas.r s.lex 
	$(BASEBOL) -u $(TARGET) r.sbl <gas-sys.gas.r >gas-sys.gas

gas-sys.o: gas-sys.gas gas.h
	$(GAS) $(GASOPTS) -ogas-sys.o gas-sys.gas

# c language header dependencies:

main.o: $(OSINT)/save.h

sysgc.o: $(OSINT)/save.h

sysxi.o: $(OSINT)/save.h

dlfcn.o: dlfcn.h

dic:
	nm -n s-nasm.o >s-nasm.nm
	spitbol test/map-$(WS).sbl <s-nasm.nm >s-nasm.dic
	spitbol it.sbl <ad >ae

# install binaries from ./bin as the system spitbol compilers
install:
	sudo cp ./bin/spitbol /usr/local/bin

clean:
	rm -f *.o s.lex s.equ [rs]-* ./asmbol ./gasbol ./spitbol gas.hdr gas.h gas-sys.gas 
	rm asm.spt gas.spt

s-gas.dic: s-gas.nm
	$(BASEBOL) test/map-$(WS).sbl <s-gas.nm >s-gas.dic

s-gas.nm: s-gas.o
	nm -n s-gas.o >s-gas.nm

it-gas:	s-gas.dic it.sbl
	$(BASEBOL) -u s-gas.dic it.sbl <ad >ae

s-nasm.dic: s-nasm.nm
	$(BASEBOL) test/map-$(WS).sbl <s-nasm.nm >s-nasm.dic

s-nasm.nm: s-nasm.o
	nm $(NMFLAGS) s-nasm.o >s-nasm.nm

it-nasm: s-nasm.dic it.sbl
	$(BASEBOL) -u s-nasm.dic it.sbl <ad >ae

sclean:
# clean up after sanity-check
	make clean
	rm tbol*
