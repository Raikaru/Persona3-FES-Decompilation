#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBpDialog368; // 007ce368
static u32* sBpDialog36c; // 007ce36c

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

// FUN_0025cf00
void bpDialog0025cf00(u32* param_1)
{
    *param_1 = 0;
    sBpDialog36c = param_1;
}
