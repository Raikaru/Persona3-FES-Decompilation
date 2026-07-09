#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

int FUN_0035ed20();
int FUN_0016dce0(short);
char FUN_0016dba0(short);
int FUN_0016e100(short);
void FUN_0035f060();
void FUN_0016e2b0(short, int);

// FUN_00360280
u32 scrComu00360280(void)
{
    char uVar1;
    int uVar2;
    int lVar3;

    uVar2 = FUN_0035ed20(0);
    lVar3 = FUN_0016dce0(uVar2);
    K_ASSERT(lVar3 != 0, 0x293);
    uVar1 = FUN_0016dba0(uVar2);
    FUN_0035f060(uVar1);
    return 1;
}

// FUN_003604a0
u32 scrComu003604a0(void)
{
    int uVar1;
    int lVar2;
    int lVar3;

    uVar1 = FUN_0035ed20(0);
    lVar2 = FUN_0016dce0(uVar1);
    K_ASSERT(lVar2 != 0, 0x2d2);
    lVar2 = FUN_0035ed20(1);
    K_ASSERT(lVar2 >= 0, 0x2d6);
    lVar3 = FUN_0016e100(uVar1);
    if (lVar3 == 0) {
        return 1;
    }
    FUN_0016e2b0(uVar1, lVar2);
    return 1;
}
