#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBrPersona; // DAT_007ce380

void FUN_00264f90();
void FUN_00195020();
u32 FUN_001749a0();
u32 FUN_003c9850();
void FUN_003c9b00();
void FUN_003c9cd0();
void FUN_003c9d00();

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

// FUN_00264e30
void brPersona00264e30(int param_1)
{
    u32* puVar1;
    u32 uVar2;
    u32 uVar3;

    K_ASSERT(sBrPersona != NULL, 0x27);
    puVar1 = sBrPersona;
    *(u16*)((int)puVar1 + 8) = (u16)param_1;
    uVar2 = FUN_001749a0(param_1);
    uVar3 = FUN_003c9850(0, 0, 0, 0);
    puVar1[1] = uVar3;
    FUN_003c9b00(uVar3, uVar2, 0);
    FUN_003c9cd0(puVar1[1], -1);
    FUN_003c9d00(puVar1[1], 8);
    *puVar1 |= 1;
}

// FUN_00264ef0
void brPersona00264ef0(int param_1)
{
    u32* work;
    u32 uVar2;

    K_ASSERT(sBrPersona != NULL, 0x27);
    work = sBrPersona;
    K_ASSERT(*(u16*)((int)work + 8) != (u16)param_1, 0x59);
    uVar2 = FUN_001749a0(param_1);
    FUN_003c9b00(work[1], uVar2, 0);
}
