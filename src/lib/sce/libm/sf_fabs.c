#include "mw_harvest_compat.h"
#include "libm.h"
/*
 * See src/lib/sce/libm/sf_tan.c for the measured ee-gcc provenance and
 * wrapper-family floor analysis retained for these vendor libm translation units.
 */




#pragma optimization_level 2

#pragma intrinsic fabsf
// FUN_0052e788 NONMATCHING
float fabsf(register float x)
{
    return fabsf(x);
}
