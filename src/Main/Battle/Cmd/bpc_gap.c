#include "Utils.h"
#include "Kosaka/k_assert.h"

/* BPC panel subtask state at DAT_007CE324 / GP -0x49CC. */
u32* sBpc324;

typedef void (*BpcRenderState)(s32 property, u32 value);
typedef void (*BpcRenderQuad)(void* quad, s32 count, s32 group, s32 pass, s32 blend);
extern BpcRenderState gBpcRenderState;
extern BpcRenderQuad gBpcRenderQuad;
extern void RpSkyRenderStateSet(s32 state, u32 value);
extern u32 func_0021c3f0(s32 texture);
extern u32 func_0021cca0(u32 texture, s32 frame);
extern u32 func_0021cce0(u32 frame);
extern void* func_0021c550(s32 index);
extern void func_0021d3b0(void* destination, u32 frame);
extern void func_0021d8e0(void* destination, const f32* layout);
extern void func_0021d950(void* destination, const u8* color);
extern void func_0021e380(void* destination, u32 frame, s32 mode);
extern void* func_003a52c0(s32 width, s32 height, s32 first, s32 mode,
                            s32 count, void* left, void* right);
extern void func_003b0170(u32 resource);
extern u32 func_003b0970(u32 resource, s32 mode, s32 group, s32 a, s32 b);
extern void func_003b0d70(u32 resource, s32 x, s32 y);
extern void func_003b0e20(u32 resource, u32 color);
extern void func_003b0e70(s32 mode);
extern void func_003b0e90(s32 mode);
extern s32 func_003b19d0(u32 resource);
extern void func_003b2c60(u32 resource, f32 angle);
extern void func_003c72d0(void* resource);
extern void func_003c7430(s32 mode);
extern void func_003c7650(s32 mode);
extern u32 func_003c7850(s32 mode);
extern void func_003c7bc0(s32 mode, u32 value);
extern void func_003c7c20(s32 mode, u32 value, s32 count);
extern void FUN_003c77a0(s32 mode);
extern u32 datGetFlag(s32 flag);
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

void FUN_002491f0(void);
void* FUN_00248fc0(void*);

// FUN_002484A0
void FUN_002484a0(void)
{
    K_ASSERT(sBpc324 != NULL, 0x3d);
    if ((*sBpc324 & 1u) != 0) {
        FUN_002491f0();
    }
    sBpc324 = NULL;
}

// FUN_00248500 NONMATCHING
void FUN_00248500(void* destination)
{
    u32 texture;

    K_ASSERT(sBpc324 != NULL, 0x3d);
    texture = func_0021c3f0(1);
    func_0021d3b0(destination, func_0021cca0(texture, 0));
    func_0021e380((u8*)destination + 0x100,
                  func_0021cca0(texture, 0x43), 1);
}

// FUN_00248580 NONMATCHING
void FUN_00248580(void* destination, void* origin)
{
    void* resource;

    K_ASSERT(sBpc324 != NULL, 0x3d);
    resource = func_003a52c0(100, 100, -1, 2, 6, destination, origin);
    FUN_00248fc0(resource);
}

// FUN_00248620 NONMATCHING
void FUN_00248620(void)
{
    u8* work;
    u32 texture;
    u32 frame;
    void* entry;
    f32 total;
    s32 count;
    s32 i;
    f32 rect[4];
    u8 color[4] = { 0xff, 0xff, 0xff, 0xff };
    u8* slot;

    K_ASSERT(sBpc324 != NULL, 0x3d);
    work = (u8*)sBpc324;
    texture = func_0021c3f0(1);
    if ((*sBpc324 & 1u) != 0) {
        if (*(u32*)(work + 8) < 0x2d) {
            (*(u32*)(work + 8))++;
        } else {
            FUN_002491f0();
            *sBpc324 &= ~2u;
        }
    }
    if ((*sBpc324 & 1u) == 0) {
        return;
    }
    *sBpc324 |= 2;
    total = 0.0f;
    count = 0;
    entry = *(void**)(work + 4);
    while (entry != NULL && count < 0x40) {
        total += (f32)func_003b19d0((u32)entry);
        entry = *(void**)((u8*)entry + 0x24);
        count++;
    }
    if (count == 0) {
        count = 1;
    }
    frame = func_0021cca0(texture, 0x43);
    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = 417.0f;
    rect[3] = 250.0f;
    func_0021d8e0(work + 0x10, rect);
    func_0021d3b0(work + 0x10, frame);
    func_0021d950(work + 0x10, color);
    *(f32*)(work + 0x60) = 0.0f;
    *(f32*)(work + 0x64) = 200.0f;
    *(f32*)(work + 0x68) = 40.0f + total / (f32)count;
    *(f32*)(work + 0x6c) = 40.0f;
    func_0021d8e0(work + 0x110, (f32*)(work + 0x60));
    func_0021d950(work + 0x110, color);
    for (i = 0; i < 3; i++) {
        slot = work + 0x210 + i * 0x100;
        func_0021d3b0(slot, func_0021cca0(texture, 0x44));
        func_0021d950(slot, color);
    }
}

// FUN_00248BB0 NONMATCHING
void FUN_00248bb0(void)
{
    u8* work;
    u32 texture;
    u32 frame;
    s32 i;

    K_ASSERT(sBpc324 != NULL, 0x3d);
    work = (u8*)sBpc324;
    if ((*sBpc324 & 1u) == 0) {
        return;
    }
    if ((*sBpc324 & 2u) != 0) {
        FUN_00248620();
    }
    bpc324RenderState(9, 2);
    bpc324RenderState(0x14, 2);
    bpc324RenderState(8, 0);
    texture = func_0021c3f0(1);
    frame = func_0021cce0(func_0021cca0(texture, 0));
    bpc324RenderState(1, frame);
    RpSkyRenderStateSet(3, 0x717fb);
    RpSkyRenderStateSet(2, 0x44);
    for (i = 0; i < 5; i++) {
        bpc324Draw(work + 0x310 + i * 0x100, 1, 2);
        bpc324Draw(work + 0x310 + i * 0x100, 2, 3);
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

// FUN_00248FC0 NONMATCHING
void* FUN_00248fc0(void* destination)
{
    u8* work;
    u32 texture;

    K_ASSERT(sBpc324 != NULL, 0x3d);
    work = (u8*)sBpc324;
    texture = func_0021c3f0(1);
    func_003b0d70((u32)destination, 0x640, 0x320);
    func_003b2c60((u32)destination, 0.0f);
    func_003b0e20((u32)destination, (u32)-1);
    *(void**)(work + 4) = destination;
    func_0021d3b0(work + 0x10, func_0021cca0(texture, 0x43));
    func_0021e380(work + 0x110, func_0021cca0(texture, 0x43), 1);
    func_0021d3b0(work + 0x210, func_0021cca0(texture, 0x44));
    func_0021d3b0(work + 0x310, func_0021cca0(texture, 0));
    *(u32*)(work + 8) = 0;
    *sBpc324 |= 1;
    *sBpc324 &= ~2u;
    return destination;
}

// FUN_00249130 NONMATCHING
u32 FUN_00249130(void)
{
    return bpc324Flags() & 1u;
}

// FUN_002491F0
void FUN_002491f0(void)
{
    K_ASSERT(sBpc324 != NULL, 0x3d);
    func_003b0170(*(u32*)((u8*)sBpc324 + 4));
}

// FUN_002492B0 NONMATCHING
void FUN_002492b0(void)
{
    u8* work;
    void* cursor;
    u32 mode;

    K_ASSERT(sBpc324 != NULL, 0x37);
    work = (u8*)sBpc324;
    if ((*sBpc324 & 1u) == 0) {
        return;
    }
    cursor = func_0021c550(1);
    mode = *(u32*)(work + 4);
    if (mode == 0 && func_003c7850(0) == 0) {
        func_003c7650(0);
        FUN_003c77a0(0);
        func_003c72d0(cursor);
        func_003c7bc0(0, *(u16*)(work + 0xa));
        func_003c7bc0(1, *(u16*)(work + 0xc));
        func_003c7c20(2, *(u16*)(work + 8), 5);
        func_003c7430(0);
        *(u32*)(work + 4) = 1;
    } else if (mode == 1 && func_003c7850(1) == 0) {
        func_003c7650(1);
        FUN_003c77a0(1);
        func_003c72d0(cursor);
        *sBpc324 &= ~2u;
    }
}

// FUN_00249420 NONMATCHING
void FUN_00249420(u32 result, u32 actor, u32 target)
{
    u8* work;
    void* first;
    void* second;
    void* unit;

    K_ASSERT(sBpc324 != NULL, 0x37);
    work = (u8*)sBpc324;
    first = func_0021c550(0);
    second = func_0021c550(1);
    unit = func_0030c0c0();
    K_ASSERT(unit != NULL, 0x8c);
    datSetFlag((s32)(*(u16*)unit) + 0x12c0, 1);
    datSetFlag(0x1301, 1);
    if (datGetFlag(0x1301) == 0) {
        func_003c72d0(first);
        func_003c7bc0(0, result);
        FUN_003c77a0(0);
    } else {
        func_003c72d0(second);
        func_003c7bc0(0, actor);
        func_003c7bc0(1, target);
        func_003c7c20(2, result & 0xffffu, 5);
        func_003c7430(0);
    }
    *(u16*)(work + 8) = (u16)result;
    *(u16*)(work + 0xa) = (u16)actor;
    *(u16*)(work + 0xc) = (u16)target;
    *sBpc324 |= 1;
}
