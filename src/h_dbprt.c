#include "h_dbprt.h"
#include "h_cdvd.h"
#include "temporary.h"

typedef char* va_list;
#define va_start(ap, last) (ap = ((va_list)__builtin_next_arg(last) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8)))
#define va_end(ap) ((void)0)
extern int vsprintf(char* buffer, const char* fmt, va_list args);

#define HDBPRT_LOG_MAXLINE 15
#define HDBPRT_LOG_MAXCHAR 256

// divided by 12 because a single character in the texture is 12 * 12 pixels
#define HDBPRT_GRID_WIDTH  (640 / 12)
#define HDBPRT_GRID_HEIGHT (480 / 12)

const RwV2d sLogBoxPos = {28.0f, 42.0f};     // 007cb290
const RwV2d sLogStringsPos = {36.0f, 50.0f}; // 007cb298

static RwRaster* sFontRaster;  // 007cded0
static RwImage* sFontImage;    // 007cdecc
static HDbText3D* sText3DList; // 007cdec8. Linked list of """3D""" strings
static s8 sLogLine;            // 007cdec4. Current line in the log
static u32 sDrawLogEnabled;    // 007cdec0
static char sGrid[HDBPRT_GRID_HEIGHT][HDBPRT_GRID_WIDTH];  // 007e1e30. Grids of characters wherever on the screen
static char sLogs[HDBPRT_LOG_MAXLINE][HDBPRT_LOG_MAXCHAR]; // 007e0a30. Strings in the log box

// FUN_001042e0
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
                            rwRASTERFORMATPAL4  |
                            rwRASTERFORMAT8888);
    sFontRaster = raster;
    RwRasterSetFromImage(raster, sFontImage);

    RwImageDestroy(sFontImage);
    sFontImage = NULL;

    H_Cdvd_001007f0();

    memset(sGrid, ' ', sizeof(sGrid));
    sText3DList = NULL;
}

// FUN_001043b0
void H_Dbprt_Flush()
{
    HDbText3D* curr;
    HDbText3D* next;

    memset(sGrid, ' ', sizeof(sGrid));
    
    curr = sText3DList;
    sText3DList = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        RwFree(curr);
        curr = next;
    }
}

// FUN_00104420
void H_Dbprt_Main()
{
    // TODO
}

// FUN_00104d10
void H_Dbprt_FmtAt(RwV2d pos, const char* fmt, ...)
{
    // TODO
}

// FUN_00104eb0. Forces to be in 2D (with color)
void H_Dbprt_FmtCol3D(RwV2d pos, RwRGBA col, const char* fmt, ...)
{
    // TODO
}

// FUN_00104fd0. Forces to be in 2D
void H_Dbprt_Fmt3D(RwV2d pos, const char* fmt, ...)
{
    // TODO
}

// FUN_001050e0. Forces to be in 2D (with a Z offset)
void H_Dbprt_FmtZOff3D(RwV2d pos, f32 zOffset, const char* fmt, ...)
{
    // TODO
}

// FUN_001052b0
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