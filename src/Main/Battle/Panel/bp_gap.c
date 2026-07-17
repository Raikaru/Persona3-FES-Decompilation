#include "Utils.h"
#include "Kosaka/k_assert.h"

extern const u16 D_007E094C;
extern const u16 D_007E0952;
extern const u16 D_007E0956;
extern const u16 D_007E095A;
extern void func_0010a4e0(s32 bank, s32 cue, s32 variant, s32 pan);

void func_0024a630(s32* state, s32 mode);

// FUN_0024A260
#pragma tailcall off
void func_0024a260(s32* state)
{
    s32* state_p = state;
    s32 count;
    s32 selection;
    s32 nextSelection;
    s32 scroll;
    s32 pageSize;

    K_ASSERT(~state[0] & 1, 0x15);

    if ((state[0] & 2) &&
        ((D_007E094C & 0xf000) || (D_007E0956 & 0xf000)))
    {
        return;
    }

    state_p[0] &= ~2;
    if ((D_007E0952 & 0x4000) || (D_007E095A & 0x4000))
    {
        count = state[4];
        if (count <= 1)
        {
            return;
        }
            selection = state[3];
            if (selection < count - 1)
            {
                selection++;
                state[3] = selection;
                pageSize = state[2];
                scroll = state_p[1];
                if (selection >= scroll + pageSize - 1 &&
                    scroll < state[4] - pageSize)
                {
                    state[1] = scroll + 1;
                }
                func_0024a630(state, 0);
            }
            else
            {
                state_p[3] = 0;
                state_p[1] = 0;
                func_0024a630(state_p, 4);
            }
            if (state[3] == state[4] - 1)
            {
                state[0] |= 2;
            }
            state_p[0] = state_p[0] | (1);
    }
    else if ((D_007E0952 & 0x1000) || (D_007E095A & 0x1000))
    {
        count = state[4];
        if (!(count <= 1))
        {
            selection = state[3];
            if (selection > 0)
            {
                nextSelection = selection - 1;
                state[3] = nextSelection;
                scroll = state[1];
                if (nextSelection <= scroll && scroll > 0)
                {
                    state[1] = scroll - 1;
                }
                func_0024a630(state, 1);
            }
            else
            {
                state_p[3] = count - 1;
                state[1] = state[4] - state_p[2];
                func_0024a630(state_p, 5);
            }
            if (state[3] == 0)
            {
                state_p[0] |= 2;
            }
            state_p[0] |= 1;
        }
    }
    else if (D_007E0952 & 2)
    {
        count = state[4];
        if (!(count <= 1))
        {
            selection = count - 1;
            if (state_p[3] != selection)
            {
                pageSize = state_p[2];
                scroll = state_p[3] + pageSize;
                if (scroll < selection &&
                    state[1] + pageSize <= count - pageSize)
                {
                    state[3] = scroll;
                    state_p[1] += state_p[2];
                }
                else
                {
                    state_p[3] = selection;
                    state_p[1] = state[4] - state_p[2];
                }
                func_0024a630(state_p, 3);
                if (state[3] == state_p[4] - 1)
                {
                    state[0] = state[0] | (2);
                }
                state_p[0] = state_p[0] | (1);
            }
        }
    }
    else if ((D_007E0952 & 1) && !(state[4] <= 1))
    {
        selection = state[3];
        if (selection != 0)
        {
            pageSize = state_p[2];
            if (selection >= pageSize && state_p[1] >= pageSize)
            {
                state_p[3] = selection - pageSize;
                state_p[1] = state_p[1] - (state_p[2]);
            }
            else
            {
                state_p[3] = 0;
                state_p[1] = 0;
            }
            func_0024a630(state_p, 7);
            if (state[3] == 0)
            {
                state[0] |= 2;
            }
            state_p[0] |= 1;
        }
    }
}
#pragma tailcall on
// FUN_0024A630
void func_0024a630(s32* state, s32 mode)
{
    u8* sound;

    sound = (u8*)state + mode * 4 + 0x14;
    if (~state[0] & 4)
    {
        return;
    }

    switch (sound[0])
    {
    case 0:
        func_0010a4e0(0, sound[1], sound[2], sound[3]);
        return;
    case 1:
        func_0010a4e0(1, sound[1], sound[2], sound[3]);
        break;
    }
}
