#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBrHero; // puGpffffb68c

void FUN_002630e0();
void FUN_003b0170();

// FUN_002626e0
void brHero002626e0(u32* param_1)
{
    K_ASSERT(sBrHero == NULL, 0x59);
    *param_1 = 0;
    sBrHero = param_1;
}

// FUN_00262730
void brHero00262730(void)
{
    K_ASSERT(sBrHero != NULL, 0x53);
    if (*sBrHero & 1) {
        FUN_002630e0();
    }
    sBrHero = NULL;
}

// FUN_002630e0
void brHero002630e0(void)
{
    u32* work;

    K_ASSERT(sBrHero != NULL, 0x53);
    work = sBrHero;
    K_ASSERT(*work & 1, 0x19a);
    FUN_003b0170(work[0xad4]);
    *work &= 0xfffffffe;
}
