#include "Battle/btlUnit.h"
#include "Battle/btlPacket.h"
#include "Battle/battle.h"
#include "Graphics/Model/mdlManager.h"
#include "Main/Battle/Data/datUnit.h"
#include "Graphics/Model/mdlFile.h"
#include "h_cdvd.h"

static u32 sNextId = 1; // 007cc51c

static f32 gUnk_007cad7c = 0.3f; // 007cad7c. No idea where to put this

RwV3d gUnk_00957188; // 00957188

BtlPacket* btlUnitCreateResNullifiedAnimPacket(BtlUnit* unit, f32 param_2);
BtlPacket* btlUnit00284900(BtlUnit* unit, s32 param_2);
BtlPacket* btlUnitCreateEnmDodgeAnimPacket(BtlUnit* unit, s32 unused);
void FUN_00287490(BtlUnit* unit);
void FUN_00287510(BtlUnit* unit);
void FUN_00287b20(BtlUnit* unit, s16 param_2);
void FUN_003b7090(u16 resTypeId);
void FUN_002bbbc0(void* param);
void FUN_00287cf0(BtlUnit* unit, s16 param_2);

// 12 bytes
typedef struct BtlUnitPacketResNullifiedAnim
{
    BtlUnit* unit; // 0x00
    f32 unk_4;     // 0x04
    u8 unkData[4];
} BtlUnitPacketResNullifiedAnim;

void btlUnitInitResNullifiedAnimPacket(void* work);
u32 btlUnitUpdateResNullifiedAnimPacket(void* work);
void btlUnitDestroyResNullifiedAnimPacket(void* work);

// 24 bytes
typedef struct BtlUnitPacket00284900
{
    u8 unkData1[0x0c];
    BtlUnit* unit; // 0x0c
    s16 unk_10;    // 0x10
    s16 unk_12;    // 0x12
    u8 unkData2[0x04];
} BtlUnitPacket00284900;

void btlUnitInit00284900Packet(void* work);
u32 btlUnitUpdate00284900Packet(void* work);
void btlUnitDestroy00284900Packet(void* work);

// 16 bytes
typedef struct BtlUnitPacketEnmDodgeAnim
{
    BtlUnit* unit; // 0x00
    s32 unk_4;     // 0x04
    u8 unkData[0x08];
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
    // TODO
}

// FUN_0027f930
s32 btlUnit0027f930(s32 param_1)
{
    return param_1 + 0x4e;
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

    return true;
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

// FUN_002813f0
u32 btlUnitUpdateMovePacket(void* work)
{
    // TODO

    return false;
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

// FUN_00281ad0
u32 btlUnitUpdateMoveToUnitPacket(void* work)
{
    // TODO

    return false;
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
        return true;
    }

    packet->timer++;

    return false;
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

// FUN_002823b0
u32 btlUnitUpdateRotateTowardUnitPacket(void* work)
{
    // TODO

    return false;
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

    return false;
}

// FUN_00282d40
void btlUnitAnimate(BtlUnit* unit, s32 id, u16 blendFrameCount, f32 speed, u16 mode)
{
    // TODO
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

    return true;
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

// FUN_00284350 NONMATCHING
u32 btlUnitUpdate002843e0Packet(void* work)
{
    BtlUnitPacket002843e0* packet;
    BtlUnit* unit;
    s16 frame;

    packet = (BtlUnitPacket002843e0*)work;

    unit = packet->unit;

    if (unit->flags2 & BTLUNIT_FLAG2_UPDATE)
    {
        frame = unit->unk_9ce;
    }
    else
    {
        frame = 0;
    }

    if (unit->unk_9e0 != frame)
    {
        btlUnitAnimate(unit, unit->unk_9e0, packet->unk_4, unit->unk_9e4, unit->unk_9e8);
    }

    return true;
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
    // TODO

    return false;
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
    // TODO

    return false;
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

// FUN_002849a0
u32 btlUnitUpdateEnmDodgeAnimPacket(void* work)
{
    // TODO

    return false;
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

    return false;
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

    return true;
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

        FUN_00287b20(unit, 4);
    }

    return true;
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
            mdlFile0031d530(packet->type, packet->id, path);
            packet->cdvd = H_Cdvd_Request(path, 0);
            unit->flags2 |= BTLUNIT_FLAG2_UNK01;
        }

        unit->flags2 &= ~BTLUNIT_FLAG2_UPDATE;
    }
}

// FUN_002850f0
u32 btlUnitUpdateModelPacket(void* work)
{
    // TODO

    return false;
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

    return true;
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

// FUN_00285880
u32 btlUnitUpdate00285d30Packet(void* work)
{
    // TODO

    return false;
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

    return true;
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

    return true;
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

// FUN_00285fa0 NONMATCHING
u32 btlUnitUpdate002860b0Packet(void* work)
{
    BtlUnitPacketUnitPtr* packet;
    u16 i;
    BtlUnit* unit;

    packet = (BtlUnitPacketUnitPtr*)work;

    unit = packet->unit;

    if (!(unit->flags2 & BTLUNIT_FLAG2_UPDATE))
    {
        return true;
    }

    if (unit->mdl == NULL)
    {
        return true;
    }

    for (i = 0; i < 5; i++)
    {
        if (unit->mdl->attachedWpns[i].flags & (1 << 0) &&
            unit->mdl->attachedWpns[i].wpnMdl != NULL)
        {
            if (mdl00319770(unit->mdl, i))
            {
                unit->mdl->attachedWpns[i].wpnMdl->flags &= ~(1 << 1);
            }
        }
    }

    return true;
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

// FUN_00286130 NONMATCHING
u32 btlUnitUpdate00286240Packet(void* work)
{
    BtlUnitPacketUnitPtr* packet;
    u16 i;
    BtlUnit* unit;

    packet = (BtlUnitPacketUnitPtr*)work;

    unit = packet->unit;

    if (!(unit->flags2 & BTLUNIT_FLAG2_UPDATE))
    {
        return true;
    }

    if (unit->mdl == NULL)
    {
        return true;
    }

    for (i = 0; i < 5; i++)
    {
        if (unit->mdl->attachedWpns[i].flags & (1 << 0) &&
            unit->mdl->attachedWpns[i].wpnMdl != NULL)
        {
            if (mdl00319770(unit->mdl, i))
            {
                unit->mdl->attachedWpns[i].wpnMdl->flags |= (1 << 1);
            }
        }
    }

    return true;
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

    return true;
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
    // TODO

    return NULL;
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
                FUN_00287b20(curr, 3);
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
        FUN_00287b20(unit, 3);
    }

    return true;
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
                    FUN_00287b20(curr, 3);
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
                    FUN_00287b20(curr, 3);
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
        FUN_00287b20(unit, 3);
    }

    return true;
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

    return true;
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

// FUN_002889c0
void btlUnitInitFromCharId(BtlUnit* unit, u16 id)
{
    // TODO
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