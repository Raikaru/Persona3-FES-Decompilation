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

#include "Kosaka/Field/k_encount.h"
#include "Kosaka/Field/k_unit.h"
#include "Kosaka/Field/k_fldFrame.h"
#include "Kosaka/Field/k_event.h"
#include "Main/g_data.h"
#include "Main/Battle/Data/datUnit.h"
#include "Main/Battle/Data/datPersona.h"
#include "Script/scrScriptProcess.h"
#include "rw/rprandom.h"
#pragma alias func_004c69f0_y2 func_004c69f0
#pragma alias FUN_001a1210_y2 FUN_001a1210
#pragma alias FUN_0048d480_y2 FUN_0048d480
extern s32 func_001c0040(void);
extern u32 RpRandom(void);
#pragma alias jtbl_0096017C_abs jtbl_0096017C
extern u32 jtbl_0096017C_abs[];
extern u8* DAT_007ce4ac;
extern u8* DAT_007ce4b0;
extern u8* DAT_007ce4b4;
extern u8* DAT_007ce4b8;
extern u32 iGpffffb418;
extern RwMatrix* func_004c38c0(void);
extern void func_004c3880(RwMatrix* matrix);
extern f32 func_004c69f0(RwV3d* out, const RwV3d* in);
extern f32 acosf(f32 value);
#pragma alias sDegreesPerRadian D_007CAFA0
extern f32 sDegreesPerRadian;
#pragma alias sEncountAxis D_00683B78
extern RwV3d sEncountAxis;
#pragma alias sEncountForward D_00683B88
extern RwV3d sEncountForward;
typedef struct EncounterWork
{
    u32 state;
    u32 taskSlot;
    u32 paused;
    void* effectHandle;
    u32 pcCount;
    u32 ecCount;
    FldUnit* pc[4];
    FldUnit* ec[4];
    u32 progress;
    u32 duration;
    u32 reaperFlag;
    u32 totalActive;
    u32 pcTotal;
    u32 ecTotal;
    u32 selectedFlatIndex;
} EncounterWork;
typedef struct EncounterRecord
{
    u32 count;
    u32 ids[3];
} EncounterRecord;
typedef struct PeriodicWork
{
    u32 state;
    u32 disabled;
    u32 initialGate;
    u32 timestamp;
    KwlnTask* scriptTask[16];
    EncounterRecord records[16];
} PeriodicWork;
extern KwlnTask* D_00875A40[3];
extern void* func_001a9180(KwlnTask* task);
extern void* func_001a91b0(KwlnTask* task, const RwV3d* position);
extern void func_001a9390(KwlnTask* task, void* handle, u32 value);
extern void func_001a9400(KwlnTask* task, void* handle);
extern void func_00434f70(void);
extern u32 func_001fc720(DatUnit* unit);
extern void func_001fc590(DatUnit* src, DatUnit* dst);
extern u32 func_002ff790(DatUnitGenusBase* genus);
#pragma alias func_002ffb00_u32 func_002ffb00
extern u32 func_002ffb00_u32(DatUnitGenusBase* genus);
extern u16 func_002ffb00(DatUnitGenusBase* genus);
extern u32 datGetMaxHp(s16 pcId);
extern void func_0035c1a0(KwlnTask* task, int record);
extern ScrHeader* D_007CE220;
extern void func_001b00c0(KwlnTask* task);
extern void func_0010a4e0(s32 bank, s32 cue, s32 variant, s32 pan);
#include "Kosaka/Field/k_fldFilter.h"
#include "rw/rwcore.h"
#define FLDFILTER_FILE_SIZE 74752 // in bytes
#define FLDFILTER_QUAD_XPIXELS 80
#define FLDFILTER_QUAD_YPIXELS 64
#define FLDFILTER_GRID_WIDTH  (SCREEN_WIDTH / FLDFILTER_QUAD_XPIXELS)  // 8
#define FLDFILTER_GRID_HEIGHT (SCREEN_HEIGHT / FLDFILTER_QUAD_YPIXELS) // 7
typedef struct
{
    RwIm2DVertex vert[4]; // 0x00
} FilterQuad;
extern void* sFilterFile;
extern s32 sFilterColorOffset;
extern s32 sFilterCurrent;
extern f32 sFilterPrevious;
extern f32 sFilterBlend;
extern s32 sFilterBlendDuration;
extern FilterQuad sFilterGrid[FLDFILTER_GRID_HEIGHT][FLDFILTER_GRID_WIDTH];
#pragma alias sFilterGrid_abs sFilterGrid
extern u8 sFilterGrid_abs[];
extern u32 gp0xffff95d8;
extern f32 fGpffff8248;
#define FLDFILTER_ALPHA gp0xffff95d8
extern const char D_00683A60[];
extern const char D_00683A78[];
extern void (*D_00960090)(u32 state, u32 value);
extern void (*D_009600A0)(RwPrimitiveType primitiveType, RwIm2DVertex* vertices, s32 vertexCount);
#pragma alias D_00960090_abs D_00960090
extern void (*D_00960090_abs[])(u32 state, u32 value);
#pragma alias D_009600A0_abs D_009600A0
extern void (*D_009600A0_abs[])(RwPrimitiveType primitiveType, RwIm2DVertex* vertices, s32 vertexCount);
extern u32 D_00960184[];
extern void (*D_0096017c)(void* memory);
#pragma alias D_0096017c_abs D_0096017c
extern u32 D_0096017c_abs[];
extern void func_004d7f60(s32 state, u32 value);
extern void func_004c69f0_y2(RwV3d* output, const RwV3d* input);
extern void func_004cb420(RwFrame* parent, RwFrame* child);
extern void func_004cb590(RwFrame* frame);
extern RwFrame* func_004caf10(void);
extern RwFrame* func_004caf80(RwFrame* frame);
extern void func_004cb930(RwFrame* frame);
extern void func_004cb750(RwFrame* frame, const RwV3d* translation, RwOpCombineType combine);
extern void FUN_001a1210_y2(RwCamera* camera, const RwV3d* at, const RwV3d* position, const RwV3d* up);
extern void* FUN_0048d480_y2(f32 frame, void* curve, s32 flags, RwV3d* output, s32 unused);
extern const char D_00683A48[];
extern const char D_007CC2CC[];
typedef struct FldFilterCameraWork
{
    u32 state;                 // 0x00
    u32 flags;                 // 0x04
    u32 type;                  // 0x08
    RwFrame* frame;            // 0x0c
    RwFrame* parentFrame;      // 0x10
    RwV3d posOffset;            // 0x14
    f32 xzDeadZone;            // 0x20
    f32 yDeadZone;             // 0x24
    u8 unknown28[0x1c];         // 0x28
    KwlnTask* pointTask0;       // 0x44
    KwlnTask* pointTask1;       // 0x48
    KwlnTask* pointTask2;       // 0x4c
    u8 unknown50[0x10];         // 0x50
    RwV3d cameraPoints[9];       // 0x60
    ResrcModelChar* playerResrc;// 0xcc
} FldFilterCameraWork;
extern void* FUN_001d5220(KwlnTask* cameraTask);
extern void FUN_001d59e0(KwlnTask* cameraTask);


#pragma alias memset_y2 memset


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

// FUN_001d5a90 NONMATCHING
KwlnTask* FUN_001d5a90(KwlnTask* parentTask)
{
    RwFrame** slot0;
    RwFrame** slot1;
    KwlnTask* task;
    FldFilterCameraWork* work;

    work = (*(void* (**)(u32, u32, u32))D_00960184)(1, 0xd0, rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parentTask,
                                          10,
                                          D_00683A60,
                                          (KwlnTaskUpdateFunc)FUN_001d5220,
                                          (KwlnTaskDestroyFunc)FUN_001d59e0,
                                          work);
    slot1 = &work->frame;
    *slot1 = func_004caf10();
    if (*slot1 == NULL)
    {
        kwlnTaskDestroyWithHierarchy(task);
        return NULL;
    }
    func_004cb930(*slot1);
    slot0 = &work->parentFrame;
    *slot0 = ((RwFrame*)kwlnGetMainCamera()->object.object.parent)->object.parent;
    if (*slot0 != NULL)
    {
        func_004cb590(kwlnGetMainCamera()->object.object.parent);
        func_004cb420(*slot0, work->frame);
        func_004cb420(*slot1, kwlnGetMainCamera()->object.object.parent);
    }
    else
    {
        K_Assert(D_00683A78, 0x1b4);
    }
    K_Draw_CreateCylinderTask(task);
    return task;
}

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

// Reconstructed frame-position capture, axis setup, frame update, and camera look-at.
// Keep the axis address materialized before the absolute global loads; retail stores directly to the stack object.
// Measured: direct stores are nd26 without this pragma and nd0 with it; pointer stores remain nd4.
// FUN_001d5e10
RwV3d* K_FldCamera_GetPos(KwlnTask* fldCameraTask)
{
    return &((FldCamera*)fldCameraTask->workData)->frame->modelling.pos;
}
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

// Reconstructed the complete camera-rotation state machine and gated look-at updates.
// Remaining differences are MWCC branch/layout scheduling and axis setup ordering.
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
    memset_y2(data, 0, 0x60);
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

// Negative probe: all 24 permutations of cmr/fldCamera/camera/cameraFrame declarations were neutral at nd211, object 1212/1248 (W418).
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
        if (H_Cdvd_IsFileLoaded(cmrRequest))
        {
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
        return false;
    }

    fieldIds = PTR_DAT_007cd540;
    sprintf(path, "field/pack/f%03d_%03d.CMR",
            (s32)fieldIds[0], (s32)fieldIds[1]);
    cmr = (CmrFile*)H_Cdvd_CacheFindFile(path, &fileSize);
    if (cmr != NULL)
    {
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

// FUN_001d7300 NONMATCHING
u32 K_Encount_001d7300(u32 param_1, u16 flag, u32 areaId)
{
    s32 temp_16;
    s32 temp_3;
    s32 temp_3_3;
    s32 temp_5_2;
    s32 var_20;
    s32 var_19;
    s32 temp_18;
    s32 var_5;
    s32 var_7;
    u16 var_21;
    u32 var_17;
    u32 temp_6;
    s32 temp_hi;
    u8* temp_3_2;
    u8* temp_4;

    var_21 = 0xffff;
    temp_3 = param_1 & 0xffff;
    if (((temp_3 >= 0x14) && (temp_3 < 0x1d) && !(flag & 0xffff)) ||
        ((temp_3 >= 0x28) && (temp_3 < 0x31) && !(flag & 0xffff)) ||
        ((temp_3 >= 0x33) && (temp_3 <= 0x3a)) ||
        ((temp_3 >= 0x47) && (temp_3 < 0x4f)))
    {
        var_17 = *(u16*)(DAT_007ce4b0 + (areaId & 0xffff) * 0xa);
        goto block_15;
    }
    if ((temp_3 >= 0x1f) && (temp_3 < 0x28))
    {
        var_17 = *(u16*)(DAT_007ce4b4 + temp_3 * 0xc8 + (flag & 0xffff) * 0xa -
                         0x1842);
        goto block_15;
    }
    else
    {
        return 0xffffffff;
    }
block_15:
        temp_16 = (var_17 & 0xffff) * 0x7c;
        temp_4 = DAT_007ce4ac + temp_16;
        temp_18 = temp_4[2] + (temp_4[0] + temp_4[1]);
        temp_hi = RpRandom() % temp_18;
        if ((s32)temp_hi < (s32)DAT_007ce4ac[temp_16])
        {
            var_20 = 1;
            var_19 = 0;
            temp_18 = 0x14;
        }
        else if ((s32)temp_hi < (s32)(DAT_007ce4ac[temp_16] +
                                      DAT_007ce4ac[temp_16 + 1]))
        {
            var_20 = 2;
            var_19 = 0x14;
            temp_18 = 0x19;
        }
        else
        {
            var_20 = 4;
            var_19 = 0x19;
            temp_18 = 0x1e;
        }
        if (func_001c0040() == 3)
        {
            var_20 = 4;
            var_19 = 0x19;
            temp_18 = 0x1e;
        }
        var_17 = 0;
        temp_3_2 = DAT_007ce4ac + temp_16;
        for (var_5 = var_19; var_5 < temp_18; var_5 += 1)
        {
            temp_3_3 = var_5 * 4;
            if (*(u16*)(temp_3_2 + temp_3_3 + 4) != 0)
            {
                var_17 += *(u16*)(temp_3_2 + temp_3_3 + 6);
            }
        }
        if (var_17 == 0)
        {
            return 0xffffffff;
        }
        temp_6 = RpRandom() % var_17;
        var_7 = 0;
        temp_5_2 = (s32)(DAT_007ce4ac + temp_16);
        for (; var_19 < temp_18; var_19 += 1)
        {
            temp_3_3 = var_19 * 4;
            var_7 += *(u16*)(temp_5_2 + temp_3_3 + 6);
            if ((s32)temp_6 < var_7)
            {
                var_21 = *(u16*)(temp_3_3 + temp_5_2 + 4);
                break;
            }
        }
        return (var_20 << 0x10) | (var_21 & 0xffff);
    }

// FUN_001d75f0
u8 K_Encount_001d75f0(u32 param_1, u16 flag, u32 areaId)
{
    u8 result;
    int mapId;

    result = 0;
    mapId = param_1 & 0xffff;
    if ((0x14 <= mapId && mapId < 0x1d && flag == 0) ||
        (0x28 <= mapId && mapId < 0x31 && flag == 0) ||
        (0x33 <= mapId && mapId <= 0x3a) ||
        (0x47 <= mapId && mapId < 0x4f))
    {
        result = DAT_007ce4b0[(areaId & 0xffff) * 10 + 3];
    }
    else if (0x1e <= mapId && mapId < 0x28)
    {
        result = DAT_007ce4b4[mapId * 200 - 0x176d];
    }
    return result;
}

// FUN_001d76e0
u8 K_Encount_001d76e0(u32 param_1, u16 flag, u32 areaId)
{
    u8 result;
    int mapId;

    result = 0;
    mapId = param_1 & 0xffff;
    if ((0x14 <= mapId && mapId < 0x1d && flag == 0) ||
        (0x28 <= mapId && mapId < 0x31 && flag == 0) ||
        (0x33 <= mapId && mapId <= 0x3a) ||
        (0x47 <= mapId && mapId < 0x4f))
    {
        result = DAT_007ce4b0[(areaId & 0xffff) * 10 + 2];
    }
    else if (0x1e <= mapId && mapId < 0x28)
    {
        result = DAT_007ce4b4[mapId * 200 - 0x176e];
    }
    return result;
}

// FUN_001d77d0
u8 K_Encount_001d77d0(u32 param_1, u16 flag, u32 areaId)
{
    u8 result;
    int mapId;

    result = 0;
    mapId = param_1 & 0xffff;
    if ((0x14 <= mapId && mapId < 0x1d && flag == 0) ||
        (0x28 <= mapId && mapId < 0x31 && flag == 0) ||
        (0x33 <= mapId && mapId <= 0x3a) ||
        (0x47 <= mapId && mapId < 0x4f))
    {
        result = DAT_007ce4b0[(areaId & 0xffff) * 10 + 4];
    }
    else if (0x1e <= mapId && mapId < 0x28)
    {
        result = DAT_007ce4b4[mapId * 200 - 0x176c];
    }
    return result;
}




static u32 K_Encount_Now(KwlnTask* task)
{
    return task != NULL ? kwlnTaskGetTimer(task) : 0;
}

static void* K_Encount_FieldWord(u32 offset)
{
    Field* field = K_Field_Get();
    return field != NULL ? *(void**)((u8*)field + offset) : NULL;
}

static void K_Encount_Face(FldUnit* unit, FldUnit* target)
{
    RwMatrix matrix;
    RwV3d axis = {0.0f, 1.0f, 0.0f};
    RwV3d delta;
    f32 heading;

    if (unit == NULL || target == NULL || unit->mdl == NULL || target->mdl == NULL ||
        unit->resrc == NULL)
    {
        return;
    }
    delta = mdlGetMatrix(target->mdl)->pos;
    delta.x -= mdlGetMatrix(unit->mdl)->pos.x;
    delta.y = 0.0f;
    delta.z -= mdlGetMatrix(unit->mdl)->pos.z;
    heading = atan2f(delta.x, delta.z) * (180.0f / 3.14159265f);
    memset(&matrix, 0, sizeof(matrix));
    matrix.right.x = 1.0f;
    matrix.up.y = 1.0f;
    matrix.at.z = 1.0f;
    matrix.pos = mdlGetMatrix(unit->mdl)->pos;
    matrix.flags = 0x20003;
    RwMatrixRotate(&matrix, &axis, heading, rwCOMBINEPRECONCAT);
    K_FldFrame_CtlUpdateMdlMat(unit->resrc->collisCtlTask, &matrix);
}

// FUN_001d78c0 NONMATCHING
u16* K_Encount_001d78c0(u32 param_1, u16 flag, u32 areaId)
{
    s32 temp_3;
    s32 var_16;
    s32 var_18;
    s32 var_4;
    s32 var_4_2;
    s32 var_6;
    u16* temp_5;
    u16* var_19;
    u32 temp_3_3;
    u32 var_17;
    void* temp_3_2;

    var_19 = NULL;
    temp_3 = param_1 & 0xffff;
    if (((temp_3 >= 0x14) && (temp_3 < 0x1d) && !(flag & 0xffff)) ||
        ((temp_3 >= 0x28) && (temp_3 < 0x31) && !(flag & 0xffff)) ||
        ((temp_3 >= 0x33) && (temp_3 < 0x3b)) ||
        ((temp_3 >= 0x47) && (temp_3 < 0x4f)))
    {
        var_18 = (s32)(DAT_007ce4b8 +
                       (*(u16*)(DAT_007ce4b0 + ((areaId & 0xffff) * 0xa) + 6) & 0xffff) *
                           0xb4);
        goto block_15;
    }
    if ((temp_3 >= 0x1f) && (temp_3 < 0x28))
    {
        var_18 = (s32)(DAT_007ce4b8 +
                       (*(u16*)(DAT_007ce4b4 + (temp_3 * 0xc8) +
                                ((flag & 0xffff) * 0xa) - 0x183c) & 0xffff) *
                           0xb4);
        goto block_15;
    }
    return NULL;
block_15:
    var_16 = 1;
    if (func_001c0040() == 2)
    {
        var_16 = 2;
    }
    var_4 = 0;
    var_17 = 0;
loop_23:
    if (var_4 < 0xf)
    {
        temp_3_2 = (u8*)var_18 + var_4 * 0xc;
        if (*(u16*)((u8*)temp_3_2 + 2) != 0)
        {
            if ((*(u8*)((u8*)temp_3_2 + 7) & 1) != 0)
            {
                var_17 += var_16 * *(u16*)temp_3_2;
            }
            else
            {
                var_17 += *(u16*)temp_3_2;
            }
        }
        var_4 += 1;
        goto loop_23;
    }
    if (var_17 == 0)
    {
        K_ASSERT(0, 0x147);
    }
    temp_3_3 = RpRandom() % var_17;
    var_4_2 = 0;
    var_6 = 0;
loop_34:
    if (var_4_2 < 0xf)
    {
        temp_5 = (u16*)((u8*)var_18 + var_4_2 * 0xc);
        if (temp_5[1] != 0)
        {
            if ((((u8*)temp_5)[7] & 1) != 0)
            {
                var_6 += var_16 * temp_5[0];
            }
            else
            {
                var_6 += temp_5[0];
            }
            if ((s32)temp_3_3 < var_6)
            {
                var_19 = temp_5;
            }
            else
            {
                goto block_33;
            }
        }
        else
        {
block_33:
            var_4_2 += 1;
            goto loop_34;
        }
    }
    return var_19;
}


// FUN_001d7b70 NONMATCHING
DatUnit* func_001d7b70(KwlnTask* task, s32 flatIndex)
{
    void* temp_8;
    s32 var_10;
    s32 var_4;
    s32 pcCount;
    s32 ecCount;
    s32 var_9;
    s32 var_11;
    s32 temp_3;
    s32 temp_6;
    void* ecBase;

    temp_8 = task->workData;
    var_10 = 0;
    var_4 = 0;
    pcCount = *(s32*)((u8*)temp_8 + 0x10);
    goto pc_check;
pc_body:
    if (flatIndex == var_10)
    {
        return (*(DatUnitGenusBase**)((u8*)*(FldUnit**)((u8*)temp_8 + var_4 * 4 + 0x18) +
                                      0x48))->unit;
    }
    var_10 += 1;
    var_4 += 1;
pc_check:
    if (var_4 < pcCount)
    {
        goto pc_body;
    }
    var_9 = 0;
    ecCount = *(s32*)((u8*)temp_8 + 0x14);
    goto ec_check;
ec_body:
    var_11 = 0;
    temp_6 = var_9 * 4;
    ecBase = (u8*)temp_8 + temp_6;
    goto unit_check;
unit_body:
    temp_3 = var_11 * 0x3c;
    if (((DatUnit*)((u8*)(*(DatUnitGenusBase**)((u8*)*(FldUnit**)((u8*)ecBase + 0x28) +
                                                      0x48))->unit + temp_3))->id != 0)
    {
        if (flatIndex == var_10)
        {
            return (*(DatUnitGenusBase**)((u8*)*(FldUnit**)((u8*)temp_8 + temp_6 +
                                                           0x28) +
                                          0x48))->unit + var_11;
        }
        var_10 += 1;
        goto unit_next;
    }
unit_next:
    var_11 += 1;
unit_check:
    if (var_11 < 6)
    {
        goto unit_body;
    }
    var_9 += 1;
ec_check:
    if (var_9 < ecCount)
    {
        goto ec_body;
    }
    return NULL;
}

static void K_Encount_CompactEc(EncounterWork* work)
{
    u32 i;
    u32 out = 0;
    for (i = 0; i < work->ecCount && i < 4; ++i)
    {
        if (work->ec[i] != NULL)
        {
            work->ec[out++] = work->ec[i];
        }
    }
    while (out < 4)
    {
        work->ec[out++] = NULL;
    }
}

// FUN_001d7c60
FldUnit* func_001d7c60(KwlnTask* task, s32 flatIndex)
{
    s32 unitIndex;
    s32 flatUnitIndex;
    s32 pcIndex;
    s32 pcCount;
    s32 ecIndex;
    s32 ecCount;
    EncounterWork* work;
    s32 unitOffset;
    u32 ecOffset;
    u8* ecBase;

    work = (EncounterWork*)task->workData;
    flatUnitIndex = 0;
    pcIndex = 0;
    pcCount = work->pcCount;
    goto pc_check;
pc_body:
    if (flatIndex == flatUnitIndex)
    {
        return work->pc[pcIndex];
    }
    flatUnitIndex++;
    pcIndex++;
pc_check:
    if (pcIndex < pcCount)
    {
        goto pc_body;
    }

    ecIndex = 0;
    ecCount = work->ecCount;
    goto ec_check;
ec_body:
    unitIndex = 0;
    ecOffset = ecIndex * 4;
    ecBase = (u8*)work + ecOffset;
    goto unit_check;
unit_body:
    unitOffset = unitIndex * sizeof(DatUnit);
    if (((DatUnit*)((u8*)(*(FldUnit**)(ecBase + 0x28))->genusBase->unit + unitOffset))->id != 0)
    {
        if (flatIndex == flatUnitIndex)
        {
            return work->ec[ecIndex];
        }
        flatUnitIndex++;
    }
    unitIndex++;
unit_check:
    if (unitIndex < 6)
    {
        goto unit_body;
    }
    ecIndex++;
ec_check:
    if (ecIndex < ecCount)
    {
        goto ec_body;
    }
    return NULL;
}

// FUN_001d7d40 NONMATCHING
void* func_001d7d40(KwlnTask* task)
{
    EncounterWork* work;
    FldUnit* pc;
    FldUnit* ec;
    FldUnit* ec2;
    DatUnit* src;
    DatUnit* dst;
    DatUnit* t4;
    u32 i;
    u32 j;
    u32 alivePc;
    u32 aliveEc;
    u32 deadPc;
    u32 deadEc;
    u32 faceDir;
    u32 modelType;
    u32 randVal;
    s16 hpVal;
    u8* base;
    void* effectField;
    void* modelId;
    void* fieldWord;
    void* fieldWord2;
    RwV3d pos;
    RwV3d ppos;
    RwV3d tmpPos;
    f32 scale;
    u32 pcAliveCount;
    u32 ecAliveCount;
    u32 curIdx;
    u32 total;
    s32 genResult;
    u32 procIdx;
    u32 offset1200;

    if (task == NULL || task->workData == NULL)
    {
        return KWLNTASK_CONTINUE;
    }
    work = (EncounterWork*)task->workData;
    if (work->paused != 0)
    {
        return KWLNTASK_CONTINUE;
    }
    if (work->state == 0)
    {
        if (work->pcCount == 0 || work->ecCount == 0 ||
            work->pc[0] == NULL || work->ec[0] == NULL)
        {
            work->state = 2;
            return KWLNTASK_CONTINUE;
        }
        pc = work->pc[0];
        ec = work->ec[0];
        {
            pos.x = (mdlGetMatrix(pc->mdl)->pos.x +
                     mdlGetMatrix(ec->mdl)->pos.x) * 0.5f;
            pos.y = (mdlGetMatrix(pc->mdl)->pos.y +
                     mdlGetMatrix(ec->mdl)->pos.y) * 0.5f + 3.0f;
            pos.z = (mdlGetMatrix(pc->mdl)->pos.z +
                     mdlGetMatrix(ec->mdl)->pos.z) * 0.5f;
            effectField = func_001a91b0(
                *(KwlnTask**)((u8*)K_Field_Get() + 0x1200), &pos);
            work->effectHandle = effectField;
            func_001a9390(*(KwlnTask**)((u8*)K_Field_Get() + 0x1200),
                          effectField, 3);
        }
        K_Encount_Face(pc, ec);
        K_Encount_Face(ec, pc);
        mdlAnimSet(pc->mdl, 0, 4, 0, 1);
        mdlAnimSetSpeed(pc->mdl, 0, 1.0f);
        mdlAnimSet(ec->mdl, 0, 3, 0, 1);
        mdlAnimSetSpeed(ec->mdl, 0, 1.0f);
        func_001b00c0(pc->unk_170);
        func_001b00c0(ec->unk_170);
        work->pcTotal = work->pcCount;
        work->ecTotal = 0;
        for (i = 0; i < work->ecCount; ++i)
        {
            if (work->ec[i] != NULL && work->ec[i]->genusBase != NULL)
            {
                work->ecTotal += work->ec[i]->genusBase->count;
            }
        }
        work->totalActive = work->pcTotal + work->ecTotal;
        if (work->totalActive != 0)
        {
            work->selectedFlatIndex = RpRandom() % work->totalActive;
        }
        work->state = 1;
        return KWLNTASK_CONTINUE;
    }
    if (work->state == 2)
    {
        return KWLNTASK_STOP;
    }
    if (work->state != 1)
    {
        return KWLNTASK_CONTINUE;
    }
    if (work->progress++ <= work->duration)
    {
        return KWLNTASK_CONTINUE;
    }
    work->progress = 0;
    src = func_001d7b70(task, (s32)work->selectedFlatIndex);
    if (src == NULL)
    {
        work->state = 2;
        return KWLNTASK_CONTINUE;
    }
    if (func_001fc720(src) == 0)
    {
        goto skip_attack;
    }
    if (work->selectedFlatIndex < work->pcTotal && work->reaperFlag == 0)
    {
        pc = func_001d7c60(task, (s32)work->selectedFlatIndex);
        if (pc != NULL && work->ecTotal != 0)
        {
            do
            {
                dst = func_001d7b70(task,
                                   (s32)(work->pcTotal + (RpRandom() % work->ecTotal)));
            } while (dst != NULL && (s16)dst->hp <= 0);
            if (dst != NULL)
            {
                func_001fc590(src, dst);
                pos = mdlGetMatrix(pc->mdl)->pos;
                base = (u8*)K_Encount_FieldWord(0x1200);
                func_001a91b0(*(KwlnTask**)(base + 0x120c), &pos);
                func_0010a4e0(1, 8, 2, 0x15);
                randVal = RpRandom();
                t4 = func_001d7b70(task,
                                  (s32)(work->pcTotal + (randVal % work->ecTotal)));
                if (t4 != NULL && (s16)t4->hp > 0)
                {
                    src = func_001d7b70(task, (s32)work->selectedFlatIndex);
                    if (src != NULL)
                    {
                        func_001fc590(t4, src);
                        pos = mdlGetMatrix(pc->mdl)->pos;
                        base = (u8*)K_Encount_FieldWord(0x1200);
                        func_001a91b0(*(KwlnTask**)(base + 0x120c), &pos);
                    }
                }
            }
        }
    }
    else if (work->pcTotal != 0)
    {
        do
        {
            dst = func_001d7b70(task, (s32)(RpRandom() % work->pcTotal));
        } while (dst != NULL && (s16)dst->hp <= 0);
        if (dst != NULL)
        {
            func_001fc590(src, dst);
            if (work->ec[0] != NULL && work->ec[0]->mdl != NULL)
            {
                pos = mdlGetMatrix(work->ec[0]->mdl)->pos;
                base = (u8*)K_Encount_FieldWord(0x1200);
                func_001a91b0(*(KwlnTask**)(base + 0x120c), &pos);
            }
            func_0010a4e0(1, 8, 2, 0x15);
        }
    }
skip_attack:
    /* Count alive PCs and set animations */
    alivePc = 0;
    deadPc = 0;
    for (i = 0; i < work->pcCount; ++i)
    {
        if (work->pc[i] != NULL && work->pc[i]->genusBase != NULL)
        {
            genResult = func_002ff790(work->pc[i]->genusBase);
            if (genResult == 0)
            {
                ++alivePc;
                ppos = mdlGetMatrix(work->pc[i]->mdl)->pos;
                mdlAnimSet(work->pc[i]->mdl, 0, 0, 2, 0);
                mdlAnimSetSpeed(work->pc[i]->mdl, 0, 1.0f);
            }
            else
            {
                ++deadPc;
                if (work->pc[i]->mdl != NULL)
                {
                    ppos = mdlGetMatrix(work->pc[i]->mdl)->pos;
                    base = (u8*)K_Encount_FieldWord(0x1200);
                    func_001a91b0(*(KwlnTask**)(base + 0x1204), &ppos);
                }
                func_0010a4e0(1, 8, 3, 0);
            }
        }
    }
    if (alivePc == 0)
    {
        base = (u8*)K_Encount_FieldWord(0x1200);
        func_001a9400(*(KwlnTask**)(base + 0x1200), work->effectHandle);
        work->state = 2;
        return KWLNTASK_CONTINUE;
    }
    if (deadPc != 0)
    {
        fieldWord = K_Encount_FieldWord(0x1200);
        for (procIdx = 0; procIdx < work->pcCount; ++procIdx)
        {
            pc = work->pc[procIdx];
            if (pc != NULL && pc->genusBase != NULL &&
                func_002ff790(pc->genusBase) == 0)
            {
                ppos = mdlGetMatrix(pc->mdl)->pos;
                mdlAnimSet(pc->mdl, 0, 0, 2, 1);
                mdlAnimSetSpeed(pc->mdl, 0, 1.0f);
            }
        }
    }
    /* Count alive ECs and set animations */
    aliveEc = 0;
    deadEc = 0;
    for (i = 0; i < work->ecCount; ++i)
    {
        ec = work->ec[i];
        if (ec == NULL || ec->genusBase == NULL)
        {
            continue;
        }
        genResult = func_002ff790(ec->genusBase);
        if (genResult == 0)
        {
            ++aliveEc;
            if (ec->mdl != NULL)
            {
                ppos = mdlGetMatrix(ec->mdl)->pos;
                mdlAnimSet(ec->mdl, 0, 0, 2, 0);
                mdlAnimSetSpeed(ec->mdl, 0, 1.0f);
            }
        }
        else
        {
            ++deadEc;
            if (ec->mdl != NULL)
            {
                ppos = mdlGetMatrix(ec->mdl)->pos;
                ppos.y += 100.0f;
                base = (u8*)K_Encount_FieldWord(0x1200);
                func_001a91b0(*(KwlnTask**)(base + 0x1204), &ppos);
                func_0010a4e0(1, 8, 3, 0);
            }
            K_FldUnit_Destroy(ec);
            work->ec[i] = NULL;
        }
    }
    K_Encount_CompactEc(work);
    if (aliveEc == 0)
    {
        base = (u8*)K_Encount_FieldWord(0x1200);
        func_001a9400(*(KwlnTask**)(base + 0x1200), work->effectHandle);
        work->state = 2;
        return KWLNTASK_CONTINUE;
    }
    if (deadEc != 0)
    {
        fieldWord2 = K_Encount_FieldWord(0x1200);
        for (procIdx = 0; procIdx < work->ecCount; ++procIdx)
        {
            ec = work->ec[procIdx];
            if (ec != NULL && ec->genusBase != NULL && ec->mdl != NULL &&
                func_002ff790(ec->genusBase) == 0)
            {
                ppos = mdlGetMatrix(ec->mdl)->pos;
                mdlAnimSet(ec->mdl, 0, 0, 2, 1);
                mdlAnimSetSpeed(ec->mdl, 0, 1.0f);
            }
        }
    }
    /* Final pass: iterate units and apply effects */
    for (procIdx = 0; procIdx < work->ecCount; ++procIdx)
    {
        ec = work->ec[procIdx];
        if (ec != NULL && ec->genusBase != NULL && ec->mdl != NULL &&
            func_002ff790(ec->genusBase) == 0)
        {
            ppos = mdlGetMatrix(ec->mdl)->pos;
            mdlAnimSet(ec->mdl, 0, 0, 0, 1);
            mdlAnimSetSpeed(ec->mdl, 0, 1.0f);
        }
    }
    for (procIdx = 0; procIdx < work->pcCount; ++procIdx)
    {
        pc = work->pc[procIdx];
        if (pc != NULL && pc->genusBase != NULL && pc->mdl != NULL &&
            func_002ff790(pc->genusBase) == 0)
        {
            ppos = mdlGetMatrix(pc->mdl)->pos;
            mdlAnimSet(pc->mdl, 0, 0, 0, 1);
            mdlAnimSetSpeed(pc->mdl, 0, 1.0f);
        }
    }
    if (work->totalActive != 0)
    {
        curIdx = work->selectedFlatIndex + 1;
        total = work->totalActive;
        if (curIdx >= total)
        {
            curIdx = 0;
        }
        work->selectedFlatIndex = curIdx;
    }
    if (work->duration > 0x16)
    {
        work->duration = 0x16;
    }
    return KWLNTASK_CONTINUE;
}








// Retail offsets 0x00-0x4a8 reconstruct unit registration, facing rotation,
// field updates, and active-count aggregation; 1196 of 1200 bytes are implemented.

static u32 K_Encount_AppendRecord(EncounterRecord* out, u16 id)
{
    if (out->count >= 3)
    {
        return 0;
    }
    out->ids[out->count++] = id;
    return 1;
}

static u32 K_Encount_HpRatio(u16 id, f32* ratio)
{
    u32 maxHp = datGetMaxHp((s16)id);
    if (maxHp == 0)
    {
        return 0;
    }
    *ratio = (f32)datGetHp((s16)id) / (f32)maxHp;
    return 1;
}





static KwlnTask* K_Encount_CreatePeriodicScript(PeriodicWork* work, u32 slot, u32 procedure)
{
    KwlnTask* child;
    if (slot >= 16)
    {
        return NULL;
    }
    child = scrCreateTaskFromHeader(10, D_007CE220, procedure);
    work->scriptTask[slot] = child;
    if (child != NULL)
    {
        func_0035c1a0(child, (int)&work->records[slot]);
    }
    return child;
}




// num of pixels in a single quad

// 256 bytes

/* The filter controller keeps the first six words in the small-BSS block. */

/* This word belongs to the neighbouring field-resource work block. */


/* Work data for the field camera controller (the public header intentionally
 * keeps the post-camera fields opaque). */






/* Return the closest camera point to the controlled character. */


// FUN_001d89b0
void func_001d89b0(KwlnTask* task)
{
    EncounterWork* work;
    u32 i;

    work = (EncounterWork*)task->workData;
    for (i = 0; i < work->pcCount; ++i)
    {
        FldUnit** slot = &work->pc[i];
        if ((*slot)->genusBase != NULL)
        {
            if (datGetFlag(0xC22) == 0 &&
                datGetScenarioMode() == 0 &&
                RpRandom() % 100 < 50)
            {
                func_002ffb00_u32((*slot)->genusBase);
            }
            if (func_002ff790((*slot)->genusBase) == 0)
            {
                if (*(KwlnTask**)((u8*)K_Field_Get() + 0x28) != NULL)
                {
                    func_0018bee0(
                        *(KwlnTask**)((u8*)K_Field_Get() + 0x28),
                        (*slot)->charId, 0);
                }
            }
        }
    }
    D_00875A40[work->taskSlot] = NULL;
    RwFree(task->workData);
}
