#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Utils.h"
 
static u32* sBpeWork; // puGpffffb638

 
void FUN_003c77a0();

// FUN_00249240
void bpe00249240(u32* param_1)
{
    *param_1 = 0;
    sBpeWork = param_1;
}

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

// FUN_00249600
u32 bpe00249600(void)
{
    K_ASSERT(sBpeWork != NULL, 0x37);
    return *sBpeWork & 1;
}

extern u32 datGetFlag(s32 flag);
extern void* func_00198590(void);
extern void* kwlnGetMainCamera(void);
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


// FUN_00249650
u32 func_00249650(u32 flag)
{
    return !datGetFlag((s32)(flag & 0xffffu) + 0x12c0);
}

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

// FUN_002496E0 NONMATCHING
/* Removing this worsens FUN_002496e0 (nd110 -> nd136) - measured W161. */
#pragma opt_loop_invariants on
void func_002496e0(void* work)
{
    struct Buffer {
        u8* data;
        s32 stride;
    };
    struct Local {
        f32 uv[4];
        f32 world[3];
        u8 pad0[4];
        f32 origin[3];
        u8 pad1[4];
        f32 dimensions[2];
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
    f32 worldX;
    f32 worldY;
    f32 worldZ;

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
    local.dimensions[0] = 20.0f;
    local.dimensions[1] = 20.0f;
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    *(f32*)(node + 0xc0) = local.dimensions[0];
    *(f32*)(node + 0xc4) = local.dimensions[1];
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
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    *(u32*)(node + 4) = 0x80;
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    *(u32*)(node + 0xb4) = 1;
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    *(u32*)(node + 0xac) = 3;
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    *(u32*)(node + 0xb0) = 9;
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
    local.origin[0] = 0.0f;
    local.origin[1] = 0.0f;
    local.origin[2] = 100.0f;
    func_004c6be0(local.world, local.origin, matrix);
    worldZ = local.world[2];
    worldX = local.world[0];
    worldY = local.world[1];
    *(f32*)(base + 0x608) = worldX;
    *(f32*)(base + 0x60c) = worldY;
    *(f32*)(base + 0x610) = worldZ;
    *(u32*)(base + 0x604) |= 1;
}
#pragma opt_loop_invariants off

// FUN_00249C10 NONMATCHING
void func_00249c10(void* work)
{
    struct Buffer {
        u8* data;
        s32 stride;
    };
    struct Local {
        struct Buffer colors;
        struct Buffer positions;
        f32 transformed[3];
        u8 pad0[4];
        f32 origin[3];
        u8 pad1[4];
        f32 point[3];
    };
    u8* base;
    u8* camera;
    u8* frame;
    u8* cameraMatrix;
    u8* matrix;
    struct Local local;
    f32 deltaX;
    f32 deltaY;
    f32 deltaZ;
    f32 alpha;
    f32 distance;
    s32 i;

    base = (u8*)work;
    camera = (u8*)func_00198590();
    if ((~*(u32*)(base + 0x604) & 1u) != 0) {
        return;
    }
    cameraMatrix = (u8*)func_004cb2f0(*(u8**)(camera + 4));
    frame = *(u8**)(*(u8**)(base + 0x600) + 4);
    matrix = (u8*)func_004c38c0();
    func_004c32a0(matrix, cameraMatrix);

    local.origin[0] = 0.0f;
    local.origin[1] = 0.0f;
    local.origin[2] = 100.0f;
    RwV3dTransformPoint(local.transformed, local.origin, cameraMatrix);

    deltaX = local.transformed[0] - *(f32*)(base + 0x608);
    deltaY = local.transformed[1] - *(f32*)(base + 0x60c);
    deltaZ = local.transformed[2] - *(f32*)(base + 0x610);
    func_004cb750(frame, local.transformed, 0);
    func_00474640(*(void**)(base + 0x600), (void**)&local.positions.data, 2, 0x40000000);
    func_00474640(*(void**)(base + 0x600), (void**)&local.colors.data, 1, 0x40000000);

    {
        u8* color;
        f32* position;

        color = local.colors.data;
        position = (f32*)local.positions.data;
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
            position[0] = local.transformed[0] + *(f32*)(base + i * 0xc);
            position[1] = local.transformed[1] + *(f32*)(base + i * 0xc + 4);
            position[2] = local.transformed[2] + *(f32*)(base + i * 0xc + 8);
            RwV3dTransformPoint(local.point, position, matrix);

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
            position = (f32*)((u8*)position + local.positions.stride);
        }
    }

    *(f32*)(base + 0x608) = local.transformed[0];
    *(f32*)(base + 0x60c) = local.transformed[1];
    *(f32*)(base + 0x610) = local.transformed[2];
    func_004747f0(*(void**)(base + 0x600));
    func_004c3880(matrix);
}
