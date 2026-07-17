#include "Battle/battle.h"
#include "Kosaka/k_assert.h"

/* Shared command work is owned by bcm_main.c. */
extern u8* gBcmWork;

extern u32 func_002d5550(void);
extern void func_002518b0(u32 mode);
extern void func_00251e10(void);
extern void bppMain0020fc40(void);
extern void* func_0030c0c0(void);
extern u32 func_00249650(u16 id);
extern u32 datGetFlag(u16 id);
extern u32 datGetScenarioMode(void);
extern u32 bpMisc001ff7f0(u32 id);
extern u32 datGetBadStatusNoDown(s16 unitId);
extern void bcmPanel00222ed0(void);
extern void FUN_0010a4e0(u32, u32, u32, u32);
extern void func_003b0170(u32 value);
extern u32 datCalcIsDead(void* calc, u32 mode);
extern u32 func_002ddc10(u32 unitId);
extern void func_002ddba0(u32 id);
extern u32 RpRandom(void);

static void func_002083d0(void);
static void func_00208860(u32 unitId);

#define BCM_WORD(off) (*(u32*)((u8*)gBcmWork + (off)))
typedef struct BcmCommandEntry
{
    u32 flags;
    u32 type;
    u32 icon;
    u16 id;
} BcmCommandEntry;

// FUN_00207c40
void func_00207c40(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0x77a0) &= ~2u;
}

// FUN_00207c90
void func_00207c90(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0x77a0) &= ~4u;
}

// FUN_00207ce0
void func_00207ce0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0x77a0) &= ~8u;
}

// FUN_00207d30
void func_00207d30(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0x77a0) &= ~0x10u;
}

// FUN_00207d80
void func_00207d80(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0x77a0) &= ~0x20u;
}

// FUN_00207dd0
void func_00207dd0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0x77a0) &= ~0x40u;
}

// FUN_00207e20
void func_00207e20(void)
{
    u8* work;
    s32 mode;
    u32 state;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    state = func_002d5550();
    switch (state) {
    case 0x1d2:
        mode = 0;
        break;
    case 0x1d3:
        mode = 1;
        break;
    case 0x1d4:
        mode = 2;
        break;
    case 0x1d5:
        mode = 3;
        break;
    default:
        K_ASSERT(0, 0x1365);
        break;
    }
    func_002518b0(mode);
    bppMain0020fc40();
    *(u32*)(work + 0x10) = 0xa;
}

// FUN_00207f10
void func_00207f10(void)
{
    u8* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    func_00251e10();
    bppMain0020fc40();
    *(u32*)(work + 0x10) = 0xb;
}

// FUN_00207f70
u32 func_00207f70(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    return BCM_WORD(0) & 0x02000000;
}

// FUN_00207fc0
u32 func_00207fc0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    return BCM_WORD(0) & 0x04000000;
}

// FUN_00208010
u32 func_00208010(void)
{
    void* unit;

    unit = func_0030c0c0();
    if (unit != NULL) {
        return func_00249650(*(u16*)unit);
    }
    return 0;
}

// FUN_00208050
u32 func_00208050(void)
{
    u32 mode;

    mode = func_002d5550();
    if (mode == 0x1d5) {
        goto mode_1d5;
    }
    if (mode == 0x1d4) {
        goto mode_1d4;
    }
    if (mode == 0x1d3) {
        goto mode_1d3;
    }
    switch (mode) {
    case 0x1d2:
        goto mode_1d2;
    default:
        goto done;
    }
mode_1d2:
    if (datGetFlag(0x1307) == 0) {
        return 1;
    }
    goto done;
mode_1d3:
    if (datGetFlag(0x1308) == 0) {
        return 1;
    }
    goto done;
mode_1d4:
    if (datGetFlag(0x1309) == 0) {
        return 1;
    }
    goto done;
mode_1d5:
    if (datGetFlag(0x130a) == 0) {
        return 1;
    }
done:
    return 0;
}

// FUN_00208130
u32 func_00208130(void)
{
    u64 status;

    if (datGetScenarioMode() == 0) {
        if (bpMisc001ff7f0(3) == 0) {
            return 0;
        }
    } else {
        if (bpMisc001ff7f0(9) == 0) {
            return 0;
        }
    }
    if (datGetScenarioMode() == 0 && datGetFlag(0xdf) != 0) {
        return 0;
    }
    if (datGetFlag(0x1306) != 0) {
        return 0;
    }
    if ((gBtl->flags & 0x200000) != 0) {
        return 0;
    }
    if (datGetScenarioMode() != 0) {
        status = (u64)(datGetBadStatusNoDown(9) & 0xfffff);
    } else {
        status = (u64)(datGetBadStatusNoDown(3) & 0xfffff);
    }
    if (status == 1 || status == 2 || status == 4 || status == 8 ||
        status == 0x10 || status == 0x20 || status == 0x40 ||
        status == 0x80000 || status == 0x100000) {
        return 0;
    }
    return 1;
}

// FUN_002082c0
void func_002082c0(u32 value)
{
    u8* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    K_ASSERT((~*(u32*)work & 0x00800000) != 0, 0x13e6);
    *(u32*)(work + 0x779c) = value;
    *(u32*)(work + 0x6d20) = value;
    *(u32*)work |= 0x00800000;
}

// FUN_00208360
void func_00208360(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    K_ASSERT((BCM_WORD(0) & 0x00800000) != 0, 0x13f1);
    func_002083d0();
}

// FUN_002083d0
void func_002083d0(void)
{
    u8* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    K_ASSERT((*(u32*)work & 0x00800000) != 0, 0x13f9);
    func_003b0170(*(u32*)(work + 0x779c));
    *(u32*)work &= ~0x00800000u;
}

// FUN_00208460
void func_00208460(void)
{
    u8* work;
    s32 state;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    state = *(u32*)(work + 0x10);
    switch (state) {
    case 1:
        *(u32*)(work + 4) |= 1;
        bcmPanel00222ed0();
        break;
    case 2:
        *(u32*)(work + 4) |= 2;
        bcmPanel00222ed0();
        break;
    case 3:
        bcmPanel00222ed0();
        break;
    case 4:
        bcmPanel00222ed0();
        break;
    default:
        K_ASSERT(0, 0x1414);
        break;
    }
    FUN_0010a4e0(0, 0, 0, 4);
    *(u32*)(work + 0x10) = 0;
}

// FUN_00208570
void func_00208570(u32* panel)
{
    s32 i;
    u8* entry;

    panel[0] |= 4;
    for (i = 0; i < 8; i++) {
        entry = (u8*)&panel[i];
        entry[0x14] = 0;
        entry[0x15] = 0;
        entry[0x16] = 0;
    }
    ((u8*)panel)[0x17] = 0;
    ((u8*)panel)[0x1b] = 0;
    ((u8*)panel)[0x1f] = 5;
    ((u8*)panel)[0x23] = 5;
    ((u8*)panel)[0x2b] = 0;
    ((u8*)panel)[0x27] = 0;
    ((u8*)panel)[0x33] = 5;
    ((u8*)panel)[0x2f] = 5;
}

// FUN_002085e0
void func_002085e0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0) |= 0x08000000;
}

// FUN_00208630
void func_00208630(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0) &= ~0x08000000u;
}

// FUN_00208680
void func_00208680(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0) |= 0x10000000;
}

// FUN_002086d0
void func_002086d0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0) &= ~0x10000000u;
}

// FUN_00208720
u32 func_00208720(void)
{
    u8* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    if (*(u32*)(work + 0x10) != 0) {
        goto done;
    }
    if ((~*(u32*)work & 0x20) == 0) {
        goto done;
    }
    return 1;
done:
    return 0;
}

// FUN_00208790
#pragma optimization_level 3
#pragma schedule off
void func_00208790(void)
{
    u32 ids[4];
    s32 count;
    s32 i;
    s32 total;
    u8* work;
    BcmCommandEntry* entry;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    count = 0;
    i = 0;
    total = *(s32*)(work + 0x3a8);
    while (i < total) {
        entry = (BcmCommandEntry*)(work + i * 0x18 + 0x2e0);
        switch (entry->type) {
        case 1:
            ids[count++] = entry->id;
            break;
        }
        i++;
    }
    func_00208860((u16)ids[RpRandom() % count]);
}
#pragma optimization_level 2
#pragma schedule off

// FUN_00208860
void func_00208860(u32 unitId)
{
    u32 status;
    u32 id;

    status = datGetBadStatusNoDown((s16)unitId);
    if ((status & 0x80371) != 0) {
        goto done;
    }
    id = unitId & 0xffff;
    switch (id) {
    case 0:
    case 1:
        goto done;
    case 2:
        if (func_002ddc10(unitId) != 0) {
            goto case2_true;
        }
        func_002ddba0(0xa2);
        goto done;
case2_true:
        func_002ddba0(0xa3);
        goto done;
    case 3:
        if (func_002ddc10(unitId) != 0) {
            goto case3_true;
        }
        func_002ddba0(0xf3);
        goto done;
case3_true:
        func_002ddba0(0xf4);
        goto done;
    case 4:
        if (func_002ddc10(unitId) != 0) {
            goto case4_true;
        }
        func_002ddba0(0x158);
        goto done;
case4_true:
        func_002ddba0(0x159);
        goto done;
    case 5:
        if (func_002ddc10(unitId) != 0) {
            goto case5_true;
        }
        func_002ddba0(0x1a1);
        goto done;
case5_true:
        func_002ddba0(0x1a2);
        goto done;
    case 6:
        K_ASSERT(0, 0x149a);
        goto done;
    case 7:
        if (func_002ddc10(unitId) != 0) {
            goto case7_true;
        }
        func_002ddba0(0x1ea);
        goto done;
case7_true:
        func_002ddba0(0x1eb);
        goto done;
    case 8:
        if (func_002ddc10(unitId) != 0) {
            goto case8_true;
        }
        func_002ddba0(0x233);
        goto done;
case8_true:
        func_002ddba0(0x234);
        goto done;
    case 9:
        if (datGetScenarioMode() != 0) {
            goto case9_true;
        }
        func_002ddba0(0x279);
        goto done;
case9_true:
        func_002ddba0(0x46b);
        goto done;
    case 10:
        if (func_002ddc10(unitId) != 0) {
            goto case10_true;
        }
        func_002ddba0(0x2bd);
        goto done;
case10_true:
        func_002ddba0(0x2be);
        goto done;
    default:
        goto done;
    }
done:
    return;
}
