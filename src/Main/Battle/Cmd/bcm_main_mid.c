#include "Utils.h"
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
extern u32 datGetBadStatusNoDown(u16 unitId);
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

// FUN_00207e20 NONMATCHING
void func_00207e20(void)
{
    u32 mode;
    u32 state;

    K_ASSERT(gBcmWork != NULL, 0x164);
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
        mode = 0;
        break;
    }
    func_002518b0(mode);
    bppMain0020fc40();
    BCM_WORD(0x10) = 0xa;
}

// FUN_00207f10 NONMATCHING
void func_00207f10(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    func_00251e10();
    bppMain0020fc40();
    BCM_WORD(0x10) = 0xb;
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

// FUN_00208050 NONMATCHING
u32 func_00208050(void)
{
    u32 mode;
    u16 flag;

    mode = func_002d5550();
    switch (mode) {
    case 0x1d2:
        flag = 0x1307;
        break;
    case 0x1d3:
        flag = 0x1308;
        break;
    case 0x1d4:
        flag = 0x1309;
        break;
    case 0x1d5:
        flag = 0x130a;
        break;
    default:
        return 0;
    }
    return datGetFlag(flag) == 0;
}

// FUN_00208130 NONMATCHING
u32 func_00208130(void)
{
    u32 scenario;
    u32 status;

    scenario = datGetScenarioMode();
    if (bpMisc001ff7f0(scenario != 0 ? 9 : 3) == 0) {
        return 0;
    }
    scenario = datGetScenarioMode();
    if (scenario == 0 && datGetFlag(0xdf) != 0) {
        return 0;
    }
    if (datGetFlag(0x1306) != 0) {
        return 0;
    }
    status = datGetBadStatusNoDown(scenario != 0 ? 9 : 3);
    switch (status) {
    case 1:
    case 2:
    case 4:
    case 8:
    case 0x10:
    case 0x20:
    case 0x40:
    case 0x80000:
    case 0x100000:
        return 0;
    default:
        return 1;
    }
}

// FUN_002082c0 NONMATCHING
void func_002082c0(u32 value)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    K_ASSERT((BCM_WORD(0) & 0x00800000) == 0, 0x13e6);
    BCM_WORD(0x779c) = value;
    BCM_WORD(0x6d20) = value;
    BCM_WORD(0) |= 0x00800000;
}

// FUN_00208360
void func_00208360(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    K_ASSERT((BCM_WORD(0) & 0x00800000) != 0, 0x13f1);
    func_002083d0();
}

// FUN_002083d0 NONMATCHING
void func_002083d0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    K_ASSERT((BCM_WORD(0) & 0x00800000) != 0, 0x13f9);
    func_003b0170(BCM_WORD(0x779c));
    BCM_WORD(0) &= ~0x00800000u;
}

// FUN_00208460 NONMATCHING
void func_00208460(void)
{
    u32* work;
    u32 state;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = (u32*)gBcmWork;
    state = work[4];
    switch (state) {
    case 1:
        work[1] |= 1;
        bcmPanel00222ed0();
        break;
    case 2:
        work[1] |= 2;
        bcmPanel00222ed0();
        break;
    case 3:
    case 4:
        bcmPanel00222ed0();
        break;
    default:
        K_ASSERT(0, 0x1414);
        break;
    }
    FUN_0010a4e0(0, 0, 0, 4);
    work[4] = 0;
}

// FUN_00208570 NONMATCHING
void func_00208570(u8* panel)
{
    s32 i;

    panel[0] |= 4;
    for (i = 0; i < 8; i++) {
        panel[i * 4 + 0x14] = 0;
        panel[i * 4 + 0x15] = 0;
        panel[i * 4 + 0x16] = 0;
    }
    panel[0x17] = 0;
    panel[0x1b] = 0;
    panel[0x1f] = 5;
    panel[0x23] = 5;
    panel[0x2b] = 0;
    panel[0x27] = 0;
    panel[0x33] = 5;
    panel[0x2f] = 5;
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

// FUN_00208720 NONMATCHING
u32 func_00208720(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    return BCM_WORD(0x10) == 0 && (BCM_WORD(0) & 0x20) == 0;
}

// FUN_00208790 NONMATCHING
void func_00208790(void)
{
    u16 ids[32];
    u32 count;
    u32 i;
    u8* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    count = 0;
    for (i = 0; i < *(u32*)(work + 0x3a8); i++) {
        u8* entry = work + i * 0x18;
        if (*(u32*)(entry + 0x2e4) == 1 && count < ARRAY_SIZE(ids)) {
            ids[count++] = *(u16*)(entry + 0x2ec);
        }
    }
    if (count != 0) {
        func_00208860(ids[RpRandom() % count]);
    }
}

// FUN_00208860 NONMATCHING
void func_00208860(u32 unitId)
{
    u32 status;
    u32 id;

    status = datGetBadStatusNoDown((u16)unitId);
    if ((status & 0x80371) != 0 || (unitId & 0xffff) >= 0xb) {
        return;
    }
    id = unitId & 0xffff;
    switch (id) {
    case 0:
        func_002ddba0(func_002ddc10(unitId) ? 0xa3 : 0xa2);
        break;
    case 1:
        func_002ddba0(func_002ddc10(unitId) ? 0xf4 : 0xf3);
        break;
    case 2:
        func_002ddba0(func_002ddc10(unitId) ? 0x159 : 0x158);
        break;
    case 3:
        func_002ddba0(func_002ddc10(unitId) ? 0x1a2 : 0x1a1);
        break;
    case 4:
        func_002ddba0(datGetScenarioMode() ? 0x46b : 0x279);
        break;
    case 5:
        func_002ddba0(func_002ddc10(unitId) ? 0x2be : 0x2bd);
        break;
    case 6:
        func_002ddba0(0x1ea);
        break;
    case 7:
        func_002ddba0(0x233);
        break;
    case 8:
        func_002ddba0(0x234);
        break;
    case 9:
        func_002ddba0(0x1ea);
        break;
    case 10:
        func_002ddba0(0x1ea);
        break;
    default:
        K_ASSERT(0, 0x149a);
        break;
    }
}
