#include "Main/Social/sfl_res.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

/* The Ground task owns this 0x8780-byte Social work area. */
static u32* sSflGround; // puGpffffb624 / DAT_007ce314
/* 0x0023D7A0 onward is Panel: it switches to DAT_007CE318 and sfl_panel.c asserts. */

typedef struct SflGroundVec2
{
    f32 x;
    f32 y;
} SflGroundVec2;

typedef struct SflGroundColor
{
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} SflGroundColor;
typedef struct SflGroundViewport
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 width;
    s32 height;
} SflGroundViewport;
typedef struct SflGroundTile
{
    u8 pad0[8];
    f32 color;
    u8 pad0c[12];
    f32 scale;
    u32 white0;
    u32 white1;
    u32 white2;
    u32 white3;
} SflGroundTile;

typedef void (*SflGroundTickCallback)(void* owner);
typedef void (*SflGroundRenderStateCallback)(u32 selector, u32 value);
typedef void (*SflGroundRenderQuadCallback)(void* vertices, u32 count,
                                             u32 group, u32 pass, u32 blend);

#define GROUND_TILE(work, offset) ((SflGroundTile*)GROUND_PTR((work), (offset)))
#define GROUND_PTR(work, offset) ((void*)((u8*)(work) + (offset)))
#define GROUND_U32(work, offset) (*(u32*)GROUND_PTR((work), (offset)))
#define GROUND_F32(work, offset) (*(f32*)GROUND_PTR((work), (offset)))

enum
{
    SFL_GROUND_WORK_SIZE = 0x8780,
    SFL_GROUND_PANEL_OFFSET = 0x110,
    SFL_GROUND_PANEL_STRIDE = 0x200,
    SFL_GROUND_PARTICLE_OFFSET = 0xD10,
    SFL_GROUND_PARTICLE_STRIDE = 0x130,
    SFL_GROUND_TILE_OFFSET = 0x6B00,
    SFL_GROUND_TILE_STRIDE = 0x40
};

extern const f32 D_00960088;
extern const u32 D_00960090[];
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
#pragma alias D_0096009C_abs D_0096009C
extern u8 D_0096009C_abs[];
extern const u32 D_0096009C[];
extern const SflGroundVec2 D_0068E7C0[];
extern f32 gPI;
extern void (*D_009600A4)(u32, void*, u32, void*, u32);
extern f32 sqrtf(f32 value);

void FUN_00249690();
void* H_Maestro_001120a0(s32 font);
void func_00249680(void* work);

// FUN_00239140
void* func_00239140(s32 font)
{
    return *(void**)((u8*)H_Maestro_001120a0(font) + 0x104);
}

// FUN_00239170
void func_00239170(u32* work)
{
    u16* table;
    u8* slot;
    s32 col;
    s32 row;
    s32 tableIndex;
    s32 glyph;

    K_ASSERT(sSflGround == NULL, 0x90);
    work[0] = 0;
    work[3] = 0;
    tableIndex = 0;
    glyph = 0;
    row = 0;
    table = (u16*)((u8*)work + 0x83c0);
    for (; row < 8; row++) {
        for (col = 0; col < 10; col++) {
            table[tableIndex] = (u16)glyph;
            slot = (u8*)work + tableIndex * 2;
            *(u16*)(slot + 0x83c2) = (u16)(glyph + 1);
            *(u16*)(slot + 0x83c4) = (u16)(glyph + 0xb);
            *(u16*)(slot + 0x83c6) = (u16)(glyph + 1);
            *(u16*)(slot + 0x83c8) = (u16)(glyph + 0xc);
            *(u16*)(slot + 0x83ca) = (u16)(glyph + 0xb);
            tableIndex += 6;
            glyph++;
        }
        glyph++;
    }
    func_00249680((u8*)work + 0x8780);
    sSflGround = work;
}

void FUN_0023d2a0();
void FUN_0023d650();
void func_002496e0();
void func_00249c10();
void func_0024a180();
void func_0024a230();
void* kwlnGetMainCamera();
void func_0021d890(void* destination, const void* layout);
void func_0021d8e0(void* destination, const void* rect);
void func_0021d950(void* destination, const void* color);
void func_0021e170(void* destination, const void* center,
                   const void* direction, const void* size);
void func_0021eb80(void* destination, const f32* layout);
f32 func_0052ea18(f32 y, f32 x);
f32 func_00269c80(f32 value);
f32 func_00269ca0(f32 value);
f32 sqrtf(f32 value);
u32 RpRandom();
u32 func_00488f30(void);
f32 func_0052e878(f32 angle);
f32 func_0052e6d8(f32 angle);
f32 cosf(f32 angle);
void func_002392d0();
void func_0023b990();
void func_0023c280();
void func_0023c3a0();
void func_0023c520();
void func_0023c850();

static void sflGroundCallState(u32 selector, u32 value);
static void sflGroundCallStateTable(const u32* table, u32 selector, u32 value);
// FUN_0024A180
void func_0024a180(u32* work)
{
    u32* owner;

    if ((~GROUND_U32(work, 0x604) & 1) != 0) {
        return;
    }

    {
        register const u32* const state = &D_00960090[0];

        ((SflGroundRenderStateCallback)(void*)state[0])(9, 2);
        ((SflGroundRenderStateCallback)(void*)state[0])(0x14, 2);
        ((SflGroundRenderStateCallback)(void*)state[0])(6, 0);
        ((SflGroundRenderStateCallback)(void*)state[0])(8, 0);
        owner = *(u32**)GROUND_PTR(work, 0x600);
        ((SflGroundTickCallback)(void*)GROUND_U32(owner, 0x48))(owner);
    }
}
// FUN_0024A230
void func_0024a230(void* work, const volatile SflGroundColor* color)
{
    u8 r;
    u8 g;
    u8 b;
    u8 a;

    r = color->r;
    g = color->g;
    b = color->b;
    a = color->a;
    ((u8*)work)[0x614] = r;
    ((u8*)work)[0x615] = g;
    ((u8*)work)[0x616] = b;
    ((u8*)work)[0x617] = a;
}
void func_0023c8c0();
void func_0023ca10();
void func_0023cda0();
void func_0023d130();
void func_0023d2a0();
void func_0023d650();

static f32 sflGroundClamp01(f32 value)
{
    if (value < 0.0f) {
        return 0.0f;
    }
    if (value > 1.0f) {
        return 1.0f;
    }
    return value;
}

static u8 sflGroundAlpha(f32 value)
{
    value *= 255.0f;
    if (value >= 255.0f) {
        return 0xff;
    }
    if (value <= 0.0f) {
        return 0;
    }
    return (u8)value;
}

static f32 sflGroundRandomUnit(void)
{
    return (f32)(RpRandom() & 0xfff) / 4095.0f;
}

static void sflGroundCallState(u32 selector, u32 value)
{
    ((SflGroundRenderStateCallback)(void*)D_00960090[0])(selector, value);
}
static void sflGroundCallStateTable(const u32* table, u32 selector, u32 value)
{
    ((SflGroundRenderStateCallback)(void*)table[0])(selector, value);
}

static void sflGroundDraw(void* vertices, u32 pass, u32 blend)
{
    ((SflGroundRenderQuadCallback)(void*)D_0096009C)(vertices, 4, 0, pass, blend);
}

static void sflGroundSetSkyState(u32 textureState)
{
    RpSkyRenderStateSet(3, textureState);
    RpSkyRenderStateSet(2, textureState == 0x71801 ? 0x48 : 0x44);
}

static void sflGroundInitParticle(u32* particle)
{
    u32 lifetime;

    particle[0] |= 1;
    particle[0x44] = 0;
    lifetime = 0x78 + RpRandom() % 0x3c;
    particle[0x45] = lifetime;
    particle[1] = RpRandom() % 3;
    GROUND_F32(particle, 0x118) = 640.0f * sflGroundRandomUnit();
    GROUND_F32(particle, 0x11c) = 448.0f * sflGroundRandomUnit();
    GROUND_F32(particle, 0x120) = 640.0f * sflGroundRandomUnit();
    GROUND_F32(particle, 0x124) = 448.0f * sflGroundRandomUnit();
}

static void sflGroundInitFxLayout(u32 flag, s32 state)
{
    u32* work;
    SflGroundViewport* viewport;
    f32 cameraScale;
    f32 rect[4];
    s32 i;
    s32 j;

    K_ASSERT(sSflGround != NULL, 0x87);
    work = sSflGround;
    cameraScale = 1.0f / GROUND_F32(kwlnGetMainCamera(), 0x80);

    viewport = sflRes0020e690(5);
    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = 1.0f;
    rect[3] = 1.0f;
    func_0021eb80(GROUND_PTR(work, 0x4710), rect);

    viewport = sflRes0020e690(4);
    rect[0] = 1.0f / (f32)viewport->width;
    rect[1] = 0.0f;
    rect[2] = 51.0f / (f32)viewport->width;
    rect[3] = 128.0f / (f32)viewport->height;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 4; j++) {
            func_0021eb80(GROUND_PTR(work, 0x4810 + i * 0x420 + j * 0x100), rect);
        }
        GROUND_F32(work, 0x4c20 + i * 0x420) = sflGroundRandomUnit();
        GROUND_U32(work, 0x4c24 + i * 0x420) = 0;
        GROUND_U32(work, 0x4c28 + i * 0x420) = RpRandom();
    }

    viewport = sflRes0020e690(3);
    rect[0] = 1.0f / (f32)viewport->width;
    rect[1] = 0.0f;
    rect[2] = (flag == 0x20 ? 511.0f : 503.0f) / (f32)viewport->width;
    rect[3] = 44.0f / (f32)viewport->height;
    for (i = 0; i < 6; i++) {
        func_0021eb80(GROUND_PTR(work, 0x64f0 + i * 0x100), rect);
        GROUND_F32(work, 0x64f8 + i * 0x100) = D_00960088;
        GROUND_F32(work, 0x6508 + i * 0x100) = cameraScale;
    }

    work[1] = 0;
    work[0x1abc] = 0x78;
    work[0] |= 8;
    work[0] |= 0x10;
    work[0] |= flag;
    work[3] = state;
}

static void sflGroundUpdateParticles(u32* work, f32 intensity)
{
    u32* particle;
    SflGroundVec2 center;
    SflGroundVec2 direction;
    SflGroundVec2 scale;
    SflGroundColor color;
    s32 i;
    s32 j;

    color.r = 0xff;
    color.g = 0xff;
    color.b = 0xff;
    color.a = sflGroundAlpha(intensity);
    direction.x = 1.0f;
    direction.y = 0.0f;
    for (i = 0; i < 48; i++) {
        particle = (u32*)GROUND_PTR(work, SFL_GROUND_PARTICLE_OFFSET + i * SFL_GROUND_PARTICLE_STRIDE);
        if ((particle[0] & 1) == 0) {
            continue;
        }
        particle[0x44]++;
        if (particle[0x44] > particle[0x45]) {
            particle[0] &= ~1;
            continue;
        }
        center.x = GROUND_F32(particle, 0x118) + GROUND_F32(particle, 0x120) * intensity;
        center.y = GROUND_F32(particle, 0x11c) + GROUND_F32(particle, 0x124) * intensity;
        scale.x = 124.0f * intensity;
        scale.y = 162.0f * intensity;
        for (j = 0; j < 4; j++) {
            func_0021e170(GROUND_PTR(particle, 0x10 + j * 0x100), &center, &direction, &scale);
        }
        func_0021d950(GROUND_PTR(particle, 0x10), &color);
    }
}

// FUN_00239280
void sflGround00239280(void)
{
    K_ASSERT(sSflGround != NULL, 0x87);
    FUN_00249690(sSflGround + 0x21e0);
    sSflGround = NULL;
}

// FUN_002392D0 NONMATCHING
void func_002392d0(void)
{
    u32* work;
    u8* particle;
    u8* tile;
    SflGroundVec2 center;
    SflGroundVec2 direction;
    SflGroundVec2 scale;
    SflGroundColor color;
    f32 rect[4];
    f32 fade;
    f32 particleFade;
    f32 panelFade;
    f32 panelScale;
    f32 panelPhase;
    f32 frameAngle;
    f32 frameFraction;
    f32 trig1;
    f32 trig2;
    f32 trig3;
    f32 motion;
    f32 x;
    f32 y;
    f32 distance;
    f32 angle;
    f32 wave;
    f32 wave2;
    f32 alpha;
    s32 i;
    s32 j;
    s32 row;
    s32 column;
    f32 normProgress;
    f32 normFade;
    f32 invNormFade;
    f32 work2F;
    s32 active;
    f32 sixHundred;
    f32 sinAngle;
    f32 cosAngle;
    f32 angleArg;
    s32 found;
    K_ASSERT(sSflGround != NULL, 0x87);
    work = sSflGround;
    (void)kwlnGetMainCamera();

    /*
     * The first switch is deliberately written as four separate arms.  The
     * retail task does not increment the animation clock for states 1/2;
     * those states only consume their one-shot flag.
     */
    switch (work[3]) {
    case 1:
        if ((work[0] & 1) != 0) {
            if ((s32)work[1] < 20)
                work[1]++;
            else
                work[0] &= ~1;
        }
        break;
    case 2:
        if ((work[0] & 4) != 0) {
            if ((s32)work[1] < 30)
                work[1]++;
            else
                work[0] &= ~4;
        }
        break;
    case 3:
        if ((work[0] & 2) != 0) {
            if ((s32)work[1] < 30)
                work[1]++;
            else
                work[0] &= ~2;
        }
        work[0x1abc] = work[0x1abc] + 1;
        if (work[0x1abc] >= 80)
            work[0] &= ~9;
        if (work[0x1abc] >= 160)
            work[0] &= ~0x11;
        work[0x1abc] %= 240;
        break;
    case 4:
        if ((work[0] & 0x20) != 0) {
            if ((s32)work[1] < 30)
                work[1]++;
            else
                work[0] &= ~0x20;
        }
        work[0x1abc] = work[0x1abc] + 1;
        if (work[0x1abc] >= 80)
            work[0] &= ~9;
        if (work[0x1abc] >= 160)
            work[0] &= ~0x11;
        work[0x1abc] %= 240;
        break;
    default:
        break;
    }
    work[2] = (work[2] + 1) % 180;
    normProgress = (f32)work[1] / 30.0f;
    work2F = (f32)work[2];
    normFade = normProgress;
    if (normFade < 0.0f)
        normFade = 0.0f;
    else if (normFade > 1.0f)
        normFade = 1.0f;
    invNormFade = 1.0f - normFade;
    switch (work[3]) {
    case 1:
        fade = (f32)(work[1] % 40) / 40.0f;
        break;
    case 2:
        fade = 0.0f;
        break;
    case 3:
    case 4:
        fade = invNormFade;
        break;
    case 5:
        fade = 1.0f;
        break;
    default:
        fade = 0.0f;
        break;
    }

    color.r = 0xff;
    color.g = 0xff;
    color.b = 0xff;
    color.a = 0xff;

    /*
     * The full-screen tile.  The source uses the normalized progress for
     * the alpha of this tile, while the remaining tiles use the state
     * dependent value below.
     */
    panelFade = 0.0f;
    if (work[3] == 1) {
        if ((work[0] & 1) != 0) {
            if ((s32)work[1] < 10)
                panelFade = 0.0f;
            else
                panelFade = (f32)((s32)work[1] - 10) / 10.0f;
        } else {
            panelFade = 1.0f;
        }
    } else if (work[3] == 2 || work[3] == 3 || work[3] == 4) {
        panelFade = 1.0f;
    }
    if (work[3] >= 1 && work[3] <= 4) {
        rect[0] = 0.0f;
        rect[1] = 0.0f;
        rect[2] = 640.0f;
        rect[3] = 448.0f;
        func_0021d8e0(GROUND_PTR(work, 0x10), rect);
    { f32 _sgav = panelFade * 255.0f; if (_sgav >= 255.0f) color.a = 0xff; else if (_sgav <= 0.0f) color.a = 0; else color.a = (u8)_sgav; }
        func_0021d950(GROUND_PTR(work, 0x10), &color);
    }

    /*
     * The 9x11 curtain grid is animated in the ground task itself.  Keep the
     * radial calculation here (rather than replacing it with a helper): the
     * original has one independent wave calculation per tile.
     */
    frameFraction = work2F / 180.0f;
    frameAngle = (4.0f * gPI) * frameFraction;
    panelScale = 204.0f * panelFade;
    for (row = 0; row < 9; row++) {
        for (column = 0; column < 11; column++) {
            tile = (u8*)work + SFL_GROUND_TILE_OFFSET +
                   (row * 11 + column) * SFL_GROUND_TILE_STRIDE;
            x = (f32)column * 64.0f;
            y = (f32)row * 56.0f - 224.0f;
            GROUND_F32(tile, 0) = x;
            GROUND_F32(tile, 4) = y;
            GROUND_F32(tile, 0x20) = 255.0f;
            GROUND_F32(tile, 0x24) = 255.0f;
            GROUND_F32(tile, 0x28) = 255.0f;
            alpha = panelScale;
            if (alpha < 0.0f)
                alpha = 0.0f;
            wave = alpha * 255.0f;
    { f32 _sgav = wave * 255.0f; u8 _sgar; if (_sgav >= 255.0f) _sgar = 0xff; else if (_sgav <= 0.0f) _sgar = 0; else _sgar = (u8)_sgav; GROUND_F32(tile, 0x2c) = (f32)_sgar; }

            distance = sqrtf((x - 320.0f) * (x - 320.0f) + y * y);
            angle = func_0052ea18(y, x - 320.0f);
            /*
             * These are the four calls seen in every retail tile body:
             * three sine terms for the travelling wave and one cosine term
             * for the orthogonal scale.
             */
            wave = func_00269c80(1.95f * (distance / 780.0f) * 2.0f -
                                 frameAngle * 1.9f);
            wave2 = func_00269c80(angle - frameAngle);
            wave = distance + wave * (distance * 0.08f);
            wave2 = func_00269c80(angle) * wave2;
            GROUND_F32(tile, 0x10) =
                (wave2 + 320.0f) / 640.0f;
            GROUND_F32(tile, 0x14) =
                (func_00269ca0(angle) * wave + 224.0f) / 448.0f;
        }
    }

    /*
     * State 1 has six independently animated title panels.  Retail lays
     * these out in this non-address order (the first two are the top pair).
     */
    if (work[3] == 1 && (work[0] & 1) != 0) {
        if ((s32)work[1] < 4)
            panelPhase = (f32)work[1] / 4.0f;
        else if ((s32)work[1] < 10)
            panelPhase = 1.0f;
        else
            panelPhase = 1.0f - (f32)((s32)work[1] - 10) / 10.0f;
        panelScale = 1.0f;
    { f32 _sgav = panelFade * panelPhase * 255.0f; if (_sgav >= 255.0f) color.a = 0xff; else if (_sgav <= 0.0f) color.a = 0; else color.a = (u8)_sgav; }
        sinAngle = func_0052e6d8(angleArg);
        cosAngle = func_0052e878(angleArg);
        direction.x = sinAngle;
        direction.y = cosAngle;
        center.x = 320.0f;
        center.y = 224.0f;
        scale.x = panelScale;
        scale.y = panelScale;
        func_0023c520(GROUND_PTR(work, 0x910), &center, &direction, &scale);
        func_0023c850(GROUND_PTR(work, 0x910), &color);

        sinAngle = func_0052e6d8(angleArg);
        cosAngle = func_0052e878(angleArg);
        direction.x = sinAngle;
        direction.y = cosAngle;
        trig1 = func_0052e6d8(angleArg);
        trig2 = func_0052e6d8(angleArg);
        trig3 = func_0052e6d8(angleArg);
        motion = sixHundred * (panelPhase * (trig2 + trig3) - trig1);
        center.x = 320.0f + motion;
        trig1 = func_0052e878(angleArg);
        trig2 = func_0052e878(angleArg);
        trig3 = func_0052e878(angleArg);
        motion = sixHundred * (panelPhase * (trig2 + trig3) - trig1);
        center.y = 30.0f + motion;
        scale.x = panelScale;
        scale.y = panelScale;
        func_0023c520(GROUND_PTR(work, 0xb10), &center, &direction, &scale);
        func_0023c850(GROUND_PTR(work, 0xb10), &color);

        sinAngle = func_0052e6d8(angleArg);
        cosAngle = func_0052e878(angleArg);
        direction.x = sinAngle;
        direction.y = cosAngle;
        trig1 = func_0052e6d8(angleArg);
        trig2 = func_0052e6d8(angleArg);
        trig3 = func_0052e6d8(angleArg);
        motion = sixHundred * (trig1 - panelPhase * (trig2 + trig3));
        center.x = 320.0f + motion;
        trig1 = func_0052e878(angleArg);
        trig2 = func_0052e878(angleArg);
        trig3 = func_0052e878(angleArg);
        motion = sixHundred * (trig1 - panelPhase * (trig2 + trig3));
        center.y = 418.0f + motion;
        scale.x = panelScale;
        scale.y = panelScale;
        func_0023c520(GROUND_PTR(work, 0x110), &center, &direction, &scale);
        func_0023c850(GROUND_PTR(work, 0x110), &color);

        sinAngle = func_0052e6d8(angleArg);
        cosAngle = func_0052e878(angleArg);
        direction.x = sinAngle;
        direction.y = cosAngle;
        trig1 = func_0052e6d8(angleArg);
        trig2 = func_0052e6d8(angleArg);
        trig3 = func_0052e6d8(angleArg);
        motion = sixHundred * (trig1 - panelPhase * (trig2 + trig3));
        center.x = 320.0f + motion;
        trig1 = func_0052e878(angleArg);
        trig2 = func_0052e878(angleArg);
        trig3 = func_0052e878(angleArg);
        motion = sixHundred * (trig1 - panelPhase * (trig2 + trig3));
        center.y = 418.0f + motion;
        scale.x = panelScale;
        scale.y = panelScale;
        func_0023c520(GROUND_PTR(work, 0x310), &center, &direction, &scale);
        func_0023c850(GROUND_PTR(work, 0x310), &color);

        sinAngle = func_0052e6d8(angleArg);
        cosAngle = func_0052e878(angleArg);
        direction.x = sinAngle;
        direction.y = cosAngle;
        trig1 = func_0052e6d8(angleArg);
        trig2 = func_0052e6d8(angleArg);
        trig3 = func_0052e6d8(angleArg);
        motion = sixHundred * (trig1 - panelPhase * (trig2 + trig3));
        center.x = 320.0f + motion;
        trig1 = func_0052e878(angleArg);
        trig2 = func_0052e878(angleArg);
        trig3 = func_0052e878(angleArg);
        motion = sixHundred * (trig1 - panelPhase * (trig2 + trig3));
        center.y = 418.0f + motion;
        scale.x = panelScale;
        scale.y = panelScale;
        func_0023c520(GROUND_PTR(work, 0x510), &center, &direction, &scale);
        func_0023c850(GROUND_PTR(work, 0x510), &color);

        sinAngle = func_0052e6d8(angleArg);
        cosAngle = func_0052e878(angleArg);
        direction.x = sinAngle;
        direction.y = cosAngle;
        center.x = 320.0f;
        center.y = 418.0f;
        scale.x = panelScale;
        scale.y = panelScale;
        func_0023c520(GROUND_PTR(work, 0x710), &center, &direction, &scale);
        func_0023c850(GROUND_PTR(work, 0x710), &color);
    }
    /*
     * States 3/4 draw seven four-quad effects.  Their particle pool is
     * topped up before the update pass, so a partially initialized scene is
     * still rendered deterministically.
     */
    if (work[3] == 3 || work[3] == 4) {
        panelFade = invNormFade;
    }
    /*
     * Particle opacity is a separate state transition from the curtain
     * opacity.  State 1 follows the full-screen fade, while states 2-4
     * fade out over the 30-frame transition; state 5 is fully opaque.
     */
    switch (work[3]) {
    case 1:
        particleFade = panelFade;
        break;
    case 2:
    case 3:
    case 4:
        particleFade = invNormFade;
        break;
    case 5:
        particleFade = 1.0f;
        break;
    default:
        particleFade = 0.0f;
        break;
    }
    { f32 _sgav = fade * 255.0f; if (_sgav >= 255.0f) color.a = 0xff; else if (_sgav <= 0.0f) color.a = 0; else color.a = (u8)_sgav; }
    active = 0;
    for (i = 0; i < 48; i++) {
        particle = (u8*)work + SFL_GROUND_PARTICLE_OFFSET +
                   i * SFL_GROUND_PARTICLE_STRIDE;
        if ((GROUND_U32(particle, 0) & 1) != 0)
            active++;
    }
    for (i = 0; i < 48 - active; i++) {
        u32 randomValue;
        f32 randomUnit;

        for (j = 0; j < 48; j++) {
            particle = (u8*)work + SFL_GROUND_PARTICLE_OFFSET +
                       j * SFL_GROUND_PARTICLE_STRIDE;
            if ((GROUND_U32(particle, 0) & 1) == 0) {
                found = 1;
                break;
            }
        }
        K_ASSERT(found != 0, 0x2e4);

        GROUND_U32(particle, 0) |= 1;
        GROUND_U32(particle, 0x110) = 0;
        randomValue = func_00488f30();
        GROUND_U32(particle, 0x114) = randomValue % 0x3c + 0x78;
        randomValue = func_00488f30();
        GROUND_U32(particle, 4) = randomValue % 3;

        randomValue = func_00488f30() & 0xfff;
        randomUnit = (f32)randomValue / 4095.0f;
        GROUND_F32(particle, 0x118) = 640.0f * randomUnit;
        randomValue = func_00488f30() & 0xfff;
        randomUnit = (f32)randomValue / 4095.0f;
        GROUND_F32(particle, 0x11c) = 448.0f * randomUnit;
        randomValue = func_00488f30() & 0xfff;
        randomUnit = (f32)randomValue / 4095.0f;
        GROUND_F32(particle, 0x120) = 640.0f * randomUnit;
        randomValue = func_00488f30() & 0xfff;
        randomUnit = (f32)randomValue / 4095.0f;
        GROUND_F32(particle, 0x124) = 448.0f * randomUnit;
        found = 0;
    }

    for (i = 0; i < 48; i++) {
        f32 progress;
        f32 width;
        f32 height;
        f32 deltaX;
        f32 deltaY;

        particle = (u8*)work + SFL_GROUND_PARTICLE_OFFSET +
                   i * SFL_GROUND_PARTICLE_STRIDE;
        if ((GROUND_U32(particle, 0) & 1) == 0)
            continue;
        GROUND_U32(particle, 0x110)++;
        if (GROUND_U32(particle, 0x110) > GROUND_U32(particle, 0x114)) {
            GROUND_U32(particle, 0) &= ~1;
            continue;
        }
        if (GROUND_U32(particle, 4) == 0) {
            width = 1.3f;
            height = 0.2f;
        } else if (GROUND_U32(particle, 4) == 1) {
            width = 1.8f;
            height = 0.2f;
        } else {
            width = 1.2f;
            height = 0.13333334f;
        }
        progress = (f32)GROUND_U32(particle, 0x110) /
                   (f32)GROUND_U32(particle, 0x114);
        if (progress < 0.2f)
            progress /= 0.2f;
        else if (progress >= 0.8f)
            progress = 1.0f - (progress - 0.8f) / 0.2f;
        scale.x = 63.0f * width;
        scale.y = 81.0f * width;
        deltaX = GROUND_F32(particle, 0x120) -
                 GROUND_F32(particle, 0x118);
        deltaY = GROUND_F32(particle, 0x124) -
                 GROUND_F32(particle, 0x11c);
        center.x = GROUND_F32(particle, 0x118) + deltaX * progress;
        center.y = GROUND_F32(particle, 0x11c) + deltaY * progress;
        direction.x = deltaX;
        direction.y = deltaY;
        func_0021e170(particle + 0x10, &center, &direction, &scale);
    { f32 _sgav = particleFade * height * progress * 255.0f; if (_sgav >= 255.0f) color.a = 0xff; else if (_sgav <= 0.0f) color.a = 0; else color.a = (u8)_sgav; }
        func_0021d950(particle + 0x10, &color);
    }

    if (work[3] == 3 || work[3] == 4) {
        f32 ribbonPhase;

        panelScale = invNormFade;
        for (i = 0; i < 7; i++) {
            tile = (u8*)work + 0x4810 + i * 0x420;
            ribbonPhase = GROUND_F32(tile, 0x410) + 0.033333335f;
            if (ribbonPhase > 1.0f)
                ribbonPhase -= 1.0f;
            GROUND_F32(tile, 0x410) = ribbonPhase;
            GROUND_U32(tile, 0x414) =
                (GROUND_U32(tile, 0x414) + 1) & 0xfff;
            scale.x = 76.5f;
            scale.y = 192.0f;
            direction.x = func_0052e878(angleArg + 0.17453294f);
            direction.y = 0.43f;
            for (j = 0; j < 4; j++) {
                center.x = ((f32)i + 0.5f) * (224.0f / 7.0f);
                center.y = 224.0f *
                           (ribbonPhase + (f32)j / 4.0f);
                if ((i & 1) != 0)
                    center.y = 224.0f * (1.0f - ribbonPhase -
                                         (f32)j / 4.0f);
                center.y -= 96.0f;
                func_0021e170(tile + 0x10 + j * 0x100, &center,
                              &direction, &scale);
    { f32 _sgav = panelScale * 0.43f * 255.0f; if (_sgav >= 255.0f) color.a = 0xff; else if (_sgav <= 0.0f) color.a = 0; else color.a = (u8)_sgav; }
                func_0021d950(tile + 0x10 + j * 0x100, &color);
            }
        }
    }
    if (work[3] == 2 || work[3] == 3 || work[3] == 4) {
        panelScale = normFade;
        rect[0] = 0.0f;
        rect[1] = 220.0f;
        rect[2] = 640.0f;
        rect[3] = 238.0f;
        func_0021d8e0(GROUND_PTR(work, 0x4610), rect);
    { f32 _sgav = panelScale * 0.2f * 255.0f; if (_sgav >= 255.0f) color.a = 0xff; else if (_sgav <= 0.0f) color.a = 0; else color.a = (u8)_sgav; }
        func_0021d950(GROUND_PTR(work, 0x4610), &color);
    }
    if (work[3] == 3 || work[3] == 4) {
        panelScale = normFade;
        panelPhase = 1.0f - panelScale;
        rect[0] = 0.0f;
        rect[1] = 206.0f + panelPhase * 40.0f;
        rect[2] = 640.0f;
        rect[3] = 223.0f;
        func_0021d8e0(GROUND_PTR(work, 0x4710), rect);
    { f32 _sgav = panelScale * 0.4f * 255.0f; if (_sgav >= 255.0f) color.a = 0xff; else if (_sgav <= 0.0f) color.a = 0; else color.a = (u8)_sgav; }
        func_0021d950(GROUND_PTR(work, 0x4710), &color);
    }

    /*
     * The six narrow strips are the final transition layer.  Three texture
     * phases are used, repeated for the two halves of the strip array.
     */
    if (work[3] == 3 || work[3] == 4) {
        panelPhase = (f32)(work[0x1abc] % 240) / 240.0f;
        rect[0] = (1.0f - panelPhase) * 1659.0f - 503.0f;
        rect[1] = 0.0f;
        rect[2] = 503.0f;
        rect[3] = 44.0f;
    { f32 _sgav = fade * 255.0f; if (_sgav >= 255.0f) color.a = 0xff; else if (_sgav <= 0.0f) color.a = 0; else color.a = (u8)_sgav; }
        func_0021d8e0(GROUND_PTR(work, 0x64f0), rect);
        func_0021d950(GROUND_PTR(work, 0x64f0), &color);

        panelPhase = (f32)((work[0x1abc] + 160) % 240) / 240.0f;
        rect[0] = (1.0f - panelPhase) * 1659.0f - 503.0f;
        func_0021d8e0(GROUND_PTR(work, 0x65f0), rect);
        func_0021d950(GROUND_PTR(work, 0x65f0), &color);

        panelPhase = (f32)((work[0x1abc] + 80) % 240) / 240.0f;
        rect[0] = (1.0f - panelPhase) * 1659.0f - 503.0f;
        func_0021d8e0(GROUND_PTR(work, 0x66f0), rect);
        func_0021d950(GROUND_PTR(work, 0x66f0), &color);
        rect[1] = 404.0f;

        panelPhase = (f32)((work[0x1abc] + 160) % 240) / 240.0f;
        rect[0] = (1.0f - panelPhase) * 1659.0f - 503.0f;
        func_0021d8e0(GROUND_PTR(work, 0x67f0), rect);
        func_0021d950(GROUND_PTR(work, 0x67f0), &color);

        panelPhase = (f32)((work[0x1abc] + 80) % 240) / 240.0f;
        rect[0] = (1.0f - panelPhase) * 1659.0f - 503.0f;
        func_0021d8e0(GROUND_PTR(work, 0x68f0), rect);
        func_0021d950(GROUND_PTR(work, 0x68f0), &color);

        panelPhase = (f32)((work[0x1abc] + 80) % 240) / 240.0f;
        rect[0] = (1.0f - panelPhase) * 1659.0f - 503.0f;
        func_0021d8e0(GROUND_PTR(work, 0x69f0), rect);
        func_0021d950(GROUND_PTR(work, 0x69f0), &color);
    }

    { f32 _sgav = (128.0f / 255.0f) * panelFade * 255.0f; if (_sgav >= 255.0f) color.a = 0xff; else if (_sgav <= 0.0f) color.a = 0; else color.a = (u8)_sgav; }
    func_0024a230(GROUND_PTR(work, SFL_GROUND_WORK_SIZE), &color);
    func_00249c10(GROUND_PTR(work, SFL_GROUND_WORK_SIZE));
}

// FUN_0023B990 NONMATCHING
void func_0023b990(void)
{
    u32* work;
    s32 state;
    s32 i;
    s32 j;
    register const volatile u32* stateTable;
    register const volatile u32* drawTable;

    K_ASSERT(sSflGround != NULL, 0x87);
    work = sSflGround;
    stateTable = (const u32*)D_00960090_abs;
    
    ((SflGroundRenderStateCallback)(void*)stateTable[0])(9, 2);
    ((SflGroundRenderStateCallback)(void*)stateTable[0])(0x14, 2);
    ((SflGroundRenderStateCallback)(void*)stateTable[0])(8, 0);
    ((SflGroundRenderStateCallback)(void*)stateTable[0])(6, 0);

    state = work[3];
    if (state >= 1 && state <= 5) {
        RpSkyRenderStateSet(3, 0x717fb);
        RpSkyRenderStateSet(2, 0x44);
        ((SflGroundRenderStateCallback)(void*)stateTable[0])(
            1, (u32)sflRes0020e590(0));
        drawTable = (const u32*)D_0096009C_abs;
        
        for (i = 0; i < 6; i++) {
            void* vertices = GROUND_PTR(work, 0x110 + i * 0x200);
            ((SflGroundRenderQuadCallback)(void*)drawTable[0])(vertices, 4, 0, 1, 2);
            ((SflGroundRenderQuadCallback)(void*)drawTable[0])(vertices, 4, 0, 2, 3);
        }
    }

    if (state == 1) {
        ((SflGroundRenderStateCallback)(void*)stateTable[0])(9, 2);
        ((SflGroundRenderStateCallback)(void*)stateTable[0])(9, 3);
        ((SflGroundRenderStateCallback)(void*)stateTable[0])(9, 4);
        ((SflGroundRenderStateCallback)(void*)stateTable[0])(9, 6);
        ((SflGroundRenderStateCallback)(void*)stateTable[0])(9, 1);
        ((SflGroundRenderStateCallback)(void*)stateTable[0])(9, 5);
        for (i = 0; i < 6; i++) {
            func_0023c8c0(GROUND_PTR(work, 0x110 + i * 0x200));
        }
    }

    if (state >= 1 && state <= 5) {
        ((SflGroundRenderStateCallback)(void*)stateTable[0])(
            1, (u32)sflRes0020e590(2));
        for (i = 0; i < 48; i++) {
            u8* particle = (u8*)work + 0xd10 + i * 0x1300;
            if ((GROUND_U32(particle, 0) & 1) != 0) {
                u32 particleType = GROUND_U32(particle, 4);
                if (particleType == 0 || particleType == 2) {
                    RpSkyRenderStateSet(3, 0x717fb);
                    RpSkyRenderStateSet(2, 0x44);
                } else if (particleType == 1) {
                    RpSkyRenderStateSet(3, 0x71801);
                    RpSkyRenderStateSet(2, 0x48);
                }
                if (particleType <= 2) {
                    
                    ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
                        particle + 0x10, 4, 0, 1, 2);
                    ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
                        particle + 0x10, 4, 0, 2, 3);
                }
            }
        }
    }

    if (state == 3 || state == 4) {
        RpSkyRenderStateSet(3, 0x717fb);
        RpSkyRenderStateSet(2, 0x44);
        ((SflGroundRenderStateCallback)(void*)stateTable[0])(
            1, (u32)sflRes0020e690(4));
        for (i = 0; i < 7; i++) {
            for (j = 0; j < 4; j++) {
                
                ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
                    GROUND_PTR(work, 0x4810 + i * 0x420 + j * 0x100 + 0x10),
                    4, 0, 1, 2);
                ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
                    GROUND_PTR(work, 0x4810 + i * 0x420 + j * 0x100 + 0x10),
                    4, 0, 2, 3);
            }
        }
    }

    func_0024a180(GROUND_PTR(work, 0x8780));

    if (state == 3 || state == 4) {
        RpSkyRenderStateSet(3, 0x717fb);
        RpSkyRenderStateSet(2, 0x44);
        ((SflGroundRenderStateCallback)(void*)stateTable[0])(
            1, (u32)sflRes0020e510(3));
        
        ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
            GROUND_PTR(work, 0x4610), 4, 0, 1, 2);
        ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
            GROUND_PTR(work, 0x4610), 4, 0, 2, 3);

        RpSkyRenderStateSet(3, 0x717fb);
        RpSkyRenderStateSet(2, 0x44);
        ((SflGroundRenderStateCallback)(void*)stateTable[0])(
            1, (u32)sflRes0020e690(5));
        ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
            GROUND_PTR(work, 0x4710), 4, 0, 1, 2);
        ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
            GROUND_PTR(work, 0x4710), 4, 0, 2, 3);
    }

    
    if ((work[0] & 8) == 0) {
        ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
            GROUND_PTR(work, 0x65f0), 4, 0, 1, 2);
        ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
            GROUND_PTR(work, 0x65f0), 4, 0, 2, 3);
    }
    if ((work[0] & 0x10) == 0) {
        ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
            GROUND_PTR(work, 0x66f0), 4, 0, 1, 2);
        ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
            GROUND_PTR(work, 0x66f0), 4, 0, 2, 3);
    }
    ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
        GROUND_PTR(work, 0x67f0), 4, 0, 1, 2);
    ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
        GROUND_PTR(work, 0x67f0), 4, 0, 2, 3);
    if ((work[0] & 8) == 0) {
        ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
            GROUND_PTR(work, 0x68f0), 4, 0, 1, 2);
        ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
            GROUND_PTR(work, 0x68f0), 4, 0, 2, 3);
    }
    if ((work[0] & 0x10) == 0) {
        ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
            GROUND_PTR(work, 0x69f0), 4, 0, 1, 2);
        ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
            GROUND_PTR(work, 0x69f0), 4, 0, 2, 3);
    }
}

// FUN_0023C280
void func_0023c280(void)
{
    void* work;
    s32 i;

    K_ASSERT(sSflGround != NULL, 0x87);
    work = sSflGround;
    K_ASSERT((~GROUND_U32(work, 0) & 1) != 0, 0x4f2);
    for (i = 0; i < 6; i++) {
        func_0023c3a0((u8*)work + i * SFL_GROUND_PANEL_STRIDE + SFL_GROUND_PANEL_OFFSET);
    }
    func_0023d2a0();
    func_0023d650();
    GROUND_U32(work, 0xc) = 1;
    GROUND_U32(work, 4) = 0;
    GROUND_U32(work, 8) = 0;
    GROUND_U32(work, 0) |= 1;
}

// FUN_0023C350
u32 sflGround0023c350(void)
{
    K_ASSERT(sSflGround != NULL, 0x87);
    return *sSflGround & 1;
}

#pragma opt_loop_invariants on
// FUN_0023C3A0
void func_0023c3a0(void* destination)
{
    SflGroundViewport* viewport;
    f32 cameraScale;
    f32 width;
    f32 height;
    register f32 invWidth;
    f32 rect[4];
    u8* base;
    register s32 i;
    register s32 j;

    cameraScale = 1.0f / GROUND_F32(kwlnGetMainCamera(), 0x80);
    viewport = sflRes0020e590(1);
    width = (f32)viewport->width;
    height = (f32)viewport->height;
    invWidth = 1.0f / width;
    rect[0] = invWidth;
    rect[1] = 1.0f / height;
    rect[2] = 253.0f / width;
    rect[3] = 51.0f / height;
    func_0021eb80(destination, rect);
    rect[0] = invWidth;
    rect[1] = 52.0f / height;
    rect[2] = 182.0f / width;
    rect[3] = 75.0f / height;
    func_0021eb80((u8*)destination + 0x100, rect);
    for (i = 0; i < 2; i++) {
        j = 0;
        base = (u8*)destination + i * 0x100;
        while (j < 4) {
            GROUND_F32(base + j * 0x40, 8) =
                *(const volatile f32*)&D_00960088;
            GROUND_F32(base + j * 0x40, 0x18) = cameraScale;
            j++;
        }
    }
}
#pragma opt_loop_invariants off

// FUN_0023C520 NONMATCHING
void func_0023c520(void* destination, const SflGroundVec2* center,
                   const SflGroundVec2* direction, const SflGroundVec2* scale)
{
    SflGroundVec2 transformed[8];
    f32 length;
    f32 angle;
    f32 sine;
    f32 cosine;
    f32 x;
    f32 y;
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        transformed[i] = D_0068E7C0[i];
    }

    length = sqrtf(direction->x * direction->x + direction->y * direction->y);
    angle = func_0052ea18(direction->x / length, -(direction->y / length)) - gPI;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            transformed[i * 4 + j].x -= 126.5f;
            transformed[i * 4 + j].y -= 25.5f;
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            transformed[i * 4 + j].x *= scale->x;
            transformed[i * 4 + j].y *= scale->y;
        }
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            sine = sinf(angle);
            y = transformed[i * 4 + j].y;
            cosine = cosf(angle);
            x = transformed[i * 4 + j].x;
            transformed[i * 4 + j].x = x * cosine - y * sine;
            sine = sinf(angle);
            cosine = cosf(angle);
            y = transformed[i * 4 + j].y;
            transformed[i * 4 + j].y = x * sine + y * cosine;
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            transformed[i * 4 + j].x += center->x;
            transformed[i * 4 + j].y += center->y;
        }
    }
    for (i = 0; i < 2; i++) {
        func_0021d890((u8*)destination + i * 0x100, &transformed[i * 4]);
    }
}

// FUN_0023C850
void func_0023c850(void* vertices, const SflGroundColor* color)
{
    s32 i;

    for (i = 0; i < 2; i++) {
        func_0021d950((u8*)vertices + i * 0x100, color);
    }
}

#pragma optimization_level 1
// FUN_0023C8C0
void func_0023c8c0(void* vertices)
{
    void* vertices_p;
    register const volatile u32* stateTable;
    register const volatile u32* drawTable;

    vertices_p = vertices;
    stateTable = D_00960090;
    ((SflGroundRenderStateCallback)(void*)stateTable[0])(9, 2);
    ((SflGroundRenderStateCallback)(void*)stateTable[0])(0x14, 2);
    ((SflGroundRenderStateCallback)(void*)stateTable[0])(8, 0);
    ((SflGroundRenderStateCallback)(void*)stateTable[0])(6, 0);
    RpSkyRenderStateSet(3, 0x71801);
    RpSkyRenderStateSet(2, 0x48);
    ((SflGroundRenderStateCallback)(void*)stateTable[0])(
        1, (u32)sflRes0020e590(1));

    drawTable = D_0096009C;
    ((SflGroundRenderQuadCallback)(void*)drawTable[0])(vertices_p, 4, 0, 1, 2);
    ((SflGroundRenderQuadCallback)(void*)drawTable[0])(vertices_p, 4, 0, 2, 3);
    ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
        (u8*)vertices_p + 0x100, 4, 0, 1, 2);
    ((SflGroundRenderQuadCallback)(void*)drawTable[0])(
        (u8*)vertices_p + 0x100, 4, 0, 2, 3);
}
#pragma optimization_level 2

// FUN_0023CA10
void func_0023ca10(void)
{
    u32* work;
    SflGroundViewport* viewport;
    f32 cameraScale;
    f32 width;
    f32 height;
    f32 rect[4];
    s32 i;
    s32 j;
    u8* tile;
    K_ASSERT(sSflGround != NULL, 0x87);
    work = sSflGround;
    cameraScale = 1.0f / GROUND_F32(kwlnGetMainCamera(), 0x80);

    viewport = sflRes0020e690(5);
    width = (f32)viewport->width;
    height = (f32)viewport->height;
    rect[0] = 0.0f / width;
    rect[1] = 0.0f / height;
    rect[2] = width / width;
    rect[3] = height / height;
    func_0021eb80(GROUND_PTR(work, 0x4710), rect);

    viewport = sflRes0020e690(4);
    width = (f32)viewport->width;
    height = (f32)viewport->height;
    rect[0] = 1.0f / width;
    rect[1] = 0.0f / height;
    rect[2] = 51.0f / width;
    rect[3] = 128.0f / height;
    for (i = 0; i < 7; i++) {
        tile = (u8*)work + i * 0x420 + 0x4810;
        for (j = 0; j < 4; j++) {
            func_0021eb80(tile + j * 0x100 + 0x10, rect);
        }
    }
    for (j = 0; j < 7; j++) {
        tile = (u8*)work + j * 0x420 + 0x4810;
        GROUND_F32(tile, 0x410) = (f32)(RpRandom() & 0xfff) / 4095.0f;
        GROUND_U32(tile, 0x418) = RpRandom();
        GROUND_U32(tile, 0x414) = 0;
    }

    viewport = sflRes0020e690(3);
    width = (f32)viewport->width;
    height = (f32)viewport->height;
    rect[0] = 1.0f / width;
    rect[1] = 2.0f / height;
    rect[2] = 503.0f / width;
    rect[3] = 44.0f / height;
    for (j = 0; j < 6; j++) {
        tile = (u8*)work + j * 0x100;
        func_0021eb80(tile + 0x64f0, rect);
        GROUND_F32(tile, 0x64f8) = D_00960088;
        GROUND_F32(tile, 0x6508) = cameraScale;
    }

    work[1] = 0;
    work[0x1abc] = 0x78;
    work[0] |= 8;
    work[0] |= 0x10;
    work[0] |= 2;
    work[3] = 3;
}

// FUN_0023CD50
u32 sflGround0023cd50(void)
{
    K_ASSERT(sSflGround != NULL, 0x87);
    return *sSflGround & 2;
}

// FUN_0023CDA0
void func_0023cda0(void)
{
    u32* work;
    SflGroundViewport* viewport;
    f32 cameraScale;
    f32 width;
    f32 height;
    f32 rect[4];
    s32 i;
    s32 j;
    u8* tile;

    K_ASSERT(sSflGround != NULL, 0x87);
    work = sSflGround;
    cameraScale = 1.0f / GROUND_F32(kwlnGetMainCamera(), 0x80);

    viewport = sflRes0020e690(5);
    width = (f32)viewport->width;
    height = (f32)viewport->height;
    rect[0] = 0.0f / width;
    rect[1] = 0.0f / height;
    rect[2] = width / width;
    rect[3] = height / height;
    func_0021eb80(GROUND_PTR(work, 0x4710), rect);

    viewport = sflRes0020e690(4);
    width = (f32)viewport->width;
    height = (f32)viewport->height;
    rect[0] = 1.0f / width;
    rect[1] = 0.0f / height;
    rect[2] = 51.0f / width;
    rect[3] = 128.0f / height;
    for (i = 0; i < 7; i++) {
        tile = (u8*)work + i * 0x420 + 0x4810;
        for (j = 0; j < 4; j++) {
            func_0021eb80(tile + j * 0x100 + 0x10, rect);
        }
    }
    for (j = 0; j < 7; j++) {
        tile = (u8*)work + j * 0x420 + 0x4810;
        GROUND_F32(tile, 0x410) = (f32)(RpRandom() & 0xfff) / 4095.0f;
        GROUND_U32(tile, 0x418) = RpRandom();
        GROUND_U32(tile, 0x414) = 0;
    }

    viewport = sflRes0020e690(3);
    width = (f32)viewport->width;
    height = (f32)viewport->height;
    rect[0] = 1.0f / width;
    rect[1] = 47.0f / height;
    rect[2] = 511.0f / width;
    rect[3] = 44.0f / height;
    for (j = 0; j < 6; j++) {
        tile = (u8*)work + j * 0x100;
        func_0021eb80(tile + 0x64f0, rect);
        GROUND_F32(tile, 0x64f8) = D_00960088;
        GROUND_F32(tile, 0x6508) = cameraScale;
    }

    work[1] = 0;
    work[0x1abc] = 0x78;
    work[0] |= 8;
    work[0] |= 0x10;
    work[0] |= 0x20;
    work[3] = 4;
}

// FUN_0023D0E0
u32 sflGround0023d0e0(void)
{
    K_ASSERT(sSflGround != NULL, 0x87);
    return *sSflGround & 0x20;
}

// FUN_0023D130
void func_0023d130(void)
{
    u32* work;
    SflGroundViewport* viewport;
    f32 width;
    f32 height;
    f32 rect[4];

    K_ASSERT(sSflGround != NULL, 0x87);
    work = sSflGround;
    viewport = sflRes0020e510(3);
    width = (f32)viewport->width;
    height = (f32)viewport->height;
    rect[0] = 0.0f / width;
    rect[1] = 0.0f / height;
    rect[2] = width / width;
    rect[3] = height / height;
    func_0021eb80(GROUND_PTR(work, 0x4610), rect);
    func_002496e0(GROUND_PTR(work, SFL_GROUND_WORK_SIZE));
    work[1] = 0;
    work[0] |= 4;
    work[3] = 2;
}

// FUN_0023D1F0
u32 sflGround0023d1f0(void)
{
    K_ASSERT(sSflGround != NULL, 0x87);
    return *sSflGround & 4;
}

// FUN_0023D240
void sflGround0023d240(void)
{
    int base;

    K_ASSERT(sSflGround != NULL, 0x87);
    base = (int)sSflGround;
    FUN_0023d2a0();
    FUN_0023d650();
    *(u32*)(base + 8) = 0;
    *(u32*)(base + 0xc) = 5;
}

#pragma opt_loop_invariants on
// FUN_0023D2A0 NONMATCHING
void func_0023d2a0(void)
{
    u32* work;
    SflGroundViewport* viewport;
    f32 width;
    f32 height;
    register f32 rect0;
    register f32 rect1;
    register f32 rect2;
    register f32 rect3;
    f32 rect[4];
    s32 i;
    u32* particle;
    u32 lifetime;

    K_ASSERT(sSflGround != NULL, 0x87);
    work = sSflGround;
    viewport = sflRes0020e590(2);
    width = (f32)viewport->width;
    height = (f32)viewport->height;
    i = 0;
    rect0 = 0.0f / width;
    rect1 = 1.0f / height;
    rect2 = 63.0f / width;
    rect3 = 81.0f / height;
    for (; i < 48; i++) {
        particle = (u32*)GROUND_PTR(work, SFL_GROUND_PARTICLE_OFFSET + i * SFL_GROUND_PARTICLE_STRIDE);
        GROUND_U32(particle, 0) = 0;
        rect[0] = rect0;
        rect[1] = rect1;
        rect[2] = rect2;
        rect[3] = rect3;
        func_0021eb80(GROUND_PTR(particle, 0x10), rect);
    }
    for (i = 0; i < 48; i++) {
        particle = (u32*)GROUND_PTR(work, SFL_GROUND_PARTICLE_OFFSET + i * SFL_GROUND_PARTICLE_STRIDE);
        GROUND_U32(particle, 0) |= 1;
        lifetime = 0x78 + RpRandom() % 0x3c;
        GROUND_U32(particle, 0x114) = lifetime;
        GROUND_U32(particle, 4) = RpRandom() % 3;
        GROUND_F32(particle, 0x118) = -20.0f + 680.0f * (f32)(RpRandom() & 0xfff) / 4095.0f;
        GROUND_F32(particle, 0x11c) = -20.0f + 488.0f * (f32)(RpRandom() & 0xfff) / 4095.0f;
        GROUND_F32(particle, 0x120) = 640.0f * (f32)(RpRandom() & 0xfff) / 4095.0f;
        GROUND_F32(particle, 0x124) = 448.0f * (f32)(RpRandom() & 0xfff) / 4095.0f;
        GROUND_U32(particle, 0x110) = RpRandom() % lifetime;
    }
}
#pragma opt_loop_invariants off

#pragma opt_loop_invariants on
// FUN_0023D650
void func_0023d650(void)
{
    u32* work;
    SflGroundViewport* viewport;
    f32 cameraScale;
    f32 width;
    f32 height;
    f32 rect[4];
    s32 column;
    u32 white;
    s32 row;

    K_ASSERT(sSflGround != NULL, 0x87);
    work = sSflGround;
    cameraScale = 1.0f / GROUND_F32(kwlnGetMainCamera(), 0x80);
    viewport = sflRes0020e590(0);
    width = (f32)viewport->width;
    height = (f32)viewport->height;
    rect[0] = 1.0f / width;
    rect[1] = 1.0f / height;
    rect[2] = (width - 2.0f) / width;
    rect[3] = (height - 2.0f) / height;
    func_0021eb80(GROUND_PTR(work, 0x10), rect);
    white = 0x437f0000;
    row = 0;
    while (row < 9) {
        column = 0;
        while (column < 11) {
            u8* tile;
            tile = (u8*)work + SFL_GROUND_TILE_OFFSET +
                   (row * 11 + column) * SFL_GROUND_TILE_STRIDE;
            GROUND_F32(tile, 8) = *(const volatile f32*)&D_00960088;
            GROUND_F32(tile, 0x18) = cameraScale;
            GROUND_U32(tile, 0x20) = white;
            GROUND_U32(tile, 0x24) = white;
            GROUND_U32(tile, 0x28) = white;
            GROUND_U32(tile, 0x2c) = white;
            column++;
        }
        row++;
    }
}
#pragma opt_loop_invariants off
