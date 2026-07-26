#include "Main/Battle/Panel/bp_root.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"
#include "Main/Battle/Cmd/bcm_main.h"
#include "Main/Battle/Cmd/bpp_main.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"

typedef struct PanelSkillRow
{
    u32 flags;
    u32 handle;
    u32 type;
    u32 icon;
} PanelSkillRow;

extern u8* DAT_007ce3f8;
extern u8* DAT_007ce3ec;

static u8* panelWork(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    return gBcmWork;
}

static u32 panelWork32(u32 offset)
{
    return *(u32*)(panelWork() + offset);
}

static void panelSetWork32(u32 offset, u32 value)
{
    *(u32*)(panelWork() + offset) = value;
}

static u16 panelWork16(u32 offset)
{
    return *(u16*)(panelWork() + offset);
}

static void panelSetWork16(u32 offset, u16 value)
{
    *(u16*)(panelWork() + offset) = value;
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

// FUN_001fdbe0
void bpRootDestroyTask(KwlnTask* btlPanelTask)
{
    bpRootDestroy(btlPanelTask);
}

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

// FUN_001fe630
u32 bpRoot001fe630()
{
    return *(u32*)sBtlPanelTask->workData & 0x400;
}

// FUN_001feb30
u32 bpRoot001feb30()
{
    return *(u32*)sBtlPanelTask->workData & 0x1000;
}


// FUN_001fdd60
void bpRoot001fdd60()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    FUN_001ff890();
    *flags |= 4;
}

void FUN_0021b940();

// FUN_001fe5f0
void bpRoot001fe5f0()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    FUN_0021b940();
    *flags |= 0x400;
}

void FUN_00215a30();

// FUN_001feb70
void bpRoot001feb70()
{
    FUN_00215a30((u8*)sBtlPanelTask->workData + 0x119b0);
}

void FUN_00201d10();
void FUN_00205410();

// FUN_001fdec0
void bpRoot001fdec0()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    FUN_00201d10();
    FUN_00205410();
    *flags &= ~8;
}

void FUN_00244a00();
void FUN_002086d0();

// FUN_001fe920
void bpRoot001fe920()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    FUN_00244a00();
    FUN_002086d0();
    *flags &= ~0x10000;
}

void FUN_0020fce0();
void FUN_00208680();
void FUN_0020fe30();

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

void FUN_002449d0();

// FUN_001fe8d0
void bpRoot001fe8d0()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    FUN_002449d0();
    FUN_002086d0();
    *flags &= ~0x10000;
}

void FUN_00215a40();

// FUN_001febb0
void bpRoot001febb0()
{
    FUN_00215a40((u8*)sBtlPanelTask->workData + 0x119b0);
}

void FUN_00248500();
void FUN_00245e00();

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

void FUN_00248580();

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

void FUN_0021bb00();

// FUN_001febf0
void bpRoot001febf0(u32 param_1)
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    flags[0xccc4] = param_1;
    *flags |= 0x4000;
    FUN_0021bb00();
}

void FUN_0020fd30();
void FUN_00210d60();

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

void FUN_00201c30();
void bppMain0020fc40();
void FUN_002085e0();
void FUN_00208b30();

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

void FUN_0021b830();

// FUN_001fe430
void bpRoot001fe430()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    K_ASSERT(*flags & 0x200, 0x29a);
    *flags &= ~0x200;
    FUN_0021b830();
}

void basClearAnalyzePending(void); // bas_main.c

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

void FUN_0021b8b0();

// FUN_001fe3b0
void bpRoot001fe3b0(void* param_1)
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    K_ASSERT(*flags & 0x200, 0x28c);
    *flags &= ~0x200;
    FUN_0021b8b0(param_1);
}

void FUN_00201e00();
void bppMain0020fc90();
void FUN_00208630();
void FUN_002094f0();

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

void FUN_0024cf00();

// FUN_001fec50
void bpRoot001fec50()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    K_ASSERT(*flags & 0x4000, 0x3ac);
    FUN_0024cf00(flags[0xccc4]);
    *flags |= 0x8000;
}

void bppMain0020f3b0();

// FUN_001fdd20
void bpRoot001fdd20()
{
    bppMain0020f3b0();
}

void bppMain0020f570();

// FUN_001fdd40
void bpRoot001fdd40()
{
    bppMain0020f570();
}

void FUN_00244120();

// FUN_001fe7f0
void bpRoot001fe7f0()
{
    FUN_00244120();
}

void FUN_00244a40();

// FUN_001fe970
void bpRoot001fe970()
{
    FUN_00244a40();
}

void FUN_00249180();

// FUN_001fea70
void bpRoot001fea70()
{
    FUN_00249180();
}

void FUN_0021bb50();

// FUN_001fec30
void bpRoot001fec30()
{
    FUN_0021bb50();
}

u32 baiMainIsActive(void);

// FUN_001fecc0
void bpRoot001fecc0()
{
    baiMainIsActive();
}

void FUN_00207bf0();

// FUN_001fed00
void bpRoot001fed00()
{
    FUN_00207bf0();
}

void FUN_002079c0();

// FUN_001fece0
void bpRoot001fece0()
{
    FUN_002079c0();
}

void FUN_00207a10();

// FUN_001fed20
void bpRoot001fed20()
{
    FUN_00207a10();
}

void FUN_00207c40();

// FUN_001fed40
void bpRoot001fed40()
{
    FUN_00207c40();
}

void FUN_00207a60();

// FUN_001fed60
void bpRoot001fed60()
{
    FUN_00207a60();
}

void FUN_00207c90();

// FUN_001fed80
void bpRoot001fed80()
{
    FUN_00207c90();
}

void FUN_00207ab0();

// FUN_001feda0
void bpRoot001feda0()
{
    FUN_00207ab0();
}

void FUN_00207ce0();

// FUN_001fedc0
void bpRoot001fedc0()
{
    FUN_00207ce0();
}

void FUN_00207d30();

// FUN_001fee00
void bpRoot001fee00()
{
    FUN_00207d30();
}

void FUN_00207b00();

// FUN_001fede0
void bpRoot001fede0()
{
    FUN_00207b00();
}

void FUN_00207b50();

// FUN_001fee20
void bpRoot001fee20()
{
    FUN_00207b50();
}

void FUN_00207d80();

// FUN_001fee40
void bpRoot001fee40()
{
    FUN_00207d80();
}

void FUN_00207ba0();

// FUN_001fee60
void bpRoot001fee60()
{
    FUN_00207ba0();
}

void FUN_00207dd0();

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

void FUN_0025c190();

// FUN_001ff2b0
void bpRoot001ff2b0()
{
    FUN_0025c190();
}

void FUN_0025d800();

// FUN_001ff310
void bpRoot001ff310()
{
    FUN_0025d800();
}

void FUN_00242b80();

// FUN_001fef10
void bpRoot001fef10()
{
    FUN_00242b80();
}

void FUN_00251f40();

// FUN_001fef30
void bpRoot001fef30()
{
    FUN_00251f40();
}

void FUN_00252e90();

// FUN_001fef50
void bpRoot001fef50()
{
    FUN_00252e90();
}

void FUN_00252ee0();

// FUN_001fef70
void bpRoot001fef70()
{
    FUN_00252ee0();
}

void FUN_0025c190();

// FUN_001ff100
void bpRoot001ff100()
{
    FUN_0025c190();
}

void FUN_0025c1e0();

// FUN_001ff120
void bpRoot001ff120()
{
    FUN_0025c1e0();
}

void FUN_0025c110();

// FUN_001ff140
void bpRoot001ff140()
{
    FUN_0025c110();
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

void FUN_0025d850();

// FUN_001ff330
void bpRoot001ff330()
{
    FUN_0025d850();
}

void FUN_00244e10();

// FUN_001fe990
void bpRoot001fe990()
{
    FUN_00244e10();
}

void FUN_00208010();

// FUN_001fea90
void bpRoot001fea90()
{
    FUN_00208010();
}

void FUN_00242ae0();

// FUN_001feb50
void bpRoot001feb50()
{
    FUN_00242ae0();
}

// FUN_001ff350
void bpRoot001ff350()
{
    FUN_0025d760();
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

u32 bpMisc001ff500(u32);
u32 bpMisc001ff740(void);
void bcmPanel00222a60(void);
void bcmPanel00222b90(void);
void bcmPanel00222930(void);
void bcmPanel00222d60(void);
void bcmPanel0022bf60(void);
void func_0021f0c0(void*);

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
// FUN_00201880 NONMATCHING
void FUN_00201880(void)
{
    s32 i;
    s32 selector;
    u32 request;
    u32* entry;
    u32* flags;
    u8* work;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    for (i = 0; i < 7; i++)
    {
        request = 0;
        entry = (u32*)work + i;
        flags = entry + 0x590;
        *flags &= ~1u;
        selector = i;
        switch (selector)
        {
        case 0:
            if (*(u32*)(work + 0xc) & 0x20) request = 1;
            break;
        case 1:
            if (*(u32*)(work + 0xc) & 1) request = 1;
            break;
        case 2:
            if (*(u32*)(work + 0xc) & 2) request = 1;
            break;
        case 3:
            if (*(u32*)(work + 0xc) & 4) request = 1;
            break;
        case 4:
            if (*(u32*)(work + 0xc) & 8) request = 1;
            break;
        case 5:
            if (*(u32*)(work + 0xc) & 0x10) request = 1;
            break;
        case 6:
            if (*(u32*)(work + 0xc) & 0x40) request = 1;
            break;
        }
        if (request)
        {
            *flags |= 1;
        }
    }
    if (*(u32*)work & 0x800000)
    {
        func_00208360();
    }
    request = func_003a5540(100, 100, -0x4e, 2, 6,
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

// FUN_00201EF0 NONMATCHING
void FUN_00201EF0(void)
{
    DatPersonaWork* persona;
    u16* skills;
    u32 count;
    u32 i;
    u32 found;
    u32* work;

    work = (u32*)panelWork();
    persona = datPersonaGetByPcId(1);
    count = datPersonaCountValidSkills(persona);
    skills = datPersonaGetSkills(persona);
    found = 0;
    for (i = 0; i < count; i++)
    {
        if (FUN_002055F0(skills[i]))
        {
            found = 1;
            break;
        }
    }
    if (func_0030c0c0() == NULL && i == count)
    {
        work[0] |= 0x80;
    }
    else if ((work[0x77a0 / 4] & 2) == 0)
    {
        work[3] |= 1;
    }
    (void)found;
}

static u32 panelSkillAccept(u16 id)
{
    return FUN_002055F0(id);
}

static PanelSkillRow* panelSkillRow(u32 index)
{
    return (PanelSkillRow*)(panelWork() + 0x4a90 + index * 0x2d0);
}

// FUN_00202010 NONMATCHING
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
    K_ASSERT(out < 10, 0x7e4);
    *(u32*)(p + 0x74) = out;
    *(u32*)(p + 0x70) = out;
    if (out >= 5)
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
        if (selectedSkill != 0)
        {
            for (i = 0; i < *(s32*)(p + 0x74); i++)
            {
                if (*(u16*)(p + 0x2c + i * 8) == (u16)selectedSkill)
                {
                    break;
                }
            }
            if (i == *(s32*)(p + 0x74))
            {
                *(u32*)(p + 0x7664) = 0;
                *(u32*)(p + 0x765c) = 0;
            }
            else if (i == *(s32*)(p + 0x74) - 1)
            {
                *(u32*)(p + 0x765c) =
                    i - (*(s32*)(p + 0x70) - 1);
                *(u32*)(p + 0x7664) = i;
            }
            else if (*(s32*)(p + 0x70) - 2 < i)
            {
                *(u32*)(p + 0x765c) =
                    i - (*(s32*)(p + 0x70) - 2);
                *(u32*)(p + 0x7664) = i;
            }
            else
            {
                *(u32*)(p + 0x765c) = 0;
                *(u32*)(p + 0x7664) = i;
            }
        }
        else
        {
            *(u32*)(p + 0x7664) = 0;
            *(u32*)(p + 0x765c) = 0;
        }
    }
    else
    {
        *(u32*)(p + 0x7664) = 0;
        *(u32*)(p + 0x765c) = 0;
    }
    FUN_002024B0();
    visible = *(s32*)(p + 0x74);
    if (visible >= 5)
    {
        visible = 4;
    }
    for (i = 0; i < visible; i++)
    {
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
        *(u32*)(row + 8) =
            (((DAT_007ce3f8 + *(u16*)(p + i * 8 + 0x2c) * 0x2c)[3] == 1) ||
             ((DAT_007ce3f8 + *(u16*)(p + i * 8 + 0x2c) * 0x2c)[3] == 2)) ? 1 : 0;
        *(u32*)(row + 0xc) =
            func_003083f0(*(u32*)(misc2 + 0xa2c), *(u16*)(p + i * 8 + 0x2c));
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

// FUN_002025E0 NONMATCHING
void FUN_002025E0(void)
{
    u32 i;
    u32 start;
    u32* rec;
    PanelSkillRow* row;
    u16 id;
    u8* misc;

    K_ASSERT((panelWork32(0) & 2) != 0, 0x87c);
    misc = (u8*)bpMisc001ff500(1);
    start = panelWork32(0x765c);
    for (i = 0; i < panelWork32(0x70); i++)
    {
        rec = (u32*)(panelWork() + (start + i) * 8);
        row = (PanelSkillRow*)(misc + i * 0x2d0);
        row->flags = 0;
        row->handle = rec[0x78 / 4];
        row->flags |= rec[0x28 / 4] & 3;
        id = (u16)rec[0x2c / 4];
        row->type = panelDataType(id) == 2 ? 1 : 0;
        row->icon = func_003083f0(*(u32*)(panelWork() + 0xa2c), id);
    }
    panelSetWork32(0x7640, 0);
    panelSetWork32(0x64a0, panelWork32(0x70));
    panelSetWork32(0x6498, panelWork32(0x7664));
    panelSetWork32(0x649c, panelWork32(0x765c));
    panelSetWork32(0x64a4, panelWork32(0x74));
    panelSetWork32(0x6d28, 0);
    if (bcm00207930(FUN_00205500()))
    {
        panelSetWork32(0x6d28, 1);
        panelSetWork32(0x6d24, FUN_00207960(FUN_00205500()));
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

// FUN_00202A10 NONMATCHING
void FUN_00202A10(void)
{
    u32 i;
    u32 count;
    u32 handle;
    u16 id;

    count = panelWork32(0x70);
    for (i = 0; i < count; i++)
    {
        handle = *(u32*)(panelWork() + 0x78 + i * 4);
        if (handle != 0) func_003b0170(handle);
        *(u32*)(panelWork() + 0x78 + i * 4) = 0;
    }
    if (panelWork32(0) & 0x800000)
    {
        func_00208360();
    }
    func_003c7d60(7);
    for (i = 0; i < count; i++)
    {
        id = panelWork16(0x2c + i * 8);
        handle = func_003b0970(func_0030bb40(id), 2,
                               i == panelWork32(0x7664) - panelWork32(0x765c) ? 6 : 0,
                               0, 0);
        *(u32*)(panelWork() + 0x78 + i * 4) = handle;
    }
    panelSetWork32(0, panelWork32(0) | 2);
}

// FUN_00202BC0 NONMATCHING
void FUN_00202BC0(void)
{
    u32 i;

    K_ASSERT((panelWork32(0) & 2) != 0, 0x910);
    for (i = 0; i < panelWork32(0x70); i++)
    {
        if (*(u32*)(panelWork() + 0x78 + i * 4) != 0)
            func_003b0170(*(u32*)(panelWork() + 0x78 + i * 4));
    }
    if (panelWork32(0) & 0x20)
    {
        func_003b0170(panelWork32(0x88));
    }
    panelSetWork32(0, panelWork32(0) & ~3u);
}
static PanelSkillRow* panelItemRow(u32 index)
{
    return (PanelSkillRow*)(panelWork() + 0x4a90 + index * 0x310);
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
// FUN_00202D70 NONMATCHING
void FUN_00202D70(void)
{
    u32 id;
    u32 out;
    u32 i;
    u32 visible;
    u16 selected;
    PanelSkillRow* row;

    out = 0;
    for (id = 0xfa0; id < 0x107f && out < 0x100; id++)
    {
        if (FUN_00205650((s16)id) &&
            func_00170760(1, (s16)id) != 0)
        {
            panelSetWork16(0x9c + out * 2, (u16)id);
            out++;
        }
    }
    panelSetWork32(0x260, out);
    FUN_00203030();
    panelSetWork32(0x768c, 0);
    panelSetWork32(0x7694, panelWork32(0x25c));
    panelSetWork32(0x769c, panelWork32(0x260));
    func_00208570(panelWork() + 0x768c);
    selected = 0;
    if (datGetFlag(0x186) && FUN_0016F380(0x32))
    {
        for (i = 0; i < out; i++)
        {
            if (panelWork16(0x9c + i * 2) == (u16)FUN_0016F380(0x32))
            {
                selected = (u16)i;
                break;
            }
        }
    }
    panelSetWork32(0x7698, selected);
    panelSetWork32(0x7690, selected > 3 ? selected - 3 : 0);
    visible = panelWork32(0x25c);
    for (i = 0; i < visible; i++)
    {
        row = panelItemRow(i);
        row->flags = 0;
        row->handle = *(u32*)(panelWork() + 0x8c + i * 4);
        row->type = 0;
        row->icon = func_00170760(1, panelWork16(0x9c + i * 2));
    }
    panelSetWork32(0x7640, 0);
    panelSetWork32(0x64a0, visible);
    panelSetWork32(0x6498, panelWork32(0x7698));
    panelSetWork32(0x649c, panelWork32(0x7690));
    panelSetWork32(0x64a4, panelWork32(0x260));
    panelSetWork32(0x6d28, 0);
    bcmPanel00222930();
    FUN_0010a4e0(0, 0, 0, 3);
    panelSetWork32(0x10, 2);
}

// FUN_00203030 NONMATCHING
void FUN_00203030(void)
{
    u32 i;
    u32 count;
    u32 handle;
    const char* name;

    count = panelWork32(0x260);
    for (i = 0; i < panelWork32(0x25c); i++)
    {
        handle = *(u32*)(panelWork() + 0x8c + i * 4);
        if (handle != 0) func_003b0170(handle);
        *(u32*)(panelWork() + 0x8c + i * 4) = 0;
    }
    func_003b0e70(1);
    func_003b0e90(2);
    if (count > 4) count = 4;
    for (i = 0; i < count; i++)
    {
        name = func_00171110((s16)panelWork16(0x9c + i * 2), 0);
        handle = func_003b0970((u32)name, 2, i == 0 ? 6 : 0, 0, 0);
        *(u32*)(panelWork() + 0x8c + i * 4) = handle;
    }
    panelSetWork32(0x25c, count);
    func_003b0e90(1);
    func_003b0e70(2);
    panelSetWork32(0, panelWork32(0) | 4);
}

// FUN_002031C0 NONMATCHING
void FUN_002031C0(void)
{
    u32 i;
    u32 start;
    u16 id;
    PanelSkillRow* row;

    K_ASSERT((panelWork32(0) & 4) != 0, 0x9e0);
    FUN_00203410();
    start = panelWork32(0x7690);
    for (i = 0; i < panelWork32(0x25c) && i < 4; i++)
    {
        id = panelWork16(0x9c + (start + i) * 2);
        row = panelItemRow(i);
        row->flags = 0;
        row->handle = *(u32*)(panelWork() + 0x8c + i * 4);
        row->type = 0;
        row->icon = func_00170760(1, id);
    }
    panelSetWork32(0x7640, 0);
    panelSetWork32(0x64a0, panelWork32(0x25c));
    panelSetWork32(0x6498, panelWork32(0x7698));
    panelSetWork32(0x649c, panelWork32(0x7690));
    panelSetWork32(0x64a4, panelWork32(0x260));
    panelSetWork32(0x6d28, 0);
    id = FUN_00205550();
    id = func_0030bc20(id);
    if (bcm00207930(id))
    {
        panelSetWork32(0x6d28, 1);
        panelSetWork32(0x6d24, FUN_00207960(id));
    }
    bcmPanel00222d60();
}

// FUN_00203410 NONMATCHING
void FUN_00203410(void)
{
    u32 i;
    u32 count;
    u32 handle;
    const char* name;

    count = panelWork32(0x260);
    for (i = 0; i < panelWork32(0x25c); i++)
    {
        handle = *(u32*)(panelWork() + 0x8c + i * 4);
        if (handle != 0) func_003b0170(handle);
        *(u32*)(panelWork() + 0x8c + i * 4) = 0;
    }
    if (panelWork32(0) & 0x800000)
    {
        func_00208360();
    }
    func_003c7d60(5);
    for (i = 0; i < count && i < 4; i++)
    {
        if (i == panelWork32(0x7698) - panelWork32(0x7690))
        {
            name = func_00171110((s16)panelWork16(0x9c + i * 2), 0);
            handle = func_003b0970((u32)name, 2, 6, 0, 0);
        }
        else
        {
            name = func_00171110((s16)panelWork16(0x9c + i * 2), 0);
            handle = func_003b0970((u32)name, 2, 0, 0, 0);
        }
        *(u32*)(panelWork() + 0x8c + i * 4) = handle;
    }
    panelSetWork32(0x25c, count < 4 ? count : 4);
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

// FUN_00203C30 NONMATCHING
void FUN_00203C30(void)
{
    u32 i;
    u32 start;
    u32 count;
    PanelSkillRow* row;
    u32 index;

    K_ASSERT((panelWork32(0) & 8) != 0, 0xb07);
    FUN_00203DE0();
    start = panelWork32(0x76c4);
    count = panelWork32(0x2d8);
    for (i = 0; i < count && i < 4; i++)
    {
        index = start + i;
        row = panelItemRow(i);
        row->flags = 0;
        row->handle = *(u32*)(panelWork() + 0x2c8 + i * 4);
        row->type = 0;
        row->icon = *(u32*)(panelWork() + 0x26c + index * 8);
    }
    panelSetWork32(0x7640, 0);
    panelSetWork32(0x64a0, count);
    panelSetWork32(0x6498, panelWork32(0x76cc));
    panelSetWork32(0x649c, panelWork32(0x76c4));
    panelSetWork32(0x64a4, panelWork32(0x2dc));
    bcmPanel00224860();
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

// FUN_00204480 NONMATCHING
void FUN_00204480(void)
{
    u8* work;
    u8* itemBase;
    u8* srcRow;
    u8* dstRow;
    s32 i;
    s32 count;
    s32 found;
    s32 selected;
    s32 type;

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
            count = *(u32*)(work + 0x3a8);
            for (i = 0; i < count; i++)
            {
                srcRow = work + 0x2e0 + i * 0x18;
                type = *(u32*)(srcRow + 4);
                switch (type)
                {
                    case 1:
                        if (*(u16*)(srcRow + 0xc) == selected)
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
    i = 0;
    while (i < *(u32*)(work + 0x3ac))
    {
        srcRow = work + 0x2e0 + i * 0x18;
        dstRow = itemBase + i * 0x420;
        *(u32*)(dstRow + 0x410) = 0;
        type = *(u32*)(srcRow + 4);
        switch (type)
        {
            case 1:
                *(u32*)dstRow = 0;
                *(u32*)(dstRow + 8) =
                    *(u32*)(work + 0x370 + i * 8);
                *(u32*)(dstRow + 0xc) =
                    *(u32*)(work + 0x374 + i * 8);
                break;
            case 0:
                *(u32*)dstRow = 1;
                *(u32*)(dstRow + 8) =
                    *(u32*)(work + 0x370 + i * 8);
                break;
            case 2:
                *(u32*)dstRow = 2;
                *(u32*)(dstRow + 8) =
                    *(u32*)(work + 0x370 + i * 8);
                *(u32*)(dstRow + 0xc) =
                    *(u32*)(work + 0x374 + i * 8);
                if ((*(u32*)srcRow & 2) != 0)
                    *(u32*)(dstRow + 0x410) = 1;
                break;
            default:
                break;
        }
        i++;
    }
    count = *(u32*)(work + 0x3ac);
    *(u32*)(work + 0x7640) = count < 5 ? 0 : count - 4;
    *(u32*)(work + 0x64a0) = count;
    *(u32*)(work + 0x6498) = *(u32*)(work + 0x7700);
    *(u32*)(work + 0x649c) = *(u32*)(work + 0x76f8);
    *(u32*)(work + 0x64a4) = *(u32*)(work + 0x3a8);
    bcmPanel00222fa0();
    FUN_0010a4e0(0, 0, 0, 3);
    *(u32*)(work + 0x10) = 4;
}

// FUN_00204760 NONMATCHING
void FUN_00204760(void)
{
    u32 i;
    u32 count;
    u32 type;
    u32 alpha;
    u32 handle;
    u16 id;

    count = panelWork32(0x3ac);
    func_003b0e70(1);
    func_003b0e90(2);
    for (i = 0; i < count; i++)
    {
        type = panelWork32(0x2e4 + i * 0x18);
        alpha = i == panelWork32(0x7700) - panelWork32(0x76f8) ? 6 : 0;
        id = panelWork16(0x2ec + i * 0x18);
        if (type == 0)
        {
            handle = func_003b0970(0, 2, alpha, 0, 0);
            func_003b2c60(handle);
            func_003b0e20(handle, -1);
            *(u32*)(panelWork() + 0x370 + i * 8) = handle;
        }
        else if (type == 1)
        {
            handle = func_003b0970(func_00177790((s16)id), 2, alpha, 0, 0);
            func_003b2c60(handle);
            func_003b0e20(handle, -1);
            *(u32*)(panelWork() + 0x370 + i * 8) = handle;
            *(u32*)(panelWork() + 0x374 + i * 8) =
                func_003b0970(0, 2, alpha, 0, 0);
        }
        else
        {
            handle = func_003b0970(func_00177790(4), 2, alpha, 0, 0);
            func_003b2c60(handle);
            func_003b0e20(handle, -1);
            *(u32*)(panelWork() + 0x370 + i * 8) = handle;
            *(u32*)(panelWork() + 0x374 + i * 8) = 0;
        }
    }
    func_003b0e90(1);
    func_003b0e70(2);
    panelSetWork32(0, panelWork32(0) | 0x10);
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
                    FUN_001FF430(*(u32*)(row + 8)),
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
    u32 i;
    u32 start;
    u32 type;
    u32 handle;
    s32 color;
    PanelSkillRow* row;

    K_ASSERT((panelWork32(0) & 0x10) != 0, 0xd47);
    FUN_00205000();
    start = panelWork32(0x76f8);
    for (i = 0; i < panelWork32(0x3ac); i++)
    {
        row = panelItemRow(i);
        type = panelWork32(0x2e4 + (start + i) * 0x18);
        handle = *(u32*)(panelWork() + 0x370 + (start + i) * 8);
        color = (i == panelWork32(0x7700) ? 0xffffffff : 0x8080ffff);
        row->flags = type;
        row->handle = handle;
        switch (type)
        {
        case 0:
            row->type = 1;
            func_003b0d70(handle, 0x730, i * 0x48);
            func_003b0e20(handle, color);
            break;
        case 1:
            row->type = 0;
            func_003b0d70(handle, 0x730, i * 0x48);
            func_003b0e20(handle, color);
            break;
        case 2:
            row->type = 2;
            func_003b0d70(handle, 0x730, i * 0x48);
            func_003b0e20(handle, color);
            break;
        default:
            break;
        }
        row->icon = *(u32*)(panelWork() + 0x374 + (start + i) * 8);
    }
    panelSetWork32(0x64a0, panelWork32(0x3ac));
    panelSetWork32(0x6498, panelWork32(0x7700));
    panelSetWork32(0x649c, panelWork32(0x76f8));
    panelSetWork32(0x64a4, panelWork32(0x3a8));
    func_002230e0();
}

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
            handle = func_003b0970(*(u32*)0x00684f24, 2, alpha, 0, 0);
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
                ((u32*)0x00684efc)[*(u32*)(row + 0x10) - 1],
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
            handle = func_003b0970(*(u32*)0x00684f20, 2, alpha, 0, 0);
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
// FUN_002057C0 NONMATCHING
void FUN_002057C0(void)
{
    u8* work;
    u8* entry;
    u32 i;
    u32 count;
    u32 id;
    u32 handle;
    u32 type;
    u32 index;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    K_ASSERT((*(u32*)work & 0x1000) == 0, 0xe89);
    count = 0;
    for (id = 1; id < 0xb; id++)
    {
        switch (id)
        {
        case 1:
        case 7:
        case 9:
            break;
        case 2:
            if (datGetFlag(0x121b) != 0) continue;
            break;
        case 3:
            if (datGetFlag(0x121c) != 0) continue;
            break;
        case 4:
            if (datGetFlag(0x121d) != 0) continue;
            break;
        case 5:
            if (datGetFlag(0x121e) != 0) continue;
            break;
        case 6:
            if (datGetFlag(0x121a) != 0) continue;
            break;
        case 8:
            if (datGetFlag(0x121f) != 0) continue;
            break;
        case 10:
            entry = work + work[0x7700 / 4] * 0x18 + 0x2e0;
            type = *(u32*)(entry + 4);
            if (type == 2)
            {
                K_ASSERT(0, 0xec8);
                break;
            }
            if (type == 1)
            {
                if (*(u16*)(entry + 0xc) == 3)
                    continue;
                if (datGetScenarioMode() != 0 && *(u16*)(entry + 0xc) == 9)
                    continue;
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
        handle = func_003b0970(((u32*)0x00684efc)[id], 2, 0, 0, 0);
        func_003b0d70(handle, 0x1450, 0x8c0 + i * 0x90);
        func_003b2c60(handle, 0.0f);
        func_003b0e20(handle, -1);
        *(u32*)(work + 0x3d8 + i * 4) = handle;
    }
    *(u32*)(work + 0x77ac) = 0;
    entry = work + work[0x7700 / 4] * 0x18 + 0x2e0;
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
        handle = func_003b0970(*(u32*)0x007cc414, 2, 6, 0, 0);
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
    entry = work + work[0x7700 / 4] * 0x18 + 0x2e0;
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
        *(u32*)(work + 0x772c) = *(u32*)(work + 0x404) - index;
    else if (*(u32*)(work + 0x400) - 2 < index)
        *(u32*)(work + 0x772c) = index - (*(u32*)(work + 0x400) - 2);
    for (i = 0; i < *(u32*)(work + 0x400); i++)
    {
        u8* row = work + 0x4a90 + i * 0x420;
        *(u32*)(row + 0x410) = 0;
        *(u32*)(row + 0x414) = *(u32*)(work + 0x3d8 + i * 4);
    }
    *(u32*)(work + 0x64a0) = *(u32*)(work + 0x404);
    *(u32*)(work + 0x6498) = *(u32*)(work + 0x7700);
    *(u32*)(work + 0x649c) = *(u32*)(work + 0x76f8);
    *(u32*)(work + 0x64a4) = *(u32*)(work + 0x3a8);
    func_002230e0();
    func_002255f0();
    FUN_0010a4e0(0, 0, 0, 4);
    *(u32*)(work + 0x1c) = 2;
    printf("start command operation ----------+\n");
}

// FUN_00205D60 NONMATCHING
void FUN_00205D60(void)
{
    u8* work;
    u8* entry;
    u8* row;
    u32 i;
    u32 index;
    u32 count;
    u32 type;
    u32 handle;
    s32 color;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    for (i = 0; i < *(u32*)(work + 0x3ac); i++)
    {
        index = i + *(u32*)(work + 0x76f8);
        entry = work + index * 0x18 + 0x2e0;
        if (*(u32*)(work + 0x7700) != index)
        {
            if ((*work & 1) != 0 || (*work & 0x20000000) != 0)
                color = -1;
            else
                color = (s32)0x8080ffff;
        }
        else
        {
            color = -1;
        }
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
        row = work + 0x4a90 + i * 0x420;
        entry = work + i * 0x18 + 0x2e0;
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
            if (i + *(u32*)(work + 0x76f8) == 0)
                *(u32*)(work + 0x4a90 + 0x18e0) = *(u32*)(entry + 0x94);
        }
        else
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
    func_002255f0();
    FUN_0010a4e0(0, 0, 0, 4);
    *(u32*)(work + 0x1c) = 2;
}

// FUN_002060B0 NONMATCHING
void FUN_002060B0(void)
{
    u32 i;

    FUN_00206170();
    for (i = 0; i < panelWork32(0x6a0c); i++)
    {
        *(u32*)(panelWork() + 0x64b0 + i * 0x18) = 0;
        *(u32*)(panelWork() + 0x64b4 + i * 0x18) = 0;
    }
    panelSetWork32(0x6a00, panelWork32(0x404));
    panelSetWork32(0x6a04, panelWork32(0x7734));
    panelSetWork32(0x6a08, panelWork32(0x772c));
    panelSetWork32(0x6a0c, panelWork32(0x400));
    panelSetWork32(0x6d28, 0);
    func_00225670();
}

// FUN_00206170 NONMATCHING
void FUN_00206170(void)
{
    u32 i;
    u32 count;
    u32 handle;
    u32 id;

    count = panelWork32(0x404);
    for (i = 0; i < count; i++)
    {
        handle = *(u32*)(panelWork() + 0x3d8 + i * 4);
        if (handle != 0) func_003b0170(handle);
        *(u32*)(panelWork() + 0x3d8 + i * 4) = 0;
    }
    if (panelWork32(0) & 0x800000)
        func_00208360();
    handle = func_003a5540(100, 100, -1, 2, 6, NULL, 0);
    func_002082c0(handle);
    func_003b0e70(1);
    func_003b0e90(2);
    for (i = 0; i < count; i++)
    {
        id = panelWork32(0x3b0 + i * 4);
        handle = func_003b0970(id, 2, i == panelWork32(0x7734) ? 6 : 0, 0, 0);
        *(u32*)(panelWork() + 0x3d8 + i * 4) = handle;
    }
    func_003b0e90(1);
    func_003b0e70(2);
}

// FUN_00206310 NONMATCHING
void FUN_00206310(void)
{
    u32 i;

    K_ASSERT((panelWork32(0) & 0x1000) != 0, 0x105c);
    if (panelWork32(0x77a8) != 0)
        func_003b0170(panelWork32(0x77a8));
    if (panelWork32(0x77ac) != 0)
        func_003b0170(panelWork32(0x77ac));
    for (i = 0; i < panelWork32(0x404); i++)
    {
        if (*(u32*)(panelWork() + 0x3d8 + i * 4) != 0)
            func_003b0170(*(u32*)(panelWork() + 0x3d8 + i * 4));
    }
    panelSetWork32(0, panelWork32(0) & ~0x1000u);
}

// FUN_002063F0 NONMATCHING
void FUN_002063F0(void)
{
    u8* work;
    u8* row;
    u32 i;
    u32 index;
    u32 id;
    u32 type;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    index = *(u32*)(work + 0x7734);
    id = *(u32*)(work + 0x3b0 + index * 4);
    if (id == 7)
    {
        FUN_005225a8((const char*)0x684f48);
        FUN_0021B670(0);
        FUN_002085E0();
        *(u32*)(work + 0x1c) = 1;
    }
    else
    {
        row = work + *(u32*)(work + 0x7700) * 0x18 + 0x2e0;
        type = *(u32*)(row + 4);
        if (type == 2)
        {
            K_ASSERT(0, 0x104e);
        }
        else if (type == 1)
        {
            *(u32*)(row + 0x10) = id;
            *(u32*)row |= 1;
            FUN_00208860(*(u16*)(row + 0xc));
        }
        else if (type == 0)
        {
            for (i = 0; i < *(u32*)(work + 0x3a8); i++)
            {
                row = work + i * 0x18 + 0x2e0;
                if ((*(u32*)row & 2) == 0 && *(u32*)(row + 4) == 1)
                {
                    *(u32*)(row + 0x10) = id;
                    *(u32*)row |= 1;
                }
            }
            FUN_00208790();
        }
    }
    FUN_00205D60();
}

// FUN_002065A0 NONMATCHING
void FUN_002065A0(void)
{
    u8* work;
    u32 i;
    u32 index;
    u32 id;
    u32 type;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    index = *(u32*)(work + 0x7734);
    for (i = 0; i < *(u32*)(work + 0x404); i++)
    {
        id = *(u32*)(work + 0x3b0 + i * 4);
        type = panelDataType((u16)id);
        if (type == 0)
        {
            *(u32*)(work + 0x3b0 + i * 4) = id;
            *(u32*)(work + 0x414 + i * 4) = *(u32*)(work + 0x428);
            FUN_00208790();
        }
        else if (type == 1)
        {
            FUN_00208860((u16)id);
        }
    }
    *(u32*)(work + 0x7734) = index;
    FUN_00205D60();
}
// FUN_00206740 NONMATCHING
void FUN_00206740(void)
{
    u8* work;
    DatPersonaWork* persona;
    u16* skills;
    s32 i;
    u32 mode;
    s32 count;
    u32 type;
    s8 alpha;
    u32 handle;
    s32 value;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    K_ASSERT((*(u32*)work & 0x2000) != 0, 0x109f);
    K_ASSERT(*(u32*)(work + 0x20) != 2, 0x10a0);
    count = 0;
    for (mode = 0; mode < 3; mode++)
    {
        if (mode == 0)
        {
            *(u32*)(work + 0x408 + count * 4) = 0;
            count++;
        }
        else if (mode == 1)
        {
            *(u32*)(work + 0x408 + count * 4) = 1;
            count++;
        }
        else if (*(u32*)(work + 0x20) == 1)
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
                *(u32*)(work + 0x408 + count * 4) = 2;
                count++;
            }
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
    if (datGetFlag(0x186) != 0 && (value = FUN_0016F380(0x34)) != 0)
    {
        for (i = 0; i < *(u32*)(work + 0x420); i++)
        {
            if (*(u32*)(work + 0x408 + i * 4) == value)
                *(u32*)(work + 0x7768) = i;
        }
    }
    else
    {
        *(u32*)(work + 0x7768) = 0;
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
            handle = func_003b0970(*(u32*)0x007cc418,
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
        type = *(u32*)(work + 0x408 + i * 4);
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
        *(u32*)(row + 4) = *(u32*)(work + 0x414 + i * 4);
    }
    *(u32*)(work + 0x6a04) = *(u32*)(work + 0x7768);
    *(u32*)(work + 0x6a08) = 0;
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

// FUN_00207010 NONMATCHING
void FUN_00207010(void)
{
    u8* work;
    u32 i;
    u32 type;
    u32 alpha;
    u32 handle;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = gBcmWork;
    for (i = 0; i < *(u32*)(work + 0x424); i++)
    {
        handle = *(u32*)(work + 0x414 + i * 4);
        func_003b0170(handle);
        *(u32*)(work + 0x414 + i * 4) = 0;
    }
    if (*(u32*)work & 0x80)
        func_00208360();
    type = *(u32*)(work + 0x408 +
                   (*(u32*)(work + 0x7768) +
                    *(u32*)(work + 0x7760)) * 4);
    if (type == 2)
        alpha = 3;
    else if (type == 1)
        alpha = 1;
    else if (*(u32*)(work + 0x20) == 1)
        alpha = 1;
    else
        alpha = 0;
    handle = func_003a5540(100, 100, -1, 2, 6,
                           *(void**)(work + 0x7798), alpha);
    func_002082c0(handle);
    func_003b0e70(1);
    func_003b0e90(2);
    for (i = 0; i < *(u32*)(work + 0x424); i++)
    {
        alpha = i == *(u32*)(work + 0x7768) -
                       *(u32*)(work + 0x7760) ? 6 : 0;
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
            handle = func_003b0970(*(u32*)0x007cc418,
                                    2, alpha, 0, 0);
        }
        else
        {
            if (*(u32*)(work + 0x20) != 1)
                K_ASSERT(0, 0x1209);
            handle = func_003b0970(func_0030bb40(0x145),
                                    2, alpha, 0, 0);
        }
        *(u32*)(work + 0x414 + i * 4) = handle;
    }
    func_003b0e90(1);
    func_003b0e70(2);
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
            effect = bpMisc001ff740();
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
            effect = bpMisc001ff740();
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
            effect = bpMisc001ff740();
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

void func_0021bcb0(void);
void func_0024c110(void);
u32 bpRush0025d020(void);
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
void bpPersona00267180(void);
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

// FUN_001FD890 NONMATCHING
void* FUN_001fd890(KwlnTask* task)
{
    u32* work;
    u32* misc;
    u32 flags;

    work = (u32*)task->workData;
    func_0021bcb0();
    func_0024c110();
    bpRush0025d020();
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
    bpPersona00267180();
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

// FUN_001FDF10 NONMATCHING
void FUN_001FDF10(void* out)
{
    u32* work;
    u32 flags;
    u32 mode;
    u16 value;

    K_ASSERT(sBtlPanelTask != NULL, 0x164);
    work = (u32*)sBtlPanelTask->workData;
    flags = work[0];
    K_ASSERT((flags & 4) != 0, 0x1e9);
    *(u32*)out = 0;
    if (flags & 0x2000)
    {
        *(u32*)((u8*)out + 4) = 10;
        *(u32*)((u8*)out + 0x10) = work[4];
        return;
    }
    if (flags & 0x200)
    {
        *(u32*)((u8*)out + 4) = 4;
        mode = work[3];
        if (mode == 0)
        {
            *(u32*)out |= 1;
            *(u16*)((u8*)out + 0xA) = 0;
        }
        else if (mode == 1)
        {
            *(u32*)out |= 2;
            *(u16*)((u8*)out + 0xA) = 0x144;
        }
        else
        {
            K_ASSERT(0, 0x200);
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
    case 3:
        *(u32*)((u8*)out + 4) = 5;
        value = FUN_002055A0();
        *(u16*)((u8*)out + 0xC) = value;
        break;
    case 4:
        *(u32*)((u8*)out + 4) = 6;
        break;
    case 5:
        *(u32*)((u8*)out + 4) = 7;
        break;
    default:
        K_ASSERT(0, 0x229);
        break;
    }
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

#pragma push
#pragma opt_rebuildconditionals off
 
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
#pragma pop

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

#pragma push
#pragma opt_rebuildconditionals off
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
#pragma pop

#pragma push
#pragma opt_rebuildconditionals off
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
#pragma pop

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

// FUN_001FF430
u32 FUN_001FF430(u32 id)
{
    s32 i;
    u8* base;
    u8* node;

    base = DAT_007ce3ec;
    K_ASSERT(base != NULL, 0x2f);
    for (i = 0; i < 4; i++)
    {
        node = *(u8**)(base + 0x150 + i * 8);
        while (node != NULL)
        {
            if ((~*(u32*)(node + 0x9c) & 8) == 0 &&
                *(u32*)(node + 0xa8) == id)
            {
                return (u32)node;
            }
            node = *(u8**)(node + 0xa34);
        }
    }
    K_ASSERT(0, 0x3d);
    return 0;
}

// FUN_001FF630
u32 FUN_001FF630(u32 index)
{
    u8* base;
    u8* scan;
    u8* node;
    s32 count;

    base = DAT_007ce3ec;
    K_ASSERT(base != NULL, 0x88);
    scan = DAT_007ce3ec;
    K_ASSERT(scan != NULL, 0x5d);
    count = 0;
    node = *(u8**)(scan + 0x150);
    while (node != NULL)
    {
        if ((~*(u32*)(node + 0x9c) & 8) == 0)
        {
            count++;
        }
        node = *(u8**)(node + 0xa34);
    }
    count--;
    node = *(u8**)(base + 0x150);
    while (node != NULL)
    {
        if ((~*(u32*)(node + 0x9c) & 8) == 0)
        {
            if (count == index)
            {
                return *(u16*)(node + 0xa4);
            }
            count--;
        }
        node = *(u8**)(node + 0xa34);
    }
    K_ASSERT(0, 0x99);
    return 0;
}

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
void bpRush0025d6c0(void);
void bpRush0025d710(void);
void func_002083d0(void);

// W112BpRoot reconstruction: retail request-mask logging and state-transition paths recovered.
// FUN_001FF890 NONMATCHING
void FUN_001ff890(void)
{
    u32* work;
    u32 flags;
    void* message;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = (u32*)gBcmWork;
    if (*(u32*)((u8*)work + 0x77a0) & 1)
        FUN_005225a8((const char*)0x685058);
    else
        FUN_005225a8((const char*)0x685068);
    if (*(u32*)((u8*)work + 0x77a0) & 2)
        FUN_005225a8((const char*)0x685078);
    else
        FUN_005225a8((const char*)0x685088);
    if (*(u32*)((u8*)work + 0x77a0) & 4)
        FUN_005225a8((const char*)0x685098);
    else
        FUN_005225a8((const char*)0x6850a8);
    if (*(u32*)((u8*)work + 0x77a0) & 8)
        FUN_005225a8((const char*)0x6850b8);
    else
        FUN_005225a8((const char*)0x6850c8);
    if (*(u32*)((u8*)work + 0x77a0) & 0x10)
        FUN_005225a8((const char*)0x6850d8);
    else
        FUN_005225a8((const char*)0x6850e8);
    if (*(u32*)((u8*)work + 0x77a0) & 0x20)
        FUN_005225a8((const char*)0x6850f8);
    else
        FUN_005225a8((const char*)0x685108);
    if (*(u32*)((u8*)work + 0x77a0) & 0x40)
        FUN_005225a8((const char*)0x685120);
    else
        FUN_005225a8((const char*)0x685140);
    work[0] &= ~0x21u;
    work[0] &= ~2u;
    work[0] &= ~0x20000000u;
    work[0] &= ~0x02000000u;
    work[0] &= ~0x00040000u;
    work[0] &= ~0x80u;
    work[0] &= ~0x100u;
    work[0] &= ~0x200u;
    work[0] &= ~0x400u;
    work[1] = 0;
    work[3] = 0;
    if (datGetFlag(0x186))
    {
        work[0x24 / 4] = FUN_0016F380(0x30);
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
    bpRush0025d6c0();
}

// FUN_001FFC60 NONMATCHING
void FUN_001FFC60(void)
{
    u32* work;
    u8* record;
    u32 i;

    work = (u32*)panelWork();
    for (i = 0; i < work[0x3a8 / 4]; i++)
    {
        record = (u8*)work + 0x2e0 + i * 0x18;
        if ((*(u32*)record & 1) == 0 && *(u32*)(record + 4) == 1)
        {
            datSetAiTactic(*(s16*)(record + 0xc), *(s16*)(record + 0x10));
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
    if (*(u32*)work & 4) bcm00203360();
    if (*(u32*)work & 8) FUN_00203B70();
    if (*(u32*)work & 0x10) FUN_00204BE0();
    itfMesMngDestroyHandle(work[0x7790 / 4]);
    itfMesMngDestroyHandle(work[0x7794 / 4]);
    itfMesMngDestroyHandle(work[0x7798 / 4]);
    func_0021f3c0();
    bpRush0025d710();
}

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
void bpPersona00266f60(u32);
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
u32 bpPersona00267210(void);
void bpPersona00267120(void);
void bpPersona00267070(u32);

static inline u16 panelRootInputFlags(void)
{
    return *(u16*)0x007E094E;
}

static inline u16 panelRootTargetFlags(void)
{
    return *(u16*)0x007E0952;
}

// Retail state-3 persona selection also handles input-driven left/right
// navigation and invokes bpPersona00267070 before the transition effect.
// The state-1/2/4 branches use the same input flag register as retail;
// these paths are reconstructed directly even though MWCC lays out the
// resulting switch differently from the retail object.
// FUN_001FFF40 NONMATCHING
void FUN_001FFF40(void)
{
    u32* work;
    u32 flags;
    u32 panelFlags;
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
    panelFlags = work[1];
    if (flags & 0x08000000)
    {
        if (work[0x77a4 / 4] != 0)
            work[0x77a4 / 4]--;
    }
    if (flags & 0x10000000)
    {
        if (work[0x77a4 / 4] < 0x10)
            work[0x77a4 / 4]++;
    }
    *(f32*)((u8*)work + 0x7644) =
        (f32)(s32)work[0x77a4 / 4] / 16.0f;
    if ((panelFlags & 1) && !bcmPanel0022b4e0())
    {
        FUN_00202BC0();
        work[1] &= ~2u;
        panelFlags = work[1];
    }
    if ((panelFlags & 2) && !bcmPanel0022b4e0())
    {
        bcm00203360();
        work[1] &= ~3u;
        panelFlags = work[1];
    }
    if ((panelFlags & 4) && !bcmPanel0022b4e0())
    {
        FUN_00204BE0();
        work[1] &= ~5u;
        panelFlags = work[1];
    }

    state = work[4];
    switch (state)
    {
    case 0:
        if (!FUN_00201AF0() && !(flags & 0x40) && panelFlags == 0)
        {
            if ((*(u16*)0x007E094E) & 4)
            {
                if (!(work[3] & 4) || bpMisc001ff740() == 2)
                {
                    FUN_0010A4E0(0, 0, 0, 8);
                }
                else
                {
                    FUN_0021B670(1);
                    work[4] = 6;
                    work[6] = 1;
                    work[0] |= 0x80000000u;
                    FUN_0010A4E0(0, 0, 0, 3);
                }
            }
            else
            {
                if (func_002d1a70() == 0 && ((*(u16*)0x007E094E) & 0x10))
                {
                    work[0] |= 0x200000;
                    work[0] |= 0x20;
                }
                else if ((work[3] & 0x40) && ((*(u16*)0x007E094E) & 0x80))
                {
                    work[0] |= 0x400000;
                    work[0] |= 0x20;
                }
                else if ((*(u16*)0x007E094E) & 0x40)
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
                                bcm00201ad0();
                                printf("battle panel command accepted\n");
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
                                bcm00201ad0();
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
                                bcm00201ad0();
                                FUN_00202D70();
                                renderFlags |= 5;
                            }
                            break;
                        case 3:
                            if (!(work[3] & 4))
                            {
                                if (work[0] & 0x200)
                                {
                                    if (FUN_0016F190(0x1317) != 0)
                                        bpRoot001fea10(
                                            *(u32*)(DAT_007ce3ec + 0xba0), 0xd4);
                                    else
                                        bpRoot001fea10(
                                            *(u32*)(DAT_007ce3ec + 0xba0), 0xd3);
                                }
                            }
                            else
                            {
                                bcm00201ad0();
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
                                bcm00201ad0();
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
                                bcm00201ad0();
                                printf("battle panel command accepted\n");
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
                                bcm00201ad0();
                                printf("battle panel command accepted\n");
                                work[0] |= 0x20;
                            }
                            break;
                        default:
                            break;
                        }
                        FUN_0016F3E0(0x30, menu);
                    }
                }
                else
                {
                    K_ASSERT((flags & 2) == 0, 0x2b5);
                    if ((*(u16*)0x007E0952) & 0x20)
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
                            if (((*(u16*)0x007E0952) & 0x4000) ||
                                (*(u16*)0x007E095A & 0x4000) ||
                                ((*(u16*)0x007E0952) & 0x8000) ||
                                (*(u16*)0x007E095A & 0x8000))
                                effect = 1;
                            if (((*(u16*)0x007E0952) & 0x1000) ||
                                (*(u16*)0x007E095A & 0x1000) ||
                                ((*(u16*)0x007E0952) & 0x2000) ||
                                (*(u16*)0x007E095A & 0x2000))
                                value = 1;
                        }
                        else
                        {
                            if (((*(u16*)0x007E0952) & 0x4000) ||
                                (*(u16*)0x007E095A & 0x4000) ||
                                ((*(u16*)0x007E0952) & 0x2000) ||
                                (*(u16*)0x007E095A & 0x2000))
                                effect = 1;
                            if (((*(u16*)0x007E0952) & 0x1000) ||
                                (*(u16*)0x007E095A & 0x1000) ||
                                ((*(u16*)0x007E0952) & 0x8000) ||
                                (*(u16*)0x007E095A & 0x8000))
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
            if ((*(u16*)0x007E094E) & 0x20)
            {
                func_00208460();
                renderFlags |= 1;
            }
            else if ((*(u16*)0x007E094E) & 0x40)
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
            if ((*(u16*)0x007E094E) & 0x20)
            {
                func_00208460();
                renderFlags |= 1;
            }
            else if ((*(u16*)0x007E094E) & 0x40)
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
                if ((*(u16*)0x007E094E) & 0x20)
                {
                    FUN_00204AF0();
                    func_00208460();
                    renderFlags |= 1;
                }
                else if ((*(u16*)0x007E094E) & 0x80)
                {
                    bpPersona00266f60(
                        *(u16*)((u8*)work + 0x268 + work[0x76cc / 4] * 8));
                    FUN_002085E0();
                    FUN_0020FC40();
                    work[5] = 1;
                    FUN_0010A4E0(0, 0, 0, 1);
                }
                else if ((*(u16*)0x007E094E) & 0x40)
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
            if (!FUN_00201AF0() && !bpPersona00267210())
            {
                if ((*(u16*)0x007E094E) & 0x20)
                {
                    bpPersona00267120();
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
                else if ((*(u16*)0x007E094E) & 0x40)
                {
                    persona = datPersonaGetByPcId(1);
                    entry = (u8*)work + 0x268 + work[0x76cc / 4] * 8;
                    if (*(u16*)entry != *(u16*)((u8*)persona + 2))
                    {
                        bpPersona00267120();
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
                    if (value >= 2 && ((*(u16*)0x007E0952) & 8))
                    {
                        menu = work[0x76cc / 4];
                        if (menu < value - 1)
                            work[0x76cc / 4] = menu + 1;
                        else
                            work[0x76cc / 4] = 0;
                        bpPersona00267070(
                            *(u16*)((u8*)work + 0x268 +
                                    work[0x76cc / 4] * 8));
                        FUN_0010A4E0(0, 0, 0, 8);
                    }
                    else if ((*(u16*)0x007E0952) & 4)
                    {
                        menu = work[0x76cc / 4];
                        if (menu != 0)
                            work[0x76cc / 4] = menu - 1;
                        else
                            work[0x76cc / 4] = value - 1;
                        bpPersona00267070(
                            *(u16*)((u8*)work + 0x268 +
                                    work[0x76cc / 4] * 8));
                        FUN_0010A4E0(0, 0, 0, 8);
                    }
                }
            }
        }
        break;
    case 4:
        if (!FUN_00201AF0() && !(flags & 0x40) && panelFlags == 0)
        {
            if ((*(u16*)0x007E094E) & 0x40)
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
                FUN_0016F3E0(0x33, value);
            }
            else if ((*(u16*)0x007E094E) & 0x20)
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
        if (!FUN_00201AF0() && !(flags & 0x40) && panelFlags == 0)
        {
            substate = work[7];
            if (substate == 0)
            {
                if ((*(u16*)0x007E0952) & 0x20)
                {
                    FUN_00205D60();
                    renderFlags |= 1;
                }
                else if ((*(u16*)0x007E0952) & 0x40)
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
            if ((*(u16*)0x007E0952) & 0x20)
            {
                func_003c77a0();
                FUN_00206E40();
                renderFlags |= 1;
            }
            else if ((*(u16*)0x007E0952) & 0x40)
            {
                func_003c77a0();
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
                        FUN_005225a8((const char*)0x685050,
                                     *(u16*)(entry + 2));
                        FUN_005225a8((const char*)0x685060);
                        func_0024a6e0(work[0x7654 / 4]);
                        work[0] &= ~0x4001u;
                        work[6] = 2;
                    }
                    else
                    {
                        FUN_005225a8((const char*)0x685050,
                                     *(u16*)(entry + 2));
                        FUN_005225a8((const char*)0x685070);
                        work[0] |= 0x4000;
                        work[0] &= ~0x20001u;
                        func_002dbac0();
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
                func_003c7430(FUN_002D5550() == 0x1a1 ? 8 : 5);
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
