#include "Utils.h"
#include "Kosaka/k_assert.h"

/* DAT_007CE348: panel effect work installed by FUN_0024C100. */
static u32* sBpEffect;

extern void func_0010a4e0(s32, s32, s32, s32);
extern void* func_0021c790(void* frame);
extern void func_0021d890(void* destination, const f32* vertices);
extern void func_0021d8e0(void* destination, const f32* layout);
extern void func_0021d950(void* destination, const u8* color);
extern void func_0021eac0(void* destination, f32 value);
extern void func_0021eb80(void* destination, const f32* layout);
extern f32 DAT_007cad60;
extern f32 DAT_007cafec;
extern void RpSkyRenderStateSet(s32 state, u32 value);
extern u32 D_00960090[];
extern u32 D_0096009c[];

typedef void (*BpEffectSetRenderState)(s32 state, u32 value);
typedef void (*BpEffectRenderQuad)(void* quad, s32 layer, s32 group, s32 pass, s32 blend);



