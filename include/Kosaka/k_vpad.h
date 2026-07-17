#ifndef K_VPAD_H
#define K_VPAD_H

#include "Utils.h"
#include "rw/rwplcore.h"

typedef struct KwlnTask KwlnTask;
typedef struct Model Model;

// 144 bytes
typedef struct VPadWork
{
    u32 state;                // 0x00
    u8 unkData1[0x4c];        // 0x04
    KwlnTask* rotateTask;     // 0x50
    KwlnTask* collisCtlTask;  // 0x54
    Model* mdl;               // 0x58
    u32 controlMode;          // 0x5c
    u32 controlFlags;         // 0x60
    u8 unkData2[0x08];        // 0x64
    u32 animState;            // 0x6c
    s16 animId;               // 0x70
    u16 unk_72;
    f32 cameraHeading;        // 0x74
    u32 moveTimer;            // 0x78
    u32 animDebounce;         // 0x7c
    u32 stationaryFrames;     // 0x80
    KwlnTask* cameraTask;     // 0x84
    KwlnTask* eventTask;      // 0x88
    u8 unkData3[0x04];        // 0x8c
} VPadWork;

typedef enum
{
    PCROTATE_STATE_IDLE,
    PCROTATE_STATE_ROTATING
} PcRotateState;

// 96 bytes
typedef struct PcRotateWork
{
    RwMatrix mat;            // 0x00
    u32 state;               // 0x40. See enum 'PcRotateState'
    KwlnTask* collisCtlTask; // 0x44
    Model* mdl;              // 0x48
    u8 unkData[0x08];
    f32 angle;               // 0x54
    s32 steps;               // 0x58
    s32 maxSteps;            // 0x5c
} PcRotateWork;

KwlnTask* K_VPad_CreateTask(KwlnTask* parent, KwlnTask* collisCtlTask, Model* mdl);

KwlnTask* K_VPad_CreateRotateTask(KwlnTask* parent, KwlnTask* collisCtlTask, Model* mdl);
u32 K_VPad_IsRotating(KwlnTask* rotatePcTask);

#endif