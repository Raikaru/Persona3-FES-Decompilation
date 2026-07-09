#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sSflScript; // puGpffffb668

void FUN_00259850();

// FUN_00259640
void sflScript00259640(void)
{
    u32* work;

    K_ASSERT(sSflScript != NULL, 0x43);
    work = sSflScript;
    work[2] = work[1];
    *work |= 1;
}

// FUN_00259970
void sflScript00259970(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    FUN_00259850(0, 0);
}

// FUN_00259b00
void sflScript00259b00(u16 param_1)
{
    u16 arg;

    K_ASSERT(sSflScript != NULL, 0x43);
    arg = param_1;
    FUN_00259850(2, &arg);
}

// FUN_00259b60
void sflScript00259b60(u16 param_1)
{
    u16 arg;

    K_ASSERT(sSflScript != NULL, 0x43);
    arg = param_1;
    FUN_00259850(4, &arg);
}

// FUN_00259bc0
void sflScript00259bc0(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    FUN_00259850(5, 0);
}

// FUN_00259c60
void sflScript00259c60(u16 param_1)
{
    u16 arg;

    K_ASSERT(sSflScript != NULL, 0x43);
    arg = param_1;
    FUN_00259850(7, &arg);
}

s32 FUN_00256430();

// FUN_00259690
void sflScript00259690(u32 param_1, u32 param_2)
{
    u32* work;

    K_ASSERT(sSflScript != NULL, 0x43);
    work = sSflScript;
    work[1] = param_1;
    work[3] = param_1;
    work[4] = param_2;
}

// FUN_002596f0
u32 sflScript002596f0(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    return *sSflScript & 1;
}

// FUN_00259c10
void sflScript00259c10(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    FUN_00259850(6, 0);
}

// FUN_00259cc0
void sflScript00259cc0(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    FUN_00259850(8, 0);
}

// FUN_00259e00
u32 sflScript00259e00(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    if (FUN_00256430() != 0) {
        return 0;
    }
    return 1;
}

// FUN_00259610
void sflScript00259610(u32* param_1)
{
    *param_1 = 0;
    param_1[5] = 0;
    sSflScript = param_1;
}
