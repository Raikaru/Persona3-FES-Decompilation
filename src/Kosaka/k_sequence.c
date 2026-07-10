#include "Kosaka/k_sequence.h"
#include "Kosaka/Field/k_dungeon.h"
#include "Kosaka/Field/k_field.h"
#include "Kosaka/k_assert.h"
#include "Kernel/Kwln/kwlnTask.h"
// This field-root task creator has no recovered canonical name; see k_field.c.
KwlnTask* func_001ba5f0(KwlnTask* parentTask, u16 majorId, u16 minorId,
                        u16 fieldParam4, u16 fieldParam5, u16 fieldParam6, u32 flags,
                        u8 fieldParam8, u8 fieldParam9, s16 fieldParam10,
                        s32 eventParam0, s32 eventParam1, s32 eventParam2, s32 eventParam3);

// 28-byte ADMINI_SEQ_FIELD2 payload.  The first 12 bytes are not read by this callback.
typedef struct
{
    u8 unused[0x0c];
    s32 eventParam0; // 0x0c
    s32 eventParam1; // 0x10
    s32 eventParam2; // 0x14
} SeqField2;

// FUN_001b7850
s32 K_Seq_ExitField(void)
{
    if (K_Field_Get()->rootTask != NULL)
    {
        kwlnTaskDestroyWithHierarchy(K_Field_Get()->rootTask);

        K_Field_Get()->rootTask = NULL;
    }

    return 0;
}

// FUN_001b78a0
u8 K_Seq_CheckField(void)
{
    if (kwlnTaskExists(K_Field_Get()->rootTask) == true)
    {
        return false;
    }

    K_Field_Get()->rootTask = NULL;

    return true;
}

// FUN_001b7900
void K_Seq_CallField2(u8 isRestored, void* seqData)
{
    SeqField2* fieldData;

    fieldData = (SeqField2*)seqData;
    K_ASSERT(fieldData->eventParam0 != 0, 0x91);

    K_Field_Get()->rootTask = func_001ba5f0(NULL,
                                            0, 0, 0, 0, 0,
                                            0, 0, 0, 0,
                                            fieldData->eventParam0,
                                            fieldData->eventParam1,
                                            fieldData->eventParam2,
                                            0);
}

// FUN_001b79a0
s32 K_Seq_ExitField2(void)
{
    if (K_Field_Get()->rootTask != NULL)
    {
        kwlnTaskDestroyWithHierarchy(K_Field_Get()->rootTask);
        K_Field_Get()->rootTask = NULL;
    }

    return 0;
}

// FUN_001b79f0
u8 K_Seq_CheckField2(void)
{
    if (kwlnTaskExists(K_Field_Get()->rootTask) == true)
    {
        return false;
    }

    K_Field_Get()->rootTask = NULL;
    return true;
}

// FUN_001b7a50
void K_Seq_CallDungeon(u8 isRestored, void* seqData)
{
    SeqDungeon* seq = (SeqDungeon*)seqData;

    gDungeonTask = K_FldDungeon_CreateTask(NULL, seq->floor, seq->unk_04);
}

// FUN_001b7a90
s32 K_Seq_ExitDungeon(void)
{
    if (gDungeonTask != NULL)
    {
        kwlnTaskDestroyWithHierarchy(gDungeonTask);
    }

    return 0;
}

// FUN_001b7ac0
u8 K_Seq_CheckDungeon(void)
{
    if (kwlnTaskExists(gDungeonTask) == true)
    {
        return false;
    }

    gDungeonTask = NULL;

    return true;
}