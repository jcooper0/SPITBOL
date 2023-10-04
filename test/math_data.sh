#!/bin/bash
 gcc -mfpmath=sse -mieee-fp -mlong-double-64 -ffloat-store -o math_data math_data.cpp -lm
 ./math_data > math_data.txt
