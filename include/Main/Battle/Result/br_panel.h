#ifndef BR_PANEL_H
#define BR_PANEL_H

#include "Utils.h"

typedef struct BrPanelResultEntry {
    s32 type;
    s16 characterId;
    u16 unk_06;
    s32 value;
    u32 fontHandle;
    u8 background[0x100];
    u8 label[0x100];
    u8 digits[2][0x100];
    u8 typeIcon[0x100];
} BrPanelResultEntry;

void brPanel00234820(u32* work);
void brPanel00234960(void);
void brPanel00234a00(u32* params);
void brPanel00235010(void);
void brPanel002350f0(void);
void brPanel00235f30(void* glyphs, s32 capacity, s32 value, s32 style);
void brPanel00235ff0(void* glyphs, s32 capacity, s32 value, s32 style, const float* origin);
void brPanel00236280(void);
void brPanel002362e0(void);
u32 brPanel00236340(void);

#endif