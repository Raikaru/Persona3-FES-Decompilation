#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBpo65c; // puGpffffb65c

// FUN_00251f20
void bpo00251f20(u32* param_1)
{
    *param_1 = 0;
    sBpo65c = param_1;
}

// FUN_00251f30
void bpo00251f30(void)
{
    sBpo65c = NULL;
}
