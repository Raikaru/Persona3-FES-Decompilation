#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

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
