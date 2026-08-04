#include "Kosaka/Field/k_dungeon.h"
#include "Kosaka/k_data.h"
#include "Kosaka/Field/k_field.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Main/g_data.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "Graphics/Model/mdlManager.h"
#include "rw/rwplcore.h"
#include "temporary.h"
#include "h_cdvd.h"
#include "Main/admini.h"
#include "Kosaka/k_sequence.h"
#include "Kosaka/Field/k_unit.h"
#include "Script/scrTraceCode.h"

#pragma alias K_Scene_001a0250_y2 K_Scene_001a0250
#pragma alias func_001a02c0_y2 func_001a02c0
#pragma alias K_FldDungeon_GetCurrentFloor_y2 K_FldDungeon_GetCurrentFloor
#pragma alias MT_Scene_GetResListHead_y2 MT_Scene_GetResListHead
#pragma alias adminiGetNextSeqId_y2 adminiGetNextSeqId
#pragma alias D_006833C0_y2 D_006833C0_y2
#pragma alias D_0086E580_y2 D_0086E580_y2
#pragma alias kwlnGetMainCamera_y2 kwlnGetMainCamera_y2
#pragma alias kwlnTaskDestroyWithHierarchy_y2 kwlnTaskDestroyWithHierarchy_y2
#pragma alias kwlnTaskExists_y2 kwlnTaskExists_y2
#pragma alias K_FldDungeon_RequestShutdown_y2 K_FldDungeon_RequestShutdown_y2
#pragma alias FUN_001c1f30_y2 FUN_001c1f30_y2
#pragma alias func_001bf340_y2 func_001bf340_y2


KwlnTask* gDungeonTask; // 007ce268. NULL when not in tartarus. Task name = "automatic dungeon"
Model* gDungeonTpMdl;   // 007ce280. FOBJ000.RMD, model for the teleport pad. Maybe a cache ?

#define DUNGEON_GET_WORK() ((FldDungeon*)gDungeonTask->workData)

static HCdvd* sDngBtlEffectCdvd; // 007ce258. field/btl_effect/btl_eff.pac

extern void* D_0086BDC0[];
extern u32 D_0086E580[];
extern u32 D_0086E694[];
extern u32 D_006833C0[];
extern void* DAT_0096017c[];
extern void* DAT_00960184[];

HCdvd* K_FldDungeon_RequestScript(void);
void K_FldDungeon_DestroyScrMemory(void);
u32 K_FldDungeon_CreateScrMemory(HCdvd* scrCdvd);
void K_FldDungeon_FUN_001c03f0(void);

s32 func_001bf340(FldDungeonFloorData* floorData);
u32 func_001c0440(void);
u32 func_001c0740(void);
void func_001c07f0(void);
KwlnTask* func_001a9080(KwlnTask* parentTask, const char* path, s32 param_3, HCdvd* cdvd);
u32 func_001a9180(KwlnTask* eplTask);
s32 func_001a91b0(KwlnTask* eplTask, void* data);
KwlnTask* func_001ba5f0(KwlnTask* parentTask, u16 majorId, u16 minorId, u16 param_4,
                         u16 param_5, u16 param_6, u32 flags, u8 param_8, u8 param_9,
                         s16 param_10, s32 param_11, s32 param_12, s32 param_13,
                         s32 param_14);
void func_001baa50(KwlnTask* fldRootTask, u32 enabled);
KwlnTask* func_00447e70(KwlnTask* parentTask, u8 param_2, u8 param_3);
void func_001b3c90(void* resource);

extern void func_001d4180(void);
extern void* func_001a9470(void* resource);
extern void* func_00195020(void* task);
extern void* func_001ad050(void* clump, const RwV4d* center,
                           const RwV3d* extents, void* result);
extern f32 K_FldFrame_CtlGetSphereCollisRadius(KwlnTask* collisCtlTask);
extern void K_FldFrame_CtlCopyPos(RwV3d* dst, KwlnTask* collisCtlTask);
extern void* func_001ad220(void* object, const RwV3d* point, void* result);
extern void* func_00198590(void);
extern RwMatrix* func_004cb2f0(void* camera);
extern void func_004c69f0(RwV3d* out, const RwV3d* in);
extern void* func_00318b00(void* model);
extern void* func_00318b80(void* model);
extern void* kwlnGetMainCamera(void);


typedef struct
{
    u32 state;
    u8 unkData[0x200];
    KwlnTask* collisionTask;
    u8 reserved[4];
} TransWallCtlWork;
typedef struct
{
    Resrc base;
    s32 unk_100;
    Model* model;
    KwlnTask* fadeTask;
    u32 fadeTimer;
    u8 unkData[0x20];
} DungeonModelFld;
typedef struct DungeonNode
{
    u8 unk_00[8];
    u32 active;
    u8 unk_0c[0x0c];
    f32 alpha;
    KwlnTask* fadeTask;
    u32 fadeTimer;
    struct DungeonNode* next;
} DungeonNode;
extern void K_FldFrame_CtlCopyPos(RwV3d* dst, KwlnTask* collisCtlTask);
extern void func_001c1e20(KwlnTask* transWallTask);
extern void func_0017f8d0(void);
extern void func_001d0270(void);
extern void func_00171b50(u32 socialLink);
extern void datSetActiveSocialLink_s16(s16 activeSocialLink);
extern u32 adminiGetNowSeqId_u32(void);
extern u32 adminiGetNextSeqId_u32(void);
typedef struct
{
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 unkData[0x12];
} FieldSequenceData;
typedef struct
{
    u8 unkData[0x0c];
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
} SocialLinkSequenceData;
#define DUNGEON_SEQUENCE_FLAG (*(u32*)((u8*)&gDungeonTask + 4)) // 007ce26c
#include "Kosaka/Field/k_event.h"
#include "rw/rprandom.h"
extern u32 DAT_008717e8;
extern u32 DAT_008717f0;
extern u32 DAT_008717f4;
extern f32 fGpffff844c;
extern f32 fGpffff8450;
extern f32 fGpffff82fc;
extern f32 fGpffff82b8;
extern f32 fGpffffb544;
extern f32 fGpffffb540;
extern u32 uGpffffb53c;
extern u8 D_0067F600[];
extern const char D_0067F5E0[];
extern const char D_0067F590[];
extern u8 D_0067F720[];
extern u8 D_0067FA26[];
extern u8 D_00681560[];
extern u8 D_00681866[];
extern u8 D_006833B0[];
extern u8 D_006833B8[];
extern u8 D_006833C0_y2[];
extern u8 D_006833A0[];
extern u8 D_0086E580_y2[];
extern u8 D_0086EDA0[];
extern u8 D_008717A0[];
extern const char D_0067F5C8[];
extern RwV3d D_0067F5B8;
extern u8 D_00869F98[];
extern u8 D_00869FA2[];
extern u8 D_00869FA3[];
extern u8 D_00869FA4[];
extern u32 FUN_00198590(void);
extern f32 FUN_001A5AA0(void* value);
extern u32 K_Scene_001a0250(void);
extern u32 func_001a02c0(void);
extern void K_Assert(const char* file, s32 line);
extern void func_0019ff10(void);
extern void* func_001b5380(u32* resource, const RwV3d* position, u32 rotation);
extern u16 func_003b6790(u16 resourceId, void* resource);
extern u16 func_003b65d0(u16 resourceId, void* model);
extern u16 func_003b66b0(u16 resourceId, void* model);
extern u32 K_Misc_FindNextFreeResId(u16 resType);
extern u16 func_003b6870(u16 resourceId, const void* position, u32 packed,
                          f32 angleX, f32 angleY, f32 angleZ);
extern void func_001e6af0(void* position, void* model,
                          f32 x, f32 y, f32 z);
extern u16 func_003b6b90(u16 resourceId, const RwV3d* position, f32 angle);
extern u16 func_003b6c50(u16 resourceId, const RwV3d* position, f32 angle);
extern u16 func_003b6d10(u16 resourceId, const RwV3d* position, f32 angle);
extern RwMatrix* func_004c38c0(void);
extern void func_004c31b0(void* object, const void* axis, f32 angle, u32 mode);
extern void func_004c6be0(void* dst, const void* src, void* object);
extern void func_004c3880(RwMatrix* matrix);
extern u32 func_001c7160(const FldUnit* enemy, const FldUnit* party, f32 distance);
extern u16 func_003b6dd0(u16 resourceId, const RwV3d* position, f32 angle);
extern u32 FUN_0016F380(u32 parameter);
extern void FUN_0016F3E0(u32 parameter, u32 value);
extern s32 DAT_007ce250;
extern s32 DAT_007ce254;
static u32 sDungeonGenerationAttempts;  // 007ce260
static u32 sDungeonGenerationFailed;    // 007ce264
static u32 sDungeonRoomCounter;         // 007ce25c
extern KwlnTask* gDungeonTask;
extern u32 D_00960184[];
extern void (*jtbl_0096017C)(void* memory);
extern u32 jtbl_0096017C_abs[];
extern RwCamera* kwlnGetMainCamera_y2(void);
extern void kwlnSetClearColor(u8 r, u8 g, u8 b, u8 a);
extern KwlnTask* kwlnTaskCreateWithAutoPriority(KwlnTask* parentTask, u32 priority,
                                                 const char* name, KwlnTaskUpdateFunc update,
                                                 KwlnTaskDestroyFunc destroy, void* workData);
extern u8 kwlnTaskDestroyWithHierarchy_y2(KwlnTask* task);
extern u32 kwlnTaskExists_y2(KwlnTask* task);
extern void K_Fldrc_RequestFldPac(s16 majorId, s16 minorId);
extern u8 K_Fldrc_IsFldPacLoaded(void);
extern void K_Fldrc_DestroyFldPac(void);
extern u32 K_FldDungeon_GetCurrentFloor(void);
extern void K_FldDungeon_RequestShutdown_y2(void);
extern void K_FldUnit_DestroyPcMdl(s32 unitId);
extern void K_FldUnit_DestroyAllPc(void);
extern void K_FldUnit_DestroyAllEc(void);
extern void MT_Scene_Load(s32 majorId, s32 minorId);
extern u32 MT_Scene_TryLoadFinish(void);
extern void MT_Scene_Destroy(void);
extern Resrc* MT_Scene_GetResListHead(u32 resType);
extern void func_001a0150(u16 resourceId, u32 visible);
extern s32 K_FldFrame_CtlGetXGrid(KwlnTask* collisCtlTask);
extern s32 K_FldFrame_CtlGetZGrid(KwlnTask* collisCtlTask);
extern void Y_TimeLimit_Stop(void);
extern void H_Fade_FadeOut(void);
extern void H_Fade_SetType(s16 type);
extern void H_Snd_StopBgmFade(s16 fadeDuration);
extern u8 func_00109f60(s16 channelIndex, s16 mappedChannelIndex);
extern s8 adminiGetNextSeqId(void);
extern void clnd00187ea0(void* task);
extern void* func_001a96c0(KwlnTask* task);
extern void func_001a0040(u32 visible, u32 updateField);
extern void func_0019fec0(const void* position);
extern void func_001cd8e0(void);
extern void func_001e7410(void);
extern void func_00350080(s32 sequence);
extern void func_003c8f70(void);
extern void func_003c8f40(void);
extern void func_00458bb0(void);
extern void func_0045a430(s32 enabled);
extern void func_0045af70(s32 enabled);
extern void func_004cb930(void* frame);
extern void func_004cb270(void* frame);
extern u32 FUN_00398060(u32 resource);
extern u32 FUN_00398140(u32 resource, s32* id, u32* minor, u32* param4, u32* param5);
extern u32 FUN_001b7d60(void);
extern u32 FUN_001b7e30(void);
extern u32 FUN_001c0440(void);
extern u32 FUN_001c0740(void);
extern u32 FUN_00398060(u32 resource);
extern u32 FUN_00398140(u32 resource, s32* id, u32* minor, u32* param4, u32* param5);
extern u32 FUN_00397ec0(s32 param1, s32 param2, s32 param3, s32 param4);
extern u32 FUN_0035bc00(s32 type, u32 list, u32 list2, s32 index);
extern u32 FUN_0035bb40(s32 type, u32 list, s32 index);
extern u32 FUN_003b5d50(u32 resType);
extern void FUN_0019d3f0(const char* file, s32 line);
extern u32 FUN_001e7200(s16 majorId);
extern u32 FUN_001e7290(u32 request, s16 majorId);
extern u32 FUN_001c7e70(s16 majorId, u16 minorId);
extern u32 FUN_001c7f20(u32 request);
extern void FUN_003b58c0(u16 value);
extern void FUN_003b5980();
extern u16 FUN_001b6eb0(s16 majorId, u16 minorId);
extern u32 FUN_00187e20(void);
extern u32 FUN_001ce960(void);
extern void FUN_001d19d0(void);
extern void FUN_001d70a0(void);
extern void FUN_001d5f30(u32 cameraTask, u32 model);
extern void FUN_001d6270(KwlnTask* task, s32 enabled, s32 value);
extern u32 FUN_003982d0(u32 resource);
extern void FUN_001a9850(void);
extern void FUN_001aa1b0(void);
extern void FUN_00187ea0(void);
extern u32 FUN_0036f3b0(KwlnTask* task, u32 resource);
extern u32 FUN_001c1f30_y2(KwlnTask* task, u32 model);
extern void FUN_0016f1f0(s32 id, s32 enabled);
extern void FUN_001d2610(void);
extern void FUN_001d1fa0(void);
extern u32 FUN_001d9f10(KwlnTask* task);
extern u32 FUN_001dd600(void);
extern u64 FUN_0018bff0(KwlnTask* task);
extern void FUN_0018c0c0(u32 object, s32 enabled);
extern u32 FUN_0018e820(KwlnTask* task);
extern void FUN_001ddca0(s64 value);
extern void FUN_0018eb30(u32 object, s32 enabled);
extern u32 FUN_004579b0(KwlnTask* task);
extern u32 FUN_00429d40(KwlnTask* task, u32 scene);
extern void FUN_004532d0(s32 enabled);
extern u32 FUN_001c03b0(u32 task);
extern u32 FUN_001d9fd0(u32 task);
extern void FUN_001da000(u32 task, s32 enabled);
extern u32 FUN_0042ba30(void);
extern u32 FUN_0018c0a0(u32 object);
extern void FUN_001dd8e0(void);
extern void FUN_001d2a10(void);
extern void FUN_00188650(void);
extern void FUN_001085c0(void);
extern void FUN_001086a0(s32 duration);
extern u32 FUN_00108710(void);
extern void FUN_0027c080(s32 type, void* data, s32 size, s32 flags);
extern void FUN_00100ec0(void);
extern u32 FUN_0036f480(void);
extern u16 FUN_0036f4c0(void);
extern void FUN_0017f8d0(void);
extern void FUN_0035bfb0(void);
extern u32 FUN_001e1230(KwlnTask* task, u32 camera, u32 model);
extern u32 FUN_001cd5a0(KwlnTask* task);
extern void FUN_004350e0(s32 enabled, s32 update);
extern void FUN_00429e80(u32 object, s32 enabled);
extern u32 FUN_001c0330(u8 blockId);
extern u32 FUN_001bffa0(void);
extern u32 FUN_001bffe0(void);
extern u32 FUN_001c0010(void);
#define FIELD_U8(address)  (*(u8*)(address))
#define FIELD_U16(address) (*(u16*)(address))
#define FIELD_U32(address) (*(u32*)(address))
#define FIELD_S32(address) (*(s32*)(address))
#define FIELD_F32(address) (*(f32*)(address))
#define ROOT_U8(work, offset)  (*(u8*)((u8*)(work) + (offset)))
#define ROOT_U16(work, offset) (*(u16*)((u8*)(work) + (offset)))
#define ROOT_U32(work, offset) (*(u32*)((u8*)(work) + (offset)))
#define ROOT_S32(work, offset) (*(s32*)((u8*)(work) + (offset)))
#define ROOT_F32(work, offset) (*(f32*)((u8*)(work) + (offset)))
#define DUNGEON_SEQUENCE_FLAG (*(u32*)((u8*)&gDungeonTask + 4))
static Field sField; // 00869f60
extern RwMatrix* FUN_00318b60(void* model);
extern u32 FUN_001d5a90(KwlnTask* task);
extern void func_001d8cb0(void);
extern u32 DAT_007ce24c;
extern u32 K_FldDungeon_GetCurrentFloor(void);
extern s16 FUN_0016DD60(s32 index);
typedef struct DungeonPattern DungeonPattern;
void func_001bb300(u16 patternId, u16 x, u16 y);
u32 func_001bc630(const DungeonPattern* pattern, s32* x, s32* y);
void func_001bcac0(u32 patternId, u32 x, u32 y, u32 fromX, u32 fromY);
void func_001bd450(u32 patternId);
void func_001bd8c0(void);
void func_001bd950(void);
void func_001bf220(RwV3d* dst, u32 x, u32 y);
u32 func_001bf340_y2(const FldDungeonFloorData* floorData);
struct DungeonPattern
{
    u8 raw[0x60];
};
static const s16 sDungeonVisibilityOffsets0[] = {
    -0xc4, -0xb4, -0xa4, 0x2c, 0x3c, 0x4c, 0x5c, 0x6c,
    0x12c, 0x13c, 0x14c, 0x15c, 0x16c, 0x22c, 0x23c,
    0x24c, 0x25c, 0x26c, 0x33c, 0x34c, 0x35c
};
static const s16 sDungeonVisibilityOffsets1[] = {
    -0xc4, -0xb4, -0xa4, 0x2c, 0x3c, 0x4c, 0x5c, 0x6c,
    0x12c, 0x13c, 0x14c, 0x15c, 0x16c, 0x22c, 0x23c,
    0x24c, 0x25c, 0x26c, 0x33c, 0x34c, 0x35c
};
static const s16 sDungeonVisibilityOffsets2[] = {
    0x34c, 0x35c, 0x23c, 0x24c, 0x25c, 0x26c, 0x13c,
    0x14c, 0x15c, 0x16c, 0x17c, 0x3c, 0x4c, 0x5c,
    0x6c, 0x7c, -0xc4, -0xb4, -0xa4, -0x94
};
static const s16 sDungeonVisibilityOffsets3[] = {
    -0xc4, 0x3c, 0x13c, -0x1b4, -0xb4, 0x4c, 0x14c,
    0x24c, -0x1a4, -0xa4, 0x5c, 0x15c, 0x25c, -0x194,
    -0x94, 0x6c, 0x16c, 0x26c, -0x84, 0x7c, 0x17c
};
static const s16 sDungeonVisibilityOffsets4[] = {
    0x13c, 0x14c, 0x15c, 0x16c, 0x3c, 0x4c, 0x5c, 0x6c,
    0x7c, -0xc4, -0xb4, -0xa4, -0x94, -0x84, -0x1c4,
    -0x1b4, -0x1a4, -0x194, -0x2b4, -0x2a4
};
static const s16 sDungeonVisibilityOffsets5[] = {
    0x34c, 0x35c, 0x25c, 0x24c, 0x23c, 0x22c, 0x15c,
    0x14c, 0x13c, 0x12c, 0x11c, 0x5c, 0x4c, 0x3c,
    0x2c, 0x1c, -0xd4, -0xc4, -0xb4, -0xa4
};
static const s16 sDungeonVisibilityOffsets6[] = {
    -0xa4, 0x5c, 0x15c, -0x1b4, -0xb4, 0x4c, 0x14c,
    0x24c, -0x1c4, -0xc4, 0x3c, 0x13c, 0x23c, -0x1d4,
    -0xd4, 0x2c, 0x12c, 0x22c, -0xe4, 0x1c, 0x11c
};
static const s16 sDungeonVisibilityOffsets7[] = {
    0x15c, 0x14c, 0x13c, 0x12c, 0x5c, 0x4c, 0x3c, 0x2c,
    0x1c, -0xa4, -0xb4, -0xc4, -0xd4, -0xe4, -0x1a4,
    -0x1b4, -0x1c4, -0x1d4, -0x2b4, -0x2a4
};

void* func_001c0880(KwlnTask* task);
void func_001c0920(KwlnTask* task);
static inline void K_Dungeon_ProcessFieldNodes(
    KwlnTask* parentTask,
    DungeonNode* node,
    const RwV4d* collisionQueryPosition,
    void* cameraFrame,
    const RwV3d* cameraDirection,
    u8* queryData,
    RwV3d* probe,
    RwV3d* special,
    u32 extendedProbes)
{
    void* camera;
    u8* fadeWork;
    KwlnTask* child;
    f32 alpha;

    while (node != NULL)
    {
        if (node->active != 0)
        {
            memset(queryData, 0, 0x208);

            probe[0] = *(RwV3d*)((u8*)cameraFrame + 0x30);
            probe[0].x += cameraDirection->x;
            probe[0].y += cameraDirection->y;
            probe[0].z += cameraDirection->z;
            func_001ad220(node, &probe[0], queryData);

            probe[1] = probe[0];
            probe[0] = *(RwV3d*)collisionQueryPosition;
            *(RwV3d*)collisionQueryPosition = probe[1];
            func_001ad220(node, &probe[0], queryData);

            probe[1] = probe[0];
            probe[0] = *(RwV3d*)collisionQueryPosition;
            *(RwV3d*)collisionQueryPosition = probe[1];
            func_001ad220(node, &probe[0], queryData);

            probe[1] = probe[0];
            probe[0] = *(RwV3d*)collisionQueryPosition;
            *(RwV3d*)collisionQueryPosition = probe[1];
            func_001ad220(node, &probe[0], queryData);

            if (extendedProbes != 0)
            {
                if (func_001a01c0() == 0)
                {
                    probe[0] = *(RwV3d*)((u8*)cameraFrame + 0x30);
                    func_001ad220(node, &probe[0], queryData);
                }

                if (gMtScene->fldMajorId == 0x23)
                {
                    camera = kwlnGetMainCamera();
                    cameraFrame = func_004cb2f0(*(void**)((u8*)camera + 4));
                    special[0] = *(RwV3d*)cameraFrame;
                    func_004c69f0(&special[0], &special[0]);
                    special[1] = special[0];
                    special[0].x *= 100.0f;
                    special[0].y *= 100.0f;
                    special[0].z *= 100.0f;
                    special[1].x *= -100.0f;
                    special[1].y *= -100.0f;
                    special[1].z *= -100.0f;
                    special[0].x += *(f32*)((u8*)cameraFrame + 0x30);
                    special[0].y += *(f32*)((u8*)cameraFrame + 0x34);
                    special[0].z += *(f32*)((u8*)cameraFrame + 0x38);
                    special[1].x += *(f32*)((u8*)cameraFrame + 0x30);
                    special[1].y += *(f32*)((u8*)cameraFrame + 0x34);
                    special[1].z += *(f32*)((u8*)cameraFrame + 0x38);
                    func_001ad220(node, &special[0], queryData);
                }
            }

            if (*(u32*)(queryData + 4) > 0)
            {
                if (node->fadeTask == NULL)
                {
                    alpha = node->alpha;
                    if (alpha == 1.0f)
                    {
                        fadeWork = (u8*)((void* (*)(u32, u32, u32))DAT_00960184[0])(
                            1, 0x14, rwMEMHINTDUR_GLOBAL);
                        child = NULL;
                        if (fadeWork != NULL)
                        {
                            child = kwlnTaskCreateWithAutoPriority(
                                parentTask, 10, "field npc alpha",
                                func_001c0880, func_001c0920, fadeWork);
                            *(DungeonNode**)(fadeWork + 4) = node;
                            *(u32*)(fadeWork + 8) = 5;
                            *(f32*)(fadeWork + 0x0c) = 0.0f;
                        }
                        node->fadeTask = child;
                        node->fadeTimer = 0;
                    }
                }
            }
            else if (node->fadeTask == NULL)
            {
                alpha = node->alpha;
                if (alpha == 0.0f)
                {
                    if (node->fadeTimer >= 0xb)
                    {
                        fadeWork = (u8*)((void* (*)(u32, u32, u32))DAT_00960184[0])(
                            1, 0x14, rwMEMHINTDUR_GLOBAL);
                        child = NULL;
                        if (fadeWork != NULL)
                        {
                            child = kwlnTaskCreateWithAutoPriority(
                                parentTask, 10, "field npc alpha",
                                func_001c0880, func_001c0920, fadeWork);
                            *(DungeonNode**)(fadeWork + 4) = node;
                            *(u32*)(fadeWork + 8) = 10;
                            *(f32*)(fadeWork + 0x0c) = 1.0f;
                        }
                        node->fadeTask = child;
                        node->fadeTimer = 0;
                    }
                    else
                    {
                        node->fadeTimer += 1;
                    }
                }
            }
        }
        node = node->next;
    }
}
static void fldRootSetLoadSlot(u8* work)
{
    u16 majorId;
    u16 minorId;

    majorId = ROOT_U16(work, 0x10);
    minorId = ROOT_U16(work, 0x12);
    if (FIELD_U32(0x0086afa8) == 0)
    {
        return;
    }

    if ((majorId < 0x14 || majorId > 0x1c || minorId < 0x32) &&
        (majorId < 0x28 || majorId > 0x30 || minorId < 0x32))
    {
        if (majorId < 0x14 || (majorId > 0x1c && majorId < 0x28) || majorId > 0x30)
        {
            ROOT_U32(work, 0x40) =
                FUN_0035bc00(10, FIELD_U32(0x0086afa8), FIELD_U32(0x0086afac),
                             (s32)minorId - 1);
        }
    }
    else
    {
        ROOT_U32(work, 0x40) =
            FUN_0035bc00(10, FIELD_U32(0x0086afa8), FIELD_U32(0x0086afac),
                         (s32)minorId - 0x32);
    }
}
static u8* dungeonCell(s32 x, s32 y)
{
    return (u8*)K_Field_Get() + y * 0x100 + x * 0x10;
}
static inline u8* dungeonPatternCell(DungeonPattern* pattern, u32 x, u32 y)
{
    return pattern->raw + y * 0x18 + x * 8;
}
static inline void dungeonCopyQuad(u8* dst, const u8* src)
{
    ((s16*)dst)[0] = ((const s16*)src)[0];
    ((s16*)dst)[1] = ((const s16*)src)[1];
    ((s16*)dst)[2] = ((const s16*)src)[2];
    ((s16*)dst)[3] = ((const s16*)src)[3];
}
static void dungeonShowResources(s32 x, s32 y, const s16* offsets, u32 count)
{
    u8* cell;
    u32 i;

    cell = dungeonCell(x, y);
    for (i = 0; i < count; i++)
    {
        func_001a0150(*(u16*)(cell + offsets[i]), 1);
    }
}

/* W417 failed probe: a switch around only the occupied test (assignment
 * left outside) was byte-identical at nd401/object612; wrapping the normal
 * assignment in case 0 and the assert/continue in default gave nd375/object620
 * and the exact 13-call order. */
/* W418 negatives: removing either/both startX/startY u16 casts was neutral at nd375/object620; changing both locals to u16 regressed nd399/object656 and exceeded the 624-byte window. */
/* W418 accepted: u8 directionLocal assigned from direction before the loops and used for cell->direction; nd375/object620 -> nd301/object624 (rate 60.48% -> 48.24%). */
// W419 accepted: swapping the independent row/col declarations reduced func_001bb090 from nd301/object624/window624 (48.24%) to nd296/object624/window624 (47.44%); no size change.
/* W419 rejected probes: direct direction was nd375/object620/window624 (60.48%), row/col plus direct direction nd376/620/624 (60.65%), u16 directionLocal nd302/624/624 (48.40%), u8 volatile directionLocal nd337/620/624 (54.35%), a direction stack store nd398/632/624 (62.97%), and a direction array nd297/624/624 (47.60%). */
/* W419 rejected start-width probes: startX u16 was nd316/object644/window624 (49.07%), startY u16 with row/col swap nd403/640/624 (62.97%), and both starts u16 nd414/660/624 (62.73%); direction pointer/deref/volatile-pointer and inert placed-local/declaration probes stayed at nd296/624/624 (47.44%) or nd301/624/624 (48.24%). A volatile direction parameter made all 46 scanned functions COMPILE_ERROR. */
// FUN_001bb090 NONMATCHING
void func_001bb090(const DungeonPattern* pattern, u16 x, u16 y, u16 direction)
{
    s32 startX;
    s32 startY;
    s32 row;
    s32 col;
    FieldDungeonCell* cell;
    const u8* patternCell;
    u8 directionLocal;

    if ((u16)x + pattern->raw[1] - 1 >= 0x10)
    {
        K_Assert((const char*)D_006833A0, 0x106);
    }
    if ((u16)y + pattern->raw[2] - 1 >= 0x10)
    {
        K_Assert((const char*)D_006833A0, 0x107);
    }

    startX = (u16)x;
    startY = (u16)y;
    directionLocal = direction;

    cell = &K_Field_Get()->dungeonCells[startY][startX];
    cell->placed = 1;
    for (row = 0; row < pattern->raw[2]; row++)
    {
        for (col = 0; col < pattern->raw[1]; col++)
        {
            cell = &K_Field_Get()->dungeonCells[startY + row][startX + col];
            switch (cell->occupied)
            {
            case 0:
                cell = &K_Field_Get()->dungeonCells[startY + row][startX + col];
                cell->occupied = 1;
                patternCell = pattern->raw + row * 0x18 + col * 8;
                cell = &K_Field_Get()->dungeonCells[startY + row][startX + col];
                cell->connections = patternCell[0x0e];
                cell = &K_Field_Get()->dungeonCells[startY + row][startX + col];
                cell->width = pattern->raw[1];
                cell = &K_Field_Get()->dungeonCells[startY + row][startX + col];
                cell->height = pattern->raw[2];
                cell = &K_Field_Get()->dungeonCells[startY + row][startX + col];
                cell->patternId = pattern->raw[0];
                cell = &K_Field_Get()->dungeonCells[startY + row][startX + col];
                cell->direction = directionLocal;
                cell = &K_Field_Get()->dungeonCells[startY + row][startX + col];
                cell->elevation = patternCell[0x0f];
                cell = &K_Field_Get()->dungeonCells[startY + row][startX + col];
                cell->roomId = sDungeonRoomCounter;
                break;
            default:
                K_Assert((const char*)D_006833A0, 0x124);
                continue;
            }
        }
    }
    sDungeonRoomCounter++;
}

#pragma opt_propagation off
// W415 census negative: adding the missing K_Field_Get before func_001b5380 (direction-expression and no-op probes) changed nd3024->3559/3561 and object4780->4788 against the 4912-byte window; the exact target call was present but the +535 nd rise for +8 bytes was non-proportional, so the probe was reverted.
// Direct census: ours omits one 0x001b9120 (K_Field_Get) immediately before
// 0x001b5380; retail has it there. Baseline 3024/4780 = 63.26% wrong;
// direction-expression probe 3559/4788 = 74.31%, no-op probe 3561/4788 =
// 74.35%. Both add 8 bytes without real code recovery, so retain baseline.
// FUN_001bb300 NONMATCHING
void func_001bb300(u16 patternId, u16 x, u16 y)
{
    u8* fieldRoot;
    FieldDungeonCell* dungeon;
    u8* source;
    u8* roomCopy;
    u8* records;
    u8* record;
    u8* modelResource;
    u8* sceneResource;
    RwV3d origin;
    RwV3d axis;
    RwV3d position0;
    RwV3d position1;
    RwV3d position2;
    RwMatrix* matrix;
    u32 row;
    u32 col;
    u32 i;
    u32 count;
    u32 version;
    u32 direction;
    u32 sourceIndex;
    s8 orientation;
    u32 resourceId;
    u16 roomResId;
    u16 ids[4];
    RwV3d position3;
    f32 angle;
    axis = *(RwV3d*)D_006833B0;

    dungeon = &K_Field_Get()->dungeonCells[y][x];
    if (dungeon->occupied == 0)
    {
        return;
    }
    dungeon = &K_Field_Get()->dungeonCells[y][x];
    if (dungeon->placed == 0)
    {
        return;
    }

    dungeon = &K_Field_Get()->dungeonCells[y][x];
    if ((s32)x + dungeon->width - 1 >= 0x10)
    {
        K_Assert((const char*)D_006833A0, 0x139);
    }
    dungeon = &K_Field_Get()->dungeonCells[y][x];
    if ((s32)y + dungeon->height - 1 >= 0x10)
    {
        K_Assert((const char*)D_006833A0, 0x13a);
    }

    origin.x = (f32)x * 800.0f +
               (f32)(K_Field_Get()->dungeonCells[y][x].width - 1) * 400.0f;
    dungeon = &K_Field_Get()->dungeonCells[y][x];
    origin.y = (f32)dungeon->elevation * 300.0f;
    origin.z = (f32)y * 800.0f +
               (f32)(K_Field_Get()->dungeonCells[y][x].height - 1) * 400.0f;

    fieldRoot = (u8*)K_Field_Get();
    dungeon = &((Field*)fieldRoot)->dungeonCells[y][x];
    sourceIndex = dungeon->patternId;
    source = *(u8**)(fieldRoot + 0x116c + sourceIndex * 4);
    dungeon = &K_Field_Get()->dungeonCells[y][x];
    direction = dungeon->direction;
    roomCopy = (u8*)func_001b5380((u32*)source, &origin, (direction + 2) & 3);
    roomResId = func_003b6790(patternId, roomCopy);
    sceneResource = (u8*)MT_Scene_GetRes(roomResId);
    func_001a0150(roomResId, 1);
    func_0019ff10();

    for (row = 0;
         row < K_Field_Get()->dungeonCells[y][x].height;
         row++)
    {
        for (col = 0;
             col < K_Field_Get()->dungeonCells[y][x].width;
             col++)
        {
            K_Field_Get()->dungeonCells[y + row][x + col].resourceId = roomResId;
        }
    }
    for (i = 0; i < *(u32*)(roomCopy + 0x118); i++)
    {
        record = roomCopy + 0x11c + i * 0x18;
        if (*(u16*)record == 0)
        {
            resourceId = K_Misc_FindNextFreeResId(RESRC_TYPE_MODELFLD);
            resourceId = MT_Scene_CreateResModelFld(
                (u16)resourceId, *(Model**)(record + 0x0c));
            modelResource = (u8*)MT_Scene_GetRes((u16)resourceId);
            *(u32*)(modelResource + 0x100) =
                *(u32*)(sceneResource + 0x100);
            *(u32*)(modelResource + 0x104) =
                *(u32*)(sceneResource + 0x104);
            *(u32*)(modelResource + 0x108) =
                *(u32*)(sceneResource + 0x108);
            *(u32*)(modelResource + 0x10c) =
                *(u32*)(sceneResource + 0x10c);
        }
        else if (*(u16*)record == 1)
        {
            resourceId = K_Misc_FindNextFreeResId(RESRC_TYPE_11);
            resourceId = func_003b66b0(
                (u16)resourceId, *(Model**)(record + 0x10));
            modelResource = (u8*)MT_Scene_GetRes((u16)resourceId);
            *(u32*)(modelResource + 0x100) =
                *(u32*)(sceneResource + 0x100);
            *(u32*)(modelResource + 0x104) =
                *(u32*)(sceneResource + 0x104);
            *(u32*)(modelResource + 0x108) =
                *(u32*)(sceneResource + 0x108);
            *(u32*)(modelResource + 0x10c) =
                *(u32*)(sceneResource + 0x10c);
        }
        else
        {
            continue;
        }
        func_001a0150((u16)resourceId, 1);
    }
    *(u32*)(roomCopy + 0x118) = 0;

    sourceIndex = K_Field_Get()->dungeonCells[y][x].patternId;
    fieldRoot = (u8*)K_Field_Get();
    source = *(u8**)(fieldRoot + 0x116c + sourceIndex * 4);
    source = *(u8**)(source + 0xa3c);
    if (source == NULL)
    {
        return;
    }
    matrix = func_004c38c0();
    sourceIndex = K_Field_Get()->dungeonCells[y][x].patternId;
    fieldRoot = (u8*)K_Field_Get();
    source = *(u8**)(fieldRoot + 0x116c + sourceIndex * 4);
    source = *(u8**)(source + 0xa3c);

    version = *(u32*)(source + 4);
    if (version == 0x1000)
    {
        records = source + 0x28;
    }
    else if (version == 0x1001)
    {
        records = source + 0x30;
    }
    else if (version == 0x1002)
    {
        records = source + 0x38;
    }
    else
    {
        records = source + 0x48;
    }

    for (i = 0, record = records;
         i < *(u32*)(source + 8);
         i++, record += 0x20)
    {
        if (K_Scene_001a0250() == 1)
        {
            resourceId = func_003b6870(*(u16*)record & 0x3ff,
                                       record + 8, *(u32*)(record + 4),
                                       *(f32*)(record + 0x14),
                                       *(f32*)(record + 0x18),
                                       *(f32*)(record + 0x1c));
            modelResource = (u8*)MT_Scene_GetRes((u16)resourceId);
            func_001e6af0(modelResource + 0x11c, modelResource + 0x104,
                          *(f32*)(modelResource + 0x110),
                          *(f32*)(modelResource + 0x114),
                          *(f32*)(modelResource + 0x118));
            orientation = (K_Field_Get()->dungeonCells[y][x].direction + 2) & 3;
            angle = (f32)orientation * 90.0f;
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
            func_004c31b0(matrix, &axis, angle, 2);
            for (count = 0; count < 4; count++)
            {
                RwV3d* vertex = (RwV3d*)(modelResource + 0x11c + count * 0xc);
                func_004c6be0(vertex, vertex, matrix);
                vertex->x += origin.x;
                vertex->y += origin.y;
                vertex->z += origin.z;
            }
        }
    }

    records = record;
    for (i = 0, record = records;
         i < *(u32*)(source + 0x10);
         i++, record += 0x14)
    {
        if (K_Scene_001a0250() == 1)
        {
            position0 = *(RwV3d*)(record + 4);
            orientation = (K_Field_Get()->dungeonCells[y][x].direction + 2) & 3;
            angle = (f32)orientation * 90.0f;
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
            func_004c31b0(matrix, &axis, angle, 2);
            func_004c6be0(&position0, &position0, matrix);
            position0.x += origin.x;
            position0.y += origin.y;
            position0.z += origin.z;
            angle += *(f32*)(record + 0x10);
            while (angle > 360.0f)
            {
                angle -= 360.0f;
            }
            resourceId = K_Misc_FindNextFreeResId(0xf);
            func_003b6b90((u16)resourceId, &position0, angle);
        }
    }
    records = record;
    for (i = 0, record = records;
         i < *(u32*)(source + 0x18);
         i++, record += 0x14)
    {
        if (K_Scene_001a0250() == 1)
        {
            position1 = *(RwV3d*)(record + 4);
            orientation = (K_Field_Get()->dungeonCells[y][x].direction + 2) & 3;
            angle = (f32)orientation * 90.0f;
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
            func_004c31b0(matrix, &axis, angle, 2);
            func_004c6be0(&position1, &position1, matrix);
            position1.x += origin.x;
            position1.y += origin.y;
            position1.z += origin.z;
            angle += *(f32*)(record + 0x10);
            while (angle > 360.0f)
            {
                angle -= 360.0f;
            }
            resourceId = K_Misc_FindNextFreeResId(0x10);
            func_003b6c50((u16)resourceId, &position1, angle);
        }
    }
    records = record;
    for (i = 0, record = records;
         i < *(u32*)(source + 0x20);
         i++, record += 0x14)
    {
        if (K_Scene_001a0250() == 1)
        {
            position2 = *(RwV3d*)(record + 4);
            orientation = (K_Field_Get()->dungeonCells[y][x].direction + 2) & 3;
            angle = (f32)orientation * 90.0f;
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
            func_004c31b0(matrix, &axis, angle, 2);
            func_004c6be0(&position2, &position2, matrix);
            position2.x += origin.x;
            position2.y += origin.y;
            position2.z += origin.z;
            angle += *(f32*)(record + 0x10);
            while (angle > 360.0f)
            {
                angle -= 360.0f;
            }
            resourceId = K_Misc_FindNextFreeResId(0x11);
            func_003b6d10((u16)resourceId, &position2, angle);
        }
    }
    records = record;

    records += *(u32*)(source + 0x28) * 0x14;
    if (version >= 0x1002)
    {
        records += *(u32*)(source + 0x30) * 0x20;
        if (version >= 0x1003)
        {
            for (i = 0, record = records;
                 i < *(u32*)(source + 0x38);
                 i++, record += 0x14)
            {
                if (K_Scene_001a0250() == 1)
                {
                    position3 = *(RwV3d*)(record + 4);
                    orientation = (K_Field_Get()->dungeonCells[y][x].direction + 2) & 3;
                    angle = (f32)orientation * 90.0f;
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
                    func_004c31b0(matrix, &axis, angle, 2);
                    func_004c6be0(&position3, &position3, matrix);
                    position3.x += origin.x;
                    position3.y += origin.y;
                    position3.z += origin.z;
                    angle += *(f32*)(record + 0x10);
                    while (angle > 360.0f)
                    {
                        angle -= 360.0f;
                    }
                    ids[i] = (u16)K_Misc_FindNextFreeResId(0x12);
                    func_003b6dd0(ids[i], &position3, angle);
                }
            }
        }
    }

    count = *(u32*)(source + 0x38);
    if (count >= 5)
    {
        K_Assert((const char*)D_006833A0, 0x212);
    }
    if (count == 1)
    {
        K_Field_Get()->dungeonCells[y][x].unk_0c = ids[0];
    }
    else if (count == 3)
    {
        direction = K_Field_Get()->dungeonCells[y][x].direction;
        switch (direction)
        {
        case 0:
            K_Field_Get()->dungeonCells[y][x].unk_0c = -1;
            K_Field_Get()->dungeonCells[y][x + 1].unk_0c = ids[0];
            K_Field_Get()->dungeonCells[y + 1][x].unk_0c = ids[1];
            K_Field_Get()->dungeonCells[y + 1][x + 1].unk_0c = ids[2];
            break;
        case 1:
            K_Field_Get()->dungeonCells[y][x].unk_0c = ids[0];
            K_Field_Get()->dungeonCells[y][x + 1].unk_0c = ids[2];
            K_Field_Get()->dungeonCells[y + 1][x].unk_0c = -1;
            K_Field_Get()->dungeonCells[y + 1][x + 1].unk_0c = ids[1];
            break;
        case 2:
            K_Field_Get()->dungeonCells[y][x].unk_0c = ids[2];
            K_Field_Get()->dungeonCells[y][x + 1].unk_0c = ids[1];
            K_Field_Get()->dungeonCells[y + 1][x].unk_0c = ids[0];
            K_Field_Get()->dungeonCells[y + 1][x + 1].unk_0c = -1;
            break;
        case 3:
            K_Field_Get()->dungeonCells[y][x].unk_0c = ids[1];
            K_Field_Get()->dungeonCells[y][x + 1].unk_0c = -1;
            K_Field_Get()->dungeonCells[y + 1][x].unk_0c = ids[2];
            K_Field_Get()->dungeonCells[y + 1][x + 1].unk_0c = ids[0];
            break;
        }
    }
    else if (count == 4)
    {
        direction = K_Field_Get()->dungeonCells[y][x].direction;
        switch (direction)
        {
        case 0:
            K_Field_Get()->dungeonCells[y][x].unk_0c = ids[0];
            K_Field_Get()->dungeonCells[y][x + 1].unk_0c = ids[1];
            K_Field_Get()->dungeonCells[y + 1][x].unk_0c = ids[2];
            K_Field_Get()->dungeonCells[y + 1][x + 1].unk_0c = ids[3];
            break;
        case 1:
            K_Field_Get()->dungeonCells[y][x].unk_0c = ids[1];
            K_Field_Get()->dungeonCells[y][x + 1].unk_0c = ids[3];
            K_Field_Get()->dungeonCells[y + 1][x].unk_0c = ids[0];
            K_Field_Get()->dungeonCells[y + 1][x + 1].unk_0c = ids[2];
            break;
        case 2:
            K_Field_Get()->dungeonCells[y][x].unk_0c = ids[3];
            K_Field_Get()->dungeonCells[y][x + 1].unk_0c = ids[2];
            K_Field_Get()->dungeonCells[y + 1][x].unk_0c = ids[1];
            K_Field_Get()->dungeonCells[y + 1][x + 1].unk_0c = ids[0];
            break;
        case 3:
            K_Field_Get()->dungeonCells[y][x].unk_0c = ids[2];
            K_Field_Get()->dungeonCells[y][x + 1].unk_0c = ids[0];
            K_Field_Get()->dungeonCells[y + 1][x].unk_0c = ids[3];
            K_Field_Get()->dungeonCells[y + 1][x + 1].unk_0c = ids[1];
            break;
        }
    }
    func_004c3880(matrix);
}
#pragma opt_propagation reset

#pragma opt_loop_invariants on
#pragma opt_propagation off
// FUN_001bc630 NONMATCHING
u32 func_001bc630(const DungeonPattern* pattern, s32* x, s32* y)
{
    s32 startX;
    s32 startY;
    s32 roomX;
    s32 roomY;
    s32 row;
    s32 col;
    u8* field;
    u8* neighbor;
    u8 neighborFlags;

    for (roomY = 0, startY = *y;
         roomY < pattern->raw[2];
         roomY++, startY++)
    {
        for (roomX = 0, startX = *x;
             roomX < pattern->raw[1];
             roomX++, startX++)
        {
            field = (u8*)K_Field_Get();
            for (row = 0; row < pattern->raw[2]; row++)
            {
                for (col = 0; col < pattern->raw[1]; col++)
                {
                    u8* fieldCell;
                    fieldCell = field + (startY + row) * 0x100 +
                                (startX + col) * 0x10;
                    if (fieldCell[0x48] != 0)
                    {
                        goto reject;
                    }
                }
            }

            for (row = 0; row < pattern->raw[2]; row++)
            {
                for (col = 0; col < pattern->raw[1]; col++)
                {
                    if (startY == 0x0e &&
                        (pattern->raw[row * 0x18 + col * 8 + 0x0e] & 0x40) != 0)
                    {
                        return false;
                    }
                    if (startY == 1 &&
                        (pattern->raw[row * 0x18 + col * 8 + 0x0e] & 0x10) != 0)
                    {
                        return false;
                    }
                    if (startX + col == 0x0e &&
                        (pattern->raw[row * 0x18 + col * 8 + 0x0e] & 0x80) != 0)
                    {
                        return false;
                    }
                    if (startX + col == 1 &&
                        (pattern->raw[row * 0x18 + col * 8 + 0x0e] & 0x20) != 0)
                    {
                        return false;
                    }

                    neighbor = (u8*)K_Field_Get() +
                               (startY + row) * 0x100 +
                               (startX + col) * 0x10 - 0x100;
                    if (neighbor[0x48] != 0)
                    {
                        neighborFlags = ((u8*)K_Field_Get() +
                                         (startY + row) * 0x100 +
                                         (startX + col) * 0x10 - 0x100)[0x53];
                        if (((neighborFlags & 0x40) != 0) !=
                            ((pattern->raw[row * 0x18 + col * 8 + 0x0e] & 0x10) != 0))
                        {
                            return false;
                        }
                    }
                    neighbor = (u8*)K_Field_Get() +
                               (startY + row) * 0x100 +
                               (startX + col) * 0x10 - 0x10;
                    if (neighbor[0x48] != 0)
                    {
                        neighborFlags = ((u8*)K_Field_Get() +
                                         (startY + row) * 0x100 +
                                         (startX + col) * 0x10 - 0x10)[0x53];
                        if (((neighborFlags & 0x80) != 0) !=
                            ((pattern->raw[row * 0x18 + col * 8 + 0x0e] & 0x20) != 0))
                        {
                            return false;
                        }
                    }
                    neighbor = (u8*)K_Field_Get() +
                               (startY + row) * 0x100 +
                               (startX + col) * 0x10 + 0x100;
                    if (neighbor[0x48] != 0)
                    {
                        neighborFlags = ((u8*)K_Field_Get() +
                                         (startY + row) * 0x100 +
                                         (startX + col) * 0x10 + 0x100)[0x53];
                        if (((neighborFlags & 0x10) != 0) !=
                            ((pattern->raw[row * 0x18 + col * 8 + 0x0e] & 0x40) != 0))
                        {
                            return false;
                        }
                    }
                    neighbor = (u8*)K_Field_Get() +
                               (startY + row) * 0x100 +
                               (startX + col) * 0x10 + 0x10;
                    if (neighbor[0x48] != 0)
                    {
                        neighborFlags = ((u8*)K_Field_Get() +
                                         (startY + row) * 0x100 +
                                         (startX + col) * 0x10 + 0x10)[0x53];
                        if (((neighborFlags & 0x20) != 0) !=
                            ((pattern->raw[row * 0x18 + col * 8 + 0x0e] & 0x80) != 0))
                        {
                            return false;
                        }
                    }
                }
            }

            *x = startX;
            *y = startY;
            return true;

        reject:
            ;
        }
    }
    return false;
}
#pragma opt_propagation reset
#pragma opt_loop_invariants reset

#pragma opt_common_subs off
#pragma opt_lifetimes on
// FUN_001bcac0 NONMATCHING
void func_001bcac0(u32 patternId, u32 x, u32 y, u32 fromX, u32 fromY)
{
    DungeonPattern pattern;
    const u8* table;
    const s16* src;
    s16* dst;
    u32 templateId;
    u32 rotation;
    u32 connectionCount;
    u32 row;
    u32 col;
    u32 direction;
    u32 temp20;
    u32 temp19;
    u32 temp22;
    u32 temp20_2;
    u32 temp23;
    u32 temp30;
    u32 temp21;
    u32 temp20_3;
    u32 spD0;
    u32 spC0;
    u32 spB0;
    u32 spA0;
    u32 spF0;
    u32 spE0;
    u32 sp100;
    s32 placedX;
    s32 placedY;
    s32 count;
    u8 value;

    temp20 = y << 8;
    temp19 = x << 4;
    if (*(u8*)((u8*)K_Field_Get() + temp20 + temp19 + 0x48) != 0 ||
        sDungeonGenerationFailed == 1)
    {
        return;
    }
    if (x == 0 || x == 0xf || y == 0 || y == 0xf)
    {
        return;
    }

    if (x == ((u8*)K_Field_Get())[0x3e] &&
        y == ((u8*)K_Field_Get())[0x3f])
    {
        if (datGetScenarioMode() == 0)
        {
            src = (const s16*)(D_0067FA26 + patternId * 0x35c);
        }
        else
        {
            src = (const s16*)(D_00681866 + patternId * 0x35c);
        }
        dst = (s16*)pattern.raw;
        count = 0x2b;
        do
        {
            *dst++ = *src++;
            count--;
        } while (count > 0);
        func_001bab60(&pattern, 1u << ((u8*)K_Field_Get())[0x41]);
        func_001bb090(&pattern, (u16)x, (u16)y,
                      (u16)((u8*)K_Field_Get())[0x41]);
        return;
    }

    sDungeonGenerationAttempts = 0;
    temp20_2 = temp20 + temp19;
    temp22 = (fromY << 8) + (fromX << 4);
    for (;;)
    {
        sDungeonGenerationAttempts++;
        if (sDungeonGenerationAttempts >= 0x2711)
        {
            sDungeonGenerationFailed = 1;
            return;
        }

        if (x == ((u8*)K_Field_Get())[0x3c] &&
            y == ((u8*)K_Field_Get())[0x3d])
        {
            connectionCount = 0;
            if (*(u8*)((u8*)K_Field_Get() + temp20_2 - 0xb8) != 0 &&
                (*(u8*)((u8*)K_Field_Get() + temp20_2 - 0xad) & 0x40) != 0)
            {
                connectionCount++;
            }
            if (*(u8*)((u8*)K_Field_Get() + temp20_2 + 0x38) != 0 &&
                (*(u8*)((u8*)K_Field_Get() + temp20_2 + 0x43) & 0x80) != 0)
            {
                connectionCount++;
            }
            if (*(u8*)((u8*)K_Field_Get() + temp20_2 + 0x148) != 0 &&
                (*(u8*)((u8*)K_Field_Get() + temp20_2 + 0x153) & 0x10) != 0)
            {
                connectionCount++;
            }
            if (*(u8*)((u8*)K_Field_Get() + temp20_2 + 0x58) != 0 &&
                (*(u8*)((u8*)K_Field_Get() + temp20_2 + 0x63) & 0x20) != 0)
            {
                connectionCount++;
            }
            if (connectionCount >= 2)
            {
                continue;
            }
            templateId = 5;
            rotation = RpRandom() & 3;
        }
        else
        {
            templateId = (RpRandom() & 7) + 1;
            rotation = RpRandom() & 3;
            if ((templateId == 2 || templateId == 4) &&
                *(u8*)((u8*)K_Field_Get() + temp22 + 0x48) != 0 &&
                (*(u8*)((u8*)K_Field_Get() + temp22 + 0x4a) == 1 ||
                 *(u8*)((u8*)K_Field_Get() + temp22 + 0x4a) == 3))
            {
                continue;
            }
        }

        if (datGetScenarioMode() == 0)
        {
            table = D_0067F720 + patternId * 0x35c + templateId * 0x56;
        }
        else
        {
            table = D_00681560 + patternId * 0x35c + templateId * 0x56;
        }
        src = (const s16*)table;
        dst = (s16*)pattern.raw;
        count = 0x2b;
        do
        {
            *dst++ = *src++;
            count--;
        } while (count > 0);

        func_001bab60(&pattern, 1u << rotation);
        *(s32*)(pattern.raw + 0x5c) = (s32)x;
        *(s32*)(pattern.raw + 0x58) = (s32)y;
        if (func_001bc630(&pattern,
                          (s32*)(pattern.raw + 0x5c),
                          (s32*)(pattern.raw + 0x58)) != 1)
        {
            continue;
        }
        func_001bb090(&pattern,
                      *(u16*)(pattern.raw + 0x5c),
                      *(u16*)(pattern.raw + 0x58),
                      (u16)rotation);
        placedX = *(s32*)(pattern.raw + 0x5c);
        placedY = *(s32*)(pattern.raw + 0x58);
        x = (u32)placedX;
        y = (u32)placedY;
        if ((*(u32*)((u8*)K_Field_Get() + 0x38) & 1) != 0)
        {
            continue;
        }

        for (row = 0; row < pattern.raw[2]; row++)
        {
            temp20_2 = (y + row) << 8;
            temp23 = temp20_2 - 0xb8;
            temp30 = temp20_2 - 0xa8;
            spD0 = temp20_2 - 0xc8;
            spC0 = temp20_2 - 0x1b8;
            for (col = 0; col < pattern.raw[1]; col++)
            {
                temp20_3 = (x + col) << 4;
                if (*(u8*)((u8*)K_Field_Get() + temp23 + temp20_3) == 0 &&
                    (*(u8*)((u8*)K_Field_Get() + temp20_2 + temp20_3 + 0x53) & 0x10) == 0 &&
                    *(u8*)((u8*)K_Field_Get() + temp30 + temp20_3) != 1 &&
                    *(u8*)((u8*)K_Field_Get() + spD0 + temp20_3) != 1 &&
                    *(u8*)((u8*)K_Field_Get() + spC0 + temp20_3) != 1)
                {
                    *(u8*)((u8*)K_Field_Get() + temp23 + temp20_3) = 2;
                }
                if (*(u8*)((u8*)K_Field_Get() + temp20_2 + temp20_3 + 0x38) == 0 &&
                    (*(u8*)((u8*)K_Field_Get() + temp20_2 + temp20_3 + 0x53) & 0x20) == 0 &&
                    *(u8*)((u8*)K_Field_Get() + spD0 + temp20_3) != 1 &&
                    *(u8*)((u8*)K_Field_Get() + temp20_2 + temp20_3 + 0x138) != 1 &&
                    *(u8*)((u8*)K_Field_Get() + temp20_2 + temp20_3 + 0x28) != 1)
                {
                    *(u8*)((u8*)K_Field_Get() + temp20_2 + temp20_3 + 0x38) = 2;
                }
                if (*(u8*)((u8*)K_Field_Get() + temp20_2 + temp20_3 + 0x148) == 0 &&
                    (*(u8*)((u8*)K_Field_Get() + temp20_2 + temp20_3 + 0x53) & 0x40) == 0 &&
                    *(u8*)((u8*)K_Field_Get() + temp20_2 + temp20_3 + 0x158) != 1 &&
                    *(u8*)((u8*)K_Field_Get() + temp20_2 + temp20_3 + 0x138) != 1 &&
                    *(u8*)((u8*)K_Field_Get() + temp20_2 + temp20_3 + 0x248) != 1)
                {
                    *(u8*)((u8*)K_Field_Get() + temp20_2 + temp20_3 + 0x148) = 2;
                }
                if (*(u8*)((u8*)K_Field_Get() + temp20_2 + temp20_3 + 0x58) == 0 &&
                    (*(u8*)((u8*)K_Field_Get() + temp20_2 + temp20_3 + 0x53) & 0x80) == 0)
                {
                    value = *(u8*)((u8*)K_Field_Get() + temp30 + temp20_3);
                    if (value != 1)
                    {
                        value = *(u8*)((u8*)K_Field_Get() + temp20_2 + temp20_3 + 0x158);
                        if (value != 1)
                        {
                            value = *(u8*)((u8*)K_Field_Get() + temp20_2 + temp20_3 + 0x68);
                            if (value != 1)
                            {
                                *(u8*)((u8*)K_Field_Get() + temp20_2 + temp20_3 + 0x58) = 2;
                            }
                        }
                    }
                }
            }
        }

        for (row = 0; row < pattern.raw[2]; row++)
        {
            temp21 = y + row;
            spB0 = temp21 << 8;
            sp100 = temp21 + 1;
            spF0 = x - 1;
            spE0 = x + 1;
            for (col = 0; col < pattern.raw[1]; col++)
            {
                temp20_3 = x + col;
                spA0 = spB0 + (temp20_3 << 4);
                for (direction = 0; direction < 4; direction++)
                {
                    if ((*(u8*)((u8*)K_Field_Get() + spA0 + 0x53) &
                         (1u << (direction + 4))) != 0)
                    {
                        switch (direction)
                        {
                            case 0:
                                func_001bcac0(patternId, temp20_3,
                                              temp21 - 1, temp20_3, temp21);
                                break;
                            case 1:
                                func_001bcac0(patternId, spF0, temp21,
                                              temp20_3, temp21);
                                break;
                            case 2:
                                func_001bcac0(patternId, temp20_3,
                                              sp100, temp20_3, temp21);
                                break;
                            case 3:
                                func_001bcac0(patternId, spE0, temp21,
                                              temp20_3, temp21);
                                break;
                        }
                    }
                }
            }
        }
        return;
    }
}
#pragma opt_lifetimes reset
#pragma opt_common_subs reset

#pragma opt_loop_invariants on
// FUN_001bd450 NONMATCHING
void func_001bd450(u32 patternId)
{
    u8* field;
    u8* targetCell;
    s32 startX;
    s32 startY;
    s32 targetX;
    s32 targetY;
    s32 rooms;
    s32 exits;
    u32 x;
    u32 y;

    goto check;

generate:
    sDungeonGenerationFailed = 0;
    sDungeonGenerationAttempts = 0;
    sDungeonRoomCounter = 0;
    memset((u8*)K_Field_Get() + 0x48, 0, 0x1000);
    for (x = 0; x < 0x10; x++)
    {
        *(u8*)((u8*)K_Field_Get() + x * 0x10 + 0x48) = 2;
        *(u8*)((u8*)K_Field_Get() + x * 0x10 + 0xf48) = 2;
    }
    for (y = 0; y < 0x10; y++)
    {
        *(u8*)((u8*)K_Field_Get() + y * 0x100 + 0x48) = 2;
        *(u8*)((u8*)K_Field_Get() + y * 0x100 + 0x138) = 2;
    }

    *(u8*)((u8*)K_Field_Get() + 0x3c) = 0;
    *(u8*)((u8*)K_Field_Get() + 0x3d) = 0;
    *(u8*)((u8*)K_Field_Get() + 0x3e) = 0;
    *(u8*)((u8*)K_Field_Get() + 0x3f) = 0;
    do
    {
        startX = (s32)(RpRandom() % 12) + 2;
        *(u8*)((u8*)K_Field_Get() + 0x3c) = (u8)startX;
        startY = (s32)(RpRandom() % 12) + 2;
        *(u8*)((u8*)K_Field_Get() + 0x3d) = (u8)startY;
    } while (*(u8*)((u8*)K_Field_Get() +
                     startY * 0x100 + startX * 0x10 + 0x48) != 0);
    *(u8*)((u8*)K_Field_Get() + 0x40) = (u8)(RpRandom() & 3);

    do
    {
        targetX = (s32)(RpRandom() % 11) + 2;
        *(u8*)((u8*)K_Field_Get() + 0x3e) = (u8)targetX;
        targetY = (s32)(RpRandom() % 11) + 2;
        *(u8*)((u8*)K_Field_Get() + 0x3f) = (u8)targetY;
        *(u8*)((u8*)K_Field_Get() + 0x41) = (u8)(RpRandom() & 3);
        targetCell = (u8*)K_Field_Get() +
                     targetY * 0x100 + targetX * 0x10;
    } while (targetCell[0x48] != 0 ||
             *(u8*)((u8*)K_Field_Get() +
                    targetY * 0x100 + (targetX + 1) * 0x10 + 0x48) != 0 ||
             *(u8*)((u8*)K_Field_Get() +
                    (targetY + 1) * 0x100 + targetX * 0x10 + 0x48) != 0 ||
             *(u8*)((u8*)K_Field_Get() +
                    (targetY + 1) * 0x100 + (targetX + 1) * 0x10 + 0x48) != 0);
    func_001bcac0(patternId,
                  *(u8*)((u8*)K_Field_Get() + 0x3e),
                  *(u8*)((u8*)K_Field_Get() + 0x3f), 0, 0);

    rooms = 0;
    exits = 0;
    for (y = 0; y < 0x10; y++)
    {
        for (x = 0; x < 0x10; x++)
        {
            field = (u8*)K_Field_Get() + y * 0x100 + x * 0x10;
            if (field[0x48] == 1)
            {
                rooms++;
            }
            if (((u8*)K_Field_Get() + y * 0x100 + x * 0x10)[0x4a] == 4)
            {
                exits++;
            }
        }
    }

    if (rooms < (s32)*(u8*)((u8*)K_Field_Get() + 0x42) ||
        rooms > (s32)*(u8*)((u8*)K_Field_Get() + 0x43))
    {
        sDungeonGenerationFailed = 1;
    }
    if (exits < 2)
    {
        sDungeonGenerationFailed = 1;
    }

check:
    targetCell = (u8*)K_Field_Get() +
                 (*(u8*)((u8*)K_Field_Get() + 0x3d) * 0x100) +
                 (*(u8*)((u8*)K_Field_Get() + 0x3c) * 0x10);
    if (targetCell[0x48] != 1)
    {
        goto generate;
    }
    targetCell = (u8*)K_Field_Get() +
                 (*(u8*)((u8*)K_Field_Get() + 0x3d) * 0x100) +
                 (*(u8*)((u8*)K_Field_Get() + 0x3c) * 0x10);
    if (targetCell[0x4a] != 4)
    {
        goto generate;
    }
    if (sDungeonGenerationFailed != 0)
    {
        goto generate;
    }
}
#pragma opt_loop_invariants reset

// FUN_001bd8c0
void func_001bd8c0(void)
{
    s32 y;
    s32 x;
    u32 rowOffset;
    u32 packed;

    for (y = 0; y < 0x10; y++)
    {
        x = 0;
        rowOffset = (u32)(y << 4);
        for (; x < 0x10; x++)
        {
            packed = (u32)x + rowOffset;
            func_001bb300((u16)packed, (u16)x, (u16)y);
        }
    }
}

#pragma opt_loop_invariants on
#pragma opt_dead_assignments off
// FUN_001bd950 NONMATCHING
#pragma push
void func_001bd950(void)
{
    Resrc* fieldResource;
    ResrcModelChar* heroResource;
    Resrc* modelFld;
    Resrc* modelNpc;
    s32 xGrid;
    s32 zGrid;
    s32 i;
    f32 angle;
    if (K_Scene_001a0250() != true && func_001a02c0() != true)
    {
        return;
    }

    fieldResource = MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    heroResource = (ResrcModelChar*)MT_Scene_GetRes(0x400);
    modelFld = MT_Scene_GetResListHead(RESRC_TYPE_MODELFLD);
    modelNpc = MT_Scene_GetResListHead(RESRC_TYPE_11);

    if (heroResource != NULL)
    {
        DAT_007ce250 = K_FldFrame_CtlGetXGrid(heroResource->collisCtlTask);
        DAT_007ce254 = K_FldFrame_CtlGetZGrid(heroResource->collisCtlTask);
        for (; fieldResource != NULL; fieldResource = fieldResource->next)
        {
            fieldResource->flags &= ~2u;
        }
        (void)MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    }
    else
    {
        for (; fieldResource != NULL; fieldResource = fieldResource->next)
        {
            fieldResource->flags |= 2;
        }
        (void)MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    }
    xGrid = DAT_007ce250;
    zGrid = DAT_007ce254;

    angle = FUN_001A5AA0(
        &((RwFrame*)kwlnGetMainCamera_y2()->object.object.parent)->modelling);
    if (angle <= 22.5f && angle >= -22.5f)
    {
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 3][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 3][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 3][xGrid + 1].resourceId, 1);
    }
    else if (angle > 22.5f && angle <= 67.5f)
    {
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 3][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 3][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid + 3].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid + 3].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid + 2].resourceId, 1);
    }
    else if (angle > 67.5f && angle <= 112.5f)
    {
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid + 3].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid + 3].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid + 3].resourceId, 1);
    }
    else if (angle > 112.5f && angle <= 157.5f)
    {
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid + 3].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid + 3].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 3][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 3][xGrid + 1].resourceId, 1);
    }
    else if (angle > 157.5f || angle < -157.5f)
    {
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 3][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 3][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid - 3].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid - 3].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid + 1].resourceId, 1);
    }
    else if (angle >= -157.5f && angle < -112.5f)
    {
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 2][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid - 3].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid - 3].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid - 3].resourceId, 1);
    }
    else if (angle >= -112.5f && angle < -67.5f)
    {
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid - 3].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid - 3].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 3][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 3][xGrid + 1].resourceId, 1);
    }
    else
    {
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid + 1][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 1][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid - 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid + 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 2][xGrid + 2].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 3][xGrid - 1].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 3][xGrid].resourceId, 1);
        func_001a0150(K_Field_Get()->dungeonCells[zGrid - 3][xGrid + 1].resourceId, 1);
    }
    for (; modelFld != NULL; modelFld = modelFld->next)
    {
        Resrc* parent;
        parent = *(Resrc**)((u8*)modelFld + 0x100);
        if (parent != NULL && (parent->flags & 2) != 0)
        {
            modelFld->flags |= 2;
        }
        else
        {
            modelFld->flags &= ~2u;
        }
    }
    for (; modelNpc != NULL; modelNpc = modelNpc->next)
    {
        Resrc* parent;
        parent = *(Resrc**)((u8*)modelNpc + 0x100);
        if (parent != NULL && (parent->flags & 2) != 0)
        {
            modelNpc->flags |= 2;
        }
        else
        {
            modelNpc->flags &= ~2u;
        }
    }

    for (i = 0; i < FLDUNIT_EC_MAX; i++)
    {
        if (gFldUnitsEc[i].genusBase != NULL &&
            gFldUnitsEc[i].resrc != NULL)
        {
            if (K_FldEvent_AreUnitsWithinDist(
                    &gFldUnitsEc[i], &gFldUnitsPc[FLDUNIT_PC_HERO],
                    2000.0f) == true)
            {
                gFldUnitsEc[i].resrc->base.flags |= 2;
            }
            else
            {
                gFldUnitsEc[i].resrc->base.flags &= ~2u;
            }
        }
    }
}
#pragma pop
#pragma opt_dead_assignments reset
#pragma opt_loop_invariants reset

// FUN_001bf220
void func_001bf220(RwV3d* dst, u32 x, u32 y)
{
    Resrc* resource;
    u8* cell;
    u32 offset;
    u32 id;
    u32 resourceTypeId;
    RwV3d result;
    resource = MT_Scene_GetResListHead(0x12);
    memset(&result, 0, sizeof(result));
    if (K_Scene_001a0250() == true || func_001a02c0() == true)
    {
        offset = ((u32)(u16)y << 8) + ((u32)(u16)x << 4);
        while (resource != NULL)
        {
            resourceTypeId = resource->resTypeId & 0x3ff;
            cell = (u8*)offset;
            cell += (u32)K_Field_Get();
            id = *(u32*)(cell + 0x54);
            if (resourceTypeId == (id & 0x3ff))
            {
                result = *(RwV3d*)((u8*)resource + 0x100);
                break;
            }
            resource = resource->next;
        }
    }
    *dst = result;
}

// FUN_001bf340 MATCHING
u32 func_001bf340_y2(const FldDungeonFloorData* floorData)
{
    s32 chance;
    u32 currentFloor;
    s32 random;
    s32 lower;
    s32 upper;
    s32 total;
    s32 choice;
    s32 i;

    chance = (s32)FUN_0016F380(0x3b);
    currentFloor = K_FldDungeon_GetCurrentFloor();
    if (currentFloor >= FUN_0016F380(0x0c))
    {
        return 0;
    }
    if (chance - 1 < 0)
    {
        FUN_0016F3E0(0x3b, FUN_0016F380(0x3a));
        goto done_reset;
    }
    if (floorData->minorId != 0)
    {
        goto done_reset;
    }
    if (chance - 1 == 0)
    {
        random = (s32)(RpRandom() % 100);
        lower = (s32)FUN_0016F380(0x3c);
        if (random >= lower)
        {
            goto done_reset;
        }
        lower = (s32)FUN_0016F380(0x3d);
        upper = (s32)FUN_0016F380(0x3e);
        total = (s32)FUN_0016F380(0x37);
        i = (s32)FUN_0016F380(0x36);
        total += lower + upper;
        choice = (s32)(RpRandom() % (i + total));
        FUN_0016F3E0(0x3b, FUN_0016F380(0x3a));
        if (choice < lower)
        {
            return 1;
        }
        if (choice >= lower && choice < lower + upper)
        {
            return 2;
        }
        if (choice >= lower + upper && choice < total)
        {
            return 3;
        }
        for (i = 0; i < 3; i++)
        {
            if (FUN_0016DD60(i) >= 1)
            {
                break;
            }
        }
        if (i < 3)
        {
            return 4;
        }
    }
    else
    {
        goto reset;
    }
done_loop:
    return 0;
reset:
    FUN_0016F3E0(0x3b, chance - 1);
done_reset:
    return 0;
}

// FUN_001bf570
void* K_FldDungeon_UpdateTask(KwlnTask* dungeonTask)
{
    FldDungeon* dungeon;
    char eplPath[48];
    u8 effectData[12];
    u8 reloadEffectData[12];
    u32 i;
    u8* effectDataPtr;
    s32 j;

    dungeon = (FldDungeon*)dungeonTask->workData;

    switch (dungeon->state)
    {
        case FLDDUNGEON_STATE_INITIALIZE:
            if (gDungeonTpMdl != NULL && !mdlStreamRead(gDungeonTpMdl))
            {
                break;
            }

            if (!K_FldDungeon_CreateScrMemory(dungeon->scrCdvd))
            {
                break;
            }

            dungeon->scrCdvd = NULL;
            if (!func_001c0440())
            {
                break;
            }

            if (!func_001c0740())
            {
                break;
            }

            dungeon->floorsData = gFldDngFloorsData;
            j = dungeon->currFloor << 4;
            if (*(u8*)(j + (s32)dungeon->floorsData + 0x1d) < 0xff)
            {
                sprintf(eplPath, "field/effect/DNG%02d.EPL",
                        *(u8*)(j + (s32)dungeon->floorsData + 0x0d));
                dungeon->effectEplTask = func_001a9080(dungeonTask, eplPath, -1, NULL);
            }
            else
            {
                dungeon->effectEplTask = NULL;
            }

            dungeon->state++;

        case FLDDUNGEON_STATE_WAIT_EFFECT:
            effectDataPtr = effectData;
            j = 12;
            if (effectDataPtr != NULL)
            {
                do
                {
                    *effectDataPtr++ = 0;
                    j--;
                } while (j != 0);
            }
            if (dungeon->effectEplTask != NULL)
            {
                if (!func_001a9180(dungeon->effectEplTask))
                {
                    break;
                }

                dungeon->effectEplSlot = func_001a91b0(dungeon->effectEplTask, effectData);
            }

            dungeon->state++;

        case FLDDUNGEON_STATE_CREATE_FIELD:
            dungeon->encounterResult = func_001bf340(&dungeon->floorsData[dungeon->currFloor]);
            D_0086E580[0] = 0;
            dungeon->fieldFlags = dungeon->floorsData[dungeon->currFloor].fieldFlags | 0x80000000;
            dungeon->fldRootTask = func_001ba5f0(dungeonTask,
                                                  dungeon->floorsData[dungeon->currFloor].majorId,
                                                  dungeon->floorsData[dungeon->currFloor].minorId,
                                                  (u16)dungeon->unk_08,
                                                  0,
                                                  0,
                                                  dungeon->fieldFlags,
                                                  dungeon->floorsData[dungeon->currFloor].unk_06,
                                                  dungeon->floorsData[dungeon->currFloor].unk_07,
                                                  dungeon->floorsData[dungeon->currFloor].unk_04,
                                                  -1,
                                                  -1,
                                                  -1,
                                                  -1);
            dungeon->fieldFlags = 0;

            i = 0;
            while (i < 6)
            {
                if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY &&
                    dungeon->currFloor == D_006833C0[i])
                {
                    break;
                }
                i++;
            }

            if (i < 6)
            {
                func_001baa50(dungeon->fldRootTask, true);
                datSetFlag(0x1421, true);
                dungeon->transitionTask = func_00447e70(dungeonTask, 0, 0);
                dungeon->state = FLDDUNGEON_STATE_WAIT_TRANSITION;
            }
            else
            {
                dungeon->state++;
            }
            break;

        case FLDDUNGEON_STATE_IDLE:
            if (dungeon->shouldShutdown == true)
            {
                dungeon->state = FLDDUNGEON_STATE_STOP;
            }
            break;

        case FLDDUNGEON_STATE_UNK_04:
        case FLDDUNGEON_STATE_UNK_05:
        case FLDDUNGEON_STATE_UNK_06:
            dungeon->state++;
            break;

        case FLDDUNGEON_STATE_RELOAD_FIELD:
            effectDataPtr = reloadEffectData;
            j = 12;
            if (effectDataPtr != NULL)
            {
                do
                {
                    *effectDataPtr++ = 0;
                    j--;
                } while (j != 0);
            }

            if ((gDungeonTpMdl != NULL && !mdlStreamRead(gDungeonTpMdl)) ||
                !K_FldDungeon_CreateScrMemory(dungeon->scrCdvd))
            {
                break;
            }

            dungeon->scrCdvd = NULL;
            if (!func_001c0440() || !func_001c0740())
            {
                break;
            }

            if (dungeon->effectEplTask != NULL)
            {
                if (!func_001a9180(dungeon->effectEplTask))
                {
                    break;
                }

                dungeon->effectEplSlot = func_001a91b0(dungeon->effectEplTask, reloadEffectData);
            }

            dungeon->encounterResult = func_001bf340(&dungeon->floorsData[dungeon->currFloor]);
            D_0086E580[0] = 0;
            dungeon->fieldFlags |= dungeon->floorsData[dungeon->currFloor].fieldFlags;
            dungeon->fldRootTask = func_001ba5f0(dungeonTask,
                                                  dungeon->floorsData[dungeon->currFloor].majorId,
                                                  dungeon->floorsData[dungeon->currFloor].minorId,
                                                  (u16)dungeon->unk_08,
                                                  0,
                                                  0,
                                                  dungeon->fieldFlags,
                                                  dungeon->floorsData[dungeon->currFloor].unk_06,
                                                  dungeon->floorsData[dungeon->currFloor].unk_07,
                                                  dungeon->floorsData[dungeon->currFloor].unk_04,
                                                  -1,
                                                  -1,
                                                  -1,
                                                  -1);
            dungeon->fieldFlags = 0;

            i = 0;
            while (i < 6)
            {
                if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY &&
                    dungeon->currFloor == D_006833C0[i])
                {
                    break;
                }
                i++;
            }

            if (i < 6)
            {
                func_001baa50(dungeon->fldRootTask, true);
                datSetFlag(0x1421, true);
                dungeon->transitionTask = func_00447e70(dungeonTask, 0, 0);
                dungeon->state = FLDDUNGEON_STATE_WAIT_TRANSITION;
            }
            else
            {
                dungeon->state = FLDDUNGEON_STATE_IDLE;
            }
            break;

        case FLDDUNGEON_STATE_WAIT_TRANSITION:
            if (kwlnTaskExists(dungeon->transitionTask) != true)
            {
                datSetFlag(0x1421, false);
                func_001baa50(dungeon->fldRootTask, false);
                dungeon->state = FLDDUNGEON_STATE_IDLE;
            }
            break;

        case FLDDUNGEON_STATE_STOP:
            return KWLNTASK_STOP;
    }

    return KWLNTASK_CONTINUE;
}

// FUN_001bfaf0
void K_FldDungeon_DestroyTask(KwlnTask* dungeonTask)
{
    s32 i;

    func_001c07f0();
    K_FldDungeon_DestroyScrMemory();
    gDungeonTask = NULL;
    gMtScene->fldMajorId = 0;

    for (i = 0; i < 9; i++)
    {
        if (D_0086BDC0[i] != NULL)
        {
            func_001b3c90(D_0086BDC0[i]);
            D_0086BDC0[i] = NULL;
        }
    }

    if (gDungeonTpMdl != NULL)
    {
        mdlDestroy(gDungeonTpMdl);
        gDungeonTpMdl = NULL;
        D_0086E694[0] = 0;
    }

    ((void (*)(void*))(*(void**)((u8*)&rwGlobals + 0x17c)))(dungeonTask->workData);
}

// FUN_001bfbc0
KwlnTask* K_FldDungeon_CreateTask(KwlnTask* parentTask, u32 floor, u32 param_3)
{
    KwlnTask* dungeonTask;
    FldDungeon* dungeon;

    dungeon = (FldDungeon*)RwCalloc(1, sizeof(FldDungeon), rwMEMHINTDUR_GLOBAL);
    if (dungeon == NULL)
    {
        return NULL;
    }

    gDungeonTask = dungeonTask = kwlnTaskCreateWithAutoPriority(parentTask,
                                                                10,
                                                                "automatic dungeon ",
                                                                K_FldDungeon_UpdateTask,
                                                                K_FldDungeon_DestroyTask,
                                                                dungeon);

    dungeon->currFloor = floor;
    dungeon->unk_08 = param_3;

    if (floor > 1)
    {
        gDungeonTpMdl = mdlCreateFromPath(MODEL_TYPE_FLD,
                                          0xffff,
                                          "field/grmd/fobj000.RMD",
                                          MDL_READASYNC);

        dungeon->scrCdvd = K_FldDungeon_RequestScript();

        K_FldDungeon_FUN_001c03f0();
    }

    return dungeonTask;
}

// FUN_001bfcc0
void func_001bfcc0(void)
{
    FldDungeon* dungeon;
    char eplPath[48];
    s32 i;
    if (gDungeonTask == NULL)
    {
        return;
    }

    dungeon = DUNGEON_GET_WORK();
    dungeon->unk_08 = 0;
    func_001a9470(*(void**)((u8*)K_Field_Get() + 0x1200));
    func_001d4180();

    if (dungeon->floorsData[dungeon->currFloor].effectId !=
        dungeon->floorsData[dungeon->currFloor + 1].effectId)
    {
        if (dungeon->effectEplTask != NULL)
        {
            kwlnTaskDestroyWithHierarchy(dungeon->effectEplTask);
        }
        if (dungeon->floorsData[dungeon->currFloor + 1].effectId < 0xff)
        {
            sprintf(eplPath, "field/effect/DNG%02d.EPL",
                    dungeon->floorsData[dungeon->currFloor + 1].effectId);
            dungeon->effectEplTask = func_001a9080(
                gDungeonTask, eplPath, -1, NULL);
        }
        else
        {
            dungeon->effectEplTask = NULL;
        }
    }
    else if (dungeon->effectEplTask != NULL)
    {
        func_001a9400(dungeon->effectEplTask, dungeon->effectEplSlot);
    }

    if (dungeon->currFloor + 1 > 1)
    {
        if (gDungeonTpMdl == NULL)
        {
            gDungeonTpMdl = mdlCreateFromPath(MODEL_TYPE_FLD, 0xffff,
                                               "field/grmd/fobj000.RMD",
                                               MDL_READASYNC);
        }
        dungeon->scrCdvd = K_FldDungeon_RequestScript();
        K_FldDungeon_FUN_001c03f0();
    }

    if (dungeon->floorsData[dungeon->currFloor].majorId !=
            dungeon->floorsData[dungeon->currFloor + 1].majorId ||
        dungeon->floorsData[dungeon->currFloor].minorId !=
            dungeon->floorsData[dungeon->currFloor + 1].minorId)
    {
        dungeon->fieldFlags |= 0x80000000;
        if (K_Scene_001a0250_y2() == true || func_001a02c0_y2() == true)
        {
            for (i = 0; i < 9; i++)
            {
                if (D_0086BDC0[i] != NULL)
                {
                    func_001b3c90(D_0086BDC0[i]);
                    D_0086BDC0[i] = NULL;
                }
            }
        }
    }

    dungeon->currFloor++;
    K_Field_SetShouldShutdown(dungeon->fldRootTask, true);
    dungeon->state = FLDDUNGEON_STATE_UNK_04;
}

// FUN_001bff00
void K_FldDungeon_RequestShutdown()
{
    if (gDungeonTask != NULL)
    {
        DUNGEON_GET_WORK()->shouldShutdown = true;
    }
}

// FUN_001bff20
u32 K_FldDungeon_GetCurrentFloor_y2()
{
    if (gDungeonTask == NULL)
    {
        return 0;
    }

    return DUNGEON_GET_WORK()->currFloor;
}

// FUN_001bff50
u8 K_FldDungeon_IsCurrentFloorExplorable()
{
    u32 currFloor;

    if (gDungeonTask == NULL)
    {
        currFloor = 0;
    }
    else 
    {
        currFloor = DUNGEON_GET_WORK()->currFloor;
    }

    if (currFloor >= 2 && currFloor < 400)
    {
        return true;
    }

    return false;
}

// FUN_001bffa0
FldDungeonFloorData* K_FldDungeon_GetCurrentFloorData()
{
    if (gDungeonTask == NULL)
    {
        return 0;
    }

    return &DUNGEON_GET_WORK()->floorsData[DUNGEON_GET_WORK()->currFloor];
}

// FUN_001bffe0
void* K_FldDungeon_GetScrMemory()
{
    if (gDungeonTask == NULL)
    {
        return NULL;
    }

    return DUNGEON_GET_WORK()->scrMemory;
}

// FUN_001c0010
u32 K_FldDungeon_GetScrSize()
{
    if (gDungeonTask == NULL)
    {
        return 0;
    }

    return DUNGEON_GET_WORK()->scrSize;
}

// FUN_001c0040
u32 func_001c0040(void)
{
    if (gDungeonTask == NULL)
    {
        return 0;
    }
    return DUNGEON_GET_WORK()->encounterResult;
}

// FUN_001c0070
f32 func_001c0070(void)
{
    f32 result;
    s32 encounterResult;

    result = 1.0f;
    if (gDungeonTask == NULL)
    {
        encounterResult = 0;
    }
    else
    {
        encounterResult = DUNGEON_GET_WORK()->encounterResult;
    }
    switch (encounterResult)
    {
        case 1:
        case 3:
            result = 2.0f;
            break;
        default:
            break;
    }
    return result;
}

// FUN_001c00d0
void func_001c00d0(void)
{
    if (gDungeonTask != NULL && DUNGEON_GET_WORK()->effectEplTask != NULL)
    {
        func_001a9400(DUNGEON_GET_WORK()->effectEplTask,
                      DUNGEON_GET_WORK()->effectEplSlot);
    }
}

// FUN_001c0110
void func_001c0110(void)
{
    FldDungeon* dungeon;
    u8 data[12];
    u8* dataPtr;
    s32 i;

    if (gDungeonTask == NULL)
    {
        return;
    }
    dungeon = DUNGEON_GET_WORK();
    if (dungeon->effectEplTask == NULL)
    {
        return;
    }
    dataPtr = data;
    i = sizeof(data);
    if (dataPtr != NULL)
    {
        do
        {
            *dataPtr = 0;
            dataPtr++;
            i--;
        } while (i != 0);
    }
    dungeon->effectEplSlot = func_001a91b0(dungeon->effectEplTask, data);
}
// FUN_001c0190. Request a cdvd stream to load main tartarus script
HCdvd* K_FldDungeon_RequestScript(void)
{
    HCdvd* cdvd;

    cdvd = NULL;
    if (gDungeonTask == NULL)
    {
        return NULL;
    }

    if (DUNGEON_GET_WORK()->scrMemory == NULL)
    {
        if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
        {
            cdvd = H_Cdvd_Request("field/script/dungeonat.bf", HCDVD_FILENORMAL);
        }
        else
        {
            cdvd = H_Cdvd_Request("field/script/dungeonat_aegis.bf", HCDVD_FILENORMAL);
        }
    }

    return cdvd;
}

// FUN_001c0210. Allocate a new memory block to store tartarus main script by copying H_Cdvd's 'fileMemory'
u32 K_FldDungeon_CreateScrMemory(HCdvd* scrCdvd)
{
    FldDungeon* dungeon;
    s32 fileSize;

    if (gDungeonTask == NULL)
    {
        return true;
    }

    dungeon = DUNGEON_GET_WORK();
    if (scrCdvd == NULL)
    {
        return true;
    }

    if (H_Cdvd_IsFileLoaded(scrCdvd))
    {
        fileSize = scrCdvd->fileSize;
        dungeon->scrMemory = (*(void* (**)(u32, u32, u32))((u8*)&rwGlobals + 0x184))(1, fileSize, rwMEMHINTDUR_GLOBAL);
        dungeon->scrSize = scrCdvd->fileSize;
        memcpy(dungeon->scrMemory, scrCdvd->fileMemory, (s32)scrCdvd->fileSize);

        H_Cdvd_Destroy(scrCdvd);

        return true;
    }

    return false;
}


// FUN_001c02e0
void K_FldDungeon_DestroyScrMemory(void)
{
    FldDungeon* dungeon;

    if (gDungeonTask != NULL)
    {
        dungeon = DUNGEON_GET_WORK();
        if (dungeon->scrMemory != NULL)
        {
            RwFree(dungeon->scrMemory);
            dungeon->scrMemory = NULL;
        }
    }
}

// FUN_001c0330. Request a cdvd stream to load tartarus block specific script (thebel, arqa, etc...)
HCdvd* K_FldDungeon_RequestBlockScript(u32 blockId)
{
    char buffer[128];

    if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
    {
        sprintf(buffer, "field/script/dungeonat%02d.bf", blockId);
    }
    else
    {
        sprintf(buffer, "field/script/dungeonat%02d_aegis.bf", blockId);
    }

    return H_Cdvd_Request(buffer, HCDVD_FILENORMAL);
}

// 0x20c bytes. The transition controller keeps its collision-controller task
// at offset 0x204; the remaining tail is reserved by the retail work layout.




// Retail uses a 100-unit normalized camera ray and reloads the frame origin
// for each model probe and before field-node traversal.
// The previous reconstruction reused a mutated origin and omitted this scale.
// Restoring those real probe semantics increases normalized_diff in this pass,
// but avoids silently testing the wrong collision locations.
// Field-node probes must reload the camera-frame origin at each node helper call.
// Passing the frame itself preserves that live-origin behavior when camera state
// changes during traversal; caching cameraPosition would probe stale locations.
// This intentional semantic correction currently has a larger normalized diff.
// FUN_001c03b0
u32 func_001c03b0(HCdvd* cdvd)
{
    if (cdvd == NULL)
    {
        return true;
    }
    return H_Cdvd_IsFileLoaded(cdvd) != false;
}


#pragma alias datSetActiveSocialLink_s16 datSetActiveSocialLink
#pragma alias adminiGetNowSeqId_u32 adminiGetNowSeqId
#pragma alias adminiGetNextSeqId_u32 adminiGetNextSeqId_y2


// 28-byte payload used when switching to the field sequence.

// 28-byte payload used when switching to the social-link event sequence.


// FUN_001c03f0
void K_FldDungeon_FUN_001c03f0(void)
{
    if (*(KwlnTask**)((u8*)K_Field_Get() + 0x11f4) == NULL && sDngBtlEffectCdvd == NULL)
    {
        sDngBtlEffectCdvd = H_Cdvd_Request("field/btl_effect/btl_eff.pac", HCDVD_FILEARCHIVE);
    }
}


// FUN_001c0440
u32 func_001c0440(void)
{
    if (sDngBtlEffectCdvd == NULL)
    {
        return true;
    }
    if (!H_Cdvd_IsFileLoaded(sDngBtlEffectCdvd))
    {
        return false;
    }

    if (*(KwlnTask**)((u8*)K_Field_Get() + 0x11f4) == NULL)
    {
        *(KwlnTask**)((u8*)K_Field_Get() + 0x11f4) =
            func_001a9080(NULL, "field/effect/DNG_BTL.EPL", 30,
                          sDngBtlEffectCdvd);
    }
    if (*(KwlnTask**)((u8*)K_Field_Get() + 0x11f8) == NULL)
    {
        *(KwlnTask**)((u8*)K_Field_Get() + 0x11f8) =
            func_001a9080(NULL, "field/effect/DNG_BTL2.EPL", -1,
                          sDngBtlEffectCdvd);
    }
    if (*(KwlnTask**)((u8*)K_Field_Get() + 0x11fc) == NULL)
    {
        *(KwlnTask**)((u8*)K_Field_Get() + 0x11fc) =
            func_001a9080(NULL, "field/effect/DNG_BTL3.EPL", 60,
                          sDngBtlEffectCdvd);
    }
    if (*(KwlnTask**)((u8*)K_Field_Get() + 0x1200) == NULL)
    {
        *(KwlnTask**)((u8*)K_Field_Get() + 0x1200) =
            func_001a9080(NULL, "field/effect/DNG_BTL4.EPL", -1,
                          sDngBtlEffectCdvd);
    }
    if (*(KwlnTask**)((u8*)K_Field_Get() + 0x1204) == NULL)
    {
        *(KwlnTask**)((u8*)K_Field_Get() + 0x1204) =
            func_001a9080(NULL, "field/effect/DNG_BTL5.EPL", 40,
                          sDngBtlEffectCdvd);
    }
    if (*(KwlnTask**)((u8*)K_Field_Get() + 0x1208) == NULL)
    {
        *(KwlnTask**)((u8*)K_Field_Get() + 0x1208) =
            func_001a9080(NULL, "field/effect/DNG_BTL6.EPL", 30,
                          sDngBtlEffectCdvd);
    }
    if (*(KwlnTask**)((u8*)K_Field_Get() + 0x120c) == NULL)
    {
        *(KwlnTask**)((u8*)K_Field_Get() + 0x120c) =
            func_001a9080(NULL, "field/effect/DNG_BTL7.EPL", 40,
                          sDngBtlEffectCdvd);
    }
    if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
    {
        return true;
    }
    if (*(KwlnTask**)((u8*)K_Field_Get() + 0x1210) == NULL)
    {
        *(KwlnTask**)((u8*)K_Field_Get() + 0x1210) =
            func_001a9080(NULL, "field/effect/DNG_BTL8.EPL", 8,
                          sDngBtlEffectCdvd);
    }
    if (*(KwlnTask**)((u8*)K_Field_Get() + 0x1214) == NULL)
    {
        *(KwlnTask**)((u8*)K_Field_Get() + 0x1214) =
            func_001a9080(NULL, "field/effect/DNG_BTL9.EPL", 20,
                          sDngBtlEffectCdvd);
    }
    if (*(KwlnTask**)((u8*)K_Field_Get() + 0x1218) == NULL)
    {
        *(KwlnTask**)((u8*)K_Field_Get() + 0x1218) =
            func_001a9080(NULL, "field/effect/DNG_BTL10.EPL", 50,
                          sDngBtlEffectCdvd);
    }
    return true;
}

// FUN_001c0740
u32 func_001c0740(void)
{
    s32 i;

    for (i = 0; i < 10; i++)
    {
        if (*(KwlnTask**)((u8*)K_Field_Get() + 0x11f4 + i * 4) != NULL &&
            !func_001a9180(
                *(KwlnTask**)((u8*)K_Field_Get() + 0x11f4 + i * 4)))
        {
            return false;
        }
    }
    if (sDngBtlEffectCdvd != NULL)
    {
        H_Cdvd_Destroy(sDngBtlEffectCdvd);
        sDngBtlEffectCdvd = NULL;
    }
    return true;
}

// FUN_001c07f0
void func_001c07f0(void)
{
    s32 i;

    for (i = 0; i < 10; i++)
    {
        if (*(KwlnTask**)((u8*)K_Field_Get() + 0x11f4 + i * 4) != NULL)
        {
            kwlnTaskDestroyWithHierarchy(
                *(KwlnTask**)((u8*)K_Field_Get() + 0x11f4 + i * 4));
            *(KwlnTask**)((u8*)K_Field_Get() + 0x11f4 + i * 4) = NULL;
        }
    }
}

// FUN_001C0880
void* func_001c0880(KwlnTask* task)
{
    u8* work;
    s32 state;
    s32 frames;
    f32 alpha;

    work = (u8*)task->workData;
    state = *(s32*)work;
    switch (state)
    {
    case 0:
        frames = *(s32*)(work + 8);
        if (frames > 0)
        {
            alpha = *(f32*)(*(u8**)(work + 4) + 0x18) -
                    (*(f32*)(*(u8**)(work + 4) + 0x18) - *(f32*)(work + 0x0c)) /
                        (f32)frames;
            *(s32*)(work + 8) = frames - 1;
        }
        else
        {
            alpha = *(f32*)(work + 0x0c);
            *(s32*)work = state + 1;
        }
        *(f32*)(*(u8**)(work + 4) + 0x18) = alpha;
        break;
    case 1:
        return KWLNTASK_STOP;
    default:
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_001c0920
void func_001c0920(KwlnTask* task)
{
    *(u32*)((u8*)*(void**)((u8*)task->workData + 4) + 0x20) = 0;
    ((void (*)(void*))DAT_0096017c[0])(task->workData);
}

// FUN_001c0960
void* func_001c0960(KwlnTask* task)
{
    u8* work;
    u8* modelData;
    u8* node;
    RwRGBA* sourceColor;
    RwRGBA color;
    f32 alpha;
    f32 normalizedAlpha;
    void* result;

    work = (u8*)task->workData;
    sourceColor = mdlGetColor(*(Model**)(*(u8**)(work + 4) + 0x104));
    color = *sourceColor;
    switch (*(u32*)work)
    {
    case 0:
        if (*(s32*)(work + 8) > 0)
        {
            alpha = (f32)sourceColor->a;
            alpha -= *(f32*)(work + 0x0c);
            alpha /= (f32)*(s32*)(work + 8);
            alpha = (f32)sourceColor->a - alpha;
            color.a = (u8)alpha;
            *(s32*)(work + 8) -= 1;
        }
        else
        {
            alpha = *(f32*)(work + 0x0c);
            color.a = (u8)alpha;
            *(s32*)work += 1;
        }

        normalizedAlpha = (f32)color.a / 255.0f;
        modelData = *(u8**)(*(u8**)(*(u8**)(work + 4) + 0x104) + 0xe0);

        node = *(u8**)(modelData + 8);
        while (node != NULL)
        {
            *(f32*)(node + 0x18) = normalizedAlpha;
            node = *(u8**)(node + 0x28);
        }
        node = *(u8**)(modelData + 0x14);
        while (node != NULL)
        {
            *(f32*)(node + 0x18) = normalizedAlpha;
            node = *(u8**)(node + 0x28);
        }
        node = *(u8**)(modelData + 0x18);
        while (node != NULL)
        {
            *(f32*)(node + 0x18) = normalizedAlpha;
            node = *(u8**)(node + 0x28);
        }
        node = *(u8**)(modelData + 0x20);
        while (node != NULL)
        {
            *(f32*)(node + 0x18) = normalizedAlpha;
            node = *(u8**)(node + 0x28);
        }
        node = *(u8**)(modelData + 0x0c);
        while (node != NULL)
        {
            *(f32*)(node + 0x18) = normalizedAlpha;
            node = *(u8**)(node + 0x28);
        }
        node = *(u8**)(modelData + 0x10);
        while (node != NULL)
        {
            *(f32*)(node + 0x18) = normalizedAlpha;
            node = *(u8**)(node + 0x28);
        }
        node = *(u8**)(modelData + 0x1c);
        while (node != NULL)
        {
            *(f32*)(node + 0x18) = normalizedAlpha;
            node = *(u8**)(node + 0x28);
        }
        node = *(u8**)(modelData + 0x24);
        while (node != NULL)
        {
            *(f32*)(node + 0x18) = normalizedAlpha;
            node = *(u8**)(node + 0x28);
        }
        modelData = *(u8**)(modelData + 0x28);
        while (modelData != NULL)
        {
            *(f32*)(modelData + 0x18) = normalizedAlpha;
            modelData = *(u8**)(modelData + 0x28);
        }
        mdlSetColor(*(Model**)(*(u8**)(work + 4) + 0x104), &color);
        break;
    case 1:
        goto stop;
    }
    goto done;
stop:
    return KWLNTASK_STOP;
done:
    return KWLNTASK_CONTINUE;
}
// FUN_001c0d30
void func_001c0d30(KwlnTask* task)
{
    *(u32*)((u8*)*(void**)((u8*)task->workData + 4) + 0x108) = 0;
    ((void (*)(void*))DAT_0096017c[0])(task->workData);
}

// FUN_001c0d70 NONMATCHING
void* func_001c0d70(KwlnTask* task)
{
    TransWallCtlWork* work;
    DungeonModelFld* modelFld;
    ResrcFld* fld;
    Model* model;
    KwlnTask* child;
    u8* fadeWork;
    void* camera;
    RwMatrix* cameraFrame;
    RwV3d collisionPosition;
    RwV4d collisionQueryPosition;
    RwV3d cameraPosition;
    RwV3d cameraDirection;
    RwV3d ray[2];
    RwV3d special[2];
    u8 queryData[0x208];

    work = (TransWallCtlWork*)task->workData;
    modelFld = (DungeonModelFld*)MT_Scene_GetResListHead_y2(RESRC_TYPE_MODELFLD);
    fld = (ResrcFld*)MT_Scene_GetResListHead_y2(RESRC_TYPE_FLD);

    switch (work->state)
    {
    case 0:
        break;
    case 1:
        goto stop;
    default:
        goto done;
    }

    K_FldFrame_CtlCopyPos(&collisionPosition, work->collisionTask);
    collisionQueryPosition.x = collisionPosition.x;
    collisionQueryPosition.y = collisionPosition.y;
    collisionQueryPosition.z = collisionPosition.z;
    collisionQueryPosition.w =
        K_FldFrame_CtlGetSphereCollisRadius(work->collisionTask);
    collisionPosition.y +=
        60.0f + collisionQueryPosition.w;
    collisionQueryPosition.x = collisionPosition.x;
    collisionQueryPosition.y = collisionPosition.y;
    collisionQueryPosition.z = collisionPosition.z;
    collisionQueryPosition.w =
        K_FldFrame_CtlGetSphereCollisRadius(work->collisionTask);
    camera = kwlnGetMainCamera();
    cameraFrame = func_004cb2f0(*(void**)((u8*)camera + 4));
    cameraPosition = cameraFrame->pos;
    cameraDirection = cameraFrame->right;
    func_004c69f0(&cameraDirection, &cameraDirection);
    cameraDirection.x *= 100.0f;
    cameraDirection.y *= 100.0f;
    cameraDirection.z *= 100.0f;
    if (gMtScene->fldMajorId == 0x18 &&
        gMtScene->fldMinorId == 0x32 &&
        cameraPosition.x == collisionQueryPosition.x &&
        cameraPosition.y == collisionQueryPosition.y &&
        cameraPosition.z == collisionQueryPosition.z)
    {
        return KWLNTASK_CONTINUE;
    }

    while (modelFld != NULL)
    {
        if ((modelFld->base.flags & 2) != 0)
        {
            model = modelFld->model;
            memset(queryData, 0, 0x208);
            cameraPosition = cameraFrame->pos;

            cameraPosition.x += cameraDirection.x;
            cameraPosition.y += cameraDirection.y;
            cameraPosition.z += cameraDirection.z;
            func_001ad050(mdlGetClump(model), &collisionQueryPosition,
                          &cameraPosition, queryData);

            cameraPosition = cameraFrame->pos;
            cameraPosition.x -= cameraDirection.x;
            cameraPosition.y -= cameraDirection.y;
            cameraPosition.z -= cameraDirection.z;
            func_001ad050(mdlGetClump(model), &collisionQueryPosition,
                          &cameraPosition, queryData);
            if (*(u32*)queryData > 0)
            {
                if (modelFld->fadeTask == NULL &&
                    ((u8*)mdlGetColor(model))[3] == 255)
                {
                    fadeWork = (u8*)((void* (*)(u32, u32, u32))DAT_00960184[0])(
                        1, 0x14, rwMEMHINTDUR_GLOBAL);
                    child = NULL;
                    if (fadeWork != NULL)
                    {
                        child = kwlnTaskCreateWithAutoPriority(
                            task, 10, "field model alpha",
                            func_001c0960, func_001c0d30, fadeWork);
                        *(u8**)(fadeWork + 4) = (u8*)modelFld;
                        *(u32*)(fadeWork + 8) = 5;
                        *(f32*)(fadeWork + 0x0c) = 0.0f;
                    }
                    modelFld->fadeTask = child;
                    modelFld->fadeTimer = 0;
                }
            }
            else if (modelFld->fadeTask == NULL &&
                     ((u8*)mdlGetColor(model))[3] == 0)
            {
                if (modelFld->fadeTimer >= 0xb)
                {
                    fadeWork = (u8*)((void* (*)(u32, u32, u32))DAT_00960184[0])(
                        1, 0x14, rwMEMHINTDUR_GLOBAL);
                    child = NULL;
                    if (fadeWork != NULL)
                    {
                        child = kwlnTaskCreateWithAutoPriority(
                            task, 10, "field model alpha",
                            func_001c0960, func_001c0d30, fadeWork);
                        *(u8**)(fadeWork + 4) = (u8*)modelFld;
                        *(u32*)(fadeWork + 8) = 10;
                        *(f32*)(fadeWork + 0x0c) = 255.0f;
                    }
                    modelFld->fadeTask = child;
                    modelFld->fadeTimer = 0;
                }
                else
                {
                    modelFld->fadeTimer += 1;
                }
            }
        }
        modelFld = (DungeonModelFld*)modelFld->base.next;
    }
    cameraPosition = cameraFrame->pos;

    while (fld != NULL)
    {
        if ((fld->base.flags & 2) != 0 && fld->unk_160 != NULL)
        {
            u32 i;
            u8* entry;

            i = 0;
            while (i < *(u32*)((u8*)fld->unk_160 + 0x14))
            {
                entry = *(u8**)((u8*)fld->unk_160 + 0x98 + i * 4);
                if (entry != NULL)
                {
                    K_Dungeon_ProcessFieldNodes(
                        task, (DungeonNode*)*(u8**)(entry + 0x14), &collisionQueryPosition,
                        cameraFrame, &cameraDirection, queryData,
                        &ray[0], &special[0], 1);
                    K_Dungeon_ProcessFieldNodes(
                        task, (DungeonNode*)*(u8**)(entry + 0x28), &collisionQueryPosition,
                        cameraFrame, &cameraDirection, queryData,
                        &ray[0], &special[0], 0);
                    K_Dungeon_ProcessFieldNodes(
                        task, (DungeonNode*)*(u8**)(entry + 0x24), &collisionQueryPosition,
                        cameraFrame, &cameraDirection, queryData,
                        &ray[0], &special[0], 0);
                }
                i++;
            }
        }

        fld = (ResrcFld*)fld->base.next;
    }
done:
    return KWLNTASK_CONTINUE;
stop:
    return KWLNTASK_STOP;
}



#pragma alias jtbl_0096017C_abs jtbl_0096017C









// Retail reconstruction note: states 3, 5, and 11 each perform field-load
// scheduling directly rather than calling the compact source helper.
// The task/archive predicates and camera-frame offsets follow retail.
// State 11 also queues the special zero-minor resource request path.
// This restores the missing state-machine work; residual differences are
// primarily compiler layout and register-allocation choices.





/* Removing this pragma leaves func_001ba8d0 at normalized_diff 132 (object 372B); with it, normalized_diff 0 (object 376B) — measured W310. */
















// FUN_001c1e20
void func_001c1e20(KwlnTask* transWallTask)
{
    ResrcModelFld* modelFld;
    void* fadeWork;

    modelFld = (ResrcModelFld*)MT_Scene_GetResListHead_y2(RESRC_TYPE_MODELFLD);
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

/* W377: opt_propagation off improves func_001bb300 (nd3604 -> nd3024; object 4780/4912). */
// FUN_001C1F30
KwlnTask* FUN_001c1f30(KwlnTask* parentTask, KwlnTask* collisionTask)
{
    KwlnTask* task;
    TransWallCtlWork* work;
    void* camera;
    RwV3d collisionPosition;

    work = (TransWallCtlWork*)((void* (*)(u32, u32, u32))DAT_00960184[0])(
        1, sizeof(TransWallCtlWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parentTask,
                                          0x83d,
                                          "trans wall CTL",
                                          func_001c0d70,
                                          func_001c1e20,
                                          work);
    work->collisionTask = collisionTask;

    camera = kwlnGetMainCamera();
    func_004cb2f0(*(void**)((u8*)camera + 4));
    K_FldFrame_CtlCopyPos(&collisionPosition, collisionTask);

    return task;
}

// Residual MWCC register allocation and loop scheduling differ from retail; accepted floor.
// Candidate bounds now follow the pattern dimensions; remaining mismatch is compiler codegen.
/* W377: stacking opt_loop_invariants on and opt_propagation off improves func_001bc630 (nd756 -> nd667; object 996/1168). */
// FUN_001C2000
void FUN_001c2000(KwlnTask* transWallTask, KwlnTask* collisionTask)
{
    TransWallCtlWork* work;

    work = (TransWallCtlWork*)transWallTask->workData;
    work->collisionTask = collisionTask;
}

/* W377: stacking opt_common_subs off and opt_lifetimes on improves func_001bcac0 (nd1569 -> nd1551; object 2384/2448). */
// FUN_001C2010
u32 FUN_001c2010(void)
{
    FieldSequenceData data;

    func_0017f8d0();
    memset(&data, 0, sizeof(data));
    data.unk_00 = (u16)scrGetIntPara(0);
    data.unk_02 = (u16)scrGetIntPara(1);
    data.unk_04 = (u16)scrGetIntPara(2);
    data.unk_08 = (u16)scrGetIntPara(3);
    adminiChangeSeq(ADMINI_SEQ_FIELD, &data, 0x1c, false);
    func_001d0270();

    return true;
}

/* W377: opt_loop_invariants on improves func_001bd450 (nd439 -> nd431; object 1132/1136). */
// FUN_001C20B0
u32 FUN_001c20b0(void)
{
    FieldSequenceData data;

    gMtScene->unk_14 = -1;
    func_0017f8d0();
    memset(&data, 0, sizeof(data));
    data.unk_00 = (u16)scrGetIntPara(0);
    data.unk_02 = (u16)scrGetIntPara(1);
    data.unk_04 = (u16)scrGetIntPara(2);
    data.unk_08 = (u16)scrGetIntPara(3);
    adminiChangeSeq(ADMINI_SEQ_FIELD, &data, 0x1c, false);
    func_001d0270();

    return true;
}

// FUN_001C2160
u32 FUN_001c2160(void)
{
    SocialLinkSequenceData data;
    s32 cmdTimer;
    u32 result;

    datSetActiveSocialLink(0xff);
    data.unk_0c = (u32)scrGetIntPara(0);
    data.unk_10 = (u32)scrGetIntPara(1);
    data.unk_14 = (u32)scrGetIntPara(2);

    cmdTimer = scrGetCmdTimer();
    if (cmdTimer == 0)
    {
        adminiChangeSeq(ADMINI_SEQ_FIELD2, &data, 0x1c, false);
        goto common_false;
    }
    if ((s32)scrGetCmdTimer() <= 10)
    {
        goto common_false;
    }
    if (adminiGetNowSeqId_u32() != ADMINI_SEQ_NULL)
    {
        goto checks_false;
    }
    if (adminiGetNextSeqId_u32() != ADMINI_SEQ_INVALID)
    {
        goto checks_false;
    }
    result = true;
    goto done;
checks_false:
    result = false;
    goto done;
common_false:
    result = false;
done:
    return result;
}

/* W377: stacking opt_loop_invariants on and opt_dead_assignments off improves func_001bd950 (nd3513 -> nd2143; object 6328/6352). */
// FUN_001C2240
u32 FUN_001c2240(void)
{
    SocialLinkSequenceData data;
    s32 socialLink;
    s32 cmdTimer;
    u32 result;

    socialLink = scrGetIntPara(3);
    datSetActiveSocialLink_s16((s16)socialLink);
    data.unk_0c = (u32)scrGetIntPara(0);
    data.unk_10 = (u32)scrGetIntPara(1);
    data.unk_14 = (u32)scrGetIntPara(2);

    cmdTimer = scrGetCmdTimer();
    if (cmdTimer == 0)
    {
        adminiChangeSeq(ADMINI_SEQ_FIELD2, &data, 0x1c, false);
        goto common_false;
    }
    if ((s32)scrGetCmdTimer() <= 10)
    {
        goto common_false;
    }
    if (adminiGetNowSeqId_u32() != ADMINI_SEQ_NULL)
    {
        goto checks_false;
    }
    if (adminiGetNextSeqId_u32() != ADMINI_SEQ_INVALID)
    {
        goto checks_false;
    }
    func_00171b50(socialLink);
    result = true;
    goto done;
checks_false:
    result = false;
    goto done;
common_false:
    result = false;
done:
    return result;
}

// FUN_001C2340
u32 FUN_001c2340(void)
{
    SeqDungeon data;

    func_0017f8d0();
    data.floor = (u32)scrGetIntPara(0);
    data.unk_04 = 0;
    if (data.floor == 1)
    {
        DUNGEON_SEQUENCE_FLAG = 1;
    }
    adminiChangeSeq(ADMINI_SEQ_DUNGEON, &data, sizeof(data), false);
    func_001d0270();

    return true;
}

// FUN_001C23B0
u32 FUN_001c23b0(void)
{
    SeqDungeon data;
    s32 i;
    KwlnTask* task;

    func_0017f8d0();
    data.floor = (u32)scrGetIntPara(0);
    data.unk_04 = (u32)scrGetIntPara(1);
    if (data.floor == 1)
    {
        DUNGEON_SEQUENCE_FLAG = 1;
    }
    adminiChangeSeq(ADMINI_SEQ_DUNGEON, &data, sizeof(data), false);

    for (i = 0; i < FLDUNIT_PC_MAX; i++)
    {
        task = *(KwlnTask**)((u8*)gFldUnitsPc + i * sizeof(FldUnit) + 0x16c);
        if (task != NULL)
        {
            kwlnTaskEnableFlags(task, KWLNTASK_FLAG_SUSPENDED, 0);
        }
    }

    return true;
}
