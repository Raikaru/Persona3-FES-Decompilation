#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBppMain; // DAT_007ce2f4

// FUN_0020fc40
void bppMain0020fc40(void)
{
    K_ASSERT(sBppMain != NULL, 0x43);
    *sBppMain |= 0x10;
}

// FUN_0020fc90
void bppMain0020fc90(void)
{
    K_ASSERT(sBppMain != NULL, 0x43);
    *sBppMain &= 0xffffffef;
}
