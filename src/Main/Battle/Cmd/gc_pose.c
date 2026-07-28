#include "Utils.h"
#include "Main/Battle/Cmd/gc_pose.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwln.h"
#include "Kosaka/k_assert.h"
#include "rw/rprandom.h"
#include "rw/rwplcore.h"
#include "rw/rtquat.h"

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
void gcPoseStartDirectedTranslation(u8 *work, const RwV3d *target, s32 frames, const RwV3d *direction);
void gcPoseStartEaseOutTranslation(int param_1,u32 *param_2,int param_3);
void gcPoseStartEaseInTranslation(int param_1,u32 *param_2,int param_3);
void gcPoseSetRotationVectorElement(int param_1,int param_2,u32 param_3);
void gcPoseStartRotation(u32 *work, void *target, f32 startAngle, f32 endAngle, s32 frames);
void gcPoseProjectToScreen(float* output, const RwV3d* input);

extern f32 fGpffff81f8;
extern void FUN_004bdde0(f32 angle, void *output, void *target, s32 mode);
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
void gcPose0024f960(GcPoseController *pose, RwV3d *param_2)
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
RwV3d* gcPose0024faa0(GcPoseController *pose)
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


/*
 * The pose controller is a small two-level state machine.  Its retail work
 * area is embedded in several Battle model records, so the public callbacks
 * intentionally operate on byte offsets rather than imposing a new ABI on
 * those records.
 */
#define GC_U32(work, offset) (*(u32*)((u8*)(work) + (offset)))
#define GC_S32(work, offset) (*(s32*)((u8*)(work) + (offset)))
#define GC_F32(work, offset) (*(f32*)((u8*)(work) + (offset)))
#define GC_V3D(work, offset) ((RwV3d*)((u8*)(work) + (offset)))

static void gcPose0024f350(GcPoseController* pose);
static void gcPose0024f410(GcPoseController* pose);
static void gcPose0024f780(GcPoseController* pose);
static void gcPose0024f7f0(GcPoseController* pose, const RwV3d* offset);
static void gcPose0024fe40(GcPoseController* pose);
static void gcPose0024ff10(GcPoseController* pose);
static void gcPose00250280(void* state, const RwV3d* offset);

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
static void gcPose00250280(void* state, const RwV3d* offset)
{
    f32 *pose;
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

    pose = (f32 *)((u8 *)state + 0x28);
    pose[3] = pose[0] + offset->x;
    pose[4] = pose[1] + offset->y;
    pose[5] = pose[2] + offset->z;

    fromOrigin.x = anchor.x - pose[9];
    fromOrigin.y = anchor.y - pose[10];
    fromOrigin.z = anchor.z - pose[11];
    toOrigin.x = pose[9] - pose[0];
    toOrigin.y = pose[10] - pose[1];
    toOrigin.z = pose[11] - pose[2];
    RwV3dNormalize(&fromOrigin, &fromOrigin);
    RwV3dNormalize(&toOrigin, &toOrigin);
    crossX = toOrigin.y * fromOrigin.z - toOrigin.z * fromOrigin.y;
    crossY = toOrigin.z * fromOrigin.x - toOrigin.x * fromOrigin.z;
    crossZ = toOrigin.x * fromOrigin.y - toOrigin.y * fromOrigin.x;
    tangentX = crossY * fromOrigin.z - crossZ * fromOrigin.y;
    tangentY = crossZ * fromOrigin.x - crossX * fromOrigin.z;
    tangentZ = crossX * fromOrigin.y - crossY * fromOrigin.x;

    scale = pose[16];
    tangentX *= scale;
    tangentY *= scale;
    tangentZ *= scale;
    pose[6] = pose[9] + tangentX;
    pose[7] = pose[10] + tangentY;
    pose[8] = pose[11] + tangentZ;
}

// FUN_002503F0
void gcPose002503f0(void* state, s32 index, u32 value)
{
    u32 address;
    K_ASSERT(GC_U32(state, 0x20) == 2, 0x45c);
    K_ASSERT(index < 3, 0x45d);
    address = index * 4;
    address += (u32)state;
    *(u32*)(address + 0x24) = value;
}

/* Recovered battle-misc harvest: 0x002505B0-0x00250F80 */
// FUN_002505B0


void gcPoseStartDirectedTranslation(u8 *work, const RwV3d *target, s32 frames, const RwV3d *direction)
{
    u32 *state;
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

    K_ASSERT(*(s32 *)(work + 0xc) == 0, 0x4a9);
    K_ASSERT(*(s32 *)(work + 0x20) == 3, 0x4aa);

    fixedFrames = frames << 16;
    duration = (f32)fixedFrames / 1966080.0f;
    state = (u32 *)(work + 0x24);
    state[0] = 1;
    acceleration = (RwV3d *)((u8 *)state + 0xc);
    *(acceleration + 1) = *direction;
    *(RwV3d *)(work + 0x54) = *target;
    *(RwV3d *)(work + 0x48) = *(RwV3d *)(work + 0x14);

    delta.x = *(f32 *)(work + 0x54) - *(f32 *)(work + 0x48);
    delta.y = *(f32 *)(work + 0x58) - *(f32 *)(work + 0x4c);
    delta.z = *(f32 *)(work + 0x5c) - *(f32 *)(work + 0x50);
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

    *(u32 *)(work + 0x10) = 0;
    state[2] = (u32)fixedFrames;
    state[1] |= 1;
}

// FUN_002508C0


void gcPoseStartEaseOutTranslation(int param_1, u32 *param_2, int param_3)
{
    u8 *work;
    f32 *target;
    f32 duration;
    f32 factor;
    f32 delta;
    f32 x;
    f32 y;
    f32 z;

    work = (u8 *)param_1;
    target = (f32 *)param_2;
    K_ASSERT(*(s32 *)(work + 0xc) == 0, 0x4d6);
    K_ASSERT(*(s32 *)(work + 0x20) == 3, 0x4d7);

    duration = (f32)(param_3 << 16) / 1966080.0f;
    *(u32 *)(work + 0x24) = 1;
    *(RwV3d *)(work + 0x54) = *(RwV3d *)target;
    *(RwV3d *)(work + 0x48) = *(RwV3d *)(work + 0x14);

    factor = 2.0f / (duration * duration);
    delta = *(f32 *)(work + 0x54) - *(f32 *)(work + 0x48);
    x = delta * factor;
    delta = *(f32 *)(work + 0x58) - *(f32 *)(work + 0x4c);
    y = delta * factor;
    delta = *(f32 *)(work + 0x5c) - *(f32 *)(work + 0x50);
    z = delta * factor;

    *(f32 *)(work + 0x30) = -1.0f * x;
    *(f32 *)(work + 0x34) = -1.0f * y;
    *(f32 *)(work + 0x38) = -1.0f * z;
    *(f32 *)(work + 0x3c) = x * duration;
    *(f32 *)(work + 0x40) = y * duration;
    *(f32 *)(work + 0x44) = z * duration;

    *(u32 *)(work + 0x10) = 0;
    *(s32 *)(work + 0x2c) = param_3 << 16;
    *(u32 *)(work + 0x28) |= 1;
}

// FUN_00250A30


void gcPoseStartEaseInTranslation(int param_1, u32 *param_2, int param_3)
{
    u8 *work;
    f32 *target;
    f32 duration;
    f32 factor;
    f32 delta;
    RwV3d acceleration;

    work = (u8 *)param_1;
    target = (f32 *)param_2;
    K_ASSERT(*(s32 *)(work + 0xc) == 0, 0x4f5);
    K_ASSERT(*(s32 *)(work + 0x20) == 3, 0x4f6);

    duration = (f32)(param_3 << 16) / 1966080.0f;
    *(u32 *)(work + 0x24) = 1;
    *(RwV3d *)(work + 0x54) = *(RwV3d *)target;
    *(RwV3d *)(work + 0x48) = *(RwV3d *)(work + 0x14);

    factor = 2.0f / (duration * duration);
    delta = *(f32 *)(work + 0x54) - *(f32 *)(work + 0x48);
    acceleration.x = delta * factor;
    delta = *(f32 *)(work + 0x58) - *(f32 *)(work + 0x4c);
    acceleration.y = delta * factor;
    delta = *(f32 *)(work + 0x5c) - *(f32 *)(work + 0x50);
    acceleration.z = delta * factor;
    *(RwV3d *)(work + 0x30) = acceleration;

    *(u32 *)(work + 0x3c) = 0;
    *(u32 *)(work + 0x40) = 0;
    *(u32 *)(work + 0x44) = 0;
    *(u32 *)(work + 0x10) = 0;
    *(s32 *)(work + 0x2c) = param_3 << 16;
    *(u32 *)(work + 0x28) |= 1;
}

// FUN_00250BE0


void gcPoseSetRotationVectorElement(int param_1, int param_2, u32 param_3)
{
    K_ASSERT(*(s32*)(param_1 + 0xc) == 2, 0x52f);
    K_ASSERT(*(s32*)(param_1 + 0x24) == 2, 0x530);
    {
        s32 offset = param_2 * 4;
        *(u32*)(offset + param_1 + 0x28) = param_3;
    }
}

// FUN_00250CF0


void gcPoseStartRotation(u32 *work, void *target, f32 startAngle, f32 endAngle, s32 frames)
{
    u32 *state;
    u8 *motion;
    f32 duration;
    f32 acceleration;

    K_ASSERT(*(s32 *)((u8 *)work + 0xc) == 2, 0x55d);
    K_ASSERT(*(s32 *)((u8 *)work + 0x24) == 3, 0x55e);

    state = (u32 *)((u8 *)work + 0x28);
    motion = (u8 *)state + 0xc;
    state[0] = 1;
    *(RwV3d *)motion = *(RwV3d *)target;
    *(f32 *)(motion + 0xc) = startAngle;
    *(f32 *)(motion + 0x10) = endAngle;
    FUN_004bdde0((*(f32 *)(motion + 0xc) / fGpffff81f8) * 360.0f,
                 (u8 *)work + 0x14, target, 0);

    duration = (f32)(frames << 16) / 1966080.0f;
    acceleration = ((*(f32 *)(motion + 0x10) -
                     *(f32 *)(motion + 0xc)) * 2.0f) /
                   (duration * duration);
    *(f32 *)(motion + 0x18) = -acceleration;
    *(f32 *)(motion + 0x14) = acceleration * duration;
    work[4] = 0;
    state[2] = (u32)(frames << 16);
    state[1] |= 1;
}

// FUN_00250F80


void gcPoseProjectToScreen(float* output, const RwV3d* input)
{
    RwV3d projected;

    RwV3dTransformPoint(&projected, input, &kwlnGetMainCamera()->viewMatrix);
    output[0] = (projected.x / projected.z) * SCREEN_WIDTH;
    output[1] = (projected.y / projected.z) * SCREEN_HEIGHT;
}
