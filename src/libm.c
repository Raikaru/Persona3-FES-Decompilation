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
#pragma alias FUN_005318a0_void FUN_005318a0
extern void FUN_005318a0_void(u64);
#pragma alias FUN_005318f8_u32 FUN_005318f8
extern u32 FUN_005318f8_u32(u64);
#pragma alias FUN_00530da0_u64 FUN_00530da0
extern u64 FUN_00530da0_u64(u32);
extern u64 FUN_0052efd8(u64, u64, u64 *);
extern u32 FUN_0052f7d0(long, long, long);

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

    ix = *(u32*)&x;
    ix &= 0x7FFFFFFF;
    if (ix <= 0x3F490FD8)
    {
        return func_0052d2d8(x, 0.0f);
    }

    n = func_0052c000(x, y);
    switch (n & 3)
    {
    case 0:
        return func_0052d2d8(y[0], y[1]);
    case 1:
        return -func_0052dc48(y[0], y[1], 1);
    case 2:
        return -func_0052d2d8(y[0], y[1]);
    default:
        return func_0052dc48(y[0], y[1], 1);
    }
}
#pragma optimization_level 2

#pragma optimization_level 3
// FUN_0052e788 NONMATCHING
float fabsf(register float x)
{
    union {
        float f;
        u32 i;
    } ux;

    ux.f = x;
    ux.i &= 0x7FFFFFFF;
    return ux.f;
}
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
u64 FUN_0052eac8(u64 param_1)
{
  u64 uVar1;
  u64 uVar2;

  uVar1 = FUN_00531720_u64(param_1 >> 0x20);
  uVar1 = FUN_00531230_u64(uVar1,0x40f0000000000000);
  uVar1 = FUN_00531230_u64(uVar1,0x40f0000000000000);
  uVar2 = FUN_00531720_u64((int)param_1);
  if ((int)param_1 < 0) {
    uVar2 = FUN_00531170_u64(uVar2,0x41f0000000000000);
  }
  FUN_00531170_u64(uVar1,uVar2);
  return (u64)(uVar1 | uVar2);
}
#pragma optimization_level 2
// FUN_0052EB60 NONMATCHING
void FUN_0052eb60(u32 param_1)

{
  u64 uVar1;
  u64 uVar2;
  
  if ((0x3ffffffffffffe < param_1 + 0x1fffffffffffff) && ((param_1 & 0x7ff) != 0)) {
    param_1 = param_1 | 0x800;
  }
  uVar1 = FUN_00531720_u64((long)param_1 >> 0x20);
  uVar1 = FUN_00531230_u64(uVar1,0x40f0000000000000);
  uVar1 = FUN_00531230_u64(uVar1,0x40f0000000000000);
  uVar2 = FUN_00531720_u64((int)param_1);
  if ((int)param_1 < 0) {
    uVar2 = FUN_00531170_u64(uVar2,0x41f0000000000000);
  }
  uVar1 = FUN_00531170_u64(uVar1,uVar2);
  FUN_005318a0_void(uVar1);
  return;
}
#pragma optimization_level 3
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
      uVar2 = FUN_0052eac8((uVar3 & 0xffffffff) << 0x1f);
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
      uVar3 = FUN_0052eac8((uVar4 & 0xffffffff) << 0x1f);
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
#pragma optimization_level 2
#pragma optimization_level 2
#pragma optimization_level 3
// FUN_0052EEB0 NONMATCHING
u64 FUN_0052eeb0(long param_1,long param_2)

{
  u64 uVar1;
  u32 uVar2;
  
  if (param_1 >> 0x20 < 0) {
    uVar2 = 0xffffffff;
    param_1 = CONCAT44(-(u32)(-(int)param_1 != 0) - (int)((u32)param_1 >> 0x20),-(int)param_1);
  }
  if (param_2 >> 0x20 < 0) {
    uVar2 = ~uVar2;
    param_2 = CONCAT44(-(u32)(-(int)param_2 != 0) - (int)((u32)param_2 >> 0x20),-(int)param_2);
  }
  uVar1 = FUN_0052efd8(param_1,param_2,0);
  if (uVar2 != 0) {
    uVar1 = CONCAT44(-(u32)(-(int)uVar1 != 0) - (int)((u32)uVar1 >> 0x20),-(int)uVar1);
  }
  return uVar1;
}
#pragma optimization_level 3
#pragma optimization_level 2
// FUN_0052EFD8 NONMATCHING
u64 FUN_0052efd8(u64 n, u64 d, u64 *rp)
{
  u32 d0;
  u32 d1;
  u32 n0;
  u32 n1;
  u32 n2;
  u32 q0;
  u32 q1;
  u32 b;
  u32 bm;
  u32 m0;
  u32 m1;
  u64 product;
  union {
    u64 ll;
    struct {
      u32 low;
      u32 high;
    } s;
  } nn;
  union {
    u64 ll;
    struct {
      u32 low;
      u32 high;
    } s;
  } dd;
  union {
    u64 ll;
    struct {
      u32 low;
      u32 high;
    } s;
  } rr;
  union {
    u64 ll;
    struct {
      u32 low;
      u32 high;
    } s;
  } ww;

#define CLZ32(c, x) \
  do { \
    u32 clz_index; \
    if ((x) < 0x10000) { \
      clz_index = 8; \
      if ((x) < 0x100) { \
        clz_index = 0; \
      } \
    } else { \
      clz_index = 0x10; \
      if (0xffffff < (x)) { \
        clz_index = 0x18; \
      } \
    } \
    (c) = 0x20 - ((u32)(u8)(&DAT_007c0388)[(x) >> clz_index] + clz_index); \
  } while (0)

#define UDIV_QRNND(q, r, nh, nl, dv) \
  do { \
    u32 udiv_d1; \
    u32 udiv_d0; \
    u32 udiv_q1; \
    u32 udiv_q0; \
    u32 udiv_r1; \
    u32 udiv_r0; \
    u32 udiv_m; \
    udiv_d1 = (dv) >> 0x10; \
    udiv_d0 = (dv) & 0xffff; \
    udiv_r1 = (nh) % udiv_d1; \
    udiv_q1 = (nh) / udiv_d1; \
    udiv_m = udiv_q1 * udiv_d0; \
    udiv_r1 = (udiv_r1 << 0x10) | ((nl) >> 0x10); \
    if (udiv_r1 < udiv_m) { \
      udiv_q1--; \
      udiv_r1 += (dv); \
      if (udiv_r1 >= (dv)) { \
        if (udiv_r1 < udiv_m) { \
          udiv_q1--; \
          udiv_r1 += (dv); \
        } \
      } \
    } \
    udiv_r1 -= udiv_m; \
    udiv_r0 = udiv_r1 % udiv_d1; \
    udiv_q0 = udiv_r1 / udiv_d1; \
    udiv_m = udiv_q0 * udiv_d0; \
    udiv_r0 = (udiv_r0 << 0x10) | ((nl) & 0xffff); \
    if (udiv_r0 < udiv_m) { \
      udiv_q0--; \
      udiv_r0 += (dv); \
      if (udiv_r0 >= (dv)) { \
        if (udiv_r0 < udiv_m) { \
          udiv_q0--; \
          udiv_r0 += (dv); \
        } \
      } \
    } \
    udiv_r0 -= udiv_m; \
    (q) = (udiv_q1 << 0x10) | udiv_q0; \
    (r) = udiv_r0; \
  } while (0)

  nn.ll = n;
  dd.ll = d;
  d0 = dd.s.low;
  d1 = dd.s.high;
  n0 = nn.s.low;
  n1 = nn.s.high;

  if (d1 == 0) {
    if (d0 > n1) {
      CLZ32(bm, d0);
      if (bm != 0) {
        d0 = d0 << (bm & 0x1f);
        n1 = (n1 << (bm & 0x1f)) | (n0 >> ((0x20 - bm) & 0x1f));
        n0 = n0 << (bm & 0x1f);
      }
      UDIV_QRNND(q0, n0, n1, n0, d0);
      q1 = 0;
      if (rp != 0) {
        rr.s.low = n0 >> (bm & 0x1f);
        rr.s.high = 0;
        *rp = rr.ll;
      }
    } else {
      if (d0 == 0) {
        d0 = 1 / d0;
      }
      CLZ32(bm, d0);
      if (bm == 0) {
        n1 -= d0;
        q1 = 1;
      } else {
        b = 0x20 - bm;
        d0 = d0 << (bm & 0x1f);
        n2 = n1 >> (b & 0x1f);
        n1 = (n1 << (bm & 0x1f)) | (n0 >> (b & 0x1f));
        n0 = n0 << (bm & 0x1f);
        UDIV_QRNND(q1, n1, n2, n1, d0);
      }
      UDIV_QRNND(q0, n0, n1, n0, d0);
      if (rp != 0) {
        rr.s.low = n0 >> (bm & 0x1f);
        rr.s.high = 0;
        *rp = rr.ll;
      }
    }
  } else if (d1 > n1) {
    q0 = 0;
    q1 = 0;
    if (rp != 0) {
      rr.s.low = n0;
      rr.s.high = n1;
      *rp = rr.ll;
    }
  } else {
    CLZ32(bm, d1);
    if (bm == 0) {
      if ((n1 > d1) || (n0 >= d0)) {
        q0 = 1;
        {
          u32 old_n0 = n0;
          n0 -= d0;
          n1 -= d1 + (u32)(n0 > old_n0);
        }
      } else {
        q0 = 0;
      }
      q1 = 0;
      if (rp != 0) {
        rr.s.low = n0;
        rr.s.high = n1;
        *rp = rr.ll;
      }
    } else {
      b = 0x20 - bm;
      d1 = (d1 << (bm & 0x1f)) | (d0 >> (b & 0x1f));
      d0 = d0 << (bm & 0x1f);
      n2 = n1 >> (b & 0x1f);
      n1 = (n1 << (bm & 0x1f)) | (n0 >> (b & 0x1f));
      n0 = n0 << (bm & 0x1f);
      UDIV_QRNND(q0, n1, n2, n1, d1);
      product = (u64)q0 * d0;
      m1 = (u32)(product >> 0x20);
      m0 = (u32)product;
      if ((m1 > n1) || ((m1 == n1) && (m0 > n0))) {
        q0--;
        {
          u32 old_n0 = m0;
          m0 = n0 - m0;
          m1 = n1 - m1 - (u32)(n0 < old_n0);
        }
      }
      q1 = 0;
      if (rp != 0) {
        {
          u32 old_n0 = n0;
          n0 -= m0;
          n1 -= m1 + (u32)(n0 > old_n0);
        }
        rr.s.low = (n1 << (b & 0x1f)) | (n0 >> (bm & 0x1f));
        rr.s.high = n1 >> (bm & 0x1f);
        *rp = rr.ll;
      }
    }
  }

  ww.s.low = q0;
  ww.s.high = q1;
  return ww.ll;
}
#pragma optimization_level 2
// Reconstructed signed remainder wrapper; retail keeps a longer scheduled
// 64-bit negate path that MWCCPS2 does not reproduce from equivalent C.
// FUN_0052F6A0 NONMATCHING
u64 FUN_0052f6a0(long param_1,long param_2)
{
  int iVar1;
  u64 auStack_30[2];
  u64 uVar2;

  iVar1 = 0;
  if (param_1 >> 0x20 < 0) {
    iVar1 = -1;
    param_1 = CONCAT44(-(u32)(-(int)param_1 != 0) - (int)((u32)param_1 >> 0x20),-(int)param_1);
  }
  if (param_2 >> 0x20 < 0) {
    param_2 = CONCAT44(-(u32)(-(int)param_2 != 0) - (int)((u32)param_2 >> 0x20),-(int)param_2);
  }
  FUN_0052f7d0(param_1,param_2,(long)auStack_30);
  uVar2 = auStack_30[0];
  if (iVar1 != 0) {
    uVar2 =
         CONCAT44(-(u32)(-(int)uVar2 != 0) - (int)((u32)uVar2 >> 0x20),
                  -(int)uVar2);
  }
  return uVar2;
}
// FUN_0052F7D0 NONMATCHING
u32 FUN_0052f7d0(long param_1,long param_2,long param_3)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  int iVar10;
  u32 uVar11;
  u32 uVar12;
  int iVar13;
  u32 uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  u32 uVar18;
  u32 uVar19;
  u32 uVar20;
  
  uVar6 = param_2 >> 0x20;
  uVar2 = (u32)param_2;
  uVar18 = (u32)param_1;
  uVar7 = param_1 >> 0x20;
  uVar3 = (u32)(int)uVar2;
  uVar19 = (u32)(int)uVar18;
  uVar8 = (u32)((u32)param_1 >> 0x20);
  uVar20 = (u32)((u32)param_2 >> 0x20);
  if (uVar6 == 0) {
    if (uVar7 < uVar3) {
      if (uVar3 < 0x10000) {
        iVar13 = 8;
        if (uVar3 < 0x100) {
          iVar13 = 0;
        }
      }
      else {
        iVar13 = 0x10;
        if (0xffffff < uVar3) {
          iVar13 = 0x18;
        }
      }
      uVar20 = 0x20 - ((u32)(u8)(&DAT_007c0388)[uVar2 >> iVar13] + iVar13);
      if (uVar20 != 0) {
        uVar3 = (u32)(int)(uVar2 << (uVar20 & 0x1f));
        uVar7 = (u32)(int)(uVar8 << (uVar20 & 0x1f) | uVar18 >> (0x20 - uVar20 & 0x1f));
        uVar19 = (u32)(int)(uVar18 << (uVar20 & 0x1f));
      }
      uVar2 = (u32)uVar3;
      uVar8 = uVar2 >> 0x10;
      iVar13 = (int)uVar7 / (int)uVar8;
      if (uVar8 == 0) {
        trap(7);
      }
      iVar15 = iVar13 * (uVar2 & 0xffff);
      uVar18 = (int)uVar7 % (int)uVar8 << 0x10 | (u32)uVar19 >> 0x10;
      if ((u32)(long)(int)uVar18 < (u32)(long)iVar15) {
        iVar16 = uVar18 + uVar2;
        iVar10 = iVar13 + -1;
        if (uVar3 <= (u32)(long)iVar16) {
          if ((u32)(long)iVar15 <= (u32)(long)iVar16) {
            iVar15 = iVar16 - iVar15;
            goto LAB_0052f8c8;
          }
          iVar10 = iVar13 + -2;
          iVar16 = iVar16 + uVar2;
        }
        iVar15 = iVar16 - iVar15;
      }
      else {
        iVar15 = uVar18 - iVar15;
        iVar10 = iVar13;
      }
LAB_0052f8c8:
      uVar18 = iVar15 / (int)uVar8;
      if (uVar8 == 0) {
        trap(7);
      }
      iVar13 = uVar18 * (uVar2 & 0xffff);
      uVar6 = (long)(iVar15 % (int)uVar8 << 0x10) | uVar19 & 0xffff;
      uVar9 = uVar18;
      if (uVar6 < (u32)(long)iVar13) {
        iVar15 = (int)uVar6 + uVar2;
        uVar6 = (u32)iVar15;
        uVar9 = uVar18 - 1;
        if ((uVar3 <= uVar6) && (uVar6 < (u32)(long)iVar13)) {
          uVar6 = (u32)(int)(iVar15 + uVar2);
          uVar9 = uVar18 - 2;
        }
      }
      uVar2 = (int)uVar6 - iVar13;
      uVar9 = iVar10 << 0x10 | uVar9;
      uVar6 = 0;
    }
    else {
      if (uVar3 == 0) {
        uVar3 = (u32)(1 / (int)uVar20);
        trap(7);
      }
      if (uVar3 < 0x10000) {
        iVar13 = 8;
        if (uVar3 < 0x100) {
          iVar13 = 0;
        }
      }
      else {
        iVar13 = 0x10;
        if (0xffffff < uVar3) {
          iVar13 = 0x18;
        }
      }
      uVar2 = (u32)uVar3;
      uVar20 = 0x20 - ((u32)(u8)(&DAT_007c0388)[uVar2 >> iVar13] + iVar13);
      if (uVar20 == 0) {
        iVar16 = uVar8 - uVar2;
        uVar6 = 1;
        uVar5 = uVar2 >> 0x10;
        uVar2 = uVar2 & 0xffff;
      }
      else {
        uVar9 = uVar2 << (uVar20 & 0x1f);
        uVar3 = (u32)(int)uVar9;
        uVar5 = uVar9 >> 0x10;
        uVar11 = uVar8 >> (0x20 - uVar20 & 0x1f);
        iVar13 = (int)uVar11 / (int)uVar5;
        uVar2 = uVar9 & 0xffff;
        uVar8 = uVar8 << (uVar20 & 0x1f) | uVar18 >> (0x20 - uVar20 & 0x1f);
        uVar19 = (u32)(int)(uVar18 << (uVar20 & 0x1f));
        if (uVar5 == 0) {
          trap(7);
        }
        iVar15 = iVar13 * uVar2;
        uVar18 = (int)uVar11 % (int)uVar5 << 0x10 | uVar8 >> 0x10;
        iVar10 = iVar13;
        if ((u32)(long)(int)uVar18 < (u32)(long)iVar15) {
          uVar18 = uVar18 + uVar9;
          iVar10 = iVar13 + -1;
          if ((u32)(long)(int)uVar18 < uVar3) goto LAB_0052fb70;
          if ((u32)(long)(int)uVar18 < (u32)(long)iVar15) {
            iVar10 = iVar13 + -2;
            uVar18 = uVar18 + uVar9;
            goto LAB_0052fb70;
          }
          iVar15 = uVar18 - iVar15;
        }
        else {
LAB_0052fb70:
          iVar15 = uVar18 - iVar15;
        }
        iVar13 = iVar15 / (int)uVar5;
        uVar7 = (u32)iVar13;
        if (uVar5 == 0) {
          trap(7);
        }
        iVar16 = iVar13 * uVar2;
        uVar14 = (long)(iVar15 % (int)uVar5 << 0x10) | (long)(int)uVar8 & 0xffffU;
        uVar6 = (u32)(iVar10 << 0x10);
        if (uVar14 < (u32)(long)iVar16) {
          iVar15 = (int)uVar14 + uVar9;
          uVar14 = (u32)iVar15;
          uVar7 = (u32)(iVar13 + -1);
          if (uVar3 <= uVar14) {
            uVar6 = (u32)(iVar10 << 0x10);
            if ((u32)(long)iVar16 <= uVar14) goto LAB_0052fbd0;
            uVar7 = (u32)(iVar13 + -2);
            uVar14 = (u32)(int)(iVar15 + uVar9);
          }
          uVar6 = (u32)(iVar10 << 0x10);
        }
LAB_0052fbd0:
        iVar16 = (int)uVar14 - iVar16;
        uVar6 = uVar6 | uVar7;
      }
      iVar13 = iVar16 / (int)uVar5;
      if (uVar5 == 0) {
        trap(7);
      }
      iVar15 = iVar13 * uVar2;
      uVar8 = iVar16 % (int)uVar5 << 0x10 | (u32)uVar19 >> 0x10;
      iVar10 = (int)uVar3;
      if ((u32)(long)(int)uVar8 < (u32)(long)iVar15) {
        iVar17 = uVar8 + iVar10;
        iVar16 = iVar13 + -1;
        if (uVar3 <= (u32)(long)iVar17) {
          if ((u32)(long)iVar15 <= (u32)(long)iVar17) {
            iVar15 = iVar17 - iVar15;
            goto LAB_0052fa8c;
          }
          iVar16 = iVar13 + -2;
          iVar17 = iVar17 + iVar10;
        }
        iVar15 = iVar17 - iVar15;
      }
      else {
        iVar15 = uVar8 - iVar15;
        iVar16 = iVar13;
      }
LAB_0052fa8c:
      uVar8 = iVar15 / (int)uVar5;
      if (uVar5 == 0) {
        trap(7);
      }
      iVar13 = uVar8 * uVar2;
      uVar7 = (long)(iVar15 % (int)uVar5 << 0x10) | uVar19 & 0xffff;
      uVar9 = uVar8;
      if (uVar7 < (u32)(long)iVar13) {
        iVar15 = (int)uVar7 + iVar10;
        uVar7 = (u32)iVar15;
        uVar9 = uVar8 - 1;
        if ((uVar3 <= uVar7) && (uVar7 < (u32)(long)iVar13)) {
          uVar7 = (u32)(iVar15 + iVar10);
          uVar9 = uVar8 - 2;
        }
      }
      uVar2 = (int)uVar7 - iVar13;
      uVar9 = iVar16 << 0x10 | uVar9;
    }
    if (param_3 == 0) goto LAB_0052f95c;
    uVar3 = (u32)(uVar2 >> (uVar20 & 0x1f));
  }
  else {
    uVar9 = 0;
    uVar14 = uVar19;
    if (uVar6 <= uVar7) {
      if (uVar6 < 0x10000) {
        iVar13 = 8;
        if (uVar6 < 0x100) {
          iVar13 = 0;
        }
      }
      else {
        iVar13 = 0x10;
        if (0xffffff < uVar6) {
          iVar13 = 0x18;
        }
      }
      uVar11 = 0x20 - ((u32)(u8)(&DAT_007c0388)[uVar20 >> iVar13] + iVar13);
      uVar5 = 0x20 - uVar11;
      if (uVar11 != 0) {
        uVar12 = uVar8 >> (uVar5 & 0x1f);
        uVar20 = uVar20 << (uVar11 & 0x1f) | uVar2 >> (uVar5 & 0x1f);
        uVar9 = uVar20 >> 0x10;
        iVar13 = (int)uVar12 / (int)uVar9;
        uVar8 = uVar8 << (uVar11 & 0x1f) | uVar18 >> (uVar5 & 0x1f);
        uVar2 = uVar2 << (uVar11 & 0x1f);
        uVar18 = uVar18 << (uVar11 & 0x1f);
        if (uVar9 == 0) {
          trap(7);
        }
        uVar1 = iVar13 * (uVar20 & 0xffff);
        uVar12 = (int)uVar12 % (int)uVar9 << 0x10 | uVar8 >> 0x10;
        if (uVar12 < uVar1) {
          uVar12 = uVar12 + uVar20;
          iVar15 = iVar13 + -1;
          if (uVar20 <= uVar12) {
            if (uVar1 <= uVar12) {
              iVar10 = uVar12 - uVar1;
              goto LAB_0052fd40;
            }
            iVar15 = iVar13 + -2;
            uVar12 = uVar12 + uVar20;
          }
          iVar10 = uVar12 - uVar1;
        }
        else {
          iVar10 = uVar12 - uVar1;
          iVar15 = iVar13;
        }
LAB_0052fd40:
        uVar12 = iVar10 / (int)uVar9;
        if (uVar9 == 0) {
          trap(7);
        }
        uVar1 = uVar12 * (uVar20 & 0xffff);
        uVar4 = iVar10 % (int)uVar9 << 0x10 | uVar8 & 0xffff;
        uVar8 = uVar12;
        if (uVar4 < uVar1) {
          uVar4 = uVar4 + uVar20;
          uVar8 = uVar12 - 1;
          if ((uVar20 <= uVar4) && (uVar4 < uVar1)) {
            uVar8 = uVar12 - 2;
            uVar4 = uVar4 + uVar20;
          }
        }
        uVar9 = iVar15 << 0x10 | uVar8;
        uVar4 = uVar4 - uVar1;
        uVar12 = (uVar8 & 0xffff) * (uVar2 & 0xffff);
        uVar1 = (uVar9 >> 0x10) * (uVar2 & 0xffff);
        uVar8 = (uVar8 & 0xffff) * (uVar2 >> 0x10) + (uVar12 >> 0x10) + uVar1;
        iVar13 = (uVar9 >> 0x10) * (uVar2 >> 0x10);
        if (uVar8 < uVar1) {
          iVar13 = iVar13 + 0x10000;
        }
        uVar1 = iVar13 + (uVar8 >> 0x10);
        uVar8 = uVar8 * 0x10000 + (uVar12 & 0xffff);
        if ((uVar4 < uVar1) || ((uVar12 = uVar8, uVar1 == uVar4 && (uVar18 < uVar8)))) {
          uVar12 = uVar8 - uVar2;
          uVar9 = uVar9 - 1;
          uVar1 = (uVar1 - uVar20) - (u32)(uVar8 < uVar12);
        }
        uVar6 = 0;
        if (param_3 == 0) goto LAB_0052f95c;
        uVar2 = (uVar4 - uVar1) - (u32)(uVar18 < uVar18 - uVar12);
        uVar3 = CONCAT44(uVar2 >> (uVar11 & 0x1f),
                         uVar2 << (uVar5 & 0x1f) | uVar18 - uVar12 >> (uVar11 & 0x1f));
        goto LAB_0052f958;
      }
      if ((uVar6 < uVar7) || (uVar9 = 0, uVar3 <= uVar19)) {
        uVar14 = (u32)(int)(uVar18 - uVar2);
        uVar9 = 1;
        uVar7 = (u32)(int)((uVar8 - uVar20) - (u32)(uVar19 < uVar14));
      }
    }
    uVar6 = 0;
    if (param_3 == 0) goto LAB_0052f95c;
    uVar3 = uVar14 & 0xffffffff | uVar7 << 0x20;
  }
LAB_0052f958:
  *(u32 *)param_3 = uVar3;
LAB_0052f95c:
  return (u32)uVar9 | uVar6 << 0x20;
}
// FUN_0052FE98 NONMATCHING
u32 FUN_0052fe98(long param_1,long param_2)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  int iVar7;
  u32 uVar8;
  u32 uVar9;
  u32 uVar10;
  int iVar11;
  u32 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  u32 uVar16;
  u32 uVar17;
  u32 uVar18;
  u32 uVar19;
  
  uVar4 = param_2 >> 0x20;
  uVar1 = (u32)param_2;
  uVar17 = (u32)param_1;
  uVar5 = param_1 >> 0x20;
  uVar2 = (u32)(int)uVar1;
  uVar18 = (u32)(int)uVar17;
  uVar10 = (u32)((u32)param_1 >> 0x20);
  uVar19 = (u32)((u32)param_2 >> 0x20);
  if (uVar4 != 0) {
    uVar6 = 0;
    if (uVar4 <= uVar5) {
      if (uVar4 < 0x10000) {
        iVar11 = 8;
        if (uVar4 < 0x100) {
          iVar11 = 0;
        }
      }
      else {
        iVar11 = 0x10;
        if (0xffffff < uVar4) {
          iVar11 = 0x18;
        }
      }
      uVar3 = 0x20 - ((u32)(u8)(&DAT_007c0388)[uVar19 >> iVar11] + iVar11);
      uVar6 = 0x20 - uVar3;
      if (uVar3 != 0) {
        uVar9 = uVar10 >> (uVar6 & 0x1f);
        uVar19 = uVar19 << (uVar3 & 0x1f) | uVar1 >> (uVar6 & 0x1f);
        uVar8 = uVar19 >> 0x10;
        iVar11 = (int)uVar9 / (int)uVar8;
        uVar10 = uVar10 << (uVar3 & 0x1f) | uVar17 >> (uVar6 & 0x1f);
        uVar1 = uVar1 << (uVar3 & 0x1f);
        if (uVar8 == 0) {
          trap(7);
        }
        uVar6 = iVar11 * (uVar19 & 0xffff);
        uVar9 = (int)uVar9 % (int)uVar8 << 0x10 | uVar10 >> 0x10;
        if (uVar9 < uVar6) {
          uVar9 = uVar9 + uVar19;
          iVar13 = iVar11 + -1;
          if (uVar19 <= uVar9) {
            if (uVar6 <= uVar9) {
              iVar7 = uVar9 - uVar6;
              goto LAB_00530420;
            }
            iVar13 = iVar11 + -2;
            uVar9 = uVar9 + uVar19;
          }
          iVar7 = uVar9 - uVar6;
        }
        else {
          iVar7 = uVar9 - uVar6;
          iVar13 = iVar11;
        }
LAB_00530420:
        uVar6 = iVar7 / (int)uVar8;
        if (uVar8 == 0) {
          trap(7);
        }
        uVar9 = uVar6 * (uVar19 & 0xffff);
        uVar8 = iVar7 % (int)uVar8 << 0x10 | uVar10 & 0xffff;
        uVar10 = uVar6;
        if (uVar8 < uVar9) {
          uVar8 = uVar8 + uVar19;
          uVar10 = uVar6 - 1;
          if ((uVar19 <= uVar8) && (uVar8 < uVar9)) {
            uVar10 = uVar6 - 2;
            uVar8 = uVar8 + uVar19;
          }
        }
        uVar16 = uVar1 & 0xffff;
        uVar6 = iVar13 << 0x10 | uVar10;
        uVar1 = uVar1 >> 0x10;
        uVar19 = (uVar10 & 0xffff) * uVar16;
        uVar16 = (uVar6 >> 0x10) * uVar16;
        uVar10 = (uVar10 & 0xffff) * uVar1 + (uVar19 >> 0x10) + uVar16;
        iVar11 = (uVar6 >> 0x10) * uVar1;
        if (uVar10 < uVar16) {
          iVar11 = iVar11 + 0x10000;
        }
        uVar1 = iVar11 + (uVar10 >> 0x10);
        if ((uVar8 - uVar9 < uVar1) ||
           ((uVar1 == uVar8 - uVar9 &&
            (uVar17 << (uVar3 & 0x1f) < uVar10 * 0x10000 + (uVar19 & 0xffff))))) {
          uVar6 = uVar6 - 1;
        }
        uVar4 = 0;
        goto LAB_0053003c;
      }
      if ((uVar4 < uVar5) || (uVar6 = 0, uVar2 <= uVar18)) {
        uVar6 = 1;
      }
    }
    uVar4 = 0;
    goto LAB_0053003c;
  }
  if (uVar5 < uVar2) {
    if (uVar2 < 0x10000) {
      iVar11 = 8;
      if (uVar2 < 0x100) {
        iVar11 = 0;
      }
    }
    else {
      iVar11 = 0x10;
      if (0xffffff < uVar2) {
        iVar11 = 0x18;
      }
    }
    uVar19 = 0x20 - ((u32)(u8)(&DAT_007c0388)[uVar1 >> iVar11] + iVar11);
    if (uVar19 != 0) {
      uVar2 = (u32)(int)(uVar1 << (uVar19 & 0x1f));
      uVar5 = (u32)(int)(uVar10 << (uVar19 & 0x1f) | uVar17 >> (0x20 - uVar19 & 0x1f));
      uVar18 = (u32)(int)(uVar17 << (uVar19 & 0x1f));
    }
    uVar1 = (u32)uVar2;
    uVar19 = uVar1 >> 0x10;
    iVar11 = (int)uVar5 / (int)uVar19;
    if (uVar19 == 0) {
      trap(7);
    }
    iVar13 = iVar11 * (uVar1 & 0xffff);
    uVar10 = (int)uVar5 % (int)uVar19 << 0x10 | (u32)uVar18 >> 0x10;
    if ((u32)(long)(int)uVar10 < (u32)(long)iVar13) {
      iVar14 = uVar10 + uVar1;
      iVar7 = iVar11 + -1;
      if (uVar2 <= (u32)(long)iVar14) {
        if ((u32)(long)iVar13 <= (u32)(long)iVar14) {
          iVar13 = iVar14 - iVar13;
          goto LAB_0052ffa8;
        }
        iVar7 = iVar11 + -2;
        iVar14 = iVar14 + uVar1;
      }
      iVar13 = iVar14 - iVar13;
    }
    else {
      iVar13 = uVar10 - iVar13;
      iVar7 = iVar11;
    }
LAB_0052ffa8:
    uVar10 = iVar13 / (int)uVar19;
    if (uVar19 == 0) {
      trap(7);
    }
    uVar4 = (u32)(int)(uVar10 * (uVar1 & 0xffff));
    uVar5 = (long)(iVar13 % (int)uVar19 << 0x10) | uVar18 & 0xffff;
    uVar6 = uVar10;
    if (uVar5 < uVar4) {
      uVar5 = (u32)(int)((int)uVar5 + uVar1);
      uVar6 = uVar10 - 1;
      if ((uVar2 <= uVar5) && (uVar5 < uVar4)) {
        uVar6 = uVar10 - 2;
      }
    }
    uVar6 = iVar7 << 0x10 | uVar6;
    uVar4 = 0;
    goto LAB_0053003c;
  }
  if (uVar2 == 0) {
    uVar2 = (u32)(1 / (int)uVar19);
    trap(7);
  }
  if (uVar2 < 0x10000) {
    iVar11 = 8;
    if (uVar2 < 0x100) {
      iVar11 = 0;
    }
  }
  else {
    iVar11 = 0x10;
    if (0xffffff < uVar2) {
      iVar11 = 0x18;
    }
  }
  uVar1 = (u32)uVar2;
  uVar19 = 0x20 - ((u32)(u8)(&DAT_007c0388)[uVar1 >> iVar11] + iVar11);
  if (uVar19 == 0) {
    iVar14 = uVar10 - uVar1;
    uVar4 = 1;
    uVar3 = uVar1 >> 0x10;
    uVar1 = uVar1 & 0xffff;
  }
  else {
    uVar6 = uVar1 << (uVar19 & 0x1f);
    uVar2 = (u32)(int)uVar6;
    uVar3 = uVar6 >> 0x10;
    uVar8 = uVar10 >> (0x20 - uVar19 & 0x1f);
    iVar11 = (int)uVar8 / (int)uVar3;
    uVar1 = uVar6 & 0xffff;
    uVar10 = uVar10 << (uVar19 & 0x1f) | uVar17 >> (0x20 - uVar19 & 0x1f);
    uVar18 = (u32)(int)(uVar17 << (uVar19 & 0x1f));
    if (uVar3 == 0) {
      trap(7);
    }
    iVar13 = iVar11 * uVar1;
    uVar19 = (int)uVar8 % (int)uVar3 << 0x10 | uVar10 >> 0x10;
    iVar7 = iVar11;
    if ((u32)(long)(int)uVar19 < (u32)(long)iVar13) {
      uVar19 = uVar19 + uVar6;
      iVar7 = iVar11 + -1;
      if ((u32)(long)(int)uVar19 < uVar2) goto LAB_00530250;
      if ((u32)(long)(int)uVar19 < (u32)(long)iVar13) {
        iVar7 = iVar11 + -2;
        uVar19 = uVar19 + uVar6;
        goto LAB_00530250;
      }
      iVar13 = uVar19 - iVar13;
    }
    else {
LAB_00530250:
      iVar13 = uVar19 - iVar13;
    }
    iVar11 = iVar13 / (int)uVar3;
    uVar5 = (u32)iVar11;
    if (uVar3 == 0) {
      trap(7);
    }
    iVar14 = iVar11 * uVar1;
    uVar12 = (long)(iVar13 % (int)uVar3 << 0x10) | (long)(int)uVar10 & 0xffffU;
    uVar4 = (u32)(iVar7 << 0x10);
    if (uVar12 < (u32)(long)iVar14) {
      iVar13 = (int)uVar12 + uVar6;
      uVar12 = (u32)iVar13;
      uVar5 = (u32)(iVar11 + -1);
      if (uVar2 <= uVar12) {
        uVar4 = (u32)(iVar7 << 0x10);
        if ((u32)(long)iVar14 <= uVar12) goto LAB_005302b0;
        uVar5 = (u32)(iVar11 + -2);
        uVar12 = (u32)(int)(iVar13 + uVar6);
      }
      uVar4 = (u32)(iVar7 << 0x10);
    }
LAB_005302b0:
    iVar14 = (int)uVar12 - iVar14;
    uVar4 = uVar4 | uVar5;
  }
  iVar11 = iVar14 / (int)uVar3;
  if (uVar3 == 0) {
    trap(7);
  }
  iVar13 = iVar11 * uVar1;
  uVar19 = iVar14 % (int)uVar3 << 0x10 | (u32)uVar18 >> 0x10;
  iVar7 = (int)uVar2;
  if ((u32)(long)(int)uVar19 < (u32)(long)iVar13) {
    iVar15 = uVar19 + iVar7;
    iVar14 = iVar11 + -1;
    if (uVar2 <= (u32)(long)iVar15) {
      if ((u32)(long)iVar13 <= (u32)(long)iVar15) {
        iVar13 = iVar15 - iVar13;
        goto LAB_0053016c;
      }
      iVar14 = iVar11 + -2;
      iVar15 = iVar15 + iVar7;
    }
    iVar13 = iVar15 - iVar13;
  }
  else {
    iVar13 = uVar19 - iVar13;
    iVar14 = iVar11;
  }
LAB_0053016c:
  uVar19 = iVar13 / (int)uVar3;
  if (uVar3 == 0) {
    trap(7);
  }
  uVar5 = (long)(iVar13 % (int)uVar3 << 0x10) | uVar18 & 0xffff;
  uVar6 = uVar19;
  if (uVar5 < (u32)(long)(int)(uVar19 * uVar1)) {
    uVar5 = (u32)((int)uVar5 + iVar7);
    uVar6 = uVar19 - 1;
    if ((uVar2 <= uVar5) && (uVar5 < (u32)(long)(int)(uVar19 * uVar1))) {
      uVar6 = uVar19 - 2;
    }
  }
  uVar6 = iVar14 << 0x10 | uVar6;
LAB_0053003c:
  return (u32)uVar6 | uVar4 << 0x20;
}
