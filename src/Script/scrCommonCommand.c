#include "Script/scrCommonCommand.h"
#include "Script/scrTraceCode.h"
#include "Script/scrScriptProcess.h"
#include "Script/scr.h"
#include "Kosaka/k_command.h"
#include "Kosaka/k_assert.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rprandom.h"
#include "datCalendar.h"
#include "temporary.h"
#include "dds3Process.h"

#pragma alias scrSetIntReturnVal_y2 scrSetIntReturnVal

#pragma alias scrCommand_GET_TRIGGERED_BUTTONS FUN_0035B1B0
#pragma alias scrCommand_GET_HELD_BUTTONS FUN_0035B1F0
#pragma alias scrCommand_NOOP3 FUN_0035B230
#pragma alias scrCommand_NOOP FUN_0035B270


u32 scrCommand_RAND();
u32 scrCommand_SYNC();
u32 scrCommand_WAIT();
u32 scrCommand_PUT();
u32 scrCommand_PUTSTR();
u32 scrCommand_SWITCH();
u32 scrCommand_SCR_RUN();
u32 scrCommand_SCR_KILL();
u32 scrCommand_SCR_KILL_SYNC();
u32 scrCommand_SCR_EXISTS();
u32 scrCommand_SCR_GET_TIMER();
u32 scrCommand_SQRT();

// 007b92b0
ScrCommandTable gScrCmdTable =
{
    // cmds. TODO
    {
        { NULL, 0 },
    },

    // count
    ARRAY_SIZE(gScrCmdTable.cmds)
};

// FUN_0035afb0
u32 scrCommand_RAND()
{
    scrSetIntReturnVal(RpRandom() % (scrGetIntPara(0) + 1));

    return true;
}

// FUN_0035b000
u32 scrCommand_SYNC()
{
    return scrGetCmdTimer() != 0;
}

// FUN_0035b030
u32 scrCommand_WAIT()
{
    s32 cmdTimer;

    if (scrGetIntPara(0) < 1)
    {
        return true;
    }

    cmdTimer = scrGetCmdTimer();

    return scrGetIntPara(0) <= cmdTimer;
}

// FUN_0035b090
u32 scrCommand_PUT()
{
    s32 param;

    param = scrGetIntPara(0);
    printf("PUT -> %d\n", param);

    return true;
}

// FUN_0035b0d0
u32 scrCommand_PUTSTR()
{
    char* param;

    param = scrGetStrPara(0);
    printf("PUTSTR -> %s\n", param);

    return true;
}

// FUN_0035b110
u32 scrCommand_SWITCH()
{
    s32 caseIdx;
    s32 lblIdx;

    caseIdx = scrGetIntPara(0);
    if (caseIdx < 0)
    {
        return true;
    }

    K_ASSERT(caseIdx <= 6, 342);

    lblIdx = scrGetIntPara(caseIdx + 1);
    if (lblIdx < 0)
    {
        return true;
    }

    scrSetPC(scrGetLabelAddr(lblIdx));

    return true;
}

// FUN_0035b280
u32 scrCommand_SCR_RUN()
{
    s32 prcdIdx;
    u32 priority;
    ScrData* scr;
    ScrContentEntry* entries;
    KwlnTask* task;

    prcdIdx = scrGetIntPara(0);

    scr = scrGetCurrent();
    if (scr == NULL)
    {
        return true;
    }

    if (scr->task == NULL)
    {
        printf("warning %s %d  ※警告:SCR_RUN()このコマンドはプロセス型スクリプトでのみ有効です。\n", 
               "scrCommonCommand.c",
               459);
    
        return true;
    }

    if (prcdIdx < 0 ||
        prcdIdx >= (entries = scr->entries, entries[SCR_CONTENT_TYPE_PROCEDURE].elementCount))
    {
        return true;
    }

    priority = scr->task->priority + scrGetIntPara(1);

    task = scrCreateTask(priority,
                         scr->scrHeader,
                         entries,
                         scr->proceduresContent,
                         scr->labelsContent,
                         scr->instrContent,
                         scr->msgContentHeader,
                         scr->stringsContent,
                         prcdIdx);

    scrSetIntReturnVal((s32)task);

    return true;
}

// FUN_0035b390
u32 scrCommand_SCR_KILL()
{
    KwlnTask* task;

    task = (KwlnTask*)scrGetIntPara(0);

    if (!dds3ProcessExists(task))
    {
        return true;
    }

    dds3KillProcess(task, 1);

    return true;
}

// FUN_0035b400
u32 scrCommand_SCR_KILL_SYNC()
{
    KwlnTask* task;

    task = (KwlnTask*)scrGetIntPara(0);

    return dds3ProcessExists(task) == false;
}

// FUN_0035b440
u32 scrCommand_SCR_EXISTS()
{
    KwlnTask* task;

    task = (KwlnTask*)scrGetIntPara(0);

    if (dds3ProcessExists(task))
    {
        scrSetIntReturnVal(true);
    }
    else
    {
        scrSetIntReturnVal(false);
    }

    return true;
}

// FUN_0035b4a0
u32 scrCommand_SCR_GET_TIMER()
{
    KwlnTask* task;

    task = (KwlnTask*)scrGetIntPara(0);

    if (!dds3ProcessExists(task))
    {
        scrSetIntReturnVal(false);
    }
    else
    {
        scrSetIntReturnVal(dds3GetProcessTimer(task));
    }

    return true;
}

// FUN_0035b520
u32 scrCommand_SQRT()
{
    f32 param;

    param = scrGetFloatPara(0);

    scrSetFloatReturnVal(sqrtf(param));
    // BUG: no return
}


// FUN_0035B1B0
u32 scrCommand_GET_TRIGGERED_BUTTONS(void)
{
    scrSetIntReturnVal(*(u16*)0x007e094e & scrGetIntPara(0));

    return true;
}

// FUN_0035B1F0
u32 scrCommand_GET_HELD_BUTTONS(void)
{
    scrSetIntReturnVal(*(u16*)0x007e094c & scrGetIntPara(0));

    return true;
}

// FUN_0035B230


u32 scrCommand_NOOP3(void)



{

  scrGetIntPara(0);

  scrGetIntPara(1);

  scrGetIntPara(2);

  return 1;

}

// FUN_0035B270
u32 scrCommand_NOOP(void)
{
  return 1;
}



#pragma alias scrCommand_RESOURCE_LOADED FUN_0035AEB0
#pragma alias scrCommand_LOAD_RESOURCE FUN_0035AEF0
#pragma alias scrCommand_UNLOAD_RESOURCE FUN_0035AF50
#pragma alias scrGetResourceFlag FUN_003951d0
#pragma alias scrSetResourceFlag FUN_00395170
#pragma alias scrClearResourceFlag FUN_003951a0

// 'unused1' and 'unused2' were probably 'runningDelay' and 'destroyDelay',
// but instead of using 'kwlnTaskInitEx' they used the normal one for some reason







/* ---- Recovered range 0x35AE50-0x35AFA0 (Ghidra reference, pending match) ---- */
extern void scrSetIntReturnVal_y2(s32 value);
extern s32 scrGetResourceFlag(s32 value);
extern void scrSetResourceFlag(u32 value);
extern void scrClearResourceFlag(u32 value);







// FUN_0035AEB0


u32 scrCommand_RESOURCE_LOADED(void)



{

  s32 uVar1;

  

  uVar1 = scrGetIntPara(0);

  uVar1 = scrGetResourceFlag(uVar1);

  scrSetIntReturnVal_y2(uVar1);

  return 1;

}

// FUN_0035AEF0


u32 scrCommand_LOAD_RESOURCE(void)



{

  u32 uVar1;

  

  uVar1 = scrGetIntPara(0);

  K_ASSERT(uVar1 < 0x1600, 0x75);

  scrSetResourceFlag(uVar1);

  return 1;

}

// FUN_0035AF50


u32 scrCommand_UNLOAD_RESOURCE(void)



{

  u32 uVar1;

  

  uVar1 = scrGetIntPara(0);

  K_ASSERT(uVar1 < 0x1600, 0x84);

  scrClearResourceFlag(uVar1);

  return 1;

}
