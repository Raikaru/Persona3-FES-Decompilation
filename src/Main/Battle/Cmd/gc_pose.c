#include "Utils.h"
#include "Main/Battle/Cmd/gc_pose.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwln.h"
#include "Kosaka/k_assert.h"
#include "rw/rprandom.h"
#include "rw/rwplcore.h"
#include "rw/rtquat.h"
void bpTut00251010();
void bpTut00251030();
void bpTut00251050();




#pragma alias gcPose0024f960_y2 gcPose0024f960
#pragma alias gcPose0024faa0_y2 gcPose0024faa0
#pragma alias FUN_004bdde0_y2 FUN_004bdde0
#pragma alias FUN_004c69f0_y2 FUN_004c69f0
#pragma alias gcPose0024f090_y2 gcPose0024f090_y2
#pragma alias gcPose002503f0_y2 gcPose002503f0_y2
#pragma alias gcPose0024fd20_y2 gcPose0024fd20_y2
#pragma alias gcPose0024fd40_y2 gcPose0024fd40_y2
#pragma alias gcPose0024fba0_y2 gcPose0024fba0_y2


#pragma alias gcPoseStartDirectedTranslation FUN_002505B0
#pragma alias gcPoseStartEaseOutTranslation FUN_002508C0
#pragma alias gcPoseStartEaseInTranslation FUN_00250A30
#pragma alias gcPoseSetRotationVectorElement FUN_00250BE0
#pragma alias gcPoseStartRotation FUN_00250CF0
#pragma alias gcPoseProjectToScreen FUN_00250F80
#pragma alias RwV3dNormalize FUN_004c69f0
#pragma alias RwV3dLength FUN_004c6ac0

/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void gcPoseStartDirectedTranslation(GcPoseController *work, const RwV3d *target, s32 frames, const RwV3d *direction);
void gcPoseStartEaseOutTranslation(int param_1,u32 *param_2,int param_3);
void gcPoseStartEaseInTranslation(int param_1,u32 *param_2,int param_3);
void gcPoseSetRotationVectorElement(int param_1,int param_2,u32 param_3);
void gcPoseStartRotation(u32 *work, void *target, f32 startAngle, f32 endAngle, s32 frames);
void gcPoseProjectToScreen(float* output, const RwV3d* input);

extern f32 fGpffff81f8;
extern void FUN_004bdde0_y2(f32 angle, void *output, void *target, s32 mode);
extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
extern f32 RwV3dLength(const RwV3d *in);

// FUN_00250480
void gcPose00250480(GcPoseController *pose)
{
    K_ASSERT(pose->type.s32Value == 0, 0x466);
    K_ASSERT(pose->state.position.mode.s32Value == 3, 0x467);
    pose->state.position.data.translation.flags.u32Value &= 0xfffffffe;
}

// FUN_00250b90
u32 gcPose00250b90(GcPoseController *pose)
{
    K_ASSERT(pose->state.position.mode.s32Value == 3, 0x512);
    return pose->state.position.data.translation.flags.u32Value & 1;
}

// FUN_00250c70
void gcPose00250c70(GcPoseController *pose)
{
    K_ASSERT(pose->type.s32Value == 2, 0x539);
    K_ASSERT(pose->state.rotation.mode.s32Value == 3, 0x53a);
    pose->state.rotation.data.motion.flags.u32Value &= 0xfffffffe;
}

// FUN_00250e70
u32 gcPose00250e70(GcPoseController *pose)
{
    K_ASSERT(pose->type.s32Value == 2, 0x57d);
    K_ASSERT(pose->state.rotation.mode.s32Value == 3, 0x57e);
    return pose->state.rotation.data.motion.flags.u32Value & 1;
}

// FUN_00250ef0
void gcPose00250ef0(GcPoseController *pose, float param_2)
{
    K_ASSERT(pose->type.s32Value == 2, 0x588);
    K_ASSERT(pose->state.rotation.mode.s32Value == 4, 0x589);
    pose->state.rotation.data.random.scale = param_2;
    pose->flags |= 2;
}

// FUN_0024f960
void gcPose0024f960_y2(GcPoseController *pose, RwV3d *param_2)
{
    K_ASSERT(pose->type.s32Value == 0, 0x375);
    K_ASSERT(pose->state.position.mode.s32Value < 4, 0x376);
    *param_2 = pose->state.position.value;
}

// FUN_00250500
void gcPose00250500(GcPoseController *pose, RwV3d *param_2, int param_3)
{
    K_ASSERT(pose->state.position.mode.s32Value == 3, 0x471);
    pose->state.position.data.translation.active.u32Value = 0;
    pose->state.position.data.translation.acceleration = *param_2;
    pose->state.position.data.translation.direction = pose->state.position.value;
    pose->field_0x10 = 0;
    pose->state.position.data.translation.duration.s32Value = param_3 << 0x10;
    pose->state.position.data.translation.flags.u32Value |= 1;
}

// FUN_0024faa0
RwV3d* gcPose0024faa0_y2(GcPoseController *pose)
{
    K_ASSERT(pose->state.position.mode.s32Value < 2, 0x38e);
    return &pose->state.position.value;
}

// FUN_0024fba0
void gcPose0024fba0(GcPoseController *pose, RtQuat *param_2)
{
    K_ASSERT(pose->type.s32Value == 2, 0x3a6);
    K_ASSERT(pose->state.rotation.mode.s32Value < 5, 0x3a7);
    *param_2 = pose->state.rotation.value;
}



static void gcPose0024f350(GcPoseController* pose);
static void gcPose0024f410(GcPoseController* pose);
static void gcPose0024f780(GcPoseController* pose);
static void gcPose0024f7f0(GcPoseController* pose, const RwV3d* offset);
static void gcPose0024fe40(GcPoseController* pose);
static void gcPose0024ff10(GcPoseController* pose);
static void gcPose00250280(GcPoseController* pose, const RwV3d* offset);

static inline f32 gcPoseRandomExtent(f32 extent)
{
    return extent / 2.0f -
        extent * (f32)(RpRandom() & 0xfff) / 4096.0f;
}


// FUN_0024F090
void gcPose0024f090(GcPoseController* pose)
{
    u32 mode;

    pose->flags |= 1;
    switch (pose->type.u32Value) {
        case 0:
            mode = pose->state.position.mode.u32Value;
            switch (mode) {
                case 1:
                    gcPose0024f350(pose);
                    break;
                case 0:
                case 2:
                    break;
                case 3:
                    gcPose0024f780(pose);
                    break;
                default:
                    K_ASSERT(0, 0x2d4);
                    break;
            }
            break;
        case 1:
            mode = pose->state.position.mode.u32Value;
            switch (mode) {
                case 0:
                case 1:
                    break;
                default:
                    K_ASSERT(0, 0x2e4);
                    break;
            }
            break;
        case 2:
            mode = pose->state.rotation.mode.u32Value;
            switch (mode) {
                case 0:
                case 1:
                case 2:
                    break;
                case 3:
                    pose->state.rotation.data.motion.flags.u32Value = 0;
                    break;
                case 4:
                    gcPose0024fe40(pose);
                    break;
                default:
                    K_ASSERT(0, 0x2fb);
                    break;
            }
            break;
        default:
            K_ASSERT(0, 0x302);
            break;
    }
}

// FUN_0024F210
void gcPose0024f210(GcPoseController* pose, f32 first, u32 value, f32 fourth)
{
    K_ASSERT(pose->type.u32Value == 0, 0x30b);
    K_ASSERT(pose->state.position.mode.u32Value == 1, 0x30c);
    pose->state.position.data.random.randomExtent = first;
    pose->state.position.data.random.parameter58.u32Value = value;
    pose->state.position.data.random.offsetScale = fourth;
    pose->flags |= 2;
}

// FUN_0024F2C0
void gcPose0024f2c0(GcPoseController* pose, f32 value)
{
    K_ASSERT(pose->type.u32Value == 0, 0x31b);
    K_ASSERT(pose->state.position.mode.u32Value == 1, 0x31c);
    pose->state.position.data.random.scale = value;
    pose->flags |= 2;
}

// FUN_0024F350
static void gcPose0024f350(GcPoseController* pose)
{
    RwV3d offset;
    GcPosePositionRandomData *poseData;

    K_ASSERT(pose->type.u32Value == 0, 0x329);
    K_ASSERT(pose->state.position.mode.u32Value == 1, 0x32a);

    poseData = &pose->state.position.data.random;
    poseData->randomExtent = 10.0f;
    poseData->parameter58.u32Value = 0xb4;
    poseData->offsetScale = 10.0f;
    poseData->scale = 1.0f;
    gcPose0024f410(pose);

    offset.x = 0.0f;
    offset.y = 0.0f;
    offset.z = poseData->offsetScale;
    gcPose0024f7f0(pose, &offset);
}

// FUN_0024F410
static void gcPose0024f410(GcPoseController* pose)
{
    RwV3d value;
    GcPosePositionRandomData* poseData;

    K_ASSERT(pose->type.u32Value == 0, 0x341);
    K_ASSERT(pose->state.position.mode.u32Value == 1, 0x342);
    poseData = &pose->state.position.data.random;

    value.x = gcPoseRandomExtent(poseData->randomExtent);
    value.y = gcPoseRandomExtent(poseData->randomExtent);
    value.z = gcPoseRandomExtent(poseData->randomExtent);
    poseData->sample = value;

    value.x = gcPoseRandomExtent(poseData->randomExtent);
    value.y = gcPoseRandomExtent(poseData->randomExtent);
    value.z = gcPoseRandomExtent(poseData->randomExtent);
    poseData->anchor = value;
}

// FUN_0024F780
static void gcPose0024f780(GcPoseController* pose)
{
    K_ASSERT(pose->type.u32Value == 0, 0x355);
    K_ASSERT(pose->state.position.mode.u32Value == 3, 0x356);
    pose->state.position.data.translation.flags.f32Value = 0.0f;
}

// FUN_0024F7F0
static void gcPose0024f7f0(GcPoseController* state, const RwV3d* offset)
{
    GcPosePositionRandomData *pose;
    RwV3d fromOrigin;
    RwV3d toOrigin;
    RwV3d anchor = { 0.0f, 0.0f, 0.0f };
    f32 crossX;
    f32 crossY;
    f32 crossZ;
    f32 tangentX;
    f32 tangentY;
    f32 tangentZ;
    f32 scale;

    pose = &state->state.position.data.random;
    pose->shiftedSample.x = pose->sample.x + offset->x;
    pose->shiftedSample.y = pose->sample.y + offset->y;
    pose->shiftedSample.z = pose->sample.z + offset->z;

    fromOrigin.x = anchor.x - pose->anchor.x;
    fromOrigin.y = anchor.y - pose->anchor.y;
    fromOrigin.z = anchor.z - pose->anchor.z;
    toOrigin.x = pose->anchor.x - pose->sample.x;
    toOrigin.y = pose->anchor.y - pose->sample.y;
    toOrigin.z = pose->anchor.z - pose->sample.z;
    RwV3dNormalize(&fromOrigin, &fromOrigin);
    RwV3dNormalize(&toOrigin, &toOrigin);
    crossX = toOrigin.y * fromOrigin.z - toOrigin.z * fromOrigin.y;
    crossY = toOrigin.z * fromOrigin.x - toOrigin.x * fromOrigin.z;
    crossZ = toOrigin.x * fromOrigin.y - toOrigin.y * fromOrigin.x;
    tangentX = crossY * fromOrigin.z - crossZ * fromOrigin.y;
    tangentY = crossZ * fromOrigin.x - crossX * fromOrigin.z;
    tangentZ = crossX * fromOrigin.y - crossY * fromOrigin.x;

    scale = pose->offsetScale;
    tangentX *= scale;
    tangentY *= scale;
    tangentZ *= scale;
    pose->controlPoint.x = pose->anchor.x + tangentX;
    pose->controlPoint.y = pose->anchor.y + tangentY;
    pose->controlPoint.z = pose->anchor.z + tangentZ;
}

// FUN_0024F9F0
void gcPose0024f9f0(GcPoseController* pose, RwV3d* param_2)
{
    K_ASSERT(pose->state.position.mode.s32Value < 4, 0x37d);
    switch (pose->state.position.mode.s32Value) {
        case 0:
        case 3:
            pose->state.position.value = *param_2;
            break;
        default:
            K_ASSERT(0, 0x386);
            break;
    }
}

// FUN_0024FAF0
void gcPose0024faf0(GcPoseController* pose, RwV3d* param_2)
{
    K_ASSERT(pose->state.position.mode.s32Value < 2, 0x395);
    switch (pose->state.position.mode.s32Value) {
        case 0:
        case 1:
            pose->state.position.value = *param_2;
            break;
        default:
            K_ASSERT(0, 0x39e);
            break;
    }
}

// FUN_0024FC40
void gcPose0024fc40(GcPoseController* pose, RtQuat* param_2)
{
    K_ASSERT(pose->type.s32Value == 2, 0x3ae);
    switch (pose->state.rotation.mode.s32Value) {
        case 0:
        case 1:
        case 2:
        case 3:
            pose->state.rotation.value = *param_2;
            break;
        default:
            K_ASSERT(0, 0x3b9);
            break;
    }
}

// FUN_0024FD10
void gcPose0024fd10(GcPoseController* pose)
{
    pose->type.u32Value = 0;
    pose->state.position.mode.u32Value = 0;
}

// FUN_0024FD20
void gcPose0024fd20(GcPoseController* pose)
{
    pose->type.u32Value = 0;
    pose->state.position.mode.u32Value = 1;
}

// FUN_0024FD40
void gcPose0024fd40(GcPoseController* pose)
{
    GcPoseScalar* values;
    s32 index;

    pose->type.u32Value = 0;
    pose->state.position.mode.u32Value = 2;
    values = pose->state.position.data.vector.values;
    for (index = 0; index < 3; index++) {
        values[index].s32Value = 0;
    }
}

// FUN_0024FD80
void gcPose0024fd80(GcPoseController* pose)
{
    pose->type.u32Value = 0;
    pose->state.position.mode.u32Value = 3;
}

// FUN_0024FDA0
void gcPose0024fda0(GcPoseController* pose)
{
    pose->type.u32Value = 1;
    pose->state.position.mode.u32Value = 0;
}

// FUN_0024FDC0
void gcPose0024fdc0(GcPoseController* pose)
{
    GcPoseScalar* values;
    s32 index;

    pose->type.u32Value = 2;
    pose->state.rotation.mode.u32Value = 2;
    values = pose->state.rotation.data.vector.values;
    for (index = 0; index < 3; index++) {
        values[index].s32Value = 0;
    }
}

// FUN_0024FE00
void gcPose0024fe00(GcPoseController* pose)
{
    pose->type.u32Value = 2;
    pose->state.rotation.mode.u32Value = 3;
}

// FUN_0024FE20
void gcPose0024fe20(GcPoseController* pose)
{
    pose->type.u32Value = 2;
    pose->state.rotation.mode.u32Value = 4;
}

// FUN_0024FE40
static void gcPose0024fe40(GcPoseController* pose)
{
    RwV3d offset;
    GcPoseRotationRandomData* poseData;

    K_ASSERT(pose->type.u32Value == 2, 0x41b);
    K_ASSERT(pose->state.rotation.mode.u32Value == 4, 0x41c);
    poseData = &pose->state.rotation.data.random;
    poseData->randomExtentX = 5.0f;
    poseData->randomExtentY = 15.0f;
    poseData->randomExtentZ = 15.0f;
    poseData->angle = 0xB4;
    poseData->offsetScale = 1.0f;
    poseData->scale = 1.0f;
    gcPose0024ff10(pose);
    offset.x = 0.0f;
    offset.y = 0.0f;
    offset.z = poseData->offsetScale;
    gcPose00250280(pose, &offset);
}

// FUN_0024FF10
static void gcPose0024ff10(GcPoseController* pose)
{
    RwV3d value;
    GcPoseRotationRandomData* poseData;

    K_ASSERT(pose->type.u32Value == 2, 0x434);
    K_ASSERT(pose->state.rotation.mode.u32Value == 4, 0x435);
    poseData = &pose->state.rotation.data.random;

    value.x = gcPoseRandomExtent(poseData->randomExtentX);
    value.y = gcPoseRandomExtent(poseData->randomExtentY);
    value.z = gcPoseRandomExtent(poseData->randomExtentZ);
    poseData->sample = value;

    value.x = gcPoseRandomExtent(poseData->randomExtentX);
    value.y = gcPoseRandomExtent(poseData->randomExtentY);
    value.z = gcPoseRandomExtent(poseData->randomExtentZ);
    poseData->anchor = value;
}

// FUN_00250280
static void gcPose00250280(GcPoseController* state, const RwV3d* offset)
{
    GcPoseRotationRandomData *pose;
    RwV3d fromOrigin;
    RwV3d toOrigin;
    RwV3d anchor = { 0.0f, 0.0f, 0.0f };
    f32 crossX;
    f32 crossY;
    f32 crossZ;
    f32 tangentX;
    f32 tangentY;
    f32 tangentZ;
    f32 scale;

    pose = &state->state.rotation.data.random;
    pose->shiftedSample.x = pose->sample.x + offset->x;
    pose->shiftedSample.y = pose->sample.y + offset->y;
    pose->shiftedSample.z = pose->sample.z + offset->z;

    fromOrigin.x = anchor.x - pose->anchor.x;
    fromOrigin.y = anchor.y - pose->anchor.y;
    fromOrigin.z = anchor.z - pose->anchor.z;
    toOrigin.x = pose->anchor.x - pose->sample.x;
    toOrigin.y = pose->anchor.y - pose->sample.y;
    toOrigin.z = pose->anchor.z - pose->sample.z;
    RwV3dNormalize(&fromOrigin, &fromOrigin);
    RwV3dNormalize(&toOrigin, &toOrigin);
    crossX = toOrigin.y * fromOrigin.z - toOrigin.z * fromOrigin.y;
    crossY = toOrigin.z * fromOrigin.x - toOrigin.x * fromOrigin.z;
    crossZ = toOrigin.x * fromOrigin.y - toOrigin.y * fromOrigin.x;
    tangentX = crossY * fromOrigin.z - crossZ * fromOrigin.y;
    tangentY = crossZ * fromOrigin.x - crossX * fromOrigin.z;
    tangentZ = crossX * fromOrigin.y - crossY * fromOrigin.x;

    scale = pose->offsetScale;
    tangentX *= scale;
    tangentY *= scale;
    tangentZ *= scale;
    pose->controlPoint.x = pose->anchor.x + tangentX;
    pose->controlPoint.y = pose->anchor.y + tangentY;
    pose->controlPoint.z = pose->anchor.z + tangentZ;
}

// FUN_002503F0
void gcPose002503f0(GcPoseController* pose, s32 index, u32 value)
{
    K_ASSERT(pose->state.position.mode.u32Value == 2, 0x45c);
    K_ASSERT(index < 3, 0x45d);
    pose->state.position.data.vector.values[index].u32Value = value;
}

/* Recovered battle-misc harvest: 0x002505B0-0x00250F80 */
// FUN_002505B0


void gcPoseStartDirectedTranslation(GcPoseController *work, const RwV3d *target, s32 frames, const RwV3d *direction)
{
    GcPoseTranslationData *state;
    RwV3d *acceleration;
    s32 fixedFrames;
    f32 duration;
    RwV3d delta;
    RwV3d normalizedDelta;
    RwV3d normalizedDirection;
    f32 dot;
    f32 directionLength;
    f32 projectedX;
    f32 projectedY;
    RwV3d accelerationValue;
    f32 correctionX;
    f32 correctionY;
    f32 correctionZ;
    f32 factor;

    K_ASSERT(work->type.s32Value == 0, 0x4a9);
    K_ASSERT(work->state.position.mode.s32Value == 3, 0x4aa);

    fixedFrames = frames << 16;
    duration = (f32)fixedFrames / 1966080.0f;
    state = &work->state.position.data.translation;
    state->active.u32Value = 1;
    acceleration = &state->acceleration;
    state->direction = *direction;
    state->target = *target;
    state->start = work->state.position.value;

    delta.x = state->target.x - state->start.x;
    delta.y = state->target.y - state->start.y;
    delta.z = state->target.z - state->start.z;
    RwV3dNormalize(&normalizedDelta, &delta);
    RwV3dNormalize(&normalizedDirection, acceleration + 1);

    dot = normalizedDelta.x * normalizedDirection.x +
          normalizedDelta.y * normalizedDirection.y +
          normalizedDelta.z * normalizedDirection.z;
    directionLength = RwV3dLength(acceleration + 1);
    projectedX = normalizedDelta.x * (dot * directionLength);
    directionLength = RwV3dLength(acceleration + 1);
    projectedY = normalizedDelta.y * (dot * directionLength);
    directionLength = RwV3dLength(acceleration + 1);
    {
        f32 projectedZ;

        projectedZ = normalizedDelta.z * (dot * directionLength);

        accelerationValue.x = projectedX * duration;
        accelerationValue.y = projectedY * duration;
        accelerationValue.z = projectedZ * duration;
        accelerationValue.x -= delta.x;
        accelerationValue.y -= delta.y;
        accelerationValue.z -= delta.z;
        accelerationValue.x *= 2.0f;
        accelerationValue.y *= 2.0f;
        accelerationValue.z *= 2.0f;
        factor = -1.0f / (duration * duration);
        accelerationValue.x *= factor;
        accelerationValue.y *= factor;
        accelerationValue.z *= factor;

        correctionX = (acceleration + 1)->x - projectedX;
        correctionY = (acceleration + 1)->y - projectedY;
        correctionZ = (acceleration + 1)->z - projectedZ;
        correctionX *= duration;
        correctionY *= duration;
        correctionZ *= duration;
        correctionX *= 2.0f;
        correctionY *= 2.0f;
        correctionZ *= 2.0f;
        correctionX *= factor;
        correctionY *= factor;
        correctionZ *= factor;
        *acceleration = accelerationValue;
        acceleration->x += correctionX;
        acceleration->y += correctionY;
        acceleration->z += correctionZ;
    }

    work->field_0x10 = 0;
    state->duration.u32Value = (u32)fixedFrames;
    state->flags.u32Value |= 1;
}

// FUN_002508C0


void gcPoseStartEaseOutTranslation(int param_1, u32 *param_2, int param_3)
{
    GcPoseController *work;
    f32 *target;
    f32 duration;
    f32 factor;
    f32 delta;
    f32 x;
    f32 y;
    f32 z;

    work = (GcPoseController *)param_1;
    target = (f32 *)param_2;
    K_ASSERT(work->type.s32Value == 0, 0x4d6);
    K_ASSERT(work->state.position.mode.s32Value == 3, 0x4d7);

    duration = (f32)(param_3 << 16) / 1966080.0f;
    work->state.position.data.translation.active.u32Value = 1;
    work->state.position.data.translation.target = *(RwV3d *)target;
    work->state.position.data.translation.start = work->state.position.value;

    factor = 2.0f / (duration * duration);
    delta = work->state.position.data.translation.target.x -
            work->state.position.data.translation.start.x;
    x = delta * factor;
    delta = work->state.position.data.translation.target.y -
            work->state.position.data.translation.start.y;
    y = delta * factor;
    delta = work->state.position.data.translation.target.z -
            work->state.position.data.translation.start.z;
    z = delta * factor;

    work->state.position.data.translation.acceleration.x = -1.0f * x;
    work->state.position.data.translation.acceleration.y = -1.0f * y;
    work->state.position.data.translation.acceleration.z = -1.0f * z;
    work->state.position.data.translation.direction.x = x * duration;
    work->state.position.data.translation.direction.y = y * duration;
    work->state.position.data.translation.direction.z = z * duration;

    work->field_0x10 = 0;
    work->state.position.data.translation.duration.s32Value = param_3 << 16;
    work->state.position.data.translation.flags.u32Value |= 1;
}

// FUN_00250A30


void gcPoseStartEaseInTranslation(int param_1, u32 *param_2, int param_3)
{
    GcPoseController *work;
    f32 *target;
    f32 duration;
    f32 factor;
    f32 delta;
    RwV3d acceleration;

    work = (GcPoseController *)param_1;
    target = (f32 *)param_2;
    K_ASSERT(work->type.s32Value == 0, 0x4f5);
    K_ASSERT(work->state.position.mode.s32Value == 3, 0x4f6);

    duration = (f32)(param_3 << 16) / 1966080.0f;
    work->state.position.data.translation.active.u32Value = 1;
    work->state.position.data.translation.target = *(RwV3d *)target;
    work->state.position.data.translation.start = work->state.position.value;

    factor = 2.0f / (duration * duration);
    delta = work->state.position.data.translation.target.x -
            work->state.position.data.translation.start.x;
    acceleration.x = delta * factor;
    delta = work->state.position.data.translation.target.y -
            work->state.position.data.translation.start.y;
    acceleration.y = delta * factor;
    delta = work->state.position.data.translation.target.z -
            work->state.position.data.translation.start.z;
    acceleration.z = delta * factor;
    work->state.position.data.translation.acceleration = acceleration;

    work->state.position.data.translation.direction.x = 0;
    work->state.position.data.translation.direction.y = 0;
    work->state.position.data.translation.direction.z = 0;
    work->field_0x10 = 0;
    work->state.position.data.translation.duration.s32Value = param_3 << 16;
    work->state.position.data.translation.flags.u32Value |= 1;
}

// FUN_00250BE0


void gcPoseSetRotationVectorElement(int param_1, int param_2, u32 param_3)
{
    GcPoseController *pose;

    pose = (GcPoseController *)param_1;
    K_ASSERT(pose->type.s32Value == 2, 0x52f);
    K_ASSERT(pose->state.rotation.mode.s32Value == 2, 0x530);
    pose->state.rotation.data.vector.values[param_2].u32Value = param_3;
}

// FUN_00250CF0


void gcPoseStartRotation(u32 *work, void *target, f32 startAngle, f32 endAngle, s32 frames)
{
    GcPoseRotationMotionData *state;
    GcPoseRotationKinematics *motion;
    f32 duration;
    f32 acceleration;

    K_ASSERT(((GcPoseController *)work)->type.s32Value == 2, 0x55d);
    K_ASSERT(((GcPoseController *)work)->state.rotation.mode.s32Value == 3, 0x55e);

    state = &((GcPoseController *)work)->state.rotation.data.motion;
    motion = &state->motion;
    state->active.u32Value = 1;
    motion->target = *(RwV3d *)target;
    motion->startAngle = startAngle;
    motion->endAngle = endAngle;
    FUN_004bdde0_y2((motion->startAngle / fGpffff81f8) * 360.0f,
                 &((GcPoseController *)work)->state.rotation.value, target, 0);

    duration = (f32)(frames << 16) / 1966080.0f;
    acceleration = ((motion->endAngle - motion->startAngle) * 2.0f) /
                   (duration * duration);
    motion->acceleration = -acceleration;
    motion->velocity = acceleration * duration;
    ((GcPoseController *)work)->field_0x10 = 0;
    state->duration.u32Value = (u32)(frames << 16);
    state->flags.u32Value |= 1;
}

// FUN_00250F80


void gcPoseProjectToScreen(float* output, const RwV3d* input)
{
    RwV3d projected;

    RwV3dTransformPoint(&projected, input, &kwlnGetMainCamera()->viewMatrix);
    output[0] = (projected.x / projected.z) * SCREEN_WIDTH;
    output[1] = (projected.y / projected.z) * SCREEN_HEIGHT;
}



static u32* sSflCamera; // DAT_007ce33c
extern u32 DAT_00960070[];
u32 FUN_0024d430();
void FUN_0024d5e0();
void FUN_0024d7d0();
u32 FUN_0024d3b0();









static u32* sSflCameraNodes; // DAT_007ce350

extern void gcPose0024f090_y2(void* pose);
extern void gcPose002503f0_y2(void* pose, s32 index, u32 value);
extern void gcPose0024fd20_y2(void* pose);
extern void gcPose0024fd40_y2(void* pose);
extern void* func_004c38c0(void);
extern void func_004c3880(void* matrix);
extern void func_004cb750(void* matrix, const void* source, s32 mode);
extern u32 RpRandom(void);
extern void gcPose0024f960(void* pose, RwV3d* output);
extern RwV3d* gcPose0024faa0(void* pose);
extern void gcPose0024fba0_y2(void* pose, RtQuat* output);
extern void func_0024f7f0(void* pose, const RwV3d* offset);
extern void func_00250280(void* pose, const RwV3d* offset);
extern void FUN_004bdde0(f32 angle, f32* output, const f32* axis, s32 mode);
extern void FUN_004c69f0(RwV3d* output, const RwV3d* input);
extern RwV3d DAT_0068e9b0;
void func_0024da60(void* camera);

void func_0024dc90(void* camera);
static u32* sflCameraNodeHead(void)
{
    K_ASSERT(sSflCamera != NULL, 0x3b);
    return (u32*)sSflCamera[1];
}

static u32* sflCameraFindNode(u16 id)
{
    u32* node;

    node = sflCameraNodeHead();
    while (node != NULL) {
        if (*(u16*)((u8*)node + 4) == id) {
            return node;
        }
        node = (u32*)node[3];
    }
    return NULL;
}

static inline u32* sflCameraFindRequiredNode(u32* node, s32 id)
{
    u32 key;

    key = (u16)id;
    while (node != NULL) {
        if (*(u16*)((u8*)node + 4) == key) {
            return node;
        }
        node = (u32*)node[3];
    }
    K_ASSERT(0, 0xaf);
    return NULL;
}






// FUN_0024DA20
void func_0024da20(void)
{
    K_ASSERT(sSflCameraNodes != NULL, 0x5d);
    sSflCameraNodes = NULL;
}

// FUN_0024DA60
void func_0024da60(void* camera)
{
    u32* list;

    K_ASSERT(sSflCameraNodes != NULL, 0x5d);
    list = sSflCameraNodes;
    *(u32*)((u8*)camera + 8) = 0;
    *(u32*)((u8*)camera + 0x10) = 0;
    if (list[0] != 0) {
        *(u32*)((u8*)camera + 0) = list[1];
        *(u32*)((u8*)camera + 4) = 0;
        ((u32*)list[1])[1] = (u32)camera;
        list[1] = (u32)camera;
    } else {
        *(u32*)((u8*)camera + 4) = 0;
        *(u32*)((u8*)camera + 0) = 0;
        list[0] = (u32)camera;
        list[1] = (u32)camera;
    }
}

// FUN_0024DAF0
void func_0024daf0(u32* camera)
{
    u32* list;
    u32* link;

    K_ASSERT(sSflCameraNodes != NULL, 0x5d);
    list = sSflCameraNodes;
    link = (u32*)camera[1];
    if (link != NULL) {
        link[0] = camera[0];
    }
    link = (u32*)camera[0];
    if (link != NULL) {
        link[1] = camera[1];
    }
    if (camera == (u32*)list[0]) {
        list[0] = camera[1];
    }
    if (camera == (u32*)list[1]) {
        list[1] = camera[0];
    }
}

// FUN_0024DB90
void func_0024db90(void)
{
    u32* camera;

    K_ASSERT(sSflCameraNodes != NULL, 0x5d);
    camera = (u32*)sSflCameraNodes[0];
    while (camera != NULL) {
        if ((~camera[2] & 1u) == 0) {
            bpTut00251010(camera, 0x10000);
        }
        camera = (u32*)camera[1];
    }
}

// FUN_0024DC10
void func_0024dc10(void)
{
    u32* camera;
    u32* list;

    K_ASSERT(sSflCameraNodes != NULL, 0x5d);
    list = sSflCameraNodes;
    list[0x82] = 0;
    camera = (u32*)list[0];
    while (camera != NULL) {
        func_0024dc90(camera);
        camera = (u32*)camera[1];
    }
}

// Retail cross-check restored the state-0 interpolation path and state-2 mode fields.
// The state-0 mode-3 path now clamps, interpolates, and clears completion flags.
// State-2 mode-3 uses the node's inline pose payload, matching retail addressing.
// State-2 mode-4 uses its distinct duration field for the second cubic segment.
// Queue setup and cleanup avoid an unnecessary persistent counter local.
// The function remains NONMATCHING while these semantic repairs alter scheduling.
// FUN_0024DC90 NONMATCHING
void func_0024dc90(void* camera)
{
    u32* list;
    u8* node;
    u32 queued;
    u32 i;
    u32* pose;
    u32** poses;
    f32* p;
    f32 ratio;
    f32 ratio2;
    f32 oneMinus;
    f32 dot;
    f32 angle;
    f32 extent;
    u32 random;
    u32 duration;
    RwV3d first;
    RwV3d second;
    RwV3d value;
    RwV3d offset;
    RwV3d axis;
    RwV3d cross;
    RwV3d* firstPoseVector;
    RwV3d* secondPoseVector;

    K_ASSERT(sSflCameraNodes != NULL, 0x5d);
    list = sSflCameraNodes;
    K_ASSERT(list[0x82] == 0, 0xe6);
    list[list[0x82] + 2] = (u32)camera;
    list[0x82]++;

    while (list[0x82] != 0) {
        u32 flags;
        u32 state;
        u32 mode;
        node = (u8*)list[list[0x82] + 1];
        flags = *(u32*)(node + 8);
        queued = 0;
        if ((flags & 1) != 0 && (flags & 2) != 0) {
            state = *(u32*)(node + 0xc);

            switch (state) {
            case 0: {
                mode = *(u32*)(node + 0x20);
                switch (mode) { case 1: { u32 oldTimer;
                u32 firstDuration;
                
                p = (f32*)(node + 0x24);
                oldTimer = *(u32*)(node + 0x10);
                firstDuration = (*(u32*)(node + 0x58)) << 16;
                ratio = (f32)(s32)oldTimer / (f32)(s32)firstDuration;
                
                offset.x = p[6] - p[9];
                offset.y = p[7] - p[10];
                offset.z = p[8] - p[11];
                first = offset;
                first.x = -first.x;
                first.y = -first.y;
                first.z = -first.z;
                *(RwV3d*)&p[0] = *(RwV3d*)&p[9];
                extent = p[12];
                
                random = RpRandom() & 0xfff;
                offset.x = extent / 2.0f - extent * (f32)random / 4096.0f;
                random = RpRandom() & 0xfff;
                offset.y = extent / 2.0f - extent * (f32)random / 4096.0f;
                random = RpRandom() & 0xfff;
                offset.z = extent / 2.0f - extent * (f32)random / 4096.0f;
                *(RwV3d*)&p[9] = offset;
                func_0024f7f0(node, &first);
                *(u32*)(node + 0x10) = 0;
                
                if (oldTimer >= firstDuration) {
                    oneMinus = 1.0f - ratio;
                    value.x = p[0] * oneMinus * oneMinus * oneMinus +
                              3.0f * p[3] * ratio * oneMinus * oneMinus +
                              3.0f * p[6] * ratio * ratio * oneMinus +
                              p[9] * ratio * ratio * ratio;
                    value.y = p[1] * oneMinus * oneMinus * oneMinus +
                              3.0f * p[4] * ratio * oneMinus * oneMinus +
                              3.0f * p[7] * ratio * ratio * oneMinus +
                              p[10] * ratio * ratio * ratio;
                    value.z = p[2] * oneMinus * oneMinus * oneMinus +
                              3.0f * p[5] * ratio * oneMinus * oneMinus +
                              3.0f * p[8] * ratio * ratio * oneMinus +
                              p[11] * ratio * ratio * ratio;
                    *(RwV3d*)(node + 0x14) = value;
                }
                duration = (*(u32*)(node + 0x34)) << 16;
                ratio2 = (f32)(s32)*(u32*)(node + 0x10) /
                         (f32)(s32)duration;
                oneMinus = 1.0f - ratio2;
                value.x = p[0] * oneMinus * oneMinus * oneMinus +
                          3.0f * p[3] * ratio2 * oneMinus * oneMinus +
                          3.0f * p[6] * ratio2 * ratio2 * oneMinus +
                          p[9] * ratio2 * ratio2 * ratio2;
                value.y = p[1] * oneMinus * oneMinus * oneMinus +
                          3.0f * p[4] * ratio2 * oneMinus * oneMinus +
                          3.0f * p[7] * ratio2 * ratio2 * oneMinus +
                          p[10] * ratio2 * ratio2 * ratio2;
                value.z = p[2] * oneMinus * oneMinus * oneMinus +
                          3.0f * p[5] * ratio2 * oneMinus * oneMinus +
                          3.0f * p[8] * ratio2 * ratio2 * oneMinus +
                          p[11] * ratio2 * ratio2 * ratio2;
                *(RwV3d*)(node + 0x14) = value; } break; case 0: break; case 2: { poses = (u32**)(node + 0x24);
                queued = 0;
                for (i = 0; i < 3; i++) {
                    pose = poses[i];
                    if (pose != NULL && (pose[2] & 2) == 0) {
                        K_ASSERT(list[0x82] < 0x80, 0x132);
                        list[list[0x82] + 2] = (u32)pose;
                        list[0x82]++;
                        queued = 1;
                    }
                }
                if (queued == 0) {
                    value.x = 0.0f;
                    value.y = 0.0f;
                    value.z = 0.0f;
                    for (i = 0; i < 3; i++) {
                        if (poses[i] != NULL) {
                            gcPose0024f960(poses[i], &first);
                            value.x += first.x;
                            value.y += first.y;
                            value.z += first.z;
                        }
                    }
                    *(RwV3d*)(node + 0x14) = value;
                } } break; case 3: { p = (f32*)(node + 0x24);
                if ((*(u32*)(node + 0x28) & 1u) != 0) {
                    if (*(u32*)(node + 0x10) >= *(u32*)(node + 0x2c)) {
                        *(u32*)(node + 0x10) = *(u32*)(node + 0x2c);
                    }
                    if (*(u32*)p == 0) {
                        ratio = (f32)(s32)*(u32*)(node + 0x10) /
                                (f32)(s32)*(u32*)(node + 0x2c);
                        first.x = p[6];
                        first.y = p[7];
                        first.z = p[8];
                        second.x = p[3];
                        second.y = p[4];
                        second.z = p[5];
                        second.x -= first.x;
                        second.y -= first.y;
                        second.z -= first.z;
                        second.x *= ratio;
                        second.y *= ratio;
                        second.z *= ratio;
                        value.x = first.x + second.x;
                        value.y = first.y + second.y;
                        value.z = first.z + second.z;
                        *(RwV3d*)(node + 0x14) = value;
                    }
                    else if (*(u32*)p == 1) {
                        ratio = (f32)(s32)*(u32*)(node + 0x10) /
                                1966080.0f;
                        ratio *= 0.5f;
                        value.x = p[3] * ratio + p[6];
                        value.y = p[4] * ratio + p[7];
                        value.z = p[5] * ratio + p[8];
                        *(RwV3d*)(node + 0x14) = value;
                    }
                }
                if ((*(u32*)(node + 0x28) & 1u) != 0 &&
                    *(u32*)(node + 0x10) >= *(u32*)(node + 0x2c)) {
                    *(u32*)(node + 0x28) &= ~2u;
                } } break; default: { K_ASSERT(0, 0x17d); } break; }
                break;
            }
            case 1: {
                mode = *(u32*)(node + 0x20);
                if (mode == 1) {
                    poses = (u32**)(node + 0x28);
                    queued = 0;
                    for (i = 0; i < 2; i++) {
                        pose = poses[i];
                        if ((pose[2] & 2) == 0) {
                            K_ASSERT(list[0x82] < 0x80, 0x1a9);
                            list[list[0x82] + 2] = (u32)pose;
                            list[0x82]++;
                            queued = 1;
                        }
                    }
                    if (queued == 0) {
                        gcPose0024f960(poses[0], &first);
                        gcPose0024f960(poses[1], &second);
                        value.x = second.x - first.x;
                        value.y = second.y - first.y;
                        value.z = second.z - first.z;
                        *(RwV3d*)(node + 0x14) = value;
                    }
                }
                else if (mode != 0) {
                    K_ASSERT(0, 0x1a9);
                }
                break;
            }
            case 2: {
                mode = *(u32*)(node + 0x24);
                if (mode == 1) {
                    poses = (u32**)(node + 0x28);
                    queued = 0;
                    for (i = 0; i < 2; i++) {
                        pose = poses[i];
                        if (pose != NULL && (pose[2] & 2) == 0) {
                            K_ASSERT(list[0x82] < 0x80, 0x1c4);
                            list[list[0x82] + 2] = (u32)pose;
                            list[0x82]++;
                            queued = 1;
                        }
                    }
                    if (queued == 0) {
                        gcPose0024f960(poses[0], &second);
                        gcPose0024f960(poses[1], &first);
                        value.x = first.x - second.x;
                        value.y = first.y - second.y;
                        value.z = first.z - second.z;
                        *(RwV3d*)(node + 0x14) = value;
                    }
                }
                else if (mode == 2) {
                    poses = (u32**)(node + 0x28);
                    queued = 0;
                    for (i = 0; i < 3; i++) {
                        pose = poses[i];
                        if (pose != NULL && (pose[2] & 2) == 0) {
                            K_ASSERT(list[0x82] < 0x80, 0x212);
                            list[list[0x82] + 2] = (u32)pose;
                            list[0x82]++;
                            queued = 1;
                        }
                    }
                    if (queued == 0) {
                        firstPoseVector = gcPose0024faa0(poses[0]);
                        secondPoseVector = gcPose0024faa0(poses[1]);
                        FUN_004c69f0(&first, firstPoseVector);
                        FUN_004c69f0(&second, secondPoseVector);
                        cross.x = first.y * second.z - first.z * second.y;
                        cross.y = first.z * second.x - first.x * second.z;
                        cross.z = first.x * second.y - first.y * second.x;
                        FUN_004c69f0(&cross, &cross);
                        dot = first.x * second.x +
                              first.y * second.y +
                              first.z * second.z;
                        if (dot == 1.0f) {
                            cross.x = 0.0f;
                            cross.y = 1.0f;
                            cross.z = 0.0f;
                        }
                        angle = 180.0f * (dot - 1.0f) / 2.0f;
                        FUN_004bdde0(angle, (f32*)(node + 0x14),
                                     (const f32*)&cross, 0);
                    }
                }
                else if (mode == 3) {
                    pose = (u32*)(node + 0x28);
                    if ((*(u32*)(node + 0x10) >= pose[2]) &&
                        ((pose[1] & 1) != 0)) {
                        *(u32*)(node + 0x10) = pose[2];
                    }
                    if (pose[0] == 0) {
                        ratio = (f32)(s32)*(u32*)(node + 0x10) /
                                (f32)(s32)pose[2];
                        angle = ((f32)*(s32*)((u8*)pose + 0x1c) -
                                 (f32)*(s32*)((u8*)pose + 0x18)) * ratio +
                                (f32)*(s32*)((u8*)pose + 0x18);
                        angle = angle / fGpffff81f8 * 360.0f;
                        FUN_004bdde0(angle, (f32*)(node + 0x14),
                                     (const f32*)(node + 0x34), 0);
                    }
                    else if (pose[0] == 1) {
                        ratio = (f32)(s32)*(u32*)(node + 0x10) /
                                1966080.0f;
                        angle = (f32)*(s32*)((u8*)pose + 0x20) +
                                0.5f * (f32)*(s32*)((u8*)pose + 0x24) * ratio;
                        angle = angle / fGpffff81f8 * 360.0f;
                        FUN_004bdde0(angle, (f32*)(node + 0x14),
                                     (const f32*)(node + 0x34), 0);
                    }
                    else {
                        K_ASSERT(0, 0x2a5);
                    }
                    if ((pose[1] & 1) != 0 &&
                        *(u32*)(node + 0x10) >= pose[2]) {
                        pose[1] &= ~2u;
                    }
                }
                else if (mode == 4) {
                    u32 oldTimer;
                    u32 firstDuration;

                    p = (f32*)(node + 0x28);
                    oldTimer = *(u32*)(node + 0x10);
                    firstDuration = (*(u32*)(node + 0x64)) << 16;
                    ratio = (f32)(s32)oldTimer / (f32)(s32)firstDuration;
                    offset.x = p[6] - p[9];
                    offset.y = p[7] - p[10];
                    offset.z = p[8] - p[11];
                    first = offset;
                    first.x = -first.x;
                    first.y = -first.y;
                    first.z = -first.z;
                    *(RwV3d*)&p[0] = *(RwV3d*)&p[9];
                    extent = p[12];
                    random = RpRandom() & 0xfff;
                    offset.x = extent / 2.0f - extent * (f32)random / 4096.0f;
                    random = RpRandom() & 0xfff;
                    offset.y = extent / 2.0f - extent * (f32)random / 4096.0f;
                    random = RpRandom() & 0xfff;
                    offset.z = extent / 2.0f - extent * (f32)random / 4096.0f;
                    *(RwV3d*)&p[9] = offset;
                    func_00250280(node, &first);
                    *(u32*)(node + 0x10) = 0;
                    if (oldTimer >= firstDuration) {
                        oneMinus = 1.0f - ratio;
                        value.x = p[0] * oneMinus * oneMinus * oneMinus +
                                  3.0f * p[3] * ratio * oneMinus * oneMinus +
                                  3.0f * p[6] * ratio * ratio * oneMinus +
                                  p[9] * ratio * ratio * ratio;
                        value.y = p[1] * oneMinus * oneMinus * oneMinus +
                                  3.0f * p[4] * ratio * oneMinus * oneMinus +
                                  3.0f * p[7] * ratio * ratio * oneMinus +
                                  p[10] * ratio * ratio * ratio;
                        value.z = p[2] * oneMinus * oneMinus * oneMinus +
                                  3.0f * p[5] * ratio * oneMinus * oneMinus +
                                  3.0f * p[8] * ratio * ratio * oneMinus +
                                  p[11] * ratio * ratio * ratio;
                        *(RwV3d*)(node + 0x14) = value;
                    }
                    duration = (*(u32*)(node + 0x3c)) << 16;
                    ratio2 = (f32)(s32)*(u32*)(node + 0x10) /
                             (f32)(s32)duration;
                    oneMinus = 1.0f - ratio2;
                    value.x = p[0] * oneMinus * oneMinus * oneMinus +
                              3.0f * p[3] * ratio2 * oneMinus * oneMinus +
                              3.0f * p[6] * ratio2 * ratio2 * oneMinus +
                              p[9] * ratio2 * ratio2 * ratio2;
                    value.y = p[1] * oneMinus * oneMinus * oneMinus +
                              3.0f * p[4] * ratio2 * oneMinus * oneMinus +
                              3.0f * p[7] * ratio2 * ratio2 * oneMinus +
                              p[10] * ratio2 * ratio2 * ratio2;
                    value.z = p[2] * oneMinus * oneMinus * oneMinus +
                              3.0f * p[5] * ratio2 * oneMinus * oneMinus +
                              3.0f * p[8] * ratio2 * ratio2 * oneMinus +
                              p[11] * ratio2 * ratio2 * ratio2;
                    value.x *= p[17];
                    value.y *= p[17];
                    value.z *= p[17];
                    *(RwV3d*)(node + 0xe0) = value;
                    axis.x = 1.0f;
                    axis.y = 0.0f;
                    axis.z = 0.0f;
                    FUN_004bdde0(value.x, (f32*)(node + 0x90),
                                 (const f32*)&axis, 0);
                    axis.x = 0.0f;
                    axis.y = 1.0f;
                    axis.z = 0.0f;
                    FUN_004bdde0(value.y, (f32*)(node + 0x90),
                                 (const f32*)&axis, 2);
                    axis.x = 0.0f;
                    axis.y = 0.0f;
                    axis.z = 1.0f;
                    FUN_004bdde0(value.z, (f32*)(node + 0x90),
                                 (const f32*)&axis, 2);
                    *(RtQuat*)(node + 0x14) = *(RtQuat*)(node + 0x90);
                }
                else {
                    K_ASSERT(0, 0x2ab);
                break;
            }
                break;
            }
            default:
                K_ASSERT(0, 0x2ab);
                break;
            }
        }
        if (queued == 0) {
            *(u32*)(node + 8) &= ~3u;
            list[0x82]--;
        }
    }
}




/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_00251060(void);
void FUN_002510d0(void);
void FUN_002518b0(s32 param_1);
u32 FUN_002519d0(void);
void FUN_00251a20(void);
extern int iGpffffb654;
extern void FUN_0019d3f0(const char* file, s32 line);
extern const char DAT_0068e9c0[];
#define FUN_0019d3f0(file, line) FUN_0019d3f0((const char*)(file), line)

static u32* sBpTut654; // puGpffffb654
typedef struct BpTutWork
{
    u32 flags;
    u32 phase;
    s32 type;
    u32 step;
    KwlnTask* task;
} BpTutWork;

s32 FUN_0021c8b0(s32 param_1);
u32 FUN_001114b0(KwlnTask* task);
void FUN_00111500(KwlnTask* task);
void FUN_00111530(KwlnTask* task);
u32 FUN_00195460(KwlnTask* task);
void FUN_003c72d0(s32 handle);
void FUN_003c7560(s32 param_1);
u32 FUN_003c7610(void);
u32 FUN_003c7650(s32 param_1);
void FUN_003c77a0(void);
u32 FUN_003c7850(void);
void FUN_003c7990(s32 param_1);

// FUN_00251010
void bpTut00251010(void* param_1, s32 param_2)
{
    *(s32*)((u8*)param_1 + 0x10) += param_2;
    *(u32*)((u8*)param_1 + 8) |= 2;
}

// FUN_00251030
void bpTut00251030(void* param_1)
{
    *(u32*)((u8*)param_1 + 8) |= 2;
}

// FUN_00251050
void bpTut00251050(u32* param_1)
{
    *param_1 = 0;
    sBpTut654 = param_1;
}

/* Recovered battle-misc harvest: 0x00251060-0x00251A20 */
