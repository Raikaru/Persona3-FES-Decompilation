#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

int FUN_0035ed20();
int FUN_0016dce0(short);
char FUN_0016dba0(short);
int FUN_0016e100(short);
void FUN_0035f060();
void FUN_0016e2b0(short, int);
int FUN_001717c0();
int FUN_00172160();
void FUN_0016e410(short, char);
int FUN_003bded0();
int FUN_0035f140();
int FUN_00172f70();

static u32 sDat007ce5d4; // DAT_007ce5d4

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

// FUN_00360300
u32 scrComu00360300(void)
{
    int uVar1;
    int lVar2;

    uVar1 = FUN_0035ed20(0);
    lVar2 = FUN_0016dce0(uVar1);
    K_ASSERT(lVar2 != 0, 0x2a1);
    lVar2 = FUN_0016e100(uVar1);
    if (lVar2 == 0) {
        FUN_0035f060(0);
        return 1;
    }
    lVar2 = FUN_001717c0(uVar1);
    if (lVar2 == 1) {
        FUN_0035f060(1);
    } else {
        FUN_0035f060(0);
    }
    return 1;
}

// FUN_003603d0
u32 scrComu003603d0(void)
{
    int uVar1;
    int lVar2;

    uVar1 = FUN_0035ed20(0);
    lVar2 = FUN_0016dce0(uVar1);
    K_ASSERT(lVar2 != 0, 0x2b9);
    lVar2 = FUN_0016e100(uVar1);
    if (lVar2 == 0) {
        FUN_0035f060(0);
        return 1;
    }
    lVar2 = FUN_00172160(uVar1);
    if (lVar2 == 1) {
        FUN_0035f060(1);
    } else {
        FUN_0035f060(0);
    }
    return 1;
}

// FUN_00360570
u32 scrComu00360570(void)
{
    char cVar1;
    int uVar2;
    int lVar3;

    uVar2 = FUN_0035ed20(0);
    lVar3 = FUN_0016dce0(uVar2);
    K_ASSERT(lVar3 != 0, 0x2ea);
    lVar3 = FUN_0016e100(uVar2);
    if (lVar3 == 0) {
        return 1;
    }
    cVar1 = FUN_0016dba0(uVar2);
    if (cVar1 > 0 && cVar1 < 10) {
        FUN_0016e410(uVar2, cVar1 + 1);
    }
    return 1;
}

// FUN_003608e0
u32 scrComu003608e0(void)
{
    int uVar1;
    int lVar2;

    uVar1 = FUN_0035ed20(0);
    lVar2 = FUN_0016dce0(uVar1);
    K_ASSERT(lVar2 != 0, 0x367);
    lVar2 = FUN_0016e100(uVar1);
    K_ASSERT(lVar2 != 0, 0x36a);
    FUN_0035f060(FUN_003bded0(uVar1));
    return 1;
}

// FUN_00360090
u32 scrComu00360090(void)
{
    int lVar1;
    int uStack_4;

    lVar1 = FUN_0035f140();
    K_ASSERT(lVar1 >= 0, 0x23d);
    lVar1 = FUN_00172f70(&uStack_4);
    if (lVar1 == 1) {
        sDat007ce5d4 = uStack_4;
        FUN_0035f060(1);
    } else {
        FUN_0035f060(0);
    }
    return 1;
}
