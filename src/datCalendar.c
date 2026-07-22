#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwln.h"
#include "rw/rwcore.h"
#include "rw/rprandom.h"
#include "Script/scrTraceCode.h"
#include "Event/Comu/comuFunction.h"
#include "Main/admini.h"
#include "Main/g_data.h"
#include "h_cursor.h"
#include "h_dbprt.h"
#include "h_fade.h"
#include "h_maestro.h"
#include "h_pad.h"
#include "h_sfdply.h"
#include "temporary.h"
 
extern u32 D_00960184[];
extern u32 jtbl_0096017C[];
#pragma alias datSetTimeSkipTarget_u8 datSetTimeSkipTarget
extern void datSetTimeSkipTarget_u8(u8 time);
#define CLND_ALLOC(count, size, flags) \
    (*(void* (**)(u32, u32, u32))D_00960184)((count), (size), (flags))
#define CLND_FREE(memory) (*(void (**)(void*))jtbl_0096017C)((memory))

typedef struct
{
    s16 month;
    s16 day;
} Holiday;

// 005e3a40
static const Holiday sHolidays[] = 
{
    {CALENDAR_MONTH_APRIL, 29}, {CALENDAR_MONTH_MAY, 2}, {CALENDAR_MONTH_MAY, 5},
    {CALENDAR_MONTH_JULY, 20}, {CALENDAR_MONTH_JULY, 21}, {CALENDAR_MONTH_JULY, 22},
    {CALENDAR_MONTH_JULY, 23}, {CALENDAR_MONTH_JULY, 26}, {CALENDAR_MONTH_JULY, 27},
    {CALENDAR_MONTH_JULY, 28}, {CALENDAR_MONTH_JULY, 29}, {CALENDAR_MONTH_JULY, 30},
    {CALENDAR_MONTH_JULY, 31}, {CALENDAR_MONTH_AUGUST, 1}, {CALENDAR_MONTH_AUGUST, 2},
    {CALENDAR_MONTH_AUGUST, 3}, {CALENDAR_MONTH_AUGUST, 4}, {CALENDAR_MONTH_AUGUST, 5},
    {CALENDAR_MONTH_AUGUST, 6}, {CALENDAR_MONTH_AUGUST, 7}, {CALENDAR_MONTH_AUGUST, 8},
    {CALENDAR_MONTH_AUGUST, 9}, {CALENDAR_MONTH_AUGUST, 10}, {CALENDAR_MONTH_AUGUST, 11},
    {CALENDAR_MONTH_AUGUST, 12}, {CALENDAR_MONTH_AUGUST, 13}, {CALENDAR_MONTH_AUGUST, 14} ,
    {CALENDAR_MONTH_AUGUST, 15}, {CALENDAR_MONTH_AUGUST, 16}, {CALENDAR_MONTH_AUGUST, 17},
    {CALENDAR_MONTH_AUGUST, 18}, {CALENDAR_MONTH_AUGUST, 19}, {CALENDAR_MONTH_AUGUST, 20},
    {CALENDAR_MONTH_AUGUST, 21}, {CALENDAR_MONTH_AUGUST, 23}, {CALENDAR_MONTH_AUGUST, 24},
    {CALENDAR_MONTH_AUGUST, 25}, {CALENDAR_MONTH_AUGUST, 26}, {CALENDAR_MONTH_AUGUST, 27},
    {CALENDAR_MONTH_AUGUST, 28}, {CALENDAR_MONTH_AUGUST, 29}, {CALENDAR_MONTH_AUGUST, 30},
    {CALENDAR_MONTH_AUGUST, 31}, {CALENDAR_MONTH_SEPTEMBER, 21}, {CALENDAR_MONTH_SEPTEMBER, 22},
    {CALENDAR_MONTH_SEPTEMBER, 23}, {CALENDAR_MONTH_OCTOBER, 12}, {CALENDAR_MONTH_NOVEMBER, 3},
    {CALENDAR_MONTH_NOVEMBER, 17}, {CALENDAR_MONTH_NOVEMBER, 18}, {CALENDAR_MONTH_NOVEMBER, 19},
    {CALENDAR_MONTH_NOVEMBER, 20}, {CALENDAR_MONTH_NOVEMBER, 23}, {CALENDAR_MONTH_DECEMBER, 23},
    {CALENDAR_MONTH_DECEMBER, 27}, {CALENDAR_MONTH_DECEMBER, 28}, {CALENDAR_MONTH_DECEMBER, 29},
    {CALENDAR_MONTH_DECEMBER, 30}, {CALENDAR_MONTH_DECEMBER, 31}, {CALENDAR_MONTH_JANUARY, 1},
    {CALENDAR_MONTH_JANUARY, 2}, {CALENDAR_MONTH_JANUARY, 3}, {CALENDAR_MONTH_JANUARY, 4},
    {CALENDAR_MONTH_JANUARY, 5}, {CALENDAR_MONTH_JANUARY, 6}, {CALENDAR_MONTH_JANUARY, 7},
    {CALENDAR_MONTH_JANUARY, 10}, {CALENDAR_MONTH_JANUARY, 11}, {CALENDAR_MONTH_FEBRUARY, 11},
    {CALENDAR_MONTH_MARCH, 22}, {-1, -1},
};

const s16 gNumOfDaysInMonths[CALENDAR_MONTH_MAX - 1] =
{  /*JAN FEB MAR APR MAY JUN JUL AUG SEP OCT NOV DEC*/
     31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
#pragma alias gNumOfDaysInMonths_abs gNumOfDaysInMonths
extern u8 gNumOfDaysInMonths_abs[];

// 005e38d0. Moon phases from April 5, 2009 through April 4, 2010.
// Values intentionally use MoonPhases' retail enum order; the final four entries are zero.
static const u8 daysMoonPhases[365] =
{
    10, 11, 12, 13, 14, 15, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28,
    29, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 17, 18, 19,
    20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 29, 0, 1,
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 29, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
    12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 29, 0, 1, 2,
    3, 4, 5, 6, 7, 8, 9, 10, 11, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
    22, 23, 24, 25, 26, 27, 29, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
    13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 29, 0, 1, 2, 3,
    4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 17, 18, 19, 20, 21, 22,
    23, 24, 25, 26, 27, 29, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12,
    13, 14, 15, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 0, 1, 2, 3,
    4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
    25, 26, 27, 28, 28, 29, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14,
    15, 0, 0, 0, 0,
};

static KwlnTask* sClndTask; // 007cdfec. Task name = "CalenderDraw"

s32 clndFindAndExecSiteibiEvents();
u32 func_0017db40(s16 daysSinceApr5);
#pragma alias clndGetTimeSigned datGetTime
extern s16 clndGetTimeSigned(void);
KwlnTask* func_0017fc70(KwlnTask* clndTask);
KwlnTask* func_00180a20(KwlnTask* clndTask);
KwlnTask* func_00180c40(KwlnTask* clndTask);
void func_00180e60(void);
KwlnTask* func_00180ee0(KwlnTask* clndTask);
KwlnTask* func_00181010(KwlnTask* clndTask);
KwlnTask* func_00181170(KwlnTask* clndTask);
KwlnTask* func_00181310(KwlnTask* clndTask);
KwlnTask* func_00181430(KwlnTask* clndTask);
KwlnTask* func_00181580(KwlnTask* clndTask, u32* specialAction);
void func_00181b70(void);
void func_001848f0(KwlnTask* task, u32 confirmed);
void func_00184c80(KwlnTask* task, u32 confirmed);
KwlnTask* func_00184db0(KwlnTask* parent);
KwlnTask* func_00187550(KwlnTask* parent);
void* func_00184f00(KwlnTask* task);
void func_00185830(KwlnTask* task);
KwlnTask* func_00185880(KwlnTask* parent, s16 sourceMonth, s16 sourceDay, s16 targetMonth, s16 targetDay);
void func_00185980(void* resource, u64 position, u32 unused, s16 day);
void func_00185ae0(void* resource, u64 position, u32 alpha, s16 day);
void func_00185b40(void* resource, u64 position, u32 unused, s16 month, s16 day);
void func_00186050(void* resource, u64 position, u32 alpha);
void func_00186100(void* resource, u64 position, u32 alpha);
void func_00186140(void* resource, u64 position, u32 alpha);
void* func_00186190(KwlnTask* task);
void func_001868f0(KwlnTask* task);
KwlnTask* func_00186960(KwlnTask* parent, s32 currentValue, s32 targetValue);
void func_00186a40(void* resource, u64 position, u32 alpha, s16 selection);
void func_00186bd0(void* resource, u64 position, u32 alpha, s16 selection);
void* func_00186d50(KwlnTask* task);
void func_00187050(KwlnTask* task);
KwlnTask* func_001870e0(KwlnTask* parent);
void* func_001871a0(KwlnTask* task);
void func_001875f0(s32 angle, s32 scaleAngle, s32 alpha);
void* func_00187be0(KwlnTask* task);
KwlnTask* func_00187e20(void);
void func_00187ec0(KwlnTask* task, s32 month, s32 day, s32 time);
void* func_00188250(KwlnTask* task);
void func_001883d0(KwlnTask* task);
void func_00188420(KwlnTask* task, s32 month, s32 day, s32 time);
KwlnTask* func_00188440(KwlnTask* parent, s32 month, s32 day, s32 time);
KwlnTask* func_00188640(void);
u32 clnd00184d90(KwlnTask* task);
KwlnTask* func_00181950(KwlnTask* clndTask, s32 eventIndex);
typedef struct
{
    u8* records;
    u32 total;
} CalendarDateTable;

extern u16* func_00170620(s16 pcId, s16 index);
extern void func_0016d6b0(s16 socialLink, s16 condition);
extern void func_0027d8d0(void);
extern CalendarDateTable* func_003bd890(void);
extern CalendarDateTable* func_003bd8a0(void);
extern KwlnTask* func_001b7700(KwlnTask* parent);
extern void func_001fa450(void);
extern void func_001a5cd0(void);
extern KwlnTask* func_003c1ab0(KwlnTask* parent, u8 time);
extern KwlnTask* func_003bdd60(u32 priority, u16 procedure);
extern KwlnTask* func_001ba5f0(KwlnTask* parent, ...);
extern u32 func_00195290(KwlnTask* task);
extern void func_00195020(KwlnTask* task);
extern u32 func_00488f30(void);

#define CLND_SCHEDULE_DEFAULTS ((const u8*)0x005e3bc0)
void* clndUpdateTask(KwlnTask* clndTask);
void clndDestroyTask(KwlnTask* clndTask);

// FUN_0017FC70 NONMATCHING
KwlnTask* func_0017fc70(KwlnTask* clndTask)
{
    s32 eventIndex;

    if (datGetSkipToTarget() != 0 || datGetFlag(0xa02) != 0)
    {
        return NULL;
    }

    eventIndex = clndFindAndExecSiteibiEvents();
    if (eventIndex < 0)
    {
        H_Dbprt_FmtLog("calendar: no late-night event");
        return func_003c1ab0(clndTask, datGetTime());
    }

    return func_00181950(clndTask, eventIndex);
}

// FUN_0017FD30 NONMATCHING
u32 func_0017fd30(void)
{
    s16 pcId;
    s16 index;
    const u8* source;
    u16* destination;

    for (pcId = 2; pcId < 0xb; pcId++)
    {
        for (index = 0; index < 0xc; index++)
        {
            source = CLND_SCHEDULE_DEFAULTS + (pcId - 2) * 0x30 + index * 4;
            destination = func_00170620(pcId, index);
            destination[0] = *(const u16*)source;
            destination[1] = *(const u16*)(source + 2);
        }
    }

    return true;
}

// FUN_0017FE10 NONMATCHING
void func_0017fe10(KwlnTask* clndTask)
{
    CalendarDateTable* table;
    const u8* record;
    u32 i;
    s16 month;
    s16 day;
    u16 flag;

    for (i = 0xbd0; i < 0xc00; i++)
    {
        datSetFlag(i, false);
    }
    datSetFlag(0xa01, false);
    datSetFlag(0xa02, false);
    datSetFlag(0xa04, false);

    func_0017fd30();
    table = func_003bd8a0();
    month = clndGetCurrentMonth();
    day = clndGetCurrentDay();
    for (i = 0; i < table->total; i++)
    {
        record = table->records + i * 6;
        if (record[0] == month && record[1] == day)
        {
            flag = *(const u16*)(record + 2);
            if (flag != 0)
            {
                datSetFlag(flag, true);
            }
            flag = *(const u16*)(record + 4);
            if (flag != 0)
            {
                datSetFlag(flag, false);
            }
        }
    }

    func_001b7700(clndTask);
}

// FUN_00180030 NONMATCHING
void func_00180030(void)
{
    CalendarDateTable* table;
    const u8* record;
    u32 i;
    s16 month;
    s16 day;

    table = func_003bd890();
    month = clndGetCurrentMonth();
    day = clndGetCurrentDay();
    for (i = 0; i < table->total; i++)
    {
        record = table->records + i * 4;
        if (record[0] != month || record[1] != day)
        {
            continue;
        }

        if (record[2] == 1)
        {
            datSetFlag(0xa95, false);
            datSetFlag(0xa96, false);
            datSetFlag(0xa97, false);
            datSetFlag(0xa98, false);
            datSetFlag(0xa99, false);
            datSetFlag(0xa9a, false);
            datSetFlag(0xa7a, false);
            datSetFlag(0xa9b, false);
            datSetFlag(0xa9c, false);
            if (record[3] == 5)
            {
                datSetFlag(0xa98, true);
            }
            if (record[3] == 3)
            {
                datSetFlag(0xa99, true);
            }
            if (record[3] == 2)
            {
                datSetFlag(0xa9b, true);
            }
        }

        func_0016d6b0(record[2], record[3]);
    }
}

// FUN_00180220 NONMATCHING
void func_00180220(void)
{
    CalendarDateTable* table;
    const u8* record;
    u32 i;
    s16 socialLink;
    s16 oldCondition;
    s16 newCondition;
    s32 value;
    s32 amount;
    u32 randomValue;
    u32 found;

    for (socialLink = 1; socialLink <= 10; socialLink++)
    {
        found = false;
        table = func_003bd890();
        for (i = 0; i < table->total; i++)
        {
            record = table->records + i * 4;
            if (record[0] == clndGetCurrentMonth() &&
                record[1] == clndGetCurrentDay() &&
                record[2] == socialLink)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            continue;
        }

        oldCondition = func_0016c920(socialLink);
        newCondition = oldCondition;
        value = FUN_0016f380(socialLink + 0x19);
        FUN_0016f3e0(socialLink + 0x19, value);

        if (oldCondition == 2)
        {
            value = FUN_0016f380(socialLink + 0xf) - 1;
            if (value < 0)
            {
                value = 0;
            }
            FUN_0016f3e0(socialLink + 0xf, value);
            if (value == 0)
            {
                newCondition = 0;
            }
        }
        else if (oldCondition == 3)
        {
            value = FUN_0016f380(socialLink + 0x19);
            if (value < 0)
            {
                value = 0;
            }
            FUN_0016f3e0(socialLink + 0x19, value);
            if (socialLink == 3)
            {
                randomValue = func_00488f30();
                value = FUN_0016f380(0x12);
                amount = value - (randomValue % 20 + 25);
                if (amount < 0)
                {
                    amount = 0;
                }
                FUN_0016f3e0(0x12, amount);
                if (amount == 0)
                {
                    newCondition = 0;
                }
            }
            else
            {
                randomValue = func_00488f30();
                if (randomValue % 100 < 0x15)
                {
                    newCondition = 5;
                }
                else
                {
                    value = FUN_0016f380(socialLink + 0xf);
                    amount = value - (randomValue % 20 + 25);
                    if (amount < 0)
                    {
                        amount = 0;
                    }
                    FUN_0016f3e0(socialLink + 0xf, amount);
                    if (amount == 0)
                    {
                        newCondition = 0;
                    }
                }
            }
            if (socialLink == 1 && datGetFlag(0xa9e) != 0)
            {
                newCondition = 0;
            }
        }
        else if (oldCondition == 5)
        {
            value = FUN_0016f380(socialLink + 0x19);
            if (value < 0)
            {
                value = 0;
            }
            FUN_0016f3e0(socialLink + 0x19, value);
            randomValue = func_00488f30();
            value = FUN_0016f380(socialLink + 0xf);
            amount = value - (randomValue % 40 + 20);
            if (socialLink == 1)
            {
                if (datGetFlag(0xa8e) == 0)
                {
                    if (datGetFlag(0xa8f) != 0)
                    {
                        amount -= 60;
                    }
                }
                else
                {
                    amount -= 30;
                }
            }
            else
            {
                if (datGetFlag(0xa2e - socialLink) != 0)
                {
                    amount -= 30;
                }
                if (datGetFlag(0xa40 - socialLink) != 0)
                {
                    amount -= 60;
                }
            }
            if (amount < 1)
            {
                amount = 0;
            }
            FUN_0016f3e0(socialLink + 0xf, amount);
            if (amount == 0)
            {
                newCondition = 0;
            }
            if (socialLink == 1 && datGetFlag(0xa9e) != 0)
            {
                newCondition = 0;
            }
        }

        if (socialLink != 3 && FUN_0016f380(socialLink + 0x19) > 99)
        {
            newCondition = 2;
        }
        func_0016d6b0(socialLink, newCondition);

        if (socialLink == 1)
        {
            datSetFlag(0xa95, false);
            datSetFlag(0xa96, false);
            datSetFlag(0xa97, false);
            datSetFlag(0xa98, false);
            datSetFlag(0xa99, false);
            datSetFlag(0xa9a, false);
            datSetFlag(0xa9b, false);
            datSetFlag(0xa9c, false);
            datSetFlag(0xa9f, false);
            datSetFlag(0xacd, false);
            datSetFlag(0xace, false);
            if (datGetFlag(0xa7a) != 0)
            {
                func_0016d6b0(1, 2);
            }
            else if (newCondition == 2 && oldCondition == 0)
            {
                datSetFlag(0xa9b, true);
            }
            else if (newCondition == 3 && oldCondition == 3)
            {
                datSetFlag(0xa9d, true);
            }
            else if (newCondition == 5 && oldCondition == 3)
            {
                datSetFlag(0xa97, true);
            }
            else if (newCondition == 5 && oldCondition == 5)
            {
                datSetFlag(0xa96, true);
            }
            else if (newCondition == 0 && oldCondition == 2)
            {
                datSetFlag(0xa9c, true);
            }
            else if (newCondition == 0 && oldCondition == 3)
            {
                if (datGetFlag(0xa9e) == 0)
                {
                    datSetFlag(0xa9a, true);
                }
                else
                {
                    datSetFlag(0xacd, true);
                }
            }
            else if (newCondition == 0 && oldCondition == 5)
            {
                if (datGetFlag(0xa8e) == 0 && datGetFlag(0xa8f) == 0)
                {
                    if (datGetFlag(0xa9e) == 0)
                    {
                        datSetFlag(0xa95, true);
                    }
                    else
                    {
                        datSetFlag(0xa9f, true);
                    }
                }
                else
                {
                    datSetFlag(0xace, true);
                }
            }
        }

        if (socialLink == 1)
        {
            datSetFlag(0xa8e, false);
            datSetFlag(0xa8f, false);
            datSetFlag(0xa9e, false);
        }
        else
        {
            datSetFlag(0xa2e - socialLink, false);
            datSetFlag(0xa40 - socialLink, false);
        }
    }

    datSetFlag(0x141c, true);
}

// FUN_00180A20 NONMATCHING
KwlnTask* func_00180a20(KwlnTask* clndTask)
{
    CalendarTaskWork* work;
    s32 eventIndex;

    work = clndTask->workData;
    datSetFlag(0xa80, false);
    datSetFlag(0xa81, false);
    datSetFlag(0xa82, false);
    datSetFlag(0xa83, false);
    datSetFlag(0xa84, false);
    datSetFlag(0xa85, false);
    datSetFlag(0xa86, false);
    datSetFlag(0xa87, false);

    if (datGetSkipToTarget() == 0)
    {
        eventIndex = clndFindAndExecSiteibiEvents();
        if (eventIndex >= 0)
        {
            return func_00181950(clndTask, eventIndex);
        }
        if (datGetFlag(0xa00) != 0)
        {
            return NULL;
        }
        if (datGetFlag(0x1403) == 0)
        {
            datSetFlag(0x1403, true);
            datSetDaysSkipTarget(datGetDaysSinceApr5());
            datSetTimeSkipTarget(datGetTime());
            datSetSkipToTarget(true);
            if (datGetFlag(0xbdf) != 0)
            {
                if (datGetTime() == CALENDAR_TIME_NULL)
                {
                    func_00184c80(work->confirmationTask, true);
                }
                else
                {
                    func_001848f0(work->confirmationTask, true);
                }
                return func_001ba5f0(clndTask, 0, 0, 0, 0, 0, 0, 0);
            }
        }
    }

    return NULL;
}

// FUN_00180C40
KwlnTask* func_00180c40(KwlnTask* clndTask)
{
    CalendarTaskWork* work;
    s32 eventIndex;

    work = clndTask->workData;
    printf("calendar: early morning");
    datSetFlag(0xa80, true);
    datSetFlag(0xa81, false);
    datSetFlag(0xa82, false);
    datSetFlag(0xa83, false);
    datSetFlag(0xa84, false);
    datSetFlag(0xa85, false);
    datSetFlag(0xa86, false);
    datSetFlag(0xa87, false);

    if (datGetFlag(0x1402) == 0)
    {
        datSetFlag(0x1402, true);
        datSetFlag(0xbd2, false);
        func_0027d8d0();
        func_001fa450();
        func_0017fe10(clndTask);
        work->validateSkipTarget = false;
        goto calendar_done;
    }
    else
    {
        if (datGetFlag(0x1406) == 0)
        {
            datSetFlag(0x1406, true);
            func_00180220();
            func_001a5cd0();
        }
        if (datGetFlag(0x1405) == 0)
        {
            datSetFlag(0x1405, true);
            func_00180030();
        }
        if (datGetSkipToTarget() == 0)
        {
            eventIndex = clndFindAndExecSiteibiEvents();
            if (eventIndex != -1)
            {
                return func_00181950(clndTask, eventIndex);
            }
            if (func_0017db40(clndGetTimeSigned()) != 0)
            {
                goto early_morning_time;
            }
            return func_003c1ab0(clndTask, datGetTime() & 0xff);
early_morning_time:
            return func_003c1ab0(clndTask, datGetTime() & 0xff);
        }
    }

    return NULL;
calendar_done:
    ;
}

// FUN_00180E60
void func_00180e60(void)
{
    datSetFlag(0x1402, false);
    datSetFlag(0x1403, false);
    datSetFlag(0x1404, false);
    datSetFlag(0x1405, false);
    datSetFlag(0x1406, false);
    datSetFlag(0xa00, false);
}

// FUN_00180EE0 NONMATCHING
KwlnTask* func_00180ee0(KwlnTask* clndTask)
{
    s32 eventIndex;

    H_Dbprt_FmtLog("calendar: morning");
    datSetFlag(0xa80, false);
    datSetFlag(0xa81, true);
    datSetFlag(0xa82, false);
    datSetFlag(0xa83, false);
    datSetFlag(0xa84, false);
    datSetFlag(0xa85, false);
    datSetFlag(0xa86, false);
    datSetFlag(0xa87, false);

    if (datGetSkipToTarget() != 0)
    {
        return NULL;
    }
    eventIndex = clndFindAndExecSiteibiEvents();
    if (eventIndex < 0)
    {
        return func_003c1ab0(clndTask, datGetTime());
    }
    return func_00181950(clndTask, eventIndex);
}

// FUN_00181010
KwlnTask* func_00181010(KwlnTask* clndTask)
{
    s32 eventIndex;
    KwlnTask* result;

    result = NULL;
    datSetFlag(0xa80, false);
    datSetFlag(0xa81, false);
    datSetFlag(0xa82, true);
    datSetFlag(0xa83, false);
    datSetFlag(0xa84, false);
    datSetFlag(0xa85, false);
    datSetFlag(0xa86, false);
    datSetFlag(0xa87, false);
    if (datGetSkipToTarget() == 0)
    {
        printf("calendar: lunch");
        eventIndex = clndFindAndExecSiteibiEvents();
        if (eventIndex != -1)
        {
            return func_00181950(clndTask, eventIndex);
        }
        if ((datGetDaysSinceApr5() + 7) % 7 == 6)
        {
            return NULL;
        }
        result = func_003c1ab0(clndTask, datGetTime() & 0xff);
    }
    return result;
}

// FUN_00181170
KwlnTask* func_00181170(KwlnTask* clndTask)
{
    KwlnTask* result;
    s32 eventIndex;

    result = NULL;
    datSetFlag(0xa80, false);
    datSetFlag(0xa81, false);
    datSetFlag(0xa82, false);
    datSetFlag(0xa83, true);
    datSetFlag(0xa84, false);
    datSetFlag(0xa85, false);
    datSetFlag(0xa86, false);
    datSetFlag(0xa87, false);
    if (datGetSkipToTarget() == 0)
    {
        printf("calendar: afternoon");
        eventIndex = clndFindAndExecSiteibiEvents();
        if (eventIndex != -1)
        {
            return func_00181950(clndTask, eventIndex);
        }
        if (func_0017db40(datGetDaysSinceApr5()) != 0)
        {
            result = func_003c1ab0(clndTask, datGetTime() & 0xff);
            goto ret;
        }
        if ((datGetDaysSinceApr5() + 7) % 7 == 6)
        {
            return NULL;
        }
        result = func_003c1ab0(clndTask, datGetTime() & 0xff);
    }
ret:
    return result;
}

// FUN_00181310 NONMATCHING
KwlnTask* func_00181310(KwlnTask* clndTask)
{
    s32 eventIndex;

    datSetFlag(0xa80, false);
    datSetFlag(0xa81, false);
    datSetFlag(0xa82, false);
    datSetFlag(0xa83, false);
    datSetFlag(0xa84, true);
    datSetFlag(0xa85, false);
    datSetFlag(0xa86, false);
    datSetFlag(0xa87, false);
    H_Dbprt_FmtLog("calendar: after school");

    if (datGetSkipToTarget() != 0)
    {
        return NULL;
    }
    eventIndex = clndFindAndExecSiteibiEvents();
    if (eventIndex < 0)
    {
        return func_003c1ab0(clndTask, datGetTime());
    }
    return func_00181950(clndTask, eventIndex);
}

// FUN_00181430
KwlnTask* func_00181430(KwlnTask* clndTask)
{
    KwlnTask* result;
    s32 eventIndex;

    result = NULL;
    datSetFlag(0xa80, false);
    datSetFlag(0xa81, false);
    datSetFlag(0xa82, false);
    datSetFlag(0xa83, false);
    datSetFlag(0xa84, false);
    datSetFlag(0xa85, true);
    datSetFlag(0xa86, false);
    datSetFlag(0xa87, false);
    printf("calendar: evening");
    if (datGetSkipToTarget() != 0)
    {
        goto done;
    }
    if (datGetFlag(0xa01) != 1)
    {
        eventIndex = clndFindAndExecSiteibiEvents();
        if (eventIndex != -1)
        {
            return func_00181950(clndTask, eventIndex);
        }
        result = func_003c1ab0(clndTask, datGetTime() & 0xff);
    }
    datSetFlag(0xa01, false);
done:
    return result;
}

// FUN_00181580 NONMATCHING
KwlnTask* func_00181580(KwlnTask* clndTask, u32* specialAction)
{
    u32 sequenceData[2];
    s32 eventIndex;

    *specialAction = false;
    datSetFlag(0xa80, false);
    datSetFlag(0xa81, false);
    datSetFlag(0xa82, false);
    datSetFlag(0xa83, false);
    datSetFlag(0xa84, false);
    datSetFlag(0xa85, false);
    datSetFlag(0xa86, false);
    datSetFlag(0xa87, true);

    if (datGetSkipToTarget() != 0)
    {
        return NULL;
    }
    if (datGetFlag(0xa05) != 0)
    {
        sequenceData[0] = 1;
        sequenceData[1] = 0;
        adminiChangeSeq(ADMINI_SEQ_DUNGEON, sequenceData, 8, false);
        *specialAction = true;
        datSetFlag(0xa05, false);
        return NULL;
    }
    if (datGetFlag(0xa03) != 0)
    {
        datSetFlag(0xa03, false);
        eventIndex = clndFindAndExecSiteibiEvents();
        if (eventIndex < 0)
        {
            return func_003c1ab0(clndTask, datGetTime());
        }
        return func_00181950(clndTask, eventIndex);
    }

    return NULL;
}

// FUN_00181950 NONMATCHING
KwlnTask* func_00181950(KwlnTask* clndTask, s32 eventIndex)
{
    CalendarTaskWork* work;
    SiteibiEvent* event;
    KwlnTask* actionTask;

    work = clndTask->workData;
    event = &Comu_GetSiteibiEvtTable()->events[eventIndex];
    if (event->unk_07 == 0xff)
    {
        H_Dbprt_FmtLog("calendar: siteibi procedure %d", event->scrPrcdIdx);
        actionTask = func_003bdd60(0xf, event->scrPrcdIdx);
    }
    else
    {
        H_Dbprt_FmtLog("calendar: siteibi event %d", event->scrPrcdIdx);
        actionTask = func_001ba5f0(clndTask, 0, 0, 0, 0, 0, 0, 0);
        if (datGetTime() == CALENDAR_TIME_NULL)
        {
            func_00184c80(work->confirmationTask, true);
        }
        else
        {
            func_001848f0(work->confirmationTask, true);
        }
    }

    datSetDaysSkipTarget(clndGetDaysSinceStartFromDate(event->endMonth, event->endDay));
    datSetTimeSkipTarget(event->endTime);
    datSetSkipToTarget(true);
    return actionTask;
}

// FUN_0017DB40 NONMATCHING
u32 func_0017db40(s16 daysSinceApr5)
{
    s32 month;
    s32 day;
    s32 i;

    if (clndGetWeekDay(daysSinceApr5) == CALENDAR_DAY_SUNDAY)
    {
        return true;
    }

    month = clndGetMonthFromDaysSinceApr5(daysSinceApr5);
    day = clndGetDayOfMonthFromDaysSinceApr5(daysSinceApr5);
    for (i = 0; sHolidays[i].month != -1; i++)
    {
        if (sHolidays[i].month == month && sHolidays[i].day == day)
        {
            return true;
        }
    }

    return false;
}

// FUN_0017DDF0 NONMATCHING
u32 func_0017ddf0(s16* monthOut, s16* dayOut)
{
    s16 currentDay;
    s16 nextDay;
    s16 month;
    s16 day;

    currentDay = datGetDaysSinceApr5();
    for (;;)
    {
        nextDay = currentDay + 1;
        if (nextDay > 0x15e)
        {
            return false;
        }

        if (func_0017db40(nextDay))
        {
            currentDay += 5;
            month = clndGetMonthFromDaysSinceApr5(currentDay);
            day = clndGetDayOfMonthFromDaysSinceApr5(currentDay);
            *monthOut = month;
            *dayOut = day;
            return true;
        }

        currentDay = nextDay;
    }
}

// FUN_0017E050 NONMATCHING
u32 func_0017e050(s32 category, s16 month, s32 day)
{
    s16 daysSinceApr5;
    s16 daysBeforeMonth;
    s16 currentMonth;
    s16 dayOfWeek;
    s16 week;
    s16 i;

    daysSinceApr5 = datGetDaysSinceApr5() + 4;
    daysBeforeMonth = 0;
    currentMonth = CALENDAR_MONTH_APRIL;
    while (daysSinceApr5 >= gNumOfDaysInMonths[currentMonth - 1])
    {
        daysSinceApr5 -= gNumOfDaysInMonths[currentMonth - 1];
        daysBeforeMonth += gNumOfDaysInMonths[currentMonth - 1];
        currentMonth++;
        if (currentMonth >= CALENDAR_MONTH_MAX)
        {
            currentMonth = CALENDAR_MONTH_JANUARY;
        }
    }

    dayOfWeek = (daysBeforeMonth + 3) % CALENDAR_DAY_MAX;
    week = 0;
    for (i = 0; i < daysSinceApr5; i++)
    {
        dayOfWeek++;
        if (dayOfWeek == CALENDAR_DAY_MAX)
        {
            week++;
            dayOfWeek = CALENDAR_DAY_SUNDAY;
        }
    }

    if (category == 0x65)
    {
        return clndGetCurrentWeekDay() != CALENDAR_DAY_SUNDAY;
    }
    if (category == 100)
    {
        return func_0017db40(datGetDaysSinceApr5());
    }
    if (category >= 1 && category <= 7)
    {
        return clndGetCurrentWeekDay() == (category - 1);
    }
    if (category == 0)
    {
        return daysBeforeMonth == month && daysSinceApr5 + 1 == day;
    }

    return week == category / 10 - 1 &&
           clndGetCurrentWeekDay() == category % 10 - 1;
}

// FUN_0017F8D0 NONMATCHING
void func_0017f8d0(void)
{
    CalendarTaskWork* work;

    if (sClndTask == NULL)
    {
        return;
    }

    work = sClndTask->workData;
    if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
    {
        if (work->state != CLNDTASK_STATE_WAIT_SKIP_CONFIRM)
        {
            work->state = CLNDTASK_STATE_CONFIRM_DAY_CHANGE;
        }
    }
    else if (work->state != CLNDTASK_STATE_BEGIN_DAY)
    {
        work->state = CLNDTASK_STATE_DEBUG_WAIT_CLOSE;
    }

    if (work->actionTask != NULL)
    {
        kwlnTaskDestroyWithHierarchy(work->actionTask);
        work->actionTask = NULL;
    }
}

// FUN_0017F990
u32 func_0017f990(void)
{
    CalendarTaskWork* work;

    if (sClndTask == NULL)
    {
        return true;
    }

    if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
    {
        work = sClndTask->workData;
        work->stopDelay = 0x3c;
        work->state = CLNDTASK_STATE_STOP_DELAY;
    }
    else
    {
        work = sClndTask->workData;
        work->debugCursorBg = (KwlnTask*)(uintptr_t)0x3c;
        work->state = CLNDTASK_STATE_BEGIN_DAY_08;
    }

    return true;
}

// FUN_0017FAD0
KwlnTask* func_0017fad0(void)
{
    KwlnTask* task;
    CalendarTaskWork* work;

    work = RwCalloc(1, sizeof(CalendarTaskWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(NULL, 0x106f, "CalenderDraw",
                                          clndUpdateTask, clndDestroyTask, work);
    if (task == NULL)
    {
        return NULL;
    }

    sClndTask = task;
    work->state = CLNDTASK_STATE_DEBUG_WAIT_CLOSE;
    H_SfdPlay_CreateTaskIdle(task);
    return task;
}

#define CLND_SKIP_TRANSITION_ACTIVE DAT_007cdffc
extern u32 DAT_007cdffc;


 
// FUN_0017d830 NONMATCHING
s32 clndGetMonthFromDaysSinceApr5(s32 daysSinceApr5)
{
    s16 month;
    s16 days;
    const s16* numOfDays;

    month = CALENDAR_MONTH_APRIL;
    days = daysSinceApr5 + 4;
    numOfDays = gNumOfDaysInMonths;

    while (true)
    {
        if (days < numOfDays[month - 1])
        {
            break;
        }

        days -= numOfDays[month - 1];
        month++;

        if (month >= CALENDAR_MONTH_MAX)
        {
            month = CALENDAR_MONTH_JANUARY;
        }
    }

    return month;
}

#pragma push
#pragma opt_propagation off
// FUN_0017d8b0 NONMATCHING
s32 clndGetDaysSinceStartFromDate(s32 month, s32 day)
{
    s32 dayAccumulator = 0;
    s32 m = CALENDAR_MONTH_APRIL;
    const s16* numOfDays = (const s16*)gNumOfDaysInMonths_abs;
    register s32 monthEnd = CALENDAR_MONTH_MAX;
    register s32 monthsInYear = CALENDAR_MONTH_DECEMBER;
    register s32 firstMonth = CALENDAR_MONTH_JANUARY;
    s32 startMonth;
    startMonth = m;

    for (;;)
    {
        if (month == startMonth)
        {
            break;
        }

        dayAccumulator += numOfDays[m - 1];
        m++;
        month--;

        if (month == 0)
        {
            month = monthsInYear;
        }
        if (m == monthEnd)
        {
            m = firstMonth;
        }
    }

    return dayAccumulator + (day - 5); // - 5 because the game starts in april 5th
}
#pragma pop

// FUN_0017d920 NONMATCHING
u32 clndGetCurrentMonth()
{
    s16 month;
    s16 daysSinceApr5;
    const s16* numOfDays;

    daysSinceApr5 = datGetDaysSinceApr5() + 4;
    month = CALENDAR_MONTH_APRIL;
    numOfDays = gNumOfDaysInMonths;
    while (true)
    {
        if (daysSinceApr5 < numOfDays[month - 1])
        {
            break;
        }

        daysSinceApr5 -= numOfDays[month - 1];
        month++;
        if (month >= CALENDAR_MONTH_MAX)
        {
            month = CALENDAR_MONTH_JANUARY;
        }
    }

    return month;
}

// FUN_0017d9c0 NONMATCHING
s32 clndGetDayOfMonthFromDaysSinceApr5(s32 daysSinceApr5)
{
    s16 month;
    s16 days;
    const s16* numOfDays;

    month = CALENDAR_MONTH_APRIL;
    days = daysSinceApr5 + 4;
    numOfDays = gNumOfDaysInMonths;

    while (true)
    {
        if (days < numOfDays[month - 1])
        {
            break;
        }

        days -= numOfDays[month - 1];
        month++;

        if (month >= CALENDAR_MONTH_MAX)
        {
            month = CALENDAR_MONTH_JANUARY;
        }
    }

    return days + 1;
}

// FUN_0017da40. Return the current day of the month NONMATCHING
u32 clndGetCurrentDay()
{
    s16 month;
    s16 daysSinceApr5;
    const s16* numOfDays;

    daysSinceApr5 = datGetDaysSinceApr5() + 4;
    month = CALENDAR_MONTH_APRIL;
    numOfDays = gNumOfDaysInMonths;
    while (true)
    {
        if (daysSinceApr5 < numOfDays[month - 1])
        {
            break;
        }

        daysSinceApr5 -= numOfDays[month - 1];
        month++;
        if (month >= CALENDAR_MONTH_MAX)
        {
            month = CALENDAR_MONTH_JANUARY;
        }
    }

    return daysSinceApr5 + 1;
}

// FUN_0017dae0
s32 clndGetWeekDay(s32 daysSinceApr5)
{
    return (daysSinceApr5 + CALENDAR_DAY_MAX) % CALENDAR_DAY_MAX;
}

// FUN_0017db00
u32 clndGetCurrentWeekDay()
{
    s32 daysSinceApr5 = datGetDaysSinceApr5();

    return (daysSinceApr5 + CALENDAR_DAY_MAX) % CALENDAR_DAY_MAX;
}

// FUN_0017dcf0 NONMATCHING
u8 clndIsHolidayOrSunday()
{
    s16 daysSinceApr5;
    s16 currDayOfMonth;
    s16 currMonth;
    s16 i;

    daysSinceApr5 = datGetDaysSinceApr5();
    if ((daysSinceApr5 + CALENDAR_DAY_MAX) % CALENDAR_DAY_MAX == CALENDAR_DAY_SUNDAY)
    {
        return true;
    }

    currMonth = clndGetMonthFromDaysSinceApr5(daysSinceApr5);
    currDayOfMonth = clndGetDayOfMonthFromDaysSinceApr5(daysSinceApr5);
    for (i = 0; i < 0x164; i++)
    {
        if (sHolidays[i].month == -1)
        {
            break;
        }
        if (currMonth == sHolidays[i].month && currDayOfMonth == sHolidays[i].day)
        {
            return true;
        }
    }

    return false;
}

// FUN_0017e480
u32 clndIsDateInRange(u32 startMonth, u32 startDay, u32 endMonth, u32 endDay)
{
    s32 startDate = clndGetDaysSinceStartFromDate(startMonth, startDay);
    s32 endDate = clndGetDaysSinceStartFromDate(endMonth, endDay);

    if (datGetDaysSinceApr5() >= startDate && datGetDaysSinceApr5() <= endDate)
    {
        return true;
    }

    return false;
}

// FUN_0017e520
u8 clndIsDateInRangeFromDate(u32 monthToTest, u32 dayToTest,
                                  u32 startMonth, u32 startDay,
                                  u32 endMonth, u32 endDay)
{
    s32 startDate = clndGetDaysSinceStartFromDate(startMonth, startDay);
    s32 endDate = clndGetDaysSinceStartFromDate(endMonth, endDay);
    s32 testDate = clndGetDaysSinceStartFromDate(monthToTest, dayToTest);

    if (testDate >= startDate && testDate <= endDate)
    {
        return true;
    }

    return false;
}

// FUN_0017e5d0
u8 clndIsDateInRangeFromStart(u32 month, u32 day, u32 range)
{
    s32 startDate;
    s32 endDate;

    if (range == 0)
    {
        H_Dbprt_FmtLog("Calender chk range is 0");
        return false;
    }

    startDate = clndGetDaysSinceStartFromDate(month, day);
    endDate = startDate + (range - 1);

    if (datGetDaysSinceApr5() >= startDate && datGetDaysSinceApr5() <= endDate)
    {
        return true;
    }

    return false;
}

// FUN_0017e680 NONMATCHING
void* clndUpdateTask(KwlnTask* clndTask)
{
    CalendarTaskWork* work = clndTask->workData;
    s16 daysSinceApr5;
    s16 dayOfMonth;
    s16 month;
    s16 totalDaysBeforeMonth;
    s16 dayOfWeek;
    s16 i;
    RwV2d pos;
    u16 padState;
    u32 specialAction;
    KwlnTask* actionTask;

    switch (work->state)
    {
        case CLNDTASK_STATE_DEBUG_INIT:
            pos.x = 21.0f;
            pos.y = 84.0f;
            work->debugCursorBg = H_Cursor_CreateTask(clndTask,
                                                       2.0f,
                                                       pos,
                                                       (RwRect){0, 0, 252, 168},
                                                       (RwRGBA){0, 0, 100, 255});
            work->debugCursor = H_Cursor_CreateTask(clndTask,
                                                     1.0f,
                                                     pos,
                                                     (RwRect){0, 0, 36, 12},
                                                     (RwRGBA){120, 0, 0, 255});
            work->state = CLNDTASK_STATE_DEBUG_UPDATE;
            break;

        case CLNDTASK_STATE_DEBUG_UPDATE:
            padState = *(u16*)0x007e0952;
            if (padState & 0x8000)
            {
                daysSinceApr5 = datGetDaysSinceApr5() - 1;
                datSetDaysSinceApr5(daysSinceApr5);
                if (datGetDaysSinceApr5() < 0)
                {
                    datSetDaysSinceApr5(364);
                }
            }
            else if (padState & 0x2000)
            {
                daysSinceApr5 = datGetDaysSinceApr5() + 1;
                datSetDaysSinceApr5(daysSinceApr5);
                if (datGetDaysSinceApr5() > 364)
                {
                    datSetDaysSinceApr5(0);
                }
            }
            else if (padState & 0x1000)
            {
                daysSinceApr5 = datGetDaysSinceApr5() - 7;
                datSetDaysSinceApr5(daysSinceApr5);
                if (datGetDaysSinceApr5() < 0)
                {
                    datSetDaysSinceApr5(0);
                }
            }
            else if (padState & 0x4000)
            {
                daysSinceApr5 = datGetDaysSinceApr5() + 7;
                datSetDaysSinceApr5(daysSinceApr5);
                if (datGetDaysSinceApr5() > 364)
                {
                    datSetDaysSinceApr5(364);
                }
            }
            else if (padState & 0x4)
            {
                if (datGetTime() == CALENDAR_TIME_NULL)
                {
                    datSetTime(CALENDAR_TIME_DARK_HOUR);
                    if (datGetDaysSinceApr5() != 0)
                    {
                        datSetDaysSinceApr5(datGetDaysSinceApr5() - 1);
                    }
                }
                else
                {
                    datSetTime(datGetTime() - 1);
                }
            }
            else if (padState & 0x8)
            {
                if (datGetTime() == CALENDAR_TIME_DARK_HOUR)
                {
                    datSetTime(CALENDAR_TIME_NULL);
                    if (datGetDaysSinceApr5() != 0)
                    {
                        datSetDaysSinceApr5(datGetDaysSinceApr5() + 1);
                    }
                }
                else
                {
                    datSetTime(datGetTime() + 1);
                }
            }
            else if (padState & 0x1)
            {
                if (clndGetMonthFromDaysSinceApr5(datGetDaysSinceApr5()) != CALENDAR_MONTH_APRIL)
                {
                    month = clndGetMonthFromDaysSinceApr5(datGetDaysSinceApr5());
                    datSetDaysSinceApr5(datGetDaysSinceApr5() - gNumOfDaysInMonths[month - 1]);
                    if (datGetDaysSinceApr5() < 0)
                    {
                        datSetDaysSinceApr5(0);
                    }
                }
            }
            else if (padState & 0x2)
            {
                if (clndGetMonthFromDaysSinceApr5(datGetDaysSinceApr5()) != CALENDAR_MONTH_MARCH)
                {
                    month = clndGetMonthFromDaysSinceApr5(datGetDaysSinceApr5());
                    datSetDaysSinceApr5(datGetDaysSinceApr5() + gNumOfDaysInMonths[month - 1]);
                    if (datGetDaysSinceApr5() > 364)
                    {
                        datSetDaysSinceApr5(364);
                    }
                }
            }
            else if (*(u16*)0x007e094e & 0x40)
            {
                datSetFlag(0x141d, false);
                work->state = CLNDTASK_STATE_DEBUG_WAIT_OPEN;
            }

            daysSinceApr5 = datGetDaysSinceApr5() + 4;
            totalDaysBeforeMonth = 0;
            month = CALENDAR_MONTH_APRIL;
            while (daysSinceApr5 >= gNumOfDaysInMonths[month - 1])
            {
                daysSinceApr5 -= gNumOfDaysInMonths[month - 1];
                totalDaysBeforeMonth += gNumOfDaysInMonths[month - 1];
                month++;
                if (month >= CALENDAR_MONTH_MAX)
                {
                    month = CALENDAR_MONTH_JANUARY;
                }
            }

            dayOfWeek = (totalDaysBeforeMonth + 3) % CALENDAR_DAY_MAX;
            pos.x = dayOfWeek * 3.0f + 2.0f;
            pos.y = 9.0f;
            for (i = 0; i < gNumOfDaysInMonths[month - 1]; i++)
            {
                H_Dbprt_FmtAt(pos, "%3d", i + 1);
                pos.x += 3.0f;
                dayOfWeek++;
                if (dayOfWeek >= CALENDAR_DAY_MAX)
                {
                    dayOfWeek -= CALENDAR_DAY_MAX;
                    pos.x -= 21.0f;
                    pos.y += 2.0f;
                }
            }

            H_Dbprt_FmtAt((RwV2d){2.0f, 7.0f}, "%2d/%3d", month, daysSinceApr5 + 1, datGetTime());
            switch (datGetTime())
            {
                case CALENDAR_TIME_NULL:          H_Dbprt_FmtAt((RwV2d){10.0f, 7.0f}, "(SOUCHOU)"); break;
                case CALENDAR_TIME_EARLY_MORNING: H_Dbprt_FmtAt((RwV2d){10.0f, 7.0f}, "(ASA)"); break;
                case CALENDAR_TIME_MORNING:       H_Dbprt_FmtAt((RwV2d){10.0f, 7.0f}, "(GOZEN)"); break;
                case CALENDAR_TIME_LUNCH:         H_Dbprt_FmtAt((RwV2d){10.0f, 7.0f}, "(GOGO)"); break;
                case CALENDAR_TIME_AFTERNOON:     H_Dbprt_FmtAt((RwV2d){10.0f, 7.0f}, "(YORU)"); break;
                case CALENDAR_TIME_AFTER_SCHOOL:  H_Dbprt_FmtAt((RwV2d){10.0f, 7.0f}, "(SINYA)"); break;
                case CALENDAR_TIME_EVENING:       H_Dbprt_FmtAt((RwV2d){10.0f, 7.0f}, "(25)"); break;
                case CALENDAR_TIME_LATE_NIGHT:    H_Dbprt_FmtAt((RwV2d){10.0f, 7.0f}, "NO."); break;
                case CALENDAR_TIME_DARK_HOUR:     H_Dbprt_FmtAt((RwV2d){10.0f, 7.0f}, "PS2D"); break;
            }

            pos.x = dayOfWeek * 36.0f + 24.0f;
            pos.y = 108.0f;
            for (i = 0; i < daysSinceApr5; i++)
            {
                pos.x += 36.0f;
                dayOfWeek++;
                if (dayOfWeek == CALENDAR_DAY_MAX)
                {
                    dayOfWeek = CALENDAR_DAY_SUNDAY;
                    pos.y += 24.0f;
                    pos.x -= 252.0f;
                }
            }
            H_Cursor_SetPos(work->debugCursor, pos);
            break;

        case CLNDTASK_STATE_DEBUG_WAIT_OPEN:
            if (work->confirmationTask == NULL)
            {
                work->confirmationTask = func_00184db0(clndTask);
            }
            if (!clnd00184d90(work->confirmationTask))
            {
                return KWLNTASK_CONTINUE;
            }
            work->state = CLNDTASK_STATE_DEBUG_WAIT_CLOSE;
            break;

        case CLNDTASK_STATE_DEBUG_WAIT_CLOSE:
            if (work->confirmationTask == NULL)
            {
                work->confirmationTask = func_00184db0(clndTask);
            }
            if (!clnd00184d90(work->confirmationTask))
            {
                return KWLNTASK_CONTINUE;
            }
            if (datGetSkipToTarget() == 0)
            {
                func_00184c80(work->confirmationTask, true);
            }
            else
            {
                H_Dbprt_FmtLog("####  next time");
            }
            if (work->debugCursorBg != NULL)
            {
                kwlnTaskDestroyWithHierarchy(work->debugCursorBg);
            }
            if (work->debugCursor != NULL)
            {
                kwlnTaskDestroyWithHierarchy(work->debugCursor);
            }
            work->debugCursorBg = NULL;
            work->debugCursor = NULL;
            work->state = CLNDTASK_STATE_BEGIN_DAY_05;
            break;

        case CLNDTASK_STATE_BEGIN_DAY:
            work->state = CLNDTASK_STATE_BEGIN_DAY_05;
            break;

        case CLNDTASK_STATE_BEGIN_DAY_05:
            work->state = CLNDTASK_STATE_BEGIN_DAY_06;
            break;

        case CLNDTASK_STATE_BEGIN_DAY_06:
            work->state = CLNDTASK_STATE_BEGIN_DAY_07;
            break;

        case CLNDTASK_STATE_BEGIN_DAY_07:
            work->state = CLNDTASK_STATE_BEGIN_DAY_08;
            break;

        case CLNDTASK_STATE_BEGIN_DAY_08:
            work->state = CLNDTASK_STATE_BEGIN_DAY_09;
            break;

        case CLNDTASK_STATE_BEGIN_DAY_09:
            work->state = CLNDTASK_STATE_BEGIN_DAY_10;
            break;

        case CLNDTASK_STATE_BEGIN_DAY_10:
            work->state = CLNDTASK_STATE_BEGIN_DAY_11;
            break;

        case CLNDTASK_STATE_BEGIN_DAY_11:
            work->state = CLNDTASK_STATE_BEGIN_DAY_12;
            break;

        case CLNDTASK_STATE_BEGIN_DAY_12:
            work->state = CLNDTASK_STATE_SELECT_TIME_ACTION;
            break;

        case CLNDTASK_STATE_SELECT_TIME_ACTION:
            actionTask = NULL;
            specialAction = false;
            work->validateSkipTarget = true;
            datSetFlag(0x1410, true);
            switch (datGetTime())
            {
                case CALENDAR_TIME_NULL:          actionTask = func_00180a20(clndTask); break;
                case CALENDAR_TIME_EARLY_MORNING: actionTask = func_00180c40(clndTask); break;
                case CALENDAR_TIME_MORNING:       actionTask = func_00180ee0(clndTask); break;
                case CALENDAR_TIME_LUNCH:         actionTask = func_00181010(clndTask); break;
                case CALENDAR_TIME_AFTERNOON:     actionTask = func_00181170(clndTask); break;
                case CALENDAR_TIME_AFTER_SCHOOL:  actionTask = func_00181310(clndTask); break;
                case CALENDAR_TIME_EVENING:       actionTask = func_00181430(clndTask); break;
                case CALENDAR_TIME_LATE_NIGHT:    actionTask = func_0017fc70(clndTask); break;
                case CALENDAR_TIME_DARK_HOUR:     actionTask = func_00181580(clndTask, &specialAction); break;
            }
            if (specialAction != 0)
            {
                work->state = CLNDTASK_STATE_CONFIRM_DAY_CHANGE;
            }
            else if (actionTask != NULL)
            {
                work->actionTask = actionTask;
                work->state = CLNDTASK_STATE_WAIT_ACTION_START;
            }
            else
            {
                work->state = CLNDTASK_STATE_SKIP;
            }
            break;

        case CLNDTASK_STATE_WAIT_ACTION_START:
            if (adminiGetNowSeqId() == ADMINI_SEQ_FIELD2 || adminiGetNowSeqId() == ADMINI_SEQ_FIELD)
            {
                if (datGetTime() == CALENDAR_TIME_NULL)
                {
                    func_00184c80(work->confirmationTask, true);
                }
                else
                {
                    func_001848f0(work->confirmationTask, true);
                }
                work->state = CLNDTASK_STATE_WAIT_ACTION_FINISH;
            }
            if (kwlnTaskGetState(work->actionTask) == KWLNTASK_STATE_DESTROY)
            {
                work->actionTask = NULL;
                work->state = CLNDTASK_STATE_SKIP;
            }
            break;

        case CLNDTASK_STATE_WAIT_ACTION_FINISH:
            if (kwlnTaskGetState(work->actionTask) == KWLNTASK_STATE_DESTROY)
            {
                work->actionTask = NULL;
                work->state = CLNDTASK_STATE_SKIP;
            }
            break;

        case CLNDTASK_STATE_CONFIRM_DAY_CHANGE:
            if (datGetTime() == CALENDAR_TIME_NULL)
            {
                func_00184c80(work->confirmationTask, true);
            }
            else
            {
                func_001848f0(work->confirmationTask, true);
            }
            work->state = CLNDTASK_STATE_WAIT_SKIP_CONFIRM;
            break;

        case CLNDTASK_STATE_WAIT_SKIP_CONFIRM:
            break;

        case CLNDTASK_STATE_REQSKIP:
            if (adminiGetNowSeqId() == ADMINI_SEQ_NULL)
            {
                work->actionTask = NULL;
                work->state = CLNDTASK_STATE_SKIP;
            }
            break;

        case CLNDTASK_STATE_CREATE_SKIP_MESSAGE:
            work->debugCursor = func_00188640();
            work->state = CLNDTASK_STATE_WAIT_SKIP_MESSAGE;
            break;

        case CLNDTASK_STATE_WAIT_SKIP_MESSAGE:
            if (kwlnTaskGetState(work->debugCursor) == KWLNTASK_STATE_DESTROY)
            {
                work->debugCursor = NULL;
                work->state = CLNDTASK_STATE_APPLY_SKIP;
            }
            break;

        case CLNDTASK_STATE_APPLY_SKIP:
            if (CLND_SKIP_TRANSITION_ACTIVE == 0)
            {
                work->state = CLNDTASK_STATE_DEBUG_WAIT_CLOSE;
            }
            else
            {
                if (work->confirmationTask == NULL)
                {
                    work->confirmationTask = func_00184db0(clndTask);
                }
                if (!clnd00184d90(work->confirmationTask))
                {
                    return KWLNTASK_CONTINUE;
                }
                func_00184c80(work->confirmationTask, true);
                func_00181b70();
                work->state = CLNDTASK_STATE_CONFIRM_DAY_CHANGE;
                CLND_SKIP_TRANSITION_ACTIVE = 0;
                work->validateSkipTarget = true;
            }
            break;

        case CLNDTASK_STATE_SKIP:
            if (work->confirmationTask == NULL)
            {
                work->confirmationTask = func_00184db0(clndTask);
            }
            if (!clnd00184d90(work->confirmationTask))
            {
                return KWLNTASK_CONTINUE;
            }
            if (work->validateSkipTarget != 0)
            {
                if (datGetSkipToTarget() != 0)
                {
                    daysSinceApr5 = datGetDaysSinceApr5();
                    dayOfMonth = datGetDaysSkipTarget();
                    if (dayOfMonth - daysSinceApr5 > 5)
                    {
                        datSetDaysSinceApr5(dayOfMonth);
                        datSetTime(datGetTimeSkipTarget());
                        datSetSkipToTarget(false);
                        work->state = CLNDTASK_STATE_BEGIN_DAY;
                        return KWLNTASK_CONTINUE;
                    }
                    if (daysSinceApr5 == dayOfMonth && datGetTime() == datGetTimeSkipTarget())
                    {
                        datSetDaysSinceApr5(dayOfMonth);
                        datSetTime(datGetTimeSkipTarget());
                        datSetSkipToTarget(false);
                        work->state = CLNDTASK_STATE_BEGIN_DAY;
                        return KWLNTASK_CONTINUE;
                    }
                }

                if (datGetTime() == CALENDAR_TIME_EARLY_MORNING)
                {
                    func_00180e60();
                }
                if (datGetTime() == CALENDAR_TIME_DARK_HOUR)
                {
                    datSetTime(CALENDAR_TIME_NULL);
                    datSetDaysSinceApr5(datGetDaysSinceApr5() + 1);
                }
                else if (func_0017db40(datGetDaysSinceApr5()) == 0 &&
                         clndGetWeekDay(datGetDaysSinceApr5()) == CALENDAR_DAY_SATURDAY &&
                         datGetTime() == CALENDAR_TIME_MORNING)
                {
                    datSetTime(CALENDAR_TIME_AFTER_SCHOOL);
                }
                else if (func_0017db40(datGetDaysSinceApr5()) != 0 &&
                         datGetTime() == CALENDAR_TIME_EARLY_MORNING)
                {
                    datSetTime(CALENDAR_TIME_AFTERNOON);
                }
                else if (func_0017db40(datGetDaysSinceApr5()) != 0 &&
                         datGetTime() == CALENDAR_TIME_AFTERNOON)
                {
                    datSetTime(CALENDAR_TIME_EVENING);
                }
                else
                {
                    datSetTime(datGetTime() + 1);
                }

                if (datGetSkipToTarget() != 0 &&
                    datGetDaysSinceApr5() == datGetDaysSkipTarget() &&
                    datGetTime() == datGetTimeSkipTarget())
                {
                    datSetSkipToTarget(false);
                }
            }
            work->state = CLNDTASK_STATE_BEGIN_DAY;
            break;

        case CLNDTASK_STATE_RESTART_SKIP:
            if (work->confirmationTask == NULL)
            {
                work->confirmationTask = func_00184db0(clndTask);
            }
            if (!clnd00184d90(work->confirmationTask))
            {
                return KWLNTASK_CONTINUE;
            }
            func_00184c80(work->confirmationTask, true);
            func_00181b70();
            work->validateSkipTarget = true;
            work->state = CLNDTASK_STATE_CONFIRM_DAY_CHANGE;
            break;

        case CLNDTASK_STATE_STOP_DELAY:
            work->stopDelay--;
            if (work->stopDelay == 0)
            {
                return KWLNTASK_STOP;
            }
            break;
    }

    return KWLNTASK_CONTINUE;
}

// FUN_0017fa10
void clndReqSkip()
{
    if (sClndTask != NULL)
    {
        if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
        {
            ((CalendarTaskWork*)sClndTask->workData)->state = CLNDTASK_STATE_REQSKIP;
            adminiChangeSeq(ADMINI_SEQ_NULL, NULL, 0, false);
        }
        else
        {
            ((CalendarTaskWork*)sClndTask->workData)->state = CLNDTASK_STATE_BEGIN_DAY_05;
            adminiChangeSeq(ADMINI_SEQ_NULL, NULL, 0, false);
        }
    }
}

// FUN_0017faa0
void clndDestroyTask(KwlnTask* clndTask)
{
    RwFree(clndTask->workData);
    sClndTask = NULL;
}

// FUN_0017fb90
KwlnTask* clndCreateTask()
{
    KwlnTask* clndTask;
    CalendarTaskWork* work;

    work = RwCalloc(1, sizeof(CalendarTaskWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    clndTask = kwlnTaskCreateWithAutoPriority(NULL,
                                              4207,
                                              "CalenderDraw",
                                              clndUpdateTask,
                                              clndDestroyTask,
                                              work);
    if (clndTask == NULL)
    {
        return NULL;
    }

    sClndTask = clndTask;

    work->state = CLNDTASK_STATE_RESTART_SKIP;
    H_SfdPlay_CreateTaskIdle(clndTask);
    if (datGetDaysSinceApr5() == 2)
    {
        work->state = CLNDTASK_STATE_DEBUG_WAIT_CLOSE;
    }

    return clndTask;
}

// FUN_00181720 NONMATCHING
s32 clndFindAndExecSiteibiEvents()
{
    SiteibiEventTable* siteibiTable;
    SiteibiEvent* event;
    s16 daysSinceApr5;
    s16 month;
    s16 dayOfMonth;
    s8 slLvl;
    u8 time;
    u8 foundEvent;
    u32 i;

    siteibiTable = Comu_GetSiteibiEvtTable();
    i = 0;
    while (true)
    {
        if (i >= siteibiTable->total)
        {
            printf("## NO EVENT ##\n");
            return -1;
        }

        event = &siteibiTable->events[i];
        daysSinceApr5 = datGetDaysSinceApr5();
        month = clndGetMonthFromDaysSinceApr5(daysSinceApr5);
        if (event->startMonth == month)
        {
            daysSinceApr5 = datGetDaysSinceApr5();
            dayOfMonth = clndGetDayOfMonthFromDaysSinceApr5(daysSinceApr5);
            if (event->startDay == dayOfMonth)
            {
                time = datGetTime();
                if (event->startTime == time)
                {
                    foundEvent = true;
                    if (event->flagReqOn1 != 0 && !datGetFlag(event->flagReqOn1))
                    {
                        foundEvent = false;
                    }
                    if (event->flagReqOn2 != 0 && !datGetFlag(event->flagReqOn2))
                    {
                        foundEvent = false;
                    }
                    if (event->flagReqOff1 != 0 && datGetFlag(event->flagReqOff1))
                    {
                        foundEvent = false;
                    }
                    if (event->flagReqOff2 != 0 && datGetFlag(event->flagReqOff2))
                    {
                        foundEvent = false;
                    }
                    if (event->slID != SOCIAL_LINK_NONE)
                    {
                        slLvl = datGetSocialLinkLevel(event->slID);
                        if (slLvl < event->slLvlReq)
                        {
                            foundEvent = false;
                        }
                    }
                    if (foundEvent)
                    {
                        printf("## EXEC EVENT = %d ##\n", i);
                        datSetFlag(event->flagToActivate, true);
                        return i;
                    }
                }
            }
        }
        i++;
    }
}

// FUN_00181b10
u8 clndGetCurrentMoonPhase()
{
    s16 daysSinceApr5 = datGetDaysSinceApr5();

    return daysMoonPhases[daysSinceApr5];
}

// FUN_00181b50
u8 clndGetMoonPhase(u32 daysSinceApr5)
{
    return daysMoonPhases[daysSinceApr5];
}

typedef struct
{
    u32 state;
    u32 reserved04;
    s32 timer;
    KwlnTask* actionTask;
    u32 specialAction;
    KwlnTask* calendarDisplayTask;
} CalendarAigesWork;

typedef struct
{
    u16 procedure;
    u8 argument;
    u8 mode;
    u8 month;
    u8 day;
    u8 time;
    u8 reserved07;
    s16 flagsOn[10];
    s16 flagsOff[6];
} CalendarScenarioEntry;
extern CalendarScenarioEntry CLND_SCENARIO_TABLE[];
#pragma alias CLND_SCENARIO_TABLE_abs CLND_SCENARIO_TABLE
extern u8 CLND_SCENARIO_TABLE_abs[];
#pragma alias adminiGetNowSeqId_u32 adminiGetNowSeqId
extern u32 adminiGetNowSeqId_u32(void);

typedef struct
{
    u32 reserved00;
    s32 timer;
    f32 current;
    u32 reserved0c;
    f32 target;
    u32 reserved14;
    f32 start;
    u32 reserved1c;
    s32 active;
} CalendarXWork;
typedef struct
{
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u8 reserved[0x12];
} CalendarFieldSequenceData;

extern const char D_005E3F00[];


extern void* func_00170d60(s16 id);
extern void* func_00170da0(s16 id);
extern void* func_00170df0(s16 id);
extern void* func_00170e40(s16 id);
extern s32 func_001714b0(s32 index);
extern s32 func_001714d0(s32 index);
extern u8 func_00171550(s16 unused1, s16 unused2, u16 index);
extern const char D_005E3F20[];
extern void* func_00112370(const char* path);
extern void func_001124b0(void* node);
extern f32 gp0xffffb308;
#define CLND_CALENDAR_X gp0xffffb308
extern void func_001159f0(void* unused, void* atlas, s32 tile, u32 alpha,
                           f32 x, f32 y, f32 depth);
extern void func_00115ad0(void* unused, void* atlas, s32 tile, u32 alpha,
                          u32 extraAlpha, f32 x, f32 y, f32 depth);
extern void func_00115bc0(void* unused, void* atlas, s32 tile, u32 alpha,
                           u32 red, u32 green, u32 blue,
                           f32 x, f32 y, f32 depth);
extern void func_00115cd0(void* unused, void* atlas, s32 tile, u32 alpha,
                           u32 red, u32 green, u32 blue,
                           f32 x, f32 y, f32 depth);
extern void (*D_00960090)(u32 state, u32 value);
extern void (*D_00960094)(u32 state, void* value);

#define CLND_SCENARIO_TABLE ((CalendarScenarioEntry*)0x0083ab30)

// FUN_00181B70
void func_00181b70(void)
{
    CalendarFieldSequenceData fieldData;
    struct
    {
        u32 floor;
        u32 reserved04;
    } dungeonData;

    if (gGlobalWork.savedDungeonFloor == 0)
    {
        func_0017f8d0();
        fieldData.unk_00 = (u16)gGlobalWork.savedFldMajorId;
        fieldData.unk_02 = (u16)gGlobalWork.savedFldMinorId;
        fieldData.unk_04 = 0xff;
        fieldData.unk_08 = 0;
        adminiChangeSeq(ADMINI_SEQ_FIELD, &fieldData, 0x1c, false);
    }
    else
    {
        dungeonData.floor = FUN_0016f380(0x35);
        dungeonData.reserved04 = 0xff;
        adminiChangeSeq(ADMINI_SEQ_DUNGEON, &dungeonData, 8, false);
    }
}

// FUN_00181C20
u32 func_00181c20(void)
{
    s32 timeSkip;
    s32 days;
    u32 currentTime;

    timeSkip = scrGetIntPara(0);
    days = datGetDaysSinceApr5();
    currentTime = datGetTime() & 0xff;
    timeSkip = currentTime + timeSkip;
    while (true)
    {
        if (timeSkip <= 8)
        {
            break;
        }

        timeSkip -= 9;
        days++;
    }
    datSetDaysSkipTarget(days);
    datSetTimeSkipTarget_u8(timeSkip);
    datSetSkipToTarget(1);
    return 1;
}

// FUN_00181CC0 NONMATCHING
void* func_00181cc0(KwlnTask* task)
{
    CalendarAigesWork* work;
    KwlnTask* parent;
    CalendarScenarioEntry* scenarioTable;
    KwlnTask* displayTask;
    s32 time;
    u16 procedure;
    s32 month;
    s32 day;
    struct
    {
        u32 floor;
        u32 reserved04;
    } dungeonData;
    CalendarFieldSequenceData fieldData;

    parent = task;
    work = (CalendarAigesWork*)parent->workData;
    scenarioTable = (CalendarScenarioEntry*)CLND_SCENARIO_TABLE_abs;
    switch (work->state)
    {
        case 0:
            if (CLND_SKIP_TRANSITION_ACTIVE != 0)
            {
                month = datGetDaysSinceApr5();
                month = clndGetMonthFromDaysSinceApr5(month);
                day = datGetDaysSinceApr5();
                day = clndGetDayOfMonthFromDaysSinceApr5(day);
                time = datGetTime() & 0xff;
                displayTask = work->calendarDisplayTask;
                if (displayTask == NULL)
                {
                    work->calendarDisplayTask = func_00188440(parent, month, day, time);
                }
                else
                {
                    func_00188420(displayTask, month, day, time);
                }

                if (gGlobalWork.savedDungeonFloor == 0)
                {
                    func_0017f8d0();
                    fieldData.unk_00 = (u16)gGlobalWork.savedFldMajorId;
                    fieldData.unk_02 = (u16)gGlobalWork.savedFldMinorId;
                    fieldData.unk_04 = 0xff;
                    fieldData.unk_08 = 0;
                    adminiChangeSeq(ADMINI_SEQ_FIELD, &fieldData, 0x1c, false);
                }
                else
                {
                    dungeonData.floor = FUN_0016f380(0x35);
                    dungeonData.reserved04 = 0xff;
                    adminiChangeSeq(ADMINI_SEQ_DUNGEON, &dungeonData, 8, false);
                }
                work->state = 4;
                CLND_SKIP_TRANSITION_ACTIVE = 0;
                break;
            }

            month = scenarioTable[func_0017d810()].month;
            day = scenarioTable[func_0017d810()].day;
            time = scenarioTable[func_0017d810()].time;
            datSetDaysSinceApr5(clndGetDaysSinceStartFromDate(month, day));
            datSetTime((u8)time);

            if (scenarioTable[func_0017d810()].flagsOn[0] != -1)
                datSetFlag(scenarioTable[func_0017d810()].flagsOn[0], true);
            if (scenarioTable[func_0017d810()].flagsOn[1] != -1)
                datSetFlag(scenarioTable[func_0017d810()].flagsOn[1], true);
            if (scenarioTable[func_0017d810()].flagsOn[2] != -1)
                datSetFlag(scenarioTable[func_0017d810()].flagsOn[2], true);
            if (scenarioTable[func_0017d810()].flagsOn[3] != -1)
                datSetFlag(scenarioTable[func_0017d810()].flagsOn[3], true);
            if (scenarioTable[func_0017d810()].flagsOn[4] != -1)
                datSetFlag(scenarioTable[func_0017d810()].flagsOn[4], true);
            if (scenarioTable[func_0017d810()].flagsOn[5] != -1)
                datSetFlag(scenarioTable[func_0017d810()].flagsOn[5], true);
            if (scenarioTable[func_0017d810()].flagsOn[6] != -1)
                datSetFlag(scenarioTable[func_0017d810()].flagsOn[6], true);
            if (scenarioTable[func_0017d810()].flagsOn[7] != -1)
                datSetFlag(scenarioTable[func_0017d810()].flagsOn[7], true);
            if (scenarioTable[func_0017d810()].flagsOn[8] != -1)
                datSetFlag(scenarioTable[func_0017d810()].flagsOn[8], true);
            if (scenarioTable[func_0017d810()].flagsOn[9] != -1)
                datSetFlag(scenarioTable[func_0017d810()].flagsOn[9], true);
            if (scenarioTable[func_0017d810()].flagsOff[0] != -1)
                datSetFlag(scenarioTable[func_0017d810()].flagsOff[0], false);
            if (scenarioTable[func_0017d810()].flagsOff[1] != -1)
                datSetFlag(scenarioTable[func_0017d810()].flagsOff[1], false);
            if (scenarioTable[func_0017d810()].flagsOff[2] != -1)
                datSetFlag(scenarioTable[func_0017d810()].flagsOff[2], false);
            if (scenarioTable[func_0017d810()].flagsOff[3] != -1)
                datSetFlag(scenarioTable[func_0017d810()].flagsOff[3], false);
            if (scenarioTable[func_0017d810()].flagsOff[4] != -1)
                datSetFlag(scenarioTable[func_0017d810()].flagsOff[4], false);
            if (scenarioTable[func_0017d810()].flagsOff[5] != -1)
                datSetFlag(scenarioTable[func_0017d810()].flagsOff[5], false);

            displayTask = work->calendarDisplayTask;
            if (displayTask == NULL)
            {
                work->calendarDisplayTask = func_00188440(parent, month, day, time);
            }
            else
            {
                func_00188420(displayTask, month, day, time);
            }

            if (scenarioTable[func_0017d810()].mode != 0xff)
            {
                displayTask = func_001ba5f0(parent,
                                            0, 0, 0, 0, 0, 0, 0, 0, 0,
                                            scenarioTable[func_0017d810()].procedure,
                                            scenarioTable[func_0017d810()].argument,
                                            scenarioTable[func_0017d810()].mode,
                                            0);
            }
            else
            {
                procedure = scenarioTable[func_0017d810()].procedure;
                displayTask = func_003bdd60(0xf, procedure);
            }
            work->actionTask = displayTask;
            work->state = 1;
            break;

        case 1:
            if (adminiGetNowSeqId_u32() == 3 || adminiGetNowSeqId_u32() == 2)
            {
                work->state = 2;
            }
            else if (kwlnTaskGetState(work->actionTask) == KWLNTASK_STATE_DESTROY)
            {
                work->actionTask = NULL;
                if (work->specialAction != 0)
                {
                    work->state = 9;
                }
                else
                {
                    func_0017d820(func_0017d810() + 1);
                    work->state = 0;
                }
            }
            break;
        case 2:
            break;

        case 3:
            work->state = 4;
            break;

        case 4:
            break;
        case 5:
            if (adminiGetNowSeqId_u32() == 0)
            {
                work->actionTask = NULL;
                if (work->specialAction != 0)
                {
                    work->state = 9;
                }
                else
                {
                    func_0017d820(func_0017d810() + 1);
                    work->state = 0;
                }
            }
            break;

        case 6:
            break;
        case 7:
            break;

        case 9:
            H_Fade_FadeIn();
            work->state = 10;
            break;

        case 10:
            if ((*(u16*)0x007e094e & 0x40) != 0)
            {
                work->state = 0;
            }
            else
            {
                u16 debugPad = *(u16*)0x007e0952;
                if ((debugPad & 0x1000) != 0)
                {
                    func_0017d820(func_0017d810() + 1);
                }
                else if ((debugPad & 0x4000) != 0 && func_0017d810() != 0)
                {
                    func_0017d820(func_0017d810() - 1);
                }
            }
            H_Dbprt_FmtAt((RwV2d){2.0f, 2.0f},
                          D_005E3F00,
                          func_0017d810());
            break;
        case 8:
            work->timer--;
            if (work->timer == 0)
            {
                return KWLNTASK_STOP;
            }
            break;
    }
    return KWLNTASK_CONTINUE;
}


// FUN_00182720
void func_00182720(KwlnTask* task)
{
    RwFree(task->workData);
    sClndTask = NULL;
}

// FUN_00182750
KwlnTask* func_00182750(KwlnTask* parent)
{
    KwlnTask* task;
    void* work;

    work = RwCalloc(1, 0x18, rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent,
                                          0x106f,
                                          D_005E3F20,
                                          func_00181cc0,
                                          func_00182720,
                                          work);
    if (task == NULL)
    {
        return NULL;
    }
    sClndTask = task;
    *(u32*)work = 0;
    H_SfdPlay_CreateTaskIdle(task);
    return task;
}

// FUN_00182810 NONMATCHING
u8 func_00182810(u16 index)
{
    u8* weights;
    u32 random;

    weights = (u8*)(uintptr_t)func_001714b0(index);
    random = func_00488f30() % 100;
    if (random < weights[4])
    {
        return 4;
    }
    if (random < (u32)weights[4] + weights[3])
    {
        return 3;
    }
    if (random < (u32)weights[4] + weights[3] + weights[2])
    {
        return 2;
    }
    return random < (u32)weights[4] + weights[3] + weights[2] + weights[1];
}

// FUN_001828D0 NONMATCHING
u32 func_001828d0(s16 id, DatEquipment* out)
{
    u8* resource;
    u16* range;
    s32 percent;
    s32 value;

    if (id >= 4000)
    {
        return 0;
    }
    if (id >= 3000)
    {
        resource = (u8*)func_00170e40(id);
        out->id = id;
        out->type = *(u32*)(resource + 0);
        out->unk_08 = 2;
        out->effect = 0;
        return 1;
    }
    if (id >= 2000)
    {
        resource = (u8*)func_00170df0(id);
        out->id = id;
        out->type = *(u32*)(resource + 4);
        out->unk_08 = func_00182810(*(u16*)(resource + 0));
        range = (u16*)(uintptr_t)func_001714d0(*(u16*)(resource + 0x0a));
        percent = (s32)(func_00488f30() % 100) + 1;
        value = (s32)range[0] + ((s32)range[1] - range[0]) * percent / 100;
        out->unk_10 = (u16)((u16)*(u16*)(resource + 8) * (value & 0xffff) / 100);
        out->effect = func_00171550(out->unk_08, (s16)out->type,
                                    *(u16*)(resource + 0x0c));
        return 1;
    }
    if (id >= 1000)
    {
        resource = (u8*)func_00170da0(id);
        out->id = id;
        out->type = *(u32*)(resource + 4);
        out->unk_08 = func_00182810(*(u16*)(resource + 0));
        range = (u16*)(uintptr_t)func_001714d0(*(u16*)(resource + 0x0a));
        percent = (s32)(func_00488f30() % 100) + 1;
        value = (s32)range[0] + ((s32)range[1] - range[0]) * percent / 100;
        out->unk_0e = (u16)((u16)*(u16*)(resource + 8) * (value & 0xffff) / 100);
        out->effect = func_00171550(out->unk_08, (s16)out->type,
                                    *(u16*)(resource + 0x0c));
        return 1;
    }

    resource = (u8*)func_00170d60(id);
    out->id = id;
    out->type = *(u32*)(resource + 4);
    out->unk_08 = func_00182810(*(u16*)(resource + 0));
    range = (u16*)(uintptr_t)func_001714d0(*(u16*)(resource + 0x0a));
    percent = (s32)(func_00488f30() % 100) + 1;
    value = (s32)range[0] + ((s32)range[1] - range[0]) * percent / 100;
    out->firstStat = (u16)((u16)*(u16*)(resource + 8) * (value & 0xffff) / 100);
    range = (u16*)(uintptr_t)func_001714d0(*(u16*)(resource + 0x0e));
    percent = (s32)(func_00488f30() % 100) + 1;
    value = (s32)range[0] + ((s32)range[1] - range[0]) * percent / 100;
    out->secondStat = (u16)((u16)*(u16*)(resource + 0x0c) * (value & 0xffff) / 100);
    out->effect = func_00171550(out->unk_08, (s16)out->type,
                                *(u16*)(resource + 0x14));
    return 1;
}

// FUN_00182C50
u32 func_00182c50(s16 id, DatEquipment* out)
{
    u8* resource;

    if (id >= 4000)
    {
        return 0;
    }
    if (id >= 3000)
    {
        resource = (u8*)func_00170e40(id);
        out->id = id;
        out->type = *(u32*)(resource + 0);
        out->unk_08 = 2;
        out->effect = 0;
        return 1;
    }
    if (id >= 2000)
    {
        resource = (u8*)func_00170df0(id);
        out->id = id;
        out->type = *(u32*)(resource + 4);
        out->unk_08 = 2;
        out->unk_10 = *(u16*)(resource + 8);
        out->effect = 0;
        return 1;
    }
    if (id >= 1000)
    {
        resource = (u8*)func_00170da0(id);
        out->id = id;
        out->type = *(u32*)(resource + 4);
        out->unk_08 = 2;
        out->unk_0e = *(u16*)(resource + 8);
        out->effect = 0;
        return 1;
    }
    resource = (u8*)func_00170d60(id);
    out->id = id;
    out->type = *(u32*)(resource + 4);
    out->unk_08 = 2;
    out->firstStat = *(u16*)(resource + 8);
    out->secondStat = *(u16*)(resource + 0x0c);
    out->effect = 0;
    return 1;
}

// FUN_00182D90 NONMATCHING
u32 func_00182d90(s16 id, u8 row, u8 effect, DatEquipment* out)
{
    u8* resource;
    u16* range;
    s32 percent;
    s32 value;

    if (id >= 4000)
    {
        return 0;
    }
    if (id >= 3000)
    {
        resource = (u8*)func_00170e40(id);
        out->id = id;
        out->type = *(u32*)(resource + 0);
        out->unk_08 = 2;
        out->effect = 0;
        return 1;
    }
    if (id >= 2000)
    {
        resource = (u8*)func_00170df0(id);
        out->id = id;
        out->type = *(u32*)(resource + 4);
        out->unk_08 = row;
        range = (u16*)(uintptr_t)func_001714d0(*(u16*)(resource + 0x0a));
        percent = (s32)(func_00488f30() % 100) + 1;
        value = (s32)range[0] + ((s32)range[1] - range[0]) * percent / 100;
        out->unk_10 = (u16)((u16)*(u16*)(resource + 8) * (value & 0xffff) / 100);
        out->effect = effect;
        return 1;
    }
    if (id >= 1000)
    {
        resource = (u8*)func_00170da0(id);
        out->id = id;
        out->type = *(u32*)(resource + 4);
        out->unk_08 = row;
        range = (u16*)(uintptr_t)func_001714d0(*(u16*)(resource + 0x0a));
        percent = (s32)(func_00488f30() % 100) + 1;
        value = (s32)range[0] + ((s32)range[1] - range[0]) * percent / 100;
        out->unk_0e = (u16)((u16)*(u16*)(resource + 8) * (value & 0xffff) / 100);
        out->effect = effect;
        return 1;
    }
    resource = (u8*)func_00170d60(id);
    out->id = id;
    out->type = *(u32*)(resource + 4);
    out->unk_08 = 2;
    range = (u16*)(uintptr_t)func_001714d0(*(u16*)(resource + 0x0a));
    percent = (s32)(func_00488f30() % 100) + 1;
    value = (s32)range[0] + ((s32)range[1] - range[0]) * percent / 100;
    out->firstStat = (u16)((u16)*(u16*)(resource + 8) * (value & 0xffff) / 100);
    range = (u16*)(uintptr_t)func_001714d0(*(u16*)(resource + 0x0e));
    percent = (s32)(func_00488f30() % 100) + 1;
    value = (s32)range[0] + ((s32)range[1] - range[0]) * percent / 100;
    out->secondStat = (u16)((u16)*(u16*)(resource + 0x0c) * (value & 0xffff) / 100);
    out->effect = effect;
    return 1;
}

// FUN_001830C0
u32 func_001830c0(const DatEquipment* record)
{
    s32 slot;

    for (slot = 0; slot < 300; slot++)
    {
        if (datGetEquipmentId(1, slot) == 0)
        {
            func_0016fea0(1, slot, record->id);
            func_0016ff90(1, slot, record->type);
            func_00170080(1, slot, record->unk_08);
            func_00170170(1, slot, record->effect);
            func_00170260(1, slot, record->firstStat);
            func_00170350(1, slot, record->secondStat);
            func_00170440(1, slot, record->unk_0e);
            func_00170530(1, slot, record->unk_10);
            return 1;
        }
    }
    return 0;
}

// FUN_001831E0
u32 func_001831e0(s16 pcId, s16 slot, const DatEquipment* record)
{
    func_0016fea0(pcId, slot, record->id);
    func_0016ff90(pcId, slot, record->type);
    func_00170080(pcId, slot, record->unk_08);
    func_00170170(pcId, slot, record->effect);
    func_00170260(pcId, slot, record->firstStat);
    func_00170350(pcId, slot, record->secondStat);
    func_00170440(pcId, slot, record->unk_0e);
    func_00170530(pcId, slot, record->unk_10);
    return 1;
}

// FUN_001832C0
void* func_001832c0(KwlnTask* task)
{
    CalendarXWork* work;

    work = (CalendarXWork*)task->workData;
    if (work->active != 0)
    {
        if (datGetFlag(0x141d) != 0 || datGetFlag(0x1407) != 0)
        {
            work->active = 0;
            work->start = work->current;
            work->target = 400.0f;
            work->timer = 10;
        }
    }
    else
    {
        if (datGetFlag(0x141d) == 0 && datGetFlag(0x1407) == 0)
        {
            work->active = 1;
            work->start = work->current;
            work->target = 0.0f;
            work->timer = 10;
        }
    }
    if (work->timer != 0)
    {
        work->timer--;
    }
    work->current = work->start +
                    ((f32)(10 - work->timer) * (work->target - work->start)) / 10.0f;
    CLND_CALENDAR_X = work->current;
    return KWLNTASK_CONTINUE;
}
// FUN_001833e0
void clnd001833e0(KwlnTask* task)
{
    RwFree(task->workData);
}

typedef struct
{
    u32 state;
    u32 confirmed;
    u32 drawReady;
    u32 reserved0c;
    u32 reserved10;
    u32 transitionPending;
    s32 month;
    s32 day;
    s32 time;
    s32 reserved24;
    s32 timer;
    s32 frame;
    s32 oldMonth;
    s32 oldDay;
    s32 oldTime;
    s32 reserved3c;
    s32 targetMonth;
    s32 targetDay;
    s32 targetTime;
    s32 reserved4c;
    u8 renderContext[0x148];
    void* resource;
    KwlnTask* child;
} CalendarConfirmWork;

extern const char D_005E4190[];
extern u32 H_Maestro_00111f30(s16* state);
extern void func_001842c0(KwlnTask* task,
                          s32 month,
                          s32 day,
                          s32 time,
                          s32 timer,
                          s32 frame,
                          void* context);

// FUN_00183410 NONMATCHING
void* func_00183410(KwlnTask* task)
{
    CalendarConfirmWork* work;
    RwCamera* camera;
    u32 oldState;

    work = (CalendarConfirmWork*)task->workData;
    camera = kwlnGetMainCamera();
    if (RwCameraBeginUpdate(camera) == NULL)
    {
        return KWLNTASK_CONTINUE;
    }

    D_00960094(14, &oldState);
    D_00960090(14, 0);
    work->frame = (work->frame + 1) % 0x168;

    if (work->state < 2 || work->confirmed != 0)
    {
        switch (work->state)
        {
            case 0:
                work->resource = func_00112370(D_005E4190);
                work->state = 1;
                break;

            case 1:
                if (H_Maestro_00111f30((s16*)work->resource) == 1)
                {
                    *(void**)0x007cdff0 = work->resource;
                    work->timer = 60;
                    work->state = 2;
                }
                break;

            case 2:
                datSetFlag(0x1421, false);
                if (work->drawReady == 0)
                {
                    printf((const char*)0x007cc0c0);
                }
                else
                {
                    if (work->timer < 60)
                    {
                        work->timer++;
                    }
                    func_001842c0(task,
                                  work->month,
                                  work->day,
                                  work->time,
                                  work->timer,
                                  work->frame,
                                  work->renderContext);
                }
                break;

            case 4:
                datSetFlag(0x1421, true);
                work->child = func_00185880(task,
                                            (s16)work->month,
                                            (s16)work->day,
                                            (s16)work->targetMonth,
                                            (s16)work->targetDay);
                work->state = 5;
                break;

            case 5:
                if (kwlnTaskGetState(work->child) == KWLNTASK_STATE_DESTROY)
                {
                    work->timer = 60;
                    work->month = work->targetMonth;
                    work->day = work->targetDay;
                    work->time = work->targetTime;
                    work->drawReady = 1;
                    work->state = 2;
                    datSetFlag(0x1410, false);
                }
                break;

            case 6:
                datSetFlag(0x1421, true);
                func_001842c0(task,
                              work->month,
                              work->day,
                              work->time,
                              work->timer,
                              work->frame,
                              work->renderContext);
                work->child = func_00186960(task, work->time, work->targetTime);
                work->state = 7;
                break;

            case 7:
                if (work->timer != 0)
                {
                    work->timer -= 6;
                    if (work->timer < 0)
                    {
                        work->timer = 0;
                    }
                }
                func_001842c0(task,
                              work->month,
                              work->day,
                              work->time,
                              work->timer,
                              work->frame,
                              work->renderContext);
                if (kwlnTaskGetState(work->child) == KWLNTASK_STATE_DESTROY)
                {
                    work->timer = 0;
                    work->month = work->targetMonth;
                    work->day = work->targetDay;
                    work->time = work->targetTime;
                    work->drawReady = 1;
                    work->state = 8;
                }
                break;

            case 8:
                if (work->drawReady != 0)
                {
                    if (work->timer < 60)
                    {
                        work->timer += 20;
                        if (work->timer >= 60)
                        {
                            work->timer = 60;
                        }
                    }
                    else
                    {
                        datSetFlag(0x1410, false);
                        work->state = 2;
                    }
                    func_001842c0(task,
                                  work->month,
                                  work->day,
                                  work->time,
                                  work->timer,
                                  work->frame,
                                  work->renderContext);
                }
                break;
        }
    }

    D_00960090(14, oldState);
    RwCameraEndUpdate(camera);
    return KWLNTASK_CONTINUE;
}

// FUN_00183840 NONMATCHING
void func_00183840(void* resource,
                   s32 alpha,
                   s32 month,
                   s32 day,
                   f32 baseX,
                   f32 baseY)
{
    static const u8 moonFrames[30] =
    {
        3, 3, 4, 4, 5, 5, 6, 7, 7, 8,
        8, 8, 9, 9, 10, 11, 11, 12, 12, 12,
        13, 13, 14, 15, 15, 16, 16, 17, 17, 18,
    };
    s32 days;
    s32 phase;
    s32 blink;
    s32 blinkAlpha;
    s32 frame;

    days = clndGetDaysSinceStartFromDate(month, day);
    phase = daysMoonPhases[days];
    if (phase != 0x1d)
    {
        func_001159f0(NULL, resource, 0x2e, alpha & 0xff,
                      baseX + 584.0f, baseY + 57.0f, 50.0f);
    }

    if (phase < 30)
    {
        frame = moonFrames[phase];
    }
    else
    {
        frame = 0;
    }
    func_001159f0(NULL, resource, frame, alpha & 0xff,
                  baseX + 595.0f, baseY + 67.0f, 50.0f);

    if (phase >= 0 && phase < 15)
    {
        blink = ++(*(s32*)0x007cdff4);
        if (blink >= 0x29)
        {
            *(s32*)0x007cdff4 = 0;
            blink = 0;
        }
        if (blink >= 0x15)
        {
            blink = 0x28 - blink;
        }
        blinkAlpha = (blink * 0xff) / 0x14;
        func_00115ad0(NULL, resource, frame + 0x39, alpha & 0xff,
                      blinkAlpha,
                      baseX + 584.0f, baseY + 57.0f, 50.0f);
    }

    if (phase == 0x1d)
    {
        func_001159f0(NULL, resource, 2, alpha & 0xff,
                      baseX + 540.0f, baseY + 80.0f, 50.0f);
    }
    else if (phase == 6 || phase == 0x16)
    {
        func_001159f0(NULL, resource, 0, alpha & 0xff,
                      baseX + 540.0f, baseY + 80.0f, 50.0f);
    }
    else if (phase == 0x0e)
    {
        func_001159f0(NULL, resource, 1, alpha & 0xff,
                      baseX + 540.0f, baseY + 67.0f, 50.0f);
    }
}

// FUN_00183BE0 NONMATCHING
void func_00183be0(void* resource,
                   s32 alpha,
                   s32 month,
                   s32 day,
                   f32 baseX,
                   f32 baseY)
{
    s32 days;
    s32 weekday;
    s32 weekdayFrame;
    u32 red;
    u32 green;
    u32 blue;

    if (alpha < 0x28)
    {
        alpha = 0x28;
    }
    if (month >= 10)
    {
        func_00115bc0(NULL, resource, 0x24, alpha & 0xff,
                      0, 0x0e, 2,
                      baseX + 515.0f, baseY + 15.0f, 50.0f);
    }
    func_00115bc0(NULL, resource, (month % 10) + 0x23, alpha & 0xff,
                  0, 0x0e, 2,
                  baseX + 532.0f, baseY + 15.0f, 50.0f);
    func_00115bc0(NULL, resource, 0x2d, alpha & 0xff,
                  0, 0x0e, 2,
                  baseX + 548.0f, baseY + 15.0f, 50.0f);
    if (day >= 10)
    {
        func_00115bc0(NULL, resource, day / 10 + 0x23, alpha & 0xff,
                      0, 0x0e, 2,
                      baseX + 557.0f, baseY + 15.0f, 50.0f);
    }
    func_00115bc0(NULL, resource, day % 10 + 0x23, alpha & 0xff,
                  0, 0x0e, 2,
                  baseX + 574.0f, baseY + 15.0f, 50.0f);

    days = clndGetDaysSinceStartFromDate(month, day);
    if (func_0017db40(days) == 1)
    {
        red = 0x5f;
        green = 0x2a;
        blue = 0x50;
    }
    else if (clndGetWeekDay(days) == 6)
    {
        red = 6;
        green = 0x4e;
        blue = 0x7e;
    }
    else
    {
        red = 0x32;
        green = 0x3c;
        blue = 0x42;
    }
    weekday = clndGetWeekDay(days);
    switch (weekday)
    {
        case 0: weekdayFrame = 0x22; break;
        case 1: weekdayFrame = 0x1c; break;
        case 2: weekdayFrame = 0x1d; break;
        case 3: weekdayFrame = 0x1e; break;
        case 4: weekdayFrame = 0x1f; break;
        case 5: weekdayFrame = 0x20; break;
        case 6: weekdayFrame = 0x21; break;
        default: return;
    }
    func_00115bc0(NULL, resource, weekdayFrame, alpha & 0xff,
                  red, green, blue,
                  baseX + 592.0f, baseY + 13.0f, 50.0f);
}

// FUN_00183F60 NONMATCHING
void func_00183f60(void* resource,
                   s32 alpha,
                   s32 month,
                   s32 day,
                   s32 time,
                   f32 baseX,
                   f32 baseY)
{
    s32 days;
    s32 frame;
    f32 x;
    f32 y;

    days = clndGetDaysSinceStartFromDate(month, day);
    x = baseX;
    y = baseY;
    if (func_0017db40(days) == 1 && time >= 2 && time <= 5)
    {
        func_001159f0(NULL, resource, 0x36, alpha & 0xff,
                      x + 525.0f, y + 29.0f, 50.0f);
        return;
    }

    frame = -1;
    switch (time)
    {
        case 0:
        case 7:
            frame = 0x35;
            x += 491.0f;
            y += 29.0f;
            break;
        case 1:
            frame = 0x2f;
            x += 452.0f;
            y += 29.0f;
            break;
        case 2:
            frame = 0x30;
            x += 524.0f;
            y += 29.0f;
            break;
        case 3:
            frame = 0x31;
            x += 495.0f;
            y += 29.0f;
            break;
        case 4:
            frame = 0x32;
            x += 499.0f;
            y += 29.0f;
            break;
        case 5:
            frame = 0x33;
            x += 467.0f;
            y += 29.0f;
            break;
        case 6:
            frame = 0x34;
            x += 528.0f;
            y += 29.0f;
            break;
        case 8:
            frame = 0x37;
            x += 500.0f;
            y += 26.0f;
            break;
        default:
            break;
    }
    if (frame >= 0)
    {
        func_001159f0(NULL, resource, frame, alpha & 0xff,
                      x, y, 50.0f);
    }
}

// FUN_001842C0 NONMATCHING
void func_001842c0(KwlnTask* task,
                   s32 month,
                   s32 day,
                   s32 time,
                   s32 timer,
                   s32 frame,
                   void* context)
{
    CalendarConfirmWork* work;
    void* resource;
    f32 x;
    s32 fade;
    s32 dayIndex;
    s32 moonOffset;
    s32 i;
    u32 red;
    u32 green;
    u32 blue;

    (void)context;
    work = (CalendarConfirmWork*)task->workData;
    resource = work->resource;
    x = CLND_CALENDAR_X;

    func_001159f0(NULL, resource, 0x3a, 0,
                  x + 514.0f, 23.0f, 50.0f);
    if (time == 8)
    {
        func_00115bc0(NULL, resource, 0x39, 0,
                      0x7c, 0xff, 0x90,
                      x + 390.0f, -8.0f, 50.0f);
        red = 0x7c;
        green = 0xff;
        blue = 0x90;
    }
    else
    {
        func_00115bc0(NULL, resource, 0x39, 0,
                      0x4c, 0x9a, 0xff,
                      x + 390.0f, -8.0f, 50.0f);
        red = 0x4a;
        green = 0x9a;
        blue = 0xff;
    }

    func_00183840(resource, 0, month, day, x, 0.0f);
    func_00183be0(resource, 0, month, day, x, 0.0f);
    fade = ((60 - timer) * 0xff) / 60;
    func_00183f60(resource, fade, month, day, time, x, 0.0f);

    if (datGetFlag(0x1420) != 0)
    {
        return;
    }

    dayIndex = clndGetDaysSinceStartFromDate(month, day);
    moonOffset = 0;
    for (i = 0; i < 100; i++)
    {
        if (daysMoonPhases[dayIndex + i] == 0x0e)
        {
            moonOffset = i;
            break;
        }
    }
    if (moonOffset == 0)
    {
        return;
    }

    if (moonOffset >= 10)
    {
        func_001159f0(NULL, resource, 0x4c, 0,
                      x + 497.0f, 66.0f, 50.0f);
        D_00960090(6, 1);
        D_00960090(7, 2);
        D_00960090(8, 1);
        D_00960090(9, 2);
        D_00960090(0xc, 1);
        D_00960090(0xb, 6);
        D_00960090(0xa, 5);
        D_00960090(2, 4);
        D_00960090(0xe, 0);
        RpSkyRenderStateSet(2, (void*)0x48);
        RpSkyRenderStateSet(3, (void*)0x71801);
        func_00115cd0(NULL, resource, moonOffset / 10 + 0x23, 0,
                      red, green, blue,
                      x + 554.0f, 67.0f, 50.0f);
    }
    else
    {
        func_001159f0(NULL, resource, 0x4c, 0,
                      x + 514.0f, 66.0f, 50.0f);
        D_00960090(6, 1);
        D_00960090(7, 2);
        D_00960090(8, 1);
        D_00960090(9, 2);
        D_00960090(0xc, 1);
        D_00960090(0xb, 6);
        D_00960090(0xa, 5);
        D_00960090(2, 4);
        D_00960090(0xe, 0);
        RpSkyRenderStateSet(2, (void*)0x48);
        RpSkyRenderStateSet(3, (void*)0x71801);
    }
    func_00115cd0(NULL, resource, moonOffset % 10 + 0x23, 0,
                  red, green, blue,
                  x + 571.0f, 67.0f, 50.0f);
}

extern void* DAT_007cdff0;

// FUN_00184890
void func_00184890(KwlnTask* task)
{
    CalendarConfirmWork* work;

    work = (CalendarConfirmWork*)task->workData;
    if (work->resource != NULL)
    {
        func_001124b0(work->resource);
        work->resource = NULL;
    }
    DAT_007cdff0 = NULL;
    RwFree(work);
}

// FUN_001848F0 NONMATCHING
void func_001848f0(KwlnTask* task, u32 confirmed)
{
    CalendarConfirmWork* work;
    s32 currentMonth;
    s32 currentDay;
    s32 currentTime;
    s32 currentDays;
    s32 oldDays;

    work = (CalendarConfirmWork*)task->workData;
    work->confirmed = confirmed;
    if (confirmed == 0)
    {
        work->transitionPending = 1;
        work->state = 2;
        datSetFlag(0x1410, false);
        return;
    }
    if (datGetFlag(0x14f) != 0)
    {
        datSetFlag(0x1410, false);
        work->month = clndGetCurrentMonth();
        work->day = clndGetCurrentDay();
        work->time = datGetTime() & 0xff;
        return;
    }

    currentMonth = clndGetCurrentMonth();
    currentDay = clndGetCurrentDay();
    currentTime = datGetTime() & 0xff;
    currentDays = clndGetDaysSinceStartFromDate(currentMonth, currentDay);
    oldDays = clndGetDaysSinceStartFromDate(work->month, work->day);
    if (currentDays - oldDays >= 6)
    {
        func_00184c80(task, confirmed);
    }

    if (func_0017db40(currentDays) == 1 &&
        func_0017db40(oldDays) == 1 &&
        currentTime >= 2 && currentTime <= 5 &&
        work->time >= 2 && work->time <= 5)
    {
        if (work->month != currentMonth || work->day != currentDay)
        {
            work->reserved0c = 0x280;
            work->transitionPending = 1;
            work->oldMonth = work->month;
            work->oldDay = work->day;
            work->oldTime = work->time;
            work->targetMonth = currentMonth;
            work->targetDay = currentDay;
            work->targetTime = currentTime;
            work->state = 4;
        }
        else
        {
            work->month = currentMonth;
            work->day = currentDay;
            work->time = currentTime;
            work->state = 2;
            datSetFlag(0x1410, false);
            work->drawReady = 1;
        }
    }
    else if (work->month == currentMonth &&
             work->day == currentDay &&
             work->time == currentTime)
    {
        datSetFlag(0x1410, false);
        work->state = 2;
        work->drawReady = 1;
    }
    else
    {
        work->reserved0c = 0x280;
        work->transitionPending = 1;
        work->oldMonth = work->month;
        work->oldDay = work->day;
        work->oldTime = work->time;
        work->targetMonth = currentMonth;
        work->targetDay = currentDay;
        work->targetTime = currentTime;
        if (work->month != currentMonth || work->day != currentDay)
        {
            work->timer = 0;
            work->state = 4;
        }
        else
        {
            work->state = 6;
        }
        datSetFlag(0x1410, true);
    }
}

// FUN_00184C80 NONMATCHING
void func_00184c80(KwlnTask* task, u32 confirmed)
{
    CalendarConfirmWork* work;
    s32 currentMonth;
    s32 currentDay;
    s32 currentTime;

    work = (CalendarConfirmWork*)task->workData;
    work->confirmed = confirmed;
    currentMonth = clndGetCurrentMonth();
    currentDay = clndGetCurrentDay();
    currentTime = datGetTime() & 0xff;
    (void)clndGetDaysSinceStartFromDate(currentMonth, currentDay);
    (void)clndGetDaysSinceStartFromDate(work->month, work->day);
    work->month = currentMonth;
    work->day = currentDay;
    work->time = currentTime;
    work->state = 2;
    datSetFlag(0x1410, false);
    if (confirmed != 0)
    {
        work->drawReady = 1;
    }
    else
    {
        work->transitionPending = 1;
        work->state = 2;
    }
}

// FUN_00184d90
u32 clnd00184d90(KwlnTask* task)
{
    return ((CalendarTaskWork*)task->workData)->state == 2;
}

// FUN_00187520
void clnd00187520(KwlnTask* task)
{
    CLND_FREE(task->workData);
}

void H_Free(void* memory);

// FUN_00187df0
void clnd00187df0(KwlnTask* task)
{
    H_Free(task->workData);
}

// FUN_00187ea0
void clnd00187ea0(KwlnTask* task)
{
    ((CalendarTaskWork*)task->workData)->state = 3;
}

// FUN_00188510
u32 clndScrCmd_SET_DATE()
{
    u32 month;
    u32 day;
    s32 time;
    u32 daysSinceApr5;

    month = scrGetIntPara(0);
    day = scrGetIntPara(1);
    time = scrGetIntPara(2);

    daysSinceApr5 = clndGetDaysSinceStartFromDate(month, day);

    datSetDaysSinceApr5(daysSinceApr5);
    datSetTime(time);

    return true;
}
 
#include "h_maestro.h"
#include "h_fade.h"
#include "h_cdvd.h"
#include "Kernel/h_malloc.h"

extern void* func_001832c0(KwlnTask* task);
extern void* func_00183410(KwlnTask* task);
extern void func_00184890(KwlnTask* task);
extern void func_001159f0(void* unused, void* atlas, s32 tile, u32 alpha,
                           f32 x, f32 y, f32 depth);
extern void func_00115bc0(void* unused, void* atlas, s32 tile, u32 alpha,
                           u32 red, u32 green, u32 blue,
                           f32 x, f32 y, f32 depth);
extern void func_00113a30(f32 depth, f32 x, f32 y, u32 color,
                          s32 width, s32 height);
extern void func_003b2cb0(f32 depth, s32 x, s32 y, u32 color, u32 font,
                          u32 align, const void* text, u32 width, u32 flags);
extern void func_00108f70();
extern u8 func_00109f60(s16 channelIndex, s16 mappedChannelIndex);
extern void (*D_00960090)(u32 state, u32 value);
extern void (*D_00960094)(u32 state, void* value);
extern void (*D_009600A0)(RwPrimitiveType primitiveType, RwIm2DVertex* vertices, s32 vertexCount);
extern f32 D_00960088;
extern const f32 DAT_007caf38;
extern const char D_005E3F38[];
extern const char* D_005E4150[];
extern const char D_005E4190[];
extern const char D_005E41A8[];
extern const char D_005E41C0[];
extern const char D_005E41E0[];
extern const char D_005E41F0[];
extern const char D_005E4200[];
extern const char D_005E4220[];
extern const char D_005E4240[];
extern const char D_005E4260[];
extern const char D_005E4280[];
extern const char D_005E4290[];
extern const char D_005E42B8[];
extern const char D_005E42D0[];
extern void* H_Calloc(u32 count, size_t size);
extern f32 sinf(f32 angle);
extern f32 cosf(f32 angle);
extern RwMatrix* func_004c38c0(void);
extern void func_004c3880(RwMatrix* matrix);
extern RwMatrix* func_004c2fc0(RwReal oneMinusCosine,
                               RwReal sine,
                               RwMatrix* matrix,
                               const RwV3d* axis,
                               RwOpCombineType combineOp);
extern RwV3d* func_004c6c20(RwV3d* pointsOut,
                            const RwV3d* pointsIn,
                            RwUInt32 pointCount,
                            const RwMatrix* matrix);
extern void* func_004c9d10(RwCamera* camera);
extern void* func_004c9d00(RwCamera* camera);

#define CLND_MOON_X_SCALE (*(f32*)0x007cb174)
#define CLND_MOON_Y_SCALE (*(f32*)0x007cb178)

typedef struct
{
    u32 state;
    void* resource;
    s16 sourceMonth;
    s16 sourceDay;
    s16 frame;
    s16 padding;
    s16 currentMonth;
    s16 currentDay;
    s16 targetMonth;
    s16 targetDay;
    KwlnTask* eventTask;
} CalendarDateTransitionWork;

typedef struct
{
    u32 state;
    void* resource;
    s32 currentValue;
    s32 selectedValue;
    s32 targetValue;
    s32 timer;
    KwlnTask* transitionTask;
    KwlnTask* eventTask;
    void* archive;
} CalendarMoonWork;

typedef struct
{
    u32 state;
    s32 fadeTimer;
    s32 transitionTimer;
    KwlnTask* firstTask;
    KwlnTask* secondTask;
    u8 reserved14[4];
} CalendarTransitionWork;

typedef struct
{
    u32 state;
    s32 messageIndex;
    s32 timer;
} CalendarRecoveredColdWork;

typedef struct
{
    u32 state;
    s32 timer;
    s32 alpha;
    s32 angle;
    s32 scaleAngle;
} CalendarSkipDrawWork;

typedef struct
{
    u32 state;
    s32 month;
    s32 day;
    s32 time;
    void* resource;
} CalendarTransitionMessageWork;

static u64 clndPackPosition(f32 x, f32 y)
{
    union
    {
        f32 value;
        u32 bits;
    } xBits, yBits;

    xBits.value = x;
    yBits.value = y;
    return ((u64)yBits.bits << 32) | xBits.bits;
}

static f32 clndPackedX(u64 position)
{
    union
    {
        f32 value;
        u32 bits;
    } bits;

    bits.bits = (u32)position;
    return bits.value;
}

static f32 clndPackedY(u64 position)
{
    union
    {
        f32 value;
        u32 bits;
    } bits;

    bits.bits = (u32)(position >> 32);
    return bits.value;
}

static s32 clndNormalizeAngle(s32 angle)
{
    while (angle > 180)
    {
        angle -= 360;
    }
    while (angle < -180)
    {
        angle += 360;
    }
    return angle;
}

// FUN_00184DB0 NONMATCHING
KwlnTask* func_00184db0(KwlnTask* parent)
{
    u8* work;
    KwlnTask* task;
    KwlnTask* child;
    u8* childWork;

    work = CLND_ALLOC(1, 0x1a0, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent,
                          D_005E41A8,
                          0x1cd5,
                          (KwlnTaskUpdateFunc)func_00183410,
                          (KwlnTaskDestroyFunc)func_00184890,
                          work);
    if (task == NULL)
    {
        return NULL;
    }

    *(s32*)(work + 0x18) = clndGetCurrentMonth();
    *(s32*)(work + 0x1c) = clndGetCurrentDay();
    *(s32*)(work + 0x20) = datGetTime() & 0xff;

    childWork = CLND_ALLOC(1, 0x24, 0x40000);
    if (childWork != NULL)
    {
        child = kwlnTaskCreate(task,
                               D_005E3F38,
                               0x1cd5,
                               (KwlnTaskUpdateFunc)func_001832c0,
                               clnd001833e0,
                               childWork);
        if (child != NULL)
        {
            *(f32*)(childWork + 0x08) = 400.0f;
            *(f32*)(childWork + 0x10) = 400.0f;
            CLND_CALENDAR_X = 400.0f;
        }
    }

    return task;
}

// FUN_00184F00 NONMATCHING
void* func_00184f00(KwlnTask* task)
{
    CalendarDateTransitionWork* work;
    s16 frame;
    s16 nextDay;
    s32 currentDays;
    s32 targetDays;
    u16 alpha;
    f32 offset;
    f32 wave;

    work = (CalendarDateTransitionWork*)task->workData;
    switch (work->state)
    {
        case 0:
            work->resource = func_00112370(D_005E41C0);
            work->state = 1;
            break;

        case 1:
            if (H_Maestro_00111f30((s16*)work->resource))
            {
                work->frame = 0;
                work->currentMonth = work->sourceMonth;
                work->currentDay = work->sourceDay;
                work->state = 2;
            }
            break;

        case 2:
            work->frame++;
            if (work->frame > 60)
            {
                work->frame = 0;
                work->state = 3;
            }
            break;

        case 3:
            offset = ((f32)(30 - work->frame) * -80.0f) / 30.0f;
            func_00186100(work->resource, clndPackPosition(offset, 0.0f), 0);
            offset = ((f32)(30 - work->frame) * 80.0f) / 30.0f;
            func_00186140(work->resource, clndPackPosition(offset, 0.0f), 0);
            work->frame++;
            if (work->frame == 30)
            {
                work->frame = 0;
                work->state = 4;
            }
            break;

        case 4:
            frame = ++work->frame;
            if (frame < 15)
            {
                offset = -((f32)((15 - frame) * 20) / 15.0f);
                alpha = (u16)(((15 - frame) * 0xff) / 15);
            }
            else
            {
                offset = 0.0f;
                alpha = 0;
            }
            func_00185980(work->resource,
                          clndPackPosition(offset, 0.0f),
                          alpha,
                          work->currentMonth);
            func_00185ae0(work->resource,
                          clndPackPosition(offset, 0.0f),
                          alpha,
                          work->currentMonth);
            alpha = (u16)(((60 - frame) * 0xff) / 60);
            func_00185b40(work->resource,
                          clndPackPosition(0.0f, 0.0f),
                          alpha,
                          work->currentMonth,
                          work->currentDay);
            func_00186050(work->resource, clndPackPosition(0.0f, 0.0f), alpha);
            func_00186100(work->resource, clndPackPosition(0.0f, 0.0f), 0);
            func_00186140(work->resource, clndPackPosition(0.0f, 0.0f), 0);
            if (frame == 60)
            {
                work->frame = 0;
                work->state = 5;
            }
            break;

        case 5:
            func_00185980(work->resource,
                          clndPackPosition(0.0f, 0.0f),
                          0,
                          work->currentMonth);
            frame = work->frame;
            if (frame < 10)
            {
                func_00185ae0(work->resource,
                              clndPackPosition(0.0f, 0.0f),
                              0,
                              work->currentMonth);
            }
            else
            {
                switch (frame)
                {
                    case 11: wave = 1.0f; break;
                    case 12: wave = 3.0f; break;
                    case 13: wave = 4.0f; break;
                    case 14: wave = 5.0f; break;
                    case 15: wave = 2.0f; break;
                    default: wave = 0.0f; break;
                }
                func_00185ae0(work->resource,
                              clndPackPosition(wave, 0.0f),
                              0,
                              work->currentMonth);
            }
            work->frame++;
            wave = sinf((DAT_007caf38 * (f32)((work->frame * 0x5a) / 0xf)) / 180.0f);
            func_00185b40(work->resource,
                          clndPackPosition(-(wave * 87.0f), 0.0f),
                          0,
                          work->currentMonth,
                          work->currentDay);
            func_00186050(work->resource, clndPackPosition(0.0f, 0.0f), 0);
            func_00186100(work->resource, clndPackPosition(0.0f, 0.0f), 0);
            func_00186140(work->resource, clndPackPosition(0.0f, 0.0f), 0);
            if (work->frame == 15)
            {
                currentDays = clndGetDaysSinceStartFromDate(work->currentMonth,
                                                             work->currentDay) + 1;
                targetDays = clndGetDaysSinceStartFromDate(work->targetMonth,
                                                           work->targetDay);
                if (currentDays == targetDays)
                {
                    work->frame = 0;
                    work->state = 6;
                }
                else
                {
                    work->currentMonth = clndGetMonthFromDaysSinceApr5(currentDays);
                    nextDay = clndGetDayOfMonthFromDaysSinceApr5(currentDays);
                    work->currentDay = nextDay;
                    work->frame = 0;
                }
            }
            break;

        case 6:
            func_00185980(work->resource,
                          clndPackPosition(0.0f, 0.0f),
                          0,
                          work->targetMonth);
            func_00185ae0(work->resource,
                          clndPackPosition(0.0f, 0.0f),
                          0,
                          work->targetMonth);
            func_00185b40(work->resource,
                          clndPackPosition(0.0f, 0.0f),
                          0,
                          work->targetMonth,
                          work->targetDay);
            func_00186050(work->resource, clndPackPosition(0.0f, 0.0f), 0);
            func_00186100(work->resource, clndPackPosition(0.0f, 0.0f), 0);
            func_00186140(work->resource, clndPackPosition(0.0f, 0.0f), 0);
            work->frame++;
            if (work->frame == 20)
            {
                work->frame = 0;
                work->state = 8;
            }
            break;

        case 7:
            work->frame++;
            alpha = (u16)((work->frame * 0xff) / 15);
            func_00185980(work->resource,
                          clndPackPosition(0.0f, 0.0f),
                          alpha,
                          work->targetMonth);
            func_00185ae0(work->resource,
                          clndPackPosition(0.0f, 0.0f),
                          alpha,
                          work->targetMonth);
            func_00185b40(work->resource,
                          clndPackPosition(0.0f, 0.0f),
                          alpha,
                          work->targetMonth,
                          work->targetDay);
            func_00186050(work->resource, clndPackPosition(0.0f, 0.0f), alpha);
            func_00186100(work->resource, clndPackPosition(0.0f, 0.0f), alpha);
            func_00186140(work->resource, clndPackPosition(0.0f, 0.0f), alpha);
            if (work->frame == 15)
            {
                return KWLNTASK_STOP;
            }
            break;

        case 8:
            if (datGetFlag(0x141c) == 0)
            {
                work->state = 7;
            }
            else
            {
                work->eventTask = func_00187550(task);
                work->state = 9;
                datSetFlag(0x141c, false);
            }
            func_00185980(work->resource,
                          clndPackPosition(0.0f, 0.0f),
                          0,
                          work->targetMonth);
            func_00185ae0(work->resource,
                          clndPackPosition(0.0f, 0.0f),
                          0,
                          work->targetMonth);
            func_00185b40(work->resource,
                          clndPackPosition(0.0f, 0.0f),
                          0,
                          work->targetMonth,
                          work->targetDay);
            func_00186050(work->resource, clndPackPosition(0.0f, 0.0f), 0);
            func_00186100(work->resource, clndPackPosition(0.0f, 0.0f), 0);
            func_00186140(work->resource, clndPackPosition(0.0f, 0.0f), 0);
            break;

        case 9:
            if (kwlnTaskGetState(work->eventTask) == KWLNTASK_STATE_DESTROY)
            {
                work->state = 7;
            }
            func_00185980(work->resource,
                          clndPackPosition(0.0f, 0.0f),
                          0,
                          work->targetMonth);
            func_00185ae0(work->resource,
                          clndPackPosition(0.0f, 0.0f),
                          0,
                          work->targetMonth);
            func_00185b40(work->resource,
                          clndPackPosition(0.0f, 0.0f),
                          0,
                          work->targetMonth,
                          work->targetDay);
            func_00186050(work->resource, clndPackPosition(0.0f, 0.0f), 0);
            func_00186100(work->resource, clndPackPosition(0.0f, 0.0f), 0);
            func_00186140(work->resource, clndPackPosition(0.0f, 0.0f), 0);
            break;
    }

    return KWLNTASK_CONTINUE;
}

// FUN_00185830
void func_00185830(KwlnTask* task)
{
    CalendarDateTransitionWork* work;

    work = (CalendarDateTransitionWork*)task->workData;
    if (work->resource != NULL)
    {
        func_001124b0(work->resource);
        work->resource = NULL;
    }
    CLND_FREE(work);
}

// FUN_00185880
KwlnTask* func_00185880(KwlnTask* parent,
                        s16 sourceMonth,
                        s16 sourceDay,
                        s16 targetMonth,
                        s16 targetDay)
{
    KwlnTask* task;
    CalendarDateTransitionWork* work;

    work = CLND_ALLOC(1, sizeof(CalendarDateTransitionWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent,
                          D_005E41E0,
                          0x18c0,
                          func_00184f00,
                          func_00185830,
                          work);
    if (task == NULL)
    {
        return NULL;
    }

    work->sourceMonth = sourceMonth;
    work->sourceDay = sourceDay;
    work->targetMonth = targetMonth;
    work->targetDay = targetDay;
    H_Fade_SetType(HFADE_TRANSITION2);
    return task;
}

// FUN_00185980 NONMATCHING
void func_00185980(void* resource, u64 position, u32 alpha, s16 month)
{
    f32 x;
    f32 y;

    x = clndPackedX(position);
    y = clndPackedY(position);
    func_001159f0(NULL, resource, month < 4 ? 0x50 : 0x4f,
                  alpha & 0xff, x + 289.0f, y + 112.0f, 72.0f);
    func_001159f0(NULL, resource, month - 1,
                  alpha & 0xff, x + 251.0f, y + 131.0f, 72.0f);
    func_001159f0(NULL, resource, month + 0xb,
                  alpha & 0xff, x + 251.0f, y + 163.0f, 72.0f);
}

#pragma push
#pragma schedule off
// FUN_00185AE0 NONMATCHING
void func_00185ae0(void* resource, u64 position, u32 alpha, s16 day)
{
    union
    {
        u64 bits;
        f32 coords[2];
    } packed;
    f32 x;
    f32 y;
    u32 cellAlpha;

    (void)day;
    packed.bits = position;
    x = packed.coords[0] + 305.0f;
    y = packed.coords[1] + 188.0f;
    cellAlpha = alpha & 0xff;
    func_001159f0(resource, resource, 0x4e, cellAlpha, x, y, 50.0f);
}
#pragma pop

// FUN_00185B40 NONMATCHING
void func_00185b40(void* resource,
                   u64 position,
                   u32 alpha,
                   s16 month,
                   s16 day)
{
    s32 firstDay;
    s32 dayIndex;
    s32 i;
    s32 dayValue;
    s32 weekday;
    s32 moonPhase;
    f32 x;
    f32 y;
    u32 cellAlpha;
    u32 red;
    u32 green;
    u32 blue;

    func_00113a30(49.0f, 627.0f, 190.0f, 0xffffff00, 30, 30);
    func_00113a30(49.0f, 0.0f, 190.0f, 0xffffff00, 21, 30);
    firstDay = clndGetDaysSinceStartFromDate(month, day);
    dayIndex = firstDay - 3;
    x = clndPackedX(position) + 17.0f;
    y = clndPackedY(position) + 213.0f;
    for (i = 0; i < 8; i++, dayIndex++)
    {
        if (dayIndex < 0)
        {
            continue;
        }

        cellAlpha = i == 3 ? alpha & 0xff : 0xff - (alpha & 0xff);
        if (dayIndex == firstDay)
        {
            if (func_0017db40((s16)dayIndex) != 0)
            {
                red = 0xff;
                green = 0xa2;
                blue = 0xba;
            }
            else if (clndGetWeekDay(dayIndex) == 6)
            {
                red = 0xa8;
                green = 0xaa;
                blue = 0xff;
            }
            else
            {
                red = 0xff;
                green = 0xff;
                blue = 0xff;
            }
        }
        else if (func_0017db40((s16)dayIndex) != 0)
        {
            red = 0x88;
            green = 0x5c;
            blue = 0x62;
        }
        else if (clndGetWeekDay(dayIndex) == 6)
        {
            red = 0x5c;
            green = 0x72;
            blue = 0x88;
        }
        else
        {
            red = 0x58;
            green = 0x64;
            blue = 0x6a;
        }

        dayValue = clndGetDayOfMonthFromDaysSinceApr5(dayIndex);
        if (dayValue < 10)
        {
            func_00115bc0(NULL, resource, dayValue + 0x18, cellAlpha,
                          red, green, blue,
                          (f32)i * 87.0f + x + 25.0f, y + 10.0f, 72.0f);
        }
        else
        {
            func_00115bc0(NULL, resource, dayValue / 10 + 0x18, cellAlpha,
                          red, green, blue,
                          (f32)i * 87.0f + x + 10.0f, y + 10.0f, 72.0f);
            func_00115bc0(NULL, resource, dayValue % 10 + 0x18, cellAlpha,
                          red, green, blue,
                          (f32)i * 87.0f + x + 39.0f, y + 10.0f, 72.0f);
        }

        weekday = clndGetWeekDay(dayIndex);
        switch (weekday)
        {
            case 0: weekday = 0x28; break;
            case 1: weekday = 0x22; break;
            case 2: weekday = 0x23; break;
            case 3: weekday = 0x24; break;
            case 4: weekday = 0x25; break;
            case 5: weekday = 0x26; break;
            default: weekday = 0x27; break;
        }
        func_00115bc0(NULL, resource, weekday, cellAlpha,
                      red, green, blue,
                      (f32)i * 87.0f + x + 17.0f, y + 45.0f, 72.0f);

        moonPhase = clndGetMoonPhase(dayIndex);
        func_00115bc0(NULL, resource, moonPhase + 0x2f, cellAlpha,
                      0xff, 0xff, 0xff,
                      (f32)i * 87.0f + x + 25.0f, y + 59.0f, 72.0f);
    }
}

// FUN_00186050 NONMATCHING
void func_00186050(void* resource, u64 position, u32 alpha)
{
    func_001159f0(NULL, resource, 0x2b, alpha & 0xff,
                  clndPackedX(position), clndPackedY(position), 48.0f);
    func_001159f0(NULL, resource, 0x2c, alpha & 0xff,
                  clndPackedX(position) + 449.0f,
                  clndPackedY(position), 48.0f);
}

// FUN_00186100
void func_00186100(void* resource, u64 position, u32 alpha)
{
    f32 x;
    f32 y;
    u32 drawAlpha;
    union
    {
        u64 value;
        struct
        {
            f32 x;
            f32 y;
        } coords;
    } packed;

    packed.value = position;
    y = packed.coords.y;
    asm volatile("" : "+m"(y));
    x = packed.coords.x;
    drawAlpha = alpha & 0xff;
    func_001159f0(resource, resource, 0x29, drawAlpha,
                  x, y, 48.0f);
}

// FUN_00186140
void func_00186140(void* resource, u64 position, u32 alpha)
{
    f32 x;
    f32 y;
    u32 drawAlpha;
    union
    {
        u64 value;
        struct
        {
            f32 x;
            f32 y;
        } coords;
    } packed;

    packed.value = position;
    y = packed.coords.y + 404.0f;
    asm volatile("" : "+m"(y));
    x = packed.coords.x;
    drawAlpha = alpha & 0xff;
    func_001159f0(resource, resource, 0x2a, drawAlpha,
                  x, y, 48.0f);
}
// FUN_00186190 NONMATCHING
void* func_00186190(KwlnTask* task)
{
    CalendarMoonWork* work;
    u32 archiveEntry;
    void* source;
    s32 alpha;
    s32 timer;
    f32 x;
    f32 y;

    work = (CalendarMoonWork*)task->workData;
    switch (work->state)
    {
        case 0:
            if (H_Cdvd_IsFileLoaded(work->archive))
            {
                source = H_Cdvd_ArchiveGetFile(work->archive, 0, &archiveEntry);
                work->resource = func_00112420(source);
                work->state = 1;
            }
            break;

        case 1:
            if (H_Maestro_00111f30((s16*)work->resource))
            {
                work->timer = 0;
                work->selectedValue = work->currentValue;
                work->state = 2;
            }
            break;

        case 2:
            timer = ++work->timer;
            alpha = ((5 - timer) * 0xff) / 5;
            func_00186a40(work->resource, clndPackPosition(0.0f, 0.0f),
                          alpha, (s16)work->selectedValue);
            func_00186bd0(work->resource, clndPackPosition(0.0f, 0.0f),
                          alpha, (s16)work->selectedValue);
            if (timer == 5)
            {
                work->timer = 0;
                work->state = 3;
            }
            break;

        case 3:
            timer = ++work->timer;
            func_00186a40(work->resource, clndPackPosition(0.0f, 0.0f),
                          0, (s16)work->selectedValue);
            func_00186bd0(work->resource, clndPackPosition(0.0f, 0.0f),
                          0, (s16)work->selectedValue);
            if (timer == 5)
            {
                work->timer = 0;
                work->state = 4;
                if (work->targetValue == 8)
                {
                    work->state = 8;
                }
            }
            break;

        case 4:
            timer = ++work->timer;
            x = sinf((DAT_007caf38 * (f32)((timer * 0x5a) / 10)) / 180.0f);
            alpha = (timer * 0xff) / 10;
            func_00186a40(work->resource,
                          clndPackPosition(x * 300.0f, 0.0f),
                          alpha,
                          (s16)work->selectedValue);
            func_00186bd0(work->resource,
                          clndPackPosition(x * 300.0f, 0.0f),
                          alpha,
                          (s16)work->selectedValue);
            if (timer == 10)
            {
                work->selectedValue = work->targetValue;
                work->timer = 0;
                work->state = 5;
            }
            break;

        case 5:
            timer = ++work->timer;
            timer = 10 - timer;
            x = sinf((DAT_007caf38 * (f32)((timer * 0x5a) / 10)) / 180.0f);
            func_00186a40(work->resource,
                          clndPackPosition(x * -300.0f, 0.0f),
                          (timer * 0xff) / 10,
                          (s16)work->selectedValue);
            if (work->timer == 10)
            {
                work->timer = 0;
                work->state = 6;
            }
            break;

        case 6:
            timer = ++work->timer;
            func_00186a40(work->resource, clndPackPosition(0.0f, 0.0f),
                          0, (s16)work->selectedValue);
            if (timer < 10)
            {
                alpha = 0xff - (timer * 0xff) / 10;
                func_00186bd0(work->resource,
                              clndPackPosition(0.0f, 0.0f),
                              alpha,
                              (s16)work->selectedValue);
            }
            else
            {
                func_00186bd0(work->resource,
                              clndPackPosition(0.0f, 0.0f),
                              0,
                              (s16)work->selectedValue);
            }
            if (timer == 20)
            {
                work->timer = 0;
                if (work->selectedValue == work->targetValue)
                {
                    work->state = 7;
                }
                else
                {
                    work->state = 3;
                }
                if (work->selectedValue == 1 && datGetFlag(0x141c))
                {
                    work->eventTask = func_00187550(task);
                    work->state = 0xb;
                }
            }
            break;

        case 7:
            timer = ++work->timer;
            x = sinf((DAT_007caf38 * (f32)((timer * 0x5a) / 5)) / 180.0f);
            x *= CLND_MOON_X_SCALE;
            y = sinf((DAT_007caf38 * (f32)((timer * 0x5a) / 5)) / 180.0f);
            y *= CLND_MOON_Y_SCALE;
            alpha = (timer * 0xff) / 5;
            func_00186a40(work->resource,
                          clndPackPosition(x, y),
                          alpha,
                          (s16)work->selectedValue);
            func_00186bd0(work->resource,
                          clndPackPosition(x, y),
                          alpha,
                          (s16)work->selectedValue);
            if (timer == 5)
            {
                return KWLNTASK_STOP;
            }
            break;

        case 8:
            timer = ++work->timer;
            alpha = (timer * 0xff) / 10;
            func_00186a40(work->resource, clndPackPosition(0.0f, 0.0f),
                          alpha, (s16)work->selectedValue);
            func_00186bd0(work->resource, clndPackPosition(0.0f, 0.0f),
                          alpha, (s16)work->selectedValue);
            if (timer == 10)
            {
                work->timer = 0;
                work->state = 9;
            }
            break;

        case 9:
            work->transitionTask = func_001870e0(task);
            work->state = 10;
            break;

        case 10:
            if (kwlnTaskGetState(work->transitionTask) == KWLNTASK_STATE_DESTROY)
            {
                return KWLNTASK_STOP;
            }
            break;

        case 0xb:
            func_00186a40(work->resource, clndPackPosition(0.0f, 0.0f),
                          0, (s16)work->selectedValue);
            func_00186bd0(work->resource, clndPackPosition(0.0f, 0.0f),
                          0, (s16)work->selectedValue);
            if (kwlnTaskGetState(work->eventTask) == KWLNTASK_STATE_DESTROY)
            {
                work->timer = 0;
                work->state = work->selectedValue == work->targetValue ? 7 : 3;
            }
            break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_001868F0
void func_001868f0(KwlnTask* task)
{
    CalendarMoonWork* work;

    work = (CalendarMoonWork*)task->workData;
    if (work->resource != NULL)
    {
        func_001124b0(work->resource);
        work->resource = NULL;
    }
    if (work->archive != NULL)
    {
        H_Cdvd_Destroy(work->archive);
        work->archive = NULL;
    }
    CLND_FREE(work);
}

// FUN_00186960
KwlnTask* func_00186960(KwlnTask* parent, s32 currentValue, s32 targetValue)
{
    KwlnTask* task;
    CalendarMoonWork* work;

    work = CLND_ALLOC(1, sizeof(CalendarMoonWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent,
                          D_005E41F0,
                          0x18bf,
                          func_00186190,
                          func_001868f0,
                          work);
    if (task == NULL)
    {
        return NULL;
    }
    work->currentValue = currentValue;
    work->targetValue = targetValue;
    work->archive = H_Cdvd_Request(D_005E4200, 1);
    return task;
}

// FUN_00186A40 NONMATCHING
void func_00186a40(void* resource, u64 position, u32 alpha, s16 selection)
{
    s32 tile;

    tile = 0;
    if (clndIsHolidayOrSunday() != 0 && selection >= 2 && selection <= 5)
    {
        tile = 7;
    }
    else
    {
        switch (selection)
        {
            case 0: tile = 0; break;
            case 1: tile = 1; break;
            case 2: tile = 2; break;
            case 3: tile = 3; break;
            case 4: tile = 4; break;
            case 5: tile = 5; break;
            case 6: tile = 6; break;
            case 7: tile = 8; break;
            default: tile = 0; break;
        }
    }
    func_001159f0(NULL,
                  resource,
                  tile,
                  alpha & 0xff,
                  clndPackedX(position) + 207.0f,
                  clndPackedY(position) + 183.0f,
                  72.0f);
}

// FUN_00186BD0 NONMATCHING
void func_00186bd0(void* resource, u64 position, u32 alpha, s16 selection)
{
    s32 tile;

    if (alpha == 0xff)
    {
        return;
    }
    tile = 0;
    if (clndIsHolidayOrSunday() != 0 && selection >= 2 && selection <= 5)
    {
        tile = 0x11;
    }
    else
    {
        switch (selection)
        {
            case 0: tile = 0xa; break;
            case 1: tile = 0xb; break;
            case 2: tile = 0xc; break;
            case 3: tile = 0xd; break;
            case 4: tile = 0xe; break;
            case 5: tile = 0xf; break;
            case 6: tile = 0x10; break;
            case 7: tile = 0x12; break;
            default: tile = 0; break;
        }
    }
    func_001159f0(NULL,
                  resource,
                  tile,
                  alpha & 0xff,
                  clndPackedX(position) + 207.0f,
                  clndPackedY(position) + 211.0f,
                  72.0f);
}

// FUN_00186D50 NONMATCHING
void* func_00186d50(KwlnTask* task)
{
    CalendarTransitionWork* work;
    KwlnTask* child;

    work = (CalendarTransitionWork*)task->workData;
    if (work->state == 4)
    {
        work->fadeTimer++;
        if (work->fadeTimer > 40 && work->fadeTimer < 140)
        {
            H_Maestro_SetAlphaMult(work->secondTask,
                                   (100.0f - (f32)work->fadeTimer) / 100.0f);
        }
        if (kwlnTaskGetState(work->secondTask) == KWLNTASK_STATE_DESTROY)
        {
            work->secondTask = NULL;
            func_00109f60(3, 0);
            return KWLNTASK_STOP;
        }
    }
    else if (work->state == 3)
    {
        if (H_Maestro_FinishedInit(work->secondTask))
        {
            H_Fade_SetType(HFADE_DAY);
            H_Fade_SetDuration(0x28);
            if (work->firstTask != NULL)
            {
                kwlnTaskDestroyWithHierarchy(work->firstTask);
                work->firstTask = NULL;
            }
            H_Maestro_RequestDraw(work->secondTask);
            work->fadeTimer = 0;
            work->state = 4;
        }
    }
    else if (work->state == 2)
    {
        work->transitionTimer++;
        if (work->transitionTimer == 0x19)
        {
            func_0010a370(3, D_005E4260);
        }
        if (work->transitionTimer == 0x14 && H_Fade_IsHolding() == 0)
        {
            H_Fade_FadeOut();
            H_Fade_SetType(HFADE_TRANSITION2);
        }
        if (work->fadeTimer != 0x14)
        {
            work->fadeTimer++;
        }
        H_Maestro_SetAlphaMult(work->firstTask,
                               (f32)work->fadeTimer / 20.0f);
        if (H_Maestro_00111cb0(work->firstTask))
        {
            work->state = 3;
        }
    }
    else if (work->state == 1)
    {
        if (H_Maestro_FinishedInit(work->firstTask) &&
            H_Maestro_FinishedInit(work->secondTask))
        {
            H_Maestro_00111f20(work->firstTask, 1);
            H_Maestro_RequestDraw(work->firstTask);
            work->transitionTimer = 0;
            H_Maestro_SetAlphaMult(work->firstTask, 0.0f);
            work->fadeTimer = 0;
            work->state = 2;
        }
    }
    else
    {
        child = H_Maestro_CreateTask(NULL, 0x1cd2, D_005E4220);
        work->firstTask = child;
        work->secondTask = H_Maestro_CreateTask(NULL, 0x1cd2, D_005E4240);
        work->state = 1;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_00187050
void func_00187050(KwlnTask* task)
{
    CalendarTransitionWork* work;
    KwlnTask** child;
    s32 i;

    work = (CalendarTransitionWork*)task->workData;
    for (i = 0; i < 2; i++)
    {
        child = &work->firstTask + i;
        if (*child != NULL)
        {
            kwlnTaskDestroyWithHierarchy(*child);
            *child = NULL;
        }
    }
    CLND_FREE(work);
}

// FUN_001870E0
KwlnTask* func_001870e0(KwlnTask* parent)
{
    CalendarTransitionWork* work;
    KwlnTask* task;

    work = CLND_ALLOC(1, sizeof(CalendarTransitionWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    func_00108f70();
    task = kwlnTaskCreate(parent,
                          D_005E4280,
                          0x18c0,
                          func_00186d50,
                          func_00187050,
                          work);
    if (task == NULL)
    {
        return NULL;
    }
    datSetFlag(0x1412, true);
    return task;
}

// FUN_001871A0 NONMATCHING
void* func_001871a0(KwlnTask* task)
{
    CalendarRecoveredColdWork* work;
    u32 color;

    work = (CalendarRecoveredColdWork*)task->workData;
    if (work->state == 1)
        goto draw;
    if (work->state == 0)
    {
        work->messageIndex = -1;
        if (datGetFlag(0xa95) != 0)
            work->messageIndex = 0;
        if (datGetFlag(0xa96) != 0)
            work->messageIndex = 1;
        if (datGetFlag(0xa97) != 0)
            work->messageIndex = 2;
        if (datGetFlag(0xa98) != 0)
            work->messageIndex = 3;
        if (datGetFlag(0xa99) != 0)
            work->messageIndex = 4;
        if (datGetFlag(0xa9a) != 0)
            work->messageIndex = 5;
        if (datGetFlag(0xa7a) != 0)
            work->messageIndex = 6;
        if (datGetFlag(0xa9b) != 0)
            work->messageIndex = 7;
        if (datGetFlag(0xa9c) != 0)
            work->messageIndex = 8;
        if (datGetFlag(0xa9d) != 0)
            work->messageIndex = 9;
        if (datGetFlag(0xa9f) != 0)
            work->messageIndex = 10;
        if (datGetFlag(0xacd) != 0)
            work->messageIndex = 11;
        if (datGetFlag(0xace) != 0)
            work->messageIndex = 12;

        datSetFlag(0xa95, false);
        datSetFlag(0xa96, false);
        datSetFlag(0xa97, false);
        datSetFlag(0xa98, false);
        datSetFlag(0xa99, false);
        datSetFlag(0xa9a, false);
        datSetFlag(0xa7a, false);
        datSetFlag(0xa9b, false);
        datSetFlag(0xa9c, false);
        datSetFlag(0xa9d, false);
        datSetFlag(0xa9f, false);
        datSetFlag(0xacd, false);
        datSetFlag(0xace, false);

        if (work->messageIndex < 0)
            return KWLNTASK_STOP;
        work->state = 1;
    }
    return KWLNTASK_CONTINUE;

draw:
    if (work->timer < 10)
        color = (u32)((work->timer * 0xff) / 10);
    else if (work->timer < 0x51)
        color = 0xff;
    else
        color = (u32)(((0x5a - work->timer) * 0xff) / 10);

    func_003b2cb0(0.0f,
                  0x140,
                  0x17c,
                  color | 0xffffff00,
                  6,
                  1,
                  D_005E4150[work->messageIndex],
                  0x18,
                  0);
    work->timer++;
    if (work->timer > 0x59)
        return KWLNTASK_STOP;
    return KWLNTASK_CONTINUE;
}

// FUN_00187550
KwlnTask* func_00187550(KwlnTask* parent)
{
    CalendarRecoveredColdWork* work;
    KwlnTask* task;

    work = CLND_ALLOC(1, sizeof(CalendarRecoveredColdWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent,
                          D_005E4290,
                          0x18c1,
                          func_001871a0,
                          clnd00187520,
                          work);
    if (task == NULL)
    {
        return NULL;
    }
    return task;
}

// FUN_001875F0 NONMATCHING
void func_001875f0(s32 angle, s32 scaleAngle, s32 alpha)
{
    RwCamera* camera;
    RwMatrix* matrix;
    RwV3d axis;
    RwV3d local[4];
    RwV3d transformed[4];
    RwIm2DVertex vertices[4];
    f32 recipZ;
    f32 angleRadians;
    f32 scale;
    f32 radians;
    s32 i;

    camera = kwlnGetMainCamera();
    recipZ = 1.0f / camera->nearPlane;
    D_00960090(6, 1);
    D_00960090(7, 2);
    D_00960090(8, 1);
    D_00960090(9, 2);
    D_00960090(0xc, 1);
    D_00960090(0xb, 6);
    D_00960090(10, 5);
    D_00960090(2, 4);
    D_00960090(0xe, 0);

    local[0] = (RwV3d){-15.0f, -22.0f, 0.0f};
    local[1] = (RwV3d){15.0f, -22.0f, 0.0f};
    local[2] = (RwV3d){-15.0f, 22.0f, 0.0f};
    local[3] = (RwV3d){15.0f, 22.0f, 0.0f};
    axis = (RwV3d){0.0f, 0.0f, 1.0f};

    angle = clndNormalizeAngle(angle);
    angleRadians = DAT_007caf38 * (f32)angle / 180.0f;
    matrix = func_004c38c0();
    func_004c2fc0(1.0f - cosf(angleRadians),
                  sinf(angleRadians),
                  matrix,
                  &axis,
                  rwCOMBINEREPLACE);
    func_004c6c20(transformed, local, 4, matrix);
    func_004c3880(matrix);

    scaleAngle = clndNormalizeAngle(scaleAngle);
    radians = DAT_007caf38 * (f32)scaleAngle / 180.0f;
    scale = cosf(radians);
    for (i = 0; i < 4; i++)
    {
        transformed[i].x *= scale;
        vertices[i].u.els.scrVertex.x = transformed[i].x + 585.0f;
        vertices[i].u.els.scrVertex.y = transformed[i].y + 406.0f;
        vertices[i].u.els.scrVertex.z = D_00960088;
        vertices[i].u.els.camVertex_z = recipZ;
        vertices[i].u.els.u = 0.0f;
        vertices[i].u.els.v = 0.0f;
        vertices[i].u.els.recipZ = recipZ;
        vertices[i].u.els.color.r = 14.0f;
        vertices[i].u.els.color.g = 139.0f;
        vertices[i].u.els.color.b = 236.0f;
        vertices[i].u.els.color.a = (f32)alpha;
    }
    D_00960090(1, 0);
    D_009600A0(rwPRIMTYPETRISTRIP, vertices, 4);
}

// FUN_00187BE0 NONMATCHING
void* func_00187be0(KwlnTask* task)
{
    CalendarSkipDrawWork* work;
    RwCamera* camera;
    u32 oldState;

    work = (CalendarSkipDrawWork*)task->workData;
    camera = kwlnGetMainCamera();
    if (RwCameraBeginUpdate(camera) == NULL)
    {
        return KWLNTASK_CONTINUE;
    }
    D_00960094(0xe, &oldState);
    D_00960090(0xe, 0);

    if (work->state == 3)
    {
        func_001875f0(work->scaleAngle, work->angle, work->alpha);
        D_00960090(0xe, oldState);
        RwCameraEndUpdate(camera);
        work->angle += 10;
        work->alpha -= 20;
        if (work->alpha < 0)
        {
            return KWLNTASK_STOP;
        }
    }
    else if (work->state == 2)
    {
        if (datGetFlag(0x1421) == 0)
        {
            func_001875f0(work->scaleAngle, work->angle, work->alpha);
            work->angle += 10;
            work->alpha += 20;
            if (work->alpha > 0xff)
            {
                work->alpha = 0xff;
            }
        }
        else
        {
            work->alpha = 0;
        }
        D_00960090(0xe, oldState);
        RwCameraEndUpdate(camera);
    }
    else if (work->state == 1)
    {
        work->timer--;
        if (work->timer < 0)
        {
            work->state = 2;
        }
        D_00960090(0xe, oldState);
        RwCameraEndUpdate(camera);
    }
    else
    {
        work->alpha = 0;
        work->timer = 10;
        work->scaleAngle = 0x28;
        work->angle = 0;
        work->state = 1;
        D_00960090(0xe, oldState);
        RwCameraEndUpdate(camera);
    }
    return KWLNTASK_CONTINUE;
}

// FUN_00187E20
KwlnTask* func_00187e20(void)
{
    CalendarSkipDrawWork* work;
    KwlnTask* task;

    work = H_Calloc(1, sizeof(CalendarSkipDrawWork));
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(NULL,
                          D_005E42B8,
                          0x1cd6,
                          func_00187be0,
                          clnd00187df0,
                          work);
    if (task == NULL)
    {
        return NULL;
    }
    return task;
}

// FUN_00187EC0 NONMATCHING
void func_00187ec0(KwlnTask* task, s32 month, s32 day, s32 time)
{
    CalendarTransitionMessageWork* work;
    s32 tile;

    work = (CalendarTransitionMessageWork*)task->workData;
    if (datGetFlag(0x141d) != 0 || datGetFlag(0x1407) != 0)
    {
        return;
    }

    func_001159f0(NULL,
                  work->resource,
                  0x3a,
                  0,
                  CLND_CALENDAR_X + 514.0f,
                  23.0f,
                  72.0f);
    if (time == 8)
    {
        func_00115bc0(NULL,
                      work->resource,
                      0x39,
                      0,
                      0x7c,
                      0xff,
                      0x90,
                      CLND_CALENDAR_X + 390.0f,
                      -8.0f,
                      72.0f);
    }
    else
    {
        func_00115bc0(NULL,
                      work->resource,
                      0x39,
                      0,
                      0x4c,
                      0x9a,
                      0xff,
                      CLND_CALENDAR_X + 390.0f,
                      -8.0f,
                      72.0f);
    }

    if (month == 3 && day == 0x1f && time == 4)
    {
        tile = 0x50;
    }
    else if (month == 3 && day == 0x1f && time == 6)
    {
        tile = 0x51;
    }
    else if (month == 3 && day == 0x1f && time == 7)
    {
        tile = 0x52;
    }
    else if (month == 4 && day == 2 && time == 7)
    {
        tile = 0x53;
    }
    else if (month == 4 && day == 1 && time == 2)
    {
        tile = 0x54;
    }
    else
    {
        tile = 0x55;
    }
    func_001159f0(NULL,
                  work->resource,
                  tile,
                  0,
                  CLND_CALENDAR_X + 416.0f,
                  14.0f,
                  72.0f);
}

// FUN_00188250 NONMATCHING
void* func_00188250(KwlnTask* task)
{
    CalendarTransitionMessageWork* work;
    RwCamera* camera;
    u32 oldState;

    work = (CalendarTransitionMessageWork*)task->workData;
    if (work->state == 2)
    {
        CLND_CALENDAR_X = 0.0f;
        work->month = clndGetCurrentMonth();
        work->day = clndGetCurrentDay();
        work->time = datGetTime() & 0xff;
        camera = kwlnGetMainCamera();
        if (RwCameraBeginUpdate(camera) != NULL)
        {
            D_00960094(0xe, &oldState);
            D_00960090(0xe, 0);
            func_00187ec0(task, work->month, work->day, work->time);
            D_00960090(0xe, oldState);
            RwCameraEndUpdate(camera);
        }
    }
    else if (work->state == 1)
    {
        if (H_Maestro_00111f30((s16*)work->resource))
        {
            work->state = 2;
        }
    }
    else
    {
        work->resource = func_00112370(D_005E4190);
        work->state = 1;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_001883D0
void func_001883d0(KwlnTask* task)
{
    CalendarTransitionMessageWork* work;

    work = (CalendarTransitionMessageWork*)task->workData;
    if (work->resource != NULL)
    {
        func_001124b0(work->resource);
        work->resource = NULL;
    }
    CLND_FREE(work);
}

// FUN_00188420
void func_00188420(KwlnTask* task, s32 month, s32 day, s32 time)
{
    CalendarTransitionMessageWork* work;

    work = (CalendarTransitionMessageWork*)task->workData;
    work->month = month;
    work->day = day;
    work->time = time;
}

// FUN_00188440
KwlnTask* func_00188440(KwlnTask* parent, s32 month, s32 day, s32 time)
{
    CalendarTransitionMessageWork* work;
    KwlnTask* task;

    work = CLND_ALLOC(1, sizeof(CalendarTransitionMessageWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent,
                          D_005E42D0,
                          0x18b2,
                          func_00188250,
                          func_001883d0,
                          work);
    if (task == NULL)
    {
        return NULL;
    }
    work->month = month;
    work->day = day;
    work->time = time;
    return task;
}
