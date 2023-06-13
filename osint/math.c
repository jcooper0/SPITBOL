/*
Copyright 1987-2012 Robert B. K. Dewar and Mark Emmer.
Copyright 2012-2017 David Shields
*/

/*
 * math.c - extended math support for spitbol
 *
 * Routines not provided by hardware floating point.
 *
 * These routines are not called from other C routines.  Rather they
 * are called by inter.*, and by external functions.
 */

#include "port.h"
#include <errno.h>

#if FLOAT & !MATHHDWR

#include <math.h>
#include <fenv.h>

#ifndef errno
int errno;
#endif

#define FE_SBL_EXCEPT (FE_INVALID | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW )

extern double inf;	// infinity
extern word reg_flerr;	/* Floating point error */

/*
 * f_atn - arctangent
 */
void f_atn()
{
    feclearexcept(FE_ALL_EXCEPT);
    reg_ra = atan(reg_ra);
    reg_flerr = fetestexcept(FE_SBL_EXCEPT);
}

/*
 * f_chp - chop
 */
void f_chp()
{
    feclearexcept(FE_ALL_EXCEPT);
    if (reg_ra >= 0.0)
        reg_ra =  floor(reg_ra);
    else
        reg_ra =  ceil(reg_ra);
    reg_flerr = fetestexcept(FE_SBL_EXCEPT);
}

/*
 * f_cos - cosine
 */
void f_cos()
{
    feclearexcept(FE_ALL_EXCEPT);
    reg_ra =  cos(reg_ra);
    reg_flerr = fetestexcept(FE_SBL_EXCEPT);
}


/*
 * f_etx - e to the x
 */
void f_etx()
{
    errno = 0;
    feclearexcept(FE_ALL_EXCEPT);
    reg_ra = exp(reg_ra);
    if (errno) {
        reg_ra = inf;
    }
    reg_flerr = fetestexcept(FE_SBL_EXCEPT);
}

/*
 * f_lnf - natureg_ral log
 */
void f_lnf()
{
    errno = 0;
    feclearexcept(FE_ALL_EXCEPT);

    reg_ra = log(reg_ra);
    if (errno) {
        reg_ra = inf;
    }
    reg_flerr = fetestexcept(FE_SBL_EXCEPT);
}

/*
 * f_sin - sine
 */
void f_sin()
{
    feclearexcept(FE_ALL_EXCEPT);
    reg_ra = sin(reg_ra);
    reg_flerr = fetestexcept(FE_SBL_EXCEPT);
}

/*
 * f_sqr - square root  (reg_range checked by caller)
 */
void f_sqr()
{
    feclearexcept(FE_ALL_EXCEPT);
    reg_ra = sqrt(reg_ra);
    reg_flerr = fetestexcept(FE_SBL_EXCEPT);
}

/*
 * f_tan - tangent
 */
void f_tan()
{
    double result;
    feclearexcept(FE_ALL_EXCEPT);
    result = tan(reg_ra);
    errno = 0;
    reg_ra = errno ? inf : result;
    reg_flerr = fetestexcept(FE_SBL_EXCEPT);
}
#endif					// FLOAT & !MATHHDWR
