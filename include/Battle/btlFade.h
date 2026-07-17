#ifndef BTLFADE_H
#define BTLFADE_H

#include "Utils.h"

typedef struct KwlnTask KwlnTask;

KwlnTask* btlFadeCreateTask(s32 fadeType);
void btlFadeStart(u16 delay);
void btlFadeStartImmediate(void);
s32 btlFadeAllowsBattleTransition(void);
s32 btlFadeIsActive(void);

// Preserves the retail u64 callback ABI while exposing its boolean predicate.
u64 btlFadeSuppressesFormationUpdates(void);
#endif