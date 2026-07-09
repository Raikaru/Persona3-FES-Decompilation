#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sSflPanel; // DAT_007ce318

// FUN_0023d870
void sflPanel0023d870(void)
{
    u32* work;

    K_ASSERT(sSflPanel != NULL, 0x7f);
    work = sSflPanel;
    K_ASSERT(*work & 1, 0xa3);
    *work &= 0xfffffffe;
}

// FUN_0023f390
u32 sflPanel0023f390(void)
{
    K_ASSERT(sSflPanel != NULL, 0x7f);
    return *sSflPanel & 2;
}

// FUN_0023f3e0
void sflPanel0023f3e0(void)
{
    K_ASSERT(sSflPanel != NULL, 0x7f);
    *sSflPanel |= 8;
}

// FUN_0023f430
void sflPanel0023f430(void)
{
    K_ASSERT(sSflPanel != NULL, 0x7f);
    *sSflPanel &= 0xfffffff7;
}
