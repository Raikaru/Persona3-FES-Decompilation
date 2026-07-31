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


// FUN_0020b250 NONMATCHING
void func_0020b250(void* work)
{
    u8* panel = (u8*)work;
    u8* mode1;
    void* matrix;
    u8* mode0;
    u8* common;
    u8* mode2;
    u8 color[4];
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
    f32 alpha;
    u32 value;
    s32 mode;
    mode = *(s32*)(panel + 4);
    if (mode < 0 || mode >= 3) {
        K_Assert(D_0068E0A0, 0x2A6);
    }
    mode = *(s32*)(panel + 4);
    switch (mode) {
    case 1:
        mode1 = panel;
        common = panel + 0xE0;
        break;
    case 0:
        mode0 = panel;
        common = panel + 0xE0;
        break;
    case 2:
        mode2 = panel;
        common = panel + 0xE0;
        break;
    }
    matrix = func_004c38c0();
    func_0020ca90(matrix, (const PanelTransform*)panel);
    if (*(u32*)panel & 4) {
        func_0020ccc0(common, panel + 0x40);
        switch (*(s32*)(panel + 4)) {
        case 0:
            func_0020ccc0(mode0 + 0x178, panel + 0x40);
            func_0020ccc0(mode0 + 0x208, panel + 0x40);
            c1 = panel[0x40];
            c3 = panel[0x41];
            c2 = panel[0x42];
            c0 = panel[0x43];
            color[0] = c1;
            color[1] = c3;
            color[2] = c2;
            color[3] = c0;
            value = panel[0x43];
            alpha = (f32)(u32)value;
            alpha = (30.0f * alpha) / 100.0f;
            if (alpha < 2.1474836e9f) {
                color[3] = (u8)(s32)alpha;
            } else {
                color[3] = (u8)(s32)(alpha - 2.1474836e9f);
            }
            func_0020ccc0(mode0 + 0x298, color);
            func_0020ccc0(mode0 + 0x328, color);
            c1 = panel[0x40];
            c3 = panel[0x41];
            c2 = panel[0x42];
            c0 = panel[0x43];
            color[0] = c1;
            color[1] = c3;
            color[2] = c2;
            color[3] = c0;
            alpha = 255.0f * *(f32*)(mode0 + 0x5FC);
            if (alpha < 2.1474836e9f) {
                color[3] = (u8)(s32)alpha;
            } else {
                color[3] = (u8)(s32)(alpha - 2.1474836e9f);
            }
            func_0020ccc0(mode0 + 0x3B8, color);
            if (*(u32*)(mode0 + 0x170) & 1) {
                c1 = panel[0x40];
                c3 = panel[0x41];
                c2 = panel[0x42];
                c0 = panel[0x43];
                color[0] = c1;
                color[1] = c3;
                color[2] = c2;
                color[3] = c0;
                color[0] = 0;
                color[1] = 0;
                color[2] = 0;
                func_0020ccc0(mode0 + 0x448, color);
            } else {
                func_0020ccc0(mode0 + 0x448, panel + 0x40);
            }
            if (*(u32*)(mode0 + 0x170) & 1) {
                color[0] = panel[0x40];
                color[1] = panel[0x41];
                color[2] = panel[0x42];
                color[3] = panel[0x43];
                color[3] = 0;
                func_0020ccc0(mode0 + 0x4D8, color);
            } else {
                color[0] = panel[0x40];
                color[1] = panel[0x41];
                color[2] = panel[0x42];
                color[3] = panel[0x43];
                alpha = 255.0f * *(f32*)(mode0 + 0x5F8);
                if (alpha < 2.1474836e9f) {
                    color[3] = (u8)(s32)alpha;
                } else {
                    color[3] = (u8)(s32)(alpha - 2.1474836e9f);
                }
                func_0020ccc0(mode0 + 0x4D8, color);
            }
            break;
        case 1:
            func_0020ccc0(mode2 + 0x208, panel + 0x40);
            func_0020ccc0(mode2 + 0x178, panel + 0x40);
            value = panel[0x43];
            color[0] = panel[0x40];
            color[1] = panel[0x41];
            color[2] = panel[0x42];
            color[3] = (u8)value;
            color[0] = 0;
            color[1] = 0;
            color[2] = 0;
            alpha = (f32)(u32)value;
            alpha = *(f32*)(mode2 + 0x32C) * (alpha * *(f32*)(mode2 + 0x328));
            if (alpha < 2.1474836e9f) {
                color[3] = (u8)(s32)alpha;
            } else {
                color[3] = (u8)(s32)(alpha - 2.1474836e9f);
            }
            func_0020ccc0(mode2 + 0x298, color);
            break;
        case 2:
            func_0020ccc0(mode1 + 0x170, panel + 0x40);
            break;
        }
        *(u32*)panel &= ~4;
    }
    if (*(s32*)(panel + 4) == 0) {
        color[0] = panel[0x40];
        color[1] = panel[0x41];
        color[2] = panel[0x42];
        color[3] = panel[0x43];
        value = panel[0x43];
        alpha = (f32)(u32)value;
        alpha = (255.0f * *(f32*)(mode0 + 0x5FC) * alpha) / 255.0f;
        if (alpha < 2.1474836e9f) {
            color[3] = (u8)(s32)alpha;
        } else {
            color[3] = (u8)(s32)(alpha - 2.1474836e9f);
        }
        func_0020ccc0(mode0 + 0x3B8, color);
        color[0] = panel[0x40];
        color[1] = panel[0x41];
        color[2] = panel[0x42];
        color[3] = panel[0x43];
        if (*(u32*)(mode0 + 0x170) & 1) {
            color[3] = 0;
        } else {
            value = panel[0x43];
            alpha = (f32)(u32)value;
            alpha = (255.0f * *(f32*)(mode0 + 0x5F8) * alpha) / 255.0f;
            if (alpha < 2.1474836e9f) {
                color[3] = (u8)(s32)alpha;
            } else {
                color[3] = (u8)(s32)(alpha - 2.1474836e9f);
            }
        }
        func_0020ccc0(mode0 + 0x4D8, color);
    }
    D_00960090(9U, 2U);
    D_00960090(0x14U, 2U);
    D_00960090(6U, 0U);
    switch (*(s32*)(panel + 4)) {
    case 1:
        D_00960090(8U, 0U);
        RpSkyRenderStateSet(3, (void*)0x317F3);
        D_00960090(1U, func_0021a480(*(s32*)(panel + 0x170), *(s32*)(panel + 0x174)));
        RpSkyRenderStateSet(2, (void*)0x44);
        func_004f1ed0(panel + 0x178, 4U, matrix, 3U);
        func_004f1fd0(3U, D_0068E090, 6U);
        func_004f1f80();
        break;
    case 0:
        mode0 = panel;
        D_00960090(8U, 0U);
        RpSkyRenderStateSet(3, (void*)0x317F3);
        D_00960090(3U, 1U);
        D_00960090(4U, 1U);
        D_00960090(1U, func_0021b3a0(0));
        RpSkyRenderStateSet(2, (void*)0x44);
        func_004f1ed0(panel + 0x178, 4U, matrix, 3U);
        func_004f1fd0(3U, D_0068E090, 6U);
        func_004f1f80();
        RpSkyRenderStateSet(2, (void*)0x48);
        D_00960090(1U, func_0021b3a0(4));
        func_004f1ed0(panel + 0x3B8, 4U, matrix, 3U);
        func_004f1fd0(3U, D_0068E090, 6U);
        func_004f1f80();
        RpSkyRenderStateSet(2, (void*)0x44);
        D_00960090(1U, func_0021a590((u16)*(s32*)(panel + 0x174)));
        func_004f1ed0(panel + 0x448, 4U, matrix, 3U);
        func_004f1fd0(3U, D_0068E090, 6U);
        func_004f1f80();
        RpSkyRenderStateSet(2, (void*)0x48);
        D_00960090(1U, func_0021b3a0(3));
        func_004f1ed0(panel + 0x328, 4U, matrix, 3U);
        func_004f1fd0(3U, D_0068E090, 6U);
        func_004f1f80();
        RpSkyRenderStateSet(2, (void*)0x48);
        D_00960090(1U, func_0021b3a0(2));
        func_004f1ed0(panel + 0x298, 4U, matrix, 3U);
        func_004f1fd0(3U, D_0068E090, 6U);
        func_004f1f80();
        RpSkyRenderStateSet(2, (void*)0x48);
        D_00960090(1U, func_0021a590((u16)*(s32*)(panel + 0x174)));
        func_004f1ed0(panel + 0x4D8, 4U, matrix, 3U);
        func_004f1fd0(3U, D_0068E090, 6U);
        func_004f1f80();
        RpSkyRenderStateSet(2, (void*)0x44);
        D_00960090(1U, func_0021b3a0(1));
        func_004f1ed0(panel + 0x208, 4U, matrix, 3U);
        func_004f1fd0(3U, D_0068E090, 6U);
        func_004f1f80();
        if (*(u32*)panel & 2) {
            RpSkyRenderStateSet(2, (void*)0x48);
            D_00960090(3U, 3U);
            D_00960090(4U, 3U);
            D_00960090(1U, func_0021b3a0(5));
            func_004f1ed0(panel + 0x568, 4U, matrix, 3U);
            func_004f1fd0(3U, D_0068E090, 6U);
            func_004f1f80();
        }
        break;
    case 2:
        D_00960090(8U, 0U);
        RpSkyRenderStateSet(2, (void*)0x44);
        RpSkyRenderStateSet(3, (void*)0x317F3);
        D_00960090(1U, func_0021a410());
        func_004f1ed0(panel + 0x170, 4U, matrix, 3U);
        func_004f1fd0(3U, D_0068E090, 6U);
        func_004f1f80();
        break;
    }
    if (*(u32*)panel & 1) {
        if (*(u32*)(panel + 0x48) == 0) {
            if (*(s32*)(panel + 4) == 1) {
                RpSkyRenderStateSet(2, (void*)0x6A);
                D_00960090(1U, func_0021b3a0(1));
                func_004f1ed0(mode0 + 0x208, 4U, matrix, 3U);
                func_004f1fd0(3U, D_0068E090, 6U);
                func_004f1f80();
            }
            RpSkyRenderStateSet(2, (void*)0x58);
            D_00960090(4U, 3U);
            D_00960090(1U, func_0021b3a0(6));
            func_004f1ed0(panel + 0x4C, 4U, matrix, 3U);
            func_004f1fd0(3U, D_0068E090, 6U);
            func_004f1f80();
            D_00960090(4U, 1U);
        }
    }
    if (*(s32*)(panel + 4) == 1) {
        D_00960090(6U, 0U);
        D_00960090(8U, 0U);
        RpSkyRenderStateSet(3, (void*)0x717FB);
        RpSkyRenderStateSet(2, (void*)0x44);
        D_00960090(1U, func_0021b420(1));
        func_004f1ed0(panel + 0x298, 4U, matrix, 3U);
        func_004f1fd0(3U, D_0068E090, 6U);
        func_004f1f80();
    }
    D_00960090(1U, func_0021a3a0());
    RpSkyRenderStateSet(2, (void*)0x44);
    D_00960090(6U, 0U);
    D_00960090(8U, 0U);
    func_004f1ed0(common, 4U, matrix, 3U);
    func_004f1fd0(3U, D_0068E090, 6U);
    func_004f1f80();
    if (*(u32*)panel & 8) {
        if ((*(u32*)(panel + 0xDC) & 1) == 0) {
            D_00960090(6U, 0U);
            D_00960090(8U, 0U);
            RpSkyRenderStateSet(2, (void*)0x6A);
            switch (*(s32*)(panel + 4)) {
            case 0:
                D_00960090(1U, func_0021b3a0(1));
                func_004f1ed0(panel + 0x208, 4U, matrix, 3U);
                break;
            case 1:
                D_00960090(1U, func_0021b420(0));
                func_004f1ed0(panel + 0x208, 4U, matrix, 3U);
                break;
            case 2:
                RpSkyRenderStateSet(3, (void*)0x71801);
                RpSkyRenderStateSet(2, (void*)0x48);
                break;
            }
            func_004f1fd0(3U, D_0068E090, 6U);
            func_004f1f80();
            RpSkyRenderStateSet(2, (void*)0x58);
        } else {
            RpSkyRenderStateSet(3, (void*)0x71801);
            RpSkyRenderStateSet(2, (void*)0x48);
        }
        func_0020d500((s32*)(panel + 0xDC), matrix);
    }
    func_004c3880(matrix);
}

// FUN_0020c320
void func_0020c320(s32 unused, const f32* source, f32 scale, void* viewport)
{
    s32 size[8];
    f32* camera;
    f32 panelScale = scale;
    f32* out = viewport;

    camera = (f32*)((u8*)kwlnGetMainCamera() + 0x68);
    func_004ca560(size, func_004ca5b0());
    out[0] = panelScale * (camera[0] * (1.0f + (-source[0] / (f32)(size[0] >> 1))));
    out[1] = panelScale * (camera[1] * (1.0f + (-source[1] / (f32)(size[1] >> 1))));
    out[2] = panelScale;
}

// FUN_0020c400
void func_0020c400(s32 unused, const f32* source, f32 scale, void* viewport)
{
    s32 size[8];
    f32* camera;
    f32 panelScale = scale;
    f32* out = viewport;

    camera = (f32*)((u8*)kwlnGetMainCamera() + 0x68);
    func_004ca560(size, func_004ca5b0());
    out[0] = panelScale * (camera[0] * (1.0f + (-(source[0] - 0.5f) / (f32)(size[0] >> 1))));
    out[1] = panelScale * (camera[1] * (1.0f + (-(source[1] - 0.5f) / (f32)(size[1] >> 1))));
    out[2] = panelScale;
}

// FUN_0020c500
f32 func_0020c500(const f32* value, f32 scale)
{
    s32 size[8];
    f32* camera;
    f32 panelScale = scale;

    camera = (f32*)((u8*)kwlnGetMainCamera() + 0x68);
    func_004ca560(size, func_004ca5b0());
    return (6.0f * value[11] * (f32)(size[0] >> 1)) / (panelScale * camera[0]);
}

// FUN_0020c590
void func_0020c590(void* work, s32 value)
{
    K_ASSERT(*(u32*)((u8*)work + 4) == 0, 0x489);
    *(s16*)((u8*)work + 0x174) = (s16)value;
}

// FUN_0020c5f0
void func_0020c5f0(void* work, u32 a, u32 b)
{
    K_ASSERT(*(u32*)((u8*)work + 4) == 1, 0x492);
    *(u32*)((u8*)work + 0x170) = a;
    *(u32*)((u8*)work + 0x174) = b;
}

// FUN_0020c660
f32 func_0020c660(s32 value, s32 mode)
{
    switch (mode) {
    case 2:
        return 220.0f + 200.0f * (f32)value / (f32)(mode - 1);
    case 6:
        return 70.0f + 500.0f * (f32)value / (f32)(mode - 1);
    case 3:
    case 4:
    case 5:
        return (f32)(value + 1) * (640.0f / (f32)(mode + 1));
    default:
        K_ASSERT(0, 0x4ae);
        return 0.0f;
    }
}

// FUN_0020c7a0
void func_0020c7a0(void* work, u32 value)
{
    *(u32*)((u8*)work + 0x38) = value;
}

// FUN_0020c7b0
void func_0020c7b0(u8* work)
{
    struct Vec3
    {
        f32 x;
        f32 y;
        f32 z;
    };
    struct Vec3 topRight;
    struct Vec3 bottomRight;
    struct Vec3 bottomLeft;
    struct Vec3 topLeft;

    topRight.x = 3.0f;
    topRight.y = fGpffff8318;
    topRight.z = 0.0f;
    *(struct Vec3*)(work + 0x00) = topRight;
    bottomRight.x = 3.0f;
    bottomRight.y = fGpffff831c;
    bottomRight.z = 0.0f;
    *(struct Vec3*)(work + 0x24) = bottomRight;
    bottomLeft.x = -3.0f;
    bottomLeft.y = fGpffff831c;
    bottomLeft.z = 0.0f;
    *(struct Vec3*)(work + 0x48) = bottomLeft;
    topLeft.x = -3.0f;
    topLeft.y = fGpffff8318;
    topLeft.z = 0.0f;
    *(struct Vec3*)(work + 0x6c) = topLeft;

    work[0x0c] = 0xff;
    work[0x0d] = 0xff;
    work[0x0e] = 0xff;
    work[0x0f] = 0xff;
    work[0x30] = 0xff;
    work[0x31] = 0xff;
    work[0x32] = 0xff;
    work[0x33] = 0xff;
    work[0x54] = 0xff;
    work[0x55] = 0xff;
    work[0x56] = 0xff;
    work[0x57] = 0xff;
    work[0x78] = 0xff;
    work[0x79] = 0xff;
    work[0x7a] = 0xff;
    work[0x7b] = 0xff;

    *(u32*)(work + 0x1c) = 0x3f7e0000;
    *(u32*)(work + 0x40) = 0x3f7e0000;
    *(u32*)(work + 0x64) = 0;
    *(u32*)(work + 0x88) = 0;
    *(u32*)(work + 0x20) = 0x3c000000;
    *(u32*)(work + 0x44) = 0x3f230000;
    *(u32*)(work + 0x68) = 0x3f230000;
    *(u32*)(work + 0x8c) = 0x3c000000;
}

// FUN_0020c8d0
void func_0020c8d0(void)
{
    u16* indices;
    s32 cursor;
    s32 col;
    s32 row;
    s32 i;
    s32 alternating;
    s32 cursorPlusEight;

    printf(D_0068E0B0);
    cursor = 0;
    indices = (u16*)D_00875A90;
    for (row = 0; row < 8; row++)
    {
        col = 0;
        alternating = ~row & 1;
        while (col < 6)
        {
            if (alternating != 0)
            {
                indices[0] = cursor;
                indices[1] = cursor + 1;
                indices[2] = cursor + 8;
                indices[3] = cursor + 1;
                indices[4] = cursor + 9;
                indices[5] = cursor + 8;
                indices += 6;
                cursor++;
            }
            else
            {
                indices[0] = cursor;
                cursorPlusEight = cursor + 8;
                indices[1] = cursorPlusEight;
                indices[2] = cursor + 7;
                indices[3] = cursor;
                cursor++;
                indices[4] = cursor;
                indices[5] = cursorPlusEight;
                indices += 6;
            }
            col++;
        }
        if (alternating != 0)
        {
            indices[0] = cursor;
            indices[1] = cursor + 1;
            indices[2] = cursor + 8;
            indices += 3;
            cursor += 2;
        }
        else
        {
            indices[0] = cursor;
            indices[1] = cursor + 8;
            indices[2] = cursor + 7;
            indices += 3;
            cursor++;
        }
    }
    for (i = 0; i < 0x138; i++)
    {
        K_ASSERT(D_00875A90[i] < 0x44, 0x515);
    }
    K_ASSERT(indices - (u16*)D_00875A90 == 0x138, 0x517);
}

// FUN_0020ca90
void func_0020ca90(PanelMatrix* output, const PanelTransform* transform)
{
    const PanelVec3* cameraScale;
    PanelMatrix* rotation;
    PanelVec3 scale;
    PanelVideoMode viewport;
    f32 aspectRatio;
    f32 factor;
    f32 scaledX;
    f32 scaledY;
    f32 scaledZ;
    f32 xx;
    f32 yy;
    f32 zz;
    f32 xy;
    f32 xz;
    f32 yz;
    f32 xw;
    f32 yw;
    f32 zw;
    void* camera;
    void* viewportData;

    camera = kwlnGetMainCamera();
    cameraScale = (const PanelVec3*)((u8*)camera + 0x68);
    viewportData = func_004ca5b0();
    func_004ca560(&viewport, viewportData);

    aspectRatio = (f32)viewport.width * cameraScale->y /
                  ((f32)viewport.height * cameraScale->x);
    scale.x = transform->scale.x;
    scale.y = aspectRatio * transform->scale.y;
    scale.z = transform->scale.z;
    RwMatrixScale(output, &scale, 0);

    rotation = (PanelMatrix*)func_004c38c0();
    factor = 2.0f /
             (transform->rotation.x * transform->rotation.x +
              transform->rotation.y * transform->rotation.y +
              transform->rotation.z * transform->rotation.z +
              transform->rotation.w * transform->rotation.w);
    scaledX = transform->rotation.x * factor;
    scaledY = transform->rotation.y * factor;
    scaledZ = transform->rotation.z * factor;
    xw = scaledX * transform->rotation.w;
    yw = scaledY * transform->rotation.w;
    zw = scaledZ * transform->rotation.w;
    xx = transform->rotation.x * scaledX;
    yy = transform->rotation.y * scaledY;
    zz = transform->rotation.z * scaledZ;
    yz = transform->rotation.y * scaledZ;
    xz = transform->rotation.z * scaledX;
    xy = transform->rotation.x * scaledY;

    rotation->right.x = 1.0f - (yy + zz);
    rotation->right.y = xy + zw;
    rotation->right.z = xz - yw;
    rotation->up.x = xy - zw;
    rotation->up.y = 1.0f - (zz + xx);
    rotation->up.z = yz + xw;
    rotation->at.x = xz + yw;
    rotation->at.y = yz - xw;
    rotation->at.z = 1.0f - (xx + yy);
    rotation->pos.x = 0.0f;
    rotation->pos.y = 0.0f;
    rotation->pos.z = 0.0f;
    rotation->flags = 3;

    func_004c3760(output, rotation, 2);
    func_004c3880(rotation);
    RwMatrixTranslate(output, &transform->translation, 2);
    if (transform->model != NULL)
    {
        func_004c3760(output, func_004cb2f0(transform->model), 2);
    }
}

// FUN_0020cc80
void func_0020cc80(void* work, const u8* color)
{
    struct Color {
        u8 red;
        u8 green;
        u8 blue;
        u8 alpha;
    };
    struct Panel {
        u32 flags;
        u8 pad[0x3c];
        struct Color color;
    };
    struct Panel* panel = (struct Panel*)work;
    const struct Color* rgba = (const struct Color*)color;

    panel->color = *rgba;
    panel->flags |= 4;
}

// FUN_0020ccc0
void func_0020ccc0(void* work, const u8* color)
{
    u8* panel = (u8*)work;

    panel[0x0c] = color[0];
    panel[0x0d] = color[1];
    panel[0x0e] = color[2];
    panel[0x0f] = color[3];
    panel[0x30] = color[0];
    panel[0x31] = color[1];
    panel[0x32] = color[2];
    panel[0x33] = color[3];
    panel[0x54] = color[0];
    panel[0x55] = color[1];
    panel[0x56] = color[2];
    panel[0x57] = color[3];
    panel[0x78] = color[0];
    panel[0x79] = color[1];
    panel[0x7a] = color[2];
    panel[0x7b] = color[3];
}

// FUN_0020cd50
void func_0020cd50(void* work, void* resource)
{
    func_0020cda0(resource);
    *(void**)((u8*)work + 0xdc) = resource;
    *(u32*)work |= 8;
}

#pragma push
/* Removing this worsens FUN_0020cda0 (nd12 -> nd259) and 1 more - measured W161. */
#pragma opt_loop_invariants on
// FUN_0020cda0 NONMATCHING
void func_0020cda0(u8* work)
{
    PanelVec3 position;
    f32 rowY;
    f32 x;
    f32 half;
    f32 six;
    f32 three;
    f32 zero;
    f32 rowStep;
    f32 yOffset;
    u8* vertex;
    s32 alternating;
    s32 col;
    s32 row;
    s32 width;
    s32 widthEven;
    s32 widthOdd;
    *(u32*)(work + 0) = 0;
    half = 0.5f;
    *(f32*)(work + 0x9a0) = half;
    *(f32*)(work + 0x9a4) = 0.375f;
    vertex = work + 4;
    row = 0;
    widthEven = 7;
    widthOdd = 8;
    rowStep = fGpffff8338;
    yOffset = fGpffff8318;
    six = 6.0f;
    zero = 0.0f;
    three = 3.0f;
    while (row < 9) {
        alternating = ~row & 1;
        if (alternating != 0) {
            width = widthOdd;
        } else {
            width = widthEven;
        }
        col = 0;
        rowY = rowStep * (f32)row - yOffset;
        while (col < width) {
            if (alternating != 0) {
                if (col == 0) {
                    x = zero;
                } else if (col == width - 1) {
                    x = six;
                } else {
                    x = half + (f32)(col - 1);
                }
            } else {
                x = (f32)col;
            }
            position.x = x - three;
            position.y = rowY;
            position.z = zero;
            *(PanelVec3*)vertex = position;
            col++;
            vertex += 0x24;
        }
        row++;
    }
    K_ASSERT((vertex - (work + 4)) / 0x24 == 0x44, 0x591);
}
// FUN_0020cf20 NONMATCHING
void func_0020cf20(void* destination, PanelTransform* transform)
{
    u8* out = (u8*)destination;
    PanelMatrix* matrix;
    PanelVec3 axisZ;
    PanelVec3 facingAxis;
    PanelVec3 rotateAxis;
    PanelVec3 transformedAxis;
    PanelVec3 resourceCenter;
    PanelVec3 localPoint;
    PanelVec3 transformedPoint;
    PanelVec3 cameraDirection;
    PanelVec3 resourceDirection;
    const PanelVec3* cameraPosition;
    void* camera;
    s32 row;
    s32 col;
    s32 width;
    s32 alternating;
    u8* vertex;

    *(u64*)&axisZ = *(const u64*)D_0068E0C8_abs;
    axisZ.z = *(f32*)(D_0068E0C8_abs + 8);
    camera = kwlnGetMainCamera();
    cameraPosition = (const PanelVec3*)((u8*)func_004cb2f0(*(void**)((u8*)camera + 4)) + 0x30);
    *(u64*)&facingAxis = *(const u64*)D_0068E0D8_abs;
    facingAxis.z = *(f32*)(D_0068E0D8_abs + 8);
    *(u64*)&rotateAxis = *(const u64*)D_0068E0E8_abs;
    rotateAxis.z = *(f32*)(D_0068E0E8_abs + 8);
    *(u64*)&transformedAxis = *(const u64*)D_0068E0F8_abs;
    transformedAxis.z = *(f32*)(D_0068E0F8_abs + 8);
    matrix = (PanelMatrix*)func_004c38c0();
    func_0020ca90(matrix, transform);
    func_004c6c60(&facingAxis, &facingAxis, matrix);

    resourceCenter = *(const PanelVec3*)(out + 0x994);
    {
        f32 facing;

        if (transform->model != NULL) {
            FUN_004c6be0(&localPoint, &transform->translation,
                         func_004cb2f0(transform->model));
        } else {
            localPoint = transform->translation;
        }

        facing = facingAxis.x * (cameraPosition->x - localPoint.x) +
                 facingAxis.y * (cameraPosition->y - localPoint.y) +
                 facingAxis.z * (cameraPosition->z - localPoint.z);
        *(u32*)out &= ~1u;
        if (facing < 0.0f) {
            RwMatrixRotate(matrix, &rotateAxis, 180.0f, 1);
            *(u32*)out |= 1;
        }
    }

    {
        u8* color = (u8*)transform + 0x40;

        localPoint.x = 0.0f;
        localPoint.y = 0.0f;
        localPoint.z = 100.0f;
        FUN_004c6be0(&transformedPoint, &localPoint, matrix);
        func_004c6c60(&transformedAxis, &axisZ, matrix);
        RwV3dNormalize(&transformedAxis, &transformedAxis);

        vertex = out + 4;
        for (row = 0; row < 9; row++) {
            alternating = ~row & 1;
            if (alternating != 0) {
                width = 8;
            } else {
                width = 7;
            }
            for (col = 0; col < width; col++) {
                f32 dot;
                f32 reflectedX;
                f32 reflectedY;
                f32 reflectedZ;
                f32 highlight;
                f32 diffuse;
                f32 alpha;
                u32 alphaByte;
                u32 outputAlpha;

                if (alternating != 0) {
                    if (col == 0) {
                        localPoint.x = 0.0f;
                    } else if (col == width - 1) {
                        localPoint.x = 6.0f;
                    } else {
                        localPoint.x = 0.5f + (f32)(col - 1);
                    }
                } else {
                    localPoint.x = (f32)col;
                }
                localPoint.x -= 3.0f;
                localPoint.y = fGpffff8338 * ((f32)row / 8.0f - 0.5f);
                localPoint.z = 0.0f;
                FUN_004c6be0(&transformedPoint, &localPoint, matrix);

                cameraDirection.x = transformedPoint.x - cameraPosition->x;
                cameraDirection.y = transformedPoint.y - cameraPosition->y;
                cameraDirection.z = transformedPoint.z - cameraPosition->z;
                RwV3dNormalize(&cameraDirection, &cameraDirection);
                resourceDirection.x = transformedPoint.x - resourceCenter.x;
                resourceDirection.y = transformedPoint.y - resourceCenter.y;
                resourceDirection.z = transformedPoint.z - resourceCenter.z;
                RwV3dNormalize(&resourceDirection, &resourceDirection);

                dot = axisZ.x * cameraDirection.x +
                      axisZ.y * cameraDirection.y +
                      axisZ.z * cameraDirection.z;
                reflectedX = axisZ.x * dot - cameraDirection.x;
                reflectedX = axisZ.x * dot + reflectedX;
                reflectedY = axisZ.y * dot - cameraDirection.y;
                reflectedY = axisZ.y * dot + reflectedY;
                reflectedZ = axisZ.z * dot - cameraDirection.z;
                reflectedZ = axisZ.z * dot + reflectedZ;
                highlight = resourceDirection.x * reflectedX +
                            resourceDirection.y * reflectedY +
                            resourceDirection.z * reflectedZ;
                if (highlight <= 0.0f) {
                    alpha = 0.0f;
                } else {
                    alpha = highlight * highlight;
                    alpha *= highlight;
                    alpha *= highlight;
                    alpha *= highlight;
                    alpha *= highlight;
                }

                resourceDirection.x = transformedPoint.x - resourceCenter.x;
                resourceDirection.y = transformedPoint.y - resourceCenter.y;
                resourceDirection.z = transformedPoint.z - resourceCenter.z;
                RwV3dNormalize(&resourceDirection, &resourceDirection);
                diffuse = resourceDirection.x * transformedAxis.x +
                          resourceDirection.y * transformedAxis.y +
                          resourceDirection.z * transformedAxis.z;
                if (diffuse <= 0.0f) {
                    diffuse = 0.0f;
                }
                diffuse *= *(f32*)(out + 0x9a0);
                alpha = diffuse + alpha * *(f32*)(out + 0x9a4);
                if (alpha > 1.0f) {
                    alpha = 1.0f;
                }
                alphaByte = color[3];
                alpha *= (f32)alphaByte;
                outputAlpha = (u8)(u32)alpha;
                vertex[0x0c] = outputAlpha;
                vertex[0x0d] = outputAlpha;
                vertex[0x0e] = outputAlpha;
                vertex[0x0f] = outputAlpha;
                vertex += 0x24;
            }
        }
    }
    func_004c3880(matrix);
}
#pragma pop
