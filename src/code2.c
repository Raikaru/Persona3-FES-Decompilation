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
extern u64 uRam80074700;
extern int iRam80076700;
extern int iRam80074748;
extern u64 uRam80076708;
extern u16 uRam80076740;
extern u16 uRam80076742;
extern u16 uRamb0001810;
extern u16 uRamb0001820;
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

// FUN_0077F710 NONMATCHING
int FUN_0077f710(u32 param_1)
{
  int iVar1;
  int iVar2;
  
  if (((param_1 & 0xfff) == 0) && (0xffffe < param_1 - 1)) {
    iVar2 = func_0x00075158(0x70004000, 0, 0, 0);
    if (iVar2 < 0) {
      if (param_1 == 0) {
        return 0;
      }
      SYNC(0x10);
      iVar1 = Wired + 1;
    }
    else {
      iVar1 = Wired;
      if (param_1 == 0) {
        SYNC(0x10);
        TLB_write_indexed_entry(iVar2, 0x70004000, 0, 0, 0);
        SYNC(0x10);
        return 0;
      }
    }
    SYNC(0x10);
    TLB_write_indexed_entry(0, 0x70004000, 
      (param_1 & 0xfffff000) >> 6 | 0x1f,
      ((param_1 + 0x1000) & 0xfffff000) >> 6 | 0x1f,
      0);
    SYNC(0x10);
    iVar2 = 0;
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

// FUN_0077FDC0 NONMATCHING
void FUN_0077fdc0(void)
{
  int iVar3;
  int iVar4;
  
  if (iRambc0003c0 != 0) {
    iVar4 = iRambc0003c0 + -0x43fffff1;
    iVar3 = 0;
    do {
      *(u8 *)(iVar3 + -0x7ff8b900) = *(u8 *)(iVar4 + iVar3);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x26);
  }
  if (((long)(uRam80074700 << 0x1a) >> 0x20 & 7U) == 0) {
    uRam80074700 = uRam80074700 & 0xffff02ffffffffffULL;
  }
  return;
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

// FUN_007803F8 NONMATCHING
int FUN_007803f8(int param_1,int param_2)
{
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < iRam80076700) {
    do {
      if (param_2 < func_0x00076038(param_1,*(u16 *)(iVar4 * 0x14 + -0x7ff898c0))) {
        iVar3 = iRam80076700 + -1;
        if (iVar3 < iVar4) {
          return iVar4;
        }
        do {
          *(u32 *)(iVar3 * 0x14 + -0x7ff898c0) = *(u32 *)((iVar3 + -1) * 0x14 + -0x7ff898c0);
          *(u32 *)(iVar3 * 0x14 + -0x7ff898c4) = *(u32 *)((iVar3 + -1) * 0x14 + -0x7ff898c4);
          *(u32 *)(iVar3 * 0x14 + -0x7ff898b8) = *(u32 *)((iVar3 + -1) * 0x14 + -0x7ff898b8);
          *(u32 *)(iVar3 * 0x14 + -0x7ff898bc) = *(u32 *)((iVar3 + -1) * 0x14 + -0x7ff898bc);
          *(u32 *)(iVar3 * 0x14 + -0x7ff898b0) = *(u32 *)((iVar3 + -1) * 0x14 + -0x7ff898b0);
          iVar3 = iVar3 + -1;
        } while (iVar4 <= iVar3);
        return iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iRam80076700);
  }
  return iVar4;
}

// FUN_00780500 NONMATCHING
int FUN_00780500(u32 param_1,u32 param_2,u32 param_3)
{
  int iVar2;
  int iVar3;
  int lVar4;
  u64 uVar5;
  int iVar6;
  
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
      iVar3 = iVar3 * 0x14;
      iRam80076700 = iRam80076700 + 1;
      *(u16 *)(iVar3 + -0x7ff898be) = (u16)iVar2;
      *(u16 *)(iVar3 + -0x7ff898c0) = (u16)iVar6;
      *(int *)(iVar3 + -0x7ff898bc) = (int)lVar4;
      *(u32 *)(iVar3 + -0x7ff898b0) = (u32)&_mips_gp0_value;
      *(u32 *)(iVar3 + -0x7ff898b8) = param_2;
      *(u32 *)(iVar3 + -0x7ff898b4) = param_3;
      func_0x00076460(uRam80076740);
      lVar4 = *(int *)(iVar3 + -0x7ff898bc);
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
  int iVar3;
  u32 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar9;
  
  iVar5 = iRam80076700;
  iVar6 = -1;
  if ((0 < iRam80076700) && (iVar9 = 0, 0 < iRam80076700)) {
    do {
      if (param_1 == *(int *)(iVar9 * 0x14 + -0x7ff898bc)) {
        if ((*(u16 *)(iVar9 * 0x14 + -0x7ff898c0) == uRamb0001820) &&
           (uVar4 = REG_INTC_STAT, (uVar4 & 0x1000) != 0)) {
          return -1;
        }
        iVar6 = iVar9;
        if (iVar9 < iRam80076700 + -1) {
          do {
            iVar7 = iVar6 + 1;
            iVar3 = iVar7 * 0x14;
            iVar6 = iVar6 * 0x14;
            *(u32 *)(iVar6 + -0x7ff898c0) = *(u32 *)(iVar3 + -0x7ff898c0);
            *(u32 *)(iVar6 + -0x7ff898c4) = *(u32 *)(iVar3 + -0x7ff898c4);
            *(u32 *)(iVar6 + -0x7ff898b8) = *(u32 *)(iVar3 + -0x7ff898b8);
            *(u32 *)(iVar6 + -0x7ff898bc) = *(u32 *)(iVar3 + -0x7ff898bc);
            *(u32 *)(iVar6 + -0x7ff898b0) = *(u32 *)(iVar3 + -0x7ff898b0);
            iVar6 = iVar7;
          } while (iVar7 < iVar5 + -1);
        }
        iRam80076700 = iRam80076700 + -1;
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

// FUN_007807E0 NONMATCHING
void FUN_007807e0(u16 param_1)
{
  func_0x00076160(param_1);
  SYNC(0);
  return;
}

// FUN_00780828 NONMATCHING
void FUN_00780828(void)
{
  int sVar1;
  u32 uVar2;
  u64 uVar3;
  u32 uVar4;
  int iVar5;
  int iVar6;
  int lVar7;
  u32 uVar8;
  int iStack_ac;
  u32 uStack_a8;
  u32 uStack_a4;
  
  iVar6 = 0;
  do {
    if (iRam80076700 <= iVar6) goto LAB_007808bc;
    sVar1 = *(short *)(iVar6 * 0x14 + -0x7ff898c0);
    iVar6 = iVar6 + 1;
  } while (sRam80076740 == sVar1);
  func_0x00076460(sVar1);
LAB_007808bc:
  do {
    uVar4 = uRam80076750;
    uVar3 = uRam80076748;
    sVar1 = sRam80076740;
    lVar7 = 0;
    iRam80076700 = iRam80076700 + -1;
    iStack_ac = (int)((u64)uRam80076742 >> 0x10);
    if (0 < iRam80076700) {
      do {
        iVar6 = lVar7 * 0x14;
        iVar5 = lVar7 + 1;
        lVar7 = iVar5;
        iVar5 = iVar5 * 0x14;
        *(u32 *)(iVar6 + -0x7ff898c0) = *(u32 *)(iVar5 + -0x7ff898c0);
        *(u32 *)(iVar6 + -0x7ff898c4) = *(u32 *)(iVar5 + -0x7ff898c4);
        *(u32 *)(iVar6 + -0x7ff898b8) = *(u32 *)(iVar5 + -0x7ff898b8);
        *(u32 *)(iVar6 + -0x7ff898bc) = *(u32 *)(iVar5 + -0x7ff898bc);
        *(u32 *)(iVar6 + -0x7ff898b0) = *(u32 *)(iVar5 + -0x7ff898b0);
      } while (lVar7 < iRam80076700);
    }
    uRam80076708 = uRam80076708 & ~(1ULL << (long)iStack_ac);
    uStack_a8 = (u32)uVar3;
    uStack_a4 = (u32)(uVar3 >> 0x20);
    func_0x00076680(0x82000,uStack_a8,(long)iStack_ac,sVar1,uStack_a4,iRam80076700,uVar4);
  } while ((0 < iRam80076700) && (sVar1 == sRam80076740));
  if (iRam80076700 < 1) {
    uRamb0001810 = 0x483;
  }
  else {
    func_0x00076460(sRam80076740);
  }
  SYNC(0);
  EI();
  return;
}
