#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_00251a80(void);
void FUN_00251e10(void);
u32 FUN_00251e80(void);
void FUN_00251ed0(void);
extern int iGpffffb658;

static u32* sBpTutaWork; // puGpffffb658

// FUN_00251a70
void bpTuta00251a70(u32* param_1)
{
    *param_1 = 0;
    sBpTutaWork = param_1;
}

/* Recovered battle-misc harvest: 0x00251A80-0x00251ED0 */
// FUN_00251A80 NONMATCHING


void FUN_00251a80(void)



{

  u32 uVar1;

  u32 *puVar2;

  long lVar3;

  u64 uVar4;

  u32 uVar5;

  

  if (sBpTutaWork == (u32 *)0x0) {

    FUN_0019d3f0(0x68e9d0,0x31);

  }

  puVar2 = sBpTutaWork;

  if ((~*sBpTutaWork & 1) == 0) {

    if (sBpTutaWork[1] == 1) {

      uVar1 = sBpTutaWork[2];

      if (uVar1 == 3) {

        FUN_003c7990();

        lVar3 = FUN_003c7850();

        if (lVar3 == 0) {

          FUN_003c7650(1);

          FUN_003c77a0();


          *puVar2 = *puVar2 & 0xfffffffe;

        }

      }

      else if (uVar1 == 2) {

        FUN_003c7990();

        lVar3 = FUN_003c7850();

        if (lVar3 == 0) {

          FUN_003c7650(1);

          lVar3 = FUN_0017d800();

          if (lVar3 == 0) {


            *puVar2 = *puVar2 & 0xfffffffe;

          }

          else {

            uVar4 = FUN_0021c8b0(2);

            FUN_003c94e0(uVar4);

            FUN_003c9790(8);

            puVar2[2] = 3;

          }

        }

      }

      else if (uVar1 == 1) {

        FUN_003c7990();

        lVar3 = FUN_003c7850();

        if (lVar3 == 0) {

          lVar3 = FUN_003c7610();

          if (lVar3 == 1) {

            FUN_003c7650();

            lVar3 = FUN_0017d800();

            if (lVar3 == 0) {

              uVar5 = 4;

            }

            else {

              uVar5 = 7;

            }

            FUN_003c7430(uVar5);

            puVar2[2] = 2;

          }

          else if (lVar3 == 0) {

            FUN_003c7650();

            lVar3 = FUN_0017d800();

            if (lVar3 == 0) {

              uVar5 = 2;

            }

            else {

              uVar5 = 6;

            }

            FUN_003c7430(uVar5);

            FUN_003c74e0(3);

            FUN_003c7560(1);

            puVar2[2] = 1;

          }

        }

      }

      else if (uVar1 == 0) {

        FUN_003c7990();

        lVar3 = FUN_003c7850();

        if (lVar3 == 0) {

          lVar3 = FUN_003c7610();

          if (lVar3 == 1) {

            FUN_003c7650();

            lVar3 = FUN_0017d800();

            if (lVar3 == 0) {

              uVar5 = 4;

            }

            else {

              uVar5 = 7;

            }

            FUN_003c7430(uVar5);

            puVar2[2] = 2;

          }

          else if (lVar3 == 0) {

            FUN_003c7650();

            lVar3 = FUN_0017d800();

            if (lVar3 == 0) {

              uVar5 = 2;

            }

            else {

              uVar5 = 6;

            }

            FUN_003c7430(uVar5);

            FUN_003c74e0(3);

            puVar2[2] = 1;

          }

        }

      }

    }

    else if ((sBpTutaWork[1] == 0) && (lVar3 = FUN_0021c860(), lVar3 == 0)) {

      puVar2[1] = 1;

      uVar4 = FUN_0021c8b0(2);

      FUN_003c72d0(uVar4);

      lVar3 = FUN_0017d800();

      if (lVar3 == 0) {

        uVar4 = 0;

      }

      else {

        uVar4 = 5;

      }

      FUN_003c7430(uVar4);

      FUN_003c74e0(1);

      FUN_003c7560(0);

      puVar2[2] = 0;

    }

  }

  return;

}

// FUN_00251E10 NONMATCHING


void FUN_00251e10(void)



{

  u32 *puVar1;

  

  if (sBpTutaWork == (u32 *)0x0) {

    FUN_0019d3f0(0x68e9d0,0x31);

  }

  puVar1 = sBpTutaWork;

  FUN_0016f1f0(0x1306,1);

  FUN_0021c7f0();

  puVar1[1] = 0;

  *puVar1 = *puVar1 | 1;

  return;

}

// FUN_00251E80 NONMATCHING


u32 FUN_00251e80(void)



{

  if (sBpTutaWork == (u32 *)0x0) {

    FUN_0019d3f0(0x68e9d0,0x31);

  }

  return *sBpTutaWork & 1;

}

// FUN_00251ED0 NONMATCHING


void FUN_00251ed0(void)



{

  if (iGpffffb658 == 0) {

    FUN_0019d3f0(0x68e9d0,0x31);

  }

  FUN_003c77a0();

  FUN_0021c930();

  return;

}
