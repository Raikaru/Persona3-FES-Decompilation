#include "Main/OpEd/op_fade_mid.h"
#include "Main/Battle/Result/br_res.h"

/* Retail helpers used by the opening/ending result state. */
extern u32 D_00960178[];
extern void (*D_0096017C)(void *memory);
extern void (*D_00960090)(u32 state, u32 value);
extern void (*D_0096009C)(void *vertices, u32 primitive, u32 offset,
                          u32 first, u32 second);
extern void *D_00960070;
extern u8 *DAT_007ce420;
extern s32 DAT_007cc4dc;
extern f32 DAT_007cad74;
extern f32 DAT_007caf38;
extern f32 DAT_007caf8c;
extern f32 DAT_007cafec;
extern f32 DAT_007cb04c;

extern void *FUN_00173220(u16 id);
extern u16 *datPersonaGetSkills(void *persona);
extern u8 datPersonaGetTotalStat(void *persona, u16 stat);
extern u16 datPersonaCountValidSkills(void *persona);
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
extern void brpParam00279450(u32 value);
extern void brpParam002794c0(u32 value);
extern void func_00279510(s32 index, u32 value);
extern void func_00279580(s32 index, u32 value);
extern void func_002795f0(s32 index, u32 value);
extern void func_003b0170(u32 resource);
extern u32 func_003b0d70(u32 resource, s32 x, s32 y);
extern void func_003b0e54(u32 resource, u32 color);
extern void func_003b0e70(s32 mode);
extern void func_003b0e90(s32 mode);
extern u32 func_003b1360(u32 resource, s32 visible, s32 flags);
extern void func_003c7430(s32 value);
extern void func_003c7bc0(s32 channel, u32 value);
extern void func_003c7e20(s32 mode, s32 x, s32 y, u64 value, s32 a,
                           s32 b, s32 c);
extern u32 func_003c9ab0(u32 resource);
extern void func_003c9ba0(u64 stream, u32 resource);
extern void func_003c9cd0(u32 resource, s32 value);
extern void func_003c9d00(u32 resource, s32 value);
extern void func_003c9d80(u32 resource, s32 value);
extern void func_004d7f60(s32 state, u32 value);
extern void func_00521250(void *destination, const void *source, u32 size);
extern void func_005225a8(const void *message, ...);
extern void brLvpnl002767e0(void);
extern void brLvpnl00276870(void);
extern void brLvpnl002768c0(void);
static u32 opTexW(u32 resource, s32 frame)
{
    return (u32)sflPsel00260900((u32 *)(uintptr_t)resource, frame);
}

static u32 opTexH(u32 resource, s32 frame)
{
    return (u32)sflPsel00260920((u32 *)(uintptr_t)resource, frame);
}

static u32 opTexFrame(u32 resource, s32 frame)
{
    return sflPsel00260940((u32 *)(uintptr_t)resource, frame);
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

static u8 opClampByte(f32 value)
{
    if (value <= 0.0f)
        return 0;
    if (value >= 255.0f)
        return 0xff;
    return (u8)value;
}


// FUN_00275050 NONMATCHING
void func_00275050(s32 index)
{
    u8 *work;
    u16 *skills;
    s32 skillCount;
    s32 i;
    s32 found;
    s32 slot;
    s8 kind;

    K_ASSERT(gOpWorkC0 != NULL, 0xb0);
    work = OP_WORK0;
    skills = datPersonaGetSkills(OP_PTR(work, 0x30));
    skillCount = (s32)datPersonaCountValidSkills(OP_PTR(work, 0x30));
    K_ASSERT(OP_S32(work, 0x1c0) > index, 0x638);
    slot = 0;
    for (i = 0; ; )
    {
        s32 entry = OP_S32(work, 0x34) + (OP_S32(work, 0x78) + i) * 4;
        kind = OP_S8((void *)(uintptr_t)entry, 7);
        if (kind == 4)
        {
            i++;
            K_ASSERT(OP_S32(work, 0x78) + i <= 0xf, 0x65b);
            continue;
        }
        if (kind != 1)
            K_ABORT((const char *)0x68ed88, 0x644);
        for (found = 0; found < skillCount; found++)
        {
            if (OP_S16((void *)(uintptr_t)entry, 8) == (s16)skills[found])
                break;
        }
        if (found == skillCount)
        {
            if (slot == index)
                return;
            slot++;
        }
        i++;
        K_ASSERT(OP_S32(work, 0x78) + i <= 0xf, 0x65b);
    }
}

// FUN_002751e0 NONMATCHING
s32 func_002751e0(void)
{
    u8 *work;
    u16 *skills;
    s32 skillCount;
    s32 i;
    s32 result;
    u8 baseLevel;
    u8 currentLevel;
    u8 adjustment;

    K_ASSERT(gOpWorkC0 != NULL, 0xb0);
    work = OP_WORK0;
    skills = datPersonaGetSkills(OP_PTR(work, 0x30));
    skillCount = (s32)datPersonaCountValidSkills(OP_PTR(work, 0x30));
    baseLevel = *((u8 *)DAT_007ce420 + OP_U16(OP_PTR(work, 0x30), 2) * 0xe + 3);
    currentLevel = OP_U8(OP_PTR(work, 0x30), 4);
    adjustment = OP_U8(work, 0x38);
    result = 0;
    for (i = 0; OP_S32(work, 0x78) + i != 0x10; i++)
    {
        s32 entry = OP_S32(work, 0x34) + (OP_S32(work, 0x78) + i) * 4;
        s8 kind = OP_S8((void *)(uintptr_t)entry, 7);
        if (kind == 0)
            return result;
        if (kind == 1 && (s32)((u32)currentLevel - baseLevel - adjustment) < OP_U8((void *)(uintptr_t)entry, 6))
        {
            s32 found;
            for (found = 0; found < skillCount; found++)
            {
                if (OP_S16((void *)(uintptr_t)entry, 8) == (s16)skills[found])
                    break;
            }
            if (found == skillCount)
                result++;
        }
        else if (kind != 4)
            K_ABORT((const char *)0x68ed88, 0x686);
    }
    return result;
}

// FUN_00275370 NONMATCHING
u32 func_00275370(void)
{
    K_ASSERT(gOpWorkC0 != NULL, 0xb0);
    return *gOpWorkC0 & 0x100;
}

// FUN_002753c0 NONMATCHING
void func_002753c0(void)
{
    u8 *work;
    K_ASSERT(gOpWorkC0 != NULL, 0xb0);
    work = OP_WORK0;
    brLvpnl002767e0();
    func_003c7bc0(0, (u32)(uintptr_t)FUN_00173220(OP_U16(work, 4)));
    func_003c7430(0);
    OP_U32(work, 0x14) = 0;
    OP_U32(work, 0x10) = 1;
}

// FUN_00275440 NONMATCHING
void func_00275440(void)
{
    u8 *work = (u8 *)OP_ALLOC(0x4510, 0x40000);
    OP_U32(work, 0x4500) = 0;
    func_00272330(work);
    brRes00233970((u32 *)(work + 0x210));
    func_00275a70((u32 *)(work + 0x260));
    func_00276910((u32 *)(work + 0x880));
    func_00276d10((u32 *)(work + 0x890));
    OP_U32(work, 0x4504) = func_00194b80(NULL, 10, (const void *)0x68eeb8,
                                           (void *)func_002756c0, NULL, NULL);
    OP_U32(work, 0x4508) = func_00194e10((const void *)0x68eed0, 0x18ab,
                                           1, 2, (void *)func_002757a0, NULL, 0);
    gOpWorkC4 = (u32 *)work;
}

// FUN_00275520 NONMATCHING
void func_00275520(void)
{
    u8 *work;
    K_ASSERT(gOpWorkC4 != NULL, 0x46);
    work = OP_WORK4;
    func_00276c30();
    func_00272380();
    brRes00233e70();
    func_00275a80();
    func_00276920();
    func_00276d30();
    func_00195020(OP_U32(work, 0x4504));
    func_00195020(OP_U32(work, 0x4508));
    if (D_0096017C != NULL)
        D_0096017C(work);
    gOpWorkC4 = NULL;
}

// FUN_002755d0 NONMATCHING
void func_002755d0(u64 value)
{
    u8 *work;
    K_ASSERT(gOpWorkC4 != NULL, 0x46);
    work = OP_WORK4;
    func_00275a90();
    func_00277070();
    func_00272400(value);
    func_00276d90();
    func_0010a370(3, (const char *)0x68eef0);
    OP_U32(work, 0x4500) |= 2;
    OP_U32(work, 0x4500) |= 1;
}

// FUN_00275670 NONMATCHING
u32 func_00275670(void)
{
    K_ASSERT(gOpWorkC4 != NULL, 0x46);
    return OP_U32(OP_WORK4, 0x4500) & 1;
}

// FUN_002756c0 NONMATCHING
u64 func_002756c0(void)
{
    u8 *work;
    K_ASSERT(gOpWorkC4 != NULL, 0x46);
    work = OP_WORK4;
    brRes00234070();
    func_00275bc0();
    func_00272810();
    func_00276930();
    func_002770f0();
    if ((OP_U32(work, 0x4500) & 2) != 0 && func_00275370() == 0)
    {
        func_002753c0();
        OP_U32(work, 0x4500) &= ~2u;
    }
    if ((OP_U32(work, 0x4500) & 1) != 0 && func_002727c0() == 0)
        OP_U32(work, 0x4500) &= ~1u;
    return 0;
}

// FUN_002757a0 NONMATCHING
u64 func_002757a0(void)
{
    func_005225a8((const void *)0x7cc4d8, D_00960070);
    func_00275cb0();
    func_00278550();
    return 0;
}

// FUN_002757e0 NONMATCHING
void func_002757e0(void *resource)
{
    u8 *data = (u8 *)resource;
    s32 i;
    K_ASSERT(OP_S16(data, 4) == 3, 0xc9);
    for (i = 0; i < 3; i++)
    {
        if (i == 2)
            brRes00234690(1, data + OP_S32(data, 0x18));
        else if (i == 1)
            brRes00234690(0, data + OP_S32(data, 0x10));
        else
            brRes00234710(data + OP_S32(data, 8), OP_U32(data, 0xc));
    }
}

// FUN_002758e0 NONMATCHING
void func_002758e0(u64 arg0, u64 arg1)
{
    u16 skills[14];
    s32 count;
    void *persona;
    s32 i;
    K_ASSERT(gOpWorkCC != NULL, 0x25);
    func_002769c0(arg0, arg1);
    func_00276ba0();
    persona = FUN_001749a0((u16)arg1);
    count = (s32)datPersonaCountValidSkills(persona);
    for (i = 0; i < count; i++)
        func_002791b0(*(u16 *)((u8 *)datPersonaGetSkills(persona) + i * 2));
    func_001fb1f0(persona, skills, &count);
    if (func_001fc230(persona) != 0)
    {
        func_00279330(skills[0]);
        brpParam00279450(func_001fc3c0(persona));
    }
    brpParam002794c0(count < 2 ? 0 : (u32)(count - 1));
    for (i = 0; i < 5; i++)
    {
        u8 stat = datPersonaGetTotalStat(persona, (u16)i);
        func_00279510(i, stat);
        func_00279580(i, stat);
        func_002795f0(i, 0);
    }
    func_00276d90();
}

// FUN_00275a70 NONMATCHING
void func_00275a70(u32 *work)
{
    *work = 0;
    gOpWorkC8 = work;
}

// FUN_00275a80 NONMATCHING
void func_00275a80(void)
{
    gOpWorkC8 = NULL;
}

// FUN_00275a90 NONMATCHING
void func_00275a90(void)
{
    u8 *work;
    u32 resource;
    K_ASSERT(gOpWorkC8 != NULL, 0x3b);
    work = OP_WORK8;
    resource = brRes00234630(0);
    func_0021d3b0(work + 4, func_0021cca0(resource, 0));
    func_0021d3b0(work + 0x44, func_0021cca0(resource, 2));
    func_0021d3b0(work + 0x84, func_0021cca0(resource, 1));
    func_0021d3b0(work + 0xc4, func_0021cca0(resource, 3));
    resource = func_0021cca0(resource, 0xb);
    func_0021d3b0(work + 0x104, resource);
    func_0021e380(work + 0x144, resource, 1);
    func_002760f0();
    *gOpWorkC8 |= 1;
}

// FUN_00275bc0 NONMATCHING
void func_00275bc0(void)
{
    u32 flags;
    K_ASSERT(gOpWorkC8 != NULL, 0x3b);
    flags = *gOpWorkC8;
    if ((flags & 1) == 0)
        return;
    if ((flags & 2) != 0)
    {
        if (gOpWorkC8[0x185] == 1)
        {
            if ((s32)gOpWorkC8[0x184] < 0x21)
                gOpWorkC8[0x184]++;
            else
                *gOpWorkC8 &= ~2u;
        }
        else if (gOpWorkC8[0x185] == 0)
        {
            if ((s32)gOpWorkC8[0x184] < 0x24)
                gOpWorkC8[0x184]++;
            else
                *gOpWorkC8 &= ~2u;
        }
    }
    func_002760f0();
}

// FUN_00275cb0 NONMATCHING
void func_00275cb0(void)
{
    u8 *work;
    u32 resource;
    K_ASSERT(gOpWorkC8 != NULL, 0x3b);
    work = OP_WORK8;
    resource = brRes00234630(0);
    if ((*gOpWorkC8 & 1) == 0 || (*gOpWorkC8 & 8) != 0)
        return;
    D_00960090(8, 0);
    D_00960090(6, 0);
    D_00960090(9, 2);
    D_00960090(9, 1);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    resource = func_0021cce0(func_0021cca0(resource, 0xb));
    D_00960090(1, resource);
    D_0096009C(work + 0x104, 4, 0, 1, 2);
    D_0096009C(work + 0x104, 4, 0, 2, 3);
    D_0096009C(work + 0x144, 4, 0, 1, 2);
    D_0096009C(work + 0x144, 4, 0, 2, 3);
    D_00960090(9, 2);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    resource = func_0021cce0(func_0021cca0(brRes00234630(0), 0));
    D_00960090(1, resource);
    D_0096009C(work + 4, 4, 0, 1, 2);
    D_0096009C(work + 4, 4, 0, 2, 3);
    func_004d7f60(3, 0x71801);
    func_004d7f60(2, 0x48);
    resource = func_0021cce0(func_0021cca0(brRes00234630(0), 2));
    D_00960090(1, resource);
    D_0096009C(work + 0x44, 4, 0, 1, 2);
    D_0096009C(work + 0x44, 4, 0, 2, 3);
    D_00960090(9, 2);
    func_004d7f60(3, 0x717fb);
    func_004d7f60(2, 0x44);
    resource = func_0021cce0(func_0021cca0(brRes00234630(0), 1));
    D_00960090(1, resource);
    D_0096009C(work + 0x84, 4, 0, 1, 2);
    D_0096009C(work + 0x84, 4, 0, 2, 3);
    func_004d7f60(3, 0x71801);
    func_004d7f60(2, 0x48);
    resource = func_0021cce0(func_0021cca0(brRes00234630(0), 3));
    D_00960090(1, resource);
    D_0096009C(work + 0xc4, 4, 0, 1, 2);
    D_0096009C(work + 0xc4, 4, 0, 2, 3);
}

// FUN_002760f0 NONMATCHING
void func_002760f0(void)
{
    u8 *work;
    f32 rect[4];
    u8 color[4];
    f32 alpha;
    f32 offset;
    u32 resource;
    K_ASSERT(gOpWorkC8 != NULL, 0x3b);
    work = OP_WORK8;
    resource = brRes00234630(0);
    alpha = 0.0f;
    offset = 0.0f;
    if ((*gOpWorkC8 & 2) == 0)
        alpha = (*gOpWorkC8 & 4) != 0 ? 1.0f : 0.0f;
    else if (gOpWorkC8[0x185] == 1)
    {
        alpha = 1.0f;
        offset = 0.0f;
    }
    else if (gOpWorkC8[0x185] == 0)
    {
        if ((s32)gOpWorkC8[0x184] < 0)
            alpha = 0.0f;
        else if ((s32)gOpWorkC8[0x184] < 6)
        {
            alpha = (f32)gOpWorkC8[0x184] / 6.0f;
            offset = (1.0f - alpha) * 100.0f;
        }
        else
            alpha = 1.0f;
    }
    resource = func_0021cca0(resource, 0);
    rect[0] = offset + 128.0f;
    rect[1] = 0.0f;
    rect[2] = (f32)OP_S32((void *)(uintptr_t)resource, 0xc);
    rect[3] = (f32)OP_S32((void *)(uintptr_t)resource, 0x10);
    func_0021d8e0(work + 4, rect);
    color[0] = color[1] = color[2] = 0xff;
    color[3] = opClampByte(alpha * 255.0f);
    func_0021d950(work + 4, color);
    resource = func_0021cca0(brRes00234630(0), 1);
    rect[0] = offset + 359.0f;
    rect[1] = 0.0f;
    rect[2] = (f32)OP_S32((void *)(uintptr_t)resource, 0xc);
    rect[3] = (f32)OP_S32((void *)(uintptr_t)resource, 0x10);
    func_0021d8e0(work + 0x84, rect);
    color[3] = opClampByte(alpha * 255.0f);
    func_0021d950(work + 0x84, color);
    if ((*gOpWorkC8 & 2) == 0)
        alpha = 0.0f;
    else if (gOpWorkC8[0x185] == 1)
    {
        s32 frame = (s32)gOpWorkC8[0x184];
        alpha = frame < 0 ? 0.0f : frame < 3 ? (f32)frame / 3.0f
                                             : frame < 0x21 ? 1.0f - (f32)(frame - 3) / 30.0f : 0.0f;
    }
    else
    {
        s32 frame = (s32)gOpWorkC8[0x184];
        alpha = frame < 3 ? 0.0f : frame < 6 ? (f32)(frame - 3) / 3.0f
                                             : frame < 0x24 ? 1.0f - (f32)(frame - 6) / 30.0f : 0.0f;
    }
    resource = func_0021cca0(brRes00234630(0), 2);
    rect[0] = 128.0f;
    rect[1] = 0.0f;
    rect[2] = (f32)OP_S32((void *)(uintptr_t)resource, 0xc);
    rect[3] = (f32)OP_S32((void *)(uintptr_t)resource, 0x10);
    func_0021d8e0(work + 0x44, rect);
    color[3] = opClampByte(alpha * 255.0f);
    func_0021d950(work + 0x44, color);
    resource = func_0021cca0(brRes00234630(0), 3);
    rect[0] = 359.0f;
    rect[1] = 0.0f;
    rect[2] = (f32)OP_S32((void *)(uintptr_t)resource, 0xc);
    rect[3] = (f32)OP_S32((void *)(uintptr_t)resource, 0x10);
    func_0021d8e0(work + 0xc4, rect);
    func_0021d950(work + 0xc4, color);
    resource = func_0021cca0(brRes00234630(0), 0xb);
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

// FUN_00276910 NONMATCHING
void func_00276910(u32 *work)
{
    *work = 0;
    gOpWorkCC = work;
}

// FUN_00276920 NONMATCHING
void func_00276920(void)
{
    gOpWorkCC = NULL;
}

// FUN_00276930 NONMATCHING
void func_00276930(void)
{
    K_ASSERT(gOpWorkCC != NULL, 0x25);
    if ((*gOpWorkCC & 1) != 0 && (*gOpWorkCC & 8) != 0 && func_003c9ab0(gOpWorkCC[1]) != 0)
        *gOpWorkCC &= ~8u;
}

// FUN_002769c0 NONMATCHING
void func_002769c0(u64 arg0, u64 arg1)
{
    K_ASSERT(gOpWorkCC != NULL, 0x25);
    func_003c9ba0(arg0, (u32)(uintptr_t)FUN_001749a0((u16)arg1));
    func_003c9d00((u32)arg0, 8);
    func_003c9cd0((u32)arg0, -1);
    OP_S16(OP_WORKC, 8) = (s16)arg1;
    OP_U32(OP_WORKC, 4) = (u32)arg0;
    *gOpWorkCC |= 8;
    *gOpWorkCC |= 1;
}

// FUN_00276a80 NONMATCHING
void func_00276a80(void)
{
    K_ASSERT(gOpWorkCC != NULL, 0x25);
    K_ASSERT((*gOpWorkCC & 1) != 0, 0x59);
    func_003c9d00(gOpWorkCC[1], 0x10);
    *gOpWorkCC |= 4;
}

// FUN_00276b10 NONMATCHING
void func_00276b10(void)
{
    K_ASSERT(gOpWorkCC != NULL, 0x25);
    K_ASSERT((*gOpWorkCC & 1) != 0, 0x62);
    func_003c9d00(gOpWorkCC[1], 8);
    *gOpWorkCC &= ~4u;
}

// FUN_00276ba0 NONMATCHING
void func_00276ba0(void)
{
    K_ASSERT(gOpWorkCC != NULL, 0x25);
    K_ASSERT((*gOpWorkCC & 1) != 0, 0x6b);
    func_003c9d00(gOpWorkCC[1], 2);
    *gOpWorkCC |= 2;
}

// FUN_00276c30 NONMATCHING
void func_00276c30(void)
{
    K_ASSERT(gOpWorkCC != NULL, 0x25);
    K_ASSERT((*gOpWorkCC & 1) != 0, 0x74);
    func_003c9d80(gOpWorkCC[1], 2);
    *gOpWorkCC &= ~2u;
}

// FUN_00276cc0 NONMATCHING
u32 func_00276cc0(void)
{
    K_ASSERT(gOpWorkCC != NULL, 0x25);
    return *gOpWorkCC & 8;
}

// FUN_00276d10 NONMATCHING
void func_00276d10(u32 *work)
{
    *work = 0;
    work[0xdcc] = 0;
    work[0xdcd] = 0;
    work[0xdce] = 0;
    gOpWorkD0 = work;
}

// FUN_00276d30 NONMATCHING
void func_00276d30(void)
{
    K_ASSERT(gOpWorkD0 != NULL, 0x61);
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

// FUN_00277070 NONMATCHING
void func_00277070(void)
{
    K_ASSERT(gOpWorkD0 != NULL, 0x61);
    if (gOpWorkD0[0xdce] != 0)
        func_00279120();
    if ((*gOpWorkD0 & 2) != 0)
        func_002792c0();
    *gOpWorkD0 &= ~1u;
}

// FUN_002770f0 NONMATCHING
void func_002770f0(void)
{
    u32 flags;
    K_ASSERT(gOpWorkD0 != NULL, 0x61);
    flags = *gOpWorkD0;
    if ((flags & 1) == 0)
        return;
    if ((flags & 4) != 0)
    {
        if ((s32)gOpWorkD0[0xdcf] < 0x14)
            gOpWorkD0[0xdcf]++;
        else
        {
            *gOpWorkD0 &= ~8u;
            *gOpWorkD0 &= ~4u;
        }
    }
    gOpWorkD0[0xdd0] = (u32)((s32)(gOpWorkD0[0xdd0] + 1) % 10);
    if ((*gOpWorkD0 & 0x10) != 0)
    {
        if ((s32)gOpWorkD0[0xdd1] < 0x1e)
            gOpWorkD0[0xdd1]++;
        else
            *gOpWorkD0 &= ~0x10u;
    }
    func_002771f0();
}

// FUN_002771f0 NONMATCHING
void func_002771f0(void)
{
    u8 *work;
    u32 tex8;
    u32 tex10;
    u32 tex1;
    s32 i;
    f32 layout[4];
    u8 color[4];
    f32 alpha;
    K_ASSERT(gOpWorkD0 != NULL, 0x61);
    work = OP_WORKD;
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
    for (i = 0; i < (s32)gOpWorkD0[0xdce]; i++)
    {
        s32 x = (i / 4) * 190 + 44;
        s32 y = (i % 4) * 24 + 315 - (s32)DAT_007cad74;
        func_003b0d70(gOpWorkD0[i * 0x44 / 4 + 0x44], x * 16, y * 8);
        func_003b0e54(gOpWorkD0[i * 0x44 / 4 + 0x44],
                      (u32)color[3] | ((u32)color[2] << 8) |
                      ((u32)color[1] << 16) | ((u32)color[0] << 24));
    }
    if ((*gOpWorkD0 & 2) != 0)
    {
        if ((*gOpWorkD0 & 0x10) == 0)
            alpha = 0.0f;
        else if ((s32)gOpWorkD0[0xdd1] < 5)
            alpha = 0.0f;
        else if ((s32)gOpWorkD0[0xdd1] < 10)
            alpha = (f32)(gOpWorkD0[0xdd1] - 5) / 5.0f;
        else if ((s32)gOpWorkD0[0xdd1] < 0x14)
            alpha = 1.0f;
        else if ((s32)gOpWorkD0[0xdd1] < 0x1e)
            alpha = 1.0f - (f32)(gOpWorkD0[0xdd1] - 0x14) / 10.0f;
        else
            alpha = 0.0f;
        func_003b0d70(gOpWorkD0[0xe54], 0x1a80, 0xa90);
        color[0] = opClampByte(alpha * 199.0f + 199.0f);
        color[1] = opClampByte(alpha * 70.0f + 185.0f);
        color[2] = opClampByte(alpha * -95.0f + 255.0f);
        color[3] = 0xff;
        func_003b0e54(gOpWorkD0[0xe54], (u32)color[3] | ((u32)color[2] << 8) |
                      ((u32)color[1] << 16) | ((u32)color[0] << 24));
        layout[0] = 414.0f;
        layout[1] = 343.0f;
        layout[2] = (f32)opTexW(tex8, 0x13);
        layout[3] = (f32)opTexH(tex8, 0x13);
        func_0021d8e0(work + 0xb0c, layout);
        func_0021d950(work + 0xb0c, (u8[4]){0xff, 0xff, 0xff, 0xff});
    }
    for (i = 0; i < (s32)gOpWorkD0[0xdcc]; i++)
    {
        u8 *entry = work + i * 0x1c8;
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
    layout[0] = (f32)gOpWorkD0[0xed8] * 190.0f + 25.0f;
    layout[1] = (f32)gOpWorkD0[0xed9] * 24.0f + 309.0f;
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
    K_ASSERT(gOpWorkD0 != NULL, 0x61);
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
