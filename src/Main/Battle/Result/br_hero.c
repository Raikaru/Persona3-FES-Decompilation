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
extern u32 FUN_00233d70();
extern u32 FUN_00233d70();
extern u32 FUN_0016c470();
extern u32 FUN_0016c7e0();
extern u32 FUN_0016c970();
extern u32 FUN_0016d2f0();
extern u32 FUN_0016c4f0();
extern u32 FUN_0016c570();
extern u32 FUN_0016c5f0();
extern u32 FUN_0016c670();
extern u32 FUN_0016c6f0();
extern u32 FUN_00177280();
extern u32 FUN_0016c740();
extern u32 FUN_001772f0();
extern u32 FUN_0016c790();
extern u32 FUN_00177360();
extern u32 FUN_0016c920();
extern u32 FUN_0011f780();
extern u32 FUN_00177790();
extern u32 FUN_0021cca0();
extern void FUN_0021d3b0();
extern void FUN_0021d8e0();
extern void FUN_0021d890();
extern void FUN_0021d950();
extern void FUN_0021e380();
extern void FUN_0021eac0();
extern void FUN_0021eae0();
extern void FUN_0021eb80();
extern void FUN_00238980();
extern void FUN_00238dc0();
extern void FUN_00238bf0();
extern u32 FUN_00233df0();
extern u32 FUN_003b0970();
extern void FUN_003b0e70();
extern void FUN_003b0e90();
extern void FUN_003b0d70();
extern void thunk_FUN_003b0e54();
extern void FUN_003b1360();
extern u32 FUN_00239140();
extern void (*D_00960090)(u32, u32);
extern void (*D_0096009C)(u32*, u32, u32, u32, u32);
extern u32 uGpffffb948;
extern u32 uGpffff83a8;
extern u32 uGpffff83ac;

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
    u32 text0;
    u32 text1;
    u32 value;
    float rect[4];
    u8 color[4] = {0xff, 0xff, 0xff, 0xff};
    s32 i;
    static const s32 menuIds[6] = {6, 7, 8, 10, 9, 9};

    K_ASSERT(sBrHero != NULL, 0x53);
    w = sBrHero;
    text0 = FUN_00233d70(0);
    text1 = FUN_00233d70(1);
    w[0x588] = FUN_0016c470(1) & 0xff;
    FUN_0016c7e0(1);
    (void)FUN_0016c970(1);
    w[0x591] = FUN_0016d2f0(1);
    w[0x589] = FUN_0016c4f0(1) & 0xffff;
    w[0x58b] = FUN_0016c570(1) & 0xffff;
    w[0x58a] = FUN_0016c5f0(1) & 0xffff;
    w[0x58c] = FUN_0016c670(1) & 0xffff;
    w[0x484] = (s32)FUN_00177280(FUN_0016c6f0(1)) - 1;
    w[0x485] = (s32)FUN_001772f0(FUN_0016c740(1)) - 1;
    w[0x486] = (s32)FUN_00177360(FUN_0016c790(1)) - 1;
    w[0x58d] = FUN_0016c920(1) & 0xffff;
    K_ASSERT((s32)w[0x484] >= 0, 0x89);
    K_ASSERT((s32)w[0x485] >= 0, 0x8a);
    K_ASSERT((s32)w[0x486] >= 0, 0x8b);
    w[0] &= ~2u;
    if (FUN_0016c970(1) & 0x80)
        w[0] |= 2;
    if (w[0x591] > 99999)
        w[0x591] = 99999;

    for (i = 0; i < 6; i++)
        FUN_0021d3b0(w + i * 0x40 + 4, FUN_0021cca0(text0, 0x16 + i));
    for (i = 0; i < 3; i++)
        FUN_0021eac0(w + i * 0x40 + 0x184, 0);
    value = FUN_0021cca0(text0, 0x1c);
    for (i = 0; i < 3; i++)
        FUN_0021d3b0(w + i * 0x40 + 0x244, value);
    value = FUN_0021cca0(text0, 0x1d);
    for (i = 0; i < 3; i++)
        FUN_0021d3b0(w + i * 0x40 + 0x304, value);
    FUN_0021d3b0(w + 0x3c4, FUN_0021cca0(text0, w[0x484]));
    FUN_0021d3b0(w + 0x404, FUN_0021cca0(text0, w[0x485] + 7));
    FUN_0021d3b0(w + 0x444, FUN_0021cca0(text0, w[0x486] + 0xe));

    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = 1.0f;
    rect[3] = 1.0f;
    for (i = 0; i < 2; i++)
    {
        FUN_0021eb80(w + i * 0x40 + 0x4c8, rect);
        FUN_0021eac0(w + i * 0x40 + 0x4c8, 0);
        FUN_0021d950(w + i * 0x40 + 0x4c8, color);
    }
    FUN_0021eb80(w + 0x488, rect);
    FUN_0021eac0(w + 0x488, 0);
    FUN_0021d950(w + 0x488, color);

    FUN_0021d3b0(w + 0x548, FUN_0021cca0(text1, 0));
    FUN_00238980(w + 0x594, 2, w[0x588], 2);
    FUN_00238980(w + 0x614, 3, w[0x589], 2);
    FUN_00238980(w + 0x6d4, 3, w[0x58a], 2);
    FUN_0021d3b0(w + 0x794, FUN_0021cca0(text1, 4));
    FUN_00238980(w + 0x7d4, 3, w[0x58b], 2);
    FUN_00238980(w + 0x894, 3, w[0x58c], 2);
    FUN_0021d3b0(w + 0x954, FUN_0021cca0(text1, 5));
    FUN_0021eb80(w + 0xa54, rect);
    FUN_0021eac0(w + 0xa54, 0);
    FUN_0021d950(w + 0xa54, color);
    FUN_0021d3b0(w + 0xa94, brPersona00264ca0(w[0x58d]));

    if (w[0] & 2)
        for (i = 0; i < 6; i++)
            FUN_0021d3b0(w + i * 0x40 + 0xad8, FUN_0021cca0(text1, menuIds[i]));
    FUN_003b0e70(1);
    FUN_003b0e90(2);
    uGpffffb948 = 0x78;
    value = FUN_003b0970(FUN_00177790(1), 1, 5, 0, 0);
    uGpffffb948 = 0;
    w[0xad4] = value;
    FUN_003b0e90(1);
    FUN_003b0e70(2);
    value = FUN_0021cca0(text1, 0x11);
    FUN_0021d3b0(w + 0xc58, value);
    FUN_0021e380(w + 0xc98, value, 1);
    value = FUN_0021cca0(text1, 0x22);
    FUN_0021d3b0(w + 0xcd8, value);
    FUN_00238980(w + 0xd18, 5, w[0x591], 2);
    w[0xe58] = 0;
    *w |= 1;
}

// FUN_00263170 NONMATCHING
void brHero00263170(void)
{
    u32* w;
    u32 text0;
    u32 text1;
    u32 resource;
    float scroll;
    s32 i;
    static const float cardX[6] = {21.0f, 21.0f, 21.0f, 127.0f, 127.0f, 127.0f};
    static const float cardY[6] = {49.0f, 97.0f, 147.0f, 49.0f, 97.0f, 147.0f};

    K_ASSERT(sBrHero != NULL, 0x53);
    w = sBrHero;
    if ((*w & 1) == 0)
        return;
    w[0xe58] = w[0xe58] < 0x41a ? w[0xe58] + 1 : 0;
    text0 = FUN_00233d70(0);
    text1 = FUN_00233d70(1);
    for (i = 0; i < 6; i++)
    {
        resource = FUN_0021cca0(text0, 0x16 + i);
        brHeroSetRect(w + i * 0x40 + 4, cardX[i], cardY[i],
                      (float)*(s32*)(resource + 0x0c), (float)*(s32*)(resource + 0x10));
    }
    resource = FUN_0021cca0(text0, 0x1c);
    for (i = 0; i < 3; i++)
        brHeroSetRect(w + i * 0x40 + 0x244, 127.0f, 63.0f + i * 48.0f,
                      (float)*(s32*)(resource + 0x0c), (float)*(s32*)(resource + 0x10));
    resource = FUN_0021cca0(text0, 0x1d);
    for (i = 0; i < 3; i++)
        brHeroSetRect(w + i * 0x40 + 0x304,
                      (float)(s32)w[0x484 + i] * 20.0f + 127.0f,
                      63.0f + i * 48.0f,
                      (float)*(s32*)(resource + 0x0c), (float)*(s32*)(resource + 0x10));
    brHeroSetRect(w + 0x184, 0.0f, 0.0f, 640.0f, 37.0f);
    brHeroSetColor(w + 0x184, 0xfe, 0xbd, 0x5e, 0xff);
    brHeroSetRect(w + 0x1c4, 0.0f, 37.0f, 640.0f, 161.0f);
    brHeroSetColor(w + 0x1c4, 0, 0x28, 0x3f, 0xff);
    brHeroSetRect(w + 0x204, 0.0f, 198.0f, 640.0f, 448.0f);
    brHeroSetColor(w + 0x204, 0x0d, 0x8a, 0xeb, 0xff);
    resource = FUN_0021cca0(text0, w[0x484]);
    brHeroSetRect(w + 0x3c4, 129.0f, 72.0f,
                  (float)*(s32*)(resource + 0x0c), (float)*(s32*)(resource + 0x10));
    resource = FUN_0021cca0(text0, w[0x485] + 7);
    brHeroSetRect(w + 0x404, 129.0f, 120.0f,
                  (float)*(s32*)(resource + 0x0c), (float)*(s32*)(resource + 0x10));
    resource = FUN_0021cca0(text0, w[0x486] + 0xe);
    brHeroSetRect(w + 0x444, 129.0f, 170.0f,
                  (float)*(s32*)(resource + 0x0c), (float)*(s32*)(resource + 0x10));
    resource = FUN_00233df0(1);
    scroll = ((float)(s32)w[0xe58] / 1050.0f) *
             -((float)*(s32*)(resource + 0x0c) * 4.0f + 30.0f);
    brHeroSetRect(w + 0x4c8, 190.0f, scroll,
                  (float)*(s32*)(resource + 0x0c) * 2.0f,
                  (float)*(s32*)(resource + 0x0c) * 4.0f);
    brHeroSetRect(w + 0x508, 190.0f, scroll + (float)*(s32*)(resource + 0x0c) * 4.0f + 30.0f,
                  (float)*(s32*)(resource + 0x0c) * 2.0f,
                  (float)*(s32*)(resource + 0x0c) * 4.0f);
    brHeroSetRect(w + 0x488, 449.0f, 29.0f, (float)uGpffff83a8, (float)uGpffff83ac);
    resource = FUN_0021cca0(text1, 0);
    brHeroSetRect(w + 0x548, 52.0f, 206.0f,
                  (float)*(s32*)(resource + 0x0c), (float)*(s32*)(resource + 0x10));
    resource = FUN_0021cca0(text1, 4);
    brHeroSetRect(w + 0x794, 224.0f, 238.0f,
                  ((float)*(s32*)(resource + 0x0c) + 1.0f) * w[0x589] / w[0x58a],
                  (float)*(s32*)(resource + 0x10));
    resource = FUN_0021cca0(text1, 5);
    brHeroSetRect(w + 0x954, 224.0f, 254.0f,
                  ((float)*(s32*)(resource + 0x0c) + 1.0f) * w[0x58b] / w[0x58c],
                  (float)*(s32*)(resource + 0x10));
    brHeroSetRect(w + 0xa54, 50.0f, 0.0f, 353.0f, 42.0f);
    resource = brPersona00264ca0(w[0x58d]);
    brHeroSetRect(w + 0xa94, 216.0f, 255.0f,
                  (float)*(s32*)(resource + 0x0c), (float)*(s32*)(resource + 0x10));
    FUN_003b0d70(w[0xad4], 0x9b0, 0x670);
    thunk_FUN_003b0e54(w[0xad4], -0x33);
    resource = FUN_0021cca0(text1, 0x11);
    brHeroSetRect(w + 0xc58, 51.0f, 299.0f,
                  (float)*(s32*)(resource + 0x0c), (float)*(s32*)(resource + 0x10));
    brHeroSetRect(w + 0xc98, 51.0f + (float)*(s32*)(resource + 0x0c), 299.0f,
                  106.0f, (float)*(s32*)(resource + 0x10));
    resource = FUN_0021cca0(text1, 0x22);
    brHeroSetRect(w + 0xcd8, 305.0f, 299.0f,
                  (float)*(s32*)(resource + 0x0c), (float)*(s32*)(resource + 0x10));
}

// FUN_00263db0 NONMATCHING
void brHero00263db0(void)
{
    u32* w;
    u32 texture;
    s32 i;

    K_ASSERT(sBrHero != NULL, 0x53);
    w = sBrHero;
    if ((*w & 1) == 0)
        return;
    D_00960090(9, 2);
    D_00960090(6, 0);
    D_00960090(8, 0);
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    D_00960090(1, 0);
    for (i = 0; i < 3; i++)
    {
        D_0096009C(w + i * 0x40 + 0x184, 4, 0, 1, 2);
        D_0096009C(w + i * 0x40 + 0x184, 4, 0, 2, 3);
    }
    texture = FUN_0021cce0(FUN_0021cca0(FUN_00233d70(0), 0x16));
    D_00960090(1, texture);
    D_0096009C(w + 4, 4, 0, 1, 2);
    D_0096009C(w + 4, 4, 0, 2, 3);
    texture = FUN_0021cce0(FUN_0021cca0(FUN_00233d70(0), 0x17));
    D_00960090(1, texture);
    D_0096009C(w + 0x44, 4, 0, 1, 2);
    D_0096009C(w + 0x44, 4, 0, 2, 3);
    texture = FUN_0021cce0(FUN_0021cca0(FUN_00233d70(0), 0x18));
    D_00960090(1, texture);
    D_0096009C(w + 0x84, 4, 0, 1, 2);
    D_0096009C(w + 0x84, 4, 0, 2, 3);
    texture = FUN_0021cce0(FUN_0021cca0(FUN_00233d70(0), 0x19));
    D_00960090(1, texture);
    D_0096009C(w + 0xc4, 4, 0, 1, 2);
    D_0096009C(w + 0xc4, 4, 0, 2, 3);
    texture = FUN_0021cce0(FUN_0021cca0(FUN_00233d70(0), 0x1a));
    D_00960090(1, texture);
    D_0096009C(w + 0x104, 4, 0, 1, 2);
    D_0096009C(w + 0x104, 4, 0, 2, 3);
    texture = FUN_0021cce0(FUN_0021cca0(FUN_00233d70(0), 0x1b));
    D_00960090(1, texture);
    D_0096009C(w + 0x144, 4, 0, 1, 2);
    D_0096009C(w + 0x144, 4, 0, 2, 3);
    texture = FUN_0021cce0(FUN_0021cca0(FUN_00233d70(0), 0x1c));
    D_00960090(1, texture);
    for (i = 0; i < 3; i++)
    {
        D_0096009C(w + i * 0x40 + 0x244, 4, 0, 1, 2);
        D_0096009C(w + i * 0x40 + 0x244, 4, 0, 2, 3);
    }
    texture = FUN_0021cce0(FUN_0021cca0(FUN_00233d70(0), 0x1d));
    D_00960090(1, texture);
    for (i = 0; i < 3; i++)
    {
        D_0096009C(w + i * 0x40 + 0x304, 4, 0, 1, 2);
        D_0096009C(w + i * 0x40 + 0x304, 4, 0, 2, 3);
    }
    texture = FUN_0021cce0(FUN_0021cca0(FUN_00233d70(0), w[0x484]));
    D_00960090(1, texture);
    D_0096009C(w + 0x3c4, 4, 0, 1, 2);
    D_0096009C(w + 0x3c4, 4, 0, 2, 3);
    texture = FUN_0021cce0(FUN_0021cca0(FUN_00233d70(0), w[0x485] + 7));
    D_00960090(1, texture);
    D_0096009C(w + 0x404, 4, 0, 1, 2);
    D_0096009C(w + 0x404, 4, 0, 2, 3);
    texture = FUN_0021cce0(FUN_0021cca0(FUN_00233d70(0), w[0x486] + 0xe));
    D_00960090(1, texture);
    D_0096009C(w + 0x444, 4, 0, 1, 2);
    D_0096009C(w + 0x444, 4, 0, 2, 3);
    D_00960090(1, FUN_0021cce0(FUN_00233df0(0)));
    D_0096009C(w + 0xa54, 4, 0, 1, 2);
    D_0096009C(w + 0xa54, 4, 0, 2, 3);
    D_00960090(1, FUN_0021cce0(FUN_00233df0(1)));
    for (i = 0; i < 2; i++)
    {
        D_0096009C(w + i * 0x40 + 0x4c8, 4, 0, 1, 2);
        D_0096009C(w + i * 0x40 + 0x4c8, 4, 0, 2, 3);
    }
    D_00960090(1, FUN_0021cce0(FUN_0021cca0(FUN_00233d70(1), 0)));
    D_0096009C(w + 0x548, 4, 0, 1, 2);
    D_0096009C(w + 0x548, 4, 0, 2, 3);
    D_00960090(1, FUN_00239140(2));
    for (i = 0; i < 2; i++)
    {
        D_0096009C(w + i * 0x40 + 0x594, 4, 0, 1, 2);
        D_0096009C(w + i * 0x40 + 0x594, 4, 0, 2, 3);
    }
    D_00960090(1, FUN_00239140(2));
    for (i = 0; i < 3; i++)
    {
        D_0096009C(w + i * 0x40 + 0x614, 4, 0, 1, 2);
        D_0096009C(w + i * 0x40 + 0x614, 4, 0, 2, 3);
    }
    D_00960090(1, FUN_00239140(2));
    for (i = 0; i < 3; i++)
    {
        D_0096009C(w + i * 0x40 + 0x6d4, 4, 0, 1, 2);
        D_0096009C(w + i * 0x40 + 0x6d4, 4, 0, 2, 3);
    }
    D_00960090(1, FUN_0021cce0(FUN_0021cca0(FUN_00233d70(1), 4)));
    D_0096009C(w + 0x794, 4, 0, 1, 2);
    D_0096009C(w + 0x794, 4, 0, 2, 3);
    D_00960090(1, FUN_00239140(2));
    for (i = 0; i < 3; i++)
    {
        D_0096009C(w + i * 0x40 + 0x7d4, 4, 0, 1, 2);
        D_0096009C(w + i * 0x40 + 0x7d4, 4, 0, 2, 3);
    }
    D_00960090(1, FUN_00239140(2));
    for (i = 0; i < 3; i++)
    {
        D_0096009C(w + i * 0x40 + 0x894, 4, 0, 1, 2);
        D_0096009C(w + i * 0x40 + 0x894, 4, 0, 2, 3);
    }
    D_00960090(1, FUN_0021cce0(FUN_0021cca0(FUN_00233d70(1), 5)));
    D_0096009C(w + 0x954, 4, 0, 1, 2);
    D_0096009C(w + 0x954, 4, 0, 2, 3);
    D_00960090(1, FUN_0021cce0(brPersona00264ca0(w[0x58d])));
    D_0096009C(w + 0xa94, 4, 0, 1, 2);
    D_0096009C(w + 0xa94, 4, 0, 2, 3);
    FUN_003b1360(w[0xad4], 1, 0);
    D_00960090(1, FUN_0021cce0(FUN_0021cca0(FUN_00233d70(1), 0x11)));
    D_0096009C(w + 0xc58, 4, 0, 1, 2);
    D_0096009C(w + 0xc58, 4, 0, 2, 3);
    D_0096009C(w + 0xc98, 4, 0, 1, 2);
    D_0096009C(w + 0xc98, 4, 0, 2, 3);
    D_00960090(1, FUN_0021cce0(FUN_0021cca0(FUN_00233d70(1), 0x22)));
    D_0096009C(w + 0xcd8, 4, 0, 1, 2);
    D_0096009C(w + 0xcd8, 4, 0, 2, 3);
    D_00960090(1, FUN_00239140(2));
    for (i = 0; i < 5; i++)
    {
        D_0096009C(w + i * 0x40 + 0xd18, 4, 0, 1, 2);
        D_0096009C(w + i * 0x40 + 0xd18, 4, 0, 2, 3);
    }
}
