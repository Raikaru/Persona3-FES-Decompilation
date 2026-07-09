#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBpPersona; // DAT_007ce398

void FUN_00267120();
void FUN_00195020();
long FUN_003c9ab0();

// FUN_00266eb0
void bpPersona00266eb0(u32* param_1)
{
    K_ASSERT(sBpPersona == NULL, 0x2b);
    *param_1 = 0;
    sBpPersona = param_1;
}

// FUN_00266f00
void bpPersona00266f00(void)
{
    K_ASSERT(sBpPersona != NULL, 0x24);
    if (*sBpPersona & 1) {
        FUN_00267120();
    }
    sBpPersona = NULL;
}

// FUN_00267120
void bpPersona00267120(void)
{
    u32* work;

    K_ASSERT(sBpPersona != NULL, 0x24);
    work = sBpPersona;
    FUN_00195020(work[1]);
    *work &= 0xfffffffe;
}

// FUN_00267180
void bpPersona00267180(void)
{
    u32* work;

    K_ASSERT(sBpPersona != NULL, 0x24);
    work = sBpPersona;
    if ((~*work & 1) == 0 && (*work & 2) != 0 && FUN_003c9ab0(work[1]) != 0) {
        *work &= 0xfffffffd;
    }
}

// FUN_00267210
u32 bpPersona00267210(void)
{
    K_ASSERT(sBpPersona != NULL, 0x24);
    return *sBpPersona & 2;
}
