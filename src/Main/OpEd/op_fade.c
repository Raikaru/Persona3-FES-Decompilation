#include "Main/OpEd/op_fade.h"
#include "Kernel/Kwln/kwln.h"
#include "Kosaka/k_assert.h"

extern void func_0021eb80(void* destination, const f32* layout);
extern void func_0021d8e0(void* destination, const f32* layout);
extern void func_0021d950(void* destination, const u8* color);
extern void func_004d7f60(s32 state, u32 value);
extern void (*D_00960090)(u32 state, u32 value);
extern void (*D_0096009C)(void* quad, u32 layer, u32 group, u32 pass, u32 blend);
extern f32 D_00960088;
extern f32 fGpffff8248;
extern f32 fGpffff82fc;
extern f32 fGpffff839c;
extern f32 fGpffff81f8;
extern f32 func_00269c80(f32 value);
extern f32 func_00269ca0(f32 value);
extern f32 func_0052ea18(f32 y, f32 x);
extern f32 sqrtf(f32 value);

static OpFadeWork* sWork; // 007ce3bc

// FUN_002721d0
void opFadeStart(u32 duration)
{
    OpFadeWork* work;

    K_ASSERT(sWork != NULL, 31);
    work = sWork;

    work->state = OPFADE_STATE_START;
    work->duration = duration;
}

// FUN_00272220
void opFadeSetColor(const RwRGBA* color)
{
    OpFadeWork* work;

    K_ASSERT(sWork != NULL, 31);
    work = sWork;

    work->color = *color;
}

// FUN_00272290
void opFadeIn()
{
    OpFadeWork* work;

    K_ASSERT(sWork != NULL, 31);
    work = sWork;

    work->state = OPFADE_STATE_IN;
    work->timer = work->duration;
}

// FUN_002722e0
void opFadeOut()
{
    OpFadeWork* work;

    K_ASSERT(sWork != NULL, 31);
    work = sWork;

    work->state = OPFADE_STATE_OUT;
    work->timer = work->duration;
}
// FUN_00271CD0 NONMATCHING
void func_00271cd0(OpFadeWork* work)
{
    f32 layout[4];

    layout[0] = 0.0f;
    layout[1] = 0.0f;
    layout[2] = 0.0f;
    layout[3] = 0.0f;
    work->flags = 0;
    func_0021eb80(&work->vertices[0], layout);
    layout[2] = 640.0f;
    layout[3] = 448.0f;
    func_0021d8e0(&work->vertices[0], layout);
    work->state = OPFADE_STATE_START;
    work->timer = 0;
    work->duration = 0;
    work->color.r = 0;
    work->color.g = 0;
    work->color.b = 0;
    work->color.a = 0xff;
    sWork = work;
}

// FUN_00271D70
void func_00271d70(void)
{
    K_ASSERT(sWork != NULL, 31);
    sWork = NULL;
}

// FUN_00271DB0 NONMATCHING
void func_00271db0(void)
{
    K_ASSERT(sWork != NULL, 31);
    sWork->timer = 0;
    sWork->state = OPFADE_STATE_IN;
    sWork->flags |= 1;
}

// FUN_00271E10 NONMATCHING
void func_00271e10(void)
{
    K_ASSERT(sWork != NULL, 31);
    sWork->timer = 0;
    sWork->state = OPFADE_STATE_OUT;
    sWork->flags |= 1;
}

// FUN_00271E70
u32 func_00271e70(void)
{
    K_ASSERT(sWork != NULL, 31);
    return sWork->flags & 1;
}

// FUN_00271EC0 NONMATCHING
void func_00271ec0(void)
{
    f32 alphaScale;
    u8 color[4];

    K_ASSERT(sWork != NULL, 31);
    if (sWork->timer < sWork->duration)
        sWork->timer++;
    else
        sWork->flags &= ~1u;

    if (sWork->state == OPFADE_STATE_OUT)
        alphaScale = sWork->duration == 0 ? 1.0f :
                     1.0f - (f32)sWork->timer / (f32)sWork->duration;
    else if (sWork->state == OPFADE_STATE_IN)
        alphaScale = sWork->duration == 0 ? 1.0f :
                     (f32)sWork->timer / (f32)sWork->duration;
    else
        alphaScale = 0.0f;

    color[0] = sWork->color.r;
    color[1] = sWork->color.g;
    color[2] = sWork->color.b;
    color[3] = (u8)((f32)sWork->color.a * alphaScale);
    func_0021d950(&sWork->vertices[0], color);
}

// FUN_002720C0 NONMATCHING
void func_002720c0(void)
{
    K_ASSERT(sWork != NULL, 31);
    (*D_00960090)(8, 0);
    (*D_00960090)(6, 0);
    (*D_00960090)(9, 2);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*D_00960090)(1, 0);
    (*D_0096009C)(&sWork->vertices[0], 4, 0, 1, 2);
    (*D_0096009C)(&sWork->vertices[0], 4, 0, 2, 3);
}
