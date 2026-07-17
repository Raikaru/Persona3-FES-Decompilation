#include "Kosaka/k_draw.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwln.h"
#include "Graphics/primitive.h"
#include "Kosaka/Field/k_fldFrame.h"
#include "Graphics/Model/mdlManager.h"
#include "libm.h"

extern KwlnTask* func_001a3ae0(KwlnTask* parent, u32 width, u32 height, u32 unused);
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
extern f32 func_0052ea18(f32 x, f32 y);
extern void (*D_00960090)(u32 state, u32 value);
extern RwCamera* DAT_00960070;
extern u16 DAT_007e094e;

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
    void (*renderCallback)(void); // 0x48
    u8 unknown_4c[0x10];
    KDrawRenderGeometry* geometry; // 0x5c
} KDrawRenderObject;

typedef struct KDrawRenderManager
{
    u8 unknown_00[0x04];
    RwFrame* frame;          // 0x04
    u8 unknown_08[0x0c];
    KDrawRenderObject* renderObject; // 0x14
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

// FUN_001A4940 NONMATCHING
void* func_001a4940(KwlnTask* task)
{
    KDrawResourceTaskWork* work;
    u32* value;

    work = (KDrawResourceTaskWork*)task->workData;

    if (work->state == 2)
    {
        return KWLNTASK_STOP;
    }

    if (work->state == 1)
    {
        value = func_001a41b0(work->renderTask, 0);
        work->color[0] = (u8)*value;
        value = func_001a41b0(work->renderTask, 1);
        work->color[1] = (u8)*value;
        value = func_001a41b0(work->renderTask, 2);
        work->color[2] = (u8)*value;
        value = func_001a41b0(work->renderTask, 3);
        work->color[3] = (u8)*value;

        if ((DAT_007e094e & 0x20) != 0)
        {
            work->state = 2;
        }
    }
    else if (work->state == 0)
    {
        work->renderTask = func_001a3ae0(task, 0x100, 200, 0);
        func_001a4110(work->renderTask,
                      func_001a3f20(work->renderTask, (const void*)0x007cc1bc),
                      work->color[0], 0, 0xff, 0);
        func_001a4110(work->renderTask,
                      func_001a3f20(work->renderTask, (const void*)0x007cc1c0),
                      work->color[1], 0, 0xff, 0);
        func_001a4110(work->renderTask,
                      func_001a3f20(work->renderTask, (const void*)0x007cc1c8),
                      work->color[2], 0, 0xff, 0);
        func_001a4110(work->renderTask,
                      func_001a3f20(work->renderTask, (const void*)0x007cc1d0),
                      work->color[3], 0, 0xff, 0);
        func_001a3bf0(work->renderTask, 1);
        work->state++;
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
// FUN_001A5000 NONMATCHING
void* func_001a5000(KwlnTask* task)
{
    PositionDrawWork* work;
    RwV3d line[2];
    RwV3d hitPoint;
    RwMatrixTolerance matTolerance;

    work = (PositionDrawWork*)task->workData;
    line[0] = work->mat.pos;
    line[1] = line[0];
    line[1].y -= 800.0f;

    if (K_FldFrame_Raycast(line, &hitPoint) == 1)
    {
        hitPoint.y += 3.0f;
        work->mat.pos = hitPoint;
        RwEngineGetMatrixTolerances(&matTolerance);
        RwMatrixOptimize(&work->mat, &matTolerance);
        RwMatrixUpdate(&work->mat);
    }

    return KWLNTASK_CONTINUE;
}

// FUN_001A50F0 NONMATCHING
void* func_001a50f0(KwlnTask* task)
{
    KDrawArcTaskWork* work;
    KDrawArcData* render;
    KDrawRenderManager* manager;
    KDrawRenderObject* renderObject;
    RwMatrix modelMatrix;
    RwCamera* camera;
    RwSphere* sphere;

    work = (KDrawArcTaskWork*)task->workData;
    if (work->state == 0)
    {
        return KWLNTASK_CONTINUE;
    }

    render = work->render;
    manager = render->manager;
    if (work->model != NULL)
    {
        modelMatrix = *mdlGetMatrix(work->model);
        RwFrameTransform(manager->frame, &modelMatrix, rwCOMBINEREPLACE);
    }

    camera = kwlnGetMainCamera();
    if (RwCameraBeginUpdate(camera) != NULL)
    {
        (*D_00960090)(7, 2);
        (*D_00960090)(6, 1);
        (*D_00960090)(8, 0);
        (*D_00960090)(0xc, 1);
        RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)0x44);
        RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)0x717fb);

        renderObject = manager->renderObject;
        sphere = func_004912b0(renderObject);
        if (RwCameraFrustumTestSphere(DAT_00960070, sphere) != rwSPHEREOUTSIDE)
        {
            renderObject->renderCallback();
        }

        RwCameraEndUpdate(camera);
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

// FUN_001A5320 NONMATCHING
KwlnTask* func_001a5320(KwlnTask* parent)
{
    KDrawArcTaskWork* work;
    KDrawArcData* render;
    KDrawColorData* colorData;
    KDrawRenderObject* renderObject;
    KDrawRenderGeometry* geometry;
    RwSphere bounds;
    RwFrame* frame;
    f32 theta;
    u32 i;
    KwlnTask* task;

    work = (KDrawArcTaskWork*)RwCalloc(1, sizeof(KDrawArcTaskWork),
                                       rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent,
                          (const char*)0x00678b68,
                          0x104e,
                          func_001a50f0,
                          func_001a5280,
                          work);

    render = (KDrawArcData*)RwCalloc(1, sizeof(KDrawArcData), rwMEMHINTDUR_GLOBAL);
    work->render = render;
    render->radius = 400.0f;

    colorData = (KDrawColorData*)func_00494be0();
    render->colorData = colorData;
    colorData->color = *(const RwRGBA*)0x007cc1d8;

    renderObject = (KDrawRenderObject*)func_00493710(0x22, 0x20, 0x4a);
    for (i = 0; i < 0x20; i++)
    {
        func_00493210(renderObject,
                      renderObject->indexData,
                      0,
                      (i + 2) & 0xffff,
                      (i + 1) & 0xffff);
        func_00493230(renderObject,
                      renderObject->indexData,
                      colorData);
    }

    geometry = renderObject->geometry;
    geometry->vertices[0].x = 0.0f;
    geometry->vertices[0].y = 5.0f;
    geometry->vertices[0].z = 0.0f;
    theta = 0.0f;
    for (i = 0; i < 0x20; i++)
    {
        geometry->vertices[i + 1].x = render->radius * cosf(theta);
        geometry->vertices[i + 1].y = 5.0f;
        geometry->vertices[i + 1].z = render->radius * sinf(theta);
        theta += (gPI * 2.0f) / 32.0f;
    }
    geometry->vertices[0x21].x = render->radius * cosf(0.0f);
    geometry->vertices[0x21].y = 5.0f;
    geometry->vertices[0x21].z = render->radius * sinf(0.0f);

    func_004933d0(renderObject);
    func_00492e20(geometry, &bounds);
    geometry->bounds = bounds;

    render->manager = (KDrawRenderManager*)func_00491880();
    func_004919b0(render->manager, renderObject, 0);
    func_00493b60(renderObject);
    frame = func_004caf10();
    func_00492d10(render->manager, frame);
    func_004cb930(render->manager->frame);

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

// FUN_001A5700 NONMATCHING
void func_001a5700(KwlnTask* task, const RwRGBA* color)
{
    KDrawArcTaskWork* work;
    KDrawRenderObject* renderObject;
    u32 i;

    work = (KDrawArcTaskWork*)task->workData;
    renderObject = work->render->manager->renderObject;
    func_00493370(renderObject, 0xfff);
    for (i = 0; i < 0x22; i++)
    {
        renderObject->colors[i * 4 + 0] = color->r;
        renderObject->colors[i * 4 + 1] = color->g;
        renderObject->colors[i * 4 + 2] = color->b;
        renderObject->colors[i * 4 + 3] = color->a;
    }
    func_004933d0(renderObject);
}

// FUN_001A57A0 NONMATCHING
void func_001a57a0(f32 angle, f32 radius, KwlnTask* task)
{
    KDrawArcTaskWork* work;
    KDrawArcData* render;
    KDrawRenderObject* renderObject;
    f32 fullAngle;
    f32 normalizedAngle;
    f32 startAngle;
    f32 theta;
    u32 i;

    work = (KDrawArcTaskWork*)task->workData;
    render = work->render;
    render->radius = radius;
    render->angle = angle;

    if (render->angle < 0.0f)
    {
        render->angle = 0.0f;
    }
    if (render->angle > 360.0f)
    {
        render->angle = 360.0f;
    }

    fullAngle = gPI * 2.0f;
    normalizedAngle = render->angle / 360.0f;
    if (normalizedAngle <= 0.5f)
    {
        startAngle = (fullAngle * (0.5f - normalizedAngle)) / 2.0f;
    }
    else
    {
        startAngle = fullAngle * -((normalizedAngle - 0.5f) / 2.0f);
    }

    renderObject = render->manager->renderObject;
    func_00493370(renderObject, 0xfff);
    renderObject->geometry->vertices[0] = render->center;
    theta = startAngle;
    for (i = 0; i < 0x20; i++)
    {
        renderObject->geometry->vertices[i + 1].x =
            render->radius * cosf(theta) + render->center.x;
        renderObject->geometry->vertices[i + 1].y = render->center.y;
        renderObject->geometry->vertices[i + 1].z =
            render->radius * sinf(theta) + render->center.z;
        theta += (fullAngle * normalizedAngle) / 32.0f;
    }

    if (render->angle == 360.0f)
    {
        renderObject->geometry->vertices[0x21].x =
            render->radius * cosf(startAngle) + render->center.x;
        renderObject->geometry->vertices[0x21].y = render->center.y;
        renderObject->geometry->vertices[0x21].z =
            render->radius * sinf(startAngle) + render->center.z;
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