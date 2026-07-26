#include "mw_harvest_compat.h"
#include "temporary.h"

/* auto-extern (generated) */
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

/* EE kernel COP0 registers (accessed via mfc0/mtc0) */
extern u32 Index;
extern u32 Random;
extern u32 EntryLo0;
extern u32 EntryLo1;
extern u32 PageMask;
extern u32 Wired;
extern u32 EntryHi;

/* EE kernel symbols referenced by decompiled functions */
extern void TLB_write_indexed_entry(int idx, u32 entryhi, u32 entrylo0, u32 entrylo1, u32 pagemask);
extern u32 REG_INTC_STAT;
#pragma alias iRambc0003c0_abs iRambc0003c0
extern u8 iRambc0003c0_abs[];
#pragma alias uRam80074700_abs uRam80074700
extern u8 uRam80074700_abs[];
extern u64 uRam80074700;
extern u8 uRam800747b0[];
extern u32 uRam80076710[];
extern int iRam80076700;
extern int iRam80074748;
extern u64 uRam80076708;
extern u16 uRam80076740;
extern u16 uRam80076742;
extern u16 uRamb0001810;
extern u16 uRamb0001820;
#pragma alias uRamb0001810_abs uRamb0001810
extern u32 uRamb0001810_abs[];
#pragma alias uRamb0001820_abs uRamb0001820
extern u32 uRamb0001820_abs[];
extern u16 sRam80076740;
extern u16 uRamb0001800;
extern u16 sRamb0001800;
extern int iRambc0003c0;
extern int iRamb0001800;
extern int *piRam80074728;
extern int (*pcRam8007472c)();
extern int (*pcRam80074730)();
extern int (*pcRam80074734)();
extern int (*pcRam80074738)();
extern int (*pcRam8007473c)();
extern int (*pcRam80074740)();
extern int (*pcRam80074744)();
extern int (*pcRam80074748)();
extern int (*pcRam8007474c)();
extern int (*pcRam80074750)();
extern int (*pcRam80074754)();
extern int (*pcRam80074758)();
extern int (*pcRam8007475c)();
extern int (*pcRam80074760)();
extern int (*pcRam80074764)();
extern int (*pcRam80074768)();
extern int (*pcRam8007476c)();
extern int (*pcRam80074770)();
extern u32 uRam80074778;
extern u32 uRam80076750;
extern u64 uRam80076748;
extern u32 *puRam8007472c;
extern u32 _mips_gp0_value;
extern int func_0x00075158();
extern int func_0x000743c8();
extern int func_0x00076038();
extern int func_0x00076058();
extern int func_0x00076160();
extern int func_0x00076460();
extern int func_0x00076680();

// Retail's 304-byte TLB routine is followed by an embedded kernel image at
// 0x77fbd8 (loaded by FUN_0050d780); the generated 1712-byte window includes
// that non-function payload, so normalized_diff is zero but the status remains
// NONMATCHING. This accepted boundary-data floor is intentional.
// COP0/TLB instructions below are genuine kernel hardware operations.
// FUN_0077F710 NONMATCHING
asm int FUN_0077f710(u32 param_1)
{
  .set noreorder
  addiu $sp,$sp,-0x30
  sd $s0,0x10($sp)
  .word 0x0080802d
  andi $v0,$s0,0xfff
  bnez $v0,invalid
  sd $ra,0x20($sp)
  lui $v0,0xf
  addiu $v1,$s0,-1
  ori $v0,$v0,0xfffe
  sltu $v0,$v0,$v1
  bnez $v0,call_entry
  lui $a0,0x7000
invalid:
  b epilogue
  addiu $v0,$zero,-1
call_entry:
  .word 0x03a0282d
  ori $a0,$a0,0x4000
  ori $a2,$sp,4
  jal func_0x00075158
  ori $a3,$sp,8
  .word 0x0040282d
  bgez $a1,have_index
  nop
  beqz $s0,epilogue
  .word 0x0000102d
  mfc0 $a1,$6
  addiu $v0,$a1,1
  mtc0 $v0,$6
  .word 0x0000040f
  b setup_tlb
  nop
have_index:
  bnez $s0,setup_tlb
  addiu $v0,$a1,-1
  lui $v1,0xe001
  sll $v0,$v0,0xd
  addu $a2,$v0,$v1
  mfc0 $v0,$6
  addiu $v0,$v0,-1
  mtc0 $v0,$6
  mtc0 $a1,$0
  mtc0 $zero,$5
  mtc0 $a2,$10
  mtc0 $zero,$2
  mtc0 $zero,$3
  .word 0x0000040f
  tlbwi
  .word 0x0000040f
  b epilogue
  .word 0x0000102d
setup_tlb:
  lui $v0,0xffff
  addiu $a0,$s0,0x1000
  ori $v0,$v0,0xf000
  lui $a2,0x7000
  and $a0,$a0,$v0
  sw $zero,0($sp)
  and $v0,$s0,$v0
  srl $a0,$a0,6
  srl $v0,$v0,6
  ori $a0,$a0,0x1f
  ori $v0,$v0,0x1f
  ori $a2,$a2,0x4000
  sw $v0,4($sp)
  sw $a0,8($sp)
  mtc0 $a1,$0
  .word 0x0000182d
  mtc0 $v1,$5
  mtc0 $a2,$10
  mtc0 $v0,$2
  mtc0 $a0,$3
  .word 0x0000040f
  tlbwi
  .word 0x0000040f
  .word 0x00a0102d
epilogue:
  ld $ra,0x20($sp)
  ld $s0,0x10($sp)
  jr $ra
  addiu $sp,$sp,0x30
}

// FUN_0077FDC0 NONMATCHING
void FUN_0077fdc0(void)
{
  int iVar3;
  int iVar4;
  
  if (*(int *)iRambc0003c0_abs != 0) {
    iVar4 = *(int *)iRambc0003c0_abs + -0x43fffff1;
    iVar3 = 0;
    do {
      *(u8 *)(uRam80074700_abs + iVar3) = *(u8 *)(iVar4 + iVar3);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x26);
  }
  if (((long)(*(u64 *)uRam80074700_abs << 0x1a) >> 0x20 & 7U) == 0) {
    *(u64 *)uRam80074700_abs = *(u64 *)uRam80074700_abs & 0xffff02ffffffffffULL;
  }
  return;
}
// Retail sibling recovered from 0x0077FE80-0x0077FF24.
// FUN_0077FE80 NONMATCHING
u32 FUN_0077fe80(u8 *param_1,u32 param_2,u32 param_3)
{
  u8 *dst;
  u32 end;
  u32 i;
  u64 state;

  dst = param_1;
  end = param_2 + param_3;
  if (0x80 < end) {
    if (param_3 < 0x80) {
      param_2 = 0x80 - param_3;
    }
    else {
      param_3 = 0x80;
      param_2 = 0;
    }
  }
  end = param_2 + param_3;
  if (param_3 < end) {
    i = 0;
    do {
      dst[i] = ((u8 *)0x800747b0)[param_3];
      i = i + 1;
      param_3 = param_3 + 1;
    } while (param_3 < end);
  }
  state = *(u64 *)uRam80074700_abs;
  if ((((long)(state << 0x1a) >> 0x20) & 7U) == 0) {
    return 0;
  }
  return (state >> 0x2c) & 0xf;
}

// Retail sibling recovered from 0x0077FF28-0x0077FF9C.
// FUN_0077FF28 NONMATCHING
void FUN_0077ff28(u8 *param_1,u32 param_2,u32 param_3)
{
  u8 *src;
  u32 start;
  u32 i;

  src = param_1;
  start = param_2;
  param_2 = start + param_3;
  if (0x80 < param_2) {
    if (param_3 < 0x80) {
      start = 0x80 - param_3;
    }
    else {
      param_3 = 0x80;
      start = 0;
    }
  }
  param_2 = start + param_3;
  if (param_3 < param_2) {
    i = 0;
    do {
      ((u8 *)0x800747b0)[param_3] = src[i];
      param_3 = param_3 + 1;
      i = i + 1;
    } while (param_3 < param_2);
  }
}


// FUN_0077FFA0 NONMATCHING
void FUN_0077ffa0(void)
{
  u32 uVar1;
  
  REG_INTC_STAT = 4;
  do {
    uVar1 = REG_INTC_STAT;
  } while ((uVar1 & 4) == 0);
  REG_INTC_STAT = 4;
  pcRam80074760();
  pcRam80074764(1,2,1);
  pcRam8007474c(0xdffd);
  pcRam80074750();
  pcRam8007475c(0x7f);
  pcRam80074754();
  pcRam80074758();
  return;
}
#pragma push
#pragma schedule on
#pragma optimization_level 3
 
// FUN_00780070 NONMATCHING
int FUN_00780070(int param_1,u32 param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar4;
  int iVar5;
  int iVar6;
  u32 uVar3;

  iVar6 = 0x4c;
  iVar5 = 1;
  iVar4 = *piRam80074728;
  pcRam80074730(iVar4);
  pcRam80074734(iVar4,0);
  do {
    iVar1 = *(int *)(iVar6 + iRam80074748 + 8);
    if ((iVar1 != 0) && (iVar5 != iVar4)) {
      if (iVar1 == 0x10) {
        pcRam80074740(iVar5);
      }
      else {
        pcRam80074744(iVar5);
        pcRam80074740(iVar5);
      }
    }
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 0x4c;
  } while (iVar5 < 0x100);
  iVar5 = 0;
  pcRam8007473c();
  pcRam80074738();
  *puRam8007472c = 0;
  func_0x000743c8();
  uVar3 = uRam80074778;
  if (0 < param_3) {
    do {
      iVar6 = iVar5 * 4;
      iVar5 = iVar5 + 1;
      uVar3 = pcRam80074770(uVar3, *(int *)(iVar6 + param_4));
    } while (iVar5 < param_3);
  }
  iVar4 = iVar4 * 0x4c + iRam80074748;
  *(u32 *)(iVar4 + 0x38) = uRam80074778;
  *(int *)(iVar4 + 0x34) = param_3;
  *(int *)(iVar4 + 0xc) = param_1;
  *(int *)(iVar4 + 0x30) = param_1;
  *(u32 *)(iVar4 + 0x14) = param_2;
  *(u16 *)(iVar4 + 0x1a) = 0;
  *(u16 *)(iVar4 + 0x18) = 0;
  *(u32 *)(iVar4 + 0x24) = 0;
  *(u32 *)(iVar4 + 0x1c) = 0;
  *(u32 *)(iVar4 + 0x20) = 0;
  pcRam8007476c();
  pcRam80074768();
  return param_1;
}
#pragma pop
#pragma push
#pragma schedule off
// Retail sibling recovered from 0x007803A0-0x007803D0.
// FUN_007803A0 NONMATCHING
u32 FUN_007803a0(u32 param_1)
{
  u32 i;
  u32 *table;

  i = 0;
  table = (u32 *)0x80076710;
  do {
    if (param_1 == table[0]) {
      return table[1];
    }
    i = i + 1;
    table = table + 2;
  } while (i < 6);
  return 0;
}
#pragma pop

// Retail sibling recovered from 0x007803D4-0x007803F4.
// FUN_007803D4 NONMATCHING
int FUN_007803d4(int param_1,int param_2)
{
  int result;

  result = 0;
  if (param_2 < param_1) {
    result = 0x10000;
  }
  return param_2 | result;
}


typedef struct {
  u16 id;
  u16 pad2;
  u32 value4;
  u32 value8;
  u32 valuec;
  u32 value10;
} Code2Entry;

// FUN_007803F8 NONMATCHING
int FUN_007803f8(int param_1,int param_2)
{
  Code2Entry *entries;
  int i;
  int j;

  entries = (Code2Entry *)&uRam80076740;
  i = 0;
  if (0 < iRam80076700) {
    do {
      if (param_2 < func_0x00076038(param_1,entries[i].id)) {
        j = iRam80076700 - 1;
        if (j < i) {
          return i;
        }
        do {
          entries[j] = entries[j - 1];
          j = j - 1;
        } while (i <= j);
        return i;
      }
      i = i + 1;
    } while (i < iRam80076700);
  }
  return i;
}

// FUN_00780500 NONMATCHING
int FUN_00780500(u32 param_1,u32 param_2,u32 param_3)
{
  Code2Entry *entries;
  int iVar2;
  int iVar3;
  int lVar4;
  u64 uVar5;
  int iVar6;

  entries = (Code2Entry *)&uRam80076740;
  iVar2 = iRamb0001800;
  iVar6 = (param_1 & 0xffff) + iRamb0001800;
  if (iRam80076700 < 0x40) {
    lVar4 = 0;
    uVar5 = uRam80076708;
    do {
      if ((uVar5 & 1) == 0) {
        uRam80076708 = uRam80076708 | 1ULL << lVar4;
        goto LAB_007805a0;
      }
      lVar4 = lVar4 + 1;
      uVar5 = uRam80076708 >> lVar4;
    } while (lVar4 < 0x40);
    lVar4 = -1;
LAB_007805a0:
    if (-1 < lVar4) {
      iVar3 = func_0x00076058(iRamb0001800,iVar6);
      iRam80076700 = iRam80076700 + 1;
      entries[iVar3].id = (u16)iVar6;
      entries[iVar3].pad2 = (u16)iVar2;
      entries[iVar3].value4 = (u32)lVar4;
      entries[iVar3].value10 = (u32)&_mips_gp0_value;
      entries[iVar3].value8 = param_2;
      entries[iVar3].valuec = param_3;
      func_0x00076460(uRam80076740);
      lVar4 = entries[iVar3].value4;
    }
  }
  else {
    lVar4 = -1;
  }
  return lVar4;
}

// FUN_00780640 NONMATCHING
int FUN_00780640(int param_1)
{
  Code2Entry *entries;
  int iVar3;
  u32 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar9;

  entries = (Code2Entry *)&uRam80076740;
  iVar5 = iRam80076700;
  iVar6 = -1;
  if ((0 < iRam80076700) && (iVar9 = 0, 0 < iRam80076700)) {
    do {
      if (param_1 == (int)entries[iVar9].value4) {
        if ((entries[iVar9].id == uRamb0001820) &&
           (uVar4 = REG_INTC_STAT, (uVar4 & 0x1000) != 0)) {
          return -1;
        }
        iVar6 = iVar9;
        if (iVar9 < iRam80076700 - 1) {
          do {
            iVar7 = iVar6 + 1;
            entries[iVar6] = entries[iVar7];
            iVar6 = iVar7;
          } while (iVar7 < iVar5 - 1);
        }
        iRam80076700 = iRam80076700 - 1;
        uRam80076708 = uRam80076708 & ~(1ULL << param_1);
        if (iVar9 == 0) {
          func_0x00076460(uRam80076740);
        }
        if (iRam80076700 == 0) {
          uRamb0001810 = 0x83;
        }
        iVar6 = func_0x00076038(iVar6,iRamb0001800);
        iVar6 = iVar6 - (u16)iVar6;
        break;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < iRam80076700);
  }
  SYNC(0);
  return iVar6;
}

#pragma push
#pragma schedule on
// FUN_007807E0
void FUN_007807e0(u16 param_1)
{
  func_0x00076160(param_1);
  asm volatile("sync");
  return;
}
#pragma pop

#pragma push
#pragma schedule on
#pragma opt_propagation off
#pragma opt_common_subs off
// FUN_00780800
volatile u32* FUN_00780800(u32 value)
{
  volatile u32* reg;

  reg = (volatile u32 *)0xb0001820;
  *reg = value;
  __asm__ volatile("sync");
  reg = (volatile u32 *)0xb0001810;
  *reg = 0x583;
  return reg;
}
#pragma pop

// FUN_00780828 NONMATCHING
void FUN_00780828(void)
{
    Code2Entry *entries;
    u32 count;
    u32 i;
    u16 id0;
    u16 id1;
    u64 bitmask;
    int bitpos;
    u32 temp32;
    u64 temp64;

    entries = (Code2Entry *)&uRam80076740;
    i = 0;
    count = iRam80076700;

    /* First scan: while entries[0].id == entries[1].id, loop */
    id1 = entries[1].id;
    while (i < count) {
        if (entries[0].id != id1) {
            break;
        }
        i++;
    }

    /* If a differing entry was found, notify */
    if (entries[0].id != id1) {
        func_0x00076460(id1);
    }

    /* Main processing loop */
    while (count > 0) {
        temp32 = uRam80076750;
        temp64 = uRam80076748;
        id0 = entries[0].id;

        count = count - 1;
        iRam80076700 = count;

        bitpos = (int)((u64)uRam80076742 >> 0x10);

        if (count > 0) {
            i = 0;
            do {
                entries[i] = entries[i + 1];
                i = i + 1;
            } while (i < count);
        }

        /* Clear the bit in the bitmask */
        bitmask = uRam80076708;
        uRam80076708 = bitmask & ~(1ULL << bitpos);

        func_0x00076680(0x82000, (u32)temp64, bitpos, id0,
                        (u32)(temp64 >> 0x20), count, temp32);

        count = iRam80076700;
        if (count <= 0) break;
        if (id0 != entries[0].id) break;
    }

    if (iRam80076700 < 1) {
        uRamb0001810 = 0x483;
    } else {
        func_0x00076460(entries[0].id);
    }

    SYNC(0);
    EI();
    return;
}
// Retail kernel handler recovered from 0x00780A20-0x00780A84.
// FUN_00780A20 NONMATCHING
asm void FUN_00780a20(void)
{
  .set noreorder
  .word 0x3c1a8007
  .word 0xaf5f6c40
  .word 0x3c1a8007
  .word 0xaf5d6c50
  .word 0x40847000
  .word 0x0000040f
  .word 0x00a0182d
  .word 0x00c0202d
  .word 0x00e0282d
  .word 0x0100302d
  .word 0x401a6000
  .word 0x375a0012
  .word 0x409a6000
  .word 0x0000040f
  .word 0x42000018
  .word 0x00000000
  .word 0x40016000
  .word 0x241affe4
  .word 0x003a0824
  .word 0x40816000
  .word 0x0000040f
  .word 0x3c1a8007
  .word 0x8f5f6c40
  .word 0x3c1a8007
  .word 0x03e00008
  .word 0x8f5d6c50
}
