#include "Kosaka/k_command.h"
#include "Kosaka/k_assert.h"
#include "Kosaka/k_misc.h"
#include "Kosaka/k_data.h"
#include "Kosaka/Field/k_dungeon.h"
#include "Kosaka/Field/k_field.h"
#include "Kosaka/Field/k_unit.h"
#include "Kosaka/Field/k_fldFrame.h"
#include "Script/scrTraceCode.h"
#include "Script/scrScriptProcess.h"
#include "Script/scr.h"
#include "Graphics/Model/mdlManager.h"
#include "Scene/resrcManager.h"
#include "Scene/mt_scene.h"
#include "Main/g_data.h"
#include "Main/Battle/Data/datPersona.h"
#include "datCalendar.h"
#include "h_fade.h"
#include "h_snd.h"
#include "temporary.h"
#include "Kernel/Kwln/kwlnTask.h"
/*
 * Retail k_command passes the resource ID untruncated and narrows the second
 * argument. The mt_scene definition uses the opposite source widths, so keep
 * this translation unit's original ABI declaration local.
 */
extern u16 MT_Scene_CreateResModelNpc(s32 resId, u16 param_2, Model* mdl);
extern s32 scrGetUnkF0(void);
extern void func_001a0150(u16 resourceId, u32 value);
extern void func_00103c30(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
extern void func_00103cb0(void);
extern void func_001d6270(KwlnTask* parent, s32 mode, s32 value);
extern void func_001d6630(KwlnTask* parent, s32 mode, s32 value);
extern void func_001831e0(s32 pcId, s16 slot, void* value);
extern void func_003c8f70(void);
extern void func_003c8f20(void);
extern f32 func_001a5aa0(void* matrix);
extern f32 func_001a5b30(const RwMatrix* matrix);
extern u32 func_0043a230(s32 value);
extern void* func_001a9470(void* resource);
extern u32 func_001d00b0(void);
extern u32 func_001d1a90(void);
extern u32 func_001d1ce0(void);
extern void func_001d8c60(u32 value);
extern void func_001cd870(s32 index);
extern void func_004c43b0(void);
extern void* func_001cd9a0(u32 value);
extern void func_0030c440(void);
extern u32 func_0045af40(void);
extern void func_003952d0(s32 arg0, s32 arg1, s32 arg2);
extern void func_0045a400(void);
extern void func_0016f1f0(s32 bit, u32 enabled);
extern void func_0035bc00(s32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void func_0027d8d0(void);
extern void func_00429e80(void* object, u32 enabled);
extern void func_003b78b0(u16 resourceId, void* data, void* values);
extern void func_0019c320(KwlnTask* task, f32 value);
extern void func_003c8da0(s32 mode);
extern void func_003c8dd0(BmdHeader* header);
extern u32 func_003c8de0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern u32 func_003c8ec0(s32 arg0, s32 arg1);
extern void func_00434e60(void);
extern void func_00434d30(void);
extern void func_00435370(s8 value);
extern RwMatrix* func_004cb2f0(void* frame);
extern f32 func_001a5bc0(const RwMatrix* matrix);
extern u32 FUN_001b32f0(u32 resource, u32 wanted, u32* hasOverlay);
extern void mdl00318a70(void);
extern void func_00319230(Model* mdl, u32 value);
extern u8 D_008717E8[];
extern u8 D_008717F4[];
extern RwV3d D_00683670;
extern const char DAT_0067F040[][0x40];

void* func_001c0960(KwlnTask* fadeTask);
void func_001c0d30(KwlnTask* fadeTask);

// FUN_001c1e20
void func_001c1e20(KwlnTask* transWallTask)
{
    ResrcModelFld* modelFld;
    void* fadeWork;

    modelFld = (ResrcModelFld*)MT_Scene_GetResListHead(RESRC_TYPE_MODELFLD);
    while (modelFld != NULL)
    {
        if ((modelFld->base.flags & 2) == 0)
        {
            modelFld = (ResrcModelFld*)modelFld->base.next;
            continue;
        }

        if (mdlGetColor(modelFld->mdl)->a == 0)
        {
            fadeWork = (*(void* (**)(u32, u32, u32))((u8*)&rwGlobals + 0x184))(1, 0x14, rwMEMHINTDUR_GLOBAL);
            if (fadeWork != NULL)
            {
                kwlnTaskCreateWithAutoPriority(transWallTask,
                                               10,
                                               "RMD fade CTL",
                                               func_001c0960,
                                               func_001c0d30,
                                               fadeWork);
                ((void**)fadeWork)[1] = modelFld;
                ((u32*)fadeWork)[2] = 1;
                ((f32*)fadeWork)[3] = 255.0f;
            }
        }

        modelFld = (ResrcModelFld*)modelFld->base.next;
    }

    ((void (*)(void*))(*(void**)((u8*)&rwGlobals + 0x17c)))(transWallTask->workData);
}

// FUN_001c2480
u32 K_Cmd_SKIP_TO_DARK_HOUR()
{
    if (K_Field_Get()->rootTask != NULL)
    {
        datSetTimeSkipTarget(CALENDAR_TIME_DARK_HOUR);
        datSetSkipToTarget(true);
        datSetDaysSkipTarget(datGetDaysSinceApr5());

        K_Field_SetShouldShutdown(K_Field_Get()->rootTask, true);

        clndReqSkip();
    }

    return true;
}

// FUN_001c2550
u32 K_Cmd_REQ_CLND_SKIP()
{
    clndReqSkip();

    return true;
}

void FUN_001d0270();
void FUN_001bfcc0();

// FUN_001c2580
u32 K_Cmd_001c2580()
{
    FUN_001d0270();
    FUN_001bfcc0();

    return true;
}

// FUN_001c25b0
u32 K_Cmd_FADE_IN()
{
    s32 duration;

    duration = scrGetIntPara(0);

    H_Fade_FadeIn();
    if (duration != 0)
    {
        H_Fade_SetDuration(duration);
    }

    return true;
}

// FUN_001c2610
u32 K_Cmd_FADE_OUT()
{
    s32 type;
    s32 duration;

    type = scrGetIntPara(0);
    duration = scrGetIntPara(1);

    H_Fade_FadeOut();
    H_Fade_SetType(type);
    if (duration != 0)
    {
        H_Fade_SetDuration(duration);
    }

    return true;
}

// FUN_001c2690
u32 K_Cmd_FADE_OUT_SYNC()
{
    return H_Fade_IsFadeOutDone() != false;
}

// FUN_001c26c0
u32 K_Cmd_GET_MONTH()
{
    scrSetIntReturnVal(clndGetCurrentMonth());

    return true;
}

// FUN_001c26f0
u32 K_Cmd_GET_DAY()
{
    scrSetIntReturnVal(clndGetCurrentDay());

    return true;
}

// FUN_001c2720
u32 K_Cmd_GET_DAY_OF_WEEK()
{
    scrSetIntReturnVal(clndGetCurrentWeekDay());

    return true;
}

// FUN_001c2750
u32 K_Cmd_GET_TIME()
{
    scrSetIntReturnVal(datGetTime());

    return true;
}

// FUN_001c2780
u32 K_Cmd_DATE_IN_RANGE()
{
    u32 startMonth;
    u32 startDay;
    u32 endMonth;
    u32 endDay;

    startMonth = scrGetIntPara(0);
    startDay = scrGetIntPara(1);
    endMonth = scrGetIntPara(2);
    endDay = scrGetIntPara(3);

    if (clndIsDateInRange(startMonth, startDay, endMonth, endDay) == 1)
    {
        scrSetIntReturnVal(1);
    }
    else
    {
        scrSetIntReturnVal(0);
    }

    return true;
}

void FUN_00103cb0();

// FUN_001c28d0
u32 K_Cmd_001c28d0()
{
    FUN_00103cb0();

    return true;
}

// FUN_001c2900
u32 K_Cmd_RESRC_MDL_ANIM()
{
    s32 resTypeId;
    s32 animId;
    s32 shouldLoop;
    s32 blendFrameCount;
    f32 animSpeed;
    ResrcModelChar* character;
    ResrcModelNpc* npc;
    ResrcModelFld* fld;

    resTypeId = scrGetIntPara(0);
    animId = scrGetIntPara(1);
    shouldLoop = scrGetIntPara(2);
    blendFrameCount = scrGetFloatPara(3); // this shouldn't be scrGetFloatPara
    animSpeed = scrGetFloatPara(4);

    switch (RESRC_GET_TYPE(resTypeId))
    {
        case RESRC_TYPE_MODELCHAR:
            character = (ResrcModelChar*)MT_Scene_GetRes(resTypeId);
            if (character != NULL)
            {
                if (shouldLoop)
                {
                    mdlAnimSet(character->mdl, 0, animId, blendFrameCount, MDLANIM_FLAG_LOOP);
                }
                else
                {
                    mdlAnimSet(character->mdl, 0, animId, blendFrameCount, 0);
                }

                mdlAnimSetSpeed(character->mdl, 0, animSpeed);
            }
            break;
            
        case RESRC_TYPE_MODELNPC:
            npc = (ResrcModelNpc*)MT_Scene_GetRes(resTypeId);
            if (npc != NULL)
            {
                if (shouldLoop)
                {
                    mdlAnimSet(npc->mdl, 0, animId, blendFrameCount, MDLANIM_FLAG_LOOP);
                }
                else
                {
                    mdlAnimSet(npc->mdl, 0, animId, blendFrameCount, 0);
                }

                mdlAnimSetSpeed(npc->mdl, 0, animSpeed);
            }
            break;

        case RESRC_TYPE_MODELFLD:
            fld = (ResrcModelFld*)MT_Scene_GetRes(resTypeId);
            if (fld != NULL)
            {
                if (shouldLoop)
                {
                    mdlAnimSet(fld->mdl, 0, animId, blendFrameCount, MDLANIM_FLAG_LOOP);
                }
                else
                {
                    mdlAnimSet(fld->mdl, 0, animId, blendFrameCount, 0);
                }

                mdlAnimSetSpeed(fld->mdl, 0, animSpeed);
            }
            break;
        
        default: K_ASSERT(false, 527);
    }

    return true;
}

// FUN_001c2b80
u32 K_Cmd_RESRC_MDL_ANIM_SYNC()
{
    s32 resTypeId;
    Resrc* res;

    resTypeId = scrGetIntPara(0);
    switch (RESRC_GET_TYPE(resTypeId))
    {
        case RESRC_TYPE_MODELCHAR:
            res = MT_Scene_GetRes(resTypeId);
            if (res != NULL)
            {
                return ((ResrcModelChar*)res)->mdl->animSlots[0].anim.isAnimEnd == true;
            }
            break;
            
        case RESRC_TYPE_MODELNPC:
            res = MT_Scene_GetRes(resTypeId);
            if (res != NULL)
            {
                return ((ResrcModelNpc*)res)->mdl->animSlots[0].anim.isAnimEnd == true;
            }
            break;

        case RESRC_TYPE_MODELFLD:
            res = MT_Scene_GetRes(resTypeId);
            if (res != NULL)
            {
                return ((ResrcModelFld*)res)->mdl->animSlots[0].anim.isAnimEnd == true;
            }
            break;
        
        default: K_ASSERT(false, 577);
    }

    return true;
}

// FUN_001c2c80
u32 K_Cmd_RESRC_MODEL_SCALE()
{
    s32 resTypeId;
    RwV3d scale;
    Resrc* res;

    resTypeId = scrGetIntPara(0);
    scale.x = scrGetFloatPara(1);
    scale.y = scrGetFloatPara(1);
    scale.z = scrGetFloatPara(1);

    switch (RESRC_GET_TYPE(resTypeId))
    {
        case RESRC_TYPE_MODELCHAR:
            res = MT_Scene_GetRes(resTypeId);
            if (res != NULL)
            {
                mdlScale(((ResrcModelChar*)res)->mdl, &scale, rwCOMBINEPOSTCONCAT);
            }
            break;
        
        case RESRC_TYPE_MODELNPC:
            res = MT_Scene_GetRes(resTypeId);
            if (res != NULL)
            {
                mdlScale(((ResrcModelNpc*)res)->mdl, &scale, rwCOMBINEPOSTCONCAT);
            }
            break;
        
        case RESRC_TYPE_MODELFLD:
            res = MT_Scene_GetRes(resTypeId);
            if (res != NULL)
            {
                mdlScale(((ResrcModelFld*)res)->mdl, &scale, rwCOMBINEPOSTCONCAT);
            }
            break;

        default: K_ASSERT(false, 623);
    }

    return true;
}

// FUN_001c2ea0
u32 K_Cmd_GET_DUNGEON_FLOOR()
{
    scrSetIntReturnVal(K_FldDungeon_GetCurrentFloor());

    return true;
}

// FUN_001c2ed0
u32 K_Cmd_001c2ed0()
{
    scrSetIntReturnVal(datGetLevel(scrGetIntPara(0)));

    return true;
}

// FUN_001c2fa0
u32 K_Cmd_001c2fa0()
{
    scrSetIntReturnVal(datGetHp(scrGetIntPara(0)));

    return true;
}

// FUN_001c30a0
u32 K_Cmd_001c30a0()
{
    scrSetIntReturnVal(datGetSp(scrGetIntPara(0)));

    return true;
}

// FUN_001c3370
u32 K_Cmd_001c3370()
{
    scrSetIntReturnVal(datGetFatigueCounter(scrGetIntPara(0)));

    return true;
}

// FUN_001c33c0
u32 K_Cmd_001c33c0()
{
    scrSetIntReturnVal(datGetOldFatigueCounter(scrGetIntPara(0)));

    return true;
}

// FUN_001c3410
u32 K_Cmd_001c3410()
{
    scrSetIntReturnVal(datGetNextExp(scrGetIntPara(0)));

    return true;
}

// FUN_001c3460
u32 K_Cmd_001c3460()
{
    scrSetIntReturnVal(datGetPhysicalCondition(scrGetIntPara(0)));

    return true;
}

// FUN_001c3540
u32 K_Cmd_001c3540()
{
    scrSetIntReturnVal(datGetBadStatusNoDown(scrGetIntPara(0)));

    return true;
}

u32 FUN_001b9130();

// FUN_001c3790
u32 K_Cmd_001c3790()
{
    scrSetIntReturnVal(FUN_001b9130());

    return true;
}

void FUN_003c8f70();
void FUN_003c8f20();

// FUN_001c3dc0
u32 K_Cmd_001c3dc0()
{
    FUN_003c8f70();
    FUN_003c8f20();

    return true;
}

u32* FUN_0035f160();

// FUN_001c3f60
u32 K_Cmd_001c3f60()
{
    scrSetIntReturnVal(*FUN_0035f160());

    return true;
}

// FUN_001c3f90
u32 K_Cmd_001c3f90()
{
    s32 idx;
    u32* arr;

    idx = scrGetIntPara(0);
    arr = FUN_0035f160();
    scrSetIntReturnVal(arr[idx + 1]);

    return true;
}

u32 FUN_0016f380(u32 idx);

// FUN_001c3c40
u32 K_Cmd_001c3c40()
{
    scrSetIntReturnVal(FUN_0016f380(scrGetIntPara(0)));

    return true;
}

// FUN_001c3c80
u32 K_Cmd_001c3c80()
{
    FUN_0016f3e0(scrGetIntPara(0), scrGetIntPara(1));

    return true;
}

// FUN_001c45e0
u32 K_Cmd_CREATE_FLD_MDL()
{
    char path[64];
    char buff[64];
    s32 majorId;
    u32 minorId;
    Model* mdl;

    majorId = scrGetIntPara(0);
    minorId = scrGetIntPara(1);

    if (majorId > -1)
    {
        strcpy(path, "field/rmd/m");

        sprintf(buff, "%03d_", majorId);
        strcat(path, buff);

        sprintf(buff, "%03d.RMD", minorId);
        strcat(path, buff);
    }
    else
    {
        strcpy(path, "field/grmd/fobj");
        sprintf(buff, "%03d.RMD", minorId);
        strcat(path, buff);
    }

    mdl = mdlCreateFromPath(MODEL_TYPE_FLD,
                            minorId,
                            path,
                            MDL_READASYNC);
    scrSetIntReturnVal((s32)mdl);

    return true;
}

// FUN_001c4a00
u32 K_Cmd_CREATE_MDL()
{
    s32 type;
    s32 id;
    Model* mdl;

    type = scrGetIntPara(0);
    id = scrGetIntPara(1);

    mdl = mdlCreateAndResolvePath(type, id, MDL_READASYNC);

    scrSetIntReturnVal((s32)mdl);

    return true;
}

// FUN_001c4a60
u32 K_Cmd_CREATE_NPC_SYNC()
{
    Model* mdl;
    s32 resTypeId;
    u32 isNpcCreated;
    s32 param2;
    ResrcModelNpc* npc;

    mdl = (Model*)scrGetIntPara(0);
    param2 = scrGetIntPara(1);

    resTypeId = 0;
    isNpcCreated = false;

    if (mdlStreamRead(mdl) == true)
    {
        resTypeId = MT_Scene_CreateResModelNpc(
            K_Misc_FindNextFreeResId(RESRC_TYPE_MODELNPC), param2, mdl);

        npc = (ResrcModelNpc*)MT_Scene_GetRes(resTypeId);
        npc->baseMdl = mdlClone(gFldBaseMdl);

        isNpcCreated = true;
    }

    scrSetIntReturnVal(resTypeId);

    return isNpcCreated;
}

// FUN_001c4b30
u32 K_Cmd_RESRC_MDL_SET_COLLIS_RADIUS()
{
    s32 resTypeId;
    f32 sphereCollisRadius;
    ResrcModelChar* character;
    ResrcModelNpc* npc;
    RwV3d baseMdlScale;

    resTypeId = scrGetIntPara(0);
    sphereCollisRadius = scrGetFloatPara(1);

    switch (RESRC_GET_TYPE(resTypeId))
    {
        case RESRC_TYPE_MODELCHAR:
            character = (ResrcModelChar*)MT_Scene_GetRes(resTypeId);
            if (character != NULL)
            {
                K_FldFrame_CtlSetSphereCollisRadius(character->collisCtlTask, sphereCollisRadius);
            }
            break;

        case RESRC_TYPE_MODELNPC:
            npc = (ResrcModelNpc*)MT_Scene_GetRes(resTypeId);
            if (npc != NULL)
            {
                K_FldFrame_CtlSetSphereCollisRadius(npc->collisCtlTask, sphereCollisRadius);

                if (npc->baseMdl != NULL)
                {
                    baseMdlScale.z = sphereCollisRadius;
                    baseMdlScale.y = sphereCollisRadius;
                    baseMdlScale.x = sphereCollisRadius;

                    mdlScale(npc->baseMdl, &baseMdlScale, rwCOMBINEPOSTCONCAT);
                    mdl00317730(npc->baseMdl);
                }
            }
            break;

        default: K_ASSERT(false, 1598);
    }

    return true;
}

// FUN_001c5460
u32 K_Cmd_GET_BGM()
{
    scrSetIntReturnVal(H_Snd_GetCurrentBgmId());

    return true;
}

// FUN_001c54a0
u32 K_Cmd_PLAY_BGM()
{
    s16 currBgm;
    s32 reqBgm;

    currBgm = H_Snd_GetCurrentBgmId();

    if (currBgm != scrGetIntPara(0))
    {
        H_Snd_PlayBgm(scrGetIntPara(0), 1);
    }

    return true;
}

// FUN_001c5510
u32 K_Cmd_STOP_BGM_FADE()
{
    H_Snd_StopBgmFade(scrGetIntPara(0));

    return true;
}

u32 FUN_001c0040();

// FUN_001c5670
u32 K_Cmd_001c5670()
{
    scrSetIntReturnVal(FUN_001c0040());

    return true;
}

// FUN_001c56a0
u32 K_Cmd_GET_NPC_COUNT()
{
    ResrcModelNpc* npc;
    s32 count;

    npc = (ResrcModelNpc*)MT_Scene_GetResListHead(RESRC_TYPE_MODELNPC);
    count = 0;
    while (npc != NULL)
    {
        count++;
        npc = (ResrcModelNpc*)npc->base.next;
    }

    scrSetIntReturnVal(count);

    return true;
}

u8 clndGetCurrentMoonPhase();

// FUN_001c58d0
u32 K_Cmd_001c58d0()
{
    scrSetIntReturnVal(clndGetCurrentMoonPhase());

    return true;
}

// FUN_001c5e60
u32 K_Cmd_CHK_SCENARIO_ANSWER()
{
    s32 isAnswer;

    isAnswer = false;
    if (datGetScenarioMode() == SCENARIO_MODE_ANSWER)
    {
        isAnswer = true;
    }

    scrSetIntReturnVal(isAnswer);

    return true;
}
// FUN_001C2DD0 NONMATCHING
u32 K_Cmd_SET_NPC_SHADOW()
{
    s32 resTypeId;
    ResrcModelNpc* npc;

    resTypeId = scrGetIntPara(0);
    if (RESRC_GET_TYPE(resTypeId) == RESRC_TYPE_MODELNPC)
    {
        npc = (ResrcModelNpc*)MT_Scene_GetRes(resTypeId);
        if (npc != NULL && npc->renderTexShadowTask != NULL)
        {
            func_0019c320(npc->renderTexShadowTask,
                          scrGetFloatPara(1));
        }
    }
    else if (RESRC_GET_TYPE(resTypeId) != RESRC_TYPE_MODELCHAR &&
             RESRC_GET_TYPE(resTypeId) != RESRC_TYPE_MODELFLD)
    {
        K_ASSERT(false, 655);
    }

    return true;
}
// FUN_001C2500
u32 K_Cmd_SET_CALENDAR_SEQUENCE()
{
    s32 resourceId;

    resourceId = scrGetIntPara(0);
    func_001a0150((u16)resourceId, scrGetIntPara(1));
    return true;
}

// FUN_001C2830
u32 K_Cmd_SET_EVENT_CAMERA()
{
    s32 arg0;
    s32 arg1;
    s32 arg2;
    s32 arg3;

    arg0 = scrGetIntPara(0);
    arg1 = scrGetIntPara(1);
    arg2 = scrGetIntPara(2);
    arg3 = scrGetIntPara(3);
    func_00103c30((s16)arg0, (s16)arg1, (s16)arg2, (s16)arg3);
    return true;
}

// FUN_001C2F20
u32 K_Cmd_REVIVE_FROM_DOWN()
{
    s32 pcId;

    pcId = scrGetIntPara(0);
    if ((datGetBadStatusNoDown((s16)pcId) & 0x80000) != 0)
    {
        datSetHp((s16)pcId, 1);
        datClearBadStatus((s16)pcId, 0x80000);
    }

    return true;
}

// FUN_001C2FF0
u32 K_Cmd_SET_HP()
{
    s32 pcId;
    s32 hp;

    pcId = scrGetIntPara(0);
    hp = scrGetIntPara(1);
    datSetHp((s16)pcId, (s16)hp);
    return true;
}

// FUN_001C3050
u32 K_Cmd_GET_MAX_HP()
{
    extern u16 datGetMaxHp(s16 pcId);

    scrSetIntReturnVal(datGetMaxHp((s16)scrGetIntPara(0)));
    return true;
}

// FUN_001C30F0
u32 K_Cmd_SET_SP()
{
    s32 pcId;
    s32 sp;

    pcId = scrGetIntPara(0);
    sp = scrGetIntPara(1);
    datSetSp((s16)pcId, (s16)sp);
    return true;
}

// FUN_001C3150
u32 K_Cmd_GET_MAX_SP()
{
    s16 pcId;

    pcId = (s16)scrGetIntPara(0);
    scrSetIntReturnVal(func_0016c670(pcId));
    return true;
}

// FUN_001C31A0 NONMATCHING
u32 K_Cmd_GET_SOCIAL_STAT()
{
    s16 pcId;
    s32 stat;
    s16 value;

    pcId = (s16)scrGetIntPara(0);
    stat = scrGetIntPara(1);
    value = 0;
    if (stat == 0)
    {
        value = datGetAcademicPoint(pcId);
    }
    else if (stat == 1)
    {
        value = datGetCharmPoint(pcId);
    }
    else if (stat == 2)
    {
        value = datGetCouragePoint(pcId);
    }

    scrSetIntReturnVal(value);
    return true;
}

// FUN_001C3270 NONMATCHING
u32 K_Cmd_GET_SOCIAL_LEVEL()
{
    s16 pcId;
    s32 stat;
    s16 points;
    s16 value;

    pcId = (s16)scrGetIntPara(0);
    stat = scrGetIntPara(1);
    value = 0;
    if (stat == 0)
    {
        points = datGetAcademicPoint(pcId);
        value = datGetAcademicLevel(points);
    }
    else if (stat == 1)
    {
        points = datGetCharmPoint(pcId);
        value = datGetCharmLevel(points);
    }
    else if (stat == 2)
    {
        points = datGetCouragePoint(pcId);
        value = datGetCourageLevel(points);
    }

    scrSetIntReturnVal(value);
    return true;
}

// FUN_001C34B0 NONMATCHING
u32 K_Cmd_SET_PHYSICAL_CONDITION()
{
    s16 pcId;
    u16 condition;

    pcId = (s16)scrGetIntPara(0);
    condition = (u16)scrGetIntPara(1);
    scrSetIntReturnVal(datGetPhysicalCondition(pcId));
    datSetPhysicalCondition(pcId, condition);
    return true;
}

// FUN_001C3590 NONMATCHING
u32 K_Cmd_GET_FIELD_VALUE()
{
    scrSetIntReturnVal(func_00170760((s16)scrGetIntPara(0),
                                     (s16)scrGetIntPara(1)));
    return true;
}

// FUN_001C3600 NONMATCHING
u32 K_Cmd_SET_FIELD_VALUE()
{
    s16 pcId;
    s16 index;
    s32 value;

    pcId = (s16)scrGetIntPara(0);
    index = (s16)scrGetIntPara(1);
    value = scrGetIntPara(2);
    if (value > 99)
    {
        value = 99;
    }
    func_00170860(pcId, index, (u16)value);
    return true;
}

// FUN_001C3690 NONMATCHING
u32 K_Cmd_GET_EQUIPMENT_VALUE()
{
    s16 pcId;
    s16 equipmentType;
    s16 equipmentIndex;

    pcId = (s16)scrGetIntPara(0);
    equipmentType = (s16)scrGetIntPara(1);
    equipmentIndex = datGetEquipmentIdx(pcId, equipmentType);
    scrSetIntReturnVal(datGetEquipmentId(pcId, equipmentIndex));
    return true;
}

// FUN_001C3710
u32 K_Cmd_SET_EQUIPMENT_INDEX()
{
    s32 pcId;
    s32 equipmentType;
    s32 equipmentIndex;

    pcId = scrGetIntPara(0);
    equipmentType = scrGetIntPara(1);
    equipmentIndex = scrGetIntPara(2);
    datSetEquipmentIdx((s16)pcId, (s16)equipmentType, (s16)equipmentIndex);
    return true;
}

// FUN_001C37C0
u32 K_Cmd_SET_CAMERA_FOCUS()
{
    s32 value;

    value = scrGetIntPara(0);
    func_001d6270(NULL, scrGetIntPara(1), value);
    return true;
}

// FUN_001C3820
u32 K_Cmd_SET_CAMERA_HEADING()
{
    s32 value;

    value = scrGetIntPara(0);
    func_001d6630(NULL, scrGetIntPara(1), value);
    return true;
}

static inline u8* K_Cmd_GetCurrentFieldObject()
{
    return (u8*)(*(u32*)0x007ce284);
}

// FUN_001C3880 NONMATCHING
u32 K_Cmd_GET_FIELD_OBJECT_ID()
{
    u8* object;

    object = K_Cmd_GetCurrentFieldObject();
    scrSetIntReturnVal(object != NULL ? *(u16*)(object + 8) : 0);
    return true;
}

// FUN_001C38B0 NONMATCHING
u32 K_Cmd_GET_FIELD_OBJECT_KIND()
{
    u8* object;
    u8* work;
    u16 kind;

    object = K_Cmd_GetCurrentFieldObject();
    work = object != NULL ? *(u8**)(object + 0x11c) : NULL;
    kind = work != NULL ? *(u16*)(work + 2) : 0;
    if (kind == 0xfb5)
    {
        scrSetIntReturnVal(3);
    }
    else if (kind < 5000)
    {
        scrSetIntReturnVal(kind < 4000 ? 2 : 1);
    }
    else
    {
        scrSetIntReturnVal(0);
    }
    return true;
}

// FUN_001C3950 NONMATCHING
u32 K_Cmd_GET_FIELD_OBJECT_ACTIVE()
{
    u8* object;
    u8* work;

    object = K_Cmd_GetCurrentFieldObject();
    work = object != NULL ? *(u8**)(object + 0x11c) : NULL;
    scrSetIntReturnVal(work != NULL && (*(u8*)(work + 7) & 1) != 0);
    return true;
}

// FUN_001C3990 NONMATCHING
u32 K_Cmd_GET_FIELD_OBJECT_PARAM()
{
    u8* object;
    u8* work;
    u32 value;

    object = K_Cmd_GetCurrentFieldObject();
    work = object != NULL ? *(u8**)(object + 0x11c) : NULL;
    value = (work != NULL && *(u16*)(work + 2) == 0xfb5) ? *(u32*)(work + 8) : 0;
    scrSetIntReturnVal(value);
    return true;
}

// FUN_001C39E0 NONMATCHING
u32 K_Cmd_GET_FIELD_OBJECT_TYPE()
{
    u8* object;
    u8* work;

    object = K_Cmd_GetCurrentFieldObject();
    work = object != NULL ? *(u8**)(object + 0x11c) : NULL;
    scrSetIntReturnVal(work != NULL ? *(u16*)(work + 2) : 0);
    return true;
}

// FUN_001C3A10 NONMATCHING
u32 K_Cmd_GET_FIELD_OBJECT_VARIANT()
{
    u8* object;
    u8* work;
    u16 type;

    object = K_Cmd_GetCurrentFieldObject();
    work = object != NULL ? *(u8**)(object + 0x11c) : NULL;
    type = work != NULL ? *(u16*)(work + 2) : 0;
    scrSetIntReturnVal(type < 4000 && work != NULL ? *(u8*)(object + 0x128) : 0);
    return true;
}

// FUN_001C3A70 NONMATCHING
u32 K_Cmd_GET_FIELD_OBJECT_TYPE_COPY()
{
    u8* object;
    u8* work;

    object = K_Cmd_GetCurrentFieldObject();
    work = object != NULL ? *(u8**)(object + 0x11c) : NULL;
    scrSetIntReturnVal(work != NULL ? *(u16*)(work + 2) : 0);
    return true;
}

// FUN_001C3AA0 NONMATCHING
u32 K_Cmd_GET_FIELD_OBJECT_FLAG()
{
    u8* object;
    u8* work;

    object = K_Cmd_GetCurrentFieldObject();
    work = object != NULL ? *(u8**)(object + 0x11c) : NULL;
    scrSetIntReturnVal(work != NULL ? *(u8*)(work + 6) : 0);
    return true;
}

// FUN_001C3AD0 NONMATCHING
u32 K_Cmd_RESET_FIELD_OBJECT()
{
    func_001d22a0((void*)K_Cmd_GetCurrentFieldObject());
    return true;
}

// FUN_001C3B00 NONMATCHING
u32 K_Cmd_ADD_FIELD_OBJECT()
{
    u8* object;
    u16 type;
    s16 i;
    s16 slot;
    s16 value;

    object = K_Cmd_GetCurrentFieldObject();
    type = object != NULL && *(u8**)(object + 0x11c) != NULL
               ? *(u16*)(*(u8**)(object + 0x11c) + 2)
               : 0;
    if (type == 0xfb5)
    {
        scrSetIntReturnVal(1);
        return true;
    }
    if (type < 4000)
    {
        slot = 0;
        while (slot < 20 && datGetEquipmentId(-1, slot) != 0)
        {
            slot++;
        }
        if (slot >= 20)
        {
            K_ASSERT(false, 1061);
        }
        func_001831e0(-1, slot, object + 0x120);
        scrSetIntReturnVal(1);
        return true;
    }

    value = func_00170760(-1, (s16)type);
    i = object != NULL && *(u8**)(object + 0x11c) != NULL
            ? *(u8*)(*(u8**)(object + 0x11c) + 6)
            : 0;
    value = (s16)(value + i);
    if (value > 99)
    {
        value = 99;
    }
    func_00170860(-1, (s16)type, (u16)value);
    scrSetIntReturnVal(1);
    return true;
}
 
// FUN_001C3CD0
u32 FUN_001C3CD0()
{
    s32 resourceId;
    s32 value;
    ScrData* script;

    resourceId = scrGetIntPara(0);
    value = scrGetIntPara(1);
    func_003c8da0(1);
    script = scrGetCurrent();
    func_003c8dd0(script->msgContentHeader);
    func_003c8de0(resourceId, value, 0, 0);

    return true;
}

// FUN_001C3D60
u32 FUN_001C3D60()
{
    s32 resourceId;
    s32 value;

    resourceId = scrGetIntPara(0);
    value = scrGetIntPara(1);

    return func_003c8ec0(resourceId, value) == 0;
}

// FUN_001C3DF0 NONMATCHING
u32 FUN_001C3DF0()
{
    Field* field;
    s32 enable;
    KwlnTask* eventTask;

    enable = scrGetIntPara(0);
    field = K_Field_Get();
    eventTask = *(KwlnTask**)((u8*)field + 0x18);
    if (enable == 0)
    {
        if (eventTask != NULL)
        {
            func_00429e80(eventTask, 0);
        }
        *(u32*)((u8*)field + 0x14) = 1;
    }
    else
    {
        if (eventTask != NULL)
        {
            func_00429e80(eventTask, 1);
        }
        *(u32*)((u8*)field + 0x14) = 0;
    }

    return true;
}

// FUN_001C3EB0
u32 FUN_001C3EB0()
{
    s32 value;

    value = scrGetIntPara(0);
    if (value == 0)
    {
        func_00434e60();
    }
    else
    {
        func_00434d30();
    }
    scrSetIntReturnVal(value);

    return true;
}

// FUN_001C3F10
u32 FUN_001C3F10()
{
    s32 value;

    value = scrGetIntPara(0);
    func_00435370((s8)value);
    scrSetIntReturnVal(value);

    return true;
}

// FUN_001C3FE0 NONMATCHING
u32 FUN_001C3FE0()
{
    s32 value;
    u32* values;
    s32 i;
    u32 found;

    value = scrGetIntPara(0);
    values = FUN_0035f160();
    found = 0;
    for (i = 0; i < (s32)values[0]; i++)
    {
        if (values[i + 1] == (u32)value)
        {
            found = 1;
            break;
        }
    }
    scrSetIntReturnVal((s32)found);

    return true;
}

// FUN_001C4080 NONMATCHING
u32 FUN_001C4080()
{
    s32 index;
    u8* entry;
    u32 result;
    u32 second;

    index = scrGetIntPara(0);
    entry = D_008717E8 + (index * 0x1c0);
    result = 0;
    second = *(u32*)(D_008717F4 + (index * 0x1c0));
    if (*(u32*)entry != 0 && second != 0)
    {
        result = *(u16*)second;
    }
    scrSetIntReturnVal((s32)result);

    return true;
}

// FUN_001C4120 NONMATCHING
u32 FUN_001C4120()
{
    s32 resourceTypeId;
    s32 mode;
    Resrc* hit;
    Resrc* resource;
    Model* model;
    RwMatrix* matrix;
    RwV3d oldPosition;
    RwV3d inversePosition;
    RwV3d targetPosition;
    RwV3d axis;
    RwV3d scale;
    RwMatrixTolerance tolerance;
    f32 angle;
    u32 type;

    resourceTypeId = scrGetIntPara(0);
    mode = scrGetIntPara(1);
    hit = MT_Scene_GetResListHead(RESRC_TYPE_14);
    while (hit != NULL && RESRC_GET_ID(hit->resTypeId) != RESRC_GET_ID(mode))
    {
        hit = hit->next;
    }
    K_ASSERT(hit != NULL, 1292);

    type = RESRC_GET_TYPE(resourceTypeId);
    axis = D_00683670;
    targetPosition.x = *(f32*)((u8*)hit + 0x100);
    targetPosition.y = *(f32*)((u8*)hit + 0x104);
    targetPosition.z = *(f32*)((u8*)hit + 0x108);
    angle = *(f32*)((u8*)hit + 0x10c);

    if (type == RESRC_TYPE_MODELCHAR)
    {
        resource = MT_Scene_GetRes((u16)resourceTypeId);
        if (resource != NULL)
        {
            model = ((ResrcModelChar*)resource)->mdl;
            matrix = mdlGetMatrix(model);
            oldPosition = matrix->pos;
            inversePosition.x = -oldPosition.x;
            inversePosition.y = -oldPosition.y;
            inversePosition.z = -oldPosition.z;
            mdlTranslate(model, &inversePosition, rwCOMBINEPOSTCONCAT);
            mdlRotate(model, &axis, angle, rwCOMBINEREPLACE);
            mdlTranslate(model, &targetPosition, rwCOMBINEPOSTCONCAT);
            matrix = mdlGetMatrix(model);
            matrix->pos = targetPosition;
            RwEngineGetMatrixTolerances(&tolerance);
            RwMatrixOptimize(matrix, &tolerance);
            RwMatrixUpdate(matrix);
        }
    }
    else if (type == RESRC_TYPE_MODELNPC)
    {
        ResrcModelNpc* npc;

        resource = MT_Scene_GetRes((u16)resourceTypeId);
        if (resource != NULL)
        {
            npc = (ResrcModelNpc*)resource;
            model = npc->mdl;
            matrix = mdlGetMatrix(model);
            oldPosition = matrix->pos;
            inversePosition.x = -oldPosition.x;
            inversePosition.y = -oldPosition.y;
            inversePosition.z = -oldPosition.z;
            mdlTranslate(model, &inversePosition, rwCOMBINEPOSTCONCAT);
            mdlRotate(model, &axis, angle, rwCOMBINEPOSTCONCAT);
            mdlTranslate(model, &targetPosition, rwCOMBINEPOSTCONCAT);
            matrix = mdlGetMatrix(model);
            matrix->pos = targetPosition;
            RwEngineGetMatrixTolerances(&tolerance);
            RwMatrixOptimize(matrix, &tolerance);
            RwMatrixUpdate(matrix);

            if (npc->baseMdl != NULL)
            {
                scale.x = K_FldFrame_CtlGetSphereCollisRadius(npc->collisCtlTask);
                scale.y = scale.x;
                scale.z = scale.x;
                mdlRotate(npc->baseMdl, &axis, angle, rwCOMBINEPOSTCONCAT);
                mdlScale(npc->baseMdl, &scale, rwCOMBINEPOSTCONCAT);
                mdlTranslate(npc->baseMdl, &targetPosition, rwCOMBINEPOSTCONCAT);
                mdl00317730(npc->baseMdl);
            }
        }
    }
    else if (type == RESRC_TYPE_MODELFLD)
    {
        resource = MT_Scene_GetRes((u16)resourceTypeId);
        if (resource != NULL)
        {
            model = ((ResrcModelFld*)resource)->mdl;
            matrix = mdlGetMatrix(model);
            oldPosition = matrix->pos;
            inversePosition.x = -oldPosition.x;
            inversePosition.y = -oldPosition.y;
            inversePosition.z = -oldPosition.z;
            mdlTranslate(model, &inversePosition, rwCOMBINEPOSTCONCAT);
            mdlRotate(model, &axis, angle, rwCOMBINEREPLACE);
            mdlTranslate(model, &targetPosition, rwCOMBINEPOSTCONCAT);
            matrix = mdlGetMatrix(model);
            matrix->pos = targetPosition;
            RwEngineGetMatrixTolerances(&tolerance);
            RwMatrixOptimize(matrix, &tolerance);
            RwMatrixUpdate(matrix);
        }
    }
    else
    {
        K_ASSERT(false, 1389);
    }

    return true;
}

// FUN_001C4700 NONMATCHING
u32 FUN_001C4700()
{
    Model* model;
    s32 resourceId;
    u16 resTypeId;
    u16 createdId;
    u32 hasOverlay;
    u32 overlayResource;
    Field* field;
    RwMatrix* matrix;
    f32 angles[3];
    u32 result;

    model = (Model*)scrGetIntPara(0);
    resourceId = scrGetIntPara(1);
    resTypeId = (u16)resourceId;
    hasOverlay = 0;
    result = 0;

    if (mdlStreamRead(model) == false)
    {
        scrSetIntReturnVal(0);
        return false;
    }

    if (MT_Scene_GetRes(RESRC_MAKE_TYPEID(resTypeId, RESRC_TYPE_MODELFLD)) != NULL)
    {
        mdlDestroy(model);
        scrSetIntReturnVal(0);
        return true;
    }

    createdId = MT_Scene_CreateResModelFld(resTypeId, model);
    field = K_Field_Get();
    if (*(u32*)((u8*)field + 0x1168) > 0)
    {
        result = FUN_001b32f0(*(u32*)((u8*)field + 0x116c),
                              (u32)resourceId,
                              &hasOverlay);
    }

    if (result != 0)
    {
        matrix = func_004cb2f0((void*)result);
        angles[0] = func_001a5b30(matrix);
        angles[1] = func_001a5aa0(matrix);
        angles[2] = func_001a5bc0(matrix);
        func_003b78b0(createdId, &matrix->pos, angles);
        mdl00318a70();
        func_00319230(model, 3);
        mdlAnimSet(model, 0, 0, 8, MDLANIM_FLAG_LOOP);
    }

    if (hasOverlay == 1)
    {
        overlayResource = (u32)MT_Scene_GetRes(createdId);
        if (overlayResource != 0)
        {
            *(u32*)(overlayResource + 0x110) = 1;
        }
    }
    scrSetIntReturnVal(createdId);

    return true;
}

// FUN_001C48F0
u32 FUN_001C48F0()
{
    Model* model;
    u32 resourceId;
    u32 created;

    model = (Model*)scrGetIntPara(0);
    resourceId = 0;
    created = 0;
    if (mdlStreamRead(model) == true)
    {
        resourceId = (u16)MT_Scene_CreateResModelFld(
            K_Misc_FindNextFreeResId(RESRC_TYPE_MODELFLD), model);
        created = 1;
    }
    scrSetIntReturnVal(resourceId);

    return created;
}
/* Late field-command helpers use the same typed script/resource APIs as the command table. */
extern void* func_00177a40(u16 type, s32 slot);
extern void* func_00177a90(u16 type, s32 slot);
extern void func_00177b50(s32 value, s32 slot);
extern void* func_00177ca0(u16 type, s32 slot);
extern DatEquipment* func_0016fdb0(s16 pcId, s32 equipmentIdx);
extern KwlnTask* func_001dc910(s32 mode, s32 value);
extern void func_003bb010(u16 resourceId, u8 value);
extern u8 func_0010a370(s16 channelIndex, const char* name);
extern void func_00455b50(void);
extern void Y_TimeLimit_Stop(void);

/* These are the retail GP-backed command state words.  They are shared with the
 * field script task and must not be duplicated as TU-local state. */
#define K_CMD_GLOBAL_STATE      (*(u32*)0x007CE278)
#define K_CMD_GLOBAL_STAGE      (*(u32*)0x007CE274)
#define K_CMD_GLOBAL_FRAME      (*(u32*)0x007CE270)


// FUN_001c4990
u32 func_001c4990()
{
    s32 resourceId;
    s32 value;
    Resrc* resource;

    resourceId = scrGetIntPara(0);
    value = scrGetIntPara(1);
    resource = MT_Scene_GetRes((u16)resourceId);
    if (resource != NULL)
    {
        *(u32*)((u8*)resource + 0x110) = (u32)value;
    }

    return true;
}

// FUN_001c4c50 NONMATCHING
u32 func_001c4c50()
{
    ScrData* current;
    KwlnTask* task;
    s32 value;

    current = scrGetCurrent();
    task = (KwlnTask*)(u32)scrGetUnkF0();
    value = scrGetIntPara(0);

    if (task == NULL)
    {
        task = func_001dc910(0, value);
        func_0035c1a0(current->task, (s32)(u32)task);
        return false;
    }

    if (kwlnTaskExists(task) == true)
    {
        return false;
    }

    func_0035c1a0(current->task, 0);
    return true;
}

// FUN_001c4d10 NONMATCHING
u32 func_001c4d10()
{
    u32 result;

    result = func_00177a40((u16)scrGetIntPara(0), scrGetIntPara(1)) != NULL;
    scrSetIntReturnVal((s32)result);
    return true;
}

// FUN_001c4d90
u32 func_001c4d90()
{
    void* item;

    item = func_00177a90((u16)scrGetIntPara(0), scrGetIntPara(1));
    scrSetIntReturnVal(*(u8*)((u8*)item + 8));
    return true;
}

// FUN_001c4df0
u32 func_001c4df0()
{
    void* item;

    item = func_00177a90((u16)scrGetIntPara(0), scrGetIntPara(1));
    scrSetIntReturnVal(*(u16*)item);
    return true;
}

// FUN_001c4e50 NONMATCHING
u32 func_001c4e50()
{
    s32 itemIndex;
    s32 slot;
    s32 freeSlot;
    void* item;
    s32 value;

    for (itemIndex = 0; itemIndex < 4; itemIndex++)
    {
        if (func_00177a40((u16)scrGetIntPara(0), itemIndex) == NULL)
        {
            continue;
        }

        item = func_00177a90((u16)scrGetIntPara(0), itemIndex);
        freeSlot = 0;
        while (freeSlot < 20 && datGetEquipmentId(-1, freeSlot) != 0)
        {
            freeSlot++;
        }
        if (freeSlot >= 20)
        {
            K_ASSERT(false, 1682);
            freeSlot = 19;
        }
        func_001831e0(-1, (s16)freeSlot, item);
        value = scrGetIntPara(0);
        func_00177b50(value, itemIndex);
    }

    return true;
}

// FUN_001c4f70
u32 func_001c4f70()
{
    s32 count;
    s32 slot;
    s32 equipmentIndex;

    count = 0;
    for (slot = 0; slot < 4; slot++)
    {
        if (func_00177a40(9, slot) != NULL)
        {
            count++;
        }
    }
    for (slot = 0; slot < 4; slot++)
    {
        equipmentIndex = datGetEquipmentIdx(9, (s16)slot);
        if (func_00177ca0(9, equipmentIndex) != NULL)
        {
            count++;
        }
    }
    scrSetIntReturnVal(count);
    return true;
}

// FUN_001c5040 NONMATCHING
u32 func_001c5040()
{
    s32 requested;
    s32 slot;
    s32 found;
    s32 count;
    s32 equipmentIndex;
    void* item;

    requested = scrGetIntPara(0);
    found = 0;
    count = 0;
    for (slot = 0; slot < 4; slot++)
    {
        item = func_00177a40(9, slot);
        if (item != NULL)
        {
            if (count == requested)
            {
                found = *(u16*)func_00177a90(9, slot);
            }
            count++;
        }
    }

    for (slot = 0; slot < 4; slot++)
    {
        equipmentIndex = datGetEquipmentIdx(9, (s16)slot);
        if (func_00177ca0(9, equipmentIndex) != NULL)
        {
            if (count == requested)
            {
                found = datGetEquipmentId(9, equipmentIndex);
            }
            count++;
        }
    }

    scrSetIntReturnVal(found);
    return true;
}

// FUN_001c5180 NONMATCHING
u32 func_001c5180()
{
    s32 slot;
    s32 freeSlot;
    s32 equipmentIndex;
    void* item;

    for (slot = 0; slot < 4; slot++)
    {
        if (func_00177a40(9, slot) == NULL)
        {
            continue;
        }

        item = func_00177a90(9, slot);
        freeSlot = 0;
        while (freeSlot < 20 && datGetEquipmentId(-1, freeSlot) != 0)
        {
            freeSlot++;
        }
        if (freeSlot >= 20)
        {
            K_ASSERT(false, 1779);
            freeSlot = 19;
        }
        func_001831e0(-1, (s16)freeSlot, item);
    }

    for (slot = 0; slot < 4; slot++)
    {
        equipmentIndex = datGetEquipmentIdx(9, (s16)slot);
        if (func_00177ca0(9, equipmentIndex) == NULL)
        {
            continue;
        }
        item = func_0016fdb0(9, equipmentIndex);

        freeSlot = 0;
        while (freeSlot < 20 && datGetEquipmentId(-1, freeSlot) != 0)
        {
            freeSlot++;
        }
        if (freeSlot >= 20)
        {
            K_ASSERT(false, 1799);
            freeSlot = 19;
        }
        func_001831e0(-1, (s16)freeSlot, item);
    }

    return true;
}

// FUN_001c5340 NONMATCHING
u32 func_001c5340()
{
    s32 command;
    s32 mode;
    s32 mappedMode;

    mode = scrGetIntPara(1);
    command = scrGetIntPara(0);
    mappedMode = 0;
    if (command == 1)
    {
        mappedMode = 1;
    }
    else if (command == 2)
    {
        mappedMode = 6;
    }
    else if (command == 3)
    {
        mappedMode = 7;
    }
    func_0010a4e0(0, mappedMode, command, mode);
    return true;
}

// FUN_001c5400 NONMATCHING
u32 func_001c5400()
{
    s32 command;
    s32 mode;

    mode = scrGetIntPara(1);
    command = scrGetIntPara(0);
    func_0010a4e0(1, 8, command, mode);
    return true;
}

// FUN_001c5550 NONMATCHING
u32 func_001c5550()
{
    func_00109040((s16)scrGetIntPara(0));
    (void)scrGetIntPara(1);
    return true;
}

// FUN_001c55b0
u32 func_001c55b0()
{
    s32 index;
    const char* name;

    index = scrGetIntPara(0);
    name = DAT_0067F040[index];
    func_0010a370(4, name);
    return true;
}

// FUN_001c5600 NONMATCHING
u32 func_001c5600()
{
    s32 index;

    index = scrGetIntPara(0) + 1;
    scrSetIntReturnVal(func_0043a230(index) != false);
    return true;
}

// FUN_001c5700 NONMATCHING
u32 func_001c5700()
{
    s32 index;
    s32 i;
    u8* resource;
    Model* model;
    s32 floor;

    index = scrGetIntPara(0);
    resource = (u8*)MT_Scene_GetResListHead(RESRC_TYPE_MODELNPC);
    for (i = 0; i < index && resource != NULL; i++)
    {
        resource = *(u8**)(resource + 0xF8);
    }

    floor = 0;
    if (resource != NULL)
    {
        model = *(Model**)(resource + 0x128);
        if (model != NULL)
        {
            floor = model->id / 50 + 1;
            if (model->id >= 501)
            {
                floor = 0;
            }
        }
    }
    scrSetIntReturnVal(floor);
    return true;
}

// FUN_001c57b0 NONMATCHING
u32 func_001c57b0()
{
    u16* skills;
    s32 skillIndex;
    u32 found;
    u16 skillId;

    skills = datPersonaGetSkillsByPcId((u16)scrGetIntPara(0));
    found = false;
    for (skillIndex = 0; skillIndex < 8; skillIndex++)
    {
        skillId = skills != NULL ? skills[skillIndex] : 0;
        if (skillId != 0 && skillId == (u16)scrGetIntPara(1))
        {
            found = true;
            break;
        }
    }
    scrSetIntReturnVal(found);
    return true;
}

// FUN_001c5870 NONMATCHING
u32 func_001c5870()
{
    u16 resourceId;
    s32 value;

    resourceId = (u16)(scrGetIntPara(0) & 0x3FF) | 0x400;
    value = scrGetIntPara(1);
    func_003bb010(resourceId, (u8)value);
    return true;
}

// FUN_001c5900 NONMATCHING
u32 func_001c5900()
{
    u8* field;
    KwlnTask* task;

    (void)scrGetIntPara(0);
    func_001d1860(1);
    func_001d1910();
    func_001d1b60();
    func_001d4180();

    field = (u8*)K_Field_Get();
    task = *(KwlnTask**)(field + 0x1200);
    if (task != NULL)
    {
        func_001a9470(task);
    }
    K_CMD_GLOBAL_STATE = 0;
    return true;
}

// FUN_001c5980 NONMATCHING
u32 func_001c5980()
{
    s32 requestedId;
    u32 state;
    s32 slot;
    FldUnit* unit;
    Model* model;
    u32 valid;
    s32 weapon;
    MtScene* scene;

    requestedId = scrGetIntPara(0);
    state = K_CMD_GLOBAL_STATE;

    if (state == 0)
    {
        if (func_001d1a90() == false ||
            func_001d1ce0() == false ||
            func_001d00b0() == false)
        {
            return false;
        }

        func_00455b50();
        slot = 1;
        while (slot < 4)
        {
            unit = &gFldUnitsPc[slot];
            if (unit->genusBase != NULL &&
                unit->resrc != NULL &&
                unit->charId == (u16)requestedId)
            {
                break;
            }
            slot++;
        }

        func_001d1780(0);
        func_001d17f0(0);
        if (slot < 4)
        {
            K_FldUnit_DestroyPcMdl(slot);
            func_004c43b0();
            unit->mdl = (Model*)func_001cd9a0(requestedId);
        }
        K_CMD_GLOBAL_STATE++;
        return false;
    }

    if (state == 1)
    {
        slot = 0;
        while (slot < 4)
        {
            unit = &gFldUnitsPc[slot];
            if (unit->genusBase != NULL &&
                unit->charId == (u16)requestedId)
            {
                break;
            }
            slot++;
        }

        if (slot < 4)
        {
            model = unit->mdl;
            if (mdlStreamRead(model) == false)
            {
                return false;
            }
            valid = true;
            for (weapon = 0; weapon < 5; weapon++)
            {
                if (mdl00319770(unit->mdl, (u16)weapon) == false)
                {
                    valid = false;
                    break;
                }
            }
            if (!valid)
            {
                return false;
            }
        }

        gFldUnitsPc[0].unk_180 = func_001d40e0(NULL, &gFldUnitsPc[0]);
        func_001d0e50(0);
        func_001d19d0();
        func_001d1360();
        func_001d1c20();
        func_001d1860(0);
        K_CMD_GLOBAL_STATE++;
        return false;
    }

    if (state == 2)
    {
        if (func_001d1a90() == false ||
            func_001d1ce0() == false)
        {
            return false;
        }
        func_001d8c60(1);
    }

    scene = gMtScene;
    if (((scene->fldMajorId == 0x20) && (scene->fldMinorId == 2)) ||
        ((scene->fldMajorId == 0x27) && (scene->fldMinorId == 1)) ||
        ((scene->fldMajorId == 0x27) && (scene->fldMinorId == 3)))
    {
        func_0030c440();
    }
    return true;
}

// FUN_001c5d30 NONMATCHING
u32 func_001c5d30()
{
    K_CMD_GLOBAL_STAGE = 0;
    K_CMD_GLOBAL_FRAME = 0;
    if (func_0045af40() == false)
    {
        func_003952d0(0, 0x87, 3);
        K_CMD_GLOBAL_STAGE = 1;
    }
    return true;
}

// FUN_001c5d80 NONMATCHING
u32 func_001c5d80()
{
    if (K_CMD_GLOBAL_STAGE == 1)
    {
        if (K_CMD_GLOBAL_FRAME < 0x5A)
        {
            Y_TimeLimit_Stop();
            datSetFlag(0x141D, true);
            K_CMD_GLOBAL_FRAME++;
            scrSetIntReturnVal(0);
            return false;
        }

        if (H_Fade_IsFadeOutDone() == false)
        {
            scrSetIntReturnVal(0);
            return false;
        }

        scrCreateTaskFromScriptMemory(10, gFldScrMemory, gFldScrSize, 1);
        scrSetIntReturnVal(2);
        return true;
    }

    scrSetIntReturnVal(1);
    return true;
}

// FUN_001c5eb0
u32 func_001c5eb0()
{
    func_0027d8d0();
    return true;
}