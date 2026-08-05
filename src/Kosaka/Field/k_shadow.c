#include "Kosaka/Field/k_shadow.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rwcore.h"
#include "Graphics/Model/mdlManager.h"
#include "Kernel/Kwln/kwln.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "Kosaka/Field/k_field.h"
#include "Kosaka/Field/k_fldFrame.h"
extern f32 cosf(f32 x);
extern f32 sinf(f32 x);

extern s32 AddIntcHandler(s32 cause, s32 (*handler)(s32), s32 mode);
extern s32 EnableIntc(s32 cause);
extern s32 RemoveIntcHandler(s32 cause, s32 handle);

typedef struct FldShadowRenderTex
{
    s32 state;              // 0x00
    u32 unk_04;             // 0x04
    u16 resTypeId;          // 0x08
    u16 mode;               // 0x0a
    Resrc* res;             // 0x0c
    Model* model;           // 0x10
    void* unk_14;           // 0x14
    f32 projectionDistance; // 0x18
    u8 unk_1c[0x20];
    void* texture;          // 0x3c
    RwRaster* raster;       // 0x40
    RwCamera* camera;       // 0x44
    void* unk_48;           // 0x48
    f32* radius;            // 0x4c
    u8 unk_50[0x24];
    RwV3d sourcePosition;   // 0x74
    RwV3d projectionAxis;   // 0x80
} FldShadowRenderTex;

#define FLDSHADOW_RESOURCE_FLAGS_DRAW 0x00000002
#define FLDSHADOW_RESOURCE_FLAGS_MATRIX 0x80000000
#define FLDSHADOW_MODEL_FLAGS_SHADOWPASS 0x0004

#define FLDSHADOW_VIEW_SCALE (*(const f32*)0x007cadb0)
#define FLDSHADOW_FAR_SCALE (*(const f32*)0x007caf24)
#define FLDSHADOW_CLEAR_COLOR ((RwRGBA*)DAT_007ce138)
#define FLDSHADOW_TINT (*(const RwRGBA*)DAT_007cc144_abs)
#define FLDSHADOW_RENDER_ACTIVE (*(u32*)0x007ce158)
#define FLDSHADOW_CHAR_RENDER_GUARD (*(u32*)0x007cc1ec)
#define FLDSHADOW_CAMERA_OFFSET ((const RwV3d*)DAT_00678920)
#define FLDSHADOW_TASK_NAME ((const char*)0x00678930)
#define FLDSHADOW_SOURCE_FILE ((const char*)0x00678948)

extern void* func_0019b2b0(KwlnTask* renderTexTask);
extern void func_0019bcf0(KwlnTask* renderTexTask);
extern void func_00199c60(RwCamera* camera);
extern void* func_004d0e40(void* raster);
extern void func_004f1780(RwRaster* raster, u32 enabled);
extern void* func_004d0be0(void* texture, RwRaster* raster);
extern RwCamera* func_004ca090(void);
extern RwFrame* func_004caf10(void);
extern RwCamera* func_004d1840(RwCamera* camera, RwFrame* frame);
extern RwFrame* func_004cb930(RwFrame* frame, const RwV3d* translation, RwOpCombineType combineOp);
#pragma alias func_004cb930_one func_004cb930
extern void func_004cb930_one(RwFrame* frame);
extern RwMatrix* func_004c2fb0(RwMatrix* matrixOut, RwMatrix* matrixIn);
extern void func_004c32a0(RwMatrix* destination, const RwMatrix* source);
extern RwCamera* func_004c9db0(RwCamera* camera, f32 nearPlane);
extern RwCamera* func_004c9d70(RwCamera* camera, f32 farPlane);
extern void func_00317a20(Model* model);
extern u32 func_001a01c0(void);
extern RwMatrix* func_001a0a50(void);
extern RwMatrix* func_001a0d80(void);
extern RpLight* func_00198580(void);
extern RpWorld* func_0049c160(RpWorld* world, RwCamera* camera);
extern void* func_004caf80(void* frame);
extern void* func_004cde90(void* raster);
extern void* func_004ca030(void* camera);
extern RwSphere* func_004912b0(void* atomic);
extern RwV3d* func_004c6c20(RwV3d* pointsOut, const RwV3d* pointsIn, u32 pointCount, const RwMatrix* matrix);
extern RwMatrix* func_004cb2f0(void* frame);
extern void* func_00464120(void* atomic, void* geometry, void* callback, void* context);
extern void* func_004f1ed0(void* vertexBuffer, u32 vertexCount, u32 primitiveType, u32 stride);
extern void func_004f2150(s32 primitiveType);
extern void func_004f1f80(void);
extern void (*D_00960090)(u32 state, u32 value);
#pragma alias D_00960090_abs D_00960090
extern void (*D_00960090_abs[])(u32 state, u32 value);
extern u32 D_00960184[];
#pragma alias D_00960184_abs D_00960184
extern u8 D_00960184_abs[];
#pragma alias ShadowCalloc D_00960184
extern void* (*ShadowCalloc)(u32 count, u32 size, u32 hint);
extern RwRGBA DAT_007cc144;
#pragma alias DAT_007cc144_abs DAT_007cc144
extern u8 DAT_007cc144_abs[];
extern u8 DAT_007ce138[];
extern u8 DAT_00678920[];
extern s32 DAT_007cc148;
extern s32 DAT_007ce13c;
extern void* func_004ce0f0(s32 width, s32 height, s32 depth, s32 flags);
#pragma alias jtbl_0096017C_abs jtbl_0096017C
extern u32 jtbl_0096017C_abs[];
extern void* memset(void* dest, s32 value, u32 size);
extern s32 K_Scene_001a0250(void);
extern void* func_00491880(void);
extern void* func_004919b0(void* renderObject, void* geometry, u32 flags);
extern void* func_00492d10(void* renderObject, void* frame);
extern void* func_00492e20(void* geometry, f32* bounds);
extern void* func_00493210(void* layout, u16* indices, u16 a, u16 b, u16 c);
extern void* func_00493230(void* layout, u16* indices, void* colorData);
extern void* func_00493370(void* layout, u16 flags);
extern void* func_004933d0(void* layout);
extern void* func_00493710(s32 type, s32 count, u32 format);
extern void* func_00493b60(void* layout);
extern void* func_00494be0(void);
extern void* func_00494cc0(void* colorData);
extern void* func_0049c1b0(RpWorld* world, RwCamera* camera);
extern void* func_004d0f00(void* texture);
extern void* func_004cb750(RwFrame* frame, const RwV3d* translation, RwOpCombineType combineOp);
extern void* func_00491a80(void* renderObject);
extern void func_003176c0(Model* model);
extern void func_00318b90(Model* model);
extern u32 func_00319010(Model* model);
extern u32 mdlStreamRead(Model* model);
extern void func_004c2cc0(void* quaternion);
extern void func_004c2d20(RwMatrix* matrix, const void* quaternion);
extern void func_004c2f10(RwMatrix* matrix);

extern void* func_00464020(void* collisionWorld, void* query, void* callback, void* context);
extern void* func_004916d0(void* list, void* callback, void* context);
#pragma alias K_Field_Get_A K_Field_Get
extern void* K_Field_Get_A(void);
#pragma alias K_Field_Get_B K_Field_Get
extern void* K_Field_Get_B(void);
#pragma alias K_Field_Get_C K_Field_Get
extern void* K_Field_Get_C(void);
#pragma alias K_Field_Get_D K_Field_Get
extern void* K_Field_Get_D(void);
#pragma alias K_Field_Get_E K_Field_Get
extern void* K_Field_Get_E(void);
typedef struct FldShadowTriangle
{
    RwV3d normal;                 // 0x00
    u8 unk_0c[0x10];              // 0x0c
    const RwV3d* vertices[3];     // 0x1c
} FldShadowTriangle;

typedef struct FldShadowBoundsAccum
{
    RwV3d center;                 // 0x00
    f32 radius;                   // 0x0c
    s32 count;                    // 0x10
    void* largestAtomic;          // 0x14
} FldShadowBoundsAccum;

typedef struct FldShadowProjectionWork
{
    u8 vertexBuffer[0x5460];      // 0x0000
    s32 vertexCount;              // 0x5460
    s32 triangleCount;            // 0x5464
    u8 unk_5468[0x08];            // 0x5468
    RwV3d projectionNormal;       // 0x5470
    u32 unk_547c;                  // 0x547c
    RwMatrix projectionMatrix;    // 0x5480
    u8 alpha;                     // 0x54c0
    u8 unk_54c1[0x03];            // 0x54c1
    s32 depthAlpha;               // 0x54c4
    s32 flushedTriangles;         // 0x54c8
} FldShadowProjectionWork;

typedef struct FldShadowAtomicContext
{
    void* geometry;               // 0x00
    FldShadowProjectionWork* work; // 0x04
    void* atomic;                 // 0x08
} FldShadowAtomicContext;
extern void* func_00199d90(void* ignored1,
                           void* ignored2,
                           const FldShadowTriangle* triangle,
                           FldShadowProjectionWork* work);
extern u32 K_FldShadow_Draw(f32 xLeft,
                            f32 yTop,
                            f32 xRight,
                            f32 yBot,
                            f32 zBufferNear,
                            f32 recipZ,
                            const RwRGBA* topColor,
                            const RwRGBA* botColor);

static inline u8 K_FldShadow_DepthAlpha(f32 depth, u8 baseAlpha)
{
    f32 alpha;

    alpha = 1.0f - depth * depth;
    if (alpha < 0.0f)
    {
        return 0;
    }

    return (u8)(alpha * (f32)baseAlpha);
}

static inline u32 K_FldShadow_AxisHasNonNegative(f32 a, f32 b, f32 c)
{
    return a >= 0.0f || b >= 0.0f || c >= 0.0f;
}

static inline u32 K_FldShadow_AxisHasAtMostOne(f32 a, f32 b, f32 c)
{
    return a <= 1.0f || b <= 1.0f || c <= 1.0f;
}

static inline void K_FldShadow_EmitTriangle(FldShadowAtomicContext* context,
                                            const RwV3d* clipVertices,
                                            const RwV3d* outputVertices)
{
    RwIm3DVertex* output;
    s32 vertexCount;
    u8 alpha;
    RwV3d outputCopies[3];

    if (clipVertices[0].z < 0.0f && clipVertices[1].z < 0.0f && clipVertices[2].z < 0.0f)
    {
        return;
    }
    if (clipVertices[0].x < 0.0f && clipVertices[1].x < 0.0f && clipVertices[2].x < 0.0f)
    {
        return;
    }
    if (clipVertices[0].x > 1.0f && clipVertices[1].x > 1.0f && clipVertices[2].x > 1.0f)
    {
        return;
    }
    if (clipVertices[0].y < 0.0f && clipVertices[1].y < 0.0f && clipVertices[2].y < 0.0f)
    {
        return;
    }
    if (clipVertices[0].y > 1.0f && clipVertices[1].y > 1.0f && clipVertices[2].y > 1.0f)
    {
        return;
    }

    vertexCount = context->work->vertexCount;
    if (vertexCount >= 0x256)
    {
        if (func_004f1ed0(context->work, (u32)vertexCount, 0, 0x19) != NULL)
        {
            func_004f2150(3);
            func_004f1f80();
        }
        context->work->flushedTriangles++;
        context->work->vertexCount = 0;
        vertexCount = 0;
    }

    output = (RwIm3DVertex*)context->work->vertexBuffer;
    output += vertexCount;
    outputCopies[0] = outputVertices[0];
    outputCopies[1] = outputVertices[1];
    outputCopies[2] = outputVertices[2];
    output[0].objVertex = outputCopies[0];
    output[1].objVertex = outputCopies[1];
    output[2].objVertex = outputCopies[2];
    output[0].u = clipVertices[0].x;
    output[0].v = clipVertices[0].y;
    output[1].u = clipVertices[1].x;
    output[1].v = clipVertices[1].y;
    output[2].u = clipVertices[2].x;
    output[2].v = clipVertices[2].y;

    if (context->work->depthAlpha != 0)
    {
        alpha = K_FldShadow_DepthAlpha(clipVertices[0].z, context->work->alpha);
        output[0].c.color.r = alpha;
        output[0].c.color.g = alpha;
        output[0].c.color.b = alpha;
        output[0].c.color.a = alpha;

        alpha = K_FldShadow_DepthAlpha(clipVertices[1].z, context->work->alpha);
        output[1].c.color.r = alpha;
        output[1].c.color.g = alpha;
        output[1].c.color.b = alpha;
        output[1].c.color.a = alpha;

        alpha = K_FldShadow_DepthAlpha(clipVertices[2].z, context->work->alpha);
        output[2].c.color.r = alpha;
        output[2].c.color.g = alpha;
        output[2].c.color.b = alpha;
        output[2].c.color.a = alpha;
    }
    else
    {
        alpha = context->work->alpha;
        output[0].c.color.r = alpha;
        output[0].c.color.g = alpha;
        output[0].c.color.b = alpha;
        output[0].c.color.a = alpha;
        output[1].c.color.r = alpha;
        output[1].c.color.g = alpha;
        output[1].c.color.b = alpha;
        output[1].c.color.a = alpha;
        output[2].c.color.r = alpha;
        output[2].c.color.g = alpha;
        output[2].c.color.b = alpha;
        output[2].c.color.a = alpha;
    }
    context->work->vertexCount += 3;
}
static inline void K_FldShadow_EmitProjectedTriangle(
    FldShadowProjectionWork* work,
    const u8* workFields,
    const RwV3d* clipVertices,
    const RwV3d* outputVertices)
{
    RwIm3DVertex* output;
    s32 vertexCount;
    u8 alpha;
    RwV3d outputCopies[3];

    if (clipVertices[0].z < 0.0f &&
        clipVertices[1].z < 0.0f &&
        clipVertices[2].z < 0.0f)
    {
        return;
    }
    if (clipVertices[0].x < 0.0f &&
        clipVertices[1].x < 0.0f &&
        clipVertices[2].x < 0.0f)
    {
        return;
    }
    if (clipVertices[0].x > 1.0f &&
        clipVertices[1].x > 1.0f &&
        clipVertices[2].x > 1.0f)
    {
        return;
    }
    if (clipVertices[0].y < 0.0f &&
        clipVertices[1].y < 0.0f &&
        clipVertices[2].y < 0.0f)
    {
        return;
    }
    if (clipVertices[0].y > 1.0f &&
        clipVertices[1].y > 1.0f &&
        clipVertices[2].y > 1.0f)
    {
        return;
    }

    vertexCount = work->vertexCount;
    if (vertexCount >= 0x256)
    {
        if (func_004f1ed0(work, (u32)vertexCount, 0, 0x19) != NULL)
        {
            func_004f2150(3);
            func_004f1f80();
        }
        work->flushedTriangles++;
        work->vertexCount = 0;
        vertexCount = 0;
    }

    output = (RwIm3DVertex*)work->vertexBuffer;
    output += vertexCount;
    outputCopies[0] = outputVertices[0];
    outputCopies[1] = outputVertices[1];
    outputCopies[2] = outputVertices[2];
    output[0].objVertex = outputCopies[0];
    output[1].objVertex = outputCopies[1];
    output[2].objVertex = outputCopies[2];
    output[0].u = clipVertices[0].x;
    output[0].v = clipVertices[0].y;
    output[1].u = clipVertices[1].x;
    output[1].v = clipVertices[1].y;
    output[2].u = clipVertices[2].x;
    output[2].v = clipVertices[2].y;

    if (*(const s32*)(workFields + 0x54) != 0)
    {
        alpha = K_FldShadow_DepthAlpha(
            clipVertices[0].z, *(const u8*)(workFields + 0x50));
        output[0].c.color.r = alpha;
        output[0].c.color.g = alpha;
        output[0].c.color.b = alpha;
        output[0].c.color.a = alpha;

        alpha = K_FldShadow_DepthAlpha(
            clipVertices[1].z, *(const u8*)(workFields + 0x50));
        output[1].c.color.r = alpha;
        output[1].c.color.g = alpha;
        output[1].c.color.b = alpha;
        output[1].c.color.a = alpha;

        alpha = K_FldShadow_DepthAlpha(
            clipVertices[2].z, *(const u8*)(workFields + 0x50));
        output[2].c.color.r = alpha;
        output[2].c.color.g = alpha;
        output[2].c.color.b = alpha;
        output[2].c.color.a = alpha;
    }
    else
    {
        alpha = *(const u8*)(workFields + 0x50);
        output[0].c.color.r = alpha;
        output[0].c.color.g = alpha;
        output[0].c.color.b = alpha;
        output[0].c.color.a = alpha;
        output[1].c.color.r = alpha;
        output[1].c.color.g = alpha;
        output[1].c.color.b = alpha;
        output[1].c.color.a = alpha;
        output[2].c.color.r = alpha;
        output[2].c.color.g = alpha;
        output[2].c.color.b = alpha;
        output[2].c.color.a = alpha;
    }
    work->vertexCount = vertexCount + 3;
}




/* W377: stacking opt_loop_invariants on and opt_propagation off improves func_0019a420 (nd1122 -> nd1083; object 1748/1808). */



typedef struct
{
    RwRGBA col1;
    RwRGBA col2;
    RwRGBA col3;
    RwRGBA col4;
} ShadowColors;

// 00678960
static ShadowColors gShadowColors =
{
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 255},
    {0, 0, 0, 255}
};

//
// to help visualizing:
//
// (xLeft, yTop)  [0] --------- [2] (xRigth, yTop)
//                |   \           |
//                |     \         |
//                |       \       |
//                |         \     |
//                |           \   |
// (xLeft, yBot)  [1] --------- [3]  (xRight, yBot)

#define FLDSHADOW_RING_COLOR ((const RwRGBA*)0x007cc140)
extern f32 fGpffff8214;
#define FLDSHADOW_RING_ANGLE_STEP fGpffff8214

static void K_FldShadow_SubmitFieldResource(ResrcFld* field,
                                             const RwV3d* position,
                                             FldShadowProjectionWork* work)
{
    u8* collisionData;
    void* collisionWorld;
    u32 collisionCount;
    u32 i;

    if (field == NULL || field->unk_160 == NULL)
    {
        return;
    }

    collisionData = (u8*)field->unk_160;
    collisionWorld = *(void**)(collisionData + 0x10);
    if (collisionWorld != NULL)
    {
        func_00464020(collisionWorld, (void*)position, (void*)func_00199d90, work);
        return;
    }

    collisionCount = *(u32*)(collisionData + 0x14);
    for (i = 0; i < collisionCount; i++)
    {
        func_00464020(*(void**)(collisionData + 0x18 + i * sizeof(void*)),
                      (void*)position, (void*)func_00199d90, work);
    }
}

static void K_FldShadow_SubmitFieldGeometry(const RwV3d* position,
                                             FldShadowProjectionWork* work,
                                             s32 drawAll)
{
    ResrcFld* field;
    ResrcFld* fields[5];
    u16 resourceIds[5];
    u8* gridCell;
    ResrcModelChar* gridModel;
    KwlnTask* collisionTask;
    s32 xGrid;
    s32 zGrid;
    s32 fieldCount;
    s32 i;
    s32 j;

    field = (ResrcFld*)MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    if (field == NULL)
    {
        return;
    }

    fieldCount = 0;
    if ((drawAll != 0) &&
        ((K_Scene_001a0250() == 1) ||
         ((gMtScene->fldMajorId > 0x32) && (gMtScene->fldMajorId < 0x3b)) ||
         ((gMtScene->fldMajorId > 0x46) && (gMtScene->fldMajorId < 0x4f))))
    {
        gridModel = (ResrcModelChar*)MT_Scene_GetRes(0x400);
        collisionTask = gridModel != NULL ? gridModel->collisCtlTask : NULL;
        xGrid = collisionTask != NULL ? K_FldFrame_CtlGetXGrid(collisionTask) : 0;
        zGrid = collisionTask != NULL ? K_FldFrame_CtlGetZGrid(collisionTask) : 0;
        gridCell = (u8*)K_Field_Get() + 0x4c + zGrid * 0x100 + xGrid * 0x10;

        resourceIds[0] = *(u16*)(gridCell + 0x4c);
        resourceIds[1] = *(u16*)(gridCell + 0x5c);
        resourceIds[2] = *(u16*)(gridCell + 0x3c);
        resourceIds[3] = *(u16*)(gridCell - 0xb4);
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < fieldCount; j++)
            {
                if (resourceIds[i] == resourceIds[j])
                {
                    break;
                }
            }
            if (j == fieldCount)
            {
                fields[fieldCount] = (ResrcFld*)MT_Scene_GetRes(resourceIds[i]);
                if (fields[fieldCount] != NULL)
                {
                    fieldCount++;
                }
            }
        }
    }
    else
    {
        fields[0] = field;
        fieldCount = 1;
    }

    for (i = 0; i < fieldCount; i++)
    {
        K_FldShadow_SubmitFieldResource(fields[i], position, work);
    }
}

/* Removing this worsens FUN_0019ab80 (nd1126 -> nd1129) - measured W161. */

#pragma opt_loop_invariants reset
#pragma opt_lifetimes reset
/* W417 negative: rewriting the mode if-chain as a switch grew this object to 1092 bytes beyond its 1088-byte window (nd747); rejected. */
// FUN_0019beb0 NONMATCHING
KwlnTask* K_FldShadow_CreateRenderTexTask(KwlnTask* parent, u16 resTypeId, s32 param_3)
{
    s32 sourceIndex;
    KwlnTask* task;
    FldShadowRenderTex* shadow;
    Resrc* source;
    RwV3d sourcePosition;

    sourceIndex = 0;
    shadow = (FldShadowRenderTex*)ShadowCalloc(1, sizeof(FldShadowRenderTex),
                                               rwMEMHINTDUR_GLOBAL);
    if (shadow == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent, "renderTex for shadow", 4171, func_0019b2b0, func_0019bcf0, shadow);
    shadow->resTypeId = resTypeId;
    shadow->mode = (u16)param_3;

    source = MT_Scene_GetResListHead(RESRC_TYPE_19);
    while (source != NULL)
    {
        sourcePosition = *(const RwV3d*)((const u8*)source + sizeof(Resrc));

        if (sourceIndex == 0)
        {
            shadow->sourcePosition = sourcePosition;
        }
        else if (sourceIndex == 1)
        {
            f32 xDistance;
            f32 zDistance;

            xDistance = shadow->sourcePosition.x - sourcePosition.x;
            if (xDistance < 0.0f)
            {
                xDistance = -xDistance;
            }

            zDistance = shadow->sourcePosition.z - sourcePosition.z;
            if (zDistance < 0.0f)
            {
                zDistance = -zDistance;
            }

            if (xDistance > zDistance)
            {
                shadow->projectionAxis.x = 0.0f;
                shadow->projectionAxis.y = 0.0f;
                shadow->projectionAxis.z = 1.0f;
            }
            else
            {
                shadow->projectionAxis.x = 1.0f;
                shadow->projectionAxis.y = 0.0f;
                shadow->projectionAxis.z = 0.0f;
            }

            shadow->mode = 4;
        }

        sourceIndex++;
        source = source->next;
    }

    switch (shadow->mode)
    {
        case 1:
            shadow->texture = func_004d0e40(NULL);
            if (shadow->texture == NULL)
            {
                K_Assert("k_shadow.c", 1517);
            }

            *(u32*)((u8*)shadow->texture + 0x50) =
                (*(u32*)((u8*)shadow->texture + 0x50) & ~0x000000ff) | 0x00000002;
            *(u32*)((u8*)shadow->texture + 0x50) =
                (*(u32*)((u8*)shadow->texture + 0x50) & ~0x0000ff00) | 0x00003300;

            shadow->raster = RwRasterCreate(128, 128, 32, rwRASTERTYPECAMERATEXTURE | rwRASTERFORMAT8888);
            if (shadow->raster != NULL)
            {
                func_004f1780(shadow->raster, true);
            }

            func_004d0be0(shadow->texture, shadow->raster);
            shadow->camera = func_004ca090();
            if (shadow->camera != NULL)
            {
                func_004d1840(shadow->camera, func_004caf10());
                func_004cb930((RwFrame*)shadow->camera->object.object.parent,
                              FLDSHADOW_CAMERA_OFFSET,
                              rwCOMBINEREPLACE);

                if (shadow->camera->object.object.parent != NULL)
                {
                    shadow->camera->zBuffer = RwRasterCreate(128, 128, 0, rwRASTERTYPEZBUFFER);
                    RwCameraSetProjectionType(shadow->camera, (RwCameraProjection)2);
                }
            }
            else
            {
                func_00199c60(shadow->camera);
            }

            func_0049c160(kwlnGetWorld(gCurrWorldIdx), shadow->camera);
            shadow->camera->frameBuffer = shadow->raster;
            shadow->unk_48 = ShadowCalloc(1, 0x54d0, rwMEMHINTDUR_GLOBAL);
            break;

        case 4:
        case 3:
            shadow->radius = (f32*)ShadowCalloc(1, sizeof(RwV3d),
                                                 rwMEMHINTDUR_GLOBAL);
            shadow->radius[0] = 30.0f;
            break;
    }

    if (RESRC_GET_TYPE(resTypeId) == RESRC_TYPE_MODELCHAR)
    {
        source = MT_Scene_GetRes(resTypeId);
        shadow->res = source;
        if (source == NULL)
        {
            K_Assert("k_shadow.c", 1546);
        }

        shadow->model = ((ResrcModelChar*)source)->mdl;
    }
    else if (RESRC_GET_TYPE(resTypeId) == RESRC_TYPE_MODELNPC)
    {
        source = MT_Scene_GetRes(resTypeId);
        shadow->res = source;
        if (source == NULL)
        {
            K_Assert("k_shadow.c", 1555);
        }

        shadow->model = ((ResrcModelChar*)source)->mdl;
    }

    return task;
}

extern void* func_004916d0(void* list, void* callback, void* context);

typedef struct FldShadowRingWork
{
    f32 radius;       // 0x00
    void* renderObject; // 0x04
    void* colorData;   // 0x08
} FldShadowRingWork;

static void K_FldShadow_FillRingVertices(void* layout, f32 radius)
{
    void* geometry;
    f32* vertices;
    u16* indices;
    f32 angle;
    s32 i;

    geometry = *(void**)((u8*)layout + 0x5c);
    vertices = geometry != NULL ? *(f32**)((u8*)geometry + 0x14) : NULL;
    indices = *(u16**)((u8*)layout + 0x2c);
    if (vertices == NULL || indices == NULL)
    {
        return;
    }

    vertices[0] = 0.0f;
    vertices[1] = 5.0f;
    vertices[2] = 0.0f;
    angle = 0.0f;
    for (i = 0; i < 32; i++)
    {
        f32* vertex;
        u16* index;

        vertex = &vertices[(i + 1) * 3];
        vertex[0] = radius * cosf(angle);
        vertex[1] = 5.0f;
        vertex[2] = radius * sinf(angle);
        index = (u16*)((u8*)indices + i * 8);
        func_00493210(layout, index, 0, (u16)(i + 2), (u16)(i + 1));
        angle += FLDSHADOW_RING_ANGLE_STEP;
    }

    vertices[99] = radius;
    vertices[100] = 5.0f;
    vertices[101] = 0.0f;
}

static void K_FldShadow_CreateRing(FldShadowRenderTex* shadow)
{
    FldShadowRingWork* ring;
    void* layout;
    void* geometry;
    u8* colors;
    f32 bounds[4];
    RwFrame* frame;
    s32 i;

    ring = (FldShadowRingWork*)shadow->radius;
    if (ring == NULL)
    {
        return;
    }

    ring->colorData = func_00494be0();
    if (ring->colorData != NULL)
    {
        *(RwRGBA*)((u8*)ring->colorData + 4) = *FLDSHADOW_RING_COLOR;
    }

    layout = func_00493710(0x22, 0x20, 0x4a);
    if (layout == NULL)
    {
        return;
    }

    for (i = 0; i < 32; i++)
    {
        u16* index;

        index = (u16*)((u8*)*(void**)((u8*)layout + 0x2c) + i * 8);
        func_00493210(layout, index, 0, (u16)(i + 2), (u16)(i + 1));
        func_00493230(layout, index, ring->colorData);
    }

    colors = *(u8**)((u8*)layout + 0x30);
    if (colors != NULL)
    {
        colors[0] = 0;
        colors[1] = 0;
        colors[2] = 0;
        colors[3] = 0x80;
        memset(colors + 4, 0, 0x84);
    }

    K_FldShadow_FillRingVertices(layout, ring->radius);
    func_004933d0(layout);

    geometry = *(void**)((u8*)layout + 0x5c);
    if (geometry != NULL)
    {
        func_00492e20(geometry, bounds);
        *(f32*)((u8*)geometry + 4) = bounds[0];
        *(f32*)((u8*)geometry + 8) = bounds[1];
        *(f32*)((u8*)geometry + 0xc) = bounds[2];
        *(f32*)((u8*)geometry + 0x10) = bounds[3];
    }

    ring->renderObject = func_00491880();
    if (ring->renderObject != NULL)
    {
        func_004919b0(ring->renderObject, layout, 0);
    }
    func_00493b60(layout);

    if (ring->renderObject != NULL)
    {
        frame = (RwFrame*)*(void**)((u8*)ring->renderObject + 4);
        if (frame == NULL)
        {
            frame = func_004caf10();
            if (frame != NULL)
            {
                func_00492d10(ring->renderObject, frame);
            }
        }
        if (frame != NULL)
        {
            ((void (*)(RwFrame*))func_004cb930)(frame);
        }
    }
}

static void K_FldShadow_RenderRing(FldShadowRenderTex* shadow)
{
    FldShadowRingWork* ring;
    RwFrame* frame;
    RwCamera* camera;
    RwV3d position;
    void (*render)(void*);

    ring = (FldShadowRingWork*)shadow->radius;
    if (ring == NULL || ring->renderObject == NULL || shadow->model == NULL)
    {
        return;
    }

    frame = (RwFrame*)*(void**)((u8*)ring->renderObject + 4);
    if (frame == NULL)
    {
        return;
    }

    position = mdlGetMatrix(shadow->model)->pos;
    func_004cb750(frame, &position, rwCOMBINEREPLACE);
    camera = kwlnGetMainCamera();
    if (RwCameraBeginUpdate(camera) == NULL)
    {
        return;
    }

    D_00960090(7, 2);
    D_00960090(6, 1);
    D_00960090(8, 0);
    D_00960090(14, 0);
    RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)0x44);
    RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)0x717fb);
    render = *(void (**)(void*))((u8*)ring->renderObject + 0x48);
    if (render != NULL)
    {
        render(ring->renderObject);
    }
    if (gFogEnabled == 1)
    {
        D_00960090(14, 0);
    }
    RwCameraEndUpdate(camera);
}



// FUN_0019c2f0
void func_0019c2f0(KwlnTask* renderTexTask, void* value)
{
    FldShadowRenderTex* shadow;

    shadow = (FldShadowRenderTex*)renderTexTask->workData;
    shadow->unk_04 = (u32)(uintptr_t)value;
}

// FUN_0019c300
u16 func_0019c300(KwlnTask* renderTexTask)
{
    return ((FldShadowRenderTex*)renderTexTask->workData)->mode;
}

// FUN_0019c310
void func_0019c310(KwlnTask* renderTexTask, u16 mode)
{
    ((FldShadowRenderTex*)renderTexTask->workData)->mode = mode;
}

// FUN_0019c320
void func_0019c320(KwlnTask* renderTexTask, f32 radius)
{
    FldShadowRenderTex* shadow;
    void* layout;
    void* geometry;
    f32* vertices;
    f32* vertex;
    f32 ringAngle;
    s32 i;

    shadow = (FldShadowRenderTex*)renderTexTask->workData;
    if (shadow->radius == NULL)
    {
        return;
    }

    ((FldShadowRingWork*)shadow->radius)->radius = radius;
    if (((FldShadowRingWork*)shadow->radius)->renderObject == NULL)
    {
        return;
    }

    layout = *(void**)((u8*)((FldShadowRingWork*)shadow->radius)->renderObject + 0x18);
    func_00493370(layout, 0xfff);
    geometry = *(void**)((u8*)layout + 0x5c);
    vertices = *(f32**)((u8*)geometry + 0x14);
    vertices[0] = 0.0f;
    vertices[1] = 5.0f;
    vertices[2] = 0.0f;
    ringAngle = 0.0f;
    for (i = 0; i < 0x20; i++)
    {
        vertex = vertices + i * 3;
        vertex[3] = ((FldShadowRingWork*)shadow->radius)->radius * cosf(ringAngle);
        vertex[4] = 5.0f;
        vertex[5] = ((FldShadowRingWork*)shadow->radius)->radius * sinf(ringAngle);
        ringAngle += FLDSHADOW_RING_ANGLE_STEP;
    }
    vertices[i * 3 + 3] =
        ((FldShadowRingWork*)shadow->radius)->radius * cosf(0.0f);
    vertices[i * 3 + 4] = 5.0f;
    vertices[i * 3 + 5] =
        ((FldShadowRingWork*)shadow->radius)->radius * sinf(0.0f);

    func_004933d0(layout);
}

// FUN_0019c490
f32 func_0019c490(KwlnTask* renderTexTask)
{
    FldShadowRenderTex* shadow = (FldShadowRenderTex*)renderTexTask->workData;
    f32 radius = 0.0f;

    if (shadow->radius != NULL)
    {
        radius = *shadow->radius;
    }
    return radius;
}

#define K_FldShadow_SetAttachedShadowEnabled(model_, enabled_)                                            \
    do                                                                                                     \
    {                                                                                                      \
        s32 i;                                                                                             \
                                                                                                           \
        for (i = 0; i < 5; i++)                                                                            \
        {                                                                                                  \
            if ((enabled_) != 0)                                                                           \
            {                                                                                              \
                (model_)->attachedWpns[i].flags |= 1;                                                     \
            }                                                                                              \
            else                                                                                           \
            {                                                                                              \
                (model_)->attachedWpns[i].flags &= ~1;                                                    \
            }                                                                                              \
        }                                                                                                  \
    } while (false)

#define K_FldShadow_UsesCharRenderGuard(model_)                                                           \
    ((model_)->type == MODEL_TYPE_BTLCHAR &&                                                              \
     ((model_)->id == 2 || (model_)->id == 4 || (model_)->id == 5 ||                                     \
      (model_)->id == 7 || (model_)->id == 8))

#define K_FldShadow_PositionCamera(shadow_, direction_, modelPosition_, useCustom_, fallback_)         \
    do                                                                                                  \
    {                                                                                                   \
        RwFrame* cameraFrame;                                                                           \
        RwMatrixTolerance tolerance;                                                                    \
        RwV2d viewWindow;                                                                               \
        RwV3d translation;                                                                              \
        RwMatrix* ltm;                                                                                  \
        f32 scale;                                                                                      \
        f32 neg;                                                                                      \
                                                                                                        \
        cameraFrame = (RwFrame*)(shadow_)->camera->object.object.parent;                               \
        if ((useCustom_) != 0)                                                                          \
        {                                                                                               \
            cameraFrame->modelling.right = (direction_)->right;                                      \
            cameraFrame->modelling.up = (direction_)->up;                                            \
            cameraFrame->modelling.at = (direction_)->at;                                             \
            RwEngineGetMatrixTolerances(&tolerance);                                                   \
            RwMatrixOptimize(&cameraFrame->modelling, &tolerance);                                     \
            RwMatrixUpdate(&cameraFrame->modelling);                                                   \
        }                                                                                               \
        else                                                                                            \
        {                                                                                               \
            cameraFrame->modelling = *((fallback_)());                                                \
            RwEngineGetMatrixTolerances(&tolerance);                                                   \
            RwMatrixOptimize(&cameraFrame->modelling, &tolerance);                                     \
            RwMatrixUpdate(&cameraFrame->modelling);                                                   \
        }                                                                                               \
                                                                                                        \
        scale = FLDSHADOW_VIEW_SCALE * (shadow_)->projectionDistance;                                 \
        func_004c9db0((shadow_)->camera, 10.0f * scale);                                               \
        func_004c9d70((shadow_)->camera, FLDSHADOW_FAR_SCALE * scale);                                \
                                                                                                        \
        if (func_001a01c0() == 1)                                                                       \
        {                                                                                                \
            viewWindow.x = 2.0f * scale;                                                               \
            viewWindow.y = 2.0f * scale;                                                               \
        }                                                                                                \
        else                                                                                             \
        {                                                                                                \
            viewWindow.x = FLDSHADOW_FAR_SCALE * scale;                                                \
            viewWindow.y = FLDSHADOW_FAR_SCALE * scale;                                                \
        }                                                                                                \
        RwCameraSetViewWindow((shadow_)->camera, &viewWindow);                                          \
                                                                                                         \
        neg = -cameraFrame->modelling.pos.x;                                                            \
        translation.x = (modelPosition_)->x + neg;                                                     \
        neg = -cameraFrame->modelling.pos.y;                                                            \
        translation.y = (modelPosition_)->y + ((shadow_)->projectionDistance / 2.0f) + neg;            \
        neg = -cameraFrame->modelling.pos.z;                                                            \
        translation.z = (modelPosition_)->z + neg;                                                     \
        translation.x += cameraFrame->modelling.at.x * ((shadow_)->camera->farPlane * -0.5f);         \
        translation.y += cameraFrame->modelling.at.y * ((shadow_)->camera->farPlane * -0.5f);         \
        translation.z += cameraFrame->modelling.at.z * ((shadow_)->camera->farPlane * -0.5f);         \
                                                                                                         \
        func_004cb750(cameraFrame, &translation, rwCOMBINEPOSTCONCAT);                                 \
        ltm = RwFrameGetLTM(cameraFrame);                                                               \
        func_004c2fb0(ltm, ltm);                                                                        \
    } while (false)

#define K_FldShadow_DrawMapBands(camera_, drawMiddle_)                                                    \
    do                                                                                                     \
    {                                                                                                      \
        f32 recipZ;                                                                                        \
                                                                                                           \
        RwRenderStateSet(rwRENDERSTATEFOGENABLE, (void*)false);                                           \
        RwRenderStateSet(rwRENDERSTATEZTESTENABLE, (void*)false);                                         \
        RwRenderStateSet(rwRENDERSTATEZWRITEENABLE, (void*)false);                                        \
        RwRenderStateSet(rwRENDERSTATESHADEMODE, (void*)rwSHADEMODEGOURAUD);                              \
        RwRenderStateSet(rwRENDERSTATETEXTURERASTER, NULL);                                               \
        RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)0x44);                                        \
        RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)0x717fb);                                    \
                                                                                                           \
        recipZ = 1.0f / (camera_)->nearPlane;                                                             \
        K_FldShadow_Draw(0.0f, 0.0f, 128.0f, 48.0f, RwIm2DGetNearScreenZ(), recipZ,                       \
                         &gShadowColors.col1, &gShadowColors.col2);                                      \
                                                                                                           \
        if ((drawMiddle_) != 0)                                                                           \
        {                                                                                                 \
            RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)0x44);                                    \
            RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)0x3c803);                                \
            K_FldShadow_Draw(0.0f, 48.0f, 128.0f, 76.0f, RwIm2DGetNearScreenZ(), recipZ,                  \
                             &gShadowColors.col2, &gShadowColors.col3);                                  \
        }                                                                                                 \
        K_FldShadow_Draw(0.0f, 76.0f, 128.0f, 128.0f, RwIm2DGetNearScreenZ(), recipZ,                     \
                         &gShadowColors.col3, &gShadowColors.col4);                                      \
                                                                                                           \
        RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)0x44);                                        \
        RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)0x717fb);                                    \
        RwRenderStateSet(rwRENDERSTATECULLMODE, (void*)rwCULLMODECULLBACK);                               \
    } while (false)

#define K_FldShadow_RenderModelInline(shadow_, direction_, modelPosition_, useCustom_, fallback_, tintModel_, useCharRenderGuard_) \
    do                                                                                                     \
    {                                                                                                      \
        RwRGBA originalColor;                                                                              \
                                                                                                           \
        K_FldShadow_PositionCamera((shadow_), (direction_), (modelPosition_), (useCustom_), (fallback_)); \
        RwCameraClear((shadow_)->camera, FLDSHADOW_CLEAR_COLOR, rwCAMERACLEAR1 | rwCAMERACLEARZ);         \
                                                                                                           \
        if (RwCameraBeginUpdate((shadow_)->camera) == NULL)                                               \
        {                                                                                                  \
            K_Assert("k_shadow.c", (tintModel_) != 0 ? 1903 : 2032);                                    \
            return;                                                                                        \
        }                                                                                                  \
                                                                                                           \
        if ((tintModel_) != 0)                                                                             \
        {                                                                                                  \
            originalColor = *mdlGetColor((shadow_)->model);                                               \
            mdlSetColor((shadow_)->model, &FLDSHADOW_TINT);                                               \
        }                                                                                                  \
                                                                                                           \
        K_FldShadow_SetAttachedShadowEnabled((shadow_)->model, false);                                    \
        FLDSHADOW_RENDER_ACTIVE = true;                                                                    \
        if ((useCharRenderGuard_) != 0 && K_FldShadow_UsesCharRenderGuard((shadow_)->model) != 0)         \
        {                                                                                                  \
            FLDSHADOW_CHAR_RENDER_GUARD = false;                                                          \
        }                                                                                                  \
                                                                                                           \
        (shadow_)->model->flags |= FLDSHADOW_MODEL_FLAGS_SHADOWPASS;                                     \
        func_00317a20((shadow_)->model);                                                                   \
        (shadow_)->model->flags &= ~FLDSHADOW_MODEL_FLAGS_SHADOWPASS;                                    \
                                                                                                           \
        if ((useCharRenderGuard_) != 0)                                                                    \
        {                                                                                                  \
            FLDSHADOW_CHAR_RENDER_GUARD = true;                                                           \
        }                                                                                                  \
        FLDSHADOW_RENDER_ACTIVE = false;                                                                   \
        K_FldShadow_SetAttachedShadowEnabled((shadow_)->model, true);                                     \
                                                                                                           \
        if ((tintModel_) != 0)                                                                             \
        {                                                                                                  \
            mdlSetColor((shadow_)->model, &originalColor);                                                \
        }                                                                                                  \
                                                                                                           \
        K_FldShadow_DrawMapBands((shadow_)->camera, (useCharRenderGuard_));                              \
        if (gFogEnabled == true)                                                                           \
        {                                                                                                  \
            RwRenderStateSet(rwRENDERSTATEFOGENABLE, (void*)false);                                      \
        }                                                                                                  \
        RwCameraEndUpdate((shadow_)->camera);                                                             \
    } while (false)


static inline void K_FldShadow_UpdateModelChar(ResrcModelChar* res)
{
    FldShadowRenderTex* shadow;
    RwV3d modelPosition;
    const RwMatrix* direction;

    if ((res->base.flags & FLDSHADOW_RESOURCE_FLAGS_DRAW) == 0)
    {
        return;
    }

    shadow = (FldShadowRenderTex*)res->renderTexShadowTask->workData;
    if (shadow->mode != 1 || shadow->state <= 0)
    {
        return;
    }

    modelPosition = mdlGetMatrix(res->mdl)->pos;
    if (res->base.flags & FLDSHADOW_RESOURCE_FLAGS_MATRIX)
    {
        direction = (const RwMatrix*)((const u8*)res + 0x150);
    }

    K_FldShadow_RenderModelInline(shadow, direction, &modelPosition,
                                  (res->base.flags & FLDSHADOW_RESOURCE_FLAGS_MATRIX) != 0,
                                  func_001a0a50, true, true);
}

static inline void K_FldShadow_UpdateModelNpc(ResrcModelNpc* res)
{
    FldShadowRenderTex* shadow;
    RwV3d modelPosition;
    const RwMatrix* direction;

    if ((res->base.flags & FLDSHADOW_RESOURCE_FLAGS_DRAW) == 0)
    {
        return;
    }

    shadow = (FldShadowRenderTex*)res->renderTexShadowTask->workData;
    if (shadow->mode != 1 || shadow->state <= 0)
    {
        return;
    }

    modelPosition = mdlGetMatrix(res->mdl)->pos;
    if (res->base.flags & FLDSHADOW_RESOURCE_FLAGS_MATRIX)
    {
        direction = (const RwMatrix*)((const u8*)res + 0x150);
    }

    K_FldShadow_RenderModelInline(shadow, direction, &modelPosition,
                                  (res->base.flags & FLDSHADOW_RESOURCE_FLAGS_MATRIX) != 0,
                                  func_001a0d80, false, false);
}

#undef K_FldShadow_RenderModelInline
#undef K_FldShadow_DrawMapBands
#undef K_FldShadow_PositionCamera
#undef K_FldShadow_UsesCharRenderGuard
#undef K_FldShadow_SetAttachedShadowEnabled
/* W377: opt_dead_assignments off improves K_FldShadow_UpdateShadowMapTask (nd2297 -> nd2260; object 3520/3520). */
#pragma opt_dead_assignments off
// FUN_0019c4b0 NONMATCHING
void* K_FldShadow_UpdateShadowMapTask(KwlnTask* fldShadowMapTask)
{
    FldShadowMap* shadowMap;
    ResrcModelChar* character;
    ResrcModelNpc* npc;
    u8 directionalLightFlags;
    u8 secondaryLightFlags;
    u8 ambientLightFlags;

    shadowMap = (FldShadowMap*)fldShadowMapTask->workData;
    character = (ResrcModelChar*)MT_Scene_GetResListHead(RESRC_TYPE_MODELCHAR);
    npc = (ResrcModelNpc*)MT_Scene_GetResListHead(RESRC_TYPE_MODELNPC);

    switch (shadowMap->state)
    {
        case FLDSHADOWMAP_STATE_INIT:
            shadowMap->state++;
            break;

        case FLDSHADOWMAP_STATE_DRAW:
            directionalLightFlags = kwlnGetDirectionalLight()->object.object.flags;
            kwlnGetDirectionalLight()->object.object.flags = 0;
            kwlnGetDirectionalLight();
            secondaryLightFlags = func_00198580()->object.object.flags;
            func_00198580()->object.object.flags = 0;
            func_00198580();
            ambientLightFlags = kwlnGetAmbientLight()->object.object.flags;
            kwlnGetAmbientLight()->object.object.flags = 0;
            kwlnGetAmbientLight();

            while (character != NULL)
            {
                K_FldShadow_UpdateModelChar(character);
                character = (ResrcModelChar*)character->base.next;
            }

            while (npc != NULL)
            {
                K_FldShadow_UpdateModelNpc(npc);
                npc = (ResrcModelNpc*)npc->base.next;
            }

            kwlnGetDirectionalLight()->object.object.flags = directionalLightFlags;
            kwlnGetDirectionalLight();
            func_00198580()->object.object.flags = secondaryLightFlags;
            func_00198580();
            kwlnGetAmbientLight()->object.object.flags = ambientLightFlags;
            kwlnGetAmbientLight();
            break;

        case FLDSHADOWMAP_STATE_STOP:
            return KWLNTASK_STOP;
    }

    return KWLNTASK_CONTINUE;
}
#pragma opt_dead_assignments reset

// FUN_0019d270
void K_FldShadow_DestroyShadowMapTask(KwlnTask* fldShadowMapTask)
{
    RwFree(fldShadowMapTask->workData);
}

// FUN_0019d2a0
KwlnTask* K_FldShadow_CreateShadowMapTask(KwlnTask* fldSceneDrawTask)
{
    FldShadowMap* fldShadowMap;

    fldShadowMap = (FldShadowMap*)RwCalloc(1, sizeof(FldShadowMap), rwMEMHINTDUR_GLOBAL);
    if (fldShadowMap == NULL)
    {
        return NULL;
    }

    return kwlnTaskCreate(fldSceneDrawTask, "shadow map camera", 2068, K_FldShadow_UpdateShadowMapTask, K_FldShadow_DestroyShadowMapTask, fldShadowMap);
}

// FUN_0019d320
s32 FUN_0019d320()
{
    volatile u64* intcStat;

    intcStat = (volatile u64*)0x12001000;
    if (((*intcStat >> 13) & 1) == 0)
    {
        __asm__ volatile (
            ".set noreorder\n"
            "sync\n"
            "ei\n"
            ".set reorder"
            :
            :
            : "memory"
        );
        return -1;
    }

    __asm__ volatile (
        ".set noreorder\n"
        "sync\n"
        "ei\n"
        ".set reorder"
        :
        :
        : "memory"
    );
    return 0;
}

// FUN_0019d360
s32 func_0019d360()
{
    s32 handle;

    handle = AddIntcHandler(2, (s32 (*)(s32))FUN_0019d320, 0);
    DAT_007cc148 = handle;
    if (handle == -1)
    {
        return 0;
    }

    handle = EnableIntc(2);
    DAT_007ce13c = handle;
    if (handle == -1)
    {
        RemoveIntcHandler(2, DAT_007cc148);
        DAT_007cc148 = -1;
        return 0;
    }

    return 1;
}