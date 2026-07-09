#include "Main/Battle/Panel/bp_root.h"
#include "Kernel/Kwln/kwlnTask.h"

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

// FUN_001fdc00
void bpRootDestroy(KwlnTask* btlPanelTask)
{
    // TODO
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