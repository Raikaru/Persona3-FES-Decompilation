#include "temporary.h"
#include "comuData.h"
#include "Main/g_data.h"
#include "Kosaka/k_assert.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))
#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif
extern u32 DAT_006a3d70;
extern u32 DAT_006a3d72;
extern u8 * PTR_DAT_006a38e8;
extern u8 * PTR_DAT_007cd6ec;
extern u8 * PTR_s_Susano_o_006a3ca0;
extern u8 * PTR_s_next_Friday_006a3bf4;
extern u8 * PTR_s_next_Monday_006a3be4;
extern u8 * PTR_s_next_Saturday_006a3bf8;
extern u8 * PTR_s_next_Sunday_006a3be0;
extern u8 * PTR_s_next_Thursday_006a3bf0;
extern u8 * PTR_s_next_Tuesday_006a3be8;
extern u8 * PTR_s_next_Wednesday_006a3bec;
extern u8 * PTR_s_tomorrow_006a3bfc;

static const char* daysStrings[CALENDAR_DAY_MAX] =
{
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

// 006a3ca0 (ultimate social link personas)
static const char* ultSLPersonasStrings[22] = 
{
    "Susano-o", "Surt", "Scathach",
    "Alilat", "Odin", "Kohryu",
    "Cybele", "Thor", "Melchizedek",
    "Arahabaki", "Norn", "Siegfried",
    "Attis", "Thanatos", "Yurlungur",
    "Beelzebub", "Chi You", "Helel",
    "Sandalaphon", "Asura", "Messiah",
    "Metatron"
};

// 006a3b40 (Will see were those strings are used in game later)
static const char* unkStrings1[5] = 
{
    "A perfect gift to capture a woman's heart!",
    "This'll make you much stronger!",
    "Provides excellent protection!",
    "Functional and fashionable!",
    "Guaranteed to make your friends jealous!"
};



/* Region 0x390000-0x3CFFFF recovered prototypes */
const char* Day_GetCurrentDayString(u32 month, u32 day);
const char* ComuData_FUN_003c4210(s32 idx);
u8 * FUN_003c4040(int param_1,int param_2);
u8 FUN_003c40f0(int param_1);
u16 FUN_003c4110(int param_1);
u8 * FUN_003c4270(void);
u8 * FUN_003c4390(int param_1);
u8 * FUN_003c43f0(void);

/* Region call-cast macros */
#define FUN_003c4040(...) ((u8 * (*)(...))FUN_003c4040)(__VA_ARGS__)
#define FUN_003c40f0(...) ((u8 (*)(...))FUN_003c40f0)(__VA_ARGS__)
#define FUN_003c4110(...) ((u16 (*)(...))FUN_003c4110)(__VA_ARGS__)
#define FUN_003c4270(...) ((u8 * (*)(...))FUN_003c4270)(__VA_ARGS__)
#define FUN_003c4390(...) ((u8 * (*)(...))FUN_003c4390)(__VA_ARGS__)
#define FUN_003c43f0(...) ((u8 * (*)(...))FUN_003c43f0)(__VA_ARGS__)

// FUN_003c4130
const char* Day_GetCurrentDayString(u32 month, u32 day)
{
    const char* dayString;
    u32 currentDay;

    currentDay = clndGetDaysSinceStartFromDate(month, day);
    currentDay = clndGetWeekDay(currentDay);

    switch(currentDay)
    {
        case CALENDAR_DAY_SUNDAY:
            dayString = daysStrings[CALENDAR_DAY_SUNDAY];
            break;
        case CALENDAR_DAY_MONDAY:
            dayString = daysStrings[CALENDAR_DAY_MONDAY];
            break;
        case CALENDAR_DAY_TUESDAY:
            dayString = daysStrings[CALENDAR_DAY_TUESDAY];
            break;
        case CALENDAR_DAY_WEDNESDAY:
            dayString = daysStrings[CALENDAR_DAY_WEDNESDAY];
            break;
        case CALENDAR_DAY_THURSDAY:
            dayString = daysStrings[CALENDAR_DAY_THURSDAY];
            break;
        case CALENDAR_DAY_FRIDAY:
            dayString = daysStrings[CALENDAR_DAY_FRIDAY];
            break;
        case CALENDAR_DAY_SATURDAY:
            dayString = daysStrings[CALENDAR_DAY_SATURDAY];
            break;
        default:
            K_ASSERT(false, 136);
            dayString = NULL;
    }

    return dayString;
}

// FUN_003c4210
const char* ComuData_FUN_003c4210(s32 idx)
{
    K_ASSERT(idx < 6, 147);

    return unkStrings1[idx];
}

const char* ComuData_GetUltSLPersonasString(u32 idx)
{
    idx--;
    K_ASSERT(idx > 0 && idx < ARRAY_SIZE(ultSLPersonasStrings) - 1, 198);

    return ultSLPersonasStrings[idx];
}

#undef FUN_003c4040
// FUN_003C4040 NONMATCHING


u8 * FUN_003c4040(int param_1,int param_2)



{

  long lVar1;

  

  lVar1 = FUN_00172a50((short)param_1);

  if (lVar1 == 0) {

    FUN_0019d3f0(0x6a3d58,0x30);

  }

  lVar1 = FUN_00172a50((short)param_2);

  if (lVar1 == 0) {

    FUN_0019d3f0(0x6a3d58,0x32);

  }

  return (&PTR_DAT_006a38e8)[param_2 * 6 + param_1];

}
#define FUN_003c4040(...) ((u8 * (*)(...))FUN_003c4040)(__VA_ARGS__)
#undef FUN_003c40f0
// FUN_003C40F0 NONMATCHING


u8 FUN_003c40f0(int param_1)



{

  return (&DAT_006a3d70)[param_1 * 4];

}
#define FUN_003c40f0(...) ((u8 (*)(...))FUN_003c40f0)(__VA_ARGS__)
#undef FUN_003c4110
// FUN_003C4110 NONMATCHING


u16 FUN_003c4110(int param_1)



{

  return *(u16 *)(&DAT_006a3d72 + param_1 * 4);

}
#define FUN_003c4110(...) ((u16 (*)(...))FUN_003c4110)(__VA_ARGS__)
#undef FUN_003c4270
// FUN_003C4270 NONMATCHING


u8 * FUN_003c4270(void)



{

  short sVar1;

  int iVar2;

  u8 *puVar3;

  u64 uVar4;

  

  iVar2 = FUN_0017d8b0();

  sVar1 = FUN_0016ef20();

  puVar3 = PTR_s_tomorrow_006a3bfc;

  if (iVar2 != sVar1 + 1) {

    uVar4 = FUN_0017dae0(iVar2);

    switch(uVar4) {

    case 0:

      puVar3 = PTR_s_next_Sunday_006a3be0;

      break;

    case 1:

      puVar3 = PTR_s_next_Monday_006a3be4;

      break;

    case 2:

      puVar3 = PTR_s_next_Tuesday_006a3be8;

      break;

    case 3:

      puVar3 = PTR_s_next_Wednesday_006a3bec;

      break;

    case 4:

      puVar3 = PTR_s_next_Thursday_006a3bf0;

      break;

    case 5:

      puVar3 = PTR_s_next_Friday_006a3bf4;

      break;

    case 6:

      puVar3 = PTR_s_next_Saturday_006a3bf8;

      break;

    default:

      FUN_0019d3f0(0x6a3d58,0xba);

      puVar3 = PTR_s_next_Sunday_006a3be0;

    }

  }

  return puVar3;

}
#define FUN_003c4270(...) ((u8 * (*)(...))FUN_003c4270)(__VA_ARGS__)
#undef FUN_003c4390
// FUN_003C4390 NONMATCHING


u8 * FUN_003c4390(int param_1)



{

  param_1 = param_1 + -1;

  if ((0x15 < param_1) || (param_1 < 0)) {

    FUN_0019d3f0(0x6a3d58,0xc6);

  }

  return (&PTR_s_Susano_o_006a3ca0)[param_1];

}
#define FUN_003c4390(...) ((u8 * (*)(...))FUN_003c4390)(__VA_ARGS__)
#undef FUN_003c43f0
// FUN_003C43F0 NONMATCHING


u8 * FUN_003c43f0(void)



{

  return PTR_DAT_007cd6ec;

}
#define FUN_003c43f0(...) ((u8 * (*)(...))FUN_003c43f0)(__VA_ARGS__)
