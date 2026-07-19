#include "Kosaka/k_footstep.h"
#include "Kosaka/Field/k_event.h"
#include "Kosaka/Field/k_fldFrame.h"
#include "Graphics/Model/mdlManager.h"
#include "Main/g_data.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "Kosaka/Field/k_field.h"
#include "Kosaka/Field/k_dungeon.h"
#include "h_cdvd.h"
#include "h_fade.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/Field/k_unit.h"
#include "Kernel/Kwln/kwln.h"
#include "rw/rwcore.h"

extern void* memset(void* dst, int value, u32 count);
extern s32 func_001de630(s32 charId);
extern s32 func_001ded40(s32 charId);
extern void func_0010a4e0(s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern u8* D_0067EF00[];
extern Model* D_008717F0;
extern u32 D_00875A50[RESRC_ID_MASK + 1];
#pragma alias jtbl_0096017C_abs jtbl_0096017C
extern u32 jtbl_0096017C_abs[];

typedef s32 (*FootstepAnimSelector)(s32 charId);

static u32 K_Footstep_IsFrameWindow(f32 frame, f32 first, f32 second, f32 third, f32 fourth)
{
    return ((frame > first) && (frame < second)) ||
           ((frame > third) && (frame < fourth));
}

static u32 K_Footstep_IsNearPlayer(Model* mdl)
{
    RwMatrix* mdlMat = mdlGetMatrix(mdl);
    RwMatrix* playerMat = mdlGetMatrix(D_008717F0);
    return K_FldEvent_ArePosWithinDist(&mdlMat->pos, &playerMat->pos, 1600.0f) != 0;
}

static void K_Footstep_Play(u16 resTypeId, s32 material, s32 variant)
{
    u16 index = RESRC_GET_ID(resTypeId);
    u32* counter = &D_00875A50[index];

    func_0010a4e0(0, index + 1, variant, material * 4 + *counter);
    *counter += 1;
    if (*counter >= 4)
    {
        *counter = 0;
    }
}

static u32 K_Footstep_Try(Model* mdl, u16 charId, s16 animId, f32 frame,
                           FootstepAnimSelector selector, f32 first, f32 second,
                           f32 third, f32 fourth, u32 needProximity,
                           u16 resTypeId, s32 material, s32 variant)
{
    if (needProximity && !K_Footstep_IsNearPlayer(mdl))
    {
        return 0;
    }
    if (animId != selector(charId))
    {
        return 0;
    }
    if (!K_Footstep_IsFrameWindow(frame, first, second, third, fourth))
    {
        return 0;
    }
    K_Footstep_Play(resTypeId, material, variant);
    return 1;
}

static s32 K_Footstep_Surface(Model* mdl, RwV3d* position)
{
    ResrcFldHit* hit;
    const RwV3d* tri[3];
    static const RwV3d normal = {0.0f, 1.0f, 0.0f};
    u32 primary = (u32)gMtScene->fldMajorId;
    u32 secondary = (u32)gMtScene->fldMinorId;
    u8* materialTable;
    s32 material = 0;

    if ((primary >= 0x14) && (primary < 0x1d) && (secondary >= 0x32))
    {
        secondary -= 0x31;
    }
    materialTable = D_0067EF00[primary];
    if (materialTable == NULL)
    {
        return 0;
    }
    material = materialTable[secondary];

    hit = (ResrcFldHit*)MT_Scene_GetResListHead(0x15);
    while (hit != NULL)
    {
        tri[0] = &hit->vertices[0];
        tri[1] = &hit->vertices[1];
        tri[2] = &hit->vertices[2];
        if ((K_FldFrame_IsPointInTriangle(position, tri, &normal) != 0) &&
            (position->y < tri[0]->y + 100.0f) &&
            (position->y > tri[0]->y - 100.0f))
        {
            return hit->unk_14c;
        }

        tri[0] = &hit->vertices[1];
        tri[1] = &hit->vertices[2];
        tri[2] = &hit->vertices[3];
        if ((K_FldFrame_IsPointInTriangle(position, tri, &normal) != 0) &&
            (position->y < tri[0]->y + 100.0f) &&
            (position->y > tri[0]->y - 100.0f))
        {
            return hit->unk_14c;
        }
        hit = (ResrcFldHit*)hit->base.next;
    }
    return material;
}

// FUN_001da020 NONMATCHING
void K_Footstep_Update(Model* mdl, u16 charId, u16 resTypeId)
{
    u16 mdlType = mdl->type;
    u16 mdlId = mdl->id;
    s16 animId = mdlAnimGetId(mdl, 0);
    f32 frame = mdlAnimGetCurrentFrame(mdl, 0);
    RwMatrix* matrix;
    s32 material;
    u32 scenario;

    if ((gMtScene == NULL) || (gMtScene->fldMajorId >= 200))
    {
        return;
    }

    matrix = mdlGetMatrix(mdl);
    material = K_Footstep_Surface(mdl, &matrix->pos);
    if (charId >= 14)
    {
        return;
    }

    scenario = datGetScenarioMode();
    switch (charId)
    {
    case 0:
        return;

    case 1:
        if (scenario == SCENARIO_MODE_JOURNEY)
        {
            if (mdlType == 9)
            {
                if ((mdlId & 0xff) >= 9)
                {
                    return;
                }
                switch (mdlId & 0xff)
                {
                case 4:
                    if (animId == func_001de630(charId) &&
                        K_Footstep_IsFrameWindow(frame, 8.0f, 9.0f, 23.0f, 24.0f))
                    {
                        K_Footstep_Play(resTypeId, material, 1);
                    }
                     return;
                case 6:
                    K_Footstep_Try(mdl, charId, animId, frame, func_001ded40,
                                   9.0f, 10.0f, 19.0f, 20.0f, 0,
                                   resTypeId, material, 1);
                     return;
                default:
                    if (animId == func_001de630(charId))
                    {
                        if (K_Footstep_IsFrameWindow(frame, 10.0f, 11.0f, 25.0f, 26.0f))
                        {
                            K_Footstep_Play(resTypeId, material, 1);
                        }
                        return;
                    }
                    K_Footstep_Try(mdl, charId, animId, frame, func_001ded40,
                                   8.0f, 9.0f, 18.0f, 19.0f, 0,
                                   resTypeId, material, 1);
                     return;
                }
            }
            if (mdlType == 1)
            {
                K_Footstep_Try(mdl, charId, animId, frame, func_001ded40,
                               8.0f, 9.0f, 18.0f, 19.0f, false,
                               resTypeId, material, 1);
            }
            return;
        }

        if (mdlType == 9)
        {
            if (animId == func_001de630(charId))
            {
                if (K_Footstep_IsFrameWindow(frame, 12.0f, 13.0f, 24.0f, 25.0f))
                {
                    K_Footstep_Play(resTypeId, material, 1);
                }
                return;
            }
            K_Footstep_Try(mdl, charId, animId, frame, func_001ded40,
                           5.0f, 6.0f, 13.0f, 14.0f, 0,
                           resTypeId, material, 1);
        }
        else if (mdlType == 1)
        {
            K_Footstep_Try(mdl, charId, animId, frame, func_001ded40,
                           5.0f, 6.0f, 13.0f, 14.0f, false,
                           resTypeId, material, 1);
        }
        return;

    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 10:
    case 11:
    case 12:
    case 13:
        if (mdlType == 9)
        {
            K_Footstep_Try(mdl, charId, animId, frame, func_001ded40,
                           8.0f, 9.0f, 18.0f, 19.0f, false,
                           resTypeId, material, 5);
        }
        else if (mdlType == 1)
        {
            K_Footstep_Try(mdl, charId, animId, frame, func_001ded40,
                           8.0f, 9.0f, 18.0f, 19.0f, true,
                           resTypeId, material, 5);
        }
        return;

    case 8:
        if (mdlType == 9)
        {
            K_Footstep_Try(mdl, charId, animId, frame, func_001ded40,
                           6.0f, 7.0f, 14.0f, 15.0f, false,
                           resTypeId, material, 5);
        }
        else if (mdlType == 1)
        {
            K_Footstep_Try(mdl, charId, animId, frame, func_001ded40,
                           6.0f, 7.0f, 14.0f, 15.0f, true,
                           resTypeId, material, 5);
        }
        return;

    case 9:
        if (scenario == SCENARIO_MODE_JOURNEY)
        {
            if (mdlType == 9)
            {
                K_Footstep_Try(mdl, charId, animId, frame, func_001ded40,
                               8.0f, 9.0f, 18.0f, 19.0f, false,
                               resTypeId, material, 5);
            }
            else if (mdlType == 1)
            {
                K_Footstep_Try(mdl, charId, animId, frame, func_001ded40,
                               8.0f, 9.0f, 18.0f, 19.0f, true,
                               resTypeId, material, 5);
            }
        }
        else
        {
            if (mdlType == 9)
            {
                K_Footstep_Try(mdl, charId, animId, frame, func_001ded40,
                               8.0f, 9.0f, 18.0f, 19.0f, false,
                               resTypeId, material, 5);
            }
            else if (mdlType == 1)
            {
                K_Footstep_Try(mdl, charId, animId, frame, func_001ded40,
                               6.0f, 7.0f, 14.0f, 15.0f, true,
                               resTypeId, material, 5);
            }
        }
        return;
    }
}
typedef struct
{
    u32 state;
    u32 mode;
    u32 timer;
    KwlnTask* eplTask;
} FldEffectWork;

typedef struct
{
    u32 state;
    u32 mode;
    u32 kind;
    f32 screenX;
    f32 screenY;
    f32 depth;
    u8 data[0x218];
} FldEffectDrawWork;

typedef struct
{
    u32 state;
    u8 data[0x4c];
    void* resource;
    u8 padding[0xc];
} FldEffectResourceWork;

extern void* func_001a9080(KwlnTask* parent, const char* name, u32 priority, u32 flags);
extern u32 func_001a01c0(void);
extern u32 func_001a0310(void);
extern void* func_0018e5c0(void* owner, const void* data);
extern void* func_001a9180(KwlnTask* task);
extern void* func_001a91b0(KwlnTask* task, const RwV3d* position);
extern void func_001a9390(KwlnTask* task, void* handle, u32 value);
extern u32 func_002ff790(DatUnitGenusBase* genus);
extern void func_0018bee0(void* owner, s32 charId, u32 variant);
extern u8 D_006792E0[];
extern u8 D_006799FC[];
extern u8 D_00679A16[];
extern u8 D_00679A30[];
extern u8 D_00679A4A[];
extern u32 datGetMaxHp(s16 pcId);

static u32 K_Footstep_GameState(void)
{
    return func_001a01c0();
}

// FUN_001dc6f0 NONMATCHING
void* func_001dc6f0(KwlnTask* task)
{
    FldEffectWork* work;
    if (task == NULL || task->workData == NULL)
    {
        return KWLNTASK_CONTINUE;
    }
    work = (FldEffectWork*)task->workData;
    switch (work->state)
    {
    case 0:
        if (work->eplTask == NULL || func_001a9180(work->eplTask) == 0)
        {
            return KWLNTASK_CONTINUE;
        }
        {
            RwV3d pos = mdlGetMatrix(D_008717F0)->pos;
            void* effect;
            pos.y += 70.0f;
            effect = func_001a91b0(work->eplTask, &pos);
            func_001a9390(work->eplTask, effect, 5);
        }
        work->timer = 0;
        work->state = 1;
        break;
    case 1:
        ++work->timer;
        if (work->timer == 0x29 && work->mode != 0)
        {
            H_Fade_FadeOut();
            H_Fade_SetDuration(1);
            H_Fade_SetType(6);
        }
        if (work->timer >= 0x54)
        {
            work->state = 2;
        }
        break;
    case 2:
        return KWLNTASK_STOP;
    default:
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_001dc8e0
void func_001dc8e0(KwlnTask* task)
{
    (*(void (**)(void*))jtbl_0096017C_abs)(task->workData);
}
// FUN_001dc910 NONMATCHING
KwlnTask* func_001dc910(KwlnTask* parent, void* resource)
{
    FldEffectWork* work;
    KwlnTask* task;
    work = (FldEffectWork*)RwCalloc(1, sizeof(FldEffectWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent, 10, "field effect",
                                          func_001dc6f0, func_001dc8e0, work);
    work->mode = resource != NULL ? 1 : 0;
    if (resource != NULL && work->mode != 1)
    {
        work->eplTask = (KwlnTask*)resource;
    }
    else
    {
        work->eplTask = (KwlnTask*)func_001a9080(
            task, "field/effect", work->mode != 0 ? 0x32 : 0x53, 0);
    }
    return task;
}

// FUN_001dca10 NONMATCHING
void func_001dca10(void)
{
    static const char* const names[8] = {
        "field/effect0.epl", "field/effect1.epl", "field/effect2.epl",
        "field/effect3.epl", "field/effect4.epl", "field/effect5.epl",
        "field/effect6.epl", "field/effect7.epl"
    };
    static void* resources[8];
    HCdvd* cdvd = H_Cdvd_Request("field/effect.fld", HCDVD_FILENORMAL);
    u32 i;
    if (cdvd != NULL)
    {
        H_Cdvd_ReadSync(cdvd);
        for (i = 0; i < 8; ++i)
        {
            resources[i] = (void*)(u32)func_004d1260(names[i], 0);
        }
        H_Cdvd_Destroy(cdvd);
    }
}

// FUN_001dcb60 NONMATCHING
void* func_001dcb60(KwlnTask* task)
{
    FldEffectDrawWork* work;
    RwCamera* camera;
    RwV3d point;
    if (task == NULL || task->workData == NULL)
    {
        return KWLNTASK_CONTINUE;
    }
    work = (FldEffectDrawWork*)task->workData;
    camera = kwlnGetMainCamera();
    if (camera == NULL)
    {
        return KWLNTASK_CONTINUE;
    }
    if (work->state == 2)
    {
        return KWLNTASK_STOP;
    }
    if (work->state == 0)
    {
        work->state = 1;
        return KWLNTASK_CONTINUE;
    }
    point.x = work->screenX;
    point.y = work->screenY;
    point.z = work->depth;
    if (point.z <= 0.0f)
    {
        return KWLNTASK_CONTINUE;
    }
    work->screenX = 320.0f * (point.x / point.z) - 16.0f;
    work->screenY = 240.0f * (point.y / point.z) - 16.0f;
    return KWLNTASK_CONTINUE;
}

// FUN_001dd430
void func_001dd430(KwlnTask* task)
{
    (*(void (**)(void*))jtbl_0096017C_abs)(task->workData);
}

// FUN_001dd460
KwlnTask* func_001dd460(KwlnTask* parent, void* data, u32 kind)
{
    FldEffectDrawWork* work;
    KwlnTask* task;
    work = (FldEffectDrawWork*)RwCalloc(1, sizeof(FldEffectDrawWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "field draw effect", kind,
                          func_001dcb60, func_001dd430, work);
    work->kind = (u32)data;
    if (kind == 0x1058)
    {
        work->mode = 1;
    }
    else
    {
        work->mode = 0;
    }
    return task;
}

// FUN_001dd530
void func_001dd530(KwlnTask* task, const RwV3d* position)
{
    FldEffectDrawWork* work;
    RwV3d view;
    RwMatrix* viewMatrix;
    work = (FldEffectDrawWork*)task->workData;
    viewMatrix = &kwlnGetMainCamera()->viewMatrix;
    RwV3dTransformPoint(&view, position, viewMatrix);
    work->screenX = 640.0f * (view.x / view.z) - 16.0f;
    work->screenY = 448.0f * (view.y / view.z) - 16.0f;
    work->depth = view.z;
}

// FUN_001dd5e0
void func_001dd5e0(KwlnTask* task, u32 value)
{
    *(u32*)task->workData = value;
}

// FUN_001dd5f0
void func_001dd5f0(KwlnTask* task, u32 value)
{
    *(u32*)((u8*)task->workData + 0x224) = value;
}

// FUN_001dd600 NONMATCHING
u32 func_001dd600(void)
{
    u32 state = K_Footstep_GameState();
    if (datGetFlag(0xC35) != 0)
    {
        return 0;
    }
    if (state == 0)
    {
        return 1;
    }
    return state == 1 || state == 2 || state == 3 || state == 4 || state == 5;
}

// FUN_001dd8e0 NONMATCHING
void func_001dd8e0(void)
{
    u32 i;
    Field* field = K_Field_Get();
    void* owner = field != NULL ? *(void**)((u8*)field + 0x28) : NULL;
    if (owner == NULL)
    {
        return;
    }
    for (i = 0; i < FLDUNIT_PC_MAX; ++i)
    {
        FldUnit* unit = &gFldUnitsPc[i];
        if (unit->genusBase == NULL || unit->resrc == NULL)
        {
            continue;
        }
        if (func_002ff790(unit->genusBase) == 1)
        {
            func_0018bee0(owner, unit->charId, 2);
        }
        else if (datGetLevel((s16)unit->charId) < unit->unk_184)
        {
            unit->unk_184 = datGetLevel((s16)unit->charId);
            func_0018bee0(owner, unit->charId, 0);
        }
    }
}

// FUN_001ddb30 NONMATCHING
const void* func_001ddb30(void)
{
    u32 floor = K_FldDungeon_GetCurrentFloor();
    if (floor == 0)
    {
        return NULL;
    }
    switch (floor)
    {
    case 0x190: return D_006799FC;
    case 0x191: return D_00679A16;
    case 0x192: return D_00679A30;
    case 0x193: return D_00679A4A;
    default:
        return D_006792E0 + floor * 0x78;
    }
}

// FUN_001ddca0 NONMATCHING
void func_001ddca0(s32 index)
{
    Field* field = K_Field_Get();
    void* owner;
    const void* data;
    if (field == NULL || (owner = *(void**)((u8*)field + 0x2C)) == NULL)
    {
        return;
    }
    data = index < 0 ? func_001ddb30() : D_006792E0 + (u32)index * 0x78;
    if (data != NULL)
    {
        func_0018e5c0(owner, data);
    }
}

// FUN_001ddd30 NONMATCHING
u32 func_001ddd30(void)
{
    u32 state = K_Footstep_GameState();
    if (state == 0)
    {
        return 1;
    }
    if (datGetFlag(0xC35) != 0)
    {
        return 0;
    }
    return state != 0x21 && state != 0x20 && state != 0x23 && state != 0x25;
}

static u32 K_Footstep_StatusResult(u32 mode)
{
    u32 state = K_Footstep_GameState();
    if (mode == 1)
    {
        if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY && (state == 4 || state == 5))
        {
            return datGetFlag(0xC35) == 0;
        }
        return func_001a0310() == 1 && datGetFlag(0xC35) == 0;
    }
    if (mode == 2)
    {
        return state != 6 && state != 7 && datGetBadStatusNoDown(1) != UNIT_BADSTATUS_POISON;
    }
    if (mode == 5)
    {
        return datGetFlag(0xC2F) == 0 && state != 0x21;
    }
    if (mode == 7 || mode == 10 || mode == 13)
    {
        return datGetBadStatusNoDown(1) == UNIT_BADSTATUS_POISON;
    }
    return datGetFlag(0xC35) == 0;
}

// FUN_001dde00
u32 func_001dde00(s32 mode)
{
    switch (mode)
    {
    case 1:
        if (datGetScenarioMode() == 1)
        {
            if (gMtScene->fldMajorId == 4 || gMtScene->fldMajorId == 5)
            {
                if (datGetFlag(0xC35) != 0)
                {
                    return 0;
                }
                return 1;
            }
        }
        if (func_001a0310() == 1)
        {
            if (datGetFlag(0xC35) == 0)
            {
                goto footstep_case1_func_true;
            }
            return 0;
footstep_case1_func_true:
            return 1;
        }
        if (gMtScene->fldMajorId == 7)
        {
            if (gMtScene->fldMinorId == 6)
            {
                if (datGetTime() == 8)
                {
                    goto footstep_case1_time;
                }
            }
        }
        if (gMtScene->fldMajorId == 8)
        {
            if (gMtScene->fldMinorId == 1)
            {
                if (datGetTime() == 8)
                {
                    goto footstep_case1_time;
                }
            }
        }
        if (gMtScene->fldMajorId != 9)
        {
            goto footstep_case1_after_time;
        }
        if (gMtScene->fldMinorId != 1)
        {
            goto footstep_case1_after_time;
        }
        if (datGetTime() != 8)
        {
            goto footstep_case1_after_time;
        }

footstep_case1_time:
        if (datGetFlag(0xC35) == 0)
        {
            goto footstep_case1_time_true;
        }
        return 0;
footstep_case1_time_true:
        return 1;

footstep_case1_after_time:
        if (gMtScene->fldMajorId == 14 && gMtScene->fldMinorId == 5)
        {
            return 0;
        }
        if (gMtScene->fldMajorId == 0x21)
        {
            if (datGetFlag(0xC35) == 0)
            {
                goto footstep_case1_scene_true;
            }
            return 0;
footstep_case1_scene_true:
            return 1;
        }
        if (gMtScene->fldMajorId == 7 && datGetFlag(0xE00) == 1)
        {
            return 0;
        }
        if (gMtScene->fldMajorId == 6 && datGetFlag(0xE60) == 1)
        {
            if (datGetFlag(0xC35) == 0)
            {
                goto footstep_case1_six_true;
            }
            return 0;
footstep_case1_six_true:
            return 1;
        }
        if (func_001a01c0() == 1)
        {
            goto footstep_case1_status;
        }
        if (gMtScene->fldMajorId == 0x15)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x16)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x16)
        {
            if (gMtScene->fldMinorId == 0x33)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x17)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x17)
        {
            if (gMtScene->fldMinorId == 0x33)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x18)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x18)
        {
            if (gMtScene->fldMinorId == 0x33)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x19)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x1A)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x1B)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x29)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x2A)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x2B)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x2C)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x2D)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x2E)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x2F)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x27)
        {
            if (gMtScene->fldMinorId == 1)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId == 0x27)
        {
            if (gMtScene->fldMinorId == 2)
            {
                goto footstep_case1_status;
            }
        }
        if (gMtScene->fldMajorId != 0x27)
        {
            goto footstep_case1_default;
        }
        if (gMtScene->fldMinorId != 3)
        {
            goto footstep_case1_default;
        }
footstep_case1_status:
        if (datGetBadStatusNoDown((s16)mode) != 0x80)
        {
            goto footstep_case1_status_zero;
        }
        return 1;
footstep_case1_status_zero:
        return 0;
footstep_case1_default:
        if (datGetFlag(0xC35) != 0)
        {
            return 0;
        }
        return 1;
    case 2:
        if (gMtScene->fldMajorId == 6 || gMtScene->fldMajorId == 7)
        {
            return 0;
        }
        if (gMtScene->fldMajorId == 14 && gMtScene->fldMinorId == 5)
        {
            return 0;
        }
        if (datGetBadStatusNoDown((s16)mode) != 0x80)
        {
            goto footstep_case2_status_zero;
        }
        return 1;
footstep_case2_status_zero:
        return 0;

    case 5:
        if (gMtScene->fldMajorId == 14 && gMtScene->fldMinorId == 5)
        {
            return 0;
        }
        if (datGetFlag(0xC2F) == 1)
        {
            return 0;
        }
        if (gMtScene->fldMajorId == 0x21)
        {
            return 0;
        }
        if (datGetBadStatusNoDown((s16)mode) != 0x80)
        {
            goto footstep_case5_status_zero;
        }
        return 1;
footstep_case5_status_zero:
        return 0;

    case 7:
        if (gMtScene->fldMajorId == 14 && gMtScene->fldMinorId == 5)
        {
            return 0;
        }
        if (gMtScene->fldMajorId == 0x21)
        {
            return 0;
        }
        if (datGetBadStatusNoDown((s16)mode) != 0x80)
        {
            goto footstep_case7_status_zero;
        }
        return 1;
footstep_case7_status_zero:
        return 0;

    case 10:
        if (gMtScene->fldMajorId == 14 && gMtScene->fldMinorId == 5)
        {
            return 0;
        }
        if (datGetBadStatusNoDown((s16)mode) != 0x80)
        {
            goto footstep_case10_status_zero;
        }
        return 1;
footstep_case10_status_zero:
        return 0;

    case 13:
        if (gMtScene->fldMajorId == 14 && gMtScene->fldMinorId == 5)
        {
            return 0;
        }
        if (datGetBadStatusNoDown((s16)mode) != 0x80)
        {
            goto footstep_case13_status_zero;
        }
        return 1;
footstep_case13_status_zero:
        return 0;

    default:
        if (datGetBadStatusNoDown((s16)mode) != 0x80)
        {
            goto footstep_default_status_zero;
        }
        return 1;
footstep_default_status_zero:
        return 0;
    }
}

// FUN_001de630 NONMATCHING
s32 func_001de630(s32 charId)
{
    u32 state = K_Footstep_StatusResult(1);
    if (charId == 0)
    {
        return 0;
    }
    if (!state)
    {
        return 3;
    }
    if (charId == 6 || charId == 10 || charId == 13)
    {
        return 1;
    }
    if (charId == 1 || charId == 2 || charId == 3 || charId == 4 || charId == 5 ||
        charId == 7 || charId == 8 || charId == 9 || charId == 11 || charId == 12)
    {
        return datGetFlag(0xC35) != 0 ? 2 : 3;
    }
    return 0;
}

// FUN_001ded40 NONMATCHING
s32 func_001ded40(s32 charId)
{
    if (charId == 0)
    {
        return 0;
    }
    if (K_Footstep_StatusResult(5) == 0)
    {
        return 5;
    }
    if (charId == 6 || charId == 10 || charId == 13)
    {
        return 1;
    }
    if (charId == 1 || charId == 2 || charId == 3 || charId == 4 || charId == 5 ||
        charId == 7 || charId == 8 || charId == 9 || charId == 11 || charId == 12)
    {
        return 3;
    }
    return 0;
}

// FUN_001df450
s32 func_001df450(s32 mode)
{
    u32 result = func_001dde00(mode);

    switch (mode)
    {
    case 1:
        goto footstep_target_mode1;
    default:
        goto footstep_target_done;
    }
footstep_target_mode1:
        if (datGetScenarioMode() == 1)
        {
            if (gMtScene->fldMajorId == 4 || gMtScene->fldMajorId == 5)
            {
                result = 6 + (s32)(RpRandom() % 3U);
                goto footstep_target_done;
            }
        }
        if (func_001a0310() == 1)
        {
            result = 6 + (s32)(RpRandom() % 3U);
            goto footstep_target_done;
        }
        if (gMtScene->fldMajorId == 7)
        {
            if (gMtScene->fldMinorId == 6)
            {
                if (datGetTime() == 8)
                {
                    goto footstep_target_time_random;
                }
            }
        }
        if (gMtScene->fldMajorId == 8)
        {
            if (gMtScene->fldMinorId == 1)
            {
                if (datGetTime() == 8)
                {
                    goto footstep_target_time_random;
                }
            }
        }
        if (gMtScene->fldMajorId == 9)
        {
            if (gMtScene->fldMinorId == 1)
            {
                if (datGetTime() == 8)
                {
                    goto footstep_target_time_random;
                }
            }
        }
        goto footstep_target_after_time_random;

footstep_target_time_random:
        result = 6 + (s32)(RpRandom() % 3U);
        goto footstep_target_done;

footstep_target_after_time_random:
        if (gMtScene->fldMajorId == 0xE && gMtScene->fldMinorId == 5)
        {
            goto footstep_target_done;
        }
        if (gMtScene->fldMajorId == 0xE)
        {
            if (datGetTime() == 6)
            {
                if (clndGetCurrentMonth() == 0xB)
                {
                    if (clndGetCurrentDay() == 0x12)
                    {
                        goto footstep_target_calendar_random;
                    }
                }
                if (clndGetCurrentMonth() == 0xB)
                {
                    if (clndGetCurrentDay() == 0x13)
                    {
                        goto footstep_target_calendar_random;
                    }
                }
            }
        }
        goto footstep_target_after_calendar_random;

footstep_target_calendar_random:
        result = 6 + (s32)(RpRandom() % 3U);
        goto footstep_target_done;

footstep_target_after_calendar_random:
        if (gMtScene->fldMajorId == 0x21)
        {
            goto footstep_target_done;
        }
        if (gMtScene->fldMajorId == 7 && datGetFlag(0xE00) == 1)
        {
            goto footstep_target_done;
        }
        if (gMtScene->fldMajorId == 6)
        {
            if (datGetFlag(0xE60) == 1)
            {
                goto footstep_target_major6_random;
            }
        }
        goto footstep_target_after_major6_random;

footstep_target_major6_random:
        result = 6 + (s32)(RpRandom() % 3U);
        goto footstep_target_done;

footstep_target_after_major6_random:
        if (func_001a01c0() == 1)
        {
            goto footstep_target_special;
        }
        if (gMtScene->fldMajorId == 0x15)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x16)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x16)
        {
            if (gMtScene->fldMinorId == 0x33)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x17)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x17)
        {
            if (gMtScene->fldMinorId == 0x33)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x18)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x18)
        {
            if (gMtScene->fldMinorId == 0x33)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x19)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x1A)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x1B)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x29)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x2A)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x2B)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x2C)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x2D)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x2E)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x2F)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x29)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x2A)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x2B)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x2C)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x2D)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x2E)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x2F)
        {
            if (gMtScene->fldMinorId == 0x32)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x27)
        {
            if (gMtScene->fldMinorId == 1)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x27)
        {
            if (gMtScene->fldMinorId == 2)
            {
                goto footstep_target_special;
            }
        }
        if (gMtScene->fldMajorId == 0x27)
        {
            if (gMtScene->fldMinorId == 3)
            {
                goto footstep_target_special;
            }
        }
    goto footstep_target_random_default;

footstep_target_special:
    result = 0xF;
    goto footstep_target_done;


footstep_target_random_default:
    result = 6 + (s32)(RpRandom() % 3U);
footstep_target_done:
    return (s32)result;
}

// FUN_001dfa70 NONMATCHING
void* func_001dfa70(KwlnTask* task)
{
    FldEffectResourceWork* work;
    if (task == NULL || task->workData == NULL)
    {
        return KWLNTASK_CONTINUE;
    }
    work = (FldEffectResourceWork*)task->workData;
    if (work->state == 2)
    {
        return KWLNTASK_STOP;
    }
    if (work->state == 0)
    {
        work->state = 1;
        return KWLNTASK_CONTINUE;
    }
    if (work->resource == NULL)
    {
        work->state = 2;
        return KWLNTASK_CONTINUE;
    }
    if (func_001ddd30() != 0)
    {
        work->state = 2;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_001e04e0
void func_001e04e0(KwlnTask* task)
{
    (*(void (**)(void*))jtbl_0096017C_abs)(task->workData);
}

// FUN_001e0510
KwlnTask* func_001e0510(KwlnTask* parent, void* resource)
{
    FldEffectResourceWork* work;
    KwlnTask* task;
    work = (FldEffectResourceWork*)RwCalloc(1, sizeof(FldEffectResourceWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent, 10, "field runtime effect",
                                          func_001dfa70, func_001e04e0, work);
    work->resource = resource;
    return task;
}