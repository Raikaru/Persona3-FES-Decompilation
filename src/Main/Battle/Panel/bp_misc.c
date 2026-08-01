#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

void* func_0021c5d0(void);
void* func_0021c640(void);
void* func_0021c6b0(void);
u32 itfMesMngInitialize(void*);
void itfMesMngDestroyHandle(u32);
void func_00207e20(void);
void func_00207f10(void);
void func_002db420(s32);
void func_002db650(u32);
void func_002db2a0(s32);
void func_0021f3c0(void);
void bpRushRequestHide(void);
void bpRushClearHideRequest(void);
void func_002083d0(void);


static u32* sBpMisc; // DAT_007ce3ec
extern u8* DAT_007ce3ec;
int datGetFlag();

// FUN_001FF430
u32 FUN_001FF430(u32 id)
{
    s32 i;
    u8* base;
    u8* node;

    base = DAT_007ce3ec;
    K_ASSERT(base != NULL, 0x2f);
    for (i = 0; i < 4; i++)
    {
        node = *(u8**)(base + 0x150 + i * 8);
        while (node != NULL)
        {
            if ((~*(u32*)(node + 0x9c) & 8) == 0 &&
                *(u32*)(node + 0xa8) == id)
            {
                return (u32)node;
            }
            node = *(u8**)(node + 0xa34);
        }
    }
    K_ASSERT(0, 0x3d);
    return 0;
}


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

// FUN_001FF630
u32 FUN_001FF630(u32 index)
{
    u8* base;
    u8* scan;
    u8* node;
    s32 count;

    base = DAT_007ce3ec;
    K_ASSERT(base != NULL, 0x88);
    scan = DAT_007ce3ec;
    K_ASSERT(scan != NULL, 0x5d);
    count = 0;
    node = *(u8**)(scan + 0x150);
    while (node != NULL)
    {
        if ((~*(u32*)(node + 0x9c) & 8) == 0)
        {
            count++;
        }
        node = *(u8**)(node + 0xa34);
    }
    count--;
    node = *(u8**)(base + 0x150);
    while (node != NULL)
    {
        if ((~*(u32*)(node + 0x9c) & 8) == 0)
        {
            if (count == index)
            {
                return *(u16*)(node + 0xa4);
            }
            count--;
        }
        node = *(u8**)(node + 0xa34);
    }
    K_ASSERT(0, 0x99);
    return 0;
}


// W112BpRoot reconstruction: retail request-mask logging and state-transition paths recovered.


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
