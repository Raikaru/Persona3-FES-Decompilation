#include "h_maestro.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rt2danim.h"
#include "h_cdvd.h"
#include "temporary.h"

extern u32 FUN_004c2090(void* param_1);
extern f32 FUN_004b1a70(u32 param_1);
extern f32 FUN_004b1a60(u32 param_1);
extern void FUN_004b1870(u32 param_1, u32 param_2, u32 param_3);
extern f32 fGpffff80e4;

// FUN_00111610
void* H_Maestro_UpdateTask(KwlnTask* hmaestroTask)
{
    // TODO

    return KWLNTASK_CONTINUE;
}

// FUN_00111d50
void H_Maestro_SetAlphaMult(KwlnTask* hmaestroTask, f32 alphaMult)
{
    ((HMaestro*)hmaestroTask->workData)->alphaMult = alphaMult;
}

// FUN_00111d60
void H_Maestro_DestroyTask(KwlnTask* hmaestroTask)
{
    HMaestro* work;

    work = (HMaestro*)hmaestroTask->workData;

    if (work->cdvd != NULL)
    {
        H_Cdvd_Destroy(work->cdvd);
        work->cdvd = NULL;
    }

    if (work->maestro != NULL)
    {
        Rt2dMaestroDestroy(work->maestro);
        work->maestro = NULL;
    }

    RwFree(work);
}

// FUN_00111dd0
KwlnTask* H_Maestro_CreateTask(KwlnTask* parent, u32 priority, const char* path)
{
    KwlnTask* task;
    HMaestro* work;

    work = RwCalloc(1, sizeof(HMaestro), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent,
                          "H_DrawMaestro",
                          priority,
                          H_Maestro_UpdateTask,
                          H_Maestro_DestroyTask,
                          work);
    if (task == NULL)
    {
        return NULL;
    }

    strcpy(work->path, path);
    work->noDeltaTime = false;
    work->shouldLoop = false;
    work->alphaMult = 1.0f;
    work->useCdvd = false;

    return task;
}

// FUN_00111c50
void H_Maestro_00111c50(KwlnTask* hmaestroTask)
{
    HMaestro* work;
    u32 anim;

    work = (HMaestro*)hmaestroTask->workData;
    anim = FUN_004c2090(*(void**)((u8*)work->maestro + 8));
    FUN_004b1870(anim + 4, anim + 0x20, 0);
    work->state = HMAESTRO_STATE_IDLE;
}

// FUN_00111cb0
u32 H_Maestro_00111cb0(KwlnTask* hmaestroTask)
{
    HMaestro* work;
    u32 anim;
    f32 animEnd;
    f32 animCurrent;

    work = (HMaestro*)hmaestroTask->workData;
    if (work->state == HMAESTRO_STATE_DRAW)
    {
        anim = FUN_004c2090(*(void**)((u8*)work->maestro + 8));
        animEnd = FUN_004b1a70(anim + 4);
        animCurrent = FUN_004b1a60(anim + 4);

        return !(animEnd > fGpffff80e4 + animCurrent);
    }

    return true;
}

// FUN_00111ec0
u32 H_Maestro_FinishedInit(KwlnTask* hmaestroTask)
{
    return ((HMaestro*)hmaestroTask->workData)->state > HMAESTRO_STATE_INITSCENE;
}

// FUN_00111ee0
void H_Maestro_RequestDraw(KwlnTask* hmaestroTask)
{
    ((HMaestro*)hmaestroTask->workData)->state = HMAESTRO_STATE_DRAW;
}

// FUN_00111f00
void H_Maestro_SetShouldLoop(KwlnTask* hmaestroTask, u32 shouldLoop)
{
    ((HMaestro*)hmaestroTask->workData)->shouldLoop = shouldLoop;
}

// FUN_00111f20
void H_Maestro_00111f20(KwlnTask* hmaestroTask, u32 param_2)
{
    ((HMaestro*)hmaestroTask->workData)->unk_120 = param_2;
}

// FUN_00111f30
u32 H_Maestro_00111f30(s16* param_1)
{
    return *param_1 == 5;
}
