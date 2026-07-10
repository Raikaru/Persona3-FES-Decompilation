#ifndef K_SHADOW_H
#define K_SHADOW_H

#include "Utils.h"

typedef struct KwlnTask KwlnTask;

typedef enum FldShadowMapState
{
    FLDSHADOWMAP_STATE_INIT,
    FLDSHADOWMAP_STATE_DRAW,
    FLDSHADOWMAP_STATE_STOP
} FldShadowMapState;

// 8 bytes
typedef struct FldShadowMap
{
    FldShadowMapState state; // 0x00
    u8 unk_04[0x04];
} FldShadowMap;

KwlnTask* K_FldShadow_CreateRenderTexTask(KwlnTask* parent, u16 resTypeId, s32 param_3);
void* K_FldShadow_UpdateShadowMapTask(KwlnTask* fldShadowMapTask);
void K_FldShadow_DestroyShadowMapTask(KwlnTask* fldShadowMapTask);
KwlnTask* K_FldShadow_CreateShadowMapTask(KwlnTask* fldSceneDrawTask);

#endif