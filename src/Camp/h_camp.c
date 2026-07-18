#include "Camp/h_camp.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Main/g_data.h"
#include "h_cdvd.h"
#include "h_maestro.h"
#include "rw/rwplcore.h"

extern void* func_0010c1a0();
extern void* func_0010c3a0();
extern void func_00133d30();
extern void func_004d0f00();
extern void func_001958a0();
extern void func_001957b0();
extern void func_00123640();
extern f32 fGpffff839c;
extern f32 fGpffff80c4;
extern f32 fGpffff8088;
extern f32 fGpffff82fc;
extern void* uGpffffb260;
extern void func_001958a0(void* source, KwlnTask* destination);
extern void func_001957b0(KwlnTask* source, KwlnTask* destination);
extern void func_0010a4e0(s32 bank, s32 cue, s32 variant, s32 pan);
extern u8* iGpffffb25c;
extern void func_0018bc10(void* transition, s32 drawMode,
                          s32 positionMode, s32 alphaMode,
                          u64 start, u64 end, s32 param0, s32 tile,
                          f32 depth, s32 startFrame, s32 endFrame);

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
    u8 trailing[0xc];
} CampUiRecord;

static void h_campDestroyChildren(CampMenuWork* work, s32 firstChild)
{
    s32 i;

    for (i = firstChild; i < (s32)ARRAY_SIZE(work->childTasks); i++) {
        if (work->childTasks[i] != NULL) {
            kwlnTaskDestroyWithHierarchy(work->childTasks[i]);
            work->childTasks[i] = NULL;
        }
    }
}

static void h_campSetChildAlpha(CampMenuWork* work, s32 firstChild, f32 alpha)
{
    s32 i;

    for (i = firstChild; i < (s32)ARRAY_SIZE(work->childTasks); i++) {
        if (work->childTasks[i] != NULL) {
            H_Maestro_SetAlphaMult(work->childTasks[i], alpha);
        }
    }
}

/*
 * Most sub-screen animation callbacks use the same lifecycle: create a Maestro
 * child, wait until its archive/scene is ready, request drawing, then retire
 * the old child hierarchy after a short transition interval.
 */
static void h_campUpdateAnimationLifecycle(KwlnTask* task, const char* path,
                                           s32 firstChild, s32 keepFirstChild,
                                           s32 transitionFrames)
{
    CampMenuWork* work;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->activeAnimation = H_Maestro_CreateTask(task, 0x18BD, path);
        work->animationState = 1;
        break;
    case 1:
        if (work->activeAnimation == NULL || !H_Maestro_FinishedInit(work->activeAnimation)) {
            break;
        }
        H_Maestro_RequestDraw(work->activeAnimation);
        H_Maestro_00111f20(work->activeAnimation, 1);
        H_Maestro_SetAlphaMult(work->activeAnimation, 1.0f);
        work->transitionComplete = 1;
        work->timer = transitionFrames;
        work->animationState = 2;
        break;
    case 2:
        if (work->timer != 0) {
            work->timer--;
            break;
        }
        if (keepFirstChild) {
            h_campSetChildAlpha(work, firstChild, 0.0f);
        }
        h_campDestroyChildren(work, firstChild);
        work->retainedAnimation = work->activeAnimation;
        work->activeAnimation = NULL;
        work->animationState = 999;
        break;
    }
}

static void h_campUpdateAnimationBlend(KwlnTask* task, s32 sourceIndex, s32 destinationIndex,
                                       s32 frameCount)
{
    CampMenuWork* work;
    f32 progress;

    work = task->workData;
    switch (work->animationState) {
    case 0:
        work->timer = 0;
        work->animationState = 1;
        break;
    case 1:
        work->timer++;
        progress = (f32)work->timer / (f32)frameCount;
        if (progress > 1.0f) {
            progress = 1.0f;
        }
        if (sourceIndex >= 0 && sourceIndex < (s32)ARRAY_SIZE(work->childTasks) &&
            work->childTasks[sourceIndex] != NULL) {
            H_Maestro_SetAlphaMult(work->childTasks[sourceIndex], 1.0f - progress);
        }
        if (destinationIndex >= 0 && destinationIndex < (s32)ARRAY_SIZE(work->childTasks) &&
            work->childTasks[destinationIndex] != NULL) {
            H_Maestro_SetAlphaMult(work->childTasks[destinationIndex], progress);
        }
        if (work->timer >= (u32)frameCount) {
            if (sourceIndex >= 0 && sourceIndex < (s32)ARRAY_SIZE(work->childTasks) &&
                work->childTasks[sourceIndex] != NULL) {
                kwlnTaskDestroyWithHierarchy(work->childTasks[sourceIndex]);
                work->childTasks[sourceIndex] = NULL;
            }
            work->transitionComplete = 1;
            work->animationState = 999;
        }
        break;
    }
}

// FUN_0011a050 NONMATCHING
void* h_campUpdateTask(KwlnTask* task)
{
    CampDrawWork* work;

    work = task->workData;
    switch (work->state) {
    case 0:
        /* The Camp UI owns the menu state task and the two persona children. */
        if (sCampMenuTask == NULL) {
            sCampMenuTask = h_campCreateMenuTask(task);
            work->menuTask = sCampMenuTask;
        }
        work->state = 1;
        break;
    case 1:
        if (sCampPersonaDisplayTask == NULL ||
            kwlnTaskGetState(sCampPersonaDisplayTask) == KWLNTASK_STATE_DESTROY) {
            datSetFlag(0x1407, 1);
            work->state = 2;
        }
        break;
    case 2:
        if (sCampRootDrawTask == NULL) {
            sCampRootDrawTask = h_campCreateRootDrawTask(task, work->menuTask, work->rootStarted);
        }
        work->rootTask = sCampRootDrawTask;
        work->state = 3;
        break;
    case 3:
        if (sCampRootDrawTask == NULL) {
            work->state = 2;
            break;
        }
        if (h_campGetRootCommand(sCampRootDrawTask) == (u32)-1) {
            return KWLNTASK_STOP;
        }
        break;
    default:
        /* Screen tasks are owned by their parent hierarchy and finish independently. */
        if (work->activeScreenTask != NULL &&
            kwlnTaskGetState(work->activeScreenTask) == KWLNTASK_STATE_DESTROY) {
            work->activeScreenTask = NULL;
            work->needsRootRedraw = 1;
        }
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

// FUN_0011a8a0 NONMATCHING
void* h_campUpdateSpriteSetupTask(KwlnTask* task)
{
    CampSpriteSetupWork* work;
    static const s32 resourceSlots[8] = { 0, 1, 6, 8, 9, 10, 11, 12 };
    s32 i;
    u32 size;
    void* source;

    work = task->workData;
    if (work->state == 0) {
        if (work->archive == NULL || !H_Cdvd_IsFileLoaded(work->archive)) {
            return KWLNTASK_CONTINUE;
        }
        for (i = 0; i < (s32)ARRAY_SIZE(resourceSlots); i++) {
            source = H_Cdvd_ArchiveGetFile(work->archive, i, &size);
            work->maestroResources[resourceSlots[i]] = func_00112420(source);
        }
        work->state = 1;
    }
    if (work->state == 1) {
        for (i = 0; i < (s32)ARRAY_SIZE(work->maestroResources); i++) {
            if (work->maestroResources[i] != NULL &&
                !H_Maestro_00111f30(work->maestroResources[i])) {
                return KWLNTASK_CONTINUE;
            }
        }
        work->state = 3;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_0011aae0 NONMATCHING
void h_campDestroySpriteSetupTask(KwlnTask* task)
{
    s32 i;
    CampSpriteSetupWork* work;

    work = task->workData;
    for (i = 0; i < 14; i++) {
        if (work->maestroResources[i] != NULL) {
            func_001124b0(work->maestroResources[i]);
            work->maestroResources[i] = NULL;
        }
    }
    if (work->archive != NULL) {
        H_Cdvd_Destroy(work->archive);
    }
    if (work->cleanupOwner != NULL) {
        RwFree(work->cleanupOwner);
    }
    sCampSpriteSetupOwner = NULL;
    for (i = 0; i < 14; i++) {
        sCampSpriteResources[i] = NULL;
    }
    RwFree(work);
    sCampSpriteSetupTask = NULL;
}

// FUN_0011abd0 NONMATCHING
u32 h_campUpdatePagedCursor(u32 pageSize, u32 entryCount, s32* firstEntry, s32* selectedEntry)
{
    s32 lastEntry;

    if (entryCount == 0 || pageSize == 0) {
        return 0;
    }
    lastEntry = (s32)entryCount - 1;
    if (*selectedEntry < 0) {
        *selectedEntry = 0;
    } else if (*selectedEntry > lastEntry) {
        *selectedEntry = lastEntry;
    }
    if (*firstEntry > *selectedEntry) {
        *firstEntry = *selectedEntry;
    }
    if (*selectedEntry >= *firstEntry + (s32)pageSize) {
        *firstEntry = *selectedEntry - (s32)pageSize + 1;
    }
    if (*firstEntry < 0) {
        *firstEntry = 0;
    }
    return 1;
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
            if (work->menuMode == 0) {
                h_campDrawRootMenuEntries(work, 100.0f);
                work->state = 4;
            } else {
                h_campDrawRootMenuEntriesAlternate(work, 100.0f);
                work->state = 5;
            }
        }
        break;
    case 4:
        h_campUpdateRootMenuEntryEffect(work, 100.0f);
        break;
    case 5:
        h_campUpdateRootMenuEntryTransition(work, 110.0f);
        break;
    case 6:
        h_campUpdateRootMenuEntryFadeOut(work, 100.0f);
        break;
    case 7:
        h_campUpdateRootMenuEntryFinish(work, 100.0f);
        break;
    }
    h_campUpdateRootMenuSelectionEffect(work, 100.0f);
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

// FUN_0011bba0
void h_campNoopRootDrawCallback(void)
{
}

// FUN_0011bbb0 NONMATCHING
void h_campDrawRootUi(CampRootDrawWork* work, f32 alpha)
{
    CampUiRecord* records;
    s32 i;

    /* The root UI is a 7-entry record bank followed by calendar and money records. */
    if (work->menuTask == NULL || work->menuTask->workData == NULL) {
        return;
    }
    records = work->menuTask->workData;
    for (i = 0; i < 7; i++) {
        if (records[i].color != 0) {
            records[i].color = (records[i].color & 0x00FFFFFF) |
                               ((u32)(alpha * 255.0f) << 24);
        }
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

// FUN_0011c550 NONMATCHING
void h_campDrawRootMenuEntries(CampRootDrawWork* work, f32 alpha)
{
    struct {
        f32 endX;
        f32 endY;
        f32 startX;
        f32 startY;
    } pos;
    f32 temp;
    s32 i;

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
    temp = 57.0f + 19.0f * (f32)work->selectedEntry;
    pos.startY = temp;
    pos.endX = 213.0f;
    pos.endY = temp;
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
    if (work->frame < 0x15) {
        work->frame++;
    }
    h_campDrawMenuEntryPass(work, alpha, 3);
}

// FUN_0011cc80 NONMATCHING
void h_campDrawRootMenuEntriesAlternate(CampRootDrawWork* work, f32 alpha)
{
    h_campDrawMenuEntryPass(work, alpha, 1);
}

// FUN_0011cfb0 NONMATCHING
void h_campUpdateRootMenuEntryTransition(CampRootDrawWork* work, f32 alpha)
{
    if (work->frame < 0x16) {
        work->frame++;
    }
    h_campDrawMenuEntryPass(work, alpha, 4);
}

// FUN_0011d3a0 NONMATCHING
void h_campDrawRootMenuEntriesClosing(CampRootDrawWork* work, f32 alpha)
{
    h_campDrawMenuEntryPass(work, alpha, 2);
}

// FUN_0011d6d0 NONMATCHING
void h_campUpdateRootMenuEntryFadeOut(CampRootDrawWork* work, f32 alpha)
{
    if (work->frame > 0) {
        work->frame--;
    }
    h_campDrawMenuEntryPass(work, alpha, 5);
}

// FUN_0011da80 NONMATCHING
void h_campDrawRootMenuEntriesFadeOut(CampRootDrawWork* work, f32 alpha)
{
    h_campDrawMenuEntryPass(work, alpha, 2);
}

// FUN_0011ddb0 NONMATCHING
void h_campUpdateRootMenuEntryFinish(CampRootDrawWork* work, f32 alpha)
{
    if (work->frame < 14) {
        work->frame++;
    }
    h_campDrawMenuEntryPass(work, alpha, 6);
}

// FUN_0011dfe0 NONMATCHING
void h_campUpdateRootMenuSelectionEffect(CampRootDrawWork* work, f32 alpha)
{
    if (work->selectedEntry >= 0) {
        work->transitionDuration = (u32)(alpha * 2.5f + 54.0f);
    }
}

// FUN_0011e370
u32 h_campGetRootMenuTransitionComplete(KwlnTask* task)
{
    CampMenuWork* work;

    work = task->workData;
    return work->transitionComplete;
}

// FUN_0011e380 NONMATCHING
u32 h_campRequestRootMenuTransition(KwlnTask* task, u32 command)
{
    CampMenuWork* work;

    work = task->workData;
    if (work->state != 0) {
        return 0;
    }
    work->transitionComplete = 0;
    work->command = command;
    switch (command) {
    case 0:
    case 1:
        work->state = 1;
        break;
    case 2:
        work->state = 3;
        break;
    case 3:
        work->state = 5;
        break;
    case 4:
        work->state = 7;
        break;
    case 5:
        work->state = 9;
        break;
    default:
        work->transitionComplete = 1;
        break;
    }
    return 1;
}

// FUN_0011ea20 NONMATCHING
void* h_campUpdateMenuTask(KwlnTask* task)
{
    CampMenuWork* work;

    work = task->workData;
    switch (work->state) {
    case 0:
        break;
    case 1:
        h_campUpdateMainMenuAnimation(task);
        break;
    case 3:
        h_campUpdateStatusMainAnimation(task);
        break;
    case 5:
        h_campUpdateItemMainAnimation(task);
        break;
    case 7:
        h_campUpdateSocialMainAnimation(task);
        break;
    case 9:
        h_campUpdateSkillMainAnimation(task);
        break;
    case 11:
        h_campUpdateEquipMainAnimation(task);
        break;
    case 13:
        h_campUpdatePersonaMainAnimation(task);
        break;
    case 15:
        h_campUpdateSystemMainAnimation(task);
        break;
    }
    if (work->animationState == 999) {
        work->state = 0;
    }
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

// FUN_0011f260 NONMATCHING
void h_campUpdateMainMenuAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sMainMenuAnimation, 0, 1, 0x18);
}

// FUN_0011f400 NONMATCHING
void h_campUpdateStatusMainAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sStatusMainAnimation, 1, 1, 0x18);
}

// FUN_0011f5c0 NONMATCHING
void h_campUpdateStatusDetailAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sStatusDetailAnimation, 1, 1, 0x18);
}

// FUN_0011f760 NONMATCHING
void h_campUpdateStatusPersonaAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sStatusPersonaAnimation, 1, 1, 0x18);
}

// FUN_0011f900 NONMATCHING
void h_campUpdateStatusExitTransition(KwlnTask* task)
{
    CampMenuWork* work;
    f32 progress;
    s32 count;
    s32 i;
    s32 found;

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
        count = work->timer - 1;
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
        for (i = 1; i < 10; i++) {
            if (*(KwlnTask**)((u8*)work + 0x14 + i * 4) != NULL) {
                H_Maestro_SetAlphaMult(
                    *(KwlnTask**)((u8*)work + 0x14 + i * 4), 1.0f);
            }
        }
        H_Maestro_SetAlphaMult(work->childTasks[0], progress);
    case 999:
        return;
    }
}

// FUN_0011faf0 NONMATCHING
void h_campUpdateStatusFadeTransition(KwlnTask* task)
{
    CampMenuWork* work;
    KwlnTask* child;
    f32 progress;
    s32 count;
    s32 i;

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
        progress = (20.0f - (f32)count) / 20.0f;
        for (i = 1; i < 10; i++) {
            child = *(KwlnTask**)((u8*)work + 0x14 + i * 4);
            if (child != NULL) {
                H_Maestro_SetAlphaMult(child, 1.0f - progress);
            }
        }
        H_Maestro_SetAlphaMult(work->childTasks[0], progress);
    case 999:
        return;
    }
}


// FUN_0011fca0 NONMATCHING
void h_campUpdateItemMainAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sItemMainAnimation, 1, 1, 0x18);
}

// FUN_0011fe50 NONMATCHING
void h_campUpdateItemDetailAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sItemDetailAnimation, 2, 1, 0x18);
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
        return;
    }
}

// FUN_00120150 NONMATCHING
void h_campUpdateItemThirdAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sItemThirdAnimation, 1, 1, 0x18);
}

// FUN_001202b0 NONMATCHING
void h_campUpdateItemEighthAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sItemEighthAnimation, 1, 1, 0x18);
}

// FUN_00120410 NONMATCHING
void h_campUpdateItemSixthAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sItemSixthAnimation, 1, 1, 0x18);
}

// FUN_00120570 NONMATCHING
void h_campUpdateItemFifthAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sItemFifthAnimation, 1, 1, 0x18);
}

// FUN_001206d0 NONMATCHING
void h_campUpdateItemFourthAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sItemFourthAnimation, 1, 1, 0x18);
}

// FUN_00120830 NONMATCHING
void h_campUpdateItemSeventhAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sItemSeventhAnimation, 1, 1, 0x18);
}

// FUN_00120990 NONMATCHING
void h_campUpdateSocialMainAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sSocialMainAnimation, 1, 1, 0x18);
}

// FUN_00120b10 NONMATCHING
void h_campUpdateSocialDetailAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sSocialDetailAnimation, 2, 1, 0x18);
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

// FUN_00120e20 NONMATCHING
void h_campUpdateSkillMainAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sSkillMainAnimation, 1, 1, 0x18);
}

// FUN_00120fd0 NONMATCHING
void h_campUpdateEquipMainAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sEquipMainAnimation, 1, 1, 0x18);
}

// FUN_00121180 NONMATCHING
void h_campUpdateSkillDetailAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sSkillDetailAnimation, 2, 1, 0x18);
}

// FUN_00121300 NONMATCHING
void h_campUpdateEquipDetailAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sEquipDetailAnimation, 2, 1, 0x18);
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

// FUN_00121780 NONMATCHING
void h_campUpdatePersonaMainAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sPersonaMainAnimation, 1, 1, 0x18);
}

// FUN_00121930 NONMATCHING
void h_campUpdatePersonaDetailAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sPersonaDetailAnimation, 2, 1, 0x18);
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

// FUN_00121c30 NONMATCHING
void h_campUpdateSystemMainAnimation(KwlnTask* task)
{
    h_campUpdateAnimationLifecycle(task, sSystemMainAnimation, 1, 1, 0x18);
}

// FUN_00121de0 NONMATCHING
u32 h_campRequestMenuTransition(KwlnTask* task, u32 command)
{
    CampMenuWork* work;

    work = task->workData;
    work->command = command;
    switch (command) {
    case 0:
    case 1:
        work->state = 1;
        break;
    case 2:
        work->state = 3;
        break;
    case 3:
        work->state = 5;
        break;
    case 4:
        work->state = 7;
        break;
    case 5:
        work->state = 9;
        break;
    case 6:
        work->state = 11;
        break;
    case 7:
        work->state = 13;
        break;
    case 8:
        work->state = 15;
        break;
    default:
        return 0;
    }
    return 1;
}

// FUN_00121ff0 NONMATCHING
void* h_campUpdatePanelTransition(KwlnTask* task)
{
    CampPanelTransitionWork* work;
    s32 alpha;

    work = task->workData;
    switch (work->state) {
    case 0:
        if (work->transitionComplete != 0) {
            work->frame = 0;
            work->state = 2;
        }
        break;
    case 2:
        work->frame++;
        if (work->frame >= 0x15) {
            work->frame = 0;
            work->state = 0;
        }
        break;
    case 6:
        work->frame++;
        alpha = 255 - (work->frame * 255 / 8);
        if (alpha < 0) {
            alpha = 0;
            work->transitionComplete = 0;
            work->state = 0;
        }
        break;
    case 10:
        work->frame++;
        if (work->frame >= 0x14) {
            work->transitionComplete = 1;
            work->state = 0;
        }
        break;
    default:
        break;
    }
    return KWLNTASK_CONTINUE;
}
