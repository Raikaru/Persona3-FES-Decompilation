#ifndef BTLUNIT_H
#define BTLUNIT_H

#include "Utils.h"
#include "Battle/btlPacket.h"
#include "rw/rtquat.h"

#define BTLUNIT_FLAG_FADE (1 << 0) // 0x01

#define BTLUNIT_FLAG2_UNK01  (1 << 0)  // 0x01
#define BTLUNIT_FLAG2_UPDATE (1 << 1)  // 0x02
#define BTLUNIT_FLAG2_DIRTY  (1 << 2)  // 0x04

#define BTLUNIT_FLAG3_DEAD   (1 << 0) // 0x01
#define BTLUNIT_FLAG3_UNK02  (1 << 1) // 0x02
#define BTLUNIT_FLAG3_UNK08  (1 << 3) // 0x08
#define BTLUNIT_FLAG3_ENDURE (1 << 4) // 0x10
#define BTLUNIT_FLAG3_UNK40  (1 << 6) // 0x40
#define BTLUNIT_FLAG3_UNK1000 (1 << 12) // 0x1000
#define BTLUNIT_FLAG3_UNK800 (1 << 11) // 0x800
#define BTLUNIT_FLAG3_NOROT  (1 << 13) // 0x2000
#define BTLUNIT_FLAG3_UNK400 (1 << 10) // 0x400

#define BTLUNIT_MOVEMENTFLAGS_MOVE   (1 << 0) // 0x01
#define BTLUNIT_MOVEMENTFLAGS_ROTATE (1 << 1) // 0x02

#define BTLUNIT_LOOKAT_FLAG_ALLPLAYER (1 << 0) // 0x01
#define BTLUNIT_LOOKAT_FLAG_ALLENEMY  (1 << 1) // 0x02

#define BTLUNIT_POSROTCOL_FLAG_SETPOS (1 << 0) // 0x01
#define BTLUNIT_POSROTCOL_FLAG_SETROT (1 << 1) // 0x02
#define BTLUNIT_POSROTCOL_FLAG_SETCOL (1 << 2) // 0x04  

typedef struct DatUnit DatUnit;
typedef struct Model Model;
typedef struct BtlPacket BtlPacket;

// TODO
typedef enum
{
    BTLUNIT_COL_MAIN,

    BTLUNIT_COL_MAX = 5
} BtlUnitColor;

typedef enum
{
    BTLUNIT_LOOKAT_MODE_NONE,
    BTLUNIT_LOOKAT_MODE_TARGETPOS,
    BTLUNIT_LOOKAT_MODE_TARGETUNIT
} BtlUnitLookAtMode;

typedef struct BtlUnit BtlUnit;
typedef struct BtlUnitAnimBounds
{
    s16 centerX;
    s16 centerY;
    s16 centerZ;
    u16 unk_6;
    u16 radius;
} BtlUnitAnimBounds;


// 2616 bytes
struct BtlUnit
{
    u16 flags;                    // 0x00. See 'BTLUNIT_FLAG_*'
    RwV3d pos;                    // 0x04
    RwV3d posOffset;              // 0x10
    RtQuat rot;                   // 0x1c
    f32 scale;                    // 0x2c
    RwRGBA cols[BTLUNIT_COL_MAX]; // 0x30
    u8 unk_44[0x08];
    u16 unk_4c;
    u8 unk_4e[0x06];
    RwV3d unk_54;
    u8 unk_60[0x10];
    RtQuat unk_70;
    RwV3d sphereCenter;           // 0x80
    f32 unk_8c;                   // 0x8c
    f32 sphereRadius;             // 0x90
    s16 unk_94;                   // 0x94
    s16 unk_96;                   // 0x96
    u32 flags2;                   // 0x98. Temp name. See 'BTLUNIT_FLAG2_*'
    u32 flags3;                   // 0x9c. Temp name. See 'BTLUNIT_FLAG3_*'
    u16 packetCount;              // 0xa0
    u8 genus;                     // 0xa2. See enum 'UnitGenus'
    u16 charId;                   // 0xa4
    u32 id;                       // 0xa8
    s32 unk_ac;                   // 0xac
    u16 lookAtMode;               // 0xb0. See enum 'BtlUnitLookAtMode'
    u32 lookAtTargetId;           // 0xb4
    RwV3d lookAtTargetPos;        // 0xb8
    u32 unk_c4;                   // 0xc4
    u16 movementFlags;            // 0xc8. See 'BTLUNIT_MOVEMENTFLAGS_*'
    u8 unkData2[0x02];
    f32 unk_cc;                   // 0xcc
    RwV3d targetRot;              // 0xd0
    RwV3d unk_dc;                 // 0xdc
    s32 unk_e8;                   // 0xe8
    RwV3d unk_ec;                 // 0xec
    f32 unk_f8;                   // 0xf8
    u8 unkData5[0x3f0];
    s16 unk_4ec;                  // 0x4ec
    u8 unkData5a[0x02];
    u8 unk_4f0;                   // 0x4f0
    u8 unkData5b[0x03];
    f32 unk_4f4;                  // 0x4f4
    s32 unk_4f8;                  // 0x4f8
    u8 unkData6[0x4d0];
    u16 unk_9cc;                  // 0x9cc
    s16 unk_9ce;                  // 0x9ce
    u16 unk_9d0;                  // 0x9d0
    f32 unk_9d4;                  // 0x9d4
    u16 unk_9d8;                  // 0x9d8
    s16 unk_9da;                  // 0x9da
    s16 unk_9dc;                  // 0x9dc
    u8 unkData6b[0x02];
    s16 unk_9e0;                  // 0x9e0
    s16 unk_9e2;                  // 0x9e2
    f32 unk_9e4;                  // 0x9e4
    s8 unk_9e8;                   // 0x9e8
    u8 unkData6c[0x03];
    void* unk_9ec;                // 0x9ec
    s8 unk_9f0;                   // 0x9f0
    u8 unk_9f1;
    u16 resTypeId;                // 0x9f2
    Model* mdl;                   // 0x9f4
    void* unk_9f8;                // 0x9f8
    void* unk_9fc;                // 0x9fc
    BtlUnit* personaUnit;         // 0xa00
    u8 unkData8[0x28];
    DatUnit* datUnit;             // 0xa2c
    BtlUnit* prev;                // 0xa30
    BtlUnit* next;                // 0xa34
};

// TODO
typedef enum
{
    BTLUNIT_PACKET_ANIM = BTLPACKET_MAKE_ID(BTLPACKET_MODULE_UNIT, 0),
    BTLUNIT_PACKET_MOVE = BTLPACKET_MAKE_ID(BTLPACKET_MODULE_UNIT, 10),
    BTLUNIT_PACKET_MOVETOUNIT = BTLPACKET_MAKE_ID(BTLPACKET_MODULE_UNIT, 11),
    BTLUNIT_PACKET_ROTATE = BTLPACKET_MAKE_ID(BTLPACKET_MODULE_UNIT, 13),
    BTLUNIT_PACKET_ROTATETOWARDUNIT = BTLPACKET_MAKE_ID(BTLPACKET_MODULE_UNIT, 14),
    BTLUNIT_PACKET_LOOKAT = BTLPACKET_MAKE_ID(BTLPACKET_MODULE_UNIT, 23),
    BTLUNIT_PACKET_LOOKATUNIT = BTLPACKET_MAKE_ID(BTLPACKET_MODULE_UNIT, 24),
    BTLUNIT_PACKET_LOOKATDEACTIVATE = BTLPACKET_MAKE_ID(BTLPACKET_MODULE_UNIT, 25),
    BTLUNIT_PACKET_POSROTCOL = BTLPACKET_MAKE_ID(BTLPACKET_MODULE_UNIT, 27)
} BtlUnitPacket;

// TODO
typedef enum
{
    BTLUNIT_ANIM_ENMDODGE = -4,
    BTLUNIT_ANIM_RESNULLIFIED = -2,
    BTLUNIT_ANIM_IDLEWEAPON = 16,

    BTLUNIT_ANIM_MAX = 26
} BtlUnitAnim;

// TODO
typedef enum
{
    BTLUNIT_ANIM_MODE_ONCE,
    BTLUNIT_ANIM_MODE_LOOP
} BtlUnitAnimMode;

// 16 bytes
typedef struct BtlUnitPacketAnim
{
    BtlUnit* unit;       // 0x00
    s16 id;              // 0x04. See enum 'BtlUnitAnim'
    u16 blendFrameCount; // 0x06
    f32 speed;           // 0x08
    u16 mode;            // 0x0c. See enum 'BtlUnitAnimMode'
} BtlUnitPacketAnim;

// 36 bytes
typedef struct BtlUnitPacketMove
{
    BtlUnit* unit;    // 0x00
    RwV3d targetPos;  // 0x04 
    u32 flags;        // 0x10
    u16 state;        // 0x14
    u8 unkData[0x02];
    u32 timer;        // 0x18
    f32 unk_1c;       // 0x1c
    f32 speed;        // 0x20
} BtlUnitPacketMove;

// 40 bytes
typedef struct BtlUnitPacketMoveToUnit
{
    BtlUnitPacketMove move; // 0x00
    BtlUnit* targetUnit;    // 0x24
} BtlUnitPacketMoveToUnit;

// 24 bytes
typedef struct BtlUnitPacketRotate
{
    BtlUnit* unit; // 0x00
    RwV3d rot;     // 0x04
    u32 flags;     // 0x10
    u32 timer;     // 0x14
} BtlUnitPacketRotate;

// 16 bytes
typedef struct BtlUnitPacketRotateTowardUnit
{
    BtlUnit* unit;       // 0x00
    BtlUnit* targetUnit; // 0x04
    u32 flags;           // 0x08
    u32 timer;           // 0x0c
} BtlUnitPacketRotateTowardUnit;

// 20 bytes
typedef struct BtlUnitPacketLookAt
{
    BtlUnit* unit;   // 0x00
    RwV3d targetPos; // 0x04
    u16 flags;       // 0x10. See 'BTLUNIT_LOOKAT_FLAG_*'
} BtlUnitPacketLookAt;

// 12 bytes
typedef struct BtlUnitPacketLookAtUnit
{
    BtlUnit* unit;       // 0x00
    BtlUnit* targetUnit; // 0x04
    u16 flags;           // 0x08. See 'BTLUNIT_LOOKAT_FLAG_*'
} BtlUnitPacketLookAtUnit;

// 8 bytes
typedef struct BtlUnitPacketLookAtDeactivate
{
    BtlUnit* unit; // 0x00
    u16 flags;     // 0x04. See 'BTLUNIT_LOOKAT_FLAG_*'
} BtlUnitPacketLookAtDeactivate;

// 40 bytes
typedef struct BtlUnitPacketPosRotCol
{
    BtlUnit* unit; // 0x00
    RwV3d pos;     // 0x04
    RtQuat rot;    // 0x10
    RwRGBA col;    // 0x20
    u16 flags;     // 0x24. See 'BTLUNIT_POSROTCOL_FLAG_*'
} BtlUnitPacketPosRotCol;

extern RwV3d gUnk_00957188;

void btlUnitSetPos(BtlUnit* unit, const RwV3d* pos);
void btlUnitSetRot(BtlUnit* unit, const RtQuat* rot);
void btlUnitSetRotFromMat(BtlUnit* unit, const RwMatrix* mat);
void btlUnitSetScale(BtlUnit* unit, f32 scale);
void btlUnitSetColor(BtlUnit* unit, RwRGBA col);
void btlUnitSetFlags(BtlUnit* unit, u16 flags);
void btlUnitClearFlags(BtlUnit* unit, u16 flags);
void btlUnit0027f7c0(BtlUnit* unit, RwV3d* param_2, RwV3d* parm_3, RwV3d* param_4);
void btlUnitGetSphereWorldCenter(BtlUnit* unit, RwV3d* dst);
u32 btlUnitIsMoving(BtlUnit* unit);
void btlUnitStopMoving(BtlUnit* unit);
void btlUnitStopRotating(BtlUnit* unit);
BtlUnit* btlUnitCreate(u8 genus);
u32 btlUnit00282c60(BtlUnit* unit);
void btlUnitAnimate(BtlUnit* unit, s32 id, u16 blendFrameCount, f32 speed, u16 mode);
s16 btlUnitGetAnimFrame(BtlUnit* unit);
void btlUnitInitFromCharId(BtlUnit* unit, u16 id);
void btlUnitInitPersona(BtlUnit* unit, u16 personaId);
BtlUnit* FUN_00288fe0(u16 genus, u16 charId);
BtlUnit* btlUnitFindFromId(u16 id);

BtlPacket* btlUnitCreateAnimPacket(BtlUnit* unit, u16 id, u16 blendFrameCount, f32 speed, u16 mode);
BtlPacket* btlUnitCreateMovePacket(BtlUnit* unit, const RwV3d* targetPos, f32 speed, u32 flags);
BtlPacket* btlUnitCreateRotatePacket(BtlUnit* unit, const RwV3d* rot, u32 flags);
BtlPacket* btlUnitCreateMoveToUnitPacket(BtlUnit* unit, BtlUnit* targetUnit, f32 param_3, f32 speed, u32 flags);
BtlPacket* btlUnitCreateRotateTowardUnitPacket(BtlUnit* unit, BtlUnit* targetUnit, u32 flags);
BtlPacket* btlUnit00286320(BtlUnit* unit);
BtlPacket* btlUnitCreateLookAtPacket(BtlUnit* unit, const RwV3d* targetPos, u16 flags);
BtlPacket* btlUnitCreateModelPacket(BtlUnit* unit, u16 id, u16 flags);
BtlPacket* btlUnitCreateLookAtUnitPacket(BtlUnit* unit, BtlUnit* targetUnit, u16 flags);
BtlPacket* btlUnitCreateLookAtDeactivatePacket(BtlUnit* unit, u16 flags);
BtlPacket* btlUnitCreatePosRotColPacket(BtlUnit* unit, const RwV3d* pos, const RtQuat* rot, const RwRGBA* col);

#endif