#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBpDialog368; // 007ce368

// FUN_0025c190
u32 bpDialog0025c190(void)
{
    K_ASSERT(sBpDialog368 != NULL, 0x3c);
    return *sBpDialog368 & 2;
}

// FUN_0025c1e0
u32 bpDialog0025c1e0(void)
{
    K_ASSERT(sBpDialog368 != NULL, 0x3c);
    return sBpDialog368[4];
}

void FUN_003b0170();

// FUN_0025bdf0
void bpDialog0025bdf0(u32* param_1)
{
    *param_1 = 0;
    sBpDialog368 = param_1;
}

// FUN_0025be00
void bpDialog0025be00(void)
{
    K_ASSERT(sBpDialog368 != NULL, 0x3c);
    if (*sBpDialog368 & 1) {
        FUN_003b0170(sBpDialog368[1]);
    }
    sBpDialog368 = NULL;
}

// FUN_0025c110
void bpDialog0025c110(void)
{
    u32* puVar1;

    K_ASSERT(sBpDialog368 != NULL, 0x3c);
    puVar1 = sBpDialog368;
    K_ASSERT((*sBpDialog368 & 1) != 0, 0xa7);
    *puVar1 |= 8;
}
