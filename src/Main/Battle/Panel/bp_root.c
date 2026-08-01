#include "Main/Battle/Panel/bp_root.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"
#include "Main/Battle/Cmd/bcm_main.h"
#include "Main/Battle/Cmd/bpp_main.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"

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
void FUN_00248500();
void FUN_00245e00();
void FUN_00248580();
void FUN_0021bb00();
void FUN_0020fd30();
void FUN_00210d60();
void FUN_00201c30();
void bppMain0020fc40();
void FUN_002085e0();
void FUN_00208b30();
void FUN_0021b830();
void basClearAnalyzePending(void); // bas_main.c
void FUN_0021b8b0();
void FUN_00201e00();
void bppMain0020fc90();
void FUN_00208630();
void FUN_002094f0();
void FUN_0024cf00();
void bppMain0020f3b0();
void bppMain0020f570();
void FUN_00244120();
void FUN_00244a40();
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
void FUN_00251f40();
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
u32 bpMisc001ff740(void);
void bcmPanel00222a60(void);
void bcmPanel00222b90(void);
void bcmPanel00222930(void);
void bcmPanel00222d60(void);
void bcmPanel0022bf60(void);
void FUN_00222d60(void);
void func_0021f0c0(void*);
#pragma alias bpRoot_0021c720_ret func_0021c720
u32 bpRoot_0021c720_ret(void);
#pragma alias bpRoot_003c72d0_arg func_003c72d0
u32 bpRoot_003c72d0_arg(u32);
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
u32 bpe00249600(void);
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
u32 func_00208010(void);
u32 func_00208050(void);
u32 func_00208130(void);
void func_0025be60(u32, u32, u32);
void bpRush0025d7b0(void);
void func_0020fd80(void);
void func_0020fdd0(void);
void func_0027b9f0(void);
void func_0027ba90(void);
void func_0027bae0(void);
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


typedef struct PanelSkillRow
{
    u32 flags;
    u32 handle;
    u32 type;
    u32 icon;
} PanelSkillRow;


extern u8* DAT_007ce3f8;
extern u8* DAT_007ce3ec;
extern u32 D_00684F00[];
extern u8 gp0xffff972c;
extern u8* gp0xffffb708;

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
u32 FUN_002055F0(u32 id);
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
void FUN_00207B50(void);
void FUN_00207BA0(void);
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

void FUN_002082C0(void* context);
void FUN_00208360(void);
void FUN_00208570(void* descriptor);
void FUN_002085E0(void);
void FUN_00208790(void);
void FUN_00208860(u16 id);
void FUN_002094F0(void);
void FUN_0020FC40(void);
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
u32 FUN_0016F190(u32);
void FUN_005225a8(const char*, ...);
void FUN_0021B670(u32);
void FUN_0021C720(void);
u32 FUN_0022D5550(void);
u32 FUN_002D5550(void);
u32 FUN_001FF430(u32);
void FUN_002C0A50(u32, u32);
void datSetAiTactic(s16, s16);
u32 datGetScenarioMode(void);
void datSetScenarioMode(u32);
u32 datGetFlag(s32);
int printf(const char*, ...);
void* func_0021f410(void);
void func_00221b60(void);
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
void func_002083d0(void);
void func_00208570(void*);
void func_002085e0(void);
void func_00208790(void);
void func_00208860(u16);
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
void* func_0030c0c0(void);
u32 func_003086f0(u32, u16);
u32 func_003083f0(u32, u16);
u32 func_0030bb40(u16);
u32 func_0030bc20(u16);
void* func_00170e90(s16);
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
u32 func_003c72d0(void);
u32 func_003c7430(u32);
u32 func_003c74e0(u32);
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
void FUN_001ff890(void);
void FUN_001FFC60(void);
void FUN_001FFF40(void);

static u8* panelMiscWork(void)
{
    return *(u8**)0x007CE3EC;
}
static KwlnTask* sBtlPanelTask; // 007ce2e4

void* FUN_001fd890(KwlnTask*);
void* FUN_001fdac0(KwlnTask*);
void FUN_00208ad0(void*);
void FUN_00201730(void*);
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
// FUN_001fd630
KwlnTask* bpRootCreateTasks(KwlnTask* parent)
{
    KwlnTask* task;
    u32* workData;
    KwlnTask* drawTask;

    workData = (u32*)RwMalloc(0x35030, 0x40000);
    workData[0] = 0;
    workData[1] = 0;
    task = kwlnTaskCreateWithAutoPriority(parent, 10, "battle panel",
                                          FUN_001fd890, bpRootDestroyTask,
                                          workData);
    drawTask = kwlnTaskInitEx("battle panel draw", 0x106f, 1, 2,
                              FUN_001fdac0, NULL, workData);
    workData[2] = (u32)drawTask;
    kwlnTaskAddChild(task, drawTask);
    sBtlPanelTask = task;
    FUN_00208ad0(workData + 0x1df8);
    FUN_00201730(workData + 8);
    bppMain0020ed50(workData + 0x2fd0);
    FUN_0020fe20(workData + 0x466c);
    FUN_0021b650(workData + 0x7020);
    FUN_0021b920(workData + 0x7023);
    FUN_0023f480(workData + 0x7048);
    FUN_00242c40(workData + 0xad88);
    FUN_00248490(workData + 0xca44);
    FUN_00249240(workData + 0xcbc8);
    FUN_0024a6c0(workData + 0xcbcc);
    FUN_0024c100(workData + 0xcbd0);
    FUN_00251050(workData + 0xccc5);
    FUN_00251a70(workData + 0xccca);
    FUN_00251f20(workData + 0xccd0);
    FUN_00252e60(workData + 0xcd94);
    FUN_0025bdf0(workData + 0xd06c);
    FUN_0025cf00(workData + 0xd1b8);
    FUN_00266eb0(workData + 0xd3c0);
    FUN_0027b5b0(workData + 0xd3c4);
    bppMain0020ed70();
    FUN_0025cf20();
    return task;
}

/* W415 census negative: corrected full-project census is UNRESOLVED (retail-only 0x001FFF40; candidate extra K_Assert plus unmappable static panelMiscWork); no safe call-target edit was established. */
/* W418 negative probe: replacing extra K_Assert with retail-only FUN_001FFF40 call gave nd326/556B -> 322/532B; rate worsened, so reverted. */
// FUN_001FD890 NONMATCHING
void* FUN_001fd890(KwlnTask* task)
{
    u32* work;
    u32* misc;
    u32 flags;

    work = (u32*)task->workData;
    func_0021bcb0();
    func_0024c110();
    bpRushUpdate();
    flags = work[0];
    if (flags & 0x400)
    {
        if (bpRes0021bab0())
        {
            return NULL;
        }
        bpd00253410();
        work[0] = flags & ~0x401u;
    }
    misc = (u32*)panelMiscWork();
    K_ASSERT(misc != NULL, 0x164);
    if ((misc[3] & 0x80) && !(misc[3] & 0x800))
    {
        return NULL;
    }
    func_00210d90((u8*)work + 0x119b0);
    func_002510d0();
    func_00251a80();
    flags = work[0];
    if ((flags & 4) && !(flags & 8) && FUN_002053C0())
    {
        FUN_00201B50();
        work[0] = flags | 8;
    }
    bppMain0020edf0();
    flags = work[0];
    if ((flags & 0x8000) && !baiMainIsActive())
    {
        func_0021c7e0();
        work[0] = flags & ~0x8000u;
    }
    bpo00252060();
    func_002492b0();
    flags = work[0];
    if ((flags & 0x1000) && !bpe00249600())
    {
        func_00248620();
        flags = work[0];
        work[0] = flags & ~0x1001u;
    }
    func_00242cc0();
    func_0025c220();
    bpPersonaUpdate();
    func_0027b610();
    flags = work[0];
    if ((flags & 0x1000000) && !func_00249130() &&
        (flags & 0x200000))
    {
        func_00245e50();
        work[0] = flags & ~0x200000u;
    }
    return NULL;
}


// FUN_001FDAC0
void* FUN_001fdac0(KwlnTask* task)
{
    u32* work;
    u32* misc;
    u32 flags;

    work = (u32*)task->workData;
    misc = (u32*)DAT_007ce3ec;
    if ((misc[3] & 0x80) && !(misc[3] & 0x800))
    {
        return NULL;
    }
    func_00213e80((u8*)work + 0x119b0);
    func_00252f30();
    func_00209540();
    func_0023f540();
    func_0024cca0();
    func_002095a0();
    func_002532b0();
    flags = work[0];
    if ((flags & 4) && ((~flags & 0x20) != 0))
    {
        FUN_002016B0();
    }
    func_0020f260();
    if ((~work[0] & 0x40000) != 0)
    {
        func_00243150();
    }
    func_00241910();
    func_00248bb0();
    func_002520f0();
    func_0025c9c0();
    func_0025d470();
    func_0027b880();
    return NULL;
}

// FUN_001fdbe0
void bpRootDestroyTask(KwlnTask* btlPanelTask)
{
    bpRootDestroy(btlPanelTask);
}

// FUN_001fdc00
void bpRootDestroy(KwlnTask* btlPanelTask)
{
    u32* workData;

    workData = (u32*)btlPanelTask->workData;
    K_ASSERT((~*workData & 0x400) != 0, 0x182);
    FUN_00266f00();
    FUN_0025cf10();
    FUN_0025be00();
    FUN_00252e80();
    FUN_00251f30();
    FUN_002484a0();
    FUN_00251060();
    FUN_0021b660();
    basShutdown();
    FUN_00249250();
    FUN_00242c60();
    FUN_0023f500();
    FUN_00208b20();
    FUN_00201780();
    bppMain0020edc0();
    FUN_00215770(workData + 0x466c);
    FUN_0021bb60(workData + 0x7023);
    FUN_0027b5d0();
    sBtlPanelTask = NULL;
    RwFree(btlPanelTask->workData);
}


// FUN_001fdd20
void bpRoot001fdd20()
{
    bppMain0020f3b0();
}


// FUN_001fdd40
void bpRoot001fdd40()
{
    bppMain0020f570();
}


// FUN_001fdd60
void bpRoot001fdd60()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    FUN_001ff890();
    *flags |= 4;
}


// FUN_001FDDA0
void FUN_001FDDA0(void)
{
    u32* work;

    work = (u32*)sBtlPanelTask->workData;
    FUN_001FFC60();
    work[0] &= ~4u;
    work[0] &= ~8u;
}


// FUN_001FDDF0
u32 FUN_001FDDF0(void)
{
    u32 flags;

    flags = *(u32*)sBtlPanelTask->workData;
    if (flags & 4)
    {
        if (flags & 0x200)
        {
            K_ASSERT(~flags & 8, 0x1c4);
            return 1;
        }
        if (flags & 0x2000)
        {
            K_ASSERT(~flags & 8, 0x1c9);
            return 1;
        }
        return flags & 8;
    }
    K_ASSERT(0, 0x1d3);
    return 0;
}


// FUN_001fdec0
void bpRoot001fdec0()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    FUN_00201d10();
    FUN_00205410();
    *flags &= ~8;
}

// FUN_001FDF10
void FUN_001FDF10(void* out)
{
    u32* work;
    u32 mode;
    u16 value;

    work = (u32*)sBtlPanelTask->workData;
    K_ASSERT((work[0] & 4) != 0, 0x1e9);
    *(u32*)out = 0;
    if (work[0] & 0x2000)
    {
        *(u32*)((u8*)out + 4) = 10;
        *(u32*)((u8*)out + 0x10) = work[4];
        return;
    }
    if (work[0] & 0x200)
    {
        *(u32*)((u8*)out + 4) = 4;
        mode = work[3];
        switch (mode)
        {
        case 0:
            *(u32*)out |= 1;
            *(u16*)((u8*)out + 0xA) = 0;
            return;
        case 1:
            *(u32*)out |= 2;
            *(u16*)((u8*)out + 0xA) = 0x144;
            return;
        default:
            K_ASSERT(0, 0x200);
            break;
        }
        return;
    }
    if (func_00207f70())
    {
        *(u32*)((u8*)out + 4) = 13;
        return;
    }
    if (func_00207fc0())
    {
        *(u32*)((u8*)out + 4) = 7;
        return;
    }
    mode = FUN_002054C0();
    switch (mode)
    {
    case 0:
        *(u32*)((u8*)out + 4) = 1;
        break;
    case 1:
        *(u32*)((u8*)out + 4) = 2;
        value = FUN_00205500();
        *(u16*)((u8*)out + 0xA) = value;
        break;
    case 2:
        *(u32*)((u8*)out + 4) = 3;
        value = FUN_00205550();
        *(u16*)((u8*)out + 8) = value;
        break;
    case 4:
        *(u32*)((u8*)out + 4) = 5;
        value = FUN_002055A0();
        *(u16*)((u8*)out + 0xC) = value;
        break;
    case 5:
        *(u32*)((u8*)out + 4) = 6;
        break;
    case 6:
        *(u32*)((u8*)out + 4) = 7;
        break;
    default:
        K_ASSERT(0, 0x229);
        break;
    }
}


// FUN_001fe120
void bpRoot001fe120()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    if (*flags & 4)
    {
        FUN_00201c30();
        *flags |= 0x40000;
        bppMain0020fc40();
        FUN_002085e0();
    }
    FUN_00208b30();
    *flags |= 0x10;
}


// FUN_001fe1a0
void bpRoot001fe1a0()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    if (*flags & 4)
    {
        FUN_00201e00();
        *flags &= ~0x40000;
        bppMain0020fc90();
        FUN_00208630();
    }
    FUN_002094f0();
    *flags &= ~0x10;
}


// FUN_001FE220
u32 FUN_001FE220(void)
{
    u32* work;
    u32 result;

    work = (u32*)sBtlPanelTask->workData;
    result = func_00208720() != 0;
    if (!result)
    {
        result = (*work & 0x10000) != 0;
    }
    return result;
}


// FUN_001fe270
void bpRoot001fe270(void* param_1)
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    FUN_0020fce0();
    FUN_00208680();
    FUN_0020fe30(flags + 0x466c, 0, param_1);
    *flags |= 0x100;
}


// FUN_001fe2e0
void bpRoot001fe2e0(void* param_1)
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    FUN_0020fce0();
    FUN_00208680();
    FUN_0020fe30(flags + 0x466c, 1, param_1);
    *flags |= 0x100;
}


// FUN_001fe350
void bpRoot001fe350()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    FUN_0020fd30();
    FUN_002086d0();
    FUN_00210d60(flags + 0x466c);
    *flags &= ~0x100;
}


// FUN_001fe3b0
void bpRoot001fe3b0(void* param_1)
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    K_ASSERT(*flags & 0x200, 0x28c);
    *flags &= ~0x200;
    FUN_0021b8b0(param_1);
}


// FUN_001fe430
void bpRoot001fe430()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    K_ASSERT(*flags & 0x200, 0x29a);
    *flags &= ~0x200;
    FUN_0021b830();
}


// FUN_001fe4a0. Battle command menu's analyze request (bas_main.c) was serviced
void bpRootCompleteAnalyze()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    K_ASSERT(*flags & 0x2000, 0x2a8);
    *flags &= ~0x2000;
    basClearAnalyzePending();
}

// FUN_001fe510
void bpRoot001fe510(u32 param_1)
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    K_ASSERT(*flags & 4, 0x2b1);
    *flags |= 0x200;
    flags[3] = param_1;
}

// FUN_001fe580. Request the enemy analyze page (from bas_main.c)
void bpRootRequestAnalyze(u32 unitId)
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    K_ASSERT(*flags & 4, 0x2ba);
    *flags |= 0x2000;
    flags[4] = unitId;
}


// FUN_001fe5f0
void bpRoot001fe5f0()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    FUN_0021b940();
    *flags |= 0x400;
}


// FUN_001fe630
u32 bpRoot001fe630()
{
    return *(u32*)sBtlPanelTask->workData & 0x400;
}


// FUN_001FE650
void FUN_001FE650(void* descriptor)
{
    u8* desc;
    void* resource;
    s32 level;
    desc = (u8*)descriptor;
    K_ASSERT(btlUnitFindFromId(*(u16*)(desc + 0x10)) != NULL, 0x2d5);
    if (func_00242a60() == 0)
    {
        return;
    }
    resource = func_00242260();
    if (*(u32*)(desc + 8) & 1) func_00242320(resource, 0);
    else if (*(u32*)(desc + 8) & 2) func_00242320(resource, 1);
    else if (*(u32*)(desc + 8) & 4) func_00242320(resource, 3);
    else if (*(u32*)(desc + 8) & 8) func_00242320(resource, 2);
    func_00242a50(resource, *(u32*)(desc + 0x10));
    if (*(u32*)(desc + 8) & 0x10) func_00242600(resource, *(u32*)desc);
    if (*(u32*)(desc + 8) & 0x20) func_00242720(resource, *(u32*)(desc + 4));
    if (*(u32*)(desc + 8) & 0x40) func_00242a30(resource);
    level = *(s32*)(desc + 0x14);
    if (level > 1)
    {
        func_00242c20(resource, *(u32*)(desc + 0x18), level);
    }
    func_00242540(resource);
}


// FUN_001fe7f0
void bpRoot001fe7f0()
{
    FUN_00244120();
}


// FUN_001FE810
void FUN_001FE810(s32 id)
{
    u32* work;

    work = (u32*)sBtlPanelTask->workData;
    if (id == -1)
    {
        func_002453d0(0);
        func_002441b0(1);
        work[0] |= 0x10000;
    }
    else
    {
        func_002453d0((u16)id);
        func_002441b0(0);
        work[0] |= 0x10000;
    }
    if (id == 0x14f || id == 0x144)
    {
        func_00208680();
    }
}


// FUN_001fe8d0
void bpRoot001fe8d0()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    FUN_002449d0();
    FUN_002086d0();
    *flags &= ~0x10000;
}


// FUN_001fe920
void bpRoot001fe920()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    FUN_00244a00();
    FUN_002086d0();
    *flags &= ~0x10000;
}


// FUN_001fe970
void bpRoot001fe970()
{
    FUN_00244a40();
}


// FUN_001fe990
void bpRoot001fe990()
{
    FUN_00244e10();
}


// FUN_001fe9b0
void bpRoot001fe9b0()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    FUN_00248500();
    if (*flags & 0x10000)
    {
        FUN_00245e00();
        *flags |= 0x20000;
    }
}


// FUN_001fea10
void bpRoot001fea10()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    FUN_00248580();
    if (*flags & 0x10000)
    {
        FUN_00245e00();
        *flags |= 0x20000;
    }
}


// FUN_001fea70
void bpRoot001fea70()
{
    FUN_00249180();
}


// FUN_001fea90
void bpRoot001fea90()
{
    FUN_00208010();
}


// FUN_001FEAB0
void FUN_001FEAB0(void)
{
    u16* values;
    u32* work;

    work = (u32*)sBtlPanelTask->workData;
    values = (u16*)func_0030c0c0();
    K_ASSERT(values != NULL, 0x371);
    func_00249420(values[0], values[1], values[2]);
    work[0] |= 0x1000;
}


// FUN_001feb30
u32 bpRoot001feb30()
{
    return *(u32*)sBtlPanelTask->workData & 0x1000;
}


// FUN_001feb50
void bpRoot001feb50()
{
    FUN_00242ae0();
}


// FUN_001feb70
void bpRoot001feb70()
{
    FUN_00215a30((u8*)sBtlPanelTask->workData + 0x119b0);
}


// FUN_001febb0
void bpRoot001febb0()
{
    FUN_00215a40((u8*)sBtlPanelTask->workData + 0x119b0);
}


// FUN_001febf0
void bpRoot001febf0(u32 param_1)
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    flags[0xccc4] = param_1;
    *flags |= 0x4000;
    FUN_0021bb00();
}


// FUN_001fec30
void bpRoot001fec30()
{
    FUN_0021bb50();
}


// FUN_001fec50
void bpRoot001fec50()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    K_ASSERT(*flags & 0x4000, 0x3ac);
    FUN_0024cf00(flags[0xccc4]);
    *flags |= 0x8000;
}


// FUN_001fecc0
void bpRoot001fecc0()
{
    baiMainIsActive();
}


// FUN_001fece0
void bpRoot001fece0()
{
    FUN_002079c0();
}


// FUN_001fed00
void bpRoot001fed00()
{
    FUN_00207bf0();
}

// FUN_001fed20
void bpRoot001fed20()
{
    FUN_00207a10();
}


// FUN_001fed40
void bpRoot001fed40()
{
    FUN_00207c40();
}


// FUN_001fed60
void bpRoot001fed60()
{
    FUN_00207a60();
}


// FUN_001fed80
void bpRoot001fed80()
{
    FUN_00207c90();
}


// FUN_001feda0
void bpRoot001feda0()
{
    FUN_00207ab0();
}


// FUN_001fedc0
void bpRoot001fedc0()
{
    FUN_00207ce0();
}


// FUN_001fede0
void bpRoot001fede0()
{
    FUN_00207b00();
}


// FUN_001fee00
void bpRoot001fee00()
{
    FUN_00207d30();
}


// FUN_001fee20
void bpRoot001fee20()
{
    FUN_00207b50();
}


// FUN_001fee40
void bpRoot001fee40()
{
    FUN_00207d80();
}

// FUN_001fee60
void bpRoot001fee60()
{
    FUN_00207ba0();
}

// FUN_001fee80
void bpRoot001fee80()
{
    FUN_00207dd0();
}


// FUN_001feea0
void bpRoot001feea0(s16 pcId)
{
    bppMain0020f9a0(pcId);
}


// FUN_001FEEC0
u32 FUN_001FEEC0(void)
{
    u32 result;

    result = func_00208010() != 0;
    if (!result)
    {
        result = func_00208050() != 0;
    }
    if (!result)
    {
        result = func_00208130() != 0;
    }
    return result;
}


// FUN_001fef10
void bpRoot001fef10()
{
    FUN_00242b80();
}


// FUN_001fef30
void bpRoot001fef30()
{
    FUN_00251f40();
}

// FUN_001fef50
void bpRoot001fef50()
{
    FUN_00252e90();
}
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





/* Removing this loses FUN_00201880 (MATCH nd0 -> MISMATCH nd307) - measured W161. */





static u32 panelSkillAccept(u16 id)
{
    return FUN_002055F0(id);
}

static PanelSkillRow* panelSkillRow(u32 index)
{
    return (PanelSkillRow*)(panelWork() + 0x4a90 + index * 0x2d0);
}









static PanelSkillRow* panelItemRow(u32 index)
{
    return (PanelSkillRow*)(panelWork() + 0x4a90 + index * 0x310);
}














/* Removing this loses FUN_00204480 (MATCH nd0 -> MISMATCH nd341) - measured W308. */



















/* Removing this loses FUN_002063F0 (MATCH nd0 -> MISMATCH nd128) - measured W308. */




static void panelTargetEffect(u32 first, u32 second)
{
    func_003c7430(first);
    func_003c74e0(second);
}













// FUN_001fef70
void bpRoot001fef70()
{
    FUN_00252ee0();
}

// FUN_001FEF90
void FUN_001FEF90(u32 id)
{
    u32 first;
    u32 second;
    u32 third;

    switch ((u16)id)
    {
    case 2:
        first = 0xe3; second = 0xe4; third = 0xe5;
        break;
    case 3:
        if (datGetFlag(0xdf) != 0)
            goto flag_set;
        first = 0xe6;
        goto flag_done;
    flag_set:
        first = 0xe7;
    flag_done:
        second = 0xe8; third = 0xe9;
        break;
    case 4:
        first = 0xea; second = 0xeb; third = 0xec;
        break;
    case 5:
        first = 0xed; second = 0xee; third = 0xef;
        break;
    case 7:
        first = 0xf0; second = 0xf1; third = 0xf2;
        break;
    case 8:
        first = 0xf3; second = 0xf4; third = 0xf5;
        break;
    case 9:
        if (datGetScenarioMode() != 0)
            goto scenario_set;
        first = 0xf6; second = 0xf7; third = 0xf8;
        break;
    scenario_set:
        first = 0xfc; second = 0xfd; third = 0xfe;
        break;
    case 10:
        first = 0xf9; second = 0xfa; third = 0xfb;
        break;
    default:
        K_ASSERT(0, 0x468);
        break;
    }
    func_0025be60(first, second, third);
}

// FUN_001ff100
void bpRoot001ff100()
{
    FUN_0025c190();
}

// FUN_001ff120
void bpRoot001ff120()
{
    FUN_0025c1e0();
}

// FUN_001ff140
void bpRoot001ff140()
{
    FUN_0025c110();
}

// FUN_001FF160
void FUN_001FF160(u32 id)
{
    u32 first;
    u32 second;
    u32 third;

    switch ((u16)id)
    {
    case 2:
        first = 0xff; second = 0x100; third = 0x101;
        break;
    case 3:
        first = 0x102; second = 0x103; third = 0x104;
        break;
    case 4:
        first = 0x105; second = 0x106; third = 0x107;
        break;
    case 5:
        first = 0x108; second = 0x109; third = 0x10a;
        break;
    case 7:
        first = 0x10b; second = 0x10c; third = 0x10d;
        break;
    case 8:
        first = 0x10e; second = 0x10f; third = 0x110;
        break;
    case 9:
        if (datGetScenarioMode() != 0)
            goto scenario_set2;
        first = 0x111; second = 0x112; third = 0x113;
        break;
    scenario_set2:
        first = 0x117; second = 0x118; third = 0x119;
        break;
    case 10:
        first = 0x114; second = 0x115; third = 0x116;
        break;
    default:
        K_ASSERT(0, 0x4be);
        break;
    }
    func_0025be60(first, second, third);
}

 
// FUN_001ff2b0
void bpRoot001ff2b0()
{
    FUN_0025c190();
}

// FUN_001ff2d0
void bpRoot001ff2d0()
{
    FUN_0025c1e0();
}

// FUN_001ff2f0
void bpRoot001ff2f0()
{
    FUN_0025c110();
}


// FUN_001ff310
void bpRoot001ff310()
{
    FUN_0025d800();
}

// FUN_001ff330
void bpRoot001ff330()
{
    FUN_0025d850();
}

// FUN_001ff350
void bpRoot001ff350()
{
    FUN_0025d760();
}

// FUN_001FF370
void FUN_001FF370(void)
{
    bpRush0025d7b0();
}

// FUN_001FF390
void FUN_001FF390(void)
{
    func_0020fd80();
}

// FUN_001FF3B0
void FUN_001FF3B0(void)
{
    func_0020fdd0();
}

// FUN_001FF3D0
void FUN_001FF3D0(void)
{
    func_0027b9f0();
}

// FUN_001FF3F0
void FUN_001FF3F0(void)
{
    func_0027ba90();
}

// FUN_001FF410
void FUN_001FF410(void)
{
    func_0027bae0();
}






