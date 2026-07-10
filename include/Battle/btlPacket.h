#ifndef BTLPACKET_H
#define BTLPACKET_H

#include "Utils.h"

#define BTLPACKET_MAKE_ID(moduleId, _id) (((moduleId) << 8) | ((_id)))

// Packet producer subsystem.
typedef enum
{
    BTLPACKET_MODULE_NULL,
    BTLPACKET_MODULE_UNIT,
    BTLPACKET_MODULE_CAMERA,
    BTLPACKET_MODULE_SOUND = 9,
    BTLPACKET_MODULE_VOICE,
    BTLPACKET_MODULE_FORMATION,
    BTLPACKET_MODULE_BATTLE = 255
} BtlPacketModule;

// Packet update queues, processed in battle-frame order.
typedef enum
{
    BTLPACKET_TYPE_0,
    BTLPACKET_TYPE_1,
    BTLPACKET_TYPE_3D,
    BTLPACKET_TYPE_2D,

    BTLPACKET_TYPE_MAX
} BtlPacketType;

typedef enum
{
    BTLPACKET_WAIT_ALWAYS = 1,
    BTLPACKET_WAIT_FRAME_REACHED,
    BTLPACKET_WAIT_PACKET_UID_EXISTS,
    BTLPACKET_WAIT_PACKET_UID_ABSENT,
    BTLPACKET_WAIT_PACKET_UID_UPDATING,
    BTLPACKET_WAIT_ACTION_UID_EXISTS,
    BTLPACKET_WAIT_ACTION_UID_ABSENT,
    BTLPACKET_WAIT_ACTION_UID_UPDATING,
    BTLPACKET_WAIT_ID_EXISTS,
    BTLPACKET_WAIT_ID_ABSENT,
    BTLPACKET_WAIT_PACKET_UID_CALLBACK,
    BTLPACKET_WAIT_ACTION_UID_CALLBACK
} BtlPacketWaitType;

// 16 bytes. A gate evaluated against the packet's current frame count.
typedef struct BtlPacketWaitCondition
{
    u8 type;       // 0x00. See BtlPacketWaitType.
    u8 unk_01[7];
    u64 value;     // 0x08. Frame, packet/action UID, or packet ID by wait type.
} BtlPacketWaitCondition;

typedef void (*BtlPacketInitFunc)(void* work);
typedef u32 (*BtlPacketUpdateFunc)(void* work);
typedef void (*BtlPacketDestroyFunc)(void* work);
typedef u32 (*BtlPacketConditionFunc)(void* work);

#define BTLPACKET_FLAG_AUTO_DESTROY       (1 << 0)
#define BTLPACKET_FLAG_DESTROY_REQUESTED  (1 << 2)
#define BTLPACKET_FLAG_REGISTERED         (1 << 3)
#define BTLPACKET_FLAG_10                 (1 << 4)
#define BTLPACKET_FLAG_WAIT_TARGET        (1 << 5)

typedef enum
{
    BTLPACKET_STATE_PRE_UPDATE_CONDITIONS,
    BTLPACKET_STATE_PRE_UPDATE_DELAY,
    BTLPACKET_STATE_UPDATE,
    BTLPACKET_STATE_POST_UPDATE_CONDITIONS,
    BTLPACKET_STATE_POST_UPDATE_DELAY
} BtlPacketState;

typedef struct BtlPacket BtlPacket;

// 144 bytes. Packet scheduler node. The first condition is flattened because
// parentUID is used directly by packet producers.
struct BtlPacket
{
    u8 unk_00;                                // 0x00. First pre-update wait type.
    u8 unk_01[7];
    u64 parentUID;                            // 0x08. First pre-update wait value.
    BtlPacketWaitCondition preUpdateWait;     // 0x10
    BtlPacketWaitCondition postUpdateWaits[2]; // 0x20
    u32 id;                                   // 0x40. See BTLPACKET_MAKE_ID.
    u8 type;                                  // 0x44. See BtlPacketType.
    u8 unk_45;                                // 0x45. See BtlPacketState.
    u8 unk_46;                                // 0x46. Nonzero prevents updates.
    u8 unk_47;                                // 0x47. See BTLPACKET_FLAG_*.
    s16 preUpdateDelay;                       // 0x48
    s16 postUpdateDelay;                      // 0x4a
    s32 unk_4c;                               // 0x4c. Frame count.
    s32 unk_50;                               // 0x50. Failed update count.
    s32 unk_54;                               // 0x54
    u64 uid;                                  // 0x58
    u64 actionUID;                            // 0x60
    BtlPacketInitFunc initFunc;               // 0x68
    BtlPacketUpdateFunc updateFunc;           // 0x6c
    BtlPacketDestroyFunc destroyFunc;         // 0x70
    BtlPacketConditionFunc unk_74;            // 0x74
    void* workData;                           // 0x78. Owned within this allocation.
    BtlPacket* next;                          // 0x7c. Toward the list tail.
    BtlPacket* prev;                          // 0x80. Toward the list head.
    u8 unkData3[0x0c];
};

BtlPacket* btlPacketFindFirstByActionUID(u64 actionUID, u64 mask);
u32 btlPacketCount();
u32 btlPacketCountById(u32 id);
void btlPacket0027e4d0();
BtlPacket* btlPacketCreate(u32 id, s32 workDataSize);
u32 btlPacketCheckWaitCondition(BtlPacketWaitCondition* condition, s32 frameCount);
u64 btlPacketRegister(BtlPacket* packet, u8 type);
void btlPacketUpdate(BtlPacket* packet);
void btlPacketUpdateList(u8 type);
// Retail teardown starts at each queue head and follows prev links.
void btlPacketDestroyAll();

#endif