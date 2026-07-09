#include "Kosaka/k_assert.h"

u32 FUN_003c3f80();
u32 FUN_0017d800();
u32 FUN_00488f30();
u32 FUN_001749a0(u32 param_1);
void FUN_003dff00(s32 param_1);
s8 FUN_0016dba0(s32 param_1);
s32 FUN_003d74f0(s32 param_1, s32 param_2, s32 param_3);

extern s32 DAT_006a5fc0[];
extern char DAT_006a4ba0[];
extern char DAT_006a4e10[];
extern char DAT_006a5630[];
extern char DAT_006a5f44[];
extern char* volatile DAT_007ce420;

// FUN_003d5850
s32 fclCombineMisc003d5850(s32 param_1)
{
    s32 local[8];
    s32* src;
    s32* dst;
    s32 count;
    s32 temp;

    src = DAT_006a5fc0;
    dst = local;
    count = 5;
    do {
        temp = *src;
        src++;
        count--;
        *dst = temp;
        dst++;
    } while (count > 0);
    return local[param_1];
}

// FUN_003d58a0
void fclCombineMisc003d58a0(void)
{
    FUN_003c3f80();
}

// FUN_003d5c90
char* fclCombineMisc003d5c90(void)
{
    if (FUN_0017d800() != 0) {
        return DAT_006a4e10;
    }
    return DAT_006a4ba0;
}


// FUN_003d7180
u32 fclCombineMisc003d7180(void)
{
    return (s32)(((FUN_00488f30() % 0xffff) * 1000) / 0xffff) < 500;
}

// FUN_003d74b0
s32 fclCombineMisc003d74b0(u32 param_1)
{
    u8* base;

    base = (u8*)DAT_007ce420;
    return *(s32*)(DAT_006a5630 + (u32)base[(param_1 & 0xffff) * 0xe + 0xd] * 4);
}
// FUN_003d7a30 NONMATCHING
s32 fclCombineMisc003d7a30(s32 param_1, s32 param_2, s32 param_3)
{
    s32 link;
    s32 idx;
    u8* rec;

    idx = (u32)*(u16*)(param_1 + 2) * 0xe;
    rec = (u8*)DAT_007ce420 + idx;
    link = FUN_0016deb0(rec[2]);
    FUN_0016dba0(link);
    FUN_003d74f0(param_1, param_2, param_3);
    return 0;
}


// FUN_003d8230
u32 fclCombineMisc003d8230(s32 param_1)
{
    return FUN_001749a0(*(u16*)(param_1 + 6)) != 0;
}

// FUN_003d8830
s32 fclCombineMisc003d8830(s32 param_1)
{
    return *(s32*)(DAT_006a5f44 + param_1 * 8);
}

// FUN_003d9c90
void fclCombineMisc003d9c90(s32 param_1, s32 param_2)
{
    FUN_003dff00(*(s32*)(*(s32*)(*(s32*)(param_2 + 0x14) + 0x1c) + 0x60));
}
