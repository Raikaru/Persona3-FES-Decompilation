#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/OpEd/op_fade.h"
#include "Main/OpEd/op_res.h"

extern void func_0021eae0(void* destination, const f32* layout);
extern void func_0021d8e0(void* destination, const f32* layout);
extern void func_0021d950(void* destination, const u8* color);
extern void func_00271e10(void);

extern void func_004d7f60(s32 state, u32 value);
extern u32 D_00960090[];
extern u32 D_0096009C[];
typedef void (*OpLogoSetRenderState)(u32 state, u32 value);
typedef void (*OpLogoRenderQuad)(void* quad, u32 layer, u32 group, u32 pass, u32 blend);
extern long func_00271e70(void);
extern void func_00271db0(void);
extern u16 DAT_007e094e[8];

typedef struct OpLogoWork
{
    u32 flags;                 /* 0x0000 */
    u32 state;                 /* 0x0004 */
    u32 unk_08;                /* 0x0008 */
    u32 unk_0c;                /* 0x000c */
    u8 render[0x100];          /* 0x0010 */
    u32 unk_110;               /* 0x0110 */
    u32 phase;                 /* 0x0114 */
} OpLogoWork;

static OpLogoWork* sOpLogo; // puGpffffb6c0

// FUN_00269cc0
void opLogo00269cc0(OpLogoWork* param_1)
{
    K_ASSERT(sOpLogo == NULL, 0x33);
    param_1->flags = 0;
    sOpLogo = param_1;
}

// FUN_00269d10
void opLogo00269d10(void)
{
    K_ASSERT(sOpLogo != NULL, 0x2c);
    sOpLogo = NULL;
}

// FUN_00269D50
void opLogo00269d50(void)
{
    OpLogoWork* work;
    s32 phase;
    u32 input;

    K_ASSERT(sOpLogo != NULL, 0x2c);
    work = sOpLogo;
    if ((~work->flags & 1) != 0)
    {
        return;
    }

    switch (work->state)
    {
        case 0:
            phase = work->phase;
            switch (phase)
            {
                case 0:
                    if (func_00271e70() == 0)
                    {
                        work->unk_110 = 0;
                        work->phase = 1;
                        return;
                    }
                    break;
                case 1:
                    work->unk_110++;
                    input = !DAT_007e094e[0];
                    if (input != 0 && (s32)work->unk_110 < 0x4b)
                    {
                        break;
                    }
                    func_00271db0();
                    work->phase = 2;
                    return;
                case 2:
                    if (func_00271e70() == 0)
                    {
                        func_00271e10();
                        work->phase = 0;
                        work->state = 1;
                        return;
                    }
                    break;
            }
            break;
        case 1:
            phase = work->phase;
            switch (phase)
            {
                case 0:
                    if (func_00271e70() == 0)
                    {
                        work->unk_110 = 0;
                        work->phase = 1;
                        return;
                    }
                    break;
                case 1:
                    work->unk_110++;
                    input = !DAT_007e094e[0];
                    if (input != 0 && (s32)work->unk_110 < 0x4b)
                    {
                        break;
                    }
                    func_00271db0();
                    work->phase = 2;
                    return;
                case 2:
                    if (func_00271e70() == 0)
                    {
                        work->flags &= ~1;
                    }
                    break;
            }
            break;
    }
}

// FUN_00269F50
void opLogo00269f50(void)
{
    OpLogoWork* work;
    OpLogoSetRenderState* setRenderState;
    OpLogoRenderQuad* renderQuad;
    RwRaster* raster;

    K_ASSERT(sOpLogo != NULL, 0x2c);
    work = sOpLogo;
    if ((~work->flags & 1) != 0)
    {
        return;
    }
    setRenderState = (OpLogoSetRenderState*)D_00960090;

    (*setRenderState)(8, 0);
    (*setRenderState)(6, 0);
    (*setRenderState)(9, 2);
    switch (work->state)
    {
        case 0:
            raster = opResGetLogoRaster(0);
            (*setRenderState)(1, (u32)(uintptr_t)raster);
            renderQuad = (OpLogoRenderQuad*)D_0096009C;
            (*renderQuad)(work->render, 4, 0, 1, 2);
            (*renderQuad)(work->render, 4, 0, 2, 3);
            break;
        case 1:
            raster = opResGetLogoRaster(1);
            (*setRenderState)(1, (u32)(uintptr_t)raster);
            renderQuad = (OpLogoRenderQuad*)D_0096009C;
            (*renderQuad)(work->render, 4, 0, 1, 2);
            (*renderQuad)(work->render, 4, 0, 2, 3);
            break;
    }
}

// FUN_0026A0F0
void opLogo0026a0f0(void)
{
    u32* puVar1;
    f32 layout[4];
    u8 color[4];

    K_ASSERT(sOpLogo != NULL, 0x2c);
    puVar1 = (u32*)sOpLogo;
    (void)opResGetLogoRaster(0);
    layout[0] = 0.0f;
    layout[1] = 0.0f;
    layout[2] = 0.625f;
    layout[3] = 0.875f;
    func_0021eae0(puVar1 + 4, layout);
    layout[0] = 0.0f;
    layout[1] = 0.0f;
    layout[2] = 640.0f;
    layout[3] = 448.0f;
    func_0021d8e0(puVar1 + 4, layout);
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = 0xff;
    func_0021d950(puVar1 + 4, color);
    opFadeStart(0x14);
    func_00271e10();
    puVar1[0x45] = 0;
    puVar1[1] = 0;
    *puVar1 |= 1;
}

// FUN_0026a1e0
u32 opLogo0026a1e0(void)
{
    K_ASSERT(sOpLogo != NULL, 0x2c);
    return sOpLogo->flags & 1;
}
