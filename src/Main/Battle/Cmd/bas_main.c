#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBasWork; // puGpffffb63c

void FUN_001fe580();

// FUN_0024a6c0
void bas0024a6c0(u32* param_1)
{
    *param_1 = 0;
    sBasWork = param_1;
}

// FUN_0024a6d0
void bas0024a6d0(void)
{
    sBasWork = NULL;
}

// FUN_0024a6e0
void bas0024a6e0(u32 param_1)
{
    u32* work;

    K_ASSERT(sBasWork != NULL, 0x1d);
    work = sBasWork;
    FUN_001fe580(param_1);
    work[1] = param_1;
    *work |= 1;
}

// FUN_0024a750
u32 bas0024a750(void)
{
    K_ASSERT(sBasWork != NULL, 0x1d);
    return *sBasWork & 1;
}

// FUN_0024a7a0
void bas0024a7a0(void)
{
    K_ASSERT(sBasWork != NULL, 0x1d);
    *sBasWork &= ~1;
}
