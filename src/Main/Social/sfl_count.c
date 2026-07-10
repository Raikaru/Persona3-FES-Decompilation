#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_0025b4f0(void);
void FUN_0025b690(void);
void FUN_0025bbf0(void);
extern code DAT_00960090;
extern code DAT_0096009c;
extern f32 fGpffff83c4;

static u32* sSflCount; // puGpffffb674

// FUN_0025b4a0
void sflCount0025b4a0(u32* param_1)
{
    *param_1 = 0;
    sSflCount = param_1;
}

// FUN_0025b5f0
void sflCount0025b5f0(void)
{
    u32* work;

    K_ASSERT(sSflCount != NULL, 0x2b);
    work = sSflCount;
    work[2] = 0;
    *work |= 2;
}

// FUN_0025b4b0
void sflCount0025b4b0(void)
{
    K_ASSERT(sSflCount != NULL, 0x2b);
    sSflCount = NULL;
}

// FUN_0025b640
u32 sflCount0025b640(void)
{
    K_ASSERT(sSflCount != NULL, 0x2b);
    return *sSflCount & 1;
}

/* Recovered battle-misc harvest: 0x0025B4F0-0x0025BBF0 */
// FUN_0025B4F0 NONMATCHING


void FUN_0025b4f0(void)



{

  u32 uVar1;

  u32 *puVar2;

  int iVar3;

  int iVar4;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  if (sSflCount == (u32 *)0x0) {

    FUN_0019d3f0(0x68ebc8,0x2b);

  }

  puVar2 = sSflCount;

  for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {

    iVar3 = FUN_0020e610(iVar4);

    fStack_8 = (float)*(int *)(iVar3 + 0xc);

    fStack_4 = (float)*(int *)(iVar3 + 0x10);

    fStack_10 = 0.0 / fStack_8;

    fStack_c = 0.0 / fStack_4;

    fStack_8 = fStack_8 / fStack_8;

    fStack_4 = fStack_4 / fStack_4;

    FUN_0021eb80(puVar2 + iVar4 * 0x40 + 4,&fStack_10);

    FUN_0021eb80(puVar2 + iVar4 * 0x40 + 0xc4,&fStack_10);

  }

  puVar2[1] = 0;

  puVar2[2] = 0;

  uVar1 = *puVar2;

  *puVar2 = uVar1 & 0xfffffffd;

  *puVar2 = uVar1 & 0xfffffffd | 1;

  return;

}

// FUN_0025B690 NONMATCHING


void FUN_0025b690(void)



{

  u32 uVar1;

  u32 *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float unaff_f24;

  float fVar9;

  float afStack_30 [5];

  float fStack_1c;

  u32 uStack_18;

  float fStack_14;

  u8 uStack_4;

  u8 uStack_3;

  u8 uStack_2;

  u8 uStack_1;

  

  if (sSflCount == (u32 *)0x0) {

    FUN_0019d3f0(0x68ebc8,0x2b);

  }

  puVar2 = sSflCount;

  if ((~*sSflCount & 1) == 0) {

    uVar1 = sSflCount[1];

    sSflCount[1] = uVar1 + 1;

    if (uVar1 + 1 == 0xb4) {

      uVar1 = *sSflCount;

      *sSflCount = uVar1 & 0xfffffffd;

      *sSflCount = uVar1 & 0xfffffffc;

    }

    if ((*sSflCount & 2) == 0) {

      fVar8 = 1.0;

    }

    else {

      uVar1 = sSflCount[2];

      sSflCount[2] = uVar1 + 1;

      if (uVar1 + 1 == 0x14) {

        uVar1 = *sSflCount;

        *sSflCount = uVar1 & 0xfffffffd;

        *sSflCount = uVar1 & 0xfffffffc;

      }

      fVar8 = 1.0 - (float)(int)sSflCount[2] / 20.0;

    }

    for (iVar5 = 0; iVar5 < 3; iVar5 = iVar5 + 1) {

      iVar3 = FUN_0020e610(iVar5);

      fVar6 = fGpffff83c4 * (float)*(int *)(iVar3 + 0xc);

      fVar7 = fGpffff83c4 * (float)*(int *)(iVar3 + 0x10);

      afStack_30[0] = 236.0;

      afStack_30[1] = 196.0;

      afStack_30[2] = fVar6 + 236.0;

      afStack_30[3] = 196.0;

      afStack_30[4] = fVar6 + 236.0;

      fStack_1c = fVar7 + 196.0;

      uStack_18 = 0x436c0000;

      fStack_14 = fStack_1c;

      iVar3 = (2 - iVar5) * 0x1e + 0x5a;

      fVar9 = 1.0;

      if ((iVar3 <= (int)puVar2[1]) && (iVar4 = puVar2[1] - iVar3, fVar9 = unaff_f24, iVar4 < 0x14))

      {

        fVar9 = (float)iVar4 / 20.0 + 0.5;

      }

      for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {

        afStack_30[iVar4 * 2] = afStack_30[iVar4 * 2] - 319.0;

        afStack_30[iVar4 * 2 + 1] = afStack_30[iVar4 * 2 + 1] - 279.0;

      }

      for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {

        afStack_30[iVar4 * 2] = afStack_30[iVar4 * 2] * fVar9;

        afStack_30[iVar4 * 2 + 1] = afStack_30[iVar4 * 2 + 1] * fVar9;

      }

      for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {

        afStack_30[iVar4 * 2] = afStack_30[iVar4 * 2] + 319.0;

        afStack_30[iVar4 * 2 + 1] = afStack_30[iVar4 * 2 + 1] + 279.0;

      }

      FUN_0021d890(puVar2 + iVar5 * 0x40 + 4,afStack_30);

      afStack_30[0] = 236.0;

      afStack_30[1] = 196.0;

      afStack_30[2] = fVar6;

      afStack_30[3] = fVar7;

      FUN_0021d8e0(puVar2 + iVar5 * 0x40 + 0xc4,afStack_30);

      if ((int)puVar2[1] < iVar3) {

        fVar6 = 0.0;

      }

      else {

        iVar3 = puVar2[1] - iVar3;

        if (iVar3 == 0) {

          FUN_0010a4e0(1,1,6,5);

        }

        if (iVar3 < 10) {

          fVar6 = (float)iVar3 / 10.0;

        }

        else {

          fVar6 = 1.0;

          if (0xe < iVar3) {

            if (iVar3 < 0x14) {

              fVar6 = 1.0 - (float)(iVar3 + -0xf) / 5.0;

            }

            else {

              fVar6 = 0.0;

            }

          }

        }

      }

      uStack_4 = 0xff;

      uStack_3 = 0xff;

      uStack_2 = 0xff;

      fVar7 = fVar6 * 255.0 * fVar8;

      fVar6 = fVar7 * 0.25;

      if (fVar6 < 2.1474836e+09) {

        uStack_1 = (u8)(int)fVar6;

      }

      else {

        uStack_1 = (u8)(int)(fVar6 - 2.1474836e+09);

      }

      FUN_0021d950(puVar2 + iVar5 * 0x40 + 4,&uStack_4);

      uStack_4 = 0xff;

      uStack_3 = 0xff;

      uStack_2 = 0xff;

      if (fVar7 < 2.1474836e+09) {

        uStack_1 = (u8)(int)fVar7;

      }

      else {

        uStack_1 = (u8)(int)(fVar7 - 2.1474836e+09);

      }

      FUN_0021d950(puVar2 + iVar5 * 0x40 + 0xc4,&uStack_4);

      unaff_f24 = fVar9;

    }

  }

  return;

}

// FUN_0025BBF0 NONMATCHING


void FUN_0025bbf0(void)



{

  u32 *puVar1;

  u64 uVar2;

  u32 *puVar3;

  int iVar4;

  

  if (sSflCount == (u32 *)0x0) {

    FUN_0019d3f0(0x68ebc8,0x2b);

  }

  puVar1 = sSflCount;

  if ((~*sSflCount & 1) == 0) {

    (*DAT_00960090)(9,2);

    (*DAT_00960090)(0x14,2);

    (*DAT_00960090)(8,0);

    (*DAT_00960090)(6,0);

    FUN_004d7f60(3,0x717fb);

    FUN_004d7f60(2,0x44);

    FUN_004d7f60(3,0x71801);

    FUN_004d7f60(2,0x48);

    for (iVar4 = 0; iVar4 < 3; iVar4 = iVar4 + 1) {

      uVar2 = FUN_0020e610(iVar4);

      (*DAT_00960090)(1,uVar2);

      puVar3 = puVar1 + iVar4 * 0x40 + 4;

      (*DAT_0096009c)(puVar3,4,0,1,2);

      (*DAT_0096009c)(puVar3,4,0,2,3);

      puVar3 = puVar1 + iVar4 * 0x40 + 0xc4;

      (*DAT_0096009c)(puVar3,4,0,1,2);

      (*DAT_0096009c)(puVar3,4,0,2,3);

    }

  }

  return;

}
