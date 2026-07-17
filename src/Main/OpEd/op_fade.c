#include "Main/OpEd/op_fade.h"
#include "Kernel/Kwln/kwln.h"
#include "Kosaka/k_assert.h"

typedef void (*OpFadeSetRenderState)(u32 state, u32 value);
typedef void (*OpFadeRenderQuad)(void* quad, u32 layer, u32 group, u32 pass, u32 blend);

extern void func_0021eb80(void* destination, const f32* layout);
extern void func_0021d8e0(void* destination, f32* layout);
extern void func_0021d950(void* destination, const u8* color);
extern void func_004d7f60(s32 state, u32 value);
extern u32 D_00960090[];
extern u32 D_0096009C[];
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
// FUN_00271CD0
void func_00271cd0(OpFadeWork* work)
{
    f32 layout[8];

    work->flags = 0;

    layout[0] = 0.0f;
    layout[1] = 0.0f;
    layout[2] = 0.0f;
    layout[3] = 0.0f;
    func_0021eb80(&work->vertices[0], layout);
    layout[0] = 0.0f;
    layout[1] = 0.0f;
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

// FUN_00271DB0
void func_00271db0(void)
{
    OpFadeWork* work;

    K_ASSERT(sWork != NULL, 31);
    work = sWork;

    work->timer = 0;
    work->state = OPFADE_STATE_IN;
    work->flags |= 1;
}

// FUN_00271E10
void func_00271e10(void)
{
    OpFadeWork* work;

    K_ASSERT(sWork != NULL, 31);
    work = sWork;

    work->timer = 0;
    work->state = OPFADE_STATE_OUT;
    work->flags |= 1;
}

// FUN_00271E70
u32 func_00271e70(void)
{
    K_ASSERT(sWork != NULL, 31);
    return sWork->flags & 1;
}

// FUN_00271EC0
void func_00271ec0(void)
{
    OpFadeWork* work;
    f32 alphaScale;
    f32 ratio;
    u8 color[4];

    K_ASSERT(sWork != NULL, 31);
    work = sWork;
    if ((s32)work->timer < (s32)work->duration)
    {
        work->timer++;
    }
    else
    {
        work->flags &= ~1u;
    }

    switch (work->state)
    {
        case OPFADE_STATE_START:
            alphaScale = 0.0f;
            break;
        case OPFADE_STATE_IN:
            alphaScale = work->duration
                ? (f32)(s32)work->timer / (f32)(s32)work->duration
                : 1.0f;
            break;
        case OPFADE_STATE_OUT:
            if (work->duration != 0)
            {
                ratio = (f32)(s32)work->timer / (f32)(s32)work->duration;
            }
            else
            {
                ratio = 1.0f;
            }
            alphaScale = 1.0f - ratio;
            break;
    }

    color[0] = work->color.r;
    color[1] = work->color.g;
    color[2] = work->color.b;
    color[3] = (u8)((f32)work->color.a * alphaScale);
    func_0021d950(&work->vertices[0], color);
}

// FUN_002720C0
void func_002720c0(void)
{
    OpFadeWork* work;
    OpFadeSetRenderState* setRenderState;
    OpFadeRenderQuad* renderQuad;

    K_ASSERT(sWork != NULL, 31);
    work = sWork;
    setRenderState = (OpFadeSetRenderState*)D_00960090;
    (*setRenderState)(8, 0);
    (*setRenderState)(6, 0);
    (*setRenderState)(9, 2);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*setRenderState)(1, 0);
    renderQuad = (OpFadeRenderQuad*)D_0096009C;
    (*renderQuad)(&work->vertices[0], 4, 0, 1, 2);
    (*renderQuad)(&work->vertices[0], 4, 0, 2, 3);
}
