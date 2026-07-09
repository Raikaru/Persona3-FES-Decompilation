#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBpc324; // 007ce324

// FUN_00248490
void bpc00248490(u32* param_1)
{
    *param_1 = 0;
    sBpc324 = param_1;
}
