#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_00259630(void);
void FUN_00259740(void);
void FUN_00259850(int param_1,u64 param_2);
void FUN_002599c0(u16 param_1,u16 param_2);
void FUN_00259a60(u16 param_1,u16 param_2);
u64 FUN_00259d10(void);
u32 FUN_00259d80(u16 *param_1);
u32 FUN_00259e60(void);
u32 FUN_00259ea0(u16 *param_1);
u32 FUN_00259ed0(void);
u32 FUN_00259f40(u16 *param_1);
u32 FUN_00259fc0(u16 *param_1);
u32 FUN_0025a030(u16 *param_1);
extern u32 DAT_0068ead4;
extern code* PTR_FUN_0068ead0;
extern int iGpffffb668;
extern int iGpffffb66c;
extern u32 uGpffffb668;

static u32* sSflScript; // puGpffffb668


// FUN_00259640
void sflScript00259640(void)
{
    u32* work;

    K_ASSERT(sSflScript != NULL, 0x43);
    work = sSflScript;
    work[2] = work[1];
    *work |= 1;
}

// FUN_00259970 NONMATCHING
void sflScript00259970(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
}

// FUN_00259b00 NONMATCHING
void sflScript00259b00(u16 param_1)
{
    u16 arg;

    K_ASSERT(sSflScript != NULL, 0x43);
    arg = param_1;
}

// FUN_00259b60 NONMATCHING
void sflScript00259b60(u16 param_1)
{
    u16 arg;

    K_ASSERT(sSflScript != NULL, 0x43);
    arg = param_1;
}

// FUN_00259bc0 NONMATCHING
void sflScript00259bc0(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
}

// FUN_00259c60 NONMATCHING
void sflScript00259c60(u16 param_1)
{
    u16 arg;

    K_ASSERT(sSflScript != NULL, 0x43);
    arg = param_1;
}

s32 FUN_00256430();

// FUN_00259690
void sflScript00259690(u32 param_1, u32 param_2)
{
    u32* work;

    K_ASSERT(sSflScript != NULL, 0x43);
    work = sSflScript;
    work[1] = param_1;
    work[3] = param_1;
    work[4] = param_2;
}

// FUN_002596f0
u32 sflScript002596f0(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    return *sSflScript & 1;
}

// FUN_00259c10 NONMATCHING
void sflScript00259c10(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
}

// FUN_00259cc0 NONMATCHING
void sflScript00259cc0(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
}

// FUN_00259e00
u32 sflScript00259e00(void)
{
    K_ASSERT(sSflScript != NULL, 0x43);
    if (FUN_00256430() != 0) {
        return 0;
    }
    return 1;
}

// FUN_00259610
void sflScript00259610(u32* param_1)
{
    *param_1 = 0;
    param_1[5] = 0;
    sSflScript = param_1;
}

/* Recovered battle-misc harvest: 0x00259630-0x0025A030 */
// FUN_00259630


void FUN_00259630(void)



{

  uGpffffb668 = 0;

  return;

}

// FUN_00259740 NONMATCHING


void FUN_00259740(void)



{

  u16 *puVar1;

  u32 *puVar2;

  long lVar3;

  int iVar4;

  u16 *puVar5;

  u32 uVar6;

  

  if (sSflScript == (u32 *)0x0) {

    FUN_0019d3f0(0x68eb18,0x43);

  }

  puVar2 = sSflScript;

  if ((~*sSflScript & 1) == 0) {

    while( 1 ) {

      puVar1 = (u16 *)puVar2[2];

      iVar4 = (u32)*puVar1 * 8;

      if (*(short *)(&DAT_0068ead4 + iVar4) == 0) {

        puVar5 = (u16 *)0x0;

      }

      else {

        puVar5 = puVar1 + 1;

        if (((u32)puVar5 & 3) != 0) {

          puVar5 = puVar1 + 2;

        }

      }

      lVar3 = (*(code *)(&PTR_FUN_0068ead0)[(u32)*puVar1 * 2])(puVar5);

      if (lVar3 == 0) break;

      uVar6 = puVar2[2] + 2;

      if (*(u16 *)(&DAT_0068ead4 + iVar4) != 0) {

        if ((uVar6 & 3) != 0) {

          uVar6 = puVar2[2] + 4;

        }

        uVar6 = uVar6 + *(u16 *)(&DAT_0068ead4 + iVar4);

        if ((uVar6 & 1) != 0) {

          uVar6 = uVar6 + 1;

        }

      }

      puVar2[2] = uVar6;

    }

  }

  return;

}

// FUN_002599C0 NONMATCHING


void FUN_002599c0(u16 param_1,u16 param_2)



{

  u16 *puVar1;

  u16 *puVar2;

  u16 *puVar3;

  u16 uStack_4;

  u16 uStack_2;

  

  if (iGpffffb668 == 0) {

    FUN_0019d3f0(0x68eb18,0x43);

  }

  puVar2 = (u16 *)0x4;

  puVar3 = &uStack_4;

  puVar1 = puVar3;

  while (puVar1 != (u16 *)0x0) {

    *(u8 *)puVar3 = 0;

    puVar3 = (u16 *)((int)puVar3 + 1);

    puVar2 = (u16 *)((int)puVar2 + -1);

    puVar1 = puVar2;

  }

  uStack_4 = param_1;

  uStack_2 = param_2;


  return;

}

// FUN_00259A60 NONMATCHING


void FUN_00259a60(u16 param_1,u16 param_2)



{

  u16 *puVar1;

  u16 *puVar2;

  u16 *puVar3;

  u16 uStack_4;

  u16 uStack_2;

  

  if (iGpffffb668 == 0) {

    FUN_0019d3f0(0x68eb18,0x43);

  }

  puVar2 = (u16 *)0x4;

  puVar3 = &uStack_4;

  puVar1 = puVar3;

  while (puVar1 != (u16 *)0x0) {

    *(u8 *)puVar3 = 0;

    puVar3 = (u16 *)((int)puVar3 + 1);

    puVar2 = (u16 *)((int)puVar2 + -1);

    puVar1 = puVar2;

  }

  uStack_4 = param_1;

  uStack_2 = param_2;


  return;

}

// FUN_00259D10 NONMATCHING


u64 FUN_00259d10(void)



{

  u32 *puVar1;

  

  if (sSflScript == (u32 *)0x0) {

    FUN_0019d3f0(0x68eb18,0x43);

  }

  puVar1 = sSflScript;

  FUN_005225a8(0x68eb28);

  *puVar1 = *puVar1 & 0xfffffffe;

  return 0;

}

// FUN_00259D80 NONMATCHING


u32 FUN_00259d80(u16 *param_1)



{

  if (iGpffffb668 == 0) {

    FUN_0019d3f0(0x68eb18,0x43);

  }

  FUN_005225a8(0x68eb40,*param_1,param_1[1]);

  FUN_002551d0(*param_1,param_1[1]);

  return 1;

}

// FUN_00259E60 NONMATCHING


u32 FUN_00259e60(void)



{

  FUN_005225a8(0x68eb60);

  FUN_00257130();

  return 1;

}

// FUN_00259EA0


u32 FUN_00259ea0(u16 *param_1)



{

  FUN_002584e0(*param_1);

  return 1;

}

// FUN_00259ED0 NONMATCHING


u32 FUN_00259ed0(void)



{

  u32 uVar1;

  long lVar2;

  

  if (iGpffffb66c == 0) {

    FUN_00255b20();

    iGpffffb66c = 1;

    uVar1 = 0;

  }

  else {

    lVar2 = FUN_00255f30();

    if (lVar2 == 0) {

      iGpffffb66c = 0;

      uVar1 = 1;

    }

    else {

      uVar1 = 0;

    }

  }

  return uVar1;

}

// FUN_00259F40 NONMATCHING


u32 FUN_00259f40(u16 *param_1)



{

  if (iGpffffb668 == 0) {

    FUN_0019d3f0(0x68eb18,0x43);

  }

  FUN_005225a8(0x68eb80,*param_1,param_1[1]);

  FUN_00255570(*param_1,param_1[1]);

  return 1;

}

// FUN_00259FC0 NONMATCHING


u32 FUN_00259fc0(u16 *param_1)



{

  if (iGpffffb668 == 0) {

    FUN_0019d3f0(0x68eb18,0x43);

  }

  FUN_005225a8(0x68eb98,*param_1);

  FUN_00255810(*param_1);

  return 1;

}

// FUN_0025A030 NONMATCHING


u32 FUN_0025a030(u16 *param_1)



{

  u16 uVar1;

  u32 uVar2;

  u32 *puVar3;

  

  if (sSflScript == (u32 *)0x0) {

    FUN_0019d3f0(0x68eb18,0x43);

  }

  puVar3 = sSflScript;

  uVar1 = *param_1;

  if ((~*sSflScript & 2) == 0) {

    uVar2 = sSflScript[5];

    sSflScript[5] = uVar2 + 1;

    if (uVar2 + 1 == (u32)uVar1) {

      *sSflScript = *sSflScript & 0xfffffffd;

      return 1;

    }

  }

  else {

    FUN_005225a8(0x68eba8,*param_1);

    puVar3[5] = 0;

    if (uVar1 == 0) {

      return 1;

    }

  }

  *puVar3 = *puVar3 | 2;

  return 0;

}

/* Recovered battle-misc harvest: 0x00259850-0x00259850 */
// FUN_00259850 NONMATCHING


void FUN_00259850(int param_1,u64 param_2)



{

  u16 *puVar1;

  int iVar2;

  u16 *puVar3;

  

  if (iGpffffb668 == 0) {

    FUN_0019d3f0(0x68eb18,0x43);

  }

  iVar2 = iGpffffb668;

  puVar1 = *(u16 **)(iGpffffb668 + 0xc);

  *puVar1 = (short)param_1;

  puVar3 = puVar1 + 1;

  if (*(short *)(&DAT_0068ead4 + param_1 * 8) != 0) {

    if (((u32)puVar3 & 3) != 0) {

      puVar3 = puVar1 + 2;

    }

    FUN_00521250(puVar3,param_2,*(short *)(&DAT_0068ead4 + param_1 * 8));

    puVar3 = (u16 *)((int)puVar3 + (u32)*(u16 *)(&DAT_0068ead4 + param_1 * 8));

  }

  *(u16 **)(iVar2 + 0xc) = puVar3;

  if (*(int *)(iVar2 + 0x10) < (int)puVar3 - *(int *)(iVar2 + 4)) {

    FUN_0019d3f0(0x68eb18,0xb2);

  }

  if ((*(u32 *)(iVar2 + 0xc) & 1) != 0) {

    *(u32 *)(iVar2 + 0xc) = *(u32 *)(iVar2 + 0xc) + 1;

  }

  return;

}
