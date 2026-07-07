#ifndef BTLFORMATION_H
#define BTLFORMATION_H

#include "Utils.h"
#include "Battle/btlPacket.h"

typedef struct BtlPacket BtlPacket;

typedef enum
{
    BTLFORMATION_PACKET_UNK03 = BTLPACKET_MAKE_ID(BTLPACKET_MODULE_FORMATION, 3),
    BTLFORMATION_PACKET_UNK04 = BTLPACKET_MAKE_ID(BTLPACKET_MODULE_FORMATION, 4)
} BtlFormationPacket;

// 4 bytes
typedef struct BtlFormationPacket002b8d60
{
    s16 unk_00; // 0x00
    u16 flags;  // 0x02
} BtlFormationPacket002b8d60;

// 2 bytes
typedef struct BtlFormationPacket002b8f40
{
    s16 unk_00; // 0x00
} BtlFormationPacket002b8f40;

BtlPacket* btlFormation002b8d60(s32 param_1, u32 flags);
BtlPacket* btlFormation002b8f40(s32 param_1);

#endif