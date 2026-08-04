#include "Main/Social/sfl_res.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"
#include "Main/Social/sfl_psel.h"

extern u8* func_00209d00(void);
extern void func_0021a670(u32, u32);
extern void func_0021a760(u16);
extern f32 func_0020c500_y2(float, void*);
extern void func_0020c400_y2(void*, float*, f32, const float*);
extern void func_004bdde0(float, float*, const float*, u32);
extern void func_001f6630(void);
extern void func_001f7210(void);
extern void func_0034ff90(u32, const u8*);
extern void func_0034ff70(u32, float);
extern void func_0034fdf0(u32, const float*);
extern void func_0034fe30(float, u32, float, float);
extern void func_0034fd30(u32);
extern void func_0034fd70(u32, u32);
extern void datSetFlag(s32, u8);
extern u32 func_001761b0(DatPersonaWork*);
extern void func_00175ce0(DatPersonaWork*, u8*);
extern void func_00176100(DatPersonaWork*, u8*);
extern void func_001fb4b0(void*, s32, s32, s32, s32*, s32*);
extern u32 func_001fba70(u16);
extern void func_00176840(DatPersonaWork*, u16);
extern void func_001768e0(DatPersonaWork*, u16);
extern u8* iGpffffb740;
extern u8* iGpffffb730;
void func_001fa0d0(void);
void func_001fa450(void);
void func_001fa4f0(u32 param_1);
u32 func_001faea0(void);
void func_001fb130(u64 param_1,u64 param_2);
void func_001fb1b0(u64 param_1,u64 param_2);
void func_001fb1f0(DatPersonaWork* persona, u16* output, s32* outputCount);
void func_001fb3f0(int param_1,int param_2,int param_3,int *param_4,int *param_5);
u16 func_001fb560(u32 param_1);
u32 func_001fba70(u16 param_1);
int func_001fbca0(u16 param_1);
u8 * func_001fbd50(u16 param_1,int param_2);
int func_001fbdf0(s32 start, s32 end, s32 amount, s32 category, s32 scaleMode);
int func_001fbfa0(int param_1,int param_2,int param_3,short param_4,int param_5,long param_6);
void func_001fc1f0(void);
u8 func_001fc230(DatPersonaWork* persona);
u32 func_001fc3c0(DatPersonaWork* persona);
u32 func_001fc590(u8* event, void* target);
u32 func_001fc720(u8* persona);
int func_001fc870(u8* event, void* target);
void func_001fc980(u8* event, u16* result, s32* count);
void func_001fcb30(u8* event, u32* result, s32* count);
void func_001fccc0(u8* src, u8* dst, u32 skill);
void func_001fce20(u8* persona, u16* skills, s32 count);
void func_001fd350(u8* persona, u32* skills, s32 count);
extern s16 FUN_001706c0(s16 pcId, s16 index);
extern u8* pbGpffffb758;
extern u16* puGpffffb74c;
extern u16* puGpffffb730;
extern u16* puGpffffb750;
extern u16* psGpffffb754;
extern char gp0xffff9700[];
extern char gp0xffff9708[];
extern char gp0xffff9710[];
extern u8* DAT_007ce420;
extern u8* DAT_007ce428;
extern u8* DAT_007ce430;
extern u8* iGpffffb738;
extern int iGpffffb75c;
extern int iGpffffb760;
#pragma alias sflResultMsgC28_abs DAT_00684c28
#pragma alias sflResultMsgC40_abs DAT_00684c40
#pragma alias sflResultMsgC60_abs DAT_00684c60
#pragma alias sflResultMsgC70_abs DAT_00684c70
#pragma alias sflResultMsgC80_abs DAT_00684c80
#pragma alias sflResultMsgC90_abs DAT_00684c90
#pragma alias sflResultMsgCA0_abs DAT_00684ca0
#pragma alias sflResultMsgCD0_abs DAT_00684cd0
#pragma alias sflResultMsgCE0_abs DAT_00684ce0
#pragma alias sflResultMsgCF8_abs DAT_00684cf8
#pragma alias sflResultMsgD08_abs DAT_00684d08
#pragma alias sflResultMsgD20_abs DAT_00684d20
#pragma alias sflResultMsgD30_abs DAT_00684d30
#pragma alias sflResultMsgD40_abs DAT_00684d40
extern const char sflResultMsgC28_abs[];
extern const char sflResultMsgC40_abs[];
extern const char sflResultMsgC60_abs[];
extern const char sflResultMsgC70_abs[];
extern const char sflResultMsgC80_abs[];
extern const char sflResultMsgC90_abs[];
extern const char sflResultMsgCA0_abs[];
extern const char sflResultMsgCD0_abs[];
extern const char sflResultMsgCE0_abs[];
extern const char sflResultMsgCF8_abs[];
extern const char sflResultMsgD08_abs[];
extern const char sflResultMsgD20_abs[];
extern const char sflResultMsgD30_abs[];
extern const char sflResultMsgD40_abs[];
#pragma alias sflResultAssertBA8_abs DAT_00684ba8
extern const char sflResultAssertBA8_abs[];
extern int iGpffffb764;
extern int iGpffffb768;
extern int iGpffffb76c;
extern int iGpffffb770;
extern int iGpffffb774;
extern int iGpffffb778;
extern u8* iGpffffb7ac;
extern u8* iGpffffb7b8;
extern f32 fGpffff8070;
extern f32 fGpffff83b0;
extern f32 fGpffff83b4;
extern u8* pcGpffffb75c;
extern u8* pcGpffffb760;
extern u8* pcGpffffb764;
extern u8* pcGpffffb768;
extern u8* pcGpffffb76c;
extern u8* pcGpffffb770;
extern u8* pcGpffffb774;
extern u8* pcGpffffb778;
extern u8 DAT_00684a10[];
extern u8 DAT_00684d70[];
#pragma alias DAT_00684d60 DAT_00684d70
extern u8 DAT_00684d60[];
#pragma alias FUN_00182c50_typed FUN_00182c50
extern void FUN_00182c50_typed(s16 skill, u8* dst);
extern void FUN_001831e0_typed(s16 slot, u32 index, u8* dst);
#pragma alias FUN_0016da50_typed FUN_0016da50
extern void FUN_0016da50_typed(s16 slot, s16 type, s16 index);
#define FUN_00182c50 FUN_00182c50_typed
#define FUN_001831e0 FUN_001831e0_typed
#define FUN_0016da50 FUN_0016da50_typed
#undef FUN_00182c50
#undef FUN_001831e0
#undef FUN_0016da50
#include "Main/Battle/Result/br_panel.h"
#include "Main/Battle/Result/br_res.h"
#include "Main/Social/sfl_script.h"
#include "h_fade.h"
#include "rw/rwcore.h"
#include "rw/rprandom.h"
#pragma alias sflResGetTutorialFileUnchecked FUN_0020ea00
extern void* sflResGetTutorialFileUnchecked();
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
extern u32 func_00175ce0_y2(DatPersonaWork *, u16 *);
extern u32 func_001761b0_y2(DatPersonaWork *);
extern u32 func_00176100_y2(DatPersonaWork *, u16 *);
extern u32 func_001fbdf0_y2(u32, u32, u32, u32, u32);
extern u32 func_001fbfa0_y2(u32, u32, u32, u32, u32, u32);
extern u32 func_001f9e90(u16, u32);
extern void func_001fb4b0_y2(void *, s32, s32, s32, s32 *, s32 *);
extern u8 *DAT_007ce430_y2;
extern u32 func_001f9680(s32 *);
extern void func_001f9c60(void);
extern u32 func_001f9a80(void);
extern void func_001f98d0(void);
extern void sflResult001f9770_y2(u16 *, s32 *);
extern void sflResult001f9800_y2(u16 *, s32 *);
extern u32 sflResult001f9890_y2(void);
extern void sflResult001f9630_y2(void);
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
extern u8 *func_00209d00_y2(void);
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
extern void func_004bdde0_y2(f32, f32 *, const f32 *, u32);
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
extern u16 datGetMaxHp_y2(s16);
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
void brRewardAdvanceState(void);
void brRewardAnimateCurrentEntry(void);
void brRewardRegisterEntry(const f32 *);
void func_001f7030(void);
void func_001f70d0(void);
void func_001f7170(void);
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
#pragma alias brRewardAdvanceState func_001f6a60
#pragma alias brRewardRegisterEntry func_001f6d20
#pragma alias brRewardAnimateCurrentEntry func_001f6e80


#pragma alias func_0020c500_y2 func_0020c500
#pragma alias func_0020c400_y2 func_0020c400
#pragma alias sflResSetSpriteScale_y2 sflResSetSpriteScale
#pragma alias sflResSetSpriteRotation_y2 sflResSetSpriteRotation
#pragma alias sflResult001f99f0_y2 sflResult001f99f0
#pragma alias sflResult001f9100_y2 sflResult001f9100
#pragma alias sflResSetSpritePosition_y2 sflResSetSpritePosition
#pragma alias func_00175ce0_y2 func_00175ce0_y2
#pragma alias func_001761b0_y2 func_001761b0_y2
#pragma alias func_00176100_y2 func_00176100_y2
#pragma alias func_001fbdf0_y2 func_001fbdf0_y2
#pragma alias func_001fbfa0_y2 func_001fbfa0_y2
#pragma alias func_001fb4b0_y2 func_001fb4b0_y2
#pragma alias DAT_007ce430_y2 DAT_007ce430_y2
#pragma alias sflResult001f9770_y2 sflResult001f9770_y2
#pragma alias sflResult001f9800_y2 sflResult001f9800_y2
#pragma alias sflResult001f9890_y2 sflResult001f9890_y2
#pragma alias sflResult001f9630_y2 sflResult001f9630_y2
#pragma alias func_00209d00_y2 func_00209d00_y2
#pragma alias func_004bdde0_y2 func_004bdde0_y2
#pragma alias datGetMaxHp_y2 datGetMaxHp_y2


static u32* sSflResult; // iGpffffb5f0 / puGpffffb5f0

extern void brRoot001f1df0(u16* members, s32* count);
extern u16 datGetHp(s16 pcId);
extern u16 datGetMaxHp(s16 pcId);
extern u16 datGetSp(s16 pcId);
extern u16 func_0016c670(s16 pcId);
extern void FUN_001f6e80(void);

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
            brRewardAdvanceState();
        } else {
            brRewardAnimateCurrentEntry();
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
        brRewardAdvanceState();
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
            brRewardAdvanceState();
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
            brRewardAdvanceState();
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
            if (BR_U32(work, 0) & 0x800) {
                func_001f9c60();
            }
            func_003c7650(s0_val);
            if (BR_U32(work, 0) & 0x800) {
                func_0034fcf0((void *)BR_U32(work, 0x34e0));
                BR_U32(work, 0) &= ~0x800u;
            }
            cnt = BR_S32(work, 0x3408) + 1;
            BR_S32(work, 0x3408) = cnt;
            if (cnt == BR_S32(work, 0x3418)) {
                brRewardAdvanceState();
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
                func_003c7bc0(0, ((u32 *)DAT_00684a10)[idx]);
                func_003c7c20(1, BR_U32(work, 0x34ec + cnt * 8), 0);
                func_003c7430(0x17);
            } else {
                if (cnt == BR_S32(work, 0x3418)) {
                    brRewardAdvanceState();
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
                brRewardAdvanceState();
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
            brRewardAdvanceState();
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
                col[3] = (u8)t;
                func_0020cc80(entry + 0xc, col);
                gcPose0024f960(entry + 0x60c, &temp);
                sflResSetSpritePosition(entry + 0xc, &temp);
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
                col[3] = (u8)t;
                func_0020cc80(entry + 0xc, col);
                gcPose0024f960(entry + 0x60c, &temp);
                sflResSetSpritePosition(entry + 0xc, &temp);
                func_0020ac90(entry + 0xc);
            }
        }
    }
final_exit:
    return KWLNTASK_CONTINUE;
}

// FUN_001f64c0
void func_001f64c0(void)
{
    u8 *work;
    s32 flags;
    s32 i;

    K_ASSERT(sBrReward != NULL, 0x8c);
    work = sBrReward;
    flags = ~BR_U32(work, 0);
    if ((flags & 1) == 0) {
        switch (BR_U32(work, 8)) {
        case 1:
            if ((flags & 0x400) == 0) {
                for (i = 0; i < (s32)BR_U32(work, 0x341c); i++) {
                    u32 idx = BR_U32(work + i * 4, 0x3c);
                    u32 address = idx * 0x670;
                    address = (u32)(work + address);
                    address += 0x5c;
                    func_0020b250((u8 *)address + 0xc);
                }
                for (i = 0; i < (s32)BR_U32(work, 0x3418); i++) {
                    u32 idx = BR_U32(work + i * 4, 0x1c);
                    u32 address = idx * 0x670;
                    address = (u32)(work + address);
                    address += 0x5c;
                    func_0020b250((u8 *)address + 0xc);
                }
            }
            break;
        }
    }
}

// FUN_001f65e0
u32 func_001f65e0(void)
{
    K_ASSERT(sBrReward != NULL, 0x8c);
    return BR_U32(sBrReward, 0) & 1;
}






/* SocialA W417 negative: swapping work/i declarations in func_001f6630 was byte-identical (nd 586, object 1060/1072); retained source order. */
/* W389 measured sflResult001f9170 opt_lifetimes on: nd 471 -> 465; object 1212/1216 -> 1212/1216. */
// FUN_001f6630 NONMATCHING
void func_001f6630(void)
{
    u32 *work;
    s32 i;

    K_ASSERT(sBrReward != NULL, 0x8c);
    work = (u32 *)sBrReward;
    work[0xd03] = 0;
    work[0xd02] = 0;
    work[0xd04] = 0;
    work[0xd05] = 0;
    work[0xd01] = 0;
    work[0xd00] = 0;
    if (work[0xd07] != 0) {
        s32 available;
        s32 copyIndex;

        work[0] |= 8;
        available = func_001756f0() & 0xffff;
        if ((s32)(func_00175410() & 0xffff) < available + (s32)work[0xd07]) {
            work[0] |= 0x10;
        } else {
            K_ASSERT(work[0xd07] < 9, 0x272);
            for (copyIndex = 0; copyIndex < (s32)work[0xd07]; copyIndex++) {
                *(u16 *)((u8 *)work + 0x33f0 + copyIndex * 2) =
                    *(u16 *)((u8 *)work +
                             ((u32 *)((u8 *)work + 0x3c))[copyIndex] * 0x670 + 0x60);
            }
            work[0xd01] = work[0xd07];
        }
    }
    if (work[0xd06] != 0) {
        work[0] |= 0x20;
    }
    switch (work[2]) {
    case 1:
    {
        f32 output[12];
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
                sflResSetSpriteScale(entry + 0xc, scale);
                func_004bdde0_y2(180.0f, rotation, axis, 0);
                sflResSetSpriteRotation(entry + 0xc, rotation);
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
    brRewardAdvanceState();
}

/* Removing this loses FUN_001f9680 (MATCH nd0 -> MISMATCH nd57) - measured W161. */
// FUN_001f6a60
void brRewardAdvanceState(void)
{
    u8 *work;
    s32 i;
    u32 state;
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
            switch (result) {
            case 0:
                K_ASSERT(0, 0x32d);
                goto result_default;
            case 1:
                BR_U32(work, 4) = 8;
                return;
            case 2:
                state = 8;
                break;
            default:
            result_default:
                K_ASSERT(0, 0x337);
                goto state_default;
            }
            break;
        case 8:
            func_003c72d0(sflResGetBaseSpriteData());
            K_ASSERT(sBrReward != NULL, 0x8c);
            work = sBrReward;
            BR_U32(work, 0) &= ~1u;
            BR_U32(work, 4) = 9;
            return;
        default:
        state_default:
            K_ASSERT(0, 0x341);
            break;
        }
    }
}

// FUN_001f6d20
void brRewardRegisterEntry(const f32 *entry)
{
    u8 *work;
    u32 *words;
    u8 *dst;
    RwV3d value;

    K_ASSERT(sBrReward != NULL, 0x8c);
    work = sBrReward;
    words = (u32 *)work;
    K_ASSERT((s32)words[0xcf7] >= 0 &&
             (s32)words[0xcf7] < 8,
             0x34d);
    dst = work + words[0xcf7] * 0x670;
    value = *(const RwV3d *)entry;
    *(RwV3d *)(dst + 0x5c) = value;

    switch (*(const u32 *)entry) {
    case 0:
        K_ASSERT((s32)words[0xd07] < 8, 0x355);
        words[words[0xd07] + 0xf] = words[0xcf7];
        words[0xd07]++;
        break;
    case 1:
        K_ASSERT((s32)words[0xd06] < 8, 0x35a);
        words[words[0xd06] + 7] = words[0xcf7];
        words[0xd06]++;
        break;
    }
    words[0xcf7]++;
}

// FUN_001f6e80
void brRewardAnimateCurrentEntry(void)
{
    u8 *work;
    u32 *words;
    s32 i;
    u32 idx;
    u32 offset;
    u8 *entry;
    f32 position[2];
    f32 output[3];
    f32 scale;
    K_ASSERT(sBrReward != NULL, 0x8c);
    work = sBrReward;
    words = (u32 *)work;
    if (BR_U32(work, 0x340c) != 0) {
        for (i = 0; i < BR_S32(work, 0x341c); i++) {
            idx = BR_U32(work + i * 4, 0x3c);
            entry = work + idx * 0x670 + 0x5c;
            position[0] = (f32)(i - BR_S32(work, 0x340c)) * 220.0f + 320.0f;
            position[1] = 184.0f;
            scale = func_0020c500(entry + 0xc, 200.0f);
            func_0020c400(entry + 0xc, position, scale, output);
            output[1] += 100.0f;
            func_002508c0(entry + 0x60c, output, 0x14);
        }
    }
    offset = words[0xd03] * 4;
    idx = BR_U32((u8 *)(offset + (u32)work), 0x3c);
    offset = idx * 0x670;
    entry = (u8 *)(offset + (u32)work);
    func_003c7bc0(0, func_00173220(BR_U16(entry, 0x60)));
    func_003c7430(9);
    if (BR_U32(work, 0x340c) == BR_U32(work, 0x341c) - 1) {
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


/* W389 measured sflResult001f9e90 opt_propagation off: nd 318 -> 317; object 572/576 -> 572/576. */


/* W389 measured func_001faea0 opt_common_subs off: nd 325 -> 303; object 652/656 -> 656/656. */






// W389 residual nd2: the sole differing instruction is commutative mul.s operand order (retail f0*f1 vs. ours f1*f0); this is a documented compiler floor.
/* W389 measured func_001fbfa0 opt_dead_assignments off: nd 260 -> 219; object 580/592 -> 584/592. */







/*
 * Battle-result tasks deliberately use byte offsets.  The retail work areas
 * are private to the result system and are shared by several child tasks;
 * keeping the offsets here avoids inventing public layouts for those areas.
 */



/* Result-resource and data helpers not yet described by public headers. */
 






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





















/* Retail 0x1f13f0-0x1f1a64: level-up propagation, hero/party EXP, and
 * newly learned-skill collection. */










#pragma opt_propagation reset












/* Retail 0x1f3270-0x1f4648: reconstructed result-card selection and reward dispatch. */

















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
void func_001f7210(void)
{
    u8 *work;
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
    u32 weightTable[25];
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
    K_ASSERT(sBrReward != NULL, 0x8c);
    work = sBrReward;
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
        res_base = (u8 *)func_00209d00_y2();
        printf("money : %d\n", BR_S32(entry, 4));
        effect_table = res_base + BR_U32(entry, 4) * 26;
        func_0010a4e0(1, 0, 6, 9);
        res_base = (u8 *)sflResGetBaseDataFile(1);
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
                func_001828d0_2arg((s16)selected_id, (void *)card_buf);
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

// FUN_001f9100
void sflResult001f9100_y2(void)
{
    u8* p;

    K_ASSERT(sSflResult != NULL, 0x8c);
    p = (u8*)sSflResult;
    func_00217410((u16*)(p + 0x33f0), (s32*)(p + 0x3404));
    func_002174d0((u16*)(p + 0x33e0), (s32*)(p + 0x3400));
    func_00216800();
}

/* W418 rate choice: direct-return rewrites for cases 8+12 improved 465/1212B (0.3837) to 400/1188B (0.3367); case 10 was reverted because its 444/1200B (0.3700) combination was worse. Cases 1/3 direct-return probes regressed to nd632/1168B and nd495/1168B. */
#pragma push
#pragma opt_lifetimes on
// FUN_001f9170
u32 sflResult001f9170(u32 player)
{
    s32 j;
    char* flags;
    s32 i;
    s16 members[6];
    s32 memberCount;
    flags = (char*)func_00209d00() + player * 0x1a;
    i = 0;
    for (; i < 0xd; i++) {
        if (flags[i * 2] == 0) {
            continue;
        }
        switch (i) {
        case 0:
            if (datGetHp(1) < datGetMaxHp(1)) {
                return 1;
            }
            break;
        case 1:
            brRoot001f1df0((u16*)members, &memberCount);
            for (j = 0; j < memberCount; j++) {
                if (datGetHp(members[j]) < datGetMaxHp(members[j])) {
                    break;
                }
            }
            if (j < memberCount) {
                return 1;
            }
            break;
        case 2:
            if (datGetSp(1) < func_0016c670(1)) {
                return 1;
            }
            break;
        case 3:
            brRoot001f1df0((u16*)members, &memberCount);
            for (j = 0; j < memberCount; j++) {
                if (datGetSp(members[j]) < func_0016c670(members[j])) {
                    break;
                }
            }
            if (j < memberCount) {
                return 1;
            }
            break;
        case 4:
            if ((datGetBadStatusNoDown(1) & 0x80) != 0) {
                return 1;
            }
            break;
        case 5:
            brRoot001f1df0((u16*)members, &memberCount);
            for (j = 0; j < memberCount; j++) {
                if ((datGetBadStatusNoDown(members[j]) & 0x80) != 0) {
                    break;
                }
            }
            if (j < memberCount) {
                return 1;
            }
            break;
        case 6:
            break;
        case 7: {
            u16 condition = datGetPhysicalCondition(1);
            if ((u32)(condition - 3) < 3) {
                return 1;
            }
            break;
        }
        case 8:
            brRoot001f1df0((u16*)members, &memberCount);
            for (j = 0; j < memberCount; j++) {
                u16 condition = datGetPhysicalCondition(members[j]);
                if (condition == 3 || condition == 4 || condition == 5) {
                    break;
                }
            }
            if (j < memberCount) {
                return 1;
            }
            break;
        case 9: {
            u16 condition = datGetPhysicalCondition(1);
            if (condition != 1 && condition != 2) {
                return 1;
            }
            break;
        }
        case 10:
            brRoot001f1df0((u16*)members, &memberCount);
            for (j = 0; j < memberCount; j++) {
                u16 condition = datGetPhysicalCondition(members[j]);
                if (condition != 1 && condition != 2) {
                    break;
                }
            }
            if (j < memberCount) {
                return 1;
            }
            break;
        case 11:
            if (datGetPhysicalCondition(1) != 2) {
                return 1;
            }
            break;
        case 12:
            brRoot001f1df0((u16*)members, &memberCount);
            for (j = 0; j < memberCount; j++) {
                if (datGetPhysicalCondition(members[j]) != 2) {
                    break;
                }
            }
            if (j < memberCount) {
                return 1;
            }
            break;
        }
    }
    return 0;
}
#pragma opt_lifetimes reset
#pragma pop
// FUN_001f9630
void sflResult001f9630(void)
{
    u32* p;

    K_ASSERT(sSflResult != NULL, 0x8c);
    p = sSflResult;
    *(u32*)((int)p + 0x341c) = 0;
    *(u32*)((int)p + 0x3418) = 0;
}

/* Retail reconstruction spans 0x001f6630-0x001f6a5c: reward reset, card setup, and two indexed animation passes. */
// FUN_001f9680
#pragma opt_loop_invariants on
u32 sflResult001f9680(const s32* request)
{
    u8* base;
    s32* entry;
    s32 i;
    s32 count;
    s32 stride;
    u32 result;

    K_ASSERT(sSflResult != NULL, 0x8c);
    base = (u8*)sSflResult;
    i = 0;
    count = *(s32*)(base + 0x33dc);
    result = 1;
    stride = 0x670;
    while (i < count)
    {
        entry = (s32*)(base + i * stride + 0x5c);
        if (entry[0] == request[0])
        {
            switch (request[0])
            {
            case 0:
                if (*(u16*)&entry[1] == *(u16*)&request[1])
                    return result;
                break;
            case 1:
                if (entry[1] == request[1] || entry[2] == request[2])
                    return result;
                break;
            }
        }
        i++;
    }
    return 0;
}
#pragma opt_loop_invariants reset

// FUN_001f9770
void sflResult001f9770(int param_1, int* param_2)
{
    int i;
    u8* p;

    K_ASSERT(sSflResult != NULL, 0x8c);
    p = (u8*)sSflResult;
    for (i = 0; i < *(s32*)(p + 0x3400); i++) {
        *(u16*)(param_1 + i * 2) = *(u16*)(p + i * 2 + 0x33e0);
    }
    *param_2 = *(s32*)(p + 0x3400);
}

// FUN_001f9800
void sflResult001f9800(int param_1, int* param_2)
{
    int i;
    u8* p;

    K_ASSERT(sSflResult != NULL, 0x8c);
    p = (u8*)sSflResult;
    for (i = 0; i < *(s32*)(p + 0x3404); i++) {
        *(u16*)(param_1 + i * 2) = *(u16*)(p + i * 2 + 0x33f0);
    }
    *param_2 = *(s32*)(p + 0x3404);
}

// FUN_001f9890
u32 sflResult001f9890(void)
{
    K_ASSERT(sSflResult != NULL, 0x8c);
    return *(u32*)((u8*)sSflResult + 0x18);
}

// FUN_001f98d0
void sflResult001f98d0(void)
{
    u8* base;
    s32 i;
    K_ASSERT(sSflResult != NULL, 0x8c);
    base = (u8*)sSflResult;
    if ((*(u32*)base & 0x80) != 0) {
        switch (*(u32*)(base + 8)) {
        case 1:
            for (i = 0; i < *(s32*)(base + 0x33dc); i++) {
                s32* entry = (s32*)(base + i * 0x670 + 0x5c);
                switch (entry[0]) {
                case 0:
                    func_0021a760(*(u16*)(entry + 1));
                    break;
                case 1:
                    func_0021a670(entry[1], entry[2]);
                    break;
                }
            }
            *(u32*)base |= 0x80;
            *(u32*)(base + 4) = 0;
            break;
        case 0:
            func_001f6630();
            break;
        }
        *(u32*)base &= ~0x80;
    }
}

// FUN_001f99f0
void sflResult001f99f0_y2(void)
{
    u32* puVar1;

    K_ASSERT(sSflResult != NULL, 0x8c);
    puVar1 = sSflResult;
    puVar1[0xd03] = 0;
    switch (puVar1[2]) {
    case 1:
        puVar1[0xd33] = 0;
        puVar1[0xd34] = 0;
        puVar1[0xd32] = 0;
        *puVar1 |= 0x100;
        break;
    }
    FUN_001f6e80();
    puVar1[1] = 2;
}

/* W415 census recheck: all eight relocations resolve to the same ordered retail targets; the reported callee discrepancy is an offset shift, not a wrong callee. */
// FUN_001f9a80 NONMATCHING
void sflResult001f9a80(void)
{
    u8* base;
    s32 i;

    K_ASSERT(sSflResult != NULL, 0x8c);
    base = (u8*)sSflResult;
    *(u32*)(base + 0x3408) = 0;
    if (*(u32*)(base + 8) == 1) {
        for (i = 0; i < *(s32*)(base + 0x3418); i++) {
            u32 index = *(u32*)(base + 0x1c + i * 4);
            u8* sprite = base + index * 0x670 + 0x5c;
            float scale[3];
            float origin[2] = {(float)i * 220.0f + 320.0f, 184.0f};
            float rect[4];
            float axis[3];
            float rotation[4];
            f32 frame;

            scale[0] = 10.0f;
            scale[1] = 10.0f;
            scale[2] = 10.0f;
            sflResSetSpriteScale_y2(sprite + 0xc, scale);
            frame = func_0020c500_y2(200.0f, sprite + 0xc);
            func_0020c400_y2(sprite + 0xc, rect, frame, origin);
            rect[1] += 100.0f;
            sflResSetSpritePosition_y2(sprite + 0xc, rect);
            axis[0] = 0.0f;
            axis[1] = 1.0f;
            axis[2] = 0.0f;
            func_004bdde0(180.0f, rotation, axis, 0);
            sflResSetSpriteRotation_y2(sprite + 0xc, rotation);
        }
        *(u32*)(base + 0x36d8) = 0;
        *(u32*)(base + 0x36dc) = 0;
        *(u32*)(base + 0x36d4) = 0;
        *(u32*)base |= 0x200;
        if (*(u32*)(base + 0x341c) != 0) {
            *(u32*)(base + 0x34d0) = 0;
            *(u32*)(base + 0x34c8) = 1;
            *(u32*)base |= 0x100;
        }
    }
    func_001f7210();
    *(u32*)(base + 4) = 7;
}

// FUN_001f9c60
void sflResult001f9c60(void)
{
    struct Vector3 {
        float x;
        float y;
        float z;
    };
    u8* base;
    u8 color[4];
    struct Vector3 position;
    u32 index;
    K_ASSERT(sSflResult != NULL, 0x8c);
    base = (u8*)sSflResult;
    index = *(u32*)(base + 0x3408);
    index *= 4;
    index += (u32)base;
    index = *(u32*)(index + 0x1c);
    position = *(struct Vector3*)(base + index * 0x670 + 0x88);
    position.x = 0.0f;
    position.y = 120.0f;
    position.z = 200.0f;
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = 0xff;
    func_0034ff90(*(u32*)(base + 0x34e0), color);
    func_0034ff70(*(u32*)(base + 0x34e0), fGpffff8070);
    func_0034fdf0(*(u32*)(base + 0x34e0), (float*)&position);
    func_0034fe30(0.0f, *(u32*)(base + 0x34e0), 0.0f, 0.0f);
    func_0034fd30(*(u32*)(base + 0x34e0));
    func_0034fd70(*(u32*)(base + 0x34e0), 7);
}
