#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Result/br_panel.h"
#include "Main/Battle/Result/br_res.h"
#include "Main/Social/sfl_res.h"
#include "Main/Social/sfl_script.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"
#include "h_fade.h"
#include "rw/rwcore.h"
#include "rw/rprandom.h"
#pragma alias sflResGetTutorialFileUnchecked FUN_0020ea00
extern void* sflResGetTutorialFileUnchecked();


/*
 * Battle-result tasks deliberately use byte offsets.  The retail work areas
 * are private to the result system and are shared by several child tasks;
 * keeping the offsets here avoids inventing public layouts for those areas.
 */
#define BR_U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define BR_S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define BR_U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define BR_S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define BR_U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define BR_TASK_WORK(t) ((u8 *)((t)->workData))
#define BR_ROOT_TASK_WORK(t) BR_TASK_WORK(t)
#define BR_SET_STATE(p, s) (BR_U32((p), 0x0c) = (u32)(s))
#define BR_ALLOC2(n, f) (*(void *(**)(u32, u32))jtbl_00960178_abs)((n), (f))
#define BR_FREE(p) (*(void (**)(void *))jtbl_0096017C)((p))

static u8 *sBrRoot;       /* GP-relative -0x4a18 */
static u8 *sBrCard;       /* GP-relative -0x4a14 */
static u8 *sBrReward;     /* GP-relative -0x4a10 */

extern u32 jtbl_00960178[];
#pragma alias jtbl_00960178_abs jtbl_00960178
extern u8 jtbl_00960178_abs[];
extern u32 jtbl_0096017C[];

/* Result-resource and data helpers not yet described by public headers. */
extern s32 printf(const char *, ...);
extern const char D_006845c0[];
extern const char D_006845d0[];
extern const char D_006845f0[];
 
extern void func_002350f0(void);
extern void func_00278550(void);
extern void func_00275cb0(void);
extern void func_003c77a0(void);
extern void brPersonaShutdown(void);
extern void brPersonaDestroy(void);
extern void brHero00262730(void);
extern void brHero002630e0(void);
extern void func_00234960(void);
extern void func_00233e70(void);
extern void func_00272380(void);
extern void func_00275a80(void);
extern void func_00276920(void);
extern void func_00276d30(void);
extern void func_002362e0(void);
extern void func_00262790(void);
extern void func_00275a90(void);
extern void func_0010a370(s32, const char *);
extern void func_00171390(u32);
extern void func_00174e20(u16);
extern u32 dat00171360(u16);
extern s32 func_0016d280(s32);
extern u32 func_0016f380(u32);
extern void func_0016f3e0(u32, u32);
extern u32 func_00173220(u16);
extern u32 func_00174b40(u16);
extern u32 func_001756f0(void);
extern u32 func_00175410(void);
extern u32 func_00175ce0(DatPersonaWork *, u16 *);
extern u32 func_001761b0(DatPersonaWork *);
extern u32 func_00176100(DatPersonaWork *, u16 *);
extern u32 func_001fbdf0(u32, u32, u32, u32, u32);
extern u32 func_001fbfa0(u32, u32, u32, u32, u32, u32);
extern u32 func_001f9e90(u16, u32);
extern void func_001fb4b0(void *, s32, s32, s32, s32 *, s32 *);
extern u8 *DAT_007ce430;
extern u32 func_001f9680(s32 *);
extern void func_001f9c60(void);
extern u32 func_001f9a80(void);
extern void func_001f98d0(void);
extern void sflResult001f9770(u16 *, s32 *);
extern void sflResult001f9800(u16 *, s32 *);
extern u32 sflResult001f9890(void);
extern void sflResult001f9630(void);
extern void *func_001ef500(void *);

extern void func_00219c90(void *);
extern void func_00239170(void *);
extern void func_0023d7a0(void *);
extern void func_0023d7f0(void);
extern void func_0024da00(void *);
extern void sflCamera0024d110(void *);
extern void func_002534d0(void *);
extern void sflScript00259610(void *);
extern void sflCursor0025a110(void *);
extern void func_00215a50(void *);
extern void func_00260970(void *);
extern void sflCount0025b4a0(void *);
extern void sflPersonaInit(void *);
extern u32 sflGround0023c350(void);
extern void func_00219d90(void);
extern void func_00215fc0(void);
extern u32 func_00254f20(void);
extern u32 func_00254f70(void);
extern void func_003c72d0(void *);
extern void func_0023d130(void);
extern void func_0023ee50(void);
extern void sflCard00259250(void);
extern u32 sflGround0023d1f0(void);
extern u32 sflCard002592c0(void);
extern u32 sflCard002582b0(void);
extern void sflScript00259640(void);
extern u32 func_00259740(void);
extern u32 sflScript002596f0(void);
extern u32 sflCard00258af0(void);
extern u32 sflCount0025b640(void);
extern void sflCount0025b5f0(void);
extern void sflCursor0025aa70(void);
extern void sflCard00258490(void);
extern u8 *func_00256030(void);
extern void sflCard00258090(void);
extern void sflCard002580e0(void);
extern void func_0023f1d0(void);
extern void func_0023cda0(void);
extern void func_003c74e0(void);
extern u32 sflPanel0023f390(void);
extern u32 sflGround0023d0e0(void);
extern void func_00255fe0(void);
extern void func_002550b0(void);
extern void func_00258300(void);
extern u32 func_003c7610(void);
extern void func_003c7990(s32);
extern u32 func_003c7850(void);
extern u32 func_003c7650(s32);
extern u32 func_003c78d0(void);
extern void func_002594c0(void);
extern u32 sflCard002595c0(void);
extern void func_003c94e0(void *);
extern void func_003c9790(s32);
extern void func_0025b690(void);
extern void func_0025a130(void);
extern void func_0023d8f0(void);
extern void func_0024db90(void);
extern void func_0024dc10(void);
extern void sflCamera0024d1c0(void);
extern void func_00253a40(void);
extern void func_002392d0(void);
extern void sflPersonaUpdate(void);

extern void func_0023b990(void);
extern void func_00254b90(void);
extern void func_0025bbf0(void);
extern void func_0025a440(void);
extern void func_001f64c0(void);
extern void func_002168f0(void);
extern void func_0023e970(void);
extern void sflPersonaShutdown(void *);
extern void sflCount0025b4b0(void);
extern void func_00215aa0(void);
extern void sflPsel00260a10(void);
extern void func_0025a120(void);
extern void func_00259630(void);
extern void sflCard00253560(void);
extern void sflCamera0024d160(void);
extern void func_0024da20(void);
extern void sflPanel0023d870(void);
extern void func_0023d7b0(void);
extern void sflGround00239280(void);
extern void func_0021a1b0(void);

extern void func_004c9d70(void *, float);
extern void func_0021a840(void);
extern void func_0024fd10(void *);
extern void func_0024f9f0(void *, const float *);
extern void func_0024da60(void *);
extern void func_0024f090(void *);
extern void func_0024d8d0(void *);
extern void sflCamera0024d2e0(s32, void *);
extern void sflCamera0024d940(void *, void *);
extern void sflCamera0024d9a0(void *, void *);
extern void sflCamera0024d280(void *);
extern void func_0024d4c0(s32);
extern void func_0023c280(void);
extern u8 *func_00209e10(void);
extern u8 *func_00209e20(void);
extern u8 *func_00209e60(void);
extern u8 *func_00209e70(void);
extern u8 *func_00209dc0(void);
extern u8 *func_00209dd0(void);
extern u8 *func_00209d00(void);
extern u8 *func_00209c40(void);
extern u8 *func_00209c80(void);
extern u8 *func_00209cc0(void);
extern u8 *func_00209d40(u8 *);
extern char *func_00209e80(void);
extern char *func_00209e90(void);
extern u32 func_00255130(void);
extern void func_00254e10(void);
extern void *sflCard002537f0(u16);
extern u32 sflCard002536b0(u32, u32);
extern void sflCard00255170(void *);
extern void sflCard00255190(void *);
extern void func_002551b0(void *);
extern void sflCard00253920(void);
extern void sflScript00259690(void *, u32);
extern void sflScript00259b00(u16);
extern void sflScript00259b60(u16);
extern void sflScript00259c10(void);
extern void sflScript00259bc0(void);
extern void sflScript00259c60(u16);
extern void sflScript00259cc0(void);
extern void sflScriptQueueEndCommand(void);
extern void sflScriptQueueWaitCommand(u16 frames);
extern void sflScriptQueueOpenCommand(u16 card);
extern void sflScriptQueueWaitForActionsCommand(void);
extern void sflScriptQueueStartActionsCommand(void);
extern void sflScriptQueueSetCardValueCommand(u16 value);
extern void sflScriptQueueShuffleCommand(void);
extern void func_002595c0(void);
extern void func_002508c0(void *, const float *, s32);
extern void func_0020b250(void *);
extern void func_00209f00(void *);
extern void func_0020c590(void *, u16);
extern void func_0020a800(void *);
extern void func_0020c5f0(void *, u32, u32);
extern void func_0024fd80(void *);
extern f32 func_0020c500(void *, f32);
extern void func_0020c400(void *, const float *, float, float *);
extern void func_0020cc80(void *, const u8 *);
extern void gcPose0024f960(void *, const float *);
extern void sflResSetSpriteScale(void *, const f32 *);
extern void sflResSetSpriteRotation(void *, const f32 *);
extern void func_004bdde0(f32, f32 *, const f32 *, u32);
extern void func_0020ac90(void *);
extern void *sflResGetBaseSpriteData(void);
extern u32 func_0035c250(u32);
extern u32 sflResult001f99f0(void);
extern u32 func_001831e0(s16, s16, const void *);
extern u32 scrForceTraceCode(void *);
extern void K_Fldrc_DestroyArchives(void);
extern void func_00217590(u16);
extern void func_00215b00(void);
extern void scrReleaseScript(void *);
extern void *scrStartScriptFirstPrcd(void *header);
extern void func_0021ab80(u16 id);
extern void func_0021a920(u32 majorId, u32 minorId);
extern char D_00684850[];
extern char D_00684620[];
extern char D_006846CE[];
extern char D_006846DE[];
extern char D_00684718[];
extern char D_00684730[];
extern char D_00684750[];
extern char D_00684770[];
extern char D_00684788[];
extern char D_006847A0[];
extern char D_006847D0[];
extern char D_006847E0[];
extern char D_006847F0[];
extern char D_00684800[];
extern char D_00684810[];
extern char D_00684820[];
extern char D_00684830[];
extern char D_00684840[];
extern char D_00696950[];
extern char D_00696948[];
extern char D_00696964[];
extern char D_00696960[];
extern char D_00696958[];
extern u32 func_00255130(void);
extern void func_00257f10(void);
extern void func_002599c0(u32, u32);
extern void func_00259a60(u32, s32);
extern void sflScript00259970(void);
extern f32 func_00530da0(f32);
extern u32 datGetScenarioMode(void);
extern void sflResRequestBaseArchive(void);
extern u32 func_001f9170(s32);
extern void func_00173660(DatPersonaWork *, s32);
extern u32 func_0021a120(void);
extern void func_00258300(void);
extern void func_002550b0(void);
extern void *func_0034fcd0(void *);
extern u16 datGetMaxHp(s16);
extern void *sflResGetBaseDataFile(s32);
extern u16 func_00170760(s16, s16);
extern void func_00170860(s16, s16, u16);
extern void datSetMoney(u32);
extern void func_001828d0(s16, void *, void *);
#pragma alias func_001828d0_2arg func_001828d0
extern void func_001828d0_2arg(s16, void *);
extern void func_00182d90(s16, s16, u32, void *);
extern void func_00521250(void *, const void *, u32);
extern u32 func_003c7bc0(s32, u32);
extern u32 func_003c7c20(s32, u32, u32);
extern void func_003c7430(s32);
extern void func_0010a4e0(s32, s32, s32, s32);
extern const char *h_camp_getAcademicLevelString(s16);
extern const char *h_camp_getCharmLevelString(s16);
extern const char *h_camp_getCourageLevelString(s16);
extern void func_0021eac0(void *, float);
extern void func_0023f010(void);
extern void func_0023ca10(void);
extern void *kwlnGetMainCamera(void);
extern void func_00255f80(void);
extern void func_0025a7d0(void);
extern void func_0025b4f0(void);
extern void sflPanel0023f3e0(void);
extern void sflCard00259310(void);
extern u32 sflCard002561c0(void *);
extern u32 sflCard002561d0(void *);
extern u32 sflCard00259380(void);
extern void sflResult001f9100(void);
extern void sflResSetSpritePosition(void *, const float *);
extern void func_0034fcf0(void *);
extern u32 D_00684610[];
extern u32 func_001775a0(u32, ...);
extern u32 func_0016c6f0(u32);
extern u32 func_00177280(u32);
extern u32 func_0011a810(u32);
extern u32 func_0016c740(u32);
extern u32 func_001772f0(u32);
extern u32 func_0011a840(u32);
extern u32 func_0016c790(u32);
extern u32 func_00177360(u32);
extern u32 func_0011a870(u32);
extern u32 func_0016c4f0(u32);
extern u32 func_0016c5f0(u32);
extern u32 func_0016c570(u32);
extern u32 func_0016c970(u32);
extern u32 func_0016c920(u32);
extern void func_0016cf40(u32, u32);
extern void func_0016cf90(u32, u32);
extern void func_0016d8b0(u32, u32);
extern void func_0016d6b0(u32, u32);
extern u32 func_00488f30(void);
extern void sflResRequestTutorialArchive(void);
extern u32 func_0016f190(u32);
extern void func_0023f430(void);
extern u32 func_002561c0(void *);
extern u32 func_002561d0(void *);
extern void func_005225a8(const char *, s32, s32);
extern void func_00174800(u32);
extern void func_00174650(u32, u32, u32);
extern void func_0016cfe0(u32, u32);
extern void func_0016d090(u32, u32);
extern void func_0016d160(u32, u32);


void func_001f0990(KwlnTask *);
void func_001f0f40(KwlnTask *);
void func_001f0ff0(void);
u8 *brRoot001f1c50(void);
void func_001f1140(KwlnTask *);
void func_001f13b0(KwlnTask *);
void brRoot001f1e90(KwlnTask *);
void func_001f30d0(KwlnTask *);
void func_001f30f0(KwlnTask *);
void func_001f3270(KwlnTask *);
void func_001f4650(KwlnTask *, const u8 *);
void func_001f4750(KwlnTask *);
u32 func_001f4990(void);
void func_001f4a00(void);
void func_001f53a0(void);
void func_001f54a0(void);
void func_001f5510(void);
void func_001f55e0(void);
void func_001f5650(void);
void func_001f56b0(void);
u32 func_001f5760(u16);
u32 func_001f5810(KwlnTask *);
void func_001f58f0(u8 *);
void func_001f5950(void);
void func_001f59b0(void);
void *func_001f5b20(void);
void func_001f64c0(void);
u32 func_001f65e0(void);
void func_001f6630(void);
void brRewardAdvanceState(void);
void brRewardAnimateCurrentEntry(void);
void brRewardRegisterEntry(const f32 *);
void func_001f7030(void);
void func_001f70d0(void);
void func_001f7170(void);
void func_001f7210(void);
#pragma alias func_001f2300_update func_001f2300
extern void *func_001f2300_update(KwlnTask *);
#pragma alias func_001f2fd0_destroy func_001f2fd0
extern void func_001f2fd0_destroy(KwlnTask *);
void *func_001f2f50(KwlnTask *);
void *func_001f2f80(KwlnTask *);
void func_001f2fd0(KwlnTask *);
void func_001f2ff0(KwlnTask *);
u32 func_001f30b0(KwlnTask *);
void *func_001f2300(KwlnTask *);

static void brCopyWords(u8 *dst, const u8 *src, u32 count)
{
    u32 i;
    for (i = 0; i < count; i++) {
        dst[i] = src[i];
    }
}

static u32 brRootFlags(void)
{
    return sBrRoot != NULL ? BR_U32(sBrRoot, 0) : 0;
}

static u32 brCardFlags(void)
{
    return sBrCard != NULL ? BR_U32(sBrCard, 4) : 0;
}

static u32 brRewardFlags(void)
{
    return sBrReward != NULL ? BR_U32(sBrReward, 0) : 0;
}








typedef struct BrRootSetupParams {
    u32 flags;
    struct {
        u16 id;
        u16 pad;
        u32 value;
    } entries[3];
    u32 entryCount;
    u32 field20;
    u16 partyIds[4];
    u32 partyCount;
    u32 field30;
    u32 field34;
    u32 field38;
    u32 field3c;
    u32 field40;
} BrRootSetupParams;













/* Retail 0x1f13f0-0x1f1a64: level-up propagation, hero/party EXP, and
 * newly learned-skill collection. */






















/* Retail 0x1f3270-0x1f4648: reconstructed result-card selection and reward dispatch. */
// FUN_001f3270 NONMATCHING
void func_001f3270(KwlnTask *task)
{
    typedef struct {
        s16 id;
        s16 weight;
    } BrResultSlot;
    typedef struct {
        u32 kind;
        u32 high;
        u32 low;
    } BrResultEntry;
    typedef struct {
        u32 limit;
        u32 total;
        u32 next;
        u32 action;
        s16 candidates[256];
        BrResultSlot slots[6];
        u32 flags[5];
        BrResultEntry entries[8];
        s16 cardIds[5];
        u32 check;
        u16 checkId;
    } BrResultScratch;
    u8 *work = BR_TASK_WORK(task);
    BrResultScratch local;
    u8 *table0;
    u8 *table1;
    u8 *table2;
    u8 *table3;
    u8 *cardTable;
    u8 *rangeTable;
    u8 *selected;
    u8 *ranges;
    u8 *entry;
    u8 *reward;
    u8 *cardRecord;
    u16 candidateCount;
    u32 i;
    u32 j;
    u32 mode;
    u32 resultFlags;
    u32 selectedCount;
    u32 slotCount;
    u32 slotLimit;
    u32 entryCount;
    u32 randomValue;
    u32 value;
    u32 value2;
    s16 currentLevel;
    s16 baseLevel;
    s16 threshold;
    s16 lower;
    s16 upper;
    s16 best;
    s16 level;
    s32 sum;
    s32 selectedIndex;
    s32 start;
    s32 end;
    s32 span;
    s32 choice;
    s32 numEntries;
    s32 reservedEntries;
    s32 maxSelected;
    s16 card;

    /* Retail 0x1f32a0-0x1f32d4: data-table setup. */
    table0 = (u8 *)func_00209e10();
    table1 = (u8 *)func_00209e20();
    table2 = (u8 *)func_00209e60();
    table3 = (u8 *)func_00209e70();
    func_00209dd0();

    /* Retail 0x1f32d8-0x1f33b0: level-to-card threshold. */
    candidateCount = 0;
    currentLevel = (s32)(s16)(datGetLevel(1) & 0xff);
    baseLevel = currentLevel;
    if (datGetScenarioMode() != 0) {
        if (currentLevel >= 0x19 && currentLevel < 0x23) {
            threshold = ((s16 *)D_006846CE)[currentLevel] + 1;
        } else {
            threshold = currentLevel - 5;
        }
    } else if (currentLevel > 0 && currentLevel < 10) {
        threshold = ((s16 *)D_006846DE)[currentLevel] + 1;
    } else {
        threshold = currentLevel - 5;
    }

    /* Retail 0x1f33b0-0x1f34d0: scan the 256-card table. */
    best = -1;
    upper = 100;
    value = BR_U32(work, 4) & 0x200;
    if (value != 0) {
        local.limit = 20;
    } else if ((s16)BR_U32(work, 0x58) < 50) {
        local.limit = 10;
    } else {
        local.limit = 15;
    }
    currentLevel = (s32)(s16)BR_U32(work, 0x58);
    lower = currentLevel - (s32)local.limit;
    for (i = 0; i < 0x100; i++) {
        cardRecord = (u8 *)(*(u32 *)&D_00696950) + i * 0xe;
        if ((*(u16 *)cardRecord & 0xdb) != 0) {
            continue;
        }
        level = (s32)(s8)BR_U8(cardRecord, 3);
        if (currentLevel < level || level < lower) {
            continue;
        }
        if (baseLevel < level && level < upper) {
            best = (s32)i;
            upper = level;
        }
        if (level < threshold) {
            local.candidates[candidateCount] = (s16)i;
            candidateCount++;
        }
    }

    /* Retail 0x1f34d4-0x1f3538: rare insertion of the nearest card. */
    if (best != -1 && value == 0 && RpRandom() % 100 < 10) {
        if (candidateCount >= 0x100) {
            K_Assert(D_00684620, 0x4af);
        }
        local.candidates[0] = (s16)best;
        candidateCount = 1;
    }

    /* Retail 0x1f353c-0x1f35d0: initialize the five visible slots. */
    if (candidateCount > 0) {
        for (i = 0; i < 5; i++) {
            local.slots[i].id =
                local.candidates[RpRandom() % candidateCount];
            local.slots[i].weight = 0x14;
        }
    } else {
        for (i = 0; i < 5; i++) {
            local.slots[i].id = -1;
            local.slots[i].weight = 0;
        }
    }
    BR_U32(work, 0x18) = 0;
    cardTable = (u8 *)func_00209dc0();
    rangeTable = (u8 *)func_00209dd0();
    entry = (u8 *)(*(u32 *)&D_00696948) +
            BR_U32(work, 0xc0fc) * 0x1c;
    if (BR_U32(entry, 0x18) == 0) {
        K_Assert(D_00684620, 0x4cf);
    }
    selected = cardTable + BR_U32(entry, 0x18) * 10;
    ranges = table1 + BR_U16(selected, 8) * 8;

    /* Retail 0x1f3668-0x1f36e0: select the result mode. */
    value = BR_U32(work, 0);
    if (value == 2) {
        mode = 2;
    } else if (value == 1) {
        mode = BR_U32(work, 0xe4) != 0 ? 2 : 1;
    } else if (value == 0) {
        mode = BR_U32(work, 0xe4) != 0 ? 1 : 0;
    } else {
        K_Assert(D_00684620, 0x5f2);
        mode = value;
    }

    /* Retail 0x1f36e0-0x1f3bf0: choose cards and mark special flags. */
    resultFlags = 0;
    selectedCount = 0;
    if (mode == 0) {
        local.flags[0] = 0;
        local.cardIds[0] = 0x2e;
        selectedCount = 1;
        resultFlags |= 1;
    } else if (mode == 1) {
        local.flags[0] = 0;
        local.cardIds[0] = 0x2e;
        local.flags[1] = 0;
        local.cardIds[1] = 0xe;
        selectedCount = 2;
        resultFlags |= 3;
    } else {
        randomValue = RpRandom() % 100;
        if (randomValue < BR_U8(selected, 1)) {
            resultFlags |= 1;
        }
        if ((resultFlags & 1) != 0) {
            randomValue = RpRandom() % 100;
            if (randomValue < BR_U8(selected, 2)) {
                resultFlags |= 2;
            }
        }
        if (func_0016f190(0xc60) == 0 &&
            func_0016f190(0x1423) == 0) {
            randomValue = RpRandom() % 100;
            value = BR_U8(selected, 3);
            if (func_0016f190(0x1319) != 0) {
                f32 chance = (f32)(s32)(s8)value;
                chance = chance + chance;
                value = (u32)chance;
            }
            if (randomValue < (value & 0xffff)) {
                resultFlags |= 4;
            }
        }
        if (BR_U32(work, 0xe4) != 0) {
            slotLimit = (BR_U32(work, 4) & 0x2000) != 0 ? 4 : 5;
        } else {
            slotLimit = 0;
            if ((resultFlags & 1) != 0) {
                slotLimit++;
            }
            if ((resultFlags & 2) != 0) {
                slotLimit++;
            }
        }
        slotCount = 0;
        for (i = 0; i < 6; i++) {
            if (local.slots[i].id == -1) {
                break;
            }
            slotCount++;
        }
        sum = 0;
        for (i = 0; i < slotCount; i++) {
            sum += local.slots[i].weight;
        }
        local.total = 0;
        if (sum > 0) {
            while (local.total < slotLimit) {
                randomValue = RpRandom() % (u32)sum;
                value = 0;
                selectedIndex = 0;
                while (selectedIndex < (s32)slotCount) {
                    value += local.slots[selectedIndex].weight;
                    if (randomValue < value) {
                        break;
                    }
                    selectedIndex++;
                }
                if (selectedIndex >= (s32)slotCount) {
                    K_Assert(D_00684620, 0x59d);
                }
                local.check = 0;
                card = local.slots[selectedIndex].id;
                local.checkId = (u16)card;
                if (func_001f9680((s32 *)&local.check) == 0) {
                    if (selectedCount >= 5) {
                        K_Assert(D_00684620, 0x5ad);
                    }
                    local.flags[selectedCount] = 0;
                    local.cardIds[selectedCount] = card;
                    selectedCount++;
                }
                local.total++;
            }
        }
        if ((BR_U32(work, 4) & 0x2000) != 0) {
            value = 0;
            for (i = 0; i < 5; i++) {
                u8 *r = rangeTable + i * 4;
                if (BR_U32(work, 0x54) >= r[0] &&
                    BR_U32(work, 0x54) <= r[1]) {
                    value++;
                }
            }
            if (value != 0) {
                randomValue = RpRandom() % value;
                selectedIndex = 0;
                for (i = 0; i < 5; i++) {
                    u8 *r = rangeTable + i * 4;
                    if (BR_U32(work, 0x54) >= r[0] &&
                        BR_U32(work, 0x54) <= r[1]) {
                        if (randomValue == (u32)selectedIndex) {
                            break;
                        }
                        selectedIndex++;
                    }
                }
                if ((u32)selectedIndex >= value) {
                    K_Assert(D_00684620, 0x5d8);
                }
                local.check = 0;
                local.checkId = BR_U16(rangeTable, selectedIndex * 4 + 2);
                if (func_001f9680((s32 *)&local.check) == 0) {
                    if (selectedCount >= 5) {
                        K_Assert(D_00684620, 0x5e3);
                    }
                    local.flags[selectedCount] = 2;
                    local.cardIds[selectedCount] = local.checkId;
                    selectedCount++;
                }
            }
        }
    }

    /* Retail 0x1f3c10-0x1f3d08: reject cards above the current level. */
    for (i = 0; i < selectedCount; i++) {
        cardRecord = (u8 *)(*(u32 *)&D_00696950) +
                     (u32)local.cardIds[i] * 0xe;
        if ((datGetLevel(1) & 0xff) < BR_U8(cardRecord, 3)) {
            local.flags[i] |= 1;
        }
    }
    for (i = 0; i < selectedCount; i++) {
        if ((local.flags[i] & 1) == 0) {
            resultFlags |= 0x10;
        }
    }
    if ((resultFlags & 0x10) != 0) {
        slotLimit = 0;
    } else if ((resultFlags & 4) != 0) {
        slotLimit = 1;
    } else if (BR_U32(work, 0xe4) != 0) {
        slotLimit = 2;
    } else {
        slotLimit = 3;
    }

    /* Retail 0x1f3d0c-0x1f3efc: weighted reward/action selection. */
    value = BR_U16(selected, 6) - 1;
    if ((s32)value < 0) {
        K_Assert(D_00684620, 0x616);
    }
    local.action = *(u8 *)(table3 + slotLimit * 10 + value - 1);
    BR_U32(work, 0x1fd50) = local.action;
    reward = table0 + local.action * 0x14;
    sum = 0;
    for (i = 0; i < 6; i++) {
        sum += *(u8 *)(reward + i * 2 + 3);
    }
    if (sum == 0) {
        K_Assert(D_00684620, 0x627);
    }
    randomValue = RpRandom() % (u32)sum;
    value = 0;
    for (i = 0; i < 6; i++) {
        value += *(u8 *)(reward + i * 2 + 3);
        if (randomValue < value) {
            break;
        }
    }
    if (i >= 6) {
        K_Assert(D_00684620, 0x631);
    }
    BR_U32(work, 0x1fd54) = *(u8 *)(reward + i * 2 + 2);
    sum = 0;
    for (i = 0; i < 3; i++) {
        sum += *(u8 *)(reward + i * 2 + 0xf);
    }
    if (sum == 0) {
        K_Assert(D_00684620, 0x63c);
    }
    randomValue = RpRandom() % (u32)sum;
    value = 0;
    for (i = 0; i < 3; i++) {
        value += *(u8 *)(reward + i * 2 + 0xf);
        if (randomValue < value) {
            break;
        }
    }
    if (i >= 3) {
        K_Assert(D_00684620, 0x646);
    }
    BR_U32(work, 0x1fd58) = *(u8 *)(reward + i * 2 + 0xe);

    /* Retail 0x1f3f08-0x1f3fe8: choose the number of result entries. */
    if (mode == 0) {
        numEntries = 4;
    } else if (mode == 1) {
        numEntries = 2;
    } else {
        start = BR_U8(reward, 0);
        end = BR_U8(reward, 1);
        if (start == end) {
            numEntries = start;
        } else {
            numEntries = start + RpRandom() % (u32)(end - start + 1);
        }
    }
    printf(D_00684718, numEntries);
    if (numEntries >= 7) {
        K_Assert(D_00684620, 0x66b);
    }
    reservedEntries = (s32)BR_U32(work, 0xe4);
    if (numEntries - 1 < reservedEntries) {
        reservedEntries = numEntries - 1;
    }
    maxSelected = numEntries - reservedEntries;
    if (maxSelected < (s32)selectedCount) {
        selectedCount = maxSelected;
    }

    /* Retail 0x1f3fec-0x1f4368: fill each result entry. */
    local.next = 0;
    for (i = 0; i < (u32)numEntries; i++) {
        BrResultEntry *out = &local.entries[i];
        u32 done = 0;
        if ((s32)i < reservedEntries) {
            printf(D_00684730);
            out->kind = 2;
            done = 1;
        } else if (local.next < selectedCount) {
            for (j = local.next; j < selectedCount; j++) {
                local.check = 0;
                local.checkId = (u16)local.cardIds[j];
                if (func_001f9680((s32 *)&local.check) == 0) {
                    printf(D_00684750);
                    out->kind = 0;
                    out->high = local.checkId;
                    local.next = j + 1;
                    done = 1;
                    break;
                }
            }
        }
        if (!done) {
            printf(D_00684770);
            out->kind = 1;
            for (;;) {
            choice = RpRandom() & 3;
            printf(D_00684788, choice);
            switch (choice) {
            case 0:
                start = ranges[0];
                end = ranges[1];
                break;
            case 1:
                start = ranges[6];
                end = ranges[7];
                break;
            case 2:
                start = ranges[2];
                end = ranges[3];
                break;
            default:
                start = ranges[4];
                end = ranges[5];
                break;
            }
            if (start == end) {
                value2 = (u32)start;
            } else {
                span = end + 1 - start;
                printf((const char *)(*(u32 *)((u8 *)0 + 0x696ff0)), span);
                if (span >= 5) {
                    K_Assert(D_00684620, 0x6c4);
                }
                sum = 0;
                for (j = 0; j < (u32)span; j++) {
                    value = *(u8 *)(table2 + span * 4 - 8 + j);
                    sum += (s8)value;
                    printf((const char *)(*(u32 *)((u8 *)0 + 0x696ff8)),
                           (s8)value);
                }
                printf((const char *)(*(u32 *)((u8 *)0 + 0x696ffc)));
                randomValue = RpRandom() % (u32)sum;
                printf((const char *)(*(u32 *)((u8 *)0 + 0x69700)),
                       randomValue);
                value = 0;
                for (j = 0; j < (u32)span; j++) {
                    value += (s8)*(u8 *)(table2 + span * 4 - 8 + j);
                    if (randomValue < value) {
                        break;
                    }
                }
                printf((const char *)(*(u32 *)((u8 *)0 + 0x69708)), j);
                if (j >= (u32)span) {
                    K_Assert(D_00684620, 0x6da);
                }
                value2 = (u32)(start + j);
            }
            if (choice == 3 && func_001f9170((s32)value2) == 0) {
                choice = RpRandom() % 3;
                if (choice == 3) {
                    choice++;
                }
                continue;
            }
            out->high = (u32)choice;
            out->low = value2;
                break;
            }
        }
    }

    /* Retail 0x1f436c-0x1f4494: ensure a non-random entry or repair it. */
    for (i = 0; i < (u32)numEntries; i++) {
        if (local.entries[i].kind == 1) {
            break;
        }
    }
    if (i == (u32)numEntries) {
        value = local.entries[0].high;
        value2 = local.entries[0].low;
        for (j = 0; j < (u32)numEntries; j++) {
            if (local.entries[j].high == value &&
                local.entries[j].low == value2) {
                break;
            }
        }
        if (j == (u32)numEntries) {
            BrResultEntry *out =
                &local.entries[RpRandom() % (u32)numEntries];
            switch (value) {
            case 0:
                out->high = 2;
                break;
            case 1:
                out->high = 0;
                break;
            case 2:
            case 3:
                out->high = 1;
                break;
            }
        }
    }

    /* Retail 0x1f4494-0x1f4508: apply selected card effects. */
    for (i = 0; i < selectedCount; i++) {
        void *cardPtr = sflCard002537f0((u16)local.cardIds[i]);
        value = local.flags[i];
        if ((value & 1) != 0) {
            sflCard00255170(cardPtr);
        } else if ((value & 2) != 0) {
            func_002551b0(cardPtr);
        }
    }
    if (BR_U32(work, 0xe4) == 0) {
        sflResRequestBaseArchive();
    }

    /* Retail 0x1f4520-0x1f4604: create the generated result cards. */
    for (i = 0; i < (u32)numEntries; i++) {
        BrResultEntry *out = &local.entries[i];
        if (out->kind == 1) {
            value = sflCard002536b0(out->high, out->low);
            if ((resultFlags & 4) != 0) {
                if ((resultFlags & 8) == 0) {
                    sflCard00255190((void *)value);
                    resultFlags |= 8;
                } else if (RpRandom() % 100 < BR_U8(selected, 4)) {
                    sflCard00255190((void *)value);
                }
            }
        } else if (out->kind == 2) {
            sflCard00253920();
        }
    }
    func_00254e10();
    BR_U32(work, 8) = 1;
}

// FUN_001f4650
void func_001f4650(KwlnTask *task, const u8 *params)
{
    u8 *work;
    DatPersonaWork *persona;
    s32 count;
    s32 i;
    u32 code;

    work = BR_TASK_WORK(task);
    BR_U32(work, 0x58) = BR_U32(params, 0x0c);
    BR_U32(work, 0x54) = BR_U32(params, 0x10);
    BR_U32(work, 0xc0fc) = BR_U32(params, 4);
    code = BR_U32(params, 4);
    if (code == 0x1d5) goto code_1d5;
    switch (code) {
    case 0x1d4: goto code_1d4;
    default: goto code_other;
    }

code_1d4:
    BR_U32(work, 0) = 0;
    goto done;

code_1d5:
    count = func_001756f0() & 0xffff;
    for (i = 0; i < count; i++) {
        persona = datPersonaGetHeroPersona((s16)i);
        if (persona->id == 0x2e) break;
    }
    if (i == count) {
        BR_U32(work, 0) = 1;
        goto done;
    }
    BR_U32(work, 0) = 2;
    goto done;

code_other:
    BR_U32(work, 0) = 2;

done:
    return;
}

// FUN_001f4750
void func_001f4750(KwlnTask *task)
{
    struct BrCard {
        u32 flags;
        u32 kind;
        u16 id;
        u16 pad;
        u32 value;
    };
    u32 *work = (u32 *)task->workData;
    struct BrCard *card = (struct BrCard *)func_00256030();

    switch (card->kind) {
    case 0:
        if (sflCard002561c0(card) != 0) {
            func_003c7430(2);
            func_0010a4e0(1, 15, 6, 11);
        } else {
            func_003c7bc0(0, func_00173220(card->id));
            if (func_001f5760(card->id) != 0) {
                func_003c7430(3);
            } else {
                func_003c7430(1);
            }
        }
        break;
    case 1:
        func_003c7c20(0, card->value, 0);
        func_003c7bc0(1, D_00684610[BR_U32(card, 8)]);
        func_003c7430(0);
        break;
    case 2:
        func_003c7430(4);
        func_0010a4e0(1, 15, 6, 11);
        break;
    }
    work[1] |= 0x40;
    work[2] = 0x11;
}

// FUN_001f48d0
void func_001f48d0(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    sflResRequestGroundArchive();
    BR_U32(work, 4) |= 0x80;
}

// FUN_001f4910
u32 func_001f4910(KwlnTask *task)
{
    return BR_U32(BR_TASK_WORK(task), 4) & 0x80;
}

// FUN_001f4930
void func_001f4930(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    func_0023c280();
    BR_U32(work, 4) |= 0x100;
}

// FUN_001f4970
u32 func_001f4970(KwlnTask *task)
{
    return BR_U32(BR_TASK_WORK(task), 4) & 0x100;
}

// FUN_001f4990
u32 func_001f4990(void)
{
    K_ASSERT(sBrCard != NULL, 0xfe);
    if (BR_U32(sBrCard, 0x10000 - 0x3f04) != 0x1d4) {
        return 0;
    }
    return BR_U32(sBrCard, 0xe4) == 0;
}

// FUN_001f4a00 NONMATCHING
void func_001f4a00(void)
{
    u8 *work = sBrCard;
    DatPersonaWork *persona;
    const u8 *actTable;
    const u8 *valueTable;
    u32 i;
    s32 count;
    s32 selected;
    s32 active;
    s32 groups;
    s32 lastGroup;
    u32 enabled[4];
    u32 weightTable[8];
    s32 groupSize[4];
    f32 progress;
    f32 maxProgress;
    f32 ratio0;
    f32 ratio1;
    f32 ratio2;
    u32 random;

    if (work == NULL) {
        K_Assert("sfl_root.c", 0xfe);
    }
    work = sBrCard;
    func_00209e10();
    valueTable = (const u8 *)func_00209e80();
    actTable = (const u8 *)func_00209e90();
    BR_U32(work, 4) |= 0x20;
    persona = datPersonaGetByPcId(1);
    func_00173660(persona, 4);
    datPersonaGetLevel(persona);
    sflScriptConfigureCommandBuffer((u32)(work + 0x1e990), 0x400);
    printf(D_006847A0);
    printf(D_00696964);
    sflScriptQueueWaitCommand(10);
    count = (s32)func_00255130();
    printf(D_006847D0, count);
    printf(D_00696964);

    valueTable += BR_U32(work, 0x1fd54) * 6;
    actTable += BR_U32(work, 0x1fd58) * 3;
    ratio0 = (f32)(u32)valueTable[0];
    ratio1 = (f32)(u32)valueTable[1];
    ratio2 = (f32)(u32)valueTable[2];
    maxProgress = ratio0 + ratio1 + ratio2;
    ratio0 = (f32)(u32)valueTable[0] / maxProgress;
    ratio1 = (f32)(u32)valueTable[2] / maxProgress;
    ratio2 = (f32)(u32)valueTable[1] / maxProgress;
    printf(D_00696950, valueTable[1], valueTable[0]);
    printf(D_006847E0, (s32)func_00530da0(ratio0));
    printf(D_006847F0, (s32)func_00530da0(ratio1));
    printf(D_00684800, (s32)func_00530da0(ratio2));
    printf(D_00696964);
    printf(D_00696948);
    printf(D_006847E0, (s32)func_00530da0(1.0f));
    printf(D_006847F0, (s32)func_00530da0(1.0f));
    printf(D_00684800, (s32)func_00530da0(3.0f));
    printf(D_00696964);
    printf(D_00684810,
           (s32)func_00530da0(ratio0 * ratio1 + ratio2 * ratio0));
    printf(D_00684820, actTable[2]);

    maxProgress = (f32)(u32)actTable[2] +
                  (f32)(RpRandom() % 1);
    weightTable[0] = actTable[0];
    weightTable[1] = actTable[2];
    weightTable[2] = actTable[2];
    weightTable[3] = actTable[1];
    if (actTable[0] == 0 && actTable[2] != 0) {
        weightTable[0] = 1;
    }
    weightTable[7] = 0;

    groups = 0;
    lastGroup = 0;
    if (maxProgress < 1.0f) {
        K_Assert("sfl_root.c", 0x871);
    }
    printf(D_00684830, (s32)func_00530da0(maxProgress - 0.5f));
    progress = 0.0f;
    while (progress <= maxProgress - 0.5f) {
        u32 totalWeight;
        u32 choiceWeight;

        sflScriptQueueSetCardValueCommand((u16)((f32)(s32)actTable[0] +
                                               progress * ((f32)(s32)actTable[1] -
                                                           (f32)(s32)actTable[0]) / maxProgress));
        for (i = 0; i < 4; i++) {
            enabled[i] = 0;
        }
        enabled[0] = 1;
        enabled[3] = 1;
        if (count >= 3) {
            enabled[1] = 1;
        }
        if (groups != 0 && lastGroup == 0) {
            enabled[2] = 1;
        }
        totalWeight = 0;
        for (i = 0; i < 4; i++) {
            if (enabled[i] != 0) {
                totalWeight += weightTable[i];
            }
        }
        if (totalWeight == 0) {
            K_Assert("sfl_root.c", 0x88b);
        }
        random = RpRandom() % totalWeight;
        selected = 0;
        for (i = 0; i < 4; i++) {
            if (enabled[i] != 0) {
                selected = (s32)i;
                random -= weightTable[i];
                if ((s32)random < 0) {
                    break;
                }
            }
        }

        if (selected == 0) {
            lastGroup = 0;
            random = RpRandom() % (u32)count;
            active = (s32)(RpRandom() % (u32)(count - 1));
            if ((u32)active >= random) {
                selected = active + 1;
            } else {
                selected = random;
                random = (u32)active;
            }
            func_002599c0(random, (u32)selected);
            progress += 1.0f;
            printf(D_00684840, (s32)func_00530da0(progress));
        } else if (selected == 1) {
            lastGroup = 1;
            active = (s32)(RpRandom() % (u32)(count - 2)) + 2;
            func_00259a60(RpRandom() % (u32)((count - active) + 1), active);
            progress += 1.0f;
            printf(D_00684840, (s32)func_00530da0(progress));
            groupSize[groups] = active;
            groups++;
            count -= active - 1;
        } else if (selected == 2) {
            sflScriptQueueOpenCommand(0);
            printf(D_00684840, (s32)func_00530da0(progress));
            groups--;
            count += groupSize[groups] - 1;
        }
        if (selected == 0 || selected == 1 || selected == 2) {
            sflScriptQueueStartActionsCommand();
            sflScriptQueueWaitForActionsCommand();
        }
        if (selected == 3) {
            sflScriptQueueShuffleCommand();
            progress += 3.0f;
            printf(D_00684840, (s32)func_00530da0(progress));
        }
    }
    for (i = 0; i < groups; i++) {
        sflScriptQueueOpenCommand(0);
        sflScriptQueueStartActionsCommand();
        sflScriptQueueWaitForActionsCommand();
    }
    sflScriptQueueEndCommand();
    func_00257f10();
    func_0010a4e0(1, 0, 6, 1);
    BR_U32(work, 8) = 7;
}

// FUN_001f53a0
void func_001f53a0(void)
{
    u8 *work;
    u32 state;
    K_ASSERT(sBrCard != NULL, 0xfe);
    work = sBrCard;
    state = BR_U32(work, 8);
check_state:
    switch (state) {
    case 21:
    case 17:
        goto state_17_or_21;
    case 24:
        goto state_24;
    default:
        goto invalid_state;
    }

state_17_or_21:
    if ((BR_U32(work, 4) & 0x1000) == 0) goto repeat_as_24;
    func_001f54a0();
    goto done;

repeat_as_24:
    state = 24;
    goto check_state;

state_24:
    K_ASSERT(sBrCard != NULL, 0xfe);
    work = sBrCard;
    func_001f59b0();
    BR_U32(work, 8) = 22;
    goto done;

invalid_state:
    K_ASSERT(false, 0x943);
    goto check_state;

done:
    return;
}

// FUN_001f54a0
void func_001f54a0(void)
{
    u32 *work;
    K_ASSERT(sBrCard != NULL, 0xfe);
    work = (u32 *)sBrCard;
    func_003c7430(0x32);
    func_0010a4e0(1, 15, 6, 12);
    work[2] = 24;
}

// FUN_001f5510
void func_001f5510(void)
{
    u8* work;
    u16 ids[14];
    s32 count;
    s32 i;

    K_ASSERT(sBrCard != NULL, 0xfe);
    work = sBrCard;
    if ((BR_U32(work, 4) & 0x1000) != 0) {
        datSetFlag(0x1411, 1);
    }
    sflResult001f9770(ids, &count);
    for (i = 0; i < count; i++) {
        func_00174b40(ids[i]);
    }
    BR_U32(work, 8) = 0;
    BR_U32(work, 4) &= ~1u;
}

// FUN_001f55e0
void func_001f55e0(void)
{
    u32 *work;
    K_ASSERT(sBrCard != NULL, 0xfe);
    work = (u32 *)sBrCard;
    func_00255f80();
    func_0025a7d0();
    sflPanel0023f3e0();
    func_0025b4f0();
    work[2] = 11;
}

// FUN_001f5650
void func_001f5650(void)
{
    u32 *work;
    K_ASSERT(sBrCard != NULL, 0xfe);
    work = (u32 *)sBrCard;
    sflCard00259310();
    work[2] = 25;
}

// FUN_001f56b0
void func_001f56b0(void)
{
    u32 current = func_0016f380(0x39);
    u32 limit = func_0016f380(0x38);
    if (current == limit) {
        current = 24;
        current += RpRandom() % 5;
        func_0016f3e0(0x39, 0);
        func_0016f3e0(0x38, current);
    } else {
        func_0016f3e0(0x39, func_0016f380(0x39) + 1);
    }
}

// FUN_001f5760
u32 func_001f5760(u16 personaId)
{
    s32 i;
    s32 count = func_001756f0() & 0xffff;
    u32 target;
    i = 0;
    target = personaId & 0xffff;
    for (; i < count; i++) {
        DatPersonaWork *p = datPersonaGetHeroPersona((s16)i);
        K_ASSERT(p != NULL, 0x99c);
        if (target == p->id) {
            break;
        }
    }
    return i < count;
}

// FUN_001f5810
u32 func_001f5810(KwlnTask* task)
{
    u8* card;
    u32 result;

    K_ASSERT(sBrCard != NULL, 0xfe);
    card = sBrCard;
    if ((BR_U32(BR_TASK_WORK(task), 4) & 0x80) != 0) {
        result = 0;
    } else if (BR_U32(card, 8) == 1) {
        result = 0;
    } else {
        if (sflResIsBaseArchivePending() != 0) goto resources_busy;
        if (func_00254f20() != 0) goto resources_busy;
        if (sflResIsEffectArchivePending() != 0) goto resources_busy;
        if (sflResIsPersonaChangeSpritePending() == 0) goto resources_ready;

resources_busy:
        result = 0;
        goto resources_done;

resources_ready:
        result = 1;

resources_done:
        ;
    }
    return result;
}






/* Retail reconstruction spans 0x001f6630-0x001f6a5c: reward reset, card setup, and two indexed animation passes. */







