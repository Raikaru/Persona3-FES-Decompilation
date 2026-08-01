#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"

#include "Main/Battle/Data/datPersona.h"
#include "Main/Social/sfl_psel.h"
#include "Main/Social/sfl_res.h"
u32 brItem0025f4a0(void);
void brItem0025f510(int param_1);
static u32* sSflPsel; // puGpffffb688
u32 FUN_0021cca0();
void FUN_0021d3b0();
void FUN_00260c20();
void FUN_00261480();
extern void FUN_0021d8e0_y2(void*, const void*);
extern void FUN_0021d950_y2(void*, const void*);
extern void (*D_00960090)(u32, u32);
extern void (*D_0096009C)(u32*, u32, u32, u32, u32);
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
#pragma alias D_0096009C_abs D_0096009C
extern u8 D_0096009C_abs[];
extern void RpSkyRenderStateSet(u32, void*);
extern void func_004d7f60(s32 state, u32 value);
extern float fGpffff8300;
extern char D_00960088[];
extern u32 uGpffffb948;
extern u16 DAT_007e0952;
#pragma alias DAT_007e0952_a DAT_007e0952
extern u16 DAT_007e0952_a[8];
extern u32 func_00173220(u16 id);
extern u32 func_00173280(u16 id);
extern u8* DAT_007ce420;
extern u32 func_00175410(void);
extern u32 func_001756f0(void);
extern void* func_001749a0(u16 id);
extern DatPersonaWork* datPersonaGetHeroPersona(s16 index);
extern DatPersonaWork* datPersonaGetByPcId(u16 pcId);
extern u32 func_0010a4e0(s32 bank, s32 cue, s32 variant, s32 pan);
extern u32 func_0021cca0(u32 texture, s32 frame);
extern u32 func_0021cce0(u32 frame);
extern void func_0021d3b0(void* destination, u32 frame);
extern void func_0021d8e0(void* destination, const f32* rect);
extern void func_0021d950(void* destination, const u8* color);
extern void func_0021e380(void* destination, u32 frame, s32 mode);
extern f32 func_0021ea00(s32 duration);
extern void func_0021eac0(void* animation, f32 value);
extern void func_00238980(void* destination, s32 count, u32 value, s32 mode);
extern void* func_00238dc0(void* destination, s32 count, u32 value, s32 mode, const f32* origin);
extern u32 func_00239140(s32 font);
extern void func_0024a260(u32* state);
extern u32 func_003b0970(u32 resource, s32 mode, s8 group, s32 a, s32 b);
extern void func_003b0d70(u32 resource, s32 x, s32 y);
extern void func_003b0e20(u32 resource, u32 color);
extern void func_003b0e70(s32 mode);
extern void func_003b0e90(s32 mode);
extern void func_003b1360(u32 resource, s32 mode, s32 value);
extern void func_003b0170(u32 resource);
extern void frFontSetTextScale(u32 resource, f32 value);
extern u32 func_003c7610(void);
extern void func_003c7650(s32 mode);
extern u32 func_003c7850(void);
extern u32 func_003c78d0(void);
extern void func_003c7990(s32 mode);
extern void func_003c7bc0(s32 mode, u32 value);
extern void func_003c7430(u32 value);
extern void sflPersonaLoad(u16 id);
extern void sflPersonaSetPersona(u16 id);
extern void sflPersonaDestroy(void);
extern u32 sflPersonaIsLoading(void);
extern void sflPersonaStartExitTransition(void);
extern u32 sflPersonaIsTransitioning(void);
extern void func_00523ac8(char* destination, const char* format, ...);
extern s32 func_00524388(const char* text);
extern void func_0019d3f0(const char* file, s32 line);
extern char D_0068e228[];
extern void func_003c74e0(u32 value);
typedef void (*SflPselStateCallback)(u32 state, u32 value);
typedef void (*SflPselDrawCallback)(void* quad, u32 layer, u32 group, u32 pass, u32 blend);
extern u32 FUN_0021cce0(u32 frame);
extern void FUN_0021d890_y2(void*, const void*);


#pragma alias FUN_0021d8e0_y2 FUN_0021d8e0_y2
#pragma alias FUN_0021d950_y2 FUN_0021d950_y2
#pragma alias FUN_0021d890_y2 FUN_0021d890_y2



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

#pragma opt_propagation off
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

  float unaff_f22;

  float in_f21;

  float fVar9;

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

  switch (puVar2[1]) { case 0: in_f21 = 1.0f;
  
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
  
  } break; case 1: if ((int)puVar2[3] < 3) {
  
    in_f21 = (float)(int)puVar2[3] / 3.0f;
  
    quad[0] = in_f21 * 150.0f + 6.0f;
  
    in_f21 = 1.0f - in_f21;
  
    quad[1] = quad[0];
  
  }
  
  else {
  
    quad[0] = 156.0f;
  
    quad[1] = 156.0f;
  
    in_f21 = 0.0f;
  
  } break; }

  quad[2] = (float)iVar3;

  quad[3] = (float)iVar4;

  FUN_0021d8e0(puVar2 + 0x104,&quad[0]);

  color[0] = 0xff;

  color[1] = 0xff;

  color[2] = 0xff;

  fVar6 = in_f21 * 255.0f;

  if (fVar6 <= 2.1474836e+09f) { color[3] = (u8)(int)fVar6; } else { color[3] = (u8)(int)(fVar6 - 2.1474836e+09f); }

  FUN_0021d950(puVar2 + 0x104,&color[0]);

  iVar3 = FUN_00260900(puVar2[2],0x35);

  iVar4 = FUN_00260920(puVar2[2],0x35);

  switch (puVar2[1]) { case 0: in_f21 = 1.0f;
  
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
  
  } break; case 1: if ((int)puVar2[3] < 3) {
  
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
  
  } break; }

  quad[2] = (float)iVar3;

  quad[3] = (float)iVar4;

  FUN_0021d8e0(puVar2 + 0x144,&quad[0]);

  color[0] = 0xff;

  color[1] = 0xff;

  color[2] = 0xff;

  fVar6 = in_f21 * 255.0f;

  if (fVar6 <= 2.1474836e+09f) { color[3] = (u8)(int)fVar6; } else { color[3] = (u8)(int)(fVar6 - 2.1474836e+09f); }

  FUN_0021d950(puVar2 + 0x144,&color[0]);

  iVar3 = FUN_00260900(puVar2[2],0x36);

  iVar4 = FUN_00260920(puVar2[2],0x36);

  switch (puVar2[1]) { case 0: in_f21 = 1.0f;
  
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
  
  } break; case 1: if ((int)puVar2[3] < 3) {
  
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
  
  } break; }

  quad[2] = (float)iVar3;

  quad[3] = (float)iVar4;

  FUN_0021d8e0(puVar2 + 0x184,&quad[0]);

  color[0] = 0xff;

  color[1] = 0xff;

  color[2] = 0xff;

  fVar6 = in_f21 * 255.0f;

  if (fVar6 <= 2.1474836e+09f) { color[3] = (u8)(int)fVar6; } else { color[3] = (u8)(int)(fVar6 - 2.1474836e+09f); }

  FUN_0021d950(puVar2 + 0x184,&color[0]);

  switch (puVar2[1]) { case 0: if ((int)puVar2[3] < 8) {
  
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
  
  } break; case 1: if ((int)puVar2[3] < 10) {
  
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
  
  } break; }

  FUN_0021d890(puVar2 + 4,&quad[0]);

  uVar7 = FUN_0021ea00(0x32);

  FUN_0021eac0(puVar2 + 4,(float)uVar7);

  color[0] = 0;

  color[1] = 0;

  color[2] = 0;

  color[3] = 0;

  FUN_0021d950(puVar2 + 4,&color[0]);

  switch (puVar2[1]) { case 0: quad[0] = 320.0f;
  
  quad[1] = -320.0f;
  
  quad[2] = -224.00002f;
  
  quad[3] = 224.0f;
  
  quad[4] = -116.000015f;
  
  quad[5] = 332.0f;
  
  quad[6] = 428.0f;
  
  quad[7] = -212.0f;
  
  in_f21 = 1.0f; break; case 1: if ((int)puVar2[3] < 10) {
  
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
  
  } break; }

  FUN_0021d890(puVar2 + 0x44,&quad[0]);

  uVar7 = FUN_0021ea00(0x23);

  FUN_0021eac0(puVar2 + 0x44,(float)uVar7);

  color[0] = 4;

  color[1] = 0x29;

  color[2] = 0x46;

  in_f21 = in_f21 * 255.0f;

  if (in_f21 <= 2.1474836e+09f) { color[3] = (u8)(int)in_f21; } else { color[3] = (u8)(int)(in_f21 - 2.1474836e+09f); }

  FUN_0021d950(puVar2 + 0x44,&color[0]);

  switch (puVar2[1]) { case 0: quad[0] = 320.0f;
  
  quad[1] = -320.0f;
  
  quad[2] = -224.0f;
  
  quad[3] = 224.0f;
  
  quad[4] = -96.0f;
  
  quad[5] = 352.0f;
  
  quad[6] = 448.0f;
  
  quad[7] = -192.0f; break; case 1: fVar6 = (181.01933f - DAT_007caff0) / 1.4142135f;
  
  quad[7] = ((float)(int)puVar2[3] / 10.0f) * (544.0f - fVar6);
  
  quad[0] = fVar6 + 320.0f + quad[7];
  
  quad[1] = fVar6 + -320.0f + quad[7];
  
  quad[2] = fVar6 + -224.0f + quad[7];
  
  quad[3] = fVar6 + 224.0f + quad[7];
  
  quad[4] = quad[7] + -96.0f;
  
  quad[5] = quad[7] + 352.0f;
  
  quad[6] = quad[7] + 448.0f;
  
  quad[7] = quad[7] + -192.0f; break; }

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

  *(float *)(puVar2 + 0x204) = 0x205;
  puVar2[0x205] = 0x43e00000;
  puVar2[0x214] = 0x44200000;
  *(float *)(puVar2 + 0x215) = 0x145;
  puVar2[0x224] = 0x44200000;
  puVar2[0x225] = 0x43e00000;
  color[0] = 0x4f;
  color[1] = 0xa4;
  color[2] = 0xff;
  color[3] = 0xff;
  *(float *)(puVar2 + 0x20c) = (float)color[0];
  *(float *)(puVar2 + 0x20d) = (float)color[1];
  *(float *)(puVar2 + 0x20e) = (float)color[2];
  *(float *)(puVar2 + 0x20f) = (float)color[3];
  *(float *)(puVar2 + 0x21c) = (float)color[0];
  *(float *)(puVar2 + 0x21d) = (float)color[1];
  *(float *)(puVar2 + 0x21e) = (float)color[2];
  *(float *)(puVar2 + 0x21f) = (float)color[3];
  *(float *)(puVar2 + 0x22c) = (float)color[0];
  *(float *)(puVar2 + 0x22d) = (float)color[1];
  *(float *)(puVar2 + 0x22e) = (float)color[2];
  *(float *)(puVar2 + 0x22f) = (float)color[3];

  return;

}
#pragma opt_propagation reset

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

/* Recovered battle-misc harvest: 0x0025F370-0x0025FC50 */
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




























/* Retail converts the final color bytes into float vertex fields.
 * Keep these stores typed; raw u32 bit patterns drop those conversion paths.
 * The two geometry coordinates at the tail are integer-to-float conversions.
 * Ascending case labels preserve retail's case-0 body layout and dispatch order.
 * The expanded switch/tail reconstruction is intentional despite residual codegen differences.
*/
/* W331: opt_propagation off shrinks FUN_0025DA30 4912 -> 4856 (window 4880); retained for window. */
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






static inline u8* sflPselBytes(u32* work, u32 offset)
{
    return (u8*)work + offset;
}

static u32 sflPselReadU32(const void* object, u32 offset)
{
    return *(const u32*)((const u8*)object + offset);
}

static inline s32 sflPselReadS32(const void* object, u32 offset)
{
    return *(const s32*)((const u8*)object + offset);
}

static u8* sflPselEntry(u32* work, s32 index)
{
    u8* entries;

    entries = (u8*)(uintptr_t)sflPselReadU32(work, 0x184);
    return entries + index * 0x80;
}

static inline void sflPselSetAlpha(void* object, u8 alpha)
{
    u8 color[4];

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = alpha;
    FUN_0021d950_y2(object, color);
}

static void sflPselDraw(void* object)
{
    D_0096009C((u32*)object, 4, 0, 1, 2);
    D_0096009C((u32*)object, 4, 0, 2, 3);
}

// FUN_00260430
void sflPsel00260430(u32* base, s32 index, float* uv, u32 axis)
{
    u8* entry;
    u8* resource;
    u32 xMode;
    s32 width;
    s32 height;

    entry = (u8*)(uintptr_t)(base[0x61] + (index << 7));
    resource = (u8*)(uintptr_t)base[0x41 + *(u32*)(entry + 0x14)];
    {
        f32 x[2] = {0.0f, 0.0f};
        x[0] = (f32)*(s32*)(entry + 0x54);
        x[1] = (f32)*(s32*)(entry + 0x5c);
        {
            f32 y[2] = {0.0f, 0.0f};
            y[0] = (f32)*(s32*)(entry + 0x58);
            y[1] = (f32)*(s32*)(entry + 0x60);
            width = *(s32*)(resource + 0xc);
            height = *(s32*)(resource + 0x10);

            switch (axis) {
            case 0: xMode = 0; axis = 1; break;
            case 1: xMode = 2; axis = 0; break;
            case 2: xMode = 0; axis = 2; break;
            case 3: xMode = 1; axis = 0; break;
            case 4: xMode = 2; axis = 1; break;
            case 5: xMode = 2; axis = 2; break;
            case 6: xMode = 2; axis = 1; break;
            case 7: xMode = 1; axis = 1; break;
            }

            switch (xMode) {
            case 0:
                if (((~*(u32*)(entry + 0x18)) & 1) != 0) {
                    uv[0] = x[0] / (f32)width;
                    uv[2] = x[1] / (f32)width;
                } else {
                    uv[0] = x[1] / (f32)width;
                    uv[2] = x[0] / (f32)width;
                }
                break;
            case 1:
                if (((~*(u32*)(entry + 0x18)) & 1) != 0) {
                    uv[0] = x[0] / (f32)width;
                    uv[2] = (x[0] + 1.0f) / (f32)width;
                } else {
                    uv[0] = x[1] / (f32)width;
                    uv[2] = (x[1] - 1.0f) / (f32)width;
                }
                break;
            case 2:
                if (((~*(u32*)(entry + 0x18)) & 1) != 0) {
                    uv[0] = (x[1] - 1.0f) / (f32)width;
                    uv[2] = x[1] / (f32)width;
                } else {
                    uv[0] = (x[0] + 1.0f) / (f32)width;
                    uv[2] = x[0] / (f32)width;
                }
                break;
            }

            switch (axis) {
            case 0:
                if (((~*(u32*)(entry + 0x18)) & 2) != 0) {
                    uv[1] = y[0] / (f32)height;
                    uv[3] = y[1] / (f32)height;
                } else {
                    uv[1] = y[1] / (f32)height;
                    uv[3] = y[0] / (f32)height;
                }
                break;
            case 1:
                if (((~*(u32*)(entry + 0x18)) & 2) != 0) {
                    uv[1] = y[0] / (f32)height;
                    uv[3] = (y[0] + 1.0f) / (f32)height;
                } else {
                    uv[1] = y[1] / (f32)height;
                    uv[3] = (y[1] - 1.0f) / (f32)height;
                }
                break;
            case 2:
                if (((~*(u32*)(entry + 0x18)) & 2) != 0) {
                    uv[1] = (y[1] - 1.0f) / (f32)height;
                    uv[3] = y[1] / (f32)height;
                } else {
                    uv[1] = (y[0] + 1.0f) / (f32)height;
                    uv[3] = y[0] / (f32)height;
                }
                break;
            }
        }
    }
}

// FUN_00260900
s32 sflPsel00260900(u32* base, s32 index)
{
    u8* entry;

    entry = (u8*)(uintptr_t)(base[0x61] + (index << 7));
    return *(s32*)(entry + 0x5c) - *(s32*)(entry + 0x54);
}

// FUN_00260920
s32 sflPsel00260920(u32* base, s32 index)
{
    u8* entry;

    entry = (u8*)(uintptr_t)(base[0x61] + (index << 7));
    return *(s32*)(entry + 0x60) - *(s32*)(entry + 0x58);
}

// FUN_00260940
u32 sflPsel00260940(u32* base, s32 index)
{
    u8* entry;

    entry = (u8*)(uintptr_t)(base[0x61] + (index << 7));
    return base[0x41 + *(u32*)(entry + 0x14)];
}

// FUN_00260970
void sflPsel00260970(u8* work)
{
    float frame[4];
    u8 color[4];

    *(u32*)work = 0;
    frame[0] = 0.0f;
    frame[1] = 0.0f;
    frame[2] = 640.0f;
    frame[3] = 448.0f;
    FUN_0021d8e0_y2(work + 0x310, frame);
    FUN_0021eac0(work + 0x310, FUN_0021ea00(10));
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = 0;
    FUN_0021d950_y2(work + 0x310, color);
    sSflPsel = (u32*)work;
}












/* opt_lifetimes on: func_00215b00 nd765 -> nd748, object 1216 -> 1212/1216; measured W328. */



/* opt_lifetimes on: func_002168f0 nd777 -> nd716, object 1992 -> 1992/2000; measured W328. */
