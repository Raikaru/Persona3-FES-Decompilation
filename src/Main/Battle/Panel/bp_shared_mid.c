#include "Main/Battle/Panel/bp_mid.h"
#include "Utils.h"
#include "Kosaka/k_assert.h"

BattlePanelWork* gBattlePanelWork;

extern u32 func_0021c3f0(s32 texture);
extern void* func_0021cca0(u32 texture, s32 frame);
extern void func_0021d3b0(void* destination, void* frame);
extern void func_0021d8e0(void* destination, const void* layout);
extern void func_0021d950(void* destination, const void* color);
extern void* btlOrderGetUnitByIdx(u16 index);
extern u32 btlOrderGetActionPlaying(void);
extern u32 datCalcIsDead(void* calc, u32 mode);
extern void* func_001ff430(u32 id);
extern u32 datCalcGetHp(void* calc);
extern u32 datCalcGetMaxHp(void* calc);
extern void func_00208f60(void);
extern void func_00209a00(void* dst, u32 count, u32 slot, u32 align, f32 scale, const f32* origin);
extern void func_00209940(void* dst, u32 capacity, s32 value);
extern void func_0020c320(void* dst, u32 mode);
extern void func_0020c400(void* dst, u32 mode);
extern void func_0020c500(void* dst, u32 mode);
extern void func_0020c590(void* dst);
extern void func_0020c660(void* dst);

static u8* BP_WORK(void)
{
    return (u8*)gBattlePanelWork;
}

// FUN_00208ad0
void func_00208ad0(BattlePanelWork* work)
{
    K_ASSERT(gBattlePanelWork == NULL, 0x4e);
    *(u32*)work = 0;
    gBattlePanelWork = work;
}

// FUN_00208b20
void func_00208b20(void)
{
    gBattlePanelWork = NULL;
}

/*
 * The panel keeps a compact list of living battle units followed by one
 * 0x240-byte status slot per unit.  Keep the list construction in one place;
 * rendering and animation updates consume only these slots.
 */
// FUN_00208b30 NONMATCHING
void func_00208b30(void)
{
    u8* work;
    u32 count;
    u32 i;
    u32 slotCount;

    K_ASSERT(gBattlePanelWork != NULL, 0x47);
    work = BP_WORK();
    count = 0;
    for (i = 0; i < 0x14; i++) {
        void* unit = btlOrderGetUnitByIdx((u16)i);
        if (unit == NULL) {
            break;
        }
        if (datCalcIsDead((u8*)unit + 0xa2c, 0) != 0) {
            K_ASSERT(0, 0x70);
            continue;
        }
        if (count < 0x14) {
            *(u32*)(work + 0x80 + count * 4) = *(u32*)((u8*)unit + 0xa8);
            count++;
        }
    }
    /* Enemy and reserve lists use the same status-slot representation. */
    slotCount = count;
    *(u32*)(work + 0x2950) = slotCount;
    for (i = 0; i < slotCount; i++) {
        u8* slot = work + 0x2960 + i * 0x240;
        *(u32*)(slot + 0x10) = 0;
        *(u32*)(slot + 0x228) = 0;
        *(u32*)(slot + 8) = 0;
        *(u32*)(slot + 0xc) = 0;
    }
    func_00208f60();
    *(u32*)work |= 1;
}

// FUN_00208f60 NONMATCHING
void func_00208f60(void)
{
    u8* work;
    u32 count;
    u32 i;

    K_ASSERT(gBattlePanelWork != NULL, 0x47);
    work = BP_WORK();
    count = *(u32*)(work + 0x2950);
    for (i = 0; i < count; i++) {
        u8* slot = work + 0x2960 + i * 0x240;
        u32 unitId = *(u32*)(slot + 4);
        void* unit = func_001ff430(unitId);
        if (unit != NULL) {
            *(u32*)(slot + 8) = datCalcGetHp((u8*)unit + 0xa2c);
            *(u32*)(slot + 0xc) = datCalcGetMaxHp((u8*)unit + 0xa2c);
        }
        *(u32*)(slot + 0x10) &= ~2u;
        func_00209940(slot + 0x210, 2, 0);
        func_00209940(slot + 0x220, 2, 0);
    }
}

// FUN_002094f0 NONMATCHING
void func_002094f0(void)
{
    K_ASSERT(gBattlePanelWork != NULL, 0x47);
    *(u32*)BP_WORK() &= ~2u;
}

// FUN_00209540
void func_00209540(void)
{
    u32* work;

    K_ASSERT(gBattlePanelWork != NULL, 0x47);
    work = (u32*)gBattlePanelWork;
    if ((~*work & 1) != 0) {
        return;
    } else {
        func_00208f60();
    }
}

// FUN_002095a0 NONMATCHING
void func_002095a0(void)
{
    u8* work;
    u32 i;
    u32 count;

    K_ASSERT(gBattlePanelWork != NULL, 0x47);
    work = BP_WORK();
    if ((*(u32*)work & 1) != 0) {
        return;
    }
    count = *(u32*)(work + 0x2950);
    for (i = 0; i < count; i++) {
        u8* slot = work + 0x2960 + i * 0x240;
        if ((*(u32*)(slot + 0x10) & 1) != 0) {
            continue;
        }
        func_00209940(slot + 0x210, 2, 0);
        func_00209940(slot + 0x220, 2, 0);
    }
}
