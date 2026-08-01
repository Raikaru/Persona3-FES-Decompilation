#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Result/bp_ifont.h"




typedef struct
{
    u8 unused[0x3730];
    u32 unlockedSkillIndex;
    u32 unlockedSkillLevel;
    u8 unlockedSkillLevelGlyphs[1];
} BrpParamWork;

static BrpParamWork* sBrpParam; // iGpffffb6e0


#include "Utils.h"
#include "Main/OpEd/op_fade_mid.h"
extern u32* DAT_007ce3d0;
#define sOpTailA DAT_007ce3d0
extern u32* DAT_007ce3d4;
#define sOpTailB DAT_007ce3d4
#define sOpTailC DAT_007ce3d8
extern u32* DAT_007ce3dc;
#define sOpTailD DAT_007ce3dc
extern u32* DAT_007ce3e0;
#define sOpTailE DAT_007ce3e0
extern u32 *DAT_007ce3d8;
extern u32 *DAT_007ce3e4;
#define sOpTailF DAT_007ce3e4
#define sOpTailG (*(u32 **)(uintptr_t)0x007ce3e8)
#define OP_F80BC (*(volatile /* Removing this file's qualifier batch loses 2 MATCH(es) and worsens 0 other function(s) - measured W170. */ float*)(uintptr_t)0x007cadac)
#define OP_F80D8 (*(volatile /* Removing this file's qualifier batch loses 2 MATCH(es) and worsens 0 other function(s) - measured W170. */ float*)(uintptr_t)0x007cadc8)
#define OP_F81F8 (*(volatile /* Removing this file's qualifier batch loses 2 MATCH(es) and worsens 0 other function(s) - measured W170. */ float*)(uintptr_t)0x007caee8)
#define OP_F82BC (*(volatile /* Removing this file's qualifier batch loses 2 MATCH(es) and worsens 0 other function(s) - measured W170. */ float*)(uintptr_t)0x007cafac)
#define OP_F82C0 (*(volatile /* Removing this file's qualifier batch loses 2 MATCH(es) and worsens 0 other function(s) - measured W170. */ float*)(uintptr_t)0x007cafb0)
#define OP_F82C4 (*(volatile /* Removing this file's qualifier batch loses 2 MATCH(es) and worsens 0 other function(s) - measured W170. */ float*)(uintptr_t)0x007cafb4)
extern volatile /* Removing this file's qualifier batch loses 2 MATCH(es) and worsens 0 other function(s) - measured W170. */ s32 iGpffff97f0;
extern f32 fGpffff80d8;
extern f32 fGpffff82bc;
extern f32 fGpffff82c0;
extern f32 fGpffff82c4;
extern u8 DAT_007cc4e8[1];
#define OP_F82FC (*(volatile /* Removing this file's qualifier batch loses 2 MATCH(es) and worsens 0 other function(s) - measured W170. */ float*)(uintptr_t)0x007cafec)
#define OP_F839C (*(volatile /* Removing this file's qualifier batch loses 2 MATCH(es) and worsens 0 other function(s) - measured W170. */ float*)(uintptr_t)0x007cb08c)
extern void func_003b0170(u32 resource);
extern u32 func_003b0970(const char* text, s32 mode, s32 group, s32 a, s32 b);
extern void func_003b0d70(u32 resource, s32 x, s32 y);
extern void func_003b0e54(u32 resource, u32 color);
extern void frFontSetTextScale(u32 resource, f32 angle);
extern void func_003b0e70(s32 mode);
extern void* (*DAT_00960178[])(u32 size, u32 heap);
extern void (*DAT_0096017c[])(void* memory);
extern void func_003b1360_y2(u32 resource, s32 visible, s32 flags);
extern s32 func_003b19d0(u32 resource);
extern u8* DAT_007ce4ec;
extern void func_00521250(void* dst, const void* src, u32 size);
extern s32 func_00524388(const char* text);
extern void func_00524828(char* dst, const char* src, s32 size);
extern void func_005225a8(const void* text, ...);
extern u32 func_0016f190(s32 id);
extern void func_001985b0(u8 r, u8 g, u8 b, u8 a);
extern u32 func_0017d800(void);
extern void* func_001016b0(void* resource);
extern void* func_00102100(void* resource, s32 index, s32* size);
extern void func_00100ec0(void* resource);
extern void* func_00100d80(const void* descriptor, s32 flags);
extern void func_003af770(s32 slot, void* data);
extern void func_003afc30(s32 slot);
extern void* func_00194b80(void* parent, u32 priority, const char* name,
                           void* update, void* destroy, void* work);
extern void* func_00194e10(const char* name, u32 size, u32 a, u32 b, void* update,
                           void* destroy, u32 flags);
extern void func_00195550(void* task, void* resource);
extern s32 func_00195460(void* task, ...);
extern void func_00108570(void);
extern void func_001085c0(void);
extern u32 func_00108710(void);
extern void* func_0010bce0(void* task, u32 id);
extern void func_00195020(u32 resource);
extern void func_001749a0(u32 id);
extern void func_00176680(void* dst, u32 id);
extern void func_003c9850(s32 a, s32 b, s32 c, s32 d);
extern void func_003c9b00(u32 resource, const void* data, s32 mode);
extern void func_003c9cd0(u32 resource, s32 value);
extern void func_003c9d00(u32 resource, s32 value);
extern void func_003c9e00(u32 resource, s32 value);
extern s32 func_003c9ab0(u32 resource);
extern void func_00238980_y2(void* dst, s32 count, u32 value, s32 mode);
extern u32 func_0021c3f0(s32 id);
extern u32 func_0021cca0_y2(u32 resource, s32 id);
extern u32 func_0021cce0_y2(u32 resource);
extern void func_0021d3b0_y2(void* dst, u32 resource);
extern void func_0021d8e0_y2(void* dst, const void* value);
extern void func_0021d950_y2(void* dst, const void* value);
extern s32 func_004c9d10(u32 value);
extern void func_004c9d00(u32 value);
extern void func_004d7f60_y2(s32 a, u32 b);
extern u32 func_00198590(void);
extern void (*DAT_00960090[])(s32 state, u32 value);
extern void (*DAT_00960094[])(s32 state, void* value);
extern void (*DAT_0096009c[])(void* vertices, s32 stride, s32 mode, s32 a, s32 b);
extern void func_00521408(void* dst, s32 value, u32 size);
void func_0027a3b0(void);
u32* func_0027a4a0(void);
void func_0027a560(u32* work);
void func_0027a5d0(void);
void func_0027a6a0(u32* work, char* text, s32 align);
void func_0027a930(u32* work, const float* pos);
void func_0027aa00(u32* work, const u8* color);
u32 func_0027aaa0(void);
s32 func_0027ab10(void);
void func_0027ab80(void);
u32 func_0027b070(void);
void func_0027b200(void);
void func_0027ace0(void);
u32 func_0027b310(void);
void func_0027b3f0(s32 param);
void func_0027b6c0(void);
void sflPersonaDestroy(void);
void func_0027ac60(u32* work);
void func_0027ac80(void);
void func_0027ace0(void);
void func_0027ae90(void);
u32 func_0027af80(void);
void func_0027afd0(void);
void func_0027b0b0(void);
u32 func_0027b2b0(void);
u32 func_0027b460(void);
void func_0027b5b0(u32* work);
void func_0027b5d0(void);
void func_0027b610(void);
void func_0027b6c0(void);
void func_0027b880(void);
void func_0027b9f0(void);
void func_0027ba90(void);
typedef struct OpTailPosition {
    f32 x;
    f32 y;
} OpTailPosition;
void func_0027bae0(const OpTailPosition* value);
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
extern void func_0010a370(s32 channel, const char *message);
extern u32 func_00119a60(u32 id);
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
extern void func_002791b0_y2(u16 id);
extern void func_00279330_y2(u16 id);
extern void brpParamSetUnlockedSkillLevel_y2(u32 level);
extern void brpParamSetUnlockedSkillIndex_y2(u32 index);
extern void func_00279510_y2(s32 index, u32 value);
extern void func_00279580_y2(s32 index, u32 value);
extern void func_002795f0_y2(s32 index, u32 value);
extern u32 func_003b0d70_y2(u32 resource, s32 x, s32 y);
extern void func_003b0e20(u32 resource, u32 color);
extern void func_003b0e90_y2(s32 mode);
extern u32 func_003b1360(u32 resource, s32 visible, s32 flags);
extern void func_003c7430(s32 value);
extern void func_003c7bc0(s32 channel, u32 value);
extern void func_003c7e20(s32 mode, s32 x, s32 y, u64 value, s32 a,
                           s32 b, s32 c);
extern u32 func_003c9ab0_y2(u32 resource);
extern void func_003c9ba0(u32 stream, u32 resource);
extern void func_003c9d80(u32 resource, s32 value);
extern void func_004d7f60(s32 state, u32 value);
extern void func_00521250_y2(void *destination, const void *source, u32 size);
extern void func_005225a8_y2(const void *message, ...);
extern void brLvpnlStartEntranceAnimation(void);
extern void brLvpnlDisableDrawing(void);
extern void brLvpnlEnableDrawing(void);
extern u32 *DAT_007ce3c0;
extern u32 *DAT_007ce3c4;
extern u32 *DAT_007ce3c8;
extern u32 *DAT_007ce3cc;
extern u32 *DAT_007ce3d0_y2;
#undef gOpWorkC0
#undef gOpWorkC4
#undef gOpWorkC8
#undef gOpWorkCC
#undef gOpWorkD0
#define gOpWorkC0 DAT_007ce3c0
#define gOpWorkC4 DAT_007ce3c4
#define gOpWorkC8 DAT_007ce3c8
#define gOpWorkCC DAT_007ce3cc
#define gOpWorkD0 DAT_007ce3d0_y2
#define opTexW(resource, frame) \
    ((s32)sflPsel00260900((u32 *)(uintptr_t)(resource), (frame)))
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

// FUN_00276d30
void func_00276d30(void)
{
    OP_MATCH_ASSERT(gOpWorkD0 != NULL, 0x61);
    if ((*gOpWorkD0 & 1) != 0)
        func_00277070();
    gOpWorkD0 = NULL;
}

// FUN_00276d90
void func_00276d90(void)
{
    OpFadeWork* work;
    u32 res8;
    u32 res10;
    u32 res1;
    s32 i;

    OP_MATCH_ASSERT(gOpWorkD0 != NULL, 0x61);
    work = (OpFadeWork*)gOpWorkD0;
    res8 = func_00119a60(8);
    res10 = func_00119a60(10);
    res1 = brRes00234630(1);
    OP_MATCH_ASSERT((~work->flags & 1) != 0, 0x84);

    func_0025f5d0(work->panel15, res8, 0x15);
    func_0025fc50(work->panel15Alt, res8, 0x15, 1);
    func_0025f5d0(work->panel17, res8, 0x17);
    func_0021d3b0(work->texture1, func_0021cca0(res1, 1));
    func_0021d3b0(work->texture0, func_0021cca0(res1, 0));
    func_0021d3b0(work->texture0Alt, func_0021cca0(res1, 0));

    for (i = 0; i < 5; i++)
    {
        OpFadeEntry* entry = &work->entries[i];
        func_0025f5d0(entry->panel14, res10, 0x14);
        func_0025fc50(entry->panel14Alt, res10, 0x14, 1);
        func_0025f5d0(entry->panel15, res10, 0x15);
        func_00238980(entry->draw, 2, entry->drawHandle, 2);
        func_0025f5d0(entry->panel18, res10, 0x18);
        func_0025f5d0(entry->panel1b, res10, 0x1b);
    }

    for (i = 0; i < 8; i++)
        func_0025f5d0(work->list12[i], res8, 0x12);
    func_0025f5d0(work->panel13, res8, 0x13);
    for (i = 0; i < 7; i++)
        func_0025f5d0(work->list14[i], res8, 0x14);

    func_00238980(work->draw, 2, work->drawHandle, 2);
    work->state = 0;
    work->frame = 0;
    func_002771f0();
    work->flags &= ~0x40u;
    work->flags |= 1;
}



#pragma alias K_Assert_y2 K_Assert
#pragma alias func_0021d3b0_y2 func_0021d3b0
#pragma alias func_0021d8e0_y2 func_0021d8e0
#pragma alias func_0021d950_y2 func_0021d950
#pragma alias func_0021cca0_y2 func_0021cca0
#pragma alias func_0021cce0_y2 func_0021cce0
#pragma alias func_00238980_y2 func_00238980
#pragma alias func_00279120_y2 func_00279120
#pragma alias func_002792c0_y2 func_002792c0
#pragma alias func_003b1360_y2 func_003b1360
#pragma alias func_004d7f60_y2 func_004d7f60
#pragma alias func_002791b0_y2 func_002791b0
#pragma alias func_00279330_y2 func_00279330
#pragma alias brpParamSetUnlockedSkillLevel_y2 brpParamSetUnlockedSkillLevel
#pragma alias brpParamSetUnlockedSkillIndex_y2 brpParamSetUnlockedSkillIndex
#pragma alias func_00279510_y2 func_00279510
#pragma alias func_00279580_y2 func_00279580
#pragma alias func_002795f0_y2 func_002795f0
#pragma alias func_003b0d70_y2 func_003b0d70
#pragma alias func_003b0e90_y2 func_003b0e90
#pragma alias func_003c9ab0_y2 func_003c9ab0
#pragma alias func_00521250_y2 func_00521250
#pragma alias func_005225a8_y2 func_005225a8
#pragma alias DAT_007ce3d0_y2 DAT_007ce3d0


/* GP-owned work records are shared with the adjacent opening/ending TU. */



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
    s32 i;
    u8 *work;
    OpFadeWork *fadeWork;
    u32 tex8;
    u32 tex10;
    u32 tex1;
    u32 frame;
    u8 *listEntry;
    OpFadeEntry *entry;
    f32 layout[4];
    f32 alpha;
    f32 alpha2;
    u8 color[4];

    if (gOpWorkD0 == NULL)
        K_Assert(D_0068ED88, 0x61);
    work = OP_WORKD;
    fadeWork = (OpFadeWork*)gOpWorkD0;
    tex8 = func_00119a60(8);
    tex10 = func_00119a60(10);
    tex1 = brRes00234630(1);

    layout[0] = 411.0f;
    layout[1] = 326.0f;
    layout[2] = (f32)opTexW(tex8, 0x15);
    layout[3] = (f32)opTexH(tex8, 0x15);
    func_0021d8e0(fadeWork->panel15, layout);
    layout[0] = (f32)opTexW(tex8, 0x15) + 411.0f;
    layout[1] = 326.0f;
    layout[2] = 31.0f;
    layout[3] = (f32)opTexH(tex8, 0x15);
    func_0021d8e0(fadeWork->panel15Alt, layout);
    layout[0] = 557.0f;
    layout[1] = 326.0f;
    layout[2] = (f32)opTexW(tex8, 0x17);
    layout[3] = (f32)opTexH(tex8, 0x17);
    func_0021d8e0(fadeWork->panel17, layout);

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = 0xff;
    func_0021d950(fadeWork->panel15, color);
    func_0021d950(fadeWork->panel15Alt, color);
    func_0021d950(fadeWork->panel17, color);

    for (i = 0; i < 8; i++)
    {
        listEntry = fadeWork->list12[i];
        layout[0] = (f32)(i / 4) * 190.0f + 34.0f;
        layout[1] = (f32)(i % 4) * 24.0f + 316.0f;
        layout[2] = (f32)opTexW(tex8, 0x12);
        layout[3] = (f32)opTexH(tex8, 0x12);
        func_0021d8e0(listEntry, layout);
        func_0021d950(listEntry, color);
    }

    for (i = 0; i < OP_S32(work, 0x3738); i++)
    {
        f32 x = (f32)(i / 4) * 190.0f + 44.0f;
        f32 y = ((f32)(i % 4) * 24.0f + 315.0f - DAT_007cad74) * 8.0f;
        u32 resource = OP_U32(work, i * 0x110 + 0x110);

        func_003b0d70_y2(resource, (s32)((x + 10.0f) * 16.0f), (s32)y);
        func_003b0e20(resource, (u32)color[3] | ((u32)color[2] << 8) |
                      ((u32)color[1] << 16) | ((u32)color[0] << 24));
    }

    color[0] = 0xc7;
    color[1] = 0xb9;
    color[2] = 0xff;
    color[3] = 0xff;

    if ((OP_U32(work, 0) & 2) != 0)
    {
        if ((OP_U32(work, 0) & 0x10) == 0)
            alpha = 0.0f;
        else if (OP_S32(work, 0x3744) < 5)
            alpha = 0.0f;
        else if (OP_S32(work, 0x3744) < 10)
            alpha = (f32)(OP_S32(work, 0x3744) - 5) / 5.0f;
        else if (OP_S32(work, 0x3744) < 0x14)
            alpha = 1.0f;
        else if (OP_S32(work, 0x3744) < 0x1e)
            alpha = 1.0f - (f32)(OP_S32(work, 0x3744) - 0x14) / 10.0f;
        else
            alpha = 0.0f;

        {
            f32 x = 424.0f;
            f32 y = 169.0f;
            func_003b0d70_y2(OP_U32(work, 0x3950), (s32)(x * 16.0f), (s32)(y * 16.0f));
        }
        color[0] = (u8)(alpha * 55.0f + 199.0f);
        color[1] = (u8)(alpha * 70.0f + 185.0f);
        color[2] = (u8)(alpha * -95.0f + 255.0f);
        color[3] = 0xff;
        func_003b0e20(OP_U32(work, 0x3950),
                      (u32)color[3] | ((u32)color[2] << 8) |
                      ((u32)color[1] << 16) | ((u32)color[0] << 24));
        layout[0] = 414.0f;
        layout[1] = 343.0f;
        layout[2] = (f32)opTexW(tex8, 0x13);
        layout[3] = (f32)opTexH(tex8, 0x13);
        func_0021d8e0(fadeWork->panel13, layout);
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = 0xff;
        func_0021d950(fadeWork->panel13, color);

        if ((OP_U32(work, 0) & 0x10) == 0)
            alpha2 = 0.0f;
        else if (OP_S32(work, 0x3744) < 5)
            alpha2 = 0.0f;
        else if (OP_S32(work, 0x3744) < 10)
            alpha2 = (f32)(OP_S32(work, 0x3744) - 5) / 5.0f;
        else if (OP_S32(work, 0x3744) < 0x14)
            alpha2 = 1.0f;
        else if (OP_S32(work, 0x3744) < 0x1e)
            alpha2 = 1.0f - (f32)(OP_S32(work, 0x3744) - 0x14) / 10.0f;
        else
            alpha2 = 0.0f;

        frame = func_0021cca0(tex1, 1);
        layout[0] = 407.0f;
        layout[1] = 319.0f;
        layout[2] = (f32)OP_S32((void *)(uintptr_t)frame, 0xc);
        layout[3] = (f32)OP_S32((void *)(uintptr_t)frame, 0x10);
        func_0021d8e0(fadeWork->texture1, layout);
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = (u8)(255.0f * alpha2);
        func_0021d950(fadeWork->texture1, color);

        frame = func_0021cca0(tex1, 0);
        layout[0] = 405.0f;
        layout[1] = 333.0f;
        layout[2] = (f32)OP_S32((void *)(uintptr_t)frame, 0xc);
        layout[3] = (f32)OP_S32((void *)(uintptr_t)frame, 0x10);
        func_0021d8e0(fadeWork->texture0, layout);
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = (u8)(255.0f * alpha2);
        func_0021d950(fadeWork->texture0, color);
    }
    else
    {
        alpha = 0.0f;
        alpha2 = 0.0f;
    }

    for (i = 0; i < OP_S32(work, 0x3730); i++)
    {
        listEntry = fadeWork->list14[i];
        layout[0] = (f32)(i / 2) * 62.0f + 414.0f;
        layout[1] = (f32)(i % 2) * 24.0f + 366.0f;
        layout[2] = (f32)opTexW(tex10, 0x14);
        layout[3] = (f32)opTexH(tex10, 0x14);
        func_0021d8e0(listEntry, layout);
        func_0021d950(listEntry, color);
    }

    layout[0] = 526.0f;
    layout[1] = 328.0f;
    func_00238dc0(fadeWork->draw, 2, fadeWork->drawHandle, 2, layout);
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = 0xff;
    for (i = 0; i < 2; i++)
        func_0021d950(fadeWork->draw + i * 0x100, color);

    for (i = 0; i < 5; i++)
    {
        entry = &fadeWork->entries[i];

        layout[0] = 104.0f;
        layout[1] = 129.0f + (f32)i * 19.0f - 25.0f;
        layout[2] = (f32)opTexW(tex10, 0x14);
        layout[3] = DAT_007caf8c + (f32)opTexH(tex10, 0x14);
        func_0021d8e0(entry->panel14, layout);

        layout[0] = (f32)opTexW(tex10, 0x14) + 104.0f;
        layout[2] = 220.0f;
        layout[3] = DAT_007caf8c + (f32)opTexH(tex10, 0x14);
        func_0021d8e0(entry->panel14Alt, layout);
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = 0xff;
        func_0021d950(entry->panel14, color);
        func_0021d950(entry->panel14Alt, color);

        layout[0] = DAT_007cb04c;
        layout[1] = 129.0f + (f32)i * 19.0f - 25.0f;
        layout[2] = (f32)opTexW(tex10, 0x15);
        layout[3] = DAT_007caf8c + (f32)opTexH(tex10, 0x15);
        func_0021d8e0(entry->panel15, layout);
        func_0021d950(entry->panel15, color);

        layout[0] = 69.0f;
        layout[1] = 131.0f + (f32)i * 19.0f - 25.0f;
        func_00238dc0(entry->draw, 2, entry->drawHandle, 2, layout);
        func_0021d950(entry->draw, color);

        {
            s32 mode;
            f32 barStart;
            f32 barEnd;
            f32 pulse;

            mode = OP_S32(entry->draw, 0x200);
            if (mode == 0)
                barStart = 0.0f;
            else if (mode == 0x63)
                barStart = 229.0f;
            else
                barStart = 225.0f * (f32)mode / 98.0f + 2.0f;

            layout[0] = 108.0f;
            layout[1] = 130.0f + (f32)i * 19.0f - 25.0f;
            layout[2] = barStart;
            layout[3] = (f32)opTexH(tex10, 0x18);
            func_0021d8e0(entry->panel18, layout);
            func_0021eac0(entry->panel18, (f32)0xFFFF);
            func_0021d950(entry->panel18, color);

            if ((entry->drawHandle & 4) != 0)
            {
                mode = OP_S32(work, 0x373c);
                if (mode < 10)
                    alpha2 = 1.0f;
                else if (mode < 0x14)
                    alpha2 = 1.0f - (f32)(mode - 10) / 10.0f;
                else
                    alpha2 = 1.0f;
            }
            else
            {
                alpha2 = 1.0f;
            }

            pulse = (f32)OP_S32(work, 0x3740) / 10.0f;
            pulse *= 2.0f;
            pulse = sinf(DAT_007caf38 * pulse);
            pulse = DAT_007cafec * pulse + DAT_007cad74;

            mode = OP_S32(entry->draw, 0x200);
            if (mode == 0)
                barStart = 0.0f;
            else if (mode == 0x63)
                barStart = 229.0f;
            else
                barStart = 225.0f * (f32)mode / 98.0f + 2.0f;

            mode = OP_S32(entry->draw, 0x204);
            if (mode == 0)
                barEnd = 0.0f;
            else if (mode == 1)
                barEnd = 4.0f;
            else
                barEnd = 224.0f * (f32)mode / 98.0f + 3.0f;

            layout[0] = 108.0f + barStart - barEnd;
            layout[1] = 129.0f + (f32)i * 19.0f - 25.0f;
            layout[2] = barEnd;
            layout[3] = (f32)opTexH(tex10, 0x1b);
            func_0021d8e0(entry->panel1b, layout);
            color[0] = 0xff;
            color[1] = 0xff;
            color[2] = 0xff;
            color[3] = (u8)(255.0f * alpha2 * pulse);
            func_0021d950(entry->panel1b, color);
        }
    }

    layout[0] = (f32)OP_S32(work, 0x3b60) * 190.0f + 25.0f;
    layout[1] = (f32)OP_S32(work, 0x3b64) * 24.0f + 309.0f;
    frame = func_0021cca0(tex1, 0);
    layout[2] = (f32)OP_S32((void *)(uintptr_t)frame, 0xc);
    layout[3] = (f32)OP_S32((void *)(uintptr_t)frame, 0x10);
    func_0021d8e0(fadeWork->texture0Alt, layout);
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = 0xff;
    func_0021d950(fadeWork->texture0Alt, color);
}

#define D_00960090 (*state)
#define D_0096009C (*quad)
// FUN_00278550 NONMATCHING
void func_00278550(void)
{
    code *state;
    OpFadeWork* work;
    u32 tex8;
    u32 tex10;
    u32 tex1;
    u32 frame;
    s32 i;
    s32 j;
    u8 vertices[0x100];
    f32 rect[4];

    OP_MATCH_ASSERT(gOpWorkD0 != NULL, 0x61);
    work = (OpFadeWork*)gOpWorkD0;
    tex8 = func_00119a60(8);
    tex10 = func_00119a60(10);
    tex1 = brRes00234630(1);
    if ((work->flags & 1) == 0 || (work->flags & 0x40) != 0)
        return;
    state = (code *)&D_00960090_abs;
    D_00960090(0x14, 2);
    D_00960090(8, 0);
    D_00960090(6, 0);
    D_00960090(9, 2);
    D_00960090(0xe, 0);
    D_00960090(7, 2);
    D_00960090(0xc, 1);
    if ((work->flags & 0x20) != 0)
    {
        code *quad;
        frame = func_0021cca0(tex1, 2);
        func_0021d3b0(vertices, frame);
        rect[0] = 302.0f;
        rect[1] = 225.0f;
        rect[2] = (f32)OP_S32((void *)(uintptr_t)frame, 0xc);
        rect[3] = (f32)OP_S32((void *)(uintptr_t)frame, 0x10);
        func_0021d8e0(vertices, rect);
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        D_00960090(1, func_0021cce0(frame));
        quad = (code *)&D_0096009C_abs;
        D_0096009C(vertices, 4, 0, 1, 2);
        D_0096009C(vertices, 4, 0, 2, 3);
    }
    for (i = 0; i < 8; i++)
    {
        code *quad;
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        frame = opTexFrame(tex8, 0x12);
        D_00960090(1, frame);
        quad = (code *)&D_0096009C_abs;
        D_0096009C(work->list12[7 - i], 4, 0, 1, 2);
        D_0096009C(work->list12[7 - i], 4, 0, 2, 3);
    }
    for (i = 0; i < (s32)work->pad_3738; i++)
        func_003b1360(OP_U32(work, i * 0x110 + 0x440), 1, 0);
    if ((work->flags & 2) != 0)
    {
        code *quad;
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        frame = opTexFrame(tex8, 0x15);
        D_00960090(1, frame);
        quad = (code *)&D_0096009C_abs;
        D_0096009C(work->panel15, 4, 0, 1, 2);
        D_0096009C(work->panel15, 4, 0, 2, 3);
        D_0096009C(work->panel15Alt, 4, 0, 1, 2);
        D_0096009C(work->panel15Alt, 4, 0, 2, 3);
        frame = opTexFrame(tex8, 0x17);
        D_00960090(1, frame);
        D_0096009C(work->panel17, 4, 0, 1, 2);
        D_0096009C(work->panel17, 4, 0, 2, 3);
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        frame = opTexFrame(tex8, 0x13);
        D_00960090(1, frame);
        D_0096009C(work->panel13, 4, 0, 1, 2);
        D_0096009C(work->panel13, 4, 0, 2, 3);
        D_00960090(1, func_0021cce0(func_0021cca0(tex1, 1)));
        D_0096009C(work->texture1, 4, 0, 1, 2);
        D_0096009C(work->texture1, 4, 0, 2, 3);
        D_00960090(1, func_0021cce0(func_0021cca0(tex1, 0)));
        D_0096009C(work->texture0, 4, 0, 1, 2);
        D_0096009C(work->texture0, 4, 0, 2, 3);
        func_003b1360(OP_U32(work, 0x3950), 1, 0);
        for (i = 0; i < (s32)work->pad_3730; i++)
        {
            func_004d7f60(3, 0x717fb);
            func_004d7f60(2, 0x44);
            frame = opTexFrame(tex8, 0x14);
            D_00960090(1, frame);
            D_0096009C(work->list14[i], 4, 0, 1, 2);
            D_0096009C(work->list14[i], 4, 0, 2, 3);
        }
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        D_00960090(1, func_00239140(2));
        for (i = 0; i < 2; i++)
        {
            D_0096009C(work->draw + i * 0x100, 4, 0, 1, 2);
            D_0096009C(work->draw + i * 0x100, 4, 0, 2, 3);
        }
    }
    for (i = 0; i < 5; i++)
    {
        code *quad;
        OpFadeEntry* entry = &work->entries[i];
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        frame = opTexFrame(tex10, 0x14);
        D_00960090(1, frame);
        quad = (code *)&D_0096009C_abs;
        D_0096009C(entry->panel14, 4, 0, 1, 2);
        D_0096009C(entry->panel14, 4, 0, 2, 3);
        D_0096009C(entry->panel14Alt, 4, 0, 1, 2);
        D_0096009C(entry->panel14Alt, 4, 0, 2, 3);
        frame = opTexFrame(tex10, 0x15);
        D_00960090(1, frame);
        D_0096009C(entry->panel15, 4, 0, 1, 2);
        D_0096009C(entry->panel15, 4, 0, 2, 3);
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        D_00960090(1, func_00239140(2));
        for (j = 0; j < 2; j++)
        {
            D_0096009C(entry->draw + j * 0x100, 4, 0, 1, 2);
            D_0096009C(entry->draw + j * 0x100, 4, 0, 2, 3);
        }
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        D_00960090(1, opTexFrame(tex10, 0x18));
        D_0096009C(entry->panel18, 4, 0, 1, 2);
        D_0096009C(entry->panel18, 4, 0, 2, 3);
        if ((work->flags & 8) != 0)
        {
            func_004d7f60(3, 0x717fb);
            func_004d7f60(2, 0x44);
            D_00960090(1, opTexFrame(tex10, 0x1b));
            D_0096009C(entry->panel1b, 4, 0, 1, 2);
            D_0096009C(entry->panel1b, 4, 0, 2, 3);
        }
    }
    if ((work->flags & 0x20) != 0)
    {
        code *quad;
        if (DAT_007cc4dc != -1)
            func_003c7e20(0, 0x13c, 0x100, (u64)-1, 1, 6, 3);
        D_00960090(1, func_0021cce0(func_0021cca0(tex1, 0)));
        func_004d7f60(3, 0x71801);
        func_004d7f60(2, 0x48);
        quad = (code *)&D_0096009C_abs;
        D_0096009C(work->texture0Alt, 4, 0, 1, 2);
        D_0096009C(work->texture0Alt, 4, 0, 2, 3);
    }
}
#undef D_00960090
#undef D_0096009C


// FUN_00279120
void func_00279120_y2(void)
{
    s32 i;
    u32* work;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = sOpTailA;
    for (i = 0; i < (s32)work[0x3738 / 4]; i++) {
        func_003b0170(*(u32*)((u8*)work + i * 0x110 + 0x110));
    }
    work[0x3738 / 4] = 0;
}

// FUN_002791b0
void func_002791b0(u32 id)
{
    u32* root;
    u32* work;
    u32 handle;

    K_ASSERT(sOpTailA != NULL, 0x61);
    root = sOpTailA;
    work = (u32*)((u8*)root + root[0x3738 / 4] * 0x110 + 0x10);
    func_003b0e70(1);
    func_003b0e90(2);
    handle = func_003b0970(
        (const char*)(DAT_007ce4ec + (id & 0xffff) * 0x13), 1, 6, 0, 0);
    func_003b0d70(handle, 0x640, 0x320);
    frFontSetTextScale(handle, 0.0f);
    work[0x100 / 4] = handle;
    func_003b0e90(1);
    func_003b0e70(2);
    root[0x3738 / 4]++;
}

// FUN_002792c0
void func_002792c0_y2(void)
{
    u32* work;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = sOpTailA;
    if ((work[0] & 2) != 0) {
        func_003b0170(work[0xe54]);
    }
    work[0] &= ~2u;
}

// FUN_00279330
void func_00279330(u32 id)
{
    u32* work;
    u32 handle;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = sOpTailA;
    if ((~work[0] & 2) == 0) {
        K_Assert_y2("brp_param.c", 0x3e0);
    }
    func_003b0e70(1);
    func_003b0e90(2);
    handle = func_003b0970(
        (const char*)(DAT_007ce4ec + (id & 0xffff) * 0x13), 1, 6, 0, 0);
    func_003b0d70(handle, 0x640, 0x320);
    frFontSetTextScale(handle, 0.0f);
    work[0xe54] = handle;
    func_003b0e90(1);
    func_003b0e70(2);
    work[0] |= 2;
}

// FUN_00279450
void brpParamSetUnlockedSkillLevel(u32 level)
{
    int workBase;

    K_ASSERT(sBrpParam != NULL, 0x61);
    /* MWCC requires this address form to retain the retail call setup. */
    workBase = (int)sBrpParam;
    *(u32*)(workBase + 0x3734) = level;
    bpIFont00238980((void*)(workBase + 0x3750), 2, level, 2);
}

// FUN_002794c0
void brpParamSetUnlockedSkillIndex(u32 index)
{
    K_ASSERT(sBrpParam != NULL, 0x61);
    sBrpParam->unlockedSkillIndex = index;
}

// FUN_00279510
void func_00279510(s32 index, u32 value)
{
    u8* work;
    s32 byteOffset;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = (u8*)sOpTailA;
    byteOffset = index * 0x720;
    work = (u8*)((uintptr_t)byteOffset + (uintptr_t)work);
    *(u32*)(work + 0x890) = value;
}

// FUN_00279580
void func_00279580(s32 index, u32 value)
{
    u8* work;
    s32 byteOffset;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = (u8*)sOpTailA;
    byteOffset = index * 0x720;
    work = (u8*)((uintptr_t)byteOffset + (uintptr_t)work);
    *(u32*)(work + 0xaa0) = value;
}

// FUN_002795f0
void func_002795f0(s32 index, u32 value)
{
    u8* work;
    s32 byteOffset;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = (u8*)sOpTailA;
    byteOffset = index * 0x720;
    work = (u8*)((uintptr_t)byteOffset + (uintptr_t)work);
    *(u32*)(work + 0xaa4) = value;
}

// FUN_00279660
void func_00279660(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    sOpTailA[0] |= 8;
}

// FUN_002796b0
void func_002796b0(void)
{
    u32* work;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = sOpTailA;
    work[0xdcf] = 0;
    work[0] |= 4;
}

// FUN_00279700
u32 func_00279700(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    return sOpTailA[0] & 4;
}
// W389 residual nd20 (object 372/384): six-knob singles and all 15 knob pairs, plus pointer-type, temporary, and declaration-order probes, were reverted as neutral; alignment-cursor register coloring remains a compiler floor.
// FUN_00279750
void func_00279750(void)
{
    u32* work;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = sOpTailA;
    work[0xdd1] = 0;
    work[0] |= 0x10;
}

// FUN_002797a0
u32 func_002797a0(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    return sOpTailA[0] & 0x10;
}

// FUN_002797f0
void func_002797f0(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    sOpTailA[0] |= 0x20;
}

// FUN_00279840
void func_00279840(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    sOpTailA[0] &= ~0x20u;
}

// FUN_00279890
void func_00279890(u32 a, u32 b)
{
    u32* work;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = sOpTailA;
    work[0x3b60 / 4] = a;
    work[0x3b64 / 4] = b;
}

// FUN_002798f0
void func_002798f0(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    sOpTailA[0] |= 0x40;
}




/* Retail helpers used by the opening/ending result state. */
#pragma alias D_00960090_abs D_00960090
#pragma alias D_0096009C_abs D_0096009C




























// FUN_00279940 NONMATCHING
u32* func_00279940(const u32* header)
{
    u32 size;
    u32* out;
    u32* data;
    u32 aligned;
    u32 cursor;
    u32 i;
    u8* bytes;

    size = 0x14;
    size += header[3] * 4;
    if ((size & 3) != 0) {
        size += 4 - (size & 3);
    }
    size += header[6];
    if ((size & 3) != 0) {
        size += 4 - (size & 3);
    }
    size += header[2];
    data = out = (u32*)(*DAT_00960178)(size, 0x40000);
    data += 5;
    out[2] = (u32)data;
    aligned = (u32)data + header[3] * 4;
    if ((aligned & 3) != 0) {
        aligned += 4 - (aligned & 3);
    }
    out[3] = aligned;
    aligned += header[6];
    if ((aligned & 3) != 0) {
        aligned += 4 - (aligned & 3);
    }
    out[4] = aligned;
    out[1] = header[3];
    out[0] = header[0];
    func_00521250((void*)out[3], (const u8*)header + header[5], header[6]);
    func_00521250((void*)out[4], (const u8*)header + header[1], header[2]);
    bytes = (u8*)header + header[4];
    cursor = out[3];
    for (i = 0; i < header[3]; i++, bytes++) {
        ((u32*)out[2])[i] = cursor;
        cursor += *bytes;
    }
    return out;
}



// FUN_00279ac0
void func_00279ac0(u32 value)
{
    (*DAT_0096017c)((void*)(uintptr_t)value);
}

// FUN_00279AF0
u32 func_00279af0(const u32* work, u32 index)
{
    return *(const u32 *)(index * sizeof(u32) + work[2]);
}

// FUN_00279b10
u32 func_00279b10(const u32* work)
{
    return work[4];
}

// FUN_00279b20
u32 func_00279b20(const u32* work)
{
    return work[1];
}

// FUN_00279b30
void func_00279b30(u32* work)
{
    s32 i;
    u32 dark;

    work[0] = 0;
    ((u8*)work)[0x122c] = 0xff;
    ((u8*)work)[0x122d] = 0xff;
    ((u8*)work)[0x122e] = 0xff;
    ((u8*)work)[0x122f] = 0xff;
    dark = func_0016f190(0xb8e);
    if (dark != 0) {
        func_001985b0(0xff, 0xff, 0xff, 0xff);
    } else {
        func_001985b0(0xf, 0x1f, 0x28, 0xff);
    }
    for (i = 0; i < 0x20; i++) {
        *(u32*)((u8*)work + i * 0x90 + 4) = 0;
    }
    sOpTailB = work;
}
