#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

#pragma alias FUN_002491f0_y2 FUN_002491f0


#pragma alias bpcInit FUN_00248490
#pragma alias bpmUpdate FUN_00249180


static u32* sBpmWork; // puGpffffb634
extern u32* sBpc324; // 007ce324 / GP -0x49CC


void FUN_002491f0_y2();

// FUN_00249180
void bpmUpdate(void)
{
    u32* work;

    K_ASSERT(sBpmWork != NULL, 0x3d);
    work = sBpmWork;
    if (*work & 1)
    {
        FUN_002491f0_y2();
        *work &= ~1;
    }
}


#include "Utils.h"

#pragma alias datGetFlag_y2 datGetFlag


/* BPC panel subtask state at DAT_007CE324 / GP -0x49CC. */
extern u32* sBpc324; // 007CE324 / GP -0x49CC
/* BPC command subtask state at DAT_007CE328 / GP -0x49C8. */
u32* sBpc328;

typedef void (*BpcRenderState)(s32 property, u32 value);
typedef void (*BpcRenderQuad)(void* quad, s32 count, s32 group, s32 pass, s32 blend);
extern BpcRenderState gBpcRenderState;
extern BpcRenderQuad gBpcRenderQuad;
extern u32 D_00960090[];
extern u32 D_0096009C[];
extern void RpSkyRenderStateSet(s32 state, u32 value);
extern u32 func_0021c3f0(s32 texture);
extern u32 func_0021cca0(u32 texture, s32 frame);
extern u32 func_0021cce0(u32 frame);
extern void* func_0021c550(s32 index);
extern void func_0021d3b0(void* destination, u32 frame);
extern void func_0021d8e0(void* destination, const f32* layout);
extern void func_0021d950(void* destination, const u8* color);
extern void func_0021e380(void* destination, u32 frame, s32 mode);
extern void* func_003a52c0(f32 angle, s32 width, s32 height, s32 first,
                            s32 mode, s32 count, void* left, void* right);
extern void func_003b0170(u32 resource);
extern u32 func_003b0970(u32 resource, s32 mode, s32 group, s32 a, s32 b);
extern void func_003b1360(u32 resource, s32 mode, s32 group);
extern void func_003b0d70(u32 resource, s32 x, s32 y);
extern void func_003b0e20(u32 resource, u32 color);
extern void func_003b0e70(s32 mode);
extern void func_003b0e90(s32 mode);
extern s32 func_003b19d0(u32 resource);
extern void frFontSetTextScale(u32 resource, f32 angle);
extern void func_003c72d0(void* resource);
extern void func_003c7430(s32 mode);
extern void func_003c7650(s32 mode);
extern u32 func_003c7850(void);
extern void func_003c7990(s32 mode);
extern void func_003c7bc0(s32 mode, u32 value);
extern void func_003c7c20(s32 mode, u32 value, s32 count);
extern void func_003c77a0(void);
extern u32 func_00173220(u16 value);
extern u32 func_001775a0(u16 value);
extern void func_003c94e0(void* resource);
extern void func_003c9790(s32 mode);
extern s32 datGetFlag(s32 flag);
extern void datSetFlag(s32 flag, u8 value);
extern void* func_0030c0c0(void);

static void bpc324RenderState(u32 state, u32 value)
{
    gBpcRenderState(state, value);
}

static void bpc324Draw(void* quad, s32 pass, s32 blend)
{
    gBpcRenderQuad(quad, 4, 0, pass, blend);
}

static u32 bpc324Flags(void)
{
    K_ASSERT(sBpc324 != NULL, 0x3d);
    return *sBpc324;
}

void* FUN_00248f40(void*);
void FUN_002491f0(void);
void FUN_00248fc0(void*);

// FUN_002484A0
void FUN_002484a0(void)
{
    K_ASSERT(sBpc324 != NULL, 0x3d);
    if ((*sBpc324 & 1u) != 0) {
        FUN_002491f0();
    }
    sBpc324 = NULL;
}

// FUN_00248500
void FUN_00248500(void* destination)
{
    K_ASSERT(sBpc324 != NULL, 0x3d);
    if ((*sBpc324 & 1u) != 0) {
        FUN_002491f0();
    }
    FUN_00248fc0(FUN_00248f40(destination));
}

// FUN_00248580
void FUN_00248580(void* destination, void* origin)
{
    K_ASSERT(sBpc324 != NULL, 0x3d);
    if ((*sBpc324 & 1u) != 0) {
        FUN_002491f0();
    }
    FUN_00248fc0(func_003a52c0(0.0f, 100, 100, -1, 2, 6, destination, origin));
}

// FUN_00248620 NONMATCHING
void FUN_00248620(void)
{
    u32* work;
    u32 texture;
    u32* entry;
    u32* frame;
    f32 total;
    f32 half;
    f32 base;
    f32 left;
    f32 x;
    struct {
        f32 rect[4];
        u8 reserved[0x1c];
        u8 color[4];
    } layout;
    f32 y;

    K_ASSERT(sBpc324 != NULL, 0x3d);
    work = sBpc324;
    texture = func_0021c3f0(1);
    if ((*work & 1u) != 0) {
        if ((s32)work[2] < 0x2d) {
            work[2]++;
        } else {
            FUN_002491f0();
            *work &= ~1u;
        }
    }
    if ((~*work & 1u) != 0) {
        return;
    }
    *work |= 2;

    total = 0.0f;
    entry = (u32*)work[1];
    while (entry != NULL) {
        total += (f32)func_003b19d0((u32)entry);
        entry = (u32*)entry[9];
    }
    half = total / 2.0f;
    base = 309.0f - half;
    left = base - 57.0f;

    frame = (u32*)(uintptr_t)func_0021cca0(texture, 0x43);
    layout.rect[0] = left;
    layout.rect[1] = 100.0f;
    layout.rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    layout.rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    func_0021d8e0(work + 4, layout.rect);
    layout.color[0] = 0xff;
    layout.color[1] = 0xff;
    layout.color[2] = 0xff;
    layout.color[3] = 0xff;
    func_0021d950(work + 4, layout.color);

    x = (f32)*(s32*)((u8*)frame + 0xc) + left;
    layout.rect[0] = x;
    half = 309.0f + half;
    layout.rect[2] = 57.0f + half - 16.0f - x;
    layout.rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    func_0021d8e0(work + 0x44, layout.rect);
    layout.color[0] = 0xff;
    layout.color[1] = 0xff;
    layout.color[2] = 0xff;
    layout.color[3] = 0xff;
    func_0021d950(work + 0x44, layout.color);

    frame = (u32*)(uintptr_t)func_0021cca0(texture, 0x44);
    layout.rect[0] = left;
    layout.rect[1] = 100.0f;
    layout.rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    layout.rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    func_0021d8e0(work + 0x84, layout.rect);
    layout.color[0] = 0xff;
    layout.color[1] = 0xff;
    layout.color[2] = 0xff;
    layout.color[3] = 0xff;
    func_0021d950(work + 0x84, layout.color);

    frame = (u32*)(uintptr_t)func_0021cca0(texture, 0);
    layout.rect[0] = base - 86.0f;
    layout.rect[1] = 54.0f;
    layout.rect[2] = 86.0f + half - layout.rect[0];
    layout.rect[3] = (f32)((*(s32*)((u8*)frame + 0x10) * 390) / 100);
    func_0021d8e0(work + 0xc4, layout.rect);
    layout.color[0] = 0xff;
    layout.color[1] = 0xff;
    layout.color[2] = 0xff;
    layout.color[3] = 0xff;
    func_0021d950(work + 0xc4, layout.color);

    half = 0.0f;
    entry = (u32*)work[1];
    while (entry != NULL) {
        half += (f32)func_003b19d0((u32)entry);
        entry = (u32*)entry[9];
    }
    y = 662.0f;
    entry = (u32*)work[1];
    while (entry != NULL) {
        half -= (f32)func_003b19d0((u32)entry);
        func_003b0d70((u32)entry, (s32)(16.0f * (base + half)), (s32)y);
        entry = (u32*)entry[9];
    }

    layout.color[0] = 0xc8;
    layout.color[1] = 0xe6;
    layout.color[2] = 0xff;
    layout.color[3] = 0xff;
    func_003b0e20(work[1],
                   ((u32)layout.color[0] << 24) | ((u32)layout.color[1] << 16) |
                   ((u32)layout.color[2] << 8) | layout.color[3]);

    frame = (u32*)(uintptr_t)func_0021cca0(texture, 0x42);
    half = total / 2.0f;
    base = 309.0f - half;
    layout.rect[0] = base - 28.0f;
    layout.rect[1] = 91.0f;
    layout.rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    layout.rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    func_0021d8e0(work + 0x104, layout.rect);
    layout.color[0] = 0xff;
    layout.color[1] = 0xff;
    layout.color[2] = 0xff;
    layout.color[3] = 0xff;
    func_0021d950(work + 0x104, layout.color);

    layout.rect[0] = 309.0f + half + 28.0f - 16.0f;
    layout.rect[1] = 91.0f;
    layout.rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    layout.rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    func_0021d8e0(work + 0x144, layout.rect);
    layout.color[0] = 0xff;
    layout.color[1] = 0xff;
    layout.color[2] = 0xff;
    layout.color[3] = 0xff;
    func_0021d950(work + 0x144, layout.color);
}

// FUN_00248BB0
void FUN_00248bb0(void)
{
    u8* work;
    u32 texture;
    u32 frame;
    s32 flags;
    BpcRenderState* renderState;
    BpcRenderQuad* renderQuad;

    K_ASSERT(sBpc324 != NULL, 0x3d);
    work = (u8*)sBpc324;
    texture = func_0021c3f0(1);
    flags = ~*(u32*)work;
    if ((flags & 1u) == 0) {
        if ((flags & 2u) != 0) {
            FUN_00248620();
        }
        renderState = (BpcRenderState*)D_00960090;
        (*renderState)(9, 2);
        (*renderState)(0x14, 2);
        (*renderState)(8, 0);
        (*renderState)(6, 0);
        frame = func_0021cce0(func_0021cca0(texture, 0));
        (*renderState)(1, frame);
        RpSkyRenderStateSet(3, 0x717fb);
        RpSkyRenderStateSet(2, 0x44);
        renderQuad = (BpcRenderQuad*)D_0096009C;
        (*renderQuad)(work + 0x310, 4, 0, 1, 2);
        (*renderQuad)(work + 0x310, 4, 0, 2, 3);
        frame = func_0021cce0(func_0021cca0(texture, 0x43));
        (*renderState)(1, frame);
        RpSkyRenderStateSet(3, 0x717fb);
        RpSkyRenderStateSet(2, 0x44);
        (*renderQuad)(work + 0x10, 4, 0, 1, 2);
        (*renderQuad)(work + 0x10, 4, 0, 2, 3);
        (*renderQuad)(work + 0x110, 4, 0, 1, 2);
        (*renderQuad)(work + 0x110, 4, 0, 2, 3);
        (*renderQuad)(work + 0x210, 4, 0, 1, 2);
        (*renderQuad)(work + 0x210, 4, 0, 2, 3);
        func_003b1360(*(u32*)(work + 4), 1, 0);
        frame = func_0021cce0(func_0021cca0(texture, 0x42));
        (*renderState)(1, frame);
        RpSkyRenderStateSet(3, 0x717fb);
        RpSkyRenderStateSet(2, 0x44);
        (*renderQuad)(work + 0x410, 4, 0, 1, 2);
        (*renderQuad)(work + 0x410, 4, 0, 2, 3);
        (*renderQuad)(work + 0x510, 4, 0, 1, 2);
        (*renderQuad)(work + 0x510, 4, 0, 2, 3);
    }
}

// FUN_00248F40
void* FUN_00248f40(void* destination)
{
    void* resource;

    func_003b0e70(1);
    func_003b0e90(2);
    resource = (void*)func_003b0970((u32)destination, 2, 6, 0, 0);
    func_003b0e90(1);
    func_003b0e70(2);
    return resource;
}

// FUN_00248FC0
void FUN_00248fc0(void* destination)
{
    u8* work;
    u32 texture;
    u32 frame;
    u32 flags;

    K_ASSERT(sBpc324 != NULL, 0x3d);
    work = (u8*)sBpc324;
    texture = func_0021c3f0(1);
    func_003b0d70((u32)destination, 0x640, 0x320);
    frFontSetTextScale((u32)destination, 0.0f);
    func_003b0e20((u32)destination, (u32)-1);
    *(void**)(work + 4) = destination;
    frame = func_0021cca0(texture, 0x43);
    func_0021d3b0(work + 0x10, frame);
    func_0021e380(work + 0x110, frame, 1);
    func_0021d3b0(work + 0x210, func_0021cca0(texture, 0x44));
    func_0021d3b0(work + 0x310, func_0021cca0(texture, 0));
    frame = func_0021cca0(texture, 0x42);
    func_0021d3b0(work + 0x410, frame);
    func_0021d3b0(work + 0x510, frame);
    *(u32*)(work + 8) = 0;
    flags = *(u32*)work | 1u;
    *(u32*)work = flags;
    *(u32*)work = flags & ~2u;
}

// FUN_00249130
u32 FUN_00249130(void)
{
    K_ASSERT(sBpc324 != NULL, 0x3d);
    return *sBpc324 & 1u;
}

// FUN_002491F0
void FUN_002491f0(void)
{
    K_ASSERT(sBpc324 != NULL, 0x3d);
    func_003b0170(*(u32*)((u8*)sBpc324 + 4));
}




static u32* sBpeWork;

// FUN_00249240
void bpe00249240(u32* param_1)
{
    *param_1 = 0;
    sBpeWork = param_1;
}
