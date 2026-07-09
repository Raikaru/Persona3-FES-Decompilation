#include "Main/Game/gm_root.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"

static GmRootWork* sWork; // 007ce38c

KwlnTask* FUN_00188860(KwlnTask* parent); // temporary here

void* gmRootUpdateTask(KwlnTask* gmRootTask);
void gmRootDestroyTask(KwlnTask* gmRootTask);

// FUN_00266140
void gmRootUpdate()
{
    // TODO
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
    work->chkMemcardTask = FUN_00188860(work->task);
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

void FUN_00195de0(void);
u32 FUN_00265c20(KwlnTask* task);
long FUN_00188660(void);
void FUN_00188680(void);
u32 FUN_0017fb90(void);

// FUN_002663c0
void gmRoot002663c0(void)
{
    GmRootWork* work;

    K_ASSERT(sWork != NULL, 90);
    work = sWork;
    FUN_00195de0();
    work->unk_0c = FUN_00265c20(work->task);
    work->flags |= GMROOT_FLAG_UNK2;
    work->unk_04 = 1;
}

// FUN_00266430
void gmRoot00266430(void)
{
    GmRootWork* work;

    K_ASSERT(sWork != NULL, 90);
    work = sWork;
    K_ASSERT(FUN_00188660(), 0xfd);
    FUN_00188680();
    work->unk_10 = FUN_0017fb90();
    work->flags |= GMROOT_FLAG_UNK4;
    work->unk_04 = 2;
}