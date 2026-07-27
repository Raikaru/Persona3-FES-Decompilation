#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBrHero; // puGpffffb68c

void FUN_002630e0();
void FUN_003b0170();

// FUN_002626e0
void brHero002626e0(u32* param_1)
{
    K_ASSERT(sBrHero == NULL, 0x59);
    *param_1 = 0;
    sBrHero = param_1;
}

// FUN_00262730
void brHero00262730(void)
{
    K_ASSERT(sBrHero != NULL, 0x53);
    if (*sBrHero & 1) {
        FUN_002630e0();
    }
    sBrHero = NULL;
}

// FUN_002630e0
void brHero002630e0(void)
{
    u32* work;

    K_ASSERT(sBrHero != NULL, 0x53);
    work = sBrHero;
    K_ASSERT(*work & 1, 0x19a);
    FUN_003b0170(work[0xad4]);
    *work &= 0xfffffffe;
}
typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    s32 width;
    s32 height;
} BrHeroResource;
extern void* FUN_00233d70(s32);
extern void* FUN_00233df0(s32);
extern void* FUN_0021cca0(void*, s32);
extern u32 FUN_0021cce0(void*);
extern void FUN_0021d3b0(void*, void*);
extern void FUN_0021cd00(void*, float*);
extern void FUN_0021d8e0(void*, float*);
extern void FUN_0021d890(void*, float*);
extern void FUN_0021d950(void*, u8*);
extern void FUN_0021e380(void*, void*, s32);
extern void FUN_0021eac0(void*, float);
extern void FUN_0021eae0(void*, float*);
extern void FUN_0021eb80(void*, float*);
extern void FUN_00238980(void*, s32, s32, s32);
extern void FUN_00238dc0(void*, s32, s32, s32, float*);
extern void FUN_00238bf0(void*, s32, s32, s32, float*);
extern void* brPersonaGetPortraitFrame(s32);
extern void* brPersonaGetPortraitFrame(s32);
extern void FUN_003b0e70(s32);
extern void FUN_003b0e90(s32);
extern void FUN_003b0d70(s32, s32, s32);
extern void FUN_003b0e20(s32, s32);
extern u32 FUN_00239140(s32);
extern void RpSkyRenderStateSet(s32, void*);
extern void thunk_FUN_003b0e54(s32, s32);
extern void FUN_003b1360(s32, s32, s32);
extern void (*D_00960090)(u32, u32);
extern void (*D_0096009C)(u32*, u32, u32, u32, u32);
#pragma alias D_00960090_abs D_00960090
#pragma alias D_0096009C_abs D_0096009C
extern u8 D_00960090_abs[];
extern u8 D_0096009C_abs[];
extern u32 uGpffffb948;
extern float uGpffff83a8;
extern float uGpffff83ac;

static void brHeroSetColor(void* object, u8 r, u8 g, u8 b, u8 a)
{
    u8 color[4];
    color[0] = r;
    color[1] = g;
    color[2] = b;
    color[3] = a;
    FUN_0021d950(object, color);
}

static void brHeroSetRect(void* object, float x, float y, float w, float h)
{
    float rect[4];
    rect[0] = x;
    rect[1] = y;
    rect[2] = w;
    rect[3] = h;
    FUN_0021d8e0(object, rect);
}


// FUN_00262790 NONMATCHING
void brHero00262790(void)
{
    u32* w;
    void* value;
    void* text0;
    void* text1;
    u32 task;
    u8 color[4];
    float rect[4];
    float sourceRect[4];
    s32 i;
    void* valueLoop;
    void* tailValue;
    u32 status;
    u32 level;

    K_ASSERT(sBrHero != NULL, 0x53);
    w = sBrHero;
    text0 = FUN_00233d70(0);
    text1 = FUN_00233d70(1);
    level = FUN_0016c470(1) & 0xff;
    FUN_0016c7e0(1);
    status = FUN_0016c970(1);
    w[0x588] = level;
    w[0x591] = FUN_0016d2f0(1);
    w[0x589] = FUN_0016c4f0(1) & 0xffff;
    w[0x58b] = FUN_0016c570(1) & 0xffff;
    w[0x58a] = FUN_0016c5f0(1) & 0xffff;
    w[0x58c] = FUN_0016c670(1) & 0xffff;
    w[0x484] = (s16)FUN_00177280(FUN_0016c6f0(1)) - 1;
    w[0x485] = (s16)FUN_001772f0(FUN_0016c740(1)) - 1;
    w[0x486] = (s16)FUN_00177360(FUN_0016c790(1)) - 1;
    w[0x58d] = FUN_0016c920(1) & 0xffff;
    K_ASSERT((s32)w[0x484] >= 0, 0x89);
    K_ASSERT((s32)w[0x485] >= 0, 0x8a);
    K_ASSERT((s32)w[0x486] >= 0, 0x8b);
    w[0] &= ~2u;
    if (status & 0x80)
        w[0] |= 2;
    if ((s32)w[0x591] > 99999)
        w[0x591] = 99999;
    FUN_0021d3b0(w + 4, FUN_0021cca0(text0, 0x16));
    FUN_0021d3b0(w + 0x44, FUN_0021cca0(text0, 0x17));
    FUN_0021d3b0(w + 0x84, FUN_0021cca0(text0, 0x18));
    FUN_0021d3b0(w + 0xc4, FUN_0021cca0(text0, 0x19));
    FUN_0021d3b0(w + 0x104, FUN_0021cca0(text0, 0x1a));
    FUN_0021d3b0(w + 0x144, FUN_0021cca0(text0, 0x1b));
    {
        s32 k;
        for (k = 0; k < 3; k++)
            FUN_0021eac0(w + k * 0x40 + 0x184, 0);
        valueLoop = FUN_0021cca0(text0, 0x1c);
        for (k = 0; k < 3; k++)
            FUN_0021d3b0(w + k * 0x40 + 0x244, valueLoop);
        valueLoop = FUN_0021cca0(text0, 0x1d);
        for (k = 0; k < 3; k++)
            FUN_0021d3b0(w + k * 0x40 + 0x304, valueLoop);
    }
    FUN_0021d3b0(w + 0x3c4, FUN_0021cca0(text0, w[0x484]));
    FUN_0021d3b0(w + 0x404, FUN_0021cca0(text0, w[0x485] + 7));
    FUN_0021d3b0(w + 0x444, FUN_0021cca0(text0, w[0x486] + 0xe));
    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = 1.0f;
    rect[3] = 1.0f;
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = 0xff;
    for (i = 0; i < 2; i++)
    {
        FUN_0021eb80(w + i * 0x40 + 0x4c8, rect);
        FUN_0021eac0(w + i * 0x40 + 0x4c8, 0);
        FUN_0021d950(w + i * 0x40 + 0x4c8, color);
    }
    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = 1.0f;
    rect[3] = 1.0f;
    FUN_0021eb80(w + 0x488, rect);
    FUN_0021eac0(w + 0x488, 0);
    FUN_0021d950(w + 0x488, color);

    FUN_0021d3b0(w + 0x548, FUN_0021cca0(text1, 0));
    FUN_00238980(w + 0x594, 2, w[0x588], 2);
    FUN_00238980(w + 0x614, 3, w[0x589], 2);
    FUN_00238980(w + 0x6d4, 3, w[0x58a], 2);
    FUN_0021cd00(FUN_0021cca0(text1, 4), sourceRect);
    rect[0] = sourceRect[0];
    rect[1] = sourceRect[1];
    rect[2] = rect[0] + (float)(s32)w[0x589] * (sourceRect[2] - rect[0]) / (float)(s32)w[0x58a];
    rect[3] = sourceRect[3];
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = 0xff;
    FUN_0021eac0(w + 0x794, 0);
    FUN_0021eae0(w + 0x794, rect);
    FUN_0021d950(w + 0x794, color);
    FUN_00238980(w + 0x7d4, 3, w[0x58b], 2);
    FUN_00238980(w + 0x894, 3, w[0x58c], 2);

    FUN_0021cd00(FUN_0021cca0(text1, 5), sourceRect);
    rect[0] = sourceRect[0];
    rect[1] = sourceRect[1];
    rect[2] = rect[0] + (float)(s32)w[0x58b] * (sourceRect[2] - rect[0]) / (float)(s32)w[0x58c];
    rect[3] = sourceRect[3];
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = 0xff;
    FUN_0021eac0(w + 0x954, 0);
    FUN_0021eae0(w + 0x954, rect);
    FUN_0021d950(w + 0x954, color);

    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = 1.0f;
    rect[3] = 1.0f;
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = 0xff;
    FUN_0021eb80(w + 0xa54, rect);
    FUN_0021eac0(w + 0xa54, 0);
    FUN_0021d950(w + 0xa54, color);
    value = brPersonaGetPortraitFrame(w[0x58d]);
    FUN_0021d3b0(w + 0xa94, value);

    if (w[0] & 2)
    {
        for (i = 0; i < 6; i++)
        {
            switch (i)
            {
            case 0:
                value = FUN_0021cca0(text1, 6);
                break;
            case 1:
                value = FUN_0021cca0(text1, 7);
                break;
            case 2:
                value = FUN_0021cca0(text1, 8);
                break;
            case 3:
                value = FUN_0021cca0(text1, 10);
                break;
            case 4:
                value = FUN_0021cca0(text1, 9);
                break;
            case 5:
                value = FUN_0021cca0(text1, 9);
                break;
            }
            FUN_0021d3b0(w + i * 0x40 + 0xad8, value);
        }
    }
    FUN_003b0e70(1);
    FUN_003b0e90(2);
    uGpffffb948 = 0x78;
    task = (u32)FUN_003b0970(FUN_00177790(1), 1, 5, 0, 0);
    uGpffffb948 = 0;
    w[0xad4] = task;
    FUN_003b0e90(1);
    FUN_003b0e70(2);
    tailValue = FUN_0021cca0(text1, 0x11);
    FUN_0021d3b0(w + 0xc58, tailValue);
    FUN_0021e380(w + 0xc98, tailValue, 1);
    FUN_0021d3b0(w + 0xcd8, FUN_0021cca0(text1, 0x22));
    FUN_00238980(w + 0xd18, 5, w[0x591], 2);

    w[0xe58] = 0;
    *w |= 1;
}
// FUN_00263170 NONMATCHING
void brHero00263170(void)
{
    void* text0;
    void* text1;
    u32* w;
    BrHeroResource* resource;
    float rect[4];
    float width4;
    float offset;
    float scroll;
    u8 color[4];
    K_ASSERT(sBrHero != NULL, 0x53);
    w = sBrHero;
    if ((*w & 1) == 0)
        return;

    if ((s32)w[0xe58] < 0x41a)
        w[0xe58] += 1;
    else
        w[0xe58] = 0;

    text0 = FUN_00233d70(0);
    text1 = FUN_00233d70(1);

    resource = (BrHeroResource*)FUN_0021cca0(text0, 0x16);
    rect[0] = 21.0f;
    rect[1] = 49.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 4, rect);
    resource = (BrHeroResource*)FUN_0021cca0(text0, 0x17);
    rect[0] = 21.0f;
    rect[1] = 97.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0x44, rect);
    resource = (BrHeroResource*)FUN_0021cca0(text0, 0x18);
    rect[0] = 21.0f;
    rect[1] = 147.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0x84, rect);
    resource = (BrHeroResource*)FUN_0021cca0(text0, 0x19);
    rect[0] = 127.0f;
    rect[1] = 49.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0xc4, rect);
    resource = (BrHeroResource*)FUN_0021cca0(text0, 0x1a);
    rect[0] = 127.0f;
    rect[1] = 97.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0x104, rect);
    resource = (BrHeroResource*)FUN_0021cca0(text0, 0x1b);
    rect[0] = 127.0f;
    rect[1] = 147.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0x144, rect);

    resource = (BrHeroResource*)FUN_0021cca0(text0, 0x1c);
    rect[0] = 127.0f;
    rect[1] = 63.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0x244, rect);
    resource = (BrHeroResource*)FUN_0021cca0(text0, 0x1c);
    rect[1] = 111.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0x284, rect);
    resource = (BrHeroResource*)FUN_0021cca0(text0, 0x1c);
    rect[1] = 161.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0x2c4, rect);

    resource = (BrHeroResource*)FUN_0021cca0(text0, 0x1d);
    rect[0] = 127.0f + 20.0f * (float)(s32)w[0x484];
    rect[1] = 63.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0x304, rect);
    resource = (BrHeroResource*)FUN_0021cca0(text0, 0x1d);
    rect[0] = 127.0f + 20.0f * (float)(s32)w[0x485];
    rect[1] = 111.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0x344, rect);
    resource = (BrHeroResource*)FUN_0021cca0(text0, 0x1d);
    rect[0] = 127.0f + 20.0f * (float)(s32)w[0x486];
    rect[1] = 161.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0x384, rect);

    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = 640.0f;
    rect[3] = 37.0f;
    FUN_0021d8e0(w + 0x184, rect);
    color[0] = 0xfe;
    color[1] = 0xbd;
    color[2] = 0x5e;
    color[3] = 0xff;
    FUN_0021d950(w + 0x184, color);
    rect[0] = 0.0f;
    rect[1] = 37.0f;
    rect[2] = 640.0f;
    rect[3] = 161.0f;
    FUN_0021d8e0(w + 0x1c4, rect);
    color[0] = 0;
    color[1] = 0x28;
    color[2] = 0x3f;
    color[3] = 0xff;
    FUN_0021d950(w + 0x1c4, color);
    rect[0] = 0.0f;
    rect[1] = 198.0f;
    rect[2] = 640.0f;
    rect[3] = 448.0f;
    FUN_0021d8e0(w + 0x204, rect);
    color[0] = 0x0d;
    color[1] = 0x8a;
    color[2] = 0xeb;
    color[3] = 0xff;
    FUN_0021d950(w + 0x204, color);

    resource = (BrHeroResource*)FUN_0021cca0(text0, w[0x484]);
    rect[0] = 129.0f;
    rect[1] = 72.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0x3c4, rect);
    resource = (BrHeroResource*)FUN_0021cca0(text0, w[0x485] + 7);
    rect[0] = 129.0f;
    rect[1] = 120.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0x404, rect);
    resource = (BrHeroResource*)FUN_0021cca0(text0, w[0x486] + 0xe);
    rect[0] = 129.0f;
    rect[1] = 170.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0x444, rect);

    resource = (BrHeroResource*)FUN_00233df0(1);
    width4 = (float)(resource->width * 4);
    offset = width4 + 30.0f;
    scroll = ((float)(s32)w[0xe58] / 1050.0f) * -offset;
    rect[0] = 190.0f;
    rect[1] = scroll;
    rect[2] = (float)(resource->width * 2);
    rect[3] = width4;
    FUN_0021d8e0(w + 0x4c8, rect);
    rect[1] = scroll + offset;
    FUN_0021d8e0(w + 0x508, rect);

    rect[0] = 449.0f;
    rect[1] = 29.0f;
    rect[2] = uGpffff83a8;
    rect[3] = uGpffff83ac;
    FUN_0021d8e0(w + 0x488, rect);

    resource = (BrHeroResource*)FUN_0021cca0(text1, 0);
    rect[0] = 52.0f;
    rect[1] = 206.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0x548, rect);
    resource = (BrHeroResource*)FUN_0021cca0(text1, 4);
    rect[0] = 224.0f;
    rect[1] = 238.0f;
    rect[2] = (1.0f + (float)resource->width) * (float)w[0x589] / (float)w[0x58a];
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0x794, rect);
    resource = (BrHeroResource*)FUN_0021cca0(text1, 5);
    rect[0] = 224.0f;
    rect[1] = 254.0f;
    rect[2] = (1.0f + (float)resource->width) * (float)w[0x58b] / (float)w[0x58c];
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0x954, rect);

    FUN_00233df0(0);
    rect[0] = 50.0f;
    rect[1] = 0.0f;
    rect[2] = 353.0f;
    rect[3] = 42.0f;
    FUN_0021d8e0(w + 0xa54, rect);
    resource = (BrHeroResource*)brPersonaGetPortraitFrame(w[0x58d]);
    rect[0] = 216.0f;
    rect[1] = 255.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0xa94, rect);
    FUN_003b0d70(w[0xad4], 0x431b0 * 0x10, 0x434e0 * 8);
    FUN_003b0e20(w[0xad4], -0x33);

    resource = (BrHeroResource*)FUN_0021cca0(text1, 0x11);
    rect[0] = 51.0f;
    rect[1] = 299.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0xc58, rect);
    rect[0] = 51.0f + (float)resource->width;
    rect[2] = 106.0f;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0xc98, rect);
    resource = (BrHeroResource*)FUN_0021cca0(text1, 0x22);
    rect[0] = 305.0f;
    rect[1] = 299.0f;
    rect[2] = (float)resource->width;
    rect[3] = (float)resource->height;
    FUN_0021d8e0(w + 0xcd8, rect);
}

#define setRenderState(...) (*setRenderState)(__VA_ARGS__)
#define renderQuad(...) (*renderQuad)(__VA_ARGS__)
// FUN_00263db0 NONMATCHING
void brHero00263db0(void)
{
    u32* w;
    void* text0;
    void* text1;
    void* text3;
    s32 i;
    void (**setRenderState)(u32, u32);
    void (**renderQuad)(u32*, u32, u32, u32, u32);
    u32 texture;
    K_ASSERT(sBrHero != NULL, 0x53);
    w = sBrHero;
    if ((~*w & 1) != 0)
        return;
    text0 = FUN_00233d70(0);
    text1 = FUN_00233d70(1);
    text3 = FUN_00233d70(3);
    setRenderState = (void (**)(u32, u32))D_00960090_abs;
    setRenderState(9, 2);
    setRenderState(6, 0);
    setRenderState(8, 0);
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    setRenderState(1, 0);
    for (i = 0; i < 3; i++)
    {
        renderQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
        renderQuad(w + i * 0x40 + 0x184, 4, 0, 1, 2);
        renderQuad(w + i * 0x40 + 0x184, 4, 0, 2, 3);
    }
    texture = FUN_0021cce0(FUN_0021cca0(text0, 0x16));
    setRenderState(1, texture);
    renderQuad(w + 4, 4, 0, 1, 2);
    renderQuad(w + 4, 4, 0, 2, 3);
    texture = FUN_0021cce0(FUN_0021cca0(text0, 0x17));
    setRenderState(1, texture);
    renderQuad(w + 0x44, 4, 0, 1, 2);
    renderQuad(w + 0x44, 4, 0, 2, 3);
    texture = FUN_0021cce0(FUN_0021cca0(text0, 0x18));
    setRenderState(1, texture);
    renderQuad(w + 0x84, 4, 0, 1, 2);
    renderQuad(w + 0x84, 4, 0, 2, 3);
    texture = FUN_0021cce0(FUN_0021cca0(text0, 0x19));
    setRenderState(1, texture);
    renderQuad(w + 0xc4, 4, 0, 1, 2);
    renderQuad(w + 0xc4, 4, 0, 2, 3);
    texture = FUN_0021cce0(FUN_0021cca0(text0, 0x1a));
    setRenderState(1, texture);
    renderQuad(w + 0x104, 4, 0, 1, 2);
    renderQuad(w + 0x104, 4, 0, 2, 3);
    texture = FUN_0021cce0(FUN_0021cca0(text0, 0x1b));
    setRenderState(1, texture);
    renderQuad(w + 0x144, 4, 0, 1, 2);
    renderQuad(w + 0x144, 4, 0, 2, 3);
    texture = FUN_0021cce0(FUN_0021cca0(text0, 0x1c));
    setRenderState(1, texture);
    renderQuad(w + 0x244, 4, 0, 1, 2);
    renderQuad(w + 0x244, 4, 0, 2, 3);
    renderQuad(w + 0x284, 4, 0, 1, 2);
    renderQuad(w + 0x284, 4, 0, 2, 3);
    renderQuad(w + 0x2c4, 4, 0, 1, 2);
    renderQuad(w + 0x2c4, 4, 0, 2, 3);
    texture = FUN_0021cce0(FUN_0021cca0(text0, 0x1d));
    setRenderState(1, texture);
    for (i = 0; i < 3; i++)
    {
        renderQuad(w + i * 0x40 + 0x304, 4, 0, 1, 2);
        renderQuad(w + i * 0x40 + 0x304, 4, 0, 2, 3);
    }
    texture = FUN_0021cce0(FUN_0021cca0(text0, w[0x484]));
    setRenderState(1, texture);
    renderQuad(w + 0x3c4, 4, 0, 1, 2);
    renderQuad(w + 0x3c4, 4, 0, 2, 3);
    texture = FUN_0021cce0(FUN_0021cca0(text0, w[0x485] + 7));
    setRenderState(1, texture);
    renderQuad(w + 0x404, 4, 0, 1, 2);
    renderQuad(w + 0x404, 4, 0, 2, 3);
    texture = FUN_0021cce0(FUN_0021cca0(text0, w[0x486] + 0xe));
    setRenderState(1, texture);
    renderQuad(w + 0x444, 4, 0, 1, 2);
    renderQuad(w + 0x444, 4, 0, 2, 3);
    setRenderState(1, FUN_0021cce0(FUN_00233df0(0)));
    renderQuad(w + 0xa54, 4, 0, 1, 2);
    renderQuad(w + 0xa54, 4, 0, 2, 3);
    setRenderState(1, FUN_0021cce0(FUN_00233df0(1)));
    for (i = 0; i < 2; i++)
    {
        renderQuad(w + i * 0x40 + 0x4c8, 4, 0, 1, 2);
        renderQuad(w + i * 0x40 + 0x4c8, 4, 0, 2, 3);
    }
    setRenderState(1, FUN_0021cce0(FUN_0021cca0(text3, 0)));
    renderQuad(w + 0x488, 4, 0, 1, 2);
    renderQuad(w + 0x488, 4, 0, 2, 3);
    setRenderState(1, FUN_0021cce0(FUN_0021cca0(text1, 0)));
    renderQuad(w + 0x548, 4, 0, 1, 2);
    renderQuad(w + 0x548, 4, 0, 2, 3);
    setRenderState(1, FUN_00239140(2));
    for (i = 0; i < 2; i++)
    {
        renderQuad(w + i * 0x40 + 0x594, 4, 0, 1, 2);
        renderQuad(w + i * 0x40 + 0x594, 4, 0, 2, 3);
    }
    setRenderState(1, FUN_00239140(2));
    for (i = 0; i < 3; i++)
    {
        renderQuad(w + i * 0x40 + 0x614, 4, 0, 1, 2);
        renderQuad(w + i * 0x40 + 0x614, 4, 0, 2, 3);
    }
    setRenderState(1, FUN_00239140(2));
    for (i = 0; i < 3; i++)
    {
        renderQuad(w + i * 0x40 + 0x6d4, 4, 0, 1, 2);
        renderQuad(w + i * 0x40 + 0x6d4, 4, 0, 2, 3);
    }
    setRenderState(1, FUN_0021cce0(FUN_0021cca0(text1, 4)));
    renderQuad(w + 0x794, 4, 0, 1, 2);
    renderQuad(w + 0x794, 4, 0, 2, 3);
    setRenderState(1, FUN_00239140(2));
    for (i = 0; i < 3; i++)
    {
        renderQuad(w + i * 0x40 + 0x7d4, 4, 0, 1, 2);
        renderQuad(w + i * 0x40 + 0x7d4, 4, 0, 2, 3);
    }
    setRenderState(1, FUN_00239140(2));
    for (i = 0; i < 3; i++)
    {
        renderQuad(w + i * 0x40 + 0x894, 4, 0, 1, 2);
        renderQuad(w + i * 0x40 + 0x894, 4, 0, 2, 3);
    }
    setRenderState(1, FUN_0021cce0(FUN_0021cca0(text1, 5)));
    renderQuad(w + 0x954, 4, 0, 1, 2);
    renderQuad(w + 0x954, 4, 0, 2, 3);
    setRenderState(1, FUN_0021cce0(brPersonaGetPortraitFrame(w[0x58d])));
    renderQuad(w + 0xa94, 4, 0, 1, 2);
    renderQuad(w + 0xa94, 4, 0, 2, 3);
    FUN_003b1360(w[0xad4], 1, 0);
    setRenderState(1, FUN_0021cce0(FUN_0021cca0(text1, 0x11)));
    renderQuad(w + 0xc58, 4, 0, 1, 2);
    renderQuad(w + 0xc58, 4, 0, 2, 3);
    renderQuad(w + 0xc98, 4, 0, 1, 2);
    renderQuad(w + 0xc98, 4, 0, 2, 3);
    setRenderState(1, FUN_0021cce0(FUN_0021cca0(text1, 0x22)));
    renderQuad(w + 0xcd8, 4, 0, 1, 2);
    renderQuad(w + 0xcd8, 4, 0, 2, 3);
    setRenderState(1, FUN_00239140(2));
    for (i = 0; i < 5; i++)
    {
        renderQuad(w + i * 0x40 + 0xd18, 4, 0, 1, 2);
        renderQuad(w + i * 0x40 + 0xd18, 4, 0, 2, 3);
    }
}
#undef setRenderState
#undef renderQuad
