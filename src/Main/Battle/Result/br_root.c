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

// FUN_001f08c0
void *func_001f08c0(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    if ((BR_U32(work, 0) & 0x400000) != 0) {
        func_002350f0();
    }
    return KWLNTASK_CONTINUE;
}

// FUN_001f0900
void *func_001f0900(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    u32 flags = ~BR_U32(work, 0);
    if ((flags & 0x400000) != 0) {
        func_002350f0();
    }
    return KWLNTASK_CONTINUE;
}

// FUN_001f0940
void *func_001f0940(KwlnTask *task)
{
    (void)task;
    func_00278550();
    func_00275cb0();
    return KWLNTASK_CONTINUE;
}

// FUN_001f0970
void func_001f0970(KwlnTask *task)
{
    func_001f0990(task);
}

// FUN_001f0990
void func_001f0990(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    if ((BR_U32(work, 0) & 4) == 0) {
        if ((BR_U32(work, 0) & 8) == 0) {
            if ((BR_U32(work, 0) & 0x20) == 0) {
                goto br_cleanup_done;
            }
        }
    }
    func_003c77a0();
br_cleanup_done:
    brPersonaShutdown();
    brHero00262730();
    func_00234960();
    brRes00233e70();
    func_00272380();
    func_00275a80();
    func_00276920();
    func_00276d30();
    if ((BR_U32(work, 0) & 0x8000) != 0) {
        func_001f30d0((KwlnTask *)BR_U32(work, 0x94));
    }
    BR_FREE(task->workData);
}

// FUN_001f0a60
void func_001f0a60(KwlnTask *task)
{
    u32 *work = (u32 *)BR_TASK_WORK(task);
    func_001f30d0((KwlnTask *)work[0x25]);
    work[0] &= ~0x8000u;
    work[0x25] = 0;
}

// FUN_001F0AB0
void func_001f0ab0(KwlnTask *task)
{
    task = (KwlnTask *)task->workData;
    BR_U32(task, 0x28) = 0;
    BR_U32(task, 0xc) = 7;
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

// FUN_001f0ad0 NONMATCHING
void func_001f0ad0(KwlnTask *task, const BrRootSetupParams *params)
{
    u32 *work;
    s32 i;
    s32 j;

    work = (u32 *)BR_TASK_WORK(task);
    if ((params->flags & 1) != 0) {
        work[0] |= 2;
    }
    work[0xb0 / 4] = params->entryCount;
    for (i = 0; i < (s32)params->entryCount; i++) {
        const u8 *entry = (const u8 *)params + i * 8;
        u8 *dst = (u8 *)work + i * 8;
        BR_U16(dst, 0x98) = BR_U16(entry, 4);
        BR_U32(dst, 0x9c) = BR_U32(entry, 8);
    }
    work[0xb4 / 4] = params->field20;
    work[0x118 / 4] = params->partyCount;
    work[0x11c / 4] = params->field30;
    printf(D_006845c0, work[0x118 / 4]);
    printf(D_006845d0, work[0x11c / 4]);
    work[0x114 / 4] = 0;
    for (j = 0; j < (s32)params->partyCount; j++) {
        u16 id = params->partyIds[j];
        if (id == 1) {
            continue;
        }
        BR_U16((u8 *)work + work[0x114 / 4] * 2, 0x10c) = id;
        work[0x114 / 4] = work[0x114 / 4] + 1;
    }
    work[0x2a58 / 4] = params->field3c;
    work[0x12c / 4] = params->field34;
    work[0x130 / 4] = params->field38;
    work[0x124 / 4] = params->field3c;
    work[0x128 / 4] = params->field40;
    work[0x120 / 4] = 0;
    if ((params->flags & 2) != 0) {
        work[0x120 / 4] |= 1;
    }
}
// FUN_001f0c40 NONMATCHING
void func_001f0c40(KwlnTask *task)
{
    u8 *entry;
    u8 *work;
    s32 i;
    s32 j;
    work = task->workData;
    for (i = 0; i < (s32)BR_U32(work, 0xb0); i++) {
        entry = work + i * 8 + 0x98;
        if (dat00171360(BR_U16(entry, 0)) != 0) {
            func_00171390(BR_U16(entry, 0));
        } else {
            u8 *base = work + i * 8;
            s32 level = (s32)(func_00170760(1, BR_S16(entry, 0)) & 0xffff);
            level += BR_S32(base, 0x9c);
            if (level >= 100) {
                level = 99;
            }
            func_00170860(1, BR_S16(entry, 0), (u16)level);
        }
    }
    for (j = 0; j < (s32)BR_U32(work, 0x108); j++) {
        func_00174e20(BR_U16(work + j * 2, 0xf0));
    }
    BR_U32(work, 0) &= ~1u;
    BR_SET_STATE(work, 13);
}


// FUN_001f0d70
void func_001f0d70(KwlnTask *task)
{
    u8 *work;
    u32 state;

    work = BR_TASK_WORK(task);
    state = BR_U32(work, 0x0c);
    for (;;) {
        switch (state) {
        case 7:
            if ((BR_U32(work, 0) & 4) != 0) {
                brRoot001f1e90(task);
                return;
            }
            state = 9;
            break;
        case 9:
            if ((BR_U32(work, 0) & 8) != 0) {
                func_001f0f40(task);
                return;
            }
            state = 8;
            break;
        case 8:
            if ((BR_U32(work, 0) & 0x20) != 0) {
                func_001f1140(task);
                return;
            }
            state = 12;
            break;
        case 12:
            func_001f0c40(task);
            return;
        default:
            K_ASSERT(0, 0x582);
            break;
        }
    }
}

// FUN_001f0eb0
void func_001f0eb0(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    s32 i;
    DatPersonaWork *persona = datPersonaGetByPcId(6);
    for (i = 0; i < BR_S32(work, 0x150); i++) {
        datPersonaSetSkill(persona, BR_U16(work + i * 2, 0x140));
    }
    BR_U32(work, 0) &= ~0x400000u;
}

// FUN_001f0f40
void func_001f0f40(KwlnTask *task)
{
    u32 *work = (u32 *)BR_TASK_WORK(task);
    if ((~work[2] & 4) != 0) {
        K_ASSERT((~work[1] & 4) != 0, 0x59f);
        brRes00233b20();
        work[1] |= 4;
        work[4] = 0;
    } else {
        func_001f0ff0();
    }
    work[3] = 8;
}

// FUN_001f0fd0
void func_001f0fd0(KwlnTask *task)
{
    (void)task;
    brHero002630e0();
}

// FUN_001f0ff0
void func_001f0ff0(void)
{
    u8 *work = brRoot001f1c50();
    u32 level = datGetLevel(1);
    func_003c7c20(0, level, 0);
    func_003c7430(2);
    func_002362e0();
    BR_U32(work, 0) &= ~0x200000u;
    BR_U32(work, 0) &= ~0x80000u;
    func_00262790();
    func_00275a90();
    BR_U32(work, 0) |= 0x100000;
    func_0010a370(3, "battle result");
    BR_U32(work, 0x10) = 1;
}

// FUN_001f10b0
void func_001f10b0(void)
{
    u8 *work = brRoot001f1c50();
    func_003c7430(3);
    BR_U32(work, 0x10) = 2;
}

// FUN_001f10f0
void func_001f10f0(void)
{
    u8 *work = brRoot001f1c50();
    H_Fade_FadeOut();
    H_Fade_SetType(2);
    BR_U32(work, 0x10) = 4;
}

// FUN_001f1140
void func_001f1140(KwlnTask *task)
{
    volatile /* Removing this function's qualifier batch loses func_001f1140 (MATCH nd0 -> MISMATCH nd46, size 200 -> 188) - measured W170. */ u32 *work = (volatile /* Removing this function's qualifier batch loses func_001f1140 (MATCH nd0 -> MISMATCH nd46, size 200 -> 188) - measured W170. */ u32 *)BR_TASK_WORK(task);
    if ((~work[2] & 4) != 0) {
        K_ASSERT((~work[1] & 4) != 0, 0x5e5);
        brRes00233b20();
        work[1] |= 4;
        work[5] = 0;
    } else {
        u32 index = (work[0xc4 / 4] = 0);
        u32 addr = index * 2;
        addr = addr + (u32)work + 0xd4;
        func_003c7bc0(0, func_00173220(*(u16 *)addr));
        func_003c7430(1);
        work[5] = 1;
    }
    work[3] = 12;
}

// FUN_001f1210
void *func_001f1210(void)
{
    brPersonaDestroy();
    return (void *)func_003c7650(1);
}

// FUN_001f1240
void func_001f1240(KwlnTask *task)
{
    u32 *work = (u32 *)BR_TASK_WORK(task);
    f32 ratio;

    K_ASSERT((~work[0] & 0x20000) != 0, 0x603);
    if (((~work[0]) & 2) != 0) {
        ratio = (f32)(s32)work[0xb4 / 4] / (f32)(s32)work[0x11c / 4];
    } else {
        ratio = ((f32)(s32)work[0xb4 / 4] * (f32)(s32)work[0x2a5c / 4] / 100.0f) /
                (f32)(s32)work[0x11c / 4];
    }
    if (ratio == 0.0f) {
        work[0xb8 / 4] = 0;
    } else if (ratio < 1.0f) {
        work[0xb8 / 4] = 1;
    } else {
        work[0xb8 / 4] = (s32)ratio;
    }
    work[0x2a54 / 4] = work[0x130 / 4];
    work[0x2a50 / 4] = func_001fbdf0((u8)datGetLevel(1), work[0x2a54 / 4],
                                     work[0xb8 / 4], work[0x2a58 / 4],
                                     work[0x11c / 4]);
    func_001f13b0(task);
    work[0] |= 0x20000;
}

/* Retail 0x1f13f0-0x1f1a64: level-up propagation, hero/party EXP, and
 * newly learned-skill collection. */
// FUN_001f13b0 NONMATCHING
void func_001f13b0(KwlnTask *task)
{
    s32 *work = (s32 *)BR_TASK_WORK(task);
    s32 oldLevel;
    s32 newLevel;
    s32 heroCount;
    s32 i;
    s32 heroId;
    DatPersonaWork *persona;
    u16 *skills;
    s32 skillCount;
    s32 skill;
    s32 firstIndex;
    s32 indexCount;
    s32 j;
    s32 learnedCount;
    u8 *entry;
    u8 *current;

    /* Retail +0x24..+0x94: apply the hero's pending EXP before deriving
     * the resulting level, then print the level transition. */
    oldLevel = datGetLevel(1);
    work[0xbc / 4] = oldLevel;
    datDidCharacterLevelUp(1, work[0x2a50 / 4]);
    newLevel = func_0016d280(datGetNextExp(1));
    datSetLevel(1, newLevel);
    work[0xc0 / 4] = datGetLevel(1);
    printf(D_006845f0, work[0xbc / 4], work[0xc0 / 4]);
    if (work[0xbc / 4] != work[0xc0 / 4]) {
        work[0] |= 8;
        if (work[0xc0 / 4] > 0 && !datGetFlag(0x120c)) {
            datSetFlag(0x120c, 1);
            work[0] |= 0x40000;
        }
        if (work[0xc0 / 4] >= 10 && !datGetFlag(0x120d)) {
            datSetFlag(0x120d, 1);
            work[0] |= 0x40000;
        }
        if (work[0xc0 / 4] >= 20 && !datGetFlag(0x1201)) {
            datSetFlag(0x1201, 1);
            work[0] |= 0x40000;
        }
        if (work[0xc0 / 4] >= 30 && !datGetFlag(0x1202)) {
            datSetFlag(0x1202, 1);
            work[0] |= 0x40000;
        }
    }

    /* Retail +0x1c8..+0x3d0: walk every hero Persona.  The three skill
     * IDs are separate retail call sites, not one merged fallback call. */
    work[0xec / 4] = 0;
    heroId = datPersonaGetByPcId(1)->id;
    heroCount = func_001756f0() & 0xffff;
    for (i = 0; i < heroCount; i++) {
        persona = datPersonaGetHeroPersona((s16)i);
        K_ASSERT(persona != NULL, 0x665);
        if (persona->id == heroId) {
            datPersonaAddExp(persona, (s32)func_001fbdf0(
                (u32)persona->level, work[0x2a54 / 4],
                work[0xb8 / 4], work[0x2a58 / 4],
                work[0x11c / 4]));
        } else {
            skills = datPersonaGetSkills(persona);
            skillCount = datPersonaCountValidSkills(persona);
            skill = 0;
            while (skill < skillCount) {
                if (skills[skill] == 0x22b) {
                    break;
                }
                skill++;
            }
            if (skill < skillCount) {
                datPersonaAddExp(persona, (s32)func_001fbfa0(
                    (u32)persona->level, work[0x2a54 / 4],
                    work[0xb8 / 4], 0x22b,
                    work[0x2a58 / 4], work[0x11c / 4]));
            } else {
                skill = 0;
                while (skill < skillCount) {
                    if (skills[skill] == 0x22a) {
                        break;
                    }
                    skill++;
                }
                if (skill < skillCount) {
                    datPersonaAddExp(persona, (s32)func_001fbfa0(
                        (u32)persona->level, work[0x2a54 / 4],
                        work[0xb8 / 4], 0x22a,
                        work[0x2a58 / 4], work[0x11c / 4]));
                } else {
                    skill = 0;
                    while (skill < skillCount) {
                        if (skills[skill] == 0x229) {
                            break;
                        }
                        skill++;
                    }
                    if (skill < skillCount) {
                        datPersonaAddExp(persona, (s32)func_001fbfa0(
                            (u32)persona->level, work[0x2a54 / 4],
                            work[0xb8 / 4], 0x229,
                            work[0x2a58 / 4], work[0x11c / 4]));
                    }
                }
            }
        }
    }

    /* Retail +0x3e0..+0x464: collect Personas that learned skills. */
    learnedCount = 0;
    for (i = 0; i < heroCount; i++) {
        persona = datPersonaGetHeroPersona((s16)i);
        K_ASSERT(persona != NULL, 0x6ac);
        if (func_001761b0(persona) != 0) {
            BR_U16((u8 *)work + learnedCount * 2, 0xd4) = persona->id;
            learnedCount++;
        }
    }
    work[0xec / 4] = learnedCount;
    if (learnedCount != 0) {
        work[0] |= 0x20;
    }

    /* Retail +0x494..+0x4d8: update each non-hero party member's result. */
    for (i = 0; i < work[0x114 / 4]; i++) {
        u8 *pcEntry = (u8 *)work + 0x10c + i * 2;
        s16 pc = *(s16 *)pcEntry;
        func_001f9e90(*(u16 *)pcEntry,
                       func_001fbdf0(datGetLevel(pc), work[0x2a54 / 4],
                                     work[0xb8 / 4], work[0x2a58 / 4],
                                     work[0x11c / 4]));
    }

    /* Retail +0x4e0..+0x640: process the optional sixth Persona's
     * learned-skill table and copy type-1 entries into the result. */
    if (datGetFlag(0x140)) {
        persona = datPersonaGetByPcId(6);
        K_ASSERT(persona != NULL, 0x6c9);
        datPersonaAddExp(persona, (s32)func_001fbdf0(
            datGetLevel(6), work[0x2a54 / 4], work[0xb8 / 4],
            work[0x2a58 / 4], work[0x11c / 4]));
        if (func_001761b0(persona) != 0) {
            func_00175ce0(persona, (u16 *)((u8 *)work + 0x158));
            entry = DAT_007ce430 + (persona->id - 0xc0) * 0x26e + 4;
            func_001fb4b0(entry, 0x20, persona->level,
                          BR_U8((u8 *)work, 0x158), &firstIndex, &indexCount);
            work[0x150 / 4] = 0;
            current = entry + firstIndex * 4;
            for (j = 0; j < indexCount; j++, current += 4) {
                if (current[1] == 1) {
                    BR_U16((u8 *)work + work[0x150 / 4] * 2, 0x140) =
                        BR_U16(current, 2);
                    work[0x150 / 4]++;
                }
            }
            func_00176100(persona, (u16 *)((u8 *)work + 0x158));
            if (work[0x150 / 4] != 0) {
                work[0] |= 4;
            }
        }
    }

    if (work[0xec / 4] != 0) {
        work[(0x10000 - 0x5980) / 4] = 3;
    } else if ((work[0] & 8) != 0) {
        work[(0x10000 - 0x5980) / 4] = 2;
    } else if ((work[0] & 4) != 0) {
        work[(0x10000 - 0x5980) / 4] = 1;
    } else {
        work[(0x10000 - 0x5980) / 4] = 0;
    }
}

// FUN_001f1aa0
void *func_001f1aa0(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    sflResult001f9800((u16 *)(work + 0xf0), (s32 *)(work + 0x108));
    BR_U32(work, 0x2a5c) = sflResult001f9890();
}

// FUN_001f1ae0
KwlnTask *func_001f1ae0(KwlnTask *parent)
{
    return (KwlnTask *)func_001ef500(parent);
}

// FUN_001f1b00
u32 func_001f1b00(KwlnTask *task)
{
    return BR_U32(BR_TASK_WORK(task), 0) & 1;
}

// FUN_001f1b20
void func_001f1b20(KwlnTask *task)
{
    BR_U32(BR_TASK_WORK(task), 0) |= 0x2000;
}

// FUN_001f1b40
u32 func_001f1b40(KwlnTask *task)
{
    return BR_U32(BR_TASK_WORK(task), 0) & 0x2000;
}

// FUN_001f1b60
void brRoot001f1b60(KwlnTask* task)
{
    u8* root;
    u8* work;

    root = BR_TASK_WORK(task);
    K_ASSERT(BR_U32(root, 0x0c) == 2, 0x51e);
    if ((BR_U32(root, 0) & 2) != 0) {
        work = BR_TASK_WORK(task);
        func_001f30f0((KwlnTask*)BR_U32(work, 0x94));
        brRes002339d0();
        BR_U32(work, 0) |= 0x8000;
        BR_U32(work, 0x0c) = 3;
    } else {
        work = BR_TASK_WORK(task);
        BR_U32(work, 0x28) = 0;
        BR_U32(work, 0x0c) = 7;
    }
    BR_U32(root, 0) |= 0x40;
    BR_U32(root, 0) |= 1;
}

// FUN_001f1c20
void func_001f1c20(KwlnTask *task)
{
    sBrRoot = NULL;
    kwlnTaskDestroyWithHierarchy(task);
}

#pragma opt_propagation off
// FUN_001f1c50
u8 *brRoot001f1c50(void)
{
    K_ASSERT(sBrRoot != NULL, 0x755);
    return sBrRoot;
}

// FUN_001f1c90 NONMATCHING
void func_001f1c90(KwlnTask *task)
{
    void *work = task->workData;
    u32 params[12];
    s32 i;

    func_001f1240(task);
    BR_U32(params, 0) = 0;
    if (BR_U32(work, 0x2a5c) >= 0x65) {
        BR_U32(params, 0) |= 1;
    }
    if (BR_U32(work, 0xb0) != 0) {
        BR_U32(params, 0) |= 2;
    }
    BR_U32(params, 0x2c) = BR_U32(work, 0x2a50);
    BR_U32(params, 0x28) = BR_U32(work, 0xb0);
    for (i = 0; i < (s32)BR_U32(work, 0xb0); i++) {
        u8 *entry = (u8 *)work + i * 8 + 0x98;
        ((u32 *)params)[i * 3 + 1] = dat00171360(BR_U16(entry, 0)) != 0;
        ((u16 *)params)[i * 6 + 4] = BR_U16(entry, 0);
        ((u32 *)params)[i * 3 + 3] = BR_U32(entry, 4);
    }
    if ((BR_U32(work, 0) & 2) == 0 && (BR_U32(work, 0) & 8) != 0) {
        brRes00233c00();
    }
    brPanel00234a00((u32 *)params);
    brPanel00236280();
    BR_U32(work, 0) |= 0x200000;
}

#pragma opt_propagation reset
// FUN_001f1df0
void brRoot001f1df0(u16 *outIds, s32 *count)
{
    s32 i;
    u8 *root;
    u16 *dst;
    K_ASSERT(sBrRoot != NULL, 0x755);
    root = sBrRoot;
    outIds[0] = 1;
    for (i = 0; i < BR_S32(root, 0x114); i++) {
        dst = outIds + i;
        dst[1] = BR_U16(root + i * 2, 0x10c);
    }
    *count = BR_S32(root, 0x114) + 1;
}

// FUN_001f1e90
void brRoot001f1e90(KwlnTask *task)
{
    u32 *work = (u32 *)BR_TASK_WORK(task);
    K_ASSERT((~work[1] & 4) != 0, 0x79c);
    K_ASSERT((~work[2] & 4) != 0, 0x79d);
    brRes00233b20();
    work[0] |= 0x400000;
    work[1] |= 4;
    work[14] = 0;
    work[3] = 9;
}

// FUN_001f1f40
u32 func_001f1f40(void)
{
    u8 *work;
    u32 value;
    u32 condition;

    K_ASSERT(sBrRoot != NULL, 0x755);
    work = sBrRoot;
    K_ASSERT(work != NULL, 0x755);
    {
        u32 *root;
        root = (u32 *)sBrRoot;
        if ((root[0] & 0x8000) == 0) {
            condition = 0;
        } else if (root[0x25] == 0) {
            condition = 0;
        } else {
            condition = 1;
        }
    }
    if (condition == 1) {
        K_ASSERT(sBrRoot != NULL, 0x755);
        {
            u32 *root = (u32 *)sBrRoot;
            if ((root[0] & 0x8000) == 0) {
                value = 1;
            } else if (root[0x25] == 0) {
                value = 1;
            } else {
                value = func_001f5810((KwlnTask *)root[0x25]);
            }
        }
        return value == 1;
    }
    if ((BR_U32(work, 0) & 0x20000) != 0) {
        u32 bits = BR_U32(work, 0) & 0x2c;
        return (bits != 0) ^ 1;
    }
    return 0;
}

// FUN_001f2080 NONMATCHING
KwlnTask *func_001f2080(const u8 *params)
{
    u8 *work = (u8 *)BR_ALLOC2(0x2a220, 0x40000);
    KwlnTask *task;
    KwlnTask *child;
    RwV2d viewWindow;
    sBrCard = work;
    BR_U32(work, 4) = 0;
    BR_U32(work, 0x14) = 0;
    task = kwlnTaskCreateWithAutoPriority(NULL, 10, "battle result card",
                                          func_001f2300_update, func_001f2fd0_destroy, work);
    child = kwlnTaskInitEx("battle result ground", 0x106f, 1, 2,
                           func_001f2f50, NULL, work);
    BR_U32(work, 0x0c) = (u32)child;
    kwlnTaskAddChild(task, child);
    child = kwlnTaskInitEx("battle result draw", 0x18a6, 1, 2,
                           func_001f2f80, NULL, work);
    BR_U32(work, 0x10) = (u32)child;
    kwlnTaskAddChild(task, child);
    viewWindow.x = 1.0f;
    viewWindow.y = 0.5f;
    RwCameraSetViewWindow((RwCamera *)kwlnGetMainCamera(), &viewWindow);
    BR_U32(work, 4) |= 3;
    func_00219c90(work + 0x95c0);
    sflResInit((SflResourceManager *)(work + 0x60));
    func_00239170(work + 0xf0);
    func_0023d7a0(work + 0x8e90);
    func_0023d7f0();
    func_0024da00(work + 0xbd04);
    sflCamera0024d110(work + 0xbcf0);
    func_002534d0(work + 0xc100);
    sflScriptInit((SflScriptWork*)(work + 0xbf10));
    sflCursor0025a110(work + 0x1ed90);
    func_001f58f0(work + 0x1fd60);
    func_00215a50(work + 0x23280);
    func_00260970(work + 0x29320);
    sflCount0025b4a0(work + 0x29bf0);
    sflPersonaInit(work + 0x2a200);
    BR_U32(work, 0xe4) = 0;
    func_001f4650(task, params);
    BR_U32(work, 8) = 0;
    func_001f3270(task);
    BR_U32(work, 0x2a210) = 0;
    return task;
}

// FUN_001f2300 NONMATCHING
void *func_001f2300(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    u32 temp;
    if ((BR_U32(work, 4) & 0x80) != 0 && sflResIsGroundArchivePending() == 0) {
        BR_U32(work, 4) &= ~0x80u;
    }
    if ((BR_U32(work, 4) & 0x100) != 0 && sflGround0023c350() == 0) {
        BR_U32(work, 4) &= ~0x100u;
    }
    func_00219d90();
    sflResUpdate();
    func_00215fc0();
    func_001f5b20();
    switch (BR_U32(work, 8)) {
    case 1:
        if (sflResIsBaseArchivePending() == 0 && func_00254f20() == 0 && BR_U32(work, 0x2a210) != 0) {
            func_00254f70();
            if (BR_U32(work, 0xe4) == 0) {
                func_003c72d0((void *)sflResGetBaseSpriteData());
                func_0023d130();
                sflResRequestEffectArchive();
                sflResRequestPersonaChangeSprite();
            }
            func_0023ee50();
            sflCard00259250();
            BR_U32(work, 8) = 2;
        }
        break;
    case 2:
        if (sflGround0023d1f0() == 0 && sflCard002592c0() == 0) {
            BR_U32(work, 8) = func_001f4990() ? 4 : 3;
        }
        break;
    case 3:
        if ((BR_U32(work, 4) & 2) == 0) {
            u16 v;
            sflResRequestTutorialArchive();
            v = *(u16*)0x007E094E;
            if ((v & 0x9ff) != 0 || (*(u16*)0x007E094C & 0x10) != 0) {
                func_001f4a00();
            }
        }
        break;
    case 7:
        if (sflCard002582b0() == 0) {
            sflScriptStartQueuedCommands();
            BR_U32(work, 0x1fd5c) = 0;
            BR_U32(work, 8) = 8;
        }
        break;
    case 8:
        temp = BR_U32(work, 0x1fd5c);
        if (temp < 15) {
            BR_U32(work, 0x1fd5c) = temp + 1;
        }
        if (BR_U32(work, 0x1fd5c) == 15 &&
            ((*(u16*)0x007E094E & 0x40) != 0 ||
             (*(u16*)0x007E094C & 0x10) != 0)) {
            func_00258a50();
            BR_U32(work, 8) = 9;
        } else {
            func_00259740();
            if (func_002596f0() == 0) {
                BR_U32(work, 0x14) = 0;
                BR_U32(work, 8) = 10;
            }
        }
        break;
    case 10:
        if ((s32)BR_U32(work, 0x14) >= 0) {
            func_001f55e0();
        } else {
            BR_U32(work, 0x14)++;
        }
        break;
    case 9:
        if (sflCard00258af0() == 0) {
            func_001f55e0();
        }
        break;
    case 11:
    {
        u8 *card;
        u32 randomValue;
        u32 chance;
        u32 ready;

        if (sflCount0025b640() != 0 &&
            (*(u16 *)0x007E094E & 0x40) == 0 &&
            (*(u16 *)0x007E094C & 0x10) == 0) {
            break;
        }
        sflCount0025b5f0();
        sflCursor0025aa70();
        func_001f56b0();
        sflCard00258490();
        card = func_00256030();
        func_0023f430();
        func_003c7650(0);
        BR_U32(work, 4) &= ~0x20u;
        if (BR_U32(work, 0xe4) < 7 && func_0016f190(0x1318) != 0) {
            randomValue = func_00488f30() % 100;
            chance = ((const u8 *)0x007CC378)[BR_U32(work, 0xe4)];
            func_005225a8((const char *)0x00684680, (s32)randomValue, (s32)chance);
            if (randomValue < ((const u8 *)0x007CC378)[BR_U32(work, 0xe4)]) {
                BR_U32(work, 4) |= 0x200;
            }
        }
        if (BR_U32(card, 4) != 2) {
            BR_U32(work, 4) &= ~0x200u;
        }
        if (func_002561d0(card) == 0) {
            BR_U32(work, 4) &= ~0x200u;
        }
        if (BR_U32(card, 4) == 0 && func_002561c0(card) == 0) {
            BR_U32(work, 4) &= ~0x200u;
        }
        ready = 0;
        if ((BR_U32(work, 4) & 0x200) == 0) {
            randomValue = func_00488f30() % 100;
            switch (BR_U32(card, 4)) {
            case 0:
                if (func_002561c0(card) != 0 && randomValue < 3) {
                    ready = 1;
                }
                break;
            case 1:
                if (func_002561d0(card) != 0 && randomValue < 10) {
                    ready = 1;
                }
                break;
            case 2:
                if (randomValue < 10) {
                    ready = 1;
                }
                break;
            }
        }
        func_0010a4e0(1, 0, 6, 1);
        if (ready != 0) {
            BR_U32(work, 8) = 13;
            sflCard00258090();
        } else {
            func_001f4750(task);
            sflCard002580e0();
        }
        break;
    }
    case 13:
        if (sflResIsEffectArchivePending() == 0) {
            func_0010a4e0(1, 15, 6, 13);
            func_0023f1d0();
            func_0023cda0();
            func_003c7430(5);
            func_003c74e0();
            BR_U32(work, 8) = 0x0e;
        }
        break;
    case 17:
    {
        u8 *card;

        if (sflPanel0023f390() == 0 && sflGround0023d0e0() == 0) {
            if ((BR_U32(work, 4) & 0x200) != 0) {
                func_003c7990(1);
                if (func_003c7850() == 0) {
                    func_003c7650(1);
                }
            } else {
                func_003c7990(0);
                if (func_003c7850() == 0) {
                    func_003c7650(0);
                }
            }
            if ((BR_U32(work, 4) & 0x40) != 0) {
                BR_U32(work, 4) &= ~0x40u;
            } else {
                card = func_00256030();
                temp = BR_U32(card, 4);
                switch (temp) {
                case 0:
                    if (func_002561c0(card) == 0 &&
                        func_001f5760(*(u16 *)(card + 8)) == 0) {
                        brRewardRegisterEntry((const f32 *)&card[4]);
                    }
                    break;
                case 1:
                    brRewardRegisterEntry((const f32 *)&card[4]);
                    break;
                case 2:
                    func_001f9630();
                    break;
                }
                if (func_002561d0(card) != 0) {
                    BR_U32(work, 4) |= 0x1000u;
                }
                if ((BR_U32(work, 4) & 0x200) != 0) {
                    BR_U32(work, 8) = 0x12;
                } else {
                    func_00255fe0();
                    func_001f53a0();
                }
            }
        }
        break;
    }
    case 18:
        if (sflResIsEffectArchivePending() == 0) {
            func_0023f010();
            func_0010a4e0(1, 2, 6, 13);
            if (BR_U32(work, 0xe4) == 0) {
                func_0023ca10();
            }
            BR_U32(work, 8) = 0x13;
        }
        break;
    case 19:
        if (sflPanel0023f390() == 0 && func_0023cd50() == 0) {
            if (func_0016f190(0x1416) == 0) {
                func_003c7430(7);
                func_0016f1f0(0x1416, 1);
            } else {
                func_003c7430(6);
            }
            func_003c74e0();
            BR_U32(work, 8) = 0x14;
        }
        break;
    case 20:
        func_003c7990(0);
        if (func_003c7850() == 0) {
            BR_U32(work, 8) = 0x15;
        }
        break;
    case 21:
        func_003c7650(1);
        temp = func_003c7610();
        if (temp == 1) {
            func_001f53a0();
        } else if (temp == 0) {
            func_001f5650();
        }
        break;
    case 25:
        if (sflCard00259380() == 0) {
            BR_U32(work, 0xe4)++;
            func_00255fe0();
            func_002550b0();
            func_00258300();
            func_001f3270(task);
        }
        break;
    case 14:
        func_003c7990(0);
        if (func_003c7850() == 0) {
            BR_U32(work, 8) = 0x0f;
        }
        break;
    case 15:
        if (func_003c78d0() == 0) {
            func_003c7650(0);
            printf((const char *)0x006846A0);
            temp = func_003c7610();
            if (temp == 1) {
                func_001f4750(task);
            } else if (temp == 0) {
                func_002594c0();
                BR_U32(work, 8) = 0x10;
            }
        }
        break;
    case 16:
        if (sflCard002595c0() == 0) {
            func_001f4750(task);
        }
        break;
    case 22:
        if (func_001f65e0() == 0) {
            BR_U32(work, 8) = 0x17;
        }
        break;
    case 23:
        if (sflResIsEffectArchivePending() == 0) {
            func_001f5510();
        }
        break;
    case 4:
        if (sflResIsTutorialArchivePending() == 0) {
            func_003c77a0();
            func_003c72d0((void *)sflResGetTutorialFileUnchecked());
            func_003c7430(0);
            BR_U32(work, 8) = 5;
        }
        break;
    case 5:
        func_003c7990(1);
        if (func_003c7850() == 0) {
            func_003c7650(1);
            func_003c77a0();
            func_003c94e0((void *)sflResGetTutorialFileUnchecked());
            func_003c9790(0);
            BR_U32(work, 8) = 6;
        }
        break;
    case 6:
        func_003c7990(1);
        if (func_003c7850() == 0) {
            func_003c7650(1);
            func_003c77a0();
            sflResDestroyTutorialFiles();
            func_003c72d0((void *)sflResGetBaseSpriteData());
            BR_U32(work, 8) = 3;
        }
        break;
    case 24:
        func_003c7990(0);
        if (func_003c7850() == 0) {
            func_003c7650(0);
            func_001f53a0();
        }
        break;
    case 0:
    case 12:
    default:
        break;
    }
    func_0025b690();
    func_0025a130();
    func_0023d8f0();
    func_0024db90();
    func_0024dc10();
    sflCamera0024d1c0();
    func_00253a40();
    func_002392d0();
    sflPersonaUpdate();
    BR_U32(work, 4) &= ~3u;
    return KWLNTASK_CONTINUE;
}

// FUN_001f2f50
void *func_001f2f50(KwlnTask *task)
{
    (void)task;
    func_0023b990();
    return KWLNTASK_CONTINUE;
}

// FUN_001f2f80
void *func_001f2f80(KwlnTask *task)
{
    func_00254b90();
    func_0025bbf0();
    func_0025a440();
    func_001f64c0();
    func_002168f0();
    func_0023e970();
    return KWLNTASK_CONTINUE;
}

// FUN_001f2fd0
void func_001f2fd0(KwlnTask *task)
{
    func_001f2ff0(task);
}

// FUN_001f2ff0
void func_001f2ff0(KwlnTask *task)
{
    sflPersonaShutdown(task);
    sflCount0025b4b0();
    func_001f5950();
    func_00215aa0();
    sflPsel00260a10();
    func_0025a120();
    func_00259630();
    sflCard00253560();
    sflCamera0024d160();
    func_0024da20();
    sflPanel0023d870();
    func_0023d7b0();
    sflGround00239280();
    func_0021a1b0();
    sflResShutdown();
    func_003c77a0();
    BR_FREE(task->workData);
    sBrCard = NULL;
}

// FUN_001f30b0
u32 func_001f30b0(KwlnTask *task)
{
    return BR_U32(BR_TASK_WORK(task), 4) & 1;
}

// FUN_001f30d0
void func_001f30d0(KwlnTask *task)
{
    kwlnTaskDestroyWithHierarchy(task);
}

// FUN_001f30f0
void func_001f30f0(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    u32 rect[3];

    func_004c9d70(kwlnGetMainCamera(), 1.0f);
    func_0021a840();
    BR_U32(work, 0xe4) = 0;
    rect[0] = 0;
    rect[1] = 0x42c80000;
    rect[2] = 0;
    func_0024fd10(work + 0xc034);
    func_0024f9f0(work + 0xc034, (const float *)rect);
    func_0024da60(work + 0xc034);
    func_0024f090(work + 0xc034);
    rect[0] = 0;
    rect[1] = 0x42c80000;
    rect[2] = 0x43480000;
    func_0024fd10(work + 0xc098);
    func_0024f9f0(work + 0xc098, (const float *)rect);
    func_0024da60(work + 0xc098);
    func_0024f090(work + 0xc098);
    func_0024d8d0(work + 0xbf28);
    sflCamera0024d2e0(0, work + 0xbf28);
    sflCamera0024d940(work + 0xbf28, work + 0xc034);
    sflCamera0024d9a0(work + 0xbf28, work + 0xc098);
    sflCamera0024d280(kwlnGetMainCamera());
    func_0024d4c0(0);
    BR_U32(work, 0x2a210) = 1;
}

/* Retail 0x1f3270-0x1f4648: reconstructed result-card selection and reward dispatch. */






















/* Retail reconstruction spans 0x001f6630-0x001f6a5c: reward reset, card setup, and two indexed animation passes. */

#pragma alias brRewardAdvanceState func_001f6a60

#pragma alias brRewardRegisterEntry func_001f6d20

#pragma alias brRewardAnimateCurrentEntry func_001f6e80




