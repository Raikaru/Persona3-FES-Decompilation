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
int FUN_0016dbc0(short, int*);
u32 FUN_00173220();
void FUN_003a4220();
void FUN_00171c40();
void FUN_00172200();
short FUN_00175360();
void FUN_00174710(u16, u16, char);
void FUN_0016e920(short);
int FUN_003be8e0();
u32 FUN_003c3f40();
extern u8 DAT_00958400[];
extern u8 DAT_0095841e[];

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

// FUN_00360b70
u32 scrComu00360b70(void)
{
    int uVar1;
    int lVar2;
    int lVar3;
    int uStack_4;

    uVar1 = FUN_0035ed20(0);
    lVar2 = FUN_0016dce0(uVar1);
    K_ASSERT(lVar2 != 0, 0x3d9);
    lVar2 = FUN_0035f140();
    lVar3 = FUN_0016dbc0(uVar1, &uStack_4);
    if (lVar3 == 1) {
        if (lVar2 >= 0) {
            FUN_003a4220(lVar2, 0, FUN_00173220((u16)uStack_4));
        }
        FUN_0035f060(uStack_4);
    } else {
        FUN_0035f060(0);
    }
    return 1;
}

// FUN_00360640
u32 scrComu00360640(void)
{
    int uVar1;
    int lVar2;
    int lVar3;

    uVar1 = FUN_0035ed20(0);
    lVar2 = FUN_0035ed20(1);
    lVar3 = FUN_0016dce0(uVar1);
    K_ASSERT(lVar3 != 0, 0x306);
    lVar3 = FUN_0016e100(uVar1);
    if (lVar3 == 0) {
        return 1;
    }
    FUN_00171c40(uVar1, lVar2 != 0);
    return 1;
}

// FUN_003606f0
u32 scrComu003606f0(void)
{
    int uVar1;
    int lVar2;
    int lVar3;

    uVar1 = FUN_0035ed20(0);
    lVar2 = FUN_0035ed20(1);
    lVar3 = FUN_0016dce0(uVar1);
    K_ASSERT(lVar3 != 0, 0x321);
    lVar3 = FUN_0016e100(uVar1);
    if (lVar3 == 0) {
        return 1;
    }
    FUN_00172200(uVar1, lVar2 != 0);
    return 1;
}

// FUN_0035fbd0
u32 scrComu0035fbd0(void)
{
    int uVar1;
    short uVar2;
    int uVar3;

    uVar3 = FUN_0035ed20(0);
    K_ASSERT(uVar3 < 5, 0x186);
    uVar1 = FUN_0035ed20(1);
    uVar2 = FUN_00175360();
    FUN_00174710(uVar2, uVar3 & 0xffff, uVar1);
    return 1;
}

// FUN_0035f680
u32 scrComu0035f680(void)
{
    int uVar1;
    int lVar2;

    uVar1 = FUN_0035ed20(0);
    lVar2 = FUN_003be8e0(uVar1, DAT_00958400);
    K_ASSERT(lVar2 != 0, 0xd7);
    FUN_0016e920(uVar1);
    lVar2 = FUN_0035f140();
    if (lVar2 >= 0) {
        FUN_003a4220(lVar2, 0, FUN_003c3f40(DAT_0095841e[0]));
    }
    return 1;
}
