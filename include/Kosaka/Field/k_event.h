#ifndef K_EVENT_H
#define K_EVENT_H

#include "Utils.h"
#include "rw/rwplcore.h"

typedef struct KwlnTask KwlnTask;
typedef struct ResrcModelChar ResrcModelChar;
typedef struct ResrcModelNpc ResrcModelNpc;
typedef struct FldUnit FldUnit;

typedef enum
{
    FLDEVENT_TYPE_INIT = 0,
    FLDEVENT_TYPE_IDLE = 1,
    FLDEVENT_TYPE_OBJ_INTERACT = 2,
    FLDEVENT_TYPE_FLDHIT_INTERACT = 3,
    FLDEVENT_TYPE_NPC_INTERACT = 0x15,
    FLDEVENT_TYPE_DESTROY = 0x20
} FldEventType;

// 4 bytes
typedef struct FldDrawCmd
{
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
} FldDrawCmd;

// 288 bytes
typedef struct FldEvent
{
    FldEventType eventType;         // 0x00
    u32 inputLocked;                // 0x04
    u32 interactionLocked;          // 0x08
    u32 unk_0c;                     // 0x0c
    u32 unk_10;                     // 0x10
    ResrcModelChar* heroRes;        // 0x14
    s32 unk_18;                     // 0x18
    ResrcModelNpc* interactableNpc; // 0x1c. Npc the player can currently interact with (in FOV and nearby)
    u8 unkData2[0x3c];
    KwlnTask* drawCmdTask;          // 0x5c
    KwlnTask* objScrTask;           // 0x60. Script task of the object the player is currently interacting
    u8 unkData3[0xbc];
} FldEvent;

u32 K_FldEvent_IsPosWithinFov(const RwMatrix* viewerMat, const RwV3d* targetPos, f32 fov);
u32 K_FldEvent_IsUnitWithinDistOfHero(const FldUnit* fldUnit, f32 maxDist);
u32 K_FldEvent_AreUnitsWithinDist(const FldUnit* fldUnitA, const FldUnit* fldUnitB, f32 maxDist);
u32 K_FldEvent_ArePosWithinDist(const RwV3d* posA, const RwV3d* posB, f32 maxDist);
ResrcModelNpc* K_FldEvent_FindInteractableNpc();
u32 K_FldEvent_IsUnitHero(const FldUnit* fldUnit);
u32 K_FldEvent_IsCharNearHeroBeforeBtl(u32 charId);

KwlnTask* K_FldEvent_CreateTasks(KwlnTask* fldRootTask);
void K_FldEvent_001cd650(KwlnTask* fldEventTask, u32 param_2);

#endif