#ifndef BTLTARGET_H
#define BTLTARGET_H

#include "Utils.h"

typedef struct BtlAction BtlAction;

// 80 bytes
typedef struct BtlTarget
{
    BtlAction* targetedActions[12]; // 0x00
    s16 unk_30;                     // 0x30
    u16 targetedCount;              // 0x32
    u16 commandId;                  // 0x34. Current command in target mode (attack, skills, ...)
    u16 specificId;                 // 0x36. Id depending of the current command. Ex: if the cmd is item, then it will be the item id
    u16 unk_38;
    u16 originalSpecificId;          // 0x3a
    u8 unkData1[0x02];
    u16 unk_3e[3];                  // 0x3e
    u16 oldCommandId;               // 0x44
    u16 oldSpecificId;              // 0x46
    u16 rewardPersonaId;            // 0x48
    u8 rewardPersonaChance;         // 0x4a
    u8 unkData2[0x05];
} BtlTarget;

typedef struct BtlTargetResult
{
    s32 hpDelta;
    s32 spDelta;
    u32 statusFlags;
    u32 otherStatusFlags;
    u32 baseValue;
    u16 unk_14;
    u16 unk_16;
    u8 callbackResult;
    u8 damageType;
    u16 flags;
} BtlTargetResult;

void btlTargetInit(BtlTarget* target);
void btlTargetReset(BtlTarget* target);

#endif