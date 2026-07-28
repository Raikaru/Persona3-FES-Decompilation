#ifndef GC_POSE_H
#define GC_POSE_H

#include "Utils.h"
#include "rw/rtquat.h"

/*
 * Layout recovered from the widths, signedness, and offsets used by every
 * observed gcPose controller access in the source tree. Bytes 0x00-0x07 have
 * no observed meaning and remain explicit padding. The controller type and
 * mode select overlapping position/rotation layouts; GcPoseScalar preserves
 * the conflicting s32/u32/f32 views at offsets where the original accesses
 * disagree rather than guessing one canonical type.
 */
typedef union GcPoseScalar
{
    u32 u32Value;
    s32 s32Value;
    f32 f32Value;
} GcPoseScalar;

typedef struct GcPosePositionRandomData
{
    RwV3d sample;              // 0x24
    RwV3d shiftedSample;       // 0x30
    RwV3d controlPoint;        // 0x3c
    RwV3d anchor;              // 0x48
    f32 randomExtent;          // 0x54
    GcPoseScalar parameter58;  // 0x58
    f32 offsetScale;           // 0x5c
    f32 scale;                 // 0x60
} GcPosePositionRandomData;

typedef struct GcPoseTranslationData
{
    GcPoseScalar active;       // 0x24
    GcPoseScalar flags;        // 0x28
    GcPoseScalar duration;     // 0x2c
    RwV3d acceleration;        // 0x30
    RwV3d direction;           // 0x3c
    RwV3d start;               // 0x48
    RwV3d target;              // 0x54
    u8 pad_0x60[4];
} GcPoseTranslationData;

typedef struct GcPosePositionVectorData
{
    GcPoseScalar values[3];    // 0x24
    u8 pad_0x30[0x34];
} GcPosePositionVectorData;

typedef union GcPosePositionData
{
    GcPosePositionRandomData random;
    GcPoseTranslationData translation;
    GcPosePositionVectorData vector;
} GcPosePositionData;

typedef struct GcPosePositionState
{
    RwV3d value;               // 0x14
    GcPoseScalar mode;         // 0x20
    GcPosePositionData data;   // 0x24
    u8 pad_0x64[0x0c];
} GcPosePositionState;

typedef struct GcPoseRotationVectorData
{
    GcPoseScalar values[3];    // 0x28
    u8 pad_0x34[0x3c];
} GcPoseRotationVectorData;

typedef struct GcPoseRotationKinematics
{
    RwV3d target;              // 0x34
    f32 startAngle;            // 0x40
    f32 endAngle;              // 0x44
    f32 velocity;              // 0x48
    f32 acceleration;          // 0x4c
} GcPoseRotationKinematics;

typedef struct GcPoseRotationMotionData
{
    GcPoseScalar active;       // 0x28
    GcPoseScalar flags;        // 0x2c
    GcPoseScalar duration;     // 0x30
    GcPoseRotationKinematics motion;
    u8 pad_0x50[0x20];
} GcPoseRotationMotionData;

typedef struct GcPoseRotationRandomData
{
    RwV3d sample;              // 0x28
    RwV3d shiftedSample;       // 0x34
    RwV3d controlPoint;        // 0x40
    RwV3d anchor;              // 0x4c
    f32 randomExtentX;         // 0x58
    f32 randomExtentY;         // 0x5c
    f32 randomExtentZ;         // 0x60
    u32 angle;                 // 0x64
    f32 offsetScale;           // 0x68
    f32 scale;                 // 0x6c
} GcPoseRotationRandomData;

typedef union GcPoseRotationData
{
    GcPoseRotationVectorData vector;
    GcPoseRotationMotionData motion;
    GcPoseRotationRandomData random;
} GcPoseRotationData;

typedef struct GcPoseRotationState
{
    RtQuat value;              // 0x14
    GcPoseScalar mode;         // 0x24
    GcPoseRotationData data;   // 0x28
} GcPoseRotationState;

typedef union GcPoseState
{
    GcPosePositionState position;
    GcPoseRotationState rotation;
} GcPoseState;

typedef struct GcPoseController
{
    u8 pad_0x00[8];
    u32 flags;                 // 0x08
    GcPoseScalar type;         // 0x0c
    u32 field_0x10;            // 0x10
    GcPoseState state;         // 0x14
} GcPoseController;

typedef char GcPoseController_size_must_be_0x70[
    sizeof(GcPoseController) == 0x70 ? 1 : -1];

#endif
