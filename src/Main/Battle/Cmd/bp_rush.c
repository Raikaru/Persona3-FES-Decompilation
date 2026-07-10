#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_0025d130(void);
void FUN_0025d470(void);
extern f32 DAT_007caee8;
extern u32* DAT_007ce36c;
extern code DAT_00960090;
extern code DAT_0096009c;

static u32* sBpRush; // DAT_007ce36c


// FUN_0025d6c0
void bpRush0025d6c0(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush |= 0x10;
}

// FUN_0025d710
void bpRush0025d710(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush &= 0xffffffef;
}

// FUN_0025d760
void bpRush0025d760(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush |= 0x20;
}

// FUN_0025d7b0
void bpRush0025d7b0(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush &= 0xffffffdf;
}

// FUN_0025d800
void bpRush0025d800(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush |= 0x40;
}

// FUN_0025d850
void bpRush0025d850(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush &= 0xffffffbf;
}

// FUN_0025d020 NONMATCHING
void bpRush0025d020(void)
{
    u32* work;
    u32 v;

    K_ASSERT(sBpRush != NULL, 0x32);
    work = sBpRush;
    if ((~*sBpRush & 1) == 0) {
        v = work[0x206];
        work[0x206] = v + 1;
        work[0x206] = (int)(v + 1) % 10;
        if ((*work & 0x10) != 0 || (*work & 0x20) != 0) {
            if (0 < (int)work[0x204]) {
                work[0x204] = work[0x204] - 1;
            }
        } else if ((int)work[0x204] < 0x10) {
            work[0x204] = work[0x204] + 1;
        }
        if ((*work & 0x40) != 0) {
            if ((int)work[0x205] < 10) {
                work[0x205] = work[0x205] + 1;
            }
        } else if (0 < (int)work[0x205]) {
            work[0x205] = work[0x205] - 1;
        }
    }
}

/* Recovered battle-misc harvest: 0x0025D470-0x0025D470 */
// FUN_0025D470 NONMATCHING


void FUN_0025d470(void)



{

  u32 *puVar1;

  u64 uVar2;

  u64 uVar3;

  int iVar4;

  

  if (DAT_007ce36c == (u32 *)0x0) {

    FUN_0019d3f0(0x68ebe8,0x32);

  }

  puVar1 = DAT_007ce36c;

  uVar2 = FUN_00267390();

  if ((~*puVar1 & 1) == 0) {

    (*DAT_00960090)(9,2);

    (*DAT_00960090)(0x14,2);

    (*DAT_00960090)(8,0);

    (*DAT_00960090)(6,0);

    uVar3 = FUN_0021cca0(uVar2,1);

    uVar3 = FUN_0021cce0(uVar3);

    (*DAT_00960090)(1,uVar3);

    FUN_004d7f60(3,0x71801);

    FUN_004d7f60(2,0x48);

    for (iVar4 = 0; iVar4 < 7; iVar4 = iVar4 + 1) {

      (*DAT_0096009c)(puVar1 + iVar4 * 0x40 + 0x44,4,0,1,2);

      (*DAT_0096009c)(puVar1 + iVar4 * 0x40 + 0x44,4,0,2,3);

    }

    uVar2 = FUN_0021cca0(uVar2,0);

    uVar2 = FUN_0021cce0(uVar2);

    (*DAT_00960090)(1,uVar2);

    FUN_004d7f60(3,0x717fb);

    FUN_004d7f60(2,0x44);

    (*DAT_0096009c)(puVar1 + 4,4,0,1,2);

    (*DAT_0096009c)(puVar1 + 4,4,0,2,3);

  }

  return;

}

/* Recovered battle-misc harvest: 0x0025D130-0x0025D130 */
// FUN_0025D130 NONMATCHING


void FUN_0025d130(void)



{

  int iVar1;

  int iVar2;

  u64 uVar3;

  int iVar4;

  int iVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  u8 uStack_4;

  u8 uStack_3;

  u8 uStack_2;

  u8 uStack_1;

  

  if (DAT_007ce36c == 0) {

    FUN_0019d3f0(0x68ebe8,0x32);

  }

  iVar1 = (int)DAT_007ce36c;

  uVar3 = FUN_00267390();

  fVar6 = (float)*(int *)(iVar1 + 0x810) / 16.0;

  fVar8 = (float)*(int *)(iVar1 + 0x814) / 10.0;

  iVar2 = FUN_0021cca0(uVar3,0);

  fStack_30 = 41.0;

  fStack_2c = 379.0;

  fStack_28 = (float)*(int *)(iVar2 + 0xc);

  fStack_24 = (float)*(int *)(iVar2 + 0x10);

  FUN_0021d8e0(iVar1 + 0x10,&fStack_30);

  uStack_4 = 0xff;

  uStack_3 = 0xff;

  uStack_2 = 0xff;

  fVar7 = fVar6 * 255.0;

  if (fVar7 < 2.1474836e+09) {

    uStack_1 = (u8)(int)fVar7;

  }

  else {

    uStack_1 = (u8)(int)(fVar7 - 2.1474836e+09);

  }

  FUN_0021d950(iVar1 + 0x10,&uStack_4);

  iVar5 = *(int *)(iVar1 + 0x818);

  iVar2 = FUN_0021cca0(uVar3,1);

  fVar10 = DAT_007caee8 * ((float)iVar5 / 10.0);

  fVar6 = fVar6 * fVar8 * 20.0;

  fVar7 = fVar7 * fVar8;

  for (iVar5 = 0; iVar5 < 7; iVar5 = iVar5 + 1) {

    iVar4 = iVar1 + iVar5 * 0x100 + 0x110;

    fVar9 = fVar10 + (DAT_007caee8 * (float)iVar5) / 7.0;

    fVar8 = (float)FUN_0052e6d8(fVar9);

    fVar8 = fVar6 * fVar8;

    fVar9 = (float)FUN_0052e878(fVar9);

    fStack_30 = fVar8 + 35.0 + 6.0 + 4.0;

    fStack_2c = fVar6 * fVar9 + 366.0 + 13.0 + 4.0;

    fStack_28 = (float)*(int *)(iVar2 + 0xc);

    fStack_24 = (float)*(int *)(iVar2 + 0x10);

    FUN_0021d8e0(iVar4,&fStack_30);

    uStack_4 = 0xff;

    uStack_3 = 0xff;

    uStack_2 = 0xff;

    if (fVar7 < 2.1474836e+09) {

      uStack_1 = (u8)(int)fVar7;

    }

    else {

      uStack_1 = (u8)(int)(fVar7 - 2.1474836e+09);

    }

    FUN_0021d950(iVar4,&uStack_4);

  }

  return;

}
