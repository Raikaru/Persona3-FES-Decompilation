#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBpo654; // puGpffffb654
static u32* sBpo65c; // puGpffffb65c

// FUN_00251010
void bpo00251010(void* param_1, s32 param_2)
{
    *(s32*)((u8*)param_1 + 0x10) += param_2;
    *(u32*)((u8*)param_1 + 8) |= 2;
}

// FUN_00251030
void bpo00251030(void* param_1)
{
    *(u32*)((u8*)param_1 + 8) |= 2;
}

// FUN_00251050
void bpo00251050(u32* param_1)
{
    *param_1 = 0;
    sBpo654 = param_1;
}

// FUN_00251f20
void bpo00251f20(u32* param_1)
{
    *param_1 = 0;
    sBpo65c = param_1;
}
