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
extern u32 DAT_00836200;
#pragma alias DAT_00836200_ptr DAT_00836200
extern u8 DAT_00836200_ptr[];
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
extern u32 func_0016dce0(s16 socialLink);
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



















/* Removing this loses FUN_00172860 (MATCH nd0 -> MISMATCH nd10) - measured W161. */


















