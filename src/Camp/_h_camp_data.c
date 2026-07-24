/* Camp/data bridge functions at retail 0x001675B0-0x0016C2F0. */
#include "Camp/h_camp.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Main/g_data.h"
#include "h_cdvd.h"
#include "h_maestro.h"
#include "h_snd.h"
#include "Main/Battle/Data/datPersona.h"
#include "Script/scrTraceCode.h"
#include "Utils.h"

typedef u8 undefined1;
typedef u16 undefined2;
typedef u32 undefined4;
typedef u64 undefined8;
typedef int bool;
typedef unsigned long ulong;
#define CAMP_PTR64(value) ((undefined8)(uintptr_t)(value))

/* Retail globals shared by the Camp bridge state machines. */
extern void (*DAT_0096017c[])(...);
#pragma alias DAT_0096017c_abs DAT_0096017c
extern void (*DAT_0096017c_abs[])(...);
#pragma alias DAT_00960184_abs DAT_00960184
extern void* (*DAT_00960184_abs[])(...);
#pragma alias scrGetIntPara_u64 scrGetIntPara
extern u64 scrGetIntPara_u64(s32);
extern void* (*DAT_00960184)();
extern void* (*DAT_00960178)();
extern f32 DAT_00960088;
extern void* DAT_007cdf48;
extern void* DAT_007cdf54;
extern void* DAT_007cdf58;
extern void* DAT_007cdf84;
extern void* DAT_007cdf88;
extern s32 DAT_007e094e;
extern s32 DAT_007e0958;
/* Retail accesses these flag words by absolute address. */
#pragma alias DAT_007e094e_abs DAT_007e094e
extern u8 DAT_007e094e_abs[];
#pragma alias DAT_007e0958_abs DAT_007e0958
extern u8 DAT_007e0958_abs[];
extern u32 DAT_00833a50[];
extern s32 iGpffffb258;
extern s32 uGpffffb290;
extern s32 uGpffffb28c;
extern s32 iGpffffb28c;

/* Data bridge globals initialized by FUN_0016C010/FUN_0016C2F0. */
typedef struct CampDataBridgeRoot CampDataBridgeRoot;
extern CampDataBridgeRoot* iGpffffb2c0;
#define DAT_007cdfb0 iGpffffb2c0
extern s32* DAT_007cdfb4;
extern s32* DAT_007cdfb8;
extern s32* DAT_007cdfbc;
extern s32* DAT_007cdfc0;
extern s32* DAT_007cdfc4;
extern s32* DAT_007cdfc8;
extern s32* DAT_007cdfcc;
extern s32* DAT_007cdfd0;
extern s32* DAT_007cdfd4;
extern s32* DAT_007cdfd8;
extern s32* DAT_007cdfdc;
extern u8* DAT_007cdfe0;
extern u8* DAT_007cdfe4;
extern void* DAT_007cdfe8;
extern u32 DAT_0083bb30;
extern u8 DAT_0083bb40;
extern u32 DAT_0083aaa0[0x23];
extern const char* PTR_s_help_datWeaponHelp_bmd_005e31d0[8];
extern const void* gp0xffff897c;
extern const void* gp0xffff8998;

/* Unresolved retail helpers. Old-style declarations preserve the mixed-width
 * call ABI recovered from the stripped executable. */
extern u32 FUN_00100d80();
extern u32 FUN_00100ec0();
extern u32 FUN_001016b0();
extern u64 FUN_00102100();
extern u32 FUN_001021c0();
extern u32 FUN_001023a0();
extern u32 FUN_0010a4e0();
extern u32 FUN_00111cb0();
extern u32 FUN_00111d50();
extern u32 FUN_00111dd0();
extern u32 FUN_00111ec0();
extern u32 FUN_00111ee0();
extern u32 FUN_00111f20();
extern u32 FUN_00111f30();
extern u32 FUN_00112420();
extern u32 FUN_001124b0();
extern u32 FUN_00113a30();
extern u32 FUN_00114450();
extern u32 FUN_001159f0();
#pragma alias FUN_001159f0_typed FUN_001159f0
extern void FUN_001159f0_typed(void* owner, void* atlas, s32 tile, u8 alpha,
                                f32 x, f32 y, f32 depth);
extern u32 FUN_00115bc0();
#pragma alias FUN_00115bc0_typed FUN_00115bc0
extern void FUN_00115bc0_typed(void* owner, void* atlas, s32 tile, u8 alpha,
                                u32 red, u32 green, u32 blue, f32 x, f32 y,
                                f32 depth);
extern u32 FUN_00115de0();
extern u32 FUN_00119f10();
extern u32 FUN_0011abd0();
extern u32 FUN_00122710();
extern u32 FUN_0012a560(f32, u64, void*, s32);
extern u32 FUN_0012ac60(f32, u64, void*, s32);
extern u32 FUN_00129b30(f32, u64, void*, s32);
extern u32 FUN_0013c240();
extern u32 FUN_0013c780();
extern u32 FUN_0013cf80();
extern u32 FUN_0013d1a0();
extern u32 FUN_0013fca0();
extern u32 FUN_0016f630();
extern u32 FUN_0016f720();
extern u32 FUN_0016f810();
extern u32 FUN_0016f900();
extern u32 FUN_0016f9f0();
extern u32 FUN_0016fae0();
extern u32 FUN_0016fbd0();
extern u32 FUN_0016fcc0();
extern u32 FUN_0016fea0();
extern u32 FUN_0016ff90();
extern u32 FUN_00170080();
extern u32 FUN_00170170();
extern u32 FUN_00170260();
extern u32 FUN_00170350();
extern u32 FUN_00170440();
extern u32 FUN_00170530();
extern u32 FUN_00170a40();
extern u32 FUN_00170ab0();
extern u32 FUN_00170b20();
extern u32 FUN_00170b90();
extern u32 FUN_00174800();
extern u32 FUN_00177c10();
extern u32 FUN_001830c0();
extern u32 FUN_00194b20();
extern u32 FUN_00195290();
extern void FUN_0019d3f0(const char*, s32);
extern u32 FUN_0021ea00();
extern u32 FUN_0025f370();
extern u32 FUN_0025f570();
extern u32 FUN_0035ed20();
extern u32 FUN_003b2cb0();
extern u32 FUN_003c7430();
extern u32 FUN_003c74e0();
extern u32 FUN_003c7560();
extern u32 FUN_003c7610();
extern u32 FUN_003c7700();
extern u32 FUN_003c7850();
extern u32 FUN_003c7d80();
extern u32 FUN_003c7e20();
extern u32 FUN_0040eb50();
extern u32 FUN_00521250();
extern u32 FUN_00523ac8();

extern void* func_00133780(KwlnTask* task);
extern void* func_001618a0(KwlnTask* task);
extern void func_00161d60(KwlnTask* task);
extern void* func_00166c70(KwlnTask* task);
extern void h_campPersonaDestroyDispCtlDrawTask(KwlnTask* task);
extern const char D_005DAC70[];
extern const char D_005DAC90[];
extern const char D_005DB190[];
extern const char D_005DBD80[];
extern const char D_005DBED0[];
extern const char D_005DBEE8[];
extern const char D_005DBF00[];
extern const char D_005DBF20[];
extern const char D_005DBF40[];
extern const char D_005DBF70[];
extern const char D_005DBFA0[];
extern const char D_005DBFD0[];
/* These task archive names are addressed absolutely by retail. */
#pragma alias D_005DBF20_abs D_005DBF20
extern u8 D_005DBF20_abs[];
#pragma alias D_005DBF40_abs D_005DBF40
extern u8 D_005DBF40_abs[];
#pragma alias D_005DBF70_abs D_005DBF70
extern u8 D_005DBF70_abs[];
#pragma alias D_005DBFA0_abs D_005DBFA0
extern u8 D_005DBFA0_abs[];
#pragma alias D_005DBFD0_abs D_005DBFD0
extern u8 D_005DBFD0_abs[];
extern const char D_005DC000[];
extern const char D_005E3098[];
extern const char D_005E30B0[];
extern const char D_005E31F0[];
extern const char D_005E3200[];

/* Target entry prototypes keep all callbacks visible before their first use. */
void FUN_001675b0(KwlnTask*);
void* FUN_001675e0(KwlnTask*);
void FUN_001678e0(KwlnTask*);
void* FUN_00167930(KwlnTask*);
void FUN_00167ec0(KwlnTask*);
void FUN_00167ef0(KwlnTask*);
void FUN_00167f10(KwlnTask*);
u32 FUN_00167f30(KwlnTask*);
KwlnTask* FUN_00167f40(KwlnTask*, u32, ulong, u16, u16, u16);
u32 FUN_00168040(void);
u32 FUN_00168100(void);
bool FUN_001681d0(void);
void* FUN_00168220(KwlnTask*);
bool FUN_001685b0(KwlnTask*);
u32 FUN_001685d0(KwlnTask*);
void FUN_001685e0(KwlnTask*, s32);
void FUN_00168720(KwlnTask*);
KwlnTask* FUN_00168770(KwlnTask*, u32);
u32 FUN_00168810(undefined8);
void FUN_00169040(int);
void FUN_00169110(undefined8, undefined8, undefined8, undefined8);
void FUN_001691F0(undefined8, undefined8, undefined8, undefined8, undefined8);
undefined4 FUN_00169330(void);
bool FUN_00169420(void);
undefined4 FUN_00169470(undefined8);
void FUN_00169AE0(int);
void FUN_00169B90(void* resources, undefined8 coordinates,
                  void* list, s32 alpha);
undefined4 FUN_0016A030(void);
undefined4 FUN_0016A6A0(void);
f32 FUN_0016ba00(u32, u32);
f32 FUN_0016ba80(u32, u32);
f32 FUN_0016bb00(u32, u32);
f32 FUN_0016bb80(u32, u32);
f32 FUN_0016bc00(u32, u32);
void FUN_0016bc80(u32, u32, f32*);
void FUN_0016bdb0(u32, u32, f32*);
void FUN_0016bee0(u32, u32, void*);
void FUN_0016bf80(u32, u32, void*) __attribute__((aligned(16)));
void FUN_0016c010(void) __attribute__((aligned(16)));
void FUN_0016c1d0(void);
void FUN_0016c2f0(void);
void FUN_0016a700(f32 depth, void* resources, undefined8 coordinates,
                  void* list, s32 alpha);
void FUN_0016af90(f32 depth, void* resources, undefined8 coordinates,
                  void* list, s32 alpha);


typedef struct CampBridgeScreenWork
{
    u32 state;          /* 0x00 */
    u32 timer;          /* 0x04 */
    u32 personaId;      /* 0x08 */
    u32 opacity;        /* 0x0c (low halfword used by the fade) */
    u32 fadeTimer;      /* 0x10 (low halfword used by the fade) */
    u32 command;        /* 0x14 */
    u32 active;         /* 0x18 */
    u32 transitionKind; /* 0x1c (low halfword used by the fade) */
    u32 reserved20;     /* 0x20 */
    u32 reserved24;     /* 0x24 */
    u32 childTask;      /* 0x28 */
} CampBridgeScreenWork;

/* Work area for the 0x14-byte state task (the first five words overlap the
 * screen work above but carry different meanings). */
typedef struct CampBridgeStateWork
{
    u32 state;          /* 0x00 */
    u32 mode;           /* 0x04 */
    u32 setupTask;      /* 0x08 */
    u32 activeTask;     /* 0x0c */
    u32 screenMode;     /* 0x10 */
} CampBridgeStateWork;

/* Work area allocated by FUN_00167930 for the persona display child. */
typedef struct CampBridgePersonaDispWork
{
    u32 state;          /* 0x00 */
    u32 personaId;      /* 0x04 */
    u32 reserved08;     /* 0x08 */
    u32 mode;           /* 0x0c */
    f32 alpha;          /* 0x10 */
    f32 slideStep;      /* 0x14 */
    f32 slidePosition;  /* 0x18 */
    f32 depth;          /* 0x1c */
    void* parseRequest; /* 0x20 */
    HCdvd* cdvd;        /* 0x24 */
    void* resource;     /* 0x28 */
} CampBridgePersonaDispWork;

/* Work area allocated by FUN_00168770 (0x1c bytes). */
typedef struct CampBridgeBlendWork
{
    u32 state;       /* 0x00 */
    s32 timer;       /* 0x04 */
    u32 reserved08;  /* 0x08 */
    u32 mode;        /* 0x0c */
    u32 archive;     /* 0x10 */
    u32 sourceTask;  /* 0x14 */
    u32 targetTask;  /* 0x18 */
} CampBridgeBlendWork;

typedef struct CampTargetListRecord
{
    s32 value;                /* +0x00 */
    s32 secondaryValue;       /* +0x04 */
    s32 selectedValue;        /* +0x08 */
    s32 flags;                /* +0x0c */
    s32 availability;         /* +0x10 (record +0x74 from table base) */
    u8 unused[0x10];          /* +0x14 */
} CampTargetListRecord;
/*
 * The item payload assembled for FUN_001830c0 is laid out exactly like the
 * Ghidra auStack_* locals: two halfwords, one word, two bytes, then four
 * halfwords (0x12 bytes total).
 */
typedef struct CampTargetItemRecord
{
    u16 itemId;                /* +0x00 */
    u16 reserved02;            /* +0x02 */
    u32 quantity;              /* +0x04 */
    u8 byte08;                 /* +0x08 */
    u8 byte09;                 /* +0x09 */
    u16 value0a;               /* +0x0a */
    u16 value0c;               /* +0x0c */
    u16 value0e;               /* +0x0e */
    u16 value10;               /* +0x10 */
} CampTargetItemRecord;

typedef struct CampTargetList
{
    u8 prefix[0x64];           /* +0x0000 */
    CampTargetListRecord records[0x140]; /* +0x0064 */
    s32 count;                 /* +0x2d64 */
    s32 cursor;                /* +0x2d68 */
    s32 selected;              /* +0x2d6c */
} CampTargetList;

/* Work area used by FUN_00168810/FUN_00169040. */
typedef struct CampTargetLoadWork
{
    u32 state;                 /* +0x00 */
    s32 frame;                 /* +0x04 */
    u32 reserved08;            /* +0x08 */
    u32 drawIdWord;            /* +0x0c (low half is the draw id) */
    void* archive;             /* +0x10 */
    void* resources[2];        /* +0x14 */
    CampTargetList* listA;     /* +0x1c */
    CampTargetList* listB;     /* +0x20 */
    void* childTask;           /* +0x24 */
} CampTargetLoadWork;

/* Work area used by FUN_00169470/FUN_00169AE0. */
typedef struct CampTargetMenuWork
{
    u32 state;                 /* +0x00 */
    s32 frame;                 /* +0x04 */
    u32 reserved08;            /* +0x08 */
    void* archive;             /* +0x0c */
    void* resources[2];        /* +0x10 */
    CampTargetList* list;      /* +0x18 */
    void* childTask;           /* +0x1c */
    u32 result;                /* +0x20 */
} CampTargetMenuWork;

typedef struct CampDataBridgeRecord
{
    s16 axis0;                 /* +0x00 */
    s16 axis1;                 /* +0x02 */
    s16 axis2;                 /* +0x04 */
    s16 axis3;                 /* +0x06 */
    f32 value;                 /* +0x08 */
    u32 reserved0c;            /* +0x0c */
    u16 reserved10;            /* +0x10 */
    s16 helpIndex;             /* +0x12 */
    u32 color0;                /* +0x14 */
    u32 color1;                /* +0x18 */
    u32 reserved1c;            /* +0x1c */
} CampDataBridgeRecord;

typedef struct CampDataBridgeGroup
{
    s32 recordCount;           /* +0x00 */
    s32 auxiliaryCount;        /* +0x04 */
    CampDataBridgeRecord* records; /* +0x08 */
    u8* auxiliaryData;         /* +0x0c */
} CampDataBridgeGroup;

typedef struct CampDataBridgeRoot
{
    CampDataBridgeGroup groups[2];
} CampDataBridgeRoot;

// FUN_001675b0
void FUN_001675b0(KwlnTask* task)
{
    (*DAT_0096017c_abs)(task->workData);
}

// FUN_001675e0 NONMATCHING
void* FUN_001675e0(KwlnTask* task)
{
    CampBridgeStateWork* work;
    s32 ready;
    work = (CampBridgeStateWork*)task->workData;
    switch (work->state) {
    case 0: {
        KwlnTask* child;
        datSetFlag(0x1407, 1);
        if (DAT_007cdf48 != 0) {
            child = 0;
        }
        else {
            void* allocated;

            allocated = (*DAT_00960184_abs)(1, 0x48, 0x40000);
            if (allocated == 0) {
                child = 0;
            }
            else {
                child = kwlnTaskCreate(task, D_005DAC70, 0x18bf,
                                     h_campUpdateSpriteSetupTask,
                                     h_campDestroySpriteSetupTask,
                                     allocated);
                if (child == 0) {
                    child = 0;
                }
                else {
                    DAT_007cdf48 = (void*)child;
                    *(u32*)((u8*)allocated + 0x3c) =
                        (u32)H_Cdvd_Request(D_005DAC90, 1);
                }
            }
        }
        work->setupTask = (u32)child;
        work->activeTask = (u32)FUN_00168770(task, 0x18bf);
        DAT_007cdf88 = (void*)work->activeTask;
        work->state = 1;
        break;
    }
    case 1: {
        s16 screenMode;
        void* allocated;

        ready = 1;
        if (DAT_007cdf48 == 0) {
            ready = -1;
        }
        else {
            if (*(u32*)((KwlnTask*)DAT_007cdf48)->workData != 3) {
                ready = 0;
            }
        }
        if ((ready != 0) && FUN_001685b0((KwlnTask*)work->activeTask)) {
            if (work->mode == 0) {
                s16 screenMode0;
                void* allocated0;
                screenMode0 = (s16)work->screenMode;
                allocated0 = (*DAT_00960184_abs)(1, 0x30, 0x40000);
                if (allocated0 == 0) {
                    work->activeTask = 0;
                }
                else {
                    work->activeTask = (u32)kwlnTaskCreate(
                        task, D_005DBD80, 0x18be,
                        func_001618a0,
                        func_00161d60,
                        allocated0);
                    if (work->activeTask != 0) {
                        *(u32*)((u8*)allocated0 + 0x0c) =
                            (u32)screenMode0;
                    }
                }
            }
            else {
                screenMode = (s16)work->screenMode;
                allocated = (*DAT_00960184_abs)(1, 0x48, 0x40000);
                if (allocated == 0) {
                    work->activeTask = 0;
                }
                else {
                    work->activeTask = (u32)kwlnTaskCreate(
                        task, D_005DBED0, 0x18be,
                        func_00166c70,
                        FUN_001675b0,
                        allocated);
                    if (work->activeTask != 0) {
                        *(u32*)((u8*)allocated + 0x0c) =
                            (u32)screenMode;
                    }
                }
            }
            work->state = 2;
        }
        break;
    }
    case 2:
        if (kwlnTaskGetState((KwlnTask*)work->activeTask) == 3) {
            return KWLNTASK_STOP;
        }
        break;
    default:
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_001678e0
void FUN_001678e0(KwlnTask* task)
{
    void* work;

    work = task->workData;
    DAT_007cdf88 = 0;
    datSetFlag(0x1407, 0);
    (*DAT_0096017c_abs)(work);
}

// FUN_00167930 NONMATCHING
void* FUN_00167930(KwlnTask* task)
{
    CampBridgeScreenWork* work;
    CampBridgePersonaDispWork* personaWork;
    bool complete;
    s16 value;
    s16 opacity;
    s16 screenMode;
    s16 transitionKind;
    s16 timer;
    u32 personaId;
    KwlnTask* child;
    s16 fadeValue;
    void* persona;

    work = (CampBridgeScreenWork*)task->workData;
    switch (work->state) {
    case 0:
        FUN_001685e0((KwlnTask*)DAT_007cdf88, 2);
        personaId = datGetPersonaId(*(s16*)((u8*)work + 0x0e));
        child = 0;
        personaWork = (CampBridgePersonaDispWork*)
            (*DAT_00960184)(1, 300, 0x40000);
        if (personaWork != 0) {
            child = kwlnTaskCreate(
                task, D_005DB190, 0x18bf,
                func_00133780,
                h_campPersonaDestroyDispCtlDrawTask,
                personaWork);
            if (child != 0) {
                personaWork->personaId = personaId;
                personaWork->mode = 0xffffffff;
                personaWork->alpha = 100.0f;
            }
        }
        work->childTask = (u32)child;
        work->state = 1;
        break;
    case 1:
        *(s16*)((u8*)work + 0x10) = 0;
        h_campRequestMenuTransition((KwlnTask*)DAT_007cdf54, 3);
        FUN_00122710((KwlnTask*)DAT_007cdf58, 3);
        work->state = 2;
        break;
    case 2:
        complete = false;
        personaWork = (CampBridgePersonaDispWork*)
            ((KwlnTask*)work->childTask)->workData;
        if ((personaWork->state == 3) && (personaWork->personaId != 0)) {
            if (personaWork->slidePosition != 60.0f) {
                personaWork->slidePosition -= personaWork->slideStep;
                personaWork->slideStep += 5.0f;
                if (personaWork->slidePosition < 60.0f) {
                    personaWork->slidePosition = 60.0f;
                }
            }
            FUN_00114450(personaWork->alpha, personaWork->slidePosition,
                         personaWork->depth, personaWork->mode,
                         0x4fa4ff19, 0x280, 0x280, personaWork->resource);
        }
        screenMode = *(s16*)((u8*)work + 0x12);
        transitionKind = *(s16*)((u8*)work + 0x1c);
        if (screenMode == 0) {
            timer = *(s16*)((u8*)work + 0x04);
            complete = timer == 0x14;
            if (!complete) {
                timer++;
                *(s16*)((u8*)work + 0x04) = timer;
            }
            value = *(s16*)((u8*)work + 0x04);
            persona = datPersonaGetByPcId(*(s16*)((u8*)work + 0x0e));
            FUN_00129b30(100.0f, 0, persona, value);
        }
        else {
            opacity = *(s16*)((u8*)work + 0x0c);
            if (opacity == 0xff) {
                complete = true;
            }
            else {
                opacity += 10;
                *(s16*)((u8*)work + 0x0c) = opacity;
                if (opacity > 0xff) {
                    *(s16*)((u8*)work + 0x0c) = 0xff;
                }
            }
            opacity = *(s16*)((u8*)work + 0x0c);
            persona = datPersonaGetByPcId(*(s16*)((u8*)work + 0x0e));
            FUN_0012ac60(100.0f, 0, persona, 0xff - opacity);
        }
        if (complete) {
            if (transitionKind == 0) {
                if ((*(u16*)DAT_007e094e_abs & 0x20) == 0) {
                    if (((*(u16*)DAT_007e094e_abs & 0x8000) != 0) ||
                        ((*(u16*)DAT_007e0958_abs & 0x8000) != 0)) {
                        func_0010a4e0(0, 0, 0, 0);
                        work->command = 1;
                    }
                }
                else {
                    func_0010a4e0(0, 0, 0, 2);
                    work->command = 0xffffffff;
                }
            }
            else if ((*(u16*)DAT_007e094e_abs & 0x20) == 0) {
                if (((*(u16*)DAT_007e094e_abs & 0x8000) == 0) &&
                    ((*(u16*)DAT_007e0958_abs & 0x8000) == 0)) {
                    if ((*(u16*)DAT_007e094e_abs & 8) == 0) {
                        if ((*(u16*)DAT_007e094e_abs & 4) != 0) {
                            func_0010a4e0(0, 0, 0, 0);
                            work->command = 3;
                        }
                    }
                    else {
                        func_0010a4e0(0, 0, 0, 0);
                        work->command = 2;
                    }
                }
                else {
                    func_0010a4e0(0, 0, 0, 0);
                    work->command = 1;
                }
            }
            else {
                func_0010a4e0(0, 0, 0, 2);
                work->command = 0xffffffff;
            }
        }
        break;
    case 3:
        opacity = *(s16*)((u8*)work + 0x0c) - 0x19;
        *(s16*)((u8*)work + 0x0c) = opacity;
        if (opacity < 0) {
            return KWLNTASK_STOP;
        }
        persona = datPersonaGetByPcId(*(s16*)((u8*)work + 0x0e));
        FUN_0012ac60(100.0f, 0, persona, 0xff - opacity);
        /* Retail intentionally falls through into case 4. */
    case 4:
        persona = datPersonaGetByPcId(*(s16*)((u8*)work + 0x0e));
        FUN_0012ac60(100.0f, 0, persona, 0);
        *(s16*)((u8*)work + 0x10) = 0;
        work->state = 5;
        break;
    case 5:
        timer = *(s16*)((u8*)work + 0x10);
        if (timer == 10) {
            return KWLNTASK_STOP;
        }
        timer++;
        *(s16*)((u8*)work + 0x10) = timer;
        persona = datPersonaGetByPcId(*(s16*)((u8*)work + 0x0e));
        fadeValue = timer;
        FUN_0012a560(100.0f, 0, persona, fadeValue);
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_00167ec0
void FUN_00167ec0(KwlnTask* task)
{
    (*DAT_0096017c_abs)(task->workData);
}

// FUN_00167EF0
void FUN_00167ef0(KwlnTask* task)
{
    u32* work;

    work = (u32*)task->workData;
    *(u16*)((u8*)work + 0x0c) = 0xff;
    work[0] = 3;
}

// FUN_00167F10
void FUN_00167f10(KwlnTask* task)
{
    u32* work;

    work = (u32*)task->workData;
    *(u16*)((u8*)work + 0x10) = 0;
    work[0] = 4;
}

// FUN_00167F30
u32 FUN_00167f30(KwlnTask* task)
{
    return ((u32*)task->workData)[5];
}

// FUN_00167f40 NONMATCHING
KwlnTask* FUN_00167f40(KwlnTask* parent, u32 priority, ulong packedValue,
                       u16 param4, u16 param5, u16 param6)
{
    CampBridgeScreenWork* work;
    KwlnTask* taskValue;

    work = (CampBridgeScreenWork*)(*DAT_00960184)(1, 0x2c, 0x40000);
    if (work == 0) {
        return 0;
    }
    taskValue = kwlnTaskCreate(parent, D_005DBF00, priority,
                             FUN_00167930,
                             FUN_00167ec0,
                             work);
    if (taskValue == 0) {
        return 0;
    }
    work->timer = (u32)packedValue;
    work->personaId = (u32)(packedValue >> 32);
    work->active = 1;
    *(u16*)((u8*)work + 0x0e) = param4;
    *(u16*)((u8*)work + 0x12) = param5;
    *(u16*)((u8*)work + 0x1c) = param6;
    return (KwlnTask*)taskValue;
}

// FUN_00168040
u32 FUN_00168040(void)
{
    s16 value;
    void* allocated;
    KwlnTask* taskValue;

    value = scrGetIntPara_u64(0);
    allocated = (*DAT_00960184_abs)(1, 0x14, 0x40000);
    if (allocated == 0) {
        taskValue = 0;
    }
    else {
        taskValue = kwlnTaskCreate(0, D_005DBEE8, 100,
                                 FUN_001675e0,
                                 FUN_001678e0,
                                 allocated);
        if (taskValue == 0) {
            taskValue = 0;
        }
        else {
            *(u16*)((u8*)allocated + 0x10) = value;
            *(u32*)((u8*)allocated + 4) = 0;
        }
    }
    DAT_007cdf84 = (void*)taskValue;
    return 1;
}

// FUN_00168100
u32 FUN_00168100(void)
{
    s16 value;
    void* allocated;
    KwlnTask* taskValue;

    value = (s16)scrGetIntPara(0);
    allocated = (*DAT_00960184_abs)(1, 0x14, 0x40000);
    if (allocated == 0) {
        taskValue = 0;
    }
    else {
        taskValue = kwlnTaskCreate(0, D_005DBEE8, 100,
                                 FUN_001675e0,
                                 FUN_001678e0,
                                 allocated);
        if (taskValue == 0) {
            taskValue = 0;
        }
        else {
            *(u16*)((u8*)allocated + 0x10) = value;
            *(u32*)((u8*)allocated + 4) = 1;
        }
    }
    DAT_007cdf84 = (void*)taskValue;
    return 1;
}

// FUN_001681d0
bool FUN_001681d0(void)
{
    u32 state;

    state = kwlnTaskGetState((KwlnTask*)DAT_007cdf84);
    if (state == 3) {
        DAT_007cdf84 = 0;
        return 1;
    }
    return 0;
}

// FUN_00168220 NONMATCHING
void* FUN_00168220(KwlnTask* task)
{
    CampBridgeBlendWork* work;
    u32 child;
    s32 frame;

    work = (CampBridgeBlendWork*)task->workData;
    switch (work->state) {
    case 0:
        work->archive = (u32)H_Cdvd_Request((const char*)D_005DBF20_abs, 1);
        work->state = 1;
        break;
    case 1:
        if (H_Cdvd_IsFileLoaded((HCdvd*)work->archive) != 0) {
            work->state = 2;
        }
        break;
    case 3:
        if (work->mode == 3) {
            goto camp_blend_mode3;
        }
        if (work->mode == 2) {
            goto camp_blend_mode2;
        }
        if (work->mode == 1) {
            goto camp_blend_mode1;
        }
        if (work->mode == 0) {
            goto camp_blend_mode0;
        }
        goto camp_blend_mode_done;

camp_blend_mode3:
        child = (u32)H_Maestro_CreateTask(task, 0x18bd,
                                          (const char*)D_005DBFD0_abs);
        work->targetTask = child;
        goto camp_blend_mode_done;
camp_blend_mode2:
        child = (u32)H_Maestro_CreateTask(task, 0x18bd,
                                          (const char*)D_005DBFA0_abs);
        work->targetTask = child;
        goto camp_blend_mode_done;
camp_blend_mode1:
        child = (u32)H_Maestro_CreateTask(task, 0x18bd,
                                          (const char*)D_005DBF70_abs);
        work->targetTask = child;
        goto camp_blend_mode_done;
camp_blend_mode0:
        child = (u32)H_Maestro_CreateTask(task, 0x18bd,
                                          (const char*)D_005DBF40_abs);
        work->targetTask = child;
        goto camp_blend_mode_done;
camp_blend_mode_done:
        work->timer = 0;
        work->state = 4;
        break;
    case 4:
        if (H_Maestro_FinishedInit((KwlnTask*)work->targetTask) == 1) {
            func_0010a4e0(0, 0, 0, 5);
            H_Maestro_RequestDraw((KwlnTask*)work->targetTask);
            H_Maestro_00111f20((KwlnTask*)work->targetTask, 1);
            work->state = 5;
        }
        break;
    case 5:
        if (work->mode == 3) {
            if (work->timer != 10) {
                work->timer++;
            }
            H_Maestro_SetAlphaMult((KwlnTask*)work->sourceTask,
                         1.0f - (f32)(s32)work->timer / 10.0f);
        }
        if (H_Maestro_00111cb0((KwlnTask*)work->targetTask) != 0) {
            if (work->mode == 3) {
                H_Maestro_SetAlphaMult((KwlnTask*)work->sourceTask, 0.0f);
            }
            else {
                if (work->sourceTask != 0) {
                    kwlnTaskDestroyWithHierarchy((KwlnTask*)work->sourceTask);
                }
                work->sourceTask = work->targetTask;
                work->targetTask = 0;
            }
            work->state = 2;
        }
        break;
    case 6:
        frame = (s32)work->timer - 1;
        work->timer = (u32)frame;
        if (frame == 0) {
            return KWLNTASK_STOP;
        }
        H_Maestro_SetAlphaMult((KwlnTask*)work->sourceTask,
                     (f32)frame / 10.0f);
        break;
    case 7:
        frame = (s32)work->timer - 1;
        work->timer = (u32)frame;
        if (frame == 0) {
            if (work->targetTask != 0) {
                kwlnTaskDestroyWithHierarchy((KwlnTask*)work->targetTask);
            }
            H_Maestro_SetAlphaMult((KwlnTask*)work->sourceTask, 1.0f);
            work->targetTask = 0;
            work->state = 2;
        }
        else {
            H_Maestro_SetAlphaMult((KwlnTask*)work->targetTask,
                         (f32)frame / 10.0f);
            H_Maestro_SetAlphaMult((KwlnTask*)work->sourceTask,
                         1.0f - (f32)frame / 10.0f);
        }
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_001685B0
bool FUN_001685b0(KwlnTask* task)
{
    return *(u32*)task->workData == 2;
}

// FUN_001685D0
u32 FUN_001685d0(KwlnTask* task)
{
    return ((u32*)task->workData)[2];
}

// FUN_001685e0 NONMATCHING
void FUN_001685e0(KwlnTask* task, s32 command)
{
    u32* work;
    s32 state;

    work = (u32*)task->workData;
    state = (s32)work[2];
    if (state == 4) {
        work[1] = 10;
        work[0] = 7;
        work[2] = (u32)command;
    }
    else if (state == 2) {
        if (command == 3) {
            work[1] = 10;
            work[0] = 6;
        }
        else if ((command != 2) && (command == 1)) {
            work[3] = 2;
            work[0] = 3;
        }
        work[2] = (u32)command;
    }
    else if (state == 1) {
        if (command == 4) {
            work[3] = 3;
            work[0] = 3;
        }
        else if (command == 3) {
            work[1] = 10;
            work[0] = 6;
        }
        else if (command == 2) {
            work[3] = 1;
            work[0] = 3;
        }
        work[2] = (u32)command;
    }
    else if ((state == 0) && (command == 1)) {
        work[3] = 0;
        work[0] = 3;
        work[2] = 1;
    }
}

// FUN_00168720
void FUN_00168720(KwlnTask* task)
{
    u32* work;

    work = (u32*)task->workData;
    if (work[4] != 0) {
        H_Cdvd_Destroy((HCdvd*)work[4]);
    }
    work[4] = 0;
    (*DAT_0096017c_abs)(work);
}

// FUN_00168770
KwlnTask* FUN_00168770(KwlnTask* parent, u32 priority)
{
    void* work;
    KwlnTask* taskValue;

    work = (*DAT_00960184_abs)(1, 0x1c, 0x40000);
    if (work == 0) {
        return 0;
    }
    taskValue = kwlnTaskCreate(parent, D_005DC000, priority,
                             FUN_00168220,
                             FUN_00168720,
                             work);
    if (taskValue == 0) {
        return 0;
    }
    return (KwlnTask*)taskValue;
}




// FUN_00168810 NONMATCHING
undefined4 FUN_00168810(undefined8 param_1)
{
    KwlnTask* task;
    CampTargetLoadWork* work;
    u8 readyScratch[4];
    s32 i;
    s32 entry;
    s32 nextFrame;
    s32 phase;
    bool ready;
    u32 resource;

    task = (KwlnTask*)(uintptr_t)param_1;
    work = (CampTargetLoadWork*)task->workData;
    switch (work->state) {
    case 0:
        if (FUN_001016b0(work->archive) != 0) {
            work->resources[0] = (void*)(uintptr_t)FUN_00112420(
                FUN_00102100(work->archive, 0, readyScratch));
            work->resources[1] = (void*)(uintptr_t)FUN_00112420(
                FUN_00102100(work->archive, 1, readyScratch));
            work->childTask = (void*)(uintptr_t)FUN_00119f10(param_1, 1);
            DAT_00833a50[0] = (u32)(uintptr_t)work->resources[0];
            DAT_00833a50[1] = (u32)(uintptr_t)work->resources[1];
            work->state = 1;
        }
        break;

    case 1:
        ready = true;
        for (i = 0; i < 2; i++) {
            if (work->resources[i] != NULL && FUN_00111f30() == 0) {
                ready = false;
            }
        }
        if (iGpffffb258 == 0) {
            phase = -1;
        } else if (*(s32*)(*(u32*)((u8*)(uintptr_t)iGpffffb258 + 0x3c)) == 3) {
            phase = 1;
        } else {
            phase = 0;
        }
        if (phase == 1 && ready) {
            work->frame = 0;
            resource = (u32)(uintptr_t)(*DAT_00960184)(1, 0x2d70, 0x40000);
            for (entry = 0; entry < 0x140; entry++) {
                s32 record = (s32)resource + entry * 0x24;
                *(u32*)(record + 0x64) = 0xffffffff;
                *(u32*)(record + 0x6c) = 0;
                *(u32*)(record + 0x68) = 0xffffffff;
                *(u32*)(record + 0x70) = 0;
            }
            work->listA = (CampTargetList*)(uintptr_t)resource;
            resource = (u32)(uintptr_t)(*DAT_00960184)(1, 0x2d70, 0x40000);
            for (entry = 0; entry < 0x140; entry++) {
                s32 record = (s32)resource + entry * 0x24;
                *(u32*)(record + 0x64) = 0xffffffff;
                *(u32*)(record + 0x6c) = 0;
                *(u32*)(record + 0x68) = 0xffffffff;
                *(u32*)(record + 0x70) = 0;
            }
            work->listB = (CampTargetList*)(uintptr_t)resource;
            FUN_0013cf80(work->drawIdWord, work->listA);
            work->state = 2;
        }
        break;

    case 2:
        nextFrame = work->frame + 1;
        work->frame = nextFrame;
        if (nextFrame > 9) {
            work->state = 3;
        }
        FUN_00169110((undefined8)(u16)work->drawIdWord, 0,
                     CAMP_PTR64(work->listA),
                     (undefined8)(0xff - (work->frame * 0xff) / 10));
        break;

    case 3:
        if ((DAT_007e094e & 0x20) == 0) {
            if ((DAT_007e094e & 0x40) == 0) {
                CampTargetList* list = work->listA;
                FUN_0011abd0(list->count, 5, &list->selected, &list->cursor);
            } else {
                FUN_0010a4e0(0, 0, 0, 1);
                FUN_0013c240(work->listB, (u16)work->drawIdWord,
                             work->listA->cursor);
                if (work->listB->count == 0) {
                    FUN_003c7430(4);
                    work->state = 5;
                } else {
                    work->state = 4;
                }
            }
        } else {
            FUN_0010a4e0(0, 0, 0, 2);
            work->state = 6;
        }
        FUN_00169110((undefined8)(u16)work->drawIdWord, 0,
                     CAMP_PTR64(work->listA), 0);
        break;

    case 4:
        if ((DAT_007e094e & 0x20) == 0) {
            if ((DAT_007e094e & 0x40) == 0) {
                CampTargetList* list = work->listB;
                FUN_0011abd0(list->count, 5, &list->selected, &list->cursor);
            } else {
                u32 sourceId;
                u32 destinationId;
                undefined8 sourceValue6;
                undefined8 sourceValue7;
                undefined8 sourceValue8;
                undefined8 sourceValue9;
                undefined8 sourceValueA;
                undefined8 sourceValueB;
                undefined8 sourceValueC;
                undefined8 sourceValueD;
                undefined8 destinationValue;
                u16 drawId = (u16)work->drawIdWord;

                FUN_0010a4e0(0, 0, 0, 1);
                sourceId = (u32)work->listA->records[work->listA->cursor].secondaryValue;
                destinationId = (u32)work->listB->records[
                    work->listB->cursor + work->listB->selected].secondaryValue;
                sourceValue6 = FUN_0016f630(drawId, sourceId);
                sourceValue7 = FUN_0016f720(drawId, sourceId);
                sourceValue8 = FUN_0016f810(drawId, sourceId);
                sourceValue9 = FUN_0016f900(drawId, sourceId);
                sourceValueA = FUN_0016f9f0(drawId, sourceId);
                sourceValueB = FUN_0016fae0(drawId, sourceId);
                sourceValueC = FUN_0016fbd0(drawId, sourceId);
                sourceValueD = FUN_0016fcc0(drawId, sourceId);
                destinationValue = FUN_0016f630(1, destinationId);
                FUN_0016fea0(drawId, sourceId, destinationValue);
                destinationValue = FUN_0016f720(1, destinationId);
                FUN_0016ff90(drawId, sourceId, destinationValue);
                destinationValue = FUN_0016f810(1, destinationId);
                FUN_00170080(drawId, sourceId, destinationValue);
                destinationValue = FUN_0016f900(1, destinationId);
                FUN_00170170(drawId, sourceId, destinationValue);
                destinationValue = FUN_0016fae0(1, destinationId);
                FUN_00170350(drawId, sourceId, destinationValue);
                destinationValue = FUN_0016fbd0(1, destinationId);
                FUN_00170440(drawId, sourceId, destinationValue);
                destinationValue = FUN_0016fcc0(1, destinationId);
                FUN_00170530(drawId, sourceId, destinationValue);
                destinationValue = FUN_0016f9f0(1, destinationId);
                FUN_00170260(drawId, sourceId, destinationValue);
                FUN_0016fea0(1, destinationId, sourceValue6);
                FUN_0016ff90(1, destinationId, sourceValue7);
                FUN_00170080(1, destinationId, sourceValue8);
                FUN_00170170(1, destinationId, sourceValue9);
                FUN_00170350(1, destinationId, sourceValueB);
                FUN_00170440(1, destinationId, sourceValueC);
                FUN_00170530(1, destinationId, sourceValueD);
                FUN_00170260(1, destinationId, sourceValueA);
                FUN_00177c10(work->drawIdWord, sourceId);
                FUN_0013cf80(work->drawIdWord, work->listA);
                work->state = 3;
            }
        } else {
            FUN_0010a4e0(0, 0, 0, 2);
            work->state = 3;
        }
        FUN_001691F0((undefined8)(u16)work->drawIdWord, 0,
                     CAMP_PTR64(work->listA), CAMP_PTR64(work->listB), 0);
        break;

    case 5:
        if (FUN_003c7850() == 0) {
            FUN_003c7700();
            work->state = 3;
        }
        FUN_00169110((undefined8)(u16)work->drawIdWord, 0,
                     CAMP_PTR64(work->listA), 0);
        break;

    case 6:
        nextFrame = work->frame - 1;
        work->frame = nextFrame;
        if (nextFrame < 1) {
            work->state = 7;
        }
        FUN_00169110((undefined8)(u16)work->drawIdWord, 0,
                     CAMP_PTR64(work->listA),
                     (undefined8)(0xff - (work->frame * 0xff) / 10));
        break;

    case 7:
        return 0xffffffff;
    }
    return 0;
}

// FUN_00169040
void FUN_00169040(int param_1)
{
    CampTargetLoadWork* work;
    s32 i;

    work = (CampTargetLoadWork*)(*(u32*)((u8*)(uintptr_t)param_1 + 0x3c));
    if (work->listA != NULL) {
        (*(void (**)(...))0x0096017c)(work->listA);
        work->listA = NULL;
    }
    if (work->listB != NULL) {
        (*(void (**)(...))0x0096017c)(work->listB);
        work->listB = NULL;
    }
    for (i = 0; i < 2; i++) {
        if ((*(void**)((u8*)work + 0x14 + i * 4)) != NULL) {
            FUN_001124b0(*(void**)((u8*)work + 0x14 + i * 4));
        }
        DAT_00833a50[i] = 0;
    }
    (*(void (**)(...))0x0096017c)(work);
}

// FUN_00169110 NONMATCHING
void FUN_00169110(undefined8 param_1, undefined8 param_2,
                  undefined8 param_3, undefined8 param_4)
{
    f32 x;
    f32 y;
    f32 depth;
    y = (f32)((undefined8)param_2 >> 0x20);
    x = (f32)param_2;
    depth = (f32)FUN_0021ea00(0x29);
    FUN_00113a30(DAT_00960088 - depth, 0, 0,
                 0xffU - (u32)param_4 | 0x20808000, 0x280, 0x1c0);
    depth = (f32)FUN_0021ea00(0x28);
    FUN_0013d1a0(DAT_00960088 - depth,
                 (((undefined8)(u32)(y + 50.0)) << 32) | (u32)(x + 40.0),
                 param_3, param_4);
}

// FUN_001691F0 NONMATCHING
void FUN_001691F0(undefined8 param_1, undefined8 param_2,
                  undefined8 param_3, undefined8 param_4,
                  undefined8 param_5)
{
    f32 x;
    f32 y;
    f32 depth;
    y = (f32)((undefined8)param_2 >> 0x20);

    depth = (f32)FUN_0021ea00(0x29);
    FUN_00113a30(DAT_00960088 - depth, 0, 0,
                 0xffU - (u32)param_5 | 0x20808000, 0x280, 0x1c0);
    x = (f32)param_2;
    depth = y + 50.0;
    depth = (f32)FUN_0021ea00(0x28);
    FUN_0013fca0(DAT_00960088 - depth,
                 (((undefined8)(u32)(y + 50.0)) << 32) | (u32)(x + 40.0),
                 param_3, param_5);
    depth = (f32)FUN_0021ea00(0x28);
    FUN_0013d1a0(DAT_00960088 - depth,
                 (((undefined8)(u32)(y + 80.0)) << 32) | (u32)(x + 40.0),
                 param_4, param_5);
}

// FUN_00169330 NONMATCHING
undefined4 FUN_00169330(void)
{
    void* allocation;
    void* task;
    s16 language;

    language = (s16)FUN_0035ed20(0);
    allocation = (*DAT_00960184_abs)(1, 0x28, 0x40000);
    if (allocation == NULL) {
        task = NULL;
    } else {
        task = (void*)FUN_00194b20(0, 0x5dc020, 0x18bf,
                                   FUN_00168810, FUN_00169040, allocation);
        if (task == NULL) {
            task = NULL;
        } else {
            *(s32*)((u8*)allocation + 0x0c) = language;
            *(u32*)((u8*)allocation + 0x10) = FUN_00100d80(0x5dbc60, 1);
        }
    }
    uGpffffb290 = (s32)(uintptr_t)task;
    return 1;
}

// FUN_00169420
bool FUN_00169420(void)
{
    s32 state;

    state = FUN_00195290(uGpffffb290);
    if (state == 3) {
        uGpffffb290 = 0;
        return 1;
    }
    return 0;
}

// FUN_00169470 NONMATCHING
undefined4 FUN_00169470(undefined8 param_1)
{
    KwlnTask* task;
    CampTargetMenuWork* work;
    u8 readyScratch[4];
    bool ready;
    s32 i;
    s32 entry;
    s32 nextFrame;
    s16 itemId;
    u32 stackHeaderA;
    u32 stackHeaderB;
    CampTargetItemRecord itemRecord;

    task = (KwlnTask*)(uintptr_t)param_1;
    work = (CampTargetMenuWork*)task->workData;
    switch (work->state) {
    case 0:
        if (FUN_001016b0(work->archive) != 0) {
            work->resources[0] = (void*)(uintptr_t)FUN_00112420(
                FUN_00102100(work->archive, 0, readyScratch));
            work->resources[1] = (void*)(uintptr_t)FUN_00112420(
                FUN_00102100(work->archive, 1, readyScratch));
            work->childTask = (void*)(uintptr_t)FUN_00119f10(param_1, 1);
            work->state = 1;
        }
        break;
    case 1:
        ready = true;
        for (i = 0; i < 2; i++) {
            if (work->resources[i] != NULL && FUN_00111f30() == 0) {
                ready = false;
            }
        }
        if (ready) {
            work->frame = 0;
            work->list = (CampTargetList*)(uintptr_t)(*DAT_00960184)(1, 0x2d70, 0x40000);
            for (entry = 0; entry < 0x140; entry++) {
                s32 record = (s32)(uintptr_t)work->list + entry * 0x24;
                *(u32*)(record + 0x64) = 0xffffffff;
                *(u32*)(record + 0x6c) = 0;
                *(u32*)(record + 0x68) = 0xffffffff;
                *(u32*)(record + 0x70) = 0;
            }
            FUN_0013c780(work->list);
            work->state = 2;
        }
        break;
    case 2:
        nextFrame = work->frame + 1;
        work->frame = nextFrame;
        if (nextFrame > 0x13) {
            work->state = 3;
        }
        stackHeaderA = 0;
        stackHeaderB = 0;
        FUN_00169B90(work->resources, 0, work->list,
                     (s32)(0xff - (work->frame * 0xff) / 0x14));
        break;
    case 3:
        if ((DAT_007e094e & 0x40) == 0) {
            s32 selected = work->list->selected;
            s32 cursor = work->list->cursor;
            FUN_0011abd0(work->list->count, 6, &selected, &cursor);
            work->list->selected = selected;
            work->list->cursor = cursor;
        } else {
            FUN_0010a4e0(0, 0, 0, 1);
            if (work->list->records[
                    work->list->cursor + work->list->selected].availability == 0) {
                FUN_003c7430(6);
                work->state = 5;
            } else {
                FUN_003c7430(5);
                FUN_003c74e0(0);
                FUN_003c7560(0);
                work->state = 4;
            }
        }
        stackHeaderA = 0;
        stackHeaderB = 0;
        FUN_00169B90(work->resources, 0, work->list, 0);
        break;
    case 4:
        if (FUN_003c7850() == 0) {
            s32 waitState = FUN_003c7610();
            if (waitState != 1 && waitState == 0) {
                s32 current = work->list->records[
                    work->list->cursor + work->list->selected].secondaryValue;
                s32 selected = work->list->selected;
                s32 cursor = work->list->cursor;

                if (current < 0x1000) {
                    FUN_0016fea0(1, current, 0);
                } else {
                    FUN_0016fea0(0xffffffffffffffffULL, current - 0x1000, 0);
                }
                FUN_0013c780();
                if (work->list->count < 6) {
                    work->list->selected = 0;
                    current = work->list->count - 1;
                    if (current < cursor) {
                        work->list->cursor = current;
                    } else {
                        work->list->cursor = cursor;
                    }
                } else {
                    current = work->list->count - 6;
                    if (current < selected) {
                        work->list->selected = current;
                        work->list->cursor = cursor;
                    }
                }
            }
            FUN_003c7700();
            if (work->list->count < 0x12d) {
                for (i = 0; i < 0x14; i++) {
                    itemId = (s16)FUN_0016f630(0xffffffffffffffffULL, i);
                    if (itemId != 0) {
                        itemRecord.itemId = (u16)FUN_0016f630(0xffffffffffffffffULL, i);
                        itemRecord.quantity = FUN_0016f720(0xffffffffffffffffULL, i);
                        itemRecord.byte08 = (u8)FUN_0016f810(0xffffffffffffffffULL, i);
                        itemRecord.byte09 = (u8)FUN_0016f900(0xffffffffffffffffULL, i);
                        itemRecord.value0a = (u16)FUN_0016f9f0(0xffffffffffffffffULL, i);
                        itemRecord.value0c = (u16)FUN_0016fae0(0xffffffffffffffffULL, i);
                        itemRecord.value0e = (u16)FUN_0016fbd0(0xffffffffffffffffULL, i);
                        itemRecord.value10 = (u16)FUN_0016fcc0(0xffffffffffffffffULL, i);
                        FUN_0016fea0(0xffffffffffffffffULL, i, 0);
                        FUN_001830c0(&itemRecord);
                    }
                }
                FUN_0025f570();
                work->frame = 10;
                work->state = 6;
            } else {
                work->state = 3;
            }
        }
        stackHeaderA = 0;
        stackHeaderB = 0;
        FUN_00169B90(work->resources, 0, work->list, 0);
        break;
    case 5:
        if (FUN_003c7850() == 0) {
            FUN_003c7700();
            work->state = 3;
        }
        stackHeaderA = 0;
        stackHeaderB = 0;
        FUN_00169B90(work->resources, 0, work->list, 0);
        break;
    case 6:
        nextFrame = work->frame - 1;
        work->frame = nextFrame;
        if (nextFrame < 1) {
            work->state = 7;
        }
        stackHeaderA = 0;
        stackHeaderB = 0;
        FUN_00169B90(work->resources, 0, work->list,
                     (s32)(0xff - (work->frame * 0xff) / 10));
        break;
    case 7:
        return 0xffffffff;
    }
    return 0;
}

// FUN_00169AE0
void FUN_00169AE0(int param_1)
{
    CampTargetMenuWork* work;
    s32 i;

    work = (CampTargetMenuWork*)(*(u32*)((u8*)(uintptr_t)param_1 + 0x3c));
    if (work->list != NULL) {
        (*DAT_0096017c_abs)(work->list);
        work->list = NULL;
    }
    for (i = 0; i < 2; i++) {
        if (*(void**)((u8*)work + 0x10 + i * 4) != NULL) {
            FUN_001124b0(*(void**)((u8*)work + 0x10 + i * 4));
        }
    }
    if (*(void**)((u8*)work + 0x0c) != NULL) {
        FUN_00100ec0(*(void**)((u8*)work + 0x0c));
    }
    work->archive = NULL;
    (*DAT_0096017c_abs)(work);
}

// FUN_00169B90 NONMATCHING
void FUN_00169B90(void* param_1, undefined8 param_2,
                  void* param_3, s32 param_4)
{
    f32 x;
    f32 y;
    f32 depth;
    f32 drawY;

    y = *(f32*)((u8*)&param_2 + 4);
    x = *(f32*)&param_2;
    depth = (f32)FUN_0021ea00(0x28);
    FUN_0016a700(DAT_00960088 - depth, param_1, param_2, param_3, param_4);
    depth = (f32)FUN_0021ea00(0x28);
    FUN_0016af90(DAT_00960088 - depth, param_1, param_2, param_3, param_4);
    drawY = y + 18.0f;
    depth = (f32)FUN_0021ea00(0x28);
    FUN_001159f0(x + 240.0f, drawY, DAT_00960088 - depth);
    depth = (f32)FUN_0021ea00(0x28);
    FUN_001159f0(x + 416.0f, drawY, DAT_00960088 - depth);
    drawY = x + 468.0f;
    depth = (f32)FUN_0021ea00(0x28);
    FUN_001159f0(drawY, y + 408.0f, DAT_00960088 - depth);
    depth = (f32)FUN_0021ea00(0x28);
    FUN_001159f0(x + 386.0f, y + 379.0f, DAT_00960088 - depth);
    {
        s32 count = ((CampTargetList*)(uintptr_t)param_3)->count;
        if (count >= 100) {
            depth = (f32)FUN_0021ea00(0x28);
            FUN_00115bc0(drawY, y + 384.0f, DAT_00960088 - depth);
        }
        if (count >= 10) {
            depth = (f32)FUN_0021ea00(0x28);
            FUN_00115bc0(x + 495.0f, y + 384.0f, DAT_00960088 - depth);
        }
    }
    depth = (f32)FUN_0021ea00(0x28);
    FUN_00115bc0(x + 522.0f, y + 384.0f, DAT_00960088 - depth);
    y += 404.0f;
    depth = (f32)FUN_0021ea00(0x28);
    FUN_00115de0(x + 565.0f, y, DAT_00960088 - depth);
    depth = (f32)FUN_0021ea00(0x28);
    FUN_00115de0(x + 584.0f, y, DAT_00960088 - depth);
    depth = (f32)FUN_0021ea00(0x28);
    FUN_00115de0(x + 603.0f, y, DAT_00960088 - depth);
}

// FUN_0016A030 NONMATCHING
undefined4 FUN_0016A030(void)
{
    u16 itemId;
    u16 source;
    s16 category;
    u32 amount;
    u32 secondaryAmount;
    u32 resource;
    s32 mode;
    undefined8 packed;
    u16 item;
    u16 itemIndex;
    u16 slot;
    s32 i;
    s32 sourceCount;
    s32 generatedCount;
    s32 lastMode;
    CampTargetItemRecord itemRecord;

    mode = FUN_0035ed20(0);
    if (mode == 1) {
        lastMode = -1;
        source = 0xffff;
        for (i = 0; i < 300; i++) {
            category = (s16)i;
            itemId = (u16)func_00170760(0xffff, category + 4000);
            if (itemId != 0) {
                amount = func_00170760(0xffff, category + 4000);
                secondaryAmount = func_00170760(1, category + 4000);
                amount = (amount & 0xffff) + (secondaryAmount & 0xffff);
                if (amount > 99) {
                    amount = 99;
                }
                func_00170860(1, category + 4000, amount & 0xffff);
                func_00170860(0xffff, category + 4000, 0);
            }
        }
    } else {
        lastMode = mode + 0x100;
        source = (u16)lastMode;
        for (i = 0; i < 0x14; i++) {
            item = (u16)mode;
            slot = (u16)i;
            itemIndex = (u16)FUN_00170a40(item, slot);
            if (itemIndex != 0 && FUN_00170ab0(item, slot) != 0) {
                category = (s16)FUN_00170ab0(item, slot);
                amount = func_00170760(1, itemIndex);
                amount = (u32)category + (amount & 0xffff);
                if ((s32)amount > 99) {
                    amount = 99;
                }
                func_00170860(1, itemIndex, amount & 0xffff);
                FUN_00170b20((u16)mode, (u16)i, 0);
                FUN_00170b90((u16)mode, (u16)i, 0);
            }
        }
    }

    sourceCount = 0;
    for (i = 0; i < 0x14; i++) {
        if ((u16)FUN_0016f630(source, i) != 0) {
            sourceCount++;
        }
    }
    generatedCount = 0;
    for (i = 0; i < 300; i++) {
        if ((u16)FUN_0016f630(1, i) != 0) {
            generatedCount++;
        }
    }
    if (sourceCount + generatedCount < 0x12d) {
        for (lastMode = 0; lastMode < 0x14; lastMode++) {
            itemId = (u16)FUN_0016f630(source, lastMode);
            if (itemId != 0) {
                itemRecord.itemId = (u16)FUN_0016f630(source, lastMode);
                itemRecord.quantity = FUN_0016f720(source, lastMode);
                itemRecord.byte08 = (u8)FUN_0016f810(source, lastMode);
                itemRecord.byte09 = (u8)FUN_0016f900(source, lastMode);
                itemRecord.value0a = (u16)FUN_0016f9f0(source, lastMode);
                itemRecord.value0c = (u16)FUN_0016fae0(source, lastMode);
                itemRecord.value0e = (u16)FUN_0016fbd0(source, lastMode);
                itemRecord.value10 = (u16)FUN_0016fcc0(source, lastMode);
                FUN_0016fea0(source, lastMode, 0);
                FUN_001830c0(&itemRecord);
            }
        }
        uGpffffb28c = 0;
    } else {
        if (lastMode != -1) {
            for (lastMode = 0; lastMode < 0x14; lastMode++) {
                itemId = (u16)FUN_0016f630(source, lastMode);
                if (itemId != 0) {
                    packed = FUN_0016f630(source, lastMode);
                    FUN_0016fea0(0xffffffffffffffffULL, lastMode, packed);
                    packed = FUN_0016f720(source, lastMode);
                    FUN_0016ff90(0xffffffffffffffffULL, lastMode, packed);
                    packed = FUN_0016f810(source, lastMode);
                    FUN_00170080(0xffffffffffffffffULL, lastMode, packed);
                    packed = FUN_0016f900(source, lastMode);
                    FUN_00170170(0xffffffffffffffffULL, lastMode, packed);
                    packed = FUN_0016f9f0(source, lastMode);
                    FUN_00170260(0xffffffffffffffffULL, lastMode, packed);
                    packed = FUN_0016fae0(source, lastMode);
                    FUN_00170350(0xffffffffffffffffULL, lastMode, packed);
                    packed = FUN_0016fbd0(source, lastMode);
                    FUN_00170440(0xffffffffffffffffULL, lastMode, packed);
                    packed = FUN_0016fcc0(source, lastMode);
                    FUN_00170530(0xffffffffffffffffULL, lastMode, packed);
                    FUN_0016fea0(source, lastMode, 0);
                }
            }
        }
        resource = (u32)(uintptr_t)(*DAT_00960184)(1, 0x24, 0x40000);
        if (resource == 0) {
            uGpffffb28c = 0;
        } else {
            uGpffffb28c = (s32)(uintptr_t)FUN_00194b20(
                0, 0x5dc020, 0x18bf, FUN_00169470, FUN_00169AE0,
                (void*)(uintptr_t)resource);
            if (uGpffffb28c != 0) {
                *(u32*)(resource + 0x0c) = FUN_00100d80(0x5dc030, 1);
            }
        }
    }
    return 1;
}

// FUN_0016A6A0
undefined4 FUN_0016A6A0(void)
{
    s32 state;

    if (iGpffffb28c == 0) {
        return 1;
    }
    state = FUN_00195290(iGpffffb28c);
    if (state == 3) {
        iGpffffb28c = 0;
        return 1;
    }
    return 0;
}


// FUN_0016A700 NONMATCHING
void FUN_0016a700(f32 param_1, void* param_2, undefined8 param_3,
                  void* param_4, s32 param_5)
{
    f32 x;
    f32 y;
    f32 rowY;
    f32 spriteX;
    f32 textX;
    f32 textY;
    f32 selectedY;
    s32 i;
    s32 row;
    s32 visibleCount;
    s32 totalCount;
    s32 selected;
    u32 type;
    u32 spriteCode;
    u32 textAlpha;
    u32 textId;
    u32* drawData;
    undefined1 text[0x100];

    x = *(f32*)((u8*)&param_3 + 4);
    y = *(f32*)&param_3;
    drawData = (u32*)param_2;
    textAlpha = 0xffU - (u32)param_5;

    /* The six-argument form preserves the texture/sprite selectors carried
     * in the otherwise untyped retail calls. */
    FUN_001159f0(x + 541.0f, y + 38.0f, param_1, drawData[1], 0x44, param_5);
    FUN_001159f0(x + 541.0f, y + 235.0f, param_1, drawData[1], 0x45, param_5);

    visibleCount = *(s32*)((u8*)param_4 + 0x2d64) - 6;
    if (visibleCount < 1) {
        visibleCount = 0;
    } else {
        visibleCount = (*(s32*)((u8*)param_4 + 0x2d6c) * 0x97) / visibleCount;
    }
    FUN_001159f0(x + 541.0f, y + 43.0f + (f32)visibleCount,
                 param_1, drawData[1], 0x46, param_5);

    selected = *(s32*)((u8*)param_4 + 0x2d68);
    totalCount = *(s32*)((u8*)param_4 + 0x2d64);
    row = *(s32*)((u8*)param_4 + 0x2d6c);
    rowY = y + 43.0f;
    selectedY = y + 61.0f;
    spriteX = x + 196.0f;
    textX = x + 246.0f;
    textY = x + 525.0f;

    for (i = 0; i < 6; i++) {
        s32 recordIndex;
        s32 hasRecord;
        f32 itemY;

        recordIndex = row + i;
        hasRecord = *(s32*)((u8*)param_4 + recordIndex * 0x24 + 0x70);
        itemY = rowY + (f32)(i * 0x21);
        if (selected == i) {
            if (hasRecord != 0) {
                FUN_001159f0(spriteX, selectedY + (f32)(i * 0x21),
                             param_1, drawData[1], 0x25, param_5);
            }
            FUN_001159f0(textX, itemY, param_1, drawData[1], 0x40, param_5);
            FUN_001159f0(textY, itemY, param_1, drawData[1], 0x41, param_5);
        } else if (hasRecord == 0) {
            FUN_001159f0(textX, itemY, param_1, drawData[1], 0x3c, param_5);
            FUN_001159f0(textY, itemY, param_1, drawData[1], 0x3d, param_5);
        } else {
            FUN_001159f0(spriteX, selectedY + (f32)(i * 0x21),
                         param_1, drawData[1], 0x25, param_5);
            FUN_001159f0(textX, itemY, param_1, drawData[1], 0x3e, param_5);
            FUN_001159f0(textY, itemY, param_1, drawData[1], 0x3f, param_5);
        }
    }

    textX = x + 252.0f;
    for (i = 0; i < 6; i++) {
        s32 recordIndex;
        if (i + row >= totalCount) {
            break;
        }
        recordIndex = row + i;
        type = *(u32*)((u8*)param_4 + recordIndex * 0x24 + 0x78);
        textY = y + 43.0f + (f32)(i * 0x21);

        if (i == selected) {
            /* jtbl_007B63A0: the cases are not empty; they select the
             * selected-row digit/icon before the +1 adjustment. */
            spriteCode = 9;
            switch (type) {
            case 0:  spriteCode = 0;    break;
            case 1:  spriteCode = 2;    break;
            case 2:  spriteCode = 4;    break;
            case 3:  spriteCode = 6;    break;
            case 4:  spriteCode = 8;    break;
            case 5:  spriteCode = 0xa;  break;
            case 6:  spriteCode = 0xc;  break;
            case 7:  spriteCode = 0xe;  break;
            case 8:  spriteCode = 0;    break;
            case 9:  spriteCode = 2;    break;
            case 10: spriteCode = 4;    break;
            case 11: spriteCode = 6;    break;
            case 12: spriteCode = 8;    break;
            case 13: spriteCode = 0xa;  break;
            case 14: spriteCode = 0xc;  break;
            case 15: spriteCode = 0xe;  break;
            case 16: spriteCode = 0x12; break;
            case 17: spriteCode = 0x14; break;
            case 18: spriteCode = 0x16; break;
            case 19: spriteCode = 0x1a; break;
            case 20: spriteCode = 0x1a; break;
            default: break;
            }
            FUN_001159f0(textX, textY, param_1, drawData[0], spriteCode + 1,
                         param_5);

            {
                u8* record = (u8*)param_4 + recordIndex * 0x24;
                textId = (u32)func_00171110(*(undefined2*)(record + 100),
                                      *(undefined1*)(record + 0x7d));
                FUN_00523ac8(text, gp0xffff897c, textId);
            }
            FUN_003b2cb0(param_1, (s32)((s32)x + 292.0f),
                         (s32)((s32)y + 52.0f + (f32)(i * 0x21) + 1.0f),
                         textAlpha | 0xffffff00U, 6, 1, text, 0x10, 0);
        } else {
            /* jtbl_007B6340: this is the unselected-row table. */
            spriteCode = 9;
            switch (type) {
            case 0:  spriteCode = 1;    break;
            case 1:  spriteCode = 3;    break;
            case 2:  spriteCode = 5;    break;
            case 3:  spriteCode = 7;    break;
            case 4:  spriteCode = 9;    break;
            case 5:  spriteCode = 0xb;  break;
            case 6:  spriteCode = 0xd;  break;
            case 7:  spriteCode = 0xf;  break;
            case 8:  spriteCode = 1;    break;
            case 9:  spriteCode = 3;    break;
            case 10: spriteCode = 5;    break;
            case 11: spriteCode = 7;    break;
            case 12: spriteCode = 9;    break;
            case 13: spriteCode = 0xb;  break;
            case 14: spriteCode = 0xd;  break;
            case 15: spriteCode = 0xf;  break;
            case 16: spriteCode = 0x13; break;
            case 17: spriteCode = 0x15; break;
            case 18: spriteCode = 0x17; break;
            case 19: spriteCode = 0x1b; break;
            case 20: spriteCode = 0x1b; break;
            default: break;
            }
            FUN_00115bc0(textX, textY, param_1, drawData[0], spriteCode - 1,
                         param_5, 0x20, 0x43, 0x78, 0);
            {
                u8* record = (u8*)param_4 + recordIndex * 0x24;
                textId = (u32)func_00171110(*(undefined2*)(record + 100),
                                      *(undefined1*)(record + 0x7d));
                FUN_00523ac8(text, gp0xffff897c, textId);
            }
            FUN_003b2cb0(param_1, (s32)((s32)x + 292.0f),
                         (s32)((s32)y + 52.0f + (f32)(i * 0x21)),
                         textAlpha | 0xffffff00U, 10, 1, text, 0x10, 0);
        }
    }
}

// FUN_0016AF90 NONMATCHING
void FUN_0016af90(f32 param_1, void* param_2, undefined8 param_3,
                  void* param_4, s32 param_5)
{
    f32 x;
    f32 y;
    f32 xLeft;
    f32 xRight;
    f32 yTop;
    f32 yBottom;
    f32 rowY;
    f32 barY;
    s32 totalCount;
    s32 row;
    s32 selected;
    s32 recordIndex;
    u8* record;
    s32 condition;
    u32 type;
    u32 mainSprite;
    u32 alpha;
    u32 textId;
    u32* drawData;
    undefined1 text[0x100];

    x = *(f32*)((u8*)&param_3 + 4);
    y = *(f32*)&param_3;
    drawData = (u32*)param_2;
    alpha = 0xffU - (u32)param_5;

    FUN_001159f0(x + 36.0f, y + 242.0f, param_1, drawData[1], 0x48, param_5);
    FUN_001159f0(x + 348.0f, y + 242.0f, param_1, drawData[1], 0x49, param_5);
    FUN_001159f0(x + 55.0f, y + 252.0f, param_1, drawData[1], 0x4a, param_5);
    FUN_001159f0(x + 55.0f, y + 286.0f, param_1, drawData[1], 0x4b, param_5);
    FUN_001159f0(x + 198.0f, y + 286.0f, param_1, drawData[1], 0x4c, param_5);
    FUN_001159f0(x + 55.0f, y + 313.0f, param_1, drawData[1], 0x4d, param_5);
    FUN_001159f0(x + 198.0f, y + 313.0f, param_1, drawData[1], 0x4e, param_5);

    totalCount = *(s32*)((u8*)param_4 + 0x2d64);
    if (totalCount == 0) {
        /* Retail uses the same 0x4f glyph/frame for all four empty slots. */
        FUN_001159f0(x + 129.0f, y + 294.0f, param_1, drawData[1], 0x4f,
                     param_5);
        FUN_001159f0(x + 272.0f, y + 294.0f, param_1, drawData[1], 0x4f,
                     param_5);
        FUN_001159f0(x + 129.0f, y + 321.0f, param_1, drawData[1], 0x4f,
                     param_5);
        FUN_001159f0(x + 272.0f, y + 321.0f, param_1, drawData[1], 0x4f,
                     param_5);
        return;
    }

    row = *(s32*)((u8*)param_4 + 0x2d6c);
    selected = *(s32*)((u8*)param_4 + 0x2d68);
    recordIndex = row + selected;
    record = (u8*)param_4 + recordIndex * 0x24;
    type = *(u32*)(record + 0x78);

    /* jtbl_007B6400 selects the main selected-persona icon. */
    mainSprite = 0x51;
    switch (type) {
    case 0:  mainSprite = 0x51; break;
    case 1:  mainSprite = 0x52; break;
    case 2:  mainSprite = 0x53; break;
    case 3:  mainSprite = 0x54; break;
    case 4:  mainSprite = 0x55; break;
    case 5:  mainSprite = 0x56; break;
    case 6:  mainSprite = 0x5b; break;
    case 7:  mainSprite = 0x57; break;
    case 8:  mainSprite = 0x51; break;
    case 9:  mainSprite = 0x52; break;
    case 10: mainSprite = 0x53; break;
    case 11: mainSprite = 0x54; break;
    case 12: mainSprite = 0x55; break;
    case 13: mainSprite = 0x56; break;
    case 14: mainSprite = 0x5b; break;
    case 15: mainSprite = 0x57; break;
    case 16: mainSprite = 0x58; break;
    case 17: mainSprite = 0x59; break;
    case 18: mainSprite = 0x5a; break;
    case 19: mainSprite = 0x5a; break;
    case 20: mainSprite = 0x5a; break;
    default: break;
    }
    FUN_001159f0(x + 127.0f, y + 253.0f, param_1, drawData[1],
                 mainSprite, param_5);

    condition = *(s8*)((u8*)record + 0x7e);
    xLeft = x + 55.0f + 74.0f;
    xRight = x + 198.0f + 74.0f;
    yTop = y + 286.0f + 8.0f;
    yBottom = y + 313.0f + 8.0f;
    if (condition == 2) {
        textId = *(undefined2*)((u8*)record + 0x86);
        FUN_00523ac8(text, gp0xffff8998, textId);
        FUN_0040eb50(param_1, (s32)xRight, (s32)yBottom, alpha & 0xffU,
                     4, text, 0);
        FUN_001159f0(xLeft, yTop, param_1, drawData[1], 0x4f, param_5);
        FUN_001159f0(xRight, yTop, param_1, drawData[1], 0x4f, param_5);
        FUN_001159f0(xLeft, yBottom, param_1, drawData[1], 0x4f, param_5);
    } else if (condition == 1) {
        textId = *(undefined2*)((u8*)record + 0x84);
        FUN_00523ac8(text, gp0xffff8998, textId);
        FUN_0040eb50(param_1, (s32)xLeft, (s32)yBottom, alpha & 0xffU,
                     4, text, 0);
        FUN_001159f0(xLeft, yTop, param_1, drawData[1], 0x4f, param_5);
        FUN_001159f0(xRight, yTop, param_1, drawData[1], 0x4f, param_5);
        FUN_001159f0(xRight, yBottom, param_1, drawData[1], 0x4f, param_5);
    } else if (condition == 0) {
        textId = *(undefined2*)((u8*)record + 0x80);
        FUN_00523ac8(text, gp0xffff8998, textId);
        FUN_0040eb50(param_1, (s32)xLeft, (s32)yTop, alpha & 0xffU,
                     4, text, 0);
        textId = *(undefined2*)((u8*)record + 0x82);
        FUN_00523ac8(text, gp0xffff8998, textId);
        FUN_0040eb50(param_1, (s32)xRight, (s32)yTop, alpha & 0xffU,
                     4, text, 0);
        FUN_001159f0(xLeft, yBottom, param_1, drawData[1], 0x4f, param_5);
        FUN_001159f0(xRight, yBottom, param_1, drawData[1], 0x4f, param_5);
    } else {
        FUN_001159f0(xLeft, yTop, param_1, drawData[1], 0x4f, param_5);
        FUN_001159f0(xRight, yTop, param_1, drawData[1], 0x4f, param_5);
        FUN_001159f0(xLeft, yBottom, param_1, drawData[1], 0x4f, param_5);
        FUN_001159f0(xRight, yBottom, param_1, drawData[1], 0x4f, param_5);
    }

    rowY = y + 356.0f;
    barY = x + 55.0f;
    FUN_003c7e20(param_1, (s32)barY, (s32)rowY,
                 alpha | 0xffffff00U, 1, 10, 1,
                 (u32)((*(undefined1*)((u8*)record + 0x7c) << 16) |
                       *(undefined2*)((u8*)record + 100)));
}


// FUN_0016BA00
f32 FUN_0016ba00(u32 param_1, u32 param_2)
{
    if (iGpffffb2c0 == NULL) {
        FUN_0019d3f0(D_005E3098, 0x86);
    }
    return iGpffffb2c0->groups[param_1 & 0xffff]
        .records[param_2 & 0xffff].value;
}

// FUN_0016BA80
f32 FUN_0016ba80(u32 param_1, u32 param_2)
{
    if (iGpffffb2c0 == NULL) {
        FUN_0019d3f0(D_005E3098, 0x8b);
    }
    return (f32)(s32)iGpffffb2c0->groups[param_1 & 0xffff].records[param_2 & 0xffff].axis0;
}

// FUN_0016BB00
f32 FUN_0016bb00(u32 param_1, u32 param_2)
{
    if (iGpffffb2c0 == NULL) {
        FUN_0019d3f0(D_005E3098, 0x90);
    }
    return (f32)(s32)iGpffffb2c0->groups[param_1 & 0xffff].records[param_2 & 0xffff].axis1;
}

// FUN_0016BB80
f32 FUN_0016bb80(u32 param_1, u32 param_2)
{
    if (iGpffffb2c0 == NULL) {
        FUN_0019d3f0(D_005E3098, 0x95);
    }
    return (f32)(s32)iGpffffb2c0->groups[param_1 & 0xffff].records[param_2 & 0xffff].axis2;
}

// FUN_0016BC00
f32 FUN_0016bc00(u32 param_1, u32 param_2)
{
    if (iGpffffb2c0 == NULL) {
        FUN_0019d3f0(D_005E3098, 0x9a);
    }
    return (f32)(s32)iGpffffb2c0->groups[param_1 & 0xffff].records[param_2 & 0xffff].axis3;
}

// FUN_0016BC80
void FUN_0016bc80(u32 param_1, u32 param_2, f32* param_3)
{
    if (iGpffffb2c0 == NULL) {
        FUN_0019d3f0(D_005E3098, 0xa5);
    }
    param_3[0] = (f32)(s32)(((s32)iGpffffb2c0->groups[param_1 & 0xffff]
        .records[param_2 & 0xffff].color0 >> 24) & 0xff) / 255.0f;
    param_3[1] = (f32)(s32)(((s32)iGpffffb2c0->groups[param_1 & 0xffff]
        .records[param_2 & 0xffff].color0 >> 16) & 0xff) / 255.0f;
    param_3[2] = (f32)(s32)(((s32)iGpffffb2c0->groups[param_1 & 0xffff]
        .records[param_2 & 0xffff].color0 >> 8) & 0xff) / 255.0f;
    param_3[3] = (f32)(s32)(iGpffffb2c0->groups[param_1 & 0xffff]
        .records[param_2 & 0xffff].color0 & 0xff) / 255.0f;
}

// FUN_0016BDB0
void FUN_0016bdb0(u32 param_1, u32 param_2, f32* param_3)
{
    if (iGpffffb2c0 == NULL) {
        FUN_0019d3f0(D_005E3098, 0xaf);
    }
    param_3[0] = (f32)(s32)(((s32)iGpffffb2c0->groups[param_1 & 0xffff]
        .records[param_2 & 0xffff].color1 >> 24) & 0xff) / 255.0f;
    param_3[1] = (f32)(s32)(((s32)iGpffffb2c0->groups[param_1 & 0xffff]
        .records[param_2 & 0xffff].color1 >> 16) & 0xff) / 255.0f;
    param_3[2] = (f32)(s32)(((s32)iGpffffb2c0->groups[param_1 & 0xffff]
        .records[param_2 & 0xffff].color1 >> 8) & 0xff) / 255.0f;
    param_3[3] = (f32)(s32)(iGpffffb2c0->groups[param_1 & 0xffff]
        .records[param_2 & 0xffff].color1 & 0xff) / 255.0f;
}

// FUN_0016BEE0 NONMATCHING
void FUN_0016bee0(u32 param_1, u32 param_2, void* param_3)
{
    CampDataBridgeGroup* group;
    CampDataBridgeRecord* record;

    if (iGpffffb2c0 == NULL) {
        FUN_0019d3f0(D_005E3098, 0xb8);
    }
    group = (CampDataBridgeGroup*)((param_1 & 0xffff) * sizeof(CampDataBridgeGroup) +
        (u8*)iGpffffb2c0);
    record = group->records;
    record = (CampDataBridgeRecord*)((param_2 & 0xffff) * sizeof(CampDataBridgeRecord) +
        (u8*)record);
    FUN_00521250(param_3, group->auxiliaryData + (s32)record->helpIndex * 0x10, 0x10);
}

// FUN_0016BF80
void FUN_0016bf80(u32 param_1, u32 param_2, void* param_3)
{
    if (param_3 == NULL) {
        FUN_0019d3f0(D_005E3098, 0xc3);
    }
    FUN_00521250(param_3, &iGpffffb2c0->groups[param_1 & 0xffff].records[param_2 & 0xffff], 0x20);
}

// FUN_0016C010 NONMATCHING
void FUN_0016c010(void)
{
    void* cdvd;
    s32* descriptor;
    u8* payload;
    CampDataBridgeRoot* root;

    cdvd = (void*)(uintptr_t)FUN_00100d80(D_005E30B0, 0);
    FUN_001023a0(cdvd);
    descriptor = *(s32**)((u8*)cdvd + 0x110);
    root = (CampDataBridgeRoot*)(*DAT_00960178)(
        (((descriptor[0] + descriptor[4]) << 5) + 0x20) +
        ((descriptor[1] + descriptor[5]) << 4), 0x40000);
    iGpffffb2c0 = root;
    root->groups[0].recordCount = descriptor[0];
    root->groups[0].auxiliaryCount = descriptor[1];
    root->groups[0].records = (CampDataBridgeRecord*)((u8*)root + 0x20);
    root->groups[0].auxiliaryData =
        (u8*)root->groups[0].records + (descriptor[0] << 5);
    root->groups[1].recordCount = descriptor[4];
    root->groups[1].auxiliaryCount = descriptor[5];
    root->groups[1].records =
        (CampDataBridgeRecord*)(root->groups[0].auxiliaryData +
                                (descriptor[1] << 4));
    root->groups[1].auxiliaryData =
        (u8*)root->groups[1].records + (descriptor[4] << 5);
    payload = (u8*)(descriptor + 8);
    FUN_00521250(root->groups[0].records, payload, descriptor[0] << 5);
    payload += descriptor[0] << 5;
    FUN_00521250(root->groups[0].auxiliaryData, payload, descriptor[1] << 4);
    payload += descriptor[1] << 4;
    FUN_00521250(root->groups[1].records, payload, descriptor[4] << 5);
    FUN_00521250(root->groups[1].auxiliaryData,
                 payload + (descriptor[4] << 5), descriptor[5] << 4);
    FUN_00100ec0(cdvd);
}

// FUN_0016C1D0 NONMATCHING
void FUN_0016c1d0(void)
{
    const char* helpPaths[8];
    u8 fileSizeScratch[4];
    void* cdvd;
    void* resource;
    s32 i;

    for (i = 0; i < 8; i++) {
        helpPaths[i] = PTR_s_help_datWeaponHelp_bmd_005e31d0[i];
    }
    cdvd = (void*)(uintptr_t)FUN_00100d80((const char*)0x5e31f0, 1);
    FUN_001023a0(cdvd);
    for (i = 0; i < 8; i++) {
        resource = (void*)(uintptr_t)FUN_001021c0(helpPaths[i], (u32*)fileSizeScratch);
        FUN_003c7d80(i, resource);
    }
    FUN_0016c010();
    cdvd = (void*)(uintptr_t)FUN_00100d80((const char*)0x5e3200, 0);
    DAT_007cdfe8 = cdvd;
    FUN_001023a0(cdvd);
    FUN_00521250((void*)0x83bb30, *(void**)((u8*)cdvd + 0x110),
                 *(u32*)((u8*)cdvd + 0x118));
    FUN_00100ec0(cdvd);
    FUN_0016c2f0();
}

// FUN_0016C2F0 NONMATCHING
void FUN_0016c2f0(void)
{
    s32* piVar1;
    u32 uVar2;
    u32 count;
    s32 n;
    u8* p;

    piVar1 = (s32*)0x83bb30;
    count = (u32)*piVar1;
    p = (u8*)piVar1 + 0x10;
    DAT_007cdfe4 = p;
    p += count * 0x28;
    n = *(s32*)p;
    p += 0x10;
    DAT_007cdfe0 = p;
    p += n << 4;
    n = *(s32*)p;
    p += 0x10;
    DAT_007cdfdc = (s32*)p;
    p += n << 5;
    n = *(s32*)p;
    p += 0x10;
    DAT_007cdfd8 = (s32*)p;
    p += n << 5;
    n = *(s32*)p;
    p += 0x10;
    DAT_007cdfd4 = (s32*)p;
    p += ((n << 3) + n) << 2;
    n = *(s32*)p;
    p += 0x10;
    DAT_007cdfd0 = (s32*)p;
    p += ((n << 3) - n) << 2;
    n = *(s32*)p;
    p += 0x10;
    DAT_007cdfcc = (s32*)p;
    p += ((n << 3) - n) << 2;
    n = *(s32*)p;
    p += 0x10;
    DAT_007cdfc4 = (s32*)p;
    p += n << 4;
    n = *(s32*)p;
    p += 0x10;
    DAT_007cdfc0 = (s32*)p;
    p += n << 5;
    n = *(s32*)p;
    p += 0x10;
    DAT_007cdfbc = (s32*)p;
    p += ((n << 2) + n) << 2;
    n = *(s32*)p;
    p += 0x10;
    DAT_007cdfb4 = (s32*)p;
    p += n << 5;
    n = *(s32*)p;
    p += 0x10;
    DAT_007cdfc8 = (s32*)p;
    p += ((n << 1) + n) << 2;
    n = *(s32*)p;
    p += 0x10;
    p += ((n << 1) + n) << 2;
    piVar1 = (s32*)p;
    for (uVar2 = 0; uVar2 < 0x23; uVar2++) {
        ((u32*)0x83aaa0)[uVar2] = (u32)piVar1;
        piVar1 += 8;
    }
}
