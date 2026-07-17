#include "Main/Game/gm_root.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"

static GmRootWork* sWork; // 007ce38c
static u32 sResult; // 007ce390


void gmRoot002663c0(void);
void gmRoot00266430(void);
u32 FUN_0016f380(u32 idx);
void FUN_0016f3e0(u32 idx, u32 value);
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
void FUN_00265dc0(void);
void FUN_00265e30(void);
void FUN_00265ef0(int param_1);

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
                    gmRoot002663c0();
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
                    value = FUN_0016f380(0x2f);
                    if (value != 0x7fffffff)
                    {
                        value++;
                    }
                    FUN_0016f3e0(0x2f, value);
                }
                if (!(work->flags & GMROOT_FLAG_UNK4))
                {
                    if (datGetFlag(0x1413) != 0)
                    {
                        gmRoot00266430();
                        return;
                    }
                    gmRoot002663c0();
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
u32 gmRoot00265c20(KwlnTask* task);

// FUN_002663c0
void gmRoot002663c0(void)
{
    GmRootWork* work;

    K_ASSERT(sWork != NULL, 90);
    work = sWork;
    kwlnInitGameData();
    work->unk_0c = gmRoot00265c20(work->task);
    work->flags |= GMROOT_FLAG_UNK2;
    work->unk_04 = 1;
}

// FUN_00266430
void gmRoot00266430(void)
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
extern u32 FUN_00191af0();
extern u32 FUN_00194b80();
extern u32 FUN_00194e10();
extern void FUN_00195550();
extern void FUN_001985b0();
extern void FUN_00266670();
extern void FUN_00269cc0();
extern void FUN_002673a0();
extern void FUN_0026dd10();
extern void FUN_0026a230();
extern void FUN_00271cd0();
extern void FUN_00272220();
extern void FUN_00272290();
extern void FUN_001085c0();
extern void FUN_00108670();
extern void FUN_001086a0();
extern void FUN_00266cb0();

// FUN_00265c20
u32 gmRoot00265c20(KwlnTask* parent)
{
    u32 task;
    u32* work;
    u32* root;
    u32 child;
    u8 color[4];

    work = (u32*)FUN_00191af0(0x4530);
    task = FUN_00194b80(parent, 10, "op",
                        FUN_00265dc0, FUN_00265ef0, work);
    child = FUN_00194e10("op draw", 0x106f, 1, 2,
                         FUN_00265e30, 0, 0);
    work[3] = child;
    FUN_00195550(task, child);
    work[0] = 0;
    work[2] = task;
    FUN_00266670(work + 8);
    FUN_00269cc0(work + 0x20);
    FUN_002673a0(work + 0x68);
    FUN_0026dd10(work + 0x47c);
    FUN_0026a230(work + 0x8dc);
    FUN_00271cd0(work + 0x1100);
    FUN_001985b0(0, 0, 0, 0xff);
    sWork = (GmRootWork*)work;
    K_ASSERT(work != NULL, 0x9a);
    root = (u32*)sWork;
    root[0x1148] = 0;
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    color[3] = 0xff;
    FUN_00272220(color);
    FUN_00272290();
    FUN_001085c0();
    FUN_00108670(5);
    FUN_001086a0(10);
    FUN_00266cb0();
    root[1] = 0;
    *root |= 1;
    return task;
}

// FUN_00266660
void gmRoot00266660(u32 result)
{
    sResult = result;
}
