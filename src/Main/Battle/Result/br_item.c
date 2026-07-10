#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_0025da30(void);
void FUN_0025ed40(void);
u64 FUN_0025f370(u64 param_1,u64 param_2);
void FUN_0025f5d0(int param_1,u64 param_2,u64 param_3);
void FUN_0025fb60(int param_1,int param_2,float *param_3);
void FUN_0025fc50(int param_1,u64 param_2,u64 param_3,u64 param_4);
extern f32 DAT_007caff0;
extern f32 DAT_00960088;
extern code DAT_00960090;
extern code DAT_0096009c;
extern code DAT_00960178;

static u32* sBrItem; // DAT_007ce370
static u32 sBrItem374; // DAT_007ce374
float FUN_0021ea00();
void FUN_0021eac0(void*, float);
void FUN_0025d9e0();


// FUN_0025d9e0
void brItem0025d9e0(void)
{
    u32* work;

    K_ASSERT(sBrItem != NULL, 0x75);
    work = sBrItem;
    work[3] = 0;
    work[1] = 0;
    *work |= 2;
}

// FUN_0025f570
void brItem0025f570(void)
{
    u32* work;

    K_ASSERT(sBrItem != NULL, 0x75);
    work = sBrItem;
    work[3] = 0;
    work[1] = 1;
    *work |= 2;
}

// FUN_0025f4a0 NONMATCHING
u32 brItem0025f4a0(void)
{
    K_ASSERT(sBrItem != NULL, 0x75);
    if ((*sBrItem & 1) == 0) {
        return -1;
    }
    return 0;
}

// FUN_0025d8a0 NONMATCHING
void brItem0025d8a0(void* param_1)
{
    u32* puVar1;
    float fVar2;
    float fVar3;

    K_ASSERT(sBrItem != NULL, 0x75);
    puVar1 = sBrItem;
    sBrItem[2] = (u32)param_1;
    fVar2 = FUN_0021ea00(0x1e);
    FUN_0021eac0(puVar1 + 0x104, fVar2);
    fVar2 = FUN_0021ea00(0x1e);
    FUN_0021eac0(puVar1 + 0x144, fVar2);
    fVar2 = FUN_0021ea00(0x1e);
    FUN_0021eac0(puVar1 + 0x184, fVar2);
    fVar2 = FUN_0021ea00(0x32);
    FUN_0021eac0(puVar1 + 0x1c4, fVar2);
    fVar3 = FUN_0021ea00(0x32);
    ((float*)puVar1)[0x206] = fVar3;
    ((float*)puVar1)[0x216] = fVar3;
    ((float*)puVar1)[0x226] = fVar3;
    FUN_0025d9e0();
    *puVar1 |= 1;
}

// FUN_0025f510
void brItem0025f510(int param_1)
{
    u32 uVar1;

    uVar1 = *(u32*)(param_1 + 0x3c);
    K_ASSERT(sBrItem != NULL, 0x75);
    sBrItem = NULL;
    RwFree((void*)uVar1);
    sBrItem374 = 0;
}

/* Recovered battle-misc harvest: 0x0025F370-0x0025FC50 */
// FUN_0025F370 NONMATCHING


u64 FUN_0025f370(u64 param_1,u64 param_2)



{

  u64 uVar1;

  u64 uVar2;

  u32 *puVar3;

  u32 uVar4;

  u32 uStack_20;

  u32 uStack_1c;

  u32 uStack_18;

  u32 uStack_14;

  u8 uStack_4;

  u8 uStack_3;

  u8 uStack_2;

  u8 uStack_1;

  

  uVar1 = (*DAT_00960178)(0x8d0,0x40000);

  uVar2 = FUN_00194e10(0x68ec08,0x18b5,1,2,0x25f4a0,0x25f510,uVar1);

  FUN_00195550(param_1,uVar2);

  puVar3 = (u32 *)uVar1;

  *puVar3 = 0;

  uStack_20 = 0;

  uStack_1c = 0;

  uStack_18 = 0x44200000;

  uStack_14 = 0x43e00000;

  FUN_0021d8e0(puVar3 + 0xc4,&uStack_20);

  uVar4 = FUN_0021ea00(10);

  FUN_0021eac0(puVar3 + 0xc4,(float)uVar4);

  uStack_4 = 0xff;

  uStack_3 = 0xff;

  uStack_2 = 0xff;

  uStack_1 = 0;

  FUN_0021d950(puVar3 + 0xc4,&uStack_4);

  sBrItem = puVar3;

  FUN_0025d8a0(param_2);

  sBrItem374 = (int)uVar2;

  return uVar2;

}

// FUN_0025FB60 NONMATCHING


void FUN_0025fb60(int param_1,int param_2,float *param_3)



{

  int iVar1;

  float *pfVar2;

  float *pfVar3;

  int iVar4;

  float *pfVar5;

  u8 *puVar6;

  int iVar7;

  int iVar8;

  float fVar9;

  u8 auStack_10 [8];

  float fStack_8;

  float fStack_4;

  

  puVar6 = auStack_10;

  iVar7 = *(int *)(param_1 + 0x184) + param_2 * 0x80;

  iVar1 = *(int *)(*(int *)(iVar7 + 0x14) * 4 + param_1 + 0x104);

  pfVar3 = (float *)0x8;

  pfVar5 = &fStack_8;

  pfVar2 = pfVar5;

  while (pfVar2 != (float *)0x0) {

    *(u8 *)pfVar5 = 0;

    pfVar5 = (float *)((int)pfVar5 + 1);

    pfVar3 = (float *)((int)pfVar3 + -1);

    pfVar2 = pfVar3;

  }

  fStack_8 = (float)*(int *)(iVar7 + 0x54);

  fStack_4 = (float)*(int *)(iVar7 + 0x5c);

  iVar4 = 8;

  if (1) {

    do {

      *puVar6 = 0;

      puVar6 = puVar6 + 1;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

  }

  iVar4 = *(int *)(iVar7 + 0x58);

  iVar7 = *(int *)(iVar7 + 0x60);

  iVar8 = *(int *)(iVar1 + 0x10);

  fVar9 = (float)*(int *)(iVar1 + 0xc);

  *param_3 = fStack_8 / fVar9;

  param_3[2] = fStack_4 / fVar9;

  fVar9 = (float)iVar8;

  param_3[1] = (float)iVar4 / fVar9;

  param_3[3] = (float)iVar7 / fVar9;

  return;

}





































// FUN_0025FC50 NONMATCHING
void FUN_0025fc50(int param_1,u64 param_2,u64 param_3,u64 param_4)



{

  int iVar1;

  u32 unaff_s2_lo;

  u32 unaff_s3_lo;

  u32 unaff_s4_lo;

  u32 unaff_s5_lo;

  float fVar2;

  u32 uStack_10;

  u32 uStack_c;

  u32 uStack_8;

  u32 uStack_4;

  

  iVar1 = FUN_00198590();

  fVar2 = 1.0 / *(float *)(iVar1 + 0x80);

  iVar1 = *(int *)((int)param_2 + 0x184) + (int)param_3 * 0x80;

  switch(param_4) {

  case 0:

    FUN_00260430(param_2,param_3,&uStack_10,0);

    unaff_s5_lo = *(u32 *)(iVar1 + 100);

    unaff_s3_lo = *(u32 *)(iVar1 + 0x68);

    unaff_s2_lo = unaff_s5_lo;

    unaff_s4_lo = unaff_s3_lo;

    break;

  case 1:

    FUN_00260430(param_2,param_3,&uStack_10,1);

    unaff_s5_lo = *(u32 *)(iVar1 + 0x68);

    unaff_s3_lo = *(u32 *)(iVar1 + 0x6c);

    unaff_s2_lo = unaff_s3_lo;

    unaff_s4_lo = unaff_s5_lo;

    break;

  case 2:

    FUN_00260430(param_2,param_3,&uStack_10,2);

    unaff_s5_lo = *(u32 *)(iVar1 + 0x70);

    unaff_s3_lo = *(u32 *)(iVar1 + 0x6c);

    unaff_s2_lo = unaff_s5_lo;

    unaff_s4_lo = unaff_s3_lo;

    break;

  case 3:

    FUN_00260430(param_2,param_3,&uStack_10,3);

    unaff_s5_lo = *(u32 *)(iVar1 + 100);

    unaff_s3_lo = *(u32 *)(iVar1 + 0x70);

    unaff_s2_lo = unaff_s3_lo;

    unaff_s4_lo = unaff_s5_lo;

    break;

  case 4:

    FUN_00260430(param_2,param_3,&uStack_10,4);

    unaff_s5_lo = *(u32 *)(iVar1 + 0x68);

    unaff_s2_lo = unaff_s5_lo;

    unaff_s3_lo = unaff_s5_lo;

    unaff_s4_lo = unaff_s5_lo;

    break;

  case 5:

    FUN_00260430(param_2,param_3,&uStack_10,5);

    unaff_s5_lo = *(u32 *)(iVar1 + 0x6c);

    unaff_s2_lo = unaff_s5_lo;

    unaff_s3_lo = unaff_s5_lo;

    unaff_s4_lo = unaff_s5_lo;

    break;

  case 6:

    FUN_00260430(param_2,param_3,&uStack_10,6);

    unaff_s5_lo = *(u32 *)(iVar1 + 0x70);

    unaff_s2_lo = unaff_s5_lo;

    unaff_s3_lo = unaff_s5_lo;

    unaff_s4_lo = unaff_s5_lo;

    break;

  case 7:

    FUN_00260430(param_2,param_3,&uStack_10,7);

    unaff_s5_lo = *(u32 *)(iVar1 + 100);

    unaff_s2_lo = unaff_s5_lo;

    unaff_s3_lo = unaff_s5_lo;

    unaff_s4_lo = unaff_s5_lo;

  }

  *(u32 *)(param_1 + 0x10) = uStack_10;

  *(u32 *)(param_1 + 0x14) = uStack_c;

  *(float *)(param_1 + 0x18) = fVar2;

  *(u32 *)(param_1 + 8) = DAT_00960088;

  *(float *)(param_1 + 0x20) = (float)((unaff_s5_lo >> 0x18) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0x24) = (float)((unaff_s5_lo >> 0x10 & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0x28) = (float)((unaff_s5_lo >> 8 & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0x2c) = (float)((unaff_s5_lo & 0xff) * 0xff >> 7 & 0xff);

  *(u32 *)(param_1 + 0x50) = uStack_8;

  *(u32 *)(param_1 + 0x54) = uStack_c;

  *(float *)(param_1 + 0x58) = fVar2;

  *(u32 *)(param_1 + 0x48) = DAT_00960088;

  *(float *)(param_1 + 0x60) = (float)((unaff_s4_lo >> 0x18) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 100) = (float)((unaff_s4_lo >> 0x10 & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0x68) = (float)((unaff_s4_lo >> 8 & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0x6c) = (float)((unaff_s4_lo & 0xff) * 0xff >> 7 & 0xff);

  *(u32 *)(param_1 + 0x90) = uStack_8;

  *(u32 *)(param_1 + 0x94) = uStack_4;

  *(float *)(param_1 + 0x98) = fVar2;

  *(u32 *)(param_1 + 0x88) = DAT_00960088;

  *(float *)(param_1 + 0xa0) = (float)((unaff_s3_lo >> 0x18) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0xa4) = (float)((unaff_s3_lo >> 0x10 & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0xa8) = (float)((unaff_s3_lo >> 8 & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0xac) = (float)((unaff_s3_lo & 0xff) * 0xff >> 7 & 0xff);

  *(u32 *)(param_1 + 0xd0) = uStack_10;

  *(u32 *)(param_1 + 0xd4) = uStack_4;

  *(float *)(param_1 + 0xd8) = fVar2;

  *(u32 *)(param_1 + 200) = DAT_00960088;

  *(float *)(param_1 + 0xe0) = (float)((unaff_s2_lo >> 0x18) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0xe4) = (float)((unaff_s2_lo >> 0x10 & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0xe8) = (float)((unaff_s2_lo >> 8 & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0xec) = (float)((unaff_s2_lo & 0xff) * 0xff >> 7 & 0xff);

  return;

}

/* Recovered battle-misc harvest: 0x0025DA30-0x0025F5D0 */




























// FUN_0025DA30 NONMATCHING
void FUN_0025da30(void)



{

  u32 uVar1;

  u32 *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  float fVar6;

  u32 uVar7;

  float fVar8;

  float in_f21;

  float fVar9;

  float unaff_f22;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  u8 uStack_4;

  u8 uStack_3;

  u8 uStack_2;

  u8 uStack_1;

  

  if (sBrItem == (u32 *)0x0) {

    FUN_0019d3f0(0x68ebf8,0x75);

  }

  puVar2 = sBrItem;

  if (sBrItem[1] == 1) {

    if ((int)sBrItem[3] < 10) {

      sBrItem[3] = sBrItem[3] + 1;

    }

    else {

      uVar1 = *sBrItem;

      *sBrItem = uVar1 & 0xfffffffd;

      *puVar2 = uVar1 & 0xfffffffc;

    }

  }

  else if (sBrItem[1] == 0) {

    if ((int)sBrItem[3] < 10) {

      sBrItem[3] = sBrItem[3] + 1;

    }

    else {

      *sBrItem = *sBrItem & 0xfffffffd;

    }

  }

  iVar3 = FUN_00260900(puVar2[2],0x34);

  iVar4 = FUN_00260920(puVar2[2],0x34);

  if (puVar2[1] == 1) {

    if ((int)puVar2[3] < 3) {

      in_f21 = (float)(int)puVar2[3] / 3.0;

      fStack_30 = in_f21 * 150.0 + 6.0;

      in_f21 = 1.0 - in_f21;

      fStack_2c = fStack_30;

    }

    else {

      fStack_30 = 156.0;

      fStack_2c = 156.0;

      in_f21 = 0.0;

    }

  }

  else if (puVar2[1] == 0) {

    in_f21 = 1.0;

    if ((int)puVar2[3] < 5) {

      fVar9 = (float)(int)puVar2[3] / 5.0;

      fVar6 = (float)iVar4 + 6.0 + 6.0;

      fVar8 = 6.0 - ((float)iVar4 + 6.0);

      fStack_30 = fVar9 * (6.0 - fVar6) + fVar6 + 0.0;

      fStack_2c = fVar9 * (6.0 - fVar8) + fVar8 + 0.0;

      in_f21 = 1.0;

    }

    else {

      fStack_30 = 6.0;

      fStack_2c = 6.0;

    }

  }

  fStack_28 = (float)iVar3;

  fStack_24 = (float)iVar4;

  FUN_0021d8e0(puVar2 + 0x104,&fStack_30);

  uStack_4 = 0xff;

  uStack_3 = 0xff;

  uStack_2 = 0xff;

  fVar6 = in_f21 * 255.0;

  if (fVar6 < 2.1474836e+09) {

    uStack_1 = (u8)(int)fVar6;

  }

  else {

    uStack_1 = (u8)(int)(fVar6 - 2.1474836e+09);

  }

  FUN_0021d950(puVar2 + 0x104,&uStack_4);

  iVar3 = FUN_00260900(puVar2[2],0x35);

  iVar4 = FUN_00260920(puVar2[2],0x35);

  if (puVar2[1] == 1) {

    if ((int)puVar2[3] < 3) {

      in_f21 = (float)(int)puVar2[3] / 3.0;

      fStack_2c = in_f21 * 150.0;

      fStack_30 = fStack_2c + 23.0;

      fStack_2c = fStack_2c + 109.0;

      in_f21 = 1.0 - in_f21;

    }

    else {

      fStack_30 = 173.0;

      fStack_2c = 259.0;

      in_f21 = 0.0;

    }

  }

  else if (puVar2[1] == 0) {

    in_f21 = 1.0;

    if ((int)puVar2[3] < 6) {

      fVar9 = (float)(int)puVar2[3] / 6.0;

      iVar5 = FUN_00260920(puVar2[2],0x35);

      fVar6 = (float)iVar5 + 109.0 + 23.0;

      fVar8 = 109.0 - ((float)iVar5 + 109.0);

      fStack_30 = fVar9 * (23.0 - fVar6) + fVar6 + 0.0;

      fStack_2c = fVar9 * (109.0 - fVar8) + fVar8 + 0.0;

    }

    else {

      fStack_30 = 23.0;

      fStack_2c = 109.0;

    }

  }

  fStack_28 = (float)iVar3;

  fStack_24 = (float)iVar4;

  FUN_0021d8e0(puVar2 + 0x144,&fStack_30);

  uStack_4 = 0xff;

  uStack_3 = 0xff;

  uStack_2 = 0xff;

  fVar6 = in_f21 * 255.0;

  if (fVar6 < 2.1474836e+09) {

    uStack_1 = (u8)(int)fVar6;

  }

  else {

    uStack_1 = (u8)(int)(fVar6 - 2.1474836e+09);

  }

  FUN_0021d950(puVar2 + 0x144,&uStack_4);

  iVar3 = FUN_00260900(puVar2[2],0x36);

  iVar4 = FUN_00260920(puVar2[2],0x36);

  if (puVar2[1] == 1) {

    if ((int)puVar2[3] < 3) {

      in_f21 = (float)(int)puVar2[3] / 3.0;

      fStack_2c = in_f21 * 150.0;

      fStack_30 = fStack_2c + 116.0;

      fStack_2c = fStack_2c + 22.0;

      in_f21 = 1.0 - in_f21;

    }

    else {

      fStack_30 = 266.0;

      fStack_2c = 172.0;

      in_f21 = 0.0;

    }

  }

  else if (puVar2[1] == 0) {

    in_f21 = 1.0;

    if ((int)puVar2[3] < 6) {

      fVar9 = (float)(int)puVar2[3] / 6.0;

      iVar5 = FUN_00260920(puVar2[2],0x35);

      fVar8 = (float)iVar5 + 109.0 + 116.0;

      fVar6 = 22.0 - ((float)iVar5 + 109.0);

      fStack_30 = fVar9 * (116.0 - fVar8) + fVar8 + 0.0;

      fStack_2c = fVar9 * (22.0 - fVar6) + fVar6 + 0.0;

    }

    else {

      fStack_30 = 116.0;

      fStack_2c = 22.0;

    }

  }

  fStack_28 = (float)iVar3;

  fStack_24 = (float)iVar4;

  FUN_0021d8e0(puVar2 + 0x184,&fStack_30);

  uStack_4 = 0xff;

  uStack_3 = 0xff;

  uStack_2 = 0xff;

  fVar6 = in_f21 * 255.0;

  if (fVar6 < 2.1474836e+09) {

    uStack_1 = (u8)(int)fVar6;

  }

  else {

    uStack_1 = (u8)(int)(fVar6 - 2.1474836e+09);

  }

  FUN_0021d950(puVar2 + 0x184,&uStack_4);

  if (puVar2[1] == 1) {

    if ((int)puVar2[3] < 10) {

      fStack_20 = 864.0;

      fStack_1c = 224.0;

      fStack_18 = 320.0;

      fStack_14 = 768.0;

      fStack_24 = (1.0 - (float)(int)puVar2[3] / 10.0) *

                  (544.0 - (256.0 - DAT_007caff0 * 1.4142135) / 1.4142135);

      fStack_30 = 320.0 - fStack_24;

      fStack_2c = 768.0 - fStack_24;

      fStack_28 = 864.0 - fStack_24;

      fStack_24 = 224.0 - fStack_24;

    }

    else {

      fStack_2c = (1088.0 / unaff_f22) / unaff_f22;

      fStack_28 = fStack_2c + 320.0;

      fStack_24 = fStack_2c + -(640.0 / unaff_f22) / unaff_f22;

      fStack_30 = fStack_2c + -(448.0 / unaff_f22) / unaff_f22;

      fStack_2c = fStack_2c + 224.0;

      fStack_20 = fStack_28;

      fStack_1c = fStack_24;

      fStack_18 = fStack_30;

      fStack_14 = fStack_2c;

    }

  }

  else if (puVar2[1] == 0) {

    if ((int)puVar2[3] < 8) {

      fStack_30 = 320.0;

      fStack_2c = -320.0;

      fStack_28 = -224.00002;

      fStack_24 = 224.0;

      fStack_14 = (((float)(int)puVar2[3] / 8.0) * 1088.0) / 1.4142135;

      fStack_20 = fStack_14 + -224.00002;

      fStack_1c = fStack_14 + 224.0;

      fStack_18 = fStack_14 + 320.0;

      fStack_14 = fStack_14 + -320.0;

    }

    else {

      fStack_30 = 320.0;

      fStack_2c = -(640.0 / unaff_f22) / unaff_f22;

      fStack_28 = -(448.0 / unaff_f22) / unaff_f22;

      fStack_24 = 224.0;

      fStack_14 = 1088.0 / unaff_f22;

      fStack_20 = fStack_28 + fStack_14;

      fStack_1c = fStack_14 + 224.0;

      fStack_18 = fStack_14 + 320.0;

      fStack_14 = fStack_2c + fStack_14;

    }

  }

  FUN_0021d890(puVar2 + 4,&fStack_30);

  uVar7 = FUN_0021ea00(0x32);

  FUN_0021eac0(puVar2 + 4,(float)uVar7);

  uStack_4 = 0;

  uStack_3 = 0;

  uStack_2 = 0;

  uStack_1 = 0;

  FUN_0021d950(puVar2 + 4,&uStack_4);

  if (puVar2[1] == 1) {

    if ((int)puVar2[3] < 10) {

      fStack_24 = (float)(int)puVar2[3] / 10.0;

      in_f21 = 1.0 - fStack_24;

      fStack_24 = fStack_24 * (544.0 - (181.01933 - DAT_007caff0) / 1.4142135);

      fStack_30 = fStack_24 + 291.71573;

      fStack_2c = fStack_24 + -348.28427;

      fStack_28 = fStack_24 + -252.28427;

      fStack_24 = fStack_24 + 195.71573;

      fStack_20 = fStack_28 + 136.28427;

      fStack_1c = fStack_24 + 136.28427;

      fStack_18 = fStack_30 + 136.28427;

      fStack_14 = fStack_2c + 136.28427;

    }

    else {

      in_f21 = 0.0;

      fStack_30 = 0.0;

      fStack_2c = 0.0;

      fStack_28 = 0.0;

      fStack_24 = 0.0;

      fStack_20 = 0.0;

      fStack_1c = 0.0;

      fStack_18 = 0.0;

      fStack_14 = 0.0;

    }

  }

  else if (puVar2[1] == 0) {

    fStack_30 = 320.0;

    fStack_2c = -320.0;

    fStack_28 = -224.00002;

    fStack_24 = 224.0;

    fStack_20 = -116.000015;

    fStack_1c = 332.0;

    fStack_18 = 428.0;

    fStack_14 = -212.0;

    in_f21 = 1.0;

  }

  FUN_0021d890(puVar2 + 0x44,&fStack_30);

  uVar7 = FUN_0021ea00(0x23);

  FUN_0021eac0(puVar2 + 0x44,(float)uVar7);

  uStack_4 = 4;

  uStack_3 = 0x29;

  uStack_2 = 0x46;

  in_f21 = in_f21 * 255.0;

  if (in_f21 < 2.1474836e+09) {

    uStack_1 = (u8)(int)in_f21;

  }

  else {

    uStack_1 = (u8)(int)(in_f21 - 2.1474836e+09);

  }

  FUN_0021d950(puVar2 + 0x44,&uStack_4);

  if (puVar2[1] == 1) {

    fVar6 = (181.01933 - DAT_007caff0) / 1.4142135;

    fStack_14 = ((float)(int)puVar2[3] / 10.0) * (544.0 - fVar6);

    fStack_30 = fVar6 + 320.0 + fStack_14;

    fStack_2c = fVar6 + -320.0 + fStack_14;

    fStack_28 = fVar6 + -224.0 + fStack_14;

    fStack_24 = fVar6 + 224.0 + fStack_14;

    fStack_20 = fStack_14 + -96.0;

    fStack_1c = fStack_14 + 352.0;

    fStack_18 = fStack_14 + 448.0;

    fStack_14 = fStack_14 + -192.0;

  }

  else if (puVar2[1] == 0) {

    fStack_30 = 320.0;

    fStack_2c = -320.0;

    fStack_28 = -224.0;

    fStack_24 = 224.0;

    fStack_20 = -96.0;

    fStack_1c = 352.0;

    fStack_18 = 448.0;

    fStack_14 = -192.0;

  }

  FUN_0021d890(puVar2 + 0x84,&fStack_30);

  uVar7 = FUN_0021ea00(0x23);

  FUN_0021eac0(puVar2 + 0x84,(float)uVar7);

  uStack_4 = 0x4f;

  uStack_3 = 0xa4;

  uStack_2 = 0xff;

  uStack_1 = 0xff;

  FUN_0021d950(puVar2 + 0x84,&uStack_4);

  fStack_30 = 0.0;

  fStack_2c = 0.0;

  fStack_28 = 640.0;

  fStack_24 = 448.0;

  FUN_0021d8e0(puVar2 + 0x1c4,&fStack_30);

  uStack_4 = 0xff;

  uStack_3 = 0xff;

  uStack_2 = 0xff;

  uStack_1 = 0xff;

  FUN_0021d950(puVar2 + 0x1c4,&uStack_4);

  puVar2[0x204] = 0x44014000;

  puVar2[0x205] = 0x43e00000;

  puVar2[0x214] = 0x44200000;

  puVar2[0x215] = 0x43a28000;

  puVar2[0x224] = 0x44200000;

  puVar2[0x225] = 0x43e00000;

  puVar2[0x20c] = 0x429e0000;

  puVar2[0x20d] = 0x43240000;

  puVar2[0x20e] = 0x437f0000;

  puVar2[0x20f] = 0x437f0000;

  puVar2[0x21c] = 0x429e0000;

  puVar2[0x21d] = 0x43240000;

  puVar2[0x21e] = 0x437f0000;

  puVar2[0x21f] = 0x437f0000;

  puVar2[0x22c] = 0x429e0000;

  puVar2[0x22d] = 0x43240000;

  puVar2[0x22e] = 0x437f0000;

  puVar2[0x22f] = 0x437f0000;

  return;

}

// FUN_0025ED40 NONMATCHING


void FUN_0025ed40(void)



{

  int iVar1;

  u64 uVar2;

  

  if (sBrItem == 0) {

    FUN_0019d3f0(0x68ebf8,0x75);

  }

  iVar1 = (int)sBrItem;

  (*DAT_00960090)(9,2);

  (*DAT_00960090)(0x14,2);

  (*DAT_00960090)(8,1);

  (*DAT_00960090)(6,0);

  FUN_004d7f60(3,0x717fb);

  FUN_004d7f60(2,0x44);

  (*DAT_00960090)(1,0);

  (*DAT_0096009c)(iVar1 + 0x310,4,0,1,2);

  (*DAT_0096009c)(iVar1 + 0x310,4,0,2,3);

  (*DAT_00960090)(0x14,2);

  (*DAT_00960090)(8,1);

  (*DAT_00960090)(6,0);

  FUN_004d7f60(3,0x717fb);

  FUN_004d7f60(2,0x44);

  (*DAT_00960090)(1,0);

  (*DAT_0096009c)(iVar1 + 0x10,4,0,1,2);

  (*DAT_0096009c)(iVar1 + 0x10,4,0,2,3);

  (*DAT_00960090)(8,0);

  (*DAT_00960090)(6,1);

  uVar2 = FUN_00260940(*(u32 *)(iVar1 + 8),0x3a);

  (*DAT_00960090)(1,uVar2);

  (*DAT_0096009c)(iVar1 + 0x710,4,0,1,2);

  (*DAT_0096009c)(iVar1 + 0x710,4,0,2,3);

  (*DAT_00960090)(1,0);

  (*DAT_0096009c)(iVar1 + 0x810,4,0,1,2);

  (*DAT_00960090)(8,1);

  (*DAT_00960090)(6,1);

  FUN_004d7f60(3,0x717fb);

  FUN_004d7f60(2,0x44);

  (*DAT_00960090)(6,1);

  (*DAT_00960090)(6,1);

  (*DAT_00960090)(8,1);

  (*DAT_00960090)(1,0);

  (*DAT_0096009c)(iVar1 + 0x210,4,0,1,2);

  (*DAT_0096009c)(iVar1 + 0x210,4,0,2,3);

  if (*(int *)(iVar1 + 4) == 1) {

    (*DAT_00960090)(6,0);

    (*DAT_00960090)(8,0);

    (*DAT_00960090)(1,0);

    (*DAT_0096009c)(iVar1 + 0x110,4,0,1,2);

    (*DAT_0096009c)(iVar1 + 0x110,4,0,2,3);

  }

  else if (*(int *)(iVar1 + 4) == 0) {

    (*DAT_00960090)(6);

    (*DAT_00960090)(8,1);

    (*DAT_00960090)(1,0);

    (*DAT_0096009c)(iVar1 + 0x110,4,0,1,2);

    (*DAT_0096009c)(iVar1 + 0x110,4,0,2,3);

  }

  (*DAT_00960090)(6,1);

  (*DAT_00960090)(6,1);

  (*DAT_00960090)(8,0);

  uVar2 = FUN_00260940(*(u32 *)(iVar1 + 8),0x34);

  (*DAT_00960090)(1,uVar2);

  (*DAT_0096009c)(iVar1 + 0x410,4,0,1,2);

  (*DAT_0096009c)(iVar1 + 0x410,4,0,2,3);

  uVar2 = FUN_00260940(*(u32 *)(iVar1 + 8),0x35);

  (*DAT_00960090)(1,uVar2);

  (*DAT_0096009c)(iVar1 + 0x510,4,0,1,2);

  (*DAT_0096009c)(iVar1 + 0x510,4,0,2,3);

  uVar2 = FUN_00260940(*(u32 *)(iVar1 + 8),0x36);

  (*DAT_00960090)(1,uVar2);

  (*DAT_0096009c)(iVar1 + 0x610,4,0,1,2);

  (*DAT_0096009c)(iVar1 + 0x610,4,0,2,3);

  return;

}





































// FUN_0025F5D0 NONMATCHING
void FUN_0025f5d0(int param_1,u64 param_2,u64 param_3)



{

  int iVar1;

  u32 uVar2;

  int iVar3;

  int iVar4;

  float fVar5;

  u8 abStack_20 [7];

  u8 bStack_19;

  u8 bStack_18;

  u8 bStack_17;

  u8 bStack_16;

  u8 bStack_15;

  u8 bStack_14;

  u8 bStack_13;

  u8 bStack_12;

  u8 bStack_11;

  u32 uStack_10;

  u32 uStack_c;

  u32 uStack_8;

  u32 uStack_4;

  

  iVar1 = *(int *)((int)param_2 + 0x184);

  iVar3 = FUN_00198590();

  fVar5 = 1.0 / *(float *)(iVar3 + 0x80);


  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

    iVar4 = iVar3 * 4;

    uVar2 = *(u32 *)(iVar1 + (int)param_3 * 0x80 + iVar4 + 100);

    abStack_20[iVar4] = (u8)((uVar2 >> 0x18) * 0xff >> 7);

    abStack_20[iVar4 + 1] = (u8)((uVar2 >> 0x10 & 0xff) * 0xff >> 7);

    abStack_20[iVar4 + 2] = (u8)((uVar2 >> 8 & 0xff) * 0xff >> 7);

    abStack_20[iVar4 + 3] = (u8)((uVar2 & 0xff) * 0xff >> 7);

  }

  *(u32 *)(param_1 + 0x10) = uStack_10;

  *(u32 *)(param_1 + 0x14) = uStack_c;

  *(float *)(param_1 + 0x18) = fVar5;

  *(u32 *)(param_1 + 8) = DAT_00960088;

  *(float *)(param_1 + 0x20) = (float)abStack_20[0];

  *(float *)(param_1 + 0x24) = (float)abStack_20[1];

  *(float *)(param_1 + 0x28) = (float)abStack_20[2];

  *(float *)(param_1 + 0x2c) = (float)abStack_20[3];

  *(u32 *)(param_1 + 0x50) = uStack_8;

  *(u32 *)(param_1 + 0x54) = uStack_c;

  *(float *)(param_1 + 0x58) = fVar5;

  *(u32 *)(param_1 + 0x48) = DAT_00960088;

  *(float *)(param_1 + 0x60) = (float)abStack_20[4];

  *(float *)(param_1 + 100) = (float)abStack_20[5];

  *(float *)(param_1 + 0x68) = (float)abStack_20[6];

  *(float *)(param_1 + 0x6c) = (float)bStack_19;

  *(u32 *)(param_1 + 0x90) = uStack_8;

  *(u32 *)(param_1 + 0x94) = uStack_4;

  *(float *)(param_1 + 0x98) = fVar5;

  *(u32 *)(param_1 + 0x88) = DAT_00960088;

  *(float *)(param_1 + 0xa0) = (float)bStack_18;

  *(float *)(param_1 + 0xa4) = (float)bStack_17;

  *(float *)(param_1 + 0xa8) = (float)bStack_16;

  *(float *)(param_1 + 0xac) = (float)bStack_15;

  *(u32 *)(param_1 + 0xd0) = uStack_10;

  *(u32 *)(param_1 + 0xd4) = uStack_4;

  *(float *)(param_1 + 0xd8) = fVar5;

  *(u32 *)(param_1 + 200) = DAT_00960088;

  *(float *)(param_1 + 0xe0) = (float)bStack_14;

  *(float *)(param_1 + 0xe4) = (float)bStack_13;

  *(float *)(param_1 + 0xe8) = (float)bStack_12;

  *(float *)(param_1 + 0xec) = (float)bStack_11;

  return;

}
