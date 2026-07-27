#include "Utils.h"
#include "Kosaka/k_assert.h"
#pragma alias sflPersonaInit FUN_0027BB50
#pragma alias sflPersonaShutdown FUN_0027BBA0
#pragma alias sflPersonaLoad FUN_0027BC00
#pragma alias sflPersonaSetPersona FUN_0027BD10
#pragma alias sflPersonaDestroy FUN_0027BDF0
#pragma alias sflPersonaUpdate FUN_0027BE50
#pragma alias sflPersonaIsLoading FUN_0027BF60
#pragma alias sflPersonaStartExitTransition FUN_0027BFB0
#pragma alias sflPersonaIsTransitioning FUN_0027C020


typedef struct SflPersonaWork
{
    u32 flags;      // 0x00
    u32 resource;   // 0x04
    u16 personaId;  // 0x08
    u16 reserved;   // 0x0a
    u32 timer;      // 0x0c
} SflPersonaWork;

static SflPersonaWork* sSflPersona; // 007ce3e8


extern void func_00521408(void* dst, s32 value, u32 size);
extern void* func_001749a0(u32 id);
extern void func_00176680(void* dst, u32 id);
extern u32 func_003c9850(s32 a, s32 b, s32 c, s32 d);
extern void func_003c9b00(u32 resource, const void* data, s32 mode);
extern void func_003c9cd0(u32 resource, s32 value);
extern void func_003c9d00(u32 resource, s32 value);
extern void func_003c9e00(u32 resource, s32 value);
extern s32 func_003c9ab0(u32 resource);
extern void func_00195020(u32 resource);
void sflPersonaDestroy(void);

// FUN_0027BB50
void sflPersonaInit(u32* work)
{
    K_ASSERT(sSflPersona == NULL, 0x30);
    work[0] = 0;
    sSflPersona = (SflPersonaWork*)work;
}

// FUN_0027BBA0
void sflPersonaShutdown(void)
{
    K_ASSERT(sSflPersona != NULL, 0x29);
    if ((sSflPersona->flags & 1u) != 0) {
        sflPersonaDestroy();
    }
    sSflPersona = NULL;
}

// FUN_0027BC00
void sflPersonaLoad(u32 id)
{
    u32* work;
    void* data;
    u8 fallback[0x40];

    K_ASSERT(sSflPersona != NULL, 0x29);
    work = (u32*)sSflPersona;
    ((u16*)work)[4] = (u16)id;
    data = func_001749a0((u32)id);
    if (data == NULL) {
        func_00521408(fallback, 0, 0x34);
        func_00176680(fallback, (u32)id);
        data = fallback;
    }
    work[1] = func_003c9850(0, 0, 5, 5);
    func_003c9b00(work[1], data, 0);
    func_003c9cd0(work[1], (s32)-1);
    func_003c9d00(work[1], 8);
    func_003c9e00(work[1], 1);
    work[0] |= 2;
    work[0] |= 1;
}

// FUN_0027BD10
void sflPersonaSetPersona(u32 id)
{
    SflPersonaWork* work;
    void* data;
    u8 fallback[0x34];

    K_ASSERT(sSflPersona != NULL, 0x29);
    work = sSflPersona;
    if (work->personaId == (u16)id) {
        K_ASSERT(false, 0x6b);
    }
    work->personaId = (u16)id;
    data = func_001749a0(id);
    if (data == NULL) {
        func_00521408(fallback, 0, 0x34);
        func_00176680(fallback, id);
        data = fallback;
    }
    func_003c9b00(work->resource, data, 0);
    work->flags |= 2;
}

// FUN_0027BDF0
void sflPersonaDestroy(void)
{
    SflPersonaWork* work;

    K_ASSERT(sSflPersona != NULL, 0x29);
    work = sSflPersona;
    func_00195020(work->resource);
    work->flags &= ~1u;
}

// FUN_0027BE50
void sflPersonaUpdate(void)
{
    u32* work;

    K_ASSERT(sSflPersona != NULL, 0x29);
    work = (u32*)sSflPersona;
    if (((~work[0]) & 1) == 0) {
        if ((work[0] & 2) != 0 && func_003c9ab0(work[1]) != 0) {
            work[0] &= ~2u;
            work[3] = 0;
            work[0] |= 4;
        }
        if ((work[0] & 4) != 0) {
            if ((s32)work[3] < 5) {
                work[3]++;
            } else {
                work[0] &= ~4u;
            }
        }
        if ((work[0] & 8) != 0) {
            if ((s32)work[3] < 5) {
                work[3]++;
            } else {
                work[0] &= ~8u;
            }
        }
    }
}

// FUN_0027BF60
u32 sflPersonaIsLoading(void)
{
    K_ASSERT(sSflPersona != NULL, 0x29);
    return sSflPersona->flags & 2;
}

// FUN_0027BFB0
void sflPersonaStartExitTransition(void)
{
    SflPersonaWork* work;

    K_ASSERT(sSflPersona != NULL, 0x29);
    work = sSflPersona;
    func_003c9d00(work->resource, 0x10);
    work->timer = 0;
    work->flags |= 8;
}

// FUN_0027C020
u32 sflPersonaIsTransitioning(void)
{
    u32 flags;

    K_ASSERT(sSflPersona != NULL, 0x29);
    flags = sSflPersona->flags;
    return (flags & 4u) != 0 || (flags & 8u) != 0;
}
