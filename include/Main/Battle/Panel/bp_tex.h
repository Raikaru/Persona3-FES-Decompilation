#ifndef BP_TEX_H
#define BP_TEX_H

#include "Utils.h"

typedef struct RwRaster RwRaster;

void* bpTex0021c9f0(void* sprMemory);
RwRaster* bpTexCreateTmxRaster(void* tmxMemory);

void func_0021cc20(void* texture);
void* func_0021cca0(void* texture, s32 index);
u32 func_0021cce0(void* frame);
void func_0021cd00(void* frame, f32* uv);
void func_0021cec0(void* frame, f32* uv, u32 mode);
void func_0021d3b0(void* destination, void* frame);
void func_0021d890(void* destination, const f32* vertices);
void func_0021d8e0(void* destination, const f32* rect);
void func_0021d950(void* destination, const u8* color);
void func_0021dd60(void* destination, const u8* colors);
void func_0021e170(void* destination,
                   const f32* center,
                   const f32* direction,
                   const f32* size);
void func_0021e380(void* destination, void* frame, u32 mode);
f32 func_0021ea00(s32 duration);
void func_0021eac0(void* destination, f32 value);
void func_0021eae0(void* destination, const f32* rect);
void func_0021eb80(void* destination, const f32* rect);

void bpTexSortVisibleNodes(void);
void bpTexFinishNodeStreams(void);
u32 bpTexIsReady(void);
void bpTexBeginRender(void);
void bpTexEndRender(void);
void bpTexResetNodes(void);
void bpTexSetTransitionPending(u32* work);
void bpTexQueueNodePair(u32 first, u32 second);
u32* bpTexFindFreeNode(void);
u32* bpTexFindNodeByIndex(u32 index);
s32 bpTexGetNodeCount(void);
void bpTexQueueNodeRange(s32 start, s32 count);
void bpTexRemoveNodeAt(s32 index);
void bpTexShuffleNodes(void);
u32 bpTexIsShuffleActive(void);
void bpTexStartShuffle(void);
void bpTexStopShuffle(void);
u32* bpTexGetCurrentNode(void);
u32* bpTexFindNodeById(u32 id);
void bpTexApplyGlobalAlpha(f32 amount, void* node);
u32 bpTexHasPendingNode(void);
void bpTexUpdateNode(void* node);
void bpTexCollectLeafPos(void* node, void* values, s32* count);
void bpTexCollectLeaves(void* node, void* values, s32* count);
void bpTexApplyActions(void);
void bpTexBuildPosition(void* output, u32 index, void* source, s32 count);
void bpTexBuildFixedPosition(void* output, void* source);
void bpTexDumpNodes(void);
void bpTexPrepareNodes(void);
void func_0021f0c0(void* work);
void func_0021f140(void);
void func_0021f150(u32 selection);
void func_0021f3c0(void);
void func_0021f410(void);
void func_00221b60(void);
#endif

