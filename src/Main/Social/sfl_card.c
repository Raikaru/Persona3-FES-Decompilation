#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_00253600(u32 *param_1);
void FUN_00253a40(void);
void FUN_00258140(void);
void FUN_00258300(void);
void FUN_00258540(u32 param_1,u64 param_2);
void FUN_00258630(u32 *param_1);
void FUN_00258b40(void);
void FUN_00258f80(u32 *param_1);
void FUN_002593d0(void);
void FUN_002594c0(void);
extern u32 DAT_0068ea10;
extern u32 DAT_0068ea18;
extern u32 DAT_0068eaa0;
extern u32 DAT_0068eaa8;
extern u32 DAT_0068eab0;
extern u32 DAT_0068eab8;
extern u32 DAT_0068eac0;
extern u32 DAT_0068eac8;
extern u32 DAT_007e094c;
extern u32 DAT_007e0952;
extern u32 DAT_007e0956;
extern u32 DAT_007e095a;
extern int iGpffffb664;
extern u32 uGpffff8248;

static u32* sSflCardB664; // puGpffffb664
static u32* sSflCard354;  // DAT_007ce354

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

// FUN_002580e0 NONMATCHING
void sflCard002580e0(void)
{
    K_ASSERT(sSflCard354 != NULL, 0xbc);
    *sSflCard354 &= 0xffffdfff;
}

// FUN_002582b0
u32 sflCard002582b0(void)
{
    K_ASSERT(sSflCard354 != NULL, 0xbc);
    return *sSflCard354 & 0x40;
}

// FUN_00253560 NONMATCHING
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

// FUN_00258090 NONMATCHING
void sflCard00258090(void)
{
    K_ASSERT(sSflCard354 != NULL, 0xbc);
    *sSflCard354 |= 0x2000;
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

/* Recovered battle-misc harvest: 0x00253A40-0x002594C0 */
// FUN_00253A40 NONMATCHING


void FUN_00253a40(void)



{

  u32 *puVar1;

  int iVar2;

  u32 *puVar3;

  long lVar4;

  u64 uVar5;

  u32 uVar6;

  u64 unaff_s0;

  u32 uVar7;

  int iVar8;

  u32 uVar9;

  float fVar10;

  u8 auStack_70 [16];

  int aiStack_60 [8];

  u32 auStack_40 [6];

  u64 uStack_28;

  u32 uStack_20;

  u32 uStack_18;

  u32 uStack_14;

  u8 auStack_10 [4];

  float fStack_c;

  u8 auStack_4 [4];

  

  puVar3 = (u32 *)unaff_s0;

  if (sSflCardB664 == (u32 *)0x0) {

    FUN_0019d3f0(0x68ea00,0xbc);

  }

  puVar1 = sSflCardB664;

  uStack_28 = DAT_0068ea10;

  uStack_20 = DAT_0068ea18;

  if (((*sSflCardB664 & 0x200) != 0) && (lVar4 = FUN_0021a120(), lVar4 == 0)) {

    *puVar1 = *puVar1 & 0xfffffdff;

  }

  if ((~*puVar1 & 1) == 0) {

    puVar1[0x49a0] = puVar1[0x49a0] + 1;

    if (((((*puVar1 & 0x20) != 0) && ((DAT_007e094c & 0x8000) == 0)) &&

        ((DAT_007e0956 & 0x8000) == 0)) &&

       (((DAT_007e094c & 0x2000) == 0 && ((DAT_007e0956 & 0x2000) == 0)))) {

      *puVar1 = *puVar1 & 0xffffffdf;

    }

    uVar6 = *puVar1;

    if ((((uVar6 & 4) == 0) || ((~uVar6 & 8) == 0)) || ((~uVar6 & 0x20) == 0)) {

      if ((uVar6 & 0x10) != 0) {

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

              fStack_c = fStack_c + 200.0;

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

              iVar8 = FUN_00255440(iVar2);

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

              fStack_c = fStack_c + 400.0;

              FUN_0024f9f0((int)unaff_s0 + 0x1094,auStack_10);

            }

            puVar1[0x49ed] = 0;

            puVar1[0x49ee] = 1;

          }

        }

      }

    }

    else if (((DAT_007e0952 & 0x8000) == 0) && ((DAT_007e095a & 0x8000) == 0)) {

      if (((DAT_007e0952 & 0x2000) != 0) || ((DAT_007e095a & 0x2000) != 0)) {

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

      if ((int)puVar1[0x49eb] < 1) {

        puVar1[0x49eb] = puVar1[0x499f] - 1;

        FUN_0025b3b0();

      }

      else {

        puVar1[0x49eb] = puVar1[0x49eb] - 1;

        FUN_0025b300();

        if (puVar1[0x49eb] == 0) {

          *puVar1 = *puVar1 | 0x20;

        }

      }

      FUN_0010a4e0(0,0,0,0);

    }

    if ((*puVar1 & 0x40) != 0) {

      switch(puVar1[0x4a1c]) {

      case 1:

        if (puVar1[0x4a1d] == 2) {

          puVar1[0x4a1f] = puVar1[0x4a1f] + 1;

          uVar6 = puVar1[0x4a1f];

          puVar3 = (u32 *)FUN_00255440(puVar1[0x49eb]);

          fVar10 = 1.0 - (float)(int)uVar6 / 10.0;

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

          puVar1[0x4a20] = (int)(((float)(int)puVar1[0x4a1f] / 6.0) * 256.0);

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

          puVar1[0x4a20] = (int)((1.0 - (float)(int)puVar1[0x4a1f] / 6.0) * 256.0);

          if (puVar1[0x4a1f] == 6) {


            puVar1[0x4a1f] = 0;

            puVar1[0x4a1e] = 1;

          }

        }

        break;

      case 3:

        puVar1[0x4a1f] = puVar1[0x4a1f] + 1;

        puVar1[0x4a20] = (int)(((float)(int)puVar1[0x4a1f] / 30.0) * 256.0);

        if (puVar1[0x4a1f] == 0x1e) {

          uVar6 = *puVar1;

          *puVar1 = uVar6 & 0xffffffbf;

          *puVar1 = uVar6 & 0xfffffebf;

        }

        break;

      case 4:

        puVar1[0x4a1f] = puVar1[0x4a1f] + 1;

        puVar1[0x4a20] = (int)((1.0 - (float)(int)puVar1[0x4a1f] / 16.0) * 256.0);

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

              iVar2 = FUN_00255440(uVar7);

              *(int *)(iVar2 + 0x1260) = (int)((1.0 - (float)(int)uVar6 / 30.0) * 256.0);

            }

          }

        }

        if (puVar1[0x4a1f] == 0x1e) {

          iVar2 = FUN_00255440(puVar1[0x49eb]);

          *(u32 *)(iVar2 + 0x1260) = 0;

          puVar1[0x49eb] = puVar1[0x4a21];

          iVar2 = FUN_00255440();

          *(u32 *)(iVar2 + 0x1260) = 0x100;

          FUN_00257d90(auStack_10,iVar2 + 0x18);

          FUN_0024f9f0(iVar2 + 0x1094,auStack_10);

          FUN_0024f2c0(0,iVar2 + 0x1030);

          FUN_00250ef0(0,iVar2 + 0x11d8);

        }

        puVar3 = (u32 *)FUN_00255440(puVar1[0x49eb]);

        FUN_0024fba0(puVar1 + 0x4a00,auStack_70);

        FUN_0024fc40(puVar3 + 0x45a,auStack_70);

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

      if (puVar1[0x4a1c] == 1) {

        uVar6 = puVar1[0x4a1d];

        if (uVar6 == 2) {

          lVar4 = FUN_00250b90(puVar3 + 0x425);

          if (lVar4 == 0) {

            *puVar1 = *puVar1 & 0xffffffbf;

          }

        }

        else if (uVar6 == 1) {

          for (uVar6 = 0; (int)uVar6 < (int)puVar1[0x499f]; uVar6 = uVar6 + 1) {

            if (uVar6 != puVar1[0x49eb]) {

              iVar2 = FUN_00255440(uVar6);

              lVar4 = FUN_00250e70(iVar2 + 0x1168);

              if (lVar4 != 0) break;

            }

          }

          if (uVar6 == puVar1[0x499f]) {

            iVar2 = FUN_00255440(puVar1[0x49eb]);

            uStack_18 = 0x43a00000;

            uStack_14 = 0x43380000;

            uVar9 = FUN_0020c500(0x43480000,iVar2 + 0x18);

            FUN_0020c400(uVar9,iVar2 + 0x18,&uStack_18,auStack_10);

            fStack_c = fStack_c + 100.0;

            FUN_00250500(iVar2 + 0x1094,auStack_10,10);

            if ((~*puVar1 & 0x2000) != 0) {

              FUN_0010a4e0(1,0,6,0xf);

            }

            puVar1[0x4a1f] = 0;

            puVar1[0x4a1d] = 2;

          }

        }

        else if (uVar6 == 0) {

          iVar2 = FUN_00255440(puVar1[0x49eb]);

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

        }

      }

      else if (puVar1[0x4a1c] == 0) {

        for (uVar6 = 0; (int)uVar6 < (int)puVar1[0x499f]; uVar6 = uVar6 + 1) {

          iVar2 = FUN_00255440(uVar6);

          lVar4 = FUN_00250e70(iVar2 + 0x1168);

          if (lVar4 != 0) break;

        }

        if (uVar6 == puVar1[0x499f]) {

          *puVar1 = *puVar1 & 0xffffffbf;

        }

      }

    }

  }

  return;

}

// FUN_00258300 NONMATCHING


void FUN_00258300(void)



{

  u32 uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  if (sSflCard354 == 0) {

    FUN_0019d3f0(0x68ea00,0xbc);

  }

  iVar2 = (int)sSflCard354;

  for (iVar4 = 0; iVar4 < 0x10; iVar4 = iVar4 + 1) {

    iVar3 = iVar2 + iVar4 * 0x1264;

    uVar1 = *(u32 *)(iVar3 + 4);

    if ((~uVar1 & 4) == 0) {

      if ((uVar1 & 0x100) != 0) {

        if ((uVar1 & 0x80) != 0) {

          FUN_0034fcf0(*(u32 *)(iVar3 + 0x124c));

        }

        FUN_0024daf0(iVar3 + 0xfd0);

        FUN_0024daf0(iVar3 + 0x1098);

        FUN_0024daf0(iVar3 + 0x1034);

        FUN_0024daf0(iVar3 + 0x10fc);

        FUN_0024daf0(iVar3 + 0x116c);

        FUN_0024daf0(iVar3 + 0x11dc);

      }

      *(u32 *)(iVar3 + 4) = *(u32 *)(iVar3 + 4) & 0xfffffeff;

    }

  }


  *(u32 *)(iVar2 + 0x1267c) = 0;

  *(u32 *)(iVar2 + 0x12684) = 0;

  *(u32 *)(iVar2 + 0x1265c) = 0;

  *(u32 *)(iVar2 + 0x12660) = 0;

  *(u32 *)(iVar2 + 0x127a8) = 0;

  for (iVar4 = 0; iVar4 < 0x10; iVar4 = iVar4 + 1) {

    iVar3 = iVar2 + iVar4 * 0x1264;

    *(u32 *)(iVar3 + 4) = 0;

    *(int *)(iVar3 + 0x18) = iVar4;

  }

  return;

}

// FUN_00258540 NONMATCHING


void FUN_00258540(u32 param_1,u64 param_2)



{

  u32 *puVar1;

  u32 *unaff_s0_lo;

  

  if (sSflCard354 == 0) {

    FUN_0019d3f0(0x68ea00,0xbc);

  }

  if (sSflCard354 == 0) {

    FUN_0019d3f0(0x68ea00,0xbc);

  }

  puVar1 = *(u32 **)(sSflCard354 + 0x1265c);

  while( 1 ) {

    if ((puVar1 == (u32 *)0x0) ||

       ((unaff_s0_lo = puVar1, (*puVar1 & 2) == 0 && (puVar1[4] == param_1)))) break;

    puVar1 = (u32 *)puVar1[0x3f1];

  }

  if (puVar1 == (u32 *)0x0) {

    FUN_0019d3f0(0x68ea00,0x47a);

  }

  FUN_0024f960(unaff_s0_lo + 0x3f3,param_2);

  return;

}

// FUN_00258630 NONMATCHING


void FUN_00258630(u32 *param_1)



{

  u32 uVar1;

  u64 uVar2;

  u32 *puVar3;

  int iVar4;

  u32 uVar5;

  u8 auStack_60 [24];

  u64 uStack_48;

  u32 uStack_40;

  u32 uStack_38;

  u32 uStack_34;

  u32 uStack_30;

  u8 auStack_28 [4];

  float fStack_24;

  u32 uStack_18;

  u32 uStack_14;

  u32 uStack_10;

  u32 uStack_c;

  u32 uStack_8;

  

  uStack_48 = DAT_0068eab0;

  uStack_40 = DAT_0068eab8;

  uVar1 = *param_1;

  *param_1 = uVar1 | 0x100;

  if ((~(uVar1 | 0x100) & 8) != 0) {

    uVar1 = param_1[1];

    if (uVar1 == 2) {

      FUN_0020ab30(param_1 + 6);

    }

    else if (uVar1 == 0) {

      FUN_00209f00(param_1 + 6);

      FUN_0020c590(param_1 + 6,(short)param_1[2]);

      if ((*param_1 & 1) != 0) {

        FUN_0020d6c0(param_1 + 6);

      }

      if ((*param_1 & 0x400) != 0) {

        FUN_0020d710(param_1 + 6);

      }

    }

    else if (uVar1 == 1) {

      FUN_0020a800(param_1 + 6);

      FUN_0020c5f0(param_1 + 6,param_1[2],param_1[3]);

    }

    else {

      FUN_0019d3f0(0x68ea00,0x8de);

    }

    uStack_10 = 0x41200000;

    uStack_c = 0x41200000;

    uStack_8 = 0x41200000;

    FUN_0020d630(param_1 + 6,&uStack_10);

    if (sSflCard354 == 0) {

      FUN_0019d3f0(0x68ea00,0xbc);

    }

    iVar4 = 0;

    for (puVar3 = *(u32 **)(sSflCard354 + 0x1265c); puVar3 != (u32 *)0x0;

        puVar3 = (u32 *)puVar3[0x3f1]) {

      if ((*puVar3 & 2) == 0) {

        iVar4 = iVar4 + 1;

      }

    }

    uStack_18 = FUN_0020c660(param_1[4],iVar4);

    uStack_14 = 0x43380000;

    uVar5 = FUN_0020c500(0x42b40000,param_1 + 6);

    FUN_0020c400(uVar5,param_1 + 6,&uStack_18,auStack_28);

    fStack_24 = fStack_24 + 100.0;

    FUN_0020d650(param_1 + 6,auStack_28);

    uStack_38 = 0;

    uStack_34 = 0x3f800000;

    uStack_30 = 0;

    FUN_004bdde0(0x43340000,param_1 + 10,&uStack_38,0);

    FUN_0020cd50(param_1 + 6,param_1 + 0x186);

  }

  FUN_0024fd80(param_1 + 0x425);

  FUN_0024f9f0(param_1 + 0x425,auStack_28);

  FUN_0024da60(param_1 + 0x425);

  FUN_0024f090(param_1 + 0x425);

  FUN_0024fd20(param_1 + 0x40c);

  FUN_0024f210(0x40400000,0x40c00000,param_1 + 0x40c,0x3c);

  FUN_0024da60(param_1 + 0x40c);

  FUN_0024f090(param_1 + 0x40c);

  FUN_0024fd40(param_1 + 0x3f3);

  FUN_002503f0(param_1 + 0x3f3,0,param_1 + 0x425);

  FUN_002503f0(param_1 + 0x3f3,1,param_1 + 0x40c);

  FUN_0024da60(param_1 + 0x3f3);

  FUN_0024f090(param_1 + 0x3f3);

  FUN_0024fe00(param_1 + 0x45a);

  FUN_004bdde0(0x43340000,auStack_60,&uStack_48,0);

  FUN_0024fc40(param_1 + 0x45a,auStack_60);

  FUN_0024da60(param_1 + 0x45a);

  FUN_0024f090(param_1 + 0x45a);

  FUN_0024fe20(param_1 + 0x476);

  FUN_0024da60(param_1 + 0x476);

  FUN_0024f090(param_1 + 0x476);

  FUN_0024fdc0(param_1 + 0x43e);

  FUN_0024da60(param_1 + 0x43e);

  FUN_0024f090(param_1 + 0x43e);

  FUN_00250be0(param_1 + 0x43e,0,param_1 + 0x45a);


  if ((*param_1 & 0x80) != 0) {

    uVar2 = FUN_0020e710(0);

    uVar1 = FUN_0034fcd0(uVar2);

    param_1[0x492] = uVar1;

    param_1[0x497] = 0x100;

  }

  param_1[0x498] = 0x100;

  return;

}

// FUN_00258B40 NONMATCHING


void FUN_00258b40(void)



{

  u32 *puVar1;

  u32 *puVar2;

  u32 uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  u32 *unaff_s2_lo;

  u32 *unaff_s3_lo;

  u32 uVar8;

  int aiStack_50 [8];

  int aiStack_30 [6];

  u32 uStack_18;

  u32 uStack_14;

  u8 auStack_10 [4];

  float fStack_c;

  u8 auStack_4 [4];

  

  if (sSflCardB664 == (u32 *)0x0) {

    FUN_0019d3f0(0x68ea00,0xbc);

  }

  puVar1 = sSflCardB664;

  for (iVar6 = 0; iVar6 < (int)puVar1[0x49a1]; iVar6 = iVar6 + 1) {


  }

  uVar3 = puVar1[0x499f];

  for (iVar6 = 0; iVar6 < (int)uVar3; iVar6 = iVar6 + 1) {

    aiStack_50[iVar6] = iVar6;

  }

  uVar3 = FUN_00488f30();

  for (iVar6 = 0; iVar6 < (int)((uVar3 & 0xf) + 0x400); iVar6 = iVar6 + 1) {

    iVar4 = FUN_00488f30();

    iVar4 = iVar4 % (int)puVar1[0x499f];

    iVar5 = FUN_00488f30();

    iVar5 = iVar5 % (int)(puVar1[0x499f] - 1);

    if (iVar4 <= iVar5) {

      iVar7 = iVar5 + 1;

      iVar5 = iVar4;

      iVar4 = iVar7;

    }

    iVar7 = aiStack_50[iVar5];

    aiStack_50[iVar5] = aiStack_50[iVar4];

    aiStack_50[iVar4] = iVar7;

  }

  for (uVar3 = 0; (int)uVar3 < (int)puVar1[0x499f]; uVar3 = uVar3 + 1) {

    if (sSflCardB664 == (u32 *)0x0) {

      FUN_0019d3f0(0x68ea00,0xbc);

    }

    for (puVar2 = (u32 *)sSflCardB664[0x4997];

        (puVar2 != (u32 *)0x0 &&

        ((unaff_s3_lo = puVar2, (*puVar2 & 2) != 0 || (puVar2[4] != uVar3))));

        puVar2 = (u32 *)puVar2[0x3f1]) {

    }

    if (puVar2 == (u32 *)0x0) {

      FUN_0019d3f0(0x68ea00,0x47a);

    }

    aiStack_30[uVar3] = (int)unaff_s3_lo;

  }

  for (iVar6 = 0; iVar6 < (int)puVar1[0x499f]; iVar6 = iVar6 + 1) {

    *(int *)(aiStack_30[iVar6] + 0x10) = aiStack_50[iVar6];

  }

  *puVar1 = *puVar1 & 0xffffffef;

  for (uVar3 = 0; (int)uVar3 < (int)puVar1[0x499f]; uVar3 = uVar3 + 1) {

    if (sSflCardB664 == (u32 *)0x0) {

      FUN_0019d3f0(0x68ea00,0xbc);

    }

    for (puVar2 = (u32 *)sSflCardB664[0x4997];

        (puVar2 != (u32 *)0x0 &&

        ((unaff_s2_lo = puVar2, (*puVar2 & 2) != 0 || (puVar2[4] != uVar3))));

        puVar2 = (u32 *)puVar2[0x3f1]) {

    }

    if (puVar2 == (u32 *)0x0) {

      FUN_0019d3f0(0x68ea00,0x47a);

    }

    FUN_00256fa0(unaff_s2_lo,aiStack_30,auStack_4);

    uStack_18 = FUN_0020c660(unaff_s2_lo[4],puVar1[0x499f]);

    uStack_14 = 0x43380000;

    uVar8 = FUN_0020c500(0x42b40000,aiStack_30[0] + 0x18);

    FUN_0020c400(uVar8,aiStack_30[0] + 0x18,&uStack_18,auStack_10);

    fStack_c = fStack_c + 100.0;

    FUN_00250480(unaff_s2_lo + 0x425);

    FUN_0024f9f0(unaff_s2_lo + 0x425,auStack_10);

    FUN_00250c70(unaff_s2_lo + 0x45a);

    FUN_0024f410(unaff_s2_lo + 0x40c);

    FUN_0024ff10(unaff_s2_lo + 0x476);

    FUN_0024f2c0(0x3f800000,unaff_s2_lo + 0x40c);

    FUN_00250ef0(0x3f800000,unaff_s2_lo + 0x476);

  }

  return;

}

// FUN_00258F80 NONMATCHING


void FUN_00258f80(u32 *param_1)



{

  int iVar1;

  u32 *puVar2;

  int iVar3;

  int aiStack_30 [8];

  u8 auStack_10 [12];

  int iStack_4;

  

  if (iGpffffb664 == 0) {

    FUN_0019d3f0(0x68ea00,0xbc);

  }

  iVar1 = iGpffffb664;

  FUN_00259190(param_1,aiStack_30,&iStack_4);

  for (puVar2 = *(u32 **)(iVar1 + 0x1265c); puVar2 != (u32 *)0x0; puVar2 = (u32 *)puVar2[0x3f1])

  {

    if (((*puVar2 & 2) == 0) && ((int)param_1[4] < (int)puVar2[4])) {

      puVar2[4] = puVar2[4] + iStack_4 + -1;

    }

  }

  for (iVar3 = 0; iVar3 < iStack_4; iVar3 = iVar3 + 1) {

    puVar2 = (u32 *)aiStack_30[iVar3];

    *puVar2 = *puVar2 & 0xfffffffd;

    puVar2[4] = puVar2[4] + param_1[4];

    FUN_0024f960(param_1 + 0x425,auStack_10);

    FUN_0024f9f0(puVar2 + 0x425,auStack_10);

  }

  if (iGpffffb664 == 0) {

    FUN_0019d3f0(0x68ea00,0xbc);

  }

  if (param_1[0x3f1] != 0) {

    *(u32 *)(param_1[0x3f1] + 0xfc0) = param_1[0x3f0];

  }

  if (param_1[0x3f0] != 0) {

    *(u32 *)(param_1[0x3f0] + 0xfc4) = param_1[0x3f1];

  }

  if (*(u32 **)(iGpffffb664 + 0x1265c) == param_1) {

    *(u32 *)(iGpffffb664 + 0x1265c) = param_1[0x3f1];

  }

  if (*(u32 **)(iGpffffb664 + 0x12660) == param_1) {

    *(u32 *)(iGpffffb664 + 0x12660) = param_1[0x3f0];

  }


  *param_1 = *param_1 & 0xfffffffb;

  *(int *)(iVar1 + 0x1267c) = *(int *)(iVar1 + 0x1267c) + iStack_4 + -1;

  return;

}

// FUN_002593D0 NONMATCHING


void FUN_002593d0(void)



{

  u32 *puVar1;

  int iVar2;

  

  if (sSflCardB664 == (u32 *)0x0) {

    FUN_0019d3f0(0x68ea00,0xbc);

  }

  puVar1 = sSflCardB664;

  for (iVar2 = 0; iVar2 < 0x10; iVar2 = iVar2 + 1) {

    if (((~puVar1[iVar2 * 0x499 + 1] & 4) == 0) && ((puVar1[iVar2 * 0x499 + 1] & 8) == 0)) {

      if (puVar1[iVar2 * 0x499 + 2] == 1) {

        FUN_0021a670(puVar1[iVar2 * 0x499 + 3],puVar1[iVar2 * 0x499 + 4]);

      }

      else if (puVar1[iVar2 * 0x499 + 2] == 0) {

        FUN_0021a760((short)puVar1[iVar2 * 0x499 + 3]);

      }

    }

  }

  *puVar1 = *puVar1 & 0xfffffbff;

  return;

}

// FUN_002594C0 NONMATCHING


void FUN_002594c0(void)



{

  u32 *puVar1;

  int iVar2;

  u64 uStack_10;

  u32 uStack_8;

  

  if (sSflCardB664 == (u32 *)0x0) {

    FUN_0019d3f0(0x68ea00,0xbc);

  }

  puVar1 = sSflCardB664;

  uStack_10 = DAT_0068eac0;

  uStack_8 = DAT_0068eac8;

  iVar2 = FUN_00488f30();

  puVar1[0x4a21] = iVar2 % (int)puVar1[0x499f];


  FUN_0010a4e0(1,2,6,2);

  puVar1[0x4a1f] = 0;

  *puVar1 = *puVar1 | 0x40;

  puVar1[0x4a1c] = 5;

  *puVar1 = *puVar1 | 0x1000;

  return;

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

// FUN_00258140 NONMATCHING


void FUN_00258140(void)



{

  u32 uVar1;

  u32 *puVar2;

  u32 *puVar3;

  u32 *unaff_s2_lo;

  u64 uStack_10;

  u32 uStack_8;

  

  if (sSflCard354 == (u32 *)0x0) {

    FUN_0019d3f0(0x68ea00,0xbc);

  }

  puVar2 = sSflCard354;

  uStack_10 = DAT_0068eaa0;

  uStack_8 = DAT_0068eaa8;

  uVar1 = sSflCard354[0x49eb];

  if (sSflCard354 == (u32 *)0x0) {

    FUN_0019d3f0(0x68ea00,0xbc);

  }

  puVar3 = (u32 *)sSflCard354[0x4997];

  while( 1 ) {

    if ((puVar3 == (u32 *)0x0) ||

       ((unaff_s2_lo = puVar3, (*puVar3 & 2) == 0 && (puVar3[4] == uVar1)))) break;

    puVar3 = (u32 *)puVar3[0x3f1];

  }

  if (puVar3 == (u32 *)0x0) {

    FUN_0019d3f0(0x68ea00,0x47a);

  }


  unaff_s2_lo[0x494] = 0;

  unaff_s2_lo[0x495] = 0xc;

  unaff_s2_lo[0x493] = 3;

  *unaff_s2_lo = *unaff_s2_lo | 0x200;

  *puVar2 = *puVar2 | 0x40;

  puVar2[0x4a1c] = 1;

  puVar2[0x4a1d] = 0;

  *puVar2 = *puVar2 & 0xfffffffd;

  return;

}
