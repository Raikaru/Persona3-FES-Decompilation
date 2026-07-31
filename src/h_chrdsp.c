#include "h_chrdsp.h"
#include "h_cdvd.h"
#include "Kernel/Kwln/kwln.h"
#include "Main/g_data.h"
#include "temporary.h"

#define HCHRDP_WORK_COUNT 3
#define HCHRDP_LAYER_COUNT 3
#define HCHRDP_QUAD_COUNT  5

#define rwTEXTUREADDRESSBORDER 4

typedef struct HChrdspTexture
{
    RwRaster* raster;
    u8 reserved04[0x4c];
    u32 renderFlags;
} HChrdspTexture;

extern HChrdspWork D_007E2680[HCHRDP_WORK_COUNT];
#pragma alias D_00960090_abs D_00960090
extern void (*D_00960090_abs[])(u32 state, u32 value);
typedef void (*HChrdspDrawPrimitive)(s32 primitiveType, RwIm2DVertex* vertices,
                                     s32 vertexCount);
#pragma alias hChrdspDrawPrimitiveSlot D_009600A0
extern HChrdspDrawPrimitive hChrdspDrawPrimitiveSlot[];
extern void* D_007E2BA8[][0x19C];
extern void* D_007E2BC8[][0x19C];
extern s16 D_007E2684[][0x338];
extern s16 D_007E2688[][0x338];
extern s16 D_007E268A[][0x338];
extern s32 D_007E2BCC[][0x19C];
extern u8 D_007E2BA0[][0x670];
extern u8 D_007E2BA1[][0x670];
extern u8 D_007E2BA2[][0x670];
extern u8 D_007E2BA3[][0x670];
extern f32 D_007E2BAC[][0x19C];
extern f32 D_007E2BB0[][0x19C];
extern u32 D_007E2BE4[][0x19C];
extern const char* D_005D3350[];
extern const char D_005D3CB0[];
extern const char D_005D3CD0[];
extern const char D_005D3CF0[];
extern const char D_005D3D10[];
extern const char D_005D3D30[];
extern const char D_005D3D50[];
extern const char D_005D3D70[];
extern const char D_005D3D90[];
extern const char D_005D3DB0[];
extern const char D_005D3DD0[];
extern const char D_005D3DF0[];
extern const char D_005D3E10[];
extern const char D_005D3E30[];
extern const char D_005D3E50[];
extern const char D_005D3E70[];
extern const char* func_001022e0(HCdvd* cdvd, s32 entryIndex);
extern void* func_0010c1a0(s32 kind, const char* name, const char* path,
                            s32 requestFlags, void* source, void* buffer,
                            s32 byteCount, const char* cacheName,
                            void* result2, void* result3, void* result4);
extern void* func_0010c3a0(void* request, u32* isReady, s32* byteCount);
extern s32 sprintf(char* buffer, const char* format, ...);
extern s32 printf(const char* format, ...);
extern char* strcpy(char* destination, const char* source);
extern s32 strcmp(const char* lhs, const char* rhs);
extern void func_00133d30(void* stream, HCdvd* cdvd);
extern void func_004d0f00(void* resource);


static void H_Chrdsp_BuildQuad(RwIm2DVertex* vertices, f32 x, f32 y, f32 width,
                                f32 height, f32 z, f32 recipZ, const RwRGBA* color)
{
    s32 vertexIndex;

    for (vertexIndex = 0; vertexIndex < 4; vertexIndex++)
    {
        vertices[vertexIndex].u.els.scrVertex.z = z;
        vertices[vertexIndex].u.els.recipZ = recipZ;
        vertices[vertexIndex].u.els.color.r = (f32)color->r;
        vertices[vertexIndex].u.els.color.g = (f32)color->g;
        vertices[vertexIndex].u.els.color.b = (f32)color->b;
        vertices[vertexIndex].u.els.color.a = (f32)color->a;
    }

    vertices[0].u.els.scrVertex.x = x;
    vertices[0].u.els.scrVertex.y = y;
    vertices[0].u.els.u = 0.0f;
    vertices[0].u.els.v = 0.0f;

    vertices[1].u.els.scrVertex.x = x + width;
    vertices[1].u.els.scrVertex.y = y;
    vertices[1].u.els.u = 1.0f;
    vertices[1].u.els.v = 0.0f;

    vertices[2].u.els.scrVertex.x = x;
    vertices[2].u.els.scrVertex.y = y + height;
    vertices[2].u.els.u = 0.0f;
    vertices[2].u.els.v = 1.0f;

    vertices[3].u.els.scrVertex.x = x + width;
    vertices[3].u.els.scrVertex.y = y + height;
    vertices[3].u.els.u = 1.0f;
    vertices[3].u.els.v = 1.0f;
}

static void H_Chrdsp_RenderTexture(HChrdspTexture* texture, RwIm2DVertex* vertices)
{
    RwRenderStateSet(rwRENDERSTATETEXTURERASTER, texture->raster);
    RwIm2DRenderPrimitive(rwPRIMTYPETRISTRIP, vertices, 4);
}

static s32 H_Chrdsp_GetFadeFrames(s32 index)
{
    switch (index)
    {
    case 0:
        return 3;
    case 1:
        return 100;
    case 2:
    case 3:
    case 4:
        return 2;
    default:
        return 80;
    }
}

static f32 H_Chrdsp_GetOverlayYOffset(const HChrdspWork* work)
{
    switch (work->characterId)
    {
    case 15:
        return 189.0f;
    case 10:
        return 149.0f;
    case 39:
        return 81.0f;
    case 30:
        return 100.0f;
    case 42:
        return 76.0f;
    case 48:
        return 97.0f;
    case 12:
        return 134.0f;
    case 9:
        return 122.0f;
    case 5:
        if ((work->variant == 4) || (work->variant == 5) || (work->variant == 6))
        {
            return 101.0f;
        }
        return 111.0f;
    case 8:
        return 130.0f;
    case 6:
        return 116.0f;
    case 13:
        return 119.0f;
    case 27:
        return 136.0f;
    default:
        return 111.0f;
    }
}

static void H_Chrdsp_AdvanceAlphaTimer(HChrdspWork* work)
{
    work->alphaTimer--;
    if (work->alphaTimer > 0)
    {
        return;
    }

    work->alphaPhase = work->alphaPhase == 0;
    work->alphaIndex++;
    if (work->alphaIndex >= 6)
    {
        work->alphaIndex = 0;
    }
    work->alphaTimer = H_Chrdsp_GetFadeFrames(work->alphaIndex);
}

static void H_Chrdsp_Draw(HChrdspWork* work)
{
    RwIm2DVertex overlayVertices[4];
    RwCamera* camera;
    RwV2d position;
    f32 recipZ;
    f32 z;
    f32 primaryWidth;
    f32 primaryHeight;
    f32 overlayWidth;
    f32 overlayHeight;
    f32 overlayYOffset;
    s32 quadIndex;

    camera = kwlnGetMainCamera();
    recipZ = 1.0f / camera->nearPlane;
    z = RwIm2DGetNearScreenZ() - work->zOffset;
    position = work->position;
    if (work->characterId == 39)
    {
        position.y += 48.0f;
    }

    primaryWidth = work->layerWidth * 4.0f;
    primaryHeight = work->layerHeight * 4.0f;
    for (quadIndex = 0; quadIndex < HCHRDP_QUAD_COUNT; quadIndex++)
    {
        H_Chrdsp_BuildQuad(work->vertices[quadIndex],
                            position.x + 256.0f - primaryWidth / 2.0f,
                            position.y + 256.0f - primaryHeight / 2.0f,
                            primaryWidth - 1.0f, primaryHeight - 1.0f,
                            z, recipZ, &work->color);
    }
    H_Chrdsp_RenderTexture((HChrdspTexture*)work->resources[0], work->vertices[0]);

    if ((work->resourceIndex < 2) || (work->color.a != 255) || (work->drawMiddleLayer == 0))
    {
        return;
    }

    H_Chrdsp_AdvanceAlphaTimer(work);

    overlayWidth = work->layerWidth * 4.0f;
    overlayHeight = work->layerHeight * 128.0f;
    overlayYOffset = H_Chrdsp_GetOverlayYOffset(work);
    H_Chrdsp_BuildQuad(overlayVertices,
                        position.x + 256.0f - overlayWidth / 2.0f,
                        position.y + 32.0f - overlayHeight / 2.0f + overlayYOffset,
                        overlayWidth - 1.0f, overlayHeight - 1.0f,
                        z, recipZ, &work->color);
    H_Chrdsp_RenderTexture((HChrdspTexture*)work->resources[1], overlayVertices);

    if ((work->resourceIndex < HCHRDP_LAYER_COUNT) || (work->color.a != 255) ||
        (work->drawTopLayer == 0))
    {
        return;
    }

    H_Chrdsp_BuildQuad(overlayVertices,
                        position.x + 256.0f - overlayWidth / 2.0f,
                        position.y + 32.0f - overlayHeight / 2.0f + overlayYOffset + 155.0f,
                        overlayWidth - 1.0f, overlayHeight - 1.0f,
                        z, recipZ, &work->color);
    H_Chrdsp_RenderTexture((HChrdspTexture*)work->resources[2], overlayVertices);
}

static void H_Chrdsp_LoadArchiveLayer(HChrdspWork* work)
{
    char archivePath[256];
    const char* archiveEntry;

    if (H_Cdvd_IsFileLoaded(work->archive) == 0)
    {
        return;
    }

    if (work->usesCustomPath == 0)
    {
        if ((datGetScenarioMode() != 0) && (work->characterId == 9))
        {
            sprintf(archivePath, "test/char/i_bust29_%1d", work->resourceIndex);
        }
        else
        {
            sprintf(archivePath, "test/char/i_bust%02d_%1d", work->characterId,
                    work->resourceIndex);
        }
    }

    archiveEntry = func_001022e0(work->archive, work->resourceIndex);
    if (archiveEntry == NULL)
    {
        H_Cdvd_Destroy(work->archive);
        work->archive = NULL;
        work->state = HCHRDP_STATE_UNAVAILABLE;
        return;
    }

    sprintf(work->texturePath, "bustup/%s", archiveEntry);
    work->asyncRequest = func_0010c1a0(0, work->texturePath, NULL, 0, NULL, NULL, 0,
                                       NULL, "h_chrdsp.c", NULL, (void*)0x9F);
    work->state = HCHRDP_STATE_PARSE_LAYER;
}

static void H_Chrdsp_ParseLayer(HChrdspWork* work)
{
    HChrdspTexture* texture;
    u32 isReady;

    isReady = false;
    texture = (HChrdspTexture*)func_0010c3a0(work->asyncRequest, &isReady, NULL);
    work->resources[work->resourceIndex] = texture;
    if (isReady == false)
    {
        return;
    }

    texture->renderFlags = (texture->renderFlags & 0xFFFF00FF) | 0x00003300;
    work->asyncRequest = NULL;
    work->resourceIndex++;
    work->state = HCHRDP_STATE_LOAD_ARCHIVE;
}

/* Removing this loses FUN_00105800 (MATCH nd0 -> MISMATCH nd42) - measured W161. */
#pragma opt_loop_invariants on
// FUN_00105800
void H_Chrdsp_Init(void)
{
    s16 workIndex;
    s16 resourceIndex;
    s32 offset;
    HChrdspWork* work;

    for (workIndex = 0; workIndex < HCHRDP_WORK_COUNT; workIndex++)
    {
        offset = (long)workIndex;
        offset *= 0x670;
        work = (HChrdspWork*)((u8*)D_007E2680 + offset);
        work->state = HCHRDP_STATE_IDLE;
        work->drawMiddleLayer = 0;
        work->drawTopLayer = 0;

        for (resourceIndex = 0; resourceIndex < HCHRDP_LAYER_COUNT; resourceIndex++)
        {
            work->resources[resourceIndex] = NULL;
        }
    }
}
#pragma opt_loop_invariants reset
// FUN_001058A0
void H_Chrdsp_Main(void)
{
    s16 workIndex;
    void (**setRenderState)(u32 state, u32 value);
    setRenderState = (void (**)(u32, u32))D_00960090_abs;
    (*setRenderState)(6, 1);
    (*setRenderState)(7, 2);
    (*setRenderState)(8, 1);
    (*setRenderState)(0xB, 6);
    (*setRenderState)(0xA, 5);
    (*setRenderState)(9, 1);
    (*setRenderState)(0xC, 1);
    (*setRenderState)(2, 4);

    for (workIndex = 0; workIndex < HCHRDP_WORK_COUNT; workIndex++)
    {
        H_Chrdsp_UpdateWork(&D_007E2680[workIndex]);
    }
}

/* Removing this worsens FUN_001059b0 (nd2207 -> nd2247) - measured W161. */
#pragma opt_loop_invariants on
/* W377 six-knob/pair probe: opt_dead_assignments off improved H_Chrdsp_UpdateWork from nd2476/object3180 to nd2469/object3160; window=3456. */
#pragma opt_dead_assignments off
// FUN_001059B0 NONMATCHING
void H_Chrdsp_UpdateWork(HChrdspWork* work)
{
    char archivePath[256];
    RwIm2DVertex overlayVertices[4];
    const char* archiveEntry;
    HChrdspTexture* texture;
    RwCamera* camera;
    void (**setRenderState)(u32 state, u32 value);
    HChrdspDrawPrimitive* drawPrimitive;
    RwV2d position;
    f32 recipZ;
    f32 z;
    f32 overlayYOffset;
    s32 quadIndex;
    s32 vertexIndex;
    u32 isReady;
    switch (work->state)
    {

    case HCHRDP_STATE_IDLE:
        break;
    case HCHRDP_STATE_LOAD_ARCHIVE:
        if (H_Cdvd_IsFileLoaded(work->archive) == 0)
        {
            break;
        }
        if (work->usesCustomPath == 0)
        {
            if (datGetScenarioMode() == 0)
            {
                sprintf(archivePath, "test/char/i_bust%02d_%1d",
                        work->characterId, work->resourceIndex);
            }
            else if (work->characterId == 9)
            {
                sprintf(archivePath, "test/char/i_bust29_%1d",
                        work->resourceIndex);
            }
            else
            {
                sprintf(archivePath, "test/char/i_bust%02d_%1d",
                        work->characterId, work->resourceIndex);
            }
        }
        archiveEntry = func_001022e0(work->archive, work->resourceIndex);
        if (archiveEntry == NULL)
        {
            H_Cdvd_Destroy(work->archive);
            work->archive = NULL;
            work->state = HCHRDP_STATE_UNAVAILABLE;
            break;
        }
        archiveEntry = func_001022e0(work->archive, work->resourceIndex);
        sprintf(work->texturePath, "bustup/%s", archiveEntry);
        work->asyncRequest = func_0010c1a0(0, work->texturePath, NULL, 0, NULL,
                                           NULL, 0, NULL, "h_chrdsp.c", NULL,
                                           (void*)0x9F);
        work->state = HCHRDP_STATE_PARSE_LAYER;
        break;

    case HCHRDP_STATE_PARSE_LAYER:
        work->resources[work->resourceIndex] =
            (HChrdspTexture*)func_0010c3a0(work->asyncRequest, &isReady, NULL);
        if (isReady == false)
        {
            break;
        }
        ((HChrdspTexture*)work->resources[work->resourceIndex])->renderFlags =
            (((HChrdspTexture*)work->resources[work->resourceIndex])->renderFlags &
             0xFFFF00FF) | 0x00003300;
        work->asyncRequest = NULL;
        work->resourceIndex++;
        work->state = HCHRDP_STATE_LOAD_ARCHIVE;
        break;

    case HCHRDP_STATE_UNAVAILABLE:
        break;
    case HCHRDP_STATE_DRAW:
    {
        setRenderState = (void (**)(u32, u32))D_00960090_abs;
        drawPrimitive = hChrdspDrawPrimitiveSlot;
        camera = kwlnGetMainCamera();
        recipZ = 1.0f / camera->nearPlane;
        z = RwIm2DGetNearScreenZ() - work->zOffset;
        position = work->position;
        if (work->characterId == 39)
        {
            position.y += 48.0f;
        }

        for (quadIndex = 0; quadIndex < HCHRDP_QUAD_COUNT; quadIndex++)
        {
            for (vertexIndex = 0; vertexIndex < 4; vertexIndex++)
            {
                work->vertices[quadIndex][vertexIndex].u.els.color.r =
                    (f32)work->color.r;
                work->vertices[quadIndex][vertexIndex].u.els.color.g =
                    (f32)work->color.g;
                work->vertices[quadIndex][vertexIndex].u.els.color.b =
                    (f32)work->color.b;
                work->vertices[quadIndex][vertexIndex].u.els.color.a =
                    (f32)work->color.a;
                work->vertices[quadIndex][vertexIndex].u.els.scrVertex.z =
                    z;
                work->vertices[quadIndex][vertexIndex].u.els.recipZ = recipZ;
            }

            work->vertices[quadIndex][0].u.els.scrVertex.x =
                position.x + 256.0f - work->layerWidth * 512.0f / 2.0f;
            work->vertices[quadIndex][0].u.els.scrVertex.y =
                position.y + 256.0f - work->layerHeight * 512.0f / 2.0f;
            work->vertices[quadIndex][0].u.els.u = 0.0f;
            work->vertices[quadIndex][0].u.els.v = 0.0f;
            work->vertices[quadIndex][1].u.els.scrVertex.x =
                position.x + 256.0f + work->layerWidth * 512.0f / 2.0f - 1.0f;
            work->vertices[quadIndex][1].u.els.scrVertex.y =
                position.y + 256.0f - work->layerHeight * 512.0f / 2.0f;
            work->vertices[quadIndex][1].u.els.u = 1.0f;
            work->vertices[quadIndex][1].u.els.v = 0.0f;
            work->vertices[quadIndex][2].u.els.scrVertex.x =
                position.x + 256.0f - work->layerWidth * 512.0f / 2.0f;
            work->vertices[quadIndex][2].u.els.scrVertex.y =
                position.y + 256.0f + work->layerHeight * 512.0f / 2.0f - 1.0f;
            work->vertices[quadIndex][2].u.els.u = 0.0f;
            work->vertices[quadIndex][2].u.els.v = 1.0f;
            work->vertices[quadIndex][3].u.els.scrVertex.x =
                position.x + 256.0f + work->layerWidth * 512.0f / 2.0f - 1.0f;
            work->vertices[quadIndex][3].u.els.scrVertex.y =
                position.y + 256.0f + work->layerHeight * 512.0f / 2.0f - 1.0f;
            work->vertices[quadIndex][3].u.els.u = 1.0f;
            work->vertices[quadIndex][3].u.els.v = 1.0f;
        }
        (*setRenderState)(1, (u32)((HChrdspTexture*)work->resources[0])->raster);
        (*drawPrimitive)(rwPRIMTYPETRISTRIP, work->vertices[0], 4);

        if ((work->resourceIndex < 2) || (work->color.a != 255) ||
            (work->drawMiddleLayer == 0))
        {
            break;
        }

        work->alphaTimer--;
        if (work->alphaTimer <= 0)
        {
            work->alphaPhase = work->alphaPhase == 0;
            work->alphaIndex++;
            if (work->alphaIndex >= 6)
            {
                work->alphaIndex = 0;
            }
            switch (work->alphaIndex)
            {
            case 0:
                work->alphaTimer = 3;
                break;
            case 1:
                work->alphaTimer = 100;
                break;
            case 2:
            case 3:
            case 4:
                work->alphaTimer = 2;
                break;
            default:
                work->alphaTimer = 80;
                break;
            }
        }

        switch (work->characterId)
        {
        case 15:
            overlayYOffset = 189.0f;
            break;
        case 10:
            overlayYOffset = 149.0f;
            break;
        case 39:
            overlayYOffset = 81.0f;
            break;
        case 30:
            overlayYOffset = 100.0f;
            break;
        case 42:
            overlayYOffset = 76.0f;
            break;
        case 48:
            overlayYOffset = 97.0f;
            break;
        case 12:
            overlayYOffset = 134.0f;
            break;
        case 9:
            overlayYOffset = 122.0f;
            break;
        case 5:
            if ((work->variant == 4) || (work->variant == 5) ||
                (work->variant == 6))
            {
                overlayYOffset = 101.0f;
            }
            else
            {
                overlayYOffset = 111.0f;
            }
            break;
        case 8:
            overlayYOffset = 130.0f;
            break;
        case 6:
            overlayYOffset = 116.0f;
            break;
        case 13:
            overlayYOffset = 119.0f;
            break;
        case 27:
            overlayYOffset = 136.0f;
            break;
        default:
            overlayYOffset = 111.0f;
            break;
        }

        for (vertexIndex = 0; vertexIndex < 4; vertexIndex++)
        {
            overlayVertices[vertexIndex].u.els.scrVertex.z =
                z;
            overlayVertices[vertexIndex].u.els.recipZ = recipZ;
            overlayVertices[vertexIndex].u.els.color.r = (f32)work->color.r;
            overlayVertices[vertexIndex].u.els.color.g = (f32)work->color.g;
            overlayVertices[vertexIndex].u.els.color.b = (f32)work->color.b;
            overlayVertices[vertexIndex].u.els.color.a = (f32)work->color.a;
        }
        overlayVertices[0].u.els.scrVertex.x =
            position.x + 256.0f - work->layerWidth * 512.0f / 2.0f;
        overlayVertices[0].u.els.scrVertex.y =
            position.y + 32.0f - work->layerHeight * 64.0f / 2.0f +
            overlayYOffset;
        overlayVertices[0].u.els.u = 0.0f;
        overlayVertices[0].u.els.v = 0.0f;
        overlayVertices[1].u.els.scrVertex.x =
            position.x + 256.0f + work->layerWidth * 512.0f / 2.0f - 1.0f;
        overlayVertices[1].u.els.scrVertex.y =
            position.y + 32.0f - work->layerHeight * 64.0f / 2.0f +
            overlayYOffset;
        overlayVertices[1].u.els.u = 1.0f;
        overlayVertices[1].u.els.v = 0.0f;
        overlayVertices[2].u.els.scrVertex.x =
            position.x + 256.0f - work->layerWidth * 512.0f / 2.0f;
        overlayVertices[2].u.els.scrVertex.y =
            position.y + 32.0f + work->layerHeight * 64.0f / 2.0f - 1.0f +
            overlayYOffset;
        overlayVertices[2].u.els.u = 0.0f;
        overlayVertices[2].u.els.v = 1.0f;
        overlayVertices[3].u.els.scrVertex.x =
            position.x + 256.0f + work->layerWidth * 512.0f / 2.0f - 1.0f;
        overlayVertices[3].u.els.scrVertex.y =
            position.y + 32.0f + work->layerHeight * 64.0f / 2.0f - 1.0f +
            overlayYOffset;
        overlayVertices[3].u.els.u = 1.0f;
        overlayVertices[3].u.els.v = 1.0f;
        (*setRenderState)(1, (u32)((HChrdspTexture*)work->resources[1])->raster);
        (*drawPrimitive)(rwPRIMTYPETRISTRIP, overlayVertices, 4);

        if ((work->resourceIndex < HCHRDP_LAYER_COUNT) ||
            (work->color.a != 255) || (work->drawTopLayer == 0))
        {
            break;
        }

        for (vertexIndex = 0; vertexIndex < 4; vertexIndex++)
        {
            overlayVertices[vertexIndex].u.els.scrVertex.z =
                z;
            overlayVertices[vertexIndex].u.els.recipZ = recipZ;
            overlayVertices[vertexIndex].u.els.color.r = (f32)work->color.r;
            overlayVertices[vertexIndex].u.els.color.g = (f32)work->color.g;
            overlayVertices[vertexIndex].u.els.color.b = (f32)work->color.b;
            overlayVertices[vertexIndex].u.els.color.a = (f32)work->color.a;
        }
        overlayVertices[0].u.els.scrVertex.x =
            position.x + 256.0f - work->layerWidth * 512.0f / 2.0f;
        overlayVertices[0].u.els.scrVertex.y =
            position.y + 32.0f - work->layerHeight * 64.0f / 2.0f +
            overlayYOffset + 155.0f;
        overlayVertices[0].u.els.u = 0.0f;
        overlayVertices[0].u.els.v = 0.0f;
        overlayVertices[1].u.els.scrVertex.x =
            position.x + 256.0f + work->layerWidth * 512.0f / 2.0f - 1.0f;
        overlayVertices[1].u.els.scrVertex.y =
            position.y + 32.0f - work->layerHeight * 64.0f / 2.0f +
            overlayYOffset + 155.0f;
        overlayVertices[1].u.els.u = 1.0f;
        overlayVertices[1].u.els.v = 0.0f;
        overlayVertices[2].u.els.scrVertex.x =
            position.x + 256.0f - work->layerWidth * 512.0f / 2.0f;
        overlayVertices[2].u.els.scrVertex.y =
            position.y + 32.0f + work->layerHeight * 64.0f / 2.0f - 1.0f +
            overlayYOffset + 155.0f;
        overlayVertices[2].u.els.u = 0.0f;
        overlayVertices[2].u.els.v = 1.0f;
        overlayVertices[3].u.els.scrVertex.x =
            position.x + 256.0f + work->layerWidth * 512.0f / 2.0f - 1.0f;
        overlayVertices[3].u.els.scrVertex.y =
            position.y + 32.0f + work->layerHeight * 64.0f / 2.0f - 1.0f +
            overlayYOffset + 155.0f;
        overlayVertices[3].u.els.u = 1.0f;
        overlayVertices[3].u.els.v = 1.0f;
        (*setRenderState)(1, (u32)((HChrdspTexture*)work->resources[2])->raster);
        (*drawPrimitive)(rwPRIMTYPETRISTRIP, overlayVertices, 4);
        break;

    }
    default:
        break;
    }
}
#pragma opt_dead_assignments reset
#pragma opt_loop_invariants reset

// FUN_00106730
void func_00106730(s16 index)
{
    s16 originalIndex;
    s32 resourceIndex;
    HChrdspWork* work;

    originalIndex = index;
    printf(D_005D3CB0, originalIndex);
    if (*(void**)((u8*)D_007E2BC8 + originalIndex * 0x670) != NULL)
    {
        func_00133d30(*(void**)((u8*)D_007E2BC8 + originalIndex * 0x670),
                      *(void**)((u8*)D_007E2BA8 + originalIndex * 0x670));
        *(void**)((u8*)D_007E2BC8 + originalIndex * 0x670) = NULL;
        *(void**)((u8*)D_007E2BA8 + originalIndex * 0x670) = NULL;
    }
    else if (*(void**)((u8*)D_007E2BA8 + originalIndex * 0x670) != NULL)
    {
        H_Cdvd_Destroy(*(HCdvd**)((u8*)D_007E2BA8 + originalIndex * 0x670));
        *(void**)((u8*)D_007E2BA8 + originalIndex * 0x670) = NULL;
    }

    resourceIndex = 0;
    work = (HChrdspWork*)((u8*)D_007E2680 + originalIndex * 0x670);
    while (resourceIndex < HCHRDP_LAYER_COUNT)
    {
        void** resource;

        resource = (void**)((u8*)work + 0x14 + resourceIndex * 4);
        if (*resource != NULL)
        {
            func_004d0f00(*resource);
            *resource = NULL;
        }
        resourceIndex++;
    }
    work->state = HCHRDP_STATE_IDLE;
}

// FUN_00106860
void func_00106860(s16 index, s16 characterId, s16 layer, s16 variant)
{
    char path[256];
    s16 originalIndex;
    s32 signedIndex;
    s32 entryIndex;
    s32 offset;

    originalIndex = index;
    signedIndex = originalIndex;
    printf(D_005D3CD0, signedIndex);

    offset = signedIndex * 0x670;
    *(s32*)((u8*)D_007E2BCC + offset) = 0;
    *(s16*)((u8*)D_007E2684 + offset) = characterId;
    *(s16*)((u8*)D_007E2688 + offset) = layer;
    *(s16*)((u8*)D_007E268A + offset) = variant;
    func_00106730(originalIndex);

    if (layer < HCHRDP_LAYER_COUNT)
    {
        if (clndIsDateInRange(6, 1, 9, 30) != 0)
        {
            if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
            {
                sprintf(path, D_005D3CF0, characterId, layer, variant);
            }
            else if (characterId == 9)
            {
                sprintf(path, D_005D3D10, layer, variant);
            }
            else
            {
                sprintf(path, D_005D3CF0, characterId, layer, variant);
            }
        }
        else if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
        {
            sprintf(path, D_005D3D30, characterId, layer, variant);
        }
        else if (characterId == 9)
        {
            sprintf(path, D_005D3D50, layer, variant);
        }
        else
        {
            sprintf(path, D_005D3D30, characterId, layer, variant);
        }
    }
    else if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
    {
        sprintf(path, D_005D3D70, characterId, layer, variant);
    }
    else if (characterId == 9)
    {
        sprintf(path, D_005D3D90, layer, variant);
    }
    else
    {
        sprintf(path, D_005D3D70, characterId, layer, variant);
    }

    for (entryIndex = 0; entryIndex < 0x1388; entryIndex++)
    {
        if (D_005D3350[entryIndex][0] == '\0')
        {
            sprintf(path, D_005D3DB0);
            break;
        }

        if (strcmp(D_005D3350[entryIndex], path) == 0)
        {
            if (layer < HCHRDP_LAYER_COUNT)
            {
                if (clndIsDateInRange(6, 1, 9, 30) != 0)
                {
                    if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
                    {
                        sprintf(path, D_005D3DD0, characterId, layer, variant);
                    }
                    else if (characterId == 9)
                    {
                        sprintf(path, D_005D3DF0, layer, variant);
                    }
                    else
                    {
                        sprintf(path, D_005D3DD0, characterId, layer, variant);
                    }
                }
                else if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
                {
                    sprintf(path, D_005D3E10, characterId, layer, variant);
                }
                else if (characterId == 9)
                {
                    sprintf(path, D_005D3E30, layer, variant);
                }
                else
                {
                    sprintf(path, D_005D3E10, characterId, layer, variant);
                }
            }
            else if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
            {
                sprintf(path, D_005D3E50, characterId, layer, variant);
            }
            else if (characterId == 9)
            {
                sprintf(path, D_005D3E70, layer, variant);
            }
            else
            {
                sprintf(path, D_005D3E50, characterId, layer, variant);
            }
            break;
        }
    }

    strcpy((char*)((u8*)D_007E2680 + originalIndex * 0x670 + 0x568), path);
    *(s16*)((u8*)D_007E2680 + originalIndex * 0x670) = HCHRDP_STATE_LOAD_ARCHIVE;
    *(void**)((u8*)D_007E2BA8 + originalIndex * 0x670) =
        H_Cdvd_Request((char*)((u8*)D_007E2680 + originalIndex * 0x670 + 0x568),
                       HCDVD_FILEARCHIVE);
    *(u8*)((u8*)D_007E2BA0 + originalIndex * 0x670) = 255;
    *(u8*)((u8*)D_007E2BA1 + originalIndex * 0x670) = 255;
    *(u8*)((u8*)D_007E2BA2 + originalIndex * 0x670) = 255;
    *(u8*)((u8*)D_007E2BA3 + originalIndex * 0x670) = 255;
    *(f32*)((u8*)D_007E2BAC + originalIndex * 0x670) = 1.0f;
    *(f32*)((u8*)D_007E2BB0 + originalIndex * 0x670) = 1.0f;
    *(u32*)((u8*)D_007E2BE4 + originalIndex * 0x670) = true;
}

// FUN_00106e90
void func_00106e90(s16 index, u8 alpha)
{
    D_007E2680[index].color.a = alpha;
}

// FUN_00106ec0
void func_00106ec0(s16 index, void* request)
{
    D_007E2680[index].asyncRequest = request;
    if (request != NULL)
    {
        D_007E2680[index].alphaPhase = 1;
        D_007E2680[index].alphaIndex = 0;
        D_007E2680[index].alphaTimer = 2;
    }
}

// FUN_00106f30
void func_00106f30(s16 index, s32 resourceIndex)
{
    D_007E2680[index].resourceIndex = resourceIndex;
}

// FUN_00106f60
void func_00106f60(s16 index, s16 value)
{
    if (D_007E2680[index].state == HCHRDP_STATE_UNAVAILABLE)
    {
        D_007E2680[index].state = HCHRDP_STATE_DRAW;
    }
    D_007E2680[index].reserved02 = value;
}

// FUN_00106fb0
void func_00106fb0(s16 index, RwV2d position)
{
    D_007E2680[index].position = position;
}

// FUN_00106ff0
u32 func_00106ff0(s16 index)
{
    return D_007E2680[index].state == HCHRDP_STATE_UNAVAILABLE;
}
