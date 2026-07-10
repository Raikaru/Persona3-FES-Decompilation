#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_00252e80(void);
void FUN_00252f30(void);
void FUN_002532b0(void);
void FUN_002534d0(u32 *param_1);
extern code DAT_00960090;
extern code DAT_0096009c;
extern f32 fGpffff8248;
extern int iGpffffb6fc;
extern u32 uGpffffb660;

static u32* sBpd660; // puGpffffb660
static u32* sBpd664;
u32 FUN_0021c3f0();
u32 FUN_0021cca0();
void FUN_0021d3b0();

// FUN_00252e60
void bpd00252e60(u32* param_1)
{
    *param_1 = 0;
    param_1[0x2d5] = 0;
    sBpd660 = param_1;
}

// FUN_00252e90
void bpd00252e90(void)
{
    K_ASSERT(sBpd660 != NULL, 0x25);
    *sBpd660 |= 1;
}

// FUN_00252ee0
void bpd00252ee0(void)
{
    K_ASSERT(sBpd660 != NULL, 0x25);
    *sBpd660 &= ~1;
}

// FUN_00253410
void bpd00253410(void)
{
    u32* puVar1;
    u32 uVar2;
    int iVar3;

    K_ASSERT(sBpd660 != NULL, 0x25);
    puVar1 = sBpd660;
    uVar2 = FUN_0021cca0(FUN_0021c3f0(1), 0x4c);
    for (iVar3 = 0; iVar3 < 10; iVar3++) {
        FUN_0021d3b0(puVar1 + iVar3 * 0x48 + 8, uVar2);
    }
    puVar1[0x2d4] = 0;
    *puVar1 |= 2;
}

/* Recovered battle-misc harvest: 0x00252E80-0x002534D0 */
// FUN_00252E80


void FUN_00252e80(void)



{

  uGpffffb660 = 0;

  return;

}

// FUN_00252F30 NONMATCHING






void FUN_00252f30(void)



{

  int iVar1;

  u32 *puVar2;

  int iVar3;

  int iVar4;

  u64 uVar5;

  long lVar6;

  u32 uVar7;

  int iVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  u8 auStack_20 [16];

  u32 uStack_10;

  u32 uStack_c;

  u8 uStack_4;

  u8 uStack_3;

  u8 uStack_2;

  u8 uStack_1;

  

  if (sBpd660 == (u32 *)0x0) {

    FUN_0019d3f0(0x68e9f0,0x25);

  }

  puVar2 = sBpd660;

  uVar5 = FUN_0021c3f0(1);

  iVar8 = iGpffffb6fc;

  if (((~*puVar2 & 2) == 0) && ((~*puVar2 & 1) == 0)) {

    uVar7 = puVar2[0x2d5];

    puVar2[0x2d5] = uVar7 + 1;

    puVar2[0x2d5] = (int)(uVar7 + 1) % 0xf;

    uVar7 = 0;

    for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {

      for (iVar1 = *(int *)(iVar8 + iVar4 * 8 + 0x150); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34))

      {

        if ((~*(u32 *)(iVar1 + 0x9c) & 8) == 0) {

          FUN_002807a0(iVar1,auStack_20);

          lVar6 = FUN_002d20a0(auStack_20,&uStack_10);

          if ((lVar6 != 0) &&

             (lVar6 = FUN_00300580(*(u32 *)(iVar1 + 0xa2c),0x100000), lVar6 != 0)) {

            puVar2[uVar7 * 0x48 + 5] = *(u32 *)(iVar1 + 0xa8);

            puVar2[uVar7 * 0x48 + 0x48] = uStack_10;

            puVar2[uVar7 * 0x48 + 0x49] = uStack_c;

            iVar3 = FUN_0027f930(iVar1);

            puVar2[uVar7 * 0x48 + 0x4a] = (u32)((float)*(u8 *)(iVar3 + 3) / 255.0);

            uVar7 = uVar7 + 1;

          }

        }

      }

    }

    puVar2[0x2d4] = uVar7;

    for (iVar8 = 0; iVar8 < (int)puVar2[0x2d4]; iVar8 = iVar8 + 1) {

      fVar10 = (float)puVar2[iVar8 * 0x48 + 0x48];

      fVar11 = (float)puVar2[iVar8 * 0x48 + 0x49];

      fVar12 = (float)puVar2[iVar8 * 0x48 + 0x4a];

      fVar9 = (float)FUN_0052e878(fGpffff8248 * ((float)(int)puVar2[0x2d5] / 15.0) * 2.0);

      fVar9 = fVar9 * 3.0;

      iVar4 = FUN_0021cca0(uVar5,0x4c);

      fStack_38 = (float)*(int *)(iVar4 + 0xc);

      fStack_40 = fVar10 - fStack_38 / 2.0;

      fStack_34 = (float)*(int *)(iVar4 + 0x10);

      fStack_3c = fVar9 + ((fVar11 - fStack_34 / 2.0) - 10.0);

      FUN_0021d8e0(puVar2 + iVar8 * 0x48 + 8,&fStack_40);

      uStack_4 = 0xff;

      uStack_3 = 0xff;

      uStack_2 = 0xff;

      fVar12 = fVar12 * 255.0;

      if (fVar12 < 2.1474836e+09) {

        uStack_1 = (u8)(int)fVar12;

      }

      else {

        uStack_1 = (u8)(int)(fVar12 - 2.1474836e+09);

      }

      FUN_0021d950(puVar2 + iVar8 * 0x48 + 8,&uStack_4);

    }

  }

  return;

}

// FUN_002532B0 NONMATCHING


void FUN_002532b0(void)



{

  u32 *puVar1;

  u64 uVar2;

  int iVar3;

  

  if (sBpd660 == (u32 *)0x0) {

    FUN_0019d3f0(0x68e9f0,0x25);

  }

  puVar1 = sBpd660;

  uVar2 = FUN_0021c3f0(1);

  if (((~*puVar1 & 2) == 0) && ((~*puVar1 & 1) == 0)) {

    uVar2 = FUN_0021cca0(uVar2,0x4c);

    uVar2 = FUN_0021cce0(uVar2);

    (*DAT_00960090)(1,uVar2);

    FUN_004d7f60(3,0x717fb);

    FUN_004d7f60(2,0x44);

    for (iVar3 = 0; iVar3 < (int)puVar1[0x2d4]; iVar3 = iVar3 + 1) {

      (*DAT_0096009c)(puVar1 + iVar3 * 0x48 + 8,4,0,1,2);

      (*DAT_0096009c)(puVar1 + iVar3 * 0x48 + 8,4,0,2,3);

    }

  }

  return;

}

// FUN_002534D0 NONMATCHING


void FUN_002534d0(u32 *param_1)



{

  int iVar1;

  

  *param_1 = 0;

  param_1[0x499f] = 0;

  param_1[0x49a1] = 0;

  param_1[0x4997] = 0;

  param_1[0x4998] = 0;

  param_1[0x49ea] = 0;

  for (iVar1 = 0; iVar1 < 0x10; iVar1 = iVar1 + 1) {

    param_1[iVar1 * 0x499 + 1] = 0;

    param_1[iVar1 * 0x499 + 6] = iVar1;

  }

  param_1[0x4a20] = 0x100;

  sBpd664 = param_1;

  return;

}
