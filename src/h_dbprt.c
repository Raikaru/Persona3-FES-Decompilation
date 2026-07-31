#include "h_dbprt.h"
#include "h_cdvd.h"
#include "Kernel/Kwln/kwln.h"
#include "temporary.h"

typedef char* va_list;
#define va_start(ap, last) (ap = ((va_list)__builtin_next_arg(last) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8)))
#define va_end(ap) ((void)0)
extern int vsprintf(char* buffer, const char* fmt, va_list args);

#define HDBPRT_LOG_MAXLINE 15
#define HDBPRT_LOG_MAXCHAR 256
#define HDBPRT_GRID_WIDTH  (640 / 12)
#define HDBPRT_GRID_HEIGHT (480 / 12)

const RwV2d sLogBoxPos = {28.0f, 42.0f};
const RwV2d sLogStringsPos = {36.0f, 50.0f};

static RwRaster* sFontRaster;
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
#pragma alias D_00960088_abs D_00960088
extern volatile /* Removing this file's qualifier batch loses 0 MATCH(es) and worsens 1 other function(s) - measured W170. */ f32 D_00960088_abs[];
extern RwIm2DRenderPrimitiveFunction D_009600A0_abs[];
#pragma alias hDbprtDrawPrimitiveSlot D_009600A0
extern RwIm2DRenderPrimitiveFunction hDbprtDrawPrimitiveSlot[];

extern void (*D_00960090)(u32 state, u32 value);
extern f32 D_00960088;
extern RwBool (*D_009600A0)(RwPrimitiveType primitiveType,
                            RwIm2DVertex* vertices, s32 vertexCount);
static RwImage* sFontImage;
static HDbText3D* sText3DList;
static s8 sLogLine;
static u32 sDrawLogEnabled;
static char sGrid[HDBPRT_GRID_HEIGHT][HDBPRT_GRID_WIDTH];
static char sLogs[HDBPRT_LOG_MAXLINE][HDBPRT_LOG_MAXCHAR];

static void H_Dbprt_DrawText3D(void);
static f32 H_Dbprt_CalculateScreenZ(f32 zOffset);
static void H_Dbprt_DrawLog(void);
static void H_Dbprt_AppendText3D(HDbText3D* text);
static inline char H_Dbprt_ReadGlyph(s32 index, char* buffer)
{
    return *(char*)((u8*)(uintptr_t)index + (uintptr_t)buffer);
}

// FUN_001042E0
void H_Dbprt_Init()
{
    HCdvd* cdvd;
    RwRaster* raster;

    cdvd = H_Cdvd_Request("font/size12/f11_001.tmx", HCDVD_FILENORMAL);
    H_Cdvd_ReadSync(cdvd);

    sFontImage = RwImageRead("font/size12/f11_001.tmx");

    H_Cdvd_Destroy(cdvd);

    raster = RwRasterCreate(sFontImage->width,
                            sFontImage->height,
                            4,
                            rwRASTERTYPETEXTURE |
                            rwRASTERFORMATPAL4 |
                            rwRASTERFORMAT8888);
    sFontRaster = raster;
    RwRasterSetFromImage(raster, sFontImage);

    RwImageDestroy(sFontImage);
    sFontImage = NULL;

    H_Cdvd_001007f0();

    memset(sGrid, ' ', sizeof(sGrid));
    sText3DList = NULL;
}

// FUN_001043B0
void H_Dbprt_Flush()
{
    HDbText3D* curr;
    HDbText3D* next;

    memset(sGrid, ' ', sizeof(sGrid));

    curr = sText3DList;
    sText3DList = NULL;
    while (true)
    {
        if (curr == NULL)
        {
            break;
        }

        next = curr->next;
        RwFree(curr);
        curr = next;
    }
}

#pragma opt_lifetimes on
/* Removing this worsens FUN_00104420 (nd244 -> nd268) - measured W161. */
#pragma opt_loop_invariants on
// Reconstructed inline four-vertex glyph batching and render-state setup.
// Residual 28-byte overrun / normalized diff reflects MWCC scheduling and
// register allocation around UV arithmetic and loop control.
// FUN_00104420 NONMATCHING
void H_Dbprt_Main()
{
    RwIm2DVertex vertices[4];
    f32 recipZ;
    f32 z;
    f32 rowOffset;
    f32 rowY;
    s32 column;
    s32 row;
    s32 vertex;
    s32 glyphIndex;
    u8 glyphByte;
    u8* line;
    RwRenderStateSetFunc* setRenderState;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;

    setRenderState = (RwRenderStateSetFunc*)D_00960090_abs;
    (*setRenderState)(rwRENDERSTATEZTESTENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATESHADEMODE, (void*)rwSHADEMODEGOURAUD);
    (*setRenderState)(rwRENDERSTATEZWRITEENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATETEXTUREFILTER, (void*)rwFILTERNEAREST);
    (*setRenderState)(rwRENDERSTATEVERTEXALPHAENABLE, (void*)true);

    kwlnPushCommonRenderStates();
    (*setRenderState)(rwRENDERSTATETEXTURERASTER, (void*)sFontRaster);

    z = *(f32*)D_00960088_abs;

    for (vertex = 0; vertex < 4; vertex++)
    {
        RwIm2DVertex* vertexPtr = &vertices[vertex];

        vertexPtr->u.els.recipZ = recipZ;
        vertexPtr->u.els.color.r = 255.0f;
        vertexPtr->u.els.color.g = 255.0f;
        vertexPtr->u.els.color.b = 255.0f;
        vertexPtr->u.els.color.a = 255.0f;
        vertexPtr->u.els.scrVertex.z = z;
    }

    for (row = 0; row < HDBPRT_GRID_HEIGHT; row++)
    {
        column = 0;
        line = (u8*)sGrid[row];
        rowOffset = 12.0f * (f32)row;
        rowY = 11.0f + rowOffset;
        for (; column < HDBPRT_GRID_WIDTH; column++)
        {
            if (line[column] != ' ')
            {
                vertices[0].u.els.scrVertex.x = 12.0f * (f32)column;
                vertices[0].u.els.scrVertex.y = rowOffset;
                vertices[1].u.els.scrVertex.x =
                    vertices[0].u.els.scrVertex.x + 11.0f;
                vertices[1].u.els.scrVertex.y = rowOffset;
                vertices[2].u.els.scrVertex.x =
                    vertices[0].u.els.scrVertex.x;
                vertices[2].u.els.scrVertex.y = rowY;
                vertices[3].u.els.scrVertex.x =
                    vertices[1].u.els.scrVertex.x;
                vertices[3].u.els.scrVertex.y = rowY;
                glyphIndex = (s32)line[column] - ' ';
                glyphByte = (u8)glyphIndex;
                {
                    const f32 inv16 = 0.0625f;
                    f32 u0 = inv16 * (f32)(glyphByte % 16);
                    f32 v0 = inv16 * (f32)(glyphByte / 16);
                    f32 u1 = u0 + 0.03125f;
                    f32 v1 = v0 + 0.03125f;
                    vertices[0].u.els.u = u0;
                    vertices[0].u.els.v = v0;
                    vertices[1].u.els.u = u1;
                    vertices[1].u.els.v = v0;
                    vertices[2].u.els.u = u0;
                    vertices[2].u.els.v = v1;
                    vertices[3].u.els.u = u1;
                    vertices[3].u.els.v = v1;
                }

                D_009600A0_abs[0](rwPRIMTYPETRISTRIP, vertices, 4);
            }
        }
    }

    H_Dbprt_DrawText3D();
    H_Dbprt_DrawLog();
}



#pragma opt_loop_invariants off
#pragma opt_lifetimes off
// FUN_00104710 NONMATCHING
static void H_Dbprt_DrawText3D(void)
{
    HDbText3D* text;
    RwV2d uv[4];
    RwIm2DVertex vertices[4];
    f32 recipZ;
    f32 z;
    f32 u;
    f32 v;
    s32 character;
    s32 vertex;
    s8 glyph;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;
    kwlnGetMainCamera();
    kwlnGetMainCamera();
    kwlnGetMainCamera();

    kwlnPushCommonRenderStates();
    RwRenderStateSet(rwRENDERSTATETEXTURERASTER, sFontRaster);

    text = sText3DList;
    while (true)
    {
        if (text == NULL)
        {
            break;
        }
        kwlnGetMainCamera();
        kwlnGetMainCamera();
        if (text->pos.z != 0.0f)
        {
            z = H_Dbprt_CalculateScreenZ(text->pos.z);
        }

        for (character = 0; character < HDBPRT_LOG_MAXCHAR; character++)
        {
            glyph = (s8)text->text[character];
            if (glyph == '\0')
            {
                break;
            }

            if (glyph != ' ')
            {
                if (text->pos.z == 0.0f)
                {
                    vertices[0].u.els.scrVertex.x = text->pos.x + 12.0f * (f32)character;
                    vertices[0].u.els.scrVertex.y = text->pos.y;
                    vertices[1].u.els.scrVertex.x = vertices[0].u.els.scrVertex.x + 12.0f;
                    vertices[1].u.els.scrVertex.y = vertices[0].u.els.scrVertex.y;
                    vertices[2].u.els.scrVertex.x = vertices[0].u.els.scrVertex.x;
                    vertices[2].u.els.scrVertex.y = vertices[0].u.els.scrVertex.y + 12.0f;
                    vertices[3].u.els.scrVertex.x = vertices[1].u.els.scrVertex.x;
                    vertices[3].u.els.scrVertex.y = vertices[2].u.els.scrVertex.y;

                    u = 0.0625f * (f32)((glyph - ' ') % 16);
                    v = 0.0625f * (f32)((glyph - ' ') / 16);
                    uv[0].x = u;
                    uv[0].y = v;
                    uv[1].x = u + 0.046875f;
                    uv[1].y = v;
                    uv[2].x = u;
                    uv[2].y = v + 0.046875f;
                    uv[3].x = u + 0.046875f;
                    uv[3].y = v + 0.046875f;

                    z = RwIm2DGetNearScreenZ() - text->zOffset;
                    for (vertex = 0; vertex < 4; vertex++)
                    {
                        vertices[vertex].u.els.scrVertex.z = z;
                        vertices[vertex].u.els.color.r = text->color.r;
                        vertices[vertex].u.els.color.g = text->color.g;
                        vertices[vertex].u.els.color.b = text->color.b;
                        vertices[vertex].u.els.color.a = text->color.a;
                        vertices[vertex].u.els.recipZ = recipZ;
                        vertices[vertex].u.els.u = uv[vertex].x;
                        vertices[vertex].u.els.v = uv[vertex].y;
                    }
                }
                else
                {
                    vertices[0].u.els.scrVertex.x = text->pos.x + 12.0f * (f32)character;
                    vertices[0].u.els.scrVertex.y = text->pos.y;
                    vertices[1].u.els.scrVertex.x = vertices[0].u.els.scrVertex.x + 12.0f;
                    vertices[1].u.els.scrVertex.y = vertices[0].u.els.scrVertex.y;
                    vertices[2].u.els.scrVertex.x = vertices[0].u.els.scrVertex.x;
                    vertices[2].u.els.scrVertex.y = vertices[0].u.els.scrVertex.y + 12.0f;
                    vertices[3].u.els.scrVertex.x = vertices[1].u.els.scrVertex.x;
                    vertices[3].u.els.scrVertex.y = vertices[2].u.els.scrVertex.y;

                    u = 0.0625f * (f32)((glyph - ' ') % 16);
                    v = 0.0625f * (f32)((glyph - ' ') / 16);
                    uv[0].x = u;
                    uv[0].y = v;
                    uv[1].x = u + 0.046875f;
                    uv[1].y = v;
                    uv[2].x = u;
                    uv[2].y = v + 0.046875f;
                    uv[3].x = u + 0.046875f;
                    uv[3].y = v + 0.046875f;

                    for (vertex = 0; vertex < 4; vertex++)
                    {
                        vertices[vertex].u.els.scrVertex.z = z;
                        vertices[vertex].u.els.color.r = text->color.r;
                        vertices[vertex].u.els.color.g = text->color.g;
                        vertices[vertex].u.els.color.b = text->color.b;
                        vertices[vertex].u.els.color.a = text->color.a;
                        vertices[vertex].u.els.recipZ = recipZ;
                        vertices[vertex].u.els.u = uv[vertex].x;
                        vertices[vertex].u.els.v = uv[vertex].y;
                    }
                }

                RwIm2DRenderPrimitive(rwPRIMTYPETRISTRIP, vertices, 4);
            }
        }

        text = text->next;
    }
}

// FUN_00104D10 NONMATCHING
void H_Dbprt_FmtAt(volatile /* Removing this qualifier worsens H_Dbprt_FmtAt (NONMATCHING nd170 -> NONMATCHING nd290, size 412 -> 424) - measured W170. */ RwV2d pos, const char* fmt, ...)
{
    char buffer[HDBPRT_LOG_MAXCHAR];
    s32 character;
    s32 x;
    s32 y;
    s32 baseX;
    f32 posY;
    char glyph;
    va_list args;
    posY = pos.y;

    va_start(args, fmt);
    vsprintf(buffer, fmt, args);

    x = (s32)pos.x;
    y = (s32)posY;
    character = 0;
    baseX = x;
    while (character < HDBPRT_LOG_MAXCHAR)
    {
        if (pos.x >= HDBPRT_GRID_WIDTH || posY >= HDBPRT_GRID_HEIGHT ||
            x >= HDBPRT_GRID_WIDTH || y >= HDBPRT_GRID_HEIGHT)
        {
            break;
        }

        glyph = *(char*)((u8*)(uintptr_t)character +
                         (s32)(uintptr_t)buffer);
        if (glyph == '\0')
        {
            break;
        }

        if (glyph == '\n')
        {
            x = baseX;
            y++;
        }
        else
        {
            if (y == HDBPRT_GRID_HEIGHT - 1 && x >= HDBPRT_GRID_WIDTH)
            {
                printf("ERROR \n");
            }
            else
            {
                sGrid[y][x] = glyph;
            }
            x++;
        }
        character++;
    }
}

static inline void H_Dbprt_AppendText3D(HDbText3D* text)
{
    HDbText3D* last;

    if (sText3DList == NULL)
    {
        sText3DList = text;
        return;
    }

    last = sText3DList;
    for (;;)
    {
        if (last->next == NULL)
        {
            last->next = text;
            break;
        }
        last = last->next;
    }
}

// FUN_00104EB0
void H_Dbprt_FmtCol3D(RwV2d pos, RwRGBA color, const char* fmt, ...)
{
    HDbText3D* text;
    va_list args;

    text = RwCalloc(1, sizeof(HDbText3D), rwMEMHINTDUR_GLOBAL);
    va_start(args, fmt);
    vsprintf(text->text, fmt, args);

    text->pos.x = pos.x;
    text->pos.y = pos.y;
    text->pos.z = 0.0f;
    text->color = color;
    text->zOffset = 0.0f;

    H_Dbprt_AppendText3D(text);
}

// FUN_00104FD0
void H_Dbprt_Fmt3D(RwV2d pos, const char* fmt, ...)
{
    HDbText3D* text;
    va_list args;

    text = RwCalloc(1, sizeof(HDbText3D), rwMEMHINTDUR_GLOBAL);
    va_start(args, fmt);
    vsprintf(text->text, fmt, args);

    text->pos.x = pos.x;
    text->pos.y = pos.y;
    text->pos.z = 0.0f;
    text->zOffset = 0.0f;
    text->color.a = 255;
    text->color.b = 255;
    text->color.g = 255;
    text->color.r = 255;

    H_Dbprt_AppendText3D(text);
}

// FUN_001050E0
void H_Dbprt_FmtZOff3D(RwV2d pos, f32 zOffset, RwRGBA color, const char* fmt, ...)
{
    HDbText3D* text;
    va_list args;

    text = RwCalloc(1, sizeof(HDbText3D), rwMEMHINTDUR_GLOBAL);
    va_start(args, fmt);
    vsprintf(text->text, fmt, args);

    text->pos.x = pos.x;
    text->pos.y = pos.y;
    text->pos.z = 0.0f;
    text->zOffset = zOffset;
    text->color = color;

    H_Dbprt_AppendText3D(text);
}

// FUN_00105210
static f32 H_Dbprt_CalculateScreenZ(f32 zOffset)
{
    f32 zBufferFar;
    f32 zBufferNear;
    f32 farPlane;
    f32 nearPlane;
    f32 z;

    zBufferFar = rwGlobals.device.zBufferFar;
    zBufferNear = rwGlobals.device.zBufferNear;
    farPlane = kwlnGetMainCamera()->farPlane;
    nearPlane = kwlnGetMainCamera()->nearPlane;

    z = 0.0f + zBufferFar + (nearPlane / zOffset) *
                                ((zOffset - farPlane) * ((zBufferNear - zBufferFar) / (nearPlane - farPlane)));
    if (z < 0.0f)
    {
        z = 0.0f;
    }

    return z;
}

// FUN_001052B0
void H_Dbprt_FmtLog(const char* fmt, ...)
{
    char buffer[HDBPRT_LOG_MAXCHAR];
    s32 i;
    s32 line;
    va_list args;

    for (line = 0; line < HDBPRT_LOG_MAXCHAR; line++)
    {
        buffer[line] = 0;
    }

    va_start(args, fmt);
    vsprintf(buffer, fmt, args);

    if (sLogLine == HDBPRT_LOG_MAXLINE)
    {
        for (i = 1; i < HDBPRT_LOG_MAXLINE; i++)
        {
            memcpy(sLogs[i - 1], sLogs[i], HDBPRT_LOG_MAXCHAR);
        }
        sLogLine--;
    }

    memcpy(sLogs[sLogLine], buffer, HDBPRT_LOG_MAXCHAR);
    sLogLine++;
}

// FUN_001053F0 NONMATCHING
static void H_Dbprt_DrawLog(void)
{
    RwIm2DVertex vertices[4];
    RwV2d textureCoords[4];
    RwRGBA color;
    f32 recipZ;
    f32 z;
    f32 x;
    f32 y;
    f32 u;
    f32 v;
    RwIm2DRenderPrimitiveFunction* drawPrimitive;
    void (**setState)(u32 state, u32 value);
    s32 vertex;
    s32 row;
    s32 column;
    u8 glyph;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;

    if (sDrawLogEnabled == 0)
    {
        return;
    }
    setState = (void (**)(u32, u32))D_00960090_abs;


    (*setState)(rwRENDERSTATEZTESTENABLE, true);
    (*setState)(rwRENDERSTATESHADEMODE, rwSHADEMODEGOURAUD);
    (*setState)(rwRENDERSTATEZWRITEENABLE, true);
    (*setState)(rwRENDERSTATETEXTUREFILTER, rwFILTERNEAREST);
    (*setState)(rwRENDERSTATEVERTEXALPHAENABLE, true);

    kwlnPushCommonRenderStates();
    (*setState)(rwRENDERSTATETEXTURERASTER, (u32)NULL);

    color.r = 64;
    color.g = 64;
    color.b = 64;
    color.a = 128;
    z = RwIm2DGetNearScreenZ();

    for (vertex = 0; vertex < 4; vertex++)
    {
        vertices[vertex].u.els.scrVertex.z = z;
        vertices[vertex].u.els.recipZ = recipZ;
        vertices[vertex].u.els.color.r = (f32)color.r;
        vertices[vertex].u.els.color.g = (f32)color.g;
        vertices[vertex].u.els.color.b = (f32)color.b;
        vertices[vertex].u.els.color.a = (f32)color.a;
    }

    vertices[0].u.els.scrVertex.x = sLogBoxPos.x;
    vertices[0].u.els.scrVertex.y = sLogBoxPos.y;
    vertices[1].u.els.scrVertex.x = sLogBoxPos.x + 480.0f;
    vertices[1].u.els.scrVertex.y = sLogBoxPos.y;
    vertices[2].u.els.scrVertex.x = sLogBoxPos.x;
    vertices[2].u.els.scrVertex.y = sLogBoxPos.y + 196.0f;
    vertices[3].u.els.scrVertex.x = sLogBoxPos.x + 480.0f;
    vertices[3].u.els.scrVertex.y = sLogBoxPos.y + 196.0f;
    drawPrimitive = hDbprtDrawPrimitiveSlot;
    (*drawPrimitive)(rwPRIMTYPETRISTRIP, vertices, 4);

    kwlnPushCommonRenderStates();
    (*setState)(rwRENDERSTATETEXTURERASTER, (u32)sFontRaster);

    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 255;
    for (vertex = 0; vertex < 4; vertex++)
    {
        vertices[vertex].u.els.scrVertex.z = z;
        vertices[vertex].u.els.recipZ = recipZ;
        vertices[vertex].u.els.color.r = (f32)color.r;
        vertices[vertex].u.els.color.g = (f32)color.g;
        vertices[vertex].u.els.color.b = (f32)color.b;
        vertices[vertex].u.els.color.a = (f32)color.a;
    }
    for (row = 0; row < sLogLine; row++)
    {
        for (column = 0; column < HDBPRT_GRID_WIDTH; column++)
        {
            glyph = (u8)sLogs[row][column];
            if (glyph == '\0')
            {
                break;
            }

            if (glyph != ' ')
            {
                x = sLogStringsPos.x + 12.0f * (f32)column;
                y = sLogStringsPos.y + 12.0f * (f32)row;

                vertices[0].u.els.scrVertex.x = x;
                vertices[0].u.els.scrVertex.y = y;
                vertices[1].u.els.scrVertex.x = x + 12.0f;
                vertices[1].u.els.scrVertex.y = y;
                vertices[2].u.els.scrVertex.x = x;
                vertices[2].u.els.scrVertex.y = y + 12.0f;
                vertices[3].u.els.scrVertex.x = x + 12.0f;
                vertices[3].u.els.scrVertex.y = y + 12.0f;

                glyph -= ' ';
                u = 0.0625f * (f32)(glyph % 16);
                v = 0.0625f * (f32)(glyph / 16);
                textureCoords[0].x = u;
                textureCoords[0].y = v;
                textureCoords[1].x = u + 0.0625f;
                textureCoords[1].y = v;
                textureCoords[2].x = u;
                textureCoords[2].y = v + 0.0625f;
                textureCoords[3].x = u + 0.0625f;
                textureCoords[3].y = v + 0.0625f;
                for (vertex = 0; vertex < 4; vertex++)
                {
                    vertices[vertex].u.els.u = textureCoords[vertex].x;
                    vertices[vertex].u.els.v = textureCoords[vertex].y;
                }
                (*drawPrimitive)(rwPRIMTYPETRISTRIP, vertices, 4);
            }
        }
    }
}

