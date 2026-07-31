#include "Main/Battle/Cmd/bcm_main.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Panel/bp_root.h"
#include "rw/rwplcore.h"
#include "Main/Battle/Cmd/bpp_main.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"
typedef struct PanelSkillRow
{
    u32 flags;
    u32 handle;
    u32 type;
    u32 icon;
} PanelSkillRow;
#pragma alias bcmIsItemUsable FUN_00207930
#pragma alias bcmDestroyOwnedResourceCallback FUN_00201ad0
#pragma alias bcmDestroyCommandResources FUN_00203360


u8* gBcmWork; // 007ce2e8
extern u8* DAT_007ce3ec;

s32 FUN_0017d2e0();
void FUN_00201A50(void);
u32 FUN_00201AF0(void);
void FUN_00201EF0(void);
void FUN_00202010(void);
void FUN_00202830(void);
u32 bpe00249600(void);
void* func_0021c5d0(void);
void* func_0021c640(void);
void* func_0021c6b0(void);
u32 itfMesMngInitialize(void*);
void itfMesMngDestroyHandle(u32);
void func_00207e20(void);
void func_00207f10(void);
void func_002db420(s32);
void func_002db650(u32);
void func_002db2a0(s32);
void func_0021f3c0(void);
void bpRushRequestHide(void);
void bpRushClearHideRequest(void);
void func_002083d0(void);
void FUN_00201880(void);
void FUN_002024B0(void);
void FUN_002025E0(void);
void FUN_00202A10(void);
void FUN_00203030(void);
void FUN_002031C0(void);
void FUN_00203410(void);
void FUN_00203990(void);
void FUN_00203C30(void);
void FUN_00203DE0(void);
void FUN_00204760(void);
void FUN_00205000(void);
void FUN_002057C0(void);
void FUN_00205D60(void);
void FUN_00206170(void);
void FUN_00206310(void);
void FUN_00206740(void);
void FUN_00206E40(void);
void FUN_00206EB0(void);
void FUN_00206F70(void);
void FUN_00207010(void);
void FUN_00207340(void);
void FUN_002078A0(void);
u32 FUN_00207960(u32 id);
void FUN_002079C0(void);
void FUN_00207A60(void);
void FUN_00207AB0(void);
void FUN_00207B00(void);
void FUN_00202BC0(void);
void FUN_00202C90(void);
void FUN_00202D70(void);
void FUN_00203630(void);
void FUN_00203760(void);
void FUN_00203850(void);
void FUN_00203B70(void);
void FUN_00204000(void);
void FUN_00204480(void);
void FUN_00204AF0(void);
void FUN_00204BE0(void);
void FUN_00204CC0(void);
u32 FUN_002053C0(void);
void FUN_00205410(void);
u32 FUN_002054C0(void);
u16 FUN_00205500(void);
u16 FUN_00205550(void);
u16 FUN_002055A0(void);
u32 FUN_00205650(s32 id);
void FUN_002056A0(void);
void FUN_00205700(void);
void FUN_00205760(void);
void FUN_002060B0(void);
void FUN_002063F0(void);
void FUN_002065A0(void);
static u8* panelWork(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    return gBcmWork;
}

static inline u32 panelWork32(u32 offset)
{
    return *(u32*)(gBcmWork + offset);
}

static inline void panelSetWork32(u32 offset, u32 value)
{
    *(u32*)(gBcmWork + offset) = value;
}

static inline u16 panelWork16(u32 offset)
{
    return *(u16*)(gBcmWork + offset);
}

static inline void panelSetWork16(u32 offset, u16 value)
{
    *(u16*)(gBcmWork + offset) = value;
}

void* func_00170e90(s16);
static u32 panelDataType(u16 id)
{
    void* record;

    record = func_00170e90((s16)id);
    if (record == NULL)
    {
        return 0;
    }
    return ((u8*)record)[3];
}
u32 FUN_002055F0(u32);
u32 func_003c7430(u32);
u32 func_003c74e0(u32);
static u32 panelSkillAccept(u16 id)
{
    return FUN_002055F0(id);
}

static PanelSkillRow* panelSkillRow(u32 index)
{
    return (PanelSkillRow*)(panelWork() + 0x4a90 + index * 0x2d0);
}

static PanelSkillRow* panelItemRow(u32 index)
{
    return (PanelSkillRow*)(panelWork() + 0x4a90 + index * 0x310);
}

static void panelTargetEffect(u32 first, u32 second)
{
    func_003c7430(first);
    func_003c74e0(second);
}

#pragma alias bpRoot_0021c720_ret func_0021c720
u32 bpRoot_0021c720_ret(void);
#pragma alias bpRoot_003c72d0_arg func_003c72d0
u32 bpRoot_003c72d0_arg(u32);

// Retail state-3 persona selection also handles input-driven left/right
// navigation and invokes bpPersona00267070 before the transition effect.
// The state-1/2/4 branches use the same input flag register as retail;
// these paths are reconstructed directly even though MWCC lays out the
// resulting switch differently from the retail object.

// FUN_001FF890 NONMATCHING
void FUN_001ff890(void)
{
    u32* work;
    u32 flags;
    void* message;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = (u32*)gBcmWork;
    if (*(u32*)((u8*)work + 0x77a0) & 1)
        FUN_005225a8((const char*)0x685058);
    else
        FUN_005225a8((const char*)0x685068);
    if (*(u32*)((u8*)work + 0x77a0) & 2)
        FUN_005225a8((const char*)0x685078);
    else
        FUN_005225a8((const char*)0x685088);
    if (*(u32*)((u8*)work + 0x77a0) & 4)
        FUN_005225a8((const char*)0x685098);
    else
        FUN_005225a8((const char*)0x6850a8);
    if (*(u32*)((u8*)work + 0x77a0) & 8)
        FUN_005225a8((const char*)0x6850b8);
    else
        FUN_005225a8((const char*)0x6850c8);
    if (*(u32*)((u8*)work + 0x77a0) & 0x10)
        FUN_005225a8((const char*)0x6850d8);
    else
        FUN_005225a8((const char*)0x6850e8);
    if (*(u32*)((u8*)work + 0x77a0) & 0x20)
        FUN_005225a8((const char*)0x6850f8);
    else
        FUN_005225a8((const char*)0x685108);
    if (*(u32*)((u8*)work + 0x77a0) & 0x40)
        FUN_005225a8((const char*)0x685120);
    else
        FUN_005225a8((const char*)0x685140);
    work[0] &= ~0x21u;
    work[0] &= ~2u;
    work[0] &= ~0x20000000u;
    work[0] &= ~0x02000000u;
    work[0] &= ~0x00040000u;
    work[0] &= ~0x80u;
    work[0] &= ~0x100u;
    work[0] &= ~0x200u;
    work[0] &= ~0x400u;
    work[1] = 0;
    work[3] = 0;
    if (datGetFlag(0x186))
    {
        work[0x24 / 4] = FUN_0016F380(0x30);
    }
    else
    {
        work[0x24 / 4] = 0;
    }
    message = func_0021c5d0();
    work[0x7794 / 4] = itfMesMngInitialize(message);
    message = func_0021c640();
    work[0x7790 / 4] = itfMesMngInitialize(message);
    message = func_0021c6b0();
    work[0x7798 / 4] = itfMesMngInitialize(message);
    work[0x77a4 / 4] = 0;
    FUN_002056A0();
    FUN_00201EF0();
    FUN_00202C90();
    FUN_00204000();
    FUN_00203760();
    FUN_00205700();
    FUN_00205760();
    work[2] = 0;
    if (func_00208010()) work[2] |= 1;
    if (func_00208050()) work[2] |= 2;
    if (func_00208130()) work[2] |= 4;
    if (work[2] & 2)
    {
        func_00207e20();
    }
    else if (work[2] & 4)
    {
        func_00207f10();
    }
    else if (work[2] & 1)
    {
        FUN_002078A0();
    }
    else
    {
        FUN_00201A50();
    }
    bpRushRequestHide();
}


// FUN_001FFC60 NONMATCHING
void FUN_001FFC60(void)
{
    u32* work;
    u8* record;
    u32 i;

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = (u32*)gBcmWork;
    for (i = 0; i < work[0x3a8 / 4]; i++)
    {
        record = (u8*)work + 0x2e0 + i * 0x18;
        if ((*(u32*)record & 1) == 0 && *(u32*)(record + 4) == 1)
        {
            datSetAiTactic(*(s16*)(record + 0xc), *(s16*)(record + 0x10));
            if (*(u32*)(record + 0x10) == 7)
            {
                u32 target;
                target = FUN_001FF430(*(u32*)(record + 8));
                func_002C0A50(target, *(u32*)(record + 0x14));
            }
        }
    }
    if (*(u32*)work & 0x20000)
    {
        if (!(*(u32*)work & 0x4000))
        {
            func_002db420(2);
        }
        else
        {
            func_002db650(work[0x7654 / 4]);
            func_002db2a0(2);
        }
    }
    if (*(u32*)work & 0x40000)
    {
        if (!(*(u32*)work & 0x8000)) func_002db420(1);
        else func_002db2a0(1);
    }
    if (*(u32*)work & 0x80000)
    {
        if (!(*(u32*)work & 0x100000)) func_002db420(0);
        else func_002db2a0(0);
    }
    if (*(u32*)work & 0x800000) func_002083d0();
    if (*(u32*)work & 0x10000) func_002db2a0(0);
    if (*(u32*)work & 0x2000) FUN_00206EB0();
    if (*(u32*)work & 0x1000) FUN_00206310();
    if (*(u32*)work & 2) FUN_00202BC0();
    if (*(u32*)work & 4) bcmDestroyCommandResources();
    if (*(u32*)work & 8) FUN_00203B70();
    if (*(u32*)work & 0x10) FUN_00204BE0();
    itfMesMngDestroyHandle(work[0x7790 / 4]);
    itfMesMngDestroyHandle(work[0x7794 / 4]);
    itfMesMngDestroyHandle(work[0x7798 / 4]);
    func_0021f3c0();
    bpRushClearHideRequest();
}

u32 func_002519d0(void);
u32 func_00251e80(void);
u32 bcmPanel0022b4e0(void);
u32 bcmPanel0022b530(void);
void bcmPanel00222870(void);
void bcmPanel002226f0(u32);
void bcmPanel002227b0(u32);
void func_002bf850(void);
void func_002bf8b0(void);
void func_002bf8e0(void);
void func_002bf910(void);
void func_002bf880(void);
void func_002bf940(void);
u32 func_002d1a70(void);
void bpPersonaLoad(u32);
void func_00208630(void);
u32 basRequestAnalyze(u32);
u32 basIsAnalyzePending(void);
u32 func_0021b6f0(void);
u32 func_0021b740(void);
u32 func_0021b7c0(void);
void func_002dbac0(void);
u32 func_003c7990(u32);
u32 func_003c7850(void);
u32 func_003c7650(u32);
u32 func_003c7610(u32);
void func_003c77a0(void);
u32 func_003c72d0(void);
u32 func_003c7430(u32);
u32 func_003c74e0(u32);
void func_0024a260(void*);
u32 func_0024a6e0(u32);
u32 func_0024a750(void);
u32 bpPersonaIsLoading(void);
void bpPersonaDestroy(void);
void bpPersonaSetPersona(u32);

static inline u16 panelRootInputFlags(void)
{
    return *(u16*)0x007E094E;
}

static inline u16 panelRootTargetFlags(void)
{
    return *(u16*)0x007E0952;
}

// FUN_001FFF40 NONMATCHING
void FUN_001FFF40(void)
{
    u32* work;
    u32 flags;
    u32 renderFlags;
    u32 state;
    u32 substate;
    u32 secondary;
    u32 menu;
    u32 type;
    u32 effect;
    u32 result;
    u32 value;
    u8* entry;
    void* persona;
    u32 func_0017b260(u16);
    /* Retail offsets: +0x2a0 guard; +0x3bc/+0x4e8/+0x56c/+0x5c0
       helper arguments; +0x1028/+0x1050 case layout; +0x1110-+0x127c
       secondary-1 path; +0x13f8/+0x1520/+0x1634 diagnostics. */

    K_ASSERT(gBcmWork != NULL, 0x164);
    work = (u32*)gBcmWork;
    renderFlags = 0;
    flags = work[0];
    if (flags & 0x08000000)
    {
        if ((s32)work[0x77a4 / 4] > 0)
            work[0x77a4 / 4]--;
    }
    else if (flags & 0x10000000)
    {
        if ((s32)work[0x77a4 / 4] < 0x10)
            work[0x77a4 / 4]++;
    }
    *(f32*)((u8*)work + 0x7644) =
        (f32)(s32)work[0x77a4 / 4] / 16.0f;
    if ((work[1] & 1) && !bcmPanel0022b4e0())
    {
        FUN_00202BC0();
        work[1] &= ~2u;
    }
    if ((work[1] & 2) && !bcmPanel0022b4e0())
    {
        bcmDestroyCommandResources();
        work[1] &= ~3u;
    }
    if ((work[1] & 4) && !bcmPanel0022b4e0())
    {
        FUN_00204BE0();
        work[1] &= ~5u;
    }

    state = work[4];
    switch (state)
    {
    case 0:
        if (!FUN_00201AF0() && !(flags & 0x40) && work[1] == 0)
        {
            if ((*(u16*)0x007E094E) & 4)
            {
                if (!(work[3] & 4) || bpMisc001ff740() == 2)
                {
                    FUN_0010A4E0(0, 0, 0, 8);
                }
                else
                {
                    FUN_0021B670(1);
                    work[4] = 6;
                    work[6] = 1;
                    work[0] |= 0x80000000u;
                    FUN_0010A4E0(0, 0, 0, 3);
                }
            }
            else
            {
                if (func_002d1a70() == 0 && ((*(u16*)0x007E094E) & 0x10))
                {
                    work[0] |= 0x200000;
                    work[0] |= 0x20;
                }
                else if ((work[3] & 0x40) && ((*(u16*)0x007E094E) & 0x80))
                {
                    work[0] |= 0x400000;
                    work[0] |= 0x20;
                }
                else if ((*(u16*)0x007E094E) & 0x40)
                {
                    menu = work[0x24 / 4];
                    if (menu < 7)
                    {
                        switch (menu)
                        {
                        case 0:
                            if (!(work[3] & 0x20))
                            {
                                func_002bf850();
                            }
                            else
                            {
                                bcmDestroyOwnedResourceCallback();
                                printf("battle panel command accepted\n");
                                work[0] |= 0x20;
                            }
                            break;
                        case 1:
                            if (!(work[3] & 1))
                            {
                                if (work[0] & 0x80)
                                    bpRoot001fea10(
                                        *(u32*)(DAT_007ce3ec + 0xba0), 0xcf);
                                else
                                    func_002bf8b0();
                            }
                            else
                            {
                                bcmDestroyOwnedResourceCallback();
                                FUN_00202010();
                                renderFlags |= 3;
                            }
                            break;
                        case 2:
                            if (!(work[3] & 2))
                            {
                                if (work[0] & 0x100)
                                    bpRoot001fea10(
                                        *(u32*)(DAT_007ce3ec + 0xba0), 0xd2);
                                else
                                    func_002bf8e0();
                            }
                            else
                            {
                                bcmDestroyOwnedResourceCallback();
                                FUN_00202D70();
                                renderFlags |= 5;
                            }
                            break;
                        case 3:
                            if (!(work[3] & 4))
                            {
                                if (work[0] & 0x200)
                                {
                                    if (FUN_0016F190(0x1317) != 0)
                                        bpRoot001fea10(
                                            *(u32*)(DAT_007ce3ec + 0xba0), 0xd4);
                                    else
                                        bpRoot001fea10(
                                            *(u32*)(DAT_007ce3ec + 0xba0), 0xd3);
                                }
                            }
                            else
                            {
                                bcmDestroyOwnedResourceCallback();
                                FUN_00204480();
                                renderFlags |= 0x11;
                            }
                            break;
                        case 4:
                            if (!(work[3] & 8))
                            {
                                if (work[0] & 0x400)
                                    bpRoot001fea10(
                                        *(u32*)(DAT_007ce3ec + 0xba0), 0xd5);
                                else
                                    func_002bf910();
                            }
                            else
                            {
                                bcmDestroyOwnedResourceCallback();
                                FUN_00203850();
                                renderFlags |= 9;
                            }
                            break;
                        case 5:
                            if (!(work[3] & 0x10))
                            {
                                func_002bf880();
                            }
                            else
                            {
                                bcmDestroyOwnedResourceCallback();
                                printf("battle panel command accepted\n");
                                work[0] |= 0x20;
                            }
                            break;
                        case 6:
                            if (!(work[3] & 0x40))
                            {
                                func_002bf940();
                            }
                            else
                            {
                                bcmDestroyOwnedResourceCallback();
                                printf("battle panel command accepted\n");
                                work[0] |= 0x20;
                            }
                            break;
                        default:
                            break;
                        }
                        FUN_0016F3E0(0x30, menu);
                    }
                }
                else
                {
                    K_ASSERT((flags & 2) == 0, 0x2b5);
                    if ((*(u16*)0x007E0952) & 0x20)
                    {
                        if (work[0x24 / 4] != 0)
                        {
                            work[0x24 / 4] = 0;
                            bcmPanel00222870();
                        }
                        renderFlags |= 1;
                    }
                    else
                    {
                        result = FUN_0016F190(0x188);
                        effect = 0;
                        value = 0;
                        if (result == 0)
                        {
                            if (((*(u16*)0x007E0952) & 0x4000) ||
                                (*(u16*)0x007E095A & 0x4000) ||
                                ((*(u16*)0x007E0952) & 0x8000) ||
                                (*(u16*)0x007E095A & 0x8000))
                                effect = 1;
                            if (((*(u16*)0x007E0952) & 0x1000) ||
                                (*(u16*)0x007E095A & 0x1000) ||
                                ((*(u16*)0x007E0952) & 0x2000) ||
                                (*(u16*)0x007E095A & 0x2000))
                                value = 1;
                        }
                        else
                        {
                            if (((*(u16*)0x007E0952) & 0x4000) ||
                                (*(u16*)0x007E095A & 0x4000) ||
                                ((*(u16*)0x007E0952) & 0x2000) ||
                                (*(u16*)0x007E095A & 0x2000))
                                effect = 1;
                            if (((*(u16*)0x007E0952) & 0x1000) ||
                                (*(u16*)0x007E095A & 0x1000) ||
                                ((*(u16*)0x007E0952) & 0x8000) ||
                                (*(u16*)0x007E095A & 0x8000))
                                value = 1;
                        }
                        if (effect)
                        {
                            menu = work[0x24 / 4];
                            if (menu < 6)
                                work[0x24 / 4] = menu + 1;
                            else
                                work[0x24 / 4] = 0;
                            FUN_0010A4E0(0, 0, 0, 5);
                            bcmPanel002226f0(work[0x24 / 4]);
                            renderFlags |= 1;
                        }
                        else if (value)
                        {
                            menu = work[0x24 / 4];
                            if (menu != 0)
                                work[0x24 / 4] = menu - 1;
                            else
                                work[0x24 / 4] = 6;
                            FUN_0010A4E0(0, 0, 0, 5);
                            bcmPanel002227b0(work[0x24 / 4]);
                            renderFlags |= 1;
                        }
                    }
                }
            }
        }
        break;
    case 1:
        if (!FUN_00201AF0() && !(flags & 0x40))
        {
            if ((*(u16*)0x007E094E) & 0x20)
            {
                func_00208460();
                renderFlags |= 1;
            }
            else if ((*(u16*)0x007E094E) & 0x40)
            {
                if ((work[0x7664 / 4] < 10) &&
                    (*(u32*)((u8*)work + 0x28 + work[0x7664 / 4] * 8) & 1))
                {
                    break;
                }
                FUN_00202830();
            }
            else
            {
                work[0x7658 / 4] &= ~2u;
                func_0024a260((u8*)work + 0x7658);
                if (work[0x7658 / 4] & 1)
                    renderFlags |= 2;
            }
        }
        break;
    case 2:
        if (!FUN_00201AF0() && !(flags & 0x40))
        {
            if ((*(u16*)0x007E094E) & 0x20)
            {
                func_00208460();
                renderFlags |= 1;
            }
            else if ((*(u16*)0x007E094E) & 0x40)
            {
                FUN_00203630();
            }
            else
            {
                work[0x768c / 4] &= ~2u;
                func_0024a260((u8*)work + 0x768c);
                if (work[0x768c / 4] & 1)
                    renderFlags |= 4;
            }
        }
        break;
    case 3:
        substate = work[5];
        if (substate == 0)
        {
            if (!(flags & 0x40))
            {
                if ((*(u16*)0x007E094E) & 0x20)
                {
                    FUN_00204AF0();
                    func_00208460();
                    renderFlags |= 1;
                }
                else if ((*(u16*)0x007E094E) & 0x80)
                {
                    bpPersonaLoad(
                        *(u16*)((u8*)work + 0x268 + work[0x76cc / 4] * 8));
                    FUN_002085E0();
                    FUN_0020FC40();
                    work[5] = 1;
                    FUN_0010A4E0(0, 0, 0, 1);
                }
                else if ((*(u16*)0x007E094E) & 0x40)
                {
                    persona = datPersonaGetByPcId(0);
                    if (*(u16*)((u8*)work + 0x268 + work[0x76cc / 4] * 8) !=
                        *(u16*)((u8*)persona + 2))
                    {
                        FUN_00208630();
                        bppMain0020fc90();
                        work[0] |= 0x20;
                    }
                    else
                    {
                        FUN_0010A4E0(0, 0, 0, 8);
                    }
                }
                else
                {
                    work[0x76c0 / 4] &= ~2u;
                    func_0024a260((u8*)work + 0x76c0);
                    if (work[0x76c0 / 4] & 1)
                        renderFlags |= 8;
                }
            }
        }
        else if (substate == 1)
        {
            if (!FUN_00201AF0() && !bpPersonaIsLoading())
            {
                if ((*(u16*)0x007E094E) & 0x20)
                {
                    bpPersonaDestroy();
                    FUN_00208630();
                    bppMain0020fc90();
                    FUN_0010A4E0(0, 0, 0, 2);
                    if (work[0x2dc / 4] < 5)
                    {
                        work[0x76c4 / 4] = 0;
                    }
                    else
                    {
                        value = work[0x76cc / 4];
                        if (value < 2)
                        {
                            work[0x76c4 / 4] = 0;
                        }
                        else if (value != work[0x2dc / 4] - 1)
                        {
                            work[0x76c4 / 4] = value - 2;
                        }
                        else
                        {
                            work[0x76c4 / 4] = value - 3;
                        }
                        renderFlags |= 8;
                    }
                    work[5] = 0;
                }
                else if ((*(u16*)0x007E094E) & 0x40)
                {
                    persona = datPersonaGetByPcId(1);
                    entry = (u8*)work + 0x268 + work[0x76cc / 4] * 8;
                    if (*(u16*)entry != *(u16*)((u8*)persona + 2))
                    {
                        bpPersonaDestroy();
                        FUN_00208630();
                        bppMain0020fc90();
                        work[0] |= 0x20;
                    }
                    else
                    {
                        FUN_0010A4E0(0, 0, 0, 8);
                    }
                }
                else
                {
                    value = work[0x2dc / 4];
                    if (value >= 2 && ((*(u16*)0x007E0952) & 8))
                    {
                        menu = work[0x76cc / 4];
                        if (menu < value - 1)
                            work[0x76cc / 4] = menu + 1;
                        else
                            work[0x76cc / 4] = 0;
                        bpPersonaSetPersona(
                            *(u16*)((u8*)work + 0x268 +
                                    work[0x76cc / 4] * 8));
                        FUN_0010A4E0(0, 0, 0, 8);
                    }
                    else if ((*(u16*)0x007E0952) & 4)
                    {
                        menu = work[0x76cc / 4];
                        if (menu != 0)
                            work[0x76cc / 4] = menu - 1;
                        else
                            work[0x76cc / 4] = value - 1;
                        bpPersonaSetPersona(
                            *(u16*)((u8*)work + 0x268 +
                                    work[0x76cc / 4] * 8));
                        FUN_0010A4E0(0, 0, 0, 8);
                    }
                }
            }
        }
        break;
    case 4:
        if (!FUN_00201AF0() && !(flags & 0x40) && work[1] == 0)
        {
            if ((*(u16*)0x007E094E) & 0x40)
            {
                entry = (u8*)work + work[0x7700 / 4] * 0x18 + 0x2e0;
                if (*(u32*)entry & 2)
                    break;
                type = *(u32*)(entry + 4);
                if (type == 0 || type == 1)
                {
                    FUN_002057C0();
                    renderFlags |= 0x20;
                }
                else if (type == 2)
                {
                    FUN_00206740();
                    renderFlags |= 0x40;
                }
                if (type == 0)
                    value = 0xc;
                else if (type == 1)
                    value = *(u16*)(entry + 0xc);
                else
                    value = 0xb;
                FUN_0016F3E0(0x33, value);
            }
            else if ((*(u16*)0x007E094E) & 0x20)
            {
                FUN_00204AF0();
                func_00208460();
                renderFlags |= 1;
            }
            else
            {
                work[0x76f4 / 4] &= ~2u;
                func_0024a260((u8*)work + 0x76f4);
                if (work[0x76f4 / 4] & 1)
                    renderFlags |= 0x10;
            }
        }
        break;
    case 5:
        if (!FUN_00201AF0() && !(flags & 0x40) && work[1] == 0)
        {
            substate = work[7];
            if (substate == 0)
            {
                if ((*(u16*)0x007E0952) & 0x20)
                {
                    FUN_00205D60();
                    renderFlags |= 1;
                }
                else if ((*(u16*)0x007E0952) & 0x40)
                {
                    FUN_002063F0();
                    renderFlags |= 0x10;
                }
                else
                {
                    work[0x7728 / 4] &= ~2u;
                    func_0024a260((u8*)work + 0x7728);
                    if (work[0x7728 / 4] & 1)
                        renderFlags |= 0x20;
                }
            }
            else if (substate == 2)
            {
                if (!bcmPanel0022b530())
                {
                    FUN_00206310();
                    work[4] = 4;
                }
            }
            else if (substate == 1)
            {
                if (!func_0021b6f0())
                {
                    FUN_00208630();
                    if (func_0021b740() == 0)
                    {
                        work[7] = 0;
                    }
                    else
                    {
                        work[0x428 / 4] = func_0021b7c0();
                        FUN_002065A0();
                        renderFlags |= 0x10;
                        FUN_00205D60();
                    }
                }
            }
        }
        break;
    case 6:
        secondary = work[6];
        switch (secondary)
        {
        case 0:
            if ((*(u16*)0x007E0952) & 0x20)
            {
                func_003c77a0();
                FUN_00206E40();
                renderFlags |= 1;
            }
            else if ((*(u16*)0x007E0952) & 0x40)
            {
                func_003c77a0();
                FUN_00207340();
                renderFlags |= 1;
            }
            else
            {
                work[0x775c / 4] &= ~2u;
                func_0024a260((u8*)work + 0x775c);
                if (work[0x775c / 4] & 1)
                    renderFlags |= 0x40;
            }
            break;
        case 9:
            if (!bcmPanel0022b530())
            {
                FUN_00206EB0();
                work[4] = 4;
            }
            break;
        case 1:
            if (!func_0021b6f0())
            {
                if (func_0021b740() == 0)
                {
                    if (work[0] & 0x80000000u)
                    {
                        work[6] = 0;
                    }
                    else
                    {
                        work[4] = 0;
                        work[0] &= ~0x80000000u;
                    }
                }
                else
                {
                    work[0x7654 / 4] = func_0021b7c0();
                    persona = (void*)(uintptr_t)FUN_001FF430(
                        work[0x7654 / 4]);
                    entry = *(u8**)((u8*)persona + 0xa2c);
                    if (func_0017b260(*(u16*)(entry + 2)))
                    {
                        FUN_005225a8((const char*)0x685050,
                                     *(u16*)(entry + 2));
                        FUN_005225a8((const char*)0x685060);
                        func_0024a6e0(work[0x7654 / 4]);
                        work[0] &= ~0x4001u;
                        work[6] = 2;
                    }
                    else
                    {
                        FUN_005225a8((const char*)0x685050,
                                     *(u16*)(entry + 2));
                        FUN_005225a8((const char*)0x685070);
                        work[0] |= 0x4000;
                        work[0] &= ~0x20001u;
                        func_002dbac0();
                    }
                }
            }
            break;
        case 2:
            if (!func_0024a750())
            {
                if (work[0] & 0x80000000u)
                {
                    FUN_00206E40();
                }
                else
                {
                    work[6] = 0;
                    work[0] &= ~0x80000000u;
                    work[0x18 / 4] = 0;
                }
            }
            break;
        case 3:
            func_003c7990(0);
            if (func_003c7850())
                break;
            func_003c7650(0);
            result = func_003c7610(0);
            if (result == 1)
            {
                func_003c77a0();
                FUN_00206E40();
                break;
            }
            if (result != 0)
                break;
            work[0] &= ~0x4001u;
            effect = bpMisc001ff740();
            if (effect == 0)
            {
                func_003c7430(2);
            }
            else if (effect == 1)
            {
                func_003c7430(FUN_002D5550() == 0x1a1 ? 8 : 5);
            }
            else
            {
                K_ASSERT(0, 0x5f1);
            }
            work[6] = 4;
            break;
        case 4:
            func_003c7990(1);
            if (func_003c7850())
                break;
            func_003c7650(1);
            func_003c77a0();
            FUN_00206E40();
            break;
        case 5:
            func_003c7990(0);
            if (func_003c7850())
                break;
            func_003c7650(0);
            result = func_003c7610(0);
            if (result == 1)
            {
                func_003c77a0();
                FUN_00206E40();
                break;
            }
            if (result != 0)
                break;
            work[0] &= ~0x20001u;
            effect = bpMisc001ff740();
            if (effect == 0)
            {
                func_003c7430(0xb);
            }
            else if (effect == 1)
            {
                func_003c7430(FUN_002D5550() == 0x1a1 ? 0xe : 0xb);
            }
            else
            {
                K_ASSERT(0, 0x62a);
            }
            work[6] = 6;
            break;
        case 6:
            func_003c7990(1);
            if (func_003c7850())
                break;
            func_003c7650(1);
            func_003c77a0();
            FUN_00206E40();
            break;
        case 7:
            func_003c7990(0);
            if (func_003c7850())
                break;
            func_003c7650(0);
            result = func_003c7610(0);
            if (result == 1)
            {
                func_003c77a0();
                FUN_00206E40();
                break;
            }
            if (result != 0)
                break;
            work[0] &= ~0x8001u;
            effect = bpMisc001ff740();
            if (effect == 1)
            {
                func_003c7430(0x11);
            }
            else
            {
                K_ASSERT(0, 0x660);
            }
            work[6] = 8;
            break;
        case 8:
            func_003c7990(1);
            if (func_003c7850())
                break;
            func_003c7650(1);
            func_003c77a0();
            FUN_00206E40();
            break;
        default:
            break;
        }
        break;
    case 7:
    case 8:
        break;
    case 9:
        if (!bpe00249600())
            FUN_00201A50();
        break;
    case 10:
        if (!func_002519d0())
        {
            bppMain0020fc90();
            if (work[2] & 4) func_00207f10();
            else if (work[2] & 1) FUN_002078A0();
            else FUN_00201A50();
        }
        break;
    case 11:
        if (!func_00251e80())
        {
            bppMain0020fc90();
            if (work[2] & 1) FUN_002078A0();
            else FUN_00201A50();
        }
        break;
    default:
        break;
    }

    if (renderFlags & 1) FUN_00201880();
    if (renderFlags & 2) FUN_002025E0();
    if (renderFlags & 4) FUN_002031C0();
    if (renderFlags & 8) FUN_00203C30();
    if (renderFlags & 0x10) FUN_00204CC0();
    if (renderFlags & 0x20) FUN_002060B0();
    if (renderFlags & 0x40) FUN_00206F70();
    if (work[0] & 0x40)
        work[0] &= ~0x40u;
}

/* Removing this loses FUN_00201880 (MATCH nd0 -> MISMATCH nd307) - measured W161. */

#pragma opt_loop_invariants on
#pragma opt_loop_invariants off

static u32 panelSkillAccept(u16 id)
{
    return FUN_002055F0(id);
}

static PanelSkillRow* panelSkillRow(u32 index)
{
    return (PanelSkillRow*)(panelWork() + 0x4a90 + index * 0x2d0);
}

static PanelSkillRow* panelItemRow(u32 index)
{
    return (PanelSkillRow*)(panelWork() + 0x4a90 + index * 0x310);
}

/* Removing this loses FUN_00204480 (MATCH nd0 -> MISMATCH nd341) - measured W308. */

#pragma opt_loop_invariants on
#pragma opt_loop_invariants off

/* Removing this loses FUN_002063F0 (MATCH nd0 -> MISMATCH nd128) - measured W308. */

#pragma opt_loop_invariants on
#pragma opt_loop_invariants off

/* Removing this loses FUN_002065A0 (MATCH nd0 -> MISMATCH nd159) - measured W308. */

#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
static void panelTargetEffect(u32 first, u32 second)
{
    func_003c7430(first);
    func_003c74e0(second);
}

#pragma alias bpRoot_0021c720_ret func_0021c720
u32 bpRoot_0021c720_ret(void);
#pragma alias bpRoot_003c72d0_arg func_003c72d0
u32 bpRoot_003c72d0_arg(u32);

// FUN_00207930
u32 bcmIsItemUsable(u16 param_1)
{
    return FUN_0017d2e0(param_1) != 0xc;
}

// FUN_00207a10
void bcm00207a10(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    *(u32*)(gBcmWork + 0x77a0) |= 2;
}

// FUN_00207B50
void FUN_00207B50(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    *(u32*)(gBcmWork + 0x77a0) |= 0x20;
}

void func_0021bcb0(void);
void func_0024c110(void);
u32 bpRushUpdate(void);
u32 bpRes0021bab0(void);
void bpd00253410(void);
void func_00210d90(void*);
void func_002510d0(void);
void func_00251a80(void);
void bppMain0020edf0(void);
u32 baiMainIsActive(void);
void func_0021c7e0(void);
void bpo00252060(void);
void func_002492b0(void);
u32 bpe00249600(void);
void func_00248620(void);
void func_00242cc0(void);
void func_0025c220(void);
void bpPersonaUpdate(void);
void func_0027b610(void);
u32 func_00249130(void);
void func_00245e50(void);
void func_00213e80(void*);
void func_00252f30(void);
void func_00209540(void);
void func_0023f540(void);
void func_0024cca0(void);
void func_002095a0(void);
void func_002532b0(void);
void func_0020f260(void);
void func_00243150(void);
void func_00241910(void);
void func_00248bb0(void);
void func_002520f0(void);
void func_0025c9c0(void);
void func_0025d470(void);
void func_0027b880(void);
u32 func_00208720(void);
void* btlUnitFindFromId(u16);
u32 func_00242a60(void);
void* func_00242260(void);
void func_00242320(void*, u32);
void func_00242a50(void*, u32);
void func_00242600(void*, u32);
void func_00242720(void*, u32);
void func_00242a30(void*);
void func_00242c20(void*, u32, u32);
void func_00242540(void*);
void func_002453d0(s32);
void func_002441b0(s32);
u32 func_00207f70(void);
u32 func_00207fc0(void);


// FUN_00207BA0
void FUN_00207BA0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    *(u32*)(gBcmWork + 0x77a0) |= 0x40;
}

void func_0021bcb0(void);
void func_0024c110(void);
u32 bpRushUpdate(void);
u32 bpRes0021bab0(void);
void bpd00253410(void);
void func_00210d90(void*);
void func_002510d0(void);
void func_00251a80(void);
void bppMain0020edf0(void);
u32 baiMainIsActive(void);
void func_0021c7e0(void);
void bpo00252060(void);
void func_002492b0(void);
u32 bpe00249600(void);
void func_00248620(void);
void func_00242cc0(void);
void func_0025c220(void);
void bpPersonaUpdate(void);
void func_0027b610(void);
u32 func_00249130(void);
void func_00245e50(void);
void func_00213e80(void*);
void func_00252f30(void);
void func_00209540(void);
void func_0023f540(void);
void func_0024cca0(void);
void func_002095a0(void);
void func_002532b0(void);
void func_0020f260(void);
void func_00243150(void);
void func_00241910(void);
void func_00248bb0(void);
void func_002520f0(void);
void func_0025c9c0(void);
void func_0025d470(void);
void func_0027b880(void);
u32 func_00208720(void);
void* btlUnitFindFromId(u16);
u32 func_00242a60(void);
void* func_00242260(void);
void func_00242320(void*, u32);
void func_00242a50(void*, u32);
void func_00242600(void*, u32);
void func_00242720(void*, u32);
void func_00242a30(void*);
void func_00242c20(void*, u32, u32);
void func_00242540(void*);
void func_002453d0(s32);
void func_002441b0(s32);
u32 func_00207f70(void);
u32 func_00207fc0(void);


// FUN_00207bf0
void bcm00207bf0(void)
{
    K_ASSERT(gBcmWork != NULL, 0x164);
    *(u32*)(gBcmWork + 0x77a0) &= ~1;
}

void bcmDestroyOwnedResource();

// FUN_00201ad0
void bcmDestroyOwnedResourceCallback(void)
{
    bcmDestroyOwnedResource();
}

void FUN_003b0170();

// FUN_00203360
void bcmDestroyCommandResources(void)
{
    u32* puVar1;
    int iVar2;

    K_ASSERT(gBcmWork != NULL, 0x164);
    puVar1 = (u32*)gBcmWork;
    for (iVar2 = 0; iVar2 < (int)puVar1[0x97]; iVar2++) {
        FUN_003b0170(*(u32*)((int)puVar1 + iVar2 * 4 + 0x8c));
    }
    if ((*puVar1 & 0x20) != 0) {
        FUN_003b0170(puVar1[0x99]);
    }
    *puVar1 &= 0xfffffffb;
}
