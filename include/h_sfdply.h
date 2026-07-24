#ifndef H_SFDPLY_H
#define H_SFDPLY_H

#include "Utils.h"

typedef struct KwlnTask KwlnTask;

typedef enum
{
    HSFD_ORPHEUSAWAKENING = 7
} HSfdId;

typedef enum
{
    HSFD_STATE_IDLE,
    HSFD_STATE_WAIT_FOR_FADE = 2,
    HSFD_STATE_CREATE_STREAM,
    HSFD_STATE_PLAYING,
    HSFD_STATE_FADE_OUT,
    HSFD_STATE_CLEANUP
} HSfdState;

typedef struct HSfdQuad
{
    u8 data[0x40];
} HSfdQuad;

// 544 bytes. The movie task owns every pointer in this structure.
typedef struct HSfd
{
    u8 streamHeader[0x04];          // 0x000
    void* decoder;                  // 0x004
    u8 streamConfig[0xC8];          // 0x008
    void* renderTarget;             // 0x0D0
    void* streamDescriptor;         // 0x0D4
    void* streamAux;                // 0x0D8
    u8 reservedDC[0x04];            // 0x0DC
    HSfdQuad quads[4];              // 0x0E0
    void* compressedFrameBuffer;    // 0x1E0
    s16 state;                      // 0x1E4. See enum 'HSfdState'.
    s16 movieFrame;                 // 0x1E6
    s16 unknown1E8;                 // 0x1E8
    s16 id;                         // 0x1EA. See enum 'HSfdId'.
    s16 unknown1EC;                 // 0x1EC
    s16 stateTimer;                 // 0x1EE
    u8 reserved1F0[0x04];           // 0x1F0
    u32 isStart;                    // 0x1F4
    s32 decodeResult;               // 0x1F8
    u32 ownsCamera;                 // 0x1FC
    void* displayBuffer;            // 0x200
    s32 fadeFrame;                  // 0x204
    s32 playbackFrame;              // 0x208
    s32 streamFlags;                // 0x20C
    s32 frameWidth;                 // 0x210
    s32 frameHeight;                // 0x214
    u8 trailingData[0x08];          // 0x218
} HSfd;

void* H_SfdPlay_UpdateTask(KwlnTask* sfdPlayTask);
void H_SfdPlay_DestroyTask(KwlnTask* sfdPlayTask);
KwlnTask* H_SfdPlay_CreateTaskIdle(KwlnTask* parent);

u32 H_SfdPlayCmd_CALL_MOVIE(void);
u32 H_SfdPlayCmd_MOVIE_SYNC(void);

#endif