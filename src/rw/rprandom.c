#include "rw/rprandom.h"

typedef struct RpRandomGlobals
{
    RwUInt32 *state;
    RwUInt32 *jptr;
    RwUInt32 *kptr;
    RwUInt32 *end;
} RpRandomGlobals;

extern RwInt32 iGpffffba88;

#define RANDOMGLOBALS ((RpRandomGlobals*)((RwUInt8*)&rwGlobals + iGpffffba88))

// FUN_00488c70
void RpRandomSeedMT(RwUInt32 seed)
{
    // TODO
}

// FUN_00488dd0
#pragma optimization_level 3
void RpRandomSeed(RwUInt32 seed)
{
    RwInt32 j;
    RwInt32 offset;
    RwInt32 warmup;
    RwUInt32* state;
    RpRandomGlobals* globals;

    j = 1;
    offset = sizeof(RwUInt32);
    *RANDOMGLOBALS->state = seed;

    do
    {
        j += 6;
        state = (RwUInt32*)((RwUInt8*)RANDOMGLOBALS->state + offset);
        *state = state[-1] * 0x41c64e6d + 0x3039;

        state = (RwUInt32*)((RwUInt8*)RANDOMGLOBALS->state + offset);
        state[1] = *state * 0x41c64e6d + 0x3039;

        state = (RwUInt32*)((RwUInt8*)RANDOMGLOBALS->state + offset);
        state[2] = state[1] * 0x41c64e6d + 0x3039;

        state = (RwUInt32*)((RwUInt8*)RANDOMGLOBALS->state + offset);
        state[3] = state[2] * 0x41c64e6d + 0x3039;

        state = (RwUInt32*)((RwUInt8*)RANDOMGLOBALS->state + offset);
        state[4] = state[3] * 0x41c64e6d + 0x3039;

        state = (RwUInt32*)((RwUInt8*)RANDOMGLOBALS->state + offset);
        offset += 6 * sizeof(RwUInt32);
        state[5] = state[4] * 0x41c64e6d + 0x3039;
    } while (j < 0x1f);

    warmup = 0;
    globals = RANDOMGLOBALS;
    globals->jptr = globals->state + 3;
    globals->kptr = globals->state;

    do
    {
        RpRandom();
        warmup++;
    } while (warmup < 0x136);
}
#pragma optimization_level 2

// FUN_00488f30
RwUInt32 RpRandom()
{
    // TODO

    return 0;
}