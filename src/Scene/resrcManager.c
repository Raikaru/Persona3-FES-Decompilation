#include "Scene/resrcManager.h"
#include "Main/g_data.h"
#include "Graphics/Model/mdlManager.h"
#include "rw/rwplcore.h"
#include "temporary.h"
#include "Kosaka/k_assert.h"

#pragma alias resrcMngCreateRes_y2 resrcMngCreateRes


// FUN_003b4fc0
ResrcManager* resrcMngCreate()
{
    ResrcManager* resMgr;

    resMgr = RwMalloc(sizeof(ResrcManager), rwMEMHINTDUR_GLOBAL);
    memset(resMgr, 0, sizeof(ResrcManager));
    
    return resMgr;
}

// FUN_003b5020
void resrcMngDestroy(ResrcManager* resManager)
{
    s32 i;
    Resrc* currList;

    if (resManager != NULL)
    {
        for (i = 0; i < RESRC_TYPE_MAX; i++)
        {
            currList = resrcMngGetListHead(resManager, i);

            while (currList != NULL)
            {
                resrcMngDestroyRes(resManager, currList);

                currList = resrcMngGetListHead(resManager, i);
            }
        }

        RwFree(resManager);
    }
}

// FUN_003b50d0
Resrc* resrcMngCreateRes(ResrcManager* resManager, u16 resTypeId)
{
    Resrc* res;
    Resrc* currRes;
    Resrc* listHead;
    u32 resSize;
    u16 resId;
    s32 resType;

    resId = resTypeId & 0xffff;
    resType = RESRC_GET_TYPE(resId);
    resSize = 0;
    if (resType >= RESRC_TYPE_MAX)
    {
        printf("warning!! not known resrc!! %s\n", __FILE__);
        return NULL;
    }

    switch (resType)
    {
    case RESRC_TYPE_MODELCHAR:
        resSize = sizeof(ResrcModelChar);
        break;
    case RESRC_TYPE_MODELUNK:
        resSize = 0x1d0;
        break;
    case RESRC_TYPE_MODELNPC:
        resSize = sizeof(ResrcModelNpc);
        break;
    case RESRC_TYPE_LIGHTCHAR:
        resSize = sizeof(ResrcLightChar);
        break;
    case RESRC_TYPE_LIGHTNPC:
        resSize = sizeof(ResrcLightNpc);
        break;
    case RESRC_TYPE_06:
        resSize = 0x108;
        break;
    case RESRC_TYPE_07:
        resSize = 0x110;
        break;
    case RESRC_TYPE_08:
        resSize = sizeof(Resrc);
        break;
    case RESRC_TYPE_MODELFLD:
        resSize = sizeof(ResrcModelFld);
        break;
    case RESRC_TYPE_11:
        resSize = 0x108;
        break;
    case RESRC_TYPE_FLD:
        resSize = sizeof(ResrcFld);
        break;
    case RESRC_TYPE_FLDHIT:
    case RESRC_TYPE_21:
        resSize = 0x150;
        break;
    case RESRC_TYPE_14:
    case RESRC_TYPE_15:
    case RESRC_TYPE_16:
    case RESRC_TYPE_17:
    case RESRC_TYPE_18:
    case RESRC_TYPE_19:
        resSize = 0x110;
        break;
    case RESRC_TYPE_20:
        resSize = 0x120;
        break;
    }

    if (resSize == 0)
    {
        return NULL;
    }

    res = RwMalloc(resSize, rwMEMHINTDUR_GLOBAL);
    memset(res, 0, resSize);
    res->resTypeId = resTypeId;
    res->unk_24 = 1.0f;
    res->unk_20 = 1.0f;
    res->unk_1c = 1.0f;

    currRes = resManager->resLists[resType];
    for (listHead = currRes; listHead != NULL; listHead = listHead->next)
    {
        if (listHead->resTypeId == resId)
        {
            RwFree(res);
            printf("warning!! duplicate resID!! not regist!%s\n", __FILE__);
            K_ASSERT(false, 0xa8);
            return NULL;
        }
    }

    if (currRes != NULL)
    {
        while (currRes->next != NULL)
        {
            currRes = currRes->next;
        }

        currRes->next = res;
        res->prev = currRes;
        res->next = NULL;
    }
    else
    {
        resManager->resLists[resType] = res;
        res->next = NULL;
        res->prev = NULL;
    }

    return res;
}

// FUN_003b5360
void resrcMngDestroyRes(ResrcManager* resManager, Resrc* res)
{
    Resrc* currRes;
    Resrc* prevRes;
    Resrc* nextRes;

    currRes = resManager->resLists[RESRC_GET_TYPE(res->resTypeId)];
    while (currRes != NULL)
    {
        if (res == currRes)
        {
            prevRes = currRes->prev;
            nextRes = currRes->next;
            if (prevRes == NULL)
            {
                resManager->resLists[RESRC_GET_TYPE(res->resTypeId)] = res->next;
            }
            if (nextRes != NULL)
            {
                nextRes->prev = prevRes;
            }
            if (prevRes != NULL)
            {
                prevRes->next = nextRes;
            }
            if (res->ownedData != NULL)
            {
                RwFree(res->ownedData);
                res->ownedData = NULL;
            }
            RwFree(res);
            return;
        }
        else
        {
            currRes = currRes->next;
        }
    }
}

// FUN_003b5430. Return the head of a list of a resource type
Resrc* resrcMngGetListHead(ResrcManager* resManager, u8 resType)
{
    if (resType >= RESRC_TYPE_MAX)
    {
        return NULL;
    }

    return resManager->resLists[resType];
}

// FUN_003b5460. Return the tail of a list of a resource type
Resrc* resrcMngGetListTail(ResrcManager* resManager, u8 resType)
{
    Resrc* currRes;
    
    if (resType >= RESRC_TYPE_MAX)
    {
        return NULL;
    }

    currRes = resManager->resLists[resType];
    if (currRes == NULL)
    {
        return currRes;
    }

    while (currRes->next != NULL)
    {
        currRes = currRes->next;
    }

    return currRes;
}

// FUN_003b54c0. Return a resource by a resTypeId
Resrc* resrcMngGetRes(ResrcManager* resManager, u16 resTypeId)
{
    u8 type;
    Resrc* currRes;

    type = RESRC_GET_TYPE(resTypeId);
    if (type == 0)
    {
        return NULL;
    }

    if (type >= RESRC_TYPE_MAX)
    {
        return NULL;
    }

    for (currRes = resManager->resLists[type]; currRes != NULL; currRes = currRes->next)
    {
        if (currRes->resTypeId == resTypeId)
        {
            return currRes;
        }
    }

    return NULL;
}

// FUN_003b5550. Return the total number of resource in a list by a resType
u32 resrcMngGetTotalResInList(ResrcManager* resManager, u8 resType)
{
    u32 total;
    Resrc* currRes;

    total = 0;
    if (resType >= RESRC_TYPE_MAX)
    {
        return total;
    }

    for (currRes = resManager->resLists[resType]; currRes != NULL; currRes = currRes->next)
    {
        total++;
    }

    return total;
}


#include "Scene/mt_scene.h"
#include "Scene/mt_sceneFunc.h"
#include "Kosaka/Field/k_fldrc.h"
#include "Kosaka/Field/k_fldFrame.h"
#include "Kosaka/Field/k_sceneDraw.h"
#include "Kosaka/Field/k_shadow.h"
#include "Kosaka/Field/k_dungeon.h"
#include "Kosaka/Field/k_field.h"
#include "Kernel/Kwln/kwlnTask.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))
#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif
#define CONCAT44_F32(hi,lo) ((((u64)(*(u32 *)&(hi))) << 32) | *(u32 *)&(lo))
extern u32 DAT_006a2af0[24];
extern char DAT_006a2b50[];
extern u32 DAT_006a2af4;
extern u32 DAT_006a2af8;
extern u32 DAT_006a2afc;
extern u32 DAT_006a2d20;
extern u32 DAT_006a2d50;
#pragma alias DAT_006a2d20_abs DAT_006a2d20
extern u8 DAT_006a2d20_abs[];
#pragma alias DAT_006a2d30_abs DAT_006a2d30
extern u8 DAT_006a2d30_abs[];
#pragma alias DAT_006a2d40_abs DAT_006a2d40
extern u8 DAT_006a2d40_abs[];
#pragma alias DAT_006a2d50_abs DAT_006a2d50
extern u8 DAT_006a2d50_abs[];
extern void FUN_00318a50_typed(void *model, const RwV3d *axis, f32 angle, s32 mode);
extern void FUN_00318a90_typed(void *model, const RwV3d *scale, s32 mode);
extern void FUN_00318a30_typed(void *model, const RwV3d *translation, s32 mode);
extern u32 DAT_006a2d28;
extern u32 DAT_006a2d30;
extern u32 DAT_006a2d38;
extern u32 DAT_006a2d40;
extern u32 DAT_006a2d48;
extern u64 DAT_006a2dc8;
extern f32 DAT_006a2dd0;
extern f32 DAT_007caf18;
extern f32 DAT_007caf24;
extern f32 DAT_007caf34;
extern code DAT_0096017c;
extern u8 * PTR_DAT_007cd540;
#pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];

#pragma alias PTR_DAT_007cd540_u32 PTR_DAT_007cd540
extern u32 *PTR_DAT_007cd540_u32;
extern void FUN_001e6af0(void *param_1,void *param_2,float param_3,float param_4,float param_5);
extern s32 adminiGetNowSeqId(void);
extern void func_001b3c90(void* param_1);
extern void func_001b8600(void);
extern void func_001b8870(void);
extern void func_001b8ae0(void);
extern void func_001c80c0(void);
extern void func_003b7090(u16 resTypeId);
extern void func_004c43b0(void);
extern void* DAT_0086bdc0[9];

static MtScene sMtScene;       // 0095afc0
MtScene* gMtScene = &sMtScene; // 007cd540
extern Resrc* resrcMngCreateRes_y2(ResrcManager* resManager, u16 resTypeId);
extern u32 FUN_003b50d0(u32 resManager, u16 resTypeId);
#pragma alias FUN_003b50d0_u32 FUN_003b50d0
extern u32 FUN_003b50d0_u32(u32 resManager, u32 resTypeId);
#pragma alias FUN_0034ff70_typed FUN_0034ff70
extern void FUN_0034ff70_typed(f32 param_1, u8 (*param_2)[16]);
#pragma alias FUN_004c31b0_mtScene FUN_004c31b0
extern void FUN_004c31b0_mtScene(RwMatrix* matrix, const RwV3d* axis, f32 angle, s32 mode);
#pragma alias FUN_004c35d0_mtScene FUN_004c35d0
extern void FUN_004c35d0_mtScene(RwMatrix* matrix, u64 param_2, s32 mode);
#pragma alias FUN_00530da0_mt_scene FUN_00530da0
extern u32 FUN_00530da0_mt_scene(f32 param_1);
#pragma alias FUN_005318a0_mt_scene FUN_005318a0
extern f32 FUN_005318a0_mt_scene(u32 param_1);
#pragma alias FUN_004c69f0_mt_scene FUN_004c69f0
extern f32 FUN_004c69f0_mt_scene(float *dst, const float *src);
#pragma alias FUN_004c6ac0_mt_scene FUN_004c6ac0
extern f32 FUN_004c6ac0_mt_scene(const float *src);
#pragma alias FUN_0052e9e8_mt_scene FUN_0052e9e8
extern f32 FUN_0052e9e8_mt_scene(f32 param_1);
#pragma alias FUN_004c31b0_mt_scene_f32 FUN_004c31b0
extern void FUN_004c31b0_mt_scene_f32(f32 value, void *matrix, u32 resource, s32 mode);



/* Region 0x390000-0x3CFFFF recovered prototypes */
extern u8 D_006A2A70[];
extern u8 D_006A2A60[];
extern u8 D_006A2A80[];
void MT_Scene_Load(s32 fldMajorId, s32 fldMinorId);
u32 MT_Scene_TryLoadFinish();
void MT_Scene_Destroy();
MtScene* MT_Scene_GetScene();
Resrc* MT_Scene_GetRes(u16 resTypeId);
Resrc* MT_Scene_GetResListHead(u32 resType);
u32 MT_Scene_GetTotalResInList(u32 resType);
void MT_Scene_003b6000(u16 resId, Model* mdl);
u16 MT_Scene_CreateResModelChar(u16 resId, s32 param_2, Model* mdl);
u16 MT_Scene_CreateResModelNpc(u16 resId, s32 param_2, Model* mdl);
u16 MT_Scene_CreateResLightChar(u16 resId);
u16 MT_Scene_CreateResLightNpc(u16 resId);
u16 MT_Scene_CreateResModelFld(u32 resId, Model* mdl);
u8 * FUN_003b55b0(int param_1);
void FUN_003b55d0(u32 param_1,u32 *param_2);
u32 FUN_003b5620(int param_1,int param_2);
void FUN_003b58c0(short param_1);
void FUN_003b5980(short param_1);
u32 FUN_003b5d00(void);
Resrc* FUN_003b5da0(u32 param_1);
u16 FUN_003b5e90(u16 param_1);
u16 FUN_003b5f70(u16 param_1);
u16 FUN_003b6180(u16 param_1, void* param_2);
u32 FUN_003b66b0(u32 param_1,u32 param_2);
u16 FUN_003b6870(u16 param_1,RwV3d *param_2,float param_4,float param_5,float param_6,u32 param_3);
u16 FUN_003b69a0(u16 param_1,RwV3d *param_2,float param_4,float param_5,float param_6,u32 param_3);
u16 FUN_003b6ad0(u32 param_1, RwV3d* param_2, float param_3);
u16 FUN_003b6b90(u32 param_1, RwV3d* param_2, float param_3);
u16 FUN_003b6c50(u32 param_1, RwV3d* param_2, float param_3);
u16 FUN_003b6d10(u32 param_1, RwV3d* param_2, float param_3);
u16 FUN_003b6dd0(u32 param_1, RwV3d* param_2, float param_3);
u16 FUN_003b6e90(u32 param_1, RwV3d* param_2, float param_3);
u16 FUN_003b6f50(u32 param_1,u32 param_5,float param_4,u32 *param_6,RwV3d *param_7,float param_2,float param_3);
void FUN_003b7090(u64 param_1);
void FUN_003b7460(u8 *param_1,RwV3d *param_2,RwV3d *param_3,RwV3d *param_4);
void FUN_003b78b0(u64 param_1,RwV3d *param_2,RwV3d *param_3);
void FUN_003b7930(u64 param_1,RwV3d *param_2);
void FUN_003b79a0(u32 *param_1,u64 param_2,u32 *param_3);
void FUN_003b7ac0(u32 *param_1,float *param_2,u32 *param_3);
u32 FUN_003b8210(int param_1);
void FUN_003b8270(int param_1);
u32 FUN_003b82c0(Resrc* param_1,int param_2);
u32 FUN_003b8310(u16 param_1,int param_2);
u8 FUN_003b83a0(Resrc* param_1);
void FUN_003b83d0(u32 param_1);
u32 FUN_003b8470(u16 param_1,u16 param_2);
u32 FUN_003b8540(float *param_1,float *param_2,float *param_3,float *param_4);
u32 FUN_003b8690(float *param_1,float *param_2,float *param_3);
u8 FUN_003b86c0(float param_1,Resrc* param_2,RwV3d* param_3);
u32 FUN_003b8730(u16 param_1,RwV3d* param_2,float param_3);
u32 FUN_003b87f0(u64 param_1,RwV3d *param_2,u32 param_3,u8 param_4);
#pragma alias FUN_003b5d10_typed FUN_003b5d10
extern Resrc* FUN_003b5d10_typed(void);

/* Region call-cast macros */
#define FUN_003b55b0(...) ((u8 * (*)(...))FUN_003b55b0)(__VA_ARGS__)
#define FUN_003b55d0(...) ((void (*)(...))FUN_003b55d0)(__VA_ARGS__)
#define FUN_003b5620(...) ((u32 (*)(...))FUN_003b5620)(__VA_ARGS__)
#define FUN_003b58c0(...) ((void (*)(...))FUN_003b58c0)(__VA_ARGS__)
#define FUN_003b5980(...) ((void (*)(...))FUN_003b5980)(__VA_ARGS__)
#define FUN_003b5d00(...) ((u32 (*)(...))FUN_003b5d00)(__VA_ARGS__)
#define FUN_003b5da0(...) ((Resrc* (*)(...))FUN_003b5da0)(__VA_ARGS__)
#define FUN_003b5e90(...) ((u32 (*)(...))FUN_003b5e90)(__VA_ARGS__)
#define FUN_003b5f70(...) ((u32 (*)(...))FUN_003b5f70)(__VA_ARGS__)
#define FUN_003b6180(...) ((u32 (*)(...))FUN_003b6180)(__VA_ARGS__)
#define FUN_003b64c0(...) ((u32 (*)(...))FUN_003b64c0)(__VA_ARGS__)
#define FUN_003b66b0(...) ((u32 (*)(...))FUN_003b66b0)(__VA_ARGS__)
#define FUN_003b6790(...) ((u32 (*)(...))FUN_003b6790)(__VA_ARGS__)
#define FUN_003b6870(...) ((u32 (*)(...))FUN_003b6870)(__VA_ARGS__)
#define FUN_003b69a0(...) ((u32 (*)(...))FUN_003b69a0)(__VA_ARGS__)
#define FUN_003b6ad0(...) ((u32 (*)(...))FUN_003b6ad0)(__VA_ARGS__)
#define FUN_003b6b90(...) ((u32 (*)(...))FUN_003b6b90)(__VA_ARGS__)
#define FUN_003b6c50(...) ((u32 (*)(...))FUN_003b6c50)(__VA_ARGS__)
#define FUN_003b6d10(...) ((u32 (*)(...))FUN_003b6d10)(__VA_ARGS__)
#define FUN_003b6dd0(...) ((u32 (*)(...))FUN_003b6dd0)(__VA_ARGS__)
#define FUN_003b6e90(...) ((u32 (*)(...))FUN_003b6e90)(__VA_ARGS__)
#define FUN_003b6f50(...) ((u32 (*)(...))FUN_003b6f50)(__VA_ARGS__)
#define FUN_003b7090(...) ((void (*)(...))FUN_003b7090)(__VA_ARGS__)
#define FUN_003b7460(...) ((void (*)(...))FUN_003b7460)(__VA_ARGS__)
#define FUN_003b78b0(...) ((void (*)(...))FUN_003b78b0)(__VA_ARGS__)
#define FUN_003b7930(...) ((void (*)(...))FUN_003b7930)(__VA_ARGS__)
#define FUN_003b79a0(...) ((void (*)(...))FUN_003b79a0)(__VA_ARGS__)
#define FUN_003b7ac0(...) ((void (*)(...))FUN_003b7ac0)(__VA_ARGS__)
#define FUN_003b8210(...) ((u32 (*)(...))FUN_003b8210)(__VA_ARGS__)
#define FUN_003b8270(...) ((void (*)(...))FUN_003b8270)(__VA_ARGS__)
#define FUN_003b82c0(...) ((u32 (*)(...))FUN_003b82c0)(__VA_ARGS__)
#define FUN_003b8310(...) ((u32 (*)(...))FUN_003b8310)(__VA_ARGS__)
#define FUN_003b83a0(...) ((u8 (*)(...))FUN_003b83a0)(__VA_ARGS__)
#define FUN_003b83d0(...) ((void (*)(...))FUN_003b83d0)(__VA_ARGS__)
#define FUN_003b8470(...) ((u32 (*)(...))FUN_003b8470)(__VA_ARGS__)
#define FUN_003b8540(...) ((u32 (*)(...))FUN_003b8540)(__VA_ARGS__)
#define FUN_003b8690(...) ((u32 (*)(...))FUN_003b8690)(__VA_ARGS__)
#define FUN_003b86c0(...) ((u8 (*)(...))FUN_003b86c0)(__VA_ARGS__)
#define FUN_003b8730(...) ((u32 (*)(...))FUN_003b8730)(__VA_ARGS__)
#define FUN_003b87f0(...) ((u32 (*)(...))FUN_003b87f0)(__VA_ARGS__)













#undef FUN_003b55b0
// FUN_003B55B0


u8 * FUN_003b55b0(int param_1)



{

  return (u8 *)&DAT_006a2af0 + param_1 * 0x10;

}
#define FUN_003b55b0(...) ((u8 * (*)(...))FUN_003b55b0)(__VA_ARGS__)
#undef FUN_003b55d0
// FUN_003B55D0


void FUN_003b55d0(u32 param_1,u32 *param_2)
{
    if (param_1 < 6)
    {
        ((RwV4d*)DAT_006a2af0)[param_1] = *(RwV4d*)param_2;
    }
}
#define FUN_003b55d0(...) ((void (*)(...))FUN_003b55d0)(__VA_ARGS__)
#undef FUN_003b5620
/* W389 floor: baseline nd15 obj308/320; s0/s1 parameter colouring inversion (retail s0=a0,s1=a1; ours reversed) propagates into branches. First-use probes `first=(u32)param_1` and `second=param_2` hoisted/reused both measured nd15 obj308/320; reverted. */
// FUN_003B5620 NONMATCHING


u32 FUN_003b5620(int param_1,int param_2)
{
  u32 uVar1;
  int lVar2;
  u32 ok;
  u8 auStack_100[128];
  u8 auStack_80[128];

  FUN_00524270(auStack_100,DAT_006a2b50);
  FUN_00523ac8(auStack_80,((u8 *)&PTR_DAT_007cd540 + 8),param_1);
  FUN_00523e68(auStack_100,auStack_80);
  FUN_00523ac8(auStack_80,((u8 *)&PTR_DAT_007cd540 + 0x10),param_2);
  FUN_00523e68(auStack_100,auStack_80);
  FUN_00523e68(auStack_100,((u8 *)&PTR_DAT_007cd540 + 0x18));
  lVar2 = FUN_001008b0(auStack_100);
  if (lVar2 == 0) {
    uVar1 = 0;
  } else {
    uVar1 = 1;
    ok = (param_1 < 0x14);
    if ((((ok == 0) && (param_1 < 0x1d) && (param_2 == 0)) ||
         (((ok = (param_1 < 0x33)) == 0) && (param_1 < 0x3b))) ||
        (((ok = (param_1 < 0x28)) == 0) && (param_1 < 0x31) && (param_2 == 0)) ||
        (((ok = (param_1 < 0x47)) == 0) && (param_1 < 0x4f))) {
      uVar1 = 1;
    }
  }
  return uVar1;
}
#define FUN_003b5620(...) ((u32 (*)(...))FUN_003b5620)(__VA_ARGS__)
#undef FUN_003b58c0
#define FUN_003b58c0(...) ((void (*)(...))FUN_003b58c0)(__VA_ARGS__)
#undef FUN_003b5980
#define FUN_003b5980(...) ((void (*)(...))FUN_003b5980)(__VA_ARGS__)
#undef FUN_003b5d00
#define FUN_003b5d00(...) ((u32 (*)(...))FUN_003b5d00)(__VA_ARGS__)
#undef FUN_003b5da0
#define FUN_003b5da0(...) ((Resrc* (*)(...))FUN_003b5da0)(__VA_ARGS__)
extern const char D_006A2BB0[];
#pragma alias D_006A2BB0_abs D_006A2BB0
extern u8 D_006A2BB0_abs[];
extern const char D_006A2BD0[];
#pragma alias D_006A2BD0_abs D_006A2BD0
extern u8 D_006A2BD0_abs[];
extern const char D_006A2BE8[];
#pragma alias D_006A2BE8_abs D_006A2BE8
extern u8 D_006A2BE8_abs[];
#undef FUN_003b5e90
#define FUN_003b5e90(...) ((u32 (*)(...))FUN_003b5e90)(__VA_ARGS__)
#undef FUN_003b5f70
#define FUN_003b5f70(...) ((u32 (*)(...))FUN_003b5f70)(__VA_ARGS__)
#undef FUN_003b6180
#define FUN_003b6180(...) ((u32 (*)(...))FUN_003b6180)(__VA_ARGS__)
#undef FUN_003b64c0
#define FUN_003b64c0(...) ((u32 (*)(...))FUN_003b64c0)(__VA_ARGS__)
#undef FUN_003b66b0
#define FUN_003b66b0(...) ((u32 (*)(...))FUN_003b66b0)(__VA_ARGS__)
#undef FUN_003b6790
#define FUN_003b6790(...) ((u32 (*)(...))FUN_003b6790)(__VA_ARGS__)
#undef FUN_003b6870
#define FUN_003b6870(...) ((u32 (*)(...))FUN_003b6870)(__VA_ARGS__)
#undef FUN_003b69a0
#define FUN_003b69a0(...) ((u32 (*)(...))FUN_003b69a0)(__VA_ARGS__)
#undef FUN_003b6ad0
#define FUN_003b6ad0(...) ((u32 (*)(...))FUN_003b6ad0)(__VA_ARGS__)
#undef FUN_003b6b90
 
 
 
#define FUN_003b6b90(...) ((u32 (*)(...))FUN_003b6b90)(__VA_ARGS__)
#undef FUN_003b6c50
#define FUN_003b6c50(...) ((u32 (*)(...))FUN_003b6c50)(__VA_ARGS__)
#undef FUN_003b6d10
#define FUN_003b6d10(...) ((u32 (*)(...))FUN_003b6d10)(__VA_ARGS__)
#undef FUN_003b6dd0
#define FUN_003b6dd0(...) ((u32 (*)(...))FUN_003b6dd0)(__VA_ARGS__)
#undef FUN_003b6e90
#define FUN_003b6e90(...) ((u32 (*)(...))FUN_003b6e90)(__VA_ARGS__)
#undef FUN_003b6f50
#define FUN_003b6f50(...) ((u32 (*)(...))FUN_003b6f50)(__VA_ARGS__)
#undef FUN_003b7090
/* Measured W389: opt_loop_invariants on, with/without nd 100/98, object 972/972 (window 976). */
#define FUN_003b7090(...) ((void (*)(...))FUN_003b7090)(__VA_ARGS__)
#undef FUN_003b7460
/* Measured W389: opt_lifetimes on, with/without nd 648/642, object 1104/1104 (window 1104). */
#undef FUN_003b7460
#undef FUN_003b78b0
#define FUN_003b78b0(...) ((void (*)(...))FUN_003b78b0)(__VA_ARGS__)
#undef FUN_003b7930
#define FUN_003b7460(...) ((void (*)(...))FUN_003b7460)(__VA_ARGS__)
#define FUN_003b7930(...) ((void (*)(...))FUN_003b7930)(__VA_ARGS__)
#undef FUN_003b79a0
#define FUN_003b79a0(...) ((void (*)(...))FUN_003b79a0)(__VA_ARGS__)
#undef FUN_003b7ac0
/* Measured W389: opt_dead_assignments off, with/without nd 942/940, object 1868/1868 (window 1872). */
#define FUN_003b7ac0(...) ((void (*)(...))FUN_003b7ac0)(__VA_ARGS__)
#undef FUN_003b8210
#define FUN_003b8210(...) ((u32 (*)(...))FUN_003b8210)(__VA_ARGS__)
#undef FUN_003b8270
#define FUN_003b8270(...) ((void (*)(...))FUN_003b8270)(__VA_ARGS__)
#undef FUN_003b82c0
#define FUN_003b82c0(...) ((u32 (*)(...))FUN_003b82c0)(__VA_ARGS__)
#undef FUN_003b8310
#define FUN_003b8310(...) ((u32 (*)(...))FUN_003b8310)(__VA_ARGS__)
#undef FUN_003b83a0
#define FUN_003b83a0(...) ((u8 (*)(...))FUN_003b83a0)(__VA_ARGS__)
#undef FUN_003b83d0
#undef FUN_003b7460
#undef FUN_003b8470
#define FUN_003b8470(...) ((u32 (*)(...))FUN_003b8470)(__VA_ARGS__)
#undef FUN_003b8540
/* Measured W389: opt_common_subs off + opt_lifetimes on, with/without nd 197/190, object 312/308 (window 336). */
#undef FUN_003b8540
#undef FUN_003b8690
#define FUN_003b8690(...) ((u32 (*)(...))FUN_003b8690)(__VA_ARGS__)
#undef FUN_003b86c0
#define FUN_003b86c0(...) ((u8 (*)(...))FUN_003b86c0)(__VA_ARGS__)
#undef FUN_003b8730
#define FUN_003b8730(...) ((u32 (*)(...))FUN_003b8730)(__VA_ARGS__)
#undef FUN_003b87f0
#define FUN_003b87f0(...) ((u32 (*)(...))FUN_003b87f0)(__VA_ARGS__)
