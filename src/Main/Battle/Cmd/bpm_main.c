#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBpmWork; // puGpffffb634

void FUN_002491f0();

// FUN_00249180
void bpm00249180(void)
{
    u32* work;

    K_ASSERT(sBpmWork != NULL, 0x3d);
    work = sBpmWork;
    if (*work & 1)
    {
        FUN_002491f0();
        *work &= ~1;
    }
}
