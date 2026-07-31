#include "Main/Battle/Data/datScript.h"
#include "Kosaka/k_assert.h"

#pragma alias DAT_009571a4_y2 DAT_009571a4


#pragma alias datScriptIsCurrent FUN_003112c0
#pragma alias datScriptSetCalculationResult FUN_00311190
#pragma alias datScriptReturnTrueCommand FUN_003111C0
#pragma alias datScriptRestorePartyCommand FUN_003112E0


static ScrData* sUnk_007ce514; // doesn't looks like it's used

// FUN_003112c0
u8 datScriptIsCurrent(ScrData* scr)
{
    return sUnk_007ce514 == scr;
}

extern u16* DAT_00957190[]; // 0x957190

// FUN_003111f0
u32 datScript003111f0(void)
{
    K_ASSERT(DAT_00957190[0] != NULL, 0x205);
    return !(*DAT_00957190[0] & 4);
}

extern u16 DAT_0095719c[]; // 0x95719c
static u8* sUnk_007ce3f8;  // iGpffffb708

// FUN_00311250
u32 datScript00311250(void)
{
    K_ASSERT(DAT_0095719c[0] < 0x1d0, 0x222);
    return (sUnk_007ce3f8[DAT_0095719c[0] * 0x2c] & 2) != 0;
}

/* ---- Straggler recovery: 0x311190-0x3112E0 ---- */
extern u16 DAT_009571a4_y2;
extern u32 DAT_00957198;
extern void FUN_0035f060(u32 value);
extern void FUN_0030c440(void);
/* Removing this loses datScriptSetCalculationResult (MATCH nd0 -> MISMATCH nd16) - measured W161. */
#pragma optimization_level 1
// FUN_00311190
void datScriptSetCalculationResult(u32 param_1)

{
  *(u16*)0x009571a4 = *(u16*)0x009571a4 | 1;
  *(u32*)0x00957198 = param_1;
  return;
}
#pragma optimization_level 2

// FUN_003111C0
u32 datScriptReturnTrueCommand(void)

{
  FUN_0035f060(1);
  return 1;
}

// FUN_003112E0
u32 datScriptRestorePartyCommand(void)

{
  FUN_0030c440();
  return 1;
}


#include "Main/Battle/Data/datCalc.h"
#include "Main/g_data.h"
#include "Graphics/Effect/effMisc.h"
typedef struct DatCalcEnemy
{
    u8 unk_00[4];
    u16 hp;
    u16 sp;
    u8 unk_08[6];
    u16 skills[8];
    u8 unk_1e[0x20];
} DatCalcEnemy;

typedef struct DatCalcEquipmentEffect
{
    u8 unk_00[0x1c];
    u32 skillId;
    u8 unk_20[4];
} DatCalcEquipmentEffect;

typedef struct DatCalcWeapon
{
    u8 unk_00[4];
    u32 category;
    u8 unk_08[0x20];
} DatCalcWeapon;

extern DatCalcEnemy* D_007CE410;
extern u16 func_0016cc00(s16 pcId);
extern DatCalcWeapon* func_00170d60(s16 weaponId);
extern DatCalcEquipmentEffect* func_00170e40(s16 equipmentId);
extern const char D_0069aa80[];
#pragma alias D_0069aa80_abs D_0069aa80
extern u8 D_0069aa80_abs[];
u32 datCalc00308ba0(void);
u16* func_00308bb0(DatUnit* unit);

static u32 sPrevPercentRand; // 007ce510













/* W323 measured: opt_loop_invariants on nd116 -> 93, object 280/288; reset nd116, object 284/288. */







extern f32 sqrtf(f32);
extern u32 FUN_0016c5f0();
extern u32 FUN_0016c670();
extern u32 FUN_0016c920();
extern u32 FUN_0016cb80();
extern u32 FUN_0016ccb0();
extern u32 FUN_0016cf40();
extern u32 FUN_0016cf90();
extern u32 FUN_0016d9d0();
extern u32 FUN_0016f190();
extern u32 FUN_0016f630();
extern u32 FUN_0016f900();
extern u32 FUN_0016f9f0();
#pragma alias FUN_0016f9f0_datcalc FUN_0016f9f0
extern u32 FUN_0016f9f0_datcalc(s16 pcId, s32 equipmentIdx);
extern u32 FUN_0016fae0();
#pragma alias FUN_0016fae0_datcalc FUN_0016fae0
extern u32 FUN_0016fae0_datcalc(s16 pcId, s32 equipmentIdx);
extern u32 FUN_0016fbd0();
extern u32 FUN_0016fcc0();
extern u32 FUN_00170760();
extern u32 FUN_00170d60();
extern u32 FUN_00170e40();
extern u32 FUN_00170e90();
extern u32 FUN_00173380();
extern u32 FUN_00173460();
extern u32 FUN_00173510();
#pragma alias FUN_00173510_u16 FUN_00173510
extern u8 FUN_00173510_u16(u16, u32);
extern u32 FUN_001738d0();
extern u32 FUN_00174960();
extern u32 FUN_00174a90();
extern u32 FUN_001752b0();
extern u32 FUN_00175410();
extern u32 FUN_0017d800();
extern u32 FUN_00181b10();
extern u32 FUN_0019d3f0();
extern u32 FUN_002ffbc0();
extern u32 FUN_002ffcc0();
extern u32 FUN_002ffd70();
extern u32 FUN_002ffdf0();
extern u32 FUN_003004f0();
extern u32 FUN_003004F0();
extern u32 FUN_00300530();
extern u32 FUN_00300550();
extern u32 FUN_00300560();
extern u32 FUN_00300580();
extern u32 FUN_003005E0();
extern u32 FUN_003005e0();
extern u32 FUN_00300870();
extern u32 FUN_003009a0();
extern u32 FUN_003009A0();
extern u32 FUN_00300D80();
extern u32 FUN_00300d80();
extern u32 FUN_00308ba0();
extern u32 FUN_00308BA0();
extern u32 FUN_00308C60();
extern u32 FUN_00308c60();
extern u32 FUN_0030B5A0();
extern u32 FUN_0030b5a0();
extern u32 FUN_0030b5e0();
extern u32 FUN_0030B5E0();
extern u32 FUN_00311190(int);
#pragma alias FUN_00311190_typed FUN_00311190
extern void FUN_00311190_typed(u32);
extern u32 FUN_003111f0();
extern u32 FUN_00311250();
extern void FUN_0035f080(float);
extern u32 FUN_003951d0();
#pragma alias datCalcGetMaxSp FUN_00300100
u32 datCalcGetMaxSp(DatUnit* unit);
s32 FUN_00300410(DatUnit *unit,s32 hpDelta);
s32 FUN_00300480(DatUnit *unit,s32 spDelta);
u32 FUN_003005a0(u16* param);
u8 FUN_00300700(u16 *param_1,s16 param_2);
s32 FUN_00300750(u16 param_1,u16 param_2);
s32 FUN_00300af0(s32 param_1);
u8 FUN_00300b60(u16 *param_1,u32 param_2);
u8 FUN_00300c90(u32 param_1,u32 param_2);
u32 FUN_00300e90(u32 param_1);
s8 FUN_00300f60(int param_1,u32 param_2);
void FUN_00301030(int param_1,u8 param_2,s8 param_3);
void FUN_00301150(int param_1,u8 param_2,s8 param_3);
u8 FUN_00301230(int param_1,u32 param_2,char param_3);
#pragma alias FUN_00301230_narrow FUN_00301230
extern u8 FUN_00301230_narrow(u8 *param_1,u8 param_2,s8 param_3);
void FUN_00301540(int param_1,u32 param_2);
void FUN_00301690(u32 param_1);
s8 FUN_00301750(int param_1,u32 param_2);
void FUN_00301870(int param_1);

float FUN_00301880(u32 param_1,u32 param_2,u32 param_3);
u8 FUN_00301ca0(u32 param_1,u32 param_2);
void FUN_00302380(u32 param_1,u32 param_2,u32 param_3);
void FUN_00302c50(u32 param_1);

void FUN_00302d40(u32 param_1);
u8 FUN_00302f50(u32 param_1);

u32 FUN_00303130(u32 param_1,u32 param_2,u32 param_3,u16 param_4,short param_5,
                 short param_6,u32 param_7,u8 param_8);

u32 FUN_00305970(u32 param_1,u32 param_2,u32 param_3);
u32 FUN_00306020(u32 param_1,u32 param_2,u32 param_3,u16 param_4);
u32 FUN_00306510(u32 param_1,u32 param_2,u32 param_3,u16 param_4);
u32 FUN_00306610(u32 param_1,s32 param_2,s32 param_3,u32 param_4);
u32 FUN_003068d0(u32 param_1,s32 param_2,s32 param_3,u32 param_4);
u32
FUN_00306bc0(u32 param_1,s32 param_2,s32 param_3,u32 param_4,s32 param_5,s32 param_6,
            s32 param_7);
u32 FUN_00306d90(u16 param_1,u32 param_2);
u32 FUN_00306e80(s32 param_1,s32 param_2);
int FUN_003080c0(short param_1);
short FUN_00308120(short param_1,int param_2);
s32 FUN_003082f0(s32 param_1,u32 param_2);
#pragma alias FUN_003082f0_u16 FUN_003082f0
extern s32 FUN_003082f0_u16(s32 param_1,u16 param_2);
#pragma alias FUN_003082f0_one FUN_003082f0
extern s32 FUN_003082f0_one(s32 param_1);
u32 FUN_003083f0(u32 param_1,u32 param_2);
u8 FUN_003086c0(void *param_1,u32 param_2);
u32 FUN_003086f0(u32 param_1,u32 param_2);
u32 FUN_00308860(u16 param_1);
u8 FUN_003088b0(u16 param_1);
u16 FUN_00308930(u16 *param_1);
u8 FUN_00308a50(u16 param_1);
u16 FUN_00308a80(u32 param_1);
int FUN_00308bb0(u16 *param_1);
u16 FUN_00308ed0(u16 *param_1);
u8 FUN_00308f80(u16 *param_1);
u8 FUN_00308fd0(u16 *param_1,u16 param_2);
u32 FUN_00309080(u16 *param_1,u8 param_2);
u32 FUN_00309250(u16 *param_1,u8 param_2);
u8 FUN_003093a0(u16 *param_1);
u32 FUN_00309490(s32 param_1,u32 param_2,u16 param_3,u32 param_4);
u32 FUN_0030a740(s32 param_1,u32 param_2,u32 param_3,short param_4);
u32 FUN_0030af00(s32 param_1,u16 *param_2,u32 param_3,u32 param_4,u32 param_5);
u32
FUN_0030b130(u32 param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5);
u32 FUN_0030b210(u32 param_1,int param_2,u16 param_3,short param_4);
u32 FUN_0030b4b0(u32 param_1,u32 param_2);
u32 FUN_0030b640(s32 param_1,u32 param_2);
u32 FUN_0030b9a0(u16 *param_1,u16 param_2,u16 param_3);
int FUN_0030bb40(u16 param_1);
int FUN_0030bbb0(u8 param_1);
u16 FUN_0030bc20(s16 param_1);

#pragma alias FUN_0030bde0_narrow FUN_0030bde0
extern short FUN_0030bde0_narrow(u16 *param_1,s32 *param_2);
u32 FUN_0030bc50(int param_1);
short FUN_0030bde0(u16 *param_1,s32 param_2);
int FUN_0030c0c0(void);
s32 FUN_0030c220(s32 param_1);
u8 FUN_0030c2a0(u32 param_1);
u32 FUN_0030c3a0(u16 *param_1);
void FUN_0030c490(u16 param_1);
void FUN_0030c520(void);
void FUN_0030c930(void);
void FUN_0030cb90(void);
void FUN_0030cc40(void);
void FUN_0030cdb0(void);
void FUN_0030cec0(void);
void FUN_0030cf00(void);
void FUN_0030d000(void);
void FUN_0030d0e0(void);
void FUN_0030d1c0(void);
void FUN_0030d2a0(void);
void FUN_0030d380(void);
void FUN_0030d460(void);
void FUN_0030d4a0(void);
void FUN_0030d4e0(void);
void FUN_0030d610(void);
void FUN_0030d760(void);
void FUN_0030db80(void);
void FUN_0030ddf0(void);
void FUN_0030dec0(void);
void FUN_0030e030(void);
void FUN_0030e140(void);
void FUN_0030e180(void);
void FUN_0030e280(void);
void FUN_0030e360(void);
void FUN_0030e440(void);
void FUN_0030e520(void);
void FUN_0030e600(void);
void FUN_0030e6e0(void);
void FUN_0030e720(void);
void FUN_0030e760(void);
void FUN_0030e8a0(void);
void FUN_0030ea00(void);
void FUN_0030ee10(void);
void FUN_0030f070(void);
void FUN_0030f120(void);
void FUN_0030f290(void);
void FUN_0030f3a0(void);
void FUN_0030f3e0(void);
void FUN_0030f4e0(void);
void FUN_0030f5c0(void);
void FUN_0030f6a0(void);
void FUN_0030f780(void);
void FUN_0030f860(void);
void FUN_0030f940(void);
void FUN_0030f980(void);
void FUN_0030f9c0(void);
void FUN_0030faf0(void);
u32
FUN_0030fc40(u32 param_1,u32 param_2,u32 param_3,u16 param_4,
            u32 param_5);
u32 FUN_0030fdc0(void);

float FUN_0030fdf0(int param_1,u32 param_2);
extern f32 DAT_007cad74;
extern f32 DAT_007cad8c;
extern f32 DAT_007cadb4;
extern f32 DAT_007cae84;
extern f32 DAT_007caf8c;
extern u32 DAT_007ce3ec;
extern u32 DAT_007ce3f4;
extern u32 DAT_007ce3f8;
extern u32 DAT_007ce3fc;
extern u32 DAT_007ce410;
extern u32 DAT_007ce414;
extern u32 DAT_007ce46c;
extern u32 DAT_007ce470;
extern u32 DAT_007ce478;
extern u32 DAT_007ce47c;
extern u32 DAT_00957194;
extern u32 DAT_009571a0;
#pragma alias DAT_00957190_abs DAT_00957190
extern u8 DAT_00957190_abs[];
#pragma alias DAT_00957194_abs DAT_00957194
extern u8 DAT_00957194_abs[];
#pragma alias DAT_00957198_abs DAT_00957198
extern u8 DAT_00957198_abs[];
#pragma alias DAT_0095719c_abs DAT_0095719c
extern u8 DAT_0095719c_abs[];
#pragma alias DAT_009571a0_abs DAT_009571a0
extern u8 DAT_009571a0_abs[];

extern u32 DAT_009571a4;
#pragma alias DAT_009571a4_abs DAT_009571a4
extern u8 DAT_009571a4_abs[];
extern void (*PTR_LAB_0069aa90[])(void);
extern void (*PTR_LAB_0069aae0[])(void);
extern void (*PTR_LAB_0069ab30[])(void);
extern f32 fGpffff8070;
extern f32 fGpffff8084;
extern f32 fGpffff8088;
extern f32 fGpffff80a4;
extern f32 fGpffff80c4;
extern f32 fGpffff80e0;
extern f32 fGpffff8194;
extern f32 fGpffff8278;
extern f32 fGpffff829c;
extern f32 fGpffff82a0;
extern f32 fGpffff82a4;
extern f32 fGpffff82a8;
extern f32 fGpffff82ac;
extern u32 gp0xffff9d08;
extern u32 iGpffffb704;
extern u32 iGpffffb708;
extern u32 iGpffffb720;
extern u32 iGpffffb790;
extern u32 iGpffffb79c;
extern u32 iGpffffb7a4;
extern u32 iGpffffb7a8;
extern u32 iGpffffb7fc;
extern u32 iGpffffb800;






























































#pragma alias FUN_00301230_narrow FUN_00301230





/* W389 classification: register-colouring floor; baseline nd18/object324/336. Six singles and all 15 knob pairs were neutral; declaration-order swap stayed nd18. */





























/* W323 measured: opt_common_subs off nd1570 -> 1489, object 2252/2256; reset nd1570. */















/* W367 measured: opt_lifetimes on nd6788 -> 6786, object 10264/10304; baseline object 10264/10304. */





#pragma opt_lifetimes reset
/* W367 measured: opt_lifetimes on nd1103 -> 1066, object 1708/1712; baseline object 1712/1712. */





#pragma opt_lifetimes reset
/* W367 measured: opt_lifetimes on nd1919 -> 1916, object 4928/5008; baseline object 4928/5008. */


















































#pragma alias FUN_003083f0_narrow FUN_003083f0



































/* W323 measured: opt_common_subs off nd152 -> 147, object 236/288; reset nd152. */
#pragma opt_common_subs on


















































#pragma alias FUN_0030af00_narrow FUN_0030af00

























/* W323 measured: opt_common_subs off nd166 -> 139, object 392/416; reset nd166. */

























#pragma alias FUN_0030bde0_narrow FUN_0030bde0
/* W323 measured: opt_loop_invariants on nd407 -> 404, object 716/736; reset nd407. */

















































































































































































































































































// FUN_0030fc40
u32
FUN_0030fc40(u32 param_1,u32 param_2,u32 param_3,u16 param_4,
            u32 param_5)

{
  s32 lVar1;
  int iVar2;
  
  *(u16*)DAT_0095719c_abs = param_4;
  *(u32*)DAT_00957190_abs = param_2;
  *(u32*)DAT_00957194_abs = param_3;
  *(u32*)DAT_009571a0_abs = param_5;
  *(u16*)DAT_009571a4_abs &= 0xfffe;
  lVar1 = FUN_0016f190(0x1311);
  iVar2 = (int)param_1;
  if (lVar1 == 1) {
    if (!(param_1 < 0x11)) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x8b);
    }
    PTR_LAB_0069aae0[iVar2]();
  }
  else {
    lVar1 = FUN_0016f190(0x1319);
    if (lVar1 == 1) {
      if (!(param_1 < 0x11)) {
        FUN_0019d3f0((u32)D_0069aa80_abs, 0x90);
      }
      PTR_LAB_0069ab30[iVar2]();
    }
    else {
      if (!(param_1 < 0x11)) {
        FUN_0019d3f0((u32)D_0069aa80_abs, 0x93);
      }
      PTR_LAB_0069aa90[iVar2]();
    }
  }
  if ((*(u16*)DAT_009571a4_abs & 1) == 0) {
    FUN_0019d3f0((u32)D_0069aa80_abs, 0x9b);
  }
  return *(u32*)DAT_00957198_abs;
}





// FUN_0030fdc0
u32 FUN_0030fdc0(void)

{
  FUN_0035f080(0.0f);
  return 1;
}





 
#define DAT_00957190 (*(u32*)DAT_00957190_abs)
#define DAT_00957194 (*(u32*)DAT_00957194_abs)
#define DAT_00957198 (*(s16*)DAT_00957198_abs)
#define DAT_0095719c (*(u16*)DAT_0095719c_abs)
#define DAT_009571a0 (*(u32*)DAT_009571a0_abs)
// FUN_0030fdf0 NONMATCHING

float FUN_0030fdf0(int param_1,u32 param_2)

{
  int iVar1;
  u16 uVar2;
  u16 uVar3;
  u16 uVar4;
  short sVar5;
  u32 uVar6;
  u8 *pbVar7;
  float unaff_f20;
  
  switch(param_1) {
  case 1:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0xbe);
    }
    uVar6 = FUN_002ffcc0(DAT_00957190);
    unaff_f20 = (float)uVar6;
    break;
  case 2:
    if (DAT_00957194 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0xc2);
    }
    uVar6 = FUN_002ffcc0(DAT_00957194);
    unaff_f20 = (float)uVar6;
    break;
  case 3:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0xc6);
    }
    uVar6 = FUN_002ffd70(DAT_00957190);
    unaff_f20 = (float)uVar6;
    break;
  case 4:
    if (DAT_00957194 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0xca);
    }
    uVar6 = FUN_002ffd70(DAT_00957194);
    unaff_f20 = (float)uVar6;
    break;
  case 5:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0xce);
    }
    uVar6 = FUN_002ffdf0(DAT_00957190);
    unaff_f20 = (float)uVar6;
    break;
  case 6:
    if (DAT_00957194 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0xd2);
    }
    uVar6 = FUN_002ffdf0(DAT_00957194);
    unaff_f20 = (float)uVar6;
    break;
  case 7:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0xd6);
    }
    unaff_f20 = (float)*(u16 *)(DAT_00957190 + 10);
    break;
  case 8:
    if (DAT_00957194 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0xda);
    }
    unaff_f20 = (float)*(u16 *)(DAT_00957194 + 10);
    break;
  case 9:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0xde);
    }
    uVar6 = datCalcGetMaxSp((DatUnit*)DAT_00957190);
    unaff_f20 = (float)uVar6;
    break;
  case 10:
    if (DAT_00957194 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0xe2);
    }
    uVar6 = datCalcGetMaxSp((DatUnit*)DAT_00957194);
    unaff_f20 = (float)uVar6;
    break;
  case 0xb:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0xe6);
    }
    uVar2 = FUN_003082f0(DAT_00957190,DAT_0095719c);
    uVar3 = FUN_00306e80(DAT_00957190,(short)uVar2);
    unaff_f20 = (float)uVar3 / 100.0f;
    break;
  case 0xc:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0xec);
    }
    if (DAT_00957194 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0xed);
    }
    uVar2 = FUN_003082f0(DAT_00957190,DAT_0095719c);
    uVar3 = FUN_00306e80(DAT_00957194,(short)uVar2);
    unaff_f20 = (float)uVar3 / 100.0f;
    break;
  case 0xd:
    if (4 < (s32)param_2) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x110);
    }
    if (DAT_00957190 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x111);
    }
    uVar6 = FUN_00300c90(DAT_00957190,param_2 & 0xffff);
    unaff_f20 = (float)uVar6;
    break;
  case 0xe:
    if (4 < (s32)param_2) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x11a);
    }
    if (DAT_00957194 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x11b);
    }
    uVar6 = FUN_00300c90(DAT_00957194,param_2 & 0xffff);
    unaff_f20 = (float)uVar6;
    break;
  case 0xf:
  case 0x10:
    iVar1 = DAT_00957194;
    if (param_1 == 0xf) {
      iVar1 = DAT_00957190;
    }
    sVar5 = FUN_00308120(DAT_0095719c,DAT_009571a0);
    if (!(sVar5 < 0x13)) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0xfc);
    }
    if (((sVar5 == 0x11) || (sVar5 == 0x10)) || (sVar5 == -1)) {
      uVar3 = 100;
    }
    else {
      uVar3 = FUN_00306e80(iVar1,(short)sVar5);
    }
    unaff_f20 = (float)uVar3 / 100.0f;
    break;
  case 0x11:
    if (!(DAT_0095719c < 0x1d0)) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x11f);
    }
    pbVar7 = (u8 *)(DAT_007ce3f8 + ((u32)DAT_0095719c * 10 + (u32)DAT_0095719c) * 4);
    if ((*pbVar7 & 2) != 0) {
      if (DAT_00957190 == 0) {
        FUN_0019d3f0((u32)D_0069aa80_abs, 0x122);
      }
      uVar6 = FUN_00309080((u16*)DAT_00957190,1);
      unaff_f20 = (float)uVar6;
    }
    else {
      unaff_f20 = (float)pbVar7[0xe];
    }
    break;
  case 0x12:
    if (!(DAT_0095719c < 0x1d0)) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x129);
    }
    unaff_f20 = (float)*(u8 *)(((u32)DAT_0095719c * 10 + (u32)DAT_0095719c) * 4 + DAT_007ce3f8 +
                                0x19);
    break;
  case 0x13:
    if (!(DAT_0095719c < 0x1d0)) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x12d);
    }
    pbVar7 = (u8 *)(DAT_007ce3f8 + ((u32)DAT_0095719c * 10 + (u32)DAT_0095719c) * 4);
    if (((*pbVar7 & 2) == 0) && (pbVar7[0x11] != 0x10)) {
      if (DAT_009571a0 == 1) {
        unaff_f20 = (float)(int)*(short *)(pbVar7 + 0x12);
      }
      else if (DAT_009571a0 == 2) {
        unaff_f20 = (float)(int)*(short *)(pbVar7 + 0x16);
      }
      else {
        FUN_0019d3f0((u32)D_0069aa80_abs, 0x13c);
      }
    }
    else {
      if (DAT_00957190 == 0) {
        FUN_0019d3f0((u32)D_0069aa80_abs, 0x131);
      }
      uVar6 = FUN_00309080((u16*)DAT_00957190,0);
      unaff_f20 = (float)uVar6;
    }
    break;
  case 0x14:
    if (!(DAT_0095719c < 0x1d0)) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x141);
    }
    unaff_f20 = (float)*(u8 *)(((u32)DAT_0095719c * 10 + (u32)DAT_0095719c) * 4 + DAT_007ce3f8 +
                                0x25);
    break;
  case 0x15:
    if (!(DAT_0095719c < 0x1d0)) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x145);
    }
    unaff_f20 = (float)*(u8 *)(((u32)DAT_0095719c * 10 + (u32)DAT_0095719c) * 4 + DAT_007ce3f8 +
                                0x26);
    break;
  case 0x16:
    unaff_f20 = 31000.0;
    break;
  case 0x17:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x14c);
    }
    if (DAT_00957194 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x14d);
    }
    uVar3 = FUN_002ffcc0(DAT_00957190);
    uVar4 = FUN_002ffcc0(DAT_00957194);
    sVar5 = (uVar3 & 0xff) - (uVar4 & 0xff);
    if (sVar5 < -0x1f) {
      sVar5 = -0x1f;
    }
    else if (0x1f < sVar5) {
      sVar5 = 0x1f;
    }
    if (DAT_007ce3ec == 0) {
      unaff_f20 = *(float *)(DAT_007ce46c + (short)(sVar5 + 0x5e) * 4);
    }
    else {
      unaff_f20 = *(float *)(DAT_007ce46c + (short)(sVar5 + 0x1f) * 4);
    }
    break;
  case 0x18:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x172);
    }
    if (DAT_00957194 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x173);
    }
    uVar3 = FUN_002ffcc0(DAT_00957190);
    uVar3 = uVar3 & 0xff;
    uVar4 = FUN_002ffcc0(DAT_00957194);
    uVar4 = uVar4 & 0xff;
    if (uVar4 < uVar3) {
      sVar5 = (uVar3 - uVar4) + -1;
    }
    else {
      sVar5 = (uVar3 - uVar4) + 1;
    }
    sVar5 = sVar5 / 3;
    if (sVar5 < -6) {
      sVar5 = -6;
    }
    else if (6 < sVar5) {
      sVar5 = 6;
    }
    unaff_f20 = *(float *)(sVar5 * 4 + DAT_007ce470 + 0x18);
    break;
  case 0x19:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x185);
    }
    uVar3 = FUN_00300c90(DAT_00957190,1);
    uVar3 = (uVar3 & 0xff) / 10;
    if (9 < uVar3) {
      uVar3 = 9;
    }
    unaff_f20 = (float)(int)*(short *)(DAT_007ce478 + (short)uVar3 * 2);
    break;
  case 0x1a:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x18d);
    }
    uVar3 = FUN_00300c90(DAT_00957190,1);
    uVar3 = (uVar3 & 0xff) / 5;
    if (0x14 < uVar3) {
      uVar3 = 0x14;
    }
    unaff_f20 = (float)(int)*(short *)(DAT_007ce47c + (short)uVar3 * 2);
    break;
  case 0x1b:
    unaff_f20 = (float)(*(u16 *)(DAT_007ce3ec + 0xb98) + 1);
    break;
  case 0x1c:
    unaff_f20 = (float)DAT_00957198;
    break;
  case 0x1d:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x19b);
    }
    uVar6 = FUN_00309250((u16*)DAT_00957190,0);
    unaff_f20 = (float)uVar6;
    break;
  case 0x1e:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x19f);
    }
    uVar6 = FUN_00309250((u16*)DAT_00957190,1);
    unaff_f20 = (float)uVar6;
    break;
  case 0x1f:
    if (DAT_00957194 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x1a3);
    }
    uVar6 = FUN_00309250((u16*)DAT_00957194,0);
    unaff_f20 = (float)uVar6;
    break;
  case 0x20:
    if (DAT_00957194 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x1a7);
    }
    uVar6 = FUN_00309250((u16*)DAT_00957194,1);
    unaff_f20 = (float)uVar6;
    break;
  case 0x21:
    if (DAT_00957190 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x1ab);
    }
    if (DAT_00957194 == 0) {
      FUN_0019d3f0((u32)D_0069aa80_abs, 0x1ac);
    }
    uVar3 = FUN_002ffcc0(DAT_00957190);
    uVar4 = FUN_002ffcc0(DAT_00957194);
    sVar5 = (uVar3 & 0xff) - (uVar4 & 0xff);
    if (sVar5 < -0x1f) {
      sVar5 = -0x1f;
    }
    else if (0x1f < sVar5) {
      sVar5 = 0x1f;
    }
    unaff_f20 = *(float *)(sVar5 * 4 + DAT_007ce46c + 0x7c);
    break;
  case 0x22:
    unaff_f20 = (float)*(u16 *)(DAT_007ce3ec + 0xb9e);
    break;
  default:
    FUN_0019d3f0((u32)D_0069aa80_abs,0x1cb);
    break;
  }
  return unaff_f20;
}
#pragma opt_lifetimes reset
#undef DAT_00957190
#undef DAT_00957194
#undef DAT_00957198
#undef DAT_0095719c
#undef DAT_009571a0

// Recovered sibling: FUN_0030fdf0's Ghidra window ran to 0x00311190, but its own
// `jr $ra` is at 0x0031116c followed by four padding nops. A separate 16-byte
// function begins at 0x00311180 (addiu $v0, $zero, 1 / jr $ra / nop / nop) and is
// reached only through a raw pointer stored at ELF file offset 0x6b94b8, never by
// a direct jal, which is why Ghidra never split it out.
// FUN_00311180
u32 FUN_00311180(void)
{
  return 1;
}
