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
  FUN_0052f7d0(param_1,param_2,auStack_30);
  uVar2 = auStack_30[0];
  if (iVar1 != 0) {
    uVar2 =
         CONCAT44(-(u32)(-(int)uVar2 != 0) - (int)((u32)uVar2 >> 0x20),
                  -(int)uVar2);
  }
  return uVar2;
}
/* Structured unsigned core, measured against the raw Ghidra form below. */
#pragma opt_propagation off
// FUN_0052F7D0 NONMATCHING
u64 FUN_0052f7d0(u64 n, u64 d, u64 *rp)
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
#pragma opt_propagation reset
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
  if (uVar19 != 0) {
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
  else {
    iVar14 = uVar10 - uVar1;
    uVar4 = 1;
    uVar3 = uVar1 >> 0x10;
    uVar1 = uVar1 & 0xffff;
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
