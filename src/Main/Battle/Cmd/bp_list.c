#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBpList63c; // puGpffffb63c

// FUN_0024a6c0
void bpList0024a6c0(u32* param_1)
{
    *param_1 = 0;
    sBpList63c = param_1;
}

// FUN_0024a6d0
void bpList0024a6d0(void)
{
    sBpList63c = NULL;
}
