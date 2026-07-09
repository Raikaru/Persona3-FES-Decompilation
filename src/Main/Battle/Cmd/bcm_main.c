#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u8* sBcmWork; // 007ce2e8

s32 FUN_0017d2e0();

// FUN_00207930
u32 bcm00207930(u16 param_1)
{
    return FUN_0017d2e0(param_1) != 0xc;
}

// FUN_00207a10
void bcm00207a10(void)
{
    K_ASSERT(sBcmWork != NULL, 0x164);
    *(u32*)(sBcmWork + 0x77a0) |= 2;
}

// FUN_00207bf0
void bcm00207bf0(void)
{
    K_ASSERT(sBcmWork != NULL, 0x164);
    *(u32*)(sBcmWork + 0x77a0) &= ~1;
}

void FUN_00208360();

// FUN_00201ad0
void bcm00201ad0(void)
{
    FUN_00208360();
}

void FUN_003b0170();

// FUN_00203360
void bcm00203360(void)
{
    u32* puVar1;
    int iVar2;

    K_ASSERT(sBcmWork != NULL, 0x164);
    puVar1 = (u32*)sBcmWork;
    for (iVar2 = 0; iVar2 < (int)puVar1[0x97]; iVar2++) {
        FUN_003b0170(*(u32*)((int)puVar1 + iVar2 * 4 + 0x8c));
    }
    if ((*puVar1 & 0x20) != 0) {
        FUN_003b0170(puVar1[0x99]);
    }
    *puVar1 &= 0xfffffffb;
}
