#include "temporary.h"
/* FUSION_GLOBALS */
int *piGpffffb98c;
typedef int (*code)(...);
/* FUSION_EXACT_PROTOS */
u32 FUN_003c8b50();
#include "Kosaka/k_assert.h"
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u32 gp0xffffaa08;
extern u32 gp0xffffaa10;
extern u32 gp0xffffaa14;

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif
extern char DAT_006a3e18[];
extern u32 DAT_006a3f70;
extern u32 DAT_006a3f88;
extern u32 DAT_006a3f8c;
extern u32 DAT_006a3f90;
extern u32 DAT_006a41e8;
extern u32 DAT_006a41f8;
extern u32 DAT_006a4218;
extern u32 DAT_006a4220;
extern u32 DAT_006a4228;
extern u32 DAT_006a4230;
extern u32 DAT_006a4240;
extern u32 DAT_006a4244;
extern u32 DAT_006a4248;
extern u32 DAT_006a424c;
extern u32 DAT_006a4250;
extern u32 DAT_006a4258;
extern u32 DAT_006a4260;
extern u32 DAT_006a4268;
extern u32 DAT_007cd718;
extern u32 DAT_007ce0cc;
extern u32 DAT_007ce680;
extern u32 DAT_0095be80;
extern u32 DAT_0095be84;
extern u32 DAT_0095be85;
extern u32 DAT_0095be88;
extern u32 DAT_0095be8c;
extern u32 DAT_0095be8d;
extern u32 DAT_0095be90;
extern u32 DAT_0095be94;
extern u32 DAT_0095be95;
extern u32 DAT_0095be98;
extern u32 DAT_0095be9c;
extern u32 DAT_0095be9d;
extern code DAT_00960090;
extern code DAT_00960178;
extern code DAT_0096017c;
extern u32 LAB_003c84bc;
extern u32 LAB_003cf728;
extern u32 LAB_003cf7a4;
extern u32 LAB_003cf9d8;
extern u8 * PTR_LAB_006a4060;
extern u8 * PTR_s_facility_pss_battle_pak_006a4040;
extern u32 fGpffff808c;
extern u32 fGpffff80e0;
extern u32 fGpffff8110;
extern u32 fGpffff81f0;
extern u32 iGpffffb730;
extern u32 iGpffffb98c;
extern u32 uGpffffaa18;
extern u32 uGpffffaa1a;
extern u32 uGpffffaa1c;
extern u32 uGpffffaa1e;
extern u32 uGpffffaa20;
extern u32 uGpffffaa22;
extern u32 uGpffffaa24;
extern u32 uGpffffaa26;
extern u32 uGpffffb98c;
extern code DAT_00960090;
extern code DAT_00960178;
extern code DAT_0096017c;

// Retail calls this with $a0 untouched (no argument), so keep the
// unprototyped decl instead of including kwlnTask.h's real prototype.
int kwlnTaskGetWorkData(void);
/* Region 0x390000-0x3CFFFF recovered prototypes */
u32 fclMisc003c9ab0(void);
void fclMisc003c9b00(u32 param_1, void* param_2, void* param_3);
void fclMisc003c9ba0(u32 param_1, void* param_2);
u32 fclMisc003c9c10(u32 param_1, void* param_2, void* param_3);

/* Region call-cast macros */
#define FUN_003c8400(...) ((u32 (*)(...))FUN_003c8400)(__VA_ARGS__)
#define FUN_003c8550(...) ((u64 (*)(...))FUN_003c8550)(__VA_ARGS__)
#define FUN_003c8770(...) ((u64 (*)(...))FUN_003c8770)(__VA_ARGS__)
#define FUN_003c8810(...) ((u64 (*)(...))FUN_003c8810)(__VA_ARGS__)
#define FUN_003c88d0(...) ((void (*)(...))FUN_003c88d0)(__VA_ARGS__)
#define FUN_003c89a0(...) ((u64 (*)(...))FUN_003c89a0)(__VA_ARGS__)
#define FUN_003c8b50(...) ((u32 (*)(...))FUN_003c8b50)(__VA_ARGS__)
#define FUN_003c8d80(...) ((u8 (*)(...))FUN_003c8d80)(__VA_ARGS__)
#define FUN_003c8da0(...) ((void (*)(...))FUN_003c8da0)(__VA_ARGS__)
#define FUN_003c8dc0(...) ((void (*)(...))FUN_003c8dc0)(__VA_ARGS__)
#define FUN_003c8dd0(...) ((void (*)(...))FUN_003c8dd0)(__VA_ARGS__)
#define FUN_003c8de0(...) ((u64 (*)(...))FUN_003c8de0)(__VA_ARGS__)
#define FUN_003c8ea0(...) ((u16 (*)(...))FUN_003c8ea0)(__VA_ARGS__)
#define FUN_003c8ec0(...) ((u32 (*)(...))FUN_003c8ec0)(__VA_ARGS__)
#define FUN_003c8f20(...) ((void (*)(...))FUN_003c8f20)(__VA_ARGS__)
#define FUN_003c8f40(...) ((void (*)(...))FUN_003c8f40)(__VA_ARGS__)
#define FUN_003c8f70(...) ((void (*)(...))FUN_003c8f70)(__VA_ARGS__)
#define FUN_003c8fa0(...) ((void (*)(...))FUN_003c8fa0)(__VA_ARGS__)
#define FUN_003c9000(...) ((void (*)(...))FUN_003c9000)(__VA_ARGS__)
#define FUN_003c91b0(...) ((u8 (*)(...))FUN_003c91b0)(__VA_ARGS__)
#define FUN_003c9240(...) ((void (*)(...))FUN_003c9240)(__VA_ARGS__)
#define FUN_003c9290(...) ((u64 (*)(...))FUN_003c9290)(__VA_ARGS__)
#define FUN_003c9340(...) ((u8 (*)(...))FUN_003c9340)(__VA_ARGS__)
#define FUN_003c9390(...) ((void (*)(...))FUN_003c9390)(__VA_ARGS__)
#define FUN_003c9460(...) ((u32 (*)(...))FUN_003c9460)(__VA_ARGS__)
#define FUN_003c94e0(...) ((u32 (*)(...))FUN_003c94e0)(__VA_ARGS__)
#define FUN_003c9570(...) ((void (*)(...))FUN_003c9570)(__VA_ARGS__)
#define FUN_003c9790(...) ((u8 (*)(...))FUN_003c9790)(__VA_ARGS__)
#define FUN_003c9850(...) ((u64 (*)(...))FUN_003c9850)(__VA_ARGS__)
#define FUN_003c9cd0(...) ((void (*)(...))FUN_003c9cd0)(__VA_ARGS__)
#define FUN_003c9d00(...) ((void (*)(...))FUN_003c9d00)(__VA_ARGS__)
#define FUN_003c9d80(...) ((void (*)(...))FUN_003c9d80)(__VA_ARGS__)
#define FUN_003c9e00(...) ((void (*)(...))FUN_003c9e00)(__VA_ARGS__)
#define FUN_003c9e30(...) ((void (*)(...))FUN_003c9e30)(__VA_ARGS__)
#define FUN_003c9e70(...) ((void (*)(...))FUN_003c9e70)(__VA_ARGS__)
#define FUN_003c9ee0(...) ((s8 (*)(...))FUN_003c9ee0)(__VA_ARGS__)
#define FUN_003c9f10(...) ((void (*)(...))FUN_003c9f10)(__VA_ARGS__)
#define FUN_003c9f60(...) ((void (*)(...))FUN_003c9f60)(__VA_ARGS__)
#define FUN_003c9fb0(...) ((void (*)(...))FUN_003c9fb0)(__VA_ARGS__)
#define FUN_003c9fe0(...) ((void (*)(...))FUN_003c9fe0)(__VA_ARGS__)
#define FUN_003ca230(...) ((u64 (*)(...))FUN_003ca230)(__VA_ARGS__)
#define FUN_003ca610(...) ((u64 (*)(...))FUN_003ca610)(__VA_ARGS__)
#define FUN_003ca660(...) ((u64 (*)(...))FUN_003ca660)(__VA_ARGS__)
#define FUN_003ca6b0(...) ((void (*)(...))FUN_003ca6b0)(__VA_ARGS__)
#define FUN_003ca780(...) ((u64 (*)(...))FUN_003ca780)(__VA_ARGS__)
#define FUN_003ca960(...) ((void (*)(...))FUN_003ca960)(__VA_ARGS__)
#define FUN_003cacc0(...) ((void (*)(...))FUN_003cacc0)(__VA_ARGS__)
#define FUN_003cb050(...) ((void (*)(...))FUN_003cb050)(__VA_ARGS__)
#define FUN_003cb100(...) ((void (*)(...))FUN_003cb100)(__VA_ARGS__)
#define FUN_003cb1f0(...) ((void (*)(...))FUN_003cb1f0)(__VA_ARGS__)
#define FUN_003cb960(...) ((void (*)(...))FUN_003cb960)(__VA_ARGS__)
#define FUN_003cba50(...) ((void (*)(...))FUN_003cba50)(__VA_ARGS__)
#define FUN_003ccc40(...) ((void (*)(...))FUN_003ccc40)(__VA_ARGS__)
#define FUN_003cd0b0(...) ((void (*)(...))FUN_003cd0b0)(__VA_ARGS__)
#define FUN_003cd5a0(...) ((void (*)(...))FUN_003cd5a0)(__VA_ARGS__)
#define FUN_003cda00(...) ((u32 (*)(...))FUN_003cda00)(__VA_ARGS__)
#define FUN_003cda60(...) ((void (*)(...))FUN_003cda60)(__VA_ARGS__)
#define FUN_003cdba0(...) ((u32 (*)(...))FUN_003cdba0)(__VA_ARGS__)
#define FUN_003cdc80(...) ((u32 (*)(...))FUN_003cdc80)(__VA_ARGS__)
#define FUN_003cdcd0(...) ((u64 (*)(...))FUN_003cdcd0)(__VA_ARGS__)
#define FUN_003cdd80(...) ((u8 (*)(...))FUN_003cdd80)(__VA_ARGS__)
#define FUN_003cde00(...) ((void (*)(...))FUN_003cde00)(__VA_ARGS__)
#define FUN_003cde70(...) ((void (*)(...))FUN_003cde70)(__VA_ARGS__)
#define FUN_003cdee0(...) ((void (*)(...))FUN_003cdee0)(__VA_ARGS__)
#define FUN_003cdf40(...) ((void (*)(...))FUN_003cdf40)(__VA_ARGS__)
#define FUN_003ce060(...) ((void (*)(...))FUN_003ce060)(__VA_ARGS__)
#define FUN_003ce180(...) ((void (*)(...))FUN_003ce180)(__VA_ARGS__)
#define FUN_003ce2a0(...) ((u64 (*)(...))FUN_003ce2a0)(__VA_ARGS__)
#define FUN_003cea50(...) ((u64 (*)(...))FUN_003cea50)(__VA_ARGS__)
#define FUN_003cf6c0(...) ((short (*)(...))FUN_003cf6c0)(__VA_ARGS__)
#define FUN_003cf960(...) ((u64 (*)(...))FUN_003cf960)(__VA_ARGS__)
#define FUN_003cfb50(...) ((void (*)(...))FUN_003cfb50)(__VA_ARGS__)

// FUN_003c9ab0
u32 fclMisc003c9ab0(void)
{
    int ctx;

    ctx = kwlnTaskGetWorkData();
    K_ASSERT(ctx != 0, 0x683);
    return *(u32*)(ctx + 8) & 0x20;
}

// FUN_003c9b00
void fclMisc003c9b00(u32 param_1, void* param_2, void* param_3)
{
    int ctx;

    ctx = kwlnTaskGetWorkData();
    if (param_3 != NULL) {
        memcpy((void *)(ctx + 0x1c), param_3, 0x54);
    } else {
        memset((void *)(ctx + 0x1c), 0, 0x54);
    }
    if (param_2 != NULL) {
        memcpy((void *)(ctx + 0x20), param_2, 0x34);
    }
}

// FUN_003c9ba0
void fclMisc003c9ba0(u32 param_1, void* param_2)
{
    int ctx;

    ctx = kwlnTaskGetWorkData();
    K_ASSERT(param_2 != NULL, 0x697);
    memcpy((void *)(ctx + 0x20), param_2, 0x34);
}

// FUN_003c9c10
u32 fclMisc003c9c10(u32 param_1, void* param_2, void* param_3)
{
    int ctx;

    ctx = kwlnTaskGetWorkData();
    K_ASSERT(param_2 != NULL && param_3 != NULL, 0x69e);
    memcpy((void *)(ctx + 0x20), param_2, 0x34);
    memcpy((void *)(ctx + 0x74), param_3, 0x34);
    if ((*(u32*)(ctx + 8) & 0x40) == 0) {
        *(s16*)(ctx + 0x16) = (s16)(*(s8*)(ctx + 0xe8) * *(s16*)(ctx + 0x14));
    }
    *(u32*)(ctx + 8) |= 0x40;
    return 1;
}

#undef FUN_003c8400
// FUN_003C8400 NONMATCHING


u32 FUN_003c8400(long param_1,int param_2)



{

  int iVar1;

  long lVar2;

  int iVar3;

  int iVar4;

  u32 *puVar5;

  int iVar6;

  

  if (param_1 == 0) {

    FUN_0019d3f0(0x6a3e18,0x396);

  }

  if ((param_2 < 0) || (0xb < param_2)) {

    FUN_0019d3f0(0x6a3e18,0x397);

  }

  iVar6 = (int)param_1;

  iVar1 = iVar6 + param_2 * 0xc;

  puVar5 = (u32 *)(iVar1 + 0x1c);

  if ((*(u32 *)(iVar1 + 0x1c) & 2) == 0) {

    for (iVar3 = *(int *)(*(int *)(iVar6 + 0x18) + 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x10)) {

      iVar4 = *(int *)(iVar3 + 0x14);

      if (*(int *)(iVar4 + 4) == param_2) goto LAB_003c84bc;

    }

    iVar4 = 0;

LAB_003c84bc:

    if (iVar4 == 0) {

      *(int *)(iVar1 + 0x20) = param_2;

      lVar2 = FUN_003c4910(*(int *)(iVar6 + 0x18),*(u16 *)(*(int *)(iVar6 + 0x18) + 0x10) + 1,0);

      if (lVar2 == 0) {

        FUN_0019d3f0(0x7bb4d8,0x50);

      }

      *(u32 **)((int)lVar2 + 0x14) = puVar5;

      return 1;

    }

  }

  if ((*(u32 *)(iVar1 + 0x1c) & 4) != 0) {

    *puVar5 = *puVar5 & 0xfffffffb;

  }

  return 0;

}
#define FUN_003c8400(...) ((u32 (*)(...))FUN_003c8400)(__VA_ARGS__)
#undef FUN_003c8550
// FUN_003C8550 NONMATCHING


u64 FUN_003c8550(long param_1)



{

  u32 uVar1;

  long lVar2;

  u32 *puVar3;

  int iVar4;

  int iVar5;

  u8 auStack_20 [32];

  

  if (param_1 == 0) {

    FUN_0019d3f0(0x6a3e18,0x3ad);

  }

  iVar4 = (int)param_1;

  iVar5 = *(int *)(*(int *)(iVar4 + 0x18) + 4);

  if (iVar5 != 0) {

    puVar3 = *(u32 **)(iVar5 + 0x14);

    if (puVar3[2] == 0) {

      if (puVar3[1] == 0) {

        FUN_00523ac8(auStack_20,0x6a3ee0);

      }

      else {

        lVar2 = FUN_0017d800();

        if (lVar2 == 0) {

          FUN_00523ac8(auStack_20,0x6a3f40,puVar3[1]);

        }

        else if (puVar3[1] == 1) {

          FUN_00523ac8(auStack_20,0x6a3f00);

        }

        else if (puVar3[1] == 9) {

          FUN_00523ac8(auStack_20,0x6a3f20);

        }

        else {

          FUN_00523ac8(auStack_20,0x6a3f40);

        }

      }

      uVar1 = FUN_00112370(auStack_20);

      puVar3[2] = uVar1;

    }

    else {

      lVar2 = FUN_00111f30();

      if (lVar2 != 0) {

        *puVar3 = *puVar3 | 2;

        FUN_003c49e0(*(int *)(iVar4 + 0x18),*(int *)(iVar4 + 0x18) + 4,iVar5);

      }

    }

  }

  puVar3 = (u32 *)(iVar4 + 0x1c);

  for (iVar5 = 0; iVar5 < 0xb; iVar5 = iVar5 + 1) {

    uVar1 = *puVar3;

    if ((uVar1 & 4) != 0) {

      if (puVar3[2] == 0) {

        *puVar3 = uVar1 & 0xfffffffb;

        *puVar3 = uVar1 & 0xfffffff9;

      }

      else {

        lVar2 = FUN_00111f30();

        if (lVar2 != 0) {

          uVar1 = *puVar3;

          *puVar3 = uVar1 & 0xfffffffb;

          *puVar3 = uVar1 & 0xfffffff9;

          FUN_001124b0(puVar3[2]);

          puVar3[2] = 0;

        }

      }

    }

    puVar3 = puVar3 + 3;

  }

  return 0;

}
#define FUN_003c8550(...) ((u64 (*)(...))FUN_003c8550)(__VA_ARGS__)
#undef FUN_003c8770
// FUN_003C8770 NONMATCHING


u64 FUN_003c8770(long param_1,long param_2)



{

  int iVar1;

  

  if (param_1 == 0) {

    FUN_0019d3f0(0x6a3e18,0x3eb);

  }

  if ((param_2 < 0) || (0xb < param_2)) {

    FUN_0019d3f0(0x6a3e18,0x3ec);

  }

  iVar1 = (int)param_1 + (int)param_2 * 0xc;

  *(u32 *)(iVar1 + 0x1c) = *(u32 *)(iVar1 + 0x1c) | 4;

  return 0;

}
#define FUN_003c8770(...) ((u64 (*)(...))FUN_003c8770)(__VA_ARGS__)
#undef FUN_003c8810
// FUN_003C8810 NONMATCHING


u64 FUN_003c8810(int *param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1[6] + 4);

  while (iVar1 != 0) {

    if (*(int *)(*(int *)(iVar1 + 0x14) + 8) == 0) {

      iVar1 = FUN_003c49e0(param_1[6],param_1[6] + 4);

    }

    else {

      iVar1 = *(int *)(iVar1 + 0x10);

    }

  }

  iVar1 = *(int *)(*param_1 + 4);

  while (iVar1 != 0) {

    if ((*(u32 *)(*(int *)(iVar1 + 0x14) + 4) & 2) == 0) {

      iVar1 = FUN_003c49e0(*param_1,*param_1 + 4);

    }

    else {

      iVar1 = *(int *)(iVar1 + 0x10);

    }

  }

  return 0;

}
#define FUN_003c8810(...) ((u64 (*)(...))FUN_003c8810)(__VA_ARGS__)
#undef FUN_003c88d0
// FUN_003C88D0 NONMATCHING


void FUN_003c88d0(void)



{

  int *piVar1;

  int iVar2;

  

  iVar2 = FUN_003c44d0(0xa0,0,0,0);

  piVar1 = *(int **)(iVar2 + 0x24);

  *piVar1 = iVar2;

  iVar2 = FUN_003c44d0(0xc,0,0,0);

  piVar1[6] = iVar2;

  piVar1[1] = piVar1[1] | 1;

  DAT_0095be80 = 0xffffffff;

  DAT_0095be84 = 0;

  DAT_0095be85 = 0;

  DAT_0095be88 = 0xffffffff;

  DAT_0095be8c = 1;

  DAT_0095be8d = 1;

  piGpffffb98c = piVar1;

  FUN_00194b20(0,0x6a3f60,0x18bf,0x3c89a0,0,0);

  return;

}
#define FUN_003c88d0(...) ((void (*)(...))FUN_003c88d0)(__VA_ARGS__)
#undef FUN_003c89a0
// FUN_003C89A0 NONMATCHING


u64 FUN_003c89a0(void)



{

  u32 uVar1;

  int *piVar2;

  long lVar3;

  int iVar4;

  

  piVar2 = piGpffffb98c;

  if ((piGpffffb98c[1] & 1U) != 0) {

    if ((piGpffffb98c[1] & 2U) == 0) {

      if (*(int *)(*piGpffffb98c + 4) == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(*(int *)(*piGpffffb98c + 4) + 0x14);

      }

      if (iVar4 != 0) {

        piGpffffb98c[1] = piGpffffb98c[1] & 0xfffffffe;




        uVar1 = *(u32 *)(iVar4 + 4);

        *(u32 *)(iVar4 + 4) = uVar1 | 2;

        *(u32 *)(iVar4 + 4) = uVar1 | 3;

      }

    }

    else {



      if (lVar3 != 0) {

        piVar2[1] = piVar2[1] & 0xfffffffd;


        FUN_003c4a90(*piVar2,*piVar2 + 4);

        for (iVar4 = 0; iVar4 < 0xb; iVar4 = iVar4 + 1) {


        }

      }

    }

  }

  iVar4 = *(int *)(*piVar2 + 4);

  if (((iVar4 != 0) && ((*(u32 *)(*(int *)(iVar4 + 0x14) + 4) & 2) != 0)) &&

     (lVar3 = FUN_003c8b50(piVar2), lVar3 != 0)) {

    piVar2[1] = piVar2[1] | 1;

    FUN_003c49e0(*piVar2,*piVar2 + 4,iVar4);

  }


  return 0;

}
#define FUN_003c89a0(...) ((u64 (*)(...))FUN_003c89a0)(__VA_ARGS__)
#undef FUN_003c8b50
// FUN_003C8B50 NONMATCHING


u32 FUN_003c8b50(long param_1,int param_2)



{

  u32 uVar1;

  int iVar2;

  u32 uVar3;

  long lVar4;

  int iVar5;

  

  iVar5 = (int)param_1;

  if ((*(u32 *)(param_2 + 4) & 4) != 0) {

    uVar3 = FUN_003a3da0(*(u32 *)(param_2 + 0x10));

    if ((uVar3 & 0x3300) == 0) {


      if ((*(u32 *)(iVar5 + 0x14) & 1) == 0) {

        if (param_1 == 0) {

          FUN_0019d3f0(0x6a3e18,0x3eb);

        }

        *(u32 *)(iVar5 + 0x1c) = *(u32 *)(iVar5 + 0x1c) | 4;

      }

      uVar1 = *(u32 *)(param_2 + 0x2c);

      if ((*(u32 *)(iVar5 + 0x14) & 1 << (uVar1 & 0x1f)) == 0) {

        if (param_1 == 0) {

          FUN_0019d3f0(0x6a3e18,0x3eb);

        }

        if (((int)uVar1 < 0) || (0xb < (int)uVar1)) {

          FUN_0019d3f0(0x6a3e18,0x3ec);

        }

        iVar5 = iVar5 + uVar1 * 0xc;

        *(u32 *)(iVar5 + 0x1c) = *(u32 *)(iVar5 + 0x1c) | 4;

      }

      return 1;

    }

    return 0;

  }

  if ((*(u32 *)(param_2 + 4) & 1) != 0) {

    if (param_1 == 0) {

      FUN_0019d3f0(0x6a3e18,0x3e3);

    }

    if ((*(u32 *)(iVar5 + 0x1c) & 2) == 0) {

      return 0;

    }

    iVar2 = *(int *)(param_2 + 0x2c);

    if (param_1 == 0) {

      FUN_0019d3f0(0x6a3e18,0x3e3);

    }

    if ((*(u32 *)(iVar5 + iVar2 * 0xc + 0x1c) & 2) == 0) {

      return 0;

    }

    *(u32 *)(param_2 + 4) = *(u32 *)(param_2 + 4) & 0xfffffffe;


  }



  if (lVar4 == 0) {


    *(u32 *)(param_2 + 4) = *(u32 *)(param_2 + 4) | 4;

  }

  return 0;

}
#define FUN_003c8b50(...) ((u32 (*)(...))FUN_003c8b50)(__VA_ARGS__)
#undef FUN_003c8d80
// FUN_003C8D80


u8 FUN_003c8d80(void)



{

  return *(int *)(*(int *)(iGpffffb98c + 0x18) + 4) == 0;

}
#define FUN_003c8d80(...) ((u8 (*)(...))FUN_003c8d80)(__VA_ARGS__)
#undef FUN_003c8da0
// FUN_003C8DA0


void FUN_003c8da0(u32 param_1)



{

  *(u32 *)(iGpffffb98c + 0x14) = *(u32 *)(iGpffffb98c + 0x14) | param_1;

  return;

}
#define FUN_003c8da0(...) ((void (*)(...))FUN_003c8da0)(__VA_ARGS__)
#undef FUN_003c8dc0
// FUN_003C8DC0


void FUN_003c8dc0(u32 param_1)



{

  *(u32 *)(iGpffffb98c + 0x14) = param_1;

  return;

}
#define FUN_003c8dc0(...) ((void (*)(...))FUN_003c8dc0)(__VA_ARGS__)
#undef FUN_003c8dd0
// FUN_003C8DD0


void FUN_003c8dd0(u32 param_1)



{

  *(u32 *)(iGpffffb98c + 0xc) = param_1;

  return;

}
#define FUN_003c8dd0(...) ((void (*)(...))FUN_003c8dd0)(__VA_ARGS__)
#undef FUN_003c8de0
// FUN_003C8DE0


u64 FUN_003c8de0(int param_1,int param_2,int param_3,u16 param_4)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  

  piVar2 = piGpffffb98c;

  if (piGpffffb98c[3] == 0) {

    FUN_0019d3f0(DAT_006a3e18,0x4ae);

  }

  iVar1 = piVar2[3];

  iVar3 = *piVar2;

  iVar3 = FUN_003c4910(iVar3,*(u16 *)(iVar3 + 0x10) + 1,0x30);

  piVar2 = *(int **)(iVar3 + 0x14);

  *piVar2 = iVar3;

  piVar2[0xb] = param_1;

  piVar2[8] = param_2;

  piVar2[9] = param_3;

  piVar2[10] = iVar1;

  *(u16 *)((int)piVar2 + 0xe) = param_4;

  return 0;

}
#define FUN_003c8de0(...) ((u64 (*)(...))FUN_003c8de0)(__VA_ARGS__)
#undef FUN_003c8ea0
// FUN_003C8EA0


u16 FUN_003c8ea0(void)



{

  return *(u16 *)(*piGpffffb98c + 0x10);

}
#define FUN_003c8ea0(...) ((u16 (*)(...))FUN_003c8ea0)(__VA_ARGS__)
#undef FUN_003c8ec0
// FUN_003C8EC0 NONMATCHING


u32 FUN_003c8ec0(int param_1,int param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(*piGpffffb98c + 4);

  while( 1 ) {

    if (iVar1 == 0) {

      return 0;

    }

    if ((*(int *)(*(int *)(iVar1 + 0x14) + 0x2c) == param_1) &&

       (*(int *)(*(int *)(iVar1 + 0x14) + 0x20) == param_2)) break;

    iVar1 = *(int *)(iVar1 + 0x10);

  }

  return 1;

}
#define FUN_003c8ec0(...) ((u32 (*)(...))FUN_003c8ec0)(__VA_ARGS__)
#undef FUN_003c8f20
// FUN_003C8F20


void FUN_003c8f20(void)



{

  *(u32 *)(iGpffffb98c + 4) = *(u32 *)(iGpffffb98c + 4) | 2;

  return;

}
#define FUN_003c8f20(...) ((void (*)(...))FUN_003c8f20)(__VA_ARGS__)
#undef FUN_003c8f40
#undef FUN_003c8810
// FUN_003C8F40


void FUN_003c8f40(void)



{
  FUN_003c8810((int *)uGpffffb98c);


  return;

}
#define FUN_003c8810(...) ((u64 (*)(...))FUN_003c8810)(__VA_ARGS__)
#define FUN_003c8f40(...) ((void (*)(...))FUN_003c8f40)(__VA_ARGS__)
#undef FUN_003c8f70
// FUN_003C8F70 NONMATCHING


void FUN_003c8f70(void)



{

  FUN_00109f60(2,0);


  return;

}
#define FUN_003c8f70(...) ((void (*)(...))FUN_003c8f70)(__VA_ARGS__)
#undef FUN_003c8fa0
// FUN_003C8FA0 NONMATCHING


void FUN_003c8fa0(void)



{

  int iVar1;

  

  if ((*(int *)(*piGpffffb98c + 4) != 0) &&

     (iVar1 = *(int *)(*(int *)(*piGpffffb98c + 4) + 0x14), (*(u32 *)(iVar1 + 4) & 2) != 0)) {


    *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 4;

  }

  return;

}
#define FUN_003c8fa0(...) ((void (*)(...))FUN_003c8fa0)(__VA_ARGS__)
#undef FUN_003c9000
// FUN_003C9000 NONMATCHING


void FUN_003c9000(u32 param_1,float param_2,float param_3,int param_4,int param_5,

                 char param_6,int param_7,u64 param_8)



{

  u64 uVar1;

  int iVar2;

  u16 uVar3;

  

  iVar2 = param_7 * 0xc + iGpffffb98c;

  if ((*(u32 *)(iVar2 + 0x1c) & 2) != 0) {

    uVar1 = FUN_001158b0(0,*(u32 *)(iVar2 + 0x24),param_8);

    iVar2 = (int)uVar1;

    *(float *)(iVar2 + 0x10) = (float)param_4;

    *(float *)(iVar2 + 0x14) = (float)param_5;

    *(u32 *)(iVar2 + 0x2c) = param_1;

    *(char *)(iVar2 + 0x19) = -1 - param_6;

    param_2 = param_2 * 4096.0;

    if (param_2 < 2.1474836e+09) {

      uVar3 = (u16)(int)param_2;

    }

    else {

      uVar3 = (u16)(int)(param_2 - 2.1474836e+09);

    }

    *(u16 *)(iVar2 + 0x28) = uVar3;

    param_3 = param_3 * 4096.0;

    if (param_3 < 2.1474836e+09) {

      uVar3 = (u16)(int)param_3;

    }

    else {

      uVar3 = (u16)(int)(param_3 - 2.1474836e+09);

    }

    *(u16 *)(iVar2 + 0x2a) = uVar3;

    FUN_001127d0(uVar1,1);

    FUN_00115980(uVar1);

  }

  return;

}
#define FUN_003c9000(...) ((void (*)(...))FUN_003c9000)(__VA_ARGS__)
#undef FUN_003c91b0
// FUN_003C91B0 NONMATCHING


u8 FUN_003c91b0(long param_1,u64 param_2)



{

  int iVar1;

  u64 uVar2;

  int *piVar3;

  

  piVar3 = (int *)param_1;

  if (param_1 != 0) {

    *piVar3 = -1;

    *(u8 *)(piVar3 + 1) = 0;

    *(u8 *)((int)piVar3 + 5) = 0;

    piVar3[2] = -1;

    *(u8 *)(piVar3 + 3) = 1;

    *(u8 *)((int)piVar3 + 0xd) = 1;

  }

  iVar1 = *piVar3;

  if (iVar1 < 0) {

    uVar2 = FUN_003a2d80(param_2);

    *piVar3 = (int)uVar2;

    FUN_003a4360(uVar2,5);

  }

  return iVar1 < 0;

}
#define FUN_003c91b0(...) ((u8 (*)(...))FUN_003c91b0)(__VA_ARGS__)
#undef FUN_003c9240
// FUN_003C9240 NONMATCHING


void FUN_003c9240(int *param_1)



{


  if (-1 < *param_1) {

    FUN_003a3060();

    *param_1 = -1;

    *(u8 *)(param_1 + 1) = 0;

    *(u8 *)((int)param_1 + 5) = 0;

  }

  return;

}
#define FUN_003c9240(...) ((void (*)(...))FUN_003c9240)(__VA_ARGS__)
#undef FUN_003c9290
// FUN_003C9290 NONMATCHING


u64 FUN_003c9290(int *param_1,u64 param_2,u64 param_3)



{

  if (-1 < *param_1) {

    FUN_003a3e10(*param_1,0x200000);

    FUN_003a30c0(*param_1,param_3,0);

    FUN_003a5210(*param_1,1,5,0x20,0);

    FUN_003a8600(*param_1,param_2);

    *(u8 *)(param_1 + 1) = 1;

  }

  return 0;

}
#define FUN_003c9290(...) ((u64 (*)(...))FUN_003c9290)(__VA_ARGS__)
#undef FUN_003c9340
// FUN_003C9340 NONMATCHING


u8 FUN_003c9340(int *param_1)



{

  u8 uVar1;

  

  if (*param_1 < 0) {

    uVar1 = 0;

  }

  else if ((*(char *)((int)param_1 + 5) == '\0') || ((char)param_1[1] != '\x02')) {

    uVar1 = (u8)param_1[1];

  }

  else {

    uVar1 = 0;

  }

  return uVar1;

}
#define FUN_003c9340(...) ((u8 (*)(...))FUN_003c9340)(__VA_ARGS__)
#undef FUN_003c9390
// FUN_003C9390 NONMATCHING


void FUN_003c9390(int *param_1)



{

  char cVar1;

  long lVar2;

  

  if (-1 < *param_1) {

    cVar1 = (char)param_1[1];

    if (cVar1 == '\x03') {


    }

    else if (cVar1 == '\x02') {

      if (-1 < param_1[2]) {

        param_1[2] = -1;

      }

      if (*(char *)((int)param_1 + 5) == '\0') {

        *(u8 *)(param_1 + 1) = 3;

      }

    }

    else if ((cVar1 == '\x01') && (lVar2 = FUN_003a2580(*param_1), lVar2 < 0)) {

      *(u8 *)(param_1 + 1) = 2;

    }

  }

  return;

}
#define FUN_003c9390(...) ((void (*)(...))FUN_003c9390)(__VA_ARGS__)
#undef FUN_003c9460
// FUN_003C9460 NONMATCHING


u32 FUN_003c9460(long param_1)



{

  u32 uVar1;

  int *piVar2;

  

  if (param_1 == 0) {

    uVar1 = 0;

  }

  else {

    piVar2 = (int *)param_1;

    if (*piVar2 < 0) {

      uVar1 = 0;

    }

    else {

      FUN_003a25f0(*piVar2,0);

      FUN_003a2a30(*piVar2);

      FUN_003a3420(*piVar2,0);

      *(u8 *)(piVar2 + 1) = 0;

      uVar1 = 1;

    }

  }

  return uVar1;

}
#define FUN_003c9460(...) ((u32 (*)(...))FUN_003c9460)(__VA_ARGS__)
#undef FUN_003c94e0
// FUN_003C94E0 NONMATCHING






u32 FUN_003c94e0(void)



{

  u64 uVar1;

  

  DAT_0095be90 = 0xffffffff;

  DAT_0095be94 = 0;

  DAT_0095be95 = 0;

  DAT_0095be98 = 0xffffffff;

  DAT_0095be9c = 1;

  DAT_0095be9d = 1;

  uVar1 = FUN_003a2d80();

  DAT_0095be90 = (u32)uVar1;

  FUN_003a4360(uVar1,6);

  return 1;

}
#define FUN_003c94e0(...) ((u32 (*)(...))FUN_003c94e0)(__VA_ARGS__)
#undef FUN_003c9570
// FUN_003C9570 NONMATCHING


void FUN_003c9570(u64 param_1)



{

  u8 bVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  int *piVar8;

  int aiStack_30 [8];

  int aiStack_10 [4];

  

  iVar2 = 0;

  piVar8 = (int *)&DAT_006a3f70;

  piVar7 = aiStack_30;

  iVar6 = 3;

  do {

    iVar3 = *piVar8;

    iVar4 = piVar8[1];

    piVar8 = piVar8 + 2;

    iVar6 = iVar6 + -1;

    *piVar7 = iVar3;

    piVar7[1] = iVar4;

    piVar7 = piVar7 + 2;

  } while (0 < iVar6);

  aiStack_10[0] = DAT_006a3f88;

  aiStack_10[1] = DAT_006a3f8c;

  aiStack_10[2] = DAT_006a3f90;

  iVar6 = FUN_003af380();

  bVar1 = (short)iVar6 != -1;

  if (bVar1) {

    iVar3 = FUN_003af390();

  }

  else {

    iVar2 = FUN_003af390();

    iVar6 = aiStack_30[iVar2 * 2];

    iVar3 = aiStack_30[iVar2 * 2 + 1];

  }

  iVar4 = FUN_003af360();

  if ((short)iVar4 == -1) {

    iVar4 = 0x140 - (iVar6 >> 1);

  }

  iVar5 = FUN_003af370();

  if ((short)iVar5 == -1) {

    iVar5 = 0xe0 - (iVar3 * 0x19 >> 1);

  }

  if (bVar1) {

    FUN_003a3ce0(param_1,iVar4 << 4,iVar5 << 3);

    FUN_003a8650(param_1,iVar4 << 4,iVar5 << 3,0,iVar6 << 4,iVar3 * 200);

  }

  else {

    FUN_003a3ce0(param_1,0x4d0,0x4e0);

    iVar2 = aiStack_10[iVar2];

    FUN_003a8650(param_1,0,0x408,0,0x2800,iVar2 << 3);

    FUN_003a6a80(param_1,0x254,iVar2 + 0x71);

  }

  return;

}
#define FUN_003c9570(...) ((void (*)(...))FUN_003c9570)(__VA_ARGS__)
#undef FUN_003c9790
// FUN_003C9790 NONMATCHING


u8 FUN_003c9790(u64 param_1)



{

  u8 bVar1;

  

  bVar1 = -1 < DAT_0095be90;

  if (bVar1) {

    FUN_003a3e10(DAT_0095be90,0x200000);

    FUN_003a30c0(DAT_0095be90,param_1,0);


    FUN_003a5210(DAT_0095be90,0,0,0x20,0);

    DAT_0095be94 = 1;

    FUN_003a27c0(DAT_0095be90,0xffffffffffffffff);

  }

  return bVar1;

}
#define FUN_003c9790(...) ((u8 (*)(...))FUN_003c9790)(__VA_ARGS__)
#undef FUN_003c9850
// FUN_003C9850 NONMATCHING


u64 FUN_003c9850(u64 param_1,long param_2,u16 param_3,u16 param_4)



{

  u8 *puVar1;

  u64 uVar2;

  u64 uVar3;

  int iVar4;

  u32 *puVar5;

  u8 **ppuVar6;

  int *piVar7;

  u32 auStack_60 [16];

  int aiStack_20 [8];

  

  if ((param_2 < 0) || (4 < param_2)) {

    FUN_0019d3f0(0x6a3e18,0x661);

  }

  ppuVar6 = &PTR_s_facility_pss_battle_pak_006a4040;

  piVar7 = aiStack_20;

  iVar4 = 5;

  do {

    puVar1 = *ppuVar6;

    ppuVar6 = ppuVar6 + 1;

    iVar4 = iVar4 + -1;

    *piVar7 = (int)puVar1;

    piVar7 = piVar7 + 1;

  } while (0 < iVar4);

  ppuVar6 = &PTR_LAB_006a4060;

  puVar5 = auStack_60;

  iVar4 = 0xf;

  do {

    puVar1 = *ppuVar6;

    ppuVar6 = ppuVar6 + 1;

    iVar4 = iVar4 + -1;

    *puVar5 = (u32)puVar1;

    puVar5 = puVar5 + 1;

  } while (0 < iVar4);

  uVar2 = (*DAT_00960178)(0xec,0x40000);

  FUN_00521408(uVar2,0,0xec);

  piVar7 = (int *)uVar2;

  piVar7[1] = 1;

  iVar4 = (int)param_2;

  *piVar7 = iVar4;

  piVar7[0x33] = aiStack_20[iVar4];

  FUN_00521250(piVar7 + 0x37,auStack_60 + iVar4 * 3,0xc);

  *(u16 *)(piVar7 + 3) = param_3;

  *(u16 *)((int)piVar7 + 0xe) = param_4;

  if ((short)piVar7[3] < 1) {

    *(u16 *)(piVar7 + 3) = 1;

  }

  if (*(short *)((int)piVar7 + 0xe) < 1) {

    *(u16 *)((int)piVar7 + 0xe) = 1;

  }

  piVar7[6] = -1;

  uVar3 = FUN_00194b20(param_1,0x6a40a0,10,0x3ca230,0x3ca6b0,uVar2);

  FUN_00194b20(uVar3,0x6a40b0,0x1070,0x3ca610,0,uVar2);

  FUN_00194b20(uVar3,0x6a40c0,0x18aa,0x3ca660,0,uVar2);

  iVar4 = FUN_001339a0(0,uVar3,0x1488,0,0xffffffffffffffff);

  piVar7[0x31] = iVar4;

  FUN_005225a8(&gp0xffffaa08,0x6a3e18,0x67c);

  FUN_005225a8(0x6a40d8);

  FUN_001052b0(0x6a40d8);

  return uVar3;

}
#define FUN_003c9850(...) ((u64 (*)(...))FUN_003c9850)(__VA_ARGS__)
#undef FUN_003c9cd0
// FUN_003C9CD0


void FUN_003c9cd0(u64 param_1,u32 param_2)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  *(u32 *)(iVar1 + 0x18) = param_2;

  return;

}
#define FUN_003c9cd0(...) ((void (*)(...))FUN_003c9cd0)(__VA_ARGS__)
#undef FUN_003c9d00
// FUN_003C9D00 NONMATCHING


void FUN_003c9d00(u64 param_1,u64 param_2)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) | (u32)param_2;

  FUN_005225a8(&gp0xffffaa08,0x6a3e18,0x6b3);

  FUN_005225a8(0x6a40f0,param_2);

  FUN_001052b0(0x6a40f0,param_2);

  return;

}
#define FUN_003c9d00(...) ((void (*)(...))FUN_003c9d00)(__VA_ARGS__)
#undef FUN_003c9d80
// FUN_003C9D80 NONMATCHING


void FUN_003c9d80(u64 param_1,u64 param_2)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) & ~(u32)param_2;

  FUN_005225a8(&gp0xffffaa08,0x6a3e18,0x6b9);

  FUN_005225a8(0x6a4110,param_2);

  FUN_001052b0(0x6a4110,param_2);

  return;

}
#define FUN_003c9d80(...) ((void (*)(...))FUN_003c9d80)(__VA_ARGS__)
#undef FUN_003c9e00
// FUN_003C9E00


void FUN_003c9e00(u64 param_1,u16 param_2)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  *(u16 *)(iVar1 + 0xea) = param_2;

  return;

}
#define FUN_003c9e00(...) ((void (*)(...))FUN_003c9e00)(__VA_ARGS__)
#undef FUN_003c9e30
// FUN_003C9E30


void FUN_003c9e30(u64 param_1,u8 param_2,u8 param_3)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  *(u8 *)(iVar1 + 0xe9) = param_2;

  *(u8 *)(iVar1 + 0xe8) = param_3;

  return;

}
#define FUN_003c9e30(...) ((void (*)(...))FUN_003c9e30)(__VA_ARGS__)
#undef FUN_003c9e70
// FUN_003C9E70 NONMATCHING


void FUN_003c9e70(u64 param_1,char param_2)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  *(char *)(iVar1 + 0xe8) = param_2;

  if (param_2 < '\0') {

    *(u8 *)(iVar1 + 0xe8) = 0;

  }

  else if (*(char *)(iVar1 + 0xe9) <= param_2) {

    *(char *)(iVar1 + 0xe8) = *(char *)(iVar1 + 0xe9) + -1;

  }

  return;

}
#define FUN_003c9e70(...) ((void (*)(...))FUN_003c9e70)(__VA_ARGS__)
#undef FUN_003c9ee0
// FUN_003C9EE0


s8 FUN_003c9ee0(void)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  return *(char *)(iVar1 + 0xe8);

}
#define FUN_003c9ee0(...) ((s8 (*)(...))FUN_003c9ee0)(__VA_ARGS__)
#undef FUN_003c9f10
// FUN_003C9F10 NONMATCHING


void FUN_003c9f10(u64 param_1,short param_2)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  *(short *)(iVar1 + 0xc) = param_2;

  if (param_2 == 0) {

    *(u16 *)(iVar1 + 0xc) = 1;

  }

  return;

}
#define FUN_003c9f10(...) ((void (*)(...))FUN_003c9f10)(__VA_ARGS__)
#undef FUN_003c9f60
// FUN_003C9F60 NONMATCHING


void FUN_003c9f60(u64 param_1,short param_2)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  *(short *)(iVar1 + 0xe) = param_2;

  if (param_2 == 0) {

    *(u16 *)(iVar1 + 0xe) = 1;

  }

  return;

}
#define FUN_003c9f60(...) ((void (*)(...))FUN_003c9f60)(__VA_ARGS__)
#undef FUN_003c9fb0
// FUN_003C9FB0


void FUN_003c9fb0(void)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  *(u16 *)(iVar1 + 0x14) = 0xf;

  return;

}
#define FUN_003c9fb0(...) ((void (*)(...))FUN_003c9fb0)(__VA_ARGS__)
#undef FUN_003c9fe0
// FUN_003C9FE0 NONMATCHING


void FUN_003c9fe0(int *param_1)



{

  int iVar1;

  int iVar2;

  u64 uVar3;

  u8 auStack_4 [4];

  

  iVar2 = param_1[0x32];

  FUN_005225a8(&gp0xffffaa08,0x6a3e18,0x718);

  FUN_005225a8(0x6a4130);

  FUN_001052b0(0x6a4130);

  FUN_00119a20();

  FUN_005225a8(&gp0xffffaa08,0x6a3e18,0x71a);

  FUN_005225a8(0x6a4150);

  FUN_001052b0(0x6a4150);

  uVar3 = FUN_00102100(iVar2,0,auStack_4);

  uVar3 = FUN_00112420(uVar3);

  FUN_00119a80(6,uVar3);

  uVar3 = FUN_00102100(iVar2,1,auStack_4);

  uVar3 = FUN_00112420(uVar3);

  FUN_00119a80(8,uVar3);

  uVar3 = FUN_00102100(iVar2,2,auStack_4);

  uVar3 = FUN_00112420(uVar3);

  FUN_00119a80(10,uVar3);

  uVar3 = FUN_00102100(iVar2,3,auStack_4);

  iVar1 = FUN_00112420(uVar3);

  param_1[0x34] = iVar1;

  iVar1 = *param_1;

  if ((iVar1 == 4) || (iVar1 == 2)) {

    uVar3 = FUN_00102100(iVar2,4,auStack_4);

    iVar2 = FUN_00112420(uVar3);

    param_1[0x36] = iVar2;

  }

  else if (iVar1 == 3) {

    uVar3 = FUN_00102100(iVar2,4,auStack_4);

    iVar2 = FUN_00112420(uVar3);

    param_1[0x35] = iVar2;

  }

  else if ((iVar1 == 1) || (iVar1 == 0)) {

    uVar3 = FUN_00102100(iVar2,4,auStack_4);

    iVar2 = FUN_00112420(uVar3);

    param_1[0x35] = iVar2;

  }

  FUN_005225a8(&gp0xffffaa08,0x6a3e18,0x730);

  FUN_005225a8(0x6a4170);

  FUN_001052b0(0x6a4170);

  return;

}
#define FUN_003c9fe0(...) ((void (*)(...))FUN_003c9fe0)(__VA_ARGS__)
#undef FUN_003ca230
// FUN_003CA230 NONMATCHING


u64 FUN_003ca230(void)



{

  int iVar1;

  short sVar2;

  int iVar3;

  u32 uVar4;

  u32 uVar5;

  u64 uVar6;

  long lVar7;

  

  uVar6 = FUN_00195540();

  iVar3 = (int)uVar6;

  iVar1 = *(int *)(iVar3 + 4);

  if (iVar1 == 4) {

    uVar5 = *(u32 *)(iVar3 + 8);

    if ((uVar5 & 8) == 0) {

      if ((uVar5 & 0x10) != 0) {

        sVar2 = *(short *)(iVar3 + 0x10) + 1;

        *(short *)(iVar3 + 0x10) = sVar2;

        *(short *)(iVar3 + 0x12) = 0xff - (short)((sVar2 * 0xff) / (int)*(short *)(iVar3 + 0xe));

        if (*(short *)(iVar3 + 0xe) <= *(short *)(iVar3 + 0x10)) {

          *(u16 *)(iVar3 + 0x10) = 0;

          uVar5 = *(u32 *)(iVar3 + 8);

          *(u32 *)(iVar3 + 8) = uVar5 & 0xffffffef;

          *(u32 *)(iVar3 + 8) = uVar5 & 0xffffffee;

        }

      }

    }

    else {

      *(u32 *)(iVar3 + 8) = uVar5 | 1;

      sVar2 = *(short *)(iVar3 + 0x10) + 1;

      *(short *)(iVar3 + 0x10) = sVar2;

      *(short *)(iVar3 + 0x12) = (short)((sVar2 * 0xff) / (int)*(short *)(iVar3 + 0xc));

      if (*(short *)(iVar3 + 0xc) <= *(short *)(iVar3 + 0x10)) {

        *(u16 *)(iVar3 + 0x10) = 0;

        *(u32 *)(iVar3 + 8) = *(u32 *)(iVar3 + 8) & 0xfffffff7;

      }

    }

    if ((*(u32 *)(iVar3 + 8) & 0x40) != 0) {

      if (*(char *)(iVar3 + 0xe8) == '\0') {

        sVar2 = *(short *)(iVar3 + 0x16) + -1;

        *(short *)(iVar3 + 0x16) = sVar2;

        if (sVar2 < 1) {

          *(u32 *)(iVar3 + 8) = *(u32 *)(iVar3 + 8) & 0xffffffbf;

        }

      }

      else if ((*(char *)(iVar3 + 0xe8) == '\x01') &&

              (sVar2 = *(short *)(iVar3 + 0x16) + 1, *(short *)(iVar3 + 0x16) = sVar2,

              *(short *)(iVar3 + 0x14) <= sVar2)) {

        *(u32 *)(iVar3 + 8) = *(u32 *)(iVar3 + 8) & 0xffffffbf;

      }

    }

    (**(code **)(iVar3 + 0xdc))(uVar6);

    if ((*(u32 *)(iVar3 + 8) & 1) == 0) {

      uVar5 = FUN_00133b70(*(u32 *)(iVar3 + 0xc4));

      FUN_00133b80(*(u32 *)(iVar3 + 0xc4),0,

                   *(u32 *)(iVar3 + 0x18) & 0xffffff00 | uVar5 & 0xff);

    }

    else {

      if ((*(u32 *)(iVar3 + 8) & 4) != 0) {

        uVar5 = FUN_00133b70(*(u32 *)(iVar3 + 0xc4));

        FUN_00133b80(*(u32 *)(iVar3 + 0xc4),0,

                     *(u32 *)(iVar3 + 0x18) & 0xffffff00 | uVar5 & 0xff);

        *(u32 *)(iVar3 + 8) = *(u32 *)(iVar3 + 8) & 0xfffffffb;

      }

      uVar5 = FUN_00133b70(*(u32 *)(iVar3 + 0xc4));

      FUN_00133b80(*(u32 *)(iVar3 + 0xc4),*(u16 *)(iVar3 + 0x22),

                   *(u32 *)(iVar3 + 0x18) & 0xffffff00 | uVar5 & 0xff);

      FUN_00133b40(*(u32 *)(iVar3 + 0xc4),*(u8 *)(iVar3 + 0x12));

    }

  }

  else {

    if (iVar1 != 3) {

      if (iVar1 != 2) {

        if (iVar1 != 1) {

          return 0;

        }

        *(u32 *)(iVar3 + 4) = 2;

        FUN_005225a8(&gp0xffffaa08,0x6a3e18,0x73d);

        FUN_005225a8(0x6a4190);

        FUN_001052b0(0x6a4190);

      }

      *(u32 *)(iVar3 + 4) = 3;

      uVar4 = FUN_00100d80(*(u32 *)(iVar3 + 0xcc),1);

      *(u32 *)(iVar3 + 200) = uVar4;

      FUN_005225a8(&gp0xffffaa08,0x6a3e18,0x741);

      FUN_005225a8(0x6a41b0,*(u32 *)(iVar3 + 0xcc),*(u32 *)(iVar3 + 200));

      FUN_001052b0(0x6a41b0,*(u32 *)(iVar3 + 0xcc),*(u32 *)(iVar3 + 200));

    }

    lVar7 = FUN_001016b0(*(u32 *)(iVar3 + 200));

    if (lVar7 != 0) {


      *(u32 *)(iVar3 + 4) = 4;

      *(u32 *)(iVar3 + 8) = *(u32 *)(iVar3 + 8) | 0x20;

      FUN_005225a8(&gp0xffffaa08,0x6a3e18,0x747);

      FUN_005225a8(0x6a41d0);

      FUN_001052b0(0x6a41d0);

    }

  }

  return 0;

}
#define FUN_003ca230(...) ((u64 (*)(...))FUN_003ca230)(__VA_ARGS__)
#undef FUN_003ca610
// FUN_003CA610 NONMATCHING


u64 FUN_003ca610(void)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  if (((*(u32 *)(iVar1 + 8) & 1) != 0) && (*(short *)(iVar1 + 0x22) != 0)) {

    (**(code **)(iVar1 + 0xe0))();

  }

  return 0;

}
#define FUN_003ca610(...) ((u64 (*)(...))FUN_003ca610)(__VA_ARGS__)
#undef FUN_003ca660
// FUN_003CA660 NONMATCHING


u64 FUN_003ca660(void)



{

  int iVar1;

  

  iVar1 = FUN_00195540();

  if (((*(u32 *)(iVar1 + 8) & 1) != 0) && (*(short *)(iVar1 + 0x22) != 0)) {

    (**(code **)(iVar1 + 0xe4))();

  }

  return 0;

}
#define FUN_003ca660(...) ((u64 (*)(...))FUN_003ca660)(__VA_ARGS__)
#undef FUN_003ca6b0
// FUN_003CA6B0 NONMATCHING


void FUN_003ca6b0(void)



{

  u64 uVar1;

  u64 uVar2;

  int iVar3;

  

  uVar1 = FUN_00195540();

  uVar2 = FUN_00119a60(6);

  FUN_001124b0(uVar2);

  uVar2 = FUN_00119a60(8);

  FUN_001124b0(uVar2);

  uVar2 = FUN_00119a60(10);

  FUN_001124b0(uVar2);

  iVar3 = (int)uVar1;

  FUN_001124b0(*(u32 *)(iVar3 + 0xd0));

  if (*(int *)(iVar3 + 0xd4) != 0) {

    FUN_001124b0();

  }

  if (*(int *)(iVar3 + 0xd8) != 0) {

    FUN_001124b0();

  }

  FUN_00100ec0(*(u32 *)(iVar3 + 200));

  (*DAT_0096017c)(uVar1);

  return;

}
#define FUN_003ca6b0(...) ((void (*)(...))FUN_003ca6b0)(__VA_ARGS__)
#undef FUN_003ca780
// FUN_003CA780 NONMATCHING


u64

FUN_003ca780(u32 param_1,u32 param_2,float param_3,float param_4,int param_5,

            int param_6,u32 param_7,u64 param_8,u16 param_9,u16 param_10

            ,u64 param_11)



{

  int iVar1;

  u64 uVar2;

  u16 uVar3;

  

  uVar2 = FUN_001158b0(0,param_11,param_8);

  iVar1 = (int)uVar2;

  *(float *)(iVar1 + 0x10) = (float)param_5;

  *(float *)(iVar1 + 0x14) = (float)param_6;

  *(u32 *)(iVar1 + 0x2c) = param_1;

  *(char *)(iVar1 + 0x19) = -1 - (char)param_7;

  *(char *)(iVar1 + 0x30) = (char)((u32)param_7 >> 0x18);

  *(char *)(iVar1 + 0x31) = (char)((u32)param_7 >> 0x10);

  *(char *)(iVar1 + 0x32) = (char)((u32)param_7 >> 8);

  *(u16 *)(iVar1 + 0x24) = param_9;

  *(u16 *)(iVar1 + 0x26) = param_10;

  *(u32 *)(iVar1 + 0x20) = param_2;

  param_3 = param_3 * 4096.0;

  if (param_3 < 2.1474836e+09) {

    uVar3 = (u16)(int)param_3;

  }

  else {

    uVar3 = (u16)(int)(param_3 - 2.1474836e+09);

  }

  *(u16 *)(iVar1 + 0x28) = uVar3;

  param_4 = param_4 * 4096.0;

  if (param_4 < 2.1474836e+09) {

    uVar3 = (u16)(int)param_4;

  }

  else {

    uVar3 = (u16)(int)(param_4 - 2.1474836e+09);

  }

  *(u16 *)(iVar1 + 0x2a) = uVar3;

  FUN_001127d0(uVar2,1);

  FUN_00115980(uVar2);

  return 0;

}
#define FUN_003ca780(...) ((u64 (*)(...))FUN_003ca780)(__VA_ARGS__)
#undef FUN_003ca960
// FUN_003CA960 NONMATCHING


void FUN_003ca960(int param_1)



{

  float *pfVar1;

  float *pfVar2;

  float *pfVar3;

  int iVar4;

  long lVar5;

  int iVar6;

  float fVar7;

  int iVar8;

  float fStack_8;

  u32 uStack_4;

  

  pfVar2 = (float *)0x8;

  pfVar3 = &fStack_8;

  pfVar1 = pfVar3;

  while (pfVar1 != (float *)0x0) {

    *(u8 *)pfVar3 = 0;

    pfVar3 = (float *)((int)pfVar3 + 1);

    pfVar2 = (float *)((int)pfVar2 + -1);

    pfVar1 = pfVar2;

  }

  if (*(char *)(param_1 + 0xe8) == '\0') {

    iVar4 = param_1 + 0x1c;

  }

  else {

    iVar4 = param_1 + 0x70;

  }

  if ((*(u32 *)(param_1 + 8) & 0x40) == 0) {

    if ((*(u32 *)(param_1 + 8) & 2) == 0) {

      FUN_00133180(0,CONCAT44(uStack_4,fStack_8),iVar4,iVar4 + 4,*(u16 *)(param_1 + 0x12));

    }

    else {

      FUN_001332f0(0,CONCAT44(uStack_4,fStack_8),iVar4,iVar4 + 4,*(u16 *)(param_1 + 0x12));

    }

  }

  else {

    lVar5 = (long)*(short *)(param_1 + 0x16);

    fVar7 = (float)(int)*(short *)(param_1 + 0x14);

    iVar4 = (int)(fGpffff808c * fVar7);

    iVar8 = (int)(fGpffff80e0 * fVar7);

    if (*(char *)(param_1 + 0xe8) == '\0') {

      lVar5 = (long)((int)*(short *)(param_1 + 0x14) - (int)*(short *)(param_1 + 0x16));

      iVar6 = param_1 + 0x70;

    }

    else {

      iVar6 = param_1 + 0x1c;

    }

    if (lVar5 <= iVar8) {

      fVar7 = (float)FUN_0052e878((fGpffff81f0 + 0.0) -

                                  fGpffff8110 * ((float)(int)lVar5 / (float)iVar8));

      fStack_8 = (fVar7 + 1.0) * 80.0;

      if (*(char *)(param_1 + 0xe8) == '\0') {

        fStack_8 = fStack_8 * -1.0;

      }

      if ((*(u32 *)(param_1 + 8) & 2) == 0) {

        FUN_00133180(0,CONCAT44(uStack_4,fStack_8),iVar6,iVar6 + 4,

                     (int)((float)(int)*(short *)(param_1 + 0x12) * (1.0 - (fVar7 + 1.0))));

      }

      else {

        FUN_001332f0(0,CONCAT44(uStack_4,fStack_8),iVar6,iVar6 + 4);

      }

    }

    if (*(char *)(param_1 + 0xe8) == '\0') {

      iVar6 = param_1 + 0x1c;

    }

    else {

      iVar6 = param_1 + 0x70;

    }

    if (iVar4 <= lVar5) {

      fVar7 = (float)FUN_0052e878((fGpffff81f0 + 0.0) -

                                  fGpffff8110 * ((float)((int)lVar5 - iVar4) / (float)iVar8));

      fStack_8 = (1.0 - (fVar7 + 1.0)) * -80.0;

      if (*(char *)(param_1 + 0xe8) == '\0') {

        fStack_8 = fStack_8 * -1.0;

      }

      if ((*(u32 *)(param_1 + 8) & 2) == 0) {

        FUN_00133180(0,CONCAT44(uStack_4,fStack_8),iVar6,iVar6 + 4,

                     (int)((float)(int)*(short *)(param_1 + 0x12) * (fVar7 + 1.0)));

      }

      else {

        FUN_001332f0(0,CONCAT44(uStack_4,fStack_8),iVar6,iVar6 + 4);

      }

    }

  }

  return;

}
#define FUN_003ca960(...) ((void (*)(...))FUN_003ca960)(__VA_ARGS__)
#undef FUN_003cacc0
// FUN_003CACC0 NONMATCHING


void FUN_003cacc0(int param_1)



{

  short sVar1;

  int iVar2;

  short *psVar3;

  short *psVar4;

  int iVar5;

  long lVar6;

  short asStack_20 [8];

  short asStack_10 [8];

  

  psVar4 = (short *)&DAT_006a41e8;

  psVar3 = asStack_10;

  iVar2 = 5;

  do {

    sVar1 = *psVar4;

    psVar4 = psVar4 + 1;

    iVar2 = iVar2 + -1;

    *psVar3 = sVar1;

    psVar3 = psVar3 + 1;

  } while (0 < iVar2);

  psVar4 = (short *)&DAT_006a41f8;

  psVar3 = asStack_20;

  iVar2 = 5;

  do {

    sVar1 = *psVar4;

    psVar4 = psVar4 + 1;

    iVar2 = iVar2 + -1;

    *psVar3 = sVar1;

    psVar3 = psVar3 + 1;

  } while (0 < iVar2);

  iVar2 = *(char *)(param_1 + 0xe9) + -3;

  lVar6 = 0;

  psVar4 = asStack_20 + iVar2;

  psVar3 = asStack_10 + iVar2;

  while( 1 ) {

    iVar5 = *(char *)(param_1 + 0xe9) + -1;

    if (iVar5 <= lVar6) break;

    iVar5 = (int)lVar6;

    if (*(char *)(param_1 + 0xe8) == lVar6) {

      FUN_003ca780(0,0,0x3f800000,0x3f800000,(int)*psVar3 + iVar5 * *psVar4,10,

                   *(u16 *)(param_1 + 0x12) | 0xff00,0x18,0,0,*(u32 *)(param_1 + 0xd0));

      FUN_003ca780(0,0,0x3f800000,0x3f800000,(int)*psVar3 + iVar5 * *psVar4,8,

                   *(u16 *)(param_1 + 0x12) | 0xff00,iVar5 * 2 + 0x1a,0,0,

                   *(u32 *)(param_1 + 0xd0));

    }

    else {

      FUN_003ca780(0,0,0x3f800000,0x3f800000,(int)*psVar3 + iVar5 * *psVar4,10,

                   *(u16 *)(param_1 + 0x12) | 0xff00,0x17,0,0,*(u32 *)(param_1 + 0xd0));

      FUN_003ca780(0,0,0x3f800000,0x3f800000,(int)*psVar3 + iVar5 * *psVar4,8,

                   *(u16 *)(param_1 + 0x12) | 0xff00,iVar5 * 2 + 0x19,0,0,

                   *(u32 *)(param_1 + 0xd0));

    }

    lVar6 = (long)(iVar5 + 1);

  }

  if ((long)*(char *)(param_1 + 0xe8) == (long)iVar5) {

    FUN_003ca780(0,0,0x3f800000,0x3f800000,(int)asStack_10[iVar2] + iVar5 * asStack_20[iVar2],10,

                 *(u16 *)(param_1 + 0x12) | 0xff00,0x18,0,0,*(u32 *)(param_1 + 0xd0));

    FUN_003ca780(0,0,0x3f800000,0x3f800000,(int)asStack_10[iVar2] + iVar5 * asStack_20[iVar2],8,

                 *(u16 *)(param_1 + 0x12) | 0xff00,0x26,0,0,*(u32 *)(param_1 + 0xd0));

  }

  else {

    FUN_003ca780(0,0,0x3f800000,0x3f800000,(int)asStack_10[iVar2] + iVar5 * asStack_20[iVar2],10,

                 *(u16 *)(param_1 + 0x12) | 0xff00,0x17,0,0,*(u32 *)(param_1 + 0xd0));

    FUN_003ca780(0,0,0x3f800000,0x3f800000,(int)asStack_10[iVar2] + iVar5 * asStack_20[iVar2],8,

                 *(u16 *)(param_1 + 0x12) | 0xff00,0x25,0,0,*(u32 *)(param_1 + 0xd0));

  }

  return;

}
#define FUN_003cacc0(...) ((void (*)(...))FUN_003cacc0)(__VA_ARGS__)
#undef FUN_003cb050
// FUN_003CB050 NONMATCHING


void FUN_003cb050(u64 param_1,int param_2,u64 param_3,long param_4,int param_5,

                 int param_6,int param_7,int param_8)



{

  if (param_4 == 0) {

    FUN_003ca780(0,0,0x3f800000,0x3f800000,param_1,param_2 + param_6 * -4,

                 *(u16 *)(param_8 + 0x12) | 0xff00,param_5 + 2,0,0,

                 *(u32 *)(param_8 + 0xd8));

  }

  else {

    FUN_003ca780(0,0,0x3f800000,0x3f800000,param_1,param_2 + (param_7 - param_6) * 4,

                 *(u16 *)(param_8 + 0x12) | 0xff00,param_5 + 2,0,0,

                 *(u32 *)(param_8 + 0xd8));

  }

  return;

}
#define FUN_003cb050(...) ((void (*)(...))FUN_003cb050)(__VA_ARGS__)
#undef FUN_003cb100
// FUN_003CB100 NONMATCHING


void FUN_003cb100(int param_1)



{

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0,*(u16 *)(param_1 + 0x12) | 0xff00,2,0,0,

               *(u32 *)(param_1 + 0xd0));

  FUN_003ca780(0,0xc20c0000,0x3f800000,0x3f800000,0xfffffffffffffe9b,0xbd,

               *(u16 *)(param_1 + 0x12) | 0xff00,0,0,0,*(u32 *)(param_1 + 0xd0));

  FUN_003ca780(0,0xc20c0000,0x3f800000,0x3f800000,0xffffffffffffff9f,0xbd,

               *(u16 *)(param_1 + 0x12) | 0xff00,1,0xfffffffffffffefc,0,

               *(u32 *)(param_1 + 0xd0));

  return;

}
#define FUN_003cb100(...) ((void (*)(...))FUN_003cb100)(__VA_ARGS__)
#undef FUN_003cb1f0
// FUN_003CB1F0 NONMATCHING


void FUN_003cb1f0(u64 param_1)



{

  short sVar1;

  int iVar2;

  u64 *puVar3;

  u8 uVar4;

  u64 *puVar5;

  u64 uVar6;

  u64 *puVar7;

  int *piVar8;

  u8 auStack_18 [8];

  u8 auStack_10 [8];

  u64 uStack_8;

  

  piVar8 = (int *)param_1;

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0x25,*(u16 *)((int)piVar8 + 0x12) | 0xff00,5,0,0,

               piVar8[0x34]);

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0x16b,0x25,*(u16 *)((int)piVar8 + 0x12) | 0xff00,6,0,0,

               piVar8[0x34]);

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0x62,*(u16 *)((int)piVar8 + 0x12) | 0xff00,4,0,0,

               piVar8[0x34]);

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0,*(u16 *)((int)piVar8 + 0x12) | 0xff00,3,0,0,

               piVar8[0x34]);

  FUN_00133a80(piVar8[0x31]);

  puVar5 = (u64 *)0x8;

  puVar7 = &uStack_8;

  puVar3 = puVar7;

  while (puVar3 != (u64 *)0x0) {

    *(u8 *)puVar7 = 0;

    puVar7 = (u64 *)((int)puVar7 + 1);

    puVar5 = (u64 *)((int)puVar5 + -1);

    puVar3 = puVar5;

  }

  if ((piVar8[2] & 2U) == 0) {

    FUN_00133180(0,uStack_8,piVar8 + 7,piVar8 + 8,*(u16 *)((int)piVar8 + 0x12));

  }

  else {

    FUN_001332f0(0,uStack_8,piVar8 + 7,piVar8 + 8,*(u16 *)((int)piVar8 + 0x12));

  }

  sVar1 = *(short *)((int)piVar8 + 0xea);

  if (sVar1 == 2) {

    iVar2 = *piVar8;

    if ((iVar2 == 4) || (iVar2 == 2)) {

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x16,0xc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0x15,

                   0,0,piVar8[0x34]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x21b,0xc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0x16

                   ,0,0,piVar8[0x34]);

    }

    else if (((iVar2 == 3) || (iVar2 == 1)) || (iVar2 == 0)) {

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x2a,0xc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,2,0,0

                   ,piVar8[0x35]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x207,0xc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,3,0,

                   0,piVar8[0x35]);

    }


    if ((*(u16 *)((int)piVar8 + 0x22) != 0) && (piVar8[0x1b] != 0)) {

      uVar6 = FUN_0016deb0(*(u8 *)

                            ((u32)*(u16 *)((int)piVar8 + 0x22) * 0xe + iGpffffb730 + 2));

      uVar4 = FUN_0016dba0(uVar6);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x169,0xc9,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0,0

                   ,0,piVar8[0x36]);

      FUN_00523ac8(auStack_18,&gp0xffffaa10,uVar4);

      FUN_0040ec50(0,0x20e,199,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0,auStack_18,0,0x17,0x3cb050

                  );

      FUN_00523ac8(auStack_18,&gp0xffffaa14,piVar8[0x1b]);

      FUN_0040ec50(0,0x264,0xfc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,1,auStack_18,1,0x1b,

                   0x3cb050);

    }

  }

  else if (sVar1 == 1) {

    iVar2 = *piVar8;

    if ((iVar2 == 4) || (iVar2 == 2)) {

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x16,0xc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0x15,

                   0,0,piVar8[0x34]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x21b,0xc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0x16

                   ,0,0,piVar8[0x34]);

    }

    else if (((iVar2 == 3) || (iVar2 == 1)) || (iVar2 == 0)) {

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x2a,0xc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,2,0,0

                   ,piVar8[0x35]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x207,0xc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,3,0,

                   0,piVar8[0x35]);

    }

    FUN_003ca780(0,0,0x3f800000,0x3f800000,0xc1,8,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0x14,0,0,

                 piVar8[0x34]);

  }

  else if (sVar1 == 0) {

    FUN_003ca780(0,0,0x3f800000,0x3f800000,0xc1,8,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0x14,0,0,

                 piVar8[0x34]);

    if ((*(u16 *)((int)piVar8 + 0x22) != 0) && (piVar8[0x1b] != 0)) {

      uVar6 = FUN_0016deb0(*(u8 *)

                            ((u32)*(u16 *)((int)piVar8 + 0x22) * 0xe + iGpffffb730 + 2));

      uVar4 = FUN_0016dba0(uVar6);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x169,0xc9,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0,0

                   ,0,piVar8[0x36]);

      FUN_00523ac8(auStack_10,&gp0xffffaa10,uVar4);

      FUN_0040ec50(0,0x20e,199,*(u16 *)((int)piVar8 + 0x12) | 0xff00,0,auStack_10,0,0x17,0x3cb050

                  );

      FUN_00523ac8(auStack_10,&gp0xffffaa14,piVar8[0x1b]);

      FUN_0040ec50(0,0x264,0xfc,*(u16 *)((int)piVar8 + 0x12) | 0xff00,1,auStack_10,1,0x1b,

                   0x3cb050);

    }

  }

  return;

}
#define FUN_003cb1f0(...) ((void (*)(...))FUN_003cb1f0)(__VA_ARGS__)
#undef FUN_003cb960
// FUN_003CB960 NONMATCHING


void FUN_003cb960(int param_1)



{

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0,*(u16 *)(param_1 + 0x12) | 0xff00,2,0,0,

               *(u32 *)(param_1 + 0xd0));

  FUN_003ca780(0,0xc20c0000,0x3f800000,0x3f800000,0xfffffffffffffe9b,0xbd,

               *(u16 *)(param_1 + 0x12) | 0xff00,0,0,0,*(u32 *)(param_1 + 0xd0));

  FUN_003ca780(0,0xc20c0000,0x3f800000,0x3f800000,0xffffffffffffff9f,0xbd,

               *(u16 *)(param_1 + 0x12) | 0xff00,1,0xfffffffffffffefc,0,

               *(u32 *)(param_1 + 0xd0));

  return;

}
#define FUN_003cb960(...) ((void (*)(...))FUN_003cb960)(__VA_ARGS__)
#undef FUN_003cba50
// FUN_003CBA50 NONMATCHING


void FUN_003cba50(u64 param_1)



{

  u16 uVar1;

  u64 *puVar2;

  u64 *puVar3;

  u64 *puVar4;

  int *piVar5;

  int iVar6;

  long lVar7;

  u16 auStack_28 [16];

  u64 uStack_8;

  

  piVar5 = (int *)param_1;

  if (*(short *)((int)piVar5 + 0xea) == 4) {

    if ((char)piVar5[0x3a] == '\x01') {

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0x25,*(u16 *)((int)piVar5 + 0x12) | 0xff00,5,0,0,

                   piVar5[0x34]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x16b,0x25,*(u16 *)((int)piVar5 + 0x12) | 0xff00,6,0

                   ,0,piVar5[0x34]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0x62,*(u16 *)((int)piVar5 + 0x12) | 0xff00,4,0,0,

                   piVar5[0x34]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0,*(u16 *)((int)piVar5 + 0x12) | 0xff00,3,0,0,

                   piVar5[0x34]);

      FUN_00133a80(piVar5[0x31]);


      iVar6 = *piVar5;

      if ((iVar6 == 4) || (iVar6 == 2)) {

        FUN_003ca780(0,0,0x3f800000,0x3f800000,0x16,0xc,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                     0x15,0,0,piVar5[0x34]);

        FUN_003ca780(0,0,0x3f800000,0x3f800000,0x21b,0xc,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                     0x16,0,0,piVar5[0x34]);

      }

      else if (((iVar6 == 3) || (iVar6 == 1)) || (iVar6 == 0)) {

        FUN_003ca780(0,0,0x3f800000,0x3f800000,0x2a,0xc,*(u16 *)((int)piVar5 + 0x12) | 0xff00,2,0

                     ,0,piVar5[0x35]);

        FUN_003ca780(0,0,0x3f800000,0x3f800000,0x207,0xc,*(u16 *)((int)piVar5 + 0x12) | 0xff00,3,

                     0,0,piVar5[0x35]);

      }

      auStack_28[4] = uGpffffaa20;

      auStack_28[5] = uGpffffaa22;

      auStack_28[6] = uGpffffaa24;

      auStack_28[7] = uGpffffaa26;

      lVar7 = 0;

      while (lVar7 < *(char *)((int)piVar5 + 0xe9)) {

        iVar6 = (int)lVar7;

        if ((char)piVar5[0x3a] == lVar7) {

          uVar1 = auStack_28[iVar6 + 4];

          FUN_003ca780(0,0,0x3f800000,0x3f800000,uVar1,10,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                       0x45,0,0,piVar5[0x34]);

          FUN_003ca780(0,0,0x3f800000,0x3f800000,auStack_28[iVar6 + 6],10,

                       *(u16 *)((int)piVar5 + 0x12) | 0xff00,0x34,0,0,piVar5[0x34]);

          FUN_003ca780(0,0,0x3f800000,0x3f800000,uVar1,10,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                       iVar6 * 2 + 0x47,0,0,piVar5[0x34]);

        }

        else {

          uVar1 = auStack_28[iVar6 + 4];

          FUN_003ca780(0,0,0x3f800000,0x3f800000,uVar1,10,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                       0x46,0,0,piVar5[0x34]);

          FUN_003ca780(0,0,0x3f800000,0x3f800000,auStack_28[iVar6 + 6],10,

                       *(u16 *)((int)piVar5 + 0x12) | 0xff00,0x35,0,0,piVar5[0x34]);

          FUN_003ca780(0,0,0x3f800000,0x3f800000,uVar1,10,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                       iVar6 * 2 + 0x48,0,0,piVar5[0x34]);

        }

        lVar7 = (long)(iVar6 + 1);

      }

    }

    else {

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0x25,*(u16 *)((int)piVar5 + 0x12) | 0xff00,5,0,0,

                   piVar5[0x34]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x16b,0x25,*(u16 *)((int)piVar5 + 0x12) | 0xff00,6,0

                   ,0,piVar5[0x34]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0x62,*(u16 *)((int)piVar5 + 0x12) | 0xff00,4,0,0,

                   piVar5[0x34]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0,*(u16 *)((int)piVar5 + 0x12) | 0xff00,3,0,0,

                   piVar5[0x34]);

      FUN_00133a80(piVar5[0x31]);


      iVar6 = *piVar5;

      if ((iVar6 == 4) || (iVar6 == 2)) {

        FUN_003ca780(0,0,0x3f800000,0x3f800000,0x16,0xc,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                     0x15,0,0,piVar5[0x34]);

        FUN_003ca780(0,0,0x3f800000,0x3f800000,0x21b,0xc,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                     0x16,0,0,piVar5[0x34]);

      }

      else if (((iVar6 == 3) || (iVar6 == 1)) || (iVar6 == 0)) {

        FUN_003ca780(0,0,0x3f800000,0x3f800000,0x2a,0xc,*(u16 *)((int)piVar5 + 0x12) | 0xff00,2,0

                     ,0,piVar5[0x35]);

        FUN_003ca780(0,0,0x3f800000,0x3f800000,0x207,0xc,*(u16 *)((int)piVar5 + 0x12) | 0xff00,3,

                     0,0,piVar5[0x35]);

      }

      auStack_28[0] = uGpffffaa20;

      auStack_28[1] = uGpffffaa22;

      auStack_28[2] = uGpffffaa24;

      auStack_28[3] = uGpffffaa26;

      lVar7 = 0;

      while (lVar7 < *(char *)((int)piVar5 + 0xe9)) {

        iVar6 = (int)lVar7;

        if ((char)piVar5[0x3a] == lVar7) {

          uVar1 = auStack_28[iVar6];

          FUN_003ca780(0,0,0x3f800000,0x3f800000,uVar1,10,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                       0x45,0,0,piVar5[0x34]);

          FUN_003ca780(0,0,0x3f800000,0x3f800000,auStack_28[iVar6 + 2],10,

                       *(u16 *)((int)piVar5 + 0x12) | 0xff00,0x34,0,0,piVar5[0x34]);

          FUN_003ca780(0,0,0x3f800000,0x3f800000,uVar1,10,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                       iVar6 * 2 + 0x47,0,0,piVar5[0x34]);

        }

        else {

          uVar1 = auStack_28[iVar6];

          FUN_003ca780(0,0,0x3f800000,0x3f800000,uVar1,10,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                       0x46,0,0,piVar5[0x34]);

          FUN_003ca780(0,0,0x3f800000,0x3f800000,auStack_28[iVar6 + 2],10,

                       *(u16 *)((int)piVar5 + 0x12) | 0xff00,0x35,0,0,piVar5[0x34]);

          FUN_003ca780(0,0,0x3f800000,0x3f800000,uVar1,10,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                       iVar6 * 2 + 0x48,0,0,piVar5[0x34]);

        }

        lVar7 = (long)(iVar6 + 1);

      }

    }

  }

  else if (*(short *)((int)piVar5 + 0xea) == 3) {

    if ((char)piVar5[0x3a] == '\x01') {

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0x25,*(u16 *)((int)piVar5 + 0x12) | 0xff00,5,0,0,

                   piVar5[0x34]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x16b,0x25,*(u16 *)((int)piVar5 + 0x12) | 0xff00,6,0

                   ,0,piVar5[0x34]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0x62,*(u16 *)((int)piVar5 + 0x12) | 0xff00,4,0,0,

                   piVar5[0x34]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0,*(u16 *)((int)piVar5 + 0x12) | 0xff00,3,0,0,

                   piVar5[0x34]);

      FUN_00133a80(piVar5[0x31]);

      puVar3 = (u64 *)0x8;

      puVar4 = &uStack_8;

      puVar2 = puVar4;

      while (puVar2 != (u64 *)0x0) {

        *(u8 *)puVar4 = 0;

        puVar4 = (u64 *)((int)puVar4 + 1);

        puVar3 = (u64 *)((int)puVar3 + -1);

        puVar2 = puVar3;

      }

      if ((piVar5[2] & 2U) == 0) {

        FUN_00133180(0,uStack_8,piVar5 + 7,piVar5 + 8,*(u16 *)((int)piVar5 + 0x12));

      }

      else {

        FUN_001332f0(0,uStack_8,piVar5 + 7,piVar5 + 8,*(u16 *)((int)piVar5 + 0x12));

      }

      iVar6 = *piVar5;

      if ((iVar6 == 4) || (iVar6 == 2)) {

        FUN_003ca780(0,0,0x3f800000,0x3f800000,0x16,0xc,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                     0x15,0,0,piVar5[0x34]);

        FUN_003ca780(0,0,0x3f800000,0x3f800000,0x21b,0xc,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                     0x16,0,0,piVar5[0x34]);

      }

      else if (((iVar6 == 3) || (iVar6 == 1)) || (iVar6 == 0)) {

        FUN_003ca780(0,0,0x3f800000,0x3f800000,0x2a,0xc,*(u16 *)((int)piVar5 + 0x12) | 0xff00,2,0

                     ,0,piVar5[0x35]);

        FUN_003ca780(0,0,0x3f800000,0x3f800000,0x207,0xc,*(u16 *)((int)piVar5 + 0x12) | 0xff00,3,

                     0,0,piVar5[0x35]);

      }

      auStack_28[0xc] = uGpffffaa18;

      auStack_28[0xd] = uGpffffaa1a;

      auStack_28[0xe] = uGpffffaa1c;

      auStack_28[0xf] = uGpffffaa1e;

      lVar7 = 0;

      while (lVar7 < *(char *)((int)piVar5 + 0xe9)) {

        iVar6 = (int)lVar7;

        if ((char)piVar5[0x3a] == lVar7) {

          uVar1 = auStack_28[iVar6 + 0xc];

          FUN_003ca780(0,0,0x3f800000,0x3f800000,uVar1,10,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                       0x33,0,0,piVar5[0x34]);

          FUN_003ca780(0,0,0x3f800000,0x3f800000,auStack_28[iVar6 + 0xe],10,

                       *(u16 *)((int)piVar5 + 0x12) | 0xff00,0x35,0,0,piVar5[0x34]);

          FUN_003ca780(0,0,0x3f800000,0x3f800000,uVar1,10,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                       iVar6 * 2 + 0x37,0,0,piVar5[0x34]);

        }

        else {

          uVar1 = auStack_28[iVar6 + 0xc];

          FUN_003ca780(0,0,0x3f800000,0x3f800000,uVar1,10,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                       0x32,0,0,piVar5[0x34]);

          FUN_003ca780(0,0,0x3f800000,0x3f800000,auStack_28[iVar6 + 0xe],10,

                       *(u16 *)((int)piVar5 + 0x12) | 0xff00,0x34,0,0,piVar5[0x34]);

          FUN_003ca780(0,0,0x3f800000,0x3f800000,uVar1,10,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                       iVar6 * 2 + 0x36,0,0,piVar5[0x34]);

        }

        lVar7 = (long)(iVar6 + 1);

      }

    }

    else {

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0,*(u16 *)((int)piVar5 + 0x12) | 0xff00,3,0,0,

                   piVar5[0x34]);

      iVar6 = *piVar5;

      if ((iVar6 == 4) || (iVar6 == 2)) {

        FUN_003ca780(0,0,0x3f800000,0x3f800000,0x16,0xc,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                     0x15,0,0,piVar5[0x34]);

        FUN_003ca780(0,0,0x3f800000,0x3f800000,0x21b,0xc,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                     0x16,0,0,piVar5[0x34]);

      }

      else if (((iVar6 == 3) || (iVar6 == 1)) || (iVar6 == 0)) {

        FUN_003ca780(0,0,0x3f800000,0x3f800000,0x2a,0xc,*(u16 *)((int)piVar5 + 0x12) | 0xff00,2,0

                     ,0,piVar5[0x35]);

        FUN_003ca780(0,0,0x3f800000,0x3f800000,0x207,0xc,*(u16 *)((int)piVar5 + 0x12) | 0xff00,3,

                     0,0,piVar5[0x35]);

      }

      auStack_28[8] = uGpffffaa18;

      auStack_28[9] = uGpffffaa1a;

      auStack_28[10] = uGpffffaa1c;

      auStack_28[0xb] = uGpffffaa1e;

      lVar7 = 0;

      while (lVar7 < *(char *)((int)piVar5 + 0xe9)) {

        iVar6 = (int)lVar7;

        if ((char)piVar5[0x3a] == lVar7) {

          uVar1 = auStack_28[iVar6 + 8];

          FUN_003ca780(0,0,0x3f800000,0x3f800000,uVar1,10,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                       0x33,0,0,piVar5[0x34]);

          FUN_003ca780(0,0,0x3f800000,0x3f800000,auStack_28[iVar6 + 10],10,

                       *(u16 *)((int)piVar5 + 0x12) | 0xff00,0x35,0,0,piVar5[0x34]);

          FUN_003ca780(0,0,0x3f800000,0x3f800000,uVar1,10,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                       iVar6 * 2 + 0x37,0,0,piVar5[0x34]);

        }

        else {

          uVar1 = auStack_28[iVar6 + 8];

          FUN_003ca780(0,0,0x3f800000,0x3f800000,uVar1,10,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                       0x32,0,0,piVar5[0x34]);

          FUN_003ca780(0,0,0x3f800000,0x3f800000,auStack_28[iVar6 + 10],10,

                       *(u16 *)((int)piVar5 + 0x12) | 0xff00,0x34,0,0,piVar5[0x34]);

          FUN_003ca780(0,0,0x3f800000,0x3f800000,uVar1,10,*(u16 *)((int)piVar5 + 0x12) | 0xff00,

                       iVar6 * 2 + 0x36,0,0,piVar5[0x34]);

        }

        lVar7 = (long)(iVar6 + 1);

      }

    }

  }

  else {

    FUN_003ca780(0,0,0x3f800000,0x3f800000,0xc1,8,*(u16 *)((int)piVar5 + 0x12) | 0xff00,0x14,0,0,

                 piVar5[0x34]);

  }

  return;

}
#define FUN_003cba50(...) ((void (*)(...))FUN_003cba50)(__VA_ARGS__)
#undef FUN_003ccc40
// FUN_003CCC40 NONMATCHING


void FUN_003ccc40(int *param_1)



{

  int iVar1;

  u64 *puVar2;

  u64 *puVar3;

  u64 *puVar4;

  u64 uStack_8;

  

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0,*(u16 *)((int)param_1 + 0x12) | 0xff00,2,0,0,

               param_1[0x34]);

  FUN_003ca780(0,0xc20c0000,0x3f800000,0x3f800000,0xfffffffffffffe9b,0xbd,

               *(u16 *)((int)param_1 + 0x12) | 0xff00,0,0,0,param_1[0x34]);

  FUN_003ca780(0,0xc20c0000,0x3f800000,0x3f800000,0xffffffffffffff9f,0xbd,

               *(u16 *)((int)param_1 + 0x12) | 0xff00,1,0xfffffffffffffefc,0,param_1[0x34]);

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0x25,*(u16 *)((int)param_1 + 0x12) | 0xff00,5,0,0,

               param_1[0x34]);

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0x16b,0x25,*(u16 *)((int)param_1 + 0x12) | 0xff00,6,0,0,

               param_1[0x34]);

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0x62,*(u16 *)((int)param_1 + 0x12) | 0xff00,4,0,0,

               param_1[0x34]);

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0,*(u16 *)((int)param_1 + 0x12) | 0xff00,3,0,0,

               param_1[0x34]);

  FUN_00133a80(param_1[0x31]);

  puVar3 = (u64 *)0x8;

  puVar4 = &uStack_8;

  puVar2 = puVar4;

  while (puVar2 != (u64 *)0x0) {

    *(u8 *)puVar4 = 0;

    puVar4 = (u64 *)((int)puVar4 + 1);

    puVar3 = (u64 *)((int)puVar3 + -1);

    puVar2 = puVar3;

  }

  if ((param_1[2] & 2U) == 0) {

    FUN_00133460(0,uStack_8,param_1 + 7,param_1 + 8,*(u16 *)((int)param_1 + 0x12));

  }

  else {

    FUN_001332f0(0,uStack_8,param_1 + 7,param_1 + 8,*(u16 *)((int)param_1 + 0x12));

  }

  if (param_1[0x35] != 0) {


    FUN_003ca780(0,0,0x3f800000,0x3f800000,0x178,8,*(u16 *)((int)param_1 + 0x12) | 0xff00,1,0,0,

                 param_1[0x35]);

  }

  if (*(short *)((int)param_1 + 0xea) == 1) {

    iVar1 = *param_1;

    if ((iVar1 == 4) || (iVar1 == 2)) {

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x16,0xc,*(u16 *)((int)param_1 + 0x12) | 0xff00,0x15

                   ,0,0,param_1[0x34]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x21b,0xc,*(u16 *)((int)param_1 + 0x12) | 0xff00,

                   0x16,0,0,param_1[0x34]);

    }

    else if (((iVar1 == 3) || (iVar1 == 1)) || (iVar1 == 0)) {

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x2a,0xc,*(u16 *)((int)param_1 + 0x12) | 0xff00,2,0,

                   0,param_1[0x35]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x207,0xc,*(u16 *)((int)param_1 + 0x12) | 0xff00,3,0

                   ,0,param_1[0x35]);

    }

  }

  return;

}
#define FUN_003ccc40(...) ((void (*)(...))FUN_003ccc40)(__VA_ARGS__)
#undef FUN_003cd0b0
// FUN_003CD0B0 NONMATCHING


void FUN_003cd0b0(int *param_1)



{

  int iVar1;

  u64 *puVar2;

  u64 *puVar3;

  u64 *puVar4;

  u64 uStack_8;

  

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0,*(u16 *)((int)param_1 + 0x12) | 0xff00,2,0,0,

               param_1[0x34]);

  FUN_003ca780(0,0xc20c0000,0x3f800000,0x3f800000,0xfffffffffffffe9b,0xbd,

               *(u16 *)((int)param_1 + 0x12) | 0xff00,0,0,0,param_1[0x34]);

  FUN_003ca780(0,0xc20c0000,0x3f800000,0x3f800000,0xffffffffffffff9f,0xbd,

               *(u16 *)((int)param_1 + 0x12) | 0xff00,1,0xfffffffffffffefc,0,param_1[0x34]);

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0x25,*(u16 *)((int)param_1 + 0x12) | 0xff00,5,0,0,

               param_1[0x34]);

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0x16b,0x25,*(u16 *)((int)param_1 + 0x12) | 0xff00,6,0,0,

               param_1[0x34]);

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0x62,*(u16 *)((int)param_1 + 0x12) | 0xff00,4,0,0,

               param_1[0x34]);

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0,*(u16 *)((int)param_1 + 0x12) | 0xff00,3,0,0,

               param_1[0x34]);

  FUN_00133a80(param_1[0x31]);

  puVar3 = (u64 *)0x8;

  puVar4 = &uStack_8;

  puVar2 = puVar4;

  while (puVar2 != (u64 *)0x0) {

    *(u8 *)puVar4 = 0;

    puVar4 = (u64 *)((int)puVar4 + 1);

    puVar3 = (u64 *)((int)puVar3 + -1);

    puVar2 = puVar3;

  }

  if ((param_1[2] & 2U) == 0) {

    FUN_00133180(0,uStack_8,param_1 + 7,param_1 + 8,*(u16 *)((int)param_1 + 0x12));

  }

  else {

    FUN_001332f0(0,uStack_8,param_1 + 7,param_1 + 8,*(u16 *)((int)param_1 + 0x12));

  }

  if (param_1[0x35] != 0) {


    FUN_003ca780(0,0,0x3f800000,0x3f800000,0x178,8,*(u16 *)((int)param_1 + 0x12) | 0xff00,1,0,0,

                 param_1[0x35]);

  }

  if (*(short *)((int)param_1 + 0xea) == 1) {

    iVar1 = *param_1;

    if ((iVar1 == 4) || (iVar1 == 2)) {

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x16,0xc,*(u16 *)((int)param_1 + 0x12) | 0xff00,0x15

                   ,0,0,param_1[0x34]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x21b,0xc,*(u16 *)((int)param_1 + 0x12) | 0xff00,

                   0x16,0,0,param_1[0x34]);

    }

    else if (((iVar1 == 3) || (iVar1 == 1)) || (iVar1 == 0)) {

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x2a,0xc,*(u16 *)((int)param_1 + 0x12) | 0xff00,2,0,

                   0,param_1[0x35]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x207,0xc,*(u16 *)((int)param_1 + 0x12) | 0xff00,3,0

                   ,0,param_1[0x35]);

    }

  }

  if (param_1[0x35] != 0) {

    FUN_003ca780(0,0,0x3f800000,0x3f800000,0x1d4,0x1a1,*(u16 *)((int)param_1 + 0x12) | 0xff00,0xd

                 ,0,0);

    FUN_003ca780(0,0,0x3f800000,0x3f800000,0x231,0x1a1,*(u16 *)((int)param_1 + 0x12) | 0xff00,0xe

                 ,0,0,param_1[0x35]);

  }

  return;

}
#define FUN_003cd0b0(...) ((void (*)(...))FUN_003cd0b0)(__VA_ARGS__)
#undef FUN_003cd5a0
// FUN_003CD5A0 NONMATCHING


void FUN_003cd5a0(int *param_1)



{

  int iVar1;

  u64 *puVar2;

  u64 *puVar3;

  u64 *puVar4;

  u64 uStack_8;

  

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0,*(u16 *)((int)param_1 + 0x12) | 0xff00,2,0,0,

               param_1[0x34]);

  FUN_003ca780(0,0xc20c0000,0x3f800000,0x3f800000,0xfffffffffffffe9b,0xbd,

               *(u16 *)((int)param_1 + 0x12) | 0xff00,0,0,0,param_1[0x34]);

  FUN_003ca780(0,0xc20c0000,0x3f800000,0x3f800000,0xffffffffffffff9f,0xbd,

               *(u16 *)((int)param_1 + 0x12) | 0xff00,1,0xfffffffffffffefc,0,param_1[0x34]);

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0x25,*(u16 *)((int)param_1 + 0x12) | 0xff00,5,0,0,

               param_1[0x34]);

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0x16b,0x25,*(u16 *)((int)param_1 + 0x12) | 0xff00,6,0,0,

               param_1[0x34]);

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0x62,*(u16 *)((int)param_1 + 0x12) | 0xff00,4,0,0,

               param_1[0x34]);

  FUN_003ca780(0,0,0x3f800000,0x3f800000,0,0,*(u16 *)((int)param_1 + 0x12) | 0xff00,3,0,0,

               param_1[0x34]);

  FUN_00133a80(param_1[0x31]);

  puVar3 = (u64 *)0x8;

  puVar4 = &uStack_8;

  puVar2 = puVar4;

  while (puVar2 != (u64 *)0x0) {

    *(u8 *)puVar4 = 0;

    puVar4 = (u64 *)((int)puVar4 + 1);

    puVar3 = (u64 *)((int)puVar3 + -1);

    puVar2 = puVar3;

  }

  if ((param_1[2] & 2U) == 0) {

    FUN_00133180(0,uStack_8,param_1 + 7,param_1 + 8,*(u16 *)((int)param_1 + 0x12));

  }

  else {

    FUN_001332f0(0,uStack_8,param_1 + 7,param_1 + 8,*(u16 *)((int)param_1 + 0x12));

  }

  if (param_1[0x35] != 0) {


    FUN_003ca780(0,0,0x3f800000,0x3f800000,0x178,8,*(u16 *)((int)param_1 + 0x12) | 0xff00,1,0,0,

                 param_1[0x35]);

  }

  if (*(short *)((int)param_1 + 0xea) == 1) {

    iVar1 = *param_1;

    if ((iVar1 == 4) || (iVar1 == 2)) {

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x16,0xc,*(u16 *)((int)param_1 + 0x12) | 0xff00,0x15

                   ,0,0,param_1[0x34]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x21b,0xc,*(u16 *)((int)param_1 + 0x12) | 0xff00,

                   0x16,0,0,param_1[0x34]);

    }

    else if (((iVar1 == 3) || (iVar1 == 1)) || (iVar1 == 0)) {

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x2a,0xc,*(u16 *)((int)param_1 + 0x12) | 0xff00,2,0,

                   0,param_1[0x35]);

      FUN_003ca780(0,0,0x3f800000,0x3f800000,0x207,0xc,*(u16 *)((int)param_1 + 0x12) | 0xff00,3,0

                   ,0,param_1[0x35]);

    }

  }

  return;

}
#define FUN_003cd5a0(...) ((void (*)(...))FUN_003cd5a0)(__VA_ARGS__)
#undef FUN_003cda00
// FUN_003CDA00 NONMATCHING


u32 FUN_003cda00(void)



{

  u32 uVar1;

  u64 uVar2;

  long lVar3;

  

  uVar2 = FUN_00195540();

  lVar3 = FUN_00316f70(uVar2);

  if (lVar3 == 0) {

    uVar1 = 0;

  }

  else {

    FUN_003174e0(uVar2);

    uVar1 = 0xffffffff;

  }

  return uVar1;

}
#define FUN_003cda00(...) ((u32 (*)(...))FUN_003cda00)(__VA_ARGS__)
#undef FUN_003cda60
// FUN_003CDA60 NONMATCHING


void FUN_003cda60(u64 param_1)



{

  u64 uVar1;

  int iVar2;

  u64 uStack_20;

  u32 uStack_18;

  u64 uStack_10;

  u32 uStack_8;

  u32 uStack_4;

  

  uStack_10 = DAT_006a4218;

  uStack_8 = DAT_006a4220;

  uStack_20 = DAT_006a4228;

  uStack_18 = DAT_006a4230;

  uStack_4 = DAT_007cd718;

  uVar1 = (*DAT_00960178)(0x100,0x40000);

  FUN_00521408(uVar1,0,0x100);

  iVar2 = (int)uVar1;

  *(u16 *)(iVar2 + 0xc) = 0;

  *(u32 *)(iVar2 + 8) = 1;

  FUN_004c31b0(0x43340000,iVar2 + 0x40,&uStack_20,0);

  FUN_004c35d0(iVar2 + 0x40,&uStack_10,2);

  *(u8 *)(iVar2 + 0x80) = (u8)uStack_4;

  *(u8 *)(iVar2 + 0x81) = (u8)(uStack_4 >> 8);

  *(u8 *)(iVar2 + 0x82) = (u8)(uStack_4 >> 16);

  *(u8 *)(iVar2 + 0x83) = (u8)(uStack_4 >> 24);

  FUN_0016bc80(0,*(u16 *)(iVar2 + 0xc),iVar2 + 0x84);

  FUN_0016bdb0(0,*(u16 *)(iVar2 + 0xc),iVar2 + 0x94);

  FUN_00194b20(param_1,0x7cd720,0x147c,0x3ce2a0,0x3cf080,uVar1);

  return;

}
#define FUN_003cda60(...) ((void (*)(...))FUN_003cda60)(__VA_ARGS__)
#undef FUN_003cdba0
// FUN_003CDBA0 NONMATCHING


u32 FUN_003cdba0(u64 param_1,u16 param_2)



{

  u32 uVar1;

  long lVar2;

  int iVar3;

  

  lVar2 = FUN_00195540();

  if (lVar2 == 0) {

    FUN_0019d3f0(0x6a3e18,0x9e2);

  }

  iVar3 = (int)lVar2;

  if ((long)*(short *)(iVar3 + 0xc) == (u32)param_2) {

    *(u16 *)(iVar3 + 0xe) = 0;

    uVar1 = 0;

  }

  else if ((*(u32 *)(iVar3 + 4) & 1) == 0) {

    *(u16 *)(iVar3 + 0xe) = param_2;

    uVar1 = 0;

  }

  else {

    if ((u32)param_2 == 0) {

      if (*(int *)(iVar3 + 0x18) != 0) {

        FUN_003174e0();

        *(u32 *)(iVar3 + 0x18) = 0;

      }

    }

    else {

      *(u32 *)(iVar3 + 4) = *(u32 *)(iVar3 + 4) & 0xfffffffe;

      *(u32 *)(iVar3 + 8) = 2;

    }

    *(u16 *)(iVar3 + 0xc) = param_2;

    *(u16 *)(iVar3 + 0xe) = 0;

    uVar1 = 1;

  }

  return uVar1;

}
#define FUN_003cdba0(...) ((u32 (*)(...))FUN_003cdba0)(__VA_ARGS__)
#undef FUN_003cdc80
// FUN_003CDC80 NONMATCHING


u32 FUN_003cdc80(void)



{

  long lVar1;

  

  lVar1 = FUN_00195540();

  if (lVar1 == 0) {

    FUN_0019d3f0(0x6a3e18,0xa01);

  }

  return *(u32 *)((int)lVar1 + 4) & 1;

}
#define FUN_003cdc80(...) ((u32 (*)(...))FUN_003cdc80)(__VA_ARGS__)
#undef FUN_003cdcd0
// FUN_003CDCD0 NONMATCHING


u64 FUN_003cdcd0(u64 param_1,u64 param_2,u64 param_3,u64 param_4)



{

  long lVar1;

  u64 uVar2;

  

  lVar1 = FUN_00195540();

  if (lVar1 == 0) {

    FUN_0019d3f0(0x6a3e18,0xa08);

  }

  if ((*(u32 *)((int)lVar1 + 4) & 1) == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_003182d0(*(u32 *)((int)lVar1 + 0x18),0,param_2,param_3,param_4);

  }

  return uVar2;

}
#define FUN_003cdcd0(...) ((u64 (*)(...))FUN_003cdcd0)(__VA_ARGS__)
#undef FUN_003cdd80
// FUN_003CDD80 NONMATCHING


u8 FUN_003cdd80(void)



{

  u8 bVar1;

  long lVar2;

  

  lVar2 = FUN_00195540();

  if (lVar2 == 0) {

    FUN_0019d3f0(0x6a3e18,0xa10);

  }

  if ((*(u32 *)((int)lVar2 + 4) & 1) == 0) {

    bVar1 = 1;

  }

  else {

    bVar1 = *(char *)(*(int *)((int)lVar2 + 0x18) + 0xee) == '\x01';

  }

  return bVar1;

}
#define FUN_003cdd80(...) ((u8 (*)(...))FUN_003cdd80)(__VA_ARGS__)
#undef FUN_003cde00
// FUN_003CDE00 NONMATCHING


void FUN_003cde00(u64 param_1,int param_2)



{

  long lVar1;

  

  lVar1 = FUN_00195540();

  if (lVar1 == 0) {

    FUN_0019d3f0(0x6a3e18,0xa18);

  }

  *(u32 *)((int)lVar1 + 4) = *(u32 *)((int)lVar1 + 4) | param_2 << 0x10;

  return;

}
#define FUN_003cde00(...) ((void (*)(...))FUN_003cde00)(__VA_ARGS__)
#undef FUN_003cde70
// FUN_003CDE70 NONMATCHING


void FUN_003cde70(u64 param_1,int param_2)



{

  long lVar1;

  

  lVar1 = FUN_00195540();

  if (lVar1 == 0) {

    FUN_0019d3f0(0x6a3e18,0xa1e);

  }

  *(u32 *)((int)lVar1 + 4) = *(u32 *)((int)lVar1 + 4) & ~(param_2 << 0x10);

  return;

}
#define FUN_003cde70(...) ((void (*)(...))FUN_003cde70)(__VA_ARGS__)
#undef FUN_003cdee0
// FUN_003CDEE0 NONMATCHING


void FUN_003cdee0(u64 param_1,u16 param_2)



{

  long lVar1;

  

  lVar1 = FUN_00195540();

  if (lVar1 == 0) {

    FUN_0019d3f0(0x6a3e18,0xa26);

  }

  *(u16 *)lVar1 = param_2;

  return;

}
#define FUN_003cdee0(...) ((void (*)(...))FUN_003cdee0)(__VA_ARGS__)
#undef FUN_003cdf40
// FUN_003CDF40 NONMATCHING


void FUN_003cdf40(u64 param_1,u8 *param_2,long param_3)



{

  u8 uVar1;

  u8 uVar2;

  u8 uVar3;

  long lVar4;

  int iVar5;

  

  lVar4 = FUN_00195540();

  if (lVar4 == 0) {

    FUN_0019d3f0(0x6a3e18,0xa51);

  }

  iVar5 = (int)lVar4;

  if (param_3 == 0) {

    uVar1 = param_2[1];

    uVar2 = param_2[2];

    uVar3 = param_2[3];

    *(u8 *)(iVar5 + 0xa8) = *param_2;

    *(u8 *)(iVar5 + 0xa9) = uVar1;

    *(u8 *)(iVar5 + 0xaa) = uVar2;

    *(u8 *)(iVar5 + 0xab) = uVar3;

    *(u8 *)(iVar5 + 0xa4) = *(u8 *)(iVar5 + 0xa8);

    *(u8 *)(iVar5 + 0xa5) = *(u8 *)(iVar5 + 0xa9);

    *(u8 *)(iVar5 + 0xa6) = *(u8 *)(iVar5 + 0xaa);

    *(u8 *)(iVar5 + 0xa7) = *(u8 *)(iVar5 + 0xab);

    *(u8 *)(iVar5 + 0x80) = *(u8 *)(iVar5 + 0xa4);

    *(u8 *)(iVar5 + 0x81) = *(u8 *)(iVar5 + 0xa5);

    *(u8 *)(iVar5 + 0x82) = *(u8 *)(iVar5 + 0xa6);

    *(u8 *)(iVar5 + 0x83) = *(u8 *)(iVar5 + 0xa7);

  }

  else {

    uVar1 = param_2[1];

    uVar2 = param_2[2];

    uVar3 = param_2[3];

    *(u8 *)(iVar5 + 0xa4) = *param_2;

    *(u8 *)(iVar5 + 0xa5) = uVar1;

    *(u8 *)(iVar5 + 0xa6) = uVar2;

    *(u8 *)(iVar5 + 0xa7) = uVar3;

    *(u8 *)(iVar5 + 0xa8) = *(u8 *)(iVar5 + 0x80);

    *(u8 *)(iVar5 + 0xa9) = *(u8 *)(iVar5 + 0x81);

    *(u8 *)(iVar5 + 0xaa) = *(u8 *)(iVar5 + 0x82);

    *(u8 *)(iVar5 + 0xab) = *(u8 *)(iVar5 + 0x83);

  }

  *(u16 *)(iVar5 + 0xac) = 0;

  *(short *)(iVar5 + 0xae) = (short)param_3;

  return;

}
#define FUN_003cdf40(...) ((void (*)(...))FUN_003cdf40)(__VA_ARGS__)
#undef FUN_003ce060
// FUN_003CE060 NONMATCHING


void FUN_003ce060(u64 param_1,u32 *param_2,long param_3)



{

  long lVar1;

  int iVar2;

  u32 uVar3;

  u32 uVar4;

  u32 uVar5;

  

  lVar1 = FUN_00195540();

  if (lVar1 == 0) {

    FUN_0019d3f0(0x6a3e18,0xa61);

  }

  iVar2 = (int)lVar1;

  if (param_3 == 0) {

    uVar5 = param_2[1];

    uVar3 = param_2[2];

    uVar4 = param_2[3];

    *(u32 *)(iVar2 + 0xc0) = *param_2;

    *(u32 *)(iVar2 + 0xc4) = uVar5;

    *(u32 *)(iVar2 + 200) = uVar3;

    *(u32 *)(iVar2 + 0xcc) = uVar4;

    *(u32 *)(iVar2 + 0xb0) = *(u32 *)(iVar2 + 0xc0);

    *(u32 *)(iVar2 + 0xb4) = *(u32 *)(iVar2 + 0xc4);

    *(u32 *)(iVar2 + 0xb8) = *(u32 *)(iVar2 + 200);

    *(u32 *)(iVar2 + 0xbc) = *(u32 *)(iVar2 + 0xcc);

    *(u32 *)(iVar2 + 0x84) = *(u32 *)(iVar2 + 0xb0);

    *(u32 *)(iVar2 + 0x88) = *(u32 *)(iVar2 + 0xb4);

    *(u32 *)(iVar2 + 0x8c) = *(u32 *)(iVar2 + 0xb8);

    *(u32 *)(iVar2 + 0x90) = *(u32 *)(iVar2 + 0xbc);

  }

  else {

    uVar5 = param_2[1];

    uVar3 = param_2[2];

    uVar4 = param_2[3];

    *(u32 *)(iVar2 + 0xb0) = *param_2;

    *(u32 *)(iVar2 + 0xb4) = uVar5;

    *(u32 *)(iVar2 + 0xb8) = uVar3;

    *(u32 *)(iVar2 + 0xbc) = uVar4;

    *(u32 *)(iVar2 + 0xc0) = *(u32 *)(iVar2 + 0x84);

    *(u32 *)(iVar2 + 0xc4) = *(u32 *)(iVar2 + 0x88);

    *(u32 *)(iVar2 + 200) = *(u32 *)(iVar2 + 0x8c);

    *(u32 *)(iVar2 + 0xcc) = *(u32 *)(iVar2 + 0x90);

  }

  *(u16 *)(iVar2 + 0xd0) = 0;

  *(short *)(iVar2 + 0xd2) = (short)param_3;

  return;

}
#define FUN_003ce060(...) ((void (*)(...))FUN_003ce060)(__VA_ARGS__)
#undef FUN_003ce180
// FUN_003CE180 NONMATCHING


void FUN_003ce180(u64 param_1,u32 *param_2,long param_3)



{

  long lVar1;

  int iVar2;

  u32 uVar3;

  u32 uVar4;

  u32 uVar5;

  

  lVar1 = FUN_00195540();

  if (lVar1 == 0) {

    FUN_0019d3f0(0x6a3e18,0xa77);

  }

  iVar2 = (int)lVar1;

  if (param_3 == 0) {

    uVar5 = param_2[1];

    uVar3 = param_2[2];

    uVar4 = param_2[3];

    *(u32 *)(iVar2 + 0xe4) = *param_2;

    *(u32 *)(iVar2 + 0xe8) = uVar5;

    *(u32 *)(iVar2 + 0xec) = uVar3;

    *(u32 *)(iVar2 + 0xf0) = uVar4;

    *(u32 *)(iVar2 + 0xd4) = *(u32 *)(iVar2 + 0xe4);

    *(u32 *)(iVar2 + 0xd8) = *(u32 *)(iVar2 + 0xe8);

    *(u32 *)(iVar2 + 0xdc) = *(u32 *)(iVar2 + 0xec);

    *(u32 *)(iVar2 + 0xe0) = *(u32 *)(iVar2 + 0xf0);

    *(u32 *)(iVar2 + 0x94) = *(u32 *)(iVar2 + 0xd4);

    *(u32 *)(iVar2 + 0x98) = *(u32 *)(iVar2 + 0xd8);

    *(u32 *)(iVar2 + 0x9c) = *(u32 *)(iVar2 + 0xdc);

    *(u32 *)(iVar2 + 0xa0) = *(u32 *)(iVar2 + 0xe0);

  }

  else {

    uVar5 = param_2[1];

    uVar3 = param_2[2];

    uVar4 = param_2[3];

    *(u32 *)(iVar2 + 0xd4) = *param_2;

    *(u32 *)(iVar2 + 0xd8) = uVar5;

    *(u32 *)(iVar2 + 0xdc) = uVar3;

    *(u32 *)(iVar2 + 0xe0) = uVar4;

    *(u32 *)(iVar2 + 0xe4) = *(u32 *)(iVar2 + 0x94);

    *(u32 *)(iVar2 + 0xe8) = *(u32 *)(iVar2 + 0x98);

    *(u32 *)(iVar2 + 0xec) = *(u32 *)(iVar2 + 0x9c);

    *(u32 *)(iVar2 + 0xf0) = *(u32 *)(iVar2 + 0xa0);

  }

  *(u16 *)(iVar2 + 0xf4) = 0;

  *(short *)(iVar2 + 0xf6) = (short)param_3;

  return;

}
#define FUN_003ce180(...) ((void (*)(...))FUN_003ce180)(__VA_ARGS__)
#undef FUN_003ce2a0












// FUN_003CE2A0 NONMATCHING
u64 FUN_003ce2a0(u64 param_1)



{

  int iVar1;

  u8 *puVar2;

  short sVar3;

  u8 *puVar4;

  u32 uVar5;

  u64 uVar6;

  long lVar7;

  u8 *puVar8;

  int iVar9;

  float fVar10;

  u8 uVar11;

  u8 auStack_8 [8];

  

  uVar6 = FUN_00195540();

  puVar4 = (u8 *)0x8;

  puVar8 = auStack_8;

  puVar2 = puVar8;

  while (puVar2 != (u8 *)0x0) {

    *puVar8 = 0;

    puVar8 = puVar8 + 1;

    puVar4 = puVar4 + -1;

    puVar2 = puVar4;

  }

  iVar9 = (int)uVar6;

  iVar1 = *(int *)(iVar9 + 8);

  if (iVar1 == 4) {

    if (((*(u32 *)(iVar9 + 4) & 1) != 0) && ((*(u32 *)(iVar9 + 4) & 0x10000) != 0)) {

      if (*(short *)(iVar9 + 0xac) < *(short *)(iVar9 + 0xae)) {

        sVar3 = *(short *)(iVar9 + 0xac) + 1;

        *(short *)(iVar9 + 0xac) = sVar3;

        fVar10 = (float)*(u8 *)(iVar9 + 0xa8) +

                 (float)(int)((int)sVar3 *

                             ((u32)*(u8 *)(iVar9 + 0xa4) - (u32)*(u8 *)(iVar9 + 0xa8))) /

                 (float)(int)*(short *)(iVar9 + 0xae);

        if (fVar10 < 2.1474836e+09) {

          uVar11 = (u8)(int)fVar10;

        }

        else {

          uVar11 = (u8)(int)(fVar10 - 2.1474836e+09);

        }

        *(u8 *)(iVar9 + 0x80) = uVar11;

        fVar10 = (float)*(u8 *)(iVar9 + 0xa9) +

                 (float)(int)((int)*(short *)(iVar9 + 0xac) *

                             ((u32)*(u8 *)(iVar9 + 0xa5) - (u32)*(u8 *)(iVar9 + 0xa9))) /

                 (float)(int)*(short *)(iVar9 + 0xae);

        if (fVar10 < 2.1474836e+09) {

          uVar11 = (u8)(int)fVar10;

        }

        else {

          uVar11 = (u8)(int)(fVar10 - 2.1474836e+09);

        }

        *(u8 *)(iVar9 + 0x81) = uVar11;

        fVar10 = (float)*(u8 *)(iVar9 + 0xaa) +

                 (float)(int)((int)*(short *)(iVar9 + 0xac) *

                             ((u32)*(u8 *)(iVar9 + 0xa6) - (u32)*(u8 *)(iVar9 + 0xaa))) /

                 (float)(int)*(short *)(iVar9 + 0xae);

        if (fVar10 < 2.1474836e+09) {

          uVar11 = (u8)(int)fVar10;

        }

        else {

          uVar11 = (u8)(int)(fVar10 - 2.1474836e+09);

        }

        *(u8 *)(iVar9 + 0x82) = uVar11;

        fVar10 = (float)*(u8 *)(iVar9 + 0xab) +

                 (float)(int)((int)*(short *)(iVar9 + 0xac) *

                             ((u32)*(u8 *)(iVar9 + 0xa7) - (u32)*(u8 *)(iVar9 + 0xab))) /

                 (float)(int)*(short *)(iVar9 + 0xae);

        if (fVar10 < 2.1474836e+09) {

          uVar11 = (u8)(int)fVar10;

        }

        else {

          uVar11 = (u8)(int)(fVar10 - 2.1474836e+09);

        }

        *(u8 *)(iVar9 + 0x83) = uVar11;

      }

      if (*(short *)(iVar9 + 0xd0) < *(short *)(iVar9 + 0xd2)) {

        sVar3 = *(short *)(iVar9 + 0xd0) + 1;

        *(short *)(iVar9 + 0xd0) = sVar3;

        *(float *)(iVar9 + 0x84) =

             *(float *)(iVar9 + 0xc0) +

             ((float)(int)sVar3 * (*(float *)(iVar9 + 0xb0) - *(float *)(iVar9 + 0xc0))) /

             (float)(int)*(short *)(iVar9 + 0xd2);

        *(float *)(iVar9 + 0x88) =

             *(float *)(iVar9 + 0xc4) +

             ((float)(int)*(short *)(iVar9 + 0xd0) *

             (*(float *)(iVar9 + 0xb4) - *(float *)(iVar9 + 0xc4))) /

             (float)(int)*(short *)(iVar9 + 0xd2);

        *(float *)(iVar9 + 0x8c) =

             *(float *)(iVar9 + 200) +

             ((float)(int)*(short *)(iVar9 + 0xd0) *

             (*(float *)(iVar9 + 0xb8) - *(float *)(iVar9 + 200))) /

             (float)(int)*(short *)(iVar9 + 0xd2);

        *(float *)(iVar9 + 0x90) =

             *(float *)(iVar9 + 0xcc) +

             ((float)(int)*(short *)(iVar9 + 0xd0) *

             (*(float *)(iVar9 + 0xbc) - *(float *)(iVar9 + 0xcc))) /

             (float)(int)*(short *)(iVar9 + 0xd2);

      }

      if (*(short *)(iVar9 + 0xf4) < *(short *)(iVar9 + 0xf6)) {

        sVar3 = *(short *)(iVar9 + 0xf4) + 1;

        *(short *)(iVar9 + 0xf4) = sVar3;

        *(float *)(iVar9 + 0x94) =

             *(float *)(iVar9 + 0xe4) +

             ((float)(int)sVar3 * (*(float *)(iVar9 + 0xd4) - *(float *)(iVar9 + 0xe4))) /

             (float)(int)*(short *)(iVar9 + 0xf6);

        *(float *)(iVar9 + 0x98) =

             *(float *)(iVar9 + 0xe8) +

             ((float)(int)*(short *)(iVar9 + 0xf4) *

             (*(float *)(iVar9 + 0xd8) - *(float *)(iVar9 + 0xe8))) /

             (float)(int)*(short *)(iVar9 + 0xf6);

        *(float *)(iVar9 + 0x9c) =

             *(float *)(iVar9 + 0xec) +

             ((float)(int)*(short *)(iVar9 + 0xf4) *

             (*(float *)(iVar9 + 0xdc) - *(float *)(iVar9 + 0xec))) /

             (float)(int)*(short *)(iVar9 + 0xf6);

        *(float *)(iVar9 + 0xa0) =

             *(float *)(iVar9 + 0xf0) +

             ((float)(int)*(short *)(iVar9 + 0xf4) *

             (*(float *)(iVar9 + 0xe0) - *(float *)(iVar9 + 0xf0))) /

             (float)(int)*(short *)(iVar9 + 0xf6);

      }


    }

  }

  else {

    if (iVar1 != 3) {

      if (iVar1 != 2) {

        if (iVar1 != 1) {

          return 0;

        }

        *(u32 *)(iVar9 + 8) = 2;

      }

      if (*(int *)(iVar9 + 0x18) != 0) {

        FUN_003174e0();

      }

      if (*(short *)(iVar9 + 0xc) == 0) {

        *(u32 *)(iVar9 + 8) = 4;

        *(u32 *)(iVar9 + 4) = *(u32 *)(iVar9 + 4) | 1;

        return 0;

      }

      uVar5 = FUN_00316e00(0xb,*(short *)(iVar9 + 0xc),0);

      *(u32 *)(iVar9 + 0x18) = uVar5;

      *(u32 *)(iVar9 + 8) = 3;

    }

    lVar7 = FUN_00316f70(*(u32 *)(iVar9 + 0x18));

    if (lVar7 != 0) {

      FUN_00319230(*(u32 *)(iVar9 + 0x18),8);

      *(u32 *)(iVar9 + 8) = 4;

      *(u32 *)(iVar9 + 4) = *(u32 *)(iVar9 + 4) | 1;

      if (*(short *)(iVar9 + 0xe) == 0) {

        *(u16 *)(*(int *)(iVar9 + 0x18) + 0xd8) =

             *(u16 *)(*(int *)(iVar9 + 0x18) + 0xd8) & 0xfeff;

        FUN_00319050(*(u32 *)(iVar9 + 0x18));

        sVar3 = FUN_0017c0e0(*(u16 *)(iVar9 + 0xc));

        if (sVar3 != 8) {

          if (sVar3 == 4) {

            FUN_00319070(*(u32 *)(iVar9 + 0x18));

          }

          else if (sVar3 == 2) {

            *(u16 *)(*(int *)(iVar9 + 0x18) + 0xd8) =

                 *(u16 *)(*(int *)(iVar9 + 0x18) + 0xd8) | 0x200;

          }

        }

        FUN_0016bc80(0,*(u16 *)(iVar9 + 0xc),iVar9 + 0x84);

        FUN_0016bdb0(0,*(u16 *)(iVar9 + 0xc),iVar9 + 0x94);

      }

      else {


      }

    }

  }

  return 0;

}
#define FUN_003ce2a0(...) ((u64 (*)(...))FUN_003ce2a0)(__VA_ARGS__)
#undef FUN_003cea50
// FUN_003CEA50 NONMATCHING


u64 FUN_003cea50(u16 *param_1)



{

  u32 uVar1;

  u32 uVar2;

  float *pfVar3;

  int iVar4;

  float *pfVar5;

  u64 uVar6;

  u64 uVar7;

  long lVar8;

  float *pfVar9;

  u32 *puVar10;

  u32 *puVar11;

  int iVar12;

  float fVar13;

  u32 uVar14;

  float fVar15;

  float fVar16;

  short sStack_160;

  short sStack_15e;

  short sStack_15c;

  float fStack_158;

  u32 uStack_154;

  short sStack_150;

  short sStack_144;

  short sStack_142;

  u32 auStack_140 [16];

  float fStack_100;

  float fStack_fc;

  float fStack_f8;

  float fStack_f4;

  float fStack_f0;

  float fStack_ec;

  float fStack_e8;

  u32 uStack_e4;

  float fStack_e0;

  float fStack_dc;

  float fStack_d8;

  float fStack_d0;

  float fStack_cc;

  float fStack_c8;

  u32 uStack_c0;

  u32 uStack_bc;

  u32 uStack_b8;

  u32 auStack_b0 [16];

  u32 uStack_70;

  u32 uStack_6c;

  u32 uStack_68;

  u32 uStack_64;

  u32 uStack_60;

  u32 uStack_5c;

  u32 uStack_58;

  u32 uStack_54;

  u64 uStack_48;

  float fStack_40;

  float fStack_38;

  float fStack_34;

  float fStack_30;

  u64 uStack_28;

  u32 uStack_20;

  float fStack_18;

  float fStack_14;

  u32 uStack_10;

  u32 uStack_c;

  u8 auStack_4 [3];

  u8 bStack_1;

  

  uVar6 = FUN_00198590();

  uVar14 = FUN_001a4600(uVar6);

  iVar4 = FUN_00198560();

  uStack_60 = *(u32 *)(iVar4 + 0x18);

  uStack_5c = *(u32 *)(iVar4 + 0x1c);

  uStack_58 = *(u32 *)(iVar4 + 0x20);

  uStack_54 = *(u32 *)(iVar4 + 0x24);

  iVar4 = FUN_00198570();

  uStack_70 = *(u32 *)(iVar4 + 0x18);

  uStack_6c = *(u32 *)(iVar4 + 0x1c);

  uStack_68 = *(u32 *)(iVar4 + 0x20);

  uStack_64 = *(u32 *)(iVar4 + 0x24);

  iVar4 = FUN_00198590();

  uStack_10 = *(u32 *)(iVar4 + 0x78);

  uStack_c = *(u32 *)(iVar4 + 0x7c);

  iVar4 = FUN_00198570();

  puVar11 = (u32 *)(*(int *)(iVar4 + 4) + 0x10);

  puVar10 = auStack_b0;

  iVar4 = 8;

  do {

    uVar1 = *puVar11;

    uVar2 = puVar11[1];

    puVar11 = puVar11 + 2;

    iVar4 = iVar4 + -1;

    *puVar10 = uVar1;

    puVar10[1] = uVar2;

    puVar10 = puVar10 + 2;

  } while (0 < iVar4);

  fStack_100 = DAT_006a4240;

  fStack_fc = DAT_006a4244;

  fStack_f8 = DAT_006a4248;

  fStack_f4 = DAT_006a424c;

  uStack_28 = DAT_006a4250;

  uStack_20 = DAT_006a4258;

  pfVar5 = (float *)0xc;

  pfVar9 = &fStack_38;

  pfVar3 = pfVar9;

  while (pfVar3 != (float *)0x0) {

    *(u8 *)pfVar9 = 0;

    pfVar9 = (float *)((int)pfVar9 + 1);

    pfVar5 = (float *)((int)pfVar5 + -1);

    pfVar3 = pfVar5;

  }

  uStack_48 = DAT_006a4260;

  fStack_40 = (float)DAT_006a4268;

  iVar4 = FUN_00198590();

  iVar12 = *(int *)(iVar4 + 4) + 0x10;

  uVar6 = FUN_00198590();

  FUN_001a4580(0x42200000,uVar6);

  uVar6 = FUN_00198560();

  FUN_004944b0(uVar6,param_1 + 0x42);

  uVar6 = FUN_00198570();

  FUN_004944b0(uVar6,param_1 + 0x4a);

  FUN_0016bee0(0,param_1[6],&fStack_100);

  fVar15 = 2.0 / (fStack_f4 * fStack_f4 +

                 fStack_f8 * fStack_f8 + fStack_100 * fStack_100 + fStack_fc * fStack_fc);

  fVar16 = fStack_100 * fVar15;

  fVar13 = fStack_fc * fVar15;

  fVar15 = fStack_f8 * fVar15;

  fStack_f0 = 1.0 - (fStack_fc * fVar13 + fStack_f8 * fVar15);

  fStack_ec = fStack_100 * fVar13 + fVar15 * fStack_f4;

  fStack_e8 = fStack_f8 * fVar16 - fVar13 * fStack_f4;

  fStack_e0 = fStack_100 * fVar13 - fVar15 * fStack_f4;

  fStack_dc = 1.0 - (fStack_f8 * fVar15 + fStack_100 * fVar16);

  fStack_d8 = fStack_fc * fVar15 + fVar16 * fStack_f4;

  fStack_d0 = fStack_f8 * fVar16 + fVar13 * fStack_f4;

  fStack_cc = fStack_fc * fVar15 - fVar16 * fStack_f4;

  fStack_c8 = 1.0 - (fStack_100 * fVar16 + fStack_fc * fVar13);

  uStack_c0 = 0;

  uStack_bc = 0;

  uStack_b8 = 0;

  uStack_e4 = 3;

  FUN_004c2f30(&fStack_f0,&fStack_f0,iVar12);

  iVar4 = FUN_00198570();

  FUN_004cb7f0(*(u32 *)(iVar4 + 4),&fStack_f0,0);

  iVar4 = FUN_00198570();

  *(u8 *)(iVar4 + 2) = 3;

  FUN_00198570();

  uVar6 = FUN_00198540(DAT_007ce0cc);

  uVar7 = FUN_00198580();

  FUN_0049c480(uVar6,uVar7);

  FUN_0016bf80(*param_1,param_1[6],&sStack_160);

  fStack_18 = (float)(int)sStack_144 / 640.0;

  fStack_14 = (float)(int)sStack_142 / 448.0;

  fStack_38 = (float)((int)(short)param_1[0xe] + (int)sStack_160);

  fStack_34 = (float)((int)(short)param_1[0xf] + (int)sStack_15e);

  fStack_30 = (float)((int)(short)param_1[0x10] + (int)sStack_15c);

  fStack_40 = *(float *)(param_1 + 0x12) + fStack_158;

  uStack_48 = CONCAT44(fStack_40,fStack_40);

  FUN_00521250(auStack_4,param_1 + 0x40,4);

  bStack_1 = (u8)((int)((u32)bStack_1 * (int)sStack_150) / 0xff);

  puVar11 = (u32 *)(param_1 + 0x20);

  puVar10 = auStack_140;

  iVar4 = 8;

  do {

    uVar1 = *puVar11;

    uVar2 = puVar11[1];

    puVar11 = puVar11 + 2;

    iVar4 = iVar4 + -1;

    *puVar10 = uVar1;

    puVar10[1] = uVar2;

    puVar10 = puVar10 + 2;

  } while (0 < iVar4);

  FUN_004c31b0(uStack_154,auStack_140,&uStack_28,1);

  FUN_004c35d0(auStack_140,&fStack_38,2);

  FUN_004c2f30(auStack_140,auStack_140,iVar12);

  FUN_00318a70(*(u32 *)(param_1 + 0xc),auStack_140,0);

  FUN_00318a90(*(u32 *)(param_1 + 0xc),&uStack_48,1);

  FUN_00318ad0(*(u32 *)(param_1 + 0xc),auStack_4);

  uVar6 = FUN_00198590();

  FUN_004c9d20(uVar6,&fStack_18);

  uVar6 = FUN_00198590();

  lVar8 = FUN_004c9d10(uVar6);

  if (lVar8 == 0) {

    FUN_0019d3f0(0x6a3e18,0xb2d);

  }

  else {

    (*DAT_00960090)(6,1);

    (*DAT_00960090)(8,1);

    (*DAT_00960090)(0xe,0);

    FUN_004d7f60(2,0x44);

    FUN_004d7f60(3,0x717fb);

    FUN_00317a20(*(u32 *)(param_1 + 0xc));

    uVar6 = FUN_00198590();

    FUN_004c9d00(uVar6);

  }

  uVar6 = FUN_00198590();

  FUN_001a4580(uVar14,uVar6);

  uVar6 = FUN_00198560();

  FUN_004944b0(uVar6,&uStack_60);

  uVar6 = FUN_00198570();

  FUN_004944b0(uVar6,&uStack_70);

  iVar4 = FUN_00198570();

  FUN_004cb7f0(*(u32 *)(iVar4 + 4),auStack_b0,0);

  iVar4 = FUN_00198570();

  *(u8 *)(iVar4 + 2) = 3;

  FUN_00198570();

  uVar6 = FUN_00198590();

  FUN_004c9d20(uVar6,&uStack_10);

  return 0;

}
#define FUN_003cea50(...) ((u64 (*)(...))FUN_003cea50)(__VA_ARGS__)
#undef FUN_003cf6c0
// FUN_003CF6C0 NONMATCHING


short FUN_003cf6c0(u64 param_1)



{

  u16 uVar1;

  u16 *puVar2;

  u32 uVar3;

  short sVar4;

  short sVar5;

  int iVar6;

  u16 *puVar7;

  

  puVar7 = (u16 *)(*(int *)(DAT_007ce680 + 0x24) + 4);

  for (iVar6 = 0; iVar6 < 3; iVar6 = iVar6 + 1) {

    if ((*puVar7 & 1) == 0) {

      sVar4 = (short)iVar6;

      goto LAB_003cf728;

    }

    puVar7 = puVar7 + 10;

  }

  sVar4 = -1;

LAB_003cf728:

  if (sVar4 == -1) {

    puVar7 = (u16 *)(*(int *)(DAT_007ce680 + 0x24) + 4);

    for (iVar6 = 0; iVar6 < 3; iVar6 = iVar6 + 1) {

      uVar1 = *puVar7;

      if ((((uVar1 & 1) != 0) && ((uVar1 & 2) == 0)) && ((uVar1 & 8) == 0)) {

        sVar4 = (short)iVar6;

        goto LAB_003cf7a4;

      }

      puVar7 = puVar7 + 10;

    }

    sVar4 = -1;

  }

LAB_003cf7a4:

  FUN_005225a8(0x7cd728,0x6a4270,0x167);

  FUN_005225a8(0x6a42d8,sVar4);

  FUN_001052b0(0x6a42d8,sVar4);

  sVar5 = -1;

  if (sVar4 != -1) {

    puVar2 = *(u16 **)((int)param_1 + 0x14);

    iVar6 = *(int *)(DAT_007ce680 + 0x24) + sVar4 * 0x14;

    puVar7 = (u16 *)(iVar6 + 4);

    *(u32 *)(iVar6 + 8) = *(u32 *)(puVar2 + 2);

    *(u16 *)(iVar6 + 4) = *puVar2;

    *(short *)(iVar6 + 0xc) = sVar4;

    uVar3 = *(u32 *)(iVar6 + 8);

    FUN_00106860(sVar4,(short)((u32)uVar3 >> 0x10),(u16)((u32)uVar3 >> 8) & 0xff,

                 (u16)uVar3 & 0xff);

    FUN_00106ec0(*(u16 *)(iVar6 + 0xc),1);

    FUN_00106f30(*(u16 *)(iVar6 + 0xc),0);

    uVar1 = *puVar7;

    *puVar7 = uVar1 | 1;

    *puVar7 = uVar1 | 3;

    FUN_003c49e0(DAT_007ce680,DAT_007ce680 + 4,param_1);

    sVar5 = sVar4;

  }

  return sVar5;

}
#define FUN_003cf6c0(...) ((short (*)(...))FUN_003cf6c0)(__VA_ARGS__)
#undef FUN_003cf960
// FUN_003CF960 NONMATCHING


u64 FUN_003cf960(int param_1,u16 param_2)



{

  u8 bVar1;

  short sVar2;

  u64 uVar3;

  u16 *puVar4;

  int iVar5;

  

  puVar4 = (u16 *)(*(int *)(DAT_007ce680 + 0x24) + 4);

  iVar5 = 0;

  do {

    if (2 < iVar5) {

      sVar2 = -1;

LAB_003cf9d8:

      if (sVar2 == -1) {

        uVar3 = FUN_003c4910(DAT_007ce680,0,0x14);

        puVar4 = *(u16 **)((int)uVar3 + 0x14);

        *(int *)(puVar4 + 2) = param_1;

        *puVar4 = param_2 & 0xff00 | 3;

      }

      else {

        iVar5 = sVar2 * 0x14 + *(int *)(DAT_007ce680 + 0x24);

        bVar1 = *(u8 *)(iVar5 + 4);

        *(u16 *)(iVar5 + 4) = (u16)bVar1;

        *(u16 *)(iVar5 + 4) = (u16)bVar1 | param_2 & 0xff00;

        FUN_005225a8(0x7cd728,0x6a4270,0x1b6);

        FUN_005225a8(0x6a42f0,sVar2);

        FUN_001052b0(0x6a42f0,sVar2);

        uVar3 = 0;

      }

      return uVar3;

    }

    if (((*puVar4 & 1) != 0) && (*(int *)(puVar4 + 2) == param_1)) {

      sVar2 = (short)iVar5;

      goto LAB_003cf9d8;

    }

    puVar4 = puVar4 + 10;

    iVar5 = iVar5 + 1;

  } while( 1 );

}
#define FUN_003cf960(...) ((u64 (*)(...))FUN_003cf960)(__VA_ARGS__)
#undef FUN_003cfb50
// FUN_003CFB50 NONMATCHING


void FUN_003cfb50(void)



{

  u16 uVar1;

  float *pfVar2;

  float *pfVar3;

  u16 uVar4;

  float *pfVar5;

  int iVar6;

  int iVar7;

  u16 *puVar8;

  float fStack_8;

  u32 uStack_4;

  

  puVar8 = (u16 *)(*(int *)(DAT_007ce680 + 0x24) + 4);

  iVar7 = 0;

  do {

    if (2 < iVar7) {

      return;

    }

    if ((*puVar8 & 1) != 0) {

      switch(puVar8[1]) {

      case 1:

        puVar8[1] = 2;

        uVar1 = *puVar8;

        *puVar8 = uVar1 | 8;

        *puVar8 = uVar1 | 0x18;

        *puVar8 = uVar1 & 0xfffb | 0x18;

        puVar8[8] = 0;

      case 2:

        puVar8[8] = puVar8[8] + 1;

        uVar1 = *puVar8;

        if ((uVar1 & 0x20) == 0) {

          if ((uVar1 & 0x100) == 0) {

            iVar6 = 0x120 - ((int)(short)puVar8[8] << 5) / 5;

          }

          else {

            iVar6 = ((int)(short)puVar8[8] << 5) / 5 + -0x9e;

          }

        }

        else if ((uVar1 & 0x100) == 0) {

          iVar6 = 0x100;

        }

        else {

          iVar6 = -0x7e;

        }

        pfVar3 = (float *)0x8;

        pfVar5 = &fStack_8;

        pfVar2 = pfVar5;

        while (pfVar2 != (float *)0x0) {

          *(u8 *)pfVar5 = 0;

          pfVar5 = (float *)((int)pfVar5 + 1);

          pfVar3 = (float *)((int)pfVar3 + -1);

          pfVar2 = pfVar3;

        }

        fStack_8 = (float)iVar6;

        FUN_00106fb0(puVar8[4],CONCAT44(uStack_4,fStack_8));

        FUN_00106e90(puVar8[4],((short)puVar8[8] * 0xff) / 5 & 0xff);

        FUN_00106f60(puVar8[4],0);

        if (4 < (short)puVar8[8]) {

          puVar8[8] = 0;

          uVar1 = *puVar8;

          *puVar8 = uVar1 | 4;

          *puVar8 = uVar1 & 0xffef | 4;

          puVar8[1] = 3;

        }

        break;

      case 3:

        FUN_00106f60(puVar8[4],0);

        break;

      case 4:

        puVar8[1] = 5;

        uVar1 = *puVar8;

        *puVar8 = uVar1 | 0x10;

        *puVar8 = uVar1 & 0xfffb | 0x10;

        puVar8[8] = 0;

      case 5:

        uVar1 = puVar8[8];

        puVar8[8] = uVar1 + 1;

        FUN_00106e90(puVar8[4],0xffU - ((short)(uVar1 + 1) * 0xff) / 5 & 0xff);

        FUN_00106f60(puVar8[4],0);

        if (4 < (short)puVar8[8]) {

          puVar8[8] = 0;

          uVar1 = *puVar8;

          uVar4 = uVar1 & 0xfff7;

          *puVar8 = uVar4;

          *puVar8 = uVar4 | 4;

          *puVar8 = uVar1 & 0xffe7 | 4;

          puVar8[1] = 0;

        }

      }

    }

    puVar8 = puVar8 + 10;

    iVar7 = iVar7 + 1;

  } while( 1 );

}
#define FUN_003cfb50(...) ((void (*)(...))FUN_003cfb50)(__VA_ARGS__)
