#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u8* sBcmWork; // 007ce2e8

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

s32 FUN_0017d2e0();

// FUN_00207930
u32 bcm00207930(u16 param_1)
{
    return FUN_0017d2e0(param_1) != 0xc;
}

// FUN_0020ac80
void bcm0020ac80(void)
{
}
