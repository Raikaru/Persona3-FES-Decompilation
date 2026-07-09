#include "Kernel/Kwln/kwlnRoot.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwln.h"
#include "rw/rwcore.h"
#include "temporary.h"
#include "h_snd.h"
#include "h_fade.h"
#include "h_dbprt.h"
#include "Kosaka/Field/k_sceneDraw.h"
#include "Main/Game/gm_root.h"

KwlnTask* kwlnRootCreate2DDrawBeginTask();
KwlnTask* kwlnRootCreate2DDrawBeginPreEndTask();
KwlnTask* kwlnRootCreate2DDrawEndTask();
KwlnTask* kwlnRootCreate3DOn2DZClearTask();
KwlnTask* kwlnRootCreate3DOn2DDrawBeginTask();
KwlnTask* kwlnRootCreate3DOn2DDrawEndTask();
KwlnTask* kwlnRootCreateEtcDrawTask();
void FUN_00103580();
u32 H_Snd_FUN_00109df0(s32 param);
KwlnTask* FUN_00199440(KwlnTask* rootTask);
KwlnTask* FUN_001993d0();
KwlnTask* FUN_00199080();
KwlnTask* FUN_00199100();
KwlnTask* FUN_00199360();
KwlnTask* FUN_00192de0();
void kwlnInitGameData();
extern u32 DAT_007ce12c;
extern u32 DAT_007ce114;
void FUN_001120c0();
void FUN_001125d0();

// FUN_00198650
void* kwlnRootUpdateTask(KwlnTask* rootTask)
{
    KwlnRootWork* work;
    KwlnTask* task;

    work = rootTask->workData;
    switch (work->state)
    {
        case 0:
            FUN_00103580();
            if (H_Snd_FUN_00109df0(0) != 0)
            {
                K_SceneDraw_CreateTasks(rootTask);
                FUN_00199440(rootTask);
                task = kwlnRootCreate2DDrawBeginTask();
                kwlnTaskAddChild(rootTask, task);
                task = kwlnRootCreate2DDrawBeginPreEndTask();
                kwlnTaskAddChild(rootTask, task);
                task = kwlnRootCreate2DDrawEndTask();
                kwlnTaskAddChild(rootTask, task);
                task = kwlnRootCreate3DOn2DZClearTask();
                kwlnTaskAddChild(rootTask, task);
                task = kwlnRootCreate3DOn2DDrawBeginTask();
                kwlnTaskAddChild(rootTask, task);
                task = kwlnRootCreate3DOn2DDrawEndTask();
                kwlnTaskAddChild(rootTask, task);
                task = FUN_001993d0();
                kwlnTaskAddChild(rootTask, task);
                task = FUN_00199080();
                kwlnTaskAddChild(rootTask, task);
                task = kwlnRootCreateEtcDrawTask();
                kwlnTaskAddChild(rootTask, task);
                task = FUN_00199100();
                kwlnTaskAddChild(rootTask, task);
                task = FUN_00199360();
                kwlnTaskAddChild(rootTask, task);
                work->state++;
            }
            break;
        case 1:
            FUN_00103580();
            DAT_007ce12c = 0;
            work->state++;
            break;
        case 2:
            if (work->unk_04 == 0)
            {
                kwlnSetFlags(0x80000000, 0);
                DAT_007ce114 = 1;
                gmRootCreateTask(rootTask);
            }
            work->state = 3;
            break;
        case 3:
            if (work->unk_04 != 0 && kwlnTaskExists((KwlnTask*)work->unk_04) == 0)
            {
                work->unk_04 = 0;
                work->state = 2;
            }
            break;
        case 4:
            return KWLNTASK_STOP;
        case 5:
            kwlnSetFlags(0x80000000, 0);
            work->unk_04 = (u32)FUN_00192de0();
            work->state = 6;
            break;
        case 6:
            if (kwlnTaskExists((KwlnTask*)work->unk_04) == 0)
            {
                kwlnInitGameData();
                work->unk_04 = 0;
                work->state = 2;
            }
            break;
    }

    return KWLNTASK_CONTINUE;
}

void H_Snd_StopBgm();
void FUN_003b5ab0();

// FUN_001988f0
void kwlnRootDestroyTask(KwlnTask* rootTask)
{
    H_Snd_StopBgm();
    FUN_003b5ab0();

    RwFree(rootTask->workData);
}

// FUN_00198940
KwlnTask* kwlnRootCreateTask()
{
    KwlnTask* rootTask;
    KwlnRootWork* work;

    work = RwCalloc(1, sizeof(KwlnRootWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    rootTask = kwlnTaskInit("rootProc", 0, kwlnRootUpdateTask, kwlnRootDestroyTask, work);
    H_Snd_FUN_00109ca0(0, 1);
    H_Snd_FUN_00109ca0(1, 2);

    return rootTask;
}

// FUN_001989e0
void* kwlnRootUpdate2DDrawBeginTask(KwlnTask* drawBegin2dTask)
{
    RwRenderStateSetFunc* setRenderState;

    RwCameraClear(kwlnGetMainCamera(), kwlnGetClearColor(), rwCAMERACLEARZ);
    if (kwlnCameraBeginUpdate() != NULL)
    {
        kwlnSetFlags(KWLN_FLAG_ERR | KWLN_FLAG_3DDRAW, false);
        kwlnSetFlags(KWLN_FLAG_2DDRAW, true);
        setRenderState = &rwGlobals.device.setRenderState;
        (*setRenderState)(rwRENDERSTATEZTESTENABLE, (void*)true);
        (*setRenderState)(rwRENDERSTATEZWRITEENABLE, (void*)true);
        RpSkyRenderStateSet(2, (void*)0x44);
        RpSkyRenderStateSet(3, (void*)0x717fb);
        (*setRenderState)(rwRENDERSTATEFOGENABLE, (void*)false);
        FUN_001120c0();
        FUN_001125d0();
    }
    else
    {
        K_ASSERT(false, 393);
        kwlnSetFlags(KWLN_FLAG_ERR, true);
    }

    return KWLNTASK_CONTINUE;
}

// FUN_00198b10
void* kwlnRootUpdate2DDrawPreEndTask(KwlnTask* drawBegin2dPETask)
{
    return KWLNTASK_CONTINUE;
}

// FUN_00198b20
void* kwlnRootUpdate2DDrawEndTask(KwlnTask* drawEnd2dTask)
{
    kwlnCameraEndUpdate();

    return KWLNTASK_CONTINUE;
}

// FUN_00198b50
KwlnTask* kwlnRootCreate2DDrawBeginTask()
{
    return kwlnTaskInit("2D Draw Begin", 4196, kwlnRootUpdate2DDrawBeginTask, NULL, NULL);
}

// FUN_00198b90
KwlnTask* kwlnRootCreate2DDrawBeginPreEndTask()
{
    return kwlnTaskInit("2D Draw Begin Pre End", 5231, kwlnRootUpdate2DDrawPreEndTask, NULL, NULL);
}

// FUN_00198bd0
KwlnTask* kwlnRootCreate2DDrawEndTask()
{
    return kwlnTaskInit("2D Draw End", 5241, kwlnRootUpdate2DDrawEndTask, NULL, NULL);
}

// FUN_00198c10
void* kwlnRootUpdate3DOn2DZClearTask(KwlnTask* zclear2D3DTask)
{
    RwCameraClear(kwlnGetMainCamera(), kwlnGetClearColor(), rwCAMERACLEARZ);

    return KWLNTASK_CONTINUE;
}

// FUN_00198c60
void* kwlnRootUpdate3DOn2DDrawBeginTask()
{
    RwRenderStateSetFunc* setRenderState;

    if (kwlnCameraBeginUpdate() != NULL)
    {
        kwlnSetFlags(KWLN_FLAG_ERR | KWLN_FLAG_3DDRAW, false);
        kwlnSetFlags(KWLN_FLAG_3DDRAW, true);

        setRenderState = &rwGlobals.device.setRenderState;

        (*setRenderState)(rwRENDERSTATEZTESTENABLE, (void*)true);
        (*setRenderState)(rwRENDERSTATEZWRITEENABLE, (void*)true);
    }
    else
    {
        K_ASSERT(false, 719);
        kwlnSetFlags(KWLN_FLAG_ERR, true);
    }

    return KWLNTASK_CONTINUE;
}

// FUN_00198d20
void* kwlnRootUpdate3DOn2DDrawEndTask(KwlnTask* drawEnd3d2dTask)
{
    RwRenderStateSetFunc* setRenderState;

    if (gFogEnabled == true)
    {
        setRenderState = &rwGlobals.device.setRenderState;

        (*setRenderState)(rwRENDERSTATEFOGENABLE, (void*)true);
        (*setRenderState)(rwRENDERSTATEFOGCOLOR, (void*)PACK_RWRGBA(gFogRed, gFogGreen, gFogBlue, gFogAlpha));
        (*setRenderState)(rwRENDERSTATEFOGTYPE, (void*)rwFOGTYPELINEAR);
    }

    kwlnCameraEndUpdate();

    return KWLNTASK_CONTINUE;
}

// FUN_00198dd0
KwlnTask* kwlnRootCreate3DOn2DZClearTask()
{
    return kwlnTaskInit("3D on 2D Zclear", 5243, kwlnRootUpdate3DOn2DZClearTask, NULL, NULL);
}

// FUN_00198e10
KwlnTask* kwlnRootCreate3DOn2DDrawBeginTask()
{
    return kwlnTaskInit("3D on 2D Draw Begin", 5245, kwlnRootUpdate3DOn2DDrawBeginTask, NULL, NULL);
}

// FUN_00198e50
KwlnTask* kwlnRootCreate3DOn2DDrawEndTask()
{
    return kwlnTaskInit("3D on 2D Draw End", 6320, kwlnRootUpdate3DOn2DDrawEndTask, NULL, NULL);
}

// FUN_00198f90
void* kwlnRootUpdateEtcDrawTask(KwlnTask* etcDrawTask)
{
    H_Fade_Main();

    H_Dbprt_Main();
    H_Dbprt_Flush();

    return KWLNTASK_CONTINUE;
}

// FUN_001990c0
KwlnTask* kwlnRootCreateEtcDrawTask()
{
    return kwlnTaskInit("etc Draw", 6335, kwlnRootUpdateEtcDrawTask, NULL, NULL);
}