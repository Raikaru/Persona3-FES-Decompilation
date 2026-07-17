#include "Battle/btlCamera.h"
#include "Battle/battle.h"
#include "Battle/btlUnit.h"
#include "Battle/btlBoss.h"
#include "Kosaka/k_view.h"
#include "Kernel/Kwln/kwln.h"
#include "Main/Battle/Data/datUnit.h"
#include "Graphics/primitive.h"
#include "Battle/btlAction.h"

/* Recovered battle-misc support prelude */
typedef int (*code)(...);
u8 FUN_002a32f0(int param_1);
u32 FUN_002a3380(u8* camera);
u32 FUN_002a3420(int param_1);
u8 FUN_002a3520(int param_1);
u64 FUN_002a3550(u8* camera);
u32 FUN_002a3590(float *param_1,long param_2);
s32 FUN_002a3750(BtlCamera* camera,u32 unit);
extern s16 btlUnit00282c30(BtlUnit* unit);
extern s16 func_002835e0(BtlUnit* unit,u16 id,f32 scale);
extern s16 btlUnitGetAnimFrame(BtlUnit* unit);
u8 FUN_002a3820(int param_1);
u32 FUN_002a3850(int param_1);
u16 FUN_002a3a80(void);
void FUN_002a3a90(int param_1);
void FUN_002a3e80(float param_1,u8* param_2,u8* param_3,u8* param_4,u32 param_5);
u64 FUN_0027ffb0();
extern u8* DAT_007ce3ec;
void FUN_002a42a0(void);
void FUN_002a4470(f32 *param_1, f32 *param_2);
void FUN_002a44b0(f32 *param_1, f32 *param_2);
void FUN_002a44f0(f32 *param_1, f32 *param_2);
void FUN_002a4530(float *param_1,float *param_2,float *param_3,float *param_4);
void FUN_002a4690(void* out, const void* first, const void* second, const void* config);
void FUN_002a4a70(void);
void FUN_002a4c20(void);
extern f32 DAT_007cae38;
extern f32 DAT_007caf3c;
extern f32 DAT_007caf40;
extern f32 DAT_007caf44;
extern f32 DAT_007caf48;
extern f32 DAT_007caf4c;
extern f32 DAT_007caf50;
extern f32 DAT_007caf54;
extern code DAT_00960178;
extern code DAT_0096017c;
extern int iGpffffb710;
extern u8* iGpffffb6fc;
extern u8 DAT_006941d4[];
extern u8 DAT_00694c90[];

extern f32 FUN_002d21e0();
extern void FUN_002a3010();
extern void FUN_002a2ed0();
extern void FUN_002a2050();
extern void FUN_002a1e00();

// 006939f0
static const BtlCameraStateEntry sCameraStateEntries[] =
{
    // TODO
    {NULL, NULL, 0, 0, NULL}, // BTLCAMERA_STATE_NULL
    {NULL, NULL, 1, 0, "NOP"}, // BTLCAMERA_STATE_NOP
};

// FUN_002a31b0 NONMATCHING
void btlCameraUpdate(BtlCamera* camera)
{
    f32 step;
    f32* motion;
    u8* cameraBytes;

    if (camera == NULL)
    {
        return;
    }

    cameraBytes = (u8*)camera;
    motion = (f32*)(cameraBytes + 0x84);
    step = 0.0f;
    if ((camera->unk_00 & 2) != 0)
    {
        step = FUN_002d21e0(1.0f, motion);
        if ((camera->unk_00 & 4) != 0)
        {
            step -= *(f32*)(cameraBytes + 0x80);
            *(f32*)(cameraBytes + 0x94) += step;
        }
        else
        {
            step = 0.0f;
        }
    }

    if ((camera->unk_00 & 4) != 0)
    {
        *(f32*)(cameraBytes + 0x80) += step;
    }

}

// FUN_002a38f0 NONMATCHING
void btlCameraSetState(u16 state, BtlAction* action, u32 param_3)
{
    const BtlCameraStateEntry* entry;
    BtlCamera* camera;
    u16 oldState;
    u8* battleBytes;

    camera = &gBtl->camera;
    battleBytes = (u8*)gBtl;
    oldState = camera->state;
    entry = btlBossGetCameraStateEntry(state);
    if (entry == NULL)
    {
        if (state < (u16)(sizeof(sCameraStateEntries) / sizeof(sCameraStateEntries[0])))
        {
            entry = &sCameraStateEntries[state];
        }
        else
        {
            entry = &sCameraStateEntries[0];
        }
    }

    if (oldState != state)
    {
        *(u16*)(battleBytes + 0x102) = oldState;
        *(u16*)(battleBytes + 0x104) = state;
        camera->state = state;
        camera->updateCounter = 0;
        camera->framesUntilUpdate = 0;
        camera->action = action;
    }
    else
    {
        camera->action = action;
    }

    if (entry->unk_0c != 0)
    {
        camera->flags |= BTLCAMERA_FLAG_UNK02;
    }
    else
    {
        camera->flags &= ~3u;
    }

    if (param_3 != 0 && entry->init != NULL)
    {
        entry->init(camera);
    }
}

// FUN_002a3b00
u32 btlCameraUpdateSetStatePacket(void* work)
{
    BtlCameraPacketSetState* packet;

    packet = (BtlCameraPacketSetState*)work;

    btlCameraSetState(packet->state, packet->action, 1);

    return 1;
}

// FUN_002a3b40
BtlPacket* btlCameraCreateSetStatePacket(BtlAction* action, u16 state)
{
    BtlPacket* packet;
    BtlCameraPacketSetState* work;

    packet = btlPacketCreate(BTLCAMERA_PACKET_SETSTATE, sizeof(BtlCameraPacketSetState));

    packet->updateFunc = btlCameraUpdateSetStatePacket;

    work = (BtlCameraPacketSetState*)packet->workData;

    work->action = action;
    work->state = state;

    return packet;
}

// FUN_002a3ba0 NONMATCHING
u32 btlCameraUpdateMoveToPacket(void* work)
{
    BtlCameraPacketMoveTo* packet;
    BtlCamera* camera;
    RwV3d startPos;
    RwV3d startTarget;
    RwV3d endPos;
    RwV3d endTarget;
    RwV3d worldUp;
    RtQuat startRot;
    RtQuat endRot;
    u8* battleBytes;

    packet = (BtlCameraPacketMoveTo*)work;
    camera = &gBtl->camera;
    battleBytes = (u8*)gBtl;

    btlCameraSetState(BTLCAMERA_STATE_NOP, packet->action, 1);

    if (packet->currPosAsStart != 0)
    {
        startTarget = camera->pos;
    }
    else
    {
        startPos = packet->startPos;
        startTarget = packet->startTarget;
    }

    endPos = packet->endPos;
    endTarget = packet->endTarget;
    worldUp.x = 0.0f;
    worldUp.y = 1.0f;
    worldUp.z = 0.0f;


    camera->pos = startPos;
    camera->rot = startRot;
    camera->keyFrames[0].pos = endPos;
    camera->keyFrames[0].rot = endRot;
    camera->keyFrames[1].pos = endTarget;
    camera->keyFrameIdx = 0;
    camera->framesUntilUpdate = 0;
    *(f32*)(battleBytes + 0xa4) = packet->duration * 2.0f;
    camera->fovRad = 0.5f;
    camera->flags = (camera->flags & ~BTLCAMERA_FLAG_FREEZE) | BTLCAMERA_FLAG_UNK02;

    return 1;
}

// FUN_002a3d70
BtlPacket* btlCameraCreateMoveToPacket(BtlAction* action, 
                                       const RwV3d* startPos,
                                       const RwV3d* startTarget,
                                       const RwV3d* endPos,
                                       const RwV3d* endTarget,
                                       f32 duration)
{
    BtlPacket* packet;
    BtlCameraPacketMoveTo* work;

    packet = btlPacketCreate(BTLCAMERA_PACKET_MOVETO, sizeof(BtlCameraPacketMoveTo));

    packet->updateFunc = btlCameraUpdateMoveToPacket;

    work = (BtlCameraPacketMoveTo*)packet->workData;

    work->action = action;
    work->duration = duration;

    if (startPos != NULL && startTarget != NULL)
    {
        work->startPos = *startPos;
        work->startTarget = *startTarget;

        work->currPosAsStart = 0;
    }
    else
    {
        work->currPosAsStart = 1;
    }

    work->endPos = *endPos;
    work->endTarget = *endTarget;

    return packet;
}

// FUN_002a4330
void btlCameraCheckUnitFade()
{
    RwFrame* cameraFrame;
    RwMatrix* cameraMat;
    BtlUnitList* currUnitList;
    BtlUnit* currUnit;
    u16 i;
    RwV3d sphereCenter;
    RwV3d diff;

    cameraFrame = (RwFrame*)kwlnGetMainCamera()->object.object.parent;
    cameraMat = &cameraFrame->modelling;

    // PC and EC
    for (i = 0; i < UNIT_GENUS_PS; i++)
    {
        currUnitList = &gBtl->unitLists[i];
        currUnit = currUnitList->head;

        while (currUnit != NULL)
        {
            if (currUnit->flags3 & BTLUNIT_FLAG3_UNK08)
            {
                btlUnitGetSphereWorldCenter(currUnit, (RwV3d*)&sphereCenter);

                diff.x = cameraMat->pos.x - sphereCenter.x;
                diff.y = cameraMat->pos.y - sphereCenter.y;
                diff.z = cameraMat->pos.z - sphereCenter.z;

                if (RwV3dLength(&diff) <= (currUnit->sphereRadius * currUnit->scale) + 200.0f)
                {
                    btlUnitSetFlags(currUnit, BTLUNIT_FLAG_FADE);
                }
                else
                {
                    btlUnitClearFlags(currUnit, BTLUNIT_FLAG_FADE);
                }
            }

            currUnit = currUnit->next;
        }
    }
}

// FUN_002a46e0
void btlCameraMain()
{
    const BtlCameraStateEntry* entry;
    u16 state;
    RwMatrix mat;

    if (!(gBtl->camera.flags & BTLCAMERA_FLAG_FREEZE))
    {
        if (gBtl->camera.framesUntilUpdate <= 0)
        {
            state = gBtl->camera.state;
            entry = btlBossGetCameraStateEntry(state);
            if (entry == NULL)
            {
                entry = &sCameraStateEntries[state];
            }

            if (entry->update != NULL)
            {
                entry->update(&gBtl->camera);
            }

            btlCameraUpdate(&gBtl->camera);

            gBtl->camera.updateCounter++;
        }
        else
        {
            gBtl->camera.framesUntilUpdate--;
        }

        RtQuatConvertToMatrix(&gBtl->camera.rot, &mat);
        mat.pos = gBtl->camera.pos;

        RwFrameTransform((RwFrame*)kwlnGetMainCamera()->object.object.parent,
                         &mat,
                         rwCOMBINEREPLACE);
        K_View_SetFov(kwlnGetMainCamera(), gRadToDegFactor2 * gBtl->camera.fovRad);
    }

    if (gBtl->camera.flags & BTLCAMERA_FLAG_UNK02)
    {
        btlCameraCheckUnitFade();
    }
}

// FUN_002a48f0
void btlCameraDebugDraw()
{
    RwMatrix axisMat;
    RwRGBA quadCol;

    if (!(gBtl->flags & BTL_FLAG_UNK04) &&
        !(gBtl->flags2 & BTL_FLAG2_UNK04) &&
         (gBtl->flags2 & BTL_FLAG2_UNK08))
    {
        quadCol.r = 255;
        quadCol.g = 255;
        quadCol.b = 0;
        quadCol.a = 255;

        RtQuatConvertToMatrix(&gBtl->camera.rot, &axisMat);
        axisMat.pos = gBtl->camera.pos;

        primQuad3D(&gBtl->camera.pos, &quadCol, 6.0f, 1);
        primAxisLine3D(&axisMat, 150.0f, 1);
    }
}

// FUN_002a4c50
void btlCameraFreeze()
{
    gBtl->camera.flags |= BTLCAMERA_FLAG_FREEZE;
}
extern void FUN_002a2290(u16* camera, RwV3d* first, RwV3d* second, int mode);
extern void FUN_002a3110(f32 param_1, u16* camera);
extern f32 FUN_002d1f30();
extern u64 FUN_00351bb0();
extern u64 FUN_004be310();
extern u64 FUN_004c6b20();
extern f32 FUN_0052e930();
extern void FUN_002b6460();

typedef struct BtlCameraQuatBlend
{
    RtQuat first;
    RtQuat second;
    f32 scalar;
    s32 flag;
} BtlCameraQuatBlend;

// FUN_002a4c70 NONMATCHING
void FUN_002a4c70(f32 param_1, f32 param_2, BtlCamera* camera)
{
    BtlCameraKeyFrame current;
    BtlCameraQuatBlend blend;
    BtlUnit* unit;
    RwV3d worldUp;
    RwV3d positiveZ;
    RwV3d negativeZ;
    RwV3d center;
    RwV3d delta;
    RwV3d pointNear;
    RwV3d pointFar;
    RwV3d candidate;
    RwV3d backward;
    RwV2d horizontal;
    RwV3d target;
    RtQuat targetRot;
    RtQuat blendedRot;
    f32 radius;
    f32 fovDistance;
    f32 halfDistance;
    f32 desiredDistance;
    f32 angle;
    f32 ratio;
    f32 sideOffset;
    f32 scale;
    f32 x;
    f32 xSquared;

    unit = *(BtlUnit**)((u8*)camera->action + 0x30);
    radius = unit->sphereRadius * unit->scale;

    btlUnitGetSphereWorldCenter(unit, &center);

    if (radius < 180.0f)
    {
        current.pos.y += 0.15f * unit->unk_8c * unit->scale;
        fovDistance = (radius * 1.5f) / FUN_0052e930(camera->fovRad * 0.5f);
    }
    else
    {
        current.pos.y += 0.25f * unit->unk_8c * unit->scale;
        fovDistance = (radius * 2.5f) / FUN_0052e930(camera->fovRad * 0.5f);
    }

    delta.x = current.pos.x - center.x;
    delta.y = current.pos.y - center.y;
    delta.z = current.pos.z - center.z;
    halfDistance = RwV3dLength(&delta) * 0.5f;
    desiredDistance = fovDistance;
    if (halfDistance < desiredDistance)
    {
        desiredDistance = halfDistance;
    }

    pointNear.x = center.x + delta.x * (radius * 0.5f);
    pointNear.y = center.y + delta.y * (radius * 0.5f);
    pointNear.z = center.z + delta.z * (radius * 0.5f);
    pointFar.x = center.x + delta.x * desiredDistance;
    pointFar.y = center.y + delta.y * desiredDistance +
                 0.35f * unit->unk_8c * unit->scale;
    pointFar.z = center.z + delta.z * desiredDistance;

    delta.x = pointFar.x - pointNear.x;
    delta.y = pointFar.y - pointNear.y;
    delta.z = pointFar.z - pointNear.z;
    RwV3dNormalize(&delta, &delta);
    candidate.x = pointNear.x + delta.x * desiredDistance;
    candidate.y = pointNear.y + delta.y * desiredDistance;
    candidate.z = pointNear.z + delta.z * desiredDistance;

    worldUp.x = 0.0f;
    worldUp.y = 1.0f;
    worldUp.z = 0.0f;
    positiveZ.x = 0.0f;
    positiveZ.y = 0.0f;
    positiveZ.z = 1.0f;
    negativeZ.x = 0.0f;
    negativeZ.y = 0.0f;
    negativeZ.z = -1.0f;

    angle = FUN_002d1f30(&current.rot, &targetRot);
    param_1 *= 0.0174532923847f;
    if (param_1 < angle)
    {
        u16 cameraMode;

        cameraMode = *(u16*)((u8*)camera + 0xe4);
        if (param_2 * 0.0174532923847f < angle &&
            cameraMode != 2 &&
            cameraMode != 0x23 &&
            cameraMode != 0x1f &&
            cameraMode != 0x1d &&
            cameraMode != 0x1c)
        {
            FUN_002b6460(camera);
            FUN_00351bb0(8);
            return;
        }

        ratio = param_1 / angle;
        FUN_004be310(&current.rot, &targetRot, &blend);
        if (ratio <= 0.0f)
        {
            blendedRot = current.rot;
        }
        else if (ratio >= 1.0f)
        {
            blendedRot = targetRot;
        }
        else
        {
            f32 firstWeight;
            f32 secondWeight;

            firstWeight = 1.0f - ratio;
            secondWeight = ratio;
            if (blend.flag == 0)
            {
                x = firstWeight * blend.scalar;
                xSquared = x * x;
                firstWeight = xSquared * x *
                    (xSquared * (xSquared *
                    (xSquared * (xSquared *
                    (1.58969101771e-10f * xSquared - 2.50507596888e-8f) +
                     2.75573142972e-6f) - 1.98412701138e-4f) +
                     0.00833333376795f) - 0.166666671634f) + x;

                x = secondWeight * blend.scalar;
                xSquared = x * x;
                secondWeight = xSquared * x *
                    (xSquared * (xSquared *
                    (xSquared * (xSquared *
                    (1.58969101771e-10f * xSquared - 2.50507596888e-8f) +
                     2.75573142972e-6f) - 1.98412701138e-4f) +
                     0.00833333376795f) - 0.166666671634f) + x;
            }

            blendedRot.imag.x = blend.first.imag.x * firstWeight +
                                blend.second.imag.x * secondWeight;
            blendedRot.imag.y = blend.first.imag.y * firstWeight +
                                blend.second.imag.y * secondWeight;
            blendedRot.imag.z = blend.first.imag.z * firstWeight +
                                blend.second.imag.z * secondWeight;
            blendedRot.real = blend.first.real * firstWeight +
                              blend.second.real * secondWeight;
        }

        RtQuatTransformVectors(&backward, &negativeZ, 1, &blendedRot);
        candidate.x = pointNear.x + backward.x;
        candidate.y = pointNear.y + backward.y;
        candidate.z = pointNear.z + backward.z;
    }

    if (halfDistance < 600.0f)
    {
        halfDistance = 600.0f;
    }
    RtQuatTransformVectors(&backward, &negativeZ, 1, &targetRot);
    backward.x *= halfDistance;
    backward.y *= halfDistance;
    backward.z *= halfDistance;

    sideOffset = halfDistance *
                 FUN_0052e930(1.2f * 0.5f * camera->fovRad) *
                 0.21875f;
    horizontal.x = backward.x;
    horizontal.y = backward.z;
    FUN_004c6b20(&horizontal, &horizontal);
    pointNear.x += horizontal.y * sideOffset;
    pointNear.z -= horizontal.x * sideOffset;

    target.x = pointNear.x + backward.x;
    target.y = pointNear.y + backward.y;
    target.z = pointNear.z + backward.z;
    if (current.pos.y < 100.0f)
    {
        current.pos.y = 100.0f;
    }
    if (target.y < 100.0f)
    {
        target.y = 100.0f;
    }

    angle = FUN_002d1f30(&current.rot, &targetRot);
    scale = 2.0f;
    if (angle > 0.0f)
    {
        ratio = param_1 / angle;
        if (ratio > 1.0f)
        {
            scale = ratio * 1.25f;
        }
        else
        {
            scale = 1.25f;
        }
        if (scale > 2.0f)
        {
            scale = 2.0f;
        }
    }

}

// FUN_002A5430
void FUN_002a5430(BtlCamera* camera)
{
    FUN_002a4c70(45.0f, 200.0f, camera);
}

// FUN_002a5460 NONMATCHING
void FUN_002a5460(BtlCamera* camera)
{
    BtlAction* action;
    BtlUnit* unit;
    RwV3d center;

    action = camera->action;
    if (action != NULL &&
        (*(u16*)((u8*)action + 0x1a) & 1) != 0)
    {
        unit = *(BtlUnit**)((u8*)action + 0x30);
        btlUnitGetSphereWorldCenter(unit, &center);
        FUN_002a3e80(unit->sphereRadius * unit->scale * 0.5f,
                     (u8*)action,
                     (u8*)((u8*)camera + 0x9c),
                     (u8*)&center,
                     0x31);
    }
}

/* Retail camera callbacks for the 0x2A4C70-0x2A95D0 window.  The original
 * routines share the same unit framing and look-at path; the callbacks keep
 * that state typed while remaining NONMATCHING until instruction scheduling
 * is tuned against the retail object. */
static BtlUnit* btlCameraRangeUnit(BtlCamera* camera)
{
    if (camera == NULL || camera->action == NULL)
    {
        return NULL;
    }
    return camera->action->unit;
}

static BtlUnit* btlCameraRangeTarget(BtlCamera* camera)
{
    BtlAction* target;
    if (camera == NULL || camera->action == NULL)
    {
        return NULL;
    }
    target = camera->action->target.targetedActions[0];
    return target != NULL ? target->unit : NULL;
}

static void btlCameraRangeCross(RwV3d* out, const RwV3d* a, const RwV3d* b)
{
    out->x = a->y * b->z - a->z * b->y;
    out->y = a->z * b->x - a->x * b->z;
    out->z = a->x * b->y - a->y * b->x;
}

static void btlCameraRangeLookAt(BtlCamera* camera, const RwV3d* eye,
                                 const RwV3d* target)
{
    RwV3d at;
    RwV3d upAxis;
    RwV3d right;
    RwV3d up;
    RwMatrix matrix;

    at.x = target->x - eye->x;
    at.y = target->y - eye->y;
    at.z = target->z - eye->z;
    if (RwV3dNormalize(&at, &at) <= 0.0001f)
    {
        at.x = 0.0f;
        at.y = 0.0f;
        at.z = 1.0f;
    }
    upAxis.x = 0.0f;
    upAxis.y = 1.0f;
    upAxis.z = 0.0f;
    btlCameraRangeCross(&right, &upAxis, &at);
    if (RwV3dNormalize(&right, &right) <= 0.0001f)
    {
        upAxis.x = 0.0f;
        upAxis.y = 0.0f;
        upAxis.z = 1.0f;
        btlCameraRangeCross(&right, &upAxis, &at);
        RwV3dNormalize(&right, &right);
    }
    btlCameraRangeCross(&up, &at, &right);
    RwV3dNormalize(&up, &up);
    matrix.right = right;
    matrix.up = up;
    matrix.at = at;
    matrix.pos = *eye;
    matrix.pad1 = matrix.pad2 = matrix.pad3 = 0;
    rwMatrixSetFlags(&matrix, rwMATRIXTYPEORTHONORMAL);
    camera->pos = *eye;
    RtQuatConvertFromMatrix(&camera->rot, &matrix);
}

static void btlCameraRangeFrame(BtlCamera* camera, const RwV3d* first,
                                const RwV3d* second, f32 margin, f32 minimum)
{
    RwV3d center;
    RwV3d delta;
    RwV3d direction;
    RwV3d eye;
    f32 radius;
    f32 distance;

    if (camera == NULL || first == NULL)
    {
        return;
    }
    if (second != NULL)
    {
        center.x = (first->x + second->x) * 0.5f;
        center.y = (first->y + second->y) * 0.5f;
        center.z = (first->z + second->z) * 0.5f;
        delta.x = second->x - first->x;
        delta.y = second->y - first->y;
        delta.z = second->z - first->z;
        radius = RwV3dLength(&delta) * 0.5f;
    }
    else
    {
        center = *first;
        radius = 0.0f;
    }
    radius += 100.0f;
    distance = radius * (margin < 1.0f ? 1.0f : margin);
    if (distance < minimum)
    {
        distance = minimum;
    }
    direction.x = camera->pos.x - center.x;
    direction.y = camera->pos.y - center.y;
    direction.z = camera->pos.z - center.z;
    if (RwV3dNormalize(&direction, &direction) <= 0.0001f)
    {
        direction.x = 0.0f;
        direction.y = 0.25f;
        direction.z = 1.0f;
        RwV3dNormalize(&direction, &direction);
    }
    eye.x = center.x + direction.x * distance;
    eye.y = center.y + direction.y * distance;
    eye.z = center.z + direction.z * distance;
    btlCameraRangeLookAt(camera, &eye, &center);
    camera->keyFrameIdx = 0;
    camera->keyFrames[0].pos = eye;
    camera->keyFrames[0].rot = camera->rot;
    camera->framesUntilUpdate = 0;
    if (camera->fovRad <= 0.01f)
    {
        camera->fovRad = 0.7853982f;
    }
}

static void btlCameraRangeActionFrame(BtlCamera* camera, f32 margin,
                                      f32 minimum, u32 includeTarget)
{
    BtlUnit* unit;
    BtlUnit* target;
    RwV3d first;
    RwV3d second;

    unit = btlCameraRangeUnit(camera);
    if (unit == NULL)
    {
        return;
    }
    btlUnitGetSphereWorldCenter(unit, (RwV3d*)&first);
    target = includeTarget != 0 ? btlCameraRangeTarget(camera) : NULL;
    if (target != NULL && target != unit)
    {
        btlUnitGetSphereWorldCenter(target, (RwV3d*)&second);
        btlCameraRangeFrame(camera, &first, &second, margin, minimum);
    }
    else
    {
        btlCameraRangeFrame(camera, &first, NULL, margin, minimum);
    }
}


// FUN_002a54f0 NONMATCHING
void btlCameraFrameAction(BtlCamera* camera, u32 closeView, s32 nearScale, s32 farScale)
{
    btlCameraRangeActionFrame(camera, closeView != 0 ? 1.5f : 2.0f,
                              (f32)nearScale * (closeView != 0 ? 2.0f : 4.0f),
                              1);
    (void)farScale;
}

// FUN_002a5ee0
void btlCameraFrameActionDefault(BtlCamera* camera)
{
    u32 closeView;

    switch (*(u16 *)(DAT_007ce3ec + 0x104))
    {
    case 0x1d:
        closeView = 1;
        break;
    default:
        closeView = 0;
        break;
    }
    btlCameraFrameAction(camera, closeView, 40, 70);
}

// FUN_002a5f40
void btlCameraFrameActionClose(BtlCamera* camera)
{
    int cameraAddress;
    int actionAddress;
    BtlUnit* unit;
    RwV3d center;

    cameraAddress = (int)camera;
    actionAddress = *(int *)(cameraAddress + 0xe0);
    if (actionAddress != 0 && (*(u16 *)(actionAddress + 0x1a) & 1) != 0)
    {
        unit = *(BtlUnit **)(actionAddress + 0x30);
        FUN_0027ffb0(unit, &center);
        FUN_002a3e80(unit->sphereRadius * unit->scale * 0.25f,
                     (u8 *)(uintptr_t)*(u32 *)(cameraAddress + 0xe0),
                     (u8 *)(uintptr_t)(cameraAddress + 0x9c), (u8 *)&center, 0x31);
    }
}

// FUN_002a5fd0 NONMATCHING
void btlCameraFrameActionPair(BtlCamera* camera)
{
    btlCameraRangeActionFrame(camera, 2.0f, 300.0f, 1);
}

// FUN_002a6560
void btlCameraFrameActionQuarter(BtlCamera* camera)
{
    int cameraAddress;
    int actionAddress;
    BtlUnit* unit;
    RwV3d center;

    cameraAddress = (int)camera;
    actionAddress = *(int *)(cameraAddress + 0xe0);
    if (actionAddress != 0 && (*(u16 *)(actionAddress + 0x1a) & 1) != 0)
    {
        unit = *(BtlUnit **)(actionAddress + 0x30);
        FUN_0027ffb0(unit, &center);
        FUN_002a3e80(unit->sphereRadius * unit->scale * 0.25f,
                     (u8 *)(uintptr_t)*(u32 *)(cameraAddress + 0xe0),
                     (u8 *)(uintptr_t)(cameraAddress + 0x9c), (u8 *)&center, 0x33);
    }
}

// FUN_002a65f0 NONMATCHING
void btlCameraFrameActionDuel(BtlCamera* camera)
{
    btlCameraRangeActionFrame(camera, 2.5f, 450.0f, 1);
}

// FUN_002a6ee0 NONMATCHING
void btlCameraFrameActionSide(BtlCamera* camera)
{
    btlCameraRangeActionFrame(camera, 2.5f, 500.0f, 1);
}

// FUN_002a7390 NONMATCHING
void btlCameraFrameActionTarget(BtlCamera* camera)
{
    btlCameraRangeActionFrame(camera, 1.5f, 375.0f, 0);
}

// FUN_002a7830 NONMATCHING
u32 btlCameraSelectMode(BtlCamera* camera)
{
    BtlUnit* unit;
    BtlUnit* target;
    unit = btlCameraRangeUnit(camera);
    target = btlCameraRangeTarget(camera);
    if (unit == NULL)
    {
        return 0;
    }
    if (target == NULL || target == unit)
    {
        return 1;
    }
    if (unit->personaUnit != NULL)
    {
        return 4;
    }
    return target->genus == UNIT_GENUS_PS ? 2 : 3;
}

// FUN_002a79f0 NONMATCHING
void btlCameraFrameActionTargeting(BtlCamera* camera)
{
    btlCameraRangeActionFrame(camera, 1.75f, 500.0f, 1);
}

// FUN_002a8150 NONMATCHING
void btlCameraFrameActionPersona(BtlCamera* camera, u32 suppressEffects,
                                 u32 useCurrentTarget)
{
    btlCameraRangeActionFrame(camera, 2.0f, 450.0f, useCurrentTarget != 0);
    if (suppressEffects == 0 && camera != NULL)
    {
        camera->framesUntilUpdate = 0;
    }
}

// FUN_002a8d20 NONMATCHING
void btlCameraFrameActionAll(BtlCamera* camera, u32 suppressEffects)
{
    btlCameraRangeActionFrame(camera, 2.0f, 450.0f, 1);
    if (suppressEffects == 0 && camera != NULL)
    {
        camera->framesUntilUpdate = 0;
    }
}

// FUN_002a95d0 NONMATCHING
void btlCameraFrameActionResult(BtlCamera* camera, u32 suppressEffects,
                                u32 useCurrentTarget)
{
    btlCameraRangeActionFrame(camera, 2.0f, 375.0f, useCurrentTarget != 0);
    if (suppressEffects == 0 && camera != NULL)
    {
        camera->framesUntilUpdate = 0;
    }
}



/* Retail camera recovery for the 0x2b02xx-0x2b8cxx slice.  The bodies below
 * retain the complete branch/data flow recovered from the executable; all
 * entries remain NONMATCHING until instruction scheduling is cleaned up. */
typedef u8 undefined1;
typedef u16 undefined2;
typedef u32 undefined4;
typedef u64 undefined8;
typedef void undefined;

#ifndef CONCAT44
#define CONCAT44(hi, lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif
#ifndef ABS
#define ABS(x) ((x) < 0 ? -(x) : (x))
#endif
extern u64 FUN_0019d400();
extern u32 FUN_0027ec10();
extern u64 FUN_0027f650();
extern u64 FUN_0027f680();
extern u64 FUN_0027f7c0();
extern u64 FUN_0027f940();
extern u64 FUN_00280050();
extern u64 FUN_00280130();
extern u64 FUN_00280200();
extern u64 FUN_002802d0();
extern u64 FUN_00280390();
extern float FUN_00280870();
extern u64 FUN_00281270();
extern u64 FUN_00281290();
extern u64 FUN_002812b0();
extern s16 FUN_002835e0(BtlUnit* unit, u16 id, f32 scale);
extern s16 FUN_00284040();
extern u64 FUN_00288110();
extern u64 FUN_00288da0();
extern u64 FUN_0029a1d0();
extern u64 FUN_002a2170();
extern u64 FUN_002a2660();
extern u64 FUN_002add10();
extern u64 FUN_002d1600();
extern u64 FUN_002d1de0();
extern float FUN_002d1f30();
extern float FUN_002d1fd0();
extern u64 FUN_002d2280();
extern u64 FUN_002d4040();
extern u64 FUN_002d4e10();
extern u64 FUN_002d5bf0();
extern u64 FUN_002d6290();
extern u64 FUN_002d6370();
extern u64 FUN_002d63b0();
extern s16 FUN_002f8eb0(BtlUnit* unit, s16 index);
extern u64 FUN_002fa240();
extern u64 FUN_002fdcf0();
extern u64 FUN_002ffbc0();
extern u64 FUN_00300580();
extern u64 FUN_00308c60();
extern u64 FUN_00308a50(u16 param_1);
extern u64 FUN_003093a0();
extern u64 FUN_0030b5a0();
extern u64 FUN_0030c3a0();
extern u64 FUN_00351bb0();
extern u64 FUN_004bdde0();
extern u64 FUN_004be1e0();
extern u64 FUN_004be310();
extern u64 FUN_004c31b0();
extern float FUN_004c69f0();
extern float FUN_004c6ac0();
extern float FUN_004c6af0();
extern u64 FUN_004c6b20();
extern u64 FUN_004c6c60();
extern u64 FUN_00521250();
extern u64 FUN_00521408();
extern u64 FUN_00523ac8();
extern float FUN_0052e930();
extern u32 DAT_007ce404;
extern u8* iGpffffb6fc;
extern void LAB_002b8970(u32 *work);
extern void LAB_002b8b50(u32 *work);
extern u8 DAT_006944b0[];
extern u8 DAT_006945b0[];
extern u8 DAT_006946a4[];
extern u8 DAT_00694798[];
extern u8 DAT_00694890[];
extern u8 DAT_00694990[];
extern u8 DAT_00694a90[];
extern u8 DAT_00694b90[];
extern u8 DAT_00694c90[];
extern u8 DAT_00694d90[];
extern RwV3d D_00694E90;
extern RwV3d D_00694E9C;
extern RwV3d D_00694EA0;
extern RwV3d D_00694EA4;
extern RwV3d D_00694ED0;
extern RwV3d D_00694ED4;
extern RwV3d D_00694ED8;
extern RwV3d D_00694EDC;
extern RwV3d D_00694EE0;
extern RwV3d D_00694EE4;
extern u8 DAT_00694fe8;
extern u8 DAT_00694fea;
extern u8 DAT_00694fec;
extern u32 DAT_00697880;
extern RwV3d D_00697880;
extern u32 DAT_00697888;
extern float DAT_007cad20;
extern float DAT_007cad38;
extern float DAT_007cad40;
extern float DAT_007cad44;
extern float DAT_007cad48;
extern float DAT_007cad5c;
extern float DAT_007cad60;
extern float DAT_007cad64;
extern float DAT_007cad68;
extern float DAT_007cad6c;
extern float DAT_007cad74;
extern float DAT_007cad7c;
extern float DAT_007cad84;
extern float DAT_007cad88;
extern float DAT_007cad94;
extern float DAT_007cada4;
extern float DAT_007cadb4;
extern float DAT_007cadc4;
extern float DAT_007cadd0;
extern float DAT_007cadf0;
extern float DAT_007cadf4;
extern float DAT_007cae08;
extern float DAT_007cae20;
extern float DAT_007cae2c;
extern float fGpffff8048;
extern float fGpffff8050;
extern float fGpffff8054;
extern float fGpffff8058;
extern float fGpffff806c;
extern float fGpffff8070;
extern float fGpffff8088;
extern float fGpffff8094;
extern float fGpffff8098;
extern float fGpffff809c;
extern float fGpffff80b4;
extern float fGpffff80c4;
extern float fGpffff80d4;
extern float fGpffff8114;
extern float fGpffff8118;
extern u32 uGpffff808c;
extern u32 uGpffff80fc;
extern u32 uGpffff8100;
extern u32 uGpffff8140;
extern f32 fGpffff80e0;
extern f32 fGpffff813c;
extern u8 D_00694EB0[];
extern u8 D_00694EBC[];
extern u8 D_00694EF0[];
extern u8 D_00694EFC[];
extern u32 FUN_002b64d0(int param_1, int param_2);
extern u32 FUN_002b6bd0(int param_1);
extern void FUN_002b6bf0(undefined4 *param_1, undefined4 param_2, undefined4 param_3, u32 param_4, u32 param_5);
extern u8* FUN_002b6cd0(int param_1);
extern void FUN_002b6de0(unsigned short *param_1);
// FUN_002B0210
void FUN_002b0210(int param_1)
{
  int iVar1;
  
  iVar1 = param_1;
  param_1 = *(int *)(param_1 + 0xe0);
  if ((((param_1 != 0) && (*(u16 *)(param_1 + 0x6a) == 1)) &&
      (*(int *)(iVar1 + 0x118) == *(int *)(param_1 + 0x38))) &&
     ((*(u16 *)(param_1 + 0x1a) & 1) != 0)) {
    FUN_002a3e80(*(float *)(iVar1 + 0x10c), (u8 *)(uintptr_t)param_1,
                 (u8 *)(uintptr_t)(iVar1 + 0x9c),
                 (u8 *)(uintptr_t)(iVar1 + 0x100), 0x33);
  }
  return;
}

// FUN_002b0280 NONMATCHING

void FUN_002b0280(float param_1,undefined8 param_2,long param_3,long param_4)

{
  int iVar1;
  char cVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  undefined4 uStack_78;
  float fStack_74;
  undefined8 uStack_70;
  float fStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  undefined8 uStack_30;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar4 = (int)param_2;
  iVar6 = *(int *)(*(int *)(iVar4 + 0xe0) + 0x30);
  iVar1 = *(int *)(*(int *)(*(int *)(iVar4 + 0xe0) + 0x38) + 0x30);
  FUN_0027ffb0(iVar6,&fStack_10);
  FUN_0027ffb0(iVar1,&fStack_20);
  fVar7 = *(float *)(iVar1 + 0x8c);
  fVar9 = *(float *)(iVar1 + 0x2c);
  fVar16 = fStack_1c + 0.0;
  if (fStack_1c < 125.0) {
    fStack_1c = 125.0;
  }
  fVar13 = *(float *)(iVar6 + 0x90) * *(float *)(iVar6 + 0x2c);
  fVar11 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
  fStack_50 = fStack_10 - fStack_20;
  fStack_4c = fStack_c - fStack_1c;
  fStack_48 = fStack_8 - fStack_18;
  fVar10 = (float)FUN_004c69f0(&fStack_50,&fStack_50);
  fVar8 = DAT_007cad88 * fVar10;
  fStack_40 = fStack_50 * fVar8 + fStack_20;
  fStack_3c = fStack_4c * fVar8 + fStack_1c;
  fStack_38 = fStack_48 * fVar8 + fStack_18;
  fStack_98 = *(float *)(iVar4 + 0x9c) - fStack_40;
  fStack_94 = *(float *)(iVar4 + 0xa4) - fStack_38;
  FUN_004c6b20(&fStack_98,&fStack_98);
  fVar8 = fStack_1c;
  fStack_a0 = fStack_50;
  fStack_9c = fStack_48;
  fVar12 = fStack_50 * fStack_98 + fStack_48 * fStack_94;
  if (((fVar12 < 0.0) && (param_4 != 1)) || (param_3 != 0)) {
    fVar10 = fVar10 * 0.5;
    fStack_40 = fStack_50 * fVar10 + fStack_20;
    fStack_3c = fStack_4c * fVar10 + fStack_1c;
    fStack_38 = fStack_48 * fVar10 + fStack_18;
    uStack_30 = CONCAT44(fStack_1c,fStack_20);
    fStack_28 = fStack_18;
    fVar7 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) * 1.25;
    fStack_a0 = fStack_48;
    fStack_9c = -fStack_50;
    fVar9 = fStack_48 * fStack_98 + fStack_9c * fStack_94;
    fStack_5c = fStack_1c;
    if (fStack_1c < fStack_c) {
      fStack_5c = fStack_c;
    }
    if (0.0 <= fVar9) {
      fStack_60 = fStack_48 * fVar7 + fStack_20 + 0.0;
      fStack_58 = (fStack_18 + 0.0) - fStack_50 * fVar7;
      uStack_70 = CONCAT44(fStack_4c,fStack_50);
      fStack_68 = fStack_48;
    }
    else {
      fStack_60 = (fStack_20 + 0.0) - fStack_48 * fVar7;
      fStack_58 = fStack_50 * fVar7 + fStack_18 + 0.0;
    }
    fVar10 = fStack_18;
    FUN_004be1e0(&fStack_50,0x6978a0,1,&uStack_b8);
    fStack_90 = fStack_40;
    fStack_8c = fStack_38;
    fStack_88 = fStack_60;
    fStack_84 = fStack_58;
    uStack_78 = (float)uStack_30;
    fStack_74 = fVar10;
    fVar16 = (float)FUN_002d1fd0(&fStack_90,&fStack_88,&uStack_78,&fStack_80);
    fVar7 = DAT_007cad60;
    fVar14 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) * 1.5 + fVar16 + 0.0;
    fStack_60 = fStack_80;
    fStack_5c = fVar8;
    fStack_58 = fStack_7c;
    fVar15 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar4 + 0xb8) * 0.5);
    fVar16 = 550.0;
    if (550.0 <= fVar14 / fVar15) {
      fVar16 = fVar14 / fVar15;
    }
    fStack_50 = fStack_50 * fVar16;
    fStack_4c = fStack_4c * fVar16;
    fStack_48 = fStack_48 * fVar16;
    if (0.0 <= fVar9) {
      fVar16 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) * 0.5;
      fStack_60 = (fStack_60 + 0.0) - fStack_68 * fVar16;
      fStack_58 = (float)uStack_70 * fVar16 + fStack_58 + 0.0;
    }
    fStack_c4 = fStack_60 + fStack_50;
    fStack_c0 = fStack_5c + fStack_4c;
    fStack_bc = fStack_58 + fStack_48;
    iVar5 = iVar1;
  }
  else {
    uStack_30 = CONCAT44(fStack_c,fStack_10);
    fStack_28 = fStack_8;
    fVar10 = *(float *)(iVar6 + 0x90) * *(float *)(iVar6 + 0x2c) * 2.5;
    if ((((*(char *)(iVar6 + 0xa2) == '\0') &&
         ((*(short *)(iVar6 + 0xa4) == 3 || (lVar3 = FUN_002d5bf0(iVar6), lVar3 != 0)))) &&
        (cVar2 = FUN_003093a0(*(undefined4 *)(iVar6 + 0xa2c)), cVar2 == '\x02')) &&
       (lVar3 = FUN_002a32f0(param_2), lVar3 == 0)) {
      fVar15 = 85.0;
    }
    else {
      fVar15 = 0.0;
    }
    if (fVar7 * fVar9 * 0.5 + fVar16 <= 400.0) {
      fStack_3c = DAT_007cad7c * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) +
                  fStack_3c + 0.0;
    }
    else {
      fStack_3c = DAT_007cad5c * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) +
                  fStack_3c + 0.0;
    }
    fStack_a0 = fStack_48;
    fStack_9c = -fStack_50;
    fVar9 = fStack_48 * fStack_98 + fStack_9c * fStack_94;
    fVar8 = (float)(uStack_30 >> 32);
    fVar15 = fVar15 + (float)(uStack_30 >> 32);
    fStack_5c = *(float *)(iVar6 + 0x8c) * *(float *)(iVar6 + 0x2c) * 0.5 + fVar15 + 0.0;
    if (0.0 <= fVar9) {
      fStack_60 = fStack_48 * fVar10 + (float)uStack_30 + 0.0;
      fStack_58 = (fStack_28 + 0.0) - fStack_50 * fVar10;
    }
    else {
      fStack_60 = ((float)uStack_30 + 0.0) - fStack_48 * fVar10;
      fStack_58 = fStack_50 * fVar10 + fStack_28 + 0.0;
      uStack_70 = CONCAT44(fStack_4c,fStack_50);
      fStack_68 = fStack_48;
    }
    fVar10 = fStack_28;
    FUN_004be1e0(&fStack_50,0x6978a0,1,&uStack_b8);
    fStack_90 = fStack_40;
    fStack_8c = fStack_38;
    fStack_88 = fStack_60;
    fStack_84 = fStack_58;
    uStack_78 = (float)uStack_30;
    fStack_74 = fVar10;
    fVar16 = (float)FUN_002d1fd0(&fStack_90,&fStack_88,&uStack_78,&fStack_80);
    fVar7 = DAT_007cad60;
    fVar16 = *(float *)(iVar6 + 0x90) * *(float *)(iVar6 + 0x2c) * 2.0 + fVar16 + 0.0;
    fStack_60 = fStack_80;
    fStack_5c = *(float *)(iVar6 + 0x8c) * *(float *)(iVar6 + 0x2c) * 0.25 + fVar15 + 0.0;
    fStack_58 = fStack_7c;
    fVar15 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar4 + 0xb8) * 0.5);
    fVar16 = fVar16 / fVar15;
    fStack_50 = fStack_50 * fVar16;
    fStack_4c = fStack_4c * fVar16;
    fStack_48 = fStack_48 * fVar16;
    if (fVar9 < 0.0) {
      fVar16 = *(float *)(iVar6 + 0x90) * *(float *)(iVar6 + 0x2c) * 2.0;
      fStack_60 = fStack_68 * fVar16 + fStack_60 + 0.0;
      fStack_58 = (fStack_58 + 0.0) - (float)uStack_70 * fVar16;
    }
    fStack_c4 = fStack_60 + fStack_50;
    fStack_c0 = fStack_5c + fStack_4c;
    fStack_bc = fStack_58 + fStack_48;
    iVar5 = iVar6;
    iVar6 = iVar1;
  }
  fVar16 = (float)FUN_002d1f30(&uStack_d4,&uStack_b8);
  if ((param_1 <= 0.0) || (param_1 = DAT_007cadf4 * param_1, param_1 < fVar16)) {
    if (fVar12 < 0.0) {
      FUN_004be1e0(&fStack_50,0x6978a0,1,&uStack_b8);
      fStack_50 = fStack_50 * 200.0;
      fStack_4c = fStack_4c * 200.0;
      fStack_48 = fStack_48 * 200.0;
      fStack_e0 = fStack_c4 + fStack_50;
      fStack_dc = fStack_c0 + fStack_4c;
      fStack_d8 = fStack_bc + fStack_48;
      uStack_d4 = uStack_b8;
      uStack_d0 = uStack_b4;
      uStack_cc = uStack_b0;
      uStack_c8 = uStack_ac;
      if (fStack_dc < 25.0) {
        fStack_dc = 25.0;
      }
      if (fStack_c0 < 25.0) {
        fStack_c0 = 25.0;
      }
    }
    else {
      fVar16 = *(float *)(iVar5 + 0x90) * *(float *)(iVar5 + 0x2c);
      fStack_50 = fStack_10 - fStack_20;
      fStack_4c = fStack_c - fStack_1c;
      fStack_48 = fStack_8 - fStack_18;
      FUN_004c69f0(&fStack_50,&fStack_50);
      fStack_5c = DAT_007cadb4 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) + fVar8 + 0.0;
      if (0.0 <= fVar9) {
        fStack_60 = ((float)uStack_30 + 0.0) - fStack_48 * fVar16;
        fStack_58 = fStack_50 * fVar16 + fVar10 + 0.0;
      }
      else {
        fStack_60 = fStack_48 * fVar16 + (float)uStack_30 + 0.0;
        fStack_58 = (fVar10 + 0.0) - fStack_50 * fVar16;
      }
      FUN_004be1e0(&fStack_50,0x6978a0,1,&uStack_d4);
      fStack_90 = fStack_40;
      fStack_8c = fStack_38;
      fStack_88 = fStack_60;
      fStack_84 = fStack_58;
      uStack_78 = (float)uStack_30;
      fStack_74 = fVar10;
      FUN_002d1fd0(&fStack_90,&fStack_88,&uStack_78,&fStack_80);
      fStack_60 = fStack_80;
      fStack_5c = DAT_007cadb4 * *(float *)(iVar5 + 0x8c) * *(float *)(iVar5 + 0x2c) + fVar8 + 0.0;
      fStack_58 = fStack_7c;
      fVar7 = (float)FUN_0052e930(fVar7 * *(float *)(iVar4 + 0xb8) * 0.5);
      fVar7 = (*(float *)(iVar5 + 0x90) * *(float *)(iVar5 + 0x2c) * 4.0) / fVar7;
      fStack_50 = fStack_50 * fVar7;
      fStack_4c = fStack_4c * fVar7;
      fStack_48 = fStack_48 * fVar7;
      fStack_e0 = fStack_60 + fStack_50;
      fStack_dc = fStack_5c + fStack_4c;
      fStack_d8 = fStack_58 + fStack_48;
      if (fStack_dc < 25.0) {
        fStack_dc = 25.0;
      }
      if (fStack_c0 < 25.0) {
        fStack_c0 = 25.0;
      }
    }
    if (fVar13 <= fVar11) {
      fVar13 = fVar11;
    }
  }
  else {
    if (fVar13 <= fVar11) {
      fVar13 = fVar11;
    }
    if (fStack_dc < 25.0) {
      fStack_dc = 25.0;
    }
    if (fStack_c0 < 25.0) {
      fStack_c0 = 25.0;
    }
    fVar9 = (float)FUN_002d1f30(&uStack_d4,&uStack_b8);
    fVar7 = 1.25;
    if (0.0 < fVar9) {
      param_1 = param_1 / fVar9;
      fVar7 = DAT_007cad94;
      if (1.0 < param_1) {
        fVar7 = param_1 * DAT_007cad94;
      }
      if (1.25 < fVar7) {
        fVar7 = 1.25;
      }
    }
  }
  return;
}

// FUN_002b1020

void FUN_002b1020(undefined8 param_1)

{
  FUN_002b0280(50.0f,param_1,0,0);
  return;
}

// FUN_002b1050
void btlCameraNoOp(void)
{
}

// FUN_002b1060 NONMATCHING

void FUN_002b1060(float param_1, undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  undefined1 auStack_134 [16];
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined1 auStack_100 [64];
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  undefined4 uStack_78;
  float fStack_74;
  float fStack_70;
  undefined8 uStack_68;
  float fStack_60;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_8;
  float fStack_4;
  
  iVar3 = (int)(DAT_007ce3ec + 0x20);
  iVar1 = *(int *)(*(int *)(iVar3 + 0xe0) + 0x30);
  iVar2 = *(int *)(*(int *)(*(int *)(iVar3 + 0xe0) + 0x38) + 0x30);
  uStack_78 = *(undefined4 *)(iVar1 + 0xdc);
  fStack_74 = *(float *)(iVar1 + 0x84) * *(float *)(iVar1 + 0x2c);
  fStack_70 = *(float *)(iVar1 + 0xe4);
  FUN_0027ffb0(iVar2,&fStack_88);
  fVar8 = fStack_74 + 0.0;
  fVar5 = fGpffff8094 * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c);
  fVar9 = fStack_84 + 0.0;
  fVar6 = fGpffff8094 * *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c);
  fVar7 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c) +
          *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) + *(float *)(iVar1 + 0xe8) + 0.0;
  fStack_84 = 0.0;
  fStack_74 = 0.0;
  fStack_38 = *(float *)(iVar1 + 0xdc) - fStack_88;
  fStack_34 = *(float *)(iVar1 + 0xe0) - 0.0;
  fStack_30 = *(float *)(iVar1 + 0xe4) - fStack_80;
  FUN_004c69f0(&fStack_38,&fStack_38);
  fStack_58 = fStack_38 * fVar7 * 0.25 + fStack_88;
  fStack_50 = fStack_30 * fVar7 * 0.25 + fStack_80;
  fVar5 = (fVar5 + fVar8 + fVar6 + fVar9) * 0.5;
  *(float *)(iVar3 + 0x10c) = *(float *)(iVar1 + 0xe8) * 0.5;
  *(float *)(iVar3 + 0x100) = fStack_58;
  *(float *)(iVar3 + 0x104) = fVar5;
  *(float *)(iVar3 + 0x108) = fStack_50;
  fStack_a0 = fStack_30;
  fStack_9c = -fStack_38;
  fStack_98 = fStack_140 - fStack_58;
  fStack_94 = fStack_138 - fStack_50;
  fStack_54 = fVar5;
  FUN_004c6b20(&fStack_a0,&fStack_a0);
  FUN_004c6b20(&fStack_98,&fStack_98);
  fStack_28 = fStack_140 - fStack_58;
  fStack_24 = fStack_13c - fStack_54;
  fStack_20 = fStack_138 - fStack_50;
  if (0.0 <= fStack_a0 * fStack_98 + fStack_9c * fStack_94) {
    FUN_004c31b0(param_1,auStack_100,0x697880,0);
  }
  else {
    FUN_004c31b0(-param_1,auStack_100,0x697880,0);
  }
  FUN_004c6c60(&fStack_28,&fStack_28,auStack_100);
  fStack_28 = fStack_28 + fStack_58;
  fStack_24 = fStack_24 + fStack_54;
  fStack_20 = fStack_20 + fStack_50;
  fVar6 = 400.0;
  if (400.0 <= fVar7) {
    fVar6 = fVar7;
  }
  fVar7 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar3 + 0xb8) * 0.5);
  fVar7 = (fVar6 * 0.5) / fVar7;
  FUN_004be1e0(&fStack_28,0x6978a0,1,&uStack_118);
  fStack_34 = fStack_24;
  FUN_004c69f0(&fStack_38,&fStack_38);
  fVar6 = fStack_20 * fStack_30 + fStack_28 * fStack_38 + fStack_24 * fStack_34;
  if (0.0 <= fVar6) {
    fVar8 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
    uStack_68 = CONCAT44(fStack_74,uStack_78);
    fStack_60 = fStack_70;
  }
  else {
    fVar8 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c);
    uStack_68 = CONCAT44(fStack_84,fStack_88);
    fStack_60 = fStack_80;
  }
  fStack_18 = fStack_30 * fVar8 + fStack_88 + 0.0;
  fStack_14 = fStack_54;
  fStack_10 = (fStack_80 + 0.0) - fStack_38 * fVar8;
  fStack_48 = fStack_18 - fStack_58;
  fStack_44 = fStack_54 - fStack_54;
  fStack_40 = fStack_10 - fStack_50;
  FUN_004c69f0(&fStack_48,&fStack_48);
  fVar9 = fStack_60;
  fVar4 = fStack_40 * fStack_30 + fStack_48 * fStack_38 + fStack_44 * fStack_34;
  if (((ABS(fVar4) < ABS(fVar6)) && (fVar4 != 0.0)) && (fVar6 != 0.0)) {
    fStack_8 = fStack_58 - (float)uStack_68;
    fStack_4 = fStack_50 - fStack_60;
    fVar6 = (float)FUN_004c6af0(&fStack_8);
    fStack_14 = fStack_54 + (fVar5 * fVar6) / fVar7;
    fStack_18 = fStack_30 * fVar8 + (float)uStack_68 + 0.0;
    fStack_10 = (fVar9 + 0.0) - fStack_38 * fVar8;
    fVar5 = (float)FUN_002d1f30(auStack_134,&uStack_c0);
    fStack_18 = ((float)uStack_68 + 0.0) - fStack_30 * fVar8;
    fStack_10 = fStack_38 * fVar8 + fVar9 + 0.0;
    fVar6 = (float)FUN_002d1f30(auStack_134,&uStack_b0);
    if (fVar5 < fVar6) {
      uStack_118 = uStack_c0;
      uStack_114 = uStack_bc;
      uStack_110 = uStack_b8;
      uStack_10c = uStack_b4;
    }
    else {
      uStack_118 = uStack_b0;
      uStack_114 = uStack_ac;
      uStack_110 = uStack_a8;
      uStack_10c = uStack_a4;
    }
    FUN_004be1e0(&fStack_28,0x6978a0,1,&uStack_118);
  }
  fStack_28 = fStack_28 * fVar7;
  fStack_24 = fStack_24 * fVar7;
  fStack_20 = fStack_20 * fVar7;
  fVar5 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar3 + 0xb8) * 0.5);
  fVar5 = fVar7 * fVar5 * 0.21875;
  fStack_8 = fStack_28;
  fStack_4 = fStack_20;
  FUN_004c6b20(&fStack_8,&fStack_8);
  fStack_58 = fStack_4 * fVar5 + fStack_58 + 0.0;
  fStack_50 = (fStack_50 + 0.0) - fStack_8 * fVar5;
  fStack_124 = fStack_58 + fStack_28;
  fStack_120 = fStack_54 + fStack_24;
  fStack_11c = fStack_50 + fStack_20;
  return;
}

// FUN_002b17a0 NONMATCHING

void FUN_002b17a0(float param_1, undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  u32 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float afStack_110 [3];
  undefined1 auStack_104 [16];
  undefined1 auStack_f4 [28];
  undefined1 auStack_d8 [28];
  undefined1 auStack_bc [28];
  undefined1 auStack_a0 [64];
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar3 = (int)(DAT_007ce3ec + 0x20);
  iVar1 = *(int *)(*(int *)(iVar3 + 0xe0) + 0x30);
  iVar2 = *(int *)(*(int *)(*(int *)(iVar3 + 0xe0) + 0x38) + 0x30);
  fVar5 = *(float *)(iVar1 + 0x84);
  fVar6 = *(float *)(iVar1 + 0x2c);
  FUN_0027ffb0(iVar2,&fStack_50);
  fVar6 = fGpffff8094 * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) + fVar5 * fVar6 + 0.0 +
          fGpffff8094 * *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) + fStack_4c + 0.0;
  fStack_4c = 0.0;
  fStack_10 = *(float *)(iVar1 + 0xdc) - fStack_50;
  fStack_c = *(float *)(iVar1 + 0xe0) - 0.0;
  fStack_8 = *(float *)(iVar1 + 0xe4) - fStack_48;
  fVar5 = (float)FUN_004c69f0(&fStack_10,&fStack_10);
  fStack_20 = fStack_10 * fVar5 * 0.5 + fStack_50;
  fStack_18 = fStack_8 * fVar5 * 0.5 + fStack_48;
  fVar6 = fVar6 * 0.5;
  fStack_60 = fStack_8;
  fStack_5c = -fStack_10;
  fStack_58 = afStack_110[0] - fStack_20;
  fStack_54 = afStack_110[2] - fStack_18;
  fStack_1c = fVar6;
  FUN_004c6b20(&fStack_60,&fStack_60);
  FUN_004c6b20(&fStack_58,&fStack_58);
  fVar7 = fStack_60 * fStack_58 + fStack_5c * fStack_54;
  if (0.0 <= fVar7) {
    fVar5 = fGpffff8094 * fVar5;
  }
  else {
    fVar5 = fVar5 * 0.5;
  }
  fStack_18 = fStack_8 * fVar5;
  fStack_20 = fStack_10 * fVar5;
  fStack_20 = fStack_20 + fStack_50;
  fStack_18 = fStack_18 + fStack_48;
  *(float *)(iVar3 + 0x10c) = *(float *)(iVar1 + 0xe8) * 0.5;
  *(float *)(iVar3 + 0x100) = fStack_20;
  *(float *)(iVar3 + 0x104) = fVar6;
  *(float *)(iVar3 + 0x108) = fStack_18;
  fStack_40 = afStack_110[0] - fStack_20;
  fStack_3c = afStack_110[1] - fVar6;
  fStack_38 = afStack_110[2] - fStack_18;
  fVar5 = param_1 / 3.0;
  fStack_1c = fVar6;
  for (uVar4 = 1; uVar4 < 4; uVar4 = uVar4 + 1 & 0xffff) {
    if (0.0 <= fVar7) {
      FUN_004c31b0(fVar5,auStack_a0,0x697880,0);
    }
    else {
      FUN_004c31b0(-fVar5,auStack_a0,0x697880,0);
    }
    FUN_004c6c60(&fStack_30,&fStack_40,auStack_a0);
    afStack_110[uVar4 * 7] = fStack_30 + fStack_20;
    afStack_110[uVar4 * 7 + 1] = fStack_2c + fStack_1c;
    *(float *)(auStack_104 + uVar4 * 0x1c + -4) = fStack_28 + fStack_18;
    fVar5 = fVar5 + param_1 / 3.0;
  }
  return;
}

// FUN_002b1bc0 NONMATCHING

void FUN_002b1bc0(int param_1)

{
  if ((*(char *)(*(int *)(*(int *)(param_1 + 0xe0) + 0x30) + 0xa2) == '\0') &&
     (((*(u32 *)(iGpffffb6fc + 0xc) & 0x200000) == 0 ||
      (*(short *)(*(int *)(iGpffffb6fc + 0xbbc) + 8) != 0x1b4)))) {
    *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(*(int *)(param_1 + 0xe0) + 0x38);
    if ((*(u32 *)(iGpffffb6fc + 0xc) & 0x200000) == 0) {
      if (*(short *)(iGpffffb6fc + 0x10a) == 1) {
        FUN_002b17a0(0x42c80000,0x40400000);
      }
      else if (*(short *)(iGpffffb6fc + 0x10a) == 0) {
        FUN_002b1060(0x42200000,0x40000000);
      }
    }
    else if (*(short *)(iGpffffb6fc + 0x10a) == 1) {
      FUN_002b17a0(0x42480000,0x40400000);
    }
    else if (*(short *)(iGpffffb6fc + 0x10a) == 0) {
      FUN_002b1060(0x41a00000,0x40000000);
    }
  }
  return;
}


// FUN_002B1CF0
void FUN_002b1cf0(int param_1)
{
  u16 uVar1;
  u16 uVar2;
  int iVar3;

  iVar3 = param_1;
  param_1 = *(int *)(param_1 + 0xe0);
  if (((param_1 != 0) && (*(u16 *)(param_1 + 0x6a) == 1)) &&
     (*(int *)(iVar3 + 0x11c) == *(int *)(param_1 + 0x38))) {
    uVar1 = *(u16 *)(param_1 + 0x1a);
    if ((((uVar1 & 1) != 0) && (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) == 0)) &&
       (((*(u32 *)(iGpffffb6fc + 0xc) & 0x200000) == 0 ||
        (*(u16 *)(*(int *)(iGpffffb6fc + 0xbbc) + 8) != 0x1b4)))) {
      uVar2 = *(u16 *)(iGpffffb6fc + 0x10a);
      if (uVar2 == 1) {
        goto nonzero;
      }
      switch (uVar2) {
      case 0:
        goto zero;
      default:
        goto nonzero;
      }
zero:
      if ((param_1 != 0) && ((uVar1 & 1) != 0)) {
        FUN_002a3e80(*(float *)(iVar3 + 0x10c), (u8 *)(uintptr_t)param_1,
                     (u8 *)(uintptr_t)(iVar3 + 0x9c),
                     (u8 *)(uintptr_t)(iVar3 + 0x100), 0x33);
      }
      goto end;
nonzero:
      if ((param_1 != 0) && ((uVar1 & 1) != 0)) {
        FUN_002a3e80(*(float *)(iVar3 + 0x10c), (u8 *)(uintptr_t)param_1,
                     (u8 *)(uintptr_t)(iVar3 + 0x9c),
                     (u8 *)(uintptr_t)(iVar3 + 0x100), 0x33);
      }
    }
  }
end:
  return;
}

// FUN_002b1e00 NONMATCHING

void FUN_002b1e00(int param_1)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  u32 uVar4;
  long lVar5;
  u32 unaff_s1_lo;
  
  *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(*(int *)(param_1 + 0xe0) + 0x38);
  iVar1 = *(int *)(*(int *)(param_1 + 0xe0) + 0x30);
  if (*(char *)(iVar1 + 0xa2) == '\0') {
    lVar5 = FUN_002d5bf0(iVar1);
    if (lVar5 == 0) {
      uVar3 = *(undefined2 *)(iVar1 + 0xa4);
    }
    else {
      uVar3 = 3;
    }
    switch(uVar3) {
    case 1:
      uVar4 = FUN_00308c60(*(undefined4 *)(iVar1 + 0xa2c));
      unaff_s1_lo = (uVar4 & 0xff) * 0xf4 + 0x693d10;
      break;
    case 2:
      unaff_s1_lo = (u32)(uintptr_t)&DAT_006944b0;
      break;
    case 3:
      cVar2 = FUN_003093a0(*(undefined4 *)(iVar1 + 0xa2c));
      if (cVar2 == '\x03') {
        unaff_s1_lo = (u32)(uintptr_t)&DAT_00694798;
      }
      else if (cVar2 == '\x02') {
        unaff_s1_lo = (u32)(uintptr_t)&DAT_006946a4;
      }
      else if (cVar2 == '\x01') {
        unaff_s1_lo = (u32)(uintptr_t)&DAT_006945b0;
      }
      break;
    case 4:
      unaff_s1_lo = (u32)(uintptr_t)&DAT_00694890;
      break;
    case 5:
      unaff_s1_lo = (u32)(uintptr_t)&DAT_00694990;
      break;
    case 7:
      unaff_s1_lo = (u32)(uintptr_t)&DAT_00694a90;
      break;
    case 8:
      unaff_s1_lo = (u32)(uintptr_t)&DAT_00694b90;
      break;
    case 9:
      unaff_s1_lo = (u32)(uintptr_t)&DAT_00694c90;
      break;
    case 10:
      unaff_s1_lo = (u32)(uintptr_t)&DAT_00694d90;
    }
    FUN_002b6bf0((undefined4*)(uintptr_t)(param_1 + 0xec),*(int *)(param_1 + 0xe0),
                 *(undefined4 *)(*(int *)(param_1 + 0xe0) + 0x38),unaff_s1_lo,3);
    lVar5 = (long)FUN_002b6cd0(param_1 + 0xec);
    if (lVar5 != 0) {
      if (*(short *)((int)lVar5 + 0x1c) == 1) {
        *(undefined4 *)(param_1 + 0x110) = 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x110) = 0;
      }
    }
    *(undefined4 *)(param_1 + 0x114) = 0;
  }
  return;
}

// FUN_002b2060 NONMATCHING

void FUN_002b2060(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  iVar1 = *(int *)(iVar4 + 0xe0);
  if ((((iVar1 != 0) && (*(short *)(iVar1 + 0x6a) == 1)) && (*(int *)(iVar4 + 0x100) != 0)) &&
     ((*(int *)(iVar4 + 0x100) == *(int *)(iVar1 + 0x38) && ((*(u16 *)(iVar1 + 0x1a) & 1) != 0)))
     ) {
    lVar3 = FUN_002b6bd0(iVar4 + 0xec);
    if (lVar3 != 0) {
      FUN_002b64d0(param_1,iVar4 + 0xec);
    }
    lVar3 = (long)FUN_002b6cd0(iVar4 + 0xec);
    if (lVar3 != 0) {
      if (*(short *)((int)lVar3 + 0x1c) == 1) {
        if (*(int *)(iVar4 + 0x114) != 0) {
        }
        *(undefined4 *)(iVar4 + 0x110) = 1;
      }
      else {
        if (*(int *)(iVar4 + 0x110) == 1) {
          uVar2 = 3;
        }
        else {
          uVar2 = 0x33;
        }
        if (*(int *)(iVar4 + 0x114) == 0) {
          lVar3 = FUN_0030b5a0(*(undefined4 *)(*(int *)(*(int *)(iVar4 + 0x100) + 0x30) + 0xa2c),0);
          if (lVar3 == 0) {
            FUN_002a3e80(0x42480000,(u8*)(uintptr_t)*(undefined4 *)(iVar4 + 0xe0),
                         (u8*)(uintptr_t)(iVar4 + 0x9c),
                         (u8*)(uintptr_t)(*(int *)(*(int *)(iVar4 + 0x100) + 0x30) + 4),uVar2);
          }
        }
        else {
        }
        *(undefined4 *)(iVar4 + 0x110) = 0;
      }
    }
  }
  return;
}

// FUN_002b21f0 NONMATCHING

void FUN_002b21f0(undefined4 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  float fVar2;
  int iVar3;
  undefined8 uVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined1 auStack_d0 [12];
  undefined1 auStack_c4 [16];
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  undefined1 auStack_a8 [24];
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar3 = (int)param_2;
  iVar6 = *(int *)(*(int *)(iVar3 + 0xe0) + 0x30);
  iVar1 = *(int *)(*(int *)(*(int *)(iVar3 + 0xe0) + 0x38) + 0x30);
  FUN_00280130(iVar6,&fStack_10);
  FUN_00280130(iVar1,&fStack_20);
  fStack_50 = fStack_10 - fStack_20;
  fStack_4c = fStack_c - fStack_1c;
  fStack_48 = fStack_8 - fStack_18;
  fVar7 = (float)FUN_004c69f0(&fStack_50,&fStack_50);
  fStack_88 = *(float *)(iVar3 + 0x9c) - fStack_10;
  fStack_84 = *(float *)(iVar3 + 0xa4) - fStack_8;
  FUN_004c6b20(&fStack_88,&fStack_88);
  fStack_90 = fStack_50;
  fStack_8c = fStack_48;
  if (param_3 != 0) {
    if ((*(u32 *)(iGpffffb6fc + 0xc) & 0x200000) == 0) {
      *(u32 *)(iVar3 + 0x104) = (u32)(0.0 <= fStack_50 * fStack_88 + fStack_48 * fStack_84);
    }
    else {
      *(undefined4 *)(iVar3 + 0x104) = 0;
    }
  }
  if (*(int *)(iVar3 + 0x104) == 1) {
    fStack_2c = fStack_c;
    fStack_28 = fStack_8;
    fVar9 = *(float *)(iVar6 + 0x90) * *(float *)(iVar6 + 0x2c) * 1.25;
    fVar7 = fGpffff8098 * fVar7;
    fStack_40 = fStack_50 * fVar7;
    fStack_3c = fStack_4c * fVar7;
    fStack_38 = fStack_48 * fVar7;
    if (fStack_c < 100.0) {
      fStack_2c = 100.0;
    }
    fStack_30 = fStack_10;
    fVar7 = fGpffff809c;
    iVar5 = iVar6;
    iVar6 = iVar1;
  }
  else {
    fStack_30 = fStack_20;
    fStack_2c = fStack_1c;
    fStack_28 = fStack_18;
    fVar9 = fGpffff8098 * *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
    fVar7 = 2.5;
    fStack_c = (fStack_c + 0.0) - *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) * 0.25;
    if (fStack_c < 100.0) {
      fStack_c = 100.0;
    }
    fStack_50 = fStack_10 - fStack_20;
    fStack_4c = fStack_c - fStack_1c;
    fStack_48 = fStack_8 - fStack_18;
    fStack_38 = (float)FUN_004c69f0(&fStack_50,&fStack_50);
    fStack_38 = fStack_38 * 0.25;
    fStack_40 = fStack_50 * fStack_38;
    fStack_3c = fStack_4c * fStack_38;
    fStack_38 = fStack_48 * fStack_38;
    iVar5 = iVar1;
  }
  fVar2 = fStack_2c;
  fStack_40 = fStack_40 + fStack_20;
  fStack_3c = fStack_3c + fStack_1c;
  fStack_38 = fStack_38 + fStack_18;
  fStack_90 = fStack_48;
  fStack_8c = -fStack_50;
  if (param_3 != 0) {
    *(u32 *)(iVar3 + 0x108) = (u32)(0.0 <= fStack_48 * fStack_88 + fStack_8c * fStack_84);
  }
  if (*(int *)(iVar3 + 0x108) == 1) {
    fStack_60 = fStack_48 * fVar9 + fStack_30 + 0.0;
    fStack_58 = (fStack_28 + 0.0) - fStack_50 * fVar9;
  }
  else {
    fStack_60 = (fStack_30 + 0.0) - fStack_48 * fVar9;
    fStack_58 = fStack_50 * fVar9 + fStack_28 + 0.0;
  }
  fVar9 = fStack_28;
  fStack_5c = fStack_2c;
  FUN_004be1e0(&fStack_50,0x6978a0,1,auStack_a8);
  fStack_80 = fStack_40;
  fStack_7c = fStack_38;
  fStack_78 = fStack_60;
  fStack_74 = fStack_58;
  fStack_68 = fStack_30;
  fStack_64 = fVar9;
  fVar9 = (float)FUN_002d1fd0(&fStack_80,&fStack_78,&fStack_68,&fStack_70);
  fVar8 = fVar7 * *(float *)(iVar5 + 0x90) * *(float *)(iVar5 + 0x2c) + fVar9 + 0.0;
  fStack_60 = fStack_70;
  fStack_58 = fStack_6c;
  fStack_5c = fVar2;
  fVar9 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar3 + 0xb8) * 0.5);
  fVar7 = 500.0;
  if (500.0 <= fVar8 / fVar9) {
    fVar7 = fVar8 / fVar9;
  }
  fStack_50 = fStack_50 * fVar7;
  fStack_4c = fStack_4c * fVar7;
  fStack_48 = fStack_48 * fVar7;
  fStack_b4 = fStack_60 + fStack_50;
  fStack_b0 = fStack_5c + fStack_4c;
  fStack_ac = fStack_58 + fStack_48;
  if (fStack_b0 < 12.5) {
    fStack_b0 = 12.5;
  }
  if (param_3 != 0) {
    fVar7 = (float)FUN_002d1f30(auStack_c4,auStack_a8);
    if (fGpffff80d4 < fVar7) {
      uVar4 = 3;
    }
    else {
      uVar4 = 0x23;
    }
  }
  return;
}

// FUN_002b2800

void FUN_002b2800(BtlCamera *camera)
{
  s64 lVar1;
  undefined2 uVar2;
  BtlAction *action;
  s16 targetId;

  action = camera->action;
  targetId = *(volatile s16 *)&action->target.specificId;
  lVar1 = FUN_002f8eb0(action->unit, targetId);
  if (lVar1 == -1) {
    lVar1 = 4;
  }
  uVar2 = FUN_002835e0(camera->action->unit, lVar1 & 0xffff, 1.0f);
  *(undefined2 *)((u8 *)camera + 0x10e) = uVar2;
  *(undefined4 *)((u8 *)camera + 0x100) =
      *(undefined4 *)((u8 *)camera->action + 0x38);
  *(undefined2 *)((u8 *)camera + 0x10c) = 0;
  return;
}
// FUN_002b2880 NONMATCHING
void FUN_002b2880(undefined8 param_1)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + 0xe0);
  if ((((iVar1 != 0) && (*(short *)(iVar1 + 0x6a) == 1)) &&
      (*(int *)(iVar2 + 0x100) == *(int *)(iVar1 + 0x38))) && ((*(u16 *)(iVar1 + 0x1a) & 1) != 0)
     ) {
    uVar3 = uGpffff8100;
    if ((*(u16 *)(iVar2 + 0x10e) <= *(u16 *)(iVar2 + 0x10c)) &&
       (uVar3 = uGpffff808c, *(int *)(iVar2 + 0x108) != 0)) {
      uVar3 = uGpffff80fc;
    }
    FUN_002b21f0(uVar3,param_1,*(u16 *)(iVar2 + 0x10c) == 0);
    *(short *)(iVar2 + 0x10c) = *(short *)(iVar2 + 0x10c) + 1;
  }
  return;
}

// FUN_002b2940 NONMATCHING

void FUN_002b2940(undefined8 param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  undefined1 auStack_94 [20];
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar4 = (int)param_1;
  iVar2 = *(int *)(*(int *)(iVar4 + 0xe0) + 0x30);
  cVar1 = *(char *)(iVar2 + 0xa2);
  iVar3 = *(int *)(*(int *)(*(int *)(iVar4 + 0xe0) + 0x38) + 0x30);
  fVar6 = *(float *)(iVar3 + 0x90) * *(float *)(iVar3 + 0x2c);
  FUN_0027ffb0(iVar3,&fStack_10);
  FUN_0027ffb0(iVar2,&fStack_20);
  if (fStack_1c < fStack_c) {
    fStack_c = (fStack_c + 0.0) - fGpffff8094 * *(float *)(iVar3 + 0x8c) * *(float *)(iVar3 + 0x2c);
    fStack_1c = fGpffff806c * *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) + fStack_1c + 0.0;
  }
  else {
    fStack_c = fGpffff8094 * *(float *)(iVar3 + 0x8c) * *(float *)(iVar3 + 0x2c) + fStack_c + 0.0;
    fStack_1c = (fStack_1c + 0.0) -
                fGpffff8094 * *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c);
  }
  if (fStack_c < 65.0) {
    fStack_c = 65.0;
  }
  fStack_40 = fStack_10 + (fStack_20 - fStack_10) * fGpffff8088;
  fStack_3c = fStack_c + (fStack_1c - fStack_c) * fGpffff8088;
  fStack_38 = fStack_8 + (fStack_18 - fStack_8) * fGpffff8088;
  fStack_68 = fStack_10 - *(float *)(iVar4 + 0x9c);
  fStack_4c = fStack_c - *(float *)(iVar4 + 0xa0);
  fStack_64 = fStack_8 - *(float *)(iVar4 + 0xa4);
  fStack_50 = fStack_68;
  fStack_48 = fStack_64;
  FUN_004c6b20(&fStack_68,&fStack_68);
  FUN_004be1e0(&fStack_50,0x697870,1,iVar3 + 0x1c);
  fStack_70 = fStack_50;
  fStack_6c = fStack_48;
  FUN_004c6b20(&fStack_70,&fStack_70);
  if (cVar1 == '\0') {
    fVar5 = fVar6 * 0.5;
    fStack_50 = fStack_50 * fVar5;
    fStack_4c = fStack_4c * fVar5;
    fStack_48 = fStack_48 * fVar5;
    fStack_30 = fStack_10 - fStack_50;
    fStack_2c = fStack_c - fStack_4c;
    fStack_28 = fStack_8 - fStack_48;
  }
  else {
    fVar5 = fVar6 * 1.5;
    fStack_50 = fStack_50 * fVar5;
    fStack_4c = fStack_4c * fVar5;
    fStack_48 = fStack_48 * fVar5;
    if (fStack_70 * fStack_68 + fStack_6c * fStack_64 < 0.0) {
      fStack_30 = fStack_10 + fStack_50;
      fStack_2c = fStack_c + fStack_4c;
      fStack_28 = fStack_8 + fStack_48;
    }
    else {
      fStack_30 = fStack_10 - fStack_50;
      fStack_2c = fStack_c - fStack_4c;
      fStack_28 = fStack_8 - fStack_48;
    }
  }
  fStack_80 = fStack_40;
  fStack_7c = fStack_38;
  fStack_78 = fStack_30;
  fStack_74 = fStack_28;
  fStack_58 = fStack_10;
  fStack_54 = fStack_8;
  fVar5 = (float)FUN_002d1fd0(&fStack_80,&fStack_78,&fStack_58,0);
  if (cVar1 == '\0') {
    if (fVar6 <= 100.0) {
      fVar6 = 100.0;
    }
  }
  else if (fVar6 <= 125.0) {
    fVar6 = 125.0;
  }
  fVar7 = 160.0;
  if (160.0 <= fVar5 + fVar6) {
    fVar7 = fVar5 + fVar6;
  }
  fStack_50 = fStack_40 - fStack_30;
  fStack_4c = fStack_3c - fStack_2c;
  fStack_48 = fStack_38 - fStack_28;
  fVar6 = (float)FUN_004c6ac0(&fStack_50);
  fVar5 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar4 + 0xb8) * 0.5);
  fVar6 = fVar6 + fVar7 / fVar5;
  if (fVar6 <= 0.0) {
    fVar6 = 0.0;
  }
  FUN_004be1e0(&fStack_50,0x6978a0,1,auStack_94);
  fStack_50 = fStack_50 * fVar6;
  fStack_4c = fStack_4c * fVar6;
  fStack_48 = fStack_48 * fVar6;
  fStack_a0 = fStack_40 + fStack_50;
  fStack_9c = fStack_3c + fStack_4c;
  fStack_98 = fStack_38 + fStack_48;
  if (fStack_9c < 25.0) {
    fStack_9c = 25.0;
  }
  return;
}

// FUN_002b2eb0 NONMATCHING

void FUN_002b2eb0(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  int iStack_5c;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  undefined1 auStack_8 [4];
  float fStack_4;
  
  fVar1 = (float)FUN_00280870(3,1,&fStack_38,&fStack_4,auStack_8,1);
  fVar2 = (float)FUN_0052e930(fGpffff8070 * *(float *)(param_1 + 0xb8) * 0.5);
  fVar2 = fVar1 / fVar2;
  fStack_18 = 0.0;
  fStack_14 = fStack_4;
  fStack_10 = -fVar1;
  fVar1 = (float)FUN_002d1f30(param_1 + 0xa8,param_2 + 3);
  if (fGpffff80d4 < fVar1) {
    fVar1 = fGpffff80d4 / fVar1;
    FUN_004be310(param_1 + 0xa8,param_2 + 3,&fStack_80);
    if (fVar1 <= 0.0) {
      fStack_50 = *(float *)(param_1 + 0xa8);
      fStack_4c = *(float *)(param_1 + 0xac);
      fStack_48 = *(float *)(param_1 + 0xb0);
      fStack_44 = *(float *)(param_1 + 0xb4);
    }
    else if (1.0 <= fVar1) {
      fStack_50 = param_2[3];
      fStack_4c = param_2[4];
      fStack_48 = param_2[5];
      fStack_44 = param_2[6];
    }
    else {
      fVar3 = 1.0 - fVar1;
      if (iStack_5c == 0) {
        fVar3 = fVar3 * fStack_60;
        fVar4 = fVar3 * fVar3;
        fVar3 = fVar4 * fVar3 *
                (fVar4 * (fVar4 * (fVar4 * (fVar4 * (fGpffff8114 * fVar4 + fGpffff8048 + 0.0) +
                                           fGpffff8118 + 0.0) + fGpffff8050 + 0.0) +
                         fGpffff8054 + 0.0) + fGpffff8058 + 0.0) + fVar3 + 0.0;
        fVar1 = fVar1 * fStack_60;
        fVar4 = fVar1 * fVar1;
        fVar1 = fVar4 * fVar1 *
                (fVar4 * (fVar4 * (fVar4 * (fVar4 * (fGpffff8114 * fVar4 + fGpffff8048 + 0.0) +
                                           fGpffff8118 + 0.0) + fGpffff8050 + 0.0) +
                         fGpffff8054 + 0.0) + fGpffff8058 + 0.0) + fVar1 + 0.0;
      }
      fStack_50 = fStack_70 * fVar1 + fStack_80 * fVar3 + 0.0;
      fStack_4c = fStack_6c * fVar1 + fStack_7c * fVar3 + 0.0;
      fStack_48 = fStack_68 * fVar1 + fStack_78 * fVar3 + 0.0;
      fStack_44 = fStack_74 * fVar3 + fStack_64 * fVar1;
    }
    FUN_004be1e0(&fStack_28,0x6978a0,1,&fStack_50);
    fStack_18 = fStack_38 + fStack_28;
    fStack_14 = fStack_34 + fStack_24;
    fStack_10 = fStack_30 + fStack_20;
  }
  fVar1 = 700.0;
  if (700.0 <= fVar2) {
    fVar1 = fVar2;
  }
  FUN_004be1e0(&fStack_28,0x6978a0,1,param_2 + 3);
  fStack_28 = fStack_28 * fVar1;
  fStack_24 = fStack_24 * fVar1;
  fStack_20 = fStack_20 * fVar1;
  fVar2 = (float)FUN_0052e930(fGpffff8070 * *(float *)(param_1 + 0xb8) * 0.5);
  fVar1 = fVar1 * fVar2 * 0.21875;
  fStack_40 = fStack_28;
  fStack_3c = fStack_20;
  FUN_004c6b20(&fStack_40,&fStack_40);
  *param_2 = fStack_3c * fVar1 + fStack_38 + 0.0 + fStack_28;
  param_2[1] = fStack_34 + fStack_24;
  param_2[2] = ((fStack_30 + 0.0) - fStack_40 * fVar1) + fStack_20;
  return;
}

// FUN_002b32c0

void FUN_002b32c0(u16* camera)

{
  struct {
    undefined1 first[28];
    undefined1 second[36];
  } scratch;

  FUN_002a4470((f32*)scratch.first, (f32*)((u8*)camera + 0x9c));
  FUN_002b2eb0((int)camera, (float*)scratch.second);
  FUN_002a2290(camera, (RwV3d*)scratch.first, (RwV3d*)scratch.second, 1);
  FUN_002a3110(10.0f, camera);
  return;
}

// FUN_002b3330
void func_002b3330(void)
{
}

// FUN_002b3340 NONMATCHING

void FUN_002b3340(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  undefined1 auStack_44 [20];
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + 0xe0) == 0) {
    iVar1 = *(int *)(*(int *)(iGpffffb6fc + 0x148) + 0x30);
  }
  else {
    iVar1 = *(int *)(*(int *)(iVar2 + 0xe0) + 0x30);
  }
  fVar3 = (float)FUN_00280870(3,1,&fStack_10,&fStack_4,0,1);
  FUN_00280050(iVar1,&fStack_20);
  fStack_c = 0.0;
  fStack_1c = 0.0;
  if ((fStack_20 == fStack_10) && (fStack_18 == fStack_8)) {
    FUN_00280050(*(undefined4 *)(*(int *)(iGpffffb6fc + 0x148) + 0x30),&fStack_20);
  }
  fStack_1c = 0.0;
  fStack_30 = fStack_20 - fStack_10;
  fStack_2c = 0.0 - fStack_c;
  fStack_28 = fStack_18 - fStack_8;
  FUN_004c69f0(&fStack_30,&fStack_30);
  fStack_30 = fStack_30 * fVar3;
  fStack_2c = fStack_2c * fVar3;
  fStack_28 = fStack_28 * fVar3;
  fStack_20 = fStack_10 + fStack_30;
  fStack_18 = fStack_8 + fStack_28;
  fVar5 = *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) * 0.75;
  fStack_1c = fGpffff80c4 * fStack_4;
  if (fStack_1c <= fVar5) {
    fStack_1c = fVar5;
  }
  fVar5 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar2 + 0xb8) * 0.5);
  fVar5 = (fVar3 * 0.75) / fVar5;
  fStack_30 = fStack_20 - fStack_10;
  fStack_2c = fStack_1c - fStack_c;
  fStack_28 = fStack_18 - fStack_8;
  fVar4 = (float)FUN_004c69f0(&fStack_30,&fStack_30);
  fVar3 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar2 + 0xb8) * 0.5);
  fVar4 = fVar4 + (*(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) * 2.0) / fVar3;
  if (fVar5 <= fVar4) {
    fVar5 = fVar4;
  }
  fStack_30 = fStack_30 * fVar5;
  fStack_2c = fStack_2c * fVar5;
  fStack_28 = fStack_28 * fVar5;
  fStack_50 = fStack_30 + fStack_10;
  fStack_4c = fStack_2c + fStack_c;
  fStack_48 = fStack_28 + fStack_8;
  return;
}

// FUN_002b3690 NONMATCHING

void FUN_002b3690(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined1 auStack_10 [4];
  float fStack_c;
  float fStack_4;
  
  iVar1 = *(int *)(*(int *)(iGpffffb6fc + 0x148) + 0x30);
  fVar3 = (float)FUN_00280870(3,0,0,&fStack_4,0,1);
  FUN_00280870(2,0,&fStack_20,0,0,1);
  fStack_1c = fStack_4 * 0.5;
  FUN_00280050(iVar1,auStack_10);
  fStack_c = *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) * 0.75 + fStack_c + 0.0;
  uStack_48 = uStack_64;
  uStack_44 = uStack_60;
  uStack_40 = uStack_5c;
  uStack_3c = uStack_58;
  iVar2 = (int)param_1;
  fVar4 = (float)FUN_0052e930(*(float *)(iVar2 + 0xb8) * 0.5);
  fVar4 = 250.0 / fVar4;
  if (1 < *(u8 *)(iGpffffb6fc + 0xba4)) {
    FUN_004bdde0(0x41f00000,&uStack_64,0x697880,2);
  }
  FUN_004be1e0(&fStack_30,0x6978a0,1,&uStack_64);
  fStack_30 = fStack_30 * fVar4;
  fStack_2c = fStack_2c * fVar4;
  fStack_28 = fStack_28 * fVar4;
  fStack_70 = fStack_20 + fStack_30;
  fStack_6c = fStack_1c + fStack_2c;
  fStack_68 = fStack_18 + fStack_28;
  fVar4 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar2 + 0xb8) * 0.5);
  fVar4 = (fVar3 * 0.875) / fVar4;
  if (*(char *)(iGpffffb6fc + 0xba4) == '\x01') {
    fVar3 = (float)FUN_0052e930(*(float *)(iVar2 + 0xb8) * 0.5);
    fVar4 = fVar4 + (*(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) * 0.5) / fVar3;
  }
  FUN_004be1e0(&fStack_30,0x6978a0,1,&uStack_48);
  fStack_30 = fStack_30 * fVar4;
  fStack_2c = fStack_2c * fVar4;
  fStack_28 = fStack_28 * fVar4;
  fStack_54 = fStack_20 + fStack_30;
  fStack_50 = fStack_1c + fStack_2c;
  fStack_4c = fStack_18 + fStack_28;
  return;
}

// FUN_002b3980 NONMATCHING

void FUN_002b3980(undefined8 param_1)

{
  int iVar1;
  u32 uVar2;
  int iVar3;
  u32 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float afStack_f0 [3];
  undefined1 auStack_e4 [16];
  undefined1 auStack_d4 [28];
  undefined1 auStack_b8 [28];
  undefined1 auStack_9c [28];
  undefined1 auStack_80 [64];
  undefined1 auStack_40 [16];
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar3 = (int)param_1;
  iVar1 = *(int *)(*(int *)(iVar3 + 0xe0) + 0x30);
  FUN_0027ffb0(iVar1,&fStack_20);
  fVar8 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
  fVar6 = *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) * 0.5;
  fStack_1c = fGpffff80b4 * fVar6 + fStack_1c + 0.0;
  if (fVar6 < fVar8) {
    fVar5 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar3 + 0xb8) * 0.5);
    fVar5 = (fVar8 * 1.25) / fVar5;
  }
  else {
    fVar5 = (float)FUN_0052e930(*(float *)(iVar3 + 0xb8) * 0.5);
    fVar5 = (fVar6 * 1.25) / fVar5;
  }
  uVar2 = FUN_002ffbc0(100);
  if (uVar2 < 0x33) {
    fVar6 = -60.0;
    fVar8 = 30.0;
  }
  else {
    fVar6 = 60.0;
    fVar8 = -30.0;
  }
  for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 1 & 0xffff) {
    FUN_004c31b0(fVar6,auStack_80,0x697880,0);
    FUN_004c6c60(auStack_40,0x697890,auStack_80);
    FUN_004be1e0(&fStack_30,auStack_40,1,iVar1 + 0x1c);
    fVar10 = fStack_30 * fVar5;
    fVar7 = fStack_2c * fVar5;
    fVar9 = fStack_28 * fVar5;
    fStack_10 = fStack_20 + fVar10;
    fStack_c = fStack_1c + fVar7;
    fStack_8 = fStack_18 + fVar9;
    afStack_f0[uVar4 * 7] = fStack_20 + fVar10;
    afStack_f0[uVar4 * 7 + 1] = fStack_1c + fVar7;
    afStack_f0[uVar4 * 7 + 2] = fStack_18 + fVar9;
    fVar6 = fVar6 + fVar8;
    fVar5 = fVar5 + 37.5;
  }
  return;
}

// FUN_002b3c60 NONMATCHING

void FUN_002b3c60(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  u32 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float afStack_e0 [3];
  undefined1 auStack_d4 [16];
  undefined1 auStack_c4 [28];
  undefined1 auStack_a8 [28];
  undefined1 auStack_8c [28];
  undefined1 auStack_70 [64];
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar2 = (int)param_1;
  iVar1 = *(int *)(*(int *)(iVar2 + 0xe0) + 0x30);
  FUN_0027ffb0(iVar1,&fStack_10);
  fVar5 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
  fVar6 = *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) * 0.5;
  fStack_c = fGpffff80b4 * fVar6 + fStack_c + 0.0;
  FUN_004be1e0(&fStack_20,0x697890,1,iVar1 + 0x1c);
  fStack_30 = fStack_20 * 350.0;
  fStack_2c = fStack_1c * 350.0;
  fStack_28 = fStack_18 * 350.0;
  fStack_20 = (fStack_10 + fStack_30) - fStack_10;
  fStack_1c = ((fStack_c + fStack_2c) - 35.0) - fStack_c;
  fStack_18 = (fStack_8 + fStack_28) - fStack_8;
  FUN_004c69f0(&fStack_20,&fStack_20);
  if (fVar6 <= fVar5) {
    fVar4 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar2 + 0xb8) * 0.5);
    fVar4 = (fVar5 * 1.75) / fVar4;
  }
  else {
    fVar4 = (float)FUN_0052e930(*(float *)(iVar2 + 0xb8) * 0.5);
    fVar4 = (fGpffff8070 * fVar6) / fVar4;
  }
  fVar5 = 65.0;
  for (uVar3 = 0; uVar3 < 4; uVar3 = uVar3 + 1 & 0xffff) {
    FUN_004c31b0(fVar5,auStack_70,0x697880,0);
    FUN_004c6c60(&fStack_30,&fStack_20,auStack_70);
    afStack_e0[uVar3 * 7] = fStack_30 * fVar4 + fStack_10 + 0.0;
    afStack_e0[uVar3 * 7 + 1] = fStack_2c * fVar4 + fStack_c + 0.0;
    afStack_e0[uVar3 * 7 + 2] = fStack_28 * fVar4 + fStack_8 + 0.0;
    if (afStack_e0[uVar3 * 7 + 1] < 5.0) {
      afStack_e0[uVar3 * 7 + 1] = 5.0;
    }
    fVar5 = fVar5 + -25.0;
    fVar4 = fVar4 + 25.0;
  }
  return;
}

// FUN_002b3f80 NONMATCHING

void FUN_002b3f80(undefined8 param_1)

{
  undefined4 uVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  undefined1 auStack_90 [28];
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  undefined1 auStack_68 [16];
  float afStack_58 [2];
  float fStack_50;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_8;
  float fStack_4;
  
  iVar2 = (int)param_1;
  uVar1 = *(undefined4 *)(*(int *)(iVar2 + 0xe0) + 0x30);
  fVar3 = (float)FUN_00280870(3,1,&fStack_28,&fStack_4,&fStack_8,1);
  fStack_24 = (fStack_4 - fStack_8) * 0.5 + fStack_8 + 0.0;
  fVar4 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar2 + 0xb8) * 0.5);
  fVar3 = fVar3 / fVar4;
  FUN_00280050(uVar1,afStack_58);
  fStack_38 = afStack_58[0];
  fStack_34 = fStack_24;
  fStack_30 = fStack_50;
  fStack_48 = afStack_58[0] - fStack_28;
  fStack_44 = fStack_24 - fStack_24;
  fStack_40 = fStack_50 - fStack_20;
  fVar4 = (float)FUN_004c69f0(&fStack_48,&fStack_48);
  fVar4 = fGpffff8098 * fVar4;
  fStack_48 = fStack_48 * fVar4;
  fStack_44 = fStack_44 * fVar4;
  fStack_40 = fStack_40 * fVar4;
  fStack_18 = fStack_28 + fStack_48;
  fStack_14 = fStack_24 + fStack_44;
  fStack_10 = fStack_20 + fStack_40;
  fStack_38 = afStack_58[0];
  fStack_34 = fStack_4 * 2.5;
  fStack_30 = fStack_50;
  FUN_004be1e0(&fStack_48,0x6978a0,1,auStack_68);
  fStack_48 = fStack_48 * fVar3;
  fStack_44 = fStack_44 * fVar3;
  fStack_40 = fStack_40 * fVar3;
  fStack_74 = fStack_18 + fStack_48;
  fStack_70 = fStack_14 + fStack_44;
  fStack_6c = fStack_10 + fStack_40;
  return;
}

// FUN_002b41e0 NONMATCHING

void FUN_002b41e0(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  int iStack_6c;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar2 = (int)param_1;
  iVar1 = *(int *)(*(int *)(iVar2 + 0xe0) + 0x30);
  fVar6 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
  FUN_00280050(iVar1,&fStack_40);
  fStack_20 = fStack_d0 - fStack_40;
  fStack_1c = fStack_cc - fStack_3c;
  fStack_18 = fStack_c8 - fStack_38;
  fVar3 = (float)FUN_004c6ac0(&fStack_20);
  fVar4 = (float)FUN_0052e930(*(float *)(iVar2 + 0xb8) * 0.5);
  fVar4 = (fVar6 * 1.5) / fVar4;
  FUN_004be1e0(&fStack_20,0x697890,1,iVar1 + 0x1c);
  fVar6 = fVar6 * 0.5;
  fStack_30 = fStack_40 + fStack_20 * fVar6;
  fStack_2c = fStack_3c + fStack_1c * fVar6;
  fStack_28 = fStack_38 + fStack_18 * fVar6;
  fStack_10 = fStack_20 * fVar4 + fStack_30;
  fStack_8 = fStack_18 * fVar4 + fStack_28;
  fStack_c = DAT_007cad74 * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) +
             fStack_1c * fVar4 + fStack_2c + 0.0;
  fVar4 = (float)FUN_002d1f30(&fStack_c4,&fStack_a8);
  if (DAT_007cadc4 < fVar4) {
    fVar4 = DAT_007cadc4 / fVar4;
    FUN_004be310(&fStack_c4,&fStack_a8,&fStack_90);
    if (fVar4 <= 0.0) {
      fStack_60 = fStack_c4;
      fStack_5c = fStack_c0;
      fStack_58 = fStack_bc;
      fStack_54 = fStack_b8;
    }
    else if (1.0 <= fVar4) {
      fStack_60 = fStack_a8;
      fStack_5c = fStack_a4;
      fStack_58 = fStack_a0;
      fStack_54 = fStack_9c;
    }
    else {
      fVar6 = 1.0 - fVar4;
      if (iStack_6c == 0) {
        fVar6 = fVar6 * fStack_70;
        fVar5 = fVar6 * fVar6;
        fVar6 = fVar5 * fVar6 *
                (fVar5 * (fVar5 * (fVar5 * (fVar5 * (DAT_007cae20 * fVar5 + DAT_007cad38 + 0.0) +
                                           DAT_007cae08 + 0.0) + DAT_007cad40 + 0.0) +
                         DAT_007cad44 + 0.0) + DAT_007cad48 + 0.0) + fVar6 + 0.0;
        fVar4 = fVar4 * fStack_70;
        fVar5 = fVar4 * fVar4;
        fVar4 = fVar5 * fVar4 *
                (fVar5 * (fVar5 * (fVar5 * (fVar5 * (DAT_007cae20 * fVar5 + DAT_007cad38 + 0.0) +
                                           DAT_007cae08 + 0.0) + DAT_007cad40 + 0.0) +
                         DAT_007cad44 + 0.0) + DAT_007cad48 + 0.0) + fVar4 + 0.0;
      }
      fStack_60 = fStack_80 * fVar4 + fStack_90 * fVar6 + 0.0;
      fStack_5c = fStack_7c * fVar4 + fStack_8c * fVar6 + 0.0;
      fStack_58 = fStack_78 * fVar4 + fStack_88 * fVar6 + 0.0;
      fStack_54 = fStack_84 * fVar6 + fStack_74 * fVar4;
    }
    FUN_004be1e0(&fStack_20,0x6978a0,1,&fStack_60);
    fStack_10 = fStack_30 + fStack_20;
    fStack_c = fStack_2c + fStack_1c;
    fStack_8 = fStack_28 + fStack_18;
  }
  fVar4 = 600.0;
  if (600.0 <= fVar3 * 0.5) {
    fVar4 = fVar3 * 0.5;
  }
  FUN_004be1e0(&fStack_20,0x6978a0,1,&fStack_a8);
  fStack_20 = fStack_20 * fVar4;
  fStack_1c = fStack_1c * fVar4;
  fStack_18 = fStack_18 * fVar4;
  fVar3 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar2 + 0xb8) * 0.5);
  fVar3 = fVar4 * fVar3 * 0.21875;
  fStack_48 = fStack_20;
  fStack_44 = fStack_18;
  FUN_004c6b20(&fStack_48,&fStack_48);
  fStack_30 = fStack_44 * fVar3 + fStack_30 + 0.0;
  fStack_28 = (fStack_28 + 0.0) - fStack_48 * fVar3;
  fStack_b4 = fStack_30 + fStack_20;
  fStack_b0 = fStack_2c + fStack_1c;
  fStack_ac = fStack_28 + fStack_18;
  return;
}

// FUN_002b4720

void FUN_002b4720(int param_1)

{
  int iVar1;
  undefined1 auStack_10 [16];
  
  iVar1 = *(int *)(param_1 + 0xe0);
  if ((iVar1 != 0) && ((*(u16 *)(iVar1 + 0x1a) & 1) != 0)) {
    iVar1 = *(int *)(iVar1 + 0x30);
    FUN_0027ffb0(iVar1,auStack_10);
    FUN_002a3e80(*(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) * 0.5f,
                 (u8*)(uintptr_t)*(undefined4 *)(param_1 + 0xe0),
                 (u8*)(uintptr_t)(param_1 + 0x9c),(u8*)auStack_10,0x31);
  }
  return;
}

// FUN_002b47b0 NONMATCHING

void FUN_002b47b0(undefined8 param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar2 = *(int *)((int)param_1 + 0xe0);
  if ((*(u16 *)(iVar2 + 0x1a) & 1) == 0) {
    return;
  }
  iVar2 = *(int *)(iVar2 + 0x30);
  if (*(char *)(iVar2 + 0xa2) != '\x01') {
    return;
  }
  sVar1 = *(short *)(iVar2 + 0x9e0);
  if (sVar1 == 0x11) {
    lVar4 = FUN_0030c3a0(*(undefined4 *)(iVar2 + 0xa2c));
    if (lVar4 != 0) {
      iVar3 = ((u32)*(u16 *)(iVar2 + 0xa4) * 0x12 + (u32)*(u16 *)(iVar2 + 0xa4)) * 4 +
              DAT_007ce404;
      fStack_10 = *(float *)(iVar3 + 0x1c);
      fStack_c = *(float *)(iVar3 + 0x20);
      fStack_8 = *(float *)(iVar3 + 0x24);
      iVar3 = ((u32)*(u16 *)(iVar2 + 0xa4) * 0x12 + (u32)*(u16 *)(iVar2 + 0xa4)) * 4 +
              DAT_007ce404;
      fStack_20 = *(float *)(iVar3 + 0x28);
      fStack_1c = *(float *)(iVar3 + 0x2c);
      fStack_18 = *(float *)(iVar3 + 0x30);
      goto LAB_002b49f8;
    }
  }
  else {
    if (sVar1 == 9) {
      iVar3 = ((u32)*(u16 *)(iVar2 + 0xa4) * 0x12 + (u32)*(u16 *)(iVar2 + 0xa4)) * 4 +
              DAT_007ce404;
      fStack_10 = *(float *)(iVar3 + 0x34);
      fStack_c = *(float *)(iVar3 + 0x38);
      fStack_8 = *(float *)(iVar3 + 0x3c);
      iVar3 = ((u32)*(u16 *)(iVar2 + 0xa4) * 0x12 + (u32)*(u16 *)(iVar2 + 0xa4)) * 4 +
              DAT_007ce404;
      fStack_20 = *(float *)(iVar3 + 0x40);
      fStack_1c = *(float *)(iVar3 + 0x44);
      fStack_18 = *(float *)(iVar3 + 0x48);
      goto LAB_002b49f8;
    }
    if (sVar1 == 3) {
      iVar3 = ((u32)*(u16 *)(iVar2 + 0xa4) * 0x12 + (u32)*(u16 *)(iVar2 + 0xa4)) * 4 +
              DAT_007ce404;
      fStack_10 = *(float *)(iVar3 + 0x1c);
      fStack_c = *(float *)(iVar3 + 0x20);
      fStack_8 = *(float *)(iVar3 + 0x24);
      iVar3 = ((u32)*(u16 *)(iVar2 + 0xa4) * 0x12 + (u32)*(u16 *)(iVar2 + 0xa4)) * 4 +
              DAT_007ce404;
      fStack_20 = *(float *)(iVar3 + 0x28);
      fStack_1c = *(float *)(iVar3 + 0x2c);
      fStack_18 = *(float *)(iVar3 + 0x30);
      goto LAB_002b49f8;
    }
  }
  iVar3 = ((u32)*(u16 *)(iVar2 + 0xa4) * 0x12 + (u32)*(u16 *)(iVar2 + 0xa4)) * 4 +
          DAT_007ce404;
  fStack_10 = *(float *)(iVar3 + 4);
  fStack_c = *(float *)(iVar3 + 8);
  fStack_8 = *(float *)(iVar3 + 0xc);
  iVar3 = ((u32)*(u16 *)(iVar2 + 0xa4) * 0x12 + (u32)*(u16 *)(iVar2 + 0xa4)) * 4 +
          DAT_007ce404;
  fStack_20 = *(float *)(iVar3 + 0x10);
  fStack_1c = *(float *)(iVar3 + 0x14);
  fStack_18 = *(float *)(iVar3 + 0x18);
LAB_002b49f8:
  FUN_004be1e0(&fStack_10,&fStack_10,1,iVar2 + 0x1c);
  FUN_004be1e0(&fStack_20,&fStack_20,1,iVar2 + 0x1c);
  fStack_30 = *(float *)(iVar2 + 4) + fStack_10;
  fStack_2c = *(float *)(iVar2 + 8) + fStack_c;
  fStack_28 = *(float *)(iVar2 + 0xc) + fStack_8;
  fStack_40 = *(float *)(iVar2 + 4) + fStack_20;
  fStack_3c = *(float *)(iVar2 + 8) + fStack_1c;
  fStack_38 = *(float *)(iVar2 + 0xc) + fStack_18;
  fStack_74 = fStack_30;
  fStack_70 = fStack_2c;
  fStack_6c = fStack_28;
  uStack_84 = uStack_68;
  uStack_80 = uStack_64;
  uStack_7c = uStack_60;
  uStack_78 = uStack_5c;
  FUN_004be1e0(&fStack_50,0x6978a0,1,&uStack_68);
  fStack_50 = fStack_50 * 100.0;
  fStack_4c = fStack_4c * 100.0;
  fStack_48 = fStack_48 * 100.0;
  fStack_90 = fStack_74 + fStack_50;
  fStack_8c = fStack_70 + fStack_4c;
  fStack_88 = fStack_6c + fStack_48;
  if (fStack_8c < 25.0) {
    fStack_8c = 25.0;
  }
  return;
}

// FUN_002b4bc0

void FUN_002b4bc0(int param_1)
{
  FUN_002a3e80(0.0f, (u8 *)(uintptr_t)*(int *)(param_1 + 0xe0), 0, 0, 0);
}


// FUN_002B4C00 NONMATCHING
void FUN_002b4c00(int param_1)
{
  struct {
    RwV3d first;
    u8 firstTransform[16];
    RwV3d second;
    u8 secondTransform[16];
  } scratch;

  if (*(int *)(param_1 + 0xd8) == 0) {
    FUN_002a4690(scratch.firstTransform, &D_00694E90, D_00694EB0, &D_00697880);
    scratch.first = D_00694E90;
    FUN_002a4690(scratch.secondTransform, &D_00694ED0, D_00694EF0, &D_00697880);
    scratch.second.x = D_00694ED0.x;
    scratch.second.y = D_00694ED4.x;
    scratch.second.z = D_00694ED8.x;
    FUN_002a2290((u16 *)(iGpffffb6fc + 0x20), &scratch.first, &scratch.second, 1);
    FUN_002a3110(fGpffff813c, (u16 *)(iGpffffb6fc + 0x20));
  } else if (*(int *)(param_1 + 0xd8) == 0x25) {
    FUN_002a4690(scratch.firstTransform, &D_00694E9C, D_00694EBC, &D_00697880);
    scratch.first.x = D_00694E9C.x;
    scratch.first.y = D_00694EA0.x;
    scratch.first.z = D_00694EA4.x;
    FUN_002a4690(scratch.secondTransform, &D_00694EDC, D_00694EFC, &D_00697880);
    scratch.second.x = D_00694EDC.x;
    scratch.second.y = D_00694EE0.x;
    scratch.second.z = D_00694EE4.x;
    FUN_002a2290((u16 *)(iGpffffb6fc + 0x20), &scratch.first, &scratch.second, 1);
    FUN_002a3110(fGpffff80e0, (u16 *)(iGpffffb6fc + 0x20));
  }
}

// FUN_002b4db0 NONMATCHING

void FUN_002b4db0(float param_1)

{
  int iVar1;
  float fVar2;
  undefined1 auStack_80 [64];
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  undefined1 auStack_34 [20];
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined1 auStack_10 [4];
  undefined4 uStack_c;
  
  fVar2 = (float)FUN_00280870(3,0,auStack_10,0,0,1);
  uStack_c = 0;
  FUN_004c31b0(0xc18c0000,auStack_80,0x697870,0);
  iVar1 = (int)(DAT_007ce3ec + 0x20);
  FUN_004c31b0(*(undefined4 *)(iVar1 + 0x100),auStack_80,0x697880,2);
  FUN_004c6c60(&fStack_20,0x697890,auStack_80);
  fStack_38 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar1 + 0xb8) * 0.5);
  fStack_38 = (fVar2 * param_1) / fStack_38;
  fStack_40 = fStack_20 * fStack_38;
  fStack_3c = fStack_1c * fStack_38;
  fStack_38 = fStack_18 * fStack_38;
  if (fStack_3c < 25.0) {
    fStack_3c = 25.0;
  }
  *(float *)(iVar1 + 0x100) = *(float *)(iVar1 + 0x100) + 0.25;
  if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0) {
  }
  return;
}

// FUN_002b4f40 NONMATCHING

void FUN_002b4f40(int param_1)

{
  u32 uVar1;
  float fVar2;
  
  uVar1 = FUN_002ffbc0(0x168);
  if ((long)uVar1 < 0) {
    fVar2 = (float)(uVar1 & 0xffffffff);
  }
  else {
    fVar2 = (float)(int)uVar1;
  }
  *(float *)(param_1 + 0x100) = fVar2;
  return;
}

// FUN_002b4fd0

void FUN_002b4fd0(void)

{
  FUN_002b4db0(DAT_007cad94);
  return;
}

// FUN_002b5000 NONMATCHING

void FUN_002b5000(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined1 auStack_70 [28];
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  undefined1 auStack_48 [24];
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar2 = (int)param_1;
  iVar1 = *(int *)(*(int *)(iVar2 + 0xe0) + 0x30);
  fVar3 = (float)FUN_00280870(3,1,&fStack_10,0,0,1);
  fStack_c = 0.0;
  FUN_00280050(iVar1,&fStack_20);
  fStack_1c = DAT_007cad74 * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) + fStack_1c + 0.0;
  fVar4 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar2 + 0xb8) * 0.5);
  fVar3 = fVar3 / fVar4;
  fStack_30 = fStack_20 - fStack_10;
  fStack_2c = fStack_1c - fStack_c;
  fStack_28 = fStack_18 - fStack_8;
  fVar5 = (float)FUN_004c69f0(&fStack_30,&fStack_30);
  fVar4 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar2 + 0xb8) * 0.5);
  fVar5 = fVar5 + (*(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) * 5.0) / fVar4;
  if (fVar3 <= fVar5) {
    fVar3 = fVar5;
  }
  fStack_30 = fStack_30 * fVar3;
  fStack_2c = fStack_2c * fVar3;
  fStack_28 = fStack_28 * fVar3;
  fStack_54 = fStack_30 + fStack_10;
  fStack_50 = fStack_2c + fStack_c;
  fStack_4c = fStack_28 + fStack_8;
  if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0) {
  }
  return;
}

// FUN_002b5240 NONMATCHING

void FUN_002b5240(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  undefined1 auStack_84 [28];
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar3 = (int)param_1;
  iVar1 = *(int *)(*(int *)(iVar3 + 0xe0) + 0x30);
  uVar2 = *(undefined4 *)(*(int *)(DAT_007ce3ec + 0x148) + 0x30);
  FUN_0027ffb0(iVar1,&fStack_10);
  fVar5 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
  FUN_0027ffb0(uVar2,&fStack_20);
  fStack_30 = fStack_10 - fStack_20;
  fStack_2c = fStack_c - fStack_1c;
  fStack_28 = fStack_8 - fStack_18;
  fVar4 = (float)FUN_004c69f0(&fStack_30,&fStack_30);
  fVar4 = DAT_007cad20 * fVar4;
  fStack_50 = fStack_30 * fVar4 + fStack_20;
  fStack_4c = fStack_2c * fVar4 + fStack_1c;
  fStack_48 = fStack_28 * fVar4 + fStack_18;
  fStack_58 = fStack_8;
  fStack_60 = fStack_10;
  fStack_40 = fStack_10 - fStack_20;
  fStack_3c = fStack_1c - fStack_1c;
  fStack_38 = fStack_8 - fStack_18;
  FUN_004c69f0(&fStack_40,&fStack_40);
  fVar4 = fVar5 * 1.5;
  fStack_60 = (fStack_60 + 0.0) - fStack_38 * fVar4;
  fStack_58 = fStack_40 * fVar4 + fStack_58 + 0.0;
  fStack_5c = DAT_007cad84 * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) + fStack_c + 0.0;
  fVar4 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar3 + 0xb8) * 0.5);
  fVar4 = (fVar5 * 5.0) / fVar4;
  fStack_30 = (fStack_60 + fStack_30 * fVar4) - fStack_50;
  fStack_2c = (fStack_5c + fStack_2c * fVar4) - fStack_4c;
  fStack_28 = (fStack_58 + fStack_28 * fVar4) - fStack_48;
  fVar4 = (float)FUN_004c69f0(&fStack_30,&fStack_30);
  fStack_30 = fStack_30 * fVar4;
  fStack_2c = fStack_2c * fVar4;
  fStack_28 = fStack_28 * fVar4;
  fVar5 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar3 + 0xb8) * 0.5);
  fVar4 = fVar4 * fVar5 * 0.1328125;
  fStack_68 = fStack_30;
  fStack_64 = fStack_28;
  FUN_004c6b20(&fStack_68,&fStack_68);
  fStack_50 = (fStack_50 + 0.0) - fStack_64 * fVar4;
  fStack_48 = fStack_68 * fVar4 + fStack_48 + 0.0;
  fStack_90 = fStack_50 + fStack_30;
  fStack_8c = fStack_4c + fStack_2c;
  fStack_88 = fStack_48 + fStack_28;
  if (fStack_8c < 25.0) {
    fStack_8c = 25.0;
  }
  return;
}

// FUN_002b55d0

void FUN_002b55d0(void)

{
  FUN_00351bb0(8);
  return;
}


// FUN_002b5600
void FUN_002b5600(void* param_1)

{
  u8 auStack_20[32];

  FUN_002add10(param_1,0,0,auStack_20);
  FUN_002a2170((u16*)param_1,auStack_20);
  return;
}

// FUN_002b5650 NONMATCHING

void FUN_002b5650(int param_1)

{
  u32 uVar1;
  float fVar2;
  
  uVar1 = FUN_002ffbc0(0x168);
  if ((long)uVar1 < 0) {
    fVar2 = (float)(uVar1 & 0xffffffff);
  }
  else {
    fVar2 = (float)(int)uVar1;
  }
  *(float *)(param_1 + 0x100) = fVar2;
  return;
}

// FUN_002b56e0 NONMATCHING

void FUN_002b56e0(undefined8 param_1)

{
  int iVar1;
  undefined1 auStack_90 [64];
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  undefined1 auStack_44 [20];
  undefined1 auStack_30 [16];
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar1 = *(int *)(*(int *)(DAT_007ce3ec + 0x148) + 0x30);
  FUN_0027ffb0(iVar1,&fStack_10);
  fStack_c = 0.0;
  FUN_004be1e0(auStack_30,0x697890,1,iVar1 + 0x1c);
  FUN_004c31b0(0xc2520000,auStack_90,0x697880,0);
  FUN_004c6c60(&fStack_20,auStack_30,auStack_90);
  fStack_20 = fStack_20 * 80.0;
  fStack_1c = fStack_1c * 80.0;
  fStack_18 = fStack_18 * 80.0;
  fStack_10 = fStack_10 + fStack_20;
  fStack_c = fStack_c + fStack_1c;
  fStack_8 = fStack_8 + fStack_18;
  FUN_004c31b0(0xc1f00000,auStack_90,0x697870,0);
  iVar1 = (int)param_1;
  FUN_004c31b0(*(undefined4 *)(iVar1 + 0x100),auStack_90,0x697880,2);
  FUN_004c6c60(&fStack_20,0x697890,auStack_90);
  fStack_50 = fStack_20 * 400.0 + fStack_10 + 0.0;
  fStack_4c = fStack_1c * 400.0 + fStack_c + 0.0;
  fStack_48 = fStack_18 * 400.0 + fStack_8 + 0.0;
  if (fStack_4c < 25.0) {
    fStack_4c = 25.0;
  }
  *(float *)(iVar1 + 0x100) = *(float *)(iVar1 + 0x100) + 0.25;
  return;
}

// FUN_002b58f0 NONMATCHING

void FUN_002b58f0(undefined8 param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined1 auStack_a0 [72];
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar1 = *(int *)(*(int *)(DAT_007ce3ec + 0x148) + 0x30);
  fVar3 = (float)FUN_00280870(3,1,&fStack_50,0,0,1);
  fVar2 = 550.0;
  if (550.0 <= fVar3) {
    fVar2 = fVar3;
  }
  FUN_00280050(iVar1,&fStack_10);
  fStack_20 = fStack_10 - fStack_50;
  fStack_1c = fStack_c - fStack_4c;
  fStack_18 = fStack_8 - fStack_48;
  fStack_28 = (float)FUN_004c69f0(&fStack_20,&fStack_20);
  fStack_28 = fStack_28 * 0.25;
  fStack_30 = fStack_20 * fStack_28;
  fStack_2c = fStack_1c * fStack_28;
  fStack_28 = fStack_18 * fStack_28;
  fStack_40 = fStack_50 + fStack_30;
  fStack_3c = fStack_4c + fStack_2c;
  fStack_38 = fStack_48 + fStack_28;
  fVar2 = fVar2 * DAT_007cad6c;
  fVar3 = (float)FUN_0052e930(DAT_007cad60 * *(float *)((int)param_1 + 0xb8) * 0.5);
  fVar3 = fVar2 / fVar3;
  FUN_004c31b0(0x42020000,auStack_a0,0x697870,0);
  FUN_004c6c60(&fStack_30,0x6978a0,auStack_a0);
  FUN_004be1e0(&fStack_20,&fStack_30,1,iVar1 + 0x1c);
  fStack_10 = fStack_20 * fVar2 + fStack_50;
  fStack_c = fStack_1c * fVar2 + fStack_4c;
  fStack_8 = fStack_18 * fVar2 + fStack_48;
  FUN_004be1e0(&fStack_30,0x6978a0,1,&uStack_b8);
  fStack_20 = fStack_30 * fVar3;
  fStack_1c = fStack_2c * fVar3;
  fStack_18 = fStack_28 * fVar3;
  fVar2 = (float)FUN_0052e930(DAT_007cad60 * *(float *)((int)param_1 + 0xb8) * 0.5);
  fVar2 = fVar3 * fVar2 * 0.21875 * DAT_007cad6c;
  fStack_58 = fStack_20;
  fStack_54 = fStack_18;
  FUN_004c6b20(&fStack_58,&fStack_58);
  fStack_40 = fStack_54 * fVar2 + fStack_40 + 0.0;
  fStack_38 = (fStack_38 + 0.0) - fStack_58 * fVar2;
  fStack_c4 = fStack_40 + fStack_20;
  fStack_c0 = fStack_3c + fStack_1c;
  fStack_bc = fStack_38 + fStack_18;
  uStack_d4 = uStack_b8;
  uStack_d0 = uStack_b4;
  uStack_cc = uStack_b0;
  uStack_c8 = uStack_ac;
  fVar3 = fVar3 - 100.0;
  fStack_20 = fStack_30 * fVar3;
  fStack_1c = fStack_2c * fVar3;
  fStack_18 = fStack_28 * fVar3;
  fStack_e0 = fStack_40 + fStack_20;
  fStack_dc = fStack_3c + fStack_1c;
  fStack_d8 = fStack_38 + fStack_18;
  return;
}

// FUN_002b5cd0 NONMATCHING

void FUN_002b5cd0(undefined8 param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined1 auStack_a0 [72];
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar1 = *(int *)(*(int *)(DAT_007ce3ec + 0x148) + 0x30);
  fVar2 = (float)FUN_00280870(2,1,&fStack_50,0,0,1);
  FUN_00280050(iVar1,&fStack_10);
  fStack_20 = fStack_10 - fStack_50;
  fStack_1c = fStack_c - fStack_4c;
  fStack_18 = fStack_8 - fStack_48;
  fStack_28 = (float)FUN_004c69f0(&fStack_20,&fStack_20);
  fStack_28 = DAT_007cada4 * fStack_28;
  fStack_30 = fStack_20 * fStack_28;
  fStack_2c = fStack_1c * fStack_28;
  fStack_28 = fStack_18 * fStack_28;
  fStack_40 = fStack_50 + fStack_30;
  fStack_3c = fStack_4c + fStack_2c;
  fStack_38 = fStack_48 + fStack_28;
  fStack_8 = 450.0;
  if (450.0 <= fVar2) {
    fStack_8 = fVar2;
  }
  fVar2 = (float)FUN_0052e930(DAT_007cad60 * *(float *)((int)param_1 + 0xb8) * 0.5);
  fVar2 = fStack_8 / fVar2;
  FUN_004c31b0(0x420c0000,auStack_a0,0x697870,0);
  FUN_004c6c60(&fStack_30,0x6978a0,auStack_a0);
  FUN_004be1e0(&fStack_20,&fStack_30,1,iVar1 + 0x1c);
  fStack_10 = fStack_20 * fStack_8;
  fStack_c = fStack_1c * fStack_8;
  fStack_8 = fStack_18 * fStack_8;
  FUN_004be1e0(&fStack_30,0x6978a0,1,&uStack_b8);
  fStack_18 = fVar2 + 50.0;
  fStack_20 = fStack_30 * fStack_18;
  fStack_1c = fStack_2c * fStack_18;
  fStack_18 = fStack_28 * fStack_18;
  fVar3 = (float)FUN_0052e930(DAT_007cad60 * *(float *)((int)param_1 + 0xb8) * 0.5);
  fVar3 = fVar2 * fVar3 * 0.21875 * DAT_007cad6c;
  fStack_58 = fStack_20;
  fStack_54 = fStack_18;
  FUN_004c6b20(&fStack_58,&fStack_58);
  fStack_40 = fStack_54 * fVar3 + fStack_40 + 0.0;
  fStack_38 = (fStack_38 + 0.0) - fStack_58 * fVar3;
  fStack_c4 = fStack_40 + fStack_20;
  fStack_c0 = fStack_3c + fStack_1c;
  fStack_bc = fStack_38 + fStack_18;
  uStack_d4 = uStack_b8;
  uStack_d0 = uStack_b4;
  uStack_cc = uStack_b0;
  uStack_c8 = uStack_ac;
  fVar2 = fVar2 - 50.0;
  fStack_20 = fStack_30 * fVar2;
  fStack_1c = fStack_2c * fVar2;
  fStack_18 = fStack_28 * fVar2;
  fStack_e0 = fStack_40 + fStack_20;
  fStack_dc = fStack_3c + fStack_1c;
  fStack_d8 = fStack_38 + fStack_18;
  return;
}

// FUN_002b6070 NONMATCHING

void FUN_002b6070(float param_1,float param_2)

{
  int iVar1;
  long lVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  undefined1 auStack_a4 [16];
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  undefined1 auStack_88 [24];
  undefined1 auStack_70 [64];
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar3 = (int)(DAT_007ce3ec + 0x20);
  iVar1 = *(int *)(*(int *)(iVar3 + 0xe0) + 0x30);
  lVar2 = FUN_00300580(*(undefined4 *)(iVar1 + 0xa2c),0x100000);
  FUN_00280130(iVar1,&fStack_30);
  if (lVar2 == 0) {
    fStack_2c = DAT_007cad5c * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) + fStack_2c + 0.0
    ;
  }
  else {
    fStack_2c = (fStack_2c + 0.0) -
                DAT_007cad5c * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c);
  }
  FUN_004be1e0(&fStack_20,0x697890,1,iVar1 + 0x1c);
  fStack_10 = fStack_20 * 200.0;
  fStack_c = fStack_1c * 200.0;
  fStack_8 = fStack_18 * 200.0;
  fStack_20 = (fStack_30 + fStack_10) - fStack_30;
  fStack_1c = (fStack_2c + fStack_c + 75.0) - fStack_2c;
  fStack_18 = (fStack_28 + fStack_8) - fStack_28;
  FUN_004c69f0(&fStack_20,&fStack_20);
  fVar4 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
  fVar6 = 75.0;
  if (75.0 <= fVar4) {
    fVar6 = fVar4;
  }
  param_2 = fVar6 * param_2;
  lVar2 = FUN_002ffbc0(2);
  if ((lVar2 == 1) || (lVar2 != 0)) {
    fVar4 = -30.0;
  }
  else {
    fVar4 = 30.0;
  }
  FUN_004c31b0(-fVar4 * 0.5,auStack_70,0x697880,0);
  FUN_004c6c60(&fStack_10,&fStack_20,auStack_70);
  fVar5 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar3 + 0xb8) * 0.5);
  fVar5 = (fVar6 * param_1) / fVar5;
  fStack_10 = fStack_10 * fVar5;
  fStack_c = fStack_c * fVar5;
  fStack_8 = fStack_8 * fVar5;
  fStack_b0 = fStack_30 + fStack_10;
  fStack_ac = fStack_2c + fStack_c;
  fStack_a8 = fStack_28 + fStack_8;
  FUN_004c31b0(fVar4 * 0.5,auStack_70,0x697880,0);
  FUN_004c6c60(&fStack_10,&fStack_20,auStack_70);
  fVar6 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar3 + 0xb8) * 0.5);
  param_2 = param_2 / fVar6;
  fStack_10 = fStack_10 * param_2;
  fStack_c = fStack_c * param_2;
  fStack_8 = fStack_8 * param_2;
  fStack_94 = fStack_30 + fStack_10;
  fStack_90 = fStack_2c + fStack_c;
  fStack_8c = fStack_28 + fStack_8;
  if (fStack_ac < 25.0) {
    fStack_ac = 25.0;
  }
  if (fStack_90 < 25.0) {
    fStack_90 = 25.0;
  }
  return;
}

// FUN_002b6460

void FUN_002b6460(void)

{
  FUN_002b6070(DAT_007cad64,DAT_007cad68);
  return;
}

// FUN_002b6490

void FUN_002b6490(void)

{
  FUN_00521250(DAT_00694c90,DAT_006941d4,0xf4);
  return;
}

// FUN_002b64d0 NONMATCHING


u32 FUN_002b64d0(int param_1, int param_2)

{
  short sVar1;
  u16 *puVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  short sVar6;
  int *piVar7;
  float fVar8;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  float fStack_134;
  float fStack_130;
  float fStack_12c;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_114;
  float fStack_110;
  float fStack_10c;
  undefined1 auStack_100 [16];
  undefined1 auStack_f0 [64];
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  undefined1 auStack_a4 [16];
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  undefined1 auStack_88 [24];
  undefined1 auStack_70 [16];
  undefined1 auStack_60 [16];
  undefined8 uStack_50;
  undefined4 uStack_48;
  float fStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  float fStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  lVar5 = FUN_002b6bd0(param_2);
  if (lVar5 == 0) {
    uVar4 = 0;
  }
  else {
    piVar7 = (int *)param_2;
    puVar2 = (u16 *)piVar7[4];
    sVar1 = *(short *)((int)piVar7 + 10);
    if (puVar2 == (u16 *)0x0) {
      uVar4 = 0;
    }
    else if (sVar1 < 4) {
      if ((sVar1 == -1) ||
         ((long)(short)puVar2[sVar1 * 0x1e + 2] <= (long)(u32)*(u16 *)(piVar7 + 3))) {
        sVar6 = sVar1 + 1;
        if ((((long)sVar6 < (long)(u32)*puVar2) &&
            (((*piVar7 != 0 && (lVar5 = FUN_0029a1d0(*(undefined4 *)(*piVar7 + 0x30)), lVar5 != 0))
             && (piVar7[1] != 0)))) &&
           (lVar5 = FUN_0029a1d0(*(undefined4 *)(piVar7[1] + 0x30)), lVar5 != 0)) {
          if ((*(u16 *)((int)piVar7 + 0xe) & 0x10) == 0) {
            FUN_002d1de0(auStack_100,*(int *)(*piVar7 + 0x30) + 4,*(int *)(piVar7[1] + 0x30) + 4);
          }
          else {
            FUN_002802d0(*(undefined4 *)(*piVar7 + 0x30),*(undefined4 *)(piVar7[1] + 0x30),
                         auStack_60);
            FUN_002802d0(*(undefined4 *)(piVar7[1] + 0x30),*(undefined4 *)(*piVar7 + 0x30),
                         auStack_70);
            FUN_002d1de0(auStack_100,auStack_60,auStack_70);
          }
          fStack_30 = *(float *)(puVar2 + sVar6 * 0x1e + 4);
          uStack_2c = *(undefined4 *)(puVar2 + sVar6 * 0x1e + 6);
          uStack_28 = *(undefined4 *)(puVar2 + sVar6 * 0x1e + 8);
          fStack_40 = *(float *)(puVar2 + sVar6 * 0x1e + 10);
          uStack_3c = *(undefined4 *)(puVar2 + sVar6 * 0x1e + 0xc);
          uStack_38 = *(undefined4 *)(puVar2 + sVar6 * 0x1e + 0xe);
          if ((*(u16 *)((int)piVar7 + 0xe) & 2) != 0) {
            fStack_30 = fStack_30 * -1.0;
            fStack_40 = fStack_40 * -1.0;
          }
          if (puVar2[sVar6 * 0x1e + 3] == 1) {
            iVar3 = *(int *)(*piVar7 + 0x30);
            FUN_004be1e0(&fStack_120,&fStack_30,1,auStack_100);
            FUN_004be1e0(&fStack_114,&fStack_40,1,auStack_100);
            fStack_b0 = *(float *)(iVar3 + 4) + fStack_120;
            fStack_ac = *(float *)(iVar3 + 8) + fStack_11c;
            fStack_a8 = *(float *)(iVar3 + 0xc) + fStack_118;
            fStack_94 = *(float *)(iVar3 + 4) + fStack_114;
            fStack_90 = *(float *)(iVar3 + 8) + fStack_110;
            fStack_8c = *(float *)(iVar3 + 0xc) + fStack_10c;
          }
          fStack_30 = *(float *)(puVar2 + sVar6 * 0x1e + 0x12);
          uStack_2c = *(undefined4 *)(puVar2 + sVar6 * 0x1e + 0x14);
          uStack_28 = *(undefined4 *)(puVar2 + sVar6 * 0x1e + 0x16);
          fStack_40 = *(float *)(puVar2 + sVar6 * 0x1e + 0x18);
          uStack_3c = *(undefined4 *)(puVar2 + sVar6 * 0x1e + 0x1a);
          uStack_38 = *(undefined4 *)(puVar2 + sVar6 * 0x1e + 0x1c);
          if ((*(u16 *)((int)piVar7 + 0xe) & 2) != 0) {
            fStack_30 = fStack_30 * -1.0;
            fStack_40 = fStack_40 * -1.0;
          }
          if (puVar2[sVar6 * 0x1e + 0x10] == 2) {
            iVar3 = *(int *)(piVar7[1] + 0x30);
            lVar5 = (long)(uintptr_t)func_002fc520(
                (BtlUnit*)(uintptr_t)iVar3);
            if (lVar5 == 0) {
              FUN_00280130(iVar3,&fStack_20);
              FUN_004be1e0(&fStack_10,0x6978a0,1,auStack_100);
              fVar8 = *(float *)(iVar3 + 0x90) * *(float *)(iVar3 + 0x2c);
              fStack_140 = fStack_20 + fStack_10 * fVar8;
              fStack_13c = fStack_1c + fStack_c * fVar8;
              fStack_138 = fStack_18 + fStack_8 * fVar8;
            }
            else {
              FUN_00280200(iVar3,lVar5,&fStack_20);
              FUN_004be1e0(&fStack_10,0x6978a0,1,auStack_100);
              fVar8 = (float)*(u16 *)((int)lVar5 + 8) * *(float *)(iVar3 + 0x2c);
              fStack_140 = fStack_20 + fStack_10 * fVar8;
              fStack_13c = fStack_1c + fStack_c * fVar8;
              fStack_138 = fStack_18 + fStack_8 * fVar8;
            }
            if (fStack_13c < 100.0) {
              fStack_13c = 100.0;
            }
            else if ((*(u16 *)((int)piVar7 + 0xe) & 8) == 0) {
              if (((*(u16 *)((int)piVar7 + 0xe) & 4) != 0) && (150.0 < fStack_13c)) {
                fStack_13c = 150.0;
              }
            }
            else if (250.0 < fStack_13c) {
              fStack_13c = 250.0;
            }
            fStack_134 = fStack_140;
            fStack_130 = fStack_13c;
            fStack_12c = fStack_138;
          }
          else if (puVar2[sVar6 * 0x1e + 0x10] == 1) {
            iVar3 = *(int *)(*piVar7 + 0x30);
            FUN_004be1e0(&fStack_120,&fStack_30,1,auStack_100);
            FUN_004be1e0(&fStack_114,&fStack_40,1,auStack_100);
            fStack_140 = *(float *)(iVar3 + 4) + fStack_120;
            fStack_13c = *(float *)(iVar3 + 8) + fStack_11c;
            fStack_138 = *(float *)(iVar3 + 0xc) + fStack_118;
            fStack_134 = *(float *)(iVar3 + 4) + fStack_114;
            fStack_130 = *(float *)(iVar3 + 8) + fStack_110;
            fStack_12c = *(float *)(iVar3 + 0xc) + fStack_10c;
          }
          if (*(float *)(puVar2 + sVar6 * 0x1e + 0x1e) == 0.0) {
            uStack_50 = DAT_00697880;
            uStack_48 = DAT_00697888;
          }
          else {
            FUN_004c31b0(auStack_f0,0x697890,0);
            FUN_004c6c60(&uStack_50,0x697880,auStack_f0);
          }
          *(short *)((int)piVar7 + 10) = sVar1 + 1;
          *(undefined2 *)(piVar7 + 3) = 0;
        }
        else {
          *(u16 *)((int)piVar7 + 0xe) = *(u16 *)((int)piVar7 + 0xe) & 0xfffe;
        }
      }
      else {
        *(u16 *)(piVar7 + 3) = *(u16 *)(piVar7 + 3) + 1;
      }
      *(short *)(piVar7 + 2) = (short)piVar7[2] + 1;
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
  }
  return uVar4;
}

// FUN_002b6bd0

u32 FUN_002b6bd0(int param_1)

{
  return (*(u16 *)(param_1 + 0xe) & 1) != 0;
}

// FUN_002b6bf0 NONMATCHING

void FUN_002b6bf0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,u32 param_4,
                 u32 param_5)

{
  u32 uVar1;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[4] = param_4;
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined2 *)((int)param_1 + 10) = 0xffff;
  *(undefined2 *)(param_1 + 3) = 0;
  *(u16 *)((int)param_1 + 0xe) = *(u16 *)((int)param_1 + 0xe) | 1;
  *(u16 *)((int)param_1 + 0xe) = *(u16 *)((int)param_1 + 0xe) & 0xfffd;
  if (((param_5 & 1) != 0) && (uVar1 = FUN_002ffbc0(100), 0x31 < uVar1)) {
    *(u16 *)((int)param_1 + 0xe) = *(u16 *)((int)param_1 + 0xe) | 2;
  }
  if ((param_5 & 2) != 0) {
    *(u16 *)((int)param_1 + 0xe) = *(u16 *)((int)param_1 + 0xe) | 4;
  }
  if ((param_5 & 4) != 0) {
    *(u16 *)((int)param_1 + 0xe) = *(u16 *)((int)param_1 + 0xe) | 8;
  }
  if ((param_5 & 8) != 0) {
    *(u16 *)((int)param_1 + 0xe) = *(u16 *)((int)param_1 + 0xe) | 0x10;
  }
  return;
}

// FUN_002b6cd0
u8* FUN_002b6cd0(int param_1)
{
  u16 *puVar1;
  short sVar2;
  u16 counter;
  short frame;

  if ((*(u16 *)(param_1 + 0xe) & 1) == 0) {
    puVar1 = (u16 *)0x0;
  }
  else {
    puVar1 = *(u16 **)(param_1 + 0x10);
    sVar2 = *(short *)(param_1 + 10);
    if (puVar1 == (u16 *)0x0) {
      puVar1 = (u16 *)0x0;
    }
    else {
      if (sVar2 == -1) {
        goto increment_index;
      }
      counter = *(u16 *)(param_1 + 0xc);
      frame = puVar1[sVar2 * 0x1e + 2];
      if (counter < frame) {
        goto after_increment;
      }
increment_index:
      sVar2++;
after_increment:
      if (*puVar1 > sVar2) {
        goto check_index;
      }
      puVar1 = (u16 *)0x0;
      goto done;
check_index:
      if (sVar2 < 4) {
        goto make_pointer;
      }
      puVar1 = (u16 *)0x0;
      goto done;
make_pointer:
      puVar1 = puVar1 + sVar2 * 0x1e + 2;
done:
      ;
    }
  }
  return (u8*)puVar1;
}

// FUN_002b6db0

void FUN_002b6db0(undefined8 param_1)

{
  FUN_00521408(param_1,0,0x14);
  return;
}

// FUN_002b6de0 NONMATCHING

void FUN_002b6de0(unsigned short *param_1)

{
  long lVar1;
  int iVar2;
  short *psVar3;
  float fVar4;
  float fVar5;
  
  FUN_00521408(param_1,0,8);
  for (iVar2 = *(int *)(DAT_007ce3ec + 0x15c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa30)) {
    lVar1 = FUN_0030b5a0(*(undefined4 *)(iVar2 + 0xa2c),0);
    if (lVar1 == 0) {
      fVar4 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c);
      fVar5 = *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c);
      psVar3 = (short *)param_1;
      if (fVar5 <= 200.0) {
        if (fVar4 <= 75.0) {
          *psVar3 = *psVar3 + 1;
        }
        else if (fVar4 <= 125.0) {
          psVar3[1] = psVar3[1] + 1;
        }
        else if (fVar4 <= 200.0) {
          psVar3[2] = psVar3[2] + 1;
        }
      }
      else if (fVar5 <= 300.0) {
        if (fVar4 <= 125.0) {
          psVar3[1] = psVar3[1] + 1;
        }
        else if (fVar4 <= 200.0) {
          psVar3[2] = psVar3[2] + 1;
        }
      }
      else {
        psVar3[2] = psVar3[2] + 1;
      }
      psVar3[3] = psVar3[3] + 1;
    }
  }
  return;
}

// FUN_002b6f70 NONMATCHING

u32 FUN_002b6f70(u16 *param_1)

{
  u32 uVar1;
  int iVar2;
  
  uVar1 = 0;
  while( 1 ) {
    if (0x17 < uVar1) {
      return 0x17;
    }
    iVar2 = uVar1 * 0xe0;
    if (((*param_1 <= *(u16 *)(&DAT_00694fe8 + iVar2)) &&
        (param_1[1] <= *(u16 *)(&DAT_00694fea + iVar2))) &&
       (param_1[2] <= *(u16 *)(&DAT_00694fec + iVar2))) break;
    uVar1 = uVar1 + 1 & 0xffff;
  }
  return uVar1;
}

// FUN_002b7000
void FUN_002b7000(int param_1,u32 param_2,undefined4 param_3)
{
  u8 mode = *(u8 *)(param_1 + 0xa2);
  volatile u8 *table;
  switch (mode) {
  case 0:
    table = DAT_007ce3ec;
    *(undefined4 *)((volatile u8 *)(uintptr_t)((param_2 & 0xffff) * 4) +
                    (uintptr_t)table + 0xa3c) = param_3;
    break;
  case 1:
    table = DAT_007ce3ec;
    *(undefined4 *)((volatile u8 *)(uintptr_t)((param_2 & 0xffff) * 4) +
                    (uintptr_t)table + 0xa4c) = param_3;
    break;
  }
}

// FUN_002b7060 NONMATCHING

u32 FUN_002b7060(void)

{
  undefined2 uVar1;
  int iVar2;
  long lVar3;
  u32 uVar4;
  undefined1 auStack_110 [264];
  u16 uStack_8;
  u16 uStack_6;
  u16 uStack_4;
  
  lVar3 = FUN_002fa240();
  if (lVar3 == 1) {
    uVar1 = 0xffff;
  }
  else {
    FUN_002b6de0(&uStack_8);
    if (((3 < uStack_4) || ((uStack_4 == 3 && ((uStack_6 != 0 || (uStack_8 != 0)))))) ||
       ((uStack_4 == 2 && ((1 < uStack_6 || (2 < uStack_8)))))) {
      FUN_00523ac8(auStack_110,0x696410,*(undefined2 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8),uStack_4
                   ,uStack_6,uStack_8);
      FUN_0019d400(auStack_110,0x696430,0x16e);
    }
    for (uVar4 = 0; uVar4 < 0x18; uVar4 = uVar4 + 1 & 0xffff) {
      iVar2 = uVar4 * 0xe0;
      if (((uStack_8 <= *(u16 *)(&DAT_00694fe8 + iVar2)) &&
          (uStack_6 <= *(u16 *)(&DAT_00694fea + iVar2))) &&
         (uStack_4 <= *(u16 *)(&DAT_00694fec + iVar2))) goto LAB_002b71bc;
    }
    uVar4 = 0x17;
LAB_002b71bc:
    uVar1 = (undefined2)uVar4;
  }
  return uVar1;
}

// FUN_002b71e0 NONMATCHING

void FUN_002b71e0(void)

{
  int iVar1;
  short sVar2;
  u16 uVar3;
  u16 uVar4;
  undefined2 uVar5;
  int iVar6;
  long lVar7;
  u32 uVar8;
  u32 uVar9;
  int iVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  undefined1 auStack_160 [256];
  undefined1 auStack_60 [16];
  int aiStack_50 [6];
  u16 uStack_38;
  u16 uStack_36;
  u16 uStack_34;
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [16];
  float afStack_10 [4];
  
  afStack_10[1] = 0.0;
  *(undefined2 *)(DAT_007ce3ec + 0xa38) = 0xffff;
  lVar7 = FUN_002fa240();
  if (lVar7 == 1) {
    sVar2 = -1;
  }
  else {
    FUN_002b6de0(&uStack_38);
    if (((3 < uStack_34) || ((uStack_34 == 3 && ((uStack_36 != 0 || (uStack_38 != 0)))))) ||
       ((uStack_34 == 2 && ((1 < uStack_36 || (2 < uStack_38)))))) {
      FUN_00523ac8(auStack_160,0x696410,*(undefined2 *)(*(int *)(DAT_007ce3ec + 0xbbc) + 8),
                   uStack_34,uStack_36,uStack_38);
      FUN_0019d400(auStack_160,0x696430,0x16e);
    }
    sVar2 = FUN_002b6f70(&uStack_38);
  }
  if (sVar2 != -1) {
    FUN_00521408(DAT_007ce3ec + 0xa3c,0,0x24);
    iVar10 = sVar2 * 0xe0 + 0x694f10;
    uVar3 = 1;
    for (iVar1 = *(int *)(DAT_007ce3ec + 0x150); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34)) {
      if (*(int *)(*(int *)(DAT_007ce3ec + 0x148) + 0x30) == iVar1) {
        uVar4 = uVar3;
        uVar3 = 0;
      }
      else {
        for (; (*(char *)(iVar10 + (u32)uVar3 * 0x18) == '\0' && (uVar3 < 4)); uVar3 = uVar3 + 1) {
        }
        uVar4 = uVar3 + 1;
      }
      uVar9 = (u32)uVar3;
      iVar6 = iVar10 + uVar9 * 0x18;
      afStack_10[0] = *(float *)(iVar6 + 4);
      afStack_10[2] = *(float *)(iVar6 + 8);
      FUN_002d2280(iVar1 + 0x94,iVar1 + 0x96,afStack_10);
      afStack_10[0] = (float)(*(short *)(iVar1 + 0x94) * 0x19 + -0x6d6);
      afStack_10[2] = (float)(*(short *)(iVar1 + 0x96) * 0x19 + -0x6d6);
      FUN_0027f650(iVar1,afStack_10);
      if (*(char *)(iVar1 + 0xa2) == '\x01') {
        *(undefined4 *)(DAT_007ce3ec + uVar9 * 4 + 0xa4c) = 1;
      }
      else if (*(char *)(iVar1 + 0xa2) == '\0') {
        *(undefined4 *)(DAT_007ce3ec + uVar9 * 4 + 0xa3c) = 1;
      }
      *(char *)(iVar1 + 0x9f0) = (char)uVar3;
      uVar3 = uVar4;
    }
    iVar1 = *(int *)(DAT_007ce3ec + 0x158);
    FUN_00521408(aiStack_50,0,0x14);
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34)) {
      lVar7 = FUN_0030b5a0(*(undefined4 *)(iVar1 + 0xa2c),0);
      if (lVar7 == 0) {
        uVar9 = 5;
        fVar13 = 1e+08;
        fVar14 = fVar13;
        for (uVar8 = 0; uVar8 < 5; uVar8 = uVar8 + 1 & 0xffff) {
          if ((aiStack_50[uVar8] != 1) &&
             (iVar6 = iVar10 + uVar8 * 0x18, *(char *)(iVar6 + 0x60) != '\0')) {
            fVar11 = *(float *)(iVar6 + 0x70) - *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
            fVar12 = *(float *)(iVar6 + 0x74) - *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c);
            if ((fVar11 < fVar13) || (fVar12 < fVar14)) {
              fVar13 = fVar11;
              fVar14 = fVar12;
              uVar9 = uVar8;
            }
          }
        }
        aiStack_50[uVar9] = 1;
        iVar6 = iVar10 + uVar9 * 0x18;
        afStack_10[0] = *(float *)(iVar6 + 100);
        afStack_10[2] = *(float *)(iVar6 + 0x68);
        FUN_002d2280(iVar1 + 0x94,iVar1 + 0x96,afStack_10);
        afStack_10[0] = (float)(*(short *)(iVar1 + 0x94) * 0x19 + -0x6d6);
        afStack_10[2] = (float)(*(short *)(iVar1 + 0x96) * 0x19 + -0x6d6);
        FUN_0027f650(iVar1,afStack_10);
        if (*(char *)(iVar1 + 0xa2) == '\x01') {
          *(undefined4 *)(DAT_007ce3ec + uVar9 * 4 + 0xa4c) = 1;
        }
        else if (*(char *)(iVar1 + 0xa2) == '\0') {
          *(undefined4 *)(DAT_007ce3ec + uVar9 * 4 + 0xa3c) = 1;
        }
        *(char *)(iVar1 + 0x9f0) = (char)uVar9;
      }
    }
    FUN_00280870(2,1,auStack_30,0,0,1);
    FUN_0027ffb0(*(undefined4 *)(*(int *)(DAT_007ce3ec + 0x148) + 0x30),auStack_20);
    for (iVar1 = *(int *)(DAT_007ce3ec + 0x154); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa30)) {
      FUN_0027ffb0(iVar1,afStack_10);
      FUN_002d1de0(auStack_60,afStack_10,auStack_30);
      FUN_0027f680(iVar1,auStack_60);
    }
    for (iVar1 = *(int *)(DAT_007ce3ec + 0x15c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa30)) {
      FUN_0027ffb0(iVar1,afStack_10);
      FUN_002d1de0(auStack_60,afStack_10,auStack_20);
      FUN_0027f680(iVar1,auStack_60);
    }
    *(short *)(DAT_007ce3ec + 0xa38) = sVar2;
    uVar5 = FUN_002d4e10(2,0x80000);
    *(undefined2 *)(DAT_007ce3ec + 0xa3a) = uVar5;
  }
  return;
}

// FUN_002b77c0 NONMATCHING


void FUN_002b77c0(undefined8 param_1)

{
  int iVar1;
  int iVar2;
  u16 uVar3;
  u32 uVar4;
  undefined1 auStack_30 [16];
  undefined1 auStack_20 [16];
  undefined4 auStack_10 [2];
  undefined4 uStack_8;
  
  iVar2 = (int)param_1;
  if (*(char *)(iVar2 + 0x9f0) < '\0') {
    if ((*(char *)(iVar2 + 0xa2) != '\x01') && (*(char *)(iVar2 + 0xa2) == '\0')) {
      for (uVar3 = 0;
          ((uVar4 = (u32)uVar3,
           *(char *)((u32)*(u16 *)(DAT_007ce3ec + 0xa38) * 0xe0 + 0x694f10 + uVar4 * 0x18) ==
           '\0' || (*(int *)(DAT_007ce3ec + uVar4 * 4 + 0xa3c) == 1)) && (uVar3 < 4));
          uVar3 = uVar3 + 1) {
      }
      iVar1 = (u32)*(u16 *)(DAT_007ce3ec + 0xa38) * 0xe0;
      auStack_10[0] = *(undefined4 *)((u32)uVar3 * 0x18 + iVar1 + 0x694f14);
      uStack_8 = *(undefined4 *)((u32)uVar3 * 0x18 + iVar1 + 0x694f18);
      FUN_002d2280(iVar2 + 0x94,iVar2 + 0x96,auStack_10);
      FUN_0027f650(param_1,auStack_10);
      if (*(char *)(iVar2 + 0xa2) == '\x01') {
        *(undefined4 *)(uVar4 * 4 + DAT_007ce3ec + 0xa4c) = 1;
      }
      else if (*(char *)(iVar2 + 0xa2) == '\0') {
        *(undefined4 *)(uVar4 * 4 + DAT_007ce3ec + 0xa3c) = 1;
      }
      *(char *)(iVar2 + 0x9f0) = (char)uVar3;
      FUN_00280870(2,1,auStack_20,0,0,1);
      FUN_0027ffb0(param_1,auStack_10);
      FUN_002d1de0(auStack_30,auStack_10,auStack_20);
      FUN_0027f680(param_1,auStack_30);
    }
  }
  return;
}

// FUN_002b79e0 NONMATCHING

undefined4 FUN_002b79e0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float afStack_30 [2];
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar1 = *param_1;
  iVar2 = param_1[1];
  FUN_00280390(iVar2,iVar1,afStack_30);
  fStack_10 = *(float *)(iVar1 + 4) - afStack_30[0];
  fStack_c = 0.0;
  fStack_8 = *(float *)(iVar1 + 0xc) - fStack_28;
  FUN_004c69f0(&fStack_10,&fStack_10);
  if ((fStack_10 != 0.0) || (fStack_8 != 0.0)) {
    fVar4 = ((float)param_1[2] + 0.0) - (float)(int)*(short *)(iVar3 + 4) * *(float *)(iVar2 + 0x2c)
    ;
    fStack_10 = fStack_10 * fVar4;
    fStack_c = fStack_c * fVar4;
    fStack_8 = fStack_8 * fVar4;
    if ((*(u16 *)(param_1 + 3) & 1) != 0) {
      fStack_20 = *(float *)(iVar1 + 4) + fStack_10;
      fStack_1c = *(float *)(iVar1 + 8) + fStack_c;
      fStack_18 = *(float *)(iVar1 + 0xc) + fStack_8;
      FUN_0027f650(iVar1,&fStack_20);
      iVar1 = *(int *)(iVar1 + 0xa00);
      if (iVar1 != 0) {
        fStack_20 = *(float *)(iVar1 + 4) + fStack_10;
        fStack_1c = *(float *)(iVar1 + 8) + fStack_c;
        fStack_18 = *(float *)(iVar1 + 0xc) + fStack_8;
        FUN_0027f650(iVar1,&fStack_20);
      }
    }
    if ((*(u16 *)(param_1 + 3) & 2) != 0) {
      fStack_20 = *(float *)(iVar2 + 4) + fStack_10;
      fStack_1c = *(float *)(iVar2 + 8) + fStack_c;
      fStack_18 = *(float *)(iVar2 + 0xc) + fStack_8;
      FUN_0027f650(iVar2,&fStack_20);
    }
  }
  return 1;
}

// FUN_002b7bd0

void FUN_002b7bd0(u32 param_1,u32 param_2,float param_3,u16 param_4)
{
  u32 *work;
  u32 packet;

  packet = FUN_0027ec10(0xb00,0x10);
  *(code **)(packet + 0x6c) = (code *)FUN_002b79e0;
  work = *(u32 **)(packet + 0x78);
  work[0] = param_1;
  work[1] = param_2;
  *(float *)(work + 2) = param_3;
  *(u16 *)(work + 3) = param_4;
}

// FUN_002b7c50 NONMATCHING

u32 FUN_002b7c50(int *param_1)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int bVar6;
  undefined2 uVar7;
  short sVar8;
  long lVar9;
  u32 uVar10;
  long unaff_s5;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  undefined1 auStack_b0 [16];
  float fStack_a0;
  float fStack_9c;
  undefined4 uStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  undefined8 uStack_80;
  float fStack_78;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  undefined1 auStack_30 [8];
  float fStack_28;
  undefined8 uStack_20;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar3 = *param_1;
  uVar2 = *(undefined2 *)(iVar3 + 0x6e);
  cVar1 = *(char *)(*(int *)(iVar3 + 0x30) + 0xa2);
  if (cVar1 == '\x01') {
    if (((*(short *)(iVar3 + 0x6a) != 1) && ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0)) &&
       (sVar8 = FUN_002d1600(iVar3 + 0x38), sVar8 == 1)) {
      bVar6 = 0;
      iVar4 = *(int *)(iVar3 + 0x30);
      FUN_0027ffb0(iVar4,&fStack_10);
      fVar14 = *(float *)(iVar4 + 0x90) * *(float *)(iVar4 + 0x2c);
      if (param_1[2] == 1) {
        FUN_00280870(1,1,&uStack_20,0,0,1);
        fVar11 = 0.0;
        for (uVar10 = 0; uVar10 < *(u16 *)(iVar3 + 0x6a); uVar10 = uVar10 + 1 & 0xffff) {
          iVar5 = *(int *)(iVar3 + uVar10 * 4 + 0x38);
          if ((*(u16 *)(iVar5 + 0x1a) & 1) != 0) {
            FUN_00280050(*(undefined4 *)(iVar5 + 0x30),&fStack_70);
            fStack_40 = (float)uStack_20 - fStack_70;
            fStack_3c = (float)(uStack_20 >> 32) - fStack_6c;
            fStack_38 = fStack_18 - fStack_68;
            fVar15 = (float)FUN_004c6ac0(&fStack_40);
            if (fVar11 < fVar15) {
              fStack_28 = fStack_68;
              fVar11 = fVar15;
            }
          }
        }
        FUN_002d1de0(auStack_b0,&fStack_10,auStack_30);
        FUN_0027f680(iVar4,auStack_b0);
        FUN_002812b0(iVar4);
      }
      for (iVar3 = *(int *)(DAT_007ce3ec + 0x154); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xa30)) {
        if ((*(u32 *)(iVar3 + 0x9c) & 8) != 0) {
          FUN_002802d0(iVar3,iVar4,&uStack_20);
          fStack_40 = (float)uStack_20 - fStack_10;
          fStack_38 = fStack_18 - fStack_8;
          fStack_3c = 0.0;
          fVar15 = (float)FUN_004c69f0(&fStack_40,&fStack_40);
          fVar11 = DAT_007cadd0 * (fVar15 - fVar14) + fVar14 + 0.0;
          if ((fVar11 < fVar15) && (300.0 < fVar11)) {
            fStack_40 = fStack_40 * fVar11;
            fStack_3c = fStack_3c * fVar11;
            fStack_38 = fStack_38 * fVar11;
            fStack_50 = fStack_10 + fStack_40;
            fStack_48 = fStack_8 + fStack_38;
            fStack_4c = 0.0;
            FUN_0027f650(iVar3,&fStack_50);
            bVar6 = 1;
          }
        }
      }
      if (bVar6) {
        *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x400000;
        *(u16 *)(DAT_007ce3ec + 0x18) = *(u16 *)(DAT_007ce3ec + 0x18) | 0x1e;
      }
    }
  }
  else if (cVar1 == '\0') {
    FUN_002d6370(uVar2);
    lVar9 = FUN_002d6290(iVar3);
    if (lVar9 == 1) {
      if (iVar3 != *(int *)(iVar3 + 0x38)) {
        iVar4 = *(int *)(iVar3 + 0x30);
        iVar3 = *(int *)(*(int *)(iVar3 + 0x38) + 0x30);
        iVar5 = *(int *)(iVar4 + 0xa00);
        if (lVar9 != 0) {
          *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x400000;
          *(u16 *)(DAT_007ce3ec + 0x18) = *(u16 *)(DAT_007ce3ec + 0x18) | 0xe;
        }
        FUN_0027ffb0(iVar4,&fStack_10);
        FUN_002802d0(iVar3,iVar4,&uStack_20);
        fStack_c = *(float *)(iVar4 + 8);
        uStack_20 = CONCAT44(fStack_c,(float)uStack_20);
        if (((param_1[2] == 1) && (iVar3 != iVar4)) &&
           (lVar9 = FUN_002fdcf0(iVar4,iVar3), lVar9 != 0)) {
          if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0) {
            FUN_0027ffb0(iVar3,&fStack_70);
            FUN_002d1de0(auStack_b0,&fStack_70,&fStack_10);
            fStack_48 = *(float *)(iVar3 + 0x2c);
            fStack_50 = *(float *)(iVar3 + 0x80) * fStack_48;
            fStack_4c = *(float *)(iVar3 + 0x84) * fStack_48;
            fStack_48 = *(float *)(iVar3 + 0x88) * fStack_48;
            FUN_004be1e0(&fStack_40,&fStack_50,1,auStack_b0);
            fStack_50 = fStack_70 - fStack_40;
            fStack_48 = fStack_68 - fStack_38;
            fStack_6c = *(float *)(iVar3 + 8);
            fStack_4c = fStack_6c;
            FUN_0027f650(iVar3,&fStack_50);
            FUN_002d1de0(auStack_b0,&fStack_50,iVar4 + 4);
            FUN_0027f680(iVar3,auStack_b0);
            uStack_20 = CONCAT44(fStack_6c,fStack_70);
            fStack_18 = fStack_68;
          }
          else {
            FUN_002d1de0(auStack_b0,&uStack_20,&fStack_10);
            FUN_0027f680(iVar3,auStack_b0);
          }
          FUN_002812b0(iVar3);
        }
        if (param_1[1] == 1) {
          fStack_40 = fStack_10 - (float)uStack_20;
          fStack_38 = fStack_8 - fStack_18;
          fStack_3c = 0.0;
          fVar11 = (float)FUN_004c69f0(&fStack_40,&fStack_40);
          fVar14 = *(float *)(iVar4 + 0x90) * *(float *)(iVar4 + 0x2c);
          fVar15 = 0.0;
          if (iVar5 != 0) {
            unaff_s5 = FUN_002d63b0(iVar5,uVar2,1);
            uVar7 = FUN_00284040(iVar5,iVar4,uVar2,1);
            fVar16 = (fVar11 + 0.0) - *(float *)(iVar4 + 0x90) * *(float *)(iVar4 + 0x2c);
            if (unaff_s5 == 0) {
              sVar8 = FUN_00284040(iVar5,iVar4,uVar2,1);
              if ((sVar8 == 3) || (sVar8 == 1)) {
                FUN_0027f940(iVar5,iVar4,iVar3,uVar7,&fStack_50,0,1);
              }
              else if ((sVar8 == 2) || (sVar8 == 0)) {
                FUN_0027f940(iVar5,iVar4,iVar3,uVar7,&fStack_50,0,0);
              }
            }
            else {
              FUN_0027f940(iVar5,iVar4,iVar3,uVar7,&fStack_50,0,2);
            }
            fStack_40 = fStack_50 - (float)uStack_20;
            fStack_38 = fStack_48 - fStack_18;
            fStack_3c = 0.0;
            fVar12 = (float)FUN_004c69f0(&fStack_40,&fStack_40);
            fVar13 = *(float *)(iVar5 + 0x90) * *(float *)(iVar5 + 0x2c);
            fVar12 = fVar12 - fVar13;
            if (unaff_s5 == 0) {
              fVar11 = fVar16;
              if (fVar12 + fVar13 <=
                  *(float *)(iVar4 + 0x90) * *(float *)(iVar4 + 0x2c) + fVar16 + 0.0) {
                fStack_60 = fStack_10 - fStack_50;
                fStack_58 = fStack_8 - fStack_48;
                fStack_5c = 0.0;
                fVar15 = (float)FUN_004c69f0(&fStack_60,&fStack_60);
                fVar14 = fVar13;
                fVar11 = fVar12;
              }
            }
            else {
              fVar14 = fVar13;
              FUN_0027f940(iVar5,iVar4,0,0xffffffffffffffff,&fStack_50,0,0);
              fStack_50 = fStack_10;
              fStack_4c = fStack_c;
              fStack_60 = fStack_10 - fStack_10;
              fStack_5c = fStack_c - fStack_c;
              fStack_58 = fStack_48 - fStack_8;
              fVar15 = (float)FUN_004c6ac0(&fStack_60);
              fVar11 = fVar12;
              if (fVar15 + fVar12 + fVar13 <= fVar16) {
                fVar15 = 0.0;
                fVar11 = fVar16;
              }
            }
          }
          fVar16 = *(float *)(iVar3 + 0x90) * *(float *)(iVar3 + 0x2c);
          fVar11 = fVar11 - fVar16;
          if (fVar11 < 300.0) {
            unaff_s5 = 1;
            fVar11 = 300.0;
          }
          if (unaff_s5 != 0) {
            fVar15 = fVar11 + fVar14 + fVar16 + fVar15;
            fStack_40 = fStack_40 * fVar15;
            fStack_3c = fStack_3c * fVar15;
            fStack_38 = fStack_38 * fVar15;
            fStack_50 = (float)uStack_20 + fStack_40;
            fStack_4c = (float)(uStack_20 >> 32) + fStack_3c;
            fStack_48 = fStack_18 + fStack_38;
            FUN_0027f650(iVar4,&fStack_50);
          }
        }
      }
    }
    else if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0) {
      iVar4 = *(int *)(iVar3 + 0x30);
      if (param_1[2] == 1) {
        for (uVar10 = 0; uVar10 < *(u16 *)(iVar3 + 0x6a); uVar10 = uVar10 + 1 & 0xffff) {
          iVar5 = *(int *)(iVar3 + uVar10 * 4 + 0x38);
          if (((*(u16 *)(iVar5 + 0x1a) & 1) != 0) && (iVar5 != iVar3)) {
            FUN_002d1de0(auStack_b0,*(int *)(iVar5 + 0x30) + 4,iVar4 + 4);
            FUN_0027f680(*(undefined4 *)(iVar5 + 0x30),auStack_b0);
            FUN_002812b0(*(undefined4 *)(iVar5 + 0x30));
          }
        }
      }
      FUN_0027ffb0(iVar4,&fStack_10);
      FUN_00280870(2,0,&uStack_20,0,0,1);
      fStack_c = *(float *)(iVar4 + 8);
      uStack_20 = CONCAT44(fStack_c,(float)uStack_20);
      uStack_80 = uStack_20;
      fStack_78 = fStack_18;
      fVar14 = 0.0;
      bVar6 = 1;
      fStack_88 = fStack_10;
      fStack_84 = fStack_8;
      uStack_98 = (float)uStack_20;
      fStack_94 = fStack_18;
      for (iVar3 = *(int *)(DAT_007ce3ec + 0x15c); fVar11 = fStack_78, iVar3 != 0;
          iVar3 = *(int *)(iVar3 + 0xa30)) {
        if ((*(u32 *)(iVar3 + 0x9c) & 8) != 0) {
          FUN_002802d0(iVar3,iVar4,&fStack_70);
          fStack_90 = fStack_70;
          fStack_8c = fStack_68;
          FUN_002d1fd0(&fStack_88,&uStack_98,&fStack_90,&fStack_a0);
          fStack_90 = fStack_88 - fStack_a0;
          fStack_8c = fStack_84 - fStack_9c;
          fVar11 = (float)FUN_004c6af0(&fStack_90);
          if ((fVar11 < fVar14) || (bVar6)) {
            uStack_80 = CONCAT44(fStack_c,fStack_a0);
            fStack_78 = fStack_9c;
            bVar6 = 0;
            fVar14 = fVar11;
          }
        }
      }
      if ((fVar14 + 0.0) - *(float *)(iVar4 + 0x90) * *(float *)(iVar4 + 0x2c) < 300.0) {
        fStack_40 = fStack_10 - (float)uStack_80;
        fStack_38 = fStack_8 - fStack_78;
        fStack_3c = 0.0;
        fVar14 = (float)(uStack_80 >> 32);
        FUN_004c69f0(&fStack_40,&fStack_40);
        fVar15 = *(float *)(iVar4 + 0x90) * *(float *)(iVar4 + 0x2c) + 300.0;
        fStack_40 = fStack_40 * fVar15;
        fStack_3c = fStack_3c * fVar15;
        fStack_38 = fStack_38 * fVar15;
        fStack_50 = (float)uStack_80 + fStack_40;
        fStack_4c = fVar14 + fStack_3c;
        fStack_48 = fVar11 + fStack_38;
        FUN_0027f650(iVar4,&fStack_50);
      }
    }
    else if ((*(u32 *)(DAT_007ce3ec + 0x10) & 0x80) != 0) {
      for (iVar3 = *(int *)(DAT_007ce3ec + 0x154); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xa30)) {
        if ((*(u32 *)(iVar3 + 0x9c) & 8) != 0) {
          FUN_0027f7c0(iVar3,&fStack_50,0,0);
          fStack_48 = fStack_48 + 200.0;
          FUN_0027f650(iVar3,&fStack_50);
        }
      }
      *(u32 *)(DAT_007ce3ec + 0xc) = *(u32 *)(DAT_007ce3ec + 0xc) | 0x400000;
      *(u16 *)(DAT_007ce3ec + 0x18) = *(u16 *)(DAT_007ce3ec + 0x18) | 6;
    }
  }
  return 1;
}

// FUN_002b8900

void FUN_002b8900(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = FUN_0027ec10(0xb01,0xc);
  *(code **)(iVar2 + 0x6c) = (code *)FUN_002b7c50;
  puVar1 = *(undefined4 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_3;
  return;
}

// FUN_002b8970
void LAB_002b8970(u32 *work)
{
  u8 *unit;

  unit = (u8 *)*work;
  (*(u16 *)(unit + 0xa0))++;
}

// FUN_002b8990 NONMATCHING

undefined4 FUN_002b8990(undefined4 *param_1)
{
  s16 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int bVar4;
  s16 uVar5;
  short sVar6;
  long lVar7;
  undefined1 auStack_20 [16];
  undefined1 auStack_10 [16];
  
  uVar2 = *param_1;
  uVar3 = *(undefined4 *)(param_1[1] + 0x30);
  uVar1 = *(s16 *)(param_1 + 3);
  bVar4 = param_1[2] != 0;
  uVar5 = FUN_00284040(uVar2,uVar3,uVar1,bVar4);
  lVar7 = FUN_002d63b0(uVar2,uVar1,bVar4);
  if (lVar7 == 0) {
    sVar6 = FUN_00284040(uVar2,uVar3,uVar1,bVar4);
    if ((sVar6 == 3) || (sVar6 == 1)) {
      FUN_0027f940(uVar2,uVar3,0,uVar5,auStack_20,auStack_10,1);
    }
    else if ((sVar6 == 2) || (sVar6 == 0)) {
      FUN_0027f940(uVar2,uVar3,0,uVar5,auStack_20,auStack_10,0);
    }
    FUN_0027f680(uVar2,auStack_10);
    FUN_0027f650(uVar2,auStack_20);
  }
  else {
    FUN_0027f940(uVar2,uVar3,*(undefined4 *)(param_1[2] + 0x30),uVar5,auStack_20,auStack_10,2);
    FUN_0027f680(uVar2,auStack_10);
    FUN_0027f650(uVar2,auStack_20);
  }
  return 1;
}

// FUN_002b8b50
void LAB_002b8b50(u32 *work)
{
  u8 *unit;

  unit = (u8 *)*work;
  (*(u16 *)(unit + 0xa0))--;
}

// FUN_002b8b70

void FUN_002b8b70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = FUN_0027ec10(0xb02,0x10);
  *(undefined1 **)(iVar2 + 0x68) = (undefined1*)LAB_002b8970;
  *(code **)(iVar2 + 0x6c) = (code *)FUN_002b8990;
  *(undefined1 **)(iVar2 + 0x70) = (undefined1*)LAB_002b8b50;
  puVar1 = *(undefined4 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_3;
  *(undefined2 *)(puVar1 + 3) = param_4;
  return;
}

// FUN_002b8c00 NONMATCHING

undefined4 FUN_002b8c00(u16 *param_1)

{
  u16 uVar1;
  u16 uVar2;
  int iVar3;
  long lVar4;
  u32 uVar5;
  undefined1 auStack_20 [16];
  undefined1 auStack_10 [16];
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  for (uVar5 = 0; uVar5 < 4; uVar5 = uVar5 + 1) {
    if (((u32)uVar1 & 1 << (uVar5 & 0x1f)) != 0) {
      for (iVar3 = *(int *)(iGpffffb6fc + uVar5 * 8 + 0x150); iVar3 != 0;
          iVar3 = *(int *)(iVar3 + 0xa34)) {
        if (((*(u32 *)(iVar3 + 0x9c) & 4) != 0) &&
           (((uVar2 & 0x8000) == 0 || (lVar4 = FUN_00281270(iVar3), lVar4 == 0)))) {
          FUN_0027f7c0(iVar3,auStack_10,auStack_20,0);
          if ((uVar2 & 1) != 0) {
            FUN_0027f650(iVar3,auStack_10);
            FUN_00281290(iVar3);
            FUN_002d4040(iVar3);
          }
          if ((uVar2 & 2) != 0) {
            FUN_0027f680(iVar3,auStack_20);
            FUN_002812b0(iVar3);
          }
        }
      }
    }
  }
  return 1;
}

/* Camera-state work records use the retail 64-bit pair layout. */
#ifndef BTLCAMERA_GHIDRA_PAIR
#define BTLCAMERA_GHIDRA_PAIR
typedef u8 u8;
typedef u8 byte;
typedef unsigned short ushort;
typedef union BtlCameraGhidraPair
{
    struct { f32 _0_4_; f32 _4_4_; } f;
    u64 raw;
} BtlCameraGhidraPair;
#define GhidraPair BtlCameraGhidraPair
#define PAIR44(hi, lo) ((GhidraPair){{(lo), (hi)}})
#endif

extern f32 DAT_007cad3c;
extern f32 DAT_007cad54;
extern f32 DAT_007cad98;
extern f32 DAT_007cadb0;
extern f32 DAT_007caddc;
extern f32 DAT_007cade0;
extern f32 DAT_007cade4;
extern f32 DAT_007cade8;
extern f32 DAT_007cadfc;
extern f32 DAT_007cae00;
extern f32 DAT_007cae04;
extern f32 DAT_007cae0c;
extern f32 DAT_007cae10;
extern f32 DAT_007cae14;
extern f32 DAT_007cae18;
extern f32 DAT_007cae24;
extern f32 fGpffff8030;
extern f32 fGpffff807c;
extern f32 fGpffff80a0;
extern f32 fGpffff80a4;
extern f32 fGpffff80a8;
extern f32 fGpffff80b0;
extern f32 fGpffff80b8;
extern f32 fGpffff80bc;
extern u32 uGpffff8074;
extern u32 uGpffff809c;
extern u32 uGpffff80ac;
extern u64 func_00280050();
extern u64 func_00280870();
extern u64 func_002d1de0();
extern u8* iGpffffb6fc;
extern u8* iGpffffb73c;

// FUN_002AA2B0 NONMATCHING

void func_002aa2b0(BtlCamera* camera, long param_2, long param_3)
{
  short sVar1;
  int iVar2;
  int iVar3;
  u8 bVar4;
  u8 bVar5;
  long lVar6;
  long lVar7;
  u32 uVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  undefined4 uVar16;
  float fVar17;
  float fStack_118;
  float fStack_114;
  undefined1 auStack_110 [64];
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  GhidraPair uStack_70;
  float fStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  undefined1 auStack_50 [4];
  float fStack_4c;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar9 = (int)camera;
  iVar2 = *(int *)(*(int *)(iVar9 + 0xe0) + 0x30);
  iVar3 = *(int *)(iVar2 + 0xa00);
  if ((lVar6 == 0) && (lVar6 = FUN_002a3550((u8*)camera), lVar6 == 0)) {
    bVar4 = 0;
  }
  else {
    bVar4 = 1;
  }
  bVar5 = 0;
  btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar2), (RwV3d*)&fStack_30);
  btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar3), (RwV3d*)auStack_50);
  fVar15 = *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) * 0.5 + fStack_2c + 0.0;
  fVar13 = *(float *)(iVar3 + 0x8c) * *(float *)(iVar3 + 0x2c) * 0.5 + fStack_4c + 0.0;
  if ((fVar15 < fVar13) && (!bVar4)) {
    fStack_2c = (fVar15 + fVar13) * 0.25;
    fVar15 = fVar13;
  }
  fVar14 = *(float *)(iVar3 + 0x90) * *(float *)(iVar3 + 0x2c);
  fVar13 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c) * 1.25;
  if ((fVar13 < fVar14) && (!bVar4)) {
    fVar13 = fVar14;
  }
  if (fVar15 < 275.0) {
    fStack_2c = fGpffff80a0;
    fVar15 = 275.0;
  }
  fVar10 = (float)func_00280870(2,0,&fStack_40,&fStack_4,0,1);
  FUN_004be1e0(&fStack_10,0x697870,1,iVar2 + 0x1c);
  fStack_3c = fStack_4 * 0.5;
  fStack_20 = fStack_30 - fStack_40;
  fStack_1c = fStack_2c - fStack_3c;
  fStack_18 = fStack_28 - fStack_38;
  fVar14 = (float)FUN_004c69f0(&fStack_20,&fStack_20);
  fVar14 = fGpffff8098 * fVar14;
  fStack_60 = fStack_20 * fVar14 + fStack_40;
  fStack_5c = fStack_1c * fVar14 + fStack_3c;
  fStack_68 = fStack_18 * fVar14 + fStack_38;
  uStack_70 = PAIR44(fStack_5c,fStack_60);
  fStack_118 = *(float *)(iVar9 + 0x9c) - fStack_60;
  fStack_114 = *(float *)(iVar9 + 0xa4) - fStack_68;
  fStack_58 = fStack_68;
  FUN_004c6b20(&fStack_118,&fStack_118);
  fVar14 = fStack_18 * fStack_118 + -fStack_20 * fStack_114;
  if ((bVar4) ||
     ((*(ushort *)
        (iGpffffb73c + ((u32)*(ushort *)(iVar3 + 0xa4) * 10 + (u32)*(ushort *)(iVar3 + 0xa4)) * 8)
      & 0x20) == 0)) {
    uVar8 = FUN_00357fd0(0);
    bVar4 = (uVar8 & 1) != 0;
  }
  else {
    bVar4 = 0;
  }
  if ((lVar6 != 0) || (((bVar4 && (lVar6 = FUN_002a3380((u8*)camera), lVar6 != 0)) && (lVar7 == 0)))) {
    btlUnit002880e0((BtlUnit*)(uintptr_t)(iVar3),1);
    *(int *)(iVar9 + 0x120) = iVar3;
    *(undefined2 *)(iVar9 + 0x124) = 0;
    fVar11 = fVar13;
    if (fVar14 < 0.0) {
      fVar11 = -fVar13;
    }
    fStack_8 = fStack_8 * fVar11;
    fStack_10 = fStack_10 * fVar11;
    fStack_80 = fStack_30 + fStack_10;
    fStack_78 = fStack_28 + fStack_8;
    fVar15 = fGpffff80a4 * fVar15;
    fStack_10 = fStack_80 - fStack_60;
    fStack_c = fVar15 - fStack_5c;
    fStack_8 = fStack_78 - fStack_58;
    fStack_7c = fVar15;
    fVar11 = (float)FUN_004c69f0(&fStack_10,&fStack_10);
    fVar17 = fGpffff8070 * *(float *)(iVar9 + 0xb8) * 0.5;
    fVar12 = (float)FUN_0052e930(fVar17);
    fVar13 = fVar13 / fVar12;
    fVar12 = (float)FUN_0052e930(fVar17);
    if (fVar13 <= fVar15 / fVar12) {
      fVar13 = fVar15 / fVar12;
    }
    fVar11 = fVar11 + fVar13;
    fVar15 = (float)FUN_0052e930(fVar17);
    if (fVar11 <= fVar10 / fVar15) {
      fVar11 = fVar10 / fVar15;
    }
    fVar15 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar9 + 0xb8) * 0.5);
    fVar15 = fVar11 * fVar15 * 0.21875;
    fStack_98 = fStack_10;
    fStack_94 = fStack_8;
    FUN_004c6b20(&fStack_98,&fStack_98);
    fStack_60 = fStack_94 * fVar15 + fStack_60 + 0.0;
    fStack_58 = (fStack_58 + 0.0) - fStack_98 * fVar15;
    fStack_b4 = fStack_60 + fStack_10 * fVar11;
    fStack_b0 = fStack_5c + fStack_c * fVar11;
    fStack_ac = fStack_58 + fStack_8 * fVar11;
    btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar2), (RwV3d*)&fStack_30);
    fStack_2c = fGpffff8094 * *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) + fStack_2c + 0.0;
    fVar15 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c) * 2.5;
    FUN_004be1e0(&fStack_10,0x697870,1,iVar2 + 0x1c);
    if (0.0 <= fVar14) {
      fVar15 = -fVar15;
    }
    fStack_8 = fStack_8 * fVar15;
    fStack_c = fStack_c * fVar15;
    fStack_10 = fStack_10 * fVar15;
    fStack_90 = fStack_30 + fStack_10;
    fStack_8c = fStack_2c + fStack_c;
    fStack_88 = fStack_28 + fStack_8;
    fVar14 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c) * 4.0;
    fStack_10 = fStack_90 - uStack_70.f._0_4_;
    fStack_c = fStack_8c - uStack_70.f._4_4_;
    fStack_8 = fStack_88 - fStack_68;
    fVar15 = (float)FUN_004c69f0(&fStack_10,&fStack_10);
    fVar13 = (float)FUN_0052e930(fVar17);
    fVar15 = fVar15 + fVar14 / fVar13;
    FUN_004be1e0(&fStack_10,0x6978a0,1,&uStack_c4);
    fVar13 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar9 + 0xb8) * 0.5);
    fVar13 = fVar15 * fVar13 * 0.21875;
    fStack_98 = fStack_10;
    fStack_94 = fStack_8;
    FUN_004c6b20(&fStack_98,&fStack_98);
    fStack_d0 = fStack_94 * fVar13 + uStack_70.f._0_4_ + 0.0;
    uStack_70 = PAIR44(uStack_70.f._4_4_,fStack_d0);
    fStack_68 = (fStack_68 + 0.0) - fStack_98 * fVar13;
    fStack_10 = fStack_10 * fVar15;
    fStack_c = fStack_c * fVar15;
    fStack_8 = fStack_8 * fVar15;
    fStack_d0 = fStack_d0 + fStack_10;
    fStack_cc = uStack_70.f._4_4_ + fStack_c;
    fStack_c8 = fStack_68 + fStack_8;
    uVar16 = uGpffff8074;
  }
  else {
    btlUnit002880e0((BtlUnit*)(uintptr_t)(iVar3),0);
    *(int *)(iVar9 + 0x120) = iVar3;
    *(undefined2 *)(iVar9 + 0x124) = 1;
    fStack_78 = fStack_38;
    fStack_7c = fGpffff80a8 * fStack_4;
    fStack_80 = fStack_40;
    if (*(short *)(*(int *)(iVar9 + 0xe0) + 0x6a) == 1) {
      iVar2 = *(int *)(*(int *)(*(int *)(iVar9 + 0xe0) + 0x38) + 0x30);
      if (0.0 <= fVar14) {
        fVar15 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c);
      }
      else {
        fVar15 = -(*(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c));
      }
      fStack_8 = fStack_8 * fVar15;
      fStack_c = fStack_c * fVar15;
      fStack_10 = fStack_10 * fVar15;
      fStack_80 = fStack_40 + fStack_10;
      fStack_7c = fStack_7c + fStack_c;
      fStack_78 = fStack_38 + fStack_8;
    }
    if (fStack_7c < 125.0) {
      fStack_7c = 125.0;
    }
    fStack_10 = fStack_80 - fStack_60;
    fStack_c = fStack_7c - fStack_5c;
    fStack_8 = fStack_78 - fStack_58;
    fVar13 = (float)FUN_004c69f0(&fStack_10,&fStack_10);
    fVar15 = 300.0;
    if (300.0 <= fVar10) {
      fVar15 = fVar10;
    }
    fVar10 = (float)FUN_0052e930(*(float *)(iVar9 + 0xb8) * 0.5);
    fVar13 = fVar13 + fVar15 / fVar10;
    fVar15 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar9 + 0xb8) * 0.5);
    fVar15 = fVar13 * fVar15 * 0.21875 * 0.5;
    fStack_98 = fStack_10;
    fStack_94 = fStack_8;
    FUN_004c6b20(&fStack_98,&fStack_98);
    fStack_60 = fStack_94 * fVar15 + fStack_60 + 0.0;
    fStack_58 = (fStack_58 + 0.0) - fStack_98 * fVar15;
    fStack_b4 = fStack_60 + fStack_10 * fVar13;
    fStack_b0 = fStack_5c + fStack_c * fVar13;
    fStack_ac = fStack_58 + fStack_8 * fVar13;
    if (lVar7 == 0) {
      if (0.0 <= fVar14) {
        FUN_004c31b0(0xc1dc0000,auStack_110,0x697880,0);
      }
      else {
        FUN_004c31b0(0x41dc0000,auStack_110,0x697880,0);
      }
      FUN_004c6c60(&fStack_20,&fStack_10,auStack_110);
      fVar13 = fVar13 * fGpffff807c;
      fVar15 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar9 + 0xb8) * 0.5);
      fVar15 = fVar13 * fVar15 * 0.21875 * 0.5;
      fStack_98 = fStack_20;
      fStack_94 = fStack_18;
      FUN_004c6b20(&fStack_98,&fStack_98);
      fStack_60 = fStack_94 * fVar15 + fStack_60 + 0.0;
      fStack_58 = (fStack_58 + 0.0) - fStack_98 * fVar15;
      fStack_d0 = fStack_60 + fStack_20 * fVar13;
      fStack_c8 = fStack_58 + fStack_18 * fVar13;
      fStack_cc = fGpffff80a4 * fStack_4;
      fStack_20 = fStack_30 - fStack_40;
      fStack_1c = fStack_2c - fStack_3c;
      fStack_18 = fStack_28 - fStack_38;
      fVar15 = (float)FUN_004c69f0(&fStack_20,&fStack_20);
      fVar15 = fVar15 * 0.25;
      fStack_60 = fStack_20 * fVar15 + fStack_40;
      fStack_5c = fStack_1c * fVar15 + fStack_3c;
      fStack_58 = fStack_18 * fVar15 + fStack_38;
      uVar16 = 0x40700000;
    }
    else {
      sVar1 = *(short *)(*(int *)(iVar9 + 0xe0) + 0x6e);
      if (sVar1 == 0x38) {
        fStack_5c = 1000.0;
        fStack_cc = 500.0;
        uVar16 = 0x3fc00000;
        bVar5 = 0;
        *(undefined4 *)(iVar9 + 0xdc) = 4;
      }
      else if (sVar1 == 0x2c) {
        fStack_5c = 800.0;
        fStack_cc = 500.0;
        uVar16 = 0x40000000;
        bVar5 = 1;
        *(undefined4 *)(iVar9 + 0xdc) = 0xc;
      }
      else if (sVar1 == 0x27) {
        fStack_5c = 600.0;
        fStack_cc = 200.0;
        bVar5 = 0;
        *(undefined4 *)(iVar9 + 0xdc) = 8;
        uVar16 = uGpffff80ac;
      }
      else if (sVar1 == 0x26) {
        fStack_5c = 500.0;
        fStack_cc = 200.0;
        uVar16 = 0x3fa00000;
        bVar5 = 1;
        *(undefined4 *)(iVar9 + 0xdc) = 0xc;
      }
      else {
        fStack_5c = 500.0;
        fStack_cc = 200.0;
        bVar5 = 1;
        *(undefined4 *)(iVar9 + 0xdc) = 0;
        uVar16 = uGpffff809c;
      }
      param_2 = 0;
      fStack_d0 = fStack_b4;
      fStack_c8 = fStack_ac;
    }
  }
  if ((param_3 == 0) && (lVar7 == 0)) {
    uStack_c4 = uStack_a8;
    uStack_c0 = uStack_a4;
    uStack_bc = uStack_a0;
    uStack_b8 = uStack_9c;
    FUN_004be1e0(&fStack_10,0x697890,1,&uStack_c4);
    fStack_10 = fStack_10 * 100.0;
    fStack_c = fStack_c * 100.0;
    fStack_8 = fStack_8 * 100.0;
    fStack_d0 = fStack_b4 + fStack_10;
    fStack_cc = fStack_b0 + fStack_c;
    fStack_c8 = fStack_ac + fStack_8;
  }
  if (0 < *(int *)(iVar9 + 0xdc)) {
  }
  if (bVar5) {
    FUN_002a3160(uVar16,camera);
  }
  else {
  }
  if (param_2 != 0) {
    FUN_00351bb0(0xc);
  }
  return;
}

// FUN_002AB2A0

void func_002ab2a0(BtlCamera* camera)
{
  int iVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = (int)camera;
  iVar1 = *(int *)(iVar3 + 0xe0);
  if ((iVar1 != 0) && ((*(ushort *)(iVar1 + 0x1a) & 1) != 0)) {
    if (*(int *)(iVar3 + 0xdc) == 0) {
      FUN_002a3e80(0.0f,(u8 *)(uintptr_t)iVar1,0,0,3);
    }
    if (FUN_002a3750(camera,*(undefined4 *)(iVar3 + 0x120)) != 0) {
      btlUnit002880e0((BtlUnit*)(uintptr_t)(*(undefined4 *)(iVar3 + 0x120)),*(undefined2 *)(iVar3 + 0x124));
    }
  }
  return;
}

// FUN_002AB330 NONMATCHING

void func_002ab330(BtlCamera* camera, long param_2, long param_3)
{
  int iVar1;
  int iVar2;
  u8 bVar3;
  u32 uVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined4 uVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  GhidraPair uStack_80;
  float fStack_78;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar6 = (int)camera;
  iVar7 = *(int *)(*(int *)(iVar6 + 0xe0) + 0x30);
  iVar1 = *(int *)(*(int *)(*(int *)(iVar6 + 0xe0) + 0x38) + 0x30);
  iVar2 = *(int *)(iVar7 + 0xa00);
  btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar7), (RwV3d*)&fStack_10);
  btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar1), (RwV3d*)&fStack_20);
  btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar2), (RwV3d*)&fStack_30);
  fVar15 = *(float *)(iVar7 + 0x8c) * *(float *)(iVar7 + 0x2c) * 0.5 + fStack_c + 0.0;
  fVar12 = *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) * 0.5 + fStack_1c + 0.0;
  fVar13 = *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) * 0.5 + fStack_2c + 0.0;
  fVar14 = *(float *)(iVar7 + 0x90) * *(float *)(iVar7 + 0x2c);
  fVar10 = *(float *)(iVar2 + 0x90) * *(float *)(iVar2 + 0x2c);
  *(float *)(iVar6 + 0x104) = fStack_20;
  *(float *)(iVar6 + 0x108) = fStack_1c;
  *(float *)(iVar6 + 0x10c) = fStack_18;
  *(undefined4 *)(iVar6 + 0x100) = *(undefined4 *)(*(int *)(iVar6 + 0xe0) + 0x38);
  if (fVar13 < 135.0) {
    fStack_2c = 67.5;
    fVar13 = 135.0;
  }
  if ((*(u32 *)(iGpffffb6fc + 0xc) & 0x200000) == 0) {
    if (125.0 <= fVar13 - fVar12) {
      bVar3 = 0;
    }
    else {
      bVar3 = lVar5 != 0;
      if (!bVar3) {
        uVar4 = FUN_00357fd0(0);
        bVar3 = 0;
        if ((uVar4 & 1) != 0) {
          bVar3 = lVar5 != 0;
        }
      }
    }
  }
  else {
    bVar3 = 1;
  }
  if (bVar3) {
    fStack_60 = fStack_30 - fStack_20;
    fStack_5c = fStack_2c - fStack_1c;
    fStack_58 = fStack_28 - fStack_18;
    fVar8 = (float)FUN_004c69f0(&fStack_60,&fStack_60);
    fStack_48 = fGpffff8098 * fVar8;
    fStack_50 = fStack_60 * fStack_48;
    fStack_4c = fStack_5c * fStack_48;
    fStack_48 = fStack_58 * fStack_48;
  }
  else {
    fStack_60 = (fStack_30 + fStack_10) * 0.5;
    fStack_5c = (fStack_2c + fStack_c) * 0.5;
    fStack_38 = (fStack_28 + fStack_8) * 0.5;
    fStack_60 = fStack_60 - fStack_20;
    fStack_5c = fStack_5c - fStack_1c;
    fStack_58 = fStack_38 - fStack_18;
    fVar8 = (float)FUN_004c69f0(&fStack_60,&fStack_60);
    fStack_48 = fGpffff8098 * fVar8;
    fStack_50 = fStack_60 * fStack_48;
    fStack_4c = fStack_5c * fStack_48;
    fStack_48 = fStack_58 * fStack_48;
  }
  fStack_50 = fStack_50 + fStack_20;
  fStack_4c = fStack_4c + fStack_1c;
  fStack_48 = fStack_48 + fStack_18;
  fStack_b8 = *(float *)(iVar6 + 0x9c) - fStack_50;
  fStack_b4 = *(float *)(iVar6 + 0xa4) - fStack_48;
  FUN_004c6b20(&fStack_b8,&fStack_b8);
  if (bVar3) {
    btlUnit002880e0((BtlUnit*)(uintptr_t)(iVar2),1);
    *(int *)(iVar6 + 0x120) = iVar2;
    *(undefined2 *)(iVar6 + 0x124) = 0;
    fStack_40 = fStack_30;
    fStack_3c = fStack_2c;
    fStack_38 = fStack_28;
    fVar9 = fVar10 * 1.5;
    fStack_c0 = fStack_58;
    fStack_bc = -fStack_60;
    fVar16 = fStack_58 * fStack_b8 + fStack_bc * fStack_b4;
    if (0.0 <= fVar16) {
      fStack_70 = fStack_58 * fVar9 + fStack_30 + 0.0;
      fStack_68 = (fStack_28 + 0.0) - fStack_60 * fVar9;
    }
    else {
      fStack_70 = (fStack_30 + 0.0) - fStack_58 * fVar9;
      fStack_68 = fStack_60 * fVar9 + fStack_28 + 0.0;
      fVar8 = fVar8 * 0.5;
      fStack_50 = fStack_60 * fVar8 + fStack_20;
      fStack_4c = fStack_5c * fVar8 + fStack_1c;
      fStack_48 = fStack_58 * fVar8 + fStack_18;
    }
    if (fVar12 <= fVar13) {
      fStack_4c = fGpffff8094 * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) +
                  fStack_4c + 0.0;
      if (fStack_4c < fVar13) {
        fStack_6c = fGpffff8030 * *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) +
                    fStack_4c + 0.0;
      }
      else {
        fStack_6c = fStack_2c;
      }
    }
    else if (((*(u32 *)(iGpffffb6fc + 0xc) & 0x200000) == 0) || (fVar12 < 500.0)) {
      fStack_4c = (fStack_4c + 0.0) -
                  fGpffff80b0 * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c);
      fStack_6c = fVar13 * 0.25 + fStack_2c + 0.0;
    }
    else {
      fStack_4c = fGpffff8030 * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) +
                  fStack_4c + 0.0;
      fStack_6c = fVar13 * 0.25 + fStack_2c + 0.0;
    }
    FUN_004be1e0(&fStack_60,0x6978a0,1,&uStack_d8);
    fStack_b0 = fStack_50;
    fStack_ac = fStack_48;
    fStack_a8 = fStack_70;
    fStack_a4 = fStack_68;
    fStack_88 = fStack_40;
    fStack_84 = fStack_38;
    fVar8 = (float)FUN_002d1fd0(&fStack_b0,&fStack_a8,&fStack_88,&fStack_90);
    fVar8 = fVar10 * fGpffff809c + fVar8 + 0.0;
    fVar10 = 275.0;
    if (275.0 <= fVar8) {
      fVar10 = fVar8;
    }
    fStack_70 = fStack_90;
    if (fVar12 <= fVar13) {
      if (fStack_4c < fVar13) {
        fStack_6c = fGpffff80b4 * *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) +
                    fStack_4c + 0.0;
      }
      else {
        fStack_6c = *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) * 0.25 + fStack_3c + 0.0;
      }
    }
    else {
      fStack_6c = fVar13 * 0.25 + fStack_3c + 0.0;
    }
    fStack_68 = fStack_8c;
    fVar13 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar6 + 0xb8) * 0.5);
    fVar10 = fVar10 / fVar13;
    fStack_60 = fStack_60 * fVar10;
    fStack_5c = fStack_5c * fVar10;
    fStack_58 = fStack_58 * fVar10;
    if (fVar16 < 0.0) {
      fVar13 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar6 + 0xb8) * 0.5);
      fVar10 = fVar10 * fVar13 * 0.21875 * 1.25;
      fStack_98 = fStack_60;
      fStack_94 = fStack_58;
      FUN_004c6b20(&fStack_98,&fStack_98);
      fStack_70 = fStack_94 * fVar10 + fStack_70 + 0.0;
      fStack_68 = (fStack_68 + 0.0) - fStack_98 * fVar10;
    }
    fStack_e4 = fStack_70 + fStack_60;
    fStack_e0 = fStack_6c + fStack_5c;
    fStack_dc = fStack_68 + fStack_58;
    if (fStack_e0 < 25.0) {
      fStack_e0 = 25.0;
    }
    fStack_60 = fStack_10 - fStack_20;
    fStack_5c = fStack_c - fStack_1c;
    fStack_58 = fStack_8 - fStack_18;
    fVar13 = (float)FUN_004c69f0(&fStack_60,&fStack_60);
    fVar10 = fGpffff8098 * fVar13;
    fStack_50 = fStack_60 * fVar10 + fStack_20;
    fStack_4c = fStack_5c * fVar10 + fStack_1c;
    fStack_48 = fStack_58 * fVar10 + fStack_18;
    fStack_40 = fStack_10;
    fStack_3c = fStack_c;
    fStack_38 = fStack_8;
    fVar10 = fVar14 * 2.0;
    lVar5 = FUN_0017d800();
    if ((lVar5 != 0) && (450.0 < fStack_1c)) {
      fVar10 = fVar10 + 150.0;
      fVar15 = fVar15 + 350.0;
    }
    fStack_6c = fVar15 * 0.5 + fStack_3c + 0.0;
    if (0.0 <= fVar16) {
      fStack_70 = fStack_58 * fVar10 + fStack_40 + 0.0;
      fStack_68 = (fStack_38 + 0.0) - fStack_60 * fVar10;
    }
    else {
      fStack_70 = (fStack_40 + 0.0) - fStack_58 * fVar10;
      fStack_68 = fStack_60 * fVar10 + fStack_38 + 0.0;
      fVar13 = fVar13 * 0.5;
      fStack_50 = fStack_60 * fVar13 + fStack_20;
      fStack_4c = fStack_5c * fVar13 + fStack_1c;
      fStack_48 = fStack_58 * fVar13 + fStack_18;
    }
    fStack_4c = fGpffff8030 * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) + fStack_4c + 0.0;
    FUN_004be1e0(&fStack_60,0x6978a0,1,&uStack_f4);
    fStack_b0 = fStack_50;
    fStack_ac = fStack_48;
    fStack_a8 = fStack_70;
    fStack_a4 = fStack_68;
    fStack_88 = fStack_40;
    fStack_84 = fStack_38;
    fVar10 = (float)FUN_002d1fd0(&fStack_b0,&fStack_a8,&fStack_88,&fStack_90);
    fStack_70 = fStack_90;
    fStack_6c = fVar15 * 0.25 + fStack_3c + 0.0;
    fStack_68 = fStack_8c;
    fVar13 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar6 + 0xb8) * 0.5);
    fVar13 = (fVar14 * 3.0 + fVar10 + 0.0) / fVar13;
    fStack_60 = fStack_60 * fVar13;
    fStack_5c = fStack_5c * fVar13;
    fStack_58 = fStack_58 * fVar13;
    if (fVar16 < 0.0) {
      fVar10 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar6 + 0xb8) * 0.5);
      fVar10 = fVar13 * fVar10 * 0.21875 * 1.25;
      fStack_98 = fStack_60;
      fStack_94 = fStack_58;
      FUN_004c6b20(&fStack_98,&fStack_98);
      fStack_70 = fStack_94 * fVar10 + fStack_70 + 0.0;
      fStack_68 = (fStack_68 + 0.0) - fStack_98 * fVar10;
    }
    fStack_100 = fStack_70 + fStack_60;
    fStack_fc = fStack_6c + fStack_5c;
    fStack_f8 = fStack_68 + fStack_58;
    if (fStack_fc < 25.0) {
      fStack_fc = 25.0;
    }
    uVar11 = 0x40200000;
    iVar7 = iVar1;
  }
  else {
    btlUnit002880e0((BtlUnit*)(uintptr_t)(iVar2),0);
    *(int *)(iVar6 + 0x120) = iVar2;
    *(undefined2 *)(iVar6 + 0x124) = 1;
    fStack_3c = fStack_1c;
    fStack_38 = fStack_18;
    fVar14 = fGpffff80b8 * *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
    fVar10 = fVar10 * 0.75;
    if (fVar10 <= fVar14) {
      fVar10 = fVar14;
    }
    if (fStack_1c < 125.0) {
      fStack_3c = 125.0;
    }
    fStack_40 = fStack_20;
    fStack_c0 = fStack_58;
    fStack_bc = -fStack_60;
    fVar14 = fStack_58 * fStack_b8 + fStack_bc * fStack_b4;
    fStack_6c = fStack_3c;
    if (0.0 <= fVar14) {
      fStack_70 = fStack_58 * fVar10 + fStack_20 + 0.0;
      fStack_68 = (fStack_18 + 0.0) - fStack_60 * fVar10;
      uStack_80 = PAIR44(fStack_5c,fStack_60);
      fStack_78 = fStack_58;
    }
    else {
      fStack_70 = (fStack_20 + 0.0) - fStack_58 * fVar10;
      fStack_68 = fStack_60 * fVar10 + fStack_18 + 0.0;
    }
    if (fVar12 <= fVar13) {
      fStack_4c = fGpffff8030 * *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) +
                  fStack_4c + 0.0;
    }
    else {
      fStack_4c = fGpffff80bc * *(float *)(iVar2 + 0x8c) * *(float *)(iVar2 + 0x2c) +
                  fStack_4c + 0.0;
    }
    FUN_004be1e0(&fStack_60,0x6978a0,1,&uStack_f4);
    fStack_b0 = fStack_50;
    fStack_ac = fStack_48;
    fStack_a8 = fStack_70;
    fStack_a4 = fStack_68;
    fStack_88 = fStack_40;
    fStack_84 = fStack_38;
    fVar13 = (float)FUN_002d1fd0(&fStack_b0,&fStack_a8,&fStack_88,&fStack_90);
    fVar15 = *(float *)(iVar1 + 0x90);
    fVar10 = *(float *)(iVar1 + 0x2c);
    fStack_70 = fStack_90;
    fStack_6c = fStack_3c;
    fStack_68 = fStack_8c;
    fVar12 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar6 + 0xb8) * 0.5);
    fVar12 = (fVar15 * fVar10 * 1.5 + fVar13 + 0.0) / fVar12;
    fVar10 = 550.0;
    if (550.0 <= fVar12) {
      fVar10 = fVar12;
    }
    fStack_60 = fStack_60 * fVar10;
    fStack_5c = fStack_5c * fVar10;
    fStack_58 = fStack_58 * fVar10;
    if (0.0 <= fVar14) {
      fVar13 = (float)FUN_0052e930(fGpffff8070 * *(float *)(iVar6 + 0xb8) * 0.5);
      fVar10 = fVar10 * fVar13 * 0.21875 * 2.0;
      fStack_98 = uStack_80.f._0_4_;
      fStack_94 = fStack_78;
      FUN_004c6b20(&fStack_98,&fStack_98);
      fStack_70 = (fStack_70 + 0.0) - fStack_94 * fVar10;
      fStack_68 = fStack_98 * fVar10 + fStack_68 + 0.0;
    }
    fStack_100 = fStack_70 + fStack_60;
    fStack_fc = fStack_6c + fStack_5c;
    fStack_f8 = fStack_68 + fStack_58;
    uStack_d8 = uStack_f4;
    uStack_d4 = uStack_f0;
    uStack_d0 = uStack_ec;
    uStack_cc = uStack_e8;
    fStack_60 = fStack_10 - fStack_100;
    fStack_5c = fStack_c - fStack_fc;
    fStack_58 = fStack_8 - fStack_f8;
    fStack_e4 = fStack_100;
    fStack_e0 = fStack_fc;
    fStack_dc = fStack_f8;
    fVar10 = (float)FUN_004c69f0(&fStack_60,&fStack_60);
    btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar7), (RwV3d*)&fStack_40);
    fStack_3c = fGpffff8030 * *(float *)(iVar7 + 0x8c) * *(float *)(iVar7 + 0x2c) + fStack_3c + 0.0;
    fVar10 = fGpffff8098 * fVar10;
    fStack_60 = fStack_60 * fVar10;
    fStack_5c = fStack_5c * fVar10;
    fStack_58 = fStack_58 * fVar10;
    fStack_100 = fStack_e4 + fStack_60;
    fStack_fc = fStack_e0 + fStack_5c;
    fStack_f8 = fStack_dc + fStack_58;
    if (fStack_fc < 25.0) {
      fStack_fc = 25.0;
    }
    if (fStack_e0 < 25.0) {
      fStack_e0 = 25.0;
    }
    uVar11 = 0x40100000;
  }
  if (param_3 == 0) {
    fStack_100 = fStack_e4;
    fStack_fc = fStack_e0;
    fStack_f8 = fStack_dc;
    uStack_f4 = uStack_d8;
    uStack_f0 = uStack_d4;
    uStack_ec = uStack_d0;
    uStack_e8 = uStack_cc;
  }
  if (param_2 != 0) {
    FUN_00351bb0(0xc);
  }
  return;
}

// FUN_002AC540 NONMATCHING

void func_002ac540(BtlCamera* camera)
{
  u8 bVar1;
  int iVar2;
  undefined2 uVar3;
  long lVar4;
  int iVar5;
  
  iVar5 = (int)camera;
  iVar2 = *(int *)(*(int *)(*(int *)(iVar5 + 0xe0) + 0x30) + 0xa00);
  uVar3 = FUN_002a7830();
  *(undefined2 *)(iVar5 + 0x110) = uVar3;
  bVar1 = *(short *)(iVar5 + 0xe4) != 0x19;
  if ((iVar2 == 0) || (lVar4 = FUN_002fdbb0(*(undefined4 *)(iVar5 + 0xe0),iVar2), lVar4 == 0)) {
    *(undefined4 *)(iVar5 + 0x114) = 0;
  }
  else {
    *(undefined4 *)(iVar5 + 0x114) = 1;
  }
  switch(*(undefined2 *)(iVar5 + 0x110)) {
  case 1:
    FUN_002a8150(camera,bVar1,bVar1);
    break;
  case 2:
    FUN_002a95d0(camera,bVar1,bVar1);
    break;
  case 3:
    func_002aa2b0(camera,bVar1,bVar1);
    break;
  case 4:
    if (*(int *)(iVar5 + 0x114) == 0) {
      func_002ab330(camera,bVar1,bVar1);
    }
    else {
      FUN_002a95d0(camera,bVar1,bVar1);
    }
    break;
  case 5:
    func_002aa2b0(camera,bVar1,bVar1);
    break;
  case 6:
    FUN_002a79f0(camera,1);
  }
  return;
}

// FUN_002AC6E0

void func_002ac6e0(BtlCamera* camera)
{
    u8* cameraBytes;
    BtlAction* action;
    u16 state;

    cameraBytes = (u8*)camera;
    state = *(u16*)(cameraBytes + 0x110);

    switch (state)
    {
    case 0:
    case 1:
        break;
    case 2:
        action = *(BtlAction**)(cameraBytes + 0xe0);
        if (action != NULL && (action->unk_1a & 1) != 0)
        {
            if (FUN_002a3750(camera, *(u32*)(cameraBytes + 0x120)) != 0)
            {
                btlUnit002880e0((BtlUnit*)(uintptr_t)*(u32*)(cameraBytes + 0x120),
                                *(u16*)(cameraBytes + 0x124));
            }
        }
        break;
    case 3:
        action = *(BtlAction**)(cameraBytes + 0xe0);
        if (action != NULL && (action->unk_1a & 1) != 0)
        {
            if (*(s32*)(cameraBytes + 0xdc) == 0)
            {
                FUN_002a3e80(0.0f, (u8*)action, (u8*)0, (u8*)0, 3);
            }
            if (FUN_002a3750(camera, *(u32*)(cameraBytes + 0x120)) != 0)
            {
                btlUnit002880e0((BtlUnit*)(uintptr_t)*(u32*)(cameraBytes + 0x120),
                                *(u16*)(cameraBytes + 0x124));
            }
        }
        break;
    case 4:
        if (*(s32*)(cameraBytes + 0x114) == 0)
        {
            int actionAddress;

            actionAddress = *(int*)(cameraBytes + 0xe0);
            if (((actionAddress != 0) &&
                 (*(u16*)((u8*)actionAddress + 0x6a) == 1)) &&
                (*(s32*)(cameraBytes + 0x100) == *(s32*)((u8*)actionAddress + 0x38) &&
                 ((*(u16*)((u8*)actionAddress + 0x1a) & 1) != 0)))
            {
                if (FUN_002a3750(camera, *(u32*)(cameraBytes + 0x120)) != 0)
                {
                    btlUnit002880e0((BtlUnit*)(uintptr_t)*(u32*)(cameraBytes + 0x120),
                                    *(u16*)(cameraBytes + 0x124));
                }
                FUN_002a3e80(10.0f, *(u8**)(cameraBytes + 0xe0),
                             cameraBytes + 0x9c, cameraBytes + 0x104, 0x33);
            }
        }
        else
        {
            action = *(BtlAction**)(cameraBytes + 0xe0);
            if (action != NULL && (action->unk_1a & 1) != 0)
            {
                if (FUN_002a3750(camera, *(u32*)(cameraBytes + 0x120)) != 0)
                {
                    btlUnit002880e0((BtlUnit*)(uintptr_t)*(u32*)(cameraBytes + 0x120),
                                    *(u16*)(cameraBytes + 0x124));
                }
            }
        }
        break;
    case 5:
        func_002ab2a0(camera);
        break;
    case 6:
        action = *(BtlAction**)(cameraBytes + 0xe0);
        if (action != NULL && (action->unk_1a & 1) != 0)
        {
            if (FUN_002a3750(camera, *(u32*)(cameraBytes + 0x120)) != 0)
            {
                btlUnit002880e0((BtlUnit*)(uintptr_t)*(u32*)(cameraBytes + 0x120),
                                *(u16*)(cameraBytes + 0x124));
            }
        }
        break;
    }
}

// FUN_002AC920 NONMATCHING

void func_002ac920(BtlCamera* camera, long unused)
{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined4 uVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined1 auStack_e0 [4];
  float fStack_dc;
  undefined1 auStack_d4 [16];
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  undefined1 auStack_b8 [24];
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  GhidraPair uStack_70;
  float fStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar3 = (int)camera;
  iVar1 = *(int *)(*(int *)(iVar3 + 0xe0) + 0x30);
  iVar6 = *(int *)(*(int *)(*(int *)(iVar3 + 0xe0) + 0x38) + 0x30);
  btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar1), (RwV3d*)&fStack_10);
  btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar6), (RwV3d*)&fStack_20);
  fStack_50 = fStack_10 - fStack_20;
  fStack_4c = fStack_c - fStack_1c;
  fStack_48 = fStack_8 - fStack_18;
  fVar7 = (float)FUN_004c69f0(&fStack_50,&fStack_50);
  fStack_98 = *(float *)(iVar3 + 0x9c) - fStack_10;
  fStack_94 = *(float *)(iVar3 + 0xa4) - fStack_8;
  FUN_004c6b20(&fStack_98,&fStack_98);
  fVar7 = DAT_007cad88 * fVar7;
  fStack_40 = fStack_50 * fVar7 + fStack_20;
  fStack_3c = fStack_4c * fVar7 + fStack_1c;
  fStack_38 = fStack_48 * fVar7 + fStack_18;
  fVar7 = 0.0;
  fVar13 = fStack_50 * fStack_98 + fStack_48 * fStack_94;
  if (0.0 <= fVar13) {
    fStack_30 = fStack_10;
    fStack_2c = fStack_c;
    fStack_28 = fStack_8;
    fVar8 = 1.5;
    fVar9 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) * 1.5;
    fVar11 = DAT_007cad84;
    iVar4 = iVar1;
    if (fStack_c < 125.0) {
      fStack_2c = 125.0;
      fVar8 = 1.5;
    }
  }
  else {
    fStack_30 = fStack_20;
    fStack_2c = fStack_1c;
    fStack_28 = fStack_18;
    if (*(char *)(iVar6 + 0xa2) == '\0') {
      fVar9 = *(float *)(iVar6 + 0x90) * *(float *)(iVar6 + 0x2c) * 1.5;
      fVar8 = 3.5;
    }
    else {
      fVar9 = *(float *)(iVar6 + 0x90) * *(float *)(iVar6 + 0x2c) * 1.25;
      fVar8 = 1.75;
    }
    fVar7 = 0.25;
    fVar11 = fVar7;
    iVar4 = iVar6;
    iVar6 = iVar1;
  }
  fVar2 = fStack_2c;
  fStack_a0 = fStack_48;
  fStack_9c = -fStack_50;
  fVar12 = fStack_48 * fStack_98 + fStack_9c * fStack_94;
  fStack_5c = fVar7 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c) + fStack_2c + 0.0;
  if (0.0 <= fVar12) {
    fStack_60 = fStack_48 * fVar9 + fStack_30 + 0.0;
    fStack_58 = (fStack_28 + 0.0) - fStack_50 * fVar9;
  }
  else {
    fStack_60 = (fStack_30 + 0.0) - fStack_48 * fVar9;
    fStack_58 = fStack_50 * fVar9 + fStack_28 + 0.0;
  }
  uStack_70 = PAIR44(fStack_4c,fStack_50);
  fStack_68 = fStack_48;
  fVar7 = fStack_28;
  FUN_004be1e0(&fStack_50,0x6978a0,1,auStack_b8);
  fStack_90 = fStack_40;
  fStack_8c = fStack_38;
  fStack_88 = fStack_60;
  fStack_84 = fStack_58;
  fStack_78 = fStack_30;
  fStack_74 = fVar7;
  fVar7 = (float)FUN_002d1fd0(&fStack_90,&fStack_88,&fStack_78,&fStack_80);
  fVar9 = fVar8 * *(float *)(iVar4 + 0x90) * *(float *)(iVar4 + 0x2c) + fVar7 + 0.0;
  fStack_60 = fStack_80;
  fStack_5c = fVar2;
  fStack_58 = fStack_7c;
  fVar8 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar3 + 0xb8) * 0.5);
  fVar7 = 500.0;
  if (500.0 <= fVar9 / fVar8) {
    fVar7 = fVar9 / fVar8;
  }
  fStack_50 = fStack_50 * fVar7;
  fStack_4c = fStack_4c * fVar7;
  fStack_48 = fStack_48 * fVar7;
  if (0.0 <= fVar13) {
    if (fVar12 < 0.0) {
      fVar7 = *(float *)(iVar4 + 0x90) * *(float *)(iVar4 + 0x2c);
      fStack_60 = fStack_68 * fVar7 + fStack_60 + 0.0;
      fStack_58 = (fStack_58 + 0.0) - uStack_70.f._0_4_ * fVar7;
    }
  }
  else if (0.0 <= fVar12) {
    fVar7 = *(float *)(iVar4 + 0x90) * *(float *)(iVar4 + 0x2c);
    fStack_60 = (fStack_60 + 0.0) - fStack_68 * fVar7;
    fStack_58 = uStack_70.f._0_4_ * fVar7 + fStack_58 + 0.0;
  }
  fStack_5c = fVar11 * *(float *)(iVar4 + 0x8c) * *(float *)(iVar4 + 0x2c) + fVar2 + 0.0;
  fStack_c4 = fStack_60 + fStack_50;
  fStack_c0 = fStack_5c + fStack_4c;
  fStack_bc = fStack_58 + fStack_48;
  fVar7 = (float)FUN_002d1f30(auStack_d4,auStack_b8);
  if (DAT_007cae24 < fVar7) {
    FUN_004be1e0(&fStack_50,0x6978a0,1,auStack_d4);
    fStack_50 = fStack_50 * 150.0;
    fStack_4c = fStack_4c * 150.0;
    fStack_48 = fStack_48 * 150.0;
    fStack_c4 = fStack_c4 + fStack_50;
    fStack_c0 = fStack_c0 + fStack_4c;
    fStack_bc = fStack_bc + fStack_48;
    uVar5 = 3;
    FUN_00351bb0(0xc);
    uVar10 = 0x3fc00000;
  }
  else {
    uVar5 = 0x33;
    uVar10 = DAT_007cad98;
  }
  if (fStack_dc < 25.0) {
    fStack_dc = 25.0;
  }
  if (fStack_c0 < 25.0) {
    fStack_c0 = 25.0;
  }
  return;
}

// FUN_002ACF90 NONMATCHING

void func_002acf90(BtlCamera* camera, long unused)
{
  short sVar1;
  int iVar2;
  undefined2 uVar3;
  long lVar4;
  u32 uVar5;
  u32 uVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined4 uVar11;
  float fVar12;
  float fVar13;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  undefined1 auStack_f4 [16];
  float fStack_e4;
  float fStack_e0;
  float fStack_dc;
  undefined1 auStack_d8 [24];
  undefined1 auStack_c0 [72];
  float fStack_78;
  float fStack_74;
  GhidraPair uStack_70;
  float fStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar7 = (int)camera;
  if (*(ushort *)(*(int *)(iVar7 + 0xe0) + 0x6a) < 2) {
    uVar3 = 3;
  }
  else {
    uVar3 = FUN_002d1600(*(int *)(iVar7 + 0xe0) + 0x38);
  }
  fVar8 = (float)func_00280870(uVar3,1,&fStack_10,&fStack_4,0,0);
  fStack_c = fStack_4 * 0.75;
  fVar9 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar7 + 0xb8) * 0.5);
  fVar12 = 1000.0;
  if (1000.0 <= fVar8 / fVar9) {
    fVar12 = fVar8 / fVar9;
  }
  func_00280870(uVar3,1,&fStack_20,0,0,1);
  fVar9 = 0.0;
  uVar6 = 0;
  while( 1 ) {
    if (*(ushort *)(*(int *)(iVar7 + 0xe0) + 0x6a) <= uVar6) break;
    iVar2 = *(int *)(*(int *)(iVar7 + 0xe0) + uVar6 * 4 + 0x38);
    if ((*(ushort *)(iVar2 + 0x1a) & 1) != 0) {
      func_00280050(*(undefined4 *)(iVar2 + 0x30),&fStack_60);
      fStack_30 = fStack_20 - fStack_60;
      fStack_2c = fStack_1c - fStack_5c;
      fStack_28 = fStack_18 - fStack_58;
      fVar10 = (float)FUN_004c6ac0(&fStack_30);
      if (fVar9 < fVar10) {
        uStack_70 = PAIR44(fStack_5c,fStack_60);
        fStack_68 = fStack_58;
        fVar9 = fVar10;
      }
    }
    uVar6 = uVar6 + 1 & 0xffff;
  }
  if (fVar9 == 0.0) {
    func_00280050(*(undefined4 *)(*(int *)(gBtl + 0x148) + 0x30),&uStack_70);
  }
  uStack_70 = PAIR44(fStack_c,uStack_70.f._0_4_);
  fStack_30 = uStack_70.f._0_4_ - fStack_10;
  fStack_2c = fStack_c - fStack_c;
  fStack_28 = fStack_68 - fStack_8;
  FUN_004c69f0(&fStack_30,&fStack_30);
  fStack_30 = fStack_30 * fVar8;
  fStack_2c = fStack_2c * fVar8;
  fStack_28 = fStack_28 * fVar8;
  fVar13 = fStack_10 + fStack_30;
  fVar10 = fStack_8 + fStack_28;
  fVar9 = fStack_4 * 1.5;
  fStack_40 = fVar13 - fStack_10;
  fStack_38 = fVar10 - fStack_8;
  fStack_3c = 0.0;
  fVar8 = (float)FUN_004c69f0(&fStack_40,&fStack_40);
  fVar8 = DAT_007cad84 * fVar8;
  fStack_40 = fStack_40 * fVar8;
  fStack_3c = fStack_3c * fVar8;
  fStack_38 = fStack_38 * fVar8;
  fStack_50 = fStack_10 + fStack_40;
  fStack_48 = fStack_8 + fStack_38;
  fStack_4c = fStack_c;
  fStack_2c = 250.0;
  if (250.0 <= fVar9) {
    fStack_2c = fVar9;
  }
  fStack_30 = fVar13 - fStack_50;
  fStack_2c = fStack_2c - fStack_c;
  fStack_28 = fVar10 - fStack_48;
  FUN_004c69f0(&fStack_30,&fStack_30);
  fVar8 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar7 + 0xb8) * 0.5);
  fVar8 = fVar12 * fVar8 * 0.21875;
  fStack_78 = fStack_30;
  fStack_74 = fStack_28;
  FUN_004c6b20(&fStack_78,&fStack_78);
  fStack_50 = fStack_74 * fVar8 + fStack_50 + 0.0;
  fStack_48 = (fStack_48 + 0.0) - fStack_78 * fVar8;
  uVar5 = FUN_00357fd0(0);
  if ((uVar5 & 1) == 0) {
    fVar8 = -7.5;
  }
  else {
    fVar8 = 7.5;
  }
  FUN_004c31b0(fVar8,auStack_c0,0x697880,0);
  FUN_004c6c60(&fStack_40,&fStack_30,auStack_c0);
  fStack_40 = fStack_40 * fVar12;
  fStack_3c = fStack_3c * fVar12;
  fStack_38 = fStack_38 * fVar12;
  fStack_e4 = fStack_50 + fStack_40;
  fStack_e0 = fStack_4c + fStack_3c;
  fStack_dc = fStack_48 + fStack_38;
  if (lVar4 == 0) {
    FUN_004c31b0(-fVar8,auStack_c0,0x697880,0);
    FUN_004c6c60(&fStack_40,&fStack_30,auStack_c0);
    fStack_40 = fStack_40 * fVar12;
    fStack_3c = fStack_3c * fVar12;
    fStack_38 = fStack_38 * fVar12;
    fStack_100 = fStack_50 + fStack_40;
    fStack_fc = fStack_4c + fStack_3c;
    fStack_f8 = fStack_48 + fStack_38;
    FUN_00351bb0(0xc);
    uVar11 = 0x41000000;
  }
  else {
    fStack_100 = fStack_e4;
    fStack_f8 = fStack_dc;
    sVar1 = *(short *)(*(int *)(iVar7 + 0xe0) + 0x6e);
    if (sVar1 == 0x38) {
      fStack_fc = 1000.0;
      fStack_4c = 750.0;
      uVar11 = 0x40200000;
    }
    else if (sVar1 == 0x2c) {
      fStack_fc = 800.0;
      fStack_4c = 700.0;
      uVar11 = 0x40700000;
    }
    else if (sVar1 == 0x27) {
      fStack_fc = 600.0;
      fStack_4c = 550.0;
      uVar11 = 0x40400000;
    }
    else if (sVar1 == 0x26) {
      fStack_fc = 500.0;
      fStack_4c = 450.0;
      uVar11 = 0x40300000;
    }
    else {
      fStack_fc = 500.0;
      fStack_4c = 450.0;
      uVar11 = 0x40300000;
    }
    FUN_00351bb0(0xc);
  }
  return;
}

// FUN_002AD680 NONMATCHING

void func_002ad680(BtlCamera* camera)
{
  undefined2 uVar1;
  
  uVar1 = FUN_002a7830();
  *(undefined2 *)((int)camera + 0x110) = uVar1;
  switch(*(undefined2 *)((int)camera + 0x110)) {
  case 1:
    FUN_002a4c70(0x42340000,0x43480000,camera);
    break;
  case 2:
    func_002ac920(camera,1);
    break;
  case 3:
    func_002acf90(camera,1);
    break;
  case 4:
    func_002ac920(camera,1);
    break;
  case 5:
    func_002acf90(camera,1);
    break;
  case 6:
    FUN_002a79f0(camera,1);
  }
  return;
}

// FUN_002AD770 NONMATCHING

void func_002ad770(BtlCamera* camera)
{
  int iVar1;
  long lVar2;
  int iVar3;
  undefined1 auStack_10 [16];
  
  iVar3 = (int)camera;
  switch(*(undefined2 *)(iVar3 + 0x110)) {
  case 1:
    iVar1 = *(int *)(iVar3 + 0xe0);
    if ((iVar1 != 0) && ((*(ushort *)(iVar1 + 0x1a) & 1) != 0)) {
      iVar1 = *(int *)(iVar1 + 0x30);
      btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar1), (RwV3d*)auStack_10);
      FUN_002a3e80(*(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) * 0.5,
                   (u8*)(uintptr_t)*(undefined4 *)(iVar3 + 0xe0),(u8*)(uintptr_t)(iVar3 + 0x9c),
                   (u8*)auStack_10,0x31);
    }
    break;
  case 6:
    if (((*(int *)(iVar3 + 0xe0) != 0) && ((*(ushort *)(*(int *)(iVar3 + 0xe0) + 0x1a) & 1) != 0))
       && (FUN_002a3750(camera,*(undefined4 *)(iVar3 + 0x120)) != 0)) {
      btlUnit002880e0((BtlUnit*)(uintptr_t)(*(undefined4 *)(iVar3 + 0x120)),*(undefined2 *)(iVar3 + 0x124));
    }
  }
  return;
}


// FUN_002ad880
void func_002ad880(BtlCamera *camera, float angle, float distanceScale, float heightScale, float minimumDistance)
{
  extern f32 FUN_0052e930(f32 angle);
  extern void FUN_004c31b0(RwMatrix *matrix, const RwV3d *axis, f32 angle, s32 mode);
  extern void FUN_004be1e0(RwV3d *out, const RwV3d *basis, s32 mode, void *source);
  extern RwV3d D_00697890;
  typedef struct CameraVectorSlot {
    RwV3d value;
    u32 padding;
  } CameraVectorSlot;
  struct CameraOrbitScratch {
    RwMatrix rotation;
    RwV3d firstPosition;
    u8 firstView[16];
    RwV3d secondPosition;
    u8 secondView[24];
    CameraVectorSlot scaledOffset;
    CameraVectorSlot candidate;
    CameraVectorSlot direction;
    CameraVectorSlot forward;
    CameraVectorSlot center;
    CameraVectorSlot sphereCenter;
  } scratch;
  u8 *unitBytes;
  int cameraAddress;
  float radius;
  float halfHeight;
  float requiredDistance;
  u64 centerXY;
  float centerZ;

  cameraAddress = (int)camera;
  unitBytes = (u8 *)(uintptr_t)*(int *)(*(int *)(cameraAddress + 0xe0) + 0x30);
  btlUnitGetSphereWorldCenter((BtlUnit *)unitBytes, &scratch.sphereCenter.value);
  radius = *(float *)(unitBytes + 0x90) * *(float *)(unitBytes + 0x2c);
  halfHeight = *(float *)(unitBytes + 0x8c) * *(float *)(unitBytes + 0x2c) * 0.5f;
  centerXY = *(volatile u64 *)&scratch.sphereCenter.value;
  centerZ = *(volatile f32 *)&scratch.sphereCenter.value.z;
  *(u64 *)&scratch.center.value = centerXY;
  scratch.center.value.z = centerZ;
  scratch.center.value.y = halfHeight * heightScale + scratch.center.value.y + 0.0f;
  if (radius > halfHeight) {
    requiredDistance = (radius * distanceScale) /
      FUN_0052e930(DAT_007cad60 * (*(float *)(cameraAddress + 0xb8) * 0.5f));
  } else {
    requiredDistance = (halfHeight * distanceScale) /
      FUN_0052e930(*(float *)(cameraAddress + 0xb8) * 0.5f);
  }
  if (requiredDistance < minimumDistance) {
    requiredDistance = minimumDistance;
  }
  FUN_004be1e0(&scratch.forward.value, &D_00697890, 1, (void *)(unitBytes + 0x1c));
  scratch.scaledOffset.value.x = scratch.forward.value.x * radius;
  scratch.scaledOffset.value.y = scratch.forward.value.y * radius;
  scratch.scaledOffset.value.z = scratch.forward.value.z * radius;
  scratch.candidate.value.x = scratch.center.value.x + scratch.scaledOffset.value.x;
  scratch.candidate.value.y = scratch.center.value.y + scratch.scaledOffset.value.y;
  scratch.candidate.value.z = scratch.center.value.z + scratch.scaledOffset.value.z;
  scratch.candidate.value.y = DAT_007cada4 * halfHeight + scratch.candidate.value.y + 0.0f;
  scratch.direction.value.x = scratch.candidate.value.x - scratch.center.value.x;
  scratch.direction.value.y = scratch.candidate.value.y - scratch.center.value.y;
  scratch.direction.value.z = scratch.candidate.value.z - scratch.center.value.z;
  FUN_004c69f0(&scratch.direction.value, &scratch.direction.value);
  scratch.scaledOffset.value.x = scratch.direction.value.x * requiredDistance;
  scratch.scaledOffset.value.y = scratch.direction.value.y * requiredDistance;
  scratch.scaledOffset.value.z = scratch.direction.value.z * requiredDistance;
  FUN_004c31b0(&scratch.rotation, &D_00697880, angle, 0);
  FUN_004c6c60(&scratch.direction.value, &scratch.scaledOffset.value, &scratch.rotation);
  scratch.candidate.value.x = scratch.center.value.x + scratch.direction.value.x;
  scratch.candidate.value.y = scratch.center.value.y + scratch.direction.value.y;
  scratch.candidate.value.z = scratch.center.value.z + scratch.direction.value.z;
  FUN_002a4690(scratch.firstView, &scratch.candidate.value, &scratch.center.value, &D_00697880);
  scratch.firstPosition.x = scratch.center.value.x + scratch.direction.value.x;
  scratch.firstPosition.y = scratch.center.value.y + scratch.direction.value.y;
  scratch.firstPosition.z = scratch.center.value.z + scratch.direction.value.z;
  FUN_004c31b0(&scratch.rotation, &D_00697880, -angle, 0);
  FUN_004c6c60(&scratch.direction.value, &scratch.scaledOffset.value, &scratch.rotation);
  scratch.candidate.value.x = scratch.center.value.x + scratch.direction.value.x;
  scratch.candidate.value.y = scratch.center.value.y + scratch.direction.value.y;
  scratch.candidate.value.z = scratch.center.value.z + scratch.direction.value.z;
  FUN_002a4690(scratch.secondView, &scratch.candidate.value, &scratch.center.value, &D_00697880);
  scratch.secondPosition.x = scratch.center.value.x + scratch.direction.value.x;
  scratch.secondPosition.y = scratch.center.value.y + scratch.direction.value.y;
  scratch.secondPosition.z = scratch.center.value.z + scratch.direction.value.z;
  FUN_002a3e80(0.0f, *(u8 **)(cameraAddress + 0xe0), NULL, NULL, 1);
  FUN_002a2290((u16 *)camera, &scratch.firstPosition, &scratch.secondPosition, 1);
  FUN_002a3110(3.5f, (u16 *)camera);
}

// FUN_002ADC30

void func_002adc30(BtlCamera* camera)
{
  func_002ad880(camera,10.0f,2.0f,0.0f,250.0f);
  return;
}

// FUN_002ADC70
void btlCameraNoop002adc70(void)
{
}

// FUN_002ADC80
void func_002adc80(BtlCamera* camera)

{
  func_002ad880(camera,15.0f,2.0f,0.25f,400.0f);
  return;
}

// FUN_002ADCC0
void btlCameraNoop002adcc0(void)
{
}

// FUN_002ADCD0

void func_002adcd0(BtlCamera* camera)
{
  FUN_002a8d20(camera,1);
  return;
}

// FUN_002ADD00

void func_002ADD00(void)
{
  return;
}

// FUN_002ADD10 NONMATCHING

u32 func_002add10(BtlCamera* camera, u32 param_2, float* param_3, float* param_4)
{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined1 auStack_a0 [16];
  float afStack_90 [3];
  undefined1 auStack_84 [16];
  float afStack_74 [3];
  undefined1 auStack_68 [24];
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  fVar3 = (float)func_00280870(2,0,&fStack_50,&fStack_4,0,1);
  fStack_4c = DAT_007cadb4 * fStack_4;
  iVar1 = *(int *)(*(int *)(camera + 0xe0) + 0x30);
  fVar7 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) * DAT_007cadfc;
  btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar1), (RwV3d*)&fStack_40);
  func_002d1de0(auStack_a0,&fStack_40,&fStack_50);
  fStack_3c = DAT_007cad54 * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) + fStack_3c + 0.0;
  FUN_004be1e0(&fStack_10,0x697870,1,auStack_a0);
  fVar6 = fStack_10 * fVar7;
  fStack_c = fStack_c * fVar7;
  fStack_8 = fStack_8 * fVar7;
  fStack_40 = fStack_40 + fVar6;
  fStack_3c = fStack_3c + fStack_c;
  fStack_38 = fStack_38 + fStack_8;
  fStack_20 = fStack_40 - fStack_50;
  fStack_1c = fStack_3c - fStack_4c;
  fStack_18 = fStack_38 - fStack_48;
  fVar6 = (float)FUN_004c69f0(&fStack_20,&fStack_20);
  fVar7 = DAT_007cad74 * fVar6;
  fStack_30 = fStack_20 * fVar7 + fStack_50;
  fStack_2c = fStack_1c * fVar7 + fStack_4c;
  fStack_28 = fStack_18 * fVar7 + fStack_48;
  fStack_10 = fStack_40;
  fStack_c = fStack_3c;
  fStack_8 = fStack_38;
  fVar7 = (float)FUN_002d1f30(auStack_84,auStack_68);
  if (DAT_007cae00 < fVar7) {
    param_2 = 1;
  }
  fVar7 = *(float *)(iVar1 + 0x8c);
  fVar4 = *(float *)(iVar1 + 0x2c);
  fVar5 = (float)FUN_0052e930(*(float *)(camera + 0xb8) * 0.5);
  fVar6 = (fVar7 * fVar4) / fVar5 + fVar6;
  fVar7 = (float)FUN_0052e930(*(float *)(camera + 0xb8) * 0.5);
  fVar7 = (fVar3 * 0.875) / fVar7;
  if (fVar6 <= fVar7) {
    fVar6 = fVar7;
  }
  FUN_004be1e0(&fStack_10,0x6978a0,1,auStack_68);
  fVar7 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(camera + 0xb8) * 0.5);
  fVar7 = fVar6 * fVar7 * 0.109375 * 1.25;
  fStack_50 = fStack_8 * fVar7 + fStack_50 + 0.0;
  fStack_48 = (fStack_48 + 0.0) - fStack_10 * fVar7;
  fStack_10 = fStack_10 * fVar6;
  fStack_c = fStack_c * fVar6;
  fStack_8 = fStack_8 * fVar6;
  afStack_74[0] = fStack_50 + fStack_10;
  afStack_74[1] = fStack_4c + fStack_c;
  afStack_74[2] = fStack_48 + fStack_8;
  if (afStack_90[1] < 25.0) {
    afStack_90[1] = 25.0;
  }
  if (afStack_74[1] < 25.0) {
    afStack_74[1] = 25.0;
  }
  if (param_3 != (float *)0x0) {
    pfVar2 = afStack_90;
    iVar1 = 7;
    do {
      fVar6 = *pfVar2;
      pfVar2 = pfVar2 + 1;
      iVar1 = iVar1 + -1;
      *param_3 = fVar6;
      param_3 = param_3 + 1;
    } while (0 < iVar1);
  }
  if (param_4 != (float *)0x0) {
    pfVar2 = afStack_74;
    iVar1 = 7;
    do {
      fVar6 = *pfVar2;
      pfVar2 = pfVar2 + 1;
      iVar1 = iVar1 + -1;
      *param_4 = fVar6;
      param_4 = param_4 + 1;
    } while (0 < iVar1);
  }
  return param_2;
}

// FUN_002AE150 NONMATCHING

void func_002ae150(BtlCamera* camera)
{
  short sVar1;
  long lVar2;
  undefined8 uVar3;
  undefined1 auStack_40 [28];
  undefined1 auStack_24 [36];
  
  sVar1 = *(short *)(gBtl + 0x104);
  if ((((sVar1 == 0x23) || (sVar1 == 2)) || (sVar1 == 0x22)) || (sVar1 == 0x1d)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  lVar2 = func_002add10(camera,uVar3,(float*)auStack_40,(float*)auStack_24);
  if (lVar2 == 0) {
  }
  else {
    FUN_00351bb0(8);
  }
  return;
}

// FUN_002AE260 NONMATCHING

void func_002ae260(BtlCamera* camera)
{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar2 = (int)camera;
  iVar1 = *(int *)(*(int *)(iVar2 + 0xe0) + 0x30);
  btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar1), (RwV3d*)&fStack_10);
  fVar5 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
  fVar4 = *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) * 0.5;
  fStack_c = fVar4 * 0.25 + fStack_c + 0.0;
  if (fVar4 < fVar5) {
    fVar3 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar2 + 0xb8) * 0.5);
    fVar3 = (fVar5 * 1.25) / fVar3;
  }
  else {
    fVar3 = (float)FUN_0052e930(*(float *)(iVar2 + 0xb8) * 0.5);
    fVar3 = (fVar4 * 1.25) / fVar3;
  }
  FUN_004be1e0(&fStack_20,0x697890,1,iVar1 + 0x1c);
  fVar4 = fVar3 + 125.0;
  fVar5 = fStack_20 * fVar4;
  fVar6 = fStack_1c * fVar4;
  fVar4 = fStack_18 * fVar4;
  fStack_30 = fStack_10 + fVar5;
  fStack_2c = fStack_c + fVar6;
  fStack_28 = fStack_8 + fVar4;
  fStack_70 = fStack_10 + fVar5;
  fStack_6c = fStack_c + fVar6;
  fStack_68 = fStack_8 + fVar4;
  uStack_48 = uStack_64;
  uStack_44 = uStack_60;
  uStack_40 = uStack_5c;
  uStack_3c = uStack_58;
  fStack_54 = fStack_20 * fVar3 + fStack_10 + 0.0;
  fStack_50 = fStack_1c * fVar3 + fStack_c + 0.0;
  fStack_4c = fStack_18 * fVar3 + fStack_8 + 0.0;
  return;
}

// FUN_002AE4D0 NONMATCHING

void func_002ae4d0(BtlCamera* camera)
{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar2 = (int)camera;
  iVar1 = *(int *)(*(int *)(iVar2 + 0xe0) + 0x30);
  btlUnitGetSphereWorldCenter((BtlUnit*)(uintptr_t)(iVar1), (RwV3d*)&fStack_10);
  fVar5 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
  fVar4 = *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) * 0.5;
  fStack_c = fVar4 * 0.25 + fStack_c + 0.0;
  if (fVar4 < fVar5) {
    fVar3 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar2 + 0xb8) * 0.5);
    fVar3 = (fVar5 * 1.5) / fVar3;
  }
  else {
    fVar3 = (float)FUN_0052e930(*(float *)(iVar2 + 0xb8) * 0.5);
    fVar3 = (fVar4 * 1.5) / fVar3;
  }
  FUN_004be1e0(&fStack_20,0x697890,1,iVar1 + 0x1c);
  fVar4 = fVar3 + 125.0;
  fVar5 = fStack_20 * fVar4;
  fVar6 = fStack_1c * fVar4;
  fVar4 = fStack_18 * fVar4;
  fStack_30 = fStack_10 + fVar5;
  fStack_2c = fStack_c + fVar6;
  fStack_28 = fStack_8 + fVar4;
  fStack_70 = fStack_10 + fVar5;
  fStack_6c = fStack_c + fVar6;
  fStack_68 = fStack_8 + fVar4;
  uStack_48 = uStack_64;
  uStack_44 = uStack_60;
  uStack_40 = uStack_5c;
  uStack_3c = uStack_58;
  fStack_54 = fStack_20 * fVar3 + fStack_10 + 0.0;
  fStack_50 = fStack_1c * fVar3 + fStack_c + 0.0;
  fStack_4c = fStack_18 * fVar3 + fStack_8 + 0.0;
  return;
}

// FUN_002AE740 NONMATCHING

void func_002ae740(BtlCamera* camera, long param_2)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  int iStack_ec;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  undefined1 auStack_d4 [16];
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  undefined1 auStack_b8 [24];
  undefined1 auStack_a0 [28];
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float afStack_60 [2];
  float fStack_58;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar5 = (int)camera;
  iVar1 = *(int *)(iVar5 + 0xe0);
  uVar2 = *(undefined4 *)(iVar1 + 0x30);
  iVar3 = FUN_002c0880(iVar1 + 0x88);
  fVar6 = (float)func_00280870(3,lVar4 == 0,&fStack_30,&fStack_4,&fStack_8,1);
  fStack_2c = (fStack_4 - fStack_8) * 0.5 + fStack_8 + 0.0;
  fVar7 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar5 + 0xb8) * 0.5);
  fVar7 = (DAT_007cae18 * fVar6) / fVar7;
  func_00280050(uVar2,afStack_60);
  fStack_40 = afStack_60[0];
  fStack_3c = fStack_2c;
  fStack_38 = fStack_58;
  fStack_50 = afStack_60[0] - fStack_30;
  fStack_4c = fStack_2c - fStack_2c;
  fStack_48 = fStack_58 - fStack_28;
  fVar6 = (float)FUN_004c69f0(&fStack_50,&fStack_50);
  fVar6 = fVar6 * 0.5;
  fStack_50 = fStack_50 * fVar6;
  fStack_4c = fStack_4c * fVar6;
  fStack_48 = fStack_48 * fVar6;
  fStack_20 = fStack_30 + fStack_50;
  fStack_1c = fStack_2c + fStack_4c;
  fStack_18 = fStack_28 + fStack_48;
  fStack_40 = afStack_60[0];
  fStack_3c = fStack_4 * 2.0;
  fStack_38 = fStack_58;
  FUN_004be1e0(&fStack_50,0x6978a0,1,auStack_d4);
  fStack_50 = fStack_50 * fVar7;
  fStack_4c = fStack_4c * fVar7;
  fStack_48 = fStack_48 * fVar7;
  fVar6 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar5 + 0xb8) * 0.5);
  fVar6 = fVar7 * fVar6 * 0.21875;
  fStack_10 = fStack_50;
  fStack_c = fStack_48;
  FUN_004c6b20(&fStack_10,&fStack_10);
  fStack_20 = fStack_c * fVar6 + fStack_20 + 0.0;
  fStack_18 = (fStack_18 + 0.0) - fStack_10 * fVar6;
  fStack_e0 = fStack_20 + fStack_50;
  fStack_dc = fStack_1c + fStack_4c;
  fStack_d8 = fStack_18 + fStack_48;
  if (iVar1 == iVar3) {
    if (*(short *)(iVar5 + 0x106) == 0) {
      fStack_40 = afStack_60[0];
      fStack_3c = fStack_2c;
      fStack_38 = fStack_58;
      fStack_50 = afStack_60[0] - fStack_30;
      fStack_4c = fStack_2c - fStack_2c;
      fStack_48 = fStack_58 - fStack_28;
      fVar8 = (float)FUN_004c69f0(&fStack_50,&fStack_50);
      fVar6 = DAT_007cae18 * fVar8;
      fStack_20 = fStack_30 + fStack_50 * fVar6;
      fStack_1c = fStack_2c + fStack_4c * fVar6;
      fStack_18 = fStack_28 + fStack_48 * fVar6;
      fStack_40 = fStack_50 * fVar8 * 0.5 + afStack_60[0];
      fStack_3c = fStack_4 * 1.5;
      fStack_38 = fStack_48 * fVar8 * 0.5 + fStack_58;
      FUN_004be1e0(&fStack_50,0x6978a0,1,&fStack_78);
      fStack_50 = fStack_50 * fVar7;
      fStack_4c = fStack_4c * fVar7;
      fStack_48 = fStack_48 * fVar7;
      fVar6 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar5 + 0xb8) * 0.5);
      fVar6 = fVar7 * fVar6 * 0.21875;
      fStack_10 = fStack_50;
      fStack_c = fStack_48;
      FUN_004c6b20(&fStack_10,&fStack_10);
      fStack_20 = fStack_c * fVar6 + fStack_20 + 0.0;
      fStack_18 = (fStack_18 + 0.0) - fStack_10 * fVar6;
      fStack_84 = fStack_20 + fStack_50;
      fStack_80 = fStack_1c + fStack_4c;
      fStack_7c = fStack_18 + fStack_48;
    }
    else {
    }
  }
  else {
    func_00280050(*(undefined4 *)(iVar3 + 0x30),&fStack_20);
    FUN_004be1e0(&fStack_50,0x6978a0,1,auStack_b8);
    fStack_50 = fStack_50 * fVar7;
    fStack_4c = fStack_4c * fVar7;
    fStack_48 = fStack_48 * fVar7;
    fVar6 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar5 + 0xb8) * 0.5);
    fVar6 = fVar7 * fVar6 * 0.21875;
    fStack_10 = fStack_50;
    fStack_c = fStack_48;
    FUN_004c6b20(&fStack_10,&fStack_10);
    fStack_20 = fStack_c * fVar6 + fStack_20 + 0.0;
    fStack_18 = (fStack_18 + 0.0) - fStack_10 * fVar6;
    fStack_c4 = fStack_20 + fStack_50;
    fStack_c0 = fStack_1c + fStack_4c;
    fStack_bc = fStack_18 + fStack_48;
    if (*(short *)(iVar5 + 0x106) == 0) {
      FUN_004be310(auStack_d4,auStack_b8,&fStack_110);
      fVar6 = DAT_007cad94;
      fVar7 = DAT_007cad84;
      if (iStack_ec == 0) {
        fVar7 = DAT_007cad94 * fStack_f0;
        fVar6 = fVar7 * fVar7;
        fVar6 = fVar6 * fVar7 *
                (fVar6 * (fVar6 * (fVar6 * (fVar6 * (DAT_007cae04 * fVar6 + DAT_007cad38 + 0.0) +
                                           DAT_007cae08 + 0.0) + DAT_007cad40 + 0.0) +
                         DAT_007cad44 + 0.0) + DAT_007cad48 + 0.0) + fVar7 + 0.0;
        fStack_f0 = DAT_007cad84 * fStack_f0;
        fVar7 = fStack_f0 * fStack_f0;
        fVar7 = fVar7 * fStack_f0 *
                (fVar7 * (fVar7 * (fVar7 * (fVar7 * (DAT_007cae04 * fVar7 + DAT_007cad38 + 0.0) +
                                           DAT_007cae08 + 0.0) + DAT_007cad40 + 0.0) +
                         DAT_007cad44 + 0.0) + DAT_007cad48 + 0.0) + fStack_f0 + 0.0;
      }
      fStack_78 = fStack_100 * fVar7 + fStack_110 * fVar6 + 0.0;
      fStack_74 = fStack_fc * fVar7 + fStack_10c * fVar6 + 0.0;
      fStack_70 = fStack_f8 * fVar7 + fStack_108 * fVar6 + 0.0;
      fStack_6c = fStack_104 * fVar6 + fStack_f4 * fVar7;
      fStack_e0 = fStack_e0 * DAT_007cad94;
      fStack_dc = fStack_dc * DAT_007cad94;
      fStack_d8 = fStack_d8 * DAT_007cad94;
      fStack_c4 = fStack_c4 * DAT_007cad84;
      fStack_c0 = fStack_c0 * DAT_007cad84;
      fStack_bc = fStack_bc * DAT_007cad84;
      fStack_84 = fStack_e0 + fStack_c4;
      fStack_80 = fStack_dc + fStack_c0;
      fStack_7c = fStack_d8 + fStack_bc;
    }
    else {
    }
  }
  if (param_2 == 0) {
  }
  else {
  }
  return;
}

// FUN_002AEF80 NONMATCHING

void func_002aef80(BtlCamera* camera, long param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  float fStack_134;
  float fStack_130;
  float fStack_12c;
  float fStack_128;
  float fStack_124;
  float fStack_120;
  int iStack_11c;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  undefined1 auStack_104 [16];
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  undefined1 auStack_e8 [24];
  undefined1 auStack_d0 [28];
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  undefined1 auStack_8 [4];
  float fStack_4;
  
  iVar3 = (int)camera;
  iVar1 = *(int *)(iVar3 + 0xe0);
  iVar2 = FUN_002c0880(iVar1 + 0x88);
  iVar1 = *(int *)(iVar1 + 0x30);
  fVar5 = (float)func_00280870(1 << (*(byte *)(*(int *)(iVar2 + 0x30) + 0xa2) & 0x1f) & 0xffff,1,
                              &fStack_18,&fStack_4,auStack_8,1);
  func_00280050(iVar1,&fStack_58);
  fVar4 = *(float *)(iVar1 + 0x2c);
  fVar6 = *(float *)(iVar1 + 0x8c);
  fVar7 = *(float *)(iVar1 + 0x90) * fVar4;
  func_00280050(*(undefined4 *)(iVar2 + 0x30),&fStack_68);
  fStack_54 = fStack_54 + fVar6 * fVar4 * 0.5;
  if (fStack_14 < fStack_54) {
    fStack_14 = fStack_54 * 0.5;
  }
  if (fStack_54 <= fStack_4) {
    fStack_54 = fStack_4;
  }
  fStack_4 = fStack_54;
  fStack_20 = fStack_50;
  fStack_38 = fStack_58 - fStack_18;
  fStack_34 = fStack_14 - fStack_14;
  fStack_30 = fStack_50 - fStack_10;
  FUN_004c69f0(&fStack_38,&fStack_38);
  fVar4 = fStack_50;
  fVar6 = DAT_007cad7c * fVar5;
  fStack_18 = fStack_18 + fStack_38 * fVar6;
  fStack_14 = fStack_14 + fStack_34 * fVar6;
  fStack_10 = fStack_10 + fStack_30 * fVar6;
  fStack_88 = fStack_50;
  fStack_38 = fStack_58 - fStack_18;
  fStack_34 = fStack_14 - fStack_14;
  fStack_30 = fStack_50 - fStack_10;
  FUN_004c69f0(&fStack_38,&fStack_38);
  fVar6 = (float)FUN_0052e930(*(float *)(iVar3 + 0xb8) * 0.5);
  fVar6 = fVar7 + fStack_14 / fVar6;
  fStack_38 = fStack_38 * fVar6;
  fStack_34 = fStack_34 * fVar6;
  fStack_30 = fStack_30 * fVar6;
  fStack_48 = fStack_90 + fStack_38;
  fStack_40 = fVar4 + fStack_30;
  fStack_44 = DAT_007cae0c * fStack_4;
  fVar4 = (float)FUN_002d1e70(&fStack_48,&fStack_18);
  fVar6 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar3 + 0xb8) * 0.5);
  fVar6 = (DAT_007cadf0 * fVar5) / fVar6;
  FUN_004be1e0(&fStack_38,0x6978a0,1,auStack_104);
  if (fVar4 <= fVar6) {
    fVar4 = fVar6;
  }
  fVar6 = 1100.0;
  if (1100.0 <= fVar4) {
    fVar6 = fVar4;
  }
  fStack_38 = fStack_38 * fVar6;
  fStack_34 = fStack_34 * fVar6;
  fStack_30 = fStack_30 * fVar6;
  fVar4 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar3 + 0xb8) * 0.5);
  fVar4 = fVar6 * fVar4 * 0.21875;
  fStack_70 = fStack_38;
  fStack_6c = fStack_30;
  FUN_004c6b20(&fStack_70,&fStack_70);
  fStack_18 = fStack_6c * fVar4 + fStack_18 + 0.0;
  fStack_10 = (fStack_10 + 0.0) - fStack_70 * fVar4;
  fStack_110 = fStack_18 + fStack_38;
  fStack_10c = fStack_14 + fStack_34;
  fStack_108 = fStack_10 + fStack_30;
  fStack_78 = fStack_50;
  fStack_38 = fStack_58 - fStack_68;
  fStack_34 = fStack_14 - fStack_64;
  fStack_30 = fStack_50 - fStack_60;
  FUN_004c69f0(&fStack_38,&fStack_38);
  fVar4 = (float)FUN_0052e930(*(float *)(iVar3 + 0xb8) * 0.5);
  fVar7 = fVar7 + fStack_14 / fVar4;
  fStack_38 = fStack_38 * fVar7;
  fStack_34 = fStack_34 * fVar7;
  fStack_30 = fStack_30 * fVar7;
  fStack_48 = fStack_80 + fStack_38;
  fStack_40 = fStack_50 + fStack_30;
  fStack_44 = DAT_007cae0c * fStack_4;
  fVar4 = (float)FUN_002d1e70(&fStack_48,&fStack_68);
  fVar7 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar3 + 0xb8) * 0.5);
  fVar7 = (DAT_007cadb0 * fVar5) / fVar7;
  FUN_004be1e0(&fStack_38,0x6978a0,1,auStack_e8);
  if (fVar4 <= fVar7) {
    fVar4 = fVar7;
  }
  fVar7 = 1100.0;
  if (1100.0 <= fVar4) {
    fVar7 = fVar4;
  }
  fStack_38 = fStack_38 * fVar7;
  fStack_34 = fStack_34 * fVar7;
  fStack_30 = fStack_30 * fVar7;
  fVar4 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar3 + 0xb8) * 0.5);
  fVar4 = fVar7 * fVar4 * 0.21875;
  fStack_70 = fStack_38;
  fStack_6c = fStack_30;
  FUN_004c6b20(&fStack_70,&fStack_70);
  fStack_18 = fStack_6c * fVar4 + fStack_18 + 0.0;
  fStack_10 = (fStack_10 + 0.0) - fStack_70 * fVar4;
  fStack_f4 = fStack_68 + fStack_38;
  fStack_f0 = fStack_64 + fStack_34;
  fStack_ec = fStack_60 + fStack_30;
  if (*(short *)(iVar3 + 0x106) == 0) {
    FUN_004be310(auStack_104,auStack_e8,&fStack_140);
    fVar4 = DAT_007cae10;
    fVar7 = DAT_007cae14;
    if (iStack_11c == 0) {
      fVar7 = DAT_007cae10 * fStack_120;
      fVar4 = fVar7 * fVar7;
      fVar4 = fVar4 * fVar7 *
              (fVar4 * (fVar4 * (fVar4 * (fVar4 * (DAT_007cae04 * fVar4 + DAT_007cad38 + 0.0) +
                                         DAT_007cae08 + 0.0) + DAT_007cad40 + 0.0) +
                       DAT_007cad44 + 0.0) + DAT_007cad48 + 0.0) + fVar7 + 0.0;
      fStack_120 = DAT_007cae14 * fStack_120;
      fVar7 = fStack_120 * fStack_120;
      fVar7 = fVar7 * fStack_120 *
              (fVar7 * (fVar7 * (fVar7 * (fVar7 * (DAT_007cae04 * fVar7 + DAT_007cad38 + 0.0) +
                                         DAT_007cae08 + 0.0) + DAT_007cad40 + 0.0) +
                       DAT_007cad44 + 0.0) + DAT_007cad48 + 0.0) + fStack_120 + 0.0;
    }
    fStack_a8 = fStack_130 * fVar7 + fStack_140 * fVar4 + 0.0;
    fStack_a4 = fStack_12c * fVar7 + fStack_13c * fVar4 + 0.0;
    fStack_a0 = fStack_128 * fVar7 + fStack_138 * fVar4 + 0.0;
    fStack_9c = fStack_134 * fVar4 + fStack_124 * fVar7;
    fStack_110 = fStack_110 * DAT_007cae10;
    fStack_10c = fStack_10c * DAT_007cae10;
    fStack_108 = fStack_108 * DAT_007cae10;
    fStack_f4 = fStack_f4 * DAT_007cae14;
    fStack_f0 = fStack_f0 * DAT_007cae14;
    fStack_ec = fStack_ec * DAT_007cae14;
    fStack_b4 = fStack_110 + fStack_f4;
    fStack_b0 = fStack_10c + fStack_f0;
    fStack_ac = fStack_108 + fStack_ec;
  }
  else {
  }
  if (param_2 == 0) {
  }
  else {
  }
  return;
}

// FUN_002AF7F0 NONMATCHING

void func_002af7f0(BtlCamera* camera)
{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = *(int *)(camera + 0xe0);
  uVar2 = FUN_002bff60(iVar1,0,*(undefined2 *)(iVar1 + 0x6e),0);
  *(undefined2 *)(camera + 0x106) = uVar2;
  uVar2 = FUN_002c09f0(iVar1 + 0x88);
  *(undefined2 *)(camera + 0x104) = uVar2;
  *(undefined4 *)(camera + 0x100) = 0;
  return;
}

// FUN_002AF850 NONMATCHING

void func_002af850(BtlCamera* camera)
{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  iVar4 = (int)camera;
  iVar3 = FUN_002c0880(*(int *)(iVar4 + 0xe0) + 0x88);
  if (((iVar3 != 0) && (iVar2 = *(int *)(iVar4 + 0x100), iVar2 != iVar3)) &&
     ((iVar2 == 0 || (*(short *)(iVar4 + 0x106) == 0)))) {
    if (iVar2 == 0) {
      sVar1 = *(short *)(gBtl + 0x104);
      if ((((sVar1 == 0x23) || (sVar1 == 2)) || (sVar1 == 0x22)) || (sVar1 == 0x1c)) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
    }
    else {
      uVar5 = 0;
    }
    *(int *)(iVar4 + 0x100) = iVar3;
    if ((*(short *)(iVar4 + 0x104) == 1) || (*(short *)(iVar4 + 0x104) != 2)) {
      func_002ae740(camera,0);
    }
    else {
      func_002aef80(camera,uVar5);
    }
  }
  return;
}

// FUN_002AF960 NONMATCHING

void func_002af960(BtlCamera* camera)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float afStack_130 [2];
  float fStack_128;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_114;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  int iStack_cc;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  undefined4 uStack_78;
  float fStack_74;
  float fStack_70;
  GhidraPair uStack_68;
  float fStack_60;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_8;
  float fStack_4;
  
  iVar4 = (int)camera;
  iVar1 = *(int *)(*(int *)(iVar4 + 0xe0) + 0x30);
  iVar2 = *(int *)(*(int *)(iVar4 + 0xe0) + 0x38);
  iVar3 = *(int *)(iVar2 + 0x30);
  *(int *)(iVar4 + 0x118) = iVar2;
  uStack_78 = *(undefined4 *)(iVar1 + 0xdc);
  fStack_74 = *(float *)(iVar1 + 0x84) * *(float *)(iVar1 + 0x2c);
  fStack_70 = *(float *)(iVar1 + 0xe4);
  FUN_002802d0(iVar3,iVar1,&fStack_88);
  fVar10 = DAT_007cad84 * *(float *)(iVar1 + 0x8c) * *(float *)(iVar1 + 0x2c) + fStack_74 + 0.0 +
           DAT_007cad84 * *(float *)(iVar3 + 0x8c) * *(float *)(iVar3 + 0x2c) + fStack_84 + 0.0;
  fVar9 = *(float *)(iVar3 + 0x90) * *(float *)(iVar3 + 0x2c) +
          *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) + *(float *)(iVar1 + 0xe8) + 0.0;
  fStack_84 = 0.0;
  fStack_74 = 0.0;
  fStack_38 = *(float *)(iVar1 + 0xdc) - fStack_88;
  fStack_34 = *(float *)(iVar1 + 0xe0) - 0.0;
  fStack_30 = *(float *)(iVar1 + 0xe4) - fStack_80;
  FUN_004c69f0(&fStack_38,&fStack_38);
  fVar5 = fVar9 * 0.25;
  fStack_58 = fStack_38 * fVar5 + fStack_88;
  fStack_50 = fStack_30 * fVar5 + fStack_80;
  fVar8 = fVar10 * 0.5;
  fStack_20 = fStack_128;
  fStack_28 = afStack_130[0];
  *(float *)(iVar4 + 0x10c) = *(float *)(iVar1 + 0xe8) * 0.5;
  *(float *)(iVar4 + 0x100) = fStack_58;
  *(float *)(iVar4 + 0x104) = fVar8;
  *(float *)(iVar4 + 0x108) = fStack_50;
  fStack_54 = fVar8;
  fStack_24 = fVar10;
  fVar9 = *(float *)(iVar3 + 0x90) * *(float *)(iVar3 + 0x2c) +
          *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c) + fVar9 + 0.0;
  fVar5 = (float)FUN_002d1f30(&fStack_124,&fStack_108);
  if (DAT_007cade0 < fVar5) {
    fVar5 = DAT_007cade0 / fVar5;
    FUN_004be310(&fStack_124,&fStack_108,&fStack_f0);
    if (fVar5 <= 0.0) {
      fStack_a0 = fStack_124;
      fStack_9c = fStack_120;
      fStack_98 = fStack_11c;
      fStack_94 = fStack_118;
    }
    else if (1.0 <= fVar5) {
      fStack_a0 = fStack_108;
      fStack_9c = fStack_104;
      fStack_98 = fStack_100;
      fStack_94 = fStack_fc;
    }
    else {
      fVar10 = 1.0 - fVar5;
      if (iStack_cc == 0) {
        fVar10 = fVar10 * fStack_d0;
        fVar6 = fVar10 * fVar10;
        fVar10 = fVar6 * fVar10 *
                 (fVar6 * (fVar6 * (fVar6 * (fVar6 * (DAT_007caddc * fVar6 + DAT_007cad38 + 0.0) +
                                            DAT_007cad3c + 0.0) + DAT_007cad40 + 0.0) +
                          DAT_007cad44 + 0.0) + DAT_007cad48 + 0.0) + fVar10 + 0.0;
        fVar5 = fVar5 * fStack_d0;
        fVar6 = fVar5 * fVar5;
        fVar5 = fVar6 * fVar5 *
                (fVar6 * (fVar6 * (fVar6 * (fVar6 * (DAT_007caddc * fVar6 + DAT_007cad38 + 0.0) +
                                           DAT_007cad3c + 0.0) + DAT_007cad40 + 0.0) +
                         DAT_007cad44 + 0.0) + DAT_007cad48 + 0.0) + fVar5 + 0.0;
      }
      fStack_a0 = fStack_e0 * fVar5 + fStack_f0 * fVar10 + 0.0;
      fStack_9c = fStack_dc * fVar5 + fStack_ec * fVar10 + 0.0;
      fStack_98 = fStack_d8 * fVar5 + fStack_e8 * fVar10 + 0.0;
      fStack_94 = fStack_e4 * fVar10 + fStack_d4 * fVar5;
    }
    FUN_004be1e0(&fStack_28,0x6978a0,1,&fStack_a0);
    fStack_28 = fStack_28 + fStack_58;
    fStack_24 = fStack_24 + fStack_54;
    fStack_20 = fStack_20 + fStack_50;
  }
  else if (fVar5 < DAT_007cade4) {
    FUN_004bdde0(DAT_007cade8,&fStack_108,0x697880,2);
  }
  fVar5 = 450.0;
  if (450.0 <= fVar9) {
    fVar5 = fVar9;
  }
  fVar9 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar4 + 0xb8) * 0.5);
  fVar9 = (fVar5 * 0.5) / fVar9;
  FUN_004be1e0(&fStack_28,0x6978a0,1,&fStack_108);
  fStack_34 = fStack_24;
  FUN_004c69f0(&fStack_38,&fStack_38);
  fVar5 = fStack_20 * fStack_30 + fStack_28 * fStack_38 + fStack_24 * fStack_34;
  if (0.0 <= fVar5) {
    fVar10 = *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);
    uStack_68 = PAIR44(fStack_74,uStack_78);
    fStack_60 = fStack_70;
  }
  else {
    fVar10 = *(float *)(iVar3 + 0x90) * *(float *)(iVar3 + 0x2c);
    uStack_68 = PAIR44(fStack_84,fStack_88);
    fStack_60 = fStack_80;
  }
  fStack_18 = fStack_30 * fVar10 + fStack_88 + 0.0;
  fStack_14 = fStack_54;
  fStack_10 = (fStack_80 + 0.0) - fStack_38 * fVar10;
  fStack_48 = fStack_18 - fStack_58;
  fStack_44 = fStack_54 - fStack_54;
  fStack_40 = fStack_10 - fStack_50;
  FUN_004c69f0(&fStack_48,&fStack_48);
  fVar6 = fStack_60;
  fVar7 = fStack_40 * fStack_30 + fStack_48 * fStack_38 + fStack_44 * fStack_34;
  if (((ABS(fVar7) < ABS(fVar5)) && (fVar7 != 0.0)) && (fVar5 != 0.0)) {
    fStack_8 = fStack_58 - uStack_68.f._0_4_;
    fStack_4 = fStack_50 - fStack_60;
    fVar5 = (float)FUN_004c6af0(&fStack_8);
    fStack_14 = fStack_54 + (fVar8 * fVar5) / fVar9;
    fStack_18 = fStack_30 * fVar10 + uStack_68.f._0_4_ + 0.0;
    fStack_10 = (fVar6 + 0.0) - fStack_38 * fVar10;
    fVar5 = (float)FUN_002d1f30(&fStack_124,&fStack_c0);
    fStack_18 = (uStack_68.f._0_4_ + 0.0) - fStack_30 * fVar10;
    fStack_10 = fStack_38 * fVar10 + fVar6 + 0.0;
    fVar8 = (float)FUN_002d1f30(&fStack_124,&fStack_b0);
    if (fVar5 < fVar8) {
      fStack_108 = fStack_c0;
      fStack_104 = fStack_bc;
      fStack_100 = fStack_b8;
      fStack_fc = fStack_b4;
    }
    else {
      fStack_108 = fStack_b0;
      fStack_104 = fStack_ac;
      fStack_100 = fStack_a8;
      fStack_fc = fStack_a4;
    }
    FUN_004be1e0(&fStack_28,0x6978a0,1,&fStack_108);
  }
  fStack_28 = fStack_28 * fVar9;
  fStack_24 = fStack_24 * fVar9;
  fStack_20 = fStack_20 * fVar9;
  fVar5 = (float)FUN_0052e930(DAT_007cad60 * *(float *)(iVar4 + 0xb8) * 0.5);
  fVar5 = fVar9 * fVar5 * 0.21875;
  fStack_8 = fStack_28;
  fStack_4 = fStack_20;
  FUN_004c6b20(&fStack_8,&fStack_8);
  fStack_58 = fStack_4 * fVar5 + fStack_58 + 0.0;
  fStack_50 = (fStack_50 + 0.0) - fStack_8 * fVar5;
  fStack_114 = fStack_58 + fStack_28;
  fStack_110 = fStack_54 + fStack_24;
  fStack_10c = fStack_50 + fStack_20;
  return;
}

/* Recovered battle-misc harvest: 0x002A3A80-0x002A4C20 */
// FUN_002A3A80


u16 FUN_002a3a80(void)



{

  return *(u16 *)(iGpffffb6fc + 0xf0);

}

// FUN_002A3A90


void FUN_002a3a90(int param_1)



{

  if (*(int *)(iGpffffb6fc + 0x100) != 0) {

    if (*(int *)(*(int *)(iGpffffb6fc + 0x100) + 8) == *(int *)(param_1 + 8)) {

      *(u32 *)(iGpffffb6fc + 0x100) = 0;

    }

    switch (*(u16 *)(iGpffffb6fc + 0xf0)) {
      case 0xc:
        if ((*(int *)(iGpffffb6fc + 0x120) != 0) &&
            (*(int *)(*(int *)(iGpffffb6fc + 0x120) + 8) == *(int *)(param_1 + 8))) {
          *(u32 *)(iGpffffb6fc + 0x120) = 0;
        }
        break;
      default:
        break;
    }

  }

  return;

}

// FUN_002A42A0


void FUN_002a42a0(void)
{
  s32 node;
  s32 index;

  index = 0;
  for (; (index & 0xffff) < 2; index = (u16)(index + 1)) {
    node = *(s32 *)(DAT_007ce3ec + (u16)index * 8 + 0x150);
    while (node != 0) {
      FUN_0027f790(node, 7);
      node = *(s32 *)(node + 0xa34);
    }
  }
}

// FUN_002A4530 NONMATCHING


void FUN_002a4530(float *param_1,float *param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  

  fVar1 = param_3[1];

  fVar2 = param_3[2];

  param_1[0xc] = *param_3;

  param_1[0xd] = fVar1;

  param_1[0xe] = fVar2;

  fStack_10 = *param_2 - *param_3;

  fStack_c = param_2[1] - param_3[1];

  fStack_8 = param_2[2] - param_3[2];

  FUN_004c69f0(&fStack_10,&fStack_10);

  param_1[8] = fStack_10;

  param_1[9] = fStack_c;

  param_1[10] = fStack_8;

  fStack_20 = param_4[1] * fStack_8 - param_4[2] * fStack_c;

  fStack_1c = param_4[2] * fStack_10 - *param_4 * fStack_8;

  fStack_18 = *param_4 * fStack_c - param_4[1] * fStack_10;

  FUN_004c69f0(&fStack_20,&fStack_20);

  *param_1 = fStack_20;

  param_1[1] = fStack_1c;

  param_1[2] = fStack_18;

  param_1[4] = fStack_c * fStack_18 - fStack_8 * fStack_1c;

  param_1[5] = fStack_8 * fStack_20 - fStack_10 * fStack_18;

  param_1[6] = fStack_10 * fStack_1c - fStack_c * fStack_20;

  return;

}

// FUN_002A4A70 NONMATCHING


void FUN_002a4a70(void)



{

  int iVar1;

  u32 uVar2;

  u64 uVar3;

  u32 uVar4;

  

  uVar3 = FUN_00198590();

  FUN_004c9d70(0x420c0000,uVar3);

  uVar3 = FUN_00198590();

  FUN_001a4580(0x42200000,uVar3);

  iVar1 = (int)(uintptr_t)DAT_007ce3ec;

  *(u16 *)(DAT_007ce3ec + 0x20) = 1;

  *(u16 *)(iVar1 + 0x94) = 0;

  *(u16 *)(iVar1 + 0x96) = 0;

  *(u16 *)(iVar1 + 0x98) = 0;

  *(u32 *)(iVar1 + 0xa0) = 0;

  *(u32 *)(iVar1 + 0x9c) = 0;

  uVar3 = (*DAT_00960178)(0x30,0x40000);

  FUN_00521408(uVar3,0,0x30);

  uVar2 = FUN_0048dab0(4,1,uVar3);

  *(u32 *)(iVar1 + 0xb8) = uVar2;

  (*DAT_0096017c)(uVar3);

  FUN_00198590();

  *(u32 *)(DAT_007ce3ec + 0xd4) = DAT_007caf3c;

  *(u32 *)(DAT_007ce3ec + 200) = DAT_007caf40;

  *(u32 *)(DAT_007ce3ec + 0xcc) = DAT_007caf44;

  *(u32 *)(DAT_007ce3ec + 0xd0) = DAT_007caf48;

  *(u32 *)(DAT_007ce3ec + 0xbc) = DAT_007caf4c;

  *(u32 *)(DAT_007ce3ec + 0xc0) = DAT_007caf50;

  *(u32 *)(DAT_007ce3ec + 0xc4) = DAT_007caf54;

  *(u32 *)(DAT_007ce3ec + 0xd8) = DAT_007cae38;

  *(u16 *)(DAT_007ce3ec + 0xf0) = 0;

  *(u16 *)(DAT_007ce3ec + 0x10a) = 0;

  for (uVar4 = 0; uVar4 < 3; uVar4 = uVar4 + 1 & 0xffff) {

    *(u16 *)(DAT_007ce3ec + uVar4 * 2 + 0x104) = 0;

  }

  *(u32 *)(DAT_007ce3ec + 0xf4) = *(u32 *)(DAT_007ce3ec + 0xf4) | 2;

  FUN_002b6db0((u64)(uintptr_t)(DAT_007ce3ec + 0x10c));

  return;

}

// FUN_002A4C20


void FUN_002a4c20(void)



{

  if (*(int *)(DAT_007ce3ec + 0xb8) != 0) {

    FUN_0048da30(*(int *)(DAT_007ce3ec + 0xb8));

  }

  return;

}

/* Recovered battle-misc harvest: 0x002A32F0-0x002A4690 */
// FUN_002A32F0


u8 FUN_002a32f0(int param_1)
{
    int unit;

    unit = *(int*)(param_1 + 0xe0);
    if (unit == 0)
        return 0;
    if (FUN_002fdfe0(param_1) != 0)
        return 1;
    if (FUN_00300580(*(u32*)(*(int*)(unit + 0x30) + 0xa2c), 0x80) != 0)
        return 1;
    return FUN_002d5f50(unit) != 0;
}

// FUN_002A3380 NONMATCHING


u32 FUN_002a3380(u8* param_1)



{

  u16 uVar1;

  int iVar2;

  u32 uVar3;

  

  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0xe0) + 0x30) + 0xa00);

  if ((iVar2 == 0) ||

     (uVar1 = *(u16 *)(iVar2 + 0xa4),

     (*(u16 *)(iGpffffb73c + ((u32)uVar1 * 10 + (u32)uVar1) * 8) & 1) == 0)) {

    if ((*(u16 *)((u32)*(u16 *)(*(int *)(param_1 + 0xe0) + 0x6e) * 0x1c + iGpffffb710 + 2) &

        0x10) == 0) {

      uVar3 = 1;

    }

    else {

      uVar3 = 0;

    }

  }

  else {

    uVar3 = 0;

  }

  return uVar3;

}

// FUN_002A3420 NONMATCHING


u32 FUN_002a3420(int param_1)



{

  u16 uVar1;

  u16 uVar2;

  int iVar3;

  u8 bVar4;

  u32 uVar5;

  

  if ((*(u32 *)(iGpffffb6fc + 0xc) & 0x200000) == 0) {

    uVar1 = *(u16 *)(*(int *)(param_1 + 0xe0) + 0x6e);

    iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0xe0) + 0x30) + 0xa00);

    if ((iVar3 == 0) ||

       (uVar2 = *(u16 *)(iVar3 + 0xa4),

       (*(u16 *)(iGpffffb73c + ((u32)uVar2 * 10 + (u32)uVar2) * 8) & 1) == 0)) {

      if ((*(u16 *)((u32)uVar1 * 0x1c + iGpffffb710 + 2) & 0x10) == 0) {

        bVar4 = 1;

      }

      else {

        bVar4 = 0;

      }

    }

    else {

      bVar4 = 0;

    }

    if ((bVar4) && ((*(u16 *)((u32)uVar1 * 0x1c + iGpffffb710 + 2) & 0x20) != 0)) {

      uVar5 = 1;

    }

    else {

      uVar5 = 0;

    }

  }

  else {

    uVar5 = 1;

  }

  return uVar5;

}



// FUN_002A3520
u8 FUN_002a3520(int param_1)



{

  u8 bVar1;

  

  if (*(int *)(param_1 + 0xe0) == 0) {

    bVar1 = 0;

  }

  else {

    bVar1 = *(u16 *)(*(int *)(param_1 + 0xe0) + 0x6c) == 3;

  }

  return bVar1;

}

// FUN_002A3550


u64 FUN_002a3550(u8* param_1)



{

  u64 uVar1;

  

  if (*(int *)(param_1 + 0xe0) == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_00308a50(*(u16 *)(*(int *)(param_1 + 0xe0) + 0x72));

  }

  return uVar1;

}

// FUN_002A3590 NONMATCHING


u32 FUN_002a3590(float *param_1,long param_2)



{

  u32 uVar1;

  float *pfVar2;

  float fVar3;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  

  uVar1 = 0;

  fVar3 = *param_1;

  pfVar2 = (float *)param_2;

  if (1500.0 < ABS(fVar3)) {

    if (param_2 != 0) {

      FUN_004be1e0(&fStack_10,0x697890,1,param_1 + 3);

      if (fStack_10 != 0.0) {

        fVar3 = (ABS(fVar3) - 1500.0) / ABS(fStack_10);

        fStack_10 = fStack_10 * fVar3;

        fStack_c = fStack_c * fVar3;

        fStack_8 = fStack_8 * fVar3;

        *pfVar2 = *param_1 + fStack_10;

        pfVar2[1] = param_1[1] + fStack_c;

        pfVar2[2] = param_1[2] + fStack_8;

      }

    }

    uVar1 = 1;

  }

  fVar3 = param_1[2];

  if (1500.0 < ABS(fVar3)) {

    if (param_2 != 0) {

      FUN_004be1e0(&fStack_10,0x697890,1,param_1 + 3);

      if (fStack_8 != 0.0) {

        fVar3 = (ABS(fVar3) - 1500.0) / ABS(fStack_8);

        *pfVar2 = *param_1 + fStack_10 * fVar3;

        pfVar2[1] = param_1[1] + fStack_c * fVar3;

        pfVar2[2] = param_1[2] + fStack_8 * fVar3;

      }

    }

    uVar1 = 1;

  }

  return uVar1;

}

// FUN_002A3750


s32 FUN_002a3750(BtlCamera* camera,u32 unit)
{
  BtlUnit *unitPtr;
  s32 result;
  s16 frameCount;
  s16 animFrame;
  
  unitPtr = (BtlUnit *)(uintptr_t)unit;
  if (unitPtr == 0) {
    result = 0;
  }
  else if (((u8 *)unitPtr)[0x33] == '\0') {
    result = 0;
  }
  else if ((*(u32 *)((u8 *)unitPtr + 0x98) & 2) == 0) {
    result = 0;
  }
  else {
    frameCount = func_002835e0(
      unitPtr, (u16)(s32)btlUnit00282c30(unitPtr), 1.0f);
    animFrame = btlUnitGetAnimFrame(unitPtr);
    result = animFrame < frameCount;
    result = result ^ 1;
  }
  return result;
}

// FUN_002A3820


u8 FUN_002a3820(int param_1)



{
  u32 offset;

  offset = (u32)*(u16 *)(*(int *)(param_1 + 0xe0) + 0x6e) * 0x1c;
  offset += iGpffffb710;

  return (*(u16 *)(offset + 2) &

         0x4000) != 0;

}

// FUN_002A3850


u32 FUN_002a3850(int param_1)
{
  s32 index;
  s32 owner;
  s32 object;
  s32 work;

  work = *(s32 *)(param_1 + 0xe0);
  index = 0;
  for (; (index & 0xffff) < *(u16 *)(work + 0x6a);
       index = (u16)(index + 1)) {
    owner = *(s32 *)(work + (u16)index * 4 + 0x38);
    if (owner != 0) {
      object = *(s32 *)(owner + 0x30);
      if (object != 0 &&
          FUN_0030b5a0(*(u32 *)(object + 0xa2c), 0) != 0) {
        return 1;
      }
    }
  }
  return 0;
}

// FUN_002A3E80 NONMATCHING


void FUN_002a3e80(float param_1,u8* param_2,u8* param_3,u8* param_4,u32 param_5)



{

  int iVar1;

  u32 uVar2;

  u32 uVar3;

  int iVar4;

  float fVar5;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  u32 uStack_20;

  u32 uStack_1c;

  float fStack_18;

  float fStack_14;

  u32 auStack_10 [2];

  u32 uStack_8;

  

  if ((*(u32 *)(iGpffffb6fc + 0x10) & 4) == 0) {

    if ((param_3 == 0) || (param_4 == 0)) {

      param_1 = 0.0;

    }

    else {

      fStack_30 = *(float *)param_3;

      fStack_2c = ((float *)param_3)[2];

      fStack_28 = *(float *)param_4;

      fStack_24 = ((float *)param_4)[2];

    }

    uVar3 = param_5 & 0x10;

    for (iVar4 = *(int *)(iGpffffb6fc + 0x14c); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x4a8)) {

      if (((*(u16 *)(iVar4 + 0x1a) & 1) != 0) &&

         (iVar1 = *(int *)(iVar4 + 0x30), (*(u32 *)(iVar1 + 0x9c) & 8) != 0)) {

        if ((param_5 & 0x40) == 0) {

          if ((iVar4 == *(int *)(iGpffffb6fc + 0x148)) && ((param_5 & 4) != 0)) {

            FUN_0027f790(iVar1,2);

            FUN_0027f770(iVar1,4);

            if (uVar3 == 0) {

              *(u8 *)(iVar1 + 0x37) = 0xff;

            }

          }

          else if (param_2 == 0) {

LAB_002a4124:

            if ((param_3 == 0) || (param_4 == 0)) {

              fVar5 = 0.0;

            }

            else {

              FUN_0027ffb0(iVar1,auStack_10);

              uStack_20 = auStack_10[0];

              uStack_1c = uStack_8;

              fVar5 = (float)FUN_002d1fd0(&fStack_30,&fStack_28,&uStack_20,&fStack_18);

              fVar5 = (fVar5 + 0.0) - *(float *)(iVar1 + 0x90) * *(float *)(iVar1 + 0x2c);

              if ((((fStack_30 < fStack_18) || (fStack_18 < fStack_28)) &&

                  ((fStack_18 < fStack_30 || (fStack_28 < fStack_18)))) ||

                 (((fStack_2c < fStack_14 || (fStack_14 < fStack_24)) &&

                  ((fStack_14 < fStack_2c || (fStack_24 < fStack_14)))))) goto LAB_002a4258;

            }

            if (fVar5 <= param_1) {

              FUN_0027f770(iVar1,2);

              if ((param_5 & 0x20) == 0) {

                *(u8 *)(iVar1 + 0x37) = 0;

              }

              if ((param_5 & 0x80) != 0) {

                FUN_0027f790(iVar1,4);

              }

            }

          }

          else if ((iVar4 == (int)(uintptr_t)param_2) && ((param_5 & 1) != 0)) {

            FUN_0027f790(iVar1,2);

            FUN_0027f770(iVar1,4);

            if (uVar3 == 0) {

              *(u8 *)(iVar1 + 0x37) = 0xff;

            }

          }

          else {

            if ((param_5 & 2) != 0) {

              for (uVar2 = 0; uVar2 < *(u16 *)(param_2 + 0x6a); uVar2 = uVar2 + 1 & 0xffff) {

                if (iVar4 == *(int *)(param_2 + uVar2 * 4 + 0x38)) {

                  FUN_0027f790(iVar1,2);

                  FUN_0027f770(iVar1,4);

                  if (uVar3 == 0) {

                    *(u8 *)(iVar1 + 0x37) = 0xff;

                  }

                  break;

                }

              }

              if (uVar2 != *(u16 *)(param_2 + 0x6a)) goto LAB_002a4258;

            }

            if ((*(char *)(iVar1 + 0xa2) != *(char *)(*(int *)(param_2 + 0x30) + 0xa2)) ||

               ((param_5 & 8) == 0)) goto LAB_002a4124;

            FUN_0027f790(iVar1,2);

            if (uVar3 == 0) {

              *(u8 *)(iVar1 + 0x37) = 0xff;

            }

          }

        }

        else {

          FUN_0027f790(iVar1,2);

          if (uVar3 == 0) {

            *(u8 *)(iVar1 + 0x37) = 0xff;

          }

        }

      }

LAB_002a4258:

    ;
    }

  }

  return;

}

// FUN_002A4470


void FUN_002a4470(f32* dst, f32* src)
{
  *(RwV3d*)dst = *(RwV3d*)src;
  *(RtQuat*)(dst + 3) = *(RtQuat*)(src + 3);
}

// FUN_002A44B0


void FUN_002a44b0(f32* dst, f32* src)
{
  *(RwV3d*)dst = *(RwV3d*)src;
  *(RtQuat*)(dst + 3) = *(RtQuat*)(src + 3);
}

// FUN_002A44F0


void FUN_002a44f0(f32* dst, f32* src)
{
  *(RwV3d*)dst = *(RwV3d*)src;
  *(RtQuat*)(dst + 3) = *(RtQuat*)(src + 3);
}

// FUN_002A4690


void FUN_002a4690(void* out, const void* first, const void* second, const void* config)
{
  u8 auStack_40[64];

  FUN_002a4530((float*)auStack_40, (float*)second, (float*)first,
               (float*)config);
  FUN_004bdcb0(out, auStack_40);
}
