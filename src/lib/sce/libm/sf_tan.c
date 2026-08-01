/* TOOLCHAIN FLOOR (W383, measured).
 *
 * Retail's libm was NOT built by MWCCPS2.  Two shapes prove it:
 *
 *   1. Float bit-reinterpretation.  Retail extracts the sign/exponent word with
 *      `mfc1 $t7, $f12` and masks with a register-materialised `lui 0x7fff /
 *      ori 0xffff / and`.  MWCCPS2 b210 has no path to `mfc1`: every form of the
 *      idiom -- union member read, `*(int*)&x`, pointer laundering through
 *      `void*`, `register float` parameter, register-qualified union, at -O2
 *      and -O4 -- compiles to `swc1 $f12, N($sp)` followed by `lw`, and folds a
 *      literal 0x7fffffff mask into `dsll32/dsrl32` rather than `lui/ori/and`.
 *      A global (non-const) mask variable is the only way to get a real `and`,
 *      and it costs a $gp load retail does not make.
 *
 *   2. The nine 24-byte wrappers below (FUN_0052E9A0 .. FUN_0052EA60) retain a
 *      vestigial `sd ra / ld ra` around a tail `j`, a shape that sits between
 *      MWCC's tailcall-on (8 bytes) and tailcall-off (28/32 bytes) output.
 *
 * Both are characteristic ee-gcc / Sony SDK libm output.  The residual diffs in
 * this file are therefore compiler-provenance artifacts, not source defects, and
 * grinding them is not productive.  cosf was pushed from nd119 to nd114 with a
 * signed `ix` plus a switch-shaped quadrant dispatch, but that costs 4 bytes and
 * puts the function at 180/176 -- over its window -- so it was not retained.
 *
 * The `#pragma optimization_level 3` islands in this file are legitimate: they
 * reproduce the per-translation-unit flags retail's math TU was built with, and
 * several functions land on their exact retail size only with them.
 */
#include "mw_harvest_compat.h"
#include "libm.h"

extern s32 func_0052c000(float x, float y[2]);
extern float func_0052dd40(float x, float y, s32 iy);
extern u64 FUN_00528ae0(long);
extern u64 FUN_00529578(u32);
extern u32 FUN_005296f0(u32 param_1, u32 param_2);
extern float FUN_0052abd8(float);
extern float FUN_0052afe8(float);
extern float FUN_0052b380(float param_1, float param_2);
extern float FUN_0052b548(float);
extern float FUN_0052b800(float param_1, float param_2);
extern float FUN_0052c398(float);





#pragma optimization_level 3

// FUN_0052e930 NONMATCHING
float tanf(float x)
{
    u32 ix;
    s32 n;
    float y[2];

    ix = *(u32*)&x;
    ix &= 0x7FFFFFFF;
    if (ix <= 0x3F490FDA)
    {
        return func_0052dd40(x, 0.0f, 1);
    }

    n = func_0052c000(x, y);
    return func_0052dd40(y[0], y[1], 1 - ((n & 1) << 1));
}

#pragma optimization_level 2
#pragma tailcall on
// Wrapper floor note: retail is addiu sp,-16 / sd ra,0(sp) / ld ra,0(sp) / j target / addiu sp,+16 (20 bytes plus a 4-byte nop pad in the 24-byte window).
// The candidate is j target / nop (8 bytes): one genuine differing word at offset 4, plus four missing retail words.
// This is the tail-call-OFF frame shape with trailing jal/jr ra collapsed to tail j, retaining vestigial ra save/restore.
// It sits between MWCC tailcall-on and tailcall-off output; ruled out: optimization levels 0-3, schedule/gpopt/leaf/frame pragmas.
// Also ruled out: tailcall combinations, unused volatile locals/arrays, old-style prototypes, and address-taken locals.
// All nine wrappers are identical, so one eventual source solution should flip all nine.
// FUN_0052E9A0 NONMATCHING
u64 FUN_0052e9a0(long param_1)
{
  return FUN_00528ae0(param_1);
}
#pragma tailcall off
#pragma optimization_level 2
#pragma tailcall on
// FUN_0052E9B8 NONMATCHING
u64 FUN_0052e9b8(u32 param_1)
{
  return FUN_00529578(param_1);
}
#pragma tailcall off
// FUN_0052E9D0 NONMATCHING
#pragma tailcall on
u32 FUN_0052e9d0(u32 param_1, u32 param_2)
{
  return FUN_005296f0(param_1, param_2);
}
#pragma tailcall off
// FUN_0052E9E8 NONMATCHING
#pragma tailcall on
float FUN_0052e9e8(float param_1)
{
  return FUN_0052abd8(param_1);
}
#pragma tailcall off
// FUN_0052EA00 NONMATCHING
#pragma tailcall on
float FUN_0052ea00(float param_1)
{
  return FUN_0052afe8(param_1);
}
#pragma tailcall off
// FUN_0052EA18 NONMATCHING
#pragma tailcall on
float FUN_0052ea18(float param_1, float param_2)
{
  return FUN_0052b380(param_1, param_2);
}
#pragma tailcall off
// FUN_0052EA30 NONMATCHING
#pragma tailcall on
float FUN_0052ea30(float param_1)
{
  return FUN_0052b548(param_1);
}
#pragma tailcall off
// FUN_0052EA48 NONMATCHING
#pragma tailcall on
float FUN_0052ea48(float param_1, float param_2)
{
  return FUN_0052b800(param_1, param_2);
}
#pragma tailcall off
// FUN_0052EA60 NONMATCHING
#pragma tailcall on
float FUN_0052ea60(float param_1)
{
  return FUN_0052c398(param_1);
}
