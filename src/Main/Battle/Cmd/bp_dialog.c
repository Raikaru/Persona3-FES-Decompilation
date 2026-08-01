#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

void FUN_003b0170();



/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_0025be60(u32 param_1, u32 param_2, u32 param_3);
void FUN_0025c220(void);
void FUN_0025c9c0(void);
void FUN_0025cd30(void);
void FUN_0025cdb0(float param_1,float param_2,int param_3);
void FUN_0025ce30(float param_1,float param_2,int param_3);
int FUN_0025ceb0(int param_1);
s32 FUN_0021c3f0();
#pragma alias FUN_0021c3f0_u64 FUN_0021c3f0
extern u64 FUN_0021c3f0_u64(u32 param_1);
extern u32 FUN_003a52c0(float param_1, s32 param_2, s32 param_3,
                        s32 param_4, s32 param_5, s32 param_6,
                        u32 param_7, u32 param_8);
extern void func_003b0e20(u32 resource, u32 color);
void FUN_0025cf00(u32 *param_1);
void FUN_0025cf10(void);
void FUN_0025cf20(void);
static u32* sBpDialog678;
static u32* sBpDialog36c;
static u32* sBpDialog368; // 007ce368
#pragma alias DAT_007e094e_abs DAT_007e094e
extern u16 DAT_007e094e_abs[];
extern code DAT_00960090;
#pragma alias DAT_00960090_abs DAT_00960090
#pragma alias DAT_0096009c_abs DAT_0096009c
extern code DAT_00960090_abs[];
extern code DAT_0096009c_abs[];
extern code DAT_0096009c;
extern int iGpffffb6fc;

extern void FUN_0019d3f0(const char* file, s32 line);
extern const char DAT_0068ebd8[];
extern const char DAT_0068ebe8[];
#define FUN_0019d3f0(file, line) FUN_0019d3f0((const char*)(file), line)

// FUN_0025be00
void bpDialog0025be00(void)
{
    K_ASSERT(sBpDialog368 != NULL, 0x3c);
    if (*sBpDialog368 & 1) {
        FUN_003b0170(sBpDialog368[1]);
    }
    sBpDialog368 = NULL;
}

// FUN_0025BE60


void FUN_0025be60(u32 param_1, u32 param_2, u32 param_3)



{

  u32 *puVar1;

  int iVar2;

  u32 uVar3;

  u64 uVar4;

  int iVar4;

  u32 uVar6;

  

  if (sBpDialog678 == (u32 *)0x0) {

    FUN_0019d3f0(DAT_0068ebd8, 0x3c);

  }
  puVar1 = sBpDialog678;

  iVar2 = iGpffffb6fc;

  uVar4 = FUN_0021c3f0_u64(0);

  if ((*puVar1 & 4) != 0) {

    FUN_0025cd30();

  }

  uVar3 = FUN_003a52c0(0,100,100,0xffffffffffffffff,0,6,*(u32 *)(iVar2 + 0xba0),param_1);

  puVar1[1] = uVar3;

  uVar3 = FUN_003a52c0(0,100,100,0xffffffffffffffff,0,0,*(u32 *)(iVar2 + 0xba0),param_2);

  puVar1[2] = uVar3;

  uVar3 = FUN_003a52c0(0,100,100,0xffffffffffffffff,0,0,*(u32 *)(iVar2 + 0xba0),param_3);

  puVar1[3] = uVar3;

  iVar4 = FUN_0025ceb0(puVar1[1]);
  switch (iVar4) {
  case 1:
    puVar1[0xca] = 0;
    break;
  case 2:
    puVar1[0xca] = 1;
    break;
  default:
    FUN_0019d3f0(DAT_0068ebd8, 0x7b);
    break;
  }

  switch (puVar1[0xca]) {
  case 0:
    puVar1[200] = 0x55;
    puVar1[0xc9] = 0x56;
    break;
  case 1:
    puVar1[200] = 0x57;
    puVar1[0xc9] = 0x58;
    break;
  }

  uVar6 = FUN_0021cca0(uVar4,puVar1[200]);

  FUN_0021d3b0(puVar1 + 8,uVar6);

  uVar6 = FUN_0021cca0(uVar4,puVar1[200]);

  FUN_0021e380(puVar1 + 0x48,uVar6,1);

  uVar6 = FUN_0021cca0(uVar4,puVar1[0xc9]);

  FUN_0021d3b0(puVar1 + 0x88,uVar6);

  uVar6 = FUN_0021cca0(uVar4,0x59);

  FUN_0021d3b0(puVar1 + 0xcc,uVar6);

  uVar6 = FUN_0021cca0(uVar4,0x5a);

  FUN_0021d3b0(puVar1 + 0x10c,uVar6);

  puVar1[5] = 0;

  puVar1[6] = 0;

  uVar3 = *puVar1 & ~2u;

  *puVar1 = uVar3;

  *puVar1 = uVar3 = uVar3 & ~8u;

  *puVar1 = uVar3 = uVar3 | 4;

  *puVar1 = uVar3 = uVar3 | 1;

  return;

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

// FUN_0025c190
u32 bpDialog0025c190(void)
{
    K_ASSERT(sBpDialog368 != NULL, 0x3c);
    return *sBpDialog368 & 2;
}

/* Recovered battle-misc harvest: 0x0025BE60-0x0025CF20 */
// FUN_0025c1e0
u32 bpDialog0025c1e0(void)
{
    K_ASSERT(sBpDialog368 != NULL, 0x3c);
    return sBpDialog368[4];
}

// W389 measured source regrouping plus six-knob singles/pairs: nd2/1940B
// -> nd2/1940B (window 1952B). Residual is commutative operand order of
// `mul.s $f20, $f20, $f0` versus retail's `mul.s $f20, $f0, $f20`;
// MWCCPS2 b210 canonicalizes the source form.
// FUN_0025C220 NONMATCHING
void FUN_0025c220(void)
{
    u32* puVar1;
    s32 iVar2;
    s32 iVar3;
    s32 uVar6;
    s32 uVar7;
    u32 uVar4;
    u32 uVar5;
    f32 fVar6;
    f32 fVar7;
    f32 fVar8;
    f32 fVar9;
    f32 fVar10;
    f32 fVar11;
    struct {
        f32 rect[4];
        u8 reserved[0x1c];
        u8 color[4];
    } layout;
    s32 i;

    if (sBpDialog368 == NULL) {
        FUN_0019d3f0(DAT_0068ebd8, 0x3c);
    }
    puVar1 = sBpDialog368;
    uVar4 = FUN_0021c3f0(0);
    uVar5 = ~*puVar1;
    if ((uVar5 & 1) == 0) {
        if ((s32)puVar1[5] >= 8) {
            if (((uVar5 & 2) != 0) && ((*puVar1 & 0x10) != 0)) {
                if ((DAT_007e094e_abs[0] & 0x40) != 0) {
                    puVar1[4] = 0;
                    *puVar1 |= 2;
                    FUN_0010a4e0(0, 0, 0, 1);
                } else if ((DAT_007e094e_abs[0] & 0x20) != 0) {
                    puVar1[4] = 1;
                    *puVar1 |= 2;
                    FUN_0010a4e0(0, 0, 0, 2);
                }
            }
        }
        if ((s32)puVar1[5] < 8) {
            puVar1[5] = puVar1[5] + 1;
        } else {
            if (((~*puVar1) & 0x10) != 0) {
                *puVar1 |= 0x10;
            }
        }
        if ((*puVar1 & 8) != 0) {
            uVar5 = puVar1[6] + 1;
            puVar1[6] = uVar5;
            if (uVar5 == 4) {
                FUN_0025cd30();
                *puVar1 &= ~1u;
            }
        }

        fVar11 = 0.0f;
        iVar2 = FUN_003b19d0(puVar1[2]);
        fVar11 = fVar11 + (f32)iVar2;
        iVar3 = FUN_003b19d0(puVar1[3]);
        fVar11 = fVar11 + (f32)iVar3;
        fVar11 = fVar11 + 25.0f;
        fVar11 = fVar11 + 30.0f;
        fVar11 = fVar11 + 30.0f;
        fVar7 = 252.0f - fVar11 / 2.0f;

        switch (puVar1[0xca]) {
        case 0:
            fVar8 = 339.0f;
            break;
        case 1:
            fVar8 = 367.0f;
            break;
        }

        fVar6 = 1.0f - (f32)(s32)puVar1[6] / 4.0f;
        uVar5 = puVar1[5];
        if ((s32)uVar5 < 4) {
            fVar10 = (f32)(s32)uVar5 / 4.0f;
        } else {
            fVar10 = 1.0f;
        }
        if ((s32)uVar5 < 0) {
            fVar11 = 0.0f;
        } else if ((s32)uVar5 < 8) {
            fVar11 = (f32)(s32)uVar5 / 8.0f;
        } else {
            fVar11 = 1.0f;
        }

        FUN_0025ce30(252.0f, 302.0f, puVar1[1]);
        fVar9 = fVar7 + 30.0f;
        FUN_0025cdb0(fVar9, fVar8 - 5.0f, puVar1[2]);
        iVar2 = FUN_003b19d0(puVar1[2]);
        FUN_0025cdb0(30.0f + (25.0f + (fVar9 + (f32)iVar2)),
                     fVar8 - 5.0f, puVar1[3]);
        fVar10 = 255.0f * fVar10 * fVar6;
        uVar6 = (u8)fVar10;
        uVar6 |= 0xffffff00u;
        func_003b0e20(puVar1[1], uVar6);

        fVar11 = (255.0f * fVar6) * fVar11;
        uVar7 = (u8)fVar11;
        uVar7 |= 0xffffff00u;
        func_003b0e20(puVar1[2], uVar7);
        func_003b0e20(puVar1[3], uVar7);

        iVar2 = FUN_0021cca0(uVar4, puVar1[200]);
        layout.rect[0] = 32.0f;
        layout.rect[1] = 282.0f;
        layout.rect[2] = (f32)*(s32*)(iVar2 + 0xc);
        layout.rect[3] = (f32)*(s32*)(iVar2 + 0x10);
        FUN_0021d8e0(puVar1 + 8, layout.rect);
        layout.rect[0] = (f32)*(s32*)(iVar2 + 0xc) + 32.0f;
        layout.rect[1] = 282.0f;
        layout.rect[2] = 419.0f;
        layout.rect[3] = (f32)*(s32*)(iVar2 + 0x10);
        FUN_0021d8e0(puVar1 + 0x48, layout.rect);

        iVar2 = FUN_0021cca0(uVar4, puVar1[0xc9]);
        layout.rect[0] = 462.0f;
        layout.rect[1] = 282.0f;
        layout.rect[2] = (f32)*(s32*)(iVar2 + 0xc);
        layout.rect[3] = (f32)*(s32*)(iVar2 + 0x10);
        FUN_0021d8e0(puVar1 + 0x88, layout.rect);

        layout.color[0] = 0xff;
        layout.color[1] = 0xff;
        layout.color[2] = 0xff;
        layout.color[3] = (u8)fVar10;
        for (i = 0; i < 3; i++) {
            FUN_0021d950(puVar1 + i * 0x40 + 8, layout.color);
        }

        iVar2 = FUN_0021cca0(uVar4, 0x59);
        layout.rect[0] = fVar7;
        layout.rect[1] = fVar8;
        layout.rect[2] = (f32)*(s32*)(iVar2 + 0xc);
        layout.rect[3] = (f32)*(s32*)(iVar2 + 0x10);
        FUN_0021d8e0(puVar1 + 0xcc, layout.rect);
        iVar2 = FUN_0021cca0(uVar4, 0x5a);
        iVar3 = FUN_003b19d0(puVar1[2]);
        layout.rect[0] = fVar9 + (f32)iVar3 + 25.0f;
        layout.rect[1] = fVar8;
        layout.rect[2] = (f32)*(s32*)(iVar2 + 0xc);
        layout.rect[3] = (f32)*(s32*)(iVar2 + 0x10);
        FUN_0021d8e0(puVar1 + 0x10c, layout.rect);

        layout.color[0] = 0xff;
        layout.color[1] = 0xff;
        layout.color[2] = 0xff;
        layout.color[3] = (u8)fVar11;
        for (i = 0; i < 2; i++) {
            FUN_0021d950(puVar1 + i * 0x40 + 0xcc, layout.color);
        }
    }
}

// FUN_0025C9C0


void FUN_0025c9c0(void)



{

  volatile /* Removing this function's qualifier batch loses FUN_0025c9c0 (MATCH nd0 -> MISMATCH nd569, size 868 -> 908) - measured W170. */ code *pDraw;
  volatile /* Removing this function's qualifier batch loses FUN_0025c9c0 (MATCH nd0 -> MISMATCH nd569, size 868 -> 908) - measured W170. */ code *pState;
  u32 *puVar1;
  int iVar2;
  int iVar3;
  

  if (sBpDialog368 == (u32 *)0x0) {

    FUN_0019d3f0(DAT_0068ebd8,0x3c);

  }

  puVar1 = sBpDialog368;

  iVar2 = FUN_0021c3f0(0);

  if ((~*puVar1 & 1) == 0) {
    pState = DAT_00960090_abs;

    (*pState)(9,2);

    (*pState)(0x14,2);

    (*pState)(8,0);

    (*pState)(6,0);

    iVar3 = FUN_0021cca0(iVar2, puVar1[200]);

    iVar3 = FUN_0021cce0(iVar3);

    (*pState)(1,iVar3);

    FUN_004d7f60(3,0x717fb);

    FUN_004d7f60(2,0x44);

    pDraw = DAT_0096009c_abs;
    (*pDraw)(puVar1 + 8,4,0,1,2);

    (*pDraw)(puVar1 + 8,4,0,2,3);

    (*pDraw)(puVar1 + 0x48,4,0,1,2);

    (*pDraw)(puVar1 + 0x48,4,0,2,3);

    iVar3 = FUN_0021cca0(iVar2, puVar1[0xc9]);

    iVar3 = FUN_0021cce0(iVar3);

    (*pState)(1,iVar3);

    (*pDraw)(puVar1 + 0x88,4,0,1,2);

    (*pDraw)(puVar1 + 0x88,4,0,2,3);

    FUN_004d7f60(3,0x717fb);

    FUN_004d7f60(2,0x44);

    iVar3 = FUN_0021cca0(iVar2, 0x59);

    iVar3 = FUN_0021cce0(iVar3);

    (*pState)(1,iVar3);

    (*pDraw)(puVar1 + 0xcc,4,0,1,2);

    (*pDraw)(puVar1 + 0xcc,4,0,2,3);

    iVar3 = FUN_0021cca0(iVar2, 0x5a);

    iVar3 = FUN_0021cce0(iVar3);

    (*pState)(1,iVar3);

    (*pDraw)(puVar1 + 0x10c,4,0,1,2);

    (*pDraw)(puVar1 + 0x10c,4,0,2,3);

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

// FUN_0025CDB0


void FUN_0025cdb0(float x, float y, int node)
{
    int lastNode;

    lastNode = 0;
    for (; node != 0; node = *(int*)(node + 0x24))
    {
        if (node != 0)
        {
            lastNode = node;
        }
    }
    FUN_003b1c40((int)(x * 16.0f), (int)(y * 8.0f), lastNode);
}

// FUN_0025CE30


void FUN_0025ce30(float x, float y, int node)
{
    int lastNode;

    lastNode = 0;
    for (; node != 0; node = *(int*)(node + 0x24))
    {
        if (node != 0)
        {
            lastNode = node;
        }
    }
    FUN_003b1c90((int)(x * 16.0f), (int)(y * 8.0f), lastNode);
}

// FUN_0025CEB0


int FUN_0025ceb0(int param_1)



{

  int iVar1;

  

  iVar1 = 0;

  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {

    if (param_1 != 0) {

      iVar1 = param_1;

    }

  }

  return FUN_003b1a90(iVar1);

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

