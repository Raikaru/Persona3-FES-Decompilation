#include "temporary.h"
typedef int (*code)();
/* FUSION_EXACT_PROTOS */
void FUN_0040e300(u32 param_1,u32 param_2);
void FUN_0040e360(void);
void FUN_0040e390(void);
void FUN_0040e3c0(int param_2,int param_3,float param_1,u8 param_4,int param_5,int param_6);
void FUN_0040e3f0(float param_1,float param_2,float param_3,float param_4,int param_5,int param_6,
                   u8 param_7,int param_8,int param_9,int param_10,int param_11);
#pragma alias FUN_0040e3f0_i2f1i3f3 FUN_0040e3f0
extern void FUN_0040e3f0_i2f1i3f3(int param_5,int param_6,float param_1,u8 param_7,int param_8,
                                  int param_9,int param_10,int param_11,float param_2,
                                  float param_3,float param_4);
void FUN_0040e420(float param_1,float param_2,float param_3,float param_4,int param_5,int param_6,
                   u8 param_7,int param_8,int param_9,int param_10,int param_11);
u32 FUN_0040e450(int param_1);
u32 FUN_0040e4f0(int *param_1);
void FUN_0040e580(u32 param_1);
u64 FUN_0040e610(int param_2,int param_3,float param_1,u8 param_4,int param_5,int param_6,int param_7);
u64 FUN_0040e710(int param_5, int param_6, float param_1, int param_7, int param_8, int param_9, int param_10, int param_11, int param_12, float param_2, float param_3, float param_4);
#pragma alias FUN_0040e710_i2f1u8i4i3f FUN_0040e710
extern void FUN_0040e710_i2f1u8i4i3f(int param_5,int param_6,float param_1,u8 param_7,
                                     int param_8,int param_9,int param_10,int param_11,
                                     int param_12,float param_2,float param_3,float param_4);
#pragma alias FUN_0040e930_i2f1u8i4i3f FUN_0040e930
extern void FUN_0040e930_i2f1u8i4i3f(int param_5,int param_6,float param_1,u8 param_7,
                                     int param_8,int param_9,int param_10,int param_11,
                                     int param_12,float param_2,float param_3,float param_4);
u64 FUN_0040e930(int param_5,int param_6,float param_1,int param_7,int param_8,int param_9,int param_10,int param_11,int param_12,float param_2,float param_3,float param_4);
#pragma alias fclDrawSpriteCreate_i FUN_001158b0
extern u32 fclDrawSpriteCreate_i(int param_1, u32 param_2, int param_3);
#pragma alias fclDrawSpriteEmit FUN_0040e3c0
extern void fclDrawSpriteEmit(int param_1,int param_2,float param_3,int param_4,int param_5,int param_6);
s32 FUN_0040eb50(float param_1,int param_2,int param_3,u8 param_4,int param_5,const void *param_6,int param_7);
s32 FUN_0040ebc0(float param_1,int param_2,int param_3,int param_4,int param_5,const void *param_6,int param_7);
void FUN_0040ec20(u32 param_1,int param_2,u32 param_3,u32 param_4,u32 param_5,u64 param_6,u32 param_7,int param_8);
#pragma alias FUN_0040ec20_typed FUN_0040ec20
void FUN_0040eef0(int param_2,int param_3,float param_1,int param_4,int param_5,

                  int param_6);
u32 FUN_0040ec50();
u32 FUN_0040f030(int param_1,int param_2,int param_3);
u32 FUN_0040f430(int param_1,int param_2);
u32 FUN_0040f5d0(int param_1,int param_2,int param_3);
u64 FUN_0040fab0(u64 param_1,int param_2);
u64 FUN_0040fb90(u64 param_1,int param_2,int param_3);
void FUN_00521408(void *destination,s32 value,u32 size);
extern void *H_Cdvd_CacheFindFile(const char *path,u32 *fileSize);
extern u32 DAT_006af960[];
extern u32 DAT_006af980[];
float DAT_006af9d8;
float DAT_006af9dc;
float DAT_006af9e0;
#pragma alias DAT_006af9d8_abs DAT_006af9d8
#pragma alias DAT_006af9dc_abs DAT_006af9dc
#pragma alias DAT_006af9e0_abs DAT_006af9e0
extern float DAT_006af9d8_abs[];
extern float DAT_006af9dc_abs[];
extern float DAT_006af9e0_abs[];
typedef struct {
  float x;
  float y;
  float z;
} FclDrawSpriteVec3;
u32 DAT_006af9a0;
#pragma alias DAT_006af9a0_abs DAT_006af9a0
extern u32 DAT_006af9a0_abs[];
u16 DAT_006af9c0[];
typedef short DAT_006af9c0_abs_t;
#pragma alias DAT_006af9c0_abs DAT_006af9c0
extern DAT_006af9c0_abs_t DAT_006af9c0_abs[];
u32 DAT_006af9f0;
u32 DAT_006afa70;
int DAT_006afaf0[];
u32 DAT_006afb10;
#pragma alias DAT_006afb10_abs DAT_006afb10
extern u32 DAT_006afb10_abs[];
extern u32 DAT_007ce69c;
extern s32 DAT_007ce6a0;
extern code DAT_00960178[];
extern code DAT_0096017c[];
#pragma alias DAT_00960178_abs DAT_00960178
extern code DAT_00960178_abs[];
#pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];
#include "Kosaka/k_assert.h"

#pragma alias FUN_0040e3c0_y2 FUN_0040e3c0_y2
#pragma alias FUN_0040e3f0_y2 FUN_0040e3f0_y2
















#pragma opt_loop_invariants off





// FUN_0040EC50 NONMATCHING


u32 FUN_0040ec50(u32 param_1,int param_2,u32 param_3,u32 param_4,

                 u32 param_5,u64 param_6,u32 param_7,int param_8,code *param_9,

                 u32 param_10)



{

  char cVar1;

  u32 uVar2;

  char *pcVar3;

  u32 uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  char acStack_20 [32];

  

  iVar6 = 0;

  iVar5 = 0;

  memset(acStack_20,0,0x20);

  uVar2 = strlen((char *)param_6);

  uVar4 = 0;

  iVar7 = 0;

  do {

    pcVar3 = (char *)((int)param_6 + uVar4);

    if (*pcVar3 == ' ') {

      acStack_20[iVar7] = -1;

    }

    else {

      if (((((param_7 & 8) != 0) && (3 < uVar2)) && (uVar4 != 0)) && ((int)(uVar2 - uVar4) % 3 == 0)

         ) {

        acStack_20[iVar7] = '\n';

        iVar5 = iVar5 + 1;

        iVar7 = iVar7 + 1;

      }

      cVar1 = *pcVar3 + -0x30;

      acStack_20[iVar7] = cVar1;

      if (cVar1 < '\0') {

        K_Assert((const char *)DAT_006af960 - 0x10,0x115);

      }

      if ('\t' < acStack_20[iVar7]) {

        K_Assert((const char *)DAT_006af960 - 0x10,0x116);

      }

    }

    uVar4 = uVar4 + 1;

    iVar7 = iVar7 + 1;

  } while (uVar4 < uVar2);

  uVar2 = uVar2 * param_8 + iVar5 * 6;

  if ((param_7 & 1) == 0) {

    if ((param_7 & 2) != 0) {

      param_2 = param_2 - (uVar2 >> 1);

    }

  }

  else {

    param_2 = param_2 - uVar2;

  }

  for (iVar5 = 0; iVar5 < iVar7; iVar5 = iVar5 + 1) {

    cVar1 = acStack_20[iVar5];

    if (cVar1 != -1) {

      (*param_9)(param_1,param_2 + iVar6,param_3,param_4,param_5,cVar1,iVar5,iVar7,param_10);

    }

    if (acStack_20[iVar5] == '\n') {

      iVar6 = iVar6 + 5;

    }

    else {

      if (acStack_20[iVar5 + 1] == '\n') {

        iVar6 = iVar6 + 1;

      }

      iVar6 = iVar6 + param_8;

    }

  }

  return uVar2;

}

// FUN_0040EEF0


void FUN_0040eef0(int param_2,int param_3,float param_1,int param_4,int param_5,

                 int param_6)



{

  u32 uVar1;
  u32 uVar2;

  u32 maestro;

  u32 *puVar5;
  u32 *puVar4;
  int iVar3;

  u32 auStack_20 [8];

  

  puVar5 = DAT_006af9a0_abs;

  puVar4 = auStack_20;

  iVar3 = 5;

  do {

    uVar1 = *puVar5;

    puVar5 = puVar5 + 1;

    iVar3 = iVar3 + -1;

    *puVar4 = uVar1;

    puVar4 = puVar4 + 1;

  } while (0 < iVar3);

  maestro = H_Maestro_001120a0(auStack_20[param_5]);

  if (param_5 - 3U < 2) {

    param_6 = param_6 + 0xb;

  }

  uVar2 = fclDrawSpriteCreate(0,maestro,param_6);

  iVar3 = (int)uVar2;

  *(float *)(iVar3 + 0x10) = (float)param_2;

  *(float *)(iVar3 + 0x14) = (float)param_3;

  *(float *)(iVar3 + 0x2c) = param_1;

  *(u8 *)(iVar3 + 0x19) = 0xff - (param_4 & 0xff);

  *(char *)(iVar3 + 0x30) = (char)((u32)param_4 >> 0x18);

  *(char *)(iVar3 + 0x31) = (char)((u32)param_4 >> 0x10);

  *(char *)(iVar3 + 0x32) = (char)((u32)param_4 >> 8);

  func_001127d0(uVar2,1);

  FUN_00115980(uVar2);

  return;

}

// FUN_0040F030 NONMATCHING


u32 FUN_0040f030(int param_1,int param_2,int param_3)



{

  short uVar1;

  short uVar2;

  u32 *puVar3;

  u32 uVar4;

  int iVar5;

  u32 uVar6;

  u32 lVar7;

  int iVar8;

  short *puVar10;

  short *puVar9;

  u32 *puVar11;

  int iVar12;

  short sVar13;

  short auStack_20 [16];

  

  puVar3 = *(u32 **)(param_2 + 0xc);

  puVar10 = DAT_006af9c0_abs;

  puVar9 = auStack_20;

  iVar8 = 6;

  do {

    uVar1 = *puVar10;

    uVar2 = puVar10[1];

    puVar10 = puVar10 + 2;

    iVar8 = iVar8 + -1;

    *puVar9 = uVar1;

    puVar9[1] = uVar2;

    puVar9 = puVar9 + 2;
  } while (0 < iVar8);

  lVar7 = FUN_003e6d70();

  if (lVar7 == 0) {

    uVar6 = 2;

  }

  else {

    if (param_3 != 0) {
      sVar13 = *(short *)((int)param_3 + 6);
      if (sVar13 != 4) {
        if (sVar13 == 1) {
          FUN_00521408(puVar3,0,0x28);
          *(u16 *)(puVar3 + 2) = 0x140;
          *(u16 *)(puVar3 + 1) = 0x140;
          *(u16 *)((int)puVar3 + 6) = auStack_20[*(int *)(param_1 + 0x1c) * 4];
          *(u16 *)((int)puVar3 + 0xe) = auStack_20[*(int *)(param_1 + 0x1c) * 4 + 1];
          uVar4 = *puVar3 | 1;
          *puVar3 = uVar4;
          *puVar3 = uVar4 & 0xfffffff7;
          *(u16 *)(puVar3 + 7) = 0x280;
          *(u16 *)(puVar3 + 6) = 0x280;
          *(u16 *)((int)puVar3 + 0x1a) = auStack_20[*(int *)(param_1 + 0x1c) * 4];
          *(u16 *)(puVar3 + 9) = 0x30;
          *(u16 *)((int)puVar3 + 0x22) = auStack_20[*(int *)(param_1 + 0x1c) * 4 + 1];
          uVar4 = puVar3[5] | 4;
          puVar3[5] = uVar4;
          puVar3[5] = uVar4 & 0xfffffff7;
          puVar3[10] = 0;
        }
      }
      else {
        uVar4 = *puVar3;
        uVar4 = uVar4 | 2;
        *puVar3 = uVar4;
        uVar4 = uVar4 | 8;
        *puVar3 = uVar4;
        uVar4 = puVar3[5];
        uVar4 = uVar4 | 2;
        puVar3[5] = uVar4;
        uVar4 = uVar4 | 8;
        puVar3[5] = uVar4;
      }
    }

    uVar4 = puVar3[10];

    if (((uVar4 != 2) && (uVar4 != 1)) && (uVar4 == 0)) {

      iVar8 = 0;

      for (iVar12 = 0; iVar12 < 2; iVar12 = iVar12 + 1) {

        puVar11 = puVar3 + iVar12 * 5;

        if ((*puVar11 & 4) == 0) {

          *(short *)(puVar11 + 4) = (short)puVar11[4] + 1;

          if (((short)puVar11[1] < 0x65) && ((*puVar11 & 2) == 0)) {

            *puVar11 = *puVar11 | 2;

          }

          iVar5 = (short)puVar11[4] * 5;

          sVar13 = (short)(iVar5 >> 1);

          if (iVar5 < 0) {

            sVar13 = (short)(iVar5 + 1 >> 1);

          }

          *(short *)(puVar11 + 1) = (short)puVar11[2] - sVar13;

          if ((*puVar11 & 1) == 0) {

            if ((*puVar11 & 2) != 0) {

              sVar13 = *(short *)((int)puVar11 + 0x12) + 1;

              *(short *)((int)puVar11 + 0x12) = sVar13;

              *(short *)(puVar11 + 3) =

                   *(short *)((int)puVar11 + 0xe) -

                   (short)(((int)*(short *)((int)puVar11 + 0xe) * (int)sVar13) / 10);

              if (9 < *(short *)((int)puVar11 + 0x12)) {

                uVar4 = *puVar11;

                *puVar11 = uVar4 & 0xfffffffd;

                *puVar11 = uVar4 & 0xfffffffd | 4;

                *(u16 *)(puVar11 + 3) = 0;

                *(u16 *)((int)puVar11 + 0x12) = 0;

                *(u16 *)(puVar11 + 4) = auStack_20[*(int *)(param_1 + 0x1c) * 4 + 2];

              }

            }

          }

          else {

            sVar13 = *(short *)((int)puVar11 + 0x12) + 1;

            *(short *)((int)puVar11 + 0x12) = sVar13;

            *(short *)(puVar11 + 3) =

                 (short)(((int)*(short *)((int)puVar11 + 0xe) * (int)sVar13) / 10);

            if (9 < *(short *)((int)puVar11 + 0x12)) {

              *puVar11 = *puVar11 & 0xfffffffe;

              *(u16 *)(puVar11 + 3) = *(u16 *)((int)puVar11 + 0xe);

              *(u16 *)((int)puVar11 + 0x12) = 0;

            }

          }

        }

        else if ((*puVar11 & 8) == 0) {

          sVar13 = (short)puVar11[4] + -1;

          *(short *)(puVar11 + 4) = sVar13;

          if (sVar13 < 1) {

            *(u16 *)(puVar11 + 4) = 0;

            uVar4 = *puVar11;

            *puVar11 = uVar4 & 0xfffffffb;

            *puVar11 = uVar4 & 0xfffffffb | 1;

            *(u16 *)(puVar11 + 2) = 0x280;

            *(u16 *)(puVar11 + 1) = 0x280;

          }

        }

        else {

          iVar8 = iVar8 + 1;

        }

      }

      if (1 < iVar8) {

        puVar3[10] = 1;

        return 2;

      }

    }

    uVar6 = 1;

  }

  return uVar6;

}

// FUN_0040F430


u32 FUN_0040f430(int param_1,int param_2)



{

  int iVar1;

  u32 uVar2;
  int iVar3;

  u32 lVar4;


  int iVar5;

  FclDrawSpriteVec3 auStack_10;

  

  iVar1 = *(int *)(param_2 + 0xc);

  auStack_10 = *(FclDrawSpriteVec3 *)DAT_006af9d8_abs;


  lVar4 = FUN_003e6d70();

  if (lVar4 == 0) {

    uVar2 = 2;

  }

  else {

    switch (*(int *)(param_1 + 0x1c)) {
    case 2:
      for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {
        iVar3 = iVar1 + iVar5 * 0x14;

        fclDrawSpriteEmit(*(short *)(iVar3 + 4),*(short *)(iVar3 + 6),0.0f,

                          *(u8 *)(iVar3 + 0xc),0x56,0);

        fclDrawSpriteEmit(*(short *)(iVar3 + 4),*(short *)(iVar3 + 6),0.0f,

                          *(u8 *)(iVar3 + 0xc),0x57,0);

        fclDrawSpriteEmit(*(short *)(iVar3 + 4),*(short *)(iVar3 + 6),0.0f,

                          *(u8 *)(iVar3 + 0xc),0x58,0);

        fclDrawSpriteEmit(*(short *)(iVar3 + 4),*(short *)(iVar3 + 6),0.0f,

                          *(u8 *)(iVar3 + 0xc),0x59,0);
      }
      break;
    default:
      for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {
        iVar3 = iVar1 + iVar5 * 0x14;

        fclDrawSpriteEmit(*(short *)(iVar3 + 4),*(short *)(iVar3 + 6),0.0f,

                          *(u8 *)(iVar3 + 0xc),((u32 *)&auStack_10)[*(int *)(param_1 + 0x1c)],0);
      }
      break;
    }

    uVar2 = 0;

  }

  return uVar2;

}

// FUN_0040F5D0 NONMATCHING


u32 FUN_0040f5d0(int param_1,int param_2,int param_3)



{

  short sVar1;
  int iVar2;

  u32 uVar3;

  u32 uVar4;

  int iVar5;

  int iVar6;

  short *psVar7;

  u16 *puVar8;

  u32 *puVar9;

  int iVar10;

  int iVar11;

  short asStack_100 [2];

  float afStack_fc [14];

  short asStack_c4 [4];

  float afStack_bc [15];

  short asStack_80 [2];

  float afStack_7c [14];

  short asStack_44 [4];

  float afStack_3c [15];

  

  iVar2 = *(int *)(param_2 + 0xc);

  puVar9 = &DAT_006af9f0;

  psVar7 = asStack_80;

  iVar5 = 0xf;

  do {

    uVar4 = *puVar9;

    uVar3 = puVar9[1];

    puVar9 = puVar9 + 2;

    iVar5 = iVar5 + -1;

    *(u32 *)psVar7 = uVar4;

    *(u32 *)(psVar7 + 2) = uVar3;

    psVar7 = psVar7 + 4;

  } while (0 < iVar5);

  puVar9 = &DAT_006afa70;

  psVar7 = asStack_100;

  iVar5 = 0xf;

  do {

    uVar4 = *puVar9;

    uVar3 = puVar9[1];

    puVar9 = puVar9 + 2;

    iVar5 = iVar5 + -1;

    *(u32 *)psVar7 = uVar4;

    *(u32 *)(psVar7 + 2) = uVar3;

    psVar7 = psVar7 + 4;

  } while (0 < iVar5);

  if (param_3 != 0) {

    sVar1 = *(short *)((int)param_3 + 6);

    if (sVar1 == 4) {

      memcpy((void *)iVar2,asStack_100,0x3c);

      *(u16 *)(iVar2 + 0x3c) = 2;

      *(u16 *)(iVar2 + 0x3e) = 0;

    }

    else if ((sVar1 != 2) && (sVar1 == 1)) {

      memcpy((void *)iVar2,asStack_80,0x3c);

      *(u16 *)(iVar2 + 0x3c) = 0;

      *(u16 *)(iVar2 + 0x3e) = 0;

    }

  }

  sVar1 = *(short *)(iVar2 + 0x3c);

  if (sVar1 == 2) {

    *(short *)(iVar2 + 0x3e) = *(short *)(iVar2 + 0x3e) + 1;

    iVar10 = 0;

    for (iVar5 = 0; iVar5 < 5; iVar5 = iVar5 + 1) {

      iVar11 = iVar5 * 0xc;

      puVar8 = (u16 *)(iVar2 + iVar11);

      if ((short)puVar8[3] <= *(short *)(iVar2 + 0x3e)) {

        iVar6 = (int)*(short *)(iVar2 + 0x3e) - (int)(short)puVar8[3];

        psVar7 = (short *)((int)afStack_bc + iVar11 + -2);

        sVar1 = *(short *)((int)afStack_bc + iVar11 + -2);

        if ((long)sVar1 < (long)iVar6) {

          iVar10 = iVar10 + 1;

        }

        else {

          *puVar8 = (short)(int)((float)(int)asStack_100[iVar5 * 6] +

                                (float)(iVar6 * ((int)asStack_c4[iVar5 * 6] -

                                                (int)asStack_100[iVar5 * 6])) / (float)(int)sVar1);

          puVar8[1] = (short)(int)((float)(int)asStack_100[iVar5 * 6 + 1] +

                                  (float)(iVar6 * ((int)asStack_c4[iVar5 * 6 + 1] -

                                                  (int)asStack_100[iVar5 * 6 + 1])) /

                                  (float)(int)*psVar7);

          puVar8[2] = (short)(int)((float)(int)*(short *)(afStack_fc + iVar5 * 3) +

                                  (float)(iVar6 * ((int)asStack_c4[iVar5 * 6 + 2] -

                                                  (int)*(short *)(afStack_fc + iVar5 * 3))) /

                                  (float)(int)*psVar7);

          *(float *)(puVar8 + 4) =

               afStack_fc[iVar5 * 3 + 1] +

               ((float)iVar6 * (afStack_bc[iVar5 * 3] - afStack_fc[iVar5 * 3 + 1])) /

               (float)(int)*psVar7;

        }

      }

    }

    if (iVar10 < 5) {

      uVar4 = 0;

    }

    else {

      *(u16 *)(iVar2 + 0x3c) = 1;

      *(u16 *)(iVar2 + 0x3e) = 0;

      uVar4 = 2;

    }

  }

  else if ((sVar1 == 1) || (sVar1 != 0)) {

    uVar4 = 1;

  }

  else {

    *(short *)(iVar2 + 0x3e) = *(short *)(iVar2 + 0x3e) + 1;

    iVar5 = 0;

    for (iVar10 = 0; iVar10 < 5; iVar10 = iVar10 + 1) {

      iVar11 = iVar10 * 0xc;

      puVar8 = (u16 *)(iVar2 + iVar11);

      if ((short)puVar8[3] <= *(short *)(iVar2 + 0x3e)) {

        iVar6 = (int)*(short *)(iVar2 + 0x3e) - (int)(short)puVar8[3];

        psVar7 = (short *)((int)afStack_3c + iVar11 + -2);

        sVar1 = *(short *)((int)afStack_3c + iVar11 + -2);

        if ((long)sVar1 < (long)iVar6) {

          iVar5 = iVar5 + 1;

        }

        else {

          *puVar8 = (short)(int)((float)(int)asStack_80[iVar10 * 6] +

                                (float)(iVar6 * ((int)asStack_44[iVar10 * 6] -

                                                (int)asStack_80[iVar10 * 6])) / (float)(int)sVar1);

          puVar8[1] = (short)(int)((float)(int)asStack_80[iVar10 * 6 + 1] +

                                  (float)(iVar6 * ((int)asStack_44[iVar10 * 6 + 1] -

                                                  (int)asStack_80[iVar10 * 6 + 1])) /

                                  (float)(int)*psVar7);

          puVar8[2] = (short)(int)((float)(int)*(short *)(afStack_7c + iVar10 * 3) +

                                  (float)(iVar6 * ((int)asStack_44[iVar10 * 6 + 2] -

                                                  (int)*(short *)(afStack_7c + iVar10 * 3))) /

                                  (float)(int)*psVar7);

          *(float *)(puVar8 + 4) =

               afStack_7c[iVar10 * 3 + 1] +

               ((float)iVar6 * (afStack_3c[iVar10 * 3] - afStack_7c[iVar10 * 3 + 1])) /

               (float)(int)*psVar7;

        }

      }

    }

    if (4 < iVar5) {

      *(u16 *)(iVar2 + 0x3c) = 1;

      *(u16 *)(iVar2 + 0x3e) = 0;

    }

    uVar4 = 0;

  }

  return uVar4;

}

// FUN_0040FAB0


u64 FUN_0040fab0(u64 param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  short *psVar4;

  int *piVar7;

  int *piVar6;

  int copyCount;

  int index;

  int aiStack_20 [8];

  

  iVar1 = *(int *)(param_2 + 0xc);

  piVar7 = (int *)&DAT_006afaf0;

  piVar6 = aiStack_20;

  copyCount = 4;

  do {

    iVar2 = *piVar7;

    iVar3 = piVar7[1];

    piVar7 = piVar7 + 2;

    copyCount = copyCount + -1;

    *piVar6 = iVar2;

    piVar6[1] = iVar3;

    piVar6 = piVar6 + 2;

  } while (0 < copyCount);

  for (index = 0; index < 8; index = index + 1) {
    psVar4 = (short *)(iVar1 + aiStack_20[index] * 0xc);
    FUN_0040e3f0_i2f1i3f3(*psVar4 + 0x10, psVar4[1] + 0xd, 0.0f,
                          (u8)psVar4[2], index + 0x5a, 0, 0, 0, 0.0f,
                          *(float *)(psVar4 + 4), *(float *)(psVar4 + 4));

  }

  return 0;

}

#pragma push
// FUN_0040FB90 NONMATCHING


u64 FUN_0040fb90(u64 param_1,int param_2,int param_3)



{

  u32 *puVar1;

  u32 uVar2;

  u32 uVar3;

  u32 uVar4;

  u8 bVar5;

  short sVar6;

  u64 uVar7;

  u32 *puVar10;

  short *psVar9;

  int iVar8;

  float fVar11;

  u16 uVar12;

  typedef union {
    u8 bytes[0x80];
    short halves[0x40];
    u32 words[0x20];
    float floats[0x20];
  } FclSpriteStack;

  FclSpriteStack stack;

#define asStack_80 (stack.halves)
#define afStack_7c ((float *)(stack.bytes + 4))
#define auStack_70 (stack.bytes + 0x10)
#define auStack_60 (stack.bytes + 0x20)
#define afStack_40 ((float *)(stack.bytes + 0x40))

  

  puVar1 = *(u32 **)(param_2 + 0xc);

  puVar10 = DAT_006afb10_abs;

  psVar9 = asStack_80;

  iVar8 = 0x10;

  do {

    uVar2 = *puVar10;

    uVar3 = puVar10[1];

    puVar10 = puVar10 + 2;

    iVar8 = iVar8 + -1;

    *(u32 *)psVar9 = uVar2;

    *(u32 *)(psVar9 + 2) = uVar3;

    psVar9 = psVar9 + 4;

  } while (0 < iVar8);

  if (param_3 != 0) { switch(*(u16 *)((int)param_3 + 6)) {
  
  case 4:
  
    *puVar1 = *puVar1 | 1;
  
    *(u16 *)(puVar1 + 6) = 2;
  
    *(u16 *)((int)puVar1 + 0x1a) = 0;
  
    break;
  
  case 5:
  
    memcpy(puVar1 + 2,asStack_80,0x10);
  
    uVar4 = *puVar1;
  
    *puVar1 = uVar4 & 0xfffffffd;
  
    *puVar1 = uVar4 & 0xfffffffd | 1;
  
    puVar1[1] = 0;
  
    *(u16 *)(puVar1 + 6) = 0;
  
    *(u16 *)((int)puVar1 + 0x1a) = 0;
  
    break;
  
  case 6:
  
    memcpy(puVar1 + 2,auStack_70,0x10);
  
    uVar4 = *puVar1;
  
    *puVar1 = uVar4 & 0xfffffffd;
  
    *puVar1 = uVar4 & 0xfffffffd | 1;
  
    puVar1[1] = 1;
  
    *(u16 *)(puVar1 + 6) = 0;
  
    *(u16 *)((int)puVar1 + 0x1a) = 0;
  
    break;
  
  case 7:
  
    memcpy(puVar1 + 2,auStack_60,0x10);
  
    uVar4 = *puVar1;
  
    *puVar1 = uVar4 & 0xfffffffd;
  
    *puVar1 = uVar4 & 0xfffffffd | 1;
  
    puVar1[1] = 2;
  
    *(u16 *)(puVar1 + 6) = 0;
  
    *(u16 *)((int)puVar1 + 0x1a) = 0;
  
  }
  
  uVar7 = 0; } else { sVar6 = (short)puVar1[6];
  
  uVar7 = 2;
  
  if (sVar6 != 2) {
  
    if (sVar6 == 1) {
  
      sVar6 = *(short *)((int)puVar1 + 0x1a) + 1;
  
      *(short *)((int)puVar1 + 0x1a) = sVar6;
  
      if (599 < sVar6) {
  
        *(u16 *)((int)puVar1 + 0x1a) = 0;
  
      }
  
      if ((*puVar1 & 1) == 0) {
  
        fVar11 = 65535.0f - (float)(*(short *)((int)puVar1 + 0x1a) * 0xffff) / 600.0f;

        uVar12 = (u16)(u32)fVar11;
  
        *(u16 *)((int)puVar1 + 0x16) = uVar12;
  
      }
  
      else {
  
        fVar11 = (float)(*(short *)((int)puVar1 + 0x1a) * 0xffff) / 600.0f;

        uVar12 = (u16)(u32)fVar11;
  
        *(u16 *)((int)puVar1 + 0x16) = uVar12;
  
      }
  
    }
  
    else if (sVar6 == 0) {
  
      sVar6 = *(short *)((int)puVar1 + 0x1a) + 1;
  
      *(short *)((int)puVar1 + 0x1a) = sVar6;
  
      uVar4 = puVar1[1];
  
      bVar5 = 0;
  
      if (*(short *)((int)puVar1 + 0xe) <= sVar6) {
  
        iVar8 = (int)sVar6 - (int)*(short *)((int)puVar1 + 0xe);
  
        psVar9 = (short *)((int)afStack_40 + (uVar4 * 8 + 3) * 2);
  
        bVar5 = 1;
  
        if (iVar8 <= (int)*psVar9) {
  
          *puVar1 = *puVar1 | 2;
  
          *(short *)(puVar1 + 2) =
  
               (short)(int)((float)(int)asStack_80[uVar4 * 8] +
  
                           (float)(iVar8 * ((int)*(short *)(afStack_40 + uVar4 * 4) -
  
                                           (int)asStack_80[uVar4 * 8])) / (float)(int)*psVar9);
  
          *(short *)((int)puVar1 + 10) =
  
               (short)(int)((float)(int)asStack_80[uVar4 * 8 + 1] +
  
                           (float)(iVar8 * ((int)*(short *)((int)afStack_40 + (uVar4 * 8 + 1) * 2)
  
                                           - (int)asStack_80[uVar4 * 8 + 1])) /
  
                           (float)(int)*psVar9);
  
          *(short *)(puVar1 + 3) =
  
               (short)(int)((float)(int)*(short *)(afStack_7c + uVar4 * 4) +
  
                           (float)(iVar8 * ((int)*(short *)(afStack_40 + uVar4 * 4 + 1) -
  
                                           (int)*(short *)(afStack_7c + uVar4 * 4))) /
  
                           (float)(int)*psVar9);
  
          *(float *)(puVar1 + 4) =
              afStack_7c[uVar4 * 4 + 1] +
              ((float)iVar8 *
               (afStack_40[uVar4 * 4 + 2] - afStack_7c[uVar4 * 4 + 1])) /
              (float)(int)*psVar9;
  
          bVar5 = 0;
  
        }
  
      }
  
      if (bVar5) {
  
        *(u16 *)(puVar1 + 6) = 1;
  
        if ((*puVar1 & 1) == 0) {
  
          *(short *)((int)puVar1 + 0x1a) =
  
               (short)(int)(600.0f - (float)(*(u16 *)((int)puVar1 + 0x16) * 600) / 65535.0f
  
                           );
  
        }
  
        else {
  
          *(short *)((int)puVar1 + 0x1a) =
  
               (short)(int)((float)(*(u16 *)((int)puVar1 + 0x16) * 600) / 65535.0f);
  
        }
  
      }
  
      return 0;
  
    }
  
    uVar7 = 1;
  
  }
  
  else {
  
    sVar6 = *(short *)((int)puVar1 + 0x1a) + 1;
  
    *(short *)((int)puVar1 + 0x1a) = sVar6;
  
    *(float *)(puVar1 + 4) =
        *(float *)(puVar1 + 4) -
        (*(float *)(puVar1 + 4) * (float)(int)sVar6) / 10.0f;
  
    *(short *)(puVar1 + 3) =
  
         (short)(int)((float)(int)(short)puVar1[3] -
  
                     (float)((int)(short)puVar1[3] * (int)*(short *)((int)puVar1 + 0x1a)) / 10.0f);
  
    if (*(short *)((int)puVar1 + 0x1a) >= 10) {
  
      *puVar1 = *puVar1 & 0xfffffffd;
  
      *(u16 *)((int)puVar1 + 0x1a) = 0;
  
    }
  
    else {
  
      uVar7 = 0;
  
    }
  
  } }

  return uVar7;

}
#undef asStack_80
#undef afStack_7c
#undef auStack_70
#undef auStack_60
#undef afStack_40
#pragma pop


typedef int (*code)();
typedef void (*FclShopBgCallback)(float, float, float, int, int, int, int, int, int, int, int);
typedef struct {
    u32 *callbacks;
    int count;
} FclShopBgCallbackPair;

typedef union {
    float floats[4];
    u32 words[4];
} FclShopBgHeader;
typedef struct {
    FclShopBgHeader header;
    s16 table2[24];
    s16 table1[40];
} FclShopBgLocal;
u32 H_Maestro_CreateTask(u32 parent,u32 priority,u32 path);
u32 H_Maestro_FinishedInit(u32 task);
void H_Maestro_SetShouldLoop(u32 task,u32 shouldLoop);
void H_Maestro_00111f20(u32 task,u32 value);
void H_Maestro_00111c50(u32 task);
void H_Maestro_00111cb0(u32 task);
void H_Maestro_SetAlphaMult(float alpha,u32 task);
void func_00111f10(u32 task,u32 value);
void func_00111ca0(u32 task,u32 value);
float fGpffff80d0;
float fGpffff8110;
float fGpffff8168;
float fGpffff81f8;
float fGpffff81fc;
float fGpffff8204;
float fGpffffad18;
u32 uGpffff8208;
u32 uGpffffad1c;
#pragma alias fGpffffad1c uGpffffad1c
extern float fGpffffad1c;
u32 DAT_007cda50;

#pragma alias sinf_fclShop sinf
extern f32 sinf_fclShop(f32);
#pragma alias cosf_fclShop cosf
extern f32 cosf_fclShop(f32);
/* FUSION_EXACT_PROTOS */
void FUN_0040e3c0_y2(float, s32, s32, u8, s32, s32);
#pragma alias FUN_0040e3c0_i FUN_0040e3c0_y2
void FUN_0040e3c0_i(s32, s32, float, u8, s32, s32);
#pragma alias FUN_0040e3f0_typed FUN_0040e3f0_y2
void FUN_0040e3f0_typed(float, float, float, float, s32, s32, u8, s32, s32, s32, s32);
#pragma alias FUN_003b2cb0_typed FUN_003b2cb0
void FUN_003b2cb0_typed(float, s32, s32, u32, u32, u32, u32, u32, u32);
#pragma alias FUN_003b2cb0_i FUN_003b2cb0
void FUN_003b2cb0_i(s32, s32, float, u32, u32, u32, u32, u32, u32);
void FUN_003eec60(s32);
u64 FUN_004101b0(u64 param_1,int param_2);
u32 FUN_004105e0(int param_1, int param_2, int param_3);
u64 FUN_00410a10(u64 param_1,int param_2);
u32 FUN_00410d30(int param_1,int param_2);
u32 FUN_00410e70(u32 param_1,int param_2,int param_3);
u32 FUN_004110f0(u64 param_1,u64 param_2,int param_3);
u32 FUN_00411190(u64 param_1,u64 param_2,u32 param_3);
u32 FUN_00411340(u64 param_1,u64 param_2,s16 *param_3);
u32 FUN_004113f0(u64 param_1,int param_2,int param_3);
u64 FUN_00411710(u64 param_1,int param_2);
u32 FUN_00411790(u64 param_1,int param_2,int param_3);
u64 FUN_00411ee0(u64 param_1,int param_2);
u32 FUN_004120a0(u64 param_1, int param_2, int param_3);
u64 FUN_00412580(u64 param_1,int param_2);
u32 FUN_00412610(u64 param_1, int param_2, long param_3);
u64 FUN_00412af0(u64 param_1,int param_2);
u32 FUN_00412bc0(u64 param_1, int param_2, long param_3);
u64 FUN_00413010(u64 param_1,int param_2);
u32 FUN_004131a0(u64 param_1, int param_2, int param_3);
u64 FUN_00413680(u64 param_1,int param_2);
u64 FUN_004138e0(u64 param_1,int param_2,int param_3);
u64 FUN_00413b10(u64 param_1,int param_2);
u32 FUN_00413b70(u64 param_1, int param_2, int param_3);
void FUN_00414100(u64 param_1,u64 param_2,int param_3,int param_4,u64 param_5, u32 param_6);
void FUN_004141e0(u64 param_1,u64 param_2,int param_3,int param_4, int param_5,u32 param_6);
void FUN_00414280(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_00414320(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_00414500(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_004145f0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_004146b0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_00414770(u64 param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6);
void FUN_004148b0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_00414950(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_004149f0(u64 param_1,u64 param_2,int param_3,int param_4,u64 param_5, u32 param_6);
void FUN_00414ad0(u64 param_1,u64 param_2,int param_3,int param_4,u64 param_5, u32 param_6);
void FUN_00414bd0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_00414c70(u64 param_1,u64 param_2,int param_3,int param_4,u64 param_5, u32 param_6);
void FUN_00414d70(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
u64 FUN_00414e10(int param_1,int param_2);
u32 FUN_00414fe0(u64 param_1,int param_2,long param_3);
void FUN_004154e0(u64 param_1,u64 param_2,int param_3,int param_4, int param_5,int param_6);
void FUN_00415650(u64 param_1,u64 param_2,int param_3,int param_4, int param_5,int param_6);
void FUN_004157c0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_00415880(u64 param_1,u64 param_2,int param_3,int param_4, int param_5,int param_6);
void FUN_00415a70(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_00415b30(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u8 param_6);
void FUN_00415b70(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
u64 FUN_00415c30(int param_1, int param_2);
u64 FUN_00415dc0(u64 param_1,int param_2,u8 *param_3);
void FUN_00416240(u64 param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6);
void FUN_004163f0(u64 param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6);
void FUN_004166d0(u64 param_1,int param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_004167d0(u64 param_1,int param_2,int param_3,int param_4,int param_5, u8 param_6);
void FUN_00416b90(u64 param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6);
void FUN_00416d20(u64 param_1,int param_2,int param_3,int param_4,int param_5, u8 param_6);
u64 FUN_00417030(int param_1, int param_2);
/* FUSION_GLOBALS */
float DAT_007cadc0;
u32 DAT_006afb90;
u32 DAT_006b0020;
u32 DAT_006b0050;
u32 DAT_006b0450;
u32 DAT_006b04d0;
u32 DAT_006b0a00;
u32 DAT_006b0a60;
float DAT_006b0ac0;
float DAT_006b0ac4;
float DAT_006b0ac8;
float DAT_006b0acc;
#pragma alias DAT_006b0ac0_abs DAT_006b0ac0
extern u8 DAT_006b0ac0_abs[];
#pragma alias DAT_006b0ac4_abs DAT_006b0ac4
extern u8 DAT_006b0ac4_abs[];
#pragma alias DAT_006b0ac8_abs DAT_006b0ac8
extern u8 DAT_006b0ac8_abs[];
#pragma alias DAT_006b0acc_abs DAT_006b0acc
extern u8 DAT_006b0acc_abs[];
u32 DAT_006b0ad0;
u32 DAT_006b0cb0;
u32 DAT_006b0dd4;
u32 DAT_006b0ddc;
u32 DAT_006b0de0;
#pragma alias DAT_006b0de0_abs DAT_006b0de0
extern u8 DAT_006b0de0_abs[];
u32 DAT_006b0e30;
#pragma alias DAT_006b0e30_abs DAT_006b0e30
extern u8 DAT_006b0e30_abs[];

u32 DAT_006b0e64;
u32 DAT_006b0e6c;
#pragma alias DAT_006b0e64_abs DAT_006b0e64
extern u8 DAT_006b0e64_abs[];
u32 DAT_006b10e0;
u32 DAT_006b1130;
u32 DAT_006b1178;
u32 DAT_006b1190;
u32 DAT_006b1220;
u32 DAT_006b1340;
u32 DAT_006b1370;
u32 DAT_006b13a0;
u32 DAT_006b1400;
u32 DAT_006b1460;
u32 DAT_006b14c0;
u32 DAT_006b14f0;
u32 DAT_006b1520;
u32 DAT_006b1580;
u32 DAT_006b1610;
u32 DAT_006b1640;
u32 DAT_006b16a0;
u32 DAT_006b16e0;
u32 DAT_006b1710;
float DAT_007cada4;
float DAT_007caee8;
float DAT_007caef0;
u32 DAT_007cda4c;
u32 DAT_007cda58;
u32 DAT_007cda5a;
u32 DAT_007cda5c;
u32 DAT_007cda5e;
u32 DAT_007cda64;
#pragma alias DAT_007cda64_f DAT_007cda64
extern float DAT_007cda64_f;
u8 *DAT_007ce420;
u8 *DAT_007ce4e4;
code DAT_00960090;
u32 PTR_FUN_006b1490[];
u32 PTR_FUN_006b1494[];
u32 PTR_FUN_006b1498[];
u32 PTR_FUN_006b14a0[];
u32 PTR_FUN_006b16c8[];
u32 PTR_FUN_006b16cc[];
u32 PTR_FUN_006b16d0[];
u32 PTR_FUN_006b1830[];
u32 PTR_FUN_007cda10[];
u32 PTR_FUN_007cda14[];
u32 PTR_FUN_007cda18[];
u32 PTR_FUN_007cda1c[];
u32 PTR_FUN_007cda20[];
u32 PTR_FUN_007cda24[];
u32 PTR_FUN_007cda28[];
u32 PTR_FUN_007cda30[];
u32 PTR_FUN_007cda34[];
u32 PTR_FUN_007cda38[];
u32 PTR_FUN_007cda40[];
u32 PTR_FUN_007cda44[];














// FUN_004101B0 NONMATCHING
u64 FUN_004101b0(u64 param_1,int param_2)



{

  int sVar1;

  int sVar2;

  u32 *puVar3;


  int iVar5;

  int iVar6;
  int iVar7;

  float fVar7;

  float fVar8;

  

  puVar3 = *(u32 **)(param_2 + 0xc);

  if ((*puVar3 & 2) == 0) {
    return 0;
  }

  {

    sVar1 = (short)puVar3[2];

    sVar2 = *(short *)((int)puVar3 + 10);

    fVar8 = *(float *)((int)puVar3 + 0x10);

    iVar5 = (int)(fVar8 * 252.0f);

    iVar6 = (int)(fVar8 * 233.0f);

    fVar7 = (float)(int)(short)puVar3[3];

    FUN_0040e3f0_typed(0,DAT_007cadc0 *
                   ((DAT_007caee8 * (float)*(u16 *)((int)puVar3 + 0x16)) / 65535.0f),fVar8,fVar8,
                 sVar1 - iVar5,sVar2 - iVar6,
                 ((fVar7 < 2147483648.0f)
                  ? (s32)fVar7
                  : ((s32)(fVar7 - 2147483648.0f) | 0x80000000)) & 0xff,
                 0x56,0,iVar5,iVar6);

    FUN_0040e3f0_typed(0,DAT_007cadc0 *
                   ((DAT_007caee8 * (float)*(u16 *)((int)puVar3 + 0x16)) / 65535.0f),fVar8,fVar8,
                 sVar1 - iVar5,sVar2,
                 ((fVar7 < 2147483648.0f)
                  ? (s32)fVar7
                  : ((s32)(fVar7 - 2147483648.0f) | 0x80000000)) & 0xff,
                 0x57,0,iVar5,0);

    FUN_0040e3f0_typed(0,DAT_007cadc0 *
                   ((DAT_007caee8 * (float)*(u16 *)((int)puVar3 + 0x16)) / 65535.0f),fVar8,fVar8,
                 sVar1,sVar2 - iVar6,
                 ((fVar7 < 2147483648.0f)
                  ? (s32)fVar7
                  : ((s32)(fVar7 - 2147483648.0f) | 0x80000000)) & 0xff,
                 0x58,0,0,iVar6);

    FUN_0040e3f0_typed(0,DAT_007cadc0 *
                   ((DAT_007caee8 * (float)*(u16 *)((int)puVar3 + 0x16)) / 65535.0f),fVar8,fVar8,
                 sVar1,sVar2,
                 ((fVar7 < 2147483648.0f)
                  ? (s32)fVar7
                  : ((s32)(fVar7 - 2147483648.0f) | 0x80000000)) & 0xff,
                 0x59,0,0,0);

  }

  return 0;

}

#pragma opt_loop_invariants on
// FUN_004105E0 NONMATCHING


u32 FUN_004105e0(int param_1, int param_2, int param_3) { u16 *puVar1;

u32 uVar2;

u8 bVar3;

short sVar4;

u32 uVar5;

long lVar6;

int iVar7;

short *psVar8;

int iVar9;

u32 *puVar10;

int unaff_s2_lo;

short asStack_60050 [4];

float afStack_60048 [7];

short asStack_6002c [4];

float afStack_60024 [98289];

short asStack_50 [2];

float afStack_4c [8];

float afStack_2c [11];



puVar1 = *(u16 **)(param_2 + 0xc);

puVar10 = &DAT_006afb90;

psVar8 = asStack_50;

iVar7 = 9;

do {

  uVar5 = *puVar10;

  uVar2 = puVar10[1];

  puVar10 = puVar10 + 2;

  iVar7 = iVar7 + -1;

  *(u32 *)psVar8 = uVar5;

  *(u32 *)(psVar8 + 2) = uVar2;

  psVar8 = psVar8 + 4;

} while (0 < iVar7);

if (param_3 == 0) {

  sVar4 = puVar1[6];

  if (sVar4 == 3) {

    sVar4 = puVar1[7];

    puVar1[7] = sVar4 + 1;

    puVar1[2] = (short)(int)(255.0f - (float)((short)(sVar4 + 1) * 0xff) / 10.0f);

    if (9 < (short)puVar1[7]) {

      puVar1[7] = 0;

      return 2;

    }

  }

  else if (sVar4 == 2) {

    sVar4 = puVar1[7];

    puVar1[7] = sVar4 + 1;

    puVar1[9] = sVar4 + 1;

    if (0x4af < (short)puVar1[7]) {

      puVar1[7] = 0;

    }

  }

  else if ((sVar4 == 1) || (sVar4 == 0)) {

    sVar4 = puVar1[7] + 1;

    puVar1[7] = sVar4;

    bVar3 = 0;

    if ((short)puVar1[3] <= sVar4) {

      iVar7 = (int)sVar4 - (int)(short)puVar1[3];

      iVar9 = (int)(short)puVar1[8];

      psVar8 = (short *)((int)afStack_2c + (iVar9 * 6 + 3) * 2);

      if ((long)*psVar8 < (long)iVar7) {

        bVar3 = 1;

      }

      else {

        *puVar1 = (short)(int)((float)(int)asStack_50[iVar9 * 6] +

                              (float)(iVar7 * ((int)*(short *)(afStack_2c + iVar9 * 3) -

                                              (int)asStack_50[iVar9 * 6])) / (float)(int)*psVar8);

        puVar1[1] = (short)(int)((float)(int)asStack_50[iVar9 * 6 + 1] +

                                (float)(iVar7 * ((int)*(short *)((int)afStack_2c +

                                                                (iVar9 * 6 + 1) * 2) -

                                                (int)asStack_50[iVar9 * 6 + 1])) /

                                (float)(int)*psVar8);

        puVar1[2] = (short)(int)((float)(int)*(short *)(afStack_4c + iVar9 * 3) +

                                (float)(iVar7 * ((int)*(short *)(afStack_2c + iVar9 * 3 + 1) -

                                                (int)*(short *)(afStack_4c + iVar9 * 3))) /

                                (float)(int)*psVar8);

        *(float *)(puVar1 + 4) =

             afStack_4c[iVar9 * 3 + 1] +

             ((float)iVar7 * (afStack_2c[iVar9 * 3 + 2] - afStack_4c[iVar9 * 3 + 1])) /

             (float)(int)*psVar8;

      }

    }

    if (bVar3) {

      if (puVar1[6] == 1) {

        return 2;

      }

      puVar1[6] = 2;

      puVar1[7] = puVar1[9];

    }

    return 0;

  }

  uVar5 = 1;

}

else {

  sVar4 = *(short *)((int)param_3 + 6);

  if ((sVar4 == 6) || (sVar4 == 5)) {

    lVar6 = FUN_003c4b50(*(int *)(param_1 + 8),*(int *)(param_1 + 8) + 4,4);

    if (lVar6 != 0) {

      unaff_s2_lo = *(int *)((int)lVar6 + 0x14);

    }

    iVar7 = *(short *)((int)param_3 + 6) + -4;

    memcpy(puVar1,asStack_50 + iVar7 * 6,0xc);

    puVar1[6] = 0;

    puVar1[7] = 0;

    puVar1[8] = (short)iVar7;

    if (unaff_s2_lo != 0) {

      puVar1[9] = *(u16 *)(*(int *)(unaff_s2_lo + 0xc) + 0x12);

    }

  }

  else if (sVar4 == 4) {

    puVar1[6] = 3;

    puVar1[7] = 0;

  }

  else if (sVar4 == 1) {

    memcpy(puVar1,asStack_50,0xc);

    puVar1[6] = 0;

    puVar1[7] = 0;

    puVar1[8] = 0;

  }

  uVar5 = 0;

}

return uVar5; }
#pragma opt_loop_invariants off

// FUN_00410A10 NONMATCHING


u64 FUN_00410a10(u64 param_1,int param_2)



{

  short *psVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  

  psVar1 = *(short **)(param_2 + 0xc);

  fVar7 = *(float *)(psVar1 + 4);

  iVar3 = (int)((float)(int)*psVar1 - fVar7 * 252.0f);

  iVar4 = (int)((float)(int)psVar1[1] - fVar7 * 252.0f);

  iVar5 = (int)(fVar7 * 251.0f);

  iVar6 = (int)(fVar7 * 249.0f);

  fVar9 = (float)(int)psVar1[2];

  fVar8 = (fGpffff81f8 * (float)(int)psVar1[9]) / 1200.0f;

  fVar2 = fVar9;

  if (2.1474836e+09f <= fVar9) {

    fVar2 = fVar9 - 2.1474836e+09f;

  }

  FUN_0040e3f0_typed(0.0f,fGpffff80d0 * -fVar8,fVar7,fVar7,iVar3,iVar4,(int)fVar2 & 0xff,0x55,0,iVar5,iVar6);

  fVar2 = fVar9;

  if (2.1474836e+09f <= fVar9) {

    fVar2 = fVar9 - 2.1474836e+09f;

  }

  FUN_0040e3f0_typed(0.0f,fGpffff80d0 * (fGpffff8110 - fVar8),fVar7,fVar7,iVar3,iVar4,(int)fVar2 & 0xff,0x55,

                    0,iVar5,iVar6);

  fVar2 = fVar9;

  if (2.1474836e+09f <= fVar9) {

    fVar2 = fVar9 - 2.1474836e+09f;

  }

  FUN_0040e3f0_typed(0.0f,fGpffff80d0 * (fGpffff81fc - fVar8),fVar7,fVar7,iVar3,iVar4,(int)fVar2 & 0xff,0x55,

                    0,iVar5,iVar6);

  if (2.1474836e+09f <= fVar9) {

    fVar9 = fVar9 - 2.1474836e+09f;

  }

  FUN_0040e3f0_typed(0.0f,fGpffff80d0 * (fGpffff8168 - fVar8),fVar7,fVar7,iVar3,iVar4,(int)fVar9 & 0xff,0x55,

                    0,iVar5,iVar6);

  return 0;

}

// FUN_00410D30


u32 FUN_00410d30(int param_1,int param_2)


{

  int iVar1;

  u32 uVar2;

  u32 uVar3;

  u32 lVar4;

  

  iVar1 = *(int *)(param_2 + 0xc);

  if (*(int *)(iVar1 + 0xc) == 0) {

    uVar3 = H_Maestro_CreateTask(*(u32 *)(param_1 + 0xc),0x18b4,

                         *(u32 *)(*(int *)(param_2 + 8) + 0x18));

    *(u32 *)(iVar1 + 0xc) = uVar3;

  }

  lVar4 = H_Maestro_FinishedInit(*(u32 *)(iVar1 + 0xc));

  if (lVar4 != 0) {

    H_Maestro_SetShouldLoop(*(u32 *)(iVar1 + 0xc),0);

    func_00111f10(*(u32 *)(iVar1 + 0xc),0);

    H_Maestro_00111f20(*(u32 *)(iVar1 + 0xc),1);

    func_00111ca0(*(u32 *)(iVar1 + 0xc),1);

    uVar2 = *(u32 *)(*(int *)(param_2 + 8) + 0xc);

    if ((uVar2 & 1) != 0) {

      if ((uVar2 & 2) != 0) {

        H_Maestro_SetShouldLoop(*(u32 *)(iVar1 + 0xc),1);

      }

      if ((uVar2 & 4) != 0) {

        func_00111f10(*(u32 *)(iVar1 + 0xc),1);

      }

      if ((uVar2 & 8) != 0) {

        H_Maestro_00111f20(*(u32 *)(iVar1 + 0xc),0);

      }

      if ((uVar2 & 0x10) != 0) {

        func_00111ca0(*(u32 *)(iVar1 + 0xc),0);

      }

    }

    uVar3 = 1;

  }

  else {

    uVar3 = 0;

  }

  return uVar3;

}

/* W327 measured: opt_common_subs off normalized_diff 431 -> 409; object 640/640 -> 616/640 (without/with). */

#pragma opt_common_subs reset







/* W327 measured: opt_loop_invariants on normalized_diff 804 -> 786; object 1172/1248 -> 1164/1248 (without/with). */

#pragma opt_loop_invariants reset






#pragma opt_propagation reset
/* W327 measured: opt_loop_invariants on normalized_diff 792 -> 780; object 1172/1248 -> 1164/1248 (without/with). */

#pragma opt_loop_invariants reset






/* W327 measured: opt_loop_invariants on normalized_diff 1006 -> 986; object 1404/1424 -> 1404/1424 (without/with). */

#pragma opt_loop_invariants reset

















/* W327 measured: opt_loop_invariants on normalized_diff 719 -> 672; object 1252/1280 -> 1252/1280 (without/with). */

#pragma opt_loop_invariants reset








/* W327 measured: opt_loop_invariants on normalized_diff 573 -> 524; object 1116/1152 -> 1116/1152 (without/with). */

#pragma opt_loop_invariants reset

/* W327 measured: opt_common_subs off normalized_diff 555 -> 486; object 752/736 -> 736/736 (without/with). */

#pragma opt_common_subs reset



/* W327 measured: opt_common_subs off normalized_diff 582 -> 458; object 804/784 -> 784/784 (without/with). */

#pragma opt_common_subs reset
