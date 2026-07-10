#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_00251060(void);
void FUN_002510d0(void);
void FUN_002518b0(long param_1);
u32 FUN_002519d0(void);
void FUN_00251a20(void);
extern int iGpffffb654;
extern void FUN_0019d3f0(const char* file, s32 line);
extern const char DAT_0068e9c0[];
#define FUN_0019d3f0(file, line) FUN_0019d3f0((const char*)(file), line)

static u32* sBpTut654; // puGpffffb654

// FUN_00251010
void bpTut00251010(void* param_1, s32 param_2)
{
    *(s32*)((u8*)param_1 + 0x10) += param_2;
    *(u32*)((u8*)param_1 + 8) |= 2;
}

// FUN_00251030
void bpTut00251030(void* param_1)
{
    *(u32*)((u8*)param_1 + 8) |= 2;
}

// FUN_00251050
void bpTut00251050(u32* param_1)
{
    *param_1 = 0;
    sBpTut654 = param_1;
}

/* Recovered battle-misc harvest: 0x00251060-0x00251A20 */
// FUN_00251060


void FUN_00251060(void)



{

  if (sBpTut654 == (u32 *)0x0) {

    FUN_0019d3f0(DAT_0068e9c0, 0x39);

  }

  if ((~*sBpTut654 & 1) == 0) {

    FUN_0019d3f0(DAT_0068e9c0, 0x49);

  }

  sBpTut654 = (u32 *)0x0;

  return;

}

// FUN_002510D0 NONMATCHING


void FUN_002510d0(void)



{

  u32 *puVar1;

  u32 uVar2;

  long lVar3;

  u64 uVar4;

  

  if (sBpTut654 == (u32 *)0x0) {

    FUN_0019d3f0(0x68e9c0,0x39);

  }

  puVar1 = sBpTut654;

  if ((~*sBpTut654 & 1) == 0) {

    if (sBpTut654[1] == 1) {

      switch(sBpTut654[3]) {

      case 0:

        FUN_003c7990();

        lVar3 = FUN_003c7850();

        if (lVar3 == 0) {

          lVar3 = FUN_003c7610();

          if (lVar3 == 1) {

            FUN_003c7650();

            uVar2 = puVar1[2];

            if (uVar2 == 3) {

              FUN_003c7430(0x14);

            }

            else if (uVar2 == 2) {

              FUN_003c7430(0xf);

            }

            else if (uVar2 == 1) {

              FUN_003c7430(10);

            }

            else if (uVar2 == 0) {

              FUN_003c7430(4);

            }

            puVar1[3] = 2;

          }

          else if (lVar3 == 0) {

            FUN_003c7650();

            uVar2 = puVar1[2];

            if (uVar2 == 1) {

              FUN_003c7430(7);

              puVar1[3] = 3;

            }

            else if (((uVar2 == 3) || (uVar2 == 2)) || (uVar2 == 0)) {

              if (uVar2 == 3) {

                FUN_003c7430(0x12);

              }

              else if (uVar2 == 2) {

                FUN_003c7430(0xd);

              }

              else if (uVar2 == 0) {

                FUN_003c7430();

              }

              uVar2 = puVar1[2];

              if (uVar2 == 3) {

                FUN_003c74e0(0x13);

              }

              else if (uVar2 == 2) {

                FUN_003c74e0(0xe);

              }

              else if (uVar2 == 0) {

                FUN_003c74e0();

              }

              FUN_003c7560(0);

              puVar1[3] = 1;

            }

          }

        }

        break;

      case 1:

        FUN_003c7990();

        lVar3 = FUN_003c7850();

        if (lVar3 == 0) {

          lVar3 = FUN_003c7610();

          if (lVar3 == 0) {

            FUN_003c7650(1);

            uVar2 = puVar1[2];

            if (uVar2 == 3) {

              FUN_003c7430(0x14);

            }

            else if (uVar2 == 2) {

              FUN_003c7430(0xf);

            }

            else if (uVar2 == 1) {

              FUN_003c7430(10);

            }

            else if (uVar2 == 0) {

              FUN_003c7430(4);

            }

            puVar1[3] = 2;

          }

          else if (lVar3 == 1) {

            FUN_003c7650();

            uVar2 = puVar1[2];

            if (uVar2 == 1) {

              FUN_003c7430(7);

              puVar1[3] = 3;

            }

            else if (((uVar2 == 3) || (uVar2 == 2)) || (uVar2 == 0)) {

              if (uVar2 == 3) {

                FUN_003c7430(0x12);

              }

              else if (uVar2 == 2) {

                FUN_003c7430(0xd);

              }

              else if (uVar2 == 0) {

                FUN_003c7430();

              }

              uVar2 = puVar1[2];

              if (uVar2 == 3) {

                FUN_003c74e0(0x13);

              }

              else if (uVar2 == 2) {

                FUN_003c74e0(0xe);

              }

              else if (uVar2 == 0) {

                FUN_003c74e0();

              }

              FUN_003c7560(0);

              puVar1[3] = 1;

            }

          }

        }

        break;

      case 2:

        FUN_003c7990();

        lVar3 = FUN_003c7850();

        if (lVar3 == 0) {

          FUN_003c7650(1);

          FUN_00111500(puVar1[4]);

          puVar1[3] = 7;

        }

        break;

      case 3:

        FUN_003c7990();

        lVar3 = FUN_003c7850();

        if (lVar3 == 0) {

          FUN_003c7650(1);

          FUN_00111500(puVar1[4]);

          FUN_003c77a0();

          puVar1[3] = 4;

        }

        break;

      case 4:

        lVar3 = FUN_00195460(sBpTut654[4]);

        if (lVar3 == 0) {

          uVar4 = FUN_0021c8b0(1);

          FUN_003c94e0(uVar4);

          FUN_003c9790(0);

          puVar1[3] = 5;

        }

        break;

      case 5:

        FUN_003c7990();

        lVar3 = FUN_003c7850();

        if (lVar3 == 0) {

          FUN_003c7650(1);

          FUN_003c77a0();

          uVar4 = FUN_0021c8b0(0);

          FUN_003c72d0(uVar4);

          FUN_003c7430(8);

          FUN_003c74e0(9);

          FUN_003c7560(0);

          uVar2 = FUN_00110f80(0,0x200040004);

          puVar1[4] = uVar2;

          puVar1[3] = 6;

        }

        break;

      case 6:

        lVar3 = FUN_001114b0(sBpTut654[4]);

        if (lVar3 != 0) {

          FUN_00111530(puVar1[4]);

          puVar1[3] = 1;

        }

        break;

      case 7:

        lVar3 = FUN_00195460(sBpTut654[4]);

        if (lVar3 == 0) {


          *puVar1 = *puVar1 & 0xfffffffe;

        }

      }

    }

    else if (((sBpTut654[1] == 0) && (lVar3 = FUN_0021c860(), lVar3 == 0)) &&

            (lVar3 = FUN_001114b0(puVar1[4]), lVar3 != 0)) {

      uVar4 = FUN_0021c8b0(0);

      FUN_003c72d0(uVar4);

      FUN_00111530(puVar1[4]);

      uVar2 = puVar1[2];

      if (uVar2 == 3) {

        FUN_003c7430(0x10);

      }

      else if (uVar2 == 2) {

        FUN_003c7430(0xb);

      }

      else if (uVar2 == 1) {

        FUN_003c7430(5);

      }

      else if (uVar2 == 0) {

        FUN_003c7430(0);

      }

      uVar2 = puVar1[2];

      if (uVar2 == 3) {

        FUN_003c74e0(0x11);

      }

      else if (uVar2 == 2) {

        FUN_003c74e0(0xc);

      }

      else if (uVar2 == 1) {

        FUN_003c74e0(6);

      }

      else if (uVar2 == 0) {

        FUN_003c74e0();

      }

      FUN_003c7560(0);

      puVar1[3] = 0;

      puVar1[1] = 1;

    }

  }

  return;

}

// FUN_002518B0 NONMATCHING


void FUN_002518b0(long param_1)



{

  u32 *puVar1;

  u32 uVar2;

  

  if (sBpTut654 == (u32 *)0x0) {

    FUN_0019d3f0(0x68e9c0,0x39);

  }

  puVar1 = sBpTut654;

  if (param_1 == 3) {

    FUN_0016f1f0(0x130a,1);

  }

  else if (param_1 == 2) {

    FUN_0016f1f0(0x1309,1);

  }

  else if (param_1 == 1) {

    FUN_0016f1f0(0x1308);

  }

  else if (param_1 == 0) {

    FUN_0016f1f0(0x1307);

  }

  FUN_0021c7f0();

  uVar2 = FUN_00110f80(0,0x200040004);

  puVar1[4] = uVar2;

  puVar1[1] = 0;

  *puVar1 = *puVar1 | 1;

  puVar1[2] = (u32)param_1;

  return;

}

// FUN_002519D0


u32 FUN_002519d0(void)



{

  if (sBpTut654 == (u32 *)0x0) {
    FUN_0019d3f0(DAT_0068e9c0,0x39);

  }

  return *sBpTut654 & 1;

}

// FUN_00251A20


void FUN_00251a20(void)



{

  if (iGpffffb654 == 0) {
    FUN_0019d3f0(DAT_0068e9c0,0x39);

  }

  FUN_003c77a0();

  FUN_0021c930();

  return;

}
