#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/Social/sfl_psel.h"
#include "Main/Social/sfl_res.h"

static u32* sSflPsel; // puGpffffb688
u32 FUN_0021cca0();
void FUN_0021d3b0();
float FUN_0021ea00();
void FUN_0021eac0(void*, float);
void FUN_00260c20();
void FUN_00261480();
extern void FUN_0021d8e0(void*, const void*);
extern void FUN_0021d950(void*, const void*);
extern void (*D_00960090)(u32, u32);
extern void (*D_0096009C)(u32*, u32, u32, u32, u32);
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
#pragma alias D_0096009C_abs D_0096009C
extern u8 D_0096009C_abs[];
extern void RpSkyRenderStateSet(u32, void*);
extern void func_004d7f60(s32 state, u32 value);
extern float fGpffff8300;
extern char D_00960088[];
extern u32 uGpffffb948;
extern u16 DAT_007e0952;
#pragma alias DAT_007e0952_a DAT_007e0952
extern u16 DAT_007e0952_a[8];
extern u32 func_00173220(u16 id);
extern u32 func_00173280(u16 id);
extern u8* DAT_007ce420;
extern u32 func_00175410(void);
extern u32 func_001756f0(void);
extern void* func_001749a0(u16 id);
extern DatPersonaWork* datPersonaGetHeroPersona(s16 index);
extern DatPersonaWork* datPersonaGetByPcId(u16 pcId);
extern u32 func_0010a4e0(s32 bank, s32 cue, s32 variant, s32 pan);
extern u32 func_0021cca0(u32 texture, s32 frame);
extern u32 func_0021cce0(u32 frame);
extern void func_0021d3b0(void* destination, u32 frame);
extern void func_0021d8e0(void* destination, const f32* rect);
extern void func_0021d950(void* destination, const u8* color);
extern void func_0021e380(void* destination, u32 frame, s32 mode);
extern f32 func_0021ea00(s32 duration);
extern void func_0021eac0(void* animation, f32 value);
extern void func_00238980(void* destination, s32 count, u32 value, s32 mode);
extern void* func_00238dc0(void* destination, s32 count, u32 value, s32 mode, const f32* origin);
extern u32 func_00239140(s32 font);
extern void func_0024a260(u32* state);
extern u32 func_003b0970(u32 resource, s32 mode, s8 group, s32 a, s32 b);
extern void func_003b0d70(u32 resource, s32 x, s32 y);
extern void func_003b0e20(u32 resource, u32 color);
extern void func_003b0e70(s32 mode);
extern void func_003b0e90(s32 mode);
extern void func_003b1360(u32 resource, s32 mode, s32 value);
extern void func_003b0170(u32 resource);
extern void frFontSetTextScale(u32 resource, f32 value);
extern u32 func_003c7610(void);
extern void func_003c7650(s32 mode);
extern u32 func_003c7850(void);
extern u32 func_003c78d0(void);
extern void func_003c7990(s32 mode);
extern void func_003c7bc0(s32 mode, u32 value);
extern void func_003c7430(u32 value);
extern void sflPersonaLoad(u16 id);
extern void sflPersonaSetPersona(u16 id);
extern void sflPersonaDestroy(void);
extern u32 sflPersonaIsLoading(void);
extern void sflPersonaStartExitTransition(void);
extern u32 sflPersonaIsTransitioning(void);
extern void func_00523ac8(char* destination, const char* format, ...);
extern s32 func_00524388(const char* text);
extern void func_0019d3f0(const char* file, s32 line);
extern char D_0068e228[];
extern void func_003c74e0(u32 value);

typedef void (*SflPselStateCallback)(u32 state, u32 value);
typedef void (*SflPselDrawCallback)(void* quad, u32 layer, u32 group, u32 pass, u32 blend);

extern u32 FUN_0021cce0(u32 frame);

static inline u8* sflPselBytes(u32* work, u32 offset)
{
    return (u8*)work + offset;
}

static u32 sflPselReadU32(const void* object, u32 offset)
{
    return *(const u32*)((const u8*)object + offset);
}

static inline s32 sflPselReadS32(const void* object, u32 offset)
{
    return *(const s32*)((const u8*)object + offset);
}

static u8* sflPselEntry(u32* work, s32 index)
{
    u8* entries;

    entries = (u8*)(uintptr_t)sflPselReadU32(work, 0x184);
    return entries + index * 0x80;
}

static inline void sflPselSetAlpha(void* object, u8 alpha)
{
    u8 color[4];

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = alpha;
    FUN_0021d950(object, color);
}

static void sflPselDraw(void* object)
{
    D_0096009C((u32*)object, 4, 0, 1, 2);
    D_0096009C((u32*)object, 4, 0, 2, 3);
}

// FUN_00260430
void sflPsel00260430(u32* base, s32 index, float* uv, u32 axis)
{
    u8* entry;
    u8* resource;
    u32 xMode;
    s32 width;
    s32 height;

    entry = (u8*)(uintptr_t)(base[0x61] + (index << 7));
    resource = (u8*)(uintptr_t)base[0x41 + *(u32*)(entry + 0x14)];
    {
        f32 x[2] = {0.0f, 0.0f};
        x[0] = (f32)*(s32*)(entry + 0x54);
        x[1] = (f32)*(s32*)(entry + 0x5c);
        {
            f32 y[2] = {0.0f, 0.0f};
            y[0] = (f32)*(s32*)(entry + 0x58);
            y[1] = (f32)*(s32*)(entry + 0x60);
            width = *(s32*)(resource + 0xc);
            height = *(s32*)(resource + 0x10);

            switch (axis) {
            case 0: xMode = 0; axis = 1; break;
            case 1: xMode = 2; axis = 0; break;
            case 2: xMode = 0; axis = 2; break;
            case 3: xMode = 1; axis = 0; break;
            case 4: xMode = 2; axis = 1; break;
            case 5: xMode = 2; axis = 2; break;
            case 6: xMode = 2; axis = 1; break;
            case 7: xMode = 1; axis = 1; break;
            }

            switch (xMode) {
            case 0:
                if (((~*(u32*)(entry + 0x18)) & 1) != 0) {
                    uv[0] = x[0] / (f32)width;
                    uv[2] = x[1] / (f32)width;
                } else {
                    uv[0] = x[1] / (f32)width;
                    uv[2] = x[0] / (f32)width;
                }
                break;
            case 1:
                if (((~*(u32*)(entry + 0x18)) & 1) != 0) {
                    uv[0] = x[0] / (f32)width;
                    uv[2] = (x[0] + 1.0f) / (f32)width;
                } else {
                    uv[0] = x[1] / (f32)width;
                    uv[2] = (x[1] - 1.0f) / (f32)width;
                }
                break;
            case 2:
                if (((~*(u32*)(entry + 0x18)) & 1) != 0) {
                    uv[0] = (x[1] - 1.0f) / (f32)width;
                    uv[2] = x[1] / (f32)width;
                } else {
                    uv[0] = (x[0] + 1.0f) / (f32)width;
                    uv[2] = x[0] / (f32)width;
                }
                break;
            }

            switch (axis) {
            case 0:
                if (((~*(u32*)(entry + 0x18)) & 2) != 0) {
                    uv[1] = y[0] / (f32)height;
                    uv[3] = y[1] / (f32)height;
                } else {
                    uv[1] = y[1] / (f32)height;
                    uv[3] = y[0] / (f32)height;
                }
                break;
            case 1:
                if (((~*(u32*)(entry + 0x18)) & 2) != 0) {
                    uv[1] = y[0] / (f32)height;
                    uv[3] = (y[0] + 1.0f) / (f32)height;
                } else {
                    uv[1] = y[1] / (f32)height;
                    uv[3] = (y[1] - 1.0f) / (f32)height;
                }
                break;
            case 2:
                if (((~*(u32*)(entry + 0x18)) & 2) != 0) {
                    uv[1] = (y[1] - 1.0f) / (f32)height;
                    uv[3] = y[1] / (f32)height;
                } else {
                    uv[1] = (y[0] + 1.0f) / (f32)height;
                    uv[3] = y[0] / (f32)height;
                }
                break;
            }
        }
    }
}

// FUN_00260900
s32 sflPsel00260900(u32* base, s32 index)
{
    u8* entry;

    entry = (u8*)(uintptr_t)(base[0x61] + (index << 7));
    return *(s32*)(entry + 0x5c) - *(s32*)(entry + 0x54);
}

// FUN_00260920
s32 sflPsel00260920(u32* base, s32 index)
{
    u8* entry;

    entry = (u8*)(uintptr_t)(base[0x61] + (index << 7));
    return *(s32*)(entry + 0x60) - *(s32*)(entry + 0x58);
}

// FUN_00260940
u32 sflPsel00260940(u32* base, s32 index)
{
    u8* entry;

    entry = (u8*)(uintptr_t)(base[0x61] + (index << 7));
    return base[0x41 + *(u32*)(entry + 0x14)];
}

// FUN_00260970
void sflPsel00260970(u8* work)
{
    float frame[4];
    u8 color[4];

    *(u32*)work = 0;
    frame[0] = 0.0f;
    frame[1] = 0.0f;
    frame[2] = 640.0f;
    frame[3] = 448.0f;
    FUN_0021d8e0(work + 0x310, frame);
    FUN_0021eac0(work + 0x310, FUN_0021ea00(10));
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = 0;
    FUN_0021d950(work + 0x310, color);
    sSflPsel = (u32*)work;
}

// FUN_00260D20
void sflPsel00260d20(void)
{
    u32* work;

    K_ASSERT(sSflPsel != NULL, 0x57);
    work = sSflPsel;
    if (((~*work) & 1) != 0)
        return;

    switch (work[1])
    {
    case 0:
        if ((s32)work[2] < 10)
            work[2] += 1;
        else
            *work &= ~2u;
        break;
    case 1:
        if ((s32)work[2] < 10)
            work[2] += 1;
        else
            *work &= ~2u;
        break;
    }
    FUN_00261480();
}

// FUN_00260e00 NONMATCHING
void sflPsel00260e00(void)
{
    u32* work;
    u32 texture;
    SflPselStateCallback* state;
    SflPselDrawCallback* draw;

    K_ASSERT(sSflPsel != NULL, 0x57);
    work = sSflPsel;
    if (((~*work) & 1) != 0)
        return;

    texture = sflResGetPersonaChangeSprite();
    state = (SflPselStateCallback*)D_00960090_abs;
    (*state)(9, 2);
    (*state)(0x14, 2);
    (*state)(8, 1);
    (*state)(6, 0);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*state)(1, 0);
    draw = (SflPselDrawCallback*)D_0096009C_abs;
    (*draw)((u32*)((u8*)work + 0x310), 4, 0, 1, 2);
    (*draw)(&work[0xc4], 4, 0, 2, 3);

    (*state)(0x14, 2);
    (*state)(8, 1);
    (*state)(6, 0);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*state)(1, 0);
    (*draw)((u32*)((u8*)work + 0x10), 4, 0, 1, 2);
    (*draw)(&work[4], 4, 0, 2, 3);

    (*state)(8, 0);
    (*state)(6, 1);
    (*state)(1, FUN_0021cce0(FUN_0021cca0(texture, 0x3a)));
    (*draw)((u32*)((u8*)work + 0x710), 4, 0, 1, 2);
    (*draw)(&work[0x1c4], 4, 0, 2, 3);
    (*state)(1, 0);
    (*draw)((u32*)((u8*)work + 0x810), 4, 0, 1, 2);
    (*draw)(&work[0x204], 4, 0, 2, 3);

    (*state)(8, 1);
    (*state)(6, 1);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*state)(6, 1);
    (*state)(6, 1);
    (*state)(8, 1);
    (*state)(1, 0);
    (*draw)((u32*)((u8*)work + 0x210), 4, 0, 1, 2);
    (*draw)(&work[0x84], 4, 0, 2, 3);

    switch (work[1])
    {
    case 0:
        (*state)(6, 0);
        draw = (SflPselDrawCallback*)D_0096009C_abs;
        (*state)(8, 1);
        (*state)(1, 0);
        (*draw)((u32*)((u8*)work + 0x110), 4, 0, 1, 2);
        (*draw)(&work[0x44], 4, 0, 2, 3);
        break;
    case 1:
        (*state)(6, 0);
        draw = (SflPselDrawCallback*)D_0096009C_abs;
        (*state)(8, 1);
        (*state)(1, 0);
        (*draw)((u32*)((u8*)work + 0x110), 4, 0, 1, 2);
        (*draw)(&work[0x44], 4, 0, 2, 3);
        break;
    }

    (*state)(6, 1);
    (*state)(6, 1);
    (*state)(8, 0);
    (*state)(1, FUN_0021cce0(FUN_0021cca0(texture, 0x34)));
    (*draw)((u32*)((u8*)work + 0x410), 4, 0, 1, 2);
    (*draw)(&work[0x104], 4, 0, 2, 3);
    (*state)(1, FUN_0021cce0(FUN_0021cca0(texture, 0x35)));
    (*draw)((u32*)((u8*)work + 0x510), 4, 0, 1, 2);
    (*draw)(&work[0x144], 4, 0, 2, 3);
    (*state)(1, FUN_0021cce0(FUN_0021cca0(texture, 0x36)));
    (*draw)((u32*)((u8*)work + 0x610), 4, 0, 1, 2);
    (*draw)(&work[0x184], 4, 0, 2, 3);
}

extern void FUN_0021d890(void*, const void*);

// Reconstructed the complete retail animation path, including all quad states.
// The original source omitted dynamic frame branches and contiguous color writes.
// Restoring these stores increases the instruction window while preserving logic.
// Remaining differences are primarily MWCC register allocation and scheduling.
// This function remains NONMATCHING until those code-generation details converge.
// FUN_00261480 NONMATCHING
void sflPsel00261480(void)
{
    u8 color[4];
    u32* work;
    u32 texture;
    u8* resource34;
    f32 points[8];
    f32 diagonal;
    f32 alpha;
    s32 channel;
    f32 channelFloat;
    s32 frame;
    s32 mode;

    K_ASSERT(sSflPsel != NULL, 0x57);
    work = sSflPsel;
    texture = sflResGetPersonaChangeSprite();
    resource34 = (u8*)(uintptr_t)FUN_0021cca0(texture, 0x34);
    frame = (s32)work[2];
    mode = (s32)work[1];
    diagonal = 1.4142135f;

    switch (mode) {
    case 0:
        alpha = 1.0f;
        if (frame < 5) {
            points[0] = -(6.0f + (f32)sflPselReadS32(resource34, 0x10)) +
                        ((f32)frame / 10.0f) *
                        (12.0f + (f32)sflPselReadS32(resource34, 0x10));
            points[1] = 6.0f + (f32)sflPselReadS32(resource34, 0x10) -
                        ((f32)frame / 10.0f) *
                        (f32)sflPselReadS32(resource34, 0x10);
        } else {
            points[0] = 6.0f;
            points[1] = 6.0f;
        }
        break;
    case 1:
        channelFloat = frame < 3 ? (f32)frame / 3.0f : 1.0f;
        points[0] = channelFloat * 150.0f + 6.0f;
        points[1] = points[0];
        alpha = 1.0f - channelFloat;
        break;
    }
    points[2] = (f32)sflPselReadS32(resource34, 0x0c);
    points[3] = (f32)sflPselReadS32(resource34, 0x10);
    FUN_0021d8e0(sflPselBytes(work, 0x410), points);
    sflPselSetAlpha(sflPselBytes(work, 0x410), (u8)(alpha * 255.0f));
    resource34 = (u8*)(uintptr_t)FUN_0021cca0(texture, 0x35);

    switch (mode) {
    case 0:
        alpha = 1.0f;
        if (frame < 6) {
            points[0] =
                -(109.0f +
                  (f32)sflPselReadS32(
                      (u8*)(uintptr_t)FUN_0021cca0(texture, 0x35), 0x10)) +
                        ((f32)frame / 6.0f) *
                        (225.0f + (f32)sflPselReadS32(resource34, 0x10));
            points[1] = 109.0f + (f32)sflPselReadS32(resource34, 0x10) -
                        ((f32)frame / 6.0f) *
                        (87.0f + (f32)sflPselReadS32(resource34, 0x10));
        } else {
            points[0] = 116.0f;
            points[1] = 22.0f;
        }
        break;
    case 1:
        channelFloat = frame < 3 ? (f32)frame / 3.0f : 1.0f;
        points[0] = channelFloat * 150.0f + 23.0f;
        points[1] = channelFloat * 150.0f + 109.0f;
        alpha = 1.0f - channelFloat;
        break;
    }
    points[2] = (f32)sflPselReadS32(resource34, 0x0c);
    points[3] = (f32)sflPselReadS32(resource34, 0x10);
    FUN_0021d8e0(sflPselBytes(work, 0x510), points);
    sflPselSetAlpha(sflPselBytes(work, 0x510), (u8)(alpha * 255.0f));
    resource34 = (u8*)(uintptr_t)FUN_0021cca0(texture, 0x36);

    switch (mode) {
    case 0:
        alpha = 1.0f;
        if (frame < 6) {
            points[0] =
                -(109.0f +
                  (f32)sflPselReadS32(
                      (u8*)(uintptr_t)FUN_0021cca0(texture, 0x36), 0x10)) +
                        ((f32)frame / 6.0f) *
                        (225.0f + (f32)sflPselReadS32(resource34, 0x10));
            points[1] = 109.0f + (f32)sflPselReadS32(resource34, 0x10) -
                        ((f32)frame / 6.0f) *
                        (87.0f + (f32)sflPselReadS32(resource34, 0x10));
        } else {
            points[0] = 116.0f;
            points[1] = 22.0f;
        }
        break;
    case 1:
        channelFloat = frame < 3 ? (f32)frame / 3.0f : 1.0f;
        points[0] = channelFloat * 150.0f + 116.0f;
        points[1] = channelFloat * 150.0f + 22.0f;
        alpha = 1.0f - channelFloat;
        break;
    }
    points[2] = (f32)sflPselReadS32(resource34, 0x0c);
    points[3] = (f32)sflPselReadS32(resource34, 0x10);
    FUN_0021d8e0(sflPselBytes(work, 0x610), points);
    sflPselSetAlpha(sflPselBytes(work, 0x610), (u8)(alpha * 255.0f));

    switch (mode) {
    case 0:
        if (frame < 8) {
            channelFloat = (f32)frame / 8.0f;
            points[0] = 320.0f;
            points[1] = -320.0f;
            points[2] = -224.0f;
            points[3] = 224.0f;
            points[4] = -224.0f + channelFloat * (1088.0f / diagonal);
            points[5] = 224.0f + channelFloat * (1088.0f / diagonal);
            points[6] = 320.0f + channelFloat * (1088.0f / diagonal);
            points[7] = -320.0f + channelFloat * (1088.0f / diagonal);
        } else {
            points[0] = 320.0f;
            points[1] = -320.0f;
            points[2] = -224.0f;
            points[3] = 224.0f;
            points[4] = -224.0f + 1088.0f / diagonal;
            points[5] = 224.0f + 1088.0f / diagonal;
            points[6] = 320.0f + 1088.0f / diagonal;
            points[7] = -320.0f + 1088.0f / diagonal;
        }
        break;
    case 1:
        if (frame < 10) {
            channelFloat = (f32)frame / 10.0f;
            points[0] = 320.0f - (1.0f - channelFloat) *
                        (544.0f - (256.0f - fGpffff8300) / diagonal);
            points[1] = 768.0f - (1.0f - channelFloat) *
                        (544.0f - (256.0f - fGpffff8300) / diagonal);
            points[2] = 864.0f - (1.0f - channelFloat) *
                        (544.0f - (256.0f - fGpffff8300) / diagonal);
            points[3] = 224.0f - (1.0f - channelFloat) *
                        (544.0f - (256.0f - fGpffff8300) / diagonal);
            points[4] = 864.0f;
            points[5] = 224.0f;
            points[6] = 320.0f;
            points[7] = 768.0f;
        } else {
            points[4] = 320.0f + (1088.0f / diagonal) / diagonal;
            points[5] = (1088.0f / diagonal) / diagonal - 320.0f;
            points[6] = (1088.0f / diagonal) / diagonal - 448.0f;
            points[7] = 224.0f + (1088.0f / diagonal) / diagonal;
            points[0] = points[6];
            points[1] = points[7];
            points[2] = points[4];
            points[3] = points[5];
        }
        break;
    }
    FUN_0021d890(sflPselBytes(work, 0x10), points);
    FUN_0021eac0(sflPselBytes(work, 0x10), FUN_0021ea00(0x32));
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    color[3] = 0;
    FUN_0021d950(sflPselBytes(work, 0x10), color);

    switch (mode) {
    case 0:
        points[0] = 320.0f;
        points[1] = -320.0f;
        points[2] = -224.0f;
        points[3] = 224.0f;
        channelFloat = (216.0f / diagonal) / diagonal;
        points[4] = -224.0f + channelFloat;
        points[5] = 224.0f + channelFloat;
        points[6] = 320.0f + channelFloat;
        points[7] = -320.0f + channelFloat;
        alpha = 1.0f;
        break;
    case 1:
        if (frame < 10) {
            channelFloat = (f32)frame / 10.0f;
            points[0] = 320.0f - 40.0f / diagonal +
                        channelFloat * (544.0f -
                        (256.0f - fGpffff8300) / diagonal);
            points[1] = -320.0f - 40.0f / diagonal +
                        channelFloat * (544.0f -
                        (256.0f - fGpffff8300) / diagonal);
            points[2] = -224.0f - 40.0f / diagonal +
                        channelFloat * (544.0f -
                        (256.0f - fGpffff8300) / diagonal);
            points[3] = 224.0f - 40.0f / diagonal +
                        channelFloat * (544.0f -
                        (256.0f - fGpffff8300) / diagonal);
            points[4] = points[2] + (40.0f + 216.0f / diagonal) / diagonal;
            points[5] = points[3] + (40.0f + 216.0f / diagonal) / diagonal;
            points[6] = points[0] + (40.0f + 216.0f / diagonal) / diagonal;
            points[7] = points[1] + (40.0f + 216.0f / diagonal) / diagonal;
            alpha = 1.0f - channelFloat;
        } else {
            alpha = 0.0f;
            points[0] = 0.0f;
            points[1] = 0.0f;
            points[2] = 0.0f;
            points[3] = 0.0f;
            points[4] = 0.0f;
            points[5] = 0.0f;
            points[6] = 0.0f;
            points[7] = 0.0f;
        }
        break;
    }
    FUN_0021d890(sflPselBytes(work, 0x110), points);
    FUN_0021eac0(sflPselBytes(work, 0x110), FUN_0021ea00(0x23));
    color[0] = 4;
    color[1] = 0x29;
    color[2] = 0x46;
    color[3] = (u8)(alpha * 255.0f);
    FUN_0021d950(sflPselBytes(work, 0x110), color);

    switch (mode) {
    case 0:
        channelFloat = (256.0f / diagonal) / diagonal;
        points[0] = 320.0f;
        points[1] = -320.0f;
        points[2] = -224.0f;
        points[3] = 224.0f;
        points[4] = -224.0f + channelFloat;
        points[5] = 224.0f + channelFloat;
        points[6] = 320.0f + channelFloat;
        points[7] = -320.0f + channelFloat;
        break;
    case 1:
        if (frame < 10) {
            channelFloat = (f32)frame / 10.0f;
            points[0] = 320.0f - 40.0f / diagonal +
                        channelFloat * (544.0f -
                        (256.0f / diagonal - fGpffff8300) / diagonal);
            points[1] = -320.0f - 40.0f / diagonal +
                        channelFloat * (544.0f -
                        (256.0f / diagonal - fGpffff8300) / diagonal);
            points[2] = -224.0f - 40.0f / diagonal +
                        channelFloat * (544.0f -
                        (256.0f / diagonal - fGpffff8300) / diagonal);
            points[3] = 224.0f - 40.0f / diagonal +
                        channelFloat * (544.0f -
                        (256.0f / diagonal - fGpffff8300) / diagonal);
            points[4] = points[2] + (40.0f + 216.0f / diagonal) / diagonal;
            points[5] = points[3] + (40.0f + 216.0f / diagonal) / diagonal;
            points[6] = points[0] + (40.0f + 216.0f / diagonal) / diagonal;
            points[7] = points[1] + (40.0f + 216.0f / diagonal) / diagonal;
        } else {
            channelFloat = 0.0f;
            points[0] = 0.0f;
            points[1] = 0.0f;
            points[2] = 0.0f;
            points[3] = 0.0f;
            points[4] = 0.0f;
            points[5] = 0.0f;
            points[6] = 0.0f;
            points[7] = 0.0f;
        }
        break;
    }
    FUN_0021d890(sflPselBytes(work, 0x210), points);
    FUN_0021eac0(sflPselBytes(work, 0x210), FUN_0021ea00(0x23));
    color[0] = 0x4f;
    color[1] = 0xa4;
    color[2] = 0xff;
    color[3] = 0xff;
    FUN_0021d950(sflPselBytes(work, 0x210), color);

    points[0] = 0.0f;
    points[1] = 0.0f;
    points[2] = 640.0f;
    points[3] = 448.0f;
    FUN_0021d8e0(sflPselBytes(work, 0x710), points);
    sflPselSetAlpha(sflPselBytes(work, 0x710), 0xff);

    *(f32*)sflPselBytes(work, 0x810) = 517.0f;
    *(f32*)sflPselBytes(work, 0x814) = 448.0f;
    *(f32*)sflPselBytes(work, 0x850) = 640.0f;
    *(f32*)sflPselBytes(work, 0x854) = 325.0f;
    *(f32*)sflPselBytes(work, 0x890) = 640.0f;
    *(f32*)sflPselBytes(work, 0x894) = 448.0f;

    color[0] = 0x4f;
    color[1] = 0xa4;
    color[2] = 0xff;
    color[3] = 0xff;
    channel = color[0];
    channelFloat = (f32)(u32)channel;
    *(f32*)sflPselBytes(work, 0x830) = channelFloat;
    channel = color[1];
    channelFloat = (f32)(u32)channel;
    *(f32*)sflPselBytes(work, 0x834) = channelFloat;
    channel = color[2];
    channelFloat = (f32)(u32)channel;
    *(f32*)sflPselBytes(work, 0x838) = channelFloat;
    channel = color[3];
    channelFloat = (f32)(u32)channel;
    *(f32*)sflPselBytes(work, 0x83c) = channelFloat;
    channel = color[0];
    channelFloat = (f32)(u32)channel;
    *(f32*)sflPselBytes(work, 0x870) = channelFloat;
    channel = color[1];
    channelFloat = (f32)(u32)channel;
    *(f32*)sflPselBytes(work, 0x874) = channelFloat;
    channel = color[2];
    channelFloat = (f32)(u32)channel;
    *(f32*)sflPselBytes(work, 0x878) = channelFloat;
    channel = color[3];
    channelFloat = (f32)(u32)channel;
    *(f32*)sflPselBytes(work, 0x87c) = channelFloat;
    channel = color[0];
    channelFloat = (f32)(u32)channel;
    *(f32*)sflPselBytes(work, 0x8b0) = channelFloat;
    channel = color[1];
    channelFloat = (f32)(u32)channel;
    *(f32*)sflPselBytes(work, 0x8b4) = channelFloat;
    channel = color[2];
    channelFloat = (f32)(u32)channel;
    *(f32*)sflPselBytes(work, 0x8b8) = channelFloat;
    channel = color[3];
    channelFloat = (f32)(u32)channel;
    *(f32*)sflPselBytes(work, 0x8bc) = channelFloat;
}

// FUN_00260a10
void sflPsel00260a10(void)
{
    K_ASSERT(sSflPsel != NULL, 0x57);
    sSflPsel = NULL;
}

// FUN_00260bd0
void sflPsel00260bd0(void)
{
    K_ASSERT(sSflPsel != NULL, 0x57);
    *sSflPsel &= 0xfffffffe;
}

// FUN_00260c20
void sflPsel00260c20(void)
{
    u32* work;

    K_ASSERT(sSflPsel != NULL, 0x57);
    work = sSflPsel;
    work[2] = 0;
    work[1] = 0;
    *work |= 2;
}

// FUN_00260c70
void sflPsel00260c70(void)
{
    u32* work;

    K_ASSERT(sSflPsel != NULL, 0x57);
    work = sSflPsel;
    work[2] = 0;
    work[1] = 1;
    *work |= 2;
}

// FUN_00260cd0
u32 sflPsel00260cd0(void)
{
    K_ASSERT(sSflPsel != NULL, 0x57);
    return *sSflPsel & 2;
}

// FUN_00260a50
void sflPsel00260a50(void)
{
    u32* puVar1;
    u32 uVar2;
    u32 uVar3;
    float fVar4;
    float fVar5;

    K_ASSERT(sSflPsel != NULL, 0x57);
    puVar1 = sSflPsel;
    uVar2 = sflResGetPersonaChangeSprite();
    uVar3 = FUN_0021cca0(uVar2, 0x34);
    FUN_0021d3b0(puVar1 + 0x104, uVar3);
    fVar4 = FUN_0021ea00(0x1e);
    FUN_0021eac0(puVar1 + 0x104, fVar4);
    uVar3 = FUN_0021cca0(uVar2, 0x35);
    FUN_0021d3b0(puVar1 + 0x144, uVar3);
    fVar4 = FUN_0021ea00(0x1e);
    FUN_0021eac0(puVar1 + 0x144, fVar4);
    uVar3 = FUN_0021cca0(uVar2, 0x36);
    FUN_0021d3b0(puVar1 + 0x184, uVar3);
    fVar4 = FUN_0021ea00(0x1e);
    FUN_0021eac0(puVar1 + 0x184, fVar4);
    uVar3 = FUN_0021cca0(uVar2, 0x3a);
    FUN_0021d3b0(puVar1 + 0x1c4, uVar3);
    fVar4 = FUN_0021ea00(0x32);
    FUN_0021eac0(puVar1 + 0x1c4, fVar4);
    fVar5 = FUN_0021ea00(0x32);
    ((float*)puVar1)[0x206] = fVar5;
    ((float*)puVar1)[0x216] = fVar5;
    ((float*)puVar1)[0x226] = fVar5;
    FUN_00260c20();
    FUN_00261480();
    *puVar1 |= 1;
}
// FUN_00215A50
void func_00215a50(u32* work)
{
    if (sSflPsel != NULL)
    {
        K_ASSERT(0, 0xd1);
    }
    work[0] = 0;
    work[1] = 0;
    sSflPsel = work;
}

// FUN_00215AA0
void func_00215aa0(void)
{
    K_ASSERT(sSflPsel != NULL, 0xcb);
    if ((*sSflPsel & 1) != 0)
    {
        func_00216800();
    }
    sSflPsel = NULL;
}

// FUN_00215B00 NONMATCHING
void func_00215b00(void)
{
    u8* work;
    DatPersonaWork* hero;
    u32 heroCount;
    u32 totalCount;
    u32 count;
    u32 texture;
    u32 i;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    work = (u8*)sSflPsel;
    texture = sflResGetPersonaChangeSprite();
    hero = datPersonaGetByPcId(1);
    heroCount = func_001756f0() & 0xffff;
    totalCount = func_00175410() & 0xffff;
    *(u32*)(work + 8) = totalCount;
    count = *(u32*)(work + 4);
    for (i = 0; i < heroCount; i++)
    {
        DatPersonaWork* persona;
        u8* entry;

        persona = datPersonaGetHeroPersona((s16)i);
        entry = work + 0x10 + count * 0x10;
        *(u32*)entry = 0;
        *(u16*)(entry + 4) = persona->id;
        if (persona->id != hero->id)
        {
            count++;
        }
    }
    *(u32*)(work + 4) = count;
    *(f32*)(work + 0x5c40) = 1.0f;
    if ((s32)count < 9)
    {
        *(u32*)(work + 0xc) = count;
    }
    else
    {
        *(u32*)(work + 0xc) = 8;
    }
    for (i = 0; i < count; i++)
    {
        *(u32*)(work + 0x52e0 + i * 4) = i;
    }
    *(u32*)(work + 0x5330) = count;
    for (i = 0; i < count; i++)
    {
        u8* entry;
        u16 id;

        entry = work + 0x10 + i * 0x10;
        id = *(u16*)(entry + 4);
        if ((*(u32*)entry & 2) != 0)
        {
            *(u32*)(entry + 0xc) = DAT_007ce420[(u32)id * 0xe + 3];
        }
        else
        {
            *(u32*)(entry + 0xc) = ((u8*)func_001749a0(id))[4];
        }
        *(u32*)(entry + 8) = func_00173280(id) & 0xff;
    }
    {
        u32 frame;

        frame = func_0021cca0(texture, 0x31);
        func_0021d3b0(work + 0x5340, frame);
        func_0021eac0(work + 0x5340, func_0021ea00(0x28));
        frame = func_0021cca0(texture, 0x32);
        func_0021d3b0(work + 0x5440, frame);
        func_0021eac0(work + 0x5440, func_0021ea00(0x28));
        frame = func_0021cca0(texture, 0x38);
        func_0021d3b0(work + 0x5540, frame);
        func_0021eac0(work + 0x5540, func_0021ea00(0x28));
        frame = func_0021cca0(texture, 0x39);
        func_0021d3b0(work + 0x5640, frame);
        func_0021eac0(work + 0x5640, func_0021ea00(0x28));
        frame = func_0021cca0(texture, 0x33);
        func_0021d3b0(work + 0x5740, frame);
        func_0021eac0(work + 0x5740, func_0021ea00(0x28));
    }
    *(u32*)(work + 0x5c5c) = 0;
    *(u32*)(work + 0x5c68) = 0;
    *(u32*)(work + 0x5c60) = 0;
    *(u32*)(work + 0x5c64) = *(u32*)(work + 0xc);
    *(u32*)(work + 0x5c6c) = *(u32*)(work + 4);
    *(u32*)(work + 0x5c5c) |= 4;
    for (i = 0; i < 8; i++)
    {
        *(u8*)(work + 0x5c70 + i * 4) = 0;
        *(u8*)(work + 0x5c71 + i * 4) = 0;
        *(u8*)(work + 0x5c72 + i * 4) = 0;
    }
    *(u8*)(work + 0x5c73) = 0;
    *(u8*)(work + 0x5c77) = 0;
    *(u8*)(work + 0x5c7b) = 0;
    *(u8*)(work + 0x5c7f) = 0;
    *(u8*)(work + 0x5c87) = 0;
    *(u8*)(work + 0x5c83) = 0;
    *(u8*)(work + 0x5c8f) = 0;
    *(u8*)(work + 0x5c8b) = 0;
    func_002170c0();
    func_00217610();
    sflPsel00260a50();
    func_002187b0();
    func_0021d3b0(work + 0x5f90, func_0021cca0(texture, 0x1d));
    func_0021eac0(work + 0x5f90, func_0021ea00(0x28));
    texture = func_0021cca0(texture, 0x1e);
    func_0021d3b0(work + 0x5c90, texture);
    func_0021eac0(work + 0x5c90, func_0021ea00(0x28));
    func_0021e380(work + 0x5d90, texture, 2);
    func_0021eac0(work + 0x5d90, func_0021ea00(0x28));
    texture = func_0021cca0(sflResGetPersonaChangeSprite(), 0x1f);
    func_0021d3b0(work + 0x5e90, texture);
    func_0021eac0(work + 0x5e90, func_0021ea00(0x28));
    *(u32*)(work + 0x5334) = 0;
    *(u32*)(work + 0x5338) = 0;
    *sSflPsel |= 0x20;
    *sSflPsel |= 1;
}

// FUN_00215FC0 NONMATCHING
void func_00215fc0(void)
{
    u8* work;
    u32 flags;
    u32 updateFlags;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    work = (u8*)sSflPsel;
    sflPsel00260d20();
    flags = *(u32*)work;
    if ((~flags & 1) != 0)
    {
        return;
    }
    if ((flags & 4) != 0)
    {
        switch (*(u32*)(work + 0x5c48))
        {
        case 0:
        {
            u32 frame = *(u32*)(work + 0x5c44) + 1;
            *(u32*)(work + 0x5c44) = frame;
            if (frame == 6)
            {
                *(u32*)work &= ~4u;
            }
            *(f32*)(work + 0x5c40) = 1.0f - (f32)*(s32*)(work + 0x5c44) / 6.0f;
            break;
        }
        case 1:
        {
            u32 frame = *(u32*)(work + 0x5c44) + 1;
            *(u32*)(work + 0x5c44) = frame;
            if (frame == 6)
            {
                *(u32*)work &= ~4u;
            }
            *(f32*)(work + 0x5c40) = (f32)*(s32*)(work + 0x5c44) / 6.0f;
            break;
        }
        }
    }
    if ((*(u32*)work & 0x10) != 0)
    {
        switch (*(u32*)(work + 0x5c54))
        {
        case 0:
        {
            u32 frame = *(u32*)(work + 0x5c50) + 1;
            *(u32*)(work + 0x5c50) = frame;
            if (frame == 3)
            {
                func_00219b00();
                *(u32*)work &= ~0x10u;
            }
            *(f32*)(work + 0x5c4c) = 1.0f - (f32)*(s32*)(work + 0x5c50) / 3.0f;
            break;
        }
        case 1:
        {
            u32 frame = *(u32*)(work + 0x5c50) + 1;
            *(u32*)(work + 0x5c50) = frame;
            if (frame == 3)
            {
                *(u32*)work &= ~0x10u;
            }
            *(f32*)(work + 0x5c4c) = (f32)*(s32*)(work + 0x5c50) / 3.0f;
            break;
        }
        }
    }
    updateFlags = 0;
    switch (*(u32*)(work + 0x5334))
    {
    case 0:
        switch (*(u32*)(work + 0x5338))
        {
        case 3:
            (*(u32*)(work + 0x5338))++;
            break;
        case 4:
            *(u32*)(work + 0x5338) = 0;
            break;
        case 0:
            if ((*(u32*)work & 0x10) == 0)
            {
                if ((DAT_007e0952_a[0] & 0x40) != 0)
                {
                    func_00219b90();
                    break;
                }
                if ((DAT_007e0952_a[0] & 0x80) != 0)
                {
                    func_0010a4e0(0, 0, 0, 0);
                    sflPersonaLoad((u16)*(u16*)(work + 0x10 +
                                                *(u32*)(work + 0x52e0 + *(u32*)(work + 0x5c68) * 4) *
                                                    0x10 + 4));
                    *(u32*)(work + 0x5338) = 1;
                    break;
                }
            }
            *(u32*)(work + 0x5c5c) &= ~1u;
            func_0024a260((u32*)(work + 0x5c5c));
            if ((*(u32*)(work + 0x5c5c) & 1) != 0)
            {
                updateFlags |= 3;
            }
            break;
        case 1:
            if (sflPersonaIsLoading() == 0 && sflPersonaIsTransitioning() == 0)
            {
                if ((DAT_007e0952_a[0] & 0x40) != 0)
                {
                    *(u32*)(work + 0x6090) = 0;
                    sflPersonaStartExitTransition();
                    *(u32*)(work + 0x5338) = 2;
                }
                else if ((DAT_007e0952_a[0] & 0x20) != 0)
                {
                    func_0010a4e0(0, 0, 0, 2);
                    *(u32*)(work + 0x6090) = 1;
                    sflPersonaStartExitTransition();
                    *(u32*)(work + 0x5338) = 2;
                }
                else if ((DAT_007e0952_a[0] & 8) != 0)
                {
                    u32 current = *(u32*)(work + 0x5c68);
                    u32 total = *(u32*)(work + 0x5c6c);
                    if (current < total - 1)
                    {
                        current++;
                        *(u32*)(work + 0x5c68) = current;
                        if (current >= *(u32*)(work + 0x5c60) + *(u32*)(work + 0x5c64) - 1 &&
                            *(u32*)(work + 0x5c60) < total - *(u32*)(work + 0x5c64))
                        {
                            (*(u32*)(work + 0x5c60))++;
                        }
                    }
                    else
                    {
                        *(u32*)(work + 0x5c68) = 0;
                        *(u32*)(work + 0x5c60) = 0;
                    }
                    updateFlags |= 3;
                    func_0010a4e0(0, 0, 0, 0);
                    sflPersonaSetPersona((u16)*(u16*)(work + 0x10 +
                                                *(u32*)(work + 0x52e0 + *(u32*)(work + 0x5c68) * 4) *
                                                    0x10 + 4));
                }
                else if ((DAT_007e0952_a[0] & 4) != 0)
                {
                    u32 current = *(u32*)(work + 0x5c68);
                    u32 total = *(u32*)(work + 0x5c6c);
                    if (current > 0)
                    {
                        current--;
                        *(u32*)(work + 0x5c68) = current;
                        if (*(u32*)(work + 0x5c60) >= current &&
                            *(u32*)(work + 0x5c60) > 0)
                        {
                            (*(u32*)(work + 0x5c60))--;
                        }
                    }
                    else
                    {
                        *(u32*)(work + 0x5c68) = total - 1;
                        *(u32*)(work + 0x5c60) = total - *(u32*)(work + 0x5c64);
                    }
                    updateFlags |= 3;
                    func_0010a4e0(0, 0, 0, 0);
                    sflPersonaSetPersona((u16)*(u16*)(work + 0x10 +
                                                *(u32*)(work + 0x52e0 + *(u32*)(work + 0x5c68) * 4) *
                                                    0x10 + 4));
                }
            }
            break;
        case 2:
            if (sflPersonaIsTransitioning() == 0)
            {
                sflPersonaDestroy();
                if (*(u32*)(work + 0x6090) == 1)
                {
                    *(u32*)(work + 0x5338) = 3;
                }
                else if (*(u32*)(work + 0x6090) == 0)
                {
                    func_00219b90();
                }
            }
            break;
        }
        break;
    case 1:
        func_003c7990(0);
        if (func_003c7850() == 0)
        {
            *(u32*)(work + 0x5334) = 2;
        }
        break;
    case 2:
        if (func_003c78d0() == 0)
        {
            u32 result = func_003c7610();
            if (result == 1)
            {
                func_003c7650(0);
                func_002187b0();
                func_00219ab0();
                *(u32*)(work + 0x5334) = 0;
                *(u32*)(work + 0x5338) = 0;
            }
            else if (result == 0)
            {
                u32 selected = *(u32*)(work + 0x52e0 + *(u32*)(work + 0x5c68) * 4);
                u32 i;
                u32 total;

                func_003c7650(0);
                func_002172c0();
                for (i = *(u32*)(work + 0x5c68), total = *(u32*)(work + 0x5330) - 1;
                     i < total; i++)
                {
                    *(u32*)(work + 0x52e0 + i * 4) =
                        *(u32*)(work + 0x52e0 + (i + 1) * 4);
                }
                *(u32*)(work + 0x5330) = total;
                *(u32*)(work + 0xc) = total < 9 ? total : 8;
                *(u32*)(work + 0x5c68) = 0;
                *(u32*)(work + 0x5c60) = 0;
                *(u32*)(work + 0x5c64) = *(u32*)(work + 0xc);
                *(u32*)(work + 0x5c6c) = *(u32*)(work + 0x5330);
                updateFlags = 2;
                *(u32*)(work + 0x10 + selected * 0x10) |= 1;
                func_002170c0();
                func_003c7bc0(0, func_00173220(*(u16*)(work + 0x10 + selected * 0x10 + 4)));
                func_003c7430(0x2f);
                *(u32*)(work + 0x5334) = 3;
            }
        }
        break;
    case 3:
        func_003c7990(1);
        if (func_003c7850() == 0)
        {
            func_003c7650(1);
            if (*(u32*)(work + 0x5330) == *(u32*)(work + 8) - 1)
            {
                sflPsel00260c70();
                *(u32*)(work + 0x5334) = 6;
            }
            else
            {
                func_002187b0();
                func_00219ab0();
                *(u32*)(work + 0x5334) = 0;
                *(u32*)(work + 0x5338) = 0;
            }
        }
        break;
    case 4:
        func_003c7990(1);
        if (func_003c7850() == 0)
        {
            func_003c7650(1);
            func_002187b0();
            func_00219ab0();
            *(u32*)(work + 0x5334) = 0;
        }
        break;
    case 5:
        break;
    case 6:
        if (sflPsel00260cd0() == 0)
        {
            *(u32*)(work + 0x5334) = 5;
            *(u32*)work &= ~0x20u;
        }
        break;
    }
    if ((updateFlags & 1) != 0)
    {
        func_00217350();
    }
    if ((updateFlags & 2) != 0)
    {
        func_00217610();
    }
    func_00217780();
}
// FUN_00216800
void func_00216800(void)
{
    u32* work;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    work = sSflPsel;
    K_ASSERT((*work & 1) != 0, 0x2af);
    sflPsel00260bd0();
    func_002172c0();
    if ((*work & 8) != 0)
    {
        func_00219b00();
    }
    *work &= ~1u;
}

// FUN_002168A0
u32 func_002168a0(void)
{
    K_ASSERT(sSflPsel != NULL, 0xcb);
    return *sSflPsel & 0x20;
}

// FUN_002168F0 NONMATCHING
void func_002168f0(void)
{
    u8* work;
    u32 texture;
    s32 i;
    SflPselStateCallback* state;
    SflPselStateCallback* stateTexture;
    SflPselDrawCallback* draw;
    SflPselDrawCallback* drawLoop1;
    SflPselDrawCallback* drawLoop2;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    work = (u8*)sSflPsel;
    sflPsel00260e00();
    if (((~*(u32*)work) & 1) != 0)
    {
        return;
    }
    texture = sflResGetPersonaChangeSprite();
    state = (SflPselStateCallback*)D_00960090_abs;
    (*state)(6, 1);
    (*state)(8, 0);
    (*state)(1, 0);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    for (i = 0; i < (s32)*(u32*)(work + 0xc); i++)
    {
        u32 listIndex = *(u32*)(work + 0x5c60) + i;
        u32 entryIndex = *(u32*)(work + 0x52e0 + listIndex * 4);
        func_00219370(work + 0x150 + i * 0x910,
                      (u32*)(work + 0x10 + entryIndex * 0x10),
                      *(u32*)(work + 0x5c68) == listIndex);
    }
    func_004d7f60(3, 0x71801);
    func_004d7f60(2, 0x48);
    stateTexture = (SflPselStateCallback*)D_00960090_abs;
    (*stateTexture)(1, func_0021cce0(func_0021cca0(texture, 0x31)));
    draw = (SflPselDrawCallback*)D_0096009C_abs;
    (*draw)((u32*)(work + 0x5340), 4, 0, 1, 2);
    (*draw)((u32*)(work + 0x5340), 4, 0, 2, 3);
    (*stateTexture)(1, func_0021cce0(func_0021cca0(texture, 0x32)));
    (*draw)((u32*)(work + 0x5440), 4, 0, 1, 2);
    (*draw)((u32*)(work + 0x5440), 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*stateTexture)(1, func_0021cce0(func_0021cca0(texture, 0x38)));
    (*draw)((u32*)(work + 0x5540), 4, 0, 1, 2);
    (*draw)((u32*)(work + 0x5540), 4, 0, 2, 3);
    (*stateTexture)(1, func_0021cce0(func_0021cca0(texture, 0x39)));
    (*draw)((u32*)(work + 0x5640), 4, 0, 1, 2);
    (*draw)((u32*)(work + 0x5640), 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*stateTexture)(1, func_0021cce0(func_0021cca0(texture, 0x33)));
    (*draw)((u32*)(work + 0x5740), 4, 0, 1, 2);
    (*draw)((u32*)(work + 0x5740), 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*stateTexture)(1, func_0021cce0(func_0021cca0(texture, 0x27)));
    drawLoop1 = (SflPselDrawCallback*)D_0096009C_abs;
    for (i = 0; i < 2; i++)
    {
        (*drawLoop1)((u32*)(work + 0x5840 + i * 0x40), 4, 0, 1, 2);
        (*drawLoop1)((u32*)(work + 0x5840 + i * 0x40), 4, 0, 2, 3);
    }
    (*stateTexture)(1, func_0021cce0(func_0021cca0(texture, 0x27)));
    drawLoop2 = (SflPselDrawCallback*)D_0096009C_abs;
    for (i = 0; i < 2; i++)
    {
        (*drawLoop2)((u32*)(work + 0x5a40 + i * 0x40), 4, 0, 1, 2);
        (*drawLoop2)((u32*)(work + 0x5a40 + i * 0x40), 4, 0, 2, 3);
    }
    if ((*(u32*)work & 8) != 0)
    {
        u32 entryIndex = *(u32*)(work + 0x5c58);
        func_00219370(work + 0x49d0,
                      (u32*)(work + 0x10 + entryIndex * 0x10), 0);
    }
    state = (SflPselStateCallback*)D_00960090_abs;
    (*state)(6, 1);
    (*state)(8, 0);
    func_004d7f60(3, 0x71801);
    func_004d7f60(2, 0x48);
    (*state)(1, func_0021cce0(func_0021cca0(texture, 0x1e)));
    draw = (SflPselDrawCallback*)D_0096009C_abs;
    (*draw)((u32*)(work + 0x5c90), 4, 0, 1, 2);
    (*draw)((u32*)(work + 0x5c90), 4, 0, 2, 3);
    (*draw)((u32*)(work + 0x5d90), 4, 0, 1, 2);
    (*draw)((u32*)(work + 0x5d90), 4, 0, 2, 3);
    (*state)(1, func_0021cce0(func_0021cca0(texture, 0x1f)));
    (*draw)((u32*)(work + 0x5e90), 4, 0, 1, 2);
    (*draw)((u32*)(work + 0x5e90), 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    if ((s32)*(u32*)(work + 0x5330) > 8)
    {
        (*state)(1, func_0021cce0(func_0021cca0(texture, 0x1d)));
        draw = (SflPselDrawCallback*)D_0096009C_abs;
        (*draw)((u32*)(work + 0x5f90), 4, 0, 1, 2);
        (*draw)((u32*)(work + 0x5f90), 4, 0, 2, 3);
    }
}

// FUN_002170C0
void func_002170c0(void)
{
    u8* work;
    s32 i;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    work = (u8*)sSflPsel;
    func_003b0e70(1);
    func_003b0e90(2);
    for (i = 0; i < (s32)*(u32*)(work + 0xc); i++)
    {
        u32 listIndex = i + *(u32*)(work + 0x5c60);
        u32 entryIndex = *(u32*)(work + 0x52e0 + listIndex * 4);
        u8* entry = work + 0x10 + entryIndex * 0x10;
        u8* panel = work + 0x150 + i * 0x910;
        s32 group;
        u32 handle;

        if (*(u32*)(work + 0x5c68) == listIndex)
            group = 6;
        else
            group = 0;
        uGpffffb948 = 0x78;
        handle = func_003b0970(func_00173220(*(u16*)(entry + 4)), 1,
                               group, 0, 0);
        uGpffffb948 = 0;
        frFontSetTextScale(handle, *(f32*)D_00960088 - func_0021ea00(0x28));
        *(u32*)(panel + 0x900) = handle;
    }
    func_003b0e90(1);
    func_003b0e70(2);
    for (i = 0; i < (s32)*(u32*)(work + 0xc); i++)
    {
        u8* panel = work + 0x150 + i * 0x910;
        func_003b0d70(*(u32*)(panel + 0x900), 0x1220,
                      (s32)(i * 0x21 + 0x5d) * 8);
        func_003b0e20(
            *(u32*)(panel + 0x900),
            *(u32*)(work + 0x5c68) == i + *(u32*)(work + 0x5c60) ?
                0xffffffffu : 0x64648cffu);
    }
}

// FUN_002172C0
void func_002172c0(void)
{
    u8* work;
    s32 i;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    work = (u8*)sSflPsel;
    for (i = 0; i < *(s32*)(work + 0xc); i++)
    {
        func_003b0170(*(u32*)(work + 0xa50 + i * 0x910));
    }
}

// FUN_00217350
void func_00217350(void)
{
    u8* work;
    s32 i;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    K_ASSERT(sSflPsel != NULL, 0xcb);
    work = (u8*)sSflPsel;
    for (i = 0; i < (s32)*(u32*)(work + 0xc); i++)
    {
        func_003b0170(*(u32*)(work + 0xa50 + i * 0x910));
    }
    func_002170c0();
}

// FUN_00217410
void func_00217410(u16* ids, s32* count)
{
    u8* work;
    s32 i;
    s32 output;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    work = (u8*)sSflPsel;
    output = 0;
    for (i = 0; i < (s32)*(u32*)(work + 4); i++)
    {
        u8* entry = work + 0x10 + i * 0x10;
        u32 flags = *(u32*)entry;
        if (!(~flags & 2) && !(flags & 1))
        {
            ids[output++] = *(u16*)(entry + 4);
        }
    }
    *count = output;
}

// FUN_002174D0
void func_002174d0(u16* ids, s32* count)
{
    u8* work;
    s32 i;
    s32 output;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    work = (u8*)sSflPsel;
    output = 0;
    for (i = 0; i < (s32)*(u32*)(work + 4); i++)
    {
        u8* entry = work + 0x10 + i * 0x10;
        u32 flags = *(u32*)entry;
        if (!(flags & 2) && !(~flags & 1))
        {
            ids[output++] = *(u16*)(entry + 4);
        }
    }
    *count = output;
}

// FUN_00217590
void func_00217590(u16 id)
{
    u8* work;
    u8* entry;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    work = (u8*)sSflPsel;
    entry = work + 0x10 + *(u32*)(work + 4) * 0x10;
    *(u32*)entry = 0;
    *(u16*)(entry + 4) = id;
    *(u32*)entry |= 2;
    (*(u32*)(work + 4))++;
}

// FUN_00217610
void func_00217610(void)
{
    u8* work;
    s32 i;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    work = (u8*)sSflPsel;
    (void)sflResGetPersonaChangeSprite();
    for (i = 0; i < (s32)*(u32*)(work + 0xc); i++)
    {
        u32 listIndex = i + *(u32*)(work + 0x5c60);
        u32 entryIndex = *(u32*)(work + 0x52e0 + listIndex * 4);
        func_00218810(work + 0x150 + i * 0x910,
                      (u32*)(work + 0x10 + entryIndex * 0x10),
                      *(u32*)(work + 0x5c68) == listIndex);
    }
    func_00218250(work + 0x5840, 2, *(u32*)(work + 0x5330) + 1);
    for (i = 0; i < 2; i++)
    {
        func_0021eac0(work + 0x5840 + i * 0x100, func_0021ea00(0x28));
    }
    func_00218250(work + 0x5a40, 2, *(u32*)(work + 8));
    for (i = 0; i < 2; i++)
    {
        func_0021eac0(work + 0x5a40 + i * 0x100, func_0021ea00(0x28));
    }
}
// FUN_00217780 NONMATCHING
void func_00217780(void)
{
    u8* work;
    u32 texture;
    s32 i;
    u8 color[8];
    u8 color2[4];
    f32 origin[4];
    f32 panelOrigin[2];
    f32 scrollY;
    u8* frame;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    work = (u8*)sSflPsel;
    texture = sflResGetPersonaChangeSprite();
    for (i = 0; i < (s32)*(u32*)(work + 0xc); i++)
    {
        panelOrigin[0] = 198.0f;
        panelOrigin[1] = (f32)(i * 0x21) + 90.0f;
        func_00218b20(work + 0x150 + i * 0x910,
                      (u32*)(work + 0x10 +
                             *(u32*)(work + 0x52e0 +
                                     (i + *(u32*)(work + 0x5c60)) * 4) *
                                 0x10),
                      *(u32*)(work + 0x5c68) == (u32)(i + *(u32*)(work + 0x5c60)),
                      panelOrigin, *(f32*)(work + 0x5c40));
    }
    frame = (u8*)(uintptr_t)func_0021cca0(texture, 0x31);
    origin[0] = 240.0f;
    origin[1] = 18.0f;
    origin[2] = (f32)*(s32*)(frame + 0xc);
    origin[3] = (f32)*(s32*)(frame + 0x10);
    func_0021d8e0(work + 0x5340, origin);
    frame = (u8*)(uintptr_t)func_0021cca0(texture, 0x32);
    origin[0] = 448.0f;
    origin[1] = 18.0f;
    origin[2] = (f32)*(s32*)(frame + 0xc);
    origin[3] = (f32)*(s32*)(frame + 0x10);
    func_0021d8e0(work + 0x5440, origin);
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(255.0f * *(f32*)(work + 0x5c40));
    for (i = 0; i < 2; i++)
    {
        func_0021d950(work + 0x5340 + i * 0x40, color);
    }
    frame = (u8*)(uintptr_t)func_0021cca0(texture, 0x38);
    origin[0] = 13.0f;
    origin[1] = 408.0f;
    origin[2] = (f32)*(s32*)(frame + 0xc);
    origin[3] = (f32)*(s32*)(frame + 0x10);
    func_0021d8e0(work + 0x5540, origin);
    frame = (u8*)(uintptr_t)func_0021cca0(texture, 0x39);
    origin[0] = 82.0f;
    origin[1] = 408.0f;
    origin[2] = (f32)*(s32*)(frame + 0xc);
    origin[3] = (f32)*(s32*)(frame + 0x10);
    func_0021d8e0(work + 0x5640, origin);
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(255.0f * *(f32*)(work + 0x5c40));
    for (i = 0; i < 2; i++)
    {
        func_0021d950(work + 0x5540 + i * 0x40, color);
    }
    frame = (u8*)(uintptr_t)func_0021cca0(texture, 0x33);
    origin[0] = 421.0f;
    origin[1] = 379.0f;
    origin[2] = (f32)*(s32*)(frame + 0xc);
    origin[3] = (f32)*(s32*)(frame + 0x10);
    func_0021d8e0(work + 0x5740, origin);
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(255.0f * *(f32*)(work + 0x5c40));
    func_0021d950(work + 0x5740, color);
    origin[0] = 503.0f;
    origin[1] = 384.0f;
    func_00218370(work + 0x5840, 2, *(u32*)(work + 0x5330) + 1, origin);
    color2[0] = 0x71;
    color2[1] = 0xbf;
    color2[2] = 0xff;
    color2[3] = (u8)(255.0f * *(f32*)(work + 0x5c40));
    for (i = 0; i < 2; i++)
    {
        func_0021d950(work + 0x5840 + i * 0x40, color2);
    }
    origin[0] = 559.0f;
    origin[1] = 404.0f;
    func_00218570(work + 0x5a40, 2, *(u32*)(work + 8), origin);
    color2[0] = 4;
    color2[1] = 0x29;
    color2[2] = 0x46;
    color2[3] = (u8)(255.0f * *(f32*)(work + 0x5c40));
    for (i = 0; i < 2; i++)
    {
        func_0021d950(work + 0x5a40 + i * 0x40, color2);
    }
    if ((*(u32*)work & 8) != 0)
    {
        panelOrigin[0] = 198.0f;
        panelOrigin[1] = 123.0f;
        func_00218b20(work + 0x49d0,
                      (u32*)(work + 0x10 + *(u32*)(work + 0x5c58) * 0x10),
                      0, panelOrigin, *(f32*)(work + 0x5c4c));
    }
    if (*(s32*)(work + 0x5330) < 9)
    {
        scrollY = 0.0f;
    }
    else
    {
        scrollY = (f32)*(s32*)(work + 0x5c60) * 214.0f /
                  (f32)(*(s32*)(work + 0x5330) - 8) + 89.0f;
    }
    frame = (u8*)(uintptr_t)func_0021cca0(texture, 0x1d);
    origin[0] = 573.0f;
    origin[1] = scrollY;
    origin[2] = (f32)*(s32*)(frame + 0xc);
    origin[3] = (f32)*(s32*)(frame + 0x10);
    func_0021d8e0(work + 0x5f90, origin);
    color2[0] = 0xff;
    color2[1] = 0xff;
    color2[2] = 0xff;
    color2[3] = (u8)(255.0f * *(f32*)(work + 0x5c40));
    func_0021d950(work + 0x5f90, color2);
    frame = (u8*)(uintptr_t)func_0021cca0(texture, 0x1e);
    origin[0] = 573.0f;
    origin[1] = 85.0f;
    origin[2] = (f32)*(s32*)(frame + 0xc);
    origin[3] = (f32)*(s32*)(frame + 0x10);
    func_0021d8e0(work + 0x5c90, origin);
    origin[0] = 573.0f;
    origin[1] = (f32)*(s32*)(frame + 0x10) + 85.0f;
    origin[2] = (f32)*(s32*)(frame + 0xc);
    origin[3] = 244.0f;
    func_0021d8e0(work + 0x5d90, origin);
    frame = (u8*)(uintptr_t)func_0021cca0(texture, 0x1f);
    origin[0] = 573.0f;
    origin[1] = 344.0f;
    origin[2] = (f32)*(s32*)(frame + 0xc);
    origin[3] = (f32)*(s32*)(frame + 0x10);
    func_0021d8e0(work + 0x5e90, origin);
    color2[0] = 0xff;
    color2[1] = 0xff;
    color2[2] = 0xff;
    color2[3] = (u8)(255.0f * *(f32*)(work + 0x5c40));
    func_0021d950(work + 0x5c90, color2);
    func_0021d950(work + 0x5d90, color2);
    func_0021d950(work + 0x5e90, color2);
}

// FUN_002180B0
u32 func_002180b0(u32 value)
{
    u32 texture;
    u32 frame;

    texture = sflResGetPersonaChangeSprite();
    switch (value)
    {
    case 1: frame = 10; break;
    case 2: frame = 0xb; break;
    case 3: frame = 0xc; break;
    case 4: frame = 0xd; break;
    case 5: frame = 0xe; break;
    case 6: frame = 0xf; break;
    case 7: frame = 0x10; break;
    case 8: frame = 0x11; break;
    case 9: frame = 0x12; break;
    case 10: frame = 0x13; break;
    case 0xb: frame = 0x14; break;
    case 0xc: frame = 0x15; break;
    case 0xd: frame = 0; break;
    case 0xe: frame = 1; break;
    case 0xf: frame = 2; break;
    case 0x10: frame = 3; break;
    case 0x11: frame = 4; break;
    case 0x12: frame = 5; break;
    case 0x13: frame = 6; break;
    case 0x14: frame = 7; break;
    case 0x15: frame = 8; break;
    case 0x16: frame = 9; break;
    default:
        func_0019d3f0(D_0068e228, 0x604);
        break;
    }
    return func_0021cca0(texture, frame);
}

// FUN_00218250
void func_00218250(void* glyphs, s32 capacity, u32 value)
{
    char text[256];
    s32 length;
    s32 i;

    func_00523ac8(text, (const char*)((u8*)&DAT_007ce420 - 0x1ffc));
    length = func_00524388(text);
    if (capacity < length)
    {
        K_ASSERT(0, 0x612);
    }
    for (i = 0; i < length; i++)
    {
        func_00218310((u8*)glyphs + i * 0x100, (s8)text[length - 1 - i] - 0x30);
    }
}

// FUN_00218310
void func_00218310(void* glyph, s32 digit)
{
    func_0021d3b0(glyph, func_0021cca0(sflResGetPersonaChangeSprite(), digit + 0x27));
}

// FUN_00218370
void func_00218370(void* glyphs, s32 capacity, u32 value, const f32* origin)
{
    s32 i;
    s32 length;
    s32 halfCapacity;
    s32 halfLength;
    f32 rect[4];
    char text[256];
    u32 texture;

    texture = sflResGetPersonaChangeSprite();
    func_00523ac8(text, (const char*)((u8*)&DAT_007ce420 - 0x1ffc), value);
    length = func_00524388(text);
    if (capacity < length)
    {
        K_ASSERT(0, 0x62c);
    }
    i = 0;
    halfCapacity = (capacity * 0x1b) / 2;
    halfLength = (length * 0x1b) / 2;
    for (; i < length; i++)
    {
        u8* frame = (u8*)(uintptr_t)func_0021cca0(texture, 0x27);
        rect[0] = origin[0] + (f32)((length - 1 - i) * 0x1b) +
                  (f32)halfCapacity - (f32)halfLength;
        rect[1] = origin[1];
        rect[2] = (f32)*(s32*)(frame + 0xc);
        rect[3] = (f32)*(s32*)(frame + 0x10);
        func_0021d8e0((u8*)glyphs + i * 0x100, rect);
    }
    for (; length < capacity; length++)
    {
        rect[0] = origin[0];
        rect[1] = origin[1];
        rect[2] = 0.0f;
        rect[3] = 0.0f;
        func_0021d8e0((u8*)glyphs + length * 0x100, rect);
    }
}

// FUN_00218570
void func_00218570(void* glyphs, s32 capacity, u32 value, const f32* origin)
{
    s32 i;
    s32 length;
    s32 halfCapacity;
    s32 halfLength;
    f32 rect[4];
    char text[256];
    u8* frame;
    u32 texture;

    texture = sflResGetPersonaChangeSprite();
    func_00523ac8(text, (const char*)((u8*)&DAT_007ce420 - 0x1ffc), value);
    length = func_00524388(text);
    if (capacity < length)
    {
        K_ASSERT(0, 0x64d);
    }
    i = 0;
    halfCapacity = (capacity * 0x13) / 2;
    halfLength = (length * 0x13) / 2;
    for (; i < length; i++)
    {
        frame = (u8*)(uintptr_t)func_0021cca0(texture, 0x27);
        rect[0] = origin[0] + (f32)((length - 1 - i) * 0x13) +
                  (f32)halfCapacity - (f32)halfLength;
        rect[1] = origin[1];
        rect[2] = (f32)((*(s32*)(frame + 0xc) * 0x49) / 100);
        rect[3] = (f32)((*(s32*)(frame + 0x10) * 0x49) / 100);
        func_0021d8e0((u8*)glyphs + i * 0x100, rect);
    }
    for (; length < capacity; length++)
    {
        rect[0] = origin[0];
        rect[1] = origin[1];
        rect[2] = 0.0f;
        rect[3] = 0.0f;
        func_0021d8e0((u8*)glyphs + length * 0x100, rect);
    }
}

// FUN_002187B0
void func_002187b0(void)
{
    u32* work;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    work = sSflPsel;
    *(u32*)((u8*)work + 0x5c44) = 0;
    *(u32*)((u8*)work + 0x5c48) = 1;
    *work |= 4;
}

// FUN_00218810
void func_00218810(void* panel, const u32* entry, s32 selected)
{
    u8* destination;
    u32 texture;
    u32 frameIndex;
    u32 frame;
    u32 value;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    destination = (u8*)panel;
    texture = sflResGetPersonaChangeSprite();
    if (selected != 0)
    {
        frameIndex = 0x1b;
        value = 0x1c;
    }
    else if ((*entry & 2) != 0)
    {
        frameIndex = 0x23;
        value = 0x24;
    }
    else
    {
        frameIndex = 0x21;
        value = 0x22;
    }
    frame = func_0021cca0(texture, frameIndex);
    func_0021d3b0(destination, frame);
    func_0021eac0(destination, func_0021ea00(0x28));
    func_0021e380(destination + 0x100, frame, 1);
    func_0021eac0(destination + 0x100, func_0021ea00(0x28));
    func_0021d3b0(destination + 0x200, func_0021cca0(texture, value));
    func_0021eac0(destination + 0x200, func_0021ea00(0x28));
    if (selected != 0)
    {
        if ((*entry & 2) != 0)
            frameIndex = 0x3b;
        else
            frameIndex = 0x18;
    }
    else
    {
        frameIndex = 0x17;
    }
    func_0021d3b0(destination + 0x300, func_0021cca0(texture, frameIndex));
    func_0021eac0(destination + 0x300, func_0021ea00(0x28));
    func_0021d3b0(destination + 0x400, func_002180b0(entry[2]));
    func_0021eac0(destination + 0x400, func_0021ea00(0x28));
    if ((*entry & 2) != 0)
    {
        func_0021d3b0(destination + 0x500, func_0021cca0(texture, 0x25));
        func_0021eac0(destination + 0x500, func_0021ea00(0x28));
    }
    frameIndex = selected != 0 ? 0x1a : 0x19;
    func_0021d3b0(destination + 0x600, func_0021cca0(texture, frameIndex));
    func_0021eac0(destination + 0x600, func_0021ea00(0x28));
    func_00238980(destination + 0x700, 2, entry[3], selected != 0 ? 1 : 2);
    func_0021eac0(destination + 0x700, func_0021ea00(0x28));
    func_0021eac0(destination + 0x800, func_0021ea00(0x28));
}

#pragma optimization_level 2
// FUN_00218B20
void func_00218b20(void* panel, const u32* entry, s32 selected,
                   const f32* origin, f32 alpha)
{
    u8* destination;
    u32 texture;
    struct {
        f32 rect[4];
        u32 reserved[7];
        u8 color[4];
    } scratch;
#define rect scratch.rect
#define color scratch.color
    f32 x;
    f32 y;
    u8 alphaByte;
    u8* frame;
    void* handle;
    u32 colorValue;
    s32 i;
    s32 j;
    u32 alphaValueSelected;
    u32 alphaValueUnselected;
    s32 frameId;
    s32 mode;
    K_ASSERT(sSflPsel != NULL, 0xcb);
    destination = (u8*)panel;
    texture = sflResGetPersonaChangeSprite();
    x = origin[0] - 198.0f;
    y = origin[1] - 90.0f;
    frame = (u8*)(uintptr_t)func_0021cca0(texture, 0x21);
    rect[0] = x + 198.0f;
    rect[1] = y + 90.0f;
    rect[2] = (f32)*(s32*)(frame + 0xc);
    rect[3] = (f32)*(s32*)(frame + 0x10);
    func_0021d8e0(destination, rect);
    rect[0] = x + 198.0f + (f32)*(s32*)(frame + 0xc);
    rect[1] = y + 90.0f;
    rect[2] = 349.0f;
    rect[3] = (f32)*(s32*)(frame + 0x10);
    func_0021d8e0(destination + 0x100, rect);
    frame = (u8*)(uintptr_t)func_0021cca0(texture, 0x22);
    rect[0] = x + 557.0f;
    rect[1] = y + 90.0f;
    rect[2] = (f32)*(s32*)(frame + 0xc);
    rect[3] = (f32)*(s32*)(frame + 0x10);
    func_0021d8e0(destination + 0x200, rect);
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    alphaByte = (u8)(alpha * 255.0f);
    color[3] = alphaByte;
    for (i = 0; i < 3; i++) {
        func_0021d950(destination + i * 0x100, color);
    }
    frame = (u8*)(uintptr_t)func_0021cca0(texture, 0x17);
    rect[0] = x + 202.0f;
    rect[1] = y + 93.0f;
    rect[2] = (f32)*(s32*)(frame + 0xc);
    rect[3] = (f32)*(s32*)(frame + 0x10);
    func_0021d8e0(destination + 0x300, rect);
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(alpha * 255.0f);
    func_0021d950(destination + 0x300, color);
    frame = (u8*)(uintptr_t)func_002180b0(entry[2]);
    rect[0] = x + 202.0f;
    rect[1] = y + 93.0f;
    rect[2] = (f32)*(s32*)(frame + 0xc);
    rect[3] = (f32)*(s32*)(frame + 0x10);
    func_0021d8e0(destination + 0x400, rect);
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(alpha * 255.0f);
    func_0021d950(destination + 0x400, color);
    if (selected != 0)
    {
        color[0] = 4;
        color[1] = 0x29;
        color[2] = 0x46;
    }
    else if ((*entry & 2) != 0)
    {
        color[0] = 0xff;
        color[1] = 0xfe;
        color[2] = 0xbb;
    }
    else
    {
        color[0] = 0x71;
        color[1] = 0xbf;
        color[2] = 0xff;
    }
    color[3] = (u8)(alpha * 255.0f);
    func_0021d950(destination + 0x400, color);
    if ((*entry & 2) != 0)
    {
        frame = (u8*)(uintptr_t)func_0021cca0(texture, 0x25);
        rect[0] = x + 148.0f;
        rect[1] = y + 108.0f;
        rect[2] = (f32)*(s32*)(frame + 0xc);
        rect[3] = (f32)*(s32*)(frame + 0x10);
        func_0021d8e0(destination + 0x500, rect);
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = (u8)(alpha * 255.0f);
        func_0021d950(destination + 0x500, color);
    }
    if (selected != 0)
    {
        frameId = 0x1a;
    }
    else
    {
        frameId = 0x19;
    }
    frame = (u8*)(uintptr_t)func_0021cca0(texture, frameId);
    rect[0] = x + 482.0f;
    rect[1] = y + 105.0f;
    rect[2] = (f32)*(s32*)(frame + 0xc);
    rect[3] = (f32)*(s32*)(frame + 0x10);
    func_0021d8e0(destination + 0x600, rect);
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(alpha * 255.0f);
    func_0021d950(destination + 0x600, color);
    if (selected != 0)
    {
        mode = 1;
    }
    else
    {
        mode = 2;
    }
    rect[0] = x + 514.0f;
    rect[1] = y + 105.0f;
    handle = func_00238dc0(destination + 0x700, 2, entry[3], mode, rect);
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(alpha * 255.0f);
    for (j = 0; j < 2; j++) {
        func_0021d950(destination + 0x700 + j * 0x100, color);
    }
    rect[0] = x + 290.0f;
    rect[1] = y + 93.0f;
    func_003b0d70(*(u32*)(destination + 0x900),
                  (s32)rect[0] << 4, (s32)rect[1] << 3);
    if (selected != 0)
    {
        alphaValueSelected = (u32)(alpha * 255.0f);
        colorValue = alphaValueSelected | 0xffffff00u;
    }
    else
    {
        alphaValueUnselected = (u32)(alpha * 255.0f);
        colorValue = alphaValueUnselected | 0x64648c00u;
    }
    func_003b0e20(*(u32*)(destination + 0x900), colorValue);
    (void)handle;
#undef color
#undef rect
}
// FUN_00219370 NONMATCHING
void func_00219370(void* panel, const u32* entry, s32 selected)
{
    u32 texture;
    u32 frame;
    u32 value;
    s32 i;
    SflPselStateCallback* state;
    SflPselDrawCallback* draw;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    texture = sflResGetPersonaChangeSprite();
    state = (SflPselStateCallback*)D_00960090_abs;
    (*state)(6, 1);
    (*state)(8, 0);
    (*state)(1, 0);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    if (selected != 0)
    {
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        frame = 0x1b;
        value = 0x1c;
    }
    else if ((*entry & 2) != 0)
    {
        func_004d7f60(3, 0x71801);
        func_004d7f60(2, 0x48);
        frame = 0x23;
        value = 0x24;
    }
    else
    {
        func_004d7f60(3, 0x71801);
        func_004d7f60(2, 0x48);
        frame = 0x21;
        value = 0x22;
    }
    (*state)(1, func_0021cce0(func_0021cca0(texture, frame)));
    draw = (SflPselDrawCallback*)D_0096009C_abs;
    (*draw)((u32*)panel, 4, 0, 1, 2);
    (*draw)((u32*)panel, 4, 0, 2, 3);
    (*draw)((u32*)((u8*)panel + 0x100), 4, 0, 1, 2);
    (*draw)((u32*)((u8*)panel + 0x100), 4, 0, 2, 3);
    (*state)(1, func_0021cce0(func_0021cca0(texture, value)));
    (*draw)((u32*)((u8*)panel + 0x200), 4, 0, 1, 2);
    (*draw)((u32*)((u8*)panel + 0x200), 4, 0, 2, 3);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    if (selected != 0)
    {
        if ((*entry & 2) != 0)
            frame = 0x3b;
        else
            frame = 0x18;
    }
    else
    {
        frame = 0x17;
    }
    (*state)(1, func_0021cce0(func_0021cca0(texture, frame)));
    (*draw)((u32*)((u8*)panel + 0x300), 4, 0, 1, 2);
    (*draw)((u32*)((u8*)panel + 0x300), 4, 0, 2, 3);
    (*state)(1, func_0021cce0(func_002180b0(entry[2])));
    (*draw)((u32*)((u8*)panel + 0x400), 4, 0, 1, 2);
    (*draw)((u32*)((u8*)panel + 0x400), 4, 0, 2, 3);
    frame = selected != 0 ? 0x1a : 0x19;
    (*state)(1, func_0021cce0(func_0021cca0(texture, frame)));
    (*draw)((u32*)((u8*)panel + 0x600), 4, 0, 1, 2);
    (*draw)((u32*)((u8*)panel + 0x600), 4, 0, 2, 3);
    (*state)(1, func_00239140(selected != 0 ? 1 : 2));
    for (i = 0; i < 2; i++)
    {
        (*draw)((u32*)((u8*)panel + 0x700 + i * 0x100), 4, 0, 1, 2);
        (*draw)((u32*)((u8*)panel + 0x700 + i * 0x100), 4, 0, 2, 3);
    }
    if ((*entry & 2) != 0)
    {
        func_004d7f60(3, 0x71801);
        func_004d7f60(2, 0x48);
        (*state)(1, func_0021cce0(func_0021cca0(texture, 0x25)));
        (*draw)((u32*)((u8*)panel + 0x500), 4, 0, 1, 2);
        (*draw)((u32*)((u8*)panel + 0x500), 4, 0, 2, 3);
    }
    func_003b1360(*(u32*)((u8*)panel + 0x900), 1, 0);
}

// FUN_00219970
void func_00219970(void)
{
    u8* work;
    u32 listIndex;
    u32 listOffset;
    u8* entry;
    u32 handle;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    work = (u8*)sSflPsel;
    listIndex = *(u32*)(work + 0x5c68);
    listOffset = listIndex * 4;
    entry = (u8*)(listOffset + (u32)work);
    *(u32*)(work + 0x5c58) = *(u32*)(entry + 0x52e0);
    entry = work + 0x10 + *(u32*)(work + 0x5c58) * 0x10;
    func_003b0e70(1);
    func_003b0e90(2);
    uGpffffb948 = 0x78;
    handle = func_003b0970(
        func_00173220(*(u16*)(entry + 4)),
        1, 0, 0, 0);
    uGpffffb948 = 0;
    func_003b0e90(1);
    func_003b0e70(2);
    frFontSetTextScale(handle, *(f32*)D_00960088 - func_0021ea00(0x28));
    *(u32*)(work + 0x52d0) = handle;
    func_00218810(work + 0x49d0,
                  (u32*)(work + 0x10 + *(u32*)(work + 0x5c58) * 0x10), 0);
    *(u32*)(work + 0x5c50) = 0;
    *(u32*)(work + 0x5c54) = 1;
    *(u32*)work |= 0x10;
    *(u32*)work |= 8;
}

// FUN_00219AB0
void func_00219ab0(void)
{
    u32* work;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    work = sSflPsel;
    *(u32*)((u8*)work + 0x5c50) = 0;
    *(u32*)((u8*)work + 0x5c54) = 0;
    *work |= 0x10;
}

// FUN_00219B00
void func_00219b00(void)
{
    u32* work;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    work = sSflPsel;
    K_ASSERT((*work & 8) != 0, 0x81b);
    func_003b0170(*(u32*)((u8*)work + 0x52d0));
    *work &= ~8u;
}

// FUN_00219B90
void func_00219b90(void)
{
    u8* work;
    u32 listIndex;
    u32 entryOffset;
    u8* entry;
    u8* resetWork;

    K_ASSERT(sSflPsel != NULL, 0xcb);
    work = (u8*)sSflPsel;
    listIndex = *(u32*)(work + 0x5c68);
    entryOffset = listIndex * 4;
    entry = (u8*)(entryOffset + (u32)work);
    entry = work + 0x10 + *(u32*)(entry + 0x52e0) * 0x10;
    if ((*(u32*)entry & 4) != 0)
    {
        func_003c7430(0x31);
        *(u32*)(work + 0x5334) = 4;
    }
    else
    {
        func_003c7430(0x2e);
        func_003c74e0(0x30);
        K_ASSERT(sSflPsel != NULL, 0xcb);
        resetWork = (u8*)sSflPsel;
        *(u32*)(resetWork + 0x5c44) = 0;
        *(u32*)(resetWork + 0x5c48) = 0;
        *(u32*)resetWork |= 4;
        func_00219970();
        *(u32*)(work + 0x5334) = 1;
    }
    func_0010a4e0(0, 0, 0, 1);
}
