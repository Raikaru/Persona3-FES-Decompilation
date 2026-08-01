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
#pragma alias FUN_00530da0_u64 FUN_00530da0
extern u64 FUN_00530da0_u64(u32);






// FUN_0052EDA0 NONMATCHING
#pragma optimization_level 3
long FUN_0052eda0(void)

{
  u64 uVar1;
  long lVar2;
  u64 uVar3;
  u32 uVar4;
  long lVar5;
  
  uVar1 = FUN_00530da0_u64(0);
  lVar2 = FUN_005316d0_u64(uVar1,0);
  lVar5 = 0;
  if (-1 < lVar2) {
    uVar3 = FUN_00531230_u64(uVar1,0x3df0000000000000);
    uVar4 = FUN_005318f8_u32(uVar3);
    lVar5 = uVar4 << 0x20;
    if (lVar5 < 0) {
      uVar3 = FUN_00531170_u64(uVar3,uVar3);
    }
    else {
      uVar3 = FUN_0052eac8(lVar5);
    }
    uVar1 = FUN_005311c8_u64(uVar1,uVar3);
    lVar2 = FUN_005316d0_u64(uVar1,0);
    if (lVar2 < 0) {
      uVar1 = FUN_005311c8_u64(0,0);
      uVar4 = FUN_005318f8_u32(uVar1);
      uVar4 = -(uVar4 & 0xffffffff);
    }
    else {
      uVar4 = FUN_005318f8_u32(uVar1);
      uVar4 = uVar4 & 0xffffffff;
    }
    lVar5 = lVar5 + uVar4;
  }
  return lVar5;
}
