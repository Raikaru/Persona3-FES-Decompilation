#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBpd654; // puGpffffb654
static u32* sBpd660; // puGpffffb660

// FUN_00251010
void bpd00251010(void* param_1, s32 param_2)
{
    *(s32*)((u8*)param_1 + 0x10) += param_2;
    *(u32*)((u8*)param_1 + 8) |= 2;
}

// FUN_00251030
void bpd00251030(void* param_1)
{
    *(u32*)((u8*)param_1 + 8) |= 2;
}

// FUN_00251050
void bpd00251050(u32* param_1)
{
    *param_1 = 0;
    sBpd654 = param_1;
}

// FUN_00252e60
void bpd00252e60(u32* param_1)
{
    *param_1 = 0;
    param_1[0x2d5] = 0;
    sBpd660 = param_1;
}

// FUN_00252e90
void bpd00252e90(void)
{
    K_ASSERT(sBpd660 != NULL, 0x25);
    *sBpd660 |= 1;
}
