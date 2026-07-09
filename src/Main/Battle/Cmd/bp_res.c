#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"

static u32* sBpRes; // puGpffffb614 / DAT_007ce304

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
