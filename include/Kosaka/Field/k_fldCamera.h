#ifndef K_FLDCAMERA_H
#define K_FLDCAMERA_H

#include "Utils.h"
#include "rw/rwcore.h"

#define FLDCAMERA_FLAG_DRAWDEADZONE (1 << 31) // 0x80000000. Draw a cylinder that represents the current deadzone

typedef struct ResrcModelChar ResrcModelChar;
typedef struct HCdvd HCdvd;
typedef struct KwlnTask KwlnTask;

typedef enum
{
    FLDCAMERA_TYPE_0 = 0,
    FLDCAMERA_TYPE_FIXED = 1
} FldCameraType;

typedef enum
{
    FLDCAMERA_STATE_UPDATE,
    FLDCAMERA_STATE_IDLE
} FldCameraState;

// 112 bytes. Content of a '.CMR' file.
typedef struct CmrFile
{
    u8 unkData1[0x08];
    f32 fov;           // 0x08. Fov in deg
    s32 unk_0c;        // 0x0c
    RwMatrix mat;      // 0x10
    u16 type;          // 0x50. See enum 'FldCameraType'
    RwV3d posOffset;   // 0x54
    f32 xzDeadZone;    // 0x60
    f32 yDeadZone;     // 0x64
    u8 unkData2[0x08];
} CmrFile;

// 24 bytes. Work data for a transient camera rotation task.
typedef struct FldCameraRotationWork
{
    u32 state;             // 0x00
    s32 duration;          // 0x04. Number of update frames
    s32 frame;             // 0x08. Current update frame
    f32 initialRotation;   // 0x0c
    f32 angleDelta;        // 0x10. Total signed rotation
    f32 lastSine;          // 0x14
} FldCameraRotationWork;

// 208 bytes. Work data for the "field camera controller" task.
typedef struct FldCamera
{
    u32 state;                   // 0x00. See 'FldCameraState' enum
    u32 flags;                   // 0x04. See 'FLDCAMERA_FLAG_*'
    u32 type;                    // 0x08
    RwFrame* frame;              // 0x0c. Frame controlling the RwCamera
    RwFrame* parentFrame;        // 0x10
    RwV3d posOffset;             // 0x14
    f32 xzDeadZone;              // 0x20
    f32 yDeadZone;               // 0x24
    u8 unkData3[0x18];           // 0x28
    KwlnTask* deadZoneTask;      // 0x40
    KwlnTask* pointTask0;        // 0x44
    KwlnTask* pointTask1;        // 0x48
    KwlnTask* pointTask2;        // 0x4c
    void* drawState;             // 0x50
    u8 unkData4[0x0c];           // 0x54
    RwV3d deadZonePath[9];       // 0x60
    ResrcModelChar* playerResrc; // 0xcc
} FldCamera;

u32 K_FldCamera_GetType(KwlnTask* fldCameraTask);
RwV3d* K_FldCamera_GetPos(KwlnTask* fldCameraTask);
void K_FldCamera_SetPlayerResrcByTypeid(KwlnTask* fldCameraTask, u16 resTypeId);

void func_001d5c10(KwlnTask* fldCameraTask, u32 type);
void func_001d5e30(KwlnTask* fldCameraTask, f32 amount);
void* func_001d5f90(KwlnTask* cameraRotationTask);
void func_001d6240(KwlnTask* cameraRotationTask);
KwlnTask* func_001d6270(KwlnTask* parentTask, s32 duration, s32 heading);
KwlnTask* func_001d6630(KwlnTask* parentTask, s32 duration, s32 heading);
void func_001d68e0(CmrFile* cmr, KwlnTask* fldCameraTask);
void func_001d69e0(KwlnTask* fldCameraTask, const CmrFile* cmr);
HCdvd* func_001d6b10(void);
u32 func_001d6bc0(HCdvd* cmrRequest, RwMatrix* matrix, f32* fov, u32* type,
                  RwV3d* posOffset, f32* xzDeadZone, f32* yDeadZone);
void func_001d70a0(void);
void func_001d7260(void);

#endif