#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBrRes; // puGpffffb61c

// FUN_00233970
void brRes00233970(u32* param_1)
{
    K_ASSERT(sBrRes == NULL, 0x58);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    sBrRes = param_1;
}

// FUN_00233ad0
u32 brRes00233ad0(void)
{
    K_ASSERT(sBrRes != NULL, 0x52);
    return *sBrRes & 1;
}
