#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u32 DAT_0095b790;
extern u32 DAT_0095b794;
extern u32 DAT_0095b798;
extern u32 DAT_0095b7e0[];
extern u32 DAT_0095be74;
extern u32 LAB_003c29b0;
extern u32 LAB_003c2c00;
extern u32 LAB_003c2db0;
extern u32 LAB_003c3274;

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
u32 FUN_003c2570(u64 param_1);
u32 FUN_003c2630(u32 param_1,u64 param_2,u64 param_3);
u32 * FUN_003c2770(void);
u8 * FUN_003c2780(u32 param_1);
u32  FUN_003c28a0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5,int *param_6);
u32 FUN_003c2ab0(u32 param_1,u32 param_2);
u32 FUN_003c2b40(int *param_1,int *param_2);
u8 FUN_003c2c50(u32 param_1);
u32 FUN_003c2df0(u32 param_1);
u32 * FUN_003c2ee0(long param_1);
u32 * FUN_003c3050(u64 param_1);
u8 FUN_003c30b0(void);
u8 FUN_003c3120(void);
u32 FUN_003c3190(int *param_1);
u32 * FUN_003c3390(void);

/* Region call-cast macros */
#define FUN_003c2570(...) ((u32 (*)(...))FUN_003c2570)(__VA_ARGS__)
#define FUN_003c2630(...) ((u32 (*)(...))FUN_003c2630)(__VA_ARGS__)
#define FUN_003c2770(...) ((u32 * (*)(...))FUN_003c2770)(__VA_ARGS__)
#define FUN_003c2780(...) ((u8 * (*)(...))FUN_003c2780)(__VA_ARGS__)
#define FUN_003c28a0(...) ((u32 (*)(...))FUN_003c28a0)(__VA_ARGS__)
#define FUN_003c2ab0(...) ((u32 (*)(...))FUN_003c2ab0)(__VA_ARGS__)
#define FUN_003c2b40(...) ((u32 (*)(...))FUN_003c2b40)(__VA_ARGS__)
#define FUN_003c2c50(...) ((u8 (*)(...))FUN_003c2c50)(__VA_ARGS__)
#define FUN_003c2df0(...) ((u32 (*)(...))FUN_003c2df0)(__VA_ARGS__)
#define FUN_003c2ee0(...) ((u32 * (*)(...))FUN_003c2ee0)(__VA_ARGS__)
#define FUN_003c3050(...) ((u32 * (*)(...))FUN_003c3050)(__VA_ARGS__)
#define FUN_003c30b0(...) ((u8 (*)(...))FUN_003c30b0)(__VA_ARGS__)
#define FUN_003c3120(...) ((u8 (*)(...))FUN_003c3120)(__VA_ARGS__)
#define FUN_003c3190(...) ((u32 (*)(...))FUN_003c3190)(__VA_ARGS__)
#define FUN_003c3390(...) ((u32 * (*)(...))FUN_003c3390)(__VA_ARGS__)

#undef FUN_003c2570
// FUN_003C2570 NONMATCHING


u32 FUN_003c2570(u64 param_1)



{

  u32 uVar1;

  long lVar2;

  long lVar3;

  u8 auStack_4 [4];

  

  lVar2 = FUN_001720c0(param_1,auStack_4);

  lVar3 = FUN_00172a50((short)param_1);

  if (lVar3 == 0) {

    FUN_0019d3f0("comuSasoi.c",0x104);

  }

  if (lVar2 < 2) {

    uVar1 = 0;

  }

  else if (lVar2 < 3) {

    uVar1 = 1;

  }

  else if (lVar2 < 4) {

    uVar1 = 2;

  }

  else {

    uVar1 = 3;

  }

  return uVar1;

}
#define FUN_003c2570(...) ((u32 (*)(...))FUN_003c2570)(__VA_ARGS__)
#undef FUN_003c2630
// FUN_003C2630 NONMATCHING


u32 FUN_003c2630(u32 param_1,u64 param_2,u64 param_3)



{

  u32 uVar1;

  u64 uVar2;

  u64 uVar3;

  long lVar4;

  int iVar5;

  u32 auStack_80 [31];

  int iStack_4;

  

  iStack_4 = 0;

  uVar2 = FUN_0017d920();

  uVar3 = FUN_0017da40();

  FUN_00521408(0x95b7e0,0,0x698);

  DAT_0095be74 = param_1;

  lVar4 = FUN_003c28a0(uVar2,uVar3,param_2,param_3,auStack_80,&iStack_4);

  if (lVar4 == 0) {

    uVar1 = 0;

  }

  else {

    DAT_0095b7e0[0] = iStack_4;

    for (iVar5 = 0; iVar5 < iStack_4; iVar5 = iVar5 + 1) {

      lVar4 = FUN_003be8e0(auStack_80[iVar5],iVar5 * 0x38 + 0x95b7e4);

      if (lVar4 == 0) {

        FUN_0019d3f0("comuSasoi.c",0x34a);

      }

    }

    uVar1 = 1;

  }

  return uVar1;

}
#define FUN_003c2630(...) ((u32 (*)(...))FUN_003c2630)(__VA_ARGS__)
#undef FUN_003c2770
// FUN_003C2770

u32 *FUN_003c2770(void)
{
  return DAT_0095b7e0;
}
#define FUN_003c2770(...) ((u32 * (*)(...))FUN_003c2770)(__VA_ARGS__)
#undef FUN_003c2780
// FUN_003C2780 NONMATCHING


u8 * FUN_003c2780(u32 param_1)



{

  char cVar1;

  int iVar2;

  int iVar3;

  long lVar4;

  u8 *pbVar5;

  int iVar6;

  

  iVar2 = FUN_003bd870();

  iVar2 = *(int *)(iVar2 + 0x674);

  iVar3 = FUN_003bd870();

  iVar3 = *(int *)(iVar3 + 0x678);

  iVar6 = 0;

  do {

    if (iVar3 <= iVar6) {

      FUN_0019d3f0("comuSasoi.c",0x3cd);

      return (u8 *)0x0;

    }

    pbVar5 = (u8 *)(iVar2 + iVar6 * 0xc);

    if (*pbVar5 == param_1) {

      lVar4 = FUN_0016e100(*pbVar5);

      if (lVar4 == 0) {

        FUN_0019d3f0("comuSasoi.c",0x3c1);

      }

      cVar1 = FUN_0016dba0((short)param_1);

      if (((long)(u32)pbVar5[1] <= (long)cVar1) && ((long)cVar1 <= (long)(u32)pbVar5[2])) {

        return pbVar5;

      }

    }

    iVar6 = iVar6 + 1;

  } while( 1 );

}
#define FUN_003c2780(...) ((u8 * (*)(...))FUN_003c2780)(__VA_ARGS__)
#undef FUN_003c28a0
// FUN_003C28A0 NONMATCHING


u32

FUN_003c28a0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5,int *param_6)



{

  u8 bVar1;

  char cVar2;

  u32 uVar3;

  long lVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int aiStack_80 [32];

  

  iVar7 = 0;

  iVar6 = 0;

  do {

    if (0x1d < iVar6) {

      if (iVar7 == 0) {

        uVar3 = 0;

      }

      else {

        for (iVar6 = 0; iVar6 < iVar7; iVar6 = iVar6 + 1) {

          *(int *)(param_5 + iVar6 * 4) = aiStack_80[iVar6];

        }

        *param_6 = iVar7;

        uVar3 = 1;

      }

      return uVar3;

    }

    lVar4 = FUN_0016e100((short)iVar6);

    if ((((lVar4 != 0) && (cVar2 = FUN_0016dba0((short)iVar6), cVar2 != '\n')) &&

        (lVar4 = FUN_003c40f0(iVar6), lVar4 != 0)) &&

       ((lVar4 = FUN_001717c0(iVar6), lVar4 != 1 && (lVar4 = FUN_00172160(iVar6), lVar4 != 1)))) {

      for (iVar5 = 0; iVar5 < param_4; iVar5 = iVar5 + 1) {

        if (iVar6 == *(int *)(param_3 + iVar5 * 4)) {

          bVar1 = 1;

          goto LAB_003c29b0;

        }

      }

      bVar1 = 0;

LAB_003c29b0:

      if (((!bVar1) && (lVar4 = FUN_003c23f0(iVar6,param_1,param_2), lVar4 != 1)) &&

         ((lVar4 = FUN_00172660(iVar6), lVar4 != 0 &&

          (lVar4 = FUN_003951d0(iVar6 + 0x990), lVar4 != 1)))) {

        aiStack_80[iVar7] = iVar6;

        iVar7 = iVar7 + 1;

      }

    }

    iVar6 = iVar6 + 1;

  } while( 1 );

}
#define FUN_003c28a0(...) ((u32 (*)(...))FUN_003c28a0)(__VA_ARGS__)
#undef FUN_003c2ab0
// FUN_003C2AB0 NONMATCHING


u32 FUN_003c2ab0(u32 param_1,u32 param_2)



{

  int iVar1;

  u8 *pbVar2;

  int iVar3;

  

  iVar1 = FUN_003bdd50();

  iVar3 = 0;

  while( 1 ) {

    if (*(int *)(iVar1 + 0xc) <= iVar3) {

      return 0;

    }

    pbVar2 = (u8 *)(*(int *)(iVar1 + 8) + iVar3 * 2);

    if ((param_1 == *pbVar2) && (param_2 == pbVar2[1])) break;

    iVar3 = iVar3 + 1;

  }

  return 1;

}
#define FUN_003c2ab0(...) ((u32 (*)(...))FUN_003c2ab0)(__VA_ARGS__)
#undef FUN_003c2b40
// FUN_003C2B40 NONMATCHING


u32 FUN_003c2b40(int *param_1,int *param_2)



{

  u8 bVar1;

  u16 uVar2;

  u16 uVar3;

  int iVar4;

  u32 uVar5;

  long lVar6;

  u8 *pbVar7;

  int iVar8;

  u16 uStack_4;

  u16 uStack_2;

  

  uStack_2 = 0;

  uStack_4 = 0;

  FUN_0017d920();

  FUN_0017da40();

  lVar6 = FUN_0017ddf0(&uStack_2,&uStack_4);

  uVar3 = uStack_2;

  uVar2 = uStack_4;

  if (lVar6 == 0) {

    uVar5 = 0;

  }

  else {

    iVar4 = FUN_003bdd50();

    for (iVar8 = 0; iVar8 < *(int *)(iVar4 + 0xc); iVar8 = iVar8 + 1) {

      pbVar7 = (u8 *)(*(int *)(iVar4 + 8) + iVar8 * 2);

      if ((uVar3 == *pbVar7) && (uVar2 == pbVar7[1])) {

        bVar1 = 1;

        goto LAB_003c2c00;

      }

    }

    bVar1 = 0;

LAB_003c2c00:

    uVar5 = 1;

    if (bVar1) {

      uVar5 = 0;

    }

    else {

      *param_1 = (int)(short)uStack_2;

      *param_2 = (int)(short)uStack_4;

    }

  }

  return uVar5;

}
#define FUN_003c2b40(...) ((u32 (*)(...))FUN_003c2b40)(__VA_ARGS__)
#undef FUN_003c2c50
// FUN_003C2C50 NONMATCHING


u8 FUN_003c2c50(u32 param_1)



{

  char cVar1;

  u8 bVar2;

  int *piVar3;

  long lVar4;

  u16 uVar5;

  int iVar6;

  short sStack_2;

  

  lVar4 = FUN_00172c50(&sStack_2);

  if ((lVar4 == 0) || (param_1 != (long)sStack_2)) {

    uVar5 = (u16)param_1;

    lVar4 = FUN_0016e100(uVar5);

    if (lVar4 == 0) {

      bVar2 = 0;

    }

    else {

      lVar4 = FUN_001717c0(param_1);

      if (lVar4 == 1) {

        bVar2 = 0;

      }

      else {

        lVar4 = FUN_00172160(param_1);

        if (lVar4 == 1) {

          bVar2 = 0;

        }

        else {

          cVar1 = FUN_0016dba0(uVar5);

          if (cVar1 == '\x01') {

            bVar2 = 0;

          }

          else {

            cVar1 = FUN_0016dba0(uVar5);

            if (cVar1 == '\n') {

              bVar2 = 0;

            }

            else {

              piVar3 = (int *)FUN_003bdd50();

              for (iVar6 = 0; iVar6 < piVar3[1]; iVar6 = iVar6 + 1) {

                if (param_1 == *(u8 *)(*piVar3 + iVar6 * 0x18)) {

                  bVar2 = 1;

                  goto LAB_003c2db0;

                }

              }

              bVar2 = 0;

LAB_003c2db0:

              if (bVar2) {

                lVar4 = FUN_003951d0((int)param_1 + 0x960);

                bVar2 = lVar4 != 1;

              }

              else {

                bVar2 = 0;

              }

            }

          }

        }

      }

    }

  }

  else {

    bVar2 = 0;

  }

  return bVar2;

}
#define FUN_003c2c50(...) ((u8 (*)(...))FUN_003c2c50)(__VA_ARGS__)
#undef FUN_003c2df0
// FUN_003C2DF0 NONMATCHING


u32 FUN_003c2df0(u32 param_1)



{

  int iVar1;

  u32 uVar2;

  u32 uVar3;

  u8 *pbVar4;

  int iVar5;

  

  iVar1 = FUN_003bd870();

  uVar2 = FUN_0017d920();

  uVar3 = FUN_0017da40();

  iVar5 = 0;

  while( 1 ) {

    if (*(int *)(iVar1 + 0x654) <= iVar5) {

      return 0;

    }

    pbVar4 = (u8 *)(*(int *)(iVar1 + 0x650) + iVar5 * 3);

    if (((uVar2 == *pbVar4) && (uVar3 == pbVar4[1])) && (param_1 == pbVar4[2])) break;

    if (((uVar2 == *pbVar4) && (uVar3 == pbVar4[1])) && (pbVar4[2] == 0xff)) {

      return 1;

    }

    iVar5 = iVar5 + 1;

  }

  return 1;

}
#define FUN_003c2df0(...) ((u32 (*)(...))FUN_003c2df0)(__VA_ARGS__)
#undef FUN_003c2ee0
// FUN_003C2EE0 NONMATCHING


u32 * FUN_003c2ee0(long param_1)



{

  u8 bVar1;

  u32 *puVar2;

  long lVar3;

  int iVar4;

  int iVar5;

  short sStack_4;

  short sStack_2;

  

  FUN_001717b0();

  iVar5 = 0;

  iVar4 = 0;

  DAT_0095b790 = 0;

  if (0x1d < param_1) {

    FUN_0019d3f0("comuSasoi.c",0x558);

  }

  lVar3 = FUN_003c2c50(param_1);

  if (lVar3 == 0) {

    puVar2 = (u32 *)0x0;

  }

  else {

    sStack_2 = 0;

    sStack_4 = 0;

    FUN_0017d920();

    FUN_0017da40();

    lVar3 = FUN_0017ddf0(&sStack_2,&sStack_4);

    if (lVar3 == 0) {

      bVar1 = 0;

    }

    else {

      lVar3 = FUN_003c2ab0(sStack_2,sStack_4);

      bVar1 = 1;

      if (lVar3 == 1) {

        bVar1 = 0;

      }

      else {

        iVar5 = (int)sStack_2;

        iVar4 = (int)sStack_4;

      }

    }

    if (bVar1) {

      lVar3 = FUN_003be2a0(0,0,param_1,7,0x95b79c);

      if (lVar3 == 0) {

        puVar2 = (u32 *)0x0;

      }

      else {

        DAT_0095b790 = 1;

        puVar2 = &DAT_0095b790;

        DAT_0095b794 = iVar5;

        DAT_0095b798 = iVar4;

      }

    }

    else {

      puVar2 = (u32 *)0x0;

    }

  }

  return puVar2;

}
#define FUN_003c2ee0(...) ((u32 * (*)(...))FUN_003c2ee0)(__VA_ARGS__)
#undef FUN_003c3050
// FUN_003C3050 NONMATCHING


u32 * FUN_003c3050(u64 param_1)



{

  u32 *puVar1;

  long lVar2;

  

  lVar2 = FUN_003be2a0(0,0,param_1,7,0x95b79c);

  if (lVar2 == 0) {

    puVar1 = (u32 *)0x0;

  }

  else {

    DAT_0095b790 = 1;

    puVar1 = &DAT_0095b790;

  }

  return puVar1;

}
#define FUN_003c3050(...) ((u32 * (*)(...))FUN_003c3050)(__VA_ARGS__)
#undef FUN_003c30b0
// FUN_003C30B0 NONMATCHING


u8 FUN_003c30b0(void)



{

  u8 bVar1;

  

  bVar1 = DAT_0095b790 != 0;

  if (bVar1) {

    FUN_00172b80(DAT_0095b794,DAT_0095b798,0x95b79c,1);

    DAT_0095b790 = 0;

  }

  return bVar1;

}
#define FUN_003c30b0(...) ((u8 (*)(...))FUN_003c30b0)(__VA_ARGS__)
#undef FUN_003c3120
// FUN_003C3120 NONMATCHING


u8 FUN_003c3120(void)



{

  u8 bVar1;

  

  bVar1 = DAT_0095b790 != 0;

  if (bVar1) {

    FUN_00172b80(DAT_0095b794,DAT_0095b798,0x95b79c,0);

    DAT_0095b790 = 0;

  }

  return bVar1;

}
#define FUN_003c3120(...) ((u8 (*)(...))FUN_003c3120)(__VA_ARGS__)
#undef FUN_003c3190
// FUN_003C3190 NONMATCHING


u32 FUN_003c3190(int *param_1)



{

  u8 bVar1;

  int iVar2;

  int iVar3;

  u32 uVar4;

  u32 uVar5;

  u32 uVar6;

  long lVar7;

  u8 *pbVar8;

  int iVar9;

  int aiStack_80 [31];

  u8 auStack_2 [2];

  

  iVar3 = 0;

  uVar5 = FUN_0017d920();

  uVar6 = FUN_0017da40();

  DAT_0095b790 = 0;

  lVar7 = FUN_00395230(100);

  if (lVar7 == 0) {

    uVar4 = 0;

  }

  else {

    lVar7 = FUN_00172c50(auStack_2);

    if (lVar7 != 0) {

      FUN_0019d3f0("comuSasoi.c",0x5b5);

    }

    iVar2 = FUN_003bdd50();

    for (iVar9 = 0; iVar9 < *(int *)(iVar2 + 0xc); iVar9 = iVar9 + 1) {

      pbVar8 = (u8 *)(*(int *)(iVar2 + 8) + iVar9 * 2);

      if ((uVar5 == *pbVar8) && (uVar6 == pbVar8[1])) {

        bVar1 = 1;

        goto LAB_003c3274;

      }

    }

    bVar1 = 0;

LAB_003c3274:

    if (bVar1) {

      uVar4 = 0;

    }

    else {

      for (iVar2 = 0; iVar2 < 0x1e; iVar2 = iVar2 + 1) {

        lVar7 = FUN_003bebd0(iVar2);

        if (((lVar7 != 1) && (lVar7 = FUN_003c2c50(iVar2), lVar7 != 0)) &&

           (lVar7 = FUN_003c2df0(iVar2), lVar7 != 1)) {

          aiStack_80[iVar3] = iVar2;

          iVar3 = iVar3 + 1;

        }

      }

      if (iVar3 == 0) {

        uVar4 = 0;

      }

      else {

        iVar3 = FUN_00395200(iVar3);

        iVar3 = aiStack_80[iVar3];

        *param_1 = iVar3;

        lVar7 = FUN_003be2a0(0,0,iVar3,7,0x95b79c);

        if (lVar7 == 0) {

          FUN_0019d3f0("comuSasoi.c",0x5d6);

        }

        uVar4 = 1;

        DAT_0095b790 = 1;

      }

    }

  }

  return uVar4;

}
#define FUN_003c3190(...) ((u32 (*)(...))FUN_003c3190)(__VA_ARGS__)
#undef FUN_003c3390
// FUN_003C3390 NONMATCHING


u32 * FUN_003c3390(void)



{

  u32 *puVar1;

  

  if (DAT_0095b790 == 0) {

    puVar1 = (u32 *)0x0;

  }

  else {

    puVar1 = &DAT_0095b790;

  }

  return puVar1;

}
#define FUN_003c3390(...) ((u32 * (*)(...))FUN_003c3390)(__VA_ARGS__)
