#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sOpWait; // DAT_007ce3b8

void FUN_0026ed40();
u32 FUN_00269690();

// FUN_0026dd10
void opWait0026dd10(u32* param_1)
{
    K_ASSERT(sOpWait == NULL, 0xe2);
    *param_1 = 0;
    sOpWait = param_1;
}

// FUN_0026dd60
void opWait0026dd60(void)
{
    K_ASSERT(sOpWait != NULL, 0xdb);
    if (*sOpWait & 2) {
        FUN_0026ed40();
    }
    sOpWait = NULL;
}

// FUN_0026ec50
void opWait0026ec50(void)
{
    u32* work;

    K_ASSERT(sOpWait != NULL, 0xdb);
    work = sOpWait;
    work[2] = 0;
    work[1] = 0;
    *work |= 4;
}

// FUN_0026eca0
void opWait0026eca0(void)
{
    u32* work;
    u32 uVar2;

    K_ASSERT(sOpWait != NULL, 0xdb);
    work = sOpWait;
    if (*work & 2) {
        FUN_0026ed40();
    }
    uVar2 = FUN_00269690(1, 0xc, 9);
    work[0x45c] = uVar2;
    uVar2 = FUN_00269690(1, 0xc, 9);
    work[0x45d] = uVar2;
    *work |= 2;
}

// FUN_0026ee80
u32 opWait0026ee80(void)
{
    K_ASSERT(sOpWait != NULL, 0xdb);
    return *sOpWait & 8;
}

// FUN_0026ebf0
void opWait0026ebf0(void)
{
    u32 uVar1;

    K_ASSERT(sOpWait != NULL, 0xdb);
    uVar1 = *sOpWait & 0xfffffffe;
    *sOpWait = uVar1;
    if ((uVar1 & 2) != 0) {
        FUN_0026ed40();
    }
}

// FUN_0026edd0
void opWait0026edd0(void)
{
    u32* puVar1;

    K_ASSERT(sOpWait != NULL, 0xdb);
    puVar1 = sOpWait;
    sOpWait[2] = 0;
    puVar1[1] = 1;
    *puVar1 |= 4;
}
