#ifndef H_DBPRT_H
#define H_DBPRT_H

#include "Utils.h"
#include "rw/rwcore.h"

typedef struct HDbText3D HDbText3D;

// 280 bytes
struct HDbText3D
{
    HDbText3D* next; // 0x00
    RwV3d pos;       // 0x04
    char text[256];  // 0x10
    f32 zOffset;     // 0x110
    RwRGBA color;    // 0x114
};

void H_Dbprt_Init(void);
void H_Dbprt_Flush(void);
void H_Dbprt_Main(void);

void H_Dbprt_FmtAt(RwV2d pos, const char* fmt, ...);
void H_Dbprt_FmtCol3D(RwV2d pos, RwRGBA color, const char* fmt, ...);
void H_Dbprt_Fmt3D(RwV2d pos, const char* fmt, ...);
void H_Dbprt_FmtZOff3D(RwV2d pos, f32 zOffset, RwRGBA color, const char* fmt, ...);
void H_Dbprt_FmtLog(const char* fmt, ...);

#endif