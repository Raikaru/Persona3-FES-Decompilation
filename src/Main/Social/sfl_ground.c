#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sSflGround; // puGpffffb624 / DAT_007ce314

void FUN_00249690();
void FUN_0023d2a0();
void FUN_0023d650();

// FUN_00239280
void sflGround00239280(void)
{
    K_ASSERT(sSflGround != NULL, 0x87);
    FUN_00249690(sSflGround + 0x21e0);
    sSflGround = NULL;
}

// FUN_0023d0e0
u32 sflGround0023d0e0(void)
{
    K_ASSERT(sSflGround != NULL, 0x87);
    return *sSflGround & 0x20;
}

// FUN_0023d1f0
u32 sflGround0023d1f0(void)
{
    K_ASSERT(sSflGround != NULL, 0x87);
    return *sSflGround & 4;
}

// FUN_0023d240
void sflGround0023d240(void)
{
    int base;

    K_ASSERT(sSflGround != NULL, 0x87);
    base = (int)sSflGround;
    FUN_0023d2a0();
    FUN_0023d650();
    *(u32*)(base + 8) = 0;
    *(u32*)(base + 0xc) = 5;
}
