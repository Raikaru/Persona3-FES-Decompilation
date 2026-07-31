#include "Kosaka/Field/k_field.h"
#include "Graphics/Model/mdlManager.h"
#include "rw/rwplcore.h"
#include "Kosaka/k_data.h"
#include "Kosaka/Field/k_event.h"
#include "Kosaka/Field/k_unit.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "Main/g_data.h"
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
extern u8 D_006833C0[];
extern u8 D_006833A0[];
extern u8 D_0086E580[];
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
extern void func_001b3c90(void* resource);
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
#include "Kernel/Kwln/kwlnTask.h"
extern KwlnTask* gDungeonTask;
#include "temporary.h"
extern u32 D_00960184[];
extern void (*jtbl_0096017C)(void* memory);
#pragma alias jtbl_0096017C_abs jtbl_0096017C
extern u32 jtbl_0096017C_abs[];

extern RwCamera* kwlnGetMainCamera(void);
extern void kwlnSetClearColor(u8 r, u8 g, u8 b, u8 a);
extern KwlnTask* kwlnTaskCreateWithAutoPriority(KwlnTask* parentTask, u32 priority,
                                                 const char* name, KwlnTaskUpdateFunc update,
                                                 KwlnTaskDestroyFunc destroy, void* workData);
extern u8 kwlnTaskDestroyWithHierarchy(KwlnTask* task);
extern u32 kwlnTaskExists(KwlnTask* task);

extern void K_Fldrc_RequestFldPac(s16 majorId, s16 minorId);
extern u8 K_Fldrc_IsFldPacLoaded(void);
extern void K_Fldrc_DestroyFldPac(void);
extern u32 K_FldDungeon_GetCurrentFloor(void);
extern void K_FldDungeon_RequestShutdown(void);
extern void K_FldDungeon_FUN_001c03f0(void);
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
#pragma alias adminiGetNextSeqId_u32 adminiGetNextSeqId
extern u32 adminiGetNextSeqId_u32(void);
extern void clnd00187ea0(void* task);
extern void* func_001a96c0(KwlnTask* task);
extern void func_001a0040(u32 visible, u32 updateField);
extern void func_0019fec0(const void* position);
extern void func_001c07f0(void);
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
extern u32 FUN_001c1f30(KwlnTask* task, u32 model);
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

static Field sField; // 00869f60

// FUN_001b90f0
void K_Field_Init()
{
    memset(&sField, 0, sizeof(Field));
}

// FUN_001b9120
Field* K_Field_Get()
{
    return &sField;
}

extern RwMatrix* FUN_00318b60(void* model);
extern u32 FUN_001d5a90(KwlnTask* task);
extern void func_001d8cb0(void);
extern u32 DAT_007ce24c;
// FUN_001B9130
u32 func_001b9130(void)
{
    return DAT_007ce24c;
}
// FUN_001b9140 NONMATCHING
void func_001b9140(u16 majorId, u16 minorId)
{
    f32 scale;
    f32 distance;
    RwV3d cameraPosition;
    RwV3d delta;
    RwMatrix* cameraMatrix;

    scale = 0.0f;
    if ((void*)FIELD_U32(0x008717e8) != NULL)
    {
        if ((void*)FIELD_U32(0x008717f4) != NULL)
        {
            cameraMatrix = (RwMatrix*)func_004cb2f0(
                kwlnGetMainCamera()->object.object.parent);
            cameraPosition = cameraMatrix->pos;
            delta.x = ((RwMatrix*)FUN_00318b60((void*)FIELD_U32(0x008717f0)))->pos.x -
                      cameraPosition.x;
            delta.y = ((RwMatrix*)FUN_00318b60((void*)FIELD_U32(0x008717f0)))->pos.y -
                      cameraPosition.y;
            delta.z = ((RwMatrix*)FUN_00318b60((void*)FIELD_U32(0x008717f0)))->pos.z -
                      cameraPosition.z;
            distance = RwV3dLength(&delta);
            if (distance < 720.0f)
            {
                distance = 720.0f;
            }
            if (distance > 1100.0f)
            {
                distance = 1100.0f;
            }
            scale = fGpffff82fc * (distance / 1100.0f);
        }
    }

    if (majorId == 0x0e && minorId == 5)
    {
        fGpffffb544 = fGpffff844c;
        fGpffffb540 = fGpffff8450;
        uGpffffb53c = 0x40800000;
    }
    else if ((majorId == 6 && minorId == 1) ||
             (majorId == 6 && minorId == 2) ||
             (majorId == 6 && minorId == 4) ||
             (majorId == 6 && minorId == 7) ||
             (majorId == 6 && minorId == 0x0b) ||
             (majorId == 6 && minorId == 0x10) ||
             (majorId == 6 && minorId == 0x14) ||
             (majorId == 7 && minorId == 2) ||
             (majorId == 7 && minorId == 3) ||
             (majorId == 7 && minorId == 4) ||
             (majorId == 7 && minorId == 5))
    {
        fGpffffb544 = fGpffff82fc;
        fGpffffb540 = fGpffff82b8;
        uGpffffb53c = 0x40800000;
    }
    else if (scale > 0.0f)
    {
        fGpffffb540 = scale * 128.0f;
        fGpffffb544 = scale;
        uGpffffb53c = 0x40800000;
    }
    else
    {
        fGpffffb544 = fGpffff82fc;
        fGpffffb540 = fGpffff82b8;
        uGpffffb53c = 0x40800000;
    }

}
// Retail reconstruction note: states 3, 5, and 11 each perform field-load
// scheduling directly rather than calling the compact source helper.
// The task/archive predicates and camera-frame offsets follow retail.
// State 11 also queues the special zero-minor resource request path.
// This restores the missing state-machine work; residual differences are
// primarily compiler layout and register-allocation choices.
// FUN_001b9480 NONMATCHING
void* func_001b9480(KwlnTask* fldRootTask)
{
    u8* work;
    u32 state;
    s32 id;
    u32 value;
    u32 aux0;
    u32 aux1;
    u32 request;
    u32 resource;
    u32 camera;
    u32 list;
    u32 list2;

    work = (u8*)fldRootTask->workData;
    state = ROOT_U32(work, 0);

    switch (state)
    {
        case 0:
            resource = ROOT_U32(work, 0x38);
            if (FUN_00398060(resource) != 0 &&
                FUN_00398140(resource, &id, &aux0, &aux1, &value) == 1)
            {
                if (id == 0)
                {
                    FUN_0019d3f0((const char*)0x0067f578, 0x125);
                }
                ROOT_U16(work, 0x10) = (u16)id;
                ROOT_U16(work, 0x12) = aux0;
                ROOT_U16(work, 0x18) = aux1;
                ROOT_U16(work, 0x1a) = value;
                K_Fldrc_RequestFldPac((s16)ROOT_U16(work, 0x10), (s16)aux0);
                for (id = 0; id < 4; id++)
                {
                    K_FldUnit_DestroyPcMdl(id);
                }
                ROOT_U32(work, 0) = 2;
            }
            else if (resource != 0)
            {
                FUN_0019d3f0((const char*)0x0067f578, 0x135);
            }
            break;

        case 1:
            if (FUN_001b7d60() == 0 || FUN_001b7e30() == 0 ||
                FUN_001c0440() == 0 || FUN_001c0740() == 0)
            {
                return KWLNTASK_CONTINUE;
            }
            ROOT_U32(work, 0) = 2;
            /* fall through */

        case 2:
            if (K_Fldrc_IsFldPacLoaded() != 0)
            {
                ROOT_U32(work, 0x28) = FUN_001e7200((s16)ROOT_U16(work, 0x10));
                ROOT_U32(work, 0) = 3;
            }
            break;

        case 3:
            if (FUN_001e7290(ROOT_U32(work, 0x28),
                             (s16)ROOT_U16(work, 0x10)) != 0)
            {
                ROOT_U32(work, 0x28) = 0;
                FIELD_U32(0x007ce24c) = 0;
                if (ROOT_U32(work, 0x38) == 0 &&
                    FIELD_U32(0x0086afa8) != 0)
                {
                    if ((ROOT_U16(work, 0x10) < 0x14 ||
                         ROOT_U16(work, 0x10) > 0x1c ||
                         ROOT_U16(work, 0x12) < 0x32) &&
                        (ROOT_U16(work, 0x10) < 0x28 ||
                         ROOT_U16(work, 0x10) > 0x30 ||
                         ROOT_U16(work, 0x12) < 0x32))
                    {
                        if (ROOT_U16(work, 0x10) < 0x14 ||
                            (ROOT_U16(work, 0x10) > 0x1c &&
                             ROOT_U16(work, 0x10) < 0x28) ||
                            ROOT_U16(work, 0x10) > 0x30)
                        {
                            ROOT_U32(work, 0x40) =
                                FUN_0035bb40(10, FIELD_U32(0x0086afa8),
                                             (s32)ROOT_U16(work, 0x12) - 1);
                        }
                    }
                    else
                    {
                        ROOT_U32(work, 0x40) =
                            FUN_0035bb40(10, FIELD_U32(0x0086afa8),
                                         (s32)ROOT_U16(work, 0x12) - 0x32);
                    }
                }
                ROOT_U32(work, 0) = 4;
            }
            /* fall through */

        case 4:
            request = ROOT_U32(work, 0x40);
            if (ROOT_U32(work, 0x38) != 0 || request == 0 ||
                kwlnTaskExists((KwlnTask*)request) != 1)
            {
                ROOT_U32(work, 0x24) =
                    FUN_001c7e70((s16)ROOT_U16(work, 0x10), ROOT_U16(work, 0x12));
                MT_Scene_Load((s32)ROOT_U16(work, 0x10), (s32)ROOT_U16(work, 0x12));
                FUN_003b58c0(ROOT_U16(work, 0x18));
                if (ROOT_U16(work, 0x1a) == 0)
                {
                    ROOT_U16(work, 0x1a) =
                        FUN_001b6eb0((s16)ROOT_U16(work, 0x10), ROOT_U16(work, 0x12));
                    FUN_003b5980(ROOT_U16(work, 0x1a));
                }
                else
                {
                    FUN_003b5980();
                }
                ROOT_U32(work, 0x44) = FUN_00187e20();
                ROOT_U32(work, 0) = 5;
            }
            /* fall through */

        case 5:
            request = ROOT_U32(work, 0x24);
            if (FUN_001c7f20(request) != 0)
            {
                ROOT_U32(work, 0x24) = 0;
                if (MT_Scene_TryLoadFinish() != 0)
                {
                    FIELD_U32(0x007ce24c) = 3;
                    if (ROOT_U32(work, 0x38) == 0 &&
                        FIELD_U32(0x0086afa8) != 0)
                    {
                        if ((ROOT_U16(work, 0x10) < 0x14 ||
                             ROOT_U16(work, 0x10) > 0x1c ||
                             ROOT_U16(work, 0x12) < 0x32) &&
                            (ROOT_U16(work, 0x10) < 0x28 ||
                             ROOT_U16(work, 0x10) > 0x30 ||
                             ROOT_U16(work, 0x12) < 0x32))
                        {
                            if (ROOT_U16(work, 0x10) < 0x14 ||
                                (ROOT_U16(work, 0x10) > 0x1c &&
                                 ROOT_U16(work, 0x10) < 0x28) ||
                                ROOT_U16(work, 0x10) > 0x30)
                            {
                                ROOT_U32(work, 0x40) =
                                    FUN_0035bb40(10, FIELD_U32(0x0086afa8),
                                                 (s32)ROOT_U16(work, 0x12) - 1);
                            }
                        }
                        else
                        {
                            ROOT_U32(work, 0x40) =
                                FUN_0035bb40(10, FIELD_U32(0x0086afa8),
                                             (s32)ROOT_U16(work, 0x12) - 0x32);
                        }
                    }
                    ROOT_U32(work, 0) = 6;
                }
            }
            break;

        case 6:
            request = ROOT_U32(work, 0x40);
            if (request == 0 || kwlnTaskExists((KwlnTask*)request) != 1)
            {
                FIELD_U32(0x00869f64) = FUN_001d5a90(fldRootTask);
                FUN_001d70a0();
                if (ROOT_U32(work, 0x38) == 0)
                {
                    FUN_001d03f0((s16)ROOT_U32(work, 0x14));
                }
                ROOT_U32(work, 0) = 7;
            }
            /* fall through */

        case 7:
            if (FUN_001ce960() != 0)
            {
                FUN_001d19d0();
                if (ROOT_U32(work, 0x38) == 0)
                {
                    FUN_001d5f30(FIELD_U32(0x00869f64),
                                 *(u32*)(void*)FIELD_U32(0x008717f4));
                    FUN_001d6270(fldRootTask, 1, -1);
                    ROOT_U32(work, 0) = 8;
                }
                else if (FUN_0016f190(0x1410) != 1 && ROOT_U32(work, 4) != 1)
                {
                    if (FUN_003982d0(ROOT_U32(work, 0x38)) == 0)
                    {
                        FUN_001a9850();
                    }
                    FUN_001aa1b0();
                    FUN_00187ea0();
                    ROOT_U32(work, 0x44) = 0;
                    ROOT_U32(work, 0x3c) = FUN_0036f3b0(fldRootTask, ROOT_U32(work, 0x38));
                    ROOT_U32(work, 0) = 0x0e;
                }
            }
            break;

        case 8:
            FIELD_U32(0x007ce24c) = 1;
            if (ROOT_U32(work, 0x38) == 0 && FIELD_U32(0x0086afa8) != 0)
            {
                if ((ROOT_U16(work, 0x10) < 0x14 ||
                     ROOT_U16(work, 0x10) > 0x1c ||
                     ROOT_U16(work, 0x12) < 0x32) &&
                    (ROOT_U16(work, 0x10) < 0x28 ||
                     ROOT_U16(work, 0x10) > 0x30 ||
                     ROOT_U16(work, 0x12) < 0x32))
                {
                    if (ROOT_U16(work, 0x10) < 0x14 ||
                        (ROOT_U16(work, 0x10) > 0x1c &&
                         ROOT_U16(work, 0x10) < 0x28) ||
                        ROOT_U16(work, 0x10) > 0x30)
                    {
                        ROOT_U32(work, 0x40) =
                            FUN_0035bb40(10, FIELD_U32(0x0086afa8),
                                         (s32)ROOT_U16(work, 0x12) - 1);
                    }
                    else if (ROOT_U16(work, 0x12) == 0)
                    {
                        if (FUN_001bffe0() != 0)
                        {
                            list = FUN_001bffe0();
                            list2 = FUN_001c0010();
                            ROOT_U32(work, 0x40) =
                                FUN_0035bc00(10, (u32)list, (u32)list2, 2);
                        }
                        resource = FUN_001bffa0();
                        ROOT_U32(work, 0x2c) =
                            FUN_001c0330(*(u8*)((u8*)resource + 0x0c));
                    }
                }
                else
                {
                    ROOT_U32(work, 0x40) =
                        FUN_0035bb40(10, FIELD_U32(0x0086afa8),
                                     (s32)ROOT_U16(work, 0x12) - 0x32);
                }
            }
            ROOT_U32(work, 0) = 9;
            /* fall through */
        case 9:
            request = ROOT_U32(work, 0x40);
            if (ROOT_U32(work, 0x38) != 0 || request == 0 ||
                kwlnTaskExists((KwlnTask*)request) != 1)
            {
                camera = FIELD_U32(0x008717f4);
                FIELD_U32(0x00869f7c) =
                    FUN_001c1f30(fldRootTask, *(u32*)((u8*)camera + 0x1e0));
                FUN_0016f1f0(0x1411, 0);
                FIELD_U32(0x00869f84) = (u32)FUN_001d36f0(fldRootTask);
                FUN_001d2610();
                FUN_001d1fa0();
                FIELD_U32(0x00869f80) = FUN_001d9f10(fldRootTask);
                if (FUN_001dd600() == 1)
                {
                    FIELD_U32(0x00869f88) = (u32)FUN_0018bff0(fldRootTask);
                    FUN_0018c0c0(FIELD_U32(0x00869f88), 0);
                }
                if (ROOT_U16(work, 0x10) < 200)
                {
                    FIELD_U32(0x00869f8c) = FUN_0018e820(fldRootTask);
                    FUN_001ddca0(-1);
                    FUN_0018eb30(FIELD_U32(0x00869f8c), 0);
                }
                if (ROOT_U16(work, 0x10) == 0x0e && ROOT_U16(work, 0x12) == 5)
                {
                    ROOT_U32(work, 0x48) = FUN_004579b0(fldRootTask);
                }
                FIELD_U32(0x00869f78) =
                    FUN_00429d40(fldRootTask, FIELD_U32(0x007cc2a0));
                ROOT_U32(work, 0) = 0x0a;
            }
            /* fall through */

        case 10:
            if (FUN_001d3790((KwlnTask*)FIELD_U32(0x00869f84)) != 0)
            {
                FUN_001d37f0((KwlnTask*)FIELD_U32(0x00869f84), 1);
                FUN_004532d0(1);
                if (FUN_001c03b0(ROOT_U32(work, 0x2c)) != 0 &&
                    FUN_001d9fd0(FIELD_U32(0x00869f80)) != 0)
                {
                    FUN_001da000(FIELD_U32(0x00869f80), 1);
                    if (FUN_001dd600() == 1)
                    {
                        if (FUN_0018c0a0(FIELD_U32(0x00869f88)) == 0)
                        {
                            return KWLNTASK_CONTINUE;
                        }
                        FUN_001dd8e0();
                    }
                    if ((!(ROOT_U16(work, 0x10) == 0x0e &&
                           ROOT_U16(work, 0x12) == 5) ||
                         kwlnTaskExists((KwlnTask*)ROOT_U32(work, 0x48)) != 1) &&
                        (FIELD_U32(0x00869f78) == 0 || FUN_0042ba30() != 0) &&
                        FUN_0016f190(0x1410) != 1 && ROOT_U32(work, 4) != 1)
                    {
                        FUN_001d2a10();
                        FUN_001a9850();
                        FUN_001aa1b0();
                        if (ROOT_U16(work, 0x10) == 0x20 &&
                            ROOT_U16(work, 0x12) == 2)
                        {
                            FUN_00188650();
                        }
                        func_001b9140(ROOT_U16(work, 0x10),
                                      ROOT_U16(work, 0x12));
                        FUN_00187ea0();
                        ROOT_U32(work, 0x44) = 0;
                        FUN_001085c0();
                        if (ROOT_U16(work, 0x10) == 0x20 &&
                            ROOT_U16(work, 0x12) == 2)
                        {
                            FUN_001086a0(0x28);
                        }
                        ROOT_U32(work, 0) = 0x0b;
                    }
                }
            }
            break;

        case 11:
            if (FUN_00108710() != 0)
            {
                FIELD_U32(0x007ce24c) = 2;
                if (FIELD_U32(0x0086afa8) != 0)
                {
                    if ((ROOT_U16(work, 0x10) < 0x14 ||
                         ROOT_U16(work, 0x10) > 0x1c ||
                         ROOT_U16(work, 0x12) < 0x32) &&
                        (ROOT_U16(work, 0x10) < 0x28 ||
                         ROOT_U16(work, 0x10) > 0x30 ||
                         ROOT_U16(work, 0x12) < 0x32))
                    {
                        if (ROOT_U16(work, 0x10) < 0x14 ||
                            (ROOT_U16(work, 0x10) > 0x1c &&
                             ROOT_U16(work, 0x10) < 0x28) ||
                            ROOT_U16(work, 0x10) > 0x30)
                        {
                            ROOT_U32(work, 0x40) =
                                FUN_0035bb40(10, FIELD_U32(0x0086afa8),
                                             (s32)ROOT_U16(work, 0x12) - 1);
                        }
                        else if (ROOT_U16(work, 0x12) == 0)
                        {
                            resource = ROOT_U32(work, 0x2c);
                            ROOT_U32(work, 0x40) =
                                FUN_0035bb40(
                                    10, *(u32*)((u8*)resource + 0x110), 0);
                        }
                        else
                        {
                            ROOT_U32(work, 0x40) =
                                FUN_0035bb40(10, FIELD_U32(0x0086afa8),
                                             (s32)ROOT_U16(work, 0x12) - 1);
                        }
                    }
                    else
                    {
                        ROOT_U32(work, 0x40) =
                            FUN_0035bb40(10, FIELD_U32(0x0086afa8),
                                         (s32)ROOT_U16(work, 0x12) - 0x32);
                    }
                }
                FUN_0027c080(2, work + 0x4c, 0x1c, 0);
                ROOT_U32(work, 0) = 0x0c;
            }
            break;

        case 12:
            request = ROOT_U32(work, 0x40);
            if (request != 0)
            {
                if (kwlnTaskExists((KwlnTask*)request) == 1)
                {
                    return KWLNTASK_CONTINUE;
                }
                if (ROOT_U32(work, 0x2c) != 0)
                {
                    FUN_00100ec0();
                    ROOT_U32(work, 0x2c) = 0;
                }
            }
            camera = FIELD_U32(0x008717f4);
            FIELD_U32(0x00869f6c) =
                FUN_001e1230(fldRootTask, *(u32*)((u8*)camera + 0x1e0),
                             FIELD_U32(0x008717f0));
            FIELD_U32(0x00869f68) = FUN_001cd5a0(fldRootTask);
            FUN_001d37f0((KwlnTask*)FIELD_U32(0x00869f84), 0);
            FUN_001da000(FIELD_U32(0x00869f80), 0);
            FUN_004532d0(0);
            FUN_004350e0(0, 0);
            if (FIELD_U32(0x00869f78) != 0 && FIELD_U32(0x00869f74) == 0)
            {
                FUN_00429e80(FIELD_U32(0x00869f78), 1);
            }
            if (FIELD_U32(0x00869f88) != 0)
            {
                FUN_0018c0c0(FIELD_U32(0x00869f88), 1);
            }
            if (FIELD_U32(0x00869f8c) != 0)
            {
                FUN_0018eb30(FIELD_U32(0x00869f8c), 1);
            }
            func_0045a430(0);
            func_0045af70(0);
            ROOT_U32(work, 0) = 0x0d;
            break;

        case 13:
            if (ROOT_U32(work, 4) != 0)
            {
                ROOT_U32(work, 0) = 0x12;
            }
            break;

        case 14:
            request = ROOT_U32(work, 0x3c);
            if (kwlnTaskExists((KwlnTask*)request) != 1)
            {
                if (FUN_0036f480() == 0)
                {
                    ROOT_U32(work, 0) = 0x12;
                }
                else
                {
                    FUN_001a9850();
                    FUN_001aa1b0();
                    FUN_0017f8d0();
                    FUN_0035bfb0();
                    ROOT_U16(work, 0x14) = FUN_0036f4c0();
                    FUN_001d03f0(ROOT_U16(work, 0x14));
                    FUN_001d70a0();
                    if (ROOT_U16(work, 0x10) < 200)
                    {
                        FIELD_U32(0x00869f8c) = FUN_0018e820(fldRootTask);
                        FUN_001ddca0(-1);
                    }
                    ROOT_U32(work, 0) = 0x0f;
                }
            }
            break;

        case 15:
            if (FUN_001ce960() != 0)
            {
                FUN_001d2a10();
                FUN_001d5f30(FIELD_U32(0x00869f64),
                             *(u32*)(void*)FIELD_U32(0x008717f4));
                FUN_001d6270(fldRootTask, 1, -1);
                FIELD_U32(0x007ce24c) = 1;
                if (FIELD_U32(0x0086afa8) != 0)
                {
                    ROOT_U32(work, 0x40) =
                        FUN_0035bb40(10, FIELD_U32(0x0086afa8),
                                     (s32)ROOT_U16(work, 0x12) - 1);
                }
                ROOT_U32(work, 0) = 0x10;
            }
            break;

        case 16:
            request = ROOT_U32(work, 0x40);
            if (request == 0 || kwlnTaskExists((KwlnTask*)request) != 1)
            {
                camera = FIELD_U32(0x008717f4);
                FIELD_U32(0x00869f7c) =
                    FUN_001c1f30(fldRootTask, *(u32*)((u8*)camera + 0x1e0));
                func_001b9140(ROOT_U16(work, 0x10), ROOT_U16(work, 0x12));
                FUN_001085c0();
                ROOT_U32(work, 0) = 0x0b;
            }
            break;

        case 17:
            if (FUN_00108710() != 0)
            {
                FUN_0027c080(2, work + 0x4c, 0x1c, 0);
                ROOT_U32(work, 0) = 0x12;
            }
            break;

        case 18:
            return KWLNTASK_STOP;
    }

    return KWLNTASK_CONTINUE;
}



// FUN_001ba3d0 NONMATCHING
void func_001ba3d0(KwlnTask* fldRootTask)
{
    FldRootWork* work;

    work = (FldRootWork*)fldRootTask->workData;
    if (ROOT_U32(work, 0x44) != 0)
    {
        clnd00187ea0((void*)ROOT_U32(work, 0x44));
    }
    func_0045a430(1);
    func_0045af70(1);
    func_003c8f70();
    func_003c8f40();
    func_00109170();
    func_00109e30(4, 0);
    if ((work->majorId == 4 && work->minorId == 10) ||
        DUNGEON_SEQUENCE_FLAG != 0)
    {
        func_001cd8e0();
    }
    K_FldUnit_DestroyAllPc();
    K_FldUnit_DestroyAllEc();
    func_00458bb0();
    if (ROOT_U32(work, 0x38) != 0)
    {
        kwlnTaskDestroyWithHierarchy((KwlnTask*)ROOT_U32(work, 0x38));
    }
    func_001e7410();
    K_Fldrc_DestroyFldPac();
    printf(D_0067F590, adminiGetNextSeqId_u32());
    if (adminiGetNextSeqId_u32() != 2 &&
        adminiGetNextSeqId_u32() != 3 &&
        adminiGetNextSeqId_u32() != 5)
    {
        MT_Scene_Destroy();
    }
    if ((work->majorId == 4 && work->minorId == 10) ||
        DUNGEON_SEQUENCE_FLAG != 0)
    {
        MT_Scene_Destroy();
        DUNGEON_SEQUENCE_FLAG = 0;
    }
    if (work->majorId >= 0x1e)
    {
        if (work->majorId < 0x28 &&
            K_FldDungeon_GetCurrentFloor() == 0)
        {
            func_001c07f0();
        }
    }
    func_00350080(0);
    func_00350080(2);
    func_00350080(3);
    func_00350080(5);
    func_004cb930(kwlnGetMainCamera()->object.object.parent);
    sField.rootTask = NULL;
    (*(void (**)(void*))jtbl_0096017C_abs)(fldRootTask->workData);
}

// FUN_001ba5f0 NONMATCHING
KwlnTask* func_001ba5f0(KwlnTask* parentTask, u16 majorId, u16 minorId,
                        u16 param4, u16 param5, u16 param6, u32 flags,
                        u8 param8, u8 param9, s16 param10, s32 param11,
                        s32 param12, s32 param13, s32 param14)
{
    KwlnTask* fldRootTask;
    void* workData;
    RwCamera* camera;
    u8* cameraFrame;
    RwV3d clearColor;
    RwMatrixTolerance tolerance;
    RwMatrix* matrix;


    memset(&sField, 0, 0x1148);
    workData = (*(void*(**)(u32, u32, u32))D_00960184)(1, 0x68, 0x40000);
    if (workData == NULL)
    {
        return NULL;
    }

    fldRootTask = kwlnTaskCreateWithAutoPriority(
        parentTask, 10, D_0067F5C8, func_001b9480, func_001ba3d0,
        workData);
    sField.rootTask = fldRootTask;
    if (param11 >= 1)
    {
        ROOT_U32(workData, 0x38) = FUN_00397ec0(param11, param12, param13, param14);
        ROOT_U32(workData, 0) = 0;
        ROOT_S32(workData, 0x0c) = param11;
    }
    else
    {
        FUN_0017f8d0();
        FUN_0035bfb0();
        ROOT_U16(workData, 0x10) = majorId;
        ROOT_U16(workData, 0x12) = minorId;
        ROOT_U16(workData, 0x18) = param5;
        ROOT_U16(workData, 0x1a) = param6;
        ROOT_U16(workData, 0x14) = param4;
        *(u32*)D_00869F98 = flags;
        D_00869FA2[0] = param8;
        D_00869FA3[0] = param9;
        *(u16*)D_00869FA4 = (u16)param10;
        K_Fldrc_RequestFldPac((s16)majorId, (s16)minorId);
        if (majorId > 0x1d && majorId < 0x28 &&
            K_FldDungeon_GetCurrentFloor() == 0)
        {
            K_FldDungeon_FUN_001c03f0();
        }
        ROOT_U32(workData, 0) = 1;
    }

    clearColor = D_0067F5B8;
    camera = kwlnGetMainCamera();
    func_004cb930(camera->object.object.parent);
    camera = kwlnGetMainCamera();
    cameraFrame = (u8*)camera->object.object.parent;
    *(RwV3d*)(cameraFrame + 0x40) = clearColor;
    RwEngineGetMatrixTolerances(&tolerance);
    camera = kwlnGetMainCamera();
    matrix = (RwMatrix*)((u8*)camera->object.object.parent + 0x10);
    RwMatrixOptimize(matrix, &tolerance);
    camera = kwlnGetMainCamera();
    func_004cb270(camera->object.object.parent);
    func_001d8cb0();
    FIELD_U32(0x00869f70) = (u32)func_001a96c0(fldRootTask);
    return fldRootTask;
}

/* Removing this pragma leaves func_001ba8d0 at normalized_diff 132 (object 372B); with it, normalized_diff 0 (object 376B) — measured W310. */
#pragma opt_loop_invariants on
// FUN_001ba8d0 MATCHING
void func_001ba8d0(void)
{
    Resrc* resource;
    Resrc* other;
    void* workData;
    KwlnTask* rootTask;
    u32 otherFlags;

    resource = MT_Scene_GetResListHead(3);
    other = MT_Scene_GetResListHead(0x0b);
    Y_TimeLimit_Stop();
    func_001a0040(0, 1);
    while (resource != NULL)
    {
        resource->flags &= ~2u;
        if (*(u32*)((u8*)resource + 0x210) != 0)
        {
            func_001956d0(*(void**)((u8*)resource + 0x210), 0x20, 0);
        }
        resource = resource->next;
    }
    otherFlags = ~2u;
    goto otherTest;
otherLoop:
    other->flags &= otherFlags;
    other = other->next;
otherTest:
    if (other != NULL)
    {
        goto otherLoop;
    }
    func_0019fec0(NULL);
    kwlnSetClearColor(0, 0, 0, 0);
    func_001985e0(0, 0, 0, 0);
    if (gDungeonTask != NULL)
    {
        K_FldDungeon_RequestShutdown();
    }
    else
    {
        rootTask = sField.rootTask;
        workData = rootTask->workData;
        printf(D_0067F5E0);
        ROOT_U32(workData, 8) = 1;
    }
    func_001cd8e0();
    H_Snd_StopBgmFade(10);
    func_00109f60(3, 0);
    func_00109f60(4, 0);
}
#pragma opt_loop_invariants off

// FUN_001baa50
void func_001baa50(KwlnTask* fldRootTask, u32 enabled)
{
    FldRootWork* work;

    work = (FldRootWork*)fldRootTask->workData;
    printf(D_0067F5E0);
    work->unk_04 = enabled;
}

// FUN_001baaa0
void func_001baaa0(KwlnTask* fldRootTask, u16 param2, u16 param3, u16 param4)
{
    u8* work;

    work = (u8*)fldRootTask->workData;
    func_001d0270();
    ROOT_U16(work, 0x4c) = param2;
    ROOT_U16(work, 0x4e) = param3;
    ROOT_U16(work, 0x50) = param4;
    ROOT_U16(work, 0x52) = 0;
    ROOT_U16(work, 0x54) = 0;
    H_Fade_FadeOut();
    H_Fade_SetType(2);
    ROOT_U32(work, 0) = 0x11;
}

// FUN_001ba880
void K_Field_SetShouldShutdown(KwlnTask* fldRootTask, u32 shouldShutdown)
{
    FldRootWork* work;

    work = (FldRootWork*)fldRootTask->workData;
    printf("shutdown field proc\n");

    work->shouldShutdown = shouldShutdown;
}

// FUN_001bab20. Get field major id by the root field task. Not really used that much, 'gMtScene' is used instead
u16 K_Field_GetMajorId(KwlnTask* fldRootTask)
{
    return ((FldRootWork*)fldRootTask->workData)->majorId;
}

// FUN_001bab30. Get field minor id by the root field task. Not really used that much, 'gMtScene' is used instead
u16 K_Field_GetMinorId(KwlnTask* fldRootTask)
{
    return ((FldRootWork*)fldRootTask->workData)->minorId;
}

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
u32 func_001bf340(const FldDungeonFloorData* floorData);

struct DungeonPattern
{
    u8 raw[0x60];
};

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

// FUN_001bab40
u16 func_001bab40(KwlnTask* task)
{
    return *(u16*)((u8*)task->workData + 0x18);
}

// FUN_001bab50
u16 func_001bab50(KwlnTask* task)
{
    return *(u16*)((u8*)task->workData + 0x1a);
}

// FUN_001bab60 NONMATCHING
void func_001bab60(DungeonPattern* pattern, u32 orientationMask)
{
    u32 x;
    u32 y;
    u32 rotation;
    u32 rotationCount;
    u8 temp[8];
    u8* cell;
    u8 value;
    u8 low;
    u8 high;

    for (y = 0; y < 3; y++)
    {
        for (x = 0; x < 3; x++)
        {
            value = pattern->raw[4 + y * 3 + x];
            cell = dungeonPatternCell(pattern, x, y) + 0x0e;
            dungeonCopyQuad(cell, &D_0067F600[value * 8]);
        }
    }

    rotation = 0;
    rotationCount = 0;
    while (rotation < 4)
    {
        if ((1u << rotation) == orientationMask)
        {
            rotationCount = rotation;
            break;
        }
        rotation++;
    }

    if (pattern->raw[1] == 2 && pattern->raw[2] == 2)
    {
        while (rotationCount != 0)
        {
            rotationCount--;
            dungeonCopyQuad(temp, dungeonPatternCell(pattern, 0, 0) + 0x0e);
            dungeonCopyQuad(dungeonPatternCell(pattern, 0, 0) + 0x0e,
                            dungeonPatternCell(pattern, 1, 0) + 0x0e);
            dungeonCopyQuad(dungeonPatternCell(pattern, 1, 0) + 0x0e,
                            dungeonPatternCell(pattern, 1, 1) + 0x0e);
            dungeonCopyQuad(dungeonPatternCell(pattern, 1, 1) + 0x0e,
                            dungeonPatternCell(pattern, 0, 1) + 0x0e);
            dungeonCopyQuad(dungeonPatternCell(pattern, 0, 1) + 0x0e, temp);
        }
    }
    else if (pattern->raw[1] == 1 && pattern->raw[2] == 2)
    {
        if (rotation == 1)
        {
            dungeonCopyQuad(dungeonPatternCell(pattern, 1, 0) + 0x0e,
                            dungeonPatternCell(pattern, 0, 1) + 0x0e);
            dungeonCopyQuad(dungeonPatternCell(pattern, 0, 1) + 0x0e,
                            &D_0067F600[0]);
            pattern->raw[1] = 2;
            pattern->raw[2] = 1;
        }
        else if (rotation == 2)
        {
            dungeonCopyQuad(temp, dungeonPatternCell(pattern, 0, 0) + 0x0e);
            dungeonCopyQuad(dungeonPatternCell(pattern, 0, 0) + 0x0e,
                            dungeonPatternCell(pattern, 0, 1) + 0x0e);
            dungeonCopyQuad(dungeonPatternCell(pattern, 0, 1) + 0x0e, temp);
        }
        else if (rotation == 3)
        {
            dungeonCopyQuad(dungeonPatternCell(pattern, 1, 0) + 0x0e,
                            dungeonPatternCell(pattern, 0, 0) + 0x0e);
            dungeonCopyQuad(dungeonPatternCell(pattern, 0, 0) + 0x0e,
                            dungeonPatternCell(pattern, 0, 1) + 0x0e);
            dungeonCopyQuad(dungeonPatternCell(pattern, 0, 1) + 0x0e,
                            &D_0067F600[0]);
            pattern->raw[1] = 2;
            pattern->raw[2] = 1;
        }
    }
    else if (pattern->raw[1] == 3 && pattern->raw[2] == 3)
    {
        while (rotationCount != 0)
        {
            rotationCount--;
            dungeonCopyQuad(temp, dungeonPatternCell(pattern, 0, 0) + 0x0e);
            dungeonCopyQuad(dungeonPatternCell(pattern, 0, 0) + 0x0e,
                            dungeonPatternCell(pattern, 1, 0) + 0x0e);
            dungeonCopyQuad(dungeonPatternCell(pattern, 1, 0) + 0x0e,
                            dungeonPatternCell(pattern, 2, 0) + 0x0e);
            dungeonCopyQuad(dungeonPatternCell(pattern, 2, 0) + 0x0e,
                            dungeonPatternCell(pattern, 2, 1) + 0x0e);
            dungeonCopyQuad(dungeonPatternCell(pattern, 2, 1) + 0x0e,
                            dungeonPatternCell(pattern, 2, 2) + 0x0e);
            dungeonCopyQuad(dungeonPatternCell(pattern, 2, 2) + 0x0e,
                            dungeonPatternCell(pattern, 1, 2) + 0x0e);
            dungeonCopyQuad(dungeonPatternCell(pattern, 1, 2) + 0x0e,
                            dungeonPatternCell(pattern, 0, 2) + 0x0e);
            dungeonCopyQuad(dungeonPatternCell(pattern, 0, 2) + 0x0e,
                            dungeonPatternCell(pattern, 0, 1) + 0x0e);
            dungeonCopyQuad(dungeonPatternCell(pattern, 0, 1) + 0x0e, temp);
        }
    }

    for (y = 0; y < 3; y++)
    {
        for (x = 0; x < 3; x++)
        {
            cell = dungeonPatternCell(pattern, x, y) + 0x0e;
            value = *cell;
            low = (u8)(value & 0x0f);
            high = (u8)((value >> 4) & 0x0f);
            low = (u8)(((low << rotation) | (low >> (4 - rotation))) & 0x0f);
            high = (u8)(((high << rotation) | (high >> (4 - rotation))) & 0x0f);
            *cell = (u8)(low | (high << 4));
        }
    }
}

// FUN_001bb090 NONMATCHING
void func_001bb090(const DungeonPattern* pattern, u16 x, u16 y, u16 direction)
{
    s32 startX;
    s32 startY;
    s32 col;
    s32 row;
    FieldDungeonCell* cell;
    const u8* patternCell;

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

    cell = &K_Field_Get()->dungeonCells[startY][startX];
    cell->placed = 1;
    for (row = 0; row < pattern->raw[2]; row++)
    {
        for (col = 0; col < pattern->raw[1]; col++)
        {
            cell = &K_Field_Get()->dungeonCells[startY + row][startX + col];
            if (cell->occupied != 0)
            {
                K_Assert((const char*)D_006833A0, 0x124);
                continue;
            }
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
            cell->direction = direction;
            cell = &K_Field_Get()->dungeonCells[startY + row][startX + col];
            cell->elevation = patternCell[0x0f];
            cell = &K_Field_Get()->dungeonCells[startY + row][startX + col];
            cell->roomId = sDungeonRoomCounter;
        }
    }
    sDungeonRoomCounter++;
}

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

// Residual MWCC register allocation and loop scheduling differ from retail; accepted floor.
// Candidate bounds now follow the pattern dimensions; remaining mismatch is compiler codegen.
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
    func_001bcac0(patternId, (u32)startX, (u32)startY, 0, 0);

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
    modelNpc = MT_Scene_GetResListHead(RESRC_TYPE_MODELNPC);

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
        &((RwFrame*)kwlnGetMainCamera()->object.object.parent)->modelling);
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
u32 func_001bf340(const FldDungeonFloorData* floorData)
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
