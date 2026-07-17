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
extern void func_00474630(void* resource);
extern void func_00474640(void* resource, void** buffer, s32 type, u32 flags);
extern void func_00492d10(void* resource, void* model);
extern void func_004747f0(void* resource);
extern u32 func_00488f30(void);
extern void func_00494d50(void* material, void* texture);
extern void* func_004cb2f0(void* model);
extern void func_004c6be0(void* destination, const void* source, void* matrix);
extern void func_005225a8(const void* name, void* object);
extern s32 DAT_007ce770;
extern void* func_004c38c0(void);
extern void func_004c32a0(void* destination, const void* source);
extern void func_004cb750(void* frame, const void* translation, s32 mode);
extern f32 sqrtf(f32 value);
extern void func_004c3880(void* matrix);
extern void func_004c3760(void* matrix, void* source, s32 mode);
extern void RwMatrixScale(void* matrix, const void* scale, s32 combine);
extern void RwMatrixTranslate(void* matrix, const void* translation, s32 combine);
extern void RwV3dTransformPoint(void* out, const void* in, const void* matrix);
extern void* memcpy(void* destination, const void* source, u32 size);

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
void func_002496e0(void* work)
{
    struct Buffer {
        u8* data;
        s32 stride;
    };
    u8* base;
    u8* node;
    u8* camera;
    void** texture;
    void* matrix;
    u8* color;
    f32* position;
    struct Buffer colors;
    struct Buffer positions;
    f32 uv[4];
    f32 origin[3];
    f32 world[3];
    u8 white[4];
    s32 i;

    base = (u8*)work;
    camera = (u8*)func_00198590();
    *(void**)(base + 0x600) = func_00474210(0x80, 0x20080003, NULL);
    func_00492d10(*(void**)(base + 0x600), func_004caf10());

    texture = func_003210a0(1);
    uv[0] = 1.0f / (f32)*(s32*)((u8*)*texture + 0xc);
    uv[1] = 1.0f / (f32)*(s32*)((u8*)*texture + 0x10);
    uv[2] = ((f32)*(s32*)((u8*)*texture + 0xc) - 1.0f) /
            (f32)*(s32*)((u8*)*texture + 0xc);
    uv[3] = ((f32)*(s32*)((u8*)*texture + 0x10) - 1.0f) /
            (f32)*(s32*)((u8*)*texture + 0x10);

    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    memcpy(node + 0xe0, uv, sizeof(uv));
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    *(u32*)(node + 0x40) |= 0x80000;
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    *(f32*)(node + 0xc0) = 20.0f;
    *(f32*)(node + 0xc4) = 20.0f;
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    *(u32*)(node + 0x40) |= 0x4000;
    func_00494d50(
        **(void***)((u8*)*(void**)(*(u8**)(base + 0x600) + 0x18) + 0x20), texture);

    white[0] = 0xff;
    white[1] = 0xff;
    white[2] = 0xff;
    white[3] = 0xff;
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    memcpy(node + 0xd0, white, 0x10);
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    *(u32*)(node + 0x40) |= 0x40000;
    node = *(u8**)(*(u8**)(base + 0x600) + DAT_007ce770);
    func_005225a8((const void*)0x0068e8b0, *(void**)node);
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

    func_00474640(*(void**)(base + 0x600), (void**)&colors.data, 2, 0x40000000);
    func_00474640(*(void**)(base + 0x600), (void**)&positions.data, 1, 0x40000000);
    color = colors.data;
    for (i = 0; i < 0x80; i++) {
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = 0x80;
        color += colors.stride;
    }

    position = (f32*)positions.data;
    for (i = 0; i < 0x80; i++) {
        u32 random;
        f32 value;
        f32* saved = (f32*)(base + i * 0xc);

        random = func_00488f30() & 0xfff;
        value = ((f32)random / (f32)0xfff) * 300.0f - 150.0f;
        saved[0] = value;
        position[0] = value;
        random = func_00488f30() & 0xfff;
        value = ((f32)random / (f32)0xfff) * 300.0f - 150.0f;
        saved[1] = value;
        position[1] = value;
        random = func_00488f30() & 0xfff;
        value = ((f32)random / (f32)0xfff) * 300.0f - 150.0f;
        saved[2] = value;
        position[2] = value;
        position = (f32*)((u8*)position + positions.stride);
    }

    func_004747f0(*(void**)(base + 0x600));
    matrix = func_004cb2f0(*(void**)(camera + 4));
    origin[0] = 0.0f;
    origin[1] = 0.0f;
    origin[2] = 100.0f;
    func_004c6be0(world, origin, matrix);
    *(f32*)(base + 0x608) = world[0];
    *(f32*)(base + 0x60c) = world[1];
    *(f32*)(base + 0x610) = world[2];
    *(u32*)(base + 0x604) |= 1;
}

// FUN_00249C10 NONMATCHING
void func_00249c10(void* work)
{
    struct Buffer {
        u8* data;
        s32 stride;
    };
    u8* base;
    u8* camera;
    u8* resource;
    void* cameraMatrix;
    void* frame;
    void* matrix;
    struct Buffer colors;
    struct Buffer positions;
    f32 translated[3];
    f32 origin[3];
    f32 deltaX;
    f32 deltaY;
    f32 deltaZ;

    base = (u8*)work;
    camera = (u8*)func_00198590();
    if (camera == NULL || (*(u32*)(base + 0x604) & 1u) == 0) {
        return;
    }

    cameraMatrix = func_004cb2f0(*(void**)(camera + 4));
    resource = *(u8**)(base + 0x600);
    frame = *(void**)(resource + 4);
    matrix = func_004c38c0();
    func_004c32a0(matrix, cameraMatrix);
    origin[0] = 0.0f;
    origin[1] = 0.0f;
    origin[2] = 100.0f;
    RwV3dTransformPoint(translated, origin, cameraMatrix);
    deltaX = translated[0] - *(f32*)(base + 0x608);
    deltaY = translated[1] - *(f32*)(base + 0x60c);
    deltaZ = translated[2] - *(f32*)(base + 0x610);
    func_004cb750(frame, translated, 0);
    func_00474640(resource, (void**)&colors.data, 2, 0x40000000);
    func_00474640(resource, (void**)&positions.data, 1, 0x40000000);
    *(f32*)(base + 0x608) = translated[0];
    *(f32*)(base + 0x60c) = translated[1];
    *(f32*)(base + 0x610) = translated[2];
    func_004747f0(resource);
    func_004c3880(matrix);
    (void)deltaX;
    (void)deltaY;
    (void)deltaZ;
}
