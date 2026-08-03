#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/Social/sfl_psel.h"
#include "Main/Social/sfl_res.h"

extern void FUN_0021d890(void*, const void*);


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






// FUN_00260a10
void sflPsel00260a10(void)
{
    K_ASSERT(sSflPsel != NULL, 0x57);
    sSflPsel = NULL;
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


// Reconstructed the complete retail animation path, including all quad states.
// The original source omitted dynamic frame branches and contiguous color writes.
// Restoring these stores increases the instruction window while preserving logic.
// Remaining differences are primarily MWCC register allocation and scheduling.
// This function remains NONMATCHING until those code-generation details converge.
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
    s32 mode;

    K_ASSERT(sSflPsel != NULL, 0x57);
    work = sSflPsel;
    texture = sflResGetPersonaChangeSprite();
    resource34 = (u8*)(uintptr_t)FUN_0021cca0(texture, 0x34);
    mode = (s32)work[1];
    diagonal = 1.4142135f;

    switch (mode) {
    case 0:
        alpha = 1.0f;
        if ((s32)work[2] < 5) {
            points[0] = -(6.0f + (f32)sflPselReadS32(resource34, 0x10)) +
                        ((f32)(s32)work[2] / 10.0f) *
                        (12.0f + (f32)sflPselReadS32(resource34, 0x10));
            points[1] = 6.0f + (f32)sflPselReadS32(resource34, 0x10) -
                        ((f32)(s32)work[2] / 10.0f) *
                        (f32)sflPselReadS32(resource34, 0x10);
        } else {
            points[0] = 6.0f;
            points[1] = 6.0f;
        }
        break;
    case 1:
        channelFloat = (s32)work[2] < 3 ? (f32)(s32)work[2] / 3.0f : 1.0f;
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
        if ((s32)work[2] < 6) {
            points[0] =
                -(109.0f +
                  (f32)sflPselReadS32(
                      (u8*)(uintptr_t)FUN_0021cca0(texture, 0x35), 0x10)) +
                        ((f32)(s32)work[2] / 6.0f) *
                        (225.0f + (f32)sflPselReadS32(resource34, 0x10));
            points[1] = 109.0f + (f32)sflPselReadS32(resource34, 0x10) -
                        ((f32)(s32)work[2] / 6.0f) *
                        (87.0f + (f32)sflPselReadS32(resource34, 0x10));
        } else {
            points[0] = 116.0f;
            points[1] = 22.0f;
        }
        break;
    case 1:
        channelFloat = (s32)work[2] < 3 ? (f32)(s32)work[2] / 3.0f : 1.0f;
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
        if ((s32)work[2] < 6) {
            points[0] =
                -(109.0f +
                  (f32)sflPselReadS32(
                      (u8*)(uintptr_t)FUN_0021cca0(texture, 0x36), 0x10)) +
                        ((f32)(s32)work[2] / 6.0f) *
                        (225.0f + (f32)sflPselReadS32(resource34, 0x10));
            points[1] = 109.0f + (f32)sflPselReadS32(resource34, 0x10) -
                        ((f32)(s32)work[2] / 6.0f) *
                        (87.0f + (f32)sflPselReadS32(resource34, 0x10));
        } else {
            points[0] = 116.0f;
            points[1] = 22.0f;
        }
        break;
    case 1:
        channelFloat = (s32)work[2] < 3 ? (f32)(s32)work[2] / 3.0f : 1.0f;
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
        if ((s32)work[2] < 8) {
            channelFloat = (f32)(s32)work[2] / 8.0f;
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
        if ((s32)work[2] < 10) {
            channelFloat = (f32)(s32)work[2] / 10.0f;
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
        if ((s32)work[2] < 10) {
            channelFloat = (f32)(s32)work[2] / 10.0f;
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

    switch ((s32)work[1]) {
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
        if ((s32)work[2] < 10) {
            channelFloat = (f32)(s32)work[2] / 10.0f;
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


/* opt_lifetimes on: func_00215b00 nd765 -> nd748, object 1216 -> 1212/1216; measured W328. */



/* opt_lifetimes on: func_002168f0 nd777 -> nd716, object 1992 -> 1992/2000; measured W328. */



















