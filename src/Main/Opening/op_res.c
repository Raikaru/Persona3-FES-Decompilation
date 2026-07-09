#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sOpRes; // DAT_007ce394

void FUN_004cde90();
void FUN_0021cc20();
void FUN_00266b30();
void FUN_00266dc0();

// FUN_00266690
void opRes00266690(void)
{
    int base;

    K_ASSERT(sOpRes != NULL, 0x44);
    base = (int)sOpRes;
    if (*(u32*)(base + 4) & 1) {
        FUN_00266b30();
    }
    if (*(u32*)(base + 4) & 2) {
        FUN_00266dc0();
    }
    sOpRes = NULL;
}

// FUN_00266ae0
u32 opRes00266ae0(void)
{
    K_ASSERT(sOpRes != NULL, 0x44);
    return *sOpRes & 1;
}

// FUN_00266b30
void opRes00266b30(void)
{
    int base;
    int i;

    K_ASSERT(sOpRes != NULL, 0x44);
    base = (int)sOpRes;
    for (i = 0; i < 0xe; i++) {
        FUN_004cde90(*(u32*)(base + i * 4 + 0xc));
    }
    for (i = 0; i < 1; i++) {
        FUN_0021cc20(*(u32*)(base + i * 4 + 0x44));
    }
    *(u32*)(base + 4) &= 0xfffffffe;
}

// FUN_00266bf0
u32 opRes00266bf0(int param_1)
{
    K_ASSERT(sOpRes != NULL, 0x44);
    return sOpRes[param_1 + 3];
}

// FUN_00266c50
u32 opRes00266c50(int param_1)
{
    K_ASSERT(sOpRes != NULL, 0x44);
    return sOpRes[param_1 + 0x11];
}

// FUN_00266d70
u32 opRes00266d70(void)
{
    K_ASSERT(sOpRes != NULL, 0x44);
    return *sOpRes & 2;
}

// FUN_00266dc0
void opRes00266dc0(void)
{
    int base;
    int i;

    K_ASSERT(sOpRes != NULL, 0x44);
    base = (int)sOpRes;
    for (i = 0; i < 2; i++) {
        FUN_004cde90(*(u32*)(base + i * 4 + 0x4c));
    }
    *(u32*)(base + 4) &= 0xfffffffd;
}

// FUN_00266e50
u32 opRes00266e50(int param_1)
{
    K_ASSERT(sOpRes != NULL, 0x44);
    return sOpRes[param_1 + 0x13];
}
