#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Result/br_panel.h"
#include "Main/Battle/Result/br_res.h"

#define BR_PANEL_WORD(offset) (*(u32*)((u8*)sBrPanel + (offset)))
#define BR_PANEL_ENTRY(index) ((u8*)sBrPanel + 0xe20 + (index) * 0x510)

static u32* sBrPanel; // puGpffffb620

extern void func_003b0170(u32 resource);
extern void func_003b0e20(u32 resource, u32 color);
extern void func_003b0e70(s32 state);
extern void func_003b0e90(s32 state);
extern u32 func_003b0970(u32 type, s32 a, s32 b, s32 c, s32 d);
extern u32 func_00177790(s16 pcId);
extern u8 datGetLevel(s16 pcId);
extern const char* func_00171110(s16 id, s16 field);
extern void bpIFont00238980(void* glyphs, s32 capacity, s32 value, s32 style);
extern void func_003b1360(u32 resource, s32 visible, s32 flags);
extern void func_003b2c60(u32 resource, float value);
extern float func_0021ea00(s32 duration);
extern void func_0021eac0(void* animation, float value);
extern void* func_0021cca0(u32 texture, s32 frame);
extern void func_0021d3b0(void* panel, void* source);
extern void func_0021e380(void* panel, void* source, s32 mode);
extern void func_0021d8e0(void* panel, const float* rect);
extern void func_0021d950(void* panel, const u8* color);
extern int sprintf(char* buffer, const char* format, ...);
extern u32 strlen(const char* string);

static void brPanel002361d0(void* glyph, s32 digit, s32 style);
static void brPanel00236390(void);

static void brPanelSetQuad(void* quad, float x, float y, float width, float height)
{
    float rect[4];

    rect[0] = x;
    rect[1] = y;
    rect[2] = width;
    rect[3] = height;
    func_0021d8e0(quad, rect);
}

static void brPanelSetColor(void* quad, u8 red, u8 green, u8 blue, u8 alpha)
{
    u8 color[4];

    color[0] = red;
    color[1] = green;
    color[2] = blue;
    color[3] = alpha;
    func_0021d950(quad, color);
}

// FUN_00234820
void brPanel00234820(u32* work)
{
    float rect[4];
    u8 color[4];

    work[0] = 0;
    work[0x1d50 / 4] = 0;
    func_003b0e70(1);
    func_003b0e90(2);
    work[0x310 / 4] = func_003b0970(func_00177790(1), 1, 6, 0, 0);
    func_003b0e90(1);
    func_003b0e70(2);
    func_003b0e20(work[0x310 / 4], 0xffffff);
    func_003b2c60(work[0x310 / 4],
                  *(f32*)(uintptr_t)0x00960088 - func_0021ea00(0x28));
    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = 640.0f;
    rect[3] = 448.0f;
    func_0021d8e0((u8*)work + 0x2560, rect);
    func_0021eac0(work + 0x958, func_0021ea00(10));
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = 0;
    func_0021d950((void*)((uintptr_t)work + 0x2560), color);
    work[0x2660 / 4] = datGetLevel(1) & 0xff;
    sBrPanel = work;
}

// FUN_00234960
void brPanel00234960(void)
{
    s32 i;
    u32* work;

    K_ASSERT(sBrPanel != NULL, 0x99);
    work = sBrPanel;
    func_003b0170(work[0x310 / 4]);
    for (i = 0; i < (s32)work[0x1d50 / 4]; i++) {
        func_003b0170(*(u32*)((u8*)work + 0xe2c + i * 0x510));
    }
    sBrPanel = NULL;
}

// FUN_00234a00
void brPanel00234a00(u32* params)
{
    struct BrPanelFields {
        u8 padding[0x2660];
        s32 level;
        s32 value;
    };
    s32 copyIndex;
    s32 animIndex;
    u32 texture;
    s32 glyphIndex;
    s32 entryIndex;
    u8* entry;
    u32* source;
    u32* work;
    struct BrPanelFields* fields;
    u32 digitTexture;
    u32 handle;
    void* frame;

    K_ASSERT(sBrPanel != NULL, 0x99);
    work = sBrPanel;
    fields = (struct BrPanelFields*)work;
    work[0] &= ~4;
    work[0] &= ~8;
    if (params[0] & 1) {
        work[0] |= 8;
    }
    work[0x2664 / 4] = params[0xb];
    work[0x266c / 4] = 0;
    work[0x1d50 / 4] = params[10];
    for (copyIndex = 0; copyIndex < (s32)params[10]; copyIndex++) {
        source = params + copyIndex * 3;
        entry = (u8*)work + copyIndex * 0x510 + 0xe20;
        *(u32*)(entry + 0) = source[1];
        *(u32*)(entry + 4) = source[2];
        *(u32*)(entry + 8) = source[3];
    }
    if (work[0x1d50 / 4] != 0) {
        work[0] |= 4;
    }
    K_ASSERT((~work[0] & 1) != 0, 0xf8);

    texture = brRes00234570(0);
    digitTexture = brRes00234570(1);
    func_0021d3b0((u8*)work + 0x10, func_0021cca0(texture, 0));
    func_0021d3b0((u8*)work + 0x110, func_0021cca0(texture, 5));
    func_0021d3b0((u8*)work + 0x210, func_0021cca0(texture, 3));
    entry = (u8*)work + 0x320;
    bpIFont00238980(entry, 2, fields->level, 1);
    for (animIndex = 0; animIndex < 2; animIndex++) {
        func_0021eac0((u8*)work + 0x320 + animIndex * 0x100,
                      func_0021ea00(0x28));
    }
    entry = (u8*)work + 0x520;
    brPanel00235f30(entry, 7, fields->value, 0);
    for (animIndex = 0; animIndex < 7; animIndex++) {
        func_0021eac0((u8*)work + 0x520 + animIndex * 0x100,
                      func_0021ea00(0x28));
    }
    func_0021d3b0((u8*)work + 0xc20, func_0021cca0(texture, 2));
    func_0021e380((u8*)work + 0xd20, func_0021cca0(texture, 4), 1);

    func_003b0e70(1);
    func_003b0e90(2);
    for (entryIndex = 0;
         entryIndex < (s32)work[0x1d50 / 4];
         entryIndex++) {
        entry = (u8*)work + entryIndex * 0x510 + 0xe20;
        handle = func_003b0970(
            (u32)(uintptr_t)func_00171110(*(s16*)(entry + 4), 0),
            1, 6, 0, 0);
        func_003b2c60(handle,
                      *(f32*)(uintptr_t)0x00960088 - func_0021ea00(0x28));
        *(u32*)(entry + 0xc) = handle;
        func_0021e380(entry + 0x10, func_0021cca0(texture, 4), 1);
        frame = func_0021cca0(texture, 1);
        func_0021d3b0(entry + 0x110, frame);
        brPanel00235f30(entry + 0x210, 2, *(s32*)(entry + 8), 1);
        for (glyphIndex = 0; glyphIndex < 2; glyphIndex++) {
            func_0021eac0(entry + 0x210 + glyphIndex * 0x100,
                          func_0021ea00(0x28));
        }
        switch (*(s32*)entry) {
        case 0:
            frame = func_0021cca0(digitTexture, 0xa);
            break;
        case 1:
            frame = func_0021cca0(digitTexture, 0xb);
            break;
        }
        func_0021d3b0(entry + 0x410, frame);
    }
    func_003b0e90(1);
    func_003b0e70(2);

    func_0021d3b0((u8*)work + 0x1d60, func_0021cca0(texture, 6));
    func_0021eac0(work + 0x758, func_0021ea00(0x1e));
    if (work[0] & 8) {
        frame = func_0021cca0(texture, 0xa);
    } else {
        frame = func_0021cca0(texture, 8);
    }
    func_0021d3b0((u8*)work + 0x1f60, frame);
    func_0021eac0(work + 0x7d8, func_0021ea00(0x1e));
    func_0021d3b0((u8*)work + 0x1e60, func_0021cca0(texture, 9));
    func_0021eac0(work + 0x798, func_0021ea00(0x1e));
    func_0021d3b0((u8*)work + 0x2160, func_0021cca0(texture, 7));
    func_0021eac0(work + 0x858, func_0021ea00(0x1e));
    func_0021d3b0((u8*)work + 0x2060, func_0021cca0(texture, 9));
    func_0021eac0(work + 0x818, func_0021ea00(0x1e));
    brPanel00236390();
    work[0] |= 1;
}

// FUN_00235010
void brPanel00235010(void)
{
    u32* work;
    u32 flags;

    K_ASSERT(sBrPanel != NULL, 0x99);
    work = sBrPanel;
    flags = work[0];
    if ((~flags & 1) != 0) {
        return;
    }
    switch (work[0x266c / 4]) {
    case 1:
        if ((s32)work[0x2668 / 4] < 10) {
            work[0x2668 / 4]++;
        } else {
            work[0] = flags & ~2;
        }
        break;
    case 2:
        if ((s32)work[0x2668 / 4] < 10) {
            work[0x2668 / 4]++;
        } else {
            work[0] = flags & ~2;
        }
        break;
    }
    brPanel00236390();
}

// FUN_002350f0 NONMATCHING
void brPanel002350f0(void)
{
    s32 i;

    K_ASSERT(sBrPanel != NULL, 0x99);
    if ((BR_PANEL_WORD(0) & 1) == 0) {
        return;
    }
    func_003b1360(BR_PANEL_WORD(0x310), 1, 0);
    for (i = 0; i < (s32)BR_PANEL_WORD(0x1d50); i++) {
        if (*(u32*)(BR_PANEL_ENTRY(i) + 0xc) != 0) {
            func_003b1360(*(u32*)(BR_PANEL_ENTRY(i) + 0xc), 1, 0);
        }
    }
    brPanel00236390();
}

// FUN_00235f30
void brPanel00235f30(void* glyphs, s32 capacity, s32 value, s32 style)
{
    char digits[0x100];
    s32 i;
    s32 length;

    sprintf(digits, "%d", value);
    length = (s32)strlen(digits);
    K_ASSERT(capacity >= length, 0x26d);
    for (i = 0; i < length; i++) {
        brPanel002361d0((u8*)glyphs + i * 0x100, digits[i] - '0', style);
    }
}

// FUN_00235ff0
void brPanel00235ff0(void* glyphs, s32 capacity, s32 value, s32 style, const float* origin)
{
    float rect[4];
    char digits[0x100];
    u32 texture;
    void* frame;
    s32 i;
    s32 length;

    sprintf(digits, "%d", value);
    length = (s32)strlen(digits);
    K_ASSERT(capacity >= length, 0x281);
    texture = brRes00234570(1);
    for (i = 0; i < length; i++) {
        s32 digit = digits[length - 1 - i] - '0';

        s32 advance;

        switch (style) {
        case 0:
            frame = func_0021cca0(texture, digit + 0xd);
            advance = 0x17;
            break;
        case 1:
            frame = func_0021cca0(texture, digit);
            advance = 0x10;
            break;
        }
        rect[0] = origin[0] + (float)(advance * i);
        rect[1] = origin[1];
        rect[2] = (float)*(s32*)((u8*)frame + 0xc);
        rect[3] = (float)*(s32*)((u8*)frame + 0x10);
        func_0021d8e0((u8*)glyphs + i * 0x100, rect);
    }
    for (; length < capacity; length++) {
        rect[0] = origin[0];
        rect[1] = origin[1];
        rect[2] = 0.0f;
        rect[3] = 0.0f;
        func_0021d8e0((u8*)glyphs + length * 0x100, rect);
    }
}

// FUN_002361d0
static void brPanel002361d0(void* glyph, s32 digit, s32 style)
{
    u32 texture;
    void* frame;

    texture = brRes00234570(1);
    switch (style) {
    case 0:
        frame = func_0021cca0(texture, digit + 0xd);
        break;
    case 1:
        frame = func_0021cca0(texture, digit);
        break;
    }
    func_0021d3b0(glyph, frame);
}

// FUN_00236280
void brPanel00236280(void)
{
    u32* work;

    K_ASSERT(sBrPanel != NULL, 0x99);
    work = sBrPanel;
    work[0x2668 / 4] = 0;
    work[0x266c / 4] = 1;
    work[0] |= 2;
}

// FUN_002362e0
void brPanel002362e0(void)
{
    u32* work;

    K_ASSERT(sBrPanel != NULL, 0x99);
    work = sBrPanel;
    work[0x2668 / 4] = 0;
    work[0x266c / 4] = 2;
    work[0] |= 2;
}

// FUN_00236340
u32 brPanel00236340(void)
{
    K_ASSERT(sBrPanel != NULL, 0x99);
    return BR_PANEL_WORD(0) & 2;
}

// FUN_00236390 NONMATCHING
static void brPanel00236390(void)
{
    s32 i;
    float alpha;
    u8 color;

    K_ASSERT(sBrPanel != NULL, 0x99);
    if ((BR_PANEL_WORD(0) & 1) == 0) {
        return;
    }
    if (BR_PANEL_WORD(0x266c) == 0) {
        alpha = 0.0f;
    } else if (BR_PANEL_WORD(0x266c) == 1) {
        alpha = BR_PANEL_WORD(0x2668) < 10 ? (float)BR_PANEL_WORD(0x2668) / 10.0f : 1.0f;
    } else {
        alpha = BR_PANEL_WORD(0x2668) < 10 ? 1.0f - (float)BR_PANEL_WORD(0x2668) / 10.0f : 0.0f;
    }
    color = (u8)(alpha * 255.0f);
    brPanelSetColor((u8*)sBrPanel + 0x2560, 0xff, 0xff, 0xff, color);
    for (i = 0; i < 2; i++) {
        brPanelSetColor((u8*)sBrPanel + 0x320 + i * 0x100, 0xff, 0xff, 0xff, color);
    }
    for (i = 0; i < 7; i++) {
        brPanelSetColor((u8*)sBrPanel + 0x520 + i * 0x100, 0xff, 0xff, 0xff, color);
    }
    for (i = 0; i < (s32)BR_PANEL_WORD(0x1d50); i++) {
        u8* entry = BR_PANEL_ENTRY(i);
        if (*(u32*)(entry + 0xc) != 0) {
            func_003b2c60(*(u32*)(entry + 0xc), alpha);
        }
    }
}
