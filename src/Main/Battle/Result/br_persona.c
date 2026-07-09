#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBrPersona; // DAT_007ce380

void FUN_00264f90();
void FUN_00195020();

// FUN_00264d80
void brPersona00264d80(u32* param_1)
{
    K_ASSERT(sBrPersona == NULL, 0x2d);
    *param_1 = 0;
    sBrPersona = param_1;
}

// FUN_00264dd0
void brPersona00264dd0(void)
{
    K_ASSERT(sBrPersona != NULL, 0x27);
    if (*sBrPersona & 1) {
        FUN_00264f90();
    }
    sBrPersona = NULL;
}

// FUN_00264f90
void brPersona00264f90(void)
{
    u32* work;

    K_ASSERT(sBrPersona != NULL, 0x27);
    work = sBrPersona;
    FUN_00195020(work[1]);
    *work &= 0xfffffffe;
}

// FUN_00264ff0
u32 brPersona00264ff0(void)
{
    K_ASSERT(sBrPersona != NULL, 0x27);
    return sBrPersona[1];
}
