#ifndef MT_EVT_CUSTOM_EVENT_H
#define MT_EVT_CUSTOM_EVENT_H

#include "type.h"

// 0x20-byte entry referenced by the event data entry table.
typedef struct
{
    u8 unk_00[0x10];
    s32 unk_10;       // 0x10
    u32 unk_14;       // 0x14
    s32 type;         // 0x18
    u8 unk_1c[0x04];
} MtEvtCustomEntry;

// Partial event data layout containing the fields used by custom-event entry scans.
typedef struct
{
    u8 unk_00[0x10];
    s32 unk_10;                    // 0x10
    u8 unk_14[0x20];
    MtEvtCustomEntry* entries;     // 0x34
    s32 entryCount;                // 0x38
} MtEvtCustomData;

#endif // MT_EVT_CUSTOM_EVENT_H
