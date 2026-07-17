#ifndef K_DATA_H
#define K_DATA_H

#include "Utils.h"

#define FLDSCR_DIED_IN_TARTAROS 1

typedef struct Model Model;

// 16 bytes
typedef struct FldDungeonFloorData
{
    u16 majorId;        // 0x00
    u16 minorId;        // 0x02
    s16 unk_04;         // 0x04
    u8 unk_06;          // 0x06
    u8 unk_07;          // 0x07
    u32 fieldFlags;     // 0x08
    u8 unk_0c;          // 0x0c
    u8 effectId;        // 0x0d
    u8 unk_0e;          // 0x0e
    u8 unk_0f;          // 0x0f
} FldDungeonFloorData;

extern void* gFldScrMemory;
extern u32 gFldScrSize;
extern Model* gFldBaseMdl;
extern u32 gTraceCode;

extern FldDungeonFloorData gFldDngFloorsData[500];

void K_Data_LoadFldMainScript();
void K_Data_LoadDngFloorsData(u32 scenarioMode);
void K_Data_CreateFldBaseMdl();
u32 K_Data_ChkFldBaseMdlStream();

#endif