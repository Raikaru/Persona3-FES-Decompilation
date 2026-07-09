#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBrpResWork; // puGpffffb644

// FUN_0024ba30
void brpRes0024ba30(u32* param_1)
{
    *param_1 = 0;
    param_1[1] = 0;
    sBrpResWork = param_1;
}
