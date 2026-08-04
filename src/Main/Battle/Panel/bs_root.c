#include "Main/Battle/Panel/bs_root.h"
#include "Main/Battle/Panel/bp_tex.h"
#include "h_cdvd.h"
#include "rw/rwcore.h"

#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "libm.h"
typedef int (*code)(...);
extern void* opRes00266c50(u32 id);
#pragma alias opRes00266c50 opResGetTitleSprite
extern void* func_0021cca0_u32(void* resource, u32 index);
#pragma alias func_0021cca0_u32 func_0021cca0
extern void* func_0021cce0_ptr(void* frame);
#pragma alias func_0021cce0_ptr func_0021cce0
extern void func_0021d3b0(void* destination, void* source);
extern void func_0021d8e0(void* destination, const f32* layout);
extern void func_0021d890(void* destination, const f32* layout);
extern void func_0021d950(void* destination, const u8* color);
extern void (*D_00960090)(u32 state, u32 value);
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
extern void (*D_0096009C)(void* quad, u32 layer, u32 group, u32 pass, u32 blend);
#pragma alias D_0096009C_abs D_0096009C
extern u8 D_0096009C_abs[];
extern void func_004d7f60(s32 state, u32 value);
extern u32 (*DAT_00960178_abs[])(u32 size, u32 heap);
extern void (*DAT_0096017c[])(void* memory);
extern void (*D_009600A4[])(u32, u32, u32, u32, u32);
extern u32 FUN_00488f30(void);
extern f32 DAT_007cb164;
extern f32 DAT_007cad78;
extern f32 DAT_007cb08c;
void opTitle00269500(void);
static u32* sOpTitle; // DAT_007ce3ac / puGpffffb6bc
typedef struct OpTitleMesh
{
    s32 unk0;
    s32 unk4;
    s32 width;
    s32 height;
    s32 unk10;
    s32 unk14;
    s32 mode;
} OpTitleMesh;
#pragma alias bpPersonaInit FUN_00266eb0
#pragma alias bpPersonaShutdown FUN_00266f00
#pragma alias bpPersonaLoad FUN_00266F60
#pragma alias bpPersonaDestroy FUN_00267120
#pragma alias bpPersonaUpdate FUN_00267180
#pragma alias bpPersonaIsLoading FUN_00267210
#pragma alias bpPersonaSetPersona FUN_00267070
static u32* sBpPersona; // DAT_007ce398
void bpPersonaDestroy();
long FUN_003c9ab0();
u32 FUN_001749a0(u32 param_1);
u32 FUN_003c9850(u32 param_1, u32 param_2, u32 param_3, u32 param_4);
void FUN_003c9b00(u32 param_1, u32 param_2, u32 param_3);
void FUN_003c9cd0(u32 param_1, s64 param_2);
void FUN_003c9d00(u32 param_1, u32 param_2);
s32 FUN_001756f0(void);
void FUN_003c9e00(u32 param_1, u32 param_2);
u32 FUN_001749a0();
void FUN_003c9b00();





#define BSROOT_INIT_TMXCOUNT 2

// `bpTex0021c9f0` returns an opaque rush-panel sprite resource.
static void* sRushRaster;                        // 007ce3a8
static RwRaster* sRasters[BSROOT_INIT_TMXCOUNT]; // 007ce3a0

// FUN_00266eb0
void bpPersonaInit(u32* param_1)
{
    K_ASSERT(sBpPersona == NULL, 0x2b);
    *param_1 = 0;
    sBpPersona = param_1;
}

// FUN_00266f00
void bpPersonaShutdown(void)
{
    K_ASSERT(sBpPersona != NULL, 0x24);
    if (*sBpPersona & 1) {
        bpPersonaDestroy();
    }
    sBpPersona = NULL;
}

// FUN_00266F60
void bpPersonaLoad(u32 param_1)
{
    u32* work;
    u32 persona;

    K_ASSERT(sBpPersona != NULL, 0x24);
    work = sBpPersona;
    *(u16*)(work + 2) = (u16)param_1;
    persona = FUN_001749a0(param_1);
    work[1] = FUN_003c9850(0, 0, 5, 0);
    FUN_003c9b00(work[1], persona, 0);
    FUN_003c9cd0(work[1], (s64)-1);
    FUN_003c9d00(work[1], 8);
    if ((u16)FUN_001756f0() > 1)
    {
        FUN_003c9e00(work[1], 1);
    }
    else
    {
        FUN_003c9e00(work[1], 0);
    }
    *work |= 2;
    *work |= 1;
}









static inline void opTitleSetPoly(void* destination, f32* layout, f32 scaleX, f32 scaleY)
{
    s32 i;

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
    func_0021d890(destination, layout);
}

// FUN_00267070
void bpPersonaSetPersona(u32 param_1)
{
    u32* work;
    u32 uVar2;

    K_ASSERT(sBpPersona != NULL, 0x24);
    work = sBpPersona;
    K_ASSERT((u16)sBpPersona[2] != (u16)param_1, 0x5c);
    *(u16*)(work + 2) = param_1;
    uVar2 = FUN_001749a0(param_1);
    FUN_003c9b00(work[1], uVar2, 0);
    *work |= 2;
}

// FUN_00267120
void bpPersonaDestroy(void)
{
    u32* work;

    K_ASSERT(sBpPersona != NULL, 0x24);
    work = sBpPersona;
    kwlnTaskDestroyWithHierarchy((KwlnTask*)work[1]);
    *work &= 0xfffffffe;
}

// FUN_00267180
void bpPersonaUpdate(void)
{
    u32* work;

    K_ASSERT(sBpPersona != NULL, 0x24);
    work = sBpPersona;
    if ((~*work & 1) == 0 && (*work & 2) != 0 && FUN_003c9ab0(work[1]) != 0) {
        *work &= 0xfffffffd;
    }
}


// FUN_00267210
u32 bpPersonaIsLoading(void)
{
    K_ASSERT(sBpPersona != NULL, 0x24);
    return *sBpPersona & 2;
}
// FUN_00267260
void bsRootInit(void)
{
    HCdvd* cdvd;
    s32 contentId;
    void* file;
    u32 fileSize;

    cdvd = H_Cdvd_Request("battle/panel/bs_init.bin", HCDVD_FILENORMAL); // BUG: should be 'HCDVD_FILEARCHIVE'
    H_Cdvd_ReadSync(cdvd);

    for (contentId = 0; contentId < BSROOT_INIT_MAX; contentId++)
    {
        file = H_Cdvd_ArchiveGetFile(cdvd, contentId, &fileSize);

        switch (contentId)
        {
            case BSROOT_INIT_PCADVANTAGE:
                sRasters[contentId] = bpTexCreateTmxRaster(file);
                break;
            case BSROOT_INIT_ECADVANTAGE:
                sRasters[contentId] = bpTexCreateTmxRaster(file);
                break;

            case BSROOT_INIT_RUSH:
                sRushRaster = bpTex0021c9f0(file);
                break;
        }
    }

    H_Cdvd_Destroy(cdvd);
}

// FUN_00267370
RwRaster* bsRootGetRaster(u32 id)
{
    return sRasters[id];
}

// FUN_00267390
void* bsRootGetRushRaster(void)
{
    return sRushRaster;
}

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

// W419 negative probe: DAT_007cb164 float-array .sdata alias left opTitle00267430 at nd3280/6340B, window6640B, rate51.74%; reverted.
/* W455 retail state-1 dispatch keeps the polygon transform path out of line;
 * the explicit switch preserves that decoded branch skeleton. */
// FUN_00267430 NONMATCHING
void opTitle00267430(void)
{
    u32* work;
    void* resource;
    void* frame;
    f32 layout[11];
    u8 color[4];
    f32 alpha;
    f32 offsetX;
    f32 offsetY;
    f32 scaleX;
    f32 scaleY;
    f32 scale;
    s32 timer;
    u32 random;
    s32 i;
    s32 j;

    K_ASSERT(sOpTitle != NULL, 0x8e);
    work = sOpTitle;
    resource = opRes00266c50(0);
    scale = 1.0f;

    if ((~*work & 1) == 0)
    {
        if ((*work & 4) != 0)
        {
            switch (work[2])
            {
            case 0:
                if ((s32)work[1] < 200)
                {
                    work[1]++;
                }
                else
                {
                    *work &= ~4;
                }
                break;
            case 1:
                if ((s32)work[1] < 0x200)
                {
                    work[1]++;
                }
                else
                {
                    *work &= ~4;
                }
                break;
            }
        }

        switch (work[2])
        {
        case 0:
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
            break;
        case 1:
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
                if (timer < 0xc)
                {
                    scale = DAT_007cb164;
                    alpha = 0.0f;
                }
                else if (timer < 0x20)
                {
                    scale = DAT_007cb164;
                    alpha = (f32)(timer - 0xc) / 20.0f;
                }
                else
                {
                    scale = DAT_007cb164;
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
                offsetY = t * -60.5f + -60.5f;
            }
            else
            {
                offsetX = 217.0f;
                offsetY = -121.0f;
            }
            break;
        }

        frame = func_0021cca0_u32(resource, 0xe);
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

        switch (work[2])
        {
        case 0:
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
            break;
        case 1:
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
                if (timer < 0xc)
                {
                    scale = DAT_007cb164;
                    alpha = 0.0f;
                }
                else if (timer < 0x20)
                {
                    scale = DAT_007cb164;
                    alpha = (f32)(timer - 0xc) / 20.0f;
                }
                else
                {
                    scale = DAT_007cb164;
                    alpha = 1.0f;
                }
            }
            offsetX = (405.0f - scale * 8.0f) - (scale * -8.0f + 188.0f);
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
            break;
        }

        frame = func_0021cca0_u32(resource, 0xd);
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

        switch (work[2])
        {
        case 0:
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
            break;
        case 1:
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
                if (timer < 0xc)
                {
                    scale = DAT_007cb164;
                    alpha = 0.0f;
                }
                else if (timer < 0x20)
                {
                    scale = DAT_007cb164;
                    alpha = (f32)(timer - 0xc) / 20.0f;
                }
                else
                {
                    scale = DAT_007cb164;
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
            break;
        }

        frame = func_0021cca0_u32(resource, 0x24);
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

        switch (work[2])
        {
        case 0:
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
            break;
        case 1:
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
                offsetY = t * -62.5f + -62.5f;
            }
            else
            {
                offsetX = 197.0f;
                offsetY = -125.0f;
            }
            break;
        }

        frame = func_0021cca0_u32(resource, 0x25);
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
                offsetY = t * -62.5f + -62.5f;
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

        frame = func_0021cca0_u32(resource, 0x25);
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

        switch (work[2])
        {
        case 1:
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
            opTitleSetPoly(work + 0x84, layout, scaleX, scaleY);
            break;
        }
        default:
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
            (void)func_0021cca0_u32(resource, 0x11);
            layout[0] = 0.0f;
            layout[1] = 0.0f;
            layout[2] = 640.0f;
            layout[3] = 448.0f;
            func_0021d8e0(work + 0x84, layout);
            break;
        }
        }
        (void)func_0021cca0_u32(resource, 0x11);
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

        switch (work[2])
        {
        case 1:
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
            break;
        }
            (void)func_0021cca0_u32(resource, 0xf);
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
                        opTitleSetPoly(slot + 4, layout, scaleX, scaleY);
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

// FUN_00268E20
void opTitle00268e20(void)
{
    void* frame;
    code *state;
    s32 i;
    u32* slot;
    code *quad;
    void* resource;
    u32* work;

    K_ASSERT(sOpTitle != NULL, 0x8e);
    work = sOpTitle;
    resource = opRes00266c50(0);
    if ((~*work & 1) == 0)
    {
        state = (code *)&D_00960090_abs;
        (*state)(8, 0);
        (*state)(6, 0);
        (*state)(9, 2);

        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        frame = func_0021cce0_ptr(func_0021cca0_u32(resource, 0xe));
        (*state)(1, (u32)(uintptr_t)frame);
        quad = (code *)&D_0096009C_abs;
        (*quad)(work + 4, 4, 0, 1, 2);
        (*quad)(work + 4, 4, 0, 2, 3);

        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        frame = func_0021cce0_ptr(func_0021cca0_u32(resource, 0xd));
        (*state)(1, (u32)(uintptr_t)frame);
        (*quad)(work + 0x44, 4, 0, 1, 2);
        (*quad)(work + 0x44, 4, 0, 2, 3);

        func_004d7f60(2, 0x48);
        func_004d7f60(3, 0x71801);
        frame = func_0021cce0_ptr(func_0021cca0_u32(resource, 0x25));
        (*state)(1, (u32)(uintptr_t)frame);
        (*quad)(work + 0xc4, 4, 0, 1, 2);
        (*quad)(work + 0xc4, 4, 0, 2, 3);

        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        frame = func_0021cce0_ptr(func_0021cca0_u32(resource, 0x24));
        (*state)(1, (u32)(uintptr_t)frame);
        (*quad)(work + 0x104, 4, 0, 1, 2);
        (*quad)(work + 0x104, 4, 0, 2, 3);

        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        for (i = 0; i < 9; i++)
        {
            slot = work + i * 0x48 + 0x184;
            if ((~*slot & 1) == 0)
            {
                func_004d7f60(2, 0x6a);
                frame = func_0021cce0_ptr(func_0021cca0_u32(resource, 0x11));
                state = (code *)&D_00960090_abs;
                (*state)(1, (u32)(uintptr_t)frame);
                quad = (code *)&D_0096009C_abs;
                (*quad)(work + 0x84, 4, 0, 1, 2);
                (*quad)(work + 0x84, 4, 0, 2, 3);

                func_004d7f60(2, 0x58);
                frame = func_0021cce0_ptr(func_0021cca0_u32(resource, 0xf));
                (*state)(1, (u32)(uintptr_t)frame);
                (*quad)(slot + 4, 4, 0, 1, 2);
                (*quad)(slot + 4, 4, 0, 2, 3);
            }
        }
    }
}

// FUN_002692D0
void opTitle002692d0(void)
{
    u32* work;
    void* resource;
    void* frame;
    u32* slot;
    u32 random;
    s32 i;
    K_ASSERT(sOpTitle != NULL, 0x8e);
    work = sOpTitle;
    resource = opRes00266c50(0);
    frame = func_0021cca0_u32(resource, 0xe);
    func_0021d3b0(work + 4, frame);
    frame = func_0021cca0_u32(resource, 0xd);
    func_0021d3b0(work + 0x44, frame);
    frame = func_0021cca0_u32(resource, 0x25);
    func_0021d3b0(work + 0xc4, frame);
    frame = func_0021cca0_u32(resource, 0x24);
    func_0021d3b0(work + 0x104, frame);
    frame = func_0021cca0_u32(resource, 0x25);
    func_0021d3b0(work + 0x144, frame);
    frame = func_0021cca0_u32(resource, 0x11);
    func_0021d3b0(work + 0x84, frame);
    for (i = 0; i < 9; i++)
    {
        slot = work + i * 0x48 + 0x184;
        slot[0] = 0;
        slot[0x44] = 0;
        frame = func_0021cca0_u32(resource, 0xf);
        func_0021d3b0(slot + 4, frame);
    }
    for (i = 0; i < 3; i++)
    {
        slot = work + i * 2 + 0x40d;
        slot[1] = 0;
        random = FUN_00488f30();
        slot[0] = random & 7;
    }
    opTitle00269500();
    *work |= 1;
}

// FUN_002694b0
void opTitle002694b0(void)
{
    K_ASSERT(sOpTitle != NULL, 0x8e);
    *sOpTitle &= 0xfffffffe;
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







// FUN_00269640
u32 opTitle00269640(void)
{
    K_ASSERT(sOpTitle != NULL, 0x8e);
    return *sOpTitle & 4;
}

/* W420 verified: scoped mesh temporaries and declaration order reduced opTitle00269690 nd361/772B to nd353/772B, window784B; rate46.76% to45.73%. */
// FUN_00269690 NONMATCHING
u32* opTitle00269690(s32 mode, s32 columns, s32 rows)
{
    s32 indexCount;
    s32 vertexCount;
    u32* mesh;
    void* memory;
    s32 allocationSize;

    switch (mode)
    {
    case 0:
        {
        indexCount = (rows + 1) * (columns + 1);
        vertexCount = columns * rows * 6;
        break;
        }
    case 1:
        {
        if ((rows & 1) != 0)
        {
            s32 halfRows;
            halfRows = rows >> 1;
            if (rows < 0)
            {
                halfRows = (rows + 1) >> 1;
            }
            indexCount = (halfRows + 1) * (columns * 2 + 3);
        }
        else
        {
            s32 halfRows;
            s32 product;
            s32 rowWidth;
            halfRows = rows >> 1;
            if (rows < 0)
            {
                halfRows = (rows + 1) >> 1;
            }
            product = (columns + 1) * rows;
            rowWidth = product >> 1;
            if (product < 0)
            {
                rowWidth = (product + 1) >> 1;
            }
            indexCount = (columns + 2) * (halfRows + 1) + rowWidth;
        }
        vertexCount = rows * (columns * 6 + 3);
        break;
        }
    }

    allocationSize = 0;
    allocationSize += 0x20;
    allocationSize += indexCount * 0x40;
    allocationSize += vertexCount * 2;
    memory = (void*)(uintptr_t)(*DAT_00960178_abs)((u32)allocationSize, 0x40000);
    mesh = (u32*)memory;
    mesh[0] = (u32)(uintptr_t)((u8*)memory + 0x20);
    mesh[1] = mesh[0] + indexCount * 0x40;

    switch (mode)
    {
    case 0:
        {
            s16* indices;
            s32 value;
            s32 row;
            s32 column;
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
        break;
        }
    case 1:
        {
            s32 row;
            s32 column;
            s32 value;
            s16* indices;
            s32 columnsPlus1;
            s32 columnsPlus2;
        value = 0;
        indices = (s16*)(uintptr_t)mesh[1];
        columnsPlus2 = columns + 2;
        columnsPlus1 = columns + 1;
        for (row = 0; row < rows; row++)
        {
            for (column = 0; column < columns; column++)
            {
                if ((~row & 1) != 0)
                {
                    indices[0] = value;
                    indices[1] = value + 1;
                    indices[2] = value + columnsPlus2;
                    indices[3] = value + 1;
                    indices[4] = value + columnsPlus2 + 1;
                    indices[5] = value + columnsPlus2;
                }
                else
                {
                    indices[0] = value;
                    indices[1] = value + columnsPlus2;
                    indices[2] = value + columnsPlus1;
                    indices[3] = value;
                    indices[4] = value + 1;
                    indices[5] = value + columnsPlus2;
                }
                value++;
                indices += 6;
            }
            if ((~row & 1) != 0)
            {
                indices[0] = value;
                indices[1] = value + 1;
                indices[2] = value + columnsPlus2;
                value += 2;
            }
            else
            {
                indices[0] = value;
                indices[1] = value + columnsPlus2;
                indices[2] = value + columnsPlus1;
                value++;
            }
            indices += 3;
        }
        break;
        }
    }

    mesh[6] = (u32)mode;
    mesh[2] = (u32)columns;
    mesh[3] = (u32)rows;
    mesh[4] = (u32)indexCount;
    mesh[5] = (u32)vertexCount;
    return mesh;
}
// FUN_002699A0
void opTitle002699a0(void* memory)
{
    (*DAT_0096017c)(memory);
}

// FUN_002699D0
void opTitle002699d0(u32* vertex)
{
    (*D_009600A4)(3, vertex[0], vertex[4], vertex[1], vertex[5]);
}

// FUN_00269A10
void opTitle00269a10(OpTitleMesh* mesh, u32* callback)
{
    f32 var_f0;
    s32 temp_22;
    s32 temp_4;
    s32 temp_4_2;
    u32 index;
    s32 var_16;
    s32 var_16_2;
    s32 var_17;
    s32 var_17_2;
    s32 var_18;
    s32 var_19;
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
    temp_4 = mesh->mode;
    switch (temp_4)
    {
    case 0:
        for (var_17 = 0; var_17 < mesh->height + 1; var_17++)
        {
            for (var_16 = 0; var_16 < mesh->width + 1; var_16++)
            {
                temp_4_2 = mesh->width + 1;
                index = (u32)(var_16 + temp_4_2 * var_17);
                args.u = (f32)var_16 / (f32)mesh->width;
                args.v = (f32)var_17 / (f32)mesh->height;
                args.index = index;
                ((void (*)(void*))callback[0])(&args);
            }
        }
        return;
    case 1:
        var_19 = 0;
        for (var_17_2 = 0; var_17_2 < mesh->height + 1; var_17_2++)
        {
            temp_22 = ~var_17_2 & 1;
            if (temp_22 != 0)
            {
                var_16_2 = mesh->width + 2;
            }
            else
            {
                var_16_2 = mesh->width + 1;
            }
            for (var_18 = 0; var_18 < var_16_2; var_18++, var_19++)
            {
                if (temp_22 != 0)
                {
                    if (var_18 == 0)
                    {
                        var_f0 = 0.0f;
                    }
                    else if (var_18 == var_16_2 - 1)
                    {
                        var_f0 = 1.0f;
                    }
                    else
                    {
                        var_f0 = 1.0f / (f32)mesh->width * (f32)(var_18 - 1) +
                            1.0f / (f32)mesh->width / 2.0f;
                    }
                }
                else
                {
                    var_f0 = (f32)var_18 / (f32)mesh->width;
                }
                args.u = var_f0;
                args.v = (f32)var_17_2 / (f32)mesh->height;
                args.index = (u32)var_19;
                ((void (*)(void*))callback[0])(&args);
            }
        }
        return;
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
