#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u32 D_0095b790[];
extern u8 DAT_0095b79c[];
#pragma alias DAT_0095b790_abs DAT_0095b790
extern u32 DAT_0095b790_abs[];
extern u32 DAT_0095b790;
extern u32 DAT_0095b794;
extern u32 DAT_0095b798;
extern u32 DAT_0095b7e0[];
#pragma alias DAT_0095b7e0_abs DAT_0095b7e0
extern u8 DAT_0095b7e0_abs[];
#pragma alias DAT_0095be74_abs DAT_0095be74
extern u8 DAT_0095be74_abs[];
extern u32 DAT_0095be74;
extern u32 LAB_003c29b0;
extern u32 LAB_003c2c00;
extern u32 LAB_003c2db0;
extern u32 LAB_003c3274;
#pragma alias FUN_001720c0 func_001720c0
#pragma alias FUN_00172a50 func_00172a50
#pragma alias FUN_0019d3f0 func_0019d3f0
extern s32 FUN_001720c0(u64 param_1, u8 *out);
extern s32 FUN_00172a50(s16 param_1);
extern void FUN_0019d3f0(const char *file, s32 line);
extern u32 FUN_003bd870(void);
extern s32 FUN_0017d920(void);
extern s32 FUN_0017da40(void);
extern s32 FUN_00521408(u32 dst, s32 value, s32 size);
extern s32 FUN_003be8e0(u32 id, u8 *entry);
extern s32 FUN_003c40f0(s32 id);
extern s32 FUN_001717c0(s32 id);
extern s32 FUN_00172160(s32 id);
extern s32 FUN_003c23f0(s32 id, s32 first, s32 second);
extern s32 FUN_00172660(s32 id);
extern s32 FUN_003951d0(s32 id);
extern s32 FUN_003bdd50(void);
extern s32 FUN_00172c50(void *out);
extern s32 FUN_0017ddf0(void *first, void *second);
extern s32 FUN_003be2a0(s32 arg0, s32 arg1, u64 id, s32 arg3, u32 arg4);
extern s32 FUN_00395200(s32 max);
extern s32 FUN_001717b0(void);
extern s32 FUN_00395230(s32 max);
extern void FUN_00172b80(u32 first, u32 second, u32 third, u32 fourth);
extern s32 FUN_0016e100(s16 id);
extern s8 FUN_0016dba0(s16 id);
#pragma alias FUN_003c28a0_call FUN_003c28a0
extern u32 FUN_003c28a0_call(u32, u32, u32, u32, u32 *, s32 *);
#pragma alias FUN_003c2ab0_call FUN_003c2ab0
extern u32 FUN_003c2ab0_call(u32, u32);
#pragma alias FUN_003c2c50_call FUN_003c2c50
extern u8 FUN_003c2c50_call(u32);
#pragma alias FUN_003c2df0_call FUN_003c2df0
extern u32 FUN_003c2df0_call(u32);

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
u32 FUN_003c2570(u64 param_1);
u32 FUN_003c2630(u32 param_1,u32 param_2,u32 param_3);
u32 * FUN_003c2770(void);
u8 * FUN_003c2780(u32 param_1);
u32  FUN_003c28a0(u32 param_1,u32 param_2,int param_3,int param_4,int param_5,int *param_6);
u32 FUN_003c2ab0(u32 param_1,u32 param_2);
u32 FUN_003c2b40(int *param_1,int *param_2);
u8 FUN_003c2c50(u32 param_1);
u32 FUN_003c2df0(u32 param_1);
u32 * FUN_003c2ee0(long param_1);
u32 * FUN_003c3050(u32 param_1);
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
// FUN_003C2570


u32 FUN_003c2570(u64 param_1)



{

  u32 uVar1;

  int lVar2;

  int lVar3;

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
// FUN_003C2630
u32 FUN_003c2630(u32 param_1,u32 param_2,u32 param_3)




{

  u32 uVar1;

  u32 uVar2;

  u32 uVar3;

  s32 lVar4;

  int iVar5;

  u32 auStack_80 [31];

  int iStack_4;

  

  iStack_4 = 0;

  uVar2 = FUN_0017d920();

  uVar3 = FUN_0017da40();

  FUN_00521408((u32)DAT_0095b7e0_abs,0,0x698);

  *(u32*)DAT_0095be74_abs = param_1;
  lVar4 = FUN_003c28a0_call(uVar2,uVar3,param_2,param_3,auStack_80,&iStack_4);

  if (lVar4 == 0) {

    uVar1 = 0;

  }

  else {

    ((u32*)DAT_0095b7e0_abs)[0] = iStack_4;

    for (iVar5 = 0; iVar5 < iStack_4; iVar5 = iVar5 + 1) {

      lVar4 = FUN_003be8e0(auStack_80[iVar5],(u8*)DAT_0095b7e0_abs + iVar5 * 0x38 + 4);

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
// FUN_003C2780


u8 * FUN_003c2780(u32 param_1)



{

  char cVar1;

  u8 bVar7;
  int iVar2;

  int iVar3;

  int lVar4;

  int iVar6;

  u8 *pbVar5;

  

  iVar2 = FUN_003bd870();

  iVar2 = *(int *)(iVar2 + 0x674);

  iVar3 = FUN_003bd870();

  iVar3 = *(int *)(iVar3 + 0x678);

  for (iVar6 = 0; iVar6 < iVar3; iVar6 = iVar6 + 1) {

    pbVar5 = (u8 *)(iVar2 + iVar6 * 0xc);

    if (*pbVar5 == param_1) {

      lVar4 = FUN_0016e100((short)(u32)*pbVar5);

      if (lVar4 == 0) {

        FUN_0019d3f0("comuSasoi.c",0x3c1);

      }

      cVar1 = FUN_0016dba0((short)param_1);

      if ((long)(u32)pbVar5[1] <= (long)cVar1) {

        bVar7 = (long)(u32)pbVar5[2] < (long)cVar1;

        if (bVar7) {

          continue;

        }

        return pbVar5;

      }


    }
  }

  FUN_0019d3f0("comuSasoi.c",0x3cd);

  return (u8 *)0x0;

}
#define FUN_003c2780(...) ((u8 * (*)(...))FUN_003c2780)(__VA_ARGS__)
#undef FUN_003c28a0
// FUN_003C28A0


u32

FUN_003c28a0(u32 param_1,u32 param_2,int param_3,int param_4,int param_5,int *param_6)



{


  char cVar2;

  u32 uVar3;

  s32 lVar4;

  int iVar5;

  int iVar6;

  int iVar7;
  int iVar8;

  int aiStack_80 [31];

  

  iVar7 = 0;
  iVar6 = 0;
  while (iVar6 < 0x1e) {
    lVar4 = FUN_0016e100((short)iVar6);
    if (lVar4 != 0) {
      cVar2 = FUN_0016dba0((short)iVar6);
      if (cVar2 != '\n') {
        lVar4 = FUN_003c40f0(iVar6);
        if (lVar4 != 0) {
          lVar4 = FUN_001717c0(iVar6);
          if (lVar4 != 1) {
            lVar4 = FUN_00172160(iVar6);
            if (lVar4 != 1) {
              iVar5 = 0;
              for (; iVar5 < param_4; iVar5 = iVar5 + 1) {
                if (iVar6 == *(int *)(param_3 + iVar5 * 4)) {
                  iVar5 = 1;
                  goto LAB_003c29b0;
                }
              }
              iVar5 = 0;
LAB_003c29b0:
              if (iVar5 != 1) {
                lVar4 = FUN_003c23f0(iVar6,param_1,param_2);
                if (lVar4 != 1) {
                  lVar4 = FUN_00172660(iVar6);
                  if (lVar4 != 0) {
                    lVar4 = FUN_003951d0(iVar6 + 0x990);
                    if (lVar4 != 1) {
                      aiStack_80[iVar7] = iVar6;
                      iVar7 = iVar7 + 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    iVar6 = iVar6 + 1;
  }
  if (iVar7 == 0) {
    uVar3 = 0;
  }
  else {
    for (iVar8 = 0; iVar8 < iVar7; iVar8 = iVar8 + 1) {
      *(int *)(param_5 + iVar8 * 4) = aiStack_80[iVar8];
    }
    *param_6 = iVar7;
    uVar3 = 1;
  }
  return uVar3;

}
#define FUN_003c28a0(...) ((u32 (*)(...))FUN_003c28a0)(__VA_ARGS__)
#undef FUN_003c2ab0
// FUN_003C2AB0


u32 FUN_003c2ab0(u32 param_1,u32 param_2)
{
  int *state;
  u8 *base;
  int count;
  int index;

  state = (int *)FUN_003bdd50();
  base = (u8 *)state[2];
  count = state[3];
  index = 0;
  while (index < count) {
    if ((param_1 == base[index * 2]) && (param_2 == base[index * 2 + 1])) {
      return 1;
    }
    index = index + 1;
  }
  return 0;
}
#undef FUN_003c2ab0
#undef FUN_003c2b40
#pragma push
#pragma opt_rebuildconditionals off
// FUN_003C2B40


u32 FUN_003c2b40(int *param_1,int *param_2)



{

  u32 bVar1;

  int uVar2;

  int uVar3;

  int iVar4;

  u32 uVar5;

  s32 lVar6;
  u8 *base;

  int count;

  u8 *pbVar7;

  int iVar8;

  s16 uStack_4;

  s16 uStack_2;

  

  uStack_4 = 0;

  uStack_2 = 0;

  FUN_0017d920();

  FUN_0017da40();

  lVar6 = FUN_0017ddf0(&uStack_4,&uStack_2);


  if (lVar6 == 0) {

    uVar5 = 0;

  }

  else {
    uVar3 = uStack_2;

    uVar2 = uStack_4;

    iVar4 = FUN_003bdd50();
    base = (u8 *)(*(int *)(iVar4 + 8));
    count = *(int *)(iVar4 + 0xc);
    iVar8 = 0;
    while (iVar8 < count) {
      pbVar7 = base + iVar8 * 2;
      if ((uVar2 == *pbVar7) && (uVar3 == pbVar7[1])) {
        bVar1 = 1;
        goto LAB_003c2c00;
      }
      iVar8 = iVar8 + 1;
    }
    bVar1 = 0;

LAB_003c2c00:
    uVar5 = 1;

    if (bVar1 == 1) {
      uVar5 = 0;
    }
    else {
      *param_1 = (int)(short)uStack_4;
      *param_2 = (int)(short)uStack_2;
    }

  }

  return uVar5;

}
#pragma pop
#define FUN_003c2b40(...) ((u32 (*)(...))FUN_003c2b40)(__VA_ARGS__)
#undef FUN_003c2c50
// FUN_003C2C50 NONMATCHING


u8 FUN_003c2c50(u32 param_1)



{

  char cVar1;

  u8 bVar2;

  int *piVar3;

  int lVar4;

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
#undef FUN_003c2c50
#undef FUN_003c2df0


// FUN_003C2DF0
#pragma opt_loop_invariants on
u32 FUN_003c2df0(u32 param_1)
{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  u8 *pbVar4;
  int iVar5;
  int iVar6;
  u8 bVar7;

  iVar1 = FUN_003bd870();
  uVar2 = FUN_0017d920();
  uVar3 = FUN_0017da40();
  iVar5 = 0;
  iVar6 = *(int *)(iVar1 + 0x654);
  bVar7 = 0xff;
  while (iVar5 < iVar6) {
    pbVar4 = (u8 *)*(int *)(iVar1 + 0x650);
    pbVar4 = pbVar4 + iVar5 * 3;
    if (((uVar2 == *pbVar4) && (uVar3 == pbVar4[1])) && (param_1 == pbVar4[2])) {
      return 1;
    }
    if (((uVar2 == *pbVar4) && (uVar3 == pbVar4[1])) && (pbVar4[2] == bVar7)) {
      return 1;
    }
    iVar5 = iVar5 + 1;
  }
  return 0;
}
#pragma opt_loop_invariants off
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
// FUN_003C3050


u32 *FUN_003c3050(u32 param_1)
{
  if (FUN_003be2a0_u32(0,0,param_1,7,DAT_0095b79c) == 0) {
    return 0;
  }

  DAT_0095b790_abs[0] = 1;
  return (u32*)DAT_0095b790_abs;
}

#define FUN_003c3050(...) ((u32 * (*)(...))FUN_003c3050)(__VA_ARGS__)
#undef FUN_003c30b0
#pragma alias DAT_0095b790_wrap_abs DAT_0095b790
extern u8 DAT_0095b790_wrap_abs[];
#pragma alias DAT_0095b794_abs DAT_0095b794
extern u8 DAT_0095b794_abs[];
#pragma alias DAT_0095b798_abs DAT_0095b798
extern u8 DAT_0095b798_abs[];
#pragma alias DAT_0095b79c_abs DAT_0095b79c
extern u8 DAT_0095b79c_abs[];
// FUN_003C30B0


u8 FUN_003c30b0(void)
{
  u32 t0;
  u32 t1;
  u32 t2;

  if (*(u32*)DAT_0095b790_wrap_abs != 0) goto work;
  return 0;
work:
  t0 = *(u32*)DAT_0095b794_abs;
  t1 = *(u32*)DAT_0095b798_abs;
  asm volatile("" : "+m"(t0));
  asm volatile("" : "+m"(t1));
  t2 = (u32)DAT_0095b79c_abs;
  FUN_00172b80(t0,t1,t2,1);
  *(u32*)DAT_0095b790_wrap_abs = 0;
  return 1;
}
#define FUN_003c30b0(...) ((u8 (*)(...))FUN_003c30b0)(__VA_ARGS__)
#undef FUN_003c3120
// FUN_003C3120


u8 FUN_003c3120(void)
{
  u32 t0;
  u32 t1;
  u32 t2;

  if (*(u32*)DAT_0095b790_wrap_abs != 0) goto work;
  return 0;
work:
  t0 = *(u32*)DAT_0095b794_abs;
  t1 = *(u32*)DAT_0095b798_abs;
  asm volatile("" : "+m"(t0));
  asm volatile("" : "+m"(t1));
  t2 = (u32)DAT_0095b79c_abs;
  FUN_00172b80(t0,t1,t2,0);
  *(u32*)DAT_0095b790_wrap_abs = 0;
  return 1;
}
#define FUN_003c3120(...) ((u8 (*)(...))FUN_003c3120)(__VA_ARGS__)
#undef FUN_003c3190
// FUN_003C3190 NONMATCHING
#pragma opt_loop_invariants on


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
#pragma opt_loop_invariants off
#define FUN_003c3190(...) ((u32 (*)(...))FUN_003c3190)(__VA_ARGS__)
#undef FUN_003c3390
// FUN_003C3390


u32 * FUN_003c3390(void)



{

  u32 *puVar1;

  

  if (D_0095b790[0] == 0) {

    puVar1 = (u32 *)0x0;

  }

  else {

    puVar1 = D_0095b790;

  }

  return puVar1;

}

#define FUN_003c3390(...) ((u32 * (*)(...))FUN_003c3390)(__VA_ARGS__)
