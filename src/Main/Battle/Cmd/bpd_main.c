#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBpd660; // puGpffffb660

// FUN_00252e60
void bpd00252e60(u32* param_1)
{
    *param_1 = 0;
    param_1[0x2d5] = 0;
    sBpd660 = param_1;
}

// FUN_00252e90
void bpd00252e90(void)
{
    K_ASSERT(sBpd660 != NULL, 0x25);
    *sBpd660 |= 1;
}

// FUN_00252ee0
void bpd00252ee0(void)
{
    K_ASSERT(sBpd660 != NULL, 0x25);
    *sBpd660 &= ~1;
}
