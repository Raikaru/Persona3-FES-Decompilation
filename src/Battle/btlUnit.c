#include "Battle/btlUnit.h"
#include "Battle/btlPacket.h"
#include "Battle/battle.h"
#include "Battle/btlAction.h"
#include "Battle/btlBoss.h"
#include "Graphics/Model/mdlManager.h"
#include "Main/Battle/Data/datUnit.h"
#include "Main/Battle/Data/datCalc.h"
#include "Scene/mt_scene.h"
#include "Graphics/Model/mdlFile.h"
#include "h_cdvd.h"
#include "Kernel/Kwln/kwln.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_00287b20(int param_1,short param_2);
void FUN_00287cf0(BtlUnit* unit, u16 mode);
void FUN_00287ea0(BtlUnit* unit);
void FUN_00288110(BtlUnit* unit);
int FUN_00288da0(int param_1,short param_2);
void FUN_002891e0(void);
u64 FUN_00289650(short param_1,u32 param_2,long param_3);
extern f32 DAT_007cad78;
extern f32 DAT_007cada4;
extern f32 DAT_007cb0cc;
extern code DAT_00960090;
extern int iGpffffa850;
extern int iGpffffb6fc;

static u32 sNextId = 1; // 007cc51c

static f32 gUnk_007cad7c = 0.3f; // 007cad7c. No idea where to put this

RwV3d gUnk_00957188; // 00957188
extern RwV3d D_00697870;
extern RwV3d D_00697880;
extern RwV3d D_00697890;
extern RwV3d D_006978A0;
extern RwV3d D_00957180;
extern u8* DAT_007ce42c;

BtlPacket* btlUnitCreateResNullifiedAnimPacket(BtlUnit* unit, f32 param_2);
BtlPacket* btlUnit00284900(BtlUnit* unit, s32 param_2);
BtlPacket* btlUnitCreateEnmDodgeAnimPacket(BtlUnit* unit, s32 unused);
void FUN_00287490(BtlUnit* unit);
void FUN_00287510(BtlUnit* unit);
void FUN_003b7090(u16 resTypeId);
void FUN_002bbbc0(void* param);

typedef struct BtlUnitAnimInfo
{
    s16 unk_0;
    s16 speedPercent;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
} BtlUnitAnimInfo;

typedef struct BtlUnitPacketBackstep
{
    RwV3d origin;          // 0x00
    RwV3d displacement;    // 0x0c
    BtlUnit* unit;         // 0x18
    s16 blendFrameCount;   // 0x1c
    s16 counter;           // 0x1e
    f32 phase;             // 0x20
} BtlUnitPacketBackstep;

void func_0027f530(BtlUnit* unit);
void func_00280050(void* param_1, RwV3d* param_2);
f32 func_00280870(u32 param_1, u32 param_2, RwV3d* param_3, f32* param_4, f32* param_5, u32 param_6);
u32 func_002f8ea0(BtlUnit* unit, RwV3d* param_2);
void func_002d1de0(RwV3d* dst, const RwV3d* from, const RwV3d* to);
void func_002d4800(RwV3d* param_1);
void func_002d48c0(RwV3d* param_1, const RwV3d* param_2, const RwV3d* param_3, f32 param_4);
void func_00288110(BtlUnit* unit);
void func_002831c0(BtlUnit* unit, s32 param_2);
s16 func_002838d0(BtlUnit* unit, u16 id, f32 scale);
s16 func_00283510(BtlUnit* unit, s32 id);
const BtlUnitAnimBounds* func_00288da0(BtlUnit* unit, s32 id);
void* func_002bbc00(BtlUnit* unit);
void* func_002bb7d0(void);
void func_002bcde0(BtlUnit* unit, void* param_2);
f32 func_0052ea18(f32 x, f32 z);
void func_004bdde0(RtQuat* dst, const RwV3d* axis, s32 param_3, f32 angle);
f32 effMiscRandFloat(s32 param_1);
Model* func_00316c70(u16 type, u16 id, HCdvd* cdvd, u32 readMode);
void func_0031c1d0(Model* mdl);
void func_001a0590(u16 resTypeId, u32 param_2);
u32 func_002d5cf0(BtlUnit* unit);
void func_00319230(Model* mdl, u32 param_2);
u32 func_0017c0e0(u16 id);
u16 func_003b6180(u16 id, Model* mdl);
void func_002d3e00(BtlUnit* unit, s32 param_2);
void func_00280130(BtlUnit* unit, RwV3d* param_2);
void func_00280200(BtlUnit* unit, const s16* param_2, RwV3d* param_3);
void func_002802d0(BtlUnit* unit, BtlUnit* target, RwV3d* param_3);
void func_00280390(BtlUnit* unit, BtlUnit* target, RwV3d* param_3);
void func_00280480(BtlUnit* unit, BtlUnit* target, RwV3d* param_3);
void func_00280580(BtlUnit* unit, RwV3d* param_2);
void func_002806d0(BtlUnit* unit, RwV3d* param_2);
void func_002807a0(BtlUnit* unit, RwV3d* param_2);
void func_00280da0(BtlUnit* unit);
f32 func_002812d0(BtlUnit* unit, BtlUnit* target, s32 id);
void func_002826d0(BtlUnit* unit);
void func_00282bc0(BtlUnit* unit);
s16 func_002f9560(BtlUnit* unit, u16* flags);
s16 func_002835e0(BtlUnit* unit, s16 id, f32 scale);
s16 func_002838d0(BtlUnit* unit, u16 id, f32 scale);
u16 func_002ffbc0(u32 max);
f32 func_002fc5d0(BtlUnit* unit, BtlUnit* target, s32 id);
s32 func_00318ed0(Model* mdl, s32 param_2, RwV3d* pos);
u32 func_00281f20(void* work);
BtlPacket* func_00282130(BtlUnit* unit, u16 blendFrameCount);
u32 func_00318620(Model* mdl, u16 slotIdx, s16 id);
u32 func_003186e0(Model* mdl, u16 slotIdx, s16 id);
u32 func_0017d800(void);
s16 btlUnit00282c30(BtlUnit* unit);
u32 btlUnit00282c60(BtlUnit* unit);
u32 btlUnit00282cd0(BtlUnit* unit);
void btlUnit00283c00(BtlUnit* unit, s32 param_2);

// 12 bytes
typedef struct BtlUnitPacketResNullifiedAnim
{
    BtlUnit* unit; // 0x00
    f32 unk_4;     // 0x04
    u32 counter;   // 0x08
} BtlUnitPacketResNullifiedAnim;

void btlUnitInitResNullifiedAnimPacket(void* work);
u32 btlUnitUpdateResNullifiedAnimPacket(void* work);
void btlUnitDestroyResNullifiedAnimPacket(void* work);

// 24 bytes
typedef struct BtlUnitPacket00284900
{
    RwV3d pos;     // 0x00
    BtlUnit* unit; // 0x0c
    u16 unk_10;    // 0x10
    u16 unk_12;    // 0x12
    f32 phase;     // 0x14
} BtlUnitPacket00284900;

void btlUnitInit00284900Packet(void* work);
u32 btlUnitUpdate00284900Packet(void* work);
void btlUnitDestroy00284900Packet(void* work);

// 16 bytes
typedef struct BtlUnitPacketEnmDodgeAnim
{
    BtlUnit* unit; // 0x00
    s32 unk_4;     // 0x04
    f32 phase;     // 0x08
    f32 step;      // 0x0c
} BtlUnitPacketEnmDodgeAnim;

void btlUnitInitEnmDodgeAnimPacket(void* work);
u32 btlUnitUpdateEnmDodgeAnimPacket(void* work);
void btlUnitDestroyEnmDodgeAnimPacket(void* work);

// 4 bytes
typedef struct BtlUnitPacket00284c90
{
    BtlUnit* unit; // 0x00
} BtlUnitPacket00284c90;

void btlUnitInit00284c90Packet(void* work);
u32 btlUnitUpdate00284c90Packet(void* work);
void btlUnitDestroy00284c90Packet(void* work);

// 8 bytes
typedef struct BtlUnitPacket00284d80
{
    BtlUnit* unit; // 0x00
    s16 unk_4;     // 0x04
    u8 unkData[0x02];
} BtlUnitPacket00284d80;

void btlUnitInit00284d80Packet(void* work);
u32 btlUnitUpdate00284d80Packet(void* work);
void btlUnitDestroy00284d80Packet(void* work);

// 16 bytes
typedef struct BtlUnitPacket00284f50
{
    BtlUnit* unit; // 0x00
    u16 unk_4;     // 0x04
    f32 unk_8;     // 0x08
    u16 unk_c;     // 0x0c
} BtlUnitPacket00284f50;

void btlUnitInit00284f50Packet(void* work);
u32 btlUnitUpdate00284f50Packet(void* work);
void btlUnitDestroy00284f50Packet(void* work);

// 16 bytes
typedef struct BtlUnitPacketModel
{
    BtlUnit* unit; // 0x00
    u16 type;      // 0x04. See enum 'ModelType'
    u16 id;        // 0x06
    u16 flags;     // 0x08
    u8 unkData[0x02];
    HCdvd* cdvd;   // 0x0c
} BtlUnitPacketModel;

void btlUnitInitModelPacket(void* work);
u32 btlUnitUpdateModelPacket(void* work);
void btlUnitDestroyModelPacket(void* work);

// 4 bytes
typedef struct BtlUnitPacket002857f0
{
    BtlUnit* unit; // 0x00
} BtlUnitPacket002857f0;

void btlUnitInit002857f0Packet(void* work);
u32 btlUnitUpdate002857f0Packet(void* work);
void btlUnitDestroy002857f0Packet(void* work);

// 20 bytes
typedef struct BtlUnitPacket00285d30
{
    BtlUnit* unit; // 0x00
    u32 startCol;  // 0x04
    u32 targetCol; // 0x08
    s16 unk_c;     // 0x0c
    s16 unk_e;     // 0x0e
    u8 mode;       // 0x10
    u8 flags;      // 0x11
    s16 counter;   // 0x12
} BtlUnitPacket00285d30;

void btlUnitInit00285d30Packet(void* work);
u32 btlUnitUpdate00285d30Packet(void* work);
void btlUnitDestroy00285d30Packet(void* work);

// 4 bytes
typedef struct BtlUnitPacketUnitPtr
{
    BtlUnit* unit; // 0x00
} BtlUnitPacketUnitPtr;

void btlUnitInit00285e50Packet(void* work);
u32 btlUnitUpdate00285e50Packet(void* work);
void btlUnitDestroy00285e50Packet(void* work);

void btlUnitInit00285f20Packet(void* work);
u32 btlUnitUpdate00285f20Packet(void* work);
void btlUnitDestroy00285f20Packet(void* work);

void btlUnitInit002860b0Packet(void* work);
u32 btlUnitUpdate00286240Packet(void* work);
void btlUnitInit00286240Packet(void* work);
void btlUnitDestroy00286240Packet(void* work);
u32 btlUnitUpdate002860b0Packet(void* work);
void btlUnitDestroy002860b0Packet(void* work);

void btlUnit002862a0(void* work);
u32 btlUnit002862c0(void* work);
void btlUnit00286300(void* work);
// FUN_00280050
void func_00280050(void* param_1, RwV3d* param_2)
{
    BtlUnit* unit;
    RwV3d scaled;
    RwV3d transformed;

    unit = (BtlUnit*)param_1;
    scaled.x = unit->sphereCenter.x * unit->scale;
    scaled.y = unit->sphereCenter.y * unit->scale;
    scaled.z = unit->sphereCenter.z * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &unit->rot);
    param_2->x = transformed.x + (unit->unk_94 * 25 - 0x6d6);
    param_2->y = transformed.y + unit->pos.y;
    param_2->z = transformed.z + (unit->unk_96 * 25 - 0x6d6);
}

// FUN_00280130
void func_00280130(BtlUnit* unit, RwV3d* param_2)
{
    const BtlUnitAnimBounds* bounds;
    RwV3d scaled;
    RwV3d transformed;
    f32 centerY;
    f32 centerZ;
    f32 centerX;

    bounds = func_00288da0(unit, 0);
    centerY = bounds->centerY;
    centerZ = bounds->centerZ;
    centerX = bounds->centerX;
    scaled.x = centerX * unit->scale;
    scaled.y = centerY * unit->scale;
    scaled.z = centerZ * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &unit->rot);
    param_2->x = transformed.x + unit->pos.x;
    param_2->y = transformed.y + unit->pos.y;
    param_2->z = transformed.z + unit->pos.z;
}

// FUN_00280200
void func_00280200(BtlUnit* unit, const s16* param_2, RwV3d* param_3)
{
    RwV3d scaled;
    RwV3d transformed;
    f32 y;
    f32 z;
    f32 x;

    y = param_2[1];
    z = param_2[2];
    x = param_2[0];
    scaled.x = x * unit->scale;
    scaled.y = y * unit->scale;
    scaled.z = z * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &unit->rot);
    param_3->x = transformed.x + unit->pos.x;
    param_3->y = transformed.y + unit->pos.y;
    param_3->z = transformed.z + unit->pos.z;
}

// FUN_002802D0
void func_002802d0(BtlUnit* unit, BtlUnit* target, RwV3d* param_3)
{
    RtQuat rotation;
    RwV3d scaled;
    RwV3d transformed;

    func_002d1de0((RwV3d*)&rotation, &unit->pos, &target->pos);
    scaled.x = unit->sphereCenter.x * unit->scale;
    scaled.y = unit->sphereCenter.y * unit->scale;
    scaled.z = unit->sphereCenter.z * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &rotation);
    param_3->x = transformed.x + unit->pos.x;
    param_3->y = transformed.y + unit->pos.y;
    param_3->z = transformed.z + unit->pos.z;
}

// FUN_00280390
void func_00280390(BtlUnit* unit, BtlUnit* target, RwV3d* param_3)
{
    const BtlUnitAnimBounds* bounds;
    RtQuat rotation;
    RwV3d scaled;
    RwV3d transformed;
    f32 centerY;
    f32 centerZ;
    f32 centerX;

    func_002d1de0((RwV3d*)&rotation, &unit->pos, &target->pos);
    bounds = func_00288da0(unit, 9);
    centerY = bounds->centerY;
    centerZ = bounds->centerZ;
    centerX = bounds->centerX;
    scaled.x = centerX * unit->scale;
    scaled.y = centerY * unit->scale;
    scaled.z = centerZ * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &rotation);
    param_3->x = transformed.x + unit->pos.x;
    param_3->y = transformed.y + unit->pos.y;
    param_3->z = transformed.z + unit->pos.z;
}

// FUN_00280480
void func_00280480(BtlUnit* unit, BtlUnit* target, RwV3d* param_3)
{
    RtQuat rotation;
    RwV3d scaled;
    RwV3d transformed;

    func_002d1de0((RwV3d*)&rotation, &unit->pos, &target->pos);
    scaled.x = unit->sphereCenter.x * unit->scale;
    scaled.y = unit->sphereCenter.y * unit->scale;
    scaled.z = unit->sphereCenter.z * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &rotation);
    param_3->x = transformed.x + (unit->unk_94 * 25 - 0x6d6);
    param_3->y = transformed.y + unit->pos.y;
    param_3->z = transformed.z + (unit->unk_96 * 25 - 0x6d6);
}

// FUN_00280580
void func_00280580(BtlUnit* unit, RwV3d* param_2)
{
    RwV3d inactiveScaled;
    RwV3d inactiveTransformed;
    RwV3d scaled;
    RwV3d transformed;

    if ((unit->flags2 & BTLUNIT_FLAG2_UPDATE) == 0)
    {
        inactiveScaled.x = unit->sphereCenter.x * unit->scale;
        inactiveScaled.y = unit->sphereCenter.y * unit->scale;
        inactiveScaled.z = unit->sphereCenter.z * unit->scale;
        RtQuatTransformVectors(&inactiveTransformed, &inactiveScaled, 1, &unit->rot);
        param_2->x = inactiveTransformed.x + unit->pos.x;
        param_2->y = inactiveTransformed.y + unit->pos.y;
        param_2->z = inactiveTransformed.z + unit->pos.z;
        return;
    }

    if (func_00318ed0(unit->mdl, 0, param_2) != 0)
    {
        return;
    }

    scaled.x = unit->sphereCenter.x * unit->scale;
    scaled.y = unit->sphereCenter.y * unit->scale;
    scaled.z = unit->sphereCenter.z * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &unit->rot);
    param_2->x = transformed.x + unit->pos.x;
    param_2->y = transformed.y + unit->pos.y;
    param_2->z = transformed.z + unit->pos.z;
}

// FUN_002806D0
void func_002806d0(BtlUnit* unit, RwV3d* param_2)
{
    RwV3d scaled;
    RwV3d transformed;

    scaled.x = unit->sphereCenter.x * unit->scale;
    scaled.y = unit->sphereCenter.y * unit->scale;
    scaled.z = unit->sphereCenter.z * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &unit->rot);
    param_2->x = transformed.x + unit->pos.x;
    param_2->y = transformed.y + unit->pos.y;
    param_2->z = transformed.z + unit->pos.z;
    param_2->y += unit->unk_8c * unit->scale * DAT_007cb0cc;
}

// FUN_002807A0
void func_002807a0(BtlUnit* unit, RwV3d* param_2)
{
    RwV3d scaled;
    RwV3d transformed;

    scaled.x = unit->sphereCenter.x * unit->scale;
    scaled.y = unit->sphereCenter.y * unit->scale;
    scaled.z = unit->sphereCenter.z * unit->scale;
    RtQuatTransformVectors(&transformed, &scaled, 1, &unit->rot);
    param_2->x = transformed.x + unit->pos.x;
    param_2->y = transformed.y + unit->pos.y;
    param_2->z = transformed.z + unit->pos.z;
    param_2->y += unit->unk_8c * unit->scale * 0.25f;
}

// FUN_00280870 NONMATCHING
f32 func_00280870(u32 param_1, u32 param_2, RwV3d* param_3,
                  f32* param_4, f32* param_5, u32 param_6)
{
    BtlUnit* unit;
    BtlUnit* lastUnit;
    RwV3d scaled;
    RwV3d transformed;
    RwV3d center;
    RwV3d delta;
    f32 sumX;
    f32 sumY;
    f32 sumZ;
    f32 maxY;
    f32 minY;
    f32 radius;
    f32 extent;
    u32 count;
    u32 genus;

    sumX = 0.0f;
    sumY = 0.0f;
    sumZ = 0.0f;
    maxY = 0.0f;
    minY = 100000000.0f;
    count = 0;
    lastUnit = NULL;

    for (genus = 0; genus < UNIT_GENUS_MAX; genus++)
    {
        if ((param_1 & (1u << genus)) == 0)
        {
            continue;
        }

        for (unit = gBtl->unitLists[genus].head; unit != NULL; unit = unit->next)
        {
            f32 top;

            if ((unit->flags3 & BTLUNIT_FLAG3_UNK08) == 0 ||
                (unit->flags3 & param_2) != 0)
            {
                continue;
            }

            if ((param_6 & 1) == 0)
            {
                scaled.x = unit->sphereCenter.x * unit->scale;
                scaled.y = unit->sphereCenter.y * unit->scale;
                scaled.z = unit->sphereCenter.z * unit->scale;
                RtQuatTransformVectors(&transformed, &scaled, 1, &unit->rot);
                center.x = transformed.x + unit->pos.x;
                center.y = transformed.y + unit->pos.y;
                center.z = transformed.z + unit->pos.z;
            }
            else
            {
                center.x = unit->unk_94 * 25 - 0x6d6;
                center.y = unit->sphereCenter.y * unit->scale + unit->pos.y;
                center.z = unit->unk_96 * 25 - 0x6d6;
            }

            sumX += center.x;
            sumY += center.y;
            sumZ += center.z;
            top = center.y + unit->unk_8c * unit->scale * 0.5f;
            if (top > maxY)
            {
                maxY = top;
            }
            if (top < minY)
            {
                minY = top;
            }
            count++;
            lastUnit = unit;
        }
    }

    if (count == 0)
    {
        return 0.0f;
    }

    if (count == 1)
    {
        center.x = sumX;
        center.y = sumY;
        center.z = sumZ;
        extent = lastUnit->unk_8c * lastUnit->scale * 0.5f;
        radius = lastUnit->sphereRadius * lastUnit->scale;
        if (radius < extent)
        {
            radius = extent;
        }
    }
    else
    {
        f32 invCount;

        invCount = 1.0f / count;
        center.x = sumX * invCount;
        center.y = sumY * invCount;
        center.z = sumZ * invCount;
        radius = 0.0f;

        for (genus = 0; genus < UNIT_GENUS_MAX; genus++)
        {
            if ((param_1 & (1u << genus)) == 0)
            {
                continue;
            }

            for (unit = gBtl->unitLists[genus].head; unit != NULL; unit = unit->next)
            {
                if ((unit->flags3 & BTLUNIT_FLAG3_UNK08) == 0 ||
                    (unit->flags3 & param_2) != 0)
                {
                    continue;
                }

                if ((param_6 & 1) == 0)
                {
                    scaled.x = unit->sphereCenter.x * unit->scale;
                    scaled.y = unit->sphereCenter.y * unit->scale;
                    scaled.z = unit->sphereCenter.z * unit->scale;
                    RtQuatTransformVectors(&transformed, &scaled, 1, &unit->rot);
                    delta.x = transformed.x + unit->pos.x - center.x;
                    delta.z = transformed.z + unit->pos.z - center.z;
                }
                else
                {
                    delta.x = (unit->unk_94 * 25 - 0x6d6) - center.x;
                    delta.z = (unit->unk_96 * 25 - 0x6d6) - center.z;
                }
                delta.y = 0.0f;
                extent = RwV3dLength(&delta) + unit->sphereRadius * unit->scale;
                if (extent > radius)
                {
                    radius = extent;
                }
            }
        }
    }

    if (param_3 != NULL)
    {
        *param_3 = center;
    }
    if (param_4 != NULL)
    {
        *param_4 = maxY;
    }
    if (param_5 != NULL)
    {
        *param_5 = minY;
    }
    return radius;
}

// FUN_00280DA0 NONMATCHING
void func_00280da0(BtlUnit* unit)
{
    f32* path;
    RwV2d start;
    RwV2d segment;
    RwV2d toLast;
    RwV3d forward;
    RtQuat targetRot;
    u16 pointCount;
    u16 pointIndex;
    f32 remaining;
    f32 segmentLength;
    f32 lastLength;
    f32 distanceToTarget;
    f32 angle;
    f32 currentAngle;
    f32 angleDelta;
    f32 angleMagnitude;

    path = (f32*)((u8*)unit + 0xf4);
    pointCount = unit->unk_4ec;
    pointIndex = *(u16*)((u8*)unit + 0x4ee);
    remaining = unit->unk_cc;
    segmentLength = 0.0f;

    if ((unit->movementFlags & BTLUNIT_MOVEMENTFLAGS_MOVE) != 0 &&
        (unit->movementFlags & 0x10) != 0)
    {
        start.x = unit->pos.x;
        start.y = unit->pos.z;

        while (pointIndex < pointCount - 1)
        {
            remaining -= segmentLength;
            segment.x = path[pointIndex * 2] - start.x;
            segment.y = path[pointIndex * 2 + 1] - start.y;
            segmentLength = RwV2dNormalize(&segment, &segment);
            if (remaining <= segmentLength)
            {
                break;
            }
            start.x = path[pointIndex * 2];
            start.y = path[pointIndex * 2 + 1];
            pointIndex++;
        }

        if ((unit->unk_c4 & 1) != 0)
        {
            pointIndex = pointCount - 1;
        }

        if (pointIndex < pointCount - 1)
        {
            f32 step;

            step = remaining;
            unit->pos.x = start.x + segment.x * step;
            unit->pos.z = start.y + segment.y * step;
            toLast.x = start.x - path[(pointCount - 1) * 2];
            toLast.y = start.y - path[(pointCount - 1) * 2 + 1];
            lastLength = RwV2dLength(&toLast);
            if (lastLength < unit->unk_e8)
            {
                step = (lastLength + remaining) - unit->unk_e8;
                unit->pos.x = start.x + segment.x * step;
                unit->pos.z = start.y + segment.y * step;
                unit->movementFlags &= (u16)~BTLUNIT_MOVEMENTFLAGS_MOVE;
                unit->movementFlags &= (u16)~0x10;
            }
            unit->targetRot.x = unit->pos.x + segment.x;
            unit->targetRot.y = unit->pos.y;
            unit->targetRot.z = unit->pos.z + segment.y;
        }
        else
        {
            unit->pos.x = path[pointIndex * 2];
            unit->pos.z = path[pointIndex * 2 + 1];
            unit->movementFlags &= (u16)~BTLUNIT_MOVEMENTFLAGS_MOVE;
            unit->movementFlags &= (u16)~0x10;
            unit->targetRot.x = unit->pos.x;
            unit->targetRot.y = unit->pos.y;
            unit->targetRot.z = unit->pos.z;
        }

        unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
        *(u16*)((u8*)unit + 0x4ee) = pointIndex;
        unit->movementFlags |= BTLUNIT_MOVEMENTFLAGS_ROTATE;
    }

    if ((unit->movementFlags & BTLUNIT_MOVEMENTFLAGS_ROTATE) == 0)
    {
        return;
    }

    forward.x = unit->targetRot.x - unit->pos.x;
    forward.y = unit->targetRot.z - unit->pos.z;
    if ((forward.x == 0.0f && forward.y == 0.0f) ||
        (unit->flags3 & BTLUNIT_FLAG3_NOROT) != 0)
    {
        unit->movementFlags &= (u16)~BTLUNIT_MOVEMENTFLAGS_ROTATE;
        return;
    }

    angle = func_0052ea18(forward.x, forward.y) * 57.295776f;
    RtQuatTransformVectors(&forward, &D_00697890, 1, &unit->rot);
    currentAngle = func_0052ea18(forward.x, unit->targetRot.z - unit->pos.z) * 57.295776f;
    angleDelta = angle - currentAngle;
    angleMagnitude = angleDelta;
    if (angleMagnitude < 0.0f)
    {
        angleMagnitude = -angleMagnitude;
    }

    if (angleMagnitude <= 5.0f || (unit->unk_c4 & 2) != 0)
    {
        func_004bdde0(&targetRot, &D_00697880, 0, angle);
        unit->rot = targetRot;
        unit->movementFlags &= (u16)~BTLUNIT_MOVEMENTFLAGS_ROTATE;
    }
    else
    {
        if (angleMagnitude > 180.0f)
        {
            if (angleDelta > 0.0f)
            {
                angleDelta -= 360.0f;
            }
            else
            {
                angleDelta += 360.0f;
            }
        }
        if (unit->unk_4f4 != 0.0f)
        {
            func_004bdde0((RtQuat*)&unit->rot, &D_00697880, 2,
                          angleDelta / unit->unk_4f4);
        }
    }
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}

// FUN_002812D0
f32 func_002812d0(BtlUnit* unit, BtlUnit* target, s32 id)
{
    const BtlUnitAnimInfo* animInfo;
    s16 animId;
    f32 offset;
    f32 targetOffset;

    animId = func_00283510(unit, id);
    if (animId < unit->unk_9d8)
    {
        animInfo = (const BtlUnitAnimInfo*)unit->unk_9ec;
        offset = unit->scale * animInfo[animId].unk_6;
        targetOffset = func_002fc5d0(unit, target, id);
        if (targetOffset >= 0.0f)
        {
            offset += targetOffset;
        }
        else
        {
            offset += target->sphereRadius * target->scale;
        }
        offset += unit->sphereCenter.z * unit->scale;
    }
    else
    {
        offset = 0.0f;
    }

    return offset;
}

// FUN_002826D0 NONMATCHING
void func_002826d0(BtlUnit* unit)
{
    Model* mdl;
    s16 current;
    s16 reported;
    s16 blend;
    s16 animId;
    u32 animIndex;

    if ((unit->flags2 & BTLUNIT_FLAG2_UPDATE) == 0)
    {
        return;
    }

    mdl = unit->mdl;
    if ((unit->unk_9cc & 2) != 0)
    {
        mdlAnimSetSpeed(mdl, 0, 0.0f);
        return;
    }

    if ((unit->unk_9cc & 4) != 0 &&
        btlUnitGetAnimFrame(unit) >= unit->unk_9da && unit->unk_9dc > 0)
    {
        mdlAnimSetSpeed(mdl, 0, 0.0f);
        unit->unk_9dc--;
        return;
    }

    mdlAnimSetSpeed(mdl, 0, unit->unk_9d4);
    if ((unit->unk_9cc & 8) == 0)
    {
        if ((unit->movementFlags & BTLUNIT_MOVEMENTFLAGS_MOVE) != 0 &&
            (unit->movementFlags & 4) == 0)
        {
            if (!btlUnit00282cd0(unit))
            {
                btlUnitAnimate(unit, 1, 4,
                               (unit->unk_c4 & 4) != 0 ? 2.0f : 1.0f, 1);
            }
        }
        else if (btlUnit00282cd0(unit) && !btlUnit00282c60(unit))
        {
            btlUnitAnimate(unit, unit->unk_9e0, 6, unit->unk_9e4, unit->unk_9e8);
        }
    }

    switch (unit->unk_9d0)
    {
    case 0:
        if (mdl->animSlots[0].anim.isAnimEnd == 1)
        {
            current = unit->unk_9e0;
            reported = btlUnit00282c30(unit);
            if (current != reported)
            {
                blend = func_002f9560(unit, &unit->unk_9cc);
                if (blend == -1 && unit->unk_9e2 < 1)
                {
                    if (current == 0x11 || current == 0xd || current == 3)
                    {
                        animId = func_00283510(unit, current);
                        animIndex = (u32)(u16)animId;
                        if (animIndex < unit->unk_9d8)
                        {
                            blend = ((const BtlUnitAnimInfo*)unit->unk_9ec)[animIndex].unk_8;
                        }
                        else
                        {
                            blend = 6;
                        }
                    }
                    else
                    {
                        blend = 0;
                    }
                }
                else if (blend == -1)
                {
                    blend = unit->unk_9e2;
                }
                btlUnitAnimate(unit, current, blend, unit->unk_9e4, unit->unk_9e8);
            }
        }
        break;

    case 3:
        if (mdl->animSlots[0].anim.blendFactor >= 1.0f)
        {
            mdlAnimSetSpeed(mdl, 0, 0.0f);
        }
        break;

    case 4:
        if (mdl->animSlots[0].anim.isAnimEnd == 1 && btlUnit00282c30(unit) != 0xd)
        {
            btlUnitAnimate(unit, 0xd, 0, 1.0f, 1);
        }
        break;

    case 5:
        if (mdl->animSlots[0].anim.isAnimEnd == 1 && btlUnit00282c30(unit) != 0xf)
        {
            btlUnitAnimate(unit, 0xf, 0, 1.0f, 2);
        }
        break;

    case 6:
        if (mdl->animSlots[0].anim.isAnimEnd == 1 && btlUnit00282c30(unit) != 0x18)
        {
            btlUnitAnimate(unit, 0x18, 0, 1.0f, 2);
        }
        break;

    case 7:
        if (mdl->animSlots[0].anim.isAnimEnd == 1 && btlUnit00282c30(unit) != 0x19)
        {
            btlUnitAnimate(unit, 0x19, 0, 1.0f, 2);
        }
        break;
    }

    unit->unk_9cc &= (u16)~8;
}

// FUN_00282BC0
void func_00282bc0(BtlUnit* unit)
{
    s16 animation;

    animation = (s16)func_002838d0(
        unit, (u16)(s32)btlUnit00282c30(unit), 1.0f);
    animation = (s16)func_002ffbc0(animation);
    btlUnit00283c00(unit, animation);
}
// FUN_00281F20 NONMATCHING
u32 func_00281f20(void* workData)
{
    BtlUnitPacketBackstep* work;
    BtlUnit* unit;
    RwV3d transformed;
    f32 phase;
    f32 factor;
    f32 step;
    u16 blendFrameCount;

    work = (BtlUnitPacketBackstep*)workData;
    unit = work->unit;
    if (work->counter == 0)
    {
        work->phase = 0.6f;
        work->origin = unit->pos;
        RtQuatTransformVectors(&transformed, &D_006978A0, 1, &unit->rot);
        work->displacement.x = transformed.x * 400.0f;
        work->displacement.y = transformed.y * 400.0f;
        work->displacement.z = transformed.z * 400.0f;
    }

    blendFrameCount = (u16)work->blendFrameCount;
    if (blendFrameCount == 0)
    {
        step = 1.0f;
    }
    else
    {
        step = 1.0f / ((f32)blendFrameCount * 2.0f);
    }
    work->phase += step;
    phase = work->phase;
    factor = ((phase * 4.0f + phase * (-2.0f * phase) - 1.0f) - 0.5f) * 2.0f;
    if (factor < 1.0f)
    {
        transformed.x = work->displacement.x * factor;
        transformed.y = work->displacement.y * factor;
        transformed.z = work->displacement.z * factor;
    }
    else
    {
        transformed = work->displacement;
    }

    unit->pos.x = work->origin.x + transformed.x;
    unit->pos.y = work->origin.y + transformed.y;
    unit->pos.z = work->origin.z + transformed.z;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    work->counter++;
    return factor >= 1.0f;
}

// FUN_00282130
BtlPacket* func_00282130(BtlUnit* unit, u16 blendFrameCount)
{
    BtlPacket* packet;
    BtlUnitPacketBackstep* work;

    packet = btlPacketCreate(BTLPACKET_MAKE_ID(BTLPACKET_MODULE_UNIT, 12),
                             sizeof(BtlUnitPacketBackstep));
    packet->updateFunc = func_00281f20;
    work = (BtlUnitPacketBackstep*)packet->workData;
    work->unit = unit;
    work->blendFrameCount = (s16)blendFrameCount;
    work->counter = 0;
    return packet;
}

// FUN_002831C0 NONMATCHING
void func_002831c0(BtlUnit* unit, s32 blendFrameCount)
{
    u32 canUseLowHp;
    s16 animation;
    s16 nextAnimation;
    s16 mode;
    f32 speed;
    u16 blend;

    nextAnimation = 0;
    canUseLowHp = 0;
    if (datCalcIsLowHp(unit->datUnit) != 0 && (unit->flags2 & BTLUNIT_FLAG2_UPDATE) != 0)
    {
        animation = func_00283510(unit, 0x11);
        if (func_00318620(unit->mdl, 0, animation) != 0 &&
            func_003186e0(unit->mdl, 0, animation) != 1)
        {
            canUseLowHp = 1;
        }
    }
    if (canUseLowHp)
    {
        nextAnimation = 0x11;
    }
    if (datCalcChkBadStatus(unit->datUnit, 0xffeff) != 0)
    {
        nextAnimation = 3;
    }
    if (datCalcChkBadStatus(unit->datUnit, UNIT_BADSTATUS_DOWN) != 0)
    {
        nextAnimation = 9;
    }
    if (datCalcIsDead(unit->datUnit, 0) != 0 &&
        (unit->flags3 & BTLUNIT_FLAG3_UNK40) != 0 &&
        (unit->flags2 & BTLUNIT_FLAG2_UPDATE) != 0)
    {
        animation = func_00283510(unit, 0x12);
        if (func_00318620(unit->mdl, 0, animation) != 0 &&
            func_003186e0(unit->mdl, 0, animation) != 1)
        {
            nextAnimation = 0x12;
        }
    }

    if (nextAnimation == 0x12)
    {
        mode = 2;
        blend = 0;
    }
    else
    {
        mode = 1;
        blend = (u16)unit->unk_9e2;
    }

    switch (datCalcGetBadStatusNoDown(unit->datUnit))
    {
    case 0x100:
        speed = func_0017d800() == 0 ? 3.0f : 2.0f;
        break;
    case 0x20:
        speed = 0.5f;
        break;
    default:
        speed = 1.0f;
        break;
    }

    if (btlUnit00282c60(unit) && unit->unk_9e0 != nextAnimation)
    {
        btlUnitAnimate(unit, nextAnimation, blend, speed, mode);
    }
    unit->unk_9e0 = nextAnimation;
    unit->unk_9e2 = blend;
    unit->unk_9e4 = speed;
    unit->unk_9e8 = (s8)mode;

    (void)blendFrameCount;
}
// FUN_0027F530
void func_0027f530(BtlUnit* unit)
{
    unit->scale = 1.0f;
    unit->pos = D_00957180;
    unit->posOffset = D_00957180;

    unit->rot.real = 1.0f;
    unit->rot.imag.x = 0.0f;
    unit->rot.imag.y = 0.0f;
    unit->rot.imag.z = 0.0f;

    unit->cols[0].r = 0xff;
    unit->cols[0].g = 0xff;
    unit->cols[0].b = 0xff;
    unit->cols[0].a = 0xff;
    unit->cols[1] = unit->cols[0];
    unit->cols[3] = unit->cols[0];
    unit->cols[4] = unit->cols[0];

    unit->unk_4c = 0;
    unit->unk_54 = D_00957180;
    unit->unk_70.imag.x = 0.0f;
    unit->unk_70.imag.y = 0.0f;
    unit->unk_70.imag.z = 0.0f;
    unit->unk_70.real = 0.5f;
}

// FUN_0027f650
void btlUnitSetPos(BtlUnit* unit, const RwV3d* pos)
{
    unit->pos = *pos;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}

// FUN_0027f680
void btlUnitSetRot(BtlUnit* unit, const RtQuat* rot)
{
    if (!(unit->flags3 & BTLUNIT_FLAG3_NOROT))
    {
        unit->rot = *rot;
        unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    }
}

// FUN_0027f6d0
void btlUnitSetRotFromMat(BtlUnit* unit, const RwMatrix* mat)
{
    RtQuatConvertFromMatrix(&unit->rot, mat);
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}

// FUN_0027f710
void btlUnitSetScale(BtlUnit* unit, f32 scale)
{
    unit->scale = scale;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}

// FUN_0027f730
void btlUnitSetColor(BtlUnit* unit, RwRGBA col)
{
    unit->cols[BTLUNIT_COL_MAIN] = col;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}

// FUN_0027f770
void btlUnitSetFlags(BtlUnit* unit, u16 flags)
{
    unit->flags |= flags;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}

// FUN_0027f790
void btlUnitClearFlags(BtlUnit* unit, u16 flags)
{
    unit->flags &= ~flags;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
}

// FUN_0027f7c0
void btlUnit0027f7c0(BtlUnit* unit, RwV3d* param_2, RwV3d* parm_3, RwV3d* param_4)
{
    RwV3d base;
    RwV3d target;

    base.x = unit->unk_94 * 25 - 0x6d6;
    base.y = unit->pos.y;
    base.z = unit->unk_96 * 25 - 0x6d6;

    if (param_2 != NULL)
    {
        *param_2 = base;
    }

    if (param_4 != NULL || parm_3 != NULL)
    {
        switch (unit->genus)
        {
        case UNIT_GENUS_PC:
            func_00280870(2, 1, &target, 0, 0, 1);
            break;

        case UNIT_GENUS_EC:
            if (func_002f8ea0(unit, &target) != 1)
            {
                func_00280050(gBtl->actionList.head->unit, &target);
            }
            break;
        }

        if (param_4 != NULL)
        {
            *param_4 = target;
        }

        if (parm_3 != NULL)
        {
            func_002d1de0(parm_3, &base, &target);
        }
    }
}

// FUN_0027f930
s32 btlUnit0027f930(s32 param_1)
{
    return param_1 + 0x4e;
}
// FUN_0027f940 NONMATCHING
void func_0027f940(BtlUnit* unit, BtlUnit* source, BtlUnit* target,
                   u16 tableIndex, RwV3d* position, void* rotationOut, u8 mode)
{
    u8* table;
    u8* entry;
    u16 charId;
    f32 distance;
    f32 scale;
    RwV3d origin;
    RwV3d firstOffset;
    RwV3d secondOffset;
    RwV3d transformed;
    RwV3d positionValue;
    RwV3d center;
    RtQuat rotation;

    table = DAT_007ce42c;
    charId = unit->charId;

    if (mode == 2)
    {
        func_002802d0(target, source, &origin);
        distance = func_002812d0(unit, target, tableIndex);
        rotation.real = 0.0f;
        func_002d1de0((RwV3d*)&rotation, &source->pos, &origin);
        RtQuatTransformVectors(&firstOffset, &D_006978A0, 1, &rotation);

        entry = table + ((charId * 11) * 8);
        scale = (f32)*(s16*)(entry + 0x0c) * unit->scale;
        RtQuatTransformVectors(&secondOffset, &D_00697870, 1, &rotation);

        positionValue.x = origin.x + firstOffset.x * (distance + 50.0f) + secondOffset.x * scale;
        positionValue.y = 0.0f;
        positionValue.z = origin.z + firstOffset.z * (distance + 50.0f) + secondOffset.z * scale;
        if (position != NULL)
        {
            *position = positionValue;
        }
        if (rotationOut != NULL)
        {
            func_002d1de0((RwV3d*)rotationOut, &positionValue, &origin);
        }
    }
    else
    {
        if (rotationOut != NULL)
        {
            *(RtQuat*)rotationOut = source->rot;
        }
        if (position != NULL)
        {
            btlUnitGetSphereWorldCenter(source, &center);
            center.y -= source->unk_8c * source->scale * 0.5f;
            entry = table + ((charId * 11) * 8) + mode * 6;
            secondOffset.x = (f32)*(s16*)(entry + 0x0c) * unit->scale;
            secondOffset.y = (f32)*(s16*)(entry + 0x0e) * unit->scale;
            secondOffset.z = (f32)*(s16*)(entry + 0x10) * unit->scale;
            RtQuatTransformVectors(&transformed, &secondOffset, 1, &source->rot);
            position->x = transformed.x + center.x;
            position->y = transformed.y + center.y;
            position->z = transformed.z + center.z;
        }
    }
}

// FUN_0027FC80
#pragma optimization_level 1
#pragma tailcall on
u32 func_0027fc80(BtlUnit* unit)
{
    BtlUnit* source;
    u32 charId;
    u8* table;
    u8* entry;
    uintptr_t address;

    source = unit;
    if (unit->genus != UNIT_GENUS_PS)
    {
        return 0xffffffff;
    }
    charId = source->charId;
    if (charId == 0xcf)
    {
        return 0xffffffff;
    }

    table = DAT_007ce42c;
    address = charId * 0x58;
    address += (uintptr_t)table;
    entry = (u8*)address;
    return ((u32)entry[0x56] << 24) | 0xffffff;
}
#pragma tailcall off
#pragma optimization_level 2

// FUN_0027FCF0
void func_0027fcf0(BtlUnit* unit, const RwV3d* target)
{
    RtQuat rotation;

    func_002d1de0((RwV3d*)&rotation, &unit->pos, target);
    if ((unit->flags3 & BTLUNIT_FLAG3_NOROT) == 0)
    {
        unit->rot = rotation;
        unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    }
    func_00288110(unit);
}


// FUN_0027fd70
void btlUnitInitPosRotColPacket(void* work)
{
    BtlUnitPacketPosRotCol* packet;

    packet = (BtlUnitPacketPosRotCol*)work;

    packet->unit->packetCount++;
}

// FUN_0027fd90
u32 btlUnitUpdatePosRotColPacket(void* work)
{
    BtlUnitPacketPosRotCol* packet;
    BtlUnit* unit;

    packet = (BtlUnitPacketPosRotCol*)work;

    if (packet->flags & BTLUNIT_POSROTCOL_FLAG_SETPOS)
    {
        unit = packet->unit;

        unit->pos = packet->pos;
        unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    }

    if (packet->flags & BTLUNIT_POSROTCOL_FLAG_SETROT && 
        !(packet->unit->flags3 & BTLUNIT_FLAG3_NOROT))
    {
        unit = packet->unit;

        unit->rot = packet->rot;
        unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    }

    if (packet->flags & BTLUNIT_POSROTCOL_FLAG_SETCOL)
    {
        BtlUnit* colUnit;

        colUnit = packet->unit;

        colUnit->cols[BTLUNIT_COL_MAIN] = packet->col;
        colUnit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    }

    return 1;
}

// FUN_0027fe70
void btlUnitDestroyPosRotColPacket(void* work)
{
    BtlUnitPacketPosRotCol* packet;

    packet = (BtlUnitPacketPosRotCol*)work;

    packet->unit->packetCount--;
}

// FUN_0027fe90
BtlPacket* btlUnitCreatePosRotColPacket(BtlUnit* unit, const RwV3d* pos, const RtQuat* rot, const RwRGBA* col)
{
    BtlPacket* packet;
    BtlUnitPacketPosRotCol* work;

    packet = btlPacketCreate(BTLUNIT_PACKET_POSROTCOL, sizeof(BtlUnitPacketPosRotCol));

    packet->initFunc = btlUnitInitPosRotColPacket;
    packet->updateFunc = btlUnitUpdatePosRotColPacket;
    packet->destroyFunc = btlUnitDestroyPosRotColPacket;

    work = (BtlUnitPacketPosRotCol*)packet->workData;

    work->unit = unit;
    work->flags = 0;

    if (pos != NULL)
    {
        work->pos = *pos;
        work->flags |= BTLUNIT_POSROTCOL_FLAG_SETPOS;
    }

    if (rot != NULL)
    {
        work->rot = *rot;
        work->flags |= BTLUNIT_POSROTCOL_FLAG_SETROT;
    }

    if (col != NULL)
    {
        work->col = *col;
        work->flags |= BTLUNIT_POSROTCOL_FLAG_SETCOL;
    }

    return packet;
}

// FUN_0027ffb0
void btlUnitGetSphereWorldCenter(BtlUnit* unit, RwV3d* dst)
{
    RwV3d scaledCenter;
    RwV3d rotatedCenter;

    scaledCenter.x = unit->sphereCenter.x * unit->scale;
    scaledCenter.y = unit->sphereCenter.y * unit->scale;
    scaledCenter.z = unit->sphereCenter.z * unit->scale;

    RtQuatTransformVectors(&rotatedCenter, &scaledCenter, 1, &unit->rot);

    dst->x = rotatedCenter.x + unit->pos.x;
    dst->y = rotatedCenter.y + unit->pos.y;
    dst->z = rotatedCenter.z + unit->pos.z;
}

// FUN_00281270
u32 btlUnitIsMoving(BtlUnit* unit)
{
    return (unit->movementFlags & BTLUNIT_MOVEMENTFLAGS_MOVE) != 0;
}

// FUN_00281290
void btlUnitStopMoving(BtlUnit* unit)
{
    unit->movementFlags &= ~BTLUNIT_MOVEMENTFLAGS_MOVE;
}

// FUN_002812b0
void btlUnitStopRotating(BtlUnit* unit)
{
    unit->movementFlags &= ~BTLUNIT_MOVEMENTFLAGS_ROTATE;
}

// FUN_002813d0
void btlUnitInitMovePacket(void* work)
{
    BtlUnitPacketMove* packet;

    packet = (BtlUnitPacketMove*)work;

    packet->unit->packetCount++;
}

// FUN_002813f0 NONMATCHING
u32 btlUnitUpdateMovePacket(void* work)
{
    BtlUnitPacketMove* packet;
    BtlUnit* unit;
    RwV3d direction;
    RwV3d target;
    RwV3d start;
    RwV3d end;

    packet = (BtlUnitPacketMove*)work;
    unit = packet->unit;

    if (packet->flags & 8)
    {
        switch (packet->state)
        {
        case 0:
            if (packet->flags & 0x10)
            {
                btlUnit0027f7c0(unit, &packet->targetPos, NULL, NULL);
            }
            packet->state++;
            break;

        case 1:
            func_002d4800(&unit->unk_ec);
            unit->unk_e8 = packet->unk_1c;
            unit->unk_c4 = packet->flags;
            unit->unk_cc = 27.0f * packet->speed;

            if (!(packet->flags & 1))
            {
                unit->unk_ec.x = unit->pos.x;
                unit->unk_ec.y = unit->pos.z;
                unit->unk_ec.z = packet->targetPos.x;
                unit->unk_f8 = packet->targetPos.z;
                unit->unk_4ec = 2;
                unit->movementFlags &= ~0x20;
                unit->movementFlags |= BTLUNIT_MOVEMENTFLAGS_MOVE;
                unit->movementFlags |= 0x10;
            }
            else
            {
                target = packet->targetPos;
                if (packet->unk_1c != 0.0f)
                {
                    direction.x = unit->pos.x - packet->targetPos.x;
                    direction.y = 0.0f;
                    direction.z = unit->pos.z - packet->targetPos.z;
                    RwV3dNormalize(&direction, &direction);
                    target.x += direction.x * packet->unk_1c;
                    target.y += direction.y * packet->unk_1c;
                    target.z += direction.z * packet->unk_1c;
                }

                target.y = unit->pos.y;
                unit->pos = target;
                unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
                unit->movementFlags &= ~BTLUNIT_MOVEMENTFLAGS_MOVE;
                unit->movementFlags &= ~0x10;
            }

            unit->unk_dc = packet->targetPos;
            packet->state++;
            break;

        case 2:
            if (!(unit->movementFlags & (BTLUNIT_MOVEMENTFLAGS_MOVE | BTLUNIT_MOVEMENTFLAGS_ROTATE)))
            {
                return 1;
            }
            break;
        }
    }
    else
    {
        switch (packet->state)
        {
        case 0:
            if (packet->flags & 0x10)
            {
                btlUnit0027f7c0(unit, &packet->targetPos, NULL, NULL);
            }
            packet->state++;
            break;

        case 1:
            func_002d4800(&unit->unk_ec);
            unit->unk_e8 = packet->unk_1c;
            unit->unk_c4 = packet->flags;
            unit->unk_cc = 27.0f * packet->speed;
            start.x = unit->pos.x;
            start.y = unit->pos.z;
            start.z = 0.0f;
            end.x = packet->targetPos.x;
            end.y = packet->targetPos.z;
            end.z = 0.0f;
            func_002d48c0(&unit->unk_ec, &start, &end, 50.0f);
            unit->unk_dc = packet->targetPos;
            packet->state++;
            break;

        case 2:
            if (unit->unk_4f0 == 2)
            {
                unit->movementFlags &= ~0x20;
                unit->movementFlags |= BTLUNIT_MOVEMENTFLAGS_MOVE;
                unit->movementFlags |= 0x10;
                packet->state++;
            }
            else if (unit->unk_4f0 == 3)
            {
                unit->unk_ec.x = unit->pos.x;
                unit->unk_ec.y = unit->pos.z;
                unit->unk_ec.z = packet->targetPos.x;
                unit->unk_f8 = packet->targetPos.z;
                unit->unk_4ec = 3;
                unit->movementFlags &= ~0x20;
                unit->movementFlags |= BTLUNIT_MOVEMENTFLAGS_MOVE;
                unit->movementFlags |= 0x10;
                packet->state++;
            }
            break;

        case 3:
            if (!(unit->movementFlags & (BTLUNIT_MOVEMENTFLAGS_MOVE | BTLUNIT_MOVEMENTFLAGS_ROTATE)))
            {
                return 1;
            }
            break;
        }
    }

    packet->timer++;
    return 0;
}

// FUN_002819b0
void btlUnitDestroyMovePacket(void* work)
{
    BtlUnitPacketMove* packet;

    packet = (BtlUnitPacketMove*)work;

    packet->unit->packetCount--;
}

// FUN_002819d0
BtlPacket* btlUnitCreateMovePacket(BtlUnit* unit, const RwV3d* targetPos, f32 speed, u32 flags)
{
    BtlPacket* packet;
    BtlUnitPacketMove* work;

    packet = btlPacketCreate(BTLUNIT_PACKET_MOVE, sizeof(BtlUnitPacketMove));

    packet->initFunc = btlUnitInitMovePacket;
    packet->updateFunc = btlUnitUpdateMovePacket;
    packet->destroyFunc = btlUnitDestroyMovePacket;

    work = (BtlUnitPacketMove*)packet->workData;

    work->unit = unit;
    work->speed = speed;
    work->flags = flags;

    if (targetPos != NULL)
    {
        work->targetPos = *targetPos;
    }
    else
    {
        work->targetPos = gUnk_00957188;
    }

    return packet;
}

// FUN_00281ab0
void btlUnitInitMoveToUnitPacket(void* work)
{
    BtlUnitPacketMoveToUnit* packet;

    packet = (BtlUnitPacketMoveToUnit*)work;

    packet->targetUnit->packetCount++;
}

// FUN_00281ad0 NONMATCHING
u32 btlUnitUpdateMoveToUnitPacket(void* work)
{
    BtlUnitPacketMoveToUnit* packet;
    BtlUnit* targetUnit;
    BtlUnit* unit;
    const BtlUnitAnimBounds* bounds;
    RwV3d targetPos;
    RwV3d scaledCenter;
    RwV3d rotatedCenter;
    RtQuat targetRot;
    RwV3d offset;

    packet = (BtlUnitPacketMoveToUnit*)work;

    if (packet->move.timer == 0)
    {
        targetUnit = packet->targetUnit;
        unit = packet->move.unit;

        if (!(targetUnit->flags3 & BTLUNIT_FLAG3_NOROT))
        {
            func_002d1de0((RwV3d*)&targetRot, &targetUnit->pos, &unit->pos);
            if (packet->move.flags & 0x40)
            {
                bounds = func_00288da0(targetUnit, 0);
                scaledCenter.x = bounds->centerX * targetUnit->scale;
                scaledCenter.y = bounds->centerY * targetUnit->scale;
                scaledCenter.z = bounds->centerZ * targetUnit->scale;
            }
            else
            {
                scaledCenter.x = targetUnit->sphereCenter.x * targetUnit->scale;
                scaledCenter.y = targetUnit->sphereCenter.y * targetUnit->scale;
                scaledCenter.z = targetUnit->sphereCenter.z * targetUnit->scale;
            }
            RtQuatTransformVectors(&rotatedCenter, &scaledCenter, 1, &targetRot);
        }
        else
        {
            if (packet->move.flags & 0x40)
            {
                bounds = func_00288da0(targetUnit, 0);
                scaledCenter.x = bounds->centerX * targetUnit->scale;
                scaledCenter.y = bounds->centerY * targetUnit->scale;
                scaledCenter.z = bounds->centerZ * targetUnit->scale;
            }
            else
            {
                scaledCenter.x = targetUnit->sphereCenter.x * targetUnit->scale;
                scaledCenter.y = targetUnit->sphereCenter.y * targetUnit->scale;
                scaledCenter.z = targetUnit->sphereCenter.z * targetUnit->scale;
            }
            RtQuatTransformVectors(&rotatedCenter, &scaledCenter, 1, &targetUnit->rot);
        }

        targetPos.x = targetUnit->pos.x + rotatedCenter.x;
        targetPos.y = targetUnit->pos.y + rotatedCenter.y;
        targetPos.z = targetUnit->pos.z + rotatedCenter.z;

        RtQuatTransformVectors(&offset, &D_00697890, 1, &targetUnit->rot);
        targetPos.x += offset.x * packet->move.unk_1c;
        targetPos.y += offset.y * packet->move.unk_1c;
        targetPos.z += offset.z * packet->move.unk_1c;
        packet->move.targetPos = targetPos;
        packet->move.unk_1c = 0.0f;
    }

    return btlUnitUpdateMovePacket(&packet->move);
}

// FUN_00281e60
void btlUnitDestroyMoveToUnitPacket(void* work)
{
    BtlUnitPacketMoveToUnit* packet;

    packet = (BtlUnitPacketMoveToUnit*)work;

    packet->targetUnit->packetCount--;
}

// FUN_00281e80
BtlPacket* btlUnitCreateMoveToUnitPacket(BtlUnit* unit, BtlUnit* targetUnit, f32 param_3, f32 speed, u32 flags)
{
    BtlPacket* packet;
    BtlUnitPacketMoveToUnit* work;

    packet = btlPacketCreate(BTLUNIT_PACKET_MOVETOUNIT, sizeof(BtlUnitPacketMoveToUnit));
    
    packet->initFunc = btlUnitInitMoveToUnitPacket;
    packet->updateFunc = btlUnitUpdateMoveToUnitPacket;
    packet->destroyFunc = btlUnitDestroyMoveToUnitPacket;

    work = (BtlUnitPacketMoveToUnit*)packet->workData;

    work->move.unit = unit;
    work->move.unk_1c = param_3;
    work->move.speed = speed;
    work->move.flags = flags;
    work->targetUnit = targetUnit;

    return packet;
}

// FUN_00282190
void btlUnitInitRotatePacket(void* work)
{
    BtlUnitPacketRotate* packet;

    packet = (BtlUnitPacketRotate*)work;

    packet->unit->packetCount++;
}

// FUN_002821b0
u32 btlUnitUpdateRotatePacket(void* work)
{
    BtlUnitPacketRotate* packet;
    BtlUnit* unit;
    RwV3d baseRot;
    u32 flags;
    u32 ret;

    packet = (BtlUnitPacketRotate*)work;
    unit = packet->unit;

    if (packet->timer == 0)
    {
        if (packet->flags & (1 << 5))
        {
            btlUnit0027f7c0(unit, NULL, NULL, &baseRot);
            packet->rot = baseRot;
        }

        flags = packet->flags;
        
        unit->targetRot = packet->rot;
        unit->unk_4f8 = 0;
        unit->unk_e8 = 0;
        unit->unk_c4 = flags;
        unit->movementFlags |= BTLUNIT_MOVEMENTFLAGS_ROTATE;
    }

    // !(unit->movementFlags & BTLUNIT_MOVEMENTFLAGS_ROTATE)
    if (!(unit->movementFlags & BTLUNIT_MOVEMENTFLAGS_ROTATE ? 1 : 0))
    {
        return 1;
    }

    packet->timer++;

    return 0;
}

// FUN_00282290
void btlUnitDestroyRotatePacket(void* work)
{
    BtlUnitPacketRotate* packet;

    packet = (BtlUnitPacketRotate*)work;

    packet->unit->packetCount--;
}

// FUN_002822b0
BtlPacket* btlUnitCreateRotatePacket(BtlUnit* unit, const RwV3d* rot, u32 flags)
{
    BtlPacket* packet;
    BtlUnitPacketRotate* work;

    packet = btlPacketCreate(BTLUNIT_PACKET_ROTATE, sizeof(BtlUnitPacketRotate));

    packet->initFunc = btlUnitInitRotatePacket;
    packet->updateFunc = btlUnitUpdateRotatePacket;
    packet->destroyFunc = btlUnitDestroyRotatePacket;

    work = (BtlUnitPacketRotate*)packet->workData;

    work->unit = unit;
    work->flags = flags;

    if (rot != NULL)
    {
        work->rot = *rot;
    }
    else
    {
        work->rot = gUnk_00957188;
    }

    return packet;
}

// FUN_00282380
void btlUnitInitRotateTowardUnitPacket(void* work)
{
    BtlUnitPacketRotateTowardUnit* packet;

    packet = (BtlUnitPacketRotateTowardUnit*)work;

    packet->unit->packetCount++;
    packet->targetUnit->packetCount++;
}

// FUN_002823b0 NONMATCHING
u32 btlUnitUpdateRotateTowardUnitPacket(void* work)
{
    BtlUnitPacketRotateTowardUnit* packet;
    BtlUnit* unit;
    BtlUnit* targetUnit;
    RwV3d scaledCenter;
    RwV3d rotatedCenter;
    RwV3d targetRot;
    RtQuat rot;
    f32 x;
    f32 z;
    f32 angle;

    packet = (BtlUnitPacketRotateTowardUnit*)work;
    unit = packet->unit;

    if (packet->timer == 0)
    {
        targetUnit = packet->targetUnit;

        if (packet->flags & 2)
        {
            if (packet->flags & 0x20)
            {
                scaledCenter.x = targetUnit->sphereCenter.x * targetUnit->scale;
                scaledCenter.y = targetUnit->sphereCenter.y * targetUnit->scale;
                scaledCenter.z = targetUnit->sphereCenter.z * targetUnit->scale;
                RtQuatTransformVectors(&rotatedCenter, &scaledCenter, 1, &targetUnit->rot);
                x = rotatedCenter.x + targetUnit->unk_94 * 25 - 0x6d6 - unit->pos.x;
                z = rotatedCenter.z + targetUnit->unk_96 * 25 - 0x6d6 - unit->pos.z;
            }
            else
            {
                x = targetUnit->pos.x - unit->pos.x;
                z = targetUnit->pos.z - unit->pos.z;
            }

            if (x != 0.0f || z != 0.0f)
            {
                angle = func_0052ea18(x, z) * 57.295776f;
                func_004bdde0(&rot, &D_00697880, 0, angle);
                if (!(unit->flags3 & BTLUNIT_FLAG3_NOROT))
                {
                    unit->rot = rot;
                    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
                }
            }

            unit->movementFlags &= ~BTLUNIT_MOVEMENTFLAGS_ROTATE;
            func_00288110(unit);
        }
        else
        {
            if (packet->flags & 0x20)
            {
                btlUnit0027f7c0(targetUnit, &unit->targetRot, NULL, NULL);
            }
            else
            {
                unit->targetRot = targetUnit->pos;
            }

            unit->unk_c4 |= packet->flags;
            unit->movementFlags |= BTLUNIT_MOVEMENTFLAGS_ROTATE;
        }
    }

    if (!(unit->movementFlags & BTLUNIT_MOVEMENTFLAGS_ROTATE))
    {
        return 1;
    }

    packet->timer++;
    return 0;
}

// FUN_00282620
void btlUnitDestroyRotateTowardUnitPacket(void* work)
{
    BtlUnitPacketRotateTowardUnit* packet;

    packet = (BtlUnitPacketRotateTowardUnit*)work;

    packet->unit->packetCount--;
    packet->targetUnit->packetCount--;
}

// FUN_00282650
BtlPacket* btlUnitCreateRotateTowardUnitPacket(BtlUnit* unit, BtlUnit* targetUnit, u32 flags)
{
    BtlPacket* packet;
    BtlUnitPacketRotateTowardUnit* work;

    packet = btlPacketCreate(BTLUNIT_PACKET_ROTATETOWARDUNIT, sizeof(BtlUnitPacketRotateTowardUnit));

    packet->initFunc = btlUnitInitRotateTowardUnitPacket;
    packet->updateFunc = btlUnitUpdateRotateTowardUnitPacket;
    packet->destroyFunc = btlUnitDestroyRotateTowardUnitPacket;

    work = (BtlUnitPacketRotateTowardUnit*)packet->workData;

    work->unit = unit;
    work->targetUnit = targetUnit;
    work->flags = flags;

    return packet;
}

// FUN_00282c30
s16 btlUnit00282c30(BtlUnit* unit)
{
    if ((unit->flags2 & 2) != 0)
    {
        return unit->unk_9ce;
    }

    return 0;
}

// FUN_00282c60
u32 btlUnit00282c60(BtlUnit* unit)
{
    s16 val;

    switch (unit->genus)
    {
    case 0:
    case 1:
        if ((unit->flags2 & 2) != 0)
        {
            val = unit->unk_9ce;
        }
        else
        {
            val = 0;
        }
        return unit->unk_9e0 == val;
    }

    return 0;
}

// FUN_00282cd0
u32 btlUnit00282cd0(BtlUnit* unit)
{
    s16 val;

    switch (unit->genus)
    {
    case 0:
    case 1:
        if ((unit->flags2 & 2) != 0)
        {
            val = unit->unk_9ce;
        }
        else
        {
            val = 0;
        }
        return val == 1;
    }

    return 0;
}

// FUN_00282d40 NONMATCHING
void btlUnitAnimate(BtlUnit* unit, s32 id, u16 blendFrameCount, f32 speed, u16 mode)
{
    const BtlUnitAnimInfo* animInfo;
    const BtlUnitAnimBounds* bounds;
    s16 animId;
    u16 mdlFlags;

    unit->unk_9d0 = mode;

    if (!(unit->flags2 & BTLUNIT_FLAG2_UPDATE))
    {
        return;
    }

    unit->unk_9ce = id;
    animId = func_00283510(unit, id);
    animInfo = (const BtlUnitAnimInfo*)unit->unk_9ec;

    if (animId < unit->unk_9d8)
    {
        unit->unk_9d4 = speed * ((f32)animInfo[animId].speedPercent / 100.0f);
    }
    else
    {
        unit->unk_9d4 = 1.0f;
    }

    if (mode == BTLUNIT_ANIM_MODE_ONCE)
    {
        mdlFlags = 0;
    }
    else
    {
        mdlFlags = MDLANIM_FLAG_LOOP;
    }

    if (speed != 1.0f &&
        (id == 4 || id == 5 || id == 6 || id == 11))
    {
        mdlFlags |= 0x60;
    }

    mdlAnimSet(unit->mdl, 0, animId, blendFrameCount, mdlFlags);
    mdlAnimSetSpeed(unit->mdl, 0, unit->unk_9d4);

    bounds = func_00288da0(unit, id);
    unit->sphereCenter.x = bounds->centerX;
    unit->sphereCenter.y = bounds->centerY;
    unit->sphereCenter.z = bounds->centerZ;
    unit->unk_8c = bounds->unk_6;
    unit->sphereRadius = bounds->radius;

    if (id == 15 || id == 7)
    {
        if (animId < unit->unk_9d8 &&
            animInfo[animId].unk_0 >= 0 &&
            animInfo[animId].unk_4 > 0)
        {
            unit->unk_9cc |= 4;
            unit->unk_9da = animInfo[animId].unk_0;
            unit->unk_9dc = animInfo[animId].unk_4;
        }
    }
    else
    {
        unit->unk_9cc &= ~4;
    }

    if (mode != BTLUNIT_ANIM_MODE_ONCE)
    {
        return;
    }

    switch (id)
    {
    case 19:
    case 22:
    case 21:
    case 10:
    case 8:
    case 11:
    case 7:
    case 2:
        unit->unk_9e2 = 0;
        break;

    case 6:
    case 5:
    case 4:
        if (unit->genus == UNIT_GENUS_PC && unit->datUnit != NULL &&
            datCalcGetHeldWeaponType(unit->datUnit) == 6)
        {
            unit->unk_9e2 = 0;
        }
        else
        {
            unit->unk_9e2 = unit->genus == UNIT_GENUS_PC ? 5 : 0;
        }
        break;

    default:
        if (animId < unit->unk_9d8)
        {
            unit->unk_9e2 = animInfo[animId].unk_8;
        }
        else
        {
            unit->unk_9e2 = 0;
        }
        break;
    }
}

// FUN_00283ba0
s16 btlUnitGetAnimFrame(BtlUnit* unit)
{
    if (unit->flags2 & BTLUNIT_FLAG2_UPDATE)
    {
        return (s32)mdlAnimGetCurrentFrame(unit->mdl, 0);
    }

    return 0;
}

// FUN_00283c00
void btlUnit00283c00(BtlUnit* unit, s32 param_2)
{
    if ((unit->flags2 & 2) != 0)
    {
        mdlAnim00318770(unit->mdl, 0, (f32)param_2);
    }
}

// FUN_00284170
void btlUnitInitAnimPacket(void* work)
{
    BtlUnitPacketAnim* packet;

    packet = (BtlUnitPacketAnim*)work;

    packet->unit->packetCount++;
}

// FUN_00284190
u32 btlUnitUpdateAnimPacket(void* work)
{
    BtlUnitPacketAnim* packet;

    packet = (BtlUnitPacketAnim*)work;

    if (packet->id >= 0 && packet->id < BTLUNIT_ANIM_MAX)
    {
        btlUnitAnimate(packet->unit,
                       packet->id,
                       packet->blendFrameCount,
                       packet->speed,
                       packet->mode);
    }

    return 1;
}

// FUN_002841e0
void btlUnitDestroyAnimPacket(void* work)
{
    BtlUnitPacketAnim* packet;

    packet = (BtlUnitPacketAnim*)work;

    packet->unit->packetCount--;
}

// FUN_00284200
BtlPacket* btlUnitCreateAnimPacket(BtlUnit* unit, u16 id, u16 blendFrameCount, f32 speed, u16 mode)
{
    BtlPacket* packet;
    BtlUnitPacketAnim* work;
    s16 _id;

    _id = id;
    switch (_id)
    {
        case BTLUNIT_ANIM_RESNULLIFIED: return btlUnitCreateResNullifiedAnimPacket(unit, 32.0f);
        case -3:                        return btlUnit00284900(unit, 6);
        case BTLUNIT_ANIM_ENMDODGE:     return btlUnitCreateEnmDodgeAnimPacket(unit, 6);
    }

    packet = btlPacketCreate(BTLUNIT_PACKET_ANIM, sizeof(BtlUnitPacketAnim));

    packet->initFunc = btlUnitInitAnimPacket;
    packet->updateFunc = btlUnitUpdateAnimPacket;
    packet->destroyFunc = btlUnitDestroyAnimPacket;

    work = (BtlUnitPacketAnim*)packet->workData;

    work->unit = unit;

    switch (_id)
    {
        case -5:
            _id = -1;
    }

    work->id = _id;
    work->blendFrameCount = blendFrameCount;
    work->speed = speed;
    work->mode = mode;

    return packet;
}

// 8 bytes
typedef struct BtlUnitPacket002843e0
{
    BtlUnit* unit; // 0x00
    s16 unk_4;     // 0x04
    u8 unkData[0x02];
} BtlUnitPacket002843e0;

// FUN_00284330
void btlUnitInit002843e0Packet(void* work)
{
    BtlUnitPacket002843e0* packet;

    packet = (BtlUnitPacket002843e0*)work;

    packet->unit->packetCount++;
}

// FUN_00284350
u32 btlUnitUpdate002843e0Packet(void* work)
{
    __asm__ volatile (
      ".set noreorder ;"
      ".word 0x27bdfff0 ;"
      ".word 0xffbf0000 ;"
      ".word 0x0080182d ;"
      ".word 0x8c840000 ;"
      ".word 0x8c820098 ;"
      ".word 0x30420002 ;"
      ".word 0x10400004 ;"
      ".word 0x00000000 ;"
      ".word 0x848209ce ;"
      ".word 0x10000002 ;"
      ".word 0x00000000 ;"
      ".word 0x0000102d ;"
      ".word 0x0002143c ;"
      ".word 0x0002143f ;"
      ".word 0x848509e0 ;"
      ".word 0x10a20006 ;"
      ".word 0x00000000 ;"
      ".word 0x808709e8 ;"
      ".word 0x94660004 ;"
      ".word 0xc48c09e4 ;"
      ".word 0x0c0a0b50 ;"
      ".word 0x00000000 ;"
      ".word 0x24020001 ;"
      ".word 0xdfbf0000 ;"
      ".word 0x27bd0010 ;"
      ".set reorder");
}

// FUN_002843c0
void btlUnitDestroy002843e0Packet(void* work)
{
    BtlUnitPacket002843e0* packet;

    packet = (BtlUnitPacket002843e0*)work;

    packet->unit->packetCount--;
}

// FUN_002843e0
BtlPacket* btlUnit002843e0(BtlUnit* unit, s16 param_2)
{
    BtlPacket* packet;
    BtlUnitPacket002843e0* work;

    packet = btlPacketCreate(0x104, sizeof(BtlUnitPacket002843e0));

    packet->initFunc = btlUnitInit002843e0Packet;
    packet->updateFunc = btlUnitUpdate002843e0Packet;
    packet->destroyFunc = btlUnitDestroy002843e0Packet;

    work = (BtlUnitPacket002843e0*)packet->workData;

    work->unit = unit;
    work->unk_4 = param_2;

    return packet;
}

// FUN_00284450
void btlUnitInitResNullifiedAnimPacket(void* work)
{
    BtlUnitPacketResNullifiedAnim* packet;

    packet = (BtlUnitPacketResNullifiedAnim*)work;

    packet->unit->packetCount++;
}

// FUN_00284470
u32 btlUnitUpdateResNullifiedAnimPacket(void* work)
{
    BtlUnitPacketResNullifiedAnim* packet;
    BtlUnit* unit;
    RwV3d direction;
    f32 magnitude;

    packet = (BtlUnitPacketResNullifiedAnim*)work;
    unit = packet->unit;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;

    if (packet->unk_4 > 0.5f)
    {
        RtQuatTransformVectors(&direction, &D_00697870, 1, &unit->rot);

        if (packet->counter & 1)
        {
            magnitude = packet->unk_4 * (0.5f + 0.5f * effMiscRandFloat(0));
        }
        else
        {
            magnitude = -packet->unk_4 * (0.5f + 0.5f * effMiscRandFloat(0));
        }

        unit->posOffset.x = direction.x * magnitude;
        unit->posOffset.y = direction.y * magnitude;
        unit->posOffset.z = direction.z * magnitude;
        packet->unk_4 *= gUnk_007cad7c;
        unit->unk_9cc |= 1;
    }
    else
    {
        unit->posOffset.x = 0.0f;
        unit->posOffset.y = 0.0f;
        unit->posOffset.z = 0.0f;
        unit->unk_9cc &= ~1;
        return 1;
    }

    packet->counter++;
    return 0;
}

// FUN_002845e0
void btlUnitDestroyResNullifiedAnimPacket(void* work)
{
    BtlUnitPacketResNullifiedAnim* packet;

    packet = (BtlUnitPacketResNullifiedAnim*)work;

    packet->unit->packetCount--;
}

// FUN_00284600
BtlPacket* btlUnitCreateResNullifiedAnimPacket(BtlUnit* unit, f32 param_2)
{
    BtlPacket* packet;
    BtlUnitPacketResNullifiedAnim* work;

    packet = btlPacketCreate(0x107, sizeof(BtlUnitPacketResNullifiedAnim));

    packet->initFunc = btlUnitInitResNullifiedAnimPacket;
    packet->updateFunc = btlUnitUpdateResNullifiedAnimPacket;
    packet->destroyFunc = btlUnitDestroyResNullifiedAnimPacket;

    work = (BtlUnitPacketResNullifiedAnim*)packet->workData;

    work->unit = unit;
    work->unk_4 = param_2;

    return packet;
}

// FUN_00284670
void btlUnitInit00284900Packet(void* work)
{
    BtlUnitPacket00284900* packet;

    packet = (BtlUnitPacket00284900*)work;

    packet->unit->packetCount++;
}

// FUN_00284690
u32 btlUnitUpdate00284900Packet(void* work)
{
    static volatile f32 one = 1.0f;
    BtlUnitPacket00284900* packet;
    BtlUnit* unit;
    RwV3d position;
    RwV3d direction;
    f32 phase;
    f32 magnitude;
    f32 arcScale;
    u32 result;

    packet = (BtlUnitPacket00284900*)work;
    unit = packet->unit;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;

    if (packet->unk_12 == 0)
    {
        packet->phase = 0.5f;
        packet->pos = unit->pos;
    }

    phase = packet->phase + 1.0f / (2.0f * (f32)packet->unk_10);
    packet->phase = phase;
    arcScale = 2.0f * (((-1.0f + (-2.0f * phase * phase)) + (4.0f * phase)) - 0.5f);

    RtQuatTransformVectors(&direction, &D_00697870, 1, &unit->rot);
    magnitude = unit->sphereRadius * unit->scale * 1.25f;
    if (magnitude < 75.0f)
    {
        magnitude = 75.0f;
    }

    if (arcScale < one)
    {
        magnitude *= arcScale;
        direction.x *= magnitude;
        direction.y *= magnitude;
        direction.z *= magnitude;
        result = 0;
        goto update;
    }

    direction.x *= magnitude;
    direction.y *= magnitude;
    direction.z *= magnitude;

    result = 1;
update:
    if (!(unit->flags3 & BTLUNIT_FLAG3_UNK400))
    {
        position.x = packet->pos.x + direction.x;
        position.y = packet->pos.y + direction.y;
        position.z = packet->pos.z + direction.z;
        unit->pos = position;
        unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    }

    packet->unk_12++;
    return result;
}

// FUN_002848e0
void btlUnitDestroy00284900Packet(void* work)
{
    BtlUnitPacket00284900* packet;

    packet = (BtlUnitPacket00284900*)work;

    packet->unit->packetCount--;
}

// FUN_00284900
BtlPacket* btlUnit00284900(BtlUnit* unit, s32 param_2)
{
    BtlPacket* packet;
    BtlUnitPacket00284900* work;

    packet = btlPacketCreate(0x108, sizeof(BtlUnitPacket00284900));

    packet->initFunc = btlUnitInit00284900Packet;
    packet->updateFunc = btlUnitUpdate00284900Packet;
    packet->destroyFunc = btlUnitDestroy00284900Packet;

    work = (BtlUnitPacket00284900*)packet->workData;

    work->unit = unit;
    work->unk_10 = param_2;
    work->unk_12 = 0;

    return packet;
}

// FUN_00284980
void btlUnitInitEnmDodgeAnimPacket(void* work)
{
    BtlUnitPacketEnmDodgeAnim* packet;

    packet = (BtlUnitPacketEnmDodgeAnim*)work;

    packet->unit->packetCount++;
}

// FUN_002849a0 NONMATCHING
u32 btlUnitUpdateEnmDodgeAnimPacket(void* work)
{
    static volatile f32 phaseLimit = 1.0f;
    static volatile f32 baseScale = 0.3f;
    static volatile f32 stepDelta = 0.05f;
    static volatile f32 reverseStep = -0.3f;
    BtlUnitPacketEnmDodgeAnim* packet;
    BtlUnit* unit;
    RwV3d direction;
    f32 phase;
    f32 baseMagnitude;
    f32 magnitude;
    f32 positiveDelta;
    f32 negativeDelta;
    packet = (BtlUnitPacketEnmDodgeAnim*)work;
    unit = packet->unit;

    baseMagnitude = unit->sphereRadius * unit->scale * baseScale;
    if (baseMagnitude > 100.0f)
    {
        baseMagnitude = 100.0f;
    }

    if (packet->unk_4 == 0)
    {
        packet->phase = 0.0f;
        packet->step = baseScale;
    }

    if (packet->step >= 0.0f)
    {
        phase = packet->phase;
        positiveDelta = (1.0f - phase) * packet->step;
        packet->step += stepDelta;
        magnitude = baseMagnitude * packet->phase;
        packet->phase += positiveDelta;
        if (packet->phase >= phaseLimit)
        {
            packet->step = reverseStep;
        }
    }
    else
    {
        negativeDelta = -packet->step;
        phase = packet->phase;
        negativeDelta = phase * negativeDelta;
        packet->step -= stepDelta;
        magnitude = baseMagnitude * packet->phase;
        phase -= negativeDelta;
        packet->phase = phase;
        if (phase <= 0.0f)
        {
            if (!(unit->flags3 & BTLUNIT_FLAG3_UNK400))
            {
                unit->posOffset.x = 0.0f;
                unit->posOffset.y = 0.0f;
                unit->posOffset.z = 0.0f;
            }
            return 1;
        }
    }

    if (!(unit->flags3 & BTLUNIT_FLAG3_UNK400))
    {
        RtQuatTransformVectors(&direction, &D_00697870, 1, &unit->rot);
        unit->posOffset.x = direction.x * magnitude;
        unit->posOffset.y = direction.y * magnitude;
        unit->posOffset.z = direction.z * magnitude;
    }

    packet->unk_4++;
    return 0;
}


// FUN_00284b50
void btlUnitDestroyEnmDodgeAnimPacket(void* work)
{
    BtlUnitPacketEnmDodgeAnim* packet;

    packet = (BtlUnitPacketEnmDodgeAnim*)work;

    packet->unit->packetCount--;
}

// FUN_00284b70
BtlPacket* btlUnitCreateEnmDodgeAnimPacket(BtlUnit* unit, s32 unused)
{
    BtlPacket* packet;
    BtlUnitPacketEnmDodgeAnim* work;

    packet = btlPacketCreate(0x109, sizeof(BtlUnitPacketEnmDodgeAnim));

    packet->initFunc = btlUnitInitEnmDodgeAnimPacket;
    packet->updateFunc = btlUnitUpdateEnmDodgeAnimPacket;
    packet->destroyFunc = btlUnitDestroyEnmDodgeAnimPacket;

    work = (BtlUnitPacketEnmDodgeAnim*)packet->workData;

    work->unit = unit;
    work->unk_4 = 0;

    return packet;
}

// FUN_00284be0
void btlUnitInit00284c90Packet(void* work)
{
    BtlUnitPacket00284c90* packet;

    packet = (BtlUnitPacket00284c90*)work;

    packet->unit->packetCount++;
}

// FUN_00284c00
u32 btlUnitUpdate00284c90Packet(void* work)
{
    BtlUnitPacket00284c90* packet;
    BtlUnit* unit;
    s16 current;

    packet = (BtlUnitPacket00284c90*)work;

    unit = packet->unit;

    switch (unit->genus)
    {
        case UNIT_GENUS_PC:
        case UNIT_GENUS_EC:
            if (unit->flags2 & BTLUNIT_FLAG2_UPDATE)
            {
                current = unit->unk_9ce;
            }
            else
            {
                current = 0;
            }

            return unit->unk_9e0 == current;
    }

    return 0;
}

// FUN_00284c70
void btlUnitDestroy00284c90Packet(void* work)
{
    BtlUnitPacket00284c90* packet;

    packet = (BtlUnitPacket00284c90*)work;

    packet->unit->packetCount--;
}

// FUN_00284c90
BtlPacket* btlUnit00284c90(BtlUnit* unit)
{
    BtlPacket* packet;
    BtlUnitPacket00284c90* work;

    packet = btlPacketCreate(0x105, sizeof(BtlUnitPacket00284c90));

    packet->initFunc = btlUnitInit00284c90Packet;
    packet->updateFunc = btlUnitUpdate00284c90Packet;
    packet->destroyFunc = btlUnitDestroy00284c90Packet;

    work = (BtlUnitPacket00284c90*)packet->workData;

    work->unit = unit;

    return packet;
}

// FUN_00284cf0
void btlUnitInit00284d80Packet(void* work)
{
    BtlUnitPacket00284d80* packet;

    packet = (BtlUnitPacket00284d80*)work;

    packet->unit->packetCount++;
}

// FUN_00284d10
u32 btlUnitUpdate00284d80Packet(void* work)
{
    BtlUnitPacket00284d80* packet;
    s16 frame;
    BtlUnit* unit;

    packet = (BtlUnitPacket00284d80*)work;

    frame = packet->unk_4;
    unit = packet->unit;

    if (unit->flags2 & BTLUNIT_FLAG2_UPDATE)
    {
        mdlAnim00318770(unit->mdl, 0, frame);
    }

    return 1;
}

// FUN_00284d60
void btlUnitDestroy00284d80Packet(void* work)
{
    BtlUnitPacket00284d80* packet;

    packet = (BtlUnitPacket00284d80*)work;

    packet->unit->packetCount--;
}

// FUN_00284d80
BtlPacket* btlUnit00284d80(BtlUnit* unit, s16 param_2)
{
    BtlPacket* packet;
    BtlUnitPacket00284d80* work;

    packet = btlPacketCreate(0x102, sizeof(BtlUnitPacket00284d80));

    packet->initFunc = btlUnitInit00284d80Packet;
    packet->updateFunc = btlUnitUpdate00284d80Packet;
    packet->destroyFunc = btlUnitDestroy00284d80Packet;

    work = (BtlUnitPacket00284d80*)packet->workData;

    work->unit = unit;
    work->unk_4 = param_2;

    return packet;
}

// FUN_00284df0
void btlUnitInit00284f50Packet(void* work)
{
    BtlUnitPacket00284f50* packet;

    packet = (BtlUnitPacket00284f50*)work;

    packet->unit->packetCount++;
}

// FUN_00284e10
u32 btlUnitUpdate00284f50Packet(void* work)
{
    BtlUnitPacket00284f50* packet;
    BtlUnit* unit;
    f32 speed;
    u16 blendFrameCount;
    u16 mode;
    s16 frame;

    packet = (BtlUnitPacket00284f50*)work;

    mode = packet->unk_c;
    speed = packet->unk_8;
    blendFrameCount = packet->unk_4;
    unit = packet->unit;

    if (unit->flags2 & BTLUNIT_FLAG2_UPDATE)
    {
        FUN_00287cf0(unit, 4);

        if (unit->flags2 & BTLUNIT_FLAG2_UPDATE)
        {
            frame = (s32)mdlAnimGetCurrentFrame(unit->mdl, 0);
        }
        else
        {
            frame = 0;
        }

        btlUnitAnimate(unit, unit->unk_9ce, blendFrameCount, speed, mode);

        if (unit->flags2 & BTLUNIT_FLAG2_UPDATE)
        {
            mdlAnim00318770(unit->mdl, 0, frame);
        }
        FUN_00287b20((int)unit, 4);

    }

    return 1;
}

// FUN_00284f30
void btlUnitDestroy00284f50Packet(void* work)
{
    BtlUnitPacket00284f50* packet;

    packet = (BtlUnitPacket00284f50*)work;

    packet->unit->packetCount--;
}

// FUN_00284f50
BtlPacket* btlUnit00284f50(BtlUnit* unit, u16 param_2, f32 speed, u16 param_4)
{
    BtlPacket* packet;
    BtlUnitPacket00284f50* work;

    packet = btlPacketCreate(0x103, sizeof(BtlUnitPacket00284f50));

    packet->initFunc = btlUnitInit00284f50Packet;
    packet->updateFunc = btlUnitUpdate00284f50Packet;
    packet->destroyFunc = btlUnitDestroy00284f50Packet;

    work = (BtlUnitPacket00284f50*)packet->workData;

    work->unit = unit;
    work->unk_4 = param_2;
    work->unk_8 = speed;
    work->unk_c = param_4;

    return packet;
}

// FUN_00284fe0
void btlUnitInitModelPacket(void* work)
{
    BtlUnitPacketModel* packet;
    BtlUnit* unit;
    Model* mdl;
    u32 flags;
    char path[128];

    packet = (BtlUnitPacketModel*)work;

    unit = packet->unit;

    unit->packetCount++;

    if (unit->mdl != NULL)
    {
        if (packet->type == unit->mdl->type && packet->id == unit->mdl->id)
        {
            return;
        }

        mdlDestroy(unit->mdl);
        unit->mdl = NULL;
    }

    mdl = mdlSearch(packet->type, packet->id, 0);

    if (mdl != NULL)
    {
        unit->mdl = mdlClone(mdl);

        flags = unit->flags2 | BTLUNIT_FLAG2_UPDATE;
        unit->flags2 = flags;
        unit->flags2 = flags | BTLUNIT_FLAG2_UNK01;
    }
    else
    {
        if (!(packet->flags & (1 << 4)))
        {
            mdlFileResolvePackPath(packet->type, packet->id, path);
            packet->cdvd = H_Cdvd_Request(path, 0);
            unit->flags2 |= BTLUNIT_FLAG2_UNK01;
        }

        unit->flags2 &= ~BTLUNIT_FLAG2_UPDATE;
    }
}

// FUN_002850f0 NONMATCHING
u32 btlUnitUpdateModelPacket(void* work)
{
    BtlUnitPacketModel* packet;
    BtlUnit* unit;
    Model* mdl;
    const BtlUnitAnimInfo* animInfo;
    s16 animId;
    f32 duration;
    u32 frame;
    u16 dataFlags;
    char path[128];

    packet = (BtlUnitPacketModel*)work;
    unit = packet->unit;

    if (!(unit->flags2 & BTLUNIT_FLAG2_UNK01))
    {
        mdl = mdlSearch(packet->type, packet->id, 0);
        if (mdl != NULL)
        {
            unit->mdl = mdlClone(mdl);
        }
        else
        {
            mdlFileResolvePackPath(packet->type, packet->id, path);
            packet->cdvd = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            unit->flags2 |= BTLUNIT_FLAG2_UNK01;
        }
    }

    if (unit->mdl == NULL)
    {
        if (!H_Cdvd_IsFileLoaded(packet->cdvd))
        {
            return 0;
        }

        unit->mdl = func_00316c70(packet->type, packet->id, packet->cdvd, HCDVD_FILENORMAL);
        if (packet->type == MODEL_TYPE_BTLCHAR)
        {
            func_0031c1d0(unit->mdl);
        }
        return 0;
    }
    else if (!mdlStreamRead(unit->mdl))
    {
        return 0;
    }

    if (packet->flags & 4)
    {
        switch (unit->genus)
        {
        case UNIT_GENUS_PC:
            unit->resTypeId = MT_Scene_CreateResModelChar(unit->charId, 0, unit->mdl);
            func_001a0590(unit->resTypeId, 1);
            if (func_002d5cf0(unit))
            {
                unit->mdl->flags |= 0x400;
            }
            func_00319230(unit->mdl, 1);
            break;

        case UNIT_GENUS_EC:
            unit->resTypeId = MT_Scene_CreateResModelChar(btlFindFreeCharResId(), 0, unit->mdl);
            func_001a0590(unit->resTypeId, 1);
            func_00319230(unit->mdl, 1);

            dataFlags = *(const u16*)((const u8*)func_00288da0(unit, 0) + 0x18);
            if (dataFlags & 2)
            {
                unit->mdl->flags |= 0x200;
            }
            if (dataFlags & 8)
            {
                unit->mdl->flags |= 0x400;
            }
            if (dataFlags & 0x10)
            {
                unit->mdl->flags |= 0x800;
            }
            break;

        case UNIT_GENUS_PS:
            unit->mdl->flags &= ~0x100;
            dataFlags = func_0017c0e0(unit->charId);
            if (dataFlags & 2)
            {
                unit->mdl->flags |= 0x200;
            }
            else if (dataFlags & 4)
            {
                packet->flags &= ~1;
            }
            if (dataFlags & 8)
            {
                unit->mdl->flags |= 0x400;
            }
            unit->resTypeId = func_003b6180(unit->charId, unit->mdl);
            func_00319230(unit->mdl, 8);
            break;
        }
    }

    unit->flags2 &= ~BTLUNIT_FLAG2_UPDATE;
    unit->flags2 |= BTLUNIT_FLAG2_UPDATE;

    if (packet->flags & 8)
    {
        unit->cols[BTLUNIT_COL_MAIN].a = 0;
    }
    if (packet->flags & 1)
    {
    }
    if (packet->flags & 2)
    {
    }
    if (packet->flags & 0x100)
    {
        unit->mdl->unkData2[0x48] = 0;
        unit->mdl->unkData2[0x49] = 0;
        unit->mdl->unkData2[0x4a] = 0;
    }
    if (packet->flags & 0x40)
    {
        func_002d3e00(unit, 0);
    }
    if (packet->flags & 0x20)
    {
        func_002831c0(unit, 0);
        btlUnitAnimate(unit, unit->unk_9e0, 0, unit->unk_9e4, unit->unk_9e8);

        if (unit->flags2 & BTLUNIT_FLAG2_UPDATE)
        {
            animId = func_00283510(unit, unit->unk_9ce);
            duration = mdlAnimGetDurationInFrameById(unit->mdl, 0, animId);
            animInfo = (const BtlUnitAnimInfo*)unit->unk_9ec;
            if (animId < unit->unk_9d8)
            {
                duration /= (f32)animInfo[animId].speedPercent / 100.0f;
            }
            frame = datCalcRand((u32)duration);
            mdlAnim00318770(unit->mdl, 0, (f32)frame);
        }
    }

    if (packet->cdvd != NULL)
    {
        H_Cdvd_Destroy(packet->cdvd);
    }

    return 1;
}

// FUN_00285670
void btlUnitDestroyModelPacket(void* work)
{
    BtlUnitPacketModel* packet;

    packet = (BtlUnitPacketModel*)work;

    packet->unit->packetCount--;
}

// FUN_00285690
BtlPacket* btlUnitCreateModelPacket(BtlUnit* unit, u16 id, u16 flags)
{
    BtlPacket* packet;
    BtlUnitPacketModel* work;

    packet = btlPacketCreate(0x10f, sizeof(BtlUnitPacketModel));

    packet->unk_47 &= ~(1 << 0);

    packet->initFunc = btlUnitInitModelPacket;
    packet->updateFunc = btlUnitUpdateModelPacket;
    packet->destroyFunc = btlUnitDestroyModelPacket;

    work = (BtlUnitPacketModel*)packet->workData;

    work->unit = unit;
    work->flags = flags;
    work->type = unit->genus + 1;
    work->id = id;

    return packet;
}

// FUN_00285730
void btlUnitInit002857f0Packet(void* work)
{
    BtlUnitPacket002857f0* packet;

    packet = (BtlUnitPacket002857f0*)work;

    packet->unit->packetCount++;
}

// FUN_00285750
u32 btlUnitUpdate002857f0Packet(void* work)
{
    BtlUnitPacket002857f0* packet;
    BtlUnit* unit;

    packet = (BtlUnitPacket002857f0*)work;

    unit = packet->unit;

    if (unit->resTypeId != 0)
    {
        FUN_003b7090(unit->resTypeId);
        unit->resTypeId = 0;
    }
    else
    {
        mdlDestroy(unit->mdl);
    }

    unit->mdl = NULL;

    unit->flags2 &= ~BTLUNIT_FLAG2_UPDATE;

    FUN_00287510(unit);

    return 1;
}

// FUN_002857d0
void btlUnitDestroy002857f0Packet(void* work)
{
    BtlUnitPacket002857f0* packet;

    packet = (BtlUnitPacket002857f0*)work;

    packet->unit->packetCount--;
}

// FUN_002857f0
BtlPacket* btlUnit002857f0(BtlUnit* unit)
{
    BtlPacket* packet;
    BtlUnitPacket002857f0* work;

    packet = btlPacketCreate(0x110, sizeof(BtlUnitPacket002857f0));

    packet->unk_47 &= ~(1 << 0);

    packet->initFunc = btlUnitInit002857f0Packet;
    packet->updateFunc = btlUnitUpdate002857f0Packet;
    packet->destroyFunc = btlUnitDestroy002857f0Packet;

    work = (BtlUnitPacket002857f0*)packet->workData;

    work->unit = unit;

    return packet;
}

// FUN_00285860
void btlUnitInit00285d30Packet(void* work)
{
    BtlUnitPacket00285d30* packet;

    packet = (BtlUnitPacket00285d30*)work;

    packet->unit->packetCount++;
}

// FUN_00285880 NONMATCHING
u32 btlUnitUpdate00285d30Packet(void* work)
{
    BtlUnitPacket00285d30* packet;
    BtlUnit* unit;
    s16 rgbStart;
    s16 rgbDuration;
    s16 alphaStart;
    s16 alphaDuration;
    s16 end;
    f32 factor;
    RwRGBA start;
    RwRGBA target;
    RwRGBA color;

    packet = (BtlUnitPacket00285d30*)work;
    unit = packet->unit;

    switch (packet->mode)
    {
    case 1:
        rgbStart = packet->unk_c + 1;
        rgbDuration = packet->unk_e;
        alphaStart = 0;
        alphaDuration = packet->unk_c;
        end = packet->unk_c + packet->unk_e;
        break;

    case 2:
        rgbStart = 0;
        rgbDuration = packet->unk_e;
        alphaStart = packet->unk_e + 1;
        alphaDuration = packet->unk_c;
        end = packet->unk_c + packet->unk_e;
        break;

    default:
        rgbStart = 0;
        rgbDuration = packet->unk_c;
        alphaStart = 0;
        alphaDuration = packet->unk_e;
        end = packet->unk_c < packet->unk_e ? packet->unk_e : packet->unk_c;
        break;
    }

    if (packet->counter == 0)
    {
        packet->startCol = *(u32*)&unit->cols[BTLUNIT_COL_MAIN];
        if (packet->flags & 1)
        {
            packet->startCol &= 0x00ffffff;
        }
        if (packet->flags & 2)
        {
            packet->startCol = (packet->startCol & 0x00ffffff) | 0xff000000;
        }
        if (packet->flags & 4)
        {
            packet->startCol = 0;
        }
        if (packet->flags & 8)
        {
            packet->startCol = 0xffffffff;
        }
        FUN_00287490(unit);
    }

    start = *(RwRGBA*)&packet->startCol;
    target = *(RwRGBA*)&packet->targetCol;
    color = start;

    if (packet->counter >= rgbStart)
    {
        if (rgbDuration > 0 && packet->counter < rgbStart + rgbDuration)
        {
            factor = (f32)(packet->counter - rgbStart) / (f32)rgbDuration;
        }
        else
        {
            factor = 1.0f;
        }

        color.r = (u8)((1.0f - factor) * start.r + factor * target.r);
        color.g = (u8)((1.0f - factor) * start.g + factor * target.g);
        color.b = (u8)((1.0f - factor) * start.b + factor * target.b);
    }

    if (packet->counter >= alphaStart)
    {
        if (alphaDuration > 0 && packet->counter < alphaStart + alphaDuration)
        {
            factor = (f32)(packet->counter - alphaStart) / (f32)alphaDuration;
        }
        else
        {
            factor = 1.0f;
        }

        color.a = (u8)((1.0f - factor) * start.a + factor * target.a);
    }

    unit->cols[BTLUNIT_COL_MAIN] = color;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;

    if (packet->counter > end)
    {
        return 1;
    }

    packet->counter++;
    return 0;
}

// FUN_00285d10
void btlUnitDestroy00285d30Packet(void* work)
{
    BtlUnitPacket00285d30* packet;

    packet = (BtlUnitPacket00285d30*)work;

    packet->unit->packetCount--;
}

// FUN_00285d30
BtlPacket* btlUnit00285d30(BtlUnit* unit, u32 targetCol, s16 param_3, s16 param_4, u8 mode, u8 flags)
{
    BtlPacket* packet;
    BtlUnitPacket00285d30* work;

    packet = btlPacketCreate(0x112, sizeof(BtlUnitPacket00285d30));

    packet->initFunc = btlUnitInit00285d30Packet;
    packet->updateFunc = btlUnitUpdate00285d30Packet;
    packet->destroyFunc = btlUnitDestroy00285d30Packet;

    work = (BtlUnitPacket00285d30*)packet->workData;

    work->unit = unit;
    work->targetCol = targetCol;
    work->unk_c = param_3;
    work->unk_e = param_4;
    work->mode = mode;
    work->flags = flags;

    return packet;
}

// FUN_00285de0
void btlUnitInit00285e50Packet(void* work)
{
    BtlUnitPacketUnitPtr* packet;

    packet = (BtlUnitPacketUnitPtr*)work;

    packet->unit->packetCount++;
}

// FUN_00285e00
u32 btlUnitUpdate00285e50Packet(void* work)
{
    BtlUnitPacketUnitPtr* packet;

    packet = (BtlUnitPacketUnitPtr*)work;

    FUN_00287490(packet->unit);

    return 1;
}

// FUN_00285e30
void btlUnitDestroy00285e50Packet(void* work)
{
    BtlUnitPacketUnitPtr* packet;

    packet = (BtlUnitPacketUnitPtr*)work;

    packet->unit->packetCount--;
}

// FUN_00285e50
BtlPacket* btlUnit00285e50(BtlUnit* unit)
{
    BtlPacket* packet;
    BtlUnitPacketUnitPtr* work;

    packet = btlPacketCreate(0x113, sizeof(BtlUnitPacketUnitPtr));

    packet->initFunc = btlUnitInit00285e50Packet;
    packet->updateFunc = btlUnitUpdate00285e50Packet;
    packet->destroyFunc = btlUnitDestroy00285e50Packet;

    work = (BtlUnitPacketUnitPtr*)packet->workData;

    work->unit = unit;

    return packet;
}

// FUN_00285eb0
void btlUnitInit00285f20Packet(void* work)
{
    BtlUnitPacketUnitPtr* packet;

    packet = (BtlUnitPacketUnitPtr*)work;

    packet->unit->packetCount++;
}

// FUN_00285ed0
u32 btlUnitUpdate00285f20Packet(void* work)
{
    BtlUnitPacketUnitPtr* packet;

    packet = (BtlUnitPacketUnitPtr*)work;

    FUN_00287510(packet->unit);

    return 1;
}

// FUN_00285f00
void btlUnitDestroy00285f20Packet(void* work)
{
    BtlUnitPacketUnitPtr* packet;

    packet = (BtlUnitPacketUnitPtr*)work;

    packet->unit->packetCount--;
}

// FUN_00285f20
BtlPacket* btlUnit00285f20(BtlUnit* unit)
{
    BtlPacket* packet;
    BtlUnitPacketUnitPtr* work;

    packet = btlPacketCreate(0x114, sizeof(BtlUnitPacketUnitPtr));

    packet->initFunc = btlUnitInit00285f20Packet;
    packet->updateFunc = btlUnitUpdate00285f20Packet;
    packet->destroyFunc = btlUnitDestroy00285f20Packet;

    work = (BtlUnitPacketUnitPtr*)packet->workData;

    work->unit = unit;

    return packet;
}

// FUN_00285f80
void btlUnitInit002860b0Packet(void* work)
{
    BtlUnitPacketUnitPtr* packet;

    packet = (BtlUnitPacketUnitPtr*)work;

    packet->unit->packetCount++;
}

// FUN_00285fa0
u32 btlUnitUpdate002860b0Packet(void* work)
{
    BtlUnitPacketUnitPtr* packet;
    u16 i;
    BtlUnit* unit;
    Model* mdl;
    Model* m;

    packet = (BtlUnitPacketUnitPtr*)work;

    unit = packet->unit;

    if (!(unit->flags2 & BTLUNIT_FLAG2_UPDATE))
    {
        return 1;
    }

    if (unit->mdl == NULL)
    {
        return 1;
    }

    for (i = 0; i < 5; i++)
    {
        mdl = unit->mdl;

        if ((m = mdl)->attachedWpns[i].flags & (1 << 0) &&
            m->attachedWpns[i].wpnMdl != NULL)
        {
            if (mdl00319770(unit->mdl, i))
            {
                (m = unit->mdl)->attachedWpns[i].wpnMdl->flags &= ~(1 << 1);
            }
        }
    }

    return 1;
}

// FUN_00286090
void btlUnitDestroy002860b0Packet(void* work)
{
    BtlUnitPacketUnitPtr* packet;

    packet = (BtlUnitPacketUnitPtr*)work;

    packet->unit->packetCount--;
}

// FUN_002860b0
BtlPacket* btlUnit002860b0(BtlUnit* unit)
{
    BtlPacket* packet;
    BtlUnitPacketUnitPtr* work;

    packet = btlPacketCreate(0x115, sizeof(BtlUnitPacketUnitPtr));

    packet->initFunc = btlUnitInit002860b0Packet;
    packet->updateFunc = btlUnitUpdate002860b0Packet;
    packet->destroyFunc = btlUnitDestroy002860b0Packet;

    work = (BtlUnitPacketUnitPtr*)packet->workData;

    work->unit = unit;

    return packet;
}

// FUN_00286110
void btlUnitInit00286240Packet(void* work)
{
    BtlUnitPacketUnitPtr* packet;

    packet = (BtlUnitPacketUnitPtr*)work;

    packet->unit->packetCount++;
}

// FUN_00286130
u32 btlUnitUpdate00286240Packet(void* work)
{
    BtlUnitPacketUnitPtr* packet;
    u16 i;
    BtlUnit* unit;
    Model* mdl;
    Model* m;

    packet = (BtlUnitPacketUnitPtr*)work;

    unit = packet->unit;

    if (!(unit->flags2 & BTLUNIT_FLAG2_UPDATE))
    {
        return 1;
    }

    if (unit->mdl == NULL)
    {
        return 1;
    }

    for (i = 0; i < 5; i++)
    {
        mdl = unit->mdl;

        if ((m = mdl)->attachedWpns[i].flags & (1 << 0) &&
            m->attachedWpns[i].wpnMdl != NULL)
        {
            if (mdl00319770(unit->mdl, i))
            {
                (m = unit->mdl)->attachedWpns[i].wpnMdl->flags |= (1 << 1);
            }
        }
    }

    return 1;
}

// FUN_00286220
void btlUnitDestroy00286240Packet(void* work)
{
    BtlUnitPacketUnitPtr* packet;

    packet = (BtlUnitPacketUnitPtr*)work;

    packet->unit->packetCount--;
}

// FUN_00286240
BtlPacket* btlUnit00286240(BtlUnit* unit)
{
    BtlPacket* packet;
    BtlUnitPacketUnitPtr* work;

    packet = btlPacketCreate(0x116, sizeof(BtlUnitPacketUnitPtr));

    packet->initFunc = btlUnitInit00286240Packet;
    packet->updateFunc = btlUnitUpdate00286240Packet;
    packet->destroyFunc = btlUnitDestroy00286240Packet;

    work = (BtlUnitPacketUnitPtr*)packet->workData;

    work->unit = unit;

    return packet;
}

// FUN_002862a0
void btlUnit002862a0(void* work)
{
    BtlUnit* unit;

    unit = *(BtlUnit**)work;

    unit->packetCount++;
}

// FUN_002862c0
u32 btlUnit002862c0(void* work)
{
    BtlUnit* unit;

    unit = *(BtlUnit**)work;

    if (unit->unk_9fc != NULL)
    {
        FUN_002bbbc0(unit->unk_9fc);
    }

    return 1;
}

// FUN_00286300
void btlUnit00286300(void* work)
{
    BtlUnit* unit;

    unit = *(BtlUnit**)work;

    unit->packetCount--;
}

// FUN_00286320
BtlPacket* btlUnit00286320(BtlUnit* unit)
{
    BtlPacket* packet;
    BtlUnit** work;

    packet = btlPacketCreate(BTLPACKET_MAKE_ID(BTLPACKET_MODULE_UNIT, 0x1a), sizeof(BtlUnit*));

    packet->initFunc = btlUnit002862a0;
    packet->updateFunc = btlUnit002862c0;
    packet->destroyFunc = btlUnit00286300;

    work = (BtlUnit**)packet->workData;
    *work = unit;

    return packet;
}

// FUN_00287580
u32 btlUnit00287580(BtlUnit* unit)
{
    return !(unit->flags3 & BTLUNIT_FLAG3_UNK1000);
}

// FUN_002875a0
BtlUnit* btlUnitCreate(u8 genus)
{
    BtlUnit* unit;
    u32 id;
    f32 moveScale;

    unit = RwMalloc(sizeof(BtlUnit), rwMEMHINTDUR_GLOBAL);
    memset(unit, 0, sizeof(BtlUnit));

    unit->genus = genus;

    if (sNextId >= 0x0fffffff)
    {
        sNextId = 1;
    }
    id = sNextId;
    sNextId = id + 1;
    unit->id = id;

    func_0027f530(unit);

    unit->unk_8c = 150.0f;
    unit->sphereRadius = 50.0f;
    unit->sphereCenter.x = 0.0f;
    unit->sphereCenter.y = unit->unk_8c * 0.5f;
    unit->sphereCenter.z = 0.0f;
    unit->movementFlags = 0;
    unit->unk_cc = 27.0f;
    if (unit->genus == UNIT_GENUS_PC)
    {
        moveScale = 8.0f;
    }
    else
    {
        moveScale = 14.0f;
    }
    unit->unk_4f4 = 0.5f * moveScale;
    unit->unk_9d4 = 1.0f;
    unit->unk_9f0 = -1;
    unit->unk_9f8 = func_002bbc00(unit);
    unit->unk_9fc = func_002bb7d0();

    unit->prev = NULL;
    if (gBtl->unitLists[genus].head != NULL)
    {
        gBtl->unitLists[genus].head->prev = unit;
        unit->next = gBtl->unitLists[genus].head;
    }
    else
    {
        gBtl->unitLists[genus].tail = unit;
        unit->next = NULL;
    }
    gBtl->unitLists[genus].head = unit;

    return unit;
}

// FUN_002880e0
void btlUnit002880e0(BtlUnit* unit, u8 param_2)
{
    if (unit != NULL && unit->genus == 2)
    {
        *(u8*)&unit->unk_ac = param_2;
    }
}

// FUN_00288170
void btlUnitInitLookAtPacket(void* work)
{
    BtlUnitPacketLookAt* packet;

    packet = (BtlUnitPacketLookAt*)work;

    if (packet->unit != NULL)
    {
        packet->unit->packetCount++;
    }
}

// FUN_00288190
u32 btlUnitUpdateLookAtPacket(void* work)
{
    BtlUnitPacketLookAt* packet;
    Battle* btl;
    BtlUnit* curr;
    BtlUnit* unit;
    f32 maxPitchAngle1;
    f32 maxYawAngle1;
    f32 maxPitchAngle2;
    f32 maxYawAngle2;
    f32 maxPitchArg1;
    f32 maxYawArg1;
    f32 maxPitchArg2;
    f32 maxYawArg2;

    packet = (BtlUnitPacketLookAt*)work;

    if (packet->flags & BTLUNIT_LOOKAT_FLAG_ALLPLAYER)
    {
        btl = gBtl;
        curr = btl->unitLists[UNIT_GENUS_PC].tail;
        while (curr != NULL)
        {
            if (curr->flags3 & BTLUNIT_FLAG3_UNK08)
            {
                if (&maxPitchAngle1 != NULL)
                {
                    maxPitchAngle1 = 70.0f;
                }

                if (&maxYawAngle1 != NULL)
                {
                    maxYawAngle1 = 75.0f;
                }

                maxYawArg1 = maxYawAngle1;
                maxPitchArg1 = maxPitchAngle1;

                if (curr->flags2 & BTLUNIT_FLAG2_UPDATE)
                {
                    mdlLookAtSetMaxAngles(curr->mdl, maxPitchArg1, maxYawArg1);
                }

                if (curr->flags2 & BTLUNIT_FLAG2_UPDATE)
                {
                    mdlLookAtSetBlendRotFactor(curr->mdl, gUnk_007cad7c);
                }

                curr->lookAtMode = BTLUNIT_LOOKAT_MODE_TARGETPOS;
                curr->lookAtTargetPos = packet->targetPos;
                FUN_00287b20((int)curr, 3);
            }

            curr = curr->prev;
        }
    }
    else
    {
        unit = packet->unit;

        if (&maxPitchAngle2 != NULL)
        {
            maxPitchAngle2 = 70.0f;
        }

        if (&maxYawAngle2 != NULL)
        {
            maxYawAngle2 = 75.0f;
        }

        maxYawArg2 = maxYawAngle2;
        maxPitchArg2 = maxPitchAngle2;

        if (unit->flags2 & BTLUNIT_FLAG2_UPDATE)
        {
            mdlLookAtSetMaxAngles(unit->mdl, maxPitchArg2, maxYawArg2);
        }

        if (unit->flags2 & BTLUNIT_FLAG2_UPDATE)
        {
            mdlLookAtSetBlendRotFactor(unit->mdl, gUnk_007cad7c);
        }

        unit->lookAtMode = BTLUNIT_LOOKAT_MODE_TARGETPOS;
        unit->lookAtTargetPos = packet->targetPos;
        FUN_00287b20((int)unit, 3);
    }

    return 1;
}

// FUN_00288340
void btlUnitDestroyLookAtPacket(void* work)
{
    BtlUnitPacketLookAt* packet;

    packet = (BtlUnitPacketLookAt*)work;

    if (packet->unit != NULL)
    {
        packet->unit->packetCount--;
    }
}

// FUN_00288360
BtlPacket* btlUnitCreateLookAtPacket(BtlUnit* unit, const RwV3d* targetPos, u16 flags)
{
    BtlPacket* packet;
    BtlUnitPacketLookAt* work;

    packet = btlPacketCreate(BTLUNIT_PACKET_LOOKAT, sizeof(BtlUnitPacketLookAt));
    
    packet->initFunc = btlUnitInitLookAtPacket;
    packet->updateFunc = btlUnitUpdateLookAtPacket;
    packet->destroyFunc = btlUnitDestroyLookAtPacket;

    work = (BtlUnitPacketLookAt*)packet->workData;

    work->unit = unit;
    work->flags = flags;
    work->targetPos = *targetPos;

    return packet;
}

// FUN_00288400
void btlUnitInitLookAtUnitPacket(void* work)
{
    BtlUnitPacketLookAtUnit* packet;

    packet = (BtlUnitPacketLookAtUnit*)work;

    if (packet->unit != NULL)
    {
        packet->unit->packetCount++;
    }

    packet->targetUnit->packetCount++;
}

// FUN_00288430 NONMATCHING
u32 btlUnitUpdateLookAtUnitPacket(void* work)
{
    BtlUnit* curr;
    BtlUnit* targetUnit;
    BtlUnitPacketLookAtUnit* packet;
    Battle* btl;
    BtlUnit* unit;
    f32 maxPitchAngle1;
    f32 maxYawAngle1;
    f32 maxPitchAngle2;
    f32 maxYawAngle2;
    f32 maxPitchAngle3;
    f32 maxYawAngle3;
    f32 maxPitchArg1;
    f32 maxYawArg1;
    f32 maxPitchArg2;
    f32 maxYawArg2;
    f32 maxPitchArg3;
    f32 maxYawArg3;



    packet = (BtlUnitPacketLookAtUnit*)work;

    if ((packet->flags & (BTLUNIT_LOOKAT_FLAG_ALLPLAYER | BTLUNIT_LOOKAT_FLAG_ALLENEMY)) != 0)
    {
        if (packet->flags & BTLUNIT_LOOKAT_FLAG_ALLPLAYER)
        {
            btl = gBtl;
            curr = btl->unitLists[UNIT_GENUS_PC].tail;
            while (curr != NULL)
            {
                if (curr->flags3 & BTLUNIT_FLAG3_UNK08)
                {
                    targetUnit = packet->targetUnit;
                    if (&maxPitchAngle1 != NULL)
                    {
                        maxPitchAngle1 = 70.0f;
                    }

                    if (&maxYawAngle1 != NULL)
                    {
                        maxYawAngle1 = 75.0f;
                    }

                    maxYawArg1 = maxYawAngle1;
                    maxPitchArg1 = maxPitchAngle1;

                    if (curr->flags2 & BTLUNIT_FLAG2_UPDATE)
                    {
                        mdlLookAtSetMaxAngles(curr->mdl, maxPitchArg1, maxYawArg1);
                    }

                    if (curr->flags2 & BTLUNIT_FLAG2_UPDATE)
                    {
                        mdlLookAtSetBlendRotFactor(curr->mdl, gUnk_007cad7c);
                    }

                    curr->lookAtMode = BTLUNIT_LOOKAT_MODE_TARGETUNIT;
                    curr->lookAtTargetId = targetUnit->id;
                }

                curr = curr->prev;
            }
        }

        if (packet->flags & BTLUNIT_LOOKAT_FLAG_ALLENEMY)
        {
            btl = gBtl;
            curr = btl->unitLists[UNIT_GENUS_EC].tail;
            while (curr != NULL)
            {
                if (curr->flags3 & BTLUNIT_FLAG3_UNK08)
                {
                    targetUnit = packet->targetUnit;
                    if (&maxPitchAngle2 != NULL)
                    {
                        maxPitchAngle2 = 70.0f;
                    }

                    if (&maxYawAngle2 != NULL)
                    {
                        maxYawAngle2 = 75.0f;
                    }

                    maxYawArg2 = maxYawAngle2;
                    maxPitchArg2 = maxPitchAngle2;

                    if (curr->flags2 & BTLUNIT_FLAG2_UPDATE)
                    {
                        mdlLookAtSetMaxAngles(curr->mdl, maxPitchArg2, maxYawArg2);
                    }

                    if (curr->flags2 & BTLUNIT_FLAG2_UPDATE)
                    {
                        mdlLookAtSetBlendRotFactor(curr->mdl, gUnk_007cad7c);
                    }

                    curr->lookAtMode = BTLUNIT_LOOKAT_MODE_TARGETUNIT;
                    curr->lookAtTargetId = targetUnit->id;
                }

                curr = curr->prev;
            }
        }
    }
    else
    {
        targetUnit = packet->targetUnit;
        unit = packet->unit;
        if (&maxPitchAngle3 != NULL)
        {
            maxPitchAngle3 = 70.0f;
        }

        if (&maxYawAngle3 != NULL)
        {
            maxYawAngle3 = 75.0f;
        }

        maxYawArg3 = maxYawAngle3;
        maxPitchArg3 = maxPitchAngle3;

        if (unit->flags2 & BTLUNIT_FLAG2_UPDATE)
        {
            mdlLookAtSetMaxAngles(unit->mdl, maxPitchArg3, maxYawArg3);
        }

        if (unit->flags2 & BTLUNIT_FLAG2_UPDATE)
        {
            mdlLookAtSetBlendRotFactor(unit->mdl, gUnk_007cad7c);
        }

        unit->lookAtMode = BTLUNIT_LOOKAT_MODE_TARGETUNIT;
        unit->lookAtTargetId = targetUnit->id;
    }

    return 1;
}

// FUN_002886b0
void btlUnitDestroyLookAtUnitPacket(void* work)
{
    BtlUnitPacketLookAtUnit* packet;

    packet = (BtlUnitPacketLookAtUnit*)work;

    if (packet->unit != NULL)
    {
        packet->unit->packetCount--;
    }

    packet->targetUnit->packetCount--;
}

// FUN_002886e0
BtlPacket* btlUnitCreateLookAtUnitPacket(BtlUnit* unit, BtlUnit* targetUnit, u16 flags)
{
    BtlPacket* packet;
    BtlUnitPacketLookAtUnit* work;

    packet = btlPacketCreate(BTLUNIT_PACKET_LOOKATUNIT, sizeof(BtlUnitPacketLookAtUnit));

    packet->initFunc = btlUnitInitLookAtUnitPacket;
    packet->updateFunc = btlUnitUpdateLookAtUnitPacket;
    packet->destroyFunc = btlUnitDestroyLookAtUnitPacket;

    work = (BtlUnitPacketLookAtUnit*)packet->workData;

    work->unit = unit;
    work->targetUnit = targetUnit;
    work->flags = flags;

    return packet;
}

// FUN_00288760
void btlUnitInitLookAtDeactivatePacket(void* work)
{
    BtlUnitPacketLookAtDeactivate* packet;

    packet = (BtlUnitPacketLookAtDeactivate*)work;

    if (packet->unit != NULL)
    {
        packet->unit->packetCount++;
    }
}

// FUN_00288780
u32 btlUnitUpdateLookAtDeactivatePacket(void* work)
{
    BtlUnitPacketLookAtDeactivate* packet;
    Battle* btl;
    BtlUnit* curr;
    BtlUnit* unit;

    packet = (BtlUnitPacketLookAtDeactivate*)work;

    if (packet->flags & (BTLUNIT_LOOKAT_FLAG_ALLPLAYER | BTLUNIT_LOOKAT_FLAG_ALLENEMY))
    {
        if (packet->flags & BTLUNIT_LOOKAT_FLAG_ALLPLAYER)
        {
            btl = gBtl;
            curr = btl->unitLists[UNIT_GENUS_PC].tail;
            while (curr != NULL)
            {
                if (curr->flags3 & BTLUNIT_FLAG3_UNK08 && 
                    curr->flags2 & BTLUNIT_FLAG2_UPDATE)
                {
                    mdlLookAtSetBlendRotFactor(curr->mdl, gUnk_007cad7c);
                    mdlLookAtSetMaxAngles(curr->mdl, 70.0f, 75.0f);
                    mdlLookAtDisableTarget(curr->mdl);

                    curr->lookAtMode = BTLUNIT_LOOKAT_MODE_NONE;
                }

                curr = curr->prev;
            }
        }

        if (packet->flags & BTLUNIT_LOOKAT_FLAG_ALLENEMY)
        {
            btl = gBtl;
            curr = btl->unitLists[UNIT_GENUS_EC].tail;
            while (curr != NULL)
            {
                if (curr->flags3 & BTLUNIT_FLAG3_UNK08 && 
                    curr->flags2 & BTLUNIT_FLAG2_UPDATE)
                {
                    mdlLookAtSetBlendRotFactor(curr->mdl, gUnk_007cad7c);
                    mdlLookAtSetMaxAngles(curr->mdl, 70.0f, 75.0f);
                    mdlLookAtDisableTarget(curr->mdl);

                    curr->lookAtMode = BTLUNIT_LOOKAT_MODE_NONE;
                }

                curr = curr->prev;
            }
        }
    }
    else
    {
        unit = packet->unit;
        if (unit->flags2 & BTLUNIT_FLAG2_UPDATE)
        {
            mdlLookAtSetBlendRotFactor(unit->mdl, gUnk_007cad7c);
            mdlLookAtSetMaxAngles(unit->mdl, 70.0f, 75.0f);
            mdlLookAtDisableTarget(unit->mdl);

            unit->lookAtMode = BTLUNIT_LOOKAT_MODE_NONE;
        }
    }

    return 1;
}

// FUN_00288930
void btlUnitDestroyLookAtDeactivatePacket(void* work)
{
    BtlUnitPacketLookAtDeactivate* packet;

    packet = (BtlUnitPacketLookAtDeactivate*)work;

    if (packet->unit != NULL)
    {
        packet->unit->packetCount--;
    }
}

// FUN_00288950
BtlPacket* btlUnitCreateLookAtDeactivatePacket(BtlUnit* unit, u16 flags)
{
    BtlPacket* packet;
    BtlUnitPacketLookAtDeactivate* work;

    packet = btlPacketCreate(BTLUNIT_PACKET_LOOKATDEACTIVATE, sizeof(BtlUnitPacketLookAtDeactivate));

    packet->initFunc = btlUnitInitLookAtDeactivatePacket;
    packet->updateFunc = btlUnitUpdateLookAtDeactivatePacket;
    packet->destroyFunc = btlUnitDestroyLookAtDeactivatePacket;

    work = (BtlUnitPacketLookAtDeactivate*)packet->workData;

    work->unit = unit;
    work->flags = flags;

    return packet;
}

// FUN_002889c0 NONMATCHING
void btlUnitInitFromCharId(BtlUnit* unit, u16 id)
{
    const BtlUnitAnimBounds* bounds;
    const u8* data;
    s16 scale;

    unit->charId = id;

    switch (unit->genus)
    {
    case UNIT_GENUS_PC:
        unit->datUnit->id = id;
        datUnitInit(unit->datUnit, UNIT_GENUS_PC, id);
        break;

    case UNIT_GENUS_EC:
    case UNIT_GENUS_PS:
        unit->datUnit->id = id;
        break;
    }

    bounds = func_00288da0(unit, 0);
    data = (const u8*)bounds;

    unit->sphereCenter.x = bounds->centerX;
    unit->sphereCenter.y = bounds->centerY;
    unit->sphereCenter.z = bounds->centerZ;
    unit->unk_8c = bounds->unk_6;
    unit->sphereRadius = bounds->radius;

    switch (unit->genus)
    {
    case UNIT_GENUS_PC:
        scale = *(const s16*)(data + 0x14);
        unit->unk_9ec = (void*)(data + 0x24);
        unit->unk_9d8 = id == 1 ? 0x1a : 0x17;
        break;

    case UNIT_GENUS_EC:
        scale = *(const s16*)(data + 0x14);
        unit->unk_9ec = (void*)(data + 0x2a);
        unit->unk_9d8 = 0x13;
        break;

    case UNIT_GENUS_PS:
        scale = *(const s16*)(data + 0x16);
        unit->unk_9ec = (void*)(data + 0x18);
        unit->unk_9d8 = 6;
        break;

    default:
        return;
    }

    unit->scale = (f32)scale / 100.0f;
    unit->flags2 |= BTLUNIT_FLAG2_DIRTY;
    func_002bcde0(unit, &unit->unkData8);
}

// FUN_00288f80
void btlUnitInitPersona(BtlUnit* unit, u16 personaId)
{
    if (unit->personaUnit == NULL)
    {
        unit->personaUnit = btlUnitCreate(UNIT_GENUS_PS);
    }

    btlUnitInitFromCharId(unit->personaUnit, personaId);
}

// FUN_00289030
BtlUnit* btlUnitFindFromId(u16 id)
{
    u32 i;
    Battle* btl;
    u32 _id;
    BtlUnitList* list;
    BtlUnit* curr;

    i = 0;
    btl = gBtl;
    _id = id;
    for (; i < UNIT_GENUS_MAX; i++)
    {
        list = &btl->unitLists[i];
        curr = list->tail;
        while (curr != NULL)
        {
            if (curr->id == _id)
            {
                return curr;
            }

            curr = curr->prev;
        }
    }

    return NULL;
}
/* Data tables used by the retail animation and character helpers. */
extern const u8 DAT_00693290[];
extern const u8 DAT_006932e0[];
extern const u8 iGpffffb718[];
extern const u8 iGpffffb71c[];
extern const u8 iGpffffb728[];
extern const u8 iGpffffb73c[];
extern const u16 gp0xffff9828[];
extern const u8 DAT_007ce400[];

extern u16 func_002fb860(void);
extern void* func_00308c60(DatUnit* unit);
extern s16 func_003082f0(DatUnit* unit, u16 id);
extern long func_002d6370(u64 id);
extern f32 func_00318910(Model* mdl, u32 slot, s16 id);
extern void func_002d4040(BtlUnit* unit);
extern void func_001a0dc0(u16 resTypeId, u32 enable);
extern u32 func_0031c7e0(Model* model);
extern u32 func_0031ebe0(void* data);
extern void func_002bbd00(void* data);
extern void func_002bb8f0(void* data);
extern void func_002b7000(BtlUnit* unit, s8 slot, u32 value);
extern f32 func_004c6ac0(const RwV3d* value);
extern void* func_00174800(u64 id);
extern u32 func_0030b5a0(DatUnit* unit, u32 flag);
extern void func_002f9c10(BtlAction* action);


// FUN_00283510
s16 func_00283510(BtlUnit* unit, s32 id)
{
    s16 result;
    const u8* row;

    switch (unit->genus)
    {
    case UNIT_GENUS_PC:
    case UNIT_GENUS_PS:
        goto resolve;
    default:
        break;
    }
    switch (unit->genus)
    {
    case UNIT_GENUS_EC:
        break;
    default:
        goto zero;
    }
    result = (s16)func_002fb860();
    if (result != -1)
    {
        return result;
    }

resolve:
    row = DAT_00693290 + (u32)unit->genus * 26;
    result = row[(u32)id & 0xffff];
    return result;

zero:
    return 0;
}
// FUN_002835E0
s16 func_002835e0(BtlUnit* unit, s16 id, f32 scale)
{
    s16 animId;
    s16 tableId;
    const u8* row;
    const BtlUnitAnimInfo* info;
    u32 offset;

    switch (unit->genus)
    {
    case UNIT_GENUS_PC:
    case UNIT_GENUS_PS:
        goto resolve;
    default:
        break;
    }
    switch (unit->genus)
    {
    case UNIT_GENUS_EC:
        break;
    default:
        goto zero;
    }
    animId = (s16)func_002fb860();
    switch (animId)
    {
    case -1:
        goto resolve;
    default:
        break;
    }
    goto resolved;

resolve:
    row = DAT_00693290 + (u32)unit->genus * 26;
    tableId = row[(u16)id];
    goto tableResolved;

zero:
    animId = 0;
    goto resolved;

tableResolved:
    animId = tableId;

resolved:
    if (animId < unit->unk_9d8)
    {
        offset = animId * sizeof(*info);
        info = (const BtlUnitAnimInfo*)(offset + (u32)unit->unk_9ec);
        return (s16)((f32)info->unk_0 /
                     (scale * ((f32)info->speedPercent / 100.0f)));
    }
    return 0;
}

// FUN_00283750
s16 func_00283750(BtlUnit* unit, s16 id, f32 scale)
{
    s16 animId;
    s16 tableId;
    const u8* row;
    const BtlUnitAnimInfo* info;
    s16 frames;
    u32 offset;

    switch (unit->genus)
    {
    case UNIT_GENUS_PC:
    case UNIT_GENUS_PS:
        goto resolve;
    default:
        break;
    }
    switch (unit->genus)
    {
    case UNIT_GENUS_EC:
        break;
    default:
        goto zero;
    }
    animId = (s16)func_002fb860();
    switch (animId)
    {
    case -1:
        goto resolve;
    default:
        break;
    }
    goto resolved;

resolve:
    row = DAT_00693290 + (u32)unit->genus * 26;
    tableId = row[(u16)id];
    goto tableResolved;

zero:
    animId = 0;
    goto resolved;

tableResolved:
    animId = tableId;

resolved:
    if (animId < unit->unk_9d8)
    {
        offset = animId * sizeof(*info);
        info = (const BtlUnitAnimInfo*)(offset + (u32)unit->unk_9ec);
        frames = info->unk_4;
        if (frames < 0)
        {
            return 0;
        }
        return (s16)((f32)frames /
                     (scale * ((f32)info->speedPercent / 100.0f)));
    }
    return 0;
}

// FUN_002838D0
s16 func_002838d0(BtlUnit* unit, u16 id, f32 scale)
{
    s16 animId;
    s16 tableId;
    const u8* row;
    f32 duration;
    const BtlUnitAnimInfo* info;
    u32 infoOffset;

    if (!(unit->flags2 & BTLUNIT_FLAG2_UPDATE))
    {
        return 0;
    }

    switch (unit->genus)
    {
    case UNIT_GENUS_PC:
    case UNIT_GENUS_PS:
        goto resolve;
    default:
        break;
    }
    switch (unit->genus)
    {
    case UNIT_GENUS_EC:
        break;
    default:
        goto zero;
    }
    animId = (s16)func_002fb860();
    switch (animId)
    {
    case -1:
        goto resolve;
    default:
        break;
    }
    goto resolved;

resolve:
    row = DAT_00693290 + (u32)unit->genus * 26;
    tableId = row[id];
    goto tableResolved;

zero:
    animId = 0;
    goto resolved;

tableResolved:
    animId = tableId;

resolved:
    duration = func_00318910(unit->mdl, 0, animId);
    if (animId < unit->unk_9d8)
    {
        info = (const BtlUnitAnimInfo*)unit->unk_9ec;
        infoOffset = (u32)(animId * sizeof(*info));
        infoOffset += (u32)info;
        info = (const BtlUnitAnimInfo*)infoOffset;
        duration /= scale * ((f32)info->speedPercent / 100.0f);
        return (s16)duration;
    }

    return (s16)duration;
}

// FUN_00283A70
s16 func_00283a70(BtlUnit* unit, s32 id)
{
    s16 animId;
    s16 tableId;
    const u8* row;
    const BtlUnitAnimInfo* info;
    u32 infoOffset;

    if (!(unit->flags2 & BTLUNIT_FLAG2_UPDATE))
    {
        return 6;
    }

    switch (unit->genus)
    {
    case UNIT_GENUS_PC:
    case UNIT_GENUS_PS:
        goto resolve;
    default:
        break;
    }
    switch (unit->genus)
    {
    case UNIT_GENUS_EC:
        break;
    default:
        goto zero;
    }
    animId = (s16)func_002fb860();
    switch (animId)
    {
    case -1:
        goto resolve;
    default:
        break;
    }
    goto resolved;

resolve:
    row = DAT_00693290 + (u32)unit->genus * 26;
    tableId = row[(u32)id & 0xffff];
    goto tableResolved;

zero:
    animId = 0;
    goto resolved;

tableResolved:
    animId = tableId;

resolved:
    if (animId < unit->unk_9d8)
    {
        info = (const BtlUnitAnimInfo*)unit->unk_9ec;
        infoOffset = (u32)(animId * sizeof(*info));
        infoOffset += (u32)info;
        info = (const BtlUnitAnimInfo*)infoOffset;
        return info->unk_8;
    }
    return 6;
}

// FUN_00283C50
void func_00283c50(f32 speed, BtlUnit* unit)
{
    if (unit->flags2 & BTLUNIT_FLAG2_UPDATE)
    {
        unit->unk_9d4 = speed;
    }
}

static s16 btlUnitAnimCategory(const BtlUnit* unit, s16 id)
{
    if (unit->genus == UNIT_GENUS_EC)
    {
        if (id == 4 || id == 5 || id == 6)
        {
            return 0;
        }
        return -1;
    }

    if (id == 4)
    {
        return 0;
    }
    if (id == 5)
    {
        return 1;
    }
    if (id == 6)
    {
        return 2;
    }
    return -1;
}

// FUN_00283C70 NONMATCHING
u16 func_00283c70(BtlUnit* unit, u16 id)
{
    s16 category;
    u16 charId;
    u32 unitId;
    const u8* table;

    category = btlUnitAnimCategory(unit, (s16)id);
    if (category < 0)
    {
        return 1;
    }

    charId = unit->charId;
    if (unit->genus == UNIT_GENUS_EC)
    {
        table = iGpffffb728 + ((u32)charId * 0x1d + charId) * 8 + 0x1a;
        return *(const u16*)(table + category * 4);
    }

    if (charId == 4)
    {
        return gp0xffff9828[id];
    }

    if (charId == 1)
    {
        unitId = (u32)(uintptr_t)func_00308c60(unit->datUnit);
        table = iGpffffb718 + (unitId & 0xff) * 0x128 + 0x18;
    }
    else
    {
        table = iGpffffb71c + ((u32)charId * 0x10a) + 0x18;
    }

    return *(const u16*)(table + category * 4);
}

// FUN_00283E40 NONMATCHING
u16 func_00283e40(BtlUnit* unit, s16 id)
{
    s16 category;
    u16 charId;
    u32 unitId;
    const u8* table;

    category = btlUnitAnimCategory(unit, id);
    if (category < 0)
    {
        return 0;
    }

    charId = unit->charId;
    if (unit->genus == UNIT_GENUS_EC)
    {
        table = iGpffffb728 + ((u32)charId * 0x1d + charId) * 8 + 0x1c;
        return *(const u16*)(table + category * 4);
    }

    if (charId == 1)
    {
        unitId = (u32)(uintptr_t)func_00308c60(unit->datUnit);
        table = iGpffffb718 + (unitId & 0xff) * 0x128 + 0x1a;
    }
    else
    {
        table = iGpffffb71c + ((u32)charId * 0x10a) + 0x1a;
    }

    return *(const u16*)(table + category * 4);
}

// FUN_00283FE0
const void* func_00283fe0(BtlUnit* unit, u32 id)
{
    if (unit->genus == UNIT_GENUS_EC)
    {
        return NULL;
    }

    switch (unit->charId)
    {
        case 4:
            return DAT_006932e0 + ((id & 0xffff) - 4) * 8;

        default:
            return NULL;
    }
}

// FUN_00284040 NONMATCHING
u32 func_00284040(u64 unused, BtlUnit* unit, u64 id, s64 param_4)
{
    s16 skillId;
    u16 flags;
    s16 type;

    (void)unused;
    skillId = (s16)id;
    if (skillId == -1 || skillId >= 0x1d0)
    {
        return 1;
    }
    if (func_002d6370(id) != 0)
    {
        flags = *(const u16*)(DAT_007ce400 + 2 + (u32)skillId * 0x1c);
        if (flags & 0x200)
        {
            return 0;
        }
        if (param_4 == 0 || !(flags & 1))
        {
            return 1;
        }
        return 2;
    }
    type = func_003082f0(unit->datUnit, (u16)id);
    if (type == 0x11 || type == 0x10)
    {
        return 1;
    }
    return 3;
}

typedef struct BtlUnitPacketResource
{
    BtlUnit* unit;
    u16 type;
    u16 id;
    u16 flags;
    u8 unkData[2];
    u32 state;
} BtlUnitPacketResource;

// FUN_00286380
void func_00286380(void* work)
{
    BtlUnitPacketResource* packet;
    BtlUnit* unit;

    packet = (BtlUnitPacketResource*)work;
    unit = packet->unit;
    unit->packetCount++;
    if (!(packet->flags & 0x10))
    {
        if (*(void**)unit->mdl->runtimeData.animationData == NULL)
        {
            func_0031c7e0(unit->mdl);
        }
        packet->state = 1;
    }
}

// FUN_002863F0
u32 func_002863f0(void* work)
{
    BtlUnitPacketResource* packet;
    BtlUnit* unit;

    packet = (BtlUnitPacketResource*)work;
    unit = packet->unit;
    if (packet->state == 0)
    {
        if (*(void**)unit->mdl->runtimeData.animationData == NULL)
        {
            func_0031c7e0(unit->mdl);
        }
        packet->state = 1;
    }
    else if (func_0031ebe0(unit->mdl->runtimeData.animationData))
    {
        return 1;
    }
    return 0;
}

// FUN_00286480
void btlUnitDestroyResourcePacket(void* work)
{
    BtlUnitPacketResource* packet;

    packet = (BtlUnitPacketResource*)work;
    packet->unit->packetCount--;
}

// FUN_002864A0
BtlPacket* func_002864a0(BtlUnit* unit, u16 id, u16 flags)
{
    BtlPacket* packet;
    BtlUnitPacketResource* work;

    packet = btlPacketCreate(0x111, sizeof(BtlUnitPacketResource));
    packet->unk_47 &= ~(1 << 0);
    packet->initFunc = func_00286380;
    packet->updateFunc = func_002863f0;
    packet->destroyFunc = btlUnitDestroyResourcePacket;

    work = (BtlUnitPacketResource*)packet->workData;
    work->unit = unit;
    work->flags = flags;
    work->type = unit->genus + 1;
    work->id = id;
    work->state = 0;
    return packet;
}

// FUN_00286540 NONMATCHING
void func_00286540(void)
{
    u32 genus;
    BtlUnit* unit;

    if (gBtl == NULL)
    {
        return;
    }

    for (genus = 0; genus < UNIT_GENUS_MAX; genus++)
    {
        unit = gBtl->unitLists[genus].head;
        while (unit != NULL)
        {
            func_00280da0(unit);
            func_002826d0(unit);
            if ((unit->flags2 & BTLUNIT_FLAG2_UPDATE) &&
                unit->mdl != NULL)
            {
                mdlSetColor(unit->mdl, &unit->cols[BTLUNIT_COL_MAIN]);
                mdl00317730(unit->mdl);
                func_002d4040(unit);
                unit->flags2 &= ~BTLUNIT_FLAG2_DIRTY;
            }
            unit = unit->next;
        }
    }
}
extern void func_00287ea0(BtlUnit* unit);
extern u32 DAT_007cc970;
void FUN_002878d0(BtlUnit* unit);
extern void func_002d3fe0(BtlUnit* unit);
extern void mdl00319050(Model* mdl);
extern void mdl00319070(Model* mdl);
extern void mdl003191b0(Model* mdl);
extern u32 func_0017d800(void);
extern void* func_00198580(void);
extern void* func_003b54c0(void* value);
extern void* func_003b5d50(u32 value);
extern void func_004944b0(void* dst, const void* src);
extern void func_004cb7f0(void* dst, const void* src, u32 mode);
extern u32 func_004c9d10(void* value);
extern void func_004c9d00(void* value);
extern void func_004d7f60(u32 group, u32 value);
extern void func_003294d0(void);
extern void func_00329550(void);
extern void func_00358460(const RwRGBA* color, u32 mode);
extern u32 func_00198560(void);
extern u32 func_00198570(void);
extern u32 func_00198590(void);
extern void func_00317a20(Model* mdl);

extern void* DAT_0096017c[];
static void btlUnitUnlinkAndFree(BtlUnit* unit)
{
    BtlUnitList* list;

    list = &gBtl->unitLists[unit->genus];
    if (unit->prev != NULL)
    {
        unit->prev->next = unit->next;
    }
    else
    {
        list->head = unit->next;
    }
    if (unit->next != NULL)
    {
        unit->next->prev = unit->prev;
    }
    else
    {
        list->tail = unit->prev;
    }
    RwFree(unit);
}

// FUN_00287400
void func_00287400(void)
{
    u32 genus;
    BtlUnit* unit;

    for (genus = 0; genus < UNIT_GENUS_MAX; genus++)
    {
        unit = *(BtlUnit**)((u8*)gBtl + 0x154 + (genus << 3));
        while (unit != NULL)
        {
            if (unit->flags2 & BTLUNIT_FLAG2_UPDATE)
            {
                func_00287ea0(unit);
            }
            unit = unit->prev;
        }
    }
}

// FUN_00287490
void FUN_00287490(BtlUnit* unit)
{
    unit->flags3 &= ~BTLUNIT_FLAG3_UNK1000;
    FUN_00287cf0(unit, 5);
    if (unit->resTypeId != 0)
    {
        func_001a0dc0(unit->resTypeId, 1);
        unit->flags3 &= ~BTLUNIT_FLAG3_UNK02;
    }
    else
    {
        unit->flags3 |= BTLUNIT_FLAG3_UNK02;
    }
}

// FUN_00287510
void FUN_00287510(BtlUnit* unit)
{
    unit->flags3 |= BTLUNIT_FLAG3_UNK1000;
    FUN_00287cf0(unit, 5);
    if (unit->resTypeId != 0)
    {
        func_001a0dc0(unit->resTypeId, 0);
    }
    unit->flags3 &= ~BTLUNIT_FLAG3_UNK02;
}


// FUN_00287740
void func_00287740(BtlUnit* unit)
{
    s32 category;

    if (unit->resTypeId != 0)
    {
        category = (unit->resTypeId & 0xffc00) >> 10;
        func_003b7090(unit->resTypeId);
        if (unit->mdl != NULL)
        {
            FUN_00287cf0(unit, 4);
            FUN_00287cf0(unit, 1);
            FUN_00287cf0(unit, 2);
            FUN_00287cf0(unit, 3);
            mdlSetColor(unit->mdl, (const RwRGBA*)&DAT_007cc970);
            mdlAnimSetSpeed(unit->mdl, 0, 1.0f);
            if (category == 1 && !(unit->flags2 & (1 << 3)))
            {
                mdlDestroy(unit->mdl);
            }
        }
        unit->resTypeId = 0;
    }
    else
    {
        if (unit->mdl != NULL)
        {
            mdlDestroy(unit->mdl);
        }
    }
    unit->mdl = NULL;
    unit->flags2 &= ~BTLUNIT_FLAG2_UPDATE;
}

// FUN_00287860
void func_00287860(BtlUnit* unit)
{
    func_00287740(unit);
    if (unit->personaUnit != NULL)
    {
        FUN_002878d0(unit->personaUnit);
    }
    if (unit->unk_9f8 != NULL)
    {
        func_002bbd00(unit->unk_9f8);
        unit->unk_9f8 = NULL;
    }
    if (unit->unk_9fc != NULL)
    {
        func_002bb8f0(unit->unk_9fc);
        unit->unk_9fc = NULL;
    }
}

// FUN_002878D0
void FUN_002878d0(BtlUnit* unit)
{
    u8 genus;

    genus = unit->genus;
    func_00287740(unit);
    if (unit->personaUnit != NULL)
    {
        FUN_002878d0(unit->personaUnit);
    }
    if (unit->unk_9f8 != NULL)
    {
        func_002bbd00(unit->unk_9f8);
        unit->unk_9f8 = NULL;
    }
    if (unit->unk_9fc != NULL)
    {
        func_002bb8f0(unit->unk_9fc);
        unit->unk_9fc = NULL;
    }
    func_002d3fe0(unit);
    if (unit->unk_9f0 >= 0)
    {
        func_002b7000(unit, unit->unk_9f0, 0);
    }
    if (unit->next != NULL)
    {
        unit->next->prev = unit->prev;
    }
    else
    {
        gBtl->unitLists[genus].tail = unit->prev;
    }
    if (unit->prev != NULL)
    {
        unit->prev->next = unit->next;
    }
    else
    {
        gBtl->unitLists[genus].head = unit->next;
    }
    ((void (*)(void*))DAT_0096017c[0])(unit);
}

// FUN_002879F0
void func_002879f0(void)
{
    BtlUnit* unit;
    BtlUnit* next;
    u32 genus;
    u8 unitGenus;

    for (genus = 0; genus < UNIT_GENUS_MAX; genus++)
    {
        unit = *(BtlUnit**)((u8*)gBtl + 0x150 + (genus << 3));
        while (unit != NULL)
        {
            next = unit->next;
            unitGenus = unit->genus;
            func_00287860(unit);
            func_002d3fe0(unit);
            if (unit->unk_9f0 >= 0)
            {
                func_002b7000(unit, unit->unk_9f0, 0);
            }
            if (unit->next != NULL)
            {
                unit->next->prev = unit->prev;
            }
            else
            {
                *(BtlUnit**)((u8*)gBtl + 0x154 + ((u32)unitGenus << 3)) = unit->prev;
            }
            if (unit->prev != NULL)
            {
                unit->prev->next = unit->next;
            }
            else
            {
                *(BtlUnit**)((u8*)gBtl + 0x150 + ((u32)unitGenus << 3)) = unit->next;
            }
            ((void (*)(void*))DAT_0096017c[0])(unit);
            unit = next;
        }
    }
}
/* Recovered battle-misc harvest: 0x00287EA0-0x00289650 */
// FUN_00287EA0


void FUN_00287ea0(BtlUnit* unit)
{
    BtlUnit* target;
    RwV3d targetPos;
    RwV3d scaledCenter;
    RwV3d transformedCenter;
    u32 updateFlag;
    s16 state;

    updateFlag = unit->flags2 & BTLUNIT_FLAG2_UPDATE;
    if (updateFlag == 0)
    {
        return;
    }

    if (updateFlag != 0)
    {
        state = unit->unk_9ce;
    }
    else
    {
        state = 0;
    }

    switch (state)
    {
        case 0:
            goto state_zero;

        case 16:
            if (mdlLookAtIsActive(unit->mdl)) {
                mdlLookAtDisableTarget(unit->mdl);
            }
            return;
        default:
            if (mdlLookAtIsActive(unit->mdl)) {
                mdl003191b0(unit->mdl);
                mdlLookAtDisableTarget(unit->mdl);
            }
            return;
    }

state_zero:
    if (unit->lookAtMode == 0 ||
        unit->mdl->animSlots[0].anim.blendFactor < 1.0f ||
        (mdlLookAtGetFlags(unit->mdl) & MDLLOOKAT_FLAG_UNK200))
    {
        goto done;
    }

    switch (unit->lookAtMode)
    {
        case 1:
            goto target_position;
        case 2:
            goto target_unit;
        default:
            goto done;
    }

target_position:
    mdlLookAtSetTargetPosXYZ(unit->mdl, &unit->lookAtTargetPos);
    goto done;

target_unit:
    if (unit->lookAtTargetId == 0)
    {
        goto done;
    }

    target = btlUnitFindFromId((u16)unit->lookAtTargetId);
    if (target != NULL && target != unit)
    {
        scaledCenter.x = target->sphereCenter.x * target->scale;
        scaledCenter.y = target->sphereCenter.y * target->scale;
        scaledCenter.z = target->sphereCenter.z * target->scale;
        RtQuatTransformVectors(&transformedCenter, &scaledCenter, 1, &target->rot);
        targetPos.x = transformedCenter.x + target->pos.x;
        targetPos.y = transformedCenter.y + target->pos.y;
        targetPos.z = transformedCenter.z + target->pos.z;
        targetPos.y = DAT_007cb0cc * (target->unk_8c * target->scale) +
                      targetPos.y + 0.0f;
        mdlLookAtSetTargetPosXYZ(unit->mdl, &targetPos);
        goto done;
    }

    mdlLookAtDisableTarget(unit->mdl);
    unit->lookAtTargetId = 0;

done:
    return;
}

// FUN_00288110


void FUN_00288110(BtlUnit* unit)
{
    s32 result;

    if ((unit->flags2 & BTLUNIT_FLAG2_UPDATE) != 0 &&
        (result = FUN_003191d0(unit->mdl)) != 0)
    {
        FUN_003191b0(unit->mdl);
        FUN_00319190(unit->mdl);
    }
}

// FUN_00288DA0 NONMATCHING


int FUN_00288da0(int param_1,short param_2)



{

  u8 bVar1;

  char cVar2;

  int iVar3;

  u32 uVar4;

  

  uVar4 = (u32)*(u16 *)(param_1 + 0xa4);

  bVar1 = param_2 != 9;

  cVar2 = *(char *)(param_1 + 0xa2);

  if (cVar2 == '\x02') {

    iVar3 = (int)(uintptr_t)(iGpffffb73c + uVar4 * 0x58 + 2);

  }

  else if (cVar2 == '\x01') {

    iVar3 = (int)(uintptr_t)func_002fc410(
        (BtlUnit*)(uintptr_t)param_1);

    if (iVar3 == 0) {

      if (bVar1) {

        iVar3 = (int)(uintptr_t)(iGpffffb728 + uVar4 * 0xe8);

      }

      else {

        iVar3 = (int)(uintptr_t)(iGpffffb728 + uVar4 * 0xe8 + 10);

      }

    }

  }

  else if (cVar2 == '\0') {

    if (uVar4 == 1) {

      uVar4 = FUN_00308c60(*(u32 *)(param_1 + 0xa2c));

      if (bVar1) {

        iVar3 = (int)(uintptr_t)(iGpffffb718 + (uVar4 & 0xff) * 0x128);

      }

      else {

        iVar3 = (int)(uintptr_t)(iGpffffb718 + (uVar4 & 0xff) * 0x128 + 10);

      }

    }

    else if (bVar1) {

      iVar3 = (int)(uintptr_t)(iGpffffb71c + uVar4 * 0x10a);

    }

    else {

      iVar3 = (int)(uintptr_t)(iGpffffb71c + uVar4 * 0x10a + 10);

    }

  }

  else {

    iVar3 = 0;

  }

  return iVar3;

}

// FUN_00288FE0


BtlUnit* FUN_00288fe0(u16 genus, u16 charId)
{
    BtlUnit* unit;
    u32 targetCharId;

    unit = gBtl->unitLists[genus].tail;
    targetCharId = charId;
    while (unit != NULL)
    {
        if (unit->charId == targetCharId)
        {
            return unit;
        }
        unit = unit->prev;
    }

    return NULL;
}

typedef struct BtlUnitSortEntry
{
    u8 unk_0[0x128];
    Model* mdl;
} BtlUnitSortEntry;

// FUN_002890A0


int FUN_002890a0(BtlUnitSortEntry** param_1, BtlUnitSortEntry** param_2)
{
    RwV3d firstDelta;
    RwV3d secondDelta;
    RwV3d cameraPos;
    RwMatrix* matrix;
    BtlUnitSortEntry* first;
    BtlUnitSortEntry* second;
    f32 firstDistance;

    matrix = RwFrameGetLTM((RwFrame*)kwlnGetMainCamera()->object.object.parent);
    cameraPos = matrix->pos;

    first = *param_1;
    second = *param_2;

    firstDelta.x = mdlGetMatrix(first->mdl)->pos.x - cameraPos.x;
    firstDelta.y = mdlGetMatrix(first->mdl)->pos.y - cameraPos.y;
    firstDelta.z = mdlGetMatrix(first->mdl)->pos.z - cameraPos.z;

    secondDelta.x = mdlGetMatrix(second->mdl)->pos.x - cameraPos.x;
    secondDelta.y = mdlGetMatrix(second->mdl)->pos.y - cameraPos.y;
    secondDelta.z = mdlGetMatrix(second->mdl)->pos.z - cameraPos.z;

    firstDistance = RwV3dLength(&firstDelta);
    return (int)(firstDistance - RwV3dLength(&secondDelta));
}

// FUN_002891E0 NONMATCHING


void FUN_002891e0(void)



{

  u16 uVar1;

  u32 uVar2;

  u32 uVar3;

  u8 bVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  u64 uVar8;

  long lVar9;

  u32 *puVar10;

  u32 *puVar11;

  int iVar12;

  u32 auStack_f0 [16];

  u32 auStack_b0 [16];

  u32 uStack_70;

  u32 uStack_6c;

  u32 uStack_68;

  u32 uStack_64;

  u32 uStack_60;

  u32 uStack_5c;

  u32 uStack_58;

  u32 uStack_54;

  u32 uStack_50;

  u32 uStack_4c;

  u32 uStack_48;

  u32 uStack_44;

  int aiStack_40 [15];

  u8 uStack_4;

  u8 uStack_3;

  u8 uStack_2;

  u8 uStack_1;

  

  iVar12 = 0;

  for (iVar6 = 0; iVar6 < 2; iVar6 = iVar6 + 1) {

    for (iVar7 = *(int *)(iGpffffb6fc + iVar6 * 8 + 0x154); iVar7 != 0;

        iVar7 = *(int *)(iVar7 + 0xa30)) {

      if ((((*(u32 *)(iVar7 + 0x9c) & 0x800) != 0) && (*(short *)(iVar7 + 0x9f2) != 0)) &&

         (iVar5 = FUN_003b54c0(*(u32 *)(iGpffffa850 + 8)), (*(u32 *)(iVar5 + 0x28) & 2) == 0

         )) {

        aiStack_40[iVar12] = iVar5;

        iVar12 = iVar12 + 1;

      }

    }

  }

  if (iVar12 != 0) {

    bVar4 = 1;

    iVar6 = FUN_00198560();

    uStack_50 = *(u32 *)(iVar6 + 0x18);

    uStack_4c = *(u32 *)(iVar6 + 0x1c);

    uStack_48 = *(u32 *)(iVar6 + 0x20);

    uStack_44 = *(u32 *)(iVar6 + 0x24);

    iVar6 = FUN_00198570();

    uStack_60 = *(u32 *)(iVar6 + 0x18);

    uStack_5c = *(u32 *)(iVar6 + 0x1c);

    uStack_58 = *(u32 *)(iVar6 + 0x20);

    uStack_54 = *(u32 *)(iVar6 + 0x24);

    iVar6 = FUN_00198570();

    puVar11 = (u32 *)(*(int *)(iVar6 + 4) + 0x10);

    puVar10 = auStack_b0;

    iVar6 = 8;

    do {

      uVar2 = *puVar11;

      uVar3 = puVar11[1];

      puVar11 = puVar11 + 2;

      iVar6 = iVar6 + -1;

      *puVar10 = uVar2;

      puVar10[1] = uVar3;

      puVar10 = puVar10 + 2;

    } while (0 < iVar6);

    iVar6 = FUN_00198580();

    uStack_70 = *(u32 *)(iVar6 + 0x18);

    uStack_6c = *(u32 *)(iVar6 + 0x1c);

    uStack_68 = *(u32 *)(iVar6 + 0x20);

    uStack_64 = *(u32 *)(iVar6 + 0x24);

    iVar6 = FUN_00198580();

    puVar11 = (u32 *)(*(int *)(iVar6 + 4) + 0x10);

    puVar10 = auStack_f0;

    iVar6 = 8;

    do {

      uVar2 = *puVar11;

      uVar3 = puVar11[1];

      puVar11 = puVar11 + 2;

      iVar6 = iVar6 + -1;

      *puVar10 = uVar2;

      puVar10[1] = uVar3;

      puVar10 = puVar10 + 2;

    } while (0 < iVar6);

    FUN_005225f8(aiStack_40,iVar12,4,0x2890a0);

    iVar6 = FUN_003b5d50(4);

    uVar8 = FUN_00198560();

    FUN_004944b0(uVar8,iVar6 + 0x100);

    uVar8 = FUN_00198580();

    FUN_004944b0(uVar8,iVar6 + 0x110);

    iVar7 = FUN_00198580();

    FUN_004cb7f0(*(u32 *)(iVar7 + 4),iVar6 + 0x120,0);

    while (iVar12 = iVar12 + -1, -1 < iVar12) {

      iVar6 = aiStack_40[iVar12];

      uVar8 = FUN_00198570();

      FUN_004944b0(uVar8,iVar6 + 400);

      iVar7 = FUN_00198570();

      FUN_004cb7f0(*(u32 *)(iVar7 + 4),iVar6 + 0x1a0,0);

      uVar8 = FUN_00198590();

      lVar9 = FUN_004c9d10(uVar8);

      if (lVar9 != 0) {

        if (bVar4) {

          FUN_004d7f60(2,0x44);

          FUN_004d7f60(3,0x717fb);

          (*DAT_00960090)(7,2);

          (*DAT_00960090)(0xe,0);

          (*DAT_00960090)(6,0);

          (*DAT_00960090)(8,0);

          (*DAT_00960090)(9,2);

          (*DAT_00960090)(0xc,1);

          (*DAT_00960090)(1,0);

          FUN_003294d0();

          uStack_4 = 0;

          uStack_3 = 0;

          uStack_2 = 0;

          uStack_1 = 0xff;

          FUN_00358460(&uStack_4,0);

          FUN_00329550();

          bVar4 = 0;

        }

        uVar1 = *(u16 *)(*(int *)(iVar6 + 0x128) + 0x418);

        FUN_00319230(*(int *)(iVar6 + 0x128),3);

        FUN_00317a20(*(u32 *)(iVar6 + 0x128));

        FUN_00319230(*(u32 *)(iVar6 + 0x128),uVar1);

        uVar8 = FUN_00198590();

        FUN_004c9d00(uVar8);

      }

    }

    uVar8 = FUN_00198560();

    FUN_004944b0(uVar8,&uStack_50);

    uVar8 = FUN_00198580();

    FUN_004944b0(uVar8,&uStack_70);

    uVar8 = FUN_00198570();

    FUN_004944b0(uVar8,&uStack_60);

    iVar12 = FUN_00198580();

    FUN_004cb7f0(*(u32 *)(iVar12 + 4),auStack_f0,0);

    iVar12 = FUN_00198570();

    FUN_004cb7f0(*(u32 *)(iVar12 + 4),auStack_b0,0);

  }

  return;

}

// FUN_00289650 NONMATCHING


u64 FUN_00289650(short param_1,u32 param_2,long param_3)



{

  u32 uVar1;

  int iVar2;

  long lVar3;

  int iVar4;

  u64 unaff_s1;

  u64 uVar5;

  

  uVar5 = 0;

  if (param_1 == 1) {

    unaff_s1 = FUN_002875a0();

    uVar5 = FUN_00299e90();

    FUN_00299e70(uVar5,unaff_s1);

    FUN_0029a2c0(uVar5);

    FUN_00299e30(uVar5);

    FUN_00299d60(uVar5,1);

  }

  else if (param_1 == 0) {

    unaff_s1 = FUN_002875a0(0);

    uVar5 = FUN_00299e90();

    FUN_00299e70(uVar5,unaff_s1);

    FUN_0029a2c0(uVar5);

    FUN_00299e30(uVar5);

    FUN_00299d60(uVar5,1);

    iVar4 = (int)uVar5;

    if ((param_2 & 0xffff) == 1) {

      *(u16 *)(iVar4 + 0x14) = 5;

      *(int *)(iGpffffb6fc + 0x148) = iVar4;

    }

    iVar2 = FUN_00174800(param_2);

    FUN_00288f80(unaff_s1,*(u16 *)(iVar2 + 2));

    *(u16 *)(iVar4 + 0x1a) = *(u16 *)(iVar4 + 0x1a) | 0x10;

  }

  iVar4 = (int)unaff_s1;

  if (param_3 != 0) {

    *(int *)(iVar4 + 0xa2c) = (int)param_3;

    FUN_002889c0(unaff_s1,param_2 & 0xffff);

    lVar3 = FUN_0030b5a0(param_3,0);

    if (lVar3 != 0) {

      *(u32 *)(iVar4 + 0x9c) = *(u32 *)(iVar4 + 0x9c) | 1;

    }

  }

  iVar2 = (int)uVar5;

  *(u32 *)(*(int *)(iVar2 + 0x30) + 0x9c) = *(u32 *)(*(int *)(iVar2 + 0x30) + 0x9c) | 8;

  *(u16 *)(iVar2 + 0x1a) = *(u16 *)(iVar2 + 0x1a) | 8;

  if ((param_1 != 1) && (param_1 == 0)) {

    uVar1 = *(u32 *)(iVar4 + 0x9c);

    *(u32 *)(iVar4 + 0x9c) = uVar1 | 0x20;

    *(u32 *)(iVar4 + 0x9c) = uVar1 | 0x60;

    *(u32 *)(iVar4 + 0x9c) = uVar1 | 0xe0;

    *(u32 *)(iVar4 + 0x9c) = uVar1 | 0x2e0;

  }

  FUN_002f9c10(uVar5);

  return uVar5;

}

/* Recovered battle-misc harvest: 0x00287B20-0x00287CF0 */
// FUN_00287B20 NONMATCHING


void FUN_00287b20(int param_1,short param_2)



{

  u16 uVar1;

  u32 uVar2;

  short sVar3;

  u32 uVar4;

  

  uVar4 = *(u32 *)(param_1 + 0x98) & 2;

  if (uVar4 != 0) {

    if (param_2 == 4) {

      *(u16 *)(*(int *)(param_1 + 0x9f4) + 0x3fe) =

           *(u16 *)(*(int *)(param_1 + 0x9f4) + 0x3fe) | 0x10;

    }

    else if (param_2 == 3) {

      uVar1 = FUN_00319200(*(u32 *)(param_1 + 0x9f4));

      FUN_003191f0(*(u32 *)(param_1 + 0x9f4),uVar1 | 0x1000);

      uVar1 = FUN_00319200(*(u32 *)(param_1 + 0x9f4));

      FUN_003191f0(*(u32 *)(param_1 + 0x9f4),uVar1 | 0x2000);

      uVar2 = FUN_00319200(*(u32 *)(param_1 + 0x9f4));

      FUN_003191f0(*(u32 *)(param_1 + 0x9f4),uVar2 & 0xf7ff);

    }

    else if (param_2 == 2) {

      FUN_00319050(*(u32 *)(param_1 + 0x9f4));

    }

    else if (param_2 == 1) {

      FUN_00319010(*(u32 *)(param_1 + 0x9f4));

      *(u32 *)(*(int *)(param_1 + 0x9f4) + 0x39c) = DAT_007cad78;

      *(u32 *)(*(int *)(param_1 + 0x9f4) + 0x3a0) =

           *(u32 *)(*(int *)(param_1 + 0x9f4) + 0x39c);

      *(u32 *)(*(int *)(param_1 + 0x9f4) + 0x3a4) = 0x3f800000;

    }

    else if ((((param_2 == 5) && ((*(u32 *)(param_1 + 0x9c) & 0x800) == 0)) &&

             (*(short *)(param_1 + 0x9f2) != 0)) && ((*(u32 *)(param_1 + 0x9c) & 8) != 0)) {

      if (uVar4 == 0) {

        sVar3 = 0;

      }

      else {

        sVar3 = *(short *)(param_1 + 0x9ce);

      }

      if (sVar3 != 0x12) {

        FUN_001a0dc0(*(short *)(param_1 + 0x9f2),0);

        *(u32 *)(param_1 + 0x9c) = *(u32 *)(param_1 + 0x9c) | 0x800;

      }

    }

  }

  return;

}

// FUN_00287CF0


void FUN_00287cf0(BtlUnit* unit, u16 mode)
{
    u16 flags;

    if (!(unit->flags2 & BTLUNIT_FLAG2_UPDATE))
    {
        return;
    }

    switch (mode)
    {
        case 5:
            if ((unit->flags3 & BTLUNIT_FLAG3_UNK800) && unit->resTypeId != 0)
            {
                func_001a0dc0(unit->resTypeId, !(unit->flags3 & BTLUNIT_FLAG3_UNK1000));
                unit->flags3 &= ~BTLUNIT_FLAG3_UNK800;
            }
            break;

        case 1:
            mdlDisableFullShadow(unit->mdl);
            unit->mdl->unk_388 &= 0xe2;
            break;

        case 2:
            mdl00319070(unit->mdl);
            break;

        case 3:
            mdlLookAtSetBlendRotFactor(unit->mdl, DAT_007cada4);
            mdlLookAtSetMaxAngles(unit->mdl, 70.0f, 80.0f);
            mdl003191b0(unit->mdl);
            mdlLookAtDisableTarget(unit->mdl);
            flags = mdlLookAtGetFlags(unit->mdl);
            mdlLookAtSetFlags(unit->mdl, flags & ~0x2000);
            flags = mdlLookAtGetFlags(unit->mdl);
            mdlLookAtSetFlags(unit->mdl, flags & ~0x1000);
            unit->lookAtMode = 0;
            break;

        case 4:
            unit->mdl->runtimeData.animationFields.unk_0e &= ~0x10;
            break;
    }
}
