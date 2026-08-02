#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#pragma alias brPersonaInit FUN_00264d80
#pragma alias brPersonaShutdown FUN_00264dd0
#pragma alias brPersonaDestroy FUN_00264f90
#pragma alias brPersonaGetResource FUN_00264ff0
#pragma alias brPersonaLoad FUN_00264e30
#pragma alias brPersonaSetPersona FUN_00264ef0
#pragma alias brPersonaGetPortraitFrame FUN_00264ca0


static u32* sBrPersona; // DAT_007ce380

void brPersonaDestroy();
u32 FUN_001749a0();
u32 FUN_003c9850(int param_1, int param_2, u16 param_3, u16 param_4);
void FUN_003c9b00();
void FUN_003c9cd0();
void FUN_003c9d00(u32 param_1, u32 param_2);

// FUN_00264d80
void brPersonaInit(u32* param_1)
{
    K_ASSERT(sBrPersona == NULL, 0x2d);
    *param_1 = 0;
    sBrPersona = param_1;
}

// FUN_00264dd0
void brPersonaShutdown(void)
{
    K_ASSERT(sBrPersona != NULL, 0x27);
    if (*sBrPersona & 1) {
        brPersonaDestroy();
    }
    sBrPersona = NULL;
}

// FUN_00264e30
void brPersonaLoad(int param_1)
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
void brPersonaSetPersona(int param_1)
{
    u32* work;
    u32 uVar2;

    K_ASSERT(sBrPersona != NULL, 0x27);
    work = sBrPersona;
    K_ASSERT(*(u16*)((int)work + 8) != (u16)param_1, 0x59);
    uVar2 = FUN_001749a0(param_1);
    FUN_003c9b00(work[1], uVar2, 0);
}

// FUN_00264f90
void brPersonaDestroy(void)
{
    u32* work;

    K_ASSERT(sBrPersona != NULL, 0x27);
    work = sBrPersona;
    kwlnTaskDestroyWithHierarchy((KwlnTask*)work[1]);
    *work &= 0xfffffffe;
}

// FUN_00264ff0
u32 brPersonaGetResource(void)
{
    K_ASSERT(sBrPersona != NULL, 0x27);
    return sBrPersona[1];
}
