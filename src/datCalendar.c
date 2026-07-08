#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rwcore.h"
#include "Script/scrTraceCode.h"
#include "Event/Comu/comuFunction.h"
#include "Main/admini.h"
#include "Main/g_data.h"
#include "h_cursor.h"
#include "h_dbprt.h"
#include "h_pad.h"
#include "h_sfdply.h"
#include "temporary.h"

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

// 005e38d0. Moon phases for every day (april 5th 2009 to march 31st 2010)
static const u8 daysMoonPhases[] =
{
    // Cycle 1: april 5th 2009 to april 25th 2009
    MOON_PHASE_WAXING_GIBBOUS_4, MOON_PHASE_WAXING_GIBBOUS_5, MOON_PHASE_WAXING_GIBBOUS_6,
    MOON_PHASE_WAXING_GIBBOUS_7, MOON_PHASE_FULL_MOON, MOON_PHASE_WANING_GIBBOUS_1,
    MOON_PHASE_WANING_GIBBOUS_1, MOON_PHASE_WANING_GIBBOUS_2, MOON_PHASE_WANING_GIBBOUS_3,
    MOON_PHASE_WANING_GIBBOUS_4, MOON_PHASE_WANING_GIBBOUS_5, MOON_PHASE_WANING_GIBBOUS_6,
    MOON_PHASE_WANING_GIBBOUS_7, MOON_PHASE_LAST_QUARTER, MOON_PHASE_WANING_CRESCENT_1, 
    MOON_PHASE_WANING_CRESCENT_2, MOON_PHASE_WANING_CRESCENT_3, MOON_PHASE_WANING_CRESCENT_4, 
    MOON_PHASE_WANING_CRESCENT_5, MOON_PHASE_WANING_CRESCENT_6, MOON_PHASE_NEW_MOON,
    
    // Cycle 2: april 26th 2009 to may 24th 2009
    MOON_PHASE_WAXING_CRESCENT_1, MOON_PHASE_WAXING_CRESCENT_2, MOON_PHASE_WAXING_CRESCENT_3,
    MOON_PHASE_WAXING_CRESCENT_4, MOON_PHASE_WAXING_CRESCENT_5, MOON_PHASE_WAXING_CRESCENT_6,
    MOON_PHASE_FIRST_QUARTER, MOON_PHASE_WAXING_GIBBOUS_1, MOON_PHASE_WAXING_GIBBOUS_2, 
    MOON_PHASE_WAXING_GIBBOUS_3, MOON_PHASE_WAXING_GIBBOUS_4, MOON_PHASE_WAXING_GIBBOUS_5,
    MOON_PHASE_WAXING_GIBBOUS_6, MOON_PHASE_FULL_MOON, MOON_PHASE_WANING_GIBBOUS_1,
    MOON_PHASE_WANING_GIBBOUS_2, MOON_PHASE_WANING_GIBBOUS_3, MOON_PHASE_WANING_GIBBOUS_4,
    MOON_PHASE_WANING_GIBBOUS_5, MOON_PHASE_WANING_GIBBOUS_6, MOON_PHASE_WANING_GIBBOUS_7,
    MOON_PHASE_LAST_QUARTER, MOON_PHASE_WANING_CRESCENT_1, MOON_PHASE_WANING_CRESCENT_2,
    MOON_PHASE_WANING_CRESCENT_3, MOON_PHASE_WANING_CRESCENT_4, MOON_PHASE_WANING_CRESCENT_5,
    MOON_PHASE_WANING_CRESCENT_6, MOON_PHASE_NEW_MOON,

    // Cycle 3: may 25th 2009 to june 23rd 2009
    MOON_PHASE_WAXING_CRESCENT_1, MOON_PHASE_WAXING_CRESCENT_2, MOON_PHASE_WAXING_CRESCENT_3,
    MOON_PHASE_WAXING_CRESCENT_4, MOON_PHASE_WAXING_CRESCENT_5, MOON_PHASE_WAXING_CRESCENT_6,
    MOON_PHASE_FIRST_QUARTER, MOON_PHASE_WAXING_GIBBOUS_1, MOON_PHASE_WAXING_GIBBOUS_2,
    MOON_PHASE_WAXING_GIBBOUS_3, MOON_PHASE_WAXING_GIBBOUS_4, MOON_PHASE_WAXING_GIBBOUS_5,
    MOON_PHASE_WAXING_GIBBOUS_6, MOON_PHASE_WAXING_GIBBOUS_7, MOON_PHASE_FULL_MOON,
    MOON_PHASE_WANING_GIBBOUS_1, MOON_PHASE_WANING_GIBBOUS_2, MOON_PHASE_WANING_GIBBOUS_3,
    MOON_PHASE_WANING_GIBBOUS_4, MOON_PHASE_WANING_GIBBOUS_5, MOON_PHASE_WANING_GIBBOUS_6,
    MOON_PHASE_WANING_GIBBOUS_7, MOON_PHASE_LAST_QUARTER, MOON_PHASE_WANING_CRESCENT_1,
    MOON_PHASE_WANING_CRESCENT_2, MOON_PHASE_WANING_CRESCENT_3, MOON_PHASE_WANING_CRESCENT_4,
    MOON_PHASE_WANING_CRESCENT_5, MOON_PHASE_WANING_CRESCENT_6, MOON_PHASE_NEW_MOON

    // TODO: Other cycles
};

static KwlnTask* sClndTask; // 007cdfec. Task name = "CalenderDraw"

s32 clndFindAndExecSiteibiEvents();

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

// FUN_0017d8b0 NONMATCHING
s32 clndGetDaysSinceStartFromDate(s32 month, s32 day)
{
    s32 dayAccumulator = 0;
    s32 m = CALENDAR_MONTH_APRIL;

    while (true)
    {
        if (month == CALENDAR_MONTH_APRIL)
        {
            break;
        }

        dayAccumulator += gNumOfDaysInMonths[m - 1];
        m++;
        month--;

        if (month == 0)
        {
            month = CALENDAR_MONTH_DECEMBER;
        }
        if (m == CALENDAR_MONTH_MAX)
        {
            m = CALENDAR_MONTH_JANUARY;
        }
    }

    return dayAccumulator + day - 5; // - 5 because the game starts in april 5th
}

// FUN_0017d920 NONMATCHING
u32 clndGetCurrentMonth()
{
    u16 daysSinceApr5 = datGetDaysSinceApr5() + 4;
    u16 month = CALENDAR_MONTH_APRIL;

    while (gNumOfDaysInMonths[month - 1] <= daysSinceApr5)
    {
        daysSinceApr5 -= gNumOfDaysInMonths[month - 1];
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
    u16 daysSinceApr5 = datGetDaysSinceApr5() + 4;
    u16 month = CALENDAR_MONTH_APRIL;

    while (gNumOfDaysInMonths[month - 1] <= daysSinceApr5)
    {
        daysSinceApr5 -= gNumOfDaysInMonths[month - 1];
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
    u16 daysSinceApr5 = datGetDaysSinceApr5();
    u32 currDayOfMonth;
    u32 currMonth;
    u16 i;

    // was inlined
    if (clndGetWeekDay(daysSinceApr5) == CALENDAR_DAY_SUNDAY)
    {
        return true;
    }

    currMonth = clndGetMonthFromDaysSinceApr5(daysSinceApr5);
    currDayOfMonth = clndGetDayOfMonthFromDaysSinceApr5(daysSinceApr5);

    for (i = 0; i < 0x164; i++)
    {
        if (sHolidays[i].month == -1) break;
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

// FUN_0017e680
void* clndUpdateTask(KwlnTask* clndTask)
{
    // TODO

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
            ((CalendarTaskWork*)sClndTask->workData)->state = 5;
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

// FUN_0017fb90 NONMATCHING
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
                                              "CalenderDraw", // no
                                              clndUpdateTask,
                                              clndDestroyTask,
                                              work);
    if (clndTask == NULL)
    {
        return NULL;
    }

    sClndTask = clndTask;

    work->state = 3;
    H_SfdPlay_CreateTaskIdle(clndTask);

    return clndTask;
}

// FUN_00181720. Check if a siteibi event can be executed. If found, return its index. Return -1 if no event was found NONMATCHING
s32 clndFindAndExecSiteibiEvents()
{
    SiteibiEventTable* siteibiTable;
    u32 i;
    u32 daysSinceApr5;
    u32 month;
    u32 dayOfMonth;
    u8 time;
    u8 foundEvt;
    u16 slLvl;

    siteibiTable = Comu_GetSiteibiEvtTable();
    for (i = 0; i < siteibiTable->total; i++)
    {
        daysSinceApr5 = datGetDaysSinceApr5();
        month = clndGetMonthFromDaysSinceApr5(daysSinceApr5);

        if (siteibiTable->events[i].startMonth == month)
        {
            daysSinceApr5 = datGetDaysSinceApr5();
            dayOfMonth = clndGetDayOfMonthFromDaysSinceApr5(daysSinceApr5);

            if (siteibiTable->events[i].startDay == dayOfMonth)
            {
                time = datGetTime();

                if (siteibiTable->events[i].startTime == time)
                {
                    foundEvt = true;

                    if (siteibiTable->events[i].flagReqOn1 != 0 &&
                       (!datGetFlag(siteibiTable->events[i].flagReqOn1)))
                    {
                        foundEvt = false;
                    }
                    if (siteibiTable->events[i].flagReqOn2 != 0 &&
                       (!datGetFlag(siteibiTable->events[i].flagReqOn2)))
                    {
                        foundEvt = false;
                    }
                    if (siteibiTable->events[i].flagReqOff1 != 0 &&
                       (datGetFlag(siteibiTable->events[i].flagReqOff1)))
                    {
                        foundEvt = false;
                    }
                    if (siteibiTable->events[i].flagReqOff2 != 0 &&
                       (datGetFlag(siteibiTable->events[i].flagReqOff2)))
                    {
                        foundEvt = false;
                    }

                    if (siteibiTable->events[i].slID != SOCIAL_LINK_NONE)
                    {
                        slLvl = datGetSocialLinkLevel(siteibiTable->events[i].slID);
                        if (slLvl < siteibiTable->events[i].slLvlReq)
                        {
                            foundEvt = false;
                        }
                    }

                    if (foundEvt)
                    {
                        printf("## EXEC EVENT = %d ##\n", i);

                        datSetFlag(siteibiTable->events[i].flagToActivate, true);
                        return i;
                    }
                }
            }
        }
    }

    printf("## NO EVENT ##\n");
    return -1;
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

// FUN_00184d90
u32 clnd00184d90(KwlnTask* task)
{
    return ((CalendarTaskWork*)task->workData)->state == 2;
}

// FUN_00187520
void clnd00187520(KwlnTask* task)
{
    RwFree(task->workData);
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