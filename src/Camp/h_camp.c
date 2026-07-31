#include "Camp/h_camp.h"
#include "Camp/_h_camp_status.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Main/g_data.h"
#include "h_cdvd.h"
#include "h_maestro.h"
#include "rw/rwplcore.h"

extern void* func_0010c1a0();
extern void* func_0010c3a0();
extern void func_00133d30();
extern void func_004d0f00();
extern void func_00123640();
extern KwlnTask* iGpffffb258;
extern KwlnTask* func_00119f10(KwlnTask* parent, u32 initializeMessages);
extern KwlnTask* FUN_00122660(KwlnTask* parent);
extern KwlnTask* FUN_00123000(KwlnTask* parent, void* persona);
extern KwlnTask* FUN_00130F20(KwlnTask* parent, u32 priority, CampVec2 position, u16 param_4);
extern KwlnTask* FUN_00123570(KwlnTask* parent, u32 priority, s16 param_3);
extern KwlnTask* FUN_001336B0(KwlnTask* parent, u32 priority, CampVec2 position, u16 param_4);
extern KwlnTask* FUN_00136750(KwlnTask* parent, u32 priority);
extern KwlnTask* FUN_001548A0(KwlnTask* parent, u32 priority);
extern KwlnTask* FUN_0014EE80(KwlnTask* parent, u32 priority);
extern KwlnTask* FUN_001617D0(KwlnTask* parent, u32 priority);
extern u16 datGetPersonaId(s16 pcId);
extern void* func_00174800(u32 pcId);
extern u32 func_0016f190(s32 flag);
extern u32 FUN_00122710(KwlnTask* task, u32 command);
#pragma alias h_campStatusDrawScreen_typed func_00123640
extern void h_campStatusDrawScreen_typed(CampVec2 position, CampVec2 otherPosition,
                                          f32 alpha, s16 pcId, s32 mode,
                                          s32 phase, s32 fade);
extern f32 fGpffff839c;
extern f32 fGpffff80c4;
extern f32 fGpffff8088;
extern f32 fGpffff82fc;
extern void* uGpffffb260;
extern KwlnTask* iGpffffb270;
extern void func_001958a0(void* source, KwlnTask* destination);
extern void func_001957b0(KwlnTask* source, KwlnTask* destination);
extern void func_0010a4e0(s32 bank, s32 cue, s32 variant, s32 pan);
extern u16 DAT_007e094c;
#pragma alias DAT_007e094c_abs DAT_007e094c
extern u8 DAT_007e094c_abs[];
extern u16 DAT_007e094e;
extern u16 DAT_007e0952;
extern u16 DAT_007e0958;
extern u16 DAT_007e095a;
#pragma alias DAT_007e094e_abs DAT_007e094e
#pragma alias DAT_007e0952_abs DAT_007e0952
#pragma alias DAT_007e0958_abs DAT_007e0958
#pragma alias DAT_007e095a_abs DAT_007e095a
extern u8 DAT_007e094e_abs[];
extern u8 DAT_007e0952_abs[];
extern u8 DAT_007e0958_abs[];
extern u8 DAT_007e095a_abs[];
extern u8* iGpffffb25c;
extern void func_0018bc10(f32 depth, void* transition, s32 drawMode,
                          s32 positionMode, s32 alphaMode,
                          u64 start, u64 end, s32 param0, s32 tile,
                          s32 startFrame, s32 endFrame);
#pragma alias func_0018bc10_buffirst func_0018bc10
extern void func_0018bc10_buffirst(void* transition, s32 drawMode,
                                   s32 positionMode, s32 alphaMode,
                                   u64 start, u64 end, s32 param0, s32 tile,
                                   f32 depth, s32 startFrame, s32 endFrame);
#define func_0018bc10 func_0018bc10_buffirst
#define campStatusDrawTransitionCall(depth, transition, drawMode, positionMode, alphaMode, start, end, param0, tile, startFrame, endFrame) \
    func_0018bc10(depth, transition, drawMode, positionMode, alphaMode, start, end, param0, tile, startFrame, endFrame)
extern void* DAT_00833B78;
extern void* DAT_00833B8C;
#pragma alias DAT_00833B80_abs DAT_00833B80
#pragma alias DAT_00833B8C_abs DAT_00833B8C
#pragma alias DAT_00833B74_abs DAT_00833B74
#pragma alias DAT_00833B84_abs DAT_00833B84
#pragma alias DAT_00833B90_abs DAT_00833B90
#pragma alias DAT_00833BA0_abs DAT_00833BA0
extern u8 DAT_00833B80_abs[];
extern u8 DAT_00833B8C_abs[];
extern u8 DAT_00833B74_abs[];
extern u8 DAT_00833B84_abs[];
extern u8 DAT_00833B90_abs[];
extern u8 DAT_00833BA0_abs[];
extern void* D_00833B70[14];
extern void* func_001158b0(s32, void*, s32);
extern void func_001127d0(void*, u32);
extern void func_00115980(void*);
extern void func_00114450(f32 depth, f32 x, f32 y, u32 color, u32 colorAlpha,
                          s32 ignoredWidth, s32 height,
                          const u32* textureState);
#pragma alias func_00114450_7arg func_00114450
extern void func_00114450_7arg(f32 depth, f32 x, f32 y, u32 color, u32 colorAlpha,
                               s32 ignoredWidth, s32 height);
extern void func_00115ad0(void* parent, void* resource, s32 frame,
                          u32 alpha, u32 extraAlpha, f32 x, f32 y, f32 depth);
extern u32 func_0018b700(void* animation);
extern u32 func_0017d800(void);
extern u32 func_0017d920(void);
extern u32 func_0017da40(void);
extern u32 func_0017db00(void);
extern u32 func_0017dcf0(void);
extern u32 func_0016ef30(void);
extern void* H_Maestro_001120a0(s32 font);
extern s32 datGetMoney(void);
extern void func_00523ac8(char* buffer, const void* format, ...);
extern s32 func_0040eb50(f32 depth, s32 x, s32 y, u32 color,
                         s32 font, const char* text, s32 shadow);
extern void* DAT_00833B80;
extern void* DAT_00833B74;
extern void* DAT_00833B84;
extern void* DAT_00833B90;
extern void* DAT_00833BA0;
extern char gp0xffff8978[];
#pragma alias h_campDrawSprite FUN_001159f0
extern void h_campDrawSprite(void* parent, void* resource, s32 frame,
                             u32 alpha, f32 x, f32 y, f32 scale);

#pragma alias h_campNoopRootDrawCallback_4 h_campNoopRootDrawCallback
extern void h_campNoopRootDrawCallback_4(s32, s32, f32, f32);
#pragma alias h_campNoopRootDrawCallback_5 h_campNoopRootDrawCallback
extern void h_campNoopRootDrawCallback_5(s32, s32, f32, f32, f32);
static const char* sCourageLevels[] = {
    "Timid", "Ordinary", "Determined", "Though", "Fearless", "Badass"
};
static const char* sCharmLevels[] = {
    "Plain", "Unpolished", "Confident", "Smooth", "Popular", "Charismatic"
};
static const char* sAcademicLevels[] = {
    "Slacker", "Average", "Above Average", "Smart", "Intelligent", "Genius"
};

static KwlnTask* sCampPersonaDisplayTask;
static KwlnTask* sCampPersonaControlTask;
static KwlnTask* sCampMenuTask;
static KwlnTask* sCampRootDrawTask;
static s32 sCampSelectedEntry;
static KwlnTask* sCampSpriteSetupTask;
static void* sCampSpriteSetupOwner;
static void* sCampSpriteResources[14];

static const char* sMainMenuAnimation = "camp/main_all/if_c_mai01.anm";
static const char* sStatusMainAnimation = "camp/status/anm/if_c_sta01.anm";
static const char* sStatusDetailAnimation = "camp/status/anm/if_c_sta07.anm";
static const char* sStatusPersonaAnimation = "camp/status/anm/if_c_sta09.anm";
static const char* sItemMainAnimation = "camp/item/anm/i_c_ite01.anm";
static const char* sItemDetailAnimation = "camp/item/anm/i_c_ite02.anm";
static const char* sItemThirdAnimation = "camp/item/anm/i_c_ite03.anm";
static const char* sItemEighthAnimation = "camp/item/anm/i_c_ite08.anm";
static const char* sItemSixthAnimation = "camp/item/anm/i_c_ite06.anm";
static const char* sItemFifthAnimation = "camp/item/anm/i_c_ite05.anm";
static const char* sItemFourthAnimation = "camp/item/anm/i_c_ite04.anm";
static const char* sItemSeventhAnimation = "camp/item/anm/i_c_ite07.anm";
static const char* sSocialMainAnimation = "camp/commu/anm/i_c_com01.anm";
static const char* sSocialDetailAnimation = "camp/commu/anm/i_c_com02.anm";
static const char* sSkillMainAnimation = "camp/skill/anm/if_c_skl01.anm";
static const char* sEquipMainAnimation = "camp/EQUIP/anm/if_c_equ01.anm";
static const char* sSkillDetailAnimation = "camp/skill/anm/if_c_skl02.anm";
static const char* sEquipDetailAnimation = "camp/EQUIP/anm/if_c_equ02.anm";
static const char* sPersonaMainAnimation = "camp/persona/anm/if_c_per01.anm";
static const char* sPersonaDetailAnimation = "camp/persona/anm/if_c_per02.anm";
static const char* sSystemMainAnimation = "camp/system/anm/if_c_sys01.anm";

typedef struct CampDrawWork
{
    u32 state;
    KwlnTask* screenTask;
    u32 unknown08;
    KwlnTask* activeScreenTask;
    KwlnTask* rootTask;
    u8 unknown14[0x18];
    KwlnTask* menuTask;
    u8 unknown30[8];
    u32 needsRootRedraw;
    u32 rootStarted;
    void* cleanupOwner;
    u32 reserved44;
} CampDrawWork;

typedef struct CampUiRecord
{
    u8 opaque[0x38];
    f32 x;
    f32 y;
    u32 color;
    u8 trailing[4];
} CampUiRecord;





// Reconstructed the retail Camp task state machine and all screen transition paths.
// Remaining differences are compiler control-flow/register scheduling and relocation layout;
// the implementation covers states 0-20, task readiness, menu commands, and teardown.
// FUN_0011a050 NONMATCHING
void* h_campUpdateTask(KwlnTask* task)
{
    CampDrawWork* work;
    u32 ready;
    u32 command;
    CampVec2 size;

    work = task->workData;
    switch (work->state) {
    case 0:
        if (iGpffffb258 == NULL) {
            ready = (u32)-1;
        } else if (*(u32*)iGpffffb258->workData == 3) {
            ready = 1;
        } else {
            ready = 0;
        }
        if (ready == (u32)-1) {
            func_00119f10(task, 1);
        }
        h_campCreatePersonaTextureControlTask(task, datGetPersonaId(1));
        work->menuTask = h_campCreateMenuTask(task);
        sCampPersonaDisplayTask = FUN_00122660(task);
        sCampPersonaControlTask = FUN_00123000(task, func_00174800(1));
        sCampMenuTask = work->menuTask;
        sCampSelectedEntry = 0;
        work->rootStarted = 0;
        work->state = 1;
        break;
    case 1:
        ready = (iGpffffb258 == NULL) ? (u32)-1 :
                (*(u32*)iGpffffb258->workData == 3);
        if (ready == 1) {
            datSetFlag(0x1407, 1);
            work->state = 2;
        }
        break;
    case 2:
        if (sCampRootDrawTask != NULL) {
            h_campBeginRootClose(sCampRootDrawTask);
        } else {
            sCampRootDrawTask = h_campCreateRootDrawTask(
                task, work->menuTask, work->rootStarted);
        }
        work->rootStarted = 1;
        work->state = 3;
        break;
    case 3:
        command = h_campGetRootCommand(sCampRootDrawTask);
        switch (command) {
        case (u32)-2:
            h_campBeginRootScreenExit(sCampRootDrawTask);
            h_campRequestRootMenuTransition(work->menuTask, 0);
            h_campRequestMenuTransition(sCampPersonaDisplayTask, 0);
            FUN_00122710(sCampPersonaControlTask, 0);
            work->state = 4;
            break;
        case (u32)-1:
            break;
        case 0:
            sCampSelectedEntry = 0;
            work->state = 19;
            break;
        case 1:
            sCampSelectedEntry = 1;
            work->state = 17;
            break;
        case 2:
            sCampSelectedEntry = 2;
            h_campRequestMenuTransition(sCampPersonaDisplayTask, 4);
            FUN_00122710(sCampPersonaControlTask, 4);
            h_campBeginRootItemExit(sCampRootDrawTask);
            work->state = 11;
            break;
        case 3:
            sCampSelectedEntry = 3;
            h_campRequestMenuTransition(sCampPersonaDisplayTask, 15);
            FUN_00122710(sCampPersonaControlTask, 15);
            h_campBeginRootItemExit(sCampRootDrawTask);
            work->state = 5;
            break;
        case 4:
            sCampSelectedEntry = 4;
            work->state = 9;
            break;
        case 5:
            sCampSelectedEntry = 5;
            h_campBeginRootItemExit(sCampRootDrawTask);
            h_campRequestMenuTransition(sCampPersonaDisplayTask, 7);
            FUN_00122710(sCampPersonaControlTask, 7);
            work->state = 13;
            break;
        case 6:
            sCampSelectedEntry = 6;
            h_campRequestMenuTransition(sCampPersonaDisplayTask, 0);
            work->state = 15;
            break;
        }
        break;
    case 4:
        if (sCampRootDrawTask != NULL) {
            break;
        }
        return KWLNTASK_STOP;
    case 5:
        size.x = 50.0f;
        size.y = 50.0f;
        work->activeScreenTask = FUN_00130F20(task, 0x18be, size, 1);
        work->state = 6;
        break;
    case 6:
        if (kwlnTaskGetState(work->activeScreenTask) == 3) {
            work->activeScreenTask = NULL;
            work->state = 2;
        }
        break;
    case 7:
    case 8:
        break;
    case 9:
        work->activeScreenTask = FUN_00123570(task, 0x18be, 1);
        work->state = 10;
        break;
    case 10:
        if (kwlnTaskGetState(work->activeScreenTask) == 3) {
            work->activeScreenTask = NULL;
            work->state = 2;
        }
        break;
    case 11:
        size.x = 50.0f;
        size.y = 50.0f;
        work->activeScreenTask = FUN_001336B0(task, 0x18be, size, 1);
        work->state = 12;
        break;
    case 12:
        if (kwlnTaskGetState(work->activeScreenTask) == 3) {
            work->activeScreenTask = NULL;
            work->needsRootRedraw = 1;
            work->state = 2;
        }
        break;
    case 13:
        h_campRequestMenuTransition(sCampPersonaDisplayTask, 7);
        FUN_00122710(sCampPersonaControlTask, 7);
        size.x = 50.0f;
        size.y = 50.0f;
        work->activeScreenTask = FUN_00136750(task, 0x18be);
        work->state = 14;
        break;
    case 14:
        if (kwlnTaskGetState(work->activeScreenTask) == 3) {
            work->activeScreenTask = NULL;
            work->needsRootRedraw = 1;
            work->state = 2;
        }
        break;
    case 15:
        h_campRequestMenuTransition(sCampPersonaDisplayTask, 6);
        FUN_00122710(sCampPersonaControlTask, 6);
        work->activeScreenTask = FUN_001548A0(task, 0x18be);
        work->state = 16;
        break;
    case 16:
        if (kwlnTaskGetState(work->activeScreenTask) == 3) {
            work->activeScreenTask = NULL;
            work->needsRootRedraw = 1;
            work->state = 2;
        }
        break;
    case 17:
        work->activeScreenTask = FUN_0014EE80(task, 0x18be);
        work->state = 18;
        break;
    case 18:
        if (kwlnTaskGetState(work->activeScreenTask) == 3) {
            if (func_0016f190(0x1417) != 0) {
                return KWLNTASK_STOP;
            }
            work->activeScreenTask = NULL;
            work->needsRootRedraw = 1;
            work->state = 2;
        }
        break;
    case 19:
        work->activeScreenTask = FUN_001617D0(task, 0x18be);
        work->state = 20;
        break;
    case 20:
        if (kwlnTaskGetState(work->activeScreenTask) == 3) {
            work->activeScreenTask = NULL;
            work->needsRootRedraw = 1;
            work->state = 2;
        }
        break;
    default:
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_0011a710
void h_campDestroyTask(KwlnTask* task)
{
    CampDrawWork* work;

    work = task->workData;
    sCampPersonaDisplayTask = NULL;
    sCampPersonaControlTask = NULL;
    sCampMenuTask = NULL;
    sCampRootDrawTask = NULL;
    datSetFlag(0x1407, 0);
    RwFree(work);
}

// FUN_0011a770
KwlnTask* h_campCreateTask(KwlnTask* parent)
{
    CampDrawWork* work;
    KwlnTask* task;

    work = RwCalloc(1, sizeof(CampDrawWork), 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "H_CampDraw", 0x18BF, h_campUpdateTask,
                          h_campDestroyTask, work);
    if (task == NULL) {
        return NULL;
    }
    return task;
}

// FUN_0011a810
const char* h_camp_getAcademicLevelString(s16 idx)
{
    return sAcademicLevels[idx];
}

// FUN_0011a840
const char* h_camp_getCharmLevelString(s16 idx)
{
    return sCharmLevels[idx];
}

// FUN_0011a870
const char* h_camp_getCourageLevelString(s16 idx)
{
    return sCourageLevels[idx];
}

#pragma push
/* Removing this loop-invariant pragma leaves h_campUpdateSpriteSetupTask at normalized_diff 16; measured with it, normalized_diff is 0. */
#pragma opt_loop_invariants on

// FUN_0011a8a0
void* h_campUpdateSpriteSetupTask(KwlnTask* task)
{
    CampSpriteSetupWork* work;
    s32 i;
    u32 ready;
    u32 size;

    work = task->workData;
    switch (work->state) {
    case 0:
        if (!H_Cdvd_IsFileLoaded(work->archive)) {
            break;
        }
        work->maestroResources[0] = func_00112420(
            H_Cdvd_ArchiveGetFile(work->archive, 0, &size));
        work->maestroResources[1] = func_00112420(
            H_Cdvd_ArchiveGetFile(work->archive, 1, &size));
        work->maestroResources[6] = func_00112420(
            H_Cdvd_ArchiveGetFile(work->archive, 2, &size));
        work->maestroResources[8] = func_00112420(
            H_Cdvd_ArchiveGetFile(work->archive, 3, &size));
        work->maestroResources[9] = func_00112420(
            H_Cdvd_ArchiveGetFile(work->archive, 4, &size));
        work->maestroResources[10] = func_00112420(
            H_Cdvd_ArchiveGetFile(work->archive, 5, &size));
        work->maestroResources[11] = func_00112420(
            H_Cdvd_ArchiveGetFile(work->archive, 6, &size));
        work->maestroResources[12] = func_00112420(
            H_Cdvd_ArchiveGetFile(work->archive, 7, &size));
        work->state = 1;
        break;
    case 1:
        ready = 1;
        for (i = 0; i < 14; i++) {
            if (*(void**)((u32)work + i * 4 + 4) != NULL &&
                !H_Maestro_00111f30(*(void**)((u32)work + i * 4 + 4))) {
                ready = 0;
            }
        }
        if (!ready) {
            break;
        }
        {
            s32 j = 0;
            for (; j < 14; j++) {
                D_00833B70[j] = work->maestroResources[j];
            }
        }
        work->state = 3;
        break;
    case 3:
        break;
    }
    return KWLNTASK_CONTINUE;
}
#pragma pop

#pragma push
/* Removing this loses FUN_0011aae0 (MATCH nd0 -> MISMATCH nd19) - measured W161. */
#pragma opt_loop_invariants on
// FUN_0011aae0
void h_campDestroySpriteSetupTask(KwlnTask* task)
{
    CampSpriteSetupWork* work;
    s32 i;
    s32 j;

    work = task->workData;
    for (i = 0; i < 14; i++) {
        if (work->maestroResources[i] != NULL) {
            func_001124b0(work->maestroResources[i]);
        }
        work->maestroResources[i] = NULL;
    }
    if (work->archive != NULL) {
        H_Cdvd_Destroy(work->archive);
    }
    if (work->cleanupOwner != NULL) {
        RwFree(work->cleanupOwner);
        sCampSpriteSetupOwner = NULL;
    }
    for (j = 0; j < 14; j++) {
        sCampSpriteResources[j] = NULL;
    }
    RwFree(work);
    sCampSpriteSetupTask = NULL;
}
#pragma pop

// FUN_0011abd0 NONMATCHING
u32 h_campUpdatePagedCursor(u32 pageSize, u32 entryCount, s32* firstEntry, s32* selectedEntry)
{
    s32 selected, first;
    u32 changed;
    u16 dpad;
    s32 down;
    s32 up;

    first = *firstEntry;
    selected = *selectedEntry;
    changed = 0;
    down = 1;
    dpad = *(u16*)DAT_007e0952_abs;
    if ((dpad & 0x1000) == 0 && (*(u16*)DAT_007e095a_abs & 0x1000) == 0) {
        down = 0;
    }

    if (down) {
        if (selected == 1) {
            func_0010a4e0(0, 0, 0, 0);
            changed = 1;
            if (first != 0) {
                first--;
            } else {
                selected--;
            }
        } else if (selected == 0) {
            if (((*(u16*)DAT_007e094e_abs & 0x1000) != 0) || ((*(u16*)DAT_007e0958_abs & 0x1000) != 0)) {
                if ((s32)entryCount < (s32)pageSize) {
                    func_0010a4e0(0, 0, 0, 0);
                    changed = 1;
                    selected = entryCount - 1;
                    first = pageSize - entryCount;
                } else if (entryCount != 0 && entryCount != 1) {
                    func_0010a4e0(0, 0, 0, 0);
                    changed = 1;
                    selected = pageSize - 1;
                    first = 0;
                }
            }
        } else {
            if (entryCount != 0 && entryCount != 1) {
                func_0010a4e0(0, 0, 0, 0);
                changed = 1;
                selected--;
            }
        }
    } else {
    up = 1;
    if ((dpad & 0x4000) == 0 && (*(u16*)DAT_007e095a_abs & 0x4000) == 0) {
        up = 0;
    }
    if (up) {
        if (selected == (s32)entryCount - 2) {
            if (first + (s32)entryCount < (s32)pageSize) {
                func_0010a4e0(0, 0, 0, 0);
                changed = 1;
                first++;
            } else if (first + (s32)entryCount - 1 < (s32)pageSize) {
                func_0010a4e0(0, 0, 0, 0);
                changed = 1;
                selected++;
            } else if ((s32)pageSize - 1 == first + selected) {
                if (((*(u16*)DAT_007e094e_abs & 0x4000) != 0) || ((*(u16*)DAT_007e0958_abs & 0x4000) != 0)) {
                    if (entryCount != 0 && entryCount != 1) {
                        func_0010a4e0(0, 0, 0, 0);
                        changed = 1;
                        first = 0;
                        selected = 0;
                    }
                }
            }
        } else if ((s32)pageSize - 1 == first + selected) {
            if (((*(u16*)DAT_007e094e_abs & 0x4000) != 0) || ((*(u16*)DAT_007e0958_abs & 0x4000) != 0)) {
                if (entryCount != 0 && entryCount != 1) {
                    func_0010a4e0(0, 0, 0, 0);
                    changed = 1;
                    first = 0;
                    selected = 0;
                }
            }
        } else {
            if (entryCount != 0 && entryCount != 1) {
                func_0010a4e0(0, 0, 0, 0);
                changed = 1;
                selected++;
            }
        }
    } else if ((dpad & 1) != 0) {
        if ((s32)entryCount < (s32)pageSize) {
            if (first < (s32)entryCount) {
                if (first != 0) {
                    func_0010a4e0(0, 0, 0, 0);
                    changed = 1;
                    first = 0;
                }
            } else {
                func_0010a4e0(0, 0, 0, 0);
                changed = 1;
                first -= entryCount;
            }
            if (selected == (s32)entryCount - 1) {
                selected--;
            }
        }
    } else if ((dpad & 2) != 0) {
        if ((s32)entryCount < (s32)pageSize) {
            if (entryCount * 2 + first < (s32)pageSize) {
                func_0010a4e0(0, 0, 0, 0);
                changed = 1;
                first += entryCount;
            } else {
                s32 newFirst = pageSize - entryCount;
                if (first != newFirst) {
                    func_0010a4e0(0, 0, 0, 0);
                    changed = 1;
                    first = newFirst;
                }
            }
            if (selected == 0) {
                selected++;
            }
        }
    }
    }

    if (changed) {
        *firstEntry = first;
        *selectedEntry = selected;
    }
    return changed;
}

// FUN_0011b0b0
void* h_campUpdatePersonaTextureControlTask(KwlnTask* task)
{
    CampPersonaTextureControlWork* work;
    u32 complete;

    work = task->workData;
    switch (work->state) {
    case 0:
        if (work->resourceId != 0) {
            sprintf(work->path, "camp/persona/pst_%03X.tmx", work->resourceId);
            work->cdvd = H_Cdvd_Request(work->path, HCDVD_FILENORMAL);
            work->state = 1;
        } else {
            work->state = 3;
        }
        break;
    case 1:
        if (!H_Cdvd_IsFileLoaded(work->cdvd)) {
            break;
        }
        work->parsedTexture = func_0010c1a0(0, work->path, 0, 0, 0, 0, 0, 0, 0, 0, "h_camp.c", 0x441);
        work->state = 2;
        break;
    case 2:
        work->archive = func_0010c3a0(work->parsedTexture, &complete, 0);
        if (complete != 0) {
            work->parsedTexture = NULL;
            H_Cdvd_Destroy(work->cdvd);
            work->cdvd = NULL;
            work->state = 3;
        }
        break;
    case 3:
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_0011b210
void h_campDestroyPersonaTextureControlTask(KwlnTask* task)
{
    CampPersonaTextureControlWork* work;

    work = task->workData;
    if (work->parsedTexture != NULL) {
        func_00133d30(work->parsedTexture, work->cdvd);
        work->parsedTexture = NULL;
        work->cdvd = NULL;
        work->archive = NULL;
    } else {
        if (work->cdvd != NULL) {
            H_Cdvd_Destroy(work->cdvd);
            work->cdvd = NULL;
        }
        if (work->archive != NULL) {
            func_004d0f00(work->archive);
            work->archive = NULL;
        }
    }
    RwFree(work);
    sCampPersonaControlTask = NULL;
}

// FUN_0011b2b0
KwlnTask* h_campCreatePersonaTextureControlTask(KwlnTask* parent, u32 resourceId)
{
    CampPersonaTextureControlWork* work;
    KwlnTask* task;

    work = RwCalloc(1, sizeof(CampPersonaTextureControlWork), 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "CampPersonaTexControl", 0x18BF,
                          h_campUpdatePersonaTextureControlTask,
                          h_campDestroyPersonaTextureControlTask, work);
    if (task == NULL) {
        return NULL;
    }
    work->resourceId = resourceId;
    sCampPersonaControlTask = task;
    return task;
}

// FUN_0011b370
void h_campReplacePersonaTextureControlResource(u32 resourceId)
{
    CampPersonaTextureControlWork* work;

    work = sCampPersonaControlTask->workData;
    if (work->resourceId == resourceId) {
        return;
    }
    if (work->parsedTexture != NULL) {
        func_00133d30(work->parsedTexture, work->cdvd);
        work->parsedTexture = NULL;
        work->cdvd = NULL;
        work->archive = NULL;
    } else {
        if (work->cdvd != NULL) {
            H_Cdvd_Destroy(work->cdvd);
            work->cdvd = NULL;
        }
        if (work->archive != NULL) {
            func_004d0f00(work->archive);
            work->archive = NULL;
        }
    }
    work->resourceId = resourceId;
    work->state = 0;
}

// FUN_0011b420 NONMATCHING
void* h_campUpdateRootDrawTask(KwlnTask* task)
{
    CampRootDrawWork* work;

    work = task->workData;
    switch (work->state) {
    case 0:
        work->selectedEntry = sCampSelectedEntry;
        work->state = 2;
        break;
    case 2:
        h_campRequestRootMenuTransition(work->menuTask, 1);
        work->transitionDuration = 0xC8;
        work->state = 3;
        break;
    case 3:
        if (h_campGetRootMenuTransitionComplete(work->menuTask) != 0) {
            work->frame = 0;
            switch (work->menuMode) {
            case 0:
                h_campDrawRootMenuEntries(work, 100.0f);
                work->state = 4;
                break;
            case 1:
                h_campDrawRootMenuEntriesAlternate(work, 100.0f);
                work->state = 5;
                break;
            }
            h_campRequestMenuTransition(sCampPersonaDisplayTask, 1);
            FUN_00122710(sCampPersonaControlTask, 1);
        }
        break;
    case 4:
        work->frame++;
        if (work->frame == 0x15) {
            work->state = 6;
        }
        h_campUpdateRootMenuEntryEffect(work, 100.0f);
        break;
    case 5:
        work->frame++;
        if (work->frame == 0xa) {
            work->state = 6;
        }
        h_campUpdateRootMenuEntryTransition(work, 110.0f);
        break;
    case 7:
        work->frame--;
        if (work->frame == 0) {
            return KWLNTASK_STOP;
        }
        h_campUpdateRootMenuEntryFadeOut(work, 100.0f);
        break;
    case 8:
        work->frame -= 4;
        if (work->frame <= 0) {
            work->frame = 0;
            return KWLNTASK_STOP;
        }
        h_campUpdateRootMenuEntryFadeOut(work, 100.0f);
        break;
    case 9:
        work->frame++;
        if (work->frame >= 0xe) {
            work->frame = 0;
            return KWLNTASK_STOP;
        }
        h_campUpdateRootMenuEntryFinish(work, 100.0f);
        break;
    case 6: {
        u16 buttons;
        u16 dpad;

        buttons = *(u16*)DAT_007e094c_abs;
        if (buttons & 0x20) {
            func_0010a4e0(0, 0, 0, 2);
            work->selectedCommand = -2;
            work->state = 10;
        } else if (buttons & 0x40) {
            func_0010a4e0(0, 0, 0, 1);
            work->selectedCommand = work->selectedEntry;
            work->state = 10;
        } else if (work->drawChild != NULL) {
            s32 changed;

            changed = 1;
            dpad = *(u16*)DAT_007e0952_abs;
            if ((dpad & 0x4000) == 0 &&
                (*(u16*)DAT_007e095a_abs & 0x4000) == 0) {
                changed = 0;
            }
            if (changed != 0) {
                if (work->selectedEntry == 6) {
                    if (((*(u16*)DAT_007e094e_abs & 0x4000) != 0) ||
                        ((*(u16*)DAT_007e0958_abs & 0x4000) != 0)) {
                        func_0010a4e0(0, 0, 0, 0);
                        work->selectedEntry = 0;
                        work->transitionKind = 5;
                        work->selectedEntry = 0;
                        work->timer = 1;
                        work->drawChild = NULL;
                    }
                } else {
                    func_0010a4e0(0, 0, 0, 0);
                    work->transitionKind = 5;
                    work->selectedEntry++;
                    if (func_0017d800() != 0 &&
                        work->selectedEntry == 5) {
                        work->selectedEntry = 6;
                    }
                    work->timer = 1;
                    work->drawChild = NULL;
                }
            } else if ((dpad & 0x1000) != 0 ||
                       (*(u16*)DAT_007e095a_abs & 0x1000) != 0) {
                if (work->selectedEntry == 0) {
                    if (((*(u16*)DAT_007e094e_abs & 0x1000) != 0) ||
                        ((*(u16*)DAT_007e0958_abs & 0x1000) != 0)) {
                        func_0010a4e0(0, 0, 0, 0);
                        work->transitionKind = 5;
                        work->selectedEntry = 6;
                        work->timer = 1;
                        work->drawChild = NULL;
                    }
                } else {
                    func_0010a4e0(0, 0, 0, 0);
                    work->transitionKind = 5;
                    work->timer = 1;
                    work->drawChild = NULL;
                    work->selectedEntry--;
                    if (func_0017d800() != 0 &&
                        work->selectedEntry == 5) {
                        work->selectedEntry = 4;
                    }
                }
            }
            *(f32*)(iGpffffb25c + 0x320) =
                (f32)work->selectedEntry * 19.0f;
        }
        h_campUpdateRootMenuSelectionEffect(work, 100.0f);
        break;
    }
    case 10:
        work->frame = 0x16;
        h_campUpdateRootMenuEntryTransition(work, 100.0f);
        break;
    case 1:
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_0011b9a0
u32 h_campGetRootCommand(KwlnTask* task)
{
    CampRootDrawWork* work;

    work = task->workData;
    return work->selectedCommand;
}

// FUN_0011b9b0
void h_campBeginRootScreenExit(KwlnTask* task)
{
    CampRootDrawWork* work;

    work = task->workData;
    h_campDrawRootMenuEntriesClosing(work, 100.0f);
    work->state = 7;
    work->frame = 0x16;
}

// FUN_0011ba00
void h_campBeginRootItemExit(KwlnTask* task)
{
    CampRootDrawWork* work;

    work = task->workData;
    h_campDrawRootMenuEntriesClosing(work, 100.0f);
    work->state = 8;
    work->frame = 0x16;
}

// FUN_0011ba50
void h_campBeginRootClose(KwlnTask* task)
{
    CampRootDrawWork* work;

    work = task->workData;
    h_campDrawRootMenuEntriesAlternate(work, 100.0f);
    work->state = 5;
    work->frame = 0;
    work->selectedCommand = -1;
}

// FUN_0011baa0
void h_campDestroyRootDrawTask(KwlnTask* task)
{
    RwFree(task->workData);
    sCampRootDrawTask = NULL;
}

// FUN_0011bba0
void h_campNoopRootDrawCallback(void)
{
}

// FUN_0011bad0
KwlnTask* h_campCreateRootDrawTask(KwlnTask* parent, KwlnTask* menuTask, u32 menuMode)
{
    CampRootDrawWork* work;
    KwlnTask* task;

    work = RwCalloc(1, sizeof(CampRootDrawWork), 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "H_CampRootDraw", 0x18BF,
                          h_campUpdateRootDrawTask, h_campDestroyRootDrawTask, work);
    if (task == NULL) {
        return NULL;
    }
    work->menuTask = menuTask;
    work->selectedCommand = -1;
    work->menuMode = menuMode;
    return task;
}
// Reconstructed root UI rendering and data-driven date/currency draws.
// Residual differences are compiler register allocation and switch layout.
// FUN_0011bbb0 NONMATCHING
void h_campDrawRootUi(CampRootDrawWork* work, f32 alpha)
{
    void* parent;

    void* reserve;
    f32 x;
    f32 y;
    u32 color;
    s32 i;
    s32 value;
    s32 glyph;
    s32 month;
    s32 day;
    s32 weekday;
    void* font;
    char text[0x100];



    for (i = 0; i < 7; i++) {
        if (func_0018b700((u8*)iGpffffb25c + i * 0x44) == 0) {
            continue;
        }
        x = *(f32*)((u8*)iGpffffb25c + i * 0x44 + 0x38);
        y = *(f32*)((u8*)iGpffffb25c + i * 0x44 + 0x3c);
        color = *(u32*)((u8*)iGpffffb25c + i * 0x44 + 0x40);
        if (i == 5 && func_0017d800() != 0) {
            func_00115ad0(parent, *(void**)DAT_00833B80_abs, 0x10, 0x80,
                          color & 0xff, x - 27.0f, y + 2.0f, alpha);
            func_00115ad0(parent, *(void**)DAT_00833B80_abs, i, 0x80,
                          color & 0xff, x, y, alpha);
        }
        func_00115ad0(parent, *(void**)DAT_00833B80_abs, 0x10, 0,
                      color & 0xff, x - 27.0f, y + 2.0f, alpha);
        func_00115ad0(parent, *(void**)DAT_00833B80_abs, i, 0,
                      color & 0xff, x, y, alpha);
    }

    if (func_0018b700((u8*)iGpffffb25c + 0x2a8) != 0) {
        x = *(f32*)((u8*)iGpffffb25c + 0x2e0);
        y = *(f32*)((u8*)iGpffffb25c + 0x2e4);
        color = *(u32*)((u8*)iGpffffb25c + 0x2e8);
        func_00115ad0(parent, *(void**)DAT_00833B80_abs, 0x0e, 0,
                      color & 0xff, x, y, alpha);
    }

    if (func_0018b700((u8*)iGpffffb25c + 0x2ec) != 0) {
        x = *(f32*)((u8*)iGpffffb25c + 0x324);
        y = *(f32*)((u8*)iGpffffb25c + 0x328);
        color = *(u32*)((u8*)iGpffffb25c + 0x32c);
        func_00115ad0(parent, *(void**)DAT_00833B80_abs, 0x11, 0,
                      color & 0xff, x - 27.0f, y, alpha);
        func_00115ad0(parent, *(void**)DAT_00833B80_abs, work->selectedEntry + 7, 0,
                      color & 0xff, x, y, alpha);
    }

    if (func_0018b700((u8*)iGpffffb25c + 0x330) != 0) {
        x = *(f32*)((u8*)iGpffffb25c + 0x368);
        y = *(f32*)((u8*)iGpffffb25c + 0x36c);
        color = *(u32*)((u8*)iGpffffb25c + 0x370);
        func_00115ad0(parent, *(void**)DAT_00833B8C_abs, 0, 0,
                      color & 0xff, x, y, alpha);
        func_00115ad0(parent, *(void**)DAT_00833B8C_abs, 1, 0,
                      color & 0xff, x + 117.0f, y, alpha);
        func_00115ad0(parent, *(void**)DAT_00833B8C_abs, 2, 0,
                      color & 0xff, x + 159.0f, y, alpha);

        switch (func_0016ef30() & 0xff) {
        case 0:
        case 7:
            glyph = 0x22;
            break;
        case 1:
            glyph = 0x1c;
            break;
        case 2:
            glyph = 0x1d;
            if (func_0017dcf0() != 0)
                glyph = 0x23;
            break;
        case 3:
            glyph = 0x1f;
            if (func_0017dcf0() != 0)
                glyph = 0x23;
            break;
        case 4:
            glyph = 0x1e;
            if (func_0017dcf0() != 0)
                glyph = 0x23;
            break;
        case 5:
            glyph = 0x20;
            if (func_0017dcf0() != 0)
                glyph = 0x23;
            break;
        case 6:
            glyph = 0x21;
            break;
        case 8:
            glyph = 0x24;
            break;
        }

        y += 320.0f;
        y -= 41.0f;
        func_00115ad0(parent, *(void**)DAT_00833B84_abs, glyph, 0x64,
                      color & 0xff, y, x + 17.0f - 11.0f, alpha);
        x += 30.0f;
        x -= 11.0f;
        x -= 2.0f;

        if (func_0017d920() >= 10) {
            font = H_Maestro_001120a0(1);
            month = func_0017d920();
            value = month / 10 + 0xb;
            func_00115ad0(parent, font, value, 0x78,
                          color & 0xff, y, x, alpha);
            x += 16.0f;
        }
        font = H_Maestro_001120a0(1);
        month = func_0017d920();
        value = month % 10 + 0xb;
        func_00115ad0(parent, font, value, 0x78,
                      color & 0xff, y, x, alpha);
        x += 17.0f;
        func_00115ad0(parent, *(void**)DAT_00833B84_abs, 0x2d, 0x78,
                      color & 0xff, y, x, alpha);
        x += 10.0f;

        if (func_0017da40() >= 10) {
            font = H_Maestro_001120a0(1);
            day = func_0017da40();
            value = day / 10 + 0xb;
            func_00115ad0(parent, font, value, 0x78,
                          color & 0xff, y, x, alpha);
            x += 16.0f;
        }
        font = H_Maestro_001120a0(1);
        day = func_0017da40();
        value = day % 10 + 0xb;
        func_00115ad0(parent, font, value, 0x78,
                      color & 0xff, y, x, alpha);
        x += 15.0f;

        weekday = func_0017db00();
        switch (weekday) {
        case 0:
            glyph = 0x1b;
            break;
        case 1:
            glyph = 0x15;
            break;
        case 2:
            glyph = 0x16;
            break;
        case 3:
            glyph = 0x17;
            break;
        case 4:
            glyph = 0x18;
            break;
        case 5:
            glyph = 0x19;
            break;
        case 6:
            glyph = 0x1a;
            break;
        default:
            goto weekday_done;
        }
        func_00115ad0(parent, *(void**)DAT_00833B84_abs, glyph, 0x78,
                      color & 0xff, y, x, alpha);
weekday_done:
        ;
    }

    if (func_0018b700((u8*)iGpffffb25c + 0x374) != 0) {
        x = *(f32*)((u8*)iGpffffb25c + 0x3ac);
        y = *(f32*)((u8*)iGpffffb25c + 0x3b0);
        color = *(u32*)((u8*)iGpffffb25c + 0x3b4);
        h_campDrawSprite(parent, *(void**)DAT_00833B74_abs, 0,
                         color & 0xff, x, y, alpha);
        h_campDrawSprite(parent, *(void**)DAT_00833B74_abs, work->selectedEntry + 1,
                         color & 0xff, x + 16.0f, y, alpha);
        h_campDrawSprite(parent, *(void**)DAT_00833BA0_abs, 0,
                         color & 0xff, x + 450.0f, y, alpha);
        h_campDrawSprite(parent, *(void**)DAT_00833BA0_abs, 1,
                         color & 0xff, x + 561.0f - 44.0f, y, alpha);
    }

    if (func_0018b700((u8*)iGpffffb25c + 0x3b8) != 0) {
        x = *(f32*)((u8*)iGpffffb25c + 0x3f0);
        y = *(f32*)((u8*)iGpffffb25c + 0x3f4);
        color = *(u32*)((u8*)iGpffffb25c + 0x3f8);
        h_campDrawSprite(parent, *(void**)DAT_00833B90_abs, 2,
                         color & 0xff, x, y, alpha);
        x += 153.0f;
        func_00523ac8(text, gp0xffff8978, datGetMoney());
        func_0040eb50(alpha, (s32)(x - 2.0f), (s32)(y + 3.0f),
                      (0xff - color) & 0xff, 4, text, 9);
    }
}

static void h_campDrawMenuEntryPass(CampRootDrawWork* work, f32 alpha, s32 mode)
{
    s32 i;

    for (i = 0; i < 7; i++) {
        if (work->selectedEntry == i) {
            work->transitionKind = mode;
        }
    }
    h_campDrawRootUi(work, alpha);
}

// FUN_0011c550
void h_campDrawRootMenuEntries(CampRootDrawWork* work, f32 alpha)
{
    struct {
        f32 endX;
        f32 endY;
        f32 startX;
        f32 startY;
    } pos;
    f32 temp;
    f32 offset;
    s32 i;
    s32 selectedEntry;

    pos.endX = 46.0f;
    pos.endY = 59.0f;
    pos.startX = pos.endX - 200.0f;
    for (i = 0; i < 7; i++) {
        pos.startY = pos.endY;
        func_0018bc10(iGpffffb25c + i * 0x44, 0, 2, 1,
                      *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                      alpha, i + 4, i + 0xa);
        pos.endY += 19.0f;
    }
    pos.startX = -19.0f;

    selectedEntry = work->selectedEntry;
    /* Removing this barrier loses h_campDrawRootMenuEntries (MATCH nd0 -> MISMATCH nd463) - measured W164. */
    asm ("" : "+r"(selectedEntry));
    temp = 19.0f;
    temp = temp * (f32)selectedEntry;
    offset = temp;
    temp = 57.0f;
    temp = temp + offset;
    pos.startY = temp;
    pos.endX = 181.0f;
    pos.endY = pos.startY;
    func_0018bc10(iGpffffb25c + 0x2a8, 0, 2, 1,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0xa, 0x10);

    pos.endX = 46.0f;
    pos.endY = 59.0f;
    pos.startX = pos.endX - 200.0f;
    pos.startY = 59.0f;
    func_0018bc10(iGpffffb25c + 0x2ec, 0, 2, 1,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0xa, 0x10);

    pos.endX = 41.0f;
    pos.endY = 11.0f;
    pos.startX = pos.endX - 40.0f;
    pos.startY = 11.0f;
    func_0018bc10(iGpffffb25c + 0x330, 0, 2, 1,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0xb, 0x10);

    pos.endX = 44.0f;
    temp = (f32)0x19f;
    pos.endY = temp;
    pos.startX = pos.endX - 200.0f;
    pos.startY = temp;
    func_0018bc10(iGpffffb25c + 0x374, 0, 2, 1,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0xf, 0x15);

    pos.endX = 44.0f;
    temp = (f32)0x18b;
    pos.endY = temp;
    pos.startX = pos.endX - 200.0f;
    pos.startY = temp;
    func_0018bc10(iGpffffb25c + 0x3b8, 0, 2, 1,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0xf, 0x15);
}

// FUN_0011c880 NONMATCHING
void h_campUpdateRootMenuEntryEffect(CampRootDrawWork* work, f32 alpha)
{
    s32 frame;
    s32 phase;
    s32 fade;
    s32 half;
    s32 offset;
    s32 particleHeight;
    s16 particleAlpha;
    void* textureState;
    void* stage;
    void* particle;
    u32 color;
    u32 colorAlpha;

    frame = work->frame;
    if (frame >= 0x10 && frame < 0x16) {
        phase = frame - 0x10;
        if (phase >= 4) {
            if (uGpffffb260 == NULL) {
                textureState = NULL;
            } else {
                stage = *(void**)((u8*)uGpffffb260 + 0x3c);
                if (*(u32*)stage == 3) {
                    textureState = *(void**)((u8*)stage + 0xc);
                } else {
                    textureState = NULL;
                }
            }
            if (textureState != NULL) {
                fade = 0x100 - (((phase - 3) << 7) / 3);
                fade = 0xff - (s8)fade;
                color = (u32)fade | ~0xffu;
                colorAlpha = (u32)(fade >= 0x19 ? 0x19 : fade) |
                             0x4fa4ff00;
                func_00114450(5.0f + alpha, 0.0f, -87.0f,
                              color, colorAlpha, 0x280, 0x280,
                              (const u32*)textureState);
            }
            h_campNoopRootDrawCallback_5((s32)(s16)fade, 0x1000,
                                         0.0f, 0.0f, 5.0f + alpha);
        }

        fade = 0x32 - ((phase * 0x32) / 6);
        if (uGpffffb260 == NULL) {
            textureState = NULL;
        } else {
            stage = *(void**)((u8*)uGpffffb260 + 0x3c);
            if (*(u32*)stage == 3) {
                textureState = *(void**)((u8*)stage + 0xc);
            } else {
                textureState = NULL;
            }
        }
        if (textureState != NULL) {
            particleHeight = fade * -3;
            half = particleHeight >> 1;
            if (particleHeight < 0) {
                half = (particleHeight + 1) >> 1;
            }
            offset = half;
            func_00114450(4.0f + alpha, 0.0f,
                          -87.0f + (f32)offset,
                          0xffffff7f, 0x4fa4ff19, 0x280, 0x280,
                          (const u32*)textureState);
        }
    }

    frame = work->frame;
    if (frame >= 0xc && frame < 0x16) {
        phase = frame - 0xc;
        if (phase >= 6) {
            particleAlpha = (s16)(0x100 - (((phase - 5) << 7) / 5));
            particle = func_001158b0(0, DAT_00833B78, 0);
            *(f32*)((u8*)particle + 0x2c) = 3.0f + alpha;
            *(u32*)((u8*)particle + 0x10) = 0x43d60000;
            *(u32*)((u8*)particle + 0x14) = 0x41d80000;
            *(u8*)((u8*)particle + 0x18) = (u8)particleAlpha;
            *(u16*)((u8*)particle + 0x28) = 0x1000;
            *(u16*)((u8*)particle + 0x2a) = 0x1000;
            func_001127d0(particle, 1);
            func_00115980(particle);
        }

        particleHeight = 0x64 - ((phase * 0x64) / 10);
        particleAlpha = (s16)(0x1800 - ((phase << 0xb) / 10));
        particle = func_001158b0(0, DAT_00833B78, 0);
        *(f32*)((u8*)particle + 0x2c) = 2.0f + alpha;
        *(f32*)((u8*)particle + 0x10) = 428.0f + (f32)particleHeight;
        fade = particleHeight * -3;
        half = fade >> 1;
        if (fade < 0) {
            half = (fade + 1) >> 1;
        }
        *(f32*)((u8*)particle + 0x14) = 27.0f + (f32)half;
        *(u8*)((u8*)particle + 0x18) = 0x80;
        *(u16*)((u8*)particle + 0x28) = (u16)particleAlpha;
        *(u16*)((u8*)particle + 0x2a) = (u16)particleAlpha;
        func_001127d0(particle, 1);
        func_00115980(particle);
    }
    h_campDrawRootUi(work, alpha);
}

// FUN_0011cc80
void h_campDrawRootMenuEntriesAlternate(CampRootDrawWork* work, f32 alpha)
{
    struct {
        f32 endX;
        f32 endY;
        f32 startX;
        f32 startY;
    } pos;
    f32 temp;
    f32 offset;
    s32 i;
    s32 selectedEntry;

    pos.endX = 46.0f;
    pos.endY = 59.0f;
    pos.startX = pos.endX - 200.0f;
    for (i = 0; i < 7; i++) {
        pos.startY = pos.endY;
        func_0018bc10(iGpffffb25c + i * 0x44, 0, 0, 1,
                      *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                      alpha, 0, 0xa);
        pos.endY += 19.0f;
    }

    pos.startX = -19.0f;
    selectedEntry = work->selectedEntry;
    /* Removing this barrier from the selected-entry split leaves normalized_diff 452; measured with it, normalized_diff is 0. */
    asm ("" : "+r"(selectedEntry));
    temp = 19.0f;
    temp = temp * (f32)selectedEntry;
    offset = temp;
    temp = 57.0f;
    temp = temp + offset;
    pos.startY = temp;
    pos.endX = 181.0f;
    pos.endY = pos.startY;
    func_0018bc10(iGpffffb25c + 0x2a8, 0, 0, 1,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0, 0xa);

    pos.endX = 46.0f;
    temp = 59.0f + 19.0f * (f32)work->selectedEntry;
    pos.endY = temp;
    pos.startX = pos.endX - 200.0f;
    pos.startY = temp;
    func_0018bc10(iGpffffb25c + 0x2ec, 0, 0, 1,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0, 0xa);

    pos.endX = 41.0f;
    pos.endY = 11.0f;
    pos.startX = pos.endX - 40.0f;
    pos.startY = 11.0f;
    func_0018bc10(iGpffffb25c + 0x330, 0, 0, 1,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0, 0xa);

    pos.endX = 44.0f;
    temp = (f32)0x19f;
    pos.endY = temp;
    pos.startX = pos.endX - 200.0f;
    pos.startY = temp;
    func_0018bc10(iGpffffb25c + 0x374, 0, 0, 1,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0, 0xa);

    pos.endX = 44.0f;
    temp = (f32)0x18b;
    pos.endY = temp;
    pos.startX = 44.0f;
    pos.startY = temp;
    func_0018bc10(iGpffffb25c + 0x3b8, 0, 2, 1,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0, 0xa);
}

// FUN_0011cfb0 NONMATCHING
void h_campUpdateRootMenuEntryTransition(CampRootDrawWork* work, f32 alpha)
{
    s32 temp_16;
    void* parent;
    struct {
        f32 x;
        f32 y;
    } position;
    s64 packedPosition;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f22;
    s32 temp_3;
    s32 var_3;
    s32 var_8;
    u32 temp_3_2;
    u32 var_5;
    void* temp_2;
    void* temp_2_2;
    void* temp_4;

    temp_3 = work->frame;
    if (temp_3 >= 0xa) {
        var_3 = 0xff;
    } else {
        var_3 = (temp_3 * 0xff) / 10;
    }
    temp_16 = 0xff - var_3;
    temp_2 = uGpffffb260;
    if (temp_2 == NULL) {
        var_8 = 0;
    } else {
        temp_4 = *(void**)((u8*)temp_2 + 0x3c);
        if (*(u32*)temp_4 == 3) {
            var_8 = *(s32*)((u8*)temp_4 + 0xc);
        } else {
            var_8 = 0;
        }
    }
    if (var_8 != 0) {
        temp_3_2 = 0xff -
                   (s16)temp_16;
        var_5 = temp_3_2;
        if (temp_3_2 >= 0x19u) {
            var_5 = 0x19;
        }
        func_00114450(4.0f + alpha, 0.0f, -87.0f,
                      temp_3_2 | ~0xffu, var_5 | 0x4fa4ff00,
                      0x280, 0x280, (const u32*)var_8);
    }
    h_campNoopRootDrawCallback_5((s32)(s16)temp_16, 0, 0.0f, 0.0f,
                                 4.0f + alpha);

    temp_2_2 = func_001158b0(0, DAT_00833B78, 0);
    *(f32*)((u8*)temp_2_2 + 0x2c) = 2.0f + alpha;
    *(u32*)((u8*)temp_2_2 + 0x10) = 0x43d60000;
    *(u32*)((u8*)temp_2_2 + 0x14) = 0x41d80000;
    *(u8*)((u8*)temp_2_2 + 0x18) =
        (u8)(s16)temp_16;
    *(u16*)((u8*)temp_2_2 + 0x28) = 0;
    *(u16*)((u8*)temp_2_2 + 0x2a) = 0;
    func_001127d0(temp_2_2, 1);
    func_00115980(temp_2_2);

    position.x = (200.0f * (f32)(0x16 - work->frame)) / 22.0f;
    temp_f1 = (f32)(s32)work->transitionDuration;
    position.y = temp_f1;
    work->transitionDuration = (s32)(temp_f1 + 1.0f);
    temp_f1_2 = (f32)(s32)work->transitionDuration;
    if (!(temp_f1_2 <= (f32)0x2ff)) {
        work->transitionDuration = (s32)(temp_f1_2 - 448.0f);
    }
    packedPosition = *(s64*)&position;
    temp_f21 = 589.0f + *(f32*)&packedPosition;
    h_campDrawSprite(parent, DAT_00833B8C, 3,
                     (u32)temp_16 & 0xff, temp_f21,
                     *(f32*)((u8*)&packedPosition + 4) - 190.0f, 100.0f);
    h_campDrawSprite(parent, DAT_00833B8C, 4,
                     (u32)temp_16 & 0xff, temp_f21,
                     (*(f32*)((u8*)&packedPosition + 4) - 129.0f) - 190.0f,
                     100.0f);
    if (!(*(f32*)((u8*)&packedPosition + 4) <= 448.0f)) {
        temp_f22 = *(f32*)((u8*)&packedPosition + 4) - 448.0f;
        temp_f21_2 = 589.0f + *(f32*)&packedPosition;
        h_campDrawSprite(parent, DAT_00833B8C, 3,
                         (u32)temp_16 & 0xff, temp_f21_2,
                         temp_f22 - 190.0f, 100.0f);
        h_campDrawSprite(parent, DAT_00833B8C, 4,
                         (u32)temp_16 & 0xff, temp_f21_2,
                         (temp_f22 - 129.0f) - 190.0f, 100.0f);
    }
    h_campDrawRootUi(work, alpha);
}

// FUN_0011d3a0
void h_campDrawRootMenuEntriesClosing(CampRootDrawWork* work, f32 alpha)
{
    struct {
        f32 endX;
        f32 endY;
        f32 startX;
        f32 startY;
    } pos;
    f32 temp;
    f32 offset;
    s32 i;
    s32 selectedEntry;
    pos.endX = 46.0f;
    pos.endY = 59.0f;
    pos.startX = pos.endX - 200.0f;
    for (i = 0; i < 7; i++) {
        pos.startY = pos.endY;
        func_0018bc10(iGpffffb25c + i * 0x44, 0, 0, 2,
                      *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                      alpha, 0, 0xa);
        pos.endY += 19.0f;
    }

    pos.startX = -19.0f;
    selectedEntry = work->selectedEntry;
    /* Removing this barrier loses h_campDrawRootMenuEntriesClosing (MATCH nd0 -> MISMATCH nd455) - measured W164. */
    asm ("" : "+r"(selectedEntry));
    temp = 19.0f;
    temp = temp * (f32)selectedEntry;
    offset = temp;
    temp = 57.0f;
    temp = temp + offset;
    pos.startY = temp;
    pos.endX = 181.0f;
    pos.endY = pos.startY;
    func_0018bc10(iGpffffb25c + 0x2a8, 0, 0, 2,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0, 0xa);

    pos.endX = 46.0f;
    temp = 59.0f + 19.0f * (f32)work->selectedEntry;
    pos.endY = temp;
    pos.startX = pos.endX - 200.0f;
    pos.startY = temp;
    func_0018bc10(iGpffffb25c + 0x2ec, 0, 0, 2,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0, 0xa);

    pos.endX = 41.0f;
    pos.endY = 11.0f;
    pos.startX = pos.endX - 40.0f;
    pos.startY = 11.0f;
    func_0018bc10(iGpffffb25c + 0x330, 0, 0, 2,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0, 0xa);

    pos.endX = 44.0f;
    temp = (f32)0x19f;
    pos.endY = temp;
    pos.startX = pos.endX - 200.0f;
    pos.startY = temp;
    func_0018bc10(iGpffffb25c + 0x374, 0, 0, 2,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0, 0xa);

    pos.endX = 44.0f;
    temp = (f32)0x18b;
    pos.endY = temp;
    pos.startX = 44.0f;
    pos.startY = temp;
    func_0018bc10(iGpffffb25c + 0x3b8, 0, 2, 2,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0, 0xa);
}

// FUN_0011d6d0 NONMATCHING
void h_campUpdateRootMenuEntryFadeOut(CampRootDrawWork* work, f32 alpha)
{
    void* parent;
    s32 frame;
    s32 fade;
    s32 remaining;
    s32 overlayAlpha;
    f32 slide;
    f32 oldDuration;
    f32 newDuration;
    f32 x;
    f32 y;
    void* textureState;
    void* stage;
    void* particle;
    u32 color;
    u32 colorAlpha;

    frame = work->frame;
    fade = (frame * 0xff) / 22;
    remaining = 0xff - fade;
    if (uGpffffb260 == NULL) {
        textureState = NULL;
    } else {
        stage = *(void**)((u8*)uGpffffb260 + 0x3c);
        if (*(u32*)stage == 3) {
            textureState = *(void**)((u8*)stage + 0xc);
        } else {
            textureState = NULL;
        }
    }
    if (textureState != NULL) {
        overlayAlpha = 0xff - (s8)remaining;
        color = (u32)remaining | ~0xffu;
        colorAlpha = (u32)(overlayAlpha >= 0x19 ? 0x19 : overlayAlpha) |
                     0x4fa4ff00;
        func_00114450(2.0f + alpha, 0.0f, -87.0f,
                      color, colorAlpha, 0x280, 0x280,
                      (const u32*)textureState);
    }

    particle = func_001158b0(0, DAT_00833B78, 0);
    *(f32*)((u8*)particle + 0x2c) = 1.0f + alpha;
    *(u32*)((u8*)particle + 0x10) = 0x43d60000;
    *(u32*)((u8*)particle + 0x14) = 0x41d80000;
    *(u8*)((u8*)particle + 0x18) = (u8)remaining;
    *(u16*)((u8*)particle + 0x28) = 0;
    *(u16*)((u8*)particle + 0x2a) = 0;
    func_001127d0(particle, 1);
    func_00115980(particle);

    slide = (200.0f * (f32)(0x16 - work->frame)) / 22.0f;
    oldDuration = (f32)(s32)work->transitionDuration;
    work->transitionDuration = (s32)(oldDuration + 1.0f);
    newDuration = (f32)(s32)work->transitionDuration;
    if (!(newDuration <= 767.0f)) {
        work->transitionDuration = (s32)(newDuration - 448.0f);
    }

    x = 589.0f + slide;
    y = oldDuration - 190.0f;
    h_campDrawSprite(parent, DAT_00833B8C, 3, (u32)remaining,
                     x, y, 100.0f);
    y = (oldDuration - 129.0f) - 190.0f;
    h_campDrawSprite(parent, DAT_00833B8C, 4, (u32)remaining,
                     x, y, 100.0f);
    if (!(oldDuration <= 448.0f)) {
        y = oldDuration - 448.0f;
        h_campDrawSprite(parent, DAT_00833B8C, 3, (u32)remaining,
                         x, y - 190.0f, 100.0f);
        h_campDrawSprite(parent, DAT_00833B8C, 4, (u32)remaining,
                         x, (y - 129.0f) - 190.0f, 100.0f);
    }
    h_campDrawRootUi(work, alpha);
}

// FUN_0011da80
void h_campDrawRootMenuEntriesFadeOut(CampRootDrawWork* work, f32 alpha)
{
    struct {
        f32 endX;
        f32 endY;
        f32 startX;
        f32 startY;
    } pos;
    f32 temp;
    f32 offset;
    s32 i;
    s32 selectedEntry;

    pos.endX = 46.0f;
    pos.endY = 59.0f;
    pos.startX = pos.endX - 200.0f;
    for (i = 0; i < 7; i++) {
        pos.startY = pos.endY;
        func_0018bc10(iGpffffb25c + i * 0x44, 0, 0, 2,
                      *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                      alpha, 0, 0xa);
        pos.endY += 19.0f;
    }

    pos.startX = -19.0f;
    selectedEntry = work->selectedEntry;
    /* Removing this barrier loses h_campDrawRootMenuEntriesFadeOut (MATCH nd0 -> MISMATCH nd455) - measured W164. */
    asm ("" : "+r"(selectedEntry));
    temp = 19.0f;
    temp = temp * (f32)selectedEntry;
    offset = temp;
    temp = 57.0f;
    temp = temp + offset;
    pos.startY = temp;
    pos.endX = 181.0f;
    pos.endY = pos.startY;
    func_0018bc10(iGpffffb25c + 0x2a8, 0, 0, 2,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0, 0xa);

    pos.endX = 46.0f;
    temp = 59.0f + 19.0f * (f32)work->selectedEntry;
    pos.endY = temp;
    pos.startX = pos.endX - 200.0f;
    pos.startY = temp;
    func_0018bc10(iGpffffb25c + 0x2ec, 0, 0, 2,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0, 0xa);

    pos.endX = 41.0f;
    pos.endY = 11.0f;
    pos.startX = pos.endX - 40.0f;
    pos.startY = 11.0f;
    func_0018bc10(iGpffffb25c + 0x330, 0, 0, 2,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0, 0xa);

    pos.endX = 44.0f;
    temp = (f32)0x19f;
    pos.endY = temp;
    pos.startX = pos.endX - 200.0f;
    pos.startY = temp;
    func_0018bc10(iGpffffb25c + 0x374, 0, 0, 2,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0, 0xa);

    pos.endX = 44.0f;
    temp = (f32)0x18b;
    pos.endY = temp;
    pos.startX = 44.0f;
    pos.startY = temp;
    func_0018bc10(iGpffffb25c + 0x3b8, 0, 2, 2,
                  *(u64*)&pos.startX, *(u64*)&pos.endX, 0, 0,
                  alpha, 0, 0xa);
}

// FUN_0011ddb0 NONMATCHING
void h_campUpdateRootMenuEntryFinish(CampRootDrawWork* work, f32 alpha)
{
    void* parent;
    CampVec2 source;
    CampVec2 position;
    f32 oldDuration;
    f32 newDuration;

    source.x = 0.0f;
    oldDuration = (f32)(s32)work->transitionDuration;
    source.y = oldDuration;
    work->transitionDuration = (s32)(1.0f + oldDuration);
    newDuration = (f32)(s32)work->transitionDuration;
    if (!(newDuration <= 767.0f)) {
        work->transitionDuration = (s32)(newDuration - 448.0f);
    }

    position = source;
    h_campDrawSprite(parent, *(void**)DAT_00833B8C_abs, 3, 0,
                     589.0f + position.x, position.y - 190.0f, 100.0f);
    h_campDrawSprite(parent, *(void**)DAT_00833B8C_abs, 4, 0,
                     589.0f + position.x,
                     (position.y - 129.0f) - 190.0f, 100.0f);
    if (!(position.y <= 448.0f)) {
        position.y -= 448.0f;
        h_campDrawSprite(parent, *(void**)DAT_00833B8C_abs, 3, 0,
                         589.0f + position.x, position.y - 190.0f, 100.0f);
        h_campDrawSprite(parent, *(void**)DAT_00833B8C_abs, 4, 0,
                         589.0f + position.x,
                         (position.y - 129.0f) - 190.0f, 100.0f);
    }
    h_campDrawRootUi(work, alpha);
}

// FUN_0011dfe0 NONMATCHING
void h_campUpdateRootMenuSelectionEffect(CampRootDrawWork* work, f32 alpha)
{
    void* parent;
    void* textureState;
    void* stage;
    void* node;
    s32 cacheIndex;
    f32* cacheSlot;
    f32 oldDuration;
    f32 newDuration;
    CampVec2 source;
    CampVec2 position;

    if (iGpffffb270 == NULL) {
        textureState = NULL;
    } else {
        stage = iGpffffb270->workData;
        if (*(u32*)stage == 3) {
            textureState = *(void**)((u8*)stage + 0xc);
        } else {
            textureState = NULL;
        }
    }
    if (textureState != NULL) {
        func_00114450_7arg(2.0f + alpha, 0.0f, -87.0f, -1, 0x4fa4ff19, 0x280, 0x280);
    }
    h_campNoopRootDrawCallback_5(0, 0x1000, 0.0f, 0.0f, 2.0f + alpha);

    node = func_001158b0(0, DAT_00833B78, 0);
    *(f32*)((u8*)node + 0x2c) = 1.0f + alpha;
    *(u32*)((u8*)node + 0x10) = 0x43d60000;
    *(u32*)((u8*)node + 0x14) = 0x41d80000;
    *(u8*)((u8*)node + 0x18) = 0;
    *(u16*)((u8*)node + 0x28) = 0x1000;
    *(u16*)((u8*)node + 0x2a) = 0x1000;
    func_001127d0(node, 1);
    func_00115980(node);

    cacheIndex = work->selectedEntry * 19 + 0x39;
    cacheSlot = (f32*)(iGpffffb25c + 0x2dc);
    if (*cacheSlot != (f32)cacheIndex) {
        *cacheSlot = (f32)cacheIndex;
    } else {
        work->drawChild = (KwlnTask*)1;
    }

    source.x = 0.0f;
    oldDuration = (f32)(s32)work->transitionDuration;
    source.y = oldDuration;
    work->transitionDuration = (s32)(oldDuration + 1.0f);
    newDuration = (f32)(s32)work->transitionDuration;
    if (!(newDuration <= 767.0f)) {
        work->transitionDuration = (s32)(newDuration - 448.0f);
    }

    position = source;
    h_campDrawSprite(parent, *(void**)DAT_00833B8C_abs, 3, 0,
                     589.0f + position.x, position.y - 190.0f, 100.0f);
    h_campDrawSprite(parent, *(void**)DAT_00833B8C_abs, 4, 0,
                     589.0f + position.x,
                     (position.y - 129.0f) - 190.0f, 100.0f);
    if (!(position.y <= 448.0f)) {
        position.y -= 448.0f;
        h_campDrawSprite(parent, *(void**)DAT_00833B8C_abs, 3, 0,
                         589.0f + position.x, position.y - 190.0f, 100.0f);
        h_campDrawSprite(parent, *(void**)DAT_00833B8C_abs, 4, 0,
                         589.0f + position.x,
                         (position.y - 129.0f) - 190.0f, 100.0f);
    }

    h_campDrawRootUi(work, alpha);
}

// FUN_0011e370
u32 h_campGetRootMenuTransitionComplete(KwlnTask* task)
{
    CampMenuWork* work;

    work = task->workData;
    return work->transitionComplete;
}

// FUN_0011e380
u32 h_campRequestRootMenuTransition(KwlnTask* task, u32 command)
{
    CampMenuWork* work;
    work = task->workData;
    if (work->state != 0) {
        return 0;
    }
    work->transitionComplete = 0;
    switch (command) {
    case 0:
        work->state = 13;
        break;
    case 1:
    {
        u32 secondary = work->command;
        switch (secondary) {
        case 0:
            work->state = 1;
            break;
        case 1:
            work->transitionComplete = 1;
            break;
        case 2:
            work->state = 11;
            break;
        case 3:
            work->state = 11;
            break;
        case 4:
        case 6:
        case 7:
        case 8:
        case 9:
        case 11:
        case 12:
        case 15:
        case 16:
            work->state = 11;
            break;
        case 13:
            work->state = 11;
            break;
        case 5:
        case 10:
        case 14:
            break;
        }
        break;
    }
    case 2:
    {
        u32 secondary = work->command;
        switch (secondary) {
        case 0:
            work->state = 3;
            break;
        case 1:
            work->state = 3;
            break;
        case 2:
            work->transitionComplete = 1;
            break;
        case 3:
            work->state = 9;
            break;
        case 9:
            work->transitionComplete = 1;
            break;
        case 13:
            work->transitionComplete = 1;
            break;
        }
        break;
    }
    case 3:
    {
        u32 secondary = work->command;
        switch (secondary) {
        case 0:
            work->state = 7;
            break;
        case 1:
            work->state = 7;
            break;
        case 2:
            work->state = 7;
            break;
        case 3:
            work->state = 7;
            break;
        case 9:
            work->transitionComplete = 1;
            break;
        case 13:
            work->transitionComplete = 1;
            break;
        }
        break;
    }
    case 9:
    {
        u32 secondary = work->command;
        switch (secondary) {
        case 0:
            work->transitionComplete = 1;
            break;
        case 1:
            work->state = 15;
            break;
        case 2:
            work->transitionComplete = 1;
            break;
        case 3:
            work->transitionComplete = 1;
            break;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            break;
        case 9:
            work->transitionComplete = 1;
            break;
        case 10:
            work->state = 19;
            break;
        case 13:
            work->transitionComplete = 1;
            break;
        case 14:
            work->state = 19;
            break;
        case 11:
            work->state = 23;
            break;
        case 12:
            work->state = 29;
            break;
        }
        break;
    }
    case 10:
    {
        u32 secondary = work->command;
        switch (secondary) {
        case 9:
            work->state = 17;
            break;
        case 13:
            work->state = 17;
            break;
        }
        break;
    }
    case 11:
    {
        u32 secondary = work->command;
        switch (secondary) {
        case 1:
            work->state = 15;
            break;
        case 9:
            work->state = 21;
            break;
        case 12:
            work->state = 31;
            break;
        }
        break;
    }
    case 12:
    {
        u32 secondary = work->command;
        switch (secondary) {
        case 1:
            work->state = 15;
            break;
        case 9:
            work->state = 25;
            break;
        case 11:
            work->state = 27;
            break;
        }
        break;
    }
    case 13:
    {
        u32 secondary = work->command;
        switch (secondary) {
        case 0:
            work->transitionComplete = 1;
            break;
        case 1:
            work->state = 39;
            break;
        case 2:
            work->transitionComplete = 1;
            break;
        case 3:
            work->transitionComplete = 1;
            break;
        case 9:
            work->transitionComplete = 1;
            break;
        case 10:
            work->transitionComplete = 1;
            break;
        case 13:
            work->transitionComplete = 1;
            break;
        case 14:
            work->state = 43;
            break;
        }
        break;
    }
    case 14:
    {
        u32 secondary = work->command;
        switch (secondary) {
        case 13:
            work->state = 41;
            break;
        }
        break;
    }
    case 7:
    {
        u32 secondary = work->command;
        switch (secondary) {
        case 1:
            work->state = 33;
            break;
        case 7:
            break;
        case 8:
            work->state = 37;
            break;
        }
        break;
    }
    case 8:
    {
        u32 secondary = work->command;
        switch (secondary) {
        case 7:
            work->state = 35;
            break;
        case 8:
            break;
        }
        break;
    }
    case 15:
    {
        u32 secondary = work->command;
        switch (secondary) {
        case 1:
            work->state = 45;
            break;
        case 16:
            work->state = 49;
            break;
        }
        break;
    }
    case 16:
    {
        u32 secondary = work->command;
        switch (secondary) {
        case 15:
            work->state = 47;
            break;
        }
        break;
    }
    case 4:
    {
        u32 secondary = work->command;
        switch (secondary) {
        case 1:
            work->state = 45;
            break;
        case 5:
            work->state = 55;
            break;
        }
        break;
    }
    case 5:
    {
        u32 secondary = work->command;
        switch (secondary) {
        case 4:
            work->state = 53;
            break;
        }
        break;
    }
    case 6:
    {
        u32 secondary = work->command;
        switch (secondary) {
        case 1:
            work->state = 57;
            break;
        }
        break;
    }
    }
    work->command = command;
    return 1;
}

// FUN_0011ea20
void* h_campUpdateMenuTask(KwlnTask* task)
{
    CampMenuWork* work;

    work = task->workData;
    switch (work->state)
    {
    case 0:
        break;
    case 1:
        work->state = 2;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 2:
        h_campUpdateMainMenuAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 3:
        work->state = 4;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 4:
        h_campUpdateStatusMainAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 5:
        work->state = 6;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 6:
        return KWLNTASK_STOP;
    case 7:
        work->state = 8;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 8:
        h_campUpdateStatusDetailAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 9:
        work->state = 10;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 10:
        h_campUpdateStatusPersonaAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 11:
        work->state = 12;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 12:
        h_campUpdateStatusExitTransition(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 13:
        work->state = 14;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 14:
        h_campUpdateStatusFadeTransition(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 15:
        work->state = 16;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 16:
        h_campUpdateItemMainAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 17:
        work->state = 18;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 18:
        h_campUpdateItemDetailAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 19:
        work->state = 20;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 20:
        h_campUpdateItemAnimationBlend(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 21:
        work->state = 22;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 22:
        h_campUpdateItemThirdAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 23:
        work->state = 24;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 24:
        h_campUpdateItemEighthAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 25:
        work->state = 26;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 26:
        h_campUpdateItemSixthAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 29:
        work->state = 30;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 30:
        h_campUpdateItemFifthAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 27:
        work->state = 28;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 28:
        h_campUpdateItemFourthAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 31:
        work->state = 32;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 32:
        h_campUpdateItemSeventhAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 33:
        work->state = 34;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 34:
        h_campUpdateSocialMainAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 35:
        work->state = 36;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 36:
        h_campUpdateSocialDetailAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 37:
        work->state = 38;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 38:
        h_campUpdateSocialTransition(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 39:
        work->state = 40;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 40:
        h_campUpdateSkillMainAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 41:
        work->state = 42;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 42:
        h_campUpdateSkillDetailAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 43:
        work->state = 44;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 44:
        h_campUpdateSkillEquipBlend(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 45:
        work->state = 46;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 46:
        h_campUpdateEquipMainAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 47:
        work->state = 48;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 48:
        h_campUpdateEquipDetailAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 49:
        work->state = 50;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 50:
        h_campUpdateSkillEquipExitBlend(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 51:
        work->state = 52;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 52:
        h_campUpdatePersonaMainAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 53:
        work->state = 54;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 54:
        h_campUpdatePersonaDetailAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 55:
        work->state = 56;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 56:
        h_campUpdatePersonaBlend(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    case 57:
        work->state = 58;
        work->transitionComplete = 0;
        work->animationState = 0;
        goto done;
    case 58:
        h_campUpdateSystemMainAnimation(task);
        if (work->animationState != 999) {
            goto done;
        }
        work->state = 0;
        goto done;
    }
done:
    return KWLNTASK_CONTINUE;
}
// FUN_0011f120
void h_campDestroyMenuTask(KwlnTask* task)
{
    s32 i;
    CampMenuWork* work;
    CampMenuWork* menu;

    work = task->workData;
    for (i = 0; i < 2; i++) {
        if ((menu = work)->cdvdTasks[i] != NULL) {
            H_Cdvd_Destroy(menu->cdvdTasks[i]);
            menu->cdvdTasks[i] = NULL;
        }
    }
    RwFree(work);
}

// FUN_0011f1b0
KwlnTask* h_campCreateMenuTask(KwlnTask* parent)
{
    CampMenuWork* work;
    KwlnTask* task;

    work = RwCalloc(1, sizeof(CampMenuWork), 0x40000);
    if (work == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "h_camp_flash_control", 0x18BF,
                          h_campUpdateMenuTask, h_campDestroyMenuTask, work);
    if (task == NULL) {
        return NULL;
    }
    work->command = 0;
    return task;
}

// FUN_0011f260
void h_campUpdateMainMenuAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 count;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        child = work->childTasks[0];
        if (child == NULL) {
            work->activeAnimation = H_Maestro_CreateTask(
                task, 0x18BD, "camp/main_all/if_c_mai01.anm");
            work->animationState = 1;
            return;
        }
        H_Maestro_SetAlphaMult(child, 1.0f);
        work->transitionComplete = 1;
        work->animationState = 999;
        return;
    case 1:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->transitionComplete = 1;
        work->timer = 0x18;
        work->animationState = 2;
        func_0010a4e0(0, 0, 0, 3);
        return;
    case 2:
        count = work->timer - 1;
        work->timer = count;
        if (count == 0) {
            for (i = 0; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[0] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
        }
        break;
    case 999:
    done:
        return;
    }
}


// FUN_0011f400
void h_campUpdateStatusMainAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 count;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->animationState = 1;
        return;
    case 1:
        work->animationState = 2;
        return;
    case 2:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/status/anm/if_c_sta01.anm");
        work->animationState = 3;
        return;
    case 3:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->transitionComplete = 1;
        work->timer = 0x18;
        work->animationState = 4;
        func_0010a4e0(0, 0, 0, 3);
        return;
    case 4:
        count = work->timer - 1;
        work->timer = count;
        if (count == 0) {
            child = work->childTasks[0];
            if (child != NULL) {
                H_Maestro_SetAlphaMult(child, 0.0f);
            }
            for (i = 1; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[1] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->retainedAnimation = NULL;
            work->animationState = 999;
        }
        break;
    case 999:
    done:
        return;
    }
}


// FUN_0011f5c0
void h_campUpdateStatusDetailAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 count;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/status/anm/if_c_sta07.anm");
        work->animationState = 1;
        return;
    case 1:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        H_Maestro_SetAlphaMult(work->activeAnimation, 1.0f);
        work->transitionComplete = 1;
        work->timer = 0x18;
        work->animationState = 2;
        func_0010a4e0(0, 0, 0, 5);
        return;
    case 2:
        count = work->timer - 1;
        work->timer = count;
        if (count == 0) {
            child = work->childTasks[0];
            if (child != NULL) {
                H_Maestro_SetAlphaMult(child, 0.0f);
            }
            for (i = 1; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[1] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
        }
        break;
    case 999:
    done:
        return;
    }
}


// FUN_0011f760
void h_campUpdateStatusPersonaAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 count;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/status/anm/if_c_sta09.anm");
        work->animationState = 1;
        return;
    case 1:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        H_Maestro_SetAlphaMult(work->activeAnimation, 1.0f);
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->transitionComplete = 1;
        work->timer = 0x18;
        work->animationState = 2;
        func_0010a4e0(0, 0, 0, 5);
        return;
    case 2:
        count = work->timer - 1;
        work->timer = count;
        if (count == 0) {
            child = work->childTasks[0];
            if (child != NULL) {
                H_Maestro_SetAlphaMult(child, 0.0f);
            }
            for (i = 1; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[1] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
        }
        break;
    case 999:
    done:
        return;
    }
}

// FUN_0011f900
void h_campUpdateStatusExitTransition(KwlnTask* task)
{
    CampMenuWork* work;
    s32 count;
    s32 i;
    s32 fadeIndex;
    s32 found;
    f32 progress;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->animationState = 1;
        return;
    case 1:
        work->transitionComplete = 1;
        work->timer = 10;
        work->animationState = 2;
        func_001958a0(uGpffffb260, work->childTasks[0]);
        func_0010a4e0(0, 0, 0, 4);
        return;
    case 2:
        found = 0;
        count = work->timer;
        count--;
        work->timer = count;
        if (count == 0) {
            for (i = 1; i < 10; i++) {
                if (*(KwlnTask**)((u8*)work + 0x14 + i * 4) != NULL) {
                    if (found == 0) {
                        func_001957b0(
                            *(KwlnTask**)((u8*)work + 0x14 + i * 4),
                            work->childTasks[0]);
                    }
                    found = 1;
                    kwlnTaskDestroyWithHierarchy(
                        *(KwlnTask**)((u8*)work + 0x14 + i * 4));
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->activeAnimation = NULL;
            work->retainedAnimation = NULL;
            H_Maestro_SetAlphaMult(work->childTasks[0], 1.0f);
            work->animationState = 999;
            return;
        }
        progress = (10.0f - (f32)count) / 10.0f;
        for (fadeIndex = 1; fadeIndex < 10; fadeIndex++) {
            if (*(KwlnTask**)((u8*)work + 0x14 + fadeIndex * 4) != NULL) {
                H_Maestro_SetAlphaMult(
                    *(KwlnTask**)((u8*)work + 0x14 + fadeIndex * 4), 1.0f);
            }
        }
        H_Maestro_SetAlphaMult(work->childTasks[0], progress);
    case 999:
    done:
        return;
    }
}

// FUN_0011faf0
void h_campUpdateStatusFadeTransition(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    f32 fadeAlpha;
    f32 progress;
    s32 count;
    s32 i;
    s32 fadeIndex;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->animationState = 1;
        return;
    case 1:
        work->transitionComplete = 1;
        work->timer = 0;
        work->animationState = 2;
        func_0010a4e0(0, 0, 0, 4);
        return;
    case 2:
        count = work->timer + 1;
        work->timer = count;
        if (count == 20) {
            for (i = 1; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->activeAnimation = NULL;
            work->retainedAnimation = NULL;
            H_Maestro_SetAlphaMult(work->childTasks[0], 0.0f);
            work->animationState = 999;
            return;
        }
        progress = (f32)count;
        progress = (20.0f - progress) / 20.0f;
        fadeIndex = 1;
        fadeAlpha = 1.0f - progress;
        for (; fadeIndex < 10; fadeIndex++) {
            child = *(KwlnTask**)((u8*)work + 0x14 + fadeIndex * 4);
            if (child != NULL) {
                H_Maestro_SetAlphaMult(child, fadeAlpha);
            }
        }
        H_Maestro_SetAlphaMult(work->childTasks[0], progress);
    case 999:
    done:
        return;
    }
}


// FUN_0011fca0
void h_campUpdateItemMainAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->animationState = 1;
        return;
    case 1:
        work->animationState = 2;
        return;
    case 2:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/item/anm/i_c_ite01.anm");
        work->animationState = 3;
        return;
    case 3:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->transitionComplete = 1;
        work->timer = 0x18;
        work->animationState = 4;
        func_0010a4e0(0, 0, 0, 3);
        return;
    case 4:
        if (H_Maestro_00111cb0(work->activeAnimation) != 0) {
            child = work->childTasks[0];
            if (child != NULL) {
                H_Maestro_SetAlphaMult(child, 0.0f);
            }
            for (i = 1; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[1] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
        }
        break;
    case 999:
    done:
        return;
    }
}

// FUN_0011fe50
void h_campUpdateItemDetailAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/item/anm/i_c_ite02.anm");
        work->animationState = 1;
        return;
    case 1:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->animationState = 2;
        func_0010a4e0(0, 0, 0, 5);
        return;
    case 2:
        if (H_Maestro_00111cb0(work->activeAnimation) != 0) {
            child = work->childTasks[1];
            if (child != NULL) {
                H_Maestro_SetAlphaMult(child, 0.0f);
            }
            for (i = 2; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[2] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
            work->transitionComplete = 1;
        }
        break;
    case 999:
    done:
        return;
    }
}

// FUN_0011ffd0
void h_campUpdateItemAnimationBlend(KwlnTask* task)
{
    CampMenuWork* work;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], fGpffff839c);
        work->animationState = 1;
        return;
    case 1:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], fGpffff80c4);
        work->animationState = 2;
        return;
    case 2:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], fGpffff8088);
        work->animationState = 3;
    case 3:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], fGpffff82fc);
        work->animationState = 4;
    case 4:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], 0.0f);
        kwlnTaskDestroyWithHierarchy(work->childTasks[2]);
        work->childTasks[2] = NULL;
        work->transitionComplete = 1;
        work->animationState = 999;
        return;
    case 999:
    done:
        return;
    }
}

// FUN_00120150
void h_campUpdateItemThirdAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/item/anm/i_c_ite03.anm");
        work->animationState = 1;
        return;
    case 1:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        work->transitionComplete = 1;
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->animationState = 2;
        func_0010a4e0(0, 0, 0, 5);
        return;
    case 2:
        if (H_Maestro_00111cb0(work->activeAnimation) != 0) {
            for (i = 1; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[1] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
        }
        break;
    case 999:
    done:
        return;
    }
}


// FUN_001202b0
void h_campUpdateItemEighthAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/item/anm/i_c_ite08.anm");
        work->animationState = 1;
        return;
    case 1:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->transitionComplete = 1;
        work->animationState = 2;
        func_0010a4e0(0, 0, 0, 5);
        return;
    case 2:
        if (H_Maestro_00111cb0(work->activeAnimation) != 0) {
            for (i = 1; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[1] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
        }
        break;
    case 999:
    done:
        return;
    }
}

// FUN_00120410
void h_campUpdateItemSixthAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/item/anm/i_c_ite06.anm");
        work->animationState = 1;
        return;
    case 1:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        work->transitionComplete = 1;
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->animationState = 2;
        func_0010a4e0(0, 0, 0, 5);
        return;
    case 2:
        if (H_Maestro_00111cb0(work->activeAnimation) != 0) {
            for (i = 1; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[1] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
        }
        break;
    case 999:
    done:
        return;
    }
}

// FUN_00120570
void h_campUpdateItemFifthAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/item/anm/i_c_ite05.anm");
        work->animationState = 1;
        return;
    case 1:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        work->transitionComplete = 1;
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->animationState = 2;
        func_0010a4e0(0, 0, 0, 5);
        return;
    case 2:
        if (H_Maestro_00111cb0(work->activeAnimation) != 0) {
            for (i = 1; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[1] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
        }
        break;
    case 999:
    done:
        return;
    }
}

// FUN_001206d0
void h_campUpdateItemFourthAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/item/anm/i_c_ite04.anm");
        work->animationState = 1;
        return;
    case 1:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        work->transitionComplete = 1;
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->animationState = 2;
        func_0010a4e0(0, 0, 0, 5);
        return;
    case 2:
        if (H_Maestro_00111cb0(work->activeAnimation) != 0) {
            for (i = 1; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[1] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
        }
        break;
    case 999:
    done:
        return;
    }
}

// FUN_00120830
void h_campUpdateItemSeventhAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/item/anm/i_c_ite07.anm");
        work->animationState = 1;
        return;
    case 1:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        work->transitionComplete = 1;
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->animationState = 2;
        func_0010a4e0(0, 0, 0, 5);
        return;
    case 2:
        if (H_Maestro_00111cb0(work->activeAnimation) != 0) {
            for (i = 1; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[1] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
        }
        break;
    case 999:
    done:
        return;
    }
}

// FUN_00120990
void h_campUpdateSocialMainAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/commu/anm/i_c_com01.anm");
        work->animationState = 1;
        return;
    case 1:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->transitionComplete = 1;
        work->animationState = 2;
        func_0010a4e0(0, 0, 0, 3);
        return;
    case 2:
        if (H_Maestro_00111cb0(work->activeAnimation) != 0) {
            child = work->childTasks[0];
            if (child != NULL) {
                H_Maestro_SetAlphaMult(child, 0.0f);
            }
            for (i = 1; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[1] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
        }
        break;
    case 999:
    done:
        return;
    }
}


// FUN_00120b10
void h_campUpdateSocialDetailAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/commu/anm/i_c_com02.anm");
        work->animationState = 1;
        return;
    case 1:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->transitionComplete = 1;
        work->animationState = 2;
        func_0010a4e0(0, 0, 0, 3);
        return;
    case 2:
        if (H_Maestro_00111cb0(work->activeAnimation) != 0) {
            child = work->childTasks[0];
            if (child != NULL) {
                H_Maestro_SetAlphaMult(child, 0.0f);
            }
            for (i = 2; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            H_Maestro_SetAlphaMult(work->childTasks[1], 0.0f);
            work->childTasks[2] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
        }
        break;
    case 999:
    done:
        return;
    }
}

// FUN_00120ca0
void h_campUpdateSocialTransition(KwlnTask* task)
{
    CampMenuWork* work;
    s32 count;
    s32 i;
    KwlnTask* child;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->animationState = 1;
        return;
    case 1:
        work->timer = 0;
        work->animationState = 2;
        func_001958a0(uGpffffb260, work->childTasks[1]);
        func_0010a4e0(0, 0, 0, 4);
        return;
    case 2:
        count = work->timer + 1;
        work->timer = count;
        if (count == 5) {
            func_001958a0(work->childTasks[2], work->childTasks[1]);
            for (i = 2; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
            work->transitionComplete = 1;
            work->animationState = 999;
            return;
        }
        H_Maestro_SetAlphaMult(work->childTasks[1], (f32)count / 5.0f);
    case 999:
        return;
    }
}

// FUN_00120e20
void h_campUpdateSkillMainAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->animationState = 1;
        return;
    case 1:
        work->animationState = 2;
        return;
    case 2:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/skill/anm/if_c_skl01.anm");
        work->animationState = 3;
        return;
    case 3:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->transitionComplete = 1;
        work->timer = 0x18;
        work->animationState = 4;
        func_0010a4e0(0, 0, 0, 3);
        return;
    case 4:
        if (H_Maestro_00111cb0(work->activeAnimation) != 0) {
            child = work->childTasks[0];
            if (child != NULL) {
                H_Maestro_SetAlphaMult(child, 0.0f);
            }
            for (i = 1; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[1] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
        }
        break;
    case 999:
    done:
        return;
    }
}


// FUN_00120fd0
void h_campUpdateEquipMainAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->animationState = 1;
        return;
    case 1:
        work->animationState = 2;
        return;
    case 2:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/EQUIP/anm/if_c_equ01.anm");
        work->animationState = 3;
        return;
    case 3:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->transitionComplete = 1;
        work->timer = 0x18;
        work->animationState = 4;
        func_0010a4e0(0, 0, 0, 3);
        return;
    case 4:
        if (H_Maestro_00111cb0(work->activeAnimation) != 0) {
            child = work->childTasks[0];
            if (child != NULL) {
                H_Maestro_SetAlphaMult(child, 0.0f);
            }
            for (i = 1; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[1] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
        }
        break;
    case 999:
    done:
        return;
    }
}

// FUN_00121180
void h_campUpdateSkillDetailAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/skill/anm/if_c_skl02.anm");
        work->animationState = 1;
        return;
    case 1:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->animationState = 2;
        func_0010a4e0(0, 0, 0, 5);
        return;
    case 2:
        if (H_Maestro_00111cb0(work->activeAnimation) != 0) {
            child = work->childTasks[1];
            if (child != NULL) {
                H_Maestro_SetAlphaMult(child, 0.0f);
            }
            for (i = 2; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[2] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
            work->transitionComplete = 1;
        }
        break;
    case 999:
    done:
        return;
    }
}

// FUN_00121300
void h_campUpdateEquipDetailAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/EQUIP/anm/if_c_equ02.anm");
        work->animationState = 1;
        return;
    case 1:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->animationState = 2;
        func_0010a4e0(0, 0, 0, 5);
        return;
    case 2:
        if (H_Maestro_00111cb0(work->activeAnimation) != 0) {
            child = work->childTasks[1];
            if (child != NULL) {
                H_Maestro_SetAlphaMult(child, 0.0f);
            }
            for (i = 2; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[2] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
            work->transitionComplete = 1;
        }
        break;
    case 999:
    done:
        return;
    }
}

// FUN_00121480
void h_campUpdateSkillEquipBlend(KwlnTask* task)
{
    CampMenuWork* work;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], fGpffff839c);
        work->animationState = 1;
        return;
    case 1:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], fGpffff80c4);
        work->animationState = 2;
        return;
    case 2:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], fGpffff8088);
        work->animationState = 3;
    case 3:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], fGpffff82fc);
        work->animationState = 4;
    case 4:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], 0.0f);
        kwlnTaskDestroyWithHierarchy(work->childTasks[2]);
        work->childTasks[2] = NULL;
        work->transitionComplete = 1;
        work->animationState = 999;
        return;
    case 999:
        return;
    }
}

// FUN_00121600
void h_campUpdateSkillEquipExitBlend(KwlnTask* task)
{
    CampMenuWork* work;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], fGpffff839c);
        work->animationState = 1;
        return;
    case 1:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], fGpffff80c4);
        work->animationState = 2;
        return;
    case 2:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], fGpffff8088);
        work->animationState = 3;
    case 3:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], fGpffff82fc);
        work->animationState = 4;
    case 4:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], 0.0f);
        kwlnTaskDestroyWithHierarchy(work->childTasks[2]);
        work->childTasks[2] = NULL;
        work->transitionComplete = 1;
        work->animationState = 999;
        return;
    case 999:
        return;
    }
}

// FUN_00121780
void h_campUpdatePersonaMainAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->animationState = 1;
        return;
    case 1:
        work->animationState = 2;
        return;
    case 2:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/persona/anm/if_c_per01.anm");
        work->animationState = 3;
        return;
    case 3:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->transitionComplete = 1;
        work->timer = 0x18;
        work->animationState = 4;
        func_0010a4e0(0, 0, 0, 3);
        return;
    case 4:
        if (H_Maestro_00111cb0(work->activeAnimation) != 0) {
            child = work->childTasks[0];
            if (child != NULL) {
                H_Maestro_SetAlphaMult(child, 0.0f);
            }
            for (i = 1; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[1] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
        }
        break;
    case 999:
    done:
        return;
    }
}


// FUN_00121930
void h_campUpdatePersonaDetailAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/persona/anm/if_c_per02.anm");
        work->animationState = 1;
        return;
    case 1:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->animationState = 2;
        func_0010a4e0(0, 0, 0, 5);
        return;
    case 2:
        if (H_Maestro_00111cb0(work->activeAnimation) != 0) {
            child = work->childTasks[1];
            if (child != NULL) {
                H_Maestro_SetAlphaMult(child, 0.0f);
            }
            for (i = 2; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[2] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
            work->transitionComplete = 1;
        }
        break;
    case 999:
    done:
        return;
    }
}

// FUN_00121ab0
void h_campUpdatePersonaBlend(KwlnTask* task)
{
    CampMenuWork* work;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], fGpffff839c);
        work->animationState = 1;
        return;
    case 1:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], fGpffff80c4);
        work->animationState = 2;
        return;
    case 2:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], fGpffff8088);
        work->animationState = 3;
    case 3:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], fGpffff82fc);
        work->animationState = 4;
    case 4:
        H_Maestro_SetAlphaMult(work->childTasks[1], 1.0f);
        H_Maestro_SetAlphaMult(work->childTasks[2], 0.0f);
        kwlnTaskDestroyWithHierarchy(work->childTasks[2]);
        work->childTasks[2] = NULL;
        work->transitionComplete = 1;
        work->animationState = 999;
        return;
    case 999:
        return;
    }
}

// FUN_00121c30
void h_campUpdateSystemMainAnimation(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    s32 i;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->animationState = 1;
        return;
    case 1:
        work->animationState = 2;
        return;
    case 2:
        work->activeAnimation = H_Maestro_CreateTask(
            task, 0x18BD, "camp/system/anm/if_c_sys01.anm");
        work->animationState = 3;
        return;
    case 3:
        if (H_Maestro_FinishedInit(work->activeAnimation) != 1) {
            goto done;
        }
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        work->transitionComplete = 1;
        work->timer = 0x18;
        work->animationState = 4;
        func_0010a4e0(0, 0, 0, 3);
        return;
    case 4:
        if (H_Maestro_00111cb0(work->activeAnimation) != 0) {
            child = work->childTasks[0];
            if (child != NULL) {
                H_Maestro_SetAlphaMult(child, 0.0f);
            }
            for (i = 1; i < 10; i++) {
                child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
                if (child != NULL) {
                    kwlnTaskDestroyWithHierarchy(child);
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4) = NULL;
                }
            }
            work->childTasks[1] = work->activeAnimation;
            work->activeAnimation = NULL;
            work->animationState = 999;
        }
        break;
    case 999:
    done:
        return;
    }
}

// FUN_00121de0
u32 h_campRequestMenuTransition(KwlnTask* task, u32 command)
{
    CampMenuWork* work;
    u32 timer;

    work = task->workData;
    switch (command)
    {
    case 0:
        work->state = 11;
        break;
    case 1:
        switch (work->timer)
        {
        case 0:
            work->state = 1;
            break;
        case 3:
            work->state = 9;
            break;
        case 4:
        case 6:
        case 7:
        case 8:
        case 9:
        case 11:
        case 12:
        case 13:
        case 15:
        case 16:
            work->state = 9;
            break;
        case 5:
            work->state = 9;
            break;
        }
        break;
    case 2:
        switch (work->timer)
        {
        case 0:
            work->state = 1;
            break;
        case 1:
        case 2:
            break;
        case 3:
            work->state = 7;
            break;
        case 4:
        case 6:
        case 7:
        case 8:
        case 9:
        case 13:
            work->state = 9;
            break;
        case 5:
        case 10:
        case 11:
        case 12:
            break;
        }
        break;
    case 3:
        switch (work->timer)
        {
        case 0:
        case 1:
            break;
        case 2:
            work->state = 5;
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            break;
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 15:
    case 16:
        switch (work->timer)
        {
        case 0:
            break;
        case 1:
            work->state = 11;
            break;
        case 2:
            work->state = 11;
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            break;
        }
        break;
    case 9:
        switch (work->timer)
        {
        case 0:
            break;
        case 1:
            work->state = 13;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            break;
        }
        break;
    case 13:
        switch (work->timer)
        {
        case 0:
            break;
        case 1:
            work->state = 13;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            break;
        }
        break;
    }
    work->timer = command;
    return 1;
}

// FUN_00121ff0 NONMATCHING
void* h_campUpdatePanelTransition(KwlnTask* task)
{
    CampPanelTransitionWork* work;
    CampVec2 pos;

    work = task->workData;
    switch (work->state) {
    case 0:
        if (work->transitionComplete != 0) {
            pos.x = 30.0f;
            pos.y = 219.0f;
            h_campStatusDrawScreen_typed(pos, pos, 100.0f, work->drawId, 1, 0, 0);
        }
        break;
    case 1:
        work->state = 2;
        work->timer = 0;
        break;
    case 2:
        work->timer++;
        if (work->timer == 0x15) {
            work->state = 0;
            pos.x = 30.0f;
            pos.y = 219.0f;
            h_campStatusDrawScreen_typed(pos, pos, 100.0f, work->drawId, 0, work->timer, 0);
            work->transitionComplete = 1;
        }
        break;
    case 3:
        pos.x = 30.0f;
        pos.y = 219.0f;
        h_campStatusDrawScreen_typed(pos, pos, 100.0f, work->drawId, 1, 0, 0);
        work->state = 4;
        break;
    case 4:
        pos.x = 30.0f;
        pos.y = 219.0f;
        h_campStatusDrawScreen_typed(pos, pos, 100.0f, work->drawId, 1, 0, 0);
        work->state = 0;
        work->transitionComplete = 1;
        break;
    case 5:
        pos.x = 30.0f;
        pos.y = 219.0f;
        h_campStatusDrawScreen_typed(pos, pos, 100.0f, work->drawId, 1, 0, 0);
        work->state = 6;
        work->timer = 0;
        break;
    case 6:
    {
        s32 timer;
        s32 drawTimer;
        s32 fade;

        work->timer++;
        timer = work->timer;
        if (timer == 8) {
            work->transitionComplete = 0;
            work->state = 0;
        }
        drawTimer = ((CampPanelTransitionWork*)work)->timer;
        pos.x = 30.0f - (f32)((drawTimer * 500) / 8);
        pos.y = 219.0f;
        fade = (drawTimer * 255) / 8;
        h_campStatusDrawScreen_typed(pos, pos, 100.0f, work->drawId, 1, 0, fade);
        break;
    }
    case 7:
        work->timer = 0;
        work->state = 8;
        break;
    case 8:
    {
        s32 timer;
        s32 drawTimer;
        s32 fade;

        work->timer++;
        timer = work->timer;
        if (timer == 8) {
            work->transitionComplete = 1;
            work->state = 0;
        }
        drawTimer = ((CampPanelTransitionWork*)work)->timer;
        pos.x = 30.0f - (f32)(500 - (drawTimer * 500) / 8);
        pos.y = 219.0f;
        fade = 255 - (drawTimer * 255) / 8;
        h_campStatusDrawScreen_typed(pos, pos, 100.0f, work->drawId, 1, 0, fade);
        break;
    }
    case 9:
        work->state = 10;
        work->timer = 0;
        break;
    case 10:
    {
        s32 timer;
        s32 drawTimer;
        s32 fade;

        work->timer++;
        timer = work->timer;
        if (timer == 0x14) {
            work->transitionComplete = 1;
            work->state = 0;
        }
        drawTimer = ((CampPanelTransitionWork*)work)->timer;
        pos.x = 30.0f;
        pos.y = 219.0f;
        fade = 255 - (drawTimer * 255) / 0x14;
        h_campStatusDrawScreen_typed(pos, pos, 100.0f, work->drawId, 1, 0, fade);
        break;
    }
    case 11:
        if (work->transitionComplete == 0) {
            work->state = 0;
            break;
        }
        pos.x = 30.0f;
        pos.y = 219.0f;
        h_campStatusDrawScreen_typed(pos, pos, 100.0f, work->drawId, 1, 0, 0);
        work->timer = 0;
        work->state = 12;
        break;
    case 12:
    {
        s32 timer;
        s32 drawTimer;
        s32 fade;

        work->timer++;
        timer = work->timer;
        if (timer == 0xa) {
            work->transitionComplete = 0;
            work->state = 0;
        }
        drawTimer = ((CampPanelTransitionWork*)work)->timer;
        pos.x = 30.0f;
        pos.y = 219.0f;
        fade = (drawTimer * 255) / 0xa;
        h_campStatusDrawScreen_typed(pos, pos, 100.0f, work->drawId, 1, 0, fade);
        break;
    }
    case 13:
        if (work->transitionComplete == 0) {
            work->state = 0;
            break;
        }
        pos.x = 30.0f;
        pos.y = 219.0f;
        h_campStatusDrawScreen_typed(pos, pos, 100.0f, work->drawId, 1, 0, 0);
        work->timer = 0;
        work->state = 14;
        break;
    case 14:
    {
        s32 timer;
        CampVec2 other;

        work->timer++;
        timer = work->timer;
        if (timer == 8) {
            work->transitionComplete = 0;
            work->state = 0;
            break;
        }
        if (timer < 3) {
            pos.x = 30.0f;
        } else {
            pos.x = 30.0f + (f32)(((timer - 3) * 84) / 5);
        }
        pos.y = 219.0f;
        other.x = 30.0f;
        other.y = 219.0f;
        h_campStatusDrawScreen_typed(pos, other, 100.0f, work->drawId, 1, 0, 0);
        break;
    }
    }
    return KWLNTASK_CONTINUE;
}
#undef func_0018bc10
void* h_campStatusUpdatePcStatusRootTask(KwlnTask*);
void* FUN_001311d0(KwlnTask*);
void FUN_001124b0();
extern void (*jtbl_0096017C)(void* memory);
extern void (*jtbl_007B5AF0[6])();
extern void* (*DAT_00960184)(u32 elementCount, u32 elementSize,
                             u32 heapFlags);
extern s32 FUN_001159f0();
#pragma alias campStatusDrawSpriteCall FUN_001159f0
extern s32 campStatusDrawSpriteCall(u32 parent, void* resource, s32 frame,
                                    u32 alpha, f32 x, f32 y, f32 scale);
#pragma alias campStatusDrawSpriteCallXY FUN_001159f0
extern s32 campStatusDrawSpriteCallXY(u32 parent, void* resource, s32 frame,
                                      f32 x, f32 y, u32 alpha, f32 scale);
#pragma alias campStatusDrawFadeSprite FUN_001159f0
extern s32 campStatusDrawFadeSprite(f32 x, f32 y, f32 alpha, void* resource,
                                    s32 frame, s32 fade);
#pragma alias campStatusDrawSpritePackedCall FUN_001159f0
extern s32 campStatusDrawSpritePackedCall(f32 x, f32 y, u32 parent,
                                          void* resource, s32 frame,
                                          u8 alpha, f32 scale);
#pragma alias campStatusDrawSprite3Call FUN_001159f0
extern void campStatusDrawSprite3Call(f32 x, f32 y, u32 parent);
#pragma alias campStatusDrawSprite4Call FUN_001159f0
extern void campStatusDrawSprite4Call(f32 x, f32 y, f32 alpha, s32 digit);
#pragma alias campStatusDrawSpriteFadeCall FUN_00115ad0
extern void campStatusDrawSpriteFadeCall(u32 parent, void* resource, s32 frame,
                                         u32 alpha, f32 x, f32 y, f32 scale,
                                         u32 fade);
/* Fade XY order: h_campStatusDrawSp nd637/1020B -> nd591/1024B. */
#pragma alias campStatusDrawSpriteFadeXYCall FUN_00115ad0
extern void campStatusDrawSpriteFadeXYCall(u32 parent, void* resource,
                                           s32 frame, f32 x, f32 y,
                                           u32 alpha, f32 scale, u32 fade);
#pragma alias campStatusDrawGaugeCall FUN_00113a30
extern void campStatusDrawGaugeCall(f32 scale, f32 x, f32 y, u32 color,
                                    s32 width, s32 height);
#pragma alias campStatusDrawTextCall FUN_003b32d0
extern void campStatusDrawTextCall(f32 scale, s32 x, s32 y, s32 color,
                                   s32 font, s32 alignment, const char* text,
                                   s32 maxWidth, s32 shadow);
#pragma alias campStatusDrawFooterText FUN_0040eb50
extern s32 campStatusDrawFooterText(f32 scale, s32 x, s32 y, u8 color,
                                    s16 font, const char* text, s32 maxWidth);

extern s32 FUN_001120a0();
#pragma alias campStatusGetFont FUN_001120a0
extern void* campStatusGetFont(s32 font);
extern s32 FUN_00113a30();
extern s32 FUN_00114450();
extern s32 FUN_0011bba0();
extern s32 FUN_0011e380();
extern s32 FUN_0011d3a0();
extern s32 FUN_0010a4e0();
extern s32 FUN_0010c1a0();
extern s32 FUN_0010c3a0();
extern s32 FUN_00174800();
extern s32 FUN_0016c860();
extern s32 FUN_0016d2f0();
extern s32 FUN_00177280();
extern s32 FUN_001772f0();
extern s32 FUN_00177360();
extern s32 FUN_00173220();
extern s32 FUN_00173280();
extern s32 FUN_001733b0();
extern s32 FUN_00173340();
extern s32 FUN_00173330();
extern s32 FUN_00173580();
extern s32 FUN_00173660();
extern s32 FUN_00198590();
extern s32 FUN_00195290();
extern s32 FUN_00194b20();
extern s32 FUN_001158b0();
extern s32 FUN_001127d0();
extern s32 FUN_00115980();
extern s32 FUN_001126b0();
extern s32 FUN_00112740();
extern s32 FUN_00128140();
extern s32 FUN_001281e0();
extern s32 FUN_00128480();
extern s32 FUN_00128720();
extern s32 FUN_00128c40();
extern s32 FUN_00129160();
extern s32 FUN_001293b0();
extern s32 FUN_00129b30();
extern s32 FUN_0012a560();
extern s32 FUN_0012ac60();
extern s32 FUN_001339a0();
#pragma alias campStatusCreatePersonaChild FUN_001339a0
extern KwlnTask* campStatusCreatePersonaChild(KwlnTask* parent,
                                              u32 priority, u32 personaId,
                                              u32 mode, f32 alpha);
extern s32 FUN_00133a80();
extern void FUN_00133b80(KwlnTask* task, u32 personaId, u32 mode);
extern s32 FUN_00121de0();
extern s32 FUN_00127af0(KwlnTask* task);
extern KwlnTask* FUN_00127b00(KwlnTask* task, s32 resource, f32 unused,
                              CampVec2 packed, s32 mode, s32 selected);
extern s32 FUN_00127ad0(KwlnTask* task);
extern s32 FUN_00128030(KwlnTask* task);
extern KwlnTask* FUN_00128040(KwlnTask* task, s32 resource, f32 unused,
                              CampVec2 packed, s32 mode, s32 selected);
extern void FUN_00127ab0(KwlnTask* task);
extern void FUN_00127ff0(KwlnTask* task);
extern void FUN_00128010(KwlnTask* task);
extern void FUN_003b32d0();
extern void FUN_00523ac8();
extern void* DAT_00833B90;
extern void* DAT_00833B94;
extern void* DAT_00833B98;
#pragma alias DAT_00833B90_abs DAT_00833B90
extern u8 DAT_00833B90_abs[];
#pragma alias DAT_00833B98_abs DAT_00833B98
extern u8 DAT_00833B98_abs[];
#pragma alias DAT_00833B88_abs DAT_00833B88
extern u8 DAT_00833B88_abs[];
extern void* DAT_00833B74;
extern void* DAT_00833BA0;
extern char gp0xffff897c[];
extern f32 DAT_007caf38;
extern void* DAT_00833B88;
extern void* FUN_00177790(s16 pcId);
extern void* func_00112420(void* source);
extern u32 FUN_001344B0();
extern u32 FUN_00134900();
extern void FUN_00124e60(CampVec2 position, f32 alpha, void* persona,
                         s32 fade);
extern void FUN_00124fd0(CampVec2 position, f32 alpha, void* persona,
                         s32 fade);
extern const char D_005DB140[];
extern const char D_005DB050[];
extern const char D_005DB080[];
extern const char D_005DB0A0[];
extern const char D_005DB030[];
extern void* FUN_00125d70(KwlnTask* task);
void h_campStatusDrawPanelFrame(u32 parent, CampVec2 position, s32 alpha);
extern const char D_005DB158[];
extern const char D_005DACB0[];
extern const char D_005DB170[];
extern void* func_0010c1a0();
extern void* func_0010c3a0();
extern int printf(const char* format, ...);
extern void FUN_00174c10();
extern void FUN_00175200();
extern u32 FUN_003c7430();
extern u32 FUN_003c74e0();
extern u32 FUN_003c7560();
extern u32 FUN_003c7610();
extern u32 FUN_003c7700();
extern u32 FUN_003c7850();

#pragma alias campStatusDrawSpriteCall FUN_001159f0
#pragma alias campStatusDrawSpriteCallXY FUN_001159f0
#pragma alias campStatusDrawFadeSprite FUN_001159f0
#pragma alias campStatusDrawSpritePackedCall FUN_001159f0
#pragma alias campStatusDrawSprite3Call FUN_001159f0
#pragma alias campStatusDrawSprite4Call FUN_001159f0
#pragma alias campStatusDrawSpriteFadeCall FUN_00115ad0
/* Fade XY order: h_campStatusDrawSp nd637/1020B -> nd591/1024B. */
#pragma alias campStatusDrawSpriteFadeXYCall FUN_00115ad0
#pragma alias campStatusDrawGaugeCall FUN_00113a30
#pragma alias campStatusDrawTextCall FUN_003b32d0
#pragma alias campStatusDrawFooterText FUN_0040eb50

#pragma alias campStatusGetFont FUN_001120a0
#pragma alias campStatusCreatePersonaChild FUN_001339a0
#pragma alias DAT_00833B90_abs DAT_00833B90
#pragma alias DAT_00833B98_abs DAT_00833B98
#pragma alias DAT_00833B88_abs DAT_00833B88
void h_campStatusDrawPanelFrame(u32 parent, CampVec2 position, s32 alpha);

typedef struct CampStatusWork
{
    s32 state;
    s32 selectedScreen;
    s32 timer;
    s32 command;
    s32 alpha;
    KwlnTask* child;
    s32 transitionTimer;
    s32 inputResult;
    s32 unused20;
    KwlnTask* partsTask;
    void* resource;
    s32 scrollY;
    s32 appearance;
    s32 reserved34;
    s16 openingTimer;
    s16 mode;
    s16 closeTimer;
    s16 detailTimer;
} CampStatusWork;


#pragma alias FUN_0012b300_s32 FUN_0012b300
#pragma alias FUN_0012b860_s32 FUN_0012b860
#pragma alias FUN_0012bce0_s32 FUN_0012bce0
#pragma alias FUN_0012bfb0_s32 FUN_0012bfb0

void h_campStatusRenderStatIcon(CampVec2 position, f32 scale,
                                s32 stat, s32 alpha);
void h_campStatusDrawStatLabels(CampVec2 position, f32 scale,
                                void* persona, s32 alpha);
void h_campStatusDrawStatValues(CampVec2 position, f32 scale,
                                void* bonus, void* persona, s32 alpha);
void h_campStatusDrawSkillValues(CampVec2 position, f32 scale,
                                 void* bonus, void* persona, s32 alpha);
void h_campStatusDrawRankValue(CampVec2 position, f32 scale, s32 row,
                               s32 value, s32 extra, s32 alpha);
void h_campStatusDrawEquipment(CampVec2 position, f32 scale,
                               void* bonus, void* persona, s32 alpha);
typedef struct CampStatusParticle
{
    u8 reserved00[0x10];
    f32 x;
    f32 y;
    s8 alpha;
} CampStatusParticle;

static s32 sCampStatusScrollX;

static inline s32 campStatusClampFade(s32 fade)
{
    if (fade < 0) {
        return 0;
    }
    if (fade > 0xff) {
        return 0xff;
    }
    return fade;
}

static inline void campStatusDrawDigit(f32 alpha, f32 x, f32 y, s32 digit)
{
    FUN_001120a0(2);
    campStatusDrawSprite4Call(x, y, alpha, digit);
}

static void campStatusDrawNumber(f32 alpha, f32 x, f32 y, u32 value)
{
    if (value >= 100) {
        campStatusDrawDigit(alpha, x, y, value / 100);
        value %= 100;
    }
    if (value >= 10) {
        campStatusDrawDigit(alpha, x + 15.0f, y, value / 10);
        value %= 10;
    }
    campStatusDrawDigit(alpha, x + 30.0f, y, value);
}

static inline void campStatusDrawParticle(f32 texture, f32 x, f32 y, s8 alpha,
                                   s32 slot)
{
    CampStatusParticle* particle;

    particle = (CampStatusParticle*)FUN_001158b0(0, DAT_00833B90, slot);
    *(f32*)((u8*)particle + 0x2c) = texture;
    particle->x = x;
    particle->y = y;
    particle->alpha = alpha;
    FUN_001127d0(particle, 1);
    FUN_00115980(particle);
}
/* opt_common_subs off: default/on nd703/1056B -> off nd664/1096B; retained. */

void h_campStatusDrawStatus(CampVec2 position, CampVec2 unused,
                             f32 alpha, s16 pcId, s32 fade);
void h_campStatusDrawStatusTransition(CampVec2 position, f32 alpha,
                                       s16 pcId, s32 phase);
void h_campStatusDrawSp(CampVec2 position, f32 alpha, s16 pcId,
                        s32 barOffset, s32 fade);

/* opt_common_subs off: default/on nd767/1048B -> off nd765/1040B; retained. */

/* opt_common_subs off: default/on nd591/1024B -> off nd363/1016B; retained. */










typedef struct CampStatusSprite
{
    u8 reserved00[0x10];
    f32 x;
    f32 y;
    u8 alpha;
    u8 reserved19[3];
    s16 value;
    u8 reserved1e[0x0e];
    f32 scale;
} CampStatusSprite;

typedef s32 (*CampStatusRawSpriteFn)(void* parent, void* resource,
                                     s32 frame, u32 alpha, f32 x, f32 y,
                                     f32 scale);

static inline void campStatusDrawSprite(void* resource, s32 frame, f32 x, f32 y,
                                 f32 scale, s32 alpha)
{
    CampStatusRawSpriteFn draw;

    draw = (CampStatusRawSpriteFn)FUN_001159f0;
    draw((void*)(u32)0x42c80000, resource, frame, (u32)alpha, x, y,
         scale);
}

static inline void campStatusDrawBar(f32 scale, f32 x, f32 y, u8 alpha,
                              s32 frame, s32 value)
{
    CampStatusSprite* sprite;

    sprite = (CampStatusSprite*)(u32)FUN_001158b0(0, DAT_00833B98, frame);
    sprite->scale = scale;
    sprite->x = x;
    sprite->y = y;
    sprite->alpha = alpha;
    sprite->value = (s16)((value * 0xe3) / 99);
    FUN_001127d0(sprite, 1);
    FUN_00115980(sprite);
}

static void campStatusDrawValue(f32 scale, f32 x, f32 y,
                                u8 alpha, s32 value)
{
    campStatusDrawBar(scale, x, y, alpha, 0x18, value);
}

static inline s32 campStatusGetDisplayedValue(void* persona, void* bonus,
                                       s32 index, s32 useSkillAccessors)
{
    s32 value;

    if (useSkillAccessors != 0) {
        value = FUN_00173580(persona, index) & 0xff;
    } else {
        value = FUN_00173660(persona, index) & 0xff;
    }
    if (bonus != NULL) {
        value += *((u8*)bonus + 0x38 + index);
    }
    return value;
}

#define campStatusDrawDigitRow(x, y, scale, bonus, persona, alpha, index, \
                               useSkillAccessors) \
{ \
    u32 rowValue; \
    void* rowResource; \
    if ((useSkillAccessors) != 0) { \
        rowValue = FUN_00173580((persona), (index)) & 0xff; \
    } else { \
        rowValue = FUN_00173660((persona), (index)) & 0xff; \
    } \
    if ((bonus) != NULL) { \
        rowValue += *((u8*)(bonus) + 0x38 + (index)); \
    } \
    if (rowValue >= 10) { \
        rowResource = campStatusGetFont(2); \
        campStatusDrawSpriteCallXY(parent, rowResource, \
                                   rowValue / 10 + 0xb, \
                                   (x) + 69.0f, \
                                   (y) + 131.0f + \
                                       (f32)((index) * 19) - 25.0f, \
                                   (u8)(alpha), (scale)); \
    } \
    rowResource = campStatusGetFont(2); \
    campStatusDrawSpriteCallXY(parent, rowResource, \
                               rowValue % 10 + 0xb, \
                               (x) + 85.0f, \
                               (y) + 131.0f + \
                                   (f32)((index) * 19) - 25.0f, \
                               (u8)(alpha), (scale)); \
}

static inline void campStatusDrawDigits(CampVec2 position, f32 scale,
                                        void* bonus, void* persona,
                                        s32 alpha, s32 useSkillAccessors)
{
    u32 parent;
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 0, useSkillAccessors);
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 1, useSkillAccessors);
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 2, useSkillAccessors);
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 3, useSkillAccessors);
    campStatusDrawDigitRow(position.x, position.y, scale, bonus, persona,
                           alpha, 4, useSkillAccessors);
}

static void campStatusDrawStats(CampVec2 position, f32 scale, void* persona,
                                u8 alpha, u8 drawCurrent)
{
    s32 i;
    s32 value;
    s32 current;

    for (i = 0; i < 5; i++) {
        value = FUN_00173660(persona, i) & 0xff;
        current = 0;
        if (drawCurrent != 0) {
            current = *((u8*)persona + 0x38 + i);
        }
        h_campStatusDrawRankValue(position, scale, i, value, current, alpha);
    }
}

static void campStatusDrawExp(CampVec2 position, f32 scale, void* bonus,
                              void* persona, u8 alpha)
{
    char text[0x100];
    s32 current;
    s32 next;

    h_campStatusDrawEquipment(position, scale, bonus, persona, alpha);
    campStatusDrawSprite(DAT_00833B90, 0x11, position.x + 33.0f,
                         position.y + 278.0f, scale, alpha);
    campStatusDrawSprite(DAT_00833B90, 0x22, position.x + 287.0f,
                         position.y + 280.0f, scale, alpha);
    if (*((u8*)persona + 4) == 0x63) {
        sprintf(text, "%d", 0);
    } else {
        current = FUN_00173340(persona);
        next = FUN_00173330(persona);
        sprintf(text, "%d", current - next);
    }
    FUN_0040eb50((s32)(position.x + 287.0f), (s32)(position.y + 280.0f),
                 (u8)(0xff - alpha), 4, text, 1);
}

/* opt_loop_invariants on: off nd897/1192B -> on nd755/1232B; retained. */

/* opt_loop_invariants on: off nd449/604B -> on nd391/612B; retained. */

/*
 * Status-screen renderer and transition tasks.
 *
 * The retail status UI keeps two small task work areas: the first owns the
 * archive/texture used by the PC status parts task, while the second drives
 * the animated stat panel.  Keep the offsets explicit here; these layouts are
 * shared with the callbacks registered by the surrounding camp code.
 */
typedef struct CampStatusPartsWork
{
    u32 state;                 /* 0x00 */
    f32 x;                     /* 0x04 */
    f32 y;                     /* 0x08 */
    s16 alpha;                 /* 0x0c */
    s16 mode;                  /* 0x0e */
    s16 screen;                /* 0x10 */
    s16 detailFrame;           /* 0x12 */
    u32 flags;                 /* 0x14 */
    u32 ready;                 /* 0x18 */
    s32 result;                /* 0x1c */
    u32 reserved20[6];         /* 0x20..0x34 */
    void* ownedResource;       /* 0x38 */
    void* archive;             /* 0x3c */
    void* parsedResource;      /* 0x40 */
    f32 scrollY;               /* 0x44 */
} CampStatusPartsWork;

typedef struct CampStatusPanelWork
{
    u32 state;                 /* 0x00 */
    f32 x;                     /* 0x04 */
    f32 y;                     /* 0x08 */
    s16 alpha;                 /* 0x0c */
    s16 priorityMode;          /* 0x0e */
    s16 animationFrame;        /* 0x10 */
    s16 panelMode;             /* 0x12 */
    s32 result;                /* 0x14 */
    u32 ready;                 /* 0x18 */
    KwlnTask* child;           /* 0x1c */
} CampStatusPanelWork;

typedef struct CampStatusVertex
{
    RwV3d position;
    f32 cameraZ;
    f32 u;
    f32 v;
    f32 recipZ;
    f32 pad0;
    RwRGBAReal color;
    RwV3d normal;
    f32 pad1;
} CampStatusVertex;

extern void (*DAT_00960090)(u32 state, u32 value);
extern void (*DAT_009600A0)(u32 primitive, CampStatusVertex* vertices,
                            s32 vertexCount);
extern f32 DAT_00960088;
#pragma alias DAT_00960090_abs DAT_00960090
extern u8 DAT_00960090_abs[];
#pragma alias DAT_009600A0_abs DAT_009600A0
extern u8 DAT_009600A0_abs[];
#pragma alias DAT_00960088_abs DAT_00960088
extern u8 DAT_00960088_abs[];
extern s32 FUN_00198590();
extern void (*jtbl_007B5B60[9])();
extern void* DAT_00833B98;
extern s32 iGpffffb7fc;
extern const void* gp0xffff8980;
extern s32 FUN_00100ec0();
extern s32 FUN_004d0f00();
extern s32 FUN_001fc230();
extern s32 FUN_001fc3c0();
extern s32 FUN_001fb1f0();
extern void FUN_003b32d0();
#pragma alias FUN_003b32d0_typed FUN_003b32d0
extern void FUN_003b32d0_typed(f32 depth, s32 x, s32 y, s32 color, s32 font,
                                s32 alignment, const char* text, s32 maxWidth,
                                s32 shadow);
extern void FUN_00523ac8();

#pragma alias DAT_00960090_abs DAT_00960090
#pragma alias DAT_009600A0_abs DAT_009600A0
#pragma alias DAT_00960088_abs DAT_00960088
#pragma alias FUN_003b32d0_typed FUN_003b32d0

static void h_campStatusDrawQuad(f32 x, f32 y, f32 width, f32 height,
                                  u32 texture, s32 alpha)
{
    CampStatusVertex vertices[4];
    void* camera;
    f32 recipZ;
    s32 i;

    camera = (void*)FUN_00198590();
    recipZ = 1.0f / *((f32*)camera + 0x20);
    (*DAT_00960090)(6, 1);
    (*DAT_00960090)(7, 2);
    (*DAT_00960090)(8, 1);
    (*DAT_00960090)(11, 6);
    (*DAT_00960090)(10, 5);
    (*DAT_00960090)(9, 2);
    (*DAT_00960090)(12, 1);
    (*DAT_00960090)(2, 4);
    for (i = 0; i < 4; i++) {
        vertices[i].position.z = DAT_00960088 - x;
        vertices[i].recipZ = recipZ;
        vertices[i].color.r = 255.0f;
        vertices[i].color.g = 255.0f;
        vertices[i].color.b = 255.0f;
        vertices[i].color.a = (f32)alpha;
    }
    vertices[0].position.x = x;
    vertices[0].position.y = y;
    vertices[0].u = 0.0f;
    vertices[0].v = 0.0f;
    vertices[1].position.x = x + width;
    vertices[1].position.y = y;
    vertices[1].u = 1.0f;
    vertices[1].v = 0.0f;
    vertices[2].position.x = x;
    vertices[2].position.y = y + height;
    vertices[2].u = 0.0f;
    vertices[2].v = 1.0f;
    vertices[3].position.x = x + width;
    vertices[3].position.y = y + height;
    vertices[3].u = 1.0f;
    vertices[3].v = 1.0f;
    (*DAT_00960090)(1, texture);
    (*DAT_009600A0)(4, vertices, 4);
}

static void h_campStatusDrawStatIcon(u32 parent, CampVec2 position,
                                      s32 stat, s32 alpha)
{
    static const s32 iconX[9] = { 29, 69, 109, 159, 199, 239, 279, 319, 359 };
    f32 x;
    f32 y;

    if (stat < 0 || stat >= 9) {
        return;
    }
    x = position.x + (f32)iconX[stat];
    y = position.y + 44.0f;
    FUN_001159f0(x, y, parent, DAT_00833B98, stat, alpha & 0xff);
}

static void h_campStatusDrawStatIcons(u32 parent, CampVec2 position,
                                       void* persona, s32 alpha)
{
    static const s32 accessor[9] = { 0, 1, 2, 3, 4, 5, 6, 8, 9 };
    s32 i;

    for (i = 0; i < 9; i++) {
        FUN_001733b0(persona, accessor[i]);
        h_campStatusDrawStatIcon(parent, position, i, alpha);
    }
}

static s32 h_campStatusStatValue(void* persona, void* bonus, s32 index)
{
    s32 value;

    value = (s32)(FUN_00173660(persona, index) & 0xff);
    if (bonus != NULL) {
        value += *((u8*)bonus + 0x38 + index);
    }
    return value;
}

static s32 h_campStatusSkillValue(void* persona, void* bonus, s32 index)
{
    s32 value;

    value = (s32)(FUN_00173580(persona, index) & 0xff);
    if (bonus != NULL) {
        value += *((u8*)bonus + 0x38 + index);
    }
    return value;
}

static void h_campStatusDrawLabelRow(u32 parent, CampVec2 position,
                                     void* persona, void* bonus, s32 alpha,
                                     s32 useSkillAccessors)
{
    s32 i;
    s32 value;
    s32 x;
    f32 y;

    for (i = 0; i < 5; i++) {
        value = useSkillAccessors
            ? h_campStatusSkillValue(persona, bonus, i)
            : h_campStatusStatValue(persona, bonus, i);
        x = (s32)position.x + 104;
        y = position.y + 129.0f + (f32)(i * 19) - 25.0f;
        FUN_001159f0((f32)x, y, parent, DAT_00833B98, 20, alpha & 0xff);
        FUN_001159f0(position.x + 333.0f, y, parent, DAT_00833B98, 21,
                     alpha & 0xff);
        {
            void* text;
            text = (void*)(u32)FUN_001158b0(0, DAT_00833B98, 0x18);
            *((u32*)text + 11) = parent;
            *((f32*)text + 4) = (f32)x + 4.0f;
            *((f32*)text + 5) = y + 1.0f;
            *((u8*)text + 0x18) = (u8)alpha;
            *((s16*)text + 0x0e) = (s16)((value * 0xe3) / 99);
            FUN_001127d0(text, 1);
            FUN_00115980(text);
        }
    }
}

static void h_campStatusDrawEquipmentSlots(u32 parent, CampVec2 position,
                                            void* persona, void* bonus,
                                            s32 alpha)
{
    u16 equipped[8];
    char text[44];
    s32 i;
    s32 row;
    s32 col;
    s32 item;
    s32 disabled;
    s32 count;

    for (row = 0; row < 2; row++) {
        for (col = 0; col < 4; col++) {
            i = row * 4 + col;
            FUN_001159f0(position.x + 34.0f + (f32)(row * 190),
                         position.y + 316.0f + (f32)(col * 24), parent);
            item = *((u16*)persona + 3 + i);
            if (item == 0) {
                continue;
            }
            disabled = bonus == NULL || *((s16*)((u8*)bonus + 0x3e + i * 2)) == 0;
            FUN_00523ac8(text, gp0xffff897c,
                         iGpffffb7fc + item * 0x13);
            FUN_003b32d0(parent,
                         (s32)position.x + 44 + row * 190,
                         (s32)position.y + 320 + col * 24,
                         disabled ? ((0xff - alpha) | 0x95b9ff00)
                                  : ((0xff - alpha) | 0x77ffcf00),
                         6, 1, text, 0x10, 0x78);
        }
    }
    if (FUN_001fc230(persona) != 0) {
        FUN_001159f0(position.x + 411.0f, position.y + 326.0f, parent);
        FUN_001159f0(position.x + 557.0f, position.y + 326.0f, parent);
        count = FUN_001fc3c0(persona);
        if (count < 10) {
            FUN_001120a0(2);
            FUN_001159f0(position.x + 534.0f, position.y + 328.0f,
                         parent);
        }
        else {
            FUN_001120a0(2);
            FUN_001159f0(position.x + 526.0f, position.y + 328.0f,
                         parent);
            FUN_001120a0(2);
            FUN_001159f0(position.x + 541.0f, position.y + 328.0f,
                         parent);
        }
    }
    count = 0;
    FUN_001fb1f0(persona, equipped, &count);
    if (count > 7) {
        count = 7;
    }
    for (i = 0; i < count; i++) {
        if (equipped[i] != 0) {
            FUN_001159f0(position.x + 414.0f + (f32)((i / 2) * 62),
                         position.y + 340.0f + (f32)((i & 1) * 24), parent);
            FUN_00523ac8(text, gp0xffff897c,
                         iGpffffb7fc + equipped[i] * 0x13);
            FUN_003b32d0(parent,
                         (s32)position.x + 424 + (i / 2) * 62,
                         (s32)position.y + 344 + (i & 1) * 24,
                         (0xff - alpha) | 0x95b9ff00,
                         6, 1, text, 0x10, 0x78);
        }
    }
}



static void h_campStatusDrawPanel(CampStatusPartsWork* work, s32 alpha,
                                  f32 yOffset, void* persona, void* bonus)
{
    CampVec2 position;
    u32 parent;

    position.x = 188.0f - yOffset;
    position.y = work->scrollY;
    h_campStatusDrawViewport(work->parsedResource, position, 105.0f, alpha);
    h_campStatusDrawStatIcons(parent, position, persona, alpha);
    h_campStatusDrawLabelRow(parent, position, persona, bonus, alpha, 0);
    h_campStatusDrawEquipmentSlots(parent, position, persona, bonus, alpha);
}

static inline void h_campStatusResetInput(CampStatusPartsWork* work, s32 mask)
{
    if ((DAT_007e094e & 0x20) != 0) {
        FUN_0010a4e0(0, 0, 0, 2);
        work->result = -1;
    }
    else if ((DAT_007e094e & mask) != 0 ||
             (DAT_007e0958 & mask) != 0) {
        FUN_0010a4e0(0, 0, 0, 0);
        work->result = 1;
    }
}


/* Retail panel frame: seventeen status sprites, two footer sprites, and the
 * formatted footer text, with resource and frame selections from retail. */






void h_campStatusRenderMode(CampVec2 position, f32 scale, void* persona,
                            s32 mode, s32 frame, s32 alpha);
/* opt_common_subs off: default/on nd634/920B -> off nd614/944B; retained. */






void h_campStatusDrawTransition(CampVec2 position, f32 scale,
                                void* persona, s32 frame);
void h_campStatusDrawEntering(CampVec2 position, f32 scale,
                              void* persona, s32 frame);
void h_campStatusDrawSteady(CampVec2 position, f32 scale,
                            void* persona, s32 alpha);







static void h_campStatusDrawBody(u32 parent, CampVec2 position, void* persona,
                                 void* bonus, s32 alpha)
{
    s32 i;
    s32 value;
    s32 x;
    s32 y;
    char text[264];
    void* glyph;
    CampVec2 labelPos;

    h_campStatusDrawStatLabels(position, 0.0f, persona, alpha);
    h_campStatusDrawStatValues(position, 0.0f, bonus, persona, alpha);
    h_campStatusDrawEquipmentSlots(parent, position, persona, bonus, alpha);
    labelPos.x = position.x + 12.0f;
    labelPos.y = position.y + 96.0f;
    FUN_001159f0(labelPos.x + 21.0f, labelPos.y + 182.0f, parent);
    FUN_001159f0(labelPos.x + 296.0f, labelPos.y + 182.0f, parent);
    if (*((char*)persona + 4) != 'c') {
        value = FUN_00173340(persona) - FUN_00173330(persona);
        FUN_00523ac8(text, gp0xffff8978, value);
    }
    else {
        FUN_00523ac8(text, gp0xffff8980);
    }
    FUN_0040eb50(parent, (s32)(labelPos.x + 275.0f),
                 (s32)(labelPos.y + 184.0f), 0xff - alpha, 4, text, 1);
    glyph = (void*)FUN_001158b0(0, DAT_00833B98, 0x18);
    *((u32*)glyph + 11) = parent;
    *((f32*)glyph + 4) = position.x + 108.0f;
    *((f32*)glyph + 5) = position.y + 130.0f;
    *((u8*)glyph + 0x18) = (u8)alpha;
    value = FUN_00173660(persona, 0) & 0xff;
    *((s16*)glyph + 0x0e) = (s16)((value * 0xe3) / 99);
    FUN_001127d0(glyph, 1);
    FUN_00115980(glyph);
    for (i = 0; i < 5; i++) {
        x = (s32)position.x + 104;
        y = (s32)position.y + 129 + i * 19 - 25;
        FUN_001159f0((f32)x, (f32)y, parent);
    }
}


/* opt_loop_invariants on: off nd1115/1508B -> on nd1088/1520B; retained. */
/*
 * Persona status draw task.
 *
 * The retail callback owns the asynchronous archive used by the status
 * carousel and keeps the selected hero-persona list in the task work area.
 * The state values below mirror the observed loading, draw, transition, and
 * close phases; offsets are kept explicit because the task is shared with
 * the destroy/create callbacks above.
 */
typedef union CampStatusPackedPosition
{
    struct
    {
        f32 x;
        f32 y;
    } coordinates;
    u64 value;
} CampStatusPackedPosition;
#pragma alias campStatusDrawStatsPacked FUN_0012b860
#pragma alias campStatusDrawSkillsPacked FUN_0012bce0
#pragma alias campStatusDrawRanksPacked FUN_0012bfb0
#pragma alias campStatusDrawPersonaTopPacked FUN_00124e60
#pragma alias campStatusDrawPersonaBottomPacked FUN_00124fd0

typedef s32 (*CampStatusSpriteDrawFn)(void* parent, void* resource,
                                      s32 frame, u32 alpha, f32 x, f32 y,
                                      f32 scale);
typedef KwlnTask* (*CampStatusPersonaChildCreateFn)(KwlnTask* parent,
                                                    u32 priority,
                                                    u32 personaId, u32 mode,
                                                    f32 alpha);

#define campStatusAnimateRecord(records, index, alphaMode, start, end, \
                                startFrame, endFrame) \
    campStatusDrawTransitionCall(100.0f, (u8*)(records) + (index) * 0x44, 0, 2, \
                  (alphaMode), *(u64*)&(start), *(u64*)&(end), \
                  0, 0, (startFrame), (endFrame))

#define campStatusSetListPosition(position, row, selected, alternate) \
    do { \
        (position).x = (alternate) != 0 ? -11.0f : 119.0f; \
        (position).y = (alternate) != 0 ? 63.0f : 73.0f; \
        (position).y += (f32)((row) * 29); \
        if ((selected) != 0) (position).x += 21.0f; \
    } while (0)

static inline CampVec2 campStatusListPosition(s32 row, s32 selected, s32 alternate)
{
    CampVec2 position;

    position.x = alternate != 0 ? -11.0f : 119.0f;
    position.y = alternate != 0 ? 63.0f : 73.0f;
    position.y += (f32)(row * 29);
    if (selected != 0) {
        position.x += 21.0f;
    }
    return position;
}

static inline void campStatusInitializePersonaList(void* records, s32 selected,
                                            s32 count)
{
    CampVec2 zero;
    CampVec2 position;
    CampVec2 start;
    s32 i;

    zero.x = 0.0f;
    zero.y = 0.0f;
    campStatusAnimateRecord(records, 0, 1, zero, zero, 5, 5);
    for (i = 0; i < count; i++) {
        campStatusSetListPosition(position, i, i == selected, 0);
        start = position;
        start.x -= 600.0f;
        campStatusAnimateRecord(records, i + 1, 1, start, position, 0, 10);
        campStatusSetListPosition(position, i, i == selected, 1);
        start = position;
        start.x -= 600.0f;
        campStatusAnimateRecord(records, i + 14, 1, start, position, 0, 6);
    }
    position.x = 497.0f;
    position.y = 26.0f;
    start = position;
    start.x += 600.0f;
    campStatusAnimateRecord(records, 27, 1, start, position, 0, 10);
    position.x = 34.0f;
    position.y = 415.0f;
    start = position;
    start.x += 600.0f;
    campStatusAnimateRecord(records, 28, 1, start, position, 0, 10);
}

static inline void campStatusClosePersonaList(void* records, s32 selected, s32 count)
{
    CampVec2 position;
    s32 i;

    position.x = *((f32*)((u8*)records + 0x38));
    position.y = *((f32*)((u8*)records + 0x3c));
    campStatusAnimateRecord(records, 0, 2, position, position, 5, 5);
    for (i = 0; i < count; i++) {
        campStatusSetListPosition(position, i, i == selected, 0);
        campStatusAnimateRecord(records, i + 1, 2, position, position, 0,
                                10);
        campStatusSetListPosition(position, i, i == selected, 1);
        campStatusAnimateRecord(records, i + 14, 2, position, position, 0,
                                6);
    }
    position.x = 497.0f;
    position.y = 26.0f;
    campStatusAnimateRecord(records, 27, 2, position, position, 0, 10);
    position.x = 34.0f;
    position.y = 415.0f;
    campStatusAnimateRecord(records, 28, 2, position, position, 0, 10);
}

static inline void campStatusAnimateSelection(void* records, s32 oldSelected,
                                       s32 selected)
{
    CampVec2 start;
    CampVec2 end;

    campStatusSetListPosition(start, oldSelected, 1, 0);
    campStatusSetListPosition(end, oldSelected, 0, 0);
    campStatusAnimateRecord(records, oldSelected + 1, 0, start, end, 0, 2);
    campStatusSetListPosition(start, oldSelected, 1, 1);
    campStatusSetListPosition(end, oldSelected, 0, 1);
    campStatusAnimateRecord(records, oldSelected + 14, 0, start, end, 0, 2);
    campStatusSetListPosition(start, selected, 0, 0);
    campStatusSetListPosition(end, selected, 1, 0);
    campStatusAnimateRecord(records, selected + 1, 0, start, end, 0, 2);
    campStatusSetListPosition(start, selected, 0, 1);
    campStatusSetListPosition(end, selected, 1, 1);
    campStatusAnimateRecord(records, selected + 14, 0, start, end, 0, 2);
}

static inline void campStatusInitializeDetail(void* records, s32 alphaMode)
{
    CampVec2 position;

    position.x = 0.0f;
    position.y = 0.0f;
    campStatusAnimateRecord(records, 0, alphaMode, position, position, 0,
                            10);
    position.x = 42.0f;
    position.y = 12.0f;
    campStatusAnimateRecord(records, 2, alphaMode, position, position, 0, 8);
    position.x = 519.0f;
    position.y = 12.0f;
    campStatusAnimateRecord(records, 3, alphaMode, position, position, 0, 8);
    position.x = 170.0f;
    position.y = 8.0f;
    campStatusAnimateRecord(records, 4, alphaMode, position, position, 0, 8);
    position.x = 34.0f;
    position.y = 415.0f;
    campStatusAnimateRecord(records, 5, alphaMode, position, position, 0, 8);
}

static inline void campStatusAnimateDetailSelection(void* records)
{
    CampVec2 zero;

    zero.x = 0.0f;
    zero.y = 0.0f;
    campStatusAnimateRecord(records, 0, 1, zero, zero, 0, 10);
    campStatusAnimateRecord(records, 1, 2, zero, zero, 0, 10);
}

static inline void campStatusUpdatePersonaChild(u8* work, s32 selected)
{
    KwlnTask* child;
    u32 personaId;

    child = *(KwlnTask**)(work + 0x54);
    personaId = *(u16*)(work + 0x1a + selected * 2);
    FUN_00133b80(child, personaId, (u32)-1);
    FUN_00133a80(child);
}

static inline void campStatusDrawMain(u8* work, s32 selected)
{
    u32 result;

    campStatusUpdatePersonaChild(work, selected);
    result = FUN_001344B0(*(void**)(work + 0x64), work + 0x58,
                          work + 0x32, (s16)selected);
    *(u32*)(work + 0x4c) = result;
}
static inline void campStatusDrawMainDiscardResult(u8* work, s32 selected)
{
    campStatusUpdatePersonaChild(work, selected);
    FUN_001344B0(*(void**)(work + 0x64), work + 0x58, work + 0x32,
                 (s16)selected);
}

static inline void campStatusDrawDetail(u8* work, s32 selected, s32 previous)
{
    u32 result;

    campStatusUpdatePersonaChild(work, selected);
    FUN_001344B0(*(void**)(work + 0x64), work + 0x58, work + 0x32,
                 (s16)selected);
    result = FUN_00134900(*(void**)(work + 0x68), work + 0x58,
                          work + 0x32, (s16)selected, (s16)previous);
    *(u32*)(work + 0x4c) = result;
}

static inline void campStatusDrawDetailDiscardResult(u8* work, s32 selected,
                                              s32 previous)
{
    campStatusUpdatePersonaChild(work, selected);
    FUN_001344B0(*(void**)(work + 0x64), work + 0x58, work + 0x32,
                 (s16)selected);
    FUN_00134900(*(void**)(work + 0x68), work + 0x58, work + 0x32,
                 (s16)selected, (s16)previous);
}

static inline void campStatusRebuildPersonaList(u8* work)
{
    DatPersonaWork* persona;
    s32 count;
    s32 i;

    count = 0;
    for (i = 0; i < 12; i++) {
        *(u16*)(work + 0x1a + count * 2) = 0;
        if (datPersonaHeroPersonaValid((s16)i) != 0) {
            persona = datPersonaGetHeroPersona((s16)i);
            printf(D_005DB158, persona->id);
            *(u16*)(work + 0x1a + count * 2) = persona->id;
            *(u16*)(work + 0x32 + count * 2) = (u16)i;
            count++;
        }
    }
    *(s16*)(work + 0x4a) = (s16)count;
    if (*(s32*)(work + 0x4) >= count) {
        *(s32*)(work + 0x4) = count - 1;
    }
}

static inline void campStatusResetPersonaAnimations(void* records)
{
    u8* record;
    s32 i;

    for (i = 0; i < 12; i++) {
        record = (u8*)records + i * 0x44;
        *(u32*)(record + 0x48) = 0;
        *(u32*)(record + 0x3bc) = 0;
    }
}




/* Retail 0x1313e0 uses the direct child-create call; case 1 reloads archive
 * state at 0x13132c/0x131368/0x1313a4, and case 3 reloads records at
 * 0x131504/0x1315f0/0x13169c/0x1316e8. */



