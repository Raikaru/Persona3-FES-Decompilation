#include "Battle/btlVoice.h"

extern u32 btlVoice002e2a60(void* work);

// FUN_002e2be0
BtlPacket* btlVoice002e2be0(BtlAction* action, s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
    BtlPacket* packet;
    BtlVoicePacket002e2be0* work;

    packet = btlPacketCreate(BTLVOICE_PACKET_UNK01, sizeof(BtlVoicePacket002e2be0));

    packet->updateFunc = btlVoice002e2a60;

    work = (BtlVoicePacket002e2be0*)packet->workData;

    work->action = action;
    work->unk_04 = param_2;
    work->unk_08 = param_3;
    work->unk_0c = param_4;
    work->unk_10 = param_5;
    work->unk_14 = 0;

    return packet;
}