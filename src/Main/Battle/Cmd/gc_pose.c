#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"
#include "rw/rtquat.h"

// FUN_00250480
void gcPose00250480(int param_1)
{
    K_ASSERT(*(int*)(param_1 + 0xc) == 0, 0x466);
    K_ASSERT(*(int*)(param_1 + 0x20) == 3, 0x467);
    *(u32*)(param_1 + 0x28) &= 0xfffffffe;
}

// FUN_00250b90
u32 gcPose00250b90(int param_1)
{
    K_ASSERT(*(int*)(param_1 + 0x20) == 3, 0x512);
    return *(u32*)(param_1 + 0x28) & 1;
}

// FUN_00250c70
void gcPose00250c70(int param_1)
{
    K_ASSERT(*(int*)(param_1 + 0xc) == 2, 0x539);
    K_ASSERT(*(int*)(param_1 + 0x24) == 3, 0x53a);
    *(u32*)(param_1 + 0x2c) &= 0xfffffffe;
}

// FUN_00250e70
u32 gcPose00250e70(int param_1)
{
    K_ASSERT(*(int*)(param_1 + 0xc) == 2, 0x57d);
    K_ASSERT(*(int*)(param_1 + 0x24) == 3, 0x57e);
    return *(u32*)(param_1 + 0x2c) & 1;
}

// FUN_00250ef0
void gcPose00250ef0(int param_1, float param_2)
{
    K_ASSERT(*(int*)(param_1 + 0xc) == 2, 0x588);
    K_ASSERT(*(int*)(param_1 + 0x24) == 4, 0x589);
    *(float*)(param_1 + 0x6c) = param_2;
    *(u32*)(param_1 + 8) |= 2;
}

// FUN_0024f960
void gcPose0024f960(int param_1, RwV3d *param_2)
{
    K_ASSERT(*(int*)(param_1 + 0xc) == 0, 0x375);
    K_ASSERT(*(int*)(param_1 + 0x20) < 4, 0x376);
    *param_2 = *(RwV3d*)(param_1 + 0x14);
}

// FUN_00250500
void gcPose00250500(int param_1, RwV3d *param_2, int param_3)
{
    K_ASSERT(*(int*)(param_1 + 0x20) == 3, 0x471);
    *(u32*)(param_1 + 0x24) = 0;
    *(RwV3d*)(param_1 + 0x30) = *param_2;
    *(RwV3d*)(param_1 + 0x3c) = *(RwV3d*)(param_1 + 0x14);
    *(u32*)(param_1 + 0x10) = 0;
    *(int*)(param_1 + 0x2c) = param_3 << 0x10;
    *(u32*)(param_1 + 0x28) |= 1;
}

// FUN_0024faa0
RwV3d* gcPose0024faa0(int param_1)
{
    K_ASSERT(*(int*)(param_1 + 0x20) < 2, 0x38e);
    return (RwV3d*)(param_1 + 0x14);
}

// FUN_0024fba0
void gcPose0024fba0(int param_1, RtQuat *param_2)
{
    K_ASSERT(*(int*)(param_1 + 0xc) == 2, 0x3a6);
    K_ASSERT(*(int*)(param_1 + 0x24) < 5, 0x3a7);
    *param_2 = *(RtQuat*)(param_1 + 0x14);
}
