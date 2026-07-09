#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBpmWork; // puGpffffb634

void FUN_002491f0();

// FUN_00249180
void bpm00249180(void)
{
    u32* work;

    K_ASSERT(sBpmWork != NULL, 0x3d);
    work = sBpmWork;
    if (*work & 1)
    {
        FUN_002491f0();
        *work &= ~1;
    }
}

static u32* sBpm638; // puGpffffb638
static u32* sBpm63c; // puGpffffb63c
static u32* sBpm644; // puGpffffb644

// FUN_00249240
void bpm00249240(u32* param_1)
{
    *param_1 = 0;
    sBpm638 = param_1;
}

// FUN_00249680
void bpm00249680(void* param_1)
{
    *(u32*)((u8*)param_1 + 0x604) = 0;
}

// FUN_0024a6c0
void bpm0024a6c0(u32* param_1)
{
    *param_1 = 0;
    sBpm63c = param_1;
}

// FUN_0024a6d0
void bpm0024a6d0(void)
{
    sBpm63c = NULL;
}

// FUN_0024ba30
void bpm0024ba30(u32* param_1)
{
    *param_1 = 0;
    param_1[1] = 0;
    sBpm644 = param_1;
}

s32 FUN_0016f190();

// FUN_00249650
u32 bpm00249650(u16 param_1)
{
    return !FUN_0016f190(param_1 + 0x12c0);
}
