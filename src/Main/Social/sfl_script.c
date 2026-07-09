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
