#include "Battle/btlFade.h"
#include "Kernel/Kwln/kwlnTask.h"

typedef struct BtlFadeWork
{
    u8 state;     // 0x00
    u8 unk_01;    // 0x01
    u16 timer;    // 0x02
    u16 delay;    // 0x04
    s16 fadeType; // 0x06
} BtlFadeWork;

extern void* btlFadeUpdate(KwlnTask* task);

static BtlFadeWork sBtlFadeWork;

// FUN_002ff260
KwlnTask* btlFadeCreateTask(s32 param_1)
{
    KwlnTask* task;

    task = kwlnTaskGetTaskByName("battle_encount_fade");

    if (task == NULL)
    {
        sBtlFadeWork.state = 2;
        sBtlFadeWork.fadeType = param_1;

        task = kwlnTaskCreate(NULL, "battle_encount_fade", 0x1cbf, btlFadeUpdate, NULL, &sBtlFadeWork);
    }

    return task;
}

// FUN_002ff2d0
void btlFadeStart(u16 delay)
{
    sBtlFadeWork.timer = 0;
    sBtlFadeWork.delay = delay;
    sBtlFadeWork.state = 1;
}

// FUN_002ff2f0
void btlFadeStartImmediate(void)
{
    sBtlFadeWork.timer = 0;
    sBtlFadeWork.delay = 0;
    sBtlFadeWork.state = 1;
}

// FUN_002ff310
s32 btlFade002ff310(void)
{
    return 1;
}

// FUN_002ff320
s32 btlFadeIsActive(void)
{
    return sBtlFadeWork.state != 0;
}