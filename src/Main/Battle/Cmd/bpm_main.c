#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#pragma alias bpcInit FUN_00248490
#pragma alias bpmUpdate FUN_00249180


static u32* sBpmWork; // puGpffffb634
extern u32* sBpc324; // 007ce324 / GP -0x49CC

// FUN_00248490
void bpcInit(u32* param_1)
{
    *param_1 = 0;
    sBpc324 = param_1;
}

void FUN_002491f0();

// FUN_00249180
void bpmUpdate(void)
{
    u32* work;

    K_ASSERT(sBpmWork != NULL, 0x3d);
    work = sBpmWork;
    if (*work & 1)
    {
        FUN_002491f0();
        *work &= ~1;
    }
}
