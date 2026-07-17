#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))
typedef struct FrFontGlyph {
  u8 unknown_00[0xc];
  int advance;
  u8 unknown_10[0x18];
  struct FrFontGlyph *next;
} FrFontGlyph;

typedef struct FrFontNode {
  u8 unknown_00[3];
  s8 line_height;
  u8 unknown_04[0x18];
  FrFontGlyph *glyphs;
  u8 unknown_20[4];
  struct FrFontNode *next;
  u8 unknown_28[0x18];
  int enabled;
} FrFontNode;

typedef struct FrFontState {
  u8 unknown_00[4];
  int text_position;
  u8 unknown_08[0x14];
  u8 layout_dirty;
  u8 position_dirty;
} FrFontState;

extern u32 DAT_006a2370;
extern const char DAT_006a2730[];
extern u32 DAT_007cd4f8;
extern u32 DAT_007cd500;
extern u32 DAT_007ce638;
extern u32 DAT_007ce63c;
extern u32 DAT_0095ac70;
extern u32 DAT_0095acf0;
extern u32 DAT_0095acf4;
extern u32 DAT_0095acf8;
extern u32 DAT_0095acfc;
extern u32 DAT_0095ad00;
extern u32 DAT_0095ad04;
extern u32 DAT_0095ad08;
extern u32 DAT_0095ad0c;
extern u32 DAT_0095ad10;
extern u32 DAT_0095ad30;
extern u32 DAT_0095ad50;
extern u32 DAT_0095ad70;
extern u32 DAT_0095ad90;
extern u32 DAT_0095ae10;
extern u32 DAT_0095ae14;
extern u32 DAT_0095ae18;
extern u32 DAT_0095ae1c;
extern u32 DAT_0095ae20;
extern u32 DAT_0095ae24;
extern u32 DAT_0095ae28;
extern u32 DAT_0095ae60;
extern u32 DAT_0095ae64;
extern u32 DAT_0095ae74;
extern code DAT_00960090;
extern code DAT_00960178;
extern code DAT_0096017c;
extern u32 LAB_003b28b8;
extern u32 bGpffffb950;
extern u32 gp0xffffa808;
extern u32 gp0xffffa838;
extern u32 iGpffffa800;
extern u32 iGpffffb944;
extern u32 iGpffffb948;
extern u32 uGpffffa7f8;
extern u32 uGpffffa7fc;
extern u32 uGpffffa800;
extern s16 uGpffffa810;
extern u32 uGpffffb940;

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
void FUN_003afa40(void);
void FUN_003afad0(u32 param_1,long param_2,long param_3);
void FUN_003afc30(u32 param_1);
void FUN_003afc70(void);
void FUN_003afe30(void);
void FUN_003aff50(void);
u64 FUN_003affd0(u64 param_1);
u32 FUN_003b0030(int param_1);
u64 FUN_003b0170(u64 param_1);
void FUN_003b01d0(int param_1,int param_2);
int FUN_003b03a0(void);
void FUN_003b0430(int param_1,u64 param_2);
void FUN_003b05c0(u16 *param_1);
long FUN_003b0620(u16 param_1,u8 param_2,u8 param_3,u8 param_4);
int FUN_003b0840(short *param_1);
long FUN_003b0970(long param_1,u8 param_2,u8 param_3,u8 param_4,long param_5);
void FUN_003b0bb0(int param_1,u8 param_2);
void FUN_003b0c20(long param_1,u16 param_2);
void FUN_003b0c70(FrFontNode *node);
void FUN_003b0ce0(int param_1,u8 param_2);
void FUN_003b0d70(long param_1,u32 param_2,u32 param_3);
void FUN_003b0e04(int param_1,u8 param_2);
void FUN_003b0e54(int param_1,u32 param_2);
u16 FUN_003b0e70(s16 param_1);
u16 FUN_003b0e90(u16 param_1);
u32 FUN_003b0ec0(int param_1);
int FUN_003b0f50(int param_1,u16 *param_2,u8 param_3,u32 param_4);
void FUN_003b1300(u64 param_1);
void FUN_003b1330(u64 param_1,u64 param_2);
int FUN_003b1360(long param_1,u64 param_2,u32 param_3);
int FUN_003b1710(long param_1);
u64 FUN_003b18c0(void);
long FUN_003b1920(long param_1,long param_2,int param_3);
void FUN_003b19a0(u64 param_1);
int FUN_003b19d0(FrFontNode *node);
u16 FUN_003b1a10(u32 param_1);
u16 FUN_003b1a40(u32 param_1);
void FUN_003b1a70(void);
void FUN_003b1a80(u32 param_1);
int FUN_003b1a90(long param_1);
int FUN_003b1b00(int param_1,long param_2);
void FUN_003b1bc0(u32 *param_1,int param_2,long param_3);
void FUN_003b1c40(int param_1,int param_2,long param_3);
void FUN_003b1c90(int param_1,int param_2,long param_3);
void FUN_003b1d90(u32 param_1,int param_2);
void FUN_003b2020(long param_1,int param_2);
void FUN_003b22a0(u32 *param_1);
void FUN_003b2400(FrFontState *state);
u32 FUN_003b2430(u64 param_1);
void FUN_003b2900(u64 param_1,u64 param_2,u64 param_3);
void FUN_003b2940(u64 param_1,u64 param_2,u64 param_3,u64 param_4,  u64 param_5,u64 param_6,u64 param_7);
void FUN_003b2990(u32 param_1,u32 param_2,int param_3,u8 param_4,  u8 param_5,u8 param_6,u8 param_7,u32 param_8,  u32 param_9);
u32 FUN_003b2a00(u32 param_1);
void FUN_003b2a10(int param_1,u32 param_2);
u64 FUN_003b2a30(u64 param_1,u32 param_2);
u8 FUN_003b2bf0(u32 param_1,u32 param_2,u64 param_3);

/* Region call-cast macros */
#define FUN_003afa40(...) ((void (*)(...))FUN_003afa40)(__VA_ARGS__)
#define FUN_003afad0(...) ((void (*)(...))FUN_003afad0)(__VA_ARGS__)
#define FUN_003afc30(...) ((void (*)(...))FUN_003afc30)(__VA_ARGS__)
#define FUN_003afc70(...) ((void (*)(...))FUN_003afc70)(__VA_ARGS__)
#define FUN_003afe30(...) ((void (*)(...))FUN_003afe30)(__VA_ARGS__)
#define FUN_003aff50(...) ((void (*)(...))FUN_003aff50)(__VA_ARGS__)
#define FUN_003affd0(...) ((u64 (*)(...))FUN_003affd0)(__VA_ARGS__)
#define FUN_003b0030(...) ((u32 (*)(...))FUN_003b0030)(__VA_ARGS__)
#define FUN_003b0170(...) ((u64 (*)(...))FUN_003b0170)(__VA_ARGS__)
#define FUN_003b01d0(...) ((void (*)(...))FUN_003b01d0)(__VA_ARGS__)
#define FUN_003b03a0(...) ((int (*)(...))FUN_003b03a0)(__VA_ARGS__)
#define FUN_003b0430(...) ((void (*)(...))FUN_003b0430)(__VA_ARGS__)
#define FUN_003b05c0(...) ((void (*)(...))FUN_003b05c0)(__VA_ARGS__)
#define FUN_003b0620(...) ((long (*)(...))FUN_003b0620)(__VA_ARGS__)
#define FUN_003b0840(...) ((int (*)(...))FUN_003b0840)(__VA_ARGS__)
#define FUN_003b0970(...) ((long (*)(...))FUN_003b0970)(__VA_ARGS__)
#define FUN_003b0bb0(...) ((void (*)(...))FUN_003b0bb0)(__VA_ARGS__)
#define FUN_003b0c20(...) ((void (*)(...))FUN_003b0c20)(__VA_ARGS__)
#define FUN_003b0c70(...) ((void (*)(...))FUN_003b0c70)(__VA_ARGS__)
#define FUN_003b0ce0(...) ((void (*)(...))FUN_003b0ce0)(__VA_ARGS__)
#define FUN_003b0d70(...) ((void (*)(...))FUN_003b0d70)(__VA_ARGS__)
#define FUN_003b0e04(...) ((void (*)(...))FUN_003b0e04)(__VA_ARGS__)
#define FUN_003b0e54(...) ((void (*)(...))FUN_003b0e54)(__VA_ARGS__)
#define FUN_003b0e70(...) ((u16 (*)(...))FUN_003b0e70)(__VA_ARGS__)
#define FUN_003b0e90(...) ((u16 (*)(...))FUN_003b0e90)(__VA_ARGS__)
#define FUN_003b0ec0(...) ((u32 (*)(...))FUN_003b0ec0)(__VA_ARGS__)
#define FUN_003b0f50(...) ((int (*)(...))FUN_003b0f50)(__VA_ARGS__)
#define FUN_003b1300(...) ((void (*)(...))FUN_003b1300)(__VA_ARGS__)
#define FUN_003b1330(...) ((void (*)(...))FUN_003b1330)(__VA_ARGS__)
#define FUN_003b1360(...) ((int (*)(...))FUN_003b1360)(__VA_ARGS__)
#define FUN_003b1710(...) ((int (*)(...))FUN_003b1710)(__VA_ARGS__)
#define FUN_003b18c0(...) ((u64 (*)(...))FUN_003b18c0)(__VA_ARGS__)
#define FUN_003b1920(...) ((long (*)(...))FUN_003b1920)(__VA_ARGS__)
#define FUN_003b19a0(...) ((void (*)(...))FUN_003b19a0)(__VA_ARGS__)
#define FUN_003b19d0(...) ((int (*)(...))FUN_003b19d0)(__VA_ARGS__)
#define FUN_003b1a10(...) ((u16 (*)(...))FUN_003b1a10)(__VA_ARGS__)
#define FUN_003b1a40(...) ((u16 (*)(...))FUN_003b1a40)(__VA_ARGS__)
#define FUN_003b1a70(...) ((void (*)(...))FUN_003b1a70)(__VA_ARGS__)
#define FUN_003b1a80(...) ((void (*)(...))FUN_003b1a80)(__VA_ARGS__)
#define FUN_003b1a90(...) ((int (*)(...))FUN_003b1a90)(__VA_ARGS__)
#define FUN_003b1b00(...) ((int (*)(...))FUN_003b1b00)(__VA_ARGS__)
#define FUN_003b1bc0(...) ((void (*)(...))FUN_003b1bc0)(__VA_ARGS__)
#define FUN_003b1c40(...) ((void (*)(...))FUN_003b1c40)(__VA_ARGS__)
#define FUN_003b1c90(...) ((void (*)(...))FUN_003b1c90)(__VA_ARGS__)
#define FUN_003b1d90(...) ((void (*)(...))FUN_003b1d90)(__VA_ARGS__)
#define FUN_003b2020(...) ((void (*)(...))FUN_003b2020)(__VA_ARGS__)
#define FUN_003b22a0(...) ((void (*)(...))FUN_003b22a0)(__VA_ARGS__)
#define FUN_003b2400(...) ((void (*)(...))FUN_003b2400)(__VA_ARGS__)
#define FUN_003b2430(...) ((u32 (*)(...))FUN_003b2430)(__VA_ARGS__)
#define FUN_003b2900(...) ((void (*)(...))FUN_003b2900)(__VA_ARGS__)
#define FUN_003b2940(...) ((void (*)(...))FUN_003b2940)(__VA_ARGS__)
#define FUN_003b2990(...) ((void (*)(...))FUN_003b2990)(__VA_ARGS__)
#define FUN_003b2a00(...) ((u32 (*)(...))FUN_003b2a00)(__VA_ARGS__)
#define FUN_003b2a10(...) ((void (*)(...))FUN_003b2a10)(__VA_ARGS__)
#define FUN_003b2a30(...) ((u64 (*)(...))FUN_003b2a30)(__VA_ARGS__)
#define FUN_003b2bf0(...) ((u8 (*)(...))FUN_003b2bf0)(__VA_ARGS__)

#undef FUN_003afa40
// FUN_003AFA40 NONMATCHING


void FUN_003afa40(void)



{

  FUN_003afe30();

  FUN_003b0030(DAT_0095ae60);

  FUN_003b0030(DAT_0095ae64);

  FUN_003b4740(DAT_0095ae1c);

  FUN_003b4740(DAT_0095ae20);

  FUN_003b44a0();

  FUN_0035ac80(DAT_0095ae24);

  FUN_0035ac80(DAT_0095ae28);

  FUN_003b3740();

  return;

}
#define FUN_003afa40(...) ((void (*)(...))FUN_003afa40)(__VA_ARGS__)
#undef FUN_003afad0
// FUN_003AFAD0 NONMATCHING


void FUN_003afad0(u32 param_1,long param_2,long param_3)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  

  if ((param_2 == 0) && (param_3 != 0)) {

    param_2 = param_3;

  }

  if (param_2 == 0) {

    FUN_0019d3f0(0x6a2730,0x3ff);

  }

  param_1 = param_1 & 0xff;

  iVar1 = param_1 * 0x20;

  if (8 < param_1) {

    FUN_0035ac50(0x6a27a0);

  }

  (&DAT_0095acf0)[param_1 * 8] = (int)param_3;

  piVar3 = (int *)param_2;

  (&DAT_0095acf4)[param_1 * 8] = (u32)piVar3;

  iVar2 = *piVar3 + (u32)*(u8 *)((int)piVar3 + 10) * 0x40;

  if (*(char *)((int)piVar3 + 0x16) == '\0') {

    (&DAT_0095acf8)[param_1 * 8] = 0;

    *(u32 *)(&DAT_0095ad00 + iVar1) = 0;

    (&DAT_0095acfc)[param_1 * 8] = 0;

    *(u32 *)(&DAT_0095ad04 + iVar1) = 0;

  }

  else {

    (&DAT_0095acf8)[param_1 * 8] = *(u32 *)((int)piVar3 + iVar2);

    *(int *)(&DAT_0095ad00 + iVar1) = (int)piVar3 + iVar2 + 4;

    iVar2 = iVar2 + (&DAT_0095acf8)[param_1 * 8] + 4;

    (&DAT_0095acfc)[param_1 * 8] = *(u32 *)((int)piVar3 + iVar2);

    *(int *)(&DAT_0095ad04 + iVar1) = (int)piVar3 + iVar2 + 4;

    iVar2 = iVar2 + (&DAT_0095acfc)[param_1 * 8] + 4;

  }

  *(int *)(&DAT_0095ad08 + iVar1) = (int)piVar3 + iVar2;

  FUN_005225a8(0x6a27d0,(int)piVar3 + iVar2,iVar2,

               *(u16 *)((&DAT_0095acf4)[param_1 * 8] + 0xe));

  (&DAT_0095ad0c)[param_1 * 8] =

       (int)piVar3 + iVar2 + (u32)*(u16 *)((&DAT_0095acf4)[param_1 * 8] + 0xe) * 4;

  return;

}
#define FUN_003afad0(...) ((void (*)(...))FUN_003afad0)(__VA_ARGS__)
#undef FUN_003afc30
// FUN_003AFC30 NONMATCHING


void FUN_003afc30(u32 param_1)



{

  (*DAT_0096017c)((&DAT_0095acf0)[(param_1 & 0xff) * 8]);

  return;

}
#define FUN_003afc30(...) ((void (*)(...))FUN_003afc30)(__VA_ARGS__)
#undef FUN_003afc70
// FUN_003AFC70 NONMATCHING


void FUN_003afc70(void)



{

  u32 uVar1;

  u32 uVar2;

  u64 uVar3;

  int iVar4;

  u32 *puVar5;

  u32 *puVar6;

  u8 auStack_4 [4];

  

  if (DAT_0095ad0c != 0) {

    FUN_005225a8(0x6a2760,0);

  }

  if (DAT_0095ae74 == 0) {

    uVar3 = FUN_00100d80(0x6a2820,0);

    DAT_0095ae74 = (int)uVar3;

    FUN_001023a0(uVar3);

    uVar3 = FUN_001021c0(0x6a2820,auStack_4);

    FUN_003afad0(0,0,uVar3);

  }

  puVar6 = &DAT_0095acf0;

  puVar5 = &DAT_0095ad10;

  iVar4 = 4;

  do {

    uVar1 = *puVar6;

    uVar2 = puVar6[1];

    puVar6 = puVar6 + 2;

    iVar4 = iVar4 + -1;

    *puVar5 = uVar1;

    puVar5[1] = uVar2;

    puVar5 = puVar5 + 2;

  } while (0 < iVar4);

  puVar6 = &DAT_0095acf0;

  puVar5 = &DAT_0095ad30;

  iVar4 = 4;

  do {

    uVar1 = *puVar6;

    uVar2 = puVar6[1];

    puVar6 = puVar6 + 2;

    iVar4 = iVar4 + -1;

    *puVar5 = uVar1;

    puVar5[1] = uVar2;

    puVar5 = puVar5 + 2;

  } while (0 < iVar4);

  puVar6 = &DAT_0095acf0;

  puVar5 = &DAT_0095ad50;

  iVar4 = 4;

  do {

    uVar1 = *puVar6;

    uVar2 = puVar6[1];

    puVar6 = puVar6 + 2;

    iVar4 = iVar4 + -1;

    *puVar5 = uVar1;

    puVar5[1] = uVar2;

    puVar5 = puVar5 + 2;

  } while (0 < iVar4);

  puVar6 = &DAT_0095acf0;

  puVar5 = &DAT_0095ad70;

  iVar4 = 4;

  do {

    uVar1 = *puVar6;

    uVar2 = puVar6[1];

    puVar6 = puVar6 + 2;

    iVar4 = iVar4 + -1;

    *puVar5 = uVar1;

    puVar5[1] = uVar2;

    puVar5 = puVar5 + 2;

  } while (0 < iVar4);

  puVar6 = &DAT_0095acf0;

  puVar5 = &DAT_0095ad90;

  iVar4 = 4;

  do {

    uVar1 = *puVar6;

    uVar2 = puVar6[1];

    puVar6 = puVar6 + 2;

    iVar4 = iVar4 + -1;

    *puVar5 = uVar1;

    puVar5[1] = uVar2;

    puVar5 = puVar5 + 2;

  } while (0 < iVar4);

  DAT_007ce63c = 0;

  DAT_007ce638 = 0;

  return;

}
#define FUN_003afc70(...) ((void (*)(...))FUN_003afc70)(__VA_ARGS__)
#undef FUN_003afe30
// FUN_003AFE30 NONMATCHING


void FUN_003afe30(void)



{

  u32 uVar1;

  u32 uVar2;

  u32 uVar3;

  

  for (uVar3 = 0; (int)uVar3 < 9; uVar3 = uVar3 + 1) {

    if ((&DAT_0095ad0c)[uVar3 * 8] != 0) {

      uVar2 = uVar3 & 0xff;

      if (8 < uVar2) {

        FUN_0035ac50(0x6a27a0,uVar2);

      }

      uVar1 = uVar3 & 0xff;

      if ((&DAT_0095ad0c)[uVar1 * 8] == 0) {

        FUN_0019d3f0(0x6a2730,0x432);

      }

      if ((&DAT_0095ae74)[uVar1] != 0) {

        FUN_00100ec0();

        (&DAT_0095ae74)[uVar3 & 0xff] = 0;

        FUN_005225a8(0x6a2800,uVar2);

        (&DAT_0095acf0)[uVar1 * 8] = 0;

        (&DAT_0095ad0c)[uVar1 * 8] = 0;

      }

      *(u32 *)(&DAT_0095ad08 + uVar1 * 0x20) = 0;

    }

  }

  return;

}
#define FUN_003afe30(...) ((void (*)(...))FUN_003afe30)(__VA_ARGS__)
#undef FUN_003aff50
// FUN_003AFF50 NONMATCHING


void FUN_003aff50(void)



{

  int iVar1;

  int iVar2;

  

  for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {

    for (iVar1 = 0; iVar1 < 0x10; iVar1 = iVar1 + 1) {

    }

    FUN_005225a8(0x6a2710,0x6a2730);

  }

  return;

}
#define FUN_003aff50(...) ((void (*)(...))FUN_003aff50)(__VA_ARGS__)
#undef FUN_003affd0
// FUN_003AFFD0 NONMATCHING


u64 FUN_003affd0(u64 param_1)



{

  char cVar1;

  

  cVar1 = FUN_003b0ec0();

  if (cVar1 == '\0') {

    param_1 = FUN_003b0030(param_1);

  }

  return param_1;

}
#define FUN_003affd0(...) ((u64 (*)(...))FUN_003affd0)(__VA_ARGS__)
#undef FUN_003b0030
// FUN_003B0030 NONMATCHING


u32 FUN_003b0030(int param_1)



{

  int iVar1;

  int iVar2;

  u32 *puVar3;

  int iVar4;

  

  if (param_1 != 0) {

    while (param_1 != 0) {

      iVar4 = *(int *)(param_1 + 0x1c);

      while (iVar4 != 0) {

        iVar1 = *(int *)(iVar4 + 0x28);

        if (*(int *)(iVar4 + 0x20) == 0) {

          *(short *)(*(int *)(iVar4 + 0x1c) + 4) = *(short *)(*(int *)(iVar4 + 0x1c) + 4) + -1;

          iVar2 = *(int *)(iVar4 + 0x1c);

          if ((iVar2 != 0) && (*(short *)(iVar2 + 4) == 0)) {

            puVar3 = *(u32 **)(iVar2 + 0xc);

            if (puVar3 != (u32 *)0x0) {

              *puVar3 = *puVar3 & 0xfffffffe;

              puVar3[4] = 0;

            }

            FUN_003b4580(*(u32 *)(iVar2 + 8));

            DAT_0095ae10 = DAT_0095ae10 + -1;

          }

        }

        FUN_003b46f0(iVar4,DAT_0095ae1c);

        DAT_0095ae14 = DAT_0095ae14 + -1;

        iVar4 = iVar1;

      }

      iVar4 = *(int *)(param_1 + 0x24);

      FUN_003b46f0(param_1,DAT_0095ae20);

      DAT_0095ae18 = DAT_0095ae18 + -1;

      param_1 = iVar4;

    }

  }

  return 0;

}
#define FUN_003b0030(...) ((u32 (*)(...))FUN_003b0030)(__VA_ARGS__)
#undef FUN_003b0170
// FUN_003B0170 NONMATCHING


u64 FUN_003b0170(u64 param_1)



{

  char cVar1;

  

  cVar1 = FUN_003b0ec0();

  if (cVar1 == '\0') {

    param_1 = FUN_003b0030(param_1);

  }

  return param_1;

}
#define FUN_003b0170(...) ((u64 (*)(...))FUN_003b0170)(__VA_ARGS__)
#undef FUN_003b01d0
// FUN_003B01D0 NONMATCHING


void FUN_003b01d0(int param_1,int param_2)



{

  char cVar1;

  u8 uVar2;

  u32 uVar3;

  int iVar4;

  int iVar5;

  

  uVar3 = (u32)*(u8 *)(param_1 + 0x15);

  *(u8 *)(param_1 + 0x18) = (&DAT_007cd4f8)[uVar3];

  *(u8 *)(param_1 + 0x19) = (&DAT_007cd4f8)[*(u8 *)(param_1 + 0x15)];

  *(int *)(param_1 + 0xc) = (int)(char)(&DAT_007cd4f8)[*(u8 *)(param_1 + 0x15)];

  if ((((*(u8 *)(param_1 + 0x17) & 1) != 0) &&

      (*(char *)((&DAT_0095acf4)[uVar3 * 8] + 0x16) != '\0')) &&

     (param_2 = param_2 * 2, param_2 < (int)(&DAT_0095acf8)[uVar3 * 8])) {

    cVar1 = *(char *)(*(int *)(&DAT_0095ad00 + uVar3 * 0x20) + 1 + param_2);

    if (cVar1 != '\0') {

      iVar4 = (int)*(char *)(*(int *)(&DAT_0095ad00 + uVar3 * 0x20) + param_2);

      iVar5 = iVar4 * 0x10;

      iVar4 = cVar1 - iVar4;

      param_2 = param_2 >> 1;

      if ((param_2 == 1) || (param_2 == 0x11)) {

        iVar5 = iVar5 + -0x20;

        iVar4 = iVar4 + 4;

      }

      if (param_2 < 0x1c6) {

        iVar4 = iVar4 + 2;

      }

      else {

        iVar4 = iVar4 + 3;

      }

      iVar5 = -iVar5 * (int)(char)(&DAT_007cd4f8)[*(u8 *)(param_1 + 0x15)];

      if (iVar5 < 0) {

        iVar5 = iVar5 + 0x1f;

      }

      *(int *)(param_1 + 4) = iVar5 >> 5;

      iVar4 = iVar4 * (char)(&DAT_007cd4f8)[*(u8 *)(param_1 + 0x15)];

      if (iVar4 < 0) {

        iVar4 = iVar4 + 0x1f;

      }

      *(int *)(param_1 + 0xc) = iVar4 >> 5;

      if (0 < DAT_007ce638) {

        iVar4 = (u32)*(u8 *)(param_1 + 0x18) * DAT_007ce638;

        uVar2 = (u8)(iVar4 >> 7);

        if (iVar4 < 0) {

          uVar2 = (u8)(iVar4 + 0x7f >> 7);

        }

        *(u8 *)(param_1 + 0x18) = uVar2;

        iVar4 = *(int *)(param_1 + 0xc) * DAT_007ce638;

        if (iVar4 < 0) {

          iVar4 = iVar4 + 0x7f;

        }

        *(int *)(param_1 + 0xc) = iVar4 >> 7;

      }

      if (0 < DAT_007ce63c) {

        iVar4 = (u32)*(u8 *)(param_1 + 0x19) * DAT_007ce63c;

        uVar2 = (u8)(iVar4 >> 7);

        if (iVar4 < 0) {

          uVar2 = (u8)(iVar4 + 0x7f >> 7);

        }

        *(u8 *)(param_1 + 0x19) = uVar2;

      }

    }

  }

  return;

}
#define FUN_003b01d0(...) ((void (*)(...))FUN_003b01d0)(__VA_ARGS__)
#undef FUN_003b03a0
// FUN_003B03A0 NONMATCHING


int FUN_003b03a0(void)



{

  int iVar1;

  long lVar2;

  

  lVar2 = FUN_003b4520();

  if (lVar2 == 0) {

    FUN_0019d400(0x6a2830,0x6a2730,0x63f);

  }

  iVar1 = *(int *)((int)lVar2 + 0x14);

  if (iVar1 == 0) {

    FUN_0019d3f0(0x6a2730,0x644);

  }

  *(u16 *)(iVar1 + 4) = 1;

  *(int *)(iVar1 + 8) = (int)lVar2;

  return iVar1;

}
#define FUN_003b03a0(...) ((int (*)(...))FUN_003b03a0)(__VA_ARGS__)
#undef FUN_003b0430
// FUN_003B0430 NONMATCHING


void FUN_003b0430(int param_1,u64 param_2)



{

  u8 bVar1;

  int iVar2;

  u16 *puVar3;

  long lVar4;

  u64 uVar5;

  u64 uVar6;

  u64 unaff_s3;

  u8 auStack_10 [16];

  

  lVar4 = FUN_003b3dd0(param_2,*(u8 *)(param_1 + 0x14));

  if ((lVar4 == 0) || (iVar2 = *(int *)((int)lVar4 + 0x10), iVar2 == 0)) {

    if (lVar4 == 0) {

      bVar1 = *(u8 *)(param_1 + 0x15);

      uVar5 = (*DAT_00960178)(0x200,0x40000);

      FUN_003b4770((&DAT_0095ad0c)[(u32)bVar1 * 8],auStack_10);

      FUN_003b47b0(uVar5,param_2,(&DAT_0095ad0c)[(u32)bVar1 * 8],auStack_10);

      lVar4 = FUN_003b3d60(param_2,uVar5,*(u8 *)(param_1 + 0x14));

      if (lVar4 == 0) {

        FUN_0019d3f0(0x6a2730,0x6c2);

      }

      (*DAT_0096017c)(uVar5);

      unaff_s3 = 0;

    }

    uVar5 = FUN_003b1a10(*(u8 *)(param_1 + 0x15));

    uVar6 = FUN_003b1a40(*(u8 *)(param_1 + 0x15));

    puVar3 = (u16 *)FUN_003b03a0(uVar5,uVar6,unaff_s3,1);

    *puVar3 = (short)param_2;

    *(int *)(puVar3 + 6) = (int)lVar4;

    *(u16 **)((int)lVar4 + 0x10) = puVar3;

    DAT_0095ae10 = DAT_0095ae10 + 1;

  }

  else {

    *(short *)(iVar2 + 4) = *(short *)(iVar2 + 4) + 1;

  }

  return;

}
#define FUN_003b0430(...) ((void (*)(...))FUN_003b0430)(__VA_ARGS__)
#undef FUN_003b05c0
// FUN_003B05C0


void FUN_003b05c0(u16 *param_1)



{

  *(u32 *)(param_1 + 2) = 0;

  *(u32 *)(param_1 + 4) = 0;

  *(u8 *)((int)param_1 + 3) = 0;

  *(u32 *)(param_1 + 6) = 0;

  *(u32 *)(param_1 + 10) = 0;

  *(u8 *)(param_1 + 1) = 0xff;

  *param_1 = 0x20;

  *(u32 *)(param_1 + 0x12) = 0;

  *(u32 *)(param_1 + 0x14) = 0;

  *(u16 **)(param_1 + 0x16) = param_1;

  *(u32 *)(param_1 + 0xe) = 0;

  *(u32 *)(param_1 + 0x10) = 0;

  *(u32 *)(param_1 + 0xc) = 0;

  *(u32 *)(param_1 + 0x18) = 0;

  *(u32 *)(param_1 + 0x1a) = 0;

  *(u32 *)(param_1 + 0x1c) = 0;

  *(u32 *)(param_1 + 0x1e) = 0;

  *(u32 *)(param_1 + 0x20) = 0;

  return;

}
#define FUN_003b05c0(...) ((void (*)(...))FUN_003b05c0)(__VA_ARGS__)
#undef FUN_003b0620
// FUN_003B0620 NONMATCHING


long FUN_003b0620(u16 param_1,u8 param_2,u8 param_3,u8 param_4)



{

  u8 bVar1;

  char cVar2;


  long lVar4;

  u32 uVar5;

  int iVar6;

  u16 *puVar7;

  

  lVar4 = FUN_003b46b0(DAT_0095ae1c);

  DAT_0095ae14 = DAT_0095ae14 + 1;

  if (lVar4 == 0) {

    FUN_0019d400(0x6a2860,0x6a2730,0x743);

  }

  puVar7 = (u16 *)lVar4;

  *puVar7 = param_1;

  *(u8 *)((int)puVar7 + 0x15) = param_2;

  puVar7[2] = 0;

  puVar7[3] = 0;

  puVar7[4] = 0;

  puVar7[5] = 0;

  puVar7[6] = 0;

  puVar7[7] = 0;

  *(u8 *)(puVar7 + 10) = param_3;

  puVar7[8] = 0xff00;

  puVar7[9] = 0xffff;

  *(u8 *)(puVar7 + 0xb) = param_4;

  *(char *)((int)puVar7 + 0x17) = (char)DAT_007cd500;

  puVar7[1] = 0;

  puVar7[0xe] = 0;

  puVar7[0xf] = 0;

  puVar7[0x10] = 0;

  puVar7[0x11] = 0;

  puVar7[0x12] = 0;

  puVar7[0x13] = 0;

  puVar7[0x14] = 0;

  puVar7[0x15] = 0;

  uVar5 = (u32)*puVar7;

  if (uVar5 < 0x80) {

    if (uVar5 == 0x20) {

      iVar6 = 0x1f7;

    }

    else {

      iVar6 = uVar5 - 0x20;

    }

  }

  else {

    iVar6 = ((int)(uVar5 - 0x8080 & 0xff00) >> 1) + (uVar5 - 0x8080 & 0x7f);

  }

  if ((int)(u32)*(u16 *)((&DAT_0095acf4)[(u32)param_2 * 8] + 0xe) <= iVar6) {

    iVar6 = 0x147;

  }

  FUN_003b0430(lVar4,iVar6);
  *(u32 *)(puVar7 + 0xe) = 0;

  FUN_003b01d0(lVar4,iVar6);

  if ((*(u8 *)((int)puVar7 + 0x17) & 0x10) == 0) {

    puVar7[4] = 0;

    puVar7[5] = 0;

  }

  else {

    bVar1 = 0;

    if ((((iVar6 == 0x59) || (iVar6 == 0x51)) || (iVar6 == 0x50)) ||

       (((iVar6 == 0x4a || (iVar6 == 0x47)) || (iVar6 == 0x31)))) {

      bVar1 = 1;

    }

    if (bVar1) {

      cVar2 = '\x10';

    }

    else {

      cVar2 = '\0';

    }

    *(int *)(puVar7 + 4) = (int)cVar2;

  }

  return lVar4;

}
#define FUN_003b0620(...) ((long (*)(...))FUN_003b0620)(__VA_ARGS__)
#undef FUN_003b0840
// FUN_003B0840 NONMATCHING


int FUN_003b0840(short *param_1)



{

  short sVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = 0;

  if ((((*(char *)((int)param_1 + 0x15) == '\0') || (*(char *)((int)param_1 + 0x15) == '\x01')) &&

      (*(short **)(param_1 + 0x12) != (short *)0x0)) &&

     ((((sVar1 = *param_1, sVar1 == -0x7f2b || (sVar1 == -0x7f31)) ||

       ((sVar1 == -0x7f3b || ((sVar1 == -0x7f3f || (sVar1 == 0x75)))))) ||

      ((sVar1 == 0x6f || ((sVar1 == 0x65 || (sVar1 == 0x61)))))))) {

    sVar1 = **(short **)(param_1 + 0x12);

    if (((sVar1 == 0x54) || (sVar1 == -0x7f4c)) && (iVar2 = 3, 0 < iGpffffb948)) {

      iVar3 = iGpffffb948 * 3;

      iVar2 = iVar3 >> 7;

      if (iVar3 < 0) {

        iVar2 = iVar3 + 0x7f >> 7;

      }

    }

    if (((sVar1 == 0x59) || (sVar1 == -0x7f47)) && (iVar2 = 2, 0 < iGpffffb948)) {

      iVar3 = iGpffffb948 * 2;

      iVar2 = iVar3 >> 7;

      if (iVar3 < 0) {

        iVar2 = iVar3 + 0x7f >> 7;

      }

    }

  }

  return iVar2;

}
#define FUN_003b0840(...) ((int (*)(...))FUN_003b0840)(__VA_ARGS__)
#undef FUN_003b0970
// FUN_003B0970 NONMATCHING


long FUN_003b0970(long param_1,u8 param_2,u8 param_3,u8 param_4,long param_5)



{

  u8 bVar1;

  u32 uVar2;

  int iVar3;

  long lVar4;

  u16 uVar5;

  int iVar6;

  u32 uVar7;

  int iVar8;

  

  uVar2 = 0;

  if (-1 < (char)param_2) {

    bGpffffb950 = param_2;

  }

  if ((&DAT_0095ad0c)[(u32)bGpffffb950 * 8] == 0) {

    param_5 = 0;

  }

  else {

    if (param_1 != 0) {

      uVar2 = FUN_00524388(param_1);

    }

    if (param_5 == 0) {

      param_5 = FUN_003b46b0(DAT_0095ae20);

      DAT_0095ae18 = DAT_0095ae18 + 1;

      if (param_5 == 0) {

        FUN_0019d3f0(0x6a2730,0x7da);

      }

      FUN_003b05c0(param_5);

    }

    iVar3 = 0;

    iVar8 = (int)param_5;

    iVar6 = *(int *)(iVar8 + 0x20);

    for (uVar7 = 0; uVar7 < uVar2; uVar7 = uVar7 + 1) {

      bVar1 = *(u8 *)((int)param_1 + uVar7);

      uVar5 = (u16)bVar1;

      if (0x7f < uVar5) {

        uVar7 = uVar7 + 1;

        uVar5 = CONCAT11(bVar1,*(u8 *)((int)param_1 + uVar7));

      }

      iVar3 = FUN_003b0620(uVar5,bGpffffb950,param_3,param_4);

      if (iVar6 == 0) {

        *(int *)(iVar8 + 0x1c) = iVar3;

      }

      else {

        *(int *)(iVar6 + 0x28) = iVar3;

      }

      if (iVar3 == 0) {

        FUN_0019d3f0(0x6a2730,0x7ef);

      }

      *(int *)(iVar3 + 0x24) = iVar6;

      *(int *)(iVar8 + 0xc) = *(int *)(iVar8 + 0xc) + *(int *)(iVar3 + 0xc);

      *(int *)(iVar8 + 0x18) = *(int *)(iVar8 + 0x18) + 1;

      lVar4 = FUN_003b0840(iVar3);

      if (lVar4 != 0) {

        iVar6 = *(int *)(iVar3 + 0x24);

        if (iVar6 != 0) {

          *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) - (int)lVar4;

        }

        *(int *)(iVar8 + 0xc) = *(int *)(iVar8 + 0xc) - (int)lVar4;

      }

      iVar6 = iVar3;

    }

    if (iVar3 != 0) {

      *(int *)(iVar8 + 0x20) = iVar3;

      *(u16 *)(iVar8 + 0x10) = (u16)*(u8 *)(iVar3 + 0x18);

      *(u16 *)(iVar8 + 0x12) = (u16)*(u8 *)(iVar3 + 0x19);

    }

  }

  return param_5;

}
#define FUN_003b0970(...) ((long (*)(...))FUN_003b0970)(__VA_ARGS__)
#undef FUN_003b0bb0
// FUN_003B0BB0


void FUN_003b0bb0(int param_1,u8 param_2)



{

  if (param_1 == 0) {
    FUN_0019d3f0(DAT_006a2730,0x818);

  }

  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {

    *(u8 *)(param_1 + 2) = param_2;

  }

  return;

}
#define FUN_003b0bb0(...) ((void (*)(...))FUN_003b0bb0)(__VA_ARGS__)
#undef FUN_003b0c20
// FUN_003B0C20 NONMATCHING


void FUN_003b0c20(long param_1,u16 param_2)



{

  if (param_1 == 0) {

    FUN_0019d3f0(0x6a2730,0x82c);

  }

  *(u16 *)param_1 = param_2;

  return;

}
#define FUN_003b0c20(...) ((void (*)(...))FUN_003b0c20)(__VA_ARGS__)
#undef FUN_003b0c70
// FUN_003B0C70

void FUN_003b0c70(FrFontNode *node)
{
  FrFontNode *iter;

  node->enabled = 1;
  iter = node;
  if (node == NULL) {
    FUN_0019d3f0(DAT_006a2730, 0x818);
  }
  for (; iter != NULL; iter = iter->next) {
    iter->unknown_00[2] = 0xff;
  }
}
#define FUN_003b0c70(...) ((void (*)(...))FUN_003b0c70)(__VA_ARGS__)
#undef FUN_003b0ce0
// FUN_003B0CE0


void FUN_003b0ce0(int param_1,u8 param_2)



{

  int iVar1;

  

  if (param_1 == 0) {
    FUN_0019d3f0(DAT_006a2730,0x877);

  }

  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {

    for (iVar1 = *(int *)(param_1 + 0x1c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x28)) {

      *(u8 *)(iVar1 + 0x15) = param_2;

    }

  }

  return;

}
#define FUN_003b0ce0(...) ((void (*)(...))FUN_003b0ce0)(__VA_ARGS__)
#undef FUN_003b0d70
// FUN_003B0D70 NONMATCHING


void FUN_003b0d70(long param_1,u32 param_2,u32 param_3)



{

  if (param_1 == 0) {

    FUN_0019d3f0(0x6a2730,0x88c);

  }

  *(u32 *)((int)param_1 + 4) = param_2;

  *(u32 *)((int)param_1 + 8) = param_3;

  return;

}





#undef FUN_003b0e04
#pragma optimization_level 3
// FUN_003B0DD0 thunk_FUN_003b0e04
void thunk_FUN_003b0e04(int param_1, u8 param_2)
{
  FUN_003b0e04(param_1, param_2);
}
#pragma optimization_level 2
// FUN_003B0DD8
asm void FUN_003b0dd8(int param_1, u8 param_2)
{
  .set noreorder
  .word 0x8c83001c
  .word 0x10000003
  .word 0x00000000
  .word 0xa0650014
  .word 0x8c630028
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000
  .word 0x1460fffa
  .word 0x00000000
  .word 0x8c840024
}

#define FUN_003b0d70(...) ((void (*)(...))FUN_003b0d70)(__VA_ARGS__)
#undef FUN_003b0e04
// FUN_003B0E04
asm void FUN_003b0e04(int param_1, u8 param_2)
{
  .set noreorder
  .word 0x1480fff4
  .word 0x00000000
  .word 0x03e00008
  .word 0x00000000
}





#undef FUN_003b0e54
#pragma optimization_level 3
// FUN_003B0E20 thunk_FUN_003b0e54
void thunk_FUN_003b0e54(int param_1, u32 param_2)
{
  FUN_003b0e54(param_1, param_2);
}
#pragma optimization_level 2
// FUN_003B0E28
asm void FUN_003b0e28(int param_1, u32 param_2)
{
  .set noreorder
  .word 0x8c83001c
  .word 0x10000003
  .word 0x00000000
  .word 0xac650010
  .word 0x8c630028
  .word 0x00000000
  .word 0x00000000
  .word 0x00000000
  .word 0x1460fffa
  .word 0x00000000
  .word 0x8c840024
}

#define FUN_003b0e04(...) ((void (*)(...))FUN_003b0e04)(__VA_ARGS__)
#undef FUN_003b0e54
// FUN_003B0E54
asm void FUN_003b0e54(int param_1, u32 param_2)
{
  .set noreorder
  .word 0x1480fff4
  .word 0x00000000
  .word 0x03e00008
  .word 0x00000000
}
#define FUN_003b0e54(...) ((void (*)(...))FUN_003b0e54)(__VA_ARGS__)
#undef FUN_003b0e70
// FUN_003B0E70


u16 FUN_003b0e70(s16 param_1)



{

  u16 uVar1;

  

  uVar1 = uGpffffa810;

  uGpffffa810 = uGpffffa810 | param_1;

  return uVar1;

}
#define FUN_003b0e70(...) ((u16 (*)(...))FUN_003b0e70)(__VA_ARGS__)
#undef FUN_003b0e90
// FUN_003B0E90

u16 FUN_003b0e90(u16 param_1)
{
  __asm__ volatile (
      ".set noreorder                 \n"
      "lh $a1, -0x57f0($gp)           \n"
      "andi $v0, $a1, 0xffff          \n"
      "andi $v1, $a0, 0xffff          \n"
      "not $v1, $v1                   \n"
      "dsll32 $v1, $v1, 0x10          \n"
      "dsra32 $v1, $v1, 0x10          \n"
      "and $v1, $a1, $v1              \n"
      "sh $v1, -0x57f0($gp)           \n"
      ".set reorder"
      :
      :
      : "a1", "v0", "v1", "memory"
  );
}
#define FUN_003b0e90(...) ((u16 (*)(...))FUN_003b0e90)(__VA_ARGS__)
#undef FUN_003b0ec0
// FUN_003B0EC0 NONMATCHING


u32 FUN_003b0ec0(int param_1)



{

  u32 uVar1;

  u32 uVar2;

  int iVar3;

  

  uVar1 = 0;

  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x24)) {

    for (iVar3 = *(int *)(param_1 + 0x1c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x28)) {

      if (*(char *)(iVar3 + 0x16) == '\x02') {

        uVar2 = *(u32 *)(iVar3 + 0x10) & 0xff;

        if (uVar2 != 0) {

          uVar2 = uVar2 - 8;

          if ((int)uVar2 < 0) {

            uVar2 = 0;

          }

          *(u32 *)(iVar3 + 0x10) = *(u32 *)(iVar3 + 0x10) & 0xffffff00 | uVar2;

          *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 0x10;

          uVar1 = 1;

        }

      }

    }

  }

  return uVar1;

}
#define FUN_003b0ec0(...) ((u32 (*)(...))FUN_003b0ec0)(__VA_ARGS__)
#undef FUN_003b0f50
// FUN_003B0F50 NONMATCHING


int FUN_003b0f50(int param_1,u16 *param_2,u8 param_3,u32 param_4)



{

  int iVar1;

  int iVar2;

  u32 uVar3;

  u8 bVar4;

  u8 bVar5;

  long lVar6;

  char cVar7;

  u8 bVar8;

  u32 *puVar9;

  int iVar10;

  u32 uVar11;

  

  iVar10 = 0;

  bVar4 = 0;

  bVar8 = 0xff;

  cVar7 = '\0';

  bVar5 = 1;

  if (*(int *)(param_2 + 0x12) == 0) {

    if ((*(int *)(param_1 + 0x24) != 0) &&

       (iVar1 = *(int *)(*(int *)(param_1 + 0x24) + 0x20), iVar1 != 0)) {

      bVar8 = *(u8 *)(iVar1 + 0x10);

      cVar7 = *(char *)(iVar1 + 0x16);

    }

  }

  else {

    bVar8 = *(u8 *)(*(int *)(param_2 + 0x12) + 0x10);

  }

  if ((param_3 != 0) && (*param_2 < 0x80)) {

    param_3 = param_3 + 0x14;

  }

  puVar9 = (u32 *)(param_2 + 8);

  if ((cVar7 == '\0') || (cVar7 == (char)param_2[0xb])) {

    if (param_3 <= bVar8) {

      bVar4 = 1;

    }

  }

  else if (bVar8 == 0xff) {

    bVar4 = 1;

  }

  iVar1 = *(int *)(param_1 + 0x24);

  if (((iVar1 != 0) && (*(u16 **)(param_1 + 0x1c) == param_2)) && (*(int *)(param_1 + 0x40) == 0)

     ) {

    iVar2 = *(int *)(iVar1 + 0x30);

    if (iVar2 == 0xf247) {

      iVar2 = *(int *)(iVar1 + 0x3c);

      if (iVar2 == -1) {

        lVar6 = FUN_0010a500(2);

        if (lVar6 != 0) {

          bVar4 = 0;

        }

      }

      else if (0 < iVar2) {

        bVar4 = 0;

        *(int *)(iVar1 + 0x3c) = iVar2 + -1;

      }

    }

    else if (iVar2 == 0xf215) {

      iVar2 = *(int *)(iVar1 + 0x3c);

      if (iVar2 == -1) {

        lVar6 = FUN_0010a500(2);

        if (lVar6 != 0) {

          bVar4 = 0;

        }

      }

      else if (0 < iVar2) {

        bVar4 = 0;

        *(int *)(iVar1 + 0x3c) = iVar2 + -1;

      }

    }

    else if (((iVar2 == 0xf214) && (0 < *(int *)(iVar1 + 0x3c))) && (bVar4 = 0, bVar8 == 0xff))

    {

      *(int *)(iVar1 + 0x3c) = *(int *)(iVar1 + 0x3c) + -1;

    }

  }

  if ((*(int *)(param_1 + 0x34) == 0xf117) && (*(char *)(*(int *)(param_1 + 0x20) + 0x10) == -1)) {

    if ((*(int *)(param_1 + 0x38) == 0) && (0 < *(int *)(param_1 + 0x3c))) {

      if (*(int *)(param_1 + 0x3c) == 0xffff) {

        lVar6 = FUN_0035ae90();

        if (lVar6 != 0) {

          bVar5 = 0;

        }

      }

      else {

        bVar5 = 0;

      }

    }

    if (bVar5) {

      *(u32 *)(param_1 + 0x34) = 0;

    }

  }

  if (bVar4) {

    if ((param_4 & 0xff) < 0xff) {

      uVar11 = (u32)((float)((param_4 & 0xff) << 5) /

                     (float)(*(int *)(param_2 + 6) + (int)*(char *)(param_1 + 3)));

    }

    else {

      uVar11 = 0xff;

    }

    if ((int)uVar11 < 0x100) {

      uVar11 = uVar11 & 0xff;

    }

    else {

      uVar11 = 0xff;

    }

    uVar3 = *puVar9;

    if (0xff - (uVar3 & 0xff) < uVar11) {

      *puVar9 = uVar3 & 0xffffff00 | 0xff;

    }

    else {

      *puVar9 = uVar3 + uVar11;

    }

  }

  if (((char)*puVar9 != -1) && ((char)param_2[0xb] == '\x01')) {

    iVar10 = (((u32)param_2[1] << 1) % 5 - 2) * -0x10;

  }

  return iVar10;

}
#define FUN_003b0f50(...) ((int (*)(...))FUN_003b0f50)(__VA_ARGS__)
#undef FUN_003b1300
#undef FUN_003b1330
#undef FUN_003b1360
// FUN_003B1300


void FUN_003b1300(u64 param_1)



{

  FUN_003b1330(param_1,0);

  return;

}
// FUN_003B1330


void FUN_003b1330(u64 param_1,u64 param_2)



{

  FUN_003b1360(param_1,param_2,uGpffffb940);

  return;

}
#define FUN_003b1300(...) ((void (*)(...))FUN_003b1300)(__VA_ARGS__)
#define FUN_003b1330(...) ((void (*)(...))FUN_003b1330)(__VA_ARGS__)
#undef FUN_003b1360
// FUN_003B1360 NONMATCHING


int FUN_003b1360(long param_1,u64 param_2,u32 param_3)



{

  char cVar1;

  u8 *puVar2;

  int iVar3;

  int iVar4;

  u8 bVar5;

  int iVar6;

  long lVar7;

  int iVar8;

  int iVar9;

  

  iVar9 = 0;

  bVar5 = 1;

  if ((uGpffffa810 & 0x40) == 0) {

    (*DAT_00960090)(6,1);

    (*DAT_00960090)(7,2);

    (*DAT_00960090)(9,2);

    (*DAT_00960090)(0xc,1);

    (*DAT_00960090)(10,5);

    (*DAT_00960090)(0xb,6);

    (*DAT_00960090)(2,4);

    (*DAT_00960090)(0xe,0);

    FUN_004d7f60(2,0x44);

    FUN_004d7f60(3,0x5100d);

  }

  if (param_1 == 0) {

    iVar9 = 0;

  }

  else {

    for (puVar2 = *(u8 **)((int)param_1 + 0x2c); puVar2 != (u8 *)0x0;

        puVar2 = *(u8 **)(puVar2 + 0x28)) {

      iVar8 = *(int *)(puVar2 + 4);

      iVar3 = *(int *)(puVar2 + 8);

      cVar1 = puVar2[3];

      for (iVar4 = *(int *)(puVar2 + 0x1c); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x28)) {

        if (param_2 == '\0') {

          iVar6 = FUN_003b0f50(puVar2,iVar4,*puVar2,puVar2[2]);

        }

        else {

          iVar6 = 0;

        }

        FUN_003b38f0(*(u32 *)(puVar2 + 0x14),iVar6 + iVar8 + *(int *)(iVar4 + 4),

                     iVar3 + *(int *)(iVar4 + 8),iVar4,*(u8 *)(iVar4 + 0x14),

                     *(u8 *)(iVar4 + 0x18),*(u8 *)(iVar4 + 0x19),

                     *(u32 *)(iVar4 + 0x10));

        if (*(char *)(iVar4 + 0x10) != '\0') {

          *(short *)(iVar4 + 2) = *(short *)(iVar4 + 2) + 1;

        }

        if (*(char *)(iVar4 + 0x10) != -1) {

          bVar5 = 0;

        }

        iVar8 = iVar8 + (*(int *)(iVar4 + 0xc) + (int)cVar1) * 0x10;

      }

      if ((*(int *)(puVar2 + 0x28) == 0) && (*(int *)(puVar2 + 0x40) == 0)) {

        iVar8 = *(int *)(puVar2 + 0x30);

        if (iVar8 == 0xf247) {

          lVar7 = FUN_0010a500(2);

          if (lVar7 == 0) {

            iVar8 = *(int *)(puVar2 + 0x3c);

            if ((iVar8 != -1) && (0 < iVar8)) {

              *(int *)(puVar2 + 0x3c) = iVar8 + -1;

              bVar5 = 0;

            }

          }

          else {

            bVar5 = 0;

          }

        }

        else if (iVar8 == 0xf246) {

          iVar8 = *(int *)(puVar2 + 0x3c);

          if ((iVar8 != -1) && (0 < iVar8)) {

            *(int *)(puVar2 + 0x3c) = iVar8 + -1;

            bVar5 = 0;

          }

        }

        else if (iVar8 == 0xf215) {

          lVar7 = FUN_0010a500(2);

          if (lVar7 == 0) {

            iVar8 = *(int *)(puVar2 + 0x3c);

            if ((iVar8 != -1) && (0 < iVar8)) {

              *(int *)(puVar2 + 0x3c) = iVar8 + -1;

              bVar5 = 0;

            }

          }

          else {

            bVar5 = 0;

          }

        }

        else if (((iVar8 == 0xf214) && (bVar5)) && (0 < *(int *)(puVar2 + 0x3c))) {

          *(int *)(puVar2 + 0x3c) = *(int *)(puVar2 + 0x3c) + -1;

          bVar5 = 0;

        }

      }

      iVar9 = iVar9 + *(int *)(puVar2 + 0x18);

    }

    if (iGpffffb944 < 1) {

      if (!bVar5) {

        iVar9 = 0;

      }

    }

    else {

      iGpffffb944 = iGpffffb944 + -1;

      iVar9 = 0;

    }

  }

  return iVar9;

}
#define FUN_003b1360(...) ((int (*)(...))FUN_003b1360)(__VA_ARGS__)
#undef FUN_003b1710
// FUN_003B1710 NONMATCHING


int FUN_003b1710(long param_1)



{

  int iVar1;

  u8 bVar2;

  long lVar3;

  int iVar4;

  int iVar5;

  

  bVar2 = 1;

  iVar4 = 0;

  if (param_1 == 0) {

    iVar4 = 0;

  }

  else {

    for (iVar5 = *(int *)((int)param_1 + 0x2c); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x28)) {

      if ((*(int *)(iVar5 + 0x28) == 0) && (*(int *)(iVar5 + 0x40) == 0)) {

        iVar1 = *(int *)(iVar5 + 0x30);

        if (iVar1 == 0xf247) {

          lVar3 = FUN_0010a500(2);

          if (lVar3 == 0) {

            if ((*(int *)(iVar5 + 0x3c) != -1) && (0 < *(int *)(iVar5 + 0x3c))) {

              bVar2 = 0;

            }

          }

          else {

            bVar2 = 0;

          }

        }

        else if (iVar1 == 0xf246) {

          iVar1 = *(int *)(iVar5 + 0x3c);

          if ((iVar1 != -1) && (0 < iVar1)) {

            *(int *)(iVar5 + 0x3c) = iVar1 + -1;

            bVar2 = 0;

          }

        }

        else if (iVar1 == 0xf215) {

          lVar3 = FUN_0010a500(2);

          if (lVar3 == 0) {

            if ((*(int *)(iVar5 + 0x3c) != -1) && (0 < *(int *)(iVar5 + 0x3c))) {

              bVar2 = 0;

            }

          }

          else {

            bVar2 = 0;

          }

        }

        else if (((iVar1 == 0xf214) && (bVar2)) && (0 < *(int *)(iVar5 + 0x3c))) {

          bVar2 = 0;

        }

      }

      iVar4 = iVar4 + *(int *)(iVar5 + 0x18);

    }

    if (!bVar2) {

      iVar4 = 0;

    }

  }

  return iVar4;

}
#define FUN_003b1710(...) ((int (*)(...))FUN_003b1710)(__VA_ARGS__)
#undef FUN_003b18c0
// FUN_003B18C0 NONMATCHING


u64 FUN_003b18c0(void)



{

  u32 uVar1;

  u32 uVar2;

  

  uVar1 = FUN_0035aea0();

  uVar2 = FUN_003b0030((&DAT_0095ae60)[uVar1 & 0xff]);

  (&DAT_0095ae60)[uVar1 & 0xff] = uVar2;

  FUN_003b3770();

  return 0;

}
#define FUN_003b18c0(...) ((u64 (*)(...))FUN_003b18c0)(__VA_ARGS__)
#undef FUN_003b1920
// FUN_003B1920 NONMATCHING


long FUN_003b1920(long param_1,long param_2,int param_3)



{

  long lVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = (int)param_2;

  iVar2 = (int)param_1;

  lVar1 = param_2;

  if ((param_1 != 0) && (lVar1 = param_1, param_2 != 0)) {

    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar3 + 0x2c);

    *(int *)(*(int *)(iVar3 + 0x2c) + 0x24) = iVar2;

    *(u32 *)(iVar3 + 0x2c) = *(u32 *)(iVar2 + 0x2c);

    lVar1 = param_2;

    if (param_3 == 1) {

      *(int *)(iVar3 + 4) = *(int *)(iVar2 + 4) + *(int *)(iVar2 + 0xc) * 0x10;

      *(u32 *)(iVar3 + 8) = *(u32 *)(iVar2 + 8);

    }

  }

  return lVar1;

}
#define FUN_003b1920(...) ((long (*)(...))FUN_003b1920)(__VA_ARGS__)
#undef FUN_003b19a0
// FUN_003B19A0 NONMATCHING


void FUN_003b19a0(u64 param_1)



{

  FUN_003afad0(8,param_1,0);

  return;

}
#define FUN_003b19a0(...) ((void (*)(...))FUN_003b19a0)(__VA_ARGS__)
#undef FUN_003b19d0
// FUN_003B19D0

int FUN_003b19d0(FrFontNode *node)
{
  int total = 0;
  FrFontGlyph *glyph;

  for (glyph = node->glyphs; glyph != NULL; glyph = glyph->next) {
    total += glyph->advance;
    total += node->line_height;
  }
  return total;
}
#define FUN_003b19d0(...) ((int (*)(...))FUN_003b19d0)(__VA_ARGS__)
#undef FUN_003b1a10
// FUN_003B1A10 NONMATCHING


u16 FUN_003b1a10(u32 param_1)



{
  u32 *base = (u32 *)0x0095acf4;
  u32 *entry = base + ((param_1 & 0xff) * 8);
  return *(u16 *)((u8 *)entry + 0x10);

}
#define FUN_003b1a10(...) ((u16 (*)(...))FUN_003b1a10)(__VA_ARGS__)
#undef FUN_003b1a40
// FUN_003B1A40 NONMATCHING


u16 FUN_003b1a40(u32 param_1)



{
  u32 *base = (u32 *)0x0095acf4;
  u32 *entry = base + ((param_1 & 0xff) * 8);
  return *(u16 *)((u8 *)entry + 0x12);

}
#define FUN_003b1a40(...) ((u16 (*)(...))FUN_003b1a40)(__VA_ARGS__)
#undef FUN_003b1a70
// FUN_003B1A70


void FUN_003b1a70(void)



{

  uGpffffa800 = 0x19;

  return;

}
#define FUN_003b1a70(...) ((void (*)(...))FUN_003b1a70)(__VA_ARGS__)
#undef FUN_003b1a80
// FUN_003B1A80


void FUN_003b1a80(u32 param_1)



{

  uGpffffa800 = param_1;

  return;

}
#define FUN_003b1a80(...) ((void (*)(...))FUN_003b1a80)(__VA_ARGS__)
#undef FUN_003b1a90
// FUN_003B1A90 NONMATCHING


int FUN_003b1a90(long param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = 0;

  if (param_1 != 0) {

    for (iVar1 = *(int *)((int)param_1 + 0x2c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x28)) {

      for (iVar3 = iVar1; (iVar3 != 0 && (*(int *)(iVar3 + 8) < *(int *)(iVar1 + 8) + 100));

          iVar3 = *(int *)(iVar3 + 0x28)) {

      }

      iVar2 = iVar2 + 1;

    }

  }

  return iVar2;

}
#define FUN_003b1a90(...) ((int (*)(...))FUN_003b1a90)(__VA_ARGS__)
#undef FUN_003b1b00
// FUN_003B1B00 NONMATCHING


int FUN_003b1b00(int param_1,long param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  iVar2 = 0;

  if (param_2 == 0) {

    iVar2 = 0;

  }

  else {

    iVar5 = 0;

    for (iVar1 = *(int *)((int)param_2 + 0x2c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x28)) {

      iVar2 = 0;

      for (iVar6 = iVar1; (iVar6 != 0 && (*(int *)(iVar6 + 8) < *(int *)(iVar1 + 8) + 100));

          iVar6 = *(int *)(iVar6 + 0x28)) {

        iVar3 = 0;

        for (iVar4 = *(int *)(iVar6 + 0x1c); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x28)) {

          iVar3 = iVar3 + *(int *)(iVar4 + 0xc) + (int)*(char *)(iVar6 + 3);

        }

        iVar2 = iVar2 + iVar3;

      }

      if (iVar5 == param_1) break;

      iVar5 = iVar5 + 1;

    }

    iVar2 = iVar2 << 4;

  }

  return iVar2;

}
#define FUN_003b1b00(...) ((int (*)(...))FUN_003b1b00)(__VA_ARGS__)
#undef FUN_003b1bc0
// FUN_003B1BC0 NONMATCHING


void FUN_003b1bc0(u32 *param_1,int param_2,long param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  if (param_3 != 0) {

    iVar2 = 0;

    for (iVar1 = *(int *)((int)param_3 + 0x2c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x28)) {

      *param_1 = *(u32 *)(iVar1 + 4);

      param_1[1] = *(u32 *)(iVar1 + 8);

      for (iVar3 = iVar1; (iVar3 != 0 && (*(int *)(iVar3 + 8) < *(int *)(iVar1 + 8) + 100));

          iVar3 = *(int *)(iVar3 + 0x28)) {

      }

      if (iVar2 == param_2) {

        return;

      }

      iVar2 = iVar2 + 1;

    }

  }

  return;

}
#define FUN_003b1bc0(...) ((void (*)(...))FUN_003b1bc0)(__VA_ARGS__)
#undef FUN_003b1c40
// FUN_003B1C40 NONMATCHING


void FUN_003b1c40(int param_1,int param_2,long param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  if (param_3 != 0) {

    iVar3 = *(int *)((int)param_3 + 0x2c);

    iVar1 = *(int *)(iVar3 + 4);

    iVar2 = *(int *)(iVar3 + 8);

    for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x28)) {

      *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + (param_1 - iVar1);

      *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + (param_2 - iVar2);

    }

  }

  return;

}
#define FUN_003b1c40(...) ((void (*)(...))FUN_003b1c40)(__VA_ARGS__)
#undef FUN_003b1c90
// FUN_003B1C90 NONMATCHING


void FUN_003b1c90(int param_1,int param_2,long param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  

  if (param_3 != 0) {

    iVar6 = *(int *)((int)param_3 + 0x2c);

    iVar1 = *(int *)(iVar6 + 8);

    while (iVar6 != 0) {

      iVar3 = 0;

      iVar2 = *(int *)(iVar6 + 8);

      for (iVar7 = iVar6; (iVar7 != 0 && (*(int *)(iVar7 + 8) < iVar2 + 100));

          iVar7 = *(int *)(iVar7 + 0x28)) {

        iVar5 = 0;

        for (iVar4 = *(int *)(iVar7 + 0x1c); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x28)) {

          iVar5 = iVar5 + *(int *)(iVar4 + 0xc) + (int)*(char *)(iVar7 + 3);

        }

        iVar3 = iVar3 + iVar5;

      }

      iVar7 = *(int *)(iVar6 + 4);

      if (iVar3 < 0) {

        iVar3 = iVar3 + 1;

      }

      for (; (iVar6 != 0 && (*(int *)(iVar6 + 8) < iVar2 + 100)); iVar6 = *(int *)(iVar6 + 0x28)) {

        iVar4 = *(int *)(iVar6 + 4) + (param_1 - iVar7);

        *(int *)(iVar6 + 4) = iVar4;

        *(int *)(iVar6 + 4) = iVar4 + (iVar3 >> 1) * -0x10;

        *(int *)(iVar6 + 8) = *(int *)(iVar6 + 8) + (param_2 - iVar1);

      }

    }

  }

  return;

}
#define FUN_003b1c90(...) ((void (*)(...))FUN_003b1c90)(__VA_ARGS__)
#undef FUN_003b1d90
// FUN_003B1D90 NONMATCHING


void FUN_003b1d90(u32 param_1,int param_2)



{

  char cVar1;

  u8 uVar2;

  int iVar3;

  u8 *pbVar4;

  int iVar5;

  int iVar6;

  u32 uVar7;

  long lVar8;

  u8 *pbVar9;

  u8 *pbVar10;

  int iVar11;

  int iVar12;

  char cVar13;

  int iVar14;

  u8 abStack_4 [4];

  

  iVar3 = *(int *)(&DAT_0095ac70 + (param_1 & 0xff) * 4);

  pbVar9 = (u8 *)0x3;

  pbVar10 = abStack_4;

  pbVar4 = pbVar10;

  while (pbVar4 != (u8 *)0x0) {

    *pbVar10 = 0;

    pbVar10 = pbVar10 + 1;

    pbVar9 = pbVar9 + -1;

    pbVar4 = pbVar9;

  }

  if (iVar3 != 0) {

    iVar5 = FUN_00524388(iVar3);

    cVar13 = *(char *)(param_2 + 0xc);

    for (iVar14 = 0; iVar14 < iVar5; iVar14 = iVar14 + 1) {

      abStack_4[0] = *(u8 *)(iVar3 + iVar14);

      abStack_4[1] = 0;

      if (0x7f < abStack_4[0]) {

        iVar14 = iVar14 + 1;

        abStack_4[1] = *(u8 *)(iVar3 + iVar14);

      }

      cVar1 = *(char *)(param_2 + 0xc);

      if (cVar1 != cVar13) {

        iVar6 = *(int *)(param_2 + 0x14);

        if (iVar6 == 0) {

          lVar8 = FUN_003b0970(&gp0xffffa838,0,*(u8 *)(param_2 + 0xd),

                               *(u8 *)(param_2 + 0xe),0);

          if (lVar8 == 0) {

            uVar7 = 0;

          }

          else {

            uVar7 = FUN_003b1920(0,lVar8,1);

          }

          *(u32 *)(param_2 + 0x14) = uVar7;

        }

        else if (*(int *)(iVar6 + 0x1c) != 0) {

          lVar8 = FUN_003b0970(&gp0xffffa838,0,*(u8 *)(param_2 + 0xd),

                               *(u8 *)(param_2 + 0xe),0);

          if (lVar8 != 0) {

            iVar6 = FUN_003b1920(iVar6,lVar8,1);

          }

          *(int *)(param_2 + 0x14) = iVar6;

        }

        uVar2 = *(u8 *)(param_2 + 0xf);

        iVar6 = *(int *)(param_2 + 0x14);

        if (iVar6 == 0) {

          FUN_0019d3f0(0x6a2730,0x818);

        }

        for (; cVar13 = cVar1, iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x24)) {

          *(u8 *)(iVar6 + 2) = uVar2;

        }

      }

      lVar8 = FUN_003b0970(abStack_4,cVar1,*(u8 *)(param_2 + 0xd),

                           *(u8 *)(param_2 + 0xe),*(u32 *)(param_2 + 0x14));

      uVar2 = uGpffffa7fc;

      iVar6 = (int)lVar8;

      *(int *)(param_2 + 0x14) = iVar6;

      if (lVar8 == 0) {

        FUN_0019d3f0(0x6a2730,0x848);

      }

      *(u8 *)(iVar6 + 3) = uVar2;

      iVar11 = 0;

      for (iVar12 = *(int *)(iVar6 + 0x1c); iVar12 != 0; iVar12 = *(int *)(iVar12 + 0x28)) {

        iVar11 = iVar11 + *(int *)(iVar12 + 0xc) + (int)*(char *)(iVar6 + 3);

      }

      *(int *)(iVar6 + 0xc) = iVar11;

    }

  }

  return;

}
#define FUN_003b1d90(...) ((void (*)(...))FUN_003b1d90)(__VA_ARGS__)
#undef FUN_003b2020
// FUN_003B2020 NONMATCHING


void FUN_003b2020(long param_1,int param_2)



{

  char cVar1;

  u8 uVar2;

  u8 *pbVar3;

  int iVar4;

  int iVar5;

  u32 uVar6;

  long lVar7;

  u8 *pbVar8;

  u8 *pbVar9;

  int iVar10;

  int iVar11;

  char cVar12;

  int iVar13;

  u8 abStack_4 [4];

  

  pbVar8 = (u8 *)0x3;

  pbVar9 = abStack_4;

  pbVar3 = pbVar9;

  while (pbVar3 != (u8 *)0x0) {

    *pbVar9 = 0;

    pbVar9 = pbVar9 + 1;

    pbVar8 = pbVar8 + -1;

    pbVar3 = pbVar8;

  }

  if (param_1 != 0) {

    iVar4 = FUN_00524388(param_1);

    cVar12 = *(char *)(param_2 + 0xc);

    for (iVar13 = 0; iVar13 < iVar4; iVar13 = iVar13 + 1) {

      abStack_4[0] = *(u8 *)((int)param_1 + iVar13);

      abStack_4[1] = 0;

      if (0x7f < abStack_4[0]) {

        iVar13 = iVar13 + 1;

        abStack_4[1] = *(u8 *)((int)param_1 + iVar13);

      }

      cVar1 = *(char *)(param_2 + 0xc);

      if (cVar1 != cVar12) {

        iVar5 = *(int *)(param_2 + 0x14);

        if (iVar5 == 0) {

          lVar7 = FUN_003b0970(&gp0xffffa838,0,*(u8 *)(param_2 + 0xd),

                               *(u8 *)(param_2 + 0xe),0);

          if (lVar7 == 0) {

            uVar6 = 0;

          }

          else {

            uVar6 = FUN_003b1920(0,lVar7,1);

          }

          *(u32 *)(param_2 + 0x14) = uVar6;

        }

        else if (*(int *)(iVar5 + 0x1c) != 0) {

          lVar7 = FUN_003b0970(&gp0xffffa838,0,*(u8 *)(param_2 + 0xd),

                               *(u8 *)(param_2 + 0xe),0);

          if (lVar7 != 0) {

            iVar5 = FUN_003b1920(iVar5,lVar7,1);

          }

          *(int *)(param_2 + 0x14) = iVar5;

        }

        uVar2 = *(u8 *)(param_2 + 0xf);

        iVar5 = *(int *)(param_2 + 0x14);

        if (iVar5 == 0) {

          FUN_0019d3f0(0x6a2730,0x818);

        }

        for (; cVar12 = cVar1, iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x24)) {

          *(u8 *)(iVar5 + 2) = uVar2;

        }

      }

      lVar7 = FUN_003b0970(abStack_4,cVar1,*(u8 *)(param_2 + 0xd),

                           *(u8 *)(param_2 + 0xe),*(u32 *)(param_2 + 0x14));

      uVar2 = uGpffffa7fc;

      iVar5 = (int)lVar7;

      *(int *)(param_2 + 0x14) = iVar5;

      if (lVar7 == 0) {

        FUN_0019d3f0(0x6a2730,0x848);

      }

      *(u8 *)(iVar5 + 3) = uVar2;

      iVar10 = 0;

      for (iVar11 = *(int *)(iVar5 + 0x1c); iVar11 != 0; iVar11 = *(int *)(iVar11 + 0x28)) {

        iVar10 = iVar10 + *(int *)(iVar11 + 0xc) + (int)*(char *)(iVar5 + 3);

      }

      *(int *)(iVar5 + 0xc) = iVar10;

    }

  }

  return;

}
#define FUN_003b2020(...) ((void (*)(...))FUN_003b2020)(__VA_ARGS__)
#undef FUN_003b22a0
// FUN_003B22A0 NONMATCHING


void FUN_003b22a0(u32 *param_1)



{

  u8 uVar1;

  u16 uVar2;

  u16 *puVar3;

  u32 uVar4;

  u32 uVar5;

  int iVar6;

  long lVar7;

  

  if ((param_1[5] != 0) && (*(int *)(param_1[5] + 0x1c) == 0)) {

    *(u8 *)(param_1 + 7) = 0;

  }

  if (*(char *)(param_1 + 7) != '\0') {

    iVar6 = param_1[5];

    lVar7 = FUN_003b0970(&gp0xffffa838,0,*(u8 *)((int)param_1 + 0xd),

                         *(u8 *)((int)param_1 + 0xe),0);

    if (lVar7 != 0) {

      iVar6 = FUN_003b1920(iVar6,lVar7,1);

    }

    param_1[5] = iVar6;

    uVar1 = *(u8 *)((int)param_1 + 0xf);

    if (iVar6 == 0) {

      FUN_0019d3f0(0x6a2730,0x818);

    }

    for (; iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x24)) {

      *(u8 *)(iVar6 + 2) = uVar1;

    }

    uVar2 = *(u16 *)((int)param_1 + 0x1e);

    puVar3 = (u16 *)param_1[5];

    if (puVar3 == (u16 *)0x0) {

      FUN_0019d3f0(0x6a2730,0x82c);

    }

    *puVar3 = uVar2;

    *(u8 *)(param_1 + 7) = 0;

  }

  if (*(char *)((int)param_1 + 0x1d) != '\0') {

    uVar4 = param_1[1];

    uVar5 = *param_1;

    iVar6 = param_1[5];

    if (iVar6 == 0) {

      FUN_0019d3f0(0x6a2730,0x88c);

    }

    *(u32 *)(iVar6 + 4) = uVar5;

    *(u32 *)(iVar6 + 8) = uVar4;

    *(u8 *)((int)param_1 + 0x1d) = 0;

  }

  return;

}
#define FUN_003b22a0(...) ((void (*)(...))FUN_003b22a0)(__VA_ARGS__)
#undef FUN_003b2400
// FUN_003B2400

void FUN_003b2400(FrFontState *state)
{
  __asm__ volatile (
      ".set noreorder                 \n"
      "lw $v1, -0x5800($gp)           \n"
      "sll $a1, $v1, 3                \n"
      "lw $v1, 4($a0)                 \n"
      "addu $v1, $v1, $a1             \n"
      "sw $v1, 4($a0)                 \n"
      "addiu $v1, $zero, 1            \n"
      "sb $v1, 0x1c($a0)              \n"
      "sb $v1, 0x1d($a0)              \n"
      ".set reorder"
      :
      :
      : "a1", "v1", "memory"
  );
}
#define FUN_003b2400(...) ((void (*)(...))FUN_003b2400)(__VA_ARGS__)
#undef FUN_003b2430
// FUN_003B2430 NONMATCHING


u32 FUN_003b2430(u64 param_1)



{

  u8 bVar1;

  u8 bVar2;

  u16 uVar3;

  u16 *puVar4;

  u32 uVar5;

  int iVar6;

  u8 bVar7;

  u32 uVar8;

  long lVar9;

  int iVar10;

  int iVar11;

  u32 *puVar12;

  u32 uVar13;

  u8 bStack_4;

  u8 uStack_3;

  u8 uStack_2;

  

  puVar12 = (u32 *)param_1;

  if (((*(u8 *)puVar12[4] & 0xf0) != 0xf0) && (((u8 *)puVar12[4])[1] == 8)) {

    puVar12[6] = puVar12[6] + 4;

  }

  uGpffffa7f8 = uGpffffa7f8 & 0xffffff00;

  uGpffffa810 = uGpffffa810 & 0xfffd | 1;

  do {

    while( 1 ) {

      iVar10 = puVar12[6];

      puVar12[6] = iVar10 + 1;

      bVar2 = *(u8 *)(puVar12[4] + iVar10);

      uVar13 = (u32)bVar2;

      if (uVar13 == 0) goto LAB_003b28b8;

      if ((uVar13 & 0xf0) == 0xf0) break;

      if (uVar13 == 10) {

        if ((uGpffffa810 & 4) != 0) {

          puVar12[1] = puVar12[1] + iGpffffa800 * 8;

          *(u8 *)(puVar12 + 7) = 1;

          *(u8 *)((int)puVar12 + 0x1d) = 1;

        }

      }

      else {

        if ((puVar12[5] != 0) && (*(int *)(puVar12[5] + 0x1c) == 0)) {

          *(u8 *)(puVar12 + 7) = 0;

        }

        if (*(char *)(puVar12 + 7) != '\0') {

          uVar8 = puVar12[5];

          lVar9 = FUN_003b0970(&gp0xffffa838,0,*(u8 *)((int)puVar12 + 0xd),

                               *(u8 *)((int)puVar12 + 0xe),0);

          if (lVar9 != 0) {

            uVar8 = FUN_003b1920(uVar8,lVar9,1);

          }

          puVar12[5] = uVar8;

          FUN_003b0bb0(uVar8,*(u8 *)((int)puVar12 + 0xf));

          uVar3 = *(u16 *)((int)puVar12 + 0x1e);

          puVar4 = (u16 *)puVar12[5];

          if (puVar4 == (u16 *)0x0) {

            FUN_0019d3f0(0x6a2730,0x82c);

          }

          *puVar4 = uVar3;

          *(u8 *)(puVar12 + 7) = 0;

        }

        if (*(char *)((int)puVar12 + 0x1d) != '\0') {

          uVar8 = puVar12[1];

          uVar5 = *puVar12;

          iVar10 = puVar12[5];

          if (iVar10 == 0) {

            FUN_0019d3f0(0x6a2730,0x88c);

          }

          *(u32 *)(iVar10 + 4) = uVar5;

          *(u32 *)(iVar10 + 8) = uVar8;

          *(u8 *)((int)puVar12 + 0x1d) = 0;

        }

        bStack_4 = bVar2;

        if (bVar2 < 0x80) {

          if (uVar13 == 0x20) {

            bStack_4 = 0x83;

            uStack_3 = 0xf7;

            uStack_2 = 0;

          }

          else {

            uStack_3 = 0;

          }

          uVar8 = FUN_003b0970(&bStack_4,*(u8 *)(puVar12 + 3),

                               *(u8 *)((int)puVar12 + 0xd),

                               *(u8 *)((int)puVar12 + 0xe),puVar12[5]);

          puVar12[5] = uVar8;

        }

        else {

          iVar10 = puVar12[6];

          puVar12[6] = iVar10 + 1;

          uStack_3 = *(u8 *)(puVar12[4] + iVar10);

          if (CONCAT11(bVar2,uStack_3) < 0xc080) {

            uStack_2 = 0;

            uVar8 = FUN_003b0970(&bStack_4,*(u8 *)(puVar12 + 3),

                                 *(u8 *)((int)puVar12 + 0xd),

                                 *(u8 *)((int)puVar12 + 0xe),puVar12[5]);

            puVar12[5] = uVar8;

          }

          else {

            iVar10 = CONCAT11(bVar2,uStack_3) - 0x4000;

            bStack_4 = (u8)((u32)iVar10 >> 8);

            uStack_3 = (u8)iVar10;

            uStack_2 = 0;

            uVar8 = FUN_003b0970(&bStack_4,8,*(u8 *)((int)puVar12 + 0xd),

                                 *(u8 *)((int)puVar12 + 0xe),puVar12[5]);

            puVar12[5] = uVar8;

          }

        }

        iVar10 = (char)(&gp0xffffa808)[*(u8 *)(puVar12 + 3)] * -2;

        if (iVar10 < 0) {

          iVar10 = iVar10 + 0x1f;

        }

        iVar6 = puVar12[5];

        if (iVar6 == 0) {

          FUN_0019d3f0(0x6a2730,0x848);

        }

        *(char *)(iVar6 + 3) = (char)(iVar10 >> 5);

        iVar11 = 0;

        for (iVar10 = *(int *)(iVar6 + 0x1c); iVar10 != 0; iVar10 = *(int *)(iVar10 + 0x28)) {

          iVar11 = iVar11 + *(int *)(iVar10 + 0xc) + (int)*(char *)(iVar6 + 3);

        }

        *(int *)(iVar6 + 0xc) = iVar11;

        uVar13 = puVar12[2];

        iVar10 = puVar12[5];

        if (iVar10 == 0) {

          FUN_0019d3f0(0x6a2730,0x8a5);

        }

        *(u32 *)(iVar10 + 0x14) = uVar13 >> 4;

      }

    }

    iVar10 = puVar12[6];

    puVar12[6] = iVar10 + 1;

    bVar1 = *(u8 *)(puVar12[4] + iVar10);

    if (0x4c < bVar1) {

      FUN_0019d3f0(0x6a2730,0xdf9);

    }

    if (bVar1 < 2) {

      FUN_0019d3f0(0x6a2730,0xdfa);

    }

    lVar9 = (**(code **)(&DAT_006a2370 + (u32)bVar1 * 4))(CONCAT11(bVar2,bVar1),param_1);

    puVar12[6] = puVar12[6] + (((int)((uVar13 & 0xf) << 8) >> 8) + -1) * 2;

    if (lVar9 == 0) {

      if (*(char *)(puVar12 + 7) == '\0') {

        *(u8 *)(puVar12 + 7) = 1;

      }

      bVar7 = 0;

    }

    else {

      bVar7 = 1;

    }

  } while (!bVar7);

LAB_003b28b8:

  uGpffffa810 = uGpffffa810 & 0xfffe | 2;

  return puVar12[5];

}
#define FUN_003b2430(...) ((u32 (*)(...))FUN_003b2430)(__VA_ARGS__)
#undef FUN_003b2900
// FUN_003B2900 NONMATCHING


void FUN_003b2900(u64 param_1,u64 param_2,u64 param_3)



{

  FUN_003b2990(param_1,param_2,0,0,0,0,0xff,param_3);

  return;

}
#define FUN_003b2900(...) ((void (*)(...))FUN_003b2900)(__VA_ARGS__)
#undef FUN_003b2940
// FUN_003B2940 NONMATCHING


void FUN_003b2940(u64 param_1,u64 param_2,u64 param_3,u64 param_4,

                 u64 param_5,u64 param_6,u64 param_7)



{

  FUN_003b2990(param_1,param_2,0,param_3,param_4,param_5,param_6,param_7);

  return;

}
#define FUN_003b2940(...) ((void (*)(...))FUN_003b2940)(__VA_ARGS__)
#undef FUN_003b2990
// FUN_003B2990 NONMATCHING


void FUN_003b2990(u32 param_1,u32 param_2,int param_3,u8 param_4,

                 u8 param_5,u8 param_6,u8 param_7,u32 param_8,

                 u32 param_9)



{

  u32 uStack_20;

  u32 uStack_1c;

  int iStack_18;

  u8 uStack_14;

  u8 uStack_13;

  u8 uStack_12;

  u8 uStack_11;

  u32 uStack_10;

  u32 uStack_c;

  u32 uStack_8;

  u8 uStack_4;

  u8 uStack_3;

  u16 uStack_2;

  

  iStack_18 = param_3 << 4;

  uStack_c = param_9;

  uStack_8 = 0;

  uStack_4 = 1;

  uStack_3 = 1;

  uStack_2 = 0x20;

  uStack_20 = param_1;

  uStack_1c = param_2;

  uStack_14 = param_4;

  uStack_13 = param_5;

  uStack_12 = param_6;

  uStack_11 = param_7;

  uStack_10 = param_8;

  FUN_003b2430(&uStack_20);

  return;

}
#define FUN_003b2990(...) ((void (*)(...))FUN_003b2990)(__VA_ARGS__)
#undef FUN_003b2a00
// FUN_003B2A00


u32 FUN_003b2a00(u32 param_1)



{

  return uGpffffa7f8 & param_1;

}
#define FUN_003b2a00(...) ((u32 (*)(...))FUN_003b2a00)(__VA_ARGS__)
#undef FUN_003b2a10
// FUN_003B2A10 NONMATCHING


void FUN_003b2a10(int param_1,u32 param_2)



{
  u32 *base = (u32 *)0x0095ac70;
  u32 *entry = base + param_1;
  *entry = param_2;

  return;

}
#define FUN_003b2a10(...) ((void (*)(...))FUN_003b2a10)(__VA_ARGS__)
#undef FUN_003b2a30
// FUN_003B2A30 NONMATCHING


u64 FUN_003b2a30(u64 param_1,u32 param_2)



{

  u8 bVar1;

  u8 bVar2;

  int iVar3;

  u8 bVar4;

  long lVar5;

  u32 uVar6;

  int iVar7;

  u32 uVar8;

  

  iVar7 = (int)param_1;

  if (((**(u8 **)(iVar7 + 0x10) & 0xf0) != 0xf0) && ((*(u8 **)(iVar7 + 0x10))[1] == 8)) {

    *(int *)(iVar7 + 0x18) = *(int *)(iVar7 + 0x18) + 4;

  }

  uGpffffa7f8 = uGpffffa7f8 & 0xffffffc0;

  do {

    while( 1 ) {

      iVar3 = *(int *)(iVar7 + 0x18);

      *(int *)(iVar7 + 0x18) = iVar3 + 1;

      bVar2 = *(u8 *)(*(int *)(iVar7 + 0x10) + iVar3);

      uVar6 = (u32)bVar2;

      if (uVar6 == 0) {

        return 0;

      }

      if ((uVar6 & 0xf0) == 0xf0) break;

      if ((uVar6 != 10) && (0x7f < uVar6)) {

        *(int *)(iVar7 + 0x18) = *(int *)(iVar7 + 0x18) + 1;

      }

    }

    lVar5 = 0;

    iVar3 = *(int *)(iVar7 + 0x18);

    *(int *)(iVar7 + 0x18) = iVar3 + 1;

    bVar1 = *(u8 *)(*(int *)(iVar7 + 0x10) + iVar3);

    uVar8 = (u32)CONCAT11(bVar2,bVar1);

    if ((param_2 != 0) && (uVar8 == param_2)) {

      lVar5 = (**(code **)(&DAT_006a2370 + (u32)bVar1 * 4))(uVar8,param_1);

    }

    *(int *)(iVar7 + 0x18) = *(int *)(iVar7 + 0x18) + (((int)((uVar6 & 0xf) << 8) >> 8) + -1) * 2;

    if (lVar5 == 0) {

      if (((uVar8 == 0xf131) || (uVar8 == 0xf110)) || (uVar8 == 0xf104)) {

        bVar4 = 1;

      }

      else {

        bVar4 = 0;

      }

    }

    else {

      bVar4 = 1;

    }

  } while (!bVar4);

  return 0;

}
#define FUN_003b2a30(...) ((u64 (*)(...))FUN_003b2a30)(__VA_ARGS__)
#undef FUN_003b2bf0
// FUN_003B2BF0 NONMATCHING


u8 FUN_003b2bf0(u32 param_1,u32 param_2,u64 param_3)



{

  u8 uVar1;

  u32 uStack_20;

  u32 uStack_1c;

  u32 uStack_18;

  u8 uStack_14;

  u8 uStack_13;

  u8 uStack_12;

  u8 uStack_11;

  u32 uStack_10;

  u32 uStack_c;

  u32 uStack_8;

  u8 uStack_4;

  u8 uStack_3;

  u16 uStack_2;

  

  uStack_20 = 0;

  uStack_1c = 0;

  uStack_18 = 0;

  uStack_14 = 0;

  uStack_13 = 0;

  uStack_12 = 0;

  uStack_11 = 0;

  uStack_8 = 0;

  uStack_4 = 1;

  uStack_3 = 1;

  uStack_2 = 0x20;

  uStack_10 = param_1;

  uStack_c = param_2;

  uVar1 = FUN_003b2a30(&uStack_20,param_3);

  return uVar1;

}
#define FUN_003b2bf0(...) ((u8 (*)(...))FUN_003b2bf0)(__VA_ARGS__)
