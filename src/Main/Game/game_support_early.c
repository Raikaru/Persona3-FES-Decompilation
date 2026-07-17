#include "Main/g_data.h"
#include "Main/Game/game_support.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/Field/k_dungeon.h"

/*
 * These helpers are implemented by the game-support and memory-card modules.
 * Their retail symbols are kept here until those modules are decompiled.
 */
extern KwlnTask* func_00420340(KwlnTask* parentTask, u32 mode);
extern u32 func_004204f0(KwlnTask* task);
extern KwlnTask* func_004214e0(KwlnTask* parentTask, u32 mode);
extern void func_004215b0(KwlnTask* task, u32 state);
extern void func_00421650(KwlnTask* task);
extern u32 func_00421700(KwlnTask* task);
extern void func_00191240(void);
extern s32 func_00191260(void);
extern void func_001967d0(void);

/* Retail small-data globals used by the two game-support state machines. */
extern KwlnTask* DAT_007ce000;
extern u32 DAT_007ce00c;
extern u32 uGpffffb31c;
extern KwlnTask* uGpffffb314;

/* Runtime allocator/free-function tables. */
extern u32 D_00960184[];
extern u32 jtbl_0096017C[];

/* Task names live in the retail read-only data segment. */
extern const char D_005E42F0[];
extern const char D_005E4308[];

typedef struct GameSupportMemcardWork
{
    u32 state;
    s32 result;
    u32 timer;
    KwlnTask* task;
} GameSupportMemcardWork;

typedef struct GameSupportLoadWork
{
    u32 state;
    KwlnTask* task;
    KwlnTask* transitionTask;
} GameSupportLoadWork;

// FUN_001885A0
u32 func_001885a0(void)
{
    u32 floor;

    floor = K_FldDungeon_GetCurrentFloor();
    FUN_0016f3e0(0x35, floor);
    DAT_007ce00c = 0;
    DAT_007ce000 = func_00420340(NULL, 1);
    return 1;
}

// FUN_001885F0
u32 func_001885f0(void)
{
    u32 state;

    state = kwlnTaskGetState(DAT_007ce000);
    if (state == 3)
    {
        DAT_007ce000 = NULL;
        return 1;
    }

    return 0;
}

// FUN_00188640
u64 func_00188640(void)
{
    return 0;
}

// FUN_00188650
void func_00188650(void)
{
    return;
}

// FUN_00188660
u64 func_00188660(void)
{
    return 0;
}

// FUN_00188670
void func_00188670(void)
{
    return;
}

// FUN_00188680
void func_00188680(void)
{
    return;
}

// FUN_00188690
void* func_00188690(KwlnTask* task)
{
    GameSupportMemcardWork* work;
    u32 status;

    work = (GameSupportMemcardWork*)task->workData;

    switch (work->state)
    {
        case 0:
            work->task = func_004214e0(task, 1);
            work->state = 1;
            break;

        case 1:
            func_004215b0(work->task, 0xf);
            work->timer = 0x3c;
            work->state = 2;
            break;

        case 2:
            work->timer--;
            if (work->timer == 0)
            {
                func_00191240();
                work->state = 3;
            }
            break;

        case 3:
            status = (u32)func_00191260();
            work->result = (s32)status;
            if (status != 0)
            {
                if (status == 100)
                {
                    func_00421650(work->task);
                    return KWLNTASK_STOP;
                }
                work->state = 4;
            }
            break;

        case 4:
            if (work->result == -6)
            {
                func_004215b0(work->task, 0x15);
            }
            else
            {
                func_004215b0(work->task, 0x10);
            }
            work->state = 5;
            break;

        case 5:
            status = func_00421700(work->task);
            if (status == 1)
            {
                func_00421650(work->task);
                return KWLNTASK_STOP;
            }
            if (status == 2)
            {
                work->state = 1;
            }
            break;
    }

    return KWLNTASK_CONTINUE;
}

// FUN_00188830
void func_00188830(KwlnTask* task)
{
    (*(void (**)(void*))jtbl_0096017C)(task->workData);
}

// FUN_00188860
KwlnTask* func_00188860(KwlnTask* parentTask)
{
    void* work;
    KwlnTask* task;

    work = (*(void* (**)(u32, u32, u32))D_00960184)(1, 0x10, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parentTask,
                                          0x106f,
                                          D_005E42F0,
                                          func_00188690,
                                          func_00188830,
                                          work);
    if (task == NULL)
    {
        return NULL;
    }
    return task;
}

// FUN_00188900
void* func_00188900(KwlnTask* task)
{
    GameSupportLoadWork* work;
    u32 status;

    work = (GameSupportLoadWork*)task->workData;

    switch (work->state)
    {
        case 0:
            func_001967d0();
            work->task = func_004214e0(task, 1);
            work->state = 1;
            break;

        case 1:
            func_004215b0(work->task, 0x11);
            work->state = 2;
            break;

        case 2:
            status = func_00421700(work->task);
            if (status == 1)
            {
                func_004215b0(work->task, 0x12);
                work->state = 4;
            }
            else if (status == 2)
            {
                func_004215b0(work->task, 0x13);
                work->state = 3;
            }
            break;

        case 3:
            status = func_00421700(work->task);
            if (status == 1)
            {
                func_00421650(work->task);
                return KWLNTASK_STOP;
            }
            if (status == 2)
            {
                work->state = 1;
            }
            break;

        case 4:
            status = func_00421700(work->task);
            if (status == 1)
            {
                func_00421650(work->task);
                uGpffffb31c = 0;
                work->transitionTask = func_00420340(task, 1);
                work->state = 5;
            }
            break;

        case 5:
            status = kwlnTaskGetState(work->transitionTask);
            if (status == 3)
            {
                status = func_004204f0(work->transitionTask);
                if (status == 0)
                {
                    work->task = func_004214e0(task, 1);
                    func_004215b0(work->task, 0x13);
                    work->state = 3;
                }
                else
                {
                    func_00421650(work->task);
                    return KWLNTASK_STOP;
                }
            }
            break;
    }

    return KWLNTASK_CONTINUE;
}

// FUN_00188B20
void func_00188b20(KwlnTask* task)
{
    (*(void (**)(void*))jtbl_0096017C)(task->workData);
}

// FUN_00188B50
u32 func_00188b50(void)
{
    void* work;
    KwlnTask* created;

    work = (*(void* (**)(u32, u32, u32))D_00960184)(1, 0xc, 0x40000);
    if (work == NULL)
    {
        created = NULL;
    }
    else
    {
        created = kwlnTaskCreateWithAutoPriority(NULL,
                                                 0x106f,
                                                 D_005E4308,
                                                 func_00188900,
                                                 func_00188b20,
                                                 work);
        if (created == NULL)
        {
            created = NULL;
        }
    }
    uGpffffb314 = created;

    return 1;
}

// FUN_00188BE0
u32 func_00188be0(void)
{
    u32 state;

    state = kwlnTaskGetState(uGpffffb314);
    if (state == 3)
    {
        uGpffffb314 = NULL;
        return 1;
    }

    return 0;
}
