#include "Utils.h"
#include "Kosaka/k_assert.h"
#include "Battle/battle.h"
#include "Main/Battle/Cmd/bpp_main.h"
extern const char D_0068E880[];
extern const char DAT_007cc468[];

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned int ulong;
extern f32 sinf(f32 angle);
extern f32 cosf(f32 angle);

/* BPC state rooted at DAT_007CE320 / GP-0x49D0. */
extern u32* DAT_007ce320;
#define sBpcWork DAT_007ce320
#pragma alias bppMain0020f8b0_u16 bppMain0020f8b0
extern void bppMain0020f8b0_u16(u16 pcId);
#pragma alias bppMain0020fb60_u16 bppMain0020fb60
extern void bppMain0020fb60_u16(u16 pcId);
#pragma alias bppMain0020f7d0_u16 bppMain0020f7d0
extern void bppMain0020f7d0_u16(u16 pcId);
#pragma alias bppMain0020fa80_u16 bppMain0020fa80
extern void bppMain0020fa80_u16(u16 pcId);
#pragma alias func_001775a0_s16 func_001775a0
extern u32 func_001775a0_s16(s16 id);

typedef void (*BpcRenderState)(s32 property, u32 value);
typedef void (*BpcRenderQuad)(void* quad, s32 count, s32 group, s32 pass, s32 blend);
extern BpcRenderState D_00960090;
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
#pragma alias D_0096009C_abs D_0096009C
extern u8 D_0096009C_abs[];
extern BpcRenderQuad D_0096009C;
extern f32 DAT_007caf38;
extern u32 DAT_007ce4e8;
extern u8* DAT_007ce410;

extern int func_001ff430(u32 id);
extern u32 func_0021c3f0(s32 texture);
extern u32 func_0021cca0(u32 texture, s32 frame);
extern u32 func_0021cce0(u32 frame);
extern void func_0021d3b0(void* destination, u32 frame);
extern void func_0021d890(void* destination, const f32* layout);
extern void func_0021d8e0(void* destination, const f32* layout);
extern void func_0021d950(void* destination, const u8* color);
extern void func_0021e380(void* destination, u32 frame, s32 mode);
extern void func_0021eb80(void* destination, const f32* layout);
extern void func_0021cd00(u32 frame, f32* rect);
extern void func_00280580(int unit, void* projected);
extern u32 func_002d20a0(const void* projected, void* screen);
extern int func_0029a1d0(int unit);
extern int func_00301ca0(u32 calc, u32 skill);
extern int func_00300e90(u32 calc, s16 id);
extern u32 func_00306e80(u32 calc, u16 mode);
extern s16 func_003082f0(u32 mode, s16 id);
extern void func_003b0170(u32 resource);
extern u32 func_003b0970(u32 resource, s32 mode, s32 group, s32 a, s32 b);
extern void func_003b0d70(u32 resource, s32 x, s32 y);
extern void func_003b0e20(u32 resource, u32 value);
extern void func_003b0e70(s32 mode);
extern void func_003b0e90(s32 mode);
extern void func_003b1360(u32 resource, s32 mode, s32 value);
extern s32 func_003b19d0(u32 resource);
extern void func_004d7f60(s32 state, u32 value);
extern u32 func_00173370(u32 persona);
extern u32 func_00174800(s32 id);
extern s32 func_00176a30(u32 persona);
extern u32 func_001775a0(u16 id);
extern u32 func_0017b260(u16 id);
extern u32 func_001ff630(s32 index);
extern u32 func_0010a4e0(s32 a, s32 b, s32 c, s32 d);
extern u32 datPersonaGetByPcId(s32 id);
extern u32 datPersonaGetSkills(u32 persona);
extern s32 datPersonaCountValidSkills(u32 persona);
extern int printf(const char* format, ...);




/* High-gap entry points; declarations keep cross-calls typed under MWCC. */
void FUN_00242c40(u32*);
void FUN_00242c60(void);
void FUN_00242cc0(void);
void FUN_00243150(void);
void FUN_00244120(u32);
void FUN_002441b0(u32);
void FUN_00244770(void);
void FUN_002449d0(void);
void FUN_00244a00(void);
void FUN_00244a40(u32);
u32 FUN_00244e10(void);
void FUN_00244e80(void);
void FUN_002453d0(u16);
void FUN_00245420(uint*,u32);
void FUN_00245910(uint*);
void FUN_00245970(uint*);
void FUN_002459d0(uint*);
void FUN_00245a00(void);
uint *FUN_00245bf0(int);
void FUN_00245cd0(void);
void FUN_00245e00(void);
void FUN_00245e50(void);
void FUN_00245ea0(void);

// FUN_00242C40
void FUN_00242c40(u32 *param_1)

{
  *param_1 = 0;
  param_1[2] = 0;
  param_1[0x1cb5] = 0;
  sBpcWork = param_1;
  return;
}



// FUN_00242C60
void FUN_00242c60(void)

{
  if (sBpcWork == (uint *)0x0) {
    K_Assert(D_0068E880, 0x97);
  }
  if ((*sBpcWork & 2) != 0) {
    func_003b0170(sBpcWork[0x1b30]);
  }
  sBpcWork = (uint *)0x0;
  return;
}



// FUN_00242CC0
void FUN_00242cc0(void)

{
  int iVar7;
  int iVar8;
  int iVar9;
  uint *puVar1;
  uint uVar2;
  u32 uVar3;
  u32 uVar9;
  u32 uVar10;
  u32 lVar4;
  uint *puVar6;
  uint *puVar7;
  u8 auStack_10 [16];
  
  if (sBpcWork == (uint *)0x0) {
    K_Assert(D_0068E880, 0x97);
  }
  puVar1 = sBpcWork;
  func_0021c3f0(2);
  func_0021c3f0(1);
  func_0021c3f0(5);
  func_0021c3f0(3);
  if (((~*puVar1 & 1) == 0) || ((~*puVar1 & 0x20) == 0)) {
    if ((int)puVar1[0x1cb5] < 0x3b) {
      puVar1[0x1cb5] = puVar1[0x1cb5] + 1;
    }
    else {
      puVar1[0x1cb5] = 0;
    }
    for (iVar7 = 0; uVar2 = puVar1[3], iVar7 < (int)uVar2; iVar7 = iVar7 + 1) {
      puVar6 = puVar1 + iVar7 * 0x290 + 0x10;
      uVar2 = puVar1[1];
      switch (uVar2) {
      case 0:
      case 1:
        iVar8 = 0;
        uVar10 = puVar1[2];
        while (iVar8 < (int)uVar10) {
          puVar7 = puVar1 + iVar8 + 4;
          if (*puVar7 == puVar6[2]) break;
          iVar8 = iVar8 + 1;
        }
        if (((~*puVar6 & 0x20) != 0) && (iVar8 == uVar10)) goto LAB_0024307c;
        break;
      case 2:
        uVar2 = ~*puVar6;
        if ((uVar2 & 0x400) == 0) goto LAB_00242e4c;
        if ((uVar2 & 0x20) == 0) goto LAB_00242e4c;
        if ((uVar2 & 0x80) != 0) goto LAB_0024307c;
        break;
      }
LAB_00242e4c:
      uVar9 = *puVar6;
      if ((uVar9 & 0x10) != 0) {
        if ((int)puVar6[0x1c4] < 10) {
          puVar6[0x1c4] = puVar6[0x1c4] + 1;
        }
        else {
          *puVar6 = uVar9 & 0xffffffef;
        }
      }
      else if ((uVar9 & 0x20) != 0) {
        if ((int)puVar6[0x1c4] < 10) {
          puVar6[0x1c4] = puVar6[0x1c4] + 1;
        }
        else {
          *puVar6 = uVar9 & 0xffffffdf;
        }
      }
      else if ((uVar9 & 0x200) != 0) {
        if ((int)puVar6[0x1c4] < 4) {
          puVar6[0x1c4] = puVar6[0x1c4] + 1;
        }
        else {
          *puVar6 = uVar9 & 0xfffffdff;
        }
      }
      switch (puVar1[1]) {
      case 2:
        if ((*puVar6 & 0x80) != 0) {
          for (uVar2 = 0; (int)uVar2 < 3; uVar2 = uVar2 + 1) {
            if ((int)puVar6[0x288] < 0) {
              K_Assert(D_0068E880, 0xff);
            }
            if ((int)puVar6[0x288] >= 3) {
              K_Assert(D_0068E880, 0x100);
            }
            if (uVar2 == puVar6[0x288]) {
              puVar7 = puVar6 + 0x289 + uVar2;
              if ((int)*puVar7 < 10) {
                *puVar7 = *puVar7 + 1;
              }
            }
            else if (0 < (int)(puVar7 = puVar6 + 0x289 + uVar2, *puVar7)) {
              *puVar7 = *puVar7 - 1;
            }
          }
        }
        break;
      }
      uVar3 = func_001ff430(puVar6[2]);
      uVar2 = datCalcGetHp(*(u32 *)(uVar3 + 0xa2c));
      puVar6[0x28c] = uVar2 & 0xffff;
      uVar2 = datCalcGetMaxHp(*(u32 *)(uVar3 + 0xa2c));
      puVar6[0x28d] = uVar2 & 0xffff;
      func_00280580(uVar3,auStack_10);
      *puVar6 = *puVar6 & 0xffffffbf;
      lVar4 = func_002d20a0(auStack_10,puVar6 + 0x28e);
      if (lVar4 == 0) {
        *puVar6 = *puVar6 | 0x40;
      }
      *(f32 *)(puVar6 + 0x28f) = *(f32 *)(puVar6 + 0x28f) + 20.0f;
LAB_0024307c:
    ;
    }
    if ((*puVar1 & 0x20) != 0) {
      iVar9 = 0;
      while ((int)iVar9 < (int)uVar2) {
        puVar7 = puVar1 + iVar9 * 0x290 + 0x10;
        if ((*puVar7 & 0x20) != 0) break;
        iVar9 = iVar9 + 1;
      }
      if (iVar9 == uVar2) {
        *puVar1 = *puVar1 & 0xffffffdf;
      }
    }
    if (((~*puVar1 & 1) == 0) || ((~*puVar1 & 0x20) == 0)) {
      FUN_00245ea0();
    }
  }
  return;
}



// FUN_00243150 NONMATCHING
void FUN_00243150(void)

{
  uint *puVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  BpcRenderState *renderState;
  BpcRenderQuad *renderQuadA;
  BpcRenderQuad *renderQuadB;
  BpcRenderQuad *renderQuadC;
  BpcRenderQuad *renderQuadDEF;
  BpcRenderQuad *renderQuadGH;
  BpcRenderQuad *renderQuadIJ;
  BpcRenderQuad *renderQuadKP;
  BpcRenderQuad *renderQuadQ;
  BpcRenderQuad *renderQuadR;
  BpcRenderQuad *renderQuadS;
  BpcRenderQuad *renderQuadT;
  
  
  if (sBpcWork == (uint *)0x0) {
    K_Assert(D_0068E880, 0x97);
  }
  puVar1 = sBpcWork;
  uVar3 = func_0021c3f0(2);
  uVar4 = func_0021c3f0(1);
  uVar2 = func_0021c3f0(5);
  uVar5 = func_0021c3f0(3);
  uVar8 = ~*puVar1;
  if (((uVar8 & 1) == 0) || ((uVar8 & 0x20) == 0)) {
    if ((uVar8 & 0x100) != 0) {
      FUN_00245ea0();
    }
    renderState = (BpcRenderState *)D_00960090_abs;
#define D_00960090 (*renderState)
#define D_0096009C (*renderQuad)
    D_00960090(9,2);
    D_00960090(0x14,2);
    D_00960090(8,0);
    D_00960090(6,0);
    for (iVar10 = 0; iVar10 < (int)puVar1[3]; iVar10 = iVar10 + 1) {
      puVar9 = puVar1 + iVar10 * 0x290 + 0x10;
      uVar8 = puVar1[1];
      switch (uVar8) {
      case 0:
      case 1:
        for (iVar11 = 0;
            (iVar11 < (int)puVar1[2] && (puVar1[iVar11 + 4] != puVar1[iVar10 * 0x290 + 0x12]));
            iVar11 = iVar11 + 1) {
        }
        if (((~*puVar9 & 0x20) != 0) && (iVar11 == puVar1[2])) goto LAB_00243a18;
        break;
      case 2:
        uVar8 = ~*puVar9;
        if ((((uVar8 & 0x400) == 0) || ((uVar8 & 0x20) == 0)) || ((uVar8 & 0x80) == 0))
        goto LAB_00243348;
        break;
      default:
        goto LAB_00243348;
      }
LAB_00243348:
        if ((*puVar9 & 0x40) == 0) {
          if ((*puVar9 & 1) != 0) {
            uVar7 = func_0021cca0(uVar4,0x2c);
            uVar7 = func_0021cce0(uVar7);
            D_00960090(1,uVar7);
            func_004d7f60(3,0x71801);
            func_004d7f60(2,0x48);
            renderQuadA = (BpcRenderQuad *)D_0096009C_abs;
            (*renderQuadA)(puVar9 + 0x144, 4,0,1,2);
            (*renderQuadA)(puVar9 + 0x144, 4,0,2,3);
          }
          uVar6 = func_0021cca0(uVar4,2);
          uVar7 = func_0021cce0(uVar6);
          D_00960090(1,uVar7);
          func_004d7f60(3,0x717fb);
          func_004d7f60(2,0x44);
          renderQuadB = (BpcRenderQuad *)D_0096009C_abs;
          (*renderQuadB)(puVar9 + 0x84, 4,0,1,2);
          (*renderQuadB)(puVar9 + 0x84, 4,0,2,3);
          uVar8 = puVar1[1];
          if (uVar8 == 2) {
            uVar6 = func_0021cca0(uVar3,0x37);
          }
          else if ((uVar8 == 1) || (uVar8 == 0)) {
            uVar6 = func_0021cca0(uVar4,4);
          }
          uVar7 = func_0021cce0(uVar6);
          D_00960090(1,uVar7);
          func_004d7f60(3,0x71801);
          func_004d7f60(2,0x48);
          renderQuadC = (BpcRenderQuad *)D_0096009C_abs;
          (*renderQuadC)(puVar9 + 0x44, 4,0,1,2);
          (*renderQuadC)(puVar9 + 0x44, 4,0,2,3);
          if (puVar1[1] == 2) {
            uVar7 = func_0021cca0(uVar4,8);
            uVar7 = func_0021cce0(uVar7);
            D_00960090(1,uVar7);
            func_004d7f60(3,0x71801);
            func_004d7f60(2,0x48);
            renderQuadDEF = (BpcRenderQuad *)D_0096009C_abs;
            (*renderQuadDEF)(puVar9 + 0x248, 4,0,1,2);
            (*renderQuadDEF)(puVar9 + 0x248, 4,0,2,3);
          }
          uVar7 = func_0021cca0(uVar4,3);
          uVar7 = func_0021cce0(uVar7);
          D_00960090(1,uVar7);
          func_004d7f60(3,0x717fb);
          func_004d7f60(2,0x44);
          (*renderQuadDEF)(puVar9 + 4, 4,0,1,2);
          (*renderQuadDEF)(puVar9 + 4, 4,0,2,3);
          if ((*puVar9 & 2) != 0) {
            uVar7 = func_0021cca0(uVar4,0x45);
            uVar7 = func_0021cce0(uVar7);
            D_00960090(1,uVar7);
            func_004d7f60(3,0x717fb);
            func_004d7f60(2,0x44);
            (*renderQuadDEF)(puVar9 + 0x184, 4,0,1,2);
            (*renderQuadDEF)(puVar9 + 0x184, 4,0,2,3);
          }
          uVar8 = puVar1[1];
          if (uVar8 == 2) {
            uVar7 = func_0021cca0(uVar3,0x3d);
            uVar7 = func_0021cce0(uVar7);
            D_00960090(1,uVar7);
            func_004d7f60(3,0x717fb);
            func_004d7f60(2,0x44);
            renderQuadGH = (BpcRenderQuad *)D_0096009C_abs;
            (*renderQuadGH)(puVar9 + 0x208, 4,0,1,2);
            (*renderQuadGH)(puVar9 + 0x208, 4,0,2,3);
            uVar7 = func_0021cca0(uVar3,0x39);
            uVar7 = func_0021cce0(uVar7);
            D_00960090(1,uVar7);
            func_004d7f60(3,0x717fb);
            func_004d7f60(2,0x44);
            (*renderQuadGH)(puVar9 + 0x1c8, 4,0,1,2);
            (*renderQuadGH)(puVar9 + 0x1c8, 4,0,2,3);
          }
          else if ((uVar8 == 1) || (uVar8 == 0)) {
            uVar7 = func_0021cca0(uVar4,1);
            uVar7 = func_0021cce0(uVar7);
            D_00960090(1,uVar7);
            func_004d7f60(3,0x717fb);
            func_004d7f60(2,0x44);
            renderQuadIJ = (BpcRenderQuad *)D_0096009C_abs;
            (*renderQuadIJ)(puVar9 + 0x104, 4,0,1,2);
            (*renderQuadIJ)(puVar9 + 0x104, 4,0,2,3);
            uVar7 = func_0021cca0(uVar2,4);
            uVar7 = func_0021cce0(uVar7);
            D_00960090(1,uVar7);
            func_004d7f60(3,0x717fb);
            func_004d7f60(2,0x44);
            (*renderQuadIJ)(puVar9 + 0xc4, 4,0,1,2);
            (*renderQuadIJ)(puVar9 + 0xc4, 4,0,2,3);
          }
        }
LAB_00243a18:
    ;
    }
    if (((*puVar1 & 2) != 0) && ((~*puVar1 & 0x80) != 0)) {
      uVar3 = func_0021cca0(uVar4,0);
      uVar3 = func_0021cce0(uVar3);
      D_00960090(1,uVar3);
      func_004d7f60(3,0x717fb);
      func_004d7f60(2,0x44);
      renderQuadKP = (BpcRenderQuad *)D_0096009C_abs;
      (*renderQuadKP)(puVar1 + 0x1a70, 4,0,1,2);
      (*renderQuadKP)(puVar1 + 0x1a70, 4,0,2,3);
      uVar3 = func_0021cca0(uVar4,0x43);
      uVar3 = func_0021cce0(uVar3);
      D_00960090(1,uVar3);
      func_004d7f60(3,0x717fb);
      func_004d7f60(2,0x44);
      (*renderQuadKP)(puVar1 + 0x19b0, 4,0,1,2);
      (*renderQuadKP)(puVar1 + 0x19b0, 4,0,2,3);
      (*renderQuadKP)(puVar1 + 0x19f0, 4,0,1,2);
      (*renderQuadKP)(puVar1 + 0x19f0, 4,0,2,3);
      (*renderQuadKP)(puVar1 + 0x1a30, 4,0,1,2);
      (*renderQuadKP)(puVar1 + 0x1a30, 4,0,2,3);
      func_003b1360(puVar1[0x1b30],1,0);
      uVar7 = func_0021cca0(uVar4,0x42);
      uVar3 = func_0021cce0(uVar7);
      D_00960090(1,uVar3);
      func_004d7f60(3,0x717fb);
      func_004d7f60(2,0x44);
      (*renderQuadKP)(puVar1 + 0x1ab0, 4,0,1,2);
      (*renderQuadKP)(puVar1 + 0x1ab0, 4,0,2,3);
      (*renderQuadKP)(puVar1 + 0x1af0, 4,0,1,2);
      (*renderQuadKP)(puVar1 + 0x1af0, 4,0,2,3);
      if ((*puVar1 & 4) != 0) {
        uVar8 = puVar1[0x1b31];
        if (uVar8 == 0) {
          uVar7 = func_0021cca0(uVar4,0x3c);
        }
        else if ((uVar8 == 2) || (uVar8 == 1)) {
          uVar7 = func_0021cca0(uVar4,0x3b);
        }
        uVar3 = func_0021cce0(uVar7);
        D_00960090(1,uVar3);
        func_004d7f60(3,0x717fb);
        func_004d7f60(2,0x44);
        renderQuadQ = (BpcRenderQuad *)D_0096009C_abs;
        (*renderQuadQ)(puVar1 + 0x1b34, 4,0,1,2);
        (*renderQuadQ)(puVar1 + 0x1b34, 4,0,2,3);
        uVar8 = puVar1[0x1b32];
        if (uVar8 == 0) {
          uVar7 = func_0021cca0(uVar4,0x3e);
        }
        else if ((uVar8 == 2) || (uVar8 == 1)) {
          uVar7 = func_0021cca0(uVar4,0x3d);
        }
        uVar3 = func_0021cce0(uVar7);
        D_00960090(1,uVar3);
        func_004d7f60(3,0x717fb);
        func_004d7f60(2,0x44);
        renderQuadR = (BpcRenderQuad *)D_0096009C_abs;
        (*renderQuadR)(puVar1 + 0x1b74, 4,0,1,2);
        (*renderQuadR)(puVar1 + 0x1b74, 4,0,2,3);
        uVar8 = puVar1[0x1b33];
        if (uVar8 == 0) {
          uVar7 = func_0021cca0(uVar4,0x40);
        }
        else if ((uVar8 == 2) || (uVar8 == 1)) {
          uVar7 = func_0021cca0(uVar4,0x3f);
        }
        uVar3 = func_0021cce0(uVar7);
        D_00960090(1,uVar3);
        func_004d7f60(3,0x717fb);
        func_004d7f60(2,0x44);
        renderQuadS = (BpcRenderQuad *)D_0096009C_abs;
        (*renderQuadS)(puVar1 + 0x1bb4, 4,0,1,2);
        (*renderQuadS)(puVar1 + 0x1bb4, 4,0,2,3);
        iVar10 = 0;
        goto LAB_002440e0;
LAB_00243fc4:
        uVar8 = puVar1[iVar10 + 0x1b31];
        switch (uVar8) {
        case 1:
          uVar7 = func_0021cca0(uVar5,0x11);
          break;
        case 2:
          uVar7 = func_0021cca0(uVar5,0x12);
          break;
        case 0:
          uVar7 = func_0021cca0(uVar4,0x41);
          break;
        }
        uVar3 = func_0021cce0(uVar7);
        D_00960090(1,uVar3);
        func_004d7f60(3,0x717fb);
        func_004d7f60(2,0x44);
          renderQuadT = (BpcRenderQuad *)D_0096009C_abs;
        (*renderQuadT)(puVar1 + iVar10 * 0x40 + 0x1bf4, 4,0,1,2);
        (*renderQuadT)(puVar1 + iVar10 * 0x40 + 0x1bf4, 4,0,2,3);
LAB_002440e0:
        iVar10 = iVar10 + 1;
        if (iVar10 < 3) goto LAB_00243fc4;
      }
    }
  }
#undef D_00960090
#undef D_0096009C
  return;
}



// FUN_00244120
void FUN_00244120(u32 param_1)
{
  uint *puVar1;

  if (sBpcWork == 0) {
    K_Assert(D_0068E880, 0x97);
  }
  puVar1 = sBpcWork;
  if ((int)puVar1[2] >= 10) {
    K_Assert(D_0068E880, 0x251);
  }
  puVar1[puVar1[2] + 4] = param_1;
  puVar1[2] = puVar1[2] + 1;
  return;
}



// FUN_002441B0 NONMATCHING
void FUN_002441b0(u32 param_1)

{
  ushort uVar1;
  int unaff_s1_lo;
  short sVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  u32 uVar9;
  long lVar8;
  register u32 uVar7;
  uint *puVar2;
  int iVar10;
  const char *message;
  
  if (sBpcWork == (uint *)0x0) {
    K_Assert(D_0068E880, 0x97);
  }
  puVar2 = sBpcWork;
  func_0021c3f0(2);
  uVar7 = func_0021c3f0(1);
  func_0021c3f0(5);
  if ((~*puVar2 & 2) == 0) {
    K_Assert(D_0068E880, 0x269);
  }
  if ((int)puVar2[2] < 1) {
    K_Assert(D_0068E880, 0x26a);
  }
  message = DAT_007cc468;
  printf(message, param_1);
  uVar5 = *puVar2;
  uVar5 = uVar5 & 0xfffffffb;
  *puVar2 = uVar5;
  uVar5 = uVar5 & 0xfffffff3;
  *puVar2 = uVar5;
  uVar5 = uVar5 & 0xffffffe3;
  *puVar2 = uVar5;
  uVar5 = uVar5 & 0xffffffc3;
  *puVar2 = uVar5;
  uVar5 = uVar5 & 0xffffffc1;
  *puVar2 = uVar5;
  uVar5 = uVar5 & 0xfffffec1;
  *puVar2 = uVar5;
  if (puVar2[2] == 1) {
    *puVar2 = *puVar2 | 2;
  }
  if (((short)puVar2[0x1cb4] == 0x14f) || ((short)puVar2[0x1cb4] == 0x144)) {
    puVar2[1] = 2;
  }
  else {
    puVar2[1] = (uint)param_1;
  }
  lVar8 = bpMisc001ff740();
  if (lVar8 == 1) {
    uVar9 = func_00174800(6);
    iVar4 = func_00173370(uVar9);
    iVar6 = func_00176a30(uVar9);
    for (iVar10 = 0; (iVar10 < iVar6 && (*(short *)(iVar4 + iVar10 * 2) != 0x14f));
        iVar10 = iVar10 + 1) {
    }
    if (iVar10 < iVar6) {
      *puVar2 = *puVar2 | 4;
    }
    for (iVar10 = 0; (iVar10 < iVar6 && (*(short *)(iVar4 + iVar10 * 2) != 0x150));
        iVar10 = iVar10 + 1) {
    }
    if (iVar10 < iVar6) {
      *puVar2 = *puVar2 | 8;
    }
  }
  if ((*puVar2 & 2) != 0) {
    iVar4 = func_001ff430(puVar2[4]);
    if ((*puVar2 & 4) != 0) {
      FUN_00244e80();
    }
    if (*(char *)(iVar4 + 0xa2) == '\x01') {
      uVar1 = *(ushort *)(*(int *)(iVar4 + 0xa2c) + 2);
      unaff_s1_lo = DAT_007ce4e8 + (uint)uVar1 * 0x12 + (uint)uVar1;
    }
    else if (*(char *)(iVar4 + 0xa2) == '\0') {
      unaff_s1_lo = func_001775a0(*(u16 *)(*(int *)(iVar4 + 0xa2c) + 2));
    }
    func_003b0e70(1);
    func_003b0e90(2);
    uVar5 = func_003b0970(unaff_s1_lo,2,6,0,0);
    puVar2[0x1b30] = uVar5;
    func_003b0e90(1);
    func_003b0e70(2);
    uVar9 = func_0021cca0(uVar7,0x43);
    func_0021d3b0(puVar2 + 0x19b0,uVar9);
    func_0021e380(puVar2 + 0x19f0,uVar9,1);
    uVar9 = func_0021cca0(uVar7,0x44);
    func_0021d3b0(puVar2 + 0x1a30,uVar9);
    uVar9 = func_0021cca0(uVar7,0);
    func_0021d3b0(puVar2 + 0x1a70,uVar9);
    uVar7 = func_0021cca0(uVar7,0x42);
    func_0021d3b0(puVar2 + 0x1ab0,uVar7);
    func_0021d3b0(puVar2 + 0x1af0,uVar7);
  }
  for (iVar4 = 0; iVar4 < (int)puVar2[2]; iVar4 = iVar4 + 1) {
    iVar6 = func_001ff430(puVar2[iVar4 + 4]);
    if (*(char *)(iVar6 + 0xa2) == '\0') {
      bppMain0020f7d0(*(u16 *)(*(int *)(iVar6 + 0xa2c) + 2));
    }
  }
  if (((*puVar2 & 2) != 0) && (iVar4 = func_001ff430(puVar2[4]), *(char *)(iVar4 + 0xa2) == '\0')) {
    iVar6 = bpMisc001ff5b0();
    for (iVar10 = 0; iVar10 < iVar6; iVar10 = iVar10 + 1) {
      sVar3 = func_001ff630(iVar10);
      if (sVar3 != *(short *)(*(int *)(iVar4 + 0xa2c) + 2)) {
        bppMain0020fa80(0);
      }
    }
  }
  FUN_00245a00();
  uVar5 = puVar2[1];
  if (uVar5 == 2) {
    for (iVar4 = 0; iVar4 < (int)puVar2[3]; iVar4 = iVar4 + 1) {
      if ((puVar2[iVar4 * 0x290 + 0x12] == puVar2[4]) ||
         ((puVar2[iVar4 * 0x290 + 0x10] & 0x80) != 0)) {
        FUN_00245910(puVar2 + iVar4 * 0x290 + 0x10);
      }
    }
  }
  else if ((uVar5 == 1) || (uVar5 == 0)) {
    for (iVar4 = 0; iVar4 < (int)puVar2[2]; iVar4 = iVar4 + 1) {
      FUN_00245910(FUN_00245bf0(puVar2[iVar4 + 4]));
    }
  }
  *puVar2 = *puVar2 | 1;
  return;
}



// FUN_00244770 NONMATCHING
void FUN_00244770(void)
{
  uint uVar1;
  uint *puVar2;
  u16 sVar3;
  u32 iVar4;
  int iVar5;
  u32 uVar6;
  u32 iVar7;

  if (sBpcWork == (uint *)0x0) {
    K_Assert(D_0068E880, 0x97);
  }
  puVar2 = sBpcWork;
  if ((*sBpcWork & 2) != 0) {
    func_003b0170(sBpcWork[0x1b30]);
  }
  for (iVar4 = 0; (int)iVar4 < (int)puVar2[2]; iVar4 = iVar4 + 1) {
    iVar5 = func_001ff430(*(puVar2 + iVar4 + 4));
    switch (*(u8 *)(iVar5 + 0xa2)) {
    case 0:
      bppMain0020f8b0_u16(*(u16 *)(*(int *)(iVar5 + 0xa2c) + 2));
      break;
    }
  }
  if ((*puVar2 & 2) != 0) {
    iVar4 = func_001ff430(puVar2[4]);
    switch (*(u8 *)(iVar4 + 0xa2)) {
    case 0:
      iVar5 = bpMisc001ff5b0();
      for (iVar7 = 0; (int)iVar7 < iVar5; iVar7 = iVar7 + 1) {
        sVar3 = (u16)func_001ff630(iVar7);
        if (sVar3 != *(u16 *)(*(int *)(iVar4 + 0xa2c) + 2)) {
          bppMain0020fb60_u16(0);
        }
      }
      break;
    }
  }
  uVar1 = puVar2[1];
  if (uVar1 == 2) {
    for (iVar4 = 0; iVar4 < (int)puVar2[2]; iVar4 = iVar4 + 1) {
      FUN_00245970(puVar2 + iVar4 * 0x290 + 0x10);
      if ((puVar2[iVar4 * 0x290 + 0x10] & 0x480) == 0) {
        puVar2[iVar4 * 0x290 + 0x10] = puVar2[iVar4 * 0x290 + 0x10] & 0xffffffdf;
      }
    }
  }
  else if ((uVar1 == 1) || (uVar1 == 0)) {
    for (iVar4 = 0; iVar4 < (int)puVar2[2]; iVar4 = iVar4 + 1) {
      FUN_00245970(FUN_00245bf0(puVar2[iVar4 + 4]));
    }
  }
  uVar1 = *puVar2;
  *puVar2 = uVar1 & 0xfffffffe;
  *puVar2 = uVar1 & 0xfffffffd;
  puVar2[2] = 0;
  *puVar2 = *puVar2 | 0x20;
  return;
}



// FUN_002449D0
void FUN_002449d0(void)
{
    printf("");
    FUN_00244770();
}



// FUN_00244A00
void FUN_00244a00(void)

{
  func_0010a4e0(0,0,0,2);
  FUN_00244770();
  return;
}



// FUN_00244A40 NONMATCHING
void FUN_00244a40(u32 param_1)

{
  ushort uVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar5;
  u32 uVar6;
  u32 lVar7;
  int unaff_s2_lo;
  u8 auStack_10[32];
  
  if (sBpcWork == (uint *)0x0) {
    K_Assert(D_0068E880, 0x97);
  }
  puVar2 = sBpcWork;
  if ((*sBpcWork & 2) == 0) {
    K_Assert(D_0068E880, 0x371);
  }
  iVar3 = func_001ff430(puVar2[4]);
  switch (*(u8 *)(iVar3 + 0xa2)) {
  case 1:
    break;
  case 0:
    bppMain0020f8b0_u16(*(u16 *)(*(int *)(iVar3 + 0xa2c) + 2));
    bppMain0020fa80_u16(*(u16 *)(*(int *)(iVar3 + 0xa2c) + 2));
    iVar3 = func_001ff430(param_1);
    if (*(u8 *)(iVar3 + 0xa2) != 0) {
      K_Assert(D_0068E880, 0x37b);
    }
    bppMain0020fb60_u16(*(u16 *)(*(int *)(iVar3 + 0xa2c) + 2));
    bppMain0020f7d0_u16(*(u16 *)(*(int *)(iVar3 + 0xa2c) + 2));
    break;
  }
  uVar5 = puVar2[1];
  if (uVar5 == 2) {
    puVar5 = FUN_00245bf0(puVar2[4]);
    if ((*puVar5 & 0x80) == 0) {
      FUN_00245970(puVar5);
    }
  }
  else if ((uVar5 == 1) || (uVar5 == 0)) {
    puVar5 = FUN_00245bf0(puVar2[4]);
    FUN_00245970(puVar5);
  }
  uVar6 = func_001ff430(puVar2[4]);
  func_00280580(uVar6,auStack_10 + 0x10);
  lVar7 = func_002d20a0(auStack_10 + 0x10,(f32 *)(auStack_10 + 8));
  if (lVar7 != 0) {
    puVar2[0x1cb7] = *(u32 *)(auStack_10 + 8);
    puVar2[0x1cb8] = *(u32 *)(auStack_10 + 0xc);
    *puVar2 = *puVar2 | 0x10;
  }
  if ((*puVar2 & 2) != 0) {
    puVar4 = (uint *)FUN_00245bf0(puVar2[4]);
    *puVar4 = *puVar4 & 0xfffffbff;
  }
  puVar2[4] = (uint)param_1;
  if ((*puVar2 & 2) != 0) {
    puVar4 = (uint *)FUN_00245bf0(puVar2[4]);
    *puVar4 = *puVar4 | 0x400;
  }
  uVar5 = puVar2[1];
  if (uVar5 == 2) {
    FUN_00245cd0();
    puVar5 = FUN_00245bf0(puVar2[4]);
    if ((*puVar5 & 0x80) == 0) {
      FUN_00245910(puVar5);
    }
    else {
      FUN_002459d0(puVar5);
    }
  }
  else if ((uVar5 == 1) || (uVar5 == 0)) {
    puVar5 = FUN_00245bf0(puVar2[4]);
    FUN_00245910(puVar5);
  }
  if ((*puVar2 & 4) != 0) {
    FUN_00244e80();
  }
  func_003b0170(puVar2[0x1b30]);
  iVar3 = func_001ff430(puVar2[4]);
  if (*(u8 *)(iVar3 + 0xa2) == 1) {
    uVar1 = *(ushort *)(*(int *)(iVar3 + 0xa2c) + 2);
    unaff_s2_lo = DAT_007ce4e8 + (uint)uVar1 * 0x12 + (uint)uVar1;
  }
  else if (*(u8 *)(iVar3 + 0xa2) == 0) {
    unaff_s2_lo = func_001775a0_s16(*(s16 *)(*(int *)(iVar3 + 0xa2c) + 2));
  }
  func_003b0e70(1);
  func_003b0e90(2);
  uVar5 = func_003b0970(unaff_s2_lo,2,6,0,0);
  puVar2[0x1b30] = uVar5;
  func_003b0e90(1);
  func_003b0e70(2);
  func_0010a4e0(0,0,0,0);
  return;
}



// FUN_00244E10
uint FUN_00244e10(void)

{
  uint *puVar1;
  
  if (sBpcWork == (uint *)0x0) {
    K_Assert(D_0068E880, 0x97);
  }
  puVar1 = sBpcWork;
  if ((*sBpcWork & 2) == 0) {
    K_Assert(D_0068E880, 0x3e1);
  }
  return puVar1[4];
}



// FUN_00244E80 NONMATCHING
void FUN_00244e80(void)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  u32 uVar4;
  u32 uVar5;
  long lVar6;
  u32 uVar7;
  
  if (sBpcWork == (uint *)0x0) {
    K_Assert(D_0068E880, 0x97);
  }
  puVar2 = sBpcWork;
  uVar4 = func_0021c3f0(1);
  uVar5 = func_0021c3f0(3);
  iVar3 = func_001ff430(puVar2[4]);
  if ((*puVar2 & 2) == 0) {
    K_Assert(D_0068E880, 0x3f0);
  }
  if (puVar2[2] != 1) {
    K_Assert(D_0068E880, 0x3f1);
  }
  lVar6 = func_00301ca0(*(u32 *)(iVar3 + 0xa2c),5);
  if (lVar6 == 0) {
    lVar6 = func_00301ca0(*(u32 *)(iVar3 + 0xa2c),10);
    if (lVar6 == 0) {
      puVar2[0x1b31] = 0;
    }
    else {
      puVar2[0x1b31] = 2;
    }
  }
  else {
    lVar6 = func_00301ca0(*(u32 *)(iVar3 + 0xa2c),10);
    if (lVar6 != 0) {
      K_Assert(D_0068E880, 0x3f6);
    }
    puVar2[0x1b31] = 1;
  }
  lVar6 = func_00301ca0(*(u32 *)(iVar3 + 0xa2c),0x40);
  if (lVar6 == 0) {
    lVar6 = func_00301ca0(*(u32 *)(iVar3 + 0xa2c),0x80);
    if (lVar6 == 0) {
      puVar2[0x1b32] = 0;
    }
    else {
      puVar2[0x1b32] = 2;
    }
  }
  else {
    lVar6 = func_00301ca0(*(u32 *)(iVar3 + 0xa2c),0x80);
    if (lVar6 != 0) {
      K_Assert(D_0068E880, 0x405);
    }
    puVar2[0x1b32] = 1;
  }
  lVar6 = func_00301ca0(*(u32 *)(iVar3 + 0xa2c),0x210);
  if (lVar6 == 0) {
    lVar6 = func_00301ca0(*(u32 *)(iVar3 + 0xa2c),0x120);
    if (lVar6 == 0) {
      puVar2[0x1b33] = 0;
    }
    else {
      puVar2[0x1b33] = 2;
    }
  }
  else {
    lVar6 = func_00301ca0(*(u32 *)(iVar3 + 0xa2c),0x120);
    if (lVar6 != 0) {
      K_Assert(D_0068E880, 0x414);
    }
    puVar2[0x1b33] = 1;
  }
  uVar1 = puVar2[0x1b31];
  if (uVar1 == 0) {
    uVar7 = func_0021cca0(uVar4,0x3c);
    func_0021d3b0(puVar2 + 0x1b34,uVar7);
    uVar7 = func_0021cca0(uVar4,0x41);
    func_0021d3b0(puVar2 + 0x1bf4,uVar7);
  }
  else if (uVar1 == 2) {
    uVar7 = func_0021cca0(uVar4,0x3b);
    func_0021d3b0(puVar2 + 0x1b34,uVar7);
    uVar7 = func_0021cca0(uVar5,0x12);
    func_0021d3b0(puVar2 + 0x1bf4,uVar7);
  }
  else if (uVar1 == 1) {
    uVar7 = func_0021cca0(uVar4,0x3b);
    func_0021d3b0(puVar2 + 0x1b34,uVar7);
    uVar7 = func_0021cca0(uVar5,0x11);
    func_0021d3b0(puVar2 + 0x1bf4,uVar7);
  }
  uVar1 = puVar2[0x1b32];
  if (uVar1 == 0) {
    uVar7 = func_0021cca0(uVar4,0x3e);
    func_0021d3b0(puVar2 + 0x1b74,uVar7);
    uVar7 = func_0021cca0(uVar4,0x41);
    func_0021d3b0(puVar2 + 0x1c34,uVar7);
  }
  else if (uVar1 == 2) {
    uVar7 = func_0021cca0(uVar4,0x3d);
    func_0021d3b0(puVar2 + 0x1b74,uVar7);
    uVar7 = func_0021cca0(uVar5,0x12);
    func_0021d3b0(puVar2 + 0x1c34,uVar7);
  }
  else if (uVar1 == 1) {
    uVar7 = func_0021cca0(uVar4,0x3d);
    func_0021d3b0(puVar2 + 0x1b74,uVar7);
    uVar7 = func_0021cca0(uVar5,0x11);
    func_0021d3b0(puVar2 + 0x1c34,uVar7);
  }
  uVar1 = puVar2[0x1b33];
  if (uVar1 == 0) {
    uVar5 = func_0021cca0(uVar4,0x40);
    func_0021d3b0(puVar2 + 0x1bb4,uVar5);
    uVar4 = func_0021cca0(uVar4,0x41);
    func_0021d3b0(puVar2 + 0x1c74,uVar4);
  }
  else if (uVar1 == 2) {
    uVar4 = func_0021cca0(uVar4,0x3f);
    func_0021d3b0(puVar2 + 0x1bb4,uVar4);
    uVar4 = func_0021cca0(uVar5,0x12);
    func_0021d3b0(puVar2 + 0x1c74,uVar4);
  }
  else if (uVar1 == 1) {
    uVar4 = func_0021cca0(uVar4,0x3f);
    func_0021d3b0(puVar2 + 0x1bb4,uVar4);
    uVar4 = func_0021cca0(uVar5,0x11);
    func_0021d3b0(puVar2 + 0x1c74,uVar4);
  }
  return;
}



// FUN_002453D0
void FUN_002453d0(u16 param_1)
{
  if (sBpcWork == 0) {
    K_Assert(D_0068E880, 0x97);
  }
  *(u16 *)((u8 *)sBpcWork + 0x72d0) = param_1;
  return;
}



// FUN_00245420 NONMATCHING
void FUN_00245420(uint *param_1,uint param_2)

{
  uint *puVar1;
  u16 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  long lVar10;
  ulong uVar11;
  u8 auStack_10 [16];
  
  if (sBpcWork == (uint *)0x0) {
    K_Assert(D_0068E880, 0x97);
  }
  puVar1 = sBpcWork;
  uVar6 = func_0021c3f0(2);
  uVar7 = func_0021c3f0(1);
  uVar8 = func_0021c3f0(5);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = param_2;
  uVar9 = func_001ff430(param_2);
  iVar3 = (int)uVar9;
  uVar4 = datCalcGetHp(*(u32 *)(iVar3 + 0xa2c));
  param_1[0x28c] = uVar4 & 0xffff;
  uVar4 = datCalcGetMaxHp(*(u32 *)(iVar3 + 0xa2c));
  param_1[0x28d] = uVar4 & 0xffff;
  func_00280580(uVar9,auStack_10);
  lVar10 = func_002d20a0(auStack_10,param_1 + 0x28e);
  if (lVar10 == 0) {
    *param_1 = *param_1 | 0x40;
  }
  param_1[0x28f] = (uint)((float)param_1[0x28f] + 20.0);
  if (((*puVar1 & 2) != 0) && (param_1[2] == puVar1[4])) {
    *param_1 = *param_1 | 0x400;
  }
  uVar4 = puVar1[1];
  if (uVar4 == 2) {
    lVar10 = func_0017b260(*(u16 *)(*(int *)(iVar3 + 0xa2c) + 2));
    if (lVar10 == 0) {
      *param_1 = *param_1 | 0x80;
    }
    for (iVar5 = 0; iVar5 < 3; iVar5 = iVar5 + 1) {
      param_1[iVar5 + 0x289] = 0;
    }
    if ((*param_1 & 0x80) != 0) {
      iVar5 = func_001ff430(puVar1[4]);
      if (param_2 == *(uint *)(iVar5 + 0xa8)) {
        param_1[0x288] = 0;
      }
      else if (*(short *)(*(int *)(iVar3 + 0xa2c) + 2) == *(short *)(*(int *)(iVar5 + 0xa2c) + 2)) {
        param_1[0x288] = 1;
      }
      else {
        param_1[0x288] = 2;
      }
      param_1[param_1[0x288] + 0x289] = 10;
    }
  }
  else if ((uVar4 != 1) && (uVar4 == 0)) {
    lVar10 = func_00300e90(*(u32 *)(iVar3 + 0xa2c),(short)puVar1[0x1cb4]);
    if (lVar10 != 0) {
      *param_1 = *param_1 | 1;
    }
    if (((*puVar1 & 8) != 0) &&
       (((**(ushort **)(iVar3 + 0xa2c) & 4) == 0 ||
        ((*(ushort *)((uint)(*(ushort **)(iVar3 + 0xa2c))[1] * 0x3e + DAT_007ce410 + 0x1e) & 0x20)
         == 0)))) {
      uVar2 = func_003082f0(0,(short)puVar1[0x1cb4]);
      uVar11 = func_00306e80(*(u32 *)(iVar3 + 0xa2c),uVar2);
      lVar10 = func_0017b260(*(u16 *)(*(int *)(iVar3 + 0xa2c) + 2));
      if ((lVar10 != 0) &&
         ((((uVar11 & 0x1000000) != 0 || ((uVar11 & 0x2000000) != 0)) || ((uVar11 & 0x4000000) != 0)
          ))) {
        *param_1 = *param_1 | 2;
      }
    }
  }
  uVar9 = func_0021cca0(uVar7,3);
  func_0021d3b0(param_1 + 4,uVar9);
  uVar9 = func_0021cca0(uVar7,2);
  func_0021d3b0(param_1 + 0x84,uVar9);
  uVar9 = func_0021cca0(uVar7,0x2c);
  func_0021d3b0(param_1 + 0x144,uVar9);
  uVar9 = func_0021cca0(uVar7,0x45);
  func_0021d3b0(param_1 + 0x184,uVar9);
  uVar9 = func_0021cca0(uVar7,1);
  func_0021d3b0(param_1 + 0x104,uVar9);
  uVar8 = func_0021cca0(uVar8,4);
  func_0021d3b0(param_1 + 0xc4,uVar8);
  uVar4 = puVar1[1];
  if (uVar4 == 2) {
    uVar8 = func_0021cca0(uVar6,0x37);
    func_0021d3b0(param_1 + 0x44,uVar8);
    if ((*param_1 & 0x80) != 0) {
      uVar8 = func_0021cca0(uVar6,0x39);
      func_0021d3b0(param_1 + 0x1c8,uVar8);
    }
    uVar7 = func_0021cca0(uVar7,8);
    func_0021d3b0(param_1 + 0x248,uVar7);
    uVar6 = func_0021cca0(uVar6,0x3d);
    func_0021d3b0(param_1 + 0x208,uVar6);
  }
  else if ((uVar4 == 1) || (uVar4 == 0)) {
    uVar6 = func_0021cca0(uVar7,4);
    func_0021d3b0(param_1 + 0x44,uVar6);
  }
  return;
}



// FUN_00245910
void FUN_00245910(uint *param_1)
{
  if ((*param_1 & 0x20) != 0) {
    param_1[0x1c4] = 10 - param_1[0x1c4];
    *param_1 = *param_1 & 0xffffffdf;
    *param_1 = *param_1 & 0xfffffdff;
  }
  else {
    param_1[0x1c4] = 0;
  }
  *param_1 = *param_1 | 0x10;
  return;
}


// FUN_00245970
void FUN_00245970(uint *param_1)
{
  if ((*param_1 & 0x10) != 0) {
    param_1[0x1c4] = 10 - param_1[0x1c4];
    *param_1 = *param_1 & 0xffffffef;
    *param_1 = *param_1 & 0xfffffdff;
  }
  else {
    param_1[0x1c4] = 0;
  }
  *param_1 = *param_1 | 0x20;
  return;
}


// FUN_002459D0
void FUN_002459d0(uint *param_1)
{
  param_1[0x1c4] = 0;
  *param_1 = *param_1 & 0xffffffef;
  *param_1 = *param_1 & 0xffffffdf;
  *param_1 = *param_1 | 0x200;
  return;
}



// FUN_00245A00
void FUN_00245a00(void)
{
  u32 *work;
  Battle *battle;
  u8 *unit;
  u8 *unit2;
  u8 *found;
  int count;
  int mode;

  if (sBpcWork == 0) {
    K_Assert(D_0068E880, 0x97);
  }
  work = sBpcWork;
  battle = gBtl;
  if (battle == 0) {
    K_Assert(D_0068E880, 0x519);
  }
  count = 0;
  mode = (int)work[1];
  switch (mode) {
  case 0:
  case 1:
    for (unit = (u8 *)battle->unitLists[0].head; unit != 0;
         unit = *(u8 **)(unit + 0xa34)) {
      if ((~*(uint *)(unit + 0x9c) & 8) == 0) {
        FUN_00245420((uint *)((u8 *)work + count * 0xa40 + 0x40),
                     *(u32 *)(unit + 0xa8));
        count = count + 1;
      }
    }
    for (unit2 = (u8 *)battle->unitLists[1].head; unit2 != 0;
         unit2 = *(u8 **)(unit2 + 0xa34)) {
      if ((~*(uint *)(unit2 + 0x9c) & 8) == 0) {
        FUN_00245420((uint *)((u8 *)work + count * 0xa40 + 0x40),
                     *(u32 *)(unit2 + 0xa8));
        count = count + 1;
      }
    }
    break;
  case 2:
    for (unit2 = (u8 *)battle->unitLists[1].head; unit2 != 0;
         unit2 = *(u8 **)(unit2 + 0xa34)) {
      if (((~*(uint *)(unit2 + 0x9c) & 8) == 0) &&
          (found = (u8 *)func_0029a1d0((int)unit2), found != 0) &&
          ((*(ushort *)(found + 0x1a) & 8) != 0)) {
        FUN_00245420((uint *)((u8 *)work + count * 0xa40 + 0x40),
                     *(u32 *)(unit2 + 0xa8));
        count = count + 1;
      }
    }
    break;
  }
  work[3] = count;
  return;
}



// FUN_00245BF0
uint *FUN_00245bf0(int param_1)
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  if (sBpcWork == 0) {
    K_Assert(D_0068E880, 0x97);
  }
  puVar1 = sBpcWork;
  iVar2 = 0;
  iVar3 = (int)puVar1[3];
  for (; iVar2 < iVar3; iVar2 = iVar2 + 1) {
    iVar4 = *(int *)((u8 *)puVar1 + iVar2 * 0xa40 + 0x48);
    if (iVar4 == param_1) {
      break;
    }
  }
  if (iVar2 >= (int)puVar1[3]) {
    K_Assert(D_0068E880, 0x55f);
  }
  return (uint *)((u8 *)puVar1 + iVar2 * 0xa40 + 0x40);
}



// FUN_00245CD0
void FUN_00245cd0(void)

{
  uint sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  u32 *puVar5;
  
  if (sBpcWork == 0) {
    K_Assert(D_0068E880, 0x97);
  }
  iVar2 = (int)sBpcWork;
  func_0021c3f0(2);
  func_0021c3f0(1);
  iVar3 = func_001ff430(*(u32 *)(iVar2 + 0x10));
  sVar1 = *(ushort *)(*(int *)(iVar3 + 0xa2c) + 2);
  for (iVar3 = 0; iVar3 < *(int *)(iVar2 + 0xc); iVar3 = iVar3 + 1) {
    puVar5 = (u32 *)((u8 *)iVar2 + iVar3 * 0xa40 + 0x40);
    if ((~*puVar5 & 0x80) == 0) {
      iVar4 = func_001ff430(puVar5[2]);
      if (*(int *)(iVar4 + 0xa8) == *(int *)(iVar2 + 0x10)) {
        puVar5[0x288] = 0;
      }
      else if (*(ushort *)(*(int *)(iVar4 + 0xa2c) + 2) == sVar1) {
        puVar5[0x288] = 1;
      }
      else {
        puVar5[0x288] = 2;
      }
    }
  }
  return;
}



// FUN_00245E00
void FUN_00245e00(void)

{
  if (sBpcWork == (uint *)0x0) {
    K_Assert(D_0068E880, 0x97);
  }
  *sBpcWork = *sBpcWork | 0x80;
  return;
}



// FUN_00245E50
void FUN_00245e50(void)

{
  if (sBpcWork == (uint *)0x0) {
    K_Assert(D_0068E880, 0x97);
  }
  *sBpcWork = *sBpcWork & 0xffffff7f;
  return;
}



// FUN_00245EA0 NONMATCHING
void FUN_00245ea0(void)

{
  uint *puVar1;
  u32 uVar2;
  u32 uVar3;
  int iVar4;
  int iVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  float *pfVar13;
  float *pfVar14;
  float fVar15;
  float fVar16;
  float in_f21;
  float fVar17;
  float unaff_f20;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float unaff_f24;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float afStack_30 [8];
  u8 auStack_4[4];
  
  
  if (sBpcWork == (uint *)0x0) {
    K_Assert(D_0068E880, 0x97);
  }
  puVar1 = sBpcWork;
  uVar6 = func_0021c3f0(2);
  uVar7 = func_0021c3f0(1);
  uVar2 = func_0021c3f0(5);
  uVar3 = func_0021c3f0(3);
  if ((~*puVar1 & 0x100) != 0) {
    *puVar1 = *puVar1 | 0x100;
  }
  iVar5 = 0;
  while ((int)puVar1[3] > iVar5) {
    puVar11 = puVar1 + iVar5 * 0x290 + 0x10;
    fVar17 = ((float *)puVar11)[0x28e];
    fVar18 = ((float *)puVar11)[0x28f];
    uVar10 = puVar1[1];
    if (uVar10 == 2) {
      uVar10 = ~*puVar11;
      if ((((uVar10 & 0x400) == 0) || ((uVar10 & 0x20) == 0)) || ((uVar10 & 0x80) == 0))
      goto LAB_00246060;
    }
    else {
      if ((uVar10 == 1) || (uVar10 == 0)) {
        for (uVar10 = 0;
            ((int)uVar10 < (int)puVar1[2] && (puVar1[uVar10 + 4] != puVar11[2]));
            uVar10 = uVar10 + 1) {
        }
        if (((~*puVar11 & 0x20) != 0) && (uVar10 == puVar1[2])) goto LAB_00247ba8;
      }
LAB_00246060:
      iVar4 = func_0021cca0(uVar7,3);
      iVar12 = *(int *)(iVar4 + 0xc);
      if (iVar12 < 0) {
        iVar12 = iVar12 + 1;
      }
      afStack_30[0] = fVar17 - (float)(iVar12 >> 1);
      iVar12 = *(int *)(iVar4 + 0x10);
      if (iVar12 < 0) {
        iVar12 = iVar12 + 1;
      }
      afStack_30[1] = fVar18 - (float)(iVar12 >> 1);
      afStack_30[2] = afStack_30[0] + (float)*(int *)(iVar4 + 0xc);
      afStack_30[3] = afStack_30[1];
      afStack_30[4] = afStack_30[2];
      for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
        afStack_30[iVar12 * 2] = afStack_30[iVar12 * 2] - fVar17;
        afStack_30[iVar12 * 2 + 1] = afStack_30[iVar12 * 2 + 1] - fVar18;
      }
      fVar20 = 0.0f;
      fVar19 = 0.0f;
      uVar10 = puVar1[1];
      if (uVar10 == 2) {
        uVar10 = *puVar11;
        if ((uVar10 & 0x80) == 0) {
          if ((uVar10 & 0x10) == 0) {
            if ((uVar10 & 0x20) == 0) {
              fVar19 = 1.0f;
            }
            else {
              unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
              fVar19 = 1.0f - unaff_f24;
            }
          }
          else {
            unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
            fVar19 = unaff_f24;
          }
        }
        else {
          fVar19 = (float)(int)puVar11[0x289] / 10.0f;
          if ((uVar10 & 0x10) == 0) {
            if ((uVar10 & 0x20) != 0) {
              unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
              fVar19 = (1.0f - unaff_f24) * fVar19;
            }
          }
          else {
            unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
            fVar19 = unaff_f24 * fVar19;
          }
        }
        fVar20 = DAT_007caf38 * (fVar19 * 2.0f - fVar19 * fVar19 * 1.0f) * 0.5f * 2.0f;
      }
      else if ((uVar10 == 1) || (uVar10 == 0)) {
        if ((*puVar11 & 0x10) == 0) {
          if ((*puVar11 & 0x20) == 0) {
            fVar19 = 1.0f;
          }
          else {
            unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
            fVar19 = 1.0f - unaff_f24;
          }
        }
        else {
          unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
          fVar19 = unaff_f24;
        }
        fVar20 = DAT_007caf38 * (fVar19 * 2.0f - fVar19 * fVar19 * 1.0f) * 0.5f * 2.0f;
      }
      for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
        pfVar13 = afStack_30 + iVar12 * 2;
        pfVar14 = afStack_30 + iVar12 * 2 + 1;
        fVar15 = (float)sinf(fVar20);
        fVar23 = *pfVar14;
        fVar16 = (float)cosf(fVar20);
        fVar25 = *pfVar13;
        fVar21 = (float)sinf(fVar20);
        fVar24 = *pfVar13;
        fVar22 = (float)cosf(fVar20);
        fVar26 = *pfVar14;
        *pfVar13 = fVar25 * fVar16 - fVar23 * fVar15;
        *pfVar14 = fVar24 * fVar21 + fVar26 * fVar22;
      }
      for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
        afStack_30[iVar12 * 2] = afStack_30[iVar12 * 2] + fVar17;
        afStack_30[iVar12 * 2 + 1] = afStack_30[iVar12 * 2 + 1] + fVar18;
      }
      func_0021d890(puVar11 + 1,afStack_30);
      auStack_4[0] = 0xff;
      auStack_4[1] = 0xff;
      auStack_4[2] = 0xff;
      fVar20 = fVar19 * 255.0f;
      if (fVar20 < 2147483648.0f) {
        auStack_4[3] = (u8)(int)fVar20;
      }
      else {
        auStack_4[3] = (u8)(int)(fVar20 - 2147483648.0f);
      }
      func_0021d950(puVar11 + 1,&auStack_4[0]);
      uVar10 = puVar1[1];
      if (uVar10 == 2) {
        uVar10 = *puVar11;
        if ((uVar10 & 0x80) == 0) {
          uVar9 = *puVar1 & 0x10;
          in_f21 = fVar17;
          unaff_f20 = fVar18;
          if (uVar9 != 0) {
            if ((uVar10 & 0x10) == 0) {
              fVar19 = 1.0f;
            }
            else if ((*puVar1 & 0x20) == 0) {
              if ((int)puVar11[0x1c4] < 4) {
                fVar19 = (float)(int)puVar11[0x1c4] / 4.0f;
              }
              else {
                fVar19 = 1.0f;
              }
            }
            else {
              fVar19 = 1.0f;
            }
            fVar19 = fVar19 * 2.0f - fVar19 * fVar19 * 1.0f;
            in_f21 = fVar19 * (fVar17 - (float)puVar1[0x1cb7]) + (float)puVar1[0x1cb7] + 0.0f;
            unaff_f20 = fVar19 * (fVar18 - (float)puVar1[0x1cb8]) + (float)puVar1[0x1cb8] + 0.0f;
          }
          if ((uVar10 & 0x10) == 0) {
            if ((uVar10 & 0x20) == 0) {
              fVar19 = 1.0f;
            }
            else if ((uVar10 & 0x400) == 0) {
              fVar19 = 0.0f;
            }
            else {
              fVar19 = (float)(int)(10 - puVar11[0x1c4]) / 10.0f;
            }
          }
          else if (uVar9 == 0) {
            if ((int)puVar11[0x1c4] < 4) {
              fVar19 = (float)(int)puVar11[0x1c4] / 4.0f;
            }
            else {
              fVar19 = 1.0f;
            }
          }
          else {
            fVar19 = 1.0f;
          }
        }
        else {
          uVar9 = puVar11[0x288];
          if ((uVar9 == 2) || (uVar9 == 1)) {
            fVar19 = 0.0f;
            in_f21 = fVar17;
            unaff_f20 = fVar18;
          }
          else if (uVar9 == 0) {
            in_f21 = fVar17;
            unaff_f20 = fVar18;
            if ((*puVar1 & 0x10) != 0) {
              if ((uVar10 & 0x200) == 0) {
                fVar19 = 1.0f;
              }
              else {
                fVar19 = (float)(int)puVar11[0x1c4] / 4.0f;
              }
              fVar19 = fVar19 * 2.0f - fVar19 * fVar19 * 1.0f;
              in_f21 = fVar19 * (fVar17 - (float)puVar1[0x1cb7]) + (float)puVar1[0x1cb7] + 0.0f;
              unaff_f20 = fVar19 * (fVar18 - (float)puVar1[0x1cb8]) + (float)puVar1[0x1cb8] + 0.0f;
            }
            if ((uVar10 & 0x10) == 0) {
              if ((uVar10 & 0x20) == 0) {
                fVar19 = 1.0f;
              }
              else {
                fVar19 = (float)(int)(10 - puVar11[0x1c4]) / 10.0f;
              }
            }
            else if ((int)puVar11[0x1c4] < 4) {
              fVar19 = (float)(int)puVar11[0x1c4] / 4.0f;
            }
            else {
              fVar19 = 1.0f;
            }
          }
          else {
            K_Assert(D_0068E880, 0x6d8);
          }
        }
      }
      else if ((uVar10 == 1) || (uVar10 == 0)) {
        uVar10 = *puVar1 & 0x10;
        in_f21 = fVar17;
        unaff_f20 = fVar18;
        if (uVar10 != 0) {
          if ((*puVar11 & 0x10) == 0) {
            fVar19 = 1.0f;
          }
          else if ((*puVar1 & 0x20) == 0) {
            if ((int)puVar11[0x1c4] < 4) {
              fVar19 = (float)(int)puVar11[0x1c4] / 4.0f;
            }
            else {
              fVar19 = 1.0f;
            }
          }
          else {
            fVar19 = 1.0f;
          }
          fVar19 = fVar19 * 2.0f - fVar19 * fVar19 * 1.0f;
          in_f21 = fVar19 * (fVar17 - (float)puVar1[0x1cb7]) + (float)puVar1[0x1cb7] + 0.0f;
          unaff_f20 = fVar19 * (fVar18 - (float)puVar1[0x1cb8]) + (float)puVar1[0x1cb8] + 0.0f;
        }
        uVar9 = *puVar11;
        if ((uVar9 & 0x10) == 0) {
          if ((uVar9 & 0x20) == 0) {
            fVar19 = 1.0f;
          }
          else if ((uVar9 & 0x400) == 0) {
            fVar19 = 0.0f;
          }
          else {
            fVar19 = (float)(int)(10 - puVar11[0x1c4]) / 10.0f;
          }
        }
        else if (uVar10 == 0) {
          if ((int)puVar11[0x1c4] < 4) {
            fVar19 = (float)(int)puVar11[0x1c4] / 4.0f;
          }
          else {
            fVar19 = 1.0f;
          }
        }
        else {
          fVar19 = 1.0f;
        }
      }
      uVar10 = puVar1[1];
      if (uVar10 == 2) {
        iVar4 = func_0021cca0(uVar6,0x37);
      }
      else if ((uVar10 == 1) || (uVar10 == 0)) {
        iVar4 = func_0021cca0(uVar7,4);
      }
      iVar12 = *(int *)(iVar4 + 0xc);
      if (iVar12 < 0) {
        iVar12 = iVar12 + 1;
      }
      afStack_30[0] = in_f21 - (float)(iVar12 >> 1);
      iVar12 = *(int *)(iVar4 + 0x10);
      if (iVar12 < 0) {
        iVar12 = iVar12 + 1;
      }
      afStack_30[1] = unaff_f20 - (float)(iVar12 >> 1);
      afStack_30[2] = (float)*(int *)(iVar4 + 0xc);
      afStack_30[3] = (float)*(int *)(iVar4 + 0x10);
      func_0021d8e0(puVar11 + 0x11,afStack_30);
      auStack_4[0] = 0xff;
      auStack_4[1] = 0xff;
      auStack_4[2] = 0xff;
      fVar20 = fVar19 * 255.0f;
      if (fVar20 < 2147483648.0f) {
        auStack_4[3] = (u8)(int)fVar20;
      }
      else {
        auStack_4[3] = (u8)(int)(fVar20 - 2147483648.0f);
      }
      func_0021d950(puVar11 + 0x11,&auStack_4[0]);
      iVar4 = func_0021cca0(uVar7,2);
      iVar12 = *(int *)(iVar4 + 0xc);
      if (iVar12 < 0) {
        iVar12 = iVar12 + 1;
      }
      afStack_30[0] = fVar17 - (float)(iVar12 >> 1);
      iVar12 = *(int *)(iVar4 + 0x10);
      if (iVar12 < 0) {
        iVar12 = iVar12 + 1;
      }
      afStack_30[1] = fVar18 - (float)(iVar12 >> 1);
      afStack_30[2] = (float)*(int *)(iVar4 + 0xc);
      afStack_30[3] = (float)*(int *)(iVar4 + 0x10);
      func_0021d8e0(puVar11 + 0x21,afStack_30);
      uVar10 = puVar1[1];
      if (uVar10 == 2) {
        uVar10 = *puVar11;
        if ((uVar10 & 0x80) == 0) {
          if ((uVar10 & 0x10) == 0) {
            if ((uVar10 & 0x20) == 0) {
              fVar19 = 1.0f;
            }
            else {
              unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
              fVar19 = 1.0f - unaff_f24;
            }
          }
          else {
            unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
            fVar19 = unaff_f24;
          }
        }
        else {
          fVar19 = (float)(int)puVar11[0x289] / 10.0f;
          if ((uVar10 & 0x10) == 0) {
            if ((uVar10 & 0x20) != 0) {
              fVar19 = (1.0f - unaff_f24) * fVar19;
            }
          }
          else {
            unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
            fVar19 = unaff_f24 * fVar19;
          }
        }
      }
      else if ((uVar10 == 1) || (uVar10 == 0)) {
        if ((*puVar11 & 0x10) == 0) {
          if ((*puVar11 & 0x20) == 0) {
            fVar19 = 1.0f;
          }
          else {
            unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
            fVar19 = 1.0f - unaff_f24;
          }
        }
        else {
          unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
          fVar19 = unaff_f24;
        }
      }
      auStack_4[0] = 0xff;
      auStack_4[1] = 0xff;
      auStack_4[2] = 0xff;
      fVar20 = fVar19 * 255.0f;
      if (fVar20 < 2147483648.0f) {
        auStack_4[3] = (u8)(int)fVar20;
      }
      else {
        auStack_4[3] = (u8)(int)(fVar20 - 2147483648.0f);
      }
      func_0021d950(puVar11 + 0x21,&auStack_4[0]);
      iVar12 = func_0021cca0(uVar7,0x2c);
      fVar20 = fVar17 - 45.0f;
      afStack_30[1] = fVar18 - 44.0f;
      afStack_30[0] = fVar20;
      afStack_30[2] = fVar20 + (float)*(int *)(iVar12 + 0xc);
      afStack_30[3] = afStack_30[1];
      afStack_30[4] = afStack_30[2];
      fVar25 = afStack_30[1] + 44.0f;
      for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
        afStack_30[iVar12 * 2] = afStack_30[iVar12 * 2] - (fVar20 + 44.0f);
        afStack_30[iVar12 * 2 + 1] = afStack_30[iVar12 * 2 + 1] - fVar25;
      }
      fVar26 = (DAT_007caf38 * (float)(int)(puVar1[0x1cb5] << 1)) / 60.0f;
      for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
        pfVar13 = afStack_30 + iVar12 * 2;
        pfVar14 = afStack_30 + iVar12 * 2 + 1;
        fVar15 = (float)sinf(fVar26);
        fVar21 = *pfVar14;
        fVar16 = (float)cosf(fVar26);
        fVar23 = *pfVar13 * fVar16 - fVar21 * fVar15;
        fVar16 = (float)sinf(fVar26);
        fVar22 = *pfVar13;
        fVar21 = (float)cosf(fVar26);
        fVar15 = *pfVar14;
        *pfVar13 = fVar23;
        *pfVar14 = fVar22 * fVar16 + fVar15 * fVar21;
      }
      for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
        afStack_30[iVar12 * 2] = afStack_30[iVar12 * 2] + fVar20 + 44.0f;
        afStack_30[iVar12 * 2 + 1] = afStack_30[iVar12 * 2 + 1] + fVar25;
      }
      func_0021d890(puVar11 + 0x144,afStack_30);
      uVar10 = puVar1[1];
      if (uVar10 == 2) {
        fVar19 = 0.0f;
      }
      else if ((uVar10 == 1) || (uVar10 == 0)) {
        if ((*puVar11 & 0x10) == 0) {
          if ((*puVar11 & 0x20) == 0) {
            fVar19 = 1.0f;
          }
          else {
            unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
            fVar19 = 1.0f - unaff_f24;
          }
        }
        else {
          unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
          fVar19 = unaff_f24;
        }
      }
      auStack_4[0] = 0xff;
      auStack_4[1] = 0xff;
      auStack_4[2] = 0xff;
      fVar20 = fVar19 * 255.0f;
      if (fVar20 < 2147483648.0f) {
        auStack_4[3] = (u8)(int)fVar20;
      }
      else {
        auStack_4[3] = (u8)(int)(fVar20 - 2147483648.0f);
      }
      func_0021d950(puVar11 + 0x144,&auStack_4[0]);
      uVar10 = puVar1[1];
      if (uVar10 == 2) {
        fVar19 = 0.0f;
      }
      else if ((uVar10 == 1) || (uVar10 == 0)) {
        if ((*puVar11 & 0x10) == 0) {
          if ((*puVar11 & 0x20) == 0) {
            fVar19 = 1.0f;
          }
          else {
            unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
            fVar19 = 1.0f - unaff_f24;
          }
        }
        else {
          unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
          fVar19 = unaff_f24;
        }
      }
      iVar4 = func_0021cca0(uVar7,0x45);
      iVar12 = *(int *)(iVar4 + 0xc);
      if (iVar12 < 0) {
        iVar12 = iVar12 + 1;
      }
      afStack_30[0] = fVar17 - (float)(iVar12 >> 1);
      iVar12 = *(int *)(iVar4 + 0x10);
      if (iVar12 < 0) {
        iVar12 = iVar12 + 1;
      }
      afStack_30[1] = fVar18 - (float)(iVar12 >> 1);
      afStack_30[2] = (float)*(int *)(iVar4 + 0xc);
      afStack_30[3] = (float)*(int *)(iVar4 + 0x10);
      func_0021d8e0(puVar11 + 0x184,afStack_30);
      auStack_4[0] = 0xff;
      auStack_4[1] = 0xff;
      auStack_4[2] = 0xff;
      fVar19 = fVar19 * 255.0f;
      if (fVar19 < 2147483648.0f) {
        auStack_4[3] = (u8)(int)fVar19;
      }
      else {
        auStack_4[3] = (u8)(int)(fVar19 - 2147483648.0f);
      }
      func_0021d950(puVar11 + 0x184,&auStack_4[0]);
      if ((puVar1[1] == 1) || (puVar1[1] == 0)) {
        if ((*puVar11 & 0x10) == 0) {
          if ((*puVar11 & 0x20) == 0) {
            fVar19 = 0.0f;
            fVar20 = 1.0f;
          }
          else if ((int)puVar11[0x1c4] < 6) {
            fVar20 = 1.0f - (float)(int)puVar11[0x1c4] / 6.0f;
            fVar19 = (fVar20 * 60.0f - fVar20 * fVar20 * 30.0f) - 30.0f;
          }
          else {
            fVar19 = -30.0f;
            fVar20 = 0.0f;
          }
        }
        else if ((int)puVar11[0x1c4] < 4) {
          fVar19 = -30.0f;
          fVar20 = 0.0f;
        }
        else {
          fVar20 = (float)(int)(puVar11[0x1c4] - 4) / 6.0f;
          fVar19 = (fVar20 * 60.0f - fVar20 * fVar20 * 30.0f) - 30.0f;
        }
        iVar12 = func_0021cca0(uVar7,1);
        afStack_30[0] = fVar17 + fVar19;
        afStack_30[2] = (float)*(int *)(iVar12 + 0xc);
        afStack_30[3] = (float)*(int *)(iVar12 + 0x10);
        afStack_30[1] = fVar18;
        func_0021d8e0(puVar11 + 0x104,afStack_30);
        auStack_4[0] = 0xff;
        auStack_4[1] = 0xff;
        auStack_4[2] = 0xff;
        fVar20 = fVar20 * 255.0f;
        if (fVar20 < 2147483648.0f) {
          auStack_4[3] = (u8)(int)fVar20;
        }
        else {
          auStack_4[3] = (u8)(int)(fVar20 - 2147483648.0f);
        }
        func_0021d950(puVar11 + 0x104,&auStack_4[0]);
        uVar8 = func_0021cca0(uVar2,4);
        func_0021cd00(uVar8,afStack_30);
        fVar25 = (float)(int)puVar11[0x28c] /
                 (float)(int)puVar11[0x28d];
        afStack_30[2] = (afStack_30[2] - afStack_30[0]) * fVar25;
        afStack_30[3] = afStack_30[3] - afStack_30[1];
        func_0021eb80(puVar11 + 0xc4,afStack_30);
        afStack_30[0] = fVar17 + 8.0f + fVar19;
        afStack_30[1] = fVar18 + 4.0f;
        afStack_30[2] = (float)*(int *)((int)uVar8 + 0xc) * fVar25;
        afStack_30[3] = (float)*(int *)((int)uVar8 + 0x10);
        func_0021d8e0(puVar11 + 0xc4,afStack_30);
        auStack_4[0] = 0xff;
        auStack_4[1] = 0xff;
        auStack_4[2] = 0xff;
        if (fVar20 < 2147483648.0f) {
          auStack_4[3] = (u8)(int)fVar20;
        }
        else {
          auStack_4[3] = (u8)(int)(fVar20 - 2147483648.0f);
        }
        func_0021d950(puVar11 + 0xc4,&auStack_4[0]);
      }
      if (puVar1[1] == 2) {
        uVar10 = *puVar11;
        if ((uVar10 & 0x80) == 0) {
          fVar19 = 0.0f;
        }
        else {
          fVar19 = (float)(int)(10 - puVar11[0x28b]) / 10.0f;
          if ((uVar10 & 0x10) == 0) {
            if ((uVar10 & 0x20) != 0) {
              unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
              fVar19 = (1.0f - unaff_f24) * fVar19;
            }
          }
          else {
            unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
            fVar19 = unaff_f24 * fVar19;
          }
        }
        iVar4 = func_0021cca0(uVar6,0x39);
        iVar12 = *(int *)(iVar4 + 0xc);
        if (iVar12 < 0) {
          iVar12 = iVar12 + 1;
        }
        afStack_30[0] = fVar17 - (float)(iVar12 >> 1);
        iVar12 = *(int *)(iVar4 + 0x10);
        if (iVar12 < 0) {
          iVar12 = iVar12 + 1;
        }
        afStack_30[1] = fVar18 - (float)(iVar12 >> 1);
        afStack_30[2] = (float)*(int *)(iVar4 + 0xc);
        afStack_30[3] = (float)*(int *)(iVar4 + 0x10);
        func_0021d8e0(puVar11 + 0x1c8,afStack_30);
        auStack_4[0] = 0xff;
        auStack_4[1] = 0xff;
        auStack_4[2] = 0xff;
        fVar19 = fVar19 * 255.0f;
        if (fVar19 < 2147483648.0f) {
          auStack_4[3] = (u8)(int)fVar19;
        }
        else {
          auStack_4[3] = (u8)(int)(fVar19 - 2147483648.0f);
        }
        func_0021d950(puVar11 + 0x1c8,&auStack_4[0]);
        uVar10 = *puVar11;
        if ((uVar10 & 0x80) == 0) {
          fVar19 = 0.0f;
        }
        else {
          fVar19 = (float)(int)puVar11[0x28b] / 10.0f;
          if ((uVar10 & 0x10) == 0) {
            if ((uVar10 & 0x20) != 0) {
              unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
              fVar19 = (1.0f - unaff_f24) * fVar19;
            }
          }
          else {
            unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
            fVar19 = unaff_f24 * fVar19;
          }
        }
        iVar4 = func_0021cca0(uVar6,0x3d);
        iVar12 = *(int *)(iVar4 + 0xc);
        if (iVar12 < 0) {
          iVar12 = iVar12 + 1;
        }
        afStack_30[0] = fVar17 - (float)(iVar12 >> 1);
        iVar12 = *(int *)(iVar4 + 0x10);
        if (iVar12 < 0) {
          iVar12 = iVar12 + 1;
        }
        afStack_30[1] = fVar18 - (float)(iVar12 >> 1);
        afStack_30[2] = (float)*(int *)(iVar4 + 0xc);
        afStack_30[3] = (float)*(int *)(iVar4 + 0x10);
        func_0021d8e0(puVar11 + 0x208,afStack_30);
        auStack_4[0] = 0xff;
        auStack_4[1] = 0xff;
        auStack_4[2] = 0xff;
        fVar19 = fVar19 * 255.0f;
        if (fVar19 < 2147483648.0f) {
          auStack_4[3] = (u8)(int)fVar19;
        }
        else {
          auStack_4[3] = (u8)(int)(fVar19 - 2147483648.0f);
        }
        func_0021d950(puVar11 + 0x208,&auStack_4[0]);
        uVar10 = *puVar11;
        if ((uVar10 & 0x80) == 0) {
          fVar19 = 0.0f;
        }
        else {
          fVar19 = (float)(int)puVar11[0x28a] / 10.0f;
          if ((uVar10 & 0x10) == 0) {
            if ((uVar10 & 0x20) != 0) {
              unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
              fVar19 = (1.0f - unaff_f24) * fVar19;
            }
          }
          else {
            unaff_f24 = (float)(int)puVar11[0x1c4] / 10.0f;
            fVar19 = unaff_f24 * fVar19;
          }
        }
        iVar4 = func_0021cca0(uVar7,8);
        iVar12 = *(int *)(iVar4 + 0xc);
        if (iVar12 < 0) {
          iVar12 = iVar12 + 1;
        }
        afStack_30[0] = fVar17 - (float)(iVar12 >> 1);
        iVar12 = *(int *)(iVar4 + 0x10);
        if (iVar12 < 0) {
          iVar12 = iVar12 + 1;
        }
        afStack_30[1] = fVar18 - (float)(iVar12 >> 1);
        afStack_30[2] = (float)*(int *)(iVar4 + 0xc);
        afStack_30[3] = (float)*(int *)(iVar4 + 0x10);
        func_0021d8e0(puVar11 + 0x248,afStack_30);
        auStack_4[0] = 0xff;
        auStack_4[1] = 0xff;
        auStack_4[2] = 0xff;
        fVar19 = fVar19 * 255.0f;
        if (fVar19 < 2147483648.0f) {
          auStack_4[3] = (u8)(int)fVar19;
        }
        else {
          auStack_4[3] = (u8)(int)(fVar19 - 2147483648.0f);
        }
        func_0021d950(puVar11 + 0x248,&auStack_4[0]);
      }
    }
LAB_00247ba8:
    iVar5 = iVar5 + 1;
  }
  if ((*puVar1 & 2) != 0) {
    if ((*puVar1 & 4) == 0) {
      iVar5 = 0x135;
    }
    else {
      iVar5 = 0x113;
    }
    fVar17 = (float)iVar5;
    iVar5 = func_003b19d0(puVar1[0x1b30]);
    fVar18 = (float)iVar5;
    if ((*puVar1 & 4) == 0) {
      fVar19 = (fVar17 - fVar18 / 2.0f) - 57.0f;
    }
    else {
      fVar19 = 145.0f;
    }
    iVar5 = func_0021cca0(uVar7,0x43);
    afStack_30[1] = 100.0f;
    afStack_30[2] = (float)*(int *)(iVar5 + 0xc);
    afStack_30[3] = (float)*(int *)(iVar5 + 0x10);
    afStack_30[0] = fVar19;
    func_0021d8e0(puVar1 + 0x19b0,afStack_30);
    auStack_4[0] = 0xff;
    auStack_4[1] = 0xff;
    auStack_4[2] = 0xff;
    auStack_4[3] = 0xff;
    func_0021d950(puVar1 + 0x19b0,&auStack_4[0]);
    if ((*puVar1 & 4) == 0) {
      afStack_30[0] = (float)*(int *)(iVar5 + 0xc) + ((fVar17 - fVar18 / 2.0f) - 57.0f);
      afStack_30[2] = ((fVar17 + fVar18 / 2.0f + 57.0f) - 16.0f) - afStack_30[0];
    }
    else {
      afStack_30[0] = (float)*(int *)(iVar5 + 0xc) + 145.0f;
      afStack_30[2] = 286.0f;
    }
    afStack_30[1] = 100.0f;
    afStack_30[3] = (float)*(int *)(iVar5 + 0x10);
    func_0021d8e0(puVar1 + 0x19f0,afStack_30);
    auStack_4[0] = 0xff;
    auStack_4[1] = 0xff;
    auStack_4[2] = 0xff;
    auStack_4[3] = 0xff;
    func_0021d950(puVar1 + 0x19f0,&auStack_4[0]);
    if ((*puVar1 & 4) == 0) {
      fVar19 = (fVar17 + fVar18 / 2.0f + 57.0f) - 16.0f;
    }
    else {
      fVar19 = 451.0f;
    }
    iVar5 = func_0021cca0(uVar7,0x44);
    afStack_30[1] = 100.0f;
    afStack_30[2] = (float)*(int *)(iVar5 + 0xc);
    afStack_30[3] = (float)*(int *)(iVar5 + 0x10);
    afStack_30[0] = fVar19;
    func_0021d8e0(puVar1 + 0x1a30,afStack_30);
    auStack_4[0] = 0xff;
    auStack_4[1] = 0xff;
    auStack_4[2] = 0xff;
    auStack_4[3] = 0xff;
    func_0021d950(puVar1 + 0x1a30,&auStack_4[0]);
    iVar5 = func_0021cca0(uVar7,0);
    if ((*puVar1 & 4) == 0) {
      afStack_30[0] = (fVar17 - fVar18 / 2.0f) - 86.0f;
      afStack_30[2] = (fVar17 + fVar18 / 2.0f + 86.0f) - afStack_30[0];
    }
    else {
      afStack_30[0] = 116.0f;
      afStack_30[2] = (float)((*(int *)(iVar5 + 0xc) * 0x4f6) / 100);
    }
    afStack_30[1] = 54.0f;
    afStack_30[3] = (float)((*(int *)(iVar5 + 0x10) * 0x186) / 100);
    func_0021d8e0(puVar1 + 0x1a70,afStack_30);
    auStack_4[0] = 0xff;
    auStack_4[1] = 0xff;
    auStack_4[2] = 0xff;
    auStack_4[3] = 0xff;
    func_0021d950(puVar1 + 0x1a70,&auStack_4[0]);
    fVar20 = fVar18 / 2.0f;
    fVar19 = fVar17 - fVar20;
    func_003b0d70(puVar1[0x1b30],(int)(fVar19 * 16.0f),0x298);
    func_003b0e20(puVar1[0x1b30],0xffffffffffffffff);
    iVar5 = func_0021cca0(uVar7,0x42);
    afStack_30[0] = fVar19 - 28.0f;
    afStack_30[2] = (float)*(int *)(iVar5 + 0xc);
    afStack_30[3] = (float)*(int *)(iVar5 + 0x10);
    func_0021d8e0(puVar1 + 0x1ab0,afStack_30);
    auStack_4[0] = 0xff;
    auStack_4[1] = 0xff;
    auStack_4[2] = 0xff;
    auStack_4[3] = 0xff;
    func_0021d950(puVar1 + 0x1ab0,&auStack_4[0]);
    afStack_30[0] = (fVar17 + fVar20 + 28.0f) - 16.0f;
    afStack_30[1] = 91.0f;
    afStack_30[2] = (float)*(int *)(iVar5 + 0xc);
    afStack_30[3] = (float)*(int *)(iVar5 + 0x10);
    func_0021d8e0(puVar1 + 0x1af0,afStack_30);
    auStack_4[0] = 0xff;
    auStack_4[1] = 0xff;
    auStack_4[2] = 0xff;
    auStack_4[3] = 0xff;
    func_0021d950(puVar1 + 0x1af0,&auStack_4[0]);
    if ((*puVar1 & 4) != 0) {
      uVar10 = puVar1[0x1b31];
      if (uVar10 == 0) {
        iVar5 = func_0021cca0(uVar7,0x3c);
      }
      else {
        iVar5 = func_0021cca0(uVar7,0x3b);
      }
      afStack_30[0] = 278.0f;
      afStack_30[1] = 113.0f;
      afStack_30[2] = (float)*(int *)(iVar5 + 0xc);
      afStack_30[3] = (float)*(int *)(iVar5 + 0x10);
      func_0021d8e0(puVar1 + 0x1b34,afStack_30);
      auStack_4[0] = 0xff;
      auStack_4[1] = 0xff;
      auStack_4[2] = 0xff;
      auStack_4[3] = 0xff;
      func_0021d950(puVar1 + 0x1b34,&auStack_4[0]);
      uVar10 = puVar1[0x1b32];
      if (uVar10 == 0) {
        iVar5 = func_0021cca0(uVar7,0x3e);
      }
      else {
        iVar5 = func_0021cca0(uVar7,0x3d);
      }
      afStack_30[0] = 337.0f;
      afStack_30[1] = 113.0f;
      afStack_30[2] = (float)*(int *)(iVar5 + 0xc);
      afStack_30[3] = (float)*(int *)(iVar5 + 0x10);
      func_0021d8e0(puVar1 + 0x1b74,afStack_30);
      auStack_4[0] = 0xff;
      auStack_4[1] = 0xff;
      auStack_4[2] = 0xff;
      auStack_4[3] = 0xff;
      func_0021d950(puVar1 + 0x1b74,&auStack_4[0]);
      uVar10 = puVar1[0x1b33];
      if (uVar10 == 0) {
        iVar5 = func_0021cca0(uVar7,0x40);
      }
      else {
        iVar5 = func_0021cca0(uVar7,0x3f);
      }
      afStack_30[0] = 396.0f;
      afStack_30[1] = 113.0f;
      afStack_30[2] = (float)*(int *)(iVar5 + 0xc);
      afStack_30[3] = (float)*(int *)(iVar5 + 0x10);
      func_0021d8e0(puVar1 + 0x1bb4,afStack_30);
      auStack_4[0] = 0xff;
      auStack_4[1] = 0xff;
      auStack_4[2] = 0xff;
      auStack_4[3] = 0xff;
      func_0021d950(puVar1 + 0x1bb4,&auStack_4[0]);
      for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
        uVar10 = puVar1[iVar12 + 0x1b31];
        if (uVar10 == 0) {
          iVar5 = func_0021cca0(uVar7,0x41);
        }
        else if (uVar10 == 2) {
          iVar5 = func_0021cca0(uVar3,0x12);
        }
        else if (uVar10 == 1) {
          iVar5 = func_0021cca0(uVar3,0x11);
        }
        afStack_30[0] = (float)iVar12 * 59.0f + 304.0f;
        afStack_30[1] = 113.0f;
        afStack_30[2] = (float)*(int *)(iVar5 + 0xc);
        afStack_30[3] = (float)*(int *)(iVar5 + 0x10);
        func_0021d8e0(puVar1 + iVar12 * 0x40 + 0x1bf4,afStack_30);
        auStack_4[0] = 0xff;
        auStack_4[1] = 0xff;
        auStack_4[2] = 0xff;
        auStack_4[3] = 0xff;
        func_0021d950(puVar1 + iVar12 * 0x40 + 0x1bf4,&auStack_4[0]);
      }
    }
  }
  return;
}



