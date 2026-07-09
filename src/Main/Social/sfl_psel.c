#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sSflPsel; // puGpffffb688

// FUN_00260a10
void sflPsel00260a10(void)
{
    K_ASSERT(sSflPsel != NULL, 0x57);
    sSflPsel = NULL;
}

// FUN_00260bd0
void sflPsel00260bd0(void)
{
    K_ASSERT(sSflPsel != NULL, 0x57);
    *sSflPsel &= 0xfffffffe;
}

// FUN_00260c20
void sflPsel00260c20(void)
{
    u32* work;

    K_ASSERT(sSflPsel != NULL, 0x57);
    work = sSflPsel;
    work[2] = 0;
    work[1] = 0;
    *work |= 2;
}

// FUN_00260c70
void sflPsel00260c70(void)
{
    u32* work;

    K_ASSERT(sSflPsel != NULL, 0x57);
    work = sSflPsel;
    work[2] = 0;
    work[1] = 1;
    *work |= 2;
}

// FUN_00260cd0
u32 sflPsel00260cd0(void)
{
    K_ASSERT(sSflPsel != NULL, 0x57);
    return *sSflPsel & 2;
}
