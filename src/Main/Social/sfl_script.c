#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Social/sfl_script.h"

s32 bpTexHasPendingNode();
#ifndef SQRT
#define SQRT(x) sqrtf(x)
#endif
float sqrtf(float x);
typedef int (*code)(...);
void FUN_0025a120(void);
void FUN_0025a130(void);
void FUN_0025a440(void);
void FUN_0025a7d0(void);
void FUN_0025aad0(void);
void FUN_0025b440(void);
extern code DAT_00960090;
extern code DAT_0096009c;
#pragma alias DAT_00960090_abs DAT_00960090
#pragma alias DAT_0096009c_abs DAT_0096009c
extern code DAT_00960090_abs[];
extern code DAT_0096009c_abs[];
#define DAT_00960090 DAT_00960090_abs
#define DAT_0096009c DAT_0096009c_abs
extern f32 fGpffff8088;
extern f32 fGpffff8248;
extern f32 fGpffff82ac;
extern f32 fGpffff83b8;
extern f32 fGpffff83bc;
extern f32 fGpffff82fc;
extern f32 FUN_0052e878(f32 angle);
extern u32 uGpffffb670;
typedef struct { f32 a; f32 b; f32 c; } SflVec3;
typedef struct {
  u32 flags;
  f32 from[3];
  f32 to[3];
  f32 position[3];
  u32 frame;
  u32 previous;
  u32 active;
  u32 timer;
  u8 padding[0xc68];
  u32 state;
} SflCursorWork;
static u32* sSflCursor; // puGpffffb670
void FUN_00258540(u32 param_1, void* param_2);
extern u32 FUN_0020e510(s32 index);
extern void FUN_0021eb80(void* work, const f32* values);
extern void FUN_00250f80(f32* output, const void* input);
extern u32* FUN_00256110(u32 id);
extern void FUN_002561e0(f32 amount, void* node);





#pragma alias sflScriptInit FUN_00259610
#pragma alias sflScriptClearWork FUN_00259630
#pragma alias sflScriptStartQueuedCommands FUN_00259640
#pragma alias sflScriptConfigureCommandBuffer FUN_00259690
#pragma alias sflScriptIsRunning FUN_002596f0
#pragma alias sflScriptDispatchCommands FUN_00259740
#pragma alias sflScriptAppendCommand FUN_00259850
#pragma alias sflScriptQueueEndCommand FUN_00259970
#pragma alias sflScriptQueueSwapCommand FUN_002599C0
#pragma alias sflScriptQueueCloseCommand FUN_00259A60
#pragma alias sflScriptQueueWaitCommand FUN_00259b00
#pragma alias sflScriptQueueOpenCommand FUN_00259b60
#pragma alias sflScriptQueueWaitForActionsCommand FUN_00259bc0
#pragma alias sflScriptQueueStartActionsCommand FUN_00259c10
#pragma alias sflScriptQueueSetCardValueCommand FUN_00259c60
#pragma alias sflScriptQueueShuffleCommand FUN_00259cc0
#pragma alias sflScriptHandleEndCommand FUN_00259D10
#pragma alias sflScriptHandleSwapCommand FUN_00259D80
#pragma alias sflScriptHandleWaitForActionsCommand FUN_00259e00
#pragma alias sflScriptHandleStartActionsCommand FUN_00259E60
#pragma alias sflScriptHandleSetCardValueCommand FUN_00259EA0
#pragma alias sflScriptHandleShuffleCommand FUN_00259ED0
#pragma alias sflScriptHandleCloseCommand FUN_00259F40
#pragma alias sflScriptHandleOpenCommand FUN_00259FC0
#pragma alias sflScriptHandleWaitCommand FUN_0025A030
#pragma alias K_Assert FUN_0019d3f0
#pragma alias copyMemory FUN_00521250
#pragma alias debugPrintf FUN_005225a8
#pragma alias bpTexQueueNodePair FUN_002551d0
#pragma alias bpTexQueueNodeRange FUN_00255570
#pragma alias bpTexRemoveNodeAt FUN_00255810
#pragma alias bpTexShuffleNodes FUN_00255b20
#pragma alias bpTexIsShuffleActive FUN_00255f30
#pragma alias bpTexHasPendingNode FUN_00256430
#pragma alias bpTexApplyActions FUN_00257130
#pragma alias sflCardSetScriptValue FUN_002584e0
#pragma alias gSflScriptCommandTableWords D_0068EAD0
#pragma alias gSflScriptCommandParamSizes D_0068EAD4
#pragma alias sSflScriptWorkAddress iGpffffb668
#pragma alias sSflScriptShuffleStarted iGpffffb66c
#pragma alias sSflScriptWorkWord uGpffffb668
#pragma alias sSflScriptStartActionsTrace D_0068EB60
#pragma alias sSflScriptSourceFile D_0068eb18
#pragma alias sSflScriptEndTrace D_0068eb28
#pragma alias sSflScriptOpenTrace D_0068eb98
#pragma alias sSflScriptSwapTrace D_0068eb40
#pragma alias sSflScriptCloseTrace D_0068eb80
#pragma alias sSflScriptWaitTrace D_0068eba8


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void sflScriptClearWork(void);
void sflScriptDispatchCommands(void);
void sflScriptAppendCommand(int param_1,const void* param_2);
void sflScriptQueueSwapCommand(u16 param_1,u16 param_2);
void sflScriptQueueCloseCommand(u16 param_1,u16 param_2);
u64 sflScriptHandleEndCommand(void);
u32 sflScriptHandleSwapCommand(s16 *param_1);
u32 sflScriptHandleStartActionsCommand(void);
u32 sflScriptHandleSetCardValueCommand(u16 *param_1);
u32 sflScriptHandleShuffleCommand(void);
u32 sflScriptHandleCloseCommand(s16 *param_1);
u32 sflScriptHandleOpenCommand(s16 *param_1);
u32 sflScriptHandleWaitCommand(s16 *param_1);
extern u16 gSflScriptCommandTableWords[];
extern u16 gSflScriptCommandParamSizes[];
extern SflScriptWork* sSflScriptWorkAddress;
extern u32 sSflScriptShuffleStarted;
extern u32 sSflScriptWorkWord;
extern const char sSflScriptStartActionsTrace[];
extern const char sSflScriptSourceFile[];
extern const char sSflScriptEndTrace[];
extern const char sSflScriptOpenTrace[];
extern const char sSflScriptSwapTrace[];
extern const char sSflScriptCloseTrace[];
void copyMemory(void* destination, const void* source, u32 size);
extern const char sSflScriptWaitTrace[];

void debugPrintf(const char* message, ...);
void bpTexRemoveNodeAt(s16 param_1);

static SflScriptWork* sSflScript; // puGpffffb668


// FUN_00259640
void sflScriptStartQueuedCommands(void)
{
    SflScriptWork* work;

    K_ASSERT(sSflScript != NULL, 0x43);
    work = sSflScript;
    work->executeCursor = work->bufferStart.unsignedValue;
    work->flags |= 1;
}

// FUN_00259690
void sflScriptConfigureCommandBuffer(u32 param_1, u32 param_2)
{
    SflScriptWork* work;

    K_ASSERT(sSflScript != NULL, 0x43);
    work = sSflScript;
    work->bufferStart.unsignedValue = param_1;
    work->appendCursor = param_1;
    work->bufferCapacity.unsignedValue = param_2;
}

// FUN_002596f0
u32 sflScriptIsRunning(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    return sSflScript->flags & 1;
}

// FUN_00259740


void sflScriptDispatchCommands(void)



{

  u16 *cursor;
  SflScriptWork *work;
  u32 callback_result;
  u32 next_offset;
  u16 *command_entry;
  u32 flags;
  u32 length;
  u32 has_length;

  

  if (sSflScript == (SflScriptWork *)0x0) {
    K_Assert(sSflScriptSourceFile, 0x43);

  }

  work = sSflScript;

  flags = ~sSflScript->flags;
  if ((flags & 1U) == 0U) {

    while( 1 ) {

      cursor = (u16 *)work->executeCursor;
      command_entry = gSflScriptCommandTableWords + ((u32)*cursor * 4);
      length = (u32)command_entry[2];
      has_length = (length != 0) ^ 1U;
      if (has_length == 0) {
        cursor += 1;
        if (((u32)cursor & 3) != 0) {
          cursor += 1;
        }
      } else {
        cursor = (u16 *)0x0;
      }
      callback_result = (*(code *)command_entry)(cursor);
      if (callback_result == 0) break;
      next_offset = work->executeCursor + 2;
      if (command_entry[2] != 0) {
        if ((next_offset & 3) != 0) {
          next_offset += 2;
        }
        next_offset += (u32)(u16)command_entry[2];
        if ((next_offset & 1) != 0) {
          next_offset += 1;
        }
      }
      work->executeCursor = next_offset;

    }

  }

  return;

}

// FUN_00259850


void sflScriptAppendCommand(int param_1,const void* param_2)



{
  u16 *packet_cursor;
  SflScriptWork *work;
  u16 *next_cursor;
  u32 cursor;

  if (sSflScriptWorkAddress == 0) {
    K_Assert(sSflScriptSourceFile, 0x43);
  }
  work = sSflScriptWorkAddress;
  packet_cursor = (u16 *)work->appendCursor;
  *packet_cursor = (short)param_1;
  next_cursor = packet_cursor + 1;
  if (*(u16 *)((u8 *)gSflScriptCommandParamSizes + param_1 * 8) != 0) {
    if (((u32)next_cursor & 3) != 0) {
      next_cursor += 1;
    }
    copyMemory(next_cursor,param_2,
                 *(u16 *)((u8 *)gSflScriptCommandParamSizes + param_1 * 8));
    next_cursor = (u16 *)((int)next_cursor +
                     *(u16 *)((u8 *)gSflScriptCommandParamSizes + param_1 * 8));
  }
  cursor = work->appendCursor;
  cursor += (u32)next_cursor - cursor;
  work->appendCursor = cursor;
  if ((int)cursor - work->bufferStart.signedValue >
      work->bufferCapacity.signedValue) {
    K_Assert(sSflScriptSourceFile, 0xb2);
  }
  if ((work->appendCursor & 1) != 0) {
    work->appendCursor = work->appendCursor + 1;
  }
}

// FUN_00259970
void sflScriptQueueEndCommand(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    sflScriptAppendCommand(0, 0);
}


// FUN_002599C0


void sflScriptQueueSwapCommand(u16 param_1,u16 param_2)



{

  u8 *cursor;
  s32 count;

  u16 params[2];

  

  if (sSflScriptWorkAddress == 0) {

    K_Assert(sSflScriptSourceFile,0x43);

  }

  cursor = (u8*)params;
  count = sizeof(params);
  if (cursor != NULL) {
    do {
      *cursor++ = 0;
      count--;
    } while (count != 0);
  }

  params[0] = param_1;

  params[1] = param_2;


  sflScriptAppendCommand(1, params);
  return;

}

// FUN_00259A60


void sflScriptQueueCloseCommand(u16 param_1,u16 param_2)



{

  u8 *cursor;
  s32 count;

  u16 params[2];

  

  if (sSflScriptWorkAddress == 0) {

    K_Assert(sSflScriptSourceFile,0x43);

  }

  cursor = (u8*)params;
  count = sizeof(params);
  if (cursor != NULL) {
    do {
      *cursor++ = 0;
      count--;
    } while (count != 0);
  }

  params[0] = param_1;

  params[1] = param_2;


  sflScriptAppendCommand(3, params);
  return;

}

// FUN_00259b00
void sflScriptQueueWaitCommand(u16 param_1)
{
    u16 arg;

    K_ASSERT(sSflScript != NULL, 0x43);
    arg = param_1;
    sflScriptAppendCommand(2, &arg);
}

// FUN_00259b60
void sflScriptQueueOpenCommand(u16 param_1)
{
    u16 arg;

    K_ASSERT(sSflScript != NULL, 0x43);
    arg = param_1;
    sflScriptAppendCommand(4, &arg);
}

// FUN_00259bc0
void sflScriptQueueWaitForActionsCommand(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    sflScriptAppendCommand(5, 0);
}


/* Recovered battle-misc harvest: 0x00259630-0x0025A030 */

// FUN_00259c10
void sflScriptQueueStartActionsCommand(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    sflScriptAppendCommand(6, 0);
}

// FUN_00259c60
void sflScriptQueueSetCardValueCommand(u16 param_1)
{
    u16 arg;

    K_ASSERT(sSflScript != NULL, 0x43);
    arg = param_1;
    sflScriptAppendCommand(7, &arg);
}

// FUN_00259cc0
void sflScriptQueueShuffleCommand(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    sflScriptAppendCommand(8, 0);
}


// FUN_00259D10
u64 sflScriptHandleEndCommand(void)
{
    SflScriptWork *work;

    K_ASSERT(sSflScript != NULL, 0x43);
    work = sSflScript;
    debugPrintf(sSflScriptEndTrace);
    work->flags &= ~1;
    return 0;
}

// FUN_00259D80
u32 sflScriptHandleSwapCommand(s16 *param_1)
{
    s16 *next;

    if (sSflScriptWorkAddress == 0) {
        K_Assert(sSflScriptSourceFile, 0x43);
    }
    next = param_1 + 1;
    debugPrintf(sSflScriptSwapTrace, param_1[0], next[0]);
    bpTexQueueNodePair(param_1[0], next[0]);
    return 1;
}

// FUN_00259e00
u32 sflScriptHandleWaitForActionsCommand(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    if (bpTexHasPendingNode() != 0) {
        return 0;
    }
    return 1;
}

// FUN_00259E60


u32 sflScriptHandleStartActionsCommand(void)



{

  debugPrintf(sSflScriptStartActionsTrace);

  bpTexApplyActions();

  return 1;

}

// FUN_00259EA0
u32 sflScriptHandleSetCardValueCommand(u16 *param_1)
{
    sflCardSetScriptValue(*param_1);
    return 1;
}
// FUN_00259ED0
u32 sflScriptHandleShuffleCommand(void)
{
    if (sSflScriptShuffleStarted == 0) {
        bpTexShuffleNodes();
        sSflScriptShuffleStarted = 1;
        goto done_zero;
    }
    if (bpTexIsShuffleActive() != 0) {
        return 0;
    }
    sSflScriptShuffleStarted = 0;
    return 1;
done_zero:
    return 0;
}

// FUN_00259F40
u32 sflScriptHandleCloseCommand(s16 *param_1)
{
    s16 *next;

    if (sSflScriptWorkAddress == 0) {
        K_Assert(sSflScriptSourceFile, 0x43);
    }
    next = param_1 + 1;
    debugPrintf(sSflScriptCloseTrace, param_1[0], next[0]);
    bpTexQueueNodeRange(param_1[0], next[0]);
    return 1;
}

// FUN_00259FC0
u32 sflScriptHandleOpenCommand(s16 *param_1)
{
  if (sSflScriptWorkAddress == 0) {
    K_Assert(sSflScriptSourceFile, 0x43);
  }
  debugPrintf(sSflScriptOpenTrace, *param_1);
  bpTexRemoveNodeAt(*param_1);
  return 1;
}

/* Recovered battle-misc harvest: 0x00259850-0x00259850 */
// FUN_0025A030
u32 sflScriptHandleWaitCommand(s16 *param_1)
{
    SflScriptWork *work;
    u32 count;

    K_ASSERT(sSflScript != NULL, 0x43);
    work = sSflScript;
    count = *(u16 *)param_1;
    if ((~work->flags & 2) != 0) {
        debugPrintf(sSflScriptWaitTrace, *param_1);
        work->waitCounter = 0;
        if (count == 0) {
            return 1;
        }
    } else {
        work->waitCounter += 1;
        if (work->waitCounter == count) {
            work->flags &= ~2;
            return 1;
        }
    }
    work->flags |= 2;
    return 0;
}




/* Recovered battle-misc support prelude */





// FUN_0025a110
void sflCursor0025a110(u32* param_1)
{
    *param_1 = 0;
    sSflCursor = param_1;
}




/* Recovered battle-misc harvest: 0x0025A120-0x0025B440 */
// FUN_0025A120


void FUN_0025a120(void)



{

  uGpffffb670 = 0;

  return;

}

/* Reconstructed the state dispatch, interpolation, and six-slot alpha update.
 * The remaining differences are MWCC register allocation and floating-point
 * spill placement; object size now exactly matches the retail function window.
 */
/* Removing this worsens FUN_0025a130 (nd185 -> nd295) - measured W161. */

#pragma opt_loop_invariants reset



/* Recovered battle-misc harvest: 0x0025AAD0-0x0025AAD0 */
