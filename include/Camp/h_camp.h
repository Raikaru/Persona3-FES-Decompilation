#ifndef H_CAMP_H
#define H_CAMP_H

#include "Utils.h"

typedef struct KwlnTask KwlnTask;
typedef struct HCdvd HCdvd;

typedef struct CampSpriteSetupWork
{
    u32 state;                 // 0x00: archive extraction state
    void* maestroResources[14]; // 0x04: nodes built from camp_all.pak entries
    HCdvd* archive;            // 0x3c
    void* ownedResource;       // 0x40
    void* cleanupOwner;        // 0x44
} CampSpriteSetupWork;

typedef struct CampPersonaTextureControlWork
{
    u32 state;                 // 0x00: asynchronous archive state
    u32 resourceId;            // 0x04: persona texture id
    HCdvd* cdvd;               // 0x08
    void* archive;             // 0x0c
    void* parsedTexture;       // 0x10
    char path[256];            // 0x14
} CampPersonaTextureControlWork;

typedef struct CampRootDrawWork
{
    u32 state;                 // 0x00: draw transition state
    s32 frame;                 // 0x04
    u32 menuMode;              // 0x08
    s32 selectedCommand;       // 0x0c
    s32 selectedEntry;         // 0x10
    u32 transitionKind;        // 0x14
    u32 flags;                 // 0x18
    u32 timer;                 // 0x1c
    u32 transitionDuration;    // 0x20
    KwlnTask* menuTask;        // 0x24
    KwlnTask* drawChild;       // 0x28
} CampRootDrawWork;

typedef struct CampMenuWork
{
    u32 state;                 // 0x00: menu dispatcher state
    u32 animationState;        // 0x04: animation callback substate
    u32 command;               // 0x08
    u32 timer;                 // 0x0c
    u32 transitionComplete;    // 0x10
    KwlnTask* childTasks[10];  // 0x14
    KwlnTask* activeAnimation; // 0x3c
    KwlnTask* retainedAnimation; // 0x40
    u8 reserved44[0x20];       // 0x44
    HCdvd* cdvdTasks[2];       // 0x64
} CampMenuWork;

typedef struct CampPanelTransitionWork
{
    u32 state;                 // 0x00
    u32 frame;                 // 0x04
    u32 timer;                 // 0x08
    u32 unused_0c;
    u32 transitionComplete;    // 0x10
    s16 drawId;                // 0x14
} CampPanelTransitionWork;

const char* h_camp_getAcademicLevelString(s16 idx);
const char* h_camp_getCharmLevelString(s16 idx);
const char* h_camp_getCourageLevelString(s16 idx);

void* h_campUpdateTask(KwlnTask* task);
void h_campDestroyTask(KwlnTask* task);
KwlnTask* h_campCreateTask(KwlnTask* parent);
void* h_campUpdateSpriteSetupTask(KwlnTask* task);
void h_campDestroySpriteSetupTask(KwlnTask* task);
u32 h_campUpdatePagedCursor(u32 pageSize, u32 entryCount, s32* firstEntry, s32* selectedEntry);
void* h_campUpdatePersonaTextureControlTask(KwlnTask* task);
void h_campDestroyPersonaTextureControlTask(KwlnTask* task);
KwlnTask* h_campCreatePersonaTextureControlTask(KwlnTask* parent, u32 resourceId);
void h_campReplacePersonaTextureControlResource(u32 resourceId);

void* h_campUpdateRootDrawTask(KwlnTask* task);
u32 h_campGetRootCommand(KwlnTask* task);
void h_campBeginRootScreenExit(KwlnTask* task);
void h_campBeginRootItemExit(KwlnTask* task);
void h_campBeginRootClose(KwlnTask* task);
void h_campDestroyRootDrawTask(KwlnTask* task);
KwlnTask* h_campCreateRootDrawTask(KwlnTask* parent, KwlnTask* menuTask, u32 menuMode);
void h_campNoopRootDrawCallback(void);
void h_campDrawRootUi(CampRootDrawWork* work, f32 alpha);

void h_campDrawRootMenuEntries(CampRootDrawWork* work, f32 alpha);
void h_campUpdateRootMenuEntryEffect(CampRootDrawWork* work, f32 alpha);
void h_campDrawRootMenuEntriesAlternate(CampRootDrawWork* work, f32 alpha);
void h_campUpdateRootMenuEntryTransition(CampRootDrawWork* work, f32 alpha);
void h_campDrawRootMenuEntriesClosing(CampRootDrawWork* work, f32 alpha);
void h_campUpdateRootMenuEntryFadeOut(CampRootDrawWork* work, f32 alpha);
void h_campDrawRootMenuEntriesFadeOut(CampRootDrawWork* work, f32 alpha);
void h_campUpdateRootMenuEntryFinish(CampRootDrawWork* work, f32 alpha);
void h_campUpdateRootMenuSelectionEffect(CampRootDrawWork* work, f32 alpha);
u32 h_campGetRootMenuTransitionComplete(KwlnTask* task);
u32 h_campRequestRootMenuTransition(KwlnTask* task, u32 command);

u32 FUN_0015B330(void* entries, void* blobPair, u32 category, u32 selectedPage);
KwlnTask* FUN_0015C460(KwlnTask* parent);
void* h_campUpdateMenuTask(KwlnTask* task);
void h_campDestroyMenuTask(KwlnTask* task);
KwlnTask* h_campCreateMenuTask(KwlnTask* parent);
void h_campUpdateMainMenuAnimation(KwlnTask* task);
void h_campUpdateStatusMainAnimation(KwlnTask* task);
void h_campUpdateStatusDetailAnimation(KwlnTask* task);
void h_campUpdateStatusPersonaAnimation(KwlnTask* task);
void h_campUpdateStatusExitTransition(KwlnTask* task);
void h_campUpdateStatusFadeTransition(KwlnTask* task);
void h_campUpdateItemMainAnimation(KwlnTask* task);
void h_campUpdateItemDetailAnimation(KwlnTask* task);
void h_campUpdateItemAnimationBlend(KwlnTask* task);
void h_campUpdateItemThirdAnimation(KwlnTask* task);
void h_campUpdateItemEighthAnimation(KwlnTask* task);
void h_campUpdateItemSixthAnimation(KwlnTask* task);
void h_campUpdateItemFifthAnimation(KwlnTask* task);
void h_campUpdateItemFourthAnimation(KwlnTask* task);
void h_campUpdateItemSeventhAnimation(KwlnTask* task);
void h_campUpdateSocialMainAnimation(KwlnTask* task);
void h_campUpdateSocialDetailAnimation(KwlnTask* task);
void h_campUpdateSocialTransition(KwlnTask* task);
void h_campUpdateSkillMainAnimation(KwlnTask* task);
void h_campUpdateEquipMainAnimation(KwlnTask* task);
void h_campUpdateSkillDetailAnimation(KwlnTask* task);
void h_campUpdateEquipDetailAnimation(KwlnTask* task);
void h_campUpdateSkillEquipBlend(KwlnTask* task);
void h_campUpdateSkillEquipExitBlend(KwlnTask* task);
void h_campUpdatePersonaMainAnimation(KwlnTask* task);
void h_campUpdatePersonaDetailAnimation(KwlnTask* task);
void h_campUpdatePersonaBlend(KwlnTask* task);
void h_campUpdateSystemMainAnimation(KwlnTask* task);
u32 h_campRequestMenuTransition(KwlnTask* task, u32 command);
void* h_campUpdatePanelTransition(KwlnTask* task);

#endif
