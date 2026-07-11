#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBrPersona; // DAT_007ce380

void FUN_00264f90();
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
    kwlnTaskDestroyWithHierarchy((KwlnTask*)work[1]);
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
// FUN_00264ca0
u32 brPersona00264ca0(u32 personaId)
{
    u32 table;
    u32 resource;

    table = FUN_00233d70(1);
    switch (personaId)
    {
        case 0: resource = 0x0b; break;
        case 1: resource = 0x0d; break;
        case 2: resource = 0x0c; break;
        case 3: resource = 0x10; break;
        case 4: resource = 0x0e; break;
        case 5: resource = 0x0f; break;
        default:
            K_ASSERT(false, 0x4a4);
    }
    return FUN_0021cca0(table, resource);
}
