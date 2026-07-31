#include "Main/g_data.h"
#include "Main/Game/game_support.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/Field/k_dungeon.h"

/*
 * These helpers are implemented by the game-support and memory-card modules.
 * Their retail symbols are kept here until those modules are decompiled.
 */
extern KwlnTask* func_00420340(KwlnTask* parentTask, u32 mode);
extern u32 func_004204f0(KwlnTask* task);
extern KwlnTask* func_004214e0(KwlnTask* parentTask, u32 mode);
extern void func_004215b0(KwlnTask* task, u32 state);
extern void func_00421650(KwlnTask* task);
extern u32 func_00421700(KwlnTask* task);
extern void func_00191240(void);
extern s32 func_00191260(void);
extern void func_001967d0(void);

/* Retail small-data globals used by the two game-support state machines. */
extern KwlnTask* DAT_007ce000;
extern u32 DAT_007ce00c;
extern u32 uGpffffb31c;
extern KwlnTask* uGpffffb314;

/* Runtime allocator/free-function tables. */
extern u32 D_00960184[];
extern u32 jtbl_0096017C[];

/* Task names live in the retail read-only data segment. */
extern const char D_005E42F0[];
extern const char D_005E4308[];

typedef struct GameSupportMemcardWork
{
    u32 state;
    s32 result;
    u32 timer;
    KwlnTask* task;
} GameSupportMemcardWork;

typedef struct GameSupportLoadWork
{
    u32 state;
    KwlnTask* task;
    KwlnTask* transitionTask;
} GameSupportLoadWork;














