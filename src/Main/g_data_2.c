#include "Main/g_data.h"
#include "Main/Battle/Data/datPersona.h"
#include "Kosaka/k_assert.h"
#include "temporary.h"

typedef union PairKey
{
    f32 value;
    struct
    {
        u16 low;
        u16 high;
    } parts;
} PairKey;
#include "Main/Battle/Data/datCalc.h"
#include "Script/scrTraceCode.h"
#include "datCalendar.h"
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
extern void func_001828d0_y2(s16 itemId, void* itemData);
extern void func_001831e0(s16 pcId, s16 slot, const void* itemData);
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
#pragma alias DAT_00836200_u32 DAT_00836200
extern u32 DAT_00836200_u32;
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
#pragma alias datIncrementSocialLinkCounter FUN_001718b0
#pragma alias datDecreaseSocialLinkPoints FUN_00171960
#pragma alias datGetSocialLinkPoints FUN_00171ac0
#pragma alias datResetSocialLinkPoints FUN_00171b50
#pragma alias datSetSocialLinkCounter FUN_00171e90
#pragma alias datSetSocialLinkRankUnlocked FUN_001723a0
#pragma alias datSetSocialLinkRankAcknowledged FUN_001724a0
#pragma alias datApplyPendingSocialLinkRank FUN_001725a0
#pragma alias datSocialLinkHasPendingRank FUN_00172660
#pragma alias datSocialEventRecordHasData FUN_00172750
#pragma alias datGetSocialEventData FUN_00172990
#pragma alias datSocialEventDataIsLoaded FUN_001729a0
#pragma alias datTryGetSocialEventValue FUN_001729d0
#pragma alias datSetSocialEventMode FUN_00172a20
#pragma alias datSocialEventModeIsActive FUN_00172a30
#pragma alias datSocialLinkUsesRelationshipTable FUN_00172a50
#pragma alias datRecordSocialLinkDate FUN_00172cc0
#pragma alias datGetSocialLinksForToday FUN_00172d70
s32 FUN_00300af0(s32 param_1);
void FUN_00403130();
void FUN_00403220();
void FUN_0017d700_y2(s32 param_1, s32 param_2, void *param_3);
void FUN_003d74b0();
#include "Camp/h_camp.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "h_cdvd.h"
#include "h_maestro.h"
#include "h_snd.h"
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
#pragma alias DAT_0096017c_abs DAT_0096017c
extern void (*DAT_0096017c_abs[])(...);
#pragma alias DAT_00960184_abs DAT_00960184
extern void* (*DAT_00960184_abs[])(...);
#pragma alias scrGetIntPara_u64 scrGetIntPara_y2
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
#pragma alias DAT_007e094e_abs DAT_007e094e
extern u8 DAT_007e094e_abs[];
#pragma alias DAT_007e0958_abs DAT_007e0958
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
extern u32 FUN_00122710(KwlnTask* task, u32 command);
extern u32 FUN_0012a560(f32, RwV2d, void*, s32);
extern u32 FUN_0012ac60(f32, RwV2d, void*, s32);
extern u32 FUN_00129b30(f32, RwV2d, void*, s32);
extern void FUN_0013c240(void* work, s16 pcId, s16 equipmentType);
extern void FUN_0013c780(void* work);
extern void FUN_0013cf80(u64 pcId, void* work);
extern void FUN_0013d1a0(f32 texture, CampFloatPair position, void* work, s32 alpha);
extern void FUN_0013fca0(f32 texture, u64 position, void* work, s32 alpha);
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
extern f32 FUN_0021ea00(s32);
extern KwlnTask* FUN_0025f370(KwlnTask* parent, void* battle_data);
extern u32 FUN_0025f570();
extern u32 FUN_0035ed20();
extern s32 FUN_003b2cb0(s32 param_2, s32 param_3, f32 param_1, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9);
#pragma alias campDataDrawTextRaw FUN_003b2cb0
extern s32 campDataDrawTextRaw(f32 scale, s32 x, s32 y, s32 color,
                               s32 font, s32 alignment, const char* text,
                               s32 maxWidth, s32 shadow);
extern u32 FUN_003c7430(u64 param_1);
extern u32 FUN_003c74e0(s32 param_1);
extern void FUN_003c7560(u8 param_1);
extern u32 FUN_003c7610();
extern u32 FUN_003c7700();
extern u32 FUN_003c7850();
extern void FUN_003c7d80(s32 param_1, u64 param_2);
extern void FUN_003c7e20(u32 p1, u32 p2, f32 p3, u32 p4, u32 p5, u32 p6, u32 p7, u32 p8);
#pragma alias campDataDrawDigits FUN_003c7e20
extern void campDataDrawDigits(f32 depth, s32 x, s32 y, s32 color,
                               s32 style, s32 font, s32 alignment, u32 value);
extern u32 FUN_0040eb50();
#pragma alias campDataDrawText FUN_0040eb50
extern s32 campDataDrawText(f32 scale, s32 x, s32 y, u8 color, s16 font,
                            const char* text, s32 maxWidth);
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


#pragma alias FUN_00300af0_y2 FUN_00300af0
#pragma alias FUN_00403130_y2 FUN_00403130
#pragma alias FUN_00403220_y2 FUN_00403220
#pragma alias func_001828d0_y2 func_001828d0
#pragma alias FUN_0017d700_y2 FUN_0017d700
#pragma alias FUN_0019d3f0_y2 FUN_0019d3f0
#pragma alias FUN_00521250_y2 FUN_00521250
#pragma alias FUN_00523ac8_y2 FUN_00523ac8
#pragma alias scrGetIntPara_y2 scrGetIntPara


typedef unsigned long long u64;
typedef int bool;
#define true 1
#define false 0

extern void* memcpy(void* dst, const void* src, u32 size);
extern void* memset(void* dst, u8 value, u32 size);
extern int memcmp(const void* left, const void* right, u32 size);
extern void qsort(void* base, u32 count, u32 width, int (*compare)(const void*, const void*));
extern int printf(const char* fmt, ...);
extern int sprintf(char* dst, const char* fmt, ...);
extern void FUN_00521250(void* dst, const void* src, u32 size);
extern void FUN_00523ac8(void* dst, const void* format, ...);
extern u8 DAT_00833bb0[];
extern u8 DAT_00833bd0[];
extern u8 DAT_00833bf0[];
extern u8 DAT_00836212[];
extern char gp0xffff9388[1];
extern const char D_007cc078[];
extern const char D_005e3820[];
extern void FUN_0019d3f0(u32 file, u32 line);
extern void FUN_00521408(void* dst, s32 value, u32 size);
extern void func_001828d0(s16 id, void* record);
extern void func_001830c0(void* record);
extern s32 FUN_003082f0(s32 category, u32 id);
extern s32 FUN_003086f0(void* record, u64 id);
extern void FUN_003086c0(void* record, u64 value);
extern void FUN_003083f0(void* record, u64 value);
extern s32 FUN_00306610(u64 value, void* left, void* right, u64 extra);
extern s32 FUN_003068d0(u64 value, void* left, void* right, u64 extra);
extern void FUN_00306bc0(u64 value, void* left, void* right, u64 a, u64 b, u64 c, u64 d);
extern s16 FUN_00403740(s16 id);
extern u64 FUN_00403920(s16 id, u64 value);
extern u64 FUN_003f33d0(s32 category, s32 value);
extern void FUN_003eff00(s32 index, void* out);
extern void* FUN_00300af0_y2(void);
extern void* FUN_00403130_y2(void);
extern void* FUN_00403220_y2(void);
extern void* FUN_001bff20(void);
void FUN_00179360(u32 saveType, u32 id, u32 size, const void* data);
void FUN_0017a430(u32 saveType, u32 id, u32 size, const void* data);
u32 FUN_0017d7b0(void);
int FUN_0017c2f0(const u32* left, const u32* right);
u32 FUN_0017d450(s32 index, const void* date);

extern u32 D_00960178[];
extern u32 D_0096017C[];
extern u32 D_00960184[];
#pragma alias D_00960184_abs D_00960184
extern u8 D_00960184_abs[];
#pragma alias D_00960184_sda D_00960184
extern u8 D_00960184_sda[] __attribute__((section(".sdata")));
extern u8 D_00834010[];
extern u8 D_00833994[];
extern s32 D_005e3840[][2];
extern s32 D_005e3844[][2];
extern u32 D_0083a21c[];
extern u8 DAT_0083a718[];
extern u8 DAT_00836200[];
extern u32 DAT_007ce00c;
extern s8* puGpffffb704;
extern u8 D_0083A6FC[];
extern const char D_005e3098[];
extern const char D_005e3278[];
extern u8 DAT_00836e1c[];
extern u8 DAT_00836ba3[];
extern u32 gSpecialStatusMessage;
extern u8* DAT_007ce3f8;
extern u8* DAT_007ce420;
extern u8* DAT_007ce42c;
extern void* DAT_007ce050;
extern void* DAT_007ce054;
extern void* DAT_007ce058;
extern void* DAT_007ce05c;

extern u8* DAT_007ce4a0;

#define PTR8(addr) ((u8*)(addr))
#define PTR16(addr) ((u16*)(addr))
#define PTR32(addr) ((u32*)(addr))
#define PTRP(addr) (*(u8**)(addr))
#define U8(addr) (*PTR8(addr))
#define U16(addr) (*PTR16(addr))
#define U32(addr) (*PTR32(addr))
#define ALLOCATE(count, size, flags) (*(void* (**)(u32, u32, u32))(D_00960184_abs + 0x184))(count, size, flags)
#define ALLOCATE_SMALL(count, size, flags) (*(void* (**)(u32, u32, u32))D_00960178)(count, size, flags)
#define RELEASE(memory) (*(void (**)(void*))D_0096017C)(memory)

/* The retail data tables are deliberately kept at their original addresses. */
typedef struct ResourceEntry
{
    u16 id;
    u16 reserved;
    u8 data[0x10];
} ResourceEntry;

typedef struct PairCounter
{
    s16 key;
    s16 keyHigh;
    s16 id;
    s16 remaining;
} PairCounter;

typedef struct DateRecord
{
    u8 month;
    u8 day;
    s16 year;
    s32 serial;
} DateRecord;

static ResourceEntry* resource_entries(void)
{
    return (ResourceEntry*)PTRP(0x00836794);
}

static s16* resource_levels(void)
{
    return (s16*)PTRP(0x00836798);
}

static u8* compendium_record(s32 id)
{
    return PTR8(0x00836e1c) + id * 0x34;
}

static u8* code_list(void)
{
    return PTR8(0x008367a7);
}

static u32* bit_list(void)
{
    return PTR32(0x0083a8c4);
}

static u32* pair_bits(void)
{
    return PTR32(0x0083a8f0);
}

static PairCounter* pair_counters(void)
{
    return (PairCounter*)PTR8(0x0083a734);
}

static DateRecord* date_records(void)
{
    return (DateRecord*)PTR8(0x0083a834);
}

static s32 bit_index(s32 value)
{
    if (value < 0) return 0;
    return value >> 5;
}

static u32 bit_mask(s32 value)
{
    return 1u << (value & 31);
}

#define SAVE_AT(base, offset, id_value, chunk_size, source) \
    do { \
        id = (id_value); \
        FUN_00521250((base) + (offset), &id, 4); \
        size = (chunk_size); \
        FUN_00521250((base) + (offset) + 4, &size, 4); \
        FUN_00521250((base) + (offset) + 8, (source), size); \
    } while (0)

// FUN_00177A90


void* func_00177a90(u16 pcId, s32 index)
{
    s32 adjustedPcId;

    adjustedPcId = pcId - 2;
    if (adjustedPcId < 0 || adjustedPcId >= 10)
    {
        FUN_0019d3f0_y2((u32)D_005E3098, 0xf22);
    }
    if (index < 0 || index >= 4)
    {
        FUN_0019d3f0_y2((u32)D_005E3098, 0xf23);
    }

    return D_00834010 + adjustedPcId * sizeof(DatPc) + index * 0x14 + 0x130;
}

/* W357 pragma sweep: FUN_00177db0 default nd3325/object4636; loop_invariants on nd3322/object4636; lifetimes on nd3321/object4636; common_subs off nd3176/object4704; common+loop nd3177/object4704; common+lifetimes nd3175/object4704 retained; loop+lifetimes nd3320/object4636; all three nd3176/object4704; window 4736. */
// FUN_00177B50
void func_00177b50(int param_1, int param_2)
{
    u8* base = DAT_00830000_a + 0x3a78;
    *(u16*)(base + param_1 * 0x364 + param_2 * 0x14) = 0;
}

// FUN_00177B90
void func_00177b90(u32 param_1, int param_2, int param_3)
{
    u8* iVar1;

    iVar1 = (u8*)D_00834010 + ((param_1 & 0xffff) - 2) * 0x364;
    FUN_00521250_y2(iVar1 + param_2 * 0x14 + 0x130,
                 iVar1 + param_3 * 0x14 + 0x5c, 0x14);
}
 
// FUN_00177C10
void func_00177c10(int param_1, int param_2)
{
    u8* base = (u8*)D_00834120 + (param_1 - 2) * 0x364;
    u32* puVar1 = (u32*)(base + param_2 * 4);
    *puVar1 |= 1;
}


/* Reconstructed dispatch/copy bodies from retail byte window 0x179360..0x17a430; no unjustified bytes. */
// FUN_00177C50
void func_00177c50(int param_1, int param_2)
{
    u8* base = (u8*)D_00834120 + (param_1 - 2) * 0x364;
    u32* puVar1 = (u32*)(base + param_2 * 4);
    *puVar1 &= ~1;
}

// FUN_00177CA0
u32 func_00177ca0(int param_1, int param_2)
{
    u8* base = (u8*)D_00834120 + (param_1 - 2) * 0x364;
    u32* puVar1 = (u32*)(base + param_2 * 4);
    return *puVar1 & 1;
}

/* W357 pragma sweep: FUN_0017ac60 default nd121/object296; loop_invariants on nd55/object296; lifetimes on nd118/object296; loop+lifetimes nd0/object296 retained; window 304. */
// FUN_00177ce0
void dat00177ce0(s32 param_1, u32 param_2)
{
    gPcs[param_1].unk_360 = param_2;
}

/* W357 measured optimization_level 1: without nd5/object96 (MISMATCH), with nd0/object96 (MATCH); retained. */
// FUN_00177d10
u32 dat00177d10(s32 param_1)
{
    return gPcs[param_1].unk_360;
}

// FUN_00177d40
void FUN_00177d40(void)
{
    void* (**allocator)(u32, u32, u32);

    allocator = (void* (**)(u32, u32, u32))D_00960184;
    PTRP(0x00836794) = (u8*)(*allocator)(300, 0x14, 0x40000);
    PTRP(0x00836798) = (u8*)(*allocator)(300, 2, 0x40000);
}

#pragma opt_common_subs off
#pragma opt_lifetimes on
/* W419 D_00960184 first two loads via _sda: nd3098/object4696/window4736 (65.97%) vs baseline nd3175/object4704 (67.49%); retained. */
// FUN_00177db0 NONMATCHING
void* FUN_00177db0(u32 saveType, s32* saveSize)
{
    u8* buffer;
    u8* cursor;
    u8 header[0x34];
    u32 id;
    u32 size;
    u8 checksum;
    u32 chunkOffset;
    u32 i;
    u32 today;
    u32 month;
    u32 day;
    s32 resultSize;

    U32(0x0083a6ec) = ((u32*)D_00960184_sda)[0];
    U32(0x0083a6f0) = ((u32*)D_00960184_sda)[1];
    U32(0x0083a6f4) = (u32)FUN_001bff20();
    buffer = (u8*)ALLOCATE(1, 0x20000, 0x40000);
    chunkOffset = 0;
    memcpy(buffer, &saveType, 4);

    *(u16*)(header + 0) = U16(0x0083679c);
    *(u16*)(header + 2) = U8(0x0083679e);
    *(u32*)(header + 4) = U32(0x0083a598);
    today = U32(0x00836268);
    month = 0;
    day = 0;
    while (day < 99)
    {
        if (today < PTR32(0x005dc050)[day]) break;
        month = (month + 1) & 0xff;
        day = (day + 1) & 0xff;
    }
    if (day >= 99) month = 99;
    header[8] = (u8)month;
    header[9] = (U32(0x0083a47c) & 0x2000000) != 0 ? 2 :
                ((U32(0x0083a47c) & 0x20000) != 0 ? 1 : 0);
    header[10] = (u8)FUN_0017d7b0();
    header[11] = (u8)U32(0x0083a6ec);
    for (i = 0; i < 0x12; i++)
        header[0x0c + i] = DAT_00836200[i];
    for (i = 0; i < 0x12; i++)
        header[0x1e + i] = DAT_00836200[0x12 + i];
    header[0x30] = (u8)((u32*)D_00960184_abs)[0];
    header[0x31] = (u8)((u32*)D_00960184_abs)[1];

    memcpy(buffer + 4, header, sizeof(header));
    SAVE_AT(buffer, 0x38, 1, 0x24, PTR8(0x00836200));
    SAVE_AT(buffer, 0x64, 2, 0x50, PTR8(0x00836224));
    SAVE_AT(buffer, 0xbc, 3, 0x508, PTR8(0x00836274));
    SAVE_AT(buffer, 0x5cc, 4, 0x10, PTR8(0x0083677c));
    SAVE_AT(buffer, 0x5e4, 5, 8, PTR8(0x0083678c));
    SAVE_AT(buffer, 0x5f4, 6, 0x1770, PTRP(0x00836794));
    SAVE_AT(buffer, 0x1d6c, 7, 0x258, PTRP(0x00836798));
    SAVE_AT(buffer, 0x1fcc, 8, 2, PTR8(0x0083679c));
    SAVE_AT(buffer, 0x1fd6, 9, 1, PTR8(0x0083679e));
    SAVE_AT(buffer, 0x1fdf, 10, 4, PTR8(0x008367a0));
    SAVE_AT(buffer, 0x1fe7, 11, 2, PTR8(0x008367a4));
    SAVE_AT(buffer, 0x1fef, 12, 1, PTR8(0x008367a6));
    SAVE_AT(buffer, 0x1ff5, 13, 0x400, PTR8(0x008367a7));
    SAVE_AT(buffer, 0x2406, 14, 2, PTR8(0x00836ba8));
    SAVE_AT(buffer, 0x2410, 15, 0x270, PTR8(0x00836bac));
    SAVE_AT(buffer, 0x2688, 16, 0x3400, PTR8(0x00836e1c));
    SAVE_AT(buffer, 0x5a90, 17, 0x2c0, PTR8(0x0083a21c));
    SAVE_AT(buffer, 0x5d58, 18, 4, PTR8(0x0083a6dc));
    SAVE_AT(buffer, 0x5d64, 19, 8, PTR8(0x0083a6e0));
    SAVE_AT(buffer, 0x5d74, 20, 4, PTR8(0x0083a6e8));
    SAVE_AT(buffer, 0x5d80, 21, 4, PTR8(0x0083a6ec));
    SAVE_AT(buffer, 0x5d8c, 22, 4, PTR8(0x0083a6f0));
    SAVE_AT(buffer, 0x5d98, 23, 4, PTR8(0x0083a6f4));
    SAVE_AT(buffer, 0x5da4, 24, 0x2c, PTR8(0x0083a8c4));
    SAVE_AT(buffer, 0x5dd8, 25, 0x200, PTR8(0x0083a4dc));
    SAVE_AT(buffer, 0x5fe0, 26, 0x1c, PTR8(0x0083a6fc));
    SAVE_AT(buffer, 0x6004, 27, 0x10, PTR8(0x0083a718));
    SAVE_AT(buffer, 0x601c, 28, 8, PTR8(0x0083a728));
    SAVE_AT(buffer, 0x602c, 29, 4, PTR8(0x0083a730));
    SAVE_AT(buffer, 0x6038, 30, 0x100, PTR8(0x0083a734));
    SAVE_AT(buffer, 0x6140, 31, 0x90, PTR8(0x0083a834));
    SAVE_AT(buffer, 0x61d8, 0x21, 0x1a8, PTR8(0x0083a8f0));
    SAVE_AT(buffer, 0x6388, 0x22, 1, PTR8(0x0083679e));
    SAVE_AT(buffer, 0x6391, 0x23, 4, PTR8(0x0083aa98));
    SAVE_AT(buffer, 0x639d, 0x24, 4, PTR8(0x0083a6f8));
    chunkOffset += 0x63a9;
    cursor = buffer + 0x63a9;

    for (i = 0; i < 10; i++)
    {
        u32 base = 0x100 + i * 0x100;
        u32 sourceAddress = 0x00834010 + i * 0x364;
        SAVE_AT(cursor, 0, base, 4, PTR8(sourceAddress));
        SAVE_AT(cursor, 0x0c, base + 1, 0x50, PTR8(sourceAddress + 4));
        SAVE_AT(cursor, 0x64, base + 2, 8, PTR8(sourceAddress + 0x54));
        SAVE_AT(cursor, 0x74, base + 3, 0x50, PTR8(sourceAddress + 0x5c));
        SAVE_AT(cursor, 0xcc, base + 4, 0x30, PTR8(sourceAddress + 0xac));
        SAVE_AT(cursor, 0x104, base + 5, 0x34, PTR8(sourceAddress + 0xdc));
        SAVE_AT(cursor, 0x140, base + 6, 0x10, PTR8(sourceAddress + 0x110));
        SAVE_AT(cursor, 0x158, base + 7, 0x10, PTR8(sourceAddress + 0x120));
        SAVE_AT(cursor, 0x170, base + 8, 0x50, PTR8(sourceAddress + 0x130));
        SAVE_AT(cursor, 0x1c8, base + 9, 0x190, PTR8(sourceAddress + 0x180));
        SAVE_AT(cursor, 0x360, base + 10, 0x50, PTR8(sourceAddress + 0x310));
        SAVE_AT(cursor, 0x3b8, base + 11, 4, PTR8(sourceAddress + 0x360));
        cursor += 0x3c4;
        chunkOffset += 0x3c4;
    }
    SAVE_AT(cursor, 0, 0x1000, 400, PTR8(0x00833e80));
    SAVE_AT(cursor, 0x198, 0x1001, 600, PTR8(0x00833c20));
    checksum = 0;
    for (i = 0; i < chunkOffset + 0x3c0; i++)
        checksum = (u8)(checksum + buffer[0x38 + i]);
    SAVE_AT(cursor, 0x3f8, 0x2000, 1, &checksum);
    {
        u32 end = 0xffffffff;
        memcpy(cursor + 0x401, &end, 4);
    }
    resultSize = (s32)(cursor + 0x405 - buffer);
    *saveSize = resultSize;
    printf("save image size %d\n", resultSize);
    return buffer;
}
#pragma opt_lifetimes reset
#pragma opt_common_subs reset

// FUN_00179030
void FUN_00179030(u32 saveType, void* stream)
{
    u8* cursor = (u8*)stream;
    u32 id;
    u32 size;

    if (saveType >= 2) cursor += 0x34;
    for (;;)
    {
        memcpy(&id, cursor, 4);
        printf((const char*)D_005e3820, id);
        if (id == 0xffffffff || id == 0x2000) break;
        memcpy(&size, cursor + 4, 4);
        cursor += 8;
        if (DAT_007ce00c != 0)
            FUN_0017a430(saveType, id, size, cursor);
        else
            FUN_00179360(saveType, id, size, cursor);
        cursor += size;
    }
    if (DAT_007ce00c == 0)
    {
        FUN_00521408(DAT_00833bb0, 0, 0x12);
        FUN_00521408(DAT_00833bd0, 0, 0x12);
        FUN_00521408(DAT_00833bf0, 0, 0x24);
        FUN_00521250(DAT_00833bb0, DAT_00836200, 0x12);
        FUN_00521250(DAT_00833bd0, DAT_00836212, 0x12);
        FUN_00523ac8(DAT_00833bf0, gp0xffff9388, DAT_00833bd0, DAT_00833bb0);
    }
}

// FUN_001791d0
bool FUN_001791d0(u32 saveType, const void* stream, s32 streamSize)
{
    u32 consumed;
    const u8* start;
    const u8* cursor;
    u32 limit;
    u32 id;
    u32 size;
    u32 checksum;
    u32 i;
    u8 stored;

    cursor = (const u8*)stream;
    start = (const u8*)stream;
    if (streamSize < 0x1000) return false;
    if (saveType >= 2)
    {
        cursor += 0x34;
        start = cursor;
    }
    if (saveType >= 3)
    {
        consumed = 0;
        limit = (u32)(streamSize - 0x34);
        for (;;)
        {
            memcpy(&id, cursor, 4);
            if (id == 0xffffffff)
                break;
            if (id == 0x2000)
            {
                checksum = 0;
                for (i = 0; i < consumed; i++)
                    checksum = (checksum + start[i]) & 0xff;
                memcpy(&size, cursor + 4, 4);
                memcpy(&stored, cursor + 8, 1);
                return ((u32)((u8)checksum ^ stored) < 1);
            }
            memcpy(&size, cursor + 4, 4);
            if (size == 0)
                return false;
            cursor += 8;
            cursor += size;
            consumed += 8;
            consumed += size;
            if (consumed < limit)
                continue;
            return false;
        }
        return false;
    }
    return true;
}

// FUN_00179360 NONMATCHING
void FUN_00179360(u32 saveType, u32 id, u32 size, const void* data)
{
    (void)saveType;

    /* Scalar records: retail bodies 0x179ad8..0x17a01c. */
    switch (id)
    {
        case 1:
            if (size == 0x24) FUN_00521250(DAT_00836200, data, 0x24);
            break;
        case 2:
            if (size == 0x50) FUN_00521250(PTR8(0x00836224), data, 0x50);
            break;
        case 3:
            if (size == 0x508) FUN_00521250(PTR8(0x00836274), data, 0x508);
            break;
        case 4:
            if (size == 0x10) FUN_00521250(PTR8(0x0083677c), data, 0x10);
            break;
        case 5:
            if (size == 8) FUN_00521250(PTR8(0x0083678c), data, 8);
            break;
        case 6:
            if (size == 6000) FUN_00521250(PTRP(0x00836794), data, size);
            break;
        case 7:
            if (size == 600) FUN_00521250(PTRP(0x00836798), data, size);
            break;
        case 8:
            if (size == 2) FUN_00521250(PTR8(0x0083679c), data, size);
            break;
        case 9:
            if (size == 1) FUN_00521250(PTR8(0x0083679e), data, size);
            break;
        case 10:
            if (size == 4) FUN_00521250(PTR8(0x008367a0), data, size);
            break;
        case 11:
            if (size == 2) FUN_00521250(PTR8(0x008367a4), data, size);
            break;
        case 12:
            if (size == 1) FUN_00521250(PTR8(0x008367a6), data, size);
            break;
        case 13:
            if (size == 0x400) FUN_00521250(PTR8(0x008367a7), data, size);
            break;
        case 14:
            if (size == 2) FUN_00521250(PTR8(0x00836ba8), data, size);
            break;
        case 15:
            if (size == 0x270) FUN_00521250(PTR8(0x00836bac), data, size);
            break;
        case 16:
            if (size == 0x3400) FUN_00521250(DAT_00836e1c, data, size);
            break;
        case 17:
            if (size == 0x2c0) FUN_00521250(D_0083a21c, data, size);
            break;
        case 18:
            if (size == 4) FUN_00521250(PTR8(0x0083a6dc), data, size);
            break;
        case 19:
            if (size == 8) FUN_00521250(PTR8(0x0083a6e0), data, size);
            break;
        case 20:
            if (size == 4) FUN_00521250(PTR8(0x0083a6e8), data, size);
            break;
        case 21:
            if (size == 4) FUN_00521250(PTR8(0x0083a6ec), data, size);
            break;
        case 22:
            if (size == 4) FUN_00521250(PTR8(0x0083a6f0), data, size);
            break;
        case 23:
            if (size == 4) FUN_00521250(PTR8(0x0083a6f4), data, size);
            break;
        case 24:
            if (size == 0x2c) FUN_00521250(PTR8(0x0083a8c4), data, size);
            break;
        case 25:
            if (size == 0x200) FUN_00521250(PTR8(0x0083a4dc), data, size);
            break;
        case 26:
            if (size == 0x1c) FUN_00521250(D_0083A6FC, data, size);
            break;
        case 27:
            if (size == 0x10) FUN_00521250(DAT_0083a718, data, size);
            break;
        case 28:
            if (size == 8) FUN_00521250(PTR8(0x0083a728), data, size);
            break;
        case 29:
            if (size == 4) FUN_00521250(PTR8(0x0083a730), data, size);
            break;
        case 30:
            if (size == 0x100) FUN_00521250(PTR8(0x0083a734), data, size);
            break;
        case 31:
            if (size == 0x90) FUN_00521250(PTR8(0x0083a834), data, size);
            break;
        case 32:
            break;
        case 33:
            if (size == 0x1a8) FUN_00521250(PTR8(0x0083a8f0), data, size);
            break;
        case 34:
            if (size == 1) FUN_00521250(PTR8(0x0083679e), data, size);
            break;
        case 35:
            if (size == 4) FUN_00521250(PTR8(0x0083aa98), data, size);
            break;
        case 36:
            if (size == 4) FUN_00521250(PTR8(0x0083a6f8), data, size);
            break;

        /* Group bodies: retail 0x17a044..0x17a3b8. */
        case 0x100:
        case 0x200:
        case 0x300:
        case 0x400:
        case 0x500:
        case 0x600:
        case 0x700:
        case 0x800:
        case 0x900:
        case 0xa00:
            if (size == 4)
                FUN_00521250(D_00834010 + ((id >> 8) - 1) * 0x364, data, size);
            break;
        case 0x101:
        case 0x201:
        case 0x301:
        case 0x401:
        case 0x501:
        case 0x601:
        case 0x701:
        case 0x801:
        case 0x901:
        case 0xa01:
            if (size == 0x50)
                FUN_00521250(D_00834010 + 4 + ((id >> 8) - 1) * 0x364, data, size);
            break;
        case 0x102:
        case 0x202:
        case 0x302:
        case 0x402:
        case 0x502:
        case 0x602:
        case 0x702:
        case 0x802:
        case 0x902:
        case 0xa02:
            if (size == 8)
                FUN_00521250(D_00834010 + 0x54 + ((id >> 8) - 1) * 0x364, data, size);
            break;
        case 0x103:
        case 0x203:
        case 0x303:
        case 0x403:
        case 0x503:
        case 0x603:
        case 0x703:
        case 0x803:
        case 0x903:
        case 0xa03:
            if (size == 0x50)
                FUN_00521250(D_00834010 + 0x5c + ((id >> 8) - 1) * 0x364, data, size);
            break;
        case 0x104:
        case 0x204:
        case 0x304:
        case 0x404:
        case 0x504:
        case 0x604:
        case 0x704:
        case 0x804:
        case 0x904:
        case 0xa04:
            if (size == 0x30)
                FUN_00521250(D_00834010 + 0xac + ((id >> 8) - 1) * 0x364, data, size);
            break;
        case 0x105:
        case 0x205:
        case 0x305:
        case 0x405:
        case 0x505:
        case 0x605:
        case 0x705:
        case 0x805:
        case 0x905:
        case 0xa05:
            if (size == 0x34)
                FUN_00521250(D_00834010 + 0xdc + ((id >> 8) - 1) * 0x364, data, size);
            break;
        case 0x106:
        case 0x206:
        case 0x306:
        case 0x406:
        case 0x506:
        case 0x606:
        case 0x706:
        case 0x806:
        case 0x906:
        case 0xa06:
            if (size == 0x10)
                FUN_00521250(D_00834010 + 0x110 + ((id >> 8) - 1) * 0x364, data, size);
            break;
        case 0x107:
        case 0x207:
        case 0x307:
        case 0x407:
        case 0x507:
        case 0x607:
        case 0x707:
        case 0x807:
        case 0x907:
        case 0xa07:
            if (size == 0x10)
                FUN_00521250(D_00834010 + 0x120 + ((id >> 8) - 1) * 0x364, data, size);
            break;
        case 0x108:
        case 0x208:
        case 0x308:
        case 0x408:
        case 0x508:
        case 0x608:
        case 0x708:
        case 0x808:
        case 0x908:
        case 0xa08:
            if (size == 0x50)
                FUN_00521250(D_00834010 + 0x130 + ((id >> 8) - 1) * 0x364, data, size);
            break;
        case 0x109:
        case 0x209:
        case 0x309:
        case 0x409:
        case 0x509:
        case 0x609:
        case 0x709:
        case 0x809:
        case 0x909:
        case 0xa09:
            if (size == 0x190)
                FUN_00521250(D_00834010 + 0x180 + ((id >> 8) - 1) * 0x364, data, size);
            break;
        case 0x10a:
        case 0x20a:
        case 0x30a:
        case 0x40a:
        case 0x50a:
        case 0x60a:
        case 0x70a:
        case 0x80a:
        case 0x90a:
        case 0xa0a:
            if (size == 0x50)
                FUN_00521250(D_00834010 + 0x310 + ((id >> 8) - 1) * 0x364, data, size);
            break;
        case 0x10b:
        case 0x20b:
        case 0x30b:
        case 0x40b:
        case 0x50b:
        case 0x60b:
        case 0x70b:
        case 0x80b:
        case 0x90b:
        case 0xa0b:
            if (size == 4)
                FUN_00521250(D_00834010 + 0x360 + ((id >> 8) - 1) * 0x364, data, size);
            break;

        case 0x1000:
            if (size == 400) FUN_00521250(PTR8(0x00833e80), data, size);
            break;
        case 0x1001:
            if (size == 600) FUN_00521250(PTR8(0x00833c20), data, size);
            break;
        default:
            break;
    }
}

// FUN_0017a430
void FUN_0017a430(u32 saveType, u32 id, u32 size, const void* data)
{
    (void)saveType;
    switch (id)
    {
        case 1: break;
        case 2:
            if (DAT_007ce050 != NULL && size == 0x50)
                FUN_00521250(DAT_007ce050, data, 0x50);
            break;
        case 3: break;
        case 4: break;
        case 5: break;
        case 6: break;
        case 7: break;
        case 8: break;
        case 9: break;
        case 10: break;
        case 11: break;
        case 12: break;
        case 13: break;
        case 14: break;
        case 15: break;
        case 16:
            if (DAT_007ce054 != NULL && size == 0x3400)
                FUN_00521250(DAT_007ce054, data, size);
            break;
        case 17:
            if (DAT_007ce058 != NULL && size == 0x2c0)
                FUN_00521250(DAT_007ce058, data, size);
            break;
        case 18: break;
        case 19: break;
        case 20: break;
        case 21: break;
        case 22: break;
        case 23: break;
        case 24:
            if (size == 0x2c)
                FUN_00521250(DAT_007ce05c, data, size);
            break;
        case 25: break;
        case 26: break;
        case 27: break;
        case 28: break;
        case 29: break;
        case 30: break;
        case 31: break;
        case 32: break;
        case 33: break;
        case 34: break;
        case 35: break;
        case 36: break;
        case 0x100: break;
        case 0x200: break;
        case 0x300: break;
        case 0x400: break;
        case 0x500: break;
        case 0x600: break;
        case 0x700: break;
        case 0x800: break;
        case 0x900: break;
        case 0xa00: break;
        case 0x101: break;
        case 0x201: break;
        case 0x301: break;
        case 0x401: break;
        case 0x501: break;
        case 0x601: break;
        case 0x701: break;
        case 0x801: break;
        case 0x901: break;
        case 0xa01: break;
        case 0x102: break;
        case 0x202: break;
        case 0x302: break;
        case 0x402: break;
        case 0x502: break;
        case 0x602: break;
        case 0x702: break;
        case 0x802: break;
        case 0x902: break;
        case 0xa02: break;
        case 0x103: break;
        case 0x203: break;
        case 0x303: break;
        case 0x403: break;
        case 0x503: break;
        case 0x603: break;
        case 0x703: break;
        case 0x803: break;
        case 0x903: break;
        case 0xa03: break;
        case 0x104: break;
        case 0x204: break;
        case 0x304: break;
        case 0x404: break;
        case 0x504: break;
        case 0x604: break;
        case 0x704: break;
        case 0x804: break;
        case 0x904: break;
        case 0xa04: break;
        case 0x105: break;
        case 0x205: break;
        case 0x305: break;
        case 0x405: break;
        case 0x505: break;
        case 0x605: break;
        case 0x705: break;
        case 0x805: break;
        case 0x905: break;
        case 0xa05: break;
        case 0x106: break;
        case 0x206: break;
        case 0x306: break;
        case 0x406: break;
        case 0x506: break;
        case 0x606: break;
        case 0x706: break;
        case 0x806: break;
        case 0x906: break;
        case 0xa06: break;
        case 0x107: break;
        case 0x207: break;
        case 0x307: break;
        case 0x407: break;
        case 0x507: break;
        case 0x607: break;
        case 0x707: break;
        case 0x807: break;
        case 0x907: break;
        case 0xa07: break;
        case 0x108: break;
        case 0x208: break;
        case 0x308: break;
        case 0x408: break;
        case 0x508: break;
        case 0x608: break;
        case 0x708: break;
        case 0x808: break;
        case 0x908: break;
        case 0xa08: break;
        case 0x109: break;
        case 0x209: break;
        case 0x309: break;
        case 0x409: break;
        case 0x509: break;
        case 0x609: break;
        case 0x709: break;
        case 0x809: break;
        case 0x909: break;
        case 0xa09: break;
        case 0x10a: break;
        case 0x20a: break;
        case 0x30a: break;
        case 0x40a: break;
        case 0x50a: break;
        case 0x60a: break;
        case 0x70a: break;
        case 0x80a: break;
        case 0x90a: break;
        case 0xa0a: break;
        case 0x10b: break;
        case 0x20b: break;
        case 0x30b: break;
        case 0x40b: break;
        case 0x50b: break;
        case 0x60b: break;
        case 0x70b: break;
        case 0x80b: break;
        case 0x90b: break;
        case 0xa0b: break;
        case 0x1000: break;
        case 0x1001: break;
        default: break;
    }
}

#pragma opt_loop_invariants on
#pragma opt_lifetimes on
// FUN_0017ac60
void FUN_0017ac60(u32 code)
{
    struct CodeEntry
    {
        u8 first;
        u8 second;
        u8 third;
        u8 fourth;
    };
    struct CodeWork
    {
        u8 unused[0x5a7];
        struct CodeEntry entries[0x100];
    };
    u8 bytes[4];
    struct CodeWork* work;
    s32 i;
    s32 j;
    s32 b0;
    s32 b1;
    s32 b2;

    *(u32*)bytes = code;
    i = 0;
    b0 = bytes[0];
    b1 = bytes[1];
    b2 = bytes[2];
    work = (struct CodeWork*)DAT_00836200;
    while (i < 0x100)
    {
        if (work->entries[i].first != 0 && work->entries[i].first == b0 &&
            work->entries[i].second == b1 && work->entries[i].third == b2)
        {
            j = i;
            while (j < 0xff)
            {
                work->entries[j] = work->entries[j + 1];
                j++;
            }
            DAT_00836ba3[0] = 0;
        }
        i++;
    }
    i = 0;
    work = (struct CodeWork*)DAT_00836200;
    while (i < 0x100)
    {
        if (work->entries[i].first == 0)
        {
            work->entries[i] = *(struct CodeEntry*)bytes;
            break;
        }
        i++;
    }
}
#pragma opt_lifetimes reset
#pragma opt_loop_invariants reset

#pragma optimization_level 1
// FUN_0017ad90
void FUN_0017ad90(void)
{
    s32 i;
    s32 offset;
    u8* base;
    u8* previous;

    i = 0;
    base = DAT_00836200;
    while (i < 0x100)
    {
        offset = i * 4;
        if (*(u8*)((u32)base + (u32)offset + 0x5a7) == 0)
        {
            if (i == 0) return;
            previous = DAT_00836200 + 0x5a3;
            *(u8*)((u32)previous + (u32)offset) = 0;
            return;
        }
        i++;
    }
}

#pragma optimization_level 2
// FUN_0017adf0
void FUN_0017adf0(void)
{
    s32 i;
    u8* base;

    i = 0;
    base = DAT_00836200;
    while (i < 0x100)
    {
        *(u8*)((u32)base + (u32)(i * 4) + 0x5a7) = 0;
        i++;
    }
}

// FUN_0017ae30
u8* FUN_0017ae30(s32 index)
{
    u8* base = DAT_00836200;
    return base + index * 4 + 0x5a7;
}
// FUN_0017ae50
u32 FUN_0017ae50(s32 id)
{
    s32 i;
    ResourceEntry* entries;
    u16 target;
    u16* levels;

    if (((u16)id & 0x8000) != 0) id = ((ResourceEntry*)PTRP(0x00836794))[(u16)id].id;
    target = (u16)id;
    if (target >= 4000)
    {
        levels = (u16*)PTRP(0x00836798);
        if (levels[(s16)id - 4000] != 0) return 1;
    }
    else
    {
        i = 0;
        entries = (ResourceEntry*)PTRP(0x00836794);
        while (i < 300)
        {
            if (entries[i].id == target) return 1;
            i++;
        }
    }
    return 0;
}

// FUN_0017af20
void FUN_0017af20(u16 id)
{
    u8 record[0x20];
    u16* levels;

    if (id & 0x8000) id = ((ResourceEntry*)PTRP(0x00836794))[id].id;
    if (id >= 4000)
    {
        levels = (u16*)PTRP(0x00836798);
        func_00170860(1, (s16)id, levels[(s16)id - 4000] + 1);
    }
    else
    {
        func_001828d0((s16)id, record);
        func_001830c0(record);
    }
}

// FUN_0017afd0
u32 FUN_0017afd0(u16 id)
{
    s32 i;
    ResourceEntry* entries;
    if (id & 0x8000) id = ((ResourceEntry*)PTRP(0x00836794))[id].id;
    if (id >= 4000) return 1;
    i = 0;
    entries = (ResourceEntry*)PTRP(0x00836794);
    while (i < 300)
    {
        if (entries[i].id == 0) return 1;
        i++;
    }
    return 0;
}

// FUN_0017b070
void FUN_0017b070(u32 id)
{
    u16 value = (u16)id;

    if ((value & 0x8000) != 0)
    {
        ((ResourceEntry*)PTRP(0x00836794))[value & 0x7fff].id = 0;
    }
    else
    {
        s16 signedId = (s16)id;
        s32 levelAddress;
        u16* level;
        levelAddress = signedId * 2;
        levelAddress = ((u32)PTRP(0x00836798) - 0x1f40) + levelAddress;
        level = (u16*)levelAddress;
        if (*level != 0)
        {
            func_00170860(1, signedId, *level - 1);
        }
    }
}

// FUN_0017b100
void FUN_0017b100(u16 id)
{
    if (id & 0x8000) id = ((ResourceEntry*)PTRP(0x00836794))[id].id;
    func_00171110(id, 2);
}

// FUN_0017b160
void datResetTotalBtl()
{
    gGlobalWork.totalBtl = 0;
}

// FUN_0017b170
u32 datGetTotalBtl()
{
    return gGlobalWork.totalBtl;
}

// FUN_0017b180
u32 FUN_0017b180(s32 amount)
{
    u32 totalBtl;

    totalBtl = gGlobalWork.totalBtl + amount;
    gGlobalWork.totalBtl = totalBtl;
    return totalBtl;
}

// FUN_0017b1a0
void FUN_0017b1a0(void)
{
    s32 i = 0;
    u8* base = DAT_00836200;
    for (; i < 11; i++) *(u32*)(base + i * 4 + 0x46c4) = 0;
}

// FUN_0017b1e0
void FUN_0017b1e0(u32 id)
{
    s32 key = id & 0xffff;
    u32 mask = 1u << (key & 31);
    s32 index = key >> 5;
    u32* bits = (u32*)(DAT_00836200 + 0x46c4);
    bits[index] |= mask;
}

// FUN_0017b220
void FUN_0017b220(u32 id)
{
    s32 key = id & 0xffff;
    u32 mask = 1u << (key & 31);
    s32 index = key >> 5;
    u32* bits = (u32*)(DAT_00836200 + 0x46c4);
    bits[index] &= ~mask;
}

// FUN_0017b260
u32 FUN_0017b260(u32 id)
{
    s32 key = id & 0xffff;
    s32 index = key >> 5;
    u32* bits = (u32*)(DAT_00836200 + 0x46c4);
    u32 mask = 1u << (key & 31);
    u32 result = bits[index];
    return result & mask;
}

// FUN_0017b2a0
void FUN_0017b2a0(void)
{
    s32 i = 0;
    u8* base = DAT_00836200;
    for (; i < 0x6a; i++) *(u32*)(base + i * 4 + 0x46f0) = 0;
}

// FUN_0017b2e0
void FUN_0017b2e0(u32 personaId, u32 slot, s32 enabled)
{
    u32 persona = personaId & 0xffff;
    u32 slotValue;
    u32 index;
    u32 wordIndex;
    u32 mask;

    if ((s32)persona >= 0x150) FUN_0019d3f0((u32)D_005e3098, 0x1631);
    slotValue = slot & 0xffff;
    if ((s32)slotValue >= 10) FUN_0019d3f0((u32)D_005e3098, 0x1632);
    index = slotValue + persona * 10;
    wordIndex = index >> 5;
    mask = 1u << (index & 31);
    if (enabled != 0)
        ((u32*)(DAT_00836200 + 0x46f0))[wordIndex] |= mask;
    else
        ((u32*)(DAT_00836200 + 0x46f0))[wordIndex] &= ~mask;
}

// FUN_0017b3d0
bool FUN_0017b3d0(u32 personaId, u32 slot)
{
    u32 index;
    s32 wordIndex;
    u32* bits;
    u32 mask;
    u32 result;
    if ((s32)(personaId & 0xffff) >= 0x150) FUN_0019d3f0((u32)D_005e3098, 0x1644);
    if ((s32)(slot & 0xffff) >= 10) FUN_0019d3f0((u32)D_005e3098, 0x1645);
    index = (slot & 0xffff) + (personaId & 0xffff) * 10;
    wordIndex = index >> 5;
    bits = (u32*)(DAT_00836200 + 0x46f0);
    mask = 1u << (index & 31);
    result = bits[wordIndex];
    return (result & mask) != 0;
}

// FUN_0017b480
s8 FUN_0017b480(s32 id)
{
    u16 check;
    check = id;
    if ((s32)check >= 0x270) FUN_0019d3f0((u32)D_005e3098, 0x166b);
    return puGpffffb704[(id & 0xffff) * 2 + 1];
}

// FUN_0017b4e0
void dat0017b4e0(void)
{
    FUN_00300af0_y2();
}

// FUN_0017b500
void FUN_0017b500(s16 player, u64 value)
{
    u8* record;
    if (player == 1) record = DAT_00836200 + 0x24;
    else
    {
        if ((s32)player >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1);
        record = D_00834010 + (player - 2) * 0x364 + 4;
    }
    FUN_003086c0(record, value);
}
// FUN_0017b5b0
void FUN_0017b5b0(s16 player, u64 value)
{
    u8* record;
    if (player == 1) record = DAT_00836200 + 0x24;
    else
    {
        if ((s32)player >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1);
        record = D_00834010 + (player - 2) * 0x364 + 4;
    }
    FUN_003083f0(record, value);
}

// FUN_0017b660
s32 FUN_0017b660(s16 player, u64 id)
{
    u8* record;
    s32 index;
    u32* word;
    u32 mask;

    if (player == 1) record = DAT_00836200 + 0x24;
    else
    {
        if ((s32)player >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1);
        record = D_00834010 + (player - 2) * 0x364 + 4;
    }

    if (U16(record + 2) == 0 || (s32)U16(record + 2) >= 0xb)
        FUN_0019d3f0((u32)D_005e3098, 0x16aa);

    switch (id & 0xffff)
    {
    case 0x19f:
        index = D_005e3840[U16(record + 2)][0];
        word = D_0083a21c + index / 32;
        mask = 1u << (index % 32);
        return (*word & mask) != 0 ? 4 : 0;
    case 0x1a9:
        index = D_005e3844[U16(record + 2)][0];
        word = D_0083a21c + index / 32;
        mask = 1u << (index % 32);
        return (*word & mask) != 0 ? 4 : 0;
    default:
        return FUN_003086f0(record, id);
    }
}

// FUN_0017b860
s32 FUN_0017b860(s16 player, s16 sourcePlayer, u64 id, u64 value)
{
    s32 index;
    u8* left;
    u8* right;

    if (sourcePlayer == 0 || (s32)sourcePlayer >= 0xb)
        FUN_0019d3f0((u32)D_005e3098, 0x16c0);

    switch (id & 0xffff)
    {
    case 0x19f:
        index = D_005e3840[sourcePlayer][0];
        if (index < 0 || index >= 0x1600)
            FUN_0019d3f0((u32)D_005e3098, 0x78d);
        if (index == 0x1376) printf((char*)&gSpecialStatusMessage);
        D_0083a21c[index / 32] |= 1u << (index % 32);
        return 1;
    case 0x1a9:
        index = D_005e3844[sourcePlayer][0];
        if (index < 0 || index >= 0x1600)
            FUN_0019d3f0((u32)D_005e3098, 0x78d);
        if (index == 0x1376) printf((char*)&gSpecialStatusMessage);
        D_0083a21c[index / 32] |= 1u << (index % 32);
        return 1;
    }

    if (player == 1) left = DAT_00836200 + 0x24;
    else
    {
        if ((s32)player >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1);
        left = D_00834010 + (player - 2) * 0x364 + 4;
    }
    if (sourcePlayer == 1) right = DAT_00836200 + 0x24;
    else
    {
        if ((s32)sourcePlayer >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1);
        right = D_00834010 + (sourcePlayer - 2) * 0x364 + 4;
    }

    return FUN_00306610(id, left, right, value);
}
// FUN_0017bb40
u8 FUN_0017bb40(s32 id)
{
    u16 checkedId = id;

    if ((s32)checkedId >= 0x1d0)
        FUN_0019d3f0((u32)D_005e3098, 0x16dd);
    return DAT_007ce3f8[(id & 0xffff) * 0x2c + 8];
}

/* W357 measured opt_loop_invariants on: without nd23/object400, with nd0/object400; window 400 (exact MATCH). */
// FUN_0017bbb0
u8 FUN_0017bbb0(s32 id)
{
    u16 checkedId = id;

    if ((s32)checkedId >= 0x1d0)
        FUN_0019d3f0((u32)D_005e3098, 0x16ec);
    return DAT_007ce3f8[(id & 0xffff) * 0x2c + 9];
}

/* W357 measured optimization_level 1: without nd22/object176 (MISMATCH), with nd0/object176 (MATCH); retained. */
// FUN_0017bc20
s32 FUN_0017bc20(s16 player, s16 sourcePlayer, u64 id, u64 value)
{
    u8* left;
    u8* right;
    u16 condition;

    if (sourcePlayer == 0 || (s32)sourcePlayer >= 0xb)
        FUN_0019d3f0((u32)D_005e3098, 0x1702);

    switch (id & 0xffff)
    {
    case 0x19f:
    case 0x1a9:
        condition = sourcePlayer == 1
            ? *(u16*)(DAT_00836200 + 0x6c)
            : *(u16*)(D_00833994 + sourcePlayer * 0x364);
        return condition == 5 ? 0 : 8;
    }

    if (player == 1) left = DAT_00836200 + 0x24;
    else
    {
        if ((s32)player >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1);
        left = D_00834010 + (player - 2) * 0x364 + 4;
    }
    if (sourcePlayer == 1) right = DAT_00836200 + 0x24;
    else
    {
        if ((s32)sourcePlayer >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1);
        right = D_00834010 + (sourcePlayer - 2) * 0x364 + 4;
    }

    return FUN_003068d0(id, left, right, value);
}
// FUN_0017be10
void FUN_0017be10(s16 player, s16 sourcePlayer, u64 id, u64 a, u64 b, u64 c, u64 d)
{
    u8* left;
    u8* right;
    if (player == 1) left = DAT_00836200 + 0x24;
    else { if ((s32)player >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1); left = D_00834010 + (player - 2) * 0x364 + 4; }
    if (sourcePlayer == 1) right = DAT_00836200 + 0x24;
    else { if ((s32)sourcePlayer >= 0xb) FUN_0019d3f0((u32)D_005e3098, 0x2e1); right = D_00834010 + (sourcePlayer - 2) * 0x364 + 4; }
    FUN_00306bc0(id, left, right, a, b, c, d);
}

// FUN_0017bf70
u32 dat0017bf70(u16 param_1)
{
    if (param_1 < 0x1bf)
    {
        return 0;
    }

    return param_1 < 0x1d0;
}

// FUN_0017bfa0
u8 FUN_0017bfa0(s32 id, s32 field)
{
    u8 checkedField = field;
    u32 inRange;
    s32 maskedId;

    if ((s32)checkedField < 0 || (s32)checkedField >= 5)
        FUN_0019d3f0((u32)D_005e3098, 0x173b);
    maskedId = id & 0xffff;
    if (maskedId < 0x1bf)
    {
        inRange = 0;
    }
    else
    {
        if (maskedId > 0x1cf)
        {
            inRange = 0;
        }
        else
        {
            inRange = 1;
        }
    }
    if (inRange == 0) return 0;
    return (DAT_007ce4a0 + maskedId * 5)[(field & 0xff) - 0x8bb];
}

/* Removing this loses FUN_0017c700 (MATCH nd0 -> MISMATCH nd21) - measured W161. */
// FUN_0017c070
u32 FUN_0017c070(u32 id)
{
    u8* record;
    u32 offset;
    u32 result;

    if ((s32)(id & 0xffff) >= 0x1d0) return 0;
    offset = (id & 0xffff) * 0x2c;
    record = (u8*)((u32)offset + (u32)DAT_007ce3f8);
    if (record[0x11] == 0xb && *(s16*)(record + 0x12) == 100)
        result = 1;
    else
        result = 0;
    return result;
}

// FUN_0017c0e0
u32 FUN_0017c0e0(u32 id)
{
    u16 flags;
    u32 valid = id < 0x100;

    if (valid == 0) FUN_0019d3f0((u32)D_005e3098, 0x1755);
    flags = *(u16*)(DAT_007ce42c + id * 0x58);
    if (flags & 2) return 2;
    if (flags & 4) return 4;
    if (flags & 8) return 8;
    return 0;
}

// FUN_0017C190


void func_0017c190(void)



{

  FUN_00521408(D_0083A6FC,0,0x1c);

  return;

}

// FUN_0017c1c0
void FUN_0017c1c0(const void* source)
{
    if (source == NULL) FUN_0019d3f0((u32)D_005e3098, 0x176d);
    memcpy(D_0083A6FC, source, 0x1c);
}

// FUN_0017c220
void FUN_0017c220(void* destination)
{
    if (destination == NULL) FUN_0019d3f0((u32)D_005e3098, 0x1775);
    memcpy(destination, D_0083A6FC, 0x1c);
}

/* W357 measured opt_lifetimes on: without nd42/object796, with nd15/object796; window 800 (under). */
// FUN_0017C280


void func_0017c280(void)



{

    u8* entry;
    int i;

    for (i = 0; i < 4; i++)
    {
        entry = DAT_00836200 + i * 4;
        FUN_00521408(entry + 0x4518, 0, 4);
        *(s16*)(entry + 0x4518) = -1;
    }

}

// FUN_0017c2f0
s32 FUN_0017c2f0(const u32* left, const u32* right)
{
    const s16* leftValue = (const s16*)*left;
    const s16* rightValue = (const s16*)*right;
    return FUN_00403740(*leftValue) - FUN_00403740(*rightValue);
}

#pragma opt_loop_invariants on
// FUN_0017c350
void FUN_0017c350(void)
{
    void* (**allocator)(u32, u32);
    void (**releaser)(void*);
    s16* source;
    u8** sorted;
    s32 count;
    s32 i;
    s16 empty = -1;

    count = 0;
    allocator = (void* (**)(u32, u32))D_00960178;
    source = (s16*)(*allocator)(0x10, 0x40000);
    memcpy(source, DAT_0083a718, 0x10);
    sorted = (u8**)(*allocator)(0x10, 0x40000);
    FUN_00521408(sorted, 0, 0x10);
    for (i = 0; i < 4; i++)
    {
        if (source[i * 2] != empty)
            sorted[count++] = (u8*)(source + i * 2);
    }
    if (count != 0)
    {
        qsort(sorted, count, 4, (int (*)(const void*, const void*))FUN_0017c2f0);
        count = 0;
        while (count < 4)
        {
            if (sorted[count] != NULL)
                memcpy(DAT_00836200 + count * 4 + 0x4518, sorted[count], 4);
            else
                *(s16*)(DAT_00836200 + count * 4 + 0x4518) = -1;
            count++;
        }
    }
    releaser = (void (**)(void*))D_0096017C;
    (*releaser)(sorted);
    (*releaser)(source);
}
#pragma opt_loop_invariants reset

#pragma optimization_level 1
// FUN_0017c4e0
bool FUN_0017c4e0(s16 value)
{
    struct CalendarSlot
    {
        s16 value;
        s16 unused;
    };
    struct CalendarWork
    {
        u8 unused[0x4518];
        struct CalendarSlot slots[3];
    };
    s32 i = 0;
    struct CalendarSlot* slot;
    struct CalendarWork* work = (struct CalendarWork*)DAT_00836200;
    u8* candidateBase;
    s32 empty = -1;

    while (i < 3)
    {
        candidateBase = (u8*)((u32)work + (u32)(i * 4));
        if (*(s16*)(candidateBase + 0x4518) == empty)
        {
            slot = (struct CalendarSlot*)(candidateBase + 0x4518);
            FUN_00521408(slot, 0, 4);
            goto found;
        }
        i++;
    }
    slot = NULL;
found:
    if (slot == NULL) return false;
    slot->value = value;
    FUN_0017c350();
    return true;
}

#pragma optimization_level 2

// FUN_0017c590
void FUN_0017c590(s16 value)
{
    struct CalendarSlot
    {
        s16 value;
        s16 unused;
    };
    struct CalendarWork
    {
        u8 unused[0x4518];
        struct CalendarSlot slots[3];
    };
    s32 i = 0;
    s32 target = value;
    struct CalendarWork* work = (struct CalendarWork*)DAT_00836200;

    while (i < 3)
    {
        struct CalendarSlot* slot = &work->slots[i];
        if (slot->value == target)
        {
            slot->value = -1;
            break;
        }
        i++;
    }
    FUN_0017c350();
}


// FUN_0017c610
s16* FUN_0017c610(s16 value)
{
    struct CalendarEntry
    {
        u8 unused[0x4518];
        s16 value;
    };
    s32 i = 0;
    s32 target = value;
    struct CalendarEntry* data = (struct CalendarEntry*)DAT_00836200;

    for (; i < 3; i++)
    {
        struct CalendarEntry* entry = (struct CalendarEntry*)((u8*)data + i * 4);
        if (entry->value == target)
            return &entry->value;
    }
    return NULL;
}

// FUN_0017c670
s16* FUN_0017c670(s32 index)
{
    s32 offset = index * 4;

    if (*(s16*)(DAT_0083a718 + offset) != -1)
        return (s16*)(DAT_00836200 + offset + 0x4518);
    return NULL;
}

// FUN_0017c6c0
void dat0017c6c0(void)
{
    FUN_00403130();
}

// FUN_0017c6e0
void dat0017c6e0(void)
{
    FUN_00403220();
}

#pragma opt_loop_invariants on
// FUN_0017c700
s32 FUN_0017c700(void)
{
    s32 count = 0;
    s32 sentinel = -1;
    s32 i = 0;
    u8* base = DAT_00836200;
    for (; i < 3; i++)
    {
        s32 value = *(s16*)(base + i * 4 + 0x4518);
        if (value != sentinel) count++;
    }
    return count;
}
#pragma opt_loop_invariants reset

/* W212: first divergence is the prologue (ours 0x60-byte frame, retail 0x50).
 * Replacing the addressed u8[8] with a u64 aggregate measured identically
 * (nd228, 440/448) and was reverted; FUN_0017cd30 has no comparable date cascade. */
// FUN_0017c750
void FUN_0017c750(u64 value)
{
    s32 i;
    for (i = 0; i < 3; i++)
    {
        u8* entry = DAT_00836200 + i * 4;
        if (*(s16*)(entry + 0x4518) != -1 &&
            FUN_00403920(*(s16*)(entry + 0x4518), value) != 0)
        {
            s16* counter = (s16*)(entry + 0x451a);
            s16 current = *counter;
            if (current < 0x7d01) *counter = current + 1;
        }
    }
}

// FUN_0017c7f0
void FUN_0017c7f0(s32 index, u8 value)
{
    if (index < 0 || index >= 8) FUN_0019d3f0((u32)D_005e3098, 0x180f);
    DAT_00836200[0x4528 + index] = value;
}

// FUN_0017c860
u8 FUN_0017c860(s32 index)
{
    if (index < 0 || index >= 8) FUN_0019d3f0((u32)D_005e3098, 0x1814);
    return DAT_00836200[0x4528 + index];
}

// FUN_0017c8c0
DatPersonaWork* datGetPersonaByCompendium(s32 idx)
{
    K_ASSERT(idx >= 0 && idx < 256, 6177);

    if (gGlobalWork.compendium[idx].flags & PERSONA_FLAG_VALID)
    {
        return &gGlobalWork.compendium[idx];
    }

    return NULL;
}

/* W357 measured optimization_level 1: without nd12/object36 (MISMATCH), with nd0/object40 (MATCH); window 48; retained. */
// FUN_0017c960
void FUN_0017c960(const void* record)
{
    const u8* source = (const u8*)record;
    s32 id;

    if (source == NULL) FUN_0019d3f0((u32)D_005e3098, 0x182b);
    id = *(const u16*)(source + 2);
    if (id < 0 || id >= 0x100) FUN_0019d3f0((u32)D_005e3098, 0x182c);
    memcpy(DAT_00836200 + *(const u16*)(source + 2) * 0x34 + 0xc1c, source, 0x34);
}
#pragma opt_lifetimes on
/* W389 classification: loop-index lifetime/register-colouring floor; six singles and all 15 knob pairs were neutral; final nd15/object796/800 with opt_lifetimes on. */
// FUN_0017ca10 NONMATCHING
s32 FUN_0017ca10(const void* record)
{
    const u8* source = (const u8*)record;
    u8* stored;
    s32 i;
    s32 j;
    u16 index;
    u8 unsignedValue;
    s8 signedValue;
    u16 index2;
    u16 index3;

    if (record == NULL) FUN_0019d3f0((u32)D_005e3098, 0x1837);
    if (*(const u16*)(source + 2) < 0 ||
        *(const u16*)(source + 2) >= 0x100)
        FUN_0019d3f0((u32)D_005e3098, 0x1838);
    stored = DAT_00836200 + *(const u16*)(source + 2) * 0x34 + 0xc1c;
    if ((*(const u16*)stored & 1) == 0) return -1;
    if (*(const u16*)stored != *(const u16*)source) return 1;
    if (stored[4] != source[4]) return 1;
    if (*(const u32*)(stored + 8) != *(const u32*)(source + 8)) return 1;
    for (i = 0; i < 5; i++)
    {
        index = (u16)i;
        if (index >= 5) FUN_0019d3f0((u32)D_005e3278, 0x13c);
        unsignedValue = *(u8*)(stored + 0x1c + index);
        if (index >= 5) FUN_0019d3f0((u32)D_005e3278, 0x13c);
        if ((u32)unsignedValue != (u32)*(u8*)(source + 0x1c + i)) return 1;
    }
    for (i = 0; i < 5; i++)
    {
        index2 = (u16)i;
        if (index2 >= 5) FUN_0019d3f0((u32)D_005e3278, 0x1c6);
        signedValue = *(s8*)(stored + 0x21 + index2);
        if (index2 >= 5) FUN_0019d3f0((u32)D_005e3278, 0x1c6);
        if ((s32)signedValue != (s32)*(s8*)(source + 0x21 + i)) return 1;
    }
    for (i = 0; i < 5; i++)
    {
        index3 = (u16)i;
        if (index3 >= 5) FUN_0019d3f0((u32)D_005e3278, 0x1f7);
        signedValue = *(s8*)(stored + 0x26 + index3);
        if (index3 >= 5) FUN_0019d3f0((u32)D_005e3278, 0x1f7);
        if ((s32)signedValue != (s32)*(s8*)(source + 0x26 + i)) return 1;
    }
    {
        const u16* storedValues = (const u16*)(stored + 0xc);
        const u16* sourceValues = (const u16*)(source + 0xc);
    for (j = 0; j < 8; j++)
    {
        if (storedValues[j] != sourceValues[j])
            return 1;
    }
    }
    return 0;
}
#pragma opt_lifetimes reset

// FUN_0017cd30
void* FUN_0017cd30(void* record)
{
    u8* source = (u8*)record;
    u8* definition;
    u8* stored;
    s32 id;
    s32 storedId;
    u16 flags;

    if (source == NULL) FUN_0019d3f0((u32)D_005e3098, 0x1861);
    id = *(u16*)(source + 2);
    if (id < 0 || id >= 0x100) FUN_0019d3f0((u32)D_005e3098, 0x1862);
    id = *(u16*)(source + 2);
    definition = DAT_007ce420 + id * 0xe;
    flags = *(u16*)definition;
    if (flags & 8) return source;
    if (flags & 0x20) return source;

    if (id < 0 || id >= 0x100) FUN_0019d3f0((u32)D_005e3098, 0x1821);
    if ((*(u16*)(DAT_00836e1c + id * 0x34) & 1) != 0)
        stored = DAT_00836200 + id * 0x34 + 0xc1c;
    else
        stored = NULL;
    if (stored != NULL) return stored;

    if (source == NULL) FUN_0019d3f0((u32)D_005e3098, 0x182b);
    storedId = *(u16*)(source + 2);
    if (storedId < 0 || storedId >= 0x100)
        FUN_0019d3f0((u32)D_005e3098, 0x182c);
    memcpy(DAT_00836200 + *(u16*)(source + 2) * 0x34 + 0xc1c, source, 0x34);
    return NULL;
}







// 005dc050


// 005e4150













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



















/* W357 measured optimization_level 1: without nd8/object96 (MISMATCH), with nd0/object96 (MATCH); retained. */


























































/* Removing this loses FUN_0016d280 (MATCH nd0 -> MISMATCH nd19) - measured W161. */




/* Removing this loses FUN_0016deb0 (MATCH nd0 -> MISMATCH nd47) - measured W161. */








/* Removing this loses FUN_0016ea80 (MATCH nd0 -> MISMATCH nd18) - measured W161. */





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




































/* W357 measured optimization_level 0: without nd10/object24 (MISMATCH), with nd0/object44 (MATCH); window 48; retained. */













































/* Removing this loses FUN_00177280 (MATCH nd0 -> MISMATCH nd26) and 2 more - measured W161. */


/* Removing this loses FUN_00177410 (MATCH nd0 -> MISMATCH nd89) - measured W161. */


/* Removing this worsens FUN_001779a0 (nd14 -> nd121) - measured W161. */
/* W389 classification: register-colouring/loop-index allocation floor; six singles and all 15 knob pairs were neutral, declaration-order trial nd19 vs baseline nd14. */
// FUN_0017cf00
s32 FUN_0017cf00(void)
{
    s32 id;
    s32 valid;
    s32 definitionId;
    s32 eligible;
    u8* stored;
    u8* definitions;

    valid = 0;
    id = 0;
    while (id < 0x100)
    {
        if (id < 0 || id >= 0x100) FUN_0019d3f0((u32)D_005e3098, 0x1821);
        stored = DAT_00836200 + id * 0x34;
        if ((*(u16*)(stored + 0xc1c) & 1) != 0)
            stored = stored + 0xc1c;
        else
            stored = NULL;
        if (stored != NULL) valid++;
        id++;
    }

    eligible = 0;
    definitionId = 0;
    definitions = DAT_007ce420;
    while (definitionId < 0x100)
    {
        u16 flags = *(u16*)(definitions + definitionId * 0xe);
        if ((flags & 8) == 0 && (flags & 0x20) == 0) eligible++;
        definitionId++;
    }
    return valid * 100 / eligible;
}
// FUN_0017d030
u32 FUN_0017d030(void)
{
    return U32(0x0083a730);
}
// FUN_0017d040
void FUN_0017d040(void)
{
    U32(0x0083a730) = *(u32*)(D_0083A6FC + 0x34) + 1;
}
// FUN_0017d060
PairCounter* FUN_0017d060(PairKey key, u16 id, s16 value)
{
    struct PairCounterU
    {
        PairKey key;
        u16 id;
        u16 remaining;
    };
    struct PairCounterWork
    {
        u8 unused[0x4534];
        struct PairCounterU entries[0x20];
    };
    s32 i = 0;
    s32 j;
    u32 keyValue = key.parts.low;
    u32 idValue = id;
    struct PairCounterU* found;
    struct PairCounterU* freeEntry;
    struct PairCounterWork* work = (struct PairCounterWork*)DAT_00836200;

    while (i < 0x20)
    {
        u8* entryBase = (u8*)((u32)work + (u32)(i * 8));
        if (*(u16*)(entryBase + 0x4534) == keyValue &&
            *(u16*)(entryBase + 0x4538) == idValue)
        {
            found = (struct PairCounterU*)(entryBase + 0x4534);
            goto found_entry;
        }
        i++;
    }
    found = NULL;
found_entry:
    if (found != NULL)
    {
        if (found->key.parts.high != key.parts.high)
        {
            found->key = key;
            found->remaining = value;
        }
        return (PairCounter*)found;
    }

    j = 0;
    work = (struct PairCounterWork*)DAT_00836200;
    while (j < 0x20)
    {
        u8* entryBase = (u8*)((u32)work + (u32)(j * 8));
        if (*(u16*)(entryBase + 0x4538) == 0)
        {
            freeEntry = (struct PairCounterU*)(entryBase + 0x4534);
            goto found_free_entry;
        }
        j++;
    }
    freeEntry = NULL;
found_free_entry:
    if (freeEntry == NULL)
    {
        FUN_0019d3f0((u32)D_005e3098, 0x18c5);
    }
    freeEntry->key = key;
    freeEntry->id = id;
    freeEntry->remaining = value;
    return (PairCounter*)freeEntry;
}
// FUN_0017d1a0
u32 FUN_0017d1a0(u32 key, u16 id, s16 amount)
{
    struct PairCounterU
    {
        u16 key;
        u16 keyHigh;
        u16 id;
        u16 remaining;
    };
    struct PairCounterWork
    {
        u8 unused[0x4534];
        struct PairCounterU entries[0x20];
    };
    s32 i = 0;
    u32 keyValue = *(u16*)&key;
    u32 idValue = id;
    struct PairCounterU* found;
    struct PairCounterWork* work = (struct PairCounterWork*)DAT_00836200;

    while (i < 0x20)
    {
        u8* entryBase = (u8*)((u32)work + (u32)(i * 8));
        if (*(u16*)(entryBase + 0x4534) == keyValue &&
            *(u16*)(entryBase + 0x4538) == idValue)
        {
            found = (struct PairCounterU*)(entryBase + 0x4534);
            goto found_entry;
        }
        i++;
    }
    found = NULL;
found_entry:
    if (found != NULL)
    {
        s16 remaining = (s16)(found->remaining - amount);
        if (remaining < 0) remaining = 0;
        found->remaining = remaining;
        return found->remaining;
    }
    return 0xffffffff;
}
// FUN_0017d250
u32 FUN_0017d250(u32 key, u16 id)
{
    struct PairCounterU
    {
        u16 key;
        u16 keyHigh;
        u16 id;
        u16 remaining;
    };
    struct PairCounterWork
    {
        u8 unused[0x4534];
        struct PairCounterU entries[0x20];
    };
    s32 i = 0;
    u32 keyValue = *(u16*)&key;
    u32 idValue = id;
    struct PairCounterU* found;
    struct PairCounterWork* work = (struct PairCounterWork*)DAT_00836200;

    while (i < 0x20)
    {
        u8* entryBase = (u8*)((u32)work + (u32)(i * 8));
        if (*(u16*)(entryBase + 0x4534) == keyValue &&
            *(u16*)(entryBase + 0x4538) == idValue)
        {
            found = (struct PairCounterU*)(entryBase + 0x4534);
            goto found_entry;
        }
        i++;
    }
    found = NULL;
found_entry:
    if (found != NULL) return found->remaining;
    return 0xffffffff;
}
// FUN_0017d2e0
s8 FUN_0017d2e0(u32 id)
{
    s32 index;
    u16 check;

    index = (s16)FUN_003082f0(0, id);
    {
        s8 values[0x13] = {
            0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
            10, 10, 10, 10, 10, 10, 10, 10, 10
        };
        if (index == -1)
        {
            check = id;
            if ((s32)check >= 0x270)
                FUN_0019d3f0((u32)D_005e3098, 0x166b);
            if (puGpffffb704[(id & 0xffff) * 2 + 1] == 2)
                return 0xc;
        }
        return values[index];
    }
}

// FUN_0017d3c0
void FUN_0017d3c0(void)
{
    struct DateTemplate
    {
        f32 a;
        f32 b;
        f32 c;
        f32 d;
    };
    extern const volatile /* Removing this function's qualifier batch loses FUN_0017d3c0 (MATCH nd0 -> MISMATCH nd18, size 144 -> 144) - measured W170. */ struct DateTemplate D_005e38c0;
    volatile /* Removing this function's qualifier batch loses FUN_0017d3c0 (MATCH nd0 -> MISMATCH nd18, size 144 -> 144) - measured W170. */ struct DateTemplate template;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    s32 i;

    a = D_005e38c0.a;
    b = D_005e38c0.b;
    c = D_005e38c0.c;
    d = D_005e38c0.d;
    template.a = a;
    template.b = b;
    template.c = c;
    template.d = d;
    i = 0;
    while (i < 9)
    {
        memcpy(DAT_00836200 + i * 0x10 + 0x4634, (const void*)&template, 0x10);
        i++;
    }
}

// W419 date comparator declaration-order and u64 aggregate probes stayed nd228/object440; u8 flag was nd302/object456 (over window).
// FUN_0017d450 NONMATCHING
u32 FUN_0017d450(s32 index, const void* date)
{
u8 current[8];
s32 newer = 0;

    if (date == NULL) FUN_0019d3f0(0x5e3098, 0x1933);
    if (index >= 5) return 0;
    memcpy(current, DAT_00836200 + index * 0x10 + 0x4634, 8);
    if (index == 3) return 0;
    if (index == 4)
        return current[1] < ((const u8*)date)[1];
    if (current[0] < ((const u8*)date)[0])
        newer = 1;
    if (newer == 0 && current[1] < ((const u8*)date)[1])
        newer = 1;
    if (newer == 0 &&
        *(const u16*)(current + 2) != *(const u16*)((const u8*)date + 2))
        newer = 1;
    if (newer == 0 &&
        *(const u32*)(current + 4) != *(const u32*)((const u8*)date + 4))
        newer = 1;
    if (newer != 0)
    {
        if (FUN_003f33d0(index, 4) != 0) return 1;
        memcpy(DAT_00836200 + (index * 2 + 1) * 8 + 0x4634, current, 8);
        memcpy(DAT_00836200 + index * 0x10 + 0x4634, date, 8);
    }
    return 0;
}

// FUN_0017d610
u32 FUN_0017d610(u32 index)
{
    u8 date[8];
    u32 doubled;
    u32 result;

    if ((s32)index <= 4) goto valid_index;
    result = 0;
    goto done;
valid_index:
    FUN_003eff00(index, date);
    if (FUN_0017d450(index, date) != 0)
    {
        doubled = index * 2;
        index = (u32)(DAT_00836200 + index * 0x10 + 0x4634);
        memcpy(DAT_00836200 + (doubled + 1) * 8 + 0x4634, (void*)index, 8);
        memcpy((void*)index, date, 8);
        result = 1;
    }
    else
    {
        result = 0;
    }
done:
    return result;
}


// FUN_0017d6d0
void dat0017d6d0(s32 param_1, void *param_2)
{
    FUN_0017d700_y2(param_1, 1, param_2);
}

// FUN_0017d700
void FUN_0017d700(s32 index, s32 slot, void* date)
{
    if (date == NULL) FUN_0019d3f0((u32)D_005e3098, 0x197f);
    memcpy(date, DAT_00836200 + ((index << 1) + slot) * 8 + 0x4634, 8);
}


// FUN_0017d790
void dat0017d790(void)
{
    FUN_003d74b0();
}


// FUN_0017d7b0
u32 FUN_0017d7b0(void)
{
    return U32(0x0083aa98);
}

#pragma optimization_level 1
// FUN_0017d7c0
void FUN_0017d7c0(u32 value)
{
    U32(0x0083aa98) = value;
    if (U32(0x0083aa98) > 99)
        U32(0x0083aa98) = 99;
}


// FUN_0017d7f0
void datSetScenarioMode(u32 scenario)
{
    sScenarioMode = scenario;
}


// FUN_0017d800
u32 datGetScenarioMode()
{
    return sScenarioMode;
}

#pragma optimization_level 2

// FUN_0017d810
u32 FUN_0017d810(void)
{
    return U32(0x0083a6f8);
}

// FUN_0017d820
void FUN_0017d820(u32 value)
{
    U32(0x0083a6f8) = value;
}


/* Camp/data bridge functions at retail 0x001675B0-0x0016C2F0. */


/* Retail globals shared by the Camp bridge state machines. */
/* Retail accesses these flag words by absolute address. */

/* Data bridge globals initialized by FUN_0016C010/FUN_0016C2F0. */

/* Unresolved retail helpers. Old-style declarations preserve the mixed-width
 * call ABI recovered from the stripped executable. */

/* These task archive names are addressed absolutely by retail. */

/* Target entry prototypes keep all callbacks visible before their first use. */



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
