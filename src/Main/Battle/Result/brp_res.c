#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBrpResWork; // puGpffffb644

// FUN_0024ba30
void brpRes0024ba30(u32* param_1)
{
    *param_1 = 0;
    param_1[1] = 0;
    sBrpResWork = param_1;
}

static u32* sBrpRes334; // 007ce334

// FUN_0024bed0
u32 brpRes0024bed0(void)
{
    K_ASSERT(sBrpResWork != NULL, 0x39);
    return *sBrpResWork & 1;
}

// FUN_0024bf20
u32 brpRes0024bf20(s32 param_1)
{
    K_ASSERT(sBrpResWork != NULL, 0x39);
    return sBrpResWork[param_1 + 4];
}

// FUN_0024c040
u32 brpRes0024c040(void)
{
    K_ASSERT(sBrpRes334 != NULL, 0x39);
    return *sBrpRes334 & 2;
}

// FUN_0024c090
u32 brpRes0024c090(void)
{
    u32* work;

    K_ASSERT(sBrpRes334 != NULL, 0x39);
    work = sBrpRes334;
    K_ASSERT(work[1] & 2, 0xce);
    return work[8];
}
