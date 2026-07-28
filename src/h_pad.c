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
extern void* func_00520728(size_t size);
extern void func_00520748(void* memory);
extern s32 printf(const char* format, ...);
extern const char D_005CEAE0[];
extern const char D_005CEAF0[];
extern const char D_005CEB10[];
extern const char D_005CEB30[];

HPad gWorkPads[HPAD_PORT_MAX]; // 007e09b0
HPad gPads[HPAD_PORT_MAX];     // 007e0940

static u_long128 sAddrPort1[scePadDmaBufferMax] __attribute__((aligned(64))); // 007e0840
static u_long128 sAddrPort2[scePadDmaBufferMax] __attribute__((aligned(64))); // 007e0740
static u8 sRDataPort2[32]; // 007e0720
static u8 sRDataPort1[32]; // 007e0700
#pragma alias gWorkPads_abs gWorkPads
extern u8 gWorkPads_abs[];
#pragma alias gPads_abs gPads
extern u8 gPads_abs[];
#pragma alias sAddrPort1_abs sAddrPort1
extern u8 sAddrPort1_abs[];
#pragma alias sAddrPort2_abs sAddrPort2
extern u8 sAddrPort2_abs[];

static s16 sRumbleState;
static union
{
    u16 h;
    u8 b;
} sRumbleIntensity;
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

/* Removing this loses FUN_00103000 (MATCH nd0 -> MISMATCH nd48) - measured W161. */
#pragma opt_loop_invariants on
// FUN_00103000 MATCHING
void H_Pad_Init(void)
{
    s32 i;

    memset(((HPad*)gWorkPads_abs) + HPAD_PORT_1, 0, sizeof(HPad));
    memset(((HPad*)gWorkPads_abs) + HPAD_PORT_2, 0, sizeof(HPad));
    memset(((HPad*)gPads_abs) + HPAD_PORT_1, 0, sizeof(HPad));
    memset(((HPad*)gPads_abs) + HPAD_PORT_2, 0, sizeof(HPad));

    scePadInit(0);
    scePadPortOpen(HPAD_PORT_1, 0, (u_long128*)sAddrPort1_abs);
    scePadPortOpen(HPAD_PORT_2, 0, (u_long128*)sAddrPort2_abs);
    i = 0;

    for (; i < HPAD_PORT_MAX; i++)
    {
        ((HPad*)gWorkPads_abs)[i].port = i;
        ((HPad*)gWorkPads_abs)[i].slot = 0;
        ((HPad*)gWorkPads_abs)[i].state = HPAD_STATE_INITIALIZING;
        ((HPad*)gWorkPads_abs)[i].mainMode = 0;
        ((HPad*)gWorkPads_abs)[i].requestedMainMode = 3;
    }
}
#pragma opt_loop_invariants off

// FUN_00103110 NONMATCHING
void H_Pad_Poll(HPad* pad)
{
    u16 mainMode;
    s32 padState;
    s32 requestState;
    s32 port;
    s32 slot;
    u8 actuatorData[2];
    u8 hasDigitalInput;
    u8 hasAnalogSticks;
    u16 actuator0;
    u16 actuator1;
    sRDataPort1[0] = 0xFF;
    port = pad->port;
    slot = pad->slot;
    padState = scePadGetState(port, slot);

    switch (pad->state)
    {
    case HPAD_STATE_INITIALIZING:
        if (padState == HPAD_PAD_STATE_FIND_CTP1 || padState == HPAD_PAD_STATE_STABLE)
        {
            pad->appliedActuator0 = 0xFFFF;
            pad->appliedActuator1 = 0xFFFF;
            mainMode = pad->requestedMainMode;
            pad->mainMode = mainMode;
            switch (mainMode)

            {
            case 0:
                pad->state = HPAD_STATE_CONFIGURING_ACTUATORS;
                break;

            case 1:
                if (padState == HPAD_PAD_STATE_STABLE)
                {
                    if (scePadSetMainMode(port, slot, 0, 0) == 1)
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
                if (scePadSetMainMode(port, slot, 0, 0) == 1)
                {
                    pad->state = HPAD_STATE_WAITING_FOR_MODE;
                }
                break;

            case 3:
                if (scePadSetMainMode(port, slot, 1, 0) == 1)
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
            if (scePadSetMainMode(port, slot, 0, 0) == 1)
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
        if (scePadInfoAct(port, slot, -1, 0) == 0)
        {
            pad->state = HPAD_STATE_READY;
        }
        else if (scePadSetActAlign(port, slot, sRDataPort1) != 0)
        {
            pad->state = HPAD_STATE_WAITING_FOR_ACTUATORS;
        }
        break;

    case HPAD_STATE_WAITING_FOR_ACTUATORS:
        requestState = scePadGetReqState(port, slot);
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
                scePadRead(port, slot, sRDataPort1);
            }
        }
        break;
    }
    actuator0 = pad->actuator0;
    actuator1 = pad->actuator1;
    if (actuator0 != pad->appliedActuator0 || actuator1 != pad->appliedActuator1)
    {
        pad->appliedActuator0 = actuator0;
        pad->appliedActuator1 = actuator1;
        actuatorData[0] = (u8)actuator0;
        actuatorData[1] = (u8)actuator1;
        scePadSetActDirect(port, slot, actuatorData);
    }
 
    hasDigitalInput = false;
    hasAnalogSticks = false;
    if (sRDataPort1[0] == 0)
    {
        switch (sRDataPort1[1])
        {
        case 'A':
            hasDigitalInput = true;
            break;

        case 's':
        case 'y':
            hasDigitalInput = true;
            hasAnalogSticks = true;
            break;
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

}

// FUN_00103580
void H_Pad_Update(void)
{
    HPadPort port;

    for (port = HPAD_PORT_1; port < HPAD_PORT_MAX; port++)
    {
        H_Pad_Poll(&gWorkPads[port]);
        H_Pad_UpdateButtonStates(port);
    }

    gWorkPads[HPAD_PORT_2].btn[0].pressed = 0;
    gWorkPads[HPAD_PORT_2].btn[0].justPressed = 0;
    gWorkPads[HPAD_PORT_2].btn[0].justReleased = 0;
    gWorkPads[HPAD_PORT_2].btn[1].justPressed = 0;
    gWorkPads[HPAD_PORT_2].btn[1].released = 0;
    *(u8*)&gWorkPads[HPAD_PORT_2].lstickX = 0x80;
    *(u8*)&gWorkPads[HPAD_PORT_2].lstickY = 0x80;
    *(u8*)&gWorkPads[HPAD_PORT_2].rstickX = 0x80;
    *(u8*)&gWorkPads[HPAD_PORT_2].rstickY = 0x80;
    H_Pad_UpdateRumble();
}

// FUN_00103650
void H_Pad_UpdateButtonStates(HPadPort port)
{

    gWorkPads[port].btn[1].justPressed = gWorkPads[port].btn[0].pressed & 0xF0;
    if ((u8)gWorkPads[port].lstickX > 0xC0)
    {
        gWorkPads[port].btn[1].justPressed |= HPAD_BTN_RIGHT;
    }
    if ((u8)gWorkPads[port].lstickX < 0x40)
    {
        gWorkPads[port].btn[1].justPressed |= HPAD_BTN_LEFT;
    }
    if ((u8)gWorkPads[port].lstickY > 0xC0)
    {
        gWorkPads[port].btn[1].justPressed |= HPAD_BTN_DOWN;
    }
    if ((u8)gWorkPads[port].lstickY < 0x40)
    {
        gWorkPads[port].btn[1].justPressed |= HPAD_BTN_UP;
    }

    gWorkPads[port].btn[0].justPressed =
        gWorkPads[port].btn[0].pressed &
        (gWorkPads[port].btn[0].pressed ^ gWorkPads[port].btn[0].released);
    gWorkPads[port].btn[1].released =
        gWorkPads[port].btn[1].justPressed &
        (gWorkPads[port].btn[1].justPressed ^ gWorkPads[port].virtualPreviousPressed);
    gWorkPads[port].btn[0].justReleased = gWorkPads[port].btn[0].justPressed;
    gWorkPads[port].btn[1].justReleased = gWorkPads[port].btn[1].released;

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

// FUN_001038D0
void H_Pad_UpdateFaceButtonRepeat(HPadPort port, u16 buttons, s32 repeatIndex)
{
    if ((gWorkPads[port].btn[0].justPressed & buttons) != 0)
    {
        gWorkPads[port].repeatTimer[repeatIndex] = 7;
    }
    else if ((gWorkPads[port].btn[0].pressed & buttons) != 0)
    {
        gWorkPads[port].repeatTimer[repeatIndex]--;
        if (gWorkPads[port].repeatTimer[repeatIndex] == 0)
        {
            gWorkPads[port].btn[0].justReleased |= buttons;
            gWorkPads[port].repeatTimer[repeatIndex] = 3;
        }
    }
}

// FUN_00103990
void H_Pad_UpdateDirectionalButtonRepeat(HPadPort port, u16 buttons, s32 repeatIndex)
{
    if ((gWorkPads[port].btn[0].justPressed & buttons) != 0)
    {
        gWorkPads[port].repeatTimer[repeatIndex] = 7;
    }
    else if ((gWorkPads[port].btn[0].pressed & buttons) != 0)
    {
        gWorkPads[port].repeatTimer[repeatIndex]--;
        if (gWorkPads[port].repeatTimer[repeatIndex] == 0)
        {
            gWorkPads[port].btn[0].justReleased |= buttons;
            gWorkPads[port].repeatTimer[repeatIndex] = 3;
        }
    }

    if ((gWorkPads[port].btn[1].released & buttons) != 0)
    {
        gWorkPads[port].repeatTimer[repeatIndex] = 7;
    }
    else if ((gWorkPads[port].btn[1].justPressed & buttons) != 0)
    {
        gWorkPads[port].repeatTimer[repeatIndex]--;
        if (gWorkPads[port].repeatTimer[repeatIndex] == 0)
        {
            gWorkPads[port].btn[1].justReleased |= buttons;
            gWorkPads[port].repeatTimer[repeatIndex] = 3;
        }
    }
}

// FUN_00103B10 NONMATCHING
void H_Pad_UpdateRumble(void)
{
    switch (sRumbleState)
    {
    case 0:
        sRumbleDuration = 0;
        sRumbleOnFrames = 0;
        sRumbleIntensity.h = 0;
        ((HPad*)gWorkPads_abs)[HPAD_PORT_1].actuator0 = 0;
        ((HPad*)gWorkPads_abs)[HPAD_PORT_1].actuator1 = 0;
        sRumbleState++;
        break;

    case 1:
        ((HPad*)gWorkPads_abs)[HPAD_PORT_1].actuator0 = 0;
        ((HPad*)gWorkPads_abs)[HPAD_PORT_1].actuator1 = 0;
        break;

    case 2:
        if (sRumbleDuration == 0)
        {
            sRumbleState = HPAD_STATE_WAITING_FOR_MODE;
            break;
        }
        if (sRumbleCadence != 0)
        {
            goto decrement_cadence;
        }
        if (sRumblePhase != 0)
        {
            goto rumble_off;
        }
        {
            s32 intensity;
            u8 intensityByte;
            intensityByte = sRumbleIntensity.b;
            intensity = intensityByte;
            ((HPad*)gWorkPads_abs)[HPAD_PORT_1].actuator0 = intensity;
            ((HPad*)gWorkPads_abs)[HPAD_PORT_1].actuator1 = intensity;
            sRumbleCadence = sRumbleOnFrames;
            sRumblePhase = 1;
        }
        goto rumble_done;
rumble_off:
        ((HPad*)gWorkPads_abs)[HPAD_PORT_1].actuator0 = 0;
        ((HPad*)gWorkPads_abs)[HPAD_PORT_1].actuator1 = 0;
        sRumbleCadence = sRumbleOffFrames;
        sRumblePhase = 0;
        goto rumble_done;
decrement_cadence:
        sRumbleCadence--;
rumble_done:
        sRumbleDuration--;
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
        sRumbleIntensity.h = intensity;
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
    sRumbleIntensity.h = 0;
    sRumbleState = HPAD_STATE_WAITING_FOR_MODE;
    sRumblePhase = 0;
    gWorkPads[HPAD_PORT_1].actuator0 = 0;
    gWorkPads[HPAD_PORT_1].actuator1 = 0;
}

// FUN_00103CF0
void H_Pad_IgnoreRumbleCallback(void)
{
}

// FUN_00103D00
void H_Pad_RwFreeRaw(void* memory)
{
    HPadRwAllocation* allocation;
    u32 size;
    u32 hint;
    s32 intrState;

    if (memory == NULL)
    {
        return;
    }

    allocation = (HPadRwAllocation*)((u8*)memory - sizeof(HPadRwAllocation));
    size = allocation->size;
    hint = allocation->hint;
    sRwAllocatedBytes -= size;
    intrState = func_0050d3a0();
    if (hint != 0)
    {
        memset(allocation, 0, size);
    }
    func_00520748(allocation);
    if (intrState != 0)
    {
        func_0050d3f0();
    }
}

// FUN_00103DA0 NONMATCHING
void* H_Pad_RwAllocateRaw(size_t size, RwUInt32 hint)
{
    HPadRwAllocation* allocation;
    s32 intrState;
    const char* message;

    if (size == 0xAC)
    {
        message = D_005CEAE0;
        printf(message);
    }

    sRwAllocatedBytes += size;
    intrState = func_0050d3a0();
    allocation = (HPadRwAllocation*)func_00520728(size + sizeof(HPadRwAllocation));
    if (intrState != 0)
    {
        func_0050d3f0();
    }

    if (allocation == (HPadRwAllocation*)0x014CCBC8)
    {
        printf(D_005CEAE0);
    }
    if (allocation == NULL)
    {
        printf(D_005CEAF0);
        printf(D_005CEAF0);
        printf(D_005CEAF0);
        printf(D_005CEAF0);
        printf(D_005CEB10, size, sRwAllocatedBytes);
        printf(D_005CEAF0);
        printf(D_005CEAF0);
        printf(D_005CEAF0);
        printf(D_005CEAF0);
        if (datGetFlag(0x141A) != 0)
        {
            return NULL;
        }

        K_Assert(D_005CEB30, 671);
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
    s32 intrState;
    RwUInt32 mallocHint;
    mallocHint = hint;
    intrState = func_0050d3a0();
    if (memory == NULL)
    {
        reallocated = H_Pad_RwMalloc(newSize, mallocHint);
    }
    else
    {
        copySize = *(RwUInt32*)((u8*)memory - sizeof(void*));
        if (newSize < copySize)
        {
            copySize = newSize;
        }

        reallocated = H_Pad_RwMalloc(newSize, mallocHint);
        memcpy(reallocated, memory, copySize);
        H_Pad_RwFree(memory);
        sRwReallocCount++;
    }

    if (intrState != 0)
    {
        func_0050d3f0();
    }
    return reallocated;
}
#pragma optimization_level 2
// FUN_00104040 MATCHING
void* H_Pad_RwCalloc(RwUInt32 elementCount, RwUInt32 elementSize, RwUInt32 hint)
{
    void* memory;
    RwUInt32 size;
    s32 intrState;

    intrState = func_0050d3a0();
    size = elementSize * elementCount;
    if ((memory = H_Pad_RwMalloc(size, hint)) != NULL)
    {
        memset(memory, 0, size);
        sRwCallocCount++;
    }
    if (intrState != 0)
    {
        func_0050d3f0();
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

// Previous body omitted retail's debug-name checks (two kwlnTaskGetUpdating
// + strcmp guards bracketing the allocation) and the interrupt-disable
// pair around H_Pad_RwAllocateRaw. That callee was also missing its real
// second parameter (hint) - added as an unused param (its body never
// reads it) since the caller passes it in $a1 per retail. obj 88B->312B/
// 320B; residual is a small OR-condition register-choice floor.
// FUN_00104140 NONMATCHING
void* H_Pad_RwMalloc(RwUInt32 size, RwUInt32 hint)
{
    HPadRwAllocation* allocation;
    u8* alignmentBase;
    u8* alignedMemory;
    s32 intrState;

    if (kwlnTaskGetUpdating() != NULL) {
        if (strcmp("H_CutInDraw", (const char*)kwlnTaskGetUpdating()) == 0) {
            if (size == 0x27d8 || size == 0x1fe0) {
                printf(D_005CEAE0);
            }
        }
    }

    intrState = func_0050d3a0();
    allocation = (HPadRwAllocation*)H_Pad_RwAllocateRaw(size + 0x14, hint);
    if (allocation == NULL) {
        if (intrState != 0) {
            func_0050d3f0();
        }
        return NULL;
    }

    allocation[-1].alignment = 16;
    alignmentBase = (u8*)allocation + 4;
    alignedMemory = alignmentBase + (16 - ((uintptr_t)alignmentBase & 0xF));
    *(void**)(alignedMemory - sizeof(void*)) = allocation;

    if (intrState != 0) {
        func_0050d3f0();
    }

    if (kwlnTaskGetUpdating() != NULL) {
        if (size == 0x50) {
            strcmp("\n", (const char*)kwlnTaskGetUpdating());
        }
    }

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
