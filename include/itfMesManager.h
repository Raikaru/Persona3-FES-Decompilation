#ifndef ITFMESMANAGER_H
#define ITFMESMANAGER_H

#include "Utils.h"

#define BMD_HEADER_MAGIC0 0x3047534d // in little endian: "MSG0"
#define BMD_HEADER_MAGIC1 0x3147534d // in little endian: "MSG1"

// ?? bytes
typedef struct BmdHeader
{
    u8 unkData1[0x04];
    u32 size;          // size in bytes
    u32 magic;         // See 'SCR_MSG_HEADER_MAGIC0' and 'SCR_MSG_HEADER_MAGIC1'
} BmdHeader;

// 488 bytes. TODO: understand variables and find a better struct name
typedef struct ItfMes
{
    u8 unkData[0x1e8];
} ItfMes;

// Lives at offset 0xd4 within the message-manager record. Both arrays are
// indexed by the same 0..31 slot id: `objects` holds the live object pointer
// for a slot and `allocations` the backing block returned by the allocator.
#define ITF_MES_SLOT_COUNT 32

typedef struct ItfMesAllocationSlots
{
    u32 objects[ITF_MES_SLOT_COUNT];
    u32 allocations[ITF_MES_SLOT_COUNT];
} ItfMesAllocationSlots;

s32 itfMesMngInitialize(BmdHeader* bmdHeader);
void itfMesMngDestroyHandle(s32 mesHandleIdx);
void itfMesMngChangeWindowType(s32 mesHandleIdx, s32 type, u32 param_3);

#endif