#ifndef K_DUNGEON_H
#define K_DUNGEON_H

#include "Utils.h"

typedef struct KwlnTask KwlnTask;
typedef struct HCdvd HCdvd;
typedef struct Model Model;
typedef struct FldDungeonFloorData FldDungeonFloorData;

typedef enum
{
    FLDDUNGEON_STATE_INITIALIZE,
    FLDDUNGEON_STATE_WAIT_EFFECT,
    FLDDUNGEON_STATE_CREATE_FIELD,
    FLDDUNGEON_STATE_IDLE,              // Player is exploring a floor
    FLDDUNGEON_STATE_UNK_04,
    FLDDUNGEON_STATE_UNK_05,
    FLDDUNGEON_STATE_UNK_06,
    FLDDUNGEON_STATE_RELOAD_FIELD,
    FLDDUNGEON_STATE_WAIT_TRANSITION,
    FLDDUNGEON_STATE_STOP,              // Destroy dungeon task
} FldDungeonState;

// 64 bytes
typedef struct FldDungeon
{
    FldDungeonState state;              // 0x00
    u32 currFloor;                      // 0x04
    s32 unk_08;                         // 0x08
    u32 shouldShutdown;                 // 0x0c. Transitions to FLDDUNGEON_STATE_STOP when 1
    s32 unk_10;                         // 0x10
    HCdvd* scrCdvd;                     // 0x14
    KwlnTask* fldRootTask;              // 0x18
    KwlnTask* transitionTask;           // 0x1c
    FldDungeonFloorData* floorsData;    // 0x20. Ptr to gFldDngFloorsData
    u32 fieldFlags;                     // 0x24. Passed to the field root task
    s32 encounterResult;                // 0x28
    KwlnTask* effectEplTask;            // 0x2c
    s32 effectEplSlot;                  // 0x30
    void* scrMemory;                    // 0x34. dungeonat.bf or dungeonat_aegis.bf contents
    u32 scrSize;                        // 0x38. Size of scrMemory in bytes
    s32 unk_3c;                         // 0x3c
} FldDungeon;

extern KwlnTask* gDungeonTask;
extern Model* gDungeonTpMdl;

KwlnTask* K_FldDungeon_CreateTask(KwlnTask* parentTask, u32 floor, u32 param_3);
void K_FldDungeon_RequestShutdown();
u32 K_FldDungeon_GetCurrentFloor();
u8 K_FldDungeon_IsCurrentFloorExplorable();
FldDungeonFloorData* K_FldDungeon_GetCurrentFloorData();
void* K_FldDungeon_GetScrMemory();
u32 K_FldDungeon_GetScrSize();
HCdvd* K_FldDungeon_RequestBlockScript(u32 blockId);

#endif