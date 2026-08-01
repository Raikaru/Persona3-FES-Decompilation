#include "mw_harvest_compat.h"
#include "libm.h"
/*
 * See src/lib/sce/libm/sf_tan.c for the measured ee-gcc provenance and
 * wrapper-family floor analysis retained for these vendor libm translation units.
 */

static const float sAtanHi[] = {
    0.463647603989f,
    0.785398125648f,
    0.982793629169f,
    1.5707962513f,
};

static const float sAtanLo[] = {
    5.012158244e-09f,
    3.774894353e-08f,
    3.447321717e-08f,
    7.549789416e-08f,
};

static const float sAtanTerms[] = {
    0.333333343267f,
    -0.199999988079f,
    0.142857134343f,
    -0.111111104488f,
    0.090908870101f,
    -0.076918758452f,
    0.066610723734f,
    -0.058335699141f,
    0.049768779427f,
    -0.0365315712988f,
    0.0162858199328f,
};

#pragma optimization_level 3
// FUN_0052e408 NONMATCHING
float atanf(float x)
{
    s32 id;
    s32 hx;
    s32 ix;
    float w;
    float s1;
    float s2;
    float z;
    float y;
    union {
        float f;
        u32 i;
    } ux;

    ux.f = x;
    hx = ux.i;
    ix = hx & 0x7FFFFFFF;
    y = x;

    if (ix > 0x507FFFFF)
    {
        if (hx > 0)
        {
            return sAtanHi[3];
        }
        return -sAtanHi[3];
    }

    if (ix <= 0x3EDFFFFF)
    {
        if (ix <= 0x30FFFFFF)
        {
            if (1.0e30f + x > 1.0f)
            {
                return x;
            }
        }
        id = -1;
    }
    else
    {
        y = fabsf(y);
        if (ix <= 0x3F2FFFFF)
        {
            id = 0;
            y = ((y + y) - 1.0f) / (2.0f + y);
        }
        else if (ix <= 0x3F97FFFF)
        {
            id = 1;
            y = (y - 1.0f) / (y + 1.0f);
        }
        else if (ix <= 0x401BFFFF)
        {
            id = 2;
            y = (y - 1.5f) / (1.0f + (1.5f * y));
        }
        else
        {
            id = 3;
            y = -1.0f / y;
        }
    }

    z = y * y;
    w = z * z;
    s1 = z * (sAtanTerms[0] + (w * (sAtanTerms[2] + (w * (sAtanTerms[4] +
         (w * (sAtanTerms[6] + (w * (sAtanTerms[8] + (w * sAtanTerms[10]))))))))));
    s2 = w * (sAtanTerms[1] + (w * (sAtanTerms[3] + (w * (sAtanTerms[5] +
         (w * (sAtanTerms[7] + (w * sAtanTerms[9]))))))));

    if (id < 0)
    {
        return y - (y * (s1 + s2));
    }

    z = sAtanHi[id] - ((y * (s1 + s2) - sAtanLo[id]) - y);
    if (hx < 0)
    {
        return -z;
    }
    return z;
}
