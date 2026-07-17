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
    u16 result;
    int encId;
    int recOff;
    int r;
    int acc;
    int tier;
    int lo;
    int hi;
    int i;
    int mapId;
    u8* p;

    result = 0xffff;
    mapId = param_1 & 0xffff;
    if ((0x14 <= mapId && mapId < 0x1d && flag == 0) ||
        (0x28 <= mapId && mapId < 0x31 && flag == 0) ||
        (0x33 <= mapId && mapId <= 0x3a) ||
        (0x47 <= mapId && mapId < 0x4f))
    {
        encId = *(u16*)(DAT_007ce4b0 + (areaId & 0xffff) * 10);
    }
    else if (0x1f <= mapId && mapId < 0x28)
    {
        encId = *(u16*)(DAT_007ce4b4 + mapId * 200 + (flag & 0xffff) * 10 - 0x1842);
    }
    else
    {
        return 0xffffffff;
    }
    recOff = (encId & 0xffff) * 0x7c;
    p = DAT_007ce4ac + recOff;
    hi = p[0] + p[1] + p[2];
    r = RpRandom() % hi;
    p = DAT_007ce4ac + recOff;
    if (r < (int)(u32)p[0])
    {
        tier = 1;
        lo = 0;
        hi = 0x14;
    }
    else if (r < (int)((u32)p[0] + (u32)p[1]))
    {
        tier = 2;
        lo = 0x14;
        hi = 0x19;
    }
    else
    {
        tier = 4;
        lo = 0x19;
        hi = 0x1e;
    }
    if (func_001c0040() == 3)
    {
        tier = 4;
        lo = 0x19;
        hi = 0x1e;
    }
    encId = 0;
    p = DAT_007ce4ac + recOff;
    for (i = lo; i < hi; i++)
    {
        if (*(u16*)(p + i * 4 + 4) != 0)
        {
            encId += *(u16*)(p + i * 4 + 6);
        }
    }
    if (encId == 0)
    {
        return 0xffffffff;
    }
    r = RpRandom() % encId;
    acc = 0;
    p = DAT_007ce4ac + recOff;
    for (; lo < hi; lo++)
    {
        acc += *(u16*)(p + lo * 4 + 6);
        if (r < acc)
        {
            result = *(u16*)(p + lo * 4 + 4);
            break;
        }
    }
    return tier << 0x10 | (result & 0xffff);
}

// FUN_001d78c0 NONMATCHING
u16* K_Encount_001d78c0(u32 param_1, u16 flag, u32 areaId)
{
    u16 encId;
    u8* recBase;
    int mult;
    int weightSum;
    int r;
    int acc;
    int i;
    int mapId;
    u16* e;

    mapId = param_1 & 0xffff;
    if ((0x14 <= mapId && mapId < 0x1d && flag == 0) ||
        (0x28 <= mapId && mapId < 0x31 && flag == 0) ||
        (0x33 <= mapId && mapId <= 0x3a) ||
        (0x47 <= mapId && mapId < 0x4f))
    {
        encId = *(u16*)(DAT_007ce4b0 + (areaId & 0xffff) * 10 + 6);
    }
    else if (0x1f <= mapId && mapId < 0x28)
    {
        encId = *(u16*)(DAT_007ce4b4 + mapId * 200 + (flag & 0xffff) * 10 - 0x183c);
    }
    else
    {
        return NULL;
    }
    recBase = DAT_007ce4b8 + (encId & 0xffff) * 0xb4;
    mult = 1;
    if (func_001c0040() == 2)
    {
        mult = 2;
    }
    weightSum = 0;
    for (i = 0; i < 0xf; i++)
    {
        e = (u16*)(recBase + i * 0xc);
        if (e[1] != 0)
        {
            if ((*(u8*)((int)e + 7) & 1) == 0)
            {
                weightSum += e[0];
            }
            else
            {
                weightSum += mult * e[0];
            }
        }
    }
    K_ASSERT(weightSum != 0, 0x147);
    r = RpRandom();
    acc = 0;
    for (i = 0;; i++)
    {
        if (0xe < i)
        {
            return NULL;
        }
        e = (u16*)(recBase + i * 0xc);
        if (e[1] != 0)
        {
            if ((*(u8*)((int)e + 7) & 1) == 0)
            {
                acc += e[0];
            }
            else
            {
                acc += mult * e[0];
            }
            if (r % weightSum < acc)
            {
                return e;
            }
        }
    }
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
    EncounterWork* work;
    s32 index = 0;
    u32 i;

    if (task == NULL || task->workData == NULL || flatIndex < 0)
    {
        return NULL;
    }
    work = (EncounterWork*)task->workData;
    for (i = 0; i < work->pcCount && i < 4; ++i)
    {
        if (index++ == flatIndex)
        {
            return work->pc[i] != NULL && work->pc[i]->genusBase != NULL ?
                       work->pc[i]->genusBase->unit : NULL;
        }
    }
    for (i = 0; i < work->ecCount && i < 4; ++i)
    {
        DatUnitGenusBase* genus = work->ec[i] != NULL ? work->ec[i]->genusBase : NULL;
        u32 j;
        if (genus == NULL || genus->unit == NULL)
        {
            continue;
        }
        for (j = 0; j < 6; ++j)
        {
            if (genus->unit[j].id == 0)
            {
                continue;
            }
            if (index++ == flatIndex)
            {
                return &genus->unit[j];
            }
        }
    }
    return NULL;
}

// FUN_001d7c60 NONMATCHING
FldUnit* func_001d7c60(KwlnTask* task, s32 flatIndex)
{
    EncounterWork* work;
    s32 index = 0;
    u32 i;

    if (task == NULL || task->workData == NULL || flatIndex < 0)
    {
        return NULL;
    }
    work = (EncounterWork*)task->workData;
    for (i = 0; i < work->pcCount && i < 4; ++i)
    {
        if (index++ == flatIndex)
        {
            return work->pc[i];
        }
    }
    for (i = 0; i < work->ecCount && i < 4; ++i)
    {
        DatUnitGenusBase* genus = work->ec[i] != NULL ? work->ec[i]->genusBase : NULL;
        u32 j;
        if (genus == NULL || genus->unit == NULL)
        {
            continue;
        }
        for (j = 0; j < 6; ++j)
        {
            if (genus->unit[j].id == 0)
            {
                continue;
            }
            if (index++ == flatIndex)
            {
                return work->ec[i];
            }
        }
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
        FldUnit* unit = &gFldUnitsPc[i];
        f32 ratio;
        if (unit->genusBase == NULL || unit->resrc == NULL ||
            func_002ff790(unit->genusBase) == 1 ||
            !K_Encount_HpRatio(unit->charId, &ratio))
        {
            continue;
        }
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
    memset(out, 0, sizeof(*out));
    for (i = 1; i < 4; ++i)
    {
        FldUnit* unit = &gFldUnitsPc[i];
        f32 ratio;
        if (unit->genusBase == NULL || unit->resrc == NULL ||
            (datGetBadStatusNoDown((s16)unit->charId) & UNIT_BADSTATUS_POISON) == 0 ||
            !K_Encount_HpRatio(unit->charId, &ratio))
        {
            continue;
        }
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
    memset(out, 0, sizeof(*out));
    for (i = 1; i < 4; ++i)
    {
        FldUnit* unit = &gFldUnitsPc[i];
        f32 ratio;
        if (unit->genusBase == NULL || unit->resrc == NULL ||
            !K_Encount_HpRatio(unit->charId, &ratio))
        {
            continue;
        }
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
