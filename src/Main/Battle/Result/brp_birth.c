#include "Main/Social/sfl_res.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"

#pragma alias func_0010a4e0_y2 func_0010a4e0


static u32* sBrpBirthWork; // puGpffffb640

typedef struct BrpBirthVec
{
    f32 x;
    f32 y;
    f32 z;
} BrpBirthVec;

typedef struct BrpBirthColor
{
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} BrpBirthColor;
extern f32 fGpffff8248;
extern f32 fGpffff8088;
static const BrpBirthVec sBrpBirthTranslation = {0.0f, 100.0f, 200.0f};
static const BrpBirthVec sBrpBirthAxis = {0.0f, 1.0f, 0.0f};
static const BrpBirthVec sBrpBirthRotation = {1.0f, 0.0f, 0.0f};
extern void* kwlnGetMainCamera(void);
extern void func_00219c90(void* work);
extern void func_00239170(void* work);
extern void func_00239280(void);
extern void func_002392d0(void);
extern void func_0023b990(void);
extern void func_0023d240(void);
extern void func_0020a800(void* frame);
extern void func_0020c5f0(void* frame, s32 value, s32 count);
extern void func_00209f00(void* frame);
extern void func_0020c590(void* frame, u16 value);
extern void func_0020cd50(void* frame, void* resource);
extern void func_00219d90(void);
extern void func_0020ac80(void* frame);
extern void func_0020ac90(void* frame);
extern void func_0020b250(void* frame);
extern void func_0021a1b0(void);
extern void func_0021a920(s32 mode, s32 value);
extern void func_0021ab80(s32 value);
extern u32 func_0021a120(void);
extern void func_0020cc80(void* frame, const BrpBirthColor* color);
extern void func_004bdde0(f32 angle, void* frame, const BrpBirthVec* vector, u32 mode);
extern void func_004c9d70(void* camera, f32 value);
extern void func_004c9db0(void* camera, f32 value);
extern void func_004cb890(void* frame, f32 value, const BrpBirthVec* vector, u32 mode);
extern void func_004cb750(void* frame, const BrpBirthVec* vector, u32 mode);
extern void* func_0034fcd0(const void* resource);
extern void func_0034fcf0(void* resource);
extern void func_0034fdf0(void* resource, const BrpBirthVec* position);
extern void func_0034ff90(void* resource, const BrpBirthColor* color);
extern void func_0034fd30(void* resource);
extern void func_0034fd70(void* resource, s32 layer);
extern void func_0034ff70(void* resource, f32 scalar);
extern u32 func_003cda60(s32 mode, s32 value);
extern void func_003cdba0(u32 object, u16 value);
extern u32 func_003cdc80(u32 object);
extern void func_003cdcd0(u32 object, s32 a, s32 b, s32 c);
extern void func_003cde00(u32 object, s32 value);
extern void func_003c72d0(u32 value);
extern u32 func_003c7bc0(s32 mode, u32 value);
extern u32 func_00173220(u16 value);
extern u32 func_0017d790(u16 value);
extern void func_003c7430(u32 value);
extern void func_003c7990(s32 value);
extern u32 func_003c7850(void);
extern void func_003c7650(s32 value);
extern void func_003c77a0(void);
extern f32 func_0052e878(f32 value);
extern f32 func_0052e6d8(f32 value);
extern void func_00195020(void* task);
extern void H_Fade_FadeOut(void);
extern void H_Fade_SetType(s32 type);
extern void H_Fade_FadeIn(void);
extern u32 H_Fade_IsFadeOutDone(void);
extern void func_0010a4e0(s32 bank, s32 cue, s32 variant, s32 pan);
extern void func_0024be40(void);
extern void func_0024ba50(void);
extern void func_0024bb30(void);
extern void func_0024bf80(void);
extern u32 brpRes0024bed0(void);
extern u32 brpRes0024bf20(s32 index);
extern u32 brpRes0024c040(void);
extern u32 brpRes0024c090(void);
extern void brpRes0024ba30(u32* work);
extern u32 D_00960178[];

#define BRP_BIRTH_ALLOC(size, flags) \
    (*(void* (**)(u32, u32))D_00960178)((size), (flags))


// FUN_0024A870
void func_0024a870(void)
{
    u32* work;
    void* camera;
    void* frame;
    void* resource;
    BrpBirthColor color;
    BrpBirthVec translation;
    BrpBirthVec axis;

    K_ASSERT(sBrpBirthWork != NULL, 0x7f);
    work = sBrpBirthWork;
    translation = sBrpBirthTranslation;
    axis = sBrpBirthAxis;
    camera = kwlnGetMainCamera();
    func_004c9d70(camera, 100.0f);
    func_004c9db0(camera, 1000.0f);
    camera = *(void**)((u8*)camera + 4);
    func_004cb890(camera, 180.0f, &axis, 0);
    func_004cb750(camera, &translation, 2);

    switch (work[0])
    {
    case 0:
        func_00209f00(work + 7);
        frame = (u8*)work + 0x1C;
        func_0020c590(frame, *(u16*)((u8*)work + 0x0C));
        break;
    case 1:
        func_0020a800(work + 7);
        frame = (u8*)work + 0x1C;
        func_0020c5f0(frame, 0, 0xE);
        break;
    }
    func_0020cd50(frame, (u8*)work + 0x61C);

    ((f32*)work)[0x3EC] = 500.0f;
    ((f32*)work)[0x3ED] = 100.0f;
    ((f32*)work)[0x3EE] = 500.0f;
    ((f32*)frame)[8] = 0.0f;
    ((f32*)frame)[9] = 100.0f;
    ((f32*)frame)[10] = 0.0f;
    ((f32*)frame)[7] = 1.0f;
    ((f32*)frame)[4] = 0.0f;
    ((f32*)frame)[5] = 0.0f;
    ((f32*)frame)[6] = 0.0f;
    ((f32*)frame)[11] = 10.0f;
    ((f32*)frame)[12] = 10.0f;
    ((f32*)frame)[13] = 10.0f;

    H_Fade_FadeIn();
    func_0023d240();
    work[5] = 0;
    resource = (void*)(uintptr_t)brpRes0024bf20(0);
    work[0x3F3] = (u32)(uintptr_t)func_0034fcd0(resource);
    work[1] |= 0x40;
    color.r = 0xFF;
    color.g = 0xFF;
    color.b = 0xFF;
    color.a = 0xFF;
    func_0034ff90((void*)(uintptr_t)work[0x3F3], &color);
    work[1] |= 1;
    work[2] = 1;
}

// FUN_0024aa90
void brpBirth0024aa90(void)
{
    u32* work;

    K_ASSERT(sBrpBirthWork != NULL, 0x7f);
    work = sBrpBirthWork;
    H_Fade_FadeOut();
    H_Fade_SetType(2);
    H_Fade_FadeIn();
    work[1] |= 1;
    work[2] = 8;
}

// FUN_0024abd0
void brpBirth0024abd0(void)
{
    u32* work;

    K_ASSERT(sBrpBirthWork != NULL, 0x7f);
    work = sBrpBirthWork;
    func_0024be40();
    func_0021a920(0, 0xe);
    *work = 1;
    work[1] |= 2;
}

// FUN_0024ac40
u32 brpBirth0024ac40(void)
{
    K_ASSERT(sBrpBirthWork != NULL, 0x7f);
    return sBrpBirthWork[1] & 2;
}

// FUN_0024b9e0
u32 brpBirth0024b9e0(void)
{
    K_ASSERT(sBrpBirthWork != NULL, 0x7f);
    return sBrpBirthWork[1] & 1;
}

// FUN_0024AB10
void func_0024ab10(s32 date)
{
    u32* work;

    K_ASSERT(sBrpBirthWork != NULL, 0x7f);
    work = sBrpBirthWork;
    *(s16*)((u8*)work + 0x0C) = (s16)date;
    work[0x3158] = (u32)func_003cda60(0, 1);
    work[1] |= 0x80;
    func_003cdba0(work[0x3158], *(u16*)((u8*)work + 0x0C));
    func_0024be40();
    func_0021ab80(date);
    work[0] = 0;
    work[1] |= 2;
}

// FUN_0024AC90
void func_0024ac90(void)
{
    u32* work;

    K_ASSERT(sBrpBirthWork != NULL, 0x7f);
    work = sBrpBirthWork;
    K_ASSERT((~work[1] & 2) != 0, 0x103);
    func_00239280();
    sflResShutdown();
    func_0024ba50();
    func_0021a1b0();
    if ((work[1] & 0x10) != 0)
    {
        func_0034fcf0((void*)(uintptr_t)work[0x3F1]);
    }
    if ((work[1] & 0x20) != 0)
    {
        func_0034fcf0((void*)(uintptr_t)work[0x3F2]);
    }
    if ((work[1] & 0x40) != 0)
    {
        func_0034fcf0((void*)(uintptr_t)work[0x3F3]);
    }
    if ((work[1] & 0x100) != 0)
    {
        func_0034fcf0((void*)(uintptr_t)work[0x3F4]);
    }
    if ((work[1] & 4) != 0)
    {
        func_00195020((void*)(uintptr_t)work[0x3158]);
    }
    if ((work[1] & 8) != 0)
    {
        func_0020ac80((u8*)work + 0x1C);
    }
    RwFree(work);
    sBrpBirthWork = NULL;
}

static void brpBirthSetColor(void* resource, u8 r, u8 g, u8 b, u8 a)
{
    BrpBirthColor color;

    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    func_0034ff90(resource, &color);
}

static void brpBirthSetOrigin(void* resource, f32 x, f32 y, f32 z)
{
    BrpBirthVec origin;

    origin.x = x;
    origin.y = y;
    origin.z = z;
    func_0034fdf0(resource, &origin);
}

// FUN_0024ADF0 NONMATCHING
void func_0024adf0(void)
{
    s32* work;
    u32 flags;
    BrpBirthColor color;
    BrpBirthVec rotation;
    BrpBirthVec origin;
    f32 angle;
    f32 opacity;
    f32 wave;
    u8* frame;

    K_ASSERT(sBrpBirthWork != NULL, 0x7f);
    work = (s32*)sBrpBirthWork;
    rotation = sBrpBirthRotation;
    func_0024bb30();
    sflResUpdate();
    func_00219d90();
    flags = work[1];
    if ((flags & 2) != 0)
    {
        switch (work[0])
        {
        case 0:
            if (((~flags & 4) != 0) &&
                func_003cdc80(work[0x3158]) == 0)
            {
                func_003cdcd0(work[0x3158], 0, 0, 1);
                work[1] |= 4;
            }
            if ((~work[1] & 8) != 0 && func_0021a120() == 0)
            {
                work[1] |= 8;
            }
            if ((work[1] & 0xC) == 0xC && brpRes0024bed0() == 0)
            {
                work[1] &= ~2;
            }
            break;
        case 1:
            if ((~flags & 8) != 0 && func_0021a120() == 0)
            {
                work[1] |= 8;
            }
            if ((work[1] & 8) != 0 && brpRes0024bed0() == 0)
            {
                work[1] &= ~2;
            }
            break;
        }
    }

    if (work[2] != 0)
    {
        func_002392d0();
        switch (work[2])
        {
        case 1:
            if (H_Fade_IsFadeOutDone() != 0)
            {
                work[4] = 0;
                work[2] = 2;
            }
            break;
        case 2:
            if ((s32)work[4] < 0x1E)
            {
                work[4]++;
            }
            else
            {
                work[4] = 0;
                work[2] = 3;
            }
            break;
        case 3:
            if ((s32)work[4] < 0x28)
            {
                work[4]++;
            }
            else
            {
                func_0010a4e0(1, 0, 8, 5);
                work[4] = 0;
                work[2] = 4;
            }
            break;
        case 4:
            if ((s32)work[4] < 0x14)
            {
                work[4]++;
                color.r = 0xFF;
                color.g = 0;
                color.b = 0;
                color.a = (u8)(255.0f -
                    (255.0f * (f32)work[4]) / 20.0f);
                func_0034ff90((void*)(uintptr_t)work[0x3F3], &color);
            }
            else
            {
                if (work[0] == 1)
                {
                    work[0x3F2] = (u32)(uintptr_t)
                        func_0034fcd0((const void*)(uintptr_t)
                            brpRes0024bf20(1));
                    work[1] |= 0x20;
                    origin.x = 0.0f;
                    origin.y = 100.0f;
                    origin.z = 0.0f;
                    func_0034fdf0((void*)(uintptr_t)work[0x3F2],
                        &origin);
                    func_0010a4e0(1, 0, 8, 6);
                    work[1] &= ~1;
                    work[2] = 7;
                }
                else if (work[0] == 0)
                {
                    work[4] = 0;
                    work[2] = 5;
                }
                color.r = 0;
                color.g = 0;
                color.b = 0;
                color.a = 0;
                func_0034ff90((void*)(uintptr_t)work[0x3F3], &color);
            }
            break;
        case 5:
            if ((s32)work[4] < 0x1E)
            {
                work[4]++;
            }
            else
            {
                K_ASSERT((work[1] & 0x10) == 0, 0x1BF);
                work[0x3F1] = (u32)(uintptr_t)
                    func_0034fcd0((const void*)(uintptr_t)
                        brpRes0024bf20(2));
                work[1] |= 0x10;
                origin.x = 0.0f;
                origin.y = 100.0f;
                origin.z = -500.0f;
                func_0034fdf0((void*)(uintptr_t)work[0x3F1], &origin);
                func_0010a4e0(1, 0, 8, 6);
                work[4] = 0;
                work[2] = 6;
            }
            break;
        case 6:
            if (work[4] == 0x1E)
            {
                func_003cde00(work[0x3158], 1);
                K_ASSERT((work[1] & 0x100) == 0, 0x1D6);
                work[0x3F4] = (u32)(uintptr_t)
                    func_0034fcd0((const void*)(uintptr_t)
                        brpRes0024bf20(3));
                work[1] |= 0x100;
                origin.x = -60.0f;
                origin.y = -50.0f;
                origin.z = 0.0f;
                func_0034fdf0((void*)(uintptr_t)work[0x3F4], &origin);
            }
            if ((s32)work[4] < 0x3C)
            {
                work[4]++;
            }
            else
            {
                work[4] = 0;
                func_0024bf80();
                work[2] = 10;
            }
            break;
        case 8:
            if (H_Fade_IsFadeOutDone() != 0)
            {
                if ((work[1] & 0x10) != 0)
                {
                    func_0034fcf0((void*)(uintptr_t)work[0x3F1]);
                    work[1] &= ~0x10;
                }
                if ((work[1] & 0x100) != 0)
                {
                    func_0034fcf0((void*)(uintptr_t)work[0x3F4]);
                    work[1] &= ~0x100;
                }
                if ((work[1] & 0x20) != 0)
                {
                    func_0034fcf0((void*)(uintptr_t)work[0x3F2]);
                    work[1] &= ~0x20;
                }
                if ((work[1] & 0x40) != 0)
                {
                    func_0034fcf0((void*)(uintptr_t)work[0x3F3]);
                    work[1] &= ~0x40;
                }
                work[1] &= ~1;
                work[2] = 0;
            }
            break;
        case 10:
            if (brpRes0024c040() == 0)
            {
                func_003c72d0(brpRes0024c090());
                func_003c7bc0(1,
                    func_00173220((s16)work[3]));
                func_003c7430(
                    func_0017d790((s16)work[3]));
                work[2] = 0xB;
            }
            break;
        case 0xB:
            func_003c7990(1);
            if (func_003c7850() == 0)
            {
                func_003c7650(1);
                func_003c77a0();
                work[2] = 7;
                work[1] &= ~1;
            }
            break;
        default:
            break;
        }
        frame = (u8*)work + 0x1C;
        switch (work[2])
        {
        case 1:
        case 2:
            opacity = 0.0f;
            break;
        case 3:
            opacity = (f32)work[4] / 40.0f;
            break;
        case 4:
        case 5:
            opacity = 1.0f;
            break;
        case 6:
            opacity = 1.0f - (f32)work[4] / 60.0f;
            break;
        case 7:
        case 8:
            opacity = work[0] == 1 ? 1.0f : 0.0f;
            break;
        default:
            opacity = 0.0f;
            break;
        }

        work[5]++;
        wave = fGpffff8248 *
            (-((f32)work[5] / 50.0f) * 2.0f);
        ((f32*)work)[0x3EC] = func_0052e878(wave) * -300.0f;
        ((f32*)work)[0x3EE] = func_0052e6d8(wave) * -300.0f;
        ((f32*)work)[0x3ED] =
            func_0052e6d8(fGpffff8248 *
                ((f32)work[5] / 30.0f) * 2.0f) *
            400.0f + 100.0f;

        color.r = 0xFF;
        color.g = 0xFF;
        color.b = 0xFF;
        color.a = (u8)(opacity * 255.0f);
        func_0020cc80(frame, &color);

        switch (work[2])
        {
        case 1:
        case 2:
        case 3:
            angle = 180.0f;
            break;
        case 4:
            angle = (1.0f - (f32)work[4] / 20.0f) * 180.0f;
            break;
        case 5:
        case 6:
        case 7:
        case 8:
        default:
            angle = 0.0f;
            break;
        }
        func_004bdde0(angle, (u8*)work + 0x2C, &rotation, 0);
        if ((work[1] & 0x80) != 0)
        {
            func_003cdba0(work[0x3158], *(u16*)((u8*)work + 0x0C));
        }
    }
}

// FUN_0024B8A0
void func_0024b8a0(void)
{
    u32* work;

    K_ASSERT(sBrpBirthWork != NULL, 0x7f);
    work = sBrpBirthWork;
    if (work[2] != 0)
    {
        func_0023b990();
        if ((work[1] & 8) != 0)
        {
            func_0020ac90(work + 7);
            func_0020b250(work + 7);
        }
        if ((work[1] & 0x10) != 0)
        {
            func_0034fd30((void*)(uintptr_t)work[0x3F1]);
            func_0034fd70((void*)(uintptr_t)work[0x3F1], 5);
        }
        if ((work[1] & 0x100) != 0)
        {
            func_0034ff70((void*)(uintptr_t)work[0x3F4], fGpffff8088);
            func_0034fd30((void*)(uintptr_t)work[0x3F4]);
            func_0034fd70((void*)(uintptr_t)work[0x3F4], 5);
        }
        if ((work[1] & 0x20) != 0)
        {
            func_0034fd30((void*)(uintptr_t)work[0x3F2]);
            func_0034fd70((void*)(uintptr_t)work[0x3F2], 5);
        }
        if ((work[1] & 0x40) != 0)
        {
            func_0034fd30((void*)(uintptr_t)work[0x3F3]);
            func_0034fd70((void*)(uintptr_t)work[0x3F3], 5);
        }
    }
}


#include "h_cdvd.h"




extern void func_0021b4a0(void* resource);
extern void* memcpy(void* destination, const void* source, u32 size);
static const char sBrpBirthArchivePath[] = "battle/result/brp_birth.bin";
static const char sBrpCombineMessagePath[] = "facility/msg/msg_combine.bmd";

#define BRP_RES_ALLOC(size, flags) \
    (*(void* (**)(u32, u32))D_00960178)((size), (flags))
static u32* sBrpResWork; // puGpffffb644

// FUN_0024ba30
void brpRes0024ba30(u32* param_1)
{
    *param_1 = 0;
    param_1[1] = 0;
    sBrpResWork = param_1;
}





static u32* sBrpRes334; // 007ce334






#include "Utils.h"

/* DAT_007CE348: panel effect work installed by FUN_0024C100. */
static u32* sBpEffect;

extern void func_0010a4e0_y2(s32, s32, s32, s32);
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
