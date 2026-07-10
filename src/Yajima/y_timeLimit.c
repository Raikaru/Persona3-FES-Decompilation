#include "Yajima/y_timeLimit.h"

/*
 * The task framework stores the time-limit state pointer at work+0x3C.
 * Keep the explicit padding so these fields remain at their retail offsets.
 */
typedef struct YTimeLimitInner
{
    u8 reserved00[4];
    u8 lifecycleState;
    u8 reserved05[0x3f];
    s16 transitionFrame;
} YTimeLimitInner;

typedef struct YTimeLimitWork
{
    u8 reserved00[0x3c];
    YTimeLimitInner* timeLimit;
} YTimeLimitWork;

extern YTimeLimitWork* iGpffffba08;

enum
{
    /* State 6 makes FUN_0045A020 finish the time-limit task immediately. */
    Y_TIME_LIMIT_STATE_FINISHED = 6,
};

// FUN_0045a400
void Y_TimeLimit_Stop(void)
{
    YTimeLimitInner* timeLimit;

    if (iGpffffba08 != NULL)
    {
        timeLimit = iGpffffba08->timeLimit;
        timeLimit->transitionFrame = 0;
        timeLimit->lifecycleState = Y_TIME_LIMIT_STATE_FINISHED;
    }
}
