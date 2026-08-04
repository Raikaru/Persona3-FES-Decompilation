#include "Main/Battle/Cmd/bcm_main.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Panel/bp_root.h"
#include "rw/rwplcore.h"
#include "Main/Battle/Cmd/bpp_main.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"

u32 func_002519d0(void);
u32 func_00251e80(void);
u32 bcmPanel0022b4e0(void);
u32 bcmPanel0022b530(void);
void bcmPanel00222870(void);
void bcmPanel002226f0(u32);
void bcmPanel002227b0(u32);
void func_002bf850(void);
void func_002bf8b0(void);
void func_002bf8e0(void);
void func_002bf910(void);
void func_002bf880(void);
void func_002bf940(void);
u32 func_002d1a70(void);
void bpPersonaLoad(u32);
void func_00208630(void);
u32 basRequestAnalyze(u32);
u32 basIsAnalyzePending(void);
u32 func_0021b6f0(void);
u32 func_0021b740(void);
u32 func_0021b7c0(void);
void func_002dbac0(void);
u32 func_003c7990(u32);
u32 func_003c7850(void);
u32 func_003c7650(u32);
u32 func_003c7610(u32);
void func_003c77a0(void);
u32 func_003c72d0(void);
u32 func_003c7430(u32);
u32 func_003c74e0(u32);
void func_0024a260(void*);
u32 func_0024a6e0(u32);
u32 func_0024a750(void);
u32 bpPersonaIsLoading(void);
void bpPersonaDestroy(void);
void bpPersonaSetPersona(u32);
void bcmDestroyOwnedResource();
void FUN_003b0170();
extern u8* DAT_007ce3f8;
extern u32 D_00684F00[];
extern u8 DAT_00684efc[];
extern u32 DAT_007e094e;
extern u32 DAT_007e0952;
extern u32 DAT_007e095a;
#pragma alias DAT_007e094e_abs DAT_007e094e
#pragma alias DAT_007e0952_abs DAT_007e0952
#pragma alias DAT_007e095a_abs DAT_007e095a
extern u8 DAT_007e094e_abs[];
extern u8 DAT_007e0952_abs[];
extern u8 DAT_007e095a_abs[];
extern u8 gp0xffff972c;
extern u8* gp0xffffb708;
u32 FUN_002055F0(u32 id);
void FUN_00207B50_y2(void);
void FUN_00207BA0_y2(void);
void FUN_002082C0(void* context);
void FUN_00208360(void);
void FUN_00208570(void* descriptor);
void FUN_002085E0(void);
void FUN_00208790(void);
void FUN_00208860(u16 id);
void FUN_002094F0(void);
void FUN_0020FC40_y2(void);
void FUN_0020FC90(void);
void FUN_0020FE30(void*, u32, void*);
void FUN_00222A60(void);
void FUN_00222B90(void);
void FUN_00222D60(void);
void FUN_00229300(void);
void FUN_00224660(void);
void FUN_00224860(void);
void FUN_0022BF60(void);
void FUN_0022C0E0(void);
void FUN_002230E0(void);
void FUN_002254A0(void);
void FUN_002255F0(void);
void FUN_00225670(void);
void FUN_002DB450(u32);
void FUN_002DB480(void);
void FUN_002DB9F0(u32, u32);
void FUN_002DBA80(u32);
void FUN_003A5540(u32, u32, s32, u32, u32, void*);
void FUN_003B0170(u32);
void FUN_003B0970(u32, u32, s32, u32, u32, u32, u32, u32);
void FUN_003B0D70(u32, u32, u32);
void FUN_003B0E20(u32, s32);
void FUN_003B0E70(u32);
void FUN_003B0E90(u32);
void FUN_003B2C60(u32);
void FUN_003C72D0(void);
void FUN_003C7430(u32);
void FUN_003C74E0(u32);
void FUN_003C7D60(u32);
u32 FUN_0030C0C0(void);
u32 FUN_003086F0(u32, u16);
u32 FUN_003083F0(u32, u16);
u32 FUN_0030BB40(u16);
u32 FUN_0030BC20(u16);
u32 FUN_00173220(u16);
u32 FUN_001775A0(u32);
u32 FUN_00177790(u32);
u32 FUN_001756F0(void);
u32 FUN_0016F380(u32);
void FUN_0016F3E0(u32, u32);
u32 FUN_0016F190_y2(u32);
void FUN_005225a8_y2(const char*, ...);
void FUN_0021B670(u32);
void FUN_0021C720(void);
u32 FUN_0022D5550(void);
u32 FUN_002D5550_y2(void);
u32 FUN_001FF430_y2(u32);
void FUN_002C0A50(u32, u32);
void datSetAiTactic(s16, s16);
u32 datGetScenarioMode(void);
void datSetScenarioMode(u32);
u32 datGetFlag(s32);
int printf(const char*, ...);
void* func_0021f410_y2(void);
void func_00221b60_y2(void);
void func_0021f140(void);
void func_0021f150(u32);
void func_0022c0a0(void);
void func_0022c0e0(void);
void func_0022c1d0(void);
void func_002230e0(void);
void func_00224660(void);
void func_00224860(void);
void func_002254a0(void);
void func_002255f0(void);
void func_00225670(void);
void func_002082c0(u32);
void func_00208360(void);
void func_00208570(void*);
void func_002085e0(void);
void func_00208790(void);
void func_00208860_y2(u16);
void func_0022bf60(void);
void func_0023c0a0(void);
void func_003b0170(u32);
u32 func_003b0970(u32, ...);
void func_003b0d70(u32, ...);
void func_003b0e20(u32, s32);
void func_003b0e70(u32);
void func_003b0e90(u32);
void func_003b2c60(u32, ...);
u32 func_003a5540(u32, ...);
#pragma alias bpRoot_003a5540_typed func_003a5540
extern u32 bpRoot_003a5540_typed(u32 p1, u32 p2, s32 p3, f32 angle,
                                  u32 p4, u32 p5, void* p6, u32 p7);
extern u32 D_007CC418;
extern u32 DAT_007cc414;
void* func_0030c0c0(void);
u32 func_003086f0(u32, u16);
u32 func_003083f0(u32, u16);
u32 func_0030bb40(u16);
u32 func_0030bc20(u16);
u16 func_00170760(s16, s16);
const char* func_00171110(s16, s16);
u32 func_00173220(u16);
u32 func_001775a0(u32, ...);
u32 func_00177790(s16);
u32 func_001756f0(void);
u32 func_002db450(u32);
u32 func_002db480(void);
u32 func_002db9f0(u32, u32);
u32 func_002dba80(u32);
u32 func_002d5550(void);
u32 func_003c7d60(u32);
void FUN_0010a4e0(u32, u32, u32, u32);
u32 FUN_0017d2e0(u16);
u32 func_00249420(u16, u16, u16);
void FUN_0025d760();
void FUN_001FDDA0(void);
u32 FUN_001FDDF0(void);
void FUN_001FDF10(void*);
u32 FUN_001FE220(void);
void FUN_001FE650(void*);
void FUN_001FE810(s32);
void FUN_001FEAB0(void);
u32 FUN_001FEEC0(void);
void FUN_001FEF90(u32);
void FUN_001FF160(u32);
void FUN_001FF370(void);
void FUN_001FF390(void);
void FUN_001FF3B0(void);
void FUN_001FF3D0(void);
void FUN_001FF3F0(void);
void FUN_001FF410(void);
u32 FUN_001FF630(u32);
void FUN_001ff890_y2(void);
void FUN_001FFC60_y2(void);
void FUN_001FFF40_y2(void);
static KwlnTask* sBtlPanelTask; // 007ce2e4
void* FUN_001fd890(KwlnTask*);
void* FUN_001fdac0(KwlnTask*);
void FUN_00208ad0(void*);
void FUN_00201730_y2(void*);
void bppMain0020ed50(u32*);
void FUN_0020fe20(void*);
void FUN_0021b650(void*);
void FUN_0021b920(void*);
void FUN_0023f480(void*);
void FUN_00242c40(void*);
void FUN_00248490(void*);
void FUN_00249240(void*);
void FUN_0024a6c0(void*);
void FUN_0024c100(void*);
void FUN_00251050(void*);
void FUN_00251a70(void*);
void FUN_00251f20(void*);
void FUN_00252e60(void*);
void FUN_0025bdf0(void*);
void FUN_0025cf00(void*);
void FUN_00266eb0(void*);
void FUN_0027b5b0(void*);
void bppMain0020ed70(void);
void FUN_0025cf20(void);
void bpRootDestroyTask(KwlnTask*);
void FUN_00266f00();
void FUN_0025cf10();
void FUN_0025be00();
void FUN_00252e80();
void FUN_00251f30();
void FUN_002484a0();
void FUN_00251060();
void FUN_0021b660();
void basShutdown(void); // bas_main.c
void FUN_00249250();
void FUN_00242c60();
void FUN_0023f500();
void FUN_00208b20();
void FUN_00201780();
void bppMain0020edc0();
void FUN_00215770();
void FUN_0021bb60();
void FUN_0027b5d0();
void FUN_0021b940();
void FUN_00215a30();
void FUN_00201d10();
void FUN_00205410();
void FUN_00244a00();
void FUN_002086d0();
void FUN_0020fce0();
void FUN_00208680();
void FUN_0020fe30();
void FUN_002449d0();
void FUN_00215a40();
void FUN_00248500(void* destination);
void FUN_00245e00();
void FUN_00248580(void* destination, void* origin);
void FUN_0021bb00();
void FUN_0020fd30();
void FUN_00210d60();
void FUN_00201c30();
void bppMain0020fc40_y2();
void FUN_002085e0();
void FUN_00208b30();
void FUN_0021b830();
void basClearAnalyzePending(void); // bas_main.c
void FUN_0021b8b0();
void FUN_00201e00();
void bppMain0020fc90_y2();
void FUN_00208630_y2();
void FUN_002094f0();
void FUN_0024cf00(s32 mode);
void bppMain0020f3b0();
void bppMain0020f570();
void FUN_00244120(u32 param_1);
void FUN_00244a40(u32 param_1);
void FUN_00249180();
void FUN_0021bb50();
u32 baiMainIsActive(void);
void FUN_00207bf0();
void FUN_002079c0();
void FUN_00207a10();
void FUN_00207c40();
void FUN_00207a60();
void FUN_00207c90();
void FUN_00207ab0();
void FUN_00207ce0();
void FUN_00207d30();
void FUN_00207b00();
void FUN_00207b50();
void FUN_00207d80();
void FUN_00207ba0();
void FUN_00207dd0();
void FUN_0025c190();
void FUN_0025d800();
void FUN_00242b80();
void FUN_00251f40(s32 param_1);
void FUN_00252e90();
void FUN_00252ee0();
void FUN_0025c190();
void FUN_0025c1e0();
void FUN_0025c110();
void FUN_0025d850();
void FUN_00244e10();
void FUN_00208010();
void FUN_00242ae0();
u32 bpMisc001ff500(u32);
u32 bpMisc001ff740_y2(void);
void bcmPanel00222a60(void);
void bcmPanel00222b90(void);
void bcmPanel00222930(void);
void bcmPanel00222d60(void);
void bcmPanel0022bf60(void);
void FUN_00222d60(void);
void func_0021f0c0_y2(void*);
void func_0021bcb0(void);
void func_0024c110(void);
u32 bpRushUpdate(void);
u32 bpRes0021bab0(void);
void bpd00253410(void);
void func_00210d90(void*);
void func_002510d0(void);
void func_00251a80(void);
void bppMain0020edf0(void);
u32 baiMainIsActive(void);
void func_0021c7e0(void);
void bpo00252060(void);
void func_002492b0(void);
void func_00248620(void);
void func_00242cc0(void);
void func_0025c220(void);
void bpPersonaUpdate(void);
void func_0027b610(void);
u32 func_00249130(void);
void func_00245e50(void);
void func_00213e80(void*);
void func_00252f30(void);
void func_00209540(void);
void func_0023f540(void);
void func_0024cca0(void);
void func_002095a0(void);
void func_002532b0(void);
void func_0020f260(void);
void func_00243150(void);
void func_00241910(void);
void func_00248bb0(void);
void func_002520f0(void);
void func_0025c9c0(void);
void func_0025d470(void);
void func_0027b880(void);
u32 func_00208720(void);
void* btlUnitFindFromId(u16);
u32 func_00242a60(void);
void* func_00242260(void);
void func_00242320(void*, u32);
void func_00242a50(void*, u32);
void func_00242600(void*, u32);
void func_00242720(void*, u32);
void func_00242a30(void*);
void func_00242c20(void*, u32, u32);
void func_00242540(void*);
void func_002453d0(s32);
void func_002441b0(s32);
u32 func_00207f70(void);
u32 func_00207fc0(void);
u32 func_00208010_y2(void);
u32 func_00208050_y2(void);
u32 func_00208130_y2(void);
void func_0025be60(u32, u32, u32);
void bpRush0025d7b0(void);
void func_0020fd80(void);
void func_0020fdd0(void);
void func_0027b9f0(void);
void func_0027ba90(void);
void func_0027bae0(void);
#include "Battle/battle.h"
#pragma alias bcmStartTacticsTutorial FUN_00207e20
#pragma alias bcmStartBasicTutorial FUN_00207f10
#pragma alias bcmIsCurrentUnitTutorialPending FUN_00208010
#pragma alias bcmIsTacticsTutorialPending FUN_00208050
#pragma alias bcmCanStartBasicTutorial FUN_00208130
#pragma alias bcmStoreOwnedResource FUN_002082c0
#pragma alias bcmDestroyOwnedResource FUN_00208360
#pragma alias bcmDestroyOwnedResourceImpl FUN_002083d0
#pragma alias bcmFinishPanelTransition FUN_00208460
#pragma alias bcmInitCommandPanelEntries FUN_00208570
#pragma alias bcmIsCommandInputReady FUN_00208720
#pragma alias bcmPlayRandomPartyVoice FUN_00208790
extern u8* gBcmWork;
extern void func_002518b0(u32 mode);
extern void func_00251e10(void);
extern void bppMain0020fc40(void);
extern u32 func_00249650(u16 id);
extern u32 datGetFlag_y2(u16 id);
extern u32 bpMisc001ff7f0(u32 id);
extern u32 datGetBadStatusNoDown(s16 unitId);
extern void bcmPanel00222ed0(void);
extern void func_003b0170_y2(u32 value);
extern u32 datCalcIsDead(void* calc, u32 mode);
extern u32 func_002ddc10(u32 unitId);
extern void func_002ddba0(u32 id);
extern u32 RpRandom(void);
static void bcmDestroyOwnedResourceImpl(void);
static void func_00208860(u32 unitId);
#define BCM_WORD(off) (*(u32*)((u8*)gBcmWork + (off)))
typedef struct BcmCommandEntry
{
    u32 flags;
    u32 type;
    u32 icon;
    u16 id;
} BcmCommandEntry;


#pragma alias bppMain0020fc40_y2 bppMain0020fc40
#pragma alias func_00208860_y2 func_00208860
#pragma alias datGetFlag_y2 datGetFlag_y2
#pragma alias func_003b0170_y2 func_003b0170_y2


#pragma alias FUN_002055F0_y2 FUN_002055F0
#pragma alias FUN_002085E0_y2 FUN_002085E0
#pragma alias FUN_0016F380_y2 FUN_0016F380
#pragma alias FUN_0016F3E0_y2 FUN_0016F3E0
#pragma alias FUN_0021B670_y2 FUN_0021B670
#pragma alias datSetAiTactic_y2 datSetAiTactic
#pragma alias datGetFlag_y2 datGetFlag
#pragma alias printf_y2 printf
#pragma alias FUN_0017d2e0_y2 FUN_0017d2e0
#pragma alias FUN_00207B50_y2 FUN_00207B50_y2
#pragma alias FUN_00207BA0_y2 FUN_00207BA0_y2
#pragma alias FUN_0020FC40_y2 FUN_0020FC40_y2
#pragma alias FUN_0016F190_y2 FUN_0016F190_y2
#pragma alias FUN_005225a8_y2 FUN_005225a8_y2
#pragma alias FUN_002D5550_y2 FUN_002D5550_y2
#pragma alias FUN_001FF430_y2 FUN_001FF430_y2
#pragma alias func_0021f410_y2 func_0021f410_y2
#pragma alias func_00221b60_y2 func_00221b60_y2
#pragma alias FUN_001ff890_y2 FUN_001ff890_y2
#pragma alias FUN_001FFC60_y2 FUN_001FFC60_y2
#pragma alias FUN_001FFF40_y2 FUN_001FFF40_y2
#pragma alias FUN_00201730_y2 FUN_00201730_y2
#pragma alias bppMain0020fc90_y2 bppMain0020fc90_y2
#pragma alias FUN_00208630_y2 FUN_00208630_y2
#pragma alias bpMisc001ff740_y2 bpMisc001ff740
#pragma alias func_0021f0c0_y2 func_0021f0c0_y2
#pragma alias func_00208010_y2 func_00208010_y2
#pragma alias func_00208050_y2 func_00208050_y2
#pragma alias func_00208130_y2 func_00208130_y2
extern u32 datGetFlag_y2(u16 id);

typedef struct PanelSkillRow
{
    u32 flags;
    u32 handle;
    u32 type;
    u32 icon;
} PanelSkillRow;
#pragma alias bcmIsItemUsable FUN_00207930
#pragma alias bcmDestroyOwnedResourceCallback FUN_00201ad0
#pragma alias bcmDestroyCommandResources FUN_00203360


u8* gBcmWork; // 007ce2e8
extern u8* DAT_007ce3ec;
#pragma alias DAT_007ce3ec_abs DAT_007ce3ec
extern u8 DAT_007ce3ec_abs[];

s32 FUN_0017d2e0_y2();
void FUN_00201A50(void);
u32 FUN_00201AF0(void);
void FUN_00201EF0(void);
void FUN_00202010(void);
void FUN_00202830(void);
u32 bpe00249600(void);
void* func_0021c5d0(void);
void* func_0021c640(void);
void* func_0021c6b0(void);
u32 itfMesMngInitialize(void*);
void itfMesMngDestroyHandle(u32);
void func_00207e20(void);
void func_00207f10(void);
void func_002db420(s32);
void func_002db650(u32);
void func_002db2a0(s32);
void func_0021f3c0(void);
void bpRushRequestHide(void);
void bpRushClearHideRequest(void);
void func_002083d0(void);
void FUN_00201880(void);
void FUN_002024B0(void);
void FUN_002025E0(void);
void FUN_00202A10(void);
void FUN_00203030(void);
void FUN_002031C0(void);
void FUN_00203410(void);
void FUN_00203990(void);
void FUN_00203C30(void);
void FUN_00203DE0(void);
void FUN_00204760(void);
void FUN_00205000(void);
void FUN_002057C0(void);
void FUN_00205D60(void);
void FUN_00206170(void);
void FUN_00206310(void);
void FUN_00206740(void);
void FUN_00206E40(void);
void FUN_00206EB0(void);
void FUN_00206F70(void);
void FUN_00207010(void);
void FUN_00207340(void);
void FUN_002078A0(void);
u32 FUN_00207960(u32 id);
void FUN_002079C0(void);
void FUN_00207A60(void);
void FUN_00207AB0(void);
void FUN_00207B00(void);
void FUN_00202BC0(void);
void FUN_00202C90(void);
void FUN_00202D70(void);
void FUN_00203630(void);
void FUN_00203760(void);
void FUN_00203850(void);
void FUN_00203B70(void);
void FUN_00204000(void);
void FUN_00204480(void);
void FUN_00204AF0(void);
void FUN_00204BE0(void);
void FUN_00204CC0(void);
u32 FUN_002053C0(void);
void FUN_00205410(void);
u32 FUN_002054C0(void);
u16 FUN_00205500(void);
u16 FUN_00205550(void);
u16 FUN_002055A0(void);
u32 FUN_00205650(s32 id);
void FUN_002056A0(void);
void FUN_00205700(void);
void FUN_00205760(void);
void FUN_002060B0(void);
void FUN_002063F0(void);
void FUN_002065A0(void);
static u8* panelWork(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    return gBcmWork;
}

static inline u32 panelWork32(u32 offset)
{
    return *(u32*)(gBcmWork + offset);
}

static inline void panelSetWork32(u32 offset, u32 value)
{
    *(u32*)(gBcmWork + offset) = value;
}

static inline u16 panelWork16(u32 offset)
{
    return *(u16*)(gBcmWork + offset);
}

static inline void panelSetWork16(u32 offset, u16 value)
{
    *(u16*)(gBcmWork + offset) = value;
}

void* func_00170e90(s16);
static u32 panelDataType(u16 id)
{
    void* record;

    record = func_00170e90((s16)id);
    if (record == NULL)
    {
        return 0;
    }
    return ((u8*)record)[3];
}
u32 FUN_002055F0_y2(u32);
u32 func_003c7430(u32);
u32 func_003c74e0(u32);
static u32 panelSkillAccept(u16 id)
{
    return FUN_002055F0_y2(id);
}

static PanelSkillRow* panelSkillRow(u32 index)
{
    return (PanelSkillRow*)(panelWork() + 0x4a90 + index * 0x2d0);
}

static PanelSkillRow* panelItemRow(u32 index)
{
    return (PanelSkillRow*)(panelWork() + 0x4a90 + index * 0x310);
}

static void panelTargetEffect(u32 first, u32 second)
{
    func_003c7430(first);
    func_003c74e0(second);
}

#pragma alias bpRoot_0021c720_ret func_0021c720
u32 bpRoot_0021c720_ret(void);
#pragma alias bpRoot_003c72d0_arg func_003c72d0
u32 bpRoot_003c72d0_arg(u32);

// Retail state-3 persona selection also handles input-driven left/right
// navigation and invokes bpPersona00267070 before the transition effect.
// The state-1/2/4 branches use the same input flag register as retail;
// these paths are reconstructed directly even though MWCC lays out the
// resulting switch differently from the retail object.

/* W420 verified: direct work indexing, D_00684F00-relative strings, and corrected flag masks nd619/976B -> nd0/964B, window976B; rate 63.42% -> 0%. */
// W419 negative probe: FUN_001FF890 direct gBcmWork flag pointer nd521/988B, window976B (over window), rate52.73%; reverted.
// FUN_001FF890
void FUN_001ff890(void)
{
    u32* work;
    void* message;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = (u32*)gBcmWork;
    if (work[0x77a0 / 4] & 1)
        FUN_005225a8((const char*)D_00684F00 + 0x58);
    else
        FUN_005225a8((const char*)D_00684F00 + 0x68);
    if (work[0x77a0 / 4] & 2)
        FUN_005225a8((const char*)D_00684F00 + 0x78);
    else
        FUN_005225a8((const char*)D_00684F00 + 0x88);
    if (work[0x77a0 / 4] & 4)
        FUN_005225a8((const char*)D_00684F00 + 0x98);
    else
        FUN_005225a8((const char*)D_00684F00 + 0xa8);
    if (work[0x77a0 / 4] & 8)
        FUN_005225a8((const char*)D_00684F00 + 0xb8);
    else
        FUN_005225a8((const char*)D_00684F00 + 0xc8);
    if (work[0x77a0 / 4] & 0x10)
        FUN_005225a8((const char*)D_00684F00 + 0xd8);
    else
        FUN_005225a8((const char*)D_00684F00 + 0xe8);
    if (work[0x77a0 / 4] & 0x20)
        FUN_005225a8((const char*)D_00684F00 + 0xf8);
    else
        FUN_005225a8((const char*)D_00684F00 + 0x108);
    if (work[0x77a0 / 4] & 0x40)
        FUN_005225a8((const char*)D_00684F00 + 0x120);
    else
        FUN_005225a8((const char*)D_00684F00 + 0x140);
    work[0] &= ~0x20u;
    work[0] &= ~1u;
    work[0] &= ~0x20000000u;
    work[0] &= ~0x02000000u;
    work[0] &= ~0x04000000u;
    work[0] &= ~0x80u;
    work[0] &= ~0x100u;
    work[0] &= ~0x200u;
    work[0] &= ~0x400u;
    work[1] = 0;
    work[3] = 0;
    if (datGetFlag_y2(0x186))
    {
        work[0x24 / 4] = FUN_0016F380_y2(0x30);
    }
    else
    {
        work[0x24 / 4] = 0;
    }
    message = func_0021c5d0();
    work[0x7794 / 4] = itfMesMngInitialize(message);
    message = func_0021c640();
    work[0x7790 / 4] = itfMesMngInitialize(message);
    message = func_0021c6b0();
    work[0x7798 / 4] = itfMesMngInitialize(message);
    work[0x77a4 / 4] = 0;
    FUN_002056A0();
    FUN_00201EF0();
    FUN_00202C90();
    FUN_00204000();
    FUN_00203760();
    FUN_00205700();
    FUN_00205760();
    work[2] = 0;
    if (func_00208010()) work[2] |= 1;
    if (func_00208050()) work[2] |= 2;
    if (func_00208130()) work[2] |= 4;
    if (work[2] & 2)
    {
        func_00207e20();
    }
    else if (work[2] & 4)
    {
        func_00207f10();
    }
    else if (work[2] & 1)
    {
        FUN_002078A0();
    }
    else
    {
        FUN_00201A50();
    }
    bpRushRequestHide();
}


// W419 negative probe: FUN_001FFC60 declaration permutations (work/record/i) all stayed nd295/676B; reverted.
// FUN_001FFC60 NONMATCHING
void FUN_001FFC60(void)
{
    u32* work;
    u8* record;
    s16 i;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = (u32*)gBcmWork;
    for (i = 0; i < work[0x3a8 / 4]; i++)
    {
        record = (u8*)work + 0x2e0 + i * 0x18;
        if ((*(u32*)record & 1) == 0 && *(u32*)(record + 4) == 1)
        {
            datSetAiTactic_y2(*(s16*)(record + 0xc), *(s16*)(record + 0x10));
            if (*(u32*)(record + 0x10) == 7)
            {
                u32 target;
                target = FUN_001FF430(*(u32*)(record + 8));
                func_002C0A50(target, *(u32*)(record + 0x14));
            }
        }
    }
    if (*(u32*)work & 0x20000)
    {
        if (!(*(u32*)work & 0x4000))
        {
            func_002db420(2);
        }
        else
        {
            func_002db650(work[0x7654 / 4]);
            func_002db2a0(2);
        }
    }
    if (*(u32*)work & 0x40000)
    {
        if (!(*(u32*)work & 0x8000)) func_002db420(1);
        else func_002db2a0(1);
    }
    if (*(u32*)work & 0x80000)
    {
        if (!(*(u32*)work & 0x100000)) func_002db420(0);
        else func_002db2a0(0);
    }
    if (*(u32*)work & 0x800000) func_002083d0();
    if (*(u32*)work & 0x2000) FUN_00206EB0();
    if (*(u32*)work & 0x1000) FUN_00206310();
    if (*(u32*)work & 2) FUN_00202BC0();
    if (*(u32*)work & 4) bcmDestroyCommandResources();
    if (*(u32*)work & 8) FUN_00203B70();
    if (*(u32*)work & 0x10) FUN_00204BE0();
    itfMesMngDestroyHandle(work[0x7790 / 4]);
    itfMesMngDestroyHandle(work[0x7794 / 4]);
    itfMesMngDestroyHandle(work[0x7798 / 4]);
    func_0021f3c0();
    bpRushClearHideRequest();
}


static inline u16 panelRootInputFlags(void)
{
    return *(u16*)DAT_007e094e_abs;
}

static inline u16 panelRootTargetFlags(void)
{
    return *(u16*)DAT_007e0952_abs;
}

// FUN_001FFF40 NONMATCHING
void FUN_001FFF40(void)
{
    u32* work;
    u32 flags;
    u32 renderFlags;
    u32 state;
    u32 substate;
    u32 secondary;
    u32 menu;
    u32 type;
    u32 effect;
    u32 result;
    u32 value;
    u8* entry;
    void* persona;
    u32 func_0017b260(u16);
    /* Retail offsets: +0x2a0 guard; +0x3bc/+0x4e8/+0x56c/+0x5c0
       helper arguments; +0x1028/+0x1050 case layout; +0x1110-+0x127c
       secondary-1 path; +0x13f8/+0x1520/+0x1634 diagnostics. */

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = (u32*)gBcmWork;
    renderFlags = 0;
    flags = work[0];
    if (flags & 0x08000000)
    {
        if ((s32)work[0x77a4 / 4] > 0)
            work[0x77a4 / 4]--;
    }
    else if (flags & 0x10000000)
    {
        if ((s32)work[0x77a4 / 4] < 0x10)
            work[0x77a4 / 4]++;
    }
    *(f32*)((u8*)work + 0x7644) =
        (f32)(s32)work[0x77a4 / 4] / 16.0f;
    if ((work[1] & 1) && !bcmPanel0022b4e0())
    {
        FUN_00202BC0();
        work[1] &= ~2u;
    }
    if ((work[1] & 2) && !bcmPanel0022b4e0())
    {
        bcmDestroyCommandResources();
        work[1] &= ~3u;
    }
    if ((work[1] & 4) && !bcmPanel0022b4e0())
    {
        FUN_00204BE0();
        work[1] &= ~5u;
    }

    state = work[4];
    switch (state)
    {
    case 0:
        if (!FUN_00201AF0() && !(flags & 0x40) && work[1] == 0)
        {
            if ((*(u16*)DAT_007e094e_abs) & 4)
            {
                if (!(work[3] & 4) || bpMisc001ff740() == 2)
                {
                    FUN_0010A4E0(0, 0, 0, 8);
                }
                else
                {
                    FUN_0021B670_y2(1);
                    work[4] = 6;
                    work[6] = 1;
                    work[0] |= 0x80000000u;
                    FUN_0010A4E0(0, 0, 0, 3);
                }
            }
            else
            {
                if (func_002d1a70() == 0 && ((*(u16*)DAT_007e094e_abs) & 0x10))
                {
                    work[0] |= 0x200000;
                    work[0] |= 0x20;
                }
                else if ((work[3] & 0x40) && ((*(u16*)DAT_007e094e_abs) & 0x80))
                {
                    work[0] |= 0x400000;
                    work[0] |= 0x20;
                }
                else if ((*(u16*)DAT_007e094e_abs) & 0x40)
                {
                    menu = work[0x24 / 4];
                    if (menu < 7)
                    {
                        switch (menu)
                        {
                        case 0:
                            if (!(work[3] & 0x20))
                            {
                                func_002bf850();
                            }
                            else
                            {
                                bcmDestroyOwnedResourceCallback();
                                printf_y2("battle panel command accepted\n");
                                work[0] |= 0x20;
                            }
                            break;
                        case 1:
                            if (!(work[3] & 1))
                            {
                                if (work[0] & 0x80)
                                    bpRoot001fea10(
                                        *(u32*)(DAT_007ce3ec + 0xba0), 0xcf);
                                else
                                    func_002bf8b0();
                            }
                            else
                            {
                                bcmDestroyOwnedResourceCallback();
                                FUN_00202010();
                                renderFlags |= 3;
                            }
                            break;
                        case 2:
                            if (!(work[3] & 2))
                            {
                                if (work[0] & 0x100)
                                    bpRoot001fea10(
                                        *(u32*)(DAT_007ce3ec + 0xba0), 0xd2);
                                else
                                    func_002bf8e0();
                            }
                            else
                            {
                                bcmDestroyOwnedResourceCallback();
                                FUN_00202D70();
                                renderFlags |= 5;
                            }
                            break;
                        case 3:
                            if (!(work[3] & 4))
                            {
                                if (work[0] & 0x200)
                                {
                                    value = 0xd3;
                                    if (FUN_0016F190(0x1317) != 0)
                                        value = 0xd4;
                                    bpRoot001fea10(
                                        *(u32*)(DAT_007ce3ec + 0xba0), value);
                                }
                            }
                            else
                            {
                                bcmDestroyOwnedResourceCallback();
                                FUN_00204480();
                                renderFlags |= 0x11;
                            }
                            break;
                        case 4:
                            if (!(work[3] & 8))
                            {
                                if (work[0] & 0x400)
                                    bpRoot001fea10(
                                        *(u32*)(DAT_007ce3ec + 0xba0), 0xd5);
                                else
                                    func_002bf910();
                            }
                            else
                            {
                                bcmDestroyOwnedResourceCallback();
                                FUN_00203850();
                                renderFlags |= 9;
                            }
                            break;
                        case 5:
                            if (!(work[3] & 0x10))
                            {
                                func_002bf880();
                            }
                            else
                            {
                                bcmDestroyOwnedResourceCallback();
                                printf_y2("battle panel command accepted\n");
                                work[0] |= 0x20;
                            }
                            break;
                        case 6:
                            if (!(work[3] & 0x40))
                            {
                                func_002bf940();
                            }
                            else
                            {
                                bcmDestroyOwnedResourceCallback();
                                printf_y2("battle panel command accepted\n");
                                work[0] |= 0x20;
                            }
                            break;
                        default:
                            break;
                        }
                        FUN_0016F3E0_y2(0x30, menu);
                    }
                }
                else
                {
                    K_ASSERT((flags & 2) == 0, 0x2b5);
                    if ((*(u16*)DAT_007e0952_abs) & 0x20)
                    {
                        if (work[0x24 / 4] != 0)
                        {
                            work[0x24 / 4] = 0;
                            bcmPanel00222870();
                        }
                        renderFlags |= 1;
                    }
                    else
                    {
                        result = FUN_0016F190(0x188);
                        effect = 0;
                        value = 0;
                        if (result == 0)
                        {
                            if (((*(u16*)DAT_007e0952_abs) & 0x4000) ||
                                (*(u16*)DAT_007e095a_abs & 0x4000) ||
                                ((*(u16*)DAT_007e0952_abs) & 0x8000) ||
                                (*(u16*)DAT_007e095a_abs & 0x8000))
                                effect = 1;
                            if (((*(u16*)DAT_007e0952_abs) & 0x1000) ||
                                (*(u16*)DAT_007e095a_abs & 0x1000) ||
                                ((*(u16*)DAT_007e0952_abs) & 0x2000) ||
                                (*(u16*)DAT_007e095a_abs & 0x2000))
                                value = 1;
                        }
                        else
                        {
                            if (((*(u16*)DAT_007e0952_abs) & 0x4000) ||
                                (*(u16*)DAT_007e095a_abs & 0x4000) ||
                                ((*(u16*)DAT_007e0952_abs) & 0x2000) ||
                                (*(u16*)DAT_007e095a_abs & 0x2000))
                                effect = 1;
                            if (((*(u16*)DAT_007e0952_abs) & 0x1000) ||
                                (*(u16*)DAT_007e095a_abs & 0x1000) ||
                                ((*(u16*)DAT_007e0952_abs) & 0x8000) ||
                                (*(u16*)DAT_007e095a_abs & 0x8000))
                                value = 1;
                        }
                        if (effect)
                        {
                            menu = work[0x24 / 4];
                            if (menu < 6)
                                work[0x24 / 4] = menu + 1;
                            else
                                work[0x24 / 4] = 0;
                            FUN_0010A4E0(0, 0, 0, 5);
                            bcmPanel002226f0(work[0x24 / 4]);
                            renderFlags |= 1;
                        }
                        else if (value)
                        {
                            menu = work[0x24 / 4];
                            if (menu != 0)
                                work[0x24 / 4] = menu - 1;
                            else
                                work[0x24 / 4] = 6;
                            FUN_0010A4E0(0, 0, 0, 5);
                            bcmPanel002227b0(work[0x24 / 4]);
                            renderFlags |= 1;
                        }
                    }
                }
            }
        }
        break;
    case 1:
        if (!FUN_00201AF0() && !(flags & 0x40))
        {
            if ((*(u16*)DAT_007e094e_abs) & 0x20)
            {
                func_00208460();
                renderFlags |= 1;
            }
            else if ((*(u16*)DAT_007e094e_abs) & 0x40)
            {
                if ((work[0x7664 / 4] < 10) &&
                    (*(u32*)((u8*)work + 0x28 + work[0x7664 / 4] * 8) & 1))
                {
                    break;
                }
                FUN_00202830();
            }
            else
            {
                work[0x7658 / 4] &= ~2u;
                func_0024a260((u8*)work + 0x7658);
                if (work[0x7658 / 4] & 1)
                    renderFlags |= 2;
            }
        }
        break;
    case 2:
        if (!FUN_00201AF0() && !(flags & 0x40))
        {
            if ((*(u16*)DAT_007e094e_abs) & 0x20)
            {
                func_00208460();
                renderFlags |= 1;
            }
            else if ((*(u16*)DAT_007e094e_abs) & 0x40)
            {
                FUN_00203630();
            }
            else
            {
                work[0x768c / 4] &= ~2u;
                func_0024a260((u8*)work + 0x768c);
                if (work[0x768c / 4] & 1)
                    renderFlags |= 4;
            }
        }
        break;
    case 3:
        substate = work[5];
        if (substate == 0)
        {
            if (!(flags & 0x40))
            {
                if ((*(u16*)DAT_007e094e_abs) & 0x20)
                {
                    FUN_00203B70();
                    func_00208460();
                    renderFlags |= 1;
                }
                else if ((*(u16*)DAT_007e094e_abs) & 0x80)
                {
                    bpPersonaLoad(
                        *(u16*)((u8*)work + 0x268 + work[0x76cc / 4] * 8));
                    FUN_002085E0_y2();
                    FUN_0020FC40();
                    work[5] = 1;
                    FUN_0010A4E0(0, 0, 0, 1);
                }
                else if ((*(u16*)DAT_007e094e_abs) & 0x40)
                {
                    persona = datPersonaGetByPcId(0);
                    if (*(u16*)((u8*)work + 0x268 + work[0x76cc / 4] * 8) !=
                        *(u16*)((u8*)persona + 2))
                    {
                        FUN_00208630();
                        bppMain0020fc90();
                        work[0] |= 0x20;
                    }
                    else
                    {
                        FUN_0010A4E0(0, 0, 0, 8);
                    }
                }
                else
                {
                    work[0x76c0 / 4] &= ~2u;
                    func_0024a260((u8*)work + 0x76c0);
                    if (work[0x76c0 / 4] & 1)
                        renderFlags |= 8;
                }
            }
        }
        else if (substate == 1)
        {
            if (!FUN_00201AF0() && !bpPersonaIsLoading())
            {
                if ((*(u16*)DAT_007e094e_abs) & 0x20)
                {
                    bpPersonaDestroy();
                    FUN_00208630();
                    bppMain0020fc90();
                    FUN_0010A4E0(0, 0, 0, 2);
                    if (work[0x2dc / 4] < 5)
                    {
                        work[0x76c4 / 4] = 0;
                    }
                    else
                    {
                        value = work[0x76cc / 4];
                        if (value < 2)
                        {
                            work[0x76c4 / 4] = 0;
                        }
                        else if (value != work[0x2dc / 4] - 1)
                        {
                            work[0x76c4 / 4] = value - 2;
                        }
                        else
                        {
                            work[0x76c4 / 4] = value - 3;
                        }
                        renderFlags |= 8;
                    }
                    work[5] = 0;
                }
                else if ((*(u16*)DAT_007e094e_abs) & 0x40)
                {
                    persona = datPersonaGetByPcId(1);
                    entry = (u8*)work + 0x268 + work[0x76cc / 4] * 8;
                    if (*(u16*)entry != *(u16*)((u8*)persona + 2))
                    {
                        bpPersonaDestroy();
                        FUN_00208630();
                        bppMain0020fc90();
                        work[0] |= 0x20;
                    }
                    else
                    {
                        FUN_0010A4E0(0, 0, 0, 8);
                    }
                }
                else
                {
                    value = work[0x2dc / 4];
                    if (value >= 2 && ((*(u16*)DAT_007e0952_abs) & 8))
                    {
                        menu = work[0x76cc / 4];
                        if (menu < value - 1)
                            work[0x76cc / 4] = menu + 1;
                        else
                            work[0x76cc / 4] = 0;
                        bpPersonaSetPersona(
                            *(u16*)((u8*)work + 0x268 +
                                    work[0x76cc / 4] * 8));
                        FUN_0010A4E0(0, 0, 0, 8);
                    }
                    else if ((*(u16*)DAT_007e0952_abs) & 4)
                    {
                        menu = work[0x76cc / 4];
                        if (menu != 0)
                            work[0x76cc / 4] = menu - 1;
                        else
                            work[0x76cc / 4] = value - 1;
                        bpPersonaSetPersona(
                            *(u16*)((u8*)work + 0x268 +
                                    work[0x76cc / 4] * 8));
                        FUN_0010A4E0(0, 0, 0, 8);
                    }
                }
            }
        }
        break;
    case 4:
        if (!FUN_00201AF0() && !(flags & 0x40) && work[1] == 0)
        {
            if ((*(u16*)DAT_007e094e_abs) & 0x40)
            {
                entry = (u8*)work + work[0x7700 / 4] * 0x18 + 0x2e0;
                if (*(u32*)entry & 2)
                    break;
                type = *(u32*)(entry + 4);
                if (type == 0 || type == 1)
                {
                    FUN_002057C0();
                    renderFlags |= 0x20;
                }
                else if (type == 2)
                {
                    FUN_00206740();
                    renderFlags |= 0x40;
                }
                if (type == 0)
                    value = 0xc;
                else if (type == 1)
                    value = *(u16*)(entry + 0xc);
                else
                    value = 0xb;
                FUN_0016F3E0_y2(0x33, value);
            }
            else if ((*(u16*)DAT_007e094e_abs) & 0x20)
            {
                FUN_00204AF0();
                func_00208460();
                renderFlags |= 1;
            }
            else
            {
                work[0x76f4 / 4] &= ~2u;
                func_0024a260((u8*)work + 0x76f4);
                if (work[0x76f4 / 4] & 1)
                    renderFlags |= 0x10;
            }
        }
        break;
    case 5:
        if (!(flags & 0x40) && work[1] == 0)
        {
            substate = work[7];
            if (substate == 0)
            {
                if ((*(u16*)DAT_007e0952_abs) & 0x20)
                {
                    FUN_00205D60();
                    renderFlags |= 1;
                }
                else if ((*(u16*)DAT_007e0952_abs) & 0x40)
                {
                    FUN_002063F0();
                    renderFlags |= 0x10;
                }
                else
                {
                    work[0x7728 / 4] &= ~2u;
                    func_0024a260((u8*)work + 0x7728);
                    if (work[0x7728 / 4] & 1)
                        renderFlags |= 0x20;
                }
            }
            else if (substate == 2)
            {
                if (!bcmPanel0022b530())
                {
                    FUN_00206310();
                    work[4] = 4;
                }
            }
            else if (substate == 1)
            {
                if (!func_0021b6f0())
                {
                    FUN_00208630();
                    if (func_0021b740() == 0)
                    {
                        work[7] = 0;
                    }
                    else
                    {
                        work[0x428 / 4] = func_0021b7c0();
                        FUN_002065A0();
                        renderFlags |= 0x10;
                        FUN_00205D60();
                    }
                }
            }
        }
        break;
    case 6:
        secondary = work[6];
        switch (secondary)
        {
        case 0:
            if ((*(u16*)DAT_007e0952_abs) & 0x20)
            {
                FUN_00206E40();
                renderFlags |= 1;
            }
            else if ((*(u16*)DAT_007e0952_abs) & 0x40)
            {
                FUN_00207340();
                renderFlags |= 1;
            }
            else
            {
                work[0x775c / 4] &= ~2u;
                func_0024a260((u8*)work + 0x775c);
                if (work[0x775c / 4] & 1)
                    renderFlags |= 0x40;
            }
            break;
        case 9:
            if (!bcmPanel0022b530())
            {
                FUN_00206EB0();
                work[4] = 4;
            }
            break;
        case 1:
            if (!func_0021b6f0())
            {
                if (func_0021b740() == 0)
                {
                    if (work[0] & 0x80000000u)
                    {
                        work[6] = 0;
                    }
                    else
                    {
                        work[4] = 0;
                        work[0] &= ~0x80000000u;
                    }
                }
                else
                {
                    work[0x7654 / 4] = func_0021b7c0();
                    persona = (void*)(uintptr_t)FUN_001FF430(
                        work[0x7654 / 4]);
                    entry = *(u8**)((u8*)persona + 0xa2c);
                    if (func_0017b260(*(u16*)(entry + 2)))
                    {
                        FUN_005225a8((const char*)D_00684F00 + 0x150,
                                     *(u16*)(entry + 2));
                        FUN_005225a8((const char*)D_00684F00 + 0x160);
                        func_0024a6e0(work[0x7654 / 4]);
                        work[0] &= ~0x4001u;
                        work[6] = 2;
                    }
                    else
                    {
                        FUN_005225a8((const char*)D_00684F00 + 0x150,
                                     *(u16*)(entry + 2));
                        FUN_005225a8((const char*)D_00684F00 + 0x170);
                        work[0] |= 0x4000;
                        work[0] &= ~0x20001u;
                        func_002dbac0();
                        func_002db9f0(0x20, 0x88);
                        func_002db9f0(0x20, 0x87);
                        FUN_00206E40();
                    }
                }
            }
            break;
        case 2:
            if (!func_0024a750())
            {
                if (work[0] & 0x80000000u)
                {
                    FUN_00206E40();
                }
                else
                {
                    work[6] = 0;
                    work[0] &= ~0x80000000u;
                    work[0x18 / 4] = 0;
                }
            }
            break;
        case 3:
            func_003c7990(0);
            if (func_003c7850())
                break;
            func_003c7650(0);
            result = func_003c7610(0);
            if (result == 1)
            {
                func_003c77a0();
                FUN_00206E40();
                break;
            }
            if (result != 0)
                break;
            work[0] &= ~0x4001u;
            effect = bpMisc001ff740();
            if (effect == 0)
            {
                func_003c7430(2);
            }
            else if (effect == 1)
            {
                if (FUN_002D5550() == 0x1a1)
                    func_003c7430(8);
                else
                    func_003c7430(5);
            }
            else
            {
                K_ASSERT(0, 0x5f1);
            }
            work[6] = 4;
            break;
        case 4:
            func_003c7990(1);
            if (func_003c7850())
                break;
            func_003c7650(1);
            func_003c77a0();
            FUN_00206E40();
            break;
        case 5:
            func_003c7990(0);
            if (func_003c7850())
                break;
            func_003c7650(0);
            result = func_003c7610(0);
            if (result == 1)
            {
                func_003c77a0();
                FUN_00206E40();
                break;
            }
            if (result != 0)
                break;
            work[0] &= ~0x20001u;
            effect = bpMisc001ff740();
            if (effect == 0)
            {
                func_003c7430(0xb);
            }
            else if (effect == 1)
            {
                func_003c7430(FUN_002D5550() == 0x1a1 ? 0xe : 0xb);
            }
            else
            {
                K_ASSERT(0, 0x62a);
            }
            work[6] = 6;
            break;
        case 6:
            func_003c7990(1);
            if (func_003c7850())
                break;
            func_003c7650(1);
            func_003c77a0();
            FUN_00206E40();
            break;
        case 7:
            func_003c7990(0);
            if (func_003c7850())
                break;
            func_003c7650(0);
            result = func_003c7610(0);
            if (result == 1)
            {
                func_003c77a0();
                FUN_00206E40();
                break;
            }
            if (result != 0)
                break;
            work[0] &= ~0x8001u;
            effect = bpMisc001ff740();
            if (effect == 1)
            {
                func_003c7430(0x11);
            }
            else
            {
                K_ASSERT(0, 0x660);
            }
            work[6] = 8;
            break;
        case 8:
            func_003c7990(1);
            if (func_003c7850())
                break;
            func_003c7650(1);
            func_003c77a0();
            FUN_00206E40();
            break;
        default:
            break;
        }
        break;
    case 7:
    case 8:
        break;
    case 9:
        if (!bpe00249600())
            FUN_00201A50();
        break;
    case 10:
        if (!func_002519d0())
        {
            bppMain0020fc90();
            if (work[2] & 4) func_00207f10();
            else if (work[2] & 1) FUN_002078A0();
            else FUN_00201A50();
        }
        break;
    case 11:
        if (!func_00251e80())
        {
            bppMain0020fc90();
            if (work[2] & 1) FUN_002078A0();
            else FUN_00201A50();
        }
        break;
    default:
        break;
    }

    if (renderFlags & 1) FUN_00201880();
    if (renderFlags & 2) FUN_002025E0();
    if (renderFlags & 4) FUN_002031C0();
    if (renderFlags & 8) FUN_00203C30();
    if (renderFlags & 0x10) FUN_00204CC0();
    if (renderFlags & 0x20) FUN_002060B0();
    if (renderFlags & 0x40) FUN_00206F70();
    if (work[0] & 0x40)
        work[0] &= ~0x40u;
}

// FUN_002016B0
void FUN_002016B0(void)
{
    u32 state;

    K_ASSERT(gBcmWork != NULL, 0x164);
    state = *(u32*)(gBcmWork + 0x10);
    if (state == 11)
    {
        return;
    }
    if (state == 10)
    {
        return;
    }
    if (state == 9)
    {
        return;
    }
    func_0021f410();
    func_00221b60();
}

// FUN_00201730
void FUN_00201730(void* work)
{
    u8* p;

    p = (u8*)work;
    *(u32*)p = 0;
    *(u32*)(p + 0x77a0) = 0;
    *(u32*)(p + 8) = 0;
    *(u32*)(p + 0x20) = bpMisc001ff740();
    func_0021f0c0(p + 0x430);
    gBcmWork = p;
}




// FUN_00201780
void FUN_00201780(void)
{
    u32* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = (u32*)gBcmWork;
    if (work[0] & 0x800000)
    {
        func_002083d0();
    }
    if (work[0] & 0x2000)
    {
        FUN_00206EB0();
    }
    if (work[0] & 0x1000)
    {
        FUN_00206310();
    }
    if (work[0] & 2)
    {
        FUN_00202BC0();
    }
    if (work[0] & 4)
    {
        bcm00203360();
    }
    if (work[0] & 8)
    {
        FUN_00203B70();
    }
    if (work[0] & 0x10)
    {
        FUN_00204BE0();
    }
    func_0021f140();
    gBcmWork = NULL;
}

#pragma opt_loop_invariants on
// FUN_00201880
void FUN_00201880(void)
{
    s32 i;
    u32 request;
    u8* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    for (i = 0; i < 7; i++)
    {
        u32 loopRequest;
        u32* entry;
        u32* flags;
        s32 selector;
        loopRequest = 0;
        entry = (u32*)work + i;
        flags = entry + 0x590;
        *flags &= ~1u;
        selector = i;
        switch (selector)
        {
        case 0:
            if (*(u32*)(work + 0xc) & 0x20) loopRequest = 1;
            break;
        case 1:
            if (*(u32*)(work + 0xc) & 1) loopRequest = 1;
            break;
        case 2:
            if (*(u32*)(work + 0xc) & 2) loopRequest = 1;
            break;
        case 3:
            if (*(u32*)(work + 0xc) & 4) loopRequest = 1;
            break;
        case 4:
            if (*(u32*)(work + 0xc) & 8) loopRequest = 1;
            break;
        case 5:
            if (*(u32*)(work + 0xc) & 0x10) loopRequest = 1;
            break;
        case 6:
            if (*(u32*)(work + 0xc) & 0x40) loopRequest = 1;
            break;
        }
        if (loopRequest)
        {
            *flags |= 1;
        }
    }
    if (*(u32*)work & 0x800000)
    {
        func_00208360();
    }
    request = bpRoot_003a5540_typed(100, 100, -0x4e, 0.0f, 2, 6,
                                    *(void**)(work + 0x7790),
                                    *(u32*)(work + 0x24));
    func_002082c0(request);
    *(u32*)(work + 0x6d28) = 0;
}

#pragma opt_loop_invariants off

// FUN_00201A50
void FUN_00201A50(void)
{
    u8* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    FUN_00201880();
    *(u32*)work |= 0x40;
    func_0021f150(*(u32*)(work + 0x24));
    FUN_0010a4e0(1, 0xf, 2, 0x11);
    *(u32*)(work + 0x10) = 0;
}


// FUN_00201ad0
void bcmDestroyOwnedResourceCallback(void)
{
    bcmDestroyOwnedResource();
}


// FUN_00201AF0
u32 FUN_00201AF0(void)
{
    u32 flags;

    K_ASSERT(gBcmWork != NULL, 0x164);
    flags = *(u32*)gBcmWork;
    return ((flags & 1) != 0 || (flags & 0x20000000) != 0);
}


// FUN_00201B50
void FUN_00201B50(void)
{
    u32* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    *(u32*)gBcmWork |= 1;
    K_ASSERT(gBcmWork != NULL, 0x164);
    work = (u32*)gBcmWork;
    FUN_00201880();
    if (*work & 2) FUN_002025E0();
    if (*work & 4) FUN_002031C0();
    if (*work & 8) FUN_00203C30();
    if (*work & 0x10) FUN_00204CC0();
}


// FUN_00201C30
void FUN_00201C30(void)
{
    u32* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    *(u32*)gBcmWork |= 0x20000000;
    K_ASSERT(gBcmWork != NULL, 0x164);
    work = (u32*)gBcmWork;
    FUN_00201880();
    if (*work & 2) FUN_002025E0();
    if (*work & 4) FUN_002031C0();
    if (*work & 8) FUN_00203C30();
    if (*work & 0x10) FUN_00204CC0();
}











static u8* panelMiscWork(void)
{
    return *(u8**)DAT_007ce3ec_abs;
}

























































































































// FUN_00201D10
void FUN_00201D10(void)
{
    u32* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = (u32*)gBcmWork;
    *work &= ~1u;
    *work |= 0x40;
    K_ASSERT(gBcmWork != NULL, 0x164);
    work = (u32*)gBcmWork;
    FUN_00201880();
    if (work[0] & 2) FUN_002025E0();
    if (work[0] & 4) FUN_002031C0();
    if (work[0] & 8) FUN_00203C30();
    if (work[0] & 0x10) FUN_00204CC0();
}

/* Removing this loses FUN_00201880 (MATCH nd0 -> MISMATCH nd307) - measured W161. */
// FUN_00201E00
void FUN_00201E00(void)
{
    u32* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = (u32*)gBcmWork;
    *work &= ~0x20000000u;
    *work |= 0x40;
    K_ASSERT(gBcmWork != NULL, 0x164);
    work = (u32*)gBcmWork;
    FUN_00201880();
    if (work[0] & 2) FUN_002025E0();
    if (work[0] & 4) FUN_002031C0();
    if (work[0] & 8) FUN_00203C30();
    if (work[0] & 0x10) FUN_00204CC0();
}
// FUN_00201EF0
void FUN_00201EF0(void)
{
    DatPersonaWork* persona;
    u16* skills;
    void* special;
    s32 count;
    s32 i;
    u32* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = (u32*)gBcmWork;
    persona = datPersonaGetByPcId(1);
    count = datPersonaCountValidSkills(persona);
    special = func_0030c0c0();
    skills = datPersonaGetSkills(persona);
    for (i = 0; i < count; i++)
    {
        if (FUN_002055F0(skills[i]))
        {
            break;
        }
    }
    if (special == NULL && i == count)
    {
        work[0] |= 0x80;
    }
    else if ((work[0x77a0 / 4] & 2) == 0)
    {
        work[3] |= 1;
    }
}

// FUN_00202010
void FUN_00202010(void)
{
    u8* p;
    DatPersonaWork* persona;
    u16* skills;
    s32 count;
    s32 i;
    s32 out;
    u32 selectedSkill;
    s32 visible;
    u16* special;
    u8* row;
    u8* rowBase;
    u8* misc;
    u8* misc2;

    K_ASSERT(gBcmWork != NULL, 0x164);
    p = gBcmWork;
    rowBase = p + 0x4a90;
    misc = (u8*)(uintptr_t)bpMisc001ff500(1);
    K_ASSERT((~*(u32*)p & 2) != 0, 0x7c0);
    persona = datPersonaGetByPcId(1);
    count = datPersonaCountValidSkills(persona);
    skills = datPersonaGetSkills(persona);
    out = 0;
    special = (u16*)func_0030c0c0();
    if (special != NULL)
    {
        *(u32*)(p + 0x28) = 0;
        *(u16*)(p + 0x2c) = *special;
        *(u32*)(p + 0x28) |= 2;
        if (func_003086f0(*(u32*)(misc + 0xa2c), *(u16*)(p + 0x2c)))
        {
            *(u32*)(p + 0x28) |= 1;
        }
        out++;
    }
    for (i = 0; i < count; i++)
    {
        if (!FUN_002055F0(skills[i]))
        {
            continue;
        }
        *(u16*)(p + out * 8 + 0x2c) = skills[i];
        *(u32*)(p + out * 8 + 0x28) = 0;
        if (func_003086f0(*(u32*)(misc + 0xa2c),
                          *(u16*)(p + out * 8 + 0x2c)))
        {
            *(u32*)(p + out * 8 + 0x28) |= 1;
        }
        out++;
    }
    K_ASSERT(out != 0, 0x7e3);
    K_ASSERT(out <= 9, 0x7e4);
    *(u32*)(p + 0x74) = out;
    *(u32*)(p + 0x70) = out;
    if (out > 4)
    {
        *(u32*)(p + 0x70) = 4;
    }
    misc2 = (u8*)(uintptr_t)bpMisc001ff500(1);
    *(u32*)(p + 0x7658) = 0;
    *(u32*)(p + 0x7660) = *(u32*)(p + 0x70);
    *(u32*)(p + 0x7668) = *(u32*)(p + 0x74);
    func_00208570(p + 0x7658);
    if (datGetFlag(0x186))
    {
        selectedSkill = FUN_0016F380(0x31);
        if (selectedSkill == 0)
        {
            *(u32*)(p + 0x7664) = 0;
            *(u32*)(p + 0x765c) = 0;
        }
        else
        {
            u32 selectedId;
            s32 selectedIndex;
            s32 skillCount;

            selectedId = (u16)selectedSkill;
            selectedIndex = 0;
            skillCount = *(s32*)(p + 0x74);
            for (; selectedIndex < skillCount; selectedIndex++)
            {
                if (*(u16*)(p + 0x2c + selectedIndex * 8) == selectedId)
                {
                    break;
                }
            }
            if (selectedIndex == skillCount)
            {
                *(u32*)(p + 0x7664) = 0;
                *(u32*)(p + 0x765c) = 0;
            }
            else if (selectedIndex == skillCount - 1)
            {
                *(u32*)(p + 0x765c) =
                    selectedIndex - (*(s32*)(p + 0x70) - 1);
                *(u32*)(p + 0x7664) = selectedIndex;
            }
            else if (*(s32*)(p + 0x70) - 2 < selectedIndex)
            {
                *(u32*)(p + 0x765c) =
                    selectedIndex - (*(s32*)(p + 0x70) - 2);
                *(u32*)(p + 0x7664) = selectedIndex;
            }
            else
            {
                *(u32*)(p + 0x765c) = 0;
                *(u32*)(p + 0x7664) = selectedIndex;
            }
        }
    }
    else
    {
        *(u32*)(p + 0x7664) = 0;
        *(u32*)(p + 0x765c) = 0;
    }
    FUN_002024B0();
    visible = *(s32*)(p + 0x74);
    if (visible > 4)
    {
        visible = 4;
    }
    for (i = 0; i < visible; i++)
    {
        u16* skill;

        row = rowBase + i * 0x510;
        *(u32*)row = 0;
        if (*(u32*)(p + i * 8 + 0x28) & 1)
        {
            *(u32*)row |= 1;
        }
        if (*(u32*)(p + i * 8 + 0x28) & 2)
        {
            *(u32*)row |= 2;
        }
        *(u32*)(row + 4) = *(u32*)(p + i * 4 + 0x78);
        skill = (u16*)(p + i * 8 + 0x2c);
        switch (((u8*)((uintptr_t)gp0xffffb708 + *skill * 0x2c))[3])
        {
        case 1:
            *(u32*)(row + 8) = 0;
            break;
        case 2:
            *(u32*)(row + 8) = 1;
            break;
        }
        *(u32*)(row + 0xc) =
            func_003083f0(*(u32*)(misc2 + 0xa2c), *skill);
    }
    *(u32*)(p + 0x7640) = 0;
    *(u32*)(p + 0x64a0) = visible;
    *(u32*)(p + 0x6498) = *(u32*)(p + 0x7664);
    *(u32*)(p + 0x649c) = *(u32*)(p + 0x765c);
    *(u32*)(p + 0x64a4) = *(u32*)(p + 0x74);
    *(u32*)(p + 0x6d24) = 0;
    *(u32*)(p + 0x6d28) = 1;
    bcmPanel00222a60();
    FUN_0010a4e0(0, 0, 0, 3);
    *(u32*)(p + 0x10) = 1;
}

// FUN_002024B0
void FUN_002024B0(void)
{
    u8* p;
    s32 i;
    u32 handle;
    extern void func_003b2c60(u32, f32);

    K_ASSERT(gBcmWork != NULL, 0x164);
    p = gBcmWork;
    func_003b0e70(1);
    func_003b0e90(2);
    for (i = 0; i < *(s32*)(p + 0x70); i++)
    {
        handle = func_003b0970(
            func_0030bb40(*(u16*)(p + 0x2c + i * 8)),
            2, (s8)(i == 0 ? 6 : 0), 0, 0);
        func_003b2c60(handle, 0.0f);
        func_003b0e20(handle, -1);
        *(u32*)(p + 0x78 + i * 4) = handle;
    }
    func_003b0e90(1);
    func_003b0e70(2);
    *(u32*)p |= 2;
}

// FUN_002025E0
void FUN_002025E0(void)
{
    u8* work;
    u8* rowBase;
    u8* misc;
    u8* row;
    s32 i;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    rowBase = work + 0x4a90;
    K_ASSERT((*(u32*)work & 2) != 0, 0x87c);
    misc = (u8*)bpMisc001ff500(1);
    FUN_00202A10();
    for (i = 0; i < *(s32*)(work + 0x70); i++)
    {
        row = rowBase + i * 0x510;
        *(u32*)row = 0;
        *(u32*)(row + 4) = *(u32*)(work + 0x78 + i * 4);
        if (*(u32*)(work + 0x28 +
                    (i + *(u32*)(work + 0x765c)) * 8) & 1)
        {
            *(u32*)row |= 1;
        }
        if (*(u32*)(work + 0x28 +
                    (i + *(u32*)(work + 0x765c)) * 8) & 2)
        {
            *(u32*)row |= 2;
        }
        switch (((u8*)((uintptr_t)DAT_007ce3f8 +
                       (u16)*(u16*)(work + 0x2c +
                                    (i + *(u32*)(work + 0x765c)) * 8) *
                       0x2c))[3])
        {
        case 1:
            *(u32*)(row + 8) = 0;
            break;
        case 2:
            *(u32*)(row + 8) = 1;
            break;
        }
        *(u32*)(row + 0xc) = func_003083f0(
            *(u32*)(misc + 0xa2c),
            *(u16*)(work + 0x2c +
                    (i + *(u32*)(work + 0x765c)) * 8));
    }
    *(u32*)(work + 0x7640) = 0;
    *(u32*)(work + 0x64a0) = *(u32*)(work + 0x70);
    *(u32*)(work + 0x6498) = *(u32*)(work + 0x7664);
    *(u32*)(work + 0x649c) = *(u32*)(work + 0x765c);
    *(u32*)(work + 0x64a4) = *(u32*)(work + 0x74);
    *(u32*)(work + 0x6d28) = 0;
    if (bcm00207930(*(u16*)(
            (u8*)(uintptr_t)(*(u32*)(work + 0x7664) * 8) +
            (uintptr_t)work + 0x2c)))
    {
        *(u32*)(work + 0x6d28) = 1;
        *(u32*)(work + 0x6d24) = FUN_00207960(*(u16*)(
            (u8*)(uintptr_t)(*(u32*)(work + 0x7664) * 8) +
            (uintptr_t)work + 0x2c));
    }
    bcmPanel00222b90();
}

// FUN_00202830 MATCHING
void FUN_00202830(void)
{
    u8* work;
    u32* output;
    u32 handle;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    *(u32*)work |= 0x20;
    func_003b0e70(1);
    func_003b0e90(2);
    handle = func_003b0970(
        func_0030bb40(*(u16*)((u8*)(uintptr_t)(*(u32*)(work + 0x7664) * 8) +
                              (uintptr_t)work + 0x2c)),
        2, 6, 0, 0);
    *(u32*)(work + 0x88) = handle;
    func_003b0e90(1);
    func_003b0e70(2);
    output = (u32*)(work + 0x7130);
    output[0] = 0;
    output[1] = *(u32*)(work + 0x88);
    if (*(u32*)((u8*)(uintptr_t)(*(u32*)(work + 0x7664) * 8) +
                (uintptr_t)work + 0x28) & 1)
        output[0] |= 1;
    if (*(u32*)((u8*)(uintptr_t)(*(u32*)(work + 0x7664) * 8) +
                (uintptr_t)work + 0x28) & 2)
        output[0] |= 2;
    switch (((u8*)(uintptr_t)((u16)*(u16*)((u8*)(uintptr_t)(
                  *(u32*)(work + 0x7664) * 8) +
              (uintptr_t)work + 0x2c) *
             0x2c) +
             (uintptr_t)DAT_007ce3f8)[3])
    {
    case 1:
        output[2] = 0;
        break;
    case 2:
        output[2] = 1;
        break;
    }
    output[3] = func_003083f0(
        *(u32*)((u8*)(uintptr_t)bpMisc001ff500(1) + 0xa2c),
        *(u16*)((u8*)(uintptr_t)(*(u32*)(work + 0x7664) * 8) +
                (uintptr_t)work + 0x2c));
    func_0022bf60();
    printf("");
    FUN_0016F3E0(0x31, *(u16*)((u8*)(uintptr_t)(*(u32*)(work + 0x7664) * 8) +
                              (uintptr_t)work + 0x2c));
}


// FUN_00202A10
void FUN_00202A10(void)
{
    s32 destroyIndex;
    s32 rowIndex;
    u8* work;
    u32 handle;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    for (destroyIndex = 0; destroyIndex < *(s32*)(work + 0x70);
         destroyIndex++)
    {
        func_003b0170(*(u32*)(work + 0x78 + destroyIndex * 4));
    }
    if (*(u32*)work & 0x800000)
    {
        func_00208360();
    }
    handle = bpRoot_003a5540_typed(
        100, 100, -1, 0.0f, 2, 6, (void*)func_003c7d60(7),
        *(u16*)((u8*)(uintptr_t)(*(s32*)(work + 0x7664) * 8) +
                 (uintptr_t)work + 0x2c));
    func_002082c0(handle);
    func_003b0e70(1);
    func_003b0e90(2);
    for (rowIndex = 0; rowIndex < *(s32*)(work + 0x70); rowIndex++)
    {
        u8* entry;
        entry = work +
                (rowIndex + *(s32*)(work + 0x765c)) * 8 + 0x28;
        handle = func_003b0970(
            func_0030bb40(*(u16*)(entry + 4)), 2,
            (s8)(rowIndex == *(s32*)(work + 0x7664) -
                                *(s32*)(work + 0x765c) ? 6 : 0),
            0, 0);
        *(u32*)(work + 0x78 + rowIndex * 4) = handle;
    }
    func_003b0e90(1);
    func_003b0e70(2);
}



// FUN_00202BC0
void FUN_00202BC0(void)
{
    s32 i;
    u8* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    K_ASSERT((*(u32*)work & 2) != 0, 0x910);
    for (i = 0; i < *(s32*)(work + 0x70); i++)
    {
        func_003b0170(*(u32*)(work + 0x78 + i * 4));
    }
    if (*(u32*)work & 0x20)
    {
        func_003b0170(*(u32*)(work + 0x88));
    }
    *(u32*)work &= ~2u;
}


// FUN_00202C90
void FUN_00202C90(void)
{
    u8* p;
    s32 i;

    K_ASSERT(gBcmWork != NULL, 0x164);
    p = gBcmWork;
    for (i = 0; i < 0xdf; i++)
    {
        if (FUN_00205650((u16)(0xfa0 + i)) &&
            func_00170760(1, (s16)(0xfa0 + i)))
        {
            break;
        }
    }
    if (i == 0xdf)
    {
        *(u32*)p |= 0x100;
    }
    else if ((*(u32*)(p + 0x77a0) & 4) == 0)
    {
        *(u32*)(p + 0xc) |= 2;
    }
}

// W419 negative probe: FUN_00202D70 s32 loop index nd407/672B, window704B, rate60.57%; reverted.
// FUN_00202D70 NONMATCHING
void FUN_00202D70(void)
{
    u8* work;
    u8* rows;
    s32 scan;
    s32 out;
    s16 i;
    s32 selected;
    s32 start;
    s32 visible;
    u32 selectedValue;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    rows = work + 0x4a90;
    out = 0;
    for (scan = 0; scan < 0xdf; scan++)
    {
        if (FUN_00205650((u16)(scan + 0xfa0)) &&
            func_00170760(1, (s16)(scan + 0xfa0)))
        {
            *(u16*)(work + 0x9c + out * 2) = scan + 0xfa0;
            out++;
        }
    }
    *(u32*)(work + 0x260) = out;
    FUN_00203030();
    *(u32*)(work + 0x768c) = 0;
    *(u32*)(work + 0x7694) = *(u32*)(work + 0x25c);
    *(u32*)(work + 0x769c) = *(u32*)(work + 0x260);
    func_00208570(work + 0x768c);

    if (datGetFlag(0x186))
    {
        selectedValue = FUN_0016F380(0x32);
        if (selectedValue == 0)
        {
            selected = 0;
            start = 0;
        }
        else
        {
            for (selected = 0; selected < out; selected++)
            {
                if (*(u16*)(work + 0x9c + selected * 2) ==
                    selectedValue)
                    break;
            }
            if (selected == out)
            {
                selected = 0;
                start = 0;
            }
            else if (selected == out - 1)
            {
                start = selected - (*(s32*)(work + 0x25c) - 1);
            }
            else if (*(s32*)(work + 0x25c) - 2 < selected)
            {
                start = selected - (*(s32*)(work + 0x25c) - 2);
            }
            else
            {
                start = 0;
            }
        }
    }
    else
    {
        selected = 0;
        start = 0;
    }
    *(u32*)(work + 0x7698) = selected;
    *(u32*)(work + 0x7690) = start;

    visible = out;
    if (visible >= 5)
        visible = 4;
    for (i = 0; i < visible; i++)
    {
        *(u32*)(rows + i * 0x410) =
            *(u32*)(work + 0x8c + i * 4);
        *(u32*)(rows + i * 0x410 + 4) =
            func_00170760(1, *(s16*)(work + 0x9c +
                                     (start + i) * 2));
    }
    *(u32*)(work + 0x7640) = 0;
    *(u32*)(work + 0x64a0) = visible;
    *(u32*)(work + 0x6498) = *(u32*)(work + 0x7698);
    *(u32*)(work + 0x649c) = *(u32*)(work + 0x7690);
    *(u32*)(work + 0x64a4) = *(u32*)(work + 0x260);
    *(u32*)(work + 0x6d28) = 0;
    bcmPanel00222930();
    FUN_0010a4e0(0, 0, 0, 3);
    *(u32*)(work + 0x10) = 2;
}

// FUN_00203030
void FUN_00203030(void)
{
    u8* work;
    s32 i;
    u32 handle;
    extern void func_003b2c60(u32, f32);

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    func_003b0e70(1);
    func_003b0e90(2);
    for (i = 0; i < 4; i++)
    {
        if (i >= *(s32*)(work + 0x260))
            break;
        if (i == 0)
        {
            handle = func_003b0970(
                (u32)func_00171110(*(s16*)(work + 0x9c + i * 2), 0),
                2, 6, 0, 0);
        }
        else
        {
            handle = func_003b0970(
                (u32)func_00171110(*(s16*)(work + 0x9c + i * 2), 0),
                2, 0, 0, 0);
        }
        func_003b0d70(handle, 0x730, (i * 9 * 2 + 0x118) * 8);
        func_003b2c60(handle, 0.0f);
        func_003b0e20(handle, -1);
        *(u32*)(work + 0x8c + i * 4) = handle;
    }
    *(u32*)(work + 0x25c) = i;
    func_003b0e90(1);
    func_003b0e70(2);
    *(u32*)work |= 4;
}

// FUN_002031C0
void FUN_002031C0(void)
{
    u8* work;
    u32* rows;
    s32 i;
    s32 visible;
    u32* row;
    s16 id;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    rows = (u32*)(work + 0x4a90);
    K_ASSERT((*(u32*)work & 4) != 0, 0x9e0);
    FUN_00203410();
    visible = *(s32*)(work + 0x260);
    if (visible > 4)
    {
        visible = 4;
    }
    for (i = 0; i < visible; i++)
    {
        row = rows + i * 0x104;
        row[0] = *(u32*)(work + 0x8c + i * 4);
        id = *(volatile s16*)(work + 0x9c +
                              (*(s32*)(work + 0x7690) + i) * 2);
        row[1] = func_00170760(1, id);
    }
    *(u32*)(work + 0x7640) = 0;
    *(u32*)(work + 0x64a0) = visible;
    *(u32*)(work + 0x6498) = *(u32*)(work + 0x7698);
    *(u32*)(work + 0x649c) = *(u32*)(work + 0x7690);
    *(u32*)(work + 0x64a4) = *(u32*)(work + 0x260);
    *(u32*)(work + 0x6d28) = 0;
    if (bcmIsItemUsable(func_0030bc20(
            *(u16*)((u8*)(uintptr_t)(*(s32*)(work + 0x7698) * 2) +
                    (uintptr_t)work + 0x9c))))
    {
        *(u32*)(work + 0x6d28) = 1;
        *(u32*)(work + 0x6d24) = FUN_00207960(
            (u16)func_0030bc20(
                *(u16*)((u8*)(uintptr_t)(*(s32*)(work + 0x7698) * 2) +
                        (uintptr_t)work + 0x9c)));
    }
    FUN_00222d60();
}


// FUN_00203360
void bcmDestroyCommandResources(void)
{
    u32* puVar1;
    int iVar2;

    K_ASSERT(gBcmWork != NULL, 0x164);
    puVar1 = (u32*)gBcmWork;
    for (iVar2 = 0; iVar2 < (int)puVar1[0x97]; iVar2++) {
        FUN_003b0170(*(u32*)((int)puVar1 + iVar2 * 4 + 0x8c));
    }
    if ((*puVar1 & 0x20) != 0) {
        FUN_003b0170(puVar1[0x99]);
    }
    *puVar1 &= 0xfffffffb;
}

// FUN_00203410
void FUN_00203410(void)
{
    u8* work;
    s32 destroyIndex;
    s32 rowIndex;
    s32 targetIndex;
    u32 handle;
    extern void func_003b2c60(u32, f32);

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    for (destroyIndex = 0; destroyIndex < *(s32*)(work + 0x25c);
         destroyIndex++)
    {
        func_003b0170(*(u32*)(work + 0x8c + destroyIndex * 4));
    }
    if (*(u32*)work & 0x800000)
    {
        func_00208360();
    }
    handle = bpRoot_003a5540_typed(
        100, 100, -1, 0.0f, 2, 6, (void*)func_003c7d60(5),
        *(u16*)((u8*)(uintptr_t)(*(s32*)(work + 0x7698) * 2) +
                 (uintptr_t)work + 0x9c) - 0xfa0);
    func_002082c0(handle);
    func_003b0e70(1);
    func_003b0e90(2);
    for (rowIndex = 0; rowIndex < *(s32*)(work + 0x25c); rowIndex++)
    {
        targetIndex = rowIndex + *(s32*)(work + 0x7690);
        if (*(s32*)(work + 0x7698) == targetIndex)
        {
            handle = func_003b0970(
                (u32)func_00171110(
                    *(s16*)(work + 0x9c + targetIndex * 2), 0),
                2, 6, 0, 0);
        }
        else
        {
            handle = func_003b0970(
                (u32)func_00171110(
                    *(s16*)(work + 0x9c + targetIndex * 2), 0),
                2, 0, 0, 0);
        }
        func_003b0d70(handle, 0x730,
                      (rowIndex * 9 * 2 + 0x118) * 8);
        func_003b2c60(handle, 0.0f);
        func_003b0e20(handle, -1);
        *(u32*)(work + 0x8c + rowIndex * 4) = handle;
    }
    func_003b0e90(1);
    func_003b0e70(2);
}
// FUN_00203630
void FUN_00203630(void)
{
    u8* work;
    u32* output;
    u16 selectedId;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    *(u32*)work |= 0x20;
    func_003b0e70(1);
    func_003b0e90(2);
    *(u32*)(work + 0x264) = func_003b0970(
        (u32)func_00171110(
            *(s16*)((u8*)(uintptr_t)(*(u32*)(work + 0x7698) * 2) +
                    (uintptr_t)work + 0x9c), 0),
        2, 6, 0, 0);
    func_003b0e90(1);
    func_003b0e70(2);
    output = (u32*)(work + 0x7130);
    output[0] = *(u32*)(work + 0x264);
    selectedId = *(u16*)((u8*)(uintptr_t)(*(u32*)(work + 0x7698) * 2) +
                         (uintptr_t)work + 0x9c);
    output[1] = func_00170760(1, (s16)selectedId);
    func_0022c0e0();
    printf("");
    FUN_0016F3E0(
        0x32, *(u16*)((u8*)(uintptr_t)(*(u32*)(work + 0x7698) * 2) +
                     (uintptr_t)work + 0x9c));
}
// FUN_00203760
void FUN_00203760(void)
{
    u8* work;
    s32 count;
    u32 heroId;
    s32 i;
    DatPersonaWork* persona;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    count = (u16)func_001756f0();
    heroId = datPersonaGetByPcId(1)->id;
    for (i = 0; i < count; i++)
    {
        persona = datPersonaGetHeroPersona((s16)i);
        if (persona->id != heroId)
            break;
    }
    if (i == count)
    {
        *(u32*)work |= 0x400;
        return;
    }
    if ((*(u32*)(work + 0x77a0) & 8) == 0)
        *(u32*)(work + 0xc) |= 8;
}

// FUN_00203850
void FUN_00203850(void)
{
    u8* work;
    u8* itemBase;
    s32 i;
    s32 count;
    u8* row;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    itemBase = work + 0x4a90;
    FUN_00203990();
    *(u32*)(work + 0x76c0) = 0;
    *(u32*)(work + 0x76c4) = 0;
    *(u32*)(work + 0x76cc) = 0;
    *(u32*)(work + 0x76c8) = *(u32*)(work + 0x2d8);
    *(u32*)(work + 0x76d0) = *(u32*)(work + 0x2dc);
    func_00208570(work + 0x76c0);
    count = *(s32*)(work + 0x2dc);
    if (count > 4)
        count = 4;
    for (i = 0; i < count; i++)
    {
        row = itemBase + i * 0x310;
        *(u32*)(row + 0x300) = *(u32*)(work + 0x2c8 + i * 4);
        *(u32*)(row + 0x304) =
            *(u32*)(work + 0x26c + (i + *(u32*)(work + 0x76c4)) * 8);
    }
    *(u32*)(work + 0x7640) = 0;
    *(u32*)(work + 0x64a0) = count;
    *(u32*)(work + 0x6498) = *(u32*)(work + 0x76cc);
    *(u32*)(work + 0x649c) = *(u32*)(work + 0x76c4);
    *(u32*)(work + 0x64a4) = *(u32*)(work + 0x2dc);
    bcmPanel00224660();
    FUN_0010a4e0(0, 0, 0, 3);
    *(u32*)(work + 0x14) = 0;
    *(u32*)(work + 0x10) = 3;
}

// FUN_00203990
void FUN_00203990(void)
{
    u8* work;
    s32 personaCount;
    s32 scanIndex;
    s32 count;
    u32 heroId;
    u32 handle;
    s32 rowIndex;
    DatPersonaWork* persona;
    extern void func_003b2c60(u32, f32);

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    personaCount = (u16)func_001756f0();
    count = 0;
    persona = datPersonaGetByPcId(1);
    heroId = persona->id;
    *(u16*)(work + 0x268) = heroId;
    *(u32*)(work + 0x26c) = persona->level;
    count++;
    for (scanIndex = 0; scanIndex < personaCount; scanIndex++)
    {
        persona = datPersonaGetHeroPersona((s16)scanIndex);
        if (persona->id != heroId)
        {
            *(u16*)(work + 0x268 + count * 8) = persona->id;
            *(u32*)(work + 0x26c + count * 8) = persona->level;
            count++;
        }
    }
    *(u32*)(work + 0x2dc) = count;
    *(u32*)(work + 0x2d8) = count;
    if (count > 4)
        *(u32*)(work + 0x2d8) = 4;
    func_003b0e70(1);
    func_003b0e90(2);
    for (rowIndex = 0; rowIndex < *(s32*)(work + 0x2d8); rowIndex++)
    {
        handle = func_003b0970(
            func_00173220(*(u16*)(work + 0x268 + rowIndex * 8)),
            2, 6, 0, 0);
        func_003b0d70(handle, 0x730, (rowIndex * 9 * 2 + 0x118) * 8);
        func_003b2c60(handle, 0.0f);
        func_003b0e20(handle, -1);
        *(u32*)(work + 0x2c8 + rowIndex * 4) = handle;
    }
    func_003b0e90(1);
    func_003b0e70(2);
    *(u32*)work |= 8;
}

// FUN_00203B70
void FUN_00203B70(void)
{
    u8* p;
    s32 i;

    K_ASSERT(gBcmWork != NULL, 0x164);
    p = gBcmWork;
    K_ASSERT((*(u32*)p & 8) != 0, 0xaf6);
    for (i = 0; i < (s32)*(u32*)(p + 0x2d8); i++)
    {
        func_003b0170(*(u32*)(p + 0x2c8 + i * 4));
    }
    *(u32*)p &= ~8u;
}

// FUN_00203C30
void FUN_00203C30(void)
{
    u8* work;
    u8* rows;
    s32 i;
    s32 j;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    rows = work + 0x4a90;
    K_ASSERT((*(u32*)work & 8) != 0, 0xb07);
    FUN_00203DE0();
    for (i = 0; i < *(s32*)(work + 0x2d8); i++)
    {
        if (i == *(s32*)(work + 0x76cc) -
                 *(s32*)(work + 0x76c4))
        {
            K_ASSERT(gBcmWork != NULL, 0x164);
        }
    }
    for (i = 0; i < *(s32*)(work + 0x2d8); i++)
    {
        func_003b0d70(*(u32*)(work + 0x2c8 + i * 4),
                      0x730, (i * 18 + 0x118) * 8);
    }
    for (j = 0; j < *(s32*)(work + 0x2d8); j++)
    {
        *(u32*)(rows + j * 0x310 + 0x300) =
            *(u32*)(work + 0x2c8 + j * 4);
        *(u32*)(rows + j * 0x310 + 0x304) =
            *(u32*)(work + 0x26c +
                    (j + *(s32*)(work + 0x76c4)) * 8);
    }
    *(u32*)(work + 0x7640) = 0;
    *(u32*)(work + 0x64a0) = *(u32*)(work + 0x2d8);
    *(u32*)(work + 0x6498) = *(u32*)(work + 0x76cc);
    *(u32*)(work + 0x649c) = *(u32*)(work + 0x76c4);
    *(u32*)(work + 0x64a4) = *(u32*)(work + 0x2dc);
    FUN_00224860();
}

// FUN_00203DE0
void FUN_00203DE0(void)
{
    u8* work;
    u32 heroId;
    s32 mode;
    u16 id;
    u32 handle;
    s32 i;
    extern void func_003b2c60(u32, f32);

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    heroId = datPersonaGetByPcId(1)->id;
    for (i = 0; i < *(s32*)(work + 0x2d8); i++)
        func_003b0170(*(u32*)(work + 0x2c8 + i * 4));
    func_003b0e70(1);
    func_003b0e90(2);
    i = 0;
    heroId = (u16)heroId;
    while (i < *(s32*)(work + 0x2d8))
    {
        if (i == *(s32*)(work + 0x76cc) - *(s32*)(work + 0x76c4))
            mode = 6;
        else
            mode = 0;
        id = *(u16*)(work + 0x268 +
                     (i + *(s32*)(work + 0x76c4)) * 8);
        if (id == heroId)
            mode = 6;
        handle = func_003b0970(
            func_00173220(id), 2, (s8)mode, 0, 0);
        func_003b0d70(handle, 0x730, (i * 9 * 2 + 0x118) * 8);
        func_003b2c60(handle, 0.0f);
        id = *(u16*)(work + 0x268 +
                     (i + *(s32*)(work + 0x76c4)) * 8);
        if (id == heroId)
        {
            if (i == *(s32*)(work + 0x76cc) -
                     *(s32*)(work + 0x76c4))
                func_003b0e20(handle, 0xffe678ff);
            else
                func_003b0e20(handle, 0x785a28ff);
        }
        else
        {
            func_003b0e20(handle, -1);
        }
        *(u32*)(work + 0x2c8 + i * 4) = handle;
        i++;
    }
    func_003b0e90(1);
    func_003b0e70(2);
}

// W418 negative probes: FUN_00204000 i s16 nd646/1140B -> 667/1180B (over 1152B); FUN_00204760 i s16 nd390/876B -> 532/900B (reverted).
// W419 negative probe: FUN_00204000 direct data.ids[i] nd680/1140B, window1152B, rate59.65%; reverted.
// FUN_00204000 NONMATCHING
void FUN_00204000(void)
{
    struct
    {
        u16 tactics[4];
        u16 ids[4];
        u32 handles[4];
    } data;
    u8* work;
    u8* entry;
    s32 offset;
    u8* row;
    s32 i;
    u16* currentId;
    s32 count;
    s32 filtered;
    s32 dst;
    u16 id;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    entry = DAT_007ce3ec;
    K_ASSERT((~*(u32*)work & 0x10) != 0, 0xb85);
    count = 0;
    entry = *(u8**)(entry + 0x150);
    while (entry != NULL)
    {
        if ((~*(u32*)(entry + 0x9c) & 8) == 0)
        {
            id = *(u16*)(*(u8**)(entry + 0xa2c) + 2);
            if (id != 1)
            {
                data.handles[count] = *(u32*)(entry + 0xa8);
                offset = count * 2;
                *(u16*)((u8*)data.ids + offset) = id;
                *(u16*)((u8*)data.tactics + offset) =
                    datGetAiTactic((s16)id);
                count++;
            }
        }
        entry = *(u8**)(entry + 0xa34);
    }

    filtered = 0;
    for (i = 0; i < count; i++)
    {
        currentId = &data.ids[i];
        id = *currentId;
        switch (id)
        {
            case 2:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                if (datGetScenarioMode() != 0 &&
                    id == 9 && data.tactics[i] == 10)
                    continue;
                break;
            case 1:
                K_ASSERT(0, 0xbaf);
                break;
            case 3:
                if (data.tactics[i] == 10)
                    continue;
                break;
            case 0:
            default:
                break;
        }
        filtered++;
    }

    dst = 0;
    if (filtered >= 2)
    {
        *(u32*)(work + 0x2e0) = 0;
        *(u32*)(work + 0x2e4) = 0;
        dst++;
    }
    for (i = 0; i < count; i++)
    {
        row = work + 0x2e0 + dst * 0x18;
        *(u32*)row = 0;
        *(u32*)(row + 4) = 1;
        *(u32*)(row + 8) = data.handles[i];
        *(u16*)(row + 0xc) = data.ids[i];
        *(u32*)(row + 0x10) = data.tactics[i];
        if (data.tactics[i] == 10)
            *(u32*)row |= 2;
        dst++;
    }

    *(u32*)work &= ~0x4000u;
    *(u32*)work &= ~0x8000u;
    *(u32*)work &= ~0x10000u;
    *(u32*)work &= ~0x20000u;
    *(u32*)work &= ~0x40000u;
    *(u32*)work &= ~0x80000u;

    switch (*(u32*)(work + 0x20))
    {
        case 0:
        case 1:
            if (func_002db450(2))
            {
                *(u32*)work |= 0x4000;
                *(u32*)work |= 0x20000;
            }
            if (func_002db450(1))
            {
                *(u32*)work |= 0x8000;
                *(u32*)work |= 0x40000;
            }
            if (func_002db450(0))
            {
                *(u32*)work |= 0x10000;
                *(u32*)work |= 0x80000;
            }
            *(u32*)work &= ~0x100000u;
            if (datGetFlag(0x1300))
                *(u32*)work |= 0x100000;
            *(u32*)work &= ~0x200000u;
            if (func_002db480())
                *(u32*)work |= 0x200000;
            *(u32*)(work + 0x77b0) = (u16)func_002db480();
            row = work + 0x2e0 + dst * 0x18;
            *(u32*)row = 0;
            *(u32*)(row + 4) = 2;
            dst++;
            break;
        case 2:
        default:
            break;
    }

    *(u32*)(work + 0x3a8) = dst;
    *(u32*)(work + 0x3ac) = dst;
    if (dst > 7)
        *(u32*)(work + 0x3ac) = 7;
    if ((*(u32*)(work + 0x77a0) & 0x40) == 0)
    {
        if (dst != 0)
            *(u32*)(work + 0xc) |= 4;
        else
            *(u32*)work |= 0x200;
    }
}

#pragma opt_loop_invariants on
// FUN_00204480
void FUN_00204480(void)
{
    u8* work;
    u8* itemBase;
    u8* srcRow;
    u8* dstRow;
    s32 i;
    s32 j;
    s32 count;
    s32 found;
    s32 selected;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    itemBase = work + 0x4a90;
    *(u32*)(work + 0x76f4) = 0;
    *(u32*)(work + 0x76fc) = *(u32*)(work + 0x3ac);
    *(u32*)(work + 0x7704) = *(u32*)(work + 0x3a8);
    func_00208570(work + 0x76f4);
    if (datGetFlag(0x186) != 0)
    {
        selected = FUN_0016F380(0x33);
        if (selected == 0)
        {
            *(u32*)(work + 0x7700) = 0;
            *(u32*)(work + 0x76f8) = 0;
        }
        else
        {
            found = 0;
            i = 0;
            count = *(u32*)(work + 0x3a8);
            for (; i < count; i++)
            {
                srcRow = work + 0x2e0 + i * 0x18;
                switch (*(u32*)(srcRow + 4))
                {
                    case 1:
                        if (selected == *(u16*)(srcRow + 0xc))
                            found = 1;
                        break;
                    case 0:
                        if (selected == 0xc)
                            found = 1;
                        break;
                    case 2:
                        if (selected == 0xb)
                            found = 1;
                        break;
                    default:
                        break;
                }
                if (found != 0)
                    break;
            }
            if (i == count)
            {
                *(u32*)(work + 0x7700) = 0;
                *(u32*)(work + 0x76f8) = 0;
            }
            else
            {
                *(u32*)(work + 0x7700) = i;
                *(u32*)(work + 0x76f8) = 0;
            }
        }
    }
    else
    {
        *(u32*)(work + 0x7700) = 0;
        *(u32*)(work + 0x76f8) = 0;
    }
    FUN_00204760();
    for (j = 0; j < *(s32*)(work + 0x3ac); j++)
    {
        srcRow = work + 0x2e0 + j * 0x18;
        dstRow = itemBase + j * 0x420;
        *(u32*)(dstRow + 0x410) = 0;
        switch (*(u32*)(srcRow + 4))
        {
            case 1:
                *(u32*)dstRow = 0;
                *(u32*)(dstRow + 8) =
                    *(u32*)(work + 0x370 + j * 8);
                *(u32*)(dstRow + 0xc) =
                    *(u32*)(work + 0x374 + j * 8);
                break;
            case 0:
                *(u32*)dstRow = 1;
                *(u32*)(dstRow + 8) =
                    *(u32*)(work + 0x370 + j * 8);
                break;
            case 2:
                *(u32*)dstRow = 2;
                *(u32*)(dstRow + 8) =
                    *(u32*)(work + 0x370 + j * 8);
                *(u32*)(dstRow + 0xc) =
                    *(u32*)(work + 0x374 + j * 8);
                break;
            default:
                break;
        }
        if ((*(u32*)srcRow & 2) != 0)
            *(u32*)(dstRow + 0x410) = 1;
    }
    count = *(s32*)(work + 0x3ac);
    if (count < 5)
        *(u32*)(work + 0x7640) = 0;
    else
        *(u32*)(work + 0x7640) = count - 4;
    *(u32*)(work + 0x64a0) = *(u32*)(work + 0x3ac);
    *(u32*)(work + 0x6498) = *(u32*)(work + 0x7700);
    *(u32*)(work + 0x649c) = *(u32*)(work + 0x76f8);
    *(u32*)(work + 0x64a4) = *(u32*)(work + 0x3a8);
    bcmPanel00222fa0();
    FUN_0010a4e0(0, 0, 0, 3);
    *(u32*)(work + 0x10) = 4;
}

#pragma opt_loop_invariants off

// W418 negative probe: FUN_00204760 i s16 nd390/876B -> 532/900B (reverted).
// FUN_00204760 NONMATCHING
void FUN_00204760(void)
{
    u8* work;
    u8* row;
    u32 alpha;
    s32 i;
    u32 handle;
    u32 type;
    u16 id;
    u8* slot;
    extern void func_003b2c60(u32, f32);

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    K_ASSERT((~*(u32*)work & 0x10) != 0, 0xca2);
    func_003b0e70(1);
    func_003b0e90(2);
    for (i = 0; i < *(u32*)(work + 0x3ac); i++)
    {
        row = work + 0x2e0 + i * 0x18;
        alpha = *(u32*)(work + 0x7700) ==
                        i + *(u32*)(work + 0x76f8)
                    ? 6
                    : 0;
        type = *(u32*)(row + 4);
        switch (type)
        {
        case 0:
            handle = func_003b0970(*(u32*)((u8*)D_00684F00 + 0x24), 2, alpha, 0, 0);
            func_003b2c60(handle, 0.0f);
            func_003b0e20(handle, -1);
            slot = work + i * 8;
            *(u32*)(slot + 0x370) = handle;
            *(u32*)(slot + 0x374) = 0;
            break;
        case 1:
            id = *(u16*)(row + 0xc);
            handle = func_003b0970(func_00177790((s16)id), 2, alpha, 0, 0);
            func_003b2c60(handle, 0.0f);
            func_003b0e20(handle, -1);
            slot = work + i * 8;
            *(u32*)(slot + 0x370) = handle;
            handle = func_003b0970(
                *(u32*)(DAT_00684efc + (*(u32*)(row + 0x10) - 1) * 4),
                2, alpha, 0, 0);
            func_003b2c60(handle, 0.0f);
            func_003b0e20(handle, -1);
            *(u32*)(slot + 0x374) = handle;
            break;
        case 2:
            if (*(u32*)(work + 0x20) == 2)
                K_ASSERT(0, 0xcd6);
            if (*(u32*)(work + 0x20) == 1)
            {
                handle = func_003b0970(func_00177790(6), 2, alpha, 0, 0);
            }
            else if (*(u32*)(work + 0x20) == 0)
            {
                handle = func_003b0970(func_00177790(4), 2, alpha, 0, 0);
            }
            func_003b2c60(handle, 0.0f);
            func_003b0e20(handle, -1);
            slot = work + i * 8;
            *(u32*)(slot + 0x370) = handle;
            handle = func_003b0970(*(u32*)((u8*)D_00684F00 + 0x20), 2, alpha, 0, 0);
            func_003b2c60(handle, 0.0f);
            func_003b0e20(handle, -1);
            *(u32*)(slot + 0x374) = handle;
            break;
        }
    }
    func_003b0e90(1);
    func_003b0e70(2);
    *(u32*)work |= 0x10;
}

// FUN_00204AF0
void FUN_00204AF0(void)
{
    u8* work;
    u8* row;
    s32 i;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    for (i = 0; i < *(s32*)(work + 0x3a8); i++)
    {
        row = work + i * 0x18 + 0x2e0;
        switch (*(u32*)(row + 4))
        {
        case 1:
            datSetAiTactic(*(s16*)(row + 0xc), *(s16*)(row + 0x10));
            if (*(u32*)(row + 0x10) == 7)
            {
                FUN_002C0A50(
                    FUN_001FF430_y2(*(u32*)(row + 8)),
                    *(u32*)(row + 0x14));
            }
            break;
        default:
            break;
        }
    }
    *(u32*)(work + 4) |= 4;
}

// FUN_00204BE0
void FUN_00204BE0(void)
{
    u8* work;
    u8* row;
    s32 i;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    K_ASSERT((*(u32*)work & 0x10) != 0, 0xd30);
    for (i = 0; i < *(s32*)(work + 0x3ac); i++)
    {
        row = work + i * 8;
        if (*(u32*)(row + 0x370) != 0)
            func_003b0170(*(u32*)(row + 0x370));
        if (*(u32*)(row + 0x374) != 0)
            func_003b0170(*(u32*)(row + 0x374));
    }
    *(u32*)work &= ~0x10u;
}
// FUN_00204CC0 NONMATCHING
void FUN_00204CC0(void)
{
    u8* work;
    u8* rowBase;
    u8* entry;
    u8* row;
    s16 i;
    u32 type;
    u32 handle;
    s32 color;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    rowBase = work + 0x4a90;
    K_ASSERT((*(u32*)work & 0x10) != 0, 0xd47);
    FUN_00205000();
    for (i = 0; i < *(u32*)(work + 0x3ac); i++)
    {
        entry = work + (*(u32*)(work + 0x76f8) + i) * 0x18 + 0x2e0;
        type = *(u32*)(entry + 4);
        if (i == *(u32*)(work + 0x7700))
        {
            K_ASSERT(gBcmWork != NULL, 0x164);
            if ((*work & 1) != 0 || (*work & 0x20000000) != 0)
                color = 0xffff;
            else
                color = (s32)0x8080ffff;
        }
        else
        {
            color = -1;
        }
        if (type == 0)
        {
            handle = *(u32*)(work + 0x370 + i * 8);
            func_003b0d70(handle, 0x730, 0x8c0 + i * 0x90);
            func_003b0e20(handle, color);
        }
        else if (type == 1 || type == 2)
        {
            handle = *(u32*)(work + 0x370 + i * 8);
            func_003b0d70(handle, 0x730, 0x8c0 + i * 0x90);
            func_003b0e20(handle, color);
            handle = *(u32*)(work + 0x374 + i * 8);
            func_003b0d70(handle, 0xf50, 0x8c0 + i * 0x90);
            func_003b0e20(handle, color);
        }
    }
    for (i = 0; i < *(u32*)(work + 0x3ac); i++)
    {
        row = rowBase + i * 0x420;
        entry = work + (*(u32*)(work + 0x76f8) + i) * 0x18 + 0x2e0;
        *(u32*)(row + 0x410) = 0;
        type = *(u32*)(entry + 4);
        if (type == 0)
        {
            *(u32*)row = 1;
            *(u32*)(row + 8) = *(u32*)(entry + 0x90);
        }
        else if (type == 1)
        {
            *(u32*)row = 0;
            *(u32*)(row + 8) = *(u32*)(entry + 0x90);
            *(u32*)(row + 0xc) = *(u32*)(entry + 0x94);
        }
        else if (type == 2)
        {
            *(u32*)row = 2;
            *(u32*)(row + 8) = *(u32*)(entry + 0x90);
            *(u32*)(row + 0xc) = *(u32*)(entry + 0x94);
        }
        if ((*(u32*)entry & 2) != 0)
            *(u32*)(row + 0x410) = 1;
    }
    *(u32*)(work + 0x64a0) = *(u32*)(work + 0x3ac);
    *(u32*)(work + 0x6498) = *(u32*)(work + 0x7700);
    *(u32*)(work + 0x649c) = *(u32*)(work + 0x76f8);
    *(u32*)(work + 0x64a4) = *(u32*)(work + 0x3a8);
    func_002230e0();
}


/* Removing this loses FUN_00204480 (MATCH nd0 -> MISMATCH nd341) - measured W308. */
// W418 negative probe: FUN_00205000 i s16 nd548/956B -> 663/1004B (over 960B); reverted.
// FUN_00205000 NONMATCHING
void FUN_00205000(void)
{
    u8* work;
    u8* row;
    u8* slot;
    s32 i;
    s8 alpha;
    u32 type;
    u32 handle;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    for (i = 0; i < *(s32*)(work + 0x3ac); i++)
    {
        handle = *(u32*)(work + 0x370 + i * 8);
        if (handle != 0)
            func_003b0170(handle);
        *(u32*)(work + 0x370 + i * 8) = 0;
        handle = *(u32*)(work + 0x374 + i * 8);
        if (handle != 0)
            func_003b0170(handle);
        *(u32*)(work + 0x374 + i * 8) = 0;
    }
    func_003b0e70(1);
    func_003b0e90(2);
    for (i = 0; i < *(s32*)(work + 0x3ac); i++)
    {
        row = work + (i + *(u32*)(work + 0x76f8)) * 0x18 + 0x2e0;
        alpha = *(u32*)(work + 0x7700) ==
                        (u32)(i + *(u32*)(work + 0x76f8))
                    ? 6
                    : 0;
        type = *(u32*)(row + 4);
        if (type == 0)
        {
            handle = func_003b0970(*(u32*)((u8*)D_00684F00 + 0x24), 2, alpha, 0, 0);
            func_003b2c60(handle, 0.0f);
            func_003b0e20(handle, -1);
            *(u32*)(work + 0x370 + i * 8) = handle;
        }
        else if (type == 1)
        {
            handle = func_003b0970(
                func_00177790(*(s16*)(row + 0xc)), 2, alpha, 0, 0);
            func_003b2c60(handle, 0.0f);
            func_003b0e20(handle, -1);
            slot = work + i * 8;
            *(u32*)(slot + 0x370) = handle;
            handle = func_003b0970(
                DAT_00684efc[*(u32*)(row + 0x10) - 1],
                2, alpha, 0, 0);
            func_003b2c60(handle, 0.0f);
            func_003b0e20(handle, -1);
            *(u32*)(slot + 0x374) = handle;
        }
        else if (type == 2)
        {
            if (*(u32*)(work + 0x20) == 2)
                K_ASSERT(0, 0xde2);
            if (*(u32*)(work + 0x20) == 1)
            {
                handle = func_003b0970(
                    func_00177790(6), 2, alpha, 0, 0);
            }
            else if (*(u32*)(work + 0x20) == 0)
            {
                handle = func_003b0970(
                    func_00177790(4), 2, alpha, 0, 0);
            }
            func_003b2c60(handle, 0.0f);
            func_003b0e20(handle, -1);
            slot = work + i * 8;
            *(u32*)(slot + 0x370) = handle;
            handle = func_003b0970(*(u32*)((u8*)D_00684F00 + 0x20), 2, alpha, 0, 0);
            func_003b2c60(handle, 0.0f);
            func_003b0e20(handle, -1);
            *(u32*)(slot + 0x374) = handle;
        }
    }
    func_003b0e90(1);
    func_003b0e70(2);
}
// FUN_002053C0
u32 FUN_002053C0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    return *(u32*)gBcmWork & 0x20;
}

// FUN_00205410
void FUN_00205410(void)
{
    u8* work;
    u32 state;
    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    state = *(u32*)(work + 0x10);
    switch (state)
    {
    case 1:
        func_003b0170(*(u32*)(work + 0x88));
        func_0022c0a0();
        break;
    case 2:
        func_003b0170(*(u32*)(work + 0x264));
        func_0022c1d0();
        break;
    default:
        break;
    }
    *(u32*)work &= ~0x20u;
}

// FUN_002054C0
u32 FUN_002054C0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    return *(u32*)(gBcmWork + 0x24);
}

// FUN_00205500
u16 FUN_00205500(void)
{
    u8* work;
    u8* base;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    base = work + 0x2c;
    return *(u16*)(base + *(u32*)(work + 0x7664) * 8);
}

// FUN_00205550
u16 FUN_00205550(void)
{
    u8* work;
    u8* base;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    base = work + 0x9c;
    return *(u16*)(base + *(u32*)(work + 0x7698) * 2);
}

// FUN_002055A0
u16 FUN_002055A0(void)
{
    u8* work;
    u8* base;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    base = work + 0x268;
    return *(u16*)(base + *(u32*)(work + 0x76cc) * 8);
}
// FUN_002055F0
u32 FUN_002055F0(u32 id)
{
    u8* record;

    if ((u16)id >= 0x1d0)
    {
        return 0;
    }
    record = DAT_007ce3f8;
    return !(~record[(u16)id * 0x2c + 1] & 2);
}

// FUN_00205650
u32 FUN_00205650(s32 id)
{
    void* record;
    u32 state;

    record = func_00170e90((s16)id);
    state = *(u32*)((u8*)record + 4);
    if (state != 0 && state != 1)
    {
        return 0;
    }
    return 1;
}

// FUN_002056A0
void FUN_002056A0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    if ((*(u32*)(gBcmWork + 0x77a0) & 1) == 0)
        *(u32*)(gBcmWork + 0xc) |= 0x20;
}

// FUN_00205700
void FUN_00205700(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    if ((*(u32*)(gBcmWork + 0x77a0) & 0x10) == 0)
        *(u32*)(gBcmWork + 0xc) |= 0x10;
}

// FUN_00205760
void FUN_00205760(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    if ((*(u32*)(gBcmWork + 0x77a0) & 0x20) == 0)
        *(u32*)(gBcmWork + 0xc) |= 0x40;
}

// W415 negative probe: simple type==1/type==2 inversion preserved call order but raised nd 863->869; not retained.
// W418 negative probe: narrowing i to s16 regressed nd852/1404B -> nd1032/1476B (over the 1440B window); reverted.
// FUN_002057C0 NONMATCHING
void FUN_002057C0(void)
{
    u8* work;
    u8* entry;
    u32 i;
    u32 id;
    u32 count;
    u32 handle;
    u32 type;
    u32 index;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    K_ASSERT(((~*(u32*)work) & 0x1000) != 0, 0xe89);
    count = 0;
    for (id = 1; id < 0xb; id++)
    {
        switch (id)
        {
        case 1:
        case 7:
        case 9:
            break;
        case 6:
            if (datGetFlag(0x121a) == 0) continue;
            break;
        case 2:
            if (datGetFlag(0x121b) == 0) continue;
            break;
        case 3:
            if (datGetFlag(0x121c) == 0) continue;
            break;
        case 4:
            if (datGetFlag(0x121d) == 0) continue;
            break;
        case 5:
            break;
        case 8:
            if (datGetFlag(0x121e) == 0) continue;
            break;
        case 10:
            entry = work + *(u32*)(work + 0x7700) * 0x18 + 0x2e0;
            type = *(u32*)(entry + 4);
            if (type != 2)
            {
                if (type == 1)
                {
                    if (*(u16*)(entry + 0xc) == 3)
                        break;
                    if (datGetScenarioMode() == 0)
                        continue;
                    if (*(u16*)(entry + 0xc) != 9)
                        continue;
                }
                else if (type == 0)
                {
                    continue;
                }
            }
            else
            {
                K_ASSERT(0, 0xec8);
                break;
            }
            break;
        default:
            continue;
        }
        if (count >= 10)
            break;
        *(u32*)(work + 0x3b0 + count * 4) = id;
        count++;
    }
    *(u32*)(work + 0x404) = count;
    *(u32*)(work + 0x400) = count;
    if (count >= 5)
        *(u32*)(work + 0x400) = 4;
    func_003b0e70(1);
    func_003b0e90(2);
    for (i = 0; i < *(u32*)(work + 0x400); i++)
    {
        id = *(u32*)(work + 0x3b0 + i * 4);
        handle = func_003b0970(*(u32*)(DAT_00684efc + id * 4), 2, 0, 0, 0);
        func_003b0d70(handle, 0x1450, 0x8c0 + i * 0x90);
        func_003b2c60(handle, 0.0f);
        func_003b0e20(handle, -1);
        *(u32*)(work + 0x3d8 + i * 4) = handle;
    }
    *(u32*)(work + 0x77ac) = 0;
    entry = work + *(u32*)(work + 0x7700) * 0x18 + 0x2e0;
    type = *(u32*)(entry + 4);
    if (type == 1)
    {
        handle = func_003b0970(func_001775a0(*(u16*)(entry + 0xc)),
                                2, 6, 0, 0);
        *(u32*)(work + 0x77a8) = handle;
        handle = func_003b0970(*(u32*)(entry + 0x10), 2, 6, 0, 0);
        *(u32*)(work + 0x77ac) = handle;
    }
    else if (type == 0)
    {
        handle = func_003b0970(DAT_007cc414, 2, 6, 0, 0);
        *(u32*)(work + 0x77a8) = handle;
    }
    func_003b0e90(1);
    func_003b0e70(2);
    *(u32*)(work + 0x7728) = 0;
    *(u32*)(work + 0x7734) = 0;
    *(u32*)(work + 0x772c) = 0;
    *(u32*)(work + 0x7730) = *(u32*)(work + 0x400);
    *(u32*)(work + 0x7738) = *(u32*)(work + 0x404);
    func_00208570(work + 0x7728);
    entry = work + *(u32*)(work + 0x7700) * 0x18 + 0x2e0;
    type = *(u32*)(entry + 4);
    if (type == 1)
    {
        index = 0;
    }
    else if (type == 0)
    {
        u32 wanted = *(u32*)(entry + 0x10);
        index = 0;
        for (i = 0; i < *(u32*)(work + 0x404); i++)
        {
            if (*(u32*)(work + 0x3b0 + i * 4) == wanted)
                break;
            index++;
        }
        K_ASSERT(index < *(u32*)(work + 0x404), 0xf21);
    }
    else
    {
        K_ASSERT(type == 2, 0xf2a);
        index = 0;
    }
    *(u32*)(work + 0x7734) = index;
    if (index == *(u32*)(work + 0x404) - 1)
        *(u32*)(work + 0x772c) =
            *(u32*)(work + 0x404) - *(u32*)(work + 0x400);
    else if (*(u32*)(work + 0x400) - 2 < index)
        *(u32*)(work + 0x772c) =
            index - (*(u32*)(work + 0x400) - 2);
    for (i = 0; i < *(u32*)(work + 0x400); i++)
    {
        u8* row = work + 0x64b0 + i * 0x110;
        *(u32*)row = 0;
        *(u32*)(row + 4) = *(u32*)(work + 0x3d8 + i * 4);
    }
    *(u32*)(work + 0x6a00) = *(u32*)(work + 0x404);
    *(u32*)(work + 0x6a04) = *(u32*)(work + 0x7734);
    *(u32*)(work + 0x6a08) = *(u32*)(work + 0x772c);
    *(u32*)(work + 0x6a0c) = *(u32*)(work + 0x400);
    *(u32*)(work + 0x6a10) = *(u32*)(work + 0x77a8);
    *(u32*)(work + 0x6a14) = *(u32*)(work + 0x77ac);
    *(u32*)(work + 0x6d28) = 0;
    func_002254a0();
    FUN_0010a4e0(0, 0, 0, 3);
    printf("start command operation ----------+\n");
    *(u32*)work |= 0x1000;
    *(u32*)(work + 0x1c) = 0;
    *(u32*)(work + 0x10) = 5;
}

// W418 negative probe: narrowing i to s16 regressed nd545/812B -> nd604/868B (over the 848B window); reverted.
// FUN_00205D60 NONMATCHING
void FUN_00205D60(void)
{
    u8* work;
    u8* rowBase;
    u8* entry;
    u8* row;
    u32 i;
    u32 count;
    u32 type;
    u32 handle;
    s32 color;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    rowBase = work + 0x4a90;
    for (i = 0; i < *(u32*)(work + 0x3ac); i++)
    {
        entry = work + (i + *(u32*)(work + 0x76f8)) * 0x18 + 0x2e0;
        if (*(u32*)(work + 0x7700) == i + *(u32*)(work + 0x76f8))
        {
            K_ASSERT(gBcmWork != NULL, 0x164);
            if ((*work & 1) != 0 || (*work & 0x20000000) != 0)
                color = 0xffff;
            else
                color = (s32)0x8080ffff;
        }
        else
        {
            color = -1;
        }
        type = *(u32*)(entry + 4);
        if (type == 0)
        {
            handle = *(u32*)(entry + 0x90);
            func_003b0d70(handle, 0x730, 0x8c0 + i * 0x90);
            func_003b0e20(handle, color);
        }
        else if (type == 1 || type == 2)
        {
            handle = *(u32*)(entry + 0x90);
            func_003b0d70(handle, 0x730, 0x8c0 + i * 0x90);
            func_003b0e20(handle, color);
            handle = *(u32*)(entry + 0x94);
            func_003b0d70(handle, 0xf50, 0x8c0 + i * 0x90);
            func_003b0e20(handle, color);
        }
    }
    count = *(u32*)(work + 0x3ac);
    for (i = 0; i < count; i++)
    {
        row = rowBase + i * 0x420;
        entry = work + (i + *(u32*)(work + 0x76f8)) * 0x18 + 0x2e0;
        *(u32*)(row + 0x410) = 0;
        type = *(u32*)(entry + 4);
        if (type == 0)
        {
            *(u32*)row = 1;
            *(u32*)(row + 8) = *(u32*)(work + 0x370 + i * 8);
        }
        else if (type == 1)
        {
            *(u32*)row = 0;
            *(u32*)(row + 8) = *(u32*)(work + 0x370 + i * 8);
            *(u32*)(row + 0xc) = *(u32*)(work + 0x374 + i * 8);
            if (i + *(u32*)(work + 0x76f8) == 0)
                *(u32*)(rowBase + 0x18e0) =
                    *(u32*)(work + 0x374 + i * 8);
        }
        else if (type == 2)
        {
            *(u32*)row = 2;
            *(u32*)(row + 8) = *(u32*)(work + 0x370 + i * 8);
            *(u32*)(row + 0xc) = *(u32*)(work + 0x374 + i * 8);
        }
        if ((*(u32*)entry & 2) != 0)
            *(u32*)(row + 0x410) = 1;
    }
    *(u32*)(work + 0x64a0) = *(u32*)(work + 0x3ac);
    *(u32*)(work + 0x6498) = *(u32*)(work + 0x7700);
    *(u32*)(work + 0x649c) = *(u32*)(work + 0x76f8);
    *(u32*)(work + 0x64a4) = *(u32*)(work + 0x3a8);
    func_002230e0();
    func_002255f0();
    FUN_0010a4e0(0, 0, 0, 4);
    *(u32*)(work + 0x1c) = 2;
}

// FUN_002060B0
void FUN_002060B0(void)
{
    u8* work;
    s32 i;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    FUN_00206170();
    for (i = 0; i < *(s32*)(work + 0x400); i++)
    {
        *(u32*)(work + 0x64b0 + i * 0x110) = 0;
        *(u32*)(work + 0x64b4 + i * 0x110) = *(u32*)(work + 0x3d8 + i * 4);
    }
    *(u32*)(work + 0x6a00) = *(u32*)(work + 0x404);
    *(u32*)(work + 0x6a04) = *(u32*)(work + 0x7734);
    *(u32*)(work + 0x6a08) = *(u32*)(work + 0x772c);
    *(u32*)(work + 0x6a0c) = *(u32*)(work + 0x400);
    *(u32*)(work + 0x6d28) = 0;
    func_00225670();
}

// FUN_00206170
void FUN_00206170(void)
{
    u8* work;
    s32 destroyIndex;
    s32 rowIndex;
    s32 targetIndex;
    u32 handle;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    for (destroyIndex = 0; destroyIndex < *(s32*)(work + 0x400);
         destroyIndex++)
    {
        func_003b0170(*(u32*)(work + 0x3d8 + destroyIndex * 4));
    }
    if (*(u32*)work & 0x800000)
    {
        func_00208360();
    }
    handle = bpRoot_003a5540_typed(
        100, 100, -1, 0.0f, 2, 6, *(void**)(work + 0x7794),
        *(u32*)((u8*)(uintptr_t)(*(s32*)(work + 0x7734) * 4) +
                (uintptr_t)work + 0x3b0) - 1);
    func_002082c0(handle);
    func_003b0e70(1);
    func_003b0e90(2);
    for (rowIndex = 0; rowIndex < *(s32*)(work + 0x400); rowIndex++)
    {
        u32* resourceEntry;
        targetIndex = rowIndex + *(s32*)(work + 0x772c);
        resourceEntry = &D_00684F00[
            *(u32*)(work + 0x3b0 + targetIndex * 4)];
        handle = func_003b0970(
            resourceEntry[-1], 2,
            (s8)(targetIndex == *(s32*)(work + 0x7734) ? 6 : 0),
            0, 0);
        *(u32*)(work + 0x3d8 + rowIndex * 4) = handle;
    }
    func_003b0e90(1);
    func_003b0e70(2);
}

// FUN_00206310
void FUN_00206310(void)
{
    u8* work;
    s32 i;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    K_ASSERT((*(u32*)work & 0x1000) != 0, 0x1000);
    func_003b0170(*(u32*)(work + 0x77a8));
    if (*(u32*)(work + 0x77ac) != 0)
        func_003b0170(*(u32*)(work + 0x77ac));
    for (i = 0; i < *(s32*)(work + 0x400); i++)
    {
        func_003b0170(*(u32*)(work + 0x3d8 + i * 4));
    }
    *(u32*)work &= ~0x1000u;
}
#pragma opt_loop_invariants on
// FUN_002063F0
void FUN_002063F0(void)
{
    u8* work;
    u8* dispatchRow;
    u8* rowBase;
    u8* row;
    s32 i;
    u32 id;
    u32 type;
    u32 idOffset;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    id = ((u32*)(work + 0x3b0))[*(u32*)(work + 0x7734)];
    switch (id)
    {
    case 7:
        FUN_005225a8_y2((const char*)&gp0xffff972c);
        FUN_0021B670(0);
        FUN_002085E0();
        *(u32*)(work + 0x1c) = 1;
        break;
    default:
        dispatchRow = work + *(u32*)(work + 0x7700) * 0x18 + 0x2e0;
        type = *(u32*)(dispatchRow + 4);
        switch (type)
        {
        case 0:
            for (i = 0; i < *(s32*)(work + 0x3a8); i++)
            {
                rowBase = work + i * 0x18;
                row = rowBase + 0x2e0;
                if ((*(u32*)(rowBase + 0x2e0) & 2) == 0)
                {
                    switch (*(u32*)(row + 4))
                    {
                    case 1:
                        idOffset = *(u32*)(work + 0x7734) * 4;
                        id = *(u32*)(work + idOffset + 0x3b0);
                        *(u32*)(row + 0x10) = id;
                        *(u32*)row |= 1;
                        break;
                    }
                }
            }
            FUN_00208790();
            break;
        case 1:
            *(u32*)(dispatchRow + 0x10) = id;
            *(u32*)dispatchRow |= 1;
            FUN_00208860(*(u16*)(dispatchRow + 0xc));
            break;
        case 2:
            K_ASSERT(0, 0x104e);
            break;
        default:
            break;
        }
        FUN_00205D60();
        break;
    }
}

#pragma opt_loop_invariants off

/* Removing this loses FUN_002065A0 (MATCH nd0 -> MISMATCH nd159) - measured W308. */
#pragma opt_loop_invariants on
// FUN_002065A0
void FUN_002065A0(void)
{
    u8* work;
    u8* dispatchRow;
    u8* rowBase;
    u8* row;
    s32 i;
    u32 type;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    K_ASSERT(((u32*)(work + 0x3b0))[*(u32*)(work + 0x7734)] == 7,
             0x105f);
    dispatchRow = work + *(u32*)(work + 0x7700) * 0x18 + 0x2e0;
    type = *(u32*)(dispatchRow + 4);
    switch (type)
    {
    case 0:
        for (i = 0; i < *(s32*)(work + 0x3a8); i++)
        {
            rowBase = work + i * 0x18;
            row = rowBase + 0x2e0;
            if ((*(u32*)(rowBase + 0x2e0) & 2) == 0)
            {
                switch (*(u32*)(row + 4))
                {
                case 1:
                    *(u32*)(row + 0x10) =
                        *(u32*)(work + 0x3b0 +
                                *(u32*)(work + 0x7734) * 4);
                    *(u32*)(row + 0x14) = *(u32*)(work + 0x428);
                    *(u32*)row |= 1;
                    break;
                }
            }
        }
        FUN_00208790();
        break;
    case 1:
        *(u32*)(dispatchRow + 0x10) =
            ((u32*)(work + 0x3b0))[*(u32*)(work + 0x7734)];
        *(u32*)(dispatchRow + 0x14) = *(u32*)(work + 0x428);
        *(u32*)dispatchRow |= 1;
        FUN_00208860(*(u16*)(dispatchRow + 0xc));
        break;
    case 2:
        K_ASSERT(0, 0x108b);
        break;
    default:
        break;
    }
    FUN_00205D60();
}
#pragma opt_loop_invariants reset

// W418 negative probe: FUN_00206740 i s16 nd1200/1668B -> 1267/1748B (reverted).
// W419 negative probes: FUN_00206740 reversed chain nd1208/1660B, window1792B, rate72.77%; u32 mode chain nd1117/1656B, window1792B, rate67.45%; declaration/scoped row-pointer variants unchanged at nd1067/1652B, window1792B, rate64.59%; reverted.
// FUN_00206740 NONMATCHING
void FUN_00206740(void)
{
    DatPersonaWork* persona;
    u16* skills;
    u8* work;
    u32* row;
    s32 i;
    s32 count;
    s32 mode;
    u32 type;
    s8 alpha;
    u32 handle;
    s32 value;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    K_ASSERT((~*(u32*)work & 0x2000) != 0, 0x109f);
    K_ASSERT(*(u32*)(work + 0x20) != 2, 0x10a0);
    count = 0;
    for (mode = 0; mode < 3; mode++)
    {
        row = (u32*)(work + 0x408 + count * 4);
        switch (mode)
        {
        case 0:
            *row = 0;
            count++;
            break;
        case 1:
            *row = 1;
            count++;
            break;
        case 2:
            if (*(u32*)(work + 0x20) == 1)
            {
                persona = datPersonaGetByPcId(6);
                skills = datPersonaGetSkills(persona);
                value = datPersonaCountValidSkills(persona);
                for (i = 0; i < value; i++)
                {
                    if (skills[i] == 0x145)
                        break;
                }
                if (i != value)
                {
                    *row = 2;
                    count++;
                }
            }
            break;
        }
    }
    *(u32*)(work + 0x420) = count;
    *(u32*)(work + 0x424) = count;
    if (count >= 5)
        *(u32*)(work + 0x424) = 4;
    *(u32*)(work + 0x775c) = 0;
    *(u32*)(work + 0x776c) = count;
    *(u32*)(work + 0x7764) = *(u32*)(work + 0x424);
    func_00208570(work + 0x775c);
    if (datGetFlag(0x186) != 0)
    {
        value = FUN_0016F380(0x34);
        if (value != 0)
        {
            for (i = 0; i < *(s32*)(work + 0x420); i++)
            {
                if (*(u32*)(work + 0x408 + i * 4) == value)
                    break;
            }
            if (i == *(s32*)(work + 0x420))
            {
                *(u32*)(work + 0x7768) = 0;
                *(u32*)(work + 0x7760) = 0;
            }
            else
            {
                *(u32*)(work + 0x7768) = i;
                *(u32*)(work + 0x7760) = 0;
            }
        }
        else
        {
            *(u32*)(work + 0x7768) = 0;
            *(u32*)(work + 0x7760) = 0;
        }
    }
    else
    {
        *(u32*)(work + 0x7768) = 0;
        *(u32*)(work + 0x7760) = 0;
    }
    func_003b0e70(1);
    func_003b0e90(2);
    for (i = 0; i < *(u32*)(work + 0x424); i++)
    {
        u32 selected = *(u32*)(work + 0x7768) -
                       *(u32*)(work + 0x7760);
        alpha = i == selected ? 6 : 0;
        type = *(u32*)(work + 0x408 +
                       (i + *(u32*)(work + 0x7760)) * 4);
        if (type == 0)
        {
            if (*(u32*)(work + 0x20) == 1)
                handle = func_003b0970(func_0030bb40(0x146),
                                        2, alpha, 0, 0);
            else if (*(u32*)(work + 0x20) == 0)
                handle = func_003b0970(func_0030bb40(0x144),
                                        2, alpha, 0, 0);
        }
        else if (type == 1)
        {
            handle = func_003b0970(D_007CC418,
                                    2, alpha, 0, 0);
        }
        else
        {
            if (*(u32*)(work + 0x20) != 1)
                K_ASSERT(0, 0x1124);
            handle = func_003b0970(func_0030bb40(0x145),
                                    2, alpha, 0, 0);
        }
        *(u32*)(work + 0x414 + i * 4) = handle;
    }
    if (*(u32*)(work + 0x20) == 1)
    {
        handle = func_003b0970(func_001775a0(6), 2, 6, 0, 0);
    }
    else if (*(u32*)(work + 0x20) == 0)
    {
        handle = func_003b0970(func_001775a0(4), 2, 6, 0, 0);
    }
    else
    {
        K_ASSERT(0, 0x113d);
    }
    *(u32*)(work + 0x77a8) = handle;
    func_003b0e90(1);
    func_003b0e70(2);
    *(u32*)work |= 0x2000;
    *(u32*)(work + 0x6a00) = *(u32*)(work + 0x420);
    *(u32*)(work + 0x6a0c) = *(u32*)(work + 0x424);
    for (i = 0; i < *(u32*)(work + 0x6a0c); i++)
    {
        u8* row = work + 0x64b0 + i * 0x110;
        type = *(u32*)(work + 0x408 +
                       (i + *(u32*)(work + 0x7760)) * 4);
        if (type == 0)
            *(u32*)row = (*(u32*)work & 0x4000) != 0 ? 2 : 0;
        else if (type == 1)
        {
            if (*(u32*)work & 0x200000)
                *(u32*)row = 1;
            else if (*(u32*)work & 0x10000)
                *(u32*)row = 2;
            else if (*(u32*)work & 0x1000)
                *(u32*)row = 2;
            else
                *(u32*)row = 0;
        }
        else
        {
            if (*(u32*)work & 0x200000)
                *(u32*)row = 1;
            else if (*(u32*)work & 0x8000)
                *(u32*)row = 2;
            else
                *(u32*)row = 0;
        }
        *(u32*)(row + 4) =
            *(u32*)(work + 0x414 +
                    (i + *(u32*)(work + 0x7760)) * 4);
    }
    *(u32*)(work + 0x6a04) = *(u32*)(work + 0x7768);
    *(u32*)(work + 0x6a08) = *(u32*)(work + 0x7760);
    *(u32*)(work + 0x6a10) = *(u32*)(work + 0x77a8);
    *(u32*)(work + 0x6a14) = 0;
    func_002254a0();
    FUN_0010a4e0(0, 0, 0, 3);
    *(u32*)(work + 0x18) = 0;
    *(u32*)(work + 0x10) = 6;
}

// FUN_00206E40
void FUN_00206E40(void)
{
    u8* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    func_002255f0();
    FUN_0010a4e0(0, 0, 0, 4);
    *(u32*)(work + 0x18) = 9;
}

// FUN_00206EB0
void FUN_00206EB0(void)
{
    s32 i;
    u8* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    K_ASSERT((*(u32*)work & 0x2000) != 0, 0x1192);
    func_003b0170(*(u32*)(work + 0x77a8));
    for (i = 0; i < *(s32*)(work + 0x424); i++)
    {
        func_003b0170(*(u32*)(work + 0x414 + i * 4));
    }
    *(u32*)work &= ~0x2000u;
}

/* Removing this loses FUN_002063F0 (MATCH nd0 -> MISMATCH nd128) - measured W308. */
// FUN_00206F70
void FUN_00206F70(void)
{
    u8* p;
    s32 i;

    K_ASSERT(gBcmWork != NULL, 0x164);
    p = gBcmWork;
    FUN_00207010();
    for (i = 0; i < *(s32*)(p + 0x6a0c); i++)
    {
        *(u32*)(p + 0x64b4 + i * 0x110) =
            *(u32*)(p + 0x414 + i * 4);
    }
    *(u32*)(p + 0x6a04) = *(u32*)(p + 0x7768);
    *(u32*)(p + 0x6a08) = 0;
    func_00225670();
}
// FUN_00207010
void FUN_00207010(void)
{
    s32 alpha;
    u8* work;
    u32 handle;
    s32 rowIndex;
    s32 targetIndex;
    u32* typeEntry;
    u32 type;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    for (rowIndex = 0; rowIndex < *(s32*)(work + 0x424); rowIndex++)
    {
        func_003b0170(*(u32*)(work + 0x414 + rowIndex * 4));
    }
    if (*(u32*)work & 0x800000)
    {
        func_00208360();
    }

    type = *(u32*)(work + 0x408 +
                   (*(s32*)(work + 0x7768) +
                    *(s32*)(work + 0x7760)) * 4);
    switch (type)
    {
    case 0:
        switch (*(u32*)(work + 0x20))
        {
        case 0:
            alpha = 0;
            break;
        case 1:
            alpha = 1;
            break;
        }
        break;
    case 1:
        alpha = 2;
        break;
    case 2:
        alpha = 3;
        break;
    }

    handle = bpRoot_003a5540_typed(100, 100, -1, 0.0f, 2, 6,
                                    *(void**)(work + 0x7798), alpha);
    func_002082c0(handle);
    func_003b0e70(1);
    func_003b0e90(2);
    for (rowIndex = 0; rowIndex < *(s32*)(work + 0x424); rowIndex++)
    {
        targetIndex = rowIndex + *(s32*)(work + 0x7760);
        typeEntry = (u32*)(work + 0x408 + targetIndex * 4);
        alpha = rowIndex == *(s32*)(work + 0x7768) -
                              *(s32*)(work + 0x7760) ? 6 : 0;
        switch (*typeEntry)
        {
        case 0:
            switch (*(u32*)(work + 0x20))
            {
            case 0:
                handle = func_003b0970(func_0030bb40(0x144),
                                        2, (s8)alpha, 0, 0);
                break;
            case 1:
                handle = func_003b0970(func_0030bb40(0x146),
                                        2, (s8)alpha, 0, 0);
                break;
            }
            break;
        case 1:
            handle = func_003b0970(D_007CC418,
                                    2, (s8)alpha, 0, 0);
            break;
        case 2:
            K_ASSERT(*(u32*)(work + 0x20) == 1, 0x1209);
            handle = func_003b0970(func_0030bb40(0x145),
                                    2, (s8)alpha, 0, 0);
            break;
        }
        *(u32*)(work + 0x414 + rowIndex * 4) = handle;
    }
    func_003b0e90(1);
    func_003b0e70(2);
}
// FUN_00207340 NONMATCHING
void FUN_00207340(void)
{
    u8* work;
    u8* item;
    u32 type;
    u32 flags;
    u32 effect;
    u32 state;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    item = work + 0x408 + *(u32*)(work + 0x7768) * 4;
    type = *(u32*)item;
    if (type == 0)
    {
        flags = *(u32*)work;
        if (flags & 0x4000)
        {
            func_002dba80(0);
            state = bpRoot_0021c720_ret();
            bpRoot_003c72d0_arg(state);
            effect = bpMisc001ff740_y2();
            if (effect == 0)
            {
                func_003c7430(0);
                func_003c74e0(1);
            }
            else if (effect == 1)
            {
                if (func_002d5550() == 0x1a1)
                {
                    func_003c7430(6);
                    func_003c74e0(7);
                }
                else
                {
                    func_003c7430(3);
                    func_003c74e0(4);
                }
            }
            else
            {
                K_ASSERT(0, 0x1246);
            }
            *(u32*)(work + 0x18) = 3;
        }
        else
        {
            func_0021b670();
            *(u32*)(work + 0x18) = 1;
        }
    }
    else if (type == 1)
    {
        flags = *(u32*)work;
        if (flags & 0x200000)
        {
            state = *(u32*)(work + 0x77b0);
            if (state == 1)
            {
                func_002dba80(0);
                func_002db9f0(0x20, 0xbc);
            }
            else if (state == 2)
            {
                func_002dba80(0);
                func_002db9f0(0x20, 0xbd);
            }
            else if (state == 3)
            {
                func_002dba80(0);
                func_002db9f0(0x20, 0xbe);
            }
            else
            {
                K_ASSERT(0, 0x126e);
            }
            K_ASSERT(gBcmWork != NULL, 0x164);
            work = gBcmWork;
            func_002255f0();
            FUN_0010a4e0(0, 0, 0, 4);
            *(u32*)(work + 0x18) = 9;
        }
        else if (flags & 0x10000)
        {
            func_002dba80(0);
            state = bpRoot_0021c720_ret();
            bpRoot_003c72d0_arg(state);
            effect = bpMisc001ff740_y2();
            if (effect == 0)
            {
                func_003c7430(9);
                func_003c74e0(10);
            }
            else if (effect == 1)
            {
                func_003c7430(0xc);
                func_003c74e0(0xd);
            }
            else
            {
                K_ASSERT(0, 0x1288);
            }
            *(u32*)(work + 0x18) = 5;
        }
        else
        {
            func_002dba80(0);
            func_002db9f0(0x20, 0xb8);
            *(u32*)work |= 0x10000;
            K_ASSERT(gBcmWork != NULL, 0x164);
            work = gBcmWork;
            func_002255f0();
            FUN_0010a4e0(0, 0, 0, 4);
            *(u32*)(work + 0x18) = 9;
        }
    }
    else
    {
        flags = *(u32*)work;
        if (flags & 0x100000)
        {
            func_002dba80(0);
            func_002db9f0(0x20, 0xb0);
            K_ASSERT(gBcmWork != NULL, 0x164);
            work = gBcmWork;
            func_002255f0();
            FUN_0010a4e0(0, 0, 0, 4);
            *(u32*)(work + 0x18) = 9;
        }
        else if (flags & 0x8000)
        {
            func_002dba80(0);
            state = bpRoot_0021c720_ret();
            bpRoot_003c72d0_arg(state);
            effect = bpMisc001ff740_y2();
            if (effect == 1)
            {
                func_003c7430(0xf);
                func_003c74e0(0x10);
            }
            else
            {
                K_ASSERT(0, 0x12b3);
            }
            *(u32*)(work + 0x18) = 7;
        }
        else
        {
            func_002dba80(0);
            func_002db9f0(0x20, 0xaf);
            *(u32*)work |= 0x8000;
            K_ASSERT(gBcmWork != NULL, 0x164);
            work = gBcmWork;
            func_002255f0();
            FUN_0010a4e0(0, 0, 0, 4);
            *(u32*)(work + 0x18) = 9;
        }
    }
    FUN_0016F3E0(0x34, type);
}

// FUN_002078A0
void FUN_002078A0(void)
{
    u16* values;
    u8* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    values = (u16*)func_0030c0c0();
    K_ASSERT(values != NULL, 0x12d0);
    func_00249420(values[0], values[1], values[2]);
    *(u32*)(work + 0x10) = 9;
}

// FUN_00207930
u32 bcmIsItemUsable(u16 param_1)
{
    return FUN_0017d2e0_y2(param_1) != 0xc;
}

// FUN_00207960
u32 FUN_00207960(u32 id)
{
    u32 status;
    u32 valid;

    status = FUN_0017d2e0((u16)id);
    valid = (status ^ 0xc) != 0;
    K_ASSERT(valid, 0x12f2);
    return FUN_0017d2e0((u16)id);
}



// FUN_002079C0
void FUN_002079C0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    *(u32*)(gBcmWork + 0x77a0) |= 1;
}

// FUN_00207a10
void bcm00207a10(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    *(u32*)(gBcmWork + 0x77a0) |= 2;
}

// FUN_00207A60
void FUN_00207A60(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    *(u32*)(gBcmWork + 0x77a0) |= 4;
}

// FUN_00207AB0
void FUN_00207AB0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    *(u32*)(gBcmWork + 0x77a0) |= 8;
}

// FUN_00207B00
void FUN_00207B00(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    *(u32*)(gBcmWork + 0x77a0) |= 0x10;
}

// FUN_00207B50
void FUN_00207B50(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    *(u32*)(gBcmWork + 0x77a0) |= 0x20;
}

// FUN_00207BA0
void FUN_00207BA0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    *(u32*)(gBcmWork + 0x77a0) |= 0x40;
}

// FUN_00207bf0
void bcm00207bf0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    *(u32*)(gBcmWork + 0x77a0) &= ~1;
}










 







/* Shared command work is owned by bcm_main.c. */




// FUN_00207c40
void func_00207c40(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0x77a0) &= ~2u;
}

// FUN_00207c90
void func_00207c90(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0x77a0) &= ~4u;
}

// FUN_00207ce0
void func_00207ce0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0x77a0) &= ~8u;
}

// FUN_00207d30
void func_00207d30(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0x77a0) &= ~0x10u;
}

// FUN_00207d80
void func_00207d80(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0x77a0) &= ~0x20u;
}

// FUN_00207dd0
void func_00207dd0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0x77a0) &= ~0x40u;
}

// FUN_00207e20
void bcmStartTacticsTutorial(void)
{
    u8* work;
    s32 mode;
    u32 state;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    state = func_002d5550();
    switch (state) {
    case 0x1d2:
        mode = 0;
        break;
    case 0x1d3:
        mode = 1;
        break;
    case 0x1d4:
        mode = 2;
        break;
    case 0x1d5:
        mode = 3;
        break;
    default:
        K_ASSERT(0, 0x1365);
        break;
    }
    func_002518b0(mode);
    bppMain0020fc40();
    *(u32*)(work + 0x10) = 0xa;
}

// FUN_00207f10
void bcmStartBasicTutorial(void)
{
    u8* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    func_00251e10();
    bppMain0020fc40();
    *(u32*)(work + 0x10) = 0xb;
}

// FUN_00207f70
u32 func_00207f70(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    return BCM_WORD(0) & 0x02000000;
}

// FUN_00207fc0
u32 func_00207fc0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    return BCM_WORD(0) & 0x04000000;
}

// FUN_00208010
u32 bcmIsCurrentUnitTutorialPending(void)
{
    void* unit;

    unit = func_0030c0c0();
    if (unit != NULL) {
        return func_00249650(*(u16*)unit);
    }
    return 0;
}

// FUN_00208050
u32 bcmIsTacticsTutorialPending(void)
{
    u32 mode;

    mode = func_002d5550();
    if (mode == 0x1d5) {
        goto mode_1d5;
    }
    if (mode == 0x1d4) {
        goto mode_1d4;
    }
    if (mode == 0x1d3) {
        goto mode_1d3;
    }
    switch (mode) {
    case 0x1d2:
        goto mode_1d2;
    default:
        goto done;
    }
mode_1d2:
    if (datGetFlag_y2(0x1307) == 0) {
        return 1;
    }
    goto done;
mode_1d3:
    if (datGetFlag_y2(0x1308) == 0) {
        return 1;
    }
    goto done;
mode_1d4:
    if (datGetFlag_y2(0x1309) == 0) {
        return 1;
    }
    goto done;
mode_1d5:
    if (datGetFlag_y2(0x130a) == 0) {
        return 1;
    }
done:
    return 0;
}

// FUN_00208130
u32 bcmCanStartBasicTutorial(void)
{
    u64 status;

    if (datGetScenarioMode() == 0) {
        if (bpMisc001ff7f0(3) == 0) {
            return 0;
        }
    } else {
        if (bpMisc001ff7f0(9) == 0) {
            return 0;
        }
    }
    if (datGetScenarioMode() == 0 && datGetFlag_y2(0xdf) != 0) {
        return 0;
    }
    if (datGetFlag_y2(0x1306) != 0) {
        return 0;
    }
    if ((gBtl->flags & 0x200000) != 0) {
        return 0;
    }
    if (datGetScenarioMode() != 0) {
        status = (u64)(datGetBadStatusNoDown(9) & 0xfffff);
    } else {
        status = (u64)(datGetBadStatusNoDown(3) & 0xfffff);
    }
    if (status == 1 || status == 2 || status == 4 || status == 8 ||
        status == 0x10 || status == 0x20 || status == 0x40 ||
        status == 0x80000 || status == 0x100000) {
        return 0;
    }
    return 1;
}

// FUN_002082c0
void bcmStoreOwnedResource(u32 value)
{
    u8* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    K_ASSERT((~*(u32*)work & 0x00800000) != 0, 0x13e6);
    *(u32*)(work + 0x779c) = value;
    *(u32*)(work + 0x6d20) = value;
    *(u32*)work |= 0x00800000;
}

// FUN_00208360
void bcmDestroyOwnedResource(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    K_ASSERT((BCM_WORD(0) & 0x00800000) != 0, 0x13f1);
    bcmDestroyOwnedResourceImpl();
}

// FUN_002083d0
void bcmDestroyOwnedResourceImpl(void)
{
    u8* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    K_ASSERT((*(u32*)work & 0x00800000) != 0, 0x13f9);
    func_003b0170_y2(*(u32*)(work + 0x779c));
    *(u32*)work &= ~0x00800000u;
}

// FUN_00208460
void bcmFinishPanelTransition(void)
{
    u8* work;
    s32 state;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    state = *(u32*)(work + 0x10);
    switch (state) {
    case 1:
        *(u32*)(work + 4) |= 1;
        bcmPanel00222ed0();
        break;
    case 2:
        *(u32*)(work + 4) |= 2;
        bcmPanel00222ed0();
        break;
    case 3:
        bcmPanel00222ed0();
        break;
    case 4:
        bcmPanel00222ed0();
        break;
    default:
        K_ASSERT(0, 0x1414);
        break;
    }
    FUN_0010a4e0(0, 0, 0, 4);
    *(u32*)(work + 0x10) = 0;
}

// FUN_00208570
void bcmInitCommandPanelEntries(u32* panel)
{
    s32 i;
    u8* entry;

    panel[0] |= 4;
    for (i = 0; i < 8; i++) {
        entry = (u8*)&panel[i];
        entry[0x14] = 0;
        entry[0x15] = 0;
        entry[0x16] = 0;
    }
    ((u8*)panel)[0x17] = 0;
    ((u8*)panel)[0x1b] = 0;
    ((u8*)panel)[0x1f] = 5;
    ((u8*)panel)[0x23] = 5;
    ((u8*)panel)[0x2b] = 0;
    ((u8*)panel)[0x27] = 0;
    ((u8*)panel)[0x33] = 5;
    ((u8*)panel)[0x2f] = 5;
}

// FUN_002085e0
void func_002085e0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0) |= 0x08000000;
}

// FUN_00208630
void func_00208630(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0) &= ~0x08000000u;
}

// FUN_00208680
void func_00208680(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0) |= 0x10000000;
}

// FUN_002086d0
void func_002086d0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    BCM_WORD(0) &= ~0x10000000u;
}

// FUN_00208720
u32 bcmIsCommandInputReady(void)
{
    u8* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    if (*(u32*)(work + 0x10) != 0) {
        goto done;
    }
    if ((~*(u32*)work & 0x20) == 0) {
        goto done;
    }
    return 1;
done:
    return 0;
}

/* Removing the schedule pragma below loses FUN_00208790 (MATCH nd0 -> MISMATCH nd117) - measured W161. */
// FUN_00208790
#pragma push
#pragma optimization_level 3
#pragma schedule off
void bcmPlayRandomPartyVoice(void)
{
    u32 ids[4];
    s32 count;
    s32 i;
    s32 total;
    u8* work;
    BcmCommandEntry* entry;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    count = 0;
    i = 0;
    total = *(s32*)(work + 0x3a8);
    while (i < total) {
        entry = (BcmCommandEntry*)(work + i * 0x18 + 0x2e0);
        switch (entry->type) {
        case 1:
            ids[count++] = entry->id;
            break;
        }
        i++;
    }
    func_00208860((u16)ids[RpRandom() % count]);
}
#pragma pop

// FUN_00208860
void func_00208860(u32 unitId)
{
    u32 status;
    u32 id;

    status = datGetBadStatusNoDown((s16)unitId);
    if ((status & 0x80371) != 0) {
        goto done;
    }
    id = unitId & 0xffff;
    switch (id) {
    case 0:
    case 1:
        goto done;
    case 2:
        if (func_002ddc10(unitId) != 0) {
            goto case2_true;
        }
        func_002ddba0(0xa2);
        goto done;
case2_true:
        func_002ddba0(0xa3);
        goto done;
    case 3:
        if (func_002ddc10(unitId) != 0) {
            goto case3_true;
        }
        func_002ddba0(0xf3);
        goto done;
case3_true:
        func_002ddba0(0xf4);
        goto done;
    case 4:
        if (func_002ddc10(unitId) != 0) {
            goto case4_true;
        }
        func_002ddba0(0x158);
        goto done;
case4_true:
        func_002ddba0(0x159);
        goto done;
    case 5:
        if (func_002ddc10(unitId) != 0) {
            goto case5_true;
        }
        func_002ddba0(0x1a1);
        goto done;
case5_true:
        func_002ddba0(0x1a2);
        goto done;
    case 6:
        K_ASSERT(0, 0x149a);
        goto done;
    case 7:
        if (func_002ddc10(unitId) != 0) {
            goto case7_true;
        }
        func_002ddba0(0x1ea);
        goto done;
case7_true:
        func_002ddba0(0x1eb);
        goto done;
    case 8:
        if (func_002ddc10(unitId) != 0) {
            goto case8_true;
        }
        func_002ddba0(0x233);
        goto done;
case8_true:
        func_002ddba0(0x234);
        goto done;
    case 9:
        if (datGetScenarioMode() != 0) {
            goto case9_true;
        }
        func_002ddba0(0x279);
        goto done;
case9_true:
        func_002ddba0(0x46b);
        goto done;
    case 10:
        if (func_002ddc10(unitId) != 0) {
            goto case10_true;
        }
        func_002ddba0(0x2bd);
        goto done;
case10_true:
        func_002ddba0(0x2be);
        goto done;
    default:
        goto done;
    }
done:
    return;
}
