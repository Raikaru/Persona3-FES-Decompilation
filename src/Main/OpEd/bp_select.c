#include "Utils.h"
#include "Kosaka/k_assert.h"
#include "Main/OpEd/op_fade_mid.h"
#include "Kernel/Kwln/kwlnTask.h"

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

















































// FUN_0027b5d0
void func_0027b5d0(void)
{
    K_ASSERT(sOpTailF != NULL, 0x27);
    sOpTailF = NULL;
}

// FUN_0027b610
void func_0027b610(void)
{
    u32* work;
    u32 flags;

    K_ASSERT(sOpTailF != NULL, 0x27);
    work = sOpTailF;
    flags = work[0];
    if ((~flags & 1) == 0) {
        if ((flags & 2) != 0) {
            if (*(s32*)((u8*)work + 0x110) < 0x14) {
                work[0x44]++;
            } else {
                work[0] = flags & ~1u;
            }
        } else if (*(s32*)((u8*)work + 0x110) < 0x14) {
            work[0x44]++;
        }
        func_0027b6c0();
    }
}

// FUN_0027b6c0
void func_0027b6c0(void)
{
    typedef struct {
        u8 scratch[0x1c];
        u8 rgba[4];
    } ColorWorkspace;
    u32* work;
    u32 texture;
    u32 descriptor;
    ColorWorkspace color;
    f32 values[4];
    f32 alpha;

    K_ASSERT(sOpTailF != NULL, 0x27);
    work = sOpTailF;
    texture = func_0021c3f0(2);
    descriptor = func_0021cca0(texture, 0x3a);
    values[0] = *(f32*)((u8*)work + 0x114);
    values[1] = *(f32*)((u8*)work + 0x118);
    values[2] = (f32)*(s32*)((u8*)(uintptr_t)descriptor + 0xc);
    values[3] = (f32)*(s32*)((u8*)(uintptr_t)descriptor + 0x10);
    func_0021d8e0(work + 4, values);
    if ((work[0] & 2) != 0) {
        if (*(s32*)((u8*)work + 0x110) < 0x14) {
            alpha = 1.0f - (f32)*(s32*)((u8*)work + 0x110) / 20.0f;
        } else {
            alpha = 0.0f;
        }
    } else if (*(s32*)((u8*)work + 0x110) < 0x14) {
        alpha = (f32)*(s32*)((u8*)work + 0x110) / 20.0f;
    } else {
        alpha = 1.0f;
    }
    color.rgba[0] = 0xff;
    color.rgba[1] = 0xff;
    color.rgba[2] = 0xff;
    color.rgba[3] = (u8)(alpha * 255.0f);
    func_0021d950(work + 4, color.rgba);
}

// FUN_0027b880
void func_0027b880(void)
{
    void (* volatile /* Removing this function's qualifier batch loses func_0027b880 (MATCH nd0 -> MISMATCH nd225, size 364 -> 368) - measured W170. */ *stateSetter)(s32 state, u32 value);
    void (* volatile /* Removing this function's qualifier batch loses func_0027b880 (MATCH nd0 -> MISMATCH nd225, size 364 -> 368) - measured W170. */ *draw)(void* vertices, s32 stride, s32 mode, s32 a, s32 b);
    u32* work;
    u32 texture;
    u32 descriptor;

    K_ASSERT(sOpTailF != NULL, 0x27);
    work = sOpTailF;
    texture = func_0021c3f0(2);
    if ((~work[0] & 1) == 0) {
        stateSetter = DAT_00960090;
        (*stateSetter)(9, 2);
        (*stateSetter)(0x14, 2);
        (*stateSetter)(8, 0);
        (*stateSetter)(6, 0);
        descriptor = func_0021cce0(func_0021cca0(texture, 0x3a));
        (*stateSetter)(1, descriptor);
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        draw = DAT_0096009c;
        (*draw)(work + 4, 4, 0, 1, 2);
        (*draw)(work + 4, 4, 0, 2, 3);
    }
}

// FUN_0027b9f0
void func_0027b9f0(void)
{
    u32* work;
    u32 texture;

    K_ASSERT(sOpTailF != NULL, 0x27);
    work = sOpTailF;
    texture = func_0021cca0(func_0021c3f0(2), 0x3a);
    func_0021d3b0(work + 4, texture);
    work[0x44] = 0;
    work[0] &= ~2u;
    func_0027b6c0();
    work[0] |= 1;
}

// FUN_0027ba90
void func_0027ba90(void)
{
    u32* work;

    K_ASSERT(sOpTailF != NULL, 0x27);
    work = sOpTailF;
    work[0x44] = 0;
    work[0] |= 2;
}

// FUN_0027bae0
void func_0027bae0(const OpTailPosition* value)
{
    u32* work;

    K_ASSERT(sOpTailF != NULL, 0x27);
    work = sOpTailF;
    *(OpTailPosition*)((u8*)work + 0x114) = *value;
    if ((work[0] & 1) != 0) {
        func_0027b6c0();
    }
}
