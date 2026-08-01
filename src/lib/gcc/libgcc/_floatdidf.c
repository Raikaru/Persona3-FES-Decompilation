#include "mw_harvest_compat.h"
/*
 * See src/lib/sce/libm/sf_tan.c for the measured ee-gcc provenance and
 * wrapper-family floor analysis retained for these vendor libm translation units.
 */

#pragma alias FUN_00531170_u64 FUN_00531170
extern u64 FUN_00531170_u64(u64, u64);
#pragma alias FUN_00531230_u64 FUN_00531230
extern u64 FUN_00531230_u64(u64, u64);
#pragma alias FUN_00531720_u64 FUN_00531720
extern u64 FUN_00531720_u64(u32);






#pragma optimization_level 2
#pragma optimization_level 3
// FUN_0052EAC8 NONMATCHING
u64 FUN_0052eac8(s64 u)
{
    u64 high;
    u64 low;

    high = FUN_00531720_u64((u32)(u >> 0x20));
    high = FUN_00531230_u64(high, 0x40F0000000000000ULL);
    high = FUN_00531230_u64(high, 0x40F0000000000000ULL);
    low = FUN_00531720_u64((u32)u);
    if ((s32)u < 0)
        low = FUN_00531170_u64(low, 0x41F0000000000000ULL);
    return FUN_00531170_u64(high, low);
}
