#include "Main/Game/gm_root.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"

#pragma alias gmRootStartOpeningTask FUN_002663c0
#pragma alias gmRootStartCalendarTask FUN_00266430
#pragma alias opRootCreateTask FUN_00265c20
#pragma alias gmRootSetResult FUN_00266660
#pragma alias datGetAuxData FUN_0016f380
#pragma alias datSetAuxData FUN_0016f3e0
#pragma alias H_Malloc FUN_00191af0
#pragma alias kwlnTaskCreateWithAutoPriority FUN_00194b80
#pragma alias kwlnTaskInitEx FUN_00194e10
#pragma alias kwlnTaskAddChild FUN_00195550
#pragma alias kwlnSetClearColor FUN_001985b0
#pragma alias opRootUpdateTask FUN_00265dc0
#pragma alias opRootDrawTask FUN_00265e30
#pragma alias opRootDestroyTask FUN_00265ef0
#pragma alias opResInit FUN_00266670
#pragma alias opLogoInit FUN_00269cc0
#pragma alias opTitleInit FUN_002673a0
#pragma alias opWaitInit FUN_0026dd10
#pragma alias opMenuInit FUN_0026a230
#pragma alias opFadeInit FUN_00271cd0
#pragma alias opFadeSetColor FUN_00272220
#pragma alias opFadeIn FUN_00272290
#pragma alias opResRequestLogo FUN_00266cb0
#pragma alias H_Fade_FadeIn FUN_001085c0
#pragma alias H_Fade_SetType FUN_00108670
#pragma alias H_Fade_SetDuration FUN_001086a0

static GmRootWork* sWork; // 007ce38c
static u32 sResult; // 007ce390


void gmRootStartOpeningTask(void);
void gmRootStartCalendarTask(void);
u32 datGetAuxData(u32 idx);
void datSetAuxData(u32 idx, u32 value);
u32 datGetFlag(s32 bit);
u32 datGetScenarioMode(void);
void func_0017d820(u32 arg);
u32 func_00182750(u32 arg);
void func_00188670(u32 arg);
u32 func_0017fad0(void);
u32 clndCreateTask(void);
u64 func_00188660(void);
void func_00188680(void);
KwlnTask* func_00188860(KwlnTask* parent);
void opRootUpdateTask(void);
void opRootDrawTask(void);
void opRootDestroyTask(int param_1);

void* gmRootUpdateTask(KwlnTask* gmRootTask);
void gmRootDestroyTask(KwlnTask* gmRootTask);
// FUN_00266140
void gmRootUpdate()
{
    GmRootWork* work;
    s32 result;
    u32 value;
    u32 flags;

    K_ASSERT(sWork != NULL, 90);
    work = sWork;
    flags = work->flags;
    if (!(~flags & GMROOT_FLAG_ACTIVE))
    {
        if ((flags & GMROOT_FLAG_UNK2) &&
            kwlnTaskExists((KwlnTask*)work->unk_0c) == 0)
        {
            work->unk_14 = sResult;
            work->flags &= ~GMROOT_FLAG_UNK2;
        }
        if ((work->flags & GMROOT_FLAG_UNK4) &&
            kwlnTaskExists((KwlnTask*)work->unk_10) == 0)
        {
            work->flags &= ~GMROOT_FLAG_UNK4;
        }

        switch (work->unk_04)
        {
            case 0:
                if (kwlnTaskExists(work->chkMemcardTask) == 0)
                {
                    gmRootStartOpeningTask();
                    return;
                }
                break;
            case 1:
                if (!(work->flags & GMROOT_FLAG_UNK2))
                {
                    result = work->unk_14;
                    switch (result)
                    {
                        case 0:
                            if (datGetScenarioMode() != 0)
                            {
                                func_0017d820(0);
                                work->unk_10 = func_00182750(0);
                            }
                            else
                            {
                                func_00188670(0);
                                work->unk_10 = func_0017fad0();
                            }
                            break;
                        case 1:
                            if (datGetScenarioMode() != 0)
                            {
                                work->unk_10 = func_00182750(0);
                            }
                            else
                            {
                                work->unk_10 = clndCreateTask();
                            }
                            break;
                        default:
                            K_ASSERT(false, 188);
                            break;
                    }
                    work->flags |= GMROOT_FLAG_UNK4;
                    work->unk_04 = 2;
                    return;
                }
                break;
            case 2:
                if (datGetFlag(0x1418) == 0)
                {
                    value = datGetAuxData(0x2f);
                    if (value != 0x7fffffff)
                    {
                        value++;
                    }
                    datSetAuxData(0x2f, value);
                }
                if (!(work->flags & GMROOT_FLAG_UNK4))
                {
                    if (datGetFlag(0x1413) != 0)
                    {
                        gmRootStartCalendarTask();
                        return;
                    }
                    gmRootStartOpeningTask();
                }
                break;
        }
    }
}

static inline KwlnTask* createTask(KwlnTask* parent)
{
    GmRootWork* work;
    KwlnTask* task;

    work = RwMalloc(sizeof(GmRootWork), rwMEMHINTDUR_GLOBAL);
    task = kwlnTaskCreateWithAutoPriority(parent,
                                          10,
                                          "game root",
                                          gmRootUpdateTask,
                                          gmRootDestroyTask,
                                          work);

    work->flags = 0;
    work->task = task;

    sWork = work;

    return task;
}

// FUN_002664c0
KwlnTask* gmRootCreateTask(KwlnTask* parent)
{
    GmRootWork* work;
    KwlnTask* task;

    task = createTask(parent);

    K_ASSERT(sWork != NULL, 90);

    work = sWork;
    work->chkMemcardTask = func_00188860(work->task);
    work->unk_04 = 0;
    work->flags |= GMROOT_FLAG_ACTIVE;

    return task;
}

// FUN_00266590
void* gmRootUpdateTask(KwlnTask* gmRootTask)
{
    gmRootUpdate();

    K_ASSERT(sWork != NULL, 90);

    if (sWork->flags & GMROOT_FLAG_ACTIVE)
    {
        return KWLNTASK_CONTINUE;
    }

    return KWLNTASK_STOP;
}

// FUN_00266600
void gmRootDestroyTask(KwlnTask* gmRootTask)
{
    K_ASSERT(sWork != NULL, 90);

    sWork = NULL;
    RwFree(gmRootTask->workData);
}


void kwlnInitGameData(void);
u32 opRootCreateTask(KwlnTask* task);

// FUN_002663c0
void gmRootStartOpeningTask(void)
{
    GmRootWork* work;

    K_ASSERT(sWork != NULL, 90);
    work = sWork;
    kwlnInitGameData();
    work->unk_0c = opRootCreateTask(work->task);
    work->flags |= GMROOT_FLAG_UNK2;
    work->unk_04 = 1;
}

// FUN_00266430
void gmRootStartCalendarTask(void)
{
    GmRootWork* work;

    K_ASSERT(sWork != NULL, 90);
    work = sWork;
    K_ASSERT(func_00188660(), 0xfd);
    func_00188680();
    work->unk_10 = clndCreateTask();
    work->flags |= GMROOT_FLAG_UNK4;
    work->unk_04 = 2;
}
extern u32 H_Malloc();
extern u32 kwlnCreateTaskWithAutoPriority();
extern u32 kwlnInitTaskEx();
extern void kwlnAddTaskChild();
extern void kwlnSetClearColor();
extern void opResInit();
extern void opLogoInit();
extern void opTitleInit();
extern void opWaitInit();
extern void opMenuInit();
extern void opFadeInit();
extern void opFadeSetColor();
extern void opFadeIn();
extern void H_Fade_FadeIn();
extern void H_Fade_SetType();
extern void H_Fade_SetDuration();
extern void opResRequestLogo();


// FUN_00266660
void gmRootSetResult(u32 result)
{
    sResult = result;
}
