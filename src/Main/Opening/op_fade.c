#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sOpFade; // puGpffffb6cc

// FUN_00271d70
void opFade00271d70(void)
{
    K_ASSERT(sOpFade != NULL, 0x1f);
    sOpFade = NULL;
}

// FUN_00271db0
void opFade00271db0(void)
{
    u32* work;

    K_ASSERT(sOpFade != NULL, 0x1f);
    work = sOpFade;
    work[3] = 0;
    work[1] = 1;
    *work |= 1;
}

// FUN_00271e10
void opFade00271e10(void)
{
    u32* work;

    K_ASSERT(sOpFade != NULL, 0x1f);
    work = sOpFade;
    work[3] = 0;
    work[1] = 2;
    *work |= 1;
}

// FUN_00271e70
u32 opFade00271e70(void)
{
    K_ASSERT(sOpFade != NULL, 0x1f);
    return *sOpFade & 1;
}

// FUN_00272290
void opFade00272290(void)
{
    u32* work;

    K_ASSERT(sOpFade != NULL, 0x1f);
    work = sOpFade;
    work[1] = 1;
    work[3] = work[2];
}

// FUN_002722e0
void opFade002722e0(void)
{
    u32* work;

    K_ASSERT(sOpFade != NULL, 0x1f);
    work = sOpFade;
    work[1] = 2;
    work[3] = work[2];
}
