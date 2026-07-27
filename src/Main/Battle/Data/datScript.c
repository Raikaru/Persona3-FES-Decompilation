#include "Main/Battle/Data/datScript.h"
#include "Kosaka/k_assert.h"
#pragma alias datScriptIsCurrent FUN_003112c0
#pragma alias datScriptSetCalculationResult FUN_00311190
#pragma alias datScriptReturnTrueCommand FUN_003111C0
#pragma alias datScriptRestorePartyCommand FUN_003112E0


static ScrData* sUnk_007ce514; // doesn't looks like it's used

// FUN_003112c0
u8 datScriptIsCurrent(ScrData* scr)
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

/* ---- Straggler recovery: 0x311190-0x3112E0 ---- */
extern u16 DAT_009571a4;
extern u32 DAT_00957198;
extern void FUN_0035f060(u32 value);
extern void FUN_0030c440(void);
#pragma optimization_level 1
// FUN_00311190
void datScriptSetCalculationResult(u32 param_1)

{
  *(u16*)0x009571a4 = *(u16*)0x009571a4 | 1;
  *(u32*)0x00957198 = param_1;
  return;
}
#pragma optimization_level 2

// FUN_003111C0
u32 datScriptReturnTrueCommand(void)

{
  FUN_0035f060(1);
  return 1;
}

// FUN_003112E0
u32 datScriptRestorePartyCommand(void)

{
  FUN_0030c440();
  return 1;
}
