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
