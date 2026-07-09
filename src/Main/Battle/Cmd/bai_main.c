#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBaiMain; // DAT_007ce338

// FUN_0024d0c0
u32 baiMain0024d0c0(void)
{
    K_ASSERT(sBaiMain != NULL, 0x37);
    return sBaiMain[1] & 1;
}
