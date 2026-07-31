#include "Kosaka/k_spipe.h"
#include "Kosaka/k_assert.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwln.h"
#include "Main/g_data.h"
#include "rw/rwcore.h"
#include "temporary.h"




extern u32 FUN_00195750(void);
extern void FUN_001a8910(u32 param);
extern u32 gUnk_008668f0[];


// FUN_00199520
void* K_SPipe_Update3DDrwBeginTask(KwlnTask* draw3DBeginTask)
{
    RwRenderStateSetFunc* setRenderState;

    if (kwlnCameraBeginUpdate() != NULL)
    {
        kwlnSetFlags(KWLN_FLAG_ERR | KWLN_FLAG_3DDRAW, false);
        kwlnSetFlags(KWLN_FLAG_3DDRAW, true);
        setRenderState = &rwGlobals.device.setRenderState;
        (*setRenderState)(rwRENDERSTATEZTESTENABLE, (void*)true);
        (*setRenderState)(rwRENDERSTATEZWRITEENABLE, (void*)true);
        FUN_00195750();
    }
    else
    {
        K_Assert("k_spipe.c", 385);
        kwlnSetFlags(KWLN_FLAG_ERR, true);
    }

    return KWLNTASK_CONTINUE;
}

// FUN_001995f0
void* K_SPipe_Update3DDrwEndTask(KwlnTask* draw3DEndTask)
{
    RwRenderStateSetFunc* setRenderState;

    setRenderState = &rwGlobals.device.setRenderState;
    (*setRenderState)(rwRENDERSTATEFOGENABLE, (void*)false);
    (*setRenderState)(rwRENDERSTATEFOGENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATEFOGCOLOR, (void*)PACK_RWRGBA(gFogRed, gFogGreen, gFogBlue, gFogAlpha));
    (*setRenderState)(rwRENDERSTATEFOGTYPE, (void*)rwFOGTYPELINEAR);

    kwlnCameraEndUpdate();

    kwlnSetFlags(KWLN_FLAG_2DDRAW | KWLN_FLAG_3DDRAW, false);

    return KWLNTASK_CONTINUE;
}

// FUN_001996c0
KwlnTask* K_SPipe_Create3DDrwBeginTask(KwlnTask* draw3DTask)
{
    return kwlnTaskCreate(draw3DTask, "3D Draw Begin", 2098, K_SPipe_Update3DDrwBeginTask, NULL, NULL);
}

// FUN_00199700
KwlnTask* K_SPipe_Create3DDrwEndTask(KwlnTask* draw3DTask)
{
    return kwlnTaskCreate(draw3DTask, "3D Draw End", 4167, K_SPipe_Update3DDrwEndTask, NULL, NULL);
}

// FUN_00199740
void* K_SPipe_UpdateShadowNodeTask(KwlnTask* shadowNodeTask)
{
    RwCameraClear(kwlnGetMainCamera(), kwlnGetClearColor(), rwCAMERACLEAR1 | rwCAMERACLEARZ);
    FUN_001a8910((u32)gUnk_008668f0);

    return KWLNTASK_CONTINUE;
}

// FUN_001997a0
KwlnTask* K_SPipe_CreateShadowNodeTask(KwlnTask* draw3DTask)
{
    return kwlnTaskCreate(draw3DTask, "shadow node(camera all clear)", 2069, K_SPipe_UpdateShadowNodeTask, NULL, NULL);
}

#include "Kosaka/Field/k_shadow.h"
#include "Graphics/Model/mdlManager.h"
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
#define FLDSHADOW_CLEAR_COLOR ((RwRGBA*)0x007ce138)
#define FLDSHADOW_TINT (*(const RwRGBA*)0x007cc144)
#define FLDSHADOW_RENDER_ACTIVE (*(u32*)0x007ce158)
#define FLDSHADOW_CHAR_RENDER_GUARD (*(u32*)0x007cc1ec)
#define FLDSHADOW_CAMERA_OFFSET ((const RwV3d*)0x00678920)
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
extern s32 DAT_007cc148;
extern s32 DAT_007ce13c;
extern void* func_004ce0f0(s32 width, s32 height, s32 depth, s32 flags);
#pragma alias jtbl_0096017C_abs jtbl_0096017C
extern u32 jtbl_0096017C_abs[];
extern void* memset(void* dest, u8 value, u32 size);
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

// FUN_00199c60
void func_00199c60(RwCamera* camera)
{
    RwFrame* frame;
    RwRaster* zBuffer;

    if (camera == NULL)
    {
        return;
    }

    frame = (RwFrame*)camera->object.object.parent;
    if (frame != NULL)
    {
        func_004d1840(camera, NULL);
        func_004caf80(frame);
    }

    zBuffer = camera->zBuffer;
    if (zBuffer != NULL)
    {
        camera->zBuffer = NULL;
        func_004cde90(zBuffer);
    }

    if (camera->frameBuffer != NULL)
    {
        camera->frameBuffer = NULL;
    }
    func_004ca030(camera);
}

// FUN_00199cf0
void* func_00199cf0(void* atomic, FldShadowBoundsAccum* accum)
{
    const RwSphere* sphere;

    sphere = func_004912b0(atomic);
    if (sphere->radius > accum->radius)
    {
        sphere = func_004912b0(atomic);
        accum->center = sphere->center;
        accum->largestAtomic = atomic;
    }
    sphere = func_004912b0(atomic);
    accum->radius += sphere->radius;
    accum->count++;
    return atomic;
}

// FUN_00199d90 NONMATCHING
void* func_00199d90(void* ignored1,
                    void* ignored2,
                    const FldShadowTriangle* triangle,
                    FldShadowProjectionWork* work)
{
    RwV3d sourceVertices[3];
    RwV3d vertices[3];
    const RwV3d* projectionNormal;
    f32 normalX;
    f32 normalY;
    f32 normalZ;

    (void)ignored1;
    (void)ignored2;
    projectionNormal = &work->projectionNormal;
    if (RwV3dDotProductMacro(&triangle->normal, projectionNormal) > 0.0f)
    {
        return (void*)triangle;
    }

    sourceVertices[0] = *triangle->vertices[0];
    sourceVertices[1] = *triangle->vertices[1];
    sourceVertices[2] = *triangle->vertices[2];
    func_004c6c20(vertices, sourceVertices, 3, &work->projectionMatrix);

    normalX = triangle->normal.x * 1.5f;
    normalY = triangle->normal.y * 1.5f;
    normalZ = triangle->normal.z * 1.5f;
    sourceVertices[0].x += normalX;
    sourceVertices[0].y += normalY;
    sourceVertices[0].z += normalZ;
    sourceVertices[1].x += normalX;
    sourceVertices[1].y += normalY;
    sourceVertices[1].z += normalZ;
    sourceVertices[2].x += normalX;
    sourceVertices[2].y += normalY;
    sourceVertices[2].z += normalZ;
    K_FldShadow_EmitProjectedTriangle(
        work, (const u8*)projectionNormal, vertices, sourceVertices);
    return (void*)triangle;
}

/* W377: stacking opt_loop_invariants on and opt_propagation off improves func_0019a420 (nd1122 -> nd1083; object 1748/1808). */
#pragma opt_loop_invariants on
#pragma opt_propagation off
// FUN_0019a420 NONMATCHING
void* func_0019a420(void* ignored,
                    const FldShadowTriangle* triangle,
                    FldShadowAtomicContext* context)
{
    RwV3d normal;
    RwV3d sourceVertices[3];
    RwV3d projected[3];
    s32 i;
    f32 normalY;
    f32 normalZ;
    const RwV3d* projectionNormal;

    (void)ignored;
    normal = triangle->normal;
    projectionNormal = &context->work->projectionNormal;
    for (i = 0; i < 3; i++)
    {
        func_004c6c20(&sourceVertices[i], triangle->vertices[i], 1,
                      func_004cb2f0(*(void**)((u8*)context->atomic + 4)));
    }
    normalY = normal.y;
    normalZ = normal.z;
    if (normal.x * projectionNormal->x +
            normalY * projectionNormal->y +
            normalZ * projectionNormal->z > 0.0f)
    {
        return (void*)triangle;
    }

    projected[0] = sourceVertices[0];
    projected[1] = sourceVertices[1];
    projected[2] = sourceVertices[2];
    func_004c6c20(projected, projected, 3,
                  &context->work->projectionMatrix);
    sourceVertices[0].x += normal.x * 1.5f;
    sourceVertices[0].y += normalY * 1.5f;
    sourceVertices[0].z += normalZ * 1.5f;
    sourceVertices[1].x += normal.x * 1.5f;
    sourceVertices[1].y += normalY * 1.5f;
    sourceVertices[1].z += normalZ * 1.5f;
    sourceVertices[2].x += normal.x * 1.5f;
    sourceVertices[2].y += normalY * 1.5f;
    sourceVertices[2].z += normalZ * 1.5f;
    K_FldShadow_EmitTriangle(context, projected, sourceVertices);
    return (void*)triangle;
}
#pragma opt_propagation reset
#pragma opt_loop_invariants reset

// FUN_0019ab30
void* func_0019ab30(void* atomic, FldShadowAtomicContext* context)
{
    context->atomic = atomic;
    func_00464120(atomic, context->geometry, func_0019a420, context);
    return atomic;
}


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
// FUN_001997e0
u32 K_FldShadow_Draw(f32 xLeft, f32 yTop,
                     f32 xRight, f32 yBot,
                     f32 zBufferNear, f32 recipZ,
                     const RwRGBA* topColor, const RwRGBA* botColor)
{
    RwIm2DVertex vertices[4];

    vertices[0].u.els.scrVertex.x = xLeft;
    vertices[0].u.els.scrVertex.y = yTop;
    vertices[0].u.els.scrVertex.z = zBufferNear;
    vertices[0].u.els.color.r = topColor->r;
    vertices[0].u.els.color.g = topColor->g;
    vertices[0].u.els.color.b = topColor->b;
    vertices[0].u.els.color.a = topColor->a;
    vertices[0].u.els.recipZ = recipZ;

    vertices[1].u.els.scrVertex.x = xLeft;
    vertices[1].u.els.scrVertex.y = yBot;
    vertices[1].u.els.scrVertex.z = zBufferNear;
    vertices[1].u.els.color.r = botColor->r;
    vertices[1].u.els.color.g = botColor->g;
    vertices[1].u.els.color.b = botColor->b;
    vertices[1].u.els.color.a = botColor->a;
    vertices[1].u.els.recipZ = recipZ;

    vertices[2].u.els.scrVertex.x = xRight;
    vertices[2].u.els.scrVertex.y = yTop;
    vertices[2].u.els.scrVertex.z = zBufferNear;
    vertices[2].u.els.color.r = topColor->r;
    vertices[2].u.els.color.g = topColor->g;
    vertices[2].u.els.color.b = topColor->b;
    vertices[2].u.els.color.a = topColor->a;
    vertices[2].u.els.recipZ = recipZ;

    vertices[3].u.els.scrVertex.x = xRight;
    vertices[3].u.els.scrVertex.y = yBot;
    vertices[3].u.els.scrVertex.z = zBufferNear;
    vertices[3].u.els.color.r = botColor->r;
    vertices[3].u.els.color.g = botColor->g;
    vertices[3].u.els.color.b = botColor->b;
    vertices[3].u.els.color.a = botColor->a;
    vertices[3].u.els.recipZ = recipZ;

    RwIm2DRenderPrimitive(rwPRIMTYPETRISTRIP, vertices, 4);

    return true;
}

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
#pragma opt_loop_invariants on
/* W377: adding opt_lifetimes on to the existing opt_loop_invariants scope improves func_0019ab80 (nd1126 -> nd1115; object 1820/1840). */
#pragma opt_lifetimes on
// FUN_0019ab80 NONMATCHING
u32 func_0019ab80(f32 alpha,
                  f32 projectionHalf,
                  RwCamera* camera,
                  RwRaster* raster,
                  s32 drawField,
                  const RwV3d* position,
                  u32 depthAlpha,
                  FldShadowProjectionWork* work)
{
    RwMatrix* projectionMatrix;
    RwV3d scale;
    RwV3d translation;
    f32 viewWidth;
    u32 count;
    RwFrame* frame;
    void (**stateSet)(u32, u32);
    ResrcFld* field;
    u8* collisionData;
    void* collisionWorld;
    u32 collisionCount;
    u32 i;
    u32 j;
    ResrcFld* fields[5];
    u16 resourceIds[5];

    field = (ResrcFld*)MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    stateSet = (void (**)(u32, u32))D_00960090_abs;
    (*stateSet)(1, (u32)(uintptr_t)raster);
    (*stateSet)(2, 3);
    (*stateSet)(12, 1);
    (*stateSet)(9, 2);
    (*stateSet)(10, 5);

    if (alpha < 0.0f)
    {
        alpha = -alpha;
        (*stateSet)(11, 5);
    }
    else
    {
        (*stateSet)(11, 6);
    }

    frame = (RwFrame*)camera->object.object.parent;
    if (frame != NULL)
    {
        work->projectionNormal = frame->modelling.pos;
        func_004c32a0(projectionMatrix, &frame->modelling);

        viewWidth = camera->viewWindow.x;
        scale.x = -0.5f / viewWidth;
        scale.y = scale.x;
        scale.z = 1.0f / (projectionHalf + viewWidth);
        RwMatrixScale(projectionMatrix, &scale, rwCOMBINEPOSTCONCAT);

        translation.x = 0.5f;
        translation.y = 0.5f;
        translation.z = 0.0f;
        RwMatrixTranslate(projectionMatrix, &translation, rwCOMBINEPOSTCONCAT);
    }

    work->depthAlpha = (s32)depthAlpha;
    alpha *= 255.0f;
    work->alpha = (u8)alpha;
    work->flushedTriangles = 0;
    work->vertexCount = 0;
    if (drawField == 0)
    {
        collisionData = (u8*)field->unk_160;
        collisionWorld = *(void**)(collisionData + 0x10);
        if (collisionWorld == NULL)
        {
            collisionWorld = *(void**)(collisionData + 0x08);
        }
        func_00464020(collisionWorld, (void*)position,
                      (void*)func_00199d90, work);
    }
    else if (drawField == 1)
    {
        u32 fieldCount;
        void* gridModel;
        KwlnTask* collisionTask;
        s32 xGrid;
        s32 zGrid;
        u8* gridCell;

        fieldCount = 0;
        if ((K_Scene_001a0250() == 1) ||
            ((gMtScene->fldMajorId > 0x32) &&
             (gMtScene->fldMajorId < 0x3b)) ||
            ((gMtScene->fldMajorId > 0x46) &&
             (gMtScene->fldMajorId < 0x4f)))
        {
            gridModel = MT_Scene_GetRes(0x400);
            collisionTask = gridModel != NULL
                ? ((ResrcModelChar*)gridModel)->collisCtlTask : NULL;
            xGrid = collisionTask != NULL
                ? K_FldFrame_CtlGetXGrid(collisionTask) : 0;
            zGrid = collisionTask != NULL
                ? K_FldFrame_CtlGetZGrid(collisionTask) : 0;

            gridCell = (u8*)K_Field_Get_A() +
                       0x4c + zGrid * 0x100 + xGrid * 0x10;
            resourceIds[0] = *(u16*)(gridCell + 0x4c);
            for (j = 0; j < fieldCount; j++)
            {
                if (resourceIds[0] == resourceIds[j])
                {
                    break;
                }
            }
            if (j == fieldCount)
            {
                fields[fieldCount] =
                    (ResrcFld*)MT_Scene_GetRes(resourceIds[0]);
                if (fields[fieldCount] != NULL)
                {
                    fieldCount++;
                }
            }

            gridCell = (u8*)K_Field_Get_B() +
                       0x4c + zGrid * 0x100 + xGrid * 0x10;
            resourceIds[1] = *(u16*)(gridCell + 0x5c);
            for (j = 0; j < fieldCount; j++)
            {
                if (resourceIds[1] == resourceIds[j])
                {
                    break;
                }
            }
            if (j == fieldCount)
            {
                fields[fieldCount] =
                    (ResrcFld*)MT_Scene_GetRes(resourceIds[1]);
                if (fields[fieldCount] != NULL)
                {
                    fieldCount++;
                }
            }

            gridCell = (u8*)K_Field_Get_C() +
                       0x4c + zGrid * 0x100 + xGrid * 0x10;
            resourceIds[2] = *(u16*)(gridCell + 0x3c);
            for (j = 0; j < fieldCount; j++)
            {
                if (resourceIds[2] == resourceIds[j])
                {
                    break;
                }
            }
            if (j == fieldCount)
            {
                fields[fieldCount] =
                    (ResrcFld*)MT_Scene_GetRes(resourceIds[2]);
                if (fields[fieldCount] != NULL)
                {
                    fieldCount++;
                }
            }

            gridCell = (u8*)K_Field_Get_D() +
                       0x4c + zGrid * 0x100 + xGrid * 0x10;
            resourceIds[3] = *(u16*)(gridCell + 0x14c);
            for (j = 0; j < fieldCount; j++)
            {
                if (resourceIds[3] == resourceIds[j])
                {
                    break;
                }
            }
            if (j == fieldCount)
            {
                fields[fieldCount] =
                    (ResrcFld*)MT_Scene_GetRes(resourceIds[3]);
                if (fields[fieldCount] != NULL)
                {
                    fieldCount++;
                }
            }

            gridCell = (u8*)K_Field_Get_E() +
                       0x4c + zGrid * 0x100 + xGrid * 0x10;
            resourceIds[4] = *(u16*)(gridCell - 0xb4);
            for (j = 0; j < fieldCount; j++)
            {
                if (resourceIds[4] == resourceIds[j])
                {
                    break;
                }
            }
            if (j == fieldCount)
            {
                fields[fieldCount] =
                    (ResrcFld*)MT_Scene_GetRes(resourceIds[4]);
                if (fields[fieldCount] != NULL)
                {
                    fieldCount++;
                }
            }
        }

        for (i = 0; i < fieldCount; i++)
        {
            collisionData = (u8*)fields[i]->unk_160;
            collisionWorld = *(void**)(collisionData + 0x10);
            if (collisionWorld != NULL)
            {
                func_004916d0(collisionWorld, (void*)func_00199d90, work);
            }
            else
            {
                collisionCount = *(u32*)(collisionData + 0x14);
                for (j = 0; j < collisionCount; j++)
                {
                    func_004916d0(
                        *(void**)(collisionData + 0x18 + j * sizeof(void*)),
                        (void*)func_00199d90, work);
                }
            }
        }
    }

    count = work->vertexCount;
    work->triangleCount = (s32)(count + work->flushedTriangles * 600) / 3;
    if (count != 0)
    {
        (*stateSet)(1, (u32)(uintptr_t)raster);
        (*stateSet)(14, 0);
        (*stateSet)(6, 1);
        (*stateSet)(8, 0);
        if (func_004f1ed0(work, count, 0, 0x19) != NULL)
        {
            func_004f2150(3);
            func_004f1f80();
        }
        if (gFogEnabled == 1)
            (*stateSet)(14, 0);
        work->vertexCount = 0;
    }

    (*stateSet)(11, 6);
    (*stateSet)(10, 5);
    return true;
}

#pragma opt_loop_invariants reset
#pragma opt_lifetimes reset

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

// FUN_0019b2b0 NONMATCHING
void* func_0019b2b0(KwlnTask* renderTexTask)
{
    FldShadowRenderTex* shadow;
    ResrcFld* field;
    FldShadowBoundsAccum bounds;
    RwCamera* camera;
    RwMatrix savedMatrix;
    RwV3d scale;
    RwV3d position;
    FldShadowRingWork* ring;
    void* layout;
    void* geometry;
    void* renderObject;
    u8* vertices;
    u8* colors;
    RwFrame* frame;
    f32 ringAngle;
    f32* vertex;
    u16* index;
    s32 i;
    void (*render)(void*);
    f32 ringBounds[4];
    RwV3d projectionBounds[2];
    f32 quaternion[4];

    shadow = (FldShadowRenderTex*)renderTexTask->workData;
    if ((shadow->res->flags & FLDSHADOW_RESOURCE_FLAGS_DRAW) == 0)
        return KWLNTASK_CONTINUE;
    if (shadow->unk_04 == 1)
        return KWLNTASK_CONTINUE;
    if (shadow->state == 2)
        return KWLNTASK_STOP;

    if (shadow->state == 0)
    {
        if (shadow->mode == 0)
        {
            shadow->state++;
            return KWLNTASK_CONTINUE;
        }
        if (shadow->mode == 2)
        {
            if (shadow->model != NULL && mdlStreamRead(shadow->model) != 0)
            {
                func_00319010(shadow->model);
                shadow->state++;
            }
            return KWLNTASK_CONTINUE;
        }
        if (shadow->mode == 3 || shadow->mode == 4)
        {
            if (shadow->model != NULL && mdlStreamRead(shadow->model) != 0)
            {
                ring = (FldShadowRingWork*)shadow->radius;
                ring->colorData = func_00494be0();
                *(RwRGBA*)((u8*)ring->colorData + 4) = *FLDSHADOW_RING_COLOR;
                layout = func_00493710(0x22, 0x20, 0x4a);
                for (i = 0; i < 0x20; i++)
                {
                    index = (u16*)((u8*)*(void**)((u8*)layout + 0x2c) + i * 8);
                    func_00493210(layout, index, 0, (u16)(i + 2), (u16)(i + 1));
                    func_00493230(layout, index, ring->colorData);
                }
                colors = *(u8**)((u8*)layout + 0x30);
                colors[0] = 0;
                colors[1] = 0;
                colors[2] = 0;
                colors[3] = 0x80;
                for (i = 0; i < 0x21; i++)
                {
                    colors[i * 4 + 4] = 0;
                    colors[i * 4 + 5] = 0;
                    colors[i * 4 + 6] = 0;
                    colors[i * 4 + 7] = 0;
                }
                geometry = *(void**)((u8*)layout + 0x5c);
                vertices = *(u8**)((u8*)geometry + 0x14);
                *(f32*)(vertices + 0) = 0.0f;
                *(f32*)(vertices + 4) = 5.0f;
                *(f32*)(vertices + 8) = 0.0f;
                ringAngle = 0.0f;
                for (i = 0; i < 0x20; i++)
                {
                    vertex = (f32*)(vertices + (i + 1) * 0x0c);
                    vertex[0] = ring->radius * cosf(ringAngle);
                    vertex[1] = 5.0f;
                    vertex[2] = ring->radius * sinf(ringAngle);
                    ringAngle += FLDSHADOW_RING_ANGLE_STEP;
                }
                *(f32*)(vertices + 99 * sizeof(f32)) =
                    ring->radius * cosf(ringAngle);
                *(f32*)(vertices + 100 * sizeof(f32)) = 5.0f;
                *(f32*)(vertices + 101 * sizeof(f32)) =
                    ring->radius * sinf(ringAngle);
                func_004933d0(layout);
                geometry = *(void**)((u8*)layout + 0x5c);
                func_00492e20(geometry, ringBounds);
                *(f32*)((u8*)geometry + 4) = ringBounds[0];
                *(f32*)((u8*)geometry + 8) = ringBounds[1];
                *(f32*)((u8*)geometry + 0xc) = ringBounds[2];
                *(f32*)((u8*)geometry + 0x10) = ringBounds[3];
                ring->renderObject = func_00491880();
                renderObject = ring->renderObject;
                func_004919b0(renderObject, layout, 0);
                func_00493b60(layout);
                frame = func_004caf10();
                func_00492d10(renderObject, frame);
                func_004cb930_one(
                    (RwFrame*)*(void**)((u8*)renderObject + 4));
                shadow->state++;
            }
        }
        else if (shadow->mode == 1 && shadow->model != NULL &&
                 mdlStreamRead(shadow->model) != 0)
        {
            memset(&bounds, 0, sizeof(bounds));
            func_004916d0((void*)mdlGetClump(shadow->model),
                          (void*)func_00199cf0, &bounds);
            shadow->unk_14 = bounds.largestAtomic;
            shadow->projectionDistance = 90.0f;
            *(f32*)((u8*)shadow + 0x2c) = bounds.center.x;
            *(f32*)((u8*)shadow + 0x30) = bounds.center.y;
            *(f32*)((u8*)shadow + 0x34) = bounds.center.z;
            *(f32*)((u8*)shadow + 0x2c) = 0.0f;
            *(f32*)((u8*)shadow + 0x34) = 0.0f;
            *(f32*)((u8*)shadow + 0x38) = bounds.radius;
            shadow->state++;
        }
        return KWLNTASK_CONTINUE;
    }

    if (shadow->state != 1)
        return KWLNTASK_CONTINUE;

    if (shadow->mode == 1)
    {
        field = (ResrcFld*)MT_Scene_GetResListHead(RESRC_TYPE_FLD);
        camera = kwlnGetMainCamera();
        if (RwCameraBeginUpdate(camera) != NULL)
        {
            D_00960090(14, 0);
            if (field != NULL && shadow->model != NULL)
            {
                if (field->unk_160 != NULL &&
                    (*(u32*)field->unk_160 & 1) != 0)
                {
                    projectionBounds[0].x =
                        shadow->projectionDistance +
                        mdlGetMatrix(shadow->model)->pos.x;
                    projectionBounds[0].y =
                        shadow->projectionDistance +
                        mdlGetMatrix(shadow->model)->pos.y;
                    projectionBounds[0].z =
                        shadow->projectionDistance +
                        mdlGetMatrix(shadow->model)->pos.z;
                    projectionBounds[1].x =
                        mdlGetMatrix(shadow->model)->pos.x -
                        shadow->projectionDistance;
                    projectionBounds[1].y =
                        mdlGetMatrix(shadow->model)->pos.y -
                        shadow->projectionDistance;
                    projectionBounds[1].z =
                        mdlGetMatrix(shadow->model)->pos.z -
                        shadow->projectionDistance;
                    func_0019ab80(
                        1.0f, shadow->projectionDistance / 2.0f,
                        shadow->camera, shadow->raster, 0, projectionBounds, 0,
                        (FldShadowProjectionWork*)shadow->unk_48);
                }
                else
                {
                    position = mdlGetMatrix(shadow->model)->pos;
                    func_0019ab80(
                        1.0f, shadow->projectionDistance / 2.0f,
                        shadow->camera, shadow->raster, 1, &position, 0,
                        (FldShadowProjectionWork*)shadow->unk_48);
                }
            }
            if (gFogEnabled == 1)
                D_00960090(14, 0);
            RwCameraEndUpdate(kwlnGetMainCamera());
        }
        return KWLNTASK_CONTINUE;
    }

    if (shadow->mode == 4 && shadow->model != NULL)
    {
        camera = kwlnGetMainCamera();
        if (RwCameraBeginUpdate(camera) != NULL)
        {
            savedMatrix = *mdlGetMatrix(shadow->model);
            position = savedMatrix.pos;
            if (shadow->projectionAxis.z <= shadow->projectionAxis.x)
            {
                scale.x = 1.0f;
                scale.y = 1.0f;
                scale.z = -1.0f;
                position.z = shadow->sourcePosition.z * 2.0f - position.z;
            }
            else
            {
                scale.x = -1.0f;
                scale.y = 1.0f;
                scale.z = 1.0f;
                position.x = shadow->sourcePosition.x * 2.0f - position.x;
            }
            shadow->model->flags |= 4;
            mdlScale(shadow->model, &scale, rwCOMBINEPOSTCONCAT);
            mdlGetMatrix(shadow->model)->pos = position;
            func_004c2cc0(quaternion);
            func_004c2d20(mdlGetMatrix(shadow->model), quaternion);
            func_004c2f10(mdlGetMatrix(shadow->model));
            shadow->model->flags |= 0x40;
            func_003176c0(shadow->model);
            func_00318b90(shadow->model);
            func_00317a20(shadow->model);
            shadow->model->flags &= ~0x40;
            D_00960090(0x14, 2);
            *mdlGetMatrix(shadow->model) = savedMatrix;
            shadow->model->flags &= ~4;
            func_003176c0(shadow->model);
            func_00318b90(shadow->model);
            RwCameraEndUpdate(kwlnGetMainCamera());
        }
    }

    ring = (FldShadowRingWork*)shadow->radius;
    if ((shadow->mode == 3 || shadow->mode == 4) && ring != NULL)
    {
        position = mdlGetMatrix(shadow->model)->pos;
        frame = (RwFrame*)*(void**)((u8*)ring->renderObject + 4);
        func_004cb750(frame, &position, rwCOMBINEREPLACE);
        camera = kwlnGetMainCamera();
        if (RwCameraBeginUpdate(camera) != NULL)
        {
            D_00960090(7, 2);
            D_00960090(6, 1);
            D_00960090(8, 0);
            D_00960090(14, 0);
            RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)0x44);
            RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)0x717fb);
            render = *(void (**)(void*))((u8*)ring->renderObject + 0x48);
            render(ring->renderObject);
            if (gFogEnabled == 1)
                D_00960090(14, 0);
            RwCameraEndUpdate(kwlnGetMainCamera());
        }
    }
    return KWLNTASK_CONTINUE;
}

// FUN_0019bcf0
void func_0019bcf0(KwlnTask* renderTexTask)
{
    KwlnTask* task;
    FldShadowRenderTex* shadow;
    RwCamera* camera;
    RwFrame* frame;
    RwRaster* raster;

    task = renderTexTask;
    shadow = (FldShadowRenderTex*)task->workData;
    switch (shadow->mode)
    {
    case 1:
        goto destroyMode1;
    case 4:
    case 3:
    default:
        goto destroyRing;
    }
destroyMode1:
    func_0049c1b0(kwlnGetWorld(gCurrWorldIdx), shadow->camera);
    camera = shadow->camera;
    if (camera != NULL)
    {
        frame = (RwFrame*)camera->object.object.parent;
        if (frame != NULL)
        {
            func_004d1840(camera, NULL);
            func_004caf80(frame);
        }
        raster = camera->zBuffer;
        if (raster != NULL)
        {
            camera->zBuffer = NULL;
            func_004cde90(raster);
        }
        if (camera->frameBuffer != NULL)
        {
            camera->frameBuffer = NULL;
        }
        func_004ca030(camera);
    }
    func_004f1780(shadow->raster, false);
    func_004cde90(shadow->raster);
    func_004d0be0(shadow->texture, NULL);
    func_004d0f00(shadow->texture);
    if (shadow->unk_48 != NULL)
    {
        (*(void (**)(void*))jtbl_0096017C_abs)(shadow->unk_48);
    }
    goto destroyRing;

destroyRing:
    if (shadow->radius != NULL)
    {
        if (((FldShadowRingWork*)shadow->radius)->colorData != NULL)
        {
            func_00494cc0(((FldShadowRingWork*)shadow->radius)->colorData);
        }
        if (((FldShadowRingWork*)shadow->radius)->renderObject != NULL)
        {
            frame = (RwFrame*)*(void**)((u8*)((FldShadowRingWork*)shadow->radius)->renderObject + 4);
            func_004caf80(frame);
            func_00491a80(((FldShadowRingWork*)shadow->radius)->renderObject);
        }
        (*(void (**)(void*))jtbl_0096017C_abs)(shadow->radius);
    }
    (*(void (**)(void*))jtbl_0096017C_abs)(task->workData);
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
        translation.x = (modelPosition_)->x - cameraFrame->modelling.pos.x;                            \
        translation.y = (modelPosition_)->y + ((shadow_)->projectionDistance / 2.0f) -                \
                        cameraFrame->modelling.pos.y;                                                  \
        translation.z = (modelPosition_)->z - cameraFrame->modelling.pos.z;                           \
        translation.x += cameraFrame->modelling.at.x * ((shadow_)->camera->farPlane * -0.5f);         \
        translation.y += cameraFrame->modelling.at.y * ((shadow_)->camera->farPlane * -0.5f);         \
        translation.z += cameraFrame->modelling.at.z * ((shadow_)->camera->farPlane * -0.5f);         \
                                                                                                         \
        func_004cb750(cameraFrame, &translation, rwCOMBINEPOSTCONCAT);                                 \
        ltm = RwFrameGetLTM(cameraFrame);                                                               \
        func_004c2fb0(ltm, ltm);                                                                        \
    } while (false)

#define K_FldShadow_DrawMapBands(camera_)                                                                 \
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
        RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)0x44);                                        \
        RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)0x3c803);                                    \
        K_FldShadow_Draw(0.0f, 48.0f, 128.0f, 76.0f, RwIm2DGetNearScreenZ(), recipZ,                      \
                         &gShadowColors.col2, &gShadowColors.col3);                                      \
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
        K_FldShadow_DrawMapBands((shadow_)->camera);                                                      \
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
