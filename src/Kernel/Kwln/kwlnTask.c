#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwln.h"
#include "Kernel/h_malloc.h"
#include "Kosaka/k_assert.h"
#include "Main/g_data.h"
#include "h_pad.h"
#include "temporary.h"

#define KWLNTASK_MAXINLIST 10000

// Scheduler gates owned by the task-control helpers at 00195750-00195790.
static u32 sTaskPriorityGateB; // 007ce090
static u32 sTaskPriorityGateA; // 007ce08c

static KwlnTask* sTaskUpdating; // 007ce088. Current task updating

// for 'KWLNTASK_STATE_RUNNING' state
static s32 sNumTaskRunning;          // 007ce084
static KwlnTask* sRunningTaskTail;   // 007ce080
static KwlnTask* sRunningTaskHead;   // 007ce07c

// for 'KWLNTASK_STATE_DESTROY' state
static s32 sNumTaskDestroy;          // 007ce078
static KwlnTask* sDestroyTaskTail;   // 007ce074
static KwlnTask* sDestroyTaskHead;   // 007ce070

// for 'KWLNTASK_STATE_STAGED' state
static s32 sNumTaskStaged;           // 007ce06c
static KwlnTask* sStagedTaskTail;    // 007ce068
static KwlnTask* sStagedTaskHead;    // 007ce064

static char sPrintIndent[64]; // 00847e50

void kwlnTaskDestroy(KwlnTask* task);
void kwlnTaskDetachAllChildren(KwlnTask* task);
void kwlnTaskDestroyHierarchy(KwlnTask* task);

// FUN_001939d0. Remove a task from a list by its current state
void kwlnTaskRemoveFromList(KwlnTask* task)
{
    KwlnTask* next;
    KwlnTask* prev;
    u32 taskState;
    
    taskState = KWLNTASK_GET_STATE(task);
    if (taskState == KWLNTASK_STATE_NULL ||
       (taskState != KWLNTASK_STATE_DESTROY) &&
       (taskState != KWLNTASK_STATE_RUNNING) &&
       (taskState != KWLNTASK_STATE_STAGED))
    {
        K_ABORT("Process stat Invalid!!", 70);
        return;
    }

    if (task->prev != NULL)
    {
        task->prev->next = task->next;
    }
    else 
    {
        switch (taskState)
        {
            case KWLNTASK_STATE_STAGED:  sStagedTaskHead  = task->next; break;
            case KWLNTASK_STATE_RUNNING: sRunningTaskHead = task->next; break;
            case KWLNTASK_STATE_DESTROY: sDestroyTaskHead = task->next; break;
        }
    }

    if (task->next != NULL)
    {
        prev = task->prev;
        task->next->unk_48 = prev;
        
        next = task->next;
        next->prev = prev;
    }
    else
    {
        taskState = KWLNTASK_GET_STATE(task);
        switch (taskState)
        {
            case KWLNTASK_STATE_STAGED:  sStagedTaskTail  = task->prev; break;
            case KWLNTASK_STATE_RUNNING: sRunningTaskTail = task->prev; break;
            case KWLNTASK_STATE_DESTROY: sDestroyTaskTail = task->prev; break;
        }
    }

    task->next = NULL;
    task->prev = NULL;
    
    taskState = KWLNTASK_GET_STATE(task);
    switch (taskState)
    {
        case KWLNTASK_STATE_STAGED:  sNumTaskStaged--;  break;
        case KWLNTASK_STATE_RUNNING: sNumTaskRunning--; break;
        case KWLNTASK_STATE_DESTROY: sNumTaskDestroy--; break;
    }
}

// FUN_00193ba0. Add a task to the priority-sorted list for its current state
void kwlnTaskAddToList(KwlnTask* task)
{
    KwlnTask* list;
    u32 taskState = KWLNTASK_GET_STATE(task);

    switch (taskState)
    {
        case KWLNTASK_STATE_STAGED:  list = sStagedTaskHead;  break;
        case KWLNTASK_STATE_RUNNING: list = sRunningTaskHead; break;
        case KWLNTASK_STATE_DESTROY: list = sDestroyTaskHead; break;

        case KWLNTASK_STATE_NULL: // fallthrough
        default: K_ABORT("Process stat Invalid!!", 143); return;
    }

    if (list == NULL)
    {
        switch (taskState)
        {
            case KWLNTASK_STATE_STAGED:
                sStagedTaskHead = task;
                sStagedTaskTail = task;
                break;

            case KWLNTASK_STATE_RUNNING:
                sRunningTaskHead = task;
                sRunningTaskTail = task;
                break;

            case KWLNTASK_STATE_DESTROY:
                sDestroyTaskHead = task;
                sDestroyTaskTail = task;
                break;
        }

        task->unk_48 = NULL;
        task->prev = NULL;
        task->next = NULL;
    }
    else
    {
        while (list != NULL)
        {
            if (list->priority > task->priority)
            {
                if (list->prev != NULL)
                {
                    list->prev->next = task;
                    task->prev = task->unk_48 = list->prev;
                    task->next = list;
                    list->unk_48 = task;
                    list->prev = task;
                }
                else
                {
                    switch (taskState)
                    {
                        case KWLNTASK_STATE_STAGED:  sStagedTaskHead = task;  break;
                        case KWLNTASK_STATE_RUNNING: sRunningTaskHead = task; break;
                        case KWLNTASK_STATE_DESTROY: sDestroyTaskHead = task; break;
                    }

                    task->prev = NULL;
                    task->next = list;
                    list->unk_48 = task;
                    list->prev = task;
                }

                break;
            }

            list = list->next;
        }

        if (list == NULL)
        {
            taskState = KWLNTASK_GET_STATE(task); // again
            switch (taskState)
            {
                case KWLNTASK_STATE_STAGED: 
                    sStagedTaskTail->next = task;
                    task->prev = task->unk_48 = sStagedTaskTail;
                    sStagedTaskTail = task;
                    break;

                case KWLNTASK_STATE_RUNNING: 
                    sRunningTaskTail->next = task;
                    task->prev = task->unk_48 = sRunningTaskTail;
                    sRunningTaskTail = task;
                    break;

                case KWLNTASK_STATE_DESTROY: 
                    sDestroyTaskTail->next = task;
                    task->prev = task->unk_48 = sDestroyTaskTail;
                    sDestroyTaskTail = task;
                    break;
            }

            task->next = NULL;
        }
    }

    taskState = KWLNTASK_GET_STATE(task); // again
    switch (taskState)
    {
        case KWLNTASK_STATE_STAGED:
            sNumTaskStaged++;
            K_ASSERT(sNumTaskStaged <= KWLNTASK_MAXINLIST, 226);
            break;

        case KWLNTASK_STATE_RUNNING:
            sNumTaskRunning++;
            K_ASSERT(sNumTaskRunning <= KWLNTASK_MAXINLIST, 230);
            break;

        case KWLNTASK_STATE_DESTROY:
            sNumTaskDestroy++;
            K_ASSERT(sNumTaskDestroy <= KWLNTASK_MAXINLIST, 234);
            break;
    }
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00193ec0
u8 kwlnTaskUpdate(KwlnTask* task)
{
    s32 i;
    KwlnTaskUpdateFunc updateFunc;
    void* updateResult;

    if ((kwlnGetFlags() & 0xC0000000) != 0 &&
        task->priority >= 0x816 &&
        task->priority < 0x1CE6)
    {
        return true;
    }

    if (sTaskPriorityGateA != 0 &&
        task->priority >= 0x833 &&
        task->priority < 0x103E)
    {
        return true;
    }

    if (sTaskPriorityGateB != 0 &&
        task->priority >= 0x1064 &&
        task->priority < 0x1CDA)
    {
        return true;
    }

    if ((task->stateAndFlags & KWLNTASK_FLAG_SUSPENDED) != 0)
    {
        return true;
    }

        sTaskUpdating = task;

        if (task->stateAndFlags & KWLNTASK_FLAG_DISABLE_PAD)
        {
            memset(gPads, 0, HPAD_PORT_MAX * sizeof(HPad));

            for (i = 0; i < HPAD_PORT_MAX; i++)
            {
                gPads[i].virtualPreviousPressed = gPads[i].btn[1].released = gPads[i].btn[1].justPressed = 0x80;
                *((u8*)&gPads[i].rstickY) = *((u8*)&gPads[i].rstickX) =
                    *((u8*)&gPads[i].lstickY) = *((u8*)&gPads[i].lstickX) = 0x80;
            }
        }
        else
        {
            memcpy(gPads, gWorkPads, HPAD_PORT_MAX * sizeof(HPad));
        }

        updateFunc = task->update;
        if (updateFunc != NULL && updateFunc != (KwlnTaskUpdateFunc)0xFFFFFFFF)
        {
            updateResult = updateFunc(task);
            if (updateResult != KWLNTASK_CONTINUE)
            {
                task->update = updateResult;
            }

            if (updateResult == KWLNTASK_STOP &&
                KWLNTASK_GET_STATE(task) == KWLNTASK_STATE_RUNNING)
            {
                kwlnTaskDestroy(task);
                kwlnTaskDestroyHierarchy(task->child);
                sTaskUpdating = NULL;

                return false;
            }

            if (task->stateAndFlags == KWLNTASK_STATE_DESTROY)
            {
                sTaskUpdating = NULL;

                return false;
            }
        }

        task->timer++;
        sTaskUpdating = NULL;

    return true;
}
#pragma pop

// FUN_00194100 NONMATCHING
void kwlnTaskUpdateAll()
{
    KwlnTask* currTask;
    KwlnTask* prevTask;
    KwlnTask* cursor;

    if (sRunningTaskHead != NULL)
    {
        currTask = sRunningTaskHead;
        while (currTask != NULL)
        {
            prevTask = currTask->prev;

            if (kwlnTaskUpdate(currTask))
            {
                currTask = currTask->next;
            }
            else
            {
                currTask = sRunningTaskHead;

                if (prevTask != NULL)
                {
                    cursor = prevTask;
                    while ((u32)(cursor != NULL) != 0 &&
                           (KWLNTASK_GET_STATE(cursor) == KWLNTASK_STATE_DESTROY))
                    {
                        prevTask = cursor->prev;
                        if (prevTask != NULL)
                        {
                            cursor = prevTask;
                        }
                        else
                        {
                            cursor = cursor->unk_48;
                            break;
                        }
                    }

                    if (cursor != NULL)
                    {
                        currTask = cursor->next;
                    }
                    else
                    {
                        currTask = sRunningTaskHead;
                    }
                }
            }
        }
    }
}

// FUN_001941f0. Destroy every task in the hierarchy
void kwlnTaskDestroyHierarchy(KwlnTask* task)
{
    KwlnTask* currTask;
    KwlnTask* currChild;
    
    if (task != NULL)
    {
        currTask = task;
        while (currTask != NULL)
        {
            currChild = currTask->child;
            if (currChild != NULL)
            {
                while (currChild != NULL)
                {
                    kwlnTaskDestroyHierarchy(currChild->child);
                    kwlnTaskDestroy(currChild);

                    currChild = currChild->sibling;
                }
            }

            kwlnTaskDestroy(currTask);
            currTask = currTask->sibling;
        }
    }
}

// FUN_00194280. Change a task state to 'KWLNTASK_STATE_DESTROY'. If 'destroyTask' is 0, destroy the task immediately
void kwlnTaskDestroy(KwlnTask* task)
{
    u32 state;

    state = KWLNTASK_GET_STATE(task);

    switch (state)
    {
        case KWLNTASK_STATE_STAGED:
        case KWLNTASK_STATE_RUNNING:
            goto destroyTask;

        case KWLNTASK_STATE_DESTROY: return;
        case KWLNTASK_STATE_NULL:
        default:
            printf("Process stat Invalid!!\n");
            K_ASSERT(false, 574);
            break;
    }
    return;

destroyTask:
    kwlnTaskRemoveFromList(task);
    KWLNTASK_SET_STATE(task, KWLNTASK_STATE_DESTROY);
    kwlnTaskAddToList(task);

    if (task->destroyDelay == 0)
    {
        kwlnTaskRemoveFromList(task);
        if (task->destroy != NULL)
        {
            task->destroy(task);
        }

        KWLNTASK_RESET_STATE(task);

        kwlnTaskDetachParent(task);
        kwlnTaskDetachAllChildren(task);
        H_Free(task);
    }
}
#pragma optimization_level 1
// FUN_001943B0. Set task flags recursively through the child hierarchy.
void kwlnTaskSetFlagsRecursive(u32 enabled, KwlnTask* task, u32 flags)
{
    KwlnTask* child;
    KwlnTask* grandchild;
    u32 maskedFlags;
    u32 clearFlags;

    if (enabled != 0)
    {
        task->stateAndFlags |= flags & 0x0ffffff0;
    }
    else
    {
        task->stateAndFlags &= ~(flags & 0x0ffffff0);
    }

    child = task->child;
    maskedFlags = flags & 0x0ffffff0;
    clearFlags = ~maskedFlags;
    while (child != NULL)
    {
        if (enabled != 0)
        {
            child->stateAndFlags |= maskedFlags;
        }
        else
        {
            child->stateAndFlags &= clearFlags;
        }

        grandchild = child->child;
        while (grandchild != NULL)
        {
            kwlnTaskSetFlagsRecursive(enabled, grandchild, flags);
            grandchild = grandchild->sibling;
        }

        child = child->sibling;
    }
}
#pragma optimization_level 2

#pragma push
#pragma opt_loop_invariants on
// FUN_001944C0. Set task flags for one task, its hierarchy, or the task lists.
void kwlnTaskSetFlags(u32 enabled, KwlnTask* task, u32 flags, u32 scope)
{
    s32 listIndex;
    KwlnTask* currentTask;
    u32 maskedFlags;
    u32 clearFlags;
    currentTask = NULL;
    switch (scope)
    {
        case 0:
            goto scopeZero;
        case 1:
            goto scopeOne;
        case 3:
            goto scopeLists;
        case 2:
            goto scopeTwo;
        default:
            goto scopeDefault;
    }

scopeZero:
    if (task == NULL)
    {
        K_ASSERT(false, 669);
    }

    if (enabled != 0)
    {
        task->stateAndFlags |= flags & 0x0ffffff0;
        return;
    }

    task->stateAndFlags &= ~(flags & 0x0ffffff0);
    return;

scopeOne:
    if (task == NULL)
    {
        K_ASSERT(false, 677);
    }

scopeLists:
    listIndex = 0;
    maskedFlags = flags & 0x0ffffff0;
    clearFlags = ~maskedFlags;
    for (; listIndex < 3; listIndex++)
    {
        switch (listIndex)
        {
            case 0:
                currentTask = sStagedTaskHead;
                break;

            case 1:
                currentTask = sRunningTaskHead;
                break;

            case 2:
                currentTask = sDestroyTaskHead;
                break;
        }

        while (currentTask != NULL)
        {
            if ((currentTask != task && scope == 1) || scope == 3)
            {
                if (enabled != 0)
                {
                    currentTask->stateAndFlags |= maskedFlags;
                }
                else
                {
                    currentTask->stateAndFlags &= clearFlags;
                }
            }
            currentTask = currentTask->next;
        }
    }
    return;

scopeTwo:
    if (task == NULL)
    {
        K_ASSERT(false, 703);
    }

    if (enabled != 0)
    {
        task->stateAndFlags |= flags & 0x0ffffff0;
    }
    else
    {
        task->stateAndFlags &= ~(flags & 0x0ffffff0);
    }

    currentTask = task->child;
    while (currentTask != NULL)
    {
        kwlnTaskSetFlagsRecursive(enabled, currentTask, flags);
        currentTask = currentTask->sibling;
    }
    return;

scopeDefault:
    K_ASSERT(false, 708);
    return;
}
#pragma pop

// FUN_00194750
void kwlnTaskPrintRecursive(const KwlnTask* task, s32 indentDepth)
{
    printf("%s+-%s [%d]", sPrintIndent, task->name, task->priority);

    if (task->stateAndFlags & KWLNTASK_FLAG_SUSPENDED)
    {
        printf(" <S>");
    }

    if (task->stateAndFlags & KWLNTASK_FLAG_DISABLE_PAD)
    {
        printf(" <!P>");
    }

    printf("\n");

    if (task->child != NULL)
    {
        if (task->parent == NULL)
        {
            sPrintIndent[0] = ' ';
        }
        else if (task->sibling == NULL)
        {
            sPrintIndent[indentDepth * 4] = ' ';
        }
        else
        {
            sPrintIndent[indentDepth * 4] = '|';
        }

        sPrintIndent[(indentDepth * 4) + 4] = '\0';

        kwlnTaskPrintRecursive(task->child, indentDepth + 1);

        sPrintIndent[indentDepth * 4] = '\0';
    }

    if (task->sibling != NULL)
    {
        kwlnTaskPrintRecursive(task->sibling, indentDepth);
    }
}

// FUN_001948b0
#pragma optimization_level 1
void kwlnTaskPrintTrees()
{
    s32 i;
    u32 space;
    KwlnTask* currTask;
    KwlnTask* currTask_c;
    char* indent;

    printf("<<< process tree >>>\n");
    i = 0;
    space = ' ';
    indent = sPrintIndent;
    for (; i < 64; i++)
    {
        indent[i] = (char)space;
    }
    currTask = sStagedTaskHead;
    while (currTask != NULL)
    {
        if (currTask->parent == NULL)
        {
            sPrintIndent[0] = '\0';

            kwlnTaskPrintRecursive(currTask, 0);
        }

        currTask = currTask->next;
    }

    currTask = sRunningTaskHead;
    while (NULL != currTask)
    {
        if (currTask->parent == NULL)
        {
            sPrintIndent[0] = '\0';

            kwlnTaskPrintRecursive(currTask, 0);
        }

        currTask = currTask->next;
    }

    currTask = sDestroyTaskHead;
    while (currTask != NULL)
    {
        if (currTask->parent == NULL)
        {
            sPrintIndent[0] = '\0';

            kwlnTaskPrintRecursive(currTask, 0);
        }

        currTask = (currTask_c = currTask)->next;
    }

    printf("\n\n");
}
#pragma optimization_level 2

// FUN_001949e0. Called every frame in the game main loop
u32 kwlnTaskMain()
{
    KwlnTask* nextTask;
    KwlnTask* currTask;

    nextTask = sStagedTaskHead;
    while (nextTask != NULL)
    {
        if (nextTask->runningDelay > 0)
        {
            nextTask->runningDelay--;
        }

        currTask = nextTask;
        nextTask = nextTask->next;
        if (currTask->runningDelay == 0)
        {
            kwlnTaskRemoveFromList(currTask);
            KWLNTASK_SET_STATE(currTask, KWLNTASK_STATE_RUNNING);
            kwlnTaskAddToList(currTask);

            currTask->unk_24 = 0;
            currTask->timer = 0;
        }
    }

    kwlnTaskUpdateAll();

    nextTask = sDestroyTaskHead;
    while (nextTask != NULL)
    {
        if (nextTask->destroyDelay > 0)
        {
            nextTask->destroyDelay--;
        }

        currTask = nextTask;
        nextTask = nextTask->next;
        if (currTask->destroyDelay == 0)
        {
            kwlnTaskRemoveFromList(currTask);
            
            if (currTask->destroy != NULL)
            {
                currTask->destroy(currTask);
            }

            KWLNTASK_RESET_STATE(currTask);
            kwlnTaskDetachParent(currTask);
            kwlnTaskDetachAllChildren(currTask);

            H_Free(currTask);
        }
    }

    return true;
}

// FUN_00194b20. Create a new task. 'parentTask' can be NULL
KwlnTask* kwlnTaskCreate(KwlnTask* parentTask,
                          const char* name,
                          u32 priority,
                          KwlnTaskUpdateFunc update,
                          KwlnTaskDestroyFunc destroy,
                          void* workData)
{
    KwlnTask* task = kwlnTaskInit(name, priority, update, destroy, workData);
    kwlnTaskAddChild(parentTask, task);

    return task;
}

// FUN_00194b80 NONMATCHING. Create a new task and adjust priority by the parent hierarchy. 'parentTask' can be NULL
KwlnTask* kwlnTaskCreateWithAutoPriority(KwlnTask* parentTask,
                                         u32 priority,
                                         const char* name,
                                         KwlnTaskUpdateFunc update,
                                         KwlnTaskDestroyFunc destroy,
                                         void* workData)
{
    u32 maxPriority;
    KwlnTask* currParent;
    u32 currPriority;
    KwlnTask* task;

    currParent = parentTask;
    if (currParent == NULL)
    {
        goto noParent;
    }

    maxPriority = 0;
    goto parentCheck;

parentBody:
    currPriority = currParent->priority;
    if (currPriority >= priority &&
        currPriority < priority + 1024 &&
        currPriority > maxPriority)
    {
        maxPriority = currPriority;
    }

    currParent = currParent->parent;

parentCheck:
    if (currParent != NULL)
    {
        goto parentBody;
    }

    if (maxPriority != 0)
    {
        priority = maxPriority + 1;
    }

noParent:

    task = kwlnTaskInit(name, priority, update, destroy, workData);
    kwlnTaskAddChild(parentTask, task);

    return task;
}

// FUN_00194c50. Init a new task. See 'kwlnTaskInitEx' for adjustable 'runningDelay' and 'destroyDelay'
KwlnTask* kwlnTaskInit(const char* name,
                       u32 priority,
                       KwlnTaskUpdateFunc update,
                       KwlnTaskDestroyFunc destroy,
                       void* workData)
{
    KwlnTask* task;
    char currChar;
    s32 i;

    K_ASSERT(name[0] != '\0', 1022);

    task = (KwlnTask*)H_Malloc(sizeof(KwlnTask));
    K_ASSERT(task != NULL, 1032);

    if (task == NULL)
    {
        return NULL;
    }
    
    task->nameHash = 0;
    i = 0;
    while ((task->name[i] = name[i]) != '\0' && i < 24)
    {
        task->nameHash += name[i];
        i++;
    }

    task->name[23] = '\0';
    task->stateAndFlags = KWLNTASK_STATE_NULL;
    task->stateAndFlags |= KWLNTASK_STATE_STAGED;
    task->priority = priority;
    task->unk_24 = 0;
    task->timer = 0;
    task->runningDelay = 0;
    task->destroyDelay = 2;
    task->update = update;
    task->destroy = destroy;
    task->workData = workData;
    task->next = NULL;
    task->prev = NULL;
    task->unk_48 = NULL;
    task->parent = NULL;
    task->child = NULL;
    task->sibling = NULL;
    task->unk_58 = 0;
    task->unk_5c = 0;
    task->unk_60 = 0;
    task->unk_64 = 0;
    
    kwlnTaskAddToList(task);

    if (task->runningDelay == 0)
    {
        kwlnTaskRemoveFromList(task);
        KWLNTASK_SET_STATE(task, KWLNTASK_STATE_RUNNING);
        kwlnTaskAddToList(task);

        task->unk_24 = 0;
        task->timer = 0;
    }

    return task;
}

// FUN_00194e10. Init a new task with adjustable 'runningDelay' and 'destroyDelay'
KwlnTask* kwlnTaskInitEx(const char* name,
                         u32 priority,
                         s32 runningDelay,
                         s32 destroyDelay,
                         KwlnTaskUpdateFunc update,
                         KwlnTaskDestroyFunc destroy,
                         void* workData)
{
    KwlnTask* task;
    char currChar;
    s32 i;

    K_ASSERT(name[0] != '\0', 1101);

    task = (KwlnTask*)H_Malloc(sizeof(KwlnTask));
    K_ASSERT(task != NULL, 1109);

    if (task == NULL)
    {
        return NULL;
    }

    task->nameHash = 0;
    i = 0;
    while ((task->name[i] = name[i]) != '\0' && i < 24)
    {
        task->nameHash += name[i];
        i++;
    }

    task->name[23] = '\0';
    task->stateAndFlags = KWLNTASK_STATE_NULL;
    task->stateAndFlags |= KWLNTASK_STATE_STAGED;
    task->priority = priority;
    task->unk_24 = 0;
    task->timer = 0;
    task->runningDelay = runningDelay;
    task->destroyDelay = destroyDelay;
    task->update = update;
    task->destroy = destroy;
    task->workData = workData;
    task->next = NULL;
    task->prev = NULL;
    task->unk_48 = NULL;
    task->parent = NULL;
    task->child = NULL;
    task->sibling = NULL;
    task->unk_58 = 0;
    task->unk_5c = 0;
    task->unk_60 = 0;
    task->unk_64 = 0;
    
    kwlnTaskAddToList(task);

    if (task->runningDelay == 0)
    {
        kwlnTaskRemoveFromList(task);
        KWLNTASK_SET_STATE(task, KWLNTASK_STATE_RUNNING);
        kwlnTaskAddToList(task);

        task->unk_24 = 0;
        task->timer = 0;
    }

    return task;
}

// FUN_00194fe0
u8 kwlnTaskDestroyWithHierarchyByName(const char* name)
{
    KwlnTask* task;

    task = kwlnTaskGetTaskByName(name);
    if (task == NULL)
    {
        return false;
    }

    return kwlnTaskDestroyWithHierarchy(task);
}

// FUN_00195020. Destroy a task and its hierarchy
u8 kwlnTaskDestroyWithHierarchy(KwlnTask* task)
{
    u32 state;

    if (task == NULL || task == (KwlnTask*)0xFFFFFFFF)
    {
        K_ABORT("ProcessID invalid!!\n", 1181);
        return false;
    }

    state = KWLNTASK_GET_STATE(task);
    switch (state)
    {
        case KWLNTASK_STATE_STAGED:  // fallthrough
        case KWLNTASK_STATE_RUNNING: 
            task->destroyDelay = 2;

            state = KWLNTASK_GET_STATE(task);
            switch (state)
            {
                case KWLNTASK_STATE_STAGED:  // fallthrough
                case KWLNTASK_STATE_RUNNING:
                    goto destroyCurrent;
                case KWLNTASK_STATE_DESTROY:
                    goto processChildren;

                case KWLNTASK_STATE_NULL:    // fallthrough
                default:
                    printf("Process stat Invalid!!\n");
                    K_ASSERT(false, 574);
                    goto processChildren;
            }

destroyCurrent:
            kwlnTaskRemoveFromList(task);
            KWLNTASK_SET_STATE(task, KWLNTASK_STATE_DESTROY);
            kwlnTaskAddToList(task);

            if (task->destroyDelay == 0)
            {
                kwlnTaskRemoveFromList(task);
                if (task->destroy != NULL)
                {
                    task->destroy(task);
                }

                KWLNTASK_RESET_STATE(task);

                kwlnTaskDetachParent(task);
                kwlnTaskDetachAllChildren(task);
                H_Free(task);
            }

processChildren:

            task = task->child;
            if (task != NULL)
            {
                while (task != NULL)
                {
                    kwlnTaskDestroyHierarchy(task->child);
                    kwlnTaskDestroy(task);

                    task = task->sibling;
                }
            }
            break;

        case KWLNTASK_STATE_DESTROY:
            task->destroyDelay = 2;
            if (task->destroyDelay == 0)
            {
                kwlnTaskRemoveFromList(task);
                if (task->destroy != NULL)
                {
                    task->destroy(task);
                }

                KWLNTASK_RESET_STATE(task);

                kwlnTaskDetachParent(task);
                kwlnTaskDetachAllChildren(task);
                H_Free(task);
            }
            break;

        case KWLNTASK_STATE_NULL: // fallthrough
        default:
            K_ABORT("ProcessID invalid!!\n", 1204);
            return false;
    }

    return true;
}

// FUN_00195290
u32 kwlnTaskGetState(KwlnTask* task)
{
    u32 state;

    if (!kwlnTaskExists(task))
    {
        return KWLNTASK_STATE_NULL;
    }

    state = KWLNTASK_GET_STATE(task);
    switch (state)
    {
        case KWLNTASK_STATE_STAGED:  // fallthrough
        case KWLNTASK_STATE_RUNNING: // fallthrough
        case KWLNTASK_STATE_DESTROY: // fallthrough
        case KWLNTASK_STATE_NULL:    return state;
    }

    printf("Process stat Invalid!!\n");
    K_ASSERT(false, 1286);
    return KWLNTASK_STATE_NULL;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00195340 NONMATCHING
KwlnTask* kwlnTaskGetTaskByName(const char* name)
{
    KwlnTask* list;
    s32 i;
    s32 nameHash;
    KwlnTask* stagedList;
    KwlnTask* runningList;
    KwlnTask* destroyList;
    s32 j;
    s32 k;
    
    list = NULL;
    nameHash = 0;
    for (i = 0; name[i] != '\0'; i++)
    {
        nameHash += name[i];
    }
    j = 0;
    stagedList = sStagedTaskHead;
    runningList = sRunningTaskHead;
    destroyList = sDestroyTaskHead;

    for (; j < 3; j++)
    {
        switch (j)
        {
            case 0: list = stagedList;  break;
            case 1: list = runningList; break;
            case 2: list = destroyList; break;
        }

        while (list != NULL)
        {
            if (list->nameHash == nameHash)
            {
                k = i;

                while (name[k] == list->name[k])
                {
                    if (k == 0)
                    {
                        break;
                    }
                    k--;
                }

                if (k == 0)
                {
                    return list;
                }
            }

            list = list->next;
        }
    }

    return NULL;
}
#pragma pop

// FUN_00195450. Get the current task updating
KwlnTask* kwlnTaskGetUpdating()
{
    return sTaskUpdating;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00195460. Return true if 'task' is in a list
u32 kwlnTaskExists(KwlnTask* task)
{
    s32 i;
    KwlnTask* currTask;
    KwlnTask* stagedList;
    KwlnTask* runningList;
    KwlnTask* destroyList;

    currTask = NULL;
    if (task == NULL)
    {
        return false;
    }
    i = 0;

    stagedList = sStagedTaskHead;
    runningList = sRunningTaskHead;
    destroyList = sDestroyTaskHead;
    for (; i < 3; i++)
    {
        switch (i)
        {
            case 0: currTask = stagedList;  break;
            case 1: currTask = runningList; break;
            case 2: currTask = destroyList; break;
        }

        while (currTask != NULL)
        {
            if (currTask == task)
            {
                return true;
            }

            currTask = currTask->next;
        }
    }

    return false;
}
#pragma pop

// FUN_00195520
u32 kwlnTaskGetTimer(KwlnTask* task)
{
    return task->timer;
}

// FUN_00195530
void kwlnTaskSetWorkData(KwlnTask* task, void* workData)
{
    task->workData = workData;
}

// FUN_00195540
void* kwlnTaskGetWorkData(KwlnTask* task)
{
    return task->workData;
}

// FUN_00195550
void kwlnTaskAddChild(KwlnTask* parentTask, KwlnTask* childTask)
{
    KwlnTask* lastChild;

    if (parentTask != NULL)
    {
        if (childTask->parent != NULL)
        {
            kwlnTaskDetachParent(childTask);
        }

        lastChild = parentTask->child;
        if (parentTask->child != NULL)
        {
            while (lastChild->sibling != NULL)
            {
                lastChild = lastChild->sibling;
            }

            lastChild->sibling = childTask;
            
        }
        else
        {
            parentTask->child = childTask;
        }

        childTask->parent = parentTask;
    }
}

// FUN_001955f0
void kwlnTaskDetachParent(KwlnTask* childTask)
{
    KwlnTask* parentTask;
    KwlnTask* currSibling;
    KwlnTask** childPtr;

    parentTask = childTask->parent;
    if (parentTask == NULL)
    {
        K_ASSERT(childTask->sibling == NULL, 1519);
        return;
    }

    childPtr = &parentTask->child;
    if (*childPtr == childTask)
    {
        *childPtr = childTask->sibling;
    }
    else
    {
        currSibling = *childPtr;
        while (currSibling->sibling != childTask)
        {
            currSibling = currSibling->sibling;
        }

        currSibling->sibling = childTask->sibling;
    }

    childTask->parent = NULL;
    childTask->sibling = NULL;
}

// FUN_00195690
void kwlnTaskDetachAllChildren(KwlnTask* parentTask)
{
    KwlnTask* next;
    KwlnTask* currTask;

    next = parentTask->child;
    while (next != NULL)
    {
        if (next->parent == parentTask)
        {
            currTask = next;
        }

        next = next->sibling;
        currTask->parent = NULL;
        currTask->sibling = NULL;
    }
}
// FUN_001956D0
void kwlnTaskEnableFlags(KwlnTask* task, u32 flags, u32 scope)
{
    kwlnTaskSetFlags(1, task, flags, scope);
}

// FUN_00195710
void kwlnTaskDisableFlags(KwlnTask* task, u32 flags, u32 scope)
{
    kwlnTaskSetFlags(0, task, flags, scope);
}

// FUN_00195750
u32 kwlnTaskIsPriorityGateAOpen()
{
    return sTaskPriorityGateA != 1;
}

// FUN_00195770
void kwlnTaskSetPriorityGateB(u32 enabled)
{
    sTaskPriorityGateB = enabled != 1;
}

// FUN_00195790
u32 kwlnTaskIsPriorityGateBOpen()
{
    return sTaskPriorityGateB != 1;
}

// FUN_001957B0. Move a task immediately after another running task.
void kwlnTaskMoveAfter(KwlnTask* sourceTask, KwlnTask* task)
{
    KwlnTask* current;
    KwlnTask* current2;

    task->priority = sourceTask->priority;

    current = sRunningTaskHead;
    while (current != NULL)
    {
        if (current == task)
        {
            if (current->prev != NULL)
            {
                if (current->next != NULL)
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                else
                {
                    current->prev->next = NULL;
                }
            }
            else if (current->next != NULL)
            {
                current->next->prev = NULL;
            }
            break;
        }

        current = current->next;
    }

    current2 = sRunningTaskHead;
    while (current2 != NULL)
    {
        if (current2 == sourceTask)
        {
            if (current2->next != NULL)
            {
                task->prev = current2;
                task->next = current2->next;
                current2->next->prev = task;
                current2->next = task;
            }
            else
            {
                task->prev = current2;
                task->next = NULL;
                current2->next = task;
            }
            break;
        }

        current2 = current2->next;
    }
}
// FUN_001958A0. Move a task immediately before another running task.
void kwlnTaskMoveBefore(KwlnTask* sourceTask, KwlnTask* task)
{
    KwlnTask* current;
    KwlnTask* current2;

    task->priority = sourceTask->priority;

    current = sRunningTaskHead;
    while (current != NULL)
    {
        if (current == task)
        {
            if (current->prev != NULL)
            {
                if (current->next != NULL)
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                else
                {
                    current->prev->next = NULL;
                }
            }
            else if (current->next != NULL)
            {
                current->next->prev = NULL;
            }
            break;
        }

        current = current->next;
    }

    current2 = sRunningTaskHead;
    while (current2 != NULL)
    {
        if (current2 == sourceTask)
        {
            if (current2->prev != NULL)
            {
                task->prev = current2->prev;
                task->next = current2;
                current2->prev->next = task;
                current2->prev = task;
            }
            else
            {
                task->prev = NULL;
                task->next = current2;
                current2->prev = task;
            }
            break;
        }

        current2 = current2->next;
    }
}


typedef struct KwlnTaskCameraView
{
    RwV2d offset;
    s32 width;
    s32 height;
} KwlnTaskCameraView;
extern KwlnTaskCameraView sTaskCameraFallbackView; // 00847ea0

extern u32 D_00847E98[];
extern u32 D_00847E9C[];
extern u32 D_00847E90[];
extern u32 D_00847E94[];
extern u32 D_00847EA8[];
extern u32 D_00847EAC[];
extern u32 D_00847EA0[];
extern u32 D_00847EA4[];
#define TASK_CAMERA_VIEW_WIDTH D_00847E98[0]
#define TASK_CAMERA_VIEW_HEIGHT D_00847E9C[0]
#define TASK_CAMERA_VIEW_CACHE_OFFSET_X D_00847E94[0]
#define TASK_CAMERA_VIEW_CACHE_OFFSET_Y D_00847E90[0]
#define TASK_CAMERA_VIEW_FALLBACK_WIDTH D_00847EA8[0]
#define TASK_CAMERA_VIEW_FALLBACK_HEIGHT D_00847EAC[0]
#define TASK_CAMERA_VIEW_FALLBACK_OFFSET_X D_00847EA0[0]
#define TASK_CAMERA_VIEW_FALLBACK_OFFSET_Y D_00847EA4[0]

extern const void* func_004ca5b0(void);
extern void func_004ca560(u32* output, const void* descriptor);
extern RwCamera* func_004ca090(void);
extern RwCamera* func_004ca030(RwCamera* camera);
extern RwFrame* func_004caf10(void);
extern RwFrame* func_004caf80(RwFrame* frame);
extern RwCamera* func_004d1840(RwCamera* camera, RwFrame* frame);
extern RwRaster* func_004cde90(RwRaster* raster);

// FUN_00195980. Replace a camera's rasters and update its view window.
void func_00195980(RwCamera* camera,
                   KwlnTaskCameraView* requestedView,
                   f32 scale,
                   f32 aspectRatio)
{
    u32 displayInfo[4];
    KwlnTaskCameraView* view;
    RwRaster* newFrameBuffer;
    RwRaster* newZBuffer;
    f32 viewWindow[2];

    if (camera == NULL)
    {
        return;
    }

    if (TASK_CAMERA_VIEW_WIDTH == 0 || TASK_CAMERA_VIEW_HEIGHT == 0)
    {
        TASK_CAMERA_VIEW_CACHE_OFFSET_X = 0;
        TASK_CAMERA_VIEW_CACHE_OFFSET_Y = 0;
        TASK_CAMERA_VIEW_WIDTH = camera->frameBuffer->width;
        TASK_CAMERA_VIEW_HEIGHT = camera->frameBuffer->height;
    }

    func_004ca560(displayInfo, func_004ca5b0());

    if (requestedView == NULL)
    {
        view = &sTaskCameraFallbackView;
        TASK_CAMERA_VIEW_FALLBACK_WIDTH = camera->frameBuffer->width;
        TASK_CAMERA_VIEW_FALLBACK_HEIGHT = camera->frameBuffer->height;
        TASK_CAMERA_VIEW_FALLBACK_OFFSET_Y = 0;
        TASK_CAMERA_VIEW_FALLBACK_OFFSET_X = 0;
    }
    else
    {
        view = requestedView;
    }

    if ((displayInfo[3] & 1) != 0)
    {
        view->offset.y = 0;
        view->offset.x = 0;
        view->width = displayInfo[0];
        view->height = displayInfo[1];
    }

    if (view->width <= 0)
    {
        return;
    }
    if (view->height <= 0)
    {
        return;
    }

    if (camera->frameBuffer != NULL)
    {
        func_004cde90(camera->frameBuffer);
    }

    if (camera->zBuffer != NULL)
    {
        func_004cde90(camera->zBuffer);
    }

    newFrameBuffer = RwRasterCreate(view->width, view->height, 0, rwRASTERTYPECAMERA);
    newZBuffer = RwRasterCreate(view->width, view->height, 0, rwRASTERTYPEZBUFFER);
    if (newFrameBuffer == NULL)
    {
        goto allocation_failed;
    }
    if (newZBuffer == NULL)
    {
        goto allocation_failed;
    }

    camera->frameBuffer = newFrameBuffer;
    camera->zBuffer = newZBuffer;
    goto update_view_window;

allocation_failed:
    if (newFrameBuffer != NULL)
    {
        func_004cde90(newFrameBuffer);
    }
    if (newZBuffer != NULL)
    {
        func_004cde90(newZBuffer);
    }

    view->width = TASK_CAMERA_VIEW_WIDTH;
    view->height = TASK_CAMERA_VIEW_HEIGHT;
    newFrameBuffer = RwRasterCreate(view->width, view->height, 0, rwRASTERTYPECAMERA);
    newZBuffer = RwRasterCreate(view->width, view->height, 0, rwRASTERTYPEZBUFFER);
    camera->frameBuffer = newFrameBuffer;
    camera->zBuffer = newZBuffer;
    return;

update_view_window:

    if ((displayInfo[3] & 1) != 0)
    {
        viewWindow[0] = scale * aspectRatio;
        viewWindow[1] = scale;
    }
    else
    {
        view->width = camera->frameBuffer->width;
        view->height = camera->frameBuffer->height;

        if (view->height < view->width)
        {
            viewWindow[0] = scale;
            viewWindow[1] = ((f32)view->height * scale) / (f32)view->width;
        }
        else
        {
            viewWindow[0] = ((f32)view->width * scale) / (f32)view->height;
            viewWindow[1] = scale;
        }
    }

    RwCameraSetViewWindow(camera, (RwV2d*)viewWindow);
}

// FUN_00195C80. Create a camera with frame and optional z-buffer rasters.
RwCamera* func_00195c80(u32 width, u32 height, u32 createZBuffer)
{
    RwCamera* camera;
    RwFrame* frame;

    camera = func_004ca090();
    if (camera != NULL)
    {
        func_004d1840(camera, func_004caf10());

        camera->frameBuffer = RwRasterCreate(width, height, 0, rwRASTERTYPECAMERA);
        if (createZBuffer != 0)
        {
            camera->zBuffer = RwRasterCreate(width, height, 0, rwRASTERTYPEZBUFFER);
        }

        if (camera->object.object.parent != NULL &&
            camera->frameBuffer != NULL &&
            (createZBuffer == 0 || camera->zBuffer != NULL))
        {
            return camera;
        }
    }

    if (camera != NULL)
    {
        frame = (RwFrame*)camera->object.object.parent;
        if (frame != NULL)
        {
            func_004d1840(camera, NULL);
            func_004caf80(frame);
        }

        if (camera->frameBuffer != NULL)
        {
            func_004cde90(camera->frameBuffer);
            camera->frameBuffer = NULL;
        }
        if (camera->zBuffer != NULL)
        {
            func_004cde90(camera->zBuffer);
            camera->zBuffer = NULL;
        }
        func_004ca030(camera);
    }

    return NULL;
}
