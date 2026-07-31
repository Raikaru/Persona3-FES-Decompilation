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
extern u16 datGetMaxHp(s16 pcId);
#define CLND_ALLOC(count, size, flags) \
    (*(void* (**)(u32, u32, u32))D_00960184)((count), (size), (flags))
#define CLND_FREE(memory) (*(void (**)(void*))jtbl_0096017C)((memory))
typedef struct
{
    f32 x;
    f32 y;
} CalendarPackedPosition;

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
#pragma alias clndIsHolidayOrSunday_u32 clndIsHolidayOrSunday
extern u32 clndIsHolidayOrSunday_u32(void);
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
void func_00185980(void* resource, CalendarPackedPosition position, u32 alpha, s16 day);
void func_00185ae0(void* resource, CalendarPackedPosition position, u32 alpha, s16 day);
void func_00185b40(void* resource, CalendarPackedPosition position, u32 unused, s16 month, s16 day);
void func_00186050(void* resource, CalendarPackedPosition position, u32 alpha);
void func_00186100(void* resource, CalendarPackedPosition position, u32 alpha);
void func_00186140(void* resource, CalendarPackedPosition position, u32 alpha);
void* func_00186190(KwlnTask* task);
void func_001868f0(KwlnTask* task);
KwlnTask* func_00186960(KwlnTask* parent, s32 currentValue, s32 targetValue);
void func_00186a40(void* resource, CalendarPackedPosition position, u32 alpha, s16 selection);
void func_00186bd0(void* resource, CalendarPackedPosition position, u32 alpha, s16 selection);
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
#pragma alias func_00188640_calendar func_00188640
extern KwlnTask* func_00188640_calendar(void);
u32 clnd00184d90(KwlnTask* task);
KwlnTask* func_00181950(KwlnTask* clndTask, s32 eventIndex);
typedef struct
{
    u8* records;
    u32 total;
} CalendarDateTable;

extern u16* func_00170620(s16 pcId, s16 index);
extern void datSetFlag(s32 bit, u8 enabled);
extern s32 clndGetMonthFromDaysSinceApr5(s32 daysSinceApr5);
extern s32 clndGetDayOfMonthFromDaysSinceApr5(s32 daysSinceApr5);
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

extern const u8 D_005E3C20[];
#define CLND_SCHEDULE_DEFAULTS ((const u8*)0x005e3bc0)
void* clndUpdateTask(KwlnTask* clndTask);
void clndDestroyTask(KwlnTask* clndTask);

 
// FUN_0017FC70
KwlnTask* func_0017fc70(KwlnTask* clndTask)
{
    s32 eventIndex;
    KwlnTask* task = clndTask;
    KwlnTask* actionTask = NULL;

    if (datGetSkipToTarget() == 0)
    {
        if (datGetFlag(0xa02) != 1)
        {
            eventIndex = clndFindAndExecSiteibiEvents();
            if (eventIndex != -1)
            {
                return func_00181950(task, eventIndex);
            }
            else
            {
                H_Dbprt_FmtLog("calendar: no late-night event");
                {
                    u8 time = datGetTime() & 0xff;
                    actionTask = func_003c1ab0(task, time);
                }
            }
        }
    }

    return actionTask;
}

// FUN_0017FD30
u32 func_0017fd30(void)
{
    s32 pcId;
    s32 index;
    const s16* sourceBase;
    const s16* source;
    s16 value;
    s16* destination;

    for (pcId = 2; pcId < 0xb; pcId++)
    {
        index = 0;
        sourceBase = (const s16*)(D_005E3C20 + pcId * 0x30);
        for (; index < 0xc; index++)
        {
            source = sourceBase + index * 2;
            value = source[-0x30];
            destination = (s16*)func_00170620(pcId, index);
            destination[0] = value;
            value = source[-0x2f];
            destination = (s16*)func_00170620(pcId, index);
            destination[1] = value;
        }
    }

    return true;
}

// FUN_0017FE10
void func_0017fe10(KwlnTask* clndTask)
{
    CalendarDateTable* table;
    s32 i;
    s32 day;
    s32 month;
    u16 flag;
    u32 index;
    const s16* sourceBase;
    const s16* source;
    s16 value;
    u16* destination;
    s32 recordVal;
    int recAddr;

    for (i = 0xbd0; i < 0xc00; i++)
    {
        datSetFlag(i, false);
    }
    datSetFlag(0xa01, false);
    datSetFlag(0xa02, false);
    datSetFlag(0xa04, false);

    table = func_003bd8a0();
    for (month = 2; month < 0xb; month++)
    {
        day = 0;
        sourceBase = (const s16*)(D_005E3C20 + month * 0x30);
        for (; day < 0xc; day++)
        {
            source = sourceBase + day * 2;
            value = source[-0x30];
            destination = func_00170620(month, day);
            destination[0] = value;
            value = source[-0x2f];
            destination = func_00170620(month, day);
            destination[1] = value;
        }
    }

    for (index = 0; index < table->total; index++)
    {
        month = clndGetMonthFromDaysSinceApr5(datGetDaysSinceApr5());
        recordVal = table->records[index * 6];
        if (recordVal != month)
        {
            continue;
        }
        day = clndGetDayOfMonthFromDaysSinceApr5(datGetDaysSinceApr5());
        recAddr = (int)table->records + index * 6;
        recordVal = *(u8 *)(recAddr + 1);
        if (recordVal != day)
        {
            continue;
        }
        flag = *(const u16*)(recAddr + 2);
        if (flag != 0)
        {
            datSetFlag(flag, true);
        }
        flag = *(const u16*)((int)table->records + index * 6 + 4);
        if (flag != 0)
        {
            datSetFlag(flag, false);
        }
    }
    func_001b7700(clndTask);
}

/* W212: first divergence is the prologue (ours 0x60-byte frame, retail 0x40).
 * Recomputing dates in-loop measured nd202 -> nd296 (424/496), and additionally
 * recomputing the record measured nd342 (480/496); both honest probes were reverted. */
// FUN_00180030
void func_00180030(void)
{
    CalendarDateTable* table;
    u32 i;
    u32 currentDate;
    u32 recordDate;
    u8* records;

    table = func_003bd890();
    for (i = 0; i < table->total; i++)
    {
        currentDate = clndGetMonthFromDaysSinceApr5(datGetDaysSinceApr5());
        recordDate = table->records[i * 4];
        if (recordDate != currentDate)
        {
            continue;
        }
        currentDate = clndGetDayOfMonthFromDaysSinceApr5(datGetDaysSinceApr5());
        records = table->records;
        records += i * 4;
        recordDate = records[1];
        if (recordDate != currentDate)
        {
            continue;
        }

        if (table->records[i * 4 + 2] == 1)
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
            records = table->records;
            records += i * 4;
            if (records[3] == 5)
            {
                datSetFlag(0xa98, true);
            }
            records = table->records;
            records += i * 4;
            if (records[3] == 3)
            {
                datSetFlag(0xa99, true);
            }
            records = table->records;
            records += i * 4;
            if (records[3] == 2)
            {
                datSetFlag(0xa9b, true);
            }
        }

        records = table->records;
        func_0016d6b0(*(u8 *)((int)records + i * 4 + 2),
                      *(u8 *)((int)records + i * 4 + 3));
    }
}

// FUN_00180220 NONMATCHING
void func_00180220(void)
{
    CalendarDateTable* table;
    u32 i;
    s32 socialLink;
    s32 oldCondition;
    s32 newCondition;
    s32 amount;
    u32 randomValue;
    u32 currentDate;

    for (socialLink = 1; socialLink <= 10; socialLink++)
    {
        table = func_003bd890();
        for (i = 0; i < table->total; i++)
        {
            currentDate = clndGetMonthFromDaysSinceApr5(datGetDaysSinceApr5());
            if (currentDate != table->records[i * 4])
            {
                continue;
            }
            currentDate = clndGetDayOfMonthFromDaysSinceApr5(datGetDaysSinceApr5());
            if (currentDate != table->records[i * 4 + 1])
            {
                continue;
            }
            if (table->records[i * 4 + 2] == socialLink)
            {
                break;
            }
        }
        if (i < table->total)
        {
            continue;
        }

        oldCondition = func_0016c920(socialLink);
        newCondition = oldCondition;
        FUN_0016f3e0(socialLink + 0x19,
                     FUN_0016f380(socialLink + 0x19));

        if (oldCondition == 5)
        {
                amount = FUN_0016f380(socialLink + 0x19);
                if (amount < 0)
                {
                    amount = 0;
                }
                FUN_0016f3e0(socialLink + 0x19, amount);
                randomValue = func_00488f30();
                amount = FUN_0016f380(socialLink + 0xf) -
                         (randomValue % 40 + 20);
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

        else if (oldCondition == 3)
        {
                amount = FUN_0016f380(socialLink + 0x19);
                if (amount < 0)
                {
                    amount = 0;
                }
                FUN_0016f3e0(socialLink + 0x19, amount);
                if (socialLink == 3)
                {
                    randomValue = func_00488f30();
                    amount = FUN_0016f380(0x12) -
                             (randomValue % 20 + 25);
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
                        randomValue = func_00488f30();
                        amount = FUN_0016f380(socialLink + 0xf) -
                                 (randomValue % 20 + 25);
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

        else if (oldCondition == 2)
        {
                amount = FUN_0016f380(socialLink + 0xf) - 1;
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
    for (socialLink = 1; socialLink <= 10; socialLink++)
    {
        datSetHp(socialLink, datGetMaxHp(socialLink));
        datSetSp(socialLink, func_0016c670(socialLink));
        datClearBadStatus(socialLink, 0x80000);
    }
}

// FUN_00180A20
KwlnTask* func_00180a20(KwlnTask* clndTask)
{
    s32 eventIndex;
    KwlnTask* task;
    CalendarTaskWork* work;

    task = clndTask;
    work = task->workData;

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
        if (eventIndex != -1)
        {
            return func_00181950(task, eventIndex);
        }
        if (datGetFlag(0xa00) == 1)
        {
            return NULL;
        }
        if (datGetSkipToTarget() == 0)
        {
            if (datGetFlag(0x1403) == 0)
            {
                datSetFlag(0x1403, true);
                datSetDaysSkipTarget(datGetDaysSinceApr5());
                datSetTimeSkipTarget_u8(datGetTime());
                datSetSkipToTarget(true);
                if (datGetFlag(0xbdf) == 1)
                {
                    if ((datGetTime() & 0xff) == 0)
                    {
                        func_00184c80(work->confirmationTask, true);
                    }
                    else
                    {
                        func_001848f0(work->confirmationTask, true);
                    }
                    return func_001ba5f0(task, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x320, 1, 0, 0);
                }
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

// FUN_00180EE0
KwlnTask* func_00180ee0(KwlnTask* clndTask)
{
    s32 eventIndex;
    KwlnTask* task = clndTask;
    KwlnTask* actionTask = NULL;

    H_Dbprt_FmtLog("calendar: morning");
    datSetFlag(0xa80, false);
    datSetFlag(0xa81, true);
    datSetFlag(0xa82, false);
    datSetFlag(0xa83, false);
    datSetFlag(0xa84, false);
    datSetFlag(0xa85, false);
    datSetFlag(0xa86, false);
    datSetFlag(0xa87, false);

    if (datGetSkipToTarget() == 0)
    {
        eventIndex = clndFindAndExecSiteibiEvents();
        if (eventIndex != -1)
        {
            return func_00181950(task, eventIndex);
        }
        func_0017db40(datGetDaysSinceApr5());
        actionTask = func_003c1ab0(task, datGetTime() & 0xff);
    }
    return actionTask;
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

extern const char D_005E3E70[];
// FUN_00181310
KwlnTask* func_00181310(KwlnTask* clndTask)
{
    s32 eventIndex;
    KwlnTask* task = clndTask;
    KwlnTask* actionTask = NULL;

    datSetFlag(0xa80, false);
    datSetFlag(0xa81, false);
    datSetFlag(0xa82, false);
    datSetFlag(0xa83, false);
    datSetFlag(0xa84, true);
    datSetFlag(0xa85, false);
    datSetFlag(0xa86, false);
    datSetFlag(0xa87, false);

    if (datGetSkipToTarget() == 0)
    {
        H_Dbprt_FmtLog(D_005E3E70);
        eventIndex = clndFindAndExecSiteibiEvents();
        if (eventIndex != -1)
        {
            return func_00181950(task, eventIndex);
        }
        actionTask = func_003c1ab0(task, datGetTime() & 0xff);
    }
    return actionTask;
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

// FUN_00181580
KwlnTask* func_00181580(KwlnTask* clndTask, u32* specialAction)
{
    u32 sequenceData[2];
    s32 eventIndex;
    KwlnTask* result;

    result = NULL;
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
        goto done;
    }
    if (datGetFlag(0xa05) == 1)
    {
        sequenceData[0] = 1;
        sequenceData[1] = 0;
        adminiChangeSeq(ADMINI_SEQ_DUNGEON, sequenceData, 8, false);
        *specialAction = true;
        datSetFlag(0xa05, false);
        return NULL;
    }
    if (datGetFlag(0xa03) == 1)
    {
        datSetFlag(0xa03, false);
        eventIndex = clndFindAndExecSiteibiEvents();
        if (eventIndex != -1)
        {
            return func_00181950(clndTask, eventIndex);
        }
        else
        {
            result = func_003c1ab0(clndTask, datGetTime() & 0xff);
        }
    }

done:
    return result;
}

// W295: fell to volatile lhu arg pin + pointer-cast offset addu orientation; not a floor.
// FUN_00181950
KwlnTask* func_00181950(KwlnTask* clndTask, s32 eventIndex)
{
    CalendarTaskWork* work;
    SiteibiEventTable* eventTable;
    KwlnTask* actionTask;
    volatile u16* sitePtr;

    work = clndTask->workData;
    eventTable = Comu_GetSiteibiEvtTable();
    if (eventTable->events[eventIndex].unk_07 != 0xff)
    {
        H_Dbprt_FmtLog("calendar: siteibi event %d",
                       eventTable->events[eventIndex].scrPrcdIdx);
        actionTask = func_001ba5f0(
            clndTask, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            eventTable->events[eventIndex].scrPrcdIdx,
            eventTable->events[eventIndex].unk_06,
            eventTable->events[eventIndex].unk_07, 0);
        if (datGetTime() == CALENDAR_TIME_NULL)
        {
            func_00184c80(work->confirmationTask, true);
        }
        else
        {
            func_001848f0(work->confirmationTask, true);
        }
    }
    else
    {
        H_Dbprt_FmtLog("calendar: siteibi procedure %d",
                       eventTable->events[eventIndex].scrPrcdIdx);
        sitePtr = (volatile u16 *)((u8 *)(eventIndex * (s32)sizeof(SiteibiEvent)) + (int)eventTable->events + 4);
        actionTask = func_003bdd60(0xf, *sitePtr);
    }

    datSetDaysSkipTarget(clndGetDaysSinceStartFromDate(
        eventTable->events[eventIndex].endMonth,
        eventTable->events[eventIndex].endDay));
    datSetTimeSkipTarget_u8(eventTable->events[eventIndex].endTime);
    datSetSkipToTarget(true);
    return actionTask;
}

// FUN_0017DB40 NONMATCHING
u32 func_0017db40(s16 daysSinceApr5)
{
    s16 month;
    s16 day;
    s16 days;
    s16 i;

    if ((daysSinceApr5 + CALENDAR_DAY_MAX) % CALENDAR_DAY_MAX ==
        CALENDAR_DAY_SUNDAY)
    {
        return true;
    }

    month = CALENDAR_MONTH_APRIL;
    days = daysSinceApr5 + 4;
    while (days >= ((const s16*)gNumOfDaysInMonths_abs)[month - 1])
    {
        days -= ((const s16*)gNumOfDaysInMonths_abs)[month - 1];
        month++;
        if (month > CALENDAR_MONTH_DECEMBER)
        {
            month = CALENDAR_MONTH_JANUARY;
        }
    }

    day = daysSinceApr5 + 4;
    i = CALENDAR_MONTH_APRIL;
    while (day >= gNumOfDaysInMonths[i - 1])
    {
        day -= gNumOfDaysInMonths[i - 1];
        i++;
        if (i > CALENDAR_MONTH_DECEMBER)
        {
            i = CALENDAR_MONTH_JANUARY;
        }
    }
    day++;

    for (i = 0; i < 0x164; i++)
    {
        if (sHolidays[i].month == -1)
        {
            break;
        }
        if (sHolidays[i].month == month && sHolidays[i].day == day)
        {
            return true;
        }
    }
    return false;
}

#pragma push
#pragma opt_propagation off

// Residual is limited to MWCC register coloring and branch layout; date and holiday logic matches retail.
// FUN_0017DDF0 NONMATCHING
u32 func_0017ddf0(s16* monthOut, s16* dayOut)
{
    s16 month;
    s16 currentDay;
    s16 nextDay;
    s16 day;
    s16 i;
    s16 days;
    s16 remaining;
    const s16* numOfDays;
    s16 isHoliday;

    currentDay = datGetDaysSinceApr5() + 1;
    for (;;)
    {
        nextDay = currentDay;
        if (nextDay >= 0x15f)
        {
            return false;
        }

        if ((nextDay + 7) % CALENDAR_DAY_MAX == CALENDAR_DAY_SUNDAY)
        {
            isHoliday = true;
            goto check;
        }

        month = clndGetMonthFromDaysSinceApr5(nextDay);
        day = clndGetDayOfMonthFromDaysSinceApr5(nextDay);
        isHoliday = false;
        for (i = 0; i < 0x164; i++)
        {
            if (sHolidays[i].month == -1)
            {
                goto check;
            }
            if (month == sHolidays[i].month && day == sHolidays[i].day)
            {
                isHoliday = true;
                goto check;
            }
        }

check:
        if (!isHoliday)
        {
            currentDay++;
            continue;
        }
        month = CALENDAR_MONTH_APRIL;
        days = nextDay + 4;
        remaining = days;
        numOfDays = (const s16*)gNumOfDaysInMonths_abs;
        while (remaining >= numOfDays[month - 1])
        {
            remaining -= numOfDays[month - 1];
            month++;
            if (month >= CALENDAR_MONTH_MAX)
            {
                month = CALENDAR_MONTH_JANUARY;
            }
        }

        numOfDays = (const s16*)gNumOfDaysInMonths_abs;
        for (i = CALENDAR_MONTH_APRIL;;)
        {
            if (days < numOfDays[i - 1])
            {
                break;
            }
            days -= numOfDays[i - 1];
            i++;
            if (i >= CALENDAR_MONTH_MAX)
            {
                i = CALENDAR_MONTH_JANUARY;
            }
        }

        *monthOut = month;
        *dayOut = days + 1;
        return true;

    }
}
#pragma pop

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

    switch (category)
    {
    case 0:
        return currentMonth == month && daysSinceApr5 + 1 == day;
    case 1:
        return (datGetDaysSinceApr5() + CALENDAR_DAY_MAX) %
                   CALENDAR_DAY_MAX == CALENDAR_DAY_SUNDAY;
    case 2:
        return (datGetDaysSinceApr5() + CALENDAR_DAY_MAX) %
                   CALENDAR_DAY_MAX == CALENDAR_DAY_MONDAY;
    case 3:
        return (datGetDaysSinceApr5() + CALENDAR_DAY_MAX) %
                   CALENDAR_DAY_MAX == CALENDAR_DAY_TUESDAY;
    case 4:
        return (datGetDaysSinceApr5() + CALENDAR_DAY_MAX) %
                   CALENDAR_DAY_MAX == CALENDAR_DAY_WEDNESDAY;
    case 5:
        return (datGetDaysSinceApr5() + CALENDAR_DAY_MAX) %
                   CALENDAR_DAY_MAX == CALENDAR_DAY_THURSDAY;
    case 6:
        return (datGetDaysSinceApr5() + CALENDAR_DAY_MAX) %
                   CALENDAR_DAY_MAX == CALENDAR_DAY_FRIDAY;
    case 7:
        return (datGetDaysSinceApr5() + CALENDAR_DAY_MAX) %
                   CALENDAR_DAY_MAX == CALENDAR_DAY_SATURDAY;
    case 100:
        return func_0017db40(datGetDaysSinceApr5());
    case 0x65:
        return (datGetDaysSinceApr5() + CALENDAR_DAY_MAX) %
                   CALENDAR_DAY_MAX != CALENDAR_DAY_SUNDAY;
    default:
        return week == category / 10 - 1 &&
               (datGetDaysSinceApr5() + CALENDAR_DAY_MAX) %
                   CALENDAR_DAY_MAX == category % 10 - 1;
    }
}

// FUN_0017F8D0
void func_0017f8d0(void)
{
    CalendarTaskWork* work;

    if (sClndTask == NULL)
    {
        return;
    }

    if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
    {
        work = sClndTask->workData;
        if (work->state != CLNDTASK_STATE_WAIT_SKIP_CONFIRM)
        {
            work->state = CLNDTASK_STATE_CONFIRM_DAY_CHANGE;
        }
        if (work->actionTask != NULL)
        {
            kwlnTaskDestroyWithHierarchy(work->actionTask);
            work->actionTask = NULL;
        }
    }
    else
    {
        work = sClndTask->workData;
        if (work->state != CLNDTASK_STATE_BEGIN_DAY)
        {
            work->state = CLNDTASK_STATE_DEBUG_WAIT_CLOSE;
        }
        if (work->actionTask != NULL)
        {
            kwlnTaskDestroyWithHierarchy(work->actionTask);
            work->actionTask = NULL;
        }
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


 
#pragma push
/* Removing this loses FUN_0017d830 (MATCH nd0 -> MISMATCH nd93) and 4 more - measured W161. */
#pragma opt_loop_invariants on
 
// FUN_0017d830 MATCHING
s32 clndGetMonthFromDaysSinceApr5(s32 daysSinceApr5)
{
    s16 days;
    s16 month;

    month = CALENDAR_MONTH_APRIL;
    days = daysSinceApr5 + 4;

    while (true)
    {
        if (days < ((const s16*)gNumOfDaysInMonths_abs)[month - 1])
        {
            break;
        }

        days -= ((const s16*)gNumOfDaysInMonths_abs)[month - 1];
        month++;

        if (month > CALENDAR_MONTH_DECEMBER)
        {
            month = CALENDAR_MONTH_JANUARY;
        }
    }

    return month;
}

#pragma opt_propagation on
// FUN_0017d8b0 MATCHING
s32 clndGetDaysSinceStartFromDate(s32 month, s32 day)
{
    s32 dayAccumulator = 0;
    s32 m = CALENDAR_MONTH_APRIL;
    s32 monthEnd = CALENDAR_MONTH_MAX;
    s32 monthsInYear = CALENDAR_MONTH_DECEMBER;
    s32 firstMonth = CALENDAR_MONTH_JANUARY;
    s32 startMonth;
    startMonth = m;

    for (;;)
    {
        if (month == startMonth)
        {
            break;
        }

        dayAccumulator += ((const s16*)gNumOfDaysInMonths_abs)[m - 1];
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

// FUN_0017d920 MATCHING
u32 clndGetCurrentMonth()
{
    s16 daysSinceApr5;
    s16 month;

    daysSinceApr5 = datGetDaysSinceApr5();
    month = CALENDAR_MONTH_APRIL;
    daysSinceApr5 += 4;
    while (true)
    {
        if (daysSinceApr5 < gNumOfDaysInMonths[month - 1])
        {
            break;
        }

        daysSinceApr5 -= gNumOfDaysInMonths[month - 1];
        month++;
        if (month > CALENDAR_MONTH_DECEMBER)
        {
            month = CALENDAR_MONTH_JANUARY;
        }
    }

    return month;
}

// FUN_0017d9c0 MATCHING
s32 clndGetDayOfMonthFromDaysSinceApr5(s32 daysSinceApr5)
{
    s16 days;
    s16 month;

    month = CALENDAR_MONTH_APRIL;
    days = daysSinceApr5 + 4;

    while (true)
    {
        if (days < gNumOfDaysInMonths[month - 1])
        {
            break;
        }

        days -= gNumOfDaysInMonths[month - 1];
        month++;

        if (month > CALENDAR_MONTH_DECEMBER)
        {
            month = CALENDAR_MONTH_JANUARY;
        }
    }

    return days + 1;
}

// FUN_0017da40. Return the current day of the month MATCHING
u32 clndGetCurrentDay()
{
    s16 daysSinceApr5;
    s16 month;
    daysSinceApr5 = datGetDaysSinceApr5();
    month = CALENDAR_MONTH_APRIL;
    daysSinceApr5 += 4;
    while (true)
    {
        if (daysSinceApr5 < gNumOfDaysInMonths[month - 1])
        {
            break;
        }

        daysSinceApr5 -= gNumOfDaysInMonths[month - 1];
        month++;
        if (month > CALENDAR_MONTH_DECEMBER)
        {
            month = CALENDAR_MONTH_JANUARY;
        }
    }

    return daysSinceApr5 + 1;
}
#pragma pop

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

#pragma push
#pragma opt_loop_invariants on
// FUN_0017dcf0
u8 clndIsHolidayOrSunday()
{
    s16 daysSinceApr5;
    s16 currDayOfMonth;
    s16 currMonth;
    s16 i;
    s32 month;
    const Holiday* holidays;
    s32 day;
    s16 sentinel;

    daysSinceApr5 = datGetDaysSinceApr5();
    if ((daysSinceApr5 + CALENDAR_DAY_MAX) % CALENDAR_DAY_MAX == CALENDAR_DAY_SUNDAY)
    {
        return true;
    }

    currMonth = clndGetMonthFromDaysSinceApr5(daysSinceApr5);
    currDayOfMonth = clndGetDayOfMonthFromDaysSinceApr5(daysSinceApr5);
    i = 0;
    month = currMonth;
    day = currDayOfMonth;
    holidays = sHolidays;
    sentinel = -1;
    for (; i < 0x164; i++)
    {
        if (holidays[i].month == sentinel)
        {
            break;
        }
        if (month == holidays[i].month && day == holidays[i].day)
        {
            return true;
        }
    }

    return false;
}
#pragma pop

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
    u16 padState;
    u32 specialAction;
    KwlnTask* actionTask;

    switch (work->state)
    {
        case CLNDTASK_STATE_DEBUG_INIT:
        {
            struct
            {
                RwRect rect;
                RwV2d pos;
                RwRGBA color;
            } debug;
            debug.rect.x = 0;
            debug.rect.y = 0;
            debug.rect.w = 252;
            debug.rect.h = 168;
            debug.pos.x = 24.0f;
            debug.pos.y = 84.0f;
            debug.color.r = 0;
            debug.color.g = 0;
            debug.color.b = 100;
            debug.color.a = 255;
            work->debugCursorBg = H_Cursor_CreateTask(clndTask,
                                                       2.0f,
                                                       debug.pos,
                                                       debug.rect,
                                                       debug.color);
            debug.rect.x = 0;
            debug.rect.y = 0;
            debug.rect.w = 36;
            debug.rect.h = 12;
            debug.color.r = 120;
            debug.color.g = 0;
            debug.color.b = 0;
            debug.color.a = 255;
            work->debugCursor = H_Cursor_CreateTask(clndTask,
                                                     1.0f,
                                                     debug.pos,
                                                     debug.rect,
                                                     debug.color);
            work->state = CLNDTASK_STATE_DEBUG_UPDATE;
            break;
        }

        case CLNDTASK_STATE_DEBUG_UPDATE:
        {
            RwV2d pos;
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
        }

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
            work->debugCursor = func_00188640_calendar();
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

/* W212: first divergence is the prologue (ours 0x50-byte frame, retail 0x60).
 * Delaying the event pointer and retaining startTime across its call reconciled
 * the frame but regressed nd298 -> nd329 (512/560), so the probe was reverted. */
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
extern u16 DAT_007e094e;
extern u16 DAT_007e0952;
#pragma alias DAT_007e094e_abs DAT_007e094e
#pragma alias DAT_007e0952_abs DAT_007e0952
extern u8 DAT_007e094e_abs[];
extern u8 DAT_007e0952_abs[];


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

// FUN_00181CC0
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
    RwV2d position;
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

            {
                s32 scenarioMonth;
                s32 scenarioDay;
                s32 scenarioTime;
                scenarioMonth = scenarioTable[func_0017d810()].month;
                scenarioDay = scenarioTable[func_0017d810()].day;
                scenarioTime = scenarioTable[func_0017d810()].time;
                datSetDaysSinceApr5(clndGetDaysSinceStartFromDate(scenarioMonth, scenarioDay));
                datSetTime((u8)scenarioTime);

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
                work->calendarDisplayTask = func_00188440(parent, scenarioMonth, scenarioDay, scenarioTime);
            }
            else
            {
                func_00188420(displayTask, scenarioMonth, scenarioDay, scenarioTime);
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
            }

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
            if ((*(u16*)DAT_007e094e_abs & 0x40) != 0)
            {
                work->state = 0;
            }
            else
            {
                u16 debugPad = *(u16*)DAT_007e0952_abs;
                if ((debugPad & 0x1000) != 0)
                {
                    func_0017d820(func_0017d810() + 1);
                }
                else if ((debugPad & 0x4000) != 0 && func_0017d810() != 0)
                {
                    func_0017d820(func_0017d810() - 1);
                }
            }
            position.x = 2.0f;
            position.y = 2.0f;
            {
                u32 debugIndex = func_0017d810();
                H_Dbprt_FmtAt(position,
                              D_005E3F00,
                              debugIndex);
            }
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

// FUN_00182810
u8 func_00182810(u32 index)
{
    u8* weights;
    s32 random;

    weights = (u8*)(uintptr_t)func_001714b0(index);
    random = func_00488f30() % 100;
    if (random < weights[4])
    {
        return 4;
    }
    if (random < weights[3] + weights[4])
    {
        return 3;
    }
    if (random < weights[2] + weights[3] + weights[4])
    {
        return 2;
    }
    return random < weights[1] + weights[2] + weights[3] + weights[4];
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
    u16 minimum;
    u16 maximum;
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
        range = (u16*)(uintptr_t)func_001714d0(*(u16*)(resource + 0x0a)) +
                out->unk_08 * 2;
        minimum = range[0];
        maximum = range[1];
        percent = (s32)(func_00488f30() % 100) + 1;
        value = (s32)minimum + ((s32)maximum - minimum) * percent / 100;
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
        range = (u16*)(uintptr_t)func_001714d0(*(u16*)(resource + 0x0a)) +
                out->unk_08 * 2;
        minimum = range[0];
        maximum = range[1];
        percent = (s32)(func_00488f30() % 100) + 1;
        value = (s32)minimum + ((s32)maximum - minimum) * percent / 100;
        out->unk_0e = (u16)((u16)*(u16*)(resource + 8) * (value & 0xffff) / 100);
        out->effect = effect;
        return 1;
    }
    resource = (u8*)func_00170d60(id);
    out->id = id;
    out->type = *(u32*)(resource + 4);
    out->unk_08 = 2;
    range = (u16*)(uintptr_t)func_001714d0(*(u16*)(resource + 0x0a)) +
            out->unk_08 * 2;
    minimum = range[0];
    maximum = range[1];
    percent = (s32)(func_00488f30() % 100) + 1;
    value = (s32)minimum + ((s32)maximum - minimum) * percent / 100;
    out->firstStat = (u16)((u16)*(u16*)(resource + 8) * (value & 0xffff) / 100);
    range = (u16*)(uintptr_t)func_001714d0(*(u16*)(resource + 0x0e)) +
            out->unk_08 * 2;
    minimum = range[0];
    maximum = range[1];
    percent = (s32)(func_00488f30() % 100) + 1;
    value = (s32)minimum + ((s32)maximum - minimum) * percent / 100;
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
    u32 oldState;

    work = (CalendarConfirmWork*)task->workData;
    if (RwCameraBeginUpdate(kwlnGetMainCamera()) == NULL)
    {
        return KWLNTASK_CONTINUE;
    }

    D_00960094(14, &oldState);
    D_00960090(14, 0);
    work->frame = (work->frame + 1) % 0x168;

    if (work->state >= 2 && work->confirmed == 0)
    {
        D_00960090(14, oldState);
        RwCameraEndUpdate(kwlnGetMainCamera());
        return KWLNTASK_CONTINUE;
    }

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

            case 3:
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

    D_00960090(14, oldState);
    RwCameraEndUpdate(kwlnGetMainCamera());
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

    switch (phase)
    {
        case 0:
        case 1:
            frame = 3;
            break;
        case 2:
        case 3:
            frame = 4;
            break;
        case 4:
        case 5:
            frame = 5;
            break;
        case 6:
            frame = 6;
            break;
        case 7:
        case 8:
            frame = 7;
            break;
        case 9:
        case 10:
        case 11:
            frame = 8;
            break;
        case 12:
        case 13:
            frame = 9;
            break;
        case 14:
            frame = 10;
            break;
        case 15:
        case 16:
            frame = 11;
            break;
        case 17:
        case 18:
        case 19:
            frame = 12;
            break;
        case 20:
        case 21:
            frame = 13;
            break;
        case 22:
            frame = 14;
            break;
        case 23:
        case 24:
            frame = 15;
            break;
        case 25:
        case 26:
            frame = 16;
            break;
        case 27:
        case 28:
            frame = 17;
            break;
        case 29:
            frame = 18;
            break;
        default:
            frame = 0;
            break;
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
    u32 red;
    u32 green;
    u32 blue;
    s32 weekday;
    s32 days;
    void* unused;

    if (alpha < 0x28)
    {
        alpha = 0x28;
    }
    if (month >= 10)
    {
        func_00115bc0(unused, resource, 0x24, alpha & 0xff,
                      0, 0x0e, 2,
                      baseX + 515.0f, baseY + 15.0f, 50.0f);
    }
    func_00115bc0(unused, resource, (month % 10) + 0x23, alpha & 0xff,
                  0, 0x0e, 2,
                  baseX + 532.0f, baseY + 15.0f, 50.0f);
    func_00115bc0(unused, resource, 0x2d, alpha & 0xff,
                  0, 0x0e, 2,
                  baseX + 548.0f, baseY + 15.0f, 50.0f);
    if (day >= 10)
    {
        func_00115bc0(unused, resource, day / 10 + 0x23, alpha & 0xff,
                      0, 0x0e, 2,
                      baseX + 557.0f, baseY + 15.0f, 50.0f);
    }
    func_00115bc0(unused, resource, day % 10 + 0x23, alpha & 0xff,
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
        case 0: weekday = 0x22; break;
        case 1: weekday = 0x1c; break;
        case 2: weekday = 0x1d; break;
        case 3: weekday = 0x1e; break;
        case 4: weekday = 0x1f; break;
        case 5: weekday = 0x20; break;
        case 6: weekday = 0x21; break;
        default: break;
    }
    func_00115bc0(unused, resource, weekday, alpha & 0xff,
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
    void* unused;

    days = clndGetDaysSinceStartFromDate(month, day);
    if (func_0017db40(days) == 1 && time >= 2 && time <= 5)
    {
        func_001159f0(unused, resource, 0x36, alpha & 0xff,
                      baseX + 525.0f, baseY + 29.0f, 50.0f);
        return;
    }

    switch (time)
    {
        case 0:
        case 7:
            func_001159f0(unused, resource, 0x35, alpha & 0xff,
                          baseX + 491.0f, baseY + 29.0f, 50.0f);
            return;
        case 1:
            func_001159f0(unused, resource, 0x2f, alpha & 0xff,
                          baseX + 452.0f, baseY + 29.0f, 50.0f);
            return;
        case 2:
            func_001159f0(unused, resource, 0x30, alpha & 0xff,
                          baseX + 524.0f, baseY + 29.0f, 50.0f);
            return;
        case 3:
            func_001159f0(unused, resource, 0x31, alpha & 0xff,
                          baseX + 495.0f, baseY + 29.0f, 50.0f);
            return;
        case 4:
            func_001159f0(unused, resource, 0x32, alpha & 0xff,
                          baseX + 499.0f, baseY + 29.0f, 50.0f);
            return;
        case 5:
            func_001159f0(unused, resource, 0x33, alpha & 0xff,
                          baseX + 467.0f, baseY + 29.0f, 50.0f);
            return;
        case 6:
            func_001159f0(unused, resource, 0x34, alpha & 0xff,
                          baseX + 528.0f, baseY + 29.0f, 50.0f);
            return;
        case 8:
            func_001159f0(unused, resource, 0x37, alpha & 0xff,
                          baseX + 500.0f, baseY + 26.0f, 50.0f);
            return;
        default:
            return;
    }
}

/* W212: first divergence is the prologue (ours 0xa0-byte frame, retail 0x90);
 * this is an excess live-range/frame defect before the displaced draw tail, not
 * a tail defect.  func_00187ec0 does not share this draw/phase loop structure. */
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

    func_001159f0(NULL, resource, 0x3a, 0,
                  CLND_CALENDAR_X + 514.0f, 23.0f, 50.0f);
    if (time == 8)
    {
        func_00115bc0(NULL, resource, 0x39, 0,
                      0x7c, 0xff, 0x90,
                      CLND_CALENDAR_X + 390.0f, -8.0f, 50.0f);
        red = 0x7c;
        green = 0xff;
        blue = 0x90;
    }
    else
    {
        func_00115bc0(NULL, resource, 0x39, 0,
                      0x4c, 0x9a, 0xff,
                      CLND_CALENDAR_X + 390.0f, -8.0f, 50.0f);
        red = 0x4a;
        green = 0x9a;
        blue = 0xff;
    }

    func_00183840(resource, 0, month, day, CLND_CALENDAR_X, 0.0f);
    func_00183be0(resource, 0, month, day, CLND_CALENDAR_X, 0.0f);
    fade = ((60 - timer) * 0xff) / 60;
    func_00183f60(resource, fade, month, day, time, CLND_CALENDAR_X, 0.0f);

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
                      CLND_CALENDAR_X + 497.0f, 66.0f, 50.0f);
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
                      CLND_CALENDAR_X + 554.0f, 67.0f, 50.0f);
        func_00115cd0(NULL, resource, moonOffset % 10 + 0x23, 0,
                      red, green, blue,
                      CLND_CALENDAR_X + 571.0f, 67.0f, 50.0f);
    }
    else
    {
        func_001159f0(NULL, resource, 0x4c, 0,
                      CLND_CALENDAR_X + 514.0f, 66.0f, 50.0f);
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
        func_00115cd0(NULL, resource, moonOffset % 10 + 0x23, 0,
                      red, green, blue,
                      CLND_CALENDAR_X + 571.0f, 67.0f, 50.0f);
    }
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
    if (confirmed != 0)
    {
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
        (currentTime == 2 || currentTime == 3 ||
         currentTime == 4 || currentTime == 5) &&
        (work->time == 2 || work->time == 3 ||
         work->time == 4 || work->time == 5))
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
    else
    {
        work->transitionPending = 1;
        work->state = 2;
        datSetFlag(0x1410, false);
    }
}

// FUN_00184C80
void func_00184c80(KwlnTask* task, u32 confirmed)
{
    CalendarConfirmWork* work;
    s16 currentMonth;
    s16 currentDay;
    s16 currentTime;

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
#define func_00188640 func_00188640_game_support_proto
#include "Main/Game/game_support.h"
#undef func_00188640
#include "h_cdvd.h"
#include "libm.h"
#pragma alias func_00115ad0_gs func_00115ad0

/* Retail interfaces whose headers use a different (decompiler-friendly) ABI. */
extern void* func_0010c1a0(void* owner, const char* path, ...);
extern void* func_0010c3a0(void* stream, u32* finished, s32 byteCount);
extern KwlnTask* func_00111380(KwlnTask* parent, u32 priority, u64 dimensions, void* archive);
extern KwlnTask* func_00111150(KwlnTask* parent, u64 dimensions);
extern u32 func_001114b0(KwlnTask* task);
extern void func_00111500(KwlnTask* task);
extern void func_00111520(KwlnTask* task, s16 count);
extern u32 func_00111530(KwlnTask* task);
extern void func_001115b0(KwlnTask* task);
extern void func_001115e0(KwlnTask* task);
extern void func_001120c0(void);
extern void* func_00112420(void* source);
extern f32 func_001126b0(void* sprite);
extern f32 func_00112740(void* sprite);
extern void func_001127d0(void* sprite, u32 enabled);
extern void* func_001158b0(void* unused, void* atlas, s32 tile);
extern void func_00115980(void* sprite);
extern void func_001159f0(void* unused, void* atlas, s32 tile, u32 alpha,
                          f32 x, f32 y, f32 depth);
#pragma alias gsDrawSpritePositionFirst func_001159f0
extern void gsDrawSpritePositionFirst(f32 x, f32 y, void* unused,
                                      void* atlas, s32 tile, u32 alpha,
                                      f32 depth);
extern void func_00115ad0_gs(void* unused, void* atlas, s32 tile,
                          f32 x, f32 y, u32 alpha, u32 extraAlpha, f32 depth);
extern void func_00113a30(f32 depth, f32 x, f32 y, u32 color,
                          s32 width, s32 height);
extern void func_00113d80(f32 depth, f32 x, f32 y, u32 color,
                          s32 width, s32 height);
extern void func_00114af0(f32 depth, f32 x, f32 y, u32 color,
                          s32 width, s32 height, void* texture);
extern void func_003b2cb0(f32 depth, s32 x, s32 y, u32 color,
                          u32 font, u32 align, const void* text,
                          u32 width, u32 flags);
extern void func_004d0f00(void* resource);
extern u32 RpRandom(void);
#pragma alias DAT_007caf38_gs DAT_007caf38
extern f32 DAT_007caf38_gs;
extern u16 func_0016c670(s16 pcId);
extern s32 func_00530da0(f32 value);
extern s32 sprintf(char* buffer, const char* format, ...);
extern char* strcpy(char* destination, const char* source);
#pragma alias gsConfigureTransition func_0018bc10
extern void gsConfigureTransition(void* transition, s32 drawMode,
                                  s32 positionMode, s32 alphaMode,
                                  u64 start, u64 end, s32 param0, s32 tile,
                                  s32 startFrame, s32 endFrame, f32 depth);

/* Runtime allocator/free-function tables. */
extern u32 D_00960184[];
#pragma alias D_00960184_abs D_00960184
extern u8 D_00960184_abs[];
extern u32 jtbl_0096017C[];
#define GS_ALLOC(count, size, flags) \
    (*(void* (**)(u32, u32, u32))D_00960184_abs)((count), (size), (flags))
#define GS_FREE(ptr) (*(void (**)(void*))jtbl_0096017C)((ptr))

/* Render-state callback table and data resources. */
extern void (*D_00960090)(u32 state, u32 value);
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
extern void* D_00846730[0x12];
extern void* DAT_007ce008;

extern const char D_005E4320[];
extern const char D_005E4340[];
extern const char D_005E4360[];
extern const char D_005E4380[];
extern const char D_005E43A0[];
extern const char D_005E43C0[];
extern const char D_005E43E0[];
extern const char D_005E43F0[];
extern const char D_005E4418[];
extern const char D_005E4430[];
extern const char D_005E4450[];
extern const char D_005E4480[];
extern const char D_005E44B0[];
extern const char D_005E44D0[];
extern const char D_005E44E0[];
extern const char D_005E4500[];
extern const char D_005E4520[];
extern const char D_005E4540[];
extern const char D_005E4560[];
extern const char D_005E4580[];
extern const char D_005E45A0[];
extern const char D_005E45C0[];
extern const char D_005E45E0[];
extern const char D_005E4600[];
extern const char D_005E4620[];
extern const char D_005E4640[];
extern const char D_005E4660[];
extern const char D_005E4680[];
extern const char D_005E46A0[];



/* Target work blocks use the retail 32-bit offsets. */
#define GS_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define GS_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define GS_U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define GS_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define GS_U32(p, o) (*(u32*)((u8*)(p) + (o)))
#define GS_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define GS_F32(p, o) (*(f32*)((u8*)(p) + (o)))
#define GS_PTR(p, o) (*(void**)((u8*)(p) + (o)))
#define GS_TASK(p, o) (*(KwlnTask**)((u8*)(p) + (o)))

typedef struct GsCdvdWork
{
    u32 reserved00;
    HCdvd* cdvd;
} GsCdvdWork;
typedef struct GsLargeCdvdWork
{
    u8 reserved00[0x20];
    HCdvd* cdvd;
} GsLargeCdvdWork;
typedef struct GsResourceWork
{
    u8 reserved00[0x28];
    void* resources[0x12];
    void* allocation;
} GsResourceWork;
typedef struct GsAnimationWork
{
    u32 reserved00;
    HCdvd* cdvd;
    u8 reserved08[0x200];
    u32 transitionInitialized;
    u32 visible;
    void* transitions;
    void* atlas;
} GsAnimationWork;
typedef struct GsB270Entry
{
    u8 reserved00[0x154];
    void* cache;
    u8 reserved158[0x20c];
} GsB270Entry;

typedef struct GsB270Header
{
    u8 reserved00[0x30];
    void* resources[4];
    HCdvd* cdvd;
} GsB270Header;

typedef union GsB270Work
{
    GsB270Header header;
    GsB270Entry entries[3];
} GsB270Work;
typedef struct GsArchiveTaskWork
{
    u32 state;
    u32 reserved04;
    s32 argument;
    KwlnTask* tasks[4];
    void* resources[0x12];
} GsArchiveTaskWork;

typedef struct GsEb40WorkView
{
    u8 reserved00[0x60];
    s32 frame;
    u32 reserved64;
    u32 release;
} GsEb40WorkView;

typedef struct GsDb20WorkView
{
    u8 reserved00[0xc];
    s32 state;
    u8 reserved10[4];
    s16 pcId;
    u8 reserved16[0xe];
    s32 visible;
    u8 reserved28[4];
    void* sprite2c;
    u8 reserved30[4];
    void* sprite34;
    u8 reserved38[4];
    void* atlases[13];
    void* transition;
} GsDb20WorkView;






typedef union GsPackedPosition
{
    u64 value;
    f32 valueF[2];
} GsPackedPosition;

typedef struct GsPosition
{
    f32 valueF[2];
} GsPosition;

typedef struct GsTransition
{
    void* sprite;
    u32 enabled;
    s32 positionMode;
    s32 activePositionMode;
    s32 alphaMode;
    s32 tile;
    s32 elapsed;
    s32 start;
    s32 end;
    f32 depth;
    f32 startX;
    f32 startY;
    f32 endX;
    f32 endY;
    GsPosition position;
    u32 alpha;
} GsTransition;



typedef union GsPackedDimensions
{
    u64 value;
    s16 valueS[4];
} GsPackedDimensions;

typedef struct GsSprite
{
    u8 reserved00[0x10];
    f32 x;
    f32 y;
    u8 alpha;
    u8 reserved19[7];
    f32 angle;
    s16 centerX;
    s16 centerY;
    s16 scaleX;
    s16 scaleY;
    f32 depth;
} GsSprite;

static inline void gsDrawSprite(void* atlas, s32 tile, u32 alpha,
                                f32 x, f32 y, f32 depth)
{
    func_001159f0(NULL, atlas, tile, alpha, x, y, depth);
}

static inline void gsDrawSpriteAlt(void* atlas, s32 tile, u32 alpha,
                                   u32 extraAlpha, f32 x, f32 y, f32 depth)
{
    func_00115ad0_gs(NULL, atlas, tile, x, y, alpha, extraAlpha, depth);
}

static inline s16 gsMappedPcId(s16 pcId)
{
    if (datGetScenarioMode() != 0)
    {
        if (pcId == 1)
        {
            pcId = 11;
        }
        if (pcId == 9)
        {
            pcId = 12;
        }
        if (pcId == 3)
        {
            pcId = 11;
        }
    }
    return pcId;
}

static inline void* gsPcAtlas(void* object, s16 pcId)
{
    if (datGetScenarioMode() != 0)
    {
        if (pcId == 1)
        {
            pcId = 11;
        }
        if (pcId == 9)
        {
            pcId = 12;
        }
        if (pcId == 3)
        {
            pcId = 11;
        }
    }
    return GS_PTR(object, 0x3c + (pcId * 4));
}

static inline void gsDrawHeader(void* object, s32 tile0, s32 tile1, s32 tile2)
{
    void* atlas;
    void* transition;

    transition = GS_PTR(object, 0x70);
    atlas = gsPcAtlas(object, GS_S16(object, 0x14));
    gsDrawSprite(atlas, tile0, GS_U8(transition, 0x40),
                 GS_F32(transition, 0x38) + 20.0f,
                 GS_F32(transition, 0x3c) + 18.0f,
                 GS_F32(transition, 0x24));
    gsDrawSprite(atlas, tile1, GS_U8(transition, 0x40),
                 GS_F32(transition, 0x38) + 20.0f,
                 GS_F32(transition, 0x3c) + 18.0f,
                 GS_F32(transition, 0x24));
    gsDrawSprite(GS_PTR(object, 0x2c), tile2, GS_U8(transition, 0x40),
                 GS_F32(transition, 0x38) + 44.0f,
                 GS_F32(transition, 0x3c) + 39.0f,
                 GS_F32(transition, 0x24));
}

static inline void gsDrawStatusBars(void* object)
{
    s16 pcId;
    s32 value;
    s32 maxValue;
    s32 width;
    void* transition;

    transition = GS_PTR(object, 0x70);
    pcId = GS_S16(object, 0x14);

    value = datGetHp(pcId);
    maxValue = datGetMaxHp(pcId);
    width = ((value & 0xffff) << 5) / (maxValue & 0xffff);
    if (width != 0x20)
    {
        func_00113a30(GS_F32(transition, 0x24) - 1.0f,
                      GS_F32(transition, 0x38) + (f32)width + 50.0f,
                      GS_F32(transition, 0x3c) + 46.0f,
                      0xffffff00, 0x20 - width, 0x14);
    }
    gsDrawSprite(GS_PTR(object, 0x2c), 1, GS_U8(transition, 0x40),
                 GS_F32(transition, 0x38) + 50.0f,
                 GS_F32(transition, 0x3c) + 46.0f,
                 GS_F32(transition, 0x24));

    value = datGetSp(pcId);
    maxValue = func_0016c670(pcId);
    width = ((value & 0xffff) << 5) / (maxValue & 0xffff);
    if (width != 0x20)
    {
        func_00113a30(GS_F32(transition, 0x24) - 3.0f,
                      GS_F32(transition, 0x38) + (f32)width + 50.0f,
                      GS_F32(transition, 0x3c) + 51.0f,
                      0xffffff00, 0x20 - width, 0x14);
    }
    gsDrawSprite(GS_PTR(object, 0x2c), 2, GS_U8(transition, 0x40),
                 GS_F32(transition, 0x38) + 50.0f,
                 GS_F32(transition, 0x3c) + 51.0f,
                 GS_F32(transition, 0x24) - 2.0f);
}

static inline void gsDrawAnimatedSprite(void* object, s32 atlasOffset,
                                        s32 tile, s32 timer, s32 maxTimer,
                                        s32 xOffset, s32 yOffset,
                                        u32 alpha, s16 scale)
{
    void* transition;
    void* sprite;
    f32 width;
    f32 height;
    GsSprite* node;

    transition = GS_PTR(object, 0x70);
    sprite = func_001158b0(NULL, GS_PTR(object, atlasOffset), tile);
    node = (GsSprite*)sprite;
    node->depth = GS_F32(transition, 0x24) - 4.0f;
    node->scaleX = scale;
    node->scaleY = scale;
    width = func_001126b0(sprite);
    node->centerX = (s16)(s32)(width / 2.0f);
    height = func_00112740(sprite);
    node->centerY = (s16)(s32)(height / 2.0f);
    width = func_001126b0(sprite);
    node->x = GS_F32(transition, 0x38) + 6.0f + (f32)xOffset - width / 2.0f;
    height = func_00112740(sprite);
    node->y = GS_F32(transition, 0x3c) + 22.0f + (f32)yOffset - height / 2.0f;
    node->alpha = (u8)alpha;
    func_001127d0(sprite, 1);
    func_00115980(sprite);
    (void)timer;
    (void)maxTimer;
}


















/* Removing this loses FUN_0018bd90 (MATCH nd0 -> MISMATCH nd24) - measured W161. */































 

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
#pragma alias D_00960090_abs D_00960090
#pragma alias D_00960094_abs D_00960094
extern u8 D_00960090_abs[];
extern u8 D_00960094_abs[];
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
    KwlnTask* tasks[2];
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



static inline CalendarPackedPosition clndPackPosition(CalendarPackedPosition* position,
                                                            f32 x,
                                                            f32 y)
{
    position->x = x;
    position->y = y;
    return *position;
}

static inline f32 clndPackedX(u64 position)
{
    union
    {
        f32 value;
        u32 bits;
    } bits;

    bits.bits = (u32)position;
    return bits.value;
}

static inline f32 clndPackedY(u64 position)
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
    void* (**allocator)(u32, u32, u32);

    allocator = (void* (**)(u32, u32, u32))D_00960184;
    work = (*allocator)(1, 0x1a0, 0x40000);
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

    childWork = (*allocator)(1, 0x24, 0x40000);
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
            CLND_CALENDAR_X = 400.0f;
            *(f32*)(childWork + 0x10) = 400.0f;
            *(f32*)(childWork + 0x08) = 400.0f;
        }
    }

    return task;
}

// FUN_00184F00 NONMATCHING
void* func_00184f00(KwlnTask* task)
{
    CalendarDateTransitionWork* work;
    CalendarPackedPosition position;
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
            func_00186100(work->resource, clndPackPosition(&position, offset, 0.0f), 0);
            offset = ((f32)(30 - work->frame) * 80.0f) / 30.0f;
            func_00186140(work->resource, clndPackPosition(&position, offset, 0.0f), 0);
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
                          clndPackPosition(&position, offset, 0.0f),
                          alpha,
                          work->currentMonth);
            func_00185ae0(work->resource,
                          position,
                          alpha,
                          work->currentMonth);
            alpha = (u16)(((60 - frame) * 0xff) / 60);
            func_00185b40(work->resource,
                          clndPackPosition(&position, 0.0f, 0.0f),
                          alpha,
                          work->currentMonth,
                          work->currentDay);
            func_00186050(work->resource, position, alpha);
            func_00186100(work->resource, position, 0);
            func_00186140(work->resource, position, 0);
            if (frame == 60)
            {
                work->frame = 0;
                work->state = 5;
            }
            break;

        case 5:
            func_00185980(work->resource,
                          clndPackPosition(&position, 0.0f, 0.0f),
                          0,
                          work->currentMonth);
            frame = work->frame;
            if (frame < 10)
            {
                func_00185ae0(work->resource,
                              position,
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
                              clndPackPosition(&position, wave, 0.0f),
                              0,
                              work->currentMonth);
            }
            work->frame++;
            wave = sinf((DAT_007caf38 * (f32)((work->frame * 0x5a) / 0xf)) / 180.0f);
            func_00185b40(work->resource,
                          clndPackPosition(&position, -(wave * 87.0f), 0.0f),
                          0,
                          work->currentMonth,
                          work->currentDay);
            func_00186050(work->resource, clndPackPosition(&position, 0.0f, 0.0f), 0);
            func_00186100(work->resource, position, 0);
            func_00186140(work->resource, position, 0);
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
                          clndPackPosition(&position, 0.0f, 0.0f),
                          0,
                          work->targetMonth);
            func_00185ae0(work->resource,
                          position,
                          0,
                          work->targetMonth);
            func_00185b40(work->resource,
                          position,
                          0,
                          work->targetMonth,
                          work->targetDay);
            func_00186050(work->resource, position, 0);
            func_00186100(work->resource, position, 0);
            func_00186140(work->resource, position, 0);
            if (++work->frame == 20)
            {
                work->frame = 0;
                work->state = 8;
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
                          clndPackPosition(&position, 0.0f, 0.0f),
                          0,
                          work->targetMonth);
            func_00185ae0(work->resource,
                          position,
                          0,
                          work->targetMonth);
            func_00185b40(work->resource,
                          position,
                          0,
                          work->targetMonth,
                          work->targetDay);
            func_00186050(work->resource, position, 0);
            func_00186100(work->resource, position, 0);
            func_00186140(work->resource, position, 0);
            break;

        case 9:
            if (kwlnTaskGetState(work->eventTask) == KWLNTASK_STATE_DESTROY)
            {
                work->state = 7;
            }
            func_00185980(work->resource,
                          clndPackPosition(&position, 0.0f, 0.0f),
                          0,
                          work->targetMonth);
            func_00185ae0(work->resource,
                          position,
                          0,
                          work->targetMonth);
            func_00185b40(work->resource,
                          position,
                          0,
                          work->targetMonth,
                          work->targetDay);
            func_00186050(work->resource, position, 0);
            func_00186100(work->resource, position, 0);
            func_00186140(work->resource, position, 0);
            break;

        case 7:
            work->frame++;
            alpha = (u16)((work->frame * 0xff) / 15);
            func_00185980(work->resource,
                          clndPackPosition(&position, 0.0f, 0.0f),
                          alpha,
                          work->targetMonth);
            func_00185ae0(work->resource,
                          position,
                          alpha,
                          work->targetMonth);
            func_00185b40(work->resource,
                          position,
                          alpha,
                          work->targetMonth,
                          work->targetDay);
            func_00186050(work->resource, position, alpha);
            func_00186100(work->resource, position, alpha);
            func_00186140(work->resource, position, alpha);
            if (work->frame == 15)
            {
                return KWLNTASK_STOP;
            }
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

#pragma push
/* Removing this pragma worsens func_00185980 (fndiff nd3 -> nd75, object 352B -> 344B) - measured W305. */
#pragma opt_common_subs off
// FUN_00185980
void func_00185980(void* resource, CalendarPackedPosition position, u32 alpha, s16 month)
{
    void* unused;
    f32 y;
    f32 x;
    f32 xFirst;
    f32 yFirst;
    f32 x2;
    f32 ySecond;
    f32 yThird;
    s32 signedMonth;

    /* Removing this barrier restores a 7-word f20/f21 residual (fndiff nd7 -> nd0) - measured W314. */
    asm ("" : "+m"(position));
    y = position.y;
    /* Part of the measured barrier set: removing all seven worsens fndiff nd3 -> nd17 (W305). */
    asm ("" : "+m"(y));
    x = position.x;
    /* Part of the measured barrier set: removing all seven worsens fndiff nd3 -> nd17 (W305). */
    asm ("" : "+m"(x));
    xFirst = x + 289.0f;
    /* Part of the measured barrier set: removing all seven worsens fndiff nd3 -> nd17 (W305). */
    asm ("" : "+m"(xFirst));
    yFirst = y + 112.0f;
    /* Part of the measured barrier set: removing all seven worsens fndiff nd3 -> nd17 (W305). */
    asm ("" : "+m"(yFirst));
    if (month < 4)
    {
        func_001159f0(unused, resource, 0x50,
                      alpha & 0xff, xFirst, yFirst, 50.0f);
    }
    else
    {
        func_001159f0(unused, resource, 0x4f,
                      alpha & 0xff, xFirst, yFirst, 50.0f);
    }
    x2 = position.x + 251.0f;
    ySecond = y + 131.0f;
    /* Part of the measured barrier set: removing all seven worsens fndiff nd3 -> nd17 (W305). */
    asm ("" : "+m"(ySecond));
    signedMonth = month;
    func_001159f0(unused, resource, signedMonth - 1,
                  alpha & 0xff, x2, ySecond, 50.0f);
    yThird = y + 163.0f;
    /* Part of the measured barrier set: removing all seven worsens fndiff nd3 -> nd17 (W305). */
    asm ("" : "+m"(yThird));
    func_001159f0(unused, resource, signedMonth + 0xb,
                  alpha & 0xff, x2, yThird, 50.0f);
}
#pragma pop

// FUN_00185AE0
void func_00185ae0(void* resource, CalendarPackedPosition position, u32 alpha, s16 day)
{
    f32 x;
    f32 y;
    u32 cellAlpha;

    (void)day;
    x = position.x + 305.0f;
    /* Removing this barrier loses func_00185ae0 (MATCH nd0 -> MISMATCH nd35) - measured W164. */
    asm ("" : "+m"(x));
    y = position.y + 188.0f;
    /* Removing this barrier loses func_00185ae0 (MATCH nd0 -> MISMATCH nd20) - measured W164. */
    asm ("" : "+m"(y));
    cellAlpha = alpha & 0xff;
    func_001159f0(resource, resource, 0x4e, cellAlpha, x, y, 50.0f);
}

// FUN_00185B40 NONMATCHING
void func_00185b40(void* resource,
                   CalendarPackedPosition position,
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
    x = clndPackedX(*(u64*)&position) + 17.0f;
    y = clndPackedY(*(u64*)&position) + 213.0f;
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

#pragma push
/* Removing this worsens func_00186050 (nd29 -> nd37) - measured W161. */
#pragma opt_common_subs off
// FUN_00186050 NONMATCHING
void func_00186050(void* resource, CalendarPackedPosition position, u32 alpha)
{
    f32 y;
    f32 x;
    void* unused;

    y = position.y;
    func_001159f0(unused, resource, 0x2b, alpha & 0xff,
                  position.x, y, 48.0f);
    x = position.x + 449.0f;
    func_001159f0(unused, resource, 0x2c, alpha & 0xff,
                  x, y, 48.0f);
}
#pragma pop

// FUN_00186100
void func_00186100(void* resource, CalendarPackedPosition position, u32 alpha)
{
    f32 x;
    f32 y;
    u32 drawAlpha;

    y = position.y;
    /* Removing this barrier loses func_00186100 (MATCH nd0 -> MISMATCH nd24) - measured W164. */
    asm ("" : "+m"(y));
    x = position.x;
    drawAlpha = alpha & 0xff;
    func_001159f0(resource, resource, 0x29, drawAlpha,
                  x, y, 48.0f);
}

// FUN_00186140
void func_00186140(void* resource, CalendarPackedPosition position, u32 alpha)
{
    f32 x;
    f32 y;
    u32 drawAlpha;

    y = position.y + 404.0f;
    /* Removing this barrier loses func_00186140 (MATCH nd0 -> MISMATCH nd20) - measured W164. */
    asm ("" : "+m"(y));
    x = position.x;
    drawAlpha = alpha & 0xff;
    func_001159f0(resource, resource, 0x2a, drawAlpha,
                  x, y, 48.0f);
}
// FUN_00186190 NONMATCHING
void* func_00186190(KwlnTask* task)
{
    CalendarMoonWork* work;
    CalendarPackedPosition position;
    u32 archiveEntry;
    void* source;
    s32 alpha;
    s32 timer;
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
            func_00186a40(work->resource, clndPackPosition(&position, 0.0f, 0.0f),
                          alpha, (s16)work->selectedValue);
            func_00186bd0(work->resource, clndPackPosition(&position, 0.0f, 0.0f),
                          alpha, (s16)work->selectedValue);
            if (timer == 5)
            {
                work->timer = 0;
                work->state = 3;
            }
            break;

        case 3:
            timer = ++work->timer;
            func_00186a40(work->resource, clndPackPosition(&position, 0.0f, 0.0f),
                          0, (s16)work->selectedValue);
            func_00186bd0(work->resource, clndPackPosition(&position, 0.0f, 0.0f),
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
        {
            f32 _x;
            timer = ++work->timer;
            _x = sinf((DAT_007caf38 * (f32)((timer * 0x5a) / 10)) / 180.0f) * 300.0f;
            alpha = (timer * 0xff) / 10;
            func_00186a40(work->resource,
                          clndPackPosition(&position, _x, 0.0f),
                          alpha,
                          (s16)work->selectedValue);
            func_00186bd0(work->resource,
                          position,
                          alpha,
                          (s16)work->selectedValue);
            if (timer == 10)
            {
                work->selectedValue = work->targetValue;
                work->timer = 0;
                work->state = 5;
            }
            break;
        }

        case 5:
        {
            f32 _x;
            timer = ++work->timer;
            timer = 10 - timer;
            _x = sinf((DAT_007caf38 * (f32)((timer * 0x5a) / 10)) / 180.0f) * -300.0f;
            func_00186a40(work->resource,
                          clndPackPosition(&position, _x, 0.0f),
                          (timer * 0xff) / 10,
                          (s16)work->selectedValue);
            if (work->timer == 10)
            {
                work->timer = 0;
                work->state = 6;
            }
            break;
        }

        case 6:
            timer = ++work->timer;
            func_00186a40(work->resource, clndPackPosition(&position, 0.0f, 0.0f),
                          0, (s16)work->selectedValue);
            if (timer < 10)
            {
                alpha = 0xff - (timer * 0xff) / 10;
                func_00186bd0(work->resource,
                              clndPackPosition(&position, 0.0f, 0.0f),
                              alpha,
                              (s16)work->selectedValue);
            }
            else
            {
                func_00186bd0(work->resource,
                              clndPackPosition(&position, 0.0f, 0.0f),
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
        {
            f32 _x;
            f32 _y;
            timer = ++work->timer;
            _x = sinf((DAT_007caf38 * (f32)((timer * 0x5a) / 5)) / 180.0f) *
                 CLND_MOON_X_SCALE;
            _y = sinf((DAT_007caf38 * (f32)((timer * 0x5a) / 5)) / 180.0f) *
                 CLND_MOON_Y_SCALE;
            alpha = (timer * 0xff) / 5;
            func_00186a40(work->resource,
                          clndPackPosition(&position, _x, _y),
                          alpha,
                          (s16)work->selectedValue);
            func_00186bd0(work->resource,
                          position,
                          alpha,
                          (s16)work->selectedValue);
            if (timer == 5)
            {
                return KWLNTASK_STOP;
            }
            break;
        }

        case 8:
            timer = ++work->timer;
            alpha = (timer * 0xff) / 10;
            func_00186a40(work->resource, clndPackPosition(&position, 0.0f, 0.0f),
                          alpha, (s16)work->selectedValue);
            func_00186bd0(work->resource, clndPackPosition(&position, 0.0f, 0.0f),
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
            func_00186a40(work->resource, clndPackPosition(&position, 0.0f, 0.0f),
                          0, (s16)work->selectedValue);
            func_00186bd0(work->resource, clndPackPosition(&position, 0.0f, 0.0f),
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
void func_00186a40(void* resource, CalendarPackedPosition position, u32 alpha, s16 selection)
{
    void* unused;
    s32 tile;
    f32 x;
    f32 y;

    x = position.x + 207.0f;
    y = position.y + 183.0f;
    tile = 0;
    if (clndIsHolidayOrSunday_u32() == true &&
        (selection == 2 || selection == 3 || selection == 4 || selection == 5))
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
            case 8: break;
            default: break;
        }
    }
    func_001159f0(unused,
                  resource,
                  tile,
                  alpha & 0xff,
                  x,
                  y,
                  50.0f);
}

// FUN_00186BD0 NONMATCHING
void func_00186bd0(void* resource, CalendarPackedPosition position, u32 alpha, s16 selection)
{
    s32 tile;
    void* unused;

    if (alpha == 0xff)
    {
        return;
    }
    tile = 0;
    if (clndIsHolidayOrSunday_u32() == true &&
        (selection == 2 || selection == 3 || selection == 4 || selection == 5))
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
        case 8: break;
        default: break;
    }
    }
    func_001159f0(unused,
                  resource,
                  tile,
                  alpha & 0xff,
                  position.x + 207.0f,
                  position.y + 211.0f,
                  50.0f);
}

// FUN_00186D50
void* func_00186d50(KwlnTask* task)
{
    CalendarTransitionWork* work;
    s32 initialized;
    KwlnTask** entry;
    s32 i;

    work = (CalendarTransitionWork*)task->workData;
    switch (work->state)
    {
        case 0:
            work->tasks[0] = H_Maestro_CreateTask(NULL, 0x1cd2, D_005E4220);
            work->tasks[1] = H_Maestro_CreateTask(NULL, 0x1cd2, D_005E4240);
            work->state = 1;
            break;

        case 1:
            initialized = 1;
            for (i = 0; i < 2; i++)
            {
                entry = &work->tasks[i];
                if (!H_Maestro_FinishedInit(*entry))
                {
                    initialized = 0;
                }
            }
            if (initialized)
            {
                H_Maestro_00111f20(work->tasks[0], 1);
                H_Maestro_RequestDraw(work->tasks[0]);
                work->transitionTimer = 0;
                H_Maestro_SetAlphaMult(work->tasks[0], 0.0f);
                work->fadeTimer = 0;
                work->state = 2;
            }
            break;

        case 2:
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
            H_Maestro_SetAlphaMult(work->tasks[0],
                                   (f32)work->fadeTimer / 20.0f);
            if (H_Maestro_00111cb0(work->tasks[0]))
            {
                work->state = 3;
            }
            break;

        case 3:
            if (H_Maestro_FinishedInit(work->tasks[1]))
            {
                H_Fade_SetType(HFADE_DAY);
                H_Fade_SetDuration(0x28);
                if (work->tasks[0] != NULL)
                {
                    kwlnTaskDestroyWithHierarchy(work->tasks[0]);
                    work->tasks[0] = NULL;
                }
                H_Maestro_RequestDraw(work->tasks[1]);
                work->fadeTimer = 0;
                work->state = 4;
            }
            break;

        case 4:
            work->fadeTimer++;
            if (work->fadeTimer > 40 && work->fadeTimer < 140)
            {
                H_Maestro_SetAlphaMult(work->tasks[1],
                                       (100.0f - (f32)work->fadeTimer) / 100.0f);
            }
            if (kwlnTaskGetState(work->tasks[1]) == KWLNTASK_STATE_DESTROY)
            {
                work->tasks[1] = NULL;
                func_00109f60(3, 0);
                return KWLNTASK_STOP;
            }
            break;
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
        child = &work->tasks[0] + i;
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
    switch (work->state)
    {
    case 0:
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

        if (work->messageIndex == -1)
            return KWLNTASK_STOP;
        work->state = 1;
        break;
    case 1:
        goto draw;
    default:
        break;
    }
    return KWLNTASK_CONTINUE;

draw:
    if (work->timer < 10)
        color = (u32)((work->timer * 0xff) / 10);
    else if (work->timer >= 0x51)
        color = (u32)(((0x5a - work->timer) * 0xff) / 10);
    else
        color = 0xff;

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
    if (work->timer < 0x5a)
        return KWLNTASK_CONTINUE;
    return KWLNTASK_STOP;
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

    while (angle > 180)
    {
        angle -= 360;
    }
    while (angle < -180)
    {
        angle += 360;
    }
    angleRadians = DAT_007caf38 * (f32)angle / 180.0f;
    matrix = func_004c38c0();
    func_004c2fc0(1.0f - cosf(angleRadians),
                  sinf(angleRadians),
                  matrix,
                  &axis,
                  rwCOMBINEREPLACE);
    func_004c6c20(transformed, local, 4, matrix);
    func_004c3880(matrix);

    while (scaleAngle > 180)
    {
        scaleAngle -= 360;
    }
    while (scaleAngle < -180)
    {
        scaleAngle += 360;
    }
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
    if (scaleAngle > 180)
    {
        scaleAngle -= 360;
    }
    if (scaleAngle < -180)
    {
        scaleAngle += 360;
    }
    radians = DAT_007caf38 * (f32)scaleAngle / 180.0f;
    scale = 1.0f - radians * radians * 0.5f;
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

// FUN_00187BE0
void* func_00187be0(KwlnTask* task)
{
    CalendarSkipDrawWork* work;
    void (**setState)(u32 state, u32 value);
    u32 oldState;

    work = (CalendarSkipDrawWork*)task->workData;
    if (RwCameraBeginUpdate(kwlnGetMainCamera()) == NULL)
    {
        return KWLNTASK_CONTINUE;
    }
    (*(void (**)(u32, void*))D_00960094_abs)(0xe, &oldState);
    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(0xe, 0);

    switch (work->state)
    {
        case 0:
            work->alpha = 0;
            work->timer = 10;
            work->scaleAngle = 0x28;
            work->angle = 0;
            work->state = 1;
            break;

        case 1:
            work->timer--;
            if (work->timer < 0)
            {
                work->state = 2;
            }
            break;

        case 2:
            if (datGetFlag(0x1421) == 0)
            {
                func_001875f0(work->scaleAngle, work->angle, work->alpha);
                work->angle += 10;
                work->alpha += 20;
                if (work->alpha >= 0xff)
                {
                    work->alpha = 0xff;
                }
            }
            else
            {
                work->alpha = 0;
            }
            break;

        case 3:
            func_001875f0(work->scaleAngle, work->angle, work->alpha);
            (*setState)(0xe, oldState);
            RwCameraEndUpdate(kwlnGetMainCamera());
            work->angle += 10;
            work->alpha -= 20;
            if (work->alpha < 0)
            {
                return KWLNTASK_STOP;
            }
            return KWLNTASK_CONTINUE;
    }

    (*setState)(0xe, oldState);
    RwCameraEndUpdate(kwlnGetMainCamera());
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

// FUN_00187EC0
void func_00187ec0(KwlnTask* task, s32 month, s32 day, s32 time)
{
    CalendarTransitionMessageWork* work;
    void* parent;

    work = (CalendarTransitionMessageWork*)task->workData;
    if (datGetFlag(0x141d) != 0 || datGetFlag(0x1407) != 0)
    {
        return;
    }

    func_001159f0(parent,
                  work->resource,
                  0x3a,
                  0,
                  CLND_CALENDAR_X + 514.0f,
                  23.0f,
                  50.0f);
    if (time == 8)
    {
        func_00115bc0(parent,
                      work->resource,
                      0x39,
                      0,
                      0x7c,
                      0xff,
                      0x90,
                      CLND_CALENDAR_X + 390.0f,
                      -8.0f,
                      50.0f);
    }
    else
    {
        func_00115bc0(parent,
                      work->resource,
                      0x39,
                      0,
                      0x4c,
                      0x9a,
                      0xff,
                      CLND_CALENDAR_X + 390.0f,
                      -8.0f,
                      50.0f);
    }

    if (month == 3 && day == 0x1f && time == 4)
    {
        func_001159f0(parent,
                      work->resource,
                      0x50,
                      0,
                      CLND_CALENDAR_X + 416.0f,
                      14.0f,
                      50.0f);
    }
    else if (month == 3 && day == 0x1f && time == 6)
    {
        func_001159f0(parent,
                      work->resource,
                      0x51,
                      0,
                      CLND_CALENDAR_X + 416.0f,
                      14.0f,
                      50.0f);
    }
    else if (month == 3 && day == 0x1f && time == 7)
    {
        func_001159f0(parent,
                      work->resource,
                      0x52,
                      0,
                      CLND_CALENDAR_X + 416.0f,
                      14.0f,
                      50.0f);
    }
    else if (month == 4 && day == 2 && time == 7)
    {
        func_001159f0(parent,
                      work->resource,
                      0x53,
                      0,
                      CLND_CALENDAR_X + 416.0f,
                      14.0f,
                      50.0f);
    }
    else if (month == 4 && day == 1 && time == 2)
    {
        func_001159f0(parent,
                      work->resource,
                      0x54,
                      0,
                      CLND_CALENDAR_X + 416.0f,
                      14.0f,
                      50.0f);
    }
    else
    {
        func_001159f0(parent,
                      work->resource,
                      0x55,
                      0,
                      CLND_CALENDAR_X + 416.0f,
                      14.0f,
                      50.0f);
    }
}

// FUN_00188250
void* func_00188250(KwlnTask* task)
{
    CalendarTransitionMessageWork* work;
    void (**setState)(u32 state, u32 value);
    u32 oldState;

    work = (CalendarTransitionMessageWork*)task->workData;
    switch (work->state)
    {
        case 0:
            work->resource = func_00112370(D_005E4190);
            work->state = 1;
            break;

        case 1:
            if (H_Maestro_00111f30((s16*)work->resource) == true)
            {
                work->state = 2;
            }
            break;

        case 2:
            CLND_CALENDAR_X = 0.0f;
            work->month = clndGetCurrentMonth();
            work->day = clndGetCurrentDay();
            work->time = datGetTime() & 0xff;
            if (RwCameraBeginUpdate(kwlnGetMainCamera()) == NULL)
            {
                return KWLNTASK_CONTINUE;
            }
            (*(void (**)(u32, void*))D_00960094_abs)(0xe, &oldState);
            setState = (void (**)(u32, u32))D_00960090_abs;
            (*setState)(0xe, 0);
            func_00187ec0(task, work->month, work->day, work->time);
            (*setState)(0xe, oldState);
            RwCameraEndUpdate(kwlnGetMainCamera());
            break;
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
#define func_00115ad0 func_00115ad0_gs
#define DAT_007caf38 DAT_007caf38_gs

#include "Kosaka/Field/k_dungeon.h"

/*
 * These helpers are implemented by the game-support and memory-card modules.
 * Their retail symbols are kept here until those modules are decompiled.
 */
extern KwlnTask* func_00420340(KwlnTask* parentTask, u32 mode);
extern u32 func_004204f0(KwlnTask* task);
extern KwlnTask* func_004214e0(KwlnTask* parentTask, u32 mode);
extern void func_004215b0(KwlnTask* task, u32 state);
extern void func_00421650(KwlnTask* task);
extern u32 func_00421700(KwlnTask* task);
extern void func_00191240(void);
extern s32 func_00191260(void);
extern void func_001967d0(void);

/* Retail small-data globals used by the two game-support state machines. */
extern KwlnTask* DAT_007ce000;
extern u32 DAT_007ce00c;
extern u32 uGpffffb31c;
extern KwlnTask* uGpffffb314;

/* Runtime allocator/free-function tables. */
extern u32 D_00960184[];
extern u32 jtbl_0096017C[];

/* Task names live in the retail read-only data segment. */
extern const char D_005E42F0[];
extern const char D_005E4308[];

typedef struct GameSupportMemcardWork
{
    u32 state;
    s32 result;
    u32 timer;
    KwlnTask* task;
} GameSupportMemcardWork;

typedef struct GameSupportLoadWork
{
    u32 state;
    KwlnTask* task;
    KwlnTask* transitionTask;
} GameSupportLoadWork;

// FUN_001885A0
u32 func_001885a0(void)
{
    u32 floor;

    floor = K_FldDungeon_GetCurrentFloor();
    FUN_0016f3e0(0x35, floor);
    DAT_007ce00c = 0;
    DAT_007ce000 = func_00420340(NULL, 1);
    return 1;
}

// FUN_001885F0
u32 func_001885f0(void)
{
    u32 state;

    state = kwlnTaskGetState(DAT_007ce000);
    if (state == 3)
    {
        DAT_007ce000 = NULL;
        return 1;
    }

    return 0;
}

// FUN_00188640
u64 func_00188640(void)
{
    return 0;
}

// FUN_00188650
void func_00188650(void)
{
    return;
}

// FUN_00188660
u64 func_00188660(void)
{
    return 0;
}

// FUN_00188670
void func_00188670(void)
{
    return;
}

// FUN_00188680
void func_00188680(void)
{
    return;
}

// FUN_00188690
void* func_00188690(KwlnTask* task)
{
    GameSupportMemcardWork* work;
    u32 status;

    work = (GameSupportMemcardWork*)task->workData;

    switch (work->state)
    {
        case 0:
            work->task = func_004214e0(task, 1);
            work->state = 1;
            break;

        case 1:
            func_004215b0(work->task, 0xf);
            work->timer = 0x3c;
            work->state = 2;
            break;

        case 2:
            work->timer--;
            if (work->timer == 0)
            {
                func_00191240();
                work->state = 3;
            }
            break;

        case 3:
            status = (u32)func_00191260();
            work->result = (s32)status;
            if (status != 0)
            {
                if (status == 100)
                {
                    func_00421650(work->task);
                    return KWLNTASK_STOP;
                }
                work->state = 4;
            }
            break;

        case 4:
            if (work->result == -6)
            {
                func_004215b0(work->task, 0x15);
            }
            else
            {
                func_004215b0(work->task, 0x10);
            }
            work->state = 5;
            break;

        case 5:
            status = func_00421700(work->task);
            if (status == 1)
            {
                func_00421650(work->task);
                return KWLNTASK_STOP;
            }
            if (status == 2)
            {
                work->state = 1;
            }
            break;
    }

    return KWLNTASK_CONTINUE;
}

// FUN_00188830
void func_00188830(KwlnTask* task)
{
    (*(void (**)(void*))jtbl_0096017C)(task->workData);
}

// FUN_00188860
KwlnTask* func_00188860(KwlnTask* parentTask)
{
    void* work;
    KwlnTask* task;

    work = (*(void* (**)(u32, u32, u32))D_00960184)(1, 0x10, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parentTask,
                                          0x106f,
                                          D_005E42F0,
                                          func_00188690,
                                          func_00188830,
                                          work);
    if (task == NULL)
    {
        return NULL;
    }
    return task;
}

// FUN_00188900
void* func_00188900(KwlnTask* task)
{
    GameSupportLoadWork* work;
    u32 status;

    work = (GameSupportLoadWork*)task->workData;

    switch (work->state)
    {
        case 0:
            func_001967d0();
            work->task = func_004214e0(task, 1);
            work->state = 1;
            break;

        case 1:
            func_004215b0(work->task, 0x11);
            work->state = 2;
            break;

        case 2:
            status = func_00421700(work->task);
            if (status == 1)
            {
                func_004215b0(work->task, 0x12);
                work->state = 4;
            }
            else if (status == 2)
            {
                func_004215b0(work->task, 0x13);
                work->state = 3;
            }
            break;

        case 3:
            status = func_00421700(work->task);
            if (status == 1)
            {
                func_00421650(work->task);
                return KWLNTASK_STOP;
            }
            if (status == 2)
            {
                work->state = 1;
            }
            break;

        case 4:
            status = func_00421700(work->task);
            if (status == 1)
            {
                func_00421650(work->task);
                uGpffffb31c = 0;
                work->transitionTask = func_00420340(task, 1);
                work->state = 5;
            }
            break;

        case 5:
            status = kwlnTaskGetState(work->transitionTask);
            if (status == 3)
            {
                status = func_004204f0(work->transitionTask);
                if (status == 0)
                {
                    work->task = func_004214e0(task, 1);
                    func_004215b0(work->task, 0x13);
                    work->state = 3;
                }
                else
                {
                    func_00421650(work->task);
                    return KWLNTASK_STOP;
                }
            }
            break;
    }

    return KWLNTASK_CONTINUE;
}

// FUN_00188B20
void func_00188b20(KwlnTask* task)
{
    (*(void (**)(void*))jtbl_0096017C)(task->workData);
}

// FUN_00188B50
u32 func_00188b50(void)
{
    void* work;
    KwlnTask* created;

    work = (*(void* (**)(u32, u32, u32))D_00960184)(1, 0xc, 0x40000);
    if (work == NULL)
    {
        created = NULL;
    }
    else
    {
        created = kwlnTaskCreateWithAutoPriority(NULL,
                                                 0x106f,
                                                 D_005E4308,
                                                 func_00188900,
                                                 func_00188b20,
                                                 work);
        if (created == NULL)
        {
            created = NULL;
        }
    }
    uGpffffb314 = created;

    return 1;
}

// FUN_00188BE0
u32 func_00188be0(void)
{
    u32 state;

    state = kwlnTaskGetState(uGpffffb314);
    if (state == 3)
    {
        uGpffffb314 = NULL;
        return 1;
    }

    return 0;
}
















// FUN_0018A9F0 NONMATCHING
void* func_0018a9f0(KwlnTask* task)
{
    struct GsLateTimerWork
    {
        u8 pad[0xa70];
        s32 timer;
    };
    s32 i;
    u32 done;
    u32 allDone;
    struct
    {
        u32 pad[4];
        char text[256];
    } pathBuffer;
    GsPackedDimensions dimensions;
    void* resource;
    u32 alpha;
    u8* work = (u8*)task->workData;

    switch (GS_U32(work, 0))
    {
    case 0:
        switch (GS_U32(work, 4))
        {
        case 0x110:
            GS_U32(work, 8) = 0;
            break;
        case 0x111:
            GS_U32(work, 8) = 1;
            break;
        case 0x112:
            GS_U32(work, 8) = 2;
            break;
        case 0x113:
            GS_U32(work, 8) = 3;
            break;
        case 0x114:
            GS_U32(work, 8) = 4;
            break;
        case 0x115:
            GS_U32(work, 8) = 5;
            break;
        case 0x116:
            GS_U32(work, 8) = 6;
            break;
        case 0x117:
            GS_U32(work, 8) = 7;
            break;
        case 0x118:
            GS_U32(work, 8) = 8;
            break;
        case 0x119:
            GS_U32(work, 8) = 9;
            break;
        case 0x11a:
            GS_U32(work, 8) = 10;
            break;
        case 0x11b:
            GS_U32(work, 8) = 11;
            break;
        case 0x11c:
            GS_U32(work, 8) = 12;
            break;
        case 0x11d:
            GS_U32(work, 8) = 13;
            break;
        case 0x11e:
            GS_U32(work, 8) = 14;
            break;
        case 0x11f:
            GS_U32(work, 8) = 15;
            break;
        case 0x120:
            GS_U32(work, 8) = 16;
            break;
        case 0x121:
            GS_U32(work, 8) = 17;
            break;
        default:
            break;
        }
        sprintf(pathBuffer.text, D_005E43C0, GS_U32(work, 8));
        GS_PTR(work, 0x40) = H_Cdvd_Request(pathBuffer.text, HCDVD_FILEARCHIVE);
        GS_U32(work, 0) = 1;
        break;
    case 1:
        if (H_Cdvd_IsFileLoaded((HCdvd*)GS_PTR(work, 0x40)) != 0)
        {
            for (i = 0; i < 3; i++)
            {
                u8* entry = work + i * 0x364;
                resource = H_Cdvd_ArchiveGetFile((HCdvd*)GS_PTR(work, 0x40),
                                                  i + 4, (u32*)(entry + 0x15c));
                GS_PTR(entry, 0x154) = resource;
                func_00102720(D_005E43E0, resource);
            }
            dimensions.valueS[0] = 0x29;
            dimensions.valueS[1] = 1;
            if (GS_S32(work, 8) < 9)
            {
                dimensions.valueS[2] = 10;
                dimensions.valueS[3] = (s16)(GS_S32(work, 8) + 1);
            }
            else
            {
                dimensions.valueS[2] = 11;
                dimensions.valueS[3] = (s16)(GS_S32(work, 8) - 9);
            }
            GS_TASK(work, 0x14) = func_00111380(task, 0x18bf,
                                                dimensions.value,
                                                work + 0x3a8);
            dimensions.valueS[1] = 2;
            GS_TASK(work, 0x18) = func_00111380(task, 0x18bf,
                                                dimensions.value,
                                                work + 0x70c);
            dimensions.valueS[0] = 0x29;
            dimensions.valueS[1] = 1;
            dimensions.valueS[2] = 10;
            dimensions.valueS[3] = 0;
            GS_TASK(work, 0x1c) = func_00111380(task, 0x18bf,
                                                dimensions.value,
                                                work + 0x44);
            GS_U32(work, 0) = 2;
        }
        break;
    case 2:
        allDone = 1;
        for (i = 0; i < 3; i++)
        {
            if (func_001114b0(GS_TASK(work, 0x14 + i * 4)) == 0)
            {
                allDone = 0;
            }
        }
        if (allDone != 0)
        {
            GS_PTR(work, 0x20) = func_0010c1a0(NULL, D_005E43F0,
                                                NULL, NULL, NULL, NULL,
                                                NULL, NULL, D_005E4418, 0x426);
            GS_PTR(work, 0x24) = func_0010c1a0(NULL, D_005E4430,
                                                NULL, NULL, NULL, NULL,
                                                NULL, NULL, D_005E4418, 0x427);
            GS_PTR(work, 0x28) = func_0010c1a0(NULL, D_005E4450,
                                                NULL, NULL, NULL, NULL,
                                                NULL, NULL, D_005E4418, 0x428);
            GS_PTR(work, 0x2c) = func_0010c1a0(NULL, D_005E4480,
                                                NULL, NULL, NULL, NULL,
                                                NULL, NULL, D_005E4418, 0x429);
            GS_U32(work, 0) = 3;
        }
        break;
    case 3:
        allDone = 1;
        for (i = 0; i < 4; i++)
        {
            void* stream = GS_PTR(work, 0x20 + i * 4);
            if (stream != NULL)
            {
                done = 0;
                GS_PTR(work, 0x30 + i * 4) = func_0010c3a0(stream, &done, 0);
                if (done == 0)
                {
                    allDone = 0;
                }
                else
                {
                    GS_PTR(work, 0x20 + i * 4) = NULL;
                }
            }
        }
        if (allDone != 0)
        {
            GS_U32(work, 0) = 4;
        }
        break;
    case 4:
        break;
    case 5:
        ((struct GsLateTimerWork*)work)->timer++;
        if (((struct GsLateTimerWork*)work)->timer == 0x46)
        {
            for (i = 0; i < 3; i++)
            {
                KwlnTask** child = &GS_TASK(work, 0x14 + i * 4);
                if (*child != NULL && kwlnTaskGetState(*child) == 3)
                {
                    *child = NULL;
                }
                if (*child != NULL)
                {
                    kwlnTaskDestroyWithHierarchy(*child);
                }
                *child = NULL;
            }
        }
        if (((struct GsLateTimerWork*)work)->timer < 6 || ((struct GsLateTimerWork*)work)->timer > 8)
        {
            if (((struct GsLateTimerWork*)work)->timer > 8 && ((struct GsLateTimerWork*)work)->timer < 0x41)
            {
                func_00113a30(100.0f, 0.0f, 0.0f, 0x0f3956ff, 0x280, 0x1c0);
            }
        }
        else
        {
            func_00113a30(100.0f, 0.0f, 0.0f, 0x0f395603, 0x280, 0x1c0);
        }
        for (i = 0; i < 2; i++)
        {
            KwlnTask** child = &GS_TASK(work, 0x14 + i * 4);
            if (*child != NULL && kwlnTaskGetState(*child) == 3)
            {
                *child = NULL;
            }
            if (*child != NULL)
            {
                func_001115b0(*child);
                func_001115e0(*child);
            }
        }
        if (((struct GsLateTimerWork*)work)->timer > 5 && ((struct GsLateTimerWork*)work)->timer < 0x46)
        {
            func_00114af0(99.0f, 0.0f, 0.0f, 0xffffffff,
                          0x280, 0x1c0, GS_PTR(work, 0x34));
        }
        if (GS_TASK(work, 0x1c) != NULL && kwlnTaskGetState(GS_TASK(work, 0x1c)) == 3)
        {
            GS_TASK(work, 0x1c) = NULL;
        }
        if (GS_TASK(work, 0x1c) != NULL)
        {
            func_001115b0(GS_TASK(work, 0x1c));
            func_001115e0(GS_TASK(work, 0x1c));
        }
        if (((struct GsLateTimerWork*)work)->timer > 0x31 && ((struct GsLateTimerWork*)work)->timer < 0x46)
        {
            alpha = (u32)(((((struct GsLateTimerWork*)work)->timer - 0x32) * 0xff) / 0xf);
            func_00114af0(98.0f, 0.0f, 0.0f,
                          alpha | 0xffffff00, 0x280, 0x1c0,
                          GS_PTR(work, 0x30));
        }
        if (((struct GsLateTimerWork*)work)->timer > 0x36 && ((struct GsLateTimerWork*)work)->timer < 0x50)
        {
            if (((struct GsLateTimerWork*)work)->timer < 0x41)
            {
                alpha = (u32)(((((struct GsLateTimerWork*)work)->timer - 0x37) * 0xff) / 10);
            }
            else if (((struct GsLateTimerWork*)work)->timer < 0x46)
            {
                alpha = 0xff;
            }
            else
            {
                alpha = 0xff - (u32)(((((struct GsLateTimerWork*)work)->timer - 0x46) * 0xff) / 10);
            }
            func_00113d80(97.0f, 0.0f, 0.0f,
                          alpha | 0xffffff00, 0x280, 0x1c0);
        }
        if (((struct GsLateTimerWork*)work)->timer > 0x4f)
        {
            return KWLNTASK_STOP;
        }
        break;
    default:
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_0018B270
void func_0018b270(KwlnTask* task)
{
    s32 cacheIndex;
    s32 resourceIndex;
    GsB270Work* work = (GsB270Work*)task->workData;

    for (cacheIndex = 0; cacheIndex < 3; cacheIndex++)
    {
        if (GS_PTR((u8*)work + cacheIndex * sizeof(GsB270Entry), 0x154) != NULL)
        {
            H_Cdvd_CacheRemove(
                GS_PTR((u8*)work + cacheIndex * sizeof(GsB270Entry), 0x154));
        }
        GS_PTR((u8*)work + cacheIndex * sizeof(GsB270Entry), 0x154) = NULL;
    }
    for (resourceIndex = 0; resourceIndex < 4; resourceIndex++)
    {
        if (GS_PTR((u8*)work + resourceIndex * sizeof(void*), 0x30) != NULL)
        {
            func_004d0f00(
                GS_PTR((u8*)work + resourceIndex * sizeof(void*), 0x30));
            GS_PTR((u8*)work + resourceIndex * sizeof(void*), 0x30) = NULL;
        }
    }
    if (work->header.cdvd != NULL)
    {
        H_Cdvd_Destroy(work->header.cdvd);
        work->header.cdvd = NULL;
    }
    GS_FREE(work);
}

// FUN_0018B360
s32 func_0018b360(KwlnTask* task)
{
    return GS_S32(task->workData, 0) > 3;
}

// FUN_0018B380
void* func_0018b380(KwlnTask* task)
{
    struct GsB380Work
    {
        u32 state;
        u8 pad04[0x10];
        KwlnTask* tasks[3];
        u8 pad20[0x18];
        u32 payload38;
        u32 payload3c;
        u8 pad40[0xa30];
        s32 status;
    };
    struct GsB380Work* work = (struct GsB380Work*)task->workData;
    void* (**allocator)(u32, u32, u32);

    if (work->state == 4)
    {
        func_00111530(work->tasks[0]);
        func_00111530(work->tasks[1]);
        func_00111530(work->tasks[2]);
        work->status = -2;
        {
            u32 payload = work->payload38;
            void* allocation;
            allocator = (void* (**)(u32, u32, u32))D_00960184_abs;
            allocation = (*allocator)(1, 0x10, 0x40000);
            if (allocation != NULL)
            {
                if (kwlnTaskCreate(NULL, D_005E4320, 0x18c0,
                                   func_00188c30, func_0018a9c0, allocation) != NULL)
                {
                    GS_U32(allocation, 0xc) = payload;
                }
            }
        }
        {
            u32 payload = work->payload38;
            void* allocation;
            allocation = (*allocator)(1, 0x10, 0x40000);
            if (allocation != NULL)
            {
                if (kwlnTaskCreate(NULL, D_005E4340, 0x18c0,
                                   func_00189230, func_0018a9c0, allocation) != NULL)
                {
                    GS_U32(allocation, 0xc) = payload;
                }
            }
        }
        {
            u32 payload = work->payload38;
            void* allocation;
            allocation = (*allocator)(1, 0x10, 0x40000);
            if (allocation != NULL)
            {
                if (kwlnTaskCreate(NULL, D_005E4360, 0x18c0,
                                   func_00189810, func_0018a9c0, allocation) != NULL)
                {
                    GS_U32(allocation, 0xc) = payload;
                }
            }
        }
        {
            u32 payload = work->payload3c;
            void* allocation;
            allocation = (*allocator)(1, 0x10, 0x40000);
            if (allocation != NULL)
            {
                if (kwlnTaskCreate(NULL, D_005E4380, 0x18c0,
                                   func_00189df0, func_0018a9c0, allocation) != NULL)
                {
                    GS_U32(allocation, 0xc) = payload;
                }
            }
        }
        {
            u32 payload = work->payload3c;
            void* allocation;
            allocation = (*allocator)(1, 0x10, 0x40000);
            if (allocation != NULL)
            {
                if (kwlnTaskCreate(NULL, D_005E43A0, 0x18c0,
                                   func_0018a3f0, func_0018a9c0, allocation) != NULL)
                {
                    GS_U32(allocation, 0xc) = payload;
                }
            }
        }
        work->state = 5;
    }
}

// FUN_0018B5F0
s32 func_0018b5f0(KwlnTask* task)
{
    u8* work = (u8*)task->workData;
    if (GS_U32(work, 0) == 5)
    {
        return GS_S32(work, 0xa70);
    }
    return 0;
}

// FUN_0018B620
KwlnTask* func_0018b620(KwlnTask* parent, s32 mode)
{
    void* work;
    KwlnTask* task;

    work = GS_ALLOC(1, 0xa74, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_005E44B0, 0x18bf,
                          func_0018a9f0, func_0018b270, work);
    if (task == NULL)
    {
        return NULL;
    }
    GS_S32(work, 4) = mode;
    return task;
}

// FUN_0018B6D0
void* func_0018b6d0(s32 count)
{
    return GS_ALLOC((u32)count, 0x44, 0x40000);
}

// FUN_0018B700
u32 func_0018b700(void* transition)
{
    GsTransition* work = (GsTransition*)transition;

    if (work->enabled == 0)
    {
        return 0;
    }
    if (work->elapsed < work->end)
    {
        work->elapsed = work->elapsed + 1;
    }
    if (work->start > work->elapsed)
    {
        return 0;
    }

    switch (work->positionMode)
    {
    case 0:
        return func_0018bb20(transition);
    case 1:
        return func_0018bb80(transition);
    }
    return 0;
}

// FUN_0018B7B0
void func_0018b7b0(void* transition, f32* position)
{
    s32 total;
    s32 elapsed;
    s32 mode;
    f32 phase;

    total = GS_S32(transition, 0x20) - GS_S32(transition, 0x1c);
    elapsed = GS_S32(transition, 0x18) - GS_S32(transition, 0x1c);
    mode = GS_S32(transition, 0xc);
    switch (mode)
    {
    case 0:
        position[0] = GS_F32(transition, 0x30);
        position[1] = GS_F32(transition, 0x34);
        break;
    case 1:
        if (elapsed == total)
        {
            position[0] = GS_F32(transition, 0x30);
            position[1] = GS_F32(transition, 0x34);
        }
        else
        {
            phase = GS_F32(transition, 0x30) - GS_F32(transition, 0x28);
            position[0] = GS_F32(transition, 0x28) +
                          (phase * (f32)elapsed) / (f32)total;
            phase = GS_F32(transition, 0x34) - GS_F32(transition, 0x2c);
            position[1] = GS_F32(transition, 0x2c) +
                          (phase * (f32)elapsed) / (f32)total;
        }
        break;
    case 2:
        if (total != 0)
        {
            phase = (f32)((elapsed * 0x5a) / total);
        }
        else
        {
            phase = 90.0f;
        }
        phase = cosf((DAT_007caf38 * phase) / 180.0f);
        if (elapsed == total)
        {
            position[0] = GS_F32(transition, 0x30);
            position[1] = GS_F32(transition, 0x34);
        }
        else
        {
            position[0] = (GS_F32(transition, 0x30) - GS_F32(transition, 0x28)) * phase +
                          GS_F32(transition, 0x28);
            position[1] = (GS_F32(transition, 0x34) - GS_F32(transition, 0x2c)) * phase +
                          GS_F32(transition, 0x2c);
        }
        break;
    case 3:
        if (total != 0)
        {
            phase = (f32)((elapsed * 0x5a) / total);
        }
        else
        {
            phase = 90.0f;
        }
        phase = sinf((DAT_007caf38 * phase) / 180.0f);
        if (elapsed == total)
        {
            position[0] = GS_F32(transition, 0x28);
            position[1] = GS_F32(transition, 0x2c);
        }
        else
        {
            position[0] = GS_F32(transition, 0x30) -
                          (GS_F32(transition, 0x28) - GS_F32(transition, 0x30)) * phase;
            position[1] = GS_F32(transition, 0x34) -
                          (GS_F32(transition, 0x2c) - GS_F32(transition, 0x34)) * phase;
        }
        break;
    }
}

// FUN_0018BA60
void func_0018ba60(void* transition, u8* alpha)
{
    s32 total = GS_S32(transition, 0x20) - GS_S32(transition, 0x1c);
    s32 elapsed = GS_S32(transition, 0x18) - GS_S32(transition, 0x1c);
    s32 mode = GS_S32(transition, 0x10);
    s32 value;

    switch (mode)
    {
    case 0:
        *alpha = 0;
        break;
    case 1:
        value = total == 0 ? 0xff : (elapsed * 0xff) / total;
        *alpha = (u8)(0xff - value);
        break;
    case 2:
        value = total == 0 ? 0xff : (elapsed * 0xff) / total;
        *alpha = (u8)value;
        break;
    }
}

// FUN_0018BB20
u32 func_0018bb20(void* transition)
{
    GsPosition position;
    u8 alpha;

    func_0018b7b0(transition, position.valueF);
    func_0018ba60(transition, &alpha);
    *(GsPosition*)((u8*)transition + 0x38) = position;
    GS_U32(transition, 0x40) = alpha;
    return alpha != 0xff;
}

// FUN_0018BB80
u32 func_0018bb80(void* transition)
{
    GsPosition position;
    u8 alpha;

    func_0018b7b0(transition, position.valueF);
    func_0018ba60(transition, &alpha);
    *(GsPosition*)((u8*)transition + 0x38) = position;
    GS_U32(transition, 0x40) = alpha;
    {
        void* unused;
        func_00115ad0(unused, GS_PTR(transition, 0), GS_S32(transition, 0x14),
                      position.valueF[0], position.valueF[1], 0xff, alpha,
                      GS_F32(transition, 0x24));
    }
    return *(u32*)((u32)transition + 0x40) != 0xff;
}

// FUN_0018BC10
void func_0018bc10(f32 depth, void* transition, s32 drawMode,
                          s32 positionMode, s32 alphaMode,
                          u64 start, u64 end, s32 param0, s32 tile,
                          s32 startFrame, s32 endFrame)
{
    GsPackedPosition endPos;
    GsPackedPosition startPos;

    startPos.value = start;
    endPos.value = end;
    GS_U32(transition, 4) = 1;
    GS_S32(transition, 8) = drawMode;
    GS_S32(transition, 0xc) = positionMode;
    GS_S32(transition, 0x10) = alphaMode;
    *(GsPosition*)((u8*)transition + 0x28) = *(GsPosition*)&startPos;
    *(GsPosition*)((u8*)transition + 0x30) = *(GsPosition*)&endPos;
    GS_S32(transition, 0) = param0;
    GS_S32(transition, 0x14) = tile;
    GS_F32(transition, 0x24) = depth;
    GS_S32(transition, 0x1c) = startFrame;
    GS_S32(transition, 0x20) = endFrame;
    GS_S32(transition, 0x18) = 0;
}

// FUN_0018BC80
void func_0018bc80(void)
{
    HCdvd* cdvd;
    void* archiveEntry;
    u32 size;
    u32 ready;
    u32 allReady;
    s32 i;

    cdvd = H_Cdvd_Request(D_005E44D0, HCDVD_FILEARCHIVE);
    H_Cdvd_ReadSync(cdvd);
    for (i = 0; i < 0x12; i++)
    {
        archiveEntry = H_Cdvd_ArchiveGetFile(cdvd, i, &size);
        D_00846730[i] = func_00112420(archiveEntry);
    }
    do
    {
        func_001120c0();
        allReady = 1;
        for (i = 0; i < 0x12; i++)
        {
            ready = H_Maestro_00111f30((s16*)D_00846730[i]);
            if (ready == 0)
            {
                allReady = 0;
            }
        }
        ready = !(allReady != 0);
    } while (ready != 0);
    H_Cdvd_Destroy(cdvd);
}

/* Removing this loses FUN_0018bd90 (MATCH nd0 -> MISMATCH nd24) - measured W161. */

// FUN_0018BD90
#pragma opt_loop_invariants on
void* func_0018bd90(KwlnTask* task)
{
    GsArchiveTaskWork* work = (GsArchiveTaskWork*)task->workData;
    s32 copyIndex;
    s32 taskIndex;

    switch (work->state)
    {
    case 0:
        work->state = 1;
        break;
    case 1:
        for (copyIndex = 0; copyIndex < 0x12; copyIndex++)
        {
            work->resources[copyIndex] = D_00846730[copyIndex];
        }
        work->tasks[0] = func_0018e390(task, 0, work->resources);
        work->tasks[1] = func_0018e390(task, 1, work->resources);
        work->tasks[2] = func_0018e390(task, 2, work->resources);
        work->tasks[3] = func_0018e390(task, 3, work->resources);
        work->state = 2;
        break;
    case 2:
        break;
    }

    for (taskIndex = 0; taskIndex < 4; taskIndex++)
    {
        if (work->tasks[taskIndex] != NULL)
        {
            func_0018e490(work->tasks[taskIndex], work->argument);
        }
    }
    return KWLNTASK_CONTINUE;
}

#pragma opt_loop_invariants off
// FUN_0018BEE0
void func_0018bee0(KwlnTask* task, s32 pcId, s32 mode)
{
    GsArchiveTaskWork* work = (GsArchiveTaskWork*)task->workData;
    s16 partyId;
    s32 i;

    if (pcId == 1)
    {
        func_0018dde0(work->tasks[0], mode);
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            partyId = datGetPartyId(i);
            if (pcId == partyId)
            {
                func_0018dde0(work->tasks[i + 1], mode);
                return;
            }
        }
    }
}

// FUN_0018BFA0
void func_0018bfa0(KwlnTask* task)
{
    GsCdvdWork* work = (GsCdvdWork*)task->workData;

    if (work->cdvd != NULL)
    {
        H_Cdvd_Destroy(work->cdvd);
        work->cdvd = NULL;
    }
    GS_FREE(work);
}

// FUN_0018BFF0
KwlnTask* func_0018bff0(KwlnTask* parent)
{
    void* work;
    KwlnTask* task;

    work = GS_ALLOC(1, 0x64, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_005E44E0, 0x18b3,
                          func_0018bd90, func_0018bfa0, work);
    if (task == NULL)
    {
        return NULL;
    }
    GS_U32(work, 8) = 1;
    return task;
}

// FUN_0018C0A0
u32 func_0018c0a0(KwlnTask* task)
{
    return GS_U32(task->workData, 0) == 2;
}

// FUN_0018C0C0
void func_0018c0c0(KwlnTask* task, s32 visible)
{
    u8* work = (u8*)task->workData;
    GS_S32(work, 8) = visible;
    if (GS_U32(task->workData, 0) == 2)
    {
        func_0018e490(GS_TASK(work, 0xc), visible);
        func_0018e490(GS_TASK(work, 0x10), visible);
        func_0018e490(GS_TASK(work, 0x14), visible);
        func_0018e490(GS_TASK(work, 0x18), visible);
    }
}

// FUN_0018C150 NONMATCHING
void func_0018c150(KwlnTask* task)
{
    void* object;
    GsTransition* transition;
    void* atlas;
    s16 pcId;
    s32 i;
    s32 phase;
    s32 radius;
    s32 alpha;
    f32 angle;
    f32 sine;
    f32 cosine;
    void* sprite;
    GsSprite* node;
    u32 hp;
    u32 maxHp;
    u32 sp;
    u32 maxSp;
    s32 width;

    object = (void*)task;
    transition = (GsTransition*)GS_PTR(object, 0x70);
    pcId = GS_S16(object, 0x14);
    atlas = gsPcAtlas(object, pcId);
    gsDrawSprite(atlas, 1, GS_U8(transition, 0x40), transition->position.valueF[0] + 20.0f, transition->position.valueF[1] + 18.0f, transition->depth);
    if ((datGetBadStatusNoDown(pcId) & 0x80) == 0)
    {
        gsDrawSprite(atlas, 0, GS_U8(transition, 0x40), transition->position.valueF[0] + 20.0f, transition->position.valueF[1] + 18.0f, transition->depth);
    }
    else
    {
        gsDrawSprite(atlas, 2, GS_U8(transition, 0x40), transition->position.valueF[0] + 20.0f, transition->position.valueF[1] + 18.0f, transition->depth);
    }
    gsDrawSprite(GS_PTR(object, 0x2c), 0, GS_U8(transition, 0x40), transition->position.valueF[0] + 44.0f, transition->position.valueF[1] + 39.0f, transition->depth);

    if ((datGetBadStatusNoDown(pcId) & 0x80) != 0)
    {
        GS_U32(object, 0x20)++;
        if (GS_U32(object, 0x20) >= 100)
        {
            GS_U32(object, 0x20) = 0;
        }
        for (i = 0; i < 12; i++)
        {
            phase = (GS_S32(object, 0x20) + i * 15) % 100;
            if (phase <= 50)
            {
                continue;
            }
            angle = DAT_007caf38 * ((f32)((i / 3) * 0x28 >> 2) + 40.0f) / 180.0f;
            sine = sinf(angle);
            cosine = cosf(angle);
            radius = ((phase - 50) * 50) / 50;
            if (phase - 50 < 10)
            {
                alpha = 0xff - (((phase - 50) * 0xff) / 10);
            }
            else if (phase - 50 < 0x28)
            {
                alpha = 0;
            }
            else
            {
                alpha = (((phase - 0x5a) * 0xff) / 10);
            }
            sprite = func_001158b0(NULL, GS_PTR(object, 0x30), (i % 3) + 1);
            node = (GsSprite*)sprite;
            node->depth = transition->depth;
            node->x = transition->position.valueF[0] + 44.0f +
                      (f32)(s32)((f32)radius * cosine);
            node->y = transition->position.valueF[1] + 34.0f -
                      (f32)(s32)((f32)radius * sine);
            node->alpha = (u8)alpha;
            func_001127d0(sprite, 1);
            func_00115980(sprite);
        }
    }

    hp = datGetHp(pcId);
    maxHp = datGetMaxHp(pcId);
    width = ((hp & 0xffff) << 5) / (maxHp & 0xffff);
    if (width != 0x20)
    {
        func_00113a30(transition->depth - 1.0f,
                      transition->position.valueF[0] + (f32)width + 50.0f,
                      transition->position.valueF[1] + 46.0f,
                      0xffffff00, 0x20 - width, 0x14);
    }
    gsDrawSprite(GS_PTR(object, 0x2c), 1, GS_U8(transition, 0x40), transition->position.valueF[0] + 50.0f, transition->position.valueF[1] + 46.0f, transition->depth);
    sp = datGetSp(pcId);
    maxSp = func_0016c670(pcId);
    width = ((sp & 0xffff) << 5) / (maxSp & 0xffff);
    if (width != 0x20)
    {
        func_00113a30(transition->depth - 3.0f,
                      transition->position.valueF[0] + (f32)width + 50.0f,
                      transition->position.valueF[1] + 51.0f,
                      0xffffff00, 0x20 - width, 0x14);
    }
    gsDrawSprite(GS_PTR(object, 0x2c), 2, GS_U8(transition, 0x40), transition->position.valueF[0] + 50.0f, transition->position.valueF[1] + 51.0f, transition->depth - 2.0f);
}

// FUN_0018C780 NONMATCHING
void func_0018c780(KwlnTask* task)
{
    void* object = (void*)task;
    void* transition = GS_PTR(object, 0x70);
    u32 alpha = GS_U8(transition, 0x40);
    s32 frame = GS_S32(object, 0x18);
    s32 fadeFrame;
    s16 scale;
    u8 fadeAlpha;
    void* sprite;
    f32 width;
    f32 height;

    gsDrawHeader(object, 8, 7, 6);
    gsDrawStatusBars(object);
    if (frame > 5)
    {
        frame = 5;
    }
    sprite = func_001158b0(NULL, GS_PTR(object, 0x3c), 1);
    ((GsSprite*)sprite)->depth = GS_F32(transition, 0x24) - 4.0f;
    scale = (s16)(((frame << 0xc) / 5) + 1);
    ((GsSprite*)sprite)->scaleX = scale;
    ((GsSprite*)sprite)->scaleY = scale;
    width = func_001126b0(sprite);
    ((GsSprite*)sprite)->centerX = (s16)(s32)(width / 2.0f);
    height = func_00112740(sprite);
    ((GsSprite*)sprite)->centerY = (s16)(s32)(height / 2.0f);
    ((GsSprite*)sprite)->angle = 90.0f;
    width = func_001126b0(sprite);
    ((GsSprite*)sprite)->x = GS_F32(transition, 0x38) + 48.0f - width / 2.0f;
    height = func_00112740(sprite);
    ((GsSprite*)sprite)->y = GS_F32(transition, 0x3c) + 43.0f - height / 2.0f;
    ((GsSprite*)sprite)->alpha = (u8)(0xff - (frame * 0xff) / 5);
    func_001127d0(sprite, 1);
    func_00115980(sprite);

    fadeFrame = GS_S32(object, 0x18) - 5;
    if (fadeFrame >= 0 && fadeFrame < 8)
    {
        scale = (s16)((fadeFrame * 0x1000) >> 3);
        fadeAlpha = (u8)(0xff - ((fadeFrame * 0xff) >> 3));
        sprite = func_001158b0(NULL, GS_PTR(object, 0x3c), 0);
        ((GsSprite*)sprite)->depth = GS_F32(transition, 0x24) - 4.0f;
        ((GsSprite*)sprite)->scaleX = (s16)(scale + 1);
        ((GsSprite*)sprite)->scaleY = (s16)(scale + 1);
        width = func_001126b0(sprite);
        ((GsSprite*)sprite)->centerX = (s16)(s32)(width / 2.0f);
        height = func_00112740(sprite);
        ((GsSprite*)sprite)->centerY = (s16)(s32)(height / 2.0f);
        width = func_001126b0(sprite);
        ((GsSprite*)sprite)->x = GS_F32(transition, 0x38) + 49.0f - width / 2.0f;
        height = func_00112740(sprite);
        ((GsSprite*)sprite)->y = GS_F32(transition, 0x3c) + 43.0f - height / 2.0f;
        ((GsSprite*)sprite)->alpha = fadeAlpha;
        func_001127d0(sprite, 1);
        func_00115980(sprite);
    }
    (void)alpha;
    GS_S32(object, 0x18)++;
    if (GS_S32(object, 0x18) > 0x11)
    {
        GS_S32(object, 0x18) = 0;
        GS_S32(object, 0xc) = 4;
    }
}

#pragma opt_strength_reduction off
// FUN_0018CE50 NONMATCHING
void func_0018ce50(KwlnTask* task)
{
    void* object = (void*)task;
    void* transition = GS_PTR(object, 0x70);
    void* sprite;
    GsSprite* node;
    f32 width;
    f32 height;

    gsDrawHeader(object, 8, 7, 6);
    gsDrawStatusBars(object);
    sprite = func_001158b0(NULL, GS_PTR(object, 0x3c), 1);
    node = (GsSprite*)sprite;
    node->depth = GS_F32(transition, 0x24) - 4.0f;
    node->scaleX = 0x1000;
    node->scaleY = 0x1000;
    width = func_001126b0(sprite);
    node->centerX = (s16)(s32)(width / 2.0f);
    height = func_00112740(sprite);
    node->centerY = (s16)(s32)(height / 2.0f);
    node->angle = 90.0f;
    width = func_001126b0(sprite);
    node->x = GS_F32(transition, 0x38) + 48.0f - width / 2.0f;
    height = func_00112740(sprite);
    node->y = GS_F32(transition, 0x3c) + 43.0f - height / 2.0f;
    node->alpha = 0x28;
    func_001127d0(sprite, 1);
    func_00115980(sprite);
}

#pragma opt_strength_reduction reset
// FUN_0018D320 NONMATCHING
void func_0018d320(KwlnTask* task)
{
    void* object = (void*)task;
    void* transition = GS_PTR(object, 0x70);
    void* sprite;
    GsSprite* node;
    f32 width;
    f32 height;
    s32 frame;
    s32 burstFrame;
    s32 i;
    u32 alpha;
    u32 burstAlpha;
    u32 randomFrame;
    gsDrawHeader(object, 6, 4, 5);
    gsDrawStatusBars(object);
    frame = GS_S32(object, 0x18);
    if (frame > 5)
    {
        frame = 5;
    }
    alpha = 0xff - (u32)((frame * 0xff) / 5);
    sprite = func_001158b0(NULL, GS_PTR(object, 0x38), 0);
    node = (GsSprite*)sprite;
    node->depth = GS_F32(transition, 0x24) - 4.0f;
    node->scaleX = (s16)((frame << 0xc) / 5);
    node->scaleY = (s16)((frame << 0xc) / 5);
    width = func_001126b0(sprite);
    node->centerX = (s16)(s32)(width / 2.0f);
    height = func_00112740(sprite);
    node->centerY = (s16)(s32)(height / 2.0f);
    width = func_001126b0(sprite);
    node->x = GS_F32(transition, 0x38) + 64.0f - width / 2.0f;
    height = func_00112740(sprite);
    node->y = GS_F32(transition, 0x3c) + 60.0f - height / 2.0f;
    node->alpha = (u8)alpha;
    func_001127d0(sprite, 1);
    func_00115980(sprite);

    burstFrame = GS_S32(object, 0x18) - 5;
    if (burstFrame >= 0)
    {
        if (burstFrame < 5)
        {
            randomFrame = (u32)(burstFrame / 5);
        }
        else
        {
            randomFrame = RpRandom() % 0x99;
        }
        gsDrawSprite(GS_PTR(object, 0x38), 1, randomFrame & 0xff, GS_F32(transition, 0x38) + 28.0f, GS_F32(transition, 0x3c) + 22.0f, GS_F32(transition, 0x24) - 4.0f);
    }
    burstFrame = GS_S32(object, 0x18) - 5;
    if (burstFrame >= 0)
    {
        if (burstFrame < 5)
        {
            randomFrame = (u32)(burstFrame / 5);
        }
        else
        {
            randomFrame = RpRandom() % 0x99;
        }
        gsDrawSprite(GS_PTR(object, 0x38), 2, randomFrame & 0xff, GS_F32(transition, 0x38) + 59.0f, GS_F32(transition, 0x3c) + 23.0f, GS_F32(transition, 0x24) - 4.0f);
    }
    burstFrame = GS_S32(object, 0x18) - 5;
    if (burstFrame >= 0)
    {
        if (burstFrame < 5)
        {
            randomFrame = (u32)(burstFrame / 5);
        }
        else
        {
            randomFrame = RpRandom() % 0x99;
        }
        gsDrawSprite(GS_PTR(object, 0x38), 3, randomFrame & 0xff, GS_F32(transition, 0x38) + 21.0f, GS_F32(transition, 0x3c) + 47.0f, GS_F32(transition, 0x24) - 4.0f);
    }
    burstFrame = GS_S32(object, 0x18) - 5;
    if (burstFrame >= 0)
    {
        if (burstFrame < 5)
        {
            randomFrame = (u32)(burstFrame / 5);
        }
        else
        {
            randomFrame = RpRandom() % 0x99;
        }
        gsDrawSprite(GS_PTR(object, 0x38), 4, randomFrame & 0xff, GS_F32(transition, 0x38) + 49.0f, GS_F32(transition, 0x3c) + 43.0f, GS_F32(transition, 0x24) - 4.0f);
    }
    burstFrame = GS_S32(object, 0x18) - 5;
    if (burstFrame >= 0)
    {
        if (burstFrame < 5)
        {
            randomFrame = (u32)(burstFrame / 5);
        }
        else
        {
            randomFrame = RpRandom() % 0x99;
        }
        gsDrawSprite(GS_PTR(object, 0x38), 5, randomFrame & 0xff, GS_F32(transition, 0x38) + 67.0f, GS_F32(transition, 0x3c) + 62.0f, GS_F32(transition, 0x24) - 4.0f);
    }
    GS_S32(object, 0x18)++;
    if (GS_S32(object, 0x18) > 0x1e)
    {
        GS_S32(object, 0xc) = GS_S32(object, 0x10);
        GS_S32(object, 0x18) = 0;
    }
}

// FUN_0018DB20 NONMATCHING
void* func_0018db20(KwlnTask* task)
{
    GsDb20WorkView* object = (GsDb20WorkView*)task;
    if (func_0018b700(object->transition) == 0)
    {
        goto done;
    }
    if (object->visible == 0)
    {
        goto done;
    }
    switch (object->state)
    {
        case 0:
            func_0018c150(task);
            break;
        case 1:
        {
            void* unused;
            void** atlas;
            GsTransition* transition;
            s16 pcId;

            transition = (GsTransition*)object->transition;
            pcId = object->pcId;

            if (datGetScenarioMode() != 0)
            {
                if (pcId == 1)
                {
                    pcId = 11;
                }
                if (pcId == 9)
                {
                    pcId = 12;
                }
                if (pcId == 3)
                {
                    pcId = 11;
                }
            }
            atlas = &object->atlases[pcId];
            {
                f32 x;
                f32 y;
                u32 alpha;

                x = *(volatile f32*)&transition->position.valueF[0] + 20.0f;
                y = *(volatile f32*)&transition->position.valueF[1] + 18.0f;
                alpha = *(volatile u8*)&transition->alpha;
                func_001159f0(unused, *atlas, 3, alpha, x, y,
                              transition->depth);
            }
            {
                f32 x;
                f32 y;
                u32 alpha;

                x = *(volatile f32*)&transition->position.valueF[0] + 20.0f;
                y = *(volatile f32*)&transition->position.valueF[1] + 18.0f;
                alpha = *(volatile u8*)&transition->alpha;
                func_001159f0(unused, *atlas, 1, alpha, x, y,
                              transition->depth);
            }
            {
                f32 x;
                f32 y;
                u32 alpha;

                x = *(volatile f32*)&transition->position.valueF[0] + 44.0f;
                y = *(volatile f32*)&transition->position.valueF[1] + 39.0f;
                alpha = *(volatile u8*)&transition->alpha;
                func_001159f0(unused, object->sprite2c, 0, alpha, x, y,
                              transition->depth);
            }
            {
                f32 x;
                f32 y;
                u32 alpha;

                x = *(volatile f32*)&transition->position.valueF[0] + 50.0f;
                y = *(volatile f32*)&transition->position.valueF[1] + 51.0f;
                alpha = *(volatile u8*)&transition->alpha;
                func_001159f0(unused, object->sprite2c, 3, alpha, x, y,
                              transition->depth);
            }
            {
                f32 x;
                f32 y;
                u32 alpha;

                x = *(volatile f32*)&transition->position.valueF[0] + 27.0f;
                y = *(volatile f32*)&transition->position.valueF[1] + 22.0f;
                alpha = *(volatile u8*)&transition->alpha;
                func_001159f0(unused, object->sprite34, 0, alpha, x, y,
                              transition->depth);
            }
            break;
        }
        case 2:
            func_0018d320(task);
            break;
        case 3:
            func_0018c780(task);
            break;
        case 4:
            func_0018ce50(task);
            break;
        default:
            break;
        }
done:
    ;
}

// FUN_0018DDE0
void func_0018dde0(KwlnTask* transitionTask, s32 mode)
{
    void* transition = transitionTask->workData;

    switch (mode)
    {
    case 0:
        GS_S32(transition, 0xc) = 0;
        break;
    case 1:
        GS_S32(transition, 0xc) = 3;
        break;
    case 2:
        GS_S32(transition, 0xc) = 1;
        break;
    case 3:
        GS_S32(transition, 0x10) = GS_S32(transition, 0xc);
        GS_S32(transition, 0xc) = 2;
        break;
    }
    GS_S32(transition, 0x18) = 0;
}

// FUN_0018DE60 NONMATCHING
void* func_0018de60(KwlnTask* task)
{
    u8* work = (u8*)task->workData;
    s32 count = 1;
    s16 partyId;
    s32 i;
    f32 y;
    GsPackedPosition start;
    GsPackedPosition end;
    void* transition;

    if (GS_U32(work, 0) == 1)
    {
        for (i = 0; i < 3; i++)
        {
            partyId = datGetPartyId(i);
            if (partyId != 0)
            {
                count++;
            }
        }
        if (GS_S32(work, 8) != 0 && datGetPartyId(GS_S32(work, 8) - 1) == 0)
        {
            GS_S32(work, 4) = 0;
            transition = GS_TASK(work, 0x70)->workData;
            GS_S32(transition, 4) = 0;
        }
        if (GS_S32(work, 8) == 0)
        {
            GS_S32(work, 0x14) = 1;
        }
        else
        {
            if (GS_S32(work, 0x14) != datGetPartyId(GS_S32(work, 8) - 1))
            {
                GS_S32(work, 4) = 0;
                GS_S32(work, 0x14) = datGetPartyId(GS_S32(work, 8) - 1);
            }
        }
        if (GS_S32(work, 4) == 3)
        {
            if (count != GS_S32(work, 0x1c))
            {
                GS_S32(work, 0x1c) = count;
                if (count == 4)
                {
                    y = (f32)(GS_S32(work, 8) * 0x35) + 195.0f;
                }
                else if (count == 3)
                {
                    y = (f32)(GS_S32(work, 8) * 0x3c) + 234.0f;
                }
                else if (count == 2)
                {
                    y = (f32)(GS_S32(work, 8) * 0x3c) + 294.0f;
                }
                else
                {
                    y = 324.0f;
                }
                end.valueF[0] = 534.0f;
                end.valueF[1] = y;
                printf(D_005E4500, GS_S32(work, 8), func_00530da0(end.valueF[1]));
                transition = GS_TASK(work, 0x70)->workData;
                start.valueF[0] = GS_F32(transition, 0x38);
                start.valueF[1] = GS_F32(transition, 0x3c);
                func_0018bc10(110.0f, transition, 0, 2, 0,
                              start.value, end.value, 0, 0, 0, 0);
            }
        }
        else if (GS_S32(work, 4) == 2)
        {
            GS_S32(work, 4) = 0;
        }
        else if (GS_S32(work, 4) == 1)
        {
            transition = GS_TASK(work, 0x70)->workData;
            if (GS_S32(transition, 0x18) == GS_S32(transition, 0x20))
            {
                GS_S32(work, 4) = 3;
            }
        }
        else if (GS_S32(work, 4) == 0)
        {
            GS_S32(work, 0x1c) = count;
            if (GS_S32(work, 0x14) != 0)
            {
                if (count == 4)
                {
                    y = (f32)(GS_S32(work, 8) * 0x35) + 195.0f;
                }
                else if (count == 3)
                {
                    y = (f32)(GS_S32(work, 8) * 0x3c) + 234.0f;
                }
                else if (count == 2)
                {
                    y = (f32)(GS_S32(work, 8) * 0x3c) + 294.0f;
                }
                else
                {
                    y = 324.0f;
                }
                end.valueF[0] = 534.0f;
                end.valueF[1] = y;
                printf(D_005E4500, GS_S32(work, 8), func_00530da0(end.valueF[1]));
                GS_S32(work, 4) = 1;
                transition = GS_TASK(work, 0x70)->workData;
                start = end;
                start.valueF[0] += 300.0f;
                func_0018bc10(110.0f, transition, 0, 2, 1,
                              start.value, end.value, 0, 0, 0, 0);
            }
        }
        if (GS_S32(work, 4) == 1 || GS_S32(work, 4) == 3)
        {
            func_0018db20(GS_TASK(work, 0x70));
        }
    }
    else if (GS_U32(work, 0) == 0)
    {
        GS_TASK(work, 0x70) = (KwlnTask*)func_0018b6d0(1);
        GS_S32(work, 4) = 0;
        GS_TASK(work, 0xc) = NULL;
        GS_U32(work, 0) = 1;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_0018E330
void func_0018e330(KwlnTask* task)
{
    GsResourceWork* work = (GsResourceWork*)task->workData;

    if (work->allocation != NULL)
    {
        GS_FREE(work->allocation);
    }
    work->allocation = NULL;
    GS_FREE(work);
}

// FUN_0018E390
KwlnTask* func_0018e390(KwlnTask* parent, s32 index, void* resources)
{
    GsResourceWork* work;
    KwlnTask* task;
    s32 i;

    work = GS_ALLOC(1, 0x74, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_005E4520, 0x18b4,
                          func_0018de60, func_0018e330, work);
    if (task == NULL)
    {
        return NULL;
    }
    for (i = 0; i < 0x12; i++)
    {
        GS_PTR((u8*)work + i * 4, 0x28) = ((void**)resources)[i];
    }
    GS_U32(work, 0x24) = 1;
    GS_S32(work, 8) = index;
    return task;
}

// FUN_0018E490
void func_0018e490(KwlnTask* task, s32 visible)
{
    GS_S32((u8*)task->workData, 0x24) = visible;
}

// FUN_0018E4A0
void func_0018e4a0(void)
{
    HCdvd* cdvd;
    void* entry;
    u32 size;

    cdvd = H_Cdvd_Request(D_005E4540, HCDVD_FILEARCHIVE);
    H_Cdvd_ReadSync(cdvd);
    entry = H_Cdvd_ArchiveGetFile(cdvd, 0, &size);
    DAT_007ce008 = func_00112420(entry);
    do
    {
        func_001120c0();
    } while (H_Maestro_00111f30((s16*)DAT_007ce008) ? 0 : 1);
    H_Cdvd_Destroy(cdvd);
}

// FUN_0018E540
void* func_0018e540(KwlnTask* task)
{
    u8* work = (u8*)task->workData;

    switch (GS_U32(work, 0))
    {
    case 0:
        GS_U32(work, 0) = 1;
        break;
    case 1:
        GS_PTR(work, 0x214) = DAT_007ce008;
        GS_U32(work, 0) = 2;
        break;
    case 2:
        func_0018e8e0(work);
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_0018E5C0
void func_0018e5c0(KwlnTask* task, void* record)
{
    GsAnimationWork* work = (GsAnimationWork*)task->workData;
    GsPackedPosition firstStart;
    GsPackedPosition end;
    GsPackedPosition commonStart;
    GsPackedPosition alternateStart;

    if (work->transitionInitialized != 0)
    {
        func_00524270((u8*)work + 0x108, (u8*)work + 8);
        end.valueF[0] = 40.0f;
        end.valueF[1] = 407.0f;
        firstStart = end;
        end.valueF[0] = end.valueF[0] + 200.0f;
        gsConfigureTransition((u8*)work->transitions + 0x88, 0, 2, 2,
                              firstStart.value, end.value, 0, 0, 0, 10,
                              100.0f);
    }
    else
    {
        end.valueF[0] = 194.0f;
        end.valueF[1] = 399.0f;
        alternateStart = end;
        alternateStart.valueF[0] = alternateStart.valueF[0] - 200.0f;
        gsConfigureTransition(work->transitions, 0, 2, 1,
                              alternateStart.value, end.value, 0, 0, 0, 10,
                              100.0f);
        work->transitionInitialized = 1;
    }
    func_00524270((u8*)work + 8, record);
    end.valueF[0] = 40.0f;
    end.valueF[1] = 407.0f;
    commonStart = end;
    commonStart.valueF[0] = commonStart.valueF[0] - 200.0f;
    gsConfigureTransition((u8*)work->transitions + 0x44, 0, 2, 1,
                          commonStart.value, end.value, 0, 0, 0, 10,
                          100.0f);
}

// FUN_0018E7A0
void func_0018e7a0(KwlnTask* task)
{
    GsAnimationWork* work = (GsAnimationWork*)task->workData;

    if (work->cdvd != NULL)
    {
        work->cdvd = NULL;
        H_Cdvd_Destroy(NULL);
    }
    if (work->transitions != NULL)
    {
        GS_FREE(work->transitions);
    }
    work->transitions = NULL;
    GS_FREE(work);
}

// FUN_0018E820
KwlnTask* func_0018e820(KwlnTask* parent)
{
    KwlnTask* task;
    void* work;

    work = GS_ALLOC(1, 0x218, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_005E4560, 0x18b4,
                          func_0018e540, func_0018e7a0, work);
    if (task == NULL)
    {
        return NULL;
    }
    GS_PTR(work, 0x210) = func_0018b6d0(10);
    GS_U32(work, 0x20c) = 1;
    return task;
}

// FUN_0018E8E0
void func_0018e8e0(void* workData)
{
    GsAnimationWork* work = (GsAnimationWork*)workData;
    s32 i;
    void* unused;
    s32 transitionOffset;
    GsTransition* transition;

    for (i = 0; i < 3; i++)
    {
        transitionOffset = i * sizeof(GsTransition);
        if (func_0018b700((u8*)work->transitions + transitionOffset) != 0)
        {
            transition = (GsTransition*)((u8*)work->transitions + transitionOffset);
            if (work->visible != 0)
            {
                switch (i)
                {
                case 0:
                {
                    f32 x;
                    f32 y;

                    func_001159f0(unused, work->atlas, 0,
                                  *(u8*)&transition->alpha,
                                  transition->position.valueF[0],
                                  transition->position.valueF[1],
                                  transition->depth);
                    x = 21.0f + transition->position.valueF[0] - 174.0f - 27.0f;
                    y = 3.0f + (412.0f + transition->position.valueF[1] - 399.0f);
                    gsDrawSpritePositionFirst(x, y, unused, work->atlas, 2,
                                              *(u8*)&transition->alpha,
                                              transition->depth);
                    break;
                }
                case 1:
                {
                    u32 alpha;

                    alpha = transition->alpha;
                    alpha = 0xff - alpha;
                    func_003b2cb0(
                        transition->depth,
                        (s32)((f32)(s32)transition->position.valueF[0] - 10.0f),
                        (s32)transition->position.valueF[1] + 5,
                        alpha | 0xffffff00, 5, 1, (u8*)work + 8, 0x10, 0);
                    break;
                }
                case 2:
                {
                    u32 alpha;

                    alpha = transition->alpha;
                    alpha = 0xff - alpha;
                    func_003b2cb0(
                        transition->depth,
                        (s32)((f32)(s32)transition->position.valueF[0] - 10.0f),
                        (s32)transition->position.valueF[1] + 5,
                        alpha | 0xffffff00, 5, 1, (u8*)work + 0x108, 0x10, 0);
                    break;
                }
                }
            }
        }
    }
}

// FUN_0018EB30
void func_0018eb30(KwlnTask* task, u32 visible)
{
    GS_U32((u8*)task->workData, 0x20c) = visible;
}

// FUN_0018EB40
void* func_0018eb40(KwlnTask* task)
{
    u8* work = (u8*)task->workData;
    char path[264];
    GsPackedDimensions dimensions;
    void (**renderState)(u32, u32);
    u32 mode;

    kwlnGetMainCamera();
    renderState = (void (**)(u32, u32))D_00960090_abs;
    (*renderState)(6, 1);
    (*renderState)(7, 2);
    (*renderState)(8, 1);
    (*renderState)(9, 1);
    (*renderState)(0xc, 1);
    (*renderState)(0xb, 6);
    (*renderState)(10, 5);
    mode = GS_U32(work, 0);
    switch (mode)
    {
    case 0:
        switch (GS_U32(work, 4))
        {
        case 2:
            sprintf(path, (const char*)D_005E4580);
            break;
        case 3:
            sprintf(path, (const char*)D_005E45A0);
            break;
        case 4:
            sprintf(path, (const char*)D_005E45C0);
            break;
        case 5:
            sprintf(path, (const char*)D_005E45E0);
            break;
        case 7:
            sprintf(path, (const char*)D_005E4600);
            break;
        case 8:
            sprintf(path, (const char*)D_005E4620);
            break;
        case 9:
            if (datGetScenarioMode() != 0)
            {
                sprintf(path, (const char*)D_005E4660);
            }
            else
            {
                sprintf(path, (const char*)D_005E4640);
            }
            break;
        case 10:
            sprintf(path, (const char*)D_005E4680);
            break;
        case 0:
        case 1:
        case 6:
        default:
            sprintf(path, (const char*)D_005E4580);
            break;
        }
        GS_U32(work, 0) = 1;
        break;
    case 1:
        dimensions.valueS[0] = 0x29;
        dimensions.valueS[1] = 4;
        dimensions.valueS[2] = 0xb;
        switch (GS_U32(work, 4))
        {
        case 2:
            dimensions.valueS[3] = 0;
            break;
        case 3:
            dimensions.valueS[3] = 1;
            break;
        case 4:
            dimensions.valueS[3] = 2;
            break;
        case 5:
            dimensions.valueS[3] = 3;
            break;
        case 7:
            dimensions.valueS[3] = 4;
            break;
        case 8:
            dimensions.valueS[3] = 5;
            break;
        case 9:
            if (datGetScenarioMode() != 0)
            {
                dimensions.valueS[3] = 8;
            }
            else
            {
                dimensions.valueS[3] = 6;
            }
            break;
        case 10:
            dimensions.valueS[3] = 7;
            break;
        case 0:
        case 1:
        case 6:
        default:
            dimensions.valueS[3] = 0;
            break;
        }
        GS_TASK(work, 8) = func_00111150(task, dimensions.value);
        GS_U32(work, 0) = 2;
        break;
    case 2:
        if (func_001114b0(*(KwlnTask* volatile*)(work + 8)) != 0)
        {
            func_00111520(*(KwlnTask* volatile*)(work + 8), 0x32);
            GS_U32(work, 0) = 3;
        }
        break;
    case 3:
        break;
    case 4:
        func_00111530(*(KwlnTask* volatile*)(work + 8));
        GS_U32(work, 0) = 5;
        break;
    case 5:
        if (((GsEb40WorkView*)work)->frame >= 0x32)
        {
            if (((GsEb40WorkView*)work)->release != 0)
            {
                GS_U32(work, 0x60) = GS_U32(work, 0x60) + 1;
                func_00111500(*(KwlnTask* volatile*)(work + 8));
            }
        }
        else
        {
            GS_U32(work, 0x60) = GS_U32(work, 0x60) + 1;
        }
        if (kwlnTaskGetState(*(KwlnTask* volatile*)(work + 8)) == 3)
        {
            return KWLNTASK_STOP;
        }
        break;
    default:
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_0018EF60
void func_0018ef60(KwlnTask* task)
{
    GsLargeCdvdWork* work = (GsLargeCdvdWork*)task->workData;

    if (work->cdvd != NULL)
    {
        H_Cdvd_Destroy(work->cdvd);
        work->cdvd = NULL;
    }
    GS_FREE(work);
}

// FUN_0018EFB0
KwlnTask* func_0018efb0(KwlnTask* parent, s32 mode)
{
    void* work;
    KwlnTask* task;

    work = GS_ALLOC(1, 0x3d0, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent, 0x106f, D_005E46A0,
                                          func_0018eb40,
                                          func_0018ef60, work);
    if (task == NULL)
    {
        return NULL;
    }
    GS_S32(work, 4) = mode;
    return task;
}

// FUN_0018F060
u32 func_0018f060(KwlnTask* task)
{
    return GS_U32(task->workData, 0) == 3;
}

// FUN_0018F080
void func_0018f080(KwlnTask* task)
{
    GS_U32(task->workData, 0) = 4;
}

// FUN_0018F0A0
u32 func_0018f0a0(void)
{
    return 0x3f;
}

// FUN_0018F0B0
u32 func_0018f0b0(KwlnTask* task)
{
    return GS_U32(task->workData, 0x60);
}

// FUN_0018F0C0
u32 func_0018f0c0(KwlnTask* task)
{
    return GS_S32(task->workData, 0x60) > 0x31;
}

// FUN_0018F0E0
void func_0018f0e0(KwlnTask* task)
{
    GS_U32(task->workData, 0x68) = 1;
}
#undef func_00115ad0
#undef DAT_007caf38
