#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sSflCount; // puGpffffb674

// FUN_0025b4a0
void sflCount0025b4a0(u32* param_1)
{
    *param_1 = 0;
    sSflCount = param_1;
}

// FUN_0025b5f0
void sflCount0025b5f0(void)
{
    u32* work;

    K_ASSERT(sSflCount != NULL, 0x2b);
    work = sSflCount;
    work[2] = 0;
    *work |= 2;
}
