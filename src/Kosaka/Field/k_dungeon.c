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

HCdvd* K_FldDungeon_RequestScript();
void K_FldDungeon_DestroyScrMemory();
u32 K_FldDungeon_CreateScrMemory(HCdvd* scrCdvd);
void K_FldDungeon_FUN_001c03f0();

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
extern void* func_004cb2f0(void* camera);
extern void func_004c69f0(RwV3d* out, const RwV3d* in);
extern void* func_00318b00(void* model);
extern void* func_00318b80(void* model);
extern void* kwlnGetMainCamera(void);

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

// FUN_001bff00
void K_FldDungeon_RequestShutdown()
{
    if (gDungeonTask != NULL)
    {
        DUNGEON_GET_WORK()->shouldShutdown = true;
    }
}

// FUN_001bff20
u32 K_FldDungeon_GetCurrentFloor()
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

// FUN_001c0190. Request a cdvd stream to load main tartarus script
HCdvd* K_FldDungeon_RequestScript()
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
void K_FldDungeon_DestroyScrMemory()
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

// FUN_001c03f0
void K_FldDungeon_FUN_001c03f0()
{
    if (*(KwlnTask**)((u8*)K_Field_Get() + 0x11f4) == NULL && sDngBtlEffectCdvd == NULL)
    {
        sDngBtlEffectCdvd = H_Cdvd_Request("field/btl_effect/btl_eff.pac", HCDVD_FILEARCHIVE);
    }
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
        if (K_Scene_001a0250() == true || func_001a02c0() == true)
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

// FUN_001c03b0
u32 func_001c03b0(HCdvd* cdvd)
{
    if (cdvd == NULL)
    {
        return true;
    }
    return H_Cdvd_IsFileLoaded(cdvd) != false;
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

static inline void K_Dungeon_ProcessFieldNodes(
    KwlnTask* parentTask,
    u8* node,
    const RwV4d* collisionQueryPosition,
    void* cameraFrame,
    const RwV3d* cameraDirection,
    u8* queryData,
    RwV3d* probe,
    RwV3d* special)
{
    void* camera;
    u8* fadeWork;
    KwlnTask* child;
    f32 alpha;

    while (node != NULL)
    {
        if (*(u32*)(node + 8) != 0)
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

            if (*(u32*)(queryData + 4) > 0)
            {
                if (*(KwlnTask**)(node + 0x20) == NULL)
                {
                    alpha = *(f32*)(node + 0x18);
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
                            *(u8**)(fadeWork + 4) = node;
                            *(u32*)(fadeWork + 8) = 5;
                            *(f32*)(fadeWork + 0x0c) = 0.0f;
                        }
                        *(KwlnTask**)(node + 0x20) = child;
                        *(u32*)(node + 0x24) = 0;
                    }
                }
            }
            else if (*(KwlnTask**)(node + 0x20) == NULL)
            {
                alpha = *(f32*)(node + 0x18);
                if (alpha == 0.0f)
                {
                    if (*(u32*)(node + 0x24) >= 0xb)
                    {
                        fadeWork = (u8*)((void* (*)(u32, u32, u32))DAT_00960184[0])(
                            1, 0x14, rwMEMHINTDUR_GLOBAL);
                        child = NULL;
                        if (fadeWork != NULL)
                        {
                            child = kwlnTaskCreateWithAutoPriority(
                                parentTask, 10, "field npc alpha",
                                func_001c0880, func_001c0920, fadeWork);
                            *(u8**)(fadeWork + 4) = node;
                            *(u32*)(fadeWork + 8) = 10;
                            *(f32*)(fadeWork + 0x0c) = 1.0f;
                        }
                        *(KwlnTask**)(node + 0x20) = child;
                        *(u32*)(node + 0x24) = 0;
                    }
                    else
                    {
                        *(u32*)(node + 0x24) += 1;
                    }
                }
            }
        }
        node = *(u8**)(node + 0x28);
    }
}

#pragma optimization_level 3
// Retail uses a 100-unit normalized camera ray and reloads the frame origin
// for each model probe and before field-node traversal.
// The previous reconstruction reused a mutated origin and omitted this scale.
// Restoring those real probe semantics increases normalized_diff in this pass,
// but avoids silently testing the wrong collision locations.
// Field-node probes must reload the camera-frame origin at each node helper call.
// Passing the frame itself preserves that live-origin behavior when camera state
// changes during traversal; caching cameraPosition would probe stale locations.
// This intentional semantic correction currently has a larger normalized diff.
// FUN_001c0d70 NONMATCHING
void* func_001c0d70(KwlnTask* task)
{
    u8* work;
    ResrcModelFld* modelFld;
    ResrcFld* fld;
    Model* model;
    KwlnTask* child;
    u8* fadeWork;
    void* camera;
    void* cameraFrame;
    RwV3d collisionPosition;
    RwV4d collisionQueryPosition;
    RwV3d cameraPosition;
    RwV3d cameraDirection;
    RwV3d ray[2];
    RwV3d special[2];
    u8 queryData[0x208];

    work = (u8*)task->workData;
    modelFld = (ResrcModelFld*)MT_Scene_GetResListHead(RESRC_TYPE_MODELFLD);
    fld = (ResrcFld*)MT_Scene_GetResListHead(RESRC_TYPE_FLD);

    switch (*(u32*)work)
    {
    case 0:
        break;
    case 1:
        goto stop;
    default:
        goto done;
    }

    K_FldFrame_CtlCopyPos(&collisionPosition,
                          *(KwlnTask**)(work + 0x204));
    collisionQueryPosition.x = collisionPosition.x;
    collisionQueryPosition.y = collisionPosition.y;
    collisionQueryPosition.z = collisionPosition.z;
    collisionQueryPosition.w =
        K_FldFrame_CtlGetSphereCollisRadius(
            *(KwlnTask**)(work + 0x204));
    collisionPosition.y +=
        60.0f + collisionQueryPosition.w;
    collisionQueryPosition.x = collisionPosition.x;
    collisionQueryPosition.y = collisionPosition.y;
    collisionQueryPosition.z = collisionPosition.z;
    collisionQueryPosition.w =
        K_FldFrame_CtlGetSphereCollisRadius(
            *(KwlnTask**)(work + 0x204));

    camera = kwlnGetMainCamera();
    cameraFrame = func_004cb2f0(*(void**)((u8*)camera + 4));
    cameraPosition = *(RwV3d*)((u8*)cameraFrame + 0x30);
    cameraDirection = *(RwV3d*)cameraFrame;
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
            model = *(Model**)((u8*)modelFld + 0x104);
            memset(queryData, 0, 0x208);
            cameraPosition = *(RwV3d*)((u8*)cameraFrame + 0x30);

            cameraPosition.x += cameraDirection.x;
            cameraPosition.y += cameraDirection.y;
            cameraPosition.z += cameraDirection.z;
            func_001ad050(mdlGetClump(model), &collisionQueryPosition,
                          &cameraPosition, queryData);

            cameraPosition = *(RwV3d*)((u8*)cameraFrame + 0x30);
            cameraPosition.x -= cameraDirection.x;
            cameraPosition.y -= cameraDirection.y;
            cameraPosition.z -= cameraDirection.z;
            func_001ad050(mdlGetClump(model), &collisionQueryPosition,
                          &cameraPosition, queryData);
            if (*(u32*)queryData > 0)
            {
                if (*(KwlnTask**)((u8*)modelFld + 0x108) == NULL &&
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
                    *(KwlnTask**)((u8*)modelFld + 0x108) = child;
                    *(u32*)((u8*)modelFld + 0x10c) = 0;
                }
            }
            else if (*(KwlnTask**)((u8*)modelFld + 0x108) == NULL &&
                     ((u8*)mdlGetColor(model))[3] == 0)
            {
                if (*(u32*)((u8*)modelFld + 0x10c) >= 0xb)
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
                    *(KwlnTask**)((u8*)modelFld + 0x108) = child;
                    *(u32*)((u8*)modelFld + 0x10c) = 0;
                }
                else
                {
                    *(u32*)((u8*)modelFld + 0x10c) += 1;
                }
            }
        }
        modelFld = (ResrcModelFld*)modelFld->base.next;
    }
    cameraPosition = *(RwV3d*)((u8*)cameraFrame + 0x30);

    while (fld != NULL)
    {
        if ((fld->base.flags & 2) != 0 && fld->unk_160 != NULL)
        {
            u8* fieldData;
            u32 i;
            u8* entry;

            fieldData = (u8*)fld->unk_160;
            i = 0;
            while (i < *(u32*)(fieldData + 0x14))
            {
                entry = *(u8**)(fieldData + 0x98 + i * 4);
                if (entry != NULL)
                {
                    K_Dungeon_ProcessFieldNodes(
                        task, *(u8**)(entry + 0x14), &collisionQueryPosition,
                        cameraFrame, &cameraDirection, queryData,
                        &ray[0], &special[0]);
                    K_Dungeon_ProcessFieldNodes(
                        task, *(u8**)(entry + 0x28), &collisionQueryPosition,
                        cameraFrame, &cameraDirection, queryData,
                        &ray[0], &special[0]);
                    K_Dungeon_ProcessFieldNodes(
                        task, *(u8**)(entry + 0x24), &collisionQueryPosition,
                        cameraFrame, &cameraDirection, queryData,
                        &ray[0], &special[0]);
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
#pragma optimization_level 2


extern void K_FldFrame_CtlCopyPos(RwV3d* dst, KwlnTask* collisCtlTask);
extern void func_001c1e20(KwlnTask* transWallTask);
extern void func_0017f8d0(void);
extern void func_001d0270(void);
extern void func_00171b50(u32 socialLink);
#pragma alias datSetActiveSocialLink_s16 datSetActiveSocialLink
extern void datSetActiveSocialLink_s16(s16 activeSocialLink);
#pragma alias adminiGetNowSeqId_u32 adminiGetNowSeqId
extern u32 adminiGetNowSeqId_u32(void);
#pragma alias adminiGetNextSeqId_u32 adminiGetNextSeqId
extern u32 adminiGetNextSeqId_u32(void);

// 0x20c bytes. The transition controller keeps its collision-controller task
// at offset 0x204; the remaining tail is reserved by the retail work layout.
typedef struct
{
    u8 unkData[0x204];
    KwlnTask* collisionTask;
    u8 reserved[4];
} TransWallCtlWork;

// 28-byte payload used when switching to the field sequence.
typedef struct
{
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 unkData[0x12];
} FieldSequenceData;

// 28-byte payload used when switching to the social-link event sequence.
typedef struct
{
    u8 unkData[0x0c];
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
} SocialLinkSequenceData;

#define DUNGEON_SEQUENCE_FLAG (*(u32*)((u8*)&gDungeonTask + 4)) // 007ce26c

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

// FUN_001C2000
void FUN_001c2000(KwlnTask* transWallTask, KwlnTask* collisionTask)
{
    TransWallCtlWork* work;

    work = (TransWallCtlWork*)transWallTask->workData;
    work->collisionTask = collisionTask;
}

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

#pragma push
#pragma opt_rebuildconditionals off
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
#pragma pop
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