#ifndef EVENT_FCL_FCLCOMBINETYPES_H
#define EVENT_FCL_FCLCOMBINETYPES_H

#include "type.h"

typedef union FclPersonaTableEntry {
    u8 data[0xe];
    struct {
        u16 flags;       /* 0x00 */
        u8 arcana;       /* 0x02 */
        u8 level;        /* 0x03 */
        u8 unk_04[8];            /* 0x04 */
        u8 fusion_accident_rate; /* 0x0c */
        u8 unk_0d;               /* 0x0d */
    } fields;
} FclPersonaTableEntry;

typedef char FclPersonaTableEntrySizeMustBe0E[
    sizeof(FclPersonaTableEntry) == 0xe ? 1 : -1
];

#endif
