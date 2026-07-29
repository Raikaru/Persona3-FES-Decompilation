#ifndef BR_PANEL_H
#define BR_PANEL_H

#include "Utils.h"
#include "rw/rwplcore.h"


typedef struct BrPanelResultEntry {
    s32 type;
    s16 characterId;
    u16 unk_06;
    s32 value;
    u32 fontHandle;
    RwIm2DVertex background[4];
    RwIm2DVertex label[4];
    RwIm2DVertex digits[2][4];
    RwIm2DVertex typeIcon[4];
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