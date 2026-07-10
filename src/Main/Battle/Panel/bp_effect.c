#include "Utils.h"
#include "Kosaka/k_assert.h"

/* DAT_007CE348: panel effect work installed by FUN_0024C100. */
static u32* sBpEffect;

extern void func_0010a4e0(s32, s32, s32, s32);
extern void* func_0021c790(void* frame);
extern void func_0021eac0(void* destination, f32 value);
extern void func_0021eb80(void* destination, const f32* layout);
extern void RpSkyRenderStateSet(s32 state, u32 value);
extern u32 D_00960090[];
extern u32 D_0096009c[];

static void bpEffectSetState(u32 state, u32 value)
{
    typedef void (*Callback)(u32, u32);
    ((Callback)(void*)D_00960090)(state, value);
}

static void bpEffectDraw(void* quad, s32 pass, s32 blend)
{
    typedef void (*Callback)(void*, s32, s32, s32, s32);
    ((Callback)(void*)D_0096009c)(quad, 4, 0, pass, blend);
}

// FUN_0024C100 NONMATCHING
void FUN_0024c100(u32* work)
{
    K_ASSERT(work != NULL, 0x37);
    work[1] = 0;
    sBpEffect = work;
}

// FUN_0024C110 NONMATCHING
void FUN_0024c110(void)
{
    u8* work;
    u32 mode;
    u32 timer;
    f32 fade;
    f32 pulse;
    f32 rect[4];
    s32 i;

    K_ASSERT(sBpEffect != NULL, 0x37);
    work = (u8*)sBpEffect;
    if ((*(u32*)(work + 4) & 1u) != 0) {
        return;
    }
    timer = *(u32*)(work + 0xc);
    if (timer < 0x3c) {
        timer++;
        *(u32*)(work + 0xc) = timer;
    } else {
        *(u32*)(work + 4) &= ~2u;
    }
    mode = *(u32*)work;
    if (timer < 10) {
        fade = 0.0f;
    } else if (timer < 15) {
        fade = (f32)(timer - 10) / 5.0f;
    } else if (timer < 45) {
        fade = 1.0f;
    } else {
        fade = 1.0f - (f32)(timer - 45) / 15.0f;
    }
    if (fade < 0.0f) {
        fade = 0.0f;
    }
    pulse = mode == 1 ? 1.0f : 0.0f;
    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = mode == 1 ? 438.0f : 417.0f;
    rect[3] = mode == 1 ? 256.0f : 250.0f;
    func_0021eb80(work + 0x110, rect);
    func_0021eb80(work + 0x210, rect);
    func_0021eac0(work + 0x110, fade);
    func_0021eac0(work + 0x210, fade);
    func_0021eac0(work + 0x10, fade * (0.8f + pulse * 0.2f));
    for (i = 0; i < 3; i++) {
        *(f32*)(work + 0x310 + i * 0x40) = fade;
    }
    if (timer == 14) {
        func_0010a4e0(1, 0, 7, 5);
    }
}

// FUN_0024CCA0 NONMATCHING
void FUN_0024cca0(void)
{
    u8* work;
    u32 mode;
    s32 i;

    K_ASSERT(sBpEffect != NULL, 0x37);
    work = (u8*)sBpEffect;
    if ((*(u32*)(work + 4) & 1u) != 0) {
        return;
    }
    mode = *(u32*)work;
    RpSkyRenderStateSet(3, 0x717fb);
    RpSkyRenderStateSet(2, 0x44);
    bpEffectSetState(8, 0);
    bpEffectSetState(6, 0);
    bpEffectSetState(1, 0);
    bpEffectDraw(work + 0x10, 1, 2);
    bpEffectDraw(work + 0x10, 2, 3);
    bpEffectSetState(1, 0);
    bpEffectDraw(work + 0x310, 1, 2);
    RpSkyRenderStateSet(3, 0x717fb);
    RpSkyRenderStateSet(2, 0x44);
    bpEffectDraw(work + 0x110, 1, 2);
    bpEffectDraw(work + 0x110, 2, 3);
    if (mode != 0) {
        RpSkyRenderStateSet(3, 0x71801);
        RpSkyRenderStateSet(2, 0x48);
        bpEffectDraw(work + 0x210, 1, 2);
        bpEffectDraw(work + 0x210, 2, 3);
    }
    for (i = 0; i < 3; i++) {
        *(u32*)(work + 0x318 + i * 4) = 0;
    }
}

// FUN_0024CF00 NONMATCHING
void FUN_0024cf00(void* frame)
{
    u8* work;
    u32* metrics;
    f32 layout[4];
    f32 width;
    f32 height;

    K_ASSERT(sBpEffect != NULL, 0x37);
    K_ASSERT(frame != NULL, 0x37);
    work = (u8*)sBpEffect;
    metrics = (u32*)func_0021c790(frame);
    width = metrics != NULL && metrics[3] != 0 ?
        1.0f / (f32)metrics[3] : 0.0f;
    height = metrics != NULL && metrics[4] != 0 ?
        1.0f / (f32)metrics[4] : 0.0f;
    layout[0] = width;
    layout[1] = height;
    layout[2] = 417.0f * width;
    layout[3] = 250.0f * height;
    func_0021eb80(work + 0x110, layout);
    func_0021eac0(work + 0x110, 0.0f);
    func_0021eb80(work + 0x210, layout);
    func_0021eac0(work + 0x210, 0.0f);
    func_0021eac0(work + 0x10, 0.0f);
    *(void**)(work + 0) = frame;
    *(u32*)(work + 8) = 0;
    *(u32*)(work + 0xc) = 0;
    *(u32*)(work + 4) |= 1;
}
