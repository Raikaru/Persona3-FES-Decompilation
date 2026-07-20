#include "type.h"
#include "Main/Game/game_support.h"

extern void func_001140d0(u32 rgba, s32 width, s32 height, const void* texture,
                          f32 depthOffset, f32 x, f32 y);

// FUN_00188C30 NONMATCHING
void* func_00188c30(KwlnTask* task)
{
    s32 param_1 = (s32)(u32)task;
    s32* puVar1;
    s32 iVar2;
    s32 iVar3;
    f32 fVar1;
    f32 fVar2;

    puVar1 = *(s32**)(param_1 + 0x3c);
    puVar1[1] = puVar1[1] + 1;
    puVar1[2] = puVar1[2] + 1;
    switch (puVar1[0])
    {
        case 0:
            if (puVar1[1] == 3)
            {
                puVar1[1] = 0;
                puVar1[2] = 0;
                puVar1[0] = 1;
            }
            break;

        case 1:
            if (puVar1[1] == 5)
            {
                puVar1[0] = 2;
            }
            break;

        case 2:
            if (puVar1[1] == 8)
            {
                puVar1[0] = 3;
            }
            fVar1 = 190.0f - (f32)(puVar1[1] + -6) / 2.0f;
            fVar2 = 20.0f - ((f32)(puVar1[1] + -6) * 4.0f) / 2.0f;
            iVar2 = (((puVar1[2] * 0x1e) / 0x32 + 0x5f) * 0x1000) / 100;
            iVar2 = iVar2 * 0x80;
            iVar3 = iVar2 >> 0xc;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f, fVar1, fVar2);
            break;

        case 3:
            if (puVar1[1] == 10)
            {
                puVar1[0] = 4;
            }
            iVar2 = ((((puVar1[2] * 0x1e) / 0x32 + 0x5f) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f,
                          189.0f - (f32)(puVar1[1] + -8) / 2.0f,
                          ((f32)(puVar1[1] + -8) * 4.0f) / 2.0f + 16.0f);
            break;

        case 4:
            if (puVar1[1] == 0xe)
            {
                puVar1[0] = 5;
            }
            iVar2 = ((((puVar1[2] * 0x1e) / 0x32 + 0x5f) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f,
                          185.0f - ((f32)(puVar1[1] + -10) * 3.0f) / 4.0f,
                          20.0f - ((f32)(puVar1[1] + -10) * 11.0f) / 4.0f);
            break;

        case 5:
            if (puVar1[1] == 0x10)
            {
                puVar1[0] = 6;
            }
            iVar2 = ((((puVar1[2] * 0x1e) / 0x32 + 0x5f) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f,
                          185.0f - ((f32)(puVar1[1] + -0xe) * 2.0f) / 2.0f,
                          ((f32)(puVar1[1] + -0xe) * 7.0f) / 2.0f + 9.0f);
            break;

        case 6:
            if (puVar1[1] == 0x27)
            {
                puVar1[0] = 7;
            }
            iVar2 = ((((puVar1[2] * 0x1e) / 0x32 + 0x5f) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f,
                          183.0f - ((f32)(puVar1[1] + -0x10) * 41.0f) / 34.0f,
                          16.0f - ((f32)(puVar1[1] + -0x10) * 50.0f) / 34.0f);
            break;

        case 7:
            iVar2 = puVar1[1];
            if (iVar2 == 0x32)
            {
                return KWLNTASK_STOP;
            }
            iVar3 = ((((puVar1[2] * 0x1e) / 0x32 + 0x5f) * 0x1000) / 100) * 0x80;
            if (iVar3 < 0)
            {
                iVar3 = iVar3 + 0xfff;
            }
            func_001140d0(0xffffff00U |
                              (0xffU - ((iVar2 + -0x27) * 0xff) / 0xb),
                          iVar3 >> 0xc, iVar3 >> 0xc,
                          (const void*)(u32)puVar1[3], 0.0f,
                          183.0f - ((f32)(iVar2 + -0x10) * 41.0f) / 34.0f,
                          16.0f - ((f32)(iVar2 + -0x10) * 50.0f) / 34.0f);
            break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_00189230 NONMATCHING
void* func_00189230(KwlnTask* task)
{
    s32 param_1 = (s32)(u32)task;
    s32* puVar1;
    s32 iVar2;
    s32 iVar3;
    f32 fVar1;
    f32 fVar2;
    f32 fVar4;

    puVar1 = *(s32**)(param_1 + 0x3c);
    puVar1[1] = puVar1[1] + 1;
    puVar1[2] = puVar1[2] + 1;
    switch (puVar1[0])
    {
        case 0:
            if (puVar1[1] == 3)
            {
                puVar1[1] = 0;
                puVar1[2] = 0;
                puVar1[0] = 1;
            }
            break;

        case 1:
            if (puVar1[1] == 8)
            {
                puVar1[0] = 2;
            }
            break;

        case 2:
            if (puVar1[1] == 0xb)
            {
                puVar1[0] = 3;
            }
            fVar1 = 230.0f - ((f32)(puVar1[1] + -9) * 3.0f) / 2.0f;
            fVar2 = 89.0f - ((f32)(puVar1[1] + -9) * 7.0f) / 2.0f;
            iVar2 = ((((puVar1[2] * 0x14) / 0x32 + 0x5a) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f, fVar1, fVar2);
            break;

        case 3:
            if (puVar1[1] == 0xd)
            {
                puVar1[0] = 4;
            }
            fVar1 = ((f32)(puVar1[1] + -0xb) * 2.0f) / 2.0f + 227.0f;
            fVar2 = ((f32)(puVar1[1] + -0xb) * 6.0f) / 2.0f + 83.0f;
            iVar2 = ((((puVar1[2] * 0x14) / 0x32 + 0x5a) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f, fVar1, fVar2);
            break;

        case 4:
            if (puVar1[1] == 0x11)
            {
                puVar1[0] = 5;
            }
            fVar1 = 229.0f - ((f32)(puVar1[1] + -0xd) * 6.0f) / 4.0f;
            fVar2 = 89.0f - ((f32)(puVar1[1] + -0xd) * 7.0f) / 4.0f;
            iVar2 = ((((puVar1[2] * 0x14) / 0x32 + 0x5a) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f, fVar1, fVar2);
            break;

        case 5:
            if (puVar1[1] == 0x13)
            {
                puVar1[0] = 6;
            }
            fVar1 = 223.0f - (f32)(puVar1[1] + -0x11) / 2.0f;
            fVar2 = ((f32)(puVar1[1] + -0x11) * 5.0f) / 2.0f + 82.0f;
            iVar2 = ((((puVar1[2] * 0x14) / 0x32 + 0x5a) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f, fVar1, fVar2);
            break;

        case 6:
            if (puVar1[1] == 0x27)
            {
                puVar1[0] = 7;
            }
            fVar4 = ((f32)(puVar1[1] + -0x13) * 17.0f) / 31.0f;
            iVar2 = ((((puVar1[2] * 0x14) / 0x32 + 0x5a) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f,
                          222.0f - fVar4, 87.0f - fVar4);
            break;

        case 7:
            iVar2 = puVar1[1];
            if (iVar2 == 0x32)
            {
                return KWLNTASK_STOP;
            }
            fVar4 = ((f32)(iVar2 + -0x13) * 17.0f) / 31.0f;
            iVar2 = 0xff - ((iVar2 + -0x27) * 0xff) / 0xb;
            iVar3 = ((((puVar1[2] * 0x14) / 0x32 + 0x5a) * 0x1000) / 100) * 0x80;
            if (iVar3 < 0)
            {
                iVar3 = iVar3 + 0xfff;
            }
            func_001140d0(0xffffff00U | iVar2, iVar3 >> 0xc, iVar3 >> 0xc,
                          (const void*)(u32)puVar1[3], 0.0f,
                          222.0f - fVar4, 87.0f - fVar4);
            break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_00189810 NONMATCHING
void* func_00189810(KwlnTask* task)
{
    s32 param_1 = (s32)(u32)task;
    s32* puVar1;
    s32 iVar2;
    s32 iVar3;
    f32 fVar1;
    f32 fVar2;
    f32 fVar4;

    puVar1 = *(s32**)(param_1 + 0x3c);
    puVar1[1] = puVar1[1] + 1;
    puVar1[2] = puVar1[2] + 1;
    switch (puVar1[0])
    {
        case 0:
            if (puVar1[1] == 3)
            {
                puVar1[1] = 0;
                puVar1[2] = 0;
                puVar1[0] = 1;
            }
            break;

        case 1:
            if (puVar1[1] == 0xb)
            {
                puVar1[0] = 2;
            }
            break;

        case 2:
            if (puVar1[1] == 0xe)
            {
                puVar1[0] = 3;
            }
            fVar1 = (f32)(puVar1[1] + -0xc) / 2.0f;
            fVar1 += 311.0f;
            fVar2 = ((f32)(puVar1[1] + -0xc) * 7.0f) / 2.0f;
            fVar2 += 125.0f;
            iVar2 = ((((puVar1[2] * 0x14) / 0x32 + 0x50) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f, fVar1, fVar2);
            break;

        case 3:
            if (puVar1[1] == 0x10)
            {
                puVar1[0] = 4;
            }
            fVar1 = (f32)(puVar1[1] + -0xe) / 2.0f;
            fVar1 = 312.0f - fVar1;
            fVar2 = ((f32)(puVar1[1] + -0xe) * 10.0f) / 2.0f;
            fVar2 = 132.0f - fVar2;
            iVar2 = ((((puVar1[2] * 0x14) / 0x32 + 0x50) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f, fVar1, fVar2);
            break;

        case 4:
            if (puVar1[1] == 0x14)
            {
                puVar1[0] = 5;
            }
            fVar1 = (f32)(puVar1[1] + -0x10) / 4.0f;
            fVar1 = 311.0f - fVar1;
            fVar2 = ((f32)(puVar1[1] + -0x10) * 9.0f) / 4.0f;
            fVar2 += 122.0f;
            iVar2 = ((((puVar1[2] * 0x14) / 0x32 + 0x50) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f, fVar1, fVar2);
            break;

        case 5:
            if (puVar1[1] == 0x16)
            {
                puVar1[0] = 6;
            }
            fVar1 = (f32)(puVar1[1] + -0x14) / 2.0f;
            fVar1 += 310.0f;
            fVar2 = ((f32)(puVar1[1] + -0x14) * 6.0f) / 2.0f;
            fVar2 = 131.0f - fVar2;
            iVar2 = ((((puVar1[2] * 0x14) / 0x32 + 0x50) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f, fVar1, fVar2);
            break;

        case 6:
            if (puVar1[1] == 0x27)
            {
                puVar1[0] = 7;
            }
            fVar4 = ((f32)(puVar1[1] + -0x16) * 4.0f) / 28.0f;
            iVar2 = ((((puVar1[2] * 0x14) / 0x32 + 0x50) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f,
                          fVar4 + 311.0f, 125.0f - fVar4);
            break;

        case 7:
            iVar2 = puVar1[1];
            if (iVar2 == 0x32)
            {
                return KWLNTASK_STOP;
            }
            fVar4 = ((f32)(iVar2 + -0x16) * 4.0f) / 28.0f;
            iVar2 = 0xff - ((iVar2 + -0x27) * 0xff) / 0xb;
            iVar3 = ((((puVar1[2] * 0x14) / 0x32 + 0x50) * 0x1000) / 100) * 0x80;
            if (iVar3 < 0)
            {
                iVar3 = iVar3 + 0xfff;
            }
            func_001140d0(0xffffff00U | iVar2, iVar3 >> 0xc, iVar3 >> 0xc,
                          (const void*)(u32)puVar1[3], 0.0f,
                          fVar4 + 311.0f, 125.0f - fVar4);
            break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_00189DF0 NONMATCHING
void* func_00189df0(KwlnTask* task)
{
    s32 param_1 = (s32)(u32)task;
    s32* puVar1;
    s32 iVar2;
    s32 iVar3;

    puVar1 = *(s32**)(param_1 + 0x3c);
    puVar1[1] = puVar1[1] + 1;
    puVar1[2] = puVar1[2] + 1;
    switch (puVar1[0])
    {
        case 0:
            if (puVar1[1] == 3)
            {
                puVar1[1] = 0;
                puVar1[2] = 0;
                puVar1[0] = 1;
            }
            break;

        case 1:
            if (puVar1[1] == 0xe)
            {
                puVar1[0] = 2;
            }
            break;

        case 2:
            if (puVar1[1] == 0x11)
            {
                puVar1[0] = 3;
            }
            iVar2 = ((((puVar1[2] * 0x14) / 0x32 + 0x46) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f,
                          (f32)(puVar1[1] + -0xf) / 2.0f + 351.0f,
                          ((f32)(puVar1[1] + -0xf) * 3.0f) / 2.0f + 207.0f);
            break;

        case 3:
            if (puVar1[1] == 0x13)
            {
                puVar1[0] = 4;
            }
            iVar2 = ((((puVar1[2] * 0x14) / 0x32 + 0x46) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f,
                          352.0f - ((f32)(puVar1[1] + -0x11) * 2.0f) / 2.0f,
                          204.0f - ((f32)(puVar1[1] + -0x11) * 9.0f) / 2.0f);
            break;

        case 4:
            if (puVar1[1] == 0x17)
            {
                puVar1[0] = 5;
            }
            iVar2 = ((((puVar1[2] * 0x14) / 0x32 + 0x46) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f,
                          (f32)(puVar1[1] + -0x13) / 4.0f + 350.0f,
                          213.0f - ((f32)(puVar1[1] + -0x13) * 8.0f) / 4.0f);
            break;

        case 5:
            if (puVar1[1] == 0x19)
            {
                puVar1[0] = 6;
            }
            iVar2 = ((((puVar1[2] * 0x14) / 0x32 + 0x46) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f,
                          (f32)(puVar1[1] + -0x17) / 2.0f + 351.0f,
                          205.0f - ((f32)(puVar1[1] + -0x17) * 9.0f) / 2.0f);
            break;

        case 6:
            if (puVar1[1] == 0x27)
            {
                puVar1[0] = 7;
            }
            iVar2 = ((((puVar1[2] * 0x14) / 0x32 + 0x46) * 0x1000) / 100) * 0x80;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f,
                          ((f32)(puVar1[1] + -0x19) * 9.0f) / 25.0f + 352.0f,
                          ((f32)(puVar1[1] + -0x19) * 3.0f) / 25.0f + 214.0f);
            break;

        case 7:
            iVar2 = puVar1[1];
            if (iVar2 == 0x32)
            {
                return KWLNTASK_STOP;
            }
            iVar3 = ((((puVar1[2] * 0x14) / 0x32 + 0x46) * 0x1000) / 100) * 0x80;
            if (iVar3 < 0)
            {
                iVar3 = iVar3 + 0xfff;
            }
            func_001140d0(0xffffff00U |
                              (0xffU - ((iVar2 + -0x27) * 0xff) / 0xb),
                          iVar3 >> 0xc, iVar3 >> 0xc,
                          (const void*)(u32)puVar1[3], 0.0f,
                          ((f32)(iVar2 + -0x19) * 9.0f) / 25.0f + 352.0f,
                          ((f32)(iVar2 + -0x19) * 3.0f) / 25.0f + 214.0f);
            break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_0018A3F0 NONMATCHING
void* func_0018a3f0(KwlnTask* task)
{
    s32 param_1 = (s32)(u32)task;
    s32* puVar1;
    s32 iVar2;
    s32 iVar3;

    puVar1 = *(s32**)(param_1 + 0x3c);
    puVar1[1] = puVar1[1] + 1;
    puVar1[2] = puVar1[2] + 1;
    switch (puVar1[0])
    {
        case 0:
            if (puVar1[1] == 3)
            {
                puVar1[1] = 0;
                puVar1[2] = 0;
                puVar1[0] = 1;
            }
            break;

        case 1:
            if (puVar1[1] == 0x11)
            {
                puVar1[0] = 2;
            }
            break;

        case 2:
            if (puVar1[1] == 0x14)
            {
                puVar1[0] = 3;
            }
            iVar2 = ((((puVar1[2] * 5) / 0x32 + 0x5a) * 0x1000) / 100) * 0x40;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f,
                          419.0f, 273.0f - ((f32)(puVar1[1] + -0x12) * 2.0f) / 2.0f);
            break;

        case 3:
            if (puVar1[1] == 0x16)
            {
                puVar1[0] = 4;
            }
            iVar2 = ((((puVar1[2] * 5) / 0x32 + 0x5a) * 0x1000) / 100) * 0x40;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f,
                          ((f32)(puVar1[1] + -0x14) * 4.0f) / 2.0f + 419.0f,
                          ((f32)(puVar1[1] + -0x14) * 9.0f) / 2.0f + 271.0f);
            break;

        case 4:
            if (puVar1[1] == 0x1a)
            {
                puVar1[0] = 5;
            }
            iVar2 = ((((puVar1[2] * 5) / 0x32 + 0x5a) * 0x1000) / 100) * 0x40;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f,
                          (f32)(puVar1[1] + -0x16) / 4.0f + 423.0f,
                          280.0f - ((f32)(puVar1[1] + -0x16) * 4.0f) / 4.0f);
            break;

        case 5:
            if (puVar1[1] == 0x1c)
            {
                puVar1[0] = 6;
            }
            iVar2 = ((((puVar1[2] * 5) / 0x32 + 0x5a) * 0x1000) / 100) * 0x40;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f,
                          (f32)(puVar1[1] + -0x1a) / 2.0f + 428.0f,
                          ((f32)(puVar1[1] + -0x1a) * 10.0f) / 2.0f + 276.0f);
            break;

        case 6:
            if (puVar1[1] == 0x27)
            {
                puVar1[0] = 7;
            }
            iVar2 = ((((puVar1[2] * 5) / 0x32 + 0x5a) * 0x1000) / 100) * 0x40;
            iVar3 = iVar2 >> 0xc;
            if (iVar2 < 0)
            {
                iVar2 = iVar2 + 0xfff;
                iVar3 = iVar2 >> 0xc;
            }
            func_001140d0(0xffffffffU, iVar3, iVar3,
                          (const void*)(u32)puVar1[3], 0.0f,
                          ((f32)(puVar1[1] + -0x1c) * 22.0f) / 22.0f + 429.0f,
                          ((f32)(puVar1[1] + -0x1c) * 18.0f) / 22.0f + 286.0f);
            break;

        case 7:
            iVar2 = puVar1[1];
            if (iVar2 == 0x32)
            {
                return KWLNTASK_STOP;
            }
            iVar3 = ((((puVar1[2] * 5) / 0x32 + 0x5a) * 0x1000) / 100) * 0x40;
            if (iVar3 < 0)
            {
                iVar3 = iVar3 + 0xfff;
            }
            func_001140d0(0xffffff00U |
                              (0xffU - ((iVar2 + -0x27) * 0xff) / 0xb),
                          iVar3 >> 0xc, iVar3 >> 0xc,
                          (const void*)(u32)puVar1[3], 0.0f,
                          ((f32)(iVar2 + -0x1c) * 22.0f) / 22.0f + 429.0f,
                          ((f32)(iVar2 + -0x1c) * 18.0f) / 22.0f + 286.0f);
            break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_0018A9C0
void func_0018a9c0(KwlnTask* task)
{
    (*(void (**)(void*))0x0096017c)(task->workData);
}
