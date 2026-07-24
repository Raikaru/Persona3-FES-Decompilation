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
extern u32 sflPanel0023f430(void);
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
extern void func_003c78d0(void);
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
extern void func_00209e10(void);
extern u8 *func_00209e20(void);
extern u8 *func_00209e60(void);
extern u8 *func_00209e70(void);
extern u8 *func_00209dc0(void);
extern u8 *func_00209dd0(void);
extern u8 *func_00209d00(void);
extern u8 *func_00209c40(void);
extern u8 *func_00209c80(void);
extern u8 *func_00209cc0(void);
extern char *func_00209e80(void);
extern char *func_00209e90(void);
extern u32 func_00255130(void);
extern void func_00254e10(void);
extern void sflCard002537f0(u16);
extern void sflCard002536b0(u32, u32);
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
extern void func_0020ac90(void *);
extern u32 sflResult001f99f0(void);
extern void func_001831e0(void);
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
extern void func_0021a120(void);
extern void func_00258300(void);
extern void func_002550b0(void);
extern void *func_0034fcd0(void *);
extern u16 datGetMaxHp(s16);
extern void datSetMoney(u32);
extern void func_001828d0(s16, void *, void *);
extern void func_00182d90(s16, s16, u32, void *);
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
extern u32 D_00684610[];
extern u32 func_001775a0(u32, ...);

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

// FUN_001f13b0 NONMATCHING
#pragma optimization_level 3
void *func_001f13b0(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    u32 oldLevel = datGetLevel(1);
    u32 newLevel;
    u32 i;
    BR_U32(work, 0xbc) = oldLevel;
    newLevel = func_0016d280(datGetNextExp(1));
    datSetLevel(1, (u8)newLevel);
    BR_U32(work, 0xc0) = datGetLevel(1);
    if (oldLevel != newLevel) {
        BR_U32(work, 0) |= 8;
        if (newLevel > 0 && !datGetFlag(0x120c)) {
            datSetFlag(0x120c, 1);
            BR_U32(work, 0) |= 0x40000;
        }
        if (newLevel >= 10 && !datGetFlag(0x120d)) {
            datSetFlag(0x120d, 1);
            BR_U32(work, 0) |= 0x40000;
        }
        if (newLevel >= 20 && !datGetFlag(0x1201)) {
            datSetFlag(0x1201, 1);
            BR_U32(work, 0) |= 0x40000;
        }
        if (newLevel >= 30 && !datGetFlag(0x1202)) {
            datSetFlag(0x1202, 1);
            BR_U32(work, 0) |= 0x40000;
        }
    }
    BR_U32(work, 0xec) = 0;
    for (i = 0; i < func_001756f0(); i++) {
        DatPersonaWork *persona = datPersonaGetHeroPersona((s16)i);
        if (persona == NULL) {
            continue;
        }
        if (persona->id == datGetPersonaId(1)) {
            datPersonaAddExp(persona, (s32)BR_U32(work, 0x2a50));
        } else {
            u16 *skills = datPersonaGetSkills(persona);
            u32 skillCount = datPersonaCountValidSkills(persona);
            u32 skill = 0;
            while (skill < skillCount && skills[skill] != 0x22b) {
                skill++;
            }
            if (skill == skillCount) {
                skill = 0;
                while (skill < skillCount && skills[skill] != 0x22a) {
                    skill++;
                }
            }
            if (skill == skillCount) {
                skill = 0;
                while (skill < skillCount && skills[skill] != 0x229) {
                    skill++;
                }
            }
            if (skill < skillCount) {
                datPersonaAddExp(persona, (s32)func_001fbfa0(datPersonaGetLevel(persona),
                    BR_U32(work, 0x2a54), BR_U32(work, 0xb8), skills[skill],
                    BR_U32(work, 0x2a58), BR_U32(work, 0x11c)));
            }
        }
    }
    for (i = 0; i < BR_U32(work, 0x114); i++) {
        u16 pc = BR_U16(work, 0x10c + i * 2);
        u32 exp = func_001fbdf0(datGetLevel((s16)pc), BR_U32(work, 0x2a54),
                                BR_U32(work, 0xb8), BR_U32(work, 0x2a58), BR_U32(work, 0x11c));
        func_001f9e90(pc, exp);
    }
    if (datGetFlag(0x140)) {
        DatPersonaWork *p = datPersonaGetByPcId(6);
        if (p != NULL) {
            datPersonaAddExp(p, (s32)func_001fbdf0(datPersonaGetLevel(p),
                BR_U32(work, 0x2a54), BR_U32(work, 0xb8), BR_U32(work, 0x2a58), BR_U32(work, 0x11c)));
            BR_U32(work, 0x150) = 0;
            /* The skill table is generated by the battle-data helper. */
            if (func_00175ce0(p, (u16 *)(work + 0x158)) != 0) {
                BR_U32(work, 0) |= 4;
            }
            func_00176100(p, (u16 *)(work + 0x158));
        }
    }
    BR_U32(work, 0xec) = 0;
    for (i = 0; i < func_001756f0(); i++) {
        DatPersonaWork *p = datPersonaGetHeroPersona((s16)i);
        if (p != NULL && func_001761b0(p) != 0 && BR_U32(work, 0xec) < 8) {
            BR_U16(work, 0xd4 + BR_U32(work, 0xec) * 2) = p->id;
            BR_U32(work, 0xec)++;
        }
    }
    if (BR_U32(work, 0xec) != 0) {
        BR_U32(work, 0) |= 0x20;
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
    u32 state;
    /* All child systems are advanced before the state transition. */
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
    state = BR_U32(work, 8);
    switch (state) {
    case 0:
        if (sflRes0020dfe0() == 0 && func_00254f20() == 0 && BR_U32(work, 0x2a210) != 0) {
            func_00254f70();
            if (BR_U32(work, 0xe4) == 0) {
                func_003c72d0(sflRes0020e790());
                func_0023d130();
                sflRes0020e3d0();
                sflRes0020eb40();
            }
            func_0023ee50();
            sflCard00259250();
            BR_U32(work, 8) = 2;
        }
        break;
    case 1:
        if (sflGround0023d1f0() == 0 && sflCard002592c0() == 0) {
            BR_U32(work, 8) = func_001f4990() ? 4 : 3;
        }
        break;
    case 2:
        if (sflCard002582b0() == 0) {
            sflScript00259640();
            BR_U32(work, 0x1fd5c) = 0;
            BR_U32(work, 8) = 8;
        }
        break;
    case 3:
        if (sflCard00258af0() == 0) {
            func_001f55e0();
        }
        break;
    case 4:
        if (sflRes0020e4c0() == 0) {
            func_001f4750(task);
            sflCard002580e0();
        }
        break;
    case 5:
        if (sflRes0020e9b0() == 0) {
            func_003c77a0();
            func_003c7430(0);
            BR_U32(work, 8) = 5;
        }
        break;
    case 6:
        if (sflRes0020e4c0() == 0) {
            func_001f53a0();
        }
        break;
    case 8:
        if (sflCount0025b640() != 0) {
            sflCount0025b5f0();
            sflCursor0025aa70();
            func_001f56b0();
            sflCard00258490();
            func_00256030();
            func_003c7650(0);
            BR_U32(work, 4) &= ~0x220u;
            BR_U32(work, 8) = 9;
        }
        break;
    case 9:
        if (sflCard002561d0(work) != 0) {
            BR_U32(work, 4) &= ~0x200u;
        }
        if ((BR_U32(work, 4) & 0x200) != 0) {
            BR_U32(work, 8) = 0x12;
        } else if (sflRes0020e4c0() == 0) {
            func_001f53a0();
        }
        break;
    case 10:
        if (sflRes0020e4c0() == 0) {
            func_0010a4e0(1, 15, 6, 13);
            BR_U32(work, 8) = 0x0e;
        }
        break;
    case 11:
        if (sflPanel0023f390() == 0 && sflGround0023d0e0() == 0) {
            func_001f4750(task);
            BR_U32(work, 8) = 0x0f;
        }
        break;
    case 12:
        if (sflCard00259380() == 0) {
            BR_U32(work, 0xe4)++;
            func_00255fe0();
            func_002550b0();
            func_00258300();
            func_001f3270(task);
            BR_U32(work, 8) = 0x0f;
        }
        break;
    case 13:
        if (func_003c7850() == 0) {
            BR_U32(work, 8) = 0x0f;
        }
        break;
    case 14:
        if (sflRes0020e4c0() == 0) {
            func_001f5510();
            BR_U32(work, 8) = 0x10;
        }
        break;
    case 15:
        if (func_003c7850() == 0) {
            func_001f4750(task);
        }
        break;
    case 17:
        if (func_001f65e0() == 0) {
            BR_U32(work, 8) = 0x17;
        }
        break;
    case 18:
        if (sflRes0020e4c0() == 0) {
            func_001f5510();
        }
        break;
    case 19:
        if (sflPanel0023f390() == 0) {
            func_0010a4e0(1, 2, 6, 13);
            BR_U32(work, 8) = 0x14;
        }
        break;
    case 20:
        if (func_003c7850() == 0) {
            BR_U32(work, 8) = 0x15;
        }
        break;
    case 21:
        if (func_003c7850() == 0) {
            BR_U32(work, 8) = 0x16;
        }
        break;
    case 22:
        if (func_003c7850() == 0) {
            BR_U32(work, 8) = 0x17;
        }
        break;
    case 23:
        if (func_003c7850() == 0) {
            func_001f53a0();
        }
        break;
    case 24:
        func_001f53a0();
        break;
    case 25:
        if (func_003c7850() == 0) {
            func_001f53a0();
        }
        break;
    default:
        K_ASSERT(state < 0x1a, 0x1da);
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

// FUN_001f3270 NONMATCHING
void func_001f3270(KwlnTask *task)
{
    u8 *work = BR_TASK_WORK(task);
    u32 count;
    u32 i;
    u32 mode = BR_U32(work, 0x58) & 3;
    /* Build the card candidates from the data tables, then let sflCard own
     * the weighted selection.  This mirrors the retail ordering and keeps
     * all card nodes in the shared card work area. */
    func_00209e10();
    func_00209e20();
    func_00209e60();
    func_00209e70();
    func_00209dd0();
    count = BR_U32(work, 0xe4);
    if (count > 5) {
        count = 5;
    }
    for (i = 0; i < count; i++) {
        u16 id = (u16)(0x2e + i);
        s32 value = (s32)datGetLevel(1) - (s32)i;
        if (value < 1) {
            value = 1;
        }
        if (mode == 1 && i == 0) {
            sflCard002536b0(id, 1);
        } else {
            sflCard002537f0(id);
        }
    }
    if (count == 0) {
        sflCard002537f0(0x2e);
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
    s32 groupSize[4];
    u32 enabled[4];
    volatile u32 framePad[8];
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
    ratio0 = (f32)(s32)valueTable[0];
    ratio1 = (f32)(s32)valueTable[1];
    ratio2 = (f32)(s32)valueTable[2];
    maxProgress = ratio0 + ratio1 + ratio2;
    ratio0 = (f32)(s32)valueTable[0] / maxProgress;
    ratio1 = (f32)(s32)valueTable[2] / maxProgress;
    ratio2 = (f32)(s32)valueTable[1] / maxProgress;
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

    maxProgress = (f32)(s32)actTable[2] +
                  (f32)(RpRandom() % 1);
    framePad[0] = actTable[0];
    framePad[1] = actTable[2];
    framePad[2] = actTable[2];
    framePad[3] = actTable[1];
    if (actTable[0] == 0 && actTable[2] != 0) {
        framePad[0] = 1;
    }
    framePad[7] = 0;

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

        sflScript00259c60((u16)((f32)actTable[0] +
                                progress * ((f32)actTable[1] -
                                            (f32)actTable[0]) / maxProgress));
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
                totalWeight += framePad[i];
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
                random -= framePad[i];
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
void *func_001f5b20(void)
#pragma optimization_level 3
{
    u8 *work = sBrReward;
    u32 state;
    if (work == NULL) {
        return KWLNTASK_CONTINUE;
    }
    state = BR_U32(work, 4);
    switch (state) {
    case 0:
        if ((BR_U32(work, 0) & 0x40) != 0 && (BR_U32(work, 0) & 0x10) != 0) {
            func_003c7990(0);
            if (func_003c7850() == 0) {
                BR_U32(work, 4) = 1;
            }
        }
        break;
    case 1:
        if (func_003c7850() == 0) {
            BR_U32(work, 0x3510)++;
            if (BR_U32(work, 0x3510) < BR_U32(work, 0x3514)) {
                func_003c7bc0(0, BR_U32(work, 0x34ec + BR_U32(work, 0x3510) * 8));
                func_003c7c20(1, BR_U32(work, 0x34e8 + BR_U32(work, 0x3510) * 8), 0);
                func_003c7430(0x17);
            } else {
                BR_U32(work, 0x3408)++;
                if (BR_U32(work, 0x3408) >= BR_U32(work, 0x3418)) {
                    func_001f6a60();
                } else {
                    func_001f7210();
                }
            }
        }
        break;
    case 2:
        if (func_003c7850() == 0) {
            BR_U32(work, 0x3510)++;
            if (BR_U32(work, 0x3510) >= BR_U32(work, 0x3514)) {
                BR_U32(work, 0x3408)++;
                if (BR_U32(work, 0x3408) >= BR_U32(work, 0x3418)) {
                    func_001f6a60();
                } else {
                    func_001f7210();
                }
            }
        }
        break;
    case 3:
        if (func_003c7850() == 0) {
            func_001f6a60();
        }
        break;
    case 4:
        if (func_003c7850() == 0) {
            func_001f7170();
        }
        break;
    case 5:
        func_001f7030();
        break;
    case 6:
        func_001f70d0();
        break;
    case 7:
        func_001f6e80();
        break;
    case 8:
        func_001f6630();
        break;
    default:
        K_ASSERT(state < 9, 0x341);
        break;
    }
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

// FUN_001f6630 NONMATCHING
void func_001f6630(void)
{
    u8 *work = sBrReward;
    u32 i;
    K_ASSERT(work != NULL, 0x8c);
    BR_U32(work, 0x340c) = 0;
    BR_U32(work, 0x3408) = 0;
    BR_U32(work, 0x3410) = 0;
    BR_U32(work, 0x3414) = 0;
    BR_U32(work, 0x3404) = 0;
    BR_U32(work, 0x3400) = 0;
    if (BR_U32(work, 0x341c) != 0) {
        BR_U32(work, 0) |= 8;
        for (i = 0; i < BR_U32(work, 0x341c) && i < 8; i++) {
            BR_U16(work, 0x33f0 + i * 2) = BR_U16(work + BR_U32(work, 0x3c + i * 4) * 0x670, 0x60);
        }
        BR_U32(work, 0x3404) = BR_U32(work, 0x341c);
    }
    if (BR_U32(work, 0x3418) != 0) {
        BR_U32(work, 0) |= 0x20;
    }
    BR_U32(work, 0) |= 0x400;
    BR_U32(work, 4) = 1;
    func_001f6a60();
}

// FUN_001f6a60 NONMATCHING
void func_001f6a60(void)
{
    u8 *work = sBrReward;
    K_ASSERT(work != NULL, 0x8c);
    switch (BR_U32(work, 4)) {
    case 0:
        if ((BR_U32(work, 0) & 8) != 0) {
            sflResult001f99f0();
        } else {
            BR_U32(work, 4) = 2;
        }
        break;
    case 1:
        if ((BR_U32(work, 0) & 0x10) != 0) {
            BR_U32(work, 4) = 3;
        } else {
            BR_U32(work, 4) = 2;
        }
        break;
    case 2:
        BR_U32(work, 4) = 3;
        break;
    case 3:
        if (BR_U32(work, 0x3404) != 0) {
            func_001f7030();
        } else {
            BR_U32(work, 4) = 8;
        }
        break;
    case 4:
        func_001f7170();
        break;
    case 5:
        func_001f7030();
        break;
    case 6:
        func_001f70d0();
        break;
    case 7:
        func_001f6e80();
        break;
    case 8:
        func_003c77a0();
        func_001831e0();
        BR_U32(work, 4) = 0;
        break;
    default:
        K_ASSERT(BR_U32(work, 4) < 9, 0x341);
        break;
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
    u32 i;
    K_ASSERT(work != NULL, 0x8c);
    for (i = 0; i < BR_U32(work, 0x341c); i++) {
        u32 idx = BR_U32(work, 0x3c + i * 4);
        func_0020c500(work + idx * 0x670 + 0x68, 0x43480000);
    }
    if (BR_U32(work, 0x340c) < BR_U32(work, 0x341c)) {
        u32 idx = BR_U32(work, 0x3c + BR_U32(work, 0x340c) * 4);
        func_003c7bc0(0, func_00173220(BR_U16(work + idx * 0x670, 0x60)));
        func_003c7430(9);
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
    u8 *entry;
    u32 kind = 0;
    s32 value = 0;
    u32 i;
    K_ASSERT(work != NULL, 0x8c);
    slot = BR_U32(work, 0x3408);
    entry = work + slot * 0x670 + 0x60;
    switch (BR_U32(entry, 0)) {
    case 0:
        /* Recovery/status reward: choose a party member which can benefit. */
        if (BR_U32(entry, 4) != 0) {
            kind = 14 + (BR_U32(entry, 4) % 13);
            value = BR_S32(entry, 8);
        } else {
            kind = 0x1b;
            value = 1;
        }
        break;
    case 1:
        kind = 1 + (BR_U32(entry, 4) % 5);
        value = BR_S16(entry, 8);
        break;
    case 2:
        kind = 6;
        value = BR_S32(entry, 8);
        break;
    case 3:
        kind = 14 + (BR_U32(entry, 4) % 13);
        value = BR_S16(entry, 8);
        break;
    default:
        return;
    }
    switch (kind) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5: {
        DatPersonaWork *persona = datPersonaGetByPcId(1);
        if (persona != NULL) {
            datPersonaAddToNaturalStat(persona, (u16)(kind - 1), (s8)value);
        }
        break;
    }
    case 6: {
        u32 money = datGetMoney();
        if ((s32)money + value < 0) {
            money = 0;
        } else if ((u32)value > 0x989680u - money) {
            money = 0x98967fu;
        } else {
            money += (u32)value;
        }
        datSetMoney(money);
        break;
    }
    case 7: {
        u16 hp = datGetHp(1);
        u16 maxHp = datGetMaxHp(1);
        u32 result = hp + (u32)((s32)maxHp * value / 100);
        datSetHp(1, (u16)(result > maxHp ? maxHp : result));
        break;
    }
    case 8: {
        u16 sp = datGetSp(1);
        u16 maxSp = (u16)func_0016c670(1);
        u32 result = sp + (u32)((s32)maxSp * value / 100);
        datSetSp(1, (u16)(result > maxSp ? maxSp : result));
        break;
    }
    case 9:
        datSetBadStatus(1, datGetBadStatusNoDown(1) & ~0x80u);
        break;
    case 10:
        datSetPhysicalCondition(1, 0);
        break;
    case 11:
        datSetPhysicalCondition(1, 2);
        break;
    case 12:
        datSetPhysicalCondition(1, 3);
        break;
    case 13:
        datSetPhysicalCondition(1, 4);
        break;
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
        func_003c7bc0(0, func_00173220((u16)value));
        func_003c7430((s32)kind);
        break;
    case 27:
        func_003c7430(0x1b);
        break;
    default:
        break;
    }
    /* Keep the selected reward for the script and advance the current item. */
    BR_U32(work, 0x34c0) = kind;
    BR_U32(work, 0x34c4) = (u32)value;
    for (i = 0; i < BR_U32(work, 0x341c); i++) {
        u32 idx = BR_U32(work, 0x3c + i * 4);
        if (idx == slot) {
            BR_U32(work, idx * 0x670 + 0x60) = kind;
        }
    }
    if (slot + 1 >= BR_U32(work, 0x3418)) {
        BR_U32(work, 0) |= 0x40;
    }
    BR_U32(work, 0x34e4) = (kind == 9) ? 1 : 0;
}
#pragma optimization_level 2
