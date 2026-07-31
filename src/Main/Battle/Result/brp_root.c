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
extern f32 sinf(f32 angle);
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
    ((s32)sflPsel00260900((u32 *)(uintptr_t)(resource), (frame)))
#define opTexH(resource, frame) \
    ((s32)sflPsel00260920((u32 *)(uintptr_t)(resource), (frame)))
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


static inline u8 opFadeColorByte(f32 value)
{
    return (u8)(u32)value;
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













typedef struct OpFadeEntry
{
    u32 drawHandle;
    u8 pad_004[0x0c];
    u8 draw[0x210];
    u8 panel18[0x100];
    u8 panel1b[0x100];
    u8 panel14[0x100];
    u8 panel14Alt[0x100];
    u8 panel15[0x100];
} OpFadeEntry;

typedef struct OpFadeWork
{
    u32 flags;
    u8 pad_004[0x0c];
    u8 list12[8][0x110];
    OpFadeEntry entries[5];
    u8 panel13[0x100];
    u8 panel15[0x100];
    u8 panel15Alt[0x100];
    u8 panel17[0x100];
    u8 list14[7][0x100];
    u32 pad_3730;
    u32 drawHandle;
    u32 pad_3738;
    u32 state;
    u32 frame;
    u8 pad_3744[0x0c];
    u8 draw[0x210];
    u8 texture1[0x100];
    u8 texture0[0x110];
    u8 texture0Alt[0x100];
} OpFadeWork;





#define D_00960090 (*state)
#define D_0096009C (*quad)
#undef D_00960090
#undef D_0096009C
