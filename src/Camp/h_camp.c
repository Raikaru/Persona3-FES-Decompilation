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
extern void func_0018bc10(void* transition, s32 drawMode,
                          s32 positionMode, s32 alphaMode,
                          u64 start, u64 end, s32 param0, s32 tile,
                          f32 depth, s32 startFrame, s32 endFrame);
#define campStatusDrawTransitionCall(depth, transition, drawMode, positionMode, alphaMode, start, end, param0, tile, startFrame, endFrame) \
    func_0018bc10(transition, drawMode, positionMode, alphaMode, start, end, param0, tile, depth, startFrame, endFrame)
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
