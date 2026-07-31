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




































// FUN_0027ac80
void func_0027ac80(void)
{
    K_ASSERT(sOpTailC != NULL, 0x31);
    if ((sOpTailC[1] & 1) != 0) {
        func_0027afd0();
    }
    sOpTailC = NULL;
}

// FUN_0027ace0
void func_0027ace0(void)
{
    u32* work;
    s32 size;
    s32 i;
    void* data;
    void* copy;

    if (sOpTailC == NULL) {
        K_Assert("ed_res.c", 0x31);
    }
    work = sOpTailC;
    if ((work[0] & 1) != 0 && func_001016b0((void*)(uintptr_t)work[2]) != NULL) {
        for (i = 0; i < 3; i++) {
            data = func_00102100((void*)(uintptr_t)work[2], i, &size);
            switch (i) {
            case 0:
                work[3] = (u32)func_00279940((const u32*)data);
                break;
            case 1:
                copy = (*DAT_00960178)(size, 0x40000);
                func_00521250(copy, data, size);
                func_003af770(6, copy);
                break;
            case 2:
                copy = (*DAT_00960178)(size, 0x40000);
                func_00521250(copy, data, size);
                func_003af770(7, copy);
                break;
            }
        }
        work[1] |= 1;
        func_00100ec0((void*)(uintptr_t)work[2]);
        work[0] &= ~1u;
    }
}

// FUN_0027ae90
void func_0027ae90(void)
{
    u32* work;

    if (sOpTailC == NULL) {
        K_Assert("ed_res.c", 0x31);
    }
    work = sOpTailC;
    if ((~work[0] & 1) == 0) {
        K_Assert("ed_res.c", 0x76);
    }
    if ((~work[1] & 1) == 0) {
        K_Assert("ed_res.c", 0x77);
    }
    if (func_0017d800() == 0) {
        work[2] = (u32)func_00100d80("oped/ed_sr.bin", 1);
    } else {
        work[2] = (u32)func_00100d80("oped/ed_sr_f.bin", 1);
    }
    work[0] |= 1;
}

// FUN_0027af80
u32 func_0027af80(void)
{
    K_ASSERT(sOpTailC != NULL, 0x31);
    return sOpTailC[0] & 1;
}

// FUN_0027afd0
void func_0027afd0(void)
{
    u32* work;

    K_ASSERT(sOpTailC != NULL, 0x31);
    work = sOpTailC;
    K_ASSERT((work[1] & 1) != 0, 0x8e);
    func_00279ac0(work[3]);
    func_003afc30(6);
    func_003afc30(7);
    work[1] &= ~1u;
}

// FUN_0027b070
u32 func_0027b070(void)
{
    K_ASSERT(sOpTailC != NULL, 0x31);
    return sOpTailC[3];
}

// FUN_0027b0b0
void func_0027b0b0(void)
{
    u32* work;
    u32 state;

    if (sOpTailD == NULL) {
        K_Assert("ed_sr.c", 0x3d);
    }
    work = sOpTailD;
    if ((~work[0] & 1) != 0) {
        return;
    }
    state = work[0x493];
    switch (state) {
    case 0:
        if (func_0027af80() == 0) {
            func_001085c0();
            work[0x493] = 1;
        }
        break;
    case 1:
        if (func_00108710() != 0) {
            func_0027b200();
        }
        break;
    case 2:
        work[0x495]++;
        if (func_00279d10() == 0 &&
            kwlnTaskExists((KwlnTask*)(uintptr_t)work[0x494]) == 0) {
            func_00108570();
            work[0x493] = 3;
        }
        break;
    case 3:
        if (func_00108710() != 0) {
            work[0] &= ~1u;
        }
        break;
    }
    func_0027ace0();
    func_00279d60();
}

// FUN_0027b200
void func_0027b200(void)
{
    u32* work;
    u32 id;
    void* task;

    if (sOpTailD == NULL) {
        K_Assert("ed_sr.c", 0x3d);
    }
    work = sOpTailD;
    if (func_0017d800() == 0) {
        if (func_0016f190(0xb8e) != 0) {
            id = 0x20;
        } else {
            id = 0x21;
        }
    } else {
        id = 0x2a;
    }
    func_00279c90();
    task = func_0010bce0((void*)(uintptr_t)work[1], id);
    *(u32*)((u8*)work + 0x1250) = (u32)task;
    *(u32*)((u8*)work + 0x1254) = 0;
    *(u32*)((u8*)work + 0x124c) = 2;
}

// FUN_0027b2b0
u32 func_0027b2b0(void)
{
    func_0027b0b0();
    if (sOpTailD == NULL) {
        K_Assert("ed_sr.c", 0x3d);
    }
    return (sOpTailD[0] & 1) != 0 ? 0 : (u32)-1;
}

// FUN_0027b310
u32 func_0027b310(void)
{
    void (* volatile /* Removing this qualifier loses func_0027b310 (MATCH nd0 -> MISMATCH nd94, size 216 -> 220) - measured W170. */ *stateSetter)(s32 state, u32 value);
    u32 saved;

    if (func_004c9d10(func_00198590()) != 0) {
        (*DAT_00960094)(0xe, &saved);
        stateSetter = DAT_00960090;
        (*stateSetter)(0xe, 0);
        if (sOpTailD == NULL) {
            K_Assert("ed_sr.c", 0x3d);
        }
        if ((~sOpTailD[0] & 1) == 0) {
            func_0027a3b0();
        }
        (*stateSetter)(0xe, saved);
        func_004c9d00(func_00198590());
    }
    return 0;
}

// FUN_0027b3f0
void func_0027b3f0(s32 param)
{
    if (sOpTailD == NULL) {
        K_Assert("ed_sr.c", 0x3d);
    }
    func_00279bf0();
    func_0027ac80();
    (*DAT_0096017c)(*(void**)((u8*)(uintptr_t)param + 0x3c));
}

// FUN_0027b460
u32 func_0027b460(void)
{
    u32* root;
    void* task;
    void* resource;

    if (sOpTailE == NULL) {
        root = (*DAT_00960178)(0x1258, 0x40000);
        task = kwlnTaskCreateWithAutoPriority(NULL, 10, "edsr",
                                              (KwlnTaskUpdateFunc)func_0027b2b0,
                                              (KwlnTaskDestroyFunc)func_0027b3f0, root);
        resource = kwlnTaskInitEx("edsr draw", 0x1cd8, 1, 2,
                                  (KwlnTaskUpdateFunc)func_0027b310, NULL, NULL);
        root[2] = (u32)resource;
        kwlnTaskAddChild(task, resource);
        root[0] = 0;
        func_0027ac60(root + 3);
        func_00279b30(root + 7);
        root[1] = (u32)task;
        sOpTailD = root;
        if (root == NULL) {
            K_Assert("ed_sr.c", 0x3d);
        }
        root = sOpTailD;
        func_0027ae90();
        root[0x493] = 0;
        root[0] |= 1;
        sOpTailE = (u32*)task;
        return 0;
    }
    if (kwlnTaskExists((KwlnTask*)sOpTailE) == 0) {
        sOpTailE = NULL;
        return 1;
    }
    return 0;
}

// FUN_0027B5B0
void func_0027b5b0(u32* work)
{
    work[0] = 0;
    work[0x114 / 4] = 0x42c80000;
    work[0x118 / 4] = 0x42c80000;
    sOpTailF = work;
}







