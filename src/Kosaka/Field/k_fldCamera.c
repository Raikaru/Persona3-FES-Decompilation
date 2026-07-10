#include "Kosaka/Field/k_fldCamera.h"
#include "Kosaka/Field/k_field.h"
#include "Kosaka/Field/k_fldrc.h"
#include "Kosaka/Field/k_sceneDraw.h"
#include "Kosaka/k_assert.h"
#include "Kosaka/k_draw.h"
#include "Kosaka/k_view.h"
#include "Graphics/Model/mdlManager.h"
#include "Kernel/Kwln/kwln.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "h_cdvd.h"
#include "libm.h"
#include "temporary.h"

#define CAMERA_DATA_U32(address) (*(volatile u32*)(uintptr_t)(address))
#define CAMERA_FIELD_IDS (*(volatile u32**)(uintptr_t)0x007cd540)
#define CAMERA_UP_AXIS ((const RwV3d*)(uintptr_t)0x00683a98)

typedef struct FldCameraResource
{
    u8 unkData[0x100];
    u32 type;               // 0x100
    f32 fov;                // 0x104
    const RwMatrix* matrix; // 0x108
    RwV3d posOffset;        // 0x10c
    f32 xzDeadZone;         // 0x118
    f32 yDeadZone;          // 0x11c
} FldCameraResource;

extern f32 FUN_001a5aa0(const RwMatrix* matrix);
extern void FUN_001a1210(RwCamera* camera, const RwV3d* target,
                         const RwV3d* position, const RwV3d* upVector);
extern void FUN_0019d3f0(const char* file, s32 line);
extern void FUN_0048d270(void* curve, s32 index, RwV3d* dst);
extern void FUN_0048d480(f32 time, void* curve, s32 mode, RwV3d* dst, void* aux);
extern void FUN_004cb7f0(RwFrame* frame, const RwMatrix* matrix, u32 flags);
extern void FUN_004c31b0(f32 angle, RwFrame* frame, const RwV3d* axis, u32 mode);
extern void func_004c2330(RwMatrix* dst, const RwMatrix* src);
extern const char DAT_00683b10[];
extern void* DAT_00960184[];
extern void* func_00100d80(const char* path, u32 mode);
extern void func_001023a0(void* object);
extern void func_00100ec0(void* object);
extern void func_00521250();

// FUN_001d5c00
u32 K_FldCamera_GetType(KwlnTask* fldCameraTask)
{
    return ((FldCamera*)fldCameraTask->workData)->type;
}

// FUN_001d5c10 NONMATCHING
void func_001d5c10(KwlnTask* fldCameraTask, u32 type)
{
    FldCamera* fldCamera;
    void* curve;
    s32 i;
    RwV3d center;

    fldCamera = (FldCamera*)fldCameraTask->workData;
    fldCamera->type = type;

    if (type == 3 || type == 4)
    {
        curve = *(void**)((u8*)*(void**)((u8*)K_Field_Get() + 0x116c) + 0xa1c);
        if (curve != NULL)
        {
            for (i = 0; i < 9; i++)
            {
                FUN_0048d480((f32)i * 0.125f, curve, 10,
                             &fldCamera->deadZonePath[i], NULL);
            }

            if (fldCamera->pointTask0 == NULL)
            {
                fldCamera->pointTask0 = K_Draw_CreatePointTask(fldCameraTask);
                fldCamera->pointTask1 = K_Draw_CreatePointTask(fldCameraTask);
                fldCamera->pointTask2 = K_Draw_CreatePointTask(fldCameraTask);
            }

            K_Draw_SetPointDrawEnabled(fldCamera->pointTask0, true);
            K_Draw_SetPointDrawEnabled(fldCamera->pointTask1, true);
            K_Draw_SetPointDrawEnabled(fldCamera->pointTask2, true);
            FUN_0048d270(curve, 0, &center);
            K_Draw_SetPointCenter(fldCamera->pointTask0, &center);
            K_Draw_SetPointColor(fldCamera->pointTask0,
                                 (const RwRGBA*)(uintptr_t)0x00683a8c);
            K_Draw_SetPointColor(fldCamera->pointTask1,
                                 (const RwRGBA*)(uintptr_t)0x00683a90);
            K_Draw_SetPointColor(fldCamera->pointTask2,
                                 (const RwRGBA*)(uintptr_t)0x00683a90);
        }
    }
    else
    {
        if (fldCamera->deadZoneTask != NULL)
        {
            kwlnTaskDestroyWithHierarchy(fldCamera->deadZoneTask);
            fldCamera->deadZoneTask = NULL;
        }
        if (fldCamera->pointTask0 != NULL)
        {
            kwlnTaskDestroyWithHierarchy(fldCamera->pointTask0);
            fldCamera->pointTask0 = NULL;
            kwlnTaskDestroyWithHierarchy(fldCamera->pointTask1);
            kwlnTaskDestroyWithHierarchy(fldCamera->pointTask2);
        }
    }
}

// FUN_001d5e10
RwV3d* K_FldCamera_GetPos(KwlnTask* fldCameraTask)
{
    return &((FldCamera*)fldCameraTask->workData)->frame->modelling.pos;
}

// FUN_001d5e30 NONMATCHING
void func_001d5e30(KwlnTask* fldCameraTask, f32 amount)
{
    FldCamera* fldCamera;
    RwCamera* camera;
    RwFrame* cameraFrame;

    fldCamera = (FldCamera*)fldCameraTask->workData;
    if (fldCamera->type != FLDCAMERA_TYPE_0)
    {
        return;
    }

    camera = kwlnGetMainCamera();
    cameraFrame = (RwFrame*)camera->object.object.parent;
    FUN_004c31b0(amount, cameraFrame, CAMERA_UP_AXIS, 2);
}

// FUN_001d5f30
void K_FldCamera_SetPlayerResrcByTypeid(KwlnTask* fldCameraTask, u16 resTypeId)
{
    FldCamera* fldCam;

    fldCam = (FldCamera*)fldCameraTask->workData;

    if (RESRC_GET_TYPE(resTypeId) == RESRC_TYPE_MODELCHAR)
    {
        fldCam->playerResrc = (ResrcModelChar*)MT_Scene_GetRes(resTypeId);
    }
}

// FUN_001d5f90 NONMATCHING
void* func_001d5f90(KwlnTask* cameraRotationTask)
{
    FldCameraRotationWork* work;
    RwCamera* camera;
    RwFrame* cameraFrame;
    f32 sine;
    f32 sineDelta;

    work = (FldCameraRotationWork*)cameraRotationTask->workData;
    if (work->state == 2)
    {
        return KWLNTASK_STOP;
    }
    if (work->state != 1)
    {
        if (work->state != 0)
        {
            return KWLNTASK_CONTINUE;
        }

        camera = kwlnGetMainCamera();
        cameraFrame = (RwFrame*)camera->object.object.parent;
        FUN_004c31b0(work->initialRotation, cameraFrame, CAMERA_UP_AXIS, 2);
        work->state++;
    }

    if (work->frame < work->duration)
    {
        work->frame++;
        sine = sinf((2.0f * gPI * (f32)work->frame) / (f32)work->duration);
        sineDelta = sine - work->lastSine;
        camera = kwlnGetMainCamera();
        cameraFrame = (RwFrame*)camera->object.object.parent;
        FUN_004c31b0(work->angleDelta * sineDelta, cameraFrame,
                     CAMERA_UP_AXIS, 2);
        work->lastSine = sine;
    }
    else
    {
        work->state++;
    }

    return KWLNTASK_CONTINUE;
}

// FUN_001d6240
void func_001d6240(KwlnTask* cameraRotationTask)
{
    RwFree(cameraRotationTask->workData);
}

// FUN_001d6270 NONMATCHING
KwlnTask* func_001d6270(KwlnTask* parentTask, s32 duration, s32 heading)
{
    FldCameraRotationWork* work;
    KwlnTask* task;
    RwMatrix* playerMatrix;
    RwFrame* cameraFrame;
    f32 playerHeading;
    f32 cameraHeading;
    f32 directDelta;
    f32 wrappedDelta;

    if (CAMERA_DATA_U32(0x008717e8) == 0)
    {
        return NULL;
    }

    work = (FldCameraRotationWork*)RwCalloc(1, sizeof(FldCameraRotationWork),
                                             rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parentTask, 10,
                                          "field camera rotation",
                                          (KwlnTaskUpdateFunc)func_001d5f90,
                                          (KwlnTaskDestroyFunc)func_001d6240,
                                          work);
    work->duration = duration;

    playerMatrix = mdlGetMatrix((Model*)(uintptr_t)CAMERA_DATA_U32(0x008717f0));
    playerHeading = FUN_001a5aa0(playerMatrix);
    if (playerHeading < 0.0f)
    {
        playerHeading += 360.0f;
    }

    cameraFrame = (RwFrame*)kwlnGetMainCamera()->object.object.parent;
    cameraHeading = FUN_001a5aa0(RwFrameGetLTM(cameraFrame));
    if (cameraHeading < 0.0f)
    {
        cameraHeading += 360.0f;
    }

    if (heading == -1)
    {
        if (playerHeading < 45.0f || playerHeading >= 315.0f)
        {
            playerHeading = 0.0f;
        }
        else if (playerHeading < 135.0f)
        {
            playerHeading = 90.0f;
        }
        else if (playerHeading < 225.0f)
        {
            playerHeading = 180.0f;
        }
        else if (playerHeading < 315.0f)
        {
            playerHeading = 270.0f;
        }
        else
        {
            FUN_0019d3f0((const char*)(uintptr_t)0x00683a78, 0x34e);
        }
    }
    else
    {
        playerHeading += (f32)heading;
        while (playerHeading > 360.0f)
        {
            playerHeading -= 360.0f;
        }
    }

    directDelta = playerHeading - cameraHeading;
    if (cameraHeading > 180.0f)
    {
        wrappedDelta = (360.0f - cameraHeading) + playerHeading;
    }
    else
    {
        wrappedDelta = -((360.0f - playerHeading) + cameraHeading);
    }
    while (directDelta > 360.0f)
    {
        directDelta -= 360.0f;
    }
    while (wrappedDelta > 360.0f)
    {
        wrappedDelta -= 360.0f;
    }

    if (fabsf(directDelta) < fabsf(wrappedDelta))
    {
        work->angleDelta = directDelta;
    }
    else
    {
        work->angleDelta = wrappedDelta;
    }
    return task;
}

// FUN_001d6630 NONMATCHING
KwlnTask* func_001d6630(KwlnTask* parentTask, s32 duration, s32 heading)
{
    FldCameraRotationWork* work;
    KwlnTask* task;
    RwFrame* cameraFrame;
    f32 ignoredHeading;
    f32 desiredHeading;
    f32 cameraHeading;
    f32 directDelta;
    f32 wrappedDelta;

    if (CAMERA_DATA_U32(0x008717e8) == 0)
    {
        return NULL;
    }

    work = (FldCameraRotationWork*)RwCalloc(1, sizeof(FldCameraRotationWork),
                                             rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parentTask, 10,
                                          "field camera rotation",
                                          (KwlnTaskUpdateFunc)func_001d5f90,
                                          (KwlnTaskDestroyFunc)func_001d6240,
                                          work);
    work->duration = duration;

    ignoredHeading = FUN_001a5aa0(
        mdlGetMatrix((Model*)(uintptr_t)CAMERA_DATA_U32(0x008717f0)));
    (void)ignoredHeading;
    cameraFrame = (RwFrame*)kwlnGetMainCamera()->object.object.parent;
    cameraHeading = FUN_001a5aa0(RwFrameGetLTM(cameraFrame));
    if (cameraHeading < 0.0f)
    {
        cameraHeading += 360.0f;
    }

    desiredHeading = (f32)heading;
    while (desiredHeading > 360.0f)
    {
        desiredHeading -= 360.0f;
    }
    while (desiredHeading < -360.0f)
    {
        desiredHeading += 360.0f;
    }

    directDelta = desiredHeading - cameraHeading;
    if (cameraHeading > 180.0f)
    {
        wrappedDelta = (360.0f - cameraHeading) + desiredHeading;
    }
    else
    {
        wrappedDelta = -((360.0f - desiredHeading) + cameraHeading);
    }
    while (directDelta > 360.0f)
    {
        directDelta -= 360.0f;
    }
    while (wrappedDelta > 360.0f)
    {
        wrappedDelta -= 360.0f;
    }

    if (fabsf(directDelta) < fabsf(wrappedDelta))
    {
        work->angleDelta = directDelta;
    }
    else
    {
        work->angleDelta = wrappedDelta;
    }
    return task;
}

// FUN_001d68e0 NONMATCHING
void func_001d68e0(CmrFile* cmr, KwlnTask* fldCameraTask)
{
    FldCamera* fldCamera;
    RwCamera* camera;
    RwFrame* cameraFrame;

    fldCamera = (FldCamera*)fldCameraTask->workData;
    camera = kwlnGetMainCamera();
    cameraFrame = (RwFrame*)camera->object.object.parent;
    memset(cmr, 0, sizeof(CmrFile));
    cmr->fov = K_View_GetFov(camera);
    cmr->mat = cameraFrame->modelling;
    cmr->type = (u16)fldCamera->type;
    cmr->posOffset = fldCamera->posOffset;
    cmr->xzDeadZone = fldCamera->xzDeadZone;
    cmr->yDeadZone = fldCamera->yDeadZone;
}

// FUN_001d69e0 NONMATCHING
void func_001d69e0(KwlnTask* fldCameraTask, const CmrFile* cmr)
{
    FldCamera* fldCamera;
    RwCamera* camera;
    RwFrame* cameraFrame;

    camera = kwlnGetMainCamera();
    cameraFrame = (RwFrame*)camera->object.object.parent;
    K_View_SetFov(camera, cmr->fov);
    FUN_004cb7f0(cameraFrame, &cmr->mat, 0);
    func_001d5c10(fldCameraTask, cmr->type);

    fldCamera = (FldCamera*)fldCameraTask->workData;
    fldCamera->posOffset = cmr->posOffset;
    fldCamera->xzDeadZone = cmr->xzDeadZone;
    fldCamera->yDeadZone = cmr->yDeadZone;

    if (fldCamera->type == 2)
    {
        FUN_001a1210(camera, &cameraFrame->modelling.pos,
                     &fldCamera->frame->modelling.pos, NULL);
    }
    else if (fldCamera->type == 5 || fldCamera->type == 0)
    {
        func_001d5e30(K_Field_Get()->cameraCtlTask, 0.0f);
    }
}

// FUN_001d6b10 NONMATCHING
HCdvd* func_001d6b10(void)
{
    char path[128];
    u32* fieldIds;

    fieldIds = (u32*)(uintptr_t)CAMERA_FIELD_IDS;
    if (fieldIds[0] == 0xffffffff)
    {
        return NULL;
    }

    if (K_Fldrc_GetFldPacCdvd() == NULL)
    {
        sprintf(path, "field/env/f%03d_%03d.CMR",
                (s32)fieldIds[0], (s32)fieldIds[1]);
        if (H_Cdvd_FileExists(path) == false)
        {
            return NULL;
        }
        return H_Cdvd_Request(path, HCDVD_FILENORMAL);
    }

    return (HCdvd*)(uintptr_t)1;
}

// FUN_001d6bc0 NONMATCHING
u32 func_001d6bc0(HCdvd* cmrRequest, RwMatrix* matrix, f32* fov, u32* type,
                  RwV3d* posOffset, f32* xzDeadZone, f32* yDeadZone)
{
    CmrFile* cmr;
    FldCamera* fldCamera;
    RwCamera* camera;
    RwFrame* cameraFrame;
    char path[76];
    u32 fileSize;
    u32* fieldIds;
    HCdvd* fldPacCdvd;

    if (cmrRequest == NULL)
    {
        return true;
    }

    fldPacCdvd = K_Fldrc_GetFldPacCdvd();
    fieldIds = (u32*)(uintptr_t)CAMERA_FIELD_IDS;
    if (fldPacCdvd == NULL)
    {
        if (H_Cdvd_IsFileLoaded(cmrRequest) == false)
        {
            return false;
        }
        cmr = (CmrFile*)cmrRequest->fileMemory;
    }
    else
    {
        sprintf(path, "field/pack/f%03d_%03d.CMR",
                (s32)fieldIds[0], (s32)fieldIds[1]);
        cmr = (CmrFile*)H_Cdvd_CacheFindFile(path, &fileSize);
        if (cmr == NULL)
        {
            return true;
        }
    }

    if (matrix == NULL)
    {
        camera = kwlnGetMainCamera();
        cameraFrame = (RwFrame*)camera->object.object.parent;
        K_View_SetFov(camera, cmr->fov);
        FUN_004cb7f0(cameraFrame, &cmr->mat, 0);
        func_001d5c10(K_Field_Get()->cameraCtlTask, cmr->type);

        fldCamera = (FldCamera*)K_Field_Get()->cameraCtlTask->workData;
        fldCamera->posOffset = cmr->posOffset;
        if (cmr->xzDeadZone == 0.0f && K_Scene_001a0250() == false)
        {
            fldCamera->xzDeadZone = 50.0f;
        }
        else
        {
            fldCamera->xzDeadZone = cmr->xzDeadZone;
        }
        fldCamera->yDeadZone = cmr->yDeadZone;

        if (fldCamera->type == 2)
        {
            FUN_001a1210(camera, &cameraFrame->modelling.pos,
                         &fldCamera->frame->modelling.pos, NULL);
        }
        else if (fldCamera->type == 5 || fldCamera->type == 0)
        {
            func_001d5e30(K_Field_Get()->cameraCtlTask, 0.0f);
        }
    }
    else
    {
        *matrix = cmr->mat;
        *fov = cmr->fov;
        *type = (u32)cmr->type;
        *posOffset = cmr->posOffset;
        *xzDeadZone = cmr->xzDeadZone;
        *yDeadZone = cmr->yDeadZone;
    }

    if (fldPacCdvd == NULL)
    {
        H_Cdvd_Destroy(cmrRequest);
    }
    return true;
}

// FUN_001d70a0 NONMATCHING
void func_001d70a0(void)
{
    FldCameraResource* resource;
    FldCamera* fldCamera;
    RwCamera* camera;
    RwFrame* cameraFrame;
    RwMatrix matrix;

    resource = (FldCameraResource*)MT_Scene_GetResListHead(RESRC_TYPE_20);
    if (resource == NULL)
    {
        return;
    }

    camera = kwlnGetMainCamera();
    cameraFrame = (RwFrame*)camera->object.object.parent;
    K_View_SetFov(camera, resource->fov);
    func_004c2330(&matrix, resource->matrix);
    FUN_004cb7f0(cameraFrame, &matrix, 0);
    func_001d5c10(K_Field_Get()->cameraCtlTask, resource->type);

    fldCamera = (FldCamera*)K_Field_Get()->cameraCtlTask->workData;
    fldCamera->posOffset = resource->posOffset;
    if (resource->xzDeadZone == 0.0f && K_Scene_001a0250() == false)
    {
        fldCamera->xzDeadZone = 50.0f;
    }
    else
    {
        fldCamera->xzDeadZone = resource->xzDeadZone;
    }
    fldCamera->yDeadZone = resource->yDeadZone;

    if (fldCamera->type == 2)
    {
        FUN_001a1210(camera, &cameraFrame->modelling.pos,
                     &fldCamera->frame->modelling.pos, NULL);
    }
    else if (fldCamera->type == 5 || fldCamera->type == 0)
    {
        func_001d5e30(K_Field_Get()->cameraCtlTask, 0.0f);
    }
}

// FUN_001d7260 NONMATCHING
void func_001d7260(void)
{
    char path[128];
    HCdvd* object;
    void* opmap;

    sprintf(path, DAT_00683b10);
    object = (HCdvd*)func_00100d80(path, 0);
    func_001023a0(object);
    opmap = ((void* (*)(u32, u32, u32))DAT_00960184[0])(
        1, object->fileSize, 0x40000);
    *(void**)(uintptr_t)0x007ce2b0 = opmap;
    func_00521250(opmap, (u32)object->fileMemory, object->fileSize);
    func_00100ec0(object);
}