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
typedef struct CampFloatPair
{
    f32 x;
    f32 y;
} CampFloatPair;
typedef struct CampHelpPaths
{
    const char* paths[8];
} CampHelpPaths;
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
#pragma alias DAT_00960178_abs DAT_00960178
extern void* (*DAT_00960178_abs[])(...);
extern f32 DAT_00960088;
#pragma alias DAT_00960088_abs DAT_00960088
extern u8 DAT_00960088_abs[];
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
extern u32 DAT_0083bb30[];
extern u8 DAT_0083bb40;
extern u32 DAT_0083aaa0[0x23];
extern const char* PTR_s_help_datWeaponHelp_bmd_005e31d0[8];
extern char DAT_005dc020[];
extern char DAT_005dbc60[];
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
extern void FUN_00113a30(f32 depth, f32 x, f32 y, u32 color, s32 width, s32 height);
#pragma alias FUN_00113a30_camp_reordered FUN_00113a30
extern void FUN_00113a30_camp_reordered(u32 color, f32 depth, f32 x,
                                        f32 y, s32 width, s32 height);
extern u32 FUN_00114450();
#pragma alias campDataDrawPersonaSprite FUN_00114450
extern void campDataDrawPersonaSprite(f32 alpha, f32 slidePosition, f32 depth,
                                      s32 mode, u32 color, u32 width,
                                      u32 height, void* resource);
extern void FUN_001159f0(f32 x, f32 y, ...);
#pragma alias FUN_001159f0_typed FUN_001159f0
extern void FUN_001159f0_typed(void* owner, void* atlas, s32 tile, u8 alpha,
                                f32 x, f32 y, f32 depth);
extern u32 FUN_00115bc0();
#pragma alias FUN_00115bc0_typed FUN_00115bc0
extern void FUN_00115bc0_typed(void* owner, void* atlas, s32 tile, u8 alpha,
                                u32 red, u32 green, u32 blue, f32 x, f32 y,
                                f32 depth);
#pragma alias campDataDrawSpriteDirect FUN_001159f0
extern void campDataDrawSpriteDirect(f32 x, f32 y, f32 depth);
#pragma alias campDataDrawSpriteAltDirect FUN_00115bc0
extern void campDataDrawSpriteAltDirect(f32 x, f32 y, f32 depth);
#pragma alias campDataDrawDigitsDirect FUN_00115de0
extern void campDataDrawDigitsDirect(f32 x, f32 y, f32 depth);
#pragma alias campDataDrawSpriteFade FUN_001159f0
extern void campDataDrawSpriteFade(f32 x, f32 y, f32 depth,
                                   void* atlas, s32 tile, s32 alpha);
#pragma alias campDataDrawSpriteAltFade FUN_00115bc0
extern void campDataDrawSpriteAltFade(f32 x, f32 y, f32 depth,
                                      void* atlas, s32 tile, s32 alpha,
                                      s32 red, s32 green, s32 blue, s32 flags);
extern u32 FUN_00115de0();
extern u32 FUN_00119f10();
#pragma alias campDataCreateTask FUN_00119f10
extern void* campDataCreateTask(void* task, s32 mode);
extern u32 FUN_0011abd0();
extern u32 FUN_00122710();
extern u32 FUN_0012a560(f32, RwV2d, void*, s32);
extern u32 FUN_0012ac60(f32, RwV2d, void*, s32);
extern u32 FUN_00129b30(f32, RwV2d, void*, s32);
extern u32 FUN_0013c240();
extern u32 FUN_0013c780();
extern u32 FUN_0013cf80();
extern u32 FUN_0013d1a0();
extern u32 FUN_0013fca0();
#pragma alias campDataDrawEquipment FUN_0013d1a0
extern void campDataDrawEquipment(f32 depth, CampFloatPair position,
                                  void* work, s32 alpha);
#pragma alias campDataDrawEquipmentAlt FUN_0013fca0
extern void campDataDrawEquipmentAlt(f32 depth, CampFloatPair position,
                                     void* work, s32 alpha);
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
extern f32 FUN_0021ea00(s32);
extern KwlnTask* FUN_0025f370(KwlnTask* parent, void* battle_data);
extern u32 FUN_0025f570();
extern u32 FUN_0035ed20();
extern u32 FUN_003b2cb0();
#pragma alias campDataDrawTextRaw FUN_003b2cb0
extern s32 campDataDrawTextRaw(f32 scale, s32 x, s32 y, s32 color,
                               s32 font, s32 alignment, const char* text,
                               s32 maxWidth, s32 shadow);
extern u32 FUN_003c7430();
extern u32 FUN_003c74e0();
extern u32 FUN_003c7560();
extern u32 FUN_003c7610();
extern u32 FUN_003c7700();
extern u32 FUN_003c7850();
extern u32 FUN_003c7d80();
extern u32 FUN_003c7e20();
#pragma alias campDataDrawDigits FUN_003c7e20
extern void campDataDrawDigits(f32 depth, s32 x, s32 y, s32 color,
                               s32 style, s32 font, s32 alignment, u32 value);
extern u32 FUN_0040eb50();
#pragma alias campDataDrawText FUN_0040eb50
extern s32 campDataDrawText(f32 scale, s32 x, s32 y, u8 color, s16 font,
                            const char* text, s32 maxWidth);
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
KwlnTask* FUN_00167f40(KwlnTask*, u32, CampFloatPair, u16, u16, u16);
u32 FUN_00168040(void);
u32 FUN_00168100(void);
bool FUN_001681d0(void);
void* FUN_00168220(KwlnTask*);
bool FUN_001685b0(KwlnTask*);
u32 FUN_001685d0(KwlnTask*);
void FUN_001685e0(KwlnTask*, s32);
void FUN_00168720(KwlnTask*);
KwlnTask* FUN_00168770(KwlnTask*, u32);
u32 FUN_00168810(u32);
void FUN_00169040(int);
void FUN_00169110(u16, CampFloatPair, void*, s32);
void FUN_001691F0(u16, CampFloatPair, void*, void*, s32);
undefined4 FUN_00169330(void);
bool FUN_00169420(void);
undefined4 FUN_00169470(KwlnTask*);
void FUN_00169AE0(int);
void FUN_00169B90(void* resources, undefined8 coordinates,
                  void* list, s32 alpha, undefined8 stackArg);
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
#pragma alias campDataDrawListA FUN_0016A700
extern void campDataDrawListA(f32 depth, void* resources, RwV2d coordinates,
                              void* list, s32 alpha);
#pragma alias campDataDrawListB FUN_0016AF90
extern void campDataDrawListB(f32 depth, void* resources, RwV2d coordinates,
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


/* Work area used by FUN_00168810/FUN_00169040. */
typedef struct CampTargetLoadWork
{
    u32 state;                 /* +0x00 */
    u32 reserved04;            /* +0x04 */
    s32 frame;                 /* +0x08 */
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






















/* opt_loop_invariants on: baseline nd1045/2096B -> on nd1038/2096B; retained. */

#pragma opt_loop_invariants reset




/* opt_loop_invariants on: baseline nd1082/1628B -> on nd1079/1628B; opt_propagation off nd1070/1600B; stacked nd1045/1596B; retained. */

#pragma opt_propagation reset
#pragma opt_loop_invariants reset
/* Existing lifetime/propagation scope: baseline nd555/812B; single probes nd552/812B and nd552/808B; stacked probe nd551/808B; retained. */

/* opt_lifetimes on and opt_propagation off are both active for this draw helper. */

#pragma opt_propagation reset
#pragma opt_lifetimes reset
/* opt_lifetimes on: baseline nd1098/1576B -> on nd1087/1576B; propagation off nd1093/1576B; stacked nd1099/1576B; lifetimes retained. */



/* opt_lifetimes on: baseline nd1526/2180B -> on nd1518/2180B; retained. */

/* opt_propagation off: baseline nd1935/2576B -> off nd1912/2464B; retained. */


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

// FUN_0016BEE0 MATCHING
void FUN_0016bee0(u32 param_1, u32 param_2, void* param_3)
{
    u32 groupOffset;
    CampDataBridgeGroup* group;
    CampDataBridgeRecord* record;
    u32 recordOffset;

    if (iGpffffb2c0 == NULL) {
        FUN_0019d3f0(D_005E3098, 0xb8);
    }
    groupOffset = (param_1 & 0xffff) * 0x10;
    group = (CampDataBridgeGroup*)(groupOffset + (u32)(uintptr_t)iGpffffb2c0);
    record = group->records;
    recordOffset = (param_2 & 0xffff) * 0x20;
    record = (CampDataBridgeRecord*)(recordOffset + (u32)(uintptr_t)record);
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

// FUN_0016C010
void FUN_0016c010(void)
{
    void* cdvd;
    s32* descriptor;
    u8* payload;

    cdvd = (void*)(uintptr_t)FUN_00100d80(D_005E30B0, 0);
    FUN_001023a0(cdvd);
    descriptor = *(s32**)((u8*)cdvd + 0x110);
    iGpffffb2c0 = (CampDataBridgeRoot*)DAT_00960178_abs[0](
        (((descriptor[0] + descriptor[4]) << 5) + 0x20) +
        ((descriptor[1] + descriptor[5]) << 4), 0x40000);
    iGpffffb2c0->groups[0].recordCount = descriptor[0];
    iGpffffb2c0->groups[0].auxiliaryCount = descriptor[1];
    iGpffffb2c0->groups[0].records =
        (CampDataBridgeRecord*)((u8*)iGpffffb2c0 + 0x20);
    iGpffffb2c0->groups[0].auxiliaryData =
        (u8*)iGpffffb2c0->groups[0].records +
        (iGpffffb2c0->groups[0].recordCount << 5);
    payload = (u8*)(descriptor + 8);
    FUN_00521250(iGpffffb2c0->groups[0].records,
                 payload, iGpffffb2c0->groups[0].recordCount << 5);
    payload += iGpffffb2c0->groups[0].recordCount << 5;
    FUN_00521250(iGpffffb2c0->groups[0].auxiliaryData,
                 payload, iGpffffb2c0->groups[0].auxiliaryCount << 4);
    iGpffffb2c0->groups[1].recordCount = descriptor[4];
    iGpffffb2c0->groups[1].auxiliaryCount = descriptor[5];
    iGpffffb2c0->groups[1].records =
        (CampDataBridgeRecord*)(iGpffffb2c0->groups[0].auxiliaryData +
            (iGpffffb2c0->groups[0].auxiliaryCount << 4));
    iGpffffb2c0->groups[1].auxiliaryData =
        (u8*)iGpffffb2c0->groups[1].records +
        (iGpffffb2c0->groups[1].recordCount << 5);
    payload += iGpffffb2c0->groups[0].auxiliaryCount << 4;
    FUN_00521250(iGpffffb2c0->groups[1].records,
                 payload, iGpffffb2c0->groups[1].recordCount << 5);
    payload += iGpffffb2c0->groups[1].recordCount << 5;
    FUN_00521250(iGpffffb2c0->groups[1].auxiliaryData,
                 payload, iGpffffb2c0->groups[1].auxiliaryCount << 4);
    FUN_00100ec0(cdvd);
}

// FUN_0016C1D0 MATCHING
void FUN_0016c1d0(void)
{
    CampHelpPaths helpPaths;
    u8 fileSizeScratch[4];
    void* cdvd;
    void* resource;
    s32 i;
    u32 copySize;

    helpPaths = *(CampHelpPaths*)PTR_s_help_datWeaponHelp_bmd_005e31d0;
    FUN_001023a0((void*)(uintptr_t)FUN_00100d80(D_005E31F0, 1));
    for (i = 0; i < 8; i++) {
        resource = (void*)(uintptr_t)FUN_001021c0(
            helpPaths.paths[i], (u32*)fileSizeScratch);
        FUN_003c7d80(i, resource);
    }
    FUN_0016c010();
    FUN_001023a0(DAT_007cdfe8 =
        (void*)(uintptr_t)FUN_00100d80(D_005E3200, 0));
    cdvd = DAT_007cdfe8;
    copySize = *(volatile u32*)((u8*)cdvd + 0x118);
    FUN_00521250(DAT_0083bb30, *(void**)((u8*)cdvd + 0x110),
                 copySize);
    FUN_00100ec0(DAT_007cdfe8);
    FUN_0016c2f0();
}

// FUN_0016C2F0
void FUN_0016c2f0(void)
{
    u8* data;
    u32 count;
    s32 n;
    s32 scaled;
    u8* p;

    data = (u8*)DAT_0083bb30;
    count = *(u32*)data;
    p = data + 0x10;
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
    scaled = n << 3;
    p += (scaled + n) << 2;
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
    scaled = n << 2;
    p += (scaled + n) << 2;
    n = *(s32*)p;
    p += 0x10;
    DAT_007cdfb4 = (s32*)p;
    p += n << 5;
    n = *(s32*)p;
    p += 0x10;
    DAT_007cdfc8 = (s32*)p;
    p += n << 3;
    n = *(s32*)p;
    p += 0x10;
    DAT_007cdfb8 = (s32*)p;
    scaled = n << 1;
    scaled += n;
    p += scaled << 2;
    {
        s32* entry;
        u32* output;
        u32 i;

        entry = (s32*)(p + 0x10);
        i = 0;
        output = DAT_0083aaa0;
        for (; i < 0x23; i++) {
            output[i] = (u32)entry;
            entry += 8;
        }
    }
}
