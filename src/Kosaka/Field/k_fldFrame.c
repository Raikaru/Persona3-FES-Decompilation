#include "Kosaka/Field/k_fldFrame.h"
#include "Kosaka/Field/k_field.h"
#include "Kosaka/Field/k_unit.h"
#include "Kosaka/Field/k_sceneDraw.h"
#include "Kosaka/k_footstep.h"
#include "Graphics/Model/mdlManager.h"
#include "Graphics/primitive.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwln.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "libm.h"

#define COLLISCTL_SUBSTEPS 3

static RwRGBA sDebugSphereColor = {0, 168, 168, 168};
static const RwV3d sAxisUp = {0.0f, 1.0f, 0.0f};
static const RwV3d sAxisForward = {0.0f, 0.0f, 1.0f};

KwlnTask* K_FldFrame_CreateCollisSphereTask(KwlnTask* parent);
void K_FldFrame_CollisSphereSetDrawEnabled(KwlnTask* collisSphereTask, u32 drawEnabled);

typedef struct FldFrameResourceCollision
{
    void* unk_00;
    void* unk_04;
    void* collisionWorld;
} FldFrameResourceCollision;

extern RwV3d D_00683780[];
extern const char D_00678CE0[];
#pragma alias D_00678CE0_typed D_00678CE0
extern const char D_00678CE0_typed[];
extern u32 K_Clump_MatUsrDataHasData(const void* material, const char* name);
#pragma alias K_Clump_MatUsrDataHasData_typed K_Clump_MatUsrDataHasData
extern u32 K_Clump_MatUsrDataHasData_typed(const void* material, const char* name);
extern RwSphere* func_004912b0(void* atomic);
extern RwCamera* DAT_00960070;
#pragma alias DAT_00960070_abs DAT_00960070
extern u8 DAT_00960070_abs[];
typedef struct FldFrameAtomicQuery
{
    void* output;
    u8 intersection[0x2c];
    void* atomic;
} FldFrameAtomicQuery;
extern s32 func_001ab390(void* collision, const RwV3d* pos, RwV3d* translation,
                         f32 sphereCollisRadius);
extern s32 func_001abd20(void* collisionWorld, const RwV3d* pos, RwV3d* translation,
                          f32 sphereCollisRadius, u16 resTypeId);
extern void* func_001ac950(const RwV3d* line, void* unused,
                           const void* triangle, FldFrameRaycast* raycast);
extern void* func_001acb20(void* collisionWorld, FldFrameRaycast* raycast);
extern void func_00464020(void* collision, void* intersection, void* callback, void* param);
extern void func_00464120(void* collision, void* state, void* callback, void* param);
extern void FUN_004916d0(void* collisionWorld, void* callback, void* param);
extern RwMatrix* func_004cb2f0(void* frame);
extern RwV3d* func_004c6ca0(RwV3d* out, const RwV3d* in,
                            u32 count, const RwMatrix* matrix);
extern f32 func_004c6ac0(const RwV3d* vector);
extern f32 fGpffff8078;
#pragma alias jtbl_0096017C_abs jtbl_0096017C
extern u32 jtbl_0096017C_abs[];

#pragma opt_loop_invariants on
// FUN_001aaad0 NONMATCHING
u32 K_FldFrame_IsPointInTriangle(const RwV3d* point, const RwV3d** tri, const RwV3d* normal)
{
    s32 i;
    s32 axis;
    s32 previous;
    u32 inside;
    f32 primary0;
    f32 primary1;
    f32 primary2;
    f32 absX;
    f32 absY;
    f32 absZ;

    inside = false;
    absX = fabsf(normal->x);
    absY = fabsf(normal->y);
    absZ = fabsf(normal->z);
    if (!(absZ <= absY))
    {
        if (!(absZ <= absX))
        {
            axis = 2;
        }
        else
        {
            axis = 0;
        }
    }
    else if (!(absY <= absX))
    {
        axis = 1;
    }
    else
    {
        axis = 0;
    }

    if (axis != 0x7fffffff)
    {
        previous = 2;
        switch (axis)
        {
        case 0:
            primary0 = point->y;
            for (i = 0; i < 3; i++)
            {
                if (((tri[i]->y <= primary0) && (primary0 < tri[previous]->y)) ||
                    ((tri[previous]->y <= primary0) && (primary0 < tri[i]->y)))
                {
                    if (point->z < tri[i]->z +
                        ((primary0 - tri[i]->y) * (tri[previous]->z - tri[i]->z)) /
                        (tri[previous]->y - tri[i]->y))
                    {
                        inside = !inside;
                    }
                }
                previous = i;
            }
            break;
        case 1:
            primary1 = point->z;
            for (i = 0; i < 3; i++)
            {
                if (((tri[i]->z <= primary1) && (primary1 < tri[previous]->z)) ||
                    ((tri[previous]->z <= primary1) && (primary1 < tri[i]->z)))
                {
                    if (point->x < tri[i]->x +
                        ((primary1 - tri[i]->z) * (tri[previous]->x - tri[i]->x)) /
                        (tri[previous]->z - tri[i]->z))
                    {
                        inside = !inside;
                    }
                }
                previous = i;
            }
            break;
        case 2:
            primary2 = point->y;
            for (i = 0; i < 3; i++)
            {
                if (((tri[i]->y <= primary2) && (primary2 < tri[previous]->y)) ||
                    ((tri[previous]->y <= primary2) && (primary2 < tri[i]->y)))
                {
                    if (point->x < tri[i]->x +
                        ((primary2 - tri[i]->y) * (tri[previous]->x - tri[i]->x)) /
                        (tri[previous]->y - tri[i]->y))
                    {
                        inside = !inside;
                    }
                }
                previous = i;
            }
            break;
        default:
            break;
        }
    }

    return inside;
}
#pragma opt_loop_invariants off

// FUN_001ac750
void K_FldFrame_HandleCollis(const RwV3d* pos, RwV3d* translation, f32 sphereCollisRadius,
                             u16 resTypeId)
{
    Resrc* res;
    void* collisionWorld;
    Resrc* fldRes;
    s32 xGrid;
    s32 zGrid;
    u32 gridResTypeId;
    u32 belowMin;

    if ((*(FldFrameCollisionState**)((u8*)K_Field_Get() + FLDFRAME_FIELD_STATE_OFFSET))->flags &
        FLDFRAME_COLLIS_FLAG_STATICWORLD)
    {
        func_001ab390(
            (*(FldFrameCollisionState**)((u8*)K_Field_Get() + FLDFRAME_FIELD_STATE_OFFSET))->staticCollision,
            pos, translation, sphereCollisRadius);
        return;
    }

    collisionWorld = NULL;
    if (K_Scene_001a0250() == true)
    {
        goto resource;
    }
    belowMin = gMtScene->fldMajorId < 0x33;
    if (belowMin)
    {
        goto fallback;
    }
    if (gMtScene->fldMajorId >= 0x4f)
    {
        goto fallback;
    }

resource:
    fldRes = MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    res = MT_Scene_GetRes(resTypeId);
    if (RESRC_GET_TYPE(resTypeId) == RESRC_TYPE_MODELCHAR)
    {
        xGrid = K_FldFrame_CtlGetXGrid(((ResrcModelChar*)res)->collisCtlTask);
        zGrid = K_FldFrame_CtlGetZGrid(((ResrcModelChar*)res)->collisCtlTask);
    }
    else
    {
        xGrid = K_FldFrame_CtlGetXGrid(((ResrcModelNpc*)res)->collisCtlTask);
        zGrid = K_FldFrame_CtlGetZGrid(((ResrcModelNpc*)res)->collisCtlTask);
    }
    gridResTypeId = *(u16*)((u8*)K_Field_Get() + 0x4c + zGrid * 0x100 + xGrid * 0x10);

    while (fldRes != NULL)
    {
        if (fldRes->resTypeId == gridResTypeId)
        {
            collisionWorld = ((FldFrameResourceCollision*)((ResrcFld*)fldRes)->unk_160)->collisionWorld;
            break;
        }
        fldRes = fldRes->next;
    }
    goto done;

fallback:
    collisionWorld =
        (*(FldFrameCollisionState**)((u8*)K_Field_Get() + FLDFRAME_FIELD_STATE_OFFSET))->collisionWorld;

done:
    func_001abd20(collisionWorld, pos, translation, sphereCollisRadius, resTypeId);
}

// FUN_001acc30 NONMATCHING
u32 K_FldFrame_Raycast(const RwV3d* line, RwV3d* hitPointDst)
{
    FldFrameCollisionState* state;
    FldFrameRaycast raycast;
    Resrc* fldRes;
    void* collisionWorld;
    s32 xGrid;
    s32 zGrid;
    u16 gridResTypeId;

    raycast.hitPointDst = hitPointDst;
    raycast.didHit = false;
    raycast.line[0] = line[0];
    raycast.line[1] = line[1];
    raycast.intersectionType = 1;
    raycast.nearestFraction = 1.0f;
    raycast.hitObject = NULL;

    state = *(FldFrameCollisionState**)((u8*)K_Field_Get() + FLDFRAME_FIELD_STATE_OFFSET);
    if (state->flags & FLDFRAME_COLLIS_FLAG_STATICWORLD)
    {
        if (state->staticCollision != NULL)
        {
            func_00464020(state->staticCollision, &raycast.line[0], func_001ac950, &raycast);
        }
        return raycast.didHit;
    }

    collisionWorld = NULL;
    if ((K_Scene_001a0250() == true) ||
        ((gMtScene->fldMajorId > 0x32) && (gMtScene->fldMajorId < 0x4f)))
    {
        fldRes = MT_Scene_GetResListHead(RESRC_TYPE_FLD);
        xGrid = (line[0].x + 400.0f) / 800.0f;
        zGrid = (line[0].z + 400.0f) / 800.0f;
        gridResTypeId = *(u16*)((u8*)K_Field_Get() + 0x4c + zGrid * 0x100 + xGrid * 0x10);

        while (fldRes != NULL)
        {
            if (fldRes->resTypeId == gridResTypeId)
            {
                collisionWorld = ((FldFrameResourceCollision*)((ResrcFld*)fldRes)->unk_160)->collisionWorld;
                break;
            }
            fldRes = fldRes->next;
        }
    }
    else
    {
        collisionWorld = state->collisionWorld;
    }

    if (collisionWorld != NULL)
    {
        FUN_004916d0(collisionWorld, func_001acb20, &raycast);
    }
    return raycast.didHit;
}

// FUN_001ad2f0
void* K_FldFrame_UpdateCtlTask(KwlnTask* collisCtlTask)
{
    CollisCtl* ctl;
    ResrcModelChar* charList; // unused
    ResrcModelNpc* npcList;   // unused
    RwMatrix* mdlMatrix;
    RwV3d line[2];
    RwV3d hitPoint;
    RwV3d translation;
    RwV3d pos;
    s32 i;

    ctl = (CollisCtl*)collisCtlTask->workData;

    charList = (ResrcModelChar*)MT_Scene_GetResListHead(RESRC_TYPE_MODELCHAR);
    npcList = (ResrcModelNpc*)MT_Scene_GetResListHead(RESRC_TYPE_MODELNPC);

    if (ctl->flags & COLLISCTL_FLAG_NOUPDATE)
    {
        return KWLNTASK_CONTINUE;
    }

    switch (ctl->state)
    {
        case COLLISCTL_STATE_DIRTY:
            mdlMatrix = mdlGetMatrix(ctl->mdl);
            pos = mdlMatrix->pos;

            if (ctl->flags & COLLISCTL_FLAG_GROUNDSNAP && 
                !(ctl->flags & COLLISCTL_FLAG_NOCOLLIS))
            {
                line[0] = line[1] = pos;

                if (K_Scene_001a0250())
                {
                    line[0].y += 600.0f;
                }
                else
                {
                    line[0].y += 200.0f;
                }

                line[1].y -= 1000.0f;

                if (K_FldFrame_Raycast(line, &hitPoint) == true)
                {
                    ctl->velocity.y = -(pos.y - hitPoint.y);
                }
            }

            for (i = 0; i < COLLISCTL_SUBSTEPS; i++)
            {
                translation.x = ctl->velocity.x / COLLISCTL_SUBSTEPS;
                translation.y = ctl->velocity.y / COLLISCTL_SUBSTEPS;
                translation.z = ctl->velocity.z / COLLISCTL_SUBSTEPS;

                pos = mdlGetMatrix(ctl->mdl)->pos;
                pos.y += ctl->sphereCollisRadius;

                if (!(ctl->flags & COLLISCTL_FLAG_NOCOLLIS))
                {
                    K_FldFrame_HandleCollis(&pos, &translation, ctl->sphereCollisRadius, ctl->resTypeId);
                }

                mdlTranslate(ctl->mdl, &translation, rwCOMBINEPOSTCONCAT);
            }

            ctl->xGrid = (mdlMatrix->pos.x + 400.0f) / 800.0f;
            ctl->zGrid = (mdlMatrix->pos.z + 400.0f) / 800.0f;

            if (RESRC_GET_ID(ctl->resTypeId) < 100)
            {
                K_Footstep_Update(ctl->mdl, ctl->charId, ctl->resTypeId);
            }

            ctl->state++; // COLLISCTL_STATE_NOTDIRTY
            break;

        case COLLISCTL_STATE_NOTDIRTY:
            mdlMatrix = mdlGetMatrix(ctl->mdl);

            if (ctl->flags & COLLISCTL_FLAG_DEBUGDRAW)
            {
                K_FldFrame_CollisSphereSetDrawEnabled(collisCtlTask->child, true);
            }
            else
            {
                K_FldFrame_CollisSphereSetDrawEnabled(collisCtlTask->child, false);
            }
            break;
        
        case COLLISCTL_STATE_IDLE: break;
    }

    return KWLNTASK_CONTINUE;
}

// FUN_001ad630
void K_FldFrame_DestroyCtlTask(KwlnTask* collisCtlTask)
{
    RwFree(collisCtlTask->workData);
}

// FUN_001ad660 NONMATCHING
KwlnTask* K_FldFrame_CreateCtlTask(KwlnTask* parent, u32 resTypeId, s32 unused, f32 sphereCollisRadius)
{
    KwlnTask* task;
    CollisCtl* ctl;
    Resrc* res;
    s32 i;
    FldUnit* units;

    ctl = RwCalloc(1, sizeof(CollisCtl), rwMEMHINTDUR_GLOBAL);
    if (ctl == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parent,
                                          10,
                                          "collision controler",
                                          K_FldFrame_UpdateCtlTask,
                                          K_FldFrame_DestroyCtlTask,
                                          ctl);

    ctl->state = COLLISCTL_STATE_NOTDIRTY;
    ctl->resTypeId = resTypeId;
    ctl->sphereCollisRadius = sphereCollisRadius;
    ctl->unk_24 = 0;

    if (RESRC_GET_TYPE(resTypeId) == RESRC_TYPE_MODELCHAR)
    {
        res = MT_Scene_GetRes(resTypeId);
        if (res != NULL)
        {
            ctl->mdl = ((ResrcModelChar*)res)->mdl;
        }
        i = 0;
        for (; i < FLDUNIT_PC_MAX; i++)
        {
            units = &gFldUnitsPc[i];
            if (units->genusBase != NULL &&
                units->mdl == ((ResrcModelChar*)res)->mdl)
            {
                u16 charId;

                charId = units->charId;
                ctl->charId = charId;
                ctl->fldUnit = units;
                break;
            }
        }

        i = 0;
        for (; i < FLDUNIT_EC_MAX; i++)
        {
            units = &gFldUnitsEc[i];
            if (units->genusBase != NULL &&
                units->mdl == ((ResrcModelChar*)res)->mdl)
            {
                u16 charId;

                charId = units->charId;
                ctl->charId = charId;
                ctl->fldUnit = units;
                break;
            }
        }
    }
    else if (RESRC_GET_TYPE(resTypeId) == RESRC_TYPE_MODELNPC)
    {
        res = MT_Scene_GetRes(resTypeId);
        if (res != NULL)
        {
            ctl->mdl = ((ResrcModelNpc*)res)->mdl;
        }
    }

    K_FldFrame_CreateCollisSphereTask(task);

    return task;
}

// FUN_001ad870
void K_FldFrame_CtlSetFlags(KwlnTask* collisCtlTask, u32 flags)
{
    ((CollisCtl*)collisCtlTask->workData)->flags |= flags;
}

// FUN_001ad890
void K_FldFrame_CtlClearFlags(KwlnTask* collisCtlTask, u32 flags)
{
    ((CollisCtl*)collisCtlTask->workData)->flags &= ~flags;
}

// FUN_001ad8b0
f32 K_FldFrame_CtlGetSphereCollisRadius(KwlnTask* collisCtlTask)
{
    return ((CollisCtl*)collisCtlTask->workData)->sphereCollisRadius;
}

// FUN_001ad8c0
void K_FldFrame_CtlSetSphereCollisRadius(KwlnTask* collisCtlTask, f32 radius)
{
    CollisCtl* ctl;

    ctl = (CollisCtl*)collisCtlTask->workData;
    ctl->sphereCollisRadius = radius;

    if (radius == 0.0f)
    {
        ctl->flags |= COLLISCTL_FLAG_NOCOLLIS;
        return;
    }

    ctl->flags &= ~COLLISCTL_FLAG_NOCOLLIS;
}

// FUN_001ad910
s32 K_FldFrame_CtlGetXGrid(KwlnTask* collisCtlTask)
{
    return ((CollisCtl*)collisCtlTask->workData)->xGrid;
}

// FUN_001ad920
s32 K_FldFrame_CtlGetZGrid(KwlnTask* collisCtlTask)
{
    return ((CollisCtl*)collisCtlTask->workData)->zGrid;
}

// FUN_001ad930
u32 K_FldFrame_CtlGetTotalDist(KwlnTask* collisCtlTask)
{
    return ((CollisCtl*)collisCtlTask->workData)->totalDist;
}

// FUN_001ad940
void K_FldFrame_CtlCopyPos(RwV3d* dst, KwlnTask* collisCtlTask)
{
    CollisCtl* ctl = (CollisCtl*)collisCtlTask->workData;
    RwV3d vec = {0};

    if (ctl->mdl != NULL)
    {
        vec = mdlGetMatrix(ctl->mdl)->pos;
    }

    *dst = vec;
}

// FUN_001ad9e0
void K_FldFrame_CtlUpdateMdlMat(KwlnTask* collisCtlTask, const RwMatrix* mat)
{
    CollisCtl* ctl = (CollisCtl*)collisCtlTask->workData;
    RwV3d originalPos;
    RwV3d zeroPos = {0};
    RwMatrixTolerance initialTolerance;
    RwMatrixTolerance rotatedTolerance;
    RwMatrixTolerance finalTolerance;

    if (ctl->mdl != NULL)
    {
        originalPos = mdlGetMatrix(ctl->mdl)->pos;
        mdlGetMatrix(ctl->mdl)->pos = zeroPos;
        RwEngineGetMatrixTolerances(&initialTolerance);
        RwMatrixOptimize(mdlGetMatrix(ctl->mdl), &initialTolerance);
        RwMatrixUpdate(mdlGetMatrix(ctl->mdl));

        mdlGetMatrix(ctl->mdl)->right = mat->right;
        mdlGetMatrix(ctl->mdl)->up = mat->up;
        mdlGetMatrix(ctl->mdl)->at = mat->at;
        RwEngineGetMatrixTolerances(&rotatedTolerance);
        RwMatrixOptimize(mdlGetMatrix(ctl->mdl), &rotatedTolerance);
        RwMatrixUpdate(mdlGetMatrix(ctl->mdl));

        if (ctl->fldUnit != NULL)
        {
            mdlScale(ctl->mdl, &D_00683780[ctl->fldUnit->scaleIdx], rwCOMBINEPOSTCONCAT);
        }

        mdlGetMatrix(ctl->mdl)->pos = originalPos;
        RwEngineGetMatrixTolerances(&finalTolerance);
        RwMatrixOptimize(mdlGetMatrix(ctl->mdl), &finalTolerance);
        RwMatrixUpdate(mdlGetMatrix(ctl->mdl));
    }
}

// FUN_001addf0
void K_FldFrame_CtlMoveInDir(f32 dist, KwlnTask* collisCtlTask, const RwV3d* normalizedDir)
{
    CollisCtl* ctl;
    RwV3d velocity;

    ctl = (CollisCtl*)collisCtlTask->workData;
    velocity = *normalizedDir;

    if (ctl->state == COLLISCTL_STATE_NOTDIRTY)
    {
        velocity.x *= dist;
        velocity.y *= dist;
        velocity.z *= dist;
        
        ctl->totalDist += (u32)dist;
        ctl->velocity = velocity;

        ctl->state = COLLISCTL_STATE_DIRTY;
    }
}

// FUN_001adec0
void K_FldFrame_CtlMoveForward(f32 dist, KwlnTask* collisCtlTask)
{
    CollisCtl* ctl = (CollisCtl*)collisCtlTask->workData;
    RwV3d velocity = {0};

    if (ctl->state == COLLISCTL_STATE_NOTDIRTY)
    {
        velocity = mdlGetMatrix(ctl->mdl)->at;
        RwV3dNormalize(&velocity, &velocity);
        
        velocity.x *= dist;
        velocity.y *= dist;
        velocity.z *= dist;

        ctl->totalDist += (u32)dist;
        ctl->velocity = velocity;

        ctl->state = COLLISCTL_STATE_DIRTY;
    }
}

// FUN_001adff0
void K_FldFrame_CtlRotate(KwlnTask* collisCtlTask, const RwV3d* axis, f32 angle)
{
    CollisCtl* ctl;
    RwV3d originalPos;
    RwV3d negPos;

    ctl = (CollisCtl*)collisCtlTask->workData;

    if (ctl->mdl != NULL)
    {
        originalPos = mdlGetMatrix(ctl->mdl)->pos;

        negPos.x = originalPos.x * -1.0f;
        negPos.y = originalPos.y * -1.0f;
        negPos.z = originalPos.z * -1.0f;

        mdlTranslate(ctl->mdl, &negPos, rwCOMBINEPOSTCONCAT); // basically just do pos + (-pos) = (0, 0, 0)
        mdlRotate(ctl->mdl, axis, angle, rwCOMBINEPOSTCONCAT);
        mdlTranslate(ctl->mdl, &originalPos, rwCOMBINEPOSTCONCAT);
    }
}

// FUN_001ae290
void* K_FldFrame_UpdateCollisSphereTask(KwlnTask* collisSphereTask)
{
    CollisSphereDebug* debug;
    CollisCtl* ctl;
    f32 radius;

    debug = (CollisSphereDebug*)collisSphereTask->workData;
    ctl = (CollisCtl*)collisSphereTask->parent->workData;
    radius = ctl->sphereCollisRadius;

    {
        RwV3d spherePos;
        volatile RwV3d posCopy;
        RwV3d pos = {0};
        RwRGBA color;

        if (ctl->mdl != NULL)
        {
            pos = mdlGetMatrix(ctl->mdl)->pos;
        }

        posCopy = pos;
        spherePos = posCopy;
        color = sDebugSphereColor;

        if (debug->drawEnabled == 0)
        {
            return KWLNTASK_CONTINUE;
        }

        spherePos.y += radius;
        if (RwCameraBeginUpdate(kwlnGetMainCamera()) != NULL)
        {
            primSphereLine3D(&spherePos, radius, &color, true);
            RwCameraEndUpdate(kwlnGetMainCamera());
        }
    }

    return KWLNTASK_CONTINUE;
}

// FUN_001ae3c0
void K_FldFrame_DestroyCollisSphereTask(KwlnTask* collisSphereTask)
{
    RwFree(collisSphereTask->workData);
}

// FUN_001ae3f0
KwlnTask* K_FldFrame_CreateCollisSphereTask(KwlnTask* parent)
{
    CollisSphereDebug* work;

    work = RwCalloc(1, sizeof(CollisSphereDebug), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    return kwlnTaskCreate(parent,
                          "collis sphere",
                          4174,
                          K_FldFrame_UpdateCollisSphereTask,
                          K_FldFrame_DestroyCollisSphereTask,
                          work);
}

// FUN_001ae470
void K_FldFrame_CollisSphereSetDrawEnabled(KwlnTask* collisSphereTask, u32 drawEnabled)
{
    ((CollisSphereDebug*)collisSphereTask->workData)->drawEnabled = drawEnabled;
}
/*
 * Field movement-path work data.
 *
 * The retail task allocates 0x5a0 bytes. Keeping the point records explicit
 * is useful here: the public queue helpers below are also used by event code,
 * and the controller stores a complete 0x18-byte record for every point.
 */
typedef struct FldFrameMovePoint
{
    u32 kind;
    RwV3d position;
    f32 duration;
    KwlnTask* drawTask;
} FldFrameMovePoint;

typedef struct FldFrameMoveWork
{
    u32 state;
    u32 flags;
    u32 mode;
    void* resource;
    s32 animation;
    s32 targetAnimation;
    s32 pathMode;
    s32 pointCount;
    FldFrameMovePoint points[48];
    RwV3d startPosition;
    f32 currentAngle;
    f32 angleStep;
    s32 turnMode;
    s32 frame;
    RwV3d direction;
    f32 directionLength;
    void* drawMatrix;
    s32 frameCount;
    f32 frameRemainder;
    s32 pendingPointCount;
    u8 reserved[0x5a0 - 0x4dc];
} FldFrameMoveWork;

extern void* func_004c38c0(void);
extern void func_004c3880(void* matrix);
extern void func_0045edc0(void* work);
extern s32 func_001dde00(s32 value);
extern s32 func_001ded40(s32 value);
extern s32 func_003182d0(Model* model, s32 layer, s32 animation, s32 mode, s32 flag);
extern void func_003189f0(Model* model, s32 layer, f32 speed);
extern s32 func_00318540(Model* model, s32 layer);
extern void* func_00318b60(u32 id);
extern f32 func_001a5aa0(void* matrix);
extern s32 func_00530da0(f32 value);
extern s32 func_0052e118(s32 value);
extern s32 func_0045ec20(s32 left, s32 right);
extern f32 fGpffff82b0;
extern void func_00318a30(Model* model, const RwV3d* offset, s32 combine);
extern void func_00318a50(Model* model, const RwV3d* axis, f32 angle,
                          s32 combine);
extern void func_004c31b0(RwMatrix* matrix, const RwV3d* axis, f32 angle,
                          s32 combine);
extern void func_001ad9e0(KwlnTask* ctl, void* matrix);
extern f32 func_004c69f0(RwV3d* out, const RwV3d* in);
extern f32 func_0052e9e8(f32 value);
extern KwlnTask* K_Draw_CreatePositionTask(s32 parent);
extern void K_Draw_SetPositionColor(KwlnTask* task, const RwRGBA* color);
extern void K_Draw_SetPositionPos(KwlnTask* task, const RwV3d* position);
extern void* func_0048dab0(s32 count, s32 mode, const RwV3d* position);
extern void func_0048d480(f32 frame, void* curve, s32 flags, RwV3d* output, s32 unused);
extern void func_0048da30(void* curve);
extern void* func_001a4cd0(s32 parent);
extern void func_001a4dc0(void* task, const RwRGBA* color);
extern void func_001a4e60(void* task, const RwV3d* position);
extern u8 D_007E095F[];
extern u8 D_007E095E[];
extern u8 D_007E0960[];
extern u8 D_007E0961[];
extern u8 D_007E094C[];

static FldFrameMoveWork* fldFrameMoveWork(KwlnTask* task)
{
    return (FldFrameMoveWork*)task->workData;
}

static Model* fldFrameMoveModel(const FldFrameMoveWork* work)
{
    if (work->resource == NULL)
    {
        return NULL;
    }
    return *(Model**)((u8*)work->resource + 0x128);
}

static KwlnTask* fldFrameMoveCtl(const FldFrameMoveWork* work)
{
    if (work->resource == NULL)
    {
        return NULL;
    }
    return *(KwlnTask**)((u8*)work->resource + 0x1e0);
}

static void fldFrameMoveCopyPoint(FldFrameMovePoint* dst,
                                  const FldFrameMovePoint* src)
{
    *dst = *src;
}

static void fldFrameMoveResolvePosition(const RwV3d* input, RwV3d* output)
{
    RwV3d line[2];

    line[0] = *input;
    line[1] = *input;
    if (K_Scene_001a0250() != false)
    {
        line[0].y += 600.0f;
    }
    else
    {
        line[0].y += 200.0f;
    }
    line[1].y -= 1000.0f;
    if (K_FldFrame_Raycast(line, output) == false)
    {
        *output = *input;
    }
}

static void fldFrameMoveCreateDebugPoint(FldFrameMoveWork* work,
                                         FldFrameMovePoint* point,
                                         const RwRGBA* color)
{
    if ((work->flags & 0x80000000) != 0)
    {
        point->drawTask = K_Draw_CreatePositionTask(0);
        if (point->drawTask != NULL)
        {
            K_Draw_SetPositionColor(point->drawTask, color);
            K_Draw_SetPositionPos(point->drawTask, &point->position);
        }
    }
}

static void fldFrameMoveAppend(FldFrameMoveWork* work,
                               u32 kind,
                               const RwV3d* position,
                               f32 duration)
{
    FldFrameMovePoint* point;

    if (work->pointCount >= 47)
    {
        return;
    }
    point = &work->points[work->pointCount];
    point->kind = kind;
    point->position = *position;
    point->duration = duration;
    point->drawTask = NULL;
    work->pointCount++;
}


#pragma opt_loop_invariants on

// FUN_001ae480 NONMATCHING
u32 func_001ae480(KwlnTask* task)
{
    FldFrameMoveWork* work;
    s32 i;

    work = (FldFrameMoveWork*)task->workData;
    if (work->pointCount > 0)
    {
        if ((work->flags & 0x80000000) != 0 &&
            work->points[0].drawTask != NULL)
        {
            kwlnTaskDestroyWithHierarchy(work->points[0].drawTask);
            work->points[0].drawTask = NULL;
        }
        memset(&work->points[0], 0, sizeof(FldFrameMovePoint));
        work->pointCount--;
        for (i = 0; i < work->pointCount; i++)
        {
            s32 j;
            u8* pointBase;
            u32* source;
            u32* destination;
            pointBase = (u8*)work + i * sizeof(FldFrameMovePoint);
            source = (u32*)(pointBase + 0x38);
            destination = (u32*)(pointBase + 0x20);

            j = 3;
            do
            {
                u32 value0 = source[0];
                u32 value1 = source[1];

                source += 2;
                j--;
                destination[0] = value0;
                destination[1] = value1;
                destination += 2;
            } while (j > 0);
            *(u32*)(pointBase + 0x4c) = 0;
        }
        return true;
    }
    return false;
}

#pragma opt_loop_invariants off
static void fldFrameMoveSetAnimation(FldFrameMoveWork* work,
                                     s16 animation,
                                     u16 blendFrames)
{
    Model* model = fldFrameMoveModel(work);

    if (model == NULL)
    {
        return;
    }
    if (mdlAnimGetId(model, 0) != animation)
    {
        mdlAnimSet(model, 0, animation, blendFrames, 1);
    }
    mdlAnimSetSpeed(model, 0, 1.0f);
}

// FUN_001ae580 NONMATCHING
void* func_001ae580(KwlnTask* task)
{
    FldFrameMoveWork* work;
    Model* model;
    s32 i;
    f32 amount;
    f32 localAngleStep;
    f32 localAngle;
    f32 localAngleB;
    RwV3d translation;
    RwV3d localDir;
    RwV3d localPosition;
    s32 mode;
    s32 pointCount;

    work = fldFrameMoveWork(task);
    model = fldFrameMoveModel(work);
    pointCount = work->pointCount;
    mode = work->mode;
    if (mode == 1)
    {
        return KWLNTASK_CONTINUE;
    }
    localAngleStep = 0.0f;
    localAngle = 0.0f;
    localAngleB = 0.0f;
    localDir = sAxisUp;
    localPosition = sAxisForward;
    switch (work->state)
    {
    case 0:
    {
        work->drawMatrix = func_004c38c0();
        work->state = 1;
        return KWLNTASK_CONTINUE;
    }
    case 1:
    {
        s32 kind;
        s32 anim;

        if (pointCount > 0 || work->pendingPointCount > 0)
        {
            kind = (s32)work->points[0].kind;
            if (kind == 1 || kind == 4)
            {
                if ((*(u16*)work->resource & 0x3ff) < 100)
                {
                    func_003182d0(fldFrameMoveModel(work), 0,
                                  (s16)func_001dde00(work->animation), 2, 1);
                }
                else
                {
                    func_003182d0(fldFrameMoveModel(work), 0, 0, 8, 1);
                }
                func_003189f0(fldFrameMoveModel(work), 0, 1.0f);
                work->frameCount = (s32)work->points[0].duration;
                work->state = 5;
            }
            else if (kind == 2)
            {
                anim = (s16)func_001dde00(work->animation);
                if ((*(u16*)work->resource & 0x3ff) < 100)
                {
                    func_003182d0(fldFrameMoveModel(work), 0, anim, 2, 1);
                }
                else
                {
                    func_003182d0(fldFrameMoveModel(work), 0, anim, 8, anim);
                }
                func_003189f0(fldFrameMoveModel(work), 0, 1.0f);
                work->frameCount = (s32)work->points[0].duration;
                work->state = 6;
            }
            else if (kind != 5)
            {
                if ((*(u16*)work->resource & 0x3ff) < 100)
                {
                    anim = (s16)func_00318540(fldFrameMoveModel(work), 0);
                    if (anim != func_001ded40(work->animation))
                    {
                        func_003182d0(fldFrameMoveModel(work), 0,
                                      (s16)func_001ded40(work->animation), 8, 1);
                    }
                }
                else
                {
                    anim = (s16)func_00318540(fldFrameMoveModel(work), 0);
                    if (anim != 1)
                    {
                        func_003182d0(fldFrameMoveModel(work), 0, 1, 8, 1);
                    }
                }
                work->targetAnimation = 8;
                work->state = 2;
            }
            return KWLNTASK_CONTINUE;
        }
        if (work->targetAnimation > 0)
        {
            work->targetAnimation--;
            return KWLNTASK_CONTINUE;
        }
        anim = (s16)func_00318540(fldFrameMoveModel(work), 0);
        if ((*(u16*)work->resource & 0x3ff) < 100)
        {
            if (anim != 4 && anim != 0x15 &&
                anim != func_001dde00(work->animation))
            {
                func_003182d0(fldFrameMoveModel(work), 0,
                              (s16)func_001dde00(work->animation), 8, 1);
                func_003189f0(fldFrameMoveModel(work), 0, 1.0f);
            }
        }
        else if (anim != 3 && anim != 0)
        {
            func_003182d0(fldFrameMoveModel(work), 0, 0, 8, 1);
            func_003189f0(fldFrameMoveModel(work), 0, 1.0f);
        }
        return KWLNTASK_CONTINUE;
    }
    case 2:
    {
        s32 pending = work->pendingPointCount;
        if (pending > 0)
        {
            if (pending < 3)
            {
                if (work->pointCount + pending < 48)
                {
                    for (i = 0; i < work->pendingPointCount; i++)
                    {
                        const u8* source = (const u8*)work + 0x4e0 + i * 0x18;

                        work->points[work->pointCount].position.x =
                            *(const f32*)(source + 0x00);
                        work->points[work->pointCount].position.y =
                            *(const f32*)(source + 0x04);
                        work->points[work->pointCount].position.z =
                            *(const f32*)(source + 0x08);
                        work->points[work->pointCount].duration =
                            *(const f32*)(source + 0x0c);
                        work->points[work->pointCount].kind = 0;
                        work->pointCount++;
                    }
                    work->pendingPointCount = 0;
                }
            }
            else if (work->pointCount + pending * 4 < 48)
            {
                RwV3d curvePoints[13];
                void* curve;
                s32 index;
                s32 step;
                f32 stepScale;

                index = -1;
                if (work->pointCount > 0)
                {
                    index = work->pointCount - 1;
                    while (index >= 0 && work->points[index].kind != 0)
                    {
                        index--;
                    }
                }
                if (index >= 0)
                {
                    curvePoints[0] = work->points[index].position;
                }
                else
                {
                    const u8* origin =
                        (const u8*)func_00318b60((u32)fldFrameMoveModel(work));

                    curvePoints[0].x = *(const f32*)(origin + 0x30);
                    curvePoints[0].y = *(const f32*)(origin + 0x34);
                    curvePoints[0].z = *(const f32*)(origin + 0x38);
                }
                for (i = 0; i < work->pendingPointCount; i++)
                {
                    const u8* source = (const u8*)work + 0x4e0 + i * 0x18;

                    curvePoints[i + 1].x = *(const f32*)(source + 0x00);
                    curvePoints[i + 1].y = *(const f32*)(source + 0x04);
                    curvePoints[i + 1].z = *(const f32*)(source + 0x08);
                }
                curve = func_0048dab0(work->pendingPointCount + 1, 1, curvePoints);
                stepScale = 1.0f / (f32)(work->pendingPointCount * 4);
                for (step = 1; step < work->pendingPointCount * 4; step++)
                {
                    func_0048d480((f32)step * stepScale, curve, 0xa,
                                  &work->points[work->pointCount].position, 0);
                    work->points[work->pointCount].duration =
                        *(const f32*)((const u8*)work + 0x4ec +
                                      (work->pendingPointCount / 4) * 0x18);
                    work->points[work->pointCount].kind = 0;
                    fldFrameMoveCreateDebugPoint(
                        work, &work->points[work->pointCount],
                        &sDebugSphereColor);
                    work->pointCount++;
                }
                work->pendingPointCount = 0;
                func_0048da30(curve);
            }
        }
        pointCount = work->pointCount;
        if (pointCount <= 0)
        {
            work->state = 1;
            return KWLNTASK_CONTINUE;
        }
        {
            const u8* origin =
                (const u8*)func_00318b60((u32)fldFrameMoveModel(work));

            work->startPosition.x = *(const f32*)(origin + 0x30);
            work->startPosition.y = *(const f32*)(origin + 0x34);
            work->startPosition.z = *(const f32*)(origin + 0x38);
            translation = work->points[0].position;
            work->startPosition.y = 0.0f;
            translation.y = 0.0f;
            work->direction.x = translation.x - work->startPosition.x;
            work->direction.y = 0.0f - work->startPosition.y;
            work->direction.z = translation.z - work->startPosition.z;
            work->directionLength =
                func_004c69f0(&work->direction, &work->direction);
        }
        localAngle = fGpffff82b0 *
                     func_0052e9e8(work->direction.y * localPosition.y +
                                   work->direction.x * localPosition.x +
                                   work->direction.z * localPosition.z);
        if (work->direction.x < 0.0f)
        {
            localAngle = localAngle * -1.0f;
        }
        if (work->turnMode != 0)
        {
            localAngleStep =
                180.0f +
                func_001a5aa0(func_00318b60((u32)fldFrameMoveModel(work)));
            work->currentAngle = localAngleStep;
            localAngle = 180.0f + localAngle;
            if (localAngle <= localAngleStep)
            {
                localAngleB = (360.0f - localAngleStep) + localAngle;
            }
            else
            {
                localAngleB = (360.0f - localAngle) + localAngleStep;
            }
            amount = localAngle - localAngleStep;
            if (func_0045ec20(func_0052e118(func_00530da0(localAngleB)),
                              func_0052e118(func_00530da0(amount))) != 0)
            {
                localAngleB = amount;
            }
            work->frame = 0;
            work->angleStep = localAngleB / (f32)(u32)work->turnMode;
            work->currentAngle = localAngle;
        }
        else
        {
            work->currentAngle = 180.0f + localAngle;
        }
        work->frameCount =
            (s32)(work->directionLength / work->points[0].duration);
        work->frameRemainder =
            work->directionLength -
            work->points[0].duration * (f32)work->frameCount;
        if (work->frameRemainder > 0.0f)
        {
            work->frameCount++;
        }
        work->state = 3;
        return KWLNTASK_CONTINUE;
    }
    case 3:
    {
        if (model == NULL)
        {
            func_001ae480(task);
            work->state = 1;
            return KWLNTASK_CONTINUE;
        }
        amount = work->directionLength / (f32)work->frameCount;
        translation.x = work->direction.x * amount;
        translation.y = work->direction.y * amount;
        translation.z = work->direction.z * amount;
        mdlTranslate(model, &translation, rwCOMBINEPOSTCONCAT);
        if (work->points[0].drawTask != NULL)
        {
            K_Draw_SetPositionPos(work->points[0].drawTask,
                                  &mdlGetMatrix(model)->pos);
        }
        work->frameCount--;
        if (work->frameCount <= 0)
        {
            mdlGetMatrix(model)->pos = work->points[0].position;
            func_001ae480(task);
            work->state = (mode == 1 || mode == 4) ? 1 : 2;
        }
        return KWLNTASK_CONTINUE;
    }
    case 4:
    {
        RwV3d targetDir;
        f32 targetLen;

        if (model == NULL)
        {
            func_001ae480(task);
            work->state = 1;
            return KWLNTASK_CONTINUE;
        }
        localPosition = mdlGetMatrix(model)->pos;
        targetDir.x = work->points[0].position.x - localPosition.x;
        targetDir.y = work->points[0].position.y - localPosition.y;
        targetDir.z = work->points[0].position.z - localPosition.z;
        targetLen = sqrtf(targetDir.x * targetDir.x +
                          targetDir.y * targetDir.y +
                          targetDir.z * targetDir.z);
        work->directionLength = targetLen;
        if (targetLen > 0.0f)
        {
            work->direction.x = targetDir.x / targetLen;
            work->direction.y = targetDir.y / targetLen;
            work->direction.z = targetDir.z / targetLen;
        }
        amount = targetLen / (f32)work->frameCount;
        translation.x = work->direction.x * amount;
        translation.y = work->direction.y * amount;
        translation.z = work->direction.z * amount;
        mdlTranslate(model, &translation, rwCOMBINEPOSTCONCAT);
        if (work->points[0].drawTask != NULL)
        {
            K_Draw_SetPositionPos(work->points[0].drawTask,
                                  &mdlGetMatrix(model)->pos);
        }
        work->frameCount--;
        if (work->frameCount <= 0)
        {
            mdlGetMatrix(model)->pos = work->points[0].position;
            func_001ae480(task);
            work->state = (mode == 1 || mode == 4) ? 1 : 2;
        }
        return KWLNTASK_CONTINUE;
    }
    case 5:
    {
        RwV3d axis = {0.0f, 1.0f, 0.0f};
        if (model != NULL)
        {
            mdlRotate(model, &axis, localAngleStep, rwCOMBINEPOSTCONCAT);
        }
        work->frameCount--;
        if (work->frameCount <= 0)
        {
            func_001ae480(task);
            work->state = 1;
        }
        return KWLNTASK_CONTINUE;
    }
    case 6:
    {
        const u8* origin =
            (const u8*)func_00318b60((u32)fldFrameMoveModel(work));

        work->startPosition.x = *(const f32*)(origin + 0x30);
        work->startPosition.y = *(const f32*)(origin + 0x34);
        work->startPosition.z = *(const f32*)(origin + 0x38);
        work->direction.x =
            work->points[0].position.x - work->startPosition.x;
        work->direction.y =
            work->points[0].position.y - work->startPosition.y;
        work->direction.z =
            work->points[0].position.z - work->startPosition.z;
        work->directionLength =
            func_004c69f0(&work->direction, &work->direction);
        localAngle = fGpffff82b0 *
                     func_0052e9e8(work->direction.y * localPosition.y +
                                   work->direction.x * localPosition.x +
                                   work->direction.z * localPosition.z);
        if (work->direction.x < 0.0f)
        {
            localAngle = localAngle * -1.0f;
        }
        localAngleStep =
            180.0f +
            func_001a5aa0(func_00318b60((u32)fldFrameMoveModel(work)));
        work->currentAngle = localAngleStep;
        localAngle = 180.0f + localAngle;
        if (localAngle <= localAngleStep)
        {
            localAngleB = (360.0f - localAngleStep) + localAngle;
        }
        else
        {
            localAngleB = (360.0f - localAngle) + localAngleStep;
        }
        amount = localAngle - localAngleStep;
        if (func_0045ec20(func_0052e118(func_00530da0(localAngleB)),
                          func_0052e118(func_00530da0(amount))) != 0)
        {
            localAngleB = amount;
        }
        work->frame = 0;
        work->angleStep = localAngleB / work->points[0].duration;
        work->currentAngle = localAngle;
        work->state = 7;
        return KWLNTASK_CONTINUE;
    }
    case 7:
    {
        if ((u32)work->frame < (u32)(s32)work->points[0].duration)
        {
            RwV3d pivot;
            RwV3d offset;
            f32 step;
            Model* target;

            localDir = sAxisUp;
            step = work->angleStep;
            target = *(Model**)((u8*)fldFrameMoveCtl(work)->workData + 0x10);
            if (target != NULL)
            {
                const u8* origin = (const u8*)func_00318b60((u32)target);

                pivot.x = *(const f32*)(origin + 0x30);
                pivot.y = *(const f32*)(origin + 0x34);
                pivot.z = *(const f32*)(origin + 0x38);
                offset.x = -1.0f * pivot.x;
                offset.y = -1.0f * pivot.y;
                offset.z = -1.0f * pivot.z;
                func_00318a30(
                    *(Model**)((u8*)fldFrameMoveCtl(work)->workData + 0x10),
                    &offset, 2);
                func_00318a50(
                    *(Model**)((u8*)fldFrameMoveCtl(work)->workData + 0x10),
                    &localDir, step, 2);
                func_00318a30(
                    *(Model**)((u8*)fldFrameMoveCtl(work)->workData + 0x10),
                    &pivot, 2);
            }
            work->frame++;
            return KWLNTASK_CONTINUE;
        }
        ((RwMatrix*)work->drawMatrix)->at.z = 1.0f;
        ((RwMatrix*)work->drawMatrix)->up.y = 1.0f;
        ((RwMatrix*)work->drawMatrix)->right.x = 1.0f;
        ((RwMatrix*)work->drawMatrix)->up.x = 0.0f;
        ((RwMatrix*)work->drawMatrix)->right.z = 0.0f;
        ((RwMatrix*)work->drawMatrix)->right.y = 0.0f;
        ((RwMatrix*)work->drawMatrix)->at.y = 0.0f;
        ((RwMatrix*)work->drawMatrix)->at.x = 0.0f;
        ((RwMatrix*)work->drawMatrix)->up.z = 0.0f;
        ((RwMatrix*)work->drawMatrix)->pos.z = 0.0f;
        ((RwMatrix*)work->drawMatrix)->pos.y = 0.0f;
        ((RwMatrix*)work->drawMatrix)->pos.x = 0.0f;
        ((RwMatrix*)work->drawMatrix)->flags |=
            rwMATRIXINTERNALIDENTITY | rwMATRIXTYPEORTHONORMAL;
        func_004c31b0((RwMatrix*)work->drawMatrix, &localDir,
                      work->currentAngle - 180.0f, 1);
        func_001ad9e0(fldFrameMoveCtl(work), work->drawMatrix);
        func_001ae480(task);
        work->state = 1;
        return KWLNTASK_CONTINUE;
    }
    case 8:
    {
        work->state = 1;
        return KWLNTASK_CONTINUE;
    }
    default:
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_001af8e0
void func_001af8e0(KwlnTask* task)
{
    FldFrameMoveWork* work = (FldFrameMoveWork*)task->workData;

    if (work->drawMatrix != NULL)
    {
        func_004c3880(work->drawMatrix);
    }
    (*(void (**)(void*))jtbl_0096017C_abs)(task->workData);
}

// FUN_001af930 NONMATCHING
KwlnTask* func_001af930(KwlnTask* parent, void* resource)
{
    FldFrameMoveWork* work;
    KwlnTask* task;
    Model* model;

    work = (FldFrameMoveWork*)RwCalloc(1, 0x5a0, rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent,
                                          10,
                                          "field move",
                                          func_001ae580,
                                          func_001af8e0,
                                          work);
    if (task == NULL)
    {
        RwFree(work);
        return NULL;
    }
    work->resource = resource;
    model = fldFrameMoveModel(work);
    if (model != NULL && model->id < 100)
    {
        work->targetAnimation = (u16)*(u16*)((u8*)resource + 0xd6);
        work->turnMode = 0;
    }
    else
    {
        work->turnMode = 5;
    }
    return task;
}

// FUN_001AFA20 NONMATCHING
// Retail fully inlines fldFrameMoveWork/fldFrameMoveResolvePosition, and
// (pathMode==0 branch) fldFrameMoveAppend/fldFrameMoveCreateDebugPoint -
// none are called via jal. K_FldFrame_Raycast is duplicated per branch,
// not shared. Dispatch uses work->pathMode (0x18), not work->mode (0x8,
// a different field - see func_001b0260/func_001b0240). Residual: a
// register-bank floor (764B vs 800B window); logic verified vs retail.
u32 func_001afa20(f32 duration, KwlnTask* task, const RwV3d* position)
{
    FldFrameMoveWork* work;
    RwV3d line[2];
    RwV3d resolved;

    work = (FldFrameMoveWork*)task->workData;
    line[1] = *position;
    line[0] = *position;
    if (K_Scene_001a0250() != false)
    {
        line[0].y += 600.0f;
    }
    else
    {
        line[0].y += 200.0f;
    }
    line[1].y -= 1000.0f;
    switch (work->pathMode)
    {
    case 0:
        if (work->pointCount >= 47)
        {
            return false;
        }
        if (K_FldFrame_Raycast(line, &resolved) != false)
        {
            work->points[work->pointCount].position = resolved;
        }
        else
        {
            work->points[work->pointCount].position = *position;
        }
        work->points[work->pointCount].duration = duration;
        work->points[work->pointCount].kind = 0;
        if ((work->flags & 0x80000000) != 0)
        {
            work->points[work->pointCount].drawTask = K_Draw_CreatePositionTask(0);
            if (work->points[work->pointCount].drawTask != NULL)
            {
                K_Draw_SetPositionColor(work->points[work->pointCount].drawTask, &sDebugSphereColor);
                K_Draw_SetPositionPos(work->points[work->pointCount].drawTask,
                                      &work->points[work->pointCount].position);
            }
        }
        work->pointCount++;
        return true;
    case 1:
        if (work->pendingPointCount >= 7)
        {
            return false;
        }
        if (K_FldFrame_Raycast(line, &resolved) != false)
        {
            memcpy((u8*)work + 0x4e0 + work->pendingPointCount * 0x18, &resolved, sizeof(RwV3d));
        }
        else
        {
            memcpy((u8*)work + 0x4e0 + work->pendingPointCount * 0x18, position, sizeof(RwV3d));
        }
        *(f32*)((u8*)work + 0x4e0 + work->pendingPointCount * 0x18 + 0x0c) = duration;
        work->pendingPointCount++;
        return true;
    default:
        return false;
    }
}

// FUN_001AFD40 NONMATCHING
// Same inlining pattern as func_001afa20 above (fldFrameMoveWork,
// fldFrameMoveResolvePosition, fldFrameMoveAppend/CreateDebugPoint all
// inlined; retail does not jal any of them) - simpler single-path variant
// with a fixed kind=3, no pathMode dispatch.
u32 func_001afd40(f32 duration, KwlnTask* task, const RwV3d* position)
{
    FldFrameMoveWork* work;
    RwV3d line[2];
    RwV3d resolved;

    work = (FldFrameMoveWork*)task->workData;
    line[1] = *position;
    line[0] = *position;
    if (K_Scene_001a0250() != false)
    {
        line[0].y += 600.0f;
    }
    else
    {
        line[0].y += 200.0f;
    }
    line[1].y -= 1000.0f;
    if (work->pointCount >= 47)
    {
        return false;
    }
    if (K_FldFrame_Raycast(line, &resolved) != false)
    {
        work->points[work->pointCount].position = resolved;
    }
    else
    {
        work->points[work->pointCount].position = *position;
    }
    work->points[work->pointCount].duration = duration;
    work->points[work->pointCount].kind = 3;
    if ((work->flags & 0x80000000) != 0)
    {
        work->points[work->pointCount].drawTask = K_Draw_CreatePositionTask(0);
        if (work->points[work->pointCount].drawTask != NULL)
        {
            K_Draw_SetPositionColor(work->points[work->pointCount].drawTask, &sDebugSphereColor);
            K_Draw_SetPositionPos(work->points[work->pointCount].drawTask,
                                  &work->points[work->pointCount].position);
        }
    }
    work->pointCount++;
    return true;
}

// FUN_001AFF70
// The existing model/matrix-derived position guess did not match retail
// at all - retail's bytes have NO fldFrameMoveModel/mdlGetMatrix calls
// and never write points[pointCount].position for this kind=1 point (it
// is a duration/kind-only marker point, position is left whatever it was).
u32 func_001aff70(KwlnTask* task, s32 duration)
{
    FldFrameMoveWork* work;

    work = (FldFrameMoveWork*)task->workData;
    if (work->pointCount < 47)
    {
        if (work->pointCount > 0 &&
            work->points[work->pointCount - 1].kind == 1)
        {
            return false;
        }
        work->points[work->pointCount].kind = 1;
        work->points[work->pointCount].duration = (f32)duration;
        work->pointCount++;
        return true;
    }
    return false;
}

// FUN_001b0020
u32 func_001b0020(KwlnTask* task, const RwV3d* position, s32 duration)
{
    FldFrameMoveWork* work;

    work = (FldFrameMoveWork*)task->workData;
    if (work->pointCount < 47)
    {
        work->points[work->pointCount].kind = 2;
        work->points[work->pointCount].position = *position;
        work->points[work->pointCount].duration = (f32)duration;
        work->pointCount++;
        return true;
    }
    return false;
}

// FUN_001b00c0 NONMATCHING
void func_001b00c0(KwlnTask* task)
{
    FldFrameMoveWork* work;
    s32 i;
    Model* model;

    work = fldFrameMoveWork(task);
    if (work->mode == 3 || work->mode == 4)
    {
        return;
    }
    if ((work->flags & 0x80000000) != 0)
    {
        for (i = 0; i < work->pointCount; i++)
        {
            if (work->points[i].drawTask != NULL)
            {
                kwlnTaskDestroyWithHierarchy(work->points[i].drawTask);
                work->points[i].drawTask = NULL;
            }
        }
    }
    model = fldFrameMoveModel(work);
    if (work->pointCount > 0 && model != NULL)
    {
        mdlLookAtDisableTarget(model);
    }
    memset(work->points, 0, sizeof(work->points));
    work->pointCount = 0;
    work->pendingPointCount = 0;
    work->state = 1;
}

// FUN_001b01b0
u32* func_001b01b0(KwlnTask* task, s32 index)
{
    return &((FldFrameMoveWork*)task->workData)->points[index].kind;
}

// FUN_001b01d0
void func_001b01d0(KwlnTask* task, s32 index, const FldFrameMovePoint* point)
{
    FldFrameMoveWork* work;
    s32 offset;

    work = (FldFrameMoveWork*)task->workData;
    offset = index * 0x18;
    *(FldFrameMovePoint*)(offset + (int)work + 0x20) = *point;
}

// FUN_001b0220
s32 func_001b0220(KwlnTask* task)
{
    return ((FldFrameMoveWork*)task->workData)->pointCount;
}

// FUN_001b0230
void func_001b0230(KwlnTask* task, s32 pointCount)
{
    ((FldFrameMoveWork*)task->workData)->pointCount = pointCount;
}

// FUN_001b0240
void func_001b0240(KwlnTask* task, s32 mode)
{
    ((FldFrameMoveWork*)task->workData)->pathMode = mode;
}

// FUN_001b0250
void func_001b0250(KwlnTask* task, s32 turnMode)
{
    ((FldFrameMoveWork*)task->workData)->turnMode = turnMode;
}

// FUN_001b0260
void func_001b0260(KwlnTask* task, s32 mode)
{
    FldFrameMoveWork* work;
    CollisCtl* ctl;

    work = (FldFrameMoveWork*)task->workData;
    work->mode = mode;
    if (mode == 1)
    {
        ctl = (CollisCtl*)((KwlnTask*)*(void**)((u8*)work->resource + 0x1e0))->workData;
        ctl->flags |= COLLISCTL_FLAG_NOUPDATE;
    }
    else
    {
        ctl = (CollisCtl*)((KwlnTask*)*(void**)((u8*)work->resource + 0x1e0))->workData;
        ctl->flags &= ~COLLISCTL_FLAG_NOUPDATE;
    }
}

/*
 * The collision package passes triangle data as a small, engine-private
 * record.  Keeping the record definition here makes the callback code
 * readable without exposing that implementation detail in the public header.
 */
typedef struct FldFrameCollisionTriangle
{
    RwV3d normal;
    u8 reserved[16];
    const RwV3d* vertices[3];
} FldFrameCollisionTriangle;

typedef struct FldFrameCollisionCollector
{
    RwV3d points[64];
    RwV3d normals[64];
    f32 distances[64];
    u8 reserved[0x400];
    u32 mode;
    u32 count;
    u32 blockingCount;
    u8 tail[0x28];
    void* owner;
} FldFrameCollisionCollector;
typedef struct FldFrameCollisionQuery
{
    RwV3d center;
    f32 radius;
    u8 reserved[8];
    u32 type;
} FldFrameCollisionQuery;


typedef struct FldFrameResourceSet
{
    u32 count;
    u32 reserved;
    void* items[64];
} FldFrameResourceSet;
typedef struct FldFrameResourceQuery
{
    void* output;
    u32 direction[6];
    u32 directionMode;
    RwV4d position;
    void* resource;
} FldFrameResourceQuery;
typedef struct FldFrameResourceTable
{
    u32 count;
    u8 reserved[4];
    void* items[64];
} FldFrameResourceTable;

typedef struct FldFrameMaterialWork
{
    u8 reserved_00[8];
    u32 flags;
    u8 reserved_0c[0x14];
    void* items;
    u32 itemCount;
    u8 reserved_28[4];
    void* indices;
} FldFrameMaterialWork;

typedef struct FldFrameMaterialLink
{
    u8 reserved_00[0x18];
    FldFrameMaterialWork* work;
} FldFrameMaterialLink;

typedef struct FldFrameMaterialSet
{
    FldFrameResourceTable* table;
    u8 reserved_04[0x2c];
    FldFrameMaterialLink* link;
} FldFrameMaterialSet;

typedef struct FldFrameMaterialIndex
{
    u8 reserved_00[6];
    u16 value;
} FldFrameMaterialIndex;

static const char sFldFrameMaterialName[] = "per3TrnsWall";

static f32 FldFrame_Dot(const RwV3d* a, const RwV3d* b)
{
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

static f32 FldFrame_LengthSquared(const RwV3d* value)
{
    return FldFrame_Dot(value, value);
}

static void FldFrame_CollisionCollectorReset(FldFrameCollisionCollector* collector)
{
    s32 i;

    collector->mode = 0;
    collector->count = 0;
    collector->blockingCount = 0;
    collector->owner = NULL;

    for (i = 0; i < 64; i++)
    {
        collector->points[i].x = 0.0f;
        collector->points[i].y = 0.0f;
        collector->points[i].z = 0.0f;
        collector->normals[i].x = 0.0f;
        collector->normals[i].y = 0.0f;
        collector->normals[i].z = 0.0f;
        collector->distances[i] = 1.0e30f;
    }
}

static s32 FldFrame_FindCollision(const FldFrameCollisionCollector* collector,
                                  const RwV3d* normal)
{
    s32 i;

    for (i = 0; i < (s32)collector->count; i++)
    {
        if (collector->normals[i].x == normal->x &&
            collector->normals[i].y == normal->y &&
            collector->normals[i].z == normal->z)
        {
            return i;
        }
    }
    return -1;
}

static void FldFrame_RecordCollision(FldFrameCollisionCollector* collector,
                                      const RwV3d* point, const RwV3d* normal,
                                      f32 distance)
{
    s32 index;

    index = FldFrame_FindCollision(collector, normal);
    if (index < 0)
    {
        if (collector->count >= 64)
        {
            return;
        }
        index = collector->count;
        collector->count++;
    }

    if (distance < collector->distances[index])
    {
        collector->points[index] = *point;
        collector->normals[index] = *normal;
        collector->distances[index] = distance;
    }
}

static void FldFrame_ApplyCollisions(FldFrameCollisionCollector* collector,
                                     RwV3d* translation, f32 radius)
{
    s32 i;

    for (i = 0; i < (s32)collector->count; i++)
    {
        RwV3d normal;
        f32 distance;
        f32 correction;
        f32 inward;

        distance = collector->distances[i];
        correction = radius - distance;
        if (correction <= 0.0f)
        {
            continue;
        }

        normal = collector->normals[i];
        if (FldFrame_LengthSquared(&normal) > 0.000001f)
        {
            RwV3dNormalize(&normal, &normal);
        }

        inward = FldFrame_Dot(translation, &normal);
        if (inward < 0.0f)
        {
            translation->x -= normal.x * inward;
            translation->y -= normal.y * inward;
            translation->z -= normal.z * inward;
        }

        if (FldFrame_LengthSquared(translation) < 0.000001f)
        {
            translation->x += normal.x * correction;
            translation->y += normal.y * correction;
            translation->z += normal.z * correction;
        }
    }
}

// FUN_001aae10
RwV3d* func_001aae10(RwV3d* dst, const RwV3d* point,
                     const RwV3d* start, const RwV3d* end)
{
    RwV3d edge;
    f32 projection;
    f32 edgeLengthSquared;
    f32 fraction;

    edge.x = end->x - start->x;
    edge.y = end->y - start->y;
    edge.z = end->z - start->z;
    projection = point->x * edge.x + point->y * edge.y + point->z * edge.z -
                 (start->x * edge.x + start->y * edge.y + start->z * edge.z);

    if (projection <= 0.0f)
    {
        *dst = *start;
    }
    else
    {
        edgeLengthSquared = edge.x * edge.x + edge.y * edge.y + edge.z * edge.z;
        if (projection < edgeLengthSquared)
        {
            fraction = projection / edgeLengthSquared;
            dst->x = edge.x * fraction;
            dst->y = edge.y * fraction;
            dst->z = edge.z * fraction;
            dst->x += start->x;
            dst->y += start->y;
            dst->z += start->z;
        }
        else
        {
            *dst = *end;
        }
    }

    return dst;
}

// FUN_001aaf30 NONMATCHING
void* func_001aaf30(const RwV3d* point, void* unused,
                    const FldFrameCollisionTriangle* triangle,
                    FldFrameCollisionCollector* collector)
{
    const RwV3d* vertices[3];
    RwV3d projected;
    RwV3d closest;
    RwV3d delta;
    f32 signedDistance;
    f32 distance;
    s32 i;

    (void)unused;
    if (point == NULL || triangle == NULL || collector == NULL)
    {
        return (void*)triangle;
    }

    vertices[0] = triangle->vertices[0];
    vertices[1] = triangle->vertices[1];
    vertices[2] = triangle->vertices[2];
    if (vertices[0] == NULL || vertices[1] == NULL || vertices[2] == NULL)
    {
        return (void*)triangle;
    }

    signedDistance = FldFrame_Dot(vertices[0], &triangle->normal) -
                     FldFrame_Dot(point, &triangle->normal);
    projected.x = point->x + triangle->normal.x * signedDistance;
    projected.y = point->y + triangle->normal.y * signedDistance;
    projected.z = point->z + triangle->normal.z * signedDistance;

    if (K_FldFrame_IsPointInTriangle(&projected, vertices, &triangle->normal))
    {
        distance = fabsf(signedDistance);
        FldFrame_RecordCollision(collector, &projected, &triangle->normal, distance);
    }
    else
    {
        distance = 1.0e30f;
        for (i = 0; i < 3; i++)
        {
            func_001aae10(&closest, &projected, vertices[i], vertices[(i + 1) % 3]);
            delta.x = point->x - closest.x;
            delta.y = point->y - closest.y;
            delta.z = point->z - closest.z;
            if (FldFrame_LengthSquared(&delta) < distance * distance)
            {
                distance = RwV3dLength(&delta);
                projected = closest;
            }
        }
        if (distance < 1.0e30f)
        {
            FldFrame_RecordCollision(collector, &projected, &triangle->normal, distance);
        }
    }

    return (void*)triangle;
}

// FUN_001ab390 NONMATCHING
s32 func_001ab390(void* collision, const RwV3d* pos,
                  RwV3d* translation, f32 sphereCollisRadius)
{
    FldFrameCollisionCollector collector;
    FldFrameCollisionQuery query;
    RwV3d diff;
    f32 correction;
    f32 adjustX;
    f32 adjustY;
    f32 adjustZ;
    f32 dot;
    s32 i;
    s32 result;

    query.center.x = pos->x + translation->x;
    query.center.y = pos->y + translation->y;
    query.center.z = pos->z + translation->z;
    query.radius = sphereCollisRadius;
    query.type = 3;
    for (i = 0; i < 64; i++)
    {
        memset(&collector.points[i], 0, sizeof(RwV3d));
        memset(&collector.normals[i], 0, sizeof(RwV3d));
        collector.distances[i] = 1.0e30f;
    }
    collector.count = 0;
    result = 0;
    if (collision == NULL)
    {
        return result;
    }

    func_00464020(collision, &query, func_001aaf30, &collector);
    for (i = 0; i < (s32)collector.count; i++)
    {
        if (collector.distances[i] < 1.0e30f)
        {
            diff.x = query.center.x - collector.points[i].x;
            diff.y = query.center.y - collector.points[i].y;
            diff.z = query.center.z - collector.points[i].z;
            func_004c69f0(&diff, &diff);
            correction = query.radius - collector.distances[i];
            adjustX = diff.x * correction;
            adjustY = diff.y * correction;
            adjustZ = diff.z * correction;
            dot = translation->y * diff.y +
                  translation->x * diff.x +
                  translation->z * diff.z;
            if (dot < 0.0f)
            {
                translation->x -= diff.x * dot;
                translation->y -= diff.y * dot;
                translation->z -= diff.z * dot;
            }
            result = 1;
            if (translation->x == 0.0f &&
                translation->y == 0.0f &&
                translation->z == 0.0f)
            {
                translation->x += adjustX;
                translation->y += adjustY;
                translation->z += adjustZ;
                result = 1;
            }
        }
    }
    return result;
}

// Reconstructed point/triangle collision callback.
// Remaining differences are MWCCPS2 stack-slot and register scheduling residuals.
// FUN_001ab640 NONMATCHING
void* func_001ab640(const RwV3d* point, const void* triangle,
                    FldFrameCollisionCollector* collector)
{
    const FldFrameCollisionTriangle* candidate;
    const RwV3d* vertexPointers[3];
    RwV3d vertices[3];
    RwV3d projected;
    RwV3d normal;
    RwV3d closest;
    RwV3d delta;
    RwMatrix* matrix;
    f32 distance;
    f32 planeDistance;
    s32 index;
    s32 i;

    candidate = (const FldFrameCollisionTriangle*)triangle;
    normal = candidate->normal;
    matrix = func_004cb2f0(*(void**)((u8*)collector->owner + 4));
    func_004c6ca0(&normal, &candidate->normal, 1, matrix);
    func_004c69f0(&normal, &normal);

    for (i = 0; i < 3; i++)
    {
        func_004c6c20(&vertices[i], candidate->vertices[i], 1, matrix);
        vertexPointers[i] = &vertices[i];
    }

    if (normal.x * *(f32*)((u8*)collector + 0xb0c) +
        normal.y * *(f32*)((u8*)collector + 0xb10) +
        normal.z * *(f32*)((u8*)collector + 0xb14) < 0.0f &&
        collector->mode != 0)
    {
        return (void*)triangle;
    }

    if (fabsf(normal.y) <= fGpffff8078)
    {
        return (void*)triangle;
    }

    planeDistance =
        (vertices[0].x * normal.x + vertices[0].y * normal.y +
         vertices[0].z * normal.z) -
        (point->x * normal.x + point->y * normal.y + point->z * normal.z);
    projected.x = point->x + normal.x * planeDistance;
    projected.y = point->y + normal.y * planeDistance;
    projected.z = point->z + normal.z * planeDistance;

    if (K_FldFrame_IsPointInTriangle(&projected, vertexPointers, &normal))
    {
        distance = fabsf(planeDistance);
        index = 0;
        while (index < (s32)collector->count &&
               (collector->normals[index].x != normal.x ||
                collector->normals[index].y != normal.y ||
                collector->normals[index].z != normal.z))
        {
            index++;
        }
        if (index < (s32)collector->count)
        {
            if (distance < collector->distances[index])
            {
                collector->points[index] = projected;
                collector->normals[index] = normal;
                collector->distances[index] = distance;
                if (collector->mode == 1 &&
                    *(u32*)((u8*)collector + 0xa00 + index * 4) == 0)
                {
                    collector->blockingCount++;
                    *(u32*)((u8*)collector + 0xa00 + index * 4) = 1;
                }
            }
        }
        else
        {
            index = collector->count;
            if (distance < collector->distances[index])
            {
                collector->points[index] = projected;
                collector->normals[index] = normal;
                collector->distances[index] = distance;
                if (collector->mode == 1 &&
                    *(u32*)((u8*)collector + 0xa00 + index * 4) == 0)
                {
                    collector->blockingCount++;
                    *(u32*)((u8*)collector + 0xa00 + index * 4) = 1;
                }
                collector->count++;
            }
        }
        return (void*)triangle;
    }

    for (i = 0; i < 3; i++)
    {
        func_001aae10(&closest, &projected, vertexPointers[i],
                      vertexPointers[(i + 1) % 3]);
        delta.x = point->x - closest.x;
        delta.y = point->y - closest.y;
        delta.z = point->z - closest.z;
        distance = func_004c6ac0(&delta);

        index = 0;
        while (index < (s32)collector->count &&
               (collector->normals[index].x != normal.x ||
                collector->normals[index].y != normal.y ||
                collector->normals[index].z != normal.z))
        {
            index++;
        }
        if (index < (s32)collector->count)
        {
            if (distance < collector->distances[index])
            {
                collector->points[index] = closest;
                collector->normals[index] = normal;
                collector->distances[index] = distance;
                if (collector->mode == 1 &&
                    *(u32*)((u8*)collector + 0xa00 + index * 4) == 0)
                {
                    collector->blockingCount++;
                    *(u32*)((u8*)collector + 0xa00 + index * 4) = 1;
                }
            }
        }
        else
        {
            index = collector->count;
            if (distance < collector->distances[index])
            {
                collector->points[index] = closest;
                collector->normals[index] = normal;
                collector->distances[index] = distance;
                if (collector->mode == 1 &&
                    *(u32*)((u8*)collector + 0xa00 + index * 4) == 0)
                {
                    collector->blockingCount++;
                    *(u32*)((u8*)collector + 0xa00 + index * 4) = 1;
                }
                collector->count++;
            }
        }
    }
    return (void*)triangle;
}

// FUN_001abcd0
void* func_001abcd0(void* collisionWorld, void* state)
{
    *(void**)((u8*)state + 0xb34) = collisionWorld;
    func_00464120(collisionWorld, (u8*)state + 0xb18,
                  func_001ab640, state);
    return collisionWorld;
}

extern u8 DAT_008717f0[];
extern void* func_00318b80(u32 id);
extern void* func_00318b60(u32 id);
extern void* func_004353f0(void* arg);
extern u32 func_001acb70(void* collisionWorld, const RwV3d* line, RwV3d* hitPointDst);
extern u32 func_001afd40(f32 duration, KwlnTask* task, const RwV3d* position);

// FUN_001abd20 NONMATCHING
// Remaining: post-grid collision processing (type1 walk, final apply, dampening)
s32 func_001abd20(void* collisionWorld, const RwV3d* pos,
                   RwV3d* translation, f32 sphereCollisRadius, u16 resTypeId)
{
    FldFrameCollisionCollector collector;
    void* type10ListHead;
    RwV3d query;
    void* type3ListHead;
    void* type1ListHead;
    s32 i;
    void* listNode;
    void* listThree;
    void* model;
    RwV3d diff;
    RwV3d rayOrigin;
    RwV3d hitPoint;
    u16 resTypeMask;
    s32 returnVal;

    returnVal = 0;

    type10ListHead = (void*)func_003b5d50(10);
    type3ListHead = (void*)func_003b5d50(3);
    type1ListHead = (void*)func_003b5d50(1);

    query.x = pos->x + translation->x;
    query.y = pos->y + translation->y;
    query.z = pos->z + translation->z;
    collector.count = 0;
    collector.blockingCount = 0;
    collector.owner = NULL;
    for (i = 0; i < 64; i++)
    {
        memset(&collector.points[i], 0, sizeof(RwV3d));
        memset(&collector.normals[i], 0, sizeof(RwV3d));
        collector.distances[i] = 1.0e30f;
        *(u32*)((u8*)&collector + 0xa00 + i * 4) = 0;
    }
    collector.owner = collisionWorld;

    for (i = 0; i < 7; i++)
    {
        *(u32*)((u8*)&collector + 0xb18 + i * 4) =
            *(u32*)((u8*)&collector + 0xb60 + i * 4);
    }

    func_004c69f0((RwV3d*)((u8*)&collector + 0xb0c), translation);
    memset((u8*)&collector + 0xb38, 0, 0xc);

    if (collisionWorld == NULL)
        return 0;

    resTypeMask = (u16)resTypeId;

    listNode = *(void**)((u8*)type10ListHead + 0xf8);
    while (listNode != NULL)
    {
        if ((*(u32*)((u8*)listNode + 0x28) & 2) &&
            (*(u32*)((u8*)listNode + 0x110) == 1))
        {
            model = (void*)func_00318b80(*(u32*)((u8*)listNode + 0x104));
            if (model != NULL)
            {
                FUN_004916d0(model, func_001abcd0, &collector);
                rayOrigin = *pos;
                rayOrigin.y += 400.0f;
                hitPoint.x = 0.0f;
                hitPoint.y = 0.0f;
                hitPoint.z = 0.0f;
                if (func_001acb70(model, &rayOrigin, &hitPoint) == 1)
                    translation->y = hitPoint.y - (pos->y - sphereCollisRadius);
            }
        }
    }

    listThree = *(void**)((u8*)type3ListHead + 0xf8);
    while (listThree != NULL)
    {
        if ((*(u32*)((u8*)listThree + 0x28) & 2) &&
            (*(u32*)((u8*)listThree + 0x110) == 1))
        {
            model = (void*)func_00318b80(*(u32*)((u8*)listThree + 0x104));
            if (model != NULL)
            {
                FUN_004916d0(model, func_001abcd0, &collector);
                rayOrigin = *pos;
                rayOrigin.y -= 600.0f;
                hitPoint.x = 0.0f;
                hitPoint.y = 0.0f;
                hitPoint.z = 0.0f;
                if (func_001acb70(model, &rayOrigin, &hitPoint) == 1)
                    translation->y = hitPoint.y - (pos->y - sphereCollisRadius);
            }
        }
        listThree = *(void**)((u8*)listThree + 0xf8);
    }
    func_001abd20(collisionWorld, pos, translation, sphereCollisRadius, resTypeId);
    {
        s32 quadIter;
        for (quadIter = 0; quadIter < 4; quadIter++)
        {
            void* gridEntry;
            void* objData;
            s32 entryOff = quadIter * 448;
            void* gridBase = (void*)func_00318b60(*(u32*)(DAT_008717f0 + 0));
            gridEntry = (u8*)gridBase + entryOff;

            if (*(u32*)((u8*)gridEntry + 0x48) == 0) continue;
            if (*(u32*)((u8*)gridEntry + 0x54) == 0) continue;
            if (*(u16*)(*(void**)((u8*)gridEntry + 0x54)) == resTypeMask) continue;

            objData = *(void**)((u8*)gridEntry + 0x54);
            model = (void*)func_00318b80(*(u32*)((u8*)objData + 0x1e8));
            if (model != NULL)
            {
                FUN_004916d0(model, func_001abcd0, &collector);
            }
            else if (resTypeMask == 0x400)
            {
                void* rootObj;
                RwV3d* vecA;
                RwV3d* vecB;
                f32 dist;
                s32 moveCount;

                rootObj = (void*)func_00318b60(*(u32*)(DAT_008717f0 + 0));
                vecA = (RwV3d*)((u8*)rootObj + 0x30);
                vecB = (RwV3d*)((u8*)func_00318b60(*(u32*)((u8*)gridEntry + 0x50)) + 0x30);

                diff.x = vecB->x - vecA->x;
                diff.y = vecB->y - vecA->y;
                diff.z = vecB->z - vecA->z;

                dist = func_004c69f0(&diff, &diff);
                if (dist >= 97.0f) continue;

                moveCount = func_001b0220(*(void**)((u8*)gridEntry + 0x170));
                if (moveCount != 0) continue;
                if (*(u32*)((u8*)gridEntry + 0x48) == 0) continue;

                {
                    u8 typeCode;
                    void* typeInfo = func_004353f0(gridEntry);
                    typeCode = (u8)(((u32)typeInfo >> 24) >> 8);
                    if (typeCode == 5) continue;
                }

                {
                    RwV3d scaled;
                    scaled.x = diff.x * 50.0f;
                    scaled.y = diff.y * 50.0f;
                    scaled.z = diff.z * 50.0f;
                    scaled.x += vecA->x;
                    scaled.y += vecA->y;
                    scaled.z += vecA->z;
                    func_001afd40(50.0f, *(KwlnTask**)(*(u32*)((u8*)gridEntry + 0x170)),
                                  &scaled);
                }
            }
        }
    }
    /* Type 1 list walk (post-grid) */
    listNode = *(void**)((u8*)type1ListHead + 0xf8);
    while (listNode != NULL)
    {
        if ((*(u32*)((u8*)listNode + 0x28) & 2))
        {
            s32 field114 = *(s32*)((u8*)listNode + 0x114);
            if (field114 != 0)
            {
                model = (void*)func_00318b80(field114);
                if (model != NULL)
                    FUN_004916d0(model, func_001abcd0, &collector);
            }
        }
        listNode = *(void**)((u8*)listNode + 0xf8);
    }

    for (i = 0; i < (s32)collector.count; i++)
    {
        f32 dv;
        f32 corr;
        u32 fl;

        dv = collector.distances[i];
        if (dv >= 1.0e30f) continue;

        diff.x = collector.points[i].x - pos->x;
        diff.y = collector.points[i].y - pos->y;
        diff.z = collector.points[i].z - pos->z;
        func_004c69f0(&diff, &diff);

        if (collector.distances[i] <= 0.0f) continue;

        corr = sphereCollisRadius - collector.distances[i];
        if (corr <= 0.0f) continue;

        fl = *(u32*)((u8*)&collector + 0xa00 + i * 4);
        if (fl == 1)
        {
            RwV3d nrm;
            f32 nd;
            nrm = collector.normals[i];
            func_004c69f0(&nrm, &nrm);
            nd = FldFrame_Dot(&nrm, &diff);
            if (nd > 0.0f)
            {
                translation->x += nrm.x * corr;
                translation->y += nrm.y * corr;
                translation->z += nrm.z * corr;
            }
        }
        else
        {
            translation->x += diff.x * corr;
            translation->y += diff.y * corr;
            translation->z += diff.z * corr;
        }

        returnVal = 1;

        if (fabsf(translation->x) < 0.000001f &&
            fabsf(translation->y) < 0.000001f &&
            fabsf(translation->z) < 0.000001f)
        {
            translation->x += diff.x * corr;
            translation->y += diff.y * corr;
            translation->z += diff.z * corr;
        }
    }

    {
        f32 trLen;
        trLen = func_004c69f0(&diff, translation);
        if (trLen > 9.0f)
        {
            translation->x = 8.5f * diff.x;
            translation->y = 8.5f * diff.y;
            translation->z = 8.5f * diff.z;
        }
    }

    return returnVal;
}
// FUN_001ac950 NONMATCHING
void* func_001ac950(const RwV3d* line, void* unused,
                    const void* triangle, FldFrameRaycast* raycast)
{
    const FldFrameCollisionTriangle* candidate;
    RwV3d segment;
    RwV3d fromVertex;
    f32 denominator;
    f32 fraction;

    (void)unused;
    if (line == NULL || triangle == NULL || raycast == NULL)
    {
        return (void*)triangle;
    }

    candidate = (const FldFrameCollisionTriangle*)triangle;
    if (candidate->vertices[0] == NULL)
    {
        return (void*)triangle;
    }

    segment.x = line[1].x - line[0].x;
    segment.y = line[1].y - line[0].y;
    segment.z = line[1].z - line[0].z;
    denominator = FldFrame_Dot(&candidate->normal, &segment);
    if (fabsf(denominator) < 0.000001f)
    {
        return (void*)triangle;
    }

    fromVertex.x = candidate->vertices[0]->x - line[0].x;
    fromVertex.y = candidate->vertices[0]->y - line[0].y;
    fromVertex.z = candidate->vertices[0]->z - line[0].z;
    fraction = FldFrame_Dot(&candidate->normal, &fromVertex) / denominator;
    if (fraction < 0.0f || fraction > 1.0f)
    {
        return (void*)triangle;
    }

    raycast->hitPointDst->x = line[0].x + segment.x * fraction;
    raycast->hitPointDst->y = line[0].y + segment.y * fraction;
    raycast->hitPointDst->z = line[0].z + segment.z * fraction;
    raycast->didHit = true;
    return (void*)triangle;
}

// FUN_001aca40 NONMATCHING
void* func_001aca40(f32 fraction, const RwV3d* line,
                    void* unused, FldFrameRaycast* raycast)
{
    RwV3d segment;

    (void)unused;
    if (line == NULL || raycast == NULL || fraction >= raycast->nearestFraction)
    {
        return unused;
    }

    segment.x = line[1].x - line[0].x;
    segment.y = line[1].y - line[0].y;
    segment.z = line[1].z - line[0].z;
    raycast->hitPointDst->x = line[0].x + segment.x * fraction;
    raycast->hitPointDst->y = line[0].y + segment.y * fraction;
    raycast->hitPointDst->z = line[0].z + segment.z * fraction;
    raycast->nearestFraction = fraction;
    raycast->didHit = true;
    return unused;
}

// FUN_001acb20
void* func_001acb20(void* collisionWorld, FldFrameRaycast* raycast)
{
    raycast->hitObject = collisionWorld;
    func_00464120(collisionWorld, &raycast->line[0],
                  func_001aca40, raycast);
    return collisionWorld;
}

// FUN_001acb70 NONMATCHING
u32 func_001acb70(void* collisionWorld, const RwV3d* line,
                  RwV3d* hitPointDst)
{
    FldFrameRaycast raycast;

    raycast.hitPointDst = hitPointDst;
    raycast.didHit = false;
    raycast.line[0] = line[0];
    raycast.line[1] = line[1];
    raycast.intersectionType = 1;
    raycast.nearestFraction = 1.0f;
    raycast.hitObject = NULL;

    if (collisionWorld != NULL)
    {
        FUN_004916d0(collisionWorld, func_001acb20, &raycast);
    }
    return raycast.didHit;
}

// FUN_001ace90
void* func_001ace90(void* resource, void* unused, FldFrameMaterialSet* set)
{
    FldFrameMaterialWork* work;
    FldFrameResourceTable* table;
    FldFrameMaterialIndex* indices;
    void** slot;
    void* item;
    s32 count;
    s32 j;
    s32 i;
    u32 key;
    u16 index;
    work = set->link->work;
    indices = (FldFrameMaterialIndex*)work->indices;
    work->flags |= 0x40;
    key = *(u32*)((u8*)unused + 0x18);
    index = indices[key].value;
    item = ((void**)work->items)[index];
    if (!K_Clump_MatUsrDataHasData_typed(item, sFldFrameMaterialName))
    {
        return unused;
    }

    count = work->itemCount;
    i = 0;
    while (i < count)
    {
        item = ((void**)work->items)[i];
        j = 0;
        while (j < 0x40)
        {
            table = set->table;
            slot = (void**)((u8*)table + j * 4 + 8);
            if (*slot == NULL)
            {
                *slot = item;
                table = set->table;
                table->count++;
                break;
            }
            if (*slot == item)
            {
                break;
            }
            j++;
        }
        i++;
    }
    return unused;
}

// FUN_001acfc0
void* func_001acfc0(void* resource, void* state)
{
    RwSphere* sphere;

    func_004912b0(resource);
    sphere = func_004912b0(resource);
    if (RwCameraFrustumTestSphere(*(RwCamera**)DAT_00960070_abs, sphere) != rwSPHEREOUTSIDE)
    {
        *(void**)((u8*)state + 0x30) = resource;
        func_00464120(resource, (u8*)state + 4, func_001ace90, state);
    }
    return resource;
}

// FUN_001ad050
void func_001ad050(void* collisionWorld, const RwV4d* position,
                   u32* direction, void* result)
{
    struct
    {
        void* output;
        u32 direction[6];
        u32 directionMode;
        RwV4d position;
        u32 reserved;
    } resources;
    struct
    {
        u32 x;
        u32 y;
    } *src, *dst;
    u32 x, y;
    s32 i;

    memset(&resources, 0, sizeof(resources));
    resources.directionMode = 1;
    src = (void*)direction;
    dst = (void*)resources.direction;
    i = 3;
    do
    {
        x = src->x;
        y = src->y;
        src++;
        i--;
        dst->x = x;
        dst->y = y;
        dst++;
    } while (i > 0);
    resources.position = *position;
    resources.output = result;
    FUN_004916d0(collisionWorld, func_001acfc0, &resources);
}

// FUN_001ad120
void* func_001ad120(void* unused, void* collision, FldFrameAtomicQuery* query)
{
    void* geometry;
    void* entry;
    u8* triangles;
    u8* triangle;
    u32 offset;
    u32 materialIndex;
    void** materials;
    void* material;
    s32 i;

    geometry = *(void**)((u8*)query->atomic + 0x18);
    triangles = *(u8**)((u8*)geometry + 0x2c);
    entry = *(void**)((u8*)geometry + 8);
    entry = (void*)((uintptr_t)entry | 0x40);
    *(void**)((u8*)geometry + 8) = entry;
    offset = *(u32*)((u8*)collision + 0x18) * 8;
    offset += (u32)triangles;
    triangle = (u8*)offset;
    materialIndex = *(u16*)(triangle + 6);
    materials = *(void***)((u8*)geometry + 0x20);
    material = materials[materialIndex];
    if (!K_Clump_MatUsrDataHasData_typed(material, D_00678CE0_typed))
    {
        return collision;
    }

    for (i = 0; i < 64; i++)
    {
        void** slot;

        slot = (void**)query->output;
        slot += i;
        slot = (void**)((u8*)slot + 0x108);
        if (*slot == NULL)
        {
            *slot = query->atomic;
            (*(u32*)((u8*)query->output + 4))++;
            break;
        }
        if (*slot == query->atomic)
        {
            break;
        }
    }
    return collision;
}

// FUN_001ad220
void func_001ad220(void* object, const RwV3d* point, void* result)
{
    FldFrameAtomicQuery query;
    u32* src;
    u32* dst;
    u32 x;
    u32 y;
    s32 i;
    RwSphere* sphere;

    memset(&query, 0, sizeof(query));
    *(u32*)(query.intersection + 0x18) = 1;
    src = (u32*)point;
    dst = (u32*)query.intersection;
    i = 3;
    do
    {
        x = src[0];
        y = src[1];
        src += 2;
        i--;
        dst[0] = x;
        dst[1] = y;
        dst += 2;
    } while (i > 0);
    query.output = result;
    sphere = func_004912b0(*(void**)object);
    if (RwCameraFrustumTestSphere(*(RwCamera**)DAT_00960070_abs, sphere) != rwSPHEREOUTSIDE)
    {
        query.atomic = *(void**)object;
        func_00464120(query.atomic, query.intersection,
                      func_001ad120, &query);
    }
}

// FUN_001adc20
void func_001adc20(KwlnTask* collisCtlTask, const RwV3d* position)
{
    CollisCtl* ctl;
    RwMatrixTolerance tolerance;

    ctl = (CollisCtl*)collisCtlTask->workData;
    if (ctl->mdl == NULL)
    {
        return;
    }

    mdlGetMatrix(ctl->mdl)->pos = *position;
    RwEngineGetMatrixTolerances(&tolerance);
    RwMatrixOptimize(mdlGetMatrix(ctl->mdl), &tolerance);
    RwMatrixUpdate(mdlGetMatrix(ctl->mdl));
    ctl->xGrid = (mdlGetMatrix(ctl->mdl)->pos.x + 400.0f) / 800.0f;
    ctl->zGrid = (mdlGetMatrix(ctl->mdl)->pos.z + 400.0f) / 800.0f;
}

// FUN_001add40
void func_001add40(KwlnTask* collisCtlTask)
{
    CollisCtl* ctl;

    ctl = (CollisCtl*)collisCtlTask->workData;
    ctl->xGrid = (mdlGetMatrix(ctl->mdl)->pos.x + 400.0f) / 800.0f;
    ctl->zGrid = (mdlGetMatrix(ctl->mdl)->pos.z + 400.0f) / 800.0f;

}
// FUN_001ae0d0
void func_001ae0d0(KwlnTask* collisCtlTask)
{
    CollisCtl* ctl;
    RwMatrix* matrix;
    RwV3d line[2];
    RwV3d hitPoint;
    RwMatrixTolerance tolerance;

    ctl = (CollisCtl*)collisCtlTask->workData;
    matrix = mdlGetMatrix(ctl->mdl);
    line[1] = matrix->pos;
    line[0] = line[1];
    line[0].y += ctl->sphereCollisRadius;
    line[1].y -= 800.0f;
    if (K_FldFrame_Raycast(line, &hitPoint) == true)
    {
        hitPoint.y += 3.0f;
        ctl = (CollisCtl*)collisCtlTask->workData;
        if (ctl->mdl != NULL)
        {
            mdlGetMatrix(ctl->mdl)->pos = hitPoint;
            RwEngineGetMatrixTolerances(&tolerance);
            RwMatrixOptimize(mdlGetMatrix(ctl->mdl), &tolerance);
            RwMatrixUpdate(mdlGetMatrix(ctl->mdl));
            ctl->xGrid = (mdlGetMatrix(ctl->mdl)->pos.x + 400.0f) / 800.0f;
            ctl->zGrid = (mdlGetMatrix(ctl->mdl)->pos.z + 400.0f) / 800.0f;
        }
    }
}

extern f32 func_0052ea18(f32 x, f32 y);

// FUN_001b02c0 NONMATCHING
f32 func_001b02c0(s32 inputIndex, s32 usePad)
{
    f32 horizontal;
    f32 vertical;
    u16 flags;
    s32 offset;
    f32 angle;

    offset = inputIndex * 0x36;
    horizontal = 0.0f;
    vertical = 0.0f;
    flags = *(u16*)(D_007E094C + inputIndex * 0x1b);
    if (usePad == 0)
    {
        vertical = (f32)D_007E095F[offset] - 128.0f;
        if ((flags & 0x1000) != 0)
        {
            vertical = -128.0f;
        }
        else if ((flags & 0x4000) != 0)
        {
            vertical = 128.0f;
        }
        if ((flags & 0xa000) != 0 &&
            vertical >= -48.0f && vertical <= 48.0f)
        {
            vertical = 0.0f;
        }

        horizontal = (f32)D_007E095E[offset] - 128.0f;
        if ((flags & 0x8000) != 0)
        {
            horizontal = -128.0f;
        }
        else if ((flags & 0x2000) != 0)
        {
            horizontal = 128.0f;
        }
        if ((flags & 0x5000) != 0 &&
            horizontal >= -48.0f && horizontal <= 48.0f)
        {
            horizontal = 0.0f;
        }
    }
    else
    {
        vertical = (f32)D_007E0961[offset] - 128.0f;
        if (vertical >= -48.0f && vertical <= 48.0f)
        {
            vertical = 0.0f;
        }
        horizontal = (f32)D_007E0960[offset] - 128.0f;
        if (horizontal >= -48.0f && horizontal <= 48.0f)
        {
            horizontal = 0.0f;
        }
    }

    if (vertical < -48.0f || vertical > 48.0f ||
        horizontal < -48.0f || horizontal > 48.0f)
    {
        angle = func_0052ea18(horizontal, vertical) * 57.2957795f;
        if (horizontal < 0.0f)
        {
            angle = 360.0f - angle;
        }
        angle += 180.0f;
        if (angle > 360.0f)
        {
            angle -= 360.0f;
        }
        return angle;
    }
    return 0.0f;
}