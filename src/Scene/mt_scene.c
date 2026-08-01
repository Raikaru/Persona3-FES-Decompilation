#include "temporary.h"
#include "Scene/mt_scene.h"
#include "Scene/mt_sceneFunc.h"
#include "Scene/resrcManager.h"
#include "Kosaka/Field/k_fldrc.h"
#include "Kosaka/Field/k_fldFrame.h"
#include "Kosaka/Field/k_sceneDraw.h"
#include "Kosaka/Field/k_shadow.h"
#include "Graphics/Model/mdlManager.h"
#include "rw/rwplcore.h"
#include "temporary.h"
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
#pragma alias FUN_003b79a0_typed FUN_003b79a0
extern void FUN_003b79a0_typed(u32 *param_1, u64 param_2, u32 *param_3);
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
extern Resrc* resrcMngCreateRes(ResrcManager* resManager, u16 resTypeId);
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
extern void FUN_004c31b0_mt_scene_f32(void *matrix, u32 resource, f32 value, s32 mode);



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

// FUN_003b5760
void MT_Scene_Load(s32 fldMajorId, s32 fldMinorId)
{
    gMtScene->flags = 0;

    if (gMtScene->fldMajorId == fldMajorId && 
        gMtScene->fldMinorId == fldMinorId &&
       (fldMajorId < 20 || fldMajorId > 28))
    {
        printf("Scene data cashe hit!! major=%d minor=%d\n", fldMajorId, fldMinorId);
        gMtScene->flags |= MTSCENE_FLAG_CACHE;

        return;
    }

    MT_Scene_Destroy();

    K_Fldrc_RequestFldPac(fldMajorId, fldMinorId);
    K_Fldrc_001b0a20(fldMajorId, fldMinorId);

    gMtScene->fldFilterTask = K_Fldrc_CreateFilterTask(NULL);
    gMtScene->fldMajorId = fldMajorId;
    gMtScene->fldMinorId = fldMinorId;
    gMtScene->unk_14 = 0;
    gMtScene->unk_16 = gMtScene->fldMinorId;
    gMtScene->resManager = resrcMngCreate();

    MT_Scene_CreateResLightChar(0);
    K_Scene_InitCharLight();

    MT_Scene_CreateResLightNpc(0);
    K_Scene_InitNpcLight();

    printf("Scene data load...\n");
}
#undef FUN_003b55b0
#define FUN_003b55b0(...) ((u8 * (*)(...))FUN_003b55b0)(__VA_ARGS__)
#undef FUN_003b55d0
#define FUN_003b55d0(...) ((void (*)(...))FUN_003b55d0)(__VA_ARGS__)
#undef FUN_003b5620
/* W389 floor: baseline nd15 obj308/320; s0/s1 parameter colouring inversion (retail s0=a0,s1=a1; ours reversed) propagates into branches. First-use probes `first=(u32)param_1` and `second=param_2` hoisted/reused both measured nd15 obj308/320; reverted. */
#define FUN_003b5620(...) ((u32 (*)(...))FUN_003b5620)(__VA_ARGS__)
#undef FUN_003b58c0
// FUN_003B58C0


void FUN_003b58c0(short param_1)
{
    int iVar1;
    int wait;

    if ((gMtScene->flags & 1) != 0) {
        if (gMtScene->unk_14 != param_1) {
            gMtScene->flags |= 2;
            gMtScene->unk_14 = param_1;
            wait = 0x1e;
            *(u32 *)(FUN_001b9120() + 0x1058) = wait;
            return;
        }
        for (iVar1 = (int)MT_Scene_GetResListHead(3); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xf8)) {
            *(u32 *)(iVar1 + 0x28) |= 2;
        }
        return;
    }
    gMtScene->unk_14 = param_1;
}
#define FUN_003b58c0(...) ((void (*)(...))FUN_003b58c0)(__VA_ARGS__)
#undef FUN_003b5980
// FUN_003B5980

void FUN_003b5980(short param_1)
{
    int iVar2;

    if ((gMtScene->flags & 1) != 0) {
        if (gMtScene->unk_16 == param_1) {
            return;
        }
        gMtScene->flags |= 4;
        gMtScene->unk_16 = param_1;
        if ((gMtScene->flags & 2) != 0) {
            return;
        }
        iVar2 = 0x28;
        *(u32 *)(FUN_001b9120() + 0x1058) = iVar2;
        return;
    }
    gMtScene->unk_16 = param_1;
}
#define FUN_003b5980(...) ((void (*)(...))FUN_003b5980)(__VA_ARGS__)

// FUN_003b5a10
u32 MT_Scene_TryLoadFinish()
{
    if (gMtScene->resManager == NULL)
    {
        return true;
    }

    if (gMtScene->flags & MTSCENE_FLAG_CACHE && 
        !(gMtScene->flags & (MTSCENE_FLAG_UNK02 | MTSCENE_FLAG_UNK04)))
    {
        return true;
    }

    if (!K_Fldrc_Init())
    {
        return false;
    }
        
    if (gMtScene->sceneMngTask == NULL)
    {
        gMtScene->sceneMngTask = MT_SceneFunc_CreateTasks();
    }

    return true;
}

// FUN_003b5ab0
void MT_Scene_Destroy()
{
    s32 resType;
    Resrc* res;
    Resrc* nextRes;
    s32 i;
    ResrcManager* resManager;

    resManager = gMtScene->resManager;
    if (gMtScene->sceneMngTask != NULL)
    {
        kwlnTaskDestroyWithHierarchy(gMtScene->sceneMngTask);
        gMtScene->sceneMngTask = NULL;
    }

    if (gMtScene->fldFilterTask != NULL)
    {
        kwlnTaskPrintTrees();
        kwlnTaskDestroyWithHierarchy(gMtScene->fldFilterTask);
        gMtScene->fldFilterTask = NULL;
    }

    if (resManager != NULL)
    {
        for (resType = 0; resType < RESRC_TYPE_MAX; resType++)
        {
            for (res = resrcMngGetListHead(resManager, resType); res != NULL; res = nextRes)
            {
                nextRes = res->next;
                func_003b7090(res->resTypeId);
            }
        }

        resrcMngDestroy(resManager);
        gMtScene->resManager = NULL;
    }

    if (adminiGetNowSeqId() != 5)
    {
        if (gDungeonTpMdl != NULL && K_FldDungeon_GetCurrentFloor() == 0)
        {
            mdlDestroy(gDungeonTpMdl);
            gDungeonTpMdl = NULL;
        }

        for (i = 0; i < 9; i++)
        {
            if (DAT_0086bdc0[i] != NULL)
            {
                func_001b3c90(DAT_0086bdc0[i]);
                DAT_0086bdc0[i] = NULL;
            }
        }
    }

    if (*(Model**)((u8*)K_Field_Get() + 0x11ec) != NULL)
    {
        mdlDestroy(*(Model**)((u8*)K_Field_Get() + 0x11ec));
        *(Model**)((u8*)K_Field_Get() + 0x11ec) = NULL;
    }

    if (*(Model**)((u8*)K_Field_Get() + 0x11f0) != NULL)
    {
        mdlDestroy(*(Model**)((u8*)K_Field_Get() + 0x11f0));
        *(Model**)((u8*)K_Field_Get() + 0x11f0) = NULL;
    }

    func_001b8600();
    func_001b8870();
    func_001b8ae0();
    func_001c80c0();
    gMtScene->fldMajorId = -1;
    gMtScene->fldMinorId = -1;
    gMtScene->unk_14 = 0;
    gMtScene->unk_16 = 0;
    gMtScene->shouldSortChars = false;

    func_004c43b0();
}
// FUN_003b5cf0
MtScene* MT_Scene_GetScene()
{
    return gMtScene;
}
#undef FUN_003b5d00
// FUN_003B5D00


u32 FUN_003b5d00(void)
{
    return *(u32 *)(PTR_DAT_007cd540 + 8);
}
#define FUN_003b5d00(...) ((u32 (*)(...))FUN_003b5d00)(__VA_ARGS__)

// FUN_003b5d10
Resrc* MT_Scene_GetRes(u16 resTypeId)
{
    if (gMtScene->resManager == NULL)
    {
        return NULL;
    }

    return resrcMngGetRes(gMtScene->resManager, resTypeId);
}

// FUN_003b5d50
Resrc* MT_Scene_GetResListHead(u32 resType)
{
    if (gMtScene->resManager == NULL)
    {
        return NULL;
    }

    return resrcMngGetListHead(gMtScene->resManager, resType);
}
#undef FUN_003b5da0
// FUN_003B5DA0


Resrc* FUN_003b5da0(u32 param_1)
{
    if (*(int *)(PTR_DAT_007cd540 + 8) == 0)
    {
        return NULL;
    }

    return resrcMngGetListTail(*(ResrcManager **)(PTR_DAT_007cd540 + 8), param_1);
}
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

// FUN_003b5df0
u32 MT_Scene_GetTotalResInList(u32 resType)
{
    s32 i;
    s32 total;
    ResrcManager* resManager;
    u32 type;

    type = resType;
    total = 0;
    resManager = gMtScene->resManager;
    if (resManager == NULL)
    {
        return 0;
    }

    // ??? wtf is the point of this loop
    for (i = 0; i < RESRC_TYPE_MAX; i++)
    {
        if (i == type)
        {
            total += resrcMngGetTotalResInList(resManager, i);
        }
    }

    return total;
}
#undef FUN_003b5e90
// FUN_003B5E90







u16 FUN_003b5e90(u16 param_1)
{
    u16 uVar1;
    Resrc* lVar2;
    u32 typeId;
    uVar1 = ((param_1 & 0xffff) & 0x3ff) | 0x2000;
    if (gMtScene->resManager == NULL)
    {
        FUN_005225a8(D_006A2BB0_abs);
        return 0;
    }

    typeId = uVar1 & 0xffff;
    if (((s32)(typeId & RESRC_TYPE_MASK) >> 10) != 8)
    {
        FUN_005225a8(D_006A2BD0_abs);
        return 0;
    }

    lVar2 = resrcMngCreateRes(gMtScene->resManager, uVar1);
    if (lVar2 == 0)
    {
        return 0;
    }
    else if (lVar2 == 0)
    {
        FUN_0019d3f0(D_006A2BE8_abs, 0x1d7);
    }

    return uVar1;
}
#define FUN_003b5e90(...) ((u32 (*)(...))FUN_003b5e90)(__VA_ARGS__)
#undef FUN_003b5f70
// FUN_003B5F70
u16 FUN_003b5f70(u16 param_1)
{
    u16 resTypeId;
    ResrcManager* resManager;
    Resrc* res;

    resTypeId = (param_1 & RESRC_ID_MASK) | 0x1c00;
    resManager = gMtScene->resManager;
    if (resManager == NULL)
    {
        printf("not found active resmanager\n");
        return 0;
    }

    res = resrcMngCreateRes(resManager, resTypeId);
    if (res == NULL)
    {
        return 0;
    }

    *(u32*)((u8*)res + 0x100) = 0x420c0000;
    return resTypeId;
}
#define FUN_003b5f70(...) ((u32 (*)(...))FUN_003b5f70)(__VA_ARGS__)





// FUN_003b6000
void MT_Scene_003b6000(u16 resId, Model* mdl)
{
    MT_Scene_CreateResModelChar(resId, 0, mdl);
}

// FUN_003b6030
u16 MT_Scene_CreateResModelChar(u16 resId, s32 param_2, Model* mdl)
{
    ResrcManager* resManager;
    u16 resTypeId;
    ResrcModelChar* res;
    RwV3d translation = {0};

    resTypeId = RESRC_MAKE_TYPEID(resId, RESRC_TYPE_MODELCHAR);
    
    resManager = gMtScene->resManager;
    if (resManager == NULL)
    {
        printf("not found active resmanager\n");
        return 0;
    }

    if (mdl == NULL)
    {
        return 0;
    }

    res = (ResrcModelChar*)resrcMngCreateRes(resManager, resTypeId);
    if (res == NULL)
    {
        return 0;
    }

    res->mdl = mdl;
    mdlTranslate(res->mdl, &translation, rwCOMBINEREPLACE);
    RwMatrixUpdate(mdlGetMatrix(res->mdl));

    res->collisCtlTask = K_FldFrame_CreateCtlTask(NULL, resTypeId, 0, 60.0f);
    res->renderTexShadowTask = K_FldShadow_CreateRenderTexTask(res->collisCtlTask, resTypeId, param_2);

    return resTypeId;
}
#undef FUN_003b6180
// FUN_003B6180


u16 FUN_003b6180(u16 param_1, void* param_2)
{
    u16 resTypeId;
    Resrc* res;
    u8 auStack_10[16];
    u8* puVar5;
    u8* puVar2;


    puVar5 = auStack_10;
    puVar2 = (u8*)0xc;
    if (puVar5 != NULL)
    {
        do
        {
            *puVar5 = 0;
            puVar5++;
            puVar2--;
        } while (puVar2 != NULL);
    }

    resTypeId = (param_1 & RESRC_ID_MASK) | 0x800;

    if (gMtScene->resManager == NULL)
    {
        FUN_005225a8(D_006A2BB0_abs);
        return 0;
    }
    else if (param_2 == NULL)
    {
        return 0;
    }
    else
    {
        res = (Resrc*)FUN_003b50d0((u32)gMtScene->resManager, resTypeId);
        if (res == NULL)
        {
            return 0;
        }
        else
        {
            *(void**)((u8*)res + 0x118) = param_2;
            FUN_00318a30(param_2, (RwV3d*)auStack_10, 0);
        }
    }

    return resTypeId;
}
#define FUN_003b6180(...) ((u32 (*)(...))FUN_003b6180)(__VA_ARGS__)
// FUN_003b6270
u16 MT_Scene_CreateResModelNpc(u16 resId, s32 param_2, Model* mdl)
{
    ResrcManager* resManager;
    u16 resTypeId;
    ResrcModelNpc* res;
    RwV3d translation = {0};

    resTypeId = RESRC_MAKE_TYPEID(resId, RESRC_TYPE_MODELNPC);
    
    resManager = gMtScene->resManager;
    if (resManager == NULL)
    {
        printf("not found active resmanager\n");
        return 0;
    }

    if (mdl == NULL)
    {
        return 0;
    }

    res = (ResrcModelNpc*)resrcMngCreateRes(resManager, resTypeId);
    if (res == NULL)
    {
        return 0;
    }

    res->mdl = mdl;
    mdlTranslate(res->mdl, &translation, rwCOMBINEREPLACE);
    RwMatrixUpdate(mdlGetMatrix(res->mdl));

    res->collisCtlTask = K_FldFrame_CreateCtlTask(NULL, resTypeId, 0, 60.0f);
    res->renderTexShadowTask = K_FldShadow_CreateRenderTexTask(res->collisCtlTask, resTypeId, param_2);

    return resTypeId;
}
// FUN_003b63c0
u16 MT_Scene_CreateResLightChar(u16 resId)
{
    ResrcManager* resManager;
    u16 resTypeId;

    resTypeId = RESRC_MAKE_TYPEID(resId, RESRC_TYPE_LIGHTCHAR);

    resManager = gMtScene->resManager;
    if (resManager == NULL)
    {
        printf("not found active resmanager\n");
        return 0;
    }

    if (resrcMngCreateRes(resManager, resTypeId) == NULL)
    {
        return 0;
    }

    return resTypeId;
}

// FUN_003b6440
u16 MT_Scene_CreateResLightNpc(u16 resId)
{
    ResrcManager* resManager;
    u16 resTypeId;

    resTypeId = RESRC_MAKE_TYPEID(resId, RESRC_TYPE_LIGHTNPC);

    resManager = gMtScene->resManager;
    if (resManager == NULL)
    {
        printf("not found active resmanager\n");
        return 0;
    }

    if (resrcMngCreateRes(resManager, resTypeId) == NULL)
    {
        return 0;
    }

    return resTypeId;
}
#undef FUN_003b64c0
// FUN_003B64C0


u32 FUN_003b64c0(u32 param_1, u32 param_2, u8 param_3)
{
    u32 resTypeId;
    u32 res;
    u32 auStack_10[3];

    resTypeId = (u16)(((u16)param_1 & 0xffff) & RESRC_ID_MASK | 0x1800);
    if (gMtScene->resManager == NULL)
    {
        FUN_005225a8(D_006A2BB0_abs);
        return 0;
    }
    else if (param_2 == 0)
    {
        FUN_005225a8(D_006A2BD0_abs);
        return 0;
    }
    else
    {
        res = FUN_003b50d0_u32((u32)gMtScene->resManager, resTypeId);
        if (res == 0)
        {
            return 0;
        }
        else
        {
            *(u32*)(res + 0x104) = FUN_0034fcd0(param_2);
            *(u8*)(res + 0x100) = param_3;
            auStack_10[0] = 0x42c80000;
            auStack_10[1] = 0;
            auStack_10[2] = 0;
            FUN_0034fdf0(*(u32*)(res + 0x104), auStack_10);
            FUN_0034ff70_typed(1.5f, (u8 (*)[16])*(u32*)(res + 0x104));
        }
    }

    return resTypeId;
}
#define FUN_003b64c0(...) ((u32 (*)(...))FUN_003b64c0)(__VA_ARGS__)
// FUN_003b65d0
u16 MT_Scene_CreateResModelFld(u32 resId, Model* mdl)
{
    ResrcManager* resManager;
    u16 resTypeId;
    ResrcModelFld* res;
    RwV3d unused = {0};

    resTypeId = RESRC_MAKE_TYPEID((u16)resId, RESRC_TYPE_MODELFLD);

    resManager = gMtScene->resManager;
    if (resManager == NULL)
    {
        printf("not found active resmanager\n");
        return 0;
    }

    if (mdl == NULL)
    {
        return 0;
    }

    res = (ResrcModelFld*)resrcMngCreateRes(resManager, resTypeId);
    if (res == NULL)
    {
        return 0;
    }

    res->mdl = mdl;
    res->base.flags |= (1 << 3); // 0x08

    return resTypeId;
}
#undef FUN_003b66b0
// FUN_003B66B0


u32 FUN_003b66b0(u32 param_1, u32 param_2)
{
    u32 resTypeId;
    ResrcModelFld* res;
    u8 auStack_10[16];
    u8* puVar5;
    u8* puVar2;

    puVar5 = auStack_10;
    puVar2 = (u8*)0xc;
    if (puVar5 != NULL)
    {
        do
        {
            *puVar5 = 0;
            puVar5++;
            puVar2--;
        } while (puVar2 != NULL);
    }

    resTypeId = (u16)(((u16)param_1 & 0xffff) & RESRC_ID_MASK | 0x2c00);
    if (gMtScene->resManager == NULL)
    {
        FUN_005225a8(D_006A2BB0_abs);
        return 0;
    }
    else if (param_2 == 0)
    {
        return 0;
    }
    else
    {
        res = (ResrcModelFld*)FUN_003b50d0_u32((u32)gMtScene->resManager, resTypeId);
        if (res == NULL)
        {
            return 0;
        }
        else
        {
            res->mdl = (Model*)param_2;
            res->base.flags = res->base.flags | 8;
        }
    }

    return resTypeId;
}
#define FUN_003b66b0(...) ((u32 (*)(...))FUN_003b66b0)(__VA_ARGS__)
#undef FUN_003b6790
// FUN_003B6790


u32 FUN_003b6790(u32 param_1, u32 param_2)
{
    u32 resTypeId;
    ResrcFld* res;
    u8 auStack_10[16];
    u8* puVar5;
    u8* puVar2;

    puVar5 = auStack_10;
    puVar2 = (u8*)0xc;
    if (puVar5 != NULL)
    {
        do
        {
            *puVar5 = 0;
            puVar5++;
            puVar2--;
        } while (puVar2 != NULL);
    }

    resTypeId = (u16)(((u16)param_1 & 0xffff) & RESRC_ID_MASK | 0x3000);
    if (gMtScene->resManager == NULL)
    {
        FUN_005225a8(D_006A2BB0_abs);
        return 0;
    }
    else if (param_2 == 0)
    {
        return 0;
    }
    else
    {
        res = (ResrcFld*)FUN_003b50d0_u32((u32)gMtScene->resManager, resTypeId);
        if (res == NULL)
        {
            return 0;
        }
        else
        {
            res->unk_160 = (void*)param_2;
            res->base.flags = res->base.flags | 8;
        }
    }

    return resTypeId;
}
#define FUN_003b6790(...) ((u32 (*)(...))FUN_003b6790)(__VA_ARGS__)
#undef FUN_003b6870
// FUN_003B6870


u16 FUN_003b6870(u16 param_1,RwV3d *param_2,float param_4,float param_5,float param_6,u32 param_3)
{
  u16 uVar1;
  Resrc *res1;
  RwRGBA color;
  uVar1 = param_1 & 0x3ff | 0x3400;
  if (gMtScene->resManager == NULL) {
    FUN_005225a8(D_006A2BB0_abs);
    return 0;
  }
  else {
    res1 = resrcMngCreateRes(gMtScene->resManager,uVar1);
    if (res1 == 0) {
      return 0;
    }
    else {
      *(RwV3d *)((u8 *)res1 + 0x104) = *param_2;
      *(float *)((u8 *)res1 + 0x110) = param_4;
      *(float *)((u8 *)res1 + 0x114) = param_5;
      *(float *)((u8 *)res1 + 0x118) = param_6;
      color = *(RwRGBA *)&param_3;
      *(RwRGBA *)((u8 *)res1 + 0x100) = color;
      FUN_001e6af0((u8 *)res1 + 0x11c,param_2,param_4,param_5,param_6);
      res1->flags = res1->flags | 8;
    }
  }
  return uVar1;
}
#define FUN_003b6870(...) ((u32 (*)(...))FUN_003b6870)(__VA_ARGS__)
#undef FUN_003b69a0
// FUN_003B69A0


u16 FUN_003b69a0(u16 param_1,RwV3d *param_2,float param_4,float param_5,float param_6,u32 param_3)
{
  u16 uVar1;
  Resrc *res1;
  RwRGBA color;

  uVar1 = param_1 & 0x3ff | 0x5400;
  if (gMtScene->resManager == NULL) {
    FUN_005225a8(D_006A2BB0_abs);
    return 0;
  }
  else {
    res1 = resrcMngCreateRes(gMtScene->resManager,uVar1);
    if (res1 == 0) {
      return 0;
    }
    else {
      *(RwV3d *)((u8 *)res1 + 0x104) = *param_2;
      *(float *)((u8 *)res1 + 0x110) = param_4;
      *(float *)((u8 *)res1 + 0x114) = param_5;
      *(float *)((u8 *)res1 + 0x118) = param_6;
      color = *(RwRGBA *)&param_3;
      *(RwRGBA *)((u8 *)res1 + 0x100) = color;
      FUN_001e6af0((u8 *)res1 + 0x11c,param_2,param_4,param_5,param_6);
      res1->flags = res1->flags | 8;
    }
  }
  return uVar1;
}
#define FUN_003b69a0(...) ((u32 (*)(...))FUN_003b69a0)(__VA_ARGS__)
#undef FUN_003b6ad0
// FUN_003B6AD0


u16 FUN_003b6ad0(u32 param_1, RwV3d* param_2, float param_3)
{
    Resrc* res1;
    u16 uVar2;

    uVar2 = (u16)param_1;
    uVar2 = (uVar2 & 0x3ff) | 0x3800;
    if (gMtScene->resManager == NULL)
    {
        FUN_005225a8(D_006A2BB0_abs);
        return 0;
    }
    res1 = resrcMngCreateRes(gMtScene->resManager, uVar2);
    if (res1 == NULL)
    {
        return 0;
    }
    *(RwV3d*)((u8*)res1 + 0x100) = *param_2;
    *(f32*)((u8*)res1 + 0x10c) = param_3;
    res1->flags |= 8;
    return uVar2;
}
#define FUN_003b6ad0(...) ((u32 (*)(...))FUN_003b6ad0)(__VA_ARGS__)
#undef FUN_003b6b90
// FUN_003B6B90


u16 FUN_003b6b90(u32 param_1, RwV3d* param_2, float param_3)
{
    Resrc* res1;
    u16 uVar2;

    uVar2 = (u16)param_1;
    uVar2 = (uVar2 & 0x3ff) | 0x3c00;
    if (gMtScene->resManager == NULL)
    {
        FUN_005225a8(D_006A2BB0_abs);
        return 0;
    }
    res1 = resrcMngCreateRes(gMtScene->resManager, uVar2);
    if (res1 == NULL)
    {
        return 0;
    }
    *(RwV3d*)((u8*)res1 + 0x100) = *param_2;
    *(f32*)((u8*)res1 + 0x10c) = param_3;
    res1->flags |= 8;
    return uVar2;
}
 
 
 
#define FUN_003b6b90(...) ((u32 (*)(...))FUN_003b6b90)(__VA_ARGS__)
#undef FUN_003b6c50
// FUN_003B6C50


u16 FUN_003b6c50(u32 param_1, RwV3d* param_2, float param_3)
{
    Resrc* res1;
    u16 uVar2;

    uVar2 = (u16)param_1;
    uVar2 = (uVar2 & 0x3ff) | 0x4000;
    if (gMtScene->resManager == NULL)
    {
        FUN_005225a8(D_006A2BB0_abs);
        return 0;
    }
    res1 = resrcMngCreateRes(gMtScene->resManager, uVar2);
    if (res1 == NULL)
    {
        return 0;
    }
    *(RwV3d*)((u8*)res1 + 0x100) = *param_2;
    *(f32*)((u8*)res1 + 0x10c) = param_3;
    res1->flags |= 8;
    return uVar2;
}
#define FUN_003b6c50(...) ((u32 (*)(...))FUN_003b6c50)(__VA_ARGS__)
#undef FUN_003b6d10
// FUN_003B6D10


u16 FUN_003b6d10(u32 param_1, RwV3d* param_2, float param_3)
{
    Resrc* res1;
    u16 uVar2;

    uVar2 = (u16)param_1;
    uVar2 = (uVar2 & 0x3ff) | 0x4400;
    if (gMtScene->resManager == NULL)
    {
        FUN_005225a8(D_006A2BB0_abs);
        return 0;
    }
    res1 = resrcMngCreateRes(gMtScene->resManager, uVar2);
    if (res1 == NULL)
    {
        return 0;
    }
    *(RwV3d*)((u8*)res1 + 0x100) = *param_2;
    *(f32*)((u8*)res1 + 0x10c) = param_3;
    res1->flags |= 8;
    return uVar2;
}
#define FUN_003b6d10(...) ((u32 (*)(...))FUN_003b6d10)(__VA_ARGS__)
#undef FUN_003b6dd0
// FUN_003B6DD0


u16 FUN_003b6dd0(u32 param_1, RwV3d* param_2, float param_3)
{
    Resrc* res1;
    u16 uVar2;

    uVar2 = (u16)param_1;
    uVar2 = (uVar2 & 0x3ff) | 0x4800;
    if (gMtScene->resManager == NULL)
    {
        FUN_005225a8(D_006A2BB0_abs);
        return 0;
    }
    res1 = resrcMngCreateRes(gMtScene->resManager, uVar2);
    if (res1 == NULL)
    {
        return 0;
    }
    *(RwV3d*)((u8*)res1 + 0x100) = *param_2;
    *(f32*)((u8*)res1 + 0x10c) = param_3;
    res1->flags |= 8;
    return uVar2;
}
#define FUN_003b6dd0(...) ((u32 (*)(...))FUN_003b6dd0)(__VA_ARGS__)
#undef FUN_003b6e90
// FUN_003B6E90


u16 FUN_003b6e90(u32 param_1, RwV3d* param_2, float param_3)
{
    Resrc* res1;
    u16 uVar2;

    uVar2 = (u16)param_1;
    uVar2 = (uVar2 & 0x3ff) | 0x4c00;
    if (gMtScene->resManager == NULL)
    {
        FUN_005225a8(D_006A2BB0_abs);
        return 0;
    }
    res1 = resrcMngCreateRes(gMtScene->resManager, uVar2);
    if (res1 == NULL)
    {
        return 0;
    }
    *(RwV3d*)((u8*)res1 + 0x100) = *param_2;
    *(f32*)((u8*)res1 + 0x10c) = param_3;
    res1->flags |= 8;
    return uVar2;
}
#define FUN_003b6e90(...) ((u32 (*)(...))FUN_003b6e90)(__VA_ARGS__)
#undef FUN_003b6f50
// FUN_003B6F50


u16 FUN_003b6f50(u32 param_1,u32 param_5,float param_4,u32 *param_6,RwV3d *param_7,float param_2,float param_3)
{
    u32 *puVar1;
    u16 uVar2;
    Resrc* res1;
    int iVar4;
    u32 uVar6;
    u32 uVar7;

    uVar2 = (u16)param_1;
    uVar2 = (uVar2 & 0x3ff) | 0x5000;
    if (gMtScene->resManager == NULL) {
        FUN_005225a8(D_006A2BB0_abs);
        return 0;
    }
    res1 = resrcMngCreateRes(gMtScene->resManager, uVar2);
    if (res1 == NULL) {
        return 0;
    }
    *(u32 *)((u8 *)res1 + 0x100) = param_5;
    *(f32 *)((u8 *)res1 + 0x104) = param_4;
    puVar1 = (u32 *)FUN_004c38c0();
    *(u32 **)((u8 *)res1 + 0x108) = puVar1;
    iVar4 = 8;
    do {
        uVar6 = *param_6;
        uVar7 = param_6[1];
        param_6 += 2;
        iVar4--;
        *puVar1 = uVar6;
        puVar1[1] = uVar7;
        puVar1 += 2;
    } while (0 < iVar4);
    *(RwV3d *)((u8 *)res1 + 0x10c) = *param_7;
    *(f32 *)((u8 *)res1 + 0x118) = param_2;
    *(f32 *)((u8 *)res1 + 0x11c) = param_3;
    res1->flags |= 8;
    return uVar2;
}
#define FUN_003b6f50(...) ((u32 (*)(...))FUN_003b6f50)(__VA_ARGS__)
#undef FUN_003b7090
/* Measured W389: opt_loop_invariants on, with/without nd 100/98, object 972/972 (window 976). */
#pragma push
#pragma opt_loop_invariants on
/* W420 negative: swapping puVar4 and iVar6 declarations left nd 98, object 972/976 (window 976), rate 0.100823 unchanged. */
// FUN_003B7090 NONMATCHING


void FUN_003b7090(u64 param_1)



{

  u32 resource;
  u32 scene;
  u32 uVar2;
  u32 uVar3;
  u32 *puVar4;
  int iVar6;

  scene = *(u32 *)(PTR_DAT_007cd540 + 8);
  if (scene == 0) {
    FUN_005225a8(0x6a2bb0);
  }
  else {
    if (scene == 0) {
      resource = 0;
    }
    else {
      resource = (u32)FUN_003b54c0(scene,param_1);
    }


    if (resource != 0) {
      puVar4 = (u32 *)resource;

      switch((int)(*(u16 *)puVar4 & 0xffc00) >> 10) {

      case 0:

        break;

      case 1:

        uVar2 = puVar4[0x4a];

        FUN_00195020(puVar4[0x78]);

        puVar4[0x78] = 0;

        puVar4[0x79] = 0;

        puVar4[0x4a] = 0;


        for (iVar6 = 0; iVar6 < 3; iVar6 = iVar6 + 1) {

          if (puVar4[iVar6 + 0x40] != 0) {

            FUN_0034fcf0();

            puVar4[iVar6 + 0x40] = 0;

          }

        }

        if (puVar4[0x7a] != 0) {

          uVar3 = FUN_00318b70();

          FUN_004cb590(uVar3);

          FUN_003174e0(puVar4[0x7a]);

          puVar4[0x7a] = 0;

        }

        FUN_005225a8(0x6a2c20,uVar2);

        break;

      case 2:

        uVar2 = puVar4[0x46];

        FUN_003174e0(uVar2);

        puVar4[0x46] = 0;

        FUN_005225a8(0x6a2c20,uVar2);

        break;

      case 3:

        uVar2 = puVar4[0x4a];

        FUN_00195020(puVar4[0x7a]);

        puVar4[0x7a] = 0;

        puVar4[0x7c] = 0;

        FUN_003174e0(uVar2);

        puVar4[0x4a] = 0;

        for (iVar6 = 0; iVar6 < 3; iVar6 = iVar6 + 1) {

          if (puVar4[iVar6 + 0x40] != 0) {

            FUN_0034fcf0();

            puVar4[iVar6 + 0x40] = 0;

          }

        }

        if (puVar4[0x80] != 0) {

          (*DAT_0096017c_abs)();

        }

        if (puVar4[0x82] != 0) {

          (*DAT_0096017c_abs)();

        }

        if (puVar4[0x7b] != 0) {

          FUN_003174e0();

          puVar4[0x7b] = 0;

        }

        FUN_005225a8(0x6a2c20,uVar2);

        break;

      case 4:

      case 5:

        break;

      case 6:

        if (puVar4[0x41] != 0) {

          FUN_0034fcf0();

          puVar4[0x41] = 0;

          FUN_005225a8(0x6a2c40,resource);

        }

        break;

      case 7:

      case 8:

      case 9:

        break;

      case 10:

        uVar2 = puVar4[0x41];

        FUN_003174e0(uVar2);

        puVar4[0x41] = 0;

        if (puVar4[0x4b] != 0) {

          FUN_003174e0();

          puVar4[0x4b] = 0;

        }

        FUN_005225a8(0x6a2c60,uVar2);

        break;

      case 0xb:

        if (puVar4[0x41] != 0) {

          FUN_0034fcf0();

          puVar4[0x41] = 0;

          FUN_005225a8(0x6a2c80,resource);

        }

        break;

      case 0xc:

        if (puVar4[0x58] != 0) {

          FUN_001b3c90();

          puVar4[0x58] = 0;

          FUN_005225a8(0x6a2ca0,resource);

        }

        break;

      case 0xd:

      case 0x15:

        FUN_005225a8(0x6a2cc0,resource);

        break;

      case 0xe:

      case 0xf:

      case 0x10:

        FUN_005225a8(0x6a2ce0,resource);

        break;

      case 0x11:

      case 0x12:

      case 0x13:

        break;

      case 0x14:

        FUN_004c3880(puVar4[0x42]);

        FUN_005225a8(0x6a2d00,resource);

      }
      FUN_003b5360(scene,resource);
    }
  }
  return;
}
#pragma pop
#pragma opt_loop_invariants reset
#define FUN_003b7090(...) ((void (*)(...))FUN_003b7090)(__VA_ARGS__)
#undef FUN_003b7460
/* Measured W389: opt_lifetimes on, with/without nd 648/642, object 1104/1104 (window 1104). */
#pragma push
#pragma opt_lifetimes on
/* W415 probes: RwV3d/byte-vector rewrites exceeded the 1104-byte window (1156/1116); retained explicit aggregate layout. */
/* W420 negative: caching the DAT_006a2d20/30/40/50_abs base through a local pointer left nd 643, object 1104/1104 (window 1104), rate 0.582428 unchanged. */
/* W420 negative: changing the stack vector z field to f32 emitted an oversized 1160-byte object and nd701 against the 1104-byte window; reverted. */
// FUN_003B7460 NONMATCHING
void FUN_003b7460(u8 *param_1, RwV3d *param_2, RwV3d *param_3, RwV3d *param_4)
{
    void *model;
    struct {
        u64 xy;
        u32 z;
        u32 pad;
    } stackVec[4];
    u32 auStack_30[8];
    u32 auStack_70[16];
    u32 *src;
    u32 *dst;
    u32 value0;
    u32 value1;
    s32 type;
    s32 i;

    stackVec[0].xy = *(u64 *)DAT_006a2d20_abs;
    stackVec[0].z = *(u32 *)(DAT_006a2d20_abs + 8);
    stackVec[1].xy = *(u64 *)DAT_006a2d30_abs;
    stackVec[1].z = *(u32 *)(DAT_006a2d30_abs + 8);
    stackVec[2].xy = *(u64 *)DAT_006a2d40_abs;
    stackVec[2].z = *(u32 *)(DAT_006a2d40_abs + 8);
    stackVec[3].xy = *(u64 *)DAT_006a2d50_abs;
    stackVec[3].z = *(u32 *)(DAT_006a2d50_abs + 8);

    if (param_1 != 0) {
        if (param_2 != 0) {
            *(RwV3d *)(param_1 + 4) = *param_2;
        }
        if (param_3 != 0) {
            *(RwV3d *)(param_1 + 0x10) = *param_3;
        }
        if (param_4 != 0) {
            *(RwV3d *)(param_1 + 0x1c) = *param_4;
        }
        stackVec[3].xy = *(u64 *)(param_1 + 0x1c);
        stackVec[3].z = *(u32 *)(param_1 + 0x24);

        type = (s32)(*(u16 *)param_1 & 0xffc00) >> 10;
        if (type == 10) {
            model = *(void **)(param_1 + 0x104);
            if (model == 0) {
                FUN_005225a8(0x6a2d60);
            } else {
                FUN_00318a50_typed(model, (RwV3d *)&stackVec[0].xy, *(f32 *)(param_1 + 0x14), 0);
                FUN_00318a50_typed(model, (RwV3d *)&stackVec[1].xy, *(f32 *)(param_1 + 0x10), 1);
                FUN_00318a50_typed(model, (RwV3d *)&stackVec[2].xy, *(f32 *)(param_1 + 0x18), 1);
                FUN_00318a90_typed(model, (RwV3d *)&stackVec[3].xy, 2);
                FUN_00318a30_typed(model, (RwV3d *)(param_1 + 4), 2);
            }
        } else if (type == 6) {
            model = *(void **)(param_1 + 0x104);
            if (model == 0) {
                FUN_005225a8(0x6a2d80);
            } else {
                FUN_003b79a0_typed(auStack_30, (u64)(param_1 + 4), (u32 *)(param_1 + 0x10));
                src = auStack_30;
                dst = auStack_70;
                for (i = 8; i > 0; i--) {
                    value0 = src[0];
                    value1 = src[1];
                    src += 2;
                    dst[0] = value0;
                    dst[1] = value1;
                    dst += 2;
                }
                FUN_0034fe80(model, auStack_70);
            }
        } else if (type == 3) {
            model = *(void **)(param_1 + 0x128);
            if (model == 0) {
                FUN_005225a8(0x6a2d60);
            } else {
                FUN_00318a50_typed(model, (RwV3d *)&stackVec[0].xy, *(f32 *)(param_1 + 0x14), 0);
                FUN_00318a50_typed(model, (RwV3d *)&stackVec[1].xy, *(f32 *)(param_1 + 0x10), 1);
                FUN_00318a50_typed(model, (RwV3d *)&stackVec[2].xy, *(f32 *)(param_1 + 0x18), 1);
                FUN_00318a90_typed(model, (RwV3d *)&stackVec[3].xy, 2);
                FUN_00318a30_typed(model, (RwV3d *)(param_1 + 4), 2);
            }
        } else if (type == 2) {
            model = *(void **)(param_1 + 0x118);
            if (model == 0) {
                FUN_005225a8(0x6a2d60);
            } else {
                FUN_00318a50_typed(model, (RwV3d *)&stackVec[0].xy, *(f32 *)(param_1 + 0x14), 0);
                FUN_00318a50_typed(model, (RwV3d *)&stackVec[1].xy, *(f32 *)(param_1 + 0x10), 1);
                FUN_00318a50_typed(model, (RwV3d *)&stackVec[2].xy, *(f32 *)(param_1 + 0x18), 1);
                FUN_00318a90_typed(model, (RwV3d *)&stackVec[3].xy, 2);
                FUN_00318a30_typed(model, (RwV3d *)(param_1 + 4), 2);
            }
        } else if (type == 1) {
            model = *(void **)(param_1 + 0x128);
            if (model == 0) {
                FUN_005225a8(0x6a2d60);
            } else {
                FUN_00318a50_typed(model, (RwV3d *)&stackVec[0].xy, *(f32 *)(param_1 + 0x14), 0);
                FUN_00318a50_typed(model, (RwV3d *)&stackVec[1].xy, *(f32 *)(param_1 + 0x10), 1);
                FUN_00318a50_typed(model, (RwV3d *)&stackVec[2].xy, *(f32 *)(param_1 + 0x18), 1);
                FUN_00318a90_typed(model, (RwV3d *)&stackVec[3].xy, 2);
                FUN_00318a30_typed(model, (RwV3d *)(param_1 + 4), 2);
            }
        }
    }
}
#pragma pop
#pragma opt_lifetimes reset
#undef FUN_003b7460
#undef FUN_003b78b0
// FUN_003B78B0


void FUN_003b78b0(u64 param_1,RwV3d *param_2,RwV3d *param_3)



{

  u8 *lVar1;
  extern u8 *FUN_003b54c0(int, u64);

  

  if (*(int *)(PTR_DAT_007cd540 + 8) == 0) {

    lVar1 = 0;

  }

  else {

    lVar1 = FUN_003b54c0(*(int *)(PTR_DAT_007cd540 + 8),param_1);

  }

  if (lVar1 != 0) {

    FUN_003b7460(lVar1,param_2,param_3,0);

  }

  return;

}
#define FUN_003b78b0(...) ((void (*)(...))FUN_003b78b0)(__VA_ARGS__)
#undef FUN_003b7930
// FUN_003B7930


void FUN_003b7930(u64 param_1,RwV3d *param_2)



{

  u8 *lVar1;
  extern u8 *FUN_003b54c0(int, u64);

  

  if (*(int *)(PTR_DAT_007cd540 + 8) == 0) {

    lVar1 = 0;

  }

  else {

    lVar1 = FUN_003b54c0(*(int *)(PTR_DAT_007cd540 + 8),param_1);

  }

  if (lVar1 != 0) {

    FUN_003b7460(lVar1,0,0,param_2);

  }

  return;

}
#define FUN_003b7460(...) ((void (*)(...))FUN_003b7460)(__VA_ARGS__)
#define FUN_003b7930(...) ((void (*)(...))FUN_003b7930)(__VA_ARGS__)
#undef FUN_003b79a0
// FUN_003B79A0


void FUN_003b79a0(u32 *param_1, u64 param_2, u32 *param_3)
{
    u32 uVar1;
    u32 uVar2;
    float *pfParam3;
    u32 *puVar4;
    int iVar3;
    u32 auStack_40[16];

    auStack_40[10] = 0x3f800000;
    auStack_40[5] = 0x3f800000;
    auStack_40[0] = 0x3f800000;
    auStack_40[4] = 0;
    auStack_40[2] = 0;
    auStack_40[1] = 0;
    auStack_40[9] = 0;
    auStack_40[8] = 0;
    auStack_40[6] = 0;
    auStack_40[14] = 0;
    auStack_40[13] = 0;
    auStack_40[12] = 0;
    auStack_40[3] = auStack_40[3] | 0x20003;

    pfParam3 = (float*)param_3;
    FUN_004c31b0_mtScene((RwMatrix*)auStack_40, (const RwV3d*)D_006A2A70, pfParam3[1], 1);
    FUN_004c31b0_mtScene((RwMatrix*)auStack_40, (const RwV3d*)D_006A2A60, pfParam3[0], 1);
    FUN_004c31b0_mtScene((RwMatrix*)auStack_40, (const RwV3d*)D_006A2A80, pfParam3[2], 1);
    FUN_004c35d0_mtScene((RwMatrix*)auStack_40, param_2, 2);

    puVar4 = auStack_40;
    iVar3 = 8;
    do
    {
        uVar1 = *puVar4;
        uVar2 = puVar4[1];
        puVar4 = puVar4 + 2;
        iVar3 = iVar3 + -1;
        *param_1 = uVar1;
        param_1[1] = uVar2;
        param_1 = param_1 + 2;
    } while (0 < iVar3);

    return;
}
#undef FUN_003b7ac0
/* Measured W389: opt_dead_assignments off, with/without nd 942/940, object 1868/1868 (window 1872). W420 integer-first FUN_004c31b0 arguments plus angle declaration order angle2, angle1, angle3: nd 940/object 1868/1872 (rate 0.503212) -> nd 913/object 1868/1872 (rate 0.488758; retained). */
#pragma push
#pragma opt_dead_assignments off
// FUN_003B7AC0 NONMATCHING


void FUN_003b7ac0(u32 *param_1,float *param_2,u32 *param_3)
{
  u32 *src;
  u32 *dst;
  RwV3d *right;
  RwV3d *up;
  RwV3d *at;
  int count;
  float angle2;

  float angle1;

  float angle3;
  RwMatrix inputMatrix;
  RwMatrix rotationMatrix;
  RwMatrix rotationRwMatrix;
  RwMatrix transformedMatrix;
  RwMatrix rotationMatrix2;
  RwMatrix rotationRwMatrix2;
  RwMatrix transformedMatrix2;
  RwV3d axis;
  RwV3d normalized;
  RwV3d cross;
  RwMatrix finalMatrix;
  RwV3d crossNormalized;
  RwV3d difference;
  RwV3d transformedAt;
  RwV3d transformedDifference;
  RwV3d worldAxis;
  RwV3d finalAt;
  RwV3d finalDifference;

  src = param_1;
  dst = (u32 *)&inputMatrix;
  count = 8;
  do {
    dst[0] = src[0];
    dst[1] = src[1];
    src += 2;
    dst += 2;
    count--;
  } while (count > 0);

  param_3[0] = *(u32 *)&inputMatrix.pos.x;
  param_3[1] = *(u32 *)&inputMatrix.pos.y;
  param_3[2] = *(u32 *)&inputMatrix.pos.z;
  inputMatrix.pos.x = 0.0f;
  inputMatrix.pos.y = 0.0f;
  inputMatrix.pos.z = 0.0f;
  right = &inputMatrix.right;
  up = &inputMatrix.up;
  at = &inputMatrix.at;

  axis.x = 0.0f;
  axis.y = 1.0f;
  axis.z = 0.0f;
  normalized = axis;
  if (FUN_004c69f0_mt_scene(&axis.x, &normalized.x) == 0.0f) {
    FUN_0019d3f0("mt_scene.c", 0x5f5);
  }
  cross.x = at->y * axis.z - at->z * axis.y;
  cross.y = at->z * axis.x - at->x * axis.z;
  cross.z = at->x * axis.y - at->y * axis.x;
  normalized = cross;
  if (FUN_004c69f0_mt_scene(&cross.x, &normalized.x) == 0.0f) {
    FUN_0019d3f0("mt_scene.c", 0x5f9);
  }
  crossNormalized.x = cross.y * at->z - cross.z * at->y;
  crossNormalized.y = cross.z * at->x - cross.x * at->z;
  crossNormalized.z = cross.x * at->y - cross.y * at->x;
  normalized = crossNormalized;
  if (FUN_004c69f0_mt_scene(&crossNormalized.x, &normalized.x) == 0.0f) {
    FUN_0019d3f0("mt_scene.c", 0x5fd);
  }
  normalized = crossNormalized;

  difference.x = up->x - normalized.x;
  difference.y = up->y - normalized.y;
  difference.z = up->z - normalized.z;
  if (FUN_004c6ac0_mt_scene(&difference.x) <= DAT_007caf24) {
    angle1 = 0.0f;
  } else {
    angle1 = FUN_0052e9e8_mt_scene(up->z * normalized.z +
                                  up->x * normalized.x +
                                  up->y * normalized.y);
    angle1 = DAT_007caf34 * angle1;
  }
  if (right->y < 0.0f) {
    angle1 *= -1.0f;
  }

  rotationMatrix.right.x = 1.0f;
  rotationMatrix.up.y = 1.0f;
  rotationMatrix.at.z = 1.0f;
  rotationMatrix.up.x = 0.0f;
  rotationMatrix.right.z = 0.0f;
  rotationMatrix.right.y = 0.0f;
  rotationMatrix.at.y = 0.0f;
  rotationMatrix.at.x = 0.0f;
  rotationMatrix.up.z = 0.0f;
  rotationMatrix.pos.z = 0.0f;
  rotationMatrix.pos.y = 0.0f;
  rotationMatrix.pos.x = 0.0f;
  rotationMatrix.flags |= rwMATRIXTYPEORTHONORMAL | rwMATRIXINTERNALIDENTITY;
  FUN_004c31b0_mt_scene_f32(&rotationMatrix, 0x6a2a80, angle1, 1);
  FUN_004c32a0(&rotationRwMatrix, &rotationMatrix);
  FUN_004c2f30(&transformedMatrix, &rotationRwMatrix, &inputMatrix);

  axis.x = transformedMatrix.at.x;
  axis.y = 0.0f;
  axis.z = transformedMatrix.at.z;
  normalized = axis;
  if (FUN_004c69f0_mt_scene(&axis.x, &normalized.x) == 0.0f) {
    FUN_0019d3f0("mt_scene.c", 0x633);
  }
  transformedAt = transformedMatrix.at;
  normalized = transformedAt;
  if (FUN_004c69f0_mt_scene(&transformedAt.x, &normalized.x) == 0.0f) {
    FUN_0019d3f0("mt_scene.c", 0x637);
  }
  transformedDifference.x = transformedAt.x - axis.x;
  transformedDifference.y = transformedAt.y - axis.y;
  transformedDifference.z = transformedAt.z - axis.z;
  if (FUN_004c6ac0_mt_scene(&transformedDifference.x) <= DAT_007caf24) {
    angle2 = 0.0f;
  } else {
    angle2 = FUN_0052e9e8_mt_scene(transformedAt.z * axis.z +
                                  transformedAt.x * axis.x +
                                  transformedAt.y * axis.y);
    angle2 = DAT_007caf34 * angle2;
  }
  if (transformedMatrix.at.y > 0.0f) {
    angle2 *= -1.0f;
  }

  rotationMatrix2.right.x = 1.0f;
  rotationMatrix2.up.y = 1.0f;
  rotationMatrix2.at.z = 1.0f;
  rotationMatrix2.up.x = 0.0f;
  rotationMatrix2.right.z = 0.0f;
  rotationMatrix2.right.y = 0.0f;
  rotationMatrix2.at.y = 0.0f;
  rotationMatrix2.at.x = 0.0f;
  rotationMatrix2.up.z = 0.0f;
  rotationMatrix2.pos.z = 0.0f;
  rotationMatrix2.pos.y = 0.0f;
  rotationMatrix2.pos.x = 0.0f;
  rotationMatrix2.flags |= rwMATRIXTYPEORTHONORMAL | rwMATRIXINTERNALIDENTITY;
  FUN_004c31b0_mt_scene_f32(&rotationMatrix2, 0x6a2a80, angle1, 1);
  FUN_004c32a0(&rotationRwMatrix2, &rotationMatrix2);
  FUN_004c2f30(&transformedMatrix2, &rotationRwMatrix2, &inputMatrix);

  rotationMatrix2.right.x = 1.0f;
  rotationMatrix2.up.y = 1.0f;
  rotationMatrix2.at.z = 1.0f;
  rotationMatrix2.up.x = 0.0f;
  rotationMatrix2.right.z = 0.0f;
  rotationMatrix2.right.y = 0.0f;
  rotationMatrix2.at.y = 0.0f;
  rotationMatrix2.at.x = 0.0f;
  rotationMatrix2.up.z = 0.0f;
  rotationMatrix2.pos.z = 0.0f;
  rotationMatrix2.pos.y = 0.0f;
  rotationMatrix2.pos.x = 0.0f;
  rotationMatrix2.flags |= rwMATRIXTYPEORTHONORMAL | rwMATRIXINTERNALIDENTITY;
  FUN_004c31b0_mt_scene_f32(&rotationMatrix2, 0x6a2a60, angle2, 1);
  FUN_004c32a0(&rotationRwMatrix2, &rotationMatrix2);
  FUN_004c2f30(&finalMatrix, &rotationRwMatrix2, &transformedMatrix2);

  worldAxis.x = 0.0f;
  worldAxis.y = 0.0f;
  worldAxis.z = 1.0f;
  normalized = worldAxis;
  if (FUN_004c69f0_mt_scene(&worldAxis.x, &normalized.x) == 0.0f) {
    FUN_0019d3f0("mt_scene.c", 0x669);
  }
  finalAt = finalMatrix.at;
  normalized = finalAt;
  if (FUN_004c69f0_mt_scene(&finalAt.x, &normalized.x) == 0.0f) {
    FUN_0019d3f0("mt_scene.c", 0x66d);
  }
  finalDifference.x = finalAt.x - worldAxis.x;
  finalDifference.y = finalAt.y - worldAxis.y;
  finalDifference.z = finalAt.z - worldAxis.z;
  if (FUN_004c6ac0_mt_scene(&finalDifference.x) <= DAT_007caf24) {
    angle3 = 0.0f;
  } else {
    angle3 = FUN_0052e9e8_mt_scene(finalAt.z * worldAxis.z +
                                  finalAt.x * worldAxis.x +
                                  finalAt.y * worldAxis.y);
    angle3 = DAT_007caf34 * angle3;
  }
  if (finalAt.x < 0.0f) {
    angle3 = 360.0f - angle3;
  }

  param_2[0] = angle2;
  param_2[1] = angle3;
  param_2[2] = angle1;
}
#pragma pop
#pragma opt_dead_assignments reset
#define FUN_003b7ac0(...) ((void (*)(...))FUN_003b7ac0)(__VA_ARGS__)
#undef FUN_003b8210
// FUN_003B8210


u32 FUN_003b8210(int param_1)



{

  int *piVar1;

  int iVar2;

  u32 uVar3;

  

  piVar1 = *(int **)(param_1 + 0x3c);

  iVar2 = *piVar1;

  *piVar1 = iVar2 + -1;

  if (iVar2 + -1 < 0) {

    FUN_0034fcf0(piVar1[1]);

    piVar1[1] = 0;

    uVar3 = 0xffffffff;

  }

  else {

    uVar3 = 0;

  }

  return uVar3;

}
#define FUN_003b8210(...) ((u32 (*)(...))FUN_003b8210)(__VA_ARGS__)
#undef FUN_003b8270
// FUN_003B8270


void FUN_003b8270(int param_1)



{

  int iVar1;
  u32 uVar2;

  

  iVar1 = *(int *)(param_1 + 0x3c);
  uVar2 = *(u32 *)(iVar1 + 4);

  if (uVar2 != 0) {

    FUN_0034fcf0(uVar2);

    *(u32 *)(iVar1 + 4) = 0;

  }

  ((code*)0x0096017c)[0](iVar1);

  return;

}
#define FUN_003b8270(...) ((void (*)(...))FUN_003b8270)(__VA_ARGS__)
#undef FUN_003b82c0
// FUN_003B82C0
u32 FUN_003b82c0(Resrc* res, int param_2)
{
    if (res == NULL)
    {
        return 0;
    }

    if (param_2 == 1)
    {
        res->flags |= 8;
    }
    else
    {
        res->flags &= ~8;
    }

    return 1;
}
#define FUN_003b82c0(...) ((u32 (*)(...))FUN_003b82c0)(__VA_ARGS__)
#undef FUN_003b8310
// FUN_003B8310
u32 FUN_003b8310(u16 resTypeId, int param_2)
{
    Resrc* res;

    res = MT_Scene_GetRes(resTypeId);
    if (res == NULL)
    {
        return 0;
    }
    else if (res == NULL)
    {
        return 0;
    }
    else
    {
        if (param_2 == 1)
        {
            res->flags |= 8;
        }
        else
        {
            res->flags &= ~8;
        }

        return 1;
    }
}
#define FUN_003b8310(...) ((u32 (*)(...))FUN_003b8310)(__VA_ARGS__)
#undef FUN_003b83a0
// FUN_003B83A0


u8 FUN_003b83a0(Resrc* param_1)



{
    if (param_1 == NULL)
    {
        return 0;
    }

    return (param_1->flags & 8) != 0;
}
#define FUN_003b83a0(...) ((u8 (*)(...))FUN_003b83a0)(__VA_ARGS__)
#undef FUN_003b83d0
// FUN_003B83D0
void FUN_003b83d0(u32 param_1)
{
    s32 i;
    Resrc* currRes;
    Resrc* res;

    for (i = 1; i < RESRC_TYPE_MAX; i++)
    {
        for (currRes = MT_Scene_GetResListHead(i); currRes != NULL; currRes = currRes->next)
        {
            res = MT_Scene_GetRes(currRes->resTypeId);
            if ((res != NULL) && (res != NULL))
            {
                res->flags |= 0x20;
                *(u32*)((u8*)res + 0xf4) = param_1;
            }
        }
    }
}
#undef FUN_003b7460
#undef FUN_003b8470
// FUN_003B8470
u32 FUN_003b8470(u16 param_1,u16 param_2)
{
    Resrc* res1;
    Resrc* res2;
    RwV3d* dst;
    RwV3d* src;
    u32 result;

    res1 = MT_Scene_GetRes(param_1);
    if (res1 == NULL)
    {
        result = 0;
    }
    else
    {
        res2 = MT_Scene_GetRes(param_2);
        if (res2 == NULL)
        {
            result = 0;
        }
        else if (res1 == NULL)
        {
            result = 0;
        }
        else if (res2 == NULL)
        {
            result = 0;
        }
        else
        {
            dst = (RwV3d*)((u8*)res1 + 4);
            src = (RwV3d*)((u8*)res2 + 4);
            *dst = *src;
            {
                extern void FUN_003b7460(Resrc*, RwV3d*, long, long);
                FUN_003b7460(res1, dst, 0, 0);
            }
            result = 1;
        }
    }

    return result;
}
#define FUN_003b8470(...) ((u32 (*)(...))FUN_003b8470)(__VA_ARGS__)
#undef FUN_003b8540
/* Measured W389: opt_common_subs off + opt_lifetimes on, with/without nd 197/190, object 312/308 (window 336). */
/* W418 negative: changing the FUN_003b8540 stack assignment from 0.0 to 0.0f produced no metric changes; reverted. */
#pragma push
#pragma opt_common_subs off
#pragma opt_lifetimes on
// FUN_003B8540 NONMATCHING


u32 FUN_003b8540(float *param_1,float *param_2,float *param_3,float *param_4)



{

  u32 uVar1;

  u32 uVar2;

  float fVar3;

  float fVar4;

  float fStack_30;

  float fStack_2c;

  float afStack_20 [4];

  float fStack_10;

  float fStack_c;

  float fStack_8;

  

  fVar4 = DAT_006a2dd0;

  uVar2 = DAT_006a2dc8;

  fStack_10 = *param_2 - *param_1;

  fStack_c = param_2[1] - param_1[1];

  fStack_8 = param_2[2] - param_1[2];

  fVar3 = FUN_004c69f0_mt_scene(afStack_20,&fStack_10);

  if (fVar3 == 0.0f) {

    uVar1 = 0;

  }

  else {

    afStack_20[1] = 0.0;

    fStack_30 = *(float *)&uVar2;

    fStack_2c = *(((float *)&uVar2) + 1);

    uVar2 = FUN_00530da0_mt_scene(afStack_20[2] * fVar4 +

                         afStack_20[0] * fStack_30 + fStack_2c * 0.0f + 0.0f + 0.0f);

    uVar2 = FUN_0052e9a0(uVar2);

    fVar4 = FUN_005318a0_mt_scene((u32)uVar2);

    fVar4 = DAT_007caf18 * fVar4;

    if (afStack_20[0] < 0.0f) {

      fVar4 = fVar4 * -1.0f;

    }

    *param_4 = fVar4;

    *param_3 = fStack_10;

    param_3[1] = fStack_c;

    param_3[2] = fStack_8;

    uVar1 = 1;

  }

  return uVar1;

}
#pragma pop
#pragma opt_lifetimes reset
#pragma opt_common_subs reset
#undef FUN_003b8540
#undef FUN_003b8690
// FUN_003B8690


u32 FUN_003b8690(float *param_1,float *param_2,float *param_3)
{
    float auStack_10[4];

    return FUN_003b8540(param_1,param_2,auStack_10,param_3);
}
#define FUN_003b8690(...) ((u32 (*)(...))FUN_003b8690)(__VA_ARGS__)
#undef FUN_003b86c0
// FUN_003B86C0
u8 FUN_003b86c0(float param_1,Resrc* param_2,RwV3d* param_3)
{
    RwV3d* base;
    RwV3d* dest;

    if (param_2 == NULL)
    {
        return 0;
    }

    param_2->flags |= 1;
    param_2->flags &= ~0x40;

    base = (RwV3d*)((u8*)param_2 + 4);
    dest = (RwV3d*)((u8*)param_2 + 0x2c);
    *dest = *base;
    dest = (RwV3d*)((u8*)param_2 + 0x38);
    *dest = *param_3;

    *(float*)((u8*)param_2 + 0x58) = param_1;
    *(u8*)((u8*)param_2 + 0x50) = 0;
    return 1;
}
#define FUN_003b86c0(...) ((u8 (*)(...))FUN_003b86c0)(__VA_ARGS__)
#undef FUN_003b8730
// FUN_003B8730
u32 FUN_003b8730(u16 param_1,RwV3d* param_2,float param_3)
{
    Resrc* res;
    RwV3d* base;
    RwV3d* dest;
    u32 result;

    res = MT_Scene_GetRes(param_1);
    if (res == NULL)
    {
        result = 0;
    }
    else if (res == NULL)
    {
        result = 0;
    }
    else
    {
        res->flags |= 1;
        res->flags &= ~0x40;

        base = (RwV3d*)((u8*)res + 4);
        dest = (RwV3d*)((u8*)res + 0x2c);
        *dest = *base;
        dest = (RwV3d*)((u8*)res + 0x38);
        *dest = *param_2;

        *(float*)((u8*)res + 0x58) = param_3;
        *(u8*)((u8*)res + 0x50) = 0;
        result = 1;
    }

    return result;
}
#define FUN_003b8730(...) ((u32 (*)(...))FUN_003b8730)(__VA_ARGS__)
#undef FUN_003b87f0
// FUN_003B87F0


u32 FUN_003b87f0(u64 param_1,RwV3d *param_2,u32 param_3,u8 param_4)
{
    Resrc* res;
    RwV3d* base;
    RwV3d* dest;
    u32 result;

    res = FUN_003b5d10_typed();
    if (res == NULL)
    {
        return 0;
    }
    if (res == NULL)
    {
        result = 0;
    }
    else
    {
        res->flags |= 1;
        res->flags &= ~0x40;

        base = (RwV3d*)((u8*)res + 4);
        dest = (RwV3d*)((u8*)res + 0x2c);
        *dest = *base;
        dest = (RwV3d*)((u8*)res + 0x38);
        *dest = *param_2;

        *(u32*)((u8*)res + 0x60) = param_3;
        *(u8*)((u8*)res + 0x50) = 1;
        *(u8*)((u8*)res + 0x51) = param_4;
        *(u32*)((u8*)res + 0x5c) = 0;
        result = 1;
    }

    return result;
}
#define FUN_003b87f0(...) ((u32 (*)(...))FUN_003b87f0)(__VA_ARGS__)
