#include "mw_harvest_compat.h"
#include "libm.h"

extern s32 func_0052c000(float x, float y[2]);
extern float func_0052d2d8(float x, float y);
extern float func_0052dc48(float x, float y, s32 iy);
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
#pragma alias FUN_00531170_u64 FUN_00531170
extern u64 FUN_00531170_u64(u64, u64);
#pragma alias FUN_005311c8_u64 FUN_005311c8
extern u64 FUN_005311c8_u64(u64, u64);
#pragma alias FUN_00531230_u64 FUN_00531230
extern u64 FUN_00531230_u64(u64, u64);
#pragma alias FUN_005316d0_u64 FUN_005316d0
extern s64 FUN_005316d0_u64(u64, u64);
#pragma alias FUN_00531720_u64 FUN_00531720
extern u64 FUN_00531720_u64(u32);
#pragma alias FUN_005318a0_f32 FUN_005318a0
extern float FUN_005318a0_f32(u64);
#pragma alias FUN_005318f8_u32 FUN_005318f8
extern u32 FUN_005318f8_u32(u64);
#pragma alias FUN_00530da0_u64 FUN_00530da0
extern u64 FUN_00530da0_u64(u32);
extern u64 FUN_0052efd8(u64, u64, u64 *);
extern u64 FUN_0052f7d0(u64, u64, u64 *);

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
#pragma optimization_level 2

#pragma intrinsic fabsf
// FUN_0052e788 NONMATCHING
#pragma opt_alias on
float fabsf(float x)
{
    union {
        float f;
        u32 i;
    } ux;
    ux.f = x;
    ux.i &= 0x7FFFFFFF;
    return ux.f;
}
#pragma opt_alias reset
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

#pragma optimization_level 3
// FUN_0052e878 NONMATCHING
float sinf(float x)
{
    float y[2];
    s32 n;
    s32 ix;
    s32 threshold = 0x3F490FD8;

    ix = *(s32*)&x;
    ix &= 0x7FFFFFFF;
    if (threshold < ix) goto large_argument;
    return func_0052dc48(x, 0.0f, 0);

large_argument:
    n = func_0052c000(x, y) & 3;
    if (n == 1)
    {
        return func_0052d2d8(y[0], y[1]);
    }
    if (n < 2)
    {
        return func_0052dc48(y[0], y[1], 1);
    }
    if (n == 2)
    {
        return -func_0052dc48(y[0], y[1], 1);
    }
    return -func_0052d2d8(y[0], y[1]);
}
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
#pragma tailcall off
#pragma optimization_level 2
// FUN_0052EA78 NONMATCHING
u64 FUN_0052ea78(long param_1, long param_2)
{
    return param_1 * param_2;
}
#pragma optimization_level 2
#pragma optimization_level 3
// FUN_0052EAC8 NONMATCHING
u64 FUN_0052eac8(s64 u)
{
    u64 high;
    u64 low;

    high = FUN_00531720_u64((u32)(u >> 0x20));
    high = FUN_00531230_u64(high, 0x40F0000000000000ULL);
    high = FUN_00531230_u64(high, 0x40F0000000000000ULL);
    low = FUN_00531720_u64((u32)u);
    if ((s32)u < 0)
        low = FUN_00531170_u64(low, 0x41F0000000000000ULL);
    return FUN_00531170_u64(high, low);
}
#pragma optimization_level 2
// Scoped scheduler: level-2 target is 224B without schedule and 200B with schedule.
#pragma schedule on
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
#pragma optimization_level 2
// FUN_0052ED30 NONMATCHING
long FUN_0052ed30(u64 param_1)
{
    long lVar1;
    u64 uVar2;
    long zero;
    u64 input;

    zero = 0;
    input = param_1;
    lVar1 = FUN_005316d0_u64(input, zero);
    if (-1 < lVar1)
    {
        lVar1 = FUN_0052ec28(input);
        return lVar1;
    }
    uVar2 = FUN_005311c8_u64(zero, input);
    lVar1 = FUN_0052ec28(uVar2);
    return -lVar1;
}
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
