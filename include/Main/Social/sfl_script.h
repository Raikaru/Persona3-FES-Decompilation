#ifndef SFL_SCRIPT_H
#define SFL_SCRIPT_H

#include "Utils.h"

/*
 * Layout recovered from every observed SflScript command-buffer access in the
 * source tree. SflScriptScalar preserves the signed and unsigned views used for
 * buffer arithmetic at offsets 0x04 and 0x10.
 */
typedef union SflScriptScalar
{
    u32 unsignedValue;
    s32 signedValue;
} SflScriptScalar;

typedef struct SflScriptWork
{
    u32 flags;                         // 0x00
    SflScriptScalar bufferStart;       // 0x04
    u32 executeCursor;                 // 0x08
    u32 appendCursor;                  // 0x0c
    SflScriptScalar bufferCapacity;    // 0x10
    u32 waitCounter;                   // 0x14
} SflScriptWork;

typedef char SflScriptWork_size_must_be_0x18[
    sizeof(SflScriptWork) == 0x18 ? 1 : -1];

void sflScriptInit(SflScriptWork* work);
void sflScriptClearWork(void);
void sflScriptStartQueuedCommands(void);
void sflScriptConfigureCommandBuffer(u32 buffer, u32 capacity);
u32 sflScriptIsRunning(void);
void sflScriptDispatchCommands(void);
void sflScriptAppendCommand(int opcode, const void* parameters);

#endif
