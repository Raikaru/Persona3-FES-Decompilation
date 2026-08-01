#ifndef H_MAESTRO_H
#define H_MAESTRO_H

#include "Utils.h"
#include "rw/rwplcore.h"

typedef struct HCdvd HCdvd;
typedef struct KwlnTask KwlnTask;

typedef struct RwStream RwStream;
typedef struct Rt2dMaestro Rt2dMaestro;
typedef struct Rt2dObject Rt2dObject;   // TODO: create 'rt2d.h' file

typedef enum
{
    HMAESTRO_STATE_INITCDVD,
    HMAESTRO_STATE_INITSTREAM,
    HMAESTRO_STATE_INITSCENE,
    HMAESTRO_STATE_IDLE,
    HMAESTRO_STATE_DRAW,
    HMAESTRO_STATE_IDLE2
} HMaestroState;

// 308 bytes
typedef struct HMaestro
{
    s32 state;            // 0x00. See enum 'HMaestroState'
    HCdvd* cdvd;          // 0x04
    RwStream* rws;        // 0x08
    Rt2dMaestro* maestro; // 0x0c
    Rt2dObject* scene;    // 0x10
    f32 deltaTime;        // 0x14
    char path[256];       // 0x18
    u32 shouldLoop;       // 0x118
    u32 noDeltaTime;      // 0x11c
    u32 unk_120;          // 0x120
    u32 unk_124;          // 0x124
    f32 alphaMult;        // 0x128
    u32 useCdvd;          // 0x12c. Request cdvd or not
    s32 unk_130;          // 0x130
} HMaestro;

void func_001102e0(KwlnTask* task);
KwlnTask* func_001103e0(KwlnTask* parent, u32 priority, u32 param_3, u32 resourceCount);
u32 func_001104b0(KwlnTask* task);
u32 func_001104d0(KwlnTask* task);
u32 func_00110510(KwlnTask* task);
void func_001105d0(KwlnTask* task, s32 index, void* resource);
void func_00110620(KwlnTask* task, s16 index, s16 param_3, s16 param_4, s16 param_5);
void func_00110650(void* work, s32 sourceIndex, s32 destinationIndex);
void* func_001107d0(KwlnTask* task);
void func_00110e70(KwlnTask* task);
KwlnTask* func_00110f80(KwlnTask* parent, u64 dimensions);
KwlnTask* func_00111150(KwlnTask* parent, u64 dimensions);
KwlnTask* func_00111260(KwlnTask* parent, u64 dimensions, void* archive);
KwlnTask* func_00111380(KwlnTask* parent, u32 priority, u64 dimensions, void* archive);
u32 func_001114b0(KwlnTask* task);
s32 func_00111500(KwlnTask* task);
void func_00111520(KwlnTask* task, s16 count);
u32 func_00111530(KwlnTask* task);
void func_00111570(KwlnTask* task, u32 value);
void func_00111580(KwlnTask* task, u64 packedCoordinates);
void func_001115b0(KwlnTask* task);
void func_001115e0(KwlnTask* task);
void H_Maestro_00111c50(KwlnTask* task);
void func_00111ca0(KwlnTask* task, u32 value);
void func_00111f10(KwlnTask* task, u32 noDeltaTime);
void func_00111f50(void);
void func_001120c0(void);
void func_00112110(void* node);
void* func_00112370(const char* path);
void* func_00112420(void* source);
void func_001124b0(void* node);
void func_001125d0(void);
f32 func_001126b0(void* sample);
f32 func_00112740(void* sample);
void func_001127d0(void* node, u32 enabled);

void* H_Maestro_UpdateTask(KwlnTask* task);
void H_Maestro_DestroyTask(KwlnTask* task);
u32 H_Maestro_00111f30(s16* state);

KwlnTask* H_Maestro_CreateTask(KwlnTask* parent, u32 priority, const char* path);
void H_Maestro_SetAlphaMult(KwlnTask* hmaestroTask, f32 alphaMult);
u32 H_Maestro_00111cb0(KwlnTask* hmaestroTask);
u32 H_Maestro_FinishedInit(KwlnTask* hmaestroTask);
void H_Maestro_RequestDraw(KwlnTask* hmaestroTask);
void H_Maestro_SetShouldLoop(KwlnTask* hmaestroTask, u32 shouldLoop);
void H_Maestro_00111f20(KwlnTask* hmaestroTask, u32 param_2);

#endif