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
#pragma opt_loop_invariants on
static inline BtlPacket* btlPacketFindWaitTarget(u64 value, u32 useActionUid)
{
    BtlPacket* packet;
    u32 i;
    u64 uid;

    for (i = 0; i < BTLPACKET_TYPE_MAX; i++)
    {
        for (packet = gBtl->packetLists[i].head; packet != NULL; packet = packet->next)
        {
            uid = useActionUid ? packet->actionUID : packet->uid;
            if (value == (uid & 0x3fffffffffffffffULL) &&
                (packet->unk_47 & BTLPACKET_FLAG_WAIT_TARGET))
            {
                return packet;
            }
        }
    }
    return NULL;
}

static inline BtlPacket* btlPacketFindWaitTargetById(u16 id)
{
    BtlPacket* packet;
    u32 i;

    for (i = 0; i < BTLPACKET_TYPE_MAX; i++)
    {
        for (packet = gBtl->packetLists[i].head; packet != NULL; packet = packet->next)
        {
            if (*(u16*)&packet->id == id &&
                (packet->unk_47 & BTLPACKET_FLAG_WAIT_TARGET))
            {
                return packet;
            }
        }
    }
    return NULL;
}

// FUN_0027e530
u32 btlPacketCheckWaitCondition(BtlPacketWaitCondition* condition, s32 frameCount)
{
    BtlPacket* packet;
    u32 result;

    result = 0;
    switch (condition->type)
    {
    case BTLPACKET_WAIT_ALWAYS:
        result = 1;
        break;

    case BTLPACKET_WAIT_FRAME_REACHED:
    {
        s32 value;

        value = (s32)condition->value;
        if (value > frameCount)
        {
            break;
        }
        result = 1;
        break;
    }

    case BTLPACKET_WAIT_PACKET_UID_EXISTS:
        packet = btlPacketFindWaitTarget(condition->value, 0);
        if (packet == NULL)
        {
            break;
        }
        result = 1;
        break;

    case BTLPACKET_WAIT_PACKET_UID_ABSENT:
        packet = btlPacketFindWaitTarget(condition->value, 0);
        if (packet != NULL)
        {
            break;
        }
        result = 1;
        break;

    case BTLPACKET_WAIT_PACKET_UID_UPDATING:
        result = 1;
        packet = btlPacketFindWaitTarget(condition->value, 0);
        if (packet == NULL)
        {
            break;
        }
        if (packet->unk_45 == BTLPACKET_STATE_UPDATE)
        {
            break;
        }
        result = 0;
        break;

    case BTLPACKET_WAIT_ACTION_UID_EXISTS:
        packet = btlPacketFindWaitTarget(condition->value, 1);
        if (packet == NULL)
        {
            break;
        }
        result = 1;
        break;

    case BTLPACKET_WAIT_ACTION_UID_ABSENT:
        packet = btlPacketFindWaitTarget(condition->value, 1);
        if (packet != NULL)
        {
            break;
        }
        result = 1;
        break;

    case BTLPACKET_WAIT_ACTION_UID_UPDATING:
        result = 1;
        packet = btlPacketFindWaitTarget(condition->value, 1);
        if (packet == NULL)
        {
            break;
        }
        if (packet->unk_45 == BTLPACKET_STATE_UPDATE)
        {
            break;
        }
        result = 0;
        break;

    case BTLPACKET_WAIT_ID_EXISTS:
        packet = btlPacketFindWaitTargetById((u16)condition->value);
        if (packet == NULL)
        {
            break;
        }
        result = 1;
        break;

    case BTLPACKET_WAIT_ID_ABSENT:
        packet = btlPacketFindWaitTargetById((u16)condition->value);
        if (packet != NULL)
        {
            break;
        }
        result = 1;
        break;

    case BTLPACKET_WAIT_PACKET_UID_CALLBACK:
    {
        BtlPacketConditionFunc callback;

        result = 1;
        packet = btlPacketFindWaitTarget(condition->value, 0);
        if (packet == NULL)
        {
            break;
        }
        callback = packet->unk_74;
        if (callback != NULL)
        {
            result = callback(packet->workData);
            break;
        }
        result = 0;
        break;
    }

    case BTLPACKET_WAIT_ACTION_UID_CALLBACK:
    {
        BtlPacketConditionFunc callback;

        result = 1;
        packet = btlPacketFindWaitTarget(condition->value, 1);
        if (packet == NULL)
        {
            break;
        }
        callback = packet->unk_74;
        if (callback != NULL)
        {
            result = callback(packet->workData);
            break;
        }
        result = 0;
        break;
    }
    }
    return result;
}
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
// FUN_0027ec10
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
#pragma opt_loop_invariants off

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


// FUN_0027ee00
void btlPacketUpdate(BtlPacket* packet)
{
    s32 frameCount;
    u16 i;
    u32 result;

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
            switch (packet->unk_45)
            {
            case BTLPACKET_STATE_PRE_UPDATE_CONDITIONS:
                i = 0;
                for (; i < 2; i++)
                {
                    if (!btlPacketCheckWaitCondition(&((BtlPacketWaitCondition*)packet)[i], frameCount))
                    {
                        result = 0;
                        goto preUpdateConditionsDone;
                    }
                }
                result = 1;
preUpdateConditionsDone:
                if (result == 0)
                {
                    goto done;
                }
                packet->unk_45 = BTLPACKET_STATE_PRE_UPDATE_DELAY;
                break;
            default:
                goto done;
            }
preUpdateDelay:
            if (packet->preUpdateDelay <= 0)
            {
                packet->unk_45 = BTLPACKET_STATE_UPDATE;
            }
            else
            {
                packet->preUpdateDelay--;
                goto done;
            }

update:
            if (packet->updateFunc(packet->workData))
            {
                packet->unk_45 = BTLPACKET_STATE_POST_UPDATE_CONDITIONS;
                goto postUpdateConditions;
            }
            packet->unk_50++;
            goto done;

postUpdateConditions:
            i = 0;
            for (; i < 2; i++)
            {
                if (!btlPacketCheckWaitCondition(&((BtlPacketWaitCondition*)((u8*)packet + 0x20))[i], frameCount))
                {
                    result = 0;
                    goto postUpdateConditionsDone;
                }
            }
            result = 1;
postUpdateConditionsDone:
            if (result == 0)
            {
                goto done;
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
#pragma opt_loop_invariants on
// FUN_0027f2f0
BtlPacket* btlPacketCreatePostUpdatePacket()
{
    BtlPacket* packet;
    u16 i;
    u16 j;

    packet = RwMalloc(sizeof(BtlPacket), rwMEMHINTDUR_GLOBAL);
    memset(packet, 0, sizeof(BtlPacket));
    packet->id = 0xff00;
    for (i = 0; i < 2; i++)
    {
        ((BtlPacketWaitCondition*)packet)[i].type = BTLPACKET_WAIT_ALWAYS;
    }
    {
        BtlPacketWaitCondition* wait;

        wait = packet->postUpdateWaits;
        for (j = 0; j < 2; j++)
        {
            wait[j].type = BTLPACKET_WAIT_ALWAYS;
        }
    }
    packet->unk_47 |= BTLPACKET_FLAG_AUTO_DESTROY |
                      BTLPACKET_FLAG_10 |
                      BTLPACKET_FLAG_WAIT_TARGET;
    packet->updateFunc = btlPacket0027f2e0;
    return packet;
}
#pragma opt_loop_invariants off

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

#pragma opt_loop_invariants on
// FUN_0027f410
BtlPacket* btlPacketCreateCallbackPacket(void (*callback)(void*), void* data)
{
    typedef struct BtlPacketCallbackWork
    {
        void (*callback)(void* data);
        void* data;
    } BtlPacketCallbackWork;
    BtlPacket* packet;
    BtlPacketCallbackWork* callbackWork;
    u16 i;
    u16 j;
    u8 waitType;
    s32 size;

    size = sizeof(BtlPacket) + sizeof(BtlPacketCallbackWork);
    packet = RwMalloc(size, rwMEMHINTDUR_GLOBAL);
    memset(packet, 0, size);
    packet->id = 0xff01;
    waitType = BTLPACKET_WAIT_ALWAYS;
    for (i = 0; i < 2; i++)
    {
        ((BtlPacketWaitCondition*)packet)[i].type = waitType;
    }
    {
        BtlPacketWaitCondition* wait;

        wait = packet->postUpdateWaits;
        for (j = 0; j < 2; j++)
        {
            wait[j].type = waitType;
        }
    }
    packet->workData = (u8*)packet + sizeof(BtlPacket);
    packet->unk_47 |= BTLPACKET_FLAG_AUTO_DESTROY |
                      BTLPACKET_FLAG_10 |
                      BTLPACKET_FLAG_WAIT_TARGET;
    packet->updateFunc = (u32 (*)(void*))btlPacketInvokeCallback;
    callbackWork = (BtlPacketCallbackWork*)packet->workData;
    callbackWork->callback = callback;
    callbackWork->data = data;
    return packet;
}
#pragma opt_loop_invariants off
