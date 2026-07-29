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
extern void (*D_00960090)(u32 state, u32 value);
extern void (*D_0096009C)(u32* quad, u32 primitive, u32 offset, u32 first, u32 second);
/* Retail +0x84/+0x114 materialize the state/quad callback-table addresses. */
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
#pragma alias D_0096009C_abs D_0096009C
extern u8 D_0096009C_abs[];
#pragma alias brPanelSetStateRaw D_00960090
#pragma alias brPanelSetQuadRaw D_0096009C
extern void (*brPanelSetStateRaw)(u32 state, u32 value);
extern void (*brPanelSetQuadRaw)(u32* quad, u32 primitive, u32 offset, u32 first, u32 second);
extern void RpSkyRenderStateSet(s32 state, u32 value);
extern u32 func_0021cce0(void* frame);
extern u32 func_00239140(s32 index);
#pragma alias brPanelResRaw brRes00234570
extern u32 brPanelResRaw(s32 type);
extern void func_003b0d70(u32 resource, s32 offset, s32 flags);
extern u32 datGetScenarioMode(void);
extern f32 sqrtf(f32 value);
extern f32 DAT_007caff0;
extern void bpIFont00238a50(void* glyphs, s32 capacity, s32 value, s32 style, const float* origin);

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

/* Retail +0x84 and +0x114 reload these callback tables before their jalr sites. */
#define D_00960090 (*brPanelSetState)
#define D_0096009C (*brPanelSetQuad)
#pragma push
// FUN_002350f0 NONMATCHING
void brPanel002350f0(void)
{
    u8* work;
    BrPanelResultEntry* entry;
    u32 texture;
    u32 digitTexture;
    u32 frame;
    u32 digitFrame;
    s32 i;
    s32 mode;
    void (**brPanelSetState)(u32 state, u32 value);
    void (**brPanelSetQuad)(u32* quad, u32 primitive, u32 offset, u32 first, u32 second);
    u32 workFlags;
    s32 j;
    void (**entrySetQuad)(u32* quad, u32 primitive, u32 offset, u32 first, u32 second);
    s32 entryType;
    u8* digitRowBase;

    K_ASSERT(sBrPanel != NULL, 0x99);
    work = (u8*)sBrPanel;
    if ((~(*(u32*)work) & 1) != 0) {
        return;
    }
    
    texture = brRes00234570(0);
    digitTexture = brRes00234570(1);
    brPanelSetState = (void (**)(u32, u32))D_00960090_abs;

    D_00960090(9, 2);
    D_00960090(0x14, 2);
    D_00960090(8, 1);
    D_00960090(6, 0);
    RpSkyRenderStateSet(3, 0x717fb);
    RpSkyRenderStateSet(2, 0x44);
    D_00960090(1, 0);
    brPanelSetQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
    D_0096009C((u32*)(work + 0x2560), 4, 0, 1, 2);
    D_0096009C((u32*)(work + 0x2560), 4, 0, 2, 3);

    D_00960090(8, 1);
    D_00960090(6, 0);
    RpSkyRenderStateSet(3, 0x717fb);
    RpSkyRenderStateSet(2, 0x44);
    D_00960090(1, 0);
    D_0096009C((u32*)(work + 0x2260), 4, 0, 1, 2);
    D_0096009C((u32*)(work + 0x2260), 4, 0, 2, 3);

    D_00960090(8, 0);
    D_00960090(6, 1);
    RpSkyRenderStateSet(3, 0x717fb);
    RpSkyRenderStateSet(2, 0x44);
    frame = func_0021cce0(func_0021cca0(texture, 4));
    D_00960090(1, frame);
    D_0096009C((u32*)(work + 0xd20), 4, 0, 1, 2);
    D_0096009C((u32*)(work + 0xd20), 4, 0, 2, 3);
    frame = func_0021cce0(func_0021cca0(digitTexture, 0xd));
    D_00960090(1, frame);
    RpSkyRenderStateSet(3, 0x717fb);
    RpSkyRenderStateSet(2, 0x44);

    digitRowBase = work + 0x520;
    for (i = 0; i < 7; i++) {
        D_0096009C((u32*)(digitRowBase + i * 0x100), 4, 0, 1, 2);
        D_0096009C((u32*)(digitRowBase + i * 0x100), 4, 0, 2, 3);
    }
    RpSkyRenderStateSet(3, 0x717fb);
    RpSkyRenderStateSet(2, 0x44);
    frame = func_0021cce0(func_0021cca0(texture, 2));
    D_00960090(1, frame);
    D_0096009C((u32*)(work + 0xc20), 4, 0, 1, 2);
    D_0096009C((u32*)(work + 0xc20), 4, 0, 2, 3);
    RpSkyRenderStateSet(3, 0x717fb);
    RpSkyRenderStateSet(2, 0x44);
    for (i = 0; i < *(s32*)(work + 0x1d50); i++) {
        entry = (BrPanelResultEntry*)(work + 0xe20) + i;
        frame = (u32)(uintptr_t)func_0021cca0(texture, 4);
        brPanelSetState = (void (**)(u32, u32))D_00960090_abs;
        frame = func_0021cce0((void*)(uintptr_t)frame);
        D_00960090(1, frame);
        brPanelSetQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
        D_0096009C((u32*)entry->background, 4, 0, 1, 2);
        D_0096009C((u32*)entry->background, 4, 0, 2, 3);
        func_003b0e70(0x40);
        RpSkyRenderStateSet(3, 0x717fb);
        RpSkyRenderStateSet(2, 0x44);
        func_003b1360(entry->fontHandle, 1, 0);
        func_003b0e90(0x40);
        RpSkyRenderStateSet(3, 0x717fb);
        RpSkyRenderStateSet(2, 0x44);
        frame = func_0021cce0(func_0021cca0(texture, 1));
        D_00960090(1, frame);
        D_0096009C((u32*)entry->label, 4, 0, 1, 2);
        D_0096009C((u32*)entry->label, 4, 0, 2, 3);
        frame = func_0021cce0(func_0021cca0(digitTexture, 0));
        D_00960090(1, frame);
        RpSkyRenderStateSet(3, 0x717fb);
        RpSkyRenderStateSet(2, 0x44);
        for (j = 0; j < 2; j++) {
            entrySetQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
            (*entrySetQuad)((u32*)entry->digits[j], 4, 0, 1, 2);
            (*entrySetQuad)((u32*)entry->digits[j], 4, 0, 2, 3);
        }
        entryType = entry->type;
        if (entryType == 0) {
            digitFrame = (u32)(uintptr_t)func_0021cca0(digitTexture, 0xa);
        } else {
            digitFrame = (u32)(uintptr_t)func_0021cca0(digitTexture, 0xb);
        }
        frame = func_0021cce0((void*)(uintptr_t)digitFrame);
        D_00960090(1, frame);
        D_0096009C((u32*)entry->typeIcon, 4, 0, 1, 2);
        D_0096009C((u32*)entry->typeIcon, 4, 0, 2, 3);
    }

    D_00960090(8, 0);
    D_00960090(6, 1);
    RpSkyRenderStateSet(3, 0x717fb);
    RpSkyRenderStateSet(2, 0x44);
    frame = func_0021cce0(func_0021cca0(texture, 0));
    D_00960090(1, frame);
    D_0096009C((u32*)(work + 0x10), 4, 0, 1, 2);
    D_0096009C((u32*)(work + 0x10), 4, 0, 2, 3);
    frame = func_0021cce0(func_0021cca0(texture, 5));
    D_00960090(1, frame);
    D_0096009C((u32*)(work + 0x110), 4, 0, 1, 2);
    D_0096009C((u32*)(work + 0x110), 4, 0, 2, 3);
    frame = func_0021cce0(func_0021cca0(texture, 3));
    D_00960090(1, frame);
    D_0096009C((u32*)(work + 0x210), 4, 0, 1, 2);
    D_0096009C((u32*)(work + 0x210), 4, 0, 2, 3);
    func_003b0e70(0x40);
    func_003b1360(*(u32*)(work + 0x310), 1, 0);
    func_003b0e90(0x40);
    frame = func_00239140(1);
    D_00960090(1, frame);
    RpSkyRenderStateSet(3, 0x717fb);
    RpSkyRenderStateSet(2, 0x44);
    D_0096009C((u32*)(work + 0x320), 4, 0, 1, 2);
    D_0096009C((u32*)(work + 0x320), 4, 0, 2, 3);
    D_0096009C((u32*)(work + 0x420), 4, 0, 1, 2);
    D_0096009C((u32*)(work + 0x420), 4, 0, 2, 3);
    D_00960090(6, 1);
    D_00960090(1, 0);
    D_0096009C((u32*)(work + 0x2460), 4, 0, 1, 2);
    mode = *(s32*)(work + 0x266c);
    D_0096009C((u32*)(work + 0x2460), 4, 0, 2, 3);
    if (mode == 1) {
        D_00960090(1, 0);
        D_0096009C((u32*)(work + 0x2360), 4, 0, 1, 2);
        D_0096009C((u32*)(work + 0x2360), 4, 0, 2, 3);
    } else if (mode == 2) {
        D_00960090(6, 0);
        D_00960090(8, 0);
        D_00960090(1, 0);
        D_0096009C((u32*)(work + 0x2360), 4, 0, 1, 2);
        D_0096009C((u32*)(work + 0x2360), 4, 0, 2, 3);
    }

    D_00960090(6, 1);
    frame = func_0021cce0(func_0021cca0(texture, 6));
    D_00960090(1, frame);
    D_0096009C((u32*)(work + 0x1d60), 4, 0, 1, 2);
    D_0096009C((u32*)(work + 0x1d60), 4, 0, 2, 3);
    frame = func_0021cce0(func_0021cca0(texture, 9));
    D_00960090(1, frame);
    D_0096009C((u32*)(work + 0x1e60), 4, 0, 1, 2);
    D_0096009C((u32*)(work + 0x1e60), 4, 0, 2, 3);
    workFlags = *(u32*)work;
    if (workFlags & 8) {
        frame = (u32)(uintptr_t)func_0021cca0(texture, 0xa);
    } else {
        frame = (u32)(uintptr_t)func_0021cca0(texture, 8);
    }
    frame = func_0021cce0((void*)(uintptr_t)frame);
    D_00960090(1, frame);
    D_0096009C((u32*)(work + 0x1f60), 4, 0, 1, 2);
    D_0096009C((u32*)(work + 0x1f60), 4, 0, 2, 3);
    workFlags = *(u32*)work;
    if (workFlags & 4) {
        frame = func_0021cce0(func_0021cca0(texture, 7));
        D_00960090(1, frame);
        D_0096009C((u32*)(work + 0x2160), 4, 0, 1, 2);
        D_0096009C((u32*)(work + 0x2160), 4, 0, 2, 3);
        frame = func_0021cce0(func_0021cca0(texture, 9));
        D_00960090(1, frame);
        D_0096009C((u32*)(work + 0x2060), 4, 0, 1, 2);
        D_0096009C((u32*)(work + 0x2060), 4, 0, 2, 3);
    }
}
#pragma opt_loop_invariants off
#undef D_00960090
#undef D_0096009C
#pragma optimization_level 2
#pragma pop

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

#pragma optimization_level 3
#define brRes00234570(x) ((x) == 0 ? texture : digitTexture)
#define BR_PANEL_SET_RECT(dst, x, y, w, h) \
    do { \
        rect[0] = (x); \
        rect[1] = (y); \
        rect[2] = (w); \
        rect[3] = (h); \
        func_0021d8e0((dst), rect); \
    } while (0)
#define BR_PANEL_SET_VERTICES(dst) \
    do { func_0021d890((dst), rect); } while (0)
#define BR_PANEL_ANIMATE(dst, duration) \
    do { anim = func_0021ea00((duration)); \
         func_0021eac0((dst), anim); } while (0)
#define BR_PANEL_SET_COLOR(dst, alpha) \
    do { \
        color[0] = 0xff; \
        color[1] = 0xff; \
        color[2] = 0xff; \
        color[3] = (u8)(u32)(255.0f * (alpha)); \
        func_0021d950((dst), color); \
    } while (0)
// FUN_00236390 NONMATCHING
static void brPanel00236390(void)
{
    u8* work;
    BrPanelResultEntry* entry;
    void* frame;
    u32 texture;
    u32 digitTexture;
    s32 mode;
    s32 timer;
    s32 value;
    s32 length;
    s32 i;
    f32 alpha;
    f32 shift;
    f32 shift2;
    f32 scale;
    f32 textWidth;
    f32 root2;
    f32 baseShift;
    f32 progressShift;
    f32 secondShift;
    f32 anim;
    u8 color[4];
    f32 rect[8];
    char text[0xf0];
    char text2[0x100];
    u32 packedColor;

    K_ASSERT(sBrPanel != NULL, 0x99);
    work = (u8*)sBrPanel;
    texture = brPanelResRaw(0);
    digitTexture = brPanelResRaw(1);
    frame = func_0021cca0(texture, 0);

    if ((*(s32*)(work + 0x266c)) == 2) {
        shift = (f32)((*(s32*)((u8*)frame + 0xc) + 1) / 2);
        alpha = 0.0f;
        if ((*(s32*)(work + 0x2668)) < 10) {
            shift *= (f32)(*(s32*)(work + 0x2668)) / 32.0f;
            alpha = 1.0f - (f32)(*(s32*)(work + 0x2668)) / 32.0f;
        } else {
            shift = 0.0f;
        }
    } else if ((*(s32*)(work + 0x266c)) == 1) {
        shift = 1.0f;
        alpha = 1.0f;
        if ((*(s32*)(work + 0x2668)) < 2) {
            shift = 0.0f;
        } else if ((*(s32*)(work + 0x2668)) < 8) {
            shift = (1.0f - (f32)((*(s32*)(work + 0x2668)) - 2) / 6.0f) * (f32)*(s32*)((u8*)frame + 0xc);
        } else {
            shift = 0.0f;
        }
    } else {
        shift = 0.0f;
        alpha = 0.0f;
    }
    rect[0] = 381.0f + shift;
    rect[1] = 55.0f;
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    frame = func_0021cca0(brRes00234570(0), 0);
    func_0021d8e0(work + 0x10, rect);
    BR_PANEL_ANIMATE(work + 0x10, 0x28);
    BR_PANEL_SET_COLOR(work + 0x10, alpha);
    frame = func_0021cca0(brRes00234570(0), 5);
    if ((*(s32*)(work + 0x266c)) == 0) {
        shift = 0.0f;
        alpha = 0.0f;
    } else if ((*(s32*)(work + 0x266c)) == 1) {
        shift = 100.0f;
        alpha = 0.0f;
        if ((*(s32*)(work + 0x2668)) >= 3) {
            if ((*(s32*)(work + 0x2668)) < 10) {
                shift = (1.0f - (f32)((*(s32*)(work + 0x2668)) - 3) / 6.0f) * 100.0f;
            } else {
                shift = 0.0f;
                alpha = 1.0f;
            }
        }
    } else {
        shift = 0.0f;
        alpha = 1.0f;
        if ((*(s32*)(work + 0x2668)) >= 0 && (*(s32*)(work + 0x2668)) < 10) {
            scale = (f32)(*(s32*)(work + 0x2668)) / 10.0f;
            shift = scale * 40.0f;
            alpha = 1.0f - scale;
        }
    }
    BR_PANEL_SET_RECT(work + 0x110, 397.0f + shift, 342.0f,
                      (f32)*(s32*)((u8*)frame + 0xc),
                      (f32)*(s32*)((u8*)frame + 0x10));
    BR_PANEL_ANIMATE(work + 0x110, 0x28);
    BR_PANEL_SET_COLOR(work + 0x110, alpha);

    frame = func_0021cca0(brRes00234570(0), 3);
    if ((*(s32*)(work + 0x266c)) == 0) {
        shift = 0.0f;
        alpha = 0.0f;
    } else if ((*(s32*)(work + 0x266c)) == 1) {
        shift = 200.0f;
        alpha = 0.0f;
        if ((*(s32*)(work + 0x2668)) >= 4) {
            if ((*(s32*)(work + 0x2668)) < 10) {
                shift = (1.0f - (f32)((*(s32*)(work + 0x2668)) - 4) / 6.0f) * 200.0f;
            } else {
                shift = 0.0f;
                alpha = 1.0f;
            }
        }
    } else {
        shift = 0.0f;
        alpha = 1.0f;
        if ((*(s32*)(work + 0x2668)) >= 0 && (*(s32*)(work + 0x2668)) < 10) {
            scale = (f32)(*(s32*)(work + 0x2668)) / 10.0f;
            shift = scale * 160.0f;
            alpha = 1.0f - scale;
        }
    }
    BR_PANEL_SET_RECT(work + 0x210, 413.0f + shift, 372.0f,
                      (f32)*(s32*)((u8*)frame + 0xc),
                      (f32)*(s32*)((u8*)frame + 0x10));
    BR_PANEL_ANIMATE(work + 0x210, 0x28);
    BR_PANEL_SET_COLOR(work + 0x210, alpha);

    value = *(s32*)(work + 0x2660);
    K_ASSERT(value > 0 && value < 100, 0x3bd);
    if ((*(s32*)(work + 0x266c)) == 0) {
        shift = 0.0f;
        alpha = 0.0f;
    } else if ((*(s32*)(work + 0x266c)) == 1) {
        shift = 40.0f;
        alpha = 0.0f;
        if ((*(s32*)(work + 0x2668)) >= 5) {
            if ((*(s32*)(work + 0x2668)) < 11) {
                shift = (1.0f - (f32)((*(s32*)(work + 0x2668)) - 5) / 6.0f) * 40.0f;
            } else {
                shift = 0.0f;
                alpha = 1.0f;
            }
        }
    } else {
        shift = 0.0f;
        alpha = 1.0f;
        if ((*(s32*)(work + 0x2668)) >= 0 && (*(s32*)(work + 0x2668)) < 10) {
            scale = (f32)(*(s32*)(work + 0x2668)) / 10.0f;
            shift = scale * 40.0f;
            alpha = 1.0f - scale;
        }
    }

    if (value < 10) {
        rect[0] = 465.0f + shift;
    } else {
        rect[0] = 473.0f + shift;
    }
    rect[1] = 372.0f;
    rect[2] = 0.0f;
    rect[3] = 0.0f;
    bpIFont00238a50(work + 0x320, 2, value, 1, rect);
    BR_PANEL_SET_COLOR(work + 0x320, alpha);
    if (datGetScenarioMode() != 0) {
        func_003b0d70(*(u32*)(work + 0x310),
                      (s32)((477.0f + shift) * 16.0f), 0xc28);
    } else {
        func_003b0d70(*(u32*)(work + 0x310),
                      (s32)((427.0f + shift) * 16.0f), 0xc28);
    }
    packedColor = 0xffffff00 | (u8)(u32)(255.0f * alpha);
    func_003b0e20(*(u32*)(work + 0x310), packedColor);

    if ((*(s32*)(work + 0x266c)) == 0) {
        shift = 0.0f;
        alpha = 0.0f;
    } else if ((*(s32*)(work + 0x266c)) == 1) {
        shift = -40.0f;
        alpha = 0.0f;
        if ((*(s32*)(work + 0x2668)) >= 2) {
            if ((*(s32*)(work + 0x2668)) < 7) {
                shift = (1.0f - (f32)((*(s32*)(work + 0x2668)) - 2) / 5.0f) * -40.0f;
            } else {
                shift = 0.0f;
                alpha = 1.0f;
            }
        }
    } else {
        shift = 0.0f;
        alpha = 1.0f;
        if ((*(s32*)(work + 0x2668)) >= 0 && (*(s32*)(work + 0x2668)) < 10) {
            alpha = 1.0f - (f32)(*(s32*)(work + 0x2668)) / 10.0f;
        }
    }
    frame = func_0021cca0(brRes00234570(0), 2);
    sprintf(text, "%d", *(s32*)(work + 0x2664));
    length = (s32)strlen(text);
    textWidth = (f32)(length * 23);
    rect[0] = 350.0f - (textWidth + 40.0f +
                        (f32)*(s32*)((u8*)frame + 0xc)) / 2.0f + shift;
    rect[1] = 154.0f;
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    brPanel00235ff0(work + 0x520, 7, *(s32*)(work + 0x2664), 0, rect);
    BR_PANEL_SET_COLOR(work + 0x520, alpha);
    sprintf(text2, "%d", *(s32*)(work + 0x2664));
    length = (s32)strlen(text2);
    textWidth = (f32)(length * 23);

    frame = func_0021cca0(brRes00234570(0), 2);
    rect[0] = 40.0f + textWidth +
              40.0f - 0.0f + shift;
    rect[1] = 158.0f;
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    BR_PANEL_SET_RECT(work + 0xc20, rect[0], rect[1], rect[2], rect[3]);
    BR_PANEL_ANIMATE(work + 0xc20, 0x28);
    BR_PANEL_SET_COLOR(work + 0xc20, alpha);


    frame = func_0021cca0(brRes00234570(0), 6);
    scale = 1.0f;
    if ((*(s32*)(work + 0x266c)) == 1 && (*(s32*)(work + 0x2668)) < 8) {
        scale = (f32)(*(s32*)(work + 0x2668)) / 8.0f;
    } else if ((*(s32*)(work + 0x266c)) == 2 && (*(s32*)(work + 0x2668)) < 10) {
        scale = (f32)(*(s32*)(work + 0x2668)) / 10.0f;
    }
    rect[0] = 0.0f;
    rect[1] = 169.0f;
    rect[2] = 640.0f * scale;
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    BR_PANEL_SET_RECT(work + 0xd20, rect[0], rect[1], rect[2], rect[3]);
    BR_PANEL_ANIMATE(work + 0xd20, 0x28);
    BR_PANEL_SET_COLOR(work + 0xd20, alpha);
    for (i = 0; i < (s32)*(u32*)(work + 0x1d50); i++) {
        entry = (BrPanelResultEntry*)(work + 0xe20) + i;
        baseShift = (f32)(i * 30);
        progressShift = (f32)((*(s32*)(work + 0x2668)) - i);
        secondShift = (f32)((*(s32*)(work + 0x2668)) + i + 1);
        if ((*(s32*)(work + 0x266c)) == 0) {
            shift = 0.0f;
            alpha = 0.0f;
            scale = 1.0f;
            progressShift = 0.0f;
            secondShift = 0.0f;
        } else if ((*(s32*)(work + 0x266c)) == 1) {
            shift = progressShift;
            alpha = 1.0f;
            scale = 1.0f;
            if (progressShift <= 0.0f) {
                shift = -40.0f;
                alpha = 0.0f;
                scale = 0.0f;
            } else if (progressShift < 4.0f) {
                scale = 1.0f - (progressShift - 1.0f) / 3.0f;
                shift = -40.0f * scale;
                alpha = scale;
            } else if (progressShift < 8.0f) {
                secondShift = (progressShift - 4.0f) / 4.0f;
                shift = -40.0f * (1.0f - secondShift);
                scale = 0.75f + secondShift * 0.25f;
                alpha = 0.75f + secondShift * 0.25f;
            } else {
                shift = 0.0f;
            }
        } else {
            shift = 0.0f;
            scale = 1.0f;
            alpha = 1.0f;
            if ((*(s32*)(work + 0x2668)) < 3) {
                secondShift = (f32)(*(s32*)(work + 0x2668)) / 3.0f;
                shift = -40.0f * (1.0f - secondShift);
                scale = secondShift;
                alpha = secondShift;
            } else if ((*(s32*)(work + 0x2668)) < 10) {
                secondShift = (f32)((*(s32*)(work + 0x2668)) - 3) / 7.0f;
                shift = -40.0f * (1.0f - secondShift);
                scale = 0.5f + secondShift * 0.5f;
                alpha = 0.5f + secondShift * 0.5f;
            } else {
                alpha = 0.0f;
                scale = 0.0f;
            }
        }
        func_003b0d70(entry->fontHandle,
                      (s32)((174.0f - baseShift + shift +
                             progressShift * 2.0f) * 16.0f),
                      (s32)((210.0f + baseShift +
                             secondShift * 2.0f) * 8.0f));
        packedColor = 0xffffff00 | (u8)(u32)(255.0f * alpha);
        func_003b0e20(entry->fontHandle, packedColor);

        frame = func_0021cca0(brRes00234570(0), 4);
        BR_PANEL_SET_RECT(entry->background, progressShift * 0.5f,
                          233.0f + baseShift + progressShift,
                          (f32)*(s32*)((u8*)frame + 0xc) * scale +
                          secondShift,
                          (f32)*(s32*)((u8*)frame + 0x10) +
                          secondShift * 0.25f);
        BR_PANEL_ANIMATE(entry->background, 0x28);
        BR_PANEL_SET_COLOR(entry->background, alpha);

        frame = func_0021cca0(brRes00234570(0), 1);
        BR_PANEL_SET_RECT(entry->label,
                          373.0f - baseShift + shift + secondShift,
                          221.0f + (f32)i + progressShift * 0.5f,
                          (f32)*(s32*)((u8*)frame + 0xc) * scale,
                          (f32)*(s32*)((u8*)frame + 0x10) +
                          progressShift * 0.25f);
        BR_PANEL_ANIMATE(entry->label, 0x28);
        BR_PANEL_SET_COLOR(entry->label, alpha);

        if (entry->value < 10) {
            rect[0] = 389.5f + shift + secondShift -
                      baseShift * 0.05f;
        } else {
            rect[0] = 370.0f + shift + secondShift -
                      baseShift * 0.05f;
        }
        rect[1] = 221.0f + (f32)i + progressShift * 0.5f;
        brPanel00235ff0(entry->digits, 2, entry->value, 1, rect);
        BR_PANEL_SET_COLOR(entry->digits, alpha);

        if (entry->type == 0) {
            frame = func_0021cca0(brRes00234570(1), 0xa);
        } else {
            frame = func_0021cca0(brRes00234570(1), 0xb);
        }
        rect[0] = 142.0f - baseShift + shift + secondShift;
        rect[1] = 205.0f + baseShift +
                  progressShift * 0.5f;
        rect[2] = (f32)*(s32*)((u8*)frame + 0xc) * scale;
        rect[3] = (f32)*(s32*)((u8*)frame + 0x10) +
                  secondShift * 0.25f;
        BR_PANEL_SET_RECT(entry->typeIcon, rect[0], rect[1], rect[2], rect[3]);
        BR_PANEL_ANIMATE(entry->typeIcon, 0x28);
        BR_PANEL_SET_COLOR(entry->typeIcon, alpha);
    }

    frame = func_0021cca0(brRes00234570(0), 6);
    if ((*(s32*)(work + 0x266c)) == 0) {
        rect[0] = 0.0f;
        rect[1] = 0.0f;
        alpha = 0.0f;
    } else if ((*(s32*)(work + 0x266c)) == 1) {
        alpha = 1.0f;
        if ((*(s32*)(work + 0x2668)) < 5) {
            shift = (f32)(*(s32*)(work + 0x2668)) / 5.0f;
            scale = (f32)*(s32*)((u8*)frame + 0x10);
            baseShift = scale - 12.0f;
            progressShift = 21.0f + baseShift;
            rect[0] = progressShift +
                      shift * (21.0f - progressShift);
            rect[1] = -12.0f - baseShift +
                      shift * (-12.0f - (-12.0f - baseShift));
        } else {
            rect[0] = 21.0f;
            rect[1] = -12.0f;
        }
    } else {
        alpha = 1.0f;
        if ((*(s32*)(work + 0x2668)) < 3) {
            shift = (f32)(*(s32*)(work + 0x2668)) / 3.0f;
            scale = shift * 100.0f;
            rect[0] = 21.0f + scale;
            rect[1] = -12.0f + scale;
            alpha = 1.0f - shift;
        } else {
            rect[0] = 121.0f;
            rect[1] = 88.0f;
            alpha = 0.0f;
        }
    }
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    BR_PANEL_SET_RECT(work + 0x1d60, rect[0], rect[1],
                      rect[2], rect[3]);
    BR_PANEL_SET_COLOR(work + 0x1d60, alpha);

    frame = func_0021cca0(brRes00234570(0), 7);
    if ((*(s32*)(work + 0x266c)) == 0) {
        shift = 0.0f;
        scale = 0.0f;
        alpha = 0.0f;
    } else if ((*(s32*)(work + 0x266c)) == 1) {
        alpha = 1.0f;
        scale = (f32)*(s32*)((u8*)frame + 0x10) + 260.0f;
        if ((*(s32*)(work + 0x2668)) < 3) {
            shift = scale;
            shift2 = -scale;
        } else if ((*(s32*)(work + 0x2668)) < 6) {
            progressShift = (f32)((*(s32*)(work + 0x2668)) - 3) / 3.0f;
            shift = (1.0f - progressShift) * scale;
            shift2 = -(1.0f - progressShift) * scale;
        } else {
            shift = 0.0f;
            shift2 = 0.0f;
        }
    } else {
        if ((*(s32*)(work + 0x2668)) < 3) {
            progressShift = (f32)(*(s32*)(work + 0x2668)) / 3.0f;
            shift = progressShift * 100.0f;
            shift2 = progressShift * 100.0f;
            alpha = 1.0f - progressShift;
        } else {
            shift = 100.0f;
            shift2 = 100.0f;
            alpha = 0.0f;
        }
    }
    if (BR_PANEL_WORD(0) & 8) {
        frame = func_0021cca0(brRes00234570(0), 10);
        rect[0] = 141.0f + shift;
        rect[1] = 1.0f + shift2;
    } else {
        frame = func_0021cca0(brRes00234570(0), 8);
        rect[0] = 158.0f + shift;
        rect[1] = 44.0f + shift2;
    }
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    BR_PANEL_SET_RECT(work + 0x1f60, rect[0], rect[1],
                      rect[2], rect[3]);
    BR_PANEL_SET_COLOR(work + 0x1f60, alpha);

    frame = func_0021cca0(brRes00234570(0), 9);
    BR_PANEL_SET_RECT(work + 0x1e60, 132.0f + shift, 136.0f + shift2,
                      (f32)*(s32*)((u8*)frame + 0xc),
                      (f32)*(s32*)((u8*)frame + 0x10));
    BR_PANEL_SET_COLOR(work + 0x1e60, alpha);

    frame = func_0021cca0(brRes00234570(0), 7);
    BR_PANEL_SET_RECT(work + 0x2160, 34.0f + shift, 180.0f + shift2,
                      (f32)*(s32*)((u8*)frame + 0xc),
                      (f32)*(s32*)((u8*)frame + 0x10));
    BR_PANEL_SET_COLOR(work + 0x2160, alpha);

    frame = func_0021cca0(brRes00234570(0), 9);
    BR_PANEL_SET_RECT(work + 0x2060, 8.0f + shift, 260.0f + shift2,
                      (f32)*(s32*)((u8*)frame + 0xc),
                      (f32)*(s32*)((u8*)frame + 0x10));
    BR_PANEL_SET_COLOR(work + 0x2060, alpha);

    if ((*(s32*)(work + 0x266c)) == 0) {
        rect[0] = 0.0f;
        rect[1] = 0.0f;
        rect[2] = 0.0f;
        rect[3] = 0.0f;
        rect[4] = 0.0f;
        rect[5] = 0.0f;
        rect[6] = 0.0f;
        rect[7] = 0.0f;
        alpha = 0.0f;
    } else if ((*(s32*)(work + 0x266c)) == 1) {
        root2 = sqrtf(2.0f);
        scale = ((*(s32*)(work + 0x2668)) < 8) ? (f32)(*(s32*)(work + 0x2668)) / 8.0f : 1.0f;
        if ((*(s32*)(work + 0x2668)) < 0) {
            scale = 0.0f;
        }
        baseShift = (320.0f / root2) * (1.0f - scale);
        progressShift = (1096.0f * scale) / root2;
        secondShift = 224.0f / root2;
        if ((*(s32*)(work + 0x2668)) < 2) {
            secondShift *= scale;
            progressShift *= scale;
        } else if ((*(s32*)(work + 0x2668)) < 6) {
            shift2 = (f32)((*(s32*)(work + 0x2668)) - 2) / 4.0f;
            secondShift *= 0.5f + shift2 * 0.5f;
            progressShift += secondShift * (1.0f - shift2);
        } else {
            shift2 = 1.0f;
            secondShift *= shift2;
        }
        rect[0] = 320.0f + baseShift;
        rect[1] = -320.0f - baseShift;
        rect[2] = -224.0f - baseShift;
        rect[3] = 224.0f + baseShift;
        shift = progressShift + secondShift;
        rect[4] = rect[2] + shift;
        rect[5] = rect[3] + shift;
        rect[6] = rect[0] + shift;
        rect[7] = rect[1] + shift;
        alpha = 0.5f + scale * 0.5f;
        if ((*(s32*)(work + 0x2668)) < 3) {
            shift2 = (f32)((*(s32*)(work + 0x2668)) + 1) / 3.0f;
            rect[0] += baseShift * (1.0f - shift2);
            rect[1] -= baseShift * (1.0f - shift2);
            rect[2] -= secondShift * (1.0f - shift2);
            rect[3] += secondShift * (1.0f - shift2);
            rect[4] = rect[2] + shift + secondShift * shift2;
            rect[5] = rect[3] + shift + secondShift * shift2;
            rect[6] = rect[0] + shift + secondShift * shift2;
            rect[7] = rect[1] + shift + secondShift * shift2;
        } else if ((*(s32*)(work + 0x2668)) < 7) {
            shift2 = (f32)((*(s32*)(work + 0x2668)) - 2) / 5.0f;
            rect[0] += progressShift * shift2;
            rect[1] += progressShift * shift2;
            rect[2] += progressShift * shift2;
            rect[3] += progressShift * shift2;
            rect[4] += progressShift * shift2;
            rect[5] += progressShift * shift2;
            rect[6] += progressShift * shift2;
            rect[7] += progressShift * shift2;
        }
    } else {
        root2 = sqrtf(2.0f);
        scale = ((*(s32*)(work + 0x2668)) < 10) ? (f32)(*(s32*)(work + 0x2668)) / 10.0f : 1.0f;
        if ((*(s32*)(work + 0x2668)) < 0) {
            scale = 0.0f;
        }
        baseShift = (350.0f / root2 - DAT_007caff0) * scale;
        progressShift = (544.0f - baseShift) * scale;
        secondShift = (40.0f + 283.0f / root2) / root2;
        if ((*(s32*)(work + 0x2668)) < 3) {
            shift2 = (f32)(*(s32*)(work + 0x2668)) / 3.0f;
            progressShift *= shift2;
            secondShift *= shift2;
        } else if ((*(s32*)(work + 0x2668)) < 7) {
            shift2 = (f32)((*(s32*)(work + 0x2668)) - 3) / 4.0f;
            progressShift += secondShift * shift2;
        } else {
            shift2 = 1.0f;
        }
        shift = progressShift - 40.0f / root2;
        rect[0] = 320.0f - 40.0f / root2 + shift;
        rect[1] = -320.0f - 40.0f / root2 + shift;
        rect[2] = -224.0f - 40.0f / root2 + shift;
        rect[3] = 224.0f - 40.0f / root2 + shift;
        rect[4] = rect[2] + secondShift;
        rect[5] = rect[3] + secondShift;
        rect[6] = rect[0] + secondShift;
        rect[7] = rect[1] + secondShift;
        alpha = 1.0f - scale;
    }
    BR_PANEL_SET_VERTICES(work + 0x2260);
    BR_PANEL_ANIMATE(work + 0x2260, 0x32);
    color[0] = 0xe;
    color[1] = 0x8b;
    color[2] = 0xec;
    color[3] = (u8)(u32)(255.0f * alpha);
    func_0021d950(work + 0x2260, color);

    if ((*(s32*)(work + 0x266c)) == 0) {
        rect[0] = 0.0f;
        rect[1] = 0.0f;
        rect[2] = 0.0f;
        rect[3] = 0.0f;
        rect[4] = 0.0f;
        rect[5] = 0.0f;
        rect[6] = 0.0f;
        rect[7] = 0.0f;
        alpha = 0.0f;
    } else if ((*(s32*)(work + 0x266c)) == 1) {
        root2 = sqrtf(2.0f);
        scale = ((*(s32*)(work + 0x2668)) < 10) ? (f32)(*(s32*)(work + 0x2668)) / 10.0f : 1.0f;
        baseShift = (320.0f / root2) * (1.0f - scale);
        progressShift = (1096.0f * scale) / root2;
        secondShift = 224.0f / root2;
        if ((*(s32*)(work + 0x2668)) < 4) {
            shift2 = (f32)(*(s32*)(work + 0x2668)) / 4.0f;
            progressShift *= shift2;
            secondShift *= shift2;
        } else if ((*(s32*)(work + 0x2668)) < 8) {
            shift2 = (f32)((*(s32*)(work + 0x2668)) - 4) / 4.0f;
            baseShift *= 1.0f - shift2;
            progressShift += secondShift * shift2;
        } else {
            shift2 = 1.0f;
        }
        rect[0] = 320.0f + baseShift;
        rect[1] = -320.0f - baseShift;
        rect[2] = -224.0f - baseShift;
        rect[3] = 224.0f + baseShift;
        shift = progressShift + secondShift * 0.5f;
        rect[4] = rect[2] + shift;
        rect[5] = rect[3] + shift;
        rect[6] = rect[0] + shift;
        rect[7] = rect[1] + shift;
        alpha = 0.25f + scale * 0.75f;
    } else {
        root2 = sqrtf(2.0f);
        scale = (f32)(*(s32*)(work + 0x2668)) / 10.0f;
        if ((*(s32*)(work + 0x2668)) < 0) {
            scale = 0.0f;
        } else if ((*(s32*)(work + 0x2668)) >= 10) {
            scale = 0.0f;
        }
        baseShift = (350.0f / root2 - 350.0f) * scale;
        progressShift = (320.0f - 224.0f) * (1.0f - scale);
        secondShift = 224.0f * scale;
        shift = baseShift + progressShift;
        if ((*(s32*)(work + 0x2668)) < 3) {
            shift2 = (f32)(*(s32*)(work + 0x2668)) / 3.0f;
            shift += secondShift * shift2;
        } else if ((*(s32*)(work + 0x2668)) < 7) {
            shift2 = (f32)((*(s32*)(work + 0x2668)) - 3) / 4.0f;
            shift += secondShift * (1.0f - shift2);
        } else {
            shift2 = 1.0f;
        }
        rect[0] = 320.0f + shift;
        rect[1] = -320.0f + shift - progressShift;
        rect[2] = -224.0f + shift - secondShift * 0.5f;
        rect[3] = 224.0f + shift + progressShift;
        rect[4] = rect[0] - secondShift;
        rect[5] = rect[1] - secondShift;
        rect[6] = rect[2] + secondShift;
        rect[7] = rect[3] + secondShift;
        alpha = 1.0f - scale;
    }
    BR_PANEL_SET_VERTICES(work + 0x2360);
    BR_PANEL_ANIMATE(work + 0x2360, 0x23);
    color[0] = 4;
    color[1] = 0x29;
    color[2] = 0x46;
    color[3] = (u8)(u32)(255.0f * alpha);
    func_0021d950(work + 0x2360, color);

    if ((*(s32*)(work + 0x266c)) == 2) {
        root2 = sqrtf(2.0f);
        scale = (f32)(*(s32*)(work + 0x2668)) / 10.0f;
        if ((*(s32*)(work + 0x2668)) < 0) {
            scale = 0.0f;
        } else if ((*(s32*)(work + 0x2668)) >= 10) {
            scale = 0.0f;
        }
        alpha = 1.0f - scale;
        baseShift = (350.0f / root2 - DAT_007caff0) / root2;
        progressShift = scale * (544.0f - baseShift);
        secondShift = (40.0f + 283.0f / root2) / root2;
        shift2 = 40.0f / root2;
        if ((*(s32*)(work + 0x2668)) < 3) {
            shift = (f32)(*(s32*)(work + 0x2668)) / 3.0f;
            progressShift *= shift;
            secondShift *= shift;
        } else if ((*(s32*)(work + 0x2668)) < 7) {
            shift = (f32)((*(s32*)(work + 0x2668)) - 3) / 4.0f;
            baseShift *= 1.0f - shift;
            progressShift += secondShift * shift;
        } else {
            shift = 1.0f;
        }
        rect[0] = 320.0f - shift2 + progressShift;
        rect[1] = -320.0f - shift2 + progressShift;
        rect[2] = -224.0f - shift2 + progressShift;
        rect[3] = 224.0f - shift2 + progressShift;
        rect[4] = rect[2] + secondShift;
        rect[5] = rect[3] + secondShift;
        rect[6] = rect[0] + secondShift;
        rect[7] = rect[1] + secondShift;
    } else if ((*(s32*)(work + 0x266c)) == 1) {
        root2 = sqrtf(2.0f);
        scale = ((*(s32*)(work + 0x2668)) < 8) ? (f32)(*(s32*)(work + 0x2668)) / 8.0f : 1.0f;
        baseShift = 320.0f / root2 * (1.0f - scale);
        progressShift = 283.0f / root2 / root2;
        secondShift = progressShift * scale;
        shift = ((*(s32*)(work + 0x2668)) < 4) ? ((f32)(*(s32*)(work + 0x2668)) / 4.0f) : 1.0f;
        rect[0] = 320.0f + baseShift * shift;
        rect[1] = -320.0f - baseShift * shift;
        rect[2] = -224.0f - baseShift * shift;
        rect[3] = 224.0f + baseShift * shift;
        rect[4] = rect[2] + secondShift;
        rect[5] = rect[3] + secondShift;
        rect[6] = rect[0] + secondShift;
        rect[7] = rect[1] + secondShift;
        alpha = 0.5f + scale * 0.5f;
    } else {
        for (i = 0; i < 8; i++) {
            rect[i] = 0.0f;
        }
        alpha = 0.0f;
    }
    BR_PANEL_SET_VERTICES(work + 0x2460);
    BR_PANEL_ANIMATE(work + 0x2460, 0x23);
    color[0] = 0x4f;
    color[1] = 0xa4;
    color[2] = 0xff;
    color[3] = 0xff;
    func_0021d950(work + 0x2460, color);
}
#undef brRes00234570
#undef BR_PANEL_SET_RECT
#undef BR_PANEL_SET_VERTICES
#undef BR_PANEL_ANIMATE
#undef BR_PANEL_SET_COLOR
#pragma optimization_level 2
