#include "Main/Battle/Panel/bp_root.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"

void FUN_0025d760();

static KwlnTask* sBtlPanelTask; // 007ce2e4

// FUN_001fd630
KwlnTask* bpRootCreateTasks(KwlnTask* parent)
{
    // TODO

    return NULL;
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
void FUN_0024a6d0();
void FUN_00249250();
void FUN_00242c60();
void FUN_0023f500();
void FUN_00208b20();
void FUN_00201780();
void FUN_0020edc0();
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
    FUN_0024a6d0();
    FUN_00249250();
    FUN_00242c60();
    FUN_0023f500();
    FUN_00208b20();
    FUN_00201780();
    FUN_0020edc0();
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

void FUN_001ff890();

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
void FUN_0020fc40();
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
        FUN_0020fc40();
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

void FUN_0024a7a0();

// FUN_001fe4a0
void bpRoot001fe4a0()
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    K_ASSERT(*flags & 0x2000, 0x2a8);
    *flags &= ~0x2000;
    FUN_0024a7a0();
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

// FUN_001fe580
void bpRoot001fe580(u32 param_1)
{
    u32* flags;

    flags = sBtlPanelTask->workData;
    K_ASSERT(*flags & 4, 0x2ba);
    *flags |= 0x2000;
    flags[4] = param_1;
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
void FUN_0020fc90();
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
        FUN_0020fc90();
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

void FUN_0020f3b0();

// FUN_001fdd20
void bpRoot001fdd20()
{
    FUN_0020f3b0();
}

void FUN_0020f570();

// FUN_001fdd40
void bpRoot001fdd40()
{
    FUN_0020f570();
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

void FUN_0024d0c0();

// FUN_001fecc0
void bpRoot001fecc0()
{
    FUN_0024d0c0();
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

void FUN_0020f9a0();

// FUN_001feea0
void bpRoot001feea0()
{
    FUN_0020f9a0();
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