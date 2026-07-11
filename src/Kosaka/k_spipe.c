#include "Kosaka/k_spipe.h"
#include "Kosaka/k_assert.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/Kwln/kwln.h"
#include "Main/g_data.h"
#include "rw/rwcore.h"
#include "temporary.h"

extern u32 FUN_00195750(void);
extern void FUN_001a8910(u32 param);
extern u32 gUnk_008668f0[];


// FUN_00199520
void* K_SPipe_Update3DDrwBeginTask(KwlnTask* draw3DBeginTask)
{
    RwRenderStateSetFunc* setRenderState;

    if (kwlnCameraBeginUpdate() != NULL)
    {
        kwlnSetFlags(KWLN_FLAG_ERR | KWLN_FLAG_3DDRAW, false);
        kwlnSetFlags(KWLN_FLAG_3DDRAW, true);
        setRenderState = &rwGlobals.device.setRenderState;
        (*setRenderState)(rwRENDERSTATEZTESTENABLE, (void*)true);
        (*setRenderState)(rwRENDERSTATEZWRITEENABLE, (void*)true);
        FUN_00195750();
    }
    else
    {
        K_Assert("k_spipe.c", 385);
        kwlnSetFlags(KWLN_FLAG_ERR, true);
    }

    return KWLNTASK_CONTINUE;
}

// FUN_001995f0
void* K_SPipe_Update3DDrwEndTask(KwlnTask* draw3DEndTask)
{
    RwRenderStateSetFunc* setRenderState;

    setRenderState = &rwGlobals.device.setRenderState;
    (*setRenderState)(rwRENDERSTATEFOGENABLE, (void*)false);
    (*setRenderState)(rwRENDERSTATEFOGENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATEFOGCOLOR, (void*)PACK_RWRGBA(gFogRed, gFogGreen, gFogBlue, gFogAlpha));
    (*setRenderState)(rwRENDERSTATEFOGTYPE, (void*)rwFOGTYPELINEAR);

    kwlnCameraEndUpdate();

    kwlnSetFlags(KWLN_FLAG_2DDRAW | KWLN_FLAG_3DDRAW, false);

    return KWLNTASK_CONTINUE;
}

// FUN_001996c0
KwlnTask* K_SPipe_Create3DDrwBeginTask(KwlnTask* draw3DTask)
{
    return kwlnTaskCreate(draw3DTask, "3D Draw Begin", 2098, K_SPipe_Update3DDrwBeginTask, NULL, NULL);
}

// FUN_00199700
KwlnTask* K_SPipe_Create3DDrwEndTask(KwlnTask* draw3DTask)
{
    return kwlnTaskCreate(draw3DTask, "3D Draw End", 4167, K_SPipe_Update3DDrwEndTask, NULL, NULL);
}

// FUN_00199740
void* K_SPipe_UpdateShadowNodeTask(KwlnTask* shadowNodeTask)
{
    RwCameraClear(kwlnGetMainCamera(), kwlnGetClearColor(), rwCAMERACLEAR1 | rwCAMERACLEARZ);
    FUN_001a8910((u32)gUnk_008668f0);

    return KWLNTASK_CONTINUE;
}

// FUN_001997a0
KwlnTask* K_SPipe_CreateShadowNodeTask(KwlnTask* draw3DTask)
{
    return kwlnTaskCreate(draw3DTask, "shadow node(camera all clear)", 2069, K_SPipe_UpdateShadowNodeTask, NULL, NULL);
}