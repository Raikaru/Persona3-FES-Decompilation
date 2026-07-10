#ifndef _H_CAMP_PERSONA_H
#define _H_CAMP_PERSONA_H
#include "Utils.h"
#include "Camp/_h_camp_status.h"

typedef struct KwlnTask KwlnTask;

typedef struct CampPersonaDrawParams
{
    f32 alpha;
    f32 x;
    f32 y;
    void* persona;
    s32 mode;
    s32 frame;
    s32 fade;
} CampPersonaDrawParams;

void FUN_00124e00(CampVec2 position, CampVec2 otherPosition, f32 alpha,
                  void* persona, s32 mode, s32 frame, s32 fade);
void FUN_00124e60(CampVec2 position, f32 alpha, void* persona, s32 fade);
void FUN_00124fd0(CampVec2 position, f32 alpha, void* persona, s32 fade);
void FUN_00125740(CampVec2 position, f32 alpha, void* persona,
                  s32 frame);
void FUN_00125b40(CampVec2 position, CampVec2 unused, f32 alpha,
                  void* persona, s32 fade);
void* FUN_00125d70(KwlnTask* task);
#endif