#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Result/br_panel.h"
#include "Main/Battle/Result/br_res.h"
#include "Main/Social/sfl_res.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"
#include "h_fade.h"
#include "rw/rwcore.h"
#include "rw/rprandom.h"

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
#define BR_ALLOC2(n, f) (*(void *(*)(u32, u32))jtbl_00960178)((n), (f))
#define BR_FREE(p) (*(void (**)(void *))jtbl_0096017C)((p))

static u8 *sBrRoot;       /* GP-relative -0x4a18 */
static u8 *sBrCard;       /* GP-relative -0x4a14 */
static u8 *sBrReward;     /* GP-relative -0x4a10 */

extern u32 jtbl_00960178[];
extern u32 jtbl_0096017C[];

/* Result-resource and data helpers not yet described by public headers. */
extern s32 printf(const char *, ...);
 
extern void func_002350f0(void);
extern void func_00278550(void);
extern void func_00275cb0(void);
extern void func_003c77a0(void);
extern void brPersona00264dd0(void);
extern void brPersona00264f90(void);
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
extern u8 func_0016d280(s32);
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
extern void func_0027bb50(void *);
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
extern void func_0027be50(void);

extern void func_0023b990(void);
extern void func_00254b90(void);
extern void func_0025bbf0(void);
extern void func_0025a440(void);
extern void func_001f64c0(void);
extern void func_002168f0(void);
extern void func_0023e970(void);
extern void func_0027bba0(void *);
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
extern void func_0020d630(void *, const f32 *);
extern void func_0020d690(void *, const f32 *);
extern void func_004bdde0(f32, f32 *, const f32 *, u32);
extern void func_0020ac90(void *);
extern void *func_0020e790(void);
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
extern void func_0020e200(void);
extern u32 func_001f9170(s32);
extern void func_00173660(DatPersonaWork *, s32);
extern u32 func_0021a120(void);
extern void func_00258300(void);
extern void func_002550b0(void);
extern void *func_0034fcd0(void *);
extern u16 datGetMaxHp(s16);
extern void *func_0020e710(s32);
extern u16 func_00170760(s16, s16);
extern void func_00170860(s16, s16, u16);
extern void datSetMoney(u32);
extern void func_001828d0(s16, void *, void *);
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
extern void func_0020d650(void *, const float *);
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
extern void func_0020e8f0(void);
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
void *func_001f13b0(KwlnTask *);
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
void func_001f6a60(void);
void func_001f6e80(void);
void func_001f6d20(const f32 *);
void func_001f7030(void);
void func_001f70d0(void);
void func_001f7170(void);
void func_001f7210(void);
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
    brPersona00264dd0();
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
    volatile u32 *work = (volatile u32 *)BR_TASK_WORK(task);
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

// FUN_001f0ad0 NONMATCHING
#pragma optimization_level 3
void func_001f0ad0(KwlnTask *task, const u8 *params)
{
    u8 *work;
    s32 i;
    s32 j;

    work = BR_TASK_WORK(task);
    if ((BR_U32(params, 0) & 1) != 0) {
        BR_U32(work, 0) |= 2;
    }
    BR_U32(work, 0xb0) = BR_U32(params, 0x1c);
    for (i = 0; i < (s32)BR_U32(params, 0x1c); i++) {
        BR_U16(work + i * 8, 0x98) = BR_U16(params + i * 8, 4);
        BR_U32(work + i * 8, 0x9c) = BR_U32(params + i * 8, 8);
    }
    BR_U32(work, 0xb4) = BR_U32(params, 0x20);
    BR_U32(work, 0x118) = BR_U32(params, 0x2c);
    BR_U32(work, 0x11c) = BR_U32(params, 0x30);
    printf((const char *)0x006845c0, BR_U32(work, 0x118));
    printf((const char *)0x006845d0, BR_U32(work, 0x11c));
    BR_U32(work, 0x114) = 0;
    for (j = 0; j < (s32)BR_U32(params, 0x2c); j++) {
        u16 id = BR_U16(params + j * 2, 0x24);
        if (id == 1) {
            continue;
        }
        BR_U16(work, 0x10c + BR_U32(work, 0x114) * 2) = id;
        BR_U32(work, 0x114) = BR_U32(work, 0x114) + 1;
    }
    BR_U32(work, 0x2a58) = BR_U32(params, 0x3c);
    BR_U32(work, 0x12c) = BR_U32(params, 0x34);
    BR_U32(work, 0x130) = BR_U32(params, 0x38);
    BR_U32(work, 0x124) = BR_U32(params, 0x3c);
    BR_U32(work, 0x128) = BR_U32(params, 0x40);
    BR_U32(work, 0x120) = 0;
    if ((BR_U32(params, 0) & 2) != 0) {
        BR_U32(work, 0x120) |= 1;
    }
}
#pragma optimization_level 2
// FUN_001f0c40 NONMATCHING
void func_001f0c40(KwlnTask *task)
{
    u8 *work;
    s32 i;
    s32 j;
    u8 *entry;
    work = task->workData;

    for (i = 0; i < (s32)BR_U32(work, 0xb0); i++) {
        entry = (u8 *)work + i * 8;
        if (dat00171360(BR_U16(entry, 0x98)) != 0) {
            func_00171390(BR_U16(entry, 0x98));
        } else {
            s32 level = (s32)(func_00170760(1, BR_S16(entry, 0x98)) & 0xffff);
            level += BR_S32(entry, 0x9c);
            if (level >= 100) {
                level = 99;
            }
            func_00170860(1, BR_S16(entry, 0x98), (u16)level);
        }
    }
    for (j = 0; j < (s32)BR_U32(work, 0x108); j++) {
        func_00174e20(BR_U16(work, 0xf0 + j * 2));
    }
    BR_U32(work, 0) &= ~2u;
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
    volatile u32 *work = (volatile u32 *)BR_TASK_WORK(task);
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
    volatile u32 *work = (volatile u32 *)BR_TASK_WORK(task);
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
    brPersona00264f90();
    return (void *)func_003c7650(1);
}

// FUN_001f1240 NONMATCHING
#pragma optimization_level 3
void func_001f1240(KwlnTask *task)
{
    u32 *work = (u32 *)BR_TASK_WORK(task);
    f32 ratio;

    K_ASSERT((BR_U32(work, 0) & 0x20000) == 0, 0x603);
    if ((BR_U32(work, 0) & 2) == 0) {
        ratio = (f32)BR_S32(work, 0xb4) / (f32)BR_S32(work, 0x11c);
    } else {
        ratio = ((f32)BR_S32(work, 0xb4) * (f32)BR_S32(work, 0x2a5c) / 100.0f) /
                (f32)BR_S32(work, 0x11c);
    }
    if (ratio == 0.0f) {
        BR_U32(work, 0xb8) = 0;
    } else if (ratio < 1.0f) {
        BR_U32(work, 0xb8) = 1;
    } else {
        BR_U32(work, 0xb8) = (s32)ratio;
    }
    BR_U32(work, 0x2a54) = BR_U32(work, 0x130);
    BR_U32(work, 0x2a50) = func_001fbdf0((u8)datGetLevel(1), BR_U32(work, 0x2a54),
                                         BR_U32(work, 0xb8), BR_U32(work, 0x2a58),
                                         BR_U32(work, 0x11c));
    func_001f13b0(task);
    BR_U32(work, 0) |= 0x20000;
}
#pragma optimization_level 2

/* Retail 0x1f13f0-0x1f1a64: level-up propagation, hero/party EXP, and
 * newly learned-skill collection. */
// FUN_001f13b0 NONMATCHING
#pragma optimization_level 3
void *func_001f13b0(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    u32 oldLevel;
    u32 newLevel;
    u32 heroCount;
    u32 i;
    u16 heroId;
    DatPersonaWork *persona;
    u16 *skills;
    u32 skillCount;
    u32 skill;
    s32 firstIndex;
    s32 indexCount;
    s32 j;
    u8 *entry;
    u8 *current;

    /* Retail +0x24..+0x94: apply the hero's pending EXP before deriving
     * the resulting level, then print the level transition. */
    oldLevel = datGetLevel(1);
    BR_U32(work, 0xbc) = oldLevel;
    datDidCharacterLevelUp(1, BR_U32(work, 0x2a50));
    newLevel = func_0016d280(datGetNextExp(1));
    datSetLevel(1, newLevel);
    BR_U32(work, 0xc0) = datGetLevel(1);
    printf((const char *)0x006845f0, BR_U32(work, 0xbc), BR_U32(work, 0xc0));
    if (BR_U32(work, 0xbc) != BR_U32(work, 0xc0)) {
        BR_U32(work, 0) |= 8;
        if (BR_U32(work, 0xc0) > 0 && !datGetFlag(0x120c)) {
            datSetFlag(0x120c, 1);
            BR_U32(work, 0) |= 0x40000;
        }
        if (BR_U32(work, 0xc0) >= 10 && !datGetFlag(0x120d)) {
            datSetFlag(0x120d, 1);
            BR_U32(work, 0) |= 0x40000;
        }
        if (BR_U32(work, 0xc0) >= 20 && !datGetFlag(0x1201)) {
            datSetFlag(0x1201, 1);
            BR_U32(work, 0) |= 0x40000;
        }
        if (BR_U32(work, 0xc0) >= 30 && !datGetFlag(0x1202)) {
            datSetFlag(0x1202, 1);
            BR_U32(work, 0) |= 0x40000;
        }
    }

    /* Retail +0x1c8..+0x3d0: walk every hero Persona.  The three skill
     * IDs are separate retail call sites, not one merged fallback call. */
    BR_U32(work, 0xec) = 0;
    heroId = datPersonaGetByPcId(1)->id;
    heroCount = func_001756f0();
    for (i = 0; i < heroCount; i++) {
        persona = datPersonaGetHeroPersona((s16)i);
        K_ASSERT(persona != NULL, 0x665);
        if (persona->id == heroId) {
            datPersonaAddExp(persona, (s32)func_001fbdf0(
                (u32)persona->level, BR_U32(work, 0x2a54),
                BR_U32(work, 0xb8), BR_U32(work, 0x2a58),
                BR_U32(work, 0x11c)));
        } else {
            skills = datPersonaGetSkills(persona);
            skillCount = datPersonaCountValidSkills(persona);
            skill = 0;
            while (skill < skillCount && skills[skill] != 0x22b) {
                skill++;
            }
            if (skill < skillCount) {
                datPersonaAddExp(persona, (s32)func_001fbfa0(
                    (u32)persona->level, BR_U32(work, 0x2a54),
                    BR_U32(work, 0xb8), 0x22b,
                    BR_U32(work, 0x2a58), BR_U32(work, 0x11c)));
            } else {
                skill = 0;
                while (skill < skillCount && skills[skill] != 0x22a) {
                    skill++;
                }
                if (skill < skillCount) {
                    datPersonaAddExp(persona, (s32)func_001fbfa0(
                        (u32)persona->level, BR_U32(work, 0x2a54),
                        BR_U32(work, 0xb8), 0x22a,
                        BR_U32(work, 0x2a58), BR_U32(work, 0x11c)));
                } else {
                    skill = 0;
                    while (skill < skillCount && skills[skill] != 0x229) {
                        skill++;
                    }
                    if (skill < skillCount) {
                        datPersonaAddExp(persona, (s32)func_001fbfa0(
                            (u32)persona->level, BR_U32(work, 0x2a54),
                            BR_U32(work, 0xb8), 0x229,
                            BR_U32(work, 0x2a58), BR_U32(work, 0x11c)));
                    }
                }
            }
        }
    }

    /* Retail +0x3e0..+0x464: collect Personas that learned skills. */
    BR_U32(work, 0xec) = 0;
    for (i = 0; i < heroCount; i++) {
        persona = datPersonaGetHeroPersona((s16)i);
        K_ASSERT(persona != NULL, 0x6ac);
        if (func_001761b0(persona) != 0 && BR_U32(work, 0xec) < 8) {
            BR_U16(work, 0xd4 + BR_U32(work, 0xec) * 2) = persona->id;
            BR_U32(work, 0xec)++;
        }
    }
    if (BR_U32(work, 0xec) != 0) {
        BR_U32(work, 0) |= 0x20;
    }

    /* Retail +0x494..+0x4d8: update each non-hero party member's result. */
    for (i = 0; i < BR_U32(work, 0x114); i++) {
        u8 *pcEntry = work + 0x10c + i * 2;
        s16 pc = *(s16 *)pcEntry;
        u32 exp = func_001fbdf0(datGetLevel(pc), BR_U32(work, 0x2a54),
                                BR_U32(work, 0xb8), BR_U32(work, 0x2a58),
                                BR_U32(work, 0x11c));
        func_001f9e90(*(u16 *)pcEntry, exp);
    }

    /* Retail +0x4e0..+0x640: process the optional sixth Persona's
     * learned-skill table and copy type-1 entries into the result. */
    if (datGetFlag(0x140)) {
        persona = datPersonaGetByPcId(6);
        K_ASSERT(persona != NULL, 0x6c9);
        datPersonaAddExp(persona, (s32)func_001fbdf0(
            datGetLevel(6), BR_U32(work, 0x2a54), BR_U32(work, 0xb8),
            BR_U32(work, 0x2a58), BR_U32(work, 0x11c)));
        if (func_001761b0(persona) != 0) {
            func_00175ce0(persona, (u16 *)(work + 0x158));
            entry = DAT_007ce430 + (persona->id - 0xc0) * 0x26e + 4;
            func_001fb4b0(entry, 0x20, persona->level,
                          BR_U8(work, 0x158), &firstIndex, &indexCount);
            BR_U32(work, 0x150) = 0;
            current = entry + firstIndex * 4;
            for (j = 0; j < indexCount; j++, current += 4) {
                if (current[1] == 1) {
                    BR_U16(work, 0x140 + BR_U32(work, 0x150) * 2) =
                        BR_U16(current, 2);
                    BR_U32(work, 0x150)++;
                }
            }
            func_00176100(persona, (u16 *)(work + 0x158));
            if (BR_U32(work, 0x150) != 0) {
                BR_U32(work, 0) |= 4;
            }
        }
    }

    if (BR_U32(work, 0xec) != 0) {
        BR_U32(work, 0x10000 - 0x5980) = 3;
    } else if ((BR_U32(work, 0) & 8) != 0) {
        BR_U32(work, 0x10000 - 0x5980) = 2;
    } else if ((BR_U32(work, 0) & 4) != 0) {
        BR_U32(work, 0x10000 - 0x5980) = 1;
    } else {
        BR_U32(work, 0x10000 - 0x5980) = 0;
    }
    return KWLNTASK_CONTINUE;
}
#pragma optimization_level 2

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
    BR_U32(params, 0x28) = BR_U32(work, 0x2a50);
    BR_U32(params, 0x2c) = BR_U32(work, 0xb0);
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
#pragma opt_propagation on

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
#pragma optimization_level 3
KwlnTask *func_001f2080(KwlnTask *parent, const u8 *params)
{
    u8 *work = (u8 *)BR_ALLOC2(0x2a220, 0x40000);
    KwlnTask *task;
    KwlnTask *child;
    RwV2d viewWindow;
    if (work == NULL) {
        return NULL;
    }
    sBrCard = work;
    BR_U32(work, 4) = 0;
    BR_U32(work, 0x14) = 0;
    task = kwlnTaskCreateWithAutoPriority(parent, 10, "battle result card",
                                          func_001f2300, func_001f2fd0, work);
    if (task == NULL) {
        BR_FREE(work);
        sBrCard = NULL;
        return NULL;
    }
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
    sflRes0020d7d0(work + 0x60);
    func_00239170(work + 0xf0);
    func_0023d7a0(work + 0x8e90);
    func_0023d7f0();
    func_0024da00(work + 0xbd04);
    sflCamera0024d110(work + 0xbcf0);
    func_002534d0(work + 0xc100);
    sflScript00259610(work + 0xbf10);
    sflCursor0025a110(work + 0x1ed90);
    func_001f58f0(work + 0x1fd60);
    func_00215a50(work + 0x23280);
    func_00260970(work + 0x29320);
    sflCount0025b4a0(work + 0x29bf0);
    func_0027bb50(work + 0x2a200);
    BR_U32(work, 0xe4) = 0;
    func_001f4650(task, params);
    BR_U32(work, 8) = 0;
    func_001f3270(task);
    BR_U32(work, 0x2a210) = 0;
    return task;
}
#pragma optimization_level 2

// FUN_001f2300 NONMATCHING
#pragma optimization_level 3
void *func_001f2300(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    u32 temp;
    if ((BR_U32(work, 4) & 0x80) != 0 && sflRes0020e380() == 0) {
        BR_U32(work, 4) &= ~0x80u;
    }
    if ((BR_U32(work, 4) & 0x100) != 0 && sflGround0023c350() == 0) {
        BR_U32(work, 4) &= ~0x100u;
    }
    func_00219d90();
    sflRes0020d820();
    func_00215fc0();
    func_001f5b20();
    switch (BR_U32(work, 8)) {
    case 1:
        if (sflRes0020dfe0() == 0 && func_00254f20() == 0 && BR_U32(work, 0x2a210) != 0) {
            func_00254f70();
            if (BR_U32(work, 0xe4) == 0) {
                func_003c72d0((void *)sflRes0020e790());
                func_0023d130();
                sflRes0020e3d0();
                sflRes0020eb40();
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
            func_0020e8f0();
            v = *(volatile u16*)0x007E094E;
            if ((v & 0x9ff) != 0 || (*(volatile u16*)0x007E094C & 0x10) != 0) {
                func_001f4a00();
            }
        }
        break;
    case 7:
        if (sflCard002582b0() == 0) {
            sflScript00259640();
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
            ((*(volatile u16*)0x007E094E & 0x40) != 0 ||
             (*(volatile u16*)0x007E094C & 0x10) != 0)) {
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
            (*(volatile u16 *)0x007E094E & 0x40) == 0 &&
            (*(volatile u16 *)0x007E094C & 0x10) == 0) {
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
        if (sflRes0020e4c0() == 0) {
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
                        func_001f6d20((const f32 *)&card[4]);
                    }
                    break;
                case 1:
                    func_001f6d20((const f32 *)&card[4]);
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
        if (sflRes0020e4c0() == 0) {
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
        if (sflRes0020e4c0() == 0) {
            func_001f5510();
        }
        break;
    case 4:
        if (sflRes0020e9b0() == 0) {
            func_003c77a0();
            func_003c72d0((void *)func_0020ea00());
            func_003c7430(0);
            BR_U32(work, 8) = 5;
        }
        break;
    case 5:
        func_003c7990(1);
        if (func_003c7850() == 0) {
            func_003c7650(1);
            func_003c77a0();
            func_003c94e0((void *)func_0020ea00());
            func_003c9790(0);
            BR_U32(work, 8) = 6;
        }
        break;
    case 6:
        func_003c7990(1);
        if (func_003c7850() == 0) {
            func_003c7650(1);
            func_003c77a0();
            func_0020ea80();
            func_003c72d0((void *)sflRes0020e790());
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
    func_0027be50();
    BR_U32(work, 4) &= ~3u;
    return KWLNTASK_CONTINUE;
}
#pragma optimization_level 2

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
    func_0027bba0(task);
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
    sflRes0020e030();
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
        u32 table0;
        u32 table1;
        u32 table2;
        u32 table3;
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
    u32 candidateCount;
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
    s32 currentLevel;
    s32 baseLevel;
    s32 threshold;
    s32 lower;
    s32 upper;
    s32 best;
    s32 level;
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
    local.table0 = (u32)func_00209e10();
    local.table1 = (u32)func_00209e20();
    local.table2 = (u32)func_00209e60();
    local.table3 = (u32)func_00209e70();
    func_00209dd0();
    table0 = (u8 *)local.table0;
    table1 = (u8 *)local.table1;
    table2 = (u8 *)local.table2;
    table3 = (u8 *)local.table3;

    /* Retail 0x1f32d8-0x1f33b0: level-to-card threshold. */
    candidateCount = 0;
    currentLevel = (s32)(s8)(datGetLevel(1) & 0xff);
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
                value = (u32)(s32)chance;
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
        func_0020e200();
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
    sflRes0020e2c0();
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
#pragma optimization_level 3
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
    sflScript00259690(work + 0x1e990, 0x400);
    printf(D_006847A0);
    printf(D_00696964);
    sflScript00259b00(10);
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

        sflScript00259c60((u16)((f32)(s32)actTable[0] +
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
            sflScript00259b60(0);
            printf(D_00684840, (s32)func_00530da0(progress));
            groups--;
            count += groupSize[groups] - 1;
        }
        if (selected == 0 || selected == 1 || selected == 2) {
            sflScript00259c10();
            sflScript00259bc0();
        }
        if (selected == 3) {
            sflScript00259cc0();
            progress += 3.0f;
            printf(D_00684840, (s32)func_00530da0(progress));
        }
    }
    for (i = 0; i < groups; i++) {
        sflScript00259b60(0);
        sflScript00259c10();
        sflScript00259bc0();
    }
    sflScript00259970();
    func_00257f10();
    func_0010a4e0(1, 0, 6, 1);
    BR_U32(work, 8) = 7;
}
#pragma optimization_level 2

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
        if (sflRes0020dfe0() != 0) goto resources_busy;
        if (func_00254f20() != 0) goto resources_busy;
        if (sflRes0020e4c0() != 0) goto resources_busy;
        if (sflRes0020ec00() == 0) goto resources_ready;

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

// FUN_001f58f0
void func_001f58f0(u8 *work)
{
    K_ASSERT(sBrReward == NULL, 0x92);
    BR_U32(work, 0) = 0;
    BR_U32(work, 0x3418) = 0;
    BR_U32(work, 0x341c) = 0;
    BR_U32(work, 0x33dc) = 0;
    sBrReward = work;
}

// FUN_001f5950
void func_001f5950(void)
{
    u8 *work;

    K_ASSERT(sBrReward != NULL, 0x8c);
    work = sBrReward;
    func_001f98d0();
    scrReleaseScript((void *)BR_U32(work, 0x34c4));
    sBrReward = NULL;
}

// FUN_001f59b0
void func_001f59b0(void)
{
    u8 *work;
    u32 *words;
    s32 i;
    u8 *entry;
    u32 type;

    K_ASSERT(sBrReward != NULL, 0x8c);
    work = sBrReward;
    words = (u32 *)work;
    BR_U32(work, 0) |= 1;
    BR_U32(work, 0) |= 2;
    BR_U32(work, 0x10) = 0;
    BR_U32(work, 0x18) = 100;
    BR_U32(work, 0x34c0) = 0;
    BR_U32(work, 0x34c4) = (u32)scrStartScriptFirstPrcd(D_00684850);
    if ((s32)BR_S32(work, 0x341c) + (s32)BR_S32(work, 0x3418) < 2) {
        words[2] = 0;
    } else {
        words[2] = 1;
    }
    if (words[2] == 0) {
        goto reward_state_zero;
    }
    switch (words[2]) {
    case 1:
        goto reward_loop_init;
    default:
        goto reward_done;
    }

reward_loop_init:
    i = 0;
    goto reward_loop_test;

reward_loop:
    entry = work + i * 0x670 + 0x5c;
    type = BR_U32(entry, 0);
    if (type == 1) {
        goto reward_type_one;
    }
    switch (type) {
    case 0:
        goto reward_type_zero;
    default:
        goto reward_loop_increment;
    }

reward_type_zero:
    func_0021ab80(BR_U16(entry, 4));
    goto reward_loop_increment;

reward_type_one:
    func_0021a920(BR_U32(entry, 4), BR_U32(entry, 8));

reward_loop_increment:
    i++;

reward_loop_test:
    if (i < BR_S32(work, 0x33dc)) {
        goto reward_loop;
    }
    sflCard00259310();
    BR_U32(work, 0) |= 0x80;
    BR_U32(work, 4) = 0;
    goto reward_done;

reward_state_zero:
    func_001f6630();

reward_done:
    ;
}

// FUN_001f5b20 NONMATCHING
#pragma optimization_level 3
void *func_001f5b20(void)
{
    u32 flags;
    u32 sub_state;
    s32 cnt;
    f32 t;
    u32 s0_val;
    u8 *entry;
    u8 col[4];
    f32 temp;
    u32 i;
    u8 *work;
    K_ASSERT(sBrReward != NULL, 0x8c);
    work = sBrReward;
    flags = BR_U32(work, 0);
    if (flags & 2) {
        BR_U32(work, 0) = flags & ~2u;
        goto final_exit;
    }
    if (!(flags & 1)) {
        goto final_exit;
    }
    if (flags & 0x100) {
        sub_state = BR_U32(work, 0x34c8);
        if (sub_state == 0) {
            cnt = BR_S32(work, 0x34d0) + 1;
            BR_S32(work, 0x34d0) = cnt;
            t = (f32)cnt / 30.0f;
            BR_S32(work, 0x34cc) = (s32)(256.0f * t);
            if (cnt == 30) {
                BR_U32(work, 0) &= ~0x100u;
            }
        } else if (sub_state == 1) {
            cnt = BR_S32(work, 0x34d0) + 1;
            BR_S32(work, 0x34d0) = cnt;
            t = (f32)cnt / 30.0f;
            BR_S32(work, 0x34cc) = (s32)(256.0f * (1.0f - t));
            if (cnt == 30) {
                BR_U32(work, 0) &= ~0x100u;
            }
        }
    }
    flags = BR_U32(work, 0);
    if (flags & 0x200) {
        sub_state = BR_U32(work, 0x34d4);
        if (sub_state == 0) {
            cnt = BR_S32(work, 0x34dc) + 1;
            BR_S32(work, 0x34dc) = cnt;
            t = (f32)cnt / 30.0f;
            BR_S32(work, 0x34d8) = (s32)(256.0f * t);
            if (cnt == 30) {
                BR_U32(work, 0) &= ~0x200u;
            }
        } else if (sub_state == 1) {
            cnt = BR_S32(work, 0x34dc) + 1;
            BR_S32(work, 0x34dc) = cnt;
            t = (f32)cnt / 30.0f;
            BR_S32(work, 0x34d8) = (s32)(256.0f * (1.0f - t));
            if (cnt == 30) {
                BR_U32(work, 0) &= ~0x200u;
            }
        }
    }
    sub_state = BR_U32(work, 4);
    if (sub_state >= 9) {
        goto main_exit;
    }
    switch (sub_state) {
    case 0:
        if (func_0021a120() != 0) {
            break;
        }
        if (sflCard00259380() != 0) {
            break;
        }
        func_00258300();
        func_002550b0();
        func_001f6630();
        break;
    case 1:
        break;
    case 2:
        flags = BR_U32(work, 0);
        if (flags & 0x40) {
            func_003c7990(1);
            if (func_003c7850() != 0) {
                break;
            }
            func_003c7650(1);
        } else {
            func_003c7990(0);
            if (func_003c7850() != 0) {
                break;
            }
            func_003c7650(0);
        }
        cnt = BR_S32(work, 0x340c) + 1;
        BR_S32(work, 0x340c) = cnt;
        if (cnt == BR_S32(work, 0x341c)) {
            func_001f6a60();
        } else {
            func_001f6e80();
        }
        break;
    case 3:
        if (func_001b07d0() != 0) {
            K_Fldrc_DestroyArchives();
            func_001f7170();
        }
        break;
    case 4:
        if (func_002168a0() != 0) {
            break;
        }
        sflResult001f9100();
        func_001f6a60();
        break;
    case 5:
        func_003c7990(0);
        if (func_003c7850() != 0) {
            break;
        }
        func_003c7650(0);
        cnt = BR_S32(work, 0x3410) + 1;
        BR_S32(work, 0x3410) = cnt;
        if (cnt == BR_S32(work, 0x3400)) {
            func_001f6a60();
        } else {
            func_001f7030();
        }
        break;
    case 6:
        func_003c7990(0);
        if (func_003c7850() != 0) {
            break;
        }
        func_003c7650(0);
        cnt = BR_S32(work, 0x3414) + 1;
        BR_S32(work, 0x3414) = cnt;
        if (cnt == BR_S32(work, 0x3404)) {
            func_001f6a60();
        } else {
            func_001f70d0();
        }
        break;
    case 7:
        sub_state = BR_U32(work, 0x34e4);
        if (sub_state == 0) {
            flags = BR_U32(work, 0);
            if ((flags & 0x40) && (flags & 0x10)) {
                s0_val = 1;
            } else {
                s0_val = 0;
            }
            func_003c7990(s0_val);
            if (func_003c7850() != 0) {
                break;
            }
            func_003c7650(s0_val);
            if (BR_U32(work, 0) & 0x800) {
                func_0034fcf0((void *)BR_U32(work, 0x34e0));
                func_001f9c60();
                BR_U32(work, 0) &= ~0x800u;
            }
            cnt = BR_S32(work, 0x3408) + 1;
            BR_S32(work, 0x3408) = cnt;
            if (cnt == BR_S32(work, 0x3418)) {
                func_001f6a60();
            } else {
                func_001f7210();
            }
        } else if (sub_state == 1) {
            flags = BR_U32(work, 0);
            if ((flags & 0x40) && (flags & 0x10)) {
                s0_val = 1;
            } else {
                s0_val = 0;
            }
            func_003c7990(s0_val);
            if (func_003c7850() != 0) {
                break;
            }
            func_003c7650(s0_val);
            cnt = BR_S32(work, 0x3510) + 1;
            BR_S32(work, 0x3510) = cnt;
            if ((u32)cnt < BR_U32(work, 0x3514)) {
                u32 idx = BR_U32(work, 0x34e8 + cnt * 8);
                func_003c7bc0(0, ((u32 *)0x00684a10)[idx]);
                func_003c7c20(1, BR_U32(work, 0x34ec + cnt * 8), 0);
                func_003c7430(0x17);
            } else {
                if (cnt == BR_S32(work, 0x3418)) {
                    func_001f6a60();
                } else {
                    func_001f7210();
                }
            }
        } else if (sub_state == 2) {
            flags = BR_U32(work, 0);
            if ((flags & 0x40) && (flags & 0x10)) {
                s0_val = 1;
            } else {
                s0_val = 0;
            }
            func_003c7990(s0_val);
            if (func_003c7850() != 0) {
                break;
            }
            func_003c7650(s0_val);
            cnt = BR_S32(work, 0x3408) + 1;
            BR_S32(work, 0x3408) = cnt;
            if (cnt == BR_S32(work, 0x3418)) {
                func_001f6a60();
            } else {
                func_001f7210();
            }
        }
        break;
    case 8:
    {
        u32 result = scrForceTraceCode((void *)BR_U32(work, 0x34c4));
        if (result == 0) {
            K_ASSERT(0, 0x1da);
        } else if (result == 2) {
            func_001f6a60();
        }
        break;
    }
    default:
        break;
    }
main_exit:
    if (BR_U32(work, 8) == 1) {
        flags = BR_U32(work, 0);
        if (flags & 0x400) {
            for (i = 0; i < BR_U32(work, 0x341c); i++) {
                u32 idx = BR_U32(work, 0x3c + i * 4);
                entry = work + idx * 0x670 + 0x5c;
                t = (f32)BR_S32(work, 0x34cc);
                t = 255.0f * t / 256.0f;
                col[0] = 0xff;
                col[1] = 0xff;
                col[2] = 0xff;
                if (t < 2147483648.0f) {
                    col[3] = (u8)((s32)t & 0xff);
                } else {
                    col[3] = (u8)(((s32)(t - 2147483648.0f) | 0x80000000) & 0xff);
                }
                func_0020cc80(entry + 0xc, col);
                gcPose0024f960(entry + 0x60c, &temp);
                func_0020d650(entry + 0xc, &temp);
                func_0020ac90(entry + 0xc);
            }
            for (i = 0; i < BR_U32(work, 0x3418); i++) {
                u32 idx = BR_U32(work, 0x1c + i * 4);
                entry = work + idx * 0x670 + 0x5c;
                t = (f32)BR_S32(work, 0x34d8);
                t = 255.0f * t / 256.0f;
                col[0] = 0xff;
                col[1] = 0xff;
                col[2] = 0xff;
                if (t < 2147483648.0f) {
                    col[3] = (u8)((s32)t & 0xff);
                } else {
                    col[3] = (u8)(((s32)(t - 2147483648.0f) | 0x80000000) & 0xff);
                }
                func_0020cc80(entry + 0xc, col);
                gcPose0024f960(entry + 0x60c, &temp);
                func_0020d650(entry + 0xc, &temp);
                func_0020ac90(entry + 0xc);
            }
        }
    }
final_exit:
    return KWLNTASK_CONTINUE;
}
#pragma optimization_level 2

// FUN_001f64c0 NONMATCHING
void func_001f64c0(void)
{
    u8 *work;
    s32 flags;
    s32 i;

    K_ASSERT(sBrReward != NULL, 0x8c);
    work = sBrReward;
    flags = ~BR_U32(work, 0);
    if ((flags & 1) == 0) {
        if (BR_U32(work, 8) == 1) {
            if ((flags & 0x400) == 0) {
                for (i = 0; i < BR_U32(work, 0x341c); i++) {
                    u32 idx = BR_U32(work + i * 4, 0x3c);
                    u8 *entry = work + idx * 0x670 + 0x5c;
                    func_0020b250(entry + 0xc);
                }
                for (i = 0; i < BR_U32(work, 0x3418); i++) {
                    u32 idx = BR_U32(work + i * 4, 0x1c);
                    u8 *entry = work + idx * 0x670 + 0x5c;
                    func_0020b250(entry + 0xc);
                }
            }
        }
    }
}
// FUN_001f65e0
u32 func_001f65e0(void)
{
    K_ASSERT(sBrReward != NULL, 0x8c);
    return BR_U32(sBrReward, 0) & 1;
}

/* Retail reconstruction spans 0x001f6630-0x001f6a5c: reward reset, card setup, and two indexed animation passes. */
// FUN_001f6630 NONMATCHING
void func_001f6630(void)
{
    u32 *work;
    s32 count;
    s32 i;

    K_ASSERT(sBrReward != NULL, 0x8c);
    work = (u32 *)sBrReward;
    work[0xd03] = 0;
    work[0xd02] = 0;
    work[0xd04] = 0;
    work[0xd05] = 0;
    work[0xd01] = 0;
    work[0xd00] = 0;
    count = work[0xd07];
    if (count != 0) {
        u32 available = func_001756f0() & 0xffff;
        work[0] |= 8;
        if ((func_00175410() & 0xffff) < available + count) {
            work[0] |= 0x10;
        } else {
            K_ASSERT(count < 9, 0x272);
            for (i = 0; i < count; i++) {
                *(u16 *)((u8 *)work + 0x33f0 + i * 2) =
                    *(u16 *)((u8 *)work +
                             ((u32 *)((u8 *)work + 0x3c))[i] * 0x670 + 0x60);
            }
            work[0xd01] = count;
        }
    }
    if (work[0xd06] != 0) {
        work[0] |= 0x20;
    }
    switch (work[2]) {
    case 1:
    {
        f32 output[4];
        for (i = 0; i < (s32)work[0xcf7]; i++) {
            u8 *entry;
            entry = (u8 *)work +
                    ((u32 *)((u8 *)work + 0x3c))[i] * 0x670 + 0x5c;
            switch (BR_U32(entry, 0)) {
            case 0:
                func_00209f00(entry + 0xc);
                func_0020c590(entry + 0xc, BR_U16(entry, 4));
                break;
            case 1:
                func_0020a800(entry + 0xc);
                func_0020c5f0(entry + 0xc, BR_U32(entry, 4),
                              BR_U32(entry, 8));
                break;
            }
            {
                static const f32 scale[3] = {10.0f, 10.0f, 10.0f};
                static const f32 axis[3] = {0.0f, 1.0f, 0.0f};
                f32 rotation[4];
                func_0020d630(entry + 0xc, scale);
                func_004bdde0(180.0f, rotation, axis, 0);
                func_0020d690(entry + 0xc, rotation);
            }
            func_0024fd80(entry + 0x60c);
            func_0024da60(entry + 0x60c);
            func_0024f090(entry + 0x60c);
        }
        for (i = 0; i < (s32)work[0xd07]; i++) {
            u8 *entry;
            f32 position[2];
            position[0] = (f32)i * 220.0f + 320.0f;
            position[1] = 184.0f;
            entry = (u8 *)work +
                    ((u32 *)((u8 *)work + 0x3c))[i] * 0x670 + 0x5c;
            func_0020c400(entry + 0xc, position,
                          func_0020c500(entry + 0xc, 200.0f), output);
            output[1] += 100.0f;
            func_0024f9f0(entry + 0x60c, output);
        }
        for (i = 0; i < (s32)work[0xd06]; i++) {
            u8 *entry;
            f32 position[2];
            position[0] = (f32)i * 220.0f + 320.0f;
            position[1] = 184.0f;
            entry = (u8 *)work +
                    ((u32 *)((u8 *)work + 0x1c))[i] * 0x670 + 0x5c;
            func_0020c400(entry + 0xc, position,
                          func_0020c500(entry + 0xc, 200.0f), output);
            output[1] += 100.0f;
            func_0024f9f0(entry + 0x60c, output);
        }
        work[0xd33] = 0;
        work[0xd36] = 0;
        break;
    }
    case 0:
        break;
    }
    work[0] |= 0x400;
    work[1] = 1;
    func_001f6a60();
}

// FUN_001f6a60 NONMATCHING
void func_001f6a60(void)
{
    u8 *work;
    u32 state;
    s32 i;
    u32 result;
    K_ASSERT(sBrReward != NULL, 0x8c);
    work = sBrReward;
    state = BR_U32(work, 4);
    for (;;) {
        switch (state) {
        case 1:
            if ((BR_U32(work, 0) & 8) != 0) {
                sflResult001f99f0();
                return;
            }
            state = 2;
            break;
        case 2:
            if ((BR_U32(work, 0) & 0x10) != 0) {
                BR_U32(work, 4) = 3;
                return;
            }
            state = 4;
            break;
        case 4:
            if ((BR_U32(work, 0) & 0x10) != 0 &&
                BR_U32(work, 0x3400) != 0) {
                func_001f7030();
                return;
            }
            state = 5;
            break;
        case 5:
            if ((BR_U32(work, 0) & 0x10) != 0 &&
                BR_U32(work, 0x3404) != 0) {
                func_001f70d0();
                return;
            }
            state = 6;
            break;
        case 6:
            if ((BR_U32(work, 0) & 0x20) != 0) {
                func_001f9a80();
                return;
            }
            state = 7;
            break;
        case 7:
            func_003c77a0();
            for (i = 0; i < (s32)BR_U32(work, 0x34c0); i++) {
                func_001831e0(-1, (s16)i,
                              work + (u32)i * 20 + 0x3420);
            }
            result = func_0035c250(BR_U32(work, 0x34c4));
            if (result == 2) {
                BR_U32(work, 4) = 8;
                return;
            }
            if (result == 1) {
                state = 8;
                break;
            }
            if (result == 0) {
                K_ASSERT(0, 0x32d);
            }
            K_ASSERT(0, 0x337);
            break;
        case 8:
            func_003c72d0(func_0020e790());
            if (sBrReward == NULL) {
                K_ASSERT(sBrReward != NULL, 0x8c);
            }
            BR_U32(sBrReward, 0) &= ~2u;
            BR_U32(sBrReward, 4) = 9;
            return;
        default:
            K_ASSERT(0, 0x341);
            break;
        }
    }
}

// FUN_001f6d20 NONMATCHING
#pragma optimization_level 3
void func_001f6d20(const f32 *entry)
{
    u8 *work = sBrReward;
    u32 type;
    u32 index;
    K_ASSERT(work != NULL, 0x8c);
    type = BR_U32(entry, 0);
    if (type == 0) {
        index = BR_U32(work, 0x341c);
        K_ASSERT(index < 8, 0x355);
        BR_U32(work, 0x3c + index * 4) = index;
        BR_U32(work, index * 0x670 + 0x5c) = 0;
        BR_U32(work, index * 0x670 + 0x60) = 0;
        BR_U32(work, index * 0x670 + 0x64) = 0;
        BR_U32(work, index * 0x670 + 0x5c) = 0;
        BR_U32(work, 0x341c) = index + 1;
    } else if (type == 1) {
        index = BR_U32(work, 0x3418);
        K_ASSERT(index < 8, 0x35a);
        BR_U32(work, 0x1c + index * 4) = index;
        BR_U32(work, index * 0x670 + 0x5c) = 1;
        BR_U32(work, 0x3418) = index + 1;
    } else {
        K_ASSERT(0, 0x35f);
        return;
    }
    BR_U32(work, BR_U32(work, 0x33dc) * 0x670 + 0x5c) = *(const u32 *)entry;
    BR_U32(work, BR_U32(work, 0x33dc) * 0x670 + 0x60) = *(const u32 *)(entry + 1);
    BR_U32(work, BR_U32(work, 0x33dc) * 0x670 + 0x64) = *(const u32 *)(entry + 2);
    BR_U32(work, 0x33dc)++;
}
#pragma optimization_level 2

// FUN_001f6e80 NONMATCHING
void func_001f6e80(void)
{
    u8 *work = sBrReward;
    s32 i;
    u32 count;
    u32 idx;
    u8 *entry;
    f32 output[2];
    f32 position[2];
    f32 scale;
    K_ASSERT(work != NULL, 0x8c);
    count = BR_U32(work, 0x340c);
    if (count != 0) {
        for (i = 0; i < BR_S32(work, 0x341c); i++) {
            idx = BR_U32(work, 0x3c + i * 4);
            entry = work + idx * 0x670 + 0x5c;
            position[0] = (f32)(i - (s32)count) * 220.0f + 320.0f;
            position[1] = 184.0f;
            scale = func_0020c500(entry + 0xc, 200.0f);
            func_0020c400(entry + 0xc, position, scale, output);
            output[1] += 100.0f;
            func_002508c0(entry + 0x60c, output, 0x14);
        }
    }
    idx = BR_U32(work, 0x3c + count * 4);
    entry = work + idx * 0x670 + 0x5c;
    func_003c7bc0(0, func_00173220(BR_U16(entry, 0x60)));
    func_003c7430(9);
    if (count == BR_U32(work, 0x341c) - 1) {
        BR_U32(work, 0) |= 0x40;
    }
    func_0010a4e0(1, 0, 6, 10);
}

// FUN_001f7030
void func_001f7030(void)
{
    u8* work;
    u32 offset;

    K_ASSERT(sBrReward != NULL, 0x8c);
    work = sBrReward;
    func_003c7bc0(0, func_001775a0(1));
    offset = BR_U32(work, 0x3410) * 2;
    func_003c7bc0(1, func_00173220(
        BR_U16((u8*)(offset + (u32)work), 0x33e0)));
    func_003c7430(14);
    BR_U32(work, 4) = 5;
}

// FUN_001f70d0
void func_001f70d0(void)
{
    u8* work;
    u32 offset;

    K_ASSERT(sBrReward != NULL, 0x8c);
    work = sBrReward;
    func_003c7bc0(0, func_001775a0(1));
    offset = BR_U32(work, 0x3414) * 2;
    func_003c7bc0(1, func_00173220(
        BR_U16((u8*)(offset + (u32)work), 0x33f0)));
    func_003c7430(16);
    BR_U32(work, 4) = 6;
}

// FUN_001f7170
void func_001f7170(void)
{
    u8 *work;
    s32 i;
    K_ASSERT(sBrReward != NULL, 0x8c);
    work = sBrReward;
    for (i = 0; i < BR_S32(work, 0x341c); i++) {
        u32 idx = BR_U32(work + i * 4, 0x3c);
        func_00217590(BR_U16(work + idx * 0x670, 0x60));
    }
    func_00215b00();
    BR_U32(work, 4) = 4;
}

// FUN_001f7210 NONMATCHING
#pragma optimization_level 3
void func_001f7210(void)
{
    u8 *work = sBrReward;
    u32 slot;
    u32 entry_idx;
    u8 *entry;
    u32 entry_type;
    u32 kind;
    s32 value = 0;
    u16 selected_id;
    s16 selected_value;
    u16 selected_aux;
    u32 stat_cnt[5];
    u8 card_buf[20];
    u32 item_substate;
    u32 debug_val;
    u32 total_weight;
    u32 weightTable[13];
    s32 *weight_slot;
    s16 scan_arr[6];
    s32 member_count;
    u16 cur_hp, max_hp;
    u16 cur_sp, max_sp;
    u32 st_val;
    u32 effect_idx;
    u32 apply_idx;
    s16 *apply_ptr;
    u32 amount;
    u32 new_val;
    K_ASSERT(work != NULL, 0x8c);
    debug_val = 0;
    slot = BR_U32(work, 0x3408);
    entry_idx = BR_U32(work, 0x1c + slot * 4);
    BR_U32(work, 0x34e8) = entry_idx + slot;
    entry = work + entry_idx * 0x670 + 0x60;
    kind = 0;
    entry_type = BR_U32(entry, 0);
    BR_U32(work, 0x34e0) = entry_idx * 0x670;
    switch (entry_type) {
    case 0:
    {
        u8 *wt_base;
        u32 wt_idx;
        u32 sum_w;
        u32 search_idx;
        /* case 0: weighted random via func_00209c40 */
        printf("rank %d\n", 0);
        func_0010a4e0(1, 0, 6, 6);
        wt_base = (u8 *)func_00209c40();
        printf("rnd %d/%d\n", BR_U32(entry, 4));
        wt_base += BR_U32(entry, 4) * 256;
        /* Count valid entries */
        for (wt_idx = 0; wt_idx < 32; wt_idx++) {
            if (*(s16 *)(wt_base + wt_idx * 8) < 0) break;
        }
        /* Sum weights directly from table */
        sum_w = 0;
        {
            u32 j;
            for (j = 0; j < wt_idx; j++) {
                sum_w += (u32)*(s16 *)(wt_base + j * 8 + 6);
            }
        }
        if (sum_w > 0) {
            u32 rnd = func_00488f30() % sum_w;
            for (search_idx = 0; search_idx < wt_idx; search_idx++) {
                s16 w = *(s16 *)(wt_base + search_idx * 8 + 6);
                if (rnd < (u32)w) break;
                rnd -= (u32)w;
            }
            wt_base += search_idx * 8;
        }
        printf("rnd %d/%d\n", search_idx, sum_w);
        {
            selected_id = *(u16 *)wt_base;
            selected_value = *(s16 *)(wt_base + 2);
            selected_aux = *(u16 *)(wt_base + 4);
            printf("item id %d\n", selected_id);
            kind = 1;
            value = (s32)selected_value;
        }
        printf("type : get money\n");
        break;
    }
    case 1:
    {
        u8 *tbl_entry;
        u32 new_kind;
        u32 rnd;
        u32 entry_count;
        u8 *tbl_scan[16];
        /* case 1: item-table scan via func_00209c80 */
        printf("type : get item\n");
        func_0010a4e0(1, 0, 6, 7);
        tbl_entry = (u8 *)func_00209c80();
        printf("money : %d\n", BR_S32(entry, 4));
        tbl_entry += BR_U32(entry, 4) * 192;
        for (new_kind = 0; new_kind < 16; new_kind++) {
            u8 *p = tbl_entry + new_kind * 12;
            u32 ret = (u32)func_00209d40(p);
            tbl_scan[new_kind] = p;
            if (ret == 2) break;
        }
        rnd = func_00488f30() % new_kind;
        printf("item id : 0x%03x\n", rnd);
        tbl_entry = tbl_scan[rnd];
        entry_count = (u32)func_00209d40(tbl_entry);
        if (entry_count == 1) {
            printf("item id : 0x%03x\n", BR_U16(entry, 4));
            selected_id = BR_U16(entry, 4);
            selected_value = BR_S16(entry, 8);
            selected_aux = BR_U16(entry, 4);
            value = (s32)selected_value;
            kind = 2;
        } else if (entry_count == 0) {
            printf("rank %d\n", value);
            printf("rank %d\n", value);
            if (datGetFlag(0xbd1) != 0) {
                value = (s32)((f32)BR_S32(entry, 4) * 0.25f);
            }
            kind = 3;
        } else {
            K_ASSERT(work != NULL, 0x450);
        }
        printf("money : %d\n", value);
        break;
    }
    case 2:
    {
        u8 *tbl_entry;
        u32 entry_off;
        u32 rnd;
        /* case 2: reward table via func_00209cc0 */
        printf("money : %d\n", BR_S32(entry, 8));
        func_0010a4e0(1, 0, 6, 8);
        tbl_entry = (u8 *)func_00209cc0();
        printf("type : get money\n", BR_U32(entry, 4));
        tbl_entry += BR_U32(entry, 4) * 24;
        rnd = func_00488f30() % 100;
        for (entry_off = 0; entry_off < 6; entry_off++) {
            s16 w = *(s16 *)(tbl_entry + entry_off * 4);
            if (w > 0 && rnd < (u32)w) break;
            if (w > 0) rnd -= (u32)w;
        }
        if (entry_off >= 6) {
            K_ASSERT(work != NULL, 0x469);
        }
        switch (entry_off) {
        case 0:
            rnd = func_00488f30() % 5;
            value = (s32)*(s16 *)(tbl_entry + 2);
            switch (rnd) {
            case 0:
                kind = 4;
                break;
            case 1:
                kind = 7;
                break;
            case 2:
                kind = 6;
                break;
            case 3:
                kind = 5;
                break;
            case 4:
                kind = 8;
                break;
            }
            break;
        case 1:
            value = (s32)*(s16 *)(tbl_entry + 6);
            kind = 9;
            break;
        case 2:
            value = (s32)*(s16 *)(tbl_entry + 10);
            kind = 11;
            break;
        case 3:
            value = (s32)*(s16 *)(tbl_entry + 14);
            kind = 12;
            break;
        case 4:
            value = (s32)*(s16 *)(tbl_entry + 18);
            kind = 10;
            break;
        case 5:
            value = (s32)*(s16 *)(tbl_entry + 22);
            kind = 13;
            break;
        }
        break;
    }
    case 3:
    {
        u8 *res_base;
        u8 *effect_table;
        u32 effect_idx;
        u32 random_value;
        u32 selected_idx;
        /* The effect table stores 13 (weight,value) byte pairs. */
        printf("type : get item\n");
        res_base = (u8 *)func_00209d00();
        printf("money : %d\n", BR_S32(entry, 4));
        effect_table = res_base + BR_U32(entry, 4) * 26;
        func_0010a4e0(1, 0, 6, 9);
        res_base = (u8 *)func_0020e710(1);
        func_0034fcd0(res_base);
        BR_U32(work, 0x34e0) = (u32)res_base;
        BR_U32(work, 0) |= 0x800;
        total_weight = 0;
        for (effect_idx = 0; effect_idx < 13; effect_idx++) {
            weight_slot = (s32 *)&weightTable[effect_idx];
            *weight_slot = 0;
            switch (effect_idx) {
            case 0:
            {
                u16 cur = (u16)func_0016c4f0(1);
                u16 max = (u16)func_0016c5f0(1);
                if (cur < max) {
                    *weight_slot = (s32)*(s8 *)(effect_table + 0);
                    total_weight += *weight_slot;
                }
                break;
            }
            case 1:
            {
                brRoot001f1df0((u16 *)scan_arr, &member_count);
                for (effect_idx = 0; effect_idx < (u32)member_count; effect_idx++) {
                    s16 mbr = scan_arr[effect_idx];
                    u16 cur = (u16)func_0016c4f0(mbr);
                    u16 max = (u16)func_0016c5f0(mbr);
                    if (cur < max) break;
                }
                if (effect_idx < (u32)member_count) {
                    *weight_slot = (s32)*(s8 *)(effect_table + 2);
                    total_weight += *weight_slot;
                }
                break;
            }
            case 2:
            {
                u16 cur = (u16)func_0016c570(1);
                u16 max = (u16)func_0016c670(1);
                if (cur < max) {
                    *weight_slot = (s32)*(s8 *)(effect_table + 4);
                    total_weight += *weight_slot;
                }
                break;
            }
            case 3:
            {
                brRoot001f1df0((u16 *)scan_arr, &member_count);
                for (effect_idx = 0; effect_idx < (u32)member_count; effect_idx++) {
                    s16 mbr = scan_arr[effect_idx];
                    u16 cur = (u16)func_0016c570(mbr);
                    u16 max = (u16)func_0016c670(mbr);
                    if (cur < max) break;
                }
                if (effect_idx < (u32)member_count) {
                    *weight_slot = (s32)*(s8 *)(effect_table + 6);
                    total_weight += *weight_slot;
                }
                break;
            }
            case 4:
                if ((func_0016c970(1) & 0x80) != 0) {
                    *weight_slot = (s32)*(s8 *)(effect_table + 8);
                    total_weight += *weight_slot;
                }
                break;
            case 5:
            {
                brRoot001f1df0((u16 *)scan_arr, &member_count);
                for (effect_idx = 0; effect_idx < (u32)member_count; effect_idx++) {
                    if ((func_0016c970(scan_arr[effect_idx]) & 0x80) != 0) break;
                }
                if (effect_idx < (u32)member_count) {
                    *weight_slot = (s32)*(s8 *)(effect_table + 10);
                    total_weight += *weight_slot;
                }
                break;
            }
            case 6:
                break;
            case 7:
                st_val = func_0016c920(1);
                if (st_val >= 3 && st_val <= 5) {
                    *weight_slot = (s32)*(s8 *)(effect_table + 14);
                    total_weight += *weight_slot;
                }
                break;
            case 8:
            {
                brRoot001f1df0((u16 *)scan_arr, &member_count);
                for (effect_idx = 0; effect_idx < (u32)member_count; effect_idx++) {
                    st_val = func_0016c920(scan_arr[effect_idx]);
                    if (st_val >= 3 && st_val <= 5) break;
                }
                if (effect_idx < (u32)member_count) {
                    *weight_slot = (s32)*(s8 *)(effect_table + 16);
                    total_weight += *weight_slot;
                }
                break;
            }
            case 9:
                st_val = func_0016c920(1);
                if (st_val == 1 || st_val == 2) {
                    *weight_slot = (s32)*(s8 *)(effect_table + 18);
                    total_weight += *weight_slot;
                }
                break;
            case 10:
            {
                brRoot001f1df0((u16 *)scan_arr, &member_count);
                for (effect_idx = 0; effect_idx < (u32)member_count; effect_idx++) {
                    st_val = func_0016c920(scan_arr[effect_idx]);
                    if (st_val == 1 || st_val == 2) break;
                }
                if (effect_idx < (u32)member_count) {
                    *weight_slot = (s32)*(s8 *)(effect_table + 20);
                    total_weight += *weight_slot;
                }
                break;
            }
            case 11:
                st_val = func_0016c920(1);
                if (st_val != 2) {
                    *weight_slot = (s32)*(s8 *)(effect_table + 22);
                    total_weight += *weight_slot;
                }
                break;
            case 12:
            {
                brRoot001f1df0((u16 *)scan_arr, &member_count);
                for (effect_idx = 0; effect_idx < (u32)member_count; effect_idx++) {
                    st_val = func_0016c920(scan_arr[effect_idx]);
                    if (st_val != 2) break;
                }
                if (effect_idx < (u32)member_count) {
                    *weight_slot = (s32)*(s8 *)(effect_table + 24);
                    total_weight += *weight_slot;
                }
                break;
            }
            }
        }
        if (total_weight == 0) {
            kind = 27;
        } else {
            random_value = func_00488f30() % total_weight;
            for (selected_idx = 0; selected_idx < 13; selected_idx++) {
                random_value -= weightTable[selected_idx];
                if ((s32)random_value < 0) break;
            }
            if (selected_idx >= 13) {
                K_ASSERT(0, 0x59d);
            } else {
                switch (selected_idx) {
                case 0:
                    kind = 14;
                    value = (s32)*(s8 *)(effect_table + 1);
                    break;
                case 1:
                    kind = 15;
                    value = (s32)*(s8 *)(effect_table + 3);
                    break;
                case 2:
                    kind = 16;
                    value = (s32)*(s8 *)(effect_table + 5);
                    break;
                case 3:
                    kind = 17;
                    value = (s32)*(s8 *)(effect_table + 7);
                    break;
                case 4:
                    kind = 18;
                    value = (s32)*(s8 *)(effect_table + 9);
                    break;
                case 5:
                    kind = 19;
                    value = (s32)*(s8 *)(effect_table + 11);
                    break;
                case 6:
                    kind = 20;
                    value = (s32)*(s8 *)(effect_table + 13);
                    break;
                case 7:
                    kind = 21;
                    value = (s32)*(s8 *)(effect_table + 15);
                    break;
                case 8:
                    kind = 22;
                    value = (s32)*(s8 *)(effect_table + 17);
                    break;
                case 9:
                    kind = 23;
                    value = (s32)*(s8 *)(effect_table + 19);
                    break;
                case 10:
                    kind = 24;
                    value = (s32)*(s8 *)(effect_table + 21);
                    break;
                case 11:
                    kind = 25;
                    value = (s32)*(s8 *)(effect_table + 23);
                    break;
                case 12:
                    kind = 26;
                    value = (s32)*(s8 *)(effect_table + 25);
                    break;
                }
            }
        }
        break;
    }
    }
    /* Per-kind custom processing (retail first dispatch at 0x7b6f90) */
    if (kind < 28) {
        switch (kind) {
        case 0:
            /* Kind 0: skip to common code */
            break;
        case 1:
            /* Kind 1: card slot management */
            printf("rank %d\n", value);
            printf("type : get item\n");
            if (selected_value < 0) {
                func_001828d0((s16)selected_id, (void *)card_buf, (void *)0);
                value = (s32)*(u8 *)(card_buf + 8);
            } else {
                func_00182d90((s16)selected_id, (u8)selected_value,
                             (u32)selected_aux, (void *)card_buf);
            }
            if (BR_U32(work, 0x34c0) >= 8) {
                K_ASSERT(work != NULL, 0x5b9);
            }
            {
                u32 off = BR_U32(work, 0x34c0) * 5 * 4;
                func_00521250(work + 0x3420 + off, card_buf, 20);
            }
            BR_U32(work, 0x34c0)++;
            break;
        case 2:
        {
            u8 item_count;
            /* Kind 1: item reward */
            printf("rank %d\n", value);
            printf("item id : 0x%03x\n", selected_id);
            printf("item num : %d\n", (s32)selected_value);
            item_count = (u8)func_00170760(1, (s16)selected_id);
            printf("money : %d\n", item_count);
            item_count += (u8)selected_value;
            if (item_count >= 100) item_count = 99;
            func_00170860(1, (s16)selected_id, item_count);
            printf("money : %d\n", item_count);
            break;
        }
        case 3:
        {
            u32 per_kind_val;
            /* Kind 2: money reward */
            printf("rank %d\n", value);
            per_kind_val = datGetMoney();
            printf("money : %d\n", per_kind_val);
            per_kind_val += (u32)value;
            if (per_kind_val > 9999999) per_kind_val = 9999999;
            printf("money : %d\n", per_kind_val);
            datSetMoney(per_kind_val);
            printf("money : %d\n", per_kind_val);
            break;
        }
        case 4:
        {
            DatPersonaWork *persona = datPersonaGetByPcId(1);
            datPersonaAddToNaturalStat(persona, 0, (s8)BR_S16(entry, 2));
            break;
        }
        case 5:
        {
            DatPersonaWork *persona = datPersonaGetByPcId(1);
            datPersonaAddToNaturalStat(persona, 3, (s8)BR_S16(entry, 2));
            break;
        }
        case 6:
        {
            DatPersonaWork *persona = datPersonaGetByPcId(1);
            datPersonaAddToNaturalStat(persona, 2, (s8)BR_S16(entry, 2));
            break;
        }
        case 7:
        {
            DatPersonaWork *persona = datPersonaGetByPcId(1);
            datPersonaAddToNaturalStat(persona, 1, (s8)BR_S16(entry, 2));
            break;
        }
        case 8:
        {
            DatPersonaWork *persona = datPersonaGetByPcId(1);
            datPersonaAddToNaturalStat(persona, 4, (s8)BR_S16(entry, 2));
            break;
        }
        case 9:
        {
            u32 i_idx;
            u32 out_idx;
            u32 rnd_stat;
            DatPersonaWork *persona;
            for (i_idx = 0; i_idx < 5; i_idx++) {
                stat_cnt[i_idx] = 0;
            }
            for (i_idx = 0; i_idx < (u32)BR_S16(entry, 2); i_idx++) {
                rnd_stat = func_00488f30() % 5;
                persona = datPersonaGetByPcId(1);
                datPersonaAddToNaturalStat(persona, (u16)rnd_stat, 1);
                stat_cnt[rnd_stat]++;
            }
            out_idx = 0;
            for (i_idx = 0; i_idx < 5; i_idx++) {
                if (stat_cnt[i_idx] != 0) {
                    BR_U32(work, 0x34e8 + out_idx * 8) = i_idx;
                    BR_U32(work, 0x34ec + out_idx * 8) = stat_cnt[i_idx];
                    out_idx++;
                }
            }
            BR_U32(work, 0x3514) = out_idx;
            BR_U32(work, 0x3510) = 0;
            break;
        }
        case 10:
        {
            s16 cur_pts = datGetAcademicPoint(1);
            s16 old_lvl = datGetAcademicLevel(cur_pts);
            s16 new_pts = cur_pts + BR_S16(entry, 2);
            if (new_pts >= 1000) new_pts = 999;
            datSetAcademicPoint(1, new_pts);
            if (datGetAcademicLevel(new_pts) != old_lvl) {
                debug_val |= 1;
            }
            break;
        }
        case 11:
        {
            s16 cur_pts = datGetCharmPoint(1);
            s16 old_lvl = datGetCharmLevel(cur_pts);
            s16 new_pts = cur_pts + BR_S16(entry, 2);
            if (new_pts >= 1000) new_pts = 999;
            datSetCharmPoint(1, new_pts);
            if (datGetCharmLevel(new_pts) != old_lvl) {
                debug_val |= 1;
            }
            break;
        }
        case 12:
        {
            s16 cur_pts = datGetCouragePoint(1);
            s16 old_lvl = datGetCourageLevel(cur_pts);
            s16 new_pts = cur_pts + BR_S16(entry, 2);
            if (new_pts >= 1000) new_pts = 999;
            datSetCouragePoint(1, new_pts);
            if (datGetCourageLevel(new_pts) != old_lvl) {
                debug_val |= 1;
            }
            break;
        }
        case 13:
            /* F852C: work[0x18] = work[0x18] * value / 100 */
            BR_U32(work, 0x18) = (u32)((s32)BR_U32(work, 0x18) * value / 100);
            break;
        case 14:
            /* F854C: HP recover direct (member 1) */
            cur_hp = (u16)func_0016c4f0(1);
            max_hp = (u16)func_0016c5f0(1);
            amount = (u32)((s32)max_hp * value / 100);
            new_val = cur_hp + amount;
            if (new_val > max_hp) new_val = max_hp;
            func_0016cf40(1, (u32)(s16)new_val);
            break;
        case 15:
            /* F85AC: HP recover scan */
            for (apply_idx = 0; apply_idx < (u32)member_count; apply_idx++) {
                apply_ptr = &scan_arr[apply_idx];
                cur_hp = (u16)func_0016c4f0(*apply_ptr);
                max_hp = (u16)func_0016c5f0(*apply_ptr);
                amount = (u32)((s32)max_hp * value / 100);
                new_val = cur_hp + amount;
                if (new_val > max_hp) new_val = max_hp;
                func_0016cf40(*apply_ptr, (u32)(s16)new_val);
            }
            break;
        case 16:
            /* F8638: SP recover direct (member 1) */
            cur_sp = (u16)func_0016c570(1);
            max_sp = (u16)func_0016c670(1);
            amount = (u32)((s32)max_sp * value / 100);
            new_val = cur_sp + amount;
            if (new_val > max_sp) new_val = max_sp;
            func_0016cf90(1, (u32)(s16)new_val);
            break;
        case 17:
            /* F8698: SP recover scan */
            for (apply_idx = 0; apply_idx < (u32)member_count; apply_idx++) {
                apply_ptr = &scan_arr[apply_idx];
                cur_sp = (u16)func_0016c570(*apply_ptr);
                max_sp = (u16)func_0016c670(*apply_ptr);
                amount = (u32)((s32)max_sp * value / 100);
                new_val = cur_sp + amount;
                if (new_val > max_sp) new_val = max_sp;
                func_0016cf90(*apply_ptr, (u32)(s16)new_val);
            }
            break;
        case 18:
            /* F8724: bad-status clear direct (member 1) */
            st_val = func_0016c970(1);
            func_0016d8b0(1, st_val & ~0x80);
            break;
        case 19:
            /* F874C: bad-status clear scan */
            for (apply_idx = 0; apply_idx < (u32)member_count; apply_idx++) {
                apply_ptr = &scan_arr[apply_idx];
                st_val = func_0016c970(*apply_ptr);
                func_0016d8b0(*apply_ptr, st_val & ~0x80);
            }
            break;
        case 21:
            /* F87A0: physicalCondition set 0 direct */
            st_val = func_0016c920(1);
            func_0016d6b0(1, 0);
            break;
        case 22:
            /* F87C4: physicalCondition set 0 scan */
            for (apply_idx = 0; apply_idx < (u32)member_count; apply_idx++) {
                apply_ptr = &scan_arr[apply_idx];
                st_val = func_0016c920(*apply_ptr);
                func_0016d6b0(*apply_ptr, 0);
            }
            break;
        case 23:
            /* F8814: physicalCondition set 1 direct */
            st_val = func_0016c920(1);
            func_0016d6b0(1, 1);
            break;
        case 24:
            /* F8838: physicalCondition set 1 scan */
            for (apply_idx = 0; apply_idx < (u32)member_count; apply_idx++) {
                apply_ptr = &scan_arr[apply_idx];
                st_val = func_0016c920(*apply_ptr);
                func_0016d6b0(*apply_ptr, 1);
            }
            break;
        case 25:
            /* F8888: physicalCondition set 2 direct */
            st_val = func_0016c920(1);
            func_0016d6b0(1, 2);
            break;
        case 26:
            /* F88AC: physicalCondition set 2 scan */
            for (apply_idx = 0; apply_idx < (u32)member_count; apply_idx++) {
                apply_ptr = &scan_arr[apply_idx];
                st_val = func_0016c920(*apply_ptr);
                func_0016d6b0(*apply_ptr, 2);
            }
            break;
        default:
            break;
        }
    }
    if (kind >= 28) {
        K_ASSERT(work != NULL, 0x6b1);
    }
    printf("rank %d\n", kind);
    item_substate = BR_U32(entry, 4) % 6;
    /*
     * Kind dispatch: 28-entry jump table (retail 0x7b6f20).
     * Each case body opens with the retail instruction(s) transcribed from
     * the disassembly; all distinct entries force MWCC to emit the table.
     */
    switch (kind) {
    case 1:
        /* off=5948 */
        func_003c7bc0(0, (u32)func_00171110((u32)selected_id, (s32)selected_value));
        func_003c7430(10);
        goto animation_tail;
    case 2:
        /* off=6008 */
        func_003c7bc0(0, (u32)func_00171110((u32)selected_id, 0));
        func_003c7c20(1, value, 0);
        func_003c7430(11);
        goto animation_tail;
    case 3:
        /* off=6084 */
        func_003c7c20(0, BR_U32(entry, 8), 0);
        func_003c7430(12);
        goto animation_tail;
    case 4:
    {
        u32 tmp = func_00173220(BR_U16(entry, 2));
        func_003c7bc0(0, tmp);
        func_003c7c20(1, value, 0);
        func_003c7430(17);
        goto animation_tail;
    }
    case 5:
    {
        u32 tmp = func_00173220(BR_U16(entry, 2));
        func_003c7bc0(0, tmp);
        func_003c7c20(1, value, 0);
        func_003c7430(20);
        goto animation_tail;
    }
    case 6:
    {
        u32 tmp = func_00173220(BR_U16(entry, 2));
        func_003c7bc0(0, tmp);
        func_003c7c20(1, value, 0);
        func_003c7430(18);
        goto animation_tail;
    }
    case 7:
    {
        u32 tmp = func_00173220(BR_U16(entry, 2));
        func_003c7bc0(0, tmp);
        func_003c7c20(1, value, 0);
        func_003c7430(19);
        goto animation_tail;
    }
    case 8:
    {
        u32 tmp = func_00173220(BR_U16(entry, 2));
        func_003c7bc0(0, tmp);
        func_003c7c20(1, value, 0);
        func_003c7430(21);
        goto animation_tail;
    }
    case 9:
    {
        u32 tmp = func_00173220(BR_U16(entry, 2));
        func_003c7bc0(0, tmp);
        func_003c7430(22);
        goto animation_tail;
    }
    case 10:
    {
        u32 tmp;
        /* off=6512 */
        if ((debug_val & 1) == 0) {
            tmp = func_001775a0(1);
            func_003c7bc0(0, tmp);
            func_003c7430(26);
        } else {
            tmp = func_001775a0(1);
            func_003c7bc0(0, tmp);
            tmp = func_0016c6f0(1);
            tmp = func_00177280(tmp);
            tmp = func_0011a810(tmp);
            func_003c7bc0(1, tmp);
            func_003c7430(29);
        }
        goto animation_tail;
    }
    case 11:
    {
        u32 tmp;
        /* off=6680 */
        if ((debug_val & 1) == 0) {
            tmp = func_001775a0(1);
            func_003c7bc0(0, tmp);
            func_003c7430(25);
        } else {
            tmp = func_001775a0(1);
            func_003c7bc0(0, tmp);
            tmp = func_0016c740(1);
            tmp = func_001772f0(tmp);
            tmp = func_0011a840(tmp);
            func_003c7bc0(1, tmp);
            func_003c7430(28);
        }
        goto animation_tail;
    }
    case 12:
    {
        u32 tmp;
        /* off=6848 */
        if ((debug_val & 1) == 0) {
            tmp = func_001775a0(1);
            func_003c7bc0(0, tmp);
            func_003c7430(24);
        } else {
            tmp = func_001775a0(1);
            func_003c7bc0(0, tmp);
            tmp = func_0016c790(1);
            tmp = func_00177360(tmp);
            tmp = func_0011a870(tmp);
            func_003c7bc0(1, tmp);
            func_003c7430(27);
        }
        goto animation_tail;
    }
    case 13:
        func_003c7430(30);
        goto animation_tail;
    case 14:
    {
        u32 tmp = func_001775a0(1);
        func_003c7bc0(0, tmp);
        func_003c7430(25);
        goto animation_tail;
    }
    case 15:
        func_003c7430(32);
        goto animation_tail;
    case 16:
    {
        u32 tmp = func_001775a0(1);
        func_003c7bc0(0, tmp);
        func_003c7430(27);
        goto animation_tail;
    }
    case 17:
        func_003c7430(34);
        goto animation_tail;
    case 18:
    {
        u32 tmp = func_001775a0(1);
        func_003c7bc0(0, tmp);
        func_003c7430(31);
        goto animation_tail;
    }
    case 19:
        func_003c7430(36);
        goto animation_tail;
    case 20:
    {
        u32 tmp = func_00173220(BR_U16(entry, 2));
        func_003c7bc0(0, tmp);
        func_003c7430(37);
        goto animation_tail;
    }
    case 21:
    {
        u32 tmp = func_001775a0(1);
        func_003c7bc0(0, tmp);
        func_003c7430(38);
        goto animation_tail;
    }
    case 22:
        func_003c7430(39);
        goto animation_tail;
    case 23:
    {
        u32 tmp = func_001775a0(1);
        func_003c7bc0(0, tmp);
        func_003c7430(40);
        goto animation_tail;
    }
    case 24:
        func_003c7430(41);
        goto animation_tail;
    case 25:
    {
        u32 tmp = func_001775a0(1);
        func_003c7bc0(0, tmp);
        func_003c7430(42);
        goto animation_tail;
    }
    case 26:
        func_003c7430(43);
        goto animation_tail;
    case 27:
        func_003c7430(44);
        goto animation_tail;
    case 0:
        goto animation_tail;
    default:
        goto animation_tail;
    }
animation_tail:
    {
        u32 slot_count = BR_U32(work, 0x3408);
        u32 anim_i;
        if (slot_count != 0) {
            for (anim_i = 0; anim_i < BR_U32(work, 0x3418); anim_i++) {
                u32 slot_idx = BR_U32(work, 0x1c + anim_i * 4);
                u8 *card = work + slot_idx * 0x670 + 0x5c;
                f32 delta = (f32)((s32)(anim_i - slot_count));
                f32 scale;
                f32 output[3];
                f32 vec_in[2];
                /* retail 0x1f8fa8-0x1f8fd0: 320.0f + delta * 220.0f */
                vec_in[0] = 320.0f + delta * 220.0f;
                vec_in[1] = 184.0f;
                scale = func_0020c500(card + 0xc, 200.0f);
                func_0020c400(card + 0xc, vec_in, scale, output);
                output[1] = output[1] + 100.0f;
                func_002508c0(card + 0x60c, output, 0x14);
            }
        }
        if (slot_count == BR_U32(work, 0x3418) - 1) {
            BR_U32(work, 0) |= 0x40;
        }
        if ((BR_U32(work, 0) & 0x800) != 0) {
            func_001f9c60();
        }
        if (kind == 9) {
            if ((BR_U32(work, 0) & 0x800) == 0) {
                K_ASSERT(work != NULL, 0x770);
            }
            BR_U32(work, 0x34e4) = 1;
        } else {
            BR_U32(work, 0x34e4) = 0;
        }
    }
}
#pragma optimization_level 2
