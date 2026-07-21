#include "Utils.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Result/bp_ifont.h"

/*
 * Battle status/analyze (BSA) owns one large, contiguous panel work area.  The
 * retail code addresses this area as an array of words; keeping that view here
 * makes the offsets explicit and also documents the shared layout used by the
 * panel renderer.
 */
typedef struct BsaWork
{
    u32 words[0x29b0];
} BsaWork;

typedef int (*code)(...);

extern u32 DAT_007ce4e8;
extern u8* DAT_007ce410;
extern code D_00960090;
#pragma alias D_00960090_abs D_00960090
#pragma alias D_0096009C_abs D_0096009C
extern code D_00960090_abs[];
extern code D_0096009C_abs[];
extern code D_0096009C;

extern void* func_001ff430(u32 id);
extern void func_0017b1e0(u16 id);
extern s16 func_0017d2e0(void);
extern u32 func_0010a4e0(s32 a, s32 b, s32 c, s32 d);

extern u32 func_0021c3f0(s32 texture);
extern u32 func_0021cca0(u32 texture, s32 frame);
extern u32 func_0021cce0(u32 frame);
extern void* func_00239140(s32 index);
extern void func_0021d3b0(void* destination, u32 frame);
extern void func_0021d8e0(void* destination, const f32* rect);
extern void func_0021d950(void* destination, const u8* color);
extern void func_0021dd60(void* destination, const u8* color);
extern void func_0021e380(void* destination, u32 frame, s32 mode);
extern void func_0021eac0(void* destination, f32 value);
extern void func_00238980(void* glyphs, s32 capacity, s32 value, s32 style);
u32 bsaMain00215830(u32 type);
void bsaMain00215770(BsaWork* work);

extern u32 func_00306e80(u32 calc, s16 mode);
extern s16 func_003082f0(u32 calc, s16 id);
extern u16* func_00308bb0(u32 calc);
extern u32 func_0030bb40(u16 id);
extern u32 func_003b0970(u32 resource, s32 mode, s32 group, s32 a, s32 b);
extern void func_003b0d70(u32 resource, s32 x, s32 y);
extern void func_003b0e70(s32 mode);
extern void func_003b0e90(s32 mode);
extern void func_003b1360(u32 resource, s32 mode, s32 value);
extern void func_003b0170(u32 resource);
extern void func_003b2c60(u32 resource, f32 value);
extern void func_003b0e20(u32 resource, u32 value);
extern void func_004d7f60(s32 state, u32 value);

#define BSA_FLAG_ACTIVE      0x00000001u
#define BSA_FLAG_RESOURCE    0x00000002u
#define BSA_FLAG_STATUS      0x00000004u
#define BSA_FLAG_PERSONA     0x00000008u
#define BSA_FLAG_AILMENT     0x00000010u
#define BSA_FLAG_TOP_LABEL   0x00000020u
#define BSA_FLAG_TRANSITION  0x00000040u
#define BSA_FLAG_BOSS        0x00000080u

#define BSA_FRAME_W(frame) ((f32)((s32*)(frame))[3])
#define BSA_FRAME_H(frame) ((f32)((s32*)(frame))[4])

static inline u8 bsaAlpha(f32 value)
{
    if (value <= 0.0f)
        return 0;
    if (value >= 255.0f)
        return 0xff;
    return (u8)(s32)value;
}

#define bsaPlaceQuad(work, destination, frame, x, y, width, height, alpha) \
    do { \
        rect[0] = (x); \
        rect[1] = (y); \
        rect[2] = (width) < 0.0f ? BSA_FRAME_W(frame) : (width); \
        rect[3] = (height) < 0.0f ? BSA_FRAME_H(frame) : (height); \
        func_0021d8e0((work) + (destination), rect); \
        drawColor[0] = 0xff; \
        drawColor[1] = 0xff; \
        drawColor[2] = 0xff; \
        drawColor[3] = (alpha); \
        func_0021d950((work) + (destination), drawColor); \
    } while (0)
#define bsaSetColor(destination, alpha) \
    do { \
        drawColor[0] = 0xff; \
        drawColor[1] = 0xff; \
        drawColor[2] = 0xff; \
        drawColor[3] = (alpha); \
        func_0021d950((destination), drawColor); \
    } while (0)




static s32 bsaSkillCategory(u32 flags)
{
    if ((flags & 0x1000000) != 0)
        return 1;
    if ((flags & 0x2000000) != 0)
        return 4;
    if ((flags & 0x4000000) != 0)
        return 3;
    if ((flags & 0x8000000) != 0)
        return 0;
    if ((flags & 0x10000000) != 0)
        return 2;
    return 5;
}

// FUN_0020FE20
void bsaMain0020fe20(BsaWork* work)
{
    work->words[1] = 0;
}

#pragma optimization_level 1
// FUN_0020FE30 NONMATCHING
#define p ((u32*)work)
void bsaMain0020fe30(BsaWork* work, s32 mode, u32 unitId)
{
    void* unit;
    u32 calc;
    u32 table6;
    u32 table1;
    u32 table2;
    u32 image;
    u16* slots;
    s16 categories[9];
    u16 enemyId;
    s16 slotId;
    s32 i;
    s32 count;
    table6 = func_0021c3f0(6);
    table1 = func_0021c3f0(1);
    table2 = func_0021c3f0(2);
    if ((~p[1] & BSA_FLAG_ACTIVE) == 0)
        K_ASSERT(0, 0x91);
    p[1] = BSA_FLAG_ACTIVE;
    p[1] |= BSA_FLAG_TRANSITION;
    p[0] = mode;
    p[0x29ac] = 0;
    p[0x29ad] = 0;
    p[2] = unitId;

    unit = func_001ff430(unitId);
    p[3] = *(u16*)((u8*)*(u32*)((u8*)unit + 0xa2c) + 2);
    p[1] &= ~BSA_FLAG_BOSS;
    if (*(u16*)((u8*)p + 0xc) == 0x126)
        p[1] |= BSA_FLAG_BOSS;

    func_0017b1e0(*(u16*)((u8*)unit + 0xa2c) + 0);
    func_003b0e70(1);
    func_003b0e90(2);
    image = func_003b0970(DAT_007ce4e8 + *(u16*)((u8*)p + 0xc) * 0x3e,
                          2, 6, 0, 0);
    func_003b0e90(1);
    func_003b0e70(2);
    func_003b0e20(image, 0xffffffff);
    func_003b0d70(image, 0xa10, 0x268);
    func_003b2c60(image, 0.0f);
    p[4] = image;

    if ((*(u16*)((u8*)DAT_007ce410 +
                 *(u16*)((u8*)p + 0xc) * 0x3e + 0x1e) & 2) != 0)
        p[1] |= BSA_FLAG_TOP_LABEL;
    if ((*(u16*)((u8*)DAT_007ce410 +
                 *(u16*)((u8*)p + 0xc) * 0x3e + 0x1e) & 0x40) != 0)
        p[1] |= BSA_FLAG_RESOURCE;
    if ((*(u16*)((u8*)DAT_007ce410 +
                 *(u16*)((u8*)p + 0xc) * 0x3e + 0x1e) & 8) != 0)
        p[1] |= BSA_FLAG_STATUS;
    if ((*(u16*)((u8*)DAT_007ce410 +
                 *(u16*)((u8*)p + 0xc) * 0x3e + 0x1e) & 0x10) != 0)
        p[1] |= BSA_FLAG_PERSONA;
    if ((*(u16*)((u8*)DAT_007ce410 +
                 *(u16*)((u8*)p + 0xc) * 0x3e + 0x1e) & 0x20) != 0)
        p[1] |= BSA_FLAG_AILMENT;
    p[0x1310] = DAT_007ce410[*(u16*)((u8*)p + 0xc) * 0x3e + 3];
    p[0x1394] = *(u16*)(DAT_007ce410 + *(u16*)((u8*)p + 0xc) * 0x3e + 4);
    p[0x1498] = *(u16*)(DAT_007ce410 + *(u16*)((u8*)p + 0xc) * 0x3e + 6);

    for (i = 0; i < 9; i++) {
        switch (i) {
        case 0: slotId = 0; break;
        case 1: slotId = 1; break;
        case 2: slotId = 2; break;
        case 3: slotId = 3; break;
        case 4: slotId = 4; break;
        case 5: slotId = 5; break;
        case 6: slotId = 6; break;
        case 7: slotId = 8; break;
        case 8: slotId = 9; break;
        default: slotId = 0; K_ASSERT(0, 0xd9); break;
        }
        p[0x159c + i] = (u32)(s32)bsaSkillCategory(
            func_00306e80(*(u32*)((u8*)unit + 0xa2c), slotId));
    }
    p[0x17e8] = (u32)(s32)func_003082f0(
        *(u32*)((u8*)unit + 0xa2c), 0);
    slots = func_00308bb0(*(u32*)((u8*)unit + 0xa2c));
    count = 0;
    while (count < 8 && slots[count] != 0)
        count++;
    p[0xd] = count;

    p[0x10] = func_0021cca0(table2, 0x1f);
    func_0021d3b0(p + 0x10, p[0x10]);
    p[0x510] = func_0021cca0(table2, 0x28);
    func_0021d3b0(p + 0x510, p[0x510]);
    p[0x550] = func_0021cca0(table2, 0x27);
    func_0021d3b0(p + 0x550, p[0x550]);
    p[0x12d0] = func_0021cca0(table2, 0x20);
    func_0021d3b0(p + 0x12d0, p[0x12d0]);
    p[0x1250] = func_0021cca0(table2, 0x31);
    func_0021d3b0(p + 0x1250, p[0x1250]);
    if ((p[1] & BSA_FLAG_BOSS) == 0 || p[0x17e8] == 7)
        p[0x17ec] = func_0021cca0(table2, 0x3c);
    else
        p[0x17ec] = func_0021cca0(table2, p[0x17e8] + 0x16);
    func_0021d3b0(p + 0x17ec, p[0x17ec]);
    p[0x50] = func_0021cca0(table1, 0x47);
    func_0021d3b0(p + 0x50, p[0x50]);
    p[0x90] = func_0021cca0(table2, 0x30);
    func_0021d3b0(p + 0x90, p[0x90]);
    p[0xd0] = func_0021cca0(table1, 0x48);
    func_0021d3b0(p + 0xd0, p[0xd0]);
    p[0x110] = func_0021cca0(table2, 0x30);
    func_0021d3b0(p + 0x110, p[0x110]);
    p[0x150] = func_0021cca0(table2, 0x21);
    func_0021d3b0(p + 0x150, p[0x150]);
    p[0x190] = func_0021cca0(table2, 0x21);
    func_0021e380(p + 0x190, p[0x190], 0);
    p[0x1d0] = func_0021cca0(table2, 0x24);
    func_0021d3b0(p + 0x1d0, p[0x1d0]);
    p[0x210] = p[0x1d0];
    func_0021e380(p + 0x210, p[0x1d0], 1);
    p[0x250] = func_0021cca0(table2, 0x22);
    func_0021d3b0(p + 0x250, p[0x250]);
    p[0x290] = p[0x250];
    func_0021e380(p + 0x290, p[0x250], 0);
    for (i = 0; i < 9; i++) {
        image = func_0021cca0(table2, 0x26);
        func_0021d3b0(p + i * 0x40 + 0x2d0, image);
    }
    for (i = 0; i < 9; i++) {
        image = func_0021cca0(table2, i + 0x16);
        func_0021d3b0(p + i * 0x40 + 0x610, image);
    }
    for (i = 0; i < 8; i++) {
        image = func_0021cca0(table2, 0x23);
        func_0021d3b0(p + i * 0x80 + 0x850, image);
        func_0021e380(p + i * 0x80 + 0x890, image, 0);
    }
    for (i = 0; i < 8; i++) {
        image = func_0021cca0(table2, 0x25);
        func_0021d3b0(p + i * 0x80 + 0xc50, image);
        func_0021e380(p + i * 0x80 + 0xc90, image, 1);
    }
    for (i = 0; i < 8; i++) {
        if (slots[i] == 0)
            *(s16*)((u8*)p + i * 2 + 0xa6b8) = 0x2b;
        else
            *(s16*)((u8*)p + i * 2 + 0xa6b8) = func_0017d2e0() + 0x20;
        image = func_0021cca0(table6,
                              *(s16*)((u8*)p + i * 2 + 0xa6b8));
        func_0021d3b0(p + i * 0x40 + 0x1050, image);
    }
    p[0x590] = bsaMain00215830(
        DAT_007ce410[*(u16*)((u8*)p + 0xc) * 0x3e + 2]);
    func_0021d3b0(p + 0x590, p[0x590]);
    p[0x5d0] = func_0021cca0(table2, 0x2f);
    func_0021d3b0(p + 0x5d0, p[0x5d0]);

    if ((p[1] & BSA_FLAG_TOP_LABEL) != 0) {
        p[0x182c] = func_0021cca0(table2, 0x32);
        func_0021d3b0(p + 0x182c, p[0x182c]);
        p[0x186c] = func_0021cca0(table2, 0x33);
        func_0021d3b0(p + 0x186c, p[0x186c]);
        func_0021e380(p + 0x18ac, p[0x186c], 1);
        p[0x18ec] = func_0021cca0(table2, 0x36);
        func_0021d3b0(p + 0x18ec, p[0x18ec]);
    } else {
        func_00238980(p + 0x1314, 2, p[0x1310], 1);
    }
    if ((p[1] & BSA_FLAG_STATUS) != 0) {
        p[0x192c] = func_0021cca0(table2, 0x32);
        func_0021d3b0(p + 0x192c, p[0x192c]);
        p[0x196c] = func_0021cca0(table2, 0x34);
        func_0021d3b0(p + 0x196c, p[0x196c]);
        func_0021e380(p + 0x19ac, p[0x196c], 1);
        p[0x19ec] = func_0021cca0(table2, 0x36);
        func_0021d3b0(p + 0x19ec, p[0x19ec]);
    } else {
        func_00238980(p + 0x1398, 4, p[0x1394], 1);
    }
    if ((p[1] & BSA_FLAG_PERSONA) != 0) {
        p[0x1a2c] = func_0021cca0(table2, 0x32);
        func_0021d3b0(p + 0x1a2c, p[0x1a2c]);
        p[0x1a6c] = func_0021cca0(table2, 0x34);
        func_0021d3b0(p + 0x1a6c, p[0x1a6c]);
        func_0021e380(p + 0x1aac, p[0x1a6c], 1);
        p[0x1aec] = func_0021cca0(table2, 0x36);
        func_0021d3b0(p + 0x1aec, p[0x1aec]);
    } else {
        func_00238980(p + 0x149c, 4, p[0x1498], 1);
    }
    if ((p[1] & BSA_FLAG_AILMENT) != 0) {
        p[0x1b2c] = func_0021cca0(table2, 0x32);
        func_0021d3b0(p + 0x1b2c, p[0x1b2c]);
        p[0x1b6c] = func_0021cca0(table2, 0x35);
        func_0021d3b0(p + 0x1b6c, p[0x1b6c]);
        func_0021e380(p + 0x1bac, p[0x1b6c], 1);
        p[0x1bec] = func_0021cca0(table2, 0x36);
        func_0021d3b0(p + 0x1bec, p[0x1bec]);
    } else {
        for (i = 0; i < 9; i++) {
            if (p[0x159c + i] < 5) {
                image = func_0021cca0(table2, p[0x159c + i] + 0x29);
                func_0021d3b0(p + i * 0x40 + 0x15a8, image);
            }
        }
    }
    if (p[0] == 1) {
        if ((p[1] & BSA_FLAG_RESOURCE) != 0) {
            for (i = 0; i < 8; i++) {
                image = func_0021cca0(table2, 0x32);
                func_0021d3b0(p + i * 0x100 + 0x1c2c, image);
                image = func_0021cca0(table2, 0x35);
                func_0021d3b0(p + i * 0x100 + 0x1c6c, image);
                func_0021e380(p + i * 0x100 + 0x1cac, image, 1);
                image = func_0021cca0(table2, 0x36);
                func_0021d3b0(p + i * 0x100 + 0x1cec, image);
            }
        } else {
            func_003b0e70(1);
            func_003b0e90(2);
            for (i = 0; i < (s32)p[0xd]; i++) {
                image = func_003b0970(
                    func_0030bb40(slots[i]), 2, 6, 0, 0);
                func_003b0e20(image, 0xffffffff);
                func_003b0d70(image, ((i / 4) * 0x96 + 0x82) * 0x10,
                              ((i % 4) * 0x19 + 100) * 8);
                func_003b2c60(image, 0.0f);
                p[i + 5] = image;
            }
            func_003b0e90(1);
            func_003b0e70(2);
        }
    }
    func_0021eac0(p + 0x242c, 0.0f);
    func_0021eac0(p + 0x246c, 0.0f);
    func_0021eac0(p + 0x24ac, 0.0f);
    func_0021eac0(p + 0x24ec, 0.0f);
    func_0021eac0(p + 0x252c, 0.0f);
    func_0021eac0(p + 0x256c, 0.0f);
    for (i = 0; i < 8; i++) {
        func_0021eac0(p + i * 0x80 + 0x25ac, 0.0f);
        func_0021eac0(p + i * 0x80 + 0x25ec, 0.0f);
    }
    func_0010a4e0(1, 0, 2, 0x15);
}
#undef p

#pragma optimization_level 2
// FUN_00210D60
void bsaMain00210d60(BsaWork* work)
{
    u32* p;
    p = work->words;
    p[0x29ac] = 0;
    p[0x29ad] = 1;
    p[1] |= BSA_FLAG_TRANSITION;
}
 
static inline void bsaTransition(s32* p, f32* alpha, f32* slide, f32* iconAlpha)
{
    s32 timer;
    timer = ((s32*)p)[0x29ac];
    *slide = 0.0f;
    *iconAlpha = 1.0f;
    if ((p[1] & BSA_FLAG_TRANSITION) == 0)
        return;
    if (((s32*)p)[0x29ad] == 1) {
        if (timer < 10) ((s32*)p)[0x29ac] = ++timer;
        else {
            p[1] &= ~BSA_FLAG_TRANSITION;
            bsaMain00215770((BsaWork*)p);
            p[1] &= ~BSA_FLAG_ACTIVE;
        }
        *alpha = 1.0f - (f32)((s32*)p)[0x29ac] / 10.0f;
    } else {
        if (timer < 10) ((s32*)p)[0x29ac] = ++timer;
        else p[1] &= ~BSA_FLAG_TRANSITION;
        *alpha = (f32)((s32*)p)[0x29ac] / 10.0f;
    }
    if ((p[1] & BSA_FLAG_TRANSITION) == 0) {
        *alpha = ((s32*)p)[0x29ad] == 1 ? 0.0f : 1.0f;
        return;
    }
    if (((s32*)p)[0x29ad] == 1) {
        *iconAlpha = 1.0f - (f32)((s32*)p)[0x29ac] / 10.0f;
    } else if (timer < 4) {
        *iconAlpha = 0.0f;
    } else if (timer < 8) {
        *iconAlpha = (f32)(timer - 4) / 4.0f;
        *slide = (1.0f - *iconAlpha) * -20.0f;
    }
}

// FUN_00210D90 NONMATCHING
void bsaMain00210d90(BsaWork* work)
{
    s32* p;
    u32 table6;
    u32 table1;
    u32 table2;
    u32 image;
    u32 resource;
    f32 alpha;
    f32 slide;
    f32 iconAlpha;
    f32 x;
    f32 y;
    f32 base;
    f32 value;
    s32 i;
    f32 rect[4];
    u8 drawColor[4];
    u8 color;

    p = (s32*)work->words;
    table6 = func_0021c3f0(6);
    table1 = func_0021c3f0(1);
    table2 = func_0021c3f0(2);
    if ((p[1] & BSA_FLAG_ACTIVE) == 0)
        return;

    alpha = 1.0f;
    slide = 0.0f;
    iconAlpha = 1.0f;
    bsaTransition(p, &alpha, &slide, &iconAlpha);
    base = (p[0] == 0) ? 180.0f : 0.0f;
    color = bsaAlpha(alpha * 255.0f);

    image = func_0021cca0(table2, 0x1f);
    rect[0] = 59.0f;
    rect[1] = base + 60.0f;
    rect[2] = BSA_FRAME_W(image);
    rect[3] = BSA_FRAME_H(image);
    func_0021d8e0(p + 0x10, rect);
    drawColor[0] = 0xff;
    drawColor[1] = 0xff;
    drawColor[2] = 0xff;
    drawColor[3] = color;
    func_0021d950(p + 0x10, drawColor);
    image = func_0021cca0(table2, 0x28);
    bsaPlaceQuad(p, 0x510, image, 18.0f, base + 54.0f + slide,
                 -1.0f, -1.0f, bsaAlpha(iconAlpha * 255.0f));

    if ((p[1] & BSA_FLAG_TOP_LABEL) == 0) {
        f32 origin[2];
        origin[0] = p[0x1310] < 10 ? 66.0f : 58.0f;
        origin[1] = base + 62.0f;
        bpIFont00238a50(p + 0x1314, 2, p[0x1310], 1, origin);
        bsaSetColor(p + 0x1314, color);
        bsaSetColor(p + 0x1354, color);
    } else {
        image = func_0021cca0(table2, 0x32);
        bsaPlaceQuad(p, 0x182c, image, 110.0f, base + 58.0f,
                     -1.0f, -1.0f, color);
        image = func_0021cca0(table2, 0x33);
        bsaPlaceQuad(p, 0x186c, image, 106.0f, base + 58.0f,
                     -1.0f, -1.0f, color);
        bsaPlaceQuad(p, 0x18ac, image, 106.0f + BSA_FRAME_W(image),
                     base + 58.0f, 30.0f, -1.0f, color);
        image = func_0021cca0(table2, 0x36);
        bsaPlaceQuad(p, 0x18ec, image, 140.0f, base + 58.0f,
                     -1.0f, -1.0f, color);
    }
    if ((p[1] & BSA_FLAG_STATUS) == 0) {
        f32 origin[2];
        origin[0] = 181.0f;
        origin[1] = base + 113.0f;
        bpIFont00238a50(p + 0x1398, 4, p[0x1394], 1, origin);
        for (i = 0; i < 4; i++) bsaSetColor(p + 0x1398 + i * 0x40, color);
    } else {
        image = func_0021cca0(table2, 0x32);
        bsaPlaceQuad(p, 0x192c, image, 178.0f, base + 109.0f,
                     -1.0f, -1.0f, color);
        image = func_0021cca0(table2, 0x34);
        bsaPlaceQuad(p, 0x196c, image, 167.0f, base + 109.0f,
                     -1.0f, -1.0f, color);
        bsaPlaceQuad(p, 0x19ac, image, 167.0f + BSA_FRAME_W(image),
                     base + 109.0f, 43.0f, -1.0f, color);
        image = func_0021cca0(table2, 0x36);
        bsaPlaceQuad(p, 0x19ec, image, 214.0f, base + 109.0f,
                     -1.0f, -1.0f, color);
    }
    if ((p[1] & BSA_FLAG_PERSONA) == 0) {
        f32 origin[2];
        origin[0] = 181.0f;
        origin[1] = base + 130.0f;
        bpIFont00238a50(p + 0x149c, 4, p[0x1498], 1, origin);
        for (i = 0; i < 4; i++) bsaSetColor(p + 0x149c + i * 0x40, color);
    } else {
        image = func_0021cca0(table2, 0x32);
        bsaPlaceQuad(p, 0x1a2c, image, 178.0f, base + 126.0f,
                     -1.0f, -1.0f, color);
        image = func_0021cca0(table2, 0x34);
        bsaPlaceQuad(p, 0x1a6c, image, 167.0f, base + 126.0f,
                     -1.0f, -1.0f, color);
        bsaPlaceQuad(p, 0x1aac, image, 167.0f + BSA_FRAME_W(image),
                     base + 126.0f, 43.0f, -1.0f, color);
        image = func_0021cca0(table2, 0x36);
        bsaPlaceQuad(p, 0x1aec, image, 214.0f, base + 126.0f,
                     -1.0f, -1.0f, color);
    }


    resource = p[4];
    func_003b0e20(resource, 0xffffff00u | color);
    func_003b0d70(resource, 0xa10, (s32)((base + 77.0f) * 8.0f));
    image = bsaMain00215830(DAT_007ce410[(*(u16*)(p + 3)) * 0x3e + 2]);
    bsaPlaceQuad(p, 0x590, image, 59.0f, base + 78.0f,
                 -1.0f, -1.0f, color);
    image = func_0021cca0(table2, 0x2f);
    bsaPlaceQuad(p, 0x5d0, image, 148.0f, base + 88.0f,
                 -1.0f, -1.0f, color);
    image = func_0021cca0(table1, 0x47);
    bsaPlaceQuad(p, 0x50, image, 59.0f, base + 111.0f,
                 -1.0f, -1.0f, color);
    image = func_0021cca0(table2, 0x30);
    bsaPlaceQuad(p, 0x90, image, 146.0f, base + 112.0f,
                 -1.0f, -1.0f, color);
    image = func_0021cca0(table1, 0x48);
    bsaPlaceQuad(p, 0xd0, image, 59.0f, base + 128.0f,
                 -1.0f, -1.0f, color);
    image = func_0021cca0(table2, 0x30);
    bsaPlaceQuad(p, 0x110, image, 146.0f, base + 129.0f,
                 -1.0f, -1.0f, color);
    image = func_0021cca0(table2, 0x21);
    bsaPlaceQuad(p, 0x150, image, 46.0f, base + 141.0f,
                 -1.0f, -1.0f, color);
    bsaPlaceQuad(p, 0x190, image, 46.0f, base + 53.0f,
                 -1.0f, 88.0f, color);
    image = func_0021cca0(table2, 0x24);
    bsaPlaceQuad(p, 0x1d0, image, 58.0f, base + 141.0f,
                 -1.0f, -1.0f, color);
    bsaPlaceQuad(p, 0x210, image, 58.0f + BSA_FRAME_W(image),
                 base + 141.0f, 318.0f, -1.0f, color);
    image = func_0021cca0(table2, 0x22);
    bsaPlaceQuad(p, 0x250, image, 46.0f, base + 203.0f,
                 -1.0f, -1.0f, color);
    bsaPlaceQuad(p, 0x290, image, 46.0f, base + 158.0f,
                 -1.0f, 45.0f, color);

    for (i = 0; i < 9; i++) {
        image = func_0021cca0(table2, 0x26);
        bsaPlaceQuad(p, i * 0x40 + 0x2d0, image,
                     (f32)i * 37.0f + 53.0f, base + 203.0f,
                     -1.0f, -1.0f, color);
    }
    for (i = 0; i < 9; i++) {
        image = func_0021cca0(table2, i + 0x16);
        bsaPlaceQuad(p, i * 0x40 + 0x610, image,
                     (f32)i * 37.0f + 53.0f, base + 166.0f,
                     -1.0f, -1.0f, color);
    }
    if ((p[1] & BSA_FLAG_AILMENT) == 0) {
        for (i = 0; i < 9; i++) {
            if (p[0x159c + i] != 5) {
                image = func_0021cca0(table2, p[0x159c + i] + 0x29);
                bsaPlaceQuad(p, i * 0x40 + 0x15a8, image,
                             (f32)i * 37.0f + 53.0f, base + 190.0f,
                             -1.0f, -1.0f, color);
            }
        }
    } else {
        image = func_0021cca0(table2, 0x32);
        bsaPlaceQuad(p, 0x1b2c, image, 178.0f, base + 171.0f,
                     -1.0f, -1.0f, color);
        image = func_0021cca0(table2, 0x35);
        bsaPlaceQuad(p, 0x1b6c, image, 137.0f, base + 171.0f,
                     -1.0f, -1.0f, color);
        bsaPlaceQuad(p, 0x1bac, image, 137.0f + BSA_FRAME_W(image),
                     base + 171.0f, 103.0f, -1.0f, color);
        image = func_0021cca0(table2, 0x36);
        bsaPlaceQuad(p, 0x1bec, image, 244.0f, base + 171.0f,
                     -1.0f, -1.0f, color);
    }

    if (p[0] == 1) {
        f32 personaAlpha;
        f32 personaSlide;
        s32 timer;
        timer = (s32)p[0x29ac];
        personaAlpha = 1.0f;
        personaSlide = 0.0f;
        if ((p[1] & BSA_FLAG_TRANSITION) != 0) {
            if (p[0x29ad] == 1) personaAlpha = 1.0f - (f32)timer / 10.0f;
            else if (timer < 2) personaAlpha = 0.0f;
            else if (timer < 6) {
                personaAlpha = (f32)(timer - 2) / 4.0f;
                personaSlide = (1.0f - personaAlpha) * -20.0f;
            }
        }
        value = personaSlide;
        image = func_0021cca0(table2, 0x27);
        bsaPlaceQuad(p, 0x550, image, 18.0f, value + base + 274.0f,
                     -1.0f, -1.0f, bsaAlpha(personaAlpha * 255.0f));
        image = func_0021cca0(table2, 0x20);
        bsaPlaceQuad(p, 0x12d0, image, 46.0f, 227.0f,
                     -1.0f, -1.0f, color);
        image = func_0021cca0(table2, 0x31);
        bsaPlaceQuad(p, 0x1250, image, 82.0f, 227.0f,
                     -1.0f, -1.0f, color);
        if ((p[1] & BSA_FLAG_BOSS) == 0 && p[0x17e8] != 7)
            image = func_0021cca0(table2, p[0x17e8] + 0x16);
        else
            image = func_0021cca0(table2, 0x3c);
        bsaPlaceQuad(p, 0x17ec, image, 50.0f, 233.0f,
                     -1.0f, -1.0f, bsaAlpha(alpha * 255.0f));

        for (i = 0; i < 8; i++) {
            f32 groupX;
            f32 groupY;
            groupX = ((i / 4) == 0 ? 0.0f : 270.0f) + 46.0f;
            groupY = (f32)(i & 3) * 30.0f + 292.0f;
            image = func_0021cca0(table2, 0x23);
            bsaPlaceQuad(p, i * 0x80 + 0x850, image,
                         groupX, groupY, -1.0f, -1.0f, color);
            bsaPlaceQuad(p, i * 0x80 + 0x890, image,
                         groupX, groupY - 17.0f, 17.0f, -1.0f, color);
            image = func_0021cca0(table2, 0x25);
            bsaPlaceQuad(p, i * 0x80 + 0xc50, image,
                         groupX + 58.0f, groupY, -1.0f, -1.0f, color);
            bsaPlaceQuad(p, i * 0x80 + 0xc90, image,
                         groupX + 58.0f, groupY, 236.0f, -1.0f, color);
            if (i < (s32)p[0xd]) {
                image = func_0021cca0(table6,
                                      *(s16*)((u8*)p + i * 2 + 0xa6b8));
                bsaPlaceQuad(p, i * 0x40 + 0x1050, image,
                             ((i / 4) == 0 ? 0.0f : 270.0f) + 54.0f,
                             (f32)(i & 3) * 30.0f + 271.0f,
                             -1.0f, -1.0f, color);
            }
            if ((p[1] & BSA_FLAG_RESOURCE) != 0) {
                image = func_0021cca0(table2, 0x32);
                bsaPlaceQuad(p, i * 0x100 + 0x1c2c, image,
                             groupX + 142.0f, groupY - 14.0f,
                             -1.0f, -1.0f, color);
                image = func_0021cca0(table2, 0x35);
                bsaPlaceQuad(p, i * 0x100 + 0x1c6c, image,
                             groupX + 101.0f, groupY - 14.0f,
                             -1.0f, -1.0f, color);
                bsaPlaceQuad(p, i * 0x100 + 0x1cac, image,
                             groupX + 101.0f + BSA_FRAME_W(image), groupY - 14.0f,
                             103.0f, -1.0f, color);
                image = func_0021cca0(table2, 0x36);
                bsaPlaceQuad(p, i * 0x100 + 0x1cec, image,
                             groupX + 208.0f, groupY - 14.0f,
                             -1.0f, -1.0f, color);
            } else if (i < (s32)p[0xd]) {
                func_003b0d70(p[i + 5], (s32)((groupX + 89.0f) * 16.0f),
                              (s32)((groupY - 18.0f) * 8.0f));
                func_003b0e20(p[i + 5], 0xffffff00u | color);
            }
        }
    }

    if (p[0] == 1) {
        rect[0] = -1.0f; rect[1] = 39.0f; rect[2] = 51.0f; rect[3] = 370.0f;
        func_0021d8e0(p + 0x242c, rect);
        rect[0] = 50.0f; rect[1] = 39.0f; rect[2] = 500.0f; rect[3] = 370.0f;
        func_0021d8e0(p + 0x246c, rect);
    } else {
        rect[0] = -1.0f; rect[1] = 219.0f; rect[2] = 51.0f; rect[3] = 190.0f;
        func_0021d8e0(p + 0x242c, rect);
        rect[0] = 50.0f; rect[1] = 219.0f; rect[2] = 500.0f; rect[3] = 190.0f;
        func_0021d8e0(p + 0x246c, rect);
    }
    x = base + 54.0f;
    bsaPlaceQuad(p, 0x24ac, 0, 53.0f, x, 220.0f, 97.0f, 0xff);
    bsaPlaceQuad(p, 0x24ec, 0, 273.0f, x, 120.0f, 97.0f, 0xff);
    y = base + 158.0f;
    bsaPlaceQuad(p, 0x252c, 0, 53.0f, y, 220.0f, 54.0f, 0xff);
    bsaPlaceQuad(p, 0x256c, 0, 273.0f, y, 130.0f, 54.0f, 0xff);
    for (i = 0; i < 8; i++) {
        f32 groupX;
        f32 groupY;
        groupX = ((i / 4) == 0 ? 0.0f : 270.0f) + 53.0f;
        groupY = (f32)(i & 3) * 30.0f + 275.0f;
        bsaPlaceQuad(p, i * 0x80 + 0x25ac, 0, groupX, groupY,
                     118.0f, 26.0f, 0xff);
        bsaPlaceQuad(p, i * 0x80 + 0x25ec, 0, groupX + 118.0f,
                     groupY, 200.0f, 26.0f, 0xff);
    }
    {
        drawColor[0] = 0x1e; drawColor[1] = 0x1e; drawColor[2] = 0x1e;
        drawColor[3] = bsaAlpha(alpha * 255.0f);
        func_0021d950(p + 0x242c, drawColor);
        func_0021dd60(p + 0x246c, drawColor);
        drawColor[0] = 0x22; drawColor[1] = 0x21; drawColor[2] = 0x1f;
        drawColor[3] = bsaAlpha(alpha * 204.0f);
        func_0021d950(p + 0x24ac, drawColor);
        func_0021dd60(p + 0x24ec, drawColor);
        func_0021d950(p + 0x252c, drawColor);
        func_0021dd60(p + 0x256c, drawColor);
        for (i = 0; i < 8; i++) {
            func_0021d950(p + i * 0x80 + 0x25ac, drawColor);
            func_0021dd60(p + i * 0x80 + 0x25ec, drawColor);
        }
    }
}

// FUN_00213E80 NONMATCHING
void bsaMain00213e80(BsaWork* work)
{
    u32* p;
    u32 table6;
    u32 table1;
    u32 table2;
    u32 image;
    s32 i;
    code renderState;
    code renderQuad;

    p = work->words;
    table6 = func_0021c3f0(6);
    table1 = func_0021c3f0(1);
    table2 = func_0021c3f0(2);
    if ((~p[1] & BSA_FLAG_ACTIVE) == 0) {
        renderState = D_00960090;
        #define D_00960090_abs renderState
        renderState(1, 0);
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        D_00960090_abs(8, 0);
        D_00960090_abs(6, 0);
        D_00960090_abs(1, 0);
        renderQuad = D_0096009C;
        #define D_0096009C_abs renderQuad
        D_0096009C_abs(p + 0x242c, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x246c, 4, 0, 2, 3);
        D_0096009C_abs(p + 0x24ac, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x24ec, 4, 0, 2, 3);
        D_0096009C_abs(p + 0x252c, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x256c, 4, 0, 2, 3);
        if (p[0] == 1) {
            for (i = 0; i < 8; i++) {
                D_0096009C_abs(p + i * 0x80 + 0x25ac, 4, 0, 1, 2);
                D_0096009C_abs(p + i * 0x80 + 0x25ac, 4, 0, 2, 3);
                D_0096009C_abs(p + i * 0x80 + 0x25ec, 4, 0, 1, 2);
                D_0096009C_abs(p + i * 0x80 + 0x25ec, 4, 0, 2, 3);
            }
        }
    }
    image = func_0021cce0(func_0021cca0(table2, 0x1f));
    D_00960090_abs(1, image);
    D_0096009C_abs(p + 0x10, 4, 0, 1, 2);
    D_0096009C_abs(p + 0x10, 4, 0, 2, 3);
    image = func_0021cce0(func_0021cca0(table2, 0x28));
    D_00960090_abs(1, image);
    D_0096009C_abs(p + 0x510, 4, 0, 1, 2);
    D_0096009C_abs(p + 0x510, 4, 0, 2, 3);
    image = func_0021cce0(func_0021cca0(table1, 0x47));
    D_00960090_abs(1, image);
    D_0096009C_abs(p + 0x50, 4, 0, 1, 2);
    D_0096009C_abs(p + 0x50, 4, 0, 2, 3);
    image = func_0021cce0(func_0021cca0(table2, 0x30));
    D_00960090_abs(1, image);
    D_0096009C_abs(p + 0x90, 4, 0, 1, 2);
    D_0096009C_abs(p + 0x90, 4, 0, 2, 3);
    image = func_0021cce0(func_0021cca0(table1, 0x48));
    D_00960090_abs(1, image);
    D_0096009C_abs(p + 0xd0, 4, 0, 1, 2);
    D_0096009C_abs(p + 0xd0, 4, 0, 2, 3);
    image = func_0021cce0(func_0021cca0(table2, 0x30));
    D_00960090_abs(1, image);
    D_0096009C_abs(p + 0x110, 4, 0, 1, 2);
    D_0096009C_abs(p + 0x110, 4, 0, 2, 3);
    image = func_0021cce0(func_0021cca0(table2, 0x21));
    D_00960090_abs(1, image);
    D_0096009C_abs(p + 0x150, 4, 0, 1, 2);
    D_0096009C_abs(p + 0x150, 4, 0, 2, 3);
    D_0096009C_abs(p + 0x190, 4, 0, 1, 2);
    D_0096009C_abs(p + 0x190, 4, 0, 2, 3);
    image = func_0021cce0(func_0021cca0(table2, 0x24));
    D_00960090_abs(1, image);
    D_0096009C_abs(p + 0x1d0, 4, 0, 1, 2);
    D_0096009C_abs(p + 0x1d0, 4, 0, 2, 3);
    D_0096009C_abs(p + 0x210, 4, 0, 1, 2);
    D_0096009C_abs(p + 0x210, 4, 0, 2, 3);
    image = func_0021cce0(func_0021cca0(table2, 0x22));
    D_00960090_abs(1, image);
    D_0096009C_abs(p + 0x250, 4, 0, 1, 2);
    D_0096009C_abs(p + 0x250, 4, 0, 2, 3);
    D_0096009C_abs(p + 0x290, 4, 0, 1, 2);
    D_0096009C_abs(p + 0x290, 4, 0, 2, 3);
    image = func_0021cce0(func_0021cca0(table2, 0x26));
    D_00960090_abs(1, image);
    for (i = 0; i < 9; i++) {
        D_0096009C_abs(p + i * 0x40 + 0x2d0, 4, 0, 1, 2);
        D_0096009C_abs(p + i * 0x40 + 0x2d0, 4, 0, 2, 3);
    }
    if ((p[1] & BSA_FLAG_AILMENT) != 0) {
        image = func_0021cce0(func_0021cca0(table2, 0x32));
        D_00960090_abs(1, image);
        D_0096009C_abs(p + 0x1b2c, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x1b2c, 4, 0, 2, 3);
        D_0096009C_abs(p + 0x1b6c, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x1b6c, 4, 0, 2, 3);
        D_0096009C_abs(p + 0x1bac, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x1bac, 4, 0, 2, 3);
        D_0096009C_abs(p + 0x1bec, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x1bec, 4, 0, 2, 3);
    } else {
        for (i = 0; i < 9; i++) {
            image = func_0021cce0(func_0021cca0(table2, i + 0x16));
            D_00960090_abs(1, image);
            D_0096009C_abs(p + i * 0x40 + 0x610, 4, 0, 1, 2);
            D_0096009C_abs(p + i * 0x40 + 0x610, 4, 0, 2, 3);
        }
        for (i = 0; i < 9; i++) {
            if (p[0x159c + i] != 5) {
                image = func_0021cce0(func_0021cca0(table2, p[0x159c + i] + 0x29));
                D_00960090_abs(1, image);
                D_0096009C_abs(p + i * 0x40 + 0x15a8, 4, 0, 1, 2);
                D_0096009C_abs(p + i * 0x40 + 0x15a8, 4, 0, 2, 3);
            }
        }
    }
    if ((p[1] & BSA_FLAG_TOP_LABEL) != 0) {
        image = func_0021cce0(func_0021cca0(table2, 0x32));
        D_00960090_abs(1, image);
        D_0096009C_abs(p + 0x182c, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x182c, 4, 0, 2, 3);
        image = func_0021cce0(func_0021cca0(table2, 0x33));
        D_00960090_abs(1, image);
        D_0096009C_abs(p + 0x186c, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x186c, 4, 0, 2, 3);
        D_0096009C_abs(p + 0x18ac, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x18ac, 4, 0, 2, 3);
        image = func_0021cce0(func_0021cca0(table2, 0x36));
        D_00960090_abs(1, image);
        D_0096009C_abs(p + 0x18ec, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x18ec, 4, 0, 2, 3);
    } else {
        image = (u32)func_00239140(1);
        D_00960090_abs(1, image);
        for (i = 0; i < 2; i++) {
            D_0096009C_abs(p + i * 0x40 + 0x1314, 4, 0, 1, 2);
            D_0096009C_abs(p + i * 0x40 + 0x1314, 4, 0, 2, 3);
        }
    }
    if ((p[1] & BSA_FLAG_STATUS) != 0) {
        image = func_0021cce0(func_0021cca0(table2, 0x32));
        D_00960090_abs(1, image);
        D_0096009C_abs(p + 0x192c, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x192c, 4, 0, 2, 3);
        image = func_0021cce0(func_0021cca0(table2, 0x34));
        D_00960090_abs(1, image);
        D_0096009C_abs(p + 0x196c, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x196c, 4, 0, 2, 3);
        D_0096009C_abs(p + 0x19ac, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x19ac, 4, 0, 2, 3);
        image = func_0021cce0(func_0021cca0(table2, 0x36));
        D_00960090_abs(1, image);
        D_0096009C_abs(p + 0x19ec, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x19ec, 4, 0, 2, 3);
    } else {
        image = (u32)func_00239140(1);
        D_00960090_abs(1, image);
        for (i = 0; i < 4; i++) {
            D_0096009C_abs(p + i * 0x40 + 0x1398, 4, 0, 1, 2);
            D_0096009C_abs(p + i * 0x40 + 0x1398, 4, 0, 2, 3);
        }
    }
    if ((p[1] & BSA_FLAG_PERSONA) != 0) {
        image = func_0021cce0(func_0021cca0(table2, 0x32));
        D_00960090_abs(1, image);
        D_0096009C_abs(p + 0x1a2c, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x1a2c, 4, 0, 2, 3);
        image = func_0021cce0(func_0021cca0(table2, 0x34));
        D_00960090_abs(1, image);
        D_0096009C_abs(p + 0x1a6c, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x1a6c, 4, 0, 2, 3);
        D_0096009C_abs(p + 0x1aac, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x1aac, 4, 0, 2, 3);
        image = func_0021cce0(func_0021cca0(table2, 0x36));
        D_00960090_abs(1, image);
        D_0096009C_abs(p + 0x1aec, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x1aec, 4, 0, 2, 3);
    } else {
        image = (u32)func_00239140(1);
        D_00960090_abs(1, image);
        for (i = 0; i < 4; i++) {
            D_0096009C_abs(p + i * 0x40 + 0x149c, 4, 0, 1, 2);
            D_0096009C_abs(p + i * 0x40 + 0x149c, 4, 0, 2, 3);
        }
    }
    image = func_0021cce0(func_0021cca0(table2, 0x2f));
    D_00960090_abs(1, image);
    D_0096009C_abs(p + 0x5d0, 4, 0, 1, 2);
    D_0096009C_abs(p + 0x5d0, 4, 0, 2, 3);
    D_00960090_abs(1, func_0021cce0(p[0x590]));
    D_0096009C_abs(p + 0x590, 4, 0, 1, 2);
    D_0096009C_abs(p + 0x590, 4, 0, 2, 3);
    func_003b1360(p[4], 1, 0);
    if (p[0] == 1) {
        image = func_0021cce0(func_0021cca0(table2, 0x27));
        D_00960090_abs(1, image);
        D_0096009C_abs(p + 0x550, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x550, 4, 0, 2, 3);
        image = func_0021cce0(func_0021cca0(table2, 0x20));
        D_00960090_abs(1, image);
        D_0096009C_abs(p + 0x12d0, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x12d0, 4, 0, 2, 3);
        image = func_0021cce0(func_0021cca0(table2, 0x31));
        D_00960090_abs(1, image);
        D_0096009C_abs(p + 0x1250, 4, 0, 1, 2);
        D_0096009C_abs(p + 0x1250, 4, 0, 2, 3);
        if ((p[1] & BSA_FLAG_RESOURCE) != 0) {
            image = func_0021cce0(func_0021cca0(table2, 0x23));
            D_00960090_abs(1, image);
            for (i = 0; i < 8; i++) {
                D_0096009C_abs(p + i * 0x80 + 0x850, 4, 0, 1, 2);
                D_0096009C_abs(p + i * 0x80 + 0x850, 4, 0, 2, 3);
                D_0096009C_abs(p + i * 0x80 + 0x890, 4, 0, 1, 2);
                D_0096009C_abs(p + i * 0x80 + 0x890, 4, 0, 2, 3);
            }
            image = func_0021cce0(func_0021cca0(table2, 0x25));
            D_00960090_abs(1, image);
            for (i = 0; i < 8; i++) {
                D_0096009C_abs(p + i * 0x80 + 0xc50, 4, 0, 1, 2);
                D_0096009C_abs(p + i * 0x80 + 0xc50, 4, 0, 2, 3);
                D_0096009C_abs(p + i * 0x80 + 0xc90, 4, 0, 1, 2);
                D_0096009C_abs(p + i * 0x80 + 0xc90, 4, 0, 2, 3);
            }
            image = func_0021cce0(func_0021cca0(table2, 0x32));
            D_00960090_abs(1, image);
            for (i = 0; i < 8; i++) {
                D_0096009C_abs(p + i * 0x100 + 0x1c2c, 4, 0, 1, 2);
                D_0096009C_abs(p + i * 0x100 + 0x1c2c, 4, 0, 2, 3);
            }
            image = func_0021cce0(func_0021cca0(table2, 0x35));
            D_00960090_abs(1, image);
            for (i = 0; i < 8; i++) {
                D_0096009C_abs(p + i * 0x100 + 0x1c6c, 4, 0, 1, 2);
                D_0096009C_abs(p + i * 0x100 + 0x1c6c, 4, 0, 2, 3);
                D_0096009C_abs(p + i * 0x100 + 0x1cac, 4, 0, 1, 2);
                D_0096009C_abs(p + i * 0x100 + 0x1cac, 4, 0, 2, 3);
            }
            image = func_0021cce0(func_0021cca0(table2, 0x36));
            D_00960090_abs(1, image);
            for (i = 0; i < 8; i++) {
                D_0096009C_abs(p + i * 0x100 + 0x1cec, 4, 0, 1, 2);
                D_0096009C_abs(p + i * 0x100 + 0x1cec, 4, 0, 2, 3);
            }
        }
        else {
            for (i = 0; i < (s32)p[0xd]; i++) {
                image = func_0021cce0(func_0021cca0(
                    table6, *(s16*)((u8*)p + i * 2 + 0xa6b8)));
                D_00960090_abs(1, image);
                D_0096009C_abs(p + i * 0x40 + 0x1050, 4, 0, 1, 2);
                D_0096009C_abs(p + i * 0x40 + 0x1050, 4, 0, 2, 3);
            }
            for (i = 0; i < (s32)p[0xd]; i++)
                func_003b1360(p[i + 5], 1, 0);
        }
    }
}
#undef D_00960090_abs
#undef D_0096009C_abs

// FUN_00215770
void bsaMain00215770(BsaWork* work)
{
    u32* p;
    s32 i;
    p = work->words;
    if ((~p[1] & BSA_FLAG_ACTIVE) != 0)
        return;

    func_003b0170(p[4]);
    switch (p[0]) {
    case 0:
        break;
    case 1:
        if ((~p[1] & BSA_FLAG_RESOURCE) != 0) {
            for (i = 0; i < (s32)p[0xd]; i++)
                func_003b0170(*(u32*)((u8*)p + i * 4 + 0x14));
        }
        break;
    }
}

// FUN_00215830
u32 bsaMain00215830(u32 type)
{
    u32 table;
    u32 frame;

    table = func_0021c3f0(2);
    switch (type) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7:
    case 8: case 9: case 10: case 0xb: case 0xc: case 0xd: case 0xe:
    case 0xf: case 0x10: case 0x11: case 0x12: case 0x13: case 0x14:
    case 0x15: case 0x16:
        switch (type) {
        case 1:
            frame = 0xa;
            break;
        case 2:
            frame = 0xb;
            break;
        case 3:
            frame = 0xc;
            break;
        case 4:
            frame = 0xd;
            break;
        case 5:
            frame = 0xe;
            break;
        case 6:
            frame = 0xf;
            break;
        case 7:
            frame = 0x10;
            break;
        case 8:
            frame = 0x11;
            break;
        case 9:
            frame = 0x12;
            break;
        case 10:
            frame = 0x13;
            break;
        case 0xb:
            frame = 0x14;
            break;
        case 0xc:
            frame = 0x15;
            break;
        case 0xd:
            frame = 0;
            break;
        case 0xe:
            frame = 1;
            break;
        case 0xf:
            frame = 2;
            break;
        case 0x10:
            frame = 3;
            break;
        case 0x11:
            frame = 4;
            break;
        case 0x12:
            frame = 5;
            break;
        case 0x13:
            frame = 6;
            break;
        case 0x14:
            frame = 7;
            break;
        case 0x15:
            frame = 8;
            break;
        case 0x16:
            frame = 9;
            break;
        default:
            K_ASSERT(0, 0x76d);
            break;
        }
        return func_0021cca0(table, frame);
    case 0x17:
        return func_0021cca0(table, 0x3b);
    default:
        K_ASSERT(0, 0x778);
        return 0;
    }
}

// FUN_00215A30
u32 bsaMain00215a30(BsaWork* work)
{
    return work->words[1] & BSA_FLAG_ACTIVE;
}

// FUN_00215A40
u32 bsaMain00215a40(BsaWork* work)
{
    return work->words[1] & BSA_FLAG_TRANSITION;
}
