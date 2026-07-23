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

/* Retail helpers used by the opening/ending result state. */
extern u32 D_00960178[];
extern u32 D_0096017C[];
extern void (*D_00960090)(u32 state, u32 value);
extern void (*D_0096009C)(void *vertices, u32 primitive, u32 offset,
                          u32 first, u32 second);
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
#pragma alias D_0096009C_abs D_0096009C
extern u8 D_0096009C_abs[];
extern void *D_007D2D60;
extern u8 *DAT_007ce420;
extern s32 DAT_007cc4dc;
extern f32 DAT_007cad74;
extern f32 DAT_007caf38;
extern f32 DAT_007caf8c;
extern f32 DAT_007cafec;
extern f32 DAT_007cb04c;
extern const char DAT_0068EEB8[];
extern const char DAT_0068EED0[];

extern void *FUN_00173220(u16 id);
extern u16 *datPersonaGetSkills(void *persona);
extern u8 datPersonaGetTotalStat(void *persona, u16 stat);
extern u32 datPersonaCountValidSkills(void *persona);
extern void *FUN_001749a0(u16 id);
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
extern void func_0021d8e0(void *destination, const f32 *layout);
extern void func_0021d950(void *destination, const u8 *color);
extern u32 func_0021cca0(u32 resource, s32 frame);
extern u32 func_0021cce0(u32 frame);
extern void func_0021e380(void *destination, u32 source, s32 mode);
extern void func_0021eac0(void *destination, f32 value);
extern void func_00238980(void *destination, s32 count, u32 value, s32 mode);
extern void func_00238dc0(void *destination, s32 count, u32 value, s32 mode,
                           const f32 *layout);
extern void func_0025f5d0(void *destination, u32 resource, s32 frame);
extern void func_0025fc50(void *destination, u32 resource, s32 frame, s32 mode);
extern void func_00279120(void);
extern void func_002792c0(void);
extern u32 func_00239140(s32 font);
extern s32 sflPsel00260900(u32 *resource, s32 frame);
extern s32 sflPsel00260920(u32 *resource, s32 frame);
extern u32 sflPsel00260940(u32 *resource, s32 frame);
extern f32 func_00269c80(f32 value);
extern f32 func_00269ca0(f32 value);
extern void func_00272330(void *task);
extern void func_00272380(void);
extern void func_00272400(u64 value);
extern u32 func_002727c0(void);
extern void func_00272810(void);
extern void func_002791b0(u16 id);
extern void func_00279330(u16 id);
extern void brpParamSetUnlockedSkillLevel(u32 level);
extern void brpParamSetUnlockedSkillIndex(u32 index);
extern void func_00279510(s32 index, u32 value);
extern void func_00279580(s32 index, u32 value);
extern void func_002795f0(s32 index, u32 value);
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
extern void func_004d7f60(s32 state, u32 value);
extern void func_00521250(void *destination, const void *source, u32 size);
extern void func_005225a8(const void *message, ...);
extern void brLvpnlStartEntranceAnimation(void);
extern void brLvpnlDisableDrawing(void);
extern void brLvpnlEnableDrawing(void);
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
    ((u32)sflPsel00260900((u32 *)(uintptr_t)(resource), (frame)))
#define opTexH(resource, frame) \
    ((u32)sflPsel00260920((u32 *)(uintptr_t)(resource), (frame)))
#define opTexFrame(resource, frame) \
    (sflPsel00260940((u32 *)(uintptr_t)(resource), (frame)))

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


static u8 opClampByte(f32 value)
{
    if (value <= 0.0f)
        return 0;
    if (value >= 255.0f)
        return 0xff;
    return (u8)value;
}


// FUN_00275050 NONMATCHING
#pragma opt_loop_invariants off
void func_00275050(s32 index)
{
    register u8 *temp_19;
    register u16 *temp_18;
    register u32 temp_17;
    register s32 var_20;
    register s32 var_21;
    register s32 var_5;
    register s8 temp_4;
    if (gOpWorkC0 == NULL)
        K_Assert(D_0068ED88, 0xb0);
    temp_19 = (u8 *)gOpWorkC0;
    temp_18 = datPersonaGetSkills(OP_PTR(temp_19, 0x30));
    temp_17 = datPersonaCountValidSkills(OP_PTR(temp_19, 0x30));
    if (index >= OP_S32(temp_19, 0x1c0))
        K_Assert(D_0068ED88, 0x638);
    var_21 = 0;
    var_20 = 0;
loop_5:
    temp_4 = OP_S8((u8 *)(uintptr_t)(OP_S32(temp_19, 0x34) +
        (OP_S32(temp_19, 0x78) + var_21) * 4), 7);
    if (temp_4 == 4)
    {
block_16:
        var_21 += 1;
        if (OP_S32(temp_19, 0x78) + var_21 >= 0x10)
            K_Assert(D_0068ED88, 0x65b);
        goto loop_5;
    }
    if (temp_4 != 1)
    {
        K_Assert(D_0068ED88, 0x644);
        goto block_16;
    }
    var_5 = 0;
loop_11:
    if (var_5 < (s32)temp_17)
    {
        if (OP_U16((u8 *)(uintptr_t)(OP_S32(temp_19, 0x34) +
            (OP_S32(temp_19, 0x78) + var_21) * 4), 8) != temp_18[var_5])
        {
            var_5 += 1;
            goto loop_11;
        }
    }
    if (var_5 != (s32)temp_17)
        goto block_16;
    if (var_20 != index)
    {
        var_20 += 1;
        goto block_16;
    }
}
#pragma opt_loop_invariants on

// FUN_002751e0 NONMATCHING
s32 func_002751e0(void)
{
    s32 temp_21;
    s32 var_19;
    s32 var_20;
    s32 var_5;
    s8 temp_3;
    u16 *temp_17;
    u32 temp_16;
    void *temp_18;
    void *temp_2;

    if (gOpWorkC0 == NULL)
        K_Assert(D_0068ED88, 0xb0);
    temp_18 = OP_WORK0;
    temp_17 = datPersonaGetSkills(OP_PTR(temp_18, 0x30));
    temp_16 = datPersonaCountValidSkills(OP_PTR(temp_18, 0x30));
    var_20 = 0;
    var_19 = 0;
    temp_21 = (OP_U8(OP_PTR(temp_18, 0x30), 4) -
        OP_U8(DAT_007ce420 + OP_U16(OP_PTR(temp_18, 0x30), 2) * 0xe + 3, 0)) -
        OP_U8(temp_18, 0x38);
loop_3:
    temp_2 = (void *)(uintptr_t)(OP_S32(temp_18, 0x34) +
        (OP_S32(temp_18, 0x78) + var_20) * 4);
    temp_3 = OP_S8(temp_2, 7);
    switch (temp_3)
    {
    case 0:
        break;
    default:
        K_Assert(D_0068ED88, 0x686);
    case 4:
block_14:
        var_20 += 1;
        if (OP_S32(temp_18, 0x78) + var_20 != 0x10)
            goto loop_3;
        break;
    case 1:
        if (temp_21 < (s32)OP_U8(temp_2, 6))
        {
            var_5 = 0;
loop_11:
            if (var_5 < (s32)temp_16)
            {
                if (OP_U16((u8 *)temp_2 + 8, 2) != temp_17[var_5])
                {
                    var_5 += 1;
                    goto loop_11;
                }
            }
            if (var_5 == (s32)temp_16)
                var_19 += 1;
        }
        goto block_14;
    }
    return var_19;
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
    func_003c7bc0(0, (u32)(uintptr_t)FUN_00173220(OP_U16(work, 4)));
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

// FUN_00275520
void func_00275520(void)
{
    u8 *work;
    OP_MATCH_ASSERT(gOpWorkC4 != NULL, 0x46);
    work = OP_WORK4;
    func_00276c30();
    func_00272380();
    brRes00233e70();
    func_00275a80();
    func_00276920();
    func_00276d30();
    func_00195020(OP_U32(work, 0x4504));
    func_00195020(OP_U32(work, 0x4508));
    (*(void (**)(void *))D_0096017C)(work);
    gOpWorkC4 = NULL;
}

// FUN_002755d0
void func_002755d0(u64 value)
{
    u8 *work;
    OP_MATCH_ASSERT(gOpWorkC4 != NULL, 0x46);
    work = OP_WORK4;
    func_00275a90();
    func_00277070();
    func_00272400(value);
    func_00276d90();
    func_0010a370(3, "SOUND2\\EVENT\\EVE_530.ADX");
    OP_U32(work, 0x4500) |= 2;
    OP_U32(work, 0x4500) |= 1;
}

// FUN_00275670
u32 func_00275670(void)
{
    OP_MATCH_ASSERT(gOpWorkC4 != NULL, 0x46);
    return OP_U32(OP_WORK4, 0x4500) & 1;
}

// FUN_002756c0
u64 func_002756c0(void)
{
    u32 *work;
    OP_MATCH_ASSERT(gOpWorkC4 != NULL, 0x46);
    work = (u32 *)OP_WORK4;
    brRes00234070();
    func_00275bc0();
    func_00272810();
    func_00276930();
    func_002770f0();
    if ((work[0x4500 / 4] & 2) != 0 && func_00275370() == 0)
    {
        func_002753c0();
        work[0x4500 / 4] &= ~2u;
    }
    if ((work[0x4500 / 4] & 1) != 0 && func_002727c0() == 0)
        work[0x4500 / 4] &= ~1u;
    return 0;
}

// FUN_002757A0
u64 func_002757a0(void)
{
    func_005225a8((const void *)((const u8 *)&D_007D2D60 - 0x6888),
                  *(void **)(uintptr_t)0x00960070);
    func_00275cb0();
    func_00278550();
    return 0;
}

// FUN_002757e0
void func_002757e0(void *resource)
{
    u8 *data = (u8 *)resource;
    s32 i;
    OP_MATCH_ASSERT(OP_U16(data, 4) == 3, 0xc9);
    for (i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
        {
            u8 *entry = data + 8;
            entry += i * 8;
            brRes00234710(data + OP_U32(entry, 0), OP_U32(entry, 4));
            break;
        }
        case 1:
        {
            u8 *entry = (u8 *)(uintptr_t)(i * 8) + (uintptr_t)data;
            brRes00234690(0, OP_U32(entry, 8) + data);
            break;
        }
        case 2:
        {
            u8 *entry = (u8 *)(uintptr_t)(i * 8) + (uintptr_t)data;
            brRes00234690(1, OP_U32(entry, 8) + data);
            break;
        }
        }
    }
}

// FUN_002758e0
void func_002758e0(u32 arg0, u16 arg1)
{
    u16 skills[14];
    s32 count;
    s32 i;
    void *persona;
    u16 *personaSkills;
    func_002769c0(arg0, arg1);
    func_00276ba0();
    persona = FUN_001749a0(arg1);
    count = (s32)datPersonaCountValidSkills(persona);
    personaSkills = datPersonaGetSkills(persona);
    for (i = 0; i < count; i++)
        func_002791b0(personaSkills[i]);
    func_001fb1f0(persona, skills, &count);
    if (func_001fc230(persona) != 0)
    {
        func_00279330(skills[0]);
        brpParamSetUnlockedSkillLevel(func_001fc3c0(persona));
    }
    if (count > 1)
        brpParamSetUnlockedSkillIndex((u32)(count - 1));
    else
        brpParamSetUnlockedSkillIndex(0);
    {
        u32 stat;
        s32 statIndex;
        for (statIndex = 0; statIndex < 5; statIndex++)
        {
            stat = datPersonaGetTotalStat(persona, (u16)statIndex);
            func_00279510(statIndex, stat);
            func_00279580(statIndex, stat);
            func_002795f0(statIndex, 0);
        }
    }
    func_00276d90();
}

// FUN_00275A70
void func_00275a70(u32 *work)
{
    *work = 0;
    gOpWorkC8 = work;
}

// FUN_00275A80
void func_00275a80(void)
{
    gOpWorkC8 = NULL;
}

// FUN_00275a90
void func_00275a90(void)
{
    u32 *work;
    u32 resource;
    OP_MATCH_ASSERT(gOpWorkC8 != NULL, 0x3b);
    work = (u32*)OP_WORK8;
    resource = brRes00234630(0);
    func_0021d3b0(work + 4, func_0021cca0(resource, 0));
    func_0021d3b0(work + 0x44, func_0021cca0(resource, 2));
    func_0021d3b0(work + 0x84, func_0021cca0(resource, 1));
    func_0021d3b0(work + 0xc4, func_0021cca0(resource, 3));
    resource = func_0021cca0(resource, 0xb);
    func_0021d3b0(work + 0x104, resource);
    func_0021e380(work + 0x144, resource, 1);
    func_002760f0();
    *work |= 1;
}

// FUN_00275bc0
void func_00275bc0(void)
{
    u32 *work;
    u32 flags;
    OP_MATCH_ASSERT(gOpWorkC8 != NULL, 0x3b);
    work = (u32 *)OP_WORK8;
    flags = work[0];
    if ((~flags & 1) != 0)
        return;
    if ((flags & 2) != 0)
    {
        switch (work[0x614 / 4])
        {
        case 0:
            if (((s32 *)work)[0x610 / 4] < 0x24)
                work[0x610 / 4]++;
            else
                work[0] &= ~2u;
            break;
        case 1:
            if (((s32 *)work)[0x610 / 4] < 0x21)
                work[0x610 / 4]++;
            else
                work[0] &= ~2u;
            break;
        }
    }
    func_002760f0();
}

// FUN_00275cb0
void func_00275cb0(void)
{
    code *state;
    code *quad;
    u32 *work;
    u32 resource;
    OP_MATCH_ASSERT(gOpWorkC8 != NULL, 0x3b);
    work = (u32 *)OP_WORK8;
    resource = brRes00234630(0);
    if ((~*work & 1) != 0)
        return;
    if ((*work & 8) != 0)
        return;
    state = (code *)&D_00960090_abs;
    (*state)(8, 0);
    (*state)(6, 0);
    (*state)(9, 2);
    (*state)(9, 1);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*state)(1, func_0021cce0(func_0021cca0(resource, 0xb)));
    quad = (code *)&D_0096009C_abs;
    (*quad)(work + 0x104, 4, 0, 1, 2);
    (*quad)(work + 0x104, 4, 0, 2, 3);
    (*quad)(work + 0x144, 4, 0, 1, 2);
    (*quad)(work + 0x144, 4, 0, 2, 3);
    (*state)(9, 2);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*state)(1, func_0021cce0(func_0021cca0(resource, 0)));
    (*quad)(work + 4, 4, 0, 1, 2);
    (*quad)(work + 4, 4, 0, 2, 3);
    func_004d7f60(3, 0x71801);
    func_004d7f60(2, 0x48);
    (*state)(1, func_0021cce0(func_0021cca0(resource, 2)));
    (*quad)(work + 0x44, 4, 0, 1, 2);
    (*quad)(work + 0x44, 4, 0, 2, 3);
    (*state)(9, 2);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    (*state)(1, func_0021cce0(func_0021cca0(resource, 1)));
    (*quad)(work + 0x84, 4, 0, 1, 2);
    (*quad)(work + 0x84, 4, 0, 2, 3);
    func_004d7f60(3, 0x71801);
    func_004d7f60(2, 0x48);
    (*state)(1, func_0021cce0(func_0021cca0(resource, 3)));
    (*quad)(work + 0xc4, 4, 0, 1, 2);
    (*quad)(work + 0xc4, 4, 0, 2, 3);
}

// FUN_002760f0 NONMATCHING
void func_002760f0(void)
{
    u32 *work;
    f32 rect[4];
    u8 color[4];
    f32 alpha;
    f32 offset;
    u32 resource;
    u32 baseResource;
    K_ASSERT(gOpWorkC8 != NULL, 0x3b);
    work = (u32 *)OP_WORK8;
    baseResource = brRes00234630(0);
    resource = func_0021cca0(baseResource, 0);
    if ((OP_U32(work, 0) & 2) == 0)
        alpha = (OP_U32(work, 0) & 4) != 0 ? 1.0f : 0.0f;
    else if (OP_S32(work, 0x614) == 1)
    {
        alpha = 1.0f;
        offset = 0.0f;
    }
    else if (OP_S32(work, 0x614) == 0)
    {
        if (OP_S32(work, 0x610) < 0)
            alpha = 0.0f;
        else if (OP_S32(work, 0x610) < 6)
        {
            alpha = (f32)OP_S32(work, 0x610) / 6.0f;
            offset = (1.0f - alpha) * 100.0f;
        }
        else
            alpha = 1.0f;
    }
    resource = baseResource;
    rect[0] = offset + 128.0f;
    rect[1] = 0.0f;
    rect[2] = (f32)OP_S32((void *)(uintptr_t)resource, 0xc);
    rect[3] = (f32)OP_S32((void *)(uintptr_t)resource, 0x10);
    func_0021d8e0(work + 4, rect);
    color[0] = color[1] = color[2] = 0xff;
    color[3] = opClampByte(alpha * 255.0f);
    func_0021d950(work + 4, color);
    resource = func_0021cca0(baseResource, 1);
    rect[0] = offset + 359.0f;
    rect[1] = 0.0f;
    rect[2] = (f32)OP_S32((void *)(uintptr_t)resource, 0xc);
    rect[3] = (f32)OP_S32((void *)(uintptr_t)resource, 0x10);
    func_0021d8e0(work + 0x84, rect);
    color[3] = opClampByte(alpha * 255.0f);
    func_0021d950(work + 0x84, color);
    if ((OP_U32(work, 0) & 2) == 0)
        alpha = 0.0f;
    else if (OP_S32(work, 0x614) == 1)
    {
        s32 frame = OP_S32(work, 0x610);
        alpha = frame < 0 ? 0.0f : frame < 3 ? (f32)frame / 3.0f
                                             : frame < 0x21 ? 1.0f - (f32)(frame - 3) / 30.0f : 0.0f;
    }
    else
    {
        s32 frame = OP_S32(work, 0x610);
        alpha = frame < 3 ? 0.0f : frame < 6 ? (f32)(frame - 3) / 3.0f
                                             : frame < 0x24 ? 1.0f - (f32)(frame - 6) / 30.0f : 0.0f;
    }
    resource = func_0021cca0(baseResource, 2);
    rect[0] = 128.0f;
    rect[1] = 0.0f;
    rect[2] = (f32)OP_S32((void *)(uintptr_t)resource, 0xc);
    rect[3] = (f32)OP_S32((void *)(uintptr_t)resource, 0x10);
    func_0021d8e0(work + 0x44, rect);
    color[3] = opClampByte(alpha * 255.0f);
    func_0021d950(work + 0x44, color);
    resource = func_0021cca0(baseResource, 3);
    rect[0] = 359.0f;
    rect[1] = 0.0f;
    rect[2] = (f32)OP_S32((void *)(uintptr_t)resource, 0xc);
    rect[3] = (f32)OP_S32((void *)(uintptr_t)resource, 0x10);
    func_0021d8e0(work + 0xc4, rect);
    func_0021d950(work + 0xc4, color);
    resource = func_0021cca0(baseResource, 0xb);
    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = (f32)OP_S32((void *)(uintptr_t)resource, 0xc);
    rect[3] = (f32)OP_S32((void *)(uintptr_t)resource, 0x10);
    func_0021d8e0(work + 0x104, rect);
    rect[0] = rect[2];
    rect[2] = 650.0f;
    func_0021d8e0(work + 0x144, rect);
    color[3] = 0xff;
    func_0021d950(work + 0x104, color);
    func_0021d950(work + 0x144, color);
}

// FUN_00276910
void func_00276910(u32 *work)
{
    *work = 0;
    gOpWorkCC = work;
}

// FUN_00276920
void func_00276920(void)
{
    gOpWorkCC = NULL;
}

// FUN_00276930
void func_00276930(void)
{
    u8 *work;
    s32 flags;
    OP_MATCH_ASSERT(gOpWorkCC != NULL, 0x25);
    work = OP_WORKC;
    flags = OP_U32(work, 0);
    if ((~flags & 1) == 0 && (flags & 8) != 0 && func_003c9ab0(OP_U32(work, 4)) != 0)
        OP_U32(work, 0) &= ~8u;
}

// FUN_002769c0
void func_002769c0(u32 arg0, u16 arg1)
{
    u8 *work;

    OP_MATCH_ASSERT(gOpWorkCC != NULL, 0x25);
    work = OP_WORKC;
    func_003c9ba0(arg0, (u32)(uintptr_t)FUN_001749a0(arg1));
    func_003c9d00(arg0, 8);
    func_003c9cd0(arg0, -1);
    OP_S16(work, 8) = arg1;
    OP_U32(work, 4) = arg0;
    OP_U32(work, 0) |= 8;
    OP_U32(work, 0) |= 1;
}
// FUN_00276a80
void func_00276a80(void)
{
    u8 *work;
    OP_MATCH_ASSERT(gOpWorkCC != NULL, 0x25);
    work = OP_WORKC;
    OP_MATCH_ASSERT(OP_U32(work, 0) & 1, 0x59);
    func_003c9d00(OP_U32(work, 4), 0x10);
    OP_U32(work, 0) |= 4;
}
// FUN_00276b10
void func_00276b10(void)
{
    u8 *work;
    OP_MATCH_ASSERT(gOpWorkCC != NULL, 0x25);
    work = OP_WORKC;
    OP_MATCH_ASSERT(OP_U32(work, 0) & 1, 0x62);
    func_003c9d00(OP_U32(work, 4), 8);
    OP_U32(work, 0) &= ~4u;
}
// FUN_00276ba0
void func_00276ba0(void)
{
    u8 *work;
    OP_MATCH_ASSERT(gOpWorkCC != NULL, 0x25);
    work = OP_WORKC;
    OP_MATCH_ASSERT(OP_U32(work, 0) & 1, 0x6b);
    func_003c9d00(OP_U32(work, 4), 2);
    OP_U32(work, 0) |= 2;
}
// FUN_00276c30
void func_00276c30(void)
{
    u8 *work;
    OP_MATCH_ASSERT(gOpWorkCC != NULL, 0x25);
    work = OP_WORKC;
    OP_MATCH_ASSERT(OP_U32(work, 0) & 1, 0x74);
    func_003c9d80(OP_U32(work, 4), 2);
    OP_U32(work, 0) &= ~2u;
}


// FUN_00276cc0
u32 func_00276cc0(void)
{
    OP_MATCH_ASSERT(gOpWorkCC != NULL, 0x25);
    return *gOpWorkCC & 8;
}

// FUN_00276D10
void func_00276d10(u32 *work)
{
    work[0] = 0;
    work[0x3730 / 4] = 0;
    work[0x3734 / 4] = 0;
    work[0x3738 / 4] = 0;
    gOpWorkD0 = work;
}

// FUN_00276d30
void func_00276d30(void)
{
    OP_MATCH_ASSERT(gOpWorkD0 != NULL, 0x61);
    if ((*gOpWorkD0 & 1) != 0)
        func_00277070();
    gOpWorkD0 = NULL;
}

// FUN_00276d90 NONMATCHING
void func_00276d90(void)
{
    u8 *work;
    u32 res8;
    u32 res10;
    u32 res1;
    s32 i;
    f32 layout[4];
    u8 color[4] = {0xff, 0xff, 0xff, 0xff};
    K_ASSERT(gOpWorkD0 != NULL, 0x61);
    work = OP_WORKD;
    res8 = func_00119a60(8);
    res10 = func_00119a60(10);
    res1 = brRes00234630(1);
    K_ASSERT((*gOpWorkD0 & 1) == 0, 0x84);
    func_0025f5d0(work + 0xb4c, res1, 0x15);
    func_0025fc50(work + 0xb8c, res1, 0x15, 1);
    func_0025f5d0(work + 0xbcc, res1, 0x17);
    func_0021d3b0(work + 0xe58, func_0021cca0(res1, 1));
    func_0021d3b0(work + 0xe98, func_0021cca0(res1, 0));
    func_0021d3b0(work + 0xedc, func_0021cca0(res1, 0));
    for (i = 0; i < 5; i++)
    {
        u8 *entry = work + i * 0x1c8;
        func_0025f5d0(entry + 0x32c, res8, 0x14);
        func_0025fc50(entry + 0x36c, res8, 0x14, 1);
        func_0025f5d0(entry + 0x3ac, res8, 0x15);
        func_00238980(entry + 0x228, 2, OP_U32(entry, 0x224), 2);
        func_0025f5d0(entry + 0x2ac, res8, 0x18);
        func_0025f5d0(entry + 0x2ec, res8, 0x1b);
    }
    for (i = 0; i < 8; i++)
        func_0025f5d0(work + i * 0x44 + 4, res1, 0x12);
    func_0025f5d0(work + 0xb0c, res1, 0x13);
    for (i = 0; i < 7; i++)
        func_0025f5d0(work + i * 0x40 + 0xc0c, res1, 0x14);
    layout[0] = 526.0f;
    layout[1] = 328.0f;
    func_00238dc0(work + 0xdd4, 2, OP_U32(work, 0x3734), 2, layout);
    func_0021d950(work + 0xdd4, color);
    func_0021d950(work + 0xe14, color);
    func_002771f0();
    *gOpWorkD0 &= ~0x40u;
    *gOpWorkD0 |= 1;
}

// FUN_00277070
void func_00277070(void)
{
    u8 *work;
    OP_MATCH_ASSERT(gOpWorkD0 != NULL, 0x61);
    work = OP_WORKD;
    if (OP_U32(work, 0x3738) != 0)
        func_00279120();
    if ((OP_U32(work, 0) & 2) != 0)
        func_002792c0();
    OP_U32(work, 0) &= ~1u;
}

// FUN_002770f0
void func_002770f0(void)
{
    u32 *work;
    u32 flags;
    OP_MATCH_ASSERT(gOpWorkD0 != NULL, 0x61);
    work = (u32 *)OP_WORKD;
    flags = work[0];
    if ((~flags & 1) != 0)
        return;
    if ((flags & 4) != 0)
    {
        if (((s32 *)work)[0x373c / 4] < 0x14)
            work[0x373c / 4]++;
        else
        {
            work[0] &= ~8u;
            work[0] &= ~4u;
        }
    }
    ((s32 *)work)[0x3740 / 4]++;
    ((s32 *)work)[0x3740 / 4] %= 10;
    if ((work[0] & 0x10) != 0)
    {
        if (((s32 *)work)[0x3744 / 4] < 0x1e)
            work[0x3744 / 4]++;
        else
            work[0] &= ~0x10u;
    }
    func_002771f0();
}

// FUN_002771f0 NONMATCHING
void func_002771f0(void)
{
    u32 *work;
    u32 *work32;
    u32 tex8;
    u32 tex10;
    u32 tex1;
    s32 i;
    f32 layout[4];
    u8 color[4];
    f32 alpha;
    K_ASSERT(gOpWorkD0 != NULL, 0x61);
    work = (u32 *)OP_WORKD;
    work32 = work;
    tex8 = func_00119a60(8);
    tex10 = func_00119a60(10);
    tex1 = brRes00234630(1);
    layout[0] = 411.0f;
    layout[1] = 326.0f;
    layout[2] = (f32)opTexW(tex8, 0x15);
    layout[3] = (f32)opTexH(tex8, 0x15);
    func_0021d8e0(work + 0xb4c, layout);
    layout[0] = (f32)opTexW(tex8, 0x15) + 411.0f;
    layout[1] = 326.0f;
    layout[2] = 31.0f;
    layout[3] = (f32)opTexH(tex8, 0x15);
    func_0021d8e0(work + 0xb8c, layout);
    layout[0] = 557.0f;
    layout[1] = 326.0f;
    layout[2] = (f32)opTexW(tex8, 0x17);
    layout[3] = (f32)opTexH(tex8, 0x17);
    func_0021d8e0(work + 0xbcc, layout);
    color[0] = color[1] = color[2] = color[3] = 0xff;
    func_0021d950(work + 0xb4c, color);
    func_0021d950(work + 0xb8c, color);
    func_0021d950(work + 0xbcc, color);
    for (i = 0; i < 8; i++)
    {
        layout[0] = (f32)(i / 4) * 190.0f + 34.0f;
        layout[1] = (f32)(i % 4) * 24.0f + 316.0f;
        layout[2] = (f32)opTexW(tex8, 0x12);
        layout[3] = (f32)opTexH(tex8, 0x12);
        func_0021d8e0(work + i * 0x44 + 4, layout);
        func_0021d950(work + i * 0x44 + 4, color);
    }
    color[0] = 0xc7;
    color[1] = 0xb9;
    color[2] = 0xff;
    color[3] = 0xff;
    for (i = 0; i < (s32)work32[0xdce]; i++)
    {
        s32 x = (i / 4) * 190 + 44;
        s32 y = (i % 4) * 24 + 315 - (s32)DAT_007cad74;
        func_003b0d70(work32[i * 0x44 / 4 + 0x44], x * 16, y * 8);
        func_003b0e20(work32[i * 0x44 / 4 + 0x44],
                      (u32)color[3] | ((u32)color[2] << 8) |
                      ((u32)color[1] << 16) | ((u32)color[0] << 24));
    }
    if ((work32[0] & 2) != 0)
    {
        if ((work32[0] & 0x10) == 0)
            alpha = 0.0f;
        else if ((s32)work32[0xdd1] < 5)
            alpha = 0.0f;
        else if ((s32)work32[0xdd1] < 10)
            alpha = (f32)(work32[0xdd1] - 5) / 5.0f;
        else if ((s32)work32[0xdd1] < 0x14)
            alpha = 1.0f;
        else if ((s32)work32[0xdd1] < 0x1e)
            alpha = 1.0f - (f32)(work32[0xdd1] - 0x14) / 10.0f;
        else
            alpha = 0.0f;
        func_003b0d70(work32[0xe54], 0x1a80, 0xa90);
        color[0] = opClampByte(alpha * 199.0f + 199.0f);
        color[1] = opClampByte(alpha * 70.0f + 185.0f);
        color[2] = opClampByte(alpha * -95.0f + 255.0f);
        color[3] = 0xff;
        func_003b0e20(work32[0xe54], (u32)color[3] | ((u32)color[2] << 8) |
                      ((u32)color[1] << 16) | ((u32)color[0] << 24));
        layout[0] = 414.0f;
        layout[1] = 343.0f;
        layout[2] = (f32)opTexW(tex8, 0x13);
        layout[3] = (f32)opTexH(tex8, 0x13);
        func_0021d8e0(work + 0xb0c, layout);
        func_0021d950(work + 0xb0c, (u8[4]){0xff, 0xff, 0xff, 0xff});
    }
    for (i = 0; i < (s32)work32[0xdcc]; i++)
    {
        u8 *entry = (u8 *)(uintptr_t)(work + i * 0x1c8);
        layout[0] = (f32)(i / 2) * 62.0f + 414.0f;
        layout[1] = (f32)(i % 2) * 24.0f + 366.0f;
        layout[2] = (f32)opTexW(tex8, 0x14);
        layout[3] = (f32)opTexH(tex8, 0x14);
        func_0021d8e0(entry + 0xc0c, layout);
        func_0021d950(entry + 0xc0c, color);
        layout[0] = 104.0f;
        layout[1] = (f32)i * 19.0f + 104.0f;
        layout[2] = (f32)opTexW(tex10, 0x14);
        layout[3] = DAT_007caf8c + (f32)opTexH(tex10, 0x14);
        func_0021d8e0(entry + 0x32c, layout);
        layout[0] = (f32)opTexW(tex10, 0x14) + 104.0f;
        layout[2] = 220.0f;
        func_0021d8e0(entry + 0x36c, layout);
        func_0021d950(entry + 0x32c, color);
        func_0021d950(entry + 0x36c, color);
        layout[0] = DAT_007cb04c;
        layout[2] = (f32)opTexW(tex10, 0x15);
        func_0021d8e0(entry + 0x3ac, layout);
        func_0021d950(entry + 0x3ac, color);
        layout[0] = 69.0f;
        layout[1] = (f32)i * 19.0f + 106.0f;
        func_00238dc0(entry + 0x228, 2, OP_U32(entry, 0x224), 2, layout);
        func_0021d950(entry + 0x22c, color);
        layout[0] = 108.0f;
        layout[1] = (f32)i * 19.0f + 105.0f;
        layout[2] = (f32)opTexH(tex10, 0x18);
        func_0021d8e0(entry + 0x2ac, layout);
        func_0021eac0(entry + 0x2ac, 0x477fff00);
        func_0021d950(entry + 0x2ac, color);
        layout[0] = 108.0f;
        layout[2] = (f32)opTexH(tex10, 0x1b);
        func_0021d8e0(entry + 0x2ec, layout);
        func_0021d950(entry + 0x2ec, color);
    }
    layout[0] = (f32)work32[0xed8] * 190.0f + 25.0f;
    layout[1] = (f32)work32[0xed9] * 24.0f + 309.0f;
    tex1 = func_0021cca0(tex1, 0);
    layout[2] = (f32)OP_S32((void *)(uintptr_t)tex1, 0xc);
    layout[3] = (f32)OP_S32((void *)(uintptr_t)tex1, 0x10);
    func_0021d8e0(work + 0xedc, layout);
    func_0021d950(work + 0xedc, color);
}

// FUN_00278550 NONMATCHING
void func_00278550(void)
{
    u8 *work;
    u32 tex8;
    u32 tex10;
    u32 tex1;
    u32 frame;
    s32 i;
    s32 j;
    u8 vertices[0x100];
    f32 rect[4];
    OP_MATCH_ASSERT(gOpWorkD0 != NULL, 0x61);
    work = OP_WORKD;
    tex8 = func_00119a60(8);
    tex10 = func_00119a60(10);
    tex1 = brRes00234630(1);
    if ((*gOpWorkD0 & 1) == 0 || (*gOpWorkD0 & 0x40) != 0)
        return;
    D_00960090(0x14, 2);
    D_00960090(8, 0);
    D_00960090(6, 0);
    D_00960090(9, 2);
    D_00960090(0xe, 0);
    D_00960090(7, 2);
    D_00960090(0xc, 1);
    if ((*gOpWorkD0 & 0x20) != 0)
    {
        frame = func_0021cca0(tex1, 2);
        func_0021d3b0(vertices, frame);
        rect[0] = 302.0f;
        rect[1] = 225.0f;
        rect[2] = (f32)OP_S32((void *)(uintptr_t)frame, 0xc);
        rect[3] = (f32)OP_S32((void *)(uintptr_t)frame, 0x10);
        func_0021d8e0(vertices, rect);
        D_00960090(1, func_0021cce0(frame));
        D_0096009C(vertices, 4, 0, 1, 2);
        D_0096009C(vertices, 4, 0, 2, 3);
    }
    for (i = 0; i < 8; i++)
    {
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        frame = opTexFrame(tex8, 0x12);
        D_00960090(1, frame);
        D_0096009C(work + (7 - i) * 0x44 + 4, 4, 0, 1, 2);
        D_0096009C(work + (7 - i) * 0x44 + 4, 4, 0, 2, 3);
    }
    for (i = 0; i < (s32)gOpWorkD0[0xdce]; i++)
        func_003b1360(gOpWorkD0[i * 0x44 / 4 + 0x44], 1, 0);
    if ((*gOpWorkD0 & 2) != 0)
    {
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        frame = opTexFrame(tex8, 0x15);
        D_00960090(1, frame);
        D_0096009C(work + 0xb4c, 4, 0, 1, 2);
        D_0096009C(work + 0xb4c, 4, 0, 2, 3);
        D_0096009C(work + 0xb8c, 4, 0, 1, 2);
        D_0096009C(work + 0xb8c, 4, 0, 2, 3);
        frame = opTexFrame(tex8, 0x17);
        D_00960090(1, frame);
        D_0096009C(work + 0xbcc, 4, 0, 1, 2);
        D_0096009C(work + 0xbcc, 4, 0, 2, 3);
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        frame = opTexFrame(tex8, 0x13);
        D_00960090(1, frame);
        D_0096009C(work + 0xb0c, 4, 0, 1, 2);
        D_0096009C(work + 0xb0c, 4, 0, 2, 3);
        D_00960090(1, func_0021cce0(func_0021cca0(tex1, 1)));
        D_0096009C(work + 0xe58, 4, 0, 1, 2);
        D_0096009C(work + 0xe58, 4, 0, 2, 3);
        D_00960090(1, func_0021cce0(func_0021cca0(tex1, 0)));
        D_0096009C(work + 0xe98, 4, 0, 1, 2);
        D_0096009C(work + 0xe98, 4, 0, 2, 3);
        func_003b1360(gOpWorkD0[0xe54], 1, 0);
        for (i = 0; i < (s32)gOpWorkD0[0xdcc]; i++)
        {
            func_004d7f60(3, 0x717fb);
            func_004d7f60(2, 0x44);
            frame = opTexFrame(tex8, 0x14);
            D_00960090(1, frame);
            D_0096009C(work + i * 0x40 + 0xc0c, 4, 0, 1, 2);
            D_0096009C(work + i * 0x40 + 0xc0c, 4, 0, 2, 3);
        }
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        D_00960090(1, func_00239140(2));
        for (i = 0; i < 2; i++)
        {
            D_0096009C(work + i * 0x40 + 0xdd4, 4, 0, 1, 2);
            D_0096009C(work + i * 0x40 + 0xdd4, 4, 0, 2, 3);
        }
    }
    for (i = 0; i < 5; i++)
    {
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        frame = opTexFrame(tex10, 0x14);
        D_00960090(1, frame);
        D_0096009C(work + i * 0x1c8 + 0x32c, 4, 0, 1, 2);
        D_0096009C(work + i * 0x1c8 + 0x32c, 4, 0, 2, 3);
        D_0096009C(work + i * 0x1c8 + 0x36c, 4, 0, 1, 2);
        D_0096009C(work + i * 0x1c8 + 0x36c, 4, 0, 2, 3);
        frame = opTexFrame(tex10, 0x15);
        D_00960090(1, frame);
        D_0096009C(work + i * 0x1c8 + 0x3ac, 4, 0, 1, 2);
        D_0096009C(work + i * 0x1c8 + 0x3ac, 4, 0, 2, 3);
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        D_00960090(1, func_00239140(2));
        for (j = 0; j < 2; j++)
        {
            D_0096009C(work + i * 0x1c8 + j * 0x40 + 0x228, 4, 0, 1, 2);
            D_0096009C(work + i * 0x1c8 + j * 0x40 + 0x228, 4, 0, 2, 3);
        }
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        D_00960090(1, opTexFrame(tex10, 0x18));
        D_0096009C(work + i * 0x1c8 + 0x2ac, 4, 0, 1, 2);
        D_0096009C(work + i * 0x1c8 + 0x2ac, 4, 0, 2, 3);
        if ((*gOpWorkD0 & 8) != 0)
        {
            func_004d7f60(3, 0x717fb);
            func_004d7f60(2, 0x44);
            D_00960090(1, opTexFrame(tex10, 0x1b));
            D_0096009C(work + i * 0x1c8 + 0x2ec, 4, 0, 1, 2);
            D_0096009C(work + i * 0x1c8 + 0x2ec, 4, 0, 2, 3);
        }
    }
    if ((*gOpWorkD0 & 0x20) != 0)
    {
        if (DAT_007cc4dc != -1)
            func_003c7e20(0, 0x13c, 0x100, (u64)-1, 1, 6, 3);
        D_00960090(1, func_0021cce0(func_0021cca0(tex1, 0)));
        func_004d7f60(3, 0x71801);
        func_004d7f60(2, 0x48);
        D_0096009C(work + 0xedc, 4, 0, 1, 2);
        D_0096009C(work + 0xedc, 4, 0, 2, 3);
    }
}
