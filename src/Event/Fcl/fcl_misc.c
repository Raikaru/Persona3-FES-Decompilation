#include "Kosaka/k_assert.h"

// Retail calls this with $a0 untouched (no argument), so keep the
// unprototyped decl instead of including kwlnTask.h's real prototype.
int kwlnTaskGetWorkData(void);
void memcpy();
void memset();

// FUN_003c9ab0
u32 fclMisc003c9ab0(void)
{
    int ctx;

    ctx = kwlnTaskGetWorkData();
    K_ASSERT(ctx != 0, 0x683);
    return *(u32*)(ctx + 8) & 0x20;
}

// FUN_003c9b00
void fclMisc003c9b00(u32 param_1, void* param_2, void* param_3)
{
    int ctx;

    ctx = kwlnTaskGetWorkData();
    if (param_3 != NULL) {
        memcpy(ctx + 0x1c, param_3, 0x54);
    } else {
        memset(ctx + 0x1c, 0, 0x54);
    }
    if (param_2 != NULL) {
        memcpy(ctx + 0x20, param_2, 0x34);
    }
}

// FUN_003c9ba0
void fclMisc003c9ba0(u32 param_1, void* param_2)
{
    int ctx;

    ctx = kwlnTaskGetWorkData();
    K_ASSERT(param_2 != NULL, 0x697);
    memcpy(ctx + 0x20, param_2, 0x34);
}

// FUN_003c9c10
u32 fclMisc003c9c10(u32 param_1, void* param_2, void* param_3)
{
    int ctx;

    ctx = kwlnTaskGetWorkData();
    K_ASSERT(param_2 != NULL && param_3 != NULL, 0x69e);
    memcpy(ctx + 0x20, param_2, 0x34);
    memcpy(ctx + 0x74, param_3, 0x34);
    if ((*(u32*)(ctx + 8) & 0x40) == 0) {
        *(s16*)(ctx + 0x16) = (s16)(*(s8*)(ctx + 0xe8) * *(s16*)(ctx + 0x14));
    }
    *(u32*)(ctx + 8) |= 0x40;
    return 1;
}
