#include "Main/g_data.h"
#include "datCalendar.h"
#include "Kosaka/k_assert.h"
#include "temporary.h"

/* The social-link and event records live in the hero-status save area. */
#define SOCIAL_LINK_COUNT 30
#define SOCIAL_DATA_POINTS_OFFSET 0xD2
#define SOCIAL_DATA_COUNTER_OFFSET 0x14A
#define SOCIAL_DATA_DATE_OFFSET 0x10E
#define SOCIAL_DATA_STATUS_OFFSET 0x186

extern u8 D_00836458[];

extern u32 FUN_00172c50(u16* outValue);
extern u8 FUN_00172660(s16 socialLink);
extern void FUN_00172a20(u32 value);
extern u8 D_008364BC[];
extern s32 D_008364F4[];
extern s32 D_008365F4[];
extern u8 D_008366F4[];
extern u8 D_00836734[];
extern u8 D_00836752[];
extern u8 D_00833E80[];
extern u8 D_0083A34C[];

/* These are GP-relative resource pointers in the retail executable. */
extern u8* iGpffffb7f4;
extern u8* iGpffffb730;
extern u8* iGpffffb734;
extern u8* iGpffffb740;
extern u8* iGpffffb2e4;

extern s32 func_003951d0(s32 resourceId);
extern void func_00395170(s32 resourceId);
extern void func_003951a0(s32 resourceId);
extern s16* func_003bddd0(void);
extern u8* func_003beb10(s32 socialLink);
extern void func_0017ad90(void);
extern void func_0017ac60(u32 packedData);
extern s32 func_0016dce0(s16 socialLink);
extern void func_0016e410(s16 socialLink, s8 level);
extern void func_001828d0(s16 itemId, void* itemData);
extern void func_001831e0(s16 pcId, s16 slot, const void* itemData);

static s16* socialLinkPointValues(void)
{
    return (s16*)(gGlobalWork.heroStatus.socialLinkData + SOCIAL_DATA_POINTS_OFFSET);
}

static u16* socialLinkCounters(void)
{
    return (u16*)(gGlobalWork.heroStatus.socialLinkData + SOCIAL_DATA_COUNTER_OFFSET);
}

static s16* socialLinkDates(void)
{
    return (s16*)(gGlobalWork.heroStatus.socialLinkData + SOCIAL_DATA_DATE_OFFSET);
}

static void assertSocialLink(s32 socialLink, s32 line)
{
    K_ASSERT(socialLink >= 0 && socialLink < SOCIAL_LINK_COUNT, line);
}

// FUN_001717C0 NONMATCHING
u8 FUN_001717c0(s16 socialLink)
{
    assertSocialLink(socialLink, 0xAD0);
    if (func_003951d0(socialLink + 0x900) == 1)
    {
        return true;
    }

    assertSocialLink(socialLink, 0xAC3);
    return func_003951d0(socialLink + 0x920) == 1;
}

// FUN_001718B0 NONMATCHING
void FUN_001718b0(s16 socialLink)
{
    u16* counter;

    assertSocialLink(socialLink, 0xAE0);
    counter = &socialLinkCounters()[socialLink];
    if (*counter < 0x20)
    {
        (*counter)++;
    }
    else
    {
        *counter = 0x20;
    }
}

// FUN_00171960 NONMATCHING
void FUN_00171960(s16 socialLink, s16 points)
{
    s16* point;
    u16 selectedSocialLink;

    point = &socialLinkPointValues()[socialLink];
    if (*point >= 1000)
    {
        return;
    }

    assertSocialLink(socialLink, 0xB00);
    assertSocialLink(socialLink, 0x595);
    if (gGlobalWork.heroStatus.socialLinkStat[socialLink] > 0 &&
        gGlobalWork.heroStatus.socialLinkStat[socialLink] != 10)
    {
        *point -= points;
        if (FUN_00172c50(&selectedSocialLink) && selectedSocialLink == socialLink)
        {
            *point = 1;
        }
        if (*point < 0)
        {
            *point = 0;
        }
    }
}

// FUN_00171AC0 NONMATCHING
s16 FUN_00171ac0(s16 socialLink)
{
    assertSocialLink(socialLink, 0xB20);
    return socialLinkPointValues()[socialLink];
}

// FUN_00171B50 NONMATCHING
void FUN_00171b50(s16 socialLink)
{
    s16* defaults;

    assertSocialLink(socialLink, 0xB2C);
    defaults = func_003bddd0();
    assertSocialLink(socialLink, 0xAF0);
    socialLinkPointValues()[socialLink] = defaults[socialLink];
}

// FUN_00171C40 NONMATCHING
void FUN_00171c40(s16 socialLink, s32 enabled)
{
    s16* defaults;

    assertSocialLink(socialLink, 0xB3C);
    if (enabled == 1)
    {
        if (func_003951d0(socialLink + 0x900) == 0)
        {
            FUN_001718b0(socialLink);
            assertSocialLink(socialLink, 0xAF0);
            socialLinkPointValues()[socialLink] = 0;
            func_00395170(socialLink + 0x900);
        }
        func_00395170(0x987);
    }
    else
    {
        func_003951a0(socialLink + 0x900);
        assertSocialLink(socialLink, 0xB2C);
        defaults = func_003bddd0();
        assertSocialLink(socialLink, 0xAF0);
        socialLinkPointValues()[socialLink] = defaults[socialLink];
    }
}

// FUN_00171E90 NONMATCHING
void FUN_00171e90(s16 socialLink, u16 value)
{
    assertSocialLink(socialLink, 0xB58);
    if (value < 0x21)
    {
        socialLinkCounters()[socialLink] = value;
    }
    else
    {
        socialLinkCounters()[socialLink] = 0x20;
    }
}

// FUN_00171F50 NONMATCHING
void FUN_00171f50(s16 socialLink, s32 enabled)
{
    assertSocialLink(socialLink, 0xB9B);
    if (enabled == 1)
    {
        if (func_003951d0(socialLink + 0x920) == 0)
        {
            FUN_001718b0(socialLink);
            assertSocialLink(socialLink, 0xB8B);
            socialLinkDates()[socialLink] = gGlobalWork.calendarWork.daysSinceApr5;
            func_00395170(socialLink + 0x920);
        }
    }
    else
    {
        func_003951a0(socialLink + 0x920);
    }
}

// FUN_001720C0 NONMATCHING
s16 FUN_001720c0(s16 socialLink, s32* outDate)
{
    assertSocialLink(socialLink, 0xBB0);
    *outDate = socialLinkDates()[socialLink];
    return ((s16*)(gGlobalWork.heroStatus.socialLinkData + SOCIAL_DATA_STATUS_OFFSET))[socialLink];
}

// FUN_00172160 NONMATCHING
u8 FUN_00172160(s16 socialLink)
{
    assertSocialLink(socialLink, 0xBDC);
    return func_003951d0(socialLink + 0x940) == 1;
}

// FUN_00172200 NONMATCHING
void FUN_00172200(s16 socialLink, s32 enabled)
{
    s16* defaults;

    assertSocialLink(socialLink, 0xBEB);
    if (enabled == 1)
    {
        func_00395170(socialLink + 0x940);
        func_00395170(0x988);
    }
    else
    {
        func_003951a0(socialLink + 0x940);
        assertSocialLink(socialLink, 0xB3C);
        func_003951a0(socialLink + 0x900);
        assertSocialLink(socialLink, 0xB2C);
        defaults = func_003bddd0();
        K_ASSERT(func_0016dce0(socialLink) != 0, 0xAF0);
        socialLinkPointValues()[socialLink] = defaults[socialLink];
    }
}

// FUN_001723A0 NONMATCHING
void FUN_001723a0(s16 socialLink, s32 rank, s32 enabled)
{
    s32 resourceId;

    if (rank <= 0)
    {
        K_ASSERT(0, 0xC00);
    }
    assertSocialLink(socialLink, 0xC03);
    resourceId = rank + socialLink * 0x20 + 0x3FF;
    if (rank > 0 && rank < 0xB)
    {
        if (enabled == 1)
        {
            func_00395170(resourceId);
        }
        else
        {
            func_003951a0(resourceId);
        }
    }
}

// FUN_001724A0 NONMATCHING
void FUN_001724a0(s16 socialLink, s32 rank, s32 enabled)
{
    s32 resourceId;

    if (rank <= 0)
    {
        K_ASSERT(0, 0xC17);
    }
    assertSocialLink(socialLink, 0xC19);
    resourceId = rank + socialLink * 0x20 + 0x40F;
    if (rank > 0 && rank < 0xB)
    {
        if (enabled == 1)
        {
            func_00395170(resourceId);
        }
        else
        {
            func_003951a0(resourceId);
        }
    }
}

// FUN_001725A0 NONMATCHING
void FUN_001725a0(s16 socialLink)
{
    u8 socialLevel;

    assertSocialLink(socialLink, 0xC2E);
    socialLevel = gGlobalWork.heroStatus.socialLinkStat[socialLink];
    if (FUN_00172660(socialLink) == 1)
    {
        func_0016e410(socialLink, socialLevel + 1);
    }
}

// FUN_00172660 NONMATCHING
u8 FUN_00172660(s16 socialLink)
{
    s32 rank;

    assertSocialLink(socialLink, 0xC3F);
    for (rank = 1; rank <= 10; rank++)
    {
        if (func_003951d0(rank - 1 + socialLink * 0x20 + 0x400) == 1 &&
            func_003951d0(rank - 1 + socialLink * 0x20 + 0x410) == 0)
        {
            return true;
        }
    }
    return false;
}

// FUN_00172750
u8 FUN_00172750(const u8* data)
{
    if (data[0] == 0xFF && *(const u16*)(data + 2) == 0 && data[4] == 0 && data[5] == 0)
    {
        return false;
    }
    if (data[0] == 0 && *(const u16*)(data + 2) == 0 && data[4] == 0 && data[5] == 0)
    {
        return false;
    }
    return true;
}

// FUN_001727E0
void FUN_001727e0(void)
{
    ((u32*)D_0083A34C)[0] &= ~0x80;
    ((u32*)D_0083A34C)[0] &= ~0x100;
    ((u32*)D_0083A34C)[0] &= ~0x200;
    ((u32*)D_0083A34C)[0] &= ~0x400;
    ((u32*)D_0083A34C)[0] &= ~0x800;
}

// FUN_00172820
void FUN_00172820(s16 pcId)
{
    (*(u32*)D_0083A34C) |= 0x400;
    datSetPhysicalCondition(1, pcId);
}

#pragma optimization_level 0
// FUN_00172860
u8 FUN_00172860(void)
{
    if ((*(u32*)D_0083A34C & 0x400) != 0)
    {
        return 1;
    }
    return 0;
}
#pragma optimization_level 2

// FUN_001728D0 NONMATCHING
void FUN_001728d0(const u32* values)
{
    u32* destination = (u32*)D_00836458;
    s32 i;

    func_003951a0(0x980);
    memset(D_00836458, 0, 0x38);
    func_00395170(0x980);
    for (i = 0; i < 7; i++)
    {
        destination[i * 2] = values[i * 2];
        destination[i * 2 + 1] = values[i * 2 + 1];
    }
    FUN_00172a20(0);
    K_ASSERT(*(s32*)(D_00836458 + 4) < 5, 0xC9C);
}

// FUN_00172990
u32* FUN_00172990(void)
{
    return (u32*)D_00836458;
}

// FUN_001729A0
u8 FUN_001729a0(void)
{
    return func_003951d0(0x980) == 1;
}

// FUN_001729D0 NONMATCHING
u8 FUN_001729d0(u32* outValue)
{
    u8 value = D_00836458[0x24];
    if (value != 0xFF)
    {
        *outValue = value;
        return true;
    }
    return false;
}

// FUN_00172A10
u8 FUN_00172a10(void)
{
    return D_00836458[8];
}

// FUN_00172A20
void FUN_00172a20(u32 value)
{
    *(u32*)(D_00836458 + 0x10) = value;
}

// FUN_00172A30
u8 FUN_00172a30(void)
{
    return *(u32*)(D_00836458 + 0x10) == 1;
}

// FUN_00172A50 NONMATCHING
u8 FUN_00172a50(s16 value)
{
    s16 i;
    for (i = 0; i <= 5; i++)
    {
        if (value == i + 6)
        {
            return true;
        }
    }
    return false;
}

// FUN_00172AB0
void FUN_00172ab0(s16 personaId)
{
    D_00836458[0x38] = 1;
    *(s16*)(D_00836458 + 0x3A) = personaId;
    *(s16*)(D_00836458 + 0x3C) = gGlobalWork.calendarWork.daysSinceApr5;
}

// FUN_00172AE0
void FUN_00172ae0(void)
{
    func_003951a0(0x983);
    memset(D_008364BC, 0, 0x38);
}

// FUN_00172B20
void FUN_00172b20(void)
{
    u16 value;
    if (FUN_00172c50(&value) != 0)
    {
        func_0017ad90();
        func_003951a0(0x983);
        memset(D_008364BC, 0, 0x38);
    }
}

// FUN_00172B80 NONMATCHING
void FUN_00172b80(u8 first, u8 second, const u32* values)
{
    u32* destination = (u32*)D_008364BC;
    u32 packed;
    s32 i;

    memset(D_008364BC, 0, 0x38);
    for (i = 0; i < 7; i++)
    {
        destination[i * 2] = values[i * 2];
        destination[i * 2 + 1] = values[i * 2 + 1];
    }
    func_00395170(0x983);
    packed = (u32)first | ((u32)second << 8) | ((u32)((const u8*)values)[0x1E] << 16);
    func_0017ac60(packed);
}

// FUN_00172C50 NONMATCHING
u32 FUN_00172c50(u16* outValue)
{
    if (func_003951d0(0x983) == 1)
    {
        *outValue = D_008364BC[0];
        return (u32)D_008364BC;
    }
    return 0;
}

// FUN_00172CC0 NONMATCHING
void FUN_00172cc0(s16 socialLink)
{
    assertSocialLink(socialLink, 0xD3F);
    D_00836734[socialLink] = (u8)clndGetCurrentMonth();
    D_00836752[socialLink] = (u8)clndGetCurrentDay();
}

// FUN_00172D70 NONMATCHING
s32 FUN_00172d70(s32* outSocialLinks)
{
    s32 count = 0;
    s32 socialLink;
    u8 month = (u8)clndGetCurrentMonth();
    u8 day = (u8)clndGetCurrentDay();

    for (socialLink = 0; socialLink < SOCIAL_LINK_COUNT; socialLink++)
    {
        if (D_00836734[socialLink] == month && D_00836752[socialLink] == day)
        {
            outSocialLinks[count++] = socialLink;
        }
    }
    return count;
}

// FUN_00172E40
u8* FUN_00172e40(void)
{
    extern u8 D_00836498[];
    return D_00836498;
}
// FUN_00172E50 NONMATCHING
void FUN_00172e50(s32 slot, u8 owner, s32 amount)
{
    s32 remaining = (s32)gGlobalWork.heroMoney - amount;

    K_ASSERT(remaining >= 0, 0xD87);
    if (slot >= 0x40 || slot < 0)
    {
        K_Assert(__FILE__, 0xD8A);
    }
    if (D_008364F4[slot] != 1)
    {
        D_008364F4[slot] = 1;
        D_008365F4[slot] = 0;
        D_008366F4[slot] = owner;
        if (remaining > 9999999)
        {
            remaining = 9999999;
        }
        K_ASSERT((u32)remaining <= 9999999u, 0x68A);
        gGlobalWork.heroMoney = remaining;
    }
}
// FUN_00172F70 NONMATCHING
u8 FUN_00172f70(s32* outSlot)
{
    s32 slot;
    for (slot = 0; slot < 0x40; slot++)
    {
        if (D_008364F4[slot] == 1 && D_008365F4[slot] == 0)
        {
            const u8* record = func_003beb10(slot);
            if (clndGetDaysSinceStartFromDate(record[2], record[3]) <=
                gGlobalWork.calendarWork.daysSinceApr5)
            {
                *outSlot = slot;
                return true;
            }
        }
    }
    return false;
}

// FUN_00173040 NONMATCHING
void FUN_00173040(s32 slot)
{
    const u8* record = func_003beb10(slot);
    u8 itemCount = D_008366F4[slot];
    s32 itemIndex;

    K_ASSERT(D_008364F4[slot] != 0, 0xDBC);
    K_ASSERT(D_008365F4[slot] != 1, 0xDBF);
    D_008365F4[slot] = 1;
    for (itemIndex = 0; itemIndex < itemCount + 2; itemIndex++)
    {
        s16 itemId = *(s16*)(record + itemIndex * 2 + 4);
        u8 count = record[itemIndex + 0xC];
        if (itemId < 4000)
        {
            u8 itemData[0x20];
            s32 itemSlot;
            func_001828d0(itemId, itemData);
            for (itemSlot = 0; itemSlot < 0x14; itemSlot++)
            {
                if (*(s16*)(D_00833E80 + itemSlot * 0x14) == 0)
                {
                    func_001831e0(-1, itemSlot, itemData);
                    break;
                }
            }
            K_ASSERT(itemSlot < 0x14, 0xDE2);
        }
        else
        {
            func_00170860(-1, itemId, count);
        }
    }
}

