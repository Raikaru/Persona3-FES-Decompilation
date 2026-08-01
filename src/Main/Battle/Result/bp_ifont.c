#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Result/bp_ifont.h"

#pragma alias D_00960088_y2 D_00960088
#pragma alias kwlnGetMainCamera_y2 kwlnGetMainCamera
#pragma alias func_0021d8e0_y2 func_0021d8e0


extern void* H_Maestro_001120a0(s32 font);
extern void* kwlnGetMainCamera(void);
extern void func_0021d8e0(void* panel, const float* rect);
extern int sprintf(char* buffer, const char* format, ...);
extern u32 strlen(const char* string);
extern char D_00960088[];


// FUN_00238980
void bpIFont00238980(void* glyphs, s32 capacity, s32 value, s32 style)
{
    char digits[0x100];
    s32 i;
    s32 length;

    sprintf(digits, "%d", value);
    length = (s32)strlen(digits);
    K_ASSERT(capacity >= length, 0x25);
    for (i = 0; i < length; i++) {
        bpIFont00238fd0((u8*)glyphs + i * 0x100, digits[length - 1 - i] - '0', style);
    }
}

// FUN_00238a50
void bpIFont00238a50(void* glyphs, s32 capacity, s32 value, s32 font, const float* origin)
{
    float rect[4];
    char digits[0x100];
    void* fontData;
    u8* character;
    s32 i;
    u32 length;

    fontData = H_Maestro_001120a0(font);
    sprintf(digits, "%d", value);
    length = strlen(digits);
    K_ASSERT(capacity >= (s32)length, 0x38);
    for (i = 0; i < (s32)length; i++) {
        s32 index = length - 1 - i;

        character = *(u8**)((u8*)fontData + 0x184) + (digits[index] - 0x25) * 0x80;
        rect[0] = origin[0] + (float)(index * 15);
        rect[1] = origin[1];
        rect[2] = (float)(*(s32*)(character + 0x5c) - *(s32*)(character + 0x54));
        rect[3] = (float)(*(s32*)(character + 0x60) - *(s32*)(character + 0x58));
        func_0021d8e0((u8*)glyphs + i * 0x100, rect);
    }
    for (; (s32)length < capacity; length++) {
        rect[0] = origin[0];
        rect[1] = origin[1];
        rect[2] = 0.0f;
        rect[3] = 0.0f;
        func_0021d8e0((u8*)glyphs + length * 0x100, rect);
    }
}

// FUN_00238bf0
void bpIFont00238bf0(void* glyphs, s32 capacity, const char* text, s32 font, const float* origin)
{
    float rect[4];
    char digits[0x100];
    void* fontData;
    u8* character;
    s32 i;
    s32 length;
    s32 offset;
    float x;

    fontData = H_Maestro_001120a0(font);
    sprintf(digits, "%s", text);
    length = (s32)strlen(digits);
    K_ASSERT(capacity >= length, 0x59);
    i = 0;
    offset = (capacity - length) * 15;
    for (; i < length; i++) {
        s32 index = length - 1 - i;

        character = *(u8**)((u8*)fontData + 0x184) + (digits[index] - 0x25) * 0x80;
        x = origin[0] + (float)(index * 15);
        rect[0] = x + (float)offset;
        rect[1] = origin[1];
        rect[2] = (float)(*(s32*)(character + 0x5c) - *(s32*)(character + 0x54));
        rect[3] = (float)(*(s32*)(character + 0x60) - *(s32*)(character + 0x58));
        func_0021d8e0((u8*)glyphs + i * 0x100, rect);
    }
    for (; length < capacity; length++) {
        rect[0] = origin[0];
        rect[1] = origin[1];
        rect[2] = 0.0f;
        rect[3] = 0.0f;
        func_0021d8e0((u8*)glyphs + length * 0x100, rect);
    }
}

// FUN_00238dc0
void bpIFont00238dc0(void* glyphs, s32 capacity, const char* text, s32 font, const float* origin)
{
    float rect[4];
    char buffer[0x100];
    void* fontData;
    u8* character;
    s32 i;
    u32 length;
    s32 leftOffset;
    s32 textOffset;

    fontData = H_Maestro_001120a0(font);
    sprintf(buffer, "%s", text);
    length = strlen(buffer);
    K_ASSERT(capacity >= (s32)length, 0x7a);
    i = 0;
    leftOffset = capacity * 15 / 2;
    textOffset = (s32)length * 15 / 2;
    for (; i < (s32)length; i++) {
        s32 index = length - 1 - i;

        character = *(u8**)((u8*)fontData + 0x184) + (buffer[index] - 0x25) * 0x80;
        rect[0] = (float)leftOffset + (origin[0] + (float)(index * 15)) - (float)textOffset;
        rect[1] = origin[1];
        rect[2] = (float)(*(s32*)(character + 0x5c) - *(s32*)(character + 0x54));
        rect[3] = (float)(*(s32*)(character + 0x60) - *(s32*)(character + 0x58));
        func_0021d8e0((u8*)glyphs + i * 0x100, rect);
    }
    for (; (s32)length < capacity; length++) {
        rect[0] = origin[0];
        rect[1] = origin[1];
        rect[2] = 0.0f;
        rect[3] = 0.0f;
        func_0021d8e0((u8*)glyphs + length * 0x100, rect);
    }
}

// FUN_00238fd0
void bpIFont00238fd0(void* glyph, s32 character, s32 style)
{
    void* camera;
    void* fontData;
    u8* source;
    u8* texture;
    s32 textureAddress;
    float inverseScale;
    float x0;
    float y0;
    float x1;
    float y1;
    float* vertex;
    float* depth;

    camera = kwlnGetMainCamera();
    inverseScale = 1.0f / *(float*)((u8*)camera + 0x80);
    fontData = H_Maestro_001120a0(style);
    source = *(u8**)((u8*)fontData + 0x184) + (character + 0xb) * 0x80;
    textureAddress = *(s32*)(source + 0x14) * 4;
    textureAddress += (s32)fontData;
    texture = *(u8**)(textureAddress + 0x104);
    x0 = (float)*(s32*)(source + 0x54) / (float)*(s32*)(texture + 0xc);
    y0 = (float)*(s32*)(source + 0x58) / (float)*(s32*)(texture + 0x10);
    x1 = (float)*(s32*)(source + 0x5c) / (float)*(s32*)(texture + 0xc);
    y1 = (float)*(s32*)(source + 0x60) / (float)*(s32*)(texture + 0x10);

    vertex = (float*)glyph;
    vertex[4] = x0;
    vertex[5] = y0;
    vertex[6] = inverseScale;
    depth = (float*)D_00960088;
    vertex[2] = *depth;
    vertex[8] = 255.0f;
    vertex[9] = 255.0f;
    vertex[10] = 255.0f;
    vertex[11] = 255.0f;

    vertex = (float*)((u8*)glyph + 0x40);
    vertex[4] = x1;
    vertex[5] = y0;
    vertex[6] = inverseScale;
    vertex[2] = *depth;
    vertex[8] = 255.0f;
    vertex[9] = 255.0f;
    vertex[10] = 255.0f;
    vertex[11] = 255.0f;

    vertex = (float*)((u8*)glyph + 0x80);
    vertex[4] = x1;
    vertex[5] = y1;
    vertex[6] = inverseScale;
    vertex[2] = *depth;
    vertex[8] = 255.0f;
    vertex[9] = 255.0f;
    vertex[10] = 255.0f;
    vertex[11] = 255.0f;

    vertex = (float*)((u8*)glyph + 0xc0);
    vertex[4] = x0;
    vertex[5] = y1;
    vertex[6] = inverseScale;
    vertex[2] = *depth;
    vertex[8] = 255.0f;
    vertex[9] = 255.0f;
    vertex[10] = 255.0f;
    vertex[11] = 255.0f;
}


#include "Main/Social/sfl_res.h"

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

extern const f32 D_00960088_y2;
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
void func_00249680(void* work);

// FUN_00239140
void* func_00239140(s32 font)
{
    return *(void**)((u8*)H_Maestro_001120a0(font) + 0x104);
}


void FUN_0023d2a0();
void FUN_0023d650();
void func_002496e0();
void func_00249c10();
void func_0024a180();
void func_0024a230();
void* kwlnGetMainCamera_y2();
void func_0021d890(void* destination, const void* layout);
void func_0021d8e0_y2(void* destination, const void* rect);
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
f32 sinf(f32 angle);
void func_002392d0();
void func_0023b990();
void func_0023c280();
void func_0023c3a0();
void func_0023c520();
void func_0023c850();

static void sflGroundCallState(u32 selector, u32 value);
static void sflGroundCallStateTable(const u32* table, u32 selector, u32 value);
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
    cameraScale = 1.0f / GROUND_F32(kwlnGetMainCamera_y2(), 0x80);

    viewport = sflResGetEffectRaster(5);
    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = 1.0f;
    rect[3] = 1.0f;
    func_0021eb80(GROUND_PTR(work, 0x4710), rect);

    viewport = sflResGetEffectRaster(4);
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

    viewport = sflResGetEffectRaster(3);
    rect[0] = 1.0f / (f32)viewport->width;
    rect[1] = 0.0f;
    rect[2] = (flag == 0x20 ? 511.0f : 503.0f) / (f32)viewport->width;
    rect[3] = 44.0f / (f32)viewport->height;
    for (i = 0; i < 6; i++) {
        func_0021eb80(GROUND_PTR(work, 0x64f0 + i * 0x100), rect);
        GROUND_F32(work, 0x64f8 + i * 0x100) = D_00960088_y2;
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






/* Removing this loses FUN_0023c3a0 (MATCH nd0 -> MISMATCH nd34) - measured W161. */


/* Removing this loses func_0023c8c0 (MATCH nd0 -> MISMATCH nd228), newly over-window 336/336 -> 352/336 - measured W161. */








/* Removing this loses FUN_0023d650 (MATCH nd0 -> MISMATCH nd60) - measured W161. */
