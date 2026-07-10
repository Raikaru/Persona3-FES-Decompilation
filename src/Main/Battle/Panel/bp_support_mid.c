#include "Utils.h"
#include "Kosaka/k_assert.h"

extern u32 datGetScenarioMode(void);
extern u32 func_0021c3f0(s32 texture);
extern void* func_0021cca0(u32 texture, s32 frame);
extern u32 func_0021cce0(u32 frame);
extern void func_0021d3b0(void* destination, void* frame);
extern void func_0021d8e0(void* destination, const void* layout);
extern void func_0021d950(void* destination, const void* color);
extern void func_004cde90(void* resource);
extern void* kwlnGetMainCamera(void);
extern void* func_004ca5b0(void* camera);
extern void func_004ca560(void* viewport, void* cameraData);
extern void func_004c3760(void* matrix, void* source, s32 mode);
extern void* func_004c38c0(void);
extern void func_004c3880(void* matrix);
extern void func_004cb2f0(void* model);
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
extern void func_00209ba0(void* destination, s32 digit);
extern void func_0020c7b0(u8* work);
extern void func_0020cda0(u8* work);
extern void* memcpy(void* destination, const void* source, u32 size);
extern void func_004f1ed0(void* vertices, u32 count, void* matrix, u32 stride);
extern void func_004f1fd0(u32 primitive, void* indices, u32 count);
extern void func_004f1f80(void);
extern void (*D_00960090)(u32 state, u32 value);
extern void* D_0068E108;
extern f32 D_0068E110;

// FUN_00209940 NONMATCHING
void func_00209940(void* destination, s32 capacity, s32 value)
{
    char digits[32];
    s32 length;
    s32 i;

    length = sprintf(digits, "%d", value);
    K_ASSERT(capacity >= length, 0x1c8);
    for (i = 0; i < length; i++) {
        s32 digit = digits[length - 1 - i] - '0';
        u8* slot = (u8*)destination + i * 0x100;
        func_00209ba0(slot, digit);
    }
}

// FUN_00209a00 NONMATCHING
void func_00209a00(void* destination, s32 capacity, s32 value, s32 align, f32 scale, const f32* origin)
{
    char digits[32];
    s32 length;
    s32 i;
    s32 count;

    length = sprintf(digits, "%d", value);
    K_ASSERT(capacity >= length, 0x1de);
    count = length < capacity ? length : capacity;
    for (i = 0; i < count; i++) {
        u8* slot = (u8*)destination + i * 0x100;
        func_00209ba0(slot, digits[length - 1 - i] - '0');
        if (origin != NULL) {
            ((f32*)slot)[0] = origin[0] + (f32)(capacity - i - 1) * 0.9375f;
            ((f32*)slot)[1] = origin[1];
        }
    }
    for (; i < capacity; i++) {
        u8* slot = (u8*)destination + i * 0x100;
        if (origin != NULL) {
            ((f32*)slot)[0] = origin[0];
            ((f32*)slot)[1] = origin[1];
        }
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

// FUN_00209ea0 NONMATCHING
void func_00209ea0(u8* work)
{
    s32 i;

    *(u32*)(work + 0) = 0;
    *(u32*)(work + 0x10) = 0;
    *(u32*)(work + 0x14) = 0;
    *(u32*)(work + 0x18) = 0;
    *(u32*)(work + 0x1c) = 0x3f800000;
    *(u32*)(work + 0x20) = 0;
    *(u32*)(work + 0x24) = 0;
    *(u32*)(work + 0x28) = 0;
    *(u32*)(work + 0x2c) = 0x3f800000;
    *(u32*)(work + 0x30) = 0x3f800000;
    *(u32*)(work + 0x34) = 0x3f800000;
    *(u32*)(work + 0x38) = 0;
    *(u32*)(work + 0x3c) = 0;
    for (i = 0; i < 4; i++) {
        work[0x40 + i] = 0xff;
    }
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
    panel_init_common((u8*)work, 0);
    ((u8*)work)[0x2a4] = 0;
    ((u8*)work)[0x2a5] = 0;
    ((u8*)work)[0x2a6] = 0;
    ((u8*)work)[0x2a7] = 0xff;
}

// FUN_0020a800 NONMATCHING
void func_0020a800(void* work)
{
    panel_init_common((u8*)work, 1);
    *(u32*)((u8*)work + 0x328) = 0;
}

// FUN_0020ab30 NONMATCHING
void func_0020ab30(void* work)
{
    panel_init_common((u8*)work, 2);
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
    if ((*(u32*)panel & 1u) == 0) {
        return;
    }
    func_0020ac90(work);
}

// FUN_0020c320 NONMATCHING
void func_0020c320(s32 unused, const f32* source, const void* viewport, f32 scale)
{
    f32* out = (f32*)viewport;
    f32 width = 640.0f;
    f32 height = 448.0f;
    (void)unused;
    if (source != NULL && out != NULL) {
        out[0] = -source[0] / (width * 0.5f) * scale;
        out[1] = -source[1] / (height * 0.5f) * scale;
        out[2] = scale;
    }
}

// FUN_0020c400 NONMATCHING
void func_0020c400(s32 unused, const f32* source, const void* viewport, f32 scale)
{
    f32* out = (f32*)viewport;
    (void)unused;
    if (source != NULL && out != NULL) {
        out[0] = (0.5f - source[0]) * scale;
        out[1] = (0.5f - source[1]) * scale;
        out[2] = scale;
    }
}

// FUN_0020c500 NONMATCHING
f32 func_0020c500(const f32* value, f32 scale)
{
    if (value == NULL) {
        return 0.0f;
    }
    return value[0] * 6.0f * scale / 640.0f;
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

// FUN_0020c660 NONMATCHING
f32 func_0020c660(s32 value, s32 mode)
{
    switch (mode) {
    case 2:
        return 200.0f + (f32)value * 200.0f / (f32)(mode - 1);
    case 3:
    case 4:
    case 5:
        return ((f32)value + 1.0f) * 640.0f / (f32)(mode + 1);
    case 6:
        return 500.0f + (f32)value * 500.0f / (f32)(mode - 1);
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

// FUN_0020c7b0 NONMATCHING
void func_0020c7b0(u8* work)
{
    s32 i;
    *(u32*)(work + 0) = 0;
    *(u32*)(work + 0x1c) = 0x3f7e0000;
    *(u32*)(work + 0x40) = 0x3f7e0000;
    *(u32*)(work + 0x64) = 0;
    *(u32*)(work + 0x88) = 0;
    for (i = 0; i < 4; i++) {
        work[0xc + i] = 0xff;
        work[0x30 + i] = 0xff;
        work[0x54 + i] = 0xff;
        work[0x78 + i] = 0xff;
    }
}

// FUN_0020c8d0 NONMATCHING
void func_0020c8d0(void)
{
    /* Build the fixed six-vertex panel index table used by the renderer. */
    volatile u16* indices = D_00875A90;
    u16 cursor = 0;
    s32 row;
    s32 col;
    for (row = 0; row < 8; row++) {
        for (col = 0; col < 6; col++) {
            *indices++ = cursor;
            *indices++ = cursor + 1;
            *indices++ = cursor + 8;
            *indices++ = cursor + 1;
            *indices++ = cursor + 9;
            *indices++ = cursor + 8;
            cursor++;
        }
        cursor += 2;
    }
}

// FUN_0020ca90 NONMATCHING
void func_0020ca90(void* matrix, const u8* quad)
{
    u8* out = (u8*)matrix;
    if (quad == NULL) {
        return;
    }
    *(f32*)(out + 0x30) = *(const f32*)(quad + 0x2c);
    *(f32*)(out + 0x34) = *(const f32*)(quad + 0x30);
    *(f32*)(out + 0x38) = *(const f32*)(quad + 0x34);
}

// FUN_0020cc80 NONMATCHING
void func_0020cc80(void* work, const u8* color)
{
    s32 i;
    for (i = 0; i < 4; i++) {
        ((u8*)work)[0x40 + i] = color[i];
    }
    *(u32*)work |= 4;
}

// FUN_0020ccc0 NONMATCHING
void func_0020ccc0(void* work, const u8* color)
{
    s32 i;
    for (i = 0; i < 4; i++) {
        ((u8*)work)[0xc + i] = color[i];
        ((u8*)work)[0x30 + i] = color[i];
        ((u8*)work)[0x54 + i] = color[i];
        ((u8*)work)[0x78 + i] = color[i];
    }
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
    s32 row;
    s32 col;
    s32 idx = 0;
    *(u32*)work = 0;
    *(f32*)(work + 0x9a0) = 0.5f;
    *(f32*)(work + 0x9a4) = 0.375f;
    for (row = 0; row < 9; row++) {
        s32 width = (row & 1) ? 7 : 8;
        for (col = 0; col < width; col++) {
            f32* vertex = (f32*)(work + 4 + idx * 0x24);
            vertex[0] = (f32)col - 3.0f;
            vertex[1] = (f32)row * 0.25f - 0.75f;
            vertex[2] = 0.0f;
            idx++;
        }
    }
    K_ASSERT(idx == 0x44, 0x591);
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
