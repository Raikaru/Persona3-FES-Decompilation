#include "mw_harvest_compat.h"
/*
 * See src/lib/sce/libm/sf_tan.c for the measured ee-gcc provenance and
 * wrapper-family floor analysis retained for these vendor libm translation units.
 */

extern u64 FUN_0052eac8(s64 u);
#pragma alias FUN_00531170_u64 FUN_00531170
extern u64 FUN_00531170_u64(u64, u64);
#pragma alias FUN_005311c8_u64 FUN_005311c8
extern u64 FUN_005311c8_u64(u64, u64);
#pragma alias FUN_00531230_u64 FUN_00531230
extern u64 FUN_00531230_u64(u64, u64);
#pragma alias FUN_005316d0_u64 FUN_005316d0
extern s64 FUN_005316d0_u64(u64, u64);
#pragma alias FUN_005318f8_u32 FUN_005318f8
extern u32 FUN_005318f8_u32(u64);







#pragma optimization_level 2
// FUN_0052EC28 NONMATCHING
long FUN_0052ec28(u64 param_1)

{
  long lVar1;
  u64 uVar2;
  u32 uVar3;
  long lVar4;
  
  lVar1 = FUN_005316d0_u64(param_1,0);
  lVar4 = 0;
  if (-1 < lVar1) {
    uVar2 = FUN_00531230_u64(param_1,0x3df0000000000000);
    uVar3 = FUN_005318f8_u32(uVar2);
    lVar4 = uVar3 << 0x20;
    if (lVar4 < 0) {
      uVar2 = FUN_00531170_u64(uVar2,uVar2);
    }
    else {
      uVar2 = FUN_0052eac8(lVar4);
    }
    uVar2 = FUN_005311c8_u64(param_1,uVar2);
    lVar1 = FUN_005316d0_u64(uVar2,0);
    if (lVar1 < 0) {
      uVar2 = FUN_005311c8_u64(0,0);
      uVar3 = FUN_005318f8_u32(uVar2);
      uVar3 = -(uVar3 & 0xffffffff);
    }
    else {
      uVar3 = FUN_005318f8_u32(uVar2);
      uVar3 = uVar3 & 0xffffffff;
    }
    lVar4 = lVar4 + uVar3;
  }
  return lVar4;
}
