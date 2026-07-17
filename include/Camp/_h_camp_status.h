#ifndef _H_CAMP_STATUS_H
#define _H_CAMP_STATUS_H
#include "Utils.h"

typedef struct KwlnTask KwlnTask;

typedef struct CampVec2
{
    f32 x;
    f32 y;
} CampVec2;

void* h_campStatusUpdatePcStatusRootTask(KwlnTask* task);
void h_campStatusDrawScreen(CampVec2 position, CampVec2 otherPosition,
                            f32 alpha, s16 pcId, s32 mode,
                            s32 phase, s32 fade);
void h_campStatusDrawHp(CampVec2 position, f32 alpha, s16 pcId,
                        s32 barOffset, s32 fade);
void h_campStatusDrawSp(CampVec2 position, f32 alpha, s16 pcId,
                        s32 barOffset, s32 fade);
void h_campStatusDrawPhysicalCondition(CampVec2 position, f32 alpha,
                                        s16 pcId, s32 fade);
void h_campStatusDrawBadStatus(CampVec2 position, f32 alpha, s16 pcId,
                               s32 fade);
void h_campStatusDrawStatusTransition(CampVec2 position, f32 alpha,
                                      s16 pcId, s32 phase);
void h_campStatusDrawStatus(CampVec2 position, CampVec2 unused,
                            f32 alpha, s16 pcId, s32 fade);
void FUN_0012b300(CampVec2 position, f32 scale, void* persona,
                  u8 alpha);
void FUN_0012b860(CampVec2 position, f32 scale, void* currentStats,
                  void* persona, u8 alpha);
void FUN_0012bce0(CampVec2 position, f32 scale, void* unused,
                  void* persona, u8 alpha);
void FUN_0012bfb0(CampVec2 position, f32 scale, void* currentStats,
                  void* persona, u8 alpha);
#endif