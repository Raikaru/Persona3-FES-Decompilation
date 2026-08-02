#include "Main/g_data.h"
#include "Main/Battle/Data/datCalc.h"
#include "Kosaka/k_assert.h"
#include "Script/scrTraceCode.h"
#include "temporary.h"
#include "datCalendar.h"

#pragma alias FUN_0019d3f0_y2 FUN_0019d3f0
#pragma alias FUN_00521250_y2 FUN_00521250
#pragma alias FUN_00523ac8_y2 FUN_00523ac8
#pragma alias scrGetIntPara_y2 scrGetIntPara


#define SOCIAL_LINK_COUNT 30
#define SOCIAL_DATA_POINTS_OFFSET 0xD2
#define SOCIAL_DATA_COUNTER_OFFSET 0xD6
extern u8* FUN_00172c50(s16* outValue);
extern s32 FUN_00172660(s32 socialLink);
extern void FUN_00172a20(u32 value);
extern u8 D_008364BC[];
extern s32 D_008364F4[];
extern s32 D_008365F4[];
extern u8 D_008366F4[];
extern u8 D_00836734[];
extern u8 D_00836752[];
extern s16 D_0083679C[];
extern u8 D_0083A34C[];
extern u8* iGpffffb7f4;
extern u8* iGpffffb730;
extern u8* iGpffffb734;
extern u8* iGpffffb740;
extern u8* iGpffffb2e4;
extern s32 func_003951d0(s32 resourceId);
extern void func_00395170(s32 resourceId);
extern void func_003951a0(s32 resourceId);
extern s16* func_003bddd0(void);
extern u8* func_003beb10(s32 socialLink);
extern void func_0017ad90(void);
extern void func_0017ac60(u32 packedData);
extern void func_001828d0(s16 itemId, void* itemData);
extern void func_001831e0(s16 pcId, s16 slot, const void* itemData);


// 005dc050
static const u32 sPlayerExpThreshold[MAX_CHARACTER_LEVEL] = 
{
    0, 20, 47, 99, 185, 312, 490, 726, 1030,
    1410, 1873, 2429, 3085, 3851, 4735, 5744, 6888, 8174,
    9612, 11210, 12975, 14917, 17043, 19363, 21885, 24616, 27566,
    30742, 34154, 37810, 41717, 45885, 50321, 55035, 60035, 65328,
    70924, 76830, 83056, 89610, 96499, 103733, 111319, 119267, 127585,
    136280, 145362, 154838, // ! 005dc110 !
};

static const s16 academicLevelThreshold[6] = { 0, 20, 80, 140, 200, 260 }; // 005e3068
static const s16 charmLevelThreshold[6] =    { 0, 15, 30, 45, 65, 80 };    // 005e3078
static const s16 courageLevelThreshold[6] =  { 0, 15, 30, 45, 65, 80 };    // 005e3088

// 005e4150
static const char* physicalConditionsString[13] = 
{
    "You recovered from your cold.",
    "Your cold is not gone yet...",
    "Your cold worsened because you're tired.",
    "You've caught a cold.",
    "You've become tired.",
    "You're not tired anymore.",
    "Your condition improved because you rested.",
    "Your condition has improved.",
    "You are no longer in great condition.",
    "You're still tired",
    "You're no longer sick because you rested.",
    "You're no longer tired because you rested.",
    "The medicine cured your illness."
};

static s16 sSavedPartyIds[4]; // 007cdfa8
static u32 sScenarioMode;     // 007cdfa4. See enum 'ScenarioMode'

DatGlobal gGlobalWork; // 00836200
DatPc gPcs[PC_MAX];    // 00833948

void func_00177410(u8*, u8*);
void func_001774e0(void);
extern const char D_005E3098[];
extern const char D_005E3260[];
extern u32 gSpecialStatusMessage;
extern u8 DAT_00833bb0[];
extern u8 DAT_00833bd0[];
extern u8 DAT_00833bf0[];
extern u8 DAT_00836200[];
#pragma alias DAT_00836200_u32 DAT_00836200
extern u32 DAT_00836200_u32;
extern u8 DAT_00836212[];
extern u8* PTR_s_Aigis_005e35ec;
extern u8* PTR_s_Aigis_005e379c;
extern u8* PTR_s_Aigis_005e37dc;
extern u8* PTR_s_Metis_005e3790;
extern u8* PTR_s_Metis_005e37d0;
extern u8* PTR_s_Metis_005e35e0;
extern u8* D_005E35E0[];
extern u8* D_005E35EC[];
extern u8* D_005E3790[];
extern u8* D_005E379C[];
extern u8* D_005E37D0[];
extern u8* D_005E37DC[];
extern u8 D_007FD6C8[];
extern u8 D_007FD6CC[];
extern u8 D_007FD6D0[];
extern u8 D_007FD6D1[];
extern u8 D_007FD6D2[];
extern u8 D_007FD6D4[];
extern u8 D_007FD6D6[];
extern u8 D_007FD6D8[];
extern u8 D_008339A4[];
extern u8 D_008339A8[];
extern u8 D_008339AC[];
extern u8 D_008339AD[];
extern u8 D_008339AE[];
extern u8 D_008339B0[];
extern u8 D_008339B2[];
extern u8 D_008339B4[];
extern u8 D_008339F4[];
extern u8 D_00834010[];
extern u8 D_00834120[];
extern u8 DAT_00830000_a[];
extern u8 DAT_00830000_b[];
extern u8 DAT_00830000_c[];
extern u8 D_007CBFA0;
extern u8 D_008339F6[];
extern u8 D_00833A78[];
extern u8 D_00833C58[];
extern u8 D_00833C5A[];
extern u8 D_00833E80[];
extern u8 D_00833E84[];
extern u8 D_00833E88[];
extern u8 D_00833E89[];
extern u8 D_00833E8A[];
extern u8 D_00833E8C[];
extern u8 D_00833E8E[];
extern u8 D_00833E90[];
extern u8 D_00836458[];
extern u8 D_00836498[];

extern void func_001754a0(u32 value);

void FUN_00172890(void);
void FUN_00172e10(void);
extern u8 D_005DC1B4[];
extern s8 D_005E3220[];
extern s16 D_005E3240[];
extern u8 D_00831CE0[];
extern u8 D_007FD858[];
extern u8 D_007FD85A[];
extern u8 D_005DDDC0[];
extern u8 D_005DABF0[];
extern u8 D_005D6C70[];
extern u8 D_005D6C80[];
extern u8 D_005DE8E0[];
extern u8 D_005DE880[];
extern u8 D_005DE040[];
extern u8 D_00836773[];
extern u8* D_007CDFB4;
extern u8* D_007CDFBC;
extern u8* D_007CDFC0;
extern u8* D_007CDFC4;
extern u8* D_007CDFC8;
extern u8* D_007CDFCC;
extern u8* D_007CDFD0;
extern u8* D_007CDFD4;
extern u8* D_007CDFD8;
extern u8* D_007CDFDC;
extern u8* D_007CDFE4;

extern u16 func_00300100(DatUnit* unit);
extern u32 FUN_00173280(u16 personaId);
extern void FUN_00171B50(s16 socialLink);
extern void FUN_00171C40(s16 socialLink, s32 value);
extern void FUN_00171E90(s16 socialLink, s32 value);
extern void FUN_00172200(s32 socialLink, s32 value);
#pragma alias FUN_00172200_s16 FUN_00172200
extern void FUN_00172200_s16(s16 socialLink, s32 value);
extern void FUN_001723A0(s16 socialLink, s32 rank, s32 enabled);
extern void FUN_001724A0(s16 socialLink, s32 rank, s32 enabled);
extern f32 FUN_003BDB80(void);
extern u8* FUN_003BDD90();
extern u32 FUN_00488F30(void);
extern void FUN_005225A8();
extern s16 func_00171060(s16 id);

u16 func_0016cc00(s16 pcId);
u16 func_0016ccb0(s16 pcId);
u8 func_0016d280(s32 exp);
u32 func_0016dce0(s16 socialLink);
s8 func_0016dd20(s16 socialLink);
void func_0016ddd0(s32 index);
u8 func_0016de50(s32 index);
s16 func_0016deb0(s16 arcana);
void func_0016dfb0(s16 socialLink);
s16 func_0016e190(s32 socialLink);
void func_0016e2b0(s16 socialLink, s32 amount);
void func_0016e410(s16 socialLink, s8 level);
void func_0016e5f0(s32 socialLink, s8 progress);
#pragma alias func_0016e5f0_call func_0016e5f0
extern void func_0016e5f0_call(s16 socialLink, s8 progress);
void func_0016e670(s16 socialLink);
void func_0016e7a0(s16 socialLink, s16 day);
s16 func_0016e850(s16 socialLink);
s32 func_0016ea40(s32 amount);
u32 func_0016ea80(void);
u32 func_0016ecd0(void);
u8* func_00170620(s16 pcId, s16 index);
u16 func_00170670(s16 pcId, s16 index);
s16 func_001706c0(s16 pcId, s16 index);
void func_00170710(s16 pcId, s16 index, u16 value);
u16 func_00170a40(s16 pcId, s16 index);
s16 func_00170ab0(s16 pcId, s16 index);
void func_00170b20(s16 pcId, s16 index, u16 value);
void func_00170b90(s16 pcId, s16 index, u16 value);
u32 func_00170c00(s16 pcId, s16 index, s16 delta);
void* func_00170d60(s16 id);
void* func_00170da0(s16 id);
void* func_00170df0(s16 id);
void* func_00170e40(s16 id);
u32 func_00171250(s16 id);
u16 func_001712d0(s16 id);
void func_00171390(u32 flag);
s32 func_001714b0(s32 index);
s32 func_001714d0(s32 index);
s32 func_001714f0(s32 index);
f32 func_00171510(s16 row, s16 column);
u8 func_00171550(s16 unused1, s16 unused2, u16 index);
u32 func_001715f0(s16 id);


s32 FUN_00300af0(s32 param_1);
void FUN_00403130();
void FUN_00403220();
void FUN_0017d700(s32 param_1, s32 param_2, void *param_3);
void FUN_003d74b0();
#include "Camp/h_camp.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "h_cdvd.h"
#include "h_maestro.h"
#include "h_snd.h"
#include "Main/Battle/Data/datPersona.h"
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
extern void (*DAT_0096017c[])(...);
extern void (*DAT_0096017c_abs[])(...);
extern void* (*DAT_00960184_abs[])(...);
extern u64 scrGetIntPara_u64(s32);
extern void* (*DAT_00960184)();
extern void* (*DAT_00960178)();
extern void* (*DAT_00960178_abs[])(...);
extern f32 DAT_00960088;
extern u8 DAT_00960088_abs[];
extern void* DAT_007cdf48;
extern void* DAT_007cdf54;
extern void* DAT_007cdf58;
extern void* DAT_007cdf84;
extern void* DAT_007cdf88;
extern s32 DAT_007e094e;
extern s32 DAT_007e0958;
extern u8 DAT_007e094e_abs[];
extern u8 DAT_007e0958_abs[];
extern u32 DAT_00833a50[];
extern s32 iGpffffb258;
extern s32 uGpffffb290;
extern s32 uGpffffb28c;
extern s32 iGpffffb28c;
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
extern void FUN_00113a30_camp_reordered(u32 color, f32 depth, f32 x,
                                        f32 y, s32 width, s32 height);
extern u32 FUN_00114450();
extern void campDataDrawPersonaSprite(f32 alpha, f32 slidePosition, f32 depth,
                                      s32 mode, u32 color, u32 width,
                                      u32 height, void* resource);
extern void FUN_001159f0(f32 x, f32 y, ...);
extern void FUN_001159f0_typed(void* owner, void* atlas, s32 tile, u8 alpha,
                                f32 x, f32 y, f32 depth);
extern u32 FUN_00115bc0();
extern void FUN_00115bc0_typed(void* owner, void* atlas, s32 tile, u8 alpha,
                                u32 red, u32 green, u32 blue, f32 x, f32 y,
                                f32 depth);
extern void campDataDrawSpriteDirect(f32 x, f32 y, f32 depth);
extern void campDataDrawSpriteAltDirect(f32 x, f32 y, f32 depth);
extern void campDataDrawDigitsDirect(f32 x, f32 y, f32 depth);
extern void campDataDrawSpriteFade(f32 x, f32 y, f32 depth,
                                   void* atlas, s32 tile, s32 alpha);
extern void campDataDrawSpriteAltFade(f32 x, f32 y, f32 depth,
                                      void* atlas, s32 tile, s32 alpha,
                                      s32 red, s32 green, s32 blue, s32 flags);
extern u32 FUN_00115de0();
extern u32 FUN_00119f10();
extern void* campDataCreateTask(void* task, s32 mode);
extern u32 FUN_0011abd0();
extern u32 FUN_00122710(KwlnTask* task, u32 command);
extern u32 FUN_0012a560(f32, RwV2d, void*, s32);
extern u32 FUN_0012ac60(f32, RwV2d, void*, s32);
extern u32 FUN_00129b30(f32, RwV2d, void*, s32);
extern void FUN_0013c240(void* work, s16 pcId, s16 equipmentType);
extern void FUN_0013c780(void* work);
extern void FUN_0013cf80(u64 pcId, void* work);
extern void FUN_0013d1a0(f32 texture, CampFloatPair position, void* work, s32 alpha);
extern void FUN_0013fca0(f32 texture, u64 position, void* work, s32 alpha);
extern void campDataDrawEquipment(f32 depth, CampFloatPair position,
                                  void* work, s32 alpha);
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
extern s32 FUN_003b2cb0(s32 param_2, s32 param_3, f32 param_1, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9);
extern s32 campDataDrawTextRaw(f32 scale, s32 x, s32 y, s32 color,
                               s32 font, s32 alignment, const char* text,
                               s32 maxWidth, s32 shadow);
extern u32 FUN_003c7430(u64 param_1);
extern u32 FUN_003c74e0(s32 param_1);
extern void FUN_003c7560(u8 param_1);
extern u32 FUN_003c7610();
extern u32 FUN_003c7700();
extern u32 FUN_003c7850();
extern void FUN_003c7d80(s32 param_1, void* param_2);
extern void FUN_003c7e20(u32 p1, u32 p2, f32 p3, u32 p4, u32 p5, u32 p6, u32 p7, u32 p8);
extern void campDataDrawDigits(f32 depth, s32 x, s32 y, s32 color,
                               s32 style, s32 font, s32 alignment, u32 value);
extern u32 FUN_0040eb50();
extern s32 campDataDrawText(f32 scale, s32 x, s32 y, u8 color, s16 font,
                            const char* text, s32 maxWidth);
extern u32 FUN_00521250();
extern u32 FUN_00523ac8_y2();
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
extern u8 D_005DBF20_abs[];
extern u8 D_005DBF40_abs[];
extern u8 D_005DBF70_abs[];
extern u8 D_005DBFA0_abs[];
extern u8 D_005DBFD0_abs[];
extern const char D_005DC000[];
extern const char D_005E30B0[];
extern const char D_005E31F0[];
extern const char D_005E3200[];
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
extern void campDataDrawListA(f32 depth, void* resources, RwV2d coordinates,
                              void* list, s32 alpha);
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
typedef struct CampBridgeStateWork
{
    u32 state;          /* 0x00 */
    u32 mode;           /* 0x04 */
    u32 setupTask;      /* 0x08 */
    u32 activeTask;     /* 0x0c */
    u32 screenMode;     /* 0x10 */
} CampBridgeStateWork;
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

static inline u8 datGetLevel_impl(s16 pcId)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        return datCalcGetLevel(&gGlobalWork.heroUnit);
    }

    pc = &gPcs[2];
    return datCalcGetLevel(&pc[pcId - 2].unit);
}
static inline u32 datGetNextExp_impl(s16 pcId)
{
    DatPersonaWork* persona;

    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroStatus.nextExp;
    }

    persona = datPersonaGetByPcId(pcId);
    K_ASSERT(persona != NULL, 622);
    return datPersonaGetNextExp(persona);
}
static inline u8 func_0016d280_impl(s32 exp)
{
    u8 index;
    u8 level;
    const u32* thresholds;

    level = 0;
    index = 0;
    thresholds = sPlayerExpThreshold;
    while (index < MAX_CHARACTER_LEVEL)
    {
        if (exp < (s32)thresholds[index])
        {
            return level;
        }
        level++;
        index++;
    }
    return MAX_CHARACTER_LEVEL;
}
static inline u16 func_00170760_impl(s16 pcId, s16 index)
{
    u8* idBase;
    u8* heroEquip;
    s32 address;
    s32 i;

    if (pcId == PC_HERO)
    {
        heroEquip = *(u8* volatile /* Removing this inline-helper qualifier loses func_00170c00 (MATCH nd0 -> MISMATCH nd15, size 348 -> 348) - measured W170. */*)&gGlobalWork.heroEquip.unkPtr;
        address = index * 2;
        address += (s32)heroEquip;
        return *(u16*)(address - 8000);
    }
    if (pcId == -1)
    {
        return *(u16*)(D_00831CE0 + index * 2);
    }
    if (pcId < 0x100)
    {
        goto invalid;
    }

    i = 0;
    idBase = (u8*)gPcs + pcId * 0x364;
    for (; i < 20; i++)
    {
        if (*(u16*)(idBase + i * 4 - 0x367b8) == pcId)
        {
            return *(u16*)(D_007FD85A + pcId * 0x364 + i * 4);
        }
    }
    return 0;
invalid:
    return 0;
}
static inline void* func_00170d60_impl(s16 id)
{
    if (id < 1000)
    {
        return D_007CDFE4 + id * 0x28;
    }
    return NULL;
}
static inline void* func_00170da0_impl(s16 id)
{
    if (id >= 1000 && id < 2000)
    {
        return D_007CDFDC + (id - 1000) * 0x20;
    }
    return NULL;
}
static inline void* func_00170df0_impl(s16 id)
{
    if (id >= 2000 && id < 3000)
    {
        return D_007CDFD8 + (id - 2000) * 0x20;
    }
    return NULL;
}
static inline void* func_00170e40_impl(s16 id)
{
    if (id >= 3000 && id < 4000)
    {
        return D_007CDFD4 + (id - 3000) * 0x24;
    }
    return NULL;
}
static inline void* func_00170e90_impl(s16 id)
{
    if (id >= 3000)
    {
        return D_007CDFCC + (id - 4000) * 0x1c;
    }
    return NULL;
}
static inline void* func_00170ed0_impl(s16 id, s32* category)
{
    if (id < 1000)
    {
        *category = 0;
        return func_00170d60_impl(id);
    }
    if (id < 2000)
    {
        *category = 1;
        return func_00170da0_impl(id);
    }
    if (id < 3000)
    {
        *category = 2;
        return func_00170df0_impl(id);
    }
    if (id < 4000)
    {
        *category = 3;
        return func_00170e40_impl(id);
    }

    *category = 4;
    return func_00170e90_impl(id);
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

// FUN_0016c470
u8 datGetLevel(s16 pcId)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        return datCalcGetLevel(&gGlobalWork.heroUnit);
    }

    pc = &gPcs[2];

    return datCalcGetLevel(&pc[pcId - 2].unit);
}

// FUN_0016c4f0
u16 datGetHp(s16 pcId)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        return datCalcGetHp(&gGlobalWork.heroUnit);
    }

    pc = &gPcs[2];

    return datCalcGetHp(&pc[pcId - 2].unit);
}



// FUN_0016c570
u16 datGetSp(s16 pcId)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        return datCalcGetSp(&gGlobalWork.heroUnit);
    }

    pc = &gPcs[2];

    return datCalcGetSp(&pc[pcId - 2].unit);
}

// FUN_0016c5f0
u16 datGetMaxHp(s16 pcId)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        return datCalcGetMaxHp(&gGlobalWork.heroUnit);
    }

    pc = &gPcs[2];

    return datCalcGetMaxHp(&pc[pcId - 2].unit);
}

// FUN_0016c670
u16 func_0016c670(s16 pcId)
{
    if (IS_HERO(pcId))
    {
        return func_00300100(&gGlobalWork.heroUnit);
    }

    return func_00300100(&gPcs[pcId - 2].unit);
}

// FUN_0016c6f0
s16 datGetAcademicPoint(s16 pcId)
{
    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroStatus.socialStats.academicPoint;
    }

    return gPcs[pcId].socialStats.academicPoint;
}

// FUN_0016c740
s16 datGetCharmPoint(s16 pcId)
{
    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroStatus.socialStats.charmPoint;
    }

    return gPcs[pcId].socialStats.charmPoint;
}

// FUN_0016c790
s16 datGetCouragePoint(s16 pcId)
{
    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroStatus.socialStats.couragePoint;
    }

    return gPcs[pcId].socialStats.couragePoint;
}

// FUN_0016c7e0
u32 datGetNextExp(s16 pcId)
{
    DatPersonaWork* persona; // per

    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroStatus.nextExp;
    }

    persona = datPersonaGetByPcId(pcId);
    K_ASSERT(persona != NULL, 622);

    return datPersonaGetNextExp(persona);
}

// FUN_0016c860
u16 datGetPersonaId(s16 pcId)
{
    DatPc* pc;
    s16 equipped;

    if (IS_HERO(pcId))
    {
        equipped = gGlobalWork.heroPersona.equippedPersona;

        K_ASSERT(equipped < 12, 633);

        return gGlobalWork.heroPersona.personas[equipped].id;
    }

    pc = &gPcs[2];

    return pc[pcId - 2].persona.id;
}

// FUN_0016c910
s16 datGetEquippedPersona()
{
    return gGlobalWork.heroPersona.equippedPersona;
}

// FUN_0016c920
u16 datGetPhysicalCondition(s16 pcId)
{
    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroStatus.physicalState.physicalCondition;
    }

    return gPcs[pcId].physicalState.physicalCondition;
}

// FUN_0016c970
u32 datGetBadStatusNoDown(s16 pcId)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        return datCalcGetBadStatusNoDown(&gGlobalWork.heroUnit);
    }

    pc = &gPcs[2];

    return datCalcGetBadStatusNoDown(&pc[pcId - 2].unit);
}

// FUN_0016c9f0
u16 datGetFatigueCounter(s16 pcId)
{
    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroStatus.physicalState.fatigueCounter;
    }

    return gPcs[pcId].physicalState.fatigueCounter;
}

// FUN_0016ca40
u16 datGetOldFatigueCounter(s16 pcId)
{
    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroStatus.physicalState.oldFatigueCounter;
    }

    return gPcs[pcId].physicalState.oldFatigueCounter;
}

// FUN_0016ca90
void FUN_0016ca90(s16 pcId, s16 fatigueChange)
{
    extern void datSetFatigueCounter(s16, s16);
    u16 rawFatigueCounter;
    s32 fatigueCounter;
    s32 oldFatigueCounter;
    s32 newFatigueCounter;

    if (IS_HERO(pcId))
    {
        rawFatigueCounter = gGlobalWork.heroStatus.physicalState.fatigueCounter;
    }
    else
    {
        rawFatigueCounter = gPcs[pcId].physicalState.fatigueCounter;
    }
    fatigueCounter = rawFatigueCounter;

    if (IS_HERO(pcId))
    {
        rawFatigueCounter = gGlobalWork.heroStatus.physicalState.oldFatigueCounter;
    }
    else
    {
        rawFatigueCounter = gPcs[pcId].physicalState.oldFatigueCounter;
    }
    oldFatigueCounter = rawFatigueCounter;

    newFatigueCounter = fatigueCounter + fatigueChange;
    if (newFatigueCounter < 0)
    {
        newFatigueCounter = 0;
    }
    else if (newFatigueCounter > oldFatigueCounter)
    {
        newFatigueCounter = oldFatigueCounter;
    }

    datSetFatigueCounter(pcId, newFatigueCounter);
}

// FUN_0016cb80
s16 datGetEquipmentIdx(s16 pcId, s16 equipmentType)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroEquip.equipmentsIdx[equipmentType];
    }

    pc = &gPcs[2];

    return pc[pcId - 2].equipmentsIdx[equipmentType];
}

// FUN_0016cc00
u16 func_0016cc00(s16 pcId)
{
    u8 level;

    if (IS_HERO(pcId))
    {
        level = datCalcGetLevel(&gGlobalWork.heroUnit);
    }
    else
    {
        DatPc* pc = &gPcs[2];
        level = datCalcGetLevel(&pc[pcId - 2].unit);
    }

    return *(u16*)(D_005DC1B4 + level * 0x2c + pcId * 4);
}

// FUN_0016ccb0
u16 func_0016ccb0(s16 pcId)
{
    u8 level;

    if (IS_HERO(pcId))
    {
        level = datCalcGetLevel(&gGlobalWork.heroUnit);
    }
    else
    {
        DatPc* pc = &gPcs[2];
        level = datCalcGetLevel(&pc[pcId - 2].unit);
    }

    return *(u16*)(D_005DC1B4 + level * 0x2c + pcId * 4);
}

// FUN_0016cd60
DatUnit* datGetUnit(s16 pcId)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        return &gGlobalWork.heroUnit;
    }

    K_ASSERT(pcId < PC_MAX, 737);

    pc = &gPcs[2];

    return &pc[pcId - 2].unit;
}

/* W357 measured optimization_level 1: without nd8/object96 (MISMATCH), with nd0/object96 (MATCH); retained. */
// FUN_0016cdf0
void datInitUnit(s16 pcId)
{
    u32 idx;
    DatPc* pcsNoReserved;

    if (IS_HERO(pcId))
    {
        memset(&gGlobalWork.heroUnit, 0, sizeof(DatUnit));

        gGlobalWork.heroUnit.id = pcId;
        gGlobalWork.heroUnit.id2 = pcId;
        gGlobalWork.heroUnit.aiTactic = AI_TACTIC_ACT_FREELY;

        return;
    }

    idx = pcId - PC_YUKARI;
    pcsNoReserved = &gPcs[PC_YUKARI];
    memset(&pcsNoReserved[idx].unit, 0, sizeof(DatUnit));

    gPcs[pcId].unit.id = pcId;
    gPcs[pcId].unit.id2 = pcId;
    gPcs[pcId].unit.aiTactic = AI_TACTIC_ACT_FREELY;
}
// FUN_0016cef0
void datSetLevel(s16 pcId, u8 level)
{
    if (IS_HERO(pcId))
    {
        gGlobalWork.heroUnit.level = level;
    }
    else
    {
        K_ASSERT(false, 770);
    }
}
// FUN_0016cf40
void datSetHp(s16 pcId, s16 hp)
{
    if (IS_HERO(pcId))
    {
        gGlobalWork.heroUnit.hp = hp;
    }
    else
    {
        gPcs[pcId].unit.hp = hp;
    }
}

// FUN_0016cf90
void datSetSp(s16 pcId, s16 sp)
{
    if (IS_HERO(pcId))
    {
        gGlobalWork.heroUnit.sp = sp;
    }
    else
    {
        gPcs[pcId].unit.sp = sp;
    }
}

// FUN_0016cfe0
void datSetAcademicPoint(s16 pcId, s16 academicPoint)
{
    K_ASSERT(academicPoint >= SOCIAL_STAT_MIN_POINT && academicPoint <= SOCIAL_STAT_MAX_POINT, 797);

    if (IS_HERO(pcId))
    {
        gGlobalWork.heroStatus.socialStats.academicPoint = academicPoint;
        return;
    }

    gPcs[pcId].socialStats.academicPoint = academicPoint;
}

// FUN_0016d090
void datSetCharmPoint(s16 pcId, s16 charmPoint)
{
    K_ASSERT(charmPoint >= SOCIAL_STAT_MIN_POINT && charmPoint <= SOCIAL_STAT_MAX_POINT, 808);

    if (IS_HERO(pcId))
    {
        datGetCharmLevel(gGlobalWork.heroStatus.socialStats.charmPoint);
        gGlobalWork.heroStatus.socialStats.charmPoint = charmPoint;
        datGetCharmLevel(gGlobalWork.heroStatus.socialStats.charmPoint);
        return;
    }

    gPcs[pcId].socialStats.charmPoint = charmPoint;
}

// FUN_0016d160
void datSetCouragePoint(s16 pcId, s16 couragePoint)
{
    K_ASSERT(couragePoint >= SOCIAL_STAT_MIN_POINT && couragePoint <= SOCIAL_STAT_MAX_POINT, 828);

    if (IS_HERO(pcId))
    {
        datGetCourageLevel(gGlobalWork.heroStatus.socialStats.couragePoint);
        gGlobalWork.heroStatus.socialStats.couragePoint = couragePoint;
        datGetCourageLevel(gGlobalWork.heroStatus.socialStats.couragePoint);
        return;
    }

    gPcs[pcId].socialStats.couragePoint = couragePoint;
}

// FUN_0016d230
void datSetNextExp(s16 pcId, u32 nextExp)
{
    if (IS_HERO(pcId))
    {
        gGlobalWork.heroStatus.nextExp = nextExp;
    }
    else
    {
        K_ASSERT(false, 858);
    }
}

// FUN_0016d280
#pragma opt_loop_invariants on
u8 func_0016d280(s32 exp)
{
    u8 level = 0;
    u8 index = 0;

    while (index < MAX_CHARACTER_LEVEL)
    {
        if (exp < (s32)sPlayerExpThreshold[index])
        {
            return level;
        }
        level++;
        index++;
    }

    return MAX_CHARACTER_LEVEL;
}

// FUN_0016d2f0
u32 datGetExpUntilNextLevel(s16 pcId)
{
    u8 level;
    u32 nextThreshold;

    if (func_0016d280_impl(datGetNextExp_impl(pcId)) == MAX_CHARACTER_LEVEL)
    {
        return 0;
    }

    level = func_0016d280_impl(datGetNextExp_impl(pcId)) + 1;
    K_ASSERT(level > 0 && level <= MAX_CHARACTER_LEVEL, 876);

    nextThreshold = sPlayerExpThreshold[level - 1];
    return nextThreshold - datGetNextExp_impl(pcId);
}

// FUN_0016d560
u8 datDidCharacterLevelUp(s16 pcId, u32 expGain)
{
    u8 level;
    u8 i;
    u8 count;
    u8 resultCount;
    u8 savedCount;
    s32 exp;
    const u32* thresholds;

    if (IS_HERO(pcId))
    {
        gGlobalWork.heroStatus.nextExp += expGain;
        exp = gGlobalWork.heroStatus.nextExp;
        count = 0;
        i = 0;
        thresholds = sPlayerExpThreshold;
        for (; i < MAX_CHARACTER_LEVEL; i++)
        {
            if (exp < (s32)thresholds[i])
            {
                resultCount = count;
                goto saveCount;
            }
            count++;
        }
        resultCount = MAX_CHARACTER_LEVEL;
saveCount:
        savedCount = resultCount;
        goto getLevel;
    }
    else
    {
        K_ASSERT(false, 901);
    }

getLevel:
    level = datGetLevel_impl(pcId);
    if (savedCount != level)
    {
        return true;
    }
    return false;
}

// FUN_0016d6b0
void datSetPhysicalCondition(s16 pcId, u16 physicalCondition)
{
    u16 currentPhysicalCondition;
    u16 oldFatigueCounter;

    if (IS_HERO(pcId))
    {
        currentPhysicalCondition = gGlobalWork.heroStatus.physicalState.physicalCondition;
    }
    else
    {
        currentPhysicalCondition = gPcs[pcId].physicalState.physicalCondition;
    }

    if (currentPhysicalCondition != physicalCondition)
    {
        switch (physicalCondition)
        {
            case PHYSICAL_CONDITION_GOOD:
                FUN_0016f3e0(pcId + 15, 0);
                break;
            case PHYSICAL_CONDITION_GREAT:
                FUN_0016f3e0(pcId + 15, 1);
                FUN_0016f3e0(pcId + 25, 0);
                break;
            case PHYSICAL_CONDITION_TIRED:
                FUN_0016f3e0(pcId + 15, 50);
                break;
            case PHYSICAL_CONDITION_SICK:
                FUN_0016f3e0(pcId + 15, 60);
                break;
        }
    }

    if (currentPhysicalCondition == PHYSICAL_CONDITION_TIRED && physicalCondition != PHYSICAL_CONDITION_TIRED)
    {
        extern void datSetFatigueCounter(s16, s16);
        if (IS_HERO(pcId))
        {
            oldFatigueCounter = gGlobalWork.heroStatus.physicalState.oldFatigueCounter;
        }
        else
        {
            oldFatigueCounter = gPcs[pcId].physicalState.oldFatigueCounter;
        }
        datSetFatigueCounter(pcId, oldFatigueCounter);
    }

    if (IS_HERO(pcId))
    {
        gGlobalWork.heroStatus.physicalState.physicalCondition = physicalCondition;
    }
    else
    {
        gPcs[pcId].physicalState.physicalCondition = physicalCondition;
    }
}

// FUN_0016d8b0
void datSetBadStatus(s16 pcId, u32 flags)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        datCalcSetBadStatus(&gGlobalWork.heroUnit, flags);
        return;
    }

    pc = &gPcs[2];

    datCalcSetBadStatus(&pc[pcId - 2].unit, flags);
}

// FUN_0016d930
void datSetFatigueCounter(s16 pcId, u16 fatigueCounter)
{
    if (IS_HERO(pcId))
    {
        gGlobalWork.heroStatus.physicalState.fatigueCounter = fatigueCounter;
        return;
    }

    gPcs[pcId].physicalState.fatigueCounter = fatigueCounter;
}

// FUN_0016d980
void datSetOldFatigueCounter(s16 pcId, u16 oldFatigueCounter)
{
    if (IS_HERO(pcId))
    {
        gGlobalWork.heroStatus.physicalState.oldFatigueCounter = oldFatigueCounter;
        return;
    }

    gPcs[pcId].physicalState.oldFatigueCounter = oldFatigueCounter;
}

// FUN_0016d9d0
void datClearBadStatus(s16 pcId, u32 flags)
{
    DatPc* pc;

    if (IS_HERO(pcId))
    {
        datCalcClearBadStatus(&gGlobalWork.heroUnit, flags);
        return;
    }

    pc = &gPcs[2];

    datCalcClearBadStatus(&pc[pcId - 2].unit, flags);
}

// FUN_0016da50
void datSetEquipmentIdx(s16 pcId, s16 equipmentType, s16 equipmentIdx)
{
    if (IS_HERO(pcId))
    {
        gGlobalWork.heroEquip.equipmentsIdx[equipmentType] = equipmentIdx;
    }
    else
    {
        gPcs[pcId].equipmentsIdx[equipmentType] = equipmentIdx;
    }
}

// FUN_0016dad0
void datSetAiTactic(s16 pcId, s16 aiTacticId)
{
    K_ASSERT(aiTacticId < AI_TACTIC_MAX, 999);

    if (IS_HERO(pcId))
    {
        gGlobalWork.heroUnit.aiTactic = aiTacticId;
        return;
    }

    gPcs[pcId].unit.aiTactic = aiTacticId;
}

// FUN_0016db70
void datInitSocialLink()
{
    memset(&gGlobalWork.heroStatus.activeSocialLink, 0, 0x508);
}

// FUN_0016dba0
s8 datGetSocialLinkLevel(s16 socialLink)
{
    return gGlobalWork.heroStatus.socialLinkStat[socialLink];
}

#pragma opt_loop_invariants off

/* Removing this loses FUN_0016dbc0 (MATCH nd0 -> MISMATCH nd108) - measured W161. */
#pragma opt_loop_invariants on
// FUN_0016dbc0
u8 func_0016dbc0(s16 socialLink, u32* personaId)
{
    s8 arcana;
    u32 found = false;
    u8 bestLevel = 0;
    s32 bestPersonaId = -1;
    u16 i;

    arcana = (s8)func_0016df30(socialLink);
    for (i = 0; i < 12; i++)
    {
        DatPersonaWork* persona;
        u8 personaArcana;

        if (!datPersonaHeroPersonaValid(i))
        {
            continue;
        }

        persona = datPersonaGetHeroPersona(i);
        personaArcana = (u8)FUN_00173280(persona->id);
        if (personaArcana != arcana ||
            bestLevel >= persona->level)
        {
            continue;
        }

        found = true;
        bestPersonaId = persona->id;
        bestLevel = persona->level;
    }

    if (found == true)
    {
        *personaId = bestPersonaId;
        return true;
    }

    return false;
}

#pragma opt_loop_invariants off

// FUN_0016dce0
u32 func_0016dce0(s16 socialLink)
{
    if (socialLink < 0 || socialLink >= 30)
    {
        return false;
    }
    return true;
}

// FUN_0016dd20
s8 func_0016dd20(s16 socialLink)
{
    return gGlobalWork.heroStatus.socialLinkData[0x78 + socialLink];
}

// FUN_0016dd40
s16 datGetActiveSocialLink()
{
    return gGlobalWork.heroStatus.activeSocialLink;
}

// FUN_0016dd50
s32 datGetMoney()
{
    return gGlobalWork.heroMoney;
}

// FUN_0016dd60
s16 datGetPartyId(s32 idx)
{
    return gGlobalWork.partyIds[idx];
}

// FUN_0016dd80
s32 datGetAiTactic(s16 pcId)
{
    if (IS_HERO(pcId))
    {
        return gGlobalWork.heroUnit.aiTactic;
    }

    return gPcs[pcId].unit.aiTactic;
}

// FUN_0016ddd0
void func_0016ddd0(s32 index)
{
    u8* value;

    K_ASSERT(index < 8 && index >= 0, 1257);
    value = D_00836773 + index;
    if (*value < 200)
    {
        *value += 1;
    }
    else
    {
        *value = 200;
    }
}

// FUN_0016de50
u8 func_0016de50(s32 index)
{
    K_ASSERT(index < 8 && index >= 0, 1290);

    return gGlobalWork.heroStatus.socialLinkData[0x4df + index];
}

// FUN_0016deb0
#pragma opt_loop_invariants on
s16 func_0016deb0(s16 arcana)
{
    s32 socialLink;
    s32 bestLevel;
    s16 bestLink;

    bestLevel = -1;
    bestLink = bestLevel;
    for (socialLink = 0; socialLink < 30; socialLink++)
    {
        if (D_005E3220[socialLink] == arcana &&
            bestLevel < gGlobalWork.heroStatus.socialLinkStat[socialLink])
        {
            bestLink = socialLink;
            bestLevel = gGlobalWork.heroStatus.socialLinkStat[socialLink];
        }
    }

    return bestLink;
}

#pragma opt_loop_invariants off

// FUN_0016df30
s8 func_0016df30(s16 socialLink)
{
    u32 valid;

    if (socialLink < 0 || socialLink >= 30)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    if (!valid)
    {
        FUN_0019d3f0_y2((u32)D_005E3098, 0x54b);
    }

    return ((s8*)D_005E3220)[socialLink];
}

#pragma opt_propagation off
u32 datSocialLinkLevelIsNotZero(s16 socialLink);
// FUN_0016dfb0
void func_0016dfb0(s16 socialLink)
{
    s32 rank;
    s16 finalSocialLink;
    s16 socialLinkValue;
    u32 valid;

    if (socialLink < 0 || socialLink >= 30)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 1370);
    if (datSocialLinkLevelIsNotZero(socialLink) != true)
    {
        func_0016e410(socialLink, 1);
        socialLinkValue = socialLink;
        FUN_00171E90(socialLinkValue, 0);
        FUN_00171C40(socialLinkValue, 0);
        FUN_00172200_s16(socialLinkValue, 0);
        for (rank = 1; rank <= 10; rank++)
        {
            FUN_001724A0(socialLinkValue, rank, false);
            FUN_001723A0(socialLinkValue, rank, false);
        }
        finalSocialLink = socialLink;
        FUN_001723A0(finalSocialLink, 1, true);
        FUN_001724A0(finalSocialLink, 1, true);
    }
}

// FUN_0016e100
u32 datSocialLinkLevelIsNotZero(s16 socialLink)
{
    u32 isValidSocialLink;

    if (socialLink < SOCIAL_LINK_SEES || socialLink >= 30)
    {
        isValidSocialLink = false;
    }
    else
    {
        isValidSocialLink = true;
    }

    K_ASSERT(isValidSocialLink, 1429);

    if (gGlobalWork.heroStatus.socialLinkStat[socialLink] <= 0)
    {
        return false;
    }

    return true;
}

#pragma opt_propagation on

// FUN_0016e190
s16 func_0016e190(s32 socialLink)
{
    struct LinkedSocialLink
    {
        s16 socialLink;
        s16 value;
    };
    s32 i;
    s32 socialLinkOffset;
    struct LinkedSocialLink links[2][3] = {
        { { 12, 1 }, { 13, 2 }, { 14, 3 } },
        { { 17, 4 }, { 18, 5 }, { 19, 6 } }
    };
    struct LinkedSocialLink* selectedLinks;

    i = 0;
    socialLinkOffset = socialLink * 3;
    selectedLinks = &links[0][0] + socialLinkOffset;
    for (; i < 3; i++)
    {
        s16 linkedSocialLink;
        u32 valid;

        linkedSocialLink = selectedLinks[i].socialLink;
        if (linkedSocialLink < 0 || linkedSocialLink >= 30)
        {
            valid = false;
        }
        else
        {
            valid = true;
        }
        K_ASSERT(valid, 1429);
        if (((s8*)&gGlobalWork)[linkedSocialLink + 0x76] > 0)
        {
            return (&links[0][0])[i + socialLinkOffset].value;
        }
    }

    return 0;
}

// FUN_0016e2b0 NONMATCHING
void func_0016e2b0(s16 socialLink, s32 amount)
{
    s8* socialLinkBase;
    s8 level;
    u32* progress;
    u32* table;
    u32 personaId;

    socialLinkBase = gGlobalWork.heroStatus.socialLinkStat + socialLink;
    level = socialLinkBase[0];
    if (socialLink < 0 || socialLink >= 30)
    {
        return;
    }
    socialLink = socialLinkBase[0x76];
    if (socialLink <= 0 || socialLink >= 10)
    {
        return;
    }
    if (func_0016dbc0(socialLink, &personaId) == true)
    {
        amount = (s32)((f32)amount * FUN_003BDB80());
    }
    progress = (u32*)((u8*)&gGlobalWork + 0x94 + socialLink * 4);
    *progress += amount;
    table = (u32*)FUN_003BDD90();
    K_ASSERT(table != NULL, 1495);
    if (*progress < table[(u8)level - 1])
    {
        return;
    }
    *progress = table[(u8)level - 1];
    FUN_001723A0(socialLink, level + 1, true);
}

#pragma opt_propagation off
// FUN_0016e410
void func_0016e410(s16 socialLink, s8 level)
{
    extern u8 D_00836294[];
    s16 socialLinkValue;
    s32 levelValue;
    s32 rank;
    u32 valid;
    u32 enabled;
    u32 tableValue;
    u32* tableWords;
    u8* table;

    levelValue = level;
    K_ASSERT(levelValue <= 10, 1516);
    socialLinkValue = socialLink;
    gGlobalWork.heroStatus.socialLinkStat[socialLinkValue] = level;
    FUN_00171B50(socialLinkValue);

    if (levelValue < 2)
    {
        if (socialLinkValue < 0 || socialLinkValue >= 30)
        {
            valid = false;
        }
        else
        {
            valid = true;
        }
        if (valid)
        {
            *(u32*)(D_00836294 + socialLinkValue * 4) = 0;
        }
    }
    if (levelValue > 1 && levelValue <= 10)
    {
        table = FUN_003BDD90(socialLinkValue);
        K_ASSERT(table != NULL, 1528);
        tableWords = (u32*)table;
        tableValue = tableWords[levelValue - 2];
        if (socialLinkValue < 0 || socialLinkValue >= 30)
        {
            valid = false;
        }
        else
        {
            valid = true;
        }
        if (valid)
        {
            *(u32*)(D_00836294 + socialLinkValue * 4) =
                tableValue;
        }
    }

    for (rank = 1; rank <= 10; rank++)
    {
        enabled = false;
        if (rank <= levelValue)
        {
            enabled = true;
        }
        FUN_001723A0(socialLinkValue, rank, enabled);
        FUN_001724A0(socialLinkValue, rank, enabled);
    }
    func_0016e5f0_call(socialLink, 0);
}
#pragma opt_propagation reset

// FUN_0016e5f0
void func_0016e5f0(s32 socialLink, s8 progress)
{
    u32 isValidSocialLink;
    s16 index;
    s8* base;
    s8* value;

    index = socialLink;
    if (index < 0 || index >= 30)
    {
        isValidSocialLink = false;
    }
    else
    {
        isValidSocialLink = true;
    }

    if (!isValidSocialLink)
    {
        return;
    }

    base = (s8*)&gGlobalWork + 0x630c;
    value = base + (s16)socialLink;
    *value = progress;
    if (progress < 0)
    {
        *value = 0;
    }
    if (*value >= 10)
    {
        *value = 9;
    }
}

// FUN_0016e670
void func_0016e670(s16 socialLink)
{
    u32 isValidSocialLink;
    s16 index;
    s8* base;
    s8* progress;

    index = socialLink;
    if (index < 0 || index >= 30)
    {
        isValidSocialLink = false;
    }
    else
    {
        isValidSocialLink = true;
    }

    if (!isValidSocialLink)
    {
        return;
    }

    if (index < SOCIAL_LINK_SEES || index >= 30)
    {
        isValidSocialLink = false;
    }
    else
    {
        isValidSocialLink = true;
    }
    K_ASSERT(isValidSocialLink, 1429);

    if (gGlobalWork.heroStatus.socialLinkStat[index] <= 0)
    {
        K_ABORT(D_005E3260, 0x620);
        return;
    }
    base = (s8*)&gGlobalWork + 0x10c;
    progress = base + (s64)socialLink;
    *progress += 1;
    if (*progress < 0)
    {
        *progress = 0;
    }
    if (*progress >= 10)
    {
        *progress = 9;
    }
}

// FUN_0016e7a0
void func_0016e7a0(s16 socialLink, s16 day)
{
    u32 isValidSocialLink;

    if (socialLink < 0 || socialLink >= 30)
    {
        isValidSocialLink = false;
    }
    else
    {
        isValidSocialLink = true;
    }

    if (!isValidSocialLink)
    {
        return;
    }

    if (day < 0)
    {
        ((s16*)((u8*)&gGlobalWork + 0x632a))[socialLink] = 0;
        return;
    }
    if (day <= 360)
    {
        goto dayInRange;
    }
    day = 360;
    ((s16*)((u8*)&gGlobalWork + 0x632a))[socialLink] = day;
    return;

dayInRange:
    ((s16*)((u8*)&gGlobalWork + 0x632a))[socialLink] = day;
}

// FUN_0016e850
s16 func_0016e850(s16 socialLink)
{
    u32 isValidSocialLink;
    s16* dayPtr;
    s16 day;

    if (socialLink < 0 || socialLink >= 30)
    {
        isValidSocialLink = false;
    }
    else
    {
        isValidSocialLink = true;
    }

    K_ASSERT(isValidSocialLink, 1612);
    dayPtr = ((s16*)((u8*)&gGlobalWork + 0x632a)) + socialLink;
    if (*dayPtr == 0)
    {
        return 0;
    }

    day = datGetDaysSinceApr5() - *dayPtr;
    K_ASSERT(day >= 0, 1620);
    return day;
}

// FUN_0016e920
void datSetActiveSocialLink(u16 activeSocialLink)
{
    gGlobalWork.heroStatus.activeSocialLink = activeSocialLink;
}

// FUN_0016e930
void datSetMoney(u32 money)
{
    K_ASSERT(money <= 9999999, 1674);

    gGlobalWork.heroMoney = money;
}

// FUN_0016e990
void datSetPartyId(s32 idx, s16 pcId)
{
    gGlobalWork.partyIds[idx] = pcId;
}

// FUN_0016e9b0
u32 datAddMoney(s32 amount)
{
    s32 finalMoney;

    finalMoney = amount + gGlobalWork.heroMoney;
    if (finalMoney > 9999999)
    {
        finalMoney = 9999999;
    }
    else if (finalMoney < 0)
    {
        finalMoney = 0;
    }

    K_ASSERT((u32)finalMoney <= 9999999, 1674);

    gGlobalWork.heroMoney = finalMoney;

    return finalMoney;
}

// FUN_0016ea40
s32 func_0016ea40(s32 amount)
{
    s32 total = amount + gGlobalWork.heroMoney;

    if (total > 9999999)
    {
        return 1;
    }
    return -(total < 0);
}

#pragma opt_loop_invariants on
// FUN_0016ea80
u32 func_0016ea80(void)
{
    s32 i;
    s32 j;
    s32 found = false;
    s16* slot;

    for (i = 0; i < 3; i++)
    {
        if (gGlobalWork.partyIds[i] == scrGetIntPara(1))
        {
            found = true;
        }
    }

    if (!found)
    {
        for (j = 0; j < 3; j++)
        {
            slot = &gGlobalWork.partyIds[j];
            if (*slot == PC_NONE)
            {
                *slot = scrGetIntPara(1);
                found = true;
                break;
            }
        }
    }

    if (!found)
    {
        gGlobalWork.partyIds[3] = scrGetIntPara(1);
    }

    return true;
}

// FUN_0016eb80
#pragma optimization_level 1
u32 datScrCmd_SAVE_PARTY()
{
    s16 i;
    u32 offset;
    DatGlobal* globalWork;
    s16 value;
    s16* savedIds;

    i = 0;
    globalWork = &gGlobalWork;
    savedIds = sSavedPartyIds;
    for (; i < 4; i++)
    {
        offset = (u32)(s16)i * 2;
        value = *(s16*)((u8*)globalWork + 0x44e0 + offset);
        *(s16*)((u8*)savedIds + offset) = value;
    }

    return true;
}

#pragma optimization_level 2

/* W357 measured optimization_level 1: without nd8/object96 (MISMATCH), with nd0/object96 (MATCH); retained. */
// FUN_0016ebe0
#pragma optimization_level 1
u32 datScrCmd_RESTORE_PARTY()
{
    s16 i;
    u32 offset;
    s16* savedIds;
    s16 value;
    DatGlobal* globalWork;

    i = 0;
    savedIds = sSavedPartyIds;
    globalWork = &gGlobalWork;
    for (; i < 4; i++)
    {
        offset = (u32)(s16)i * 2;
        value = *(s16*)((u8*)savedIds + offset);
        *(s16*)((u8*)globalWork + 0x44e0 + offset) = value;
    }
    return true;
}

#pragma optimization_level 2

// FUN_0016ec40
u32 datScrCmd_CLEAR_PARTY_ID()
{
    gGlobalWork.partyIds[scrGetIntPara(0)] = PC_NONE;

    return true;
}

// FUN_0016ec80
u32 datScrCmd_GET_PARTY_ID()
{
    scrSetIntReturnVal(gGlobalWork.partyIds[scrGetIntPara(0)]);

    return true;
}

#pragma opt_loop_invariants off

/* Removing this loses FUN_0016ecd0 (MATCH nd0 -> MISMATCH nd105) - measured W161. */
#pragma opt_loop_invariants on
// FUN_0016ecd0
u32 func_0016ecd0(void)
{
    s32 i;
    s32 j;
    s16* slot;
    s16 current;

    for (i = 0; i < 4; i++)
    {
        slot = &gGlobalWork.partyIds[i];
        current = *slot;
        if (current == scrGetIntPara(0))
        {
            *slot = PC_NONE;
            break;
        }
    }

    for (j = 0; j < 4; j++)
    {
        if (gGlobalWork.partyIds[j] == PC_NONE)
        {
            for (; j < 3; j++)
            {
                gGlobalWork.partyIds[j] = gGlobalWork.partyIds[j + 1];
            }
            break;
        }
    }

    return true;
}

// FUN_0016edd0
u32 datScrCmd_GET_MONEY()
{
    scrSetIntReturnVal(gGlobalWork.heroMoney);

    return true;
}

// FUN_0016ee00
u32 datScrCmd_ADD_MONEY()
{
    s32 baseMoney;
    s32 finalMoney;

    baseMoney = gGlobalWork.heroMoney;
    finalMoney = baseMoney + scrGetIntPara(0);
    if (finalMoney > 9999999)
    {
        finalMoney = 9999999;
    }

    K_ASSERT((u32)finalMoney <= 9999999, 1674);

    gGlobalWork.heroMoney = finalMoney;

    return true;
}

// FUN_0016ee90
u32 datScrCmd_REMOVE_MONEY()
{
    s32 baseMoney;
    s32 finalMoney;

    baseMoney = gGlobalWork.heroMoney;
    if (baseMoney < scrGetIntPara(0))
    {
        finalMoney = 0;
    }
    else
    {
        finalMoney = baseMoney - scrGetIntPara(0);
    }

    K_ASSERT((u32)finalMoney <= 9999999, 1674);

    gGlobalWork.heroMoney = finalMoney;

    return true;
}

// FUN_0016ef20
s16 datGetDaysSinceApr5()
{
    return gGlobalWork.calendarWork.daysSinceApr5;
}

// FUN_0016ef30
u8 datGetTime()
{
    return gGlobalWork.calendarWork.time;
}

// FUN_0016ef40
s16 datGetDaysSkipTarget()
{
    return gGlobalWork.calendarWork.daysSkipTarget;
}

// FUN_0016ef50
u8 datGetTimeSkipTarget()
{
    return gGlobalWork.calendarWork.timeSkipTarget;
}

// FUN_0016ef60
u32 datGetSkipToTarget()
{
    return gGlobalWork.calendarWork.skipToTarget;
}


/* Removing this loses FUN_0016d280 (MATCH nd0 -> MISMATCH nd19) - measured W161. */
// FUN_0016ef70. Updates 'daysSinceApr5' and sets the correct 'FLG_DAY_*' flags
void datSetDaysSinceApr5(s16 daysSinceApr5)
{
    u32 currentWeekDay;

    datSetFlag(FLG_DAY_IS_MONDAY, false);
    datSetFlag(FLG_DAY_IS_TUESDAY, false);
    datSetFlag(FLG_DAY_IS_WEDNESDAY, false);
    datSetFlag(FLG_DAY_IS_THURSDAY, false);
    datSetFlag(FLG_DAY_IS_FRIDAY, false);
    datSetFlag(FLG_DAY_IS_SATURDAY, false);
    datSetFlag(FLG_DAY_IS_SUNDAY, false);
    datSetFlag(FLG_DAY_IS_DAYOFF, false);

    if (daysSinceApr5 != gGlobalWork.calendarWork.daysSinceApr5)
    {
        FUN_00172890(); 
        FUN_00172e10();
        datSetFlag(2444, false);
    }

    gGlobalWork.calendarWork.daysSinceApr5 = daysSinceApr5;

    currentWeekDay = datGetCurrentWeekDay();
    switch (currentWeekDay)
    {
        case CALENDAR_DAY_SUNDAY:    datSetFlag(FLG_DAY_IS_SUNDAY, true);    break;
        case CALENDAR_DAY_MONDAY:    datSetFlag(FLG_DAY_IS_MONDAY, true);    break;
        case CALENDAR_DAY_TUESDAY:   datSetFlag(FLG_DAY_IS_TUESDAY, true);   break;
        case CALENDAR_DAY_WEDNESDAY: datSetFlag(FLG_DAY_IS_WEDNESDAY, true); break;
        case CALENDAR_DAY_THURSDAY:  datSetFlag(FLG_DAY_IS_THURSDAY, true);  break;
        case CALENDAR_DAY_FRIDAY:    datSetFlag(FLG_DAY_IS_FRIDAY, true);    break;
        case CALENDAR_DAY_SATURDAY:  datSetFlag(FLG_DAY_IS_SATURDAY, true);  break;
    }

    if (clndIsHolidayOrSunday())
    {
        datSetFlag(FLG_DAY_IS_DAYOFF, true);
    }
}
// FUN_0016f150
void datSetTime(u8 time)
{
    gGlobalWork.calendarWork.time = time;
}
// FUN_0016f160
void datSetDaysSkipTarget(s16 days)
{
    gGlobalWork.calendarWork.daysSkipTarget = days;
}

// FUN_0016f170
void datSetTimeSkipTarget(s8 time)
{
    gGlobalWork.calendarWork.timeSkipTarget = time;
}

// FUN_0016f180
void datSetSkipToTarget(u32 val)
{
    gGlobalWork.calendarWork.skipToTarget = val;
}

// FUN_0016f190
u32 datGetFlag(s32 bit)
{
    s32 mask;
    s32 idx;

    idx = bit / 32;
    mask = bit % 32;

    return (gGlobalWork.flags[idx] & (1 << mask)) != 0;
}

/* Removing this loses FUN_0016deb0 (MATCH nd0 -> MISMATCH nd47) - measured W161. */
// FUN_0016f1f0. See 'g_flags.h' !!!
void datSetFlag(s32 bit, u8 enabled)
{
    s32 mask;
    s32 idx;

    K_ASSERT(bit >= 0 && bit < FLG_MAX, 1933);

    if (bit == 4982)
    {
        printf("hit \n");
    }

    idx = bit / 32;
    mask = bit % 32;
    mask = 1 << mask;
    
    if (enabled)
    {
        gGlobalWork.flags[idx] |= mask;
        return;
    }

    gGlobalWork.flags[idx] &= ~mask;
}
// FUN_0016f2e0
void datClearFlagAll()
{
    s32 i;
    DatGlobal* work;
    u32* p;

    i = 0;
    work = &gGlobalWork;
    for (; i < FLG_ARR_SIZE; i++)
    {
        p = work->flags + i;
        *p = 0;
    }
}

// FUN_0016f320
void func_0016f320(void)
{
    gGlobalWork.flags[12] |= 0x8;
    gGlobalWork.flags[12] |= 0x10;
    gGlobalWork.flags[12] &= ~0x20;
    gGlobalWork.flags[12] |= 0x40;
    gGlobalWork.flags[12] &= ~0x80;
    gGlobalWork.flags[12] &= ~0x100;
    gGlobalWork.flags[12] &= ~0x200;

    func_001754a0(1);
}
// FUN_0016f380
u32 FUN_0016f380(u32 idx)
{
    K_ASSERT((s32)idx < 128, 2001);

    return gGlobalWork.auxData[idx];
}

// FUN_0016f3e0
void FUN_0016f3e0(u32 idx, u32 value)
{
    K_ASSERT((s32)idx < 128, 2007);

    gGlobalWork.auxData[idx] = value;
}
// FUN_0016f450
void dat0016f450(void)
{
    s32 i;
    DatGlobal* work;
    u32* p;

    i = 0;
    work = &gGlobalWork;
    for (; i < 0x7f; i++)
    {
        p = work->auxData + i;
        *p = 0;
    }
}

// FUN_0016f490
s32 func_0016f490(s16 pcId)
{
    s32 count;
    s32 pcValue;

    count = 0;
    pcValue = pcId;
    if (pcValue == -1)
    {
        s32 index;
        DatEquipment* equipment;

        index = 0;
        equipment = (DatEquipment*)D_00833E80;
        for (; index < 20; index++)
        {
            if (equipment[index].id != 0)
            {
                count++;
            }
        }
        return count;
    }

    if (pcValue == 1)
    {
        s32 index;
        DatEquipment* equipment;

        index = 0;
        equipment = gGlobalWork.heroEquip.equipments;
        for (; index < 300; index++)
        {
            if (equipment[index].id != 0)
            {
                count++;
            }
        }
        return count;
    }

    if (pcValue >= 0x100)
    {
        s32 index;
        u8* equipment;

        index = 0;
        equipment = D_00834010 + pcValue * sizeof(DatPc);
        for (; index < 4; index++)
        {
            if (*(u16*)(equipment + index * sizeof(DatEquipment) - 0x36948) != 0)
            {
                count++;
            }
        }
        return count;
    }

    {
        s32 index;
        u8* equipment;

        index = 0;
        equipment = D_00834010 + pcValue * sizeof(DatPc);
        for (; index < 4; index++)
        {
            if (*(u16*)(equipment + index * sizeof(DatEquipment) - 0x66c) != 0)
            {
                count++;
            }
        }
    }

    return count;
}

// FUN_0016f630
u16 datGetEquipmentId(s16 pcId, s32 equipmentIdx)
{
    s32 offset;
    u8* equipment;

    if (pcId == -1)
    {
        offset = equipmentIdx * 0x14;
        return *(u16*)(D_00833E80 + offset);
    }
    else if (IS_HERO(pcId))
    {
        offset = equipmentIdx * 0x14;
        equipment = (u8*)gGlobalWork.heroEquip.equipments;
        return *(u16*)(equipment + offset);
    }
    else if (pcId >= 0x100)
    {
        return *(u16*)(D_007FD6C8 + pcId * 0x364 + equipmentIdx * 0x14);
    }

    return *(u16*)(D_008339A4 + pcId * 0x364 + equipmentIdx * 0x14);
}

// FUN_0016f720
u32 func_0016f720(s16 pcId, s32 equipmentIdx)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        return *(u32*)(D_00833E84 + equipmentIdx * 0x14);
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        return base[equipmentIdx].type;
    }
    else if (pcId >= 0x100)
    {
        return *(u32*)(D_007FD6CC + pcId * 0x364 + equipmentIdx * 0x14);
    }

    return *(u32*)(D_008339A8 + pcId * 0x364 + equipmentIdx * 0x14);
}

// FUN_0016f810
u8 func_0016f810(s16 pcId, s32 equipmentIdx)
{
    u8* base;

    if (pcId == -1)
    {
        return *(u8*)(D_00833E88 + equipmentIdx * 0x14);
    }
    else if (IS_HERO(pcId))
    {
        base = (u8*)gGlobalWork.heroEquip.equipments;
        return base[equipmentIdx * 0x14 + 8];
    }
    else if (pcId >= 0x100)
    {
        return *(u8*)(D_007FD6D0 + pcId * 0x364 + equipmentIdx * 0x14);
    }

    return *(u8*)(D_008339AC + pcId * 0x364 + equipmentIdx * 0x14);
}

// FUN_0016f900
u8 datGetEquipmentEffect(s16 pcId, s32 equipmentIdx)
{
    u8* base;

    if (pcId == -1)
    {
        return *(u8*)(D_00833E89 + equipmentIdx * 0x14);
    }
    else if (IS_HERO(pcId))
    {
        base = (u8*)gGlobalWork.heroEquip.equipments;
        return base[equipmentIdx * 0x14 + 9];
    }
    else if (pcId >= 0x100)
    {
        return *(u8*)(D_007FD6D1 + pcId * 0x364 + equipmentIdx * 0x14);
    }

    return *(u8*)(D_008339AD + pcId * 0x364 + equipmentIdx * 0x14);
}

/* Removing this loses FUN_0016ea80 (MATCH nd0 -> MISMATCH nd18) - measured W161. */
// FUN_0016f9f0
u16 func_0016f9f0(s16 pcId, s32 equipmentIdx)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        return *(u16*)(D_00833E8A + equipmentIdx * 0x14);
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        return base[equipmentIdx].firstStat;
    }
    else if (pcId >= 0x100)
    {
        return *(u16*)(D_007FD6D2 + pcId * 0x364 + equipmentIdx * 0x14);
    }

    return *(u16*)(D_008339AE + pcId * 0x364 + equipmentIdx * 0x14);
}

// FUN_0016fae0
u16 func_0016fae0(s16 pcId, s32 equipmentIdx)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        return *(u16*)(D_00833E8C + equipmentIdx * 0x14);
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        return base[equipmentIdx].secondStat;
    }
    else if (pcId >= 0x100)
    {
        return *(u16*)(D_007FD6D4 + pcId * 0x364 + equipmentIdx * 0x14);
    }

    return *(u16*)(D_008339B0 + pcId * 0x364 + equipmentIdx * 0x14);
}
// FUN_0016fbd0
u16 func_0016fbd0(s16 pcId, s32 equipmentIdx)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        return *(u16*)(D_00833E8E + equipmentIdx * 0x14);
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        return base[equipmentIdx].unk_0e;
    }
    else if (pcId >= 0x100)
    {
        return *(u16*)(D_007FD6D6 + pcId * 0x364 + equipmentIdx * 0x14);
    }

    return *(u16*)(D_008339B2 + pcId * 0x364 + equipmentIdx * 0x14);
}

// FUN_0016fcc0
u16 func_0016fcc0(s16 pcId, s32 equipmentIdx)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        return *(u16*)(D_00833E90 + equipmentIdx * 0x14);
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        return base[equipmentIdx].unk_10;
    }
    else if (pcId >= 0x100)
    {
        return *(u16*)(D_007FD6D8 + pcId * 0x364 + equipmentIdx * 0x14);
    }

    return *(u16*)(D_008339B4 + pcId * 0x364 + equipmentIdx * 0x14);
}

// FUN_0016fdb0
DatEquipment* func_0016fdb0(s16 pcId, s32 equipmentIdx)
{
    s32 pcIndex;

    if (pcId == -1)
    {
        return (DatEquipment*)(D_00833E80 + equipmentIdx * 0x14);
    }
    else if (IS_HERO(pcId))
    {
        return &gGlobalWork.heroEquip.equipments[equipmentIdx];
    }
    else if (pcId >= 0x100)
    {
        pcIndex = pcId - 0x102;
        return (DatEquipment*)((u8*)D_00834010 + pcIndex * 0x364 +
                               equipmentIdx * 0x14 + 0x180);
    }

    pcIndex = pcId - 2;
    return (DatEquipment*)((u8*)D_00834010 + pcIndex * 0x364 +
                           equipmentIdx * 0x14 + 0x5c);
}

// FUN_0016fea0
void func_0016fea0(s16 pcId, s32 equipmentIdx, u16 id)
{
    u8* base;

    if (pcId == -1)
    {
        *(u16*)(D_00833E80 + equipmentIdx * 0x14) = id;
    }
    else if (IS_HERO(pcId))
    {
        base = (u8*)gGlobalWork.heroEquip.equipments;
        *(u16*)&base[equipmentIdx * 0x14] = id;
    }
    else if (pcId >= 0x100)
    {
        *(u16*)(D_007FD6C8 + pcId * 0x364 + equipmentIdx * 0x14) = id;
    }
    else
    {
        *(u16*)(D_008339A4 + pcId * 0x364 + equipmentIdx * 0x14) = id;
    }
}


// FUN_0016ff90
void func_0016ff90(s16 pcId, s32 equipmentIdx, u32 type)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        *(u32*)(D_00833E84 + equipmentIdx * 0x14) = type;
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        base[equipmentIdx].type = type;
    }
    else if (pcId >= 0x100)
    {
        *(u32*)(D_007FD6CC + pcId * 0x364 + equipmentIdx * 0x14) = type;
    }
    else
    {
        *(u32*)(D_008339A8 + pcId * 0x364 + equipmentIdx * 0x14) = type;
    }
}


// FUN_00170080
void func_00170080(s16 pcId, s32 equipmentIdx, u8 value)
{
    u8* base;

    if (pcId == -1)
    {
        *(u8*)(D_00833E88 + equipmentIdx * 0x14) = value;
    }
    else if (IS_HERO(pcId))
    {
        base = (u8*)gGlobalWork.heroEquip.equipments;
        base[equipmentIdx * 0x14 + 8] = value;
    }
    else if (pcId >= 0x100)
    {
        *(u8*)(D_007FD6D0 + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
    else
    {
        *(u8*)(D_008339AC + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
}

// FUN_00170170
void func_00170170(s16 pcId, s32 equipmentIdx, u8 effect)
{
    u8* base;

    if (pcId == -1)
    {
        *(u8*)(D_00833E89 + equipmentIdx * 0x14) = effect;
    }
    else if (IS_HERO(pcId))
    {
        base = (u8*)gGlobalWork.heroEquip.equipments;
        base[equipmentIdx * 0x14 + 9] = effect;
    }
    else if (pcId >= 0x100)
    {
        *(u8*)(D_007FD6D1 + pcId * 0x364 + equipmentIdx * 0x14) = effect;
    }
    else
    {
        *(u8*)(D_008339AD + pcId * 0x364 + equipmentIdx * 0x14) = effect;
    }
}

// FUN_00170260
void func_00170260(s16 pcId, s32 equipmentIdx, u16 value)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        *(u16*)(D_00833E8A + equipmentIdx * 0x14) = value;
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        base[equipmentIdx].firstStat = value;
    }
    else if (pcId >= 0x100)
    {
        *(u16*)(D_007FD6D2 + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
    else
    {
        *(u16*)(D_008339AE + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
}

// FUN_00170350
void func_00170350(s16 pcId, s32 equipmentIdx, u16 value)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        *(u16*)(D_00833E8C + equipmentIdx * 0x14) = value;
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        base[equipmentIdx].secondStat = value;
    }
    else if (pcId >= 0x100)
    {
        *(u16*)(D_007FD6D4 + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
    else
    {
        *(u16*)(D_008339B0 + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
}

// FUN_00170440
void func_00170440(s16 pcId, s32 equipmentIdx, u16 value)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        *(u16*)(D_00833E8E + equipmentIdx * 0x14) = value;
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        base[equipmentIdx].unk_0e = value;
    }
    else if (pcId >= 0x100)
    {
        *(u16*)(D_007FD6D6 + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
    else
    {
        *(u16*)(D_008339B2 + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
}

// FUN_00170530
void func_00170530(s16 pcId, s32 equipmentIdx, u16 value)
{
    DatEquipment* base;

    if (pcId == -1)
    {
        *(u16*)(D_00833E90 + equipmentIdx * 0x14) = value;
    }
    else if (IS_HERO(pcId))
    {
        base = gGlobalWork.heroEquip.equipments;
        base[equipmentIdx].unk_10 = value;
    }
    else if (pcId >= 0x100)
    {
        *(u16*)(D_007FD6D8 + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
    else
    {
        *(u16*)(D_008339B4 + pcId * 0x364 + equipmentIdx * 0x14) = value;
    }
}







#pragma opt_loop_invariants off

// FUN_00170620
u8* func_00170620(s16 pcId, s16 index)
{
    return gPcs[pcId - 2].unkData2 + index * 4;
}

// FUN_00170670
u16 func_00170670(s16 pcId, s16 index)
{
    return *(u16*)(D_008339F4 + pcId * sizeof(DatPc) + index * 4);
}

// FUN_001706c0
s16 func_001706c0(s16 pcId, s16 index)
{
    return *(u16*)(D_008339F6 + pcId * sizeof(DatPc) + index * 4);
}

// FUN_00170710
void func_00170710(s16 pcId, s16 index, u16 value)
{
    *(u16*)(D_008339F6 + pcId * sizeof(DatPc) + index * 4) = value;
}

// FUN_00170760
u16 func_00170760(s16 pcId, s16 index)
{
    u8* idBase;
    u8* heroEquip;
    s32 address;
    s32 i;

    if (pcId == PC_HERO)
    {
        heroEquip = *(u8* volatile /* Removing this qualifier loses func_00170760 (MATCH nd0 -> MISMATCH nd15, size 256 -> 256) - measured W170. */*)&gGlobalWork.heroEquip.unkPtr;
        address = index * 2;
        address += (s32)heroEquip;
        return *(u16*)(address - 8000);
    }
    if (pcId == -1)
    {
        return *(u16*)(D_00831CE0 + index * 2);
    }
    if (pcId < 0x100)
    {
        goto invalid;
    }

    i = 0;
    idBase = (u8*)gPcs + pcId * 0x364;
    for (; i < 20; i++)
    {
        if (*(u16*)(idBase + i * 4 - 0x367b8) == pcId)
        {
            return *(u16*)(D_007FD85A + pcId * 0x364 + i * 4);
        }
    }
    return 0;
invalid:
    return 0;
}

// FUN_00170860 NONMATCHING
void func_00170860(s16 pcId, s16 index, u16 value)
{
    u8* idBase;
    u8* heroEquip;
    s32 address;
    s32 i;
    s32 j;

    K_ASSERT(value <= 99, 2341);
    if (pcId == PC_HERO)
    {
        heroEquip = *(u8* volatile /* Removing this qualifier worsens func_00170860 (NONMATCHING nd68 -> NONMATCHING nd83, size 476 -> 476) - measured W170. */*)&gGlobalWork.heroEquip.unkPtr;
        address = index * 2;
        address += (s32)heroEquip;
        *(u16*)(address - 8000) = value;
        goto done;
    }
    if (pcId == -1)
    {
        *(u16*)(D_00831CE0 + index * 2) = value;
        goto done;
    }
    if (pcId < 0x100)
    {
        goto done;
    }
    i = 0;
    idBase = (u8*)gPcs + pcId * 0x364;
    for (; i < 20; i++)
    {
        if (*(u16*)(idBase + i * 4 - 0x367b8) == pcId)
        {
            *(u16*)(D_007FD85A + pcId * 0x364 + i * 4) = value;
            if (value == 0)
            {
                *(u16*)(D_007FD858 + pcId * 0x364 + i * 4) = 0;
            }
            goto done;
        }
    }

    j = 0;
    for (; j < 20; j++)
    {
        if (*(u16*)(idBase + j * 4 - 0x367b8) == 0)
        {
            *(u16*)(D_007FD85A + pcId * 0x364 + j * 4) = value;
            if (value == 0)
            {
                *(u16*)(D_007FD858 + pcId * 0x364 + j * 4) = 0;
            }
            goto done;
        }
    }
done:
    return;
}

// FUN_00170a40
u16 func_00170a40(s16 pcId, s16 index)
{
    if (pcId >= 0x100)
    {
        pcId -= 0x100;
    }
    return *(u16*)(D_00833C58 + pcId * sizeof(DatPc) + index * 4);
}

// FUN_00170ab0
s16 func_00170ab0(s16 pcId, s16 index)
{
    if (pcId >= 0x100)
    {
        pcId -= 0x100;
    }
    return *(u16*)(D_00833C5A + pcId * sizeof(DatPc) + index * 4);
}

// FUN_00170b20
void func_00170b20(s16 pcId, s16 index, u16 value)
{
    if (pcId >= 0x100)
    {
        pcId -= 0x100;
    }
    *(u16*)(D_00833C58 + pcId * sizeof(DatPc) + index * 4) = value;
}

// FUN_00170b90
void func_00170b90(s16 pcId, s16 index, u16 value)
{
    if (pcId >= 0x100)
    {
        pcId -= 0x100;
    }
    *(u16*)(D_00833C5A + pcId * sizeof(DatPc) + index * 4) = value;
}

// FUN_00170c00
u32 func_00170c00(s16 pcId, s16 index, s16 delta)
{
    s32 value = func_00170760_impl(pcId, index) + delta;

    if (value >= 99)
    {
        value = 99;
    }
    else if (value < 0)
    {
        value = 0;
    }
    func_00170860(pcId, index, value);
    return value;
}

// FUN_00170d60
void* func_00170d60(s16 id)
{
    if (id < 1000)
    {
        return D_007CDFE4 + id * 0x28;
    }
    return NULL;
}

// FUN_00170da0
void* func_00170da0(s16 id)
{
    if (id >= 1000 && id < 2000)
    {
        return D_007CDFDC + (id - 1000) * 0x20;
    }
    return NULL;
}

// FUN_00170df0
void* func_00170df0(s16 id)
{
    if (id >= 2000 && id < 3000)
    {
        return D_007CDFD8 + (id - 2000) * 0x20;
    }
    return NULL;
}

// FUN_00170e40
void* func_00170e40(s16 id)
{
    if (id >= 3000 && id < 4000)
    {
        return D_007CDFD4 + (id - 3000) * 0x24;
    }
    return NULL;
}

// FUN_00170e90
void* func_00170e90(s16 id)
{
    if (id >= 3000)
    {
        return D_007CDFCC + (id - 4000) * 0x1c;
    }
    return NULL;
}

// FUN_00170ed0
void* func_00170ed0(s16 id, s32* category)
{
    return func_00170ed0_impl(id, category);
}

// FUN_00171060
s16 func_00171060(s16 id)
{
    id = (s16)id;
    if (id < 1000)
    {
        return id;
    }
    if (id < 2000)
    {
        return id - 1000;
    }
    if (id < 3000)
    {
        return id - 2000;
    }
    if (id < 4000)
    {
        return id - 3000;
    }
    if (id < 5000)
    {
        return id - 4000;
    }
    return id - 5000;
}

#pragma alias datIncrementSocialLinkCounter FUN_001718b0
// FUN_00171110
const char* func_00171110(s16 id, s16 field)
{
    extern u8 D_005D6C80[];
    s32 idValue = id;
    if (idValue < 1000)
    {
        return *(const char**)((u8*)D_005DDDC0 + idValue * 0x14 + field * 4);
    }
    if (idValue < 2000)
    {
        return *(const char**)((u8*)D_005DABF0 + idValue * 0x14 + field * 4);
    }
    if (idValue < 3000)
    {
        return *(const char**)(D_005D6C80 + idValue * 0x14 + field * 4);
    }
    if (idValue < 4000)
    {
        return ((const char**)D_005DE8E0)[idValue];
    }
    if (idValue < 5000)
    {
        return ((const char**)D_005DE880)[idValue];
    }
    return ((const char**)D_005DE040)[idValue];
}

#pragma alias datDecreaseSocialLinkPoints FUN_00171960
// FUN_00171250
u32 func_00171250(s16 id)
{
    if (id < 1000)
    {
        return 0;
    }
    if (id < 2000)
    {
        return 1;
    }
    if (id < 3000)
    {
        return 2;
    }
    if (id < 4000)
    {
        return 3;
    }
    return 4;
}

#pragma alias datGetSocialLinkPoints FUN_00171ac0
// FUN_001712d0
u16 func_001712d0(s16 id)
{
    s32 category;
    u8* resource = func_00170ed0(id, &category);

    if (category == 3)
    {
        goto category3;
    }
    if (category == 2)
    {
        goto category2;
    }
    if (category == 1)
    {
        goto category1;
    }
    switch (category)
    {
    default:
        goto invalid;
    case 0:
        goto category0;
    }

category0:
    return *(u16*)(resource + 0x22);
category1:
    return *(u16*)(resource + 0x18);
category2:
    return *(u16*)(resource + 0x18);
category3:
    return *(u16*)(resource + 0x16);
invalid:
    return 0;
}

#pragma alias datResetSocialLinkPoints FUN_00171b50
// FUN_00171360
u32 dat00171360(u16 param_1)
{
    if (param_1 < 5000)
    {
        return 0;
    }

    return param_1 < 0x1408;
}

// FUN_00171390
void func_00171390(u32 flag)
{
    s32 index;
    u16 eventFlag;
    u32 valid;

    eventFlag = flag;
    if (eventFlag < 5000)
    {
        valid = false;
    }
    else if (eventFlag >= 0x1408)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    if (!valid)
    {
        FUN_0019d3f0_y2((u32)D_005E3098, 0x9fe);
    }

    index = eventFlag - 0x1188;
    if (index < 0 || index >= 0x1600)
    {
        FUN_0019d3f0_y2((u32)D_005E3098, 0x78d);
    }
    if (index == 0x1376)
    {
        FUN_005225A8(&gSpecialStatusMessage);
    }
    gGlobalWork.flags[((u16)flag - 0x1188) / 32] |=
        1u << (((u16)flag - 0x1188) % 32);
}

#pragma alias datSetSocialLinkCounter FUN_00171e90
// FUN_001714b0
s32 func_001714b0(s32 index)
{
    return (s32)(D_007CDFC4 + index * 0x10);
}

// FUN_001714d0
s32 func_001714d0(s32 index)
{
    return (s32)(D_007CDFC0 + index * 0x20);
}

// FUN_001714f0
s32 func_001714f0(s32 index)
{
    return (s32)(D_007CDFC8 + index * 8);
}

// FUN_00171510
f32 func_00171510(s16 row, s16 column)
{
    return *(f32*)(D_007CDFBC + row * 0x14 + column * 4);
}

// FUN_00171550
u8 func_00171550(s16 unused1, s16 unused2, u16 index)
{
    u32 random = FUN_00488F30() % 100;
    s32 i;
    u32 threshold = 0;
    u8* table;

    i = 0;
    table = D_007CDFB4;
    table += index * 0x20;
    for (; i < 16; i++)
    {
        threshold += table[i * 2];
        if (random <= threshold)
        {
            return (D_007CDFB4 + index * 0x20)[i * 2 + 1];
        }
    }
    return (D_007CDFB4 + index * 0x20)[0x1f];
}

#pragma alias datSetSocialLinkRankUnlocked FUN_001723a0
// FUN_001715f0
u32 func_001715f0(s16 id)
{
    s32 category;
    u8* resource;
    s32 tableIndex = 0;

    id = (s16)id;
    if (id >= 4000)
    {
        return 0;
    }

    if (id < 1000)
    {
        category = 0;
    }
    else if (id < 2000)
    {
        category = 1;
    }
    else if (id < 3000)
    {
        category = 2;
    }
    else if (id < 4000)
    {
        category = 3;
    }
    else
    {
        category = 4;
    }

    switch (category)
    {
    case 0:
        resource = func_00170d60_impl(id);
        tableIndex = *(u16*)(resource + 0x14);
        break;
    case 1:
        resource = func_00170da0_impl(id);
        tableIndex = *(u16*)(resource + 0x0c);
        break;
    case 2:
        resource = func_00170df0_impl(id);
        tableIndex = *(u16*)(resource + 0x0c);
        break;
    case 3:
        return 0;
    }

    resource = D_007CDFB4 + tableIndex * 0x20;
    return resource[0] == 'd' ? resource[1] : 0xff;
}

#pragma alias datSetSocialLinkRankAcknowledged FUN_001724a0
// FUN_001717b0
s16 *datGetActiveSocialLinkPtr()
{
    return &gGlobalWork.heroStatus.activeSocialLink;
}

#pragma alias datApplyPendingSocialLinkRank FUN_001725a0
// FUN_001717C0
u8 FUN_001717c0(s32 socialLink)
{
    s32 valid;
    s32 secondValid;
    s32 available;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xAD0);
    if (func_003951d0(socialLink + 0x900) == 1)
    {
        goto socialAvailable;
    }
    secondValid = true;
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        secondValid = false;
    }
    K_ASSERT(secondValid, 0xAC3);
    available = func_003951d0(socialLink + 0x920) == 1;
    if (available != true)
    {
        goto socialUnavailable;
    }
socialAvailable:
    return true;
socialUnavailable:
    return false;
}

#pragma alias datSocialLinkHasPendingRank FUN_00172660
// FUN_001718B0
void datIncrementSocialLinkCounter(s32 socialLink)
{
    DatGlobal* globalWork = &gGlobalWork;
    s32 valid;
    u16* counter;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xAE0);
    counter = &((u16*)(globalWork->heroStatus.socialLinkData + SOCIAL_DATA_COUNTER_OFFSET))[socialLink];
    if (*counter < 0x20)
    {
        (*counter)++;
    }
    else
    {
        *counter = 0x20;
    }
}

#pragma alias datSocialEventRecordHasData FUN_00172750
// FUN_00171960
void datDecreaseSocialLinkPoints(s32 socialLink, s32 points)
{
    struct SocialPointOwner
    {
        u8 unused[2];
        s8 levels[SOCIAL_LINK_COUNT];
        u8 padding[0xD2];
        s16 pointValues[SOCIAL_LINK_COUNT];
    };
    struct SocialPointOwner* pointOwner;
    s16 selectedSocialLink = 0;
    s16* point;
    s8* levels;
    s32 valid;
    s32 secondValid;
    s8 socialLevel;

    pointOwner = (struct SocialPointOwner*)&gGlobalWork;
    pointOwner = (struct SocialPointOwner*)((socialLink << 1) + (u32)pointOwner);
    point = pointOwner->pointValues;
    if (*point >= 1000)
    {
        return;
    }
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB00);
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        secondValid = false;
    }
    else
    {
        secondValid = true;
    }
    K_ASSERT(secondValid, 0x595);
    levels = ((struct SocialPointOwner*)&gGlobalWork)->levels;
    socialLevel = levels[(s16)socialLink];
    if (socialLevel > 0 && socialLevel != 10)
    {
        *point = *point - points;
        if (FUN_00172c50(&selectedSocialLink) != NULL && selectedSocialLink == socialLink)
        {
            *point = 1;
        }
        if (*point < 0)
        {
            *point = 0;
        }
    }
}

// FUN_00171AC0
s16 datGetSocialLinkPoints(s32 socialLink)
{
    DatGlobal* globalWork = &gGlobalWork;
    s32 valid;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB20);
    return ((s16*)(globalWork->heroStatus.socialLinkData + 0x5E))[socialLink];
}

// FUN_00171B50
void datResetSocialLinkPoints(s32 socialLink)
{
    DatGlobal* globalWork;
    s32 valid;
    s32 secondValid;
    s16 defaultPoints;
    s16* defaults;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB2C);
    defaults = func_003bddd0();
    defaultPoints = defaults[socialLink];
    globalWork = &gGlobalWork;
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        secondValid = false;
    }
    else
    {
        secondValid = true;
    }
    K_ASSERT(secondValid, 0xAF0);
    ((s16*)(globalWork->heroStatus.socialLinkData + 0x5E))[socialLink] = defaultPoints;
}

/* W357 measured optimization_level 0: without nd10/object24 (MISMATCH), with nd0/object44 (MATCH); window 48; retained. */

// FUN_00171C40
void FUN_00171c40(s32 socialLink, s32 enabled)
{
    DatGlobal* globalWork;
    s32 valid;
    s32 secondValid;
    u16* counter;
    s16 defaultPoints;
    s16* defaults;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB3C);
    if (enabled == 1)
    {
        if (func_003951d0(socialLink + 0x900) == 0)
        {
            globalWork = &gGlobalWork;
            if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
            {
                valid = false;
            }
            else
            {
                valid = true;
            }
            K_ASSERT(valid, 0xAE0);
            counter = &((u16*)(globalWork->heroStatus.socialLinkData + SOCIAL_DATA_COUNTER_OFFSET))[socialLink];
            if (*counter < 0x20)
            {
                (*counter)++;
            }
            else
            {
                *counter = 0x20;
            }

            globalWork = &gGlobalWork;
            if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
            {
                valid = false;
            }
            else
            {
                valid = true;
            }
            K_ASSERT(valid, 0xAF0);
            ((s16*)(globalWork->heroStatus.socialLinkData + 0x5E))[socialLink] = 0;
            func_00395170(socialLink + 0x900);
        }
        func_00395170(0x987);
    }
    else
    {
        func_003951a0(socialLink + 0x900);
        if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
        {
            valid = false;
        }
        else
        {
            valid = true;
        }
        K_ASSERT(valid, 0xB2C);
        defaults = func_003bddd0();
        defaultPoints = defaults[socialLink];
        globalWork = &gGlobalWork;
        if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
        {
            secondValid = false;
        }
        else
        {
            secondValid = true;
        }
        K_ASSERT(secondValid, 0xAF0);
        ((s16*)(globalWork->heroStatus.socialLinkData + 0x5E))[socialLink] = defaultPoints;
    }
}

// FUN_00171E90
void datSetSocialLinkCounter(s32 socialLink, u16 value)
{
    DatGlobal* globalWork = &gGlobalWork;
    s32 valid;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB58);
    if (value > 0x20)
    {
        ((u16*)(globalWork->heroStatus.socialLinkData + SOCIAL_DATA_COUNTER_OFFSET))[socialLink] = 0x20;
    }
    else
    {
        ((u16*)(globalWork->heroStatus.socialLinkData + SOCIAL_DATA_COUNTER_OFFSET))[socialLink] = value;
    }
}

// FUN_00171F50
void FUN_00171f50(s32 socialLink, s32 enabled)
{
    s32 valid;
    s32 secondValid;
    s32 thirdValid;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xB9B);
    if (enabled == 1)
    {
        if (func_003951d0(socialLink + 0x920) == 0)
        {
            struct SocialDateOwner
            {
                u8 unused[0x12E];
                s16 dates[SOCIAL_LINK_COUNT];
            };
            struct SocialDateOwner* globalWork;

            if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
            {
                secondValid = false;
            }
            else
            {
                secondValid = true;
            }
            K_ASSERT(secondValid, 0xB76);
            FUN_001718b0(socialLink);
            globalWork = (struct SocialDateOwner*)&gGlobalWork;
            if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
            {
                thirdValid = false;
            }
            else
            {
                thirdValid = true;
            }
            K_ASSERT(thirdValid, 0xB8B);
            globalWork->dates[socialLink] = D_0083679C[0];
            func_00395170(socialLink + 0x920);
        }
    }
    else
    {
        func_003951a0(socialLink + 0x920);
    }
}

#pragma alias datGetSocialEventData FUN_00172990
// FUN_001720C0
u16 FUN_001720c0(s32 socialLink, s32* outDate)
{
    struct SocialDateStateOwner
    {
        u8 unused[0x12E];
        s16 dates[SOCIAL_LINK_COUNT];
        u8 padding[0x3C];
        u16 status[SOCIAL_LINK_COUNT];
    };
    struct SocialDateStateOwner* globalWork = (struct SocialDateStateOwner*)&gGlobalWork;
    s32 valid;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xBB0);
    *outDate = globalWork->dates[socialLink];
    return globalWork->status[socialLink];
}

#pragma alias datSocialEventDataIsLoaded FUN_001729a0
// FUN_00172160
u8 FUN_00172160(s32 socialLink)
{
    s32 valid;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xBDC);
    if (func_003951d0(socialLink + 0x940) == 1)
    {
        return true;
    }
    return false;
}

#pragma alias datTryGetSocialEventValue FUN_001729d0
// FUN_00172200
void FUN_00172200(s32 socialLink, s32 enabled)
{
    struct SocialPointStorage
    {
        u8 unused[0xF2];
        s16 pointValues[SOCIAL_LINK_COUNT];
    };
    s32 valid;
    s32 secondValid;
    s32 thirdValid;
    s16* defaults;
    s16 defaultPoints;
    struct SocialPointStorage* globalWork;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xBEB);
    if (enabled == 1)
    {
        func_00395170(socialLink + 0x940);
        func_00395170(0x988);
        return;
    }
    func_003951a0(socialLink + 0x940);
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        secondValid = false;
    }
    else
    {
        secondValid = true;
    }
    K_ASSERT(secondValid, 0xB3C);
    func_003951a0(socialLink + 0x900);
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        thirdValid = false;
    }
    else
    {
        thirdValid = true;
    }
    K_ASSERT(thirdValid, 0xB2C);
    defaults = func_003bddd0();
    defaultPoints = defaults[socialLink];
    globalWork = (struct SocialPointStorage*)&gGlobalWork;
    K_ASSERT(func_0016dce0((s16)socialLink) != 0, 0xAF0);
    globalWork->pointValues[socialLink] = defaultPoints;
}

// FUN_001723A0
void datSetSocialLinkRankUnlocked(s32 socialLink, s32 rank, s32 enabled)
{
    s32 resourceId = rank - 1 + (socialLink * 0x20 + 0x400);
    s32 valid;

    if (rank <= 0)
    {
        K_Assert(__FILE__, 0xC00);
    }
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xC03);
    if (rank <= 0 || rank > 10)
    {
        return;
    }
    if (enabled == 1)
    {
        func_00395170(resourceId);
        return;
    }
    func_003951a0(resourceId);
}

#pragma alias datSetSocialEventMode FUN_00172a20
// FUN_001724A0
void datSetSocialLinkRankAcknowledged(s32 socialLink, s32 rank, s32 enabled)
{
    s32 resourceId = rank - 1 + (socialLink * 0x20 + 0x410);
    s32 valid;

    if (rank <= 0)
    {
        K_Assert(__FILE__, 0xC17);
    }
    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xC19);
    if (rank <= 0 || rank > 10)
    {
        return;
    }
    if (enabled == 1)
    {
        func_00395170(resourceId);
        return;
    }
    func_003951a0(resourceId);
}

#pragma alias datSocialEventModeIsActive FUN_00172a30
// FUN_001725A0
void datApplyPendingSocialLinkRank(s32 socialLink)
{
    struct SocialLevelOwner
    {
        u8 unused[2];
        s8 levels[SOCIAL_LINK_COUNT];
    };
    s16 shortSocialLink = socialLink;
    s8* levels = ((struct SocialLevelOwner*)&gGlobalWork)->levels;
    s32 socialLevel = levels[shortSocialLink];
    s32 valid;

    if (shortSocialLink < 0 || shortSocialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xC2E);
    if (FUN_00172660(socialLink) == 1)
    {
        func_0016e410((s16)socialLink, socialLevel + 1);
    }
}

#pragma alias datSocialLinkUsesRelationshipTable FUN_00172a50
// FUN_00172660
s32 datSocialLinkHasPendingRank(s32 socialLink)
{
    s32 valid;
    s32 rank;
    s32 firstResourceBase;
    s32 secondResourceBase;
    s32 rankOffset;
    s32 secondResource;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xC3F);
    rank = 1;
    secondResourceBase = (socialLink << 5) + 0x410;
    firstResourceBase = (socialLink << 5) + 0x400;
    while (rank <= 10)
    {
        rankOffset = rank - 1;
        secondResource = rankOffset + secondResourceBase;
        if (func_003951d0(rankOffset + firstResourceBase) == 1)
        {
            if (func_003951d0(secondResource) == 0)
            {
                return true;
            }
        }
        rank++;
    }
    return false;
}

// FUN_00172750
u8 datSocialEventRecordHasData(const u8* data)
{
    if (data[0] == 0xFF && *(const u16*)(data + 2) == 0 && data[4] == 0 && data[5] == 0)
    {
        return false;
    }
    if (data[0] == 0 && *(const u16*)(data + 2) == 0 && data[4] == 0 && data[5] == 0)
    {
        return false;
    }
    return true;
}

// FUN_001727E0
void FUN_001727e0(void)
{
    ((u32*)D_0083A34C)[0] &= ~0x80;
    ((u32*)D_0083A34C)[0] &= ~0x100;
    ((u32*)D_0083A34C)[0] &= ~0x200;
    ((u32*)D_0083A34C)[0] &= ~0x400;
    ((u32*)D_0083A34C)[0] &= ~0x800;
}

// FUN_00172820
void FUN_00172820(s16 pcId)
{
    (*(u32*)D_0083A34C) |= 0x400;
    datSetPhysicalCondition(1, pcId);
}

#pragma optimization_level 0
// FUN_00172860
u8 FUN_00172860(void)
{
    if ((*(u32*)D_0083A34C & 0x400) != 0)
    {
        return 1;
    }
    return 0;
}

#pragma optimization_level 2



















// FUN_00172890
void FUN_00172890()
{
    btlLoadResource(0x980);
    memset(D_00836458, 0, 0x38);
}

#pragma alias datRecordSocialLinkDate FUN_00172cc0
// FUN_001728D0
void FUN_001728d0(const u32* values)
{
    struct SocialDataOwner
    {
        u8 unused[0x1E4];
        s32 data[14];
    };
    struct SocialDataOwner* globalWork = (struct SocialDataOwner*)&gGlobalWork;
    const u32* source;
    u32* destination;
    u32 firstValue;
    u32 secondValue;
    s32 remaining;

    func_003951a0(0x980);
    memset(D_00836458, 0, 0x38);
    func_00395170(0x980);
    destination = (u32*)globalWork->data;
    remaining = 7;
    source = values;
    do
    {
        firstValue = source[0];
        secondValue = source[1];
        source += 2;
        remaining--;
        destination[0] = firstValue;
        destination[1] = secondValue;
        destination += 2;
    } while (remaining > 0);
    FUN_00172a20(0);
    if (globalWork->data[1] <= 4)
    {
        return;
    }
    K_Assert(__FILE__, 0xC9C);
}

#pragma alias datGetSocialLinksForToday FUN_00172d70
// FUN_00172990
u32* datGetSocialEventData(void)
{
    return (u32*)D_00836458;
}
















// FUN_001729A0
u8 datSocialEventDataIsLoaded(void)
{
    return func_003951d0(0x980) == 1;
}

// FUN_001729D0
u8 datTryGetSocialEventValue(u32* outValue)
{
    struct SocialEventData
    {
        u8 unused[0x24];
        u8 value;
    };
    struct SocialEventData* data = (struct SocialEventData*)D_00836458;

    if (data->value != 0xFF)
    {
        *outValue = data->value;
        return true;
    }
    return false;
}

// FUN_00172A10
u8 FUN_00172a10(void)
{
    return D_00836458[8];
}

// FUN_00172A20
void datSetSocialEventMode(u32 value)
{
    *(u32*)(D_00836458 + 0x10) = value;
}

// FUN_00172A30
u8 datSocialEventModeIsActive(void)
{
    return *(u32*)(D_00836458 + 0x10) == 1;
}







// FUN_00172A50
u8 datSocialLinkUsesRelationshipTable(s16 value)
{
    s16 i;
    s32 checkedValue;

    i = 0;
    checkedValue = value;
    while (i < 6)
    {
        if (checkedValue == i + 6)
        {
            return true;
        }
        i++;
    }
    return false;
}

/* Removing this loses FUN_00177280 (MATCH nd0 -> MISMATCH nd26) and 2 more - measured W161. */


/* Removing this loses FUN_00177410 (MATCH nd0 -> MISMATCH nd89) - measured W161. */


/* Removing this worsens FUN_001779a0 (nd14 -> nd121) - measured W161. */
/* W389 classification: register-colouring/loop-index allocation floor; six singles and all 15 knob pairs were neutral, declaration-order trial nd19 vs baseline nd14. */



















/* Camp/data bridge functions at retail 0x001675B0-0x0016C2F0. */


/* Retail globals shared by the Camp bridge state machines. */
#pragma alias DAT_0096017c_abs DAT_0096017c
#pragma alias DAT_00960184_abs DAT_00960184
#pragma alias scrGetIntPara_u64 scrGetIntPara_y2
#pragma alias DAT_00960178_abs DAT_00960178
#pragma alias DAT_00960088_abs DAT_00960088
/* Retail accesses these flag words by absolute address. */
#pragma alias DAT_007e094e_abs DAT_007e094e
#pragma alias DAT_007e0958_abs DAT_007e0958

/* Data bridge globals initialized by FUN_0016C010/FUN_0016C2F0. */

/* Unresolved retail helpers. Old-style declarations preserve the mixed-width
 * call ABI recovered from the stripped executable. */
#pragma alias FUN_00113a30_camp_reordered FUN_00113a30
#pragma alias campDataDrawPersonaSprite FUN_00114450
#pragma alias FUN_001159f0_typed FUN_001159f0
#pragma alias FUN_00115bc0_typed FUN_00115bc0
#pragma alias campDataDrawSpriteDirect FUN_001159f0
#pragma alias campDataDrawSpriteAltDirect FUN_00115bc0
#pragma alias campDataDrawDigitsDirect FUN_00115de0
#pragma alias campDataDrawSpriteFade FUN_001159f0
#pragma alias campDataDrawSpriteAltFade FUN_00115bc0
#pragma alias campDataCreateTask FUN_00119f10
#pragma alias campDataDrawEquipment FUN_0013d1a0
#pragma alias campDataDrawEquipmentAlt FUN_0013fca0
#pragma alias campDataDrawTextRaw FUN_003b2cb0
#pragma alias campDataDrawDigits FUN_003c7e20
#pragma alias campDataDrawText FUN_0040eb50

/* These task archive names are addressed absolutely by retail. */
#pragma alias D_005DBF20_abs D_005DBF20
#pragma alias D_005DBF40_abs D_005DBF40
#pragma alias D_005DBF70_abs D_005DBF70
#pragma alias D_005DBFA0_abs D_005DBFA0
#pragma alias D_005DBFD0_abs D_005DBFD0

/* Target entry prototypes keep all callbacks visible before their first use. */
#pragma alias campDataDrawListA FUN_0016A700
#pragma alias campDataDrawListB FUN_0016AF90



/* Work area for the 0x14-byte state task (the first five words overlap the
 * screen work above but carry different meanings). */

/* Work area allocated by FUN_00167930 for the persona display child. */

/* Work area allocated by FUN_00168770 (0x1c bytes). */


/* Work area used by FUN_00168810/FUN_00169040. */

/* Work area used by FUN_00169470/FUN_00169AE0. */

























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


// FUN_00172AB0
void FUN_00172ab0(s16 personaId)
{
    D_00836458[0x38] = 1;
    *(s16*)(D_00836458 + 0x3A) = personaId;
    *(s16*)(D_00836458 + 0x3C) = gGlobalWork.calendarWork.daysSinceApr5;
}

// FUN_00172AE0
void FUN_00172ae0(void)
{
    func_003951a0(0x983);
    memset(D_008364BC, 0, 0x38);
}

// FUN_00172B20
void FUN_00172b20(void)
{
    s16 value;
    if (FUN_00172c50(&value) != 0)
    {
        func_0017ad90();
        func_003951a0(0x983);
        memset(D_008364BC, 0, 0x38);
    }
}

// FUN_00172B80
void FUN_00172b80(s8 first, s8 second, const u32* values)
{
    u32* destination = (u32*)D_008364BC;
    const u32* source;
    s32 remaining;
    u32 packed;
    u32 firstValue;
    u32 secondValue;

    memset(D_008364BC, 0, 0x38);
    remaining = 7;
    source = values;
    do
    {
        firstValue = source[0];
        secondValue = source[1];
        source += 2;
        remaining--;
        destination[0] = firstValue;
        destination[1] = secondValue;
        destination += 2;
    } while (remaining > 0);
    func_00395170(0x983);
    memset(&packed, 0, sizeof(packed));
    ((u8*)&packed)[0] = first;
    ((u8*)&packed)[1] = second;
    ((u8*)&packed)[2] = ((const u8*)values)[0];
    ((u8*)&packed)[3] = ((const u8*)values)[0x1E];
    func_0017ac60(packed);
}

// FUN_00172C50
u8* FUN_00172c50(s16* outValue)
{
    u8* data = D_008364BC;

    if (func_003951d0(0x983) == 1)
    {
        *outValue = data[0];
        return data;
    }
    return NULL;
}

// FUN_00172CC0
void datRecordSocialLinkDate(s32 socialLink)
{
    s32 valid;
    u32 month;
    u32 day;

    if ((s16)socialLink < 0 || (s16)socialLink >= SOCIAL_LINK_COUNT)
    {
        valid = false;
    }
    else
    {
        valid = true;
    }
    K_ASSERT(valid, 0xD3F);
    month = clndGetCurrentMonth();
    day = clndGetCurrentDay();
    D_00836734[(s16)socialLink] = (u8)month;
    D_00836752[(s16)socialLink] = (u8)day;
}

// FUN_00172D70
s32 datGetSocialLinksForToday(s32* outSocialLinks)
{
    s32 count = 0;
    u32 month = clndGetCurrentMonth();
    u32 day = clndGetCurrentDay();
    s32 socialLink = 0;
    s8* data = (s8*)DAT_00836200;

    for (; socialLink < SOCIAL_LINK_COUNT; socialLink++)
    {
        s8* record = data + socialLink;
        if (record[0x534] != month)
        {
            continue;
        }
        if (record[0x552] != day)
        {
            continue;
        }
        outSocialLinks[count] = socialLink;
        count++;
    }
    return count;
}

// FUN_00172e10
void FUN_00172e10()
{
    memset(D_00836498, 0, 0x24);
}

// FUN_00172E40
u8* FUN_00172e40(void)
{
    extern u8 D_00836498[];
    return D_00836498;
}

// FUN_00172E50
void FUN_00172e50(s32 slot, u8 owner, s32 amount)
{
    s32 remaining = (s32)gGlobalWork.heroMoney - amount;

    K_ASSERT(remaining >= 0, 0xD87);
    if (slot >= 0x40 && slot < 0)
    {
        K_Assert(__FILE__, 0xD8A);
    }
    if (D_008364F4[slot] != 1)
    {
        D_008364F4[slot] = 1;
        D_008365F4[slot] = 0;
        D_008366F4[slot] = owner;
        if (remaining > 9999999)
        {
            remaining = 9999999;
        }
        K_ASSERT((u32)remaining <= 9999999u, 0x68A);
        gGlobalWork.heroMoney = remaining;
    }
}

// FUN_00172F70
u8 FUN_00172f70(s32* outSlot)
{
    s32* records = D_008364F4;
    s32 currentDay = D_0083679C[0];
    s32 slot;

    for (slot = 0; slot < 0x40; slot++)
    {
        s32* recordState = &records[slot];
        if (recordState[0] == 1 && recordState[0x40] == 0)
        {
            const u8* record = func_003beb10(slot);
            if (currentDay >= clndGetDaysSinceStartFromDate(record[2], record[3]))
            {
                *outSlot = slot;
                return true;
            }
        }
    }
    return false;
}

// FUN_00173040
void FUN_00173040(s32 slot)
{
    const u8* record;
    s16 itemId;
    s32* state;
    s32 itemIndex;
    s32 amount;
    s32 itemSlot;
    s32 found;
    s32 itemCount;
    u16 count;
    s32 normalizedCount;
    u8 itemData[0x20];

    record = func_003beb10(slot);
    K_ASSERT(D_008364F4[slot] != 0, 0xDBC);
    state = &D_008365F4[slot];
    K_ASSERT(*state != 1, 0xDBF);
    *state = 1;
    itemCount = D_008366F4[slot];
    for (itemIndex = 0; itemIndex < itemCount + 2; itemIndex++)
    {
        itemId = *(s16*)(record + itemIndex * 2 + 4);
        {
            const u8* itemRecord = record + itemIndex;
            count = itemRecord[0xC];
        }
        if (itemId >= 4000)
        {
            func_00170860(-1, itemId, count);
        }
        else
        {
            func_001828d0(itemId, itemData);
            amount = 0;
            normalizedCount = count & 0xFFFF;
            while (amount < normalizedCount)
            {
                found = 0;
                itemSlot = 0;
                {
                    const u8* itemSlots = D_00833E80;
                    while (itemSlot < 0x14)
                    {
                        if (*(u16*)(itemSlots + itemSlot * 0x14) == 0)
                        {
                            func_001831e0(-1, (s16)itemSlot, itemData);
                            found = 1;
                            break;
                        }
                        itemSlot++;
                    }
                }
                K_ASSERT(found != 0, 0xDE2);
                amount++;
            }
        }
    }
}
