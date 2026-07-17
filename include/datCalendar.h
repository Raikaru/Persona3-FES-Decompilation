#ifndef DATCALENDAR_H
#define DATCALENDAR_H

#include "Utils.h"

typedef struct KwlnTask KwlnTask;

typedef enum
{
    CALENDAR_TIME_NULL,
    CALENDAR_TIME_EARLY_MORNING,
    CALENDAR_TIME_MORNING,
    CALENDAR_TIME_LUNCH,
    CALENDAR_TIME_AFTERNOON,
    CALENDAR_TIME_AFTER_SCHOOL,
    CALENDAR_TIME_EVENING,
    CALENDAR_TIME_LATE_NIGHT,
    CALENDAR_TIME_DARK_HOUR
} CalendarTime;

typedef enum
{
    CALENDAR_MONTH_JANUARY = 1,
    CALENDAR_MONTH_FEBRUARY,
    CALENDAR_MONTH_MARCH,
    CALENDAR_MONTH_APRIL,
    CALENDAR_MONTH_MAY,
    CALENDAR_MONTH_JUNE,
    CALENDAR_MONTH_JULY,
    CALENDAR_MONTH_AUGUST,
    CALENDAR_MONTH_SEPTEMBER,
    CALENDAR_MONTH_OCTOBER,
    CALENDAR_MONTH_NOVEMBER,
    CALENDAR_MONTH_DECEMBER,
    CALENDAR_MONTH_MAX
} CalendarMonths;

typedef enum
{
    CALENDAR_DAY_SUNDAY,
    CALENDAR_DAY_MONDAY,
    CALENDAR_DAY_TUESDAY,
    CALENDAR_DAY_WEDNESDAY,
    CALENDAR_DAY_THURSDAY,
    CALENDAR_DAY_FRIDAY,
    CALENDAR_DAY_SATURDAY,
    CALENDAR_DAY_MAX
} CalendarDays;

typedef enum
{
    MOON_PHASE_WAXING_CRESCENT_1,
    MOON_PHASE_WAXING_CRESCENT_2,
    MOON_PHASE_WAXING_CRESCENT_3,
    MOON_PHASE_WAXING_CRESCENT_4,
    MOON_PHASE_WAXING_CRESCENT_5,
    MOON_PHASE_WAXING_CRESCENT_6,
    MOON_PHASE_FIRST_QUARTER,
    MOON_PHASE_WAXING_GIBBOUS_1,
    MOON_PHASE_WAXING_GIBBOUS_2,
    MOON_PHASE_WAXING_GIBBOUS_3,
    MOON_PHASE_WAXING_GIBBOUS_4,
    MOON_PHASE_WAXING_GIBBOUS_5,
    MOON_PHASE_WAXING_GIBBOUS_6,
    MOON_PHASE_WAXING_GIBBOUS_7,
    MOON_PHASE_FULL_MOON,
    MOON_PHASE_WANING_GIBBOUS_1,
    MOON_PHASE_WANING_GIBBOUS_2,
    MOON_PHASE_WANING_GIBBOUS_3,
    MOON_PHASE_WANING_GIBBOUS_4,
    MOON_PHASE_WANING_GIBBOUS_5,
    MOON_PHASE_WANING_GIBBOUS_6,
    MOON_PHASE_WANING_GIBBOUS_7,
    MOON_PHASE_LAST_QUARTER,
    MOON_PHASE_WANING_CRESCENT_1,
    MOON_PHASE_WANING_CRESCENT_2,
    MOON_PHASE_WANING_CRESCENT_3,
    MOON_PHASE_WANING_CRESCENT_4,
    MOON_PHASE_WANING_CRESCENT_5,
    MOON_PHASE_WANING_CRESCENT_6,
    MOON_PHASE_NEW_MOON
} MoonPhases;

typedef struct CalendarWork
{
    s16 daysSinceApr5;  // days since start of the game
    s8 time;
    u32 skipToTarget;   // 0 no skip, 1 skip
    s16 daysSkipTarget; // in days since april 5th (for example: daysSkipTarget = 40 -> will skip to may 15th)
    s8 timeSkipTarget;  // see enum 'CalendarTime'
} CalendarWork;

typedef enum
{
    CLNDTASK_STATE_DEBUG_INIT,
    CLNDTASK_STATE_DEBUG_UPDATE,
    CLNDTASK_STATE_DEBUG_WAIT_OPEN,
    CLNDTASK_STATE_DEBUG_WAIT_CLOSE,
    CLNDTASK_STATE_BEGIN_DAY,
    CLNDTASK_STATE_BEGIN_DAY_05,
    CLNDTASK_STATE_BEGIN_DAY_06,
    CLNDTASK_STATE_BEGIN_DAY_07,
    CLNDTASK_STATE_BEGIN_DAY_08,
    CLNDTASK_STATE_BEGIN_DAY_09,
    CLNDTASK_STATE_BEGIN_DAY_10,
    CLNDTASK_STATE_BEGIN_DAY_11,
    CLNDTASK_STATE_BEGIN_DAY_12,
    CLNDTASK_STATE_SELECT_TIME_ACTION,
    CLNDTASK_STATE_WAIT_ACTION_START,
    CLNDTASK_STATE_WAIT_ACTION_FINISH,
    CLNDTASK_STATE_CONFIRM_DAY_CHANGE,
    CLNDTASK_STATE_WAIT_SKIP_CONFIRM,
    CLNDTASK_STATE_REQSKIP,
    CLNDTASK_STATE_CREATE_SKIP_MESSAGE,
    CLNDTASK_STATE_WAIT_SKIP_MESSAGE,
    CLNDTASK_STATE_APPLY_SKIP,
    CLNDTASK_STATE_SKIP,
    CLNDTASK_STATE_RESTART_SKIP,
    CLNDTASK_STATE_STOP_DELAY
} CalendarTaskState;

// 44 bytes
typedef struct CalendarTaskWork
{
    u32 state;                    // 0x00. See CalendarTaskState.
    KwlnTask* debugCursor;        // 0x04. Red cursor for the debug menu.
    KwlnTask* debugCursorBg;      // 0x08. Blue background for the debug menu.
    KwlnTask* actionTask;         // 0x0c. Current time-of-day action task.
    KwlnTask* confirmationTask;   // 0x10. Date-change confirmation task.
    u32 reserved14;               // 0x14
    u32 reserved18;               // 0x18
    u32 reserved1c;               // 0x1c
    u32 stopDelay;                // 0x20. Frames remaining before task termination.
    u32 validateSkipTarget;       // 0x24. Verify the selected date/time pair before advancing.
    u32 reserved28;               // 0x28
} CalendarTaskWork;

extern const s16 gNumOfDaysInMonths[CALENDAR_MONTH_MAX - 1];

s32 clndGetMonthFromDaysSinceApr5(s32 daysSinceApr5);
s32 clndGetDaysSinceStartFromDate(s32 month, s32 day);
u32 clndGetCurrentMonth();
s32 clndGetDayOfMonthFromDaysSinceApr5(s32 daysSinceApr5);
u32 clndGetCurrentDay();
s32 clndGetWeekDay(s32 daysSinceApr5);
u32 clndGetCurrentWeekDay();
u8 clndIsHolidayOrSunday();
u32 clndIsDateInRange(u32 startMonth, u32 startDay, u32 endMonth, u32 endDay);
u8 clndIsDateInRangeFromDate(u32 monthToTest, u32 dayToTest, u32 startMonth, u32 startDay, u32 endMonth, u32 endDay);
u8 clndIsDateInRangeFromStart(u32 month, u32 day, u32 range);
void clndReqSkip();
KwlnTask* clndCreateTask();
u8 clndGetCurrentMoonPhase();
u8 clndGetMoonPhase(u32 daysSinceApr5);

u32 clndScrCmd_SET_DATE();

#endif