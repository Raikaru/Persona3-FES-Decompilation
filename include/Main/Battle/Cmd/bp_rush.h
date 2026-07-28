#ifndef BP_RUSH_H
#define BP_RUSH_H

#include "Utils.h"

/*
 * Layout recovered from every observed BpRush work-buffer access in the source
 * tree. The render-quad payloads are opaque to this module, so their storage is
 * retained explicitly. BpRushCounter preserves the signed and unsigned views
 * used at offsets 0x810-0x818 rather than choosing one interpretation.
 */
typedef union BpRushCounter
{
    u32 unsignedValue;
    s32 signedValue;
} BpRushCounter;

typedef struct BpRushQuad
{
    u32 words[0x40];
} BpRushQuad;

typedef struct BpRushWork
{
    u32 flags;                         // 0x000
    u8 pad_0x004[0x0c];
    BpRushQuad mainQuad;               // 0x010
    BpRushQuad spinnerQuads[7];        // 0x110
    BpRushCounter mainVisibility;      // 0x810
    BpRushCounter spinnerVisibility;   // 0x814
    BpRushCounter spinFrame;           // 0x818
} BpRushWork;

typedef char BpRushWork_size_must_be_0x81c[
    sizeof(BpRushWork) == 0x81c ? 1 : -1];

void bpRushRequestHide(void);
void bpRushClearHideRequest(void);
void bpRushRequestSecondaryHide(void);
void bpRushClearSecondaryHideRequest(void);
void bpRushShowSpinner(void);
void bpRushHideSpinner(void);
void bpRushUpdate(void);
void bpRushDraw(void);
void bpRushUpdateGeometry(void);

#endif
