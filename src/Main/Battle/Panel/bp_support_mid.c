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
extern void* func_004c38c0(void);
extern void func_004c3880(void* matrix);
extern void* func_004cb2f0(void* model);
extern void RwMatrixScale(void* matrix, const void* scale, s32 combine);
extern void RwMatrixTranslate(void* matrix, const void* translation, s32 combine);
extern void RwMatrixRotate(void* matrix, const void* axis, f32 angle, s32 combine);
extern void RwV3dTransformPoint(void* out, const void* in, const void* matrix);
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
extern volatile u16 D_00875A90[];
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

// FUN_00209d40
s32 func_00209d40(const s16* value)
{
    switch (*value) {
    case 0:
        return 0;
    case 1:
        return 1;
    case -1:
        return 2;
    default:
        K_ASSERT(0, 0x8c);
        return -1;
    }
}

// FUN_00209dc0
char* func_00209dc0(void)
{
    return D_0068D140;
}

// FUN_00209dd0
char* func_00209dd0(void)
{
    return datGetScenarioMode() ? D_0068D910 : D_0068D8F0;
}

// FUN_00209e10
char* func_00209e10(void)
{
    return D_0068D930;
}

// FUN_00209e20
char* func_00209e20(void)
{
    return datGetScenarioMode() ? D_0068DE20 : D_0068DD20;
}

// FUN_00209e60
char* func_00209e60(void)
{
    return D_0068DF20;
}

// FUN_00209e70
char* func_00209e70(void)
{
    return D_0068DF30;
}

// FUN_00209e80
char* func_00209e80(void)
{
    return D_0068DF60;
}

// FUN_00209e90
char* func_00209e90(void)
{
    return D_0068E020;
}

// FUN_00209ea0
void func_00209ea0(u8* work)
{
    *(u32*)(work + 0x00) = 0;
    *(u32*)(work + 0x38) = 0;
    *(u32*)(work + 0x20) = 0;
    *(u32*)(work + 0x24) = 0;
    *(u32*)(work + 0x28) = 0;
    *(f32*)(work + 0x1c) = 1.0f;
    *(u32*)(work + 0x10) = 0;
    *(u32*)(work + 0x14) = 0;
    *(u32*)(work + 0x18) = 0;
    *(f32*)(work + 0x2c) = 1.0f;
    *(f32*)(work + 0x30) = 1.0f;
    *(f32*)(work + 0x34) = 1.0f;
    *(u32*)(work + 0x3c) = 0;
    *(u8*)(work + 0x40) = 0xff;
    *(u8*)(work + 0x41) = 0xff;
    *(u8*)(work + 0x42) = 0xff;
    *(u8*)(work + 0x43) = 0xff;
    *(u32*)(work + 0xdc) = 0;
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

// FUN_00209f00 NONMATCHING
void func_00209f00(void* work)
{
    u8* panel = (u8*)work;

    func_00209ea0(panel);
    *(u32*)(panel + 4) = 0;
    func_0020c7b0(panel + 0xe0);
    *(u32*)(panel + 0x170) = 0;
    panel[0x2a4] = 0;
    panel[0x2a5] = 0;
    panel[0x2a6] = 0;
    panel[0x2a7] = 0xff;
}

// FUN_0020a800
void func_0020a800(void* work)
{
    u8* panel;
    PanelVec3 outerUpperRight;
    PanelVec3 outerLowerRight;
    PanelVec3 outerLowerLeft;
    PanelVec3 outerUpperLeft;
    PanelVec3 innerUpperRight;
    PanelVec3 innerLowerRight;
    PanelVec3 innerLowerLeft;
    PanelVec3 innerUpperLeft;
    PanelVec3 centerUpperRight;
    PanelVec3 centerLowerRight;
    PanelVec3 centerLowerLeft;
    PanelVec3 centerUpperLeft;
    f32 upperY;
    f32 lowerY;

    panel = (u8*)work;
    func_00209ea0(panel);
    *(u32*)(panel + 4) = 1;
    func_0020c7b0(panel + 0xe0);
    *(u32*)(panel + 0x328) = 0;

    outerUpperRight.x = 3.0f;
    upperY = fGpffff8318;
    outerUpperRight.y = upperY;
    outerUpperRight.z = 0.0f;
    *(PanelVec3*)(panel + 0x178) = outerUpperRight;
    outerLowerRight.x = -3.0f;
    outerLowerRight.y = upperY;
    outerLowerRight.z = 0.0f;
    *(PanelVec3*)(panel + 0x19c) = outerLowerRight;
    outerLowerLeft.x = -3.0f;
    lowerY = fGpffff8334;
    outerLowerLeft.y = lowerY;
    outerLowerLeft.z = 0.0f;
    *(PanelVec3*)(panel + 0x1c0) = outerLowerLeft;
    outerUpperLeft.x = 3.0f;
    outerUpperLeft.y = lowerY;
    outerUpperLeft.z = 0.0f;
    *(PanelVec3*)(panel + 0x1e4) = outerUpperLeft;

    panel[0x184] = 0xff;
    panel[0x185] = 0xff;
    panel[0x186] = 0xff;
    panel[0x187] = 0xff;
    panel[0x1a8] = 0xff;
    panel[0x1a9] = 0xff;
    panel[0x1aa] = 0xff;
    panel[0x1ab] = 0xff;
    panel[0x1cc] = 0xff;
    panel[0x1cd] = 0xff;
    panel[0x1ce] = 0xff;
    panel[0x1cf] = 0xff;
    panel[0x1f0] = 0xff;
    panel[0x1f1] = 0xff;
    panel[0x1f2] = 0xff;
    panel[0x1f3] = 0xff;
    *(f32*)(panel + 0x194) = 1.0f;
    *(f32*)(panel + 0x1b8) = 0.0f;
    *(f32*)(panel + 0x1dc) = 0.0f;
    *(f32*)(panel + 0x200) = 1.0f;
    *(f32*)(panel + 0x198) = 0.0f;
    *(f32*)(panel + 0x1bc) = 0.0f;
    *(f32*)(panel + 0x1e0) = 0.63671875f;
    *(f32*)(panel + 0x204) = 0.63671875f;

    innerUpperRight.x = 3.0f;
    innerUpperRight.y = upperY;
    innerUpperRight.z = 0.0f;
    *(PanelVec3*)(panel + 0x208) = innerUpperRight;
    innerLowerRight.x = -3.0f;
    innerLowerRight.y = upperY;
    innerLowerRight.z = 0.0f;
    *(PanelVec3*)(panel + 0x22c) = innerLowerRight;
    innerLowerLeft.x = -3.0f;
    innerLowerLeft.y = lowerY;
    innerLowerLeft.z = 0.0f;
    *(PanelVec3*)(panel + 0x250) = innerLowerLeft;
    innerUpperLeft.x = 3.0f;
    innerUpperLeft.y = lowerY;
    innerUpperLeft.z = 0.0f;
    *(PanelVec3*)(panel + 0x274) = innerUpperLeft;

    panel[0x214] = 0xff;
    panel[0x215] = 0xff;
    panel[0x216] = 0xff;
    panel[0x217] = 0xff;
    panel[0x238] = 0xff;
    panel[0x239] = 0xff;
    panel[0x23a] = 0xff;
    panel[0x23b] = 0xff;
    panel[0x25c] = 0xff;
    panel[0x25d] = 0xff;
    panel[0x25e] = 0xff;
    panel[0x25f] = 0xff;
    panel[0x280] = 0xff;
    panel[0x281] = 0xff;
    panel[0x282] = 0xff;
    panel[0x283] = 0xff;
    *(f32*)(panel + 0x224) = 1.0f;
    *(f32*)(panel + 0x248) = 0.0f;
    *(f32*)(panel + 0x26c) = 0.0f;
    *(f32*)(panel + 0x290) = 1.0f;
    *(f32*)(panel + 0x228) = 0.0f;
    *(f32*)(panel + 0x24c) = 0.0f;
    *(f32*)(panel + 0x270) = 0.63671875f;
    *(f32*)(panel + 0x294) = 0.63671875f;

    centerUpperRight.x = 3.0f;
    centerUpperRight.y = 3.0f;
    centerUpperRight.z = 0.0f;
    *(PanelVec3*)(panel + 0x298) = centerUpperRight;
    centerLowerRight.x = -3.0f;
    centerLowerRight.y = 3.0f;
    centerLowerRight.z = 0.0f;
    *(PanelVec3*)(panel + 0x2bc) = centerLowerRight;
    centerLowerLeft.x = -3.0f;
    centerLowerLeft.y = -3.0f;
    centerLowerLeft.z = 0.0f;
    *(PanelVec3*)(panel + 0x2e0) = centerLowerLeft;
    centerUpperLeft.x = 3.0f;
    centerUpperLeft.y = -3.0f;
    centerUpperLeft.z = 0.0f;
    *(PanelVec3*)(panel + 0x304) = centerUpperLeft;

    panel[0x2a4] = 0;
    panel[0x2a5] = 0;
    panel[0x2a6] = 0;
    panel[0x2a7] = 0xff;
    panel[0x2c8] = 0;
    panel[0x2c9] = 0;
    panel[0x2ca] = 0;
    panel[0x2cb] = 0xff;
    panel[0x2ec] = 0;
    panel[0x2ed] = 0;
    panel[0x2ee] = 0;
    panel[0x2ef] = 0xff;
    panel[0x310] = 0;
    panel[0x311] = 0;
    panel[0x312] = 0;
    panel[0x313] = 0xff;
    *(f32*)(panel + 0x2b4) = 1.0f;
    *(f32*)(panel + 0x2d8) = 0.0f;
    *(f32*)(panel + 0x2fc) = 0.0f;
    *(f32*)(panel + 0x320) = 1.0f;
    *(f32*)(panel + 0x2b8) = 0.0f;
    *(f32*)(panel + 0x2dc) = 0.0f;
    *(f32*)(panel + 0x300) = 1.0f;
    *(f32*)(panel + 0x324) = 1.0f;
}

// FUN_0020ab30
void func_0020ab30(void* work)
{
    u8* panel;
    PanelVec3 upperRight;
    PanelVec3 lowerRight;
    PanelVec3 lowerLeft;
    PanelVec3 upperLeft;

    panel = (u8*)work;
    func_00209ea0(panel);
    *(u32*)(panel + 4) = 2;
    func_0020c7b0(panel + 0xe0);

    upperRight.x = 3.0f;
    upperRight.y = fGpffff8318;
    upperRight.z = 0.0f;
    *(PanelVec3*)(panel + 0x170) = upperRight;

    lowerRight.x = -3.0f;
    lowerRight.y = fGpffff8318;
    lowerRight.z = 0.0f;
    *(PanelVec3*)(panel + 0x194) = lowerRight;

    lowerLeft.x = -3.0f;
    lowerLeft.y = fGpffff8334;
    lowerLeft.z = 0.0f;
    *(PanelVec3*)(panel + 0x1b8) = lowerLeft;

    upperLeft.x = 3.0f;
    upperLeft.y = fGpffff8334;
    upperLeft.z = 0.0f;
    *(PanelVec3*)(panel + 0x1dc) = upperLeft;

    panel[0x17c] = 0xff;
    panel[0x17d] = 0xff;
    panel[0x17e] = 0xff;
    panel[0x17f] = 0xff;
    panel[0x1a0] = 0xff;
    panel[0x1a1] = 0xff;
    panel[0x1a2] = 0xff;
    panel[0x1a3] = 0xff;
    panel[0x1c4] = 0xff;
    panel[0x1c5] = 0xff;
    panel[0x1c6] = 0xff;
    panel[0x1c7] = 0xff;
    panel[0x1e8] = 0xff;
    panel[0x1e9] = 0xff;
    panel[0x1ea] = 0xff;
    panel[0x1eb] = 0xff;

    *(f32*)(panel + 0x18c) = 0.9921875f;
    *(f32*)(panel + 0x1b0) = 0.0f;
    *(f32*)(panel + 0x1d4) = 0.0f;
    *(f32*)(panel + 0x1f8) = 0.9921875f;
    *(f32*)(panel + 0x190) = 0.0078125f;
    *(f32*)(panel + 0x1b4) = 0.0078125f;
    *(f32*)(panel + 0x1d8) = 0.63671875f;
    *(f32*)(panel + 0x1fc) = 0.63671875f;
}

// FUN_0020ac80
void func_0020ac80(void* work)
{
    (void)work;
}

// FUN_0020ac90 NONMATCHING
void func_0020ac90(void* work)
{
    u8* panel = (u8*)work;
    /* Project the panel's anchor through the active camera and retain a
       conservative visibility bit for the draw routine. */
    if (*(u32*)(panel + 0) & 2u) {
        *(u32*)(panel + 0) |= 1u;
    } else {
        *(u32*)(panel + 0) &= ~2u;
    }
}

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
    u8 alphaByte;
    f32 alpha;
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;

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
            c0 = panel[0x43];
            c1 = panel[0x40];
            c2 = panel[0x41];
            c3 = panel[0x42];
            color[0] = c1;
            color[1] = c2;
            color[2] = c3;
            color[3] = c0;
            alphaByte = ((volatile u8*)panel)[0x43];
            if ((s32)alphaByte >= 0) {
                alpha = (f32)alphaByte;
            } else {
                alpha = 2.0f * (f32)((alphaByte >> 1) | (alphaByte & 1));
            }
            alpha = (30.0f * alpha) / 100.0f;
            color[3] = (u8)(s32)alpha;
            func_0020ccc0(mode0 + 0x298, color);
            func_0020ccc0(mode0 + 0x328, color);
            color[0] = panel[0x40];
            color[1] = panel[0x41];
            color[2] = panel[0x42];
            color[3] = panel[0x43];
            alpha = 255.0f * *(f32*)(mode0 + 0x5FC);
            color[3] = (u8)(s32)alpha;
            func_0020ccc0(mode0 + 0x3B8, color);
            if (*(u32*)(mode0 + 0x170) & 1) {
                color[0] = panel[0x40];
                color[1] = panel[0x41];
                color[2] = panel[0x42];
                color[3] = panel[0x43];
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
                color[3] = (u8)(s32)alpha;
                func_0020ccc0(mode0 + 0x4D8, color);
            }
            break;
        case 1:
            func_0020ccc0(mode2 + 0x208, panel + 0x40);
            func_0020ccc0(mode2 + 0x178, panel + 0x40);
            alphaByte = panel[0x43];
            color[0] = panel[0x40];
            color[1] = panel[0x41];
            color[2] = panel[0x42];
            color[3] = alphaByte;
            color[0] = 0;
            color[1] = 0;
            color[2] = 0;
            if ((s32)alphaByte >= 0) {
                alpha = (f32)alphaByte;
            } else {
                alpha = 2.0f * (f32)((alphaByte >> 1) | (alphaByte & 1));
            }
            alpha = *(f32*)(mode2 + 0x32C) * (alpha * *(f32*)(mode2 + 0x328));
            color[3] = (u8)(s32)alpha;
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
        alphaByte = panel[0x43];
        if ((s32)alphaByte >= 0) {
            alpha = (f32)alphaByte;
        } else {
            alpha = 2.0f * (f32)((alphaByte >> 1) | (alphaByte & 1));
        }
        alpha = (255.0f * *(f32*)(mode0 + 0x5FC) * alpha) / 255.0f;
        color[3] = (u8)(s32)alpha;
        func_0020ccc0(mode0 + 0x3B8, color);
        color[0] = panel[0x40];
        color[1] = panel[0x41];
        color[2] = panel[0x42];
        color[3] = panel[0x43];
        if (*(u32*)(mode0 + 0x170) & 1) {
            color[3] = 0;
        } else {
            alphaByte = panel[0x43];
            if ((s32)alphaByte >= 0) {
                alpha = (f32)alphaByte;
            } else {
                alpha = 2.0f * (f32)((alphaByte >> 1) | (alphaByte & 1));
            }
            alpha = (255.0f * *(f32*)(mode0 + 0x5F8) * alpha) / 255.0f;
            color[3] = (u8)(s32)alpha;
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

// FUN_0020cda0 NONMATCHING
void func_0020cda0(u8* work)
{
    struct Vec3
    {
        f32 x;
        f32 y;
        f32 z;
    };
    struct Vec3 position;
    u8* vertex;
    f32 x;
    f32 rowY;
    f32 rowStep;
    f32 yOffset;
    f32 half;
    f32 six;
    f32 zero;
    f32 three;
    s32 row;
    s32 col;
    s32 width;
    s32 alternating;
    *(u32*)work = 0;
    half = 0.5f;
    *(f32*)(work + 0x9a0) = half;
    *(f32*)(work + 0x9a4) = 0.375f;
    vertex = work + 4;
    row = 0;
    alternating = ~row & 1;
    six = 6.0f;
    yOffset = fGpffff8318;
    rowStep = fGpffff8338;
    three = 3.0f;
    zero = 0.0f;
    while (row < 9)
    {
        rowY = rowStep * (f32)row - yOffset;
        col = 0;
        width = alternating != 0 ? 8 : 7;
        while (col < width)
        {
            if (alternating != 0)
            {
                if (col == 0)
                {
                    x = zero;
                }
                else if (col == width - 1)
                {
                    x = six;
                }
                else
                {
                    x = half + (f32)(col - 1);
                }
            }
            else
            {
                x = (f32)col;
            }
            position.x = x - three;
            col++;
            position.y = rowY;
            position.z = zero;
            *(struct Vec3*)vertex = position;
            vertex = vertex + (0x24);
        }
        row++;
        alternating = ~row & 1;
    }
    K_ASSERT((vertex - (work + 4)) / 0x24 == 0x44, 0x591);
}

// FUN_0020cf20 NONMATCHING
void func_0020cf20(void* destination, void* source)
{
    u8* out = (u8*)destination;
    const u8* in = (const u8*)source;
    if (out == NULL || in == NULL) {
        return;
    }
    *(u32*)(out + 0) &= ~2u;
    *(f32*)(out + 0x20) = *(const f32*)(in + 0x20);
    *(f32*)(out + 0x24) = *(const f32*)(in + 0x24);
    *(f32*)(out + 0x28) = *(const f32*)(in + 0x28);
    *(u32*)(out + 0) |= 1u;
}
