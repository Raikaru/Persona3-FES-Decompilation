#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Utils.h"

extern u32 datGetFlag(s32 flag);
extern void* func_00198590(void);
extern void* kwlnGetMainCamera_y2(void);
extern void* func_00474210(u32 flags, u32 mode, void* parent);
extern void** func_003210a0(s32 index);
extern void* func_004caf10(void);
extern void func_004caf80(void* resource);
extern void func_00474640(void* resource, void** buffer, s32 type, u32 flags);
extern void func_00492d10(void* resource, void* model);
extern void func_004747f0(void* resource);
extern u32 func_00488f30(void);
extern void func_00494d50(void* material, void* texture);
extern void* func_004cb2f0(void* model);
extern void func_004c6be0(void* destination, const void* source, void* matrix);
extern void func_00521250(void* destination, const void* source, u32 size);
extern void func_005225a8(const void* name, ...);
extern u32 DAT_007ce770;
extern const u8 D_0068E880[];
extern void* func_004c38c0(void);
extern void func_004c32a0(void* destination, const void* source);
extern void func_004cb750(void* frame, const void* translation, s32 mode);
extern f32 sqrtf(f32 value);
extern void func_004c3880(void* matrix);
extern void func_004c3760(void* matrix, void* source, s32 mode);
extern void RwMatrixScale(void* matrix, const void* scale, s32 combine);
extern void RwMatrixTranslate(void* matrix, const void* translation, s32 combine);
extern void RwV3dTransformPoint(void* out, const void* in, const void* matrix);
extern u32* sBpc324; // 007CE324 / GP -0x49CC
u32* sBpc328;
typedef void (*BpcRenderState)(s32 property, u32 value);
typedef void (*BpcRenderQuad)(void* quad, s32 count, s32 group, s32 pass, s32 blend);
extern BpcRenderState gBpcRenderState;
extern BpcRenderQuad gBpcRenderQuad;
extern u32 D_00960090_y2[];
extern u32 D_0096009C_y2[];
extern void RpSkyRenderStateSet(s32 state, u32 value);
extern u32 func_0021c3f0(s32 texture);
extern u32 func_0021cca0(u32 texture, s32 frame);
extern u32 func_0021cce0(u32 frame);
extern void* func_0021c550(s32 index);
extern void func_0021d3b0(void* destination, u32 frame);
extern void func_0021d8e0(void* destination, const f32* layout);
extern void func_0021d950_y2(void* destination, const u8* color);
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
extern void frFontSetTextScale(u32 resource, f32 angle);
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
extern s32 datGetFlag_y2(s32 flag);
extern void datSetFlag(s32 flag, u8 value);
extern void* func_0030c0c0(void);
void* FUN_00248f40(void*);
void FUN_002491f0(void);
void FUN_00248fc0(void*);
#include "Main/Social/sfl_res.h"
static u32* sSflGround; // puGpffffb624 / DAT_007ce314
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
void FUN_00249690_y2();
void* H_Maestro_001120a0(s32 font);
void func_00249680_y2(void* work);
void FUN_0023d2a0();
void FUN_0023d650();
void func_002496e0_y2();
void func_00249c10_y2();
void func_0024a180();
void func_0024a230();
void* kwlnGetMainCamera();
void func_0021d890(void* destination, const void* layout);
void func_0021d8e0_y2(void* destination, const void* rect);
void func_0021d950(void* destination, const void* color);
void func_0021e170(void* destination, const void* center,
                   const void* direction, const void* size);
void func_0021eb80(void* destination, const f32* layout);
f32 func_0052ea18(f32 y, f32 x);
f32 func_00269c80(f32 value);
f32 func_00269ca0(f32 value);
u32 RpRandom();
f32 func_0052e878(f32 angle);
f32 func_0052e6d8(f32 angle);
f32 cosf(f32 angle);
f32 sinf(f32 angle);
void func_002392d0();
void func_0023b990();
void func_0023c280();
void func_0023c3a0(void* destination);
void func_0023c520();
void func_0023c850(void* vertices, const SflGroundColor* color);
static void sflGroundCallState(u32 selector, u32 value);
static void sflGroundCallStateTable(const u32* table, u32 selector, u32 value);
void func_0023c8c0(void* vertices);
void func_0023ca10();
void func_0023cda0();
void func_0023d130();
void func_0023d2a0();
void func_0023d650();


#pragma alias D_00960090_y2 D_00960090
#pragma alias D_0096009C_y2 D_0096009C
#pragma alias kwlnGetMainCamera_y2 kwlnGetMainCamera
#pragma alias func_0021d950_y2 func_0021d950
#pragma alias FUN_00249690_y2 FUN_00249690
#pragma alias func_00249680_y2 func_00249680
#pragma alias func_002496e0_y2 func_002496e0
#pragma alias func_00249c10_y2 func_00249c10
#pragma alias func_0021d8e0_y2 func_0021d8e0


#pragma alias datGetFlag_y2 datGetFlag

 
static u32* sBpeWork; // puGpffffb638

 
void FUN_003c77a0();


// FUN_00249250
void bpe00249250(void)
{
    K_ASSERT(sBpeWork != NULL, 0x37);
    if (*sBpeWork & 1)
    {
        FUN_003c77a0();
    }
    sBpeWork = NULL;
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
    firstMessage = !(datGetFlag_y2(0x1301) != 0);
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

// FUN_00249600
u32 bpe00249600(void)
{
    K_ASSERT(sBpeWork != NULL, 0x37);
    return *sBpeWork & 1;
}

// FUN_00249650
u32 func_00249650(u32 flag)
{
    return !datGetFlag((s32)(flag & 0xffffu) + 0x12c0);
}

/* Removing this worsens FUN_002496e0 (nd110 -> nd136) - measured W161. */
// FUN_00249680
void func_00249680(void* work)
{
    *(u32*)((u8*)work + 0x604) = 0;
}
// FUN_00249690
void FUN_00249690(void* work)
{
    u8* base;

    base = (u8*)work;
    if (*(u32*)(base + 0x604) & 1) {
        func_004caf80(*(void**)(*(u8**)(base + 0x600) + 4));
        func_00474630(*(void**)(base + 0x600));
    }
}



/* BPC panel subtask state at DAT_007CE324 / GP -0x49CC. */
/* BPC command subtask state at DAT_007CE328 / GP -0x49C8. */


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











// FUN_002496E0
#pragma opt_loop_invariants on
void func_002496e0(void* work)
{
    struct Buffer {
        u8* data;
        s32 stride;
    };
    struct Vec2 {
        f32 x;
        f32 y;
    };
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    struct Local {
        f32 uv[4];
        struct Vec3 world;
        u8 pad0[4];
        struct Vec3 origin;
        u8 pad1[4];
        struct Vec2 dimensions;
        struct Buffer positions;
        struct Buffer colors;
        u8 pad2[4];
        u8 white[4];
    };
    u8* base;
    u8* node;
    u8* camera;
    void** texture;
    void* matrix;
    f32* position;
    u8* color;
    s32 j;
    s32 i;
    struct Local local;

    base = (u8*)work;
    camera = (u8*)func_00198590();
    *(u32*)(base + 0x600) = (u32)func_00474210(0x80, 0x20080003, NULL);
    func_00492d10(*(void**)(base + 0x600), func_004caf10());

    texture = func_003210a0(1);
    local.uv[0] = 1.0f / (f32)*(s32*)((u8*)*texture + 0xc);
    local.uv[1] = 1.0f / (f32)*(s32*)((u8*)*texture + 0x10);
    local.uv[2] = ((f32)*(s32*)((u8*)*texture + 0xc) - 1.0f) /
                  (f32)*(s32*)((u8*)*texture + 0xc);
    local.uv[3] = ((f32)*(s32*)((u8*)*texture + 0x10) - 1.0f) /
                  (f32)*(s32*)((u8*)*texture + 0x10);

    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    func_00521250(node + 0xe0, local.uv, sizeof(local.uv));
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    *(u32*)(node + 0x40) |= 0x80000;
    local.dimensions.x = 20.0f;
    local.dimensions.y = 20.0f;
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    *(struct Vec2 *)(node + 0xc0) = local.dimensions;
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    *(u32*)(node + 0x40) |= 0x4000;
    func_00494d50(
        **(void***)((u8*)*(void**)(*(u8**)(base + 0x600) + 0x18) + 0x20), texture);

    local.white[0] = 0xff;
    local.white[1] = 0xff;
    local.white[2] = 0xff;
    local.white[3] = 0xff;
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    func_00521250(node + 0xd0, local.white, 0x10);
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    *(u32*)(node + 0x40) |= 0x40000;
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    func_005225a8((const void*)(D_0068E880 + 0x30), *(void**)node);
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    *(u32*)(node + 0x40) |= 0x800000;
    *(u32*)(*(u8**)(*(u8**)(base + 0x600) + DAT_007ce770) + 4) = 0x80;
    *(u32*)(*(u8**)(*(u8**)(base + 0x600) + DAT_007ce770) + 0xb4) = 1;
    *(u32*)(*(u8**)(*(u8**)(base + 0x600) + DAT_007ce770) + 0xac) = 3;
    *(u32*)(*(u8**)(*(u8**)(base + 0x600) + DAT_007ce770) + 0xb0) = 9;
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    *(u32*)(node + 0x40) |= 0x10000000;
    func_00474640(*(void**)(base + 0x600), (void**)&local.colors.data, 2, 0x40000000);
    func_00474640(*(void**)(base + 0x600), (void**)&local.positions.data, 1, 0x40000000);
    color = local.colors.data;
    for (j = 0; j < 0x80; j++) {
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = 0x80;
        color += local.colors.stride;
    }

    position = (f32*)local.positions.data;
    for (i = 0; i < 0x80; i++) {
        u32 random;
        f32 ratio;
        f32 value;
        f32* saved;

        random = func_00488f30() & 0xfff;
        ratio = (f32)random / (f32)0xfff;
        value = ratio;
        value *= 300.0f;
        value -= 150.0f;
        saved = (f32*)(base + i * 0xc);
        saved[0] = value;
        position[0] = value;
        random = func_00488f30() & 0xfff;
        ratio = (f32)random / (f32)0xfff;
        value = ratio;
        value *= 300.0f;
        value -= 150.0f;
        saved[1] = value;
        position[1] = value;
        random = func_00488f30() & 0xfff;
        ratio = (f32)random / (f32)0xfff;
        value = ratio;
        value *= 300.0f;
        value -= 150.0f;
        saved[2] = value;
        position[2] = value;
        position = (f32*)((u8*)position + local.positions.stride);
    }

    func_004747f0(*(void**)(base + 0x600));
    matrix = func_004cb2f0(*(void**)(camera + 4));
    local.origin.z = 100.0f;
    local.origin.x = 0.0f;
    local.origin.y = 0.0f;
    func_004c6be0(&local.world, &local.origin, matrix);
    *(struct Vec3 *)(base + 0x608) = local.world;
    *(u32*)(base + 0x604) |= 1;
}

#pragma opt_loop_invariants off

/* W418 width negative: func_00249C10 i s16 nd68/1384B -> 653/1408B (over 1392B). */
// FUN_00249C10 NONMATCHING
void func_00249c10(void* work)
{
    struct Buffer {
        u8* data;
        s32 stride;
    };
    union Vec3 {
        f32 data[3];
    };
    struct Local {
        struct Buffer colors;
        struct Buffer positions;
        union Vec3 transformed;
        u8 pad0[4];
        f32 origin[3];
        u8 pad1[4];
        f32 point[3];
    };
    u8* base;
    u8* camera;
    union Pointer {
        void* cameraMatrix;
        f32* position;
    };
    void* frame;
    void* matrix;
    u8* color;
    union Pointer pointer;
    f32 deltaX;
    f32 deltaY;
    f32 deltaZ;
    f32 alpha;
    f32 distance;
    s32 i;
    struct Local local;

    base = (u8*)work;
    camera = (u8*)func_00198590();
    if ((~*(u32*)(base + 0x604) & 1u) != 0) {
        return;
    }
    pointer.cameraMatrix = func_004cb2f0(*(void**)(camera + 4));
    frame = *(void**)(*(u8**)(base + 0x600) + 4);
    matrix = func_004c38c0();
    func_004c32a0(matrix, pointer.cameraMatrix);

    local.origin[2] = 100.0f;
    local.origin[0] = 0.0f;
    local.origin[1] = 0.0f;
    RwV3dTransformPoint(local.transformed.data, local.origin, pointer.cameraMatrix);

    deltaX = local.transformed.data[0] - *(f32*)(base + 0x608);
    deltaY = local.transformed.data[1] - *(f32*)(base + 0x60c);
    deltaZ = local.transformed.data[2] - *(f32*)(base + 0x610);
    func_004cb750(frame, local.transformed.data, 0);
    func_00474640(*(void**)(base + 0x600), (void**)&local.positions.data, 2, 0x40000000);
    func_00474640(*(void**)(base + 0x600), (void**)&local.colors.data, 1, 0x40000000);

    {

        color = local.colors.data;
        pointer.position = (f32*)local.positions.data;
        for (i = 0; i < 0x80; i++) {
            f32* particle;
            f32* particleY;
            f32* particleZ;

            particle = (f32*)(base + i * 0xc);
            particle[0] -= deltaX;
            particleY = (f32*)((u8*)particle + 4);
            particleY[0] -= deltaY;
            particleZ = (f32*)((u8*)particle + 8);
            particleZ[0] -= deltaZ;
            if (particle[0] < -150.0f) {
                particle[0] += 300.0f;
            } else if (particle[0] > 150.0f) {
                particle[0] -= 300.0f;
            }
            if (particleY[0] < -150.0f) {
                particleY[0] += 300.0f;
            } else if (particleY[0] > 150.0f) {
                particleY[0] -= 300.0f;
            }
            if (particleZ[0] < -150.0f) {
                particleZ[0] += 300.0f;
            } else if (particleZ[0] > 150.0f) {
                particleZ[0] -= 300.0f;
            }
            pointer.position[0] = local.transformed.data[0] + *(f32*)(base + i * 0xc);
            pointer.position[1] = local.transformed.data[1] + particleY[0];
            pointer.position[2] = local.transformed.data[2] + *(f32*)(base + i * 0xc + 8);
            RwV3dTransformPoint(local.point, pointer.position, matrix);

            if (local.point[2] < 100.0f) {
                if (local.point[2] < 40.0f) {
                    alpha = 0.0f;
                } else if (local.point[2] < 100.0f) {
                    alpha = (local.point[2] - 40.0f) / 60.0f;
                } else if (local.point[2] < 170.0f) {
                    alpha = 1.0f;
                } else if (local.point[2] < 230.0f) {
                    alpha = 1.0f - (local.point[2] - 170.0f) / 60.0f;
                } else {
                    alpha = 0.0f;
                }
            } else {
                distance = local.point[2] - 100.0f;
                distance = local.point[1] * local.point[1] +
                           local.point[0] * local.point[0] +
                           distance * distance;
                alpha = 0.0f;
                distance = sqrtf(distance);
                if (distance < 100.0f) {
                    alpha = 1.0f;
                } else if (distance < 150.0f) {
                    alpha = 1.0f - (distance - 100.0f) / 50.0f;
                }
            }

            color[0] = *(u8*)(base + 0x614);
            color[1] = *(u8*)(base + 0x615);
            color[2] = *(u8*)(base + 0x616);
            color[3] = (u8)((f32)*(u8*)(base + 0x617) * alpha);
            color += local.colors.stride;
            pointer.position = (f32*)((u8*)pointer.position + local.positions.stride);
        }
    }

    *(union Vec3 *)(base + 0x608) = local.transformed;
    func_004747f0(*(void**)(base + 0x600));
    func_004c3880(matrix);
}
#pragma opt_loop_invariants reset



/* The Ground task owns this 0x8780-byte Social work area. */
/* 0x0023D7A0 onward is Panel: it switches to DAT_007CE318 and sfl_panel.c asserts. */











// FUN_0024A180
void func_0024a180(u32* work)
{
    u32* owner;

    if ((~GROUND_U32(work, 0x604) & 1) != 0) {
        return;
    }

    {
        const u32* const state = &D_00960090[0];

        ((SflGroundRenderStateCallback)(void*)state[0])(9, 2);
        ((SflGroundRenderStateCallback)(void*)state[0])(0x14, 2);
        ((SflGroundRenderStateCallback)(void*)state[0])(6, 0);
        ((SflGroundRenderStateCallback)(void*)state[0])(8, 0);
        owner = *(u32**)GROUND_PTR(work, 0x600);
        ((SflGroundTickCallback)(void*)GROUND_U32(owner, 0x48))(owner);
    }
}
// FUN_0024A230
void func_0024a230(void* work, const volatile /* Removing this qualifier loses func_0024a230 (MATCH nd0 -> MISMATCH nd8, size 40 -> 40) - measured W170. */ SflGroundColor* color)
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






/* Removing this loses FUN_0023c3a0 (MATCH nd0 -> MISMATCH nd34) - measured W161. */


/* Removing this loses func_0023c8c0 (MATCH nd0 -> MISMATCH nd228), newly over-window 336/336 -> 352/336 - measured W161. */








/* Removing this loses FUN_0023d650 (MATCH nd0 -> MISMATCH nd60) - measured W161. */
