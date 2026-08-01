#include "Utils.h"
#include "Kosaka/k_assert.h"

#pragma alias func_0021d950_y2 func_0021d950
#pragma alias func_00209a00_y2 func_00209a00
#pragma alias func_00209940_y2 func_00209940
#pragma alias func_0021cce0_y2 func_0021cce0
#pragma alias func_00209c00_y2 func_00209c00
#pragma alias RpSkyRenderStateSet_y2 RpSkyRenderStateSet



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
extern u32 func_0021cce0_y2(u32 frame);
extern void func_0021d3b0(void* destination, void* frame);
extern void func_0021d8e0(void* destination, const void* layout);
extern void func_0021d950_y2(void* destination, const void* color);
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
extern void RpSkyRenderStateSet_y2(s32 state, void* value);
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


extern f32 DAT_007cadd4;
extern f32 DAT_007cad7c;
extern f32 DAT_007cad74;
extern f32 DAT_007caee8;
extern f32 FUN_0052e878(f32 angle);
extern f32 FUN_0052e6d8(f32 angle);
extern void func_0020cf20(void* destination, PanelTransform* transform);
typedef struct BattlePanelWork BattlePanelWork;
typedef struct BtlUnit BtlUnit;
typedef struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
} RwV3d;
BattlePanelWork* gBattlePanelWork;
extern void func_0021cd00(void* frame, f32* rectangle);
extern void func_0021d950(void* destination, const u8* color);
extern void func_0021eb80(void* destination, const f32* layout);
extern void* btlOrderGetUnitByIdx(u16 index);
extern u32 datCalcIsDead(void* calc, u32 mode);
extern void* func_001ff430(u32 id);
extern u32 datCalcGetHp(void* calc);
extern u32 datCalcGetMaxHp(void* calc);
extern void func_00280580(BtlUnit* unit, RwV3d* position);
extern u32 func_002d20a0(const RwV3d* position, RwV3d* projected);
extern void func_00208f60(void);
extern void func_00209a00(void* dst, u32 count, u32 slot, u32 align, f32 scale, const f32* origin);
extern void func_00209940(void* dst, u32 capacity, s32 value);
extern void func_0020c320(void* dst, u32 mode);
extern void func_0020c400(void* dst, u32 mode);
extern void func_0020c500(void* dst, u32 mode);
extern void func_0020c590(void* dst);
extern void func_0020c660(void* dst);
extern u32 func_0021cce0(void* frame);
extern u32 func_00209c00(void);
extern void RpSkyRenderStateSet(s32 state, u32 value);
extern u8* iGpffffb6fc;
extern f32 fGpffff7f20;
typedef void (*BpSetRenderState)(u32 state, u32 value);
typedef void (*BpRenderQuad)(void* vertices, u32 count, u32 first, u32 second, u32 third);
extern u32 D_00960090_y2[];
extern u32 D_0096009C[];

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
static u8* BP_WORK(void)
{
    return (u8*)gBattlePanelWork;
}

// FUN_00208ad0
void func_00208ad0(BattlePanelWork* work)
{
    K_ASSERT(gBattlePanelWork == NULL, 0x4e);
    *(u32*)work = 0;
    gBattlePanelWork = work;
}

// FUN_00208b20
void func_00208b20(void)
{
    gBattlePanelWork = NULL;
}

// FUN_00208b30 NONMATCHING
void func_00208b30(void)
{
    u8* work;
    void* initialUnit;
    void* unit;
    u32 unitIds[0x14];
    u32 texture1;
    u32 texture5;
    s32 count;
    u8* battleWork;
    s32 i;
    s32 slotIndex;
    s32 renderIndex;
    s32 j;
    u8* slot;

    K_ASSERT(gBattlePanelWork != NULL, 0x47);
    work = (u8*)gBattlePanelWork;
    battleWork = iGpffffb6fc;
    texture1 = func_0021c3f0(1);
    texture5 = func_0021c3f0(5);
    count = 0;
    for (;;) {
        initialUnit = btlOrderGetUnitByIdx((u16)count);
        if (initialUnit == NULL)
            break;
        K_ASSERT(count < 0x14, 0x6f);
        if (datCalcIsDead(*(void**)((u8*)initialUnit + 0xa2c), 0) != 0)
            K_ASSERT(0, 0x70);
        unitIds[count] = *(u32*)((u8*)initialUnit + 0xa8);
        count++;
    }

    i = 0;
    unit = *(void**)(battleWork + 0x150);
    while (unit != NULL) {
        if (((~*(u32*)((u8*)unit + 0x9c) & 8) == 0) &&
            (datCalcIsDead(*(void**)((u8*)unit + 0xa2c), 0) == 0)) {
            *(u32*)(work + i * 0x420 + 0x14) = *(u32*)((u8*)unit + 0xa8);
            i++;
        }
        unit = *(void**)((u8*)unit + 0xa34);
    }
    unit = *(void**)(battleWork + 0x158);
    while (unit != NULL) {
        if (((~*(u32*)((u8*)unit + 0x9c) & 8) == 0) &&
            (datCalcIsDead(*(void**)((u8*)unit + 0xa2c), 0) == 0)) {
            *(u32*)(work + i * 0x420 + 0x14) = *(u32*)((u8*)unit + 0xa8);
            i++;
        }
        unit = *(void**)((u8*)unit + 0xa34);
    }
    *(s32*)(work + 0x2950) = i;
    slotIndex = 0;
    while (slotIndex < *(s32*)(work + 0x2950)) {
        slot = work + slotIndex * 0x420 + 0x10;
        *(u32*)slot = 0;
        *(u32*)(slot + 0x218) = 0;
        j = 0;
        while (j < count) {
            if (*(u32*)(slot + 4) == unitIds[j]) {
                if (j == 9) {
                    *(s32*)(slot + 0x210) = -1;
                    *(s32*)(slot + 0x214) = -1;
                    *(s32*)(slot + 0x218) = 2;
                } else {
                    s32 n = *(s32*)(slot + 0x218);
                    *(s32*)(slot + 0x210 + n * 4) = j;
                    *(s32*)(slot + 0x218) = n + 1;
                }
            }
            j++;
        }
        K_ASSERT(*(u32*)(slot + 0x218) != 0, 0xaa);
        unit = func_001ff430(*(u32*)(slot + 4));
        *(u32*)(slot + 8) = datCalcGetHp(*(void**)((u8*)unit + 0xa2c)) & 0xffff;
        *(u32*)(slot + 0xc) = datCalcGetMaxHp(*(void**)((u8*)unit + 0xa2c)) & 0xffff;
        slotIndex++;
    }

    renderIndex = 0;
    while (renderIndex < *(s32*)(work + 0x2950)) {
        slot = work + renderIndex * 0x420 + 0x10;
        j = 0;
        while (j < *(s32*)(slot + 0x218)) {
            s32 value = *(s32*)(slot + 0x210 + j * 4);
            if (value == -1) {
                func_00209940(slot + 0x10 + (j << 8), 1, 1 - j);
            } else if (value == 0) {
                void* frame = func_0021cca0(texture1, 0x46);
                func_0021d3b0(slot + 0x10 + (j << 8), frame);
            } else {
                func_00209940(slot + 0x10 + (j << 8), 1, value + 1);
            }
            j++;
        }
        func_0021d3b0(slot + 0x310, func_0021cca0(texture1, 1));
        func_0021d3b0(slot + 0x210, func_0021cca0(texture5, 4));
        renderIndex++;
    }

    func_00208f60();
    *(u32*)work |= 1;
}

// FUN_00208f60 NONMATCHING
void func_00208f60(void)
{
    u8* work;
    u32 texture1;
    u32 texture5;
    u8* slot;
    BtlUnit* unit;
    void* frame;
    RwV3d position;
    RwV3d projected;
    f32 layout[4];
    f32 rectangle[4];
    f32 origin[2];
    u8 color[4];
    f32 x;
    f32 y;
    f32 originX;
    f32 originY;
    f32 layoutY;
    f32 originX2;
    f32 scale;
    f32 fullAlpha;
    s32 i;
    s32 j;

    K_ASSERT(gBattlePanelWork != NULL, 0x47);
    work = (u8*)gBattlePanelWork;
    texture1 = func_0021c3f0(1);
    texture5 = func_0021c3f0(5);
    fullAlpha = 255.0f;
    for (i = 0; i < *(s32*)(work + 0x2950); i++) {
        slot = work + i * 0x420 + 0x10;
        *(u32*)slot &= ~1u;
        unit = (BtlUnit*)func_001ff430(*(u32*)(slot + 4));
        func_00280580(unit, &position);
        if (func_002d20a0(&position, &projected) == 0) {
            *(u32*)slot |= 1;
        }
        if ((*(u32*)slot & 1) != 0) {
            continue;
        }
        x = projected.x - 55.0f;
        y = projected.y - 55.0f;
        y = y + 20.0f;
        originX = 39.0f + x;
        originY = 47.0f + y;
        layoutY = originY - 3.0f;
        originY = y + 40.0f;
        originX2 = originX + 30.0f;
        for (j = 0; j < *(s32*)(slot + 0x218); j++) {
            s32 value = *(s32*)(slot + 0x210 + j * 4);
            u8* destination = slot + 0x10 + (j << 8);

            if (value == 0) {
                frame = func_0021cca0(texture1, 0x46);
                layout[0] = originX;
                layout[1] = layoutY;
                layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
                layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
                func_0021d8e0(destination, layout);
                color[0] = 0xff;
                color[1] = 0xff;
                color[2] = 0xff;
                color[3] = 0xff;
                func_0021d950(destination, color);
                continue;
            }
            if (j == 1) {
                origin[0] = originX2;
                origin[1] = originY;
                scale = fGpffff7f20;
            } else if (j == 0) {
                origin[0] = originX;
                origin[1] = originY;
                scale = 1.0f;
            }
            if (value == -1)
                func_00209a00(destination, 1, 1 - j, 1, 1.0f, origin);
            else
                func_00209a00(destination, 1, value + 1, 1, scale, origin);
            color[0] = 0xff;
            color[1] = 0xff;
            color[2] = 0xff;
            color[3] = 0xff;
            func_0021d950(destination, color);
        }
        frame = func_0021cca0(texture1, 1);
        layout[0] = 55.0f + x;
        layout[1] = 55.0f + y;
        layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
        layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
        func_0021d8e0(slot + 0x320, layout);
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = (u8)fullAlpha;
        func_0021d950(slot + 0x320, color);
        frame = func_0021cca0(texture5, 4);
        func_0021cd00(frame, rectangle);
        scale = (f32)*(s32*)(slot + 8) / (f32)*(s32*)(slot + 0xc);
        layout[0] = rectangle[0];
        layout[1] = rectangle[1];
        layout[2] = (rectangle[2] - rectangle[0]) * scale;
        layout[3] = rectangle[3] - rectangle[1];
        func_0021eb80(slot + 0x220, layout);
        layout[0] = (8.0f + x) + 55.0f;
        layout[1] = (4.0f + y) + 55.0f;
        layout[2] = (f32)*(s32*)((u8*)frame + 0xc) * scale;
        layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
        func_0021d8e0(slot + 0x220, layout);
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = (u8)fullAlpha;
        func_0021d950(slot + 0x220, color);
    }
}

// FUN_002094f0
void func_002094f0(void)
{
    K_ASSERT(gBattlePanelWork != NULL, 0x47);
    *(u32*)gBattlePanelWork &= ~1u;
}

// FUN_00209540
void func_00209540(void)
{
    u32* work;

    K_ASSERT(gBattlePanelWork != NULL, 0x47);
    work = (u32*)gBattlePanelWork;
    if ((~*work & 1) != 0) {
        return;
    } else {
        func_00208f60();
    }
}

// FUN_002095a0
void func_002095a0(void)
{
    u8* work;
    u32 texture1;
    u32 texture5;
    s32 i;

    K_ASSERT(gBattlePanelWork != NULL, 0x47);
    work = (u8*)gBattlePanelWork;
    texture1 = func_0021c3f0(1);
    texture5 = func_0021c3f0(5);
    if ((~*(u32*)work & 1) == 0) {
        BpSetRenderState* setRenderState = (BpSetRenderState*)D_00960090_y2;

        (*setRenderState)(9, 2);
        (*setRenderState)(0x14, 2);
        (*setRenderState)(8, 0);
        (*setRenderState)(6, 0);
        for (i = 0; i < *(s32*)(work + 0x2950); i++) {
            u8* slot = work + i * 0x420 + 0x10;
            s32 j;

            if ((*(u32*)slot & 1) != 0) {
                continue;
            }
            {
                BpSetRenderState* slotRenderState;
                BpRenderQuad* slotRenderQuad;
                void* frame;

                frame = func_0021cca0(texture1, 1);
                slotRenderState = (BpSetRenderState*)D_00960090_y2;
                (*slotRenderState)(1, func_0021cce0(frame));
                RpSkyRenderStateSet(3, 0x717fb);
                RpSkyRenderStateSet(2, 0x44);
                slotRenderQuad = (BpRenderQuad*)D_0096009C;
                (*slotRenderQuad)(slot + 0x320, 4, 0, 1, 2);
                (*slotRenderQuad)(slot + 0x320, 4, 0, 2, 3);
                (*slotRenderState)(
                    1, func_0021cce0(func_0021cca0(texture5, 4)));
                RpSkyRenderStateSet(3, 0x717fb);
                RpSkyRenderStateSet(2, 0x44);
                (*slotRenderQuad)(slot + 0x220, 4, 0, 1, 2);
                (*slotRenderQuad)(slot + 0x220, 4, 0, 2, 3);
                RpSkyRenderStateSet(3, 0x717fb);
                RpSkyRenderStateSet(2, 0x44);
            }
            for (j = 0; j < *(s32*)(slot + 0x218); j++) {
                s32 value = *(s32*)(slot + 0x210 + j * 4);
                u8* quad;
                BpRenderQuad* renderQuad;

                if ((value == 0) && (value != -1)) {
                    (*setRenderState)(
                        1, func_0021cce0(func_0021cca0(texture1, 0x46)));
                } else {
                    (*setRenderState)(1, func_00209c00());
                }
                quad = slot + 0x10 + (j << 8);
                renderQuad = (BpRenderQuad*)D_0096009C;
                (*renderQuad)(quad, 4, 0, 1, 2);
                (*renderQuad)(quad, 4, 0, 2, 3);
            }
        }
    }
}

// FUN_00209940
void func_00209940_y2(void* destination, s32 capacity, s32 value)
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

















// Reconstructed state interpolation, UV projection, and corner rotation from retail control flow.
// Remaining excess is retained pending MWCCPS2 register-allocation and scheduling convergence.















/* Removing this worsens FUN_0020cda0 (nd12 -> nd259) and 1 more - measured W161. */



#pragma alias D_00960090_y2 D_00960090


// FUN_00209a00
void func_00209a00_y2(void* destination, s32 capacity, s32 value, const f32* origin, f32 scale)
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

/*
 * The panel keeps a compact list of living battle units followed by one
 * 0x240-byte status slot per unit.  Keep the list construction in one place;
 * rendering and animation updates consume only these slots.
 */
// FUN_00209c00
u32 func_00209c00_y2(void)
{
    return func_0021cce0_y2((u32)func_0021cca0(func_0021c3f0(1), 0x2e));
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
