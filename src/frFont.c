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

typedef struct FrFontGlyphLayout {
  u8 pad0[0xc];
  int width;
  u8 pad10[0x18];
  struct FrFontGlyphLayout *next;
} FrFontGlyphLayout;

typedef struct FrFontLineLayout {
  u8 pad0[3];
  s8 spacing;
  int x;
  int y;
  u8 pad0c[0x10];
  FrFontGlyphLayout *glyphs;
  u8 pad20[8];
  struct FrFontLineLayout *next;
  struct FrFontLineLayout *line;
} FrFontLineLayout;

typedef struct FrFontSlot {
  void *resource;
  void *font_data;
  u32 block0_size;
  u32 block1_size;
  void *block0;
  void *block1;
  u32 flags;
  void *object;
} FrFontSlot;

typedef struct FrFontManagerData {
  FrFontSlot slots[9];
  u8 unknown_120[0x64];
  void *allocations[9];
} FrFontManagerData;

extern u32 DAT_006a2370;
extern const char DAT_006a2730[];
extern const char DAT_006a27a0[];
extern const char DAT_006a27d0[];
extern const char DAT_006a2800[];
extern u8 DAT_006a2830[];
extern u32 DAT_007cd4f8;
#pragma alias DAT_007cd4f8_abs DAT_007cd4f8
extern u8 DAT_007cd4f8_abs[];
extern s16 DAT_007cd500;
extern s32 DAT_007ce638;
extern s32 DAT_007ce63c;
extern u32 DAT_0095ac70;
#pragma alias DAT_0095ac70_abs DAT_0095ac70
extern u32 DAT_0095ac70_abs[];
extern u32 DAT_0095acf0;
#pragma alias DAT_0095acf0_abs DAT_0095acf0
extern u32 DAT_0095acf0_abs[];
#pragma alias gFrFontManagerData_abs DAT_0095acf0
extern FrFontManagerData gFrFontManagerData_abs[];
extern u32 DAT_0095acf4;
#pragma alias DAT_0095acf4_abs DAT_0095acf4
extern u32 DAT_0095acf4_abs[];
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
#pragma alias DAT_0095ae10_abs DAT_0095ae10
extern u32 DAT_0095ae10_abs[];
extern u32 DAT_0095ae14;
#pragma alias DAT_0095ae14_abs DAT_0095ae14
extern u32 DAT_0095ae14_abs[];
extern u32 DAT_0095ae18;
#pragma alias DAT_0095ae18_abs DAT_0095ae18
extern u32 DAT_0095ae18_abs[];
extern u32 DAT_0095ae1c;
#pragma alias DAT_0095ae1c_abs DAT_0095ae1c
extern u32 DAT_0095ae1c_abs[];
extern u32 DAT_0095ae20;
extern u32 DAT_0095ae24;
extern u32 DAT_0095ae28;
extern u32 DAT_0095ae60;
extern u32 DAT_0095ae64;
#pragma alias DAT_0095ae20_abs DAT_0095ae20
extern u8 DAT_0095ae20_abs[];
#pragma alias DAT_0095ae24_abs DAT_0095ae24
extern u8 DAT_0095ae24_abs[];
#pragma alias DAT_0095ae28_abs DAT_0095ae28
extern u8 DAT_0095ae28_abs[];
#pragma alias DAT_0095ae60_abs DAT_0095ae60
extern u8 DAT_0095ae60_abs[];
#pragma alias DAT_0095ae64_abs DAT_0095ae64
extern u8 DAT_0095ae64_abs[];
extern const char DAT_006a2710[];
extern u32 DAT_0095ae74;
extern code DAT_00960090;
#pragma alias DAT_00960090_abs DAT_00960090
extern code DAT_00960090_abs[];
extern code DAT_00960178;
extern code DAT_0096017c;
#pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];
extern u32 LAB_003b28b8;
extern u8 bGpffffb950;
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
void FUN_003afad0(int param_1,int param_2,int param_3);
#pragma alias FUN_003afad0_typed FUN_003afad0
extern void FUN_003afad0_typed(u32 param_1,u64 param_2,u32 param_3);
void FUN_003afc30(u32 param_1);
void FUN_003afc70(void);
void FUN_003afe30(void);
void FUN_003aff50(void);
u64 FUN_003affd0(u64 param_1);
u32 FUN_003b0030(int param_1);
#pragma alias FUN_003b0030_u64 FUN_003b0030
extern u64 FUN_003b0030_u64(u64 param_1);
u64 FUN_003b0170(u64 param_1);
void FUN_003b01d0(int param_1,int param_2);
int FUN_003b03a0(void);
#pragma alias FUN_003b03a0_typed FUN_003b03a0
extern u16 *FUN_003b03a0_typed(u32 param_1,u32 param_2,u32 param_3,u32 param_4);
#pragma alias FUN_003b1a10_typed FUN_003b1a10
extern u32 FUN_003b1a10_typed(u32 param_1);
#pragma alias FUN_003b1a40_typed FUN_003b1a40
extern u32 FUN_003b1a40_typed(u32 param_1);
void FUN_003b0430(int param_1,u32 param_2);
#pragma alias FUN_003b0430_typed FUN_003b0430
extern void FUN_003b0430_typed(int param_1,u32 param_2);
#pragma alias FUN_003b01d0_typed FUN_003b01d0
u8 *FUN_003b0970(u8 *param_1,u8 param_2,u8 param_3,u8 param_4,u8 *param_5);
#pragma alias FUN_003b0970_typed FUN_003b0970
extern long FUN_003b0970_typed(void *param_1,u8 param_2,u8 param_3,u8 param_4,u32 param_5);
void FUN_003b05c0(u16 *param_1);
int FUN_003b0620(u16 param_1,u8 param_2,u8 param_3,u8 param_4);
#pragma alias FUN_003b0620_typed FUN_003b0620
extern int FUN_003b0620_typed(u16 param_1,u8 param_2,u8 param_3,u8 param_4);
int FUN_003b0840(short *param_1);
void FUN_003b0bb0(int param_1,u8 param_2);
#pragma alias FUN_003b0bb0_typed FUN_003b0bb0
extern void FUN_003b0bb0_typed(int param_1,u8 param_2);
void FUN_003b0c20(u32 param_1,u16 param_2);
void FUN_003b0c70(FrFontNode *node);
void FUN_003b0ce0(int param_1,u8 param_2);
void FUN_003b0d70(int param_1,u32 param_2,u32 param_3);
void FUN_003b0e04(int param_1,u8 param_2);
void FUN_003b0e54(int param_1,u32 param_2);
u16 FUN_003b0e70(s16 param_1);
u16 FUN_003b0e90(u16 param_1);
u32 FUN_003b0ec0(int param_1);
int FUN_003b0f50(u8 *param_1,u16 *param_2,u8 param_3,u32 param_4);
void FUN_003b1300(void *param_1);
void FUN_003b1330(void *param_1,u32 param_2);
int FUN_003b1360(void *param_1,u32 param_2,u32 param_3);
int FUN_003b1710(long param_1);
u64 FUN_003b18c0(void);
int FUN_003b1920(int param_1,int param_2,int param_3);
#pragma alias FUN_003b1920_typed FUN_003b1920
extern int FUN_003b1920_typed(int param_1,int param_2,int param_3);
void FUN_003b19a0(u64 param_1);
int FUN_003b19d0(FrFontNode *node);
u16 FUN_003b1a10(u32 param_1);
u16 FUN_003b1a40(u32 param_1);
void FUN_003b1a70(void);
void FUN_003b1a80(u32 param_1);
int FUN_003b1a90(int param_1);
int FUN_003b1b00(int param_1,int param_2);
void FUN_003b1bc0(u32 *param_1,int param_2,int param_3);
void FUN_003b1c40(int param_1,int param_2,int param_3);
void FUN_003b1c90(int param_1,int param_2,FrFontLineLayout *param_3);
void FUN_003b1d90(u32 param_1,int param_2);
void FUN_003b2020(int param_1,int param_2);
void FUN_003b22a0(u32 *param_1);
void FUN_003b2400(FrFontState *state);
u32 FUN_003b2430(void *param_1);
void FUN_003b2900(u32 param_1,u32 param_2,u32 param_3,u32 param_4);
void FUN_003b2940(u32 param_1,u32 param_2,u32 param_3,u32 param_4,  u32 param_5,u32 param_6,u32 param_7,u32 param_8);
void FUN_003b2990(u32 param_1,u32 param_2,int param_3,u8 param_4,  u8 param_5,u8 param_6,u8 param_7,u32 param_8,  u32 param_9);
u32 FUN_003b2a00(u32 param_1);
void FUN_003b2a10(int param_1,u32 param_2);
u64 FUN_003b2a30(void *param_1,u32 param_2);
s8 FUN_003b2bf0(u32 param_1,u32 param_2,u32 param_3);

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

#define FUN_003afa40(...) ((void (*)(...))FUN_003afa40)(__VA_ARGS__)
#undef FUN_003afad0
/* W389 residual: register-coloring/address-expression floor after recovering the real block-pointer form (candidate id uses $a0 vs retail $a1; final slot/data temporaries also differ). Baseline nd=10/object=348/window=352; six-knob singles stayed nd=10 except common-subs off, which exceeded the window at nd=73/object=356; declaration swap was neutral; pair sweep had no win. */
// FUN_003AFAD0 NONMATCHING


void FUN_003afad0(int slot_id, int font_data, int resource)



{

  u8 id;
  FrFontSlot *slot;
  u8 *data;
  int offset;

  if ((font_data == 0) && (resource != 0)) {
    font_data = resource;
  }
  if (font_data == 0) {
    FUN_0019d3f0(DAT_006a2730, 0x3ff);
  }

  id = slot_id;
  slot = &gFrFontManagerData_abs[0].slots[id];
  if (id >= 9) {
    FUN_0035ac50(DAT_006a27a0);
  }

  slot->resource = (void *)resource;
  slot->font_data = (void *)font_data;
  data = (u8 *)font_data;
  offset = *(u32 *)data + data[10] * 0x40;
  if (data[0x16] != 0) {
    slot->block0_size = *(u32 *)(data + offset);
    slot->block0 = data + (offset + 4);
    offset += slot->block0_size + 4;
    slot->block1_size = *(u32 *)(data + offset);
    slot->block1 = data + (offset + 4);
    offset += slot->block1_size + 4;
  } else {
    slot->block0_size = 0;
    slot->block0 = NULL;
    slot->block1_size = 0;
    slot->block1 = NULL;
  }

  slot->flags = (u32)(data + offset);
  FUN_005225a8(DAT_006a27d0, data + offset, offset,
               *(u16 *)((u8 *)slot->font_data + 0xe));
  slot->object = (u8 *)slot->font_data + offset +
                 *(u16 *)((u8 *)slot->font_data + 0xe) * 4;
}
#define FUN_003afad0(...) ((void (*)(...))FUN_003afad0)(__VA_ARGS__)
#undef FUN_003afc30
// FUN_003AFC30


void FUN_003afc30(u32 param_1)



{

  DAT_0096017c_abs[0](DAT_0095acf0_abs[(param_1 & 0xff) * 8]);

  return;

}
#define FUN_003afc30(...) ((void (*)(...))FUN_003afc30)(__VA_ARGS__)
#undef FUN_003afc70
/* W340 loop probe: opt_propagation off; without nd=279/object=392, with nd=247/object=400; window=448. */
#pragma opt_propagation off
/* W389 pragma: opt_lifetimes on; without nd=247/object=400, with nd=246/object=400; window=448. */
#pragma push
#pragma opt_lifetimes on
// FUN_003AFC70 NONMATCHING


void FUN_003afc70(void)



{

  u32 uVar1;

  u32 uVar2;

  u32 uVar3;

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

    FUN_003afad0_typed(0,0,uVar3);

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
#pragma pop
#pragma opt_lifetimes reset
#define FUN_003afc70(...) ((void (*)(...))FUN_003afc70)(__VA_ARGS__)
#pragma opt_propagation reset
#undef FUN_003afe30
/* W340 loop probe: opt_loop_invariants on; without nd=61/object=284, with nd=2/object=288; window=288. */
#pragma opt_loop_invariants on
// FUN_003AFE30


void FUN_003afe30(void)
{
  s32 i;
  s32 checkedIndex;
  u8 slotIndex;
  FrFontSlot *slot;

  for (i = 0; i < 9; i++) {
    slot = &gFrFontManagerData_abs[0].slots[i];
    if (slot->object != NULL) {
      checkedIndex = (u8)i;
      if (checkedIndex >= 9) {
        FUN_0035ac50(DAT_006a27a0, checkedIndex);
      }

      slotIndex = (u8)i;
      slot = &gFrFontManagerData_abs[0].slots[slotIndex];
      if (slot->object == NULL) {
        FUN_0019d3f0(DAT_006a2730, 0x432);
      }

      if (gFrFontManagerData_abs[0].allocations[(u8)i] != NULL) {
        FUN_00100ec0(gFrFontManagerData_abs[0].allocations[(u8)i]);
        gFrFontManagerData_abs[0].allocations[(u8)i] = NULL;
        FUN_005225a8(DAT_006a2800, checkedIndex);
        slot->resource = NULL;
        slot->object = NULL;
      }
        slot->flags = 0;
    }
  }
}
#define FUN_003afe30(...) ((void (*)(...))FUN_003afe30)(__VA_ARGS__)
#pragma opt_loop_invariants reset
#undef FUN_003aff50
// FUN_003AFF50 MATCHING


void FUN_003aff50(void)



{

  int iVar1;

  int iVar2;

  

  for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {

    for (iVar1 = 0; iVar1 < 0x10; iVar1 = iVar1 + 1) {

    }

    FUN_005225a8(DAT_006a2710,DAT_006a2730);

  }

  return;

}

#define FUN_003aff50(...) ((void (*)(...))FUN_003aff50)(__VA_ARGS__)
#undef FUN_003affd0
// FUN_003AFFD0 MATCHING


u64 FUN_003affd0(u64 param_1)



{

  char cVar1;
  u64 uVar2;


  

  cVar1 = FUN_003b0ec0_direct();

  if (cVar1 != '\0') {
    uVar2 = param_1;
  }
  else {
    uVar2 = FUN_003b0030_u64(param_1);
  }

  return uVar2;

}
#define FUN_003affd0(...) ((u64 (*)(...))FUN_003affd0)(__VA_ARGS__)
#undef FUN_003b0030
// FUN_003B0030


u32 FUN_003b0030(int param_1)



{

  int iVar4;

  int iVar1;
  int next_list;

  int iVar2;

  u32 *puVar3;

  
  if (param_1 == 0) {
    return param_1;
  }

    while (param_1 != 0) {

      iVar4 = *(int *)(param_1 + 0x1c);

      while (iVar4 != 0) {

        iVar1 = *(int *)(iVar4 + 0x28);

        if (*(int *)(iVar4 + 0x20) == 0) {

          *(u16 *)(*(int *)(iVar4 + 0x1c) + 4) = *(u16 *)(*(int *)(iVar4 + 0x1c) + 4) + -1;

          iVar2 = *(int *)(iVar4 + 0x1c);

          if ((iVar2 != 0) && (*(u16 *)(iVar2 + 4) == 0)) {

            puVar3 = *(u32 **)(iVar2 + 0xc);

            if (puVar3 != (u32 *)0x0) {

              *puVar3 = *puVar3 & 0xfffffffe;

              puVar3[4] = 0;

            }

            FUN_003b4580(*(u32 *)(iVar2 + 8));

            DAT_0095ae10_abs[0] = DAT_0095ae10_abs[0] + -1;

          }

        }

        FUN_003b46f0(iVar4,DAT_0095ae1c_abs[0]);

        iVar4 = iVar1;

        DAT_0095ae14_abs[0] = DAT_0095ae14_abs[0] + -1;

      }

      next_list = *(int *)(param_1 + 0x24);

      FUN_003b46f0(param_1,*(u32 *)DAT_0095ae20_abs);

      param_1 = next_list;

      DAT_0095ae18_abs[0] = DAT_0095ae18_abs[0] + -1;

    }


  return 0;

}
#define FUN_003b0030(...) ((u32 (*)(...))FUN_003b0030)(__VA_ARGS__)
#undef FUN_003b0170
// FUN_003B0170 MATCHING


u64 FUN_003b0170(u64 param_1)



{

  char cVar1;
  u64 uVar2;


  

  cVar1 = FUN_003b0ec0_direct();

  if (cVar1 != '\0') {
    uVar2 = param_1;
  }
  else {
    uVar2 = FUN_003b0030_u64(param_1);
  }

  return uVar2;

}
#define FUN_003b0170(...) ((u64 (*)(...))FUN_003b0170)(__VA_ARGS__)
#undef FUN_003b01d0
/* W340 loop probe: opt_lifetimes on; without nd=205/object=448, with nd=200/object=448; window=464. */
#pragma opt_lifetimes on
/* W340 loop probe: opt_propagation off; without nd=205/object=448, with nd=156/object=440; window=464. */
#pragma opt_propagation off
// FUN_003B01D0 NONMATCHING


void FUN_003b01d0(int param_1,int param_2)



{

  char cVar1;
  u32 uVar3;
  int iVar4;
  int iVar5;
  FrFontSlot *slot;

  

  uVar3 = (u32)*(u8 *)(param_1 + 0x15);
  slot = &gFrFontManagerData_abs[0].slots[uVar3];

  *(u8 *)(param_1 + 0x18) = ((s8 *)&DAT_007cd4f8)[uVar3];

  *(u8 *)(param_1 + 0x19) = ((s8 *)&DAT_007cd4f8)[*(u8 *)(param_1 + 0x15)];

  *(int *)(param_1 + 0xc) = ((s8 *)&DAT_007cd4f8)[*(u8 *)(param_1 + 0x15)];

  if ((((*(u8 *)(param_1 + 0x17) & 1) != 0) &&

      (*((u8 *)slot->font_data + 0x16) != 0)) &&

     (param_2 = param_2 * 2, param_2 < (int)slot->block0_size)) {

    cVar1 = *((s8 *)slot->block0 + 1 + param_2);

    if (cVar1 != '\0') {

      iVar4 = (int)*((s8 *)slot->block0 + param_2);

      iVar5 = iVar4 * 0x10;

      iVar4 = cVar1 - iVar4;

      param_2 = param_2 >> 1;

      switch (param_2 + 0x20) {
      case 0x31:
      case 0x21:
        iVar5 -= 0x20;
        iVar4 += 4;
        break;
      }

      if (param_2 < 0x1c6) {

        iVar4 = iVar4 + 2;

      }

      else {

        iVar4 = iVar4 + 3;

      }

      iVar5 = -iVar5 * ((s8 *)&DAT_007cd4f8)[*(u8 *)(param_1 + 0x15)];

      if (iVar5 < 0) {

        iVar5 = iVar5 + 0x1f;

      }

      *(int *)(param_1 + 4) = iVar5 >> 5;

      iVar4 = iVar4 * ((s8 *)&DAT_007cd4f8)[*(u8 *)(param_1 + 0x15)];

      if (iVar4 < 0) {

        iVar4 = iVar4 + 0x1f;

      }

      *(int *)(param_1 + 0xc) = iVar4 >> 5;

      if (0 < DAT_007ce638) {

        iVar4 = (u32)*(u8 *)(param_1 + 0x18) * DAT_007ce638;

        if (iVar4 < 0) {

          iVar4 = iVar4 + 0x7f;

        }

        *(u8 *)(param_1 + 0x18) = iVar4 >> 7;

        iVar4 = *(int *)(param_1 + 0xc) * DAT_007ce638;

        if (iVar4 < 0) {

          iVar4 = iVar4 + 0x7f;

        }

        *(int *)(param_1 + 0xc) = iVar4 >> 7;

      }

      if (0 < DAT_007ce63c) {

        iVar4 = (u32)*(u8 *)(param_1 + 0x19) * DAT_007ce63c;

        if (iVar4 < 0) {

          iVar4 = iVar4 + 0x7f;

        }

        *(u8 *)(param_1 + 0x19) = iVar4 >> 7;

      }

    }

  }

  return;

}
#define FUN_003b01d0(...) ((void (*)(...))FUN_003b01d0)(__VA_ARGS__)
#pragma opt_propagation reset
#pragma opt_lifetimes reset
#undef FUN_003b03a0
// FUN_003B03A0


int FUN_003b03a0(void)



{

  int iVar1;
  int lVar2;

  

  lVar2 = FUN_003b4520();

  if (lVar2 == 0) {

    FUN_0019d400(DAT_006a2830, DAT_006a2730, 0x63f);

  }

  iVar1 = *(int *)((int)lVar2 + 0x14);

  if (iVar1 == 0) {

    FUN_0019d3f0("frFont.c",0x644);

  }

  *(u16 *)(iVar1 + 4) = 1;

  *(int *)(iVar1 + 8) = (int)lVar2;

  return iVar1;

}
#define FUN_003b03a0(...) ((int (*)(...))FUN_003b03a0)(__VA_ARGS__)
#undef FUN_003b0430
/* W415 typed-call census closure: nd 230 -> 211, object 396/400 -> 372/400. */
/* W419 declaration sweep negative: 21 pair swaps; 18 stayed nd211/object372/window400/rate0.567204 and 3 reached nd212/object372/window400/rate0.569892. */
// FUN_003B0430 NONMATCHING


void FUN_003b0430(int param_1,u32 param_2)



{

  u8 bVar1;

  int iVar2;

  u16 *puVar3;

  u32 lVar4;

  u32 uVar5;

  u32 uVar6;

  u32 unaff_s3;

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

        FUN_0019d3f0("frFont.c",0x6c2);

      }

      (*DAT_0096017c)(uVar5);

      unaff_s3 = 0;

    }

    uVar5 = FUN_003b1a10_typed(*(u8 *)(param_1 + 0x15));

    uVar6 = FUN_003b1a40_typed(*(u8 *)(param_1 + 0x15));

    puVar3 = FUN_003b03a0_typed(uVar5,uVar6,unaff_s3,1);

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
/* W340 loop probe: opt_common_subs off; without nd=276/object=496, with nd=264/object=524; window=544. */
#pragma opt_common_subs off
// FUN_003B0620 NONMATCHING

int FUN_003b0620(u16 param_1,u8 param_2,u8 param_3,u8 param_4)
{
  u16 uVar5;
  int iVar6;
  u8 *puVar7;

  puVar7 = (u8 *)FUN_003b46b0(DAT_0095ae1c_abs[0]);
  DAT_0095ae14_abs[0] = DAT_0095ae14_abs[0] + 1;
  if (puVar7 == (u8 *)0) {
    FUN_0019d400(0x6a2860,0x6a2730,0x743);
  }
  *(u16 *)puVar7 = param_1;
  puVar7[0x15] = param_2;
  *(u32 *)(puVar7 + 4) = 0;
  *(u32 *)(puVar7 + 8) = 0;
  *(u32 *)(puVar7 + 0xc) = 0;
  puVar7[0x14] = param_3;
  *(u32 *)(puVar7 + 0x10) = 0xffffff00;
  puVar7[0x16] = param_4;
  puVar7[0x17] = DAT_007cd500;
  *(u16 *)(puVar7 + 2) = 0;
  *(u32 *)(puVar7 + 0x1c) = 0;
  *(u32 *)(puVar7 + 0x20) = 0;
  *(u32 *)(puVar7 + 0x24) = 0;
  *(u32 *)(puVar7 + 0x28) = 0;
  uVar5 = *(u16 *)puVar7;
  if (uVar5 < 0x80) {
    if (uVar5 == 0x20) {
      iVar6 = 0x1f7;
    }
    else {
      iVar6 = uVar5 - 0x20;
    }
  }
  else {
    iVar6 = ((uVar5 - 0x8080 & 0xff00) >> 1) +
            (uVar5 - 0x8080 & 0x7f);
  }
  if (*(u16 *)((int)(&DAT_0095acf4)[(u32)param_2 * 8] + 0xe) <= iVar6) {
    iVar6 = 0x147;
  }
  FUN_003b0430_typed((int)puVar7,iVar6);
  *(u32 *)(puVar7 + 0x1c) = 0;
  FUN_003b01d0_typed((int)puVar7,iVar6);
  if ((puVar7[0x17] & 0x10) == 0) {
    *(u32 *)(puVar7 + 8) = 0;
    *(u32 *)(puVar7 + 0xc) = 0;
  }
  else {
    if ((((iVar6 == 0x59) || (iVar6 == 0x51)) || (iVar6 == 0x50)) ||
       (((iVar6 == 0x4a) || (iVar6 == 0x47)) || (iVar6 == 0x31))) {
      *(u32 *)(puVar7 + 8) = 0x10;
    }
    else {
      *(u32 *)(puVar7 + 8) = 0;
    }
  }
  return (int)puVar7;
}
#define FUN_003b0620(...) ((long (*)(...))FUN_003b0620)(__VA_ARGS__)
#pragma opt_common_subs reset
#undef FUN_003b0840
// FUN_003B0840

int FUN_003b0840(short *param_1)
{
  u16 *puVar3;
  u16 sVar1;
  int iVar2;
  int iVar3;

  puVar3 = *(u16 **)((int)param_1 + 0x24);
  iVar2 = 0;
  if (*(u8 *)((int)param_1 + 0x15) == 0) {
    goto LAB_003b0860;
  }
  if (*(u8 *)((int)param_1 + 0x15) != 1) {
    goto LAB_003b095c;
  }
LAB_003b0860:
  if (puVar3 == (u16 *)0x0) {
    goto LAB_003b095c;
  }
  sVar1 = *(u16 *)param_1;
  switch (sVar1) {
  case 0x61:
  case 0x65:
  case 0x6f:
  case 0x75:
  case 0x80c1:
  case 0x80c5:
  case 0x80cf:
  case 0x80d5:
    goto LAB_003b08d4;
  default:
    goto LAB_003b095c;
  }
LAB_003b08d4:
  sVar1 = *puVar3;
  if (sVar1 == 0x54) goto LAB_003b08f0;
  if (sVar1 != 0x80b4) goto LAB_003b091c;
LAB_003b08f0:
  iVar2 = 3;
  iVar3 = iGpffffb948;
  if (iVar3 <= 0) goto LAB_003b091c;
  iVar3 = iVar3 * 3;
  iVar2 = iVar3 >> 7;
  if (iVar3 < 0) {
    iVar2 = iVar3 + 0x7f >> 7;
  }
LAB_003b091c:
  if (sVar1 == 0x59) goto LAB_003b0934;
  if (sVar1 != 0x80b9) goto LAB_003b095c;
LAB_003b0934:
  iVar2 = 2;
  iVar3 = iGpffffb948;
  if (iVar3 <= 0) goto LAB_003b095c;
  iVar3 = iVar3 * 2;
  iVar2 = iVar3 >> 7;
  if (iVar3 < 0) {
    iVar2 = iVar3 + 0x7f >> 7;
  }
LAB_003b095c:
  return iVar2;
}
#define FUN_003b0840(...) ((int (*)(...))FUN_003b0840)(__VA_ARGS__)
#undef FUN_003b0970
/* W340 loop probe: opt_common_subs off; without nd=337/object=564, with nd=287/object=572; window=576. */
#pragma opt_common_subs off
/* W340 loop probe: opt_lifetimes on; without nd=337/object=564, with nd=336/object=564; window=576. */
#pragma opt_lifetimes on
/* W417 CONCAT11 probes: direct, whole-cast, second-operand-cast, first-operand-cast, and multiply forms regressed nd=285/object=572 to nd=289/object=572; shift-cast form regressed to nd=306/object=576. Declaration orders J-M with plain arithmetic reached nd=284/object=572; the J order is retained below. */
/* W419 declaration sweep negative: 28 pair swaps; baseline/min nd284/object572/window576/rate0.496503 and 7 reached nd289/object572/window576/rate0.505245. */
// FUN_003B0970 NONMATCHING


u8 *FUN_003b0970(u8 *param_1,u8 param_2,u8 param_3,u8 param_4,u8 *param_5)


{

  u8 bVar1;

  u32 uVar2;

  u32 uVar7;

  int iVar3;

  int lVar4;

  u16 uVar5;

  int iVar6;

  int iVar8;

  

  uVar2 = 0;

  if ((char)param_2 < 0) {
    goto skipCachedFont;
  }

  bGpffffb950 = param_2;

skipCachedFont:

  if ((&DAT_0095ad0c)[(u32)bGpffffb950 * 8] != 0) {
    goto processFont;
  }

  return 0;

processFont:

    if (param_1 != 0) {

      uVar2 = FUN_00524388(param_1);

    }

    if (param_5 == 0) {

      param_5 = (u8 *)FUN_003b46b0(DAT_0095ae20);

      DAT_0095ae18 = DAT_0095ae18 + 1;

      if (param_5 == 0) {

        FUN_0019d3f0(DAT_006a2730,0x7da);

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

        uVar5 = ((u16)bVar1 << 8) | *(u8 *)((int)param_1 + uVar7);

      }

      iVar3 = FUN_003b0620_typed(uVar5,bGpffffb950,param_3,param_4);

      if (iVar6 == 0) {

        *(int *)(iVar8 + 0x1c) = iVar3;

      }

      else {

        *(int *)(iVar6 + 0x28) = iVar3;

      }

      if (iVar3 == 0) {

        FUN_0019d3f0(DAT_006a2730,0x7ef);

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


  return param_5;

}
#define FUN_003b0970(...) ((long (*)(...))FUN_003b0970)(__VA_ARGS__)
#pragma opt_lifetimes reset
#pragma opt_common_subs reset
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
// FUN_003B0C20


void FUN_003b0c20(u32 param_1,u16 param_2)



{

  if (param_1 == 0) {

    FUN_0019d3f0("frFont.c",0x82c);

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
// FUN_003B0D70


void FUN_003b0d70(int param_1,u32 param_2,u32 param_3)



{

  if (param_1 == 0) {

    FUN_0019d3f0(DAT_006a2730,0x88c);

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
/* Falls through into FUN_003b0e04 (no jr $ra of its own); FUN_003b0e04
 * branches back to this function's entry. Together they implement:
 *   do {
 *     for (v1 = *(int*)(param_1+0x1c); v1 != 0; v1 = *(int*)(v1+0x28))
 *       *(u8*)(v1+0x14) = param_2;
 *     param_1 = *(int*)(param_1+0x24);
 *   } while (param_1 != 0);
 * split across two retail symbols, which a single portable-C function
 * cannot reproduce byte-for-byte (the loop-back branch must land at this
 * function's exact address). Kept as readable mnemonic asm. */
// FUN_003B0DD8
asm void FUN_003b0dd8(int param_1, u8 param_2)
{
  .set noreorder
  lw $v1, 0x1c($a0)
  b FUN_003b0dd8_check
  nop
FUN_003b0dd8_store:
  sb $a1, 0x14($v1)
  lw $v1, 0x28($v1)
FUN_003b0dd8_check:
  nop
  nop
  nop
  bnez $v1, FUN_003b0dd8_store
  nop
  lw $a0, 0x24($a0)
}

#define FUN_003b0d70(...) ((void (*)(...))FUN_003b0d70)(__VA_ARGS__)
#undef FUN_003b0e04
/* Continuation of FUN_003b0dd8 (see comment there); branches back to its
 * start when param_1 != 0, otherwise returns. */
// FUN_003B0E04
asm void FUN_003b0e04(int param_1, u8 param_2)
{
  .set noreorder
  .word 0x1480fff4  /* bnez $a0, FUN_003b0dd8 (label unavailable across function boundary) */
  nop
  jr $ra
  nop
}





#undef FUN_003b0e54
#pragma optimization_level 3
// FUN_003B0E20 thunk_FUN_003b0e54
void thunk_FUN_003b0e54(int param_1, u32 param_2)
{
  FUN_003b0e54(param_1, param_2);
}
#pragma optimization_level 2
/* Falls through into FUN_003b0e54 (no jr $ra of its own); FUN_003b0e54
 * branches back to this function's entry. Same structure as
 * FUN_003b0dd8/FUN_003b0e04 above but stores a u32 at offset 0x10 instead
 * of a u8 at offset 0x14; see that pair's comment for the full loop shape
 * and why the cross-function branch cannot be portable C. */
// FUN_003B0E28
asm void FUN_003b0e28(int param_1, u32 param_2)
{
  .set noreorder
  lw $v1, 0x1c($a0)
  b FUN_003b0e28_check
  nop
FUN_003b0e28_store:
  sw $a1, 0x10($v1)
  lw $v1, 0x28($v1)
FUN_003b0e28_check:
  nop
  nop
  nop
  bnez $v1, FUN_003b0e28_store
  nop
  lw $a0, 0x24($a0)
}

#define FUN_003b0e04(...) ((void (*)(...))FUN_003b0e04)(__VA_ARGS__)
#undef FUN_003b0e54
/* Continuation of FUN_003b0e28 (see comment there); branches back to its
 * start when param_1 != 0, otherwise returns. */
// FUN_003B0E54
asm void FUN_003b0e54(int param_1, u32 param_2)
{
  .set noreorder
  .word 0x1480fff4  /* bnez $a0, FUN_003b0e28 (label unavailable across function boundary) */
  nop
  jr $ra
  nop
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
  u16 uVar1;
  long mask;

  uVar1 = uGpffffa810;
  mask = (s16)~param_1;
  uGpffffa810 = uGpffffa810 & mask;
  return uVar1;
}
#define FUN_003b0e90(...) ((u16 (*)(...))FUN_003b0e90)(__VA_ARGS__)
#undef FUN_003b0ec0
// Retail hoists the loop-invariant mask/type constants here; without
// opt_loop_invariants this function measures nd102 at 136B instead of nd1 at 140B.
// FUN_003B0EC0
#pragma push
#pragma opt_loop_invariants on

u32 FUN_003b0ec0(int list)
{
  u32 result = 0;
  u32 mask = ~0xff;
  u32 changed = 1;
  u32 type = 2;

  while (list != 0) {
    int node = *(int *)(list + 0x1c);

    while (node != 0) {
      if (*(u8 *)(node + 0x16) == type) {
        u32 word = *(u32 *)(node + 0x10);
        u32 fade = word & 0xff;
        u32 merged;

        if (fade != 0) {
          fade -= 8;
          if ((s32)fade < 0) {
            fade = 0;
          }
          merged = word & mask;
          merged |= fade;
          *(u32 *)(node + 0x10) = merged;
          *(u32 *)(node + 8) += 0x10;
          result = changed;
        }
      }
      node = *(int *)(node + 0x28);
    }
    list = *(int *)(list + 0x24);
  }
  return result;
}
#pragma opt_loop_invariants off
#pragma pop
#define FUN_003b0ec0(...) ((u32 (*)(...))FUN_003b0ec0)(__VA_ARGS__)
#undef FUN_003b0f50
// FUN_003B0F50 NONMATCHING


int FUN_003b0f50(u8 *param_1,u16 *param_2,u8 param_3,u32 param_4)



{

  int iVar1;

  int iVar2;

  u32 uVar3;

  u8 bVar4;

  u8 bVar5;

  int lVar6;

  u8 cVar7;

  u8 bVar8;

  u32 *puVar9;

  int iVar10;

  int uVar11;

  

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

  if ((param_3 > 0) && (*param_2 < 0x80)) {

    param_3 = param_3 + 0x14;

  }

  puVar9 = (u32 *)(param_2 + 8);

  if ((cVar7 == '\0') || (cVar7 == *(u8 *)((int)param_2 + 0x16))) {

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
    switch (iVar2) {
    case 0xf214:
      iVar2 = *(int *)(iVar1 + 0x3c);
      if (iVar2 > 0) {
        bVar4 = 0;
        if (bVar8 == 0xff) {
          *(int *)(iVar1 + 0x3c) = iVar2 - 1;
        }
      }
      break;
    case 0xf215:
      iVar2 = *(int *)(iVar1 + 0x3c);
      if (iVar2 == -1) {
        if (FUN_0010a500(2) != 0) {
          bVar4 = 0;
        }
      } else if (iVar2 > 0) {
        bVar4 = 0;
        *(int *)(iVar1 + 0x3c) = iVar2 - 1;
      }
      break;
    case 0xf247:
      iVar2 = *(int *)(iVar1 + 0x3c);
      if (iVar2 == -1) {
        if (FUN_0010a500(2) != 0) {
          bVar4 = 0;
        }
      } else if (iVar2 > 0) {
        bVar4 = 0;
        *(int *)(iVar1 + 0x3c) = iVar2 - 1;
      }
      break;
    }

  }

  if ((*(int *)(param_1 + 0x34) == 0xf117) && (*(u8 *)(*(int *)(param_1 + 0x20) + 0x10) == 0xff)) {

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

    if ((int)(param_4 & 0xff) < 0xff) {

      uVar11 = (int)((float)((int)(param_4 & 0xff) << 5) /

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

  if ((*(u8 *)puVar9 < 0xff) && (*(u8 *)((u8 *)param_2 + 0x16) == 1)) {

    iVar10 = (((int)param_2[1] << 1) % 5 - 2) * -0x10;

  }

  return iVar10;

}
#define FUN_003b0f50(...) ((int (*)(...))FUN_003b0f50)(__VA_ARGS__)
#undef FUN_003b1300
#undef FUN_003b1330
#undef FUN_003b1360
// FUN_003B1300


void FUN_003b1300(void *param_1)



{

  FUN_003b1330(param_1,0);

  return;

}
// FUN_003B1330


void FUN_003b1330(void *param_1,u32 param_2)



{

  FUN_003b1360(param_1,param_2,uGpffffb940);

  return;

}
#define FUN_003b1300(...) ((void (*)(...))FUN_003b1300)(__VA_ARGS__)
#define FUN_003b1330(...) ((void (*)(...))FUN_003b1330)(__VA_ARGS__)
#undef FUN_003b1360
/* W340 loop probe: opt_common_subs off; without nd=378/object=936, with nd=375/object=944; window=944. */
#pragma opt_common_subs off
/* W389 pragma: opt_loop_invariants on; without nd=375/object=944, with nd=364/object=936; window=944. */
#pragma push
#pragma opt_loop_invariants on
/* W415 typed and pointer-typed probes for FUN_003b0f50 both regressed nd 364 -> 470; old-style direct alias retained at nd 364 -> 467, object 928/944. */
// W417 rejected census closure: adding 0x003b0f50 before 0x003b38f0 closed 5 -> 6 calls,
// but baseline nd 364/object 936/window 944 (38.9%) -> direct-alias closure nd 467/object 928/window 944 (50.3%).
// The 8-byte shrink shows the alias replaced the compiler-inlined body with an out-of-line call;
// reverted to the old-style call until the frame or shape is fixed.
/* W417 switch probe: ascending cases 0xf214, 0xf215, 0xf246, 0xf247 matched retail body layout and improved nd=364/object=936 to nd=310/object=944; swapping bVar5/iVar9 declarations reached nd=305/object=944. Other declaration orders stayed at or above nd=305; parameter-width probes were unchanged or regressed (u8/char param_2 exceeded the 944-byte window). */
// FUN_003B1360 NONMATCHING


int FUN_003b1360(void *param_1,u32 param_2,u32 param_3)



{

  char cVar1;

  u8 *puVar2;

  int iVar3;

  int iVar4;

  int iVar9;

  int iVar6;

  int lVar7;

  code *fn;

  int iVar8;

  u8 bVar5;

  

  iVar9 = 0;

  bVar5 = 1;

  if ((uGpffffa810 & 0x40) == 0) {

    fn = (code *)&DAT_00960090_abs;

    (*fn)(6,bVar5);

    (*fn)(7,2);

    (*fn)(9,2);

    (*fn)(0xc,bVar5);

    (*fn)(10,5);

    (*fn)(0xb,6);

    (*fn)(2,4);

    (*fn)(0xe,0);

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

        if (*(u8 *)(iVar4 + 0x10) != 0) {

          *(short *)(iVar4 + 2) = *(short *)(iVar4 + 2) + 1;

        }

        if (*(u8 *)(iVar4 + 0x10) != 0xff) {

          bVar5 = 0;

        }

        iVar8 = iVar8 + (*(int *)(iVar4 + 0xc) + (int)cVar1) * 0x10;

      }

      if ((*(int *)(puVar2 + 0x28) == 0) && (*(int *)(puVar2 + 0x40) == 0)) {

        iVar8 = *(int *)(puVar2 + 0x30);

        switch (iVar8) {

        case 0xf214:
          if (bVar5 && (0 < *(int *)(puVar2 + 0x3c))) {

          *(int *)(puVar2 + 0x3c) = *(int *)(puVar2 + 0x3c) + -1;

          bVar5 = 0;

        
          }

          break;

        case 0xf215:

          lVar7 = FUN_0010a500(2);

          if (lVar7 != 0) {

            bVar5 = 0;

          }

          else {

            iVar8 = *(int *)(puVar2 + 0x3c);

            if ((iVar8 != -1) && (0 < iVar8)) {

              *(int *)(puVar2 + 0x3c) = iVar8 + -1;

              bVar5 = 0;

            }

          }

        
          break;

        case 0xf246:

          iVar8 = *(int *)(puVar2 + 0x3c);

          if ((iVar8 != -1) && (0 < iVar8)) {

            *(int *)(puVar2 + 0x3c) = iVar8 + -1;

            bVar5 = 0;

          }

        
          break;

        case 0xf247:

          lVar7 = FUN_0010a500(2);

          if (lVar7 != 0) {

            bVar5 = 0;

          }

          else {

            iVar8 = *(int *)(puVar2 + 0x3c);

            if ((iVar8 != -1) && (0 < iVar8)) {

              *(int *)(puVar2 + 0x3c) = iVar8 + -1;

              bVar5 = 0;

            }

          }

        
          break;

        }

      }

      iVar9 = iVar9 + *(int *)(puVar2 + 0x18);

    }

    if (iGpffffb944 >= 1) {

      iGpffffb944 = iGpffffb944 + -1;

      iVar9 = 0;

    }

    else {

      if (!bVar5) {

        iVar9 = 0;

      }

    }

  }

  return iVar9;

}
#pragma pop
#pragma opt_loop_invariants reset
#define FUN_003b1360(...) ((int (*)(...))FUN_003b1360)(__VA_ARGS__)
#pragma opt_common_subs reset
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

          if (lVar3 != 0) {

            bVar2 = 0;

          }

          else {

            if ((*(int *)(iVar5 + 0x3c) != -1) && (0 < *(int *)(iVar5 + 0x3c))) {

              bVar2 = 0;

            }

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

          if (lVar3 != 0) {

            bVar2 = 0;

          }

          else {

            if ((*(int *)(iVar5 + 0x3c) != -1) && (0 < *(int *)(iVar5 + 0x3c))) {

              bVar2 = 0;

            }

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
// FUN_003B18C0


u64 FUN_003b18c0(void)
{
    u32 index;
    u32 *entry;

    index = FUN_0035aea0() & 0xff;
    entry = (u32*)DAT_0095ae60_abs + index;
    *entry = FUN_003b0030_direct(*entry);
    FUN_003b3770();
    return 0;
}

#define FUN_003b18c0(...) ((u64 (*)(...))FUN_003b18c0)(__VA_ARGS__)
#undef FUN_003b1920
// FUN_003B1920

int FUN_003b1920(int param_1, int param_2, int param_3)
{
    if (param_1 != 0)
    {
        goto checkParam2;
    }
    return param_2;

checkParam2:
    if (param_2 != 0)
    {
        goto body;
    }
    return param_1;

body:
    *(u32*)(param_1 + 0x28) = *(u32*)(param_2 + 0x2c);
    *(int*)(*(int*)(param_2 + 0x2c) + 0x24) = param_1;
    *(u32*)(param_2 + 0x2c) = *(u32*)(param_1 + 0x2c);

    if (param_3 == 1)
    {
        *(int*)(param_2 + 4) = *(int*)(param_1 + 4) + *(int*)(param_1 + 0xc) * 0x10;
        *(u32*)(param_2 + 8) = *(u32*)(param_1 + 8);
    }

    return param_2;
}
#define FUN_003b1920(...) ((long (*)(...))FUN_003b1920)(__VA_ARGS__)
#undef FUN_003b19a0
// FUN_003B19A0


void FUN_003b19a0(u64 param_1)



{

  FUN_003afad0_typed(8,param_1,0);

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
// FUN_003B1A10


u16 FUN_003b1a10(u32 param_1)



{
  u32 **base = (u32 **)DAT_0095acf4_abs;
  u32 *entry = base[(param_1 & 0xff) * 8];
  return *(u16 *)((u8 *)entry + 0x10);

}
#define FUN_003b1a10(...) ((u16 (*)(...))FUN_003b1a10)(__VA_ARGS__)
#undef FUN_003b1a40
// FUN_003B1A40


u16 FUN_003b1a40(u32 param_1)



{
  u32 **base = (u32 **)DAT_0095acf4_abs;
  u32 *entry = base[(param_1 & 0xff) * 8];
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
/* Removing this loses FUN_003b1a90 (MATCH nd0 -> MISMATCH nd45) - measured W161. */
#pragma opt_loop_invariants on
// FUN_003B1A90


int FUN_003b1a90(int param_1)
{
  int iVar2;
  int iVar3;
  iVar2 = 0;
  if (param_1 == 0) {
    return iVar2;
  }
  param_1 = *(int *)(param_1 + 0x2c);
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x28)) {
    int iVar1;
    iVar3 = param_1;
    iVar1 = *(int *)(param_1 + 8);
    iVar1 = iVar1 + 100;
    while (iVar3 != 0) {
      if (*(int *)(iVar3 + 8) >= iVar1) {
        break;
      }
      iVar3 = *(int *)(iVar3 + 0x28);
    }
    iVar2 = iVar2 + 1;
  }

  return iVar2;

}
#define FUN_003b1a90(...) ((int (*)(...))FUN_003b1a90)(__VA_ARGS__)
#pragma opt_loop_invariants reset
#undef FUN_003b1b00
// FUN_003B1B00


int FUN_003b1b00(int param_1,int param_2)



{

  int iVar3;

  int iVar6;

  int iVar2;

  int iVar5;

  int iVar4;

  int iVar7;
  

  iVar2 = 0;
  iVar5 = 0;
  if (param_2 == 0) {
    return 0;
  }
  else {
    for (param_2 = *(int *)(param_2 + 0x2c); param_2 != 0;
         param_2 = *(int *)(param_2 + 0x28)) {
      iVar2 = 0;
      iVar6 = param_2;
      iVar7 = *(int *)(param_2 + 8) + 100;
      while (iVar6 != 0) {
        if (*(int *)(iVar6 + 8) >= iVar7) {
          break;
        }
        iVar3 = 0;
        iVar4 = *(int *)(iVar6 + 0x1c);
        goto frFont_b1b00_child_check;
frFont_b1b00_child_body:
        iVar3 = iVar3 + *(int *)(iVar4 + 0xc);
        iVar3 = iVar3 + (int)*(char *)(iVar6 + 3);
        iVar4 = *(int *)(iVar4 + 0x28);
frFont_b1b00_child_check:
        if (iVar4 != 0) goto frFont_b1b00_child_body;
        iVar2 = iVar2 + iVar3;
        iVar6 = *(int *)(iVar6 + 0x28);
      }
      iVar7 = iVar5;
      iVar5 = iVar5 + 1;
      if (iVar7 == param_1) break;
    }
    iVar2 = iVar2 << 4;
  }
  return iVar2;

}
#define FUN_003b1b00(...) ((int (*)(...))FUN_003b1b00)(__VA_ARGS__)
#undef FUN_003b1bc0
/* Removing this loses FUN_003b1bc0 (MATCH nd0 -> MISMATCH nd57) - measured W161. */
#pragma opt_loop_invariants on
// FUN_003B1BC0


void FUN_003b1bc0(u32 *param_1,int param_2,int param_3)



{


  int iVar3;
  int iVar2;


  

  iVar2 = 0;
  if (param_3 == 0) {
    return;
  }
  param_3 = *(int *)(param_3 + 0x2c);
  for (; param_3 != 0;
       param_3 = *(int *)(param_3 + 0x28)) {
    int iVar1;
    iVar3 = param_3;
    *param_1 = *(u32 *)(param_3 + 4);
    param_1[1] = *(u32 *)(param_3 + 8);
    iVar1 = *(int *)(param_3 + 8);
    iVar1 = iVar1 + 100;
    while (iVar3 != 0) {
      if (*(int *)(iVar3 + 8) >= iVar1) {
        break;
      }
      iVar3 = *(int *)(iVar3 + 0x28);
    }
    {
      int iVar4;
      iVar4 = iVar2;
      iVar2 = iVar2 + 1;
      if (iVar4 == param_2) {
        return;
      }
    }
  }

  return;

}
#define FUN_003b1bc0(...) ((void (*)(...))FUN_003b1bc0)(__VA_ARGS__)
#pragma opt_loop_invariants reset
#undef FUN_003b1c40
// FUN_003B1C40


void FUN_003b1c40(int param_1,int param_2,int param_3)



{


  int iVar1;

  int iVar2;

  

  if (param_3 == 0) {
    return;
  }
  param_3 = *(int *)((int)param_3 + 0x2c);
  iVar1 = param_1 - *(int *)(param_3 + 4);
  iVar2 = param_2 - *(int *)(param_3 + 8);
  for (; param_3 != 0; param_3 = *(int *)(param_3 + 0x28)) {
    *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + iVar1;
    *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + iVar2;
  }

  return;

}
#define FUN_003b1c40(...) ((void (*)(...))FUN_003b1c40)(__VA_ARGS__)
#undef FUN_003b1c90
// FUN_003B1C90


void FUN_003b1c90(int x, int y, FrFontLineLayout *line)
{
  int yDelta;
  int scan;
  int totalWidth;
  FrFontGlyphLayout *glyph;
  int firstY;
  int limit;
  int secondLimit;
  int lineWidth;
  int xDelta;
  int halfWidth;
  int scaledHalfWidth;

  if (line == NULL) {
    return;
  }

  line = line->line;
  yDelta = y - line->y;
  while (line != NULL) {
    totalWidth = 0;
    scan = (int)line;
    firstY = line->y;
    limit = firstY + 100;

    while (scan != 0) {
      if (*(int *)(scan + 8) >= limit) {
        break;
      }
      lineWidth = 0;
      glyph = *(FrFontGlyphLayout **)(scan + 0x1c);
      while (glyph != NULL) {
        lineWidth += glyph->width;
        lineWidth += *(s8 *)(scan + 3);
        glyph = glyph->next;
      }
      totalWidth += lineWidth;
      scan = *(int *)(scan + 0x28);
    }

    xDelta = x - line->x;
    halfWidth = totalWidth / 2;
    scaledHalfWidth = halfWidth * 0x10;
    secondLimit = firstY + 100;
    while (line != NULL) {
      if (line->y >= secondLimit) {
        break;
      }
      line->x += xDelta;
      line->x -= scaledHalfWidth;
      line->y += yDelta;
      line = line->next;
    }
  }
}
#define FUN_003b1c90(...) ((void (*)(...))FUN_003b1c90)(__VA_ARGS__)
#undef FUN_003b1d90
/* W340 loop probe: opt_common_subs off; without nd=377/object=656, with nd=376/object=656; window=656. */
#pragma opt_common_subs off
/* W340 loop probe: opt_lifetimes on; without nd=377/object=656, with nd=376/object=656; window=656. */
#pragma opt_lifetimes on
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

          lVar8 = FUN_003b0970_typed(&gp0xffffa838,0,*(u8 *)(param_2 + 0xd),

                               *(u8 *)(param_2 + 0xe),0);

          if (lVar8 == 0) {

            uVar7 = 0;

          }

          else {

            uVar7 = FUN_003b1920_typed(0,lVar8,1);

          }

          *(u32 *)(param_2 + 0x14) = uVar7;

        }

        else if (*(int *)(iVar6 + 0x1c) != 0) {

          lVar8 = FUN_003b0970_typed(&gp0xffffa838,0,*(u8 *)(param_2 + 0xd),

                               *(u8 *)(param_2 + 0xe),0);

          if (lVar8 != 0) {

            iVar6 = FUN_003b1920_typed(iVar6,lVar8,1);

          }

          *(int *)(param_2 + 0x14) = iVar6;

        }

        uVar2 = *(u8 *)(param_2 + 0xf);

        iVar6 = *(int *)(param_2 + 0x14);

        if (iVar6 == 0) {

          FUN_0019d3f0(DAT_006a2730,0x818);

        }

        for (; cVar13 = cVar1, iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x24)) {

          *(u8 *)(iVar6 + 2) = uVar2;

        }

      }

      iVar6 = FUN_003b0970_typed(abStack_4,cVar1,*(u8 *)(param_2 + 0xd),

                           *(u8 *)(param_2 + 0xe),*(u32 *)(param_2 + 0x14));

      uVar2 = uGpffffa7fc;

      *(int *)(param_2 + 0x14) = iVar6;

      if (iVar6 == 0) {

        FUN_0019d3f0(DAT_006a2730,0x848);

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
#pragma opt_lifetimes reset
#pragma opt_common_subs reset
#undef FUN_003b2020
/* W340 loop probe: opt_lifetimes on; without nd=363/object=636, with nd=362/object=636; window=640. */
#pragma opt_lifetimes on
// FUN_003B2020 NONMATCHING


void FUN_003b2020(int param_1,int param_2)



{

  char cVar1;

  u8 uVar2;

  int clearCount;

  int iVar4;

  int iVar5;

  u32 uVar6;

  long lVar7;


  u8 *pbVar9;

  int iVar10;

  int iVar11;

  char cVar12;

  int iVar13;

  u8 abStack_4 [4];

  

  clearCount = 3;
  pbVar9 = abStack_4;
  while (clearCount != 0) {
    *pbVar9 = 0;
    pbVar9 = pbVar9 + 1;
    clearCount = clearCount - 1;
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

          lVar7 = FUN_003b0970_typed(&gp0xffffa838,0,*(u8 *)(param_2 + 0xd),

                               *(u8 *)(param_2 + 0xe),0);

          if (lVar7 == 0) {

            uVar6 = 0;

          }

          else {

            uVar6 = FUN_003b1920_typed(0,lVar7,1);

          }

          *(u32 *)(param_2 + 0x14) = uVar6;

        }

        else if (*(int *)(iVar5 + 0x1c) != 0) {

          lVar7 = FUN_003b0970_typed(&gp0xffffa838,0,*(u8 *)(param_2 + 0xd),

                               *(u8 *)(param_2 + 0xe),0);

          if (lVar7 != 0) {

            iVar5 = FUN_003b1920_typed(iVar5,lVar7,1);

          }

          *(int *)(param_2 + 0x14) = iVar5;

        }

        uVar2 = *(u8 *)(param_2 + 0xf);

        iVar5 = *(int *)(param_2 + 0x14);

        if (iVar5 == 0) {

          FUN_0019d3f0(DAT_006a2730,0x818);

        }

        for (; cVar12 = cVar1, iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x24)) {

          *(u8 *)(iVar5 + 2) = uVar2;

        }

      }

      lVar7 = FUN_003b0970_typed(abStack_4,cVar1,*(u8 *)(param_2 + 0xd),
                           *(u8 *)(param_2 + 0xe),*(u32 *)(param_2 + 0x14));
      uVar2 = uGpffffa7fc;
      iVar5 = (int)lVar7;
      *(int *)(param_2 + 0x14) = iVar5;
      if (lVar7 == 0) {

        FUN_0019d3f0(DAT_006a2730,0x848);

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
#pragma opt_lifetimes reset
#undef FUN_003b22a0
/* W340 loop probe: opt_common_subs off; without nd=113/object=352, with nd=52/object=352; window=352. */
#pragma opt_common_subs off
/* W419 declaration sweep negative: all 21 pair swaps stayed nd51/object352/window352/rate0.144886. */
// FUN_003B22A0 NONMATCHING


void FUN_003b22a0(u32 *param_1)



{

  u8 uVar1;

  u16 uVar2;

  u16 *puVar3;

  u32 uVar4;

  u32 uVar5;

  int iVar6;

  int lVar7;

  

  if ((param_1[5] == 0) || (*(int *)(param_1[5] + 0x1c) == 0)) {

    *(u8 *)(param_1 + 7) = 0;

  }

  if (*(char *)(param_1 + 7) != '\0') {

    iVar6 = param_1[5];

    lVar7 = FUN_003b0970_typed(&gp0xffffa838,0,*(s8 *)((int)param_1 + 0xd),
                         *(s8 *)((int)param_1 + 0xe),0);

    if (lVar7 != 0) {
      iVar6 = FUN_003b1920_typed(iVar6,lVar7,1);
    }

    param_1[5] = iVar6;

    uVar1 = *(u8 *)((int)param_1 + 0xf);

    if (iVar6 == 0) {

      FUN_0019d3f0(DAT_006a2730,0x818);

    }

    for (; iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x24)) {

      *(u8 *)(iVar6 + 2) = uVar1;

    }

    uVar2 = *(u16 *)((int)param_1 + 0x1e);

    puVar3 = (u16 *)param_1[5];

    if (puVar3 == (u16 *)0x0) {

      FUN_0019d3f0(DAT_006a2730,0x82c);

    }

    *puVar3 = uVar2;

    *(u8 *)(param_1 + 7) = 0;

  }

  if (*(char *)((int)param_1 + 0x1d) != '\0') {

    uVar4 = param_1[1];

    uVar5 = *param_1;

    iVar6 = param_1[5];

    if (iVar6 == 0) {

      FUN_0019d3f0(DAT_006a2730,0x88c);

    }

    *(u32 *)(iVar6 + 4) = uVar5;

    *(u32 *)(iVar6 + 8) = uVar4;

    *(u8 *)((int)param_1 + 0x1d) = 0;

  }

  return;

}
#define FUN_003b22a0(...) ((void (*)(...))FUN_003b22a0)(__VA_ARGS__)
#pragma opt_common_subs reset
#undef FUN_003b2400
// FUN_003B2400

void FUN_003b2400(FrFontState *state)
{
  state->text_position += iGpffffa800 * 8;
  state->layout_dirty = 1;
  state->position_dirty = 1;
}
#define FUN_003b2400(...) ((void (*)(...))FUN_003b2400)(__VA_ARGS__)
#undef FUN_003b2430
/* W340 loop probe: opt_common_subs off; without nd=853/object=1168, with nd=841/object=1192; window=1232. */
#pragma opt_common_subs off
// FUN_003B2430 NONMATCHING


u32 FUN_003b2430(void *param_1)



{

  u8 bVar1;

  u32 bVar2;

  u16 uVar3;

  u16 *puVar4;

  u32 uVar5;

  int iVar6;

  u8 bVar7;

  u32 uVar8;

  int lVar9;

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

      if (uVar13 != 10) {

        if ((puVar12[5] != 0) && (*(int *)(puVar12[5] + 0x1c) == 0)) {

          *(u8 *)(puVar12 + 7) = 0;

        }

        if (*(char *)(puVar12 + 7) != '\0') {

          uVar8 = puVar12[5];

          lVar9 = FUN_003b0970_typed(&gp0xffffa838,0,*(u8 *)((int)puVar12 + 0xd),

                               *(u8 *)((int)puVar12 + 0xe),0);

          if (lVar9 != 0) {

            uVar8 = FUN_003b1920_typed(uVar8,lVar9,1);

          }

          puVar12[5] = uVar8;

          FUN_003b0bb0_typed(uVar8,*(u8 *)((int)puVar12 + 0xf));

          uVar3 = *(u16 *)((int)puVar12 + 0x1e);

          puVar4 = (u16 *)puVar12[5];

          if (puVar4 == (u16 *)0x0) {

            FUN_0019d3f0(DAT_006a2730,0x82c);

          }

          *puVar4 = uVar3;

          *(u8 *)(puVar12 + 7) = 0;

        }

        if (*(char *)((int)puVar12 + 0x1d) != '\0') {

          uVar8 = puVar12[1];

          uVar5 = *puVar12;

          iVar10 = puVar12[5];

          if (iVar10 == 0) {

            FUN_0019d3f0(DAT_006a2730,0x88c);

          }

          *(u32 *)(iVar10 + 4) = uVar5;

          *(u32 *)(iVar10 + 8) = uVar8;

          *(u8 *)((int)puVar12 + 0x1d) = 0;

        }

        bStack_4 = bVar2;

        if (bVar2 >= 0x80) {

          iVar10 = puVar12[6];

          puVar12[6] = iVar10 + 1;

          uStack_3 = *(u8 *)(puVar12[4] + iVar10);

          if ((((u16)bVar2 << 8) | uStack_3) >= 0xc080) {
            iVar10 = (((u16)bVar2 << 8) | uStack_3) - 0x4000;

            bStack_4 = (u8)((u32)iVar10 >> 8);

            uStack_3 = (u8)iVar10;

            uStack_2 = 0;

            uVar8 = FUN_003b0970_typed(&bStack_4,8,*(u8 *)((int)puVar12 + 0xd),

                                 *(u8 *)((int)puVar12 + 0xe),puVar12[5]);

            puVar12[5] = uVar8;

          }

          else {

            uStack_2 = 0;

            uVar8 = FUN_003b0970_typed(&bStack_4,*(u8 *)(puVar12 + 3),

                                 *(u8 *)((int)puVar12 + 0xd),

                                 *(u8 *)((int)puVar12 + 0xe),puVar12[5]);

            puVar12[5] = uVar8;

          }

        }

        else {

          if (uVar13 == 0x20) {

            bStack_4 = 0x83;

            uStack_3 = 0xf7;

            uStack_2 = 0;

          }

          else {

            uStack_3 = 0;
          }

          uVar8 = FUN_003b0970_typed(&bStack_4,*(u8 *)(puVar12 + 3),

                               *(u8 *)((int)puVar12 + 0xd),

                               *(u8 *)((int)puVar12 + 0xe),puVar12[5]);

          puVar12[5] = uVar8;

        }

        iVar10 = (char)(&gp0xffffa808)[*(u8 *)(puVar12 + 3)] * -2;

        if (iVar10 < 0) {

          iVar10 = iVar10 + 0x1f;

        }

        iVar6 = puVar12[5];

        if (iVar6 == 0) {

          FUN_0019d3f0(DAT_006a2730,0x848);

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

          FUN_0019d3f0(DAT_006a2730,0x8a5);

        }

        *(u32 *)(iVar10 + 0x14) = uVar13 >> 4;

      }

      else {

        if ((uGpffffa810 & 4) != 0) {

          puVar12[1] = puVar12[1] + iGpffffa800 * 8;

          *(u8 *)(puVar12 + 7) = 1;

          *(u8 *)((int)puVar12 + 0x1d) = 1;

        }

      }

    }

    iVar10 = puVar12[6];

    puVar12[6] = iVar10 + 1;

    bVar1 = *(u8 *)(puVar12[4] + iVar10);

    if (!(bVar1 < 0x4d)) {

      FUN_0019d3f0(DAT_006a2730,0xdf9);

    }

    if (bVar1 < 2) {

      FUN_0019d3f0(DAT_006a2730,0xdfa);

    }

    lVar9 = (*(code *)(&DAT_006a2370 + (u32)bVar1 * 4))(((u16)bVar2 << 8) | bVar1,param_1);

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
#pragma opt_common_subs reset
#undef FUN_003b2900
// FUN_003B2900


void FUN_003b2900(u32 param_1,u32 param_2,u32 param_3,u32 param_4)
{
  FUN_003b2990_typed(param_1,param_2,0,0,0,0,0xff,param_3,param_4);
}

#define FUN_003b2900(...) ((void (*)(...))FUN_003b2900)(__VA_ARGS__)
#undef FUN_003b2940
// FUN_003B2940


void FUN_003b2940(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
                  u32 param_5,u32 param_6,u32 param_7,u32 param_8)
{
  FUN_003b2990_typed(param_1,param_2,0,param_3,param_4,param_5,param_6,param_7,param_8);
}

#define FUN_003b2940(...) ((void (*)(...))FUN_003b2940)(__VA_ARGS__)
#undef FUN_003b2990
#undef FUN_003b2430
#pragma alias FUN_003b2430_typed FUN_003b2430
void FUN_003b2430_typed(void *param_1);
// FUN_003B2990


void FUN_003b2990(u32 param_1,u32 param_2,int param_3,u8 param_4,

                 u8 param_5,u8 param_6,u8 param_7,u32 param_8,

                 u32 param_9)



{
  struct {
    u32 f00;
    u32 f04;
    int f08;
    u8 f0c;
    u8 f0d;
    u8 f0e;
    u8 f0f;
    u32 f10;
    u32 f14;
    u32 f18;
    u8 f1c;
    u8 f1d;
    u16 f1e;
  } data;

  data.f00 = param_1;
  data.f04 = param_2;
  data.f08 = param_3 << 4;
  data.f0c = param_4;
  data.f0d = param_5;
  data.f0e = param_6;
  data.f0f = param_7;
  data.f10 = param_8;
  data.f14 = param_9;
  data.f18 = 0;
  data.f1c = 1;
  data.f1d = 1;
  data.f1e = 0x20;
  FUN_003b2430_typed(&data);
  return;
}
#define FUN_003b2430(...) ((u32 (*)(...))FUN_003b2430)(__VA_ARGS__)
#define FUN_003b2990(...) ((void (*)(...))FUN_003b2990)(__VA_ARGS__)
#undef FUN_003b2a00
// FUN_003B2A00


u32 FUN_003b2a00(u32 param_1)



{

  return uGpffffa7f8 & param_1;

}
#define FUN_003b2a00(...) ((u32 (*)(...))FUN_003b2a00)(__VA_ARGS__)
#undef FUN_003b2a10
// FUN_003B2A10


void FUN_003b2a10(int param_1,u32 param_2)



{
  u32 *base = DAT_0095ac70_abs;
  u32 *entry = base + param_1;
  *entry = param_2;

  return;

}
#define FUN_003b2a10(...) ((void (*)(...))FUN_003b2a10)(__VA_ARGS__)
#undef FUN_003b2a30
// FUN_003B2A30 NONMATCHING


u64 FUN_003b2a30(void *param_1,u32 param_2)



{

  u8 bVar2;

  int iVar3;

  u8 bVar4;

  int lVar5;

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

      if (bVar2 == 0) {

        return 0;

      }

      if ((bVar2 & 0xf0) == 0xf0) break;

      if ((bVar2 != 10) && (0x7f < bVar2)) {

        *(int *)(iVar7 + 0x18) = *(int *)(iVar7 + 0x18) + 1;

      }

    }

    lVar5 = 0;

    iVar3 = *(int *)(iVar7 + 0x18);

    *(int *)(iVar7 + 0x18) = iVar3 + 1;

    uVar8 = ((u32)bVar2 << 8) | *(u8 *)(*(int *)(iVar7 + 0x10) + iVar3);

    if ((param_2 != 0) && (uVar8 == param_2)) {

      lVar5 = (*(code *)(&DAT_006a2370 + (uVar8 & 0xff) * 4))(uVar8,param_1);

    }

    *(int *)(iVar7 + 0x18) = *(int *)(iVar7 + 0x18) + (((int)((uVar8 & 0xf00)) >> 8) + -1) * 2;

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
#pragma alias FUN_003b2a30_typed FUN_003b2a30
u64 FUN_003b2a30_typed(void *param_1, u32 param_2);
// FUN_003B2BF0


s8 FUN_003b2bf0(u32 param_1,u32 param_2,u32 param_3)
{
  struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 f0c;
    u8 f0d;
    u8 f0e;
    u8 f0f;
    u32 f10;
    u32 f14;
    u32 f18;
    u8 f1c;
    u8 f1d;
    u16 f1e;
  } data;

  data.f00 = 0;
  data.f04 = 0;
  data.f08 = 0;
  data.f0c = 0;
  data.f0d = 0;
  data.f0e = 0;
  data.f0f = 0;
  data.f10 = param_1;
  data.f14 = param_2;
  data.f18 = 0;
  data.f1c = 1;
  data.f1d = 1;
  data.f1e = 0x20;
  return FUN_003b2a30_typed(&data, param_3);
}
#define FUN_003b2bf0(...) ((u8 (*)(...))FUN_003b2bf0)(__VA_ARGS__)
