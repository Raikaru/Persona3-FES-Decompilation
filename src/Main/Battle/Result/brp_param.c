#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBrpParam; // iGpffffb6e0

void FUN_00238980();

// FUN_00279450
void brpParam00279450(u32 param_1)
{
    int base;

    K_ASSERT(sBrpParam != NULL, 0x61);
    base = (int)sBrpParam;
    *(u32*)(base + 0x3734) = param_1;
    FUN_00238980(base + 0x3750, 2, param_1, 2);
}

// FUN_002794c0
void brpParam002794c0(u32 param_1)
{
    K_ASSERT(sBrpParam != NULL, 0x61);
    *(u32*)((int)sBrpParam + 0x3730) = param_1;
}
