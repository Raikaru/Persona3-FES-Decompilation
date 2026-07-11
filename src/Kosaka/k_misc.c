#include "Utils.h"
#define DATCALENDAR_H
typedef struct CalendarWork
{
    s16 daysSinceApr5;
    s8 time;
    u32 skipToTarget;
    s16 daysSkipTarget;
    s8 timeSkipTarget;
} CalendarWork;
#include "Main/g_data.h"
#undef DATCALENDAR_H
#include "libm.h"
#include "Kosaka/k_misc.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Graphics/Model/mdlManager.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "rw/rwplcore.h"
#include "rw/rpusrdat.h"
#include "temporary.h"
extern u32 clndIsHolidayOrSunday(void);
extern u32 clndIsDateInRange(u32 startMonth, u32 startDay, u32 endMonth, u32 endDay);
typedef struct RmdFadeWork
{
    u32 unk_00;             // 0x00
    Model* mdl;             // 0x04
    f32 targetAlpha;        // 0x08
    f32 currentAlpha;       // 0x0c
    s32 framesRemaining;    // 0x10
} RmdFadeWork;


// FUN_001a5c50
u32 K_Misc_FindNextFreeResId(u16 resType)
{
    u32 currId;
    Resrc* res;

    currId = 0;
    res = MT_Scene_GetResListHead(resType);
    while (res != NULL)
    {
        if (RESRC_GET_ID(res->resTypeId) == currId)
        {
            currId++;
            res = MT_Scene_GetResListHead(resType);
        }
        else
        {
            res = res->next;
        }
    }

    return (u16)currId;
}
// FUN_001A5CD0
void func_001a5cd0(void)
{
    s32 usePrimaryFlag;

    usePrimaryFlag = 0;
    if (clndIsHolidayOrSunday() == true)
    {
        if (clndIsDateInRange(7, 0x1b, 8, 2) == true)
        {
            usePrimaryFlag = 1;
        }
        if (clndIsDateInRange(8, 10, 8, 0xf) == true)
        {
            usePrimaryFlag = 1;
        }
        if (clndIsDateInRange(0xb, 0x11, 0xb, 0x14) == true)
        {
            usePrimaryFlag = 1;
        }
    }
    else
    {
        usePrimaryFlag = 1;
    }

    if (usePrimaryFlag == true)
    {
        datSetFlag(0xa88, true);
        datSetFlag(0xa89, false);
    }
    else
    {
        datSetFlag(0xa88, false);
        datSetFlag(0xa89, true);
    }
}

// FUN_001A5F30 NONMATCHING
void* func_001a5f30(KwlnTask* rmdFadeTask)
{
    RmdFadeWork* work;
    RwRGBA color;

    work = (RmdFadeWork*)rmdFadeTask->workData;
    (void)sinf((3.14159274f * (f32)work->framesRemaining) / 30.0f);
    *(u32*)&color = 0xffffffff;
    if (work->framesRemaining < 1)
    {
        color.a = (u8)work->targetAlpha;
        mdlSetColor(work->mdl, &color);
        return KWLNTASK_STOP;
    }

    work->currentAlpha +=
        (work->targetAlpha - work->currentAlpha) / (f32)work->framesRemaining;
    color.a = (u8)work->currentAlpha;
    mdlSetColor(work->mdl, &color);
    work->framesRemaining--;

    return KWLNTASK_CONTINUE;
}

// FUN_001A60A0
void func_001a60a0(KwlnTask* rmdFadeTask)
{
    RwFree(rmdFadeTask->workData);
}

// FUN_001A60D0 NONMATCHING
KwlnTask* func_001a60d0(KwlnTask* parentTask, Model* mdl, u32 targetAlpha, s32 frames)
{
    RmdFadeWork* work;
    KwlnTask* task;
    RwRGBA color;

    if (mdl == NULL)
    {
        return NULL;
    }

    work = RwCalloc(1, sizeof(RmdFadeWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parentTask,
                                          0x106f,
                                          "rmd fade(kosaka)",
                                          func_001a5f30,
                                          func_001a60a0,
                                          work);

    work->mdl = mdl;
    work->targetAlpha = (f32)targetAlpha;
    work->framesRemaining = frames;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    if (targetAlpha == 0)
    {
        work->currentAlpha = 255.0f;
        color.a = 255;
    }
    else
    {
        work->currentAlpha = 0.0f;
        color.a = 0;
    }
    mdlSetColor(mdl, &color);

    return task;
}


// FUN_001a5de0
void* K_Misc_UpdateDelayMdlFreeTask(KwlnTask* delayMdlFreeTask)
{
    DelayMdlFreeWork* work;

    work = (DelayMdlFreeWork*)delayMdlFreeTask->workData;

    switch (work->state)
    {
        case DELAYMDLFREE_STATE_WAITSTREAM:
            if (mdlStreamRead(work->mdlToDestroy))
            {
                work->state++;
            }
            break;

        case DELAYMDLFREE_STATE_DESTROYING:
            mdlDestroy(work->mdlToDestroy);
            return KWLNTASK_STOP;
    }

    return KWLNTASK_CONTINUE;
}

// FUN_001a5e70
void K_Misc_DestroyDelayMdlFreeTask(KwlnTask* delayMdlFreeTask)
{
    RwFree(delayMdlFreeTask->workData);
}

// FUN_001a5ea0
KwlnTask* K_Misc_CreateDelayMdlFreeTask(Model* mdlToDestroy)
{
    DelayMdlFreeWork* work;
    KwlnTask* task;

    work = RwCalloc(1, sizeof(DelayMdlFreeWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(NULL,
                                          10,
                                          "delay model free",
                                          K_Misc_UpdateDelayMdlFreeTask,
                                          K_Misc_DestroyDelayMdlFreeTask,
                                          work);

    work->mdlToDestroy = mdlToDestroy;

    return task;
}

// FUN_001a6260
void* K_Misc_UpdateScrShutdownTask(KwlnTask* scrShutdownTask)
{
    kwlnTaskDestroyWithHierarchy(((ScrShutdownWork*)scrShutdownTask->workData)->scrTask);

    return KWLNTASK_STOP;
}

// FUN_001a6290
void K_Misc_DestroyScrShutdownTask(KwlnTask* scrShutdownTask)
{
    RwFree(scrShutdownTask->workData);
}

// FUN_001a62c0
KwlnTask* K_Misc_CreateScrShutdownTask(KwlnTask* scrTask)
{
    ScrShutdownWork* work;
    KwlnTask* task;

    work = RwCalloc(1, sizeof(ScrShutdownWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(NULL, 
                                          10,
                                          "script shutdown(kosaka)",
                                          K_Misc_UpdateScrShutdownTask,
                                          K_Misc_DestroyScrShutdownTask,
                                          work);

    work->scrTask = scrTask;

    return task;
}

// FUN_001a6350
RpUserDataArray* func_001a6350(const RpMaterial* material, const char* name)
{
    s32 i;
    RpUserDataArray* userData;

    i = 0;
    while (i < RpMaterialGetUserDataArrayCount(material))
    {
        userData = RpMaterialGetUserDataArray(material, i);
        if (strcmp(RpUserDataArrayGetName(userData), name) == 0)
        {
            break;
        }
        i++;
    }
    return userData;
}