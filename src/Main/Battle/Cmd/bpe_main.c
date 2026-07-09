#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBpeWork; // puGpffffb638

void FUN_003c77a0();

// FUN_00249240
void bpe00249240(u32* param_1)
{
    *param_1 = 0;
    sBpeWork = param_1;
}

// FUN_00249250
void bpe00249250(void)
{
    K_ASSERT(sBpeWork != NULL, 0x37);
    if (*sBpeWork & 1)
    {
        FUN_003c77a0();
    }
    sBpeWork = NULL;
}

// FUN_00249600
u32 bpe00249600(void)
{
    K_ASSERT(sBpeWork != NULL, 0x37);
    return *sBpeWork & 1;
}
