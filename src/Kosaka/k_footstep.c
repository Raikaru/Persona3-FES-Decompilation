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
extern u8 D_006791A0[];
extern u8 D_0067B160[];
extern u8 D_0067CFE0[];
extern u8 D_006799FC[];
extern u8 D_00679A16[];
extern u8 D_00679A30[];
extern u8 D_00679A4A[];
extern const char D_00683BC8[];
extern const char D_00683BE0[];
extern void* func_004d1260(const char* path, s32 mode);
extern u32 D_00875A60[];
extern const char D_00683C00[];
extern const char D_00683C20[];
extern const char D_00683C40[];
extern const char D_00683C60[];
extern const char D_00683C80[];
extern const char D_00683CA0[];
extern const char D_00683CC0[];
extern const char D_00683CE0[];
extern const char D_00683D00[];
extern const char D_00683D20[];
#pragma alias jtbl_0096017C_abs jtbl_0096017C
extern u32 jtbl_0096017C_abs[];
extern void func_004c69f0(RwV3d* output, const RwV3d* input);
extern RwMatrix* func_004c2fb0(RwMatrix* output, RwMatrix* input);
extern void func_004cb750(RwFrame* frame, const RwV3d* translation, s32 mode);
extern void func_004cb890(RwFrame* frame, f32 angle, const RwV3d* axis, s32 mode);
extern f32 func_0052ea00(f32 value);
extern f32 func_0052ea18(f32 x, f32 y);
extern s32 func_00530da0(f32 value);
extern f32 cosf(f32 value);
extern int printf(const char* format, ...);
extern f32 fGpffff8398;
extern f32 fGpffff8420;
extern f32 fGpffff8424;
extern f32 fGpffff8248;
extern const char gp0xffff95e0[];
extern u8 D_007E095E[];
extern u8 D_007E095F[];
extern u8 D_007E0960[];
extern u8 D_007E0961[];
extern u8 D_007E094C[];
extern u8 D_007E094E[];
extern const char D_00683D50[];


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
#define K_FOOTSTEP_PLAY_INLINE(resId, mat, var) \
    do { \
        u16 _index = RESRC_GET_ID(resId); \
        u32* _counter = &D_00875A50[_index]; \
        func_0010a4e0(0, (s16)(_index + 1), var, (s16)(mat * 4 + *_counter)); \
        *_counter += 1; \
        if (*_counter >= 4) { \
            *_counter = 0; \
        } \
    } while (0)

#define K_FOOTSTEP_TRY_INLINE(mdl_, charId_, animId_, frame_, selector_, first_, second_, third_, fourth_, proximity_, resId_, mat_, var_) \
    do { \
        u32 _ok = 1; \
        if (proximity_) { \
            RwMatrix* _mdlMat = mdlGetMatrix(mdl_); \
            RwMatrix* _playerMat = mdlGetMatrix(D_008717F0); \
            _ok = K_FldEvent_ArePosWithinDist(&_mdlMat->pos, &_playerMat->pos, 1600.0f) != 0; \
        } \
        if (_ok && (animId_ == selector_(charId_)) && \
            ((frame_ > first_) && (frame_ < second_) || \
             (frame_ > third_) && (frame_ < fourth_))) { \
            K_FOOTSTEP_PLAY_INLINE(resId_, mat_, var_); \
        } \
    } while (0)


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

// Recovered the scene-hit material fallback path and signed 16-bit sound-call arguments.
// Recovered the model-id 4 fallback and the model-id 6 legacy selector paths.
// The remaining case dispatch/code layout still differs from retail.
// FUN_001da020 NONMATCHING
void K_Footstep_Update(Model* mdl, u16 charId, u16 resTypeId)
{
    u16 mdlType = mdl->type;
    u16 mdlId = mdl->id;
    u16 animId = mdlAnimGetId(mdl, 0);
    f32 frame = mdlAnimGetCurrentFrame(mdl, 0);
    RwMatrix* matrix;
    RwV3d* position;
    ResrcFldHit* hit;
    const RwV3d* tri[3];
    const RwV3d normal = {0.0f, 1.0f, 0.0f};
    u8* materialTable;
    u32 primary;
    u32 secondary;
    s32 material;
    u32 scenario;

    if (gMtScene->fldMajorId >= 200)
    {
        return;
    }

    matrix = mdlGetMatrix(mdl);
    position = &matrix->pos;
    primary = (u32)gMtScene->fldMajorId;
    secondary = (u32)gMtScene->fldMinorId;
    if ((primary >= 0x14) && (primary < 0x1d) && (secondary >= 0x32))
    {
        secondary -= 0x31;
    }
    hit = (ResrcFldHit*)MT_Scene_GetResListHead(0x15);
    materialTable = D_0067EF00[primary];
    material = 0;
    if (materialTable != NULL)
    {
        material = materialTable[secondary];
    }
        while (hit != NULL)
        {
            tri[0] = &hit->vertices[0];
            tri[1] = &hit->vertices[1];
            tri[2] = &hit->vertices[2];
            if ((K_FldFrame_IsPointInTriangle(position, tri, &normal) != 0) &&
                (position->y < tri[0]->y + 100.0f) &&
                (position->y > tri[0]->y - 100.0f))
            {
                material = hit->unk_14c;
                break;
            }

            tri[0] = &hit->vertices[1];
            tri[1] = &hit->vertices[2];
            tri[2] = &hit->vertices[3];
            if ((K_FldFrame_IsPointInTriangle(position, tri, &normal) != 0) &&
                (position->y < tri[0]->y + 100.0f) &&
                (position->y > tri[0]->y - 100.0f))
            {
                material = hit->unk_14c;
                break;
            }
            hit = (ResrcFldHit*)hit->base.next;
        }
    switch (charId)
    {
    case 0:
        return;

    case 1:
        scenario = datGetScenarioMode();
        if (scenario == SCENARIO_MODE_JOURNEY)
        {
            if (mdlType == 9)
            {
                if ((u32)(mdlId & 0xff) >= 9)
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
                    else
                    {
                        K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                              8.0f, 9.0f, 18.0f, 19.0f, 0,
                                              resTypeId, material, 1);
                    }
                     return;
                case 6:
                    K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
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
                    K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                          8.0f, 9.0f, 18.0f, 19.0f, 0,
                                          resTypeId, material, 1);
                     return;
                }
            }
            if (mdlType == 1)
            {
                K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
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
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  5.0f, 6.0f, 13.0f, 14.0f, 0,
                                  resTypeId, material, 1);
        }
        else if (mdlType == 1)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  5.0f, 6.0f, 13.0f, 14.0f, false,
                                  resTypeId, material, 1);
        }
        return;

    case 2:
        if (mdlType == 9)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, false,
                                  resTypeId, material, 5);
        }
        else if (mdlType == 1)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, true,
                                  resTypeId, material, 5);
        }
        return;

    case 3:
        if (mdlType == 9)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, false,
                                  resTypeId, material, 5);
        }
        else if (mdlType == 1)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, true,
                                  resTypeId, material, 5);
        }
        return;

    case 4:
        if (mdlType == 9)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, false,
                                  resTypeId, material, 5);
        }
        else if (mdlType == 1)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, true,
                                  resTypeId, material, 5);
        }
        return;

    case 5:
        if (mdlType == 9)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, false,
                                  resTypeId, material, 5);
        }
        else if (mdlType == 1)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, true,
                                  resTypeId, material, 5);
        }
        return;

    case 6:
        if (mdlType == 9)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, false,
                                  resTypeId, material, 5);
        }
        else if (mdlType == 1)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, true,
                                  resTypeId, material, 5);
        }
        return;

    case 7:
        if (mdlType == 9)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, false,
                                  resTypeId, material, 5);
        }
        else if (mdlType == 1)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, true,
                                  resTypeId, material, 5);
        }
        return;

    case 8:
        if (mdlType == 9)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  6.0f, 7.0f, 14.0f, 15.0f, false,
                                  resTypeId, material, 5);
        }
        else if (mdlType == 1)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  6.0f, 7.0f, 14.0f, 15.0f, true,
                                  resTypeId, material, 5);
        }
        return;

    case 9:
        scenario = datGetScenarioMode();
        if (scenario == SCENARIO_MODE_JOURNEY)
        {
            if (mdlType == 9)
            {
                K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                      8.0f, 9.0f, 18.0f, 19.0f, false,
                                      resTypeId, material, 5);
            }
            else if (mdlType == 1)
            {
                K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                      8.0f, 9.0f, 18.0f, 19.0f, true,
                                      resTypeId, material, 5);
            }
        }
        else
        {
            if (mdlType == 9)
            {
                K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                      8.0f, 9.0f, 18.0f, 19.0f, false,
                                      resTypeId, material, 5);
            }
            else if (mdlType == 1)
            {
                K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                      6.0f, 7.0f, 14.0f, 15.0f, true,
                                      resTypeId, material, 5);
            }
        }
        return;
    case 10:
        if (mdlType == 9)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, false,
                                  resTypeId, material, 5);
        }
        else if (mdlType == 1)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, true,
                                  resTypeId, material, 5);
        }
        return;

    case 11:
        if (mdlType == 9)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, false,
                                  resTypeId, material, 5);
        }
        else if (mdlType == 1)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, true,
                                  resTypeId, material, 5);
        }
        return;

    case 12:
        if (mdlType == 9)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, false,
                                  resTypeId, material, 5);
        }
        else if (mdlType == 1)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, true,
                                  resTypeId, material, 5);
        }
        return;

    case 13:
        if (mdlType == 9)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, false,
                                  resTypeId, material, 5);
        }
        else if (mdlType == 1)
        {
            K_FOOTSTEP_TRY_INLINE(mdl, charId, animId, frame, func_001ded40,
                                  8.0f, 9.0f, 18.0f, 19.0f, true,
                                  resTypeId, material, 5);
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
typedef struct
{
    RwMatrix cameraMatrix;
    f32 translation[4];
    f32 rotationAxis[4];
    f32 inverse[4];
    f32 position[4];
} FootstepEffectScratch;


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
    work = (FldEffectWork*)task->workData;
    switch (work->state)
    {
    case 0:
        if (func_001a9180(work->eplTask) != 0)
        {
            RwV3d pos;
            pos = mdlGetMatrix(D_008717F0)->pos;
            pos.y += 240.0f;
            func_001a9390(work->eplTask, func_001a91b0(work->eplTask, &pos), 5);
            work->timer = 0;
            work->state += 1;
        }
        break;
    case 1:
        if (work->timer < 0x54)
        {
            if (work->timer >= 0x29)
            {
                s32 i;
                func_001d4180();
                for (i = 0; i < FLDUNIT_PC_MAX; ++i)
                {
                    FldUnit* unit = &gFldUnitsPc[i];
                    if (unit->genusBase != NULL && unit->resrc != NULL)
                    {
                        unit->resrc->base.flags &= ~2u;
                    }
                }
                if (work->mode == 1)
                {
                    H_Fade_FadeOut();
                    H_Fade_SetDuration(1);
                    H_Fade_SetType(6);
                    work->state += 1;
                }
            }
            work->timer += 1;
        }
        else
        {
            work->state += 1;
        }
        break;
    case 2:
        return KWLNTASK_STOP;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_001dc8e0
void func_001dc8e0(KwlnTask* task)
{
    (*(void (**)(void*))jtbl_0096017C_abs)(task->workData);
}
// FUN_001dc910
KwlnTask* func_001dc910(KwlnTask* parent, u32 mode)
{
    KwlnTask* task;
    FldEffectWork* work;

    work = (FldEffectWork*)RwCalloc(1, sizeof(FldEffectWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent, 10, D_00683BC8,
                                          func_001dc6f0, func_001dc8e0, work);
    work->mode = mode;
    if (mode == 0)
    {
        work->eplTask = (KwlnTask*)func_001a9080(task, D_00683BE0, 0x53, 0);
    }
    else if (mode == 1)
    {
        work->eplTask = (KwlnTask*)func_001a9080(task, D_00683BE0, 0x32, 0);
    }
    return task;
}

// FUN_001dca10
void func_001dca10(void)
{
    HCdvd* cdvd;

    cdvd = H_Cdvd_Request(D_00683C00, 1);
    H_Cdvd_ReadSync(cdvd);
    D_00875A60[0] = (u32)func_004d1260(D_00683C20, 0);
    D_00875A60[1] = (u32)func_004d1260(D_00683C40, 0);
    D_00875A60[2] = (u32)func_004d1260(D_00683C60, 0);
    D_00875A60[3] = (u32)func_004d1260(D_00683C80, 0);
    D_00875A60[4] = (u32)func_004d1260(D_00683CA0, 0);
    D_00875A60[5] = (u32)func_004d1260(D_00683CC0, 0);
    D_00875A60[6] = (u32)func_004d1260(D_00683CE0, 0);
    D_00875A60[7] = (u32)func_004d1260(D_00683D00, 0);
    D_00875A60[8] = (u32)func_004d1260(D_00683D20, 0);
    H_Cdvd_Destroy(cdvd);
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

// FUN_001dd600
u32 func_001dd600(void)
{
    s32 major;
    u32 result;

    result = 0;
    if (func_001a01c0() == 1)
    {
        result = 1;
    }
    major = gMtScene->fldMajorId;
    if (major == 33)
    {
        result = 0;
    }
    if (datGetFlag(0xc27) == 1)
    {
        result = 1;
    }
    major = gMtScene->fldMajorId;
    if ((major == 21 && gMtScene->fldMinorId == 50) ||
        (major == 22 && gMtScene->fldMinorId == 50) ||
        (major == 22 && gMtScene->fldMinorId == 51) ||
        (major == 23 && gMtScene->fldMinorId == 50) ||
        (major == 23 && gMtScene->fldMinorId == 51) ||
        (major == 24 && gMtScene->fldMinorId == 50) ||
        (major == 26 && gMtScene->fldMinorId == 50) ||
        (major == 26 && gMtScene->fldMinorId == 51) ||
        (major == 26 && gMtScene->fldMinorId == 52) ||
        (major == 26 && gMtScene->fldMinorId == 53) ||
        (major == 27 && gMtScene->fldMinorId == 50))
    {
        result = 1;
    }
    if ((major == 4 && gMtScene->fldMinorId == 10) ||
        (major == 39 && gMtScene->fldMinorId == 1) ||
        (major == 39 && gMtScene->fldMinorId == 3))
    {
        result = 1;
    }
    if ((major == 41 && gMtScene->fldMinorId == 50) ||
        (major == 42 && gMtScene->fldMinorId == 50) ||
        (major == 43 && gMtScene->fldMinorId == 50) ||
        (major == 44 && gMtScene->fldMinorId == 50) ||
        (major == 45 && gMtScene->fldMinorId == 50) ||
        (major == 46 && gMtScene->fldMinorId == 50) ||
        (major == 47 && gMtScene->fldMinorId == 50))
    {
        result = 1;
    }
    return result;
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

// FUN_001ddb30
const void* func_001ddb30(void)
{
    u32 floor;
    u32 index;
    u16* table;

    floor = K_FldDungeon_GetCurrentFloor();
    if (floor == 0)
    {
        index = 0;
        table = *(u16**)(D_006791A0 + gMtScene->fldMajorId * 4);
        if (table != NULL)
        {
            index = table[gMtScene->fldMinorId];
        }
        return D_006792E0 + index * 0x1A;
    }
    switch (floor)
    {
    case 0x190:
        return D_006799FC;
    case 0x191:
        return D_00679A16;
    case 0x192:
        return D_00679A30;
    case 0x193:
        return D_00679A4A;
    default:
        if (datGetScenarioMode() == 0)
        {
            return D_0067B160 + floor * 0x1A;
        }
        return D_0067CFE0 + floor * 0x1A;
    }
}

// FUN_001ddca0
void func_001ddca0(s32 index)
{
    const void* data;
    Field* field;

    field = K_Field_Get();
    if (*(void**)((u8*)field + 0x2C) == NULL)
    {
        return;
    }
    if (index == -1)
    {
        data = func_001ddb30();
    }
    else
    {
        data = D_006792E0 + (u32)index * 0x1A;
    }
    field = K_Field_Get();
    func_0018e5c0(*(void**)((u8*)field + 0x2C), data);
}

// FUN_001ddd30
u32 func_001ddd30(void)
{
    u32 result = 0;
    MtScene* scene;
    s32 major;

    if (func_001a01c0() == 1)
        result = 1;
    scene = gMtScene;
    major = scene->fldMajorId;
    if (major == 0x20 && scene->fldMinorId == 2)
        goto footstep_ddd30_false;
    if (major == 0x1f && scene->fldMinorId == 1)
        goto footstep_ddd30_false;
    if (major == 0x23 && scene->fldMinorId == 1)
        goto footstep_ddd30_false;
    if (major == 0x25 && scene->fldMinorId == 1)
        goto footstep_ddd30_false;
    if (major == 0x21)
        goto footstep_ddd30_false;
    goto footstep_ddd30_success;

footstep_ddd30_false:
    result = 0;
footstep_ddd30_success:
    return result;
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
    s32 result = 0;
    s32 major;
    s32 minor;

    switch (charId)
    {
    case 1:
        if (datGetScenarioMode() == 1 &&
            (gMtScene->fldMajorId == 4 || gMtScene->fldMajorId == 5))
        {
            result = 3;
            if (datGetFlag(0xC35) != 0)
            {
                result = 2;
            }
        }
        else if (func_001a0310() == 1)
        {
            result = 3;
            if (datGetFlag(0xC35) != 0)
            {
                result = 2;
            }
        }
        else if ((gMtScene->fldMajorId == 7 && gMtScene->fldMinorId == 6 &&
                  datGetTime() == 8) ||
                 (gMtScene->fldMajorId == 8 && gMtScene->fldMinorId == 1 &&
                  datGetTime() == 8) ||
                 (gMtScene->fldMajorId == 9 && gMtScene->fldMinorId == 1 &&
                  datGetTime() == 8))
        {
            result = 3;
            if (datGetFlag(0xC35) != 0)
            {
                result = 2;
            }
        }
        else
        {
            major = gMtScene->fldMajorId;
            minor = gMtScene->fldMinorId;
            if (major == 14 && minor == 5)
            {
                result = 1;
            }
            else if (major == 33)
            {
                result = 3;
                if (datGetFlag(0xC35) != 0)
                {
                    result = 2;
                }
            }
            else if (major == 7 && datGetFlag(0xE00) == 1)
            {
                result = 1;
            }
            else if (major == 6 && datGetFlag(0xE60) == 1)
            {
                result = 3;
                if (datGetFlag(0xC35) != 0)
                {
                    result = 2;
                }
            }
            else if (func_001a01c0() == 1 ||
                     ((major == 21 || major == 22 || major == 23 || major == 24 ||
                       major == 25 || major == 26 || major == 27 || major == 41 ||
                       major == 42 || major == 43 || major == 44 || major == 45 ||
                       major == 46 || major == 47) && minor == 50) ||
                     (major == 22 && minor == 51) ||
                     (major == 23 && minor == 51) ||
                     (major == 24 && minor == 51) ||
                     (major == 39 && (minor == 1 || minor == 2 || minor == 3)))
            {
                result = 3;
            }
            else
            {
                result = 3;
                if (datGetFlag(0xC35) != 0)
                {
                    result = 2;
                }
            }
        }
        break;

    case 2:
        major = gMtScene->fldMajorId;
        if (major == 6 || major == 7)
        {
            result = 1;
        }
        else if (major == 14 && gMtScene->fldMinorId == 5)
        {
            result = 1;
        }
        else
        {
            result = 3;
        }
        break;

    case 5:
        major = gMtScene->fldMajorId;
        if (major == 14 && gMtScene->fldMinorId == 5)
        {
            result = 1;
        }
        else if (datGetFlag(0xC2F) == 1 || major == 33)
        {
            result = 1;
        }
        else
        {
            result = 3;
        }
        break;

    case 7:
        major = gMtScene->fldMajorId;
        if ((major == 14 && gMtScene->fldMinorId == 5) || major == 33)
        {
            result = 1;
        }
        else
        {
            result = 3;
        }
        break;

    case 10:
    case 13:
        major = gMtScene->fldMajorId;
        result = (major == 14 && gMtScene->fldMinorId == 5) ? 1 : 3;
        break;

    case 6:
        if (gMtScene->fldMajorId == 14 && gMtScene->fldMinorId == 5)
        {
            result = 1;
        }
        break;

    default:
        result = 3;
        break;
    }

    return result;
}

// FUN_001ded40 NONMATCHING
s32 func_001ded40(s32 charId)
{
    s32 result;
    s32 major;

    result = 0;
    if (charId == 6) goto handler_6;
    if (charId == 13) goto handler_13;
    if (charId == 10) goto handler_10;
    if (charId == 7) goto handler_7;
    if (charId == 5) goto handler_5;
    if (charId == 2) goto handler_2;
    switch (charId) {
    case 1: goto handler_1;
    }
    goto default_case;

handler_1:
    if (datGetScenarioMode() == 1)
    {
        if (gMtScene->fldMajorId == 4 || gMtScene->fldMajorId == 5)
        {
            result = 5;
            if (datGetFlag(0xc35))
            {
                result -= 1;
            }
            goto done;
        }
    }
    if (func_001a0310() == 1)
    {
        result = 5;
        if (datGetFlag(0xc35))
        {
            result -= 1;
        }
        goto done;
    }
    if (gMtScene->fldMajorId == 7)
    {
        if (gMtScene->fldMinorId == 6)
        {
            if (datGetTime() == 8)
            {
                goto special_result;
            }
        }
    }
    if (gMtScene->fldMajorId == 8)
    {
        if (gMtScene->fldMinorId == 1)
        {
            if (datGetTime() == 8)
            {
                goto special_result;
            }
        }
    }
    if (gMtScene->fldMajorId == 9)
    {
        if (gMtScene->fldMinorId == 1)
        {
            if (datGetTime() == 8)
            {
                goto special_result;
            }
        }
    }
    goto after_special_result;
special_result:
    result = 5;
    if (datGetFlag(0xc35))
    {
        result -= 1;
    }
    goto done;
after_special_result:
    major = gMtScene->fldMajorId;
    if (major == 14 && gMtScene->fldMinorId == 5)
    {
        result = 1;
        goto done;
    }
    if (major == 33)
    {
        result = 3;
        if (datGetFlag(0xc35))
        {
            result -= 1;
        }
        goto done;
    }
    if (major == 7)
    {
        if (datGetFlag(0xe00) == 1)
        {
            goto done;
        }
    }
    major = gMtScene->fldMajorId;
    if (major == 6 && datGetFlag(0xe60) == 1)
    {
        result = 5;
        if (datGetFlag(0xc35))
        {
            result -= 1;
        }
        goto done;
    }
    if (func_001a01c0() == 1 ||
        (major == 21 && gMtScene->fldMinorId == 50) ||
        (major == 22 && gMtScene->fldMinorId == 50) ||
        (major == 22 && gMtScene->fldMinorId == 51) ||
        (major == 23 && gMtScene->fldMinorId == 50) ||
        (major == 23 && gMtScene->fldMinorId == 51) ||
        (major == 24 && gMtScene->fldMinorId == 50) ||
        (major == 24 && gMtScene->fldMinorId == 51) ||
        (major == 25 && gMtScene->fldMinorId == 50) ||
        (major == 26 && gMtScene->fldMinorId == 50) ||
        (major == 27 && gMtScene->fldMinorId == 50) ||
        (major == 41 && gMtScene->fldMinorId == 50) ||
        (major == 42 && gMtScene->fldMinorId == 50) ||
        (major == 43 && gMtScene->fldMinorId == 50) ||
        (major == 44 && gMtScene->fldMinorId == 50) ||
        (major == 45 && gMtScene->fldMinorId == 50) ||
        (major == 46 && gMtScene->fldMinorId == 50) ||
        (major == 47 && gMtScene->fldMinorId == 50) ||
        (major == 39 && gMtScene->fldMinorId == 1) ||
        (major == 39 && gMtScene->fldMinorId == 2) ||
        (major == 39 && gMtScene->fldMinorId == 3))
    {
        result = 3;
        goto done;
    }
    result = 5;
    if (datGetFlag(0xc35))
    {
        result -= 1;
    }
    goto done;

handler_2:
    major = gMtScene->fldMajorId;
    if (major == 6 || major == 7)
    {
        result = 2;
        goto done;
    }
    if (major == 14 && gMtScene->fldMinorId == 5)
    {
        result = 1;
        goto done;
    }
    result = 3;
    goto done;

handler_5:
    major = gMtScene->fldMajorId;
    if (major == 14 && gMtScene->fldMinorId == 5)
    {
        result = 1;
        goto done;
    }
    if (datGetFlag(0xc2f) == 1)
    {
        result = 2;
        goto done;
    }
    if (gMtScene->fldMajorId == 33)
    {
        goto done;
    }
    result = 3;
    goto done;

handler_7:
    major = gMtScene->fldMajorId;
    if (major == 14 && gMtScene->fldMinorId == 5)
    {
        result = 1;
        goto done;
    }
    if (major == 33)
    {
        result = 1;
        goto done;
    }
    result = 3;
    goto done;

handler_10:
    major = gMtScene->fldMajorId;
    if (major == 14 && gMtScene->fldMinorId == 5)
    {
        result = 1;
        goto done;
    }
    result = 3;
    goto done;

handler_13:
    major = gMtScene->fldMajorId;
    if (major == 14 && gMtScene->fldMinorId == 5)
    {
        result = 1;
        goto done;
    }
    result = 3;
    goto done;

handler_6:
    major = gMtScene->fldMajorId;
    if (major == 14 && gMtScene->fldMinorId == 5)
    {
        result = 1;
    }
    goto done;

default_case:
    result = 3;

done:
    return result;
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

// Reconstructed controller input, camera diagnostics, and frame transforms from retail.
// Remaining differences are compiler scheduling/register allocation in the large state-1 path.
// FUN_001dfa70 NONMATCHING
void* func_001dfa70(KwlnTask* task)
{
    FldEffectResourceWork* work;
    RwFrame* frame;
    s32 state;

    work = (FldEffectResourceWork*)task->workData;
    frame = *(RwFrame**)((u8*)work->resource + 4);
    state = (s32)work->state;
    switch (state)
    {
    case 0:
        {
            u32* src;
            u32* dst;
            s32 count;
            u32 value0;
            u32 value1;

            src = (u32*)((u8*)frame + 0x10);
            dst = (u32*)((u8*)work + 0x10);
            count = 8;
            do
            {
                value0 = src[0];
                value1 = src[1];
                src += 2;
                count -= 1;
                dst[0] = value0;
                dst[1] = value1;
                dst += 2;
            } while (count > 0);
            work->state += 1;
            goto footstep_continue;
        }

    case 1:
        {
            FootstepEffectScratch scratch;
            RwV3d* rotationAxis;
            u8* zero;
            s32 stickValue;
            s32 moved;
            s32 count;
            f32 stick;
            f32 axisDelta;
            f32 angle;
            f32 cameraAngle0;
            f32 cameraAngle1;
            f32 cameraAngle2;
            rotationAxis = (RwV3d*)scratch.rotationAxis;
            moved = 0;
            zero = (u8*)scratch.translation;
            count = 0xc;
            do
            {
                *zero++ = 0;
                count -= 1;
            } while (count != 0);
            angle = 0.0f;

            stickValue = (s32)D_007E095E[0];
            if (stickValue >= 0)
            {
                stick = (f32)stickValue;
            }
            else
            {
                stick = (f32)((stickValue >> 1) | (stickValue & 1));
                stick *= 2.0f;
            }
            axisDelta = stick - 128.0f;
            if ((axisDelta < -48.0f) || !(axisDelta <= 48.0f))
            {
                rotationAxis->x = 0.0f;
                rotationAxis->y = 1.0f;
                rotationAxis->z = 0.0f;
                angle = fGpffff8398 * axisDelta - angle;
                moved = 1;
            }

            stickValue = (s32)D_007E095F[0];
            if (stickValue >= 0)
            {
                stick = (f32)stickValue;
            }
            else
            {
                stick = (f32)((stickValue >> 1) | (stickValue & 1));
                stick *= 2.0f;
            }
            axisDelta = stick - 128.0f;
            if ((axisDelta < -48.0f) || !(axisDelta <= 48.0f))
            {
                rotationAxis = &frame->modelling.right;
                angle = fGpffff8398 * axisDelta - angle;
                moved = 1;
            }

            stickValue = (s32)D_007E0961[0];
            if (stickValue >= 0)
            {
                stick = (f32)stickValue;
            }
            else
            {
                stick = (f32)((stickValue >> 1) | (stickValue & 1));
                stick *= 2.0f;
            }
            axisDelta = stick - 128.0f;
            if ((axisDelta < -48.0f) || !(axisDelta <= 48.0f))
            {
                ((RwV3d*)scratch.translation)->x = frame->modelling.at.x;
                ((RwV3d*)scratch.translation)->y = frame->modelling.at.y;
                ((RwV3d*)scratch.translation)->z = frame->modelling.at.z;
                func_004c69f0((RwV3d*)scratch.translation,
                              (RwV3d*)scratch.translation);
                ((RwV3d*)scratch.translation)->x *= fGpffff8420 * axisDelta;
                ((RwV3d*)scratch.translation)->y *= fGpffff8420 * axisDelta;
                ((RwV3d*)scratch.translation)->z *= fGpffff8420 * axisDelta;
                moved = 1;
            }

            stickValue = (s32)D_007E0960[0];
            if (stickValue >= 0)
            {
                stick = (f32)stickValue;
            }
            else
            {
                stick = (f32)((stickValue >> 1) | (stickValue & 1));
                stick *= 2.0f;
            }
            axisDelta = stick - 128.0f;
            if ((axisDelta < -48.0f) || !(axisDelta <= 48.0f))
            {
                ((RwV3d*)scratch.translation)->x = frame->modelling.right.x;
                ((RwV3d*)scratch.translation)->y = frame->modelling.right.y;
                ((RwV3d*)scratch.translation)->z = frame->modelling.right.z;
                func_004c69f0((RwV3d*)scratch.translation,
                              (RwV3d*)scratch.translation);
                ((RwV3d*)scratch.translation)->x *= fGpffff8420 * axisDelta;
                ((RwV3d*)scratch.translation)->y *= fGpffff8420 * axisDelta;
                ((RwV3d*)scratch.translation)->z *= fGpffff8420 * axisDelta;
                moved = 1;
            }
            else if ((*(u16*)D_007E094C & 6) != 0)
            {
                ((RwV3d*)scratch.translation)->y -= 10.0f;
                moved = 1;
            }
            else if ((*(u16*)D_007E094C & 9) != 0)
            {
                ((RwV3d*)scratch.translation)->y += 10.0f;
                moved = 1;
            }
            else if ((*(u16*)D_007E094E & 0x1000) != 0)
            {
                rotationAxis->x = 0.0f;
                rotationAxis->y = 1.0f;
                rotationAxis->z = 0.0f;
                scratch.position[0] = frame->modelling.pos.x;
                scratch.position[1] = frame->modelling.pos.y;
                scratch.position[2] = frame->modelling.pos.z;
                scratch.inverse[0] = -scratch.position[0];
                scratch.inverse[1] = -scratch.position[1];
                scratch.inverse[2] = -scratch.position[2];
                func_004cb750(frame, (RwV3d*)scratch.inverse, 2);
                func_004cb890(frame, 0.0f, rotationAxis, 0);
                func_004cb750(frame, (RwV3d*)scratch.position, 2);
            }
            else if ((*(u16*)D_007E094E & 0x4000) != 0)
            {
                rotationAxis->x = 0.0f;
                rotationAxis->y = 1.0f;
                rotationAxis->z = 0.0f;
                scratch.position[0] = frame->modelling.pos.x;
                scratch.position[1] = frame->modelling.pos.y;
                scratch.position[2] = frame->modelling.pos.z;
                scratch.inverse[0] = -scratch.position[0];
                scratch.inverse[1] = -scratch.position[1];
                scratch.inverse[2] = -scratch.position[2];
                func_004cb750(frame, (RwV3d*)scratch.inverse, 2);
                func_004cb890(frame, 180.0f, rotationAxis, 0);
                func_004cb750(frame, (RwV3d*)scratch.position, 2);
            }
            else if ((*(u16*)D_007E094E & 0x8000) != 0)
            {
                rotationAxis->x = 0.0f;
                rotationAxis->y = 1.0f;
                rotationAxis->z = 0.0f;
                scratch.position[0] = frame->modelling.pos.x;
                scratch.position[1] = frame->modelling.pos.y;
                scratch.position[2] = frame->modelling.pos.z;
                scratch.inverse[0] = -scratch.position[0];
                scratch.inverse[1] = -scratch.position[1];
                scratch.inverse[2] = -scratch.position[2];
                func_004cb750(frame, (RwV3d*)scratch.inverse, 2);
                func_004cb890(frame, 90.0f, rotationAxis, 0);
                func_004cb750(frame, (RwV3d*)scratch.position, 2);
            }
            else if ((*(u16*)D_007E094E & 0x2000) != 0)
            {
                rotationAxis->x = 0.0f;
                rotationAxis->y = 1.0f;
                rotationAxis->z = 0.0f;
                scratch.position[0] = frame->modelling.pos.x;
                scratch.position[1] = frame->modelling.pos.y;
                scratch.position[2] = frame->modelling.pos.z;
                scratch.inverse[0] = -scratch.position[0];
                scratch.inverse[1] = -scratch.position[1];
                scratch.inverse[2] = -scratch.position[2];
                func_004cb750(frame, (RwV3d*)scratch.inverse, 2);
                func_004cb890(frame, 270.0f, rotationAxis, 0);
                func_004cb750(frame, (RwV3d*)scratch.position, 2);
            }
            else if ((*(u16*)D_007E094E & 0x20) != 0)
            {
                work->state += 1;
            }

            if ((*(u16*)D_007E094E & 0x40) != 0)
            {
                RwFrame* cameraFrame;
                u32* src;
                u32* dst;
                s32 value0;
                s32 value1;
                s32 value2;

                cameraFrame = (RwFrame*)kwlnGetMainCamera()->object.object.parent;
                value0 = func_00530da0(cameraFrame->modelling.right.x);
                value1 = func_00530da0(cameraFrame->modelling.right.y);
                value2 = func_00530da0(cameraFrame->modelling.right.z);
                printf(D_00683D50, value0, value1, value2);
                value0 = func_00530da0(cameraFrame->modelling.up.x);
                value1 = func_00530da0(cameraFrame->modelling.up.y);
                value2 = func_00530da0(cameraFrame->modelling.up.z);
                printf(D_00683D50, value0, value1, value2);
                value0 = func_00530da0(cameraFrame->modelling.at.x);
                value1 = func_00530da0(cameraFrame->modelling.at.y);
                value2 = func_00530da0(cameraFrame->modelling.at.z);
                printf(D_00683D50, value0, value1, value2);
                value0 = func_00530da0(cameraFrame->modelling.pos.x);
                value1 = func_00530da0(cameraFrame->modelling.pos.y);
                value2 = func_00530da0(cameraFrame->modelling.pos.z);
                printf(D_00683D50, value0, value1, value2);
                printf(gp0xffff95e0);

                src = (u32*)&cameraFrame->modelling;
                dst = (u32*)&scratch.cameraMatrix;
                count = 8;
                do
                {
                    dst[0] = src[0];
                    dst[1] = src[1];
                    src += 2;
                    count -= 1;
                    dst += 2;
                } while (count != 0);
                func_004c2fb0(&scratch.cameraMatrix, &scratch.cameraMatrix);
                cameraAngle0 = func_0052ea18(scratch.cameraMatrix.up.z,
                                             scratch.cameraMatrix.up.y);
                cameraAngle1 = -func_0052ea00(scratch.cameraMatrix.up.x);
                (void)func_0052ea00(scratch.cameraMatrix.at.x / cosf(cameraAngle1));
                cameraAngle2 = func_0052ea18(scratch.cameraMatrix.right.z,
                                             scratch.cameraMatrix.right.x);
                if (scratch.cameraMatrix.right.x <= 0.0f)
                {
                    cameraAngle0 = fGpffff8248 - cameraAngle0;
                }
                value0 = func_00530da0(cameraAngle0 * fGpffff8424);
                value1 = func_00530da0(cameraAngle2 * fGpffff8424);
                value2 = func_00530da0(cameraAngle1 * fGpffff8424);
                printf(D_00683D50, value0, value1, value2);
            }

            if (moved != 0)
            {
                scratch.position[0] = frame->modelling.pos.x;
                scratch.position[1] = frame->modelling.pos.y;
                scratch.position[2] = frame->modelling.pos.z;
                scratch.inverse[0] = -scratch.position[0];
                scratch.inverse[1] = -scratch.position[1];
                scratch.inverse[2] = -scratch.position[2];
                func_004cb750(frame, (RwV3d*)scratch.inverse, 2);
                func_004cb890(frame, angle, rotationAxis, 2);
                func_004cb750(frame, (RwV3d*)scratch.translation, 2);
                func_004cb750(frame, (RwV3d*)scratch.position, 2);
            }
            goto footstep_continue;
        }

    case 2:
        return KWLNTASK_STOP;

    default:
        return KWLNTASK_CONTINUE;
    }
footstep_continue:
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