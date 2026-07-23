#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#ifndef SQRT
#define SQRT(x) sqrtf(x)
#endif
float sqrtf(float x);


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_0025a120(void);
void FUN_0025a130(void);
void FUN_0025a440(void);
void FUN_0025a7d0(void);
void FUN_0025aad0(void);
void FUN_0025b440(void);
extern code DAT_00960090;
extern code DAT_0096009c;
#pragma alias DAT_00960090_abs DAT_00960090
#pragma alias DAT_0096009c_abs DAT_0096009c
extern code DAT_00960090_abs[];
extern code DAT_0096009c_abs[];
#define DAT_00960090 DAT_00960090_abs
#define DAT_0096009c DAT_0096009c_abs
extern f32 fGpffff8088;
extern f32 fGpffff8248;
extern f32 fGpffff82ac;
extern f32 fGpffff83b8;
extern f32 fGpffff83bc;
extern f32 fGpffff82fc;
extern u32 uGpffffb670;

typedef struct { f32 a; f32 b; f32 c; } SflVec3;
typedef struct {
  u32 flags;
  f32 from[3];
  f32 to[3];
  f32 position[3];
  u32 frame;
  u32 previous;
  u32 active;
  u32 timer;
  u8 padding[0xc68];
  u32 state;
} SflCursorWork;


static u32* sSflCursor; // puGpffffb670

void FUN_00258540(u32 param_1, void* param_2);
extern u32 FUN_0020e510(s32 index);
extern void FUN_0021eb80(void* work, const f32* values);
extern void FUN_00250f80(f32* output, const void* input);

// FUN_0025a110
void sflCursor0025a110(u32* param_1)
{
    *param_1 = 0;
    sSflCursor = param_1;
}

// FUN_0025b300
void sflCursor0025b300(u32 param_1)
{
    u32* work;

    K_ASSERT(sSflCursor != NULL, 0x47);
    work = sSflCursor;
    FUN_00258540(work[0xc], work + 1);
    FUN_00258540(param_1, work + 4);
    *(SflVec3*)(work + 7) = *(SflVec3*)(work + 1);
    work[0xb] = work[0xc];
    work[0xc] = param_1;
    work[10] = 0;
    work[0x328] = 0;
    *work |= 2;
    FUN_0025aad0();
}

// FUN_0025b3b0
void sflCursor0025b3b0(u32 param_1)
{
    u32* work;

    K_ASSERT(sSflCursor != NULL, 0x47);
    work = sSflCursor;
    FUN_00258540(param_1, work + 7);
    work[0xb] = work[0xc];
    work[0xc] = param_1;
    work[10] = 0;
    work[0x328] = 1;
    *work |= 2;
    FUN_0025aad0();
}

// FUN_0025aa70
void sflCursor0025aa70(void)
{
    u32* puVar1;

    K_ASSERT(sSflCursor != NULL, 0x47);
    puVar1 = sSflCursor;
    puVar1[10] = 0;
    puVar1[0x328] = 3;
    *puVar1 |= 2;
}

/* Recovered battle-misc harvest: 0x0025A120-0x0025B440 */
// FUN_0025A120


void FUN_0025a120(void)



{

  uGpffffb670 = 0;

  return;

}

// FUN_0025A130 NONMATCHING


void FUN_0025a130(void)
{
  u32 *puVar1;
  u32 *puVar2;
  s32 uVar3;
  f32 fVar4;
  f32 fStack_10;
  f32 fStack_14;
  f32 fStack_18;

  K_ASSERT(sSflCursor != NULL, 0x47);
  puVar1 = sSflCursor;
  if ((~*puVar1 & 1) == 0) {
    puVar1[0xd] = puVar1[0xd] + 1;
    puVar1[0xd] = puVar1[0xd] % 0x3c;
    if ((*puVar1 & 2) != 0) {
      uVar3 = puVar1[0x328];
      if (uVar3 == 2) {
        puVar1[10] = puVar1[10] + 1;
        if (puVar1[10] == 0x10) {
          *puVar1 = *puVar1 & 0xfffffffd;
        }
      } else if (uVar3 == 3) {
        puVar1[10] = puVar1[10] + 1;
        if (puVar1[10] == 0x10) {
          *puVar1 = *puVar1 & 0xfffffffd;
          *puVar1 = *puVar1 & 0xfffffffc;
        }
      } else if (uVar3 == 1) {
        puVar1[10] = puVar1[10] + 1;
        if (puVar1[10] == 4) {
          *puVar1 = *puVar1 & 0xfffffffd;
        }
      } else if (uVar3 == 0) {
        puVar1[10] = puVar1[10] + 1;
        if (puVar1[10] == 4) {
          *puVar1 = *puVar1 & 0xfffffffd;
        }
        fVar4 = (f32)(s32)puVar1[10] / 4.0f;
        fStack_10 = ((SflCursorWork*)puVar1)->to[0] -
                    ((SflCursorWork*)puVar1)->from[0];
        fStack_14 = ((SflCursorWork*)puVar1)->to[1] -
                    ((SflCursorWork*)puVar1)->from[1];
        fStack_18 = ((SflCursorWork*)puVar1)->to[2] -
                    ((SflCursorWork*)puVar1)->from[2];
        fStack_10 *= fVar4;
        fStack_14 *= fVar4;
        fStack_18 *= fVar4;
        fStack_10 += ((SflCursorWork*)puVar1)->from[0];
        fStack_14 += ((SflCursorWork*)puVar1)->from[1];
        fStack_18 += ((SflCursorWork*)puVar1)->from[2];
        ((SflCursorWork*)puVar1)->position[0] = fStack_10;
        ((SflCursorWork*)puVar1)->position[1] = fStack_14;
        ((SflCursorWork*)puVar1)->position[2] = fStack_18;
      }
    }
    for (uVar3 = 0; uVar3 < 6; uVar3 = uVar3 + 1) {
      puVar2 = puVar1 + uVar3 * 0x84 + 0x10;
      if (uVar3 == (s32)puVar1[0xc]) {
        if ((s32)*puVar2 < 0x100) {
          *puVar2 = *puVar2 + 0x19;
        }
        if (0x100 < (s32)*puVar2) {
          *puVar2 = 0x100;
        }
      } else {
        if (*puVar2 != 0) {
          *puVar2 = *puVar2 - 8;
        }
        if ((s32)*puVar2 < 0) {
          *puVar2 = 0;
        }
      }
      puVar2++;
      if (uVar3 == (s32)puVar1[0xc]) {
        if ((s32)*puVar2 < 0x100) {
          *puVar2 = *puVar2 + 0x40;
        }
        if (0x100 < (s32)*puVar2) {
          *puVar2 = 0x100;
        }
      } else {
        if (*puVar2 != 0) {
          *puVar2 = *puVar2 - 0xc;
        }
        if ((s32)*puVar2 < 0) {
          *puVar2 = 0;
        }
      }
    }
  }
  FUN_0025aad0();
  return;
}

// FUN_0025A440


void FUN_0025a440(void)
{
  volatile code *pRender;
  volatile code *pTex;
  u32 *puVar1;
  u32 *puVar2;
  u32 uVar2;
  s32 bVar3;
  s32 uVar4;

  K_ASSERT(sSflCursor != NULL, 0x47);
  puVar1 = sSflCursor;
  if ((~*puVar1 & 1) == 0) {
    pRender = DAT_00960090_abs;
    (*pRender)(9,2);
    (*pRender)(0x14,2);
    (*pRender)(8,0);
    (*pRender)(6,0);
    FUN_004d7f60(3,0x717fb);
    FUN_004d7f60(2,0x44);
    uVar2 = FUN_0020e510(4);
    (*pRender)(1,uVar2);
    pTex = DAT_0096009c_abs;
    (*pTex)(puVar1 + 0x32c,4,0,1,2);
    (*pTex)(puVar1 + 0x32c,4,0,2,3);
    (*pTex)(puVar1 + 0x36c,4,0,1,2);
    (*pTex)(puVar1 + 0x36c,4,0,2,3);
    uVar2 = FUN_0020e590(2);
    (*pRender)(1,uVar2);
    (*pTex)(puVar1 + 0x3ac,4,0,1,2);
    (*pTex)(puVar1 + 0x3ac,4,0,2,3);
    FUN_004d7f60(3,0x71801);
    FUN_004d7f60(2,0x48);
    for (uVar4 = 0; uVar4 < 6; uVar4 = uVar4 + 1) {
      puVar2 = puVar1 + uVar4 * 0x84 + 0x10;
      bVar3 = 0;
      if (((*puVar1 & 2) != 0) && (puVar1[0x328] == 1)) {
        if ((uVar4 == (s32)puVar1[0xc]) ||
            (uVar4 == (s32)puVar1[0xb])) {
          bVar3 = 1;
        }
      } else if (uVar4 == (s32)puVar1[0xc]) {
        bVar3 = 1;
      }
      if (bVar3) {
        volatile code *pTexInner;

        uVar2 = FUN_0020e510(2);
        (*pRender)(1,uVar2);
        pTexInner = DAT_0096009c_abs;
        (*pTexInner)(puVar2 + 4,4,0,1,2);
        (*pTexInner)(puVar2 + 4,4,0,2,3);
      }
      if (*puVar2 != 0) {
        volatile code *pTexInner;

        uVar2 = FUN_0020e510(1);
        (*pRender)(1,uVar2);
        pTexInner = DAT_0096009c_abs;
        (*pTexInner)(puVar2 + 0x44,4,0,1,2);
        (*pTexInner)(puVar2 + 0x44,4,0,2,3);
      }
    }
  }
  return;
}

// FUN_0025A7D0
void FUN_0025a7d0(void)
{
    u32* puVar2;
    s32 iVar3;
    s32 iVar4;
    f32 fVar7;
    f32 fVar5;
    f32 fVar6;
    f32 width;
    f32 height;
    f32 rect[4];

    K_ASSERT(sSflCursor != NULL, 0x47);
    puVar2 = sSflCursor;
    *sSflCursor = 0;

    iVar3 = FUN_0020e510(4);
    width = (f32)*(s32*)(iVar3 + 0xc);
    height = (f32)*(s32*)(iVar3 + 0x10);
    fVar7 = 1.0f / width;
    rect[0] = fVar7;
    rect[1] = 0.0f / height;
    fVar6 = 117.0f / width;
    rect[2] = fVar6;
    fVar5 = 32.0f / height;
    rect[3] = fVar5;
    FUN_0021eb80(puVar2 + 0x32c, rect);

    rect[0] = fVar7;
    rect[1] = fVar5;
    rect[2] = fVar6;
    rect[3] = fVar5;
    FUN_0021eb80(puVar2 + 0x36c, rect);

    iVar3 = FUN_0020e590(2);
    width = (f32)*(s32*)(iVar3 + 0xc);
    height = (f32)*(s32*)(iVar3 + 0x10);
    rect[0] = 0.0f / width;
    rect[1] = 84.0f / height;
    rect[2] = 63.0f / width;
    rect[3] = 20.0f / height;
    FUN_0021eb80(puVar2 + 0x3ac, rect);

    FUN_00258540(0, puVar2 + 7);
    for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
        u8* entry;

        entry = (u8*)puVar2 + iVar3 * 0x210 + 0x40;
        *(u32*)entry = 0;
        *(u32*)(entry + 4) = 0;

        iVar4 = FUN_0020e510(2);
        width = (f32)*(s32*)(iVar4 + 0xc);
        height = (f32)*(s32*)(iVar4 + 0x10);
        rect[0] = 0.0f / width;
        rect[1] = 0.0f / height;
        rect[2] = width / width;
        rect[3] = height / height;
        FUN_0021eb80(entry + 0x10, rect);

        iVar4 = FUN_0020e510(1);
        width = (f32)*(s32*)(iVar4 + 0xc);
        height = (f32)*(s32*)(iVar4 + 0x10);
        rect[0] = 0.0f / width;
        rect[1] = 0.0f / height;
        rect[2] = width / width;
        rect[3] = height / height;
        FUN_0021eb80(entry + 0x110, rect);
    }
    FUN_0025aad0();

    puVar2[0xc] = 0;
    puVar2[10] = 0;
    puVar2[0x328] = 2;
    *puVar2 |= 2;
    *puVar2 |= 1;
}

// FUN_0025B440


void FUN_0025b440(void)
{
  u32 uVar1;

  uVar1 = 0x18;
  uVar1 += (u32)FUN_00488f30() % 5;
  FUN_0016f3e0(0x39,0);
  FUN_0016f3e0(0x38,uVar1);
}

/* Recovered battle-misc harvest: 0x0025AAD0-0x0025AAD0 */
// FUN_0025AAD0 NONMATCHING


void FUN_0025aad0(void)



{

  u32 *puVar1;

  int iVar2;

  u64 uVar3;

  u8 bVar4;

  u32 uVar5;

  float fVar6;

  int iVar7;

  u32 uVar8;

  float fVar9;

  float fVar10;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  u8 auStack_20 [16];

  float fStack_10;

  float fStack_c;

  u8 uStack_4;

  u8 uStack_3;

  u8 uStack_2;

  u8 uStack_1;

  

  K_ASSERT(sSflCursor != NULL, 0x47);

  puVar1 = sSflCursor;

  FUN_0020e510(4);

  fStack_40 = 42.0;

  fStack_3c = 40.0;

  fStack_38 = 117.0;

  fStack_34 = 32.0;

  FUN_0021d8e0(puVar1 + 0x32c,&fStack_40);

  fStack_40 = 124.0;

  fStack_3c = 40.0;

  fStack_38 = 117.0;

  fStack_34 = 32.0;

  FUN_0021d8e0(puVar1 + 0x36c,&fStack_40);
  if ((*puVar1 & 2) == 0) {

    fVar10 = 1.0f;

  }

  else if (puVar1[0x328] == 3) {

    fVar10 = 1.0f - (float)(int)puVar1[10] / 16.0f;

  }

  else if (puVar1[0x328] == 2) {

    fVar10 = (float)(int)puVar1[10] / 16.0f;

  }

  else {

    fVar10 = 1.0f;

  }

  uStack_4 = 0xff;

  uStack_3 = 0xff;

  uStack_2 = 0xff;

  fVar9 = fVar10 * 255.0f;

  if (fVar9 < 2.1474836e+09f) {

    uStack_1 = (u8)(int)fVar9;

  }

  else {

    uStack_1 = (u8)(int)(fVar9 - 2.1474836e+09f);

  }

  FUN_0021d950(puVar1 + 0x32c,&uStack_4);

  FUN_0021d950(puVar1 + 0x36c,&uStack_4);

  FUN_0020e590(2);

  fStack_40 = 547.0;

  fStack_3c = 406.0;

  fStack_38 = 63.0;

  fStack_34 = 20.0;

  FUN_0021d8e0(puVar1 + 0x3ac,&fStack_40);

  uStack_4 = 0xff;

  uStack_3 = 0xff;

  uStack_2 = 0xff;

  if (fVar9 < 2.1474836e+09f) {

    uStack_1 = (u8)(int)fVar9;

  }

  else {

    uStack_1 = (u8)(int)(fVar9 - 2.1474836e+09f);

  }

  FUN_0021d950(puVar1 + 0x3ac,&uStack_4);

  for (uVar5 = 0; (int)uVar5 < 6; uVar5 = uVar5 + 1) {

    bVar4 = 0;

    if (((*puVar1 & 2) == 0) || (puVar1[0x328] != 1)) {

      if (uVar5 == puVar1[0xc]) {

        bVar4 = 1;

      }

    }

    else if ((uVar5 == puVar1[0xc]) || (uVar5 == puVar1[0xb])) {

      bVar4 = 1;

    }

    if (bVar4) {

      iVar2 = FUN_0020e510(2);

      iVar7 = *(int *)(iVar2 + 0xc);

      fVar9 = (float)*(int *)(iVar2 + 0x10);

      if (((*puVar1 & 2) == 0) || (puVar1[0x328] != 1)) {

        FUN_00258540(uVar5, auStack_20);
        FUN_00250f80(&fStack_10, auStack_20);

      }

      else {

        FUN_00250f80(&fStack_10, puVar1 + 7);

      }

      fStack_34 = 1.0f;

      if (((*puVar1 & 2) != 0) && (fStack_34 = 1.0f, puVar1[0x328] == 0)) {

        fVar6 = fGpffff82ac * ((float)(int)puVar1[10] / 4.0f) + fGpffff83bc + 0.0f;

        fStack_34 = 1.0f - (SQRT(1.0f - fVar6 * fVar6) - SQRT(fGpffff83b8));

      }

      fStack_38 = (((float)iVar7 * 450.0f) / 100.0f) * fStack_34;

      fStack_34 = ((fVar9 * 450.0f) / 100.0f) * fStack_34;

      fStack_40 = fStack_10 - fStack_38 / 2.0f;

      fStack_3c = fStack_c - fStack_34 / 2.0f;

      FUN_0021d8e0(puVar1 + uVar5 * 0x84 + 0x14,&fStack_40);

      fVar9 = (float)FUN_0052e878(fGpffff8248 * ((float)(int)puVar1[0xd] / 60.0f) * 2.0f);

      fVar9 = fGpffff8088 * ((fVar9 + 1.0f) / 2.0f) + fGpffff82fc + 0.0f;

      uStack_4 = 200;

      uStack_3 = 200;

      uStack_2 = 0xfa;

      if (((*puVar1 & 2) == 0) || (puVar1[0x328] != 1)) {

        fVar9 = fVar9 * 255.0f * fVar10;

        if (fVar9 < 2.1474836e+09f) {

          uStack_1 = (u8)(int)fVar9;

        }

        else {

          uStack_1 = (u8)(int)(fVar9 - 2.1474836e+09f);

        }

      }

      else {

        if (uVar5 == puVar1[0xc]) {

          uVar8 = puVar1[10];

        }

        else {

          uVar8 = 4 - puVar1[10];

        }

        fVar9 = fVar10 * ((float)(int)uVar8 / 4.0f) * 255.0f * fVar9;

        if (fVar9 < 2.1474836e+09f) {

          uStack_1 = (u8)(int)fVar9;

        }

        else {

          uStack_1 = (u8)(int)(fVar9 - 2.1474836e+09f);

        }

      }

      FUN_0021d950(puVar1 + uVar5 * 0x84 + 0x14,&uStack_4);

    }

    if (puVar1[uVar5 * 0x84 + 0x10] != 0) {



      iVar2 = FUN_0020e510(1);

      fStack_40 = fStack_10 - 92.0f;

      fStack_3c = fStack_c - 105.0f;

      fStack_38 = ((float)*(int *)(iVar2 + 0xc) * 260.0f) / 100.0f;

      fStack_34 = ((float)*(int *)(iVar2 + 0x10) * 260.0f) / 100.0f;

      FUN_0021d8e0(puVar1 + uVar5 * 0x84 + 0x54,&fStack_40);

      uStack_4 = 0xff;

      uStack_3 = 0xff;

      uStack_2 = 0xff;

      fVar9 = (((float)(int)puVar1[uVar5 * 0x84 + 0x10] * 255.0f) / 256.0f) * fVar10;

      if (fVar9 < 2.1474836e+09f) {

        uStack_1 = (u8)(int)fVar9;

      }

      else {

        uStack_1 = (u8)(int)(fVar9 - 2.1474836e+09f);

      }

      FUN_0021d950(puVar1 + uVar5 * 0x84 + 0x54,&uStack_4);

    }

    if (puVar1[uVar5 * 0x84 + 0x11] != 0) {

      uVar3 = FUN_00256110(uVar5);

      FUN_002561e0(((float)(int)puVar1[uVar5 * 0x84 + 0x11] / 256.0f) * fVar10,uVar3);

    }

  }

  return;

}
