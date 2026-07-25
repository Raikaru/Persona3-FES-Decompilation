#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwln.h"
#include "Kosaka/k_assert.h"
#include "Main/OpEd/op_res.h"
#include "rw/rwcore.h"

void opWait0026eed0(void);
void opWait0026edd0(void);
extern void opWait0026ed40(void);
extern void func_0021eae0(void* destination, const f32* layout);
extern void func_0021eac0(void* destination, f32 value);
extern void func_0021eb80(void* destination, const f32* layout);
extern void func_0021d8e0(void* destination, const f32* layout);
extern void func_0021d890(void* destination, const f32* layout);
extern void func_0021d950(void* destination, const u8* color);
extern void* opRes00266c50(u32 id);
extern void* func_0021cca0(void* resource, u32 index);
extern void* func_0021cce0(void* frame);
extern void func_002699d0(void* value);
extern void func_002699a0(void* value);
extern void func_004d7f60(s32 state, u32 value);
#pragma alias opWaitGetTitleRasterU32 opResGetTitleRaster
extern u32 opWaitGetTitleRasterU32(u32 id);
extern u32 D_00960090[];
extern u32 D_0096009C[];
extern void func_00269a10(u32 id, void* callback);
extern void func_00271230(u32* param);
extern void func_002716d0(u32* param);
extern s32 func_00488f30(void);
extern f32 func_0052e878(f32 value);
extern f32 func_0052e6d8(f32 value);
extern f32 func_00269c80(f32 value);
extern f32 func_00269ca0(f32 value);
extern u32 FUN_00269690(s32 mode, s32 index, u32 flags);
extern f32 DAT_007caf38;
extern f32 DAT_007cad84;
extern f32 DAT_007cad94;
extern f32 DAT_007cafec;
extern f32 DAT_007cb080;
extern f32 DAT_007cadb0;
extern f32 DAT_007cb15c;
extern f32 DAT_007cb160;
extern f32 DAT_007cb10c;
extern f32 fGpffff839c;
extern f32 fGpffff81f8;
extern f32 fGpffff8248;
extern f32 fGpffff82fc;
extern f32 fGpffff8294;
extern void* func_00198590(void);

static u32* sOpWait; // DAT_007ce3b8

typedef struct OpWaitWork
{
    u32 flags;                  /* 0x0000 */
    s32 mode;                   /* 0x0004 */
    u32 counters[10];           /* 0x000c..0x0033 */
    u8 reserved_34[0x0c];       /* 0x0034..0x003f */
    u8 quads[0xe00];             /* 0x0040..0x0e3f */
    u8 parts[0x330];             /* 0x0e40..0x116f, stride 0x110 */
    void* resources[2];          /* 0x1170/0x1174 */
    f32 alpha;                   /* 0x1178 */
} OpWaitWork;
static inline u32 opWaitU32(const u8* work, u32 offset)
{
    return *(const u32*)(work + offset);
}

static inline s32 opWaitS32(const u8* work, u32 offset)
{
    return *(const s32*)(work + offset);
}

static inline void opWaitPutU32(u8* work, u32 offset, u32 value)
{
    *(u32*)(work + offset) = value;
}

static inline void opWaitSetColor(void* quad, f32 alpha)
{
    u8 color[4];
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)alpha;
    func_0021d950(quad, color);
}

static inline f32 opWaitClamp01(s32 value, s32 begin, s32 end)
{
    if (value <= begin)
        return 0.0f;
    if (value >= end)
        return 1.0f;
    return (f32)(value - begin) / (f32)(end - begin);
}

// FUN_0026dd10
void opWait0026dd10(u32* param_1)
{
    K_ASSERT(sOpWait == NULL, 0xe2);
    *param_1 = 0;
    sOpWait = param_1;
}

// FUN_0026dd60
void opWait0026dd60(void)
{
    K_ASSERT(sOpWait != NULL, 0xdb);
    if (*sOpWait & 2)
        opWait0026ed40();
    sOpWait = NULL;
}

// FUN_0026ec50
void opWait0026ec50(void)
{
    u32* work;

    K_ASSERT(sOpWait != NULL, 0xdb);
    work = sOpWait;
    work[2] = 0;
    work[1] = 0;
    *work |= 4;
}

// FUN_0026eca0
void opWait0026eca0(void)
{
    u32* work;
    u32 uVar2;

    K_ASSERT(sOpWait != NULL, 0xdb);
    work = sOpWait;
    if (*work & 2)
        opWait0026ed40();
    uVar2 = FUN_00269690(1, 0xc, 9);
    work[0x45c] = uVar2;
    uVar2 = FUN_00269690(1, 0xc, 9);
    work[0x45d] = uVar2;
    *work |= 2;
}

// FUN_0026ee80
u32 opWait0026ee80(void)
{
    K_ASSERT(sOpWait != NULL, 0xdb);
    return *sOpWait & 8;
}

// FUN_0026ebf0
void opWait0026ebf0(void)
{
    u32 uVar1;

    K_ASSERT(sOpWait != NULL, 0xdb);
    uVar1 = *sOpWait & 0xfffffffe;
    *sOpWait = uVar1;
    if (uVar1 & 2)
        opWait0026ed40();
}

// FUN_0026edd0
void opWait0026edd0(void)
{
    u32* puVar1;

    K_ASSERT(sOpWait != NULL, 0xdb);
    puVar1 = sOpWait;
    sOpWait[2] = 0;
    puVar1[1] = 1;
    *puVar1 |= 4;
}

// FUN_0026ee30
u32 opWait0026ee30(void)
{
    K_ASSERT(sOpWait != NULL, 0xdb);
    return *sOpWait & 4;
}

// FUN_0026DDC0
void opWait0026ddc0(void)
{
    s32* work;

    K_ASSERT(sOpWait != NULL, 0xdb);
    work = (s32*)sOpWait;
    if ((~*work & 1) == 0)
    {
        work[3]++;
        work[3] %= 0x5a;
        work[4]++;
        work[4] %= 0x32;
        work[5]++;
        work[5] %= 0x1e;
        work[6]++;
        work[6] %= 0x2b2;
        work[7]++;
        work[7] %= 0x46;
        work[8]++;
        work[8] %= 0x2b2;
        work[9]++;
        work[9] %= 0x400;
        work[11]++;
        work[11] %= 0x168;
        work[12]++;
        work[12] %= 0x400;

        if ((*work & 8) != 0)
        {
            if (work[10] < 0xbe)
                work[10]++;
            else
                *work &= ~8;
        }

        if ((*work & 4) != 0)
        {
            switch (work[1])
            {
                case 0:
                    if (work[2] < 0xdc)
                        work[2]++;
                    else
                        *work &= ~4;
                    break;
                case 1:
                    if (work[2] < 0xdc)
                        work[2]++;
                    else
                        *work &= ~4;
                    break;
            }
        }
        opWait0026eed0();
    }
}

// FUN_0026ed40
void opWait0026ed40(void)
{
    u8* work;

    K_ASSERT(sOpWait != NULL, 0xdb);
    work = (u8*)sOpWait;
    func_002699a0(*(void**)(work + 0x1170));
    func_002699a0(*(void**)(work + 0x1174));
    opWaitPutU32(work, 0, opWaitU32(work, 0) & ~2u);
}

// FUN_0026edb0
void opWait0026edb0(void)
{
    opWait0026edd0();
}

// FUN_0026E000 NONMATCHING
void opWait0026e000(void)
{
    u8* work;
    void* atlas;
    void* frame;
    void (**setState)(u32 state, u32 value);
    void (**setQuad)(void* quad, u32 layer, u32 group, u32 pass, u32 blend);
    void (**loopSetQuad)(void* quad, u32 layer, u32 group, u32 pass, u32 blend);
    void* loopQuad;
    u32 frameId;
    s32 i;

    K_ASSERT(sOpWait != NULL, 0xdb);
    work = (u8*)sOpWait;
    atlas = opResGetTitleSprite(0);
    if ((~*(u32*)work & 1) != 0)
        return;
    setState = (void (**)(u32, u32))D_00960090;
    (*setState)(8, 0);
    (*setState)(6, 0);
    (*setState)(9, 2);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*setState)(1, opWaitGetTitleRasterU32(6));
    setQuad = (void (**)(void*, u32, u32, u32, u32))D_0096009C;
    (*setQuad)(work + 0x40, 4, 0, 1, 2);
    (*setQuad)(work + 0x40, 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*setState)(1, opWaitGetTitleRasterU32(7));
    (*setQuad)(work + 0x140, 4, 0, 1, 2);
    (*setQuad)(work + 0x140, 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*setState)(1, opWaitGetTitleRasterU32(8));
    (*setQuad)(work + 0x240, 4, 0, 1, 2);
    (*setQuad)(work + 0x240, 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    for (i = 0; i < 3; i++)
    {
        loopQuad = work + 0xe50 + (u32)i * 0x110;
        switch (i)
        {
            case 0:
                frameId = 9;
                break;
            case 1:
                frameId = 0xa;
                break;
            case 2:
                frameId = 0xb;
                break;
            default:
                continue;
        }
        (*setState)(1, opWaitGetTitleRasterU32(frameId));
        loopSetQuad = (void (**)(void*, u32, u32, u32, u32))D_0096009C;
        (*loopSetQuad)(loopQuad, 4, 0, 1, 2);
        (*loopSetQuad)(loopQuad, 4, 0, 2, 3);
    }
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*setState)(1, opWaitGetTitleRasterU32(0xc));
    (*setQuad)(work + 0x340, 4, 0, 1, 2);
    (*setQuad)(work + 0x340, 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*setState)(1, opWaitGetTitleRasterU32(0xd));
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    func_002699d0(*(void**)(work + 0x1170));
    func_004d7f60(3, 0x71801);
    func_004d7f60(2, 0x48);
    func_002699d0(*(void**)(work + 0x1174));
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x54);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    frame = func_0021cce0(func_0021cca0(atlas, 0x13));
    (*setState)(1, (u32)(unsigned long)frame);
    (*setQuad)(work + 0x940, 4, 0, 1, 2);
    (*setQuad)(work + 0x940, 4, 0, 2, 3);
    frame = func_0021cce0(func_0021cca0(atlas, 0x26));
    (*setState)(1, (u32)(unsigned long)frame);
    (*setQuad)(work + 0xa40, 4, 0, 1, 2);
    (*setQuad)(work + 0xa40, 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    frame = func_0021cce0(func_0021cca0(atlas, 10));
    (*setState)(1, (u32)(unsigned long)frame);
    (*setQuad)(work + 0xb40, 4, 0, 1, 2);
    (*setQuad)(work + 0xb40, 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    func_004d7f60(3, 0x71801);
    func_004d7f60(2, 0x48);
    frame = func_0021cce0(func_0021cca0(atlas, 0x10));
    (*setState)(1, (u32)(unsigned long)frame);
    (*setQuad)(work + 0xd40, 4, 0, 1, 2);
    (*setQuad)(work + 0xd40, 4, 0, 2, 3);
    frame = func_0021cce0(func_0021cca0(atlas, 0x10));
    (*setState)(1, (u32)(unsigned long)frame);
    (*setQuad)(work + 0xd40, 4, 0, 1, 2);
    (*setQuad)(work + 0xd40, 4, 0, 2, 3);
}

// FUN_0026E780 NONMATCHING
void opWait0026e780(void)
{
    u8* work;
    void* atlas;
    void* frame;
    volatile u8 pad[16];
    f32 layout[4];
    s32 order[3];
    s32 i;
    s32 j;
    s32 k;
    s32 width;
    s32 height;
    __asm__ volatile ("" : : "r"(pad) : "memory");

    K_ASSERT(sOpWait != NULL, 0xdb);
    work = (u8*)sOpWait;
    atlas = opResGetTitleSprite(0);
    kwlnGetMainCamera();
    layout[0] = 0.0f;
    layout[1] = 0.0f;
    layout[2] = 1.0f;
    layout[3] = 1.0f;
    func_0021eae0(work + 0x40, layout);
    func_0021eac0(work + 0x40, 0.0f);
    func_0021eae0(work + 0x140, layout);
    func_0021eac0(work + 0x140, 0.0f);
    func_0021eae0(work + 0x240, layout);
    func_0021eac0(work + 0x240, 0.0f);
    for (i = 0; i < 3; i++)
        order[i] = i;
    for (j = 0; j < 0x10; j++)
    {
        s32 a = func_00488f30() % 3;
        s32 b = func_00488f30() & 1;
        s32 t;
        if (a <= b)
            b++;
        t = order[a];
        order[a] = order[b];
        order[b] = t;
    }
    for (k = 0; k < 3; k++)
    {
        *(u32*)(work + 0xe40 + (u32)k * 0x110) =
            (u32)(order[k] * 100 + 0x3c);
        func_0021eae0(work + 0xe50 + (u32)k * 0x110, layout);
        func_0021eac0(work + 0xe50 + (u32)k * 0x110, 0.0f);
    }
    frame = opResGetTitleRaster(0xc);
    width = *(s32*)((u8*)frame + 0x0c);
    height = *(s32*)((u8*)frame + 0x10);
    layout[0] = 2.0f / (f32)width;
    layout[1] = 2.0f / (f32)height;
    layout[2] = 640.0f / (f32)width;
    layout[3] = 448.0f / (f32)height;
    func_0021eb80(work + 0x340, layout);
    func_0021eac0(work + 0x340, 0.0f);
    layout[0] = 651.0f / (f32)width;
    layout[1] = 2.0f / (f32)height;
    layout[2] = 232.0f / (f32)width;
    layout[3] = 416.0f / (f32)height;
    func_0021eb80(work + 0x440, layout);
    func_0021eac0(work + 0x440, 0.0f);
    layout[0] = 0.0f;
    layout[1] = 0.0f;
    layout[2] = 1.0f;
    layout[3] = 1.0f;
    func_0021eb80(work + 0x840, layout);
    func_0021eac0(work + 0x840, 0.0f);
    frame = func_0021cca0(atlas, 0x13);
    func_0021d3b0(work + 0x940, frame);
    frame = func_0021cca0(atlas, 0x26);
    func_0021d3b0(work + 0xa40, frame);
    frame = func_0021cca0(atlas, 0xa);
    func_0021d3b0(work + 0xb40, frame);
    frame = func_0021cca0(atlas, 0xb);
    func_0021d3b0(work + 0xc40, frame);
    frame = func_0021cca0(atlas, 0x10);
    func_0021d3b0(work + 0xd40, frame);
    opWait0026ec50();
    *(u32*)(work + 0x0c) = 0;
    *(u32*)(work + 0x10) = 0;
    *(u32*)(work + 0x14) = 0;
    *(u32*)(work + 0x18) = 0;
    *(u32*)(work + 0x1c) = 0;
    *(u32*)(work + 0x20) = 0;
    *(u32*)(work + 0x24) = 0;
    *(u32*)(work + 0x28) = 0;
    *(u32*)work |= 8;
    opWait0026eca0();
    opWait0026eed0();
    *(u32*)(work + 0x2c) = 0;
    *(u32*)(work + 0x30) = 0;
    *(u32*)work |= 1;
}

static inline void opWaitSetPoly(void* destination, f32* points, f32 x, f32 y,
                                 f32 width, f32 height, f32 scaleX, f32 scaleY)
{
    f32 halfW = width * 0.5f;
    f32 halfH = height * 0.5f;
    f32 centerX = x + halfW;
    f32 centerY = y + halfH;
    s32 i;

    points[0] = x;
    points[1] = y;
    points[2] = x + width;
    points[3] = y;
    points[4] = x + width;
    points[5] = y + height;
    points[6] = x;
    points[7] = y + height;
    for (i = 0; i < 4; i++)
    {
        points[i * 2] -= centerX;
        points[i * 2 + 1] -= centerY;
    }
    for (i = 0; i < 4; i++)
    {
        points[i * 2] *= scaleX;
        points[i * 2 + 1] *= scaleY;
    }
    for (i = 0; i < 4; i++)
    {
        points[i * 2] += centerX;
        points[i * 2 + 1] += centerY;
    }
    func_0021d890(destination, points);
}
static inline void opWaitSetPolyPivot(void* destination, f32* points,
                                      f32 width, f32 height, f32 pivotX,
                                      f32 pivotY, f32 scaleX, f32 scaleY)
{
    s32 i;

    points[0] = 0.0f;
    points[1] = 0.0f;
    points[2] = width;
    points[3] = 0.0f;
    points[4] = width;
    points[5] = height;
    points[6] = 0.0f;
    points[7] = height;
    for (i = 0; i < 4; i++)
    {
        points[i * 2] -= pivotX;
        points[i * 2 + 1] -= pivotY;
        points[i * 2] *= scaleX;
        points[i * 2 + 1] *= scaleY;
        points[i * 2] += pivotX;
        points[i * 2 + 1] += pivotY;
    }
    func_0021d890(destination, points);
}

// Retail's frame-0x10 overlay uses a dynamic x offset and fixed 256/375/202 geometry.
// Keep the explicit atlas lookup and default-mode alpha path even though this
// source-shape correction currently increases normalized_diff while preserving
// the runtime behavior for the overlay's documented mode 0/1 paths.
// The frame dimensions and mode fallback were previously approximated.
// FUN_0026EED0 NONMATCHING
void opWait0026eed0(void)
{
    u8* work;
    void* atlas;
    void* frame;
    f32 points[8];
    f32 alpha;
    f32 phase;
    f32 x;
    f32 y;
    f32 width;
    f32 height;
    f32 scale;
    f32 angle;
    s32 mode;
    s32 timer;
    s32 i;

    K_ASSERT(sOpWait != NULL, 0xdb);
    work = (u8*)sOpWait;
    atlas = opRes00266c50(0);
    mode = *(s32*)(work + 4);
    timer = *(s32*)(work + 8);

    if (mode == 1)
        alpha = 1.0f - opWaitClamp01(timer, 0, 0x28);
    else if (mode == 0)
        alpha = opWaitClamp01(timer, 0, 100);
    else
        alpha = 1.0f;
    {
        f32 rect[4] = {0.0f, 0.0f, 640.0f, 448.0f};
        func_0021d8e0(work + 0x40, rect);
        opWaitSetColor(work + 0x40, alpha * 255.0f);
    }

    phase = func_0052e878(DAT_007caf38 *
                          ((f32)*(s32*)(work + 0x1c) / 70.0f) * 2.0f);
    phase *= DAT_007cad84;
    opWaitSetPoly(work + 0x140, points, -1.0f, 29.0f, 643.0f, 419.0f,
                  1.0f, 1.0f);
    opWaitSetColor(work + 0x140, alpha * 255.0f * (phase + 0.75f));

    x = 210.0f - ((f32)*(s32*)(work + 0x20) / 690.0f) * 188.0f;
    y = 69.0f - ((f32)*(s32*)(work + 0x20) / 690.0f) * 93.0f;
    {
        f32 rect[4] = {x, y, 256.0f, 256.0f};
        func_0021d8e0(work + 0x240, rect);
        if (mode == 1)
            alpha = 1.0f - opWaitClamp01(timer, 0, 20);
        else if (mode == 0)
            alpha = opWaitClamp01(timer, 0, 200);
        else
            alpha = 1.0f;
        opWaitSetColor(work + 0x240, alpha * 255.0f);
    }

    if (mode == 0)
    {
        alpha = opWaitClamp01(timer, 0, 60);
        {
            f32 rect[4] = {0.0f, 0.0f, 640.0f, 448.0f};
            func_0021d8e0(work + 0x340, rect);
        }
    }
    else if (mode == 1)
    {
        phase = opWaitClamp01(timer, 0, 40);
        alpha = 1.0f - opWaitClamp01(timer, 0, 30);
        opWaitSetPoly(work + 0x340, points, 140.0f, 150.0f,
                      640.0f, 448.0f,
                      1.0f + phase * 4.5f,
                      1.0f + phase * 6.75f);
    }
    opWaitSetColor(work + 0x340, alpha * 255.0f);

    if (mode == 0)
    {
        phase = opWaitClamp01(timer, 55, 100);
        scale = phase * 2.0f - phase * phase;
        x = 335.0f + (1.0f - scale) * -370.0f;
        y = 32.0f + (1.0f - scale) * 200.0f;
        {
            f32 rect[4] = {x, y, 232.0f, 416.0f};
            func_0021d8e0(work + 0x440, rect);
        }
        alpha = opWaitClamp01(timer, 55, 60);
    }
    else if (mode == 1)
    {
        phase = opWaitClamp01(timer, 0, 10);
        alpha = 1.0f - phase;
        x = 335.0f + phase * 500.0f - 30.0f;
        y = 32.0f + phase * 400.0f;
        opWaitSetPoly(work + 0x440, points, x, y, 232.0f, 416.0f,
                      phase * 2.0f + 1.0f, phase * 2.0f + 1.0f);
    }
    opWaitSetColor(work + 0x440, alpha * 255.0f);

    if (mode == 1)
        alpha = 1.0f - opWaitClamp01(timer, 0, 20);
    else if (mode == 0)
        alpha = opWaitClamp01(timer, 100, 180);
    else
        alpha = 1.0f;
    phase = func_0052e878(DAT_007caf38 *
                          ((f32)*(s32*)(work + 0x10) / 50.0f) * 2.0f);
    opWaitSetColor(work + 0x640,
                   alpha * 255.0f *
                   (DAT_007cad84 * phase + DAT_007cad94));
    {
        f32 t = (f32)*(s32*)(work + 0x0c) / 90.0f;
        f32 pulse = t * 4.0f - t * 4.0f * t;
        f32 value = 0.5f - DAT_007cafec * pulse - DAT_007cb080;
        f32 rect[4];

        rect[0] = value;
        rect[1] = value;
        rect[2] = 0.5f + DAT_007cafec * pulse + DAT_007cb080;
        rect[3] = rect[2];
        func_0021eae0(work + 0x740, rect);
        opWaitSetColor(work + 0x740, 255.0f);
    }
    if (mode == 1)
        alpha = 1.0f - opWaitClamp01(timer, 0, 0x28);
    else
        alpha = opWaitClamp01(timer, 0x28, 0x96);
    *(f32*)(work + 0x1178) = alpha;
    angle = DAT_007caf38 * ((f32)*(s32*)(work + 0x14) / 30.0f) * 2.0f;
    phase = func_0052e878(angle) * DAT_007cb15c;
    scale = DAT_007cadb0;
    opWaitSetPoly(work + 0x840, points, 0.0f, 0.0f, 640.0f, 448.0f,
                  phase + scale,
                  DAT_007cb15c * func_0052e878(angle) + DAT_007cadb0);
    if (mode == 1)
        alpha = 1.0f - opWaitClamp01(timer, 0, 10);
    else if (mode == 0)
        alpha = opWaitClamp01(timer, 200, 220);
    else
        alpha = 1.0f;
    opWaitSetColor(work + 0x840, alpha * 255.0f);

    frame = func_0021cca0(atlas, 0x26);
    width = (f32)*(s32*)((u8*)frame + 0x0c);
    height = (f32)*(s32*)((u8*)frame + 0x10);
    if (mode == 1)
    {
        phase = opWaitClamp01(timer, 0, 10);
        x = 350.0f + phase * 100.0f;
        y = 401.0f + phase * 50.0f;
        alpha = 1.0f - phase;
    }
    else if (mode == 0)
    {
        phase = opWaitClamp01(timer, 200, 220);
        x = 350.0f;
        y = 401.0f;
        alpha = phase;
    }
    else
    {
        x = 350.0f;
        y = 401.0f;
        alpha = 1.0f;
    }
    {
        f32 rect[4] = {x, y, width, height};
        func_0021d8e0(work + 0xa40, rect);
        opWaitSetColor(work + 0xa40, alpha * 255.0f);
    }
    frame = func_0021cca0(atlas, 0x13);
    width = (f32)*(s32*)((u8*)frame + 0x0c);
    height = (f32)*(s32*)((u8*)frame + 0x10);
    if (mode == 1)
    {
        phase = opWaitClamp01(timer, 0, 10);
        x = 416.0f - phase * 100.0f;
        y = 401.0f - phase * 50.0f;
        alpha = 1.0f - phase;
    }
    else if (mode == 0)
    {
        alpha = opWaitClamp01(timer, 170, 210);
        x = 416.0f;
        y = 401.0f;
    }
    else
    {
        alpha = 1.0f;
        x = 416.0f;
        y = 401.0f;
    }
    {
        f32 rect[4] = {x, y, width, height};
        func_0021d8e0(work + 0x940, rect);
        opWaitSetColor(work + 0x940, alpha * 255.0f);
    }
    frame = func_0021cca0(atlas, 10);
    width = (f32)*(s32*)((u8*)frame + 0x0c);
    height = (f32)*(s32*)((u8*)frame + 0x10);
    if (mode == 1)
    {
        phase = opWaitClamp01(timer, 0, 10);
        x = 12.0f - phase * 100.0f;
        y = 15.0f - phase * 50.0f;
        alpha = 1.0f - phase;
    }
    else if (mode == 0)
    {
        alpha = opWaitClamp01(timer, 210, 220);
        x = 12.0f;
        y = 15.0f;
    }
    else
    {
        alpha = 1.0f;
        x = 12.0f;
        y = 15.0f;
    }
    {
        f32 rect[4] = {x, y, width, height};
        func_0021d8e0(work + 0xb40, rect);
        opWaitSetColor(work + 0xb40, alpha * 255.0f);
    }
    if (mode == 1)
        alpha = 1.0f - opWaitClamp01(timer, 0, 10);
    else if (mode == 0)
        alpha = opWaitClamp01(timer, 210, 220);
    else
        alpha = 1.0f;
    (void)func_0021cca0(atlas, 0x10);
    {
        f32 rect[4];
        f32 offset = ((f32)*(s32*)(work + 0x18) / 690.0f) * -300.0f;
        rect[0] = 341.0f + offset;
        rect[1] = 256.0f;
        rect[2] = 375.0f;
        rect[3] = 202.0f;
        func_0021d8e0(work + 0xd40, rect);
    }
    opWaitSetColor(work + 0xd40, alpha * 255.0f);

    for (i = 0; i < 3; i++)
    {
        s32 elapsed = *(s32*)(work + 0x24) -
                      *(s32*)(work + 0xe40 + (u32)i * 0x110);
        s32 start;
        s32 hold;
        s32 end;
        f32 partAlpha;
        f32 fade;
        f32 startX;
        f32 startY;
        f32 endX;
        f32 endY;
        f32 halfW;
        f32 halfH;
        f32 rotation;
        s32 j;

        switch (i)
        {
        case 0:
            start = 100;
            break;
        case 1:
            start = 100;
            break;
        case 2:
            start = 100;
            break;
        }
        switch (i)
        {
        case 0:
            hold = 160;
            break;
        case 1:
            hold = 160;
            break;
        case 2:
            hold = 160;
            break;
        }
        switch (i)
        {
        case 0:
            end = 200;
            break;
        case 1:
            end = 100;
            break;
        case 2:
            end = 200;
            break;
        }
        switch (i)
        {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        }
        switch (i)
        {
        case 0:
            end = 200;
            break;
        case 1:
            end = 100;
            break;
        case 2:
            end = 200;
            break;
        }
        switch (i)
        {
        case 0:
            width = 256.0f;
            height = 128.0f;
            break;
        case 1:
            width = 256.0f;
            height = 128.0f;
            break;
        case 2:
            width = 256.0f;
            height = 256.0f;
            break;
        }
        switch (i)
        {
        case 0:
            startX = 196.0f;
            startY = 84.0f;
            endX = -115.0f;
            endY = 233.0f;
            break;
        case 1:
            startX = 123.0f;
            startY = 237.0f;
            endX = -123.0f;
            endY = 21.0f;
            break;
        case 2:
            startX = -77.0f;
            startY = 173.0f;
            endX = 271.0f;
            endY = 45.0f;
            break;
        }

        if (elapsed < 0)
            partAlpha = 0.0f;
        else if (elapsed < start)
            partAlpha = (f32)elapsed / (f32)start;
        else if (elapsed < hold)
            partAlpha = 1.0f;
        else if (elapsed < end)
            partAlpha = 1.0f - (f32)(elapsed - hold) /
                        (f32)(end - hold);
        else
            partAlpha = 0.0f;

        if (mode == 1)
            fade = 1.0f - opWaitClamp01(timer, 0, 20);
        else
            fade = 1.0f;

        rotation = (f32)elapsed / (f32)end;
        x = startX + rotation * (endX - startX);
        y = startY + rotation * (endY - startY);
        rotation = DAT_007cb160 + rotation *
                   (DAT_007cb10c - DAT_007cb160);
        halfW = width * 0.5f;
        halfH = height * 0.5f;
        points[0] = 0.0f;
        points[1] = 0.0f;
        points[2] = width;
        points[3] = 0.0f;
        points[4] = width;
        points[5] = height;
        points[6] = 0.0f;
        points[7] = height;
        for (j = 0; j < 4; j++)
        {
            points[j * 2] -= halfW;
            points[j * 2 + 1] -= halfH;
        }
        for (j = 0; j < 4; j++)
        {
            f32 px = points[j * 2];
            f32 py = points[j * 2 + 1];
            points[j * 2] = px * func_0052e6d8(rotation) -
                             py * func_0052e878(rotation);
            points[j * 2 + 1] = px * func_0052e878(rotation) +
                                 py * func_0052e6d8(rotation);
        }
        for (j = 0; j < 4; j++)
        {
            points[j * 2] += halfW + x;
            points[j * 2 + 1] += halfH + y;
        }
        func_0021d890(work + 0xe50 + (u32)i * 0x110, points);
        opWaitSetColor(work + 0xe50 + (u32)i * 0x110,
                       partAlpha * fade * 255.0f);
    }

    {
        struct
        {
            void (*function)(u32*);
            u32* work;
        } callback;
        callback.function = func_00271230;
        callback.work = (u32*)work;
        func_00269a10(*(u32*)(work + 0x1170), &callback);
        callback.function = func_002716d0;
        func_00269a10(*(u32*)(work + 0x1174), &callback);
    }
}
extern f32 func_00269c80(f32 value);
extern f32 func_00269ca0(f32 value);
extern f32 func_0052ea18(f32 y, f32 x);
extern f32 sqrtf(f32 value);
extern f32 D_00960088;
extern u8* DAT_007ce420;

static inline RwIm2DVertex* opWaitVertex(u32* param)
{
    u8* stream;

    stream = *(u8**)(uintptr_t)param[0];
    return (RwIm2DVertex*)(stream + param[4] * sizeof(RwIm2DVertex));
}

static u8 opWaitColorByte(f32 value)
{
    if (value <= 0.0f)
        return 0;
    if (value >= 255.0f)
        return 255;
    return (u8)value;
}

static inline void opWaitSetVertex(RwIm2DVertex* vertex, f32 x, f32 y,
                                   f32 u, f32 v, f32 alpha, f32 recipZ)
{
    vertex->u.els.scrVertex.x = x;
    vertex->u.els.scrVertex.y = y;
    vertex->u.els.scrVertex.z = D_00960088;
    vertex->u.els.camVertex_z = 0.0f;
    vertex->u.els.u = u;
    vertex->u.els.v = v;
    vertex->u.els.recipZ = recipZ;
    vertex->u.els.color.r = 255.0f;
    vertex->u.els.color.g = 255.0f;
    vertex->u.els.color.b = 255.0f;
    vertex->u.els.color.a = (f32)opWaitColorByte(alpha);
}

// FUN_00271230 NONMATCHING
void func_00271230(u32* param)
{
    u8* context;
    RwIm2DVertex* vertex;
    RwCamera* camera;
    f32 width;
    f32 height;
    f32 x;
    f32 y;
    f32 angle;
    f32 distance;
    f32 wave;
    f32 scale;
    f32 sine;
    f32 cosine;
    f32 alpha;

    context = (u8*)(uintptr_t)param[3];
    camera = kwlnGetMainCamera();
    width = (f32)*(s32*)(context + 0x2c);
    height = (f32)*(s32*)(context + 0x30);
    x = *(f32*)&param[1] * 640.0f - 100.0f;
    y = *(f32*)&param[2] * 448.0f - 100.0f;
    angle = func_0052ea18(y, x);
    distance = sqrtf(x * x + y * y);
    wave = func_00269c80(fGpffff8248 * (distance / 1200.0f -
                                           width / 180.0f) * 2.0f);
    wave *= 20.0f;
    if (wave > 0.0f)
        wave = -wave;
    scale = distance + wave * (distance / 400.0f);
    (void)func_00269c80(fGpffff8248 * (distance / 640.0f -
                                       height / 512.0f) * 2.0f);
    sine = func_00269c80(angle);
    cosine = func_00269ca0(angle);
    wave = sine * scale + 100.0f;
    scale = cosine * scale + 100.0f;
    alpha = (fGpffff839c * (1.0f -
             func_00269c80(fGpffff8248 * (distance / 1200.0f +
             cosine / fGpffff81f8) * 2.0f) * 0.5f + 0.5f) +
             fGpffff82fc) * 255.0f * *(f32*)(context + 0x1178);
    vertex = opWaitVertex(param);
    opWaitSetVertex(vertex, *(f32*)&param[1] * 640.0f,
                    *(f32*)&param[2] * 448.0f,
                    scale / 640.0f, wave / 448.0f,
                    alpha, 1.0f / camera->nearPlane);
}

// FUN_002716D0 NONMATCHING
void func_002716d0(u32* param)
{
    u8* context;
    RwIm2DVertex* vertex;
    RwCamera* camera;
    f32 width;
    f32 height;
    f32 x;
    f32 y;
    f32 angle;
    f32 distance;
    f32 wave;
    f32 scale;

    context = (u8*)(uintptr_t)param[3];
    camera = kwlnGetMainCamera();
    width = (f32)*(s32*)(context + 0x2c);
    height = (f32)*(s32*)(context + 0x30);
    x = *(f32*)&param[1] * 640.0f;
    y = *(f32*)&param[2] * 448.0f;
    angle = func_0052ea18(y, x);
    distance = sqrtf(x * x + y * y);
    wave = func_00269c80(fGpffff8248 * (distance / 1200.0f -
                                           width / 180.0f) * 2.0f);
    wave = fGpffff8294 * wave + angle;
    scale = func_00269c80(fGpffff8248 * (distance / 30.0f) * 3.0f -
                          distance / 100.0f);
    scale = func_00269c80(fGpffff8248 *
                          (fGpffff82fc * scale + distance / 1200.0f +
                           angle / fGpffff81f8) * 2.0f);
    wave = fGpffff82fc * scale + fGpffff839c;
    vertex = opWaitVertex(param);
    opWaitSetVertex(vertex, x, y, *(f32*)&param[1], *(f32*)&param[2],
                    wave * 204.0f * *(f32*)(context + 0x1178),
                    1.0f / camera->nearPlane);
}

// FUN_00271C10
void func_00271c10(void)
{
    u32* work;

    K_ASSERT(sOpWait != NULL, 0xdb);
    work = sOpWait;
    K_ASSERT((*work & 4) != 0, 0x7fe);
    K_ASSERT(work[1] == 0, 0x7ff);
    if ((s32)work[2] < 0xdc)
    {
        work[2] = 0xdc;
        work[10] = 0xdc;
        *work &= ~8u;
    }
}
