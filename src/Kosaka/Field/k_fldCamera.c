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

#define CAMERA_DATA_U32(address) (*(volatile /* Removing this file's qualifier batch loses 1 MATCH(es) and worsens 0 other function(s) - measured W170. */ u32*)(uintptr_t)(address))
#define CAMERA_FIELD_IDS (*(volatile /* Removing this file's qualifier batch loses 1 MATCH(es) and worsens 0 other function(s) - measured W170. */ u32**)(uintptr_t)0x007cd540)
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

typedef union FldCameraRuntimeCmr
{
    struct
    {
        RwMatrix mat;           // 0x00
        f32 fov;                // 0x40
        u16 type;               // 0x44
        u16 pad;                // 0x46
        RwV3d posOffset;        // 0x48
        f32 xzDeadZone;         // 0x54
        f32 yDeadZone;          // 0x58
        u32 unk;                // 0x5c
    } fields;
    u_long128 q[6];
} FldCameraRuntimeCmr;

extern f32 FUN_001a5aa0(const RwMatrix* matrix);
extern void FUN_001a1210(RwCamera* camera, const RwV3d* target,
                         const RwV3d* position, const RwV3d* upVector);
extern void FUN_0019d3f0(const char* file, s32 line);
extern void FUN_0048d270(void* curve, s32 index, RwV3d* dst);
extern void FUN_0048d480(f32 time, void* curve, s32 mode, RwV3d* dst, void* aux);
extern void FUN_004cb7f0(RwFrame* frame, const RwMatrix* matrix, u32 flags);
extern void FUN_004cb890(RwFrame* frame, f32 amount, const RwV3d* axis, u32 mode);
extern void FUN_004c31b0(f32 angle, RwFrame* frame, const RwV3d* axis, u32 mode);
extern void func_004c2330(RwMatrix* dst, const RwMatrix* src);
extern s32 func_00530da0(f32 value);
extern s32 func_0052e118(s32 value);
extern s32 func_0045ec00(s32 left, s32 right);
extern const char DAT_00683b10[];
extern const char D_00683A8C[];
extern const char D_00683AD0[];
extern const char D_00683A90[];
extern const u64 D_00683A98;
#pragma alias D_00683A98_abs D_00683A98
extern volatile u8 D_00683A98_abs[];
extern volatile const f32 D_00683AA0;
extern void* DAT_00960184[];
extern u32* PTR_DAT_007cd540;
extern void* D_007CE2B0;
extern void* func_00100d80(const char* path, u32 mode);
extern void func_001023a0(void* object);
extern void func_00100ec0(void* object);
extern void func_00521250(void* destination, const void* source, u32 size);

// FUN_001d5c00
u32 K_FldCamera_GetType(KwlnTask* fldCameraTask)
{
    return ((FldCamera*)fldCameraTask->workData)->type;
}

// FUN_001d5c10
void func_001d5c10(KwlnTask* fldCameraTask, u32 type)
{
    FldCamera* fldCamera;
    void* field;
    void* fieldSub;
    f32 amount;
    RwV3d* destination;
    void* curve;
    s32 i;
    RwV3d center;

    fldCamera = (FldCamera*)fldCameraTask->workData;
    fldCamera->type = type;
    if (type == 3)
    {
        goto setup_dead_zone;
    }
    if (type != 4)
    {
        goto cleanup;
    }

setup_dead_zone:
    curve = *(void**)((u8*)*(void**)((u8*)K_Field_Get() + 0x116c) + 0xa1c);
    if (curve == NULL)
    {
        return;
    }
    for (i = 0; i < 9; i++)
    {
        field = K_Field_Get();
        fieldSub = (void*)*(void**)((u8*)field + 0x116c);
        amount = (f32)i * 0.125f;
        /* Removing this barrier loses func_001d5c10 (MATCH nd0 -> MISMATCH nd21) - measured W164. */
        asm ("" : "+m"(amount));
        destination = &fldCamera->deadZonePath[i];
        FUN_0048d480(amount,
                     (void*)*(void**)((u8*)fieldSub + 0xa1c),
                     10, destination, NULL);
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
    curve = *(void**)((u8*)*(void**)((u8*)K_Field_Get() + 0x116c) + 0xa1c);
    FUN_0048d270(curve, 0, &center);
    K_Draw_SetPointCenter(fldCamera->pointTask0, &center);
    K_Draw_SetPointColor(fldCamera->pointTask0,
                         (const RwRGBA*)D_00683A8C);
    K_Draw_SetPointColor(fldCamera->pointTask1,
                         (const RwRGBA*)D_00683A90);
    K_Draw_SetPointColor(fldCamera->pointTask2,
                         (const RwRGBA*)D_00683A90);
    return;

cleanup:
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

// FUN_001d5e10
RwV3d* K_FldCamera_GetPos(KwlnTask* fldCameraTask)
{
    return &((FldCamera*)fldCameraTask->workData)->frame->modelling.pos;
}

// Reconstructed frame-position capture, axis setup, frame update, and camera look-at.
// Keep the axis address materialized before the absolute global loads; retail stores directly to the stack object.
// Measured: direct stores are nd26 without this pragma and nd0 with it; pointer stores remain nd4.
#pragma opt_propagation off
// FUN_001d5e30
void func_001d5e30(KwlnTask* fldCameraTask, f32 amount)
{
    FldCamera* fldCamera;
    RwCamera* camera;
    RwFrame* cameraFrame;
    RwV3d cameraPosition;
    RwV3d target;
    RwV3d axis;
    RwV3d* axisPtr;
    u64 axisXY;
    f32 axisZ;
    u8* targetBytes;
    u32 i;

    fldCamera = (FldCamera*)fldCameraTask->workData;
    if (fldCamera->type != FLDCAMERA_TYPE_0)
    {
        return;
    }

    camera = kwlnGetMainCamera();
    cameraFrame = (RwFrame*)camera->object.object.parent;
    cameraPosition = cameraFrame->modelling.pos;
    targetBytes = (u8*)&target;
    i = 0xc;
    if (targetBytes != NULL)
    {
        do
        {
            *targetBytes = 0;
            targetBytes++;
            i--;
        } while (i != 0);
    }
    axisPtr = (RwV3d*)((u8*)&axis + 0);
    axisXY = *(volatile u64*)D_00683A98_abs;
    axisZ = D_00683AA0;
    *(u64*)&axis = axisXY;
    axis.z = axisZ;
    FUN_004cb890(cameraFrame, amount, axisPtr, 2);
    cameraPosition = cameraFrame->modelling.pos;
    camera = kwlnGetMainCamera();
    FUN_001a1210(camera, &cameraPosition, &target, NULL);

}
#pragma opt_propagation reset
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

// Reconstructed the complete camera-rotation state machine and gated look-at updates.
// Remaining differences are MWCC branch/layout scheduling and axis setup ordering.
// FUN_001d5f90 NONMATCHING
void* func_001d5f90(KwlnTask* cameraRotationTask)
{
    FldCameraRotationWork* work;
    f32 initialRotation;
    f32 sine;
    f32 sineDelta;
    RwCamera* camera;
    RwFrame* cameraFrame;
    Field* field;

    work = (FldCameraRotationWork*)cameraRotationTask->workData;
    if (work->state == 2)
    {
        return KWLNTASK_STOP;
    }
    if (work->state == 0)
    {
        initialRotation = work->initialRotation;
        field = K_Field_Get();
        if (((FldCamera*)field->cameraCtlTask->workData)->type == FLDCAMERA_TYPE_0)
        {
            RwV3d cameraPosition;
            RwV3d target;
            RwV3d axis;
            u64 axisXY;
            u8* targetBytes;
            u32 i;
            RwV3d* axisPtr;

            camera = kwlnGetMainCamera();
            cameraFrame = (RwFrame*)camera->object.object.parent;
            cameraPosition = cameraFrame->modelling.pos;
            targetBytes = (u8*)&target;
            i = 0xc;
            if (targetBytes != NULL)
            {
                do
                {
                    *targetBytes = 0;
                    targetBytes++;
                    i--;
                } while (i != 0);
            }
            axisPtr = &axis;
            axisXY = *(u64*)(uintptr_t)0x00683a98;
            *(u64*)axisPtr = axisXY;
            axisPtr->z = *(f32*)(uintptr_t)0x00683aa0;
            FUN_004cb890(cameraFrame, initialRotation, axisPtr, 2);
            cameraPosition = cameraFrame->modelling.pos;
            camera = kwlnGetMainCamera();
            FUN_001a1210(camera, &cameraPosition, &target, NULL);
        }
        work->state++;
    }

    if (work->frame < work->duration)
    {
        work->frame++;
        sine = sinf((2.0f * gPI * (f32)work->frame) / (f32)work->duration);
        sineDelta = sine - work->lastSine;
        sineDelta *= work->angleDelta;
        field = K_Field_Get();
        if (((FldCamera*)field->cameraCtlTask->workData)->type == FLDCAMERA_TYPE_0)
        {
            RwV3d cameraPosition;
            RwV3d target;
            RwV3d axis;
            u64 axisXY;
            u8* targetBytes;
            u32 i;
            RwV3d* axisPtr;

            camera = kwlnGetMainCamera();
            cameraFrame = (RwFrame*)camera->object.object.parent;
            cameraPosition = cameraFrame->modelling.pos;
            targetBytes = (u8*)&target;
            i = 0xc;
            if (targetBytes != NULL)
            {
                do
                {
                    *targetBytes = 0;
                    targetBytes++;
                    i--;
                } while (i != 0);
            }
            axisPtr = &axis;
            axisXY = *(u64*)(uintptr_t)0x00683a98;
            *(u64*)axisPtr = axisXY;
            axisPtr->z = *(f32*)(uintptr_t)0x00683aa0;
            FUN_004cb890(cameraFrame, sineDelta, axisPtr, 2);
            cameraPosition = cameraFrame->modelling.pos;
            camera = kwlnGetMainCamera();
            FUN_001a1210(camera, &cameraPosition, &target, NULL);
        }
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
    KwlnTask* task;
    FldCameraRotationWork* work;
    RwMatrix* playerMatrix;
    RwFrame* cameraFrame;
    f32 playerHeading;
    f32 cameraHeading;
    f32 directDelta;
    f32 wrappedDelta;

    task = NULL;
    if (CAMERA_DATA_U32(0x008717e8) == 0)
    {
        goto done;
    }

    work = (FldCameraRotationWork*)RwCalloc(1, sizeof(FldCameraRotationWork),
                                             rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        goto done;
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

    if (func_0045ec00(func_0052e118(func_00530da0(directDelta)),
                      func_0052e118(func_00530da0(wrappedDelta))) != 0)
    {
        work->angleDelta = directDelta;
    }
    else
    {
        work->angleDelta = wrappedDelta;
    }
done:
    return task;
}

// FUN_001d6630 NONMATCHING
KwlnTask* func_001d6630(KwlnTask* parentTask, s32 duration, s32 heading)
{
    KwlnTask* task;
    FldCameraRotationWork* work;
    RwFrame* cameraFrame;
    f32 ignoredHeading;
    f32 desiredHeading;
    f32 cameraHeading;
    f32 directDelta;
    f32 wrappedDelta;

    task = NULL;
    if (CAMERA_DATA_U32(0x008717e8) == 0)
    {
        goto done;
    }

    work = (FldCameraRotationWork*)RwCalloc(1, sizeof(FldCameraRotationWork),
                                             rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        goto done;
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

    if (func_0045ec00(func_0052e118(func_00530da0(directDelta)),
                      func_0052e118(func_00530da0(wrappedDelta))) != 0)
    {
        work->angleDelta = directDelta;
    }
    else
    {
        work->angleDelta = wrappedDelta;
    }
done:
    return task;
}

// FUN_001d68e0
void func_001d68e0(CmrFile* cmr, KwlnTask* fldCameraTask)
{
    u8 data[0x60] __attribute__((aligned(16)));
    FldCamera* fldCamera;
    RwCamera* camera;
    RwFrame* cameraFrame;

    fldCamera = (FldCamera*)fldCameraTask->workData;
    camera = kwlnGetMainCamera();
    cameraFrame = (RwFrame*)camera->object.object.parent;
    memset(data, 0, 0x60);
    ((FldCameraRuntimeCmr*)data)->fields.fov =
        K_View_GetFov(kwlnGetMainCamera());
    ((FldCameraRuntimeCmr*)data)->fields.mat = cameraFrame->modelling;
    ((FldCameraRuntimeCmr*)data)->fields.type = (u16)fldCamera->type;
    ((FldCameraRuntimeCmr*)data)->fields.posOffset = fldCamera->posOffset;
    ((FldCameraRuntimeCmr*)data)->fields.xzDeadZone = fldCamera->xzDeadZone;
    ((FldCameraRuntimeCmr*)data)->fields.yDeadZone = fldCamera->yDeadZone;
    *(FldCameraRuntimeCmr*)cmr = *(FldCameraRuntimeCmr*)data;
}

// FUN_001d69e0
void func_001d69e0(KwlnTask* fldCameraTask, const CmrFile* cmr)
{
    KwlnTask* task;
    const FldCameraRuntimeCmr* runtime;
    RwFrame* cameraFrame;
    RwCamera* mainCamera;
    RwV3d* targetPosition;

    runtime = (const FldCameraRuntimeCmr*)cmr;
    task = fldCameraTask;
    K_View_SetFov(kwlnGetMainCamera(), runtime->fields.fov);
    FUN_004cb7f0(
        (RwFrame*)kwlnGetMainCamera()->object.object.parent,
        &runtime->fields.mat, 0);
    func_001d5c10(task, runtime->fields.type);

    ((FldCamera*)task->workData)->posOffset = runtime->fields.posOffset;
    ((FldCamera*)task->workData)->xzDeadZone = runtime->fields.xzDeadZone;
    ((FldCamera*)task->workData)->yDeadZone = runtime->fields.yDeadZone;

    switch (((FldCamera*)task->workData)->type)
    {
        case 0:
        case 5:
            func_001d5e30(K_Field_Get()->cameraCtlTask, 0.0f);
            break;
        case 2:
            cameraFrame =
                (RwFrame*)kwlnGetMainCamera()->object.object.parent;
            targetPosition =
                &((FldCamera*)task->workData)->frame->modelling.pos;
            mainCamera = kwlnGetMainCamera();
            FUN_001a1210(
                mainCamera, &cameraFrame->modelling.pos,
                targetPosition, NULL);
            break;
    }
}

// FUN_001d6b10
HCdvd* func_001d6b10(void)
{
    char path[128];

    if (PTR_DAT_007cd540[0] == 0xffffffff)
    {
        return NULL;
    }

    if (K_Fldrc_GetFldPacCdvd() == NULL)
    {
        sprintf((char*)((u8*)(uintptr_t)path + 0),
                (const char*)((u8*)(uintptr_t)D_00683AD0 + 0),
                (s32)PTR_DAT_007cd540[0], (s32)PTR_DAT_007cd540[1]);
        if (H_Cdvd_FileExists(path) != false)
        {
            goto request;
        }
        return NULL;
request:
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

    if (cmrRequest == NULL)
    {
        return true;
    }

    if (K_Fldrc_GetFldPacCdvd() == NULL)
    {
        if (H_Cdvd_IsFileLoaded(cmrRequest) == false)
        {
            return false;
        }
        cmr = (CmrFile*)cmrRequest->fileMemory;
        if (matrix != NULL)
        {
            *matrix = cmr->mat;
            *fov = cmr->fov;
            *type = (u32)cmr->type;
            *posOffset = cmr->posOffset;
            *xzDeadZone = cmr->xzDeadZone;
            *yDeadZone = cmr->yDeadZone;
        }
        else
        {
            K_View_SetFov(kwlnGetMainCamera(), cmr->fov);
            cameraFrame =
                (RwFrame*)kwlnGetMainCamera()->object.object.parent;
            FUN_004cb7f0(cameraFrame, &cmr->mat, 0);
            func_001d5c10(K_Field_Get()->cameraCtlTask, cmr->type);
            ((FldCamera*)K_Field_Get()->cameraCtlTask->workData)->posOffset =
                cmr->posOffset;
            if (cmr->xzDeadZone == 0.0f && K_Scene_001a0250() == false)
            {
                cmr->xzDeadZone = 50.0f;
            }
            ((FldCamera*)K_Field_Get()->cameraCtlTask->workData)->xzDeadZone =
                cmr->xzDeadZone;
            ((FldCamera*)K_Field_Get()->cameraCtlTask->workData)->yDeadZone =
                cmr->yDeadZone;
            fldCamera = (FldCamera*)K_Field_Get()->cameraCtlTask->workData;
            if (fldCamera->type == 2)
            {
                FUN_001a1210(
                    kwlnGetMainCamera(),
                    &((RwFrame*)kwlnGetMainCamera()->object.object.parent)
                         ->modelling.pos,
                    &fldCamera->frame->modelling.pos, NULL);
            }
            else if (fldCamera->type == 5 || fldCamera->type == 0)
            {
                func_001d5e30(K_Field_Get()->cameraCtlTask, 0.0f);
            }
        }
        H_Cdvd_Destroy(cmrRequest);
        return true;
    }

    fieldIds = PTR_DAT_007cd540;
    sprintf(path, "field/pack/f%03d_%03d.CMR",
            (s32)fieldIds[0], (s32)fieldIds[1]);
    cmr = (CmrFile*)H_Cdvd_CacheFindFile(path, &fileSize);
    if (cmr == NULL)
    {
        return true;
    }

    if (matrix != NULL)
    {
        *matrix = cmr->mat;
        *fov = cmr->fov;
        *type = (u32)cmr->type;
        *posOffset = cmr->posOffset;
        *xzDeadZone = cmr->xzDeadZone;
        *yDeadZone = cmr->yDeadZone;
    }
    else
    {
        K_View_SetFov(kwlnGetMainCamera(), cmr->fov);
        cameraFrame = (RwFrame*)kwlnGetMainCamera()->object.object.parent;
        FUN_004cb7f0(cameraFrame, &cmr->mat, 0);
        func_001d5c10(K_Field_Get()->cameraCtlTask, cmr->type);
        ((FldCamera*)K_Field_Get()->cameraCtlTask->workData)->posOffset =
            cmr->posOffset;
        if (cmr->xzDeadZone == 0.0f && K_Scene_001a0250() == false)
        {
            cmr->xzDeadZone = 50.0f;
        }
        ((FldCamera*)K_Field_Get()->cameraCtlTask->workData)->xzDeadZone =
            cmr->xzDeadZone;
        ((FldCamera*)K_Field_Get()->cameraCtlTask->workData)->yDeadZone =
            cmr->yDeadZone;
        fldCamera = (FldCamera*)K_Field_Get()->cameraCtlTask->workData;
        if (fldCamera->type == 2)
        {
            FUN_001a1210(
                kwlnGetMainCamera(),
                &((RwFrame*)kwlnGetMainCamera()->object.object.parent)
                     ->modelling.pos,
                &fldCamera->frame->modelling.pos, NULL);
        }
        else if (fldCamera->type == 5 || fldCamera->type == 0)
        {
            func_001d5e30(K_Field_Get()->cameraCtlTask, 0.0f);
        }
    }

    return true;
}

// FUN_001d70a0
void func_001d70a0(void)
{
    FldCameraResource* resource;
    KwlnTask* task;
    RwCamera* camera;
    RwFrame* cameraFrame;
    RwV3d* targetPosition;
    RwMatrix matrix;
    f32 xzDeadZone;
    f32 yDeadZone;

    resource = (FldCameraResource*)MT_Scene_GetResListHead(RESRC_TYPE_20);
    if (resource == NULL)
    {
        return;
    }

    K_View_SetFov(kwlnGetMainCamera(), resource->fov);
    func_004c2330(&matrix, resource->matrix);
    FUN_004cb7f0((RwFrame*)kwlnGetMainCamera()->object.object.parent,
                 &matrix, 0);
    func_001d5c10(K_Field_Get()->cameraCtlTask, resource->type);
    ((FldCamera*)K_Field_Get()->cameraCtlTask->workData)->posOffset =
        resource->posOffset;

    if (resource->xzDeadZone == 0.0f && K_Scene_001a0250() == false)
    {
        resource->xzDeadZone = 50.0f;
    }
    xzDeadZone = resource->xzDeadZone;
    ((FldCamera*)K_Field_Get()->cameraCtlTask->workData)->xzDeadZone =
        xzDeadZone;
    yDeadZone = resource->yDeadZone;
    ((FldCamera*)K_Field_Get()->cameraCtlTask->workData)->yDeadZone =
        yDeadZone;

    task = K_Field_Get()->cameraCtlTask;
    switch (((FldCamera*)task->workData)->type)
    {
    case 0:
    case 5:
        func_001d5e30(K_Field_Get()->cameraCtlTask, 0.0f);
        break;
    case 2:
        cameraFrame =
            (RwFrame*)kwlnGetMainCamera()->object.object.parent;
        targetPosition =
            &((FldCamera*)task->workData)->frame->modelling.pos;
        camera = kwlnGetMainCamera();
        FUN_001a1210(camera, &cameraFrame->modelling.pos,
                     targetPosition, NULL);
        break;
    }
}

// FUN_001d7260
void func_001d7260(void)
{
    char path[128];
    HCdvd* object;
    volatile /* Removing this qualifier loses func_001d7260 (MATCH nd0 -> MISMATCH nd18, size 148 -> 148) - measured W170. */ HCdvd* volatileObject;
    void* opmap;
    u32 count;

    sprintf(path, DAT_00683b10);
    object = (HCdvd*)func_00100d80(path, 0);
    volatileObject = object;
    func_001023a0(object);
    count = 1;
    opmap = D_007CE2B0 =
        ((void* (*)(u32, u32, u32))DAT_00960184[0])(
            count, volatileObject->fileSize, 0x40000);
    func_00521250(opmap, object->fileMemory, volatileObject->fileSize);
    func_00100ec0(object);
}