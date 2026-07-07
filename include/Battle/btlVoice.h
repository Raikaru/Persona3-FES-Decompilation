#ifndef BTLVOICE_H
#define BTLVOICE_H

#include "Utils.h"
#include "Battle/btlPacket.h"

typedef struct BtlPacket BtlPacket;
typedef struct BtlAction BtlAction;

typedef enum
{
    BTLVOICE_PACKET_UNK01 = BTLPACKET_MAKE_ID(BTLPACKET_MODULE_VOICE, 1)
} BtlVoicePacket;

// 24 bytes
typedef struct BtlVoicePacket002e2be0
{
    BtlAction* action; // 0x00
    s16 unk_04;        // 0x04
    u8 unkData1[2];
    s32 unk_08;        // 0x08
    s32 unk_0c;        // 0x0c
    s16 unk_10;        // 0x10
    u8 unkData2[2];
    s32 unk_14;        // 0x14
} BtlVoicePacket002e2be0;

BtlPacket* btlVoice002e2be0(BtlAction* action, s32 param_2, s32 param_3, s32 param_4, s32 param_5);

#endif