#include "Utils.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rprandom.h"
#include "rw/rwplcore.h"
#include "rw/rtquat.h"

/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_002505b0(int param_1,u32 *param_2,int param_3,u32 *param_4);
void FUN_002508c0(int param_1,u32 *param_2,int param_3);
void FUN_00250a30(int param_1,u32 *param_2,int param_3);
void FUN_00250be0(int param_1,int param_2,u32 param_3);
void FUN_00250cf0(u32 param_1,u32 param_2,int param_3,u64 param_4,int param_5);
void FUN_00250f80(float *param_1,u64 param_2);

extern f32 fGpffff81f8;

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

static f32 gcPoseRandomExtent(f32 extent)
{
    return extent * 0.5f - extent * (f32)(RpRandom() & 0xfff) / 4096.0f;
}

static void gcPoseCross(RwV3d* out, const RwV3d* left, const RwV3d* right)
{
    out->x = left->y * right->z - left->z * right->y;
    out->y = left->z * right->x - left->x * right->z;
    out->z = left->x * right->y - left->y * right->x;
}

// FUN_0024F090 NONMATCHING
void gcPose0024f090(void* state)
{
    u32 phase;
    u32 mode;

    GC_U32(state, 8) |= 1;
    phase = GC_U32(state, 0xc);
    if (phase == 2) {
        mode = GC_U32(state, 0x24);
        if (mode == 4) {
            gcPose0024fe40(state);
        } else if (mode == 3) {
            GC_U32(state, 0x2c) = 0;
        } else {
            K_ASSERT(mode == 0 || mode == 1 || mode == 2, 0x2fb);
        }
    } else if (phase == 1) {
        mode = GC_U32(state, 0x20);
        K_ASSERT(mode == 0 || mode == 1, 0x2e4);
    } else if (phase == 0) {
        mode = GC_U32(state, 0x20);
        if (mode == 3) {
            gcPose0024f780(state);
        } else if (mode == 1) {
            gcPose0024f350(state);
        } else {
            K_ASSERT(mode == 0 || mode == 2, 0x2d4);
        }
    } else {
        K_ASSERT(0, 0x302);
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

// FUN_0024F350 NONMATCHING
static void gcPose0024f350(void* state)
{
    RwV3d offset;

    K_ASSERT(GC_U32(state, 0xc) == 0, 0x329);
    K_ASSERT(GC_U32(state, 0x20) == 1, 0x32a);
    GC_F32(state, 0x54) = 10.0f;
    GC_U32(state, 0x58) = 0xB4;
    GC_F32(state, 0x5c) = 10.0f;
    GC_F32(state, 0x60) = 1.0f;
    gcPose0024f410(state);
    offset.x = 0.0f;
    offset.y = 0.0f;
    offset.z = GC_F32(state, 0x5c);
    gcPose0024f7f0(state, &offset);
}

// FUN_0024F410 NONMATCHING
static void gcPose0024f410(void* state)
{
    K_ASSERT(GC_U32(state, 0xc) == 0, 0x341);
    K_ASSERT(GC_U32(state, 0x20) == 1, 0x342);
    GC_F32(state, 0x24) = gcPoseRandomExtent(GC_F32(state, 0x54));
    GC_F32(state, 0x28) = gcPoseRandomExtent(GC_F32(state, 0x54));
    GC_F32(state, 0x2c) = gcPoseRandomExtent(GC_F32(state, 0x54));
    GC_F32(state, 0x48) = gcPoseRandomExtent(GC_F32(state, 0x54));
    GC_F32(state, 0x4c) = gcPoseRandomExtent(GC_F32(state, 0x54));
    GC_F32(state, 0x50) = gcPoseRandomExtent(GC_F32(state, 0x54));
}

// FUN_0024F780
static void gcPose0024f780(void* state)
{
    K_ASSERT(GC_U32(state, 0xc) == 0, 0x355);
    K_ASSERT(GC_U32(state, 0x20) == 3, 0x356);
    GC_F32(state, 0x28) = 0.0f;
}

// FUN_0024F7F0 NONMATCHING
static void gcPose0024f7f0(void* state, const RwV3d* offset)
{
    RwV3d anchor;
    RwV3d fromOrigin;
    RwV3d toOrigin;
    RwV3d cross;
    RwV3d tangent;

    anchor.x = 0.0f;
    anchor.y = 0.0f;
    anchor.z = 0.0f;
    GC_V3D(state, 0x30)->x = GC_F32(state, 0x24) + offset->x;
    GC_V3D(state, 0x30)->y = GC_F32(state, 0x28) + offset->y;
    GC_V3D(state, 0x30)->z = GC_F32(state, 0x2c) + offset->z;

    fromOrigin.x = anchor.x - GC_F32(state, 0x48);
    fromOrigin.y = anchor.y - GC_F32(state, 0x4c);
    fromOrigin.z = anchor.z - GC_F32(state, 0x50);
    toOrigin.x = GC_F32(state, 0x48) - GC_F32(state, 0x24);
    toOrigin.y = GC_F32(state, 0x4c) - GC_F32(state, 0x28);
    toOrigin.z = GC_F32(state, 0x50) - GC_F32(state, 0x2c);
    RwV3dNormalize(&fromOrigin, &fromOrigin);
    RwV3dNormalize(&toOrigin, &toOrigin);
    gcPoseCross(&cross, &toOrigin, &fromOrigin);
    gcPoseCross(&tangent, &cross, &fromOrigin);

    GC_F32(state, 0x3c) = GC_F32(state, 0x48) +
        tangent.x * GC_F32(state, 0x5c);
    GC_F32(state, 0x40) = GC_F32(state, 0x4c) +
        tangent.y * GC_F32(state, 0x5c);
    GC_F32(state, 0x44) = GC_F32(state, 0x50) +
        tangent.z * GC_F32(state, 0x5c);
}

// FUN_0024F9F0 NONMATCHING
void gcPose0024f9f0(int param_1, RwV3d* param_2)
{
    K_ASSERT(*(int*)(param_1 + 0x20) < 4, 0x37d);
    if ((*(int*)(param_1 + 0x20) == 3) || (*(int*)(param_1 + 0x20) == 0)) {
        *(RwV3d*)(param_1 + 0x14) = *param_2;
    } else {
        K_ASSERT(0, 0x386);
    }
}

// FUN_0024FAF0 NONMATCHING
void gcPose0024faf0(int param_1, RwV3d* param_2)
{
    K_ASSERT(*(int*)(param_1 + 0x20) < 2, 0x395);
    if ((*(int*)(param_1 + 0x20) == 1) || (*(int*)(param_1 + 0x20) == 0)) {
        *(RwV3d*)(param_1 + 0x14) = *param_2;
    } else {
        K_ASSERT(0, 0x39e);
    }
}

// FUN_0024FC40 NONMATCHING
void gcPose0024fc40(int param_1, RtQuat* param_2)
{
    K_ASSERT(*(int*)(param_1 + 0xc) == 2, 0x3ae);
    K_ASSERT((*(int*)(param_1 + 0x24) == 0) ||
             (*(int*)(param_1 + 0x24) == 1) ||
             (*(int*)(param_1 + 0x24) == 2) ||
             (*(int*)(param_1 + 0x24) == 3), 0x3b9);
    *param_2 = *(RtQuat*)(param_1 + 0x14);
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

// FUN_0024FD40 NONMATCHING
void gcPose0024fd40(void* state)
{
    GC_U32(state, 0xc) = 0;
    GC_U32(state, 0x20) = 2;
    GC_U32(state, 0x24) = 0;
    GC_U32(state, 0x28) = 0;
    GC_U32(state, 0x2c) = 0;
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

// FUN_0024FDC0 NONMATCHING
void gcPose0024fdc0(void* state)
{
    GC_U32(state, 0xc) = 2;
    GC_U32(state, 0x24) = 2;
    GC_U32(state, 0x28) = 0;
    GC_U32(state, 0x2c) = 0;
    GC_U32(state, 0x30) = 0;
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

// FUN_0024FE40 NONMATCHING
static void gcPose0024fe40(void* state)
{
    RwV3d offset;

    K_ASSERT(GC_U32(state, 0xc) == 2, 0x41b);
    K_ASSERT(GC_U32(state, 0x24) == 4, 0x41c);
    GC_F32(state, 0x58) = 5.0f;
    GC_F32(state, 0x5c) = 15.0f;
    GC_F32(state, 0x60) = 15.0f;
    GC_U32(state, 0x64) = 0xB4;
    GC_F32(state, 0x68) = 1.0f;
    GC_F32(state, 0x6c) = 1.0f;
    gcPose0024ff10(state);
    offset.x = 0.0f;
    offset.y = 0.0f;
    offset.z = GC_F32(state, 0x68);
    gcPose00250280(state, &offset);
}

// FUN_0024FF10 NONMATCHING
static void gcPose0024ff10(void* state)
{
    K_ASSERT(GC_U32(state, 0xc) == 2, 0x434);
    K_ASSERT(GC_U32(state, 0x24) == 4, 0x435);
    GC_F32(state, 0x28) = gcPoseRandomExtent(GC_F32(state, 0x58));
    GC_F32(state, 0x2c) = gcPoseRandomExtent(GC_F32(state, 0x5c));
    GC_F32(state, 0x30) = gcPoseRandomExtent(GC_F32(state, 0x60));
    GC_F32(state, 0x4c) = gcPoseRandomExtent(GC_F32(state, 0x58));
    GC_F32(state, 0x50) = gcPoseRandomExtent(GC_F32(state, 0x5c));
    GC_F32(state, 0x54) = gcPoseRandomExtent(GC_F32(state, 0x60));
}

// FUN_00250280 NONMATCHING
static void gcPose00250280(void* state, const RwV3d* offset)
{
    RwV3d anchor;
    RwV3d fromOrigin;
    RwV3d toOrigin;
    RwV3d cross;
    RwV3d tangent;
    anchor.x = 0.0f;
    anchor.y = 0.0f;
    anchor.z = 0.0f;
    GC_V3D(state, 0x34)->x = GC_F32(state, 0x28) + offset->x;
    GC_V3D(state, 0x34)->y = GC_F32(state, 0x2c) + offset->y;
    GC_V3D(state, 0x34)->z = GC_F32(state, 0x30) + offset->z;

    fromOrigin.x = anchor.x - GC_F32(state, 0x4c);
    fromOrigin.y = anchor.y - GC_F32(state, 0x50);
    fromOrigin.z = anchor.z - GC_F32(state, 0x54);
    toOrigin.x = GC_F32(state, 0x4c) - GC_F32(state, 0x28);
    toOrigin.y = GC_F32(state, 0x50) - GC_F32(state, 0x2c);
    toOrigin.z = GC_F32(state, 0x54) - GC_F32(state, 0x30);
    RwV3dNormalize(&fromOrigin, &fromOrigin);
    RwV3dNormalize(&toOrigin, &toOrigin);
    gcPoseCross(&cross, &toOrigin, &fromOrigin);
    gcPoseCross(&tangent, &cross, &fromOrigin);

    GC_F32(state, 0x40) = GC_F32(state, 0x4c) +
        tangent.x * GC_F32(state, 0x68);
    GC_F32(state, 0x44) = GC_F32(state, 0x50) +
        tangent.y * GC_F32(state, 0x68);
    GC_F32(state, 0x48) = GC_F32(state, 0x54) +
        tangent.z * GC_F32(state, 0x68);
}

// FUN_002503F0 NONMATCHING
void gcPose002503f0(void* state, s32 index, u32 value)
{
    K_ASSERT(GC_U32(state, 0x20) == 2, 0x45c);
    K_ASSERT(index < 3, 0x45d);
    GC_U32(state, 0x24 + index * 4) = value;
}

/* Recovered battle-misc harvest: 0x002505B0-0x00250F80 */
// FUN_002505B0 NONMATCHING


void FUN_002505b0(int param_1,u32 *param_2,int param_3,u32 *param_4)



{

  float *pfVar1;

  u32 uVar2;

  u32 uVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  

  if (*(int *)(param_1 + 0xc) != 0) {

    FUN_0019d3f0(0x68e9a0,0x4a9);

  }

  if (*(int *)(param_1 + 0x20) != 3) {

    FUN_0019d3f0(0x68e9a0,0x4aa);

  }

  fVar8 = (float)(param_3 << 0x10) / 1.96608e+06;

  *(u32 *)(param_1 + 0x24) = 1;

  pfVar1 = (float *)(param_1 + 0x30);

  uVar2 = param_4[1];

  uVar3 = param_4[2];

  *(u32 *)(param_1 + 0x3c) = *param_4;

  *(u32 *)(param_1 + 0x40) = uVar2;

  *(u32 *)(param_1 + 0x44) = uVar3;

  uVar2 = param_2[1];

  uVar3 = param_2[2];

  *(u32 *)(param_1 + 0x54) = *param_2;

  *(u32 *)(param_1 + 0x58) = uVar2;

  *(u32 *)(param_1 + 0x5c) = uVar3;

  *(u32 *)(param_1 + 0x48) = *(u32 *)(param_1 + 0x14);

  *(u32 *)(param_1 + 0x4c) = *(u32 *)(param_1 + 0x18);

  *(u32 *)(param_1 + 0x50) = *(u32 *)(param_1 + 0x1c);

  fStack_10 = *(float *)(param_1 + 0x54) - *(float *)(param_1 + 0x48);

  fStack_c = *(float *)(param_1 + 0x58) - *(float *)(param_1 + 0x4c);

  fStack_8 = *(float *)(param_1 + 0x5c) - *(float *)(param_1 + 0x50);

  FUN_004c69f0(&fStack_20,&fStack_10);

  FUN_004c69f0(&fStack_30,param_1 + 0x3c);

  fVar7 = fStack_18 * fStack_28 + fStack_20 * fStack_30 + fStack_1c * fStack_2c;

  fVar4 = (float)FUN_004c6ac0(param_1 + 0x3c);

  fVar5 = fStack_20 * fVar7 * fVar4;

  fVar4 = (float)FUN_004c6ac0(param_1 + 0x3c);

  fVar6 = fStack_1c * fVar7 * fVar4;

  fVar4 = (float)FUN_004c6ac0(param_1 + 0x3c);

  fStack_18 = fStack_18 * fVar7 * fVar4;

  fVar4 = -1.0 / (fVar8 * fVar8);

  *pfVar1 = (fVar5 * fVar8 - fStack_10) * 2.0 * fVar4;

  *(float *)(param_1 + 0x34) = (fVar6 * fVar8 - fStack_c) * 2.0 * fVar4;

  *(float *)(param_1 + 0x38) = (fStack_18 * fVar8 - fStack_8) * 2.0 * fVar4;

  *pfVar1 = *pfVar1 + (*(float *)(param_1 + 0x3c) - fVar5) * fVar8 * 2.0 * fVar4;

  *(float *)(param_1 + 0x34) =

       *(float *)(param_1 + 0x34) + (*(float *)(param_1 + 0x40) - fVar6) * fVar8 * 2.0 * fVar4;

  *(float *)(param_1 + 0x38) =

       *(float *)(param_1 + 0x38) + (*(float *)(param_1 + 0x44) - fStack_18) * fVar8 * 2.0 * fVar4;

  *(u32 *)(param_1 + 0x10) = 0;

  *(int *)(param_1 + 0x2c) = param_3 << 0x10;

  *(u32 *)(param_1 + 0x28) = *(u32 *)(param_1 + 0x28) | 1;

  return;

}

// FUN_002508C0 NONMATCHING


void FUN_002508c0(int param_1,u32 *param_2,int param_3)



{

  u32 uVar1;

  u32 uVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  

  if (*(int *)(param_1 + 0xc) != 0) {

    FUN_0019d3f0(0x68e9a0,0x4d6);

  }

  if (*(int *)(param_1 + 0x20) != 3) {

    FUN_0019d3f0(0x68e9a0,0x4d7);

  }

  fVar5 = (float)(param_3 << 0x10) / 1.96608e+06;

  *(u32 *)(param_1 + 0x24) = 1;

  uVar1 = param_2[1];

  uVar2 = param_2[2];

  *(u32 *)(param_1 + 0x54) = *param_2;

  *(u32 *)(param_1 + 0x58) = uVar1;

  *(u32 *)(param_1 + 0x5c) = uVar2;

  *(u32 *)(param_1 + 0x48) = *(u32 *)(param_1 + 0x14);

  *(u32 *)(param_1 + 0x4c) = *(u32 *)(param_1 + 0x18);

  *(u32 *)(param_1 + 0x50) = *(u32 *)(param_1 + 0x1c);

  fVar4 = 2.0 / (fVar5 * fVar5);

  fVar6 = (*(float *)(param_1 + 0x54) - *(float *)(param_1 + 0x48)) * fVar4;

  fVar3 = (*(float *)(param_1 + 0x58) - *(float *)(param_1 + 0x4c)) * fVar4;

  fVar4 = (*(float *)(param_1 + 0x5c) - *(float *)(param_1 + 0x50)) * fVar4;

  *(float *)(param_1 + 0x30) = fVar6 * -1.0;

  *(float *)(param_1 + 0x34) = fVar3 * -1.0;

  *(float *)(param_1 + 0x38) = fVar4 * -1.0;

  *(float *)(param_1 + 0x3c) = fVar6 * fVar5;

  *(float *)(param_1 + 0x40) = fVar3 * fVar5;

  *(float *)(param_1 + 0x44) = fVar4 * fVar5;

  *(u32 *)(param_1 + 0x10) = 0;

  *(int *)(param_1 + 0x2c) = param_3 << 0x10;

  *(u32 *)(param_1 + 0x28) = *(u32 *)(param_1 + 0x28) | 1;

  return;

}

// FUN_00250A30 NONMATCHING


void FUN_00250a30(int param_1,u32 *param_2,int param_3)



{

  u32 uVar1;

  u32 uVar2;

  float fVar3;

  

  if (*(int *)(param_1 + 0xc) != 0) {

    FUN_0019d3f0(0x68e9a0,0x4f5);

  }

  if (*(int *)(param_1 + 0x20) != 3) {

    FUN_0019d3f0(0x68e9a0,0x4f6);

  }

  fVar3 = (float)(param_3 << 0x10) / 1.96608e+06;

  *(u32 *)(param_1 + 0x24) = 1;

  uVar1 = param_2[1];

  uVar2 = param_2[2];

  *(u32 *)(param_1 + 0x54) = *param_2;

  *(u32 *)(param_1 + 0x58) = uVar1;

  *(u32 *)(param_1 + 0x5c) = uVar2;

  *(u32 *)(param_1 + 0x48) = *(u32 *)(param_1 + 0x14);

  *(u32 *)(param_1 + 0x4c) = *(u32 *)(param_1 + 0x18);

  *(u32 *)(param_1 + 0x50) = *(u32 *)(param_1 + 0x1c);

  fVar3 = 2.0 / (fVar3 * fVar3);

  *(float *)(param_1 + 0x30) = (*(float *)(param_1 + 0x54) - *(float *)(param_1 + 0x48)) * fVar3;

  *(float *)(param_1 + 0x34) = (*(float *)(param_1 + 0x58) - *(float *)(param_1 + 0x4c)) * fVar3;

  *(float *)(param_1 + 0x38) = (*(float *)(param_1 + 0x5c) - *(float *)(param_1 + 0x50)) * fVar3;

  *(u32 *)(param_1 + 0x3c) = 0;

  *(u32 *)(param_1 + 0x40) = 0;

  *(u32 *)(param_1 + 0x44) = 0;

  *(u32 *)(param_1 + 0x10) = 0;

  *(int *)(param_1 + 0x2c) = param_3 << 0x10;

  *(u32 *)(param_1 + 0x28) = *(u32 *)(param_1 + 0x28) | 1;

  return;

}

// FUN_00250BE0 NONMATCHING


void FUN_00250be0(int param_1,int param_2,u32 param_3)



{

  if (*(int *)(param_1 + 0xc) != 2) {

    FUN_0019d3f0(0x68e9a0,0x52f);

  }

  if (*(int *)(param_1 + 0x24) != 2) {

    FUN_0019d3f0(0x68e9a0,0x530);

  }

  *(u32 *)(param_2 * 4 + param_1 + 0x28) = param_3;

  return;

}

// FUN_00250CF0 NONMATCHING


void FUN_00250cf0(u32 param_1,u32 param_2,int param_3,u64 param_4,int param_5)



{

  u32 *puVar1;

  u32 uVar2;

  float fVar3;

  u32 uVar4;

  float fVar5;

  

  if (*(int *)(param_3 + 0xc) != 2) {

    FUN_0019d3f0(0x68e9a0,0x55d);

  }

  if (*(int *)(param_3 + 0x24) != 3) {

    FUN_0019d3f0(0x68e9a0,0x55e);

  }

  *(u32 *)(param_3 + 0x28) = 1;

  puVar1 = (u32 *)param_4;

  uVar2 = puVar1[1];

  uVar4 = puVar1[2];

  *(u32 *)(param_3 + 0x34) = *puVar1;

  *(u32 *)(param_3 + 0x38) = uVar2;

  *(u32 *)(param_3 + 0x3c) = uVar4;

  *(u32 *)(param_3 + 0x40) = param_1;

  *(u32 *)(param_3 + 0x44) = param_2;

  FUN_004bdde0((*(float *)(param_3 + 0x40) / fGpffff81f8) * 360.0,param_3 + 0x14,param_4,0);

  fVar5 = (float)(param_5 << 0x10) / 1.96608e+06;

  fVar3 = ((*(float *)(param_3 + 0x44) - *(float *)(param_3 + 0x40)) * 2.0) / (fVar5 * fVar5);

  *(float *)(param_3 + 0x4c) = -fVar3;

  *(float *)(param_3 + 0x48) = fVar3 * fVar5;

  *(u32 *)(param_3 + 0x10) = 0;

  *(int *)(param_3 + 0x30) = param_5 << 0x10;

  *(u32 *)(param_3 + 0x2c) = *(u32 *)(param_3 + 0x2c) | 1;

  return;

}

// FUN_00250F80 NONMATCHING


void FUN_00250f80(float *param_1,u64 param_2)



{

  int iVar1;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  

  iVar1 = FUN_00198590();

  FUN_004c6be0(&fStack_10,param_2,iVar1 + 0x20);

  *param_1 = (fStack_10 / fStack_8) * 640.0;

  param_1[1] = (fStack_c / fStack_8) * 448.0;

  return;

}
