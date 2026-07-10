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

static const char* const* const sBustupNames = (const char* const*)0x005D3350;

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

// FUN_00105800 NONMATCHING
void H_Chrdsp_Init(void)
{
    s16 workIndex = 0;
    s32 stride = 0x670;
    u8* base = (u8*)D_007E2680;
    s16 resourceIndex;
    HChrdspWork* work;

    for (; workIndex < HCHRDP_WORK_COUNT; workIndex++)
    {
        work = (HChrdspWork*)(base + workIndex * stride);
        work->state = HCHRDP_STATE_IDLE;
        work->drawMiddleLayer = 0;
        work->drawTopLayer = 0;

        for (resourceIndex = 0; resourceIndex < HCHRDP_LAYER_COUNT; resourceIndex++)
        {
            work->resources[resourceIndex] = NULL;
        }
    }
}
// FUN_001058A0 NONMATCHING
void H_Chrdsp_Main(void)
{
    s32 workIndex;

    RwRenderStateSet(rwRENDERSTATEZTESTENABLE, true);
    RwRenderStateSet(rwRENDERSTATESHADEMODE, rwSHADEMODEGOURAUD);
    RwRenderStateSet(rwRENDERSTATEZWRITEENABLE, true);
    RwRenderStateSet(rwRENDERSTATEDESTBLEND, rwBLENDINVSRCALPHA);
    RwRenderStateSet(rwRENDERSTATESRCBLEND, rwBLENDSRCALPHA);
    RwRenderStateSet(rwRENDERSTATETEXTUREFILTER, rwFILTERNEAREST);
    RwRenderStateSet(rwRENDERSTATETEXTUREADDRESS, rwTEXTUREADDRESSBORDER);

    for (workIndex = 0; workIndex < HCHRDP_WORK_COUNT; workIndex++)
    {
        H_Chrdsp_UpdateWork(&D_007E2680[workIndex]);
    }
}

// FUN_001059B0 NONMATCHING
void H_Chrdsp_UpdateWork(HChrdspWork* work)
{
    switch (work->state)
    {
    case HCHRDP_STATE_LOAD_ARCHIVE:
        H_Chrdsp_LoadArchiveLayer(work);
        break;

    case HCHRDP_STATE_PARSE_LAYER:
        H_Chrdsp_ParseLayer(work);
        break;

    case HCHRDP_STATE_DRAW:
        H_Chrdsp_Draw(work);
        break;

    case HCHRDP_STATE_IDLE:
    case HCHRDP_STATE_UNAVAILABLE:
    default:
        break;
    }
}

// FUN_00106730 NONMATCHING
void func_00106730(s16 index)
{
    HChrdspWork* work;
    s32 resourceIndex;

    printf("!!! RELEASE CHAR %d\n", index);

    work = &D_007E2680[index];
    if (work->asyncRequest != NULL)
    {
        func_00133d30(work->asyncRequest, work->archive);
        work->asyncRequest = NULL;
        work->archive = NULL;
    }
    else if (work->archive != NULL)
    {
        H_Cdvd_Destroy(work->archive);
        work->archive = NULL;
    }

    for (resourceIndex = 0; resourceIndex < HCHRDP_LAYER_COUNT; resourceIndex++)
    {
        if (work->resources[resourceIndex] != NULL)
        {
            func_004d0f00(work->resources[resourceIndex]);
            work->resources[resourceIndex] = NULL;
        }
    }

    work->state = HCHRDP_STATE_IDLE;
}

// FUN_00106860 NONMATCHING
void func_00106860(s16 index, s16 characterId, s16 layer, s16 variant)
{
    HChrdspWork* work;
    char path[256];
    s32 entryIndex;

    printf("!!! READ DISP2  %d\n", index);

    work = &D_007E2680[index];
    work->resourceIndex = 0;
    work->characterId = characterId;
    work->reserved08 = layer;
    work->variant = variant;
    func_00106730(index);

    if (layer < HCHRDP_LAYER_COUNT)
    {
        if (clndIsDateInRange(6, 1, 9, 30) != 0)
        {
            if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
            {
                sprintf(path, "i_bust_%02d_%x%1da.tmx", characterId, layer, variant);
            }
            else if (characterId == 9)
            {
                sprintf(path, "i_bust_29_%x%1da.tmx", layer, variant);
            }
            else
            {
                sprintf(path, "i_bust_%02d_%x%1da.tmx", characterId, layer, variant);
            }
        }
        else if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
        {
            sprintf(path, "i_bust_%02d_%x%1db.tmx", characterId, layer, variant);
        }
        else if (characterId == 9)
        {
            sprintf(path, "i_bust_29_%x%1db.tmx", layer, variant);
        }
        else
        {
            sprintf(path, "i_bust_%02d_%x%1db.tmx", characterId, layer, variant);
        }
    }
    else if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
    {
        sprintf(path, "i_bust_%02d_%x%1d.tmx", characterId, layer, variant);
    }
    else if (characterId == 9)
    {
        sprintf(path, "i_bust_29_%x%1d.tmx", layer, variant);
    }
    else
    {
        sprintf(path, "i_bust_%02d_%x%1d.tmx", characterId, layer, variant);
    }

    for (entryIndex = 0; entryIndex < 0x1388; entryIndex++)
    {
        if (sBustupNames[entryIndex][0] == '\0')
        {
            sprintf(path, "bustup/bust_dummy.bin");
            break;
        }

        if (strcmp(sBustupNames[entryIndex], path) == 0)
        {
            if (layer < HCHRDP_LAYER_COUNT)
            {
                if (clndIsDateInRange(6, 1, 9, 30) != 0)
                {
                    if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
                    {
                        sprintf(path, "bustup/i_b_%02d%x%1da.bin", characterId, layer, variant);
                    }
                    else if (characterId == 9)
                    {
                        sprintf(path, "bustup/i_b_29%x%1da.bin", layer, variant);
                    }
                    else
                    {
                        sprintf(path, "bustup/i_b_%02d%x%1da.bin", characterId, layer, variant);
                    }
                }
                else if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
                {
                    sprintf(path, "bustup/i_b_%02d%x%1db.bin", characterId, layer, variant);
                }
                else if (characterId == 9)
                {
                    sprintf(path, "bustup/i_b_29%x%1db.bin", layer, variant);
                }
                else
                {
                    sprintf(path, "bustup/i_b_%02d%x%1db.bin", characterId, layer, variant);
                }
            }
            else if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
            {
                sprintf(path, "bustup/i_b_%02d%x%1d.bin", characterId, layer, variant);
            }
            else if (characterId == 9)
            {
                sprintf(path, "bustup/i_b_29%x%1d.bin", layer, variant);
            }
            else
            {
                sprintf(path, "bustup/i_b_%02d%x%1d.bin", characterId, layer, variant);
            }
            break;
        }
    }

    strcpy(work->texturePath, path);
    work->state = HCHRDP_STATE_LOAD_ARCHIVE;
    work->archive = H_Cdvd_Request(work->texturePath, HCDVD_FILEARCHIVE);
    work->color.r = 255;
    work->color.g = 255;
    work->color.b = 255;
    work->color.a = 255;
    work->layerWidth = 1.0f;
    work->layerHeight = 1.0f;
    work->usesCustomPath = true;
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
