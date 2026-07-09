#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sOpRoot; // DAT_007ce388
static u32 D_007cdffc;
static u32 D_007ce00c;

void FUN_00265030();
u32 FUN_0015c460();
u32 FUN_00420340();
int FUN_00108e50();
void FUN_001099d0();

// FUN_00265b30
void opRoot00265b30(void)
{
    u32* work;
    u32 v;

    K_ASSERT(sOpRoot != NULL, 0x9a);
    work = sOpRoot;
    D_007cdffc = 0;
    D_007ce00c = 0;
    v = FUN_00420340(work[2], 0);
    work[4] = v;
    *work |= 2;
    work[1] = 0xb;
}

// FUN_00265bb0
void opRoot00265bb0(void)
{
    u32* work;
    u32 v;

    K_ASSERT(sOpRoot != NULL, 0x9a);
    work = sOpRoot;
    v = FUN_0015c460(work[2]);
    work[6] = v;
    *work |= 4;
    work[1] = 0xe;
}

// FUN_00265dc0
u32 opRoot00265dc0(void)
{
    FUN_00265030();
    K_ASSERT(sOpRoot != NULL, 0x9a);
    if ((*sOpRoot & 1) != 0) {
        return 0;
    }
    return -1;
}

// FUN_00266060
void opRoot00266060(void)
{
    int base;

    K_ASSERT(sOpRoot != NULL, 0x9a);
    base = (int)sOpRoot;
    if (FUN_00108e50() != 0x36) {
        FUN_001099d0(0x36, 1);
    }
    *(u32*)(base + 0x4524) = 0;
    *(u32*)(base + 4) = 9;
}

// FUN_002660d0
void opRoot002660d0(void)
{
    int base;

    K_ASSERT(sOpRoot != NULL, 0x9a);
    base = (int)sOpRoot;
    if (FUN_00108e50() != 0x36) {
        FUN_001099d0(0x36, 1);
    }
    *(u32*)(base + 0x4524) = 0;
    *(u32*)(base + 4) = 0x11;
}
