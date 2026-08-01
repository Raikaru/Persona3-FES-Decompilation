#include "mw_harvest_compat.h"
/*
 * See src/lib/sce/libm/sf_tan.c for the measured ee-gcc provenance and
 * wrapper-family floor analysis retained for these vendor libm translation units.
 */







#pragma tailcall off
#pragma optimization_level 2
// FUN_0052EA78 NONMATCHING
u64 FUN_0052ea78(long param_1, long param_2)
{
    return param_1 * param_2;
}
