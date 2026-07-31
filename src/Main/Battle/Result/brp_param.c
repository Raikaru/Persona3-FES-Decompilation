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


#include "Utils.h"
#include "Main/OpEd/op_fade_mid.h"

/* GP-owned work records are shared with the adjacent opening/ending TU. */
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
extern void func_003b1360(u32 resource, s32 visible, s32 flags);
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
extern void func_00238980(void* dst, s32 count, u32 value, s32 mode);
extern u32 func_0021c3f0(s32 id);
extern u32 func_0021cca0(u32 resource, s32 id);
extern u32 func_0021cce0(u32 resource);
extern void func_0021d3b0(void* dst, u32 resource);
extern void func_0021d8e0(void* dst, const void* value);
extern void func_0021d950(void* dst, const void* value);
extern s32 func_004c9d10(u32 value);
extern void func_004c9d00(u32 value);
extern void func_004d7f60(s32 a, u32 b);
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

// FUN_00279120
void func_00279120(void)
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
void func_002792c0(void)
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
        K_Assert("brp_param.c", 0x3e0);
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
// W389 residual nd20 (object 372/384): six-knob singles and all 15 knob pairs, plus pointer-type, temporary, and declaration-order probes, were reverted as neutral; alignment-cursor register coloring remains a compiler floor.
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
