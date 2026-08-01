#include "mw_harvest_compat.h"
#include "libm.h"
/*
 * See src/lib/sce/libm/sf_tan.c for the measured ee-gcc provenance and
 * wrapper-family floor analysis retained for these vendor libm translation units.
 */

extern s32 func_0052c000(float x, float y[2]);
extern float func_0052d2d8(float x, float y);
extern float func_0052dc48(float x, float y, s32 iy);




#pragma optimization_level 3
// FUN_0052e6d8 NONMATCHING
float cosf(float x)
{
    u32 ix;
    s32 n;
    float y[2];
    ix = *(u32*)&x & 0x7FFFFFFF;
    if (ix <= 0x3F490FD8)
        return func_0052d2d8(x, 0.0f);
    n = func_0052c000(x, y);
    n &= 3;
    if (n == 0) return func_0052d2d8(y[0], y[1]);
    if (n == 1) return -func_0052dc48(y[0], y[1], 1);
    if (n == 2) return -func_0052d2d8(y[0], y[1]);
    return func_0052dc48(y[0], y[1], 1);
}
