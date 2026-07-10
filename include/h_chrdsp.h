#ifndef H_CHRDSP_H
#define H_CHRDSP_H

#include "Utils.h"
#include "rw/rwplcore.h"

typedef struct HCdvd HCdvd;

typedef enum HChrdspState
{
    HCHRDP_STATE_IDLE,
    HCHRDP_STATE_LOAD_ARCHIVE,
    HCHRDP_STATE_PARSE_LAYER,
    HCHRDP_STATE_UNAVAILABLE,
    HCHRDP_STATE_DRAW
} HChrdspState;

// 1648 bytes
typedef struct HChrdspWork
{
    s16 state;                       // 0x000: HChrdspState
    s16 reserved02;                  // 0x002
    s16 characterId;                 // 0x004
    s16 reserved06;                  // 0x006
    s16 reserved08;                  // 0x008
    s16 variant;                     // 0x00a
    RwV2d position;                  // 0x00c
    void* resources[3];              // 0x014
    RwIm2DVertex vertices[5][4];     // 0x020
    RwRGBA color;                    // 0x520
    f32 zOffset;                     // 0x524
    HCdvd* archive;                  // 0x528
    f32 layerWidth;                  // 0x52c
    f32 layerHeight;                 // 0x530
    u8 reserved534[0x14];            // 0x534
    void* asyncRequest;              // 0x548
    s32 resourceIndex;               // 0x54c
    u32 drawMiddleLayer;             // 0x550
    u32 drawTopLayer;                // 0x554
    u32 alphaPhase;                  // 0x558
    s32 alphaTimer;                  // 0x55c
    s32 alphaIndex;                  // 0x560
    u32 usesCustomPath;              // 0x564
    char texturePath[0x108];         // 0x568
} HChrdspWork;

void H_Chrdsp_Init(void);
void H_Chrdsp_Main(void);
void H_Chrdsp_UpdateWork(HChrdspWork* work);

#endif
