#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sSflResult; // iGpffffb5f0 / puGpffffb5f0

void FUN_001f6e80();
void FUN_00217410();
void FUN_002174d0();
void FUN_00216800();

// FUN_001f9630
void sflResult001f9630(void)
{
    u32* p;

    K_ASSERT(sSflResult != NULL, 0x8c);
    p = sSflResult;
    *(u32*)((int)p + 0x341c) = 0;
    *(u32*)((int)p + 0x3418) = 0;
}

// FUN_001f9800
void sflResult001f9800(int param_1, int* param_2)
{
    int i;
    u32* p;

    K_ASSERT(sSflResult != NULL, 0x8c);
    p = sSflResult;
    for (i = 0; i < *(int*)((int)p + 0x3404); i++) {
        *(u16*)(param_1 + i * 2) = *(u16*)((int)p + i * 2 + 0x33f0);
    }
    *param_2 = *(int*)((int)p + 0x3404);
}

// FUN_001f9890
u32 sflResult001f9890(void)
{
    K_ASSERT(sSflResult != NULL, 0x8c);
    return *(u32*)((int)sSflResult + 0x18);
}

// FUN_001f99f0
void sflResult001f99f0(void)
{
    u32* puVar1;

    K_ASSERT(sSflResult != NULL, 0x8c);
    puVar1 = sSflResult;
    puVar1[0xd03] = 0;
    switch (puVar1[2]) {
    case 1:
        puVar1[0xd33] = 0;
        puVar1[0xd34] = 0;
        puVar1[0xd32] = 0;
        *puVar1 |= 0x100;
        break;
    }
    FUN_001f6e80();
    puVar1[1] = 2;
}

// FUN_001f9100
void sflResult001f9100(void)
{
    int p;

    K_ASSERT(sSflResult != NULL, 0x8c);
    p = (int)sSflResult;
    FUN_00217410(p + 0x33f0, p + 0x3404);
    FUN_002174d0(p + 0x33e0, p + 0x3400);
    FUN_00216800();
}

// FUN_001f9770
void sflResult001f9770(int param_1, int* param_2)
{
    int i;
    u32* p;

    K_ASSERT(sSflResult != NULL, 0x8c);
    p = sSflResult;
    for (i = 0; i < *(int*)((int)p + 0x3400); i++) {
        *(u16*)(param_1 + i * 2) = *(u16*)((int)p + i * 2 + 0x33e0);
    }
    *param_2 = *(int*)((int)p + 0x3400);
}
