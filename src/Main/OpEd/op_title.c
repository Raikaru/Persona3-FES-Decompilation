#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

#include "libm.h"

extern void* opRes00266c50(u32 id);
extern void* func_0021cca0(void* resource, u32 index);
extern void* func_0021cce0(void* frame);
extern void func_0021d3b0(void* destination, void* source);
extern void func_0021d8e0(void* destination, const f32* layout);
extern void func_0021d890(void* destination, const f32* layout);
extern void func_0021d950(void* destination, const u8* color);
extern void (*D_00960090)(u32 state, u32 value);
extern void (*D_0096009C)(void* quad, u32 layer, u32 group, u32 pass, u32 blend);
extern void func_004d7f60(s32 state, u32 value);
extern void* (*DAT_00960178)(u32 size, u32 heap);
extern void (*DAT_0096017c)(void* memory);
extern void (*D_009600A4)(u32, u32, u32, u32, u32);
extern u32 FUN_00488f30(void);
extern f32 DAT_007cb164;
extern f32 DAT_007cad78;
extern f32 DAT_007cb08c;
void opTitle00269500(void);


static u32* sOpTitle; // DAT_007ce3ac / puGpffffb6bc

// FUN_002673a0
void opTitle002673a0(u32* param_1)
{
    K_ASSERT(sOpTitle == NULL, 0x95);
    *param_1 = 0;
    sOpTitle = param_1;
}

// FUN_002673f0
void opTitle002673f0(void)
{
    K_ASSERT(sOpTitle != NULL, 0x8e);
    sOpTitle = NULL;
}

// FUN_002694b0
void opTitle002694b0(void)
{
    K_ASSERT(sOpTitle != NULL, 0x8e);
    *sOpTitle &= 0xfffffffe;
}


// FUN_00267430 NONMATCHING
void opTitle00267430(void)
{
    u32* work;
    void* resource;
    void* frame;
    f32 layout[11];
    u8 color[4];
    f32 alpha;
    f32 scale;
    f32 offsetX;
    f32 offsetY;
    f32 scaleX;
    f32 scaleY;
    u32 timer;
    u32 random;
    s32 i;
    s32 j;

    K_ASSERT(sOpTitle != NULL, 0x8e);
    work = sOpTitle;
    resource = opRes00266c50(0);
    scale = 1.0f;

    if ((*work & 1) != 0)
    {
        if ((*work & 4) != 0)
        {
            if (work[2] == 1)
            {
                if ((s32)work[1] < 0x200)
                {
                    work[1]++;
                }
                else
                {
                    *work &= ~4;
                }
            }
            else if (work[2] == 0)
            {
                if ((s32)work[1] < 200)
                {
                    work[1]++;
                }
                else
                {
                    *work &= ~4;
                }
            }
        }

        if (work[2] == 1)
        {
            timer = work[1];
            if ((s32)timer < 0)
            {
                alpha = 1.0f;
            }
            else if (timer < 10)
            {
                alpha = 1.0f - (f32)timer / 10.0f;
                scale = 1.0f;
            }
            else
            {
                scale = DAT_007cb164;
                if (timer < 0xc)
                {
                    alpha = 0.0f;
                }
                else if (timer < 0x20)
                {
                    alpha = (f32)(timer - 0xc) / 20.0f;
                }
                else
                {
                    alpha = 1.0f;
                }
            }

            if ((s32)timer < 0)
            {
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else if (timer < 10)
            {
                offsetX = ((f32)timer / 10.0f) * 108.5f;
                offsetY = ((f32)timer / 10.0f) * -60.5f;
            }
            else if (timer < 0xc)
            {
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else if (timer < 0x20)
            {
                f32 t = (f32)(timer - 0xc) / 20.0f;
                offsetX = t * 108.5f + 108.5f;
                offsetY = t * -60.5f - 60.5f;
            }
            else
            {
                offsetX = 217.0f;
                offsetY = -121.0f;
            }
        }
        else
        {
            timer = work[1];
            if (timer < 0x46)
            {
                alpha = 0.0f;
            }
            else if (timer < 100)
            {
                alpha = (f32)(timer - 0x46) / 30.0f;
            }
            else
            {
                alpha = 1.0f;
            }
            offsetX = 0.0f;
            offsetY = 0.0f;
            scale = 1.0f;
        }

        frame = func_0021cca0(resource, 0xe);
        layout[0] = offsetX + 188.0f;
        layout[1] = offsetY + 144.0f;
        layout[2] = (f32)((s32*)frame)[3] * scale;
        layout[3] = (f32)((s32*)frame)[4] * scale;
        func_0021d8e0(work + 4, layout);
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = (u8)(alpha * 255.0f);
        func_0021d950(work + 4, color);

        if (work[2] == 1)
        {
            timer = work[1];
            if ((s32)timer < 0)
            {
                alpha = 1.0f;
            }
            else if (timer < 10)
            {
                alpha = 1.0f - (f32)timer / 10.0f;
            }
            else
            {
                scale = DAT_007cb164;
                if (timer < 0xc)
                {
                    alpha = 0.0f;
                }
                else if (timer < 0x20)
                {
                    alpha = (f32)(timer - 0xc) / 20.0f;
                }
                else
                {
                    alpha = 1.0f;
                }
            }
            offsetX = (405.0f - scale * 8.0f) - (scale * -8.0f + 188.0f);
            offsetY = (scale * 84.0f + 23.0f) - (scale * 84.0f + 144.0f);
            if ((s32)timer < 0)
            {
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else if (timer < 10)
            {
                offsetX = (offsetX / 2.0f) * ((f32)timer / 10.0f);
                offsetY = (offsetY / 2.0f) * ((f32)timer / 10.0f);
            }
            else if (timer < 0xc)
            {
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else if (timer < 0x20)
            {
                f32 t = (f32)(timer - 0xc) / 20.0f;
                offsetX = (offsetX / 2.0f) * t + offsetX / 2.0f;
                offsetY = (offsetY / 2.0f) * t + offsetY / 2.0f;
            }
        }
        else
        {
            timer = work[1];
            if (timer < 0x46)
            {
                alpha = 0.0f;
            }
            else if (timer < 100)
            {
                alpha = (f32)(timer - 0x46) / 30.0f;
            }
            else
            {
                alpha = 1.0f;
            }
        }

        frame = func_0021cca0(resource, 0xd);
        layout[0] = scale * -8.0f + 188.0f + offsetX;
        layout[1] = scale * 84.0f + 144.0f + offsetY;
        layout[2] = (f32)((s32*)frame)[3] * scale;
        layout[3] = (f32)((s32*)frame)[4] * scale;
        func_0021d8e0(work + 0x44, layout);
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = (u8)(alpha * 255.0f);
        func_0021d950(work + 0x44, color);

        if (work[2] == 1)
        {
            timer = work[1];
            if ((s32)timer < 0)
            {
                alpha = 1.0f;
            }
            else if (timer < 10)
            {
                alpha = 1.0f - (f32)timer / 10.0f;
            }
            else
            {
                scale = DAT_007cb164;
                if (timer < 0xc)
                {
                    alpha = 0.0f;
                }
                else if (timer < 0x20)
                {
                    alpha = (f32)(timer - 0xc) / 20.0f;
                }
                else
                {
                    alpha = 1.0f;
                }
            }
            offsetX = (scale * 182.0f + 405.0f) - (scale * 182.0f + 188.0f);
            offsetY = (23.0f - scale * 6.0f) - (scale * -6.0f + 144.0f);
            if ((s32)timer < 0)
            {
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else if (timer < 10)
            {
                offsetX = (offsetX / 2.0f) * ((f32)timer / 10.0f);
                offsetY = (offsetY / 2.0f) * ((f32)timer / 10.0f);
            }
            else if (timer < 0xc)
            {
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else if (timer < 0x20)
            {
                f32 t = (f32)(timer - 0xc) / 20.0f;
                offsetX = (offsetX / 2.0f) * t + offsetX / 2.0f;
                offsetY = (offsetY / 2.0f) * t + offsetY / 2.0f;
            }
        }
        else
        {
            timer = work[1];
            if (timer < 0x78)
            {
                alpha = 0.0f;
            }
            else if (timer < 0xa5)
            {
                alpha = (f32)(timer - 0x78) / 45.0f;
            }
            else
            {
                alpha = 1.0f;
            }
        }

        frame = func_0021cca0(resource, 0x24);
        layout[0] = scale * 182.0f + 188.0f + offsetX;
        layout[1] = scale * -6.0f + 144.0f + offsetY;
        layout[2] = (f32)((s32*)frame)[3] * scale;
        layout[3] = (f32)((s32*)frame)[4] * scale;
        func_0021d8e0(work + 0x104, layout);
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = (u8)(alpha * 255.0f);
        func_0021d950(work + 0x104, color);

        if (work[2] == 1)
        {
            timer = work[1];
            alpha = 0.0f;
            if ((s32)timer < 0)
            {
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else if (timer < 10)
            {
                offsetX = ((f32)timer / 10.0f) * 98.5f;
                offsetY = ((f32)timer / 10.0f) * -62.5f;
            }
            else if (timer < 0xc)
            {
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else if (timer < 0x20)
            {
                f32 t = (f32)(timer - 0xc) / 20.0f;
                offsetX = t * 98.5f + 98.5f;
                offsetY = t * -62.5f - 62.5f;
            }
            else
            {
                offsetX = 197.0f;
                offsetY = -125.0f;
            }
        }
        else
        {
            timer = work[1];
            if (timer < 0x5f)
            {
                alpha = 0.0f;
            }
            else if (timer < 0x82)
            {
                alpha = (f32)(timer - 0x5f) / 35.0f;
            }
            else if (timer < 0xa0)
            {
                alpha = 1.0f;
            }
            else if (timer < 0xb4)
            {
                alpha = 1.0f - (f32)(timer - 0xa0) / 20.0f;
            }
            else
            {
                alpha = 0.0f;
            }
        }

        frame = func_0021cca0(resource, 0x25);
        layout[0] = offsetX + 368.0f;
        layout[1] = offsetY + 137.0f;
        layout[2] = (f32)((s32*)frame)[3];
        layout[3] = (f32)((s32*)frame)[4];
        func_0021d8e0(work + 0xc4, layout);
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = (u8)(alpha * 255.0f);
        func_0021d950(work + 0xc4, color);

        if (work[2] == 1)
        {
            timer = work[1];
            alpha = 0.0f;
            if ((s32)timer < 0)
            {
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else if (timer < 10)
            {
                offsetX = ((f32)timer / 10.0f) * 98.5f;
                offsetY = ((f32)timer / 10.0f) * -62.5f;
            }
            else if (timer < 0xc)
            {
                offsetX = 0.0f;
                offsetY = 0.0f;
            }
            else if (timer < 0x20)
            {
                f32 t = (f32)(timer - 0xc) / 20.0f;
                offsetX = t * 98.5f + 98.5f;
                offsetY = t * -62.5f - 62.5f;
            }
            else
            {
                offsetX = 197.0f;
                offsetY = -125.0f;
            }
        }
        else
        {
            timer = work[1];
            if (timer < 0x90)
            {
                alpha = 0.0f;
            }
            else if (timer < 0x91)
            {
                alpha = (f32)(timer - 0x90);
            }
            else if (timer < 0xb4)
            {
                alpha = 1.0f - (f32)(timer - 0x91) / 35.0f;
            }
            else
            {
                alpha = 0.0f;
            }
            alpha *= DAT_007cad78;
        }

        frame = func_0021cca0(resource, 0x25);
        layout[0] = offsetX + 368.0f;
        layout[1] = offsetY + 137.0f;
        layout[2] = (f32)((s32*)frame)[3];
        layout[3] = (f32)((s32*)frame)[4];
        func_0021d8e0(work + 0x144, layout);
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = (u8)(alpha * 255.0f);
        func_0021d950(work + 0x144, color);

        if (work[2] == 1)
        {
            timer = work[1];
            if ((s32)timer < 0)
            {
                alpha = 1.0f;
            }
            else if (timer < 0x19)
            {
                alpha = (f32)timer / 25.0f;
            }
            else
            {
                alpha = 1.0f;
            }
            scale = 1.0f;
            alpha = 1.0f - alpha;
            if ((s32)timer < 0)
            {
                scale = 0.0f;
            }
            else if (timer < 0x19)
            {
                scale = (f32)timer / 25.0f;
            }
            scaleX = scale * 1.5f + 1.0f;
            scaleY = 1.0f - DAT_007cb08c * scale;
            layout[0] = 0.0f;
            layout[1] = 0.0f;
            layout[2] = 640.0f;
            layout[3] = 0.0f;
            layout[4] = 640.0f;
            layout[5] = 448.0f;
            layout[6] = 0.0f;
            layout[7] = 448.0f;
            for (i = 0; i < 4; i++)
            {
                layout[i * 2] -= 320.0f;
                layout[i * 2 + 1] -= 224.0f;
            }
            for (i = 0; i < 4; i++)
            {
                layout[i * 2] *= scaleX;
                layout[i * 2 + 1] *= scaleY;
            }
            for (i = 0; i < 4; i++)
            {
                layout[i * 2] += 320.0f;
                layout[i * 2 + 1] += 224.0f;
            }
            func_0021d890(work + 0x84, layout);
        }
        else
        {
            timer = work[1];
            if (timer < 0x78)
            {
                alpha = 0.0f;
            }
            else if (timer < 0xdc)
            {
                alpha = (f32)(timer - 0x78) / 100.0f;
            }
            else
            {
                alpha = 1.0f;
            }
            (void)func_0021cca0(resource, 0x11);
            layout[0] = 0.0f;
            layout[1] = 0.0f;
            layout[2] = 640.0f;
            layout[3] = 448.0f;
            func_0021d8e0(work + 0x84, layout);
        }
        (void)func_0021cca0(resource, 0x11);
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = (u8)(alpha * 255.0f);
        func_0021d950(work + 0x84, color);

        for (timer = 0; timer < 3; timer++)
        {
            if ((s32)work[timer * 2 + 0x40e] < (s32)work[timer * 2 + 0x40d])
            {
                work[timer * 2 + 0x40e]++;
            }
            else
            {
                work[timer * 2 + 0x40e] = 0;
                random = FUN_00488f30();
                work[timer * 2 + 0x40d] = (random & 3) + 4;
                for (i = 0; i < 9 && (work[i * 0x48 + 0x184] & 1) != 0; i++)
                {
                }
                K_ASSERT(i < 9, 0x36f);
                work[i * 0x48 + 0x184] |= 1;
                work[i * 0x48 + 0x1c8] = 0;
                work[i * 0x48 + 0x1c9] = timer;
            }
        }

        if (work[2] == 1)
        {
            timer = work[1];
            if ((s32)timer < 0)
            {
                scale = 0.0f;
            }
            else if (timer < 0x19)
            {
                scale = (f32)timer / 25.0f;
            }
            else
            {
                scale = 1.0f;
            }
            scaleX = scale * 1.5f + 1.0f;
            scaleY = 1.0f - DAT_007cb08c * scale;
        }
        (void)func_0021cca0(resource, 0xf);
        for (i = 0; i < 9; i++)
        {
            u32* slot = work + i * 0x48 + 0x184;
            if ((*slot & 1) != 0)
            {
                if ((s32)slot[0x44] < 0xc)
                {
                    slot[0x44]++;
                    timer = slot[0x45];
                    if (timer == 2)
                    {
                        offsetY = 236.0f;
                    }
                    else if (timer == 1)
                    {
                        offsetY = 187.0f;
                    }
                    else
                    {
                        offsetY = 127.0f;
                    }

                    if (timer == 1)
                    {
                        offsetX = ((f32)(s32)slot[0x44] / 12.0f) * -1840.0f + 640.0f;
                    }
                    else
                    {
                        offsetX = ((f32)(s32)slot[0x44] / 12.0f) * 1840.0f - 1200.0f;
                    }

                    if (work[2] == 1)
                    {
                        layout[0] = offsetX;
                        layout[1] = offsetY;
                        layout[2] = offsetX + 1000.0f;
                        layout[3] = offsetY;
                        layout[4] = offsetX + 1000.0f;
                        layout[5] = offsetY + 40.0f;
                        layout[6] = offsetX;
                        layout[7] = offsetY + 40.0f;
                        for (j = 0; j < 4; j++)
                        {
                            layout[j * 2] -= 320.0f;
                            layout[j * 2 + 1] -= 224.0f;
                        }
                        for (j = 0; j < 4; j++)
                        {
                            layout[j * 2] *= scaleX;
                            layout[j * 2 + 1] *= scaleY;
                        }
                        for (j = 0; j < 4; j++)
                        {
                            layout[j * 2] += 320.0f;
                            layout[j * 2 + 1] += 224.0f;
                        }
                        func_0021d890(slot + 4, layout);
                    }
                    else
                    {
                        layout[0] = offsetX;
                        layout[1] = offsetY;
                        layout[2] = 1000.0f;
                        layout[3] = 40.0f;
                        func_0021d8e0(slot + 4, layout);
                    }
                    color[0] = 0xff;
                    color[1] = 0xff;
                    color[2] = 0xff;
                    color[3] = 0x14;
                    func_0021d950(slot + 4, color);
                }
                else
                {
                    *slot &= ~1;
                }
            }
        }
    }
}

// FUN_00268E20 NONMATCHING
void opTitle00268e20(void)
{
    u32* work;
    void* resource;
    void* frame;
    s32 i;

    K_ASSERT(sOpTitle != NULL, 0x8e);
    work = sOpTitle;
    resource = opRes00266c50(0);
    if ((*work & 1) != 0)
    {
        (*D_00960090)(8, 0);
        (*D_00960090)(6, 0);
        (*D_00960090)(9, 2);

        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        frame = func_0021cce0(func_0021cca0(resource, 0xe));
        (*D_00960090)(1, (u32)(uintptr_t)frame);
        (*D_0096009C)(work + 4, 4, 0, 1, 2);
        (*D_0096009C)(work + 4, 4, 0, 2, 3);

        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        frame = func_0021cce0(func_0021cca0(resource, 0xd));
        (*D_00960090)(1, (u32)(uintptr_t)frame);
        (*D_0096009C)(work + 0x44, 4, 0, 1, 2);
        (*D_0096009C)(work + 0x44, 4, 0, 2, 3);

        func_004d7f60(2, 0x48);
        func_004d7f60(3, 0x71801);
        frame = func_0021cce0(func_0021cca0(resource, 0x25));
        (*D_00960090)(1, (u32)(uintptr_t)frame);
        (*D_0096009C)(work + 0xc4, 4, 0, 1, 2);
        (*D_0096009C)(work + 0xc4, 4, 0, 2, 3);

        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        frame = func_0021cce0(func_0021cca0(resource, 0x24));
        (*D_00960090)(1, (u32)(uintptr_t)frame);
        (*D_0096009C)(work + 0x104, 4, 0, 1, 2);
        (*D_0096009C)(work + 0x104, 4, 0, 2, 3);

        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        for (i = 0; i < 9; i++)
        {
            if ((work[i * 0x48 + 0x184] & 1) != 0)
            {
                func_004d7f60(2, 0x6a);
                frame = func_0021cce0(func_0021cca0(resource, 0x11));
                (*D_00960090)(1, (u32)(uintptr_t)frame);
                (*D_0096009C)(work + 0x84, 4, 0, 1, 2);
                (*D_0096009C)(work + 0x84, 4, 0, 2, 3);

                func_004d7f60(2, 0x58);
                frame = func_0021cce0(func_0021cca0(resource, 0xf));
                (*D_00960090)(1, (u32)(uintptr_t)frame);
                (*D_0096009C)(work + i * 0x48 + 0x188, 4, 0, 1, 2);
                (*D_0096009C)(work + i * 0x48 + 0x188, 4, 0, 2, 3);
            }
        }
    }
}

// FUN_002692D0 NONMATCHING
void opTitle002692d0(void)
{
    u32* work;
    void* resource;
    void* frame;
    u32 random;
    s32 i;

    K_ASSERT(sOpTitle != NULL, 0x8e);
    work = sOpTitle;
    resource = opRes00266c50(0);
    frame = func_0021cca0(resource, 0xe);
    func_0021d3b0(work + 4, frame);
    frame = func_0021cca0(resource, 0xd);
    func_0021d3b0(work + 0x44, frame);
    frame = func_0021cca0(resource, 0x25);
    func_0021d3b0(work + 0xc4, frame);
    frame = func_0021cca0(resource, 0x24);
    func_0021d3b0(work + 0x104, frame);
    frame = func_0021cca0(resource, 0x25);
    func_0021d3b0(work + 0x144, frame);
    frame = func_0021cca0(resource, 0x11);
    func_0021d3b0(work + 0x84, frame);
    for (i = 0; i < 9; i++)
    {
        work[i * 0x48 + 0x184] = 0;
        work[i * 0x48 + 0x1c8] = 0;
        frame = func_0021cca0(resource, 0xf);
        func_0021d3b0(work + i * 0x48 + 0x188, frame);
    }
    for (i = 0; i < 3; i++)
    {
        work[i * 2 + 0x40e] = 0;
        random = FUN_00488f30();
        work[i * 2 + 0x40d] = random & 7;
    }
    opTitle00269500();
    *work |= 1;
}

// FUN_00269500
void opTitle00269500(void)
{
    u32* work;

    K_ASSERT(sOpTitle != NULL, 0x8e);
    work = sOpTitle;
    work[1] = 0;
    work[2] = 0;
    *work |= 4;
}

// FUN_00269550
void opTitle00269550(void)
{
    u32* work;

    K_ASSERT(sOpTitle != NULL, 0x8e);
    work = sOpTitle;
    work[1] = 0;
    work[2] = 1;
    *work |= 4;
}

// FUN_00269640
u32 opTitle00269640(void)
{
    K_ASSERT(sOpTitle != NULL, 0x8e);
    return *sOpTitle & 4;
}

// FUN_002695b0
void opTitle002695b0(void)
{
    u32* puVar1;

    K_ASSERT(sOpTitle != NULL, 0x8e);
    puVar1 = sOpTitle;
    K_ASSERT((*sOpTitle & 4) != 0, 0x4bc);
    K_ASSERT(puVar1[2] == 0, 0x4bd);
    puVar1[1] = 200;
}

// FUN_00269690 NONMATCHING
u32* opTitle00269690(s32 mode, s32 columns, s32 rows)
{
    s32 halfRows;
    s32 indexCount;
    s32 vertexCount;
    s32 row;
    s32 column;
    s16 value;
    s16* indices;
    u32* mesh;
    void* memory;
    s32 rowWidth;

    if (mode == 1)
    {
        halfRows = rows >> 1;
        if ((rows & 1) == 0)
        {
            if (rows < 0)
            {
                halfRows = (rows + 1) >> 1;
            }
            rowWidth = (columns + 1) * rows;
            if (rowWidth < 0)
            {
                rowWidth++;
            }
            indexCount = (columns + 2) * (halfRows + 1) + (rowWidth >> 1);
        }
        else
        {
            if (rows < 0)
            {
                halfRows = (rows + 1) >> 1;
            }
            indexCount = (halfRows + 1) * (columns * 2 + 3);
        }
        vertexCount = rows * (columns * 6 + 3);
    }
    else if (mode == 0)
    {
        indexCount = (rows + 1) * (columns + 1);
        vertexCount = columns * rows * 6;
    }
    else
    {
        indexCount = 0;
        vertexCount = 0;
    }

    memory = (*DAT_00960178)((u32)(indexCount * 0x40 + 0x20 + vertexCount * 2), 0x40000);
    mesh = (u32*)memory;
    mesh[0] = (u32)(uintptr_t)(mesh + 8);
    mesh[1] = (u32)(uintptr_t)(mesh + 8 + indexCount * 0x10);

    if (mode == 1)
    {
        value = 0;
        indices = (s16*)(uintptr_t)mesh[1];
        for (row = 0; row < rows; row++)
        {
            for (column = 0; column < columns; column++)
            {
                if ((row & 1) == 0)
                {
                    indices[0] = value;
                    indices[1] = value + columns + 2;
                    indices[2] = value + columns + 1;
                    indices[3] = value;
                    indices[4] = value + 1;
                    indices[5] = value + columns + 2;
                }
                else
                {
                    indices[0] = value;
                    indices[1] = value + 1;
                    indices[2] = value + columns + 2;
                    indices[3] = value + 1;
                    indices[4] = value + columns + 3;
                    indices[5] = value + columns + 2;
                }
                value++;
                indices += 6;
            }
            if ((row & 1) == 0)
            {
                indices[0] = value;
                indices[1] = value + columns + 2;
                indices[2] = value + columns + 1;
                value++;
            }
            else
            {
                indices[0] = value;
                indices[1] = value + 1;
                indices[2] = value + columns + 2;
                value += 2;
            }
            indices += 3;
        }
    }
    else if (mode == 0)
    {
        value = 0;
        indices = (s16*)(uintptr_t)mesh[1];
        for (row = 0; row < rows; row++)
        {
            for (column = 0; column < columns; column++)
            {
                indices[0] = value;
                indices[1] = value + 1;
                indices[2] = value + columns + 1;
                indices[3] = value + 1;
                indices[4] = value + columns + 2;
                indices[5] = value + columns + 1;
                indices += 6;
                value++;
            }
            value++;
        }
    }

    mesh[6] = (u32)mode;
    mesh[2] = (u32)columns;
    mesh[3] = (u32)rows;
    mesh[4] = (u32)indexCount;
    mesh[5] = (u32)vertexCount;
    return mesh;
}

// FUN_002699A0 NONMATCHING
void opTitle002699a0(void* memory)
{
    (*DAT_0096017c)(memory);
}

// FUN_002699D0 NONMATCHING
void opTitle002699d0(u32* vertex)
{
    (*D_009600A4)(3, vertex[0], vertex[4], vertex[1], vertex[5]);
}

// FUN_00269A10 NONMATCHING
void opTitle00269a10(u32* mesh, u32* callback)
{
    s32 i;
    s32 j;
    s32 rowWidth;
    u32 k;

    f32 u;
    f32 v;
    struct
    {
        u32 mesh;
        f32 u;
        f32 v;
        u32 user;
        u32 index;
    } args;

    args.mesh = (u32)(uintptr_t)mesh;
    args.user = callback[1];
    if (mesh[6] == 1)
    {
        i = 0;
        for (j = 0; j < (s32)mesh[3] + 1; j++)
        {
            rowWidth = ((j & 1) == 0) ? (s32)mesh[2] + 1 : (s32)mesh[2] + 2;
            for (k = 0; k < (u32)rowWidth; k++)
            {
                if ((j & 1) == 0)
                {
                    u = (f32)k / (f32)mesh[2];
                }
                else if (k == 0)
                {
                    u = 0.0f;
                }
                else if ((s32)k == rowWidth - 1)
                {
                    u = 1.0f;
                }
                else
                {
                    u = 1.0f / (f32)mesh[2] * (f32)((s32)k - 1) +
                        1.0f / (f32)mesh[2] / 2.0f;
                }
                v = (f32)j / (f32)mesh[3];
                args.index = (u32)i;
                args.u = u;
                args.v = v;
                ((void (*)(void*))callback[0])(&args);
                i++;
            }
        }
    }
    else if (mesh[6] == 0)
    {
        for (j = 0; j < (s32)mesh[3] + 1; j++)
        {
            for (i = 0; i < (s32)mesh[2] + 1; i++)
            {
                args.index = (u32)(i + ((s32)mesh[2] + 1) * j);
                args.u = (f32)i / (f32)mesh[2];
                args.v = (f32)j / (f32)mesh[3];
                ((void (*)(void*))callback[0])(&args);
            }
        }
    }
}

// FUN_00269C80
f32 opTitle00269c80(f32 value)
{
    return sinf(value);
}

// FUN_00269CA0
f32 opTitle00269ca0(f32 value)
{
    return cosf(value);
}







