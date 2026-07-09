#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

int FUN_00195540(void);
void FUN_00521250();

// FUN_003c9ab0
u32 fclMisc003c9ab0(void)
{
    int ctx;

    ctx = FUN_00195540();
    K_ASSERT(ctx != 0, 0x683);
    return *(u32*)(ctx + 8) & 0x20;
}

// FUN_003c9ba0
void fclMisc003c9ba0(u32 param_1, void* param_2)
{
    int ctx;

    ctx = FUN_00195540();
    K_ASSERT(param_2 != NULL, 0x697);
    FUN_00521250(ctx + 0x20, param_2, 0x34);
}

// FUN_003c9c10
u32 fclMisc003c9c10(u32 param_1, void* param_2, void* param_3)
{
    int ctx;

    ctx = FUN_00195540();
    K_ASSERT(param_2 != NULL && param_3 != NULL, 0x69e);
    FUN_00521250(ctx + 0x20, param_2, 0x34);
    FUN_00521250(ctx + 0x74, param_3, 0x34);
    if ((*(u32*)(ctx + 8) & 0x40) == 0) {
        *(s16*)(ctx + 0x16) = (s16)(*(s8*)(ctx + 0xe8) * *(s16*)(ctx + 0x14));
    }
    *(u32*)(ctx + 8) |= 0x40;
    return 1;
}
