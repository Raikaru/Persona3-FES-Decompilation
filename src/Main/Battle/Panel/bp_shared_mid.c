#include "Main/Battle/Panel/bp_mid.h"
#include "Battle/btlUnit.h"
#include "Kosaka/k_assert.h"
BattlePanelWork* gBattlePanelWork;

extern u32 func_0021c3f0(s32 texture);
extern void* func_0021cca0(u32 texture, s32 frame);
extern void func_0021cd00(void* frame, f32* rectangle);
extern void func_0021d3b0(void* destination, void* frame);
extern void func_0021d8e0(void* destination, const void* layout);
extern void func_0021d950(void* destination, const u8* color);
extern void func_0021eb80(void* destination, const f32* layout);
extern void* btlOrderGetUnitByIdx(u16 index);
extern u32 datCalcIsDead(void* calc, u32 mode);
extern void* func_001ff430(u32 id);
extern u32 datCalcGetHp(void* calc);
extern u32 datCalcGetMaxHp(void* calc);
extern void func_00280580(BtlUnit* unit, RwV3d* position);
extern u32 func_002d20a0(const RwV3d* position, RwV3d* projected);
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
extern u8* iGpffffb6fc;
extern f32 fGpffff7f20;
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
    void* initialUnit;
    void* unit;
    u32 unitIds[0x14];
    u32 texture1;
    u32 texture5;
    s32 count;
    u8* battleWork;
    s32 i;
    s32 slotIndex;
    s32 renderIndex;
    s32 j;
    u8* slot;

    K_ASSERT(gBattlePanelWork != NULL, 0x47);
    work = (u8*)gBattlePanelWork;
    battleWork = iGpffffb6fc;
    texture1 = func_0021c3f0(1);
    texture5 = func_0021c3f0(5);
    count = 0;
    for (;;) {
        initialUnit = btlOrderGetUnitByIdx((u16)count);
        if (initialUnit == NULL)
            break;
        K_ASSERT(count < 0x14, 0x6f);
        if (datCalcIsDead(*(void**)((u8*)initialUnit + 0xa2c), 0) != 0)
            K_ASSERT(0, 0x70);
        unitIds[count] = *(u32*)((u8*)initialUnit + 0xa8);
        count++;
    }

    i = 0;
    unit = *(void**)(battleWork + 0x150);
    while (unit != NULL) {
        if (((~*(u32*)((u8*)unit + 0x9c) & 8) == 0) &&
            (datCalcIsDead(*(void**)((u8*)unit + 0xa2c), 0) == 0)) {
            *(u32*)(work + i * 0x420 + 0x14) = *(u32*)((u8*)unit + 0xa8);
            i++;
        }
        unit = *(void**)((u8*)unit + 0xa34);
    }
    unit = *(void**)(battleWork + 0x158);
    while (unit != NULL) {
        if (((~*(u32*)((u8*)unit + 0x9c) & 8) == 0) &&
            (datCalcIsDead(*(void**)((u8*)unit + 0xa2c), 0) == 0)) {
            *(u32*)(work + i * 0x420 + 0x14) = *(u32*)((u8*)unit + 0xa8);
            i++;
        }
        unit = *(void**)((u8*)unit + 0xa34);
    }
    *(s32*)(work + 0x2950) = i;
    slotIndex = 0;
    while (slotIndex < *(s32*)(work + 0x2950)) {
        slot = work + slotIndex * 0x420 + 0x10;
        *(u32*)slot = 0;
        *(u32*)(slot + 0x218) = 0;
        j = 0;
        while (j < count) {
            if (*(u32*)(slot + 4) == unitIds[j]) {
                if (j == 9) {
                    *(s32*)(slot + 0x210) = -1;
                    *(s32*)(slot + 0x214) = -1;
                    *(s32*)(slot + 0x218) = 2;
                } else {
                    s32 n = *(s32*)(slot + 0x218);
                    *(s32*)(slot + 0x210 + n * 4) = j;
                    *(s32*)(slot + 0x218) = n + 1;
                }
            }
            j++;
        }
        K_ASSERT(*(u32*)(slot + 0x218) != 0, 0xaa);
        unit = func_001ff430(*(u32*)(slot + 4));
        *(u32*)(slot + 8) = datCalcGetHp(*(void**)((u8*)unit + 0xa2c)) & 0xffff;
        *(u32*)(slot + 0xc) = datCalcGetMaxHp(*(void**)((u8*)unit + 0xa2c)) & 0xffff;
        slotIndex++;
    }

    renderIndex = 0;
    while (renderIndex < *(s32*)(work + 0x2950)) {
        slot = work + renderIndex * 0x420 + 0x10;
        j = 0;
        while (j < *(s32*)(slot + 0x218)) {
            s32 value = *(s32*)(slot + 0x210 + j * 4);
            if (value == -1) {
                func_00209940(slot + 0x10 + (j << 8), 1, 1 - j);
            } else if (value == 0) {
                void* frame = func_0021cca0(texture1, 0x46);
                func_0021d3b0(slot + 0x10 + (j << 8), frame);
            } else {
                func_00209940(slot + 0x10 + (j << 8), 1, value + 1);
            }
            j++;
        }
        func_0021d3b0(slot + 0x310, func_0021cca0(texture1, 1));
        func_0021d3b0(slot + 0x210, func_0021cca0(texture5, 4));
        renderIndex++;
    }

    func_00208f60();
    *(u32*)work |= 1;
}

// FUN_00208f60 NONMATCHING
void func_00208f60(void)
{
    u8* work;
    u32 texture1;
    u32 texture5;
    u8* slot;
    BtlUnit* unit;
    void* frame;
    RwV3d position;
    RwV3d projected;
    f32 layout[4];
    f32 rectangle[4];
    f32 origin[2];
    u8 color[4];
    f32 x;
    f32 y;
    f32 originX;
    f32 originY;
    f32 layoutY;
    f32 originX2;
    f32 scale;
    s32 i;
    s32 j;

    K_ASSERT(gBattlePanelWork != NULL, 0x47);
    work = (u8*)gBattlePanelWork;
    texture1 = func_0021c3f0(1);
    texture5 = func_0021c3f0(5);
    for (i = 0; i < *(s32*)(work + 0x2950); i++) {
        slot = work + i * 0x420 + 0x10;
        *(u32*)slot &= ~1u;
        unit = (BtlUnit*)func_001ff430(*(u32*)(slot + 4));
        func_00280580(unit, &position);
        if (func_002d20a0(&position, &projected) == 0) {
            *(u32*)slot |= 1;
            continue;
        }
        x = projected.x - 55.0f;
        y = projected.y - 55.0f;
        y = y + 20.0f;
        originX = 39.0f + x;
        originY = 47.0f + y;
        layoutY = originY - 3.0f;
        originY = y + 40.0f;
        originX2 = originX + 31.0f;
        for (j = 0; j < *(s32*)(slot + 0x218); j++) {
            s32 value = *(s32*)(slot + 0x210 + j * 4);
            u8* destination = slot + 0x10 + (j << 8);

            if (value == 0) {
                frame = func_0021cca0(texture1, 0x46);
                layout[0] = originX;
                layout[1] = layoutY;
                layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
                layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
                func_0021d8e0(destination, layout);
                color[0] = 0xff;
                color[1] = 0xff;
                color[2] = 0xff;
                color[3] = 0xff;
                func_0021d950(destination, color);
                continue;
            }
            if (j == 1) {
                origin[0] = originX2;
                origin[1] = originY;
                scale = fGpffff7f20;
            } else if (j == 0) {
                origin[0] = originX;
                origin[1] = originY;
                scale = 1.0f;
            }
            if (value == -1)
                func_00209a00(destination, 1, 1 - j, 1, scale, origin);
            else
                func_00209a00(destination, 1, value + 1, 1, scale, origin);
            color[0] = 0xff;
            color[1] = 0xff;
            color[2] = 0xff;
            color[3] = 0xff;
            func_0021d950(destination, color);
        }
        frame = func_0021cca0(texture1, 1);
        layout[0] = 55.0f + x;
        layout[1] = 55.0f + y;
        layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
        layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
        func_0021d8e0(slot + 0x320, layout);
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = (u8)255.0f;
        func_0021d950(slot + 0x320, color);
        frame = func_0021cca0(texture5, 4);
        func_0021cd00(frame, rectangle);
        scale = (f32)*(s32*)(slot + 8) / (f32)*(s32*)(slot + 0xc);
        layout[0] = rectangle[0];
        layout[1] = rectangle[1];
        layout[2] = (rectangle[2] - rectangle[0]) * scale;
        layout[3] = rectangle[3] - rectangle[1];
        func_0021eb80(slot + 0x220, layout);
        layout[0] = 55.0f + x;
        layout[1] = 55.0f + y;
        layout[2] = (f32)*(s32*)((u8*)frame + 0xc) * scale;
        layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
        func_0021d8e0(slot + 0x220, layout);
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = (u8)255.0f;
        func_0021d950(slot + 0x220, color);
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
