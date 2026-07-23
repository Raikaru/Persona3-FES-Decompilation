#ifndef H_PAD_H
#define H_PAD_H

#include "Utils.h"
#include "rw/rwplcore.h"
#include "sce/libpad.h"

#define HPAD_BTN_L2       SCE_PADL2     // 0x01
#define HPAD_BTN_R2       SCE_PADR2     // 0x02
#define HPAD_BTN_L1       SCE_PADL1     // 0x04
#define HPAD_BTN_R1       SCE_PADR1     // 0x08
#define HPAD_BTN_TRIANGLE SCE_PADRup    // 0x10
#define HPAD_BTN_CIRCLE   SCE_PADRright // 0x20
#define HPAD_BTN_CROSS    SCE_PADRdown  // 0x40
#define HPAD_BTN_SQUARE   SCE_PADRleft  // 0x80
#define HPAD_BTN_SELECT   SCE_PADselect // 0x100
#define HPAD_BTN_L3       SCE_PADi      // 0x200
#define HPAD_BTN_R3       SCE_PADj      // 0x400
#define HPAD_BTN_START    SCE_PADstart  // 0x800
#define HPAD_BTN_UP       SCE_PADLup    // 0x1000
#define HPAD_BTN_RIGHT    SCE_PADLright // 0x2000
#define HPAD_BTN_DOWN     SCE_PADLdown  // 0x4000
#define HPAD_BTN_LEFT     SCE_PADLleft  // 0x8000

#define HPAD_CHKBTN_PRESSED(port, btns)     ((gPads[(port)].btn[0].pressed & (btns)) != 0)
#define HPAD_CHKBTN_JUSTPRESSED(port, btns) ((gPads[(port)].btn[0].justPressed & (btns)) != 0)
#define HPAD_CHKBTN_RELEASED(port, btns)    ((gPads[(port)].btn[0].released & (btns)) != 0)

typedef enum
{
    HPAD_PORT_1,
    HPAD_PORT_2,
    HPAD_PORT_MAX
} HPadPort;

typedef enum
{
    HPAD_STATE_INITIALIZING,
    HPAD_STATE_WAITING_FOR_MODE,
    HPAD_STATE_MODE_REQUESTED,
    HPAD_STATE_CONFIGURING_ACTUATORS,
    HPAD_STATE_WAITING_FOR_ACTUATORS,
    HPAD_STATE_READY
} HPadState;

// 8 bytes
typedef struct HPadButtons
{
    u16 pressed;      // 0x00: current state for btn[0]
    u16 justPressed;  // 0x02: rising-edge state for btn[0]
    u16 released;     // 0x04: previous state for btn[0]
    u16 justReleased; // 0x06: repeat event state for btn[0]
} HPadButtons;

// 54 bytes
typedef struct HPad
{
    u16 mainMode;                    // 0x00: last requested pad main mode
    u16 state;                       // 0x02: HPadState
    u16 requestedMainMode;           // 0x04
    u16 unknown06;                   // 0x06
    u16 port;                        // 0x08
    u16 slot;                        // 0x0a
    HPadButtons btn[2];              // 0x0c: raw and virtual button state
    u16 virtualPreviousPressed;      // 0x1c
    s8 lstickX;                      // 0x1e
    s8 lstickY;                      // 0x1f
    s8 rstickX;                      // 0x20
    s8 rstickY;                      // 0x21
    u8 repeatTimer[12];              // 0x22
    u16 actuator0;                   // 0x2e
    u16 actuator1;                   // 0x30
    u16 appliedActuator0;            // 0x32
    u16 appliedActuator1;            // 0x34
} HPad;

extern HPad gWorkPads[HPAD_PORT_MAX];
extern HPad gPads[HPAD_PORT_MAX];

void H_Pad_Init(void);
void H_Pad_Poll(HPad* pad);
void H_Pad_Update(void);
void H_Pad_UpdateButtonStates(HPadPort port);
void H_Pad_UpdateFaceButtonRepeat(HPadPort port, u16 buttons, s32 repeatIndex);
void H_Pad_UpdateDirectionalButtonRepeat(HPadPort port, u16 buttons, s32 repeatIndex);
void H_Pad_UpdateRumble(void);
void H_Pad_StartRumblePattern(s16 duration, u16 intensity, s16 onFrames, s16 offFrames);
void H_Pad_StopRumble(void);
void H_Pad_IgnoreRumbleCallback(void);

void H_Pad_RwFreeRaw(void* memory);
void* H_Pad_RwAllocateRaw(size_t size, RwUInt32 hint);
void* H_Pad_RwRealloc(void* memory, RwUInt32 newSize, RwUInt32 hint);
void* H_Pad_RwCalloc(RwUInt32 elementCount, RwUInt32 elementSize, RwUInt32 hint);
RwMemoryFunctions* H_Pad_GetRwMemoryFunctions(void);
void* H_Pad_RwMalloc(RwUInt32 size, RwUInt32 hint);
void H_Pad_RwFree(void* memory);

#endif