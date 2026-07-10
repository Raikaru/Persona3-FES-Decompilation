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
void func_0021d8e0();
void func_0021d950();
void func_0021eae0();
void func_0021eac0();
void* btlUnitFindFromId();
void func_002806d0();
u32 func_002d20a0();
int sprintf(char*, const char*, ...);
u32 strlen(const char*);
void func_00242840(void* glyphs, s32 capacity, s32 value);

static void biMainSetState(u32 state, u32 value)
{
    D_00960090(state, value);
}

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

// FUN_0023F480 NONMATCHING
void func_0023f480(void* work)
{
    s32 i;

    K_ASSERT(sBiMain == NULL, 0x92);
    for (i = 0; i < BI_SLOT_COUNT; i++) {
        BI_U32(BI_SLOT(work, i), 0) = 0;
    }
    sBiMain = work;
}

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
    u8* slot;

    K_ASSERT(sBiMain != NULL, 0x8a);
    for (i = 0; i < BI_SLOT_COUNT; i++) {
        slot = BI_SLOT(sBiMain, i);
        biMainTickSlot(slot);
        if ((BI_U32(slot, 0) & BI_SLOT_ACTIVE) != 0) {
            /* The retail update refreshes the unit's projected bars and digits. */
            func_0021d8e0(slot + 0x10, slot + 0x100);
            func_0021d950(slot + 0x10, slot + 0x300);
        }
    }
}

// FUN_00241910 NONMATCHING
void func_00241910(void)
{
    s32 i;

    K_ASSERT(sBiMain != NULL, 0x8a);
    biMainSetState(9, 2);
    biMainSetState(0x14, 2);
    biMainSetState(8, 0);
    biMainSetState(6, 0);
    for (i = 0; i < BI_SLOT_COUNT; i++) {
        biMainDrawSlot(BI_SLOT(sBiMain, i));
    }
}

// FUN_00242260 NONMATCHING
void* func_00242260(void)
{
    s32 i;
    u8* slot;

    K_ASSERT(sBiMain != NULL, 0x8a);
    for (i = 0; i < BI_SLOT_COUNT; i++) {
        slot = BI_SLOT(sBiMain, i);
        if ((BI_U32(slot, 0) & BI_SLOT_ACTIVE) == 0) {
            BI_U32(slot, 0) = BI_SLOT_ACTIVE;
            return slot;
        }
    }
    K_ASSERT(0, 0x583);
    return NULL;
}

// FUN_00242320 NONMATCHING
void func_00242320(void* slot, s32 mode)
{
    void* renderContext;
    void* resource;
    s32 i;

    renderContext = func_0021c3f0(1);
    switch (mode) {
    case 0:
        resource = func_0021cca0(renderContext, 0xb);
        func_0021d3b0((u8*)slot + 0x10, resource);
        resource = func_0021cca0(renderContext, 0xa);
        for (i = 0; i < 2; i++) {
            func_0021d3b0((u8*)slot + 0x110 + i * 0x100, resource);
        }
        break;
    case 1:
        resource = func_0021cca0(renderContext, 0x13);
        func_0021d3b0((u8*)slot + 0x10, resource);
        resource = func_0021cca0(renderContext, 0x12);
        for (i = 0; i < 2; i++) {
            func_0021d3b0((u8*)slot + 0x110 + i * 0x100, resource);
        }
        break;
    case 2:
        resource = func_0021cca0(renderContext, 0x1e);
        func_0021d3b0((u8*)slot + 0x10, resource);
        resource = func_0021cca0(renderContext, 0x1d);
        func_0021d3b0((u8*)slot + 0x110, resource);
        resource = func_0021cca0(renderContext, 0x1c);
        func_0021d3b0((u8*)slot + 0x210, resource);
        break;
    case 3:
        resource = func_0021cca0(renderContext, 0x22);
        func_0021d3b0((u8*)slot + 0x10, resource);
        break;
    default:
        break;
    }
    BI_U32(slot, 4) = mode;
    BI_U32(slot, 0) |= BI_SLOT_READY;
}

// FUN_00242540 NONMATCHING
void func_00242540(void* slot)
{
    RwRGBA color;
    RwV2d origin;

    color.r = 0xff;
    color.g = 0;
    color.b = 0;
    color.a = 0xff;
    origin.x = 0.0f;
    origin.y = 0.0f;
    func_0021eae0((u8*)slot + 0xd40, &origin);
    func_0021d950((u8*)slot + 0xd40, &color);
    func_0021eac0((u8*)slot + 0xd40, 0.0f);
    func_0021eae0((u8*)slot + 0xe40, &origin);
    func_0021d950((u8*)slot + 0xe40, &color);
    func_0021eac0((u8*)slot + 0xe40, 0.0f);
    BI_U32(slot, 0x310) = 0;
    BI_U32(slot, 0) |= BI_SLOT_INITIALIZED;
}

// FUN_00242600 NONMATCHING
void func_00242600(void* slot, s32 value)
{
    char digits[6];
    s32 magnitude;

    if (value < 0) {
        BI_U32(slot, 0) |= BI_SLOT_TEXT_0;
        magnitude = -value;
    } else {
        magnitude = value;
    }
    BI_U32(slot, 0x820) = magnitude < 100000 ? magnitude : 99999;
    sprintf(digits, "%d", BI_U32(slot, 0x820));
    K_ASSERT(strlen(digits) > 0, 0x610);
    K_ASSERT(strlen(digits) <= 5, 0x611);
    BI_U32(slot, 0x824) = strlen(digits);
    BI_U32(slot, 0) |= BI_SLOT_NUMERIC_0;
    func_00242840((u8*)slot + 0x320, 5, BI_U32(slot, 0x820));
}

// FUN_00242720 NONMATCHING
void func_00242720(void* slot, s32 value)
{
    char digits[6];
    s32 magnitude;

    if (value < 0) {
        BI_U32(slot, 0) |= BI_SLOT_TEXT_1;
        magnitude = -value;
    } else {
        magnitude = value;
    }
    BI_U32(slot, 0xd30) = magnitude < 100000 ? magnitude : 99999;
    sprintf(digits, "%d", BI_U32(slot, 0xd30));
    K_ASSERT(strlen(digits) > 0, 0x635);
    K_ASSERT(strlen(digits) <= 5, 0x636);
    BI_U32(slot, 0xd34) = strlen(digits);
    BI_U32(slot, 0) |= BI_SLOT_NUMERIC_1;
    func_00242840((u8*)slot + 0x830, 5, BI_U32(slot, 0xd30));
}

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

// FUN_002428F0 NONMATCHING
void func_002428f0(void* glyph, s32 digit)
{
    biMainPrepareDigit(glyph, digit);
}

// FUN_00242950 NONMATCHING
f32 func_00242950(s32 value)
{
    char digits[6];
    s32 length;

    sprintf(digits, "%d", value);
    length = strlen(digits);
    K_ASSERT(length > 0, 0x666);
    K_ASSERT(length <= 5, 0x667);
    return 30.0f * (f32)(length - 1);
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

// FUN_00242A60 NONMATCHING
s32 func_00242a60(void)
{
    s32 i;

    K_ASSERT(sBiMain != NULL, 0x8a);
    for (i = 0; i < BI_SLOT_COUNT; i++) {
        if ((BI_U32(BI_SLOT(sBiMain, i), 0) & BI_SLOT_ACTIVE) == 0) {
            return i;
        }
    }
    return BI_SLOT_COUNT;
}

// FUN_00242AE0 NONMATCHING
s32 func_00242ae0(u32 unitId)
{
    s32 i;
    u8* slot;

    K_ASSERT(sBiMain != NULL, 0x8a);
    for (i = 0; i < BI_SLOT_COUNT; i++) {
        slot = BI_SLOT(sBiMain, i);
        if ((BI_U32(slot, 0) & BI_SLOT_ACTIVE) != 0 && BI_U32(slot, 0x314) == unitId) {
            return i;
        }
    }
    return BI_SLOT_COUNT;
}

// FUN_00242B80 NONMATCHING
u32 func_00242b80(u16 unitId, RwV2d* screenPosition)
{
    void* unit;
    RwV2d projected;

    unit = btlUnitFindFromId(unitId);
    if (unit == NULL) {
        return 0;
    }
    func_002806d0(unit, &projected);
    if (func_002d20a0(&projected, screenPosition) == 0) {
        return 0;
    }
    screenPosition->y += 14.0f;
    return 1;
}

// FUN_00242C20
void func_00242c20(void* slot, u32 leftValue, u32 rightValue)
{
    BI_U32(slot, 0) |= 0x20;
    BI_U32(slot, 0xf44) = leftValue;
    BI_U32(slot, 0xf40) = rightValue;
}
