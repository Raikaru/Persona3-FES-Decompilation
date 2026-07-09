#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBpd660; // puGpffffb660
u32 FUN_0021c3f0();
u32 FUN_0021cca0();
void FUN_0021d3b0();

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

// FUN_00252ee0
void bpd00252ee0(void)
{
    K_ASSERT(sBpd660 != NULL, 0x25);
    *sBpd660 &= ~1;
}

// FUN_00253410
void bpd00253410(void)
{
    u32* puVar1;
    u32 uVar2;
    int iVar3;

    K_ASSERT(sBpd660 != NULL, 0x25);
    puVar1 = sBpd660;
    uVar2 = FUN_0021cca0(FUN_0021c3f0(1), 0x4c);
    for (iVar3 = 0; iVar3 < 10; iVar3++) {
        FUN_0021d3b0(puVar1 + iVar3 * 0x48 + 8, uVar2);
    }
    puVar1[0x2d4] = 0;
    *puVar1 |= 2;
}
