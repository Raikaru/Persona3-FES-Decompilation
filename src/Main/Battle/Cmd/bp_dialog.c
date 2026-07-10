#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_0025be60(u64 param_1,u64 param_2,u64 param_3);
void FUN_0025c220(void);
void FUN_0025c9c0(void);
void FUN_0025cd30(void);
void FUN_0025cdb0(float param_1,float param_2,int param_3);
void FUN_0025ce30(float param_1,float param_2,int param_3);
void FUN_0025ceb0(int param_1);
void FUN_0025cf00(u32 *param_1);
void FUN_0025cf10(void);
void FUN_0025cf20(void);
static u32* sBpDialog678;
static u32* sBpDialog36c;
static u32* sBpDialog368; // 007ce368
extern u32 DAT_007e094e;
extern code DAT_00960090;
extern code DAT_0096009c;
extern int iGpffffb6fc;

extern void FUN_0019d3f0(const char* file, s32 line);
extern const char DAT_0068ebd8[];
#define FUN_0019d3f0(file, line) FUN_0019d3f0((const char*)(file), line)

// FUN_0025c190
u32 bpDialog0025c190(void)
{
    K_ASSERT(sBpDialog368 != NULL, 0x3c);
    return *sBpDialog368 & 2;
}

// FUN_0025c1e0
u32 bpDialog0025c1e0(void)
{
    K_ASSERT(sBpDialog368 != NULL, 0x3c);
    return sBpDialog368[4];
}

void FUN_003b0170();

// FUN_0025bdf0
void bpDialog0025bdf0(u32* param_1)
{
    *param_1 = 0;
    sBpDialog368 = param_1;
}

// FUN_0025be00
void bpDialog0025be00(void)
{
    K_ASSERT(sBpDialog368 != NULL, 0x3c);
    if (*sBpDialog368 & 1) {
        FUN_003b0170(sBpDialog368[1]);
    }
    sBpDialog368 = NULL;
}

// FUN_0025c110
void bpDialog0025c110(void)
{
    u32* puVar1;

    K_ASSERT(sBpDialog368 != NULL, 0x3c);
    puVar1 = sBpDialog368;
    K_ASSERT((*sBpDialog368 & 1) != 0, 0xa7);
    *puVar1 |= 8;
}

/* Recovered battle-misc harvest: 0x0025BE60-0x0025CF20 */
// FUN_0025BE60 NONMATCHING


void FUN_0025be60(u64 param_1,u64 param_2,u64 param_3)



{

  u32 *puVar1;

  int iVar2;

  u32 uVar3;

  u64 uVar4;

  long lVar5;

  u64 uVar6;

  

  if (sBpDialog678 == (u32 *)0x0) {

    FUN_0019d3f0(0x68ebd8,0x3c);

  }

  iVar2 = iGpffffb6fc;

  puVar1 = sBpDialog678;

  uVar4 = FUN_0021c3f0(0);

  if ((*puVar1 & 4) != 0) {


  }

  uVar3 = FUN_003a52c0(0,100,100,0xffffffffffffffff,0,6,*(u32 *)(iVar2 + 0xba0),param_1);

  puVar1[1] = uVar3;

  uVar3 = FUN_003a52c0(0,100,100,0xffffffffffffffff,0,0,*(u32 *)(iVar2 + 0xba0),param_2);

  puVar1[2] = uVar3;

  uVar3 = FUN_003a52c0(0,100,100,0xffffffffffffffff,0,0,*(u32 *)(iVar2 + 0xba0),param_3);

  puVar1[3] = uVar3;


  if (lVar5 == 2) {

    puVar1[0xca] = 1;

  }

  else if (lVar5 == 1) {

    puVar1[0xca] = 0;

  }

  else {

    FUN_0019d3f0(0x68ebd8,0x7b);

  }

  if (puVar1[0xca] == 1) {

    puVar1[200] = 0x57;

    puVar1[0xc9] = 0x58;

  }

  else if (puVar1[0xca] == 0) {

    puVar1[200] = 0x55;

    puVar1[0xc9] = 0x56;

  }

  uVar6 = FUN_0021cca0(uVar4,puVar1[200]);

  FUN_0021d3b0(puVar1 + 8,uVar6);

  uVar6 = FUN_0021cca0(uVar4,puVar1[200]);

  FUN_0021e380(puVar1 + 0x48,uVar6,1);

  uVar6 = FUN_0021cca0(uVar4,puVar1[0xc9]);

  FUN_0021d3b0(puVar1 + 0x88,uVar6);

  uVar6 = FUN_0021cca0(uVar4,0x59);

  FUN_0021d3b0(puVar1 + 0xcc,uVar6);

  uVar4 = FUN_0021cca0(uVar4,0x5a);

  FUN_0021d3b0(puVar1 + 0x10c,uVar4);

  puVar1[5] = 0;

  puVar1[6] = 0;

  uVar3 = *puVar1;

  *puVar1 = uVar3 & 0xfffffffd;

  uVar3 = uVar3 & 0xfffffff5;

  *puVar1 = uVar3;

  *puVar1 = uVar3 | 4;

  *puVar1 = uVar3 | 5;

  return;

}

// FUN_0025C220 NONMATCHING


void FUN_0025c220(void)



{

  u32 *puVar1;

  int iVar2;

  int iVar3;

  u64 uVar4;

  u32 uVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float in_f23;

  float fVar9;

  float fVar10;

  float fVar11;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  u8 uStack_4;

  u8 uStack_3;

  u8 uStack_2;

  u8 uStack_1;

  

  if (sBpDialog368 == (u32 *)0x0) {

    FUN_0019d3f0(0x68ebd8,0x3c);

  }

  puVar1 = sBpDialog368;

  uVar4 = FUN_0021c3f0(0);

  uVar5 = ~*puVar1;

  if ((uVar5 & 1) == 0) {

    if (((7 < (int)puVar1[5]) && ((uVar5 & 2) != 0)) && ((*puVar1 & 0x10) != 0)) {

      if ((DAT_007e094e & 0x40) == 0) {

        if ((DAT_007e094e & 0x20) != 0) {

          puVar1[4] = 1;

          *puVar1 = *puVar1 | 2;

          FUN_0010a4e0(0,0,0,2);

        }

      }

      else {

        puVar1[4] = 0;

        *puVar1 = *puVar1 | 2;

        FUN_0010a4e0(0,0,0,1);

      }

    }

    if ((int)puVar1[5] < 8) {

      puVar1[5] = puVar1[5] + 1;

    }

    else if ((~*puVar1 & 0x10) != 0) {

      *puVar1 = *puVar1 | 0x10;

    }

    if (((*puVar1 & 8) != 0) && (uVar5 = puVar1[6], puVar1[6] = uVar5 + 1, uVar5 + 1 == 4)) {


      *puVar1 = *puVar1 & 0xfffffffe;

    }

    iVar2 = FUN_003b19d0(puVar1[2]);

    iVar3 = FUN_003b19d0(puVar1[3]);

    fVar11 = 252.0 - ((float)iVar2 + 0.0 + (float)iVar3 + 25.0 + 30.0 + 30.0) / 2.0;

    if (puVar1[0xca] == 1) {

      in_f23 = 367.0;

    }

    else if (puVar1[0xca] == 0) {

      in_f23 = 339.0;

    }

    fVar6 = 1.0;

    fVar10 = 1.0 - (float)(int)puVar1[6] / 4.0;

    uVar5 = puVar1[5];

    if ((int)uVar5 < 4) {

      fVar6 = (float)(int)uVar5 / 4.0;

    }

    if ((int)uVar5 < 0) {

      fVar8 = 0.0;

    }

    else if ((int)uVar5 < 8) {

      fVar8 = (float)(int)uVar5 / 8.0;

    }

    else {

      fVar8 = 1.0;

    }


    fVar9 = fVar11 + 30.0;


    iVar2 = FUN_003b19d0(puVar1[2]);


    fVar7 = fVar6 * 255.0 * fVar10;

    fVar6 = fVar7;

    if (2.1474836e+09 <= fVar7) {

      fVar6 = fVar7 - 2.1474836e+09;

    }

    thunk_FUN_003b0e54(puVar1[1],(int)fVar6 & 0xffU | 0xffffff00);

    fVar8 = fVar10 * 255.0 * fVar8;

    fVar6 = fVar8;

    if (2.1474836e+09 <= fVar8) {

      fVar6 = fVar8 - 2.1474836e+09;

    }

    uVar5 = (int)fVar6 & 0xffU | 0xffffff00;

    thunk_FUN_003b0e54(puVar1[2],uVar5);

    thunk_FUN_003b0e54(puVar1[3],uVar5);

    iVar2 = FUN_0021cca0(uVar4,puVar1[200]);

    fStack_30 = 32.0;

    fStack_2c = 282.0;

    fStack_28 = (float)*(int *)(iVar2 + 0xc);

    fStack_24 = (float)*(int *)(iVar2 + 0x10);

    FUN_0021d8e0(puVar1 + 8,&fStack_30);

    fStack_30 = (float)*(int *)(iVar2 + 0xc) + 32.0;

    fStack_2c = 282.0;

    fStack_28 = 419.0;

    fStack_24 = (float)*(int *)(iVar2 + 0x10);

    FUN_0021d8e0(puVar1 + 0x48,&fStack_30);

    iVar2 = FUN_0021cca0(uVar4,puVar1[0xc9]);

    fStack_30 = 462.0;

    fStack_2c = 282.0;

    fStack_28 = (float)*(int *)(iVar2 + 0xc);

    fStack_24 = (float)*(int *)(iVar2 + 0x10);

    FUN_0021d8e0(puVar1 + 0x88,&fStack_30);

    uStack_4 = 0xff;

    uStack_3 = 0xff;

    uStack_2 = 0xff;

    if (fVar7 < 2.1474836e+09) {

      uStack_1 = (u8)(int)fVar7;

    }

    else {

      uStack_1 = (u8)(int)(fVar7 - 2.1474836e+09);

    }

    for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {

      FUN_0021d950(puVar1 + iVar2 * 0x40 + 8,&uStack_4);

    }

    iVar2 = FUN_0021cca0(uVar4,0x59);

    fStack_28 = (float)*(int *)(iVar2 + 0xc);

    fStack_24 = (float)*(int *)(iVar2 + 0x10);

    fStack_30 = fVar11;

    fStack_2c = in_f23;

    FUN_0021d8e0(puVar1 + 0xcc,&fStack_30);

    iVar2 = FUN_0021cca0(uVar4,0x5a);

    iVar3 = FUN_003b19d0(puVar1[2]);

    fStack_30 = fVar9 + (float)iVar3 + 25.0;

    fStack_28 = (float)*(int *)(iVar2 + 0xc);

    fStack_24 = (float)*(int *)(iVar2 + 0x10);

    fStack_2c = in_f23;

    FUN_0021d8e0(puVar1 + 0x10c,&fStack_30);

    uStack_4 = 0xff;

    uStack_3 = 0xff;

    uStack_2 = 0xff;

    if (fVar8 < 2.1474836e+09) {

      uStack_1 = (u8)(int)fVar8;

    }

    else {

      uStack_1 = (u8)(int)(fVar8 - 2.1474836e+09);

    }

    for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {

      FUN_0021d950(puVar1 + iVar2 * 0x40 + 0xcc,&uStack_4);

    }

  }

  return;

}

// FUN_0025C9C0 NONMATCHING


void FUN_0025c9c0(void)



{

  u32 *puVar1;

  u64 uVar2;

  u64 uVar3;

  

  if (sBpDialog368 == (u32 *)0x0) {

    FUN_0019d3f0(0x68ebd8,0x3c);

  }

  puVar1 = sBpDialog368;

  uVar2 = FUN_0021c3f0(0);

  if ((~*puVar1 & 1) == 0) {

    (*DAT_00960090)(9,2);

    (*DAT_00960090)(0x14,2);

    (*DAT_00960090)(8,0);

    (*DAT_00960090)(6,0);

    uVar3 = FUN_0021cca0(uVar2,puVar1[200]);

    uVar3 = FUN_0021cce0(uVar3);

    (*DAT_00960090)(1,uVar3);

    FUN_004d7f60(3,0x717fb);

    FUN_004d7f60(2,0x44);

    (*DAT_0096009c)(puVar1 + 8,4,0,1,2);

    (*DAT_0096009c)(puVar1 + 8,4,0,2,3);

    (*DAT_0096009c)(puVar1 + 0x48,4,0,1,2);

    (*DAT_0096009c)(puVar1 + 0x48,4,0,2,3);

    uVar3 = FUN_0021cca0(uVar2,puVar1[0xc9]);

    uVar3 = FUN_0021cce0(uVar3);

    (*DAT_00960090)(1,uVar3);

    (*DAT_0096009c)(puVar1 + 0x88,4,0,1,2);

    (*DAT_0096009c)(puVar1 + 0x88,4,0,2,3);

    FUN_004d7f60(3,0x717fb);

    FUN_004d7f60(2,0x44);

    uVar3 = FUN_0021cca0(uVar2,0x59);

    uVar3 = FUN_0021cce0(uVar3);

    (*DAT_00960090)(1,uVar3);

    (*DAT_0096009c)(puVar1 + 0xcc,4,0,1,2);

    (*DAT_0096009c)(puVar1 + 0xcc,4,0,2,3);

    uVar2 = FUN_0021cca0(uVar2,0x5a);

    uVar2 = FUN_0021cce0(uVar2);

    (*DAT_00960090)(1,uVar2);

    (*DAT_0096009c)(puVar1 + 0x10c,4,0,1,2);

    (*DAT_0096009c)(puVar1 + 0x10c,4,0,2,3);

    FUN_003b1360(puVar1[1],1,0);

    FUN_003b1360(puVar1[2],1,0);

    FUN_003b1360(puVar1[3],1,0);

  }

  return;

}

// FUN_0025CD30


void FUN_0025cd30(void)



{

  u32 *puVar1;

  

  if (sBpDialog368 == (u32 *)0x0) {
    FUN_0019d3f0(DAT_0068ebd8,0x3c);

  }

  puVar1 = sBpDialog368;

  FUN_003b0170(sBpDialog368[1]);

  FUN_003b0170(puVar1[2]);

  FUN_003b0170(puVar1[3]);

  *puVar1 = *puVar1 & 0xfffffffb;

  return;

}

// FUN_0025CDB0 NONMATCHING


void FUN_0025cdb0(float param_1,float param_2,int param_3)



{

  int iVar1;

  

  iVar1 = 0;

  for (; param_3 != 0; param_3 = *(int *)(param_3 + 0x24)) {

    if (param_3 != 0) {

      iVar1 = param_3;

    }

  }

  FUN_003b1c40((int)(param_1 * 16.0),(int)(param_2 * 8.0),iVar1);

  return;

}

// FUN_0025CE30 NONMATCHING


void FUN_0025ce30(float param_1,float param_2,int param_3)



{

  int iVar1;

  

  iVar1 = 0;

  for (; param_3 != 0; param_3 = *(int *)(param_3 + 0x24)) {

    if (param_3 != 0) {

      iVar1 = param_3;

    }

  }

  FUN_003b1c90((int)(param_1 * 16.0),(int)(param_2 * 8.0),iVar1);

  return;

}

// FUN_0025CEB0


void FUN_0025ceb0(int param_1)



{

  int iVar1;

  

  iVar1 = 0;

  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {

    if (param_1 != 0) {

      iVar1 = param_1;

    }

  }

  FUN_003b1a90(iVar1);

  return;

}

// FUN_0025CF00


void FUN_0025cf00(u32 *param_1)



{

  *param_1 = 0;

  sBpDialog36c = param_1;

  return;

}

// FUN_0025CF10


void FUN_0025cf10(void)



{

  sBpDialog36c = 0;

  return;

}

// FUN_0025CF20 NONMATCHING


void FUN_0025cf20(void)



{

  u32 uVar1;

  u32 *puVar2;

  u64 uVar3;

  u64 uVar4;

  int iVar5;

  

  if (sBpDialog36c == (u32 *)0x0) {

    FUN_0019d3f0(0x68ebe8,0x32);

  }

  puVar2 = sBpDialog36c;

  uVar3 = FUN_00267390();

  uVar4 = FUN_0021cca0(uVar3,0);

  FUN_0021d3b0(puVar2 + 4,uVar4);

  uVar3 = FUN_0021cca0(uVar3,1);

  for (iVar5 = 0; iVar5 < 7; iVar5 = iVar5 + 1) {

    FUN_0021d3b0(puVar2 + iVar5 * 0x40 + 0x44,uVar3);

  }

  puVar2[0x204] = 0;

  puVar2[0x205] = 0;

  puVar2[0x206] = 0;

  uVar1 = *puVar2;

  *puVar2 = uVar1 & 0xfffffffd;

  *puVar2 = uVar1 & 0xfffffffd | 4;

  FUN_0025d130();

  *puVar2 = *puVar2 | 1;

  return;

}
