#include "Kosaka/k_draw.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwln.h"
#include "Graphics/primitive.h"
#include "Kosaka/Field/k_fldFrame.h"
#include "Graphics/Model/mdlManager.h"
#include "libm.h"
#pragma alias rwGlobals_abs rwGlobals
extern u8 rwGlobals_abs[];

extern KwlnTask* func_001a3ae0(KwlnTask* parent, u32 width, u32 height);
extern u32 func_001a3f20(KwlnTask* task, const void* descriptor);
extern void func_001a3bf0(KwlnTask* task, u32 request);
extern void func_001a4110(KwlnTask* task, u32 id, u32 value, u32 min, u32 max, u32 step);
extern u32* func_001a41b0(KwlnTask* task, u32 index);

extern const char D_00678B48[];

extern void* func_00491880(void);
extern void func_004919b0(void* manager, void* renderObject, u32 index);
extern void func_00491a80(void* manager);
extern void* func_004912b0(void* atomic);
extern void func_00492d10(void* manager, void* frame);
extern void func_00492e20(void* geometry, RwSphere* bounds);
extern void func_00493210(void* renderObject, void* indexData, u32 flags, u32 index0, u32 index1);
extern void func_00493230(void* renderObject, void* indexData, void* colorData);
extern void func_00493370(void* renderObject, u32 state);
extern void func_004933d0(void* renderObject);
extern void* func_00493710(u32 vertexCount, u32 indexCount, u32 primitiveType);
extern void func_00493b60(void* renderObject);
extern void* func_00494be0(void);
extern void func_00494cc0(void* colorData);
extern RwFrame* func_004caf10(void);
extern RwFrame* func_004caf80(RwFrame* frame);
extern void func_004cb930(void* frame);
extern RwMatrix* func_004c2fb0(RwMatrix* matrixOut, RwMatrix* matrixIn);
extern void func_004cb7f0(void* dst, const void* src, u32 mode);
 #pragma alias D_00960090_abs D_00960090
extern void (*D_00960090_abs[])(u32 state, u32 value);
 #pragma alias DAT_00960070_abs DAT_00960070
extern RwCamera* DAT_00960070_abs[];
extern f32 func_0052ea18(f32 x, f32 y);
extern void (*D_00960090)(u32 state, u32 value);
#pragma alias DAT_007e094e_abs DAT_007e094e
extern u16 DAT_007e094e_abs[];
extern RwCamera* DAT_00960070;
extern u16 DAT_007e094e;
extern u8 D_007CC1BC;
extern u8 D_007CC1C0;
extern u8 D_007CC1C8;
extern f32 D_007CC1D0;
extern f32 D_007CC1D8;
extern f32 D_007CB130;

typedef struct KDrawResourceTaskWork
{
    u32 state;              // 0x00
    KwlnTask* renderTask;   // 0x04
    u8* color;              // 0x08
} KDrawResourceTaskWork;

typedef struct KDrawColorData
{
    u32 unknown;            // 0x00
    RwRGBA color;           // 0x04
} KDrawColorData;

typedef struct KDrawRenderGeometry
{
    u32 unknown;            // 0x00
    RwSphere bounds;        // 0x04
    RwV3d* vertices;        // 0x14
} KDrawRenderGeometry;

typedef struct KDrawRenderObject
{
    u8 unknown_00[0x2c];
    u8* indexData;           // 0x2c
    u8* colors;              // 0x30
    u8 unknown_34[0x14];
    void (*renderCallback)(void* object); // 0x48
    u8 unknown_4c[0x10];
    KDrawRenderGeometry* geometry; // 0x5c
} KDrawRenderObject;

typedef struct KDrawRenderManager
{
    u8 unknown_00[0x04];
    RwFrame* frame;          // 0x04
    u8 unknown_08[0x10];
    KDrawRenderObject* renderObject; // 0x18
    u8 unknown_1c[0x2c];
    void (*renderCallback)(void* object); // 0x48
} KDrawRenderManager;

typedef struct KDrawArcData
{
    f32 angle;               // 0x00
    f32 radius;              // 0x04
    RwV3d center;            // 0x08
    KDrawRenderManager* manager; // 0x14
    KDrawColorData* colorData; // 0x18
} KDrawArcData;

typedef struct KDrawArcTaskWork
{
    u32 state;               // 0x00
    Model* model;            // 0x04
    KDrawArcData* render;    // 0x08
} KDrawArcTaskWork;

static RwRGBA sCylinderColor = {0, 168, 168, 168}; // 007cc1b8

// FUN_001a4660
void* K_Draw_UpdatePointTask(KwlnTask* pointTask)
{
    PointDrawWork* work;    

    work = (PointDrawWork*)pointTask->workData;

    if (!work->drawEnabled)
    {
        return KWLNTASK_CONTINUE;
    }

    primSphereLine3D(&work->center, 10.0f, &work->color, 1);

    return KWLNTASK_CONTINUE;
}

// FUN_001a46c0
void K_Draw_DestroyPointTask(KwlnTask* pointTask)
{
    RwFree(pointTask->workData);
}

// FUN_001a46f0. Tiny sphere
KwlnTask* K_Draw_CreatePointTask(KwlnTask* parent)
{
    PointDrawWork* work;

    work = RwCalloc(1, sizeof(PointDrawWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    return kwlnTaskCreateWithAutoPriority(parent,
                                          2109,
                                          "draw point",
                                          K_Draw_UpdatePointTask,
                                          K_Draw_DestroyPointTask,
                                          work);
}

// FUN_001a4770
void K_Draw_SetPointDrawEnabled(KwlnTask* pointTask, u32 drawEnabled)
{
    ((PointDrawWork*)pointTask->workData)->drawEnabled = drawEnabled;
}

// FUN_001a4780
void K_Draw_SetPointCenter(KwlnTask* pointTask, const RwV3d* center)
{
    ((PointDrawWork*)pointTask->workData)->center = *center;
}

// FUN_001a47b0
void K_Draw_SetPointColor(KwlnTask* pointTask, const RwRGBA* color)
{
    ((PointDrawWork*)pointTask->workData)->color = *color;
}

// FUN_001a47e0
void* K_Draw_UpdateCylinderTask(KwlnTask* cylinderTask)
{
    CylinderDrawWork* work;

    work = (CylinderDrawWork*)cylinderTask->workData;

    if (work->drawEnabled)
    {
        primCylinderLine3D(&work->center, work->radius, work->height, &sCylinderColor, 1);
    }

    return KWLNTASK_CONTINUE;
}

// FUN_001a4830
void K_Draw_DestroyCylinderTask(KwlnTask* cylinderTask)
{
    RwFree(cylinderTask->workData);
}

// FUN_001a4860
KwlnTask* K_Draw_CreateCylinderTask(KwlnTask* parent)
{
    CylinderDrawWork* work;

    work = RwCalloc(1, sizeof(CylinderDrawWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    return kwlnTaskCreateWithAutoPriority(parent,
                                          2109,
                                          "field camera cylinder",  // this name is horrible btw
                                          K_Draw_UpdateCylinderTask,
                                          K_Draw_DestroyCylinderTask,
                                          work);
}

// FUN_001a48e0
void K_Draw_SetCylinderDrawEnabled(KwlnTask* cylinderTask, u32 drawEnabled)
{
    ((CylinderDrawWork*)cylinderTask->workData)->drawEnabled = drawEnabled;
}

// FUN_001a48f0
void K_Draw_SetCylinderCenter(KwlnTask* cylinderTask, const RwV3d* center)
{
    ((CylinderDrawWork*)cylinderTask->workData)->center = *center;
}

// FUN_001a4920
void K_Draw_SetCylinderRadius(KwlnTask* cylinderTask, f32 radius)
{
    ((CylinderDrawWork*)cylinderTask->workData)->radius = radius;
}

// FUN_001a4930
void K_Draw_SetCylinderHeight(KwlnTask* cylinderTask, f32 height)
{
    ((CylinderDrawWork*)cylinderTask->workData)->height = height;
}

// FUN_001A4940
void* func_001a4940(KwlnTask* task)
{
    KDrawResourceTaskWork* work;

    work = (KDrawResourceTaskWork*)task->workData;

    switch (work->state)
    {
    case 0:
        work->renderTask = func_001a3ae0(task, 0x100, 200);
        func_001a4110(work->renderTask,
                      func_001a3f20(work->renderTask,
                                    &D_007CC1BC),
                      work->color[0], 0, 0xff, 0);
        func_001a4110(work->renderTask,
                      func_001a3f20(work->renderTask,
                                    &D_007CC1C0),
                      work->color[1], 0, 0xff, 0);
        func_001a4110(work->renderTask,
                      func_001a3f20(work->renderTask,
                                    &D_007CC1C8),
                      work->color[2], 0, 0xff, 0);
        func_001a4110(work->renderTask,
                      func_001a3f20(work->renderTask,
                                    (const u8*)&D_007CC1D0),
                      work->color[3], 0, 0xff, 0);
        func_001a3bf0(work->renderTask, 1);
        work->state++;
        break;
    case 1:
        work->color[0] = (u8)*func_001a41b0(work->renderTask, 0);
        work->color[1] = (u8)*func_001a41b0(work->renderTask, 1);
        work->color[2] = (u8)*func_001a41b0(work->renderTask, 2);
        work->color[3] = (u8)*func_001a41b0(work->renderTask, 3);
        if ((DAT_007e094e_abs[0] & 0x20) != 0)
        {
            work->state = 2;
        }
        break;
    case 2:
        return KWLNTASK_STOP;
    default:
        break;
    }

    return KWLNTASK_CONTINUE;
}

// FUN_001A4B40
void K_Draw_001a4b40(KwlnTask* task)
{
    RwFree(task->workData);
}
// FUN_001A4B70
KwlnTask* func_001a4b70(KwlnTask* parent, u8* color)
{
    KDrawResourceTaskWork* work;
    KwlnTask* task;

    work = (KDrawResourceTaskWork*)RwCalloc(1, sizeof(KDrawResourceTaskWork),
                                            rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parent,
                                          10,
                                          D_00678B48,
                                          func_001a4940,
                                          K_Draw_001a4b40,
                                          work);
    work->color = color;
    return task;
}

// FUN_001a4c10
void* K_Draw_UpdatePositionTask(KwlnTask* positionTask)
{
    PositionDrawWork* work;

    work = (PositionDrawWork*)positionTask->workData;

    if (kwlnCameraBeginUpdate() != NULL)
    {
        primAxisLine3D(&work->mat, 60.0f, 1);
        primSphereLine3D(&work->mat.pos, 20.0f, &work->color, 1);

        kwlnCameraEndUpdate();
    }

    return KWLNTASK_CONTINUE;
}

// FUN_001a4ca0
void K_Draw_DestroyPositionTask(KwlnTask* positionTask)
{
    RwFree(positionTask->workData);
}

// FUN_001a4cd0
KwlnTask* K_Draw_CreatePositionTask(KwlnTask* parent)
{
    PositionDrawWork* work;
    KwlnTask* positionTask;

    work = RwCalloc(1, sizeof(PositionDrawWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    positionTask = kwlnTaskCreate(parent,
                                  "position draw",
                                  4174,
                                  K_Draw_UpdatePositionTask,
                                  K_Draw_DestroyPositionTask,
                                  work);

    RwMatrixSetIdentity(&work->mat);
    work->color.r = 255;
    work->color.g = 0;
    work->color.b = 0;
    work->color.a = 255;

    return positionTask;
}

// FUN_001a4dc0
void K_Draw_SetPositionColor(KwlnTask* positionTask, const RwRGBA* color)
{
    ((PositionDrawWork*)positionTask->workData)->color = *color;
}

// FUN_001a4df0
void K_Draw_CopyPositionCenter(RwV3d* dst, KwlnTask* positionTask)
{
    PositionDrawWork* work = (PositionDrawWork*)positionTask->workData;
    RwV3d unsused = {0};

    *dst = work->mat.pos;
}

// FUN_001a4e50
RwMatrix* K_Draw_GetPositionMatrix(KwlnTask* positionTask)
{
    return &((PositionDrawWork*)positionTask->workData)->mat;
}

// FUN_001a4e60. Dumb name ngl
void K_Draw_SetPositionPos(KwlnTask* positionTask, const RwV3d* pos)
{
    PositionDrawWork* work;
    RwMatrixTolerance matTolerance;

    work = (PositionDrawWork*)positionTask->workData;

    work->mat.pos = *pos;

    RwEngineGetMatrixTolerances(&matTolerance);
    RwMatrixOptimize(&work->mat, &matTolerance);
    RwMatrixUpdate(&work->mat);
}

// FUN_001a4ed0
void K_Draw_MovePositionInDir(f32 dist, KwlnTask* positionTask, const RwV3d* dir)
{
    PositionDrawWork* work;
    RwV3d translation;

    work = (PositionDrawWork*)positionTask->workData;

    translation = *dir;

    translation.x *= dist;
    translation.y *= dist;
    translation.z *= dist;

    RwMatrixTranslate(&work->mat, &translation, rwCOMBINEPOSTCONCAT);
}

// FUN_001a4f40
void K_Draw_RotatePosition(KwlnTask* positionTask, const RwV3d* axis, f32 angle)
{
    RwV3d originalPos;
    RwV3d negPos;
    PositionDrawWork* work;

    work = (PositionDrawWork*)positionTask->workData;
    originalPos = work->mat.pos;

    negPos.x = originalPos.x * -1.0f;
    negPos.y = originalPos.y * -1.0f;
    negPos.z = originalPos.z * -1.0f;

    RwMatrixTranslate(&work->mat, &negPos, rwCOMBINEPOSTCONCAT);
    RwMatrixRotate(&work->mat, axis, angle, rwCOMBINEPOSTCONCAT);
    RwMatrixTranslate(&work->mat, &originalPos, rwCOMBINEPOSTCONCAT);
}
// FUN_001A5000
void* func_001a5000(KwlnTask* task)
{
    RwV3d line[2];
    RwV3d hitPoint;
    RwMatrixTolerance matTolerance;
    u32 hit;
    PositionDrawWork* work;

    line[1] = ((PositionDrawWork*)task->workData)->mat.pos;
    line[0] = line[1];
    line[1].y -= 800.0f;

    hit = K_FldFrame_Raycast(line, &hitPoint);
    if (hit == 1)
    {
        hitPoint.y += 3.0f;
        work = (PositionDrawWork*)task->workData;
        work->mat.pos = hitPoint;
        RwEngineGetMatrixTolerances(&matTolerance);
        RwMatrixOptimize(&work->mat, &matTolerance);
        RwMatrixUpdate(&work->mat);
    }

    return;
}

// FUN_001A50F0
void* func_001a50f0(KwlnTask* task)
{
    KDrawArcTaskWork* work;
    volatile u8 unused[0x10];
    RwMatrix modelMatrix;
    RwSphere* sphere;
    volatile void (**stateSet)(u32 state, u32 value);

    work = (KDrawArcTaskWork*)task->workData;
    if (work->state == 0)
    {
        return KWLNTASK_CONTINUE;
    }

    if (work->model != NULL)
    {
        modelMatrix = *mdlGetMatrix(work->model);
        func_004cb7f0(work->render->manager->frame, &modelMatrix, 0);
    }

    if (RwCameraBeginUpdate(kwlnGetMainCamera()) != NULL)
    {
        stateSet = (volatile void (**)(u32, u32))D_00960090_abs;
        (*stateSet)(7, 2);
        (*stateSet)(6, 1);
        (*stateSet)(8, 0);
        (*stateSet)(0xc, 1);
        RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)0x44);
        RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)0x717fb);

        sphere = func_004912b0(work->render->manager);
        if (RwCameraFrustumTestSphere(DAT_00960070_abs[0], sphere) != 0)
        {
            work->render->manager->renderCallback(work->render->manager);
        }

        RwCameraEndUpdate(kwlnGetMainCamera());
    }

    return KWLNTASK_CONTINUE;
}

// FUN_001A5280
void func_001a5280(KwlnTask* task)
{
    KDrawArcTaskWork* work;
    void (**freeMemory)(void*);

    work = (KDrawArcTaskWork*)task->workData;
    func_00494cc0(work->render->colorData);
    func_004caf80(work->render->manager->frame);
    func_00491a80(work->render->manager);
    freeMemory = (void (**)(void*))((u8*)&rwGlobals + 0x17c);
    (*freeMemory)(work->render);
    (*freeMemory)(task->workData);
}

// Reconstructed the arc mesh setup, color table, manager, and geometry bounds pipeline.
// The remaining residual is MWCC register/scheduling layout in color initialization and tail calls.
// FUN_001A5320 NONMATCHING
KwlnTask* func_001a5320(KwlnTask* parent)
{
    void* (**callocFunc)(u32, u32, u32);
    KDrawArcTaskWork* work;
    KDrawRenderObject* renderObject;
    u8* indexData;
    u8* colors;
    RwV3d* vertices;
    volatile f32 colorValue;
    RwSphere bounds;
    f32 theta;
    s32 i;
    s32 j;
    s32 k;
    register u32 colorR;
    register u32 colorA;
    KwlnTask* task;

    colorValue = D_007CC1D8;
    callocFunc = &((RwGlobals*)rwGlobals_abs)->memFuncs.RwCalloc;
    work = (KDrawArcTaskWork*)(*callocFunc)(1, sizeof(KDrawArcTaskWork),
                                             rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent,
                          D_00678B48 + 0x20,
                          0x104e,
                          func_001a50f0,
                          func_001a5280,
                          work);

    work->render = (KDrawArcData*)(*callocFunc)(1, sizeof(KDrawArcData),
                                                rwMEMHINTDUR_GLOBAL);
    work->render->center.x = 0.0f;
    work->render->center.y = 0.0f;
    work->render->center.z = 0.0f;
    work->render->radius = 400.0f;
    work->render->colorData = (KDrawColorData*)func_00494be0();
    work->render->colorData->color = *(const RwRGBA*)&colorValue;
    renderObject = (KDrawRenderObject*)func_00493710(0x22, 0x20, 0x4a);
    indexData = renderObject->indexData;
    for (i = 0; i < 0x20; i++)
    {
        func_00493210(renderObject,
                      indexData,
                      0,
                      (i + 2) & 0xffff,
                      (i + 1) & 0xffff);
        func_00493230(renderObject,
                      indexData,
                      work->render->colorData);
        indexData += 8;
    }

    vertices = renderObject->geometry->vertices;
    vertices[0].x = 0.0f;
    vertices[0].y = 5.0f;
    vertices[0].z = 0.0f;
    theta = 0.0f;
    for (j = 0; j < 0x20; j++)
    {
        indexData = (u8*)(vertices + j);
        ((RwV3d*)indexData)[1].x = work->render->radius * cosf(theta);
        ((RwV3d*)indexData)[1].y = 5.0f;
        ((RwV3d*)indexData)[1].z = work->render->radius * sinf(theta);
        theta += gPI;
    }
    vertices[j + 1].x = work->render->radius * cosf(0.0f);
    vertices[j + 1].y = 5.0f;
    vertices[j + 1].z = work->render->radius * sinf(0.0f);


    colorR = 0xff;
    colorA = 0x80;
    colors = renderObject->colors;
    colors[0] = colorR;
    colors[1] = 0;
    colors[2] = 0;
    colors[3] = colorA;
    for (k = 0; k < 0x21; k++)
    {
        colors[4] = colorR;
        colors[5] = 0;
        colors[6] = 0;
        colors[7] = colorA;
        colors += 4;
    }
    work->render->manager = (KDrawRenderManager*)func_00491880();
    func_004933d0(renderObject);
    func_00492e20(renderObject->geometry, &bounds);
    renderObject->geometry->bounds = bounds;
    func_004919b0(work->render->manager, renderObject, 0);
    func_00493b60(renderObject);
    func_00492d10(work->render->manager, func_004caf10());
    func_004cb930(work->render->manager->frame);

    return task;
}

// FUN_001A56B0
void func_001a56b0(KwlnTask* task, u32 state)
{
    ((KDrawArcTaskWork*)task->workData)->state = state;
}

// FUN_001A56C0
void func_001a56c0(KwlnTask* task, Model* model)
{
    ((KDrawArcTaskWork*)task->workData)->model = model;
}

// FUN_001A56D0
void func_001a56d0(KwlnTask* task, const RwV3d* center)
{
    KDrawArcData* render;

    render = ((KDrawArcTaskWork*)task->workData)->render;
    render->center = *center;
}

// FUN_001A5700
void func_001a5700(KwlnTask* task, const RwRGBA* color)
{
    KDrawArcTaskWork* work;
    KDrawRenderObject* renderObject;
    s32 i;
    RwRGBA* colors;

    work = (KDrawArcTaskWork*)task->workData;
    renderObject = work->render->manager->renderObject;
    func_00493370(renderObject, 0xfff);
    colors = (RwRGBA*)renderObject->colors;
    for (i = 0; i < 0x22; i++)
    {
        colors[i] = *color;
    }
    func_004933d0(renderObject);
}

// FUN_001A57A0 NONMATCHING
void func_001a57a0(f32 angle, f32 radius, KwlnTask* task)
{
    KDrawArcTaskWork* work;
    KDrawRenderObject* renderObject;
    f32 fullAngle;
    f32 normalizedAngle;
    f32 startAngle;
    f32 theta;
    u32 i;

    work = (KDrawArcTaskWork*)task->workData;
    work->render->radius = radius;
    work->render->angle = angle;

    if (work->render->angle < 0.0f)
    {
        work->render->angle = 0.0f;
    }
    if (work->render->angle > 360.0f)
    {
        work->render->angle = 360.0f;
    }

    normalizedAngle = work->render->angle / 360.0f;
    if (normalizedAngle <= 0.5f)
    {
        fullAngle = gPI;
        startAngle = (fullAngle * (0.5f - normalizedAngle)) / 2.0f;
    }
    else
    {
        fullAngle = gPI;
        startAngle = fullAngle * -((normalizedAngle - 0.5f) / 2.0f);
    }

    renderObject = work->render->manager->renderObject;
    func_00493370(renderObject, 0xfff);
    renderObject->geometry->vertices[0] = work->render->center;
    theta = startAngle;
    for (i = 0; i < 0x20; i++)
    {
        renderObject->geometry->vertices[i + 1].x =
            work->render->radius * cosf(theta) + work->render->center.x;
        renderObject->geometry->vertices[i + 1].y = work->render->center.y;
        renderObject->geometry->vertices[i + 1].z =
            work->render->radius * sinf(theta) + work->render->center.z;
        theta += (fullAngle * normalizedAngle) / 32.0f;
    }

    if (work->render->angle == 360.0f)
    {
        renderObject->geometry->vertices[0x21].x =
            work->render->radius * cosf(startAngle) + work->render->center.x;
        renderObject->geometry->vertices[0x21].y = work->render->center.y;
        renderObject->geometry->vertices[0x21].z =
            work->render->radius * sinf(startAngle) + work->render->center.z;
    }
    else
    {
        renderObject->geometry->vertices[0x21] =
            renderObject->geometry->vertices[0];
    }
    func_004933d0(renderObject);
}


// FUN_001A5AA0
f32 func_001a5aa0(const RwMatrix* matrix)
{
    RwMatrix normalized;

    normalized = *matrix;
    func_004c2fb0(&normalized, &normalized);
    return (-func_0052ea18(normalized.right.z, normalized.right.x) * 180.0f) / gPI;
}

// FUN_001A5B30
f32 func_001a5b30(const RwMatrix* matrix)
{
    RwMatrix normalized;
    RwV3d* up;

    normalized = *matrix;
    func_004c2fb0(&normalized, &normalized);
    up = &normalized.up;
    return (-func_0052ea18(up->z, up->y) * 180.0f) / gPI;
}

// FUN_001A5BC0
f32 func_001a5bc0(const RwMatrix* matrix)
{
    RwMatrix normalized;
    RwV3d* up;

    normalized = *matrix;
    func_004c2fb0(&normalized, &normalized);
    up = &normalized.up;
    return (func_0052ea18(up->x, up->y) * 180.0f) / gPI;
}