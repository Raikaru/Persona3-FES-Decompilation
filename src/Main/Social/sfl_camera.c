#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sSflCamera; // DAT_007ce33c
extern u32 DAT_00960070[];
u32 FUN_0024d430();
void FUN_0024d5e0();
void FUN_0024d7d0();
u32 FUN_0024d3b0();

// FUN_0024d110
void sflCamera0024d110(u32* param_1)
{
    K_ASSERT(sSflCamera == NULL, 0x42);
    *param_1 = 0;
    param_1[1] = 0;
    sSflCamera = param_1;
}

// FUN_0024d160
void sflCamera0024d160(void)
{
    K_ASSERT(sSflCamera != NULL, 0x3b);
    K_ASSERT(sSflCamera != NULL, 0x4e);
    sSflCamera = NULL;
}

// FUN_0024d280
void sflCamera0024d280(u32 param_1)
{
    u32* work;

    K_ASSERT(sSflCamera != NULL, 0x3b);
    work = sSflCamera;
    work[4] = param_1;
    *work |= 1;
}

// FUN_0024d940
void sflCamera0024d940(int param_1, u32 param_2)
{
    K_ASSERT(*(int*)(param_1 + 0x2c) != 0, 0x124);
    *(u32*)(param_1 + 0x34) = param_2;
}

// FUN_0024d9a0
void sflCamera0024d9a0(int param_1, u32 param_2)
{
    K_ASSERT(*(int*)(param_1 + 0x2c) != 0, 0x129);
    *(u32*)(param_1 + 0x3c) = param_2;
}

// FUN_0024d1c0
void sflCamera0024d1c0(void)
{
    u32* puVar1;
    u32 uVar2;

    K_ASSERT(sSflCamera != NULL, 0x3b);
    puVar1 = sSflCamera;
    K_ASSERT(DAT_00960070[0] == 0, 0x58);
    if ((~*puVar1 & 1) == 0 && (~*puVar1 & 2) == 0) {
        uVar2 = FUN_0024d430(*(u16*)((int)puVar1 + 0xc));
        FUN_0024d5e0(uVar2);
        FUN_0024d7d0(puVar1[4], uVar2);
    }
}

// FUN_0024d2e0
void sflCamera0024d2e0(int param_1, u32* param_2)
{
    u32* puVar1;

    K_ASSERT(sSflCamera != NULL, 0x3b);
    puVar1 = sSflCamera;
    K_ASSERT(FUN_0024d3b0(param_1) == 0, 0x79);
    *(u16*)((int)param_2 + 4) = (u16)param_1;
    if (puVar1[1] != 0) {
        param_2[2] = puVar1[2];
        param_2[3] = 0;
        *(u32*)((int)puVar1[2] + 0xc) = (u32)param_2;
        puVar1[2] = (u32)param_2;
    } else {
        param_2[3] = 0;
        param_2[2] = 0;
        puVar1[1] = (u32)param_2;
        puVar1[2] = (u32)param_2;
    }
    param_2[0x10] = 0;
}

// FUN_0024d3b0
u32 sflCamera0024d3b0(int param_1)
{
    int iVar1;
    int key;

    K_ASSERT(sSflCamera != NULL, 0x3b);
    iVar1 = sSflCamera[1];
    key = param_1 & 0xffff;
    while (iVar1 != 0) {
        if (*(u16*)(iVar1 + 4) == key) {
            return 1;
        }
        iVar1 = *(int*)(iVar1 + 0xc);
    }
    return 0;
}

// FUN_0024d430
int sflCamera0024d430(int param_1)
{
    int iVar1;
    int key;

    K_ASSERT(sSflCamera != NULL, 0x3b);
    iVar1 = sSflCamera[1];
    key = param_1 & 0xffff;
    while (iVar1 != 0) {
        if (*(u16*)(iVar1 + 4) == key) {
            return iVar1;
        }
        iVar1 = *(int*)(iVar1 + 0xc);
    }
    K_ASSERT(0, 0xaf);
    return 0;
}
