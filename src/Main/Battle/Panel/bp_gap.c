#include "Utils.h"
#include "Kosaka/k_assert.h"

extern u16 DAT_007e094c;
extern u16 DAT_007e0952;
extern u16 DAT_007e0956;
extern u16 DAT_007e095a;
extern void func_0010a4e0(s32 bank, s32 cue, s32 variant, s32 pan);

static void bpGapSetSound(u32* state, s32 mode)
{
    u8* sound;

    sound = (u8*)state + mode * 4 + 0x14;
    if (sound[0] == 1)
    {
        func_0010a4e0(1, sound[1], sound[2], sound[3]);
    }
    else if (sound[0] == 0)
    {
        func_0010a4e0(0, sound[1], sound[2], sound[3]);
    }
}

// FUN_0024A260 NONMATCHING
void func_0024a260(u32* state)
{
    u32 flags;
    u32 value;
    u32 limit;
    u32 position;

    K_ASSERT((state[0] & 1) != 0, 0x15);

    flags = state[0];
    if ((flags & 2) != 0 &&
        ((DAT_007e094c & 0xF000) != 0 || (DAT_007e0956 & 0xF000) != 0))
    {
        return;
    }

    state[0] &= ~2;
    if ((DAT_007e0952 & 0x4000) == 0 && (DAT_007e095a & 0x4000) == 0)
    {
        if ((DAT_007e0952 & 0x1000) == 0 && (DAT_007e095a & 0x1000) == 0)
        {
            if ((DAT_007e0952 & 2) == 0)
            {
                if ((DAT_007e0952 & 1) != 0 && state[4] > 1 && state[3] != 0)
                {
                    value = state[3];
                    limit = state[2];
                    position = state[4];
                    if (value < limit || state[1] < limit)
                    {
                        state[3] = 0;
                        state[1] = 0;
                    }
                    else
                    {
                        state[3] = value - limit;
                        state[1] -= limit;
                    }
                    bpGapSetSound(state, 7);
                    if (state[3] == 0)
                    {
                        state[0] |= 2;
                    }
                    state[0] |= 1;
                    (void)position;
                }
            }
            else
            {
                limit = state[4];
                if (limit > 1)
                {
                    value = limit - 1;
                    if (state[3] != value)
                    {
                        position = state[2] + state[3];
                        if (position < value && state[1] + state[2] <= limit - state[2])
                        {
                            state[3] = position;
                            state[1] += state[2];
                        }
                        else
                        {
                            state[3] = value;
                            state[1] = limit - state[2];
                        }
                        bpGapSetSound(state, 3);
                        if (state[3] == limit - 1)
                        {
                            state[0] |= 2;
                        }
                        state[0] |= 1;
                    }
                }
            }
        }
        else if (state[4] > 1)
        {
            if ((s32)state[3] < 1)
            {
                state[3] = state[4] - 1;
                state[1] = state[4] - state[2];
                bpGapSetSound(state, 5);
            }
            else
            {
                state[3]--;
                if (state[3] <= state[1] && state[1] > 0)
                {
                    state[1]--;
                }
                bpGapSetSound(state, 1);
            }
            if (state[3] == 0)
            {
                state[0] |= 2;
            }
            state[0] |= 1;
        }
    }
    else if (state[4] > 1)
    {
        if (state[3] < state[4] - 1)
        {
            state[3]++;
            if (state[1] + state[2] - 1 <= state[3] && state[1] < state[4] - state[2])
            {
                state[1]++;
            }
            bpGapSetSound(state, 0);
        }
        else
        {
            state[3] = 0;
            state[1] = 0;
            bpGapSetSound(state, 4);
        }
        if (state[3] == state[4] - 1)
        {
            state[0] |= 2;
        }
        state[0] |= 1;
    }
}

// FUN_0024A630 NONMATCHING
void func_0024a630(u32* state, s32 mode)
{
    u8* sound;

    if ((state[0] & 4) != 0)
    {
        return;
    }

    sound = (u8*)state + mode * 4 + 0x14;
    if (sound[0] == 1)
    {
        func_0010a4e0(1, sound[1], sound[2], sound[3]);
    }
    else if (sound[0] == 0)
    {
        func_0010a4e0(0, sound[1], sound[2], sound[3]);
    }
}
