#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"

static u32* sSflRes; // DAT_007ce2f0
extern char DAT_0068e1c0[];
extern char DAT_0068e1e0[];
u32 FUN_00100d80();

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

void FUN_0021cc20();

// FUN_0020ec50
u32 sflRes0020ec50(void)
{
    int base;

    K_ASSERT(sSflRes != NULL, 0x65);
    base = (int)sSflRes;
    K_ASSERT(*(u32*)(base + 4) & 0x10, 0x22a);
    return *(u32*)(base + 0x80);
}

// FUN_0020ecc0
void sflRes0020ecc0(void)
{
    int base;

    K_ASSERT(sSflRes != NULL, 0x65);
    base = (int)sSflRes;
    K_ASSERT(*(u32*)(base + 4) & 0x10, 0x232);
    FUN_0021cc20(*(void**)(base + 0x80));
    *(u32*)(base + 4) &= 0xffffffef;
}

// FUN_0020e8f0
void sflRes0020e8f0(void)
{
    u32* puVar1;

    K_ASSERT(sSflRes != NULL, 0x65);
    puVar1 = sSflRes;
    K_ASSERT((~puVar1[1] & 8) != 0, 0x1f2);
    K_ASSERT((~*puVar1 & 8) != 0, 0x1f3);
    puVar1[0x1c] = FUN_00100d80(DAT_0068e1c0, 1);
    *puVar1 |= 8;
}

// FUN_0020eb40
void sflRes0020eb40(void)
{
    u32* puVar1;

    K_ASSERT(sSflRes != NULL, 0x65);
    puVar1 = sSflRes;
    K_ASSERT((~*puVar1 & 0x10) != 0, 0x218);
    K_ASSERT((~puVar1[1] & 0x10) != 0, 0x219);
    puVar1[0x1d] = FUN_00100d80(DAT_0068e1e0, 0);
    *puVar1 |= 0x10;
}
