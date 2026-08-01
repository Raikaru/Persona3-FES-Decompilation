#include "mw_harvest_compat.h"
#include "libm.h"
/*
 * See src/lib/sce/libm/sf_tan.c for the measured ee-gcc provenance and
 * wrapper-family floor analysis retained for these vendor libm translation units.
 */




#pragma optimization_level 2

#pragma intrinsic fabsf
/* Retail decode: mfc1 t6,f12; lui/ori t7,0x7fffffff; and t6,t6,t7;
 * jr ra; mtc1 t6,f0. MWCCPS2 b210's fabsf intrinsic emits abs.s, while
 * every C bit-reinterpretation form spills through the stack and cannot
 * produce mfc1/mtc1; this is the same ee-gcc libm floor as sf_tan. */
// FUN_0052e788 NONMATCHING
float fabsf(register float x)
{
    return fabsf(x);
}
