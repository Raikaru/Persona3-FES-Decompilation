#include "Kosaka/k_sequence.h"
#include "Kosaka/Field/k_dungeon.h"
#include "Kosaka/Field/k_field.h"
#include "Kosaka/k_assert.h"
#include "Kernel/Kwln/kwlnTask.h"
KwlnTask* func_001ba5f0(KwlnTask* parentTask, u16 majorId, u16 minorId,
                        u16 param_4, u16 param_5, u16 param_6, u32 flags,
                        u8 param_8, u8 param_9, s16 param_10, s32 param_11,
                        s32 param_12, s32 param_13, s32 param_14);

typedef struct
{
    u8 unkData[0x0c];
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
} SeqField2;

// FUN_001b7850
s32 K_Seq_ExitField()
{
    if (K_Field_Get()->rootTask != NULL)
    {
        kwlnTaskDestroyWithHierarchy(K_Field_Get()->rootTask);

        K_Field_Get()->rootTask = NULL;
    }

    return 0;
}

// FUN_001b78a0
u8 K_Seq_CheckField()
{
    if (kwlnTaskExists(K_Field_Get()->rootTask) == true)
    {
        return false;
    }

    K_Field_Get()->rootTask = NULL;

    return true;
}

// FUN_001b7900
void func_001b7900(u8 isRestored, void* seqData)
{
    SeqField2* fieldData;

    fieldData = (SeqField2*)seqData;
    K_ASSERT(fieldData->unk_0c != 0, 0x91);

    K_Field_Get()->rootTask = func_001ba5f0(NULL,
                                            0, 0, 0, 0, 0,
                                            0, 0, 0, 0,
                                            fieldData->unk_0c,
                                            fieldData->unk_10,
                                            fieldData->unk_14,
                                            0);
}

// FUN_001b79a0
s32 func_001b79a0()
{
    if (K_Field_Get()->rootTask != NULL)
    {
        kwlnTaskDestroyWithHierarchy(K_Field_Get()->rootTask);
        K_Field_Get()->rootTask = NULL;
    }

    return 0;
}

// FUN_001b79f0
u8 func_001b79f0()
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
s32 K_Seq_ExitDungeon()
{
    if (gDungeonTask != NULL)
    {
        kwlnTaskDestroyWithHierarchy(gDungeonTask);
    }

    return 0;
}

// FUN_001b7ac0
u8 K_Seq_CheckDungeon()
{
    if (kwlnTaskExists(gDungeonTask) == true)
    {
        return false;
    }

    gDungeonTask = NULL;

    return true;
}