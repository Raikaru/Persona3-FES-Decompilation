#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBrRes; // puGpffffb61c
extern char DAT_0068e6b0[];
extern char DAT_0068e6d0[];
extern char DAT_0068e6f0[];
extern char DAT_0068e710[];
extern char DAT_0068e730[];
extern char DAT_0068e750[];
extern char DAT_0068e770[];
int FUN_0017d800();
int FUN_0016f190();
u32 FUN_00100d80();

// FUN_00233970
void brRes00233970(u32* param_1)
{
    K_ASSERT(sBrRes == NULL, 0x58);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    sBrRes = param_1;
}

// FUN_00233ad0
u32 brRes00233ad0(void)
{
    K_ASSERT(sBrRes != NULL, 0x52);
    return *sBrRes & 1;
}

// FUN_002339d0
void brRes002339d0(void)
{
    u32* puVar1;
    int lVar3;

    K_ASSERT(sBrRes != NULL, 0x52);
    puVar1 = sBrRes;
    K_ASSERT((~*puVar1 & 1) != 0, 0x65);
    lVar3 = FUN_0017d800();
    if (lVar3 != 0) {
        lVar3 = FUN_0016f190(0x2f0);
        if (lVar3 != 0) {
            puVar1[3] = FUN_00100d80(DAT_0068e6b0, 1);
        } else {
            puVar1[3] = FUN_00100d80(DAT_0068e6d0, 1);
        }
    } else {
        puVar1[3] = FUN_00100d80(DAT_0068e6f0, 1);
    }
    *puVar1 |= 1;
}

// FUN_00233b20
void brRes00233b20(void)
{
    u32* puVar1;

    K_ASSERT(sBrRes != NULL, 0x52);
    puVar1 = sBrRes;
    K_ASSERT((~*puVar1 & 2) != 0, 0x7e);
    puVar1[4] = FUN_00100d80(DAT_0068e710, 1);
    *puVar1 |= 2;
}

// FUN_00233bb0
u32 brRes00233bb0(void)
{
    K_ASSERT(sBrRes != NULL, 0x52);
    return *sBrRes & 2;
}

// FUN_00233c00
void brRes00233c00(void)
{
    u32* puVar1;
    int lVar3;

    K_ASSERT(sBrRes != NULL, 0x52);
    puVar1 = sBrRes;
    K_ASSERT((~*puVar1 & 4) != 0, 0x8c);
    K_ASSERT((~puVar1[1] & 0x10) != 0, 0x8d);
    lVar3 = FUN_0017d800();
    if (lVar3 != 0) {
        lVar3 = FUN_0016f190(0x2f0);
        if (lVar3 != 0) {
            puVar1[5] = FUN_00100d80(DAT_0068e730, 1);
        } else {
            puVar1[5] = FUN_00100d80(DAT_0068e750, 1);
        }
    } else {
        puVar1[5] = FUN_00100d80(DAT_0068e770, 1);
    }
    *puVar1 |= 4;
}
