#ifndef EFFMISC_H
#define EFFMISC_H

#include "Utils.h"
#include "rw/rwcore.h"

// Not really sure about the name of this file

// 16 bytes
typedef struct EffRandState
{
    u32 x[4]; // 0x00
} EffRandState;

void effMiscQuatMultiplyVU();
void effMiscNormalizeVU();

void func_00357e30(void);
void func_00357ea0(f32 angleX, f32 angleY, f32 angleZ);
void func_00358160(f32 angle);
void func_003581f0(const RwV3d* axis, RwMatrix* matrix, f32 angle);
void func_00358340(const RwV3d* axis, f32 angle);
void func_00358380(f32 angle);
void func_00358410(void);
void func_00358460(const RwRGBA* color, u32 saveAndRestoreRenderState);
u32 effMiscRand(EffRandState* state);
f32 effMiscRandFloat(EffRandState* state);
u32 effMiscRandRange(EffRandState* state, u32 max);
void effMiscRandInit(EffRandState* state, u32 seed);

#endif