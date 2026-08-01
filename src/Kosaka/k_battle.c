#include "Kosaka/Field/k_encount.h"
#include "Kosaka/Field/k_field.h"
#include "Kosaka/Field/k_unit.h"
#include "Kosaka/Field/k_fldFrame.h"
#include "Kosaka/Field/k_event.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Graphics/Model/mdlManager.h"
#include "Main/g_data.h"
#include "Main/Battle/Data/datUnit.h"
#include "Main/Battle/Data/datPersona.h"
#include "Scene/resrcManager.h"
#include "Kosaka/k_assert.h"
#include "Script/scrScriptProcess.h"
#include "Scene/mt_scene.h"
#include "rw/rprandom.h"
#include "libm.h"







extern void* memset(void* dst, int value, u32 count);
extern s32 func_001c0040(void);
extern u32 RpRandom(void);
#pragma alias jtbl_0096017C_abs jtbl_0096017C
extern u32 jtbl_0096017C_abs[];

extern u8* DAT_007ce4ac;
extern u8* DAT_007ce4b0;
extern u8* DAT_007ce4b4;
extern u8* DAT_007ce4b8;
extern u32 iGpffffb418;
extern s32* PTR_DAT_007cd540;
extern RwMatrix* func_004c38c0(void);
extern void func_004c3880(RwMatrix* matrix);
extern f32 func_004c69f0(RwV3d* out, const RwV3d* in);
extern f32 acosf(f32 value);
#pragma alias sDegreesPerRadian D_007CAFA0
extern f32 sDegreesPerRadian;
#pragma alias sEncountAxis D_00683B78
extern RwV3d sEncountAxis;
#pragma alias sEncountForward D_00683B88
extern RwV3d sEncountForward;
extern void* func_001d7d40(KwlnTask* task);
extern void func_001d89b0(KwlnTask* task);





typedef struct EncounterWork
{
    u32 state;
    u32 taskSlot;
    u32 paused;
    void* effectHandle;
    u32 pcCount;
    u32 ecCount;
    FldUnit* pc[4];
    FldUnit* ec[4];
    u32 progress;
    u32 duration;
    u32 reaperFlag;
    u32 totalActive;
    u32 pcTotal;
    u32 ecTotal;
    u32 selectedFlatIndex;
} EncounterWork;

typedef struct EncounterRecord
{
    u32 count;
    u32 ids[3];
} EncounterRecord;

typedef struct PeriodicWork
{
    u32 state;
    u32 disabled;
    u32 initialGate;
    u32 timestamp;
    KwlnTask* scriptTask[16];
    EncounterRecord records[16];
} PeriodicWork;

extern KwlnTask* D_00875A40[3];
extern void* func_001a9180(KwlnTask* task);
extern void* func_001a91b0(KwlnTask* task, const RwV3d* position);
extern void func_001a9390(KwlnTask* task, void* handle, u32 value);
extern void func_001a9400(KwlnTask* task, void* handle);
extern void func_00434f70(void);
extern u32 func_001fc720(DatUnit* unit);
extern void func_001fc590(DatUnit* src, DatUnit* dst);
extern u32 func_002ff790(DatUnitGenusBase* genus);
#pragma alias func_002ffb00_u32 func_002ffb00
extern u32 func_002ffb00_u32(DatUnitGenusBase* genus);
extern u16 func_002ffb00(DatUnitGenusBase* genus);
extern u32 datGetMaxHp(s16 pcId);
extern void func_0035c1a0(KwlnTask* task, int record);
extern ScrHeader* D_007CE220;
extern void func_001b00c0(KwlnTask* task);
extern void func_0010a4e0(s32 bank, s32 cue, s32 variant, s32 pan);

static u32 K_Encount_Now(KwlnTask* task)
{
    return task != NULL ? kwlnTaskGetTimer(task) : 0;
}

static void* K_Encount_FieldWord(u32 offset)
{
    Field* field = K_Field_Get();
    return field != NULL ? *(void**)((u8*)field + offset) : NULL;
}

static void K_Encount_Face(FldUnit* unit, FldUnit* target)
{
    RwMatrix matrix;
    RwV3d axis = {0.0f, 1.0f, 0.0f};
    RwV3d delta;
    f32 heading;

    if (unit == NULL || target == NULL || unit->mdl == NULL || target->mdl == NULL ||
        unit->resrc == NULL)
    {
        return;
    }
    delta = mdlGetMatrix(target->mdl)->pos;
    delta.x -= mdlGetMatrix(unit->mdl)->pos.x;
    delta.y = 0.0f;
    delta.z -= mdlGetMatrix(unit->mdl)->pos.z;
    heading = atan2f(delta.x, delta.z) * (180.0f / 3.14159265f);
    memset(&matrix, 0, sizeof(matrix));
    matrix.right.x = 1.0f;
    matrix.up.y = 1.0f;
    matrix.at.z = 1.0f;
    matrix.pos = mdlGetMatrix(unit->mdl)->pos;
    matrix.flags = 0x20003;
    RwMatrixRotate(&matrix, &axis, heading, rwCOMBINEPRECONCAT);
    K_FldFrame_CtlUpdateMdlMat(unit->resrc->collisCtlTask, &matrix);
}




static void K_Encount_CompactEc(EncounterWork* work)
{
    u32 i;
    u32 out = 0;
    for (i = 0; i < work->ecCount && i < 4; ++i)
    {
        if (work->ec[i] != NULL)
        {
            work->ec[out++] = work->ec[i];
        }
    }
    while (out < 4)
    {
        work->ec[out++] = NULL;
    }
}



// FUN_001d8b00 NONMATCHING
KwlnTask* func_001d8b00(KwlnTask* parent, FldUnit* pc, FldUnit* ec)
{
    KwlnTask* task;
    EncounterWork* work;
    s32 i;
    KwlnTask** tasks;

    work = (EncounterWork*)RwCalloc(1, sizeof(EncounterWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent, 10, "field encounter",
                                          func_001d7d40, func_001d89b0, work);
    work->pc[0] = pc;
    work->pcCount = 1;
    work->ec[0] = ec;
    work->ecCount = work->pcCount;
    tasks = D_00875A40;
    for (i = 0; tasks[i] != NULL && i < 3; ++i)
    {
    }
    if (i >= 3)
    {
        i = (u32)-1;
        K_ASSERT(false, 0x29C);
    }
    work->taskSlot = i;
    D_00875A40[i] = task;
    work->duration = 0x78;
    if (*(u16*)((u8*)ec->genusBase + 8) == 0x1FA)
    {
        work->reaperFlag = 1;
    }
    return task;
}

// FUN_001d8c60
void func_001d8c60(u32 paused)
{
    s32 i = 0;
    KwlnTask** tasks = D_00875A40;

    for (; i < 3; ++i)
    {
        if (tasks[i] != NULL)
        {
            ((EncounterWork*)tasks[i]->workData)->paused = paused;
        }
    }
}

// FUN_001d8cb0
void func_001d8cb0(void)
{
    memset(D_00875A40, 0, sizeof(KwlnTask*) * 3);
    func_00434f70();
}

// FUN_001d8cf0
void func_001d8cf0(void)
{
    s32 i;
    for (i = 0; i < 3; ++i)
    {
        if (D_00875A40[i] != NULL)
        {
            kwlnTaskDestroyWithHierarchy(D_00875A40[i]);
        }
    }
}

// FUN_001d8d50
u32 func_001d8d50(KwlnTask* task)
{
    return ((EncounterWork*)task->workData)->pcCount;
}

// FUN_001d8d60
FldUnit* func_001d8d60(KwlnTask* task, s32 index)
{
    EncounterWork* work;

    work = (EncounterWork*)task->workData;
    return work->pc[index];
}

// FUN_001d8d80
KwlnTask* func_001d8d80(FldUnit* unit)
{
    KwlnTask** tasks;
    s32 i;
    s32 j;

    if (unit == NULL)
    {
        return NULL;
    }
    i = 0;
    tasks = D_00875A40;
    while (i < 3)
    {
        KwlnTask* task;
        EncounterWork* work;
        s32 count;

        task = tasks[i];
        if (task != NULL)
        {
            work = (EncounterWork*)task->workData;
            j = 0;
            count = work->pcCount;
            while (j < count)
            {
                if (*(FldUnit**)((u8*)work + j * sizeof(FldUnit*) + 0x18) == unit)
                {
                    return task;
                }
                ++j;
            }
            j = 0;
            count = work->ecCount;
            while (j < count)
            {
                if (*(FldUnit**)((u8*)work + j * sizeof(FldUnit*) + 0x28) == unit)
                {
                    return task;
                }
                ++j;
            }
        }
        ++i;
    }
    return NULL;
}

// Retail offsets 0x00-0x4a8 reconstruct unit registration, facing rotation,
// field updates, and active-count aggregation; 1196 of 1200 bytes are implemented.
// FUN_001d8e60
u32 func_001d8e60(KwlnTask* owner, FldUnit* pc, FldUnit* ec)
{
    EncounterWork* work;
    RwV3d delta;
    RwV3d axis;
    RwV3d forward;
    u32 changed;
    RwMatrix* matrix;
    f32 angle;
    s32 i;

    work = (EncounterWork*)owner->workData;
    changed = 0;
    axis = sEncountAxis;
    forward = sEncountForward;
    matrix = func_004c38c0();
    if (pc != NULL)
    {
        work->pc[work->pcCount] = pc;
        work->pcCount += 1;
        mdlAnimSet(pc->mdl, 0, 4, 0, 1);
        func_001b00c0(pc->unk_170);

        delta.x = mdlGetMatrix(work->ec[0]->mdl)->pos.x -
                  mdlGetMatrix(pc->mdl)->pos.x;
        delta.y = mdlGetMatrix(work->ec[0]->mdl)->pos.y -
                  mdlGetMatrix(pc->mdl)->pos.y;
        delta.z = mdlGetMatrix(work->ec[0]->mdl)->pos.z -
                  mdlGetMatrix(pc->mdl)->pos.z;
        RwV3dNormalize(&delta, &delta);
        angle = sDegreesPerRadian *
                acosf(delta.x * forward.x +
                      delta.y * forward.y +
                      delta.z * forward.z);
        if (delta.x < 0.0f)
        {
            angle *= -1.0f;
        }

        matrix->at.z = 1.0f;
        matrix->up.y = 1.0f;
        matrix->right.x = 1.0f;
        matrix->up.x = 0.0f;
        matrix->right.z = 0.0f;
        matrix->right.y = 0.0f;
        matrix->at.y = 0.0f;
        matrix->at.x = 0.0f;
        matrix->up.z = 0.0f;
        matrix->pos.z = 0.0f;
        matrix->pos.y = 0.0f;
        matrix->pos.x = 0.0f;
        matrix->flags |= 0x20003;
        RwMatrixRotate(matrix, &axis, angle, rwCOMBINEPRECONCAT);
        K_FldFrame_CtlUpdateMdlMat(pc->resrc->collisCtlTask, matrix);
        if (*(KwlnTask**)((u8*)K_Field_Get() + 0x28) != NULL)
        {
            func_0018bee0(
                *(KwlnTask**)((u8*)K_Field_Get() + 0x28), pc->charId, 1);
        }
        changed = 1;
    }
    if (ec != NULL)
    {
        work->ec[work->ecCount] = ec;
        work->ecCount += 1;
        mdlAnimSet(ec->mdl, 0, 3, 0, 1);
        func_001b00c0(ec->unk_170);

        delta.x = mdlGetMatrix(work->pc[0]->mdl)->pos.x -
                  mdlGetMatrix(ec->mdl)->pos.x;
        delta.y = mdlGetMatrix(work->pc[0]->mdl)->pos.y -
                  mdlGetMatrix(ec->mdl)->pos.y;
        delta.z = mdlGetMatrix(work->pc[0]->mdl)->pos.z -
                  mdlGetMatrix(ec->mdl)->pos.z;
        RwV3dNormalize(&delta, &delta);
        angle = sDegreesPerRadian *
                acosf(delta.x * forward.x +
                      delta.y * forward.y +
                      delta.z * forward.z);
        if (delta.x < 0.0f)
        {
            angle *= -1.0f;
        }

        matrix->at.z = 1.0f;
        matrix->up.y = 1.0f;
        matrix->right.x = 1.0f;
        matrix->up.x = 0.0f;
        matrix->right.z = 0.0f;
        matrix->right.y = 0.0f;
        matrix->at.y = 0.0f;
        matrix->at.x = 0.0f;
        matrix->up.z = 0.0f;
        matrix->pos.z = 0.0f;
        matrix->pos.y = 0.0f;
        matrix->pos.x = 0.0f;
        matrix->flags |= 0x20003;
        RwMatrixRotate(matrix, &axis, angle, rwCOMBINEPRECONCAT);
        K_FldFrame_CtlUpdateMdlMat(ec->resrc->collisCtlTask, matrix);
        changed = 1;
    }
    if (changed == 1)
    {
        EncounterWork* activeWork;

        activeWork = (EncounterWork*)owner->workData;
        activeWork->pcTotal = activeWork->pcCount;
        activeWork->ecTotal = 0;
        i = 0;
        while (i < (s32)activeWork->ecCount)
        {
            activeWork->ecTotal +=
                ((EncounterWork*)((u8*)activeWork +
                    i * sizeof(activeWork->ec[0])))->ec[0]->genusBase->count;
            i += 1;
        }
        activeWork->totalActive = activeWork->pcTotal + activeWork->ecTotal;
    }
    func_004c3880(matrix);
    return changed;
}

static u32 K_Encount_AppendRecord(EncounterRecord* out, u16 id)
{
    if (out->count >= 3)
    {
        return 0;
    }
    out->ids[out->count++] = id;
    return 1;
}

static u32 K_Encount_HpRatio(u16 id, f32* ratio)
{
    u32 maxHp = datGetMaxHp((s16)id);
    if (maxHp == 0)
    {
        return 0;
    }
    *ratio = (f32)datGetHp((s16)id) / (f32)maxHp;
    return 1;
}

// FUN_001d9310 NONMATCHING
u32 func_001d9310(EncounterRecord* out)
{
    u32 i;
    u32 found = 0;

    memset(out, 0, sizeof(*out));
    for (i = 1; i < 4; ++i)
    {
        FldUnit* unit;
        s32 maxHp;
        s32 hp;
        f32 maxValue;
        f32 hpValue;

        if (gFldUnitsPc[i].genusBase == NULL ||
            gFldUnitsPc[i].resrc == NULL ||
            func_002ff790(gFldUnitsPc[i].genusBase) == 1)
        {
            continue;
        }
        unit = &gFldUnitsPc[i];
        maxHp = datGetMaxHp((s16)unit->charId);
        if (maxHp < 0)
        {
            continue;
        }
        maxValue = (f32)(u32)maxHp;
        maxValue += maxValue;
        hp = datGetHp((s16)unit->charId);
        if (hp < 0)
        {
            continue;
        }
        hpValue = (f32)(u32)hp;
        hpValue += hpValue;
        if (hpValue / maxValue < 0.26f)
        {
            out->ids[out->count++] = unit->charId;
            found = 1;
        }
    }
    return found;
}

// FUN_001d94d0 NONMATCHING
u32 func_001d94d0(EncounterRecord* out)
{
    u32 i;
    u32 found = 0;

    memset(out, 0, sizeof(*out));
    for (i = 1; i < 4; ++i)
    {
        FldUnit* unit = &gFldUnitsPc[i];
        u16* charId = &unit->charId;
        s32 maxHp;
        s32 hp;
        f32 maxValue;
        f32 hpValue;

        if (unit->genusBase == NULL || unit->resrc == NULL ||
            (datGetBadStatusNoDown((s16)*charId) & UNIT_BADSTATUS_POISON) == 0)
        {
            continue;
        }
        maxHp = datGetMaxHp((s16)*charId);
        if (maxHp < 0)
        {
            continue;
        }
        maxValue = (f32)(u32)maxHp;
        maxValue += maxValue;
        hp = datGetHp((s16)*charId);
        if (hp < 0)
        {
            continue;
        }
        hpValue = (f32)(u32)hp;
        if (hpValue / maxValue >= 0.26f)
        {
            out->ids[out->count++] = unit->charId;
            found = 1;
        }
    }
    return found;
}

// FUN_001d96a0 NONMATCHING
u32 func_001d96a0(EncounterRecord* out)
{
    u32 i;
    u32 found = 0;

    memset(out, 0, sizeof(*out));
    for (i = 1; i < 4; ++i)
    {
        FldUnit* unit;
        s32 maxHp;
        s32 hp;
        f32 maxValue;
        f32 hpValue;

        if (gFldUnitsPc[i].genusBase == NULL || gFldUnitsPc[i].resrc == NULL)
        {
            continue;
        }
        unit = &gFldUnitsPc[i];
        maxHp = datGetMaxHp((s16)unit->charId);
        if (maxHp < 0)
        {
            continue;
        }
        maxValue = (f32)(u32)maxHp;
        maxValue += maxValue;
        hp = datGetHp((s16)unit->charId);
        if (hp < 0)
        {
            continue;
        }
        hpValue = (f32)(u32)hp;
        if (hpValue / maxValue >= 0.26f && hpValue / maxValue < 0.75f)
        {
            out->ids[out->count++] = unit->charId;
            found = 1;
        }
    }
    return found;
}


static KwlnTask* K_Encount_CreatePeriodicScript(PeriodicWork* work, u32 slot, u32 procedure)
{
    KwlnTask* child;
    if (slot >= 16)
    {
        return NULL;
    }
    child = scrCreateTaskFromHeader(10, D_007CE220, procedure);
    work->scriptTask[slot] = child;
    if (child != NULL)
    {
        func_0035c1a0(child, (int)&work->records[slot]);
    }
    return child;
}
// W419 rejected probes (verify.py; nd/object/window and nd/object rate):
// func_001d8b00 ecCount literal: 55/348/352 (0.1580) -> 137/344/352 (0.3983); bound-first or explicit-loop shape: 56/348/352 (0.1609); combined: 139/344/352 (0.4041).
// func_001d9310 charId pointer: 203/436/448 (0.4656) -> 272/448/448 (0.6071).
// dataGetMaxHp u16 declaration variants: func_001d9310 203/436 (0.4656) -> 220/440 (0.5000), func_001d94d0 280/416 (0.6731) -> 294/420 (0.7000), func_001d96a0 208/440 (0.4727) -> 273/444 (0.6149).
