#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

#include "Utils.h"
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





#define BAI_MAIN_ACTIVE 1

static inline f32 baiMul(f32 left, f32 right)
{
    return left * right;
}

typedef struct
{
    u32 unk0;  // 0x00
    u32 flags; // 0x04. See BAI_MAIN_*
} BaiMainWork;

static BaiMainWork* sBaiMain; // DAT_007ce338

/* W419 negative probe: placing static sBpEffect in .sdata left FUN_0024C110 at nd1500/2888B, window2960B, rate51.94%; reverted. */
// FUN_0024C110 NONMATCHING
void FUN_0024c110(void)
{
    u8* work;
    f32 rect[4];
    f32 vertices[8];
    u8 color[4];
    f32 fade;
    f32 baseX;
    f32 baseY;
    f32 offsetX;
    f32 offsetY;
    f32 overlayScale;
    f32 phase;
    f32 centerX;
    f32 centerY;
    s32 i;
    s32 timer;

    K_ASSERT(sBpEffect != NULL, 0x37);
    work = (u8*)sBpEffect;
    if (~(*(u32*)(work + 4)) & 1)
    {
        return;
    }

    if (*(s32*)(work + 0xc) < 0x3c) {
        (*(s32*)(work + 0xc))++;
    } else {
        *(u32*)(work + 4) &= ~1u;
        return;
    }

    if (*(s32*)(work + 0xc) == 14) {
        func_0010a4e0(1, 0, 7, 5);
    }
    switch (*(u32*)work)
    {
    case 0:
        baseX = 60.0f;
        baseY = -40.0f;
        break;
    case 1:
        baseX = -60.0f;
        baseY = 40.0f;
        break;
    }

    if (*(s32*)(work + 0xc) < 10) {
        fade = 0.0f;
        offsetX = 0.0f;
        offsetY = 0.0f;
    } else if (*(s32*)(work + 0xc) < 15) {
        fade = (f32)(*(s32*)(work + 0xc) - 10) / 5.0f;
        offsetX = baseX * (1.0f - fade);
        offsetY = baseY * (1.0f - fade);
    } else if (*(s32*)(work + 0xc) < 0x2a) {
        fade = 1.0f;
        offsetX = 0.0f;
        offsetY = 0.0f;
    } else if (*(s32*)(work + 0xc) < 0x32) {
        phase = (f32)(*(s32*)(work + 0xc) - 0x2a) / 8.0f;
        fade = 1.0f - phase;
        offsetX = baiMul(baiMul(DAT_007cad60, (-baseX) * 3.5f), phase);
        offsetY = baiMul(baiMul(DAT_007cad60, (-baseY) * 3.0f), phase);
    } else {
        fade = 0.0f;
        offsetX = 0.0f;
        offsetY = 0.0f;
    }

    rect[0] = 210.0f + offsetX;
    rect[1] = 178.0f + offsetY;
    switch (*(u32*)work)
    {
    case 0:
        rect[2] = (f32)0x1a1;
        rect[3] = 250.0f;
        break;
    case 1:
        rect[2] = 428.0f;
        rect[3] = 256.0f;
        break;
    }
    func_0021d8e0(work + 0x110, rect);

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(255.0f * fade);
    func_0021d950(work + 0x110, color);

    if (*(s32*)(work + 0xc) < 10) {
        baseY = 0.0f;
        baseX = 1.0f;
        overlayScale = baseX;
    } else if (*(s32*)(work + 0xc) < 15) {
        baseY = (f32)(*(s32*)(work + 0xc) - 10) / 5.0f;
        baseX = 1.0f;
        overlayScale = baseX + DAT_007cafec * (baseX - baseY);
    } else if (*(s32*)(work + 0xc) < 0x2d) {
        baseX = 1.0f;
        baseY = baseX;
        overlayScale = baseX;
    } else if (*(s32*)(work + 0xc) < 0x37) {
        baseY = (f32)(*(s32*)(work + 0xc) - 0x2d) / 8.0f;
        baseX = 1.0f;
        baseY = baseX - baseY;
        overlayScale = baseX;
    } else {
        baseY = 0.0f;
        baseX = 1.0f;
        overlayScale = baseX;
    }

    rect[0] = 210.0f;
    rect[1] = 178.0f;
    switch (*(u32*)work)
    {
    case 0:
        rect[2] = (f32)0x1a1;
        rect[3] = 250.0f;
        break;
    case 1:
        rect[2] = 428.0f;
        rect[3] = 256.0f;
        break;
    }

    vertices[0] = rect[0];
    vertices[1] = rect[1];
    vertices[2] = rect[0] + rect[2];
    vertices[3] = rect[1];
    vertices[4] = vertices[2];
    vertices[5] = rect[1] + rect[3];
    vertices[6] = rect[0];
    vertices[7] = vertices[5];

    centerX = rect[2] / 2.0f;
    centerY = rect[3] / 2.0f;
    for (i = 0; i < 4; i++) {
        vertices[i * 2] -= centerX;
        vertices[i * 2 + 1] -= centerY;
    }
    for (i = 0; i < 4; i++) {
        vertices[i * 2] *= overlayScale;
        vertices[i * 2 + 1] *= overlayScale;
    }
    for (i = 0; i < 4; i++) {
        vertices[i * 2] += centerX;
        vertices[i * 2 + 1] += centerY;
    }
    func_0021d890(work + 0x210, vertices);

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(255.0f * baseY);
    func_0021d950(work + 0x210, color);
    timer = *(s32*)(work + 0xc);

    if (timer < 12) {
        baseX = (f32)timer / 12.0f;
    } else if (timer < 0x30) {
        baseX = 1.0f;
    } else {
        baseX = 1.0f - (f32)(timer - 0x30) / 12.0f;
    }

    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = 640.0f;
    rect[3] = 448.0f;
    func_0021d8e0(work + 0x10, rect);

    switch (*(u32*)work)
    {
    case 0:
        color[0] = 0;
        color[1] = 0x11;
        color[2] = 0x48;
        break;
    case 1:
        color[0] = 0x37;
        color[1] = 0;
        color[2] = 3;
        break;
    }
    color[3] = (u8)(u32)(153.0f * baseX);
    func_0021d950(work + 0x10, color);

    *(f32*)(work + 0x310) = -360.0f;
    *(f32*)(work + 0x314) = 448.0f;
    *(f32*)(work + 0x350) = 640.0f;
    *(f32*)(work + 0x354) = 148.0f;
    *(f32*)(work + 0x390) = 640.0f;
    *(f32*)(work + 0x394) = 448.0f;

    switch (*(u32*)work)
    {
    case 0:
        color[0] = 0;
        color[1] = 0x44;
        color[2] = 0xc8;
        break;
    case 1:
        color[0] = 0x2d;
        color[1] = 2;
        color[2] = 8;
        break;
    }
    color[3] = 0;
    *(f32*)(work + 0x330) = (f32)color[0];
    *(f32*)(work + 0x334) = (f32)color[1];
    *(f32*)(work + 0x338) = (f32)color[2];
    *(f32*)(work + 0x33c) = (f32)color[3];
    *(f32*)(work + 0x370) = (f32)color[0];
    *(f32*)(work + 0x374) = (f32)color[1];
    *(f32*)(work + 0x378) = (f32)color[2];
    *(f32*)(work + 0x37c) = (f32)color[3];
    color[3] = (u8)(255.0f * baseX);
    *(f32*)(work + 0x3b0) = (f32)color[0];
    *(f32*)(work + 0x3b4) = (f32)color[1];
    *(f32*)(work + 0x3b8) = (f32)color[2];
    *(f32*)(work + 0x3bc) = (f32)color[3];
}



/* DAT_007CE348: panel effect work installed by FUN_0024C100. */




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

// FUN_0024d0c0
u32 baiMainIsActive(void)
{
    K_ASSERT(sBaiMain != NULL, 0x37);
    return sBaiMain->flags & BAI_MAIN_ACTIVE;
}
