#include "Main/Battle/Panel/bp_mid.h"
#include "Kosaka/k_assert.h"
BattlePanelWork* gBattlePanelWork;

extern u32 func_0021c3f0(s32 texture);
extern void* func_0021cca0(u32 texture, s32 frame);
extern void func_0021d3b0(void* destination, void* frame);
extern void func_0021d8e0(void* destination, const void* layout);
extern void* btlOrderGetUnitByIdx(u16 index);
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
extern u32 func_0021cce0(void* frame);
extern u32 func_00209c00(void);
extern void RpSkyRenderStateSet(s32 state, u32 value);
typedef void (*BpSetRenderState)(u32 state, u32 value);
typedef void (*BpRenderQuad)(void* vertices, u32 count, u32 first, u32 second, u32 third);
extern u32 D_00960090[];
extern u32 D_0096009C[];

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
    void* unit;
    u32 unitIds[0x14];
    u32 texture1;
    u32 texture5;
    s32 count;
    s32 slotCount;
    s32 i;
    u8* slot;
    K_ASSERT(gBattlePanelWork != NULL, 0x47);
    work = (u8*)gBattlePanelWork;
    texture1 = func_0021c3f0(1);
    texture5 = func_0021c3f0(5);
    count = 0;
    for (;;) {
        unit = btlOrderGetUnitByIdx((u16)count);
        if (unit == NULL) {
            break;
        }
        K_ASSERT(count < 0x14, 0x6f);
        if (datCalcIsDead((void*)((u8*)unit + 0xa2c), 0) != 0) {
            K_ASSERT(0, 0x70);
        }
        unitIds[count] = *(u32*)((u8*)unit + 0xa8);
        count++;
    }
    slotCount = count;
    *(u32*)(work + 0x2950) = slotCount;
    for (i = 0; i < slotCount; i++) {
        slot = work + i * 0x420;
        *(u32*)(slot + 0x10) = 0;
        *(u32*)(slot + 0x228) = 0;
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
            *(u32*)(slot + 8) = datCalcGetHp((void*)((u8*)unit + 0xa2c));
            *(u32*)(slot + 0xc) = datCalcGetMaxHp((void*)((u8*)unit + 0xa2c));
        }
        *(u32*)(slot + 0x10) &= ~1u;
        func_00209940(slot + 0x210, 2, 0);
        func_00209940(slot + 0x220, 2, 0);
    }

}
// FUN_002094f0
void func_002094f0(void)
{
    K_ASSERT(gBattlePanelWork != NULL, 0x47);
    *(u32*)gBattlePanelWork &= ~1u;
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

// FUN_002095a0
void func_002095a0(void)
{
    u8* work;
    u32 texture1;
    u32 texture5;
    s32 i;

    K_ASSERT(gBattlePanelWork != NULL, 0x47);
    work = (u8*)gBattlePanelWork;
    texture1 = func_0021c3f0(1);
    texture5 = func_0021c3f0(5);
    if ((~*(u32*)work & 1) == 0) {
        BpSetRenderState* setRenderState = (BpSetRenderState*)D_00960090;

        (*setRenderState)(9, 2);
        (*setRenderState)(0x14, 2);
        (*setRenderState)(8, 0);
        (*setRenderState)(6, 0);
        for (i = 0; i < *(s32*)(work + 0x2950); i++) {
            u8* slot = work + i * 0x420 + 0x10;
            s32 j;

            if ((*(u32*)slot & 1) != 0) {
                continue;
            }
            {
                BpSetRenderState* slotRenderState;
                BpRenderQuad* slotRenderQuad;
                void* frame;

                frame = func_0021cca0(texture1, 1);
                slotRenderState = (BpSetRenderState*)D_00960090;
                (*slotRenderState)(1, func_0021cce0(frame));
                RpSkyRenderStateSet(3, 0x717fb);
                RpSkyRenderStateSet(2, 0x44);
                slotRenderQuad = (BpRenderQuad*)D_0096009C;
                (*slotRenderQuad)(slot + 0x320, 4, 0, 1, 2);
                (*slotRenderQuad)(slot + 0x320, 4, 0, 2, 3);
                (*slotRenderState)(
                    1, func_0021cce0(func_0021cca0(texture5, 4)));
                RpSkyRenderStateSet(3, 0x717fb);
                RpSkyRenderStateSet(2, 0x44);
                (*slotRenderQuad)(slot + 0x220, 4, 0, 1, 2);
                (*slotRenderQuad)(slot + 0x220, 4, 0, 2, 3);
                RpSkyRenderStateSet(3, 0x717fb);
                RpSkyRenderStateSet(2, 0x44);
            }
            for (j = 0; j < *(s32*)(slot + 0x218); j++) {
                s32 value = *(s32*)(slot + 0x210 + j * 4);
                u8* quad;
                BpRenderQuad* renderQuad;

                if ((value == 0) && (value != -1)) {
                    (*setRenderState)(
                        1, func_0021cce0(func_0021cca0(texture1, 0x46)));
                } else {
                    (*setRenderState)(1, func_00209c00());
                }
                quad = slot + 0x10 + (j << 8);
                renderQuad = (BpRenderQuad*)D_0096009C;
                (*renderQuad)(quad, 4, 0, 1, 2);
                (*renderQuad)(quad, 4, 0, 2, 3);
            }
        }
    }
}
