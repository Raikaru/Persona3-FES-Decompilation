#ifndef MAIN_GAME_GAME_SUPPORT_H
#define MAIN_GAME_GAME_SUPPORT_H

#include "type.h"
#include "Kernel/Kwln/kwlnTask.h"

/* Calendar/game-root support tasks. */
u32 func_001885a0(void);
u32 func_001885f0(void);
u64 func_00188640(void);
void func_00188650(void);
u64 func_00188660(void);
void func_00188670(void);
void func_00188680(void);
void* func_00188690(KwlnTask* task);
void func_00188830(KwlnTask* task);
KwlnTask* func_00188860(KwlnTask* parent);
void* func_00188900(KwlnTask* task);
void func_00188b20(KwlnTask* task);
u32 func_00188b50(void);
u32 func_00188be0(void);

/* Game-support animation workers and transition helpers. */
void* func_00188c30(KwlnTask* task);
void* func_00189230(KwlnTask* task);
void* func_00189810(KwlnTask* task);
void* func_00189df0(KwlnTask* task);
void* func_0018a3f0(KwlnTask* task);
void func_0018a9c0(KwlnTask* task);
void* func_0018a9f0(KwlnTask* task);
void func_0018b270(KwlnTask* task);
s32 func_0018b360(KwlnTask* task);
void* func_0018b380(KwlnTask* task);
s32 func_0018b5f0(KwlnTask* task);
KwlnTask* func_0018b620(KwlnTask* parent, s32 mode);
void* func_0018b6d0(s32 count);
u32 func_0018b700(void* transition);
void func_0018b7b0(void* transition, f32* position);
void func_0018ba60(void* transition, u8* alpha);
u32 func_0018bb20(void* transition);
u32 func_0018bb80(void* transition);
void func_0018bc10(f32 depth, void* transition, s32 drawMode,
                   s32 positionMode, s32 alphaMode,
                   u64 start, u64 end, s32 param0, s32 tile,
                   s32 startFrame, s32 endFrame);
void func_0018bc80(void);
void* func_0018bd90(KwlnTask* task);
void func_0018bee0(KwlnTask* task, s16 pcId, s32 mode);
void func_0018bfa0(KwlnTask* task);
KwlnTask* func_0018bff0(KwlnTask* parent);
u32 func_0018c0a0(KwlnTask* task);
void func_0018c0c0(KwlnTask* task, s32 visible);
void func_0018c150(KwlnTask* task);
void func_0018c780(KwlnTask* task);
void func_0018ce50(KwlnTask* task);
void func_0018d320(KwlnTask* task);
void* func_0018db20(KwlnTask* task);
void func_0018dde0(void* transitionTask, s32 mode);
void* func_0018de60(KwlnTask* task);
void func_0018e330(KwlnTask* task);
KwlnTask* func_0018e390(KwlnTask* parent, s32 index, void* resources);
void func_0018e490(KwlnTask* task, s32 visible);
void func_0018e4a0(void);
void* func_0018e540(KwlnTask* task);
void func_0018e5c0(KwlnTask* task, void* record);
void func_0018e7a0(KwlnTask* task);
KwlnTask* func_0018e820(KwlnTask* parent);
void func_0018e8e0(KwlnTask* task);
void func_0018eb30(KwlnTask* task, u32 visible);
void* func_0018eb40(KwlnTask* task);
void func_0018ef60(KwlnTask* task);
KwlnTask* func_0018efb0(KwlnTask* parent, s32 mode);
u32 func_0018f060(KwlnTask* task);
void func_0018f080(KwlnTask* task);
u32 func_0018f0a0(void);
u32 func_0018f0b0(KwlnTask* task);
u32 func_0018f0c0(KwlnTask* task);
void func_0018f0e0(KwlnTask* task);

#endif
