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