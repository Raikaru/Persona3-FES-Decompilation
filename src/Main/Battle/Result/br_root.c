#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBrRoot; // iGpffffb5e8 / puGpffffb5e8

void FUN_00233b20();
void FUN_001f30f0();
void FUN_002339d0();

// FUN_001f1c50
int brRoot001f1c50(void)
{
    K_ASSERT(sBrRoot != NULL, 0x755);
    return (int)sBrRoot;
}

// FUN_001f1df0
void brRoot001f1df0(int param_1, int* param_2)
{
    int i;
    u32* p;

    K_ASSERT(sBrRoot != NULL, 0x755);
    p = sBrRoot;
    *(u16*)param_1 = 1;
    for (i = 0; i < *(int*)((int)p + 0x114); i++) {
        *(u16*)(param_1 + i * 2 + 2) = *(u16*)((int)p + i * 2 + 0x10c);
    }
    *param_2 = *(int*)((int)p + 0x114) + 1;
}

// FUN_001f1b60
void brRoot001f1b60(int param_1)
{
    u32* puVar1;
    u32* puVar2;
    int iVar3;

    puVar1 = *(u32**)(param_1 + 0x3c);
    K_ASSERT(puVar1[3] == 2, 0x51e);
    if ((*puVar1 & 2) != 0) {
        puVar2 = *(u32**)(param_1 + 0x3c);
        FUN_001f30f0(puVar2[0x25]);
        FUN_002339d0();
        *puVar2 |= 0x8000;
        puVar2[3] = 3;
    } else {
        iVar3 = *(int*)(param_1 + 0x3c);
        *(u32*)(iVar3 + 0x28) = 0;
        *(u32*)(iVar3 + 0xc) = 7;
    }
    *puVar1 |= 0x40;
    *puVar1 |= 1;
}

// FUN_001f1e90
void brRoot001f1e90(int param_1)
{
    u32* puVar1;

    puVar1 = *(u32**)(param_1 + 0x3c);
    K_ASSERT((~puVar1[1] & 4) != 0, 0x79c);
    K_ASSERT((~puVar1[2] & 4) != 0, 0x79d);
    FUN_00233b20();
    *puVar1 |= 0x400000;
    puVar1[1] |= 4;
    puVar1[0xe] = 0;
    puVar1[3] = 9;
}
