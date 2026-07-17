#include "Utils.h"
#include "Kosaka/k_assert.h"

/* DAT_007CE348: panel effect work installed by FUN_0024C100. */
static u32* sBpEffect;

extern void func_0010a4e0(s32, s32, s32, s32);
extern void* func_0021c790(void* frame);
extern void func_0021d890(void* destination, const f32* vertices);
extern void func_0021d8e0(void* destination, const f32* layout);
extern void func_0021d950(void* destination, const u8* color);
extern void func_0021eac0(void* destination, f32 value);
extern void func_0021eb80(void* destination, const f32* layout);
extern f32 DAT_007cad60;
extern f32 DAT_007cafec;
extern void RpSkyRenderStateSet(s32 state, u32 value);
extern u32 D_00960090[];
extern u32 D_0096009c[];

typedef void (*BpEffectSetRenderState)(s32 state, u32 value);
typedef void (*BpEffectRenderQuad)(void* quad, s32 layer, s32 group, s32 pass, s32 blend);

// FUN_0024C100
void FUN_0024c100(u32* work)
{
    work[1] = 0;
    sBpEffect = work;
}

// FUN_0024C110 NONMATCHING
void FUN_0024c110(void)
{
    u8* work;
    s32 timer;
    u32 mode;
    f32 fade;
    f32 pulse;
    f32 rect[4];
    s32 i;

    K_ASSERT(sBpEffect != NULL, 0x37);
    work = (u8*)sBpEffect;
    if (~(*(u32*)(work + 4)) & 1)
    {
        return;
    }
    timer = *(s32*)(work + 0xc);
    if (timer < 0x3c) {
        timer++;
        *(u32*)(work + 0xc) = timer;
    } else {
        *(u32*)(work + 4) &= ~1u;
        return;
    }
    if (timer == 14) {
        func_0010a4e0(1, 0, 7, 5);
    }
    mode = *(u32*)work;
    if (timer < 10) {
        fade = 0.0f;
    } else if (timer < 15) {
        fade = (f32)(timer - 10) / 5.0f;
    } else if (timer < 0x2a) {
        fade = 1.0f;
    } else if (timer < 0x32) {
        fade = 1.0f - (f32)(timer - 0x29) / 8.0f;
    } else {
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
}

// FUN_0024CCA0
void FUN_0024cca0(void)
{
    u8* work;
    BpEffectSetRenderState* setRenderState;
    BpEffectRenderQuad* renderQuad;

    K_ASSERT(sBpEffect != NULL, 0x37);
    work = (u8*)sBpEffect;
    if (~(*(u32*)(work + 4)) & 1)
    {
        return;
    }

    RpSkyRenderStateSet(3, 0x717fb);
    RpSkyRenderStateSet(2, 0x44);
    setRenderState = (BpEffectSetRenderState*)D_00960090;
    (*setRenderState)(8, 0);
    (*setRenderState)(6, 0);
    (*setRenderState)(1, 0);
    renderQuad = (BpEffectRenderQuad*)D_0096009c;
    (*renderQuad)(work + 0x10, 4, 0, 1, 2);
    (*renderQuad)(work + 0x10, 4, 0, 2, 3);

    (*setRenderState)(1, 0);
    (*renderQuad)(work + 0x310, 3, 0, 1, 2);

    (*setRenderState)(1, (u32)func_0021c790(*(void**)work));
    RpSkyRenderStateSet(3, 0x717fb);
    RpSkyRenderStateSet(2, 0x44);
    (*renderQuad)(work + 0x110, 4, 0, 1, 2);
    (*renderQuad)(work + 0x110, 4, 0, 2, 3);

    (*setRenderState)(1, (u32)func_0021c790(*(void**)work));
    RpSkyRenderStateSet(3, 0x71801);
    RpSkyRenderStateSet(2, 0x48);
    (*renderQuad)(work + 0x210, 4, 0, 1, 2);
    (*renderQuad)(work + 0x210, 4, 0, 2, 3);
}

// FUN_0024CF00
void FUN_0024cf00(s32 mode)
{
    u8* work;
    s32* metrics;
    f32 layout[4];
    s32 width;
    s32 height;

    K_ASSERT(sBpEffect != NULL, 0x37);
    work = (u8*)sBpEffect;
    metrics = (s32*)func_0021c790((void*)mode);
    width = metrics[3];
    height = metrics[4];

    switch (mode)
    {
    case 0:
        layout[0] = 1.0f / width;
        layout[1] = 1.0f / height;
        layout[2] = 417.0f / width;
        layout[3] = 250.0f / height;
        break;
    case 1:
        layout[0] = 0.0f / width;
        layout[1] = 0.0f / height;
        layout[2] = 428.0f / width;
        layout[3] = 256.0f / height;
        break;
    }
    func_0021eb80(work + 0x110, layout);
    func_0021eac0(work + 0x110, 0.0f);
    func_0021eb80(work + 0x210, layout);
    func_0021eac0(work + 0x210, 0.0f);
    func_0021eac0(work + 0x10, 0.0f);
    *(u32*)(work + 0x318) = 0;
    *(u32*)(work + 0x318) = 0;
    *(u32*)(work + 0x318) = 0;
    *(void**)(work + 0) = (void*)mode;
    *(u32*)(work + 8) = 0;
    *(u32*)(work + 0xc) = 0;
    *(u32*)(work + 4) |= 1;
}
