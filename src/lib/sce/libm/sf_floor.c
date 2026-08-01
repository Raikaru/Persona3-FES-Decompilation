#include "mw_harvest_compat.h"
#include "libm.h"
/*
 * See src/lib/sce/libm/sf_tan.c for the measured ee-gcc provenance and
 * wrapper-family floor analysis retained for these vendor libm translation units.
 */




#pragma optimization_level 2

#pragma optimization_level 3
// FUN_0052e7a0 NONMATCHING
float floorf(register float x)
{
    s32 exponent;
    u32 bits;
    u32 fractionMask;
    union {
        float f;
        u32 i;
    } ux;

    ux.f = x;
    bits = ux.i;
    exponent = ((bits & 0x7FFFFFFF) >> 23) - 127;
    if (exponent < 23)
    {
        if (exponent < 0)
        {
            if (x + 1.0e30f > 0.0f)
            {
                if ((s32)bits >= 0)
                {
                    bits = 0;
                }
                else if ((bits & 0x7FFFFFFF) != 0)
                {
                    bits = 0xBF800000;
                }
            }
        }
        else
        {
            fractionMask = 0x007FFFFF >> exponent;
            if ((bits & fractionMask) == 0)
            {
                return x;
            }
            if (x + 1.0e30f > 0.0f)
            {
                if ((s32)bits < 0)
                {
                    bits += 0x00800000 >> exponent;
                }
                bits &= ~fractionMask;
            }
        }
    }
    ux.i = bits;
    return ux.f;
}
