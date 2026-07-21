#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwcore.h"

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


void* func_0021c3f0();
void* func_0021cca0();
void* func_0021cce0();
void func_0021d3b0();
void func_0021d890();
void func_0021d8e0();
void func_0021d950();
void func_0021eae0();
void func_0021eac0(void* glyph, f32 value);
void* btlUnitFindFromId();
void func_002806d0();
u32 func_002d20a0();
int sprintf(char*, const char*, ...);
u32 strlen(const char*);
void func_00242840(void* glyphs, s32 capacity, s32 value);
f32 func_00242950(s32 value);
f32 cosf(f32);
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

    renderContext = func_0021c3f0(1);
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

// FUN_0023F540 NONMATCHING
void func_0023f540(void)
{
    s32 i;
    s32 j;
    s32 age;
    s32 first;
    s32 last;
    u8* work;
    u8* slot;
    void* unit;
    void* frame;
    void* renderContext;
    f32 projected[2];
    f32 transform[4];
    f32 layout[4];
    f32 x;
    f32 y;
    f32 alpha;
    f32 t;
    f32 vertical;
    u8 color[4];

    K_ASSERT(sBiMain != NULL, 0x8a);
    work = sBiMain;
    renderContext = func_0021c3f0(1);

    for (i = 0; i < BI_SLOT_COUNT; i++) {
        slot = BI_SLOT(work, i);
        if ((~BI_U32(slot, 0) & BI_SLOT_ACTIVE) != 0) {
            continue;
        }
        unit = btlUnitFindFromId(BI_U16(slot, 0x314));
        if (BI_U32(slot, 0x310) < 50) {
            BI_U32(slot, 0x310)++;
        }
        if (BI_U32(slot, 0x310) == 50 || unit == NULL) {
            BI_U32(slot, 0) &= ~BI_SLOT_ACTIVE;
            BI_U32(slot, 0) &= ~BI_SLOT_INITIALIZED;
        }
    }



    for (i = 0; i < BI_SLOT_COUNT; i++) {
        slot = BI_SLOT(work, i);
        if ((~BI_U32(slot, 0) & BI_SLOT_ACTIVE) != 0) {
            continue;
        }
        unit = btlUnitFindFromId(BI_U16(slot, 0x314));
        func_002806d0(unit, transform);
        if (func_002d20a0(transform, projected) == 0 ||
            *(u8*)((u8*)unit + 0x37) == 0) {
            BI_U32(slot, 0) |= BI_SLOT_HIDDEN;
        } else {
            BI_U32(slot, 0) &= ~BI_SLOT_HIDDEN;
        }
        layout[0] = projected[0] - 1.0f;
        layout[1] = projected[1] - 100.0f;
        layout[2] = 2.0f;
        layout[3] = 200.0f;
        func_0021d8e0(slot + 0xd40, layout);
        layout[0] = projected[0] - 100.0f;
        layout[1] = projected[1] - 1.0f;
        layout[2] = 200.0f;
        layout[3] = 2.0f;
        func_0021d8e0(slot + 0xe40, layout);

        if ((BI_U32(slot, 0) & BI_SLOT_READY) == 0) {
            continue;
        }

        age = (s32)BI_U32(slot, 0x310);
        x = projected[0] - 101.0f;
        y = projected[1] - 81.0f;
        switch (BI_U32(slot, 4)) {
        case 0:
            frame = func_0021cca0(renderContext, 0xb);
            layout[0] = x + 53.0f;
            layout[1] = y + 51.0f;
            layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
            layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
            func_0021d8e0(slot + 0x10, layout);
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
            if ((BI_U32(slot, 0) & BI_SLOT_TEXT_0) != 0) {
                frame = func_0021cca0(renderContext, 0xa);
                layout[0] = 0.0f;
                layout[1] = 0.0f;
                layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
                layout[3] = 0.0f;
                layout[4] = layout[2];
                layout[5] = (f32)*(s32*)((u8*)frame + 0x10);
                layout[6] = 0.0f;
                layout[7] = layout[3];
                for (j = 0; j < 4; j++) {
                    layout[j * 2] -= 150.0f;
                    layout[j * 2 + 1] -= 34.0f;
                }
                if (age < 0) {
                    alpha = 1.0f;
                } else if (age < 12) {
                    t = (f32)age / 12.0f;
                    alpha = 2.0f * t - t * t;
                } else {
                    alpha = 1.0f;
                }
                for (j = 0; j < 4; j++) {
                    layout[j * 2] *= alpha;
                    layout[j * 2 + 1] *= alpha;
                }
                for (j = 0; j < 4; j++) {
                    layout[j * 2] += 75.0f + x;
                    layout[j * 2 + 1] += 29.0f + y;
                }
                func_0021d890(slot + 0x100, layout);
                color[0] = 0xff;
                color[1] = 0xff;
                color[2] = 0xff;
                color[3] = (u8)(u32)(255.0f * alpha);
                func_0021d950(slot + 0x100, color);
            }
            break;
        case 1:
            frame = func_0021cca0(renderContext, 0xb);
            layout[0] = x + 53.0f;
            layout[1] = y + 51.0f;
            layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
            layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
            func_0021d8e0(slot + 0x10, layout);
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
            if ((BI_U32(slot, 0) & BI_SLOT_TEXT_0) != 0) {
                frame = func_0021cca0(renderContext, 0xa);
                layout[0] = 0.0f;
                layout[1] = 0.0f;
                layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
                layout[3] = 0.0f;
                layout[4] = layout[2];
                layout[5] = (f32)*(s32*)((u8*)frame + 0x10);
                layout[6] = 0.0f;
                layout[7] = layout[3];
                for (j = 0; j < 4; j++) {
                    layout[j * 2] -= 150.0f;
                    layout[j * 2 + 1] -= 34.0f;
                }
                if (age < 0) {
                    alpha = 1.0f;
                } else if (age < 8) {
                    alpha = 1.0f;
                } else if (age < 34) {
                    alpha = 1.0f - (f32)(age - 8) / 26.0f;
                } else {
                    alpha = 0.0f;
                }
                for (j = 0; j < 4; j++) {
                    layout[j * 2] *= alpha;
                    layout[j * 2 + 1] *= alpha;
                }
                for (j = 0; j < 4; j++) {
                    layout[j * 2] += 75.0f + x;
                    layout[j * 2 + 1] += 29.0f + y;
                }
                func_0021d890(slot + 0x100, layout);
                color[0] = 0xff;
                color[1] = 0xff;
                color[2] = 0xff;
                color[3] = (u8)(u32)(255.0f * alpha);
                func_0021d950(slot + 0x100, color);
            }
            break;
        case 2:
            frame = func_0021cca0(renderContext, 0x22);
            layout[0] = projected[0] -
                        (f32)((s32)*(s32*)((u8*)frame + 0xc) / 2);
            layout[1] = projected[1] -
                        (f32)((s32)*(s32*)((u8*)frame + 0x10) / 2);
            layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
            layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
            func_0021d8e0(slot + 0x10, layout);
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
            frame = func_0021cca0(renderContext, 0x1e);
            layout[0] = projected[0] - 135.0f;
            layout[1] = projected[1] - 87.0f;
            layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
            layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
            func_0021d8e0(slot + 0x200, layout);
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
            func_0021d950(slot + 0x200, color);
            break;
        case 3:
            frame = func_0021cca0(renderContext, 0x1e);
            layout[0] = x + 22.0f;
            layout[1] = y + 44.0f;
            layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
            layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
            func_0021d8e0(slot + 0x10, layout);
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
                    vertical = 80.0f * (1.0f - alpha);
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
                layout[0] = x + 28.0f * (f32)j;
                layout[1] = y + vertical;
                layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
                layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
                func_0021d8e0(slot + 0x320 + j * 0x100, layout);
                if ((BI_U32(slot, 0) & BI_SLOT_TEXT_1) != 0) {
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
                layout[0] = x;
                layout[1] = y + vertical;
                layout[2] = 0.0f;
                layout[3] = 0.0f;
                func_0021d8e0(slot + 0x320 + j * 0x100, layout);
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
                layout[0] = x + 28.0f * (f32)j;
                layout[1] = y + vertical;
                layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
                layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
                func_0021d8e0(slot + 0x830 + j * 0x100, layout);
                if ((BI_U32(slot, 0) & BI_SLOT_TEXT_0) != 0) {
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
                layout[0] = x;
                layout[1] = y + vertical;
                layout[2] = 0.0f;
                layout[3] = 0.0f;
                func_0021d8e0(slot + 0x830 + j * 0x100, layout);
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
        stateSet(1, (u32)func_0021cce0(frame)); \
        RpSkyRenderStateSet(3, (void*)0x717fb); \
        RpSkyRenderStateSet(2, (void*)0x44); \
        for (biDigitIndex = 0; biDigitIndex < 5; biDigitIndex++) { \
            D_0096009C((u8*)(base) + biDigitIndex * 0x100, 4, 0, 1, 2); \
            D_0096009C((u8*)(base) + biDigitIndex * 0x100, 4, 0, 2, 3); \
        } \
    } while (0)
// FUN_00241910 NONMATCHING
void func_00241910(void)
{
    s32 i;
    u8* work;
    u8* slot;
    void* frame;
    void* renderContext;
    void (*stateSet)(u32, u32);
    u32 flags;
    u32 mode;

    K_ASSERT(sBiMain != NULL, 0x8a);
    work = sBiMain;
    renderContext = func_0021c3f0(1);
    stateSet = D_00960090;
    stateSet(9, 2);
    stateSet(0x14, 2);
    stateSet(8, 0);
    stateSet(6, 0);
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
            frame = func_0021cca0(renderContext, 0xa);
            stateSet(1, (u32)func_0021cce0(frame));
            if ((flags & BI_SLOT_ALT_STYLE) != 0) {
                BI_MAIN_DRAW_ALT(slot + 0x10);
            } else {
                frame = func_0021cca0(renderContext, 0xb);
                stateSet(1, (u32)func_0021cce0(frame));
                BI_MAIN_DRAW_BASIC(slot + 0x10);
            }
            break;
        case 1:
            frame = func_0021cca0(renderContext, 0x12);
            stateSet(1, (u32)func_0021cce0(frame));
            if ((flags & BI_SLOT_ALT_STYLE) != 0) {
                BI_MAIN_DRAW_ALT(slot + 0x10);
            } else {
                BI_MAIN_DRAW_BASIC(slot + 0x10);
            }
            break;
        case 2:
            frame = func_0021cca0(renderContext, 0x1d);
            stateSet(1, (u32)func_0021cce0(frame));
            if ((flags & BI_SLOT_ALT_STYLE) != 0) {
                BI_MAIN_DRAW_ALT(slot + 0x10);
            } else {
                BI_MAIN_DRAW_BASIC(slot + 0x10);
            }
            break;
        case 3:
            frame = func_0021cca0(renderContext, 0x13);
            stateSet(1, (u32)func_0021cce0(frame));
            if ((flags & BI_SLOT_ALT_STYLE) != 0) {
                BI_MAIN_DRAW_ALT(slot + 0x10);
            } else {
                BI_MAIN_DRAW_BASIC(slot + 0x10);
            }
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

    renderContext = func_0021c3f0(1);
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
    func_0021eae0((u8*)slot + 0xd40, &origin);
    func_0021d950((u8*)slot + 0xd40, &color);
    func_0021eac0((u8*)slot + 0xd40, 0.0f);
    func_0021eae0((u8*)slot + 0xe40, &origin);
    func_0021d950((u8*)slot + 0xe40, &color);
    func_0021eac0((u8*)slot + 0xe40, 0.0f);
    BI_U32(slot, 0x310) = 0;
    BI_U32(slot, 0) |= BI_SLOT_INITIALIZED;
}
#pragma optimization_level 2

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
    func_0021d3b0(glyph, func_0021cca0(func_0021c3f0(1), digit + 0x2e));
}

// FUN_00242950
f32 func_00242950(s32 value)
{
    char digits[256];
    s32 length;
    void* renderContext;
    void* glyphResource;

    renderContext = func_0021c3f0(1);
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

    unit = btlUnitFindFromId(unitId);
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
