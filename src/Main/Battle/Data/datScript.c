#include "Main/Battle/Data/datScript.h"
#include "Kosaka/k_assert.h"

static ScrData* sUnk_007ce514; // doesn't looks like it's used

// FUN_003112c0
u8 datScript003112c0(ScrData* scr)
{
    return sUnk_007ce514 == scr;
}

extern u16* DAT_00957190[]; // 0x957190

// FUN_003111f0
u32 datScript003111f0(void)
{
    K_ASSERT(DAT_00957190[0] != NULL, 0x205);
    return !(*DAT_00957190[0] & 4);
}

extern u16 DAT_0095719c[]; // 0x95719c
static u8* sUnk_007ce3f8;  // iGpffffb708

// FUN_00311250
u32 datScript00311250(void)
{
    K_ASSERT(DAT_0095719c[0] < 0x1d0, 0x222);
    return (sUnk_007ce3f8[DAT_0095719c[0] * 0x2c] & 2) != 0;
}