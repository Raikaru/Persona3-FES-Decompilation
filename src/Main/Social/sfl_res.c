#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"

static u32* sSflRes; // DAT_007ce2f0

// FUN_0020e9b0
u32 sflRes0020e9b0(void)
{
    K_ASSERT(sSflRes != NULL, 0x65);
    return *sSflRes & 8;
}

// FUN_0020ea80
void sflRes0020ea80(void)
{
    int base;
    int i;

    K_ASSERT(sSflRes != NULL, 0x65);
    base = (int)sSflRes;
    K_ASSERT(*(u32*)(base + 4) & 8, 0x20c);
    for (i = 0; i < 2; i++) {
        RwFree(*(void**)(base + i * 4 + 0x5c));
    }
    *(u32*)(base + 4) &= 0xfffffff7;
}

// FUN_0020ec00
u32 sflRes0020ec00(void)
{
    K_ASSERT(sSflRes != NULL, 0x65);
    return *sSflRes & 0x10;
}
