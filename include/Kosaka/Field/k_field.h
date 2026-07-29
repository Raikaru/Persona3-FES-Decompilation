#ifndef K_FIELD_H
#define K_FIELD_H

#include "Utils.h"

typedef struct KwlnTask KwlnTask;

typedef struct FieldDungeonCell
{
    u8 occupied;       // 0x00
    u8 placed;         // 0x01
    u8 patternId;      // 0x02
    u8 unk_03;         // 0x03
    u16 resourceId;    // 0x04
    u8 direction;      // 0x06
    u8 width;          // 0x07
    u8 height;         // 0x08
    u8 roomId;         // 0x09
    s8 elevation;      // 0x0a
    u8 connections;    // 0x0b
    u32 unk_0c;        // 0x0c
} FieldDungeonCell;

// 4636 bytes
typedef struct Field
{
    KwlnTask* rootTask;      // 0x00
    KwlnTask* cameraCtlTask; // 0x04
    KwlnTask* eventTask;     // 0x08
    KwlnTask* playerPadTask; // 0x0c
    u8 unk_10[0x2c];
    u8 dungeonStartX;       // 0x3c
    u8 dungeonStartY;       // 0x3d
    u8 dungeonTargetX;      // 0x3e
    u8 dungeonTargetY;      // 0x3f
    u8 dungeonStartDirection;  // 0x40
    u8 dungeonTargetDirection; // 0x41
    u8 dungeonMinRooms;     // 0x42
    u8 dungeonMaxRooms;     // 0x43
    u8 unk_44[4];
    FieldDungeonCell dungeonCells[16][16]; // 0x48
    u8 unk_1048[0x1d4];
} Field;

// 104 bytes. Task data for "field root" task
typedef struct FldRootWork
{
    u8 unkData1[0x04];
    u32 unk_04;         // 0x04
    u32 shouldShutdown; // 0x08
    s32 unk_0c;         // 0x0c
    u16 majorId;        // 0x10
    u16 minorId;        // 0x12
    u8 unkData2[0x54];
} FldRootWork;

void K_Field_Init();
Field* K_Field_Get(void);

void K_Field_SetShouldShutdown(KwlnTask* fldRootTask, u32 shouldShutdown);
u16 K_Field_GetMajorId(KwlnTask* fldRootTask);
u16 K_Field_GetMinorId(KwlnTask* fldRootTask);

#endif