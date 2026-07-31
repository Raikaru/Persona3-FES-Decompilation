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
extern s8 DAT_006a3d70[];
extern u16 DAT_006a3d72[];
extern u8 * PTR_DAT_006a38e8;
#pragma alias PTR_DAT_006a38e8_abs PTR_DAT_006a38e8
extern u8 PTR_DAT_006a38e8_abs[];
extern u8 * PTR_DAT_007cd6ec;
extern u8 * PTR_s_Susano_o_006a3ca0;
#pragma alias PTR_s_Susano_o_006a3ca0_abs PTR_s_Susano_o_006a3ca0
extern u8 * PTR_s_Susano_o_006a3ca0_abs[];
extern u8 * PTR_s_next_Friday_006a3bf4;
#pragma alias PTR_s_next_Friday_006a3bf4_abs PTR_s_next_Friday_006a3bf4
extern u8 PTR_s_next_Friday_006a3bf4_abs[];
extern u8 * PTR_s_next_Monday_006a3be4;
#pragma alias PTR_s_next_Monday_006a3be4_abs PTR_s_next_Monday_006a3be4
extern u8 PTR_s_next_Monday_006a3be4_abs[];
extern u8 * PTR_s_next_Saturday_006a3bf8;
#pragma alias PTR_s_next_Saturday_006a3bf8_abs PTR_s_next_Saturday_006a3bf8
extern u8 PTR_s_next_Saturday_006a3bf8_abs[];
extern u8 * PTR_s_next_Sunday_006a3be0;
#pragma alias PTR_s_next_Sunday_006a3be0_abs PTR_s_next_Sunday_006a3be0
extern u8 PTR_s_next_Sunday_006a3be0_abs[];
extern u8 * PTR_s_next_Thursday_006a3bf0;
#pragma alias PTR_s_next_Thursday_006a3bf0_abs PTR_s_next_Thursday_006a3bf0
extern u8 PTR_s_next_Thursday_006a3bf0_abs[];
extern u8 * PTR_s_next_Tuesday_006a3be8;
#pragma alias PTR_s_next_Tuesday_006a3be8_abs PTR_s_next_Tuesday_006a3be8
extern u8 PTR_s_next_Tuesday_006a3be8_abs[];
extern u8 * PTR_s_next_Wednesday_006a3bec;
#pragma alias PTR_s_next_Wednesday_006a3bec_abs PTR_s_next_Wednesday_006a3bec
extern u8 PTR_s_next_Wednesday_006a3bec_abs[];
extern u8 * PTR_s_tomorrow_006a3bfc;
#pragma alias PTR_s_tomorrow_006a3bfc_abs PTR_s_tomorrow_006a3bfc
extern u8 PTR_s_tomorrow_006a3bfc_abs[];

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
u8 * FUN_003c4040(int param_2,int param_1);
s8 FUN_003c40f0(int param_1);
u16 FUN_003c4110(int param_1);
u8 * FUN_003c4270(void);
u8 * FUN_003c4390(int param_1);
u8 * FUN_003c43f0(void);
u64 FUN_003c4400(void);
u64 FUN_003c4410(void);
u64 FUN_003c4420(void);

/* Region call-cast macros */
#define FUN_003c4040(...) ((u8 * (*)(...))FUN_003c4040)(__VA_ARGS__)
#define FUN_003c40f0(...) ((s8 (*)(...))FUN_003c40f0)(__VA_ARGS__)
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

static inline uintptr_t ComuData_AddOffsetFirst(uintptr_t offset, uintptr_t base)
{
    return offset + base;
}

#undef FUN_003c4040
#pragma push
#pragma opt_propagation off
#pragma alias comuDataGetLinkPairEntry FUN_003c4040
// FUN_003C4040


u8 * comuDataGetLinkPairEntry(int secondLink,int firstLink)
{
  int valid;
  int firstSocialLink;
  int secondSocialLink;
  u8 *relationshipTable;
  int rowOffset;

  firstSocialLink = firstLink;
  secondSocialLink = secondLink;
  valid = FUN_00172a50((short)secondSocialLink);
  if (valid == 0) {
    FUN_0019d3f0("comuData.c",0x30);
  }
  valid = FUN_00172a50((short)firstSocialLink);
  if (valid == 0) {
    FUN_0019d3f0("comuData.c",0x32);
  }
  rowOffset = firstSocialLink * 0x18;
  relationshipTable = PTR_DAT_006a38e8_abs;
  relationshipTable += rowOffset;
  return *(u8 **)(uintptr_t)ComuData_AddOffsetFirst((uintptr_t)(secondSocialLink * 4),
                                                     (uintptr_t)relationshipTable);
}
#define FUN_003c4040(...) ((u8 * (*)(...))FUN_003c4040)(__VA_ARGS__)
#pragma pop
#undef FUN_003c40f0
#pragma alias comuDataGetLinkType FUN_003c40f0
// FUN_003C40F0


s8 comuDataGetLinkType(int socialLink)



{

  return *(s8 *)(DAT_006a3d70 + socialLink * 4);

}
#define FUN_003c40f0(...) ((s8 (*)(...))FUN_003c40f0)(__VA_ARGS__)
#undef FUN_003c4110
#pragma alias comuDataGetLinkResourceId FUN_003c4110
// FUN_003C4110


u16 comuDataGetLinkResourceId(int socialLink)



{

  return DAT_006a3d72[socialLink * 2];

}
#define FUN_003c4110(...) ((u16 (*)(...))FUN_003c4110)(__VA_ARGS__)
#undef FUN_003c4270
#pragma alias comuDataGetNextMeetingDayString FUN_003c4270
// FUN_003C4270


u8 * comuDataGetNextMeetingDayString(void)



{
  int targetDay;
  short currentDay;
  u8 *dayString;
  u32 weekday;

  targetDay = FUN_0017d8b0();
  currentDay = FUN_0016ef20();
  if (targetDay == currentDay + 1) {
    dayString = *(u8 **)PTR_s_tomorrow_006a3bfc_abs;
    goto ReturnResult;
  }
  weekday = FUN_0017dae0(targetDay);
  switch(weekday) {
  case 0:
    dayString = *(u8 **)PTR_s_next_Sunday_006a3be0_abs;
    break;
  case 1:
    dayString = *(u8 **)PTR_s_next_Monday_006a3be4_abs;
    break;
  case 2:
    dayString = *(u8 **)PTR_s_next_Tuesday_006a3be8_abs;
    break;
  case 3:
    dayString = *(u8 **)PTR_s_next_Wednesday_006a3bec_abs;
    break;
  case 4:
    dayString = *(u8 **)PTR_s_next_Thursday_006a3bf0_abs;
    break;
  case 5:
    dayString = *(u8 **)PTR_s_next_Friday_006a3bf4_abs;
    break;
  case 6:
    dayString = *(u8 **)PTR_s_next_Saturday_006a3bf8_abs;
    break;
  default:
    FUN_0019d3f0("comuData.c",0xba);
    dayString = *(u8 **)PTR_s_next_Sunday_006a3be0_abs;
  }
ReturnResult:
  return dayString;
}
#define FUN_003c4270(...) ((u8 * (*)(...))FUN_003c4270)(__VA_ARGS__)
#undef FUN_003c4390
#pragma alias comuDataGetUltimatePersonaName FUN_003c4390
// FUN_003C4390


u8 * comuDataGetUltimatePersonaName(int socialLink)
{
  int index;

  index = socialLink - 1;

  if ((0x15 < index) || (index < 0)) {

    FUN_0019d3f0("comuData.c",0xc6);

  }

  return PTR_s_Susano_o_006a3ca0_abs[index];


}
#define FUN_003c4390(...) ((u8 * (*)(...))FUN_003c4390)(__VA_ARGS__)
#undef FUN_003c43f0
// FUN_003C43F0


u8 * FUN_003c43f0(void)



{

  return PTR_DAT_007cd6ec;

}

// FUN_003C4400
u64 FUN_003c4400(void)
{
    return 0;
}

// FUN_003C4410
u64 FUN_003c4410(void)
{
    return 0;
}

// FUN_003C4420
u64 FUN_003c4420(void)
{
    return 0;
}
#define FUN_003c43f0(...) ((u8 * (*)(...))FUN_003c43f0)(__VA_ARGS__)


typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))
typedef struct NmlistNode {
    u32 unk0[3];
    struct NmlistNode *prev;
    struct NmlistNode *next;
} NmlistNode;
typedef struct NmlistList {
    NmlistNode *head;
    NmlistNode *tail;
    NmlistNode *cursor;
    u16 count;
} NmlistList;

extern code DAT_00960178;
#pragma alias DAT_00960178_abs DAT_00960178
extern code DAT_00960178_abs[];
extern code DAT_0096017c;
#pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];
extern u8 LAB_003c4400[];
extern u8 LAB_003c4410[];
extern u8 LAB_003c4420[];
extern u8 LAB_003c5210[];
extern u8 LAB_003c57e0[];
extern u8 LAB_003c5810[];
extern u8 LAB_003c5840[];
extern void K_Assert(const char *file, s32 line);
extern const char D_006A3DE8[];
#pragma alias D_006A3DE8_abs D_006A3DE8
extern u8 D_006A3DE8_abs[];
extern void FUN_00521408(u32 dest, int value, u32 size);

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
int *FUN_003c4430(int *param_1);
int *FUN_003c44d0(int *param_1, code param_2, code param_3, code param_4);
void FUN_003c45f0(int param_1);
int *FUN_003c4650(u32 param_1, int *param_2, int *param_3);
void FUN_003c4710(int *param_1, int *param_2, int *param_3);
NmlistNode *FUN_003c4820(int *param_1, int *param_2);
int *FUN_003c4910(int *param_1, int *param_2, int *param_3);
NmlistNode *FUN_003c49e0(NmlistList *param_1, NmlistList *param_2, int *param_3);
#pragma alias FUN_003c4430_typed FUN_003c4430
extern int *FUN_003c4430_typed(int *param_1);
#pragma alias FUN_003c4710_typed FUN_003c4710
extern void FUN_003c4710_typed(int *param_1, int *param_2, int *param_3);
#pragma alias FUN_003c4820_typed FUN_003c4820
extern NmlistNode *FUN_003c4820_typed(int *param_1, int *param_2);
#pragma alias FUN_003c4f30_typed FUN_003c4f30
extern void FUN_003c4f30_typed(int param_1);
void FUN_003c4a90(int param_1,int param_2);
int * FUN_003c4b50(int *param_1,int *param_2,int param_3);
int FUN_003c4bf0(int *param_1,int *param_2,int param_3);
u32 FUN_003c4c80(int *param_1,int *param_2);
u32 FUN_003c4d20(int *param_1,int *param_2);
void FUN_003c4dc0(u64 param_1,u32 param_2);
u64 FUN_003c4de0(u64 param_1,int param_2,u32 param_3);
int FUN_003c4df0(u64 param_1,int *param_2,int param_3);
u32 FUN_003c4e50(u64 param_1, u32* param_2);
u32 FUN_003c4e60(u64 param_1, int param_2);
int *FUN_003c4e70(int *param_1);
void FUN_003c4f30(int param_1);
void FUN_003c4fc0(int param_1, int *param_2);
int FUN_003c50b0(int param_1,u32 param_2,int param_3);
void FUN_003c5180(int param_1, int param_2);
int FUN_003c5210(void);
void FUN_003c5220(void);

/* Region call-cast macros */
#define FUN_003c4430(...) ((int * (*)(...))FUN_003c4430)(__VA_ARGS__)
#define FUN_003c44d0(...) ((int * (*)(...))FUN_003c44d0)(__VA_ARGS__)
#define FUN_003c45f0(...) ((void (*)(...))FUN_003c45f0)(__VA_ARGS__)
#define FUN_003c4650(...) ((int * (*)(...))FUN_003c4650)(__VA_ARGS__)
#define FUN_003c4710(...) ((void (*)(...))FUN_003c4710)(__VA_ARGS__)
#define FUN_003c4820(...) ((NmlistNode * (*)(...))FUN_003c4820)(__VA_ARGS__)
#define FUN_003c4910(...) ((int * (*)(...))FUN_003c4910)(__VA_ARGS__)
#define FUN_003c49e0(...) ((NmlistNode * (*)(...))FUN_003c49e0)(__VA_ARGS__)
#define FUN_003c4a90(...) ((void (*)(...))FUN_003c4a90)(__VA_ARGS__)
#define FUN_003c4b50(...) ((int * (*)(...))FUN_003c4b50)(__VA_ARGS__)
#define FUN_003c4bf0(...) ((int (*)(...))FUN_003c4bf0)(__VA_ARGS__)
#define FUN_003c4c80(...) ((u32 (*)(...))FUN_003c4c80)(__VA_ARGS__)
#define FUN_003c4d20(...) ((u32 (*)(...))FUN_003c4d20)(__VA_ARGS__)
#define FUN_003c4dc0(...) ((void (*)(...))FUN_003c4dc0)(__VA_ARGS__)
#define FUN_003c4de0(...) ((u64 (*)(...))FUN_003c4de0)(__VA_ARGS__)
#define FUN_003c4df0(...) ((int (*)(...))FUN_003c4df0)(__VA_ARGS__)
#define FUN_003c4e50(...) ((u32 (*)(...))FUN_003c4e50)(__VA_ARGS__)
#define FUN_003c4e60(...) ((u32 (*)(...))FUN_003c4e60)(__VA_ARGS__)
#define FUN_003c4e70(...) ((int * (*)(...))FUN_003c4e70)(__VA_ARGS__)
#define FUN_003c4f30(...) ((void (*)(...))FUN_003c4f30)(__VA_ARGS__)
#define FUN_003c4f80(...) ((int (*)(...))FUN_003c4f80)(__VA_ARGS__)
#define FUN_003c4fc0(...) ((void (*)(...))FUN_003c4fc0)(__VA_ARGS__)
#define FUN_003c50b0(...) ((int (*)(...))FUN_003c50b0)(__VA_ARGS__)
#define FUN_003c5180(...) ((void (*)(...))FUN_003c5180)(__VA_ARGS__)
#define FUN_003c5220(...) ((void (*)(...))FUN_003c5220)(__VA_ARGS__)

#undef FUN_003c4430
// FUN_003C4430


int *FUN_003c4430(int *param_1)
{
    u8 *size;
    int *object;
    size = (u8 *)param_1 + 0x18;
    object = (int *)(*(code *)0x00960178)(size, 0x40000);
    if (object == 0) {
        K_Assert(D_006A3DE8, 0x60);
    }
    FUN_00521408((u32)object, 0, (u32)size);
    if (param_1 != 0) {
        *(u32 *)((u8 *)object + 0x14) = (u32)((u8 *)object + 0x18);
    }
    *(u32 *)((u8 *)object + 8) = (u32)size;
    return object;
}
#define FUN_003c4430(...) ((int * (*)(...))FUN_003c4430)(__VA_ARGS__)
#undef FUN_003c44d0
// FUN_003C44D0


int *FUN_003c44d0(int *param_1, code param_2, code param_3, code param_4)
{
    u8 *size;
    int *object;
    size = (u8 *)param_1 + 0x28;
    object = (int *)(*(code *)0x00960178)(size, 0x40000);
    if (object == 0) {
        K_Assert(D_006A3DE8, 0x37);
    }
    FUN_00521408((u32)object, 0, (u32)size);
    if (param_1 != 0) {
        *(u32 *)((u8 *)object + 0x24) = (u32)((u8 *)object + 0x28);
    }
    *(u32 *)((u8 *)object + 0x20) = (u32)param_1;
    if (param_2 != 0) {
        *(code *)((u8 *)object + 0x14) = param_2;
    } else {
        *(code *)((u8 *)object + 0x14) = (code)LAB_003c4400;
    }
    if (param_3 != 0) {
        *(code *)((u8 *)object + 0x18) = param_3;
    } else {
        *(code *)((u8 *)object + 0x18) = (code)LAB_003c4410;
    }
    if (param_4 != 0) {
        *(code *)((u8 *)object + 0x1c) = param_4;
    } else {
        *(code *)((u8 *)object + 0x1c) = (code)LAB_003c4420;
    }
    return object;
}
#define FUN_003c44d0(...) ((int * (*)(...))FUN_003c44d0)(__VA_ARGS__)
#undef FUN_003c45f0
#undef FUN_003c4a90
// FUN_003C45F0


void FUN_003c45f0(int param_1)
{
    FUN_003c4a90(param_1, (int)param_1 + 4);
    if (param_1 == 0)
    {
        return;
    }
    FUN_00521408(param_1, 0, *(u32 *)((int)param_1 + 0x20));
    DAT_0096017c_abs[0](param_1);
}
#define FUN_003c45f0(...) ((void (*)(...))FUN_003c45f0)(__VA_ARGS__)
#define FUN_003c4a90(...) ((void (*)(...))FUN_003c4a90)(__VA_ARGS__)
#undef FUN_003c4650
// FUN_003C4650


int *FUN_003c4650(u32 param_1, int *param_2, int *param_3)
{
    int *parent;
    int *owner;
    u8 *size;
    int *object;
    parent = param_2;
    owner = param_3;
    size = (u8 *)owner + 0x18;
    object = (int *)(*(code *)0x00960178)(size, 0x40000);
    if (object == 0) {
        K_Assert(D_006A3DE8, 0x60);
    }
    FUN_00521408((u32)object, 0, (u32)size);
    if (owner != 0) {
        *(u32 *)((u8 *)object + 0x14) = (u32)((u8 *)object + 0x18);
    }
    *(u32 *)((u8 *)object + 8) = (u32)size;
    if (parent == 0) {
        *(u32 *)object = (u32)object;
    } else {
        *(u32 *)object = (u32)parent;
    }
    return object;
}
#define FUN_003c4650(...) ((int * (*)(...))FUN_003c4650)(__VA_ARGS__)
#undef FUN_003c4710
// FUN_003C4710


void FUN_003c4710(int *param_1, int *param_2, int *param_3)
{
    NmlistList *list;
    NmlistNode *node;
    NmlistNode *after;
    if (param_1 == 0) {
        K_Assert(D_006A3DE8, 0x115);
    }
    list = (NmlistList *)param_1;
    node = (NmlistNode *)param_3;
    after = (NmlistNode *)param_2;
    list->count++;
    if (node != 0) {
        node->next = 0;
        node->prev = 0;
        if (after == 0) {
            if (list->head != 0) {
                node->prev = 0;
                node->next = list->head;
                list->head->prev = node;
            }
            list->head = node;
            if (list->tail == 0) {
                list->tail = node;
            }
        } else if (after->next != 0) {
            node->prev = after;
            node->next = after->next;
            after->next = node;
            node->next->prev = node;
        } else {
            node->prev = after;
            node->next = 0;
            after->next = node;
            list->tail = node;
        }
        if (list->cursor == 0) {
            list->cursor = node;
        }
    }
}
#define FUN_003c4710(...) ((void (*)(...))FUN_003c4710)(__VA_ARGS__)
#undef FUN_003c4820
// FUN_003C4820


NmlistNode *FUN_003c4820(int *param_1,int *param_2)
{
    NmlistList *list;
    NmlistNode *node;
    NmlistNode *result;
    NmlistNode *next;

    if (param_1 == 0) {
        K_Assert((const char *)D_006A3DE8_abs, 0x149);
    }
    if (param_2 == 0) {
        K_Assert((const char *)D_006A3DE8_abs, 0x14a);
    }
    list = (NmlistList *)param_1;
    node = (NmlistNode *)param_2;
    list->count--;
    result = node->prev;
    if (result == 0) {
        result = node->next;
        if (result == 0) {
            if (list->head == node) {
                list->tail = 0;
                list->head = 0;
            }
            result = 0;
        }
        else {
            result->prev = 0;
            list->head = result;
        }
    }
    else {
        next = node->next;
        if (next == 0) {
            result->next = 0;
            list->tail = result;
        }
        else {
            result->next = next;
            next->prev = result;
            result = result->next;
        }
    }
    node->prev = 0;
    node->next = 0;
    return result;
}
#define FUN_003c4820(...) ((NmlistNode * (*)(...))FUN_003c4820)(__VA_ARGS__)
#undef FUN_003c4910
// FUN_003C4910


int *FUN_003c4910(int *param_1,int *param_2,int *param_3)



{

  int *lVar1;

  u32 *puVar2;

  int iVar3;

  

  if (param_1 == 0) {

    FUN_0019d3f0("nmlist.c",0x17d);

  }

  lVar1 = FUN_003c4430_typed(param_3);

  puVar2 = (u32 *)lVar1;

  if (param_2 == 0) {

      *puVar2 = (u32)puVar2;

  }

  else {

    *puVar2 = (int)param_2;

  }

  if (lVar1 == 0) {

    FUN_0019d3f0("nmlist.c",0x180);

  }

  iVar3 = (int)param_1;

  FUN_003c4710_typed((int *)(iVar3 + 4),(int *)*(u32 *)(iVar3 + 8),lVar1);

  (*(code *)(iVar3 + 0x14))(param_1,lVar1);

  return lVar1;

}
#define FUN_003c4910(...) ((int * (*)(...))FUN_003c4910)(__VA_ARGS__)
#undef FUN_003c49e0
// FUN_003C49E0


NmlistNode *FUN_003c49e0(NmlistList *param_1,NmlistList *param_2,int *param_3)
{
  NmlistNode *node;
  NmlistList *list2;
  NmlistList *list;
  NmlistNode *next;

  node = (NmlistNode *)param_3;
  list2 = param_2;
  list = param_1;
  next = FUN_003c4820_typed((int *)list2,(int *)node);
  if (node == list2->cursor) {
    list2->cursor = (NmlistNode *)next;
  }
  (*(code *)((u8 *)list + 0x18))((int *)list,(int *)node);
  if (node != 0) {
    FUN_00521408((u32)node,0,(u32)node->unk0[2]);
    (*(code *)0x0096017c)((int *)node);
  }
  return next;
}

#define FUN_003c49e0(...) ((NmlistNode * (*)(...))FUN_003c49e0)(__VA_ARGS__)
#undef FUN_003c4a90
// FUN_003C4A90
void FUN_003c4a90(int param_1, int param_2)
{
    NmlistList* list;
    NmlistNode* node;
    NmlistNode* next;

    if (param_1 != 0 && param_2 != 0)
    {
        list = (NmlistList*)param_2;
        node = list->head;
        while (node != 0)
        {
            next = node->next;
            (*(code *)((u8*)param_1 + 0x18))(param_1, node);
            if (node != 0)
            {
                FUN_00521408((u32)node, 0, node->unk0[2]);
                DAT_0096017c_abs[0](node);
            }
            node = next;
        }
        list->count = 0;
        list->cursor = 0;
        list->tail = 0;
        list->head = 0;
    }
}
#define FUN_003c4a90(...) ((void (*)(...))FUN_003c4a90)(__VA_ARGS__)
#undef FUN_003c4b50
// FUN_003C4B50


int * FUN_003c4b50(int *param_1,int *param_2,int param_3)
{
  int *piVar1;

  if (param_1 == 0) {
    K_Assert((const char*)D_006A3DE8_abs,0x1c7);
  }
  if (param_2 == 0) {
    K_Assert((const char*)D_006A3DE8_abs,0x1c8);
  }
  piVar1 = (int *)*(u32 *)param_2;
  goto loop_check;
loop_body:
  if (*piVar1 == param_3) {
    return piVar1;
  }
  piVar1 = (int *)piVar1[4];
loop_check:
  if (piVar1 != (int *)0x0) {
    goto loop_body;
  }
  return (int *)0x0;
}
#define FUN_003c4b50(...) ((int * (*)(...))FUN_003c4b50)(__VA_ARGS__)
#undef FUN_003c4bf0
// FUN_003C4BF0

int FUN_003c4bf0(int *param_1,int *param_2,int param_3)
{
  int iVar1;
  if ((param_1 == 0) || (param_2 == 0)) {
    K_Assert((const char*)D_006A3DE8_abs,0x1f7);
  }
  iVar1 = *(int *)param_2;
  goto loop_check_2;
loop_body_2:
  if (*(int *)(iVar1 + 4) == param_3) {
    return iVar1;
  }
  iVar1 = *(int *)(iVar1 + 0x10);
loop_check_2:
  if (iVar1 != 0) {
    goto loop_body_2;
  }
  return 0;
}
#define FUN_003c4bf0(...) ((int (*)(...))FUN_003c4bf0)(__VA_ARGS__)
#undef FUN_003c4c80
// FUN_003C4C80

u32 FUN_003c4c80(int *param_1,int *param_2)
{

  int iVar1;

  u32 uVar2;

  u32 *puVar3;

  

  puVar3 = (u32 *)param_2;

  if (param_1 == 0) {

    uVar2 = 0;

  }

  else if (param_2 == 0) {

    uVar2 = 0;

  }

  else if (puVar3[2] == 0) {

    uVar2 = 0;

  }

  else {

    iVar1 = *(int *)(puVar3[2] + 0x10);

    if (iVar1 != 0) {
      puVar3[2] = iVar1;
    }
    else {
      if ((*(s16 *)((int)puVar3 + 0xe) & 2) == 0) {
        puVar3[2] = *puVar3;
      }
      else {
        return 0;
      }
    }

    *(s16 *)((int)puVar3 + 0xe) = *(s16 *)((int)puVar3 + 0xe) | 2;
    uVar2 = puVar3[2];

  }

  return uVar2;

}
#define FUN_003c4c80(...) ((u32 (*)(...))FUN_003c4c80)(__VA_ARGS__)
#undef FUN_003c4d20
// FUN_003C4D20


u32 FUN_003c4d20(int *param_1,int *param_2)
{
  int iVar1;
  u32 uVar2;
  u32 *puVar3;

  puVar3 = (u32 *)param_2;
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else if (param_2 == 0) {
    uVar2 = 0;
  }
  else if (puVar3[2] == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = *(int *)(puVar3[2] + 0xc);
    if (iVar1 != 0) {
      puVar3[2] = iVar1;
    }
    else {
      if ((*(s16 *)((int)puVar3 + 0xe) & 2) == 0) {
        puVar3[2] = puVar3[1];
      }
      else {
        return 0;
      }
    }
    *(s16 *)((int)puVar3 + 0xe) = *(s16 *)((int)puVar3 + 0xe) | 2;
    uVar2 = puVar3[2];
  }
  return uVar2;
}
#define FUN_003c4d20(...) ((u32 (*)(...))FUN_003c4d20)(__VA_ARGS__)
#undef FUN_003c4dc0
// FUN_003C4DC0


void FUN_003c4dc0(u64 param_1,u32 param_2)



{

  if (param_2 != 0) {

    *(s16 *)(param_2 + 0xe) = *(s16 *)(param_2 + 0xe) & -3;

  }

  return;

}
#define FUN_003c4dc0(...) ((void (*)(...))FUN_003c4dc0)(__VA_ARGS__)
#undef FUN_003c4de0
// FUN_003C4DE0


u64 FUN_003c4de0(u64 param_1,int param_2,u32 param_3)



{

  *(u32 *)(param_2 + 8) = param_3;

  return 0;

}
#define FUN_003c4de0(...) ((u64 (*)(...))FUN_003c4de0)(__VA_ARGS__)
#undef FUN_003c4df0
// FUN_003C4DF0


int FUN_003c4df0(u64 param_1,int *param_2,int param_3)
{
  int node;
  int index;

  index = 0;
  if (param_3 == -1) {
    return param_2[1];
  }

  node = *param_2;
  while (node != 0) {
    if (index == param_3) {
      param_2[2] = node;
      return node;
    }
    node = *(int *)(node + 0x10);
    index++;
  }
  return 0;
}
#define FUN_003c4df0(...) ((int (*)(...))FUN_003c4df0)(__VA_ARGS__)
#undef FUN_003c4e50
// FUN_003C4E50


u32 FUN_003c4e50(u64 param_1, u32* param_2)
{
    return param_2[2] = param_2[0];
}
#define FUN_003c4e50(...) ((u32 (*)(...))FUN_003c4e50)(__VA_ARGS__)
#undef FUN_003c4e60
// FUN_003C4E60


u32 FUN_003c4e60(u64 param_1, int param_2)
{
    return *(u32*)(param_2 + 8) = *(u32*)(param_2 + 4);
}
#define FUN_003c4e60(...) ((u32 (*)(...))FUN_003c4e60)(__VA_ARGS__)
#undef FUN_003c4e70
// FUN_003C4E70


int *FUN_003c4e70(int *param_1)
{
  int *ctx;
  int *node;
  int *next;
  int result;

  ctx = param_1;
  node = (int *)ctx[1];
  while (node != 0) {
    result = (*(code *)((u8 *)ctx + 0x1c))(ctx,node);
    if (result != 0) {
      next = (int *)FUN_003c4820_typed(ctx + 1,node);
      if (node == (int *)ctx[3]) {
        ctx[3] = (int)next;
      }
      (*(code *)((u8 *)ctx + 0x18))(ctx,node);
      FUN_003c4f30_typed((int)node);
      node = next;
    } else {
      node = *(int **)((u8 *)node + 0x10);
    }
  }
  return 0;
}
#define FUN_003c4e70(...) ((u64 (*)(...))FUN_003c4e70)(__VA_ARGS__)
#undef FUN_003c4f30
// FUN_003C4F30


void FUN_003c4f30(int param_1)



{

  if (param_1 != 0) {

    FUN_00521408(param_1,0,*(u32 *)((int)param_1 + 8));

    (*(void (**)(...))0x0096017c)(param_1);

  }

  return;

}
#define FUN_003c4f30(...) ((void (*)(...))FUN_003c4f30)(__VA_ARGS__)
#undef FUN_003c4f80
// FUN_003C4F80


int FUN_003c4f80(int param_1)



{

  int iVar1;

  int iVar2;

  s8 cVar3;

  

  iVar1 = 0;

  for (iVar2 = 0; *(char *)(param_1 + iVar2) != '\0'; iVar2 = iVar2 + 1) {

    cVar3 = *(char *)(param_1 + iVar2);

    iVar1 = iVar1 + cVar3;

  }

  return iVar1;

}
#define FUN_003c4f80(...) ((int (*)(...))FUN_003c4f80)(__VA_ARGS__)
#undef FUN_003c4fc0
#undef FUN_003c50b0
// FUN_003C4FC0


void FUN_003c4fc0(int param_1,int *param_2)



{

  int iVar4;
  u32 uVar1;
  int iVar3;
  int iVar2;

  

  iVar3 = 0;

  iVar2 = (int)param_1;

  iVar4 = *(int *)(iVar2 + 4);

  if (iVar4 != 0) {
    uVar1 = (*(code *)0x00960178)((u32)*(u16 *)(iVar2 + 0x10) << 2,0x40000);


    for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {
      *(int *)((int)uVar1 + iVar3 * 4) = iVar4;
      iVar3 = iVar3 + 1;


    }

    FUN_005225f8(uVar1,iVar3,4,param_2);

    FUN_003c50b0(param_1,uVar1,iVar3);
    *(u32 *)(iVar2 + 0xc) = *(u32 *)(iVar2 + 4);

    (*(code *)0x0096017c)(uVar1);

  }

  return;
}

#define FUN_003c4fc0(...) ((void (*)(...))FUN_003c4fc0)(__VA_ARGS__)
#undef FUN_003c50b0
#undef FUN_003c4710
// FUN_003C50B0
int FUN_003c50b0(int param_1, u32 param_2, int param_3)
{
    int index;
    u32* values;
    u32 *valuePtr;

    if (param_2 == 0 || param_3 == 0)
    {
        return 0;
    }
    if (param_1 + 4 != 0)
    {
        FUN_00521408(param_1 + 4, 0, 0x10);
    }
    values = (u32*)param_2;
    for (index = 0; index < param_3; index++)
    {
        valuePtr = values;
        valuePtr = valuePtr + index;
        FUN_003c4710_typed((int *)(param_1 + 4),
                           (int *)*(u32 *)(param_1 + 8),
                           (int *)*valuePtr);
    }
    return index;
}
// FUN_003C5170
int FUN_003c5170(void)
{
    return 0;
}
#define FUN_003c50b0(...) ((int (*)(...))FUN_003c50b0)(__VA_ARGS__)
#define FUN_003c4710(...) ((void (*)(...))FUN_003c4710)(__VA_ARGS__)
#undef FUN_003c5180
#undef FUN_003c44d0
// FUN_003C5180

void FUN_003c5180(int param_1,int param_2)



{
  int *iVar1;

  

  iVar1 = FUN_003c44d0((int *)(param_2 + 0x30),(code)LAB_003c57e0,(code)LAB_003c5810,(code)LAB_003c5840);

  iVar1 = *(int **)((u8 *)iVar1 + 0x24);

  if (param_1 == 0) {

    *(u8 **)((u8 *)iVar1 + 8) = (u8 *)&FUN_003c5210;

  }

  else {

    *(int **)((u8 *)iVar1 + 8) = (int *)param_1;

  }

  if (param_2 != 0) {

    *(int **)((u8 *)iVar1 + 0xc) = (int *)((u8 *)iVar1 + 0x30);
  }
  return;
}
#define FUN_003c5180(...) ((void (*)(...))FUN_003c5180)(__VA_ARGS__)
// FUN_003C5210
int FUN_003c5210(void)
{
    return 0;
}
#undef FUN_003c5220
#pragma alias FUN_003c45f0_typed FUN_003c45f0
void FUN_003c45f0_typed(void);
// FUN_003C5220


void FUN_003c5220(void)



{

  FUN_003c45f0_typed();

  return;

}
#define FUN_003c5220(...) ((void (*)(...))FUN_003c5220)(__VA_ARGS__)
