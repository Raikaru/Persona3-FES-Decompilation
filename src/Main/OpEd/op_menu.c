#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sOpMenu; // DAT_007ce3b4 / puGpffffb6c4

void FUN_0026da90();
void FUN_0026db30();
void FUN_0026dc20();

// FUN_0026a230
void opMenu0026a230(u32* param_1)
{
    K_ASSERT(sOpMenu == NULL, 0x8e);
    *param_1 = 0;
    sOpMenu = param_1;
}

// FUN_0026a280
void opMenu0026a280(void)
{
    K_ASSERT(sOpMenu != NULL, 0x87);
    sOpMenu = NULL;
}

// FUN_0026da10
void opMenu0026da10(void)
{
    u32* work;

    K_ASSERT(sOpMenu != NULL, 0x87);
    work = sOpMenu;
    FUN_0026da90(0);
    FUN_0026db30(0);
    FUN_0026dc20();
    *work &= 0xfffffffe;
}

// FUN_0026dc70
void opMenu0026dc70(void)
{
    u32* work;

    K_ASSERT(sOpMenu != NULL, 0x87);
    work = sOpMenu;
    work[0x247] = 0;
    *work |= 4;
}

// FUN_0026dcc0
u32 opMenu0026dcc0(void)
{
    K_ASSERT(sOpMenu != NULL, 0x87);
    return *sOpMenu & 8;
}

// FUN_0026dbd0
void opMenu0026dbd0(void)
{
    K_ASSERT(sOpMenu != NULL, 0x87);
    *sOpMenu |= 0x20;
}
