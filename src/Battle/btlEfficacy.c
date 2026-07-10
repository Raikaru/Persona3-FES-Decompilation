#include "Battle/btlEfficacy.h"

int func_002d4e10();

// FUN_002d8780
int btlEfficacy002d8780(void)
{
    int v;

    v = func_002d4e10(2, 0x80000) & 0xffff;
    if (v >= 5)
    {
        return -1;
    }
    if (v == 0)
    {
        return -1;
    }
    return 0x6c - v;
}

// FUN_002d87e0
int btlEfficacy002d87e0(void)
{
    int v;

    v = func_002d4e10(2, 0x80000) & 0xffff;
    if (v > 5)
    {
        return -1;
    }
    if (v < 2)
    {
        return -1;
    }
    return 0x72 - v;
}
