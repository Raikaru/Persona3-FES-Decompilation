#include "Graphics/primitive.h"
#include "Kernel/Kwln/kwln.h"
#include "sce/eestruct.h"
#include "libm.h"

#define PRIM_RENDERSTATE_COUNT 6

// 8 bytes
typedef struct 
{
    u32 renderState; // 0x00
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


// FUN_00358a30 NONMATCHING
void primQuad3D(const RwV3d* pos, const RwRGBA* col, f32 size, u32 saveAndRestoreRenderState)
{
    u32 i;
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
            for (i = 0; i < PRIM_RENDERSTATE_COUNT; i++)
            {
                RwRenderStateSet(sRenderStates[i].renderState, savedRenderStates[i]);
            }
        }
    }
}

// FUN_00359110 NONMATCHING
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
// FUN_00359380 NONMATCHING
void primAxisLine3D(const RwMatrix* mat, f32 length, u32 saveAndRestoreRenderState)
{
    u32 i;
    const PrimRenderState* currRenderState;
    u32 savedRenderStates[PRIM_RENDERSTATE_COUNT];
    u32* currSavedRenderState;
    u32 j;
    const RwV3d* currAxisDir;
    RwV3d finalAxisPoint;
    RwV3d axisPoint;

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
    RwV3d lineStart;
    RwV3d lineEnd;
    f32 heightStep;
    f32 halfHeight;
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
    halfHeight = -0.5f * height;
    for (i = 0; i < 10; i++)
    {
        lineStart.x = center->x + radius * cosf(angle);
        lineStart.y = center->y + halfHeight;
        lineStart.z = center->z + radius * sinf(angle);
        lineEnd.x = lineStart.x;
        lineEnd.y = center->y + halfHeight + height;
        lineEnd.z = lineStart.z;
        primLine3D(&lineStart, &lineEnd, color, false);
        angle += g18deg + g18deg;
    }

    angle = 0.0f;
    for (i = 0; i < 5; i++)
    {
        lineStart.x = center->x + radius * cosf(angle);
        lineStart.y = center->y - 0.5f * height;
        lineStart.z = center->z + radius * sinf(angle);
        lineEnd.x = center->x + radius * cosf(angle + 3.14159274f);
        lineEnd.y = lineStart.y;
        lineEnd.z = center->z + radius * sinf(angle + 3.14159274f);
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
typedef int (*prim_code)(...);
#ifndef CONCAT11
#define CONCAT11(hi, lo) ((u16)((((u16)(u8)(hi)) << 8) | (u8)(lo)))
#endif
#ifndef CONCAT12
#define CONCAT12(hi, lo) ((u32)((((u32)(u8)(hi)) << 16) | (u16)(lo)))
#endif
extern float fGpffff8028;
extern u8 gp0xffff9d68;
extern u8 LAB_0035aa10;
extern u8 LAB_0035a850;
extern void FUN_004c33d0(u8* out, int src, int mode);
extern void FUN_004c2f30(u64 dst, u8* a, float* b);
extern long FUN_004c1750(u64 stream, void* buf, int size);
extern long FUN_004c17f0(u64 stream, void* buf, int size);
extern long FUN_004c18b0(u64 stream, void* buf, int size);
extern long FUN_004c1910(u64 stream, void* buf, int size);
extern long FUN_004b6680(void* desc);
extern void FUN_005225a8(u8* fmt, ...);
void FUN_0035a290(u64 param_1,int param_2);
void FUN_0035a3f0(float param_1,int param_2,int param_3,int param_4);
void FUN_0035a620(float param_1,int param_2,int param_3,int param_4);
u32 FUN_0035a6a0(int param_1,u64 param_2);
u64 FUN_0035a770(u64 param_1,u64 param_2);
void FUN_0035a870(int param_1,int param_2);

// FUN_0035A290 NONMATCHING


void FUN_0035a290(u64 param_1,int param_2)



{

  int iVar1;

  float fVar2;

  u32 uVar3;

  float fVar4;

  u32 uVar5;

  float fVar6;

  float fVar7;

  float fStack_80;

  float fStack_7c;

  float fStack_78;

  u32 uStack_74;

  float fStack_70;

  float fStack_6c;

  float fStack_68;

  float fStack_60;

  float fStack_5c;

  float fStack_58;

  u32 uStack_50;

  u32 uStack_4c;

  u32 uStack_48;

  u8 auStack_40 [64];

  

  fVar6 = *(float *)(param_2 + 8);

  fVar7 = *(float *)(param_2 + 0xc);

  fVar2 = *(float *)(param_2 + 0x10);

  fVar4 = *(float *)(param_2 + 0x14);

  fStack_80 = 1.0 - (fVar7 * fVar7 + fVar2 * fVar2) * 2.0;

  fStack_7c = (fVar6 * fVar7 + fVar4 * fVar2) * 2.0;

  fStack_78 = (fVar2 * fVar6 - fVar4 * fVar7) * 2.0;

  fStack_70 = (fVar6 * fVar7 - fVar4 * fVar2) * 2.0;

  fStack_6c = 1.0 - (fVar6 * fVar6 + fVar2 * fVar2) * 2.0;

  fStack_68 = (fVar7 * fVar2 + fVar4 * fVar6) * 2.0;

  fStack_60 = (fVar2 * fVar6 + fVar4 * fVar7) * 2.0;

  fStack_5c = (fVar7 * fVar2 - fVar4 * fVar6) * 2.0;

  fStack_58 = 1.0 - (fVar6 * fVar6 + fVar7 * fVar7) * 2.0;

  uStack_50 = 0;

  uStack_4c = 0;

  uStack_48 = 0;

  uStack_74 = 3;

  FUN_004c33d0(auStack_40,param_2 + 0x24,0);

  FUN_004c2f30(param_1,auStack_40,&fStack_80);

  uVar3 = *(u32 *)(param_2 + 0x1c);

  uVar5 = *(u32 *)(param_2 + 0x20);

  iVar1 = (int)param_1;

  *(u32 *)(iVar1 + 0x30) = *(u32 *)(param_2 + 0x18);

  *(u32 *)(iVar1 + 0x34) = uVar3;

  *(u32 *)(iVar1 + 0x38) = uVar5;

  *(u32 *)(iVar1 + 0xc) = *(u32 *)(iVar1 + 0xc) & 0xfffdffff;

  return;

}

// FUN_0035A3F0 NONMATCHING


void FUN_0035a3f0(float param_1,int param_2,int param_3,int param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  

  fVar2 = *(float *)(param_3 + 0x14) * *(float *)(param_4 + 0x14) +

          *(float *)(param_3 + 0x10) * *(float *)(param_4 + 0x10) +

          *(float *)(param_3 + 8) * *(float *)(param_4 + 8) +

          *(float *)(param_3 + 0xc) * *(float *)(param_4 + 0xc);

  if (fVar2 < 0.0) {

    fVar2 = -fVar2;

    *(float *)(param_4 + 8) = -*(float *)(param_4 + 8);

    *(float *)(param_4 + 0xc) = -*(float *)(param_4 + 0xc);

    *(float *)(param_4 + 0x10) = -*(float *)(param_4 + 0x10);

    *(float *)(param_4 + 0x14) = -*(float *)(param_4 + 0x14);

  }

  fVar3 = 1.0 - param_1;

  if (fVar2 < fGpffff8028) {

    fVar2 = (float)FUN_0052e9e8();

    fVar1 = (float)FUN_0052e878(fVar2);

    fVar1 = 1.0 / fVar1;

    fVar3 = (float)FUN_0052e878(fVar3 * fVar2);

    fVar3 = fVar1 * fVar3;

    param_1 = (float)FUN_0052e878(param_1 * fVar2);

    param_1 = fVar1 * param_1;

  }

  *(float *)(param_2 + 8) = fVar3 * *(float *)(param_3 + 8) + param_1 * *(float *)(param_4 + 8);

  *(float *)(param_2 + 0xc) =

       fVar3 * *(float *)(param_3 + 0xc) + param_1 * *(float *)(param_4 + 0xc);

  *(float *)(param_2 + 0x10) =

       fVar3 * *(float *)(param_3 + 0x10) + param_1 * *(float *)(param_4 + 0x10);

  *(float *)(param_2 + 0x14) =

       fVar3 * *(float *)(param_3 + 0x14) + param_1 * *(float *)(param_4 + 0x14);

  *(float *)(param_2 + 0x18) =

       param_1 * (*(float *)(param_4 + 0x18) - *(float *)(param_3 + 0x18)) +

       *(float *)(param_3 + 0x18) + 0.0;

  *(float *)(param_2 + 0x1c) =

       param_1 * (*(float *)(param_4 + 0x1c) - *(float *)(param_3 + 0x1c)) +

       *(float *)(param_3 + 0x1c) + 0.0;

  *(float *)(param_2 + 0x20) =

       param_1 * (*(float *)(param_4 + 0x20) - *(float *)(param_3 + 0x20)) +

       *(float *)(param_3 + 0x20) + 0.0;

  *(float *)(param_2 + 0x24) =

       param_1 * (*(float *)(param_4 + 0x24) - *(float *)(param_3 + 0x24)) +

       *(float *)(param_3 + 0x24) + 0.0;

  *(float *)(param_2 + 0x28) =

       param_1 * (*(float *)(param_4 + 0x28) - *(float *)(param_3 + 0x28)) +

       *(float *)(param_3 + 0x28) + 0.0;

  *(float *)(param_2 + 0x2c) =

       param_1 * (*(float *)(param_4 + 0x2c) - *(float *)(param_3 + 0x2c)) +

       *(float *)(param_3 + 0x2c) + 0.0;

  return;

}

// FUN_0035A620


void FUN_0035a620(float param_1,int param_2,int param_3,int param_4)



{

  FUN_0035a3f0((param_1 - *(float *)(param_3 + 4)) /
               (*(float *)(param_4 + 4) - *(float *)(param_3 + 4)),
               param_2, param_3, param_4);

  *(float *)(param_2 + 0x30) = *(float *)(param_3 + 0x30) * *(float *)(param_4 + 0x30);

  return;

}

// FUN_0035A6A0 NONMATCHING


u32 FUN_0035a6a0(int param_1,u64 param_2)



{

  int iVar1;

  long lVar2;

  int *piVar3;

  int iVar4;

  int iStack_4;

  

  iVar1 = *(int *)(param_1 + 0x10);

  iVar4 = 0;

  while( true ) {

    if (*(int *)(param_1 + 4) <= iVar4) {

      return 1;

    }

    piVar3 = (int *)(iVar1 + iVar4 * 0x34);

    iStack_4 = *piVar3 - iVar1;

    lVar2 = FUN_004c1750(param_2,piVar3 + 1,0x30);

    if ((lVar2 == 0) || (lVar2 = FUN_004c17f0(param_2,&iStack_4,4), lVar2 == 0)) break;

    iVar4 = iVar4 + 1;

  }

  return 0;

}

// FUN_0035A770 NONMATCHING


u64 FUN_0035a770(u64 param_1,u64 param_2)



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

    lVar2 = FUN_004c18b0(param_1,piVar3 + 1,0x30);

    if ((lVar2 == 0) || (lVar2 = FUN_004c1910(param_1,&iStack_4,4), lVar2 == 0)) break;

    *piVar3 = iVar1 + iStack_4;

    iVar4 = iVar4 + 1;

  }

  return 0;

}

// FUN_0035A870 NONMATCHING


void FUN_0035a870(int param_1,int param_2)



{

  float in_f1;

  float in_f0;

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float in_f9;

  float in_f10;

  

  fVar4 = *(float *)(param_1 + 8);

  fVar6 = *(float *)(param_1 + 0xc);

  fVar1 = *(float *)(param_1 + 0x10);

  fVar2 = *(float *)(param_1 + 0x14);

  fVar8 = *(float *)(param_2 + 0xc);

  fVar9 = *(float *)(param_2 + 8);

  fVar5 = *(float *)(param_2 + 0x10);

  fVar7 = *(float *)(param_2 + 0x14);

  fVar3 = fVar7 * fVar7 + fVar5 * fVar5 + fVar9 * fVar9 + fVar8 * fVar8;

  if (0.0 < fVar3) {

    fVar3 = 1.0 / fVar3;

    in_f10 = fVar7 * fVar3;

    fVar3 = -fVar3;

    in_f9 = fVar9 * fVar3;

    in_f1 = fVar8 * fVar3;

    in_f0 = fVar5 * fVar3;

  }

  *(float *)(param_1 + 0x14) = in_f10 * fVar2 - (in_f0 * fVar1 + in_f9 * fVar4 + in_f1 * fVar6);

  *(float *)(param_1 + 8) = in_f1 * fVar1 - in_f0 * fVar6;

  *(float *)(param_1 + 0xc) = in_f0 * fVar4 - in_f9 * fVar1;

  *(float *)(param_1 + 0x10) = in_f9 * fVar6 - in_f1 * fVar4;

  *(float *)(param_1 + 8) = fVar4 * in_f10 + *(float *)(param_1 + 8) + 0.0;

  *(float *)(param_1 + 0xc) = fVar6 * in_f10 + *(float *)(param_1 + 0xc) + 0.0;

  *(float *)(param_1 + 0x10) = fVar1 * in_f10 + *(float *)(param_1 + 0x10) + 0.0;

  *(float *)(param_1 + 8) = in_f9 * fVar2 + *(float *)(param_1 + 8) + 0.0;

  *(float *)(param_1 + 0xc) = in_f1 * fVar2 + *(float *)(param_1 + 0xc) + 0.0;

  *(float *)(param_1 + 0x10) = in_f0 * fVar2 + *(float *)(param_1 + 0x10) + 0.0;

  *(float *)(param_1 + 0x18) = *(float *)(param_1 + 0x18) - *(float *)(param_2 + 0x18);

  *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0x1c) - *(float *)(param_2 + 0x1c);

  *(float *)(param_1 + 0x20) = *(float *)(param_1 + 0x20) - *(float *)(param_2 + 0x20);

  *(float *)(param_1 + 0x24) = *(float *)(param_1 + 0x24) - *(float *)(param_2 + 0x24);

  *(float *)(param_1 + 0x28) = *(float *)(param_1 + 0x28) - *(float *)(param_2 + 0x28);

  *(float *)(param_1 + 0x2c) = *(float *)(param_1 + 0x2c) - *(float *)(param_2 + 0x2c);

  return;

}

// FUN_0035ABA0 NONMATCHING


u32 FUN_0035aba0(void)



{

  long lVar1;

  u32 uStack_30;

  u32 uStack_2c;

  u32 uStack_28;

  prim_code pcStack_24;

  prim_code pcStack_20;

  prim_code pcStack_1c;

  u8 *puStack_18;

  prim_code pcStack_14;

  prim_code pcStack_10;

  prim_code pcStack_c;

  u8 *puStack_8;

  u32 uStack_4;

  

  uStack_30 = 0x44a07195;

  uStack_28 = 0x34;

  uStack_2c = 0x34;

  pcStack_24 = (prim_code)FUN_0035a290;

  pcStack_20 = (prim_code)FUN_0035a3f0;

  pcStack_1c = (prim_code)FUN_0035a620;

  puStack_18 = &LAB_0035aa10;

  pcStack_14 = (prim_code)FUN_0035a870;

  pcStack_10 = (prim_code)FUN_0035a770;

  pcStack_c = (prim_code)FUN_0035a6a0;

  puStack_8 = &LAB_0035a850;

  uStack_4 = 0;

  lVar1 = FUN_004b6680(&uStack_30);

  return lVar1 != 0;

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

    while( true ) {

      if (param_4 <= (int)pbVar3 - (int)param_3) {

        return;

      }

      bVar1 = *pbVar3;

      pbVar2 = pbVar3 + 1;

      if ((bVar1 & 1) != 0) break;

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

    for (iVar4 = 0; pbVar3 = pbVar2, iVar4 < ((int)(u32)bVar1 >> 3) + 2; iVar4 = iVar4 + 1) {

      param_1 = param_1 + 1;

      *param_1 = *param_1 + param_2;

    }

  } while( true );

}
