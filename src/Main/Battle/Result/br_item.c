#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_0025da30(void);
void FUN_0025ed40(void);
KwlnTask* FUN_0025f370(KwlnTask* parent, void* battle_data);
void FUN_0025f5d0(int param_1, int param_2, int param_3);
void FUN_0025fb60(int param_1,int param_2,float *uv);
void FUN_0025fc50(int param_1,void* param_2,int param_3,int param_4);
extern f32 DAT_007caff0;
extern f32 DAT_00960088;
#pragma alias DAT_00960088_abs DAT_00960088
extern u8 DAT_00960088_abs[];
extern code DAT_00960090;
#pragma alias DAT_00960090_abs DAT_00960090
#pragma alias DAT_0096009c_abs DAT_0096009c
extern code DAT_00960090_abs[];
extern code DAT_0096009c_abs[];
extern code DAT_00960178;
extern char D_0068EC08[];

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

// FUN_0025f4a0
u32 brItem0025f4a0(void)
{
    FUN_0025da30();
    FUN_0025ed40();
    K_ASSERT(sBrItem != NULL, 0x75);
    if ((*sBrItem & 1) == 0) {
        return -1;
    }
    return 0;
}

// FUN_0025d8a0
void brItem0025d8a0(void* param_1)
{
    u32* puVar1;
    float fVar2;
    float fVar3;

    K_ASSERT(sBrItem != NULL, 0x75);
    puVar1 = sBrItem;
    sBrItem[2] = (u32)param_1;
    FUN_0025f5d0((int)(puVar1 + 0x104), (u32)param_1, 0x34);
    fVar2 = FUN_0021ea00(0x1e);
    FUN_0021eac0(puVar1 + 0x104, fVar2);
    FUN_0025f5d0((int)(puVar1 + 0x144), puVar1[2], 0x35);
    fVar2 = FUN_0021ea00(0x1e);
    FUN_0021eac0(puVar1 + 0x144, fVar2);
    FUN_0025f5d0((int)(puVar1 + 0x184), puVar1[2], 0x36);
    fVar2 = FUN_0021ea00(0x1e);
    FUN_0021eac0(puVar1 + 0x184, fVar2);
    FUN_0025f5d0((int)(puVar1 + 0x1c4), puVar1[2], 0x3a);
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
// FUN_0025F370


KwlnTask* FUN_0025f370(KwlnTask* parent, void* battle_data)
{
    u32* work;
    KwlnTask* task;
    float rect[4];
    u8 color[4];

    work = (u32*)(*(code*)0x00960178)(0x8d0, 0x40000);
    task = kwlnTaskInitEx(D_0068EC08, 0x18b5, 1, 2,
                          (KwlnTaskUpdateFunc)brItem0025f4a0,
                          (KwlnTaskDestroyFunc)brItem0025f510, work);
    kwlnTaskAddChild(parent, task);
    *work = 0;

    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = 640.0f;
    rect[3] = 448.0f;
    FUN_0021d8e0(work + 0xc4, rect);
    FUN_0021eac0(work + 0xc4, FUN_0021ea00(10));

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = 0;
    FUN_0021d950(work + 0xc4, color);

    sBrItem = work;
    brItem0025d8a0(battle_data);
    sBrItem374 = (u32)task;
    return task;
}

// FUN_0025FB60
void FUN_0025fb60(int contextAddress, int entryIndex, float* uv)
{
    u8* entry;
    uintptr_t resource;
    uintptr_t resourceAddress;

    entry = *(u8**)(contextAddress + 0x184) + entryIndex * 0x80;
    resourceAddress = *(s32*)(entry + 0x14) * sizeof(uintptr_t);
    resourceAddress += contextAddress;
    resource = *(uintptr_t*)(resourceAddress + 0x104);

    {
        f32 size[2] = { 0.0f, 0.0f };

        size[0] = (f32)*(s32*)(entry + 0x54);
        size[1] = (f32)*(s32*)(entry + 0x5c);

        {
            f32 offset[2] = { 0.0f, 0.0f };
            s32* dimensions;
            f32 width;
            f32 height;
            s32 rawWidth;
            s32 rawHeight;

            offset[0] = (f32)*(s32*)(entry + 0x58);
            offset[1] = (f32)*(s32*)(entry + 0x60);

            dimensions = (s32*)(resource + 0x0c);
            rawWidth = *dimensions++;
            rawHeight = *dimensions;
            width = (f32)rawWidth;
            uv[0] = size[0] / width;
            uv[2] = size[1] / width;
            height = (f32)rawHeight;
            uv[1] = offset[0] / height;
            uv[3] = offset[1] / height;
        }
    }
}





































// FUN_0025FC50 NONMATCHING
void FUN_0025fc50(int param_1,void* param_2,int param_3,int param_4)
{

  int iVar1;
    u32 unaff_s4_lo;
    u32 unaff_s5_lo;
    u32 unaff_s3_lo;
    u32 unaff_s2_lo;
    float fVar2;
  union {
    u32 bits;
    float value;
  } uStack[4];


  

  iVar1 = FUN_00198590();

  fVar2 = 1.0f / *(float *)(iVar1 + 0x80);

  iVar1 = *(int *)((int)param_2 + 0x184) + (int)param_3 * 0x80;

  switch(param_4) {

  case 0:

    FUN_00260430(param_2,param_3,&uStack[0],0);

    unaff_s5_lo = *(u32 *)(iVar1 + 100);

    unaff_s4_lo = *(u32 *)(iVar1 + 0x68);

    unaff_s3_lo = unaff_s4_lo;

    unaff_s2_lo = unaff_s5_lo;

    break;

  case 1:

    FUN_00260430(param_2,param_3,&uStack[0],1);

    unaff_s5_lo = *(u32 *)(iVar1 + 0x68);

    unaff_s4_lo = unaff_s5_lo;

    unaff_s3_lo = *(u32 *)(iVar1 + 0x6c);

    unaff_s2_lo = unaff_s3_lo;

    break;

  case 2:

    FUN_00260430(param_2,param_3,&uStack[0],2);

    unaff_s5_lo = *(u32 *)(iVar1 + 0x70);

    unaff_s4_lo = *(u32 *)(iVar1 + 0x6c);

    unaff_s3_lo = unaff_s4_lo;

    unaff_s2_lo = unaff_s5_lo;

    break;

  case 3:

    FUN_00260430(param_2,param_3,&uStack[0],3);

    unaff_s5_lo = *(u32 *)(iVar1 + 100);

    unaff_s4_lo = unaff_s5_lo;

    unaff_s3_lo = *(u32 *)(iVar1 + 0x70);

    unaff_s2_lo = unaff_s3_lo;

    break;

  case 4:

    FUN_00260430(param_2,param_3,&uStack[0],4);

    unaff_s5_lo = *(u32 *)(iVar1 + 0x68);

    unaff_s4_lo = unaff_s5_lo;

    unaff_s3_lo = unaff_s5_lo;

    unaff_s2_lo = unaff_s5_lo;

    break;

  case 5:

    FUN_00260430(param_2,param_3,&uStack[0],5);

    unaff_s5_lo = *(u32 *)(iVar1 + 0x6c);

    unaff_s4_lo = unaff_s5_lo;

    unaff_s3_lo = unaff_s5_lo;

    unaff_s2_lo = unaff_s5_lo;

    break;

  case 6:

    FUN_00260430(param_2,param_3,&uStack[0],6);

    unaff_s5_lo = *(u32 *)(iVar1 + 0x70);

    unaff_s4_lo = unaff_s5_lo;

    unaff_s3_lo = unaff_s5_lo;

    unaff_s2_lo = unaff_s5_lo;

    break;

  case 7:

    FUN_00260430(param_2,param_3,&uStack[0],7);

    unaff_s5_lo = *(u32 *)(iVar1 + 100);

    unaff_s4_lo = unaff_s5_lo;

    unaff_s3_lo = unaff_s5_lo;

    unaff_s2_lo = unaff_s5_lo;

  }

  *(float *)(param_1 + 0x10) = uStack[0].value;

  *(float *)(param_1 + 0x14) = uStack[1].value;

  *(float *)(param_1 + 0x18) = fVar2;

  *(float *)(param_1 + 8) = *(f32*)DAT_00960088_abs;

  *(float *)(param_1 + 0x20) = (float)((unaff_s5_lo >> 0x18) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0x24) = (float)((unaff_s5_lo >> 0x10 & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0x28) = (float)((unaff_s5_lo >> 8 & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0x2c) = (float)((unaff_s5_lo & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0x50) = uStack[2].value;

  *(float *)(param_1 + 0x54) = uStack[1].value;

  *(float *)(param_1 + 0x58) = fVar2;

  *(float *)(param_1 + 0x48) = *(f32*)DAT_00960088_abs;

  *(float *)(param_1 + 0x60) = (float)((unaff_s4_lo >> 0x18) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 100) = (float)((unaff_s4_lo >> 0x10 & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0x68) = (float)((unaff_s4_lo >> 8 & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0x6c) = (float)((unaff_s4_lo & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0x90) = uStack[2].value;

  *(float *)(param_1 + 0x94) = uStack[3].value;

  *(float *)(param_1 + 0x98) = fVar2;

  *(float *)(param_1 + 0x88) = *(f32*)DAT_00960088_abs;

  *(float *)(param_1 + 0xa0) = (float)((unaff_s3_lo >> 0x18) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0xa4) = (float)((unaff_s3_lo >> 0x10 & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0xa8) = (float)((unaff_s3_lo >> 8 & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0xac) = (float)((unaff_s3_lo & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0xd0) = uStack[0].value;

  *(float *)(param_1 + 0xd4) = uStack[3].value;

  *(float *)(param_1 + 0xd8) = fVar2;

  *(float *)(param_1 + 200) = *(f32*)DAT_00960088_abs;

  *(float *)(param_1 + 0xe0) = (float)((unaff_s2_lo >> 0x18) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0xe4) = (float)((unaff_s2_lo >> 0x10 & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0xe8) = (float)((unaff_s2_lo >> 8 & 0xff) * 0xff >> 7 & 0xff);

  *(float *)(param_1 + 0xec) = (float)((unaff_s2_lo & 0xff) * 0xff >> 7 & 0xff);

  return;

}




























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

  float quad[8];

  

  

  

  

  

  

  

  u8 color[4];

  

  

  

  

  if (sBrItem == (u32 *)0x0) {

    FUN_0019d3f0(0x68ebf8,0x75);

  }

  puVar2 = sBrItem;

  switch (puVar2[1]) {
  case 0:
    if ((int)puVar2[3] < 10) {
      puVar2[3] = puVar2[3] + 1;
    }
    else {
      *puVar2 = *puVar2 & 0xfffffffd;
    }
    break;
  case 1:
    if ((int)puVar2[3] < 10) {
      puVar2[3] = puVar2[3] + 1;
    }
    else {
      uVar1 = *puVar2;
      *puVar2 = uVar1 & 0xfffffffd;
      *puVar2 = uVar1 & 0xfffffffe;
    }
    break;
  }

  iVar3 = FUN_00260900(puVar2[2],0x34);

  iVar4 = FUN_00260920(puVar2[2],0x34);

  if (puVar2[1] == 1) {

    if ((int)puVar2[3] < 3) {

      in_f21 = (float)(int)puVar2[3] / 3.0f;

      quad[0] = in_f21 * 150.0f + 6.0f;

      in_f21 = 1.0f - in_f21;

      quad[1] = quad[0];

    }

    else {

      quad[0] = 156.0f;

      quad[1] = 156.0f;

      in_f21 = 0.0f;

    }

  }

  else if (puVar2[1] == 0) {

    in_f21 = 1.0f;

    if ((int)puVar2[3] < 5) {

      fVar9 = (float)(int)puVar2[3] / 5.0f;

      fVar6 = (float)iVar4 + 6.0f + 6.0f;

      fVar8 = 6.0f - ((float)iVar4 + 6.0f);

      quad[0] = fVar9 * (6.0f - fVar6) + fVar6 + 0.0f;

      quad[1] = fVar9 * (6.0f - fVar8) + fVar8 + 0.0f;

      in_f21 = 1.0f;

    }

    else {

      quad[0] = 6.0f;

      quad[1] = 6.0f;

    }

  }

  quad[2] = (float)iVar3;

  quad[3] = (float)iVar4;

  FUN_0021d8e0(puVar2 + 0x104,&quad[0]);

  color[0] = 0xff;

  color[1] = 0xff;

  color[2] = 0xff;

  fVar6 = in_f21 * 255.0f;

  if (fVar6 < 2.1474836e+09f) {

    color[3] = (u8)(int)fVar6;

  }

  else {

    color[3] = (u8)(int)(fVar6 - 2.1474836e+09f);

  }

  FUN_0021d950(puVar2 + 0x104,&color[0]);

  iVar3 = FUN_00260900(puVar2[2],0x35);

  iVar4 = FUN_00260920(puVar2[2],0x35);

  if (puVar2[1] == 1) {

    if ((int)puVar2[3] < 3) {

      in_f21 = (float)(int)puVar2[3] / 3.0f;

      quad[1] = in_f21 * 150.0f;

      quad[0] = quad[1] + 23.0f;

      quad[1] = quad[1] + 109.0f;

      in_f21 = 1.0f - in_f21;

    }

    else {

      quad[0] = 173.0f;

      quad[1] = 259.0f;

      in_f21 = 0.0f;

    }

  }

  else if (puVar2[1] == 0) {

    in_f21 = 1.0f;

    if ((int)puVar2[3] < 6) {

      fVar9 = (float)(int)puVar2[3] / 6.0f;

      iVar5 = FUN_00260920(puVar2[2],0x35);

      fVar6 = (float)iVar5 + 109.0f + 23.0f;

      fVar8 = 109.0f - ((float)iVar5 + 109.0f);

      quad[0] = fVar9 * (23.0f - fVar6) + fVar6 + 0.0f;

      quad[1] = fVar9 * (109.0f - fVar8) + fVar8 + 0.0f;

    }

    else {

      quad[0] = 23.0f;

      quad[1] = 109.0f;

    }

  }

  quad[2] = (float)iVar3;

  quad[3] = (float)iVar4;

  FUN_0021d8e0(puVar2 + 0x144,&quad[0]);

  color[0] = 0xff;

  color[1] = 0xff;

  color[2] = 0xff;

  fVar6 = in_f21 * 255.0f;

  if (fVar6 < 2.1474836e+09f) {

    color[3] = (u8)(int)fVar6;

  }

  else {

    color[3] = (u8)(int)(fVar6 - 2.1474836e+09f);

  }

  FUN_0021d950(puVar2 + 0x144,&color[0]);

  iVar3 = FUN_00260900(puVar2[2],0x36);

  iVar4 = FUN_00260920(puVar2[2],0x36);

  if (puVar2[1] == 1) {

    if ((int)puVar2[3] < 3) {

      in_f21 = (float)(int)puVar2[3] / 3.0f;

      quad[1] = in_f21 * 150.0f;

      quad[0] = quad[1] + 116.0f;

      quad[1] = quad[1] + 22.0f;

      in_f21 = 1.0f - in_f21;

    }

    else {

      quad[0] = 266.0f;

      quad[1] = 172.0f;

      in_f21 = 0.0f;

    }

  }

  else if (puVar2[1] == 0) {

    in_f21 = 1.0f;

    if ((int)puVar2[3] < 6) {

      fVar9 = (float)(int)puVar2[3] / 6.0f;

      iVar5 = FUN_00260920(puVar2[2],0x35);

      fVar8 = (float)iVar5 + 109.0f + 116.0f;

      fVar6 = 22.0f - ((float)iVar5 + 109.0f);

      quad[0] = fVar9 * (116.0f - fVar8) + fVar8 + 0.0f;

      quad[1] = fVar9 * (22.0f - fVar6) + fVar6 + 0.0f;

    }

    else {

      quad[0] = 116.0f;

      quad[1] = 22.0f;

    }

  }

  quad[2] = (float)iVar3;

  quad[3] = (float)iVar4;

  FUN_0021d8e0(puVar2 + 0x184,&quad[0]);

  color[0] = 0xff;

  color[1] = 0xff;

  color[2] = 0xff;

  fVar6 = in_f21 * 255.0f;

  if (fVar6 < 2.1474836e+09f) {

    color[3] = (u8)(int)fVar6;

  }

  else {

    color[3] = (u8)(int)(fVar6 - 2.1474836e+09f);

  }

  FUN_0021d950(puVar2 + 0x184,&color[0]);

  if (puVar2[1] == 1) {

    if ((int)puVar2[3] < 10) {

      quad[4] = 864.0f;

      quad[5] = 224.0f;

      quad[6] = 320.0f;

      quad[7] = 768.0f;

      quad[3] = (1.0f - (float)(int)puVar2[3] / 10.0f) *

                  (544.0f - (256.0f - DAT_007caff0 * 1.4142135f) / 1.4142135f);

      quad[0] = 320.0f - quad[3];

      quad[1] = 768.0f - quad[3];

      quad[2] = 864.0f - quad[3];

      quad[3] = 224.0f - quad[3];

    }

    else {

      quad[1] = (1088.0f / unaff_f22) / unaff_f22;

      quad[2] = quad[1] + 320.0f;

      quad[3] = quad[1] + -(640.0f / unaff_f22) / unaff_f22;

      quad[0] = quad[1] + -(448.0f / unaff_f22) / unaff_f22;

      quad[1] = quad[1] + 224.0f;

      quad[4] = quad[2];

      quad[5] = quad[3];

      quad[6] = quad[0];

      quad[7] = quad[1];

    }

  }

  else if (puVar2[1] == 0) {

    if ((int)puVar2[3] < 8) {

      quad[0] = 320.0f;

      quad[1] = -320.0f;

      quad[2] = -224.00002f;

      quad[3] = 224.0f;

      quad[7] = (((float)(int)puVar2[3] / 8.0f) * 1088.0f) / 1.4142135f;

      quad[4] = quad[7] + -224.00002f;

      quad[5] = quad[7] + 224.0f;

      quad[6] = quad[7] + 320.0f;

      quad[7] = quad[7] + -320.0f;

    }

    else {

      quad[0] = 320.0f;

      quad[1] = -(640.0f / unaff_f22) / unaff_f22;

      quad[2] = -(448.0f / unaff_f22) / unaff_f22;

      quad[3] = 224.0f;

      quad[7] = 1088.0f / unaff_f22;

      quad[4] = quad[2] + quad[7];

      quad[5] = quad[7] + 224.0f;

      quad[6] = quad[7] + 320.0f;

      quad[7] = quad[1] + quad[7];

    }

  }

  FUN_0021d890(puVar2 + 4,&quad[0]);

  uVar7 = FUN_0021ea00(0x32);

  FUN_0021eac0(puVar2 + 4,(float)uVar7);

  color[0] = 0;

  color[1] = 0;

  color[2] = 0;

  color[3] = 0;

  FUN_0021d950(puVar2 + 4,&color[0]);

  if (puVar2[1] == 1) {

    if ((int)puVar2[3] < 10) {

      quad[3] = (float)(int)puVar2[3] / 10.0f;

      in_f21 = 1.0f - quad[3];

      quad[3] = quad[3] * (544.0f - (181.01933f - DAT_007caff0) / 1.4142135f);

      quad[0] = quad[3] + 291.71573f;

      quad[1] = quad[3] + -348.28427f;

      quad[2] = quad[3] + -252.28427f;

      quad[3] = quad[3] + 195.71573f;

      quad[4] = quad[2] + 136.28427f;

      quad[5] = quad[3] + 136.28427f;

      quad[6] = quad[0] + 136.28427f;

      quad[7] = quad[1] + 136.28427f;

    }

    else {

      in_f21 = 0.0f;

      quad[0] = 0.0f;

      quad[1] = 0.0f;

      quad[2] = 0.0f;

      quad[3] = 0.0f;

      quad[4] = 0.0f;

      quad[5] = 0.0f;

      quad[6] = 0.0f;

      quad[7] = 0.0f;

    }

  }

  else if (puVar2[1] == 0) {

    quad[0] = 320.0f;

    quad[1] = -320.0f;

    quad[2] = -224.00002f;

    quad[3] = 224.0f;

    quad[4] = -116.000015f;

    quad[5] = 332.0f;

    quad[6] = 428.0f;

    quad[7] = -212.0f;

    in_f21 = 1.0f;

  }

  FUN_0021d890(puVar2 + 0x44,&quad[0]);

  uVar7 = FUN_0021ea00(0x23);

  FUN_0021eac0(puVar2 + 0x44,(float)uVar7);

  color[0] = 4;

  color[1] = 0x29;

  color[2] = 0x46;

  in_f21 = in_f21 * 255.0f;

  if (in_f21 < 2.1474836e+09f) {

    color[3] = (u8)(int)in_f21;

  }

  else {

    color[3] = (u8)(int)(in_f21 - 2.1474836e+09f);

  }

  FUN_0021d950(puVar2 + 0x44,&color[0]);

  if (puVar2[1] == 1) {

    fVar6 = (181.01933f - DAT_007caff0) / 1.4142135f;

    quad[7] = ((float)(int)puVar2[3] / 10.0f) * (544.0f - fVar6);

    quad[0] = fVar6 + 320.0f + quad[7];

    quad[1] = fVar6 + -320.0f + quad[7];

    quad[2] = fVar6 + -224.0f + quad[7];

    quad[3] = fVar6 + 224.0f + quad[7];

    quad[4] = quad[7] + -96.0f;

    quad[5] = quad[7] + 352.0f;

    quad[6] = quad[7] + 448.0f;

    quad[7] = quad[7] + -192.0f;

  }

  else if (puVar2[1] == 0) {

    quad[0] = 320.0f;

    quad[1] = -320.0f;

    quad[2] = -224.0f;

    quad[3] = 224.0f;

    quad[4] = -96.0f;

    quad[5] = 352.0f;

    quad[6] = 448.0f;

    quad[7] = -192.0f;

  }

  FUN_0021d890(puVar2 + 0x84,&quad[0]);

  uVar7 = FUN_0021ea00(0x23);

  FUN_0021eac0(puVar2 + 0x84,(float)uVar7);

  color[0] = 0x4f;

  color[1] = 0xa4;

  color[2] = 0xff;

  color[3] = 0xff;

  FUN_0021d950(puVar2 + 0x84,&color[0]);

  quad[0] = 0.0f;

  quad[1] = 0.0f;

  quad[2] = 640.0f;

  quad[3] = 448.0f;

  FUN_0021d8e0(puVar2 + 0x1c4,&quad[0]);

  color[0] = 0xff;

  color[1] = 0xff;

  color[2] = 0xff;

  color[3] = 0xff;

  FUN_0021d950(puVar2 + 0x1c4,&color[0]);

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
    volatile code *state;
    volatile code *quad;
    char *iVar1;
    u32 uVar2;

    if (sBrItem == (u32*)0) {
        FUN_0019d3f0(0x68ebf8, 0x75);
    }
    iVar1 = (char*)sBrItem;
    state = DAT_00960090_abs;
    quad = DAT_0096009c_abs;
    (*state)(9, 2);
    (*state)(0x14, 2);
    (*state)(8, 1);
    (*state)(6, 0);
    FUN_004d7f60(3, 0x717fb);
    FUN_004d7f60(2, 0x44);
    (*state)(1, 0);
    quad = DAT_0096009c_abs;
    (*quad)(iVar1 + 0x310, 4, 0, 1, 2);
    (*quad)(iVar1 + 0x310, 4, 0, 2, 3);
    (*state)(0x14, 2);
    (*state)(8, 1);
    (*state)(6, 0);
    FUN_004d7f60(3, 0x717fb);
    FUN_004d7f60(2, 0x44);
    (*state)(1, 0);
    quad = DAT_0096009c_abs;
    (*quad)(iVar1 + 0x10, 4, 0, 1, 2);
    (*quad)(iVar1 + 0x10, 4, 0, 2, 3);
    (*state)(8, 0);
    (*state)(6, 1);
    uVar2 = FUN_00260940(*(u32*)(iVar1 + 8), 0x3a);
    (*state)(1, uVar2);
    quad = DAT_0096009c_abs;
    (*quad)(iVar1 + 0x710, 4, 0, 1, 2);
    (*quad)(iVar1 + 0x710, 4, 0, 2, 3);
    (*state)(1, 0);
    quad = DAT_0096009c_abs;
    (*quad)(iVar1 + 0x810, 4, 0, 1, 2);
    (*state)(8, 1);
    (*state)(6, 1);
    FUN_004d7f60(3, 0x717fb);
    FUN_004d7f60(2, 0x44);
    (*state)(6, 1);
    (*state)(6, 1);
    (*state)(8, 1);
    (*state)(1, 0);
    quad = DAT_0096009c_abs;
    (*quad)(iVar1 + 0x210, 4, 0, 1, 2);
    (*quad)(iVar1 + 0x210, 4, 0, 2, 3);
    if (*(int*)(iVar1 + 4) == 1) {
        (*state)(6, 0);
        (*state)(8, 0);
        (*state)(1, 0);
        quad = state;
        (*quad)(iVar1 + 0x110, 4, 0, 1, 2);
        (*quad)(iVar1 + 0x110, 4, 0, 2, 3);
    }
    else if (*(int*)(iVar1 + 4) == 0) {
        (*state)(6, 0);
        (*state)(8, 1);
        (*state)(1, 0);
        quad = state;
        (*quad)(iVar1 + 0x110, 4, 0, 1, 2);
        (*quad)(iVar1 + 0x110, 4, 0, 2, 3);
    }
    state = DAT_00960090_abs;
    (*state)(6, 1);
    (*state)(6, 1);
    (*state)(8, 0);
    uVar2 = FUN_00260940(*(u32*)(iVar1 + 8), 0x34);
    (*state)(1, uVar2);
    quad = DAT_0096009c_abs;
    (*quad)(iVar1 + 0x410, 4, 0, 1, 2);
    (*quad)(iVar1 + 0x410, 4, 0, 2, 3);
    uVar2 = FUN_00260940(*(u32*)(iVar1 + 8), 0x35);
    (*state)(1, uVar2);
    quad = DAT_0096009c_abs;
    (*quad)(iVar1 + 0x510, 4, 0, 1, 2);
    (*quad)(iVar1 + 0x510, 4, 0, 2, 3);
    uVar2 = FUN_00260940(*(u32*)(iVar1 + 8), 0x36);
    (*state)(1, uVar2);
    quad = DAT_0096009c_abs;
    (*quad)(iVar1 + 0x610, 4, 0, 1, 2);
    (*quad)(iVar1 + 0x610, 4, 0, 2, 3);
}





































// FUN_0025F5D0
void FUN_0025f5d0(int param_1, int param_2, int param_3)
{
    int iVar1;
    int iVar3;
    u32 uVar2;
    u8 *puVar4;
    float uv[4];
    u8 abStack_20[0x10];
    float fVar5;
    u32 depthAddress;

    iVar1 = *(int *)((int)param_2 + 0x184) + param_3 * 0x80;
    iVar3 = FUN_00198590();
    fVar5 = 1.0f / *(float *)(iVar3 + 0x80);
    FUN_0025fb60(param_2, param_3, uv);
    for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
        uVar2 = *(u32 *)(iVar1 + iVar3 * 4 + 100);
        puVar4 = abStack_20 + iVar3 * 4;
        puVar4[0] = (u8)((uVar2 >> 0x18) * 0xff >> 7);
        puVar4[1] = (u8)(((uVar2 >> 0x10) & 0xff) * 0xff >> 7);
        puVar4[2] = (u8)(((uVar2 >> 8) & 0xff) * 0xff >> 7);
        puVar4[3] = (u8)((uVar2 & 0xff) * 0xff >> 7);
    }
    *(float *)(param_1 + 0x10) = uv[0];
    *(float *)(param_1 + 0x14) = uv[1];
    *(float *)(param_1 + 0x18) = fVar5;
    depthAddress = (u32)DAT_00960088_abs;
    *(float *)(param_1 + 8) = *(volatile f32*)depthAddress;
    *(float *)(param_1 + 0x20) = (float)abStack_20[0];
    *(float *)(param_1 + 0x24) = (float)abStack_20[1];
    *(float *)(param_1 + 0x28) = (float)abStack_20[2];
    *(float *)(param_1 + 0x2c) = (float)abStack_20[3];
    *(float *)(param_1 + 0x50) = uv[2];
    *(float *)(param_1 + 0x54) = uv[1];
    *(float *)(param_1 + 0x58) = fVar5;
    *(float *)(param_1 + 0x48) = *(volatile f32*)depthAddress;
    *(float *)(param_1 + 0x60) = (float)abStack_20[4];
    *(float *)(param_1 + 0x64) = (float)abStack_20[5];
    *(float *)(param_1 + 0x68) = (float)abStack_20[6];
    *(float *)(param_1 + 0x6c) = (float)abStack_20[7];
    *(float *)(param_1 + 0x90) = uv[2];
    *(float *)(param_1 + 0x94) = uv[3];
    *(float *)(param_1 + 0x98) = fVar5;
    *(float *)(param_1 + 0x88) = *(volatile f32*)depthAddress;
    *(float *)(param_1 + 0xa0) = (float)abStack_20[8];
    *(float *)(param_1 + 0xa4) = (float)abStack_20[9];
    *(float *)(param_1 + 0xa8) = (float)abStack_20[10];
    *(float *)(param_1 + 0xac) = (float)abStack_20[11];
    *(float *)(param_1 + 0xd0) = uv[0];
    *(float *)(param_1 + 0xd4) = uv[3];
    *(float *)(param_1 + 0xd8) = fVar5;
    *(float *)(param_1 + 200) = *(volatile f32*)depthAddress;
    *(float *)(param_1 + 0xe0) = (float)abStack_20[12];
    *(float *)(param_1 + 0xe4) = (float)abStack_20[13];
    *(float *)(param_1 + 0xe8) = (float)abStack_20[14];
    *(float *)(param_1 + 0xec) = (float)abStack_20[15];
}
