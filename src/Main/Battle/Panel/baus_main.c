#include "Utils.h"
#include "Kosaka/k_assert.h"

typedef struct PanelVec3 {
    f32 x;
    f32 y;
    f32 z;
} PanelVec3;

typedef struct PanelQuaternion {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} PanelQuaternion;

typedef struct PanelVideoMode {
    s32 width;
    s32 height;
    s32 depth;
    u32 flags;
    s32 refreshRate;
    s32 format;
} PanelVideoMode;

typedef struct PanelMatrix {
    PanelVec3 right;
    u32 flags;
    PanelVec3 up;
    u32 pad1;
    PanelVec3 at;
    u32 pad2;
    PanelVec3 pos;
    u32 pad3;
} PanelMatrix;

typedef struct PanelTransform {
    u8 unknown00[0x10];
    PanelQuaternion rotation;
    PanelVec3 translation;
    PanelVec3 scale;
    void* model;
} PanelTransform;
extern void func_0020ca90(PanelMatrix* output, const PanelTransform* transform);

extern u32 datGetScenarioMode(void);
extern u32 func_0021c3f0(s32 texture);
extern void* func_0021cca0(u32 texture, s32 frame);
extern u32 func_0021cce0(u32 frame);
extern void func_0021d3b0(void* destination, void* frame);
extern void func_0021d8e0(void* destination, const void* layout);
extern void func_0021d950(void* destination, const void* color);
extern void func_004cde90(void* resource);
extern void* kwlnGetMainCamera(void);
extern void* func_004ca5b0(void);
extern void func_004ca560(void* viewport, void* cameraData);
extern void func_004c3760(void* matrix, void* source, s32 mode);
extern void func_004c6c60(PanelVec3* destination, const PanelVec3* source,
                          const PanelMatrix* matrix);

extern PanelVec3 D_0068E0C8;
#pragma alias D_0068E0C8_abs D_0068E0C8
extern u8 D_0068E0C8_abs[];
extern PanelVec3 D_0068E0D8;
#pragma alias D_0068E0D8_abs D_0068E0D8
extern u8 D_0068E0D8_abs[];
extern PanelVec3 D_0068E0E8;
#pragma alias D_0068E0E8_abs D_0068E0E8
extern u8 D_0068E0E8_abs[];
extern PanelVec3 D_0068E0F8;
#pragma alias D_0068E0F8_abs D_0068E0F8
extern u8 D_0068E0F8_abs[];

extern void* func_004c38c0(void);
extern void func_004c3880(void* matrix);
extern void* func_004cb2f0(void* model);
extern void RwMatrixScale(void* matrix, const void* scale, s32 combine);
extern void RwMatrixTranslate(void* matrix, const void* translation, s32 combine);
extern void RwMatrixRotate(void* matrix, const void* axis, f32 angle, s32 combine);
extern void RwV3dTransformPoint(void* out, const void* in, const void* matrix);
extern void FUN_004c6be0(void* out, const void* in, const void* matrix);
extern void RwV3dNormalize(void* out, const void* in);
extern void RpSkyRenderStateSet(s32 state, void* value);
extern void RwRenderStateSet(s32 state, void* value);
extern void printf(const char*, ...);
extern int sprintf(char*, const char*, ...);
extern u32 strlen(const char*);

extern char D_006850C0[];
extern char D_006871C0[];
extern char D_006892C0[];
extern char D_0068AB80[];
extern char D_0068C440[];
extern char D_0068C760[];
extern char D_0068CA80[];
extern char D_0068CDE0[];
extern char D_0068D140[];
extern char D_0068D8F0[];
extern char D_0068D910[];
extern char D_0068D930[];
extern char D_0068DE20[];
extern char D_0068DF20[];
extern char D_0068DF30[];
extern char D_0068DF60[];
extern char D_0068E020[];
extern char D_0068DD20[];
extern u16 D_00875A90[];
extern char D_0068E0B0[];
extern void func_00209ba0(void* destination, s32 digit);
extern void func_0020c7b0(u8* work);
extern void func_0020cda0(u8* work);
extern void* memcpy(void* destination, const void* source, u32 size);
extern void func_004f1ed0(void* vertices, u32 count, void* matrix, u32 stride);
extern void func_004f1fd0(u32 primitive, void* indices, u32 count);
extern void func_004f1f80(void);
extern void (*D_00960090)(u32 state, u32 value);
extern void func_0020ccc0(void* work, const u8* color);
extern char D_0068E0A0[];
extern u8 D_0068E090[];
extern void func_0020d500(s32* work, void* matrix);
extern u32 func_0021a3a0(void);
extern u32 func_0021a410(void);
extern u32 func_0021a480(s32 a, s32 b);
extern u32 func_0021a590(u16 value);
extern u32 func_0021b3a0(s32 value);
extern u32 func_0021b420(s32 value);

extern void* D_0068E108;
extern f32 D_0068E110;
extern f32 fGpffff8318;
extern f32 fGpffff8320;
extern f32 fGpffff8324;
extern f32 fGpffff831c;
extern f32 fGpffff8338;
extern f32 fGpffff8334;

// FUN_00209940
void func_00209940(void* destination, s32 capacity, s32 value)
{
    char digits[256];
    s32 length;
    s32 i;

    sprintf(digits, "%d", value);
    length = strlen(digits);
    K_ASSERT(capacity >= length, 0x1c8);
    for (i = 0; i < length; i++) {
        func_00209ba0((u8*)destination + (i << 8), digits[length - 1 - i] - 0x30);
    }
}

// FUN_00209a00
void func_00209a00(void* destination, s32 capacity, s32 value, const f32* origin, f32 scale)
{
    f32 layout[4];
    char digits[256];
    void* texture;
    void* frame;
    s32 i;
    s32 length;

    texture = (void*)func_0021c3f0(1);
    sprintf(digits, "%d", value);
    length = strlen(digits);
    K_ASSERT(capacity >= length, 0x1de);
    for (i = 0; i < length; i++) {
        frame = func_0021cca0((u32)texture, value + 0x2e);
        layout[0] = origin[0] + (f32)((length - 1 - i) * 15);
        layout[1] = origin[1];
        layout[2] = (f32)*(s32*)((u8*)frame + 0xc) * scale;
        layout[3] = (f32)*(s32*)((u8*)frame + 0x10) * scale;
        func_0021d8e0((u8*)destination + (i << 8), layout);
    }
    for (; length < capacity; length++) {
        layout[0] = origin[0];
        layout[1] = origin[1];
        layout[2] = 0.0f;
        layout[3] = 0.0f;
        func_0021d8e0((u8*)destination + (length << 8), layout);
    }
}

// FUN_00209ba0
void func_00209ba0(void* destination, s32 digit)
{
    u32 texture;
    u32 frame;

    texture = func_0021c3f0(1);
    frame = (u32)func_0021cca0(texture, digit + 0x2e);
    func_0021d3b0(destination, (void*)frame);
}

// FUN_00209c00
u32 func_00209c00(void)
{
    return func_0021cce0((u32)func_0021cca0(func_0021c3f0(1), 0x2e));
}

// FUN_00209c40
char* func_00209c40(void)
{
    return datGetScenarioMode() ? D_006871C0 : D_006850C0;
}

// FUN_00209c80
char* func_00209c80(void)
{
    return datGetScenarioMode() ? D_0068AB80 : D_006892C0;
}

// FUN_00209cc0
char* func_00209cc0(void)
{
    return datGetScenarioMode() ? D_0068C760 : D_0068C440;
}

// FUN_00209d00
char* func_00209d00(void)
{
    return datGetScenarioMode() ? D_0068CDE0 : D_0068CA80;
}











static void panel_init_common(u8* work, u32 state)
{
    s32 i;

    func_00209ea0(work);
    *(u32*)(work + 4) = state;
    func_0020c7b0(work + 0xe0);
    for (i = 0; i < 4; i++) {
        work[0x184 + i] = 0xff;
        work[0x1a8 + i] = 0xff;
        work[0x1cc + i] = 0xff;
        work[0x1f0 + i] = 0xff;
    }
}





extern f32 DAT_007cadd4;
extern f32 DAT_007cad7c;
extern f32 DAT_007cad74;
extern f32 DAT_007caee8;
extern f32 FUN_0052e878(f32 angle);
extern f32 FUN_0052e6d8(f32 angle);
extern void func_0020cf20(void* destination, PanelTransform* transform);

// Reconstructed state interpolation, UV projection, and corner rotation from retail control flow.
// Remaining excess is retained pending MWCCPS2 register-allocation and scheduling convergence.















/* Removing this worsens FUN_0020cda0 (nd12 -> nd259) and 1 more - measured W161. */
