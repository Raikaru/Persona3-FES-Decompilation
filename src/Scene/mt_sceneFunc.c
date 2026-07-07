#include "Scene/mt_sceneFunc.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "Kernel/Kwln/kwlnTask.h"

void FUN_003bcc80();
void FUN_003bceb0(Resrc* res);
void FUN_0034fd70(Model* mdl, s32 type);

// FUN_003bccb0
void* MT_SceneFunc_UpdateSceneMngTask(KwlnTask* sceneMngTask)
{
    // TODO

    return KWLNTASK_CONTINUE;
}

// FUN_003bcd80
void MT_SceneFunc_DestroySceneMngTask(KwlnTask* sceneMngTask)
{
    FUN_003bcc80();
}

// FUN_003bd010
void* MT_SceneFunc_UpdateSceneMngDrawTask(KwlnTask* sceneMngDrawTask)
{
    Resrc* res;

    res = MT_Scene_GetResListHead(6);
    FUN_003bceb0(res);
    for (; res != NULL; res = res->next)
    {
        if ((res->flags & 2) != 0 && *(Model**)((u8*)res + 0x104) != NULL)
        {
            switch (*(s8*)((u8*)res + 0x100))
            {
            case 0:
                break;
            case 1:
                FUN_0034fd70(*(Model**)((u8*)res + 0x104), 6);
                break;
            default:
                break;
            }
        }
    }

    return KWLNTASK_CONTINUE;
}

// FUN_003bd0b0
KwlnTask* MT_SceneFunc_CreateTasks()
{
    KwlnTask* sceneMngTask;

    sceneMngTask = kwlnTaskCreate(NULL,
                                  "SceneManager Task",
                                  110,
                                  MT_SceneFunc_UpdateSceneMngTask,
                                  MT_SceneFunc_DestroySceneMngTask,
                                  NULL);


    kwlnTaskCreate(sceneMngTask,
                   "SceneManager Draw",
                   2109,
                   MT_SceneFunc_UpdateSceneMngDrawTask,
                   NULL,
                   NULL);

    return sceneMngTask;
}