#include "Graphics/primitive.h"
#include "Kernel/Kwln/kwln.h"
#include "sce/eestruct.h"
#include "libm.h"

#define PRIM_RENDERSTATE_COUNT 6

// 8 bytes
typedef struct 
{
    RwRenderState renderState; // 0x00
    u32 val;         // 0x04
} PrimRenderState;

// 0069ce60
static const PrimRenderState sRenderStates[PRIM_RENDERSTATE_COUNT] =
{
    {rwRENDERSTATEFOGENABLE, false},
    {rwRENDERSTATEVERTEXALPHAENABLE, true}, 
    {rwRENDERSTATESHADEMODE, rwSHADEMODEGOURAUD},
    {rwRENDERSTATECULLMODE, rwCULLMODECULLNONE},
    {rwRENDERSTATEZTESTENABLE, true},
    {rwRENDERSTATEZWRITEENABLE, false}
};

// 0069ce90
static const RwV3d sAxisDirs[3] =
{
    {1.0f, 0.0f, 0.0f}, // X
    {0.0f, 1.0f, 0.0f}, // Y
    {0.0f, 0.0f, 1.0f}  // Z
};

// 0069ceb8
static const RwRGBA sAxisColors[3] =
{
    {255, 0, 0, 255}, // X (red)
    {0, 255, 0, 255}, // Y (green)
    {0, 0, 255, 255}  // Z (blue)
};

static const RwV3d sSphereRotAxis = {1.0f, 0.0f, 0.0f}; // 0069cec8


// FUN_00358a30
void primQuad3D(const RwV3d* pos, const RwRGBA* col, f32 size, u32 saveAndRestoreRenderState)
{
    u32 i;
    u32 j;
    const PrimRenderState* currRenderState;
    u32* currSavedRenderState;
    RwRenderStateSetFunc* setRenderState;
    RwV3d cameraPos;
    RwIm2DVertex vertices[4];
    u32 savedRenderStates[PRIM_RENDERSTATE_COUNT];
    f32 zBufferNear;
    f32 zBufferFar;
    f32 nearPlane;
    f32 farPlane;
    f32 screenZ;
    f32 recipZ;
    f32 screenX;
    f32 screenY;

    RwV3dTransformPoint(&cameraPos, pos, &kwlnGetMainCamera()->viewMatrix);
    zBufferNear = rwGlobals.device.zBufferNear;
    zBufferFar = rwGlobals.device.zBufferFar;
    farPlane = kwlnGetMainCamera()->farPlane;
    nearPlane = kwlnGetMainCamera()->nearPlane;

    if (cameraPos.z > nearPlane && cameraPos.z < farPlane)
    {

        size *= 0.5f;
        screenZ = zBufferNear + (nearPlane / cameraPos.z) *
                                      ((cameraPos.z - farPlane) * ((zBufferFar - zBufferNear) / (nearPlane - farPlane)));
        if (screenZ < 0.0f)
        {
            screenZ = 0.0f;
        }

        recipZ = 1.0f / screenZ;
        screenX = 640.0f * (cameraPos.x / cameraPos.z);
        screenY = 448.0f * (cameraPos.y / cameraPos.z);

        if (saveAndRestoreRenderState)
        {
            for (i = 0; i < PRIM_RENDERSTATE_COUNT; i++)
            {
                currRenderState = &sRenderStates[i];
                currSavedRenderState = &savedRenderStates[i];
                RwRenderStateGet(currRenderState->renderState, currSavedRenderState);
                RwRenderStateSet(currRenderState->renderState, currRenderState->val);
            }
            setRenderState = &rwGlobals.device.setRenderState;

            (*setRenderState)(rwRENDERSTATEZTESTENABLE, NULL);
            (*setRenderState)(rwRENDERSTATETEXTURERASTER, NULL);
            RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)SCE_GS_SET_ALPHA_1(0, 2, 0, 1, 0));
            RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)SCE_GS_SET_TEST_1(1, 0, 128, 1, 0, 0, 1, 3));
        }

        vertices[0].u.els.scrVertex.x = screenX - size;
        vertices[0].u.els.scrVertex.y = screenY - size;
        vertices[0].u.els.scrVertex.z = screenZ;
        vertices[0].u.els.recipZ = recipZ;
        vertices[0].u.els.color.r = (f32)col->r;
        vertices[0].u.els.color.g = (f32)col->g;
        vertices[0].u.els.color.b = (f32)col->b;
        vertices[0].u.els.color.a = (f32)col->a;

        vertices[1].u.els.scrVertex.x = screenX - size;
        vertices[1].u.els.scrVertex.y = screenY + size;
        vertices[1].u.els.scrVertex.z = screenZ;
        vertices[1].u.els.recipZ = recipZ;
        vertices[1].u.els.color.r = (f32)col->r;
        vertices[1].u.els.color.g = (f32)col->g;
        vertices[1].u.els.color.b = (f32)col->b;
        vertices[1].u.els.color.a = (f32)col->a;

        vertices[2].u.els.scrVertex.x = screenX + size;
        vertices[2].u.els.scrVertex.y = screenY - size;
        vertices[2].u.els.scrVertex.z = screenZ;
        vertices[2].u.els.recipZ = recipZ;
        vertices[2].u.els.color.r = (f32)col->r;
        vertices[2].u.els.color.g = (f32)col->g;
        vertices[2].u.els.color.b = (f32)col->b;
        vertices[2].u.els.color.a = (f32)col->a;

        vertices[3].u.els.scrVertex.x = screenX + size;
        vertices[3].u.els.scrVertex.y = screenY + size;
        vertices[3].u.els.scrVertex.z = screenZ;
        vertices[3].u.els.recipZ = recipZ;
        vertices[3].u.els.color.r = (f32)col->r;
        vertices[3].u.els.color.g = (f32)col->g;
        vertices[3].u.els.color.b = (f32)col->b;
        vertices[3].u.els.color.a = (f32)col->a;

        RwIm2DRenderPrimitive(rwPRIMTYPETRISTRIP, vertices, 4);

        if (saveAndRestoreRenderState)
        {
            for (j = 0; j < PRIM_RENDERSTATE_COUNT; j++)
            {
                RwRenderStateSet(sRenderStates[j].renderState, savedRenderStates[j]);
            }
        }
    }
}

// FUN_00359110
void primLine3D(const RwV3d* startPos, const RwV3d* endPos, const RwRGBA* color, u32 saveAndRestoreRenderState)
{
    u32 i;
    const PrimRenderState* currRenderState;
    u32* currSavedRenderState;
    RwIm3DVertex vertices[2];
    RwMatrix identity;
    u32 savedRenderStates[PRIM_RENDERSTATE_COUNT];
    u32 j;

    if (saveAndRestoreRenderState)
    {
        for (i = 0; i < PRIM_RENDERSTATE_COUNT; i++)
        {
            currRenderState = &sRenderStates[i];
            currSavedRenderState = &savedRenderStates[i];
            RwRenderStateGet(currRenderState->renderState, currSavedRenderState);
            RwRenderStateSet(currRenderState->renderState, currRenderState->val);
        }

        RwRenderStateSet(rwRENDERSTATETEXTURERASTER, NULL);

        RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)SCE_GS_SET_ALPHA_1(0, 2, 0, 1, 0));
        RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)SCE_GS_SET_TEST_1(1, 0, 128, 1, 0, 0, 1, 3));
    }

    RwMatrixSetIdentity(&identity);

    RwIm3DVertexSetPos(&vertices[0], startPos->x, startPos->y, startPos->z);
    RwIm3DVertexSetPos(&vertices[1], endPos->x, endPos->y, endPos->z);
    RwIm3DVertexSetRGBA(&vertices[0], color->r, color->g, color->b, color->a);
    RwIm3DVertexSetRGBA(&vertices[1], color->r, color->g, color->b, color->a);

    RwIm3DTransform(vertices, 2, &identity, rwIM3D_ALLOPAQUE);
    RwIm3DRenderLine(0, 1);

    if (saveAndRestoreRenderState)
    {
        for (j = 0; j < PRIM_RENDERSTATE_COUNT; j++)
        {
            RwRenderStateSet(sRenderStates[j].renderState, savedRenderStates[j]);
        }
    }
}

#pragma optimization_level 1
// FUN_00359380
void primAxisLine3D(const RwMatrix* mat, f32 length, u32 saveAndRestoreRenderState)
{
    u32 i;
    const PrimRenderState* currRenderState;
    u32 savedRenderStates[PRIM_RENDERSTATE_COUNT];
    u32 j;
    const RwV3d* currAxisDir;
    RwV3d finalAxisPoint;
    RwV3d axisPoint;

    if (saveAndRestoreRenderState)
    {
        for (i = 0; i < PRIM_RENDERSTATE_COUNT; i++)
        {
            currRenderState = &sRenderStates[i];
            RwRenderStateGet(currRenderState->renderState, &savedRenderStates[i]);
            RwRenderStateSet(currRenderState->renderState, currRenderState->val);
        }

        RwRenderStateSet(rwRENDERSTATETEXTURERASTER, NULL);

        RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)SCE_GS_SET_ALPHA_1(0, 2, 0, 1, 0));
        RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)SCE_GS_SET_TEST_1(1, 0, 128, 1, 0, 0, 1, 3));
    }

    for (j = 0; j < 3; j++)
    {
        currAxisDir = &sAxisDirs[j];

        axisPoint.x = length * currAxisDir->x;
        axisPoint.y = length * currAxisDir->y;
        axisPoint.z = length * currAxisDir->z;

        RwV3dTransformPoint(&finalAxisPoint, &axisPoint, mat);

        primLine3D(&mat->pos, &finalAxisPoint, &sAxisColors[j], false);
    }

    if (saveAndRestoreRenderState)
    {
        for (j = 0; j < PRIM_RENDERSTATE_COUNT; j++)
        {
            RwRenderStateSet(sRenderStates[j].renderState, savedRenderStates[j]);
        }
    }
}
#pragma optimization_level 2

// FUN_00359560 NONMATCHING
void primCircleLine3D(const RwV3d* center, f32 radius, const RwRGBA* color, const RwMatrix* mat, u32 saveAndRestoreRenderState)
{
    u32 saveAndRestoreRenderState_p = saveAndRestoreRenderState;
    const RwMatrix* mat_p = mat;
    RwIm2DVertex vertices[21];
    f32 zScale;
    u32* currSavedRenderState;
    f32 nearPlane;
    f32 zBufferNear;
    RwV3d circlePoint;
    RwV3d worldPoint;
    RwV3d cameraPoint;
    u32 savedRenderStates[PRIM_RENDERSTATE_COUNT];
    f32 angle;
    f32 zBufferFar;
    u32 i;
    f32 farPlane;
    RwMatrix localMat;
    const RwMatrix* cameraMat;
    const PrimRenderState* currRenderState;
    const PrimRenderState* currRenderState_c;
    RwSphere sphere;

    sphere.radius = radius;
    sphere.center.x = center->x;
    sphere.center.y = center->y;
    sphere.center.z = center->z;
    if (RwCameraFrustumTestSphere(RwCameraGetCurrentCamera(), &sphere) == rwSPHEREOUTSIDE)
    {
        return;
    }

    zBufferFar = rwGlobals.device.zBufferFar;
    zBufferNear = rwGlobals.device.zBufferNear;
    farPlane = kwlnGetMainCamera()->farPlane;
    nearPlane = kwlnGetMainCamera()->nearPlane;
    cameraMat = &kwlnGetMainCamera()->viewMatrix;

    if (mat != NULL)
    {
        localMat = *mat_p;
    }
    else
    {
        RwMatrixSetIdentity(&localMat);
    }

    localMat.pos = *center;

    if (saveAndRestoreRenderState_p)
    {
        for (i = 0; i < PRIM_RENDERSTATE_COUNT; i++)
        {
            currSavedRenderState = &savedRenderStates[i];
            currRenderState = &sRenderStates[i];
            RwRenderStateGet(currRenderState->renderState, currSavedRenderState);
            RwRenderStateSet(currRenderState->renderState, (currRenderState_c = currRenderState)->val);
        }

        RwRenderStateSet(rwRENDERSTATETEXTURERASTER, NULL);
        RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)SCE_GS_SET_ALPHA_1(0, 2, 0, 1, 0));
        RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)SCE_GS_SET_TEST_1(1, 0, 128, 1, 0, 0, 1, 3));
    }

    zScale = (zBufferFar - zBufferNear) / (nearPlane - farPlane);
    angle = 0.0f;
    for (i = 0; i < 20; i++)
    {
        circlePoint.x = radius * cosf(angle);
        circlePoint.y = 0.0f;
        circlePoint.z = radius * sinf(angle);
        RwV3dTransformPoint(&worldPoint, &circlePoint, &localMat);
        RwV3dTransformPoint(&cameraPoint, &worldPoint, cameraMat);

        vertices[i].u.els.scrVertex.x = 640.0f * (cameraPoint.x / cameraPoint.z);
        vertices[i].u.els.scrVertex.y = 448.0f * (cameraPoint.y / cameraPoint.z);
        vertices[i].u.els.scrVertex.z = zBufferNear + (nearPlane / cameraPoint.z) * ((cameraPoint.z - farPlane) * zScale);
        (0, vertices[i].u.els).color.r = (f32)color->r;
        vertices[i].u.els.color.g = (f32)color->g;
        (0, vertices[i].u).els.recipZ = 1.0f / vertices[i].u.els.scrVertex.z;
        vertices[i].u.els.color.b = (f32)color->b;
        vertices[i].u.els.color.a = (f32)color->a;

        angle = angle + (g18deg);
    }

    vertices[20].u.els.scrVertex = vertices[0].u.els.scrVertex;
    vertices[20].u.els.recipZ = vertices[0].u.els.recipZ;
    vertices[20].u.els.color.r = (f32)color->r;
    (0, vertices[20].u.els).color.g = (f32)color->g;
    (0, vertices[20].u.els).color.b = (f32)color->b;
    vertices[20].u.els.color.a = (f32)color->a;

    RwIm2DRenderPrimitive(rwPRIMTYPEPOLYLINE, vertices, 21);

    if (saveAndRestoreRenderState_p)
    {
        for (i = 0; i < PRIM_RENDERSTATE_COUNT; i++)
        {
            RwRenderStateSet(sRenderStates[i].renderState, savedRenderStates[i]);
        }
    }
}

#pragma optimization_level 1
// FUN_00359b40 NONMATCHING
void primSphereLine3D(const RwV3d* center, f32 radius, const RwRGBA* color, u32 saveAndRestoreRenderState)
{
    const RwRGBA* color_p = color;
    f32 radius_p = radius;
    u32 i;
    const PrimRenderState* currRenderState;
    RwMatrix mat;
    u32 savedRenderStates[PRIM_RENDERSTATE_COUNT];
    u32* currSavedRenderState;
    RwV3d finalCenter;
    RwSphere rwSphere;
    RwV3d rotAxis;
    u32 j;
    f32 yOffset;
    f32 circleRadius;
    f32 angle;

    rotAxis = sSphereRotAxis;
    rwSphere.radius = radius_p;
    rwSphere.center.x = center->x;
    rwSphere.center.y = center->y;
    rwSphere.center.z = center->z;
    if (RwCameraFrustumTestSphere(RwCameraGetCurrentCamera(), &rwSphere) != rwSPHEREOUTSIDE)
    {
        if (saveAndRestoreRenderState)
        {
            for (i = 0; i < PRIM_RENDERSTATE_COUNT; i++)
            {
                currRenderState = &sRenderStates[i];
                RwRenderStateGet((currSavedRenderState = &savedRenderStates[i], currRenderState->renderState), currSavedRenderState);
                RwRenderStateSet(currRenderState->renderState, currRenderState->val);
            }

            RwRenderStateSet(rwRENDERSTATETEXTURERASTER, NULL);

            RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)SCE_GS_SET_ALPHA_1(0, 2, 0, 1, 0));
            RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)SCE_GS_SET_TEST_1(1, 0, 128, 1, 0, 0, 1, 3));
        }

        mat.right.x = mat.up.y = mat.at.z = 1.0f;
        angle = 0.0f;
        mat.right.y = mat.right.z = mat.up.x = 0.0f;
        mat.up.z = mat.at.x = mat.at.y = 0.0f;
        mat.pos.x = mat.pos.y = mat.pos.z = 0.0f;
        mat.flags |= (rwMATRIXINTERNALIDENTITY | rwMATRIXTYPEORTHONORMAL);

        for (j = 0; j < 9; j++)
        {
            angle += g18deg;
            yOffset = radius_p * cosf(angle);
            circleRadius = radius_p * sinf(angle);

            finalCenter.x = center->x;
            finalCenter.y = center->y + yOffset;
            finalCenter.z = center->z;

            primCircleLine3D(&finalCenter, circleRadius, color_p, &mat, false);
        }

        RwMatrixRotate(&mat, &rotAxis, 90.0f, rwCOMBINEPOSTCONCAT);

        angle = 0.0f;
        for (j = 0; j < 9; j++)
        {
            angle += g18deg;
            yOffset = radius_p * cosf(angle);
            circleRadius = radius * sinf(angle);

            finalCenter.x = center->x;
            finalCenter.z = center->z;
            finalCenter.y = center->y + yOffset;

            primCircleLine3D(&finalCenter, circleRadius, color, &mat, false);
        }

        if (saveAndRestoreRenderState)
        {
            for (j = 0; j < PRIM_RENDERSTATE_COUNT; j++)
            {
                RwRenderStateSet((0, sRenderStates[j]).renderState, savedRenderStates[j]);
            }
        }
    }
}
#pragma optimization_level 2

// FUN_00359e50 NONMATCHING
void primCylinderLine3D(const RwV3d* center, f32 radius, f32 height, const RwRGBA* color, u32 saveAndRestoreRenderState)
{
    u32 i;
    const PrimRenderState* currRenderState;
    u32* currSavedRenderState;
    u32 savedRenderStates[PRIM_RENDERSTATE_COUNT];
    RwSphere sphere;
    RwV3d circleCenter;
    RwV3d lineEnd;
    RwV3d lineStart;
    f32 heightStep;
    f32 halfHeight;
    f32 negHalfHeight;
    f32 angle;

    sphere.radius = (radius > height) ? radius : height;
    sphere.center.x = center->x;
    sphere.center.y = center->y;
    sphere.center.z = center->z;
    if (RwCameraFrustumTestSphere(RwCameraGetCurrentCamera(), &sphere) == rwSPHEREOUTSIDE)
    {
        return;
    }

    if (saveAndRestoreRenderState)
    {
        for (i = 0; i < PRIM_RENDERSTATE_COUNT; i++)
        {
            currRenderState = &sRenderStates[i];
            currSavedRenderState = &savedRenderStates[i];
            RwRenderStateGet(currRenderState->renderState, currSavedRenderState);
            RwRenderStateSet(currRenderState->renderState, currRenderState->val);
        }

        RwRenderStateSet(rwRENDERSTATETEXTURERASTER, NULL);
        RpSkyRenderStateSet(rpSKYRENDERSTATEALPHA_1, (void*)SCE_GS_SET_ALPHA_1(0, 2, 0, 1, 0));
        RpSkyRenderStateSet(rpSKYRENDERSTATEATEST_1, (void*)SCE_GS_SET_TEST_1(1, 0, 128, 1, 0, 0, 1, 3));
    }

    heightStep = height / 7.0f;
    circleCenter.x = center->x;
    halfHeight = 0.5f * height;
    circleCenter.y = center->y - halfHeight;
    circleCenter.z = center->z;
    for (i = 0; i < 8; i++)
    {
        primCircleLine3D(&circleCenter, radius, color, NULL, false);
        circleCenter.y += heightStep;
    }
    angle = 0.0f;
    negHalfHeight = -height * 0.5f;
    for (i = 0; i < 10; i++)
    {
        lineStart.x = radius * cosf(angle);
        lineStart.y = negHalfHeight;
        lineStart.z = radius * sinf(angle);
        lineEnd.x = lineStart.x;
        lineEnd.y = halfHeight;
        lineEnd.z = lineStart.z;
        lineStart.x += center->x;
        lineStart.y += center->y;
        lineStart.z += center->z;
        lineEnd.x += center->x;
        lineEnd.y += center->y;
        lineEnd.z += center->z;
        primLine3D(&lineStart, &lineEnd, color, false);
        angle += g18deg + g18deg;
    }

    angle = 0.0f;
    for (i = 0; i < 5; i++)
    {
        lineStart.x = radius * cosf(angle);
        lineStart.y = negHalfHeight;
        lineStart.z = radius * sinf(angle);
        angle += gPI;
        lineEnd.x = radius * cosf(angle);
        lineEnd.y = negHalfHeight;
        lineEnd.z = radius * sinf(angle);
        lineStart.x += center->x;
        lineStart.y += center->y;
        lineStart.z += center->z;
        lineEnd.x += center->x;
        lineEnd.y += center->y;
        lineEnd.z += center->z;
        primLine3D(&lineStart, &lineEnd, color, false);

        lineStart.y += height;
        lineEnd.y += height;
        primLine3D(&lineStart, &lineEnd, color, false);
        angle += g18deg + g18deg;
    }
    if (saveAndRestoreRenderState)
    {
        for (i = 0; i < PRIM_RENDERSTATE_COUNT; i++)
        {
            RwRenderStateSet(sRenderStates[i].renderState, savedRenderStates[i]);
        }
    }
}


/* ---- Recovered range 0x35A290-0x35AD50 (Ghidra reference, pending match) ---- */
typedef struct
{
    u8 pad0[8];
    struct
    {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    } quat;
    f32 values[6];
    f32 value30;
} PrimInterpData;

typedef void (*PrimFuncB)(void*, void*, void*, f32);
typedef void (*PrimFuncA)(int, int);
typedef u32 (*PrimFuncC)(int, u64);
typedef u64 (*PrimFuncD)(u64, u64);
typedef void (*PrimFuncE)(void*, void*);
typedef void (*PrimFuncStub)(void);
typedef struct
{
    u32 hash;
    u32 size0;
    u32 size1;
    PrimFuncA funcA;
    PrimFuncB funcB;
    PrimFuncB funcB2;
    PrimFuncStub funcC;
    PrimFuncE funcD;
    PrimFuncD funcE;
    PrimFuncC funcF;
    PrimFuncStub funcG;
    u32 zero;
} PrimDesc;
#ifndef CONCAT11
#define CONCAT11(hi, lo) ((u16)((((u16)(u8)(hi)) << 8) | (u8)(lo)))
#endif
#ifndef CONCAT12
#define CONCAT12(hi, lo) ((u32)((((u32)(u8)(hi)) << 16) | (u16)(lo)))
#endif
extern float fGpffff8028;
extern u8 gp0xffff9d68;
extern void LAB_0035aa10(void);
extern u32 LAB_0035a850(void* param_1);
extern void* FUN_004c33d0(void* matrix, const void* scale, int combineOp);
extern void FUN_004c2f30(int dst, u8* a, float* b);
extern long FUN_004c1750(u64 stream, void* buf, int size);
extern long FUN_004c17f0(u64 stream, void* buf, int size);
extern long FUN_004c18b0(u64 stream, void* buf, int size);
extern long FUN_004c1910(u64 stream, void* buf, int size);
#pragma alias FUN_004c18b0_typed FUN_004c18b0
extern long FUN_004c18b0_typed(void* stream, void* buf, int size);
#pragma alias FUN_004c1910_typed FUN_004c1910
extern long FUN_004c1910_typed(void* stream, void* buf, int size);
extern long FUN_004b6680(void* desc);
extern void FUN_005225a8(u8* fmt, ...);
extern f32 FUN_0052e878(f32 angle);
extern f32 FUN_0052e9e8(f32 param_1);
void FUN_0035a290(int param_1, int param_2);
void FUN_0035a3f0(void* param_2, void* param_3, void* param_4, f32 param_1);
void FUN_0035a620(void* param_2, void* param_3, void* param_4, f32 param_1);
u32 FUN_0035a6a0(int param_1,u64 param_2);
void* FUN_0035a770(void* param_1, void* param_2);
void FUN_0035a870(void* param_1, void* param_2);
typedef struct
{
    f32 m00;
    f32 m01;
    f32 m02;
    u32 mode;
    f32 m10;
    f32 m11;
    f32 m12;
    u32 pad1;
    f32 m20;
    f32 m21;
    f32 m22;
    u32 unused;
    u32 pad2;
    u32 pad3;
    u32 pad4;
} PrimMatrixData;

// FUN_0035A290


void FUN_0035a290(int param_1, int param_2)
{
    u8 buffer[64];
    PrimMatrixData matrix;
    f32 xx;
    f32 yy;
    f32 zz;
    f32 yz;
    f32 zx;
    f32 xy;
    f32 wx;
    f32 wy;
    f32 wz;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    f32 value30;
    f32 value34;
    f32 value38;

    x = *(f32*)(param_2 + 8);
    y = *(f32*)(param_2 + 0xc);
    z = *(f32*)(param_2 + 0x10);
    w = *(f32*)(param_2 + 0x14);
    xx = x * x;
    yy = y * y;
    zz = z * z;
    yz = y * z;
    zx = z * x;
    xy = x * y;
    wx = w * x;
    wy = w * y;
    wz = w * z;

    matrix.m00 = 1.0f - (yy + zz) * 2.0f;
    matrix.m01 = (xy + wz) * 2.0f;
    matrix.m02 = (zx - wy) * 2.0f;
    matrix.m10 = (xy - wz) * 2.0f;
    matrix.m11 = 1.0f - (xx + zz) * 2.0f;
    matrix.m12 = (yz + wx) * 2.0f;
    matrix.m20 = (zx + wy) * 2.0f;
    matrix.m21 = (yz - wx) * 2.0f;
    matrix.m22 = 1.0f - (xx + yy) * 2.0f;

    matrix.pad2 = 0;
    matrix.pad3 = 0;
    matrix.pad4 = 0;
    matrix.mode = 3;

    FUN_004c33d0((void*)buffer, (const void*)((u8*)param_2 + 0x24), 0);
    FUN_004c2f30(param_1, buffer, (f32*)&matrix);

    value30 = *(volatile f32*)(param_2 + 0x18);
    value34 = *(volatile f32*)(param_2 + 0x1c);
    value38 = *(volatile f32*)(param_2 + 0x20);
    *(f32*)((int)param_1 + 0x30) = value30;
    *(f32*)((int)param_1 + 0x34) = value34;
    *(f32*)((int)param_1 + 0x38) = value38;
    *(u32*)((int)param_1 + 0xc) = *(u32*)((int)param_1 + 0xc) & 0xfffdffff;
}

// FUN_0035A3F0


void FUN_0035a3f0(void* param_2, void* param_3, void* param_4, f32 param_1)
{
    PrimInterpData* out = (PrimInterpData*)param_2;
    const PrimInterpData* first = (const PrimInterpData*)param_3;
    PrimInterpData* second = (PrimInterpData*)param_4;
    f32 dot;
    f32 firstWeight;
    f32 secondWeight;
    f32 angle;
    f32 invSin;

    dot = first->quat.x * second->quat.x +
          first->quat.y * second->quat.y +
          first->quat.z * second->quat.z +
          first->quat.w * second->quat.w;
    if (dot < 0.0f)
    {
        dot = -dot;
        second->quat.x = -second->quat.x;
        second->quat.y = -second->quat.y;
        second->quat.z = -second->quat.z;
        second->quat.w = -second->quat.w;
    }

    firstWeight = 1.0f - param_1;
    secondWeight = param_1;
    if (dot < fGpffff8028)
    {
        angle = FUN_0052e9e8(dot);
        invSin = 1.0f / FUN_0052e878(angle);
        firstWeight = invSin * FUN_0052e878(firstWeight * angle);
        secondWeight = invSin * FUN_0052e878(secondWeight * angle);
    }

    out->quat.x = firstWeight * first->quat.x + secondWeight * second->quat.x;
    out->quat.y = firstWeight * first->quat.y + secondWeight * second->quat.y;
    out->quat.z = firstWeight * first->quat.z + secondWeight * second->quat.z;
    out->quat.w = firstWeight * first->quat.w + secondWeight * second->quat.w;

    out->values[0] = secondWeight * (second->values[0] - first->values[0]) + first->values[0] + 0.0f;
    out->values[1] = secondWeight * (second->values[1] - first->values[1]) + first->values[1] + 0.0f;
    out->values[2] = secondWeight * (second->values[2] - first->values[2]) + first->values[2] + 0.0f;
    out->values[3] = secondWeight * (second->values[3] - first->values[3]) + first->values[3] + 0.0f;
    out->values[4] = secondWeight * (second->values[4] - first->values[4]) + first->values[4] + 0.0f;
    out->values[5] = secondWeight * (second->values[5] - first->values[5]) + first->values[5] + 0.0f;
}

// FUN_0035A620


void FUN_0035a620(void* param_2, void* param_3, void* param_4, f32 param_1)
{
    PrimInterpData* out = (PrimInterpData*)param_2;
    const PrimInterpData* first = (const PrimInterpData*)param_3;
    const PrimInterpData* second = (const PrimInterpData*)param_4;
    f32 firstTime;
    f32 secondTime;
    f32 t;

    firstTime = *(const f32*)((const u8*)first + 4);
    secondTime = *(const f32*)((const u8*)second + 4);
    t = (param_1 - firstTime) / (secondTime - firstTime);
    FUN_0035a3f0(out, (void*)first, (void*)second, t);
    out->value30 = first->value30 * second->value30;
}

// FUN_0035A6A0


u32 FUN_0035a6a0(int param_1, u64 param_2)
{
    int iVar1;
    long lVar2;
    int* piVar3;
    int iVar4;
    int iStack_4;

    iVar1 = *(int*)((u8*)param_1 + 0x10);
    iVar4 = 0;
    while (iVar4 < *(int*)((u8*)param_1 + 4))
    {
        piVar3 = (int*)((u8*)iVar1 + iVar4 * 0x34);
        iStack_4 = *piVar3 - iVar1;
        lVar2 = FUN_004c1750(param_2, piVar3 + 1, 0x30);
        if ((lVar2 == 0) || ((lVar2 = FUN_004c17f0(param_2, &iStack_4, 4), lVar2 == 0)))
        {
            return 0;
        }
        iVar4++;
    }
    return 1;
}

// FUN_0035A770 NONMATCHING


void* FUN_0035a770(void* param_1, void* param_2)



{

  int iVar1;

  long lVar2;

  int *piVar3;

  int iVar4;

  int iStack_4;

  

  iVar1 = *(int *)((int)param_2 + 0x10);

  iVar4 = 0;

  while( true ) {

    if (*(int *)((int)param_2 + 4) <= iVar4) {

      return param_2;

    }

    piVar3 = (int *)(iVar1 + iVar4 * 0x34);

    lVar2 = FUN_004c18b0_typed(param_1,piVar3 + 1,0x30);

    if ((lVar2 == 0) || (lVar2 = FUN_004c1910_typed(param_1,&iStack_4,4), lVar2 == 0)) break;

    *piVar3 = iVar1 + iStack_4;

    iVar4 = iVar4 + 1;

  }

  return 0;

}
// FUN_0035a850
u32 LAB_0035a850(void* param_1)
{
    u32 index = *(u32*)((u8*)param_1 + 4);
    u32 result = index << 1;
    result += index;
    result <<= 2;
    result += index;
    result <<= 2;
    return result;
}

// The retail callback table places a second callback at 0x0035AA10; its
// marker below narrows this function's true window to 0x1A0 bytes.
// Remaining differences are MWCCPS2 FPU register allocation/scheduling.
// FUN_0035A870 NONMATCHING


void FUN_0035a870(void* param_1, void* param_2)
{
    PrimInterpData* out = (PrimInterpData*)param_1;
    const PrimInterpData* in = (const PrimInterpData*)param_2;
    volatile f32 saved[4];
    f32 inY;
    f32 inX;
    f32 inZ;
    f32 inW;
    f32 norm;
    f32 inverse;
    f32 ax;
    f32 ay;
    f32 az;
    f32 aw;

    ax = out->quat.x;
    ay = out->quat.y;
    az = out->quat.z;
    aw = out->quat.w;
    saved[0] = ax;
    saved[1] = ay;
    saved[2] = az;
    saved[3] = aw;

    inY = in->quat.y;
    inX = in->quat.x;
    inZ = in->quat.z;
    inW = in->quat.w;
    norm = inY * inY + inX * inX + inZ * inZ + inW * inW;
    if (norm > 0.0f)
    {
        inverse = 1.0f / norm;
        inW = inW * inverse;
        inverse = -inverse;
        inX = inX * inverse;
        inY = inY * inverse;
        inZ = inZ * inverse;
    }
    ay = saved[1];
    az = saved[2];
    aw = saved[3];
    ax = saved[0];

    out->quat.w = inW * aw - (inY * ay + inX * ax + inZ * az);
    out->quat.x = inZ * ay - inY * az;
    out->quat.y = inX * az - inZ * ax;
    out->quat.z = inY * ax - inX * ay;
    out->quat.x = out->quat.x + ax * inW + 0.0f;
    out->quat.y = out->quat.y + ay * inW + 0.0f;
    out->quat.z = out->quat.z + az * inW + 0.0f;
    out->quat.x = out->quat.x + inX * aw + 0.0f;
    out->quat.y = out->quat.y + inY * aw + 0.0f;
    out->quat.z = out->quat.z + inZ * aw + 0.0f;

    out->values[0] = out->values[0] - in->values[0];
    out->values[1] = out->values[1] - in->values[1];
    out->values[2] = out->values[2] - in->values[2];
    out->values[3] = out->values[3] - in->values[3];
    out->values[4] = out->values[4] - in->values[4];
    out->values[5] = out->values[5] - in->values[5];
}
// FUN_0035AA10
void FUN_0035aa10(int param_1, int param_2, int param_3)
{
    *(f32*)(param_1 + 0x14) =
        *(f32*)(param_2 + 0x14) * *(f32*)(param_3 + 0x14) -
        (*(f32*)(param_2 + 8) * *(f32*)(param_3 + 8) +
         *(f32*)(param_2 + 0xc) * *(f32*)(param_3 + 0xc) +
         *(f32*)(param_2 + 0x10) * *(f32*)(param_3 + 0x10));
    *(f32*)(param_1 + 8) =
        *(f32*)(param_2 + 0xc) * *(f32*)(param_3 + 0x10) -
        *(f32*)(param_2 + 0x10) * *(f32*)(param_3 + 0xc);
    *(f32*)(param_1 + 0xc) =
        *(f32*)(param_2 + 0x10) * *(f32*)(param_3 + 8) -
        *(f32*)(param_2 + 8) * *(f32*)(param_3 + 0x10);
    *(f32*)(param_1 + 0x10) =
        *(f32*)(param_2 + 8) * *(f32*)(param_3 + 0xc) -
        *(f32*)(param_2 + 0xc) * *(f32*)(param_3 + 8);
    *(f32*)(param_1 + 8) += *(f32*)(param_3 + 8) * *(f32*)(param_2 + 0x14);
    *(f32*)(param_1 + 0xc) += *(f32*)(param_3 + 0xc) * *(f32*)(param_2 + 0x14);
    *(f32*)(param_1 + 0x10) += *(f32*)(param_3 + 0x10) * *(f32*)(param_2 + 0x14);
    *(f32*)(param_1 + 8) += *(f32*)(param_2 + 8) * *(f32*)(param_3 + 0x14);
    *(f32*)(param_1 + 0xc) += *(f32*)(param_2 + 0xc) * *(f32*)(param_3 + 0x14);
    *(f32*)(param_1 + 0x10) += *(f32*)(param_2 + 0x10) * *(f32*)(param_3 + 0x14);
    *(f32*)(param_1 + 0x18) = *(f32*)(param_2 + 0x18) + *(f32*)(param_3 + 0x18);
    *(f32*)(param_1 + 0x1c) = *(f32*)(param_2 + 0x1c) + *(f32*)(param_3 + 0x1c);
    *(f32*)(param_1 + 0x20) = *(f32*)(param_2 + 0x20) + *(f32*)(param_3 + 0x20);
    *(f32*)(param_1 + 0x24) = *(f32*)(param_2 + 0x24) + *(f32*)(param_3 + 0x24);
    *(f32*)(param_1 + 0x28) = *(f32*)(param_2 + 0x28) + *(f32*)(param_3 + 0x28);
    *(f32*)(param_1 + 0x2c) = *(f32*)(param_2 + 0x2c) + *(f32*)(param_3 + 0x2c);
}

// FUN_0035ABA0


u32 FUN_0035aba0(void)
{
    PrimDesc desc;
    long result;

    desc.hash = 0x44a07195;
    desc.size1 = 0x34;
    desc.size0 = 0x34;
    desc.funcA = FUN_0035a290;
    desc.funcB = FUN_0035a3f0;
    desc.funcB2 = FUN_0035a620;
    desc.funcC = &LAB_0035aa10;
    desc.funcD = FUN_0035a870;
    desc.funcE = (u64 (*)(u64, u64))FUN_0035a770;
    desc.funcF = FUN_0035a6a0;
    desc.funcG = (void (*)())LAB_0035a850;
    desc.zero = 0;

    result = FUN_004b6680(&desc);
    return result != 0;
}

// FUN_0035AC50


void FUN_0035ac50(u64 param_1)



{

  do {

    FUN_005225a8(&gp0xffff9d68,param_1);

  } while( true );

}

// FUN_0035AC80


void FUN_0035ac80(void)



{

  return;

}

// FUN_0035AC90 NONMATCHING


void FUN_0035ac90(int *param_1,int param_2,u8 *param_3,int param_4)
{
  u8 bVar1;
  u8 *pbVar2;
  u8 *pbVar3;
  int iVar4;

  pbVar3 = param_3;
  do {
    while (true) {
      if (param_4 <= (int)pbVar3 - (int)param_3) {
        return;
      }
      bVar1 = *pbVar3;
      pbVar2 = pbVar3 + 1;
      if ((bVar1 & 1) != 0) {
        break;
      }
      iVar4 = (int)(u32)bVar1 >> 1;
LAB_0035ad54:
      param_1 = param_1 + iVar4;
      *param_1 = *param_1 + param_2;
      pbVar3 = pbVar2;
    }
    if ((bVar1 & 2) == 0) {
      iVar4 = (int)(u32)CONCAT11(*pbVar2,bVar1) >> 2;
      pbVar2 = pbVar3 + 2;
      goto LAB_0035ad54;
    }
    if ((bVar1 & 4) == 0) {
      iVar4 = (int)(u32)CONCAT12(pbVar3[2],CONCAT11(*pbVar2,bVar1)) >> 3;
      pbVar2 = pbVar3 + 3;
      goto LAB_0035ad54;
    }
    for (iVar4 = 0; pbVar3 = pbVar2, iVar4 < ((int)(u32)bVar1 >> 3) + 2;
         iVar4 = iVar4 + 1) {
      param_1 = param_1 + 1;
      *param_1 = *param_1 + param_2;
    }
  } while (true);
}
