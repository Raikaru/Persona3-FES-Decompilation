#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwcore.h"

#pragma alias sinf_y2 sinf
#pragma alias cosf_y2 cosf
#pragma alias D_00960090_y2 D_00960090
#pragma alias D_0096009C_y2 D_0096009C
#pragma alias func_0021c3f0_y2 func_0021c3f0
#pragma alias func_0021cca0_y2 func_0021cca0
#pragma alias func_0021cce0_y2 func_0021cce0
#pragma alias func_0021d3b0_y2 func_0021d3b0
#pragma alias func_0021d890_y2 func_0021d890
#pragma alias func_0021d8e0_y2 func_0021d8e0
#pragma alias func_0021d950_y2 func_0021d950
#pragma alias func_002d20a0_y2 func_002d20a0


/* bi_main.c owns 16 battle-information slots, each 0xF50 bytes. */
static u8* sBiMain; // DAT_007CE31C / GP -0x49D4
/* 0x00242C40 switches to bpc_main.c and its DAT_007CE320 work pointer. */

#define BI_SLOT_COUNT 16
#define BI_SLOT_SIZE 0xF50
#define BI_SLOT(work, index) ((u8*)(work) + (index) * BI_SLOT_SIZE)
#define BI_U16(work, offset) (*(u16*)((u8*)(work) + (offset)))
#define BI_U32(work, offset) (*(u32*)((u8*)(work) + (offset)))

/* Slot header: +0 flags, +4 display mode, +0x310 age, +0x314 unit id. */
enum
{
    BI_SLOT_ACTIVE = 1,
    BI_SLOT_INITIALIZED = 2,
    BI_SLOT_ALT_STYLE = 4,
    BI_SLOT_HIDDEN = 8,
    BI_SLOT_READY = 0x10,
    BI_SLOT_TEXT_0 = 0x40,
    BI_SLOT_TEXT_1 = 0x80,
    BI_SLOT_NUMERIC_0 = 0x100,
    BI_SLOT_NUMERIC_1 = 0x200
};

extern void (*D_00960090)();
extern void (*D_0096009C)();
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];


u32 func_0021c3f0(s32 param_1);
void* func_0021cca0(void* texture, s32 index);
u32 func_0021cce0(void* frameData);
void func_0021d3b0(void* destination, void* frameData);
void func_0021d890(void* destination, const f32* vertices);
void func_0021d8e0(void* destination, const f32* rect);
void func_0021d950(void* destination, const u8* color);
void func_0021eae0(void* destination, const f32* rect);
void func_0021eac0(void* glyph, f32 value);
void* btlUnitFindFromId(u16 id);
void func_002806d0(void* unit, RwV3d* param_2);
u32 func_002d20a0();
int sprintf(char*, const char*, ...);
u32 strlen(const char*);
void func_00242840(void* glyphs, s32 capacity, s32 value);
f32 func_00242950(s32 value);
f32 cosf(f32);
extern f32 D_007CB0D4;
f32 sinf(f32);






static void biMainDrawQuad(void* vertices, u32 pass, u32 blend)
{
    D_0096009C(vertices, 4, 0, pass, blend);
}

static void biMainTickSlot(u8* slot)
{
    void* unit;

    if ((BI_U32(slot, 0) & BI_SLOT_ACTIVE) == 0) {
        return;
    }

    unit = btlUnitFindFromId(BI_U16(slot, 0x314));
    if (BI_U32(slot, 0x310) < 50) {
        BI_U32(slot, 0x310)++;
    }
    if (unit == NULL || BI_U32(slot, 0x310) == 50) {
        BI_U32(slot, 0) &= ~(BI_SLOT_ACTIVE | BI_SLOT_INITIALIZED);
    }
}

static void biMainPrepareDigit(void* glyph, s32 digit)
{
    void* renderContext;
    void* glyphResource;

    renderContext = (void*)func_0021c3f0(1);
    glyphResource = func_0021cca0(renderContext, digit + 0x2e);
    func_0021d3b0(glyph, glyphResource);
}



static void biMainDrawSlot(u8* slot)
{
    u32 flags;
    u32 mode;

    flags = BI_U32(slot, 0);
    if ((flags & (BI_SLOT_ACTIVE | BI_SLOT_HIDDEN | BI_SLOT_READY)) !=
        (BI_SLOT_ACTIVE | BI_SLOT_READY)) {
        return;
    }
    mode = BI_U32(slot, 4);
    if (mode == 0 || mode == 1 || mode == 2 || mode == 3) {
        if ((flags & BI_SLOT_ALT_STYLE) != 0) {
            RpSkyRenderStateSet(3, (void*)0x717fb);
            RpSkyRenderStateSet(2, (void*)0x44);
            biMainDrawQuad(slot + 0x110, 1, 2);
            biMainDrawQuad(slot + 0x110, 2, 3);
            RpSkyRenderStateSet(3, (void*)0x71801);
            RpSkyRenderStateSet(2, (void*)0x48);
            biMainDrawQuad(slot + 0x210, 1, 2);
            biMainDrawQuad(slot + 0x210, 2, 3);
        } else {
            biMainDrawQuad(slot + 0x10, 1, 2);
            biMainDrawQuad(slot + 0x10, 2, 3);
        }
    }
}

/* Removing this loses func_0023f480 (MATCH nd0 -> MISMATCH nd15) - measured W161. */
#pragma optimization_level 1
// FUN_0023F480
void func_0023f480(void* work)
{
    s32 i;
    s32 stride;

    K_ASSERT(sBiMain == NULL, 0x92);
    i = 0;
    stride = BI_SLOT_SIZE;
    for (; i < BI_SLOT_COUNT; i++) {
        BI_U32((u8*)work + i * stride, 0) = 0;
    }
    sBiMain = work;
}
#pragma optimization_level 2

// FUN_0023F500
void func_0023f500(void)
{
    K_ASSERT(sBiMain != NULL, 0x8a);
    sBiMain = NULL;
}

/* Mode 2's three-stage sprite sequence is reconstructed; stack geometry remains nonmatching. */
// FUN_0023F540 NONMATCHING
void func_0023f540(void)
{
    u8* work;
    void* renderContext;
    void* unit;
    void* frame;
    u8* slot;
    f32 projected[2];
    f32 transform[4];
    RwV2d layout[4];
    f32 rect[4];
    f32 x;
    f32 y;
    f32 alpha;
    f32 colorAlpha;
    f32 t;
    f32 vertical;
    f32 digitOffset;
    s32 i;
    s32 k;
    s32 j;
    s32 age;
    s32 first;
    s32 last;
    u8 color[4];
    work = sBiMain;
    K_ASSERT(work != NULL, 0x8a);
    work = sBiMain;
    renderContext = (void*)func_0021c3f0(1);



    for (i = 0; i < BI_SLOT_COUNT; i++) {
        slot = BI_SLOT(work, i);
        if ((~BI_U32(slot, 0) & BI_SLOT_ACTIVE) != 0) {
            continue;
        }
        unit = btlUnitFindFromId(BI_U16(slot, 0x314));
        if ((s32)BI_U32(slot, 0x310) < 50) {
            BI_U32(slot, 0x310)++;
        }
        if ((s32)BI_U32(slot, 0x310) == 50 || unit == NULL) {
            BI_U32(slot, 0) &= ~BI_SLOT_INITIALIZED;
            BI_U32(slot, 0) &= ~BI_SLOT_ACTIVE;
        }
    }



    for (k = 0; k < BI_SLOT_COUNT; k++) {
        slot = BI_SLOT(work, k);
        if ((~BI_U32(slot, 0) & BI_SLOT_ACTIVE) != 0) {
            continue;
        }
        unit = btlUnitFindFromId(BI_U16(slot, 0x314));
        func_002806d0(unit, (RwV3d*)transform);
        if (func_002d20a0(transform, projected) != 0 &&
            *(u8*)((u8*)unit + 0x37) != 0) {
            BI_U32(slot, 0) &= ~BI_SLOT_HIDDEN;
        } else {
            BI_U32(slot, 0) |= BI_SLOT_HIDDEN;
        }
        rect[0] = projected[0] - 1.0f;
        rect[1] = projected[1] - 100.0f;
        rect[2] = 2.0f;
        rect[3] = 200.0f;
        func_0021d8e0(slot + 0xd40, rect);
        rect[0] = projected[0] - 100.0f;
        rect[1] = projected[1] - 1.0f;
        rect[2] = 200.0f;
        rect[3] = 2.0f;
        func_0021d8e0(slot + 0xe40, rect);

        if ((BI_U32(slot, 0) & BI_SLOT_READY) == 0) {
            continue;
        }

        switch (BI_U32(slot, 4)) {
        case 0:
            x = 9.0f + (projected[0] - 110.0f);
            y = ((projected[1] - 60.0f) - 7.0f) - 14.0f;
            frame = func_0021cca0(renderContext, 0xb);
            layout[0].x = 53.0f + x;
            layout[0].y = 51.0f + y;
            layout[1].x = (f32)*(s32*)((u8*)frame + 0xc);
            layout[1].y = (f32)*(s32*)((u8*)frame + 0x10);
            func_0021d8e0(slot + 0x10, (f32*)layout);
            age = (s32)BI_U32(slot, 0x310);
            if (age < 0) {
                alpha = 0.0f;
            } else if (age < 3) {
                alpha = (f32)age / 3.0f;
            } else if (age < 30) {
                alpha = 1.0f;
            } else if (age < 34) {
                alpha = 1.0f - (f32)(age - 34) / 4.0f;
            } else {
                alpha = 0.0f;
            }
            color[0] = 0xff;
            color[1] = 0xff;
            color[2] = 0xff;
            color[3] = (u8)(u32)(255.0f * alpha);
            func_0021d950(slot + 0x10, color);
            if ((BI_U32(slot, 0) & BI_SLOT_ALT_STYLE) != 0) {
                frame = func_0021cca0(renderContext, 0xa);
                age = (s32)BI_U32(slot, 0x310);
                if (age < 0) {
                    alpha = 1.0f;
                } else if (age < 12) {
                    t = (f32)age / 12.0f;
                    alpha = 2.0f * t - t * t;
                } else {
                    alpha = 1.0f;
                }
                layout[0].x = 0.0f;
                layout[0].y = 0.0f;
                layout[1].x = (f32)*(s32*)((u8*)frame + 0xc);
                layout[1].y = 0.0f;
                layout[2].x = layout[1].x;
                layout[2].y = (f32)*(s32*)((u8*)frame + 0x10);
                layout[3].x = 0.0f;
                layout[3].y = (f32)*(s32*)((u8*)frame + 0x10);
                for (j = 0; j < 4; j++) {
                    layout[j].x -= 75.0f;
                    layout[j].y -= 34.0f;
                }
                for (j = 0; j < 4; j++) {
                    layout[j].x *= alpha;
                    layout[j].y *= alpha;
                }
                for (j = 0; j < 4; j++) {
                    layout[j].x += 75.0f;
                    layout[j].y += 34.0f;
                }
                for (j = 0; j < 4; j++) {
                    layout[j].x += 75.0f + x;
                    layout[j].y += 29.0f + y;
                }
                func_0021d890(slot + 0x100, (f32*)layout);
                age = (s32)BI_U32(slot, 0x310);
                if (age < 0) {
                    colorAlpha = 0.0f;
                } else if (age < 8) {
                    colorAlpha = (f32)age / 8.0f;
                } else if (age < 30) {
                    colorAlpha = 1.0f;
                } else if (age < 34) {
                    colorAlpha = 1.0f - (f32)(age - 30) / 4.0f;
                } else {
                    colorAlpha = 0.0f;
                }
                color[0] = 0xff;
                color[1] = 0xff;
                color[2] = 0xff;
                color[3] = (u8)(u32)(255.0f * colorAlpha);
                func_0021d950(slot + 0x100, color);
            }
            if ((BI_U32(slot, 0) & BI_SLOT_ALT_STYLE) != 0) {
                frame = func_0021cca0(renderContext, 0xa);
                age = (s32)BI_U32(slot, 0x310);
                if (age < 0) {
                    alpha = 1.0f;
                } else if (age < 8) {
                    alpha = 2.0f;
                } else if (age < 8) {
                    alpha = 2.0f;
                /* Retail 0x23fd38-0x23fd58 preserves a second age<8 branch. */
                } else if (age < 34) {
                    alpha = 1.0f + (1.0f - (f32)(age - 8) / 26.0f);
                } else {
                    alpha = 1.0f;
                }
                layout[0].x = 0.0f;
                layout[0].y = 0.0f;
                layout[1].x = (f32)*(s32*)((u8*)frame + 0xc);
                layout[1].y = 0.0f;
                layout[2].x = layout[1].x;
                layout[2].y = (f32)*(s32*)((u8*)frame + 0x10);
                layout[3].x = 0.0f;
                layout[3].y = (f32)*(s32*)((u8*)frame + 0x10);
                for (j = 0; j < 4; j++) {
                    layout[j].x -= 75.0f;
                    layout[j].y -= 34.0f;
                }
                for (j = 0; j < 4; j++) {
                    layout[j].x *= alpha;
                    layout[j].y *= alpha;
                }
                for (j = 0; j < 4; j++) {
                    layout[j].x += 75.0f;
                    layout[j].y += 34.0f;
                }
                for (j = 0; j < 4; j++) {
                    layout[j].x += 75.0f + x;
                    layout[j].y += 29.0f + y;
                }
                func_0021d890(slot + 0x200, (f32*)layout);
                age = (s32)BI_U32(slot, 0x310);
                if (age < 0) {
                    colorAlpha = 0.0f;
                } else if (age < 8) {
                    colorAlpha = 1.0f;
                } else if (age < 8) {
                    colorAlpha = 1.0f;
                /* Retail 0x23fdc0-0x23fdd8 preserves a second age<8 branch. */
                } else if (age < 34) {
                    colorAlpha = 1.0f - (f32)(age - 8) / 26.0f;
                } else {
                    colorAlpha = 0.0f;
                }
                color[0] = 0x64;
                color[1] = 0x64;
                color[2] = 0xff;
                color[3] = (u8)(u32)(255.0f * colorAlpha);
                func_0021d950(slot + 0x200, color);
            }
            break;
        case 1:
            x = 9.0f + (projected[0] - 110.0f);
            y = ((projected[1] - 60.0f) - 7.0f) - 14.0f;
            frame = func_0021cca0(renderContext, 0xb);
            layout[0].x = 53.0f + x;
            layout[0].y = 51.0f + y;
            layout[1].x = (f32)*(s32*)((u8*)frame + 0xc);
            layout[1].y = (f32)*(s32*)((u8*)frame + 0x10);
            func_0021d8e0(slot + 0x10, (f32*)layout);
            age = (s32)BI_U32(slot, 0x310);
            if (age < 0) {
                alpha = 0.0f;
            } else if (age < 3) {
                alpha = (f32)age / 3.0f;
            } else if (age < 30) {
                alpha = 1.0f;
            } else if (age < 34) {
                alpha = 1.0f - (f32)(age - 34) / 4.0f;
            } else {
                alpha = 0.0f;
            }
            color[0] = 0xff;
            color[1] = 0xff;
            color[2] = 0xff;
            color[3] = (u8)(u32)(255.0f * alpha);
            func_0021d950(slot + 0x10, color);
            if ((BI_U32(slot, 0) & BI_SLOT_ALT_STYLE) != 0) {
                frame = func_0021cca0(renderContext, 0xa);
                age = (s32)BI_U32(slot, 0x310);
                if (age < 0) {
                    alpha = 1.0f;
                } else if (age < 12) {
                    t = (f32)age / 12.0f;
                    alpha = 2.0f * t - t * t;
                } else {
                    alpha = 1.0f;
                }
                layout[0].x = 0.0f;
                layout[0].y = 0.0f;
                layout[1].x = (f32)*(s32*)((u8*)frame + 0xc);
                layout[1].y = 0.0f;
                layout[2].x = layout[1].x;
                layout[2].y = (f32)*(s32*)((u8*)frame + 0x10);
                layout[3].x = 0.0f;
                layout[3].y = (f32)*(s32*)((u8*)frame + 0x10);
                for (j = 0; j < 4; j++) {
                    layout[j].x -= 75.0f;
                    layout[j].y -= 34.0f;
                }
                for (j = 0; j < 4; j++) {
                    layout[j].x *= alpha;
                    layout[j].y *= alpha;
                }
                for (j = 0; j < 4; j++) {
                    layout[j].x += 75.0f;
                    layout[j].y += 34.0f;
                }
                for (j = 0; j < 4; j++) {
                    layout[j].x += 75.0f + x;
                    layout[j].y += 29.0f + y;
                }
                func_0021d890(slot + 0x100, (f32*)layout);
                age = (s32)BI_U32(slot, 0x310);
                if (age < 0) {
                    colorAlpha = 0.0f;
                } else if (age < 8) {
                    colorAlpha = (f32)age / 8.0f;
                } else if (age < 30) {
                    colorAlpha = 1.0f;
                } else if (age < 34) {
                    colorAlpha = 1.0f - (f32)(age - 30) / 4.0f;
                } else {
                    colorAlpha = 0.0f;
                }
                color[0] = 0xff;
                color[1] = 0xff;
                color[2] = 0xff;
                color[3] = (u8)(u32)(255.0f * colorAlpha);
                func_0021d950(slot + 0x100, color);
            }
            if ((BI_U32(slot, 0) & BI_SLOT_ALT_STYLE) != 0) {
                frame = func_0021cca0(renderContext, 0xa);
                age = (s32)BI_U32(slot, 0x310);
                if (age < 0) {
                    alpha = 1.0f;
                } else if (age < 8) {
                    alpha = 2.0f;
                } else if (age < 8) {
                    alpha = 2.0f;
                /* Retail 0x2405d4-0x2405f4 preserves a second age<8 branch. */
                } else if (age < 34) {
                    alpha = 1.0f + (1.0f - (f32)(age - 8) / 26.0f);
                } else {
                    alpha = 1.0f;
                }
                layout[0].x = 0.0f;
                layout[0].y = 0.0f;
                layout[1].x = (f32)*(s32*)((u8*)frame + 0xc);
                layout[1].y = 0.0f;
                layout[2].x = layout[1].x;
                layout[2].y = (f32)*(s32*)((u8*)frame + 0x10);
                layout[3].x = 0.0f;
                layout[3].y = (f32)*(s32*)((u8*)frame + 0x10);
                for (j = 0; j < 4; j++) {
                    layout[j].x -= 75.0f;
                    layout[j].y -= 34.0f;
                }
                for (j = 0; j < 4; j++) {
                    layout[j].x *= alpha;
                    layout[j].y *= alpha;
                }
                for (j = 0; j < 4; j++) {
                    layout[j].x += 75.0f;
                    layout[j].y += 34.0f;
                }
                for (j = 0; j < 4; j++) {
                    layout[j].x += 75.0f + x;
                    layout[j].y += 29.0f + y;
                }
                func_0021d890(slot + 0x200, (f32*)layout);
                age = (s32)BI_U32(slot, 0x310);
                if (age < 0) {
                    colorAlpha = 0.0f;
                } else if (age < 8) {
                    colorAlpha = 1.0f;
                } else if (age < 8) {
                    colorAlpha = 1.0f;
                /* Retail 0x24065c-0x240674 preserves a second age<8 branch. */
                } else if (age < 34) {
                    colorAlpha = 1.0f - (f32)(age - 8) / 26.0f;
                } else {
                    colorAlpha = 0.0f;
                }
                color[0] = 0x46;
                color[1] = 0x32;
                color[2] = 0x0a;
                color[3] = (u8)(u32)(255.0f * colorAlpha);
                func_0021d950(slot + 0x200, color);
            }
            break;
        case 3:
            frame = func_0021cca0(renderContext, 0x22);
            layout[0].x = projected[0] -
                        (f32)((s32)*(s32*)((u8*)frame + 0xc) / 2);
            layout[0].y = projected[1] -
                        (f32)((s32)*(s32*)((u8*)frame + 0x10) / 2);
            layout[1].x = (f32)*(s32*)((u8*)frame + 0xc);
            layout[1].y = (f32)*(s32*)((u8*)frame + 0x10);
            func_0021d8e0(slot + 0x10, (f32*)layout);
            break;
        case 2:
            x = projected[0] - 135.0f;
            y = projected[1] - 87.0f;
            frame = func_0021cca0(renderContext, 0x1e);
            layout[0].x = x + 86.0f;
            layout[0].y = y + 78.0f;
            layout[1].x = (f32)*(s32*)((u8*)frame + 0xc);
            layout[1].y = (f32)*(s32*)((u8*)frame + 0x10);
            func_0021d8e0(slot + 0x10, (f32*)layout);
            /* Retail 0x240a44-0x240a80 reloads slot age after the first mode 2 draw. */
            age = (s32)BI_U32(slot, 0x310);
            if (age < 0) {
                alpha = 0.0f;
            } else if (age < 3) {
                alpha = (f32)age / 3.0f;
            } else if (age < 30) {
                alpha = 1.0f;
            } else if (age < 34) {
                alpha = 1.0f - (f32)(age - 34) / 4.0f;
            } else {
                alpha = 0.0f;
            }
            color[0] = 0xff;
            color[1] = 0xff;
            color[2] = 0xff;
            color[3] = (u8)(u32)(255.0f * alpha);
            func_0021d950(slot + 0x10, color);

            frame = func_0021cca0(renderContext, 0x1d);
            age = (s32)BI_U32(slot, 0x310);
            if (age < 0) {
                alpha = 0.0f;
            } else if (age < 8) {
                alpha = (f32)age / 8.0f;
            } else if (age < 30) {
                alpha = 1.0f;
            } else {
                alpha = 1.0f;
            }
            layout[0].x = 0.0f;
            layout[0].y = 0.0f;
            layout[1].x = (f32)*(s32*)((u8*)frame + 0xc);
            layout[1].y = 0.0f;
            layout[2].x = layout[1].x;
            layout[2].y = (f32)*(s32*)((u8*)frame + 0x10);
            layout[3].x = 0.0f;
            layout[3].y = (f32)*(s32*)((u8*)frame + 0x10);
            for (j = 0; j < 4; j++) {
                layout[j].x -=
                    (f32)((s32)*(s32*)((u8*)frame + 0xc) / 2);
                layout[j].y -=
                    (f32)((s32)*(s32*)((u8*)frame + 0x10) / 2);
            }
            for (j = 0; j < 4; j++) {
                layout[j].x *= alpha;
                layout[j].y *= alpha;
            }
            for (j = 0; j < 4; j++) {
                layout[j].x +=
                    (f32)((s32)*(s32*)((u8*)frame + 0xc) / 2);
                layout[j].y +=
                    (f32)((s32)*(s32*)((u8*)frame + 0x10) / 2);
            }
            for (j = 0; j < 4; j++) {
                layout[j].x += 83.0f + x;
                layout[j].y += 63.0f + y;
            }
            func_0021d890(slot + 0x110, (f32*)layout);
            age = (s32)BI_U32(slot, 0x310);
            if (age < 0) {
                colorAlpha = 0.0f;
            } else if (age < 8) {
                colorAlpha = 1.0f;
            } else if (age < 30) {
                colorAlpha = 1.0f;
            } else if (age < 34) {
                colorAlpha = 1.0f - (f32)(age - 34) / 4.0f;
            } else {
                colorAlpha = 0.0f;
            }
            color[0] = 0xff;
            color[1] = 0xff;
            color[2] = 0xff;
            color[3] = (u8)(u32)(255.0f * colorAlpha);
            func_0021d950(slot + 0x110, color);

            frame = func_0021cca0(renderContext, 0x1c);
            age = (s32)BI_U32(slot, 0x310);
            if (age < 8) {
                digitOffset = 0.0f;
                vertical = 0.0f;
            } else {
                age -= 8;
                if (age < 6) {
                    t = 50.0f * (1.0f - (f32)age / 6.0f);
                    digitOffset = -t * cosf(D_007CB0D4);
                    vertical = t * sinf(D_007CB0D4);
                /* Retail 0x240df0-0x240e70 keeps the post-subtract timing branches separate. */
                } else if (age < 0x16) {
                    digitOffset = 0.0f;
                    vertical = 0.0f;
                } else if (age < 0x22) {
                    digitOffset = 0.0f;
                    vertical = 0.0f;
                } else {
                    digitOffset = 0.0f;
                    vertical = 0.0f;
                }
            }
            layout[0].x = 75.0f + x + digitOffset;
            layout[0].y = 61.0f + y + vertical;
            layout[1].x = (f32)*(s32*)((u8*)frame + 0xc);
            layout[1].y = (f32)*(s32*)((u8*)frame + 0x10);
            func_0021d8e0(slot + 0x210, (f32*)layout);
            age = (s32)BI_U32(slot, 0x310);
            if (age < 8) {
                alpha = 0.0f;
            } else if (age - 8 < 6) {
                alpha = 1.0f;
            } else if (age - 8 < 22) {
                alpha = 1.0f;
            } else if (age - 8 < 34) {
                alpha = 1.0f - (f32)(age - 8 - 34) / 12.0f;
            } else {
                alpha = 0.0f;
            }
            color[0] = 0xff;
            color[1] = 0xff;
            color[2] = 0xff;
            color[3] = (u8)(u32)(255.0f * alpha);
            func_0021d950(slot + 0x210, color);
            break;
        }

        if ((BI_U32(slot, 0) & BI_SLOT_NUMERIC_0) != 0) {
            frame = func_0021cca0(renderContext, 0x2e);
            x = projected[0] - (f32)func_00242950(BI_U32(slot, 0x820)) / 2.0f;
            y = projected[1] -
                (f32)((s32)*(s32*)((u8*)frame + 0x10) / 2);
            if ((BI_U32(slot, 0) & 0x20) != 0 &&
                BI_U32(slot, 0xf44) < BI_U32(slot, 0xf40) - 1) {
                first = 0xe;
                last = 0x12;
            } else {
                first = 0x1e;
                last = 0x22;
            }
            for (j = 0; j < (s32)BI_U32(slot, 0x824); j++) {
                age = (s32)BI_U32(slot, 0x310);
                if (age < j) {
                    vertical = 0.0f;
                    alpha = 0.0f;
                } else if (age - j < 6) {
                    alpha = (f32)(age - j) / 6.0f;
                    vertical = 30.0f * (1.0f - alpha);
                } else if (age < first) {
                    vertical = 0.0f;
                    alpha = 1.0f;
                } else if (age < last) {
                    vertical = 0.0f;
                    alpha = 1.0f - (f32)(age - first) /
                                      (f32)(last - first);
                } else {
                    vertical = 0.0f;
                    alpha = 0.0f;
                }
                digitOffset = 0.0f;
                if ((BI_U32(slot, 0) & 0x20) != 0) {
                    if (BI_U32(slot, 0xf44) == BI_U32(slot, 0xf40) - 1) {
                        digitOffset = 0.0f;
                    } else if (age < 7) {
                        digitOffset = 0.0f;
                    } else if (age < 0xd) {
                        digitOffset = -28.0f * (f32)(age - 7) / 6.0f;
                    } else if (BI_U32(slot, 0xf40) - BI_U32(slot, 0xf44) >=
                               3) {
                        if (age < 0xe) {
                            digitOffset = -28.0f;
                        } else if (age < 0x14) {
                            digitOffset = -28.0f *
                                           (f32)(age - 0xe) / 6.0f -
                                           28.0f;
                        } else {
                            digitOffset = -56.0f;
                        }
                    } else {
                        digitOffset = -28.0f;
                    }
                } else if ((BI_U32(slot, 0) & BI_SLOT_NUMERIC_1) != 0) {
                    digitOffset = -28.0f;
                }
                frame = func_0021cca0(renderContext, 0x2e);
                layout[0].x = x + 28.0f * (f32)j;
                layout[0].y = y + vertical + digitOffset;
                layout[1].x = (f32)*(s32*)((u8*)frame + 0xc);
                layout[1].y = (f32)*(s32*)((u8*)frame + 0x10);
                func_0021d8e0(slot + 0x320 + j * 0x100, (f32*)layout);
                if ((BI_U32(slot, 0) & BI_SLOT_TEXT_0) != 0) {
                    color[0] = 0xff;
                    color[1] = 0xff;
                    color[2] = 0xff;
                } else {
                    color[0] = 0xbe;
                    color[1] = 0xff;
                    color[2] = 0xd2;
                }
                color[3] = (u8)(u32)(255.0f * alpha);
                func_0021d950(slot + 0x320 + j * 0x100, color);
            }
            for (; j < 5; j++) {
                layout[0].x = x;
                layout[0].y = y;
                layout[1].x = 0.0f;
                layout[1].y = 0.0f;
                func_0021d8e0(slot + 0x320 + j * 0x100, (f32*)layout);
            }
        }

        if ((BI_U32(slot, 0) & BI_SLOT_NUMERIC_1) != 0) {
            frame = func_0021cca0(renderContext, 0x2e);
            x = projected[0] - (f32)func_00242950(BI_U32(slot, 0xd30)) / 2.0f;
            y = projected[1] -
                (f32)((s32)*(s32*)((u8*)frame + 0x10) / 2);
            for (j = 0; j < (s32)BI_U32(slot, 0xd34); j++) {
                age = (s32)BI_U32(slot, 0x310);
                if (age < j) {
                    vertical = 0.0f;
                    alpha = 0.0f;
                } else if (age - j < 6) {
                    alpha = (f32)(age - j) / 6.0f;
                    vertical = 80.0f * (1.0f - alpha);
                } else if (age < 30) {
                    vertical = 0.0f;
                    alpha = 1.0f;
                } else if (age < 34) {
                    vertical = 0.0f;
                    alpha = 1.0f - (f32)(age - 30) / 4.0f;
                } else {
                    vertical = 0.0f;
                    alpha = 0.0f;
                }
                frame = func_0021cca0(renderContext, 0x2e);
                layout[0].x = x + 28.0f * (f32)j;
                layout[0].y = y + vertical;
                layout[1].x = (f32)*(s32*)((u8*)frame + 0xc);
                layout[1].y = (f32)*(s32*)((u8*)frame + 0x10);
                func_0021d8e0(slot + 0x830 + j * 0x100, (f32*)layout);
                if ((BI_U32(slot, 0) & BI_SLOT_TEXT_1) != 0) {
                    color[0] = 0xf0;
                    color[1] = 0xaa;
                    color[2] = 0xff;
                } else {
                    color[0] = 0xbe;
                    color[1] = 0xd2;
                    color[2] = 0xff;
                }
                color[3] = (u8)(u32)(255.0f * alpha);
                func_0021d950(slot + 0x830 + j * 0x100, color);
            }
            for (; j < 5; j++) {
                layout[0].x = x;
                layout[0].y = y;
                layout[1].x = 0.0f;
                layout[1].y = 0.0f;
                func_0021d8e0(slot + 0x830 + j * 0x100, (f32*)layout);
            }
        }
    }
}

#define BI_MAIN_DRAW_ALT(base) \
    do { \
        RpSkyRenderStateSet(3, (void*)0x717fb); \
        RpSkyRenderStateSet(2, (void*)0x44); \
        D_0096009C((u8*)(base) + 0x100, 4, 0, 1, 2); \
        D_0096009C((u8*)(base) + 0x100, 4, 0, 2, 3); \
        RpSkyRenderStateSet(3, (void*)0x71801); \
        RpSkyRenderStateSet(2, (void*)0x48); \
        D_0096009C((u8*)(base) + 0x200, 4, 0, 1, 2); \
        D_0096009C((u8*)(base) + 0x200, 4, 0, 2, 3); \
    } while (0)
#define BI_MAIN_DRAW_BASIC(base) \
    do { \
        RpSkyRenderStateSet(3, (void*)0x717fb); \
        RpSkyRenderStateSet(2, (void*)0x44); \
        D_0096009C((u8*)(base), 4, 0, 1, 2); \
        D_0096009C((u8*)(base), 4, 0, 2, 3); \
    } while (0)
#define BI_MAIN_DRAW_DIGITS(base) \
    do { \
        s32 biDigitIndex; \
        frame = func_0021cca0(renderContext, 0x2e); \
        (*stateSet)(1, (u32)func_0021cce0(frame)); \
        RpSkyRenderStateSet(3, (void*)0x717fb); \
        RpSkyRenderStateSet(2, (void*)0x44); \
        for (biDigitIndex = 0; biDigitIndex < 5; biDigitIndex++) { \
            D_0096009C((u8*)(base) + biDigitIndex * 0x100, 4, 0, 1, 2); \
            D_0096009C((u8*)(base) + biDigitIndex * 0x100, 4, 0, 2, 3); \
        } \
    } while (0)
/* W419 OpSocial2: direct absolute D_0096009C callback nd1389/object2424 exceeds 2384; cached/panel/macro variants worsened nd or remained over-window. */
// FUN_00241910 NONMATCHING
void func_00241910(void)
{
    u8* work;
    void* renderContext;
    void (**stateSet)(u32, u32);
    void* frame;
    u32 flags;
    u32 mode;
    s32 i;
    u8* slot;
    u8* panel;

    K_ASSERT(sBiMain != NULL, 0x8a);
    work = sBiMain;
    renderContext = (void*)func_0021c3f0(1);
    stateSet = (void (**)(u32, u32))D_00960090_abs;
    (*stateSet)(9, 2);
    (*stateSet)(0x14, 2);
    (*stateSet)(8, 0);
    (*stateSet)(6, 0);
    for (i = 0; i < BI_SLOT_COUNT; i++) {
        slot = BI_SLOT(work, i);
        flags = BI_U32(slot, 0);
        if ((~flags & BI_SLOT_ACTIVE) != 0 ||
            (flags & BI_SLOT_HIDDEN) != 0 ||
            (flags & BI_SLOT_READY) == 0) {
            continue;
        }
        mode = BI_U32(slot, 4);
        switch (mode) {
        case 0:
            panel = slot + 0x10;
            frame = func_0021cca0(renderContext, 0xa);
            (*stateSet)(1, (u32)func_0021cce0(frame));
            if ((flags & BI_SLOT_ALT_STYLE) != 0) {
                BI_MAIN_DRAW_ALT(panel);
            } else {
                frame = func_0021cca0(renderContext, 0xb);
                (*stateSet)(1, (u32)func_0021cce0(frame));
                BI_MAIN_DRAW_BASIC(panel);
            }
            break;
        case 1:
            panel = slot + 0x10;
            if ((flags & BI_SLOT_ALT_STYLE) != 0) {
                frame = func_0021cca0(renderContext, 0x13);
                (*stateSet)(1, (u32)func_0021cce0(frame));
                BI_MAIN_DRAW_ALT(panel);
            } else {
                frame = func_0021cca0(renderContext, 0x12);
                (*stateSet)(1, (u32)func_0021cce0(frame));
                BI_MAIN_DRAW_BASIC(panel);
            }
            break;
        case 3:
            panel = slot + 0x10;
            frame = func_0021cca0(renderContext, 0x22);
            (*stateSet)(1, (u32)func_0021cce0(frame));
            BI_MAIN_DRAW_BASIC(panel);
            break;
        case 2:
            panel = slot + 0x10;
            frame = func_0021cca0(renderContext, 0x1d);
            (*stateSet)(1, (u32)func_0021cce0(frame));
            BI_MAIN_DRAW_BASIC(panel + 0x100);
            frame = func_0021cca0(renderContext, 0x1c);
            (*stateSet)(1, (u32)func_0021cce0(frame));
            BI_MAIN_DRAW_BASIC(panel + 0x200);
            frame = func_0021cca0(renderContext, 0x1e);
            (*stateSet)(1, (u32)func_0021cce0(frame));
            BI_MAIN_DRAW_BASIC(panel);
            break;
        }
    }
    func_002bf9b0();
    for (i = 0; i < BI_SLOT_COUNT; i++) {
        slot = BI_SLOT(work, i);
        flags = BI_U32(slot, 0);
        if ((~flags & BI_SLOT_ACTIVE) != 0 ||
            (flags & BI_SLOT_HIDDEN) != 0) {
            continue;
        }
        if ((flags & BI_SLOT_NUMERIC_0) != 0) {
            BI_MAIN_DRAW_DIGITS(slot + 0x320);
        }
        if ((flags & BI_SLOT_NUMERIC_1) != 0) {
            BI_MAIN_DRAW_DIGITS(slot + 0x830);
        }
    }
}
#undef BI_MAIN_DRAW_DIGITS
#undef BI_MAIN_DRAW_BASIC
#undef BI_MAIN_DRAW_ALT

/* Removing this loses func_00242260 (MATCH nd0 -> MISMATCH nd18) - measured W161. */
#pragma optimization_level 1
// FUN_00242260
void* func_00242260(void)
{
    s32 i;
    u8* slot;
    u8* work;
    s32 stride;

    K_ASSERT(sBiMain != NULL, 0x8a);
    work = sBiMain;
    i = 0;
    stride = BI_SLOT_SIZE;
    for (; i < BI_SLOT_COUNT; i++) {
        slot = work + i * stride;
        if (~BI_U32(slot, 0) & BI_SLOT_ACTIVE) {
            break;
        }
    }
    K_ASSERT(i < BI_SLOT_COUNT, 0x583);
    BI_U32(slot, 0) = 0;
    BI_U32(slot, 0) |= BI_SLOT_ACTIVE;
    return slot;
}
#pragma optimization_level 2

// FUN_00242320
void func_00242320(void* slot, s32 mode)
{
    void* renderContext;

    renderContext = (void*)func_0021c3f0(1);
    kwlnGetMainCamera();
    switch (mode) {
    case 0: {
        u8* glyphs;
        s32 i;
        void* resource;

        glyphs = (u8*)slot + 0x10;
        func_0021d3b0(glyphs, func_0021cca0(renderContext, 0xb));
        resource = func_0021cca0(renderContext, 0xa);
        for (i = 0; i < 2; i++) {
            func_0021d3b0(glyphs + i * 0x100 + 0x100, resource);
        }
        break;
    }
    case 1: {
        u8* glyphs;
        void* resource;
        s32 i;

        glyphs = (u8*)slot + 0x10;
        func_0021d3b0(glyphs, func_0021cca0(renderContext, 0x13));
        resource = func_0021cca0(renderContext, 0x12);
        for (i = 0; i < 2; i++) {
            func_0021d3b0(glyphs + i * 0x100 + 0x100, resource);
        }
        break;
    }
    case 3:
        func_0021d3b0((u8*)slot + 0x10, func_0021cca0(renderContext, 0x22));
        break;
    case 2: {
        u8* glyphs;

        glyphs = (u8*)slot + 0x10;
        func_0021d3b0(glyphs, func_0021cca0(renderContext, 0x1e));
        func_0021d3b0(glyphs + 0x100, func_0021cca0(renderContext, 0x1d));
        func_0021d3b0(glyphs + 0x200, func_0021cca0(renderContext, 0x1c));
        break;
    }
    }
    BI_U32(slot, 4) = mode;
    BI_U32(slot, 0) |= BI_SLOT_READY;
}

/* Removing this loses func_00242540 (MATCH nd0 -> MISMATCH nd131), newly over-window 184/192 -> 200/192 - measured W161. */
#pragma optimization_level 1
// FUN_00242540
void func_00242540(void* slot)
{
    RwRGBA color;
    f32 origin[4];
    s32 opaque;

    opaque = 0xff;
    color.r = opaque;
    color.g = 0;
    color.b = 0;
    color.a = opaque;
    origin[0] = 0.0f;
    origin[1] = 0.0f;
    origin[2] = 0.0f;
    origin[3] = 0.0f;
    func_0021eae0((u8*)slot + 0xd40, (const f32*)origin);
    func_0021d950((u8*)slot + 0xd40, (const u8*)&color);
    func_0021eac0((u8*)slot + 0xd40, 0.0f);
    func_0021eae0((u8*)slot + 0xe40, (const f32*)origin);
    func_0021d950((u8*)slot + 0xe40, (const u8*)&color);
    func_0021eac0((u8*)slot + 0xe40, 0.0f);
    BI_U32(slot, 0x310) = 0;
    BI_U32(slot, 0) |= BI_SLOT_INITIALIZED;
}
#pragma optimization_level 2

/* Removing this loses func_00242600 (MATCH nd0 -> MISMATCH nd208), newly over-window 284/288 -> 300/288; loses func_00242720 (MATCH nd0 -> MISMATCH nd208), newly over-window 284/288 -> 300/288 - measured W161. */
#pragma optimization_level 1
// FUN_00242600
void func_00242600(void* slot, s32 value)
{
    char digits[256];
    s32 length;
    s32 magnitude;
    void* glyphs;
    s32 capacity;
    s32 displayValue;

    if (value >= 0) {
        magnitude = value;
    } else {
        BI_U32(slot, 0) |= BI_SLOT_TEXT_0;
        magnitude = -value;
    }
    K_ASSERT(magnitude >= 0, 0x603);
    if (magnitude < 100000) {
        BI_U32(slot, 0x820) = magnitude;
    } else {
        BI_U32(slot, 0x820) = 99999;
    }
    sprintf(digits, "%d", BI_U32(slot, 0x820));
    length = strlen(digits);
    K_ASSERT(length > 0, 0x610);
    K_ASSERT(length <= 5, 0x611);
    BI_U32(slot, 0x824) = length;
    BI_U32(slot, 0) |= BI_SLOT_NUMERIC_0;
    glyphs = (u8*)slot + 0x320;
    capacity = 5;
    displayValue = BI_U32(slot, 0x820);
    func_00242840(glyphs, capacity, displayValue);
}

// FUN_00242720
void func_00242720(void* slot, s32 value)
{
    char digits[256];
    s32 length;
    s32 magnitude;
    void* glyphs;
    s32 capacity;
    s32 displayValue;

    if (value >= 0) {
        magnitude = value;
    } else {
        magnitude = -value;
        BI_U32(slot, 0) |= BI_SLOT_TEXT_1;
    }
    K_ASSERT(magnitude >= 0, 0x628);
    if (magnitude < 100000) {
        BI_U32(slot, 0xd30) = magnitude;
    } else {
        BI_U32(slot, 0xd30) = 99999;
    }
    sprintf(digits, "%d", BI_U32(slot, 0xd30));
    length = strlen(digits);
    K_ASSERT(length > 0, 0x635);
    K_ASSERT(length <= 5, 0x636);
    BI_U32(slot, 0xd34) = length;
    BI_U32(slot, 0) |= BI_SLOT_NUMERIC_1;
    glyphs = (u8*)slot + 0x830;
    capacity = 5;
    displayValue = BI_U32(slot, 0xd30);
    func_00242840(glyphs, capacity, displayValue);
}
#pragma optimization_level 2

// FUN_00242840
void func_00242840(void* glyphs, s32 capacity, s32 value)
{
    char digits[256];
    s32 i;
    s32 length;

    sprintf(digits, "%d", value);
    length = strlen(digits);
    K_ASSERT(capacity >= length, 0x645);
    for (i = 0; i < length; i++) {
        biMainPrepareDigit((u8*)glyphs + i * 0x100, digits[i] - '0');
    }
}

// FUN_002428F0
void func_002428f0(void* glyph, s32 digit)
{
    func_0021d3b0(glyph, func_0021cca0((void*)func_0021c3f0(1), digit + 0x2e));
}

// FUN_00242950
f32 func_00242950(s32 value)
{
    char digits[256];
    s32 length;
    void* renderContext;
    void* glyphResource;

    renderContext = (void*)func_0021c3f0(1);
    sprintf(digits, "%d", value);
    length = strlen(digits);
    glyphResource = func_0021cca0(renderContext, 0x2e);
    K_ASSERT(length > 0, 0x666);
    K_ASSERT(length <= 5, 0x667);
    return (f32)*(s32*)((u8*)glyphResource + 0xc) + 28.0f * (f32)(length - 1);
}

// FUN_00242A30
void func_00242a30(void* slot)
{
    BI_U32(slot, 0) |= BI_SLOT_ALT_STYLE;
}

// FUN_00242A50
void func_00242a50(void* slot, u32 unitId)
{
    BI_U32(slot, 0x314) = unitId;
}

/* Removing this loses func_00242a60 (MATCH nd0 -> MISMATCH nd18) - measured W161. */
#pragma optimization_level 1
// FUN_00242A60
s32 func_00242a60(void)
{
    s32 i;
    u8* work;
    s32 stride;

    K_ASSERT(sBiMain != NULL, 0x8a);
    work = sBiMain;
    i = 0;
    stride = BI_SLOT_SIZE;
    for (; i < BI_SLOT_COUNT; i++) {
        if (~BI_U32(work + i * stride, 0) & BI_SLOT_ACTIVE) {
            break;
        }
    }
    return i < BI_SLOT_COUNT;
}
#pragma optimization_level 2

/* Removing this loses func_00242ae0 (MATCH nd0 -> MISMATCH nd18) - measured W161. */
#pragma optimization_level 1
// FUN_00242AE0
s32 func_00242ae0(u32 unitId)
{
    s32 i;
    u8* work;
    s32 stride;
    u8* slot;

    K_ASSERT(sBiMain != NULL, 0x8a);
    work = sBiMain;
    i = 0;
    stride = BI_SLOT_SIZE;
    for (; i < BI_SLOT_COUNT; i++) {
        slot = work + i * stride;
        if ((~BI_U32(slot, 0) & BI_SLOT_ACTIVE) || BI_U32(slot, 0x314) != unitId) {
            continue;
        }
        break;
    }
    return i < BI_SLOT_COUNT;
}
#pragma optimization_level 2

// FUN_00242B80
u32 func_00242b80(u16 unitId, RwV2d* screenPosition)
{
    void* unit;
    RwV3d projected;
    RwV2d transformed;

    unit = btlUnitFindFromId((u32)unitId);
    if (unit == NULL) {
        return 0;
    }
    func_002806d0(unit, &projected);
    if (func_002d20a0(&projected, &transformed) == 0) {
        return 0;
    }
    screenPosition->x = transformed.x;
    screenPosition->y = transformed.y + 14.0f;
    return 1;
}

// FUN_00242C20
void func_00242c20(void* slot, u32 leftValue, u32 rightValue)
{
    BI_U32(slot, 0) |= 0x20;
    BI_U32(slot, 0xf44) = leftValue;
    BI_U32(slot, 0xf40) = rightValue;
}


#include "Utils.h"
#include "Battle/battle.h"
#include "Main/Battle/Cmd/bpp_main.h"
#include "rw/rwplcore.h"
extern const char D_0068E880[];
extern const char DAT_007cc468[];

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned int ulong;
extern f32 sinf_y2(f32 angle);
extern f32 cosf_y2(f32 angle);

/* BPC state rooted at DAT_007CE320 / GP-0x49D0. */
extern u32* DAT_007ce320;
#define sBpcWork DAT_007ce320
#pragma alias bppMain0020f8b0_u16 bppMain0020f8b0
extern void bppMain0020f8b0_u16(u16 pcId);
#pragma alias bppMain0020fb60_u16 bppMain0020fb60
extern void bppMain0020fb60_u16(u16 pcId);
#pragma alias bppMain0020f7d0_u16 bppMain0020f7d0
extern void bppMain0020f7d0_u16(u16 pcId);
#pragma alias bppMain0020fa80_u16 bppMain0020fa80
extern void bppMain0020fa80_u16(u16 pcId);
#pragma alias func_001775a0_s16 func_001775a0
extern u32 func_001775a0_s16(s16 id);

typedef void (*BpcRenderState)(s32 property, u32 value);
typedef void (*BpcRenderQuad)(void* quad, s32 count, s32 group, s32 pass, s32 blend);
extern BpcRenderState D_00960090_y2;
#pragma alias D_0096009C_abs D_0096009C_y2
extern u8 D_0096009C_abs[];
extern BpcRenderQuad D_0096009C_y2;
extern f32 DAT_007caf38;
extern u32 DAT_007ce4e8;
extern u8* DAT_007ce410;

extern int func_001ff430(u32 id);
extern u32 func_0021c3f0_y2(s32 texture);
extern u32 func_0021cca0_y2(u32 texture, s32 frame);
extern u32 func_0021cce0_y2(u32 frame);
extern void func_0021d3b0_y2(void* destination, u32 frame);
extern void func_0021d890_y2(void* destination, const f32* layout);
extern void func_0021d8e0_y2(void* destination, const f32* layout);
extern void func_0021d950_y2(void* destination, const u8* color);
extern void func_0021e380(void* destination, u32 frame, s32 mode);
extern void func_0021eb80(void* destination, const f32* layout);
extern void func_0021cd00(u32 frame, f32* rect);
extern void func_00280580(int unit, void* projected);
extern u32 func_002d20a0_y2(const void* projected, void* screen);
// Typed aliases preserve the established ABI of unrelated callers.
#pragma alias func_00280580_vec func_00280580
extern void func_00280580_vec(int unit, RwV3d* projected);
#pragma alias func_002d20a0_vec func_002d20a0_y2
extern u32 func_002d20a0_vec(const RwV3d* projected, RwV2d* screen);
extern int func_0029a1d0(int unit);
extern int func_00301ca0(u32 calc, u32 skill);
extern int func_00300e90();
extern u32 func_00306e80(u32 calc, s16 mode);
extern s16 func_003082f0();
extern void func_003b0170(u32 resource);
extern u32 func_003b0970(u32 resource, s32 mode, s32 group, s32 a, s32 b);
extern void func_003b0d70(u32 resource, s32 x, s32 y);
extern void func_003b0e20(u32 resource, u32 value);
extern void func_003b0e70(s32 mode);
extern void func_003b0e90(s32 mode);
extern void func_003b1360(u32 resource, s32 mode, s32 value);
extern s32 func_003b19d0(u32 resource);
extern void func_004d7f60(s32 state, u32 value);
extern u32 func_00173370(u32 persona);
extern u32 func_00174800(s32 id);
extern s32 func_00176a30(u32 persona);
extern u32 func_001775a0(u16 id);
extern u32 func_0017b260(u16 id);
extern u32 func_001ff630(s32 index);
extern u32 func_0010a4e0(s32 a, s32 b, s32 c, s32 d);
extern u32 datPersonaGetByPcId(s32 id);
extern u32 datPersonaGetSkills(u32 persona);
extern s32 datPersonaCountValidSkills(u32 persona);
extern int printf(const char* format, ...);




/* High-gap entry points; declarations keep cross-calls typed under MWCC. */
void FUN_00242c40(u32*);
void FUN_00242c60(void);
void FUN_00242cc0(void);
void FUN_00243150(void);
void FUN_00244120(u32);
void FUN_002441b0(u32);
void FUN_00244770(void);
void FUN_002449d0(void);
void FUN_00244a00(void);
void FUN_00244a40(u32);
u32 FUN_00244e10(void);
void FUN_00244e80(void);
void FUN_002453d0(u16);
void FUN_00245420(uint*,u32);
void FUN_00245910(uint*);
void FUN_00245970(uint*);
void FUN_002459d0(uint*);
void FUN_00245a00(void);
uint *FUN_00245bf0(int);
void FUN_00245cd0(void);
void FUN_00245e00(void);
void FUN_00245e50(void);
void FUN_00245ea0(void);

// FUN_00242C40
void FUN_00242c40(u32 *param_1)

{
  *param_1 = 0;
  param_1[2] = 0;
  param_1[0x1cb5] = 0;
  sBpcWork = param_1;
  return;
}







































/* W389 measured opt_dead_assignments off: nd16/1264B -> nd8/1264B (window 1264B). */
/* W389 volatile staging of calc/skill and mode/skill loads was neutral at nd8/1264B; reverted. */

























/* W389 measured opt_propagation off: nd7126/9636B -> nd6938/9468B (window 9712B). */
