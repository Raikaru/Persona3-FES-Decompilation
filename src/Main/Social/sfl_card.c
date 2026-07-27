#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
typedef struct { f32 x; f32 y; f32 z; } SflCardVec;
typedef struct {
    f32 transformed[4];
    u8 pad0[8];
    f32 origin[3];
    u8 pad1[4];
    f32 rotation[3];
    u8 pad2[4];
    f32 rect[4];
    f32 frame_offset;
    f32 frame_const;
    f32 scale[3];
} SflCardDrawFrame;
void FUN_00253600(u32 *param_1);
void FUN_00250cf0();
void FUN_00253a40(void);
void FUN_00258140(void);
void FUN_00258300(void);
void FUN_00258540(u32 param_1,u64 param_2);
void FUN_00258630(u32 *param_1);
void FUN_00258b40(void);
void FUN_00258f80(u32 *param_1);
void FUN_002593d0(void);
void FUN_002594c0(void);
extern u64 DAT_0068ea10;
extern f32 DAT_0068ea18;
extern SflCardVec DAT_0068eaa0;
extern u64 DAT_0068eab0;
extern f32 DAT_0068eab8;
extern SflCardVec DAT_0068eac0;
extern u32 DAT_007e094c;
extern u32 DAT_007e0952;
extern u32 DAT_007e0956;
extern u32 DAT_007e095a;
extern int iGpffffb664;
extern u32 uGpffff8248;
extern f32 fGpffff8248;
extern f32 fGpffff83c0;

static u32* sSflCardB664; // puGpffffb664
static u32* sSflCard354;  // DAT_007ce354
#pragma alias DAT_0068eab0_abs DAT_0068eab0
#pragma alias DAT_0068eab8_abs DAT_0068eab8
extern u8 DAT_0068eab0_abs[];
extern u8 DAT_0068eab8_abs[];
 #pragma alias DAT_0068ea10_abs DAT_0068ea10
 #pragma alias DAT_0068ea18_abs DAT_0068ea18
 extern u8 DAT_0068ea10_abs[];
#pragma alias DAT_007e094c_abs DAT_007e094c
#pragma alias DAT_007e0952_abs DAT_007e0952
#pragma alias DAT_007e0956_abs DAT_007e0956
#pragma alias DAT_007e095a_abs DAT_007e095a
extern u8 DAT_007e094c_abs[];
extern u8 DAT_007e0952_abs[];
extern u8 DAT_007e0956_abs[];
extern u8 DAT_007e095a_abs[];
 extern u8 DAT_0068ea18_abs[];
extern u32* FUN_00255440();
extern void FUN_00256f20();
extern void FUN_00257d00();
extern void FUN_00250a30();
extern void FUN_002508c0();
extern void FUN_0010a4e0();
extern void FUN_0025b300();
extern void FUN_0025b3b0();
extern void FUN_0024f2c0();
extern void FUN_00250ef0();
extern void FUN_00251030();
extern void FUN_0024dc90();
extern void FUN_0024f9f0();
extern u32 FUN_0021a120(void);
extern u32 FUN_00250b90(void*);
extern u32 FUN_00250e70(u32);
extern void FUN_00209f00(void*);
extern void FUN_0020a800(void*);
extern void FUN_0020ab30(void*);
extern f32 FUN_0020c500(void*, f32);
extern void FUN_0020c400(void*, const f32*, f32, f32*);
extern void FUN_0020c590(void*, u16);
extern void FUN_0020c5f0(void*, u32, u32);
extern f32 FUN_0020c660(u32, u32);
extern void FUN_0020cd50(void*, void*);
extern void FUN_0020d630(void*, const f32*);
extern void FUN_0020d650(void*, const f32*);
extern void FUN_0020d6c0(void*);
extern void FUN_0020d710(void*);
extern void* FUN_0020e710(u32);
extern void FUN_0024da60(void*);
extern void FUN_0024f090(void*);
extern void FUN_0024f210(void*, f32, u32, f32);
extern void FUN_0024f9f0(void*, const f32*);
extern void FUN_0024fc40(void*, const f32*);
extern void FUN_0024fd20(void*);
extern void FUN_0024fd40(void*);
extern void FUN_0024fd80(void*);
extern void FUN_0024fdc0(void*);
extern void FUN_0024fe00(void*);
extern void FUN_0024fe20(void*);
extern void FUN_002503f0(void*, u32, void*);
extern void FUN_00250be0(void*, u32, void*);
extern u32 FUN_0034fcd0(void*);
extern void FUN_004bdde0(f32, f32*, const f32*, u32);
extern u32 FUN_00488f30(void);

// FUN_00255170
void sflCard00255170(u32* param_1)
{
    *param_1 |= 1;
}

// FUN_00255190
void sflCard00255190(u32* param_1)
{
    param_1[0x496] = 0;
    *param_1 |= 0x80;
}

// FUN_002561c0
u32 sflCard002561c0(u32* param_1)
{
    return *param_1 & 1;
}

// FUN_002561d0
u32 sflCard002561d0(u32* param_1)
{
    return *param_1 & 0x80;
}

// FUN_00259250
void sflCard00259250(void)
{
    u32* work;

    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    work = sSflCardB664;
    work[0x4a1f] = 0;
    *work |= 0x40;
    work[0x4a1c] = 3;
    *work |= 0x100;
}

// FUN_002592c0
u32 sflCard002592c0(void)
{
    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    return *sSflCardB664 & 0x100;
}

// FUN_00259310
void sflCard00259310(void)
{
    u32* work;

    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    work = sSflCardB664;
    work[0x4a1f] = 0;
    *work |= 0x40;
    work[0x4a1c] = 4;
    *work |= 0x800;
}

// FUN_00259380
u32 sflCard00259380(void)
{
    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    return *sSflCardB664 & 0x800;
}

// FUN_00258490
void sflCard00258490(void)
{
    K_ASSERT(sSflCard354 != NULL, 0xbc);
    *sSflCard354 |= 8;
}

// FUN_002584e0
void sflCard002584e0(u32 param_1)
{
    K_ASSERT(sSflCard354 != NULL, 0xbc);
    sSflCard354[0x49ec] = param_1;
}

u32* FUN_00255390();

// FUN_002580e0
void sflCard002580e0(void)
{
    K_ASSERT(sSflCard354 != NULL, 0xbc);
    *sSflCard354 &= 0xffffdfff;
    FUN_00258140();
}

// FUN_002582b0
u32 sflCard002582b0(void)
{
    K_ASSERT(sSflCard354 != NULL, 0xbc);
    return *sSflCard354 & 0x40;
}

// FUN_00253560
void sflCard00253560(void)
{
    int base;
    int i;
    int p;

    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    base = (int)sSflCardB664;
    for (i = 0; i < 0x10; i++) {
        p = base + i * 0x1264;
        if ((~*(u32*)(p + 4) & 4) == 0) {
            FUN_00253600((u32*)(p + 4));
        }
    }
    sSflCardB664 = NULL;
}

// FUN_00253920
void sflCard00253920(void)
{
    u32* a;
    u32* b;
    u32* node;

    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    a = sSflCardB664;
    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    b = sSflCardB664;
    node = FUN_00255390();
    if (b[0x4997] == 0) {
        node[0x3f1] = 0;
        node[0x3f0] = 0;
        b[0x4997] = (u32)node;
        b[0x4998] = (u32)node;
    } else {
        node[0x3f1] = 0;
        node[0x3f0] = b[0x4998];
        ((u32*)b[0x4998])[0x3f1] = (u32)node;
        b[0x4998] = (u32)node;
    }
    *node |= 4;
    node[1] = 2;
    node[4] = a[0x499f];
    a[0x499f]++;
}

// FUN_002536b0
void sflCard002536b0(u32 param_1, u32 param_2)
{
    u32* a;
    u32* b;
    u32* node;

    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    a = sSflCardB664;
    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    b = sSflCardB664;
    node = FUN_00255390();
    if (b[0x4997] == 0) {
        node[0x3f1] = 0;
        node[0x3f0] = 0;
        b[0x4997] = (u32)node;
        b[0x4998] = (u32)node;
    } else {
        node[0x3f1] = 0;
        node[0x3f0] = b[0x4998];
        ((u32*)b[0x4998])[0x3f1] = (u32)node;
        b[0x4998] = (u32)node;
    }
    *node |= 4;
    node[1] = 1;
    node[2] = param_1;
    node[3] = param_2;
    node[4] = a[0x499f];
    a[0x499f]++;
}

// FUN_002537f0
void sflCard002537f0(u16 param_1)
{
    u32* a;
    u32* b;
    u32* node;

    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    a = sSflCardB664;
    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    b = sSflCardB664;
    node = FUN_00255390();
    if (b[0x4997] == 0) {
        node[0x3f1] = 0;
        node[0x3f0] = 0;
        b[0x4997] = (u32)node;
        b[0x4998] = (u32)node;
    } else {
        node[0x3f1] = 0;
        node[0x3f0] = b[0x4998];
        ((u32*)b[0x4998])[0x3f1] = (u32)node;
        b[0x4998] = (u32)node;
    }
    *node |= 4;
    node[1] = 0;
    *(u16*)(node + 2) = param_1;
    node[4] = a[0x499f];
    a[0x499f]++;
}

void scrClearTextBox();

// FUN_00258090
void sflCard00258090(void)
{
    K_ASSERT(sSflCard354 != NULL, 0xbc);
    *sSflCard354 |= 0x2000;
    FUN_00258140();
}

// FUN_00258a50
void sflCard00258a50(void)
{
    u32* work;
    u32 v;

    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    work = sSflCardB664;
    scrClearTextBox(0, 0, 0, 2);
    work[0x4a1f] = 0;
    work[0x4a1e] = 0;
    work[0x4a1c] = 2;
    *work |= 0x40;
    *work |= 0x80;
}

// FUN_00258af0
u32 sflCard00258af0(void)
{
    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    return *sSflCardB664 & 0x80;
}

// FUN_002595c0
u32 sflCard002595c0(void)
{
    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    return *sSflCardB664 & 0x1000;
}

// FUN_00259190
void sflCard00259190(u32 param_1, int param_2, int* param_3)
{
    u32* p;
    int count;

    K_ASSERT(sSflCardB664 != NULL, 0xbc);
    count = 0;
    for (p = (u32*)sSflCardB664[0x4997]; p != NULL; p = (u32*)p[0x3f1]) {
        if ((~*p & 2) == 0 && p[0x3f2] == param_1) {
            *(u32*)(param_2 + p[4] * 4) = (u32)p;
            count++;
        }
    }
    *param_3 = count;
}

typedef struct {
  u8 auStack_70[16];
  int aiStack_60[8];
  u32 auStack_40[6];
  u64 uStack_28;
  float uStack_20;
  u32 uStack_18;
  u32 uStack_14;
  u8 auStack_10[4];
  float fStack_c;
  u8 auStack_4[4];
} SflCardFrame;

#define auStack_70 frame.auStack_70
#define aiStack_60 frame.aiStack_60
#define auStack_40 frame.auStack_40
#define uStack_28 frame.uStack_28
#define uStack_20 frame.uStack_20
#define uStack_18 frame.uStack_18
#define uStack_14 frame.uStack_14
#define auStack_10 frame.auStack_10
#define fStack_c frame.fStack_c
#define auStack_4 frame.auStack_4
/* Recovered battle-misc harvest: 0x00253A40-0x002594C0 */
// FUN_00253A40 NONMATCHING



void FUN_00253a40(void)



{

  register u32 *puVar1;

  register int iVar2;

  u32 *puVar3;

  u32 lVar4;

  u32* uVar5;

  u32 uVar6;

  u32* unaff_s0;

  u32 uVar7;

  int iVar8;

  f32 uVar9;

  float fVar10;

  SflCardFrame frame;

  


  K_ASSERT(sSflCardB664 != NULL, 0xbc);
  puVar1 = sSflCardB664;

  uStack_28 = *(u64*)DAT_0068ea10_abs;
  uStack_20 = *(f32*)DAT_0068ea18_abs;

  if (((*puVar1 & 0x200) != 0) && (lVar4 = FUN_0021a120(), lVar4 == 0)) {

    *puVar1 = *puVar1 & 0xfffffdff;

  }

  if ((~*puVar1 & 1) == 0) {

    puVar1[0x49a0] = puVar1[0x49a0] + 1;

    if (((((*puVar1 & 0x20) != 0) && ((*(u16*)DAT_007e094c_abs & 0x8000) == 0)) &&

        ((*(u16*)DAT_007e0956_abs & 0x8000) == 0)) &&

       (((*(u16*)DAT_007e094c_abs & 0x2000) == 0 && ((*(u16*)DAT_007e0956_abs & 0x2000) == 0)))) {

      *puVar1 = *puVar1 & 0xffffffdf;

    }

    if (((*puVar1 & 4) != 0) && ((~*puVar1 & 8) != 0) && ((~*puVar1 & 0x20) != 0)) {

      if ((((*(u16*)DAT_007e0952_abs & 0x8000) != 0) || ((*(u16*)DAT_007e095a_abs & 0x8000) != 0))) {

        if ((int)puVar1[0x49eb] > 0) {

          puVar1[0x49eb] = puVar1[0x49eb] - 1;

          FUN_0025b300();

          if (puVar1[0x49eb] == 0) {

            *puVar1 = *puVar1 | 0x20;

          }

        }

        else {

          puVar1[0x49eb] = puVar1[0x499f] - 1;

          FUN_0025b3b0();

        }

        FUN_0010a4e0(0,0,0,0);
      }

      else if (((*(u16*)DAT_007e0952_abs & 0x2000) != 0) || ((*(u16*)DAT_007e095a_abs & 0x2000) != 0)) {

        if ((int)puVar1[0x49eb] < (int)(puVar1[0x499f] - 1)) {

          puVar1[0x49eb] = puVar1[0x49eb] + 1;

          FUN_0025b300();

          if (puVar1[0x49eb] == puVar1[0x499f] - 1) {

            *puVar1 = *puVar1 | 0x20;

          }

        }

        else {

          puVar1[0x49eb] = 0;

          FUN_0025b3b0(0);

        }

        FUN_0010a4e0(0,0,0,0);

      }
    }

    else {

      if ((*puVar1 & 0x10) != 0) {

        if (puVar1[0x49ee] == 1) {

          puVar1[0x49ed] = puVar1[0x49ed] + 1;

          for (iVar2 = 0; iVar2 < (int)puVar1[0x499f]; iVar2 = iVar2 + 1) {

            unaff_s0 = FUN_00255440(iVar2);

            puVar3 = (u32 *)unaff_s0;

            if (((~*puVar3 & 0x40) == 0) && (iVar2 * 3 <= (int)puVar1[0x49ed])) {

              FUN_00256f20(unaff_s0,auStack_40,auStack_4);

              FUN_00257d00(auStack_10,iVar2,auStack_40[0],puVar1[0x499f]);

              FUN_002508c0(puVar3 + 0x425,auStack_10,10);

              uVar6 = *puVar3;

              *puVar3 = uVar6 | 0x20;

              *puVar3 = uVar6 & 0xffffffbf | 0x20;

            }

          }

          for (iVar2 = 0; iVar2 < (int)puVar1[0x499f]; iVar2 = iVar2 + 1) {

            if (puVar1[0x49ed] == iVar2 * 3 + 6U) {

              FUN_0010a4e0(1,0,6,2);

            }

          }

          for (uVar6 = 0; puVar3 = (u32 *)unaff_s0, (int)uVar6 < (int)puVar1[0x499f];

              uVar6 = uVar6 + 1) {

            unaff_s0 = FUN_00255440(uVar6);

            puVar3 = (u32 *)unaff_s0;

            if (((*puVar3 & 0x40) != 0) || ((*puVar3 & 0x20) != 0)) break;

          }

          if (uVar6 == puVar1[0x499f]) {

            *puVar1 = *puVar1 & 0xffffffef;

          }

        }

        else if (puVar1[0x49ee] == 0) {

          puVar1[0x49ed] = puVar1[0x49ed] + 1;

          for (iVar2 = 0; iVar2 < (int)puVar1[0x499f]; iVar2 = iVar2 + 1) {

            unaff_s0 = FUN_00255440(iVar2);

            puVar3 = (u32 *)unaff_s0;

            if (((*puVar3 & 0x40) == 0) &&

               ((int)(puVar1[iVar2 + 0x49ef] * puVar1[0x4a22]) <= (int)puVar1[0x49ed])) {

              FUN_005225a8(0x68ea20,iVar2);

              FUN_00256f20(unaff_s0,auStack_40,auStack_4);

              FUN_00257d00(auStack_10,iVar2,auStack_40[0],puVar1[0x499f]);

              fStack_c = fStack_c + 200.0f;

              FUN_00250a30(puVar3 + 0x425,auStack_10,puVar1[0x4a23]);

              uVar6 = *puVar3;

              *puVar3 = uVar6 | 0x20;

              *puVar3 = uVar6 | 0x60;

              FUN_0010a4e0(1,0,6,2);

            }

          }

          for (uVar6 = 0; (int)uVar6 < (int)puVar1[0x499f]; uVar6 = uVar6 + 1) {

            unaff_s0 = FUN_00255440(uVar6);

            if (((~*(u32 *)unaff_s0 & 0x40) != 0) || ((*(u32 *)unaff_s0 & 0x20) != 0)) break;

          }

          puVar3 = (u32 *)unaff_s0;

          if (uVar6 == puVar1[0x499f]) {

            for (iVar2 = 0; iVar2 < (int)puVar1[0x499f]; iVar2 = iVar2 + 1) {

              iVar8 = (int)(u32)FUN_00255440(iVar2);

              aiStack_60[iVar2] = iVar8;

            }

            for (iVar2 = 0; iVar2 < (int)puVar1[0x499f]; iVar2 = iVar2 + 1) {

              *(u32 *)(aiStack_60[iVar2] + 0x10) = puVar1[iVar2 + 0x49ef];

            }

            for (iVar2 = 0; puVar3 = (u32 *)unaff_s0, iVar2 < (int)puVar1[0x499f];

                iVar2 = iVar2 + 1) {

              unaff_s0 = FUN_00255440(iVar2);

              FUN_00256f20(unaff_s0,auStack_40,auStack_4);

              FUN_00257d00(auStack_10,iVar2,auStack_40[0],puVar1[0x499f]);

              fStack_c = fStack_c + 400.0f;

              FUN_0024f9f0((void *)((u8 *)unaff_s0 + 0x1094),(const f32 *)auStack_10);

            }

            puVar1[0x49ed] = 0;

            puVar1[0x49ee] = 1;

          }

        }
    }

    }
    if ((*puVar1 & 0x40) != 0) {

      switch(puVar1[0x4a1c]) {

      case 1:

        if (puVar1[0x4a1d] == 2) {

          puVar1[0x4a1f] = puVar1[0x4a1f] + 1;

          uVar6 = puVar1[0x4a1f];

          puVar3 = (u32 *)FUN_00255440(puVar1[0x49eb]);

          fVar10 = 1.0f - (float)(int)uVar6 / 10.0f;

          FUN_0024f2c0(fVar10,puVar3 + 0x40c);

          FUN_00250ef0(fVar10,puVar3 + 0x476);

          FUN_00251030(puVar3 + 0x3f3);

          FUN_0024dc90(puVar3 + 0x3f3);

          FUN_00251030(puVar3 + 0x43e);

          FUN_0024dc90(puVar3 + 0x43e);

        }

        break;

      case 2:

        uVar6 = puVar1[0x4a1e];

        if (uVar6 == 2) {

          puVar1[0x4a1f] = puVar1[0x4a1f] + 1;

          puVar1[0x4a20] = (int)(((float)(int)puVar1[0x4a1f] / 6.0f) * 256.0f);

          if (puVar1[0x4a1f] == 6) {

            uVar6 = *puVar1;

            *puVar1 = uVar6 & 0xffffff7f;

            *puVar1 = uVar6 & 0xffffff3f;

          }

        }

        else if (uVar6 == 1) {

          uVar6 = puVar1[0x4a1f];

          puVar1[0x4a1f] = uVar6 + 1;

          if (uVar6 + 1 == 5) {

            puVar1[0x4a1f] = 0;

            puVar1[0x4a1e] = 2;

          }

        }

        else if (uVar6 == 0) {

          puVar1[0x4a1f] = puVar1[0x4a1f] + 1;

          puVar1[0x4a20] = (int)((1.0f - (float)(int)puVar1[0x4a1f] / 6.0f) * 256.0f);

          if (puVar1[0x4a1f] == 6) {

            puVar1[0x4a1f] = 0;

            puVar1[0x4a1e] = 1;

          }

        }

        break;

      case 3:

        puVar1[0x4a1f] = puVar1[0x4a1f] + 1;

        puVar1[0x4a20] = (int)(((float)(int)puVar1[0x4a1f] / 30.0f) * 256.0f);

        if (puVar1[0x4a1f] == 0x1e) {

          uVar6 = *puVar1;

          *puVar1 = uVar6 & 0xffffffbf;

          *puVar1 = uVar6 & 0xfffffebf;

        }

        break;

      case 4:

        puVar1[0x4a1f] = puVar1[0x4a1f] + 1;

        puVar1[0x4a20] = (int)((1.0f - (float)(int)puVar1[0x4a1f] / 16.0f) * 256.0f);

        if (puVar1[0x4a1f] == 0x10) {

          uVar6 = *puVar1;

          *puVar1 = uVar6 & 0xffffffbf;

          *puVar1 = uVar6 & 0xfffff7bf;

        }

        break;

      case 5:

        uVar6 = puVar1[0x4a1f] + 1;

        puVar1[0x4a1f] = uVar6;

        if ((int)uVar6 < 0x1f) {

          for (uVar7 = 0; (int)uVar7 < (int)puVar1[0x499f]; uVar7 = uVar7 + 1) {

            if (uVar7 != puVar1[0x49eb]) {

              iVar2 = (int)(u32)FUN_00255440(uVar7);

              *(int *)(iVar2 + 0x1260) = (int)((1.0f - (float)(int)uVar6 / 30.0f) * 256.0f);

            }

          }

        }

        if (puVar1[0x4a1f] == 0x1e) {

          iVar2 = (int)(u32)FUN_00255440(puVar1[0x49eb]);

          *(u32 *)(iVar2 + 0x1260) = 0;

          puVar1[0x49eb] = puVar1[0x4a21];

          iVar2 = (int)(u32)FUN_00255440();

          *(u32 *)(iVar2 + 0x1260) = 0x100;

          FUN_00257d90(auStack_10,iVar2 + 0x18);

          FUN_0024f9f0((void *)(iVar2 + 0x1094),(const f32 *)auStack_10);

          FUN_0024f2c0(0,iVar2 + 0x1030);

          FUN_00250ef0(0,iVar2 + 0x11d8);

        }

        puVar3 = (u32 *)FUN_00255440(puVar1[0x49eb]);

        FUN_0024fba0(puVar1 + 0x4a00,auStack_70);

        FUN_0024fc40(puVar3 + 0x45a,(const f32 *)auStack_70);

        if (puVar1[0x4a1f] == 0x5a) {

          uVar6 = *puVar1;

          *puVar1 = uVar6 & 0xffffffbf;

          *puVar1 = uVar6 & 0xffffefbf;

        }

        FUN_00251030(puVar3 + 0x3f3);

        FUN_0024dc90(puVar3 + 0x3f3);

        FUN_00251030(puVar3 + 0x43e);

        FUN_0024dc90(puVar3 + 0x43e);

      }

    }

    iVar2 = FUN_002554f0();

    for (iVar8 = 0; iVar8 < iVar2; iVar8 = iVar8 + 1) {

      uVar5 = FUN_00255440(iVar8);

      FUN_002564c0(uVar5);

    }

    if ((*puVar1 & 0x40) != 0) {
    switch (puVar1[0x4a1c]) {

    case 0:

      for (uVar6 = 0; (int)uVar6 < (int)puVar1[0x499f]; uVar6 = uVar6 + 1) {

        iVar2 = (int)(u32)FUN_00255440(uVar6);

        lVar4 = FUN_00250e70(iVar2 + 0x1168);

        if (lVar4 != 0) break;

      }

      if (uVar6 == puVar1[0x499f]) {

        *puVar1 = *puVar1 & 0xffffffbf;

      }

      break;

    case 1:

      uVar6 = puVar1[0x4a1d];

      switch (uVar6) {

      case 0:

        iVar2 = (int)(u32)FUN_00255440(puVar1[0x49eb]);

        lVar4 = FUN_00250e70(iVar2 + 0x1168);

        if (lVar4 == 0) {

          for (uVar6 = 0; (int)uVar6 < (int)puVar1[0x499f]; uVar6 = uVar6 + 1) {

            if (uVar6 != puVar1[0x49eb]) {

              puVar3 = (u32 *)FUN_00255440(uVar6);

              FUN_00250cf0(0,uGpffff8248,puVar3 + 0x45a,&uStack_28,0xc);

              puVar3[0x494] = 0;

              puVar3[0x495] = 0xc;

              puVar3[0x493] = 3;

              *puVar3 = *puVar3 | 0x200;

            }

          }

          puVar1[0x4a1d] = 1;

        }

        break;

      case 1:

        for (uVar6 = 0; (int)uVar6 < (int)puVar1[0x499f]; uVar6 = uVar6 + 1) {

          if (uVar6 != puVar1[0x49eb]) {

            iVar2 = (int)(u32)FUN_00255440(uVar6);

            lVar4 = FUN_00250e70(iVar2 + 0x1168);

            if (lVar4 != 0) break;

          }

        }

        if (uVar6 == puVar1[0x499f]) {

          iVar2 = (int)(u32)FUN_00255440(puVar1[0x49eb]);

          uStack_18 = 0x43a00000;

          uStack_14 = 0x43380000;

          uVar9 = FUN_0020c500((void *)(iVar2 + 0x18),270.0f);
          FUN_0020c400((void *)(iVar2 + 0x18),(const f32 *)&uStack_18,uVar9,(f32 *)auStack_10);

          fStack_c = fStack_c + 100.0f;

          FUN_00250500(iVar2 + 0x1094,auStack_10,10);

          if ((~*puVar1 & 0x2000) != 0) {

            FUN_0010a4e0(1,0,6,0xf);

          }

          puVar1[0x4a1f] = 0;

          puVar1[0x4a1d] = 2;

        }

        break;

      case 2:

        lVar4 = FUN_00250b90(puVar3 + 0x425);

        if (lVar4 == 0) {

          *puVar1 = *puVar1 & 0xffffffbf;

        }

        break;

      }

      break;

    }

    }

    }


  return;

}
#undef auStack_70
#undef aiStack_60
#undef auStack_40
#undef uStack_28
#undef uStack_20
#undef uStack_18
#undef uStack_14
#undef auStack_10
#undef fStack_c
#undef auStack_4

#pragma opt_loop_invariants on
// FUN_00258300


void FUN_00258300(void)
{
  int i;
  u32 uVar1;
  u32 *base;
  u32 *item;
  int stride;
  int j;
  K_ASSERT(sSflCard354 != NULL, 0xbc);
  base = sSflCard354;
  for (i = 0; i < 0x10; i++) {
    item = base + i * 0x499 + 1;
    uVar1 = *item;
    if ((~uVar1 & 4) == 0) {
      if ((uVar1 & 0x100) != 0) {
        if ((uVar1 & 0x80) != 0) {
          FUN_0034fcf0(item[0x492]);
        }
        FUN_0024daf0(item + 0x3f3);
        FUN_0024daf0(item + 0x425);
        FUN_0024daf0(item + 0x40c);
        FUN_0024daf0(item + 0x43e);
        FUN_0024daf0(item + 0x45a);
        FUN_0024daf0(item + 0x476);
      }
      *item &= 0xfffffeff;
    }
  }
  FUN_002593d0();
  base[0x499f] = 0;
  base[0x49a1] = 0;
  base[0x4997] = 0;
  base[0x4998] = 0;
  base[0x49ea] = 0;
  stride = 0x1264;
  for (j = 0; j < 0x10; j++) {
    item = (u32 *)((int)base + j * stride);
    item[1] = 0;
    item[6] = j;
  }
}
#pragma opt_loop_invariants off

// FUN_00258540


void FUN_00258540(u32 param_1,u64 param_2)
{
  u32 *puVar1;
  u32 *work;

  K_ASSERT(sSflCard354 != NULL, 0xbc);
  K_ASSERT(sSflCard354 != NULL, 0xbc);
  puVar1 = (u32 *)sSflCard354[0x4997];
  while (puVar1 != NULL) {
    work = puVar1;
    if ((*puVar1 & 2) == 0 && puVar1[4] == param_1) {
      break;
    }
    puVar1 = (u32 *)puVar1[0x3f1];
  }
  K_ASSERT(puVar1 != NULL, 0x47a);
  FUN_0024f960(work + 0x3f3,param_2);
}

// FUN_00258630 NONMATCHING


#pragma push
#pragma opt_rebuildconditionals off
void FUN_00258630(u32 *param_1)
{
    u32 flags;
    u32 *node;
    s32 count;
    u32* model;
    SflCardDrawFrame local;
#define scale local.scale
#define frame_offset local.frame_offset
#define frame_const local.frame_const
#define rect local.rect
#define rotation local.rotation
#define transformed local.transformed
#define origin local.origin
    f32 frame;

    *(u64 *)origin = *(u64 *)DAT_0068eab0_abs;
    origin[2] = *(f32 *)DAT_0068eab8_abs;
    flags = *param_1;
    *param_1 = flags | 0x100;
    if ((~(flags | 0x100) & 8) != 0) {
        switch (param_1[1]) {
        case 1:
            FUN_0020a800(param_1 + 6);
            FUN_0020c5f0(param_1 + 6, param_1[2], param_1[3]);
            break;
        case 0:
            model = param_1 + 6;
            FUN_00209f00(model);
            FUN_0020c590(model, (u16)param_1[2]);
            if ((*param_1 & 1) != 0) {
                FUN_0020d6c0(param_1 + 6);
            }
            if ((*param_1 & 0x400) != 0) {
                FUN_0020d710(param_1 + 6);
            }
            break;
        case 2:
            FUN_0020ab30(param_1 + 6);
            break;
        default:
            K_ASSERT(0, 0x8de);
            break;
        }

        scale[0] = 10.0f;
        scale[1] = 10.0f;
        scale[2] = 10.0f;
        FUN_0020d630(param_1 + 6, scale);

        K_ASSERT(sSflCard354 != NULL, 0xbc);
        count = 0;
        for (node = *(u32 **)((u8 *)sSflCard354 + 0x1265c);
             node != NULL;
             node = (u32 *)node[0x3f1]) {
            if ((*node & 2) == 0) {
                count++;
            }
        }

        frame_offset = FUN_0020c660(param_1[4], count);
        frame_const = 184.0f;
        frame = FUN_0020c500(param_1 + 6, 90.0f);
        FUN_0020c400(param_1 + 6, &frame_offset, frame, rect);
        rect[1] += 100.0f;
        FUN_0020d650(param_1 + 6, rect);

        rotation[0] = 0.0f;
        rotation[1] = 1.0f;
        rotation[2] = 0.0f;
        FUN_004bdde0(180.0f, (f32 *)(param_1 + 10), rotation, 0);
        FUN_0020cd50(param_1 + 6, param_1 + 0x186);
    }

    FUN_0024fd80(param_1 + 0x425);
    FUN_0024f9f0(param_1 + 0x425, rect);
    FUN_0024da60(param_1 + 0x425);
    FUN_0024f090(param_1 + 0x425);
    FUN_0024fd20(param_1 + 0x40c);
    FUN_0024f210(param_1 + 0x40c, 3.0f, 0x3c, 6.0f);
    FUN_0024da60(param_1 + 0x40c);
    FUN_0024f090(param_1 + 0x40c);
    FUN_0024fd40(param_1 + 0x3f3);
    FUN_002503f0(param_1 + 0x3f3, 0, param_1 + 0x425);
    FUN_002503f0(param_1 + 0x3f3, 1, param_1 + 0x40c);
    FUN_0024da60(param_1 + 0x3f3);
    FUN_0024f090(param_1 + 0x3f3);
    FUN_0024fe00(param_1 + 0x45a);
    FUN_004bdde0(180.0f, transformed, origin, 0);
    FUN_0024fc40(param_1 + 0x45a, transformed);
    FUN_0024da60(param_1 + 0x45a);
    FUN_0024f090(param_1 + 0x45a);
    FUN_0024fe20(param_1 + 0x476);
    FUN_0024da60(param_1 + 0x476);
    FUN_0024f090(param_1 + 0x476);
    FUN_0024fdc0(param_1 + 0x43e);
    FUN_0024da60(param_1 + 0x43e);
    FUN_0024f090(param_1 + 0x43e);
    FUN_00250be0(param_1 + 0x43e, 0, param_1 + 0x45a);
    FUN_00250be0(param_1 + 0x43e, 1, param_1 + 0x476);
    if ((*param_1 & 0x80) != 0) {
        param_1[0x492] = FUN_0034fcd0(FUN_0020e710(0));
        param_1[0x497] = 0x100;
    }
    param_1[0x498] = 0x100;
}
#undef scale
#undef frame_offset
#undef rect
#undef rotation
#undef transformed
#undef origin
#pragma pop

// FUN_00258B40 NONMATCHING


void FUN_00258b40(void)



{

  u32 *puVar1;

  u32 *puVar2;

  u32 uVar3;

  int iSecond;
  int iLast;

  u32 iVar4;
  u32 iVar5;

  int iVar7;

  u32 *unaff_s2_lo;

  u32 *unaff_s3_lo;

  int iFirst;

  f32 uVar8;
  f32 uVar9;

  int aiStack_30 [6];

  int aiStack_50 [8];

  u32 uStack_18;

  u32 uStack_14;

  u8 auStack_10 [4];

  float fStack_c;

  u8 auStack_4 [4];

  

  K_ASSERT(sSflCardB664 != NULL, 0xbc);

  puVar1 = sSflCardB664;

  for (iFirst = 0; iFirst < (int)puVar1[0x49a1]; iFirst = iFirst + 1) {

    FUN_00258f80(*(u32 **)((u8 *)puVar1 + 0x12664 + 4 * (puVar1[0x49a1] - 1U - (u32)iFirst)));
  }


  uVar3 = puVar1[0x499f];
  for (iSecond = 0; iSecond < (int)uVar3; iSecond = iSecond + 1) {

    aiStack_50[iSecond] = iSecond;

  }

  uVar3 = 0x400;
  uVar3 = uVar3 + (FUN_00488f30() & 0xf);
  for (iFirst = 0; iFirst < (int)uVar3; iFirst = iFirst + 1) {

    iVar4 = FUN_00488f30();

    iVar4 = iVar4 % (int)puVar1[0x499f];

    iVar5 = FUN_00488f30();

    iVar5 = iVar5 % (int)(puVar1[0x499f] - 1);

    if ((int)iVar4 <= (int)iVar5) {

      iVar7 = iVar5 + 1;

      iVar5 = iVar4;

      iVar4 = iVar7;

    }

    iVar7 = aiStack_50[iVar5];

    aiStack_50[iVar5] = aiStack_50[iVar4];

    aiStack_50[iVar4] = iVar7;

  }

  for (uVar3 = 0; (int)uVar3 < (int)puVar1[0x499f]; uVar3 = uVar3 + 1) {

    K_ASSERT(sSflCardB664 != NULL, 0xbc);

    for (puVar2 = (u32 *)sSflCardB664[0x4997];

        (puVar2 != (u32 *)0x0 &&

        ((unaff_s3_lo = puVar2, (*puVar2 & 2) != 0 || (puVar2[4] != uVar3))));

        puVar2 = (u32 *)puVar2[0x3f1]) {

    }

    K_ASSERT(puVar2 != NULL, 0x47a);

    aiStack_30[uVar3] = (int)unaff_s3_lo;

  }

  for (iLast = 0; iLast < (int)puVar1[0x499f]; iLast = iLast + 1) {

    *(int *)(aiStack_30[iLast] + 0x10) = aiStack_50[iLast];

  }

  *puVar1 = *puVar1 & 0xffffffef;

  for (uVar3 = 0; (int)uVar3 < (int)puVar1[0x499f]; uVar3 = uVar3 + 1) {

    K_ASSERT(sSflCardB664 != NULL, 0xbc);

    for (puVar2 = (u32 *)sSflCardB664[0x4997];

        (puVar2 != (u32 *)0x0 &&

        ((unaff_s2_lo = puVar2, (*puVar2 & 2) != 0 || (puVar2[4] != uVar3))));

        puVar2 = (u32 *)puVar2[0x3f1]) {

    }

    K_ASSERT(puVar2 != NULL, 0x47a);

    FUN_00256fa0(unaff_s2_lo,aiStack_30,auStack_4);

    uStack_18 = FUN_0020c660(unaff_s2_lo[4],puVar1[0x499f]);

    uStack_14 = 0x43380000;

    uVar8 = FUN_0020c500((void *)(aiStack_30[0] + 0x18),90.0f);
    FUN_0020c400((void *)(aiStack_30[0] + 0x18),(const f32 *)&uStack_18,uVar8,(f32 *)auStack_10);

    fStack_c = fStack_c + 100.0;

    FUN_00250480(unaff_s2_lo + 0x425);

    FUN_0024f9f0(unaff_s2_lo + 0x425,(const f32 *)auStack_10);

    FUN_00250c70(unaff_s2_lo + 0x45a);

    FUN_0024f410(unaff_s2_lo + 0x40c);

    FUN_0024ff10(unaff_s2_lo + 0x476);

    FUN_0024f2c0(0x3f800000,unaff_s2_lo + 0x40c);

    FUN_00250ef0(0x3f800000,unaff_s2_lo + 0x476);

  }

  return;

}

// FUN_00258F80


void FUN_00258f80(u32 *param_1)



{

  u32 *iVar1;

  u32 *puVar2;
  u32 *puVar3;

  int iVar3;

  int aiStack_30 [8];

  u8 auStack_10 [12];

  int iStack_4;

  

  K_ASSERT(iGpffffb664 != 0, 0xbc);

  iVar1 = (u32 *)iGpffffb664;

  FUN_00259190(param_1,aiStack_30,&iStack_4);

  for (puVar2 = (u32 *)iVar1[0x4997]; puVar2 != (u32 *)0x0; puVar2 = (u32 *)puVar2[0x3f1])

  {

    if (((*puVar2 & 2) == 0) && ((int)puVar2[4] > (int)param_1[4])) {

      puVar2[4] = puVar2[4] + (iStack_4 - 1);

    }

  }

  for (iVar3 = 0; iVar3 < iStack_4; iVar3 = iVar3 + 1) {

    puVar2 = (u32 *)aiStack_30[iVar3];

    *puVar2 = *puVar2 & 0xfffffffd;

    puVar2[4] = puVar2[4] + param_1[4];

    FUN_0024f960(param_1 + 0x425,auStack_10);

    FUN_0024f9f0(puVar2 + 0x425,(const f32 *)auStack_10);

  }

  K_ASSERT(iGpffffb664 != 0, 0xbc);
  puVar3 = (u32 *)iGpffffb664;

  if (param_1[0x3f1] != 0) {

    *(u32 *)(param_1[0x3f1] + 0xfc0) = param_1[0x3f0];

  }

  if (param_1[0x3f0] != 0) {

    *(u32 *)(param_1[0x3f0] + 0xfc4) = param_1[0x3f1];

  }

  if ((u32 *)puVar3[0x4997] == param_1) {

    puVar3[0x4997] = param_1[0x3f1];

  }

  if ((u32 *)puVar3[0x4998] == param_1) {

    puVar3[0x4998] = param_1[0x3f0];

  }


  FUN_00253600(param_1);

  *param_1 = *param_1 & 0xfffffffb;

  iVar1[0x499f] = (iStack_4 - 1) + iVar1[0x499f];
  return;

}

// FUN_002593D0


void FUN_002593d0(void)
{
  u32 *puVar1;
  u32 *card;
  int iVar2;

  K_ASSERT(sSflCardB664 != NULL, 0xbc);
  puVar1 = sSflCardB664;
  for (iVar2 = 0; iVar2 < 0x10; iVar2++) {
    card = puVar1 + iVar2 * 0x499 + 1;
    if ((~*card & 4) != 0 || (*card & 8) != 0) {
      continue;
    }
    switch (card[1]) {
      case 0:
        FUN_0021a760((u16)card[2]);
        break;
      case 1:
        FUN_0021a670(card[2],card[3]);
        break;
    }
  }
  *puVar1 &= 0xfffffbff;
}

// FUN_002594C0


void FUN_002594c0(void)
{
  SflCardVec stack;
  u32 *puVar1;
  u32 uVar2;
  void FUN_00250cf0(u32 *, void *, f32, f32, int);

  K_ASSERT(sSflCardB664 != NULL, 0xbc);
  puVar1 = sSflCardB664;
  stack = DAT_0068eac0;
  uVar2 = (u32)FUN_00488f30();
  puVar1[0x4a21] = uVar2 % puVar1[0x499f];
  FUN_00250cf0(puVar1 + 0x4a00, &stack, fGpffff8248, fGpffff83c0, 0x5a);
  FUN_0010a4e0(1,2,6,2);
  puVar1[0x4a1f] = 0;
  *puVar1 |= 0x40;
  puVar1[0x4a1c] = 5;
  *puVar1 |= 0x1000;
}

/* Recovered battle-misc harvest: 0x00253600-0x00258140 */
// FUN_00253600


void FUN_00253600(u32 *param_1)



{

  if ((*param_1 & 0x100) != 0) {

    if ((*param_1 & 0x80) != 0) {

      FUN_0034fcf0(param_1[0x492]);

    }

    FUN_0024daf0(param_1 + 0x3f3);

    FUN_0024daf0(param_1 + 0x425);

    FUN_0024daf0(param_1 + 0x40c);

    FUN_0024daf0(param_1 + 0x43e);

    FUN_0024daf0(param_1 + 0x45a);

    FUN_0024daf0(param_1 + 0x476);

  }

  *param_1 = *param_1 & 0xfffffeff;

  return;

}

// FUN_00258140


void FUN_00258140(void)
{
  u32 uVar1;
  u32 *puVar2;
  u32 *puVar3;
  u32 *work;
  SflCardVec stack;
  void FUN_00250cf0(u32 *, void *, f32, f32, int);

  K_ASSERT(sSflCard354 != NULL, 0xbc);
  puVar2 = sSflCard354;
  stack = DAT_0068eaa0;
  uVar1 = puVar2[0x49eb];
  K_ASSERT(puVar2 != NULL, 0xbc);
  puVar3 = (u32 *)sSflCard354[0x4997];
  while (puVar3 != NULL) {
    work = puVar3;
    if ((*puVar3 & 2) == 0 && puVar3[4] == uVar1) {
      break;
    }
    puVar3 = (u32 *)puVar3[0x3f1];
  }
  K_ASSERT(puVar3 != NULL, 0x47a);
  FUN_00250cf0(work + 0x45a, &stack, 0.0f, fGpffff8248, 0xc);
  work[0x494] = 0;
  work[0x495] = 0xc;
  work[0x493] = 3;
  *work |= 0x200;
  *puVar2 |= 0x40;
  puVar2[0x4a1c] = 1;
  puVar2[0x4a1d] = 0;
  *puVar2 &= 0xfffffffd;
}
