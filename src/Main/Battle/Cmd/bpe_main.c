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
extern void* kwlnGetMainCamera(void);
extern void* func_00474210(u32 flags, u32 mode, void* parent);
extern void* func_004caf10(void);
extern void func_004caf80(void* resource);
extern void func_00474630(void* resource);
extern void func_00492d10(void* resource, void* model);
extern void func_004747f0(void* resource);
extern void func_004cb2f0(void* model);
extern void* func_004c38c0(void);
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

// FUN_00249680 NONMATCHING
void func_00249680(void* work)
{
    K_ASSERT(work != NULL, 0x37);
    *(u32*)((u8*)work + 0x604) = 0;
}

// FUN_00249690 NONMATCHING
void FUN_00249690(void* work)
{
    u8* base;
    void* resource;

    K_ASSERT(work != NULL, 0x37);
    base = (u8*)work;
    if ((*(u32*)(base + 0x604) & 1u) != 0) {
        resource = *(void**)(base + 0x600);
        if (resource != NULL) {
            func_004caf80(resource);
            func_00474630(resource);
        }
    }
    *(u32*)(base + 0x600) = 0;
    *(u32*)(base + 0x604) = 0;
}

// FUN_002496E0 NONMATCHING
void func_002496e0(void* work)
{
    u8* base;
    void* resource;
    void* model;
    s32 i;
    f32 setup[4];
    f32 scale[3];
    void* camera;

    K_ASSERT(work != NULL, 0x37);
    base = (u8*)work;
    camera = kwlnGetMainCamera();
    resource = func_00474210(0x80, 0x20080003, NULL);
    *(void**)(base + 0x600) = resource;
    *(u32*)(base + 0x604) = 0;
    if (resource == NULL) {
        return;
    }
    model = func_004caf10();
    func_00492d10(resource, model);
    if (model != NULL) {
        func_004cb2f0(model);
    }
    setup[0] = 1.0f;
    setup[1] = 1.0f;
    setup[2] = 0.0f;
    setup[3] = 0.0f;
    scale[0] = scale[1] = scale[2] = 1.0f;
    if (camera != NULL) {
        f32 cameraScale = 1.0f / (*(f32*)((u8*)camera + 0x80));
        setup[0] = cameraScale;
        setup[1] = cameraScale;
    }
    memcpy(base + 0x60, setup, sizeof(setup));
    for (i = 0; i < 0x80; i++) {
        u8* item = base + 0x700 + i * 0x18;
        *(f32*)(item + 0) = 0.0f;
        *(f32*)(item + 4) = 0.0f;
        *(f32*)(item + 8) = 0.0f;
        *(u32*)(item + 0xc) = 0xff808080u;
        *(u32*)(item + 0x10) = 0;
        *(u32*)(item + 0x14) = 0;
    }
    *(u32*)(base + 0x604) = 1;
}

// FUN_00249C10 NONMATCHING
void func_00249c10(void* work)
{
    u8* base;
    void* camera;
    void* resource;
    void* matrix;
    f32 translation[3];
    f32 scale[3];

    K_ASSERT(work != NULL, 0x37);
    base = (u8*)work;
    camera = kwlnGetMainCamera();
    if (camera == NULL || (*(u32*)(base + 0x604) & 1u) == 0) {
        return;
    }
    resource = *(void**)(base + 0x600);
    if (resource == NULL) {
        return;
    }
    matrix = func_004c38c0();
    if (matrix == NULL) {
        return;
    }
    func_004c3880(matrix);
    translation[0] = *(f32*)((u8*)camera + 0x20);
    translation[1] = *(f32*)((u8*)camera + 0x24);
    translation[2] = *(f32*)((u8*)camera + 0x28);
    scale[0] = scale[1] = scale[2] = 1.0f;
    RwMatrixScale(matrix, scale, 1);
    RwMatrixTranslate(matrix, translation, 1);
    func_004c3760(matrix, camera, 0);
    func_004747f0(resource);
    RwV3dTransformPoint(base + 0x608, translation, matrix);
}
