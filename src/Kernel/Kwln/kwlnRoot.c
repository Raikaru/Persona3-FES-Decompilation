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
#include "h_chrdsp.h"
#include "Yajima/y_misc.h"
#include "Kosaka/k_spipe.h"
#include "rw/rprandom.h"
#include "sce/eeregs.h"

KwlnTask* kwlnRootCreate2DDrawBeginTask();
KwlnTask* kwlnRootCreate2DDrawBeginPreEndTask();
KwlnTask* kwlnRootCreate2DDrawEndTask();
KwlnTask* kwlnRootCreate3DOn2DZClearTask();
KwlnTask* kwlnRootCreate3DOn2DDrawBeginTask();
KwlnTask* kwlnRootCreate3DOn2DDrawEndTask();
KwlnTask* kwlnRootCreateEtcDrawTask();
void H_Pad_Update();
u32 H_Snd_FUN_00109df0(s32 param);
KwlnTask* FUN_00199440(KwlnTask* rootTask);
KwlnTask* FUN_001993d0();
KwlnTask* FUN_00199080();
KwlnTask* FUN_00199100();
KwlnTask* FUN_00199360();
KwlnTask* func_00192de0();
void kwlnInitGameData();
extern u32 DAT_007ce12c;
extern u32 DAT_007ce114;
void func_001120c0();
void func_001125d0();
extern RwGlobals DAT_00960070;

extern u32 jtbl_00960178[];
extern u32 jtbl_0096017C[];
extern u32 D_00960184[];
#define KWLN_ALLOC2(size, flags) (*(void* (**)(u32, u32))jtbl_00960178)((size), (flags))
#define KWLN_FREE(memory) (*(void (**)(void*))jtbl_0096017C)(memory)
#define KWLN_ALLOC3(count, size, flags) (*(void* (**)(u32, u32, u32))D_00960184)((count), (size), (flags))
void* func_004c9ed0(RwCamera* camera, u32 param_2, u32 param_3);
int func_004c4d20(void);
void* func_004ce200(RwRaster* raster, u32 param2, s32 param3);
void* func_004cbf20(void* image);
void* func_004cdc70(void* image, RwRaster* raster);
void* func_004cde00(RwRaster* raster);
void func_004c7cf0(s32 value);
void func_0010bff0(void);
void func_0010c5f0(void);
void func_005810f0(void);

extern f32 D_007CE150;
extern f32 D_007CE14C;
extern f32 D_007CE148;
extern KwlnTask* D_007CE134;
extern u32 D_007CE130;
extern u32 D_007CE11C;
extern u32 D_007CE118;
extern u32 D_007CE110;
extern void* D_007CE104;
extern u32 D_007CE100;
extern u32 D_007CE0F8;
extern const char D_006787C8[]; // "rootProc"
extern const char D_006787D8[]; // "kwlnRoot.c"
extern const char D_006787E8[]; // "2D Draw Begin"
extern const char D_00678800[]; // "2D Draw Begin Pre End"
extern const char D_00678810[]; // "2D Draw End"
extern const char D_00678820[]; // "3D on 2D Zclear"
extern const char D_00678830[]; // "3D on 2D Draw Begin"
extern const char D_00678850[]; // "3D on 2D Draw End"
extern const char D_00678868[]; // "etc Draw Begin"
extern const char D_00678878[]; // "etc Draw"
extern const char D_00678888[]; // "etc Draw End"
extern const char D_006788A0[]; // "<<< show raster >>>"
extern const char D_006788B8[]; // "drawBustupProc"
extern const char D_006788C8[]; // "k_spipe.c"
#define sShowRasterPercent D_007CE150
#define sShowRasterDelta D_007CE14C
#define sShowRasterCurrent D_007CE148
#define sDraw3DTask D_007CE134
#define sShowRasterEnabled D_007CE130
#define sShowRasterRasterB D_007CE11C
#define sShowRasterRasterA D_007CE118
#define sShowRasterResult D_007CE110
#define sShowRasterImage D_007CE104
#define sShowRasterCurrentCount D_007CE100
#define sShowRasterUpdatePending D_007CE0F8

// FUN_00198650
void* kwlnRootUpdateTask(KwlnTask* rootTask)
{
    KwlnRootWork* work;
    KwlnTask* task;

    work = rootTask->workData;
    switch (work->state)
    {
        case 0:
            H_Pad_Update();
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
            H_Pad_Update();
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
            work->unk_04 = (u32)func_00192de0();
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
void func_003b5ab0();

// FUN_001988f0
void kwlnRootDestroyTask(KwlnTask* rootTask)
{
    H_Snd_StopBgm();
    func_003b5ab0();

    (DAT_00960070.memFuncs.RwFree)(rootTask->workData);
}

// FUN_00198940
KwlnTask* kwlnRootCreateTask()
{
    KwlnTask* rootTask;
    KwlnRootWork* work;

    work = (DAT_00960070.memFuncs.RwCalloc)(1, sizeof(KwlnRootWork), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    rootTask = kwlnTaskInit(D_006787C8, 0, kwlnRootUpdateTask, kwlnRootDestroyTask, work);
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
        setRenderState = &DAT_00960070.device.setRenderState;
        (*setRenderState)(rwRENDERSTATEZTESTENABLE, (void*)true);
        (*setRenderState)(rwRENDERSTATEZWRITEENABLE, (void*)true);
        RpSkyRenderStateSet(2, (void*)0x44);
        RpSkyRenderStateSet(3, (void*)0x717fb);
        (*setRenderState)(rwRENDERSTATEFOGENABLE, (void*)false);
        func_001120c0();
        func_001125d0();
    }
    else
    {
        K_Assert(D_006787D8, 393);
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
    return kwlnTaskInit(D_006787E8, 4196, kwlnRootUpdate2DDrawBeginTask, NULL, NULL);
}

// FUN_00198b90
KwlnTask* kwlnRootCreate2DDrawBeginPreEndTask()
{
    return kwlnTaskInit(D_00678800, 5231, kwlnRootUpdate2DDrawPreEndTask, NULL, NULL);
}

// FUN_00198bd0
KwlnTask* kwlnRootCreate2DDrawEndTask()
{
    return kwlnTaskInit(D_00678810, 5241, kwlnRootUpdate2DDrawEndTask, NULL, NULL);
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

        setRenderState = &DAT_00960070.device.setRenderState;

        (*setRenderState)(rwRENDERSTATEZTESTENABLE, (void*)true);
        (*setRenderState)(rwRENDERSTATEZWRITEENABLE, (void*)true);
    }
    else
    {
        K_Assert(D_006787D8, 719);
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
        setRenderState = &DAT_00960070.device.setRenderState;

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
    return kwlnTaskInit(D_00678820, 5243, kwlnRootUpdate3DOn2DZClearTask, NULL, NULL);
}

// FUN_00198e10
KwlnTask* kwlnRootCreate3DOn2DDrawBeginTask()
{
    return kwlnTaskInit(D_00678830, 5245, kwlnRootUpdate3DOn2DDrawBeginTask, NULL, NULL);
}

// FUN_00198e50
KwlnTask* kwlnRootCreate3DOn2DDrawEndTask()
{
    return kwlnTaskInit(D_00678850, 6320, kwlnRootUpdate3DOn2DDrawEndTask, NULL, NULL);
}

// FUN_00198e90
void* FUN_00198e90(KwlnTask* etcDrawBeginTask)
{
    RwRenderStateSetFunc* setRenderState;
    RwCamera* camera;

    camera = kwlnGetMainCamera();
    RwCameraClear(camera, kwlnGetClearColor(), rwCAMERACLEARZ);

    if (RwCameraBeginUpdate(kwlnGetMainCamera()) != NULL)
    {
        kwlnSetFlags(KWLN_FLAG_ERR | KWLN_FLAG_3DDRAW, false);
        kwlnSetFlags(KWLN_FLAG_2DDRAW, true);

        setRenderState = &DAT_00960070.device.setRenderState;
        (*setRenderState)(rwRENDERSTATEZTESTENABLE, (void*)true);
        (*setRenderState)(rwRENDERSTATEZWRITEENABLE, (void*)true);
        (*setRenderState)(rwRENDERSTATEFOGENABLE, (void*)false);
    }
    else
    {
        K_Assert(D_006787D8, 0x347);
        kwlnSetFlags(KWLN_FLAG_ERR, true);
    }

    return KWLNTASK_CONTINUE;
}

// FUN_00198f90
void* kwlnRootUpdateEtcDrawTask(KwlnTask* etcDrawTask)
{
    H_Fade_Main();

    H_Dbprt_Main();
    H_Dbprt_Flush();

    return KWLNTASK_CONTINUE;
}

// FUN_00198fd0
void* FUN_00198fd0(KwlnTask* etcDrawEndTask)
{
    RwRenderStateSetFunc* setRenderState;

    if (gFogEnabled == true)
    {
        setRenderState = &DAT_00960070.device.setRenderState;

        (*setRenderState)(rwRENDERSTATEFOGENABLE, (void*)true);
        (*setRenderState)(rwRENDERSTATEFOGCOLOR, (void*)PACK_RWRGBA(gFogRed, gFogGreen, gFogBlue, gFogAlpha));
        (*setRenderState)(rwRENDERSTATEFOGTYPE, (void*)rwFOGTYPELINEAR);
    }

    kwlnCameraEndUpdate();

    return KWLNTASK_CONTINUE;
}

// FUN_00199080
KwlnTask* FUN_00199080()
{
    return kwlnTaskInit(D_00678868, 6323, FUN_00198e90, NULL, NULL);
}

// FUN_001990c0
KwlnTask* kwlnRootCreateEtcDrawTask()
{
    return kwlnTaskInit(D_00678878, 6335, kwlnRootUpdateEtcDrawTask, NULL, NULL);
}

// FUN_00199100
KwlnTask* FUN_00199100()
{
    return kwlnTaskInit(D_00678888, 7379, FUN_00198fd0, NULL, NULL);
}

// FUN_00199140
void* kwlnRootUpdateShowRasterTask(KwlnTask* showRasterTask)
{
    RwCamera* camera;
    RwRaster* raster;
    RwUInt8* oldPixels;
    RwUInt8* newPixels;
    u32 allocationSize;
    u32 currentCount;
    sShowRasterResult = (u32)func_004c4d20();

    if (sShowRasterUpdatePending == 1)
    {
        camera = kwlnGetMainCamera();
        raster = camera->frameBuffer;
        oldPixels = raster->cpPixels;
        allocationSize = raster->width * raster->height * (raster->depth >> 3);
        newPixels = (RwUInt8*)KWLN_ALLOC2(allocationSize, 0x40000);
        if (newPixels != NULL)
        {
            raster->cpPixels = newPixels;
            if (func_004ce200(raster, 0, 2) == NULL)
            {
                raster->cpPixels = oldPixels;
                KWLN_FREE(newPixels);
            }

            func_004cbf20(sShowRasterImage);
            func_004cdc70(sShowRasterImage, raster);
            func_004cde00(raster);
            raster->cpPixels = oldPixels;
            KWLN_FREE(newPixels);
        }
        sShowRasterUpdatePending = 0;
    }

    camera = kwlnGetMainCamera();
    func_004c9ed0(camera, 0, 0);

    currentCount = Y_Misc_GetT0Count();
    sShowRasterCurrentCount = currentCount;
    sShowRasterDelta = (f32)(currentCount - gT0CountVal);

    sShowRasterCurrent = (f32)currentCount;

    sShowRasterPercent = (sShowRasterDelta / 520.0f) * 100.0f;
    DPUT_T0_COUNT(0);
    sShowRasterEnabled = 1;
    func_004c7cf0(0);
    func_0010bff0();
    func_0010c5f0();
    func_005810f0();
    RpRandom();

    return KWLNTASK_CONTINUE;
}

// FUN_00199360
KwlnTask* FUN_00199360()
{
    return kwlnTaskInit(D_006788A0, 7396, kwlnRootUpdateShowRasterTask, NULL, NULL);
}

// FUN_001993a0
void* FUN_001993a0(KwlnTask* drawBustupTask)
{
    H_Chrdsp_Main();

    return KWLNTASK_CONTINUE;
}

// FUN_001993d0
KwlnTask* FUN_001993d0()
{
    return kwlnTaskInit(D_006788B8, 5276, FUN_001993a0, NULL, NULL);
}

// FUN_00199410
void FUN_00199410(KwlnTask* draw3DTask)
{
    KWLN_FREE(draw3DTask->workData);
    sDraw3DTask = NULL;
}

typedef struct KwlnDraw3DWork
{
    u32 rasterA;
    u32 rasterB;
} KwlnDraw3DWork;

// FUN_00199440
KwlnTask* FUN_00199440(KwlnTask* rootTask)
{
    KwlnDraw3DWork* work;

    if (sDraw3DTask != NULL)
    {
        K_Assert(D_006788C8, 0x76);
    }

    work = (KwlnDraw3DWork*)KWLN_ALLOC3(1, sizeof(KwlnDraw3DWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }

    sDraw3DTask = kwlnTaskCreate(rootTask, "3D Draw", 5, NULL, FUN_00199410, work);
    work->rasterA = sShowRasterRasterB;
    work->rasterB = sShowRasterRasterA;
    K_SPipe_CreateShadowNodeTask(sDraw3DTask);
    K_SPipe_Create3DDrwBeginTask(sDraw3DTask);
    K_SPipe_Create3DDrwEndTask(sDraw3DTask);

    return sDraw3DTask;
}
