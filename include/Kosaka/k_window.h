#ifndef K_WINDOW_H
#define K_WINDOW_H

#include "Utils.h"
#include "rw/rwplcore.h"

typedef struct KwlnTask KwlnTask;

/* 0x54-byte ksk window task work area. */
typedef struct KWindowTaskWork
{
    u32 state;             // 0x00
    u32 request;           // 0x04
    u32 unused08;          // 0x08
    RwRect rect;            // 0x0c
    RwRGBA colorA;         // 0x1c
    RwRGBA colorB;         // 0x20
    void* renderData;      // 0x24
    void* colorDataA;      // 0x28
    void* colorDataB;      // 0x2c
    f32 horizontalOffset;  // 0x30
    f32 verticalOffset;    // 0x34
    f32 horizontalInset;   // 0x38
    f32 verticalInset;     // 0x3c
    f32 alphaStep;         // 0x40
    s32 bufferSize;        // 0x44
    void* buffer;          // 0x48
    void* bufferAlias;     // 0x4c
    f32 fieldOfView;       // 0x50
} KWindowTaskWork;

KwlnTask* func_001a2200(KwlnTask* parent, const RwRect* rect, const RwRGBA* colorA, const RwRGBA* colorB);
u32 func_001a2390(const KwlnTask* task);
void func_001a23d0(KwlnTask* task, u32 request);
void func_001a23e0(KwlnTask* task, const RwRect* rect);

#endif
