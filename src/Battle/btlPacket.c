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
// FUN_0027e530 NONMATCHING
u32 btlPacketCheckWaitCondition(BtlPacketWaitCondition* condition, s32 frameCount)
{
    BtlPacket* packet;
    u32 i;
    u32 found;

    switch (condition->type)
    {
    case BTLPACKET_WAIT_ALWAYS:
        return true;

    case BTLPACKET_WAIT_FRAME_REACHED:
        return (s32)condition->value <= frameCount;

    case BTLPACKET_WAIT_PACKET_UID_EXISTS:
    case BTLPACKET_WAIT_PACKET_UID_ABSENT:
    case BTLPACKET_WAIT_PACKET_UID_UPDATING:
    case BTLPACKET_WAIT_ACTION_UID_EXISTS:
    case BTLPACKET_WAIT_ACTION_UID_ABSENT:
    case BTLPACKET_WAIT_ACTION_UID_UPDATING:
    {
        u32 useActionUid;

        useActionUid = condition->type >= BTLPACKET_WAIT_ACTION_UID_EXISTS;
        found = false;
        for (i = 0; i < BTLPACKET_TYPE_MAX; i++)
        {
            packet = gBtl->packetLists[i].head;
            while (packet != NULL)
            {
                u64 value;

                value = useActionUid ? packet->actionUID : packet->parentUID;
                if (condition->value == (value & 0x3fffffffffffffffULL) &&
                    (packet->unk_47 & BTLPACKET_FLAG_WAIT_TARGET))
                {
                    found = true;
                    if (condition->type == BTLPACKET_WAIT_PACKET_UID_UPDATING ||
                        condition->type == BTLPACKET_WAIT_ACTION_UID_UPDATING)
                    {
                        return packet->unk_45 == BTLPACKET_STATE_UPDATE;
                    }
                    break;
                }
                packet = packet->next;
            }
            if (found)
            {
                break;
            }
        }

        if (condition->type == BTLPACKET_WAIT_PACKET_UID_ABSENT ||
            condition->type == BTLPACKET_WAIT_ACTION_UID_ABSENT)
        {
            return !found;
        }
        if (condition->type == BTLPACKET_WAIT_PACKET_UID_UPDATING ||
            condition->type == BTLPACKET_WAIT_ACTION_UID_UPDATING)
        {
            return !found;
        }
        return found;
    }

    case BTLPACKET_WAIT_ID_EXISTS:
    case BTLPACKET_WAIT_ID_ABSENT:
        found = false;
        for (i = 0; i < BTLPACKET_TYPE_MAX; i++)
        {
            packet = gBtl->packetLists[i].head;
            while (packet != NULL)
            {
                if (packet->id == ((u16)condition->value) &&
                    (packet->unk_47 & BTLPACKET_FLAG_WAIT_TARGET))
                {
                    found = true;
                    break;
                }
                packet = packet->next;
            }
            if (found)
            {
                break;
            }
        }
        return condition->type == BTLPACKET_WAIT_ID_ABSENT ? !found : found;

    case BTLPACKET_WAIT_PACKET_UID_CALLBACK:
    case BTLPACKET_WAIT_ACTION_UID_CALLBACK:
    {
        u32 useActionUid;

        useActionUid = condition->type == BTLPACKET_WAIT_ACTION_UID_CALLBACK;
        for (i = 0; i < BTLPACKET_TYPE_MAX; i++)
        {
            packet = gBtl->packetLists[i].head;
            while (packet != NULL)
            {
                u64 value;

                value = useActionUid ? packet->actionUID : packet->parentUID;
                if (condition->value == (value & 0x3fffffffffffffffULL) &&
                    (packet->unk_47 & BTLPACKET_FLAG_WAIT_TARGET))
                {
                    if (packet->unk_74 == NULL)
                    {
                        return false;
                    }
                    return packet->unk_74(packet->workData);
                }
                packet = packet->next;
            }
        }
        return true;
    }

    default:
        return false;
    }
}


// FUN_0027ec10 NONMATCHING
BtlPacket* btlPacketCreate(u32 id, s32 workDataSize)
{
    BtlPacket* packet;
    u16 i;
    s32 size;

    size = workDataSize + sizeof(BtlPacket);
    packet = RwMalloc(size, rwMEMHINTDUR_GLOBAL);
    memset(packet, 0, size);

    packet->id = id;
    for (i = 0; i < 2; i++)
    {
        ((BtlPacketWaitCondition*)packet)[i].type = BTLPACKET_WAIT_ALWAYS;
    }
    for (i = 0; i < 2; i++)
    {
        ((BtlPacket*)((BtlPacketWaitCondition*)packet + i))->postUpdateWaits[0].type = BTLPACKET_WAIT_ALWAYS;
    }

    if (workDataSize > 0)
    {
        packet->workData = (u8*)packet + sizeof(BtlPacket);
    }

    packet->unk_47 |= BTLPACKET_FLAG_AUTO_DESTROY |
                      BTLPACKET_FLAG_10 |
                      BTLPACKET_FLAG_WAIT_TARGET;

    return packet;
}

// FUN_0027ed20
u64 btlPacketRegister(BtlPacket* packet, u8 type)
{
    packet->uid = btlGetUID();
    packet->unk_4c = 0;
    packet->unk_50 = 0;
    packet->unk_45 = BTLPACKET_STATE_PRE_UPDATE_CONDITIONS;
    packet->type = type;
    packet->unk_47 = packet->unk_47 | BTLPACKET_FLAG_REGISTERED;

    if (packet->initFunc != NULL)
    {
        packet->initFunc(packet->workData);
    }

    packet->next = NULL;
    if (gBtl->packetLists[type].tail != NULL)
    {
        gBtl->packetLists[type].tail->next = packet;
        packet->prev = gBtl->packetLists[type].tail;
    }
    else
    {
        gBtl->packetLists[type].head = packet;
        packet->prev = NULL;
    }
    gBtl->packetLists[type].tail = packet;

    return packet->uid;
}
// FUN_0027edf0
void btlPacket0027edf0()
{
}


// FUN_0027ee00 NONMATCHING
void btlPacketUpdate(BtlPacket* packet)
{
    s32 frameCount;
    u16 i;

    if (packet->unk_46 == 0 && (packet->unk_47 & BTLPACKET_FLAG_REGISTERED))
    {
        if (packet->unk_47 & BTLPACKET_FLAG_DESTROY_REQUESTED)
        {
            if (packet->destroyFunc != NULL)
            {
                packet->destroyFunc(packet->workData);
            }
            if (packet->unk_47 & BTLPACKET_FLAG_REGISTERED)
            {
                u8 type;
                type = packet->type;
                if (packet->prev != NULL)
                {
                    packet->prev->next = packet->next;
                }
                else
                {
                    gBtl->packetLists[type].head = packet->next;
                }

                if (packet->next != NULL)
                {
                    packet->next->prev = packet->prev;
                }
                else
                {
                    gBtl->packetLists[type].tail = packet->prev;
                }
            }
            RwFree(packet);
        }
        else
        {
            frameCount = packet->unk_4c;
            packet->unk_4c = frameCount + 1;
            if (packet->unk_45 == BTLPACKET_STATE_POST_UPDATE_DELAY)
            {
                goto postUpdateDelay;
            }
            if (packet->unk_45 == BTLPACKET_STATE_POST_UPDATE_CONDITIONS)
            {
                goto postUpdateConditions;
            }
            if (packet->unk_45 == BTLPACKET_STATE_UPDATE)
            {
                goto update;
            }
            if (packet->unk_45 == BTLPACKET_STATE_PRE_UPDATE_DELAY)
            {
                goto preUpdateDelay;
            }
            if (packet->unk_45 != BTLPACKET_STATE_PRE_UPDATE_CONDITIONS)
            {
                goto done;
            }

            for (i = 0; i < 2; i++)
            {
                if (!btlPacketCheckWaitCondition(&((BtlPacketWaitCondition*)packet)[i], frameCount))
                {
                    goto done;
                }
            }
            packet->unk_45 = BTLPACKET_STATE_PRE_UPDATE_DELAY;

preUpdateDelay:
            if (packet->preUpdateDelay > 0)
            {
                packet->preUpdateDelay--;
                goto done;
            }
            packet->unk_45 = BTLPACKET_STATE_UPDATE;

update:
            if (packet->updateFunc(packet->workData))
            {
                packet->unk_45 = BTLPACKET_STATE_POST_UPDATE_CONDITIONS;
                goto postUpdateConditions;
            }
            packet->unk_50++;
            goto done;

postUpdateConditions:
            for (i = 0; i < 2; i++)
            {
                if (!btlPacketCheckWaitCondition(&packet->postUpdateWaits[i], frameCount))
                {
                    goto done;
                }
            }
            packet->unk_45 = BTLPACKET_STATE_POST_UPDATE_DELAY;

postUpdateDelay:
            if (packet->postUpdateDelay <= 0)
            {
                if (packet->destroyFunc != NULL)
                {
                    packet->destroyFunc(packet->workData);
                }
                if (packet->unk_47 & BTLPACKET_FLAG_REGISTERED)
                {
                    u8 type;
                    type = packet->type;
                    if (packet->prev != NULL)
                    {
                        packet->prev->next = packet->next;
                    }
                    else
                    {
                        gBtl->packetLists[type].head = packet->next;
                    }

                    if (packet->next != NULL)
                    {
                        packet->next->prev = packet->prev;
                    }
                    else
                    {
                        gBtl->packetLists[type].tail = packet->prev;
                    }
                }
                RwFree(packet);
                goto done;
            }
            packet->postUpdateDelay--;
        }
    }

done:
    return;
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

// FUN_0027f1c0
void btlPacketDestroyAll()
{
    BtlPacket* packet;
    BtlPacket* link;
    BtlPacket* prev;
    u32 i;
    u8 type;
    s32 listOffset;

    for (i = 0; i < BTLPACKET_TYPE_MAX; i++)
    {
        listOffset = i << 3;
        packet = *(BtlPacket**)((s32)gBtl + listOffset + 0x174);
        while (packet != NULL)
        {
            prev = packet->prev;

            if (packet->destroyFunc != NULL)
            {
                packet->destroyFunc(packet->workData);
            }
            if (packet->unk_47 & BTLPACKET_FLAG_REGISTERED)
            {
                type = packet->type;
                if (packet->prev != NULL)
                {
                    packet->prev->next = packet->next;
                }
                else
                {
                    link = packet->next;
                    listOffset = type << 3;
                    *(BtlPacket**)((s32)gBtl + listOffset + 0x174) = link;
                }

                if (packet->next != NULL)
                {
                    packet->next->prev = packet->prev;
                }
                else
                {
                    link = packet->prev;
                    listOffset = type << 3;
                    *(BtlPacket**)((s32)gBtl + listOffset + 0x170) = link;
                }
            }
            RwFree(packet);

            packet = prev;
        }
    }
}

// FUN_0027f2e0
u32 btlPacket0027f2e0()
{
    return 1;
}
// FUN_0027f2f0 NONMATCHING
BtlPacket* btlPacketCreatePostUpdatePacket()
{
    BtlPacket* packet;

    packet = btlPacketCreate(0xff00, 0);
    packet->updateFunc = btlPacket0027f2e0;
    return packet;
}

// FUN_0027f3e0
static void btlPacketInvokeCallback(void* work)
{
    typedef struct BtlPacketCallbackWork
    {
        void (*callback)(void* data);
        void* data;
    } BtlPacketCallbackWork;
    BtlPacketCallbackWork* callbackWork;

    callbackWork = (BtlPacketCallbackWork*)work;
    callbackWork->callback(callbackWork->data);
}

// FUN_0027f410 NONMATCHING
BtlPacket* btlPacketCreateCallbackPacket(void (*callback)(void*), void* data)
{
    typedef struct BtlPacketCallbackWork
    {
        void (*callback)(void* data);
        void* data;
    } BtlPacketCallbackWork;
    BtlPacket* packet;
    BtlPacketCallbackWork* callbackWork;

    packet = btlPacketCreate(0xff01, sizeof(BtlPacketCallbackWork));
    packet->updateFunc = (u32 (*)(void*))btlPacketInvokeCallback;
    callbackWork = (BtlPacketCallbackWork*)packet->workData;
    callbackWork->callback = callback;
    callbackWork->data = data;
    return packet;
}
