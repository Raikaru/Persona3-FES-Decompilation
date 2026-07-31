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
/* Removing this loses FUN_0027e530 (MATCH nd0 -> MISMATCH nd860) - measured W161. */
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
/* Removing this loses FUN_0027ec10 (MATCH nd0 -> MISMATCH nd18) - measured W161. */
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
/* Removing this loses FUN_0027f2f0 (MATCH nd0 -> MISMATCH nd18) - measured W161. */
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

/* Removing this loses FUN_0027f410 (MATCH nd0 -> MISMATCH nd18) - measured W161. */
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


#include "Battle/btlUnit.h"
#include "Battle/btlAction.h"
#include "Battle/btlBoss.h"
#include "Graphics/Model/mdlManager.h"
#include "Main/Battle/Data/datUnit.h"
#include "Main/Battle/Data/datCalc.h"
#include "Main/Battle/Data/datPersona.h"
#include "Scene/mt_scene.h"
#include "Graphics/Model/mdlFile.h"
#include "h_cdvd.h"
#include "Kernel/Kwln/kwln.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_00287b20(int param_1,u16 param_2);
#pragma alias btlUnitFabs FUN_0052e118
extern f64 btlUnitFabs(f64 value);
void FUN_00287cf0(BtlUnit* unit, u16 mode);
void FUN_00287ea0(BtlUnit* unit);
void FUN_00288110(BtlUnit* unit);
int FUN_00288da0(BtlUnit* unit, u16 mode);
void FUN_002891e0(void);
BtlAction* FUN_00289650(u16 param_1, u16 param_2, void* param_3);
void btlAction00299e30(BtlAction* action);
extern f32 DAT_007cad78;
extern f32 fGpffff8218;
extern void mdl00318a70(Model* mdl, RwMatrix* matrix, u32 mode);
extern void func_0029ee20(BtlUnit* unit);
extern void func_002fd520(BtlUnit* unit);
extern u32 func_002bbfa0(u64 bad);
extern s16 func_002bbdf0(void* value);
extern void func_002bc0e0(u64 bad, u8* color);
extern void func_002bbdc0(void* value, s16 id);
extern void func_002bbf80(void* value, u32 color);
extern void func_002bbe00(void* value);
extern f32 DAT_007cadb4;
extern f32 DAT_007cadc0;
extern f32 DAT_007caea4;
extern f32 DAT_007cada4;
extern f32 DAT_007cb0cc;
extern code DAT_00960090;
#pragma alias DAT_00960090_abs DAT_00960090
extern code DAT_00960090_abs[];
extern int iGpffffa850;
extern int iGpffffb6fc;

static u32 sNextId = 1; // 007cc51c

static f32 gUnk_007cad7c = 0.3f; // 007cad7c. No idea where to put this

RwV3d gUnk_00957188; // 00957188
extern RwV3d D_00697870;
extern RwV3d D_00697880;
extern RwV3d D_00697890;
extern RwV3d D_006978A0;
extern RwV3d D_00957180;
#pragma alias D_00957180_abs D_00957180
extern RwV3d D_00957180_abs;
extern u8* DAT_007ce42c;
extern const u8* iGpffffb718;
extern const u8* iGpffffb71c;
extern const u8* iGpffffb73c;
extern void func_002ff890(DatUnit* unit, u32 param_2, u16 id);
extern void* func_00308c60(DatUnit* unit);

BtlPacket* btlUnitCreateResNullifiedAnimPacket(BtlUnit* unit, f32 param_2);
BtlPacket* btlUnit00284900(BtlUnit* unit, s32 param_2);
BtlPacket* btlUnitCreateEnmDodgeAnimPacket(BtlUnit* unit, s32 unused);
void FUN_00287490(BtlUnit* unit);
void FUN_00287510(BtlUnit* unit);
void FUN_003b7090(u16 resTypeId);
void FUN_002bbbc0(void* param);

typedef struct BtlUnitAnimInfo
{
    s16 unk_0;
    s16 speedPercent;
    s16 unk_4;
    s16 unk_6;
    s16 unk_8;
} BtlUnitAnimInfo;

typedef struct BtlUnitPacketBackstep
{
    RwV3d origin;          // 0x00
    RwV3d displacement;    // 0x0c
    BtlUnit* unit;         // 0x18
    u16 blendFrameCount;   // 0x1c
    u16 counter;           // 0x1e
    f32 phase;             // 0x20
} BtlUnitPacketBackstep;

void func_0027f530(BtlUnit* unit);
void func_00280050(void* param_1, RwV3d* param_2);
f32 func_00280870(u32 param_1, u32 param_2, RwV3d* param_3, f32* param_4, f32* param_5, u32 param_6);
u32 func_002f8ea0(BtlUnit* unit, RwV3d* param_2);
void func_002d1de0(RwV3d* dst, const RwV3d* from, const RwV3d* to);
void func_002d4800(RwV3d* param_1);
void func_002d48c0(RwV3d* param_1, const RwV3d* param_2, const RwV3d* param_3, f32 param_4);
void func_00288110(BtlUnit* unit);
void func_002831c0(BtlUnit* unit, s32 param_2);
s16 func_002838d0(BtlUnit* unit, u16 id, f32 scale);
s16 func_00283510(BtlUnit* unit, s32 id);
const BtlUnitAnimBounds* func_00288da0(BtlUnit* unit, s32 id);
void* func_002bbc00(BtlUnit* unit);
void* func_002bb7d0(void);
void func_002bcde0(BtlUnit* unit, void* param_2);
f32 func_0052ea18(f32 x, f32 z);
void func_004bdde0(RtQuat* dst, const RwV3d* axis, s32 param_3, f32 angle);
f32 effMiscRandFloat(s32 param_1);
Model* func_00316c70(u16 type, u16 id, HCdvd* cdvd, u32 readMode);
void func_0031c1d0(Model* mdl);
void func_001a0590(u16 resTypeId, u32 param_2);
u32 func_002d5cf0(BtlUnit* unit);
void func_00319230(Model* mdl, u32 param_2);
u32 func_0017c0e0(u16 id);
u16 func_003b6180(u16 id, Model* mdl);
void func_002d3e00(BtlUnit* unit, s32 param_2);
void func_00280130(BtlUnit* unit, RwV3d* param_2);
void func_00280200(BtlUnit* unit, const s16* param_2, RwV3d* param_3);
void func_002802d0(BtlUnit* unit, BtlUnit* target, RwV3d* param_3);
void func_00280390(BtlUnit* unit, BtlUnit* target, RwV3d* param_3);
void func_00280480(BtlUnit* unit, BtlUnit* target, RwV3d* param_3);
void func_00280580(BtlUnit* unit, RwV3d* param_2);
void func_002806d0(BtlUnit* unit, RwV3d* param_2);
void func_002807a0(BtlUnit* unit, RwV3d* param_2);
void func_00280da0(BtlUnit* unit);
f32 func_002812d0(BtlUnit* unit, BtlUnit* target, s32 id);
void func_002826d0(BtlUnit* unit);
void func_00282bc0(BtlUnit* unit);
s16 func_002f9560(BtlUnit* unit, u16* flags);
s16 func_002835e0(BtlUnit* unit, s16 id, f32 scale);
s16 func_002838d0(BtlUnit* unit, u16 id, f32 scale);
u16 func_002ffbc0(u32 max);
f32 func_002fc5d0(BtlUnit* unit, BtlUnit* target, s32 id);
s32 func_00318ed0(Model* mdl, s32 param_2, RwV3d* pos);
u32 func_00281f20(void* work);
BtlPacket* func_00282130(BtlUnit* unit, u16 blendFrameCount);
u32 func_00318620(Model* mdl, u16 slotIdx, s16 id);
u32 func_003186e0(Model* mdl, u16 slotIdx, s16 id);
u32 func_0017d800(void);
s16 btlUnit00282c30(BtlUnit* unit);
u32 btlUnit00282c60(BtlUnit* unit);
u32 btlUnit00282cd0(BtlUnit* unit);
void btlUnit00283c00(BtlUnit* unit, s32 param_2);

// 12 bytes
typedef struct BtlUnitPacketResNullifiedAnim
{
    BtlUnit* unit; // 0x00
    f32 unk_4;     // 0x04
    u32 counter;   // 0x08
} BtlUnitPacketResNullifiedAnim;

void btlUnitInitResNullifiedAnimPacket(void* work);
u32 btlUnitUpdateResNullifiedAnimPacket(void* work);
void btlUnitDestroyResNullifiedAnimPacket(void* work);

// 24 bytes
typedef struct BtlUnitPacket00284900
{
    RwV3d pos;     // 0x00
    BtlUnit* unit; // 0x0c
    u16 unk_10;    // 0x10
    u16 unk_12;    // 0x12
    f32 phase;     // 0x14
} BtlUnitPacket00284900;

void btlUnitInit00284900Packet(void* work);
u32 btlUnitUpdate00284900Packet(void* work);
void btlUnitDestroy00284900Packet(void* work);

// 16 bytes
typedef struct BtlUnitPacketEnmDodgeAnim
{
    BtlUnit* unit; // 0x00
    s32 unk_4;     // 0x04
    f32 phase;     // 0x08
    f32 step;      // 0x0c
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









/* W389 measured: opt_loop_invariants on nd964->936, object 1260/1328 -> 1244/1328. */

/* W389 measured: opt_propagation off (replacing prior loop-invariants scope) nd871->862, object 1176/1232 -> 1168/1232. */



/* W389 measured: opt_dead_assignments off nd246->245, object 528/528 -> 528/528. */


// FUN_0027F530
void func_0027f530(BtlUnit* unit)
{
    unit->scale = 1.0f;
    unit->pos = D_00957180;
    unit->posOffset = D_00957180;

    unit->rot.real = 1.0f;
    unit->rot.imag.x = 0.0f;
    unit->rot.imag.y = 0.0f;
    unit->rot.imag.z = 0.0f;

    unit->cols[0].r = 0xff;
    unit->cols[0].g = 0xff;
    unit->cols[0].b = 0xff;
    unit->cols[0].a = 0xff;
    unit->cols[1] = unit->cols[0];
    unit->cols[3] = unit->cols[0];
    unit->cols[4] = unit->cols[0];

    unit->unk_4c = 0;
    unit->unk_54 = D_00957180;
    unit->unk_70.imag.x = 0.0f;
    unit->unk_70.imag.y = 0.0f;
    unit->unk_70.imag.z = 0.0f;
    unit->unk_70.real = 0.5f;
}










/* Removing this loses func_0027fc80 (MATCH nd0 -> MISMATCH nd18) - measured W161. */




































// 8 bytes
typedef struct BtlUnitPacket002843e0
{
    BtlUnit* unit; // 0x00
    s16 unk_4;     // 0x04
    u8 unkData[0x02];
} BtlUnitPacket002843e0;














































































/* W389 measured: opt_propagation off nd742->707, object 988/992 -> 984/992. */


/* Data tables used by the retail animation and character helpers. */
extern const u8 DAT_00693290[];
extern const u8 DAT_006932e0[];
extern const u8* iGpffffb718;
extern const u8* iGpffffb71c;
extern const u8* iGpffffb728;
extern const u8* iGpffffb73c;
extern const u16 gp0xffff9828[];
extern u8* iGpffffb710;

extern u16 func_002fb860(void);
extern void* func_00308c60(DatUnit* unit);
extern s16 func_003082f0(DatUnit* unit, u16 id);
extern long func_002d6370(u64 id);
extern f32 func_00318910(Model* mdl, u32 slot, s16 id);
extern void func_002d4040(BtlUnit* unit);
extern void func_001a0dc0(u16 resTypeId, u32 enable);
extern u32 func_0031c7e0(Model* model);
extern u32 func_0031ebe0(void* data);
extern void func_002bbd00(void* data);
extern void func_002bb8f0(void* data);
extern void func_002b7000(BtlUnit* unit, s8 slot, u32 value);
extern f32 func_004c6ac0(const RwV3d* value);
extern void* func_00174800(u64 id);
extern u32 func_0030b5a0(DatUnit* unit, u32 flag);
extern void func_002f9c10(BtlAction* action);







static s16 btlUnitAnimCategory(const BtlUnit* unit, s16 id)
{
    if (unit->genus == UNIT_GENUS_EC)
    {
        if (id == 4 || id == 5 || id == 6)
        {
            return 0;
        }
        return -1;
    }

    if (id == 4)
    {
        return 0;
    }
    if (id == 5)
    {
        return 1;
    }
    if (id == 6)
    {
        return 2;
    }
    return -1;
}






typedef struct BtlUnitPacketResource
{
    BtlUnit* unit;
    u16 type;
    u16 id;
    u16 flags;
    u8 unkData[2];
    u32 state;
} BtlUnitPacketResource;





/* W389 measured: opt_propagation off nd2216->2197, object 3760/3776 -> 3672/3776. */
extern void func_00287ea0(BtlUnit* unit);
extern u32 DAT_007cc970;
void FUN_002878d0(BtlUnit* unit);
extern void func_002d3fe0(BtlUnit* unit);
extern void mdl00319050(Model* mdl);
extern void mdl00319070(Model* mdl);
extern void mdl003191b0(Model* mdl);
extern u32 func_0017d800(void);
extern void* func_00198580(void);
extern void* func_003b54c0(void* value);
extern void* func_003b5d50(u32 value);
extern void func_004944b0(void* dst, const void* src);
extern void func_004cb7f0(void* dst, const void* src, u32 mode);
extern u32 func_004c9d10(void* value);
extern void func_004c9d00(void* value);
extern void func_004d7f60(u32 group, u32 value);
extern void func_003294d0(void);
extern void func_00329550(void);
extern void func_00358460(const RwRGBA* color, u32 mode);
extern u32 func_00198560(void);
extern u32 func_00198570(void);
extern u32 func_00198590(void);
extern void func_00317a20(Model* mdl);

extern void* DAT_0096017c[];
static void btlUnitUnlinkAndFree(BtlUnit* unit)
{
    BtlUnitList* list;

    list = &gBtl->unitLists[unit->genus];
    if (unit->prev != NULL)
    {
        unit->prev->next = unit->next;
    }
    else
    {
        list->head = unit->next;
    }
    if (unit->next != NULL)
    {
        unit->next->prev = unit->prev;
    }
    else
    {
        list->tail = unit->prev;
    }
    RwFree(unit);
}








/* Recovered battle-misc harvest: 0x00287EA0-0x00289650 */




typedef struct BtlUnitSortEntry
{
    u8 unk_0[0x128];
    Model* mdl;
} BtlUnitSortEntry;


/* W389 measured: opt_lifetimes on + opt_propagation off nd503->498, object 1136/1136 -> 1116/1136. */

// W295: NOT a floor - retail loads the lhu (persona id) before `move $a0,$s1`;
// a volatile-cast temp for the id reproduces it.

/* Recovered battle-misc harvest: 0x00287B20-0x00287CF0 */
#pragma opt_loop_invariants reset
