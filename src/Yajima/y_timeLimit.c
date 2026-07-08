#include "Yajima/y_timeLimit.h"

typedef struct YTimeLimitInner
{
    u8 pad0[4];
    u8 mode;
    u8 pad5[0x3f];
    s16 field44;
} YTimeLimitInner;

typedef struct YTimeLimitWork
{
    u8 pad0[0x3c];
    YTimeLimitInner* inner;
} YTimeLimitWork;

extern YTimeLimitWork* iGpffffba08;

// FUN_0045a400
void Y_TimeLimit_0045a400()
{
    YTimeLimitInner* inner;

    if (iGpffffba08 != NULL)
    {
        inner = iGpffffba08->inner;
        inner->field44 = 0;
        inner->mode = 6;
    }
}