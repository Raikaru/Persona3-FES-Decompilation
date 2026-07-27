#include "Utils.h"
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
void gcPose00250480(int param_1)
{
    K_ASSERT(*(int*)(param_1 + 0xc) == 0, 0x466);
    K_ASSERT(*(int*)(param_1 + 0x20) == 3, 0x467);
    *(u32*)(param_1 + 0x28) &= 0xfffffffe;
}

// FUN_00250b90
u32 gcPose00250b90(int param_1)
{
    K_ASSERT(*(int*)(param_1 + 0x20) == 3, 0x512);
    return *(u32*)(param_1 + 0x28) & 1;
}

// FUN_00250c70
void gcPose00250c70(int param_1)
{
    K_ASSERT(*(int*)(param_1 + 0xc) == 2, 0x539);
    K_ASSERT(*(int*)(param_1 + 0x24) == 3, 0x53a);
    *(u32*)(param_1 + 0x2c) &= 0xfffffffe;
}

// FUN_00250e70
u32 gcPose00250e70(int param_1)
{
    K_ASSERT(*(int*)(param_1 + 0xc) == 2, 0x57d);
    K_ASSERT(*(int*)(param_1 + 0x24) == 3, 0x57e);
    return *(u32*)(param_1 + 0x2c) & 1;
}

// FUN_00250ef0
void gcPose00250ef0(int param_1, float param_2)
{
    K_ASSERT(*(int*)(param_1 + 0xc) == 2, 0x588);
    K_ASSERT(*(int*)(param_1 + 0x24) == 4, 0x589);
    *(float*)(param_1 + 0x6c) = param_2;
    *(u32*)(param_1 + 8) |= 2;
}

// FUN_0024f960
void gcPose0024f960(int param_1, RwV3d *param_2)
{
    K_ASSERT(*(int*)(param_1 + 0xc) == 0, 0x375);
    K_ASSERT(*(int*)(param_1 + 0x20) < 4, 0x376);
    *param_2 = *(RwV3d*)(param_1 + 0x14);
}

// FUN_00250500
void gcPose00250500(int param_1, RwV3d *param_2, int param_3)
{
    K_ASSERT(*(int*)(param_1 + 0x20) == 3, 0x471);
    *(u32*)(param_1 + 0x24) = 0;
    *(RwV3d*)(param_1 + 0x30) = *param_2;
    *(RwV3d*)(param_1 + 0x3c) = *(RwV3d*)(param_1 + 0x14);
    *(u32*)(param_1 + 0x10) = 0;
    *(int*)(param_1 + 0x2c) = param_3 << 0x10;
    *(u32*)(param_1 + 0x28) |= 1;
}

// FUN_0024faa0
RwV3d* gcPose0024faa0(int param_1)
{
    K_ASSERT(*(int*)(param_1 + 0x20) < 2, 0x38e);
    return (RwV3d*)(param_1 + 0x14);
}

// FUN_0024fba0
void gcPose0024fba0(int param_1, RtQuat *param_2)
{
    K_ASSERT(*(int*)(param_1 + 0xc) == 2, 0x3a6);
    K_ASSERT(*(int*)(param_1 + 0x24) < 5, 0x3a7);
    *param_2 = *(RtQuat*)(param_1 + 0x14);
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

static void gcPose0024f350(void* state);
static void gcPose0024f410(void* state);
static void gcPose0024f780(void* state);
static void gcPose0024f7f0(void* state, const RwV3d* offset);
static void gcPose0024fe40(void* state);
static void gcPose0024ff10(void* state);
static void gcPose00250280(void* state, const RwV3d* offset);

static inline f32 gcPoseRandomExtent(f32 extent)
{
    return extent / 2.0f -
        extent * (f32)(RpRandom() & 0xfff) / 4096.0f;
}


// FUN_0024F090
void gcPose0024f090(void* state)
{
    u32 mode;

    GC_U32(state, 8) |= 1;
    switch (GC_U32(state, 0xc)) {
        case 0:
            mode = GC_U32(state, 0x20);
            switch (mode) {
                case 1:
                    gcPose0024f350(state);
                    break;
                case 0:
                case 2:
                    break;
                case 3:
                    gcPose0024f780(state);
                    break;
                default:
                    K_ASSERT(0, 0x2d4);
                    break;
            }
            break;
        case 1:
            mode = GC_U32(state, 0x20);
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
            mode = GC_U32(state, 0x24);
            switch (mode) {
                case 0:
                case 1:
                case 2:
                    break;
                case 3:
                    GC_U32(state, 0x2c) = 0;
                    break;
                case 4:
                    gcPose0024fe40(state);
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
void gcPose0024f210(void* state, f32 first, u32 value, f32 fourth)
{
    K_ASSERT(GC_U32(state, 0xc) == 0, 0x30b);
    K_ASSERT(GC_U32(state, 0x20) == 1, 0x30c);
    GC_F32(state, 0x54) = first;
    GC_U32(state, 0x58) = value;
    GC_F32(state, 0x5c) = fourth;
    GC_U32(state, 8) |= 2;
}

// FUN_0024F2C0
void gcPose0024f2c0(void* state, f32 value)
{
    K_ASSERT(GC_U32(state, 0xc) == 0, 0x31b);
    K_ASSERT(GC_U32(state, 0x20) == 1, 0x31c);
    GC_F32(state, 0x60) = value;
    GC_U32(state, 8) |= 2;
}

// FUN_0024F350
static void gcPose0024f350(void* state)
{
    RwV3d offset;
    f32 *poseData;

    K_ASSERT(GC_U32(state, 0xc) == 0, 0x329);
    K_ASSERT(GC_U32(state, 0x20) == 1, 0x32a);

    poseData = (f32 *)((u8 *)state + 0x24);
    poseData[12] = 10.0f;
    *(u32 *)&poseData[13] = 0xb4;
    poseData[14] = 10.0f;
    poseData[15] = 1.0f;
    gcPose0024f410(state);

    offset.x = 0.0f;
    offset.y = 0.0f;
    offset.z = poseData[14];
    gcPose0024f7f0(state, &offset);
}

// FUN_0024F410
static void gcPose0024f410(void* state)
{
    RwV3d pose;
    f32* poseData;

    K_ASSERT(GC_U32(state, 0xc) == 0, 0x341);
    K_ASSERT(GC_U32(state, 0x20) == 1, 0x342);
    poseData = (f32*)((u8*)state + 0x24);

    pose.x = gcPoseRandomExtent(poseData[12]);
    pose.y = gcPoseRandomExtent(poseData[12]);
    pose.z = gcPoseRandomExtent(poseData[12]);
    *(RwV3d*)poseData = pose;

    pose.x = gcPoseRandomExtent(poseData[12]);
    pose.y = gcPoseRandomExtent(poseData[12]);
    pose.z = gcPoseRandomExtent(poseData[12]);
    *(RwV3d*)(poseData + 9) = pose;
}

// FUN_0024F780
static void gcPose0024f780(void* state)
{
    K_ASSERT(GC_U32(state, 0xc) == 0, 0x355);
    K_ASSERT(GC_U32(state, 0x20) == 3, 0x356);
    GC_F32(state, 0x28) = 0.0f;
}

// FUN_0024F7F0
static void gcPose0024f7f0(void* state, const RwV3d* offset)
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

    pose = (f32 *)((u8 *)state + 0x24);
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

    scale = pose[14];
    tangentX *= scale;
    tangentY *= scale;
    tangentZ *= scale;
    pose[6] = pose[9] + tangentX;
    pose[7] = pose[10] + tangentY;
    pose[8] = pose[11] + tangentZ;
}

// FUN_0024F9F0
void gcPose0024f9f0(int param_1, RwV3d* param_2)
{
    K_ASSERT(*(int*)(param_1 + 0x20) < 4, 0x37d);
    switch (*(int*)(param_1 + 0x20)) {
        case 0:
        case 3:
            *(RwV3d*)(param_1 + 0x14) = *param_2;
            break;
        default:
            K_ASSERT(0, 0x386);
            break;
    }
}

// FUN_0024FAF0
void gcPose0024faf0(int param_1, RwV3d* param_2)
{
    K_ASSERT(*(int*)(param_1 + 0x20) < 2, 0x395);
    switch (*(int*)(param_1 + 0x20)) {
        case 0:
        case 1:
            *(RwV3d*)(param_1 + 0x14) = *param_2;
            break;
        default:
            K_ASSERT(0, 0x39e);
            break;
    }
}

// FUN_0024FC40
void gcPose0024fc40(int param_1, RtQuat* param_2)
{
    K_ASSERT(*(int*)(param_1 + 0xc) == 2, 0x3ae);
    switch (*(int*)(param_1 + 0x24)) {
        case 0:
        case 1:
        case 2:
        case 3:
            *(RtQuat*)(param_1 + 0x14) = *param_2;
            break;
        default:
            K_ASSERT(0, 0x3b9);
            break;
    }
}

// FUN_0024FD10
void gcPose0024fd10(void* state)
{
    GC_U32(state, 0xc) = 0;
    GC_U32(state, 0x20) = 0;
}

// FUN_0024FD20
void gcPose0024fd20(void* state)
{
    GC_U32(state, 0xc) = 0;
    GC_U32(state, 0x20) = 1;
}

// FUN_0024FD40
void gcPose0024fd40(void* state)
{
    s32* values;
    s32 index;

    GC_U32(state, 0xc) = 0;
    GC_U32(state, 0x20) = 2;
    values = (s32*)((u8*)state + 0x24);
    for (index = 0; index < 3; index++) {
        values[index] = 0;
    }
}

// FUN_0024FD80
void gcPose0024fd80(void* state)
{
    GC_U32(state, 0xc) = 0;
    GC_U32(state, 0x20) = 3;
}

// FUN_0024FDA0
void gcPose0024fda0(void* state)
{
    GC_U32(state, 0xc) = 1;
    GC_U32(state, 0x20) = 0;
}

// FUN_0024FDC0
void gcPose0024fdc0(void* state)
{
    s32* values;
    s32 index;

    GC_U32(state, 0xc) = 2;
    GC_U32(state, 0x24) = 2;
    values = (s32*)((u8*)state + 0x28);
    for (index = 0; index < 3; index++) {
        values[index] = 0;
    }
}

// FUN_0024FE00
void gcPose0024fe00(void* state)
{
    GC_U32(state, 0xc) = 2;
    GC_U32(state, 0x24) = 3;
}

// FUN_0024FE20
void gcPose0024fe20(void* state)
{
    GC_U32(state, 0xc) = 2;
    GC_U32(state, 0x24) = 4;
}

// FUN_0024FE40
static void gcPose0024fe40(void* state)
{
    RwV3d offset;
    f32* poseData;

    K_ASSERT(GC_U32(state, 0xc) == 2, 0x41b);
    K_ASSERT(GC_U32(state, 0x24) == 4, 0x41c);
    poseData = (f32*)((u8*)state + 0x28);
    GC_F32(state, 0x58) = 5.0f;
    GC_F32(state, 0x5c) = 15.0f;
    GC_F32(state, 0x60) = 15.0f;
    GC_U32(state, 0x64) = 0xB4;
    poseData[0x10] = 1.0f;
    GC_F32(state, 0x6c) = 1.0f;
    gcPose0024ff10(state);
    offset.x = 0.0f;
    offset.y = 0.0f;
    offset.z = poseData[0x10];
    gcPose00250280(state, &offset);
}

// FUN_0024FF10
static void gcPose0024ff10(void* state)
{
    RwV3d pose;
    f32* poseData;

    K_ASSERT(GC_U32(state, 0xc) == 2, 0x434);
    K_ASSERT(GC_U32(state, 0x24) == 4, 0x435);
    poseData = (f32*)((u8*)state + 0x28);

    pose.x = gcPoseRandomExtent(poseData[12]);
    pose.y = gcPoseRandomExtent(poseData[13]);
    pose.z = gcPoseRandomExtent(poseData[14]);
    *(RwV3d*)poseData = pose;

    pose.x = gcPoseRandomExtent(poseData[12]);
    pose.y = gcPoseRandomExtent(poseData[13]);
    pose.z = gcPoseRandomExtent(poseData[14]);
    *(RwV3d*)(poseData + 9) = pose;
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
