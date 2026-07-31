#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBpMisc; // DAT_007ce3ec
int datGetFlag();

// FUN_001ff500
int bpMisc001ff500(u32 param_1)
{
    int base;
    int p;

    base = (int)sBpMisc;
    K_ASSERT(sBpMisc != NULL, 0x47);
    p = *(int*)(base + 0x150);
    while (p != 0) {
        if ((~*(u32*)(p + 0x9c) & 8) == 0 && *(u16*)(p + 0xa4) == param_1) {
            return p;
        }
        p = *(int*)(p + 0xa34);
    }
    K_ASSERT(0, 0x52);
    return 0;
}

// FUN_001ff5b0
int bpMisc001ff5b0(void)
{
    int base;
    int count;
    int p;

    base = (int)sBpMisc;
    K_ASSERT(sBpMisc != NULL, 0x5d);
    count = 0;
    for (p = *(int*)(base + 0x150); p != 0; p = *(int*)(p + 0xa34)) {
        if ((~*(u32*)(p + 0x9c) & 8) == 0) {
            count++;
        }
    }
    return count;
}

// FUN_001ff7f0
u32 bpMisc001ff7f0(u32 param_1)
{
    int base;
    int p;

    base = (int)sBpMisc;
    K_ASSERT(sBpMisc != NULL, 0xf1);
    p = *(int*)(base + 0x150);
    while (p != 0) {
        if ((~*(u32*)(p + 0x9c) & 8) == 0 && *(u16*)(*(int*)(p + 0xa2c) + 2) == param_1) {
            return 1;
        }
        p = *(int*)(p + 0xa34);
    }
    return 0;
}

// FUN_001ff740
u32 bpMisc001ff740(void)
{
    u32 uVar1;
    int lVar2;

    lVar2 = datGetFlag(0x1317);
    if (lVar2 != 0) {
        uVar1 = 2;
    } else {
        lVar2 = datGetFlag(0x141);
        if (lVar2 != 0) {
            lVar2 = datGetFlag(0x140);
            K_ASSERT(lVar2 == 0, 0xe1);
            uVar1 = 0;
        } else {
            lVar2 = datGetFlag(0x140);
            if (lVar2 != 0) {
                uVar1 = 1;
            } else {
                uVar1 = 2;
            }
        }
    }
    return uVar1;
}
