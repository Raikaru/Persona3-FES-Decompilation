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

typedef void (*SflGroundTickCallback)(void);
typedef void (*SflGroundRenderStateCallback)(u32 selector, u32 value);
typedef void (*SflGroundRenderQuadCallback)(void* vertices, u32 count,
                                             u32 group, u32 pass, u32 blend);

#define GROUND_PTR(work, offset) ((void*)((u8*)(work) + (offset)))
#define GROUND_U32(work, offset) (*(u32*)GROUND_PTR((work), (offset)))
#define GROUND_F32(work, offset) (*(f32*)GROUND_PTR((work), (offset)))

enum
{
    SFL_GROUND_WORK_SIZE = 0x8780,
    SFL_GROUND_PANEL_OFFSET = 0x110,
    SFL_GROUND_PANEL_STRIDE = 0x200,
    SFL_GROUND_PARTICLE_OFFSET = 0xD10,
    SFL_GROUND_PARTICLE_STRIDE = 0x1300,
    SFL_GROUND_TILE_OFFSET = 0x6B00,
    SFL_GROUND_TILE_STRIDE = 0x40
};

extern u32 D_00960088;
extern u32 D_00960090[];
extern u32 D_0096009C[];

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
void func_0021d890();
void func_0021d8e0();
void func_0021d950();
void func_0021e170();
void func_0021eb80();
f32 func_0052ea18();
u32 RpRandom();
void RpSkyRenderStateSet();
f32 sinf(f32 angle);
f32 cosf(f32 angle);
void func_002392d0();
void func_0023b990();
void func_0023c280();
void func_0023c3a0();
void func_0023c520();
void func_0023c850();

static void sflGroundCallState(u32 selector, u32 value);
// FUN_0024A180 NONMATCHING
void func_0024a180(void* work)
{
    u32* owner;
    SflGroundTickCallback callback;

    if ((GROUND_U32(work, 0x604) & 1) != 0)
    {
        return;
    }

    sflGroundCallState(9, 2);
    sflGroundCallState(0x14, 2);
    sflGroundCallState(6, 0);
    sflGroundCallState(8, 0);

    owner = *(u32**)GROUND_PTR(work, 0x600);
    callback = *(SflGroundTickCallback*)((u8*)owner + 0x48);
    callback();
}

// FUN_0024A230 NONMATCHING
void func_0024a230(void* work, const SflGroundColor* color)
{
    u8* destination;

    destination = (u8*)work + 0x614;
    destination[0] = color->r;
    destination[1] = color->g;
    destination[2] = color->b;
    destination[3] = color->a;
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
    ((SflGroundRenderStateCallback)(void*)D_00960090)(selector, value);
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
    GROUND_F32(particle, 0x118) = -20.0f + 680.0f * sflGroundRandomUnit();
    GROUND_F32(particle, 0x11c) = -20.0f + 500.0f * sflGroundRandomUnit();
    GROUND_F32(particle, 0x120) = 160.0f * sflGroundRandomUnit();
    GROUND_F32(particle, 0x124) = 480.0f * sflGroundRandomUnit();
    particle[0x40] = RpRandom() % lifetime;
}

static void sflGroundInitFxLayout(u32 flag, s32 state)
{
    u32* work;
    u32* viewport;
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
    rect[0] = 1.0f / (f32)viewport[3];
    rect[1] = 0.0f;
    rect[2] = 51.0f / (f32)viewport[3];
    rect[3] = 128.0f / (f32)viewport[4];
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 4; j++) {
            func_0021eb80(GROUND_PTR(work, 0x4810 + i * 0x420 + j * 0x100), rect);
        }
        GROUND_F32(work, 0x4c20 + i * 0x420) = sflGroundRandomUnit();
        GROUND_U32(work, 0x4c24 + i * 0x420) = 0;
        GROUND_U32(work, 0x4c28 + i * 0x420) = RpRandom();
    }

    viewport = sflRes0020e690(3);
    rect[0] = 1.0f / (f32)viewport[3];
    rect[1] = 0.0f;
    rect[2] = (flag == 0x20 ? 511.0f : 503.0f) / (f32)viewport[3];
    rect[3] = 44.0f / (f32)viewport[4];
    for (i = 0; i < 6; i++) {
        func_0021eb80(GROUND_PTR(work, 0x64f0 + i * 0x100), rect);
        GROUND_F32(work, 0x64f8 + i * 0x100) = *(f32*)&D_00960088;
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
    SflGroundVec2 center;
    SflGroundVec2 direction;
    SflGroundVec2 scale;
    SflGroundColor color;
    f32 opacity;
    s32 i;

    K_ASSERT(sSflGround != NULL, 0x87);
    work = sSflGround;
    switch (work[3]) {
    case 1:
        if ((work[0] & 1) != 0 && work[1]++ >= 20) {
            work[0] &= ~1;
        }
        break;
    case 2:
        if ((work[0] & 4) != 0 && work[1]++ >= 30) {
            work[0] &= ~4;
        }
        break;
    case 3:
        if ((work[0] & 2) != 0 && work[1]++ >= 30) {
            work[0] &= ~2;
        }
        break;
    case 4:
        if ((work[0] & 0x20) != 0 && work[1]++ >= 30) {
            work[0] &= ~0x20;
        }
        break;
    default:
        break;
    }

    work[2] = (work[2] + 1) % 180;
    work[0x1abc] = (work[0x1abc] + 1) % 240;
    opacity = work[3] == 5 ? 1.0f : sflGroundClamp01((f32)work[1] / 30.0f);
    color.r = 0xff;
    color.g = 0xff;
    color.b = 0xff;
    color.a = sflGroundAlpha(opacity);
    scale.x = 1.0f;
    scale.y = 1.0f;
    for (i = 0; i < 6; i++) {
        center.x = 160.0f;
        center.y = 96.0f + (f32)(i * 20);
        direction.x = cosf((f32)(work[2] + i * 20) / 40.0f);
        direction.y = sinf((f32)(work[2] + i * 20) / 40.0f);
        func_0023c520(GROUND_PTR(work, SFL_GROUND_PANEL_OFFSET + i * SFL_GROUND_PANEL_STRIDE),
                       &center, &direction, &scale);
        func_0023c850(GROUND_PTR(work, SFL_GROUND_PANEL_OFFSET + i * SFL_GROUND_PANEL_STRIDE), &color);
    }
    for (i = 0; i < 9; i++) {
        center.x = (f32)i * 8.0f;
        center.y = 0.0f;
        func_0021d8e0(GROUND_PTR(work, 0x4710 + i * 0x420), &center);
    }
    sflGroundUpdateParticles(work, opacity);
    func_0024a230(GROUND_PTR(work, SFL_GROUND_WORK_SIZE), &color);
    func_00249c10(GROUND_PTR(work, SFL_GROUND_WORK_SIZE));
}

// FUN_0023B990 NONMATCHING
void func_0023b990(void)
{
    u32* work;
    s32 i;
    s32 j;

    K_ASSERT(sSflGround != NULL, 0x87);
    work = sSflGround;
    sflGroundCallState(9, 2);
    sflGroundCallState(0x14, 2);
    sflGroundCallState(8, 0);
    if (work[3] >= 1 && work[3] <= 5) {
        sflGroundSetSkyState(0x717fb);
        sflGroundCallState(1, (u32)sflRes0020e590(0));
        for (i = 0; i < 6; i++) {
            sflGroundDraw(GROUND_PTR(work, SFL_GROUND_PANEL_OFFSET + i * SFL_GROUND_PANEL_STRIDE), 1, 2);
            sflGroundDraw(GROUND_PTR(work, SFL_GROUND_PANEL_OFFSET + i * SFL_GROUND_PANEL_STRIDE), 2, 3);
        }
    }
    if (work[3] == 3 || work[3] == 4) {
        sflGroundSetSkyState(0x71801);
        for (i = 0; i < 7; i++) {
            for (j = 0; j < 4; j++) {
                sflGroundDraw(GROUND_PTR(work, 0x4810 + i * 0x420 + j * 0x100), 1, 2);
            }
        }
    }
    if ((work[0] & 8) == 0) {
        sflGroundDraw(GROUND_PTR(work, 0x65f0), 1, 2);
    }
    if ((work[0] & 0x10) == 0) {
        sflGroundDraw(GROUND_PTR(work, 0x66f0), 1, 2);
    }
    sflGroundDraw(GROUND_PTR(work, 0x67f0), 1, 2);
    if ((work[0] & 8) == 0) {
        sflGroundDraw(GROUND_PTR(work, 0x68f0), 1, 2);
    }
    if ((work[0] & 0x10) == 0) {
        sflGroundDraw(GROUND_PTR(work, 0x69f0), 1, 2);
    }
    func_0024a180(GROUND_PTR(work, SFL_GROUND_WORK_SIZE));
}

// FUN_0023C280 NONMATCHING
void func_0023c280(void)
{
    u32* work;
    s32 i;

    K_ASSERT(sSflGround != NULL, 0x87);
    work = sSflGround;
    K_ASSERT(work[0] & 1, 0x4f2);
    for (i = 0; i < 6; i++) {
        func_0023c3a0(GROUND_PTR(work, SFL_GROUND_PANEL_OFFSET + i * SFL_GROUND_PANEL_STRIDE));
    }
    func_0023d2a0();
    func_0023d650();
    work[3] = 1;
    work[1] = 0;
    work[2] = 0;
    work[0] |= 1;
}

// FUN_0023C350
u32 sflGround0023c350(void)
{
    K_ASSERT(sSflGround != NULL, 0x87);
    return *sSflGround & 1;
}

// FUN_0023C3A0 NONMATCHING
void func_0023c3a0(void* destination)
{
    u32* viewport;
    f32 cameraScale;
    f32 rect[4];
    s32 i;
    s32 j;

    cameraScale = 1.0f / GROUND_F32(kwlnGetMainCamera(), 0x80);
    viewport = sflRes0020e590(1);
    rect[0] = 1.0f / (f32)viewport[3];
    rect[1] = 1.0f / (f32)viewport[4];
    rect[2] = 253.0f / (f32)viewport[3];
    rect[3] = 51.0f / (f32)viewport[4];
    func_0021eb80(destination, rect);
    rect[1] = 52.0f / (f32)viewport[4];
    rect[2] = 182.0f / (f32)viewport[3];
    rect[3] = 75.0f / (f32)viewport[4];
    func_0021eb80((u8*)destination + 0x100, rect);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            GROUND_F32(destination, i * 0x100 + j * 0x40 + 8) = *(f32*)&D_00960088;
            GROUND_F32(destination, i * 0x100 + j * 0x40 + 0x18) = cameraScale;
        }
    }
}

// FUN_0023C520 NONMATCHING
void func_0023c520(void* destination, const SflGroundVec2* center,
                   const SflGroundVec2* direction, const SflGroundVec2* scale)
{
    static const SflGroundVec2 quad[8] = {
        { -25.5f, -25.5f }, { 25.5f, -25.5f }, { -25.5f, 25.5f }, { 25.5f, 25.5f },
        { -25.5f, -25.5f }, { 25.5f, -25.5f }, { -25.5f, 25.5f }, { 25.5f, 25.5f }
    };
    SflGroundVec2 transformed[8];
    f32 angle;
    f32 c;
    f32 s;
    f32 x;
    f32 y;
    s32 i;

    angle = func_0052ea18(direction->x, -direction->y);
    c = cosf(angle);
    s = sinf(angle);
    for (i = 0; i < 8; i++) {
        x = quad[i].x * scale->x;
        y = quad[i].y * scale->y;
        transformed[i].x = center->x + x * c - y * s;
        transformed[i].y = center->y + x * s + y * c;
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

// FUN_0023C8C0 NONMATCHING
void func_0023c8c0(void* vertices)
{
    sflGroundCallState(9, 2);
    sflGroundCallState(0x14, 2);
    sflGroundCallState(8, 0);
    sflGroundSetSkyState(0x71801);
    sflGroundCallState(1, (u32)sflRes0020e590(1));
    sflGroundDraw(vertices, 1, 2);
    sflGroundDraw(vertices, 2, 3);
    sflGroundDraw((u8*)vertices + 0x100, 1, 2);
    sflGroundDraw((u8*)vertices + 0x100, 2, 3);
}

// FUN_0023CA10 NONMATCHING
void func_0023ca10(void)
{
    sflGroundInitFxLayout(2, 3);
}

// FUN_0023CD50
u32 sflGround0023cd50(void)
{
    K_ASSERT(sSflGround != NULL, 0x87);
    return *sSflGround & 2;
}

// FUN_0023CDA0 NONMATCHING
void func_0023cda0(void)
{
    sflGroundInitFxLayout(0x20, 4);
}

// FUN_0023D0E0
u32 sflGround0023d0e0(void)
{
    K_ASSERT(sSflGround != NULL, 0x87);
    return *sSflGround & 0x20;
}

// FUN_0023D130 NONMATCHING
void func_0023d130(void)
{
    u32* work;
    u32* viewport;
    f32 rect[4];

    K_ASSERT(sSflGround != NULL, 0x87);
    work = sSflGround;
    viewport = sflRes0020e510(3);
    rect[0] = 0.0f / (f32)viewport[3];
    rect[1] = 0.0f / (f32)viewport[4];
    rect[2] = 1.0f;
    rect[3] = 1.0f;
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

// FUN_0023D2A0 NONMATCHING
void func_0023d2a0(void)
{
    u32* work;
    u32* viewport;
    f32 rect[4];
    s32 i;
    u32* particle;

    K_ASSERT(sSflGround != NULL, 0x87);
    work = sSflGround;
    viewport = sflRes0020e590(2);
    rect[0] = 0.0f;
    rect[1] = 1.0f / (f32)viewport[4];
    rect[2] = 63.0f / (f32)viewport[3];
    rect[3] = 81.0f / (f32)viewport[4];
    for (i = 0; i < 48; i++) {
        particle = (u32*)GROUND_PTR(work, SFL_GROUND_PARTICLE_OFFSET + i * SFL_GROUND_PARTICLE_STRIDE);
        particle[0] = 0;
        func_0021eb80(GROUND_PTR(particle, 0x10), rect);
    }
    for (i = 0; i < 48; i++) {
        particle = (u32*)GROUND_PTR(work, SFL_GROUND_PARTICLE_OFFSET + i * SFL_GROUND_PARTICLE_STRIDE);
        sflGroundInitParticle(particle);
    }
}

// FUN_0023D650 NONMATCHING
void func_0023d650(void)
{
    u32* work;
    u32* viewport;
    f32 cameraScale;
    f32 rect[4];
    s32 row;
    s32 column;
    void* tile;

    K_ASSERT(sSflGround != NULL, 0x87);
    work = sSflGround;
    cameraScale = 1.0f / GROUND_F32(kwlnGetMainCamera(), 0x80);
    viewport = sflRes0020e590(0);
    rect[0] = 1.0f / (f32)viewport[3];
    rect[1] = 1.0f / (f32)viewport[4];
    rect[2] = ((f32)viewport[3] - 2.0f) / (f32)viewport[3];
    rect[3] = ((f32)viewport[4] - 2.0f) / (f32)viewport[4];
    func_0021eb80(GROUND_PTR(work, 0x10), rect);
    for (row = 0; row < 9; row++) {
        for (column = 0; column < 11; column++) {
            tile = GROUND_PTR(work, SFL_GROUND_TILE_OFFSET + (row * 11 + column) * SFL_GROUND_TILE_STRIDE);
            GROUND_F32(tile, 8) = *(f32*)&D_00960088;
            GROUND_F32(tile, 0x18) = cameraScale;
            GROUND_F32(tile, 0x20) = 255.0f;
            GROUND_F32(tile, 0x24) = 255.0f;
            GROUND_F32(tile, 0x28) = 255.0f;
            GROUND_F32(tile, 0x2c) = 255.0f;
        }
    }
}
