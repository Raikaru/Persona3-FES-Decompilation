#include "Utils.h"
#include "Kosaka/k_assert.h"

/* BPC panel subtask state at DAT_007CE324 / GP -0x49CC. */
u32* sBpc324;
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
extern void func_003b2c60(u32 resource, f32 angle);
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
    func_003b2c60((u32)destination, 0.0f);
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

// FUN_002492B0
void FUN_002492b0(void)
{
    u8* work;
    void* cursor;
    s32 mode;

    K_ASSERT(sBpc328 != NULL, 0x37);
    work = (u8*)sBpc328;
    if (!(~(*(u32*)work) & 1u)) {
        cursor = func_0021c550(1);
        mode = *(s32*)(work + 4);
        switch (mode) {
        case 0:
            func_003c7990(0);
            if (func_003c7850() == 0) {
                func_003c7650(0);
                func_003c77a0();
                func_003c72d0(cursor);
                func_003c7bc0(0, func_00173220(*(u16*)(work + 0xa)));
                func_003c7bc0(1, func_00173220(*(u16*)(work + 0xc)));
                func_003c7c20(2, *(u16*)(work + 8), 5);
                func_003c7430(0);
                *(s32*)(work + 4) = 1;
                return;
            }
            break;
        case 1:
            func_003c7990(1);
            if (func_003c7850() == 0) {
                func_003c7650(1);
                func_003c77a0();
                *(u32*)work &= ~1u;
            }
            break;
        }
    }
}

// FUN_00249420
void FUN_00249420(u16 result, u16 actor, u16 target)
{
    u8* work;
    void* first;
    void* second;
    u16* unit;
    s32 firstMessage;

    K_ASSERT(sBpc328 != NULL, 0x37);
    work = (u8*)sBpc328;
    first = func_0021c550(0);
    second = func_0021c550(1);
    firstMessage = !(datGetFlag(0x1301) != 0);
    unit = func_0030c0c0();
    K_ASSERT(unit != NULL, 0x8c);
    datSetFlag(*unit + 0x12c0, 1);
    datSetFlag(0x1301, 1);
    if (firstMessage) {
        func_003c94e0(first);
        func_003c7bc0(0, func_001775a0(1));
        func_003c9790(0);
        *(s32*)(work + 4) = 0;
    } else {
        func_003c72d0(second);
        func_003c7bc0(0, func_00173220(actor));
        func_003c7bc0(1, func_00173220(target));
        func_003c7c20(2, (u16)result, 5);
        func_003c7430(0);
        *(s32*)(work + 4) = 1;
    }
    *(s16*)(work + 8) = result;
    *(s16*)(work + 0xa) = actor;
    *(s16*)(work + 0xc) = target;
    *(u32*)work |= 1u;
}
