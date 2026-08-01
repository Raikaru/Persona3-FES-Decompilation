#include "mw_harvest_compat.h"
/*
 * See src/lib/sce/libm/sf_tan.c for the measured ee-gcc provenance and
 * wrapper-family floor analysis retained for these vendor libm translation units.
 */








#pragma optimization_level 2
// Scoped scheduler: level-2 target is 224B without schedule and 200B with schedule.
#pragma schedule on
/* W415 probe rejected: canonical u64 helper rewrite compiled to nd174
 * with object 228/200, exceeding the retail window; baseline is nd141
 * at 200/200.
 */
// FUN_0052EB60 NONMATCHING
float FUN_0052eb60(s64 u)
{
  f64 f;

  if (!(-((s64)1 << 0x35) < u && u < ((s64)1 << 0x35))) {
    if (((u64)u & 0x7ff) != 0) {
      u |= 0x800;
    }
  }
  f = (s32)(u >> 0x20);
  f *= 65536.0;
  f *= 65536.0;
  f += (u32)u;
  return (float)f;
}
#pragma schedule off
