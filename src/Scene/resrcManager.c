#include "Scene/resrcManager.h"
#include "Main/g_data.h"
#include "Graphics/Model/mdlManager.h"
#include "rw/rwplcore.h"
#include "temporary.h"
#include "Kosaka/k_assert.h"

// FUN_003b4fc0
ResrcManager* resrcMngCreate()
{
    ResrcManager* resMgr;

    resMgr = RwMalloc(sizeof(ResrcManager), rwMEMHINTDUR_GLOBAL);
    memset(resMgr, 0, sizeof(ResrcManager));
    
    return resMgr;
}

// FUN_003b5020
void resrcMngDestroy(ResrcManager* resManager)
{
    s32 i;
    Resrc* currList;

    if (resManager != NULL)
    {
        for (i = 0; i < RESRC_TYPE_MAX; i++)
        {
            currList = resrcMngGetListHead(resManager, i);

            while (currList != NULL)
            {
                resrcMngDestroyRes(resManager, currList);

                currList = resrcMngGetListHead(resManager, i);
            }
        }

        RwFree(resManager);
    }
}

// FUN_003b50d0
Resrc* resrcMngCreateRes(ResrcManager* resManager, u16 resTypeId)
{
    Resrc* res;
    Resrc* currRes;
    Resrc* listHead;
    u32 resSize;
    u16 resId;
    s32 resType;

    resId = resTypeId & 0xffff;
    resType = RESRC_GET_TYPE(resId);
    resSize = 0;
    if (resType >= RESRC_TYPE_MAX)
    {
        printf("warning!! not known resrc!! %s\n", __FILE__);
        return NULL;
    }

    switch (resType)
    {
    case RESRC_TYPE_MODELCHAR:
        resSize = sizeof(ResrcModelChar);
        break;
    case RESRC_TYPE_MODELUNK:
        resSize = 0x1d0;
        break;
    case RESRC_TYPE_MODELNPC:
        resSize = sizeof(ResrcModelNpc);
        break;
    case RESRC_TYPE_LIGHTCHAR:
        resSize = sizeof(ResrcLightChar);
        break;
    case RESRC_TYPE_LIGHTNPC:
        resSize = sizeof(ResrcLightNpc);
        break;
    case RESRC_TYPE_06:
        resSize = 0x108;
        break;
    case RESRC_TYPE_07:
        resSize = 0x110;
        break;
    case RESRC_TYPE_08:
        resSize = sizeof(Resrc);
        break;
    case RESRC_TYPE_MODELFLD:
        resSize = sizeof(ResrcModelFld);
        break;
    case RESRC_TYPE_11:
        resSize = 0x108;
        break;
    case RESRC_TYPE_FLD:
        resSize = sizeof(ResrcFld);
        break;
    case RESRC_TYPE_FLDHIT:
    case RESRC_TYPE_21:
        resSize = 0x150;
        break;
    case RESRC_TYPE_14:
    case RESRC_TYPE_15:
    case RESRC_TYPE_16:
    case RESRC_TYPE_17:
    case RESRC_TYPE_18:
    case RESRC_TYPE_19:
        resSize = 0x110;
        break;
    case RESRC_TYPE_20:
        resSize = 0x120;
        break;
    }

    if (resSize == 0)
    {
        return NULL;
    }

    res = RwMalloc(resSize, rwMEMHINTDUR_GLOBAL);
    memset(res, 0, resSize);
    res->resTypeId = resTypeId;
    res->unk_24 = 1.0f;
    res->unk_20 = 1.0f;
    res->unk_1c = 1.0f;

    currRes = resManager->resLists[resType];
    for (listHead = currRes; listHead != NULL; listHead = listHead->next)
    {
        if (listHead->resTypeId == resId)
        {
            RwFree(res);
            printf("warning!! duplicate resID!! not regist!%s\n", __FILE__);
            K_ASSERT(false, 0xa8);
            return NULL;
        }
    }

    if (currRes != NULL)
    {
        while (currRes->next != NULL)
        {
            currRes = currRes->next;
        }

        currRes->next = res;
        res->prev = currRes;
        res->next = NULL;
    }
    else
    {
        resManager->resLists[resType] = res;
        res->next = NULL;
        res->prev = NULL;
    }

    return res;
}

// FUN_003b5360
void resrcMngDestroyRes(ResrcManager* resManager, Resrc* res)
{
    Resrc* currRes;
    Resrc* prevRes;
    Resrc* nextRes;

    currRes = resManager->resLists[RESRC_GET_TYPE(res->resTypeId)];
    while (currRes != NULL)
    {
        if (res == currRes)
        {
            prevRes = currRes->prev;
            nextRes = currRes->next;
            if (prevRes == NULL)
            {
                resManager->resLists[RESRC_GET_TYPE(res->resTypeId)] = res->next;
            }
            if (nextRes != NULL)
            {
                nextRes->prev = prevRes;
            }
            if (prevRes != NULL)
            {
                prevRes->next = nextRes;
            }
            if (res->ownedData != NULL)
            {
                RwFree(res->ownedData);
                res->ownedData = NULL;
            }
            RwFree(res);
            return;
        }
        else
        {
            currRes = currRes->next;
        }
    }
}

// FUN_003b5430. Return the head of a list of a resource type
Resrc* resrcMngGetListHead(ResrcManager* resManager, u8 resType)
{
    if (resType >= RESRC_TYPE_MAX)
    {
        return NULL;
    }

    return resManager->resLists[resType];
}

// FUN_003b5460. Return the tail of a list of a resource type
Resrc* resrcMngGetListTail(ResrcManager* resManager, u8 resType)
{
    Resrc* currRes;
    
    if (resType >= RESRC_TYPE_MAX)
    {
        return NULL;
    }

    currRes = resManager->resLists[resType];
    if (currRes == NULL)
    {
        return currRes;
    }

    while (currRes->next != NULL)
    {
        currRes = currRes->next;
    }

    return currRes;
}

// FUN_003b54c0. Return a resource by a resTypeId
Resrc* resrcMngGetRes(ResrcManager* resManager, u16 resTypeId)
{
    u8 type;
    Resrc* currRes;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == 0)
    {
        return NULL;
    }

    if (type >= RESRC_TYPE_MAX)
    {
        return NULL;
    }

    for (currRes = resManager->resLists[type]; currRes != NULL; currRes = currRes->next)
    {
        if (currRes->resTypeId == resTypeId)
        {
            return currRes;
        }
    }

    return NULL;
}

// FUN_003b5550. Return the total number of resource in a list by a resType
u32 resrcMngGetTotalResInList(ResrcManager* resManager, u8 resType)
{
    u32 total;
    Resrc* currRes;

    total = 0;
    if (resType >= RESRC_TYPE_MAX)
    {
        return total;
    }

    for (currRes = resManager->resLists[resType]; currRes != NULL; currRes = currRes->next)
    {
        total++;
    }

    return total;
}
