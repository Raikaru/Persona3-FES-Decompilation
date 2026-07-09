#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sOpTitle; // DAT_007ce3ac / puGpffffb6bc

// FUN_002673a0
void opTitle002673a0(u32* param_1)
{
    K_ASSERT(sOpTitle == NULL, 0x95);
    *param_1 = 0;
    sOpTitle = param_1;
}

// FUN_002673f0
void opTitle002673f0(void)
{
    K_ASSERT(sOpTitle != NULL, 0x8e);
    sOpTitle = NULL;
}

// FUN_002694b0
void opTitle002694b0(void)
{
    K_ASSERT(sOpTitle != NULL, 0x8e);
    *sOpTitle &= 0xfffffffe;
}

// FUN_00269500
void opTitle00269500(void)
{
    u32* work;

    K_ASSERT(sOpTitle != NULL, 0x8e);
    work = sOpTitle;
    work[1] = 0;
    work[2] = 0;
    *work |= 4;
}

// FUN_00269550
void opTitle00269550(void)
{
    u32* work;

    K_ASSERT(sOpTitle != NULL, 0x8e);
    work = sOpTitle;
    work[1] = 0;
    work[2] = 1;
    *work |= 4;
}

// FUN_00269640
u32 opTitle00269640(void)
{
    K_ASSERT(sOpTitle != NULL, 0x8e);
    return *sOpTitle & 4;
}
