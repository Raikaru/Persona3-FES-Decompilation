#include "Battle/btlFormation.h"

extern u32 btlFormation002b8c00(void* work);
extern u32 btlFormation002b8dc0(void* work);

// FUN_002b8d60
BtlPacket* btlFormation002b8d60(s32 param_1, u32 flags)
{
    BtlPacket* packet;
    BtlFormationPacket002b8d60* work;

    packet = btlPacketCreate(BTLFORMATION_PACKET_UNK03, sizeof(BtlFormationPacket002b8d60));

    packet->updateFunc = btlFormation002b8c00;

    work = (BtlFormationPacket002b8d60*)packet->workData;

    work->unk_00 = param_1;
    work->flags = flags;

    return packet;
}

// FUN_002b8f40
BtlPacket* btlFormation002b8f40(s32 param_1)
{
    BtlPacket* packet;
    BtlFormationPacket002b8f40* work;

    packet = btlPacketCreate(BTLFORMATION_PACKET_UNK04, sizeof(BtlFormationPacket002b8f40));

    packet->updateFunc = btlFormation002b8dc0;

    work = (BtlFormationPacket002b8f40*)packet->workData;

    work->unk_00 = param_1;

    return packet;
}