#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"




// "bas" (original file name: bas_main.c) is the thin request interface for the
// battle "analyze" command: the battle command menu (bcm_main.c) requests an
// enemy analyze page here, bp_root.c opens it (bpRootRequestAnalyze) and
// acknowledges completion through basClearAnalyzePending.

// BasWork.flags
#define BAS_PENDING 1 // an analyze request is in flight

// 8 bytes. Lives inside bp_root's panel work data
typedef struct
{
    u32 flags;  // 0x00. See 'BAS_*'
    u32 unitId; // 0x04. Unit whose analyze page was requested
} BasWork;

static BasWork* sBasWork; // puGpffffb63c

void bpRootRequestAnalyze(u32 unitId); // bp_root.c



// FUN_0024a6e0
void basRequestAnalyze(u32 unitId)
{
    BasWork* work;

    K_ASSERT(sBasWork != NULL, 0x1d);
    work = sBasWork;
    bpRootRequestAnalyze(unitId);
    work->unitId = unitId;
    work->flags |= BAS_PENDING;
}

// FUN_0024a750
u32 basIsAnalyzePending(void)
{
    K_ASSERT(sBasWork != NULL, 0x1d);
    return sBasWork->flags & BAS_PENDING;
}

// FUN_0024a7a0
void basClearAnalyzePending(void)
{
    K_ASSERT(sBasWork != NULL, 0x1d);
    sBasWork->flags &= ~BAS_PENDING;
}


#include "Main/Social/sfl_res.h"
#include "rw/rwplcore.h"

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

// FUN_0024A7F0
void func_0024a7f0(void)
{
    u32* work;

    work = (u32*)BRP_BIRTH_ALLOC(0xC570, 0x40000);
    func_00219c90((u8*)work + 0xFD4);
    sflResInit((SflResourceManager*)((u8*)work + 0x3730));
    brpRes0024ba30((u32*)((u8*)work + 0x3704));
    func_00239170((u8*)work + 0x37C0);
    work[1] = 0;
    work[2] = 0;
    sBrpBirthWork = work;
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
