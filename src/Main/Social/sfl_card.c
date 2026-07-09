#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sSflCardB664; // puGpffffb664
static u32* sSflCard354;  // DAT_007ce354

// FUN_00255170
void sflCard00255170(u32* param_1)
{
    *param_1 |= 1;
}

// FUN_00255190
void sflCard00255190(u32* param_1)
{
    param_1[0x496] = 0;
    *param_1 |= 0x80;
}

// FUN_002561c0
u32 sflCard002561c0(u32* param_1)
{
    return *param_1 & 1;
}

// FUN_002561d0
u32 sflCard002561d0(u32* param_1)
{
    return *param_1 & 0x80;
}

// FUN_00259250
void sflCard00259250(void)
{
    u32* work;

    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    work = sSflCardB664;
    work[0x4a1f] = 0;
    *work |= 0x40;
    work[0x4a1c] = 3;
    *work |= 0x100;
}

// FUN_002592c0
u32 sflCard002592c0(void)
{
    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    return *sSflCardB664 & 0x100;
}

// FUN_00259310
void sflCard00259310(void)
{
    u32* work;

    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    work = sSflCardB664;
    work[0x4a1f] = 0;
    *work |= 0x40;
    work[0x4a1c] = 4;
    *work |= 0x800;
}

// FUN_00259380
u32 sflCard00259380(void)
{
    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    return *sSflCardB664 & 0x800;
}

// FUN_00258490
void sflCard00258490(void)
{
    K_ASSERT(sSflCard354 != NULL, 0xbc);
    *sSflCard354 |= 8;
}

// FUN_002584e0
void sflCard002584e0(u32 param_1)
{
    K_ASSERT(sSflCard354 != NULL, 0xbc);
    sSflCard354[0x49ec] = param_1;
}
