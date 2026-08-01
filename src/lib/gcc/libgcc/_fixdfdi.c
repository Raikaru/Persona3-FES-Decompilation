#include "mw_harvest_compat.h"
/*
 * See src/lib/sce/libm/sf_tan.c for the measured ee-gcc provenance and
 * wrapper-family floor analysis retained for these vendor libm translation units.
 */

extern long FUN_0052ec28(u64 param_1);
#pragma alias FUN_005311c8_u64 FUN_005311c8
extern u64 FUN_005311c8_u64(u64, u64);
#pragma alias FUN_005316d0_u64 FUN_005316d0
extern s64 FUN_005316d0_u64(u64, u64);






#pragma optimization_level 2
// FUN_0052ED30 NONMATCHING
long FUN_0052ed30(u64 param_1)
{
    long lVar1;
    u64 uVar2;
    long zero;
    u64 input;

    zero = 0;
    input = param_1;
    lVar1 = FUN_005316d0_u64(input, zero);
    if (-1 < lVar1)
    {
        lVar1 = FUN_0052ec28(input);
        return lVar1;
    }
    uVar2 = FUN_005311c8_u64(zero, input);
    lVar1 = FUN_0052ec28(uVar2);
    return -lVar1;
}
