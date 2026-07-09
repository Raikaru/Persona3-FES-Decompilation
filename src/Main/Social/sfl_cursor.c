#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

typedef struct { f32 a; f32 b; f32 c; } SflVec3;

static u32* sSflCursor; // puGpffffb670

void FUN_00258540();
void FUN_0025aad0();

// FUN_0025a110
void sflCursor0025a110(u32* param_1)
{
    *param_1 = 0;
    sSflCursor = param_1;
}

// FUN_0025b300
void sflCursor0025b300(u32 param_1)
{
    u32* work;

    K_ASSERT(sSflCursor != NULL, 0x47);
    work = sSflCursor;
    FUN_00258540(sSflCursor[0xc], sSflCursor + 1);
    FUN_00258540(param_1, work + 4);
    *(SflVec3*)(work + 7) = *(SflVec3*)(work + 1);
    work[0xb] = work[0xc];
    work[0xc] = param_1;
    work[10] = 0;
    work[0x328] = 0;
    *work |= 2;
    FUN_0025aad0();
}

// FUN_0025b3b0
void sflCursor0025b3b0(u32 param_1)
{
    u32* work;

    K_ASSERT(sSflCursor != NULL, 0x47);
    work = sSflCursor;
    FUN_00258540(param_1, sSflCursor + 7);
    work[0xb] = work[0xc];
    work[0xc] = param_1;
    work[10] = 0;
    work[0x328] = 1;
    *work |= 2;
    FUN_0025aad0();
}
