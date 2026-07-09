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

void FUN_00258140();
void FUN_00253600();
u32* FUN_00255390();

// FUN_002580e0
void sflCard002580e0(void)
{
    K_ASSERT(sSflCard354 != NULL, 0xbc);
    *sSflCard354 &= 0xffffdfff;
    FUN_00258140();
}

// FUN_002582b0
u32 sflCard002582b0(void)
{
    K_ASSERT(sSflCard354 != NULL, 0xbc);
    return *sSflCard354 & 0x40;
}

// FUN_00253560
void sflCard00253560(void)
{
    int base;
    int i;
    int p;

    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    base = (int)sSflCardB664;
    for (i = 0; i < 0x10; i++) {
        p = base + i * 0x1264;
        if ((~*(u32*)(p + 4) & 4) == 0) {
            FUN_00253600(p + 4);
        }
    }
    sSflCardB664 = NULL;
}

// FUN_00253920
void sflCard00253920(void)
{
    u32* a;
    u32* b;
    u32* node;

    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    a = sSflCardB664;
    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    b = sSflCardB664;
    node = FUN_00255390();
    if (b[0x4997] == 0) {
        node[0x3f1] = 0;
        node[0x3f0] = 0;
        b[0x4997] = (u32)node;
        b[0x4998] = (u32)node;
    } else {
        node[0x3f1] = 0;
        node[0x3f0] = b[0x4998];
        ((u32*)b[0x4998])[0x3f1] = (u32)node;
        b[0x4998] = (u32)node;
    }
    *node |= 4;
    node[1] = 2;
    node[4] = a[0x499f];
    a[0x499f]++;
}

// FUN_002536b0
void sflCard002536b0(u32 param_1, u32 param_2)
{
    u32* a;
    u32* b;
    u32* node;

    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    a = sSflCardB664;
    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    b = sSflCardB664;
    node = FUN_00255390();
    if (b[0x4997] == 0) {
        node[0x3f1] = 0;
        node[0x3f0] = 0;
        b[0x4997] = (u32)node;
        b[0x4998] = (u32)node;
    } else {
        node[0x3f1] = 0;
        node[0x3f0] = b[0x4998];
        ((u32*)b[0x4998])[0x3f1] = (u32)node;
        b[0x4998] = (u32)node;
    }
    *node |= 4;
    node[1] = 1;
    node[2] = param_1;
    node[3] = param_2;
    node[4] = a[0x499f];
    a[0x499f]++;
}

// FUN_002537f0
void sflCard002537f0(u16 param_1)
{
    u32* a;
    u32* b;
    u32* node;

    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    a = sSflCardB664;
    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    b = sSflCardB664;
    node = FUN_00255390();
    if (b[0x4997] == 0) {
        node[0x3f1] = 0;
        node[0x3f0] = 0;
        b[0x4997] = (u32)node;
        b[0x4998] = (u32)node;
    } else {
        node[0x3f1] = 0;
        node[0x3f0] = b[0x4998];
        ((u32*)b[0x4998])[0x3f1] = (u32)node;
        b[0x4998] = (u32)node;
    }
    *node |= 4;
    node[1] = 0;
    *(u16*)(node + 2) = param_1;
    node[4] = a[0x499f];
    a[0x499f]++;
}
