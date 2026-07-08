#include "rw/rwcore.h"

// FUN_004c9b40 NONMATCHING
static RwCamera* CameraEndUpdate(RwCamera* camera)
{
    RwStandardFunc cameraEndUpdateFunc;

    cameraEndUpdateFunc = RWSTDFUNC(rwSTANDARDCAMERAENDUPDATE);
    if (!cameraEndUpdateFunc(NULL, camera, 0))
    {
        return NULL;
    }

    RwCameraGetCurrentCamera() = NULL;
    return camera;
}

// FUN_004c9d00 NONMATCHING
RwCamera* RwCameraEndUpdate(RwCamera* camera)
{
    return camera->endUpdate(camera);
}

// FUN_004c9d10 NONMATCHING
RwCamera* RwCameraBeginUpdate(RwCamera* camera)
{
    return camera->beginUpdate(camera);
}

// FUN_004c9e90 NONMATCHING
RwCamera* RwCameraClear(RwCamera* camera, RwRGBA* colors, RwCameraClearMode clearMode)
{
    RwStandardFunc cameraClearFunc;

    cameraClearFunc = RWSTDFUNC(rwSTANDARDCAMERACLEAR);
    if (cameraClearFunc(camera, colors, clearMode))
    {
        return camera;
    }

    return NULL;
}

// FUN_004c9df0
RwFrustumTestResult RwCameraFrustumTestSphere(const RwCamera* camera, const RwSphere* sphere)
{
    // TODO

    return rwSPHEREOUTSIDE;
}

// FUN_004c9f00
RwCamera* RwCameraSetProjectionType(RwCamera* camera, RwCameraProjection projType)
{
    // TODO

    return camera;
}

// FUN_004c9f90
RwCamera* RwCameraSetViewWindow(RwCamera* camera, const RwV2d* viewWindow)
{
    // TODO

    return camera;
}

// FUN_004d7f60
RwBool RpSkyRenderStateSet(RpSkyRenderState nState, void *pParam)
{
    // TODO

    return true;
}