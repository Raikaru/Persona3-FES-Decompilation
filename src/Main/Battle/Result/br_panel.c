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
extern void func_003b1360(u32 resource, s32 visible, s32 flags);
extern void func_003b2c60(u32 resource, float value);
extern float func_0021ea00(s32 duration);
extern void func_0021eac0(void* animation, float value);
extern void* func_0021cca0(u32 texture, s32 frame);
extern void func_0021d3b0(void* panel, void* source);
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

// FUN_00234820 NONMATCHING
void brPanel00234820(u32* work)
{
    float rect[4];

    work[0] = 0;
    work[0x1d50 / 4] = 0;
    func_003b0e70(1);
    func_003b0e90(2);
    work[0x310 / 4] = func_003b0970(1, 6, 0, 0, 0);
    func_003b0e90(1);
    func_003b0e70(2);
    func_003b0e20(work[0x310 / 4], 0xffffff);
    func_003b2c60(work[0x310 / 4], 1.0f - func_0021ea00(0x28));
    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = 640.0f;
    rect[3] = 448.0f;
    func_0021d8e0((u8*)work + 0x2560, rect);
    func_0021eac0((u8*)work + 0x2560, func_0021ea00(10));
    brPanelSetColor((u8*)work + 0x2560, 0xff, 0xff, 0xff, 0);
    work[0x2660 / 4] = 1;
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

// FUN_00234a00 NONMATCHING
void brPanel00234a00(u32* params)
{
    s32 i;
    u8* entry;

    K_ASSERT(sBrPanel != NULL, 0x99);
    BR_PANEL_WORD(0) &= ~(4 | 8);
    if (params[0] & 1) {
        BR_PANEL_WORD(0) |= 8;
    }
    BR_PANEL_WORD(0x2664) = params[0xb];
    BR_PANEL_WORD(0x266c) = 0;
    BR_PANEL_WORD(0x1d50) = params[10];
    for (i = 0; i < (s32)params[10]; i++) {
        entry = BR_PANEL_ENTRY(i);
        *(u32*)(entry + 0) = params[i * 3 + 1];
        *(u32*)(entry + 4) = params[i * 3 + 2];
        *(u32*)(entry + 8) = params[i * 3 + 3];
        *(u32*)(entry + 0xc) = 0;
    }
    if (BR_PANEL_WORD(0x1d50) != 0) {
        BR_PANEL_WORD(0) |= 4;
    }
    K_ASSERT(BR_PANEL_WORD(0) & 1, 0xf8);
    brPanelSetQuad((u8*)sBrPanel + 0x10, 0.0f, 0.0f, 256.0f, 256.0f);
    brPanelSetQuad((u8*)sBrPanel + 0x110, 0.0f, 0.0f, 256.0f, 256.0f);
    brPanelSetQuad((u8*)sBrPanel + 0x210, 0.0f, 0.0f, 256.0f, 256.0f);
    brPanel00235f30((u8*)sBrPanel + 0x320, 2, BR_PANEL_WORD(0x2660), 1);
    for (i = 0; i < 2; i++) {
        func_0021eac0((u8*)sBrPanel + 0x320 + i * 0x100, func_0021ea00(0x28));
    }
    brPanel00235f30((u8*)sBrPanel + 0x520, 7, BR_PANEL_WORD(0x2664), 0);
    for (i = 0; i < 7; i++) {
        func_0021eac0((u8*)sBrPanel + 0x520 + i * 0x100, func_0021ea00(0x28));
    }
    brPanel00236390();
    BR_PANEL_WORD(0) |= 1;
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
