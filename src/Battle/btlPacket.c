#include "Battle/btlPacket.h"
#include "Battle/battle.h"

// FUN_0027e390
BtlPacket* btlPacketFindFirstByActionUID(u64 actionUID, u64 mask)
{
    u32 i;
    Battle* btl;
    BtlPacketList* currList;
    BtlPacket* curr;

    i = 0;
    btl = gBtl;
    for (; i < BTLPACKET_TYPE_MAX; i++)
    {
        currList = &btl->packetLists[i];
        curr = currList->head;

        while (curr != NULL)
        {
            if (actionUID == (curr->actionUID & mask) &&
                curr->unk_47 & (1 << 5))
            {
                return curr;
            }

            curr = curr->next;
        }
    }

    return NULL;
}

// FUN_0027e410
u32 btlPacketCount()
{
    u32 total;
    u32 i;
    Battle* btl;
    BtlPacketList* currList;
    BtlPacket* curr;
    
    total = 0;
    i = 0;
    btl = gBtl;
    for (; i < BTLPACKET_TYPE_MAX; i++)
    {
        currList = &btl->packetLists[i];
        curr = currList->head;

        while (curr != NULL)
        {
            total++;

            curr = curr->next;
        }
    }

    return total;
}

// FUN_0027e470
u32 btlPacketCountById(u32 id)
{
    BtlPacketList* currList;
    BtlPacket* curr;
    u32 total;
    u32 i;
    Battle* btl;

    total = 0;
    i = 0;
    btl = gBtl;
    id = (u16)id;
    for (; i < BTLPACKET_TYPE_MAX; i++)
    {
        currList = &btl->packetLists[i];
        curr = currList->head;

        while (curr != NULL)
        {
            if (curr->id == id)
            {
                total++;
            }

            curr = curr->next;
        }
    }

    return total;
}

// FUN_0027e4d0
void btlPacket0027e4d0()
{
    BtlPacketList* currList;
    BtlPacket* curr;
    u32 i;
    u32 flags;

    i = 0;
    for (; i < BTLPACKET_TYPE_MAX; i++)
    {
        currList = &gBtl->packetLists[i];
        curr = currList->head;

        while (curr != NULL)
        {
            flags = curr->unk_47;
            if (flags & (1 << 0))
            {
                curr->unk_47 = flags | (1 << 2);
            }

            curr = curr->prev;
        }
    }
}

// FUN_0027ec10
BtlPacket* btlPacketCreate(u32 id, u32 workDataSize)
{
    // TODO

    return NULL;
}

// FUN_0027ed20
u64 btlPacketRegister(BtlPacket* packet, u8 type)
{
    // TODO

    return 0;
}

// FUN_0027ee00
void btlPacketUpdate(BtlPacket* packet)
{
    // TODO
}

// FUN_0027f160
void btlPacketUpdateList(u8 type)
{
    BtlPacket* curr;
    BtlPacket* next;

    curr = gBtl->packetLists[type].head;
    while (curr != NULL)
    {
        next = curr->next;

        btlPacketUpdate(curr);

        curr = next;
    }
}