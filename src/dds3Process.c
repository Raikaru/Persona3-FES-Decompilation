#include "dds3Process.h"

// FUN_0035ad80.
// 'unused1' and 'unused2' were probably 'runningDelay' and 'destroyDelay',
// but instead of using 'kwlnTaskInitEx' they used the normal one for some reason
KwlnTask* dds3InitProcess(const char* name,
                          u32 priority,
                          s32 unused1,
                          s32 unused2,
                          KwlnTaskUpdateFunc update,
                          KwlnTaskDestroyFunc destroy,
                          void* workData)
{
    return kwlnTaskInit(name, priority, update, destroy, workData);
}

// FUN_0035adb0
void dds3KillProcess(KwlnTask* task, s32 unused)
{
    kwlnTaskDestroyWithHierarchy(task);
}

// FUN_0035add0
u32 dds3ProcessExists(KwlnTask* task)
{
    return kwlnTaskExists(task);
}

// FUN_0035adf0
u32 dds3GetProcessTimer(KwlnTask* task)
{
    return kwlnTaskGetTimer(task);
}

// FUN_0035ae10
void* dds3GetProcessWorkData(KwlnTask* task)
{
    return kwlnTaskGetWorkData(task);
}

// FUN_0035ae30
void dds3SetProcessWorkData(KwlnTask* task, void* workData)
{
    kwlnTaskSetWorkData(task, workData);
}


/* ---- Recovered range 0x35AE50-0x35AFA0 (Ghidra reference, pending match) ---- */
#include "Script/scrTraceCode.h"
#include "Kosaka/k_assert.h"
extern void scrSetIntReturnVal(s32 value);
extern s32 FUN_003951d0(s32 value);
extern void FUN_00395170(u32 value);
extern void FUN_003951a0(u32 value);

// FUN_0035AE50


void FUN_0035ae50(void)



{

  return;

}

// FUN_0035AE60


void FUN_0035ae60(void)



{

  return;

}

// FUN_0035AE70


void FUN_0035ae70(void)



{

  return;

}

// FUN_0035AE80


void FUN_0035ae80(void)



{

  return;

}

// FUN_0035AE90


u64 FUN_0035ae90(void)



{

  return 0;

}

// FUN_0035AEA0


u64 FUN_0035aea0(void)



{

  return 0;

}

// FUN_0035AEB0


u32 FUN_0035aeb0(void)



{

  s32 uVar1;

  

  uVar1 = scrGetIntPara(0);

  uVar1 = FUN_003951d0(uVar1);

  scrSetIntReturnVal(uVar1);

  return 1;

}

// FUN_0035AEF0


u32 FUN_0035aef0(void)



{

  u32 uVar1;

  

  uVar1 = scrGetIntPara(0);

  K_ASSERT(uVar1 < 0x1600, 0x75);

  FUN_00395170(uVar1);

  return 1;

}

// FUN_0035AF50


u32 FUN_0035af50(void)



{

  u32 uVar1;

  

  uVar1 = scrGetIntPara(0);

  K_ASSERT(uVar1 < 0x1600, 0x84);

  FUN_003951a0(uVar1);

  return 1;

}
