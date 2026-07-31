#include "Battle/battle.h"
#include "Kosaka/k_assert.h"
#pragma alias bcmStartTacticsTutorial FUN_00207e20
#pragma alias bcmStartBasicTutorial FUN_00207f10
#pragma alias bcmIsCurrentUnitTutorialPending FUN_00208010
#pragma alias bcmIsTacticsTutorialPending FUN_00208050
#pragma alias bcmCanStartBasicTutorial FUN_00208130
#pragma alias bcmStoreOwnedResource FUN_002082c0
#pragma alias bcmDestroyOwnedResource FUN_00208360
#pragma alias bcmDestroyOwnedResourceImpl FUN_002083d0
#pragma alias bcmFinishPanelTransition FUN_00208460
#pragma alias bcmInitCommandPanelEntries FUN_00208570
#pragma alias bcmIsCommandInputReady FUN_00208720
#pragma alias bcmPlayRandomPartyVoice FUN_00208790


/* Shared command work is owned by bcm_main.c. */
extern u8* gBcmWork;

extern u32 func_002d5550(void);
extern void func_002518b0(u32 mode);
extern void func_00251e10(void);
extern void bppMain0020fc40(void);
extern void* func_0030c0c0(void);
extern u32 func_00249650(u16 id);
extern u32 datGetFlag(u16 id);
extern u32 datGetScenarioMode(void);
extern u32 bpMisc001ff7f0(u32 id);
extern u32 datGetBadStatusNoDown(s16 unitId);
extern void bcmPanel00222ed0(void);
extern void FUN_0010a4e0(u32, u32, u32, u32);
extern void func_003b0170(u32 value);
extern u32 datCalcIsDead(void* calc, u32 mode);
extern u32 func_002ddc10(u32 unitId);
extern void func_002ddba0(u32 id);
extern u32 RpRandom(void);

static void bcmDestroyOwnedResourceImpl(void);
static void func_00208860(u32 unitId);

#define BCM_WORD(off) (*(u32*)((u8*)gBcmWork + (off)))
typedef struct BcmCommandEntry
{
    u32 flags;
    u32 type;
    u32 icon;
    u16 id;
} BcmCommandEntry;
























/* Removing the schedule pragma below loses FUN_00208790 (MATCH nd0 -> MISMATCH nd117) - measured W161. */

