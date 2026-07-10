#include "h_pad.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/h_malloc.h"
#include "Kosaka/k_assert.h"
#include "Main/g_data.h"
#include "temporary.h"

#define HPAD_PAD_STATE_FIND_CTP1 2
#define HPAD_PAD_STATE_STABLE    6

typedef struct HPadRwAllocation
{
    u32 size;
    u32 alignment;
    u32 serial;
    u32 hint;
} HPadRwAllocation;

extern s32 scePadGetState(s32 port, s32 slot);
extern s32 scePadSetMainMode(s32 port, s32 slot, s32 mode, s32 lock);
extern s32 scePadInfoAct(s32 port, s32 slot, s32 actuator, s32 command);
extern s32 scePadSetActAlign(s32 port, s32 slot, u8* align);
extern s32 scePadGetReqState(s32 port, s32 slot);
extern s32 scePadRead(s32 port, s32 slot, u8* data);
extern s32 scePadSetActDirect(s32 port, s32 slot, u8* data);

HPad gWorkPads[HPAD_PORT_MAX]; // 007e09b0
HPad gPads[HPAD_PORT_MAX];     // 007e0940

static u_long128 sAddrPort1[scePadDmaBufferMax] __attribute__((aligned(64))); // 007e0840
static u_long128 sAddrPort2[scePadDmaBufferMax] __attribute__((aligned(64))); // 007e0740
static u8 sRDataPort2[32]; // 007e0720
static u8 sRDataPort1[32]; // 007e0700

static s16 sRumbleState;
static u16 sRumbleIntensity;
static s16 sRumblePhase;
static s16 sRumbleOffFrames;
static s16 sRumbleOnFrames;
static s16 sRumbleCadence;
static s16 sRumbleDuration;

static s32 sRwAllocatedBytes;
static u32 sRwAllocationCount;
static u32 sRwCallocCount;
static u32 sRwReallocCount;
static u32 sRwAllocationHint;
static RwMemoryFunctions sRwMemoryFunctions;

// FUN_00103000 NONMATCHING
void H_Pad_Init(void)
{
    s32 i;
    HPad* workPads;

    memset(&gWorkPads[HPAD_PORT_1], 0, sizeof(HPad));
    memset(&gWorkPads[HPAD_PORT_2], 0, sizeof(HPad));
    memset(&gPads[HPAD_PORT_1], 0, sizeof(HPad));
    memset(&gPads[HPAD_PORT_2], 0, sizeof(HPad));

    scePadInit(0);
    scePadPortOpen(HPAD_PORT_1, 0, sAddrPort1);
    scePadPortOpen(HPAD_PORT_2, 0, sAddrPort2);

    workPads = gWorkPads;
    for (i = 0; i < HPAD_PORT_MAX; i++)
    {
        workPads[i].port = i;
        workPads[i].mainMode = 0;
        workPads[i].state = HPAD_STATE_INITIALIZING;
        workPads[i].slot = 0;
        workPads[i].requestedMainMode = 3;
    }
}

// FUN_00103110 NONMATCHING
void H_Pad_Poll(HPad* pad)
{
    s32 padState;
    s32 requestState;
    u8 actuatorData[2];
    u8 hasDigitalInput;
    u8 hasAnalogSticks;

    sRDataPort1[0] = 0xFF;
    padState = scePadGetState(pad->port, pad->slot);

    switch (pad->state)
    {
    case HPAD_STATE_INITIALIZING:
        if (padState == HPAD_PAD_STATE_FIND_CTP1 || padState == HPAD_PAD_STATE_STABLE)
        {
            pad->appliedActuator0 = 0xFFFF;
            pad->appliedActuator1 = 0xFFFF;
            pad->mainMode = pad->requestedMainMode;

            switch (pad->mainMode)
            {
            case 0:
                pad->state = HPAD_STATE_CONFIGURING_ACTUATORS;
                break;

            case 1:
                if (padState == HPAD_PAD_STATE_STABLE)
                {
                    if (scePadSetMainMode(pad->port, pad->slot, 0, 0) == 1)
                    {
                        pad->state = HPAD_STATE_MODE_REQUESTED;
                    }
                }
                else
                {
                    pad->state = HPAD_STATE_CONFIGURING_ACTUATORS;
                }
                break;

            case 2:
                if (scePadSetMainMode(pad->port, pad->slot, 0, 0) == 1)
                {
                    pad->state = HPAD_STATE_WAITING_FOR_MODE;
                }
                break;

            case 3:
                if (scePadSetMainMode(pad->port, pad->slot, 1, 0) == 1)
                {
                    pad->state = HPAD_STATE_MODE_REQUESTED;
                }
                break;
            }
        }
        break;

    case HPAD_STATE_WAITING_FOR_MODE:
        if (padState == HPAD_PAD_STATE_STABLE)
        {
            if (scePadSetMainMode(pad->port, pad->slot, 0, 0) == 1)
            {
                pad->state = HPAD_STATE_WAITING_FOR_MODE;
            }
        }
        else
        {
            pad->state = HPAD_STATE_CONFIGURING_ACTUATORS;
        }
        break;

    case HPAD_STATE_CONFIGURING_ACTUATORS:
        if (scePadInfoAct(pad->port, pad->slot, -1, 0) == 0)
        {
            pad->state = HPAD_STATE_READY;
        }
        else if (scePadSetActAlign(pad->port, pad->slot, sRDataPort1) != 0)
        {
            pad->state = HPAD_STATE_WAITING_FOR_ACTUATORS;
        }
        break;

    case HPAD_STATE_WAITING_FOR_ACTUATORS:
        requestState = scePadGetReqState(pad->port, pad->slot);
        if (requestState == 0)
        {
            pad->state = HPAD_STATE_READY;
        }
        else if (requestState == 1)
        {
            pad->state = HPAD_STATE_CONFIGURING_ACTUATORS;
        }
        break;

    case HPAD_STATE_READY:
        if (padState == HPAD_PAD_STATE_FIND_CTP1 || padState == HPAD_PAD_STATE_STABLE)
        {
            if (pad->mainMode != pad->requestedMainMode)
            {
                pad->state = HPAD_STATE_INITIALIZING;
            }
            else
            {
                scePadRead(pad->port, pad->slot, sRDataPort1);
            }
        }
        break;
    }

    hasDigitalInput = false;
    hasAnalogSticks = false;
    if (sRDataPort1[0] == 0)
    {
        if (sRDataPort1[1] == 'A')
        {
            hasDigitalInput = true;
        }
        else if (sRDataPort1[1] == 's' || sRDataPort1[1] == 'y')
        {
            hasDigitalInput = true;
            hasAnalogSticks = true;
        }
    }

    pad->btn[0].released = pad->btn[0].pressed;
    pad->virtualPreviousPressed = pad->btn[1].justPressed;
    if (hasDigitalInput != false)
    {
        pad->btn[0].pressed = (u16)~((sRDataPort1[2] << 8) | sRDataPort1[3]);
    }
    else
    {
        pad->btn[0].pressed = 0;
        pad->btn[0].released = 0;
    }

    if (hasAnalogSticks != false)
    {
        pad->rstickX = sRDataPort1[4];
        pad->rstickY = sRDataPort1[5];
        pad->lstickX = sRDataPort1[6];
        pad->lstickY = sRDataPort1[7];
    }
    else
    {
        pad->rstickX = 128;
        pad->rstickY = 128;
        pad->lstickX = 128;
        pad->lstickY = 128;
        pad->btn[1].justPressed = 0;
        pad->virtualPreviousPressed = 0;
    }

    if (pad->actuator0 != pad->appliedActuator0 || pad->actuator1 != pad->appliedActuator1)
    {
        pad->appliedActuator0 = pad->actuator0;
        pad->appliedActuator1 = pad->actuator1;
        actuatorData[0] = (u8)pad->actuator0;
        actuatorData[1] = (u8)pad->actuator1;
        scePadSetActDirect(pad->port, pad->slot, actuatorData);
    }
}

// FUN_00103580 NONMATCHING
void H_Pad_Update(void)
{
    HPadPort port;
    HPad* secondPad;

    for (port = HPAD_PORT_1; port < HPAD_PORT_MAX; port++)
    {
        H_Pad_Poll(&gWorkPads[port]);
        H_Pad_UpdateButtonStates(port);
    }

    secondPad = &gWorkPads[HPAD_PORT_2];
    secondPad->btn[0].pressed = 0;
    secondPad->btn[0].justPressed = 0;
    secondPad->btn[0].justReleased = 0;
    secondPad->btn[1].justPressed = 0;
    secondPad->btn[1].released = 0;
    secondPad->lstickX = 128;
    secondPad->lstickY = 128;
    secondPad->rstickX = 128;
    secondPad->rstickY = 128;

    H_Pad_UpdateRumble();
}

// FUN_00103650 NONMATCHING
void H_Pad_UpdateButtonStates(HPadPort port)
{
    HPad* pad;
    u16 pressed;

    pad = &gWorkPads[port];
    pad->btn[1].justPressed = pad->btn[0].pressed & 0xF0;
    if ((u8)pad->lstickX >= 0xC1)
    {
        pad->btn[1].justPressed |= HPAD_BTN_RIGHT;
    }
    if ((u8)pad->lstickX < 0x40)
    {
        pad->btn[1].justPressed |= HPAD_BTN_LEFT;
    }
    if ((u8)pad->lstickY >= 0xC1)
    {
        pad->btn[1].justPressed |= HPAD_BTN_DOWN;
    }
    if ((u8)pad->lstickY < 0x40)
    {
        pad->btn[1].justPressed |= HPAD_BTN_UP;
    }

    pressed = pad->btn[0].pressed;
    pad->btn[0].justPressed = pressed & (pressed ^ pad->btn[0].released);
    pressed = pad->btn[1].justPressed;
    pad->btn[1].released = pressed & (pressed ^ pad->virtualPreviousPressed);
    pad->btn[0].justReleased = pad->btn[0].justPressed;
    pad->btn[1].justReleased = pad->btn[1].released;

    H_Pad_UpdateDirectionalButtonRepeat(port, HPAD_BTN_UP, 0);
    H_Pad_UpdateDirectionalButtonRepeat(port, HPAD_BTN_DOWN, 1);
    H_Pad_UpdateDirectionalButtonRepeat(port, HPAD_BTN_LEFT, 2);
    H_Pad_UpdateDirectionalButtonRepeat(port, HPAD_BTN_RIGHT, 3);
    H_Pad_UpdateFaceButtonRepeat(port, HPAD_BTN_L1, 4);
    H_Pad_UpdateFaceButtonRepeat(port, HPAD_BTN_L2, 5);
    H_Pad_UpdateFaceButtonRepeat(port, HPAD_BTN_R1, 6);
    H_Pad_UpdateFaceButtonRepeat(port, HPAD_BTN_R2, 7);
    H_Pad_UpdateFaceButtonRepeat(port, HPAD_BTN_CROSS, 8);
    H_Pad_UpdateFaceButtonRepeat(port, HPAD_BTN_CIRCLE, 9);
    H_Pad_UpdateFaceButtonRepeat(port, HPAD_BTN_TRIANGLE, 10);
    H_Pad_UpdateFaceButtonRepeat(port, HPAD_BTN_SQUARE, 11);
}

// FUN_001038D0 NONMATCHING
void H_Pad_UpdateFaceButtonRepeat(HPadPort port, u16 buttons, u8 repeatIndex)
{
    HPad* pad;

    pad = &gWorkPads[port];
    if ((pad->btn[0].justPressed & buttons) != 0)
    {
        pad->repeatTimer[repeatIndex] = 7;
    }
    else if ((pad->btn[0].pressed & buttons) != 0)
    {
        pad->repeatTimer[repeatIndex]--;
        if (pad->repeatTimer[repeatIndex] == 0)
        {
            pad->btn[0].justReleased |= buttons;
            pad->repeatTimer[repeatIndex] = 3;
        }
    }
}

// FUN_00103990 NONMATCHING
void H_Pad_UpdateDirectionalButtonRepeat(HPadPort port, u16 buttons, u8 repeatIndex)
{
    HPad* pad;

    pad = &gWorkPads[port];
    if ((pad->btn[0].justPressed & buttons) != 0)
    {
        pad->repeatTimer[repeatIndex] = 7;
    }
    else if ((pad->btn[0].pressed & buttons) != 0)
    {
        pad->repeatTimer[repeatIndex]--;
        if (pad->repeatTimer[repeatIndex] == 0)
        {
            pad->btn[0].justReleased |= buttons;
            pad->repeatTimer[repeatIndex] = 3;
        }
    }

    if ((pad->btn[1].released & buttons) != 0)
    {
        pad->repeatTimer[repeatIndex] = 7;
    }
    else if ((pad->btn[1].justPressed & buttons) != 0)
    {
        pad->repeatTimer[repeatIndex]--;
        if (pad->repeatTimer[repeatIndex] == 0)
        {
            pad->btn[1].justReleased |= buttons;
            pad->repeatTimer[repeatIndex] = 3;
        }
    }
}

// FUN_00103B10 NONMATCHING
void H_Pad_UpdateRumble(void)
{
    HPad* pad;

    pad = &gWorkPads[HPAD_PORT_1];
    switch (sRumbleState)
    {
    case 0:
        sRumbleDuration = 0;
        sRumbleOnFrames = 0;
        sRumbleIntensity = 0;
        pad->actuator0 = 0;
        pad->actuator1 = 0;
        sRumbleState++;
        break;

    case 1:
        pad->actuator0 = 0;
        pad->actuator1 = 0;
        break;

    case 2:
        if (sRumbleDuration == 0)
        {
            sRumbleState = HPAD_STATE_WAITING_FOR_MODE;
        }
        else
        {
            if (sRumbleCadence == 0)
            {
                if (sRumblePhase == 0)
                {
                    pad->actuator0 = sRumbleIntensity;
                    pad->actuator1 = sRumbleIntensity;
                    sRumbleCadence = sRumbleOnFrames;
                    sRumblePhase = 1;
                }
                else
                {
                    pad->actuator0 = 0;
                    pad->actuator1 = 0;
                    sRumbleCadence = sRumbleOffFrames;
                    sRumblePhase = 0;
                }
            }
            else
            {
                sRumbleCadence--;
            }
            sRumbleDuration--;
        }
        break;
    }
}

// FUN_00103C30
void H_Pad_StartRumblePattern(s16 duration, u16 intensity, s16 onFrames, s16 offFrames)
{
    if (datGetFlag(0x183) == 1)
    {
        sRumbleDuration = duration;
        sRumbleCadence = 0;
        sRumbleOnFrames = onFrames;
        sRumbleOffFrames = offFrames;
        sRumbleIntensity = intensity;
        sRumbleState = 2;
        sRumblePhase = 0;
    }
}

// FUN_00103CB0
void H_Pad_StopRumble(void)
{
    sRumbleDuration = 0;
    sRumbleCadence = 0;
    sRumbleOnFrames = 0;
    sRumbleOffFrames = 0;
    sRumbleIntensity = 0;
    sRumbleState = HPAD_STATE_WAITING_FOR_MODE;
    sRumblePhase = 0;
    gWorkPads[HPAD_PORT_1].actuator0 = 0;
    gWorkPads[HPAD_PORT_1].actuator1 = 0;
}

// FUN_00103CF0
void H_Pad_IgnoreRumbleCallback(void)
{
}

// FUN_00103D00 NONMATCHING
void H_Pad_RwFreeRaw(void* memory)
{
    HPadRwAllocation* allocation;

    if (memory == NULL)
    {
        return;
    }

    allocation = (HPadRwAllocation*)((u8*)memory - sizeof(HPadRwAllocation));
    sRwAllocatedBytes -= allocation->size;
    if (allocation->hint != 0)
    {
        memset(allocation, 0, allocation->size);
    }
    H_Free(allocation);
}

// FUN_00103DA0 NONMATCHING
void* H_Pad_RwAllocateRaw(size_t size)
{
    HPadRwAllocation* allocation;

    sRwAllocatedBytes += size;
    allocation = (HPadRwAllocation*)H_Malloc(size + sizeof(HPadRwAllocation));
    if (allocation == NULL)
    {
        if (datGetFlag(0x141A) != 0)
        {
            return NULL;
        }

        K_ASSERT(false, 671);
        return NULL;
    }

    allocation->size = size;
    sRwAllocationCount++;
    allocation->serial = sRwAllocationCount;
    allocation->hint = sRwAllocationHint;
    return allocation + 1;
}

// FUN_00103F50 NONMATCHING
void* H_Pad_RwRealloc(void* memory, RwUInt32 newSize, RwUInt32 hint)
{
    void* reallocated;
    size_t copySize;

    if (memory == NULL)
    {
        return H_Pad_RwMalloc(newSize, hint);
    }

    copySize = (size_t)(uintptr_t)*(void**)((u8*)memory - sizeof(void*));
    if (newSize < copySize)
    {
        copySize = newSize;
    }

    reallocated = H_Pad_RwMalloc(newSize, hint);
    memcpy(reallocated, memory, copySize);
    H_Pad_RwFree(memory);
    sRwReallocCount++;
    return reallocated;
}

// FUN_00104040 NONMATCHING
void* H_Pad_RwCalloc(RwUInt32 elementCount, RwUInt32 elementSize, RwUInt32 hint)
{
    RwUInt32 size;
    void* memory;

    size = elementCount * elementSize;
    memory = H_Pad_RwMalloc(size, hint);
    if (memory != NULL)
    {
        memset(memory, 0, size);
        sRwCallocCount++;
    }
    return memory;
}

// FUN_001040F0
RwMemoryFunctions* H_Pad_GetRwMemoryFunctions(void)
{
    sRwMemoryFunctions.RwMalloc = H_Pad_RwMalloc;
    sRwMemoryFunctions.RwFree = H_Pad_RwFree;
    sRwMemoryFunctions.RwRealloc = H_Pad_RwRealloc;
    sRwMemoryFunctions.RwCalloc = H_Pad_RwCalloc;
    return &sRwMemoryFunctions;
}

// FUN_00104140 NONMATCHING
void* H_Pad_RwMalloc(RwUInt32 size, RwUInt32 hint)
{
    HPadRwAllocation* allocation;
    u8* alignmentBase;
    u8* alignedMemory;

    allocation = (HPadRwAllocation*)H_Pad_RwAllocateRaw(size + 0x14);
    if (allocation == NULL)
    {
        return NULL;
    }

    allocation[-1].alignment = 16;
    alignmentBase = (u8*)allocation + 4;
    alignedMemory = alignmentBase + (16 - ((uintptr_t)alignmentBase & 0xF));
    *(void**)(alignedMemory - sizeof(void*)) = allocation;
    return alignedMemory;
}

// FUN_00104280
void H_Pad_RwFree(void* memory)
{
    s32 intrState;

    if (memory != NULL)
    {
        intrState = func_0050d3a0();
        H_Pad_RwFreeRaw(*(void**)((u8*)memory - sizeof(void*)));
        if (intrState != 0)
        {
            func_0050d3f0();
        }
    }
}
