#include "Kosaka/Field/k_field.h"
#include "rw/rwplcore.h"
#include "Kosaka/k_data.h"
#include "Kosaka/Field/k_event.h"
#include "Kosaka/Field/k_unit.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "Main/g_data.h"
#include "rw/rprandom.h"

extern u8 D_0067F600[];
extern const char D_0067F5E0[];
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
extern void func_004c31b0(f32 angle, void* object, const void* axis, u32 mode);
extern void func_004c6be0(void* dst, const void* src, void* object);
extern void func_004c3880(RwMatrix* matrix);
extern u32 func_001c7160(const FldUnit* enemy, const FldUnit* party, f32 distance);
extern u32 FUN_0016F380(u32 parameter);
extern void FUN_0016F3E0(u32 parameter, u32 value);
static u32 sDungeonGenerationAttempts;  // 007ce260
static u32 sDungeonGenerationFailed;    // 007ce264
static u32 sDungeonRoomCounter;         // 007ce25c
#include "Kernel/Kwln/kwlnTask.h"
#include "temporary.h"
extern u32 D_00960184[];
extern void (*jtbl_0096017C)(void* memory);

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
extern void clnd00187ea0(void* task);
extern void* func_001a96c0(KwlnTask* task);
extern void func_001a0040(u32 visible, u32 updateField);
extern void func_0019fec0(const void* position);
extern void func_001c07f0(void);
extern void func_001cd8e0(void);
extern void func_001e7410();
extern void func_00350080(s32 sequence);
extern void func_003c8f70(void);
extern void func_003c8f40(void);
extern void func_00458bb0(void);
extern void func_0045a430(s32 enabled);
extern void func_0045af70(s32 enabled);
extern void func_004cb930();
extern void func_004cb270();
extern void func_001985e0(u8 r, u8 g, u8 b, u8 a);
extern void func_001956d0(void* task, u32 flags, u32 scope);

extern u32 FUN_001b7d60(void);
extern u32 FUN_001b7e30(void);
extern u32 FUN_001c0440(void);
extern u32 FUN_001c0740(void);
extern u32 FUN_00398060(u32 resource);
extern u32 FUN_00398140(u32 resource, s32* id, u16* minor, u16* param4, u16* param5);
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
extern u64 FUN_001bffe0(void);
extern u64 FUN_001c0010(void);

#define FIELD_U8(address)  (*(volatile u8*)(address))
#define FIELD_U16(address) (*(volatile u16*)(address))
#define FIELD_U32(address) (*(volatile u32*)(address))
#define FIELD_S32(address) (*(volatile s32*)(address))
#define FIELD_F32(address) (*(volatile f32*)(address))
#define ROOT_U8(work, offset)  (*(u8*)((u8*)(work) + (offset)))
#define ROOT_U16(work, offset) (*(u16*)((u8*)(work) + (offset)))
#define ROOT_U32(work, offset) (*(u32*)((u8*)(work) + (offset)))
#define ROOT_S32(work, offset) (*(s32*)((u8*)(work) + (offset)))
#define ROOT_F32(work, offset) (*(f32*)((u8*)(work) + (offset)))

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
// FUN_001B9130
asm u32 func_001b9130(void)
{
    .set noreorder
    lw $v0, -0x4aa4($gp)
    jr $ra
    nop
}

// FUN_001b9140 NONMATCHING
void func_001b9140(s16 majorId, s16 minorId)
{
    f32 scale;
    f32 distance;
    f32 clampedDistance;
    RwCamera* camera;
    RwMatrix* cameraMatrix;
    RwMatrix* heroMatrix;
    RwV3d delta;

    scale = 0.0f;
    if (FIELD_U32(0x008717e8) != 0 && FIELD_U32(0x008717f4) != 0)
    {
        camera = kwlnGetMainCamera();
        cameraMatrix = (RwMatrix*)func_004cb2f0(camera->object.object.parent);
        heroMatrix = (RwMatrix*)FUN_00318b60((void*)FIELD_U32(0x008717f0));
        delta.x = cameraMatrix->pos.x - heroMatrix->pos.x;
        delta.y = cameraMatrix->pos.y - heroMatrix->pos.y;
        delta.z = cameraMatrix->pos.z - heroMatrix->pos.z;
        distance = RwV3dLength(&delta);
        clampedDistance = distance < 720.0f ? 720.0f : distance;
        if (clampedDistance > 1100.0f)
        {
            clampedDistance = 1100.0f;
        }
        scale = FIELD_F32(0x007cafec) * (clampedDistance / 1100.0f);
    }

    if (majorId == 0x0e && minorId == 5)
    {
        FIELD_F32(0x007ce234) = FIELD_F32(0x007cb13c);
        FIELD_F32(0x007ce230) = FIELD_F32(0x007cb140);
    }
    else if (((majorId == 6) &&
              (minorId == 1 || minorId == 2 || minorId == 4 || minorId == 7 ||
               minorId == 0x0b || minorId == 0x10 || minorId == 0x14)) ||
             ((majorId == 7) &&
              (minorId == 2 || minorId == 3 || minorId == 4 || minorId == 5)))
    {
        FIELD_F32(0x007ce234) = FIELD_F32(0x007cafec);
        FIELD_F32(0x007ce230) = FIELD_F32(0x007cafa8);
    }
    else if (scale > 0.0f)
    {
        FIELD_F32(0x007ce230) = scale * 128.0f;
        FIELD_F32(0x007ce234) = scale;
    }
    else
    {
        FIELD_F32(0x007ce234) = FIELD_F32(0x007cafec);
        FIELD_F32(0x007ce230) = FIELD_F32(0x007cafa8);
    }
    FIELD_U32(0x007ce22c) = 0x40800000;

}
// FUN_001b9480 NONMATCHING
void* func_001b9480(KwlnTask* fldRootTask)
{
    u8* work;
    u32 state;
    s32 id;
    u16 majorId;
    u16 minorId;
    u16 value;
    u16 aux0;
    u16 aux1;
    u32 request;
    u32 resource;
    u32 camera;
    u64 list;
    u64 list2;

    work = (u8*)fldRootTask->workData;
    state = ROOT_U32(work, 0);
    majorId = ROOT_U16(work, 0x10);
    minorId = ROOT_U16(work, 0x12);

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
                K_Fldrc_RequestFldPac((s16)majorId, (s16)aux0);
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
                ROOT_U32(work, 0x28) = FUN_001e7200((s16)majorId);
                ROOT_U32(work, 0) = 3;
            }
            break;

        case 3:
            if (kwlnTaskExists((KwlnTask*)ROOT_U32(work, 0x28)) != 0)
            {
                ROOT_U32(work, 0x28) = 0;
                FIELD_U32(0x007ce24c) = 0;
                if (ROOT_U32(work, 0x38) == 0)
                {
                    fldRootSetLoadSlot(work);
                }
                ROOT_U32(work, 0) = 4;
            }
            /* fall through */

        case 4:
            request = ROOT_U32(work, 0x40);
            if (ROOT_U32(work, 0x38) != 0 || request == 0 ||
                kwlnTaskExists((KwlnTask*)request) != 1)
            {
                ROOT_U32(work, 0x24) = FUN_001c7e70((s16)majorId, minorId);
                MT_Scene_Load((s32)majorId, (s32)minorId);
                FUN_003b58c0(ROOT_U16(work, 0x18));
                if (ROOT_U16(work, 0x1a) == 0)
                {
                    ROOT_U16(work, 0x1a) = FUN_001b6eb0((s16)majorId, minorId);
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
            if (kwlnTaskExists((KwlnTask*)request) != 0)
            {
                ROOT_U32(work, 0x24) = 0;
                if (MT_Scene_TryLoadFinish() != 0)
                {
                    FIELD_U32(0x007ce24c) = 3;
                    if (ROOT_U32(work, 0x38) == 0)
                    {
                        fldRootSetLoadSlot(work);
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
                if ((majorId < 0x14 || majorId > 0x1c || minorId < 0x32) &&
                    (majorId < 0x28 || majorId > 0x30 || minorId < 0x32))
                {
                    if (majorId < 0x14 || (majorId > 0x1c && majorId < 0x28) ||
                        majorId > 0x30)
                    {
                        ROOT_U32(work, 0x40) =
                            FUN_0035bb40(10, FIELD_U32(0x0086afa8), (s32)minorId - 1);
                    }
                    else if (minorId == 0)
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
                                     (s32)minorId - 0x32);
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
                    FUN_001c1f30(fldRootTask, *(u32*)((u8*)camera + 0xf0));
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
                if (majorId < 200)
                {
                    FIELD_U32(0x00869f8c) = FUN_0018e820(fldRootTask);
                    FUN_001ddca0(-1);
                    FUN_0018eb30(FIELD_U32(0x00869f8c), 0);
                }
                if (majorId == 0x0e && minorId == 5)
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
                    if ((!(majorId == 0x0e && minorId == 5) ||
                         kwlnTaskExists((KwlnTask*)ROOT_U32(work, 0x48)) != 1) &&
                        (FIELD_U32(0x00869f78) == 0 || FUN_0042ba30() != 0) &&
                        FUN_0016f190(0x1410) != 1 && ROOT_U32(work, 4) != 1)
                    {
                        FUN_001d2a10();
                        FUN_001a9850();
                        FUN_001aa1b0();
                        if (majorId == 0x20 && minorId == 2)
                        {
                            FUN_00188650();
                        }
                        func_001b9140((s16)majorId, (s16)minorId);
                        FUN_00187ea0();
                        ROOT_U32(work, 0x44) = 0;
                        FUN_001085c0();
                        if (majorId == 0x20 && minorId == 2)
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
                FUN_001e1230(fldRootTask, *(u32*)((u8*)camera + 0xf0),
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
                    FUN_001d03f0((s16)ROOT_U16(work, 0x14));
                    FUN_001d70a0();
                    if (majorId < 200)
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
                                     (s32)minorId - 1);
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
                    FUN_001c1f30(fldRootTask, *(u32*)((u8*)camera + 0xf0));
                func_001b9140((s16)majorId, (s16)minorId);
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
    u8* work;
    s8 nextSeq;
    RwCamera* camera;

    work = (u8*)fldRootTask->workData;
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
    if ((ROOT_U16(work, 0x10) == 4 && ROOT_U16(work, 0x12) == 10) ||
        FIELD_U32(0x007ce26c) != 0)
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
    nextSeq = adminiGetNextSeqId();
    printf((const char*)0x0067f590, nextSeq);
    if (nextSeq != 2 && nextSeq != 3 && nextSeq != 5)
    {
        MT_Scene_Destroy();
    }
    if ((ROOT_U16(work, 0x10) == 4 && ROOT_U16(work, 0x12) == 10) ||
        FIELD_U32(0x007ce26c) != 0)
    {
        MT_Scene_Destroy();
        FIELD_U32(0x007ce26c) = 0;
    }
    if (ROOT_U16(work, 0x10) > 0x1d && ROOT_U16(work, 0x10) < 0x28 &&
        K_FldDungeon_GetCurrentFloor() == 0)
    {
        func_001c07f0();
    }
    func_00350080(0);
    func_00350080(2);
    func_00350080(3);
    func_00350080(5);
    camera = kwlnGetMainCamera();
    func_004cb930(camera->object.object.parent);
    sField.rootTask = NULL;
    (*jtbl_0096017C)(fldRootTask->workData);
}

// FUN_001ba5f0 NONMATCHING
KwlnTask* func_001ba5f0(KwlnTask* parentTask, u16 majorId, u16 minorId,
                        u16 param4, u16 param5, u16 param6, u32 flags,
                        u8 param8, u8 param9, s16 param10, s32 param11,
                        s32 param12, s32 param13, s32 param14)
{
    void* workData;
    KwlnTask* fldRootTask;
    RwCamera* camera;
    u8* cameraFrame;
    RwMatrixTolerance tolerance;
    RwMatrix* matrix;
    u64 clearBits;
    f32 clearDepth;

    memset(&sField, 0, 0x1148);
    workData = (*(void*(**)(u32, u32, u32))D_00960184)(1, 0x68, 0x40000);
    if (workData == NULL)
    {
        return NULL;
    }

    fldRootTask = kwlnTaskCreateWithAutoPriority(
        parentTask, 10, (const char*)0x0067f5c8, func_001b9480, func_001ba3d0,
        workData);
    sField.rootTask = fldRootTask;
    if (param11 < 1)
    {
        FUN_0017f8d0();
        FUN_0035bfb0();
        ROOT_U16(workData, 0x10) = majorId;
        ROOT_U16(workData, 0x12) = minorId;
        ROOT_U16(workData, 0x18) = param5;
        ROOT_U16(workData, 0x1a) = param6;
        ROOT_U16(workData, 0x14) = param4;
        FIELD_U32(0x00869f98) = flags;
        FIELD_U8(0x00869fa2) = param8;
        FIELD_U8(0x00869fa3) = param9;
        FIELD_U16(0x00869fa4) = (u16)param10;
        K_Fldrc_RequestFldPac((s16)majorId, (s16)minorId);
        if (majorId > 0x1d && majorId < 0x28 &&
            K_FldDungeon_GetCurrentFloor() == 0)
        {
            K_FldDungeon_FUN_001c03f0();
        }
        ROOT_U32(workData, 0) = 1;
    }
    else
    {
        ROOT_U32(workData, 0x38) = FUN_00397ec0(param11, param12, param13, param14);
        ROOT_U32(workData, 0) = 0;
        ROOT_S32(workData, 0x0c) = param11;
    }

    clearBits = *(u64*)(void*)0x0067f5b8;
    clearDepth = *(f32*)(void*)0x0067f5c0;
    camera = kwlnGetMainCamera();
    cameraFrame = (u8*)camera->object.object.parent;
    func_004cb930(cameraFrame);
    camera = kwlnGetMainCamera();
    cameraFrame = (u8*)camera->object.object.parent;
    *(f32*)(cameraFrame + 0x40) = (f32)clearBits;
    *(f32*)(cameraFrame + 0x44) = (f32)(clearBits >> 32);
    *(f32*)(cameraFrame + 0x48) = clearDepth;
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

// FUN_001ba8d0 NONMATCHING
void func_001ba8d0(void)
{
    Resrc* resource;
    Resrc* other;
    KwlnTask* rootTask;

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
    while (other != NULL)
    {
        other->flags &= ~2u;
        other = other->next;
    }
    func_0019fec0(NULL);
    kwlnSetClearColor(0, 0, 0, 0);
    func_001985e0(0, 0, 0, 0);
    if (FIELD_U32(0x007ce268) != 0)
    {
        K_FldDungeon_RequestShutdown();
    }
    else
    {
        rootTask = sField.rootTask;
        K_Field_SetShouldShutdown(rootTask, 1);
    }
    func_001cd8e0();
    H_Snd_StopBgmFade(10);
    func_00109f60(3, 0);
    func_00109f60(4, 0);
}

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

static u8* dungeonPatternCell(DungeonPattern* pattern, u32 x, u32 y)
{
    return pattern->raw + y * 0x18 + x * 8;
}

static void dungeonCopyQuad(u8* dst, const u8* src)
{
    u32 i;

    for (i = 0; i < 4; i++)
    {
        ((u16*)dst)[i] = ((const u16*)src)[i];
    }
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
    u8 temp[4];
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
void func_001bb090(const DungeonPattern* pattern, u32 x, u32 y, u8 direction)
{
    u32 col;
    u32 row;
    u8* cell;
    u8* field;

    if (x + pattern->raw[1] - 1 > 0x0f)
    {
        K_Assert((const char*)D_006833A0, 0x106);
    }
    if (y + pattern->raw[2] - 1 > 0x0f)
    {
        K_Assert((const char*)D_006833A0, 0x107);
    }

    field = (u8*)K_Field_Get();
    field[y * 0x100 + x * 0x10 + 0x49] = 1;
    for (row = 0; row < pattern->raw[2]; row++)
    {
        for (col = 0; col < pattern->raw[1]; col++)
        {
            cell = field + (y + row) * 0x100 + (x + col) * 0x10;
            if (cell[0x48] == 0)
            {
                cell[0x48] = 1;
                cell[0x53] = dungeonPatternCell((DungeonPattern*)pattern, col, row)[0x0e];
                cell[0x4f] = pattern->raw[1];
                cell[0x50] = pattern->raw[2];
                cell[0x4a] = pattern->raw[0];
                cell[0x4e] = direction;
                cell[0x52] = dungeonPatternCell((DungeonPattern*)pattern, col, row)[0x0f];
                cell[0x51] = sDungeonRoomCounter;
            }
            else
            {
                K_Assert((const char*)D_006833A0, 0x124);
            }
        }
    }
    sDungeonRoomCounter++;
}

// FUN_001bb300 NONMATCHING
void func_001bb300(u16 patternId, u16 x, u16 y)
{
    u8* fieldCell;
    u32 width;
    u32 height;
    u32 col;
    u32 row;
    u32 sourceIndex;
    u32 modelCount;
    u32 i;
    RwV3d origin;
    u8* roomCopy;
    u8* modelRecord;
    u32* sourceResource;
    u16 roomResId;
    u16 modelResId;
    u16 modelKind;
    Resrc* roomResource;
    Resrc* modelResource;

    fieldCell = dungeonCell((s32)x, (s32)y);
    if (fieldCell[0x48] == 0 || fieldCell[0x49] == 0)
    {
        return;
    }

    width = fieldCell[0x4f];
    height = fieldCell[0x50];
    origin.x = (f32)x * 800.0f + (f32)(width - 1) * 400.0f;
    origin.y = (f32)(s8)fieldCell[0x52] * 300.0f;
    origin.z = (f32)y * 800.0f + (f32)(height - 1) * 400.0f;
    sourceIndex = fieldCell[0x4a];
    sourceResource = *(u32**)((u8*)K_Field_Get() +
                               0x116c + sourceIndex * sizeof(void*));
    roomCopy = (u8*)func_001b5380(
        sourceResource, &origin, (fieldCell[0x4e] + 2) & 3);
    roomResId = func_003b6790(patternId, roomCopy);
    roomResource = MT_Scene_GetRes(roomResId);
    func_001a0150(roomResId, 1);
    func_0019ff10();

    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            fieldCell = dungeonCell((s32)(x + col), (s32)(y + row));
            *(u16*)(fieldCell + 0x4c) = roomResId;
            if (roomCopy != NULL)
            {
                fieldCell[0x48] = 1;
            }
        }
    }

    if (roomCopy == NULL)
    {
        return;
    }

    modelCount = *(u32*)(roomCopy + 0x118);
    for (i = 0; i < modelCount; i++)
    {
        modelRecord = roomCopy + 0x11c + i * 0x18;
        modelKind = *(u16*)modelRecord;
        if (modelKind == 0)
        {
            modelResId = (u16)K_Misc_FindNextFreeResId(RESRC_TYPE_MODELFLD);
            modelResId = MT_Scene_CreateResModelFld(
                modelResId, *(Model**)(modelRecord + 0x0c));
            modelResource = MT_Scene_GetRes(modelResId);
            if (modelResource != NULL && roomResource != NULL)
            {
                *(u32*)((u8*)modelResource + 0x100) =
                    *(u32*)((u8*)roomResource + 0x100);
                *(u32*)((u8*)modelResource + 0x104) =
                    *(u32*)((u8*)roomResource + 0x104);
                *(u32*)((u8*)modelResource + 0x108) =
                    *(u32*)((u8*)roomResource + 0x108);
                *(u32*)((u8*)modelResource + 0x10c) =
                    *(u32*)((u8*)roomResource + 0x10c);
            }
        }
        else if (modelKind == 1)
        {
            modelResId = (u16)K_Misc_FindNextFreeResId(RESRC_TYPE_11);
            modelResId = func_003b66b0(
                modelResId, *(Model**)(modelRecord + 0x10));
        }
        else
        {
            continue;
        }
        func_001a0150(modelResId, 1);
    }
    *(u32*)(roomCopy + 0x118) = 0;
}

// FUN_001bc630 NONMATCHING
u32 func_001bc630(const DungeonPattern* pattern, s32* x, s32* y)
{
    s32 startX;
    s32 startY;
    s32 roomX;
    s32 roomY;
    s32 row;
    s32 col;
    u8* fieldCell;
    u8* neighbor;
    u8 patternFlags;
    u8 neighborFlags;

    startX = *x;
    startY = *y;
    for (roomY = startY; roomY >= 0; roomY--)
    {
        for (roomX = startX; roomX >= 0; roomX--)
        {
            for (row = 0; row < pattern->raw[2]; row++)
            {
                for (col = 0; col < pattern->raw[1]; col++)
                {
                    patternFlags = dungeonPatternCell((DungeonPattern*)pattern,
                                                       (u32)col,
                                                       (u32)row)[0x0e];
                    fieldCell = dungeonCell(roomX + col, roomY + row);
                    if (fieldCell[0x48] != 0)
                    {
                        goto reject;
                    }
                    if (roomY == 0x0e && (patternFlags & 0x40) != 0)
                    {
                        goto reject;
                    }
                    if (roomY == 1 && (patternFlags & 0x10) != 0)
                    {
                        goto reject;
                    }
                    if (roomX + col == 0x0e && (patternFlags & 0x80) != 0)
                    {
                        goto reject;
                    }
                    if (roomX + col == 1 && (patternFlags & 0x20) != 0)
                    {
                        goto reject;
                    }

                    neighbor = fieldCell - 0x100;
                    if (neighbor[0x48] != 0)
                    {
                        neighborFlags = neighbor[0x53];
                        if (((neighborFlags & 0x40) != 0) !=
                            ((patternFlags & 0x10) != 0))
                        {
                            goto reject;
                        }
                    }
                    neighbor = fieldCell + 0x100;
                    if (neighbor[0x48] != 0)
                    {
                        neighborFlags = neighbor[0x53];
                        if (((neighborFlags & 0x10) != 0) !=
                            ((patternFlags & 0x40) != 0))
                        {
                            goto reject;
                        }
                    }
                    neighbor = fieldCell - 0x10;
                    if (neighbor[0x48] != 0)
                    {
                        neighborFlags = neighbor[0x53];
                        if (((neighborFlags & 0x80) != 0) !=
                            ((patternFlags & 0x20) != 0))
                        {
                            goto reject;
                        }
                    }
                    neighbor = fieldCell + 0x10;
                    if (neighbor[0x48] != 0)
                    {
                        neighborFlags = neighbor[0x53];
                        if (((neighborFlags & 0x20) != 0) !=
                            ((patternFlags & 0x80) != 0))
                        {
                            goto reject;
                        }
                    }
                }
            }

            *x = roomX;
            *y = roomY;
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
    u8* field;
    u8* fieldCell;
    u32 templateId;
    u32 rotation;
    u32 connectionCount;
    s32 placedX;
    s32 placedY;
    u32 row;
    u32 col;
    u32 direction;
    u8 flags;
    const u8* table;

    if (sDungeonGenerationFailed != 0 ||
        x == 0 || y == 0 || x >= 0x0f || y >= 0x0f)
    {
        return;
    }
    fieldCell = dungeonCell((s32)x, (s32)y);
    if (fieldCell[0x48] != 0)
    {
        return;
    }

    field = (u8*)K_Field_Get();
    if (x == field[0x3e] &&
        y == field[0x3f] &&
        datGetScenarioMode() == 0)
    {
        table = D_0067FA26 + patternId * 0x35c;
        memset(pattern.raw, 0, sizeof(pattern.raw));
        memcpy(pattern.raw, table, 0x56);
        func_001bab60(&pattern, 1u << field[0x41]);
        func_001bb090(&pattern, x, y, field[0x41]);
        return;
    }

    sDungeonGenerationAttempts = 0;
    for (;;)
    {
        sDungeonGenerationAttempts++;
        if (sDungeonGenerationAttempts >= 0x2711)
        {
            sDungeonGenerationFailed = 1;
            return;
        }

        field = (u8*)K_Field_Get();
        if (fromX == field[0x3c] && fromY == field[0x3d])
        {
            templateId = (RpRandom() & 7) + 1;
            rotation = RpRandom() & 3;
            if (templateId == 2 || templateId == 4)
            {
                fieldCell = dungeonCell((s32)fromX, (s32)fromY);
                if (fieldCell[0x48] != 0 &&
                    (fieldCell[0x4a] == 1 || fieldCell[0x4a] == 3))
                {
                    continue;
                }
            }
        }
        else
        {
            fieldCell = dungeonCell((s32)fromX, (s32)fromY);
            connectionCount = 0;
            if (fieldCell[-0x100 + 0x48] != 0 &&
                (fieldCell[-0x100 + 0x53] & 0x40) != 0)
            {
                connectionCount++;
            }
            if (fieldCell[-0x10 + 0x48] != 0 &&
                (fieldCell[-0x10 + 0x53] & 0x80) != 0)
            {
                connectionCount++;
            }
            if (fieldCell[0x100 + 0x48] != 0 &&
                (fieldCell[0x100 + 0x53] & 0x10) != 0)
            {
                connectionCount++;
            }
            if (fieldCell[0x10 + 0x48] != 0 &&
                (fieldCell[0x10 + 0x53] & 0x20) != 0)
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

        table = (datGetScenarioMode() == 0
                     ? D_0067F720
                     : D_00681866) +
                patternId * 0x35c + templateId * 0x56;
        memset(pattern.raw, 0, sizeof(pattern.raw));
        memcpy(pattern.raw, table, 0x56);
        func_001bab60(&pattern, 1u << rotation);
        placedX = (s32)x;
        placedY = (s32)y;
        if (!func_001bc630(&pattern, &placedX, &placedY))
        {
            continue;
        }

        func_001bb090(&pattern, (u32)placedX, (u32)placedY,
                      (u8)rotation);
        if ((*(u32*)((u8*)K_Field_Get() + 0x38) & 1) != 0)
        {
            return;
        }
        for (row = 0; row < pattern.raw[2]; row++)
        {
            for (col = 0; col < pattern.raw[1]; col++)
            {
                fieldCell = dungeonCell(placedX + (s32)col,
                                        placedY + (s32)row);
                flags = dungeonPatternCell(&pattern, col, row)[0x0e];
                if ((flags & 0x10) == 0 &&
                    fieldCell[-0x100 + 0x48] == 0)
                {
                    fieldCell[-0x100 + 0x48] = 2;
                }
                if ((flags & 0x20) == 0 &&
                    fieldCell[-0x10 + 0x48] == 0)
                {
                    fieldCell[-0x10 + 0x48] = 2;
                }
                if ((flags & 0x40) == 0 &&
                    fieldCell[0x100 + 0x48] == 0)
                {
                    fieldCell[0x100 + 0x48] = 2;
                }
                if ((flags & 0x80) == 0 &&
                    fieldCell[0x10 + 0x48] == 0)
                {
                    fieldCell[0x10 + 0x48] = 2;
                }
            }
        }
        for (row = 0; row < pattern.raw[2]; row++)
        {
            for (col = 0; col < pattern.raw[1]; col++)
            {
                flags = dungeonPatternCell(&pattern, col, row)[0x0e];
                for (direction = 0; direction < 4; direction++)
                {
                    if ((flags & (1u << (direction + 4))) != 0)
                    {
                        if (direction == 0)
                        {
                            func_001bcac0(patternId, placedX + (s32)col,
                                          placedY + (s32)row - 1,
                                          (u32)placedX, (u32)placedY);
                        }
                        else if (direction == 1)
                        {
                            func_001bcac0(patternId, placedX + (s32)col - 1,
                                          placedY + (s32)row,
                                          (u32)placedX, (u32)placedY);
                        }
                        else if (direction == 2)
                        {
                            func_001bcac0(patternId, placedX + (s32)col,
                                          placedY + (s32)row + 1,
                                          (u32)placedX, (u32)placedY);
                        }
                        else
                        {
                            func_001bcac0(patternId, placedX + (s32)col + 1,
                                          placedY + (s32)row,
                                          (u32)placedX, (u32)placedY);
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
    u8* fieldBase;
    u8* targetCell;
    s32 startX;
    s32 startY;
    s32 targetX;
    s32 targetY;
    s32 rooms;
    s32 exits;
    u32 x;
    u32 y;

    fieldBase = (u8*)K_Field_Get();
    for (;;)
    {
        field = (u8*)K_Field_Get();
        targetCell = dungeonCell(field[0x3c], field[0x3d]);
        if (targetCell[0x48] == 1 &&
            targetCell[0x4a] == 4 &&
            sDungeonGenerationFailed == 0)
        {
            return;
        }

        sDungeonGenerationFailed = 0;
        sDungeonGenerationAttempts = 0;
        sDungeonRoomCounter = 0;
        memset(field + 0x48, 0, 0x1000);
        for (x = 0; x < 0x10; x++)
        {
            dungeonCell((s32)x, 0)[0x48] = 2;
            dungeonCell((s32)x, 0x0f)[0x48] = 2;
        }
        for (y = 0; y < 0x10; y++)
        {
            dungeonCell(0, (s32)y)[0x48] = 2;
            dungeonCell(0x0f, (s32)y)[0x48] = 2;
        }

        field[0x3c] = 0;
        field[0x3d] = 0;
        field[0x3e] = 0;
        field[0x3f] = 0;
        do
        {
            startX = (s32)(RpRandom() % 12) + 2;
            startY = (s32)(RpRandom() % 12) + 2;
            field[0x3c] = (u8)startX;
            field[0x3d] = (u8)startY;
        } while (dungeonCell(startX, startY)[0x48] != 0);
        field[0x40] = (u8)(RpRandom() & 3);
        func_001bcac0(patternId, (u32)startX, (u32)startY, 0, 0);

        do
        {
            targetX = (s32)(RpRandom() % 11) + 2;
            targetY = (s32)(RpRandom() % 11) + 2;
            field[0x3e] = (u8)targetX;
            field[0x3f] = (u8)targetY;
            field[0x41] = (u8)(RpRandom() & 3);
            targetCell = dungeonCell(targetX, targetY);
        } while (targetCell[0x48] != 0 ||
                 dungeonCell(targetX + 1, targetY)[0x48] != 0 ||
                 dungeonCell(targetX, targetY + 1)[0x48] != 0 ||
                 dungeonCell(targetX + 1, targetY + 1)[0x48] != 0);
        func_001bcac0(patternId, (u32)targetX, (u32)targetY, 0, 0);

        rooms = 0;
        exits = 0;
        for (y = 0; y < 0x10; y++)
        {
            for (x = 0; x < 0x10; x++)
            {
                field = dungeonCell((s32)x, (s32)y);
                if (field[0x48] == 1)
                {
                    rooms++;
                }
                if (field[0x4a] == 4)
                {
                    exits++;
                }
            }
        }

        if (rooms < (s32)fieldBase[0x42] ||
            rooms > (s32)fieldBase[0x43])
        {
            sDungeonGenerationFailed = 1;
        }
        if (exits < 2)
        {
            sDungeonGenerationFailed = 1;
        }
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
void func_001bd950(void)
{
    Resrc* fieldResource;
    Resrc* heroResource;
    Resrc* modelFld;
    Resrc* modelNpc;
    Resrc* parent;
    s32 xGrid;
    s32 zGrid;
    s32 i;
    f32 angle;
    const s16* offsets;
    u32 offsetCount;

    if (K_Scene_001a0250() != true && func_001a02c0() != true)
    {
        return;
    }

    fieldResource = MT_Scene_GetResListHead(RESRC_TYPE_FLD);
    heroResource = MT_Scene_GetRes(0x400);
    modelFld = MT_Scene_GetResListHead(RESRC_TYPE_MODELFLD);
    modelNpc = MT_Scene_GetResListHead(RESRC_TYPE_MODELNPC);

    if (heroResource != NULL)
    {
        xGrid = K_FldFrame_CtlGetXGrid(
            ((ResrcModelChar*)heroResource)->collisCtlTask);
        zGrid = K_FldFrame_CtlGetZGrid(
            ((ResrcModelChar*)heroResource)->collisCtlTask);
        for (fieldResource = MT_Scene_GetResListHead(RESRC_TYPE_FLD);
             fieldResource != NULL;
             fieldResource = fieldResource->next)
        {
            fieldResource->flags &= ~2u;
        }
    }
    else
    {
        for (; fieldResource != NULL; fieldResource = fieldResource->next)
        {
            fieldResource->flags |= 2;
        }
        xGrid = 0;
        zGrid = 0;
    }

    angle = FUN_001A5AA0(
        &((RwFrame*)kwlnGetMainCamera()->object.object.parent)->modelling);
    if (angle >= -22.5f && angle <= 22.5f)
    {
        offsets = sDungeonVisibilityOffsets0;
        offsetCount = sizeof(sDungeonVisibilityOffsets0) /
                      sizeof(sDungeonVisibilityOffsets0[0]);
    }
    else if (angle > 22.5f && angle <= 67.5f)
    {
        offsets = sDungeonVisibilityOffsets1;
        offsetCount = sizeof(sDungeonVisibilityOffsets1) /
                      sizeof(sDungeonVisibilityOffsets1[0]);
    }
    else if (angle > 67.5f && angle <= 112.5f)
    {
        offsets = sDungeonVisibilityOffsets2;
        offsetCount = sizeof(sDungeonVisibilityOffsets2) /
                      sizeof(sDungeonVisibilityOffsets2[0]);
    }
    else if (angle > 112.5f && angle <= 157.5f)
    {
        offsets = sDungeonVisibilityOffsets3;
        offsetCount = sizeof(sDungeonVisibilityOffsets3) /
                      sizeof(sDungeonVisibilityOffsets3[0]);
    }
    else if (angle > 157.5f || angle < -157.5f)
    {
        offsets = sDungeonVisibilityOffsets4;
        offsetCount = sizeof(sDungeonVisibilityOffsets4) /
                      sizeof(sDungeonVisibilityOffsets4[0]);
    }
    else if (angle >= -157.5f && angle < -112.5f)
    {
        offsets = sDungeonVisibilityOffsets5;
        offsetCount = sizeof(sDungeonVisibilityOffsets5) /
                      sizeof(sDungeonVisibilityOffsets5[0]);
    }
    else if (angle >= -112.5f && angle < -67.5f)
    {
        offsets = sDungeonVisibilityOffsets6;
        offsetCount = sizeof(sDungeonVisibilityOffsets6) /
                      sizeof(sDungeonVisibilityOffsets6[0]);
    }
    else
    {
        offsets = sDungeonVisibilityOffsets7;
        offsetCount = sizeof(sDungeonVisibilityOffsets7) /
                      sizeof(sDungeonVisibilityOffsets7[0]);
    }
    if (heroResource != NULL)
    {
        dungeonShowResources(xGrid, zGrid, offsets, offsetCount);
    }
    for (modelFld = MT_Scene_GetResListHead(RESRC_TYPE_MODELFLD);
         modelFld != NULL;
         modelFld = modelFld->next)
    {
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
    for (modelNpc = MT_Scene_GetResListHead(RESRC_TYPE_MODELNPC);
         modelNpc != NULL;
         modelNpc = modelNpc->next)
    {
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

// FUN_001bf220 NONMATCHING
void func_001bf220(RwV3d* dst, u32 x, u32 y)
{
    Resrc* resource;
    u8* cell;
    u16 id;
    RwV3d result;

    resource = MT_Scene_GetResListHead(0x12);
    memset(&result, 0, sizeof(result));
    if (K_Scene_001a0250() == true || func_001a02c0() == true)
    {
        cell = dungeonCell((s32)(u16)x, (s32)(u16)y);
        id = *(u16*)(cell + 0x54);
        while (resource != NULL)
        {
            if ((resource->resTypeId & 0x3ff) == (id & 0x3ff))
            {
                result = *(RwV3d*)((u8*)resource + 0x100);
                break;
            }
            resource = resource->next;
        }
    }
    *dst = result;
}

// FUN_001bf340 NONMATCHING
u32 func_001bf340(const FldDungeonFloorData* floorData)
{
    u32 chance;
    u32 random;
    u32 lower;
    u32 upper;
    u32 choice;
    s32 i;

    chance = FUN_0016F380(0x3b);
    if (K_FldDungeon_GetCurrentFloor() >= FUN_0016F380(0x0c))
    {
        return 0;
    }
    if ((s16)(chance - 1) < 0)
    {
        FUN_0016F3E0(0x3b, FUN_0016F380(0x3a));
        return 0;
    }
    if (floorData->minorId != 0)
    {
        return 0;
    }
    if (chance != 1)
    {
        FUN_0016F3E0(0x3b, 0);
        return 0;
    }
    random = RpRandom() % 100;
    lower = FUN_0016F380(0x3c);
    if (random >= lower)
    {
        return 0;
    }
    lower = FUN_0016F380(0x3d);
    upper = FUN_0016F380(0x3e);
    choice = RpRandom() % (lower + upper + FUN_0016F380(0x37));
    FUN_0016F3E0(0x3b, FUN_0016F380(0x3a));
    if (choice < lower)
    {
        return 1;
    }
    if (choice < lower + upper)
    {
        return 2;
    }
    if (choice < lower + upper + FUN_0016F380(0x37))
    {
        return 3;
    }
    for (i = 0; i < 3; i++)
    {
        if (FUN_0016DD60(i) >= 1)
        {
            return 4;
        }
    }
    return 0;
}
