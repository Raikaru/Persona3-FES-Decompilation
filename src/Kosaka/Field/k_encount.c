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
int func_001c0040(void);
#pragma alias jtbl_0096017C_abs jtbl_0096017C
extern u32 jtbl_0096017C_abs[];

extern u8* DAT_007ce4ac;
extern u8* DAT_007ce4b0;
extern u8* DAT_007ce4b4;
extern u8* DAT_007ce4b8;
extern u32 iGpffffb418;
extern s32* PTR_DAT_007cd540;

// FUN_001d75f0
u8 K_Encount_001d75f0(u32 param_1, u16 flag, u32 areaId)
{
    u8 result;
    int mapId;

    result = 0;
    mapId = param_1 & 0xffff;
    if ((0x14 <= mapId && mapId < 0x1d && flag == 0) ||
        (0x28 <= mapId && mapId < 0x31 && flag == 0) ||
        (0x33 <= mapId && mapId <= 0x3a) ||
        (0x47 <= mapId && mapId < 0x4f))
    {
        result = DAT_007ce4b0[(areaId & 0xffff) * 10 + 3];
    }
    else if (0x1e <= mapId && mapId < 0x28)
    {
        result = DAT_007ce4b4[mapId * 200 - 0x176d];
    }
    return result;
}

// FUN_001d76e0
u8 K_Encount_001d76e0(u32 param_1, u16 flag, u32 areaId)
{
    u8 result;
    int mapId;

    result = 0;
    mapId = param_1 & 0xffff;
    if ((0x14 <= mapId && mapId < 0x1d && flag == 0) ||
        (0x28 <= mapId && mapId < 0x31 && flag == 0) ||
        (0x33 <= mapId && mapId <= 0x3a) ||
        (0x47 <= mapId && mapId < 0x4f))
    {
        result = DAT_007ce4b0[(areaId & 0xffff) * 10 + 2];
    }
    else if (0x1e <= mapId && mapId < 0x28)
    {
        result = DAT_007ce4b4[mapId * 200 - 0x176e];
    }
    return result;
}

// FUN_001d77d0
u8 K_Encount_001d77d0(u32 param_1, u16 flag, u32 areaId)
{
    u8 result;
    int mapId;

    result = 0;
    mapId = param_1 & 0xffff;
    if ((0x14 <= mapId && mapId < 0x1d && flag == 0) ||
        (0x28 <= mapId && mapId < 0x31 && flag == 0) ||
        (0x33 <= mapId && mapId <= 0x3a) ||
        (0x47 <= mapId && mapId < 0x4f))
    {
        result = DAT_007ce4b0[(areaId & 0xffff) * 10 + 4];
    }
    else if (0x1e <= mapId && mapId < 0x28)
    {
        result = DAT_007ce4b4[mapId * 200 - 0x176c];
    }
    return result;
}

// FUN_001d7300 NONMATCHING
u32 K_Encount_001d7300(u32 param_1, u16 flag, u32 areaId)
{
    s32 temp_16;
    s32 temp_3;
    s32 temp_3_3;
    s32 temp_5;
    s32 temp_5_2;
    s32 var_18;
    s32 var_19;
    s32 var_20;
    s32 var_5;
    s32 var_7;
    u16 var_17;
    u16 var_21;
    u32 temp_18;
    u32 temp_6;
    u32 temp_hi;
    u32 var_17_2;
    u8 temp_4_2;
    u8* temp_3_2;
    u8* temp_4;

    var_21 = 0xffff;
    temp_3 = param_1 & 0xffff;
    if (((temp_3 >= 0x14) && (temp_3 < 0x1d) && !(flag & 0xffff)) ||
        ((temp_3 >= 0x28) && (temp_3 < 0x31) && !(flag & 0xffff)) ||
        ((temp_3 >= 0x33) && (temp_3 <= 0x3a)) ||
        ((temp_3 >= 0x47) && (temp_3 < 0x4f)))
    {
        var_17 = *(u16*)(DAT_007ce4b0 + (areaId & 0xffff) * 0xa);
        goto block_15;
    }
    if ((temp_3 >= 0x1f) && (temp_3 < 0x28))
    {
        var_17 = *(u16*)(DAT_007ce4b4 + temp_3 * 0xc8 + (flag & 0xffff) * 0xa -
                         0x1842);
        goto block_15;
    }
    else
    {
        return 0xffffffff;
    }
block_15:
        temp_16 = (var_17 & 0xffff) * 0x7c;
        temp_4 = DAT_007ce4ac + temp_16;
        temp_18 = temp_4[2] + (temp_4[0] + temp_4[1]);
        temp_hi = RpRandom() % temp_18;
        temp_5 = (s32)DAT_007ce4ac;
        temp_4_2 = *(u8*)(temp_5 + temp_16);
        if ((s32)temp_hi < (s32)temp_4_2)
        {
            var_20 = 1;
            var_19 = 0;
            var_18 = 0x14;
        }
        else if ((s32)temp_hi < (s32)(temp_4_2 +
                                      *(u8*)(temp_5 + temp_16 + 1)))
        {
            var_20 = 2;
            var_19 = 0x14;
            var_18 = 0x19;
        }
        else
        {
            var_20 = 4;
            var_19 = 0x19;
            var_18 = 0x1e;
        }
        if (func_001c0040() == 3)
        {
            var_20 = 4;
            var_19 = 0x19;
            var_18 = 0x1e;
        }
        var_17_2 = 0;
        var_5 = var_19;
loop_26:
        if (var_5 < var_18)
        {
            temp_3_2 = DAT_007ce4ac + temp_16 + var_5 * 4;
            if (*(u16*)(temp_3_2 + 4) != 0)
            {
                var_17_2 += *(u16*)(temp_3_2 + 6);
            }
            var_5 += 1;
            goto loop_26;
        }
        if (var_17_2 == 0)
        {
            return 0xffffffff;
        }
        temp_6 = RpRandom() % var_17_2;
        var_7 = 0;
        temp_5_2 = (s32)DAT_007ce4ac;
loop_33:
        if (var_19 < var_18)
        {
            temp_3_3 = var_19 * 4;
            var_7 += *(u16*)(temp_5_2 + temp_16 + temp_3_3 + 6);
            if ((s32)temp_6 < var_7)
            {
                var_21 = *(u16*)(temp_3_3 + temp_16 + temp_5_2 + 4);
            }
            else
            {
                var_19 += 1;
                goto loop_33;
            }
        }
        return (var_20 << 0x10) | (var_21 & 0xffff);
    }

// FUN_001d78c0 NONMATCHING
u16* K_Encount_001d78c0(u32 param_1, u16 flag, u32 areaId)
{
    s32 temp_3;
    s32 var_16;
    s32 var_18;
    s32 var_4;
    s32 var_4_2;
    s32 var_6;
    u16* temp_5;
    u16* var_19;
    u32 temp_3_3;
    u32 var_17;
    void* temp_3_2;

    var_19 = NULL;
    temp_3 = param_1 & 0xffff;
    if (((temp_3 >= 0x14) && (temp_3 < 0x1d) && !(flag & 0xffff)) ||
        ((temp_3 >= 0x28) && (temp_3 < 0x31) && !(flag & 0xffff)) ||
        ((temp_3 >= 0x33) && (temp_3 < 0x3b)) ||
        ((temp_3 >= 0x47) && (temp_3 < 0x4f)))
    {
        var_18 = (s32)(DAT_007ce4b8 +
                       (*(u16*)(DAT_007ce4b0 + ((areaId & 0xffff) * 0xa) + 6) & 0xffff) *
                           0xb4);
        goto block_15;
    }
    if ((temp_3 >= 0x1f) && (temp_3 < 0x28))
    {
        var_18 = (s32)(DAT_007ce4b8 +
                       (*(u16*)(DAT_007ce4b4 + (temp_3 * 0xc8) +
                                ((flag & 0xffff) * 0xa) - 0x183c) & 0xffff) *
                           0xb4);
        goto block_15;
    }
    return NULL;
block_15:
    var_16 = 1;
    if (func_001c0040() == 2)
    {
        var_16 = 2;
    }
    var_4 = 0;
    var_17 = 0;
loop_23:
    if (var_4 < 0xf)
    {
        temp_3_2 = (u8*)var_18 + var_4 * 0xc;
        if (*(u16*)((u8*)temp_3_2 + 2) != 0)
        {
            if ((*(u8*)((u8*)temp_3_2 + 7) & 1) != 0)
            {
                var_17 += var_16 * *(u16*)temp_3_2;
            }
            else
            {
                var_17 += *(u16*)temp_3_2;
            }
        }
        var_4 += 1;
        goto loop_23;
    }
    if (var_17 == 0)
    {
        K_ASSERT(0, 0x147);
    }
    temp_3_3 = RpRandom() % var_17;
    var_4_2 = 0;
    var_6 = 0;
loop_34:
    if (var_4_2 < 0xf)
    {
        temp_5 = (u16*)((u8*)var_18 + var_4_2 * 0xc);
        if (temp_5[1] != 0)
        {
            if ((((u8*)temp_5)[7] & 1) != 0)
            {
                var_6 += var_16 * temp_5[0];
            }
            else
            {
                var_6 += temp_5[0];
            }
            if ((s32)temp_3_3 < var_6)
            {
                var_19 = temp_5;
            }
            else
            {
                goto block_33;
            }
        }
        else
        {
block_33:
            var_4_2 += 1;
            goto loop_34;
        }
    }
    return var_19;
}
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
extern u16 func_002ffb00(DatUnitGenusBase* genus);
extern u32 datGetMaxHp(s16 pcId);
extern void func_0035c1a0(KwlnTask* task, int record);
extern ScrHeader* D_007CE220;
extern void func_001b00c0(KwlnTask* task);

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

// FUN_001d7b70 NONMATCHING
DatUnit* func_001d7b70(KwlnTask* task, s32 flatIndex)
{
    s32 temp_3;
    s32 temp_6;
    s32 var_10;
    s32 var_11;
    s32 var_4;
    s32 var_9;
    s32 pcCount;
    s32 ecCount;
    void* temp_8;
    void* ecBase;

    temp_8 = task->workData;
    var_10 = 0;
    var_4 = 0;
    pcCount = *(s32*)((u8*)temp_8 + 0x10);
    goto pc_check;
pc_body:
    if (flatIndex == var_10)
    {
        return (*(DatUnitGenusBase**)((u8*)*(FldUnit**)((u8*)temp_8 + var_4 * 4 + 0x18) +
                                      0x48))->unit;
    }
    var_10 += 1;
    var_4 += 1;
pc_check:
    if (var_4 < pcCount)
    {
        goto pc_body;
    }
    var_9 = 0;
    ecCount = *(s32*)((u8*)temp_8 + 0x14);
    goto ec_check;
ec_body:
    var_11 = 0;
    temp_6 = var_9 * 4;
    ecBase = (u8*)temp_8 + temp_6;
    goto unit_check;
unit_body:
    temp_3 = var_11 * 0x3c;
    if (((*(DatUnitGenusBase**)((u8*)*(FldUnit**)((u8*)ecBase + 0x28) + 0x48))->unit +
         var_11)->id != 0)
    {
        if (flatIndex == var_10)
        {
            return (*(DatUnitGenusBase**)((u8*)*(FldUnit**)((u8*)temp_8 + temp_6 +
                                                           0x28) +
                                          0x48))->unit + var_11;
        }
        var_10 += 1;
        goto unit_next;
    }
unit_next:
    var_11 += 1;
unit_check:
    if (var_11 < 6)
    {
        goto unit_body;
    }
    var_9 += 1;
ec_check:
    if (var_9 < ecCount)
    {
        goto ec_body;
    }
    return NULL;
}


// FUN_001d7c60 NONMATCHING
FldUnit* func_001d7c60(KwlnTask* task, s32 flatIndex)
{
    s32 temp_7;
    s32 var_10;
    s32 var_11;
    s32 var_12;
    s32 var_4;
    void* temp_9;

    temp_9 = task->workData;
    var_11 = 0;
    var_4 = 0;
    goto loop_4;
pc_body:
    if (flatIndex == var_11)
    {
        return *(FldUnit**)((u8*)temp_9 + var_4 * 4 + 0x18);
    }
    var_11 += 1;
    var_4 += 1;
loop_4:
    if (var_4 < *(s32*)((u8*)temp_9 + 0x10))
    {
        goto pc_body;
    }
    var_10 = 0;
    goto loop_14;
ec_body:
    var_12 = 0;
    temp_7 = var_10 * 4;
    goto loop_12;
unit_body:
    if (((*(FldUnit**)((u8*)temp_9 + temp_7 + 0x28))->genusBase->unit +
         var_12)->id != 0)
    {
        if (flatIndex == var_11)
        {
            return *(FldUnit**)((u8*)temp_9 + temp_7 + 0x28);
        }
        var_11 += 1;
        goto block_11;
    }
block_11:
    var_12 += 1;
loop_12:
    if (var_12 < 6)
    {
        goto unit_body;
    }
    var_10 += 1;
loop_14:
    if (var_10 < *(s32*)((u8*)temp_9 + 0x14))
    {
        goto ec_body;
    }
    return NULL;
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

// FUN_001d7d40 NONMATCHING
void* func_001d7d40(KwlnTask* task)
{
    EncounterWork* work;
    FldUnit* pc;
    FldUnit* ec;
    DatUnit* src;
    DatUnit* dst;
    u32 i;
    u32 alivePc;
    u32 aliveEc;

    if (task == NULL || task->workData == NULL)
    {
        return KWLNTASK_CONTINUE;
    }
    work = (EncounterWork*)task->workData;
    if (work->paused != 0)
    {
        return KWLNTASK_CONTINUE;
    }
    if (work->state == 0)
    {
        if (work->pcCount == 0 || work->ecCount == 0 ||
            work->pc[0] == NULL || work->ec[0] == NULL)
        {
            work->state = 2;
            return KWLNTASK_CONTINUE;
        }
        pc = work->pc[0];
        ec = work->ec[0];
        {
            RwV3d pos = mdlGetMatrix(pc->mdl)->pos;
            RwV3d epos = mdlGetMatrix(ec->mdl)->pos;
            pos.x = (pos.x + epos.x) * 0.5f;
            pos.y = (pos.y + epos.y) * 0.5f + 3.0f;
            pos.z = (pos.z + epos.z) * 0.5f;
            work->effectHandle = func_001a91b0((KwlnTask*)K_Encount_FieldWord(0x1200), &pos);
            func_001a9390((KwlnTask*)K_Encount_FieldWord(0x1200),
                          work->effectHandle, 3);
        }
        K_Encount_Face(pc, ec);
        K_Encount_Face(ec, pc);
        mdlAnimSet(pc->mdl, 0, 4, 0, 1);
        mdlAnimSetSpeed(pc->mdl, 0, 1.0f);
        mdlAnimSet(ec->mdl, 0, 3, 0, 1);
        mdlAnimSetSpeed(ec->mdl, 0, 1.0f);
        func_001b00c0(pc->unk_170);
        func_001b00c0(ec->unk_170);
        work->pcTotal = work->pcCount;
        work->ecTotal = 0;
        for (i = 0; i < work->ecCount; ++i)
        {
            if (work->ec[i] != NULL && work->ec[i]->genusBase != NULL)
            {
                work->ecTotal += work->ec[i]->genusBase->count;
            }
        }
        work->totalActive = work->pcTotal + work->ecTotal;
        if (work->totalActive != 0)
        {
            work->selectedFlatIndex = RpRandom() % work->totalActive;
        }
        work->state = 1;
        return KWLNTASK_CONTINUE;
    }
    if (work->state == 2)
    {
        return KWLNTASK_STOP;
    }
    if (work->state != 1)
    {
        return KWLNTASK_CONTINUE;
    }
    if (work->progress++ <= work->duration)
    {
        return KWLNTASK_CONTINUE;
    }
    work->progress = 0;
    src = func_001d7b70(task, (s32)work->selectedFlatIndex);
    if (src == NULL)
    {
        work->state = 2;
        return KWLNTASK_CONTINUE;
    }
    if (work->selectedFlatIndex < work->pcTotal && work->reaperFlag == 0)
    {
        pc = func_001d7c60(task, (s32)work->selectedFlatIndex);
        if (pc != NULL && work->ecTotal != 0)
        {
            do
            {
                dst = func_001d7b70(task,
                                   (s32)(work->pcTotal + (RpRandom() % work->ecTotal)));
            } while (dst != NULL && (s16)dst->hp <= 0);
            if (dst != NULL)
            {
                func_001fc590(src, dst);
            }
        }
    }
    else if (work->pcTotal != 0)
    {
        do
        {
            dst = func_001d7b70(task, (s32)(RpRandom() % work->pcTotal));
        } while (dst != NULL && (s16)dst->hp <= 0);
        if (dst != NULL)
        {
            func_001fc590(src, dst);
        }
    }
    alivePc = 0;
    for (i = 0; i < work->pcCount; ++i)
    {
        if (work->pc[i] != NULL && work->pc[i]->genusBase != NULL &&
            func_002ff790(work->pc[i]->genusBase) == 0)
        {
            ++alivePc;
        }
    }
    if (alivePc == 0)
    {
        func_001a9400((KwlnTask*)K_Encount_FieldWord(0x1200), work->effectHandle);
        work->state = 2;
        return KWLNTASK_CONTINUE;
    }
    aliveEc = 0;
    for (i = 0; i < work->ecCount; ++i)
    {
        ec = work->ec[i];
        if (ec == NULL || ec->genusBase == NULL)
        {
            continue;
        }
        if (func_002ff790(ec->genusBase) == 0)
        {
            ++aliveEc;
        }
        else
        {
            K_FldUnit_Destroy(ec);
            work->ec[i] = NULL;
        }
    }
    K_Encount_CompactEc(work);
    if (aliveEc == 0)
    {
        func_001a9400((KwlnTask*)K_Encount_FieldWord(0x1200), work->effectHandle);
        work->state = 2;
        return KWLNTASK_CONTINUE;
    }
    if (work->totalActive != 0)
    {
        work->selectedFlatIndex = (work->selectedFlatIndex + 1) % work->totalActive;
    }
    if (work->duration > 0x16)
    {
        work->duration = 0x16;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_001d89b0 NONMATCHING
void func_001d89b0(KwlnTask* task)
{
    EncounterWork* work;
    u32 i;

    if (task == NULL || task->workData == NULL)
    {
        return;
    }
    work = (EncounterWork*)task->workData;
    for (i = 0; i < work->pcCount && i < 4; ++i)
    {
        if (work->pc[i] != NULL && work->pc[i]->genusBase != NULL &&
            func_002ff790(work->pc[i]->genusBase) == 0)
        {
            void* field28 = K_Encount_FieldWord(0x28);
            if (field28 != NULL)
            {
                func_0018bee0(field28, work->pc[i]->charId, 0);
            }
        }
    }
    if (work->taskSlot < 3)
    {
        D_00875A40[work->taskSlot] = NULL;
    }
    RwFree(work);
}

// FUN_001d8b00 NONMATCHING
KwlnTask* func_001d8b00(KwlnTask* parent, FldUnit* pc, FldUnit* ec)
{
    EncounterWork* work;
    KwlnTask* task;
    u32 i;

    work = (EncounterWork*)RwCalloc(1, sizeof(EncounterWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent, 10, "field encounter",
                                          func_001d7d40, func_001d89b0, work);
    work->pc[0] = pc;
    work->pcCount = pc != NULL ? 1 : 0;
    work->ec[0] = ec;
    work->ecCount = ec != NULL ? 1 : 0;
    work->duration = 0x78;
    if (ec != NULL && ec->genusBase != NULL &&
        *(u16*)((u8*)ec->genusBase + 8) == 0x1FA)
    {
        work->reaperFlag = 1;
    }
    for (i = 0; i < 3; ++i)
    {
        if (D_00875A40[i] == NULL)
        {
            work->taskSlot = i;
            D_00875A40[i] = task;
            return task;
        }
    }
    work->taskSlot = 3;
    K_ASSERT(false, 0x29C);
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

// FUN_001d8e60 NONMATCHING
u32 func_001d8e60(KwlnTask* owner, FldUnit* pc, FldUnit* ec)
{
    EncounterWork* work;
    u32 changed = 0;
    if (owner == NULL || owner->workData == NULL)
    {
        return 0;
    }
    work = (EncounterWork*)owner->workData;
    if (pc != NULL && work->pcCount < 4)
    {
        work->pc[work->pcCount++] = pc;
        K_Encount_Face(pc, work->ecCount != 0 ? work->ec[0] : NULL);
        mdlAnimSet(pc->mdl, 0, 4, 0, 1);
        func_001b00c0(pc->unk_170);
        changed = 1;
    }
    if (ec != NULL && work->ecCount < 4)
    {
        work->ec[work->ecCount++] = ec;
        K_Encount_Face(ec, work->pcCount != 0 ? work->pc[0] : NULL);
        mdlAnimSet(ec->mdl, 0, 3, 0, 1);
        func_001b00c0(ec->unk_170);
        changed = 1;
    }
    if (changed)
    {
        u32 i;
        work->pcTotal = work->pcCount;
        work->ecTotal = 0;
        for (i = 0; i < work->ecCount; ++i)
        {
            if (work->ec[i] != NULL && work->ec[i]->genusBase != NULL)
            {
                work->ecTotal += work->ec[i]->genusBase->count;
            }
        }
        work->totalActive = work->pcTotal + work->ecTotal;
    }
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

// FUN_001d9310 NONMATCHING
u32 func_001d9310(EncounterRecord* out)
{
    u32 i;
    u32 found = 0;
    u32 maxHp;
    u32 hp;
    f32 maxHpF;
    f32 ratio;

    memset(out, 0, sizeof(*out));
    for (i = 1; i < 4; ++i)
    {
        FldUnit* unit = &gFldUnitsPc[i];
        if (unit->genusBase == NULL || unit->resrc == NULL ||
            func_002ff790(unit->genusBase) == 1)
        {
            continue;
        }
        maxHp = (u32)datGetMaxHp((s16)unit->charId);
        maxHpF = (f32)maxHp;
        hp = (u32)datGetHp((s16)unit->charId);
        ratio = (f32)hp / maxHpF;
        if (ratio < 0.26f)
        {
            found |= K_Encount_AppendRecord(out, unit->charId);
        }
    }
    return found;
}

// FUN_001d94d0 NONMATCHING
u32 func_001d94d0(EncounterRecord* out)
{
    u32 i;
    u32 found = 0;
    u32 maxHp;
    u32 hp;
    f32 maxHpF;
    f32 ratio;

    memset(out, 0, sizeof(*out));
    for (i = 1; i < 4; ++i)
    {
        FldUnit* unit = &gFldUnitsPc[i];
        if (unit->genusBase == NULL || unit->resrc == NULL ||
            (datGetBadStatusNoDown((s16)unit->charId) & UNIT_BADSTATUS_POISON) == 0)
        {
            continue;
        }
        maxHp = (u32)datGetMaxHp((s16)unit->charId);
        maxHpF = (f32)maxHp;
        hp = (u32)datGetHp((s16)unit->charId);
        ratio = (f32)hp / maxHpF;
        if (ratio >= 0.26f)
        {
            found |= K_Encount_AppendRecord(out, unit->charId);
        }
    }
    return found;
}

// FUN_001d96a0 NONMATCHING
u32 func_001d96a0(EncounterRecord* out)
{
    u32 i;
    u32 found = 0;
    u32 maxHp;
    u32 hp;
    f32 maxHpF;
    f32 ratio;

    memset(out, 0, sizeof(*out));
    for (i = 1; i < 4; ++i)
    {
        FldUnit* unit = &gFldUnitsPc[i];
        if (unit->genusBase == NULL || unit->resrc == NULL)
        {
            continue;
        }
        maxHp = (u32)datGetMaxHp((s16)unit->charId);
        maxHpF = (f32)maxHp;
        hp = (u32)datGetHp((s16)unit->charId);
        ratio = (f32)hp / maxHpF;
        if (ratio >= 0.26f && ratio < 0.75f)
        {
            found |= K_Encount_AppendRecord(out, unit->charId);
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

// FUN_001d9860 NONMATCHING
void* func_001d9860(KwlnTask* task)
{
    PeriodicWork* work;
    u32 i;
    u32 now;
    if (task == NULL || task->workData == NULL)
    {
        return KWLNTASK_CONTINUE;
    }
    work = (PeriodicWork*)task->workData;
    if (work->disabled != 0)
    {
        return KWLNTASK_CONTINUE;
    }
    if (work->state == 4)
    {
        return KWLNTASK_STOP;
    }
    now = K_Encount_Now(task);
    if (work->state == 3)
    {
        for (i = 0; i < 16; ++i)
        {
            if (work->scriptTask[i] != NULL && kwlnTaskExists(work->scriptTask[i]) != 0)
            {
                return KWLNTASK_CONTINUE;
            }
            work->scriptTask[i] = NULL;
        }
        work->timestamp = now;
        work->state = 1;
    }
    if (work->state == 0)
    {
        work->timestamp = now;
        work->state = 1;
    }
    if (now - work->timestamp < 0x385)
    {
        return KWLNTASK_CONTINUE;
    }
    if (work->initialGate == 0 && func_001d3830((KwlnTask*)K_Encount_FieldWord(0x24)) == 2)
    {
        for (i = 0; i < 16 && work->scriptTask[i] != NULL; ++i)
        {
        }
        if (i < 16)
        {
            K_Encount_CreatePeriodicScript(work, i, 2);
            work->initialGate = 1;
            work->state = 3;
        }
    }
    if (func_001d9310(&work->records[0]))
    {
        K_Encount_CreatePeriodicScript(work, 0, 4);
        work->state = 3;
    }
    if (func_001d94d0(&work->records[1]))
    {
        K_Encount_CreatePeriodicScript(work, 1, 5);
        work->state = 3;
    }
    if (func_001d96a0(&work->records[2]))
    {
        K_Encount_CreatePeriodicScript(work, 2, 6);
        work->state = 3;
    }
    work->timestamp = now;
    return KWLNTASK_CONTINUE;
}

// FUN_001d9ee0
void func_001d9ee0(KwlnTask* task)
{
    (*(void (**)(void*))jtbl_0096017C_abs)(task->workData);
}

// FUN_001d9f10
KwlnTask* func_001d9f10(KwlnTask* parent)
{
    PeriodicWork* work;
    if (func_001a01c0() == 0)
    {
        return NULL;
    }
    if (PTR_DAT_007cd540[0] == 0x21)
    {
        return NULL;
    }
    work = (PeriodicWork*)RwCalloc(1, sizeof(PeriodicWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }
    return kwlnTaskCreateWithAutoPriority(parent, 10, "field periodic",
                                          func_001d9860, func_001d9ee0, work);
}

// FUN_001d9fd0
u32 func_001d9fd0(KwlnTask* task)
{
    if (task == NULL)
    {
        return true;
    }
    return (s32)((PeriodicWork*)task->workData)->state > 0;
}

// FUN_001da000
void func_001da000(KwlnTask* task, u32 disabled)
{
    PeriodicWork* work;

    if (task == NULL)
    {
        return;
    }
    work = (PeriodicWork*)task->workData;
    work->disabled = disabled;
    work->timestamp = iGpffffb418;
}
