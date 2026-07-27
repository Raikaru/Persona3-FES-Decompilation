#include "Main/g_data.h"
#include "datCalendar.h"
#include "Kosaka/k_assert.h"
#include "temporary.h"

/* The social-link and event records live in the hero-status save area. */
#define SOCIAL_LINK_COUNT 30
#define SOCIAL_DATA_POINTS_OFFSET 0xD2
#define SOCIAL_DATA_COUNTER_OFFSET 0xD6

extern u8 D_00836458[];

extern u8* FUN_00172c50(s16* outValue);
extern s32 FUN_00172660(s32 socialLink);
extern void FUN_00172a20(u32 value);
extern s8 DAT_00836200[];
extern u8 D_008364BC[];
extern s32 D_008364F4[];
extern s32 D_008365F4[];
extern u8 D_008366F4[];
extern u8 D_00836734[];
extern u8 D_00836752[];
extern s16 D_0083679C[];
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

static void assertSocialLink(s32 socialLink, s32 line)
{
    K_ASSERT(socialLink >= 0 && socialLink < SOCIAL_LINK_COUNT, line);
}

// FUN_001717C0
u8 FUN_001717c0(s32 socialLink)
{
    s32 valid;
    s32 secondValid;
    s32 available;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xAD0);
    if (func_003951d0(socialLink + 0x900) == 1)
    {
        goto socialAvailable;
    }
    secondValid = true;
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        secondValid = false;
    }
    K_ASSERT(secondValid, 0xAC3);
    available = func_003951d0(socialLink + 0x920) == 1;
    if (available != true)
    {
        goto socialUnavailable;
    }
socialAvailable:
    return true;
socialUnavailable:
    return false;
}

#pragma alias datIncrementSocialLinkCounter FUN_001718b0
// FUN_001718B0
void datIncrementSocialLinkCounter(s32 socialLink)
{
    DatGlobal* globalWork = &gGlobalWork;
    s32 valid;
    u16* counter;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xAE0);
    counter = &((u16*)(globalWork->heroStatus.socialLinkData + SOCIAL_DATA_COUNTER_OFFSET))[socialLink];
    if (*counter < 0x20)
    {
        (*counter)++;
    }
    else
    {
        *counter = 0x20;
    }
}

#pragma alias datDecreaseSocialLinkPoints FUN_00171960
// FUN_00171960
void datDecreaseSocialLinkPoints(s32 socialLink, s32 points)
{
    struct SocialPointOwner
    {
        u8 unused[2];
        s8 levels[SOCIAL_LINK_COUNT];
        u8 padding[0xD2];
        s16 pointValues[SOCIAL_LINK_COUNT];
    };
    struct SocialPointOwner* pointOwner;
    s16 selectedSocialLink = 0;
    s16* point;
    s8* levels;
    s32 valid;
    s32 secondValid;
    s8 socialLevel;

    pointOwner = (struct SocialPointOwner*)&gGlobalWork;
    pointOwner = (struct SocialPointOwner*)((socialLink << 1) + (u32)pointOwner);
    point = pointOwner->pointValues;
    if (*point >= 1000)
    {
        return;
    }
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB00);
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        secondValid = false;
    }
    else
    {
        secondValid = true;
    }
    K_ASSERT(secondValid, 0x595);
    levels = ((struct SocialPointOwner*)&gGlobalWork)->levels;
    socialLevel = levels[(s16)socialLink];
    if (socialLevel > 0 && socialLevel != 10)
    {
        *point = *point - points;
        if (FUN_00172c50(&selectedSocialLink) != NULL && selectedSocialLink == socialLink)
        {
            *point = 1;
        }
        if (*point < 0)
        {
            *point = 0;
        }
    }
}

#pragma alias datGetSocialLinkPoints FUN_00171ac0
// FUN_00171AC0
s16 datGetSocialLinkPoints(s32 socialLink)
{
    DatGlobal* globalWork = &gGlobalWork;
    s32 valid;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB20);
    return ((s16*)(globalWork->heroStatus.socialLinkData + 0x5E))[socialLink];
}

#pragma alias datResetSocialLinkPoints FUN_00171b50
// FUN_00171B50
void datResetSocialLinkPoints(s32 socialLink)
{
    DatGlobal* globalWork;
    s32 valid;
    s32 secondValid;
    s16 defaultPoints;
    s16* defaults;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB2C);
    defaults = func_003bddd0();
    defaultPoints = defaults[socialLink];
    globalWork = &gGlobalWork;
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        secondValid = false;
    }
    else
    {
        secondValid = true;
    }
    K_ASSERT(secondValid, 0xAF0);
    ((s16*)(globalWork->heroStatus.socialLinkData + 0x5E))[socialLink] = defaultPoints;
}

// FUN_00171C40
void FUN_00171c40(s32 socialLink, s32 enabled)
{
    DatGlobal* globalWork;
    s32 valid;
    s32 secondValid;
    u16* counter;
    s16 defaultPoints;
    s16* defaults;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB3C);
    if (enabled == 1)
    {
        if (func_003951d0(socialLink + 0x900) == 0)
        {
            globalWork = &gGlobalWork;
            if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
            {
                valid = false;
            }
            else
            {
                valid = true;
            }
            K_ASSERT(valid, 0xAE0);
            counter = &((u16*)(globalWork->heroStatus.socialLinkData + SOCIAL_DATA_COUNTER_OFFSET))[socialLink];
            if (*counter < 0x20)
            {
                (*counter)++;
            }
            else
            {
                *counter = 0x20;
            }

            globalWork = &gGlobalWork;
            if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
            {
                valid = false;
            }
            else
            {
                valid = true;
            }
            K_ASSERT(valid, 0xAF0);
            ((s16*)(globalWork->heroStatus.socialLinkData + 0x5E))[socialLink] = 0;
            func_00395170(socialLink + 0x900);
        }
        func_00395170(0x987);
    }
    else
    {
        func_003951a0(socialLink + 0x900);
        if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
        {
            valid = false;
        }
        else
        {
            valid = true;
        }
        K_ASSERT(valid, 0xB2C);
        defaults = func_003bddd0();
        defaultPoints = defaults[socialLink];
        globalWork = &gGlobalWork;
        if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
        {
            secondValid = false;
        }
        else
        {
            secondValid = true;
        }
        K_ASSERT(secondValid, 0xAF0);
        ((s16*)(globalWork->heroStatus.socialLinkData + 0x5E))[socialLink] = defaultPoints;
    }
}

#pragma alias datSetSocialLinkCounter FUN_00171e90
// FUN_00171E90
void datSetSocialLinkCounter(s32 socialLink, u16 value)
{
    DatGlobal* globalWork = &gGlobalWork;
    s32 valid;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB58);
    if (value > 0x20)
    {
        ((u16*)(globalWork->heroStatus.socialLinkData + SOCIAL_DATA_COUNTER_OFFSET))[socialLink] = 0x20;
    }
    else
    {
        ((u16*)(globalWork->heroStatus.socialLinkData + SOCIAL_DATA_COUNTER_OFFSET))[socialLink] = value;
    }
}

// FUN_00171F50
void FUN_00171f50(s32 socialLink, s32 enabled)
{
    s32 valid;
    s32 secondValid;
    s32 thirdValid;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB9B);
    if (enabled == 1)
    {
        if (func_003951d0(socialLink + 0x920) == 0)
        {
            struct SocialDateOwner
            {
                u8 unused[0x12E];
                s16 dates[SOCIAL_LINK_COUNT];
            };
            struct SocialDateOwner* globalWork;

            if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
            {
                secondValid = false;
            }
            else
            {
                secondValid = true;
            }
            K_ASSERT(secondValid, 0xB76);
            FUN_001718b0(socialLink);
            globalWork = (struct SocialDateOwner*)&gGlobalWork;
            if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
            {
                thirdValid = false;
            }
            else
            {
                thirdValid = true;
            }
            K_ASSERT(thirdValid, 0xB8B);
            globalWork->dates[socialLink] = D_0083679C[0];
            func_00395170(socialLink + 0x920);
        }
    }
    else
    {
        func_003951a0(socialLink + 0x920);
    }
}

// FUN_001720C0
u16 FUN_001720c0(s32 socialLink, s32* outDate)
{
    struct SocialDateStateOwner
    {
        u8 unused[0x12E];
        s16 dates[SOCIAL_LINK_COUNT];
        u8 padding[0x3C];
        u16 status[SOCIAL_LINK_COUNT];
    };
    struct SocialDateStateOwner* globalWork = (struct SocialDateStateOwner*)&gGlobalWork;
    s32 valid;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xBB0);
    *outDate = globalWork->dates[socialLink];
    return globalWork->status[socialLink];
}

// FUN_00172160
u8 FUN_00172160(s32 socialLink)
{
    s32 valid;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xBDC);
    if (func_003951d0(socialLink + 0x940) == 1)
    {
        return true;
    }
    return false;
}

// FUN_00172200
void FUN_00172200(s32 socialLink, s32 enabled)
{
    struct SocialPointStorage
    {
        u8 unused[0xF2];
        s16 pointValues[SOCIAL_LINK_COUNT];
    };
    s32 valid;
    s32 secondValid;
    s32 thirdValid;
    s16* defaults;
    s16 defaultPoints;
    struct SocialPointStorage* globalWork;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xBEB);
    if (enabled == 1)
    {
        func_00395170(socialLink + 0x940);
        func_00395170(0x988);
        return;
    }
    func_003951a0(socialLink + 0x940);
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        secondValid = false;
    }
    else
    {
        secondValid = true;
    }
    K_ASSERT(secondValid, 0xB3C);
    func_003951a0(socialLink + 0x900);
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        thirdValid = false;
    }
    else
    {
        thirdValid = true;
    }
    K_ASSERT(thirdValid, 0xB2C);
    defaults = func_003bddd0();
    defaultPoints = defaults[socialLink];
    globalWork = (struct SocialPointStorage*)&gGlobalWork;
    K_ASSERT(func_0016dce0((s16)socialLink) != 0, 0xAF0);
    globalWork->pointValues[socialLink] = defaultPoints;
}

#pragma alias datSetSocialLinkRankUnlocked FUN_001723a0
// FUN_001723A0
void datSetSocialLinkRankUnlocked(s32 socialLink, s32 rank, s32 enabled)
{
    s32 resourceId = rank - 1 + (socialLink * 0x20 + 0x400);
    s32 valid;

    if (rank <= 0)
    {
        K_Assert(__FILE__, 0xC00);
    }
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xC03);
    if (rank <= 0 || rank > 10)
    {
        return;
    }
    if (enabled == 1)
    {
        func_00395170(resourceId);
        return;
    }
    func_003951a0(resourceId);
}

#pragma alias datSetSocialLinkRankAcknowledged FUN_001724a0
// FUN_001724A0
void datSetSocialLinkRankAcknowledged(s32 socialLink, s32 rank, s32 enabled)
{
    s32 resourceId = rank - 1 + (socialLink * 0x20 + 0x410);
    s32 valid;

    if (rank <= 0)
    {
        K_Assert(__FILE__, 0xC17);
    }
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xC19);
    if (rank <= 0 || rank > 10)
    {
        return;
    }
    if (enabled == 1)
    {
        func_00395170(resourceId);
        return;
    }
    func_003951a0(resourceId);
}

#pragma alias datApplyPendingSocialLinkRank FUN_001725a0
// FUN_001725A0
void datApplyPendingSocialLinkRank(s32 socialLink)
{
    struct SocialLevelOwner
    {
        u8 unused[2];
        s8 levels[SOCIAL_LINK_COUNT];
    };
    s16 shortSocialLink = socialLink;
    s8* levels = ((struct SocialLevelOwner*)&gGlobalWork)->levels;
    s32 socialLevel = levels[shortSocialLink];
    s32 valid;

    if (shortSocialLink < 0 || shortSocialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xC2E);
    if (FUN_00172660(socialLink) == 1)
    {
        func_0016e410((s16)socialLink, socialLevel + 1);
    }
}

#pragma alias datSocialLinkHasPendingRank FUN_00172660
// FUN_00172660
s32 datSocialLinkHasPendingRank(s32 socialLink)
{
    s32 valid;
    s32 rank;
    s32 firstResourceBase;
    s32 secondResourceBase;
    s32 rankOffset;
    s32 secondResource;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xC3F);
    rank = 1;
    secondResourceBase = (socialLink << 5) + 0x410;
    firstResourceBase = (socialLink << 5) + 0x400;
    while (rank <= 10)
    {
        rankOffset = rank - 1;
        secondResource = rankOffset + secondResourceBase;
        if (func_003951d0(rankOffset + firstResourceBase) == 1)
        {
            if (func_003951d0(secondResource) == 0)
            {
                return true;
            }
        }
        rank++;
    }
    return false;
}

#pragma alias datSocialEventRecordHasData FUN_00172750
// FUN_00172750
u8 datSocialEventRecordHasData(const u8* data)
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

/* Removing this loses FUN_00172860 (MATCH nd0 -> MISMATCH nd10) - measured W161. */
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

// FUN_001728D0
void FUN_001728d0(const u32* values)
{
    struct SocialDataOwner
    {
        u8 unused[0x1E4];
        s32 data[14];
    };
    struct SocialDataOwner* globalWork = (struct SocialDataOwner*)&gGlobalWork;
    const u32* source;
    u32* destination;
    u32 firstValue;
    u32 secondValue;
    s32 remaining;

    func_003951a0(0x980);
    memset(D_00836458, 0, 0x38);
    func_00395170(0x980);
    destination = (u32*)globalWork->data;
    remaining = 7;
    source = values;
    do
    {
        firstValue = source[0];
        secondValue = source[1];
        source += 2;
        remaining--;
        destination[0] = firstValue;
        destination[1] = secondValue;
        destination += 2;
    } while (remaining > 0);
    FUN_00172a20(0);
    if (globalWork->data[1] <= 4)
    {
        return;
    }
    K_Assert(__FILE__, 0xC9C);
}

#pragma alias datGetSocialEventData FUN_00172990
// FUN_00172990
u32* datGetSocialEventData(void)
{
    return (u32*)D_00836458;
}

#pragma alias datSocialEventDataIsLoaded FUN_001729a0
// FUN_001729A0
u8 datSocialEventDataIsLoaded(void)
{
    return func_003951d0(0x980) == 1;
}

#pragma alias datTryGetSocialEventValue FUN_001729d0
// FUN_001729D0
u8 datTryGetSocialEventValue(u32* outValue)
{
    struct SocialEventData
    {
        u8 unused[0x24];
        u8 value;
    };
    struct SocialEventData* data = (struct SocialEventData*)D_00836458;

    if (data->value != 0xFF)
    {
        *outValue = data->value;
        return true;
    }
    return false;
}

// FUN_00172A10
u8 FUN_00172a10(void)
{
    return D_00836458[8];
}

#pragma alias datSetSocialEventMode FUN_00172a20
// FUN_00172A20
void datSetSocialEventMode(u32 value)
{
    *(u32*)(D_00836458 + 0x10) = value;
}

#pragma alias datSocialEventModeIsActive FUN_00172a30
// FUN_00172A30
u8 datSocialEventModeIsActive(void)
{
    return *(u32*)(D_00836458 + 0x10) == 1;
}

#pragma alias datSocialLinkUsesRelationshipTable FUN_00172a50
// FUN_00172A50
u8 datSocialLinkUsesRelationshipTable(s16 value)
{
    s16 i;
    s32 checkedValue;

    i = 0;
    checkedValue = value;
    while (i < 6)
    {
        if (checkedValue == i + 6)
        {
            return true;
        }
        i++;
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
    s16 value;
    if (FUN_00172c50(&value) != 0)
    {
        func_0017ad90();
        func_003951a0(0x983);
        memset(D_008364BC, 0, 0x38);
    }
}

// FUN_00172B80
void FUN_00172b80(s8 first, s8 second, const u32* values)
{
    u32* destination = (u32*)D_008364BC;
    const u32* source;
    s32 remaining;
    u32 packed;
    u32 firstValue;
    u32 secondValue;

    memset(D_008364BC, 0, 0x38);
    remaining = 7;
    source = values;
    do
    {
        firstValue = source[0];
        secondValue = source[1];
        source += 2;
        remaining--;
        destination[0] = firstValue;
        destination[1] = secondValue;
        destination += 2;
    } while (remaining > 0);
    func_00395170(0x983);
    memset(&packed, 0, sizeof(packed));
    ((u8*)&packed)[0] = first;
    ((u8*)&packed)[1] = second;
    ((u8*)&packed)[2] = ((const u8*)values)[0];
    ((u8*)&packed)[3] = ((const u8*)values)[0x1E];
    func_0017ac60(packed);
}

// FUN_00172C50
u8* FUN_00172c50(s16* outValue)
{
    u8* data = D_008364BC;

    if (func_003951d0(0x983) == 1)
    {
        *outValue = data[0];
        return data;
    }
    return NULL;
}

#pragma alias datRecordSocialLinkDate FUN_00172cc0
// FUN_00172CC0
void datRecordSocialLinkDate(s32 socialLink)
{
    s32 valid;
    u32 month;
    u32 day;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xD3F);
    month = clndGetCurrentMonth();
    day = clndGetCurrentDay();
    D_00836734[(s16)socialLink] = (u8)month;
    D_00836752[(s16)socialLink] = (u8)day;
}

#pragma alias datGetSocialLinksForToday FUN_00172d70
// FUN_00172D70
s32 datGetSocialLinksForToday(s32* outSocialLinks)
{
    s32 count = 0;
    u32 month = clndGetCurrentMonth();
    u32 day = clndGetCurrentDay();
    s32 socialLink = 0;
    s8* data = DAT_00836200;

    for (; socialLink < SOCIAL_LINK_COUNT; socialLink++)
    {
        s8* record = data + socialLink;
        if (record[0x534] != month)
        {
            continue;
        }
        if (record[0x552] != day)
        {
            continue;
        }
        outSocialLinks[count] = socialLink;
        count++;
    }
    return count;
}

// FUN_00172E40
u8* FUN_00172e40(void)
{
    extern u8 D_00836498[];
    return D_00836498;
}
// FUN_00172E50
void FUN_00172e50(s32 slot, u8 owner, s32 amount)
{
    s32 remaining = (s32)gGlobalWork.heroMoney - amount;

    K_ASSERT(remaining >= 0, 0xD87);
    if (slot >= 0x40 && slot < 0)
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
// FUN_00172F70
u8 FUN_00172f70(s32* outSlot)
{
    s32* records = D_008364F4;
    s32 currentDay = D_0083679C[0];
    s32 slot;

    for (slot = 0; slot < 0x40; slot++)
    {
        s32* recordState = &records[slot];
        if (recordState[0] == 1 && recordState[0x40] == 0)
        {
            const u8* record = func_003beb10(slot);
            if (currentDay >= clndGetDaysSinceStartFromDate(record[2], record[3]))
            {
                *outSlot = slot;
                return true;
            }
        }
    }
    return false;
}

// FUN_00173040
void FUN_00173040(s32 slot)
{
    const u8* record;
    s16 itemId;
    s32* state;
    s32 itemIndex;
    s32 amount;
    s32 itemSlot;
    s32 found;
    s32 itemCount;
    u16 count;
    s32 normalizedCount;
    u8 itemData[0x20];

    record = func_003beb10(slot);
    K_ASSERT(D_008364F4[slot] != 0, 0xDBC);
    state = &D_008365F4[slot];
    K_ASSERT(*state != 1, 0xDBF);
    *state = 1;
    itemCount = D_008366F4[slot];
    for (itemIndex = 0; itemIndex < itemCount + 2; itemIndex++)
    {
        itemId = *(s16*)(record + itemIndex * 2 + 4);
        {
            const u8* itemRecord = record + itemIndex;
            count = itemRecord[0xC];
        }
        if (itemId >= 4000)
        {
            func_00170860(-1, itemId, count);
        }
        else
        {
            func_001828d0(itemId, itemData);
            amount = 0;
            normalizedCount = count & 0xFFFF;
            while (amount < normalizedCount)
            {
                found = 0;
                itemSlot = 0;
                {
                    const u8* itemSlots = D_00833E80;
                    while (itemSlot < 0x14)
                    {
                        if (*(u16*)(itemSlots + itemSlot * 0x14) == 0)
                        {
                            func_001831e0(-1, (s16)itemSlot, itemData);
                            found = 1;
                            break;
                        }
                        itemSlot++;
                    }
                }
                K_ASSERT(found != 0, 0xDE2);
                amount++;
            }
        }
    }
}

