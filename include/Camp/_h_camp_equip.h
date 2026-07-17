#ifndef _H_CAMP_EQUIP_H
#define _H_CAMP_EQUIP_H
#include "Utils.h"

typedef struct KwlnTask KwlnTask;
typedef struct CampVec2
{
    f32 x;
    f32 y;
} CampVec2;

void* FUN_0012c430(KwlnTask* task);
u32 FUN_0012dc20(u32* work);
u32 FUN_0012dcf0(u32* work);
void FUN_0012ddc0(void* work);
s32 FUN_0012df50(u32 mask);
void FUN_0012e170(void* atlas, s32 baseTile, CampVec2 position,
                  s32 scale, s32 red, s32 green, s32 blue, s32 alpha,
                  s32 value, s32 digits);
void FUN_0012e3b0(void* work, s32 index, void* recordData);
void FUN_0012f6d0(void* work, s32 index, void* recordData);
#endif