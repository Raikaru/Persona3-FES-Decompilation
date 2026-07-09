#include "Kosaka/k_assert.h"

int FUN_003c5470(int task);
int FUN_003c5460();
extern s32 DAT_007ce684;
extern char DAT_006b1fa0[];
int FUN_003d2f00(void);
void FUN_003db580(int param_1);
int FUN_0040c6f0(int param_1);
void FUN_003d06d0(int param_1, s32 param_2, s32 param_3);
void FUN_0040c9a0(int param_1);
void FUN_00401420(int param_1, char* param_2);
s32 FUN_004014e0(int param_1);
void FUN_003c5a20(int param_1);
void FUN_003c6f10(int param_1);
void FUN_003c6f50(int param_1);
void FUN_003ded40(int param_1);
void FUN_003dff00(int param_1);
void FUN_0040cad0(int param_1);
void FUN_003deda0(int param_1);
s32 FUN_003dfac0(int param_1);
void FUN_003e0680(int param_1, void* param_2, s32 param_3);
void func_003d38b0(void);
void FUN_003e0650(int param_1);
void FUN_003ded70(int param_1);
s32 FUN_003c6270(int param_1);
s32 FUN_003df010(int param_1);
s32 FUN_003c6ce0(int param_1);
s32 FUN_003c6d10(int param_1);
s32 FUN_003c6ca0(int param_1);
s32 FUN_003c6cc0(int param_1);
void FUN_0010a4e0(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
extern char LAB_003c5170[];
extern s32 DAT_007ce680;
extern void (*DAT_0096017c)(s32);
extern char DAT_006a4208[];
extern char DAT_006a4270[];
extern char DAT_006a4288[];
extern char DAT_006a4298[];
extern char DAT_006a42b0[];
extern char DAT_006a43b0[];
extern char DAT_006a43c0[];
extern char DAT_006a43d0[];
extern char DAT_006a4648[];
extern char DAT_007cd728[];

s32 FUN_00195540(void);
s32 FUN_00316f70(void);
s32 FUN_00194b20();
void FUN_003174e0(s32 param_1);
void FUN_005225a8();
void FUN_001052b0();
s32 FUN_003cf960(s32 param_1, s32 param_2);
s32 FUN_0016f190(s32 param_1);
void FUN_003c49e0(s32 param_1, s32 param_2);
s32 FUN_003c44d0(s32 param_1, s32 param_2, s32 param_3, s32 param_4);
s32 FUN_003c5760(s32 param_1);
s32 FUN_003c5180(s32 param_1, s32 param_2);
s32 FUN_003dfeb0(s32 param_1);
void FUN_003d5cd0(s32 param_1);
s32 FUN_003c5490(s32 param_1);
void FUN_0040e360(void);
void FUN_003c77a0(void);
void FUN_00100ec0();
void FUN_003c5220(s32 param_1);
s32 FUN_003c5240(s32 param_1, s32 param_2, void* param_3, s32 param_4, s32 param_5);
void FUN_003c5480(s32 param_1);
s32 FUN_003c6c50(s32 param_1);
s32 FUN_003c6c80(s32 param_1);
void FUN_003def80(s32 param_1);
void FUN_003c4e60(s32 param_1, s32 param_2);
void FUN_003c4de0(s32 param_1, s32 param_2, s32 param_3);
void FUN_003def10();
s32 FUN_003def40();
s32 FUN_003dee80();
void FUN_0019d3f0(s32 param_1, s32 param_2);
void FUN_00521408(s32 param_1, s32 param_2, s32 param_3);
void FUN_003c6f50(s32 param_1);

s16 fclCombine003cf8f0(s32 param_1);
s32 fclCombine003d03c0(void);
s32 fclCombine003d0400(void);
s32 fclCombine003d0470(void);
void fclCombine003d1df0(void);
void fclCombine003d2200(void);
s32 fclCombine003d0310(void);
s32 fclCombine003d04d0(void);
s32 fclCombine003d0600(void);
s32 fclCombine003d0610(void);
s32 fclCombine003d3050(s32 param_1);
s32 fclCombine003d3170(s32 param_1);
void fclCombine003d3280(s32 param_1);
void fclCombine003d3760(s32 param_1, s32 param_2, s32 param_3);

// FUN_003cf080 NONMATCHING
void fclCombine003cf080(void)
{
    s32 temp;

    temp = FUN_00195540();
    if (*(s32*)(temp + 0x18) != 0) {
        if (FUN_00316f70() == 0) {
            FUN_00194b20(0, DAT_006a4208, 0x147c, fclCombine003cf080, 0, *(s32*)(temp + 0x18));
        } else {
            FUN_003174e0(*(s32*)(temp + 0x18));
        }
    }
    DAT_0096017c(temp);
}

// FUN_003cf120
s32 fclCombine003cf120(void)
{
    DAT_007ce680 = FUN_003c44d0(0x40, 0, 0, 0);
    return *(s32*)(DAT_007ce680 + 0x24);
}

// FUN_003cf160 NONMATCHING
s32 fclCombine003cf160(s32 param_1, s32 param_2)
{
    u32 hi;
    u32 mid;

    FUN_005225a8(DAT_007cd728, DAT_006a4270, 0x66);
    hi = (u32)param_1 >> 0x10;
    mid = ((u32)param_1 & 0xff00) >> 8;
    FUN_005225a8(DAT_006a4288, param_1, hi, mid, param_1 & 0xff);
    FUN_001052b0(DAT_006a4288, param_1, hi, mid, param_1 & 0xff);
    return FUN_003cf960(param_1, param_2) != 0;
}

// FUN_003cf240 NONMATCHING
s32 fclCombine003cf240(s32 param_1, u16 param_2)
{
    s16 index;
    s32 base;
    u32 hi;
    u32 mid;

    FUN_005225a8(DAT_007cd728, DAT_006a4270, 0x7e);
    hi = (u32)param_1 >> 0x10;
    mid = ((u32)param_1 & 0xff00) >> 8;
    FUN_005225a8(DAT_006a4298, param_1, hi, mid, param_1 & 0xff);
    FUN_001052b0(DAT_006a4298, param_1, hi, mid, param_1 & 0xff);
    index = fclCombine003cf8f0(param_1);
    if (index != -1) {
        base = index * 0x14 + *(s32*)(DAT_007ce680 + 0x24);
        *(u16*)(base + 4) = *(u16*)(base + 4) | (param_2 & 0xff00);
        FUN_005225a8(DAT_007cd728, DAT_006a4270, 0x83);
        FUN_005225a8(DAT_006a42b0, index);
        FUN_001052b0(DAT_006a42b0, index);
    }
    return index != -1;
}

// FUN_003cf3a0 NONMATCHING
s32 fclCombine003cf3a0(s32 param_1)
{
    u16 flags;
    s32 i;
    u16* entry;

    entry = (u16*)(*(s32*)(DAT_007ce680 + 0x24) + 4);
    i = 0;
    do {
        if (i >= 3) {
            return 0;
        }
        flags = *entry;
        if ((flags & 1) != 0 && (flags & 8) != 0) {
            if (param_1 != 0 && (flags & 0x100) != 0) {
                return *(s32*)(entry + 2);
            }
            if (param_1 == 0 && (flags & 0x100) == 0) {
                return *(s32*)(entry + 2);
            }
        }
        entry += 10;
        i++;
    } while (1);
}

// FUN_003cf440 NONMATCHING
void fclCombine003cf440(void)
{
    u16 flags;
    s32 node;
    u16* entry;
    s32 i;

    entry = (u16*)(*(s32*)(DAT_007ce680 + 0x24) + 4);
    for (i = 0; i < 3; i++) {
        flags = *entry;
        if ((flags & 1) != 0) {
            if ((flags & 8) != 0 || (flags & 2) != 0) {
                *entry |= 0x400;
            }
            if (FUN_0016f190(0x1419) == 0) {
                *entry |= 0x800;
            }
        }
        entry += 10;
    }
    node = *(s32*)(DAT_007ce680 + 4);
    while (node != 0) {
        node = *(s32*)(node + 0x10);
        FUN_003c49e0(DAT_007ce680, DAT_007ce680 + 4);
    }
}

// FUN_003cf520 NONMATCHING
void fclCombine003cf520(void)
{
    u16 flags;
    u16* entry;
    s32 i;

    entry = (u16*)(*(s32*)(DAT_007ce680 + 0x24) + 4);
    for (i = 0; i < 3; i++) {
        flags = *entry;
        if ((flags & 1) != 0) {
            if ((flags & 8) != 0 || (flags & 2) != 0) {
                *entry |= 0x400;
            }
            if (FUN_0016f190(0x1419) == 0) {
                *entry |= 0x800;
            }
        }
        entry += 10;
    }
}

// FUN_003cf5d0
void fclCombine003cf5d0(void)
{
    s32 i;
    s16 flags;
    s16* entry;

    entry = (s16*)(*(s32*)(DAT_007ce680 + 0x24) + 4);
    for (i = 0; i < 3; i++) {
        flags = *entry;
        if ((flags & 1) != 0 && (flags & 8) == 0) {
            *entry = flags | 0x800;
        }
        entry = entry + (10);
    }
}

// FUN_003cf630
s32 fclCombine003cf630(void)
{
    s32 i;
    s16 flags;
    s16* entry;

    entry = (s16*)(*(s32*)(DAT_007ce680 + 0x24) + 4);
    if (*(s32*)(DAT_007ce680 + 4) != 0) {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        flags = *entry;
        if ((flags & 1) != 0 && ((flags & 2) != 0 || (flags & 0x10) != 0)) {
            return 1;
        }
        entry = entry + (10);
    }
    return 0;
}

// FUN_003cf8f0 NONMATCHING
s16 fclCombine003cf8f0(s32 param_1)
{
    s16* entry;
    s32 i;

    entry = (s16*)(*(s32*)(DAT_007ce680 + 0x24) + 4);
    i = 0;
    while (1) {
        if (i >= 3) {
            return -1;
        }
        if ((*entry & 1) != 0 && *(s32*)(entry + 2) == param_1) {
            break;
        }
        entry += 10;
        i++;
    }
    return (s16)i;
}

// FUN_003cfac0 NONMATCHING
s32 fclCombine003cfac0(u16* param_1)
{
    u16 flags;
    s32 ret;
    s32 i;
    u16* entry;

    ret = 1;
    entry = (u16*)(*(s32*)(DAT_007ce680 + 0x24) + 4);
    for (i = 0; i < 3; i++) {
        if (entry != param_1) {
            flags = *entry;
            if ((flags & 1) != 0 && (flags & 8) != 0 && (flags & 0x100) == (*param_1 & 0x100)) {
                *entry = flags | 0x400;
                if ((flags & 4) == 0) {
                    ret = 0;
                }
            }
        }
        entry += 10;
    }
    return ret;
}

// FUN_003d02e0
s32 fclCombine003d02e0(void)
{
    return DAT_007ce684;
}

// FUN_003d02f0
void fclCombine003d02f0(void)
{
    fclCombine003d0310();
}

// FUN_003d0310 NONMATCHING
s32 fclCombine003d0310(void)
{
    s32 task;
    s32 child;

    task = fclCombine003d04d0();
    child = FUN_00194b20(0, DAT_006a43b0, 10, fclCombine003d03c0, 0, 0);
    *(s32*)(task + 0xcc) = child;
    child = FUN_00194b20(child, DAT_006a43c0, 0x18b6, fclCombine003d0400, 0, 0);
    FUN_00194b20(child, DAT_006a43d0, 0x106f, fclCombine003d0470, 0, 0);
    return task;
}

#pragma optimization_level 0
// FUN_003d03c0
s32 fclCombine003d03c0(void)
{
    if (fclCombine003d0610() != 0) {
        return -1;
    }
    return 0;
}
#pragma optimization_level 2

// FUN_003d0400
s32 fclCombine003d0400(void)
{
    u32* work;

    work = (u32*)FUN_003c5460(DAT_007ce684);
    FUN_003d21d0();
    *work |= 2;
    FUN_003e0680(work[0x35], fclCombine003d1df0, 0);
    *work &= ~2;
    return 0;
}

// FUN_003d0470
s32 fclCombine003d0470(void)
{
    s32 work;

    work = FUN_003c5460(DAT_007ce684);
    FUN_003e0680(*(s32*)(work + 0xd4), fclCombine003d1df0, 0);
    return 0;
}

// FUN_003d04b0
void fclCombine003d04b0(void)
{
    fclCombine003d0600();
}

// FUN_003d04d0 NONMATCHING
s32 fclCombine003d04d0(void)
{
    s32 task;
    s32 work;

    if (DAT_007ce684 == 0) {
        task = FUN_003c5180((s32)fclCombine003d2200, 0xe0);
        DAT_007ce684 = task;
        work = FUN_003c5460(task);
        *(s32*)(work + 8) = 1;
        *(s32*)(work + 0xd4) = FUN_003dfeb0(work);
        FUN_003d5cd0(work + 0x2c);
        return task;
    }
    return 0;
}

// FUN_003d0560 NONMATCHING
void fclCombine003d0560(void)
{
    s32 work;

    if (DAT_007ce684 != 0) {
        work = FUN_003c5460();
        FUN_0040e360();
        FUN_003c77a0();
        if (*(s32*)(work + 0xbc) == 0) {
            FUN_00100ec0(*(s32*)(work + 0xc4));
            FUN_00100ec0(*(s32*)(work + 0xd8));
        } else {
            FUN_00100ec0();
            *(s32*)(work + 0xbc) = 0;
        }
        FUN_003dff00(*(s32*)(work + 0xd4));
        FUN_003c5220(DAT_007ce684);
    }
    DAT_007ce684 = 0;
}

// FUN_003d0600
s32 fclCombine003d0600(void)
{
    return DAT_007ce684 != 0;
}

// FUN_003d0610 NONMATCHING
s32 fclCombine003d0610(void)
{
    s32 work;

    if (FUN_003c5490(DAT_007ce684) == 0) {
        return 0;
    }
    work = FUN_003c5460(DAT_007ce684);
    FUN_0040e360();
    FUN_003c77a0();
    if (*(s32*)(work + 0xbc) == 0) {
        FUN_00100ec0(*(s32*)(work + 0xc4));
        FUN_00100ec0(*(s32*)(work + 0xd8));
    } else {
        FUN_00100ec0();
        *(s32*)(work + 0xbc) = 0;
    }
    FUN_003dff00(*(s32*)(work + 0xd4));
    FUN_003c5220(DAT_007ce684);
    DAT_007ce684 = 0;
    return 1;
}

// FUN_003d21d0
s32 fclCombine003d21d0(void)
{
    FUN_003c5760(DAT_007ce684);
    return 0;
}

// FUN_003d2640
s32 fclCombine003d2640(s32 param_1)
{
    s32 task;
    s32 temp;
    s32* work;

    task = *(s32*)(param_1 + 0x28);
    if (task == 0 || (temp = *(s32*)(task + 0x14)) == 0) {
        return -1;
    }
    if ((*(u32*)(temp + 0x14) & 8) != 0) {
        work = (s32*)FUN_003c5470(task);
        *(s32*)(param_1 + 0x28) = 0;
        return *work;
    }
    return -1;
}

// FUN_003d26c0
s32 fclCombine003d26c0(s32 param_1, s32 param_2)
{
    s32 temp;

    FUN_003c5460();
    temp = FUN_003c5470(param_2);
    *(s32*)(temp + 0xc) = 0;
    *(s32*)(temp + 8) = 0;
    *(s32*)(temp + 4) = 0;
    return 0;
}

// FUN_003d2710
s32 fclCombine003d2710(s32 param_1, s32 param_2)
{
    FUN_003c5470(param_2);
    return 0;
}

// FUN_003d2ce0
s32 fclCombine003d2ce0(s32 param_1)
{
    s32 task;
    s32 temp;

    task = *(s32*)(param_1 + 0x14);
    if (task == 0 || *(s32*)(task + 0x14) == 0) {
        return -1;
    }
    if ((*(u32*)(*(s32*)(task + 0x14) + 0x14) & 8) != 0) {
        temp = FUN_003c5460(DAT_007ce684);
        FUN_003d06d0(temp, 4, 1);
        temp = FUN_003c5470(task);
        *(s32*)(param_1 + 0x14) = 0;
        return *(s32*)temp;
    }
    return -1;
}

// FUN_003d2d80
s32 fclCombine003d2d80(s32 param_1, s32 param_2)
{
    s32 temp;

    FUN_003c5460();
    temp = FUN_003c5470(param_2);
    *(s32*)(temp + 8) = FUN_003d2f00();
    return 0;
}

// FUN_003d2dd0
s32 fclCombine003d2dd0(s32 param_1, s32 param_2)
{
    FUN_003c5470(param_2);
    return 0;
}

// FUN_003d2e00 NONMATCHING
s32 fclCombine003d2e00(s32 param_1, s32 param_2)
{
    s32* work;
    s32 temp;

    work = (s32*)FUN_003c5470(param_2);
    if (fclCombine003d3010(work[2]) != 0) {
        return (s32)LAB_003c5170;
    }
    temp = fclCombine003d3050(work[2]);
    if (temp == -1) {
        if (fclCombine003d3170(work[2]) != 0) {
            *work = 6;
            temp = FUN_003c5460(DAT_007ce684);
            FUN_003d06d0(temp, 10, 1);
        }
    } else {
        *work = temp - 1;
        fclCombine003d3280(work[2]);
        temp = FUN_003c5460(DAT_007ce684);
        FUN_003d06d0(temp, 10, 1);
    }
    return 0;
}

// FUN_003d3050 NONMATCHING
s32 fclCombine003d3050(s32 param_1)
{
    s32 item;
    s32 temp;
    s32* result;
    s32 value;

    if (param_1 == 0 || (item = *(s32*)param_1) == 0) {
        return 0;
    }
    temp = FUN_003c6c50(*(s32*)(item + 8));
    if (temp == 0) {
        return -1;
    }
    if (FUN_003df010(*(s32*)(item + 0x10)) == 0) {
        return -1;
    }
    FUN_003def80(*(s32*)(item + 0x10));
    result = (s32*)temp;
    if (*result != 7) {
        temp = FUN_003c5460(DAT_007ce684);
        FUN_003d06d0(temp, 0, 0);
    }
    fclCombine003d3760(item, 0, 1);
    value = *(s32*)(result[5] + 0xc);
    temp = FUN_003c5460(DAT_007ce684);
    *(s32*)(temp + 0x10) = value;
    FUN_0010a4e0(0, 0, 0, 1);
    return *result;
}

// FUN_003d3170 NONMATCHING
s32 fclCombine003d3170(s32 param_1)
{
    s32 item;
    s32 temp;
    s32 value;

    if (param_1 == 0 || (item = *(s32*)param_1) == 0) {
        return 0;
    }
    temp = *(s32*)(item + 8);
    if (FUN_003c6c80(temp) == 0) {
        return 0;
    }
    if (FUN_003df010(*(s32*)(item + 0x10)) == 0) {
        return 0;
    }
    value = *(s32*)(temp + 0xc);
    FUN_003c4e60(temp, temp + 4);
    FUN_003def80(*(s32*)(item + 0x10));
    FUN_003c4de0(temp, temp + 4, value);
    fclCombine003d3760(item, 0, 1);
    FUN_0010a4e0(0, 0, 0, 2);
    FUN_003c6f50(temp);
    return 1;
}

// FUN_003d3010
s32 fclCombine003d3010(s32 param_1)
{
    if (param_1 == 0 || *(s32*)param_1 == 0) {
        return 1;
    }
    return (*(u32*)(*(s32*)param_1 + 4) & 1) != 0;
}

// FUN_003d3280
void fclCombine003d3280(s32 param_1)
{
    s32 temp;

    if (param_1 == 0) {
        goto end;
    }
    temp = *(s32*)param_1;
    if (temp != 0) {
        goto body;
    }
end:
    return;
body:
    temp = *(s32*)(temp + 8);
    FUN_003c6f10(temp);
    FUN_003c6f50(temp);
}

// FUN_003d35c0
s32 fclCombine003d35c0(s32 param_1, s32 param_2)
{
    s32 temp;

    temp = FUN_003c5470(param_2);
    FUN_003ded40(*(s32*)(temp + 0x10));
    FUN_003dff00(*(s32*)(temp + 0x14));
    FUN_003c5a20(*(s32*)(temp + 8));
    return 0;
}

// FUN_003d3ca0
s32 fclCombine003d3ca0(s32 param_1, s32 param_2)
{
    s32 temp;

    temp = FUN_003c5470(param_2);
    *(s32*)(temp + 4) = 1;
    return 0;
}

// FUN_003d3cd0
s32 fclCombine003d3cd0(s32 param_1, s32 param_2)
{
    s32 temp;

    FUN_003c5470(param_2);
    temp = FUN_003c5460(DAT_007ce684);
    FUN_003d06d0(temp, 0, 1);
    return 0;
}

// FUN_003d3620 NONMATCHING
s32 fclCombine003d3620(s32 param_1, s32 param_2)
{
    s32 temp;
    s32 item;
    s32 state;

    temp = FUN_003c5470(param_2);
    item = *(s32*)(temp + 8);
    FUN_003e0650(*(s32*)(temp + 0x14));
    FUN_003ded70(*(s32*)(temp + 0x10));
    state = FUN_003c6270(item);
    if (state == 2) {
        goto state2;
    }
    if (state == 3) {
        if (FUN_003df010(*(s32*)(temp + 0x10)) != 0) {
            return (s32)LAB_003c5170;
        }
    }
    goto afterState;
state2:
    FUN_003c6f10(item);
    FUN_003c6f50(item);
afterState:
    if (FUN_003c6ce0(item) != 0 || FUN_003c6d10(item) != 0) {
        FUN_0010a4e0(0, 0, 0, 0);
    }
    if (FUN_003c6ca0(item) != 0 || FUN_003c6cc0(item) != 0) {
        FUN_0010a4e0(0, 0, 0, 5);
    }
    return 0;
}

// FUN_003d3b00
s32 fclCombine003d3b00(s32 param_1, s32 param_2)
{
    s32 temp;
    s32 ret;

    temp = FUN_003c5470(param_2);
    FUN_003deda0(*(s32*)(temp + 0x10));
    ret = FUN_003dfac0(*(s32*)(temp + 0x10));
    FUN_003e0680(*(s32*)(temp + 0x14), func_003d38b0, ret);
    return 0;
}

// FUN_003d3c20
s32 fclCombine003d3c20(s32 param_1)
{
    s32 task;
    s32 temp;

    task = *(s32*)(param_1 + 0x18);
    if (task == 0 || *(s32*)(task + 0x14) == 0) {
        return -1;
    }
    if ((*(u32*)(*(s32*)(task + 0x14) + 0x14) & 8) != 0) {
        temp = FUN_003c5470(task);
        *(s32*)(param_1 + 0x18) = 0;
        return *(s32*)temp;
    }
    return -1;
}

// FUN_003d4c80
s32 fclCombine003d4c80(s32 param_1, s32 param_2)
{
    s32 temp;

    FUN_003c5460();
    temp = FUN_003c5470(param_2);
    FUN_003db580(*(s32*)(temp + 0x39c));
    return 0;
}
// FUN_003d4cd0
void fclCombine003d4cd0(u32* param_1, s32 param_2)
{
    s32 i;
    u32* out;

    if (param_2 == 0) {
        FUN_0019d3f0((s32)DAT_006a4648, 0x82f);
    }
    FUN_00521408(param_2, 0, 0x18);
    out = (u32*)param_2;
    if ((*param_1 & 2) != 0) {
        *out |= 1;
    }
    *(s16*)(out + 1) = (s16)param_1[2];
    *(u16*)((s32)out + 6) = *(u16*)(param_1[0xe7] + 0x22);
    for (i = 0; i < *(s32*)(param_1[0xe7] + 0xc); i++) {
        if (*(s32*)(*(s32*)(param_1[0xe7] + 0x18) + i * 4) == 0) {
            FUN_0019d3f0((s32)DAT_006a4648, 0x836);
        }
        *(u16*)((s32)out + i * 2 + 8) = *(u16*)(*(s32*)(*(s32*)(param_1[0xe7] + 0x18) + i * 4) + 2);
    }
}


// FUN_003d4f30
s32 fclCombine003d4f30(s32 param_1, s32 param_2)
{
    s32 temp;

    FUN_003c5460();
    temp = FUN_003c5470(param_2);
    *(s32*)(temp + 8) = FUN_0040c6f0(0);
    *(s32*)(temp + 4) = 1;
    return 0;
}

// FUN_003d4e90
s32 fclCombine003d4e90(s32 param_1)
{
    s32 task;
    s32 temp;

    task = *(s32*)(param_1 + 0x20);
    if (task == 0 || *(s32*)(task + 0x14) == 0) {
        return -1;
    }
    if ((*(u32*)(*(s32*)(task + 0x14) + 0x14) & 8) != 0) {
        temp = FUN_003c5470(task);
        *(s32*)(param_1 + 0x20) = 0;
        task = FUN_003c5460(DAT_007ce684);
        FUN_003d06d0(task, 7, 1);
        return *(s32*)temp;
    }
    return -1;
}

// FUN_003d4f90
s32 fclCombine003d4f90(s32 param_1, s32 param_2)
{
    s32 temp;

    temp = FUN_003c5470(param_2);
    FUN_0040c9a0(*(s32*)(temp + 8));
    temp = FUN_003c5460(DAT_007ce684);
    FUN_003d06d0(temp, 0, 1);
    return 0;
}

// FUN_003d53e0
s32 fclCombine003d53e0(s32 param_1, s32 param_2)
{
    s32 temp;

    temp = FUN_003c5470(param_2);
    FUN_0040cad0(*(s32*)(temp + 8));
    return 0;
}

// FUN_003d5420
s32 fclCombine003d5420(void)
{
    s32 temp;
    s32 task;

    task = 0;
    temp = FUN_003c5460(DAT_007ce684);
    if (temp != 0) {
        task = *(s32*)(temp + 0x24);
    }
    if (task != 0) {
        goto body;
    }
    return 0;
body:
    temp = FUN_003c5470(task);
    FUN_00401420(*(s32*)(temp + 8), DAT_006b1fa0);
    return 0;
}

// FUN_003d54a0
s32 fclCombine003d54a0(void)
{
    s32 temp;
    s32 task;

    task = 0;
    temp = FUN_003c5460(DAT_007ce684);
    if (temp != 0) {
        task = *(s32*)(temp + 0x24);
    }
    if (task == 0) {
        return 1;
    }
    temp = FUN_003c5470(task);
    return FUN_004014e0(*(s32*)(temp + 8)) != 0;
}
