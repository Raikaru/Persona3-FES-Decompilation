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

// FUN_00209f00
void func_00209f00(void* work)
{
    u8* panel = (u8*)work;

    PanelVec3 v1;
    PanelVec3 v2;
    PanelVec3 v3;
    PanelVec3 v4;
    PanelVec3 v5;
    PanelVec3 v6;
    PanelVec3 v7;
    PanelVec3 v8;
    PanelVec3 v9;
    PanelVec3 v10;
    PanelVec3 v11;
    PanelVec3 v12;
    PanelVec3 v13;
    PanelVec3 v14;
    PanelVec3 v15;
    PanelVec3 v16;
    PanelVec3 v17;
    PanelVec3 v18;
    PanelVec3 v19;
    PanelVec3 v20;
    PanelVec3 v21;
    PanelVec3 v22;
    PanelVec3 v23;
    PanelVec3 v24;
    PanelVec3 v25;
    PanelVec3 v26;
    PanelVec3 v27;
    PanelVec3 v28;
    PanelVec3 v29;
    PanelVec3 v30;
    PanelVec3 v31;
    PanelVec3 v32;
    PanelVec3 v33;
    PanelVec3 v34;
    PanelVec3 v35;
    PanelVec3 v36;
    f32 valA;
    f32 valB;
    f32 valC;
    f32 valD;

    func_00209ea0(panel);
    *(u32*)(panel + 0x4) = 0;
    func_0020c7b0(panel + 0xe0);
    *(u32*)(panel + 0x170) = 0;
    v1.x = valA = fGpffff8320;
    v1.y = valB = fGpffff8324;
    v1.z = 0.0f;
    *(PanelVec3*)(panel + 0x178) = v1;
    v2.x = -valA;
    v2.y = valB;
    v2.z = 0.0f;
    *(PanelVec3*)(panel + 0x19c) = v2;
    v3.x = -valA;
    v3.y = -valB;
    v3.z = 0.0f;
    *(PanelVec3*)(panel + 0x1c0) = v3;
    v4.x = valA;
    v4.y = -valB;
    v4.z = 0.0f;
    *(PanelVec3*)(panel + 0x1e4) = v4;
    panel[0x184] = 255;
    panel[0x185] = 255;
    panel[0x186] = 255;
    panel[0x187] = 255;
    panel[0x1a8] = 255;
    panel[0x1a9] = 255;
    panel[0x1aa] = 255;
    panel[0x1ab] = 255;
    panel[0x1cc] = 255;
    panel[0x1cd] = 255;
    panel[0x1ce] = 255;
    panel[0x1cf] = 255;
    panel[0x1f0] = 255;
    panel[0x1f1] = 255;
    panel[0x1f2] = 255;
    panel[0x1f3] = 255;
    *(u32*)(panel + 0x194) = 0x3f630000;
    *(u32*)(panel + 0x1b8) = 0x3de80000;
    *(u32*)(panel + 0x1dc) = 0x3de80000;
    *(u32*)(panel + 0x200) = 0x3f630000;
    *(u32*)(panel + 0x198) = 0x3db80000;
    *(u32*)(panel + 0x1bc) = 0x3db80000;
    *(u32*)(panel + 0x1e0) = 0x3f690000;
    *(u32*)(panel + 0x204) = 0x3f690000;
    v5.x = 3.0f;
    v5.y = valC = fGpffff8318;
    v5.z = 0.0f;
    *(PanelVec3*)(panel + 0x208) = v5;
    v6.x = -3.0f;
    v6.y = valC;
    v6.z = 0.0f;
    *(PanelVec3*)(panel + 0x22c) = v6;
    v7.x = -3.0f;
    v7.y = valD = fGpffff831c;
    v7.z = 0.0f;
    *(PanelVec3*)(panel + 0x250) = v7;
    v8.x = 3.0f;
    v8.y = valD;
    v8.z = 0.0f;
    *(PanelVec3*)(panel + 0x274) = v8;
    panel[0x214] = 255;
    panel[0x215] = 255;
    panel[0x216] = 255;
    panel[0x217] = 255;
    panel[0x238] = 255;
    panel[0x239] = 255;
    panel[0x23a] = 255;
    panel[0x23b] = 255;
    panel[0x25c] = 255;
    panel[0x25d] = 255;
    panel[0x25e] = 255;
    panel[0x25f] = 255;
    panel[0x280] = 255;
    panel[0x281] = 255;
    panel[0x282] = 255;
    panel[0x283] = 255;
    *(u32*)(panel + 0x224) = 0x3f800000;
    *(u32*)(panel + 0x248) = 0;
    *(u32*)(panel + 0x26c) = 0;
    *(u32*)(panel + 0x290) = 0x3f800000;
    *(u32*)(panel + 0x228) = 0;
    *(u32*)(panel + 0x24c) = 0;
    *(u32*)(panel + 0x270) = 0x3f800000;
    *(u32*)(panel + 0x294) = 0x3f800000;
    v9.x = valA;
    v9.y = valB;
    v9.z = 0.0f;
    *(PanelVec3*)(panel + 0x298) = v9;
    v10.x = -valA;
    v10.y = valB;
    v10.z = 0.0f;
    *(PanelVec3*)(panel + 0x2bc) = v10;
    v11.x = -valA;
    v11.y = -valB;
    v11.z = 0.0f;
    *(PanelVec3*)(panel + 0x2e0) = v11;
    v12.x = valA;
    v12.y = -valB;
    v12.z = 0.0f;
    *(PanelVec3*)(panel + 0x304) = v12;
    panel[0x2a4] = 255;
    panel[0x2a5] = 255;
    panel[0x2a6] = 255;
    panel[0x2a7] = 127;
    panel[0x2c8] = 255;
    panel[0x2c9] = 255;
    panel[0x2ca] = 255;
    panel[0x2cb] = 127;
    panel[0x2ec] = 255;
    panel[0x2ed] = 255;
    panel[0x2ee] = 255;
    panel[0x2ef] = 127;
    panel[0x310] = 255;
    panel[0x311] = 255;
    panel[0x312] = 255;
    panel[0x313] = 127;
    *(u32*)(panel + 0x2b4) = 0x3f800000;
    *(u32*)(panel + 0x2d8) = 0;
    *(u32*)(panel + 0x2fc) = 0;
    *(u32*)(panel + 0x320) = 0x3f800000;
    *(u32*)(panel + 0x2b8) = 0;
    *(u32*)(panel + 0x2dc) = 0;
    *(u32*)(panel + 0x300) = 0x3f800000;
    *(u32*)(panel + 0x324) = 0x3f800000;
    v13.x = valA;
    v13.y = valB;
    v13.z = 0.0f;
    *(PanelVec3*)(panel + 0x328) = v13;
    v14.x = -valA;
    v14.y = valB;
    v14.z = 0.0f;
    *(PanelVec3*)(panel + 0x34c) = v14;
    v15.x = -valA;
    v15.y = -valB;
    v15.z = 0.0f;
    *(PanelVec3*)(panel + 0x370) = v15;
    v16.x = valA;
    v16.y = -valB;
    v16.z = 0.0f;
    *(PanelVec3*)(panel + 0x394) = v16;
    panel[0x334] = 255;
    panel[0x335] = 255;
    panel[0x336] = 255;
    panel[0x337] = 127;
    panel[0x358] = 255;
    panel[0x359] = 255;
    panel[0x35a] = 255;
    panel[0x35b] = 127;
    panel[0x37c] = 255;
    panel[0x37d] = 255;
    panel[0x37e] = 255;
    panel[0x37f] = 127;
    panel[0x3a0] = 255;
    panel[0x3a1] = 255;
    panel[0x3a2] = 255;
    panel[0x3a3] = 127;
    *(u32*)(panel + 0x344) = 0x3f800000;
    *(u32*)(panel + 0x368) = 0;
    *(u32*)(panel + 0x38c) = 0;
    *(u32*)(panel + 0x3b0) = 0x3f800000;
    *(u32*)(panel + 0x348) = 0;
    *(u32*)(panel + 0x36c) = 0;
    *(u32*)(panel + 0x390) = 0x3f800000;
    *(u32*)(panel + 0x3b4) = 0x3f800000;
    v17.x = 3.0f;
    v17.y = valC;
    v17.z = 0.0f;
    *(PanelVec3*)(panel + 0x3b8) = v17;
    v18.x = -3.0f;
    v18.y = valC;
    v18.z = 0.0f;
    *(PanelVec3*)(panel + 0x3dc) = v18;
    v19.x = -3.0f;
    v19.y = valD;
    v19.z = 0.0f;
    *(PanelVec3*)(panel + 0x400) = v19;
    v20.x = 3.0f;
    v20.y = valD;
    v20.z = 0.0f;
    *(PanelVec3*)(panel + 0x424) = v20;
    panel[0x3c4] = 255;
    panel[0x3c5] = 255;
    panel[0x3c6] = 255;
    panel[0x3c7] = 153;
    panel[0x3e8] = 255;
    panel[0x3e9] = 255;
    panel[0x3ea] = 255;
    panel[0x3eb] = 153;
    panel[0x40c] = 255;
    panel[0x40d] = 255;
    panel[0x40e] = 255;
    panel[0x40f] = 153;
    panel[0x430] = 255;
    panel[0x431] = 255;
    panel[0x432] = 255;
    panel[0x433] = 153;
    *(u32*)(panel + 0x3d4) = 0x3f800000;
    *(u32*)(panel + 0x3f8) = 0;
    *(u32*)(panel + 0x41c) = 0;
    *(u32*)(panel + 0x440) = 0x3f800000;
    *(u32*)(panel + 0x3d8) = 0;
    *(u32*)(panel + 0x3fc) = 0;
    *(u32*)(panel + 0x420) = 0x3f800000;
    *(u32*)(panel + 0x444) = 0x3f800000;
    v21.x = valA;
    v21.y = valB;
    v21.z = 0.0f;
    *(PanelVec3*)(panel + 0x448) = v21;
    v22.x = -valA;
    v22.y = valB;
    v22.z = 0.0f;
    *(PanelVec3*)(panel + 0x46c) = v22;
    v23.x = -valA;
    v23.y = -valB;
    v23.z = 0.0f;
    *(PanelVec3*)(panel + 0x490) = v23;
    v24.x = valA;
    v24.y = -valB;
    v24.z = 0.0f;
    *(PanelVec3*)(panel + 0x4b4) = v24;
    panel[0x454] = 255;
    panel[0x455] = 255;
    panel[0x456] = 255;
    panel[0x457] = 255;
    panel[0x478] = 255;
    panel[0x479] = 255;
    panel[0x47a] = 255;
    panel[0x47b] = 255;
    panel[0x49c] = 255;
    panel[0x49d] = 255;
    panel[0x49e] = 255;
    panel[0x49f] = 255;
    panel[0x4c0] = 255;
    panel[0x4c1] = 255;
    panel[0x4c2] = 255;
    panel[0x4c3] = 255;
    *(u32*)(panel + 0x464) = 0x3f630000;
    *(u32*)(panel + 0x488) = 0x3de80000;
    *(u32*)(panel + 0x4ac) = 0x3de80000;
    *(u32*)(panel + 0x4d0) = 0x3f630000;
    *(u32*)(panel + 0x468) = 0x3db80000;
    *(u32*)(panel + 0x48c) = 0x3db80000;
    *(u32*)(panel + 0x4b0) = 0x3f690000;
    *(u32*)(panel + 0x4d4) = 0x3f690000;
    v25.x = valA;
    v25.y = valB;
    v25.z = 0.0f;
    *(PanelVec3*)(panel + 0x4d8) = v25;
    v26.x = -valA;
    v26.y = valB;
    v26.z = 0.0f;
    *(PanelVec3*)(panel + 0x4fc) = v26;
    v27.x = -valA;
    v27.y = -valB;
    v27.z = 0.0f;
    *(PanelVec3*)(panel + 0x520) = v27;
    v28.x = valA;
    v28.y = -valB;
    v28.z = 0.0f;
    *(PanelVec3*)(panel + 0x544) = v28;
    panel[0x4e4] = 255;
    panel[0x4e5] = 255;
    panel[0x4e6] = 255;
    panel[0x4e7] = 255;
    panel[0x508] = 255;
    panel[0x509] = 255;
    panel[0x50a] = 255;
    panel[0x50b] = 255;
    panel[0x52c] = 255;
    panel[0x52d] = 255;
    panel[0x52e] = 255;
    panel[0x52f] = 255;
    panel[0x550] = 255;
    panel[0x551] = 255;
    panel[0x552] = 255;
    panel[0x553] = 255;
    *(u32*)(panel + 0x4f4) = 0x3f630000;
    *(u32*)(panel + 0x518) = 0x3de80000;
    *(u32*)(panel + 0x53c) = 0x3de80000;
    *(u32*)(panel + 0x560) = 0x3f630000;
    *(u32*)(panel + 0x4f8) = 0x3db80000;
    *(u32*)(panel + 0x51c) = 0x3db80000;
    *(u32*)(panel + 0x540) = 0x3f690000;
    *(u32*)(panel + 0x564) = 0x3f690000;
    v29.x = 3.0f;
    v29.y = valC;
    v29.z = 0.0f;
    *(PanelVec3*)(panel + 0x4c) = v29;
    v30.x = -3.0f;
    v30.y = valC;
    v30.z = 0.0f;
    *(PanelVec3*)(panel + 0x70) = v30;
    v31.x = -3.0f;
    v31.y = valD;
    v31.z = 0.0f;
    *(PanelVec3*)(panel + 0x94) = v31;
    v32.x = 3.0f;
    v32.y = valD;
    v32.z = 0.0f;
    *(PanelVec3*)(panel + 0xb8) = v32;
    panel[0x58] = 255;
    panel[0x59] = 255;
    panel[0x5a] = 255;
    panel[0x5b] = 64;
    panel[0x7c] = 255;
    panel[0x7d] = 255;
    panel[0x7e] = 255;
    panel[0x7f] = 64;
    panel[0xa0] = 255;
    panel[0xa1] = 255;
    panel[0xa2] = 255;
    panel[0xa3] = 64;
    panel[0xc4] = 255;
    panel[0xc5] = 255;
    panel[0xc6] = 255;
    panel[0xc7] = 64;
    *(u32*)(panel + 0x68) = 0x3f800000;
    *(u32*)(panel + 0x8c) = 0;
    *(u32*)(panel + 0xb0) = 0;
    *(u32*)(panel + 0xd4) = 0x3f800000;
    *(u32*)(panel + 0x6c) = 0;
    *(u32*)(panel + 0x90) = 0;
    *(u32*)(panel + 0xb4) = 0x3f800000;
    *(u32*)(panel + 0xd8) = 0x3f800000;
    v33.x = 3.0f;
    v33.y = valC;
    v33.z = 0.0f;
    *(PanelVec3*)(panel + 0x568) = v33;
    v34.x = -3.0f;
    v34.y = valC;
    v34.z = 0.0f;
    *(PanelVec3*)(panel + 0x58c) = v34;
    v35.x = -3.0f;
    v35.y = valD;
    v35.z = 0.0f;
    *(PanelVec3*)(panel + 0x5b0) = v35;
    v36.x = 3.0f;
    v36.y = valD;
    v36.z = 0.0f;
    *(PanelVec3*)(panel + 0x5d4) = v36;
    panel[0x574] = 255;
    panel[0x575] = 255;
    panel[0x576] = 255;
    panel[0x577] = 255;
    panel[0x598] = 255;
    panel[0x599] = 255;
    panel[0x59a] = 255;
    panel[0x59b] = 255;
    panel[0x5bc] = 255;
    panel[0x5bd] = 255;
    panel[0x5be] = 255;
    panel[0x5bf] = 255;
    panel[0x5e0] = 255;
    panel[0x5e1] = 255;
    panel[0x5e2] = 255;
    panel[0x5e3] = 255;
    *(u32*)(panel + 0x584) = 0x3f800000;
    *(u32*)(panel + 0x5a8) = 0;
    *(u32*)(panel + 0x5cc) = 0;
    *(u32*)(panel + 0x5f0) = 0x3f800000;
    *(u32*)(panel + 0x588) = 0;
    *(u32*)(panel + 0x5ac) = 0;
    *(u32*)(panel + 0x5d0) = 0x3f800000;
    *(u32*)(panel + 0x5f4) = 0x3f800000;
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

extern f32 DAT_007cadd4;
extern f32 DAT_007cad7c;
extern f32 DAT_007cad74;
extern f32 DAT_007caee8;
extern f32 FUN_0052e878(f32 angle);
extern f32 FUN_0052e6d8(f32 angle);
extern void func_0020cf20(void* destination, void* source);

// Reconstructed state interpolation, UV projection, and corner rotation from retail control flow.
// Remaining excess is retained pending MWCCPS2 register-allocation and scheduling convergence.

// FUN_0020ac90 NONMATCHING
void func_0020ac90(void* work)
{
    u8* panel = (u8*)work;
    f32 phase;
    f32 frac;
    f32 blend;
    s32 state;
    s32 i;
    f32 corner[4][2];
    f32 angle;
    f32 x;
    f32 y;
    f32 rotatedX;
    f32 rotatedY;
    f32 sinA;
    f32 cosA;
    *(f32*)(panel + 0x3c) += DAT_007cadd4;
    state = *(s32*)(panel + 4);
    switch (state) {
    case 0:
        goto state0;
    case 1:
        goto state1;
    default:
        goto shared_tail;
    }


state0:
    phase = *(f32*)(panel + 0x3c) / 8.0f;
    frac = phase - (f32)(s32)phase;
    *(f32*)(panel + 0x2b8) = frac;
    *(f32*)(panel + 0x2dc) = frac;
    *(f32*)(panel + 0x300) = 1.0f + frac;
    *(f32*)(panel + 0x324) = 1.0f + frac;

    phase = *(f32*)(panel + 0x3c) / 6.0f;
    frac = phase - (f32)(s32)phase;
    *(f32*)(panel + 0x348) = frac;
    *(f32*)(panel + 0x36c) = frac;
    *(f32*)(panel + 0x390) = 1.0f + frac;
    *(f32*)(panel + 0x3b4) = 1.0f + frac;

    phase = *(f32*)(panel + 0x3c) / 4.0f;
    frac = phase - (f32)(s32)phase;
    if (frac < 0.5f)
    {
        blend = DAT_007cad7c + DAT_007cad7c * frac / 0.5f;
    }
    else
    {
        blend = (1.0f - (frac - 0.5f) / 0.5f) * DAT_007cad7c + DAT_007cad7c;
    }
    *(f32*)(panel + 0x5fc) = blend;

    phase = *(f32*)(panel + 0x3c) / 2.0f;
    frac = phase - (f32)(s32)phase;
    if (frac < 0.5f)
    {
        blend = DAT_007cad74 * frac / 0.5f;
    }
    else
    {
        blend = (1.0f - (frac - 0.5f) / 0.5f) * DAT_007cad74;
    }
    *(f32*)(panel + 0x5f8) = blend;

    phase = *(f32*)(panel + 0x3c) / 20.0f;
    frac = phase - (f32)(s32)phase;
    blend = (100.0f + 20.0f * frac) / 100.0f;
    blend = 0.38671875f / blend;
    *(f32*)(panel + 0x4f4) = 0.5f + blend;
    *(f32*)(panel + 0x518) = 0.5f - blend;
    *(f32*)(panel + 0x53c) = 0.5f - blend;
    *(f32*)(panel + 0x560) = 0.5f + blend;

    blend = (100.0f + 20.0f * frac) / 100.0f;
    blend = 0.41015625f / blend;
    *(f32*)(panel + 0x4f8) = 0.5f - blend;
    *(f32*)(panel + 0x51c) = 0.5f - blend;
    *(f32*)(panel + 0x540) = 0.5f + blend;
    *(f32*)(panel + 0x564) = 0.5f + blend;
    goto shared_tail;

state1:
    phase = *(f32*)(panel + 0x3c) / 2.0f;
    frac = phase - (f32)(s32)phase;
    if (frac < 0.5f)
    {
        blend = DAT_007cad74 * frac / 0.5f;
    }
    else
    {
        blend = (1.0f - (frac - 0.5f) / 0.5f) * DAT_007cad74;
    }
    *(f32*)(panel + 0x32c) = blend;

    phase = *(f32*)(panel + 0x3c) / 20.0f;
    frac = phase - (f32)(s32)phase;
    blend = (70.0f + 20.0f * frac) / 100.0f;
    blend = 0.38671875f / blend;
    *(f32*)(panel + 0x4f4) = 0.5f + blend;
    *(f32*)(panel + 0x518) = 0.5f - blend;
    *(f32*)(panel + 0x53c) = 0.5f - blend;
    *(f32*)(panel + 0x560) = 0.5f + blend;

    blend = (70.0f + 20.0f * frac) / 100.0f;
    blend = 0.41015625f / blend;
    *(f32*)(panel + 0x4f8) = 0.5f - blend;
    *(f32*)(panel + 0x51c) = 0.5f - blend;
    *(f32*)(panel + 0x540) = 0.5f + blend;
    *(f32*)(panel + 0x564) = 0.5f + blend;

shared_tail:

    if ((*(u32*)(panel + 0) & 2) != 0 && *(s32*)(panel + 4) == 0)
    {
        corner[0][0] = 1.0f;
        corner[0][1] = 1.0f;
        corner[1][0] = 0.0f;
        corner[1][1] = 1.0f;
        corner[2][0] = 0.0f;
        corner[2][1] = 0.0f;
        corner[3][0] = 1.0f;
        corner[3][1] = 0.0f;

        angle = *(f32*)(panel + 0x3c) / 4.0f;
        angle *= DAT_007caee8;

        for (i = 0; i < 4; i++)
        {
            corner[i][0] -= 0.5f;
            corner[i][1] -= 0.5f;
        }
        for (i = 0; i < 4; i++)
        {
            y = corner[i][1];
            x = corner[i][0];
            sinA = FUN_0052e878(angle);
            cosA = FUN_0052e6d8(angle);
            rotatedX = x * cosA - y * sinA;
            sinA = FUN_0052e878(angle);
            cosA = FUN_0052e6d8(angle);
            rotatedY = x * sinA + y * cosA;
            corner[i][0] = rotatedX;
            corner[i][1] = rotatedY;
        }

        for (i = 0; i < 4; i++)
        {
            corner[i][0] += 0.5f;
            corner[i][1] += 0.5f;
        }

        *(f32*)(panel + 0x584) = corner[0][0];
        *(f32*)(panel + 0x588) = corner[0][1];
        *(f32*)(panel + 0x5a8) = corner[1][0];
        *(f32*)(panel + 0x5ac) = corner[1][1];
        *(f32*)(panel + 0x5cc) = corner[2][0];
        *(f32*)(panel + 0x5d0) = corner[2][1];
        *(f32*)(panel + 0x5f0) = corner[3][0];
        *(f32*)(panel + 0x5f4) = corner[3][1];
    }

    if (*(u32*)(panel + 0) & 1)
    {
        *(u32*)(panel + 0x44) += 0x10000;
        if (*(s32*)(panel + 0x48) == 1)
        {
        }
        else if (*(s32*)(panel + 0x48) == 0)
        {
            if (*(u32*)(panel + 0x44) >= 0x1e0000)
            {
                *(u32*)(panel + 0) &= ~1u;
            }
        }
    }

    if (*(u32*)(panel + 0) & 8)
    {
        func_0020cf20((void*)(uintptr_t)*(u32*)(panel + 0xdc), panel);
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
    register u8 c0;
    register u8 c1;
    register u8 c2;
    register u8 c3;
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
            if (value >= 0) {
                alpha = (f32)value;
            } else {
                value = (value >> 1) | (value & 1);
                alpha = (f32)value;
                alpha += alpha;
            }
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
            if (value >= 0) {
                alpha = (f32)value;
            } else {
                value = (value >> 1) | (value & 1);
                alpha = (f32)value;
                alpha += alpha;
            }
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
        if (value >= 0) {
            alpha = (f32)value;
        } else {
            value = (value >> 1) | (value & 1);
            alpha = (f32)value;
            alpha += alpha;
        }
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
            if (value >= 0) {
                alpha = (f32)value;
            } else {
                value = (value >> 1) | (value & 1);
                alpha = (f32)value;
                alpha += alpha;
            }
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
    register u8* vertex;
    register s32 alternating;
    register s32 col;
    register s32 row;
    register s32 width;
    register s32 widthEven;
    register s32 widthOdd;
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
void func_0020cf20(void* destination, void* source)
{
    u8* out = (u8*)destination;
    register PanelTransform* transform = (PanelTransform*)source;
    PanelVec3 axisZ;
    PanelVec3 facingAxis;
    PanelVec3 rotateAxis;
    PanelVec3 transformedAxis;
    PanelVec3 resourceCenter;
    PanelVec3 transformedSource;
    PanelVec3 localPoint;
    PanelVec3 transformedPoint;
    PanelVec3 cameraDirection;
    PanelVec3 resourceDirection;
    const PanelVec3* cameraPosition;
    PanelMatrix* matrix;
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
    if (transform->model != NULL) {
        RwV3dTransformPoint(&transformedSource, &transform->translation,
                            func_004cb2f0(transform->model));
    } else {
        transformedSource = transform->translation;
    }

    {
        f32 facing;

        facing = facingAxis.x * (cameraPosition->x - transformedSource.x) +
                 facingAxis.y * (cameraPosition->y - transformedSource.y) +
                 facingAxis.z * (cameraPosition->z - transformedSource.z);
        *(u32*)out &= ~2u;
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
        RwV3dTransformPoint(&transformedPoint, &localPoint, matrix);
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
                RwV3dTransformPoint(&transformedPoint, &localPoint, matrix);

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
                if (alpha < 2147483648.0f) {
                    vertex[0x0c] = (u8)(s32)alpha;
                } else {
                    vertex[0x0c] = (u8)(s32)(alpha - 2147483648.0f);
                }
                vertex[0x0d] = vertex[0x0c];
                vertex[0x0e] = vertex[0x0c];
                vertex[0x0f] = vertex[0x0c];
                vertex += 0x24;
            }
        }
    }
    func_004c3880(matrix);
}
#pragma pop
