#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sOpLogo; // puGpffffb6c0

// FUN_00269cc0
void opLogo00269cc0(u32* param_1)
{
    K_ASSERT(sOpLogo == NULL, 0x33);
    *param_1 = 0;
    sOpLogo = param_1;
}

// FUN_00269d10
void opLogo00269d10(void)
{
    K_ASSERT(sOpLogo != NULL, 0x2c);
    sOpLogo = NULL;
}

// FUN_0026a1e0
u32 opLogo0026a1e0(void)
{
    K_ASSERT(sOpLogo != NULL, 0x2c);
    return *sOpLogo & 1;
}
