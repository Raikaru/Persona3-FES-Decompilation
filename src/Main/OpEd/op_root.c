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
void FUN_00269f50();
void FUN_0026c710();
void FUN_0026e000();
void FUN_0026cc90();
void FUN_00268e20();
void FUN_002720c0();
void FUN_00108f70();
void FUN_00266b30();
void FUN_0026ebf0();
void FUN_002694b0();
void FUN_0026da10();
void FUN_00266cb0();
void FUN_00269d10();
void FUN_002673f0();
void FUN_0026dd60();
void FUN_0026a280();
void FUN_00271d70();
void FUN_00266690();
void FUN_00191a10();

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

// FUN_00265e30
u32 opRoot00265e30(void)
{
    u32* puVar1;

    K_ASSERT(sOpRoot != NULL, 0x9a);
    puVar1 = sOpRoot;
    if (puVar1[1] != 5 && (~*puVar1 & 1) == 0) {
        FUN_00269f50();
        if (puVar1[1] != 0xb) {
            FUN_0026c710();
        }
        FUN_0026e000();
        if (puVar1[1] != 0xb) {
            FUN_0026cc90();
            FUN_00268e20();
        }
        FUN_002720c0();
    }
    return 0;
}

// FUN_00265ef0
void opRoot00265ef0(int param_1)
{
    K_ASSERT(sOpRoot != NULL, 0x9a);
    FUN_00269d10();
    FUN_002673f0();
    FUN_0026dd60();
    FUN_0026a280();
    FUN_00271d70();
    FUN_00266b30();
    FUN_00266690();
    sOpRoot = NULL;
    FUN_00191a10(*(u32*)(param_1 + 0x3c));
}
