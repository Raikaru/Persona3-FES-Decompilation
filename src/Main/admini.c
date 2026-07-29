#include "Main/admini.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rwplcore.h"
#include "Kosaka/k_assert.h"
#include "Kosaka/k_sequence.h"
#include "Battle/battle.h"
#pragma alias adminiSeqCallFacility FUN_0027CB10
#pragma alias adminiSeqExitFacility FUN_0027CB40
#pragma alias adminiSeqCheckFacility FUN_0027CB50


typedef struct
{
    void (*adminiCallFunc)(u8 isRestored, void* seqData);
    s32 (*adminiExitFunc)();
    u8 (*adminiCheckFunc)();
} AdminiSeqEntry;

void adminiSeqCallTest(u8 isRestored, void* seqData);
s32 adminiSeqExitTest();
u8 adminiSeqCheckTest();
void adminiSeqCallBtl(u8 isRestored, void* seqData);
s32 adminiSeqExitBtl();
u8 adminiSeqCheckBtl();
extern void FUN_003e0780(u32 value);
extern u32 FUN_003e0920(void);
void* memcpy(void* dst, const void* src, u8 size);
int printf(const char* fmt, ...);

// 0068f020
static const AdminiSeqEntry gAdminiSeqTable[ADMINI_SEQ_MAX] = 
{
    {NULL, NULL, NULL},                                         // ADMINI_SEQ_NULL
    {adminiSeqCallTest, adminiSeqExitTest, adminiSeqCheckTest}, // ADMINI_SEQ_TEST
    {NULL, K_Seq_ExitField, K_Seq_CheckField},                  // ADMINI_SEQ_FIELD. TODO
    {K_Seq_CallField2, K_Seq_ExitField2, K_Seq_CheckField2},    // ADMINI_SEQ_FIELD2
    {NULL, NULL, NULL},                                         // ADMINI_SEQ_MAP. TODO
    {K_Seq_CallDungeon, K_Seq_ExitDungeon, K_Seq_CheckDungeon}, // ADMINI_SEQ_DUNGEON
    {adminiSeqCallBtl, adminiSeqExitBtl, adminiSeqCheckBtl},    // ADMINI_SEQ_BATTLE
    {NULL, NULL, NULL},                                         // ADMINI_SEQ_FACILITY. TODO
};

void* adminiUpdateTask_Check(KwlnTask* adminiTask);

// FUN_0027c080
void adminiChangeSeq(s8 seqId, void* seqData, u8 seqDataSize, u8 isNotRestorable)
{
    KwlnTask* adminiTask;
    AdminiWork* admini;
    u32 flags;

    adminiTask = kwlnTaskGetTaskByName("admini");
    K_ASSERT(adminiTask != NULL, 46);

    admini = (AdminiWork*)kwlnTaskGetWorkData(adminiTask);
    K_ASSERT(admini != NULL, 48);

    flags = admini->flags | ADMINI_FLAG_CHANGING_SEQ;
    admini->flags = flags;
    flags &= ~ADMINI_FLAG_UNK08;
    admini->flags = flags;
    flags = admini->flags;
    flags &= ~ADMINI_FLAG_RESTORE_PREV;
    admini->flags = flags;

    admini->nextSeqId = seqId;
    admini->seqChangeDelay = 1;

    if (admini->seqData != NULL)
    {
        RwFree(admini->seqData);
        admini->seqData = NULL;
        admini->seqDataSize = 0;
    }

    if (seqData != NULL)
    {
        admini->seqData = ((void* (*)(u8, u32))rwGlobals.memFuncs.RwMalloc)(seqDataSize, rwMEMHINTDUR_GLOBAL);
        K_ASSERT(admini->seqData != NULL, 93);

        memcpy(admini->seqData, seqData, seqDataSize);
        admini->seqDataSize = seqDataSize;
    }
    else
    {
        admini->seqData = NULL;
        admini->seqDataSize = 0;
    }

    if (isNotRestorable)
    {
        ADMINI_SET_FLAGS(admini, ADMINI_FLAG_RESTORABLE);
        return;
    }

    ADMINI_RESET_FLAGS(admini, ADMINI_FLAG_RESTORABLE);
}

// FUN_0027c220. Set flag 'ADMINI_FLAG_PASSED_CHECK'
void adminiForcePassedCheck()
{
    KwlnTask* adminiTask;
    AdminiWork* admini;

    adminiTask = kwlnTaskGetTaskByName("admini");
    K_ASSERT(adminiTask != NULL, 46);

    admini = (AdminiWork*)kwlnTaskGetWorkData(adminiTask);
    K_ASSERT(admini != NULL, 48);

    ADMINI_SET_FLAGS(admini, ADMINI_FLAG_PASSED_CHECK);
}

// FUN_0027c2b0
s8 adminiGetNowSeqId()
{
    KwlnTask* adminiTask;
    AdminiWork* admini;

    adminiTask = kwlnTaskGetTaskByName("admini");
    K_ASSERT(adminiTask != NULL, 46);

    admini = (AdminiWork*)kwlnTaskGetWorkData(adminiTask);
    K_ASSERT(admini != NULL, 48);

    return admini->nowSeqId;
}

// FUN_0027c330
s8 adminiGetNextSeqId()
{
    KwlnTask* adminiTask;
    AdminiWork* admini;

    adminiTask = kwlnTaskGetTaskByName("admini");
    K_ASSERT(adminiTask != NULL, 46);

    admini = (AdminiWork*)kwlnTaskGetWorkData(adminiTask);
    K_ASSERT(admini != NULL, 48);

    return admini->nextSeqId;
}

// FUN_0027c3b0
void* adminiUpdateTask_Call(KwlnTask* adminiTask)
{
    AdminiWork* admini;
    void (*callFunc)(u8 isRestored, void* seqData);
    u32 flags;
    s32 isRestored;

    admini = (AdminiWork*)kwlnTaskGetWorkData(adminiTask);
    K_ASSERT(admini != NULL, 217);

    if (!(admini->flags & ADMINI_FLAG_CHANGING_SEQ) ||
         admini->nextSeqId < ADMINI_SEQ_NULL)
    {
        return adminiUpdateTask_Check;
    }

    if (admini->seqChangeDelay > 0)
    {
        admini->seqChangeDelay--;
        return KWLNTASK_CONTINUE;
    }

    admini->timer = 0;
    admini->nowSeqId = admini->nextSeqId;
    admini->nextSeqId = ADMINI_SEQ_INVALID;

    flags = admini->flags & ~ADMINI_FLAG_CHANGING_SEQ;
    admini->flags = flags;
    flags &= ~ADMINI_FLAG_PASSED_CHECK;
    admini->flags = flags;
    flags = admini->flags;

    if (flags & ADMINI_FLAG_RESTORABLE)
    {
        admini->oldSeqFlags[admini->oldSeqIdx] =
            (u8)admini->oldSeqFlags[admini->oldSeqIdx] |
            ADMINI_FLAG_CHANGING_SEQ;
        ADMINI_RESET_FLAGS(admini, ADMINI_FLAG_RESTORABLE);
    }

    flags = admini->flags;
    if (flags & ADMINI_FLAG_RESTORE_PREV)
    {
        isRestored = 1;
        admini->oldSeqIdx =
            (admini->oldSeqIdx + (ADMINI_SEQ_MAX - 1)) % ADMINI_SEQ_MAX;
        ADMINI_RESET_FLAGS(admini, ADMINI_FLAG_RESTORE_PREV);
    }
    else
    {
        isRestored = 0;
        if (flags & ADMINI_FLAG_UNK08)
        {
            ADMINI_RESET_FLAGS(admini, ADMINI_FLAG_UNK08);
        }
        else
        {
            admini->oldSeqIdx =
                (admini->oldSeqIdx + 1) % ADMINI_SEQ_MAX;
        }
    }

    admini->oldSeqIds[admini->oldSeqIdx] = admini->nowSeqId;
    admini->oldSeqFlags[admini->oldSeqIdx] = 0;

    callFunc = gAdminiSeqTable[admini->nowSeqId].adminiCallFunc;
    if (callFunc != NULL)
    {
        ((void (*)(s32, void*))callFunc)(isRestored, admini->seqData);
    }

    return adminiUpdateTask_Check;
}

// FUN_0027c5a0
void* adminiUpdateTask_Exit(KwlnTask* adminiTask)
{
    AdminiWork* admini;
    s32 seqChangeDelay;

    admini = (AdminiWork*)kwlnTaskGetWorkData(adminiTask);
    K_ASSERT(admini != NULL, 296);

    if (admini->nowSeqId >= ADMINI_SEQ_NULL &&
       (gAdminiSeqTable[admini->nowSeqId].adminiExitFunc != NULL))
    {
        seqChangeDelay = gAdminiSeqTable[admini->nowSeqId].adminiExitFunc();
        if (seqChangeDelay < 0)
        {
            return KWLNTASK_CONTINUE;
        }

        admini->seqChangeDelay = seqChangeDelay + 1;
        admini->nowSeqId = ADMINI_SEQ_INVALID;
    }

    return adminiUpdateTask_Call;
}

// FUN_0027c650
void* adminiUpdateTask_Check(KwlnTask* adminiTask)
{
    AdminiWork* admini;
    u8 (*checkFunc)();
    u32 flags;
    s32 oldSeqIdx;

    admini = (AdminiWork*)kwlnTaskGetWorkData(adminiTask);
    K_ASSERT(admini != NULL, 333);

    if (!(admini->flags & ADMINI_FLAG_PASSED_CHECK))
    {
        if (admini->nowSeqId >= ADMINI_SEQ_NULL)
        {
            checkFunc =
                gAdminiSeqTable[admini->nowSeqId].adminiCheckFunc;
            if (checkFunc != NULL && checkFunc())
            {
                ADMINI_SET_FLAGS(admini, ADMINI_FLAG_PASSED_CHECK);
            }
            admini->timer++;
        }
    }

    if ((admini->flags & ADMINI_FLAG_PASSED_CHECK) &&
        admini->nowSeqId >= ADMINI_SEQ_NULL)
    {
        oldSeqIdx =
            (admini->oldSeqIdx + (ADMINI_SEQ_MAX - 1)) % ADMINI_SEQ_MAX;
        if (admini->oldSeqIds[oldSeqIdx] >= ADMINI_SEQ_NULL &&
            ((u8)admini->oldSeqFlags[oldSeqIdx] &
             ADMINI_FLAG_CHANGING_SEQ))
        {
            printf("restore sequence!!\n");

            flags = admini->flags | ADMINI_FLAG_CHANGING_SEQ;
            admini->flags = flags;
            flags |= ADMINI_FLAG_RESTORE_PREV;
            admini->flags = flags;

            admini->nextSeqId = admini->oldSeqIds[oldSeqIdx];
            admini->seqChangeDelay = 1;
            ADMINI_RESET_FLAGS(admini, ADMINI_FLAG_RESTORABLE);

            if (admini->seqData != NULL)
            {
                RwFree(admini->seqData);
                admini->seqData = NULL;
                admini->seqDataSize = 0;
            }
        }

        if (!(admini->flags & ADMINI_FLAG_CHANGING_SEQ))
        {
            adminiChangeSeq(ADMINI_SEQ_NULL, NULL, 0, 0);
        }
        ADMINI_RESET_FLAGS(admini, ADMINI_FLAG_PASSED_CHECK);
    }

    if ((admini->flags & ADMINI_FLAG_CHANGING_SEQ) &&
        admini->nextSeqId >= ADMINI_SEQ_NULL)
    {
        return adminiUpdateTask_Exit;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_0027c840
void adminiDestroyTask(KwlnTask* adminiTask)
{
    AdminiWork* admini;

    admini = (AdminiWork*)kwlnTaskGetWorkData(adminiTask);
    
    if (admini->nowSeqId >= ADMINI_SEQ_NULL &&
       (gAdminiSeqTable[admini->nowSeqId].adminiExitFunc != NULL))
    {
        gAdminiSeqTable[admini->nowSeqId].adminiExitFunc();
    }

    if (admini->seqData != NULL)
    {
        RwFree(admini->seqData);
    }

    admini = (AdminiWork*)kwlnTaskGetWorkData(adminiTask);
    RwFree(admini);
}

// FUN_0027c8f0
KwlnTask* adminiCreateTask()
{
    s32 i;
    AdminiWork* admini;
    void* nullData;
    s32 invalidSeqId;

    if (kwlnTaskGetTaskByName("admini") != NULL)
    {
        return NULL;
    }

    admini = RwMalloc(sizeof(AdminiWork), rwMEMHINTDUR_GLOBAL);
    K_ASSERT(admini != NULL, 435);

    admini->flags = 0;
    admini->timer = 0;
    invalidSeqId = (admini->nowSeqId = ADMINI_SEQ_INVALID);
    admini->nextSeqId = invalidSeqId;
    admini->oldSeqIdx = 0;
    for (i = 0; i < ADMINI_SEQ_MAX; i++)
    {
        AdminiWork* indexedAdmini = (AdminiWork*)((u8*)admini + i);
        indexedAdmini->oldSeqIds[0] = invalidSeqId;
        indexedAdmini->oldSeqFlags[0] = 0;
    }
    admini->seqData = (nullData = NULL);
    admini->seqDataSize = 0;

    return kwlnTaskCreate(NULL, "admini", 1, adminiUpdateTask_Check, adminiDestroyTask, admini);
}

// FUN_0027c9e0
void adminiSeqCallTest(u8 isRestored, void* seqData)
{
    printf("+++ call\n");
}

// FUN_0027ca10
s32 adminiSeqExitTest()
{
    printf("+++ exit\n");

    return 0;
}

// FUN_0027ca40
u8 adminiSeqCheckTest()
{
    printf("+++ check\n");

    return true;
}

// FUN_0027ca70
void adminiSeqCallBtl(u8 isRestored, void* seqData)
{
    btlStart((BtlStartInfo*)seqData);
    btl0027d8b0();
}

// FUN_0027caa0
s32 adminiSeqExitBtl()
{
    KwlnTask* btlTask;

    btlTask = btlGetTask();
    if (btlTask != NULL)
    {
        kwlnTaskDestroyWithHierarchy(btlTask);
    }

    return 0;
}

// FUN_0027cae0
u8 adminiSeqCheckBtl()
{
    return btlGetTask() == NULL;
}
// FUN_0027CB10
void adminiSeqCallFacility(void* unused, u32* param_2)
{
    FUN_003e0780(*param_2);
}
// FUN_0027CB40
u32 adminiSeqExitFacility(void)
{
    return 0;
}

// FUN_0027CB50
u32 adminiSeqCheckFacility(void)
{
    return FUN_003e0920() == 0;
}
