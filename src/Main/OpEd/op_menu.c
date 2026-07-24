#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/OpEd/op_res.h"

extern void func_0021eae0(void* destination, const f32* layout);
extern void func_0021eac0(s32 mode, void* destination);
extern void func_0021d8e0(void* destination, const f32* layout);
extern void func_0021d890(void* destination, const f32* layout);
extern void func_0021d950(void* destination, const u8* color);
extern void func_0021d3b0(void* destination, void* source);
extern void* func_0021cca0(void* resource, u32 index);
extern u32 func_0021cce0(void* frame);
extern void func_004d7f60(s32 state, u32 value);
typedef void (*OpMenuSetState)(u32 state, u32 value);
typedef void (*OpMenuDraw)(void* quad, u32 layer, u32 group, u32 pass, u32 blend);
typedef void (*OpMenuDrawWords)(u32* quad, u32 layer, u32 group, u32 pass, u32 blend);
extern u32 D_00960090[];
typedef void (*OpMenuSetFrame)(u32 state, u32 value);
#pragma alias opMenuStatePtr D_00960090
extern u8 opMenuStatePtr[];
#pragma alias opMenuDrawPtr D_0096009C
extern u8 opMenuDrawPtr[];
extern u32 D_0096009C[];
extern f32 func_0052e878(f32 value);
extern f32 func_0052e6d8(f32 value);
extern void* func_00198590(void);
#pragma alias opResGetTitleRasterU32 opResGetTitleRaster
extern u32 opResGetTitleRasterU32(u32 id);
extern f32 fGpffff8248;
extern f32 fGpffff80c0;
extern f32 fGpffff82fc;
extern f32 fGpffff819c;
extern f32 fGpffff8478;
extern f32 fGpffff847c;
extern f32 fGpffff8480;
extern f32 fGpffff809c;
extern f32 fGpffff83a4;

static u32* sOpMenu; // DAT_007ce3b4 / puGpffffb6c4
static inline u8* opMenuData(u32 offset)
{
    return (u8*)sOpMenu + offset;
}

static inline u32 opMenuGet(u32 offset)
{
    return *(u32*)opMenuData(offset);
}
static inline u32 opMenuGetW(u32* work, u32 offset)
{
    return *(u32*)((u8*)work + offset);
}

static inline s32 opMenuGetSW(u32* work, u32 offset)
{
    return *(s32*)((u8*)work + offset);
}

static inline void opMenuPutW(u32* work, u32 offset, u32 value)
{
    *(u32*)((u8*)work + offset) = value;
}

static inline s32 opMenuGetS(u32 offset)
{
    return *(s32*)opMenuData(offset);
}

static inline void opMenuPut(u32 offset, u32 value)
{
    *(u32*)opMenuData(offset) = value;
}

static inline void opMenuColor(void* quad, f32 alpha)
{
    u8 color[4];
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)alpha;
    func_0021d950(quad, color);
}

static inline f32 opMenuClamp01(s32 value, s32 begin, s32 end)
{
    if (value <= begin)
        return 0.0f;
    if (value >= end)
        return 1.0f;
    return (f32)(value - begin) / (f32)(end - begin);
}

static void opMenuSetRect(u32 offset, f32 x, f32 y, f32 width, f32 height)
{
    f32 rect[4];
    rect[0] = x;
    rect[1] = y;
    rect[2] = width;
    rect[3] = height;
    func_0021d8e0(opMenuData(offset), rect);
}

static void opMenuSetPoly(u32 offset, f32 x, f32 y, f32 width, f32 height,
                          f32 angle, f32 scaleX, f32 scaleY)
{
    f32 poly[8];
    f32 centerX = width * 0.5f;
    f32 centerY = height * 0.5f;
    s32 i;

    poly[0] = -centerX;
    poly[1] = -centerY;
    poly[2] = centerX;
    poly[3] = -centerY;
    poly[4] = centerX;
    poly[5] = centerY;
    poly[6] = -centerX;
    poly[7] = centerY;
    for (i = 0; i < 4; i++)
    {
        f32 sineX = func_0052e878(angle);
        f32 py = poly[i * 2 + 1] * scaleY;
        f32 cosineX = func_0052e6d8(angle);
        f32 px = poly[i * 2] * scaleX;
        f32 outX = px * cosineX - py * sineX + x + centerX;
        f32 sineY = func_0052e878(angle);
        f32 px2 = poly[i * 2] * scaleX;
        f32 cosineY = func_0052e6d8(angle);
        f32 outY = px2 * sineY + py * cosineY + y + centerY;
        poly[i * 2] = outX;
        poly[i * 2 + 1] = outY;
    }
    func_0021d890(opMenuData(offset), poly);
}

static void opMenuSetIcon(u32 offset, void* frame, f32 x, f32 y)
{
    f32 rect[4];
    rect[0] = x;
    rect[1] = y;
    rect[2] = (f32)*(s32*)((u8*)frame + 0x0c);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    func_0021d8e0(opMenuData(offset), rect);
}


// FUN_0026DA90
void opMenu0026da90(s32 param_1)
{
    u32* base;

    K_ASSERT(sOpMenu != NULL, 0x87);
    base = sOpMenu;
    base[param_1 * 0xc4 + 0x2c0] = 8;
    base[base[0x2be] * 0xc4 + 0x2c1] = 0;
    base[0x2be] = param_1;
    base[param_1 * 0xc4 + 0x2c0] = 0;
    base[param_1 * 0xc4 + 0x2c1] = 0;
}

// FUN_0026DB30
void opMenu0026db30(s32 param_1)
{
    u32* base;

    K_ASSERT(sOpMenu != NULL, 0x87);
    base = sOpMenu;
    base[param_1 * 0xc4 + 0x698] = 8;
    base[base[0x694] * 0xc4 + 0x699] = 0;
    base[0x694] = param_1;
    base[param_1 * 0xc4 + 0x698] = 0;
    base[param_1 * 0xc4 + 0x699] = 0;
}
// FUN_0026DC20
void opMenu0026dc20(void)
{
    K_ASSERT(sOpMenu != NULL, 0x87);
    *sOpMenu &= ~0x20u;
}

// FUN_0026a230
void opMenu0026a230(u32* param_1)
{
    K_ASSERT(sOpMenu == NULL, 0x8e);
    *param_1 = 0;
    sOpMenu = param_1;
}

// FUN_0026a280
void opMenu0026a280(void)
{
    K_ASSERT(sOpMenu != NULL, 0x87);
    sOpMenu = NULL;
}

// FUN_0026da10
void opMenu0026da10(void)
{
    u32* work;

    K_ASSERT(sOpMenu != NULL, 0x87);
    work = sOpMenu;
    opMenu0026da90(0);
    opMenu0026db30(0);
    opMenu0026dc20();
    *work &= 0xfffffffe;
}

// FUN_0026dc70
void opMenu0026dc70(void)
{
    u32* work;

    K_ASSERT(sOpMenu != NULL, 0x87);
    work = sOpMenu;
    work[0x247] = 0;
    *work |= 4;
}

// FUN_0026dcc0
u32 opMenu0026dcc0(void)
{
    K_ASSERT(sOpMenu != NULL, 0x87);
    return *sOpMenu & 8;
}

// FUN_0026dbd0
void opMenu0026dbd0(void)
{
    K_ASSERT(sOpMenu != NULL, 0x87);
    *sOpMenu |= 0x20;
}

#pragma opt_loop_invariants on
// FUN_0026A2C0 NONMATCHING
void opMenu0026a2c0(void)
{
    u32* work;
    void* sprite;
    void* frame;
    f32 alpha;
    f32 fade;
    f32 angle;
    f32 pulse;
    f32 scale;
    f32 rect[8];
    u8 color[4];
    s32 i;
    s32 count;
    u32 base;

    K_ASSERT(sOpMenu != NULL, 0x87);
    work = sOpMenu;
    sprite = opResGetTitleSprite(0);
    if ((work[0] & 1) == 0)
        return;

    work[0x910 / 4] = (work[0x910 / 4] + 1) % 0x514;
    work[0x914 / 4] = (work[0x914 / 4] + 1) % 500;
    work[0x918 / 4] = (work[0x918 / 4] + 1) % 0x96;
    work[0xae4 / 4] = (work[0xae4 / 4] + 1) % 0x96;
    work[0xae0 / 4] = (work[0xae0 / 4] + 1) % 0x50;
    work[0xae8 / 4] = (work[0xae8 / 4] + 1) % 0x96;
    work[0xaf0 / 4] = (work[0xaf0 / 4] + 1) % 0x96;
    work[0xaec / 4] = (work[0xaec / 4] + 1) % 0x96;

    if (*(s32*)((u8*)work + 0xaf4) < 0x28)
        work[0xaf4 / 4] = work[0xaf4 / 4] + 1;
    else
        work[0] &= ~8u;
    if ((work[0] & 4) != 0)
    {
        if (*(s32*)((u8*)work + 0x91c) < 0x50)
            work[0x91c / 4] = work[0x91c / 4] + 1;
        else
            work[0] &= ~4u;
    }

    count = (work[0] & 0x20) != 0 ? 4 : 2;
    base = count == 4 ? 0xb00 : 0x1a60;
    for (i = 0; i < count; i++)
    {
        u8* slot = (u8*)work + base + (u32)i * 0x310;
        if (*(s32*)slot < 8)
            *(u32*)slot = *(u32*)slot + 1;
        if ((u32)i != (count == 4 ? work[0xaf8 / 4] : work[0x1a50 / 4]) &&
            *(s32*)(slot + 4) < 0x10)
            *(u32*)(slot + 4) = *(u32*)(slot + 4) + 1;
    }
    if (count == 4 && *(s32*)((u8*)work + 0x1740) < 8)
        work[0x1740 / 4] = work[0x1740 / 4] + 1;

    fade = (f32)*(s32*)((u8*)work + 0x91c);
    alpha = opMenuClamp01((s32)fade, 0, 0x46);
    opMenuSetRect(0x10, 0.0f, 0.0f, 640.0f, 448.0f);
    opMenuColor((u8*)work + 0x10, alpha * 255.0f);

    pulse = func_0052e878(fGpffff8248 *
                          ((f32)*(s32*)((u8*)work + 0x914) / 500.0f) * 2.0f);
    opMenuSetRect(0x110,
                  -320.0f - (1.0f - (f32)*(s32*)((u8*)work + 0x910) /
                            1300.0f) * 1100.0f,
                  0.0f, 1280.0f, 448.0f);
    opMenuSetRect(0x210,
                  780.0f - (1.0f - (f32)*(s32*)((u8*)work + 0x910) /
                            1300.0f) * 1100.0f,
                  0.0f, 1280.0f, 448.0f);
    opMenuColor((u8*)work + 0x110,
                alpha * 255.0f * (pulse * 0.25f + fGpffff80c0));
    opMenuColor((u8*)work + 0x210,
                alpha * 255.0f * (pulse * 0.25f + fGpffff80c0));

    angle = fGpffff8248 *
            ((f32)*(s32*)((u8*)work + 0xae8) / 150.0f) * 2.0f;
    pulse = fGpffff8248 * ((func_0052e878(angle) * 1.5f) / 360.0f) * 2.0f;
    opMenuSetPoly(0x310, 0.0f, 0.0f, 640.0f, 448.0f, pulse,
                  fGpffff80c0, fGpffff80c0);

    angle = fGpffff8248 *
            (fGpffff82fc + (f32)*(s32*)((u8*)work + 0xaf0) / 150.0f) * 2.0f;
    pulse = fGpffff8248 * ((func_0052e878(angle) * 1.5f) / 360.0f) * 2.0f;
    {
        f32 scale = fGpffff80c0;
        if (*(s32*)((u8*)work + 0xaec) > 0x40 &&
            *(s32*)((u8*)work + 0xaec) < 0x5f)
            scale += fGpffff82fc *
                     (f32)(*(s32*)((u8*)work + 0xaec) - 0x41) / 30.0f;
        opMenuSetPoly(0x410, 0.0f, 0.0f, 640.0f, 448.0f, pulse,
                      scale, scale);
    }
    opMenuColor((u8*)work + 0x310, 255.0f);
    opMenuColor((u8*)work + 0x410, 255.0f);

    alpha = opMenuClamp01((s32)fade, 0, 0x46);
    angle = fGpffff8248 *
            (fGpffff82fc + (f32)*(s32*)((u8*)work + 0xae4) / 150.0f) * 2.0f;
    pulse = fGpffff8248 * ((func_0052e878(angle) * 25.0f) / 360.0f) * 2.0f;
    opMenuSetPoly(0x510, 0.0f, 0.0f, 640.0f, 448.0f,
                  pulse, fGpffff819c, fGpffff819c);
    opMenuSetPoly(0x610, 0.0f, 0.0f, 640.0f, 448.0f,
                  pulse, fGpffff819c, fGpffff819c);
    opMenuColor((u8*)work + 0x510, alpha * 255.0f);
    opMenuColor((u8*)work + 0x610, alpha * 255.0f * 0.6f);

    alpha = opMenuClamp01((s32)fade, 0x14, 0x32);
    opMenuSetRect(0x710, 0.0f, 0.0f, 640.0f, 448.0f);
    opMenuColor((u8*)work + 0x710, alpha * 204.0f);
    alpha = opMenuClamp01((s32)fade, 0x0a, 0x50);
    opMenuSetRect(0x810, 0.0f, 0.0f, 640.0f, 448.0f);
    opMenuColor((u8*)work + 0x810, alpha * 255.0f);

    pulse = fade < 20.0f ? 750.0f :
            fade < 40.0f ? (1.0f - (fade - 20.0f) / 20.0f) * 750.0f :
            0.0f;
    frame = func_0021cca0(sprite, 0x15);
    opMenuSetIcon(0x920, frame, pulse, 95.0f);
    opMenuColor((u8*)work + 0x920, 255.0f);

    alpha = opMenuClamp01((s32)fade, 0x14, 0x28);
    if (count == 2)
    {
        u8* slot;
        f32 shown;
        f32 slide;

        slot = (u8*)work + 0x1a60;
        shown = opMenuClamp01((s32)fade, 0x14, 0x1e);
        slide = (1.0f - (shown * 2.0f - shown * shown)) * -50.0f;
        frame = func_0021cca0(sprite, 0x1c);
        opMenuSetIcon(0x1a70, frame, 26.0f + slide, 345.0f);
        opMenuColor((u8*)work + 0x1a70,
                    (1.0f - (f32)*(s32*)(slot + 4) / 16.0f) *
                    255.0f * shown);
        frame = func_0021cca0(sprite, 0x1d);
        opMenuSetIcon(0x1b70, frame, 26.0f + slide, 345.0f);
        opMenuColor((u8*)work + 0x1b70,
                    (f32)*(s32*)(slot + 4) / 16.0f * 255.0f * shown);

        slot = (u8*)work + 0x1d70;
        shown = opMenuClamp01((s32)fade, 0x19, 0x23);
        slide = (1.0f - (shown * 2.0f - shown * shown)) * -50.0f;
        frame = func_0021cca0(sprite, 0x1e);
        opMenuSetIcon(0x1d80, frame, 26.0f + slide, 383.0f);
        opMenuColor((u8*)work + 0x1d80,
                    (1.0f - (f32)*(s32*)(slot + 4) / 16.0f) *
                    255.0f * shown);
        frame = func_0021cca0(sprite, 0x1f);
        opMenuSetIcon(0x1e80, frame, 26.0f + slide, 383.0f);
        opMenuColor((u8*)work + 0x1e80,
                    (f32)*(s32*)(slot + 4) / 16.0f * 255.0f * shown);
    }
    else
    {
        u8* slot;
        f32 shown;
        f32 slide;

        slot = (u8*)work + 0xb00;
        shown = opMenuClamp01((s32)fade, 0x14, 0x1e);
        slide = (1.0f - (shown * 2.0f - shown * shown)) * -50.0f;
        frame = func_0021cca0(sprite, 0);
        opMenuSetIcon(0xb10, frame, 20.0f + slide, 298.0f);
        opMenuColor((u8*)work + 0xb10,
                    (1.0f - (f32)*(s32*)(slot + 4) / 16.0f) *
                    255.0f * shown);
        frame = func_0021cca0(sprite, 1);
        opMenuSetIcon(0xc10, frame, 20.0f + slide, 298.0f);
        opMenuColor((u8*)work + 0xc10,
                    (f32)*(s32*)(slot + 4) / 16.0f * 255.0f * shown);
        frame = func_0021cca0(sprite, 6);
        opMenuSetIcon(0xd10, frame, 20.0f + slide, 298.0f);
        opMenuColor((u8*)work + 0xd10,
                    (f32)*(s32*)(slot + 4) / 16.0f * 255.0f * shown);

        slot = (u8*)work + 0xe10;
        shown = opMenuClamp01((s32)fade, 0x19, 0x23);
        slide = (1.0f - (shown * 2.0f - shown * shown)) * -50.0f;
        frame = func_0021cca0(sprite, 2);
        opMenuSetIcon(0xe20, frame, 20.0f + slide, 323.0f);
        opMenuColor((u8*)work + 0xe20,
                    (1.0f - (f32)*(s32*)(slot + 4) / 16.0f) *
                    255.0f * shown);
        frame = func_0021cca0(sprite, 3);
        opMenuSetIcon(0xf20, frame, 20.0f + slide, 323.0f);
        opMenuColor((u8*)work + 0xf20,
                    (f32)*(s32*)(slot + 4) / 16.0f * 255.0f * shown);
        frame = func_0021cca0(sprite, 7);
        opMenuSetIcon(0x1020, frame, 20.0f + slide, 323.0f);
        opMenuColor((u8*)work + 0x1020,
                    (f32)*(s32*)(slot + 4) / 16.0f * 255.0f * shown);

        slot = (u8*)work + 0x1120;
        shown = opMenuClamp01((s32)fade, 0x1e, 0x28);
        slide = (1.0f - (shown * 2.0f - shown * shown)) * -50.0f;
        frame = func_0021cca0(sprite, 4);
        opMenuSetIcon(0x1130, frame, 20.0f + slide, 346.0f);
        opMenuColor((u8*)work + 0x1130,
                    (1.0f - (f32)*(s32*)(slot + 4) / 16.0f) *
                    255.0f * shown);
        frame = func_0021cca0(sprite, 5);
        opMenuSetIcon(0x1230, frame, 20.0f + slide, 346.0f);
        opMenuColor((u8*)work + 0x1230,
                    (f32)*(s32*)(slot + 4) / 16.0f * 255.0f * shown);
        frame = func_0021cca0(sprite, 8);
        opMenuSetIcon(0x1330, frame, 20.0f + slide, 346.0f);
        opMenuColor((u8*)work + 0x1330,
                    (f32)*(s32*)(slot + 4) / 16.0f * 255.0f * shown);

        slot = (u8*)work + 0x1430;
        shown = opMenuClamp01((s32)fade, 0x23, 0x2d);
        slide = (1.0f - (shown * 2.0f - shown * shown)) * -50.0f;
        frame = func_0021cca0(sprite, 0x19);
        opMenuSetIcon(0x1440, frame, 20.0f + slide, 371.0f);
        opMenuColor((u8*)work + 0x1440,
                    (1.0f - (f32)*(s32*)(slot + 4) / 16.0f) *
                    255.0f * shown);
        frame = func_0021cca0(sprite, 0x1a);
        opMenuSetIcon(0x1540, frame, 20.0f + slide, 371.0f);
        opMenuColor((u8*)work + 0x1540,
                    (f32)*(s32*)(slot + 4) / 16.0f * 255.0f * shown);
        frame = func_0021cca0(sprite, 0x1b);
        opMenuSetIcon(0x1640, frame, 20.0f + slide, 371.0f);
        opMenuColor((u8*)work + 0x1640,
                    (f32)*(s32*)(slot + 4) / 16.0f * 255.0f * shown);

        frame = func_0021cca0(sprite, 0x22);
        opMenuSetIcon(0x1750, frame, 323.0f, 115.0f);
        frame = func_0021cca0(sprite, 0x23);
        opMenuSetIcon(0x1850, frame, 323.0f, 115.0f);
        opMenuColor((u8*)work + 0x1750,
                    (f32)work[0x1740 / 4] / 8.0f * 255.0f);
        opMenuColor((u8*)work + 0x1850,
                    (f32)work[0x1740 / 4] / 8.0f * 255.0f);
    }

    rect[0] = 0.0f;
    rect[1] = -88.0f;
    rect[2] = 1086.0f;
    rect[3] = 448.0f;
    rect[4] = 0.0f;
    rect[5] = 448.0f;
    angle = fGpffff8248 * ((f32)work[0x918 / 4] / 150.0f) * 2.0f;
    pulse = func_0052e878(angle);
    scale = fGpffff809c + fGpffff83a4 * pulse;
    for (i = 0; i < 3; i++)
    {
        rect[i * 2] = (rect[i * 2] - fGpffff809c) * scale +
                      fGpffff809c;
        rect[i * 2 + 1] = (rect[i * 2 + 1] - fGpffff809c) * scale +
                          fGpffff809c;
    }
    ((f32*)((u8*)work + 0xa20))[0] = rect[0];
    ((f32*)((u8*)work + 0xa20))[1] = rect[1];
    ((f32*)((u8*)work + 0xa60))[0] = rect[2];
    ((f32*)((u8*)work + 0xa60))[1] = rect[3];
    ((f32*)((u8*)work + 0xaa0))[0] = rect[4];
    ((f32*)((u8*)work + 0xaa0))[1] = rect[5];

    color[0] = 0x0a;
    color[1] = 0x11;
    color[2] = 0x30;
    color[3] = 0;
    for (i = 0; i < 4; i++)
        ((f32*)((u8*)work + 0xa40))[i] = (f32)color[i];

    color[0] = 0;
    color[1] = 7;
    color[2] = 0x26;
    color[3] = 0;
    for (i = 0; i < 4; i++)
        ((f32*)((u8*)work + 0xa80))[i] = (f32)color[i];

    color[3] = (u8)(fGpffff8480 * alpha);
    for (i = 0; i < 4; i++)
        ((f32*)((u8*)work + 0xac0))[i] = (f32)color[i];
}
#pragma opt_loop_invariants off

// FUN_0026C710
void opMenu0026c710(void)
{
    u32* work;
    OpMenuSetState* setState;
    OpMenuDrawWords* draw;

    K_ASSERT(sOpMenu != NULL, 0x87);
    work = sOpMenu;
    opResGetTitleSprite(0);
    if ((~work[0] & 1) != 0)
        return;
    setState = (OpMenuSetState*)D_00960090;
    (*setState)(8, 0);
    (*setState)(6, 0);
    (*setState)(9, 2);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*setState)(1, opResGetTitleRasterU32(1));
    draw = (OpMenuDrawWords*)D_0096009C;
    (*draw)(work + 4, 4, 0, 1, 2);
    (*draw)(work + 4, 4, 0, 2, 3);
    func_004d7f60(3, 0x71801);
    func_004d7f60(2, 0x48);
    (*setState)(1, opResGetTitleRasterU32(0));
    (*draw)(work + 0x44, 4, 0, 1, 2);
    (*draw)(work + 0x44, 4, 0, 2, 3);
    (*draw)(work + 0x84, 4, 0, 1, 2);
    (*draw)(work + 0x84, 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x6a);
    (*setState)(1, opResGetTitleRasterU32(3));
    (*draw)(work + 0x144, 4, 0, 1, 2);
    (*draw)(work + 0x144, 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x58);
    (*setState)(1, opResGetTitleRasterU32(4));
    (*draw)(work + 0xc4, 4, 0, 1, 2);
    (*draw)(work + 0xc4, 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x6a);
    (*setState)(1, opResGetTitleRasterU32(3));
    (*draw)(work + 0x184, 4, 0, 1, 2);
    (*draw)(work + 0x184, 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x58);
    (*setState)(1, opResGetTitleRasterU32(4));
    (*draw)(work + 0x104, 4, 0, 1, 2);
    (*draw)(work + 0x104, 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*setState)(1, opResGetTitleRasterU32(2));
    (*draw)(work + 0x1c4, 4, 0, 1, 2);
    (*draw)(work + 0x1c4, 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*setState)(1, 0);
    (*draw)(work + 0x288, 3, 0, 1, 2);
    func_004d7f60(3, 0x71801);
    func_004d7f60(2, 0x48);
    (*setState)(1, opResGetTitleRasterU32(5));
    (*draw)(work + 0x204, 4, 0, 1, 2);
    (*draw)(work + 0x204, 4, 0, 2, 3);
}

#pragma opt_loop_invariants on
// FUN_0026CC90 NONMATCHING
void opMenu0026cc90(void)
{
    u32* work;
    void* atlas;
    OpMenuSetFrame* setState;
    OpMenuDraw* draw;
    u32 frame;
    s32 i;
    u32 id;

    K_ASSERT(sOpMenu != NULL, 0x87);
    work = sOpMenu;
    atlas = opResGetTitleSprite(0);
    setState = (OpMenuSetFrame*)opMenuStatePtr;
    draw = (OpMenuDraw*)opMenuDrawPtr;
    if ((work[0] & 1) == 0)
        return;

    (*setState)(8, 0);
    (*setState)(6, 0);
    (*setState)(9, 2);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    frame = func_0021cce0(func_0021cca0(atlas, 0x15));
    (*setState)(1, frame);
    (*draw)(work + 0x920 / 4, 4, 0, 1, 2);
    (*draw)(work + 0x920 / 4, 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);

    if ((work[0] & 0x20) == 0)
    {
        for (i = 0; i < 2; i++)
        {
            id = i == 0 ? 0x1c : 0x1e;
            frame = func_0021cce0(func_0021cca0(atlas, id));
            (*setState)(1, frame);
            (*draw)((void*)((u8*)work + 0x1a70 + i * 0x310),
                    4, 0, 1, 2);
            (*draw)((void*)((u8*)work + 0x1a70 + i * 0x310),
                    4, 0, 2, 3);
        }
        func_004d7f60(3, 0x71801);
        func_004d7f60(2, 0x48);
        for (i = 0; i < 2; i++)
        {
            id = i == 0 ? 0x1d : 0x1f;
            frame = func_0021cce0(func_0021cca0(atlas, id));
            (*setState)(1, frame);
            (*draw)((void*)((u8*)work + 0x1b70 + i * 0x310),
                    4, 0, 1, 2);
            (*draw)((void*)((u8*)work + 0x1b70 + i * 0x310),
                    4, 0, 2, 3);
        }
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            if (i == 0) id = 0;
            else if (i == 1) id = 2;
            else if (i == 2) id = 4;
            else id = 0x19;
            frame = func_0021cce0(func_0021cca0(atlas, id));
            (*setState)(1, frame);
            (*draw)((void*)((u8*)work + 0xb10 + i * 0x310),
                    4, 0, 1, 2);
            (*draw)((void*)((u8*)work + 0xb10 + i * 0x310),
                    4, 0, 2, 3);
            if (i == 0) id = 6;
            else if (i == 1) id = 7;
            else if (i == 2) id = 8;
            else id = 0x1b;
            frame = func_0021cce0(func_0021cca0(atlas, id));
            (*setState)(1, frame);
            (*draw)((void*)((u8*)work + 0xc10 + i * 0x310),
                    4, 0, 1, 2);
            (*draw)((void*)((u8*)work + 0xc10 + i * 0x310),
                    4, 0, 2, 3);
            if (i == 0) id = 1;
            else if (i == 1) id = 3;
            else if (i == 2) id = 5;
            else id = 0x1a;
            frame = func_0021cce0(func_0021cca0(atlas, id));
            (*setState)(1, frame);
            (*draw)((void*)((u8*)work + 0xd10 + i * 0x310),
                    4, 0, 1, 2);
            (*draw)((void*)((u8*)work + 0xd10 + i * 0x310),
                    4, 0, 2, 3);
        }
        func_004d7f60(3, 0x71801);
        func_004d7f60(2, 0x48);
        id = work[0x1a50 / 4] + 0x22;
        frame = func_0021cce0(func_0021cca0(atlas, id));
        (*setState)(1, frame);
        if (work[0x1a50 / 4] == 0)
        {
            (*draw)((void*)((u8*)work + 0x1750), 4, 0, 1, 2);
            (*draw)((void*)((u8*)work + 0x1750), 4, 0, 2, 3);
        }
        else
        {
            (*draw)((void*)((u8*)work + 0x1850), 4, 0, 1, 2);
            (*draw)((void*)((u8*)work + 0x1850), 4, 0, 2, 3);
        }
    }
}

// FUN_0026D430 NONMATCHING
void opMenu0026d430(void)
{
    u32* work;
    void* atlas;
    f32 layout[4];
    f32 inverseZ;
    void* frame;
    s32 i;
    u32* item;
    u32 choice;

    K_ASSERT(sOpMenu != NULL, 0x87);
    work = sOpMenu;
    atlas = opResGetTitleSprite(0);
    inverseZ = 1.0f / *(f32*)((u8*)func_00198590() + 0x80);

    layout[0] = 0.0f;
    layout[1] = 0.0f;
    layout[2] = 1.0f;
    layout[3] = 1.0f;
    func_0021eae0(work + 4, layout);
    func_0021eac0(0, work + 4);
    layout[0] = 0.0f;
    layout[1] = 0.0f;
    layout[2] = 1.0f;
    layout[3] = 1.0f;
    func_0021eae0(work + 0x44, layout);
    func_0021eac0(0, work + 0x44);
    func_0021eae0(work + 0x84, layout);
    func_0021eac0(0, work + 0x84);
    layout[0] = 0.0f;
    layout[1] = 0.0f;
    layout[2] = 1.0f;
    layout[3] = 1.0f;
    func_0021eae0(work + 0xc4, layout);
    func_0021eac0(0, work + 0xc4);
    func_0021eae0(work + 0x104, layout);
    func_0021eac0(0, work + 0x104);
    layout[0] = 0.0f;
    layout[1] = 0.0f;
    layout[2] = 1.0f;
    layout[3] = 1.0f;
    func_0021eae0(work + 0x144, layout);
    func_0021eac0(0, work + 0x144);
    func_0021eae0(work + 0x184, layout);
    func_0021eac0(0, work + 0x184);
    layout[0] = 0.0f;
    layout[1] = 0.0f;
    layout[2] = 1.0f;
    layout[3] = 1.0f;
    func_0021eae0(work + 0x1c4, layout);
    func_0021eac0(0, work + 0x1c4);
    func_0021eae0(work + 0x204, layout);
    func_0021eac0(0, work + 0x204);

    frame = func_0021cca0(atlas, 0x15);
    func_0021d3b0((u8*)work + 0x920, frame);

    work[0xaf8 / 4] = 0;
    for (i = 0; i < 4; i++)
    {
        item = (u32*)((u8*)work + 0xb00 + i * 0x310);
        item[0] = i == work[0xaf8 / 4] ? 0 : 8;
        item[1] = 0;
        switch (i)
        {
        case 0:
            choice = 0;
            break;
        case 1:
            choice = 2;
            break;
        case 2:
            choice = 4;
            break;
        case 3:
            choice = 0x19;
            break;
        }
        frame = func_0021cca0(atlas, choice);
        func_0021d3b0((u8*)item + 0x10, frame);
        if (i == 3) choice = 0x1a;
        else if (i == 2) choice = 5;
        else if (i == 1) choice = 3;
        else choice = 1;
        frame = func_0021cca0(atlas, choice);
        func_0021d3b0((u8*)item + 0x110, frame);
        if (i == 3) choice = 0x1b;
        else if (i == 2) choice = 8;
        else if (i == 1) choice = 7;
        else choice = 6;
        frame = func_0021cca0(atlas, choice);
        func_0021d3b0((u8*)item + 0x210, frame);
    }

    work[0x1740 / 4] = 0;
    work[0x1744 / 4] = 0;
    frame = func_0021cca0(atlas, 0x22);
    func_0021d3b0((u8*)work + 0x1750, frame);
    frame = func_0021cca0(atlas, 0x23);
    func_0021d3b0((u8*)work + 0x1850, frame);

    work[0x1a50 / 4] = 0;
    for (i = 0; i < 2; i++)
    {
        item = (u32*)((u8*)work + 0x1a60 + i * 0x310);
        item[0] = i == work[0x1a50 / 4] ? 0 : 8;
        item[1] = 0;
        choice = i == 0 ? 0x1c : 0x1e;
        frame = func_0021cca0(atlas, choice);
        func_0021d3b0((u8*)item + 0x10, frame);
        choice = i == 0 ? 0x1d : 0x1f;
        frame = func_0021cca0(atlas, choice);
        func_0021d3b0((u8*)item + 0x110, frame);
    }

    work[0xa28 / 4] = 0;
    work[0xa30 / 4] = 0;
    work[0xa34 / 4] = 0;
    *(f32*)((u8*)work + 0xa38) = inverseZ;
    work[0xa68 / 4] = 0;
    work[0xa70 / 4] = 0;
    work[0xa74 / 4] = 0;
    *(f32*)((u8*)work + 0xa78) = inverseZ;
    work[0xaa8 / 4] = 0;
    work[0xab0 / 4] = 0;
    work[0xab4 / 4] = 0;
    *(f32*)((u8*)work + 0xab8) = inverseZ;
    work[0x910 / 4] = 0;
    work[0x914 / 4] = 0;
    work[0x918 / 4] = 0;
    work[0xae0 / 4] = 0;
    work[0xae4 / 4] = 0;
    work[0xae8 / 4] = 0;
    work[0xaec / 4] = 0;
    work[0xaf0 / 4] = 0;
    work[0xaf4 / 4] = 0;
    work[0] |= 8;
    opMenu0026dc70();
    work[0] |= 1;
}
#pragma opt_loop_invariants off
