#include "Main/OpEd/op_fade.h"
#include "Kernel/Kwln/kwln.h"
#include "Kosaka/k_assert.h"




typedef void (*OpFadeSetRenderState)(u32 state, u32 value);
typedef void (*OpFadeRenderQuad)(void* quad, u32 layer, u32 group, u32 pass, u32 blend);

extern void func_0021eb80(void* destination, const f32* layout);
extern void func_0021d8e0(void* destination, f32* layout);
extern void func_0021d950(void* destination, const u8* color);
extern void func_004d7f60(s32 state, u32 value);
extern u32 D_00960090_y2[];
extern u32 D_0096009C_y2[];
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


#include "Kernel/Kwln/kwlnTask.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"
static u32* sBrpSeq; // puGpffffb6d0 / iGpffffb6d0
extern u8 sBrpSeq_abs[];
extern void func_0024b8a0(void);
extern void func_0024a7f0(void);
extern void func_0024abd0(void);
extern void func_0024ab10(s16);
extern void func_0024aa90(void);
extern void func_0024a870(void);
extern void func_0024ac90(void);
extern void func_0024adf0(void);
extern u32 func_0024b9e0(void);
extern u32 func_0024ac40(void);
extern void FUN_00279750(void);
extern void func_00279660(void);
extern void func_002796b0(void);
extern u32 func_00279700(void);
extern u32 func_002797a0(void);
extern void func_002797f0(void);
extern void func_00279890(u32 mode, u32 page);
extern void func_00279120(void);
extern void func_002791b0(u16 skillId);
extern void func_002792c0(void);
extern void func_00279330(u32 value);
extern void brpParamSetUnlockedSkillLevel(u32 level);
extern void brpParamSetUnlockedSkillIndex(u32 index);
extern void func_00279510(u32 slot, u32 value);
extern void func_00279580(u32 slot, u32 value);
extern void func_002795f0(u32 slot, u32 value);
extern u32 func_00276cc0(void);
extern void brLvpnlDisableDrawing(void);
extern void brLvpnlEnableDrawing(void);
extern void scrClearTextBox(s32, s32, s32, s32);
extern void FUN_003c77a0(void);
extern void FUN_003c7990(s32);
extern u32 FUN_003c7850(void);
extern void FUN_003c7650(s32);
extern u32 FUN_003c7610(void);
extern void FUN_003c7bc0();
extern void FUN_003c7430(s32);
extern void FUN_003c74e0(s32);
extern void FUN_003c7560(s32);
extern void FUN_0010a4e0(s32, s32, s32, s32);
extern u32 FUN_00173220(u16);
extern DatPersonaWork* FUN_001749a0(u16);
extern u32 FUN_00175410(void);
extern u32 FUN_001756f0(void);
extern DatPersonaWork* FUN_001761b0(DatPersonaWork*);
extern void FUN_00176100(DatPersonaWork*, u8*);
extern void FUN_00175ce0(DatPersonaWork*, u8*);
extern u32 FUN_00176a30(DatPersonaWork*);
extern u16* FUN_00173370(DatPersonaWork*);
extern void FUN_00176d10(DatPersonaWork*, DatPersonaWork*);
extern u32 FUN_00173580(DatPersonaWork*, u16);
extern u32 FUN_00171250(s16);
extern u16 FUN_00170760();
extern void FUN_00170860();
extern void FUN_001830c0(void*);
extern void FUN_001768e0(DatPersonaWork*, u16);
extern void FUN_00176840(DatPersonaWork*, u16);
extern u32 FUN_0016f490(s32);
extern u16 FUN_001fba70(s16);
extern u16 FUN_001fb560(s16);
extern u32 FUN_00171110(s16, s32);
extern void FUN_001828d0(s16, void*);
extern void H_Fade_FadeOut(void);
extern void H_Fade_SetType(s32 type);
extern u32 H_Fade_IsFadeOutDone(void);
extern u32 FUN_002347e0(void);
extern void FUN_003c72d0(void*);
extern void FUN_001fb4b0(u8*, s32, s32, u8, u8*, u8*);
extern u8* FUN_00275050(s32);
extern u32 FUN_002751e0(void);
extern s32 func_00274f00(void);
extern u32 func_002741f0(void);
extern u8* DAT_007ce420;
extern u8* DAT_007ce428;
extern u32 DAT_007ce4ec;
extern u32 DAT_007e094e;
extern u16 DAT_007e0952;
extern u16* DAT_007ce438;
extern const char* PTR_s_Strength_0068ed70[];
extern const char D_0068EDC0[];
extern const char D_0068EDE0[];
extern const char D_0068EDF0[];
extern const char D_0068EE00[];
extern const char D_0068EE10[];
extern const char D_0068EE28[];
extern const char D_0068EE40[];
extern const char D_0068EE60[];
extern const char D_0068EE80[];
extern const char D_0068EE90[];
extern u32 gp0xffff97d0;
extern u32 gp0xffff97d0_1;
extern u32 gp0xffff97d0_2;
extern u32 gp0xffff97d0_3;
extern u32 gp0xffff97d0_4;
extern u32 gp0xffff97d0_5;
extern u32 gp0xffff97d0_6;
extern void FUN_005225a8(u32 format, ...);
extern const char D_0068ED98[];
extern const char D_0068EDA8[];
extern u32 FUN_00108570(void);
extern void FUN_00108670(s16 type);
extern void FUN_00523ac8(void*, ...);
extern s32 FUN_00488f30(void);
extern u8* FUN_003d5c90(void);
extern u8 FUN_0016c470(s32);
extern void func_00279840(void);
extern u32 uGpffff97ec;
void brpSeq00273980(void);
void brpSeq00273c00(void);
void brpSeq00273c70(void);
void func_00272810(void);
void func_00273800(void);
void func_00273a10(void);
void func_00273b30(void);
void func_00273d50(void);
void func_00273e90(void);
void func_00274030(void);
void func_00274100(void);
u32 func_002741f0(void);
void func_002743a0(void);
void func_002743e0(void*, s32*);
void func_00274590(void);
void func_00274c00(void);
u32 func_00274d40(void);
u32 func_00274d90(void);
u32 func_00274e10(void);
s32 func_00274e90(void);
extern u32 FUN_00108710(void);
#include "Main/OpEd/op_fade_mid.h"
#include "Main/Battle/Result/br_res.h"
typedef int (*code)(...);
extern void K_Assert(const char* file, s32 line);
extern const char D_0068ED88[];
#define OP_MATCH_ASSERT(condition, line) \
    do {                                 \
        if (!(condition)) {              \
            K_Assert(__FILE__, (line));  \
        }                                \
    } while (0)
extern u32 D_00960178[];
extern u32 D_0096017C[];
extern void (*D_00960090)(u32 state, u32 value);
extern void (*D_0096009C)(void *vertices, u32 primitive, u32 offset,
                          u32 first, u32 second);
extern u8 D_00960090_abs[];
extern u8 D_0096009C_abs[];
extern void *D_007D2D60;
extern u8 *DAT_007ce420_y2;
extern s32 DAT_007cc4dc;
extern f32 DAT_007cad74;
extern f32 DAT_007caf38;
extern f32 DAT_007caf8c;
extern f32 DAT_007cafec;
extern f32 DAT_007cb04c;
extern const char DAT_0068EEB8[];
extern const char DAT_0068EED0[];
extern void *FUN_00173220_y2(u16 id);
extern void *FUN_001749a0_y2(u16 id);
extern u32 func_00194b80(void *parent, u32 priority, const void *name,
                          void *update, void *destroy, void *work);
extern u32 func_00194e10(const void *name, u32 size, u32 a, u32 b,
                          void *update, void *destroy, u32 flags);
extern void func_00195020(u32 resource);
extern void func_0010a370(s32 channel, const char *message);
extern u32 func_00119a60(u32 id);
extern u32 func_00198590(void);
extern void func_001985b0(u8 r, u8 g, u8 b, u8 a);
extern void func_0019d3f0(const char *file, s32 line);
extern void func_001fb1f0(void *persona, u16 *out, s32 *count);
extern u32 func_001fc230(void *persona);
extern u32 func_001fc3c0(void *persona);
extern void func_0021d3b0(void *destination, u32 source);
extern void func_0021d8e0_y2(void *destination, const f32 *layout);
extern void func_0021d950_y2(void *destination, const u8 *color);
extern u32 func_0021cca0(u32 resource, s32 frame);
extern u32 func_0021cce0(u32 frame);
extern void func_0021e380(void *destination, u32 source, s32 mode);
extern void func_0021eac0(void *destination, f32 value);
extern void func_00238980(void *destination, s32 count, u32 value, s32 mode);
extern void func_00238dc0(void *destination, s32 count, u32 value, s32 mode,
                           const f32 *layout);
extern void func_0025f5d0(void *destination, u32 resource, s32 frame);
extern void func_0025fc50(void *destination, u32 resource, s32 frame, s32 mode);
extern u32 func_00239140(s32 font);
extern s32 sflPsel00260900(u32 *resource, s32 frame);
extern s32 sflPsel00260920(u32 *resource, s32 frame);
extern f32 sinf(f32 angle);
extern u32 sflPsel00260940(u32 *resource, s32 frame);
extern void func_00272330(void *task);
extern void func_00272380_y2(void);
extern void func_00272400_y2(u64 value);
extern u32 func_002727c0_y2(void);
extern void func_002791b0_y2(u16 id);
extern void func_00279330_y2(u16 id);
extern void func_00279510_y2(s32 index, u32 value);
extern void func_00279580_y2(s32 index, u32 value);
extern void func_002795f0_y2(s32 index, u32 value);
extern void func_003b0170(u32 resource);
extern u32 func_003b0d70(u32 resource, s32 x, s32 y);
extern void func_003b0e20(u32 resource, u32 color);
extern void func_003b0e70(s32 mode);
extern void func_003b0e90(s32 mode);
extern u32 func_003b1360(u32 resource, s32 visible, s32 flags);
extern void func_003c7430(s32 value);
extern void func_003c7bc0(s32 channel, u32 value);
extern void func_003c7e20(s32 mode, s32 x, s32 y, u64 value, s32 a,
                           s32 b, s32 c);
extern u32 func_003c9ab0(u32 resource);
extern void func_003c9ba0(u32 stream, u32 resource);
extern void func_003c9cd0(u32 resource, s32 value);
extern void func_003c9d00(u32 resource, s32 value);
extern void func_003c9d80(u32 resource, s32 value);
extern void func_00521250(void *destination, const void *source, u32 size);
extern void func_005225a8(const void *message, ...);
extern void brLvpnlStartEntranceAnimation(void);
extern u32 *DAT_007ce3c0;
extern u32 *DAT_007ce3c4;
extern u32 *DAT_007ce3c8;
extern u32 *DAT_007ce3cc;
extern u32 *DAT_007ce3d0;
#undef gOpWorkC0
#undef gOpWorkC4
#undef gOpWorkC8
#undef gOpWorkCC
#undef gOpWorkD0
#define gOpWorkC0 DAT_007ce3c0
#define gOpWorkC4 DAT_007ce3c4
#define gOpWorkC8 DAT_007ce3c8
#define gOpWorkCC DAT_007ce3cc
#define gOpWorkD0 DAT_007ce3d0
#define opTexW(resource, frame) \
    ((s32)sflPsel00260900((u32 *)(uintptr_t)(resource), (frame)))
#define opTexH(resource, frame) \
    ((s32)sflPsel00260920((u32 *)(uintptr_t)(resource), (frame)))
#define opTexFrame(resource, frame) \
    (sflPsel00260940((u32 *)(uintptr_t)(resource), (frame)))

static inline u8* brpSeqBytes(void)
{
    return (u8*)sBrpSeq;
}
static inline u32 brpSeqU32(u32 offset)
{
    return *(u32*)(brpSeqBytes() + offset);
}
static inline s32 brpSeqS32(u32 offset)
{
    return *(s32*)(brpSeqBytes() + offset);
}
static inline u16 brpSeqU16(u32 offset)
{
    return *(u16*)(brpSeqBytes() + offset);
}
static inline s16 brpSeqS16(u32 offset)
{
    return *(s16*)(brpSeqBytes() + offset);
}
static inline u8 brpSeqU8(u32 offset)
{
    return *(u8*)(brpSeqBytes() + offset);
}
static inline void brpSeqPutU32(u32 offset, u32 value)
{
    *(u32*)(brpSeqBytes() + offset) = value;
}
static inline void brpSeqPutU16(u32 offset, u16 value)
{
    *(u16*)(brpSeqBytes() + offset) = value;
}
static inline void brpSeqPutU8(u32 offset, u8 value)
{
    *(u8*)(brpSeqBytes() + offset) = value;
}

#define OP_U8(base, offset) (*(u8 *)((u8 *)(base) + (offset)))
#define OP_S8(base, offset) (*(s8 *)((u8 *)(base) + (offset)))
#define OP_U16(base, offset) (*(u16 *)((u8 *)(base) + (offset)))
#define OP_S16(base, offset) (*(s16 *)((u8 *)(base) + (offset)))
#define OP_U32(base, offset) (*(u32 *)((u8 *)(base) + (offset)))
#define OP_S32(base, offset) (*(s32 *)((u8 *)(base) + (offset)))
#define OP_PTR(base, offset) (*(void **)((u8 *)(base) + (offset)))
#define OP_WORD(base, index) (((u32 *)(base))[index])
#define OP_ALLOC(size, flags) (*(void *(**)(u32, u32))D_00960178)((size), (flags))
#define OP_WORK0 ((u8 *)gOpWorkC0)
#define OP_WORK4 ((u8 *)gOpWorkC4)
#define OP_WORK8 ((u8 *)gOpWorkC8)
#define OP_WORKC ((u8 *)gOpWorkCC)
#define OP_WORKD ((u8 *)gOpWorkD0)


static inline u8 opFadeColorByte(f32 value)
{
    return (u8)(u32)value;
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
    setRenderState = (OpFadeSetRenderState*)D_00960090_y2;
    (*setRenderState)(8, 0);
    (*setRenderState)(6, 0);
    (*setRenderState)(9, 2);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*setRenderState)(1, 0);
    renderQuad = (OpFadeRenderQuad*)D_0096009C_y2;
    (*renderQuad)(&work->vertices[0], 4, 0, 1, 2);
    (*renderQuad)(&work->vertices[0], 4, 0, 2, 3);
}

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



#pragma alias func_00272330_y2 func_00272330
#pragma alias D_00960090_y2 D_00960090
#pragma alias D_0096009C_y2 D_0096009C
#pragma alias DAT_007ce420_y2 DAT_007ce420_y2
#pragma alias FUN_00173220_y2 FUN_00173220_y2
#pragma alias FUN_001749a0_y2 FUN_001749a0_y2
#pragma alias func_0021d8e0_y2 func_0021d8e0_y2
#pragma alias func_0021d950_y2 func_0021d950_y2
#pragma alias func_00272380_y2 func_00272380_y2
#pragma alias func_00272400_y2 func_00272400_y2
#pragma alias func_002727c0_y2 func_002727c0_y2
#pragma alias func_002791b0_y2 func_002791b0_y2
#pragma alias func_00279330_y2 func_00279330_y2
#pragma alias func_00279510_y2 func_00279510_y2
#pragma alias func_00279580_y2 func_00279580_y2
#pragma alias func_002795f0_y2 func_002795f0_y2


#pragma alias sBrpSeq_abs sBrpSeq

#pragma alias gp0xffff97d0_1 gp0xffff97d0
#pragma alias gp0xffff97d0_2 gp0xffff97d0
#pragma alias gp0xffff97d0_3 gp0xffff97d0
#pragma alias gp0xffff97d0_4 gp0xffff97d0
#pragma alias gp0xffff97d0_5 gp0xffff97d0
#pragma alias gp0xffff97d0_6 gp0xffff97d0










// FUN_00272330
void func_00272330_y2(u32* work)
{
    K_ASSERT(sBrpSeq == NULL, 0xb7);
    *work = 0;
    sBrpSeq = work;
}

// FUN_00272380
void func_00272380(void)
{
    K_ASSERT(sBrpSeq != NULL, 0xb0);
    if ((brpSeqU32(0) & 0x80) != 0)
        FUN_003c77a0();
    K_ASSERT(sBrpSeq != NULL, 0xc8);
    sBrpSeq = NULL;
}

// FUN_00272400 MATCHING
void func_00272400(u32* param)
{
    u32* work;
    u16* skills;
    s32 skillCount;
    s32 skillIndex;
    s32 i;
    s32 resultCount;
    s32 resultIndex;
    u8* entry;
    u8* tableEntry;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    work = sBrpSeq;
    K_ASSERT((~work[0] & 1) != 0, 0xd6);
    K_ASSERT((~work[0] & 2) != 0, 0xd7);
    K_ASSERT((~work[0] & 0x10) != 0, 0xd8);
    K_ASSERT((~work[0] & 0x20) != 0, 0xd9);

    work[0] &= ~4u;
    work[0] &= ~8u;
    *(u16*)((u8*)work + 4) = *(u16*)((u8*)param + 4);
    work[2] = param[0];
    if ((~work[0] & 0x80) != 0)
    {
        FUN_003c72d0((void*)FUN_002347e0());
        work[0] |= 0x80;
    }

    work[0xc] = (u32)(uintptr_t)FUN_001749a0((u16)work[1]);
    K_ASSERT(FUN_001761b0((DatPersonaWork*)(uintptr_t)work[0xc]) != 0, 0xe8);
    {
        u8* destination;
        DatPersonaWork* persona;
        destination = (u8*)work + 0x38;
        persona = (DatPersonaWork*)(uintptr_t)work[0xc];
        FUN_00175ce0(persona, (u8*)(work + 0xe));
    }
    work[0xd] = (u32)(uintptr_t)
        (DAT_007ce428 + (u32)(u16)work[1] * 0x46);

    skillCount = (s32)FUN_00176a30(
        (DatPersonaWork*)(uintptr_t)work[0xc]);
    skills = FUN_00173370((DatPersonaWork*)(uintptr_t)work[0xc]);
    for (skillIndex = 0; skillIndex < skillCount; skillIndex++)
        *(u16*)((u8*)work + 0x60 + skillIndex * 2) = skills[skillIndex];
    work[0x1d] = skillCount;
    {
        DatPersonaWork* persona;
        s32 difference;
        u32 work38;
        persona = (DatPersonaWork*)(uintptr_t)work[0xc];
        difference = (s32)persona->level -
                     (s32)DAT_007ce420[persona->id * 0x0e + 3];
        work38 = ((u8*)work)[0x38];
        FUN_001fb4b0((u8*)(uintptr_t)work[0xd] + 6, 0x10, difference,
                     work38, (u8*)work + 0x78,
                     (u8*)work + 0x7c);
    }
    work[0x6c] = 0;
    work[0x6d] = func_00274f00();
    {
        DatPersonaWork* persona;
        persona = (DatPersonaWork*)(uintptr_t)work[0xc];
        FUN_00176100(persona, (u8*)(work + 0xe));
    }
    if (func_002741f0() != 0)
        work[0] |= 0x10;
    work[0xa] = 0;
    i = 0;
    goto first_check;
first_body:
    if (*(u8*)((u8*)work + 0x5a + i) != 0)
        goto first_done;
    i++;
first_check:
    if (i < 5)
        goto first_body;
first_done:
    work[0xa] = i;
    work[0xb] = 0;
    i = 0;
    goto last_check;
last_body:
    if (*(u8*)((u8*)work + 0x5a + i) == 0)
        goto last_after;
    work[0xb] = i;
last_after:
    i++;
last_check:
    if (i < 5)
        goto last_body;

    resultCount = (s32)FUN_002751e0();
    work[0x70] = resultCount;
    resultIndex = 0;
    goto result_check;
result_body:
    entry = FUN_00275050(resultIndex);
    *(u16*)((u8*)work + 0x1c4 + resultIndex * 8) =
        *(u16*)(entry + 2);
    tableEntry = DAT_007ce420 +
                 (u32)(*(u16*)((u8*)(uintptr_t)work[0xc] + 2)) * 0x0e;
    *(u32*)((u8*)work + 0x1c8 + resultIndex * 8) =
        (u32)entry[0] + tableEntry[3];
    resultIndex++;
result_check:
    if (resultIndex < resultCount)
        goto result_body;

    work[4] = 0;
    if ((s32)work[0xa] < 5 && (s32)work[0xb] < 5)
        func_00279660();
    func_00274c00();
    work[0] |= 0x100;
    work[0] |= 1;
}

// FUN_002727C0
u32 func_002727c0(void)
{
    K_ASSERT(sBrpSeq != NULL, 0xb0);
    return brpSeqU32(0) & 1;
}

extern void func_00276a80(void);
extern void func_00276b10(void);
extern void func_002798f0(void);
#define brpSeqBytes() work
#define brpSeqU32(offset) (*(u32*)(work + (offset)))
#define brpSeqS32(offset) (*(s32*)(work + (offset)))
#define brpSeqU16(offset) (*(u16*)(work + (offset)))
#define brpSeqS16(offset) (*(s16*)(work + (offset)))
#define brpSeqU8(offset) (*(u8*)(work + (offset)))
#define brpSeqPutU32(offset, value) (*(u32*)(work + (offset)) = (value))
#define brpSeqPutU16(offset, value) (*(u16*)(work + (offset)) = (value))
#define brpSeqPutU8(offset, value) (*(u8*)(work + (offset)) = (value))
/* SocialBig W419 negatives: named equal=slot==last probe (without scoped slot/last locals) was nd2332/3912B, 93 worse than the retained scoped shape nd2239/3912B; removing last and re-reading brpSeqU32(0x2c) regressed nd2460/3924B. */
// FUN_00272810 NONMATCHING
void func_00272810(void)
{
    u8* work;
    DatPersonaWork* persona;
    u32 state;
    u32 index;
    u16 skillId;
    u32 selected;
    u32 done;
    u32 mode;
    u32 page;
    u32 pad;
    u8 text[256];

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    work = (u8*)sBrpSeq;
    if ((~brpSeqU32(0) & 1) == 0)
    {
        state = brpSeqU32(0x10);
        switch (state)
        {
        case 0:
            if ((brpSeqU32(0) & 0x100) != 0 && func_00276cc0() == 0)
                brpSeqPutU32(0, brpSeqU32(0) & ~0x100u);
            break;
        case 1:
            switch (brpSeqU32(0x14))
            {
            case 0:
                FUN_003c7990(0);
                if (FUN_003c7850() == 0)
                {
                    if (brpSeqU32(0x28) < 5 && brpSeqU32(0x2c) < 5)
                    {
                        FUN_003c7650(0);
                        func_00273b30();
                    }
                    else
                    {
                        FUN_003c7650(1);
                        brpSeqPutU32(0x10, 2);
                        func_00273800();
                    }
                }
                break;
            }
            break;
        case 2:
            if (brpSeqU32(0x24) == 1)
            {
                if (func_00279700() == 0)
                    func_00273800();
            }
            else if (brpSeqU32(0x24) == 0)
            {
                u32 slot;
                u32 last;
                slot = brpSeqU32(0x28);
                last = brpSeqU32(0x2c);
                FUN_003c7990(slot == last);
                if (FUN_003c7850() == 0)
                {
                    FUN_003c7650(slot == last);
                    while (slot < last && slot < 4)
                    {
                        slot++;
                        if (brpSeqU8(0x5b + slot) != 0)
                            break;
                    }
                    brpSeqPutU32(0x28, slot);
                    if (slot < last)
                    {
                        FUN_00523ac8(text, &gp0xffff97d0,
                                     brpSeqU8(0x5b + slot));
                        FUN_003c7bc0(0, (u32)(uintptr_t)PTR_s_Strength_0068ed70[slot]);
                        FUN_003c7bc0(1, (u32)(uintptr_t)text);
                        FUN_003c7430(1);
                        FUN_0010a4e0(1, 0, 8, 1);
                    }
                    else
                    {
                        func_002796b0();
                        brpSeqPutU32(0x24, 1);
                    }
                }
            }
            break;
        case 3:
            switch (brpSeqU32(0x18))
            {
            case 0:
                if (func_002797a0() == 0)
                {
                    skillId = brpSeqU16(0x1c4 + brpSeqU32(0x1b0) * 8);
                    brpSeqPutU16(0x60 + brpSeqU32(0x74) * 2, skillId);
                    brpSeqPutU32(0x74, brpSeqU32(0x74) + 1);
                    FUN_003c7bc0(0, FUN_00173220(brpSeqU16(4)));
                    FUN_003c7bc0(1, DAT_007ce4ec + skillId * 0x13);
                    FUN_003c7430(2);
                    brpSeqPutU32(0x18, 1);
                }
                break;
            case 1:
                selected = brpSeqU32(0x74);
                FUN_003c7990(selected < 9);
                if (FUN_003c7850() == 0)
                {
                    FUN_003c7650(selected < 9);
                    if (selected < 9)
                        func_00274100();
                    else
                        func_00273e10();
                }
                break;
            case 2:
                FUN_003c7990(1);
                if (FUN_003c7850() == 0)
                {
                    FUN_003c7650(1);
                    func_002797f0();
                    brpSeqPutU32(0x1b8, 0);
                    brpSeqPutU32(0x1bc, 0);
                    func_00279890(0, 0);
                    brpSeqPutU32(0x18, 3);
                }
                break;
            case 3:
                pad = DAT_007e0952;
                if ((DAT_007e094e & 0x40) != 0)
                {
                    index = brpSeqU32(0x1b8) == 2 ?
                            8 : brpSeqU32(0x1bc) +
                            brpSeqU32(0x1b8) * 4;
                    skillId = brpSeqU16(0x60 + index * 2);
                    FUN_003c7bc0(0, DAT_007ce4ec + skillId * 0x13);
                    FUN_003c7430(4);
                    FUN_003c74e0(5);
                    FUN_0010a4e0(0, 0, 0, 1);
                    brpSeqPutU32(0x18, 4);
                }
                else
                {
                    if (brpSeqU32(0x1b8) < 2 && (pad & 0x4000) != 0)
                    {
                        page = brpSeqU32(0x1bc);
                        page = page < 3 ? page + 1 : 0;
                        brpSeqPutU32(0x1bc, page);
                        if (brpSeqU32(0x1b8) == 2)
                            func_00279890(brpSeqU32(0x1b8), 1);
                        else
                            func_00279890(brpSeqU32(0x1b8),
                                          brpSeqU32(0x1bc));
                        FUN_0010a4e0(0, 0, 0, 0);
                    }
                    else if (brpSeqU32(0x1b8) < 2 &&
                             (pad & 0x1000) != 0)
                    {
                        page = brpSeqU32(0x1bc);
                        page = page != 0 ? page - 1 : 3;
                        brpSeqPutU32(0x1bc, page);
                        if (brpSeqU32(0x1b8) == 2)
                            func_00279890(brpSeqU32(0x1b8), 1);
                        else
                            func_00279890(brpSeqU32(0x1b8),
                                          brpSeqU32(0x1bc));
                        FUN_0010a4e0(0, 0, 0, 0);
                    }
                    else if ((pad & 0x2000) != 0)
                    {
                        mode = brpSeqU32(0x1b8);
                        mode = mode < 2 ? mode + 1 : 0;
                        brpSeqPutU32(0x1b8, mode);
                        if (brpSeqU32(0x1b8) == 2)
                            func_00279890(brpSeqU32(0x1b8), 1);
                        else
                            func_00279890(brpSeqU32(0x1b8),
                                          brpSeqU32(0x1bc));
                        FUN_0010a4e0(0, 0, 0, 0);
                    }
                    else if ((pad & 0x8000) != 0)
                    {
                        mode = brpSeqU32(0x1b8);
                        mode = mode != 0 ? mode - 1 : 2;
                        brpSeqPutU32(0x1b8, mode);
                        if (brpSeqU32(0x1b8) == 2)
                            func_00279890(brpSeqU32(0x1b8), 1);
                        else
                            func_00279890(brpSeqU32(0x1b8),
                                          brpSeqU32(0x1bc));
                        FUN_0010a4e0(0, 0, 0, 0);
                    }
                    index = brpSeqU32(0x1b8) == 2 ?
                            8 : brpSeqU32(0x1bc) +
                            brpSeqU32(0x1b8) * 4;
                    skillId = brpSeqU16(0x60 + index * 2);
                    uGpffff97ec = skillId == 0 ? (u32)-1 : skillId;
                }
                break;
            case 4:
                FUN_003c7990(1);
                if (FUN_003c7850() == 0)
                {
                    done = FUN_003c7610();
                    if (done == 1)
                    {
                        FUN_003c7650(1);
                        brpSeqPutU32(0x18, 3);
                    }
                    else if (done == 0)
                    {
                        u32 slot;
                        FUN_003c7650(1);
                        index = brpSeqU32(0x1b8) == 2 ?
                                8 : brpSeqU32(0x1bc) +
                                brpSeqU32(0x1b8) * 4;
                        skillId = brpSeqU16(0x60 + index * 2);
                        for (slot = index; slot + 1 < brpSeqU32(0x74); slot++)
                            brpSeqPutU16(0x60 + slot * 2,
                                         brpSeqU16(0x62 + slot * 2));
                        brpSeqPutU32(0x74, brpSeqU32(0x74) - 1);
                        FUN_003c7bc0(0, FUN_00173220(brpSeqU16(4)));
                        FUN_003c7bc0(1, DAT_007ce4ec + skillId * 0x13);
                        if (index == 8)
                            FUN_003c7430(6);
                        else
                            FUN_003c7430(7);
                        brpSeqPutU32(0x18, 5);
                    }
                }
                break;
            case 5:
                FUN_003c7990(1);
                if (FUN_003c7850() == 0)
                {
                    FUN_003c7650(1);
                    func_00274100();
                }
                break;
            }
            break;
        case 5:
            switch (brpSeqU32(0x1c))
            {
            case 0:
                FUN_003c7990(0);
                if (FUN_003c7850() == 0)
                {
                    done = FUN_003c7610();
                    switch (done)
                    {
                    case 0:
                        FUN_003c7650(1);
                        persona = (DatPersonaWork*)(uintptr_t)brpSeqU32(0x30);
                        if ((persona->flags & 8) == 0)
                        {
                            brpSeqPutU16(0x80, FUN_001fb560(brpSeqS16(4)));
                            brpSeqPutU32(0xa4, 0);
                            brpSeqPutU32(0, brpSeqU32(0) | 4);
                            FUN_005225a8((u32)(uintptr_t)D_0068ED98,
                                         brpSeqU16(0x80));
                            FUN_0024a7f0();
                            brpSeqPutU32(0, brpSeqU32(0) | 0x40);
                            func_0024ab10(brpSeqU16(0x80));
                            H_Fade_FadeOut();
                            H_Fade_SetType(2);
                            brpSeqPutU32(0x1c, 3);
                        }
                        else
                        {
                            brpSeqPutU16(0x84, FUN_001fba70(brpSeqS16(4)));
                            brpSeqPutU32(0xa4, 1);
                            brpSeqPutU32(0, brpSeqU32(0) | 8);
                            FUN_005225a8((u32)(uintptr_t)D_0068EDA8,
                                         brpSeqU32(0x84));
                            FUN_0024a7f0();
                            brpSeqPutU32(0, brpSeqU32(0) | 0x40);
                            func_0024abd0();
                            H_Fade_FadeOut();
                            H_Fade_SetType(2);
                            brpSeqPutU32(0x1c, 3);
                        }
                        break;
                    case 1:
                        FUN_003c7650(0);
                        FUN_003c7bc0(0, FUN_00173220(brpSeqU16(4)));
                        FUN_003c7430(10);
                        brpSeqPutU32(0x1c, 1);
                        break;
                    }
                    FUN_003c77a0();
                    persona = (DatPersonaWork*)(uintptr_t)brpSeqU32(0x30);
                    persona->flags &= (u16)~0x0cu;
                }
                break;
            case 1:
                FUN_003c7990(0);
                if (FUN_003c7850() == 0)
                {
                    FUN_003c7650(0);
                    func_00273800();
                }
                break;
            case 2:
                FUN_003c7990(1);
                if (FUN_003c7850() == 0)
                {
                    FUN_003c7650(1);
                    FUN_0024aa90();
                    brpSeqPutU32(0x1c, 5);
                }
                break;
            case 3:
                if (func_0024ac40() == 0 && FUN_00108710() != 0)
                {
                    func_00276a80();
                    func_002798f0();
                    brLvpnlDisableDrawing();
                    FUN_0024a870();
                    brpSeqPutU32(0x1c, 4);
                }
                break;
            case 4:
                if (func_0024b9e0() == 0)
                {
                    FUN_003c72d0((void*)FUN_002347e0());
                    switch (brpSeqU32(0xa4))
                    {
                    case 0:
                        FUN_003c7bc0(0, FUN_00173220(brpSeqU16(4)));
                        FUN_003c7bc0(1, FUN_00173220(brpSeqU16(0x80)));
                        FUN_003c7430(0xb);
                        break;
                    case 1:
                        switch (FUN_00171250(brpSeqS16(0x84)))
                        {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                            FUN_001828d0(brpSeqS16(0x84),
                                         brpSeqBytes() + 0x88);
                            FUN_003c7bc0(1,
                                         FUN_00171110(brpSeqS16(0x84),
                                                      brpSeqU8(0x90)));
                            break;
                        case 4:
                            FUN_003c7bc0(1,
                                         FUN_00171110(brpSeqS16(0x84), 0));
                            break;
                        }
                        FUN_003c7bc0(0, FUN_00173220(brpSeqU16(4)));
                        FUN_003c7430(0xc);
                        break;
                    }
                    brpSeqPutU32(0x1c, 2);
                }
                break;
            case 5:
                if (func_0024b9e0() == 0)
                {
                    FUN_0024ac90();
                    brpSeqPutU32(0, brpSeqU32(0) & ~0x40u);
                    func_002798f0();
                    func_00276b10();
                    brLvpnlEnableDrawing();
                    brpSeqPutU32(0x1c, 6);
                }
                break;
            case 6:
                if (FUN_00108710() != 0)
                    func_00273800();
                break;
            }
            break;
        case 4:
            switch (brpSeqU32(0x20))
            {
            case 0:
                FUN_003c7990(1);
                if (FUN_003c7850() == 0)
                {
                    FUN_003c7650(1);
                    done = FUN_003c7610();
                    switch (done)
                    {
                    case 0:
                        switch (brpSeqU32(0x9c))
                        {
                        case 0:
                            FUN_003c7bc0(0, DAT_007ce4ec +
                                          brpSeqU16(0xa2) * 0x13);
                            FUN_003c7bc0(1, DAT_007ce4ec +
                                          brpSeqU16(0xa2) * 0x13);
                            FUN_003c7430(0xf);
                            FUN_0010a4e0(1, 0, 8, 3);
                            break;
                        case 1:
                            FUN_003c7bc0(0, DAT_007ce4ec +
                                          brpSeqU16(0xa2) * 0x13);
                            FUN_003c7bc0(1, DAT_007ce4ec +
                                          brpSeqU16(0xa2) * 0x13);
                            FUN_003c7430(0x10);
                            FUN_0010a4e0(1, 0, 8, 3);
                            break;
                        }
                        persona = (DatPersonaWork*)(uintptr_t)brpSeqU32(0x30);
                        FUN_001768e0(persona, brpSeqS16(0xa0));
                        FUN_00176840(persona, brpSeqU16(0xa2));
                        brpSeqPutU32(0x20, 1);
                        break;
                    case 1:
                        FUN_003c7bc0(0, FUN_00173220(brpSeqU16(4)));
                        FUN_003c7430(0xe);
                        brpSeqPutU32(0x20, 1);
                        break;
                    }
                }
                break;
            case 1:
                FUN_003c7990(1);
                if (FUN_003c7850() == 0)
                {
                    FUN_003c7650(1);
                    func_00273800();
                }
                break;
            }
            break;
        default:
            break;
        }
        if ((brpSeqU32(0) & 0x40) != 0)
            func_0024adf0();
    }
}
#undef brpSeqBytes
#undef brpSeqU32
#undef brpSeqS32
#undef brpSeqU16
#undef brpSeqS16
#undef brpSeqU8
#undef brpSeqPutU32
#undef brpSeqPutU16
#undef brpSeqPutU8
// FUN_002737a0

void brpSeq002737a0(void)
{
    K_ASSERT(sBrpSeq != NULL, 0xb0);
    if ((*sBrpSeq & 0x40) != 0) {
        func_0024b8a0();
    }
}

// FUN_00273800
void func_00273800(void)
{
    u8* work;
    s32 value;
    s32 state;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    work = (u8*)sBrpSeq;
    state = *(s32*)(work + 0x10);
loop:
    switch (state)
    {
    case 2:
        value = *(s32*)(work + 0x1b4);
        if (value == 0)
        {
            state = 3;
            goto loop;
        }
        if (value != 0)
        {
            brpSeq00273c00();
            return;
        }
        state = 3;
        goto loop;
    case 3:
        func_002743a0();
        func_00274590();
        if ((*(u32*)work & 0x20) != 0)
        {
            func_00273d50();
            return;
        }
        state = 4;
        goto loop;
    case 4:
        if ((*(u32*)work & 0x10) != 0)
        {
            brpSeq00273c70();
            return;
        }
        state = 5;
        goto loop;
    case 5:
        func_00273a10();
        brpSeq00273980();
        return;
    default:
        K_ASSERT(0, 0x39b);
        K_ASSERT(0, 0x39f);
        goto loop;
    }
}

// FUN_00273980
void brpSeq00273980(void)
{
    u32* puVar1;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    puVar1 = sBrpSeq;
    K_ASSERT((~*puVar1 & 2) != 0, 0x3a8);
    puVar1[4] = 6;
    *puVar1 &= 0xfffffffe;
}

// FUN_00273A10
void func_00273a10(void)
{
    u8* work;
    s32 exp;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    work = (u8*)sBrpSeq;
    if ((*(u32*)work & 8) != 0)
    {
        switch (FUN_00171250(*(s16*)(work + 0x84)))
        {
        case 0:
        case 1:
        case 2:
        case 3:
            FUN_001830c0(work + 0x88);
            break;
        case 4:
            exp = FUN_00170760(1, *(s16*)(work + 0x84)) + 1;
            if (exp > 99)
                exp = 99;
            FUN_00170860(1, *(s16*)(work + 0x84), (u16)exp);
            break;
        }
        *(u32*)work &= ~8u;
    }
    if ((*(u32*)work & 4) != 0)
        func_00274030();
}

// FUN_00273B30
void func_00273b30(void)
{
    u8 text[256];
    u8* work;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    work = (u8*)sBrpSeq;
    FUN_00523ac8(text, &gp0xffff97d0,
                 (*(u32*)(work + 0x28) + work)[0x5a]);
    FUN_003c7bc0(0, *(PTR_s_Strength_0068ed70 +
                      *(u32*)(work + 0x28)));
    FUN_003c7bc0(1, text);
    FUN_003c7430(1);
    FUN_0010a4e0(1, 0, 8, 1);
    *(u32*)(work + 0x24) = 0;
    *(u32*)(work + 0x10) = 2;
}

// FUN_00273c00
void brpSeq00273c00(void)
{
    int iVar1;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    iVar1 = (int)sBrpSeq;
    FUN_00279750();
    scrClearTextBox(1, 0, 8, 2);
    *(u32*)(iVar1 + 0x18) = 0;
    *(u32*)(iVar1 + 0x10) = 3;
}

// FUN_00273c70
void brpSeq00273c70(void)
{
    u32* puVar1;
    u32 uVar2;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    puVar1 = sBrpSeq;
    *puVar1 &= 0xffffffef;
    K_ASSERT((~puVar1[2] & 1) != 0, 0x3ef);
    uVar2 = FUN_00173220(*(u16*)((int)puVar1 + 4));
    FUN_003c7bc0(0, uVar2);
    FUN_003c7430(8);
    FUN_003c74e0(9);
    FUN_003c7560(0);
    scrClearTextBox(1, 0, 8, 4);
    puVar1[7] = 0;
    puVar1[4] = 5;
}

// FUN_00273D50
void func_00273d50(void)
{
    u8* work;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    work = (u8*)sBrpSeq;
    FUN_003c7bc0(0, FUN_00173220(*(u16*)(work + 4)));
    FUN_003c7bc0(1, DAT_007ce4ec + *(u16*)(work + 0xa0) * 0x13);
    FUN_003c7430(0xd);
    FUN_003c74e0(9);
    *(u32*)work &= ~0x20u;
    *(u32*)(work + 0x20) = 0;
    *(u32*)(work + 0x10) = 4;
}

// FUN_00273e10
void brpSeq00273e10(void)
{
    int iVar1;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    iVar1 = (int)sBrpSeq;
    K_ASSERT(*(int*)(iVar1 + 0x74) == 9, 0x40e);
    FUN_003c7430(3);
    *(u32*)(iVar1 + 0x18) = 2;
}

// FUN_00273E90
void func_00273e90(void)
{
    s32 existingCount;
    s32 removeIndex;
    s32 addIndex;
    s32 copyIndex;
    s32 currentIndex;
    s32 existingIndex;
    u16* skills;
    u8* source;
    s32 count;
    u8* work;
    u16* oldSkill;
    u8* newSkill;
    u16 current[8];

    K_ASSERT(sBrpSeq != NULL, 0xb0);

    source = (u8*)sBrpSeq;
    count = FUN_00176a30((DatPersonaWork*)(uintptr_t)
                         *(u32*)(source + 0x30));
    work = source;
    skills = FUN_00173370((DatPersonaWork*)(uintptr_t)
                          *(u32*)(work + 0x30));
    for (copyIndex = 0; copyIndex < (s32)count; copyIndex++)
        current[copyIndex] = skills[copyIndex];
    for (removeIndex = 0; removeIndex < (s32)count; removeIndex++)
    {
        existingIndex = 0;
        oldSkill = &current[removeIndex];
        existingCount = *(s32*)(work + 0x74);
        while (existingIndex < existingCount)
        {
            if (*(u16*)(work + 0x60 + existingIndex * 2) == *oldSkill)
                break;
            existingIndex++;
        }
        if (existingIndex >= existingCount)
            FUN_001768e0((DatPersonaWork*)(uintptr_t)
                         *(u32*)(work + 0x30), *oldSkill);
    }
    for (addIndex = 0; addIndex < *(s32*)(work + 0x74); addIndex++)
    {
        currentIndex = 0;
        newSkill = work + addIndex * 2;
        while (currentIndex < (s32)count)
        {
            if (*(u16*)(newSkill + 0x60) == current[currentIndex])
                break;
            currentIndex++;
        }
        if (currentIndex >= (s32)count)
            FUN_00176840((DatPersonaWork*)(uintptr_t)
                         *(u32*)(work + 0x30),
                         *(u16*)(newSkill + 0x60));
    }
}
// FUN_00274030
void func_00274030(void)
{
    u8* work;
    u16 current;
    DatPersonaWork* currentPersona;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    work = (u8*)sBrpSeq;
    current = (u16)FUN_001756f0();
    K_ASSERT(current < (u16)FUN_00175410(), 0x447);
    FUN_00174e20(*(u16*)(work + 0x80));
    currentPersona = FUN_001749a0(*(u16*)(work + 4));
    FUN_00176d10(FUN_001749a0(*(u16*)(work + 0x80)), currentPersona);
    *(u32*)work &= ~4u;
}

// FUN_00274100
void func_00274100(void)
{
    u8* work;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    work = (u8*)sBrpSeq;
    *(s32*)(work + 0x1b0) += 1;
    func_00279120();
    func_002792c0();
    func_00274c00();
    func_00279840();
    if (*(s32*)(work + 0x1b0) < *(s32*)(work + 0x1b4))
    {
        K_ASSERT(sBrpSeq != NULL, 0xb0);
        work = (u8*)sBrpSeq;
        FUN_00279750();
        FUN_0010a4e0(1, 0, 8, 2);
        *(u32*)(work + 0x18) = 0;
        *(u32*)(work + 0x10) = 3;
    }
    else
        func_00273800();
}

/* Removing this loses FUN_002741f0 (MATCH nd0 -> MISMATCH nd51) - measured W161. */
// FUN_002741F0
#pragma opt_loop_invariants on
u32 func_002741f0(void)
{
    u32 pad;
    u16 currentLevel;
    u8* work;
    u32 flags;
    u8* persona;
    s32 levelDiff;
    u8* newVar;
    s8 kind;
    s32 i;
    u8* entry;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    work = (u8*)sBrpSeq;
    if ((*(u32*)(work + 8) & 1) != 0)
        return 0;
    flags = ~*(u16*)(*(u32*)(work + 0x30));
    if ((flags & 4) != 0)
        return 0;
    if ((flags & 8) != 0)
    {
        currentLevel = (u16)FUN_001756f0();
        K_ASSERT(currentLevel <= (u16)FUN_00175410(), 0x474);
        currentLevel = (u16)FUN_001756f0();
        if (currentLevel == (u16)FUN_00175410())
            return 0;
    }
    else if (FUN_0016f490(1) == 300)
        return 0;
    newVar = work + 0x30;
    persona = (u8*)(*(u32*)newVar);
    levelDiff = persona[4] -
                DAT_007ce420[*(u16*)(persona + 2) * 0x0e + 3];
    for (i = 0; i < 0x10; i++)
    {
        entry = *(u8**)(work + 0x34) + i * 4 + 6;
        kind = *(s8*)(entry + 1);
        if (kind == 0)
            goto done;
        if (entry[0] > levelDiff)
            goto next;
        if (kind != 4)
            goto next;
        return 1;
next:
        ;
    }
done:
    return 0;
}
#pragma opt_loop_invariants reset

// FUN_002743A0
void func_002743a0(void)
{
    K_ASSERT(sBrpSeq != NULL, 0xb0);
    func_00273e90();
}

// FUN_002743E0
void func_002743e0(void* destination, s32* count)
{
    s32 outCount;
    u32* work;
    u16* skills;
    s32 skillCount;
    s32 copyIndex;
    s32 i;
    u8* growth;
    s8 kind;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    work = sBrpSeq;
    skills = FUN_00173370((DatPersonaWork*)(uintptr_t)work[0xc]);
    skillCount = (s32)FUN_00176a30((DatPersonaWork*)(uintptr_t)work[0xc]);
    outCount = 0;
    for (copyIndex = 0; copyIndex < skillCount; copyIndex++)
        ((u16*)destination)[outCount++] = skills[copyIndex];
    for (i = (s32)work[0x1e]; i < 0x10; i++)
    {
        growth = (u8*)(uintptr_t)(i * 4 + work[0xd]) + 6;
        kind = *(s8*)(growth + 1);
        switch (kind)
        {
        case 2:
            K_ASSERT(0, 0x4bc);
            break;
        case 0:
        case 4:
            break;
        case 1:
            K_ASSERT(outCount < 16, 0x4c4);
            ((u16*)destination)[outCount++] = *(u16*)(growth + 2);
            break;
        case 3:
            K_ASSERT(0, 0x4cc);
            break;
        default:
            break;
        }
    }
    *count = outCount;
}

/* W418 cast probe: (u32)randomValue reduced nd689/1644B (0.4191) to nd688/1644B (0.4185); declaration move stayed nd689/1644B. */
/* SocialA W417 negative: moving rankMap after skillCount was byte-identical (nd 689, object 1644/1648); retained source order. */
// FUN_00274590 NONMATCHING
void func_00274590(void)
{
    u32* work;
    u16* skills;
    s8* rankMap;
    u8 level;
    s32 flags[2];
    s32 indices[8];
    u16 candidates[8];
    u16 excluded[16];
    s32 excludedCount;
    s32 skillCount;
    s32 candidateCount;
    s32 modeIndex;
    s32 i;
    s32 j;
    s32 k;
    s32 randomValue;
    s32 randomIndex;
    s32 selected;
    s32 desiredRank;
    u16* pair;


    K_ASSERT(sBrpSeq != NULL, 0xb0);
    work = sBrpSeq;
    skills = FUN_00173370((DatPersonaWork*)(uintptr_t)work[0xc]);
    skillCount = (s32)FUN_00176a30(
        (DatPersonaWork*)(uintptr_t)work[0xc]);
    rankMap = (s8*)FUN_003d5c90();
    func_002743e0(excluded, &excludedCount);
    FUN_005225a8((u32)(uintptr_t)D_0068EDC0);
    randomValue = FUN_00488f30();
    randomValue = (s32)((u32)randomValue % 100);
    level = FUN_0016c470(1);
    FUN_005225a8((u32)(uintptr_t)D_0068EDE0, level);
    FUN_005225a8((u32)(uintptr_t)D_0068EDF0, level, 10);
    if (level < 0xb)
    {
        FUN_005225a8((u32)(uintptr_t)D_0068EE00);
        goto done;
    }
    FUN_005225a8((u32)(uintptr_t)&gp0xffff97d0_1);
    FUN_005225a8((u32)(uintptr_t)(&gp0xffff97d0_2 + 1),
                 randomValue, 0xc);
    if ((u32)randomValue >= 0xc)
    {
        FUN_005225a8((u32)(uintptr_t)D_0068EE00);
        goto done;
    }
    FUN_005225a8((u32)(uintptr_t)&gp0xffff97d0_3);
    randomValue = FUN_00488f30() & 0xff;
    FUN_005225a8((u32)(uintptr_t)D_0068EE10, randomValue, 1);
    if (randomValue == 0)
    {
        flags[0] = 0;
        flags[1] = 1;
    }
    else
    {
        flags[0] = 1;
        flags[1] = 0;
    }

    for (modeIndex = 0; modeIndex < 2; modeIndex++)
    {
        if (flags[modeIndex] == 1)
            goto mode_one;
        if (flags[modeIndex] != 0)
            goto next_mode;

        candidateCount = 0;
        pair = DAT_007ce438;
        for (;; pair += 2)
        {
            if (pair[0] == 0 && pair[1] == 0)
                break;
            i = 0;
            while (i < skillCount && skills[i] != pair[0])
                i++;
            if (i < skillCount)
            {
                j = 0;
                while (j < excludedCount && excluded[j] != pair[1])
                    j++;
                if (j == excludedCount)
                {
                    indices[candidateCount] = i;
                    candidates[candidateCount] = pair[1];
                    candidateCount++;
                }
            }
        }
        FUN_005225a8((u32)(uintptr_t)D_0068EE28, candidateCount);
        if (candidateCount == 0)
        {
            FUN_005225a8((u32)(uintptr_t)D_0068EE00);
            goto next_mode;
        }
        FUN_005225a8((u32)(uintptr_t)&gp0xffff97d0_4);
        randomValue = FUN_00488f30();
        randomIndex = randomValue % candidateCount;
        FUN_005225a8((u32)(uintptr_t)D_0068EE40, randomIndex);
        selected = skills[indices[randomIndex]];
        FUN_005225a8((u32)(uintptr_t)D_0068EE60, selected,
                     candidates[randomIndex]);
        *(u16*)((u8*)work + 0xa0) = (u16)selected;
        *(u16*)((u8*)work + 0xa2) = candidates[randomIndex];
        work[0x27] = 0;
        work[0] |= 0x20;
        goto done;

mode_one:
        candidateCount = 0;
        pair = DAT_007ce438;
        for (;; pair += 2)
        {
            if (pair[0] == 0 && pair[1] == 0)
                break;
            i = 0;
            while (i < skillCount && skills[i] != pair[0])
                i++;
            if (i < skillCount)
            {
                j = 0;
                while (j < excludedCount && excluded[j] != pair[1])
                    j++;
                if (j == excludedCount)
                {
                    indices[candidateCount] = i;
                    candidates[candidateCount] = pair[1];
                    candidateCount++;
                }
            }
        }
        FUN_005225a8((u32)(uintptr_t)D_0068EE28, candidateCount);
        if (candidateCount == 0)
        {
            FUN_005225a8((u32)(uintptr_t)D_0068EE00);
            goto next_mode;
        }
        FUN_005225a8((u32)(uintptr_t)&gp0xffff97d0_5);
        randomValue = FUN_00488f30();
        randomIndex = randomValue % candidateCount;
        FUN_005225a8((u32)(uintptr_t)D_0068EE40, randomIndex);
        selected = skills[indices[randomIndex]];
        desiredRank = (s32)rankMap[selected] + 1;

        candidateCount = 0;
        i = 0;
        while (i < 0x270)
        {
            if ((s32)rankMap[i] == desiredRank)
            {
                j = 0;
                while (j < excludedCount && excluded[j] != i)
                    j++;
                if (j == excludedCount)
                    candidateCount++;
            }
            i++;
        }
        FUN_005225a8((u32)(uintptr_t)D_0068EE80, candidateCount);
        if (candidateCount == 0)
        {
            FUN_005225a8((u32)(uintptr_t)D_0068EE00);
            goto next_mode;
        }
        FUN_005225a8((u32)(uintptr_t)&gp0xffff97d0_6);
        randomValue = FUN_00488f30();
        randomIndex = randomValue % candidateCount;
        i = 0;
        j = 0;
        while (i < 0x270)
        {
            if ((s32)rankMap[i] == desiredRank)
            {
                k = 0;
                while (k < excludedCount && excluded[k] != i)
                    k++;
                if (k == excludedCount)
                {
                    if (j == randomIndex)
                        break;
                    j++;
                }
            }
            i++;
        }
        randomIndex = i & 0xffff;
        FUN_005225a8((u32)(uintptr_t)D_0068EE90, selected, randomIndex);
        *(u16*)((u8*)work + 0xa0) = (u16)selected;
        *(u16*)((u8*)work + 0xa2) = (u16)randomIndex;
        work[0x27] = 1;
        work[0] |= 0x20;
        goto done;

next_mode:
        continue;
    }

done:
    return;
}

/* Removing this loses func_00274c00 (MATCH nd0 -> MISMATCH nd8) - measured W161. */
// FUN_00274C00
#pragma optimization_level 1
void func_00274c00(void)
{
    s32 i;
    u32* work;
    DatPersonaWork* persona;
    u16 stat;
    u32 value;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    work = sBrpSeq;
    for (i = 0; i < (s32)work[0x1d]; i++)
        func_002791b0(*(u16*)((u8*)work + 0x60 + i * 2));
    if (func_00274d40() != 0)
    {
        func_00279330(func_00274d90());
        brpParamSetUnlockedSkillLevel(func_00274e10());
    }
    brpParamSetUnlockedSkillIndex((u32)func_00274e90());
    for (i = 0; i < 5; i++)
    {
        stat = (u16)i;
        persona = (DatPersonaWork*)(uintptr_t)work[0xc];
        value = (u8)FUN_00173580(persona, stat);
        func_00279510(i, value);
        func_00279580(i, value);
        func_002795f0(i, *(u8*)((u8*)work + 0x5a + i));
    }
}
#pragma optimization_level 2

// FUN_00274D40
u32 func_00274d40(void)
{
    K_ASSERT(sBrpSeq != NULL, 0xb0);
    return brpSeqS32(0x1b0) < brpSeqS32(0x1c0);
}

// FUN_00274D90
u32 func_00274d90(void)
{
    u8* work;
    u32 offset;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    work = (u8*)sBrpSeq;
    K_ASSERT(*(s32*)(work + 0x1b0) < *(s32*)(work + 0x1c0), 0x5de);
    offset = *(s32*)(work + 0x1b0) * 8;
    offset += (uintptr_t)work;
    return *(u16*)(offset + 0x1c4);
}

// FUN_00274E10
u32 func_00274e10(void)
{
    u8* work;
    u32 offset;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    work = (u8*)sBrpSeq;
    K_ASSERT(*(s32*)(work + 0x1b0) < *(s32*)(work + 0x1c0), 0x5e6);
    offset = *(s32*)(work + 0x1b0) * 8;
    offset += (uintptr_t)work;
    return *(u32*)(offset + 0x1c8);
}

// FUN_00274E90
s32 func_00274e90(void)
{
    s32 remaining;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    remaining = (s32)brpSeqU32(0x1c0) - (s32)brpSeqU32(0x1b0);
    return remaining < 2 ? 0 : remaining - 1;
}

// FUN_00274F00
s32 func_00274f00(void)
{
    u32* work;
    u16* skills;
    s32 skillCount;
    s32 i;
    s32 j;
    s32 count;
    s8 kind;
    u8* entry;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    work = sBrpSeq;
    skills = FUN_00173370((DatPersonaWork*)(uintptr_t)work[0xc]);
    skillCount = (s32)FUN_00176a30((DatPersonaWork*)(uintptr_t)work[0xc]);
    if (work[0x1f] == 0)
        return 0;
    i = 0;
    count = 0;
    do
    {
        entry = (u8*)(uintptr_t)work[0xd] +
                (work[0x1e] + (u32)i) * 4 + 6;
        kind = *(s8*)(entry + 1);
        if (kind == 0)
            break;
        if (kind == 4)
            continue;
        if (kind != 1)
        {
            K_ASSERT(0, 0x612);
            continue;
        }
        j = 0;
        while (j < skillCount)
        {
            if (skills[j] == *(u16*)(entry + 2))
                break;
            j++;
        }
        if (j == skillCount)
            count++;
    } while (++i != (s32)work[0x1f]);
    return count;
}




/* Retail helpers used by the opening/ending result state. */
#pragma alias D_00960090_abs D_00960090
#pragma alias D_0096009C_abs D_0096009C



// FUN_00275050
u8* func_00275050(s32 index)
{
    u32 *work;
    u16 *skills;
    s32 skillCount;
    s32 slot;
    s32 skillIndex;
    s32 recordIndex;
    s32 unavailable;
    s8 kind;
    u8 *entry;
    u8 *record;

    if (gOpWorkC0 == NULL)
        K_Assert(D_0068ED88, 0xb0);
    work = gOpWorkC0;
    skills = datPersonaGetSkills((void *)(uintptr_t)work[0x30 / 4]);
    skillCount = (s32)datPersonaCountValidSkills(
        (void *)(uintptr_t)work[0x30 / 4]);
    OP_MATCH_ASSERT(index < (s32)work[0x1c0 / 4], 0x638);
    slot = 0;
    unavailable = 0;

loop:
    recordIndex = (s32)work[0x78 / 4] + slot;
    record = (u8 *)(uintptr_t)work[0x34 / 4] + recordIndex * 4;
    entry = record + 6;
    kind = *(s8 *)(record + 7);
    if (kind == 4)
        goto next;
    if (kind != 1)
    {
        K_Assert(D_0068ED88, 0x644);
        goto next;
    }
    skillIndex = 0;
    while (skillIndex < skillCount)
    {
        if (skills[skillIndex] == *(u16 *)(entry + 2))
            break;
        skillIndex++;
    }
    if (skillIndex != skillCount)
        goto next;
    if (unavailable == index)
        return entry;
    unavailable++;
next:
    slot++;
    if ((s32)work[0x78 / 4] + slot >= 0x10)
        K_Assert(D_0068ED88, 0x65b);
    goto loop;
}

// FUN_002751e0
s32 func_002751e0(void)
{
    s32 remaining;
    s32 slot;
    s32 unavailable;
    s32 i;
    u16 *skills;
    s32 skillCount;
    u32 *work;
    u8 *entry;
    u8 *persona;

    if (gOpWorkC0 == NULL)
        K_Assert(D_0068ED88, 0xb0);
    work = gOpWorkC0;
    skills = datPersonaGetSkills((void *)(uintptr_t)work[0x30 / 4]);
    skillCount = (s32)datPersonaCountValidSkills(
        (void *)(uintptr_t)work[0x30 / 4]);
    slot = 0;
    unavailable = 0;
    persona = (u8 *)(uintptr_t)work[0x30 / 4];
    remaining = persona[4] -
                DAT_007ce420_y2[*(u16 *)(persona + 2) * 0xe + 3] -
                OP_U8(work, 0x38);

loop:
    entry = (u8 *)(uintptr_t)(
                work[0x34 / 4] +
                ((s32)work[0x78 / 4] + slot) * 4) +
            6;
    switch (OP_S8(entry, 1))
    {
    default:
        K_Assert(D_0068ED88, 0x686);
        break;
    case 1:
        if (remaining < (s32)OP_U8(entry, 0))
        {
            for (i = 0; i < skillCount; i++)
            {
                if (OP_U16(entry, 2) == skills[i])
                    break;
            }
            if (i == skillCount)
                unavailable++;
        }
        break;
    case 4:
        break;
    case 0:
        goto done;
    }
    slot++;
    if ((s32)work[0x78 / 4] + slot != 0x10)
        goto loop;
done:
    return unavailable;
}

// FUN_00275370
u32 func_00275370(void)
{
    OP_MATCH_ASSERT(gOpWorkC0 != NULL, 0xb0);
    return *gOpWorkC0 & 0x100;
}

// FUN_002753c0
void func_002753c0(void)
{
    u8 *work;
    OP_MATCH_ASSERT(gOpWorkC0 != NULL, 0xb0);
    work = OP_WORK0;
    brLvpnlStartEntranceAnimation();
    func_003c7bc0(0, (u32)(uintptr_t)FUN_00173220_y2(OP_U16(work, 4)));
    func_003c7430(0);
    OP_U32(work, 0x14) = 0;
    OP_U32(work, 0x10) = 1;
}

// FUN_00275440
void func_00275440(void)
{
    u8 *work = (u8 *)OP_ALLOC(0x4510, 0x40000);
    OP_U32(work, 0x4500) = 0;
    func_00272330(work);
    brRes00233970((u32 *)(work + 0x210));
    func_00275a70((u32 *)(work + 0x260));
    func_00276910((u32 *)(work + 0x880));
    func_00276d10((u32 *)(work + 0x890));
    OP_U32(work, 0x4504) = func_00194b80(NULL, 10, DAT_0068EEB8,
                                           (void *)func_002756c0, NULL, NULL);
    OP_U32(work, 0x4508) = func_00194e10(DAT_0068EED0, 0x18ab,
                                           1, 2, (void *)func_002757a0, NULL, 0);
    gOpWorkC4 = (u32 *)work;
}



























