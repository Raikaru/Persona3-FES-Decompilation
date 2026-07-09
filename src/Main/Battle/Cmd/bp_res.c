#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"

static u32* sBpRes; // puGpffffb614 / DAT_007ce304
void FUN_0021cc20();
void FUN_0021c7e0();

// FUN_0021bab0
u32 bpRes0021bab0(void)
{
    K_ASSERT(sBpRes != NULL, 0x59);
    return *sBpRes & 1;
}

// FUN_0021bb00
void bpRes0021bb00(u32 param_1)
{
    K_ASSERT(sBpRes != NULL, 0x59);
    sBpRes[0x1b] = param_1;
}

// FUN_0021c860
u32 bpRes0021c860(void)
{
    K_ASSERT(sBpRes != NULL, 0x59);
    return *sBpRes & 4;
}

// FUN_0021c930
void bpRes0021c930(void)
{
    int base;
    int i;

    K_ASSERT(sBpRes != NULL, 0x59);
    base = (int)sBpRes;
    K_ASSERT(*(u32*)(base + 4) & 0x100, 0x1f6);
    for (i = 0; i < 3; i++) {
        RwFree(*(void**)(base + i * 4 + 0x78));
    }
    *(u32*)(base + 4) &= 0xfffffeff;
}

// FUN_0021bb60
void bpRes0021bb60(void)
{
    int iVar1;
    int iVar2;

    K_ASSERT(sBpRes != NULL, 0x59);
    iVar1 = (int)sBpRes;
    if ((*(u32*)(iVar1 + 4) & 1) != 0) {
        for (iVar2 = 0; iVar2 < 7; iVar2++) {
            FUN_0021cc20(*(u32*)(iVar1 + iVar2 * 4 + 0x10));
        }
        for (iVar2 = 0; iVar2 < 6; iVar2++) {
            RwFree(*(void**)(iVar1 + iVar2 * 4 + 0x54));
        }
    }
    if ((*(u32*)(iVar1 + 4) & 0x80) != 0) {
        FUN_0021c7e0();
    }
    if ((*(u32*)(iVar1 + 4) & 0x100) != 0) {
        bpRes0021c930();
    }
    if ((*(u32*)(iVar1 + 4) & 0x10) != 0) {
        FUN_0021cc20(*(u32*)(iVar1 + 0x38));
    }
    if ((*(u32*)(iVar1 + 4) & 0x20) != 0) {
        FUN_0021cc20(*(u32*)(iVar1 + 0x3c));
    }
    if ((*(u32*)(iVar1 + 4) & 0x40) != 0) {
        FUN_0021cc20(*(u32*)(iVar1 + 0x40));
    }
    sBpRes = NULL;
}
