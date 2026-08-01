#include "temporary.h"
#include "Kosaka/k_assert.h"
#include "mw_harvest_compat.h"

/* auto-extern (generated) */
void FUN_00421650(u32 param_1);
void FUN_00423ba0(int param_1);
u32 FUN_004214e0(u64 param_1,int param_2);
void FUN_00423fc0(int param_1);
void FUN_00421fb0(void);
void FUN_00423c10(int param_1,char param_2);
void FUN_00423cd0(int param_1);
void FUN_00421f20(void);
u8 FUN_00423b70(int param_1);
u64 FUN_004238b0(u64 param_1,char param_2,char param_3,char param_4,char param_5,char param_6,

            char param_7,char param_8);
void FUN_004202e0(int param_1);
int FUN_00423bf0(int param_1);
char FUN_00423b50(int param_1);
u32 FUN_0041ec70(int param_1);
void FUN_004215b0(u64 param_1,u32 param_2);
extern u32 kwlnTaskGetWorkData(void);
#pragma alias H_Cdvd_Destroy_u32 H_Cdvd_Destroy
extern u32 H_Cdvd_Destroy_u32(u32 cdvd);
extern u64 FUN_00420f60(u64 param_1, int param_2);
extern u64 FUN_00421330(void);
extern void FUN_00420f90(void);
extern u64 FUN_00421460(void);
extern const char D_006B4380[];
extern const char D_006B4390[];
extern void FUN_0040e360(void);
extern u32 DAT_007e0958;
extern u32 DAT_007e095a;
extern u32 DAT_006b42c0;
extern float DAT_006b4370;
extern float DAT_006b4374;
extern float DAT_006b4378;
extern float DAT_006b437c;
extern u32 DAT_007cad74;
extern u32 DAT_007cada4;
extern u32 DAT_007cae00;
extern u32 DAT_007caf38;
extern u32 DAT_007cda7c;
extern u32 DAT_007cdacc;
extern u32 DAT_007cdaf8;
extern u32 DAT_007cdafc;
extern u32 DAT_007cdffc;
extern u32 DAT_007e094e;
extern u32 DAT_007e0952;
extern code DAT_00960088;
extern code DAT_00960090;
extern code DAT_009600a0;
extern code DAT_0096017c;
#pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];
extern code DAT_00960184;
extern void* PTR_DAT_007cda78;
extern void* PTR_PTR_007cdac8;
extern u32 cGpffffb9c0;
extern float fGpffff80c4;
extern float fGpffff8248;
extern u32 gp0xffffae00;
extern u32 gp0xffffb9b4;
extern u8* iGpffffadd8;
extern u8* iGpffffb9b8;
extern u32* puGpffffb9b8;
extern u32 uGpffffaddc;
extern u32 uGpffffade8;
extern u32 uGpffffadec;
extern u32 uGpffffb9b4;
extern u32* uGpffffb9b8;


// FUN_0041CC70 NONMATCHING


void FUN_0041cc70(int param_1,u32 param_2)



{

  int iVar1;

  int *piVar2;

  long lVar3;

  int iStack_4;

  

  *(u32 *)(param_1 + 8) = param_2;

  *(u32 *)(param_1 + 0xc) = 0;

  iVar1 = *(int *)(param_1 + 8);

  if (iVar1 == 3) {

    printf((const char *)0x7cdae8, 0x7cdaf0,0x2ae);

    printf((const char *)0x6b4110);

    H_Dbprt_FmtLog(0x6b4110);

    *(u32 *)(param_1 + 0xc) = 0xe;

  }

  else if (iVar1 == 2) {

    iVar1 = **(int **)(*(int *)(param_1 + 0x39c) + 0xc);

    lVar3 = FUN_00177db0(3,&iStack_4);

    piVar2 = (int *)(*DAT_00960184)(1,0x20008,0x40000);

    piVar2[1] = (int)(piVar2 + 2);

    if ((lVar3 != 0) && (iStack_4 != 0)) {

      memcpy((void *)piVar2[1], (void *)lVar3,iStack_4);

      *piVar2 = iStack_4;

    }

    (*DAT_0096017c)(lVar3);

    func_0018f170(iVar1 + -1,piVar2[1],*piVar2);

    *(int **)(param_1 + 0x3a0) = piVar2;

    FUN_004215b0(*(u32 *)(param_1 + 0x398),0xf);

    printf((const char *)0x7cdae8, 0x7cdaf0,0x2a9);

    printf((const char *)0x6b40f0);

    H_Dbprt_FmtLog(0x6b40f0);

    *(u32 *)(param_1 + 0xc) = 0;

  }

  else if (iVar1 == 1) {

    func_00191640(**(int **)(*(int *)(param_1 + 0x39c) + 0xc) + -1);

    *(u32 *)(param_1 + 0xc) = 0;

  }

  else if (iVar1 == 0) {

    func_00190cb0(param_1 + 0x14);

    FUN_004215b0(*(u32 *)(param_1 + 0x398),0xf);

    printf((const char *)0x7cdae8, 0x7cdaf0,0x29e);

    printf((const char *)0x6b40e0);

    H_Dbprt_FmtLog(0x6b40e0);

  }

  return;

}

// FUN_0041CEA0 NONMATCHING


u32 FUN_0041cea0(int param_1)



{

  int iVar1;

  long lVar2;

  long lVar3;

  

  iVar1 = *(int *)(param_1 + 0xc);

  if (iVar1 != 2) {

    if (iVar1 != 1) {

      if (iVar1 != 0xb) {

        if (iVar1 != 10) {

          if (iVar1 != 0) {

            return 0;

          }

          lVar2 = func_00190cd0();

          if ((((lVar2 == -5) || (lVar2 == -4)) || (lVar2 == -3)) || (lVar2 == -1)) {

            FUN_004215b0(*(u32 *)(param_1 + 0x398),0);

            printf((const char *)0x7cdae8, 0x7cdaf0,0x2d9);

            printf((const char *)0x6b4170, lVar2);

            H_Dbprt_FmtLog(0x6b4170,lVar2);

            *(u32 *)(param_1 + 0xc) = 10;

            return 0;

          }

          if (lVar2 == -2) {

            *(u32 *)(param_1 + 0xc) = 1;

            printf((const char *)0x7cdae8, 0x7cdaf0,0x2ce);

            printf((const char *)0x6b4150);

            H_Dbprt_FmtLog(0x6b4150);

            memset((void *)(param_1 + 0x14), 0, 0x380);

            return 0;

          }

          if (lVar2 != 100) {

            return 0;

          }

          FUN_00421650(*(u32 *)(param_1 + 0x398));

          printf((const char *)0x7cdae8, 0x7cdaf0,0x2c8);

          printf((const char *)0x6b4130);

          H_Dbprt_FmtLog(0x6b4130);

          return 1;

        }

        *(u32 *)(param_1 + 0xc) = 0xb;

        func_00190580();

      }

      lVar2 = FUN_00421700(*(u32 *)(param_1 + 0x398));

      lVar3 = func_00190590();

      if ((lVar3 != 3) && (lVar3 != -2)) {

        if (lVar2 == 0) {

          return 0;

        }

        return 4;

      }

      return 3;

    }

    *(u32 *)(param_1 + 0xc) = 2;

    *(u32 *)(param_1 + 0x3b8) = 0;

  }

  iVar1 = *(int *)(param_1 + 0x3b8) + 1;

  *(int *)(param_1 + 0x3b8) = iVar1;

  if (iVar1 < 0xf) {

    return 0;

  }

  FUN_00421650(*(u32 *)(param_1 + 0x398));

  return 1;

}

// FUN_0041D120 NONMATCHING


u32 FUN_0041d120(int param_1)



{

  int iVar1;

  long lVar2;

  

  iVar1 = *(int *)(param_1 + 0xc);

  if (iVar1 != 0xd) {

    if (iVar1 != 0xc) {

      if (iVar1 != 0xb) {

        if (iVar1 != 10) {

          if (iVar1 != 0) {

            return 0;

          }

          lVar2 = func_00191660();

          if ((((lVar2 == -9) || (lVar2 == -5)) || (lVar2 == -4)) || (lVar2 == -1)) {

            FUN_004215b0(*(u32 *)(param_1 + 0x398),0);

            printf((const char *)0x7cdae8, 0x7cdaf0,0x318);

            printf((const char *)0x6b4170, 0);

            H_Dbprt_FmtLog(0x6b4170,0);

            *(u32 *)(param_1 + 0xc) = 10;

            return 0;

          }

          if (lVar2 == -6) {

            FUN_004215b0(*(u32 *)(param_1 + 0x398),6);

            printf((const char *)0x7cdae8, 0x7cdaf0,0x30f);

            printf((const char *)0x6b41b0);

            H_Dbprt_FmtLog(0x6b41b0);

            *(u32 *)(param_1 + 0xc) = 10;

            return 0;

          }

          if (lVar2 != 100) {

            return 0;

          }

          printf((const char *)0x7cdae8, 0x7cdaf0,0x30a);

          printf((const char *)0x6b4190);

          H_Dbprt_FmtLog(0x6b4190);

          return 1;

        }

        *(u32 *)(param_1 + 0xc) = 0xb;

      }

      lVar2 = FUN_00421700(*(u32 *)(param_1 + 0x398));

      if (lVar2 == 0) {

        return 0;

      }

      *(u32 *)(param_1 + 0xc) = 0xc;

      return 0;

    }

    *(u32 *)(param_1 + 0xc) = 0xd;

    FUN_004215b0(*(u32 *)(param_1 + 0x398),8);

  }

  lVar2 = FUN_00421700(*(u32 *)(param_1 + 0x398));

  if (lVar2 == 0) {

    return 0;

  }

  return 4;

}

// FUN_0041D330 NONMATCHING


u64 FUN_0041d330(int param_1)



{

  u32 uVar1;

  long lVar2;

  

  switch(*(u32 *)(param_1 + 0xc)) {

  case 0:

    uVar1 = *(u32 *)(param_1 + 0x3a0);

    lVar2 = func_0018f2c0();

    if ((((lVar2 != -7) && (lVar2 != -6)) && (lVar2 != -5)) &&

       (((lVar2 != -4 && (lVar2 != -3)) && (lVar2 != -1)))) {

      if (lVar2 == 2) {

        printf((const char *)0x7cdae8, 0x7cdaf0,0x279);

        printf((const char *)0x6b40d0);

        H_Dbprt_FmtLog(0x6b40d0);

        lVar2 = 2;

      }

      else if (lVar2 == 1) {

        printf((const char *)0x7cdae8, 0x7cdaf0,0x274);

        printf((const char *)0x6b40b0);

        H_Dbprt_FmtLog(0x6b40b0);

        lVar2 = 1;

      }

      else if (lVar2 == 100) {

        (*DAT_0096017c)(uVar1);

      }

    }

    if (lVar2 != 0) {

      if (lVar2 == -7) {

        printf((const char *)0x7cdae8, 0x7cdaf0,0x362);

        printf((const char *)0x6b4170, 0xfffffffffffffff9);

        H_Dbprt_FmtLog(0x6b4170,0xfffffffffffffff9);

        FUN_004215b0(*(u32 *)(param_1 + 0x398),0x1c);

        *(u32 *)(param_1 + 0xc) = 10;

      }

      else if (lVar2 == -6) {

        printf((const char *)0x7cdae8, 0x7cdaf0,0x35d);

        printf((const char *)0x6b4170, 0xfffffffffffffffa);

        H_Dbprt_FmtLog(0x6b4170,0xfffffffffffffffa);

        FUN_004215b0(*(u32 *)(param_1 + 0x398),6);

        *(u32 *)(param_1 + 0xc) = 10;

      }

      else if (lVar2 == -3) {

        printf((const char *)0x7cdae8, 0x7cdaf0,0x358);

        printf((const char *)0x6b4170, 0xfffffffffffffffd);

        H_Dbprt_FmtLog(0x6b4170,0xfffffffffffffffd);

        FUN_004215b0(*(u32 *)(param_1 + 0x398),0);

        *(u32 *)(param_1 + 0xc) = 10;

      }

      else if (lVar2 == -5) {

        printf((const char *)0x7cdae8, 0x7cdaf0,0x353);

        printf((const char *)0x6b4170, 0xfffffffffffffffb);

        H_Dbprt_FmtLog(0x6b4170,0xfffffffffffffffb);

        FUN_004215b0(*(u32 *)(param_1 + 0x398),0);

        *(u32 *)(param_1 + 0xc) = 10;

      }

      else if (lVar2 == 5) {

        FUN_004215b0(*(u32 *)(param_1 + 0x398),7);

      }

      else if (lVar2 == 4) {

        printf((const char *)0x7cdae8, 0x7cdaf0,0x349);

        printf((const char *)0x6b41f0);

        H_Dbprt_FmtLog(0x6b41f0);

        *(u32 *)(param_1 + 0x10) = *(u32 *)(param_1 + 0x10) & 0xfffffffe;

        FUN_004215b0(*(u32 *)(param_1 + 0x398),7);

      }

      else if (lVar2 == 2) {

        printf((const char *)0x7cdae8, 0x7cdaf0,0x345);

        printf((const char *)0x6b4150);

        H_Dbprt_FmtLog(0x6b4150);

        *(u32 *)(param_1 + 0xc) = 5;

      }

      else if (lVar2 == 1) {

        *(u32 *)(param_1 + 0xc) = 3;

      }

      else if (lVar2 == 100) {

        FUN_004215b0(*(u32 *)(param_1 + 0x398),9);

        printf((const char *)0x7cdae8, 0x7cdaf0,0x33e);

        printf((const char *)0x6b41d0);

        H_Dbprt_FmtLog(0x6b41d0);

        *(u32 *)(param_1 + 0xc) = 9;

      }

    }

    break;

  case 3:

    *(u32 *)(param_1 + 0xc) = 4;

    FUN_004215b0(*(u32 *)(param_1 + 0x398),0);

    func_00190580();

  case 4:

    lVar2 = FUN_00421700(*(u32 *)(param_1 + 0x398));

    if (lVar2 == 2) {

      (*DAT_0096017c)(*(u32 *)(param_1 + 0x3a0));

      return 2;

    }

    if (lVar2 == 1) {

      *(u32 *)(param_1 + 0xc) = 0;

      FUN_004215b0(*(u32 *)(param_1 + 0x398),7);

      func_0018f2a0();

    }

    lVar2 = func_00190590();

    if ((lVar2 == 3) || (lVar2 == -5)) {

      printf((const char *)0x7cdae8, 0x7cdaf0,0x380);

      printf((const char *)0x6b4170, lVar2);

      H_Dbprt_FmtLog(0x6b4170,lVar2);

      FUN_004215b0(*(u32 *)(param_1 + 0x398),0);

      *(u32 *)(param_1 + 0xc) = 10;

    }

    break;

  case 5:

    *(u32 *)(param_1 + 0xc) = 6;

    *(u32 *)(param_1 + 0x10) = *(u32 *)(param_1 + 0x10) | 1;

    FUN_004215b0(*(u32 *)(param_1 + 0x398),1);

    func_00190580();

  case 6:

    lVar2 = FUN_00421700(*(u32 *)(param_1 + 0x398));

    if (lVar2 == 2) {

      return 2;

    }

    if (lVar2 == 1) {

      *(u32 *)(param_1 + 0xc) = 0;

      FUN_004215b0(*(u32 *)(param_1 + 0x398),0);

      func_0018f2b0();

    }

    lVar2 = func_00190590();

    if ((lVar2 == 3) || (lVar2 == -5)) {

      printf((const char *)0x7cdae8, 0x7cdaf0,0x39b);

      printf((const char *)0x6b4170, lVar2);

      H_Dbprt_FmtLog(0x6b4170,lVar2);

      FUN_004215b0(*(u32 *)(param_1 + 0x398),0);

      *(u32 *)(param_1 + 0xc) = 10;

    }

    break;

  case 9:

    lVar2 = FUN_00421700(*(u32 *)(param_1 + 0x398));

    if (lVar2 != 0) {

      return 1;

    }

    break;

  case 10:

    *(u32 *)(param_1 + 0xc) = 0xb;

    func_00190580();

  case 0xb:

    lVar2 = FUN_00421700(*(u32 *)(param_1 + 0x398));

    if (lVar2 != 0) {

      *(u32 *)(param_1 + 0xc) = 0xc;

    }

    lVar2 = func_00190590();

    if ((lVar2 == 3) || (lVar2 == -2)) {

      *(u32 *)(param_1 + 0xc) = 0xc;

    }

    break;

  case 0xc:

    *(u32 *)(param_1 + 0xc) = 0xd;

    func_00190580();

    if ((*(u32 *)(param_1 + 0x10) & 1) == 0) {

      FUN_004215b0(*(u32 *)(param_1 + 0x398),8);

    }

    else {

      FUN_004215b0(*(u32 *)(param_1 + 0x398),3);

    }

    *(u32 *)(param_1 + 0x10) = *(u32 *)(param_1 + 0x10) & 0xfffffffe;

    (*DAT_0096017c)(*(u32 *)(param_1 + 0x3a0));

  case 0xd:

    lVar2 = FUN_00421700(*(u32 *)(param_1 + 0x398));

    if (lVar2 != 0) {

      return 4;

    }

    lVar2 = func_00190590();

    if ((lVar2 == 3) || (lVar2 == -2)) {

      return 4;

    }

  }

  return 0;

}

// FUN_0041DB20 NONMATCHING


u64 FUN_0041db20(int param_1)



{

  int iVar1;

  int *piVar2;

  long lVar3;

  u64 uVar4;

  int iVar5;

  u8 auStack_8 [4];

  u32 uStack_4;

  

  switch(*(u32 *)(param_1 + 0xc)) {

  case 0xc:

    *(u32 *)(param_1 + 0xc) = 0xd;

    func_00190580();

    FUN_004215b0(*(u32 *)(param_1 + 0x398),0xe);

switchD_0041db60_caseD_d:

    lVar3 = FUN_00421700(*(u32 *)(param_1 + 0x398));

    if (lVar3 == 0) {

      lVar3 = func_00190590();

      if ((lVar3 == 3) || (lVar3 == -2)) {

        printf((const char *)0x7cdae8, 0x7cdaf0,0x446);

        printf((const char *)0x6b4170, lVar3);

        H_Dbprt_FmtLog(0x6b4170,lVar3);

        uVar4 = 4;

      }

      else {

switchD_0041db60_default:

        uVar4 = 0;

      }

    }

    else {

      uVar4 = 4;

    }

    return uVar4;

  case 0xd:

    goto switchD_0041db60_caseD_d;

  case 0xe:

    *(u32 *)(param_1 + 0xc) = 0xf;

    FUN_004215b0(*(u32 *)(param_1 + 0x398),0xb);

    func_00190580();

  case 0xf:

    lVar3 = FUN_00421700(*(u32 *)(param_1 + 0x398));

    if (lVar3 == 2) {

      return 2;

    }

    if (lVar3 == 1) {

      FUN_004215b0(*(u32 *)(param_1 + 0x398),0xc);

      *(u32 *)(param_1 + 0xc) = 0x10;

    }

    lVar3 = func_00190590();

    if ((lVar3 == 3) || (lVar3 == -5)) {

      printf((const char *)0x7cdae8, 0x7cdaf0,0x3eb);

      printf((const char *)0x6b4170, lVar3);

      H_Dbprt_FmtLog(0x6b4170,lVar3);

      return 4;

    }

    goto switchD_0041db60_default;

  case 0x10:

    *(u32 *)(param_1 + 0xc) = 0x11;

    iVar1 = **(int **)(*(int *)(param_1 + 0x39c) + 0xc);

    uVar4 = (*DAT_00960184)(1,0x20008,0x40000);

    iVar5 = (int)uVar4;

    *(int *)(iVar5 + 4) = iVar5 + 8;

    func_00190700(iVar1 + -1,*(u32 *)(iVar5 + 4),uVar4);

    *(int *)(param_1 + 0x3a0) = iVar5;

  case 0x11:

    lVar3 = func_00190720();

    if (lVar3 != 0) {

      if (((lVar3 == -3) || (lVar3 == -5)) || (lVar3 != 100)) {

        printf((const char *)0x7cdae8, 0x7cdaf0,0x407);

        printf((const char *)0x6b4250);

        H_Dbprt_FmtLog(0x6b4250);

        *(u32 *)(param_1 + 0xc) = 0xc;

        (*DAT_0096017c)(*(u32 *)(param_1 + 0x3a0));

      }

      else {

        piVar2 = *(int **)(param_1 + 0x3a0);

        uStack_4 = 3;

        uVar4 = FUN_00177db0(3,auStack_8);

        (*DAT_0096017c)(uVar4);

        memcpy(&uStack_4, (void *)piVar2[1], 4);

        lVar3 = FUN_001791d0(uStack_4,piVar2[1] + 4,*piVar2 + -4);

        if (lVar3 != 0) {

          FUN_00179030(uStack_4,piVar2[1] + 4,*piVar2 + -4);

          DAT_007cdffc = 1;

        }

        (*DAT_0096017c)(*(u32 *)(param_1 + 0x3a0));

        if (lVar3 != 0) {

          printf((const char *)0x7cdae8, 0x7cdaf0,0x3fb);

          printf((const char *)0x6b4210);

          H_Dbprt_FmtLog(0x6b4210);

          *(u32 *)(param_1 + 0xc) = 0x12;

        }

        else {

          printf((const char *)0x7cdae8, 0x7cdaf0,0x400);

          printf((const char *)0x6b4230);

          H_Dbprt_FmtLog(0x6b4230);

          *(u32 *)(param_1 + 0xc) = 0x14;

        }

      }

    }

    goto switchD_0041db60_default;

  case 0x12:

    *(u32 *)(param_1 + 0xc) = 0x13;

    FUN_004215b0(*(u32 *)(param_1 + 0x398),0xd);

  case 0x13:

    lVar3 = FUN_00421700(*(u32 *)(param_1 + 0x398));

    if (lVar3 != 0) {

      return 1;

    }

    goto switchD_0041db60_default;

  case 0x14:

    *(u32 *)(param_1 + 0xc) = 0x15;

    FUN_004215b0(*(u32 *)(param_1 + 0x398),0x14);

    func_00190580();

  case 0x15:

    lVar3 = FUN_00421700(*(u32 *)(param_1 + 0x398));

    if (lVar3 != 0) {

      *(u32 *)(param_1 + 0xc) = 0xc;

    }

    lVar3 = func_00190590();

    if ((lVar3 == 3) || (lVar3 == -2)) {

      *(u32 *)(param_1 + 0xc) = 0xc;

    }

  default:

    goto switchD_0041db60_default;

  }

}

// FUN_0041E010 NONMATCHING


u32 FUN_0041e010(u64 param_1)



{

  int iVar1;

  long lVar2;

  int iVar3;

  

  iVar3 = (int)param_1;

  FUN_003c6270(*(u32 *)(iVar3 + 0x39c));

  lVar2 = FUN_003c6ce0(*(u32 *)(iVar3 + 0x39c));

  if ((lVar2 != 0) || (lVar2 = FUN_003c6d10(*(u32 *)(iVar3 + 0x39c)), lVar2 != 0)) {

    func_0010a4e0(0,0,0,0);

  }

  lVar2 = FUN_003c6ca0(*(u32 *)(iVar3 + 0x39c));

  if ((lVar2 != 0) || (lVar2 = FUN_003c6cc0(*(u32 *)(iVar3 + 0x39c)), lVar2 != 0)) {

    func_0010a4e0(0,0,0,5);

  }

  switch(*(u16 *)(iVar3 + 2)) {

  case 0:

    *(u16 *)(iVar3 + 2) = 2;

    *(u32 *)(iVar3 + 4) = *(u32 *)(iVar3 + 4) | 0x400;

    return 0;

  case 1:

    *(u32 *)(iVar3 + 4) = *(u32 *)(iVar3 + 4) | 0x800;

    return 1;

  case 2:

    *(u16 *)(iVar3 + 2) = 3;

    FUN_0041cc70(param_1,0);

    FUN_0041c180(param_1,5,0);

  case 3:

    lVar2 = 0;

    iVar1 = *(int *)(iVar3 + 8);

    if (iVar1 == 3) {

      lVar2 = FUN_0041db20(param_1);

    }

    else if (iVar1 == 2) {

      lVar2 = FUN_0041d330(param_1);

    }

    else if (iVar1 == 1) {

      lVar2 = FUN_0041d120(param_1);

    }

    else if (iVar1 == 0) {

      lVar2 = FUN_0041cea0(param_1);

    }

    if (lVar2 == 4) {

      *(u16 *)(iVar3 + 2) = 1;

      FUN_0041c180(param_1,5);

    }

    else if (lVar2 == 3) {

      *(u16 *)(iVar3 + 2) = 2;

      FUN_0041c180(param_1,5,1);

    }

    else if (lVar2 == 1) {

      *(u16 *)(iVar3 + 2) = 4;

      FUN_0041c180(param_1,5);

    }

    break;

  case 4:

    *(u16 *)(iVar3 + 2) = 5;

    FUN_003c6ee0(*(u32 *)(iVar3 + 0x39c));

    FUN_003c6ec0(*(u32 *)(iVar3 + 0x39c));

  case 5:

    *(u16 *)(iVar3 + 2) = 6;

    func_00190580();

    FUN_003c6ec0(*(u32 *)(iVar3 + 0x39c));

    FUN_0041c180(param_1,6,0);

    FUN_0041c180(param_1,4,0);

  case 6:

    lVar2 = FUN_003c6c50(*(u32 *)(iVar3 + 0x39c));

    if (lVar2 == 0) {

      lVar2 = FUN_003c6c80(*(u32 *)(iVar3 + 0x39c));

      if (lVar2 != 0) {

        FUN_0041c180(param_1,6,1);

        FUN_0041c180(param_1,4,1);

        *(u16 *)(iVar3 + 2) = 1;

        func_0010a4e0(0,0,0,2);

        return 0;

      }

    }

    else if ((*(u32 *)(iVar3 + 4) & 2) == 0) {

      lVar2 = FUN_0041ec70(param_1);

      if (lVar2 == 0) {

        func_0010a4e0(0,0,0,8);

      }

      else {

        *(u16 *)(iVar3 + 2) = 0xc;

        FUN_003c6ea0(*(u32 *)(iVar3 + 0x39c));

        func_0010a4e0(0,0,0,1);

      }

    }

    else {

      *(u16 *)(iVar3 + 2) = 7;

      FUN_003c6ea0(*(u32 *)(iVar3 + 0x39c));

      func_0010a4e0(0,0,0,1);

    }

    lVar2 = func_00190590();

    if (((lVar2 == -5) || (lVar2 == -4)) || (lVar2 == 3)) {

      *(u16 *)(iVar3 + 2) = 2;

      FUN_003c6ea0(*(u32 *)(iVar3 + 0x39c));

      FUN_0041c180(param_1,4,1);

    }

    break;

  case 7:

    *(u16 *)(iVar3 + 2) = 8;

    FUN_0041c180(param_1,6,1);

    FUN_0041c180(param_1,4,1);

    FUN_0041c180(param_1,5,0);

    FUN_0041cc70(param_1,1);

  case 8:

    lVar2 = 0;

    iVar1 = *(int *)(iVar3 + 8);

    if (iVar1 == 3) {

      lVar2 = FUN_0041db20(param_1);

    }

    else if (iVar1 == 2) {

      lVar2 = FUN_0041d330(param_1);

    }

    else if (iVar1 == 1) {

      lVar2 = FUN_0041d120(param_1);

    }

    else if (iVar1 == 0) {

      lVar2 = FUN_0041cea0(param_1);

    }

    if (lVar2 != 4) {

      if (lVar2 != 1) {

        return 0;

      }

      *(u16 *)(iVar3 + 2) = 9;

      return 0;

    }

    FUN_0041c180(param_1,5,1);

    *(u16 *)(iVar3 + 2) = 2;

    return 0;

  case 9:

    *(u16 *)(iVar3 + 2) = 0xb;

    FUN_0041cc70(param_1,2);

  case 0xb:

    lVar2 = 0;

    iVar1 = *(int *)(iVar3 + 8);

    if (iVar1 == 3) {

      lVar2 = FUN_0041db20(param_1);

    }

    else if (iVar1 == 2) {

      lVar2 = FUN_0041d330(param_1);

    }

    else if (iVar1 == 1) {

      lVar2 = FUN_0041d120(param_1);

    }

    else if (iVar1 == 0) {

      lVar2 = FUN_0041cea0(param_1);

    }

    if (lVar2 == 4) {

      FUN_0041c180(param_1,5,1);

      *(u16 *)(iVar3 + 2) = 2;

      return 0;

    }

    if (lVar2 == 2) {

      FUN_0041c180(param_1,5,1);

      *(u16 *)(iVar3 + 2) = 5;

      return 0;

    }

    if (lVar2 != 1) {

      return 0;

    }

    *(u16 *)(iVar3 + 2) = 1;

    *(u32 *)(iVar3 + 4) = *(u32 *)(iVar3 + 4) | 8;

    return 0;

  case 0xc:

    *(u16 *)(iVar3 + 2) = 0xd;

    FUN_0041c180(param_1,6,1);

    FUN_0041c180(param_1,4,1);

    FUN_0041c180(param_1,5,0);

    FUN_0041cc70(param_1,3);

  case 0xd:

    lVar2 = 0;

    iVar1 = *(int *)(iVar3 + 8);

    if (iVar1 == 3) {

      lVar2 = FUN_0041db20(param_1);

    }

    else if (iVar1 == 2) {

      lVar2 = FUN_0041d330(param_1);

    }

    else if (iVar1 == 1) {

      lVar2 = FUN_0041d120(param_1);

    }

    else if (iVar1 == 0) {

      lVar2 = FUN_0041cea0(param_1);

    }

    if (lVar2 == 4) {

      FUN_0041c180(param_1,5,1);

      *(u16 *)(iVar3 + 2) = 2;

      return 0;

    }

    if (lVar2 == 2) {

      FUN_0041c180(param_1,5,1);

      *(u16 *)(iVar3 + 2) = 5;

      return 0;

    }

    if (lVar2 != 1) {

      return 0;

    }

    FUN_0041c180(param_1,5);

    *(u16 *)(iVar3 + 2) = 1;

    return 0;

  }

  return 0;

}

// FUN_0041E830 NONMATCHING


u32 FUN_0041e830(void)



{

  short sVar1;

  u16 *puVar2;

  u32 uVar3;

  u64 uVar4;

  long lVar5;

  

  uVar4 = kwlnTaskGetWorkData();

  puVar2 = (u16 *)uVar4;

  switch(*puVar2) {

  case 0:

    *puVar2 = 1;

  case 1:

    *puVar2 = 2;

    uVar3 = H_Cdvd_Request(0x6b4270,1);

    *(u32 *)(puVar2 + 0x1da) = uVar3;

  case 2:

    lVar5 = H_Cdvd_IsFileLoaded(*(u32 *)(puVar2 + 0x1da));

    if (lVar5 != 0) {

      *puVar2 = 3;

    }

    break;

  case 3:

    *puVar2 = 4;

    uVar4 = FUN_003efef0();

    FUN_0040e300(uVar4,0);

  case 4:

    lVar5 = FUN_0040e390();

    if (lVar5 != 0) {

      *puVar2 = 5;

      *(u32 *)(puVar2 + 2) = *(u32 *)(puVar2 + 2) | 1;

    }

    break;

  case 5:

    lVar5 = datGetScenarioMode();

    if (lVar5 == 0) {

      uVar3 = H_Cdvd_Request(0x6b4298,1);

      *(u32 *)(puVar2 + 0x1d8) = uVar3;

    }

    else {

      uVar3 = H_Cdvd_Request(0x6b4280,1);

      *(u32 *)(puVar2 + 0x1d8) = uVar3;

    }

    *puVar2 = 6;

  case 6:

    lVar5 = H_Cdvd_IsFileLoaded(*(u32 *)(puVar2 + 0x1d8));

    if (lVar5 != 0) {

      *puVar2 = 7;

    }

    break;

  case 7:

    *puVar2 = 8;

    FUN_0041c180(uVar4,0,0);

  case 8:

    lVar5 = FUN_0041e010(uVar4);

    if (lVar5 != 0) {

      *puVar2 = 9;

    }

    break;

  case 9:

    if (puVar2[0x1d5] == 0xff) {

      *puVar2 = 10;

    }

    break;

  case 10:

    return 0xffffffff;

  }

  if ((*(u32 *)(puVar2 + 2) & 0x400) == 0) {

    if ((*(u32 *)(puVar2 + 2) & 0x800) != 0) {

      sVar1 = puVar2[0x1d4];

      puVar2[0x1d4] = sVar1 + 1;

      puVar2[0x1d5] = (short)(((short)(sVar1 + 1) * 0xff) / 5);

      if (4 < (short)puVar2[0x1d4]) {

        *(u32 *)(puVar2 + 2) = *(u32 *)(puVar2 + 2) & 0xfffff7ff;

        puVar2[0x1d5] = 0xff;

        puVar2[0x1d4] = 0;

      }

    }

  }

  else {

    sVar1 = puVar2[0x1d4];

    puVar2[0x1d4] = sVar1 + 1;

    puVar2[0x1d5] = 0xff - (short)(((short)(sVar1 + 1) * 0xff) / 5);

    if (4 < (short)puVar2[0x1d4]) {

      *(u32 *)(puVar2 + 2) = *(u32 *)(puVar2 + 2) & 0xfffffbff;

      puVar2[0x1d5] = 0;

      puVar2[0x1d4] = 0;

    }

  }

  FUN_003e0650(*(u32 *)(puVar2 + 0x1d6));

  return 0;

}

// FUN_0041EAF0
void FUN_0041eaf0(void)
{
    u32 work;

    work = kwlnTaskGetWorkData();
    if (*(u32 *)(work + 0x3b4) != 0)
    {
        H_Cdvd_Destroy_u32(*(u32 *)(work + 0x3b4));
    }
    FUN_0040e360();
    FUN_004202e0(work);
}

// FUN_0041EB50 NONMATCHING


u64 FUN_0041eb50(void)



{

  int iVar1;

  u64 uVar2;

  

  uVar2 = kwlnTaskGetWorkData();

  iVar1 = (int)uVar2;

  if ((*(u32 *)(iVar1 + 4) & 1) != 0) {

    *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 4;

    FUN_003e0680(*(u32 *)(iVar1 + 0x3ac),0x41ff50,uVar2);

    *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) & 0xfffffffb;

    FUN_003c6380(*(u32 *)(iVar1 + 0x39c));

    FUN_003e0680(*(u32 *)(iVar1 + 0x3ac),0x41ff50,uVar2);

    if (*(short *)(iVar1 + 0x3aa) != 0) {

      func_00113a30(0, (long)*(short *)(iVar1 + 0x3aa) & 0xffU | 0xf1f2800,
                    0, 0, 0x280, 0x1c0);

    }

  }

  return 0;

}

// FUN_0041EC30


void FUN_0041ec30(int param_1)



{

  FUN_003e0650(*(u32 *)(*(int *)(*(int *)(param_1 + 0x24) + 0x44) + 0x3a4));

  return;

}

// FUN_0041EC60
void FUN_0041ec60(void)
{
}


// FUN_0041EC70

u32 FUN_0041ec70(int param_1)



{
  u32 uVar1;

  return *(u32 *)((**(int **)(*(int *)(param_1 + 0x39c) + 0xc) - 1) * 4 + (uVar1 = param_1) + 0x14);

}

// FUN_0041ECA0 NONMATCHING


void FUN_0041eca0(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5)



{

  short sVar1;

  short *psVar2;

  u32 uVar3;

  float fVar4;

  u32 uVar5;

  

  psVar2 = *(short **)(param_5 + 0x34);

  sVar1 = *psVar2;

  *psVar2 = sVar1 + 1;

  if (0x31 < (short)(sVar1 + 1)) {

    *psVar2 = 0;

  }

  fVar4 = (float)sinf((DAT_007caf38 * (float)(int)*psVar2) / 50.0);

  uVar5 = (u32)((float)(int)param_3 * (DAT_007cad74 * fVar4 + DAT_007cada4 + 0.0));

  if (*(int *)(*(int *)(param_4 + 0x39c) + 0xc) == *(int *)(*(int *)(param_4 + 0x39c) + 4)) {

    if (0 < psVar2[1]) {

      psVar2[1] = psVar2[1] + -1;

    }

    uVar3 = (int)((DAT_007cada4 * (float)(int)param_3 * (float)(int)psVar2[1]) / 10.0);

  }

  else {

    psVar2[1] = 10;

    uVar3 = uVar5;

  }

  if (*(int *)(*(int *)(param_4 + 0x39c) + 0xc) == *(int *)(*(int *)(param_4 + 0x39c) + 8)) {

    if (0 < psVar2[2]) {

      psVar2[2] = psVar2[2] + -1;

    }

    uVar5 = (u32)((DAT_007cada4 * (float)(int)param_3 * (float)(int)psVar2[2]) / 10.0);

  }

  else {

    psVar2[2] = 10;

  }

  FUN_0040e3c0(0,0,0,param_3 & 0xff,6,0);

  FUN_0040e3c0(0,0,0,param_3 & 0xff,7,0);

  FUN_0040e3c0(0,0,0,uVar3 & 0xff,7,2);

  FUN_0040e3c0(0,0,0,param_3 & 0xff,8,0);

  FUN_0040e3c0(0,0,0,param_3 & 0xff,9,0);

  FUN_0040e3c0(0,0,0,uVar5 & 0xff,9,2);

  return;

}

// FUN_0041EF40 NONMATCHING


void FUN_0041ef40(u64 param_1,int param_2,u32 param_3,u64 param_4,int param_5)



{

  short sVar1;

  short *psVar2;

  int iVar3;

  int iVar4;

  float fVar5;

  

  psVar2 = *(short **)(param_5 + 0x34);

  sVar1 = *psVar2;

  *psVar2 = sVar1 + 1;

  if (0x57 < (short)(sVar1 + 1)) {

    *psVar2 = 0;

  }

  iVar3 = (int)*psVar2;

  iVar4 = iVar3 + -2;

  if (iVar4 < 0) {

    iVar4 = iVar3 + 0x56;

  }

  else if (0x58 < iVar4) {

    iVar4 = iVar3 + -0x5a;

  }

  if (0x27 < iVar4) {

    if (iVar4 < 0x2f) {

      fVar5 = (float)sinf((DAT_007cae00 * (float)(iVar4 + -0x28)) / 6.0);

      param_2 = (int)(fVar5 * 200.0 + (float)param_2 + 0.0);

      param_3 = (u32)(((float)(int)param_3 * (fVar5 * -255.0 + 255.0)) / 255.0);

    }

    else if (iVar4 < 0x46) {

      param_3 = 0;

    }

    else if (iVar4 < 0x4e) {

      fVar5 = (float)sinf((DAT_007cae00 * (float)(iVar4 + -0x46)) / 7.0);

      param_2 = (int)((float)param_2 + fVar5 * 150.0 + -150.0);

      param_3 = (u32)(((float)(int)param_3 * fVar5 * 255.0) / 255.0);

    }

  }

  FUN_0040e3f0(0,0xc2b40000,0x3f800000,0x3f800000,param_1,param_2 + 0xfa,param_3 & 0xff,5,0,0,0);

  sVar1 = *psVar2;

  if (0x27 < sVar1) {

    if (sVar1 < 0x2f) {

      fVar5 = (float)sinf((DAT_007cae00 * (float)(sVar1 + -0x28)) / 6.0);

      param_2 = (int)(fVar5 * 200.0 + (float)param_2 + 0.0);

      param_3 = (u32)(((float)(int)param_3 * (fVar5 * -255.0 + 255.0)) / 255.0);

    }

    else if (sVar1 < 0x46) {

      param_3 = 0;

    }

    else if (sVar1 < 0x4e) {

      fVar5 = (float)sinf((DAT_007cae00 * (float)(sVar1 + -0x46)) / 7.0);

      param_2 = (int)((float)param_2 + fVar5 * 150.0 + -150.0);

      param_3 = (u32)(((float)(int)param_3 * fVar5 * 255.0) / 255.0);

    }

  }

  FUN_0040e3f0(0,0xc2b40000,0x3f800000,0x3f800000,param_1,param_2 + 0xfa,param_3 & 0xff,2,0,0,0);

  return;

}

// FUN_0041F370 NONMATCHING


void FUN_0041f370(u64 param_1,u64 param_2,u32 param_3,int param_4,int *param_5,

                 long param_6)



{

  int iVar1;

  int iVar2;

  u32 uVar3;

  u32 uVar4;

  int iVar5;

  u32 *puVar6;

  int iVar7;

  u32 uVar8;

  int iVar9;

  u32 uVar10;

  int iVar11;

  int iVar12;

  u8 auStack_10 [8];

  u32 auStack_8 [2];

  

  auStack_8[0] = DAT_007cdaf8;

  auStack_8[1] = DAT_007cdafc;

  iVar7 = *param_5;

  iVar2 = *(int *)(*(int *)(param_4 + 0x24) + 0x44) + (iVar7 + -1) * 0x34;

  uVar3 = clndGetMonthFromDaysSinceApr5(*(u16 *)(iVar2 + 0x54));

  uVar4 = clndGetDayOfMonthFromDaysSinceApr5(*(u16 *)(iVar2 + 0x54));

  iVar5 = clndGetWeekDay(*(u16 *)(iVar2 + 0x54));

  iVar5 = iVar5 + -1;

  if (iVar5 < 0) {

    iVar5 = 6;

  }

  iVar1 = *(int *)(iVar2 + 0x58);

  uVar8 = param_3;

  if (param_6 == 0) {

    uVar8 = (int)((float)(int)param_3 * 0.5);

  }

  iVar9 = (int)param_6;

  iVar12 = iVar9 * 2;

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar12 + 0x18,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar12 + 0x15,iVar7 + -1);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar12 + 0x28,0);

  if (*(char *)(iVar2 + 0x5e) != '\0') {

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar9 + 0x32,0);

  }

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x1b,0);

  iVar11 = (int)param_1;

  FUN_0040e3c0(0,iVar11 + -2,param_2,uVar8 & 0xff,iVar9 + 0x1e,0);

  sprintf((char *)auStack_10,(const char *)0x7cdb00,uVar3);

  uVar10 = uVar8 & 0xff | 0xffffff00;

  iVar12 = (int)param_2;

  FUN_0040ec20(0,iVar11 + 0x79,iVar12 + 0xe,uVar10,param_6,auStack_10,2,0x10,0x41c140);

  sprintf((char *)auStack_10,(const char *)0x7cdb00,uVar4);

  FUN_0040ec20(0,iVar11 + 0xa9,iVar12 + 0xe,uVar10,param_6,auStack_10,2,0x10,0x41c140);

  FUN_0040e3c0(0,iVar11 + -0x25,param_2,uVar8 & 0xff,iVar9 + 0x22,0);

  FUN_0040e3c0(0,iVar11 + -0x25,param_2,uVar8 & 0xff,iVar9 + 0x26,iVar5);

  FUN_0040e3c0(0,iVar11 + -0x25,param_2,uVar8 & 0xff,iVar9 + 0x24,0);

  iVar7 = 1;

  do {

    if (DAT_007cda7c <= iVar7) {

      uVar10 = *(u32 *)((u8 *)PTR_DAT_007cda78 + 8);

LAB_0041f6b4:

      FUN_003b2cb0(0,iVar11 + 0xf4,iVar12 + 4,uVar8 | 0xffffff00,*(u8 *)(auStack_8 + iVar9),

                   1,uVar10,0,0);

      FUN_0040e3c0(0,param_1,param_2,uVar8 & 0xff,0x2b,0);

      sprintf((char *)auStack_10,(const char *)0x7cdb00,*(u8 *)(iVar2 + 0x5c));

      uVar10 = uVar8 & 0xff | 0xffffff00;

      FUN_0040ec20(0,iVar11 + 0x9b,iVar12 + 0x2d,uVar10,0,auStack_10,2,0x10,0x41c140);

      FUN_003b2f90(0,iVar11 + 0xbc,iVar12 + 0x1f,uVar8 | 0xffffff00,5,0,iVar2 + 0x72,1,

                   0xffffffffffffffff);

      FUN_0040e3c0(0,param_1,param_2,uVar8 & 0xff,0x2c,0);

      FUN_0040e3c0(0,param_1,param_2,uVar8 & 0xff,0x2d,0);

      sprintf((char *)auStack_10,(const char *)0x7cdb00,iVar1 / 0x1a5e0);

      FUN_0040ec20(0,iVar11 + 0x119,iVar12 + 0x3f,uVar10,0,auStack_10,1,0x10,0x41c140);

      FUN_0040e3c0(0,iVar11 + -0xc,param_2,uVar8 & 0xff,0x2e,0);

      sprintf((char *)auStack_10,(const char *)0x7cdb00,(iVar1 / 0x708) % 0x3c);

      FUN_0040ec20(0,iVar11 + 0x15a,iVar12 + 0x3f,uVar10,0,auStack_10,1,0x10,0x41c140);

      if (*(char *)(iVar2 + 0x5d) == '\x01') {

        FUN_0040e3c0(0,param_1,param_2,uVar8 & 0xff,0x30,0);

      }

      else if (*(char *)(iVar2 + 0x5d) == '\0') {

        FUN_0040e3c0(0,param_1,param_2,uVar8 & 0xff,0x2f,0);

      }

      else {

        FUN_0040e3c0(0,param_1,param_2,uVar8 & 0xff,0x3b,0);

      }

      return;

    }

    puVar6 = (u32 *)((u8 *)PTR_DAT_007cda78 + iVar7 * 0xc);

    if (((u32)*(u8 *)(iVar2 + 0x84) == *puVar6) && ((u32)*(u8 *)(iVar2 + 0x85) == puVar6[1]))

    {

      uVar10 = puVar6[2];

      goto LAB_0041f6b4;

    }

    iVar7 = iVar7 + 1;

  } while( true );

}

// FUN_0041F940 NONMATCHING


void FUN_0041f940(u64 param_1,u64 param_2,u32 param_3,int param_4,int *param_5,

                 u64 param_6)



{

  int iVar1;

  int iVar2;

  u32 uVar3;

  u32 uVar4;

  u64 uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  u32 uVar9;

  u32 uVar10;

  u8 auStack_8 [8];

  

  iVar7 = *param_5;

  iVar2 = *(int *)(*(int *)(param_4 + 0x24) + 0x44) + (iVar7 + -1) * 0x34;

  uVar5 = clndGetMonthFromDaysSinceApr5(*(u16 *)(iVar2 + 0x54));

  uVar3 = clndGetDayOfMonthFromDaysSinceApr5(*(u16 *)(iVar2 + 0x54));

  uVar4 = clndGetWeekDay(*(u16 *)(iVar2 + 0x54));

  iVar1 = *(int *)(iVar2 + 0x58);

  iVar8 = (int)param_1;

  uVar10 = (u32)((float)(int)param_3 * 0.5);

  iVar6 = (int)param_6;

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar6 + 0x19,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar6 + 0x16,iVar7 + -1);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar6 + 0x29,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar6 + 0x32,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x34,param_6);

  FUN_0040e3c0(0,iVar8 + 0x102,param_2,uVar10 & 0xff,iVar6 + 0x1e,0);

  sprintf((char *)auStack_8,(const char *)0x7cdb00,uVar5);

  uVar9 = uVar10 & 0xff | 0xffffff00;

  iVar7 = (int)param_2;

  FUN_0040ec20(0,iVar8 + 0x17d,iVar7 + 0xe,uVar9,param_6,auStack_8,2,0x10,0x41c140);

  FUN_0040e3c0(0,iVar8 + 0x104,param_2,uVar10 & 0xff,iVar6 + 0x20,0);

  sprintf((char *)auStack_8,(const char *)0x7cdb00,uVar3);

  FUN_0040ec20(0,iVar8 + 0x1ad,iVar7 + 0xe,uVar9,param_6,auStack_8,2,0x10,0x41c140);

  FUN_0040e3c0(0,iVar8 + 0xdf,param_2,uVar10 & 0xff,iVar6 + 0x22,0);

  FUN_0040e3c0(0,iVar8 + 0xdf,param_2,uVar10 & 0xff,iVar6 + 0x26,uVar4);

  FUN_0040e3c0(0,iVar8 + 0xdf,param_2,uVar10 & 0xff,iVar6 + 0x24,0);

  FUN_0040e3c0(0,param_1,param_2,uVar10 & 0xff,0x2b,0);

  sprintf((char *)auStack_8,(const char *)0x7cdb00,*(u8 *)(iVar2 + 0x5c));

  FUN_0040ec20(0,iVar8 + 0x9b,iVar7 + 0x2d,uVar9,0,auStack_8,2,0x10,0x41c140);

  FUN_0040e3c0(0,param_1,param_2,uVar10 & 0xff,0x2c,0);

  FUN_0040e3c0(0,param_1,param_2,uVar10 & 0xff,0x2d,0);

  sprintf((char *)auStack_8,(const char *)0x7cdb00,iVar1 / 0x1a5e0);

  FUN_0040ec20(0,iVar8 + 0x119,iVar7 + 0x3f,uVar9,0,auStack_8,1,0x10,0x41c140);

  FUN_0040e3c0(0,iVar8 + -0xc,param_2,uVar10 & 0xff,0x2e,0);

  sprintf((char *)auStack_8,(const char *)0x7cdb00,(iVar1 / 0x708) % 0x3c);

  FUN_0040ec20(0,iVar8 + 0x15a,iVar7 + 0x3f,uVar9,0,auStack_8,1,0x10,0x41c140);

  return;

}

// FUN_0041FD90 NONMATCHING


void FUN_0041fd90(u64 param_1,u64 param_2,u32 param_3,u64 param_4,

                 int *param_5)



{

  bool bVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  char cVar5;

  

  iVar2 = *(int *)(*(int *)((int)param_4 + 0x24) + 0x44);

  iVar4 = *param_5 + -1;

  iVar3 = iVar2 + iVar4 * 0x34;

  bVar1 = param_5 == *(int **)((int)param_4 + 0xc);

  if (*(int *)(iVar4 * 4 + iVar2 + 0x14) == 0) {

    cVar5 = bVar1 * '\x02';

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,cVar5 + '\x18',0);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,cVar5 + '\x15',iVar4);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,cVar5 + '(',0);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,bVar1 + '5',0);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,bVar1 + '7',0);

  }

  else if (((*(char *)(iVar3 + 0x5e) == '\0') || (*(short *)(iVar3 + 0x54) != 2)) ||

          (*(short *)(iVar3 + 0x56) != 0)) {

    FUN_0041f370(param_1,param_2,param_3,param_4,param_5,bVar1);

  }

  else {

    FUN_0041f940(param_1,param_2,param_3,param_4,param_5,bVar1);

  }

  return;

}

// FUN_0041FF50 NONMATCHING


void FUN_0041ff50(u64 param_1,int param_2,int param_3)



{

  u16 uVar1;

  short sVar2;

  u16 uVar3;

  int iVar4;

  short sVar5;

  

  uVar1 = *(u16 *)(param_2 + 0x14);

  sVar2 = *(short *)(param_2 + 0x16);

  uVar3 = *(u16 *)(param_2 + 0x26);

  if (uVar3 != 0) {

    switch(*(u32 *)(param_2 + 0x10)) {

    case 0:

      if ((*(u32 *)(param_3 + 4) & 4) != 0) {

        FUN_0040e3c0(0,0,0,uVar3 & 0xff,0x14,0);

        FUN_0040e3c0(0,0,0,uVar3 & 0xff,0x12,0);

        FUN_0040e3c0(0,0,0,uVar3 & 0xff,0x13,0);

      }

      break;

    case 1:

      if ((*(u32 *)(param_3 + 4) & 4) == 0) {

        if ((*(u32 *)(param_3 + 4) & 2) == 0) {

          FUN_0040e3c0(0,0,0,uVar3 & 0xff,10,0);

          FUN_0040e3c0(0,0,0,uVar3 & 0xff,0xb,0);

        }

        else {

          FUN_0040e3c0(0,0,0,uVar3 & 0xff,0xd,0);

          FUN_0040e3c0(0,0,0,uVar3 & 0xff,0xe,0);

        }

      }

      break;

    case 2:

      if ((*(u32 *)(param_3 + 4) & 4) == 0) {

        FUN_0040e3c0(0,0,0,uVar3 & 0xff,0x10,0);

        FUN_0040e3c0(0,0,0,uVar3 & 0xff,0x11,0);

      }

      break;

    case 3:

      if ((*(u32 *)(param_3 + 4) & 4) == 0) {

        ((code)FUN_0041eca0)((u64)uVar1,(u64)(int)sVar2,(u32)uVar3);

      }

      break;

    case 4:

      if ((*(u32 *)(param_3 + 4) & 4) == 0) {

        iVar4 = *(int *)(param_2 + 0x34);

        sVar5 = *(short *)(iVar4 + 2) + 1;

        *(short *)(iVar4 + 2) = sVar5;

        if (0x31 < sVar5) {

          *(u16 *)(iVar4 + 2) = 0;

        }

        if ((*(u32 *)(param_3 + 4) & 2) == 0) {

          FUN_0040e3f0(0,0xc2b40000,0x3f800000,0x3f800000,uVar1,sVar2 + 0xfa,uVar3 & 0xff,4,0,0,0);

          FUN_0040e3f0(0,0xc2b40000,0x3f800000,0x3f800000,uVar1,sVar2 + 0xfa,uVar3 & 0xff,1,0,0,0);

        }

        else {

          FUN_0040e3f0(0,0xc2b40000,0x3f800000,0x3f800000,uVar1,sVar2 + 0xfa,uVar3 & 0xff,3,0,0,0);

          FUN_0040e3f0(0,0xc2b40000,0x3f800000,0x3f800000,uVar1,sVar2 + 0xfa,uVar3 & 0xff,0,0,0,0);

        }

      }

      break;

    case 5:

      if ((*(u32 *)(param_3 + 4) & 4) == 0) {

        ((code)FUN_0041ef40)((u64)uVar1,(int)sVar2,(u32)uVar3);

      }

    }

  }

  return;

}

// FUN_004202E0


void FUN_004202e0(int param_1)



{

  void H_Cdvd_Destroy(struct HCdvd *cdvd);

  if (*(struct HCdvd **)(param_1 + 0x3b0) != 0) {

    H_Cdvd_Destroy(*(struct HCdvd **)(param_1 + 0x3b0));

  }

  FUN_003dff00(*(u32 *)(param_1 + 0x3a4));

  FUN_003dff00(*(u32 *)(param_1 + 0x3ac));

  FUN_003c5a20(*(u32 *)(param_1 + 0x39c));

  return;

}

// FUN_00420340 NONMATCHING


u64 FUN_00420340(u64 param_1,int param_2)



{

  u16 *puVar1;

  int iVar2;

  u32 uVar3;

  u64 uVar4;

  int iVar5;

  

  uVar4 = FUN_003c58f0(0,0x3bc,4,0x5a);

  puVar1 = *(u16 **)(*(int *)((int)uVar4 + 0x24) + 0x44);

  *(int *)(puVar1 + 0x1ce) = (int)uVar4;

  uVar3 = FUN_003dfeb0(puVar1);

  *(u32 *)(puVar1 + 0x1d2) = uVar3;

  uVar3 = FUN_003dfeb0(puVar1);

  *(u32 *)(puVar1 + 0x1d6) = uVar3;

  FUN_003c5e80(uVar4,0x41ec30);

  FUN_003c5e20(uVar4,0x41ec60);

  FUN_003c5ee0(uVar4,0x41fd90);

  FUN_003c6d40(uVar4,0x4b,0x29);

  iVar2 = *(int *)(puVar1 + 0x1ce);

  for (iVar5 = 0; iVar5 < 0x10; iVar5 = iVar5 + 1) {

    FUN_003c5a40(iVar2,*(u16 *)(iVar2 + 0x10) + 1,0,0);

  }

  *puVar1 = 0;

  puVar1[1] = 0;

  if (param_2 == 1) {

    *(u32 *)(puVar1 + 2) = *(u32 *)(puVar1 + 2) | 2;

  }

  uVar4 = kwlnTaskCreate(param_1,0x7cdb08,10,0x41e830,0x41eaf0,puVar1);

  uVar3 = kwlnTaskCreate(uVar4,0x6b42a8,0x1cc4,0x41eb50,0,puVar1);

  *(u32 *)(puVar1 + 0x1ca) = uVar3;

  uVar3 = FUN_004214e0(uVar4,0);

  *(u32 *)(puVar1 + 0x1cc) = uVar3;

  return uVar4;

}

// FUN_004204F0


bool FUN_004204f0(void)



{

  int iVar1;

  

  iVar1 = kwlnTaskGetWorkData();

  return (*(u32 *)(iVar1 + 4) & 8) != 0;

}

#pragma push
#pragma opt_common_subs off
// FUN_00420520 NONMATCHING


void FUN_00420520(u32 *param_1,int param_2,int param_3)



{

  u32 uVar1;

  u32 uVar2;

  u32 uVar3;

  u8 *puVar4;

  u64 uVar5;

  int iVar6;

  u32 *puVar7;

  u32 *puVar8;

  u32 auStack_4e0 [6];

  u16 uStack_4c8;

  u32 uStack_4c4;

  u16 uStack_4ac;

  u32 uStack_4a8;

  u16 uStack_490;

  u32 uStack_48c;

  u16 uStack_474;

  u32 uStack_470;

  u16 uStack_458;

  u32 auStack_454 [6];

  u16 uStack_43c;

  u32 auStack_430 [6];

  u16 uStack_418;

  u32 uStack_414;

  u16 uStack_3fc;

  u32 uStack_3f8;

  u16 uStack_3e0;

  u32 auStack_3dc [6];

  u16 uStack_3c4;

  u32 uStack_3c0;

  u16 uStack_3a8;

  u32 uStack_3a4;

  u16 uStack_38c;

  u32 auStack_380 [6];

  u16 uStack_368;

  u32 uStack_364;

  u16 uStack_34c;

  u32 uStack_348;

  u16 uStack_330;

  u32 uStack_32c;

  u16 uStack_314;

  u32 auStack_310 [6];

  u16 uStack_2f8;

  u32 uStack_2f4;

  u16 uStack_2dc;

  u32 auStack_2d0 [6];

  u16 uStack_2b8;

  u32 uStack_2b4;

  u16 uStack_29c;

  u32 auStack_298 [6];

  u16 uStack_280;

  u32 uStack_27c;

  u16 uStack_264;

  u32 uStack_260;

  u16 uStack_248;

  u32 uStack_244;

  u16 uStack_22c;

  u32 auStack_220 [6];

  u16 uStack_208;

  u32 auStack_204 [6];

  u16 uStack_1ec;

  u32 uStack_1e8;

  u16 uStack_1d0;

  u32 uStack_1cc;

  u16 uStack_1b4;

  u32 uStack_1b0;

  u16 uStack_198;

  u32 uStack_194;

  u16 uStack_17c;

  u32 auStack_170 [6];

  u16 uStack_158;

  u32 uStack_154;

  u16 uStack_13c;

  u32 uStack_138;

  u16 uStack_120;

  u32 uStack_11c;

  u16 uStack_104;

  u32 uStack_100;

  u16 uStack_e8;

  u32 uStack_e4;

  u16 uStack_cc;

  u8 auStack_c0 [4];

  u32 uStack_bc;

  u8 auStack_a0 [4];

  u32 uStack_9c;

  u8 auStack_80 [4];

  u32 uStack_7c;

  u8 auStack_60 [4];

  u32 uStack_5c;

  u8 auStack_40 [4];

  u32 uStack_3c;

  u8 auStack_20 [4];

  u32 uStack_1c;

  

  if (param_2 == 1) {

    if (param_3 == 0) {

      uVar1 = param_1[6];

      puVar8 = &DAT_006b42c0;

      puVar7 = auStack_2d0;

      iVar6 = 0x15;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_2d0[0] = 1;

      uStack_2b8 = 6;

      uStack_2b4 = 1;

      uStack_29c = 6;

      auStack_298[0] = 1;

      uStack_280 = 6;

      uStack_27c = 1;

      uStack_264 = 6;

      uStack_260 = 1;

      uStack_248 = 6;

      uStack_244 = 1;

      uStack_22c = 6;

      memcpy(auStack_60,auStack_298,0x1c);

      uVar5 = FUN_003dffc0(uVar1,1,uStack_5c);

      fclCombineList003df100(uVar5,auStack_60);

      puVar4 = PTR_PTR_007cdac8;

      uVar1 = *param_1;

      if (DAT_007cdacc <= uVar1) {

        K_Assert((const char *)0x7cdaf0,0x13b);

      }

      if (*(short *)(puVar4 + uVar1 * 0xc + 8) == 1) {

        uVar1 = param_1[6];

        puVar8 = &DAT_006b42c0;

        puVar7 = auStack_380;

        iVar6 = 0x15;

        do {

          uVar2 = *puVar8;

          uVar3 = puVar8[1];

          puVar8 = puVar8 + 2;

          iVar6 = iVar6 + -1;

          *puVar7 = uVar2;

          puVar7[1] = uVar3;

          puVar7 = puVar7 + 2;

        } while (0 < iVar6);

        auStack_380[0] = 2;

        uStack_368 = 10;

        uStack_364 = 2;

        uStack_34c = 10;

        uStack_348 = 2;

        uStack_330 = 10;

        uStack_32c = 2;

        uStack_314 = 10;

        auStack_310[0] = 2;

        uStack_2f8 = 10;

        uStack_2f4 = 2;

        uStack_2dc = 10;

        memcpy(auStack_80,auStack_310,0x1c);

        uVar5 = FUN_003dffc0(uVar1,2,uStack_7c);

        fclCombineList003df100(uVar5,auStack_80);

      }

    }

    else if (param_3 == 1) {

      uVar1 = param_1[6];

      puVar8 = &DAT_006b42c0;

      puVar7 = auStack_430;

      iVar6 = 0x15;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_430[0] = 1;

      uStack_418 = 6;

      uStack_414 = 1;

      uStack_3fc = 6;

      uStack_3f8 = 1;

      uStack_3e0 = 6;

      auStack_3dc[0] = 1;

      uStack_3c4 = 6;

      uStack_3c0 = 1;

      uStack_3a8 = 6;

      uStack_3a4 = 1;

      uStack_38c = 6;

      memcpy(auStack_a0,auStack_3dc,0x1c);

      uVar5 = FUN_003dffc0(uVar1,1,uStack_9c);

      fclCombineList003df100(uVar5,auStack_a0);

      puVar4 = PTR_PTR_007cdac8;

      uVar1 = *param_1;

      if (DAT_007cdacc <= uVar1) {

        K_Assert((const char *)0x7cdaf0,0x13b);

      }

      if (*(short *)(puVar4 + uVar1 * 0xc + 8) == 1) {

        uVar1 = param_1[6];

        puVar8 = &DAT_006b42c0;

        puVar7 = auStack_4e0;

        iVar6 = 0x15;

        do {

          uVar2 = *puVar8;

          uVar3 = puVar8[1];

          puVar8 = puVar8 + 2;

          iVar6 = iVar6 + -1;

          *puVar7 = uVar2;

          puVar7[1] = uVar3;

          puVar7 = puVar7 + 2;

        } while (0 < iVar6);

        auStack_4e0[0] = 2;

        uStack_4c8 = 6;

        uStack_4c4 = 2;

        uStack_4ac = 6;

        uStack_4a8 = 2;

        uStack_490 = 6;

        uStack_48c = 2;

        uStack_474 = 6;

        uStack_470 = 2;

        uStack_458 = 6;

        auStack_454[0] = 2;

        uStack_43c = 6;

        memcpy(auStack_c0,auStack_454,0x1c);

        uVar5 = FUN_003dffc0(uVar1,2,uStack_bc);

        fclCombineList003df100(uVar5,auStack_c0);

      }

    }

  }

  else if (param_2 == 0) {

    if (param_3 == 0) {

      uVar1 = param_1[6];

      puVar8 = &DAT_006b42c0;

      puVar7 = auStack_170;

      iVar6 = 0x15;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_170[0] = 0;

      uStack_158 = 0;

      uStack_154 = 0;

      uStack_13c = 0;

      uStack_138 = 0;

      uStack_120 = 0;

      uStack_11c = 0;

      uStack_104 = 0;

      uStack_100 = 0;

      uStack_e8 = 0;

      uStack_e4 = 0;

      uStack_cc = 0;

      memcpy(auStack_20,auStack_170,0x1c);

      uVar5 = FUN_003dffc0(uVar1,0,uStack_1c);

      fclCombineList003df100(uVar5,auStack_20);

    }

    else if (param_3 == 1) {

      uVar1 = param_1[6];

      puVar8 = &DAT_006b42c0;

      puVar7 = auStack_220;

      iVar6 = 0x15;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_220[0] = 0;

      uStack_208 = 6;

      auStack_204[0] = 0;

      uStack_1ec = 6;

      uStack_1e8 = 0;

      uStack_1d0 = 6;

      uStack_1cc = 0;

      uStack_1b4 = 6;

      uStack_1b0 = 0;

      uStack_198 = 6;

      uStack_194 = 0;

      uStack_17c = 6;

      memcpy(auStack_40,auStack_204,0x1c);

      uVar5 = FUN_003dffc0(uVar1,0,uStack_3c);

      fclCombineList003df100(uVar5,auStack_40);

    }

  }

  return;
}
#pragma opt_common_subs on
#pragma pop

// FUN_00420A20 NONMATCHING






void FUN_00420a20(int param_1,int param_2,u32 param_3,u32 *param_4)



{

  short sVar1;

  int iVar2;

  u32 uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  u32 uVar8;

  float uStack_10;

  float uStack_c;

  float uStack_8;

  float uStack_4;

  


  iVar7 = (int)(iGpffffadd8);
  uStack_10 = DAT_006b4370;

  uStack_c = DAT_006b4374;

  uStack_8 = DAT_006b4378;

  uStack_4 = DAT_006b437c;

  uVar8 = *param_4;

  if (uGpffffaddc <= uVar8) {

    K_Assert((const char *)&gp0xffffae00,0x136);

  }


  iVar2 = (int)(iGpffffadd8);
  iVar7 = *(int *)(uVar8 * 0xc + iVar7 + 4);

  if (uGpffffaddc <= uVar8) {

    K_Assert((const char *)&gp0xffffae00,0x131);

  }

  iVar2 = *(int *)(iVar2 + uVar8 * 0xc);

  iVar5 = FUN_003b35c0(1);

  uVar8 = (u32)(fGpffff80c4 * (float)(int)param_3);

  param_3 = param_3 | 0xffffffffffffff00;

  for (iVar6 = 0; iVar4 = (int)iGpffffadd8, iVar6 < iVar7; iVar6 = iVar6 + 1) {

    FUN_003b2cb0(0,param_1 + 0x160,((param_2 + 200) - (iVar5 * iVar7 >> 1)) + iVar6 * iVar5,param_3,

                 7,1,*(u32 *)(iVar2 + iVar6 * 4),8,0);

  }

  iVar7 = iVar5 * (iVar7 + 2) >> 1;

  uVar3 = *param_4;

  if (uGpffffaddc <= uVar3) {

    K_Assert((const char *)&gp0xffffae00,0x13b);

  }

  sVar1 = *(short *)(uVar3 * 0xc + iVar4 + 8);

  if ((sVar1 != 1) && (sVar1 == 2)) {

    if (param_4[4] == 0) {

      FUN_0040d5e0(0,param_1 + 0xf0,param_2 + 0xb4 + iVar7 + iVar5,0x50,4,uVar8 & 0xff | 0xffffff00)

      ;

      FUN_003b2cb0(0,param_1 + 0xfc,param_2 + 0xb4 + iVar7,param_3,

                   *(u8 *)(&uStack_10 + param_4[4] * 2),0,uGpffffade8,0,0);

      FUN_003b2cb0(0,param_1 + 0x192,param_2 + 0xb6 + iVar7,uVar8 | 0xffffff00,

                   *(u8 *)((int)&uStack_c + param_4[4] * 8),1,uGpffffadec,0,0);

    }

    else {

      FUN_0040d5e0(0,param_1 + 0x17c,param_2 + 0xb4 + iVar7 + iVar5,0x50,4,uVar8 & 0xff | 0xffffff00

                  );

      FUN_003b2cb0(0,param_1 + 0xfc,param_2 + 0xb6 + iVar7,uVar8 | 0xffffff00,

                   *(u8 *)(&uStack_10 + param_4[4] * 2),1,uGpffffade8,0,0);

      FUN_003b2cb0(0,param_1 + 0x192,param_2 + 0xb4 + iVar7,param_3,

                   *(u8 *)((int)&uStack_c + param_4[4] * 8),0,uGpffffadec,0,0);

    }

  }

  return;

}

// FUN_00420DA0 NONMATCHING


void FUN_00420da0(int param_1,int param_2,int param_3)



{

  short sVar1;

  short sVar2;

  int iVar3;

  u32 uVar4;

  

  sVar1 = *(short *)(param_2 + 0x14);

  sVar2 = *(short *)(param_2 + 0x16);

  uVar4 = (u32)*(short *)(param_2 + 0x26);

  if (uVar4 != 0) {

    iVar3 = *(int *)(param_2 + 0x10);

    if (iVar3 == 2) {

      if (*(int *)(param_3 + 0xc) == 1) {

        FUN_0040dcc0(0,sVar1 + 0x202,sVar2 + 0x17c,10,7,7,uVar4 | 0xffffffffffffff00,0xb4,0);

      }

      else if (*(int *)(param_3 + 0xc) == 0) {

        FUN_0040dcc0(0,sVar1 + 0x226,sVar2 + 0x17c,10,7,7,uVar4 | 0xffffffffffffff00,0xb4,0);

      }

    }

    else if (iVar3 == 1) {

      if (*(int *)(param_3 + 0xc) == 1) {

        FUN_00420a20(sVar1 + -0x24,sVar2,uVar4,(u32 *)*(u32 *)(param_1 + 4));

      }

      else if (*(int *)(param_3 + 0xc) == 0) {

        FUN_00420a20(sVar1,sVar2,uVar4,(u32 *)*(u32 *)(param_1 + 4));

      }

    }

    else if (iVar3 == 0) {

      if (*(int *)(param_3 + 0xc) == 1) {

        FUN_0040d5e0(0,0x30,0x30,sVar1,sVar2,uVar4 & 0xff | 0xe8bec00);

      }

      else if (*(int *)(param_3 + 0xc) == 0) {

        FUN_0040d5e0(0,0x54,0x30,sVar1,sVar2,uVar4 & 0xff | 0xe8bec00);

      }

    }

  }

  return;

}

// FUN_00420F60


u64 FUN_00420f60(u64 param_1,int param_2)



{

  FUN_003dff00(*(u32 *)(*(int *)(param_2 + 0x14) + 0x18));

  return 0;

}

// FUN_00420F90


void FUN_00420f90(void)



{

  u32 *puVar1;

  

  puVar1 = (u32 *)kwlnTaskGetWorkData();

  FUN_003dff00(puVar1[5]);

  FUN_003c45f0(*puVar1);

  return;

}

#pragma push
#pragma opt_common_subs off
// FUN_00420FE0 NONMATCHING


u32 FUN_00420fe0(u64 param_1,u32 *param_2)



{


  u32 uVar2;

  int iVar3;

  short sVar1;

  



  switch(param_2[2]) {

  case 0:

    param_2[2] = 2;

    param_2[1] = param_2[1] | 1;

    FUN_00420520((u32 *)param_2,0,0);

    FUN_00420520((u32 *)param_2,1,0);

    iVar3 = (int)(iGpffffadd8);

    uVar2 = *param_2;

    if (uGpffffaddc <= uVar2) {

      K_Assert((const char *)&gp0xffffae00,0x140);

    }

    if (*(int *)(uVar2 * 0xc + iVar3 + 8) >> 0x10 == 1) {

      param_2[4] = 1;

    }

  case 2:

    param_2[2] = 3;

    param_2[3] = 0;

  case 3:

    uVar2 = param_2[3];

    param_2[3] = uVar2 + 1;

    if (9 < (int)(uVar2 + 1)) {

      param_2[3] = 0;

      param_2[2] = 6;

    }

    break;

  case 4:

    param_2[2] = 5;

    param_2[3] = 0;

  case 5:

    uVar2 = param_2[3];

    param_2[3] = uVar2 + 1;

    if (9 < (int)(uVar2 + 1)) {

      param_2[3] = 0;

      param_2[2] = 1;

      param_2[1] = param_2[1] & 0xfffffffe;

      return 1;

    }

    break;

  case 6:
    iVar3 = (int)(iGpffffadd8);

    uVar2 = *param_2;

    if (uGpffffaddc <= uVar2) {

      K_Assert((const char *)&gp0xffffae00,0x13b);

    }

    sVar1 = *(short *)(uVar2 * 0xc + iVar3 + 8);

    if (sVar1 == 2) {

      if (((DAT_007e094e & 0x8000) == 0) && ((DAT_007e0958 & 0x8000) == 0)) {

        if (((DAT_007e094e & 0x2000) == 0) && ((DAT_007e0958 & 0x2000) == 0)) {

          if (((DAT_007e094e & 0x40) != 0) || ((DAT_007e0958 & 0x40) != 0)) {

            param_2[1] = param_2[1] | 4;

            func_0010a4e0(0,0,0,1);

          }

        }

        else {

          param_2[4] = 1;

          func_0010a4e0(0,0,0,0);

        }

      }

      else {

        param_2[4] = 0;

        func_0010a4e0(0,0,0,0);

      }

    }

    else if ((sVar1 == 1) && (((DAT_007e094e & 0x40) != 0 || ((DAT_007e0958 & 0x40) != 0)))) {

      param_2[1] = param_2[1] | 4;

      func_0010a4e0(0,0,0,1);

    }

    if ((param_2[1] & 4) != 0) {

      param_2[2] = 4;

      FUN_00420520((u32 *)param_2,0,1);

      FUN_00420520((u32 *)param_2,1,1);

    }

  }

  FUN_003e0650(param_2[6]);

  return 0;

}
#pragma opt_common_subs on
#pragma pop

// FUN_00421330 NONMATCHING


u64 FUN_00421330(void)



{

  int *piVar1;

  u64 uVar2;

  long lVar3;

  int iVar4;

  int iVar5;

  

  uVar2 = kwlnTaskGetWorkData();

  piVar1 = (int *)uVar2;

  iVar5 = *(int *)(*piVar1 + 4);

  while (iVar5 != 0) {

    iVar4 = *(int *)(iVar5 + 0x14);

    iVar5 = *(int *)(iVar5 + 0x10);

    if (((*(u32 *)(iVar4 + 4) & 4) != 0) && (lVar3 = FUN_00420fe0(uVar2,(u32 *)iVar4), lVar3 != 0)) {

      if (piVar1[6] == iVar4) {

        piVar1[6] = 0;

      }

      FUN_003c49e0(*piVar1,*piVar1 + 4,*(u32 *)(iVar4 + 0x14));

    }

  }

  for (iVar5 = *(int *)(*piVar1 + 4); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x10)) {

    iVar4 = *(int *)(iVar5 + 0x14);

    if ((*(u32 *)(iVar4 + 4) & 4) == 0) goto LAB_004213f8;

  }

  iVar4 = 0;

LAB_004213f8:

  if ((iVar4 != 0) && (lVar3 = FUN_00420fe0(uVar2,(u32 *)iVar4), lVar3 != 0)) {

    if (piVar1[6] == iVar4) {

      piVar1[6] = 0;

    }

    FUN_003c49e0(*piVar1,*piVar1 + 4,*(u32 *)(iVar4 + 0x14));

  }

  return 0;

}

// FUN_00421460 NONMATCHING


u64 FUN_00421460(void)



{

  u64 uVar1;

  int iVar2;

  

  uVar1 = kwlnTaskGetWorkData();

  for (iVar2 = *(int *)(*(int *)uVar1 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {

    if ((*(u32 *)(*(int *)(iVar2 + 0x14) + 4) & 1) != 0) {

      FUN_003e0680(*(u32 *)(*(int *)(iVar2 + 0x14) + 0x18),0x420da0,uVar1);

    }

  }

  return 0;

}

// FUN_004214E0


u32 FUN_004214e0(u64 param_1,int param_2)



{

  int *piVar1;

  u32 uVar2;

  int iVar3;

  

  iVar3 = FUN_003c44d0(0x28,0,(void *)FUN_00420f60,0);

  piVar1 = *(int **)(iVar3 + 0x24);

  *piVar1 = iVar3;

  iVar3 = FUN_003dfeb0(piVar1);

  piVar1[5] = iVar3;

  piVar1[3] = param_2;

  uVar2 = kwlnTaskCreate(param_1,D_006B4380,10,(void *)FUN_00421330,(void *)FUN_00420f90,piVar1);

  iVar3 = kwlnTaskCreate(uVar2,D_006B4390,0x1cc9,(void *)FUN_00421460,0,piVar1);

  piVar1[4] = iVar3;

  return;

}

// FUN_004215B0 NONMATCHING


void FUN_004215b0(u64 param_1,u32 param_2)



{

  u32 *puVar1;

  int *piVar2;

  int iVar3;

  u32 uVar4;

  

  piVar2 = (int *)kwlnTaskGetWorkData();

  if (piVar2[6] != 0) {

  }

  iVar3 = FUN_003c4910(*piVar2,*(u16 *)(*piVar2 + 0x10) + 1,0x1c);

  puVar1 = *(u32 **)(iVar3 + 0x14);

  puVar1[5] = iVar3;

  *puVar1 = param_2;

  uVar4 = FUN_003dfeb0(puVar1);

  puVar1[6] = uVar4;

  puVar1[2] = 0;

  puVar1[3] = 0;

  piVar2[6] = (int)puVar1;

  return;

}

// FUN_00421650 NONMATCHING


void FUN_00421650(u32 param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  piVar1 = (int *)kwlnTaskGetWorkData();

  for (iVar2 = *(int *)(*piVar1 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {

    iVar3 = *(int *)(iVar2 + 0x14);

    if ((*(u32 *)(iVar3 + 4) & 4) == 0) goto LAB_004216a0;

  }

  iVar3 = 0;

LAB_004216a0:

  if ((iVar3 != 0) && ((*(u32 *)(iVar3 + 4) & 4) == 0)) {

    FUN_00420520((u32 *)iVar3,0,1);

    FUN_00420520((u32 *)iVar3,1,1);

    *(u32 *)(iVar3 + 4) = *(u32 *)(iVar3 + 4) | 4;

  }

  return;

}

// FUN_00421700
int FUN_00421700(void)
{
    u32* work;
    u32* node;

    work = (u32*)kwlnTaskGetWorkData();
    node = *(u32**)((u8*)work + 0x18);
    if (node != NULL)
    {
        if ((node[1] & 4) != 0)
        {
            return node[4] + 1;
        }
        return 0;

    }
    return 1;
}
// FUN_00421760


u8 * FUN_00421760(void)



{

  return (u8 *)&gp0xffffb9b4;

}

// FUN_00421770 NONMATCHING


u64 FUN_00421770(u64 param_1)



{

  u32 *puVar1;

  u32 uVar2;

  char cVar3;

  u8 uVar4;

  u16 uVar5;

  u32 uVar6;

  u32 *puVar7;

  u64 uVar8;

  long lVar9;

  int iVar10;

  u32 *puVar11;

  u32 auStack_40 [16];

  

  puVar1 = *(u32 **)((int)param_1 + 0x3c);

  switch(*puVar1) {

  case 0:

    uVar6 = H_Cdvd_Request(0x6b43a0,0);

    puVar1[0x18] = uVar6;

    *puVar1 = 1;

    break;

  case 1:

    lVar9 = H_Cdvd_IsFileLoaded(puVar1[0x18]);

    if (lVar9 == 0) {

      return 0;

    }

    uVar6 = H_Cdvd_Request(0x6b43b8,1);

    puVar1[0x1c] = uVar6;

    *puVar1 = 2;

  case 2:

    lVar9 = H_Cdvd_IsFileLoaded(puVar1[0x1c]);

    if (lVar9 != 0) {

      uVar6 = (*DAT_00960184)(1,*(u16 *)((void *)((int)puVar1[0x18] + 0x118)),0x40000);

      puVar1[0x1a] = uVar6;

      puVar1[0x19] = *(u32 *)(puVar1[0x18] + 0x118);

      memcpy((void *)puVar1[0x1a],(void *)*(u32 *)(puVar1[0x18] + 0x110),
                   *(u16 *)((void *)((int)puVar1[0x18] + 0x118)));

      uVar6 = scrCreateTaskFromScriptMemory(10,puVar1[0x1a],puVar1[0x19],0);

      puVar1[0x17] = uVar6;

      if (puVar1[0x18] != 0) {

        H_Cdvd_Destroy();

        puVar1[0x18] = 0;

      }

      *puVar1 = 3;

    }

    break;

  case 3:

    lVar9 = kwlnTaskExists(puVar1[0x17]);

    if (lVar9 == 0) {

      *puVar1 = 4;

    }

    break;

  case 4:

    MT_Scene_Load(1,1);

    uVar5 = FUN_001b6eb0(1,1);

    FUN_003b5980(uVar5);

    *puVar1 = 5;

  case 5:

    lVar9 = MT_Scene_TryLoadFinish();

    if (lVar9 == 1) {

      *puVar1 = 6;

    }

    break;

  case 6:

    puVar7 = (u32 *)func_001a1150();

    puVar11 = auStack_40;

    iVar10 = 8;

    do {

      uVar6 = *puVar7;

      uVar2 = puVar7[1];

      puVar7 = puVar7 + 2;

      iVar10 = iVar10 + -1;

      *puVar11 = uVar6;

      puVar11[1] = uVar2;

      puVar11 = puVar11 + 2;

    } while (0 < iVar10);

    uVar8 = kwlnGetMainCamera();

    uVar6 = func_001a1190();

    K_View_SetFov(uVar6,uVar8);

    iVar10 = kwlnGetMainCamera();

    FUN_004cb7f0(*(u32 *)(iVar10 + 4),auStack_40,0);

    lVar9 = clndIsDateInRange(4,5,0xc,0x1f);

    if (((lVar9 == 1) || (lVar9 = clndIsDateInRange(4,5,0xc,0x1f), lVar9 == 1)) ||

       (lVar9 = clndIsDateInRange(3,1,3,5), lVar9 == 1)) {

      H_Snd_PlayBgm(0x19,1);

    }

    else {

      lVar9 = clndIsDateInRange(1,1,2,0x1c);

      if (lVar9 == 1) {

        H_Snd_PlayBgm(0x50);

      }

    }

    *puVar1 = 7;

  case 7:

    if (puVar1[0x24] != 0) {

      puVar1[0x24] = 0;

    }

    uVar6 = FUN_00425c60(param_1,*(u8 *)(puVar1 + 0xf));

    puVar1[0x24] = uVar6;

    if (puVar1[0x10] != 0) {

      puVar1[0x10] = 0;

    }

    uVar6 = FUN_004238b0(param_1,*puGpffffb9b8,puGpffffb9b8[1],puGpffffb9b8[2],puGpffffb9b8[3],

                         puGpffffb9b8[4],puGpffffb9b8[5],*(u8 *)(puVar1 + 0xf));

    puVar1[0x10] = uVar6;

    *puVar1 = 8;

    break;

  case 8:

    uVar8 = FUN_00423b50(puVar1[0x10]);

    FUN_00426040(puVar1[0x24],uVar8);

    cVar3 = FUN_00426070(puVar1[0x24]);

    if ((cVar3 != '\x01') && (lVar9 = FUN_00423bf0(puVar1[0x10]), lVar9 != 0)) {

      if (puVar1[0x1c] != 0) {

        H_Cdvd_Destroy();

        puVar1[0x1c] = 0;

      }

      H_Fade_FadeIn();

      *puVar1 = 9;

    }

    break;

  case 9:

    lVar9 = H_Fade_IsFadeOutDone();

    if (lVar9 != 0) {

      if (puGpffffb9b8[9] == '\x01') {

      }

      *puVar1 = 10;

    }

    break;

  case 10:

    uVar8 = FUN_00423b50(puVar1[0x10]);

    FUN_00426040(puVar1[0x24],uVar8);

    cVar3 = FUN_00423b70(puVar1[0x10]);

    if (cVar3 == '\x01') {

      FUN_00426050(puVar1[0x24]);

      cVar3 = FUN_00423b50(puVar1[0x10]);

      uVar6 = scrCreateTaskFromScriptMemory(10,puVar1[0x1a],puVar1[0x19],cVar3 + 1);

      puVar1[0x17] = uVar6;

      uVar8 = FUN_00423b50(puVar1[0x10]);

      FUN_00425d30(puVar1[0x24],*(u8 *)(puVar1 + 0xf),uVar8);

      *puVar1 = 0xb;

    }

    break;

  case 0xb:

    *puVar1 = 0xc;

  case 0xc:

    lVar9 = kwlnTaskExists(puVar1[0x17]);

    if (lVar9 == 0) {

      uVar4 = FUN_00423b50(puVar1[0x10]);

      *(u8 *)(puVar1 + 0xf) = uVar4;

      FUN_00425d10(puVar1[0x24],uVar4);

      *puVar1 = 10;

      if (cGpffffb9c0 == '\x01') {

        *puVar1 = 0xe;

        lVar9 = kwlnTaskExists(puVar1[0x10]);

        if (lVar9 == 1) {

          kwlnTaskDestroyWithHierarchy(puVar1[0x10]);

        }

        puVar7 = (u32 *)FUN_00426090();

        lVar9 = kwlnTaskExists(*puVar7);

        if (lVar9 == 1) {

          puVar7 = (u32 *)FUN_00426090();

          kwlnTaskDestroyWithHierarchy(*puVar7);

        }

        lVar9 = kwlnTaskExists(puVar1[0x24]);

        if (lVar9 == 1) {

          kwlnTaskDestroyWithHierarchy(puVar1[0x24]);

        }

      }

      else {

      }

    }

    break;

  case 0xe:

    *puVar1 = 0xf;

  }

  return 0;

}

// FUN_00421D70
void FUN_00421d70(int param_1)
{
  int *piVar1;
  code *fn;

  piVar1 = *(int **)(param_1 + 0x3c);
  FUN_00421fb0();
  MT_Scene_Destroy();
  fn = (code *)&DAT_0096017c_abs;
  (*fn)(*(u32 *)((u8 *)piVar1 + 0x68));
  (*fn)(*(u32 *)(param_1 + 0x3c));
}

// FUN_00421DE0 NONMATCHING


u64

FUN_00421de0(u8 param_1,u8 param_2,u8 param_3,u8 param_4,

            u8 param_5)



{

  long lVar1;

  u64 uVar2;

  u32 *puVar3;

  

  memset(&uGpffffb9b4,0,4);

  lVar1 = (*DAT_00960184)(1,0x9c,0x40000);

  if (lVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = kwlnTaskCreateWithAutoPriority(0,0x106f,0x6b43c8,0x421770,0x421d70,lVar1);

    puVar3 = (u32 *)lVar1;

    *puVar3 = 0;

    *(u8 *)(puVar3 + 4) = 1;

    *(u8 *)(puVar3 + 0xe) = param_2;

    *(u8 *)((int)puVar3 + 0x39) = param_3;

    *(u8 *)((int)puVar3 + 0x3a) = param_4;

    *(u8 *)((int)puVar3 + 0x3b) = param_5;

    *(u8 *)(puVar3 + 0xf) = param_1;

    *(u8 *)((int)puVar3 + 0x11) = 6;

    if (*(char *)((int)puVar3 + 0x3b) == '\x02') {

      *(u8 *)((int)puVar3 + 0x11) = 2;

    }

    uGpffffb9b4 = (u32)uVar2;

  }

  return uVar2;

}

// FUN_00421EF0


bool FUN_00421ef0(int param_1)



{

  return **(int **)(param_1 + 0x3c) == 0xf;

}

// FUN_00421F10


u32 FUN_00421f10(int param_1)



{

  return *(u32 *)(*(int *)(param_1 + 0x3c) + 0x70);

}

// FUN_00421F20 NONMATCHING


void FUN_00421f20(void)



{

  puGpffffb9b8 = (u32 *)((u8 *)(*DAT_00960184)(1,0xb,0x40000));

  *puGpffffb9b8 = 0;

  puGpffffb9b8[1] = 0;

  puGpffffb9b8[2] = 0;

  puGpffffb9b8[3] = 0;

  puGpffffb9b8[4] = 0;

  puGpffffb9b8[5] = 0;

  puGpffffb9b8[7] = 0;

  puGpffffb9b8[8] = 0;

  puGpffffb9b8[9] = 0;

  puGpffffb9b8[10] = 0;

  return;

}

// FUN_00421FB0


void FUN_00421fb0(void)



{

  (*(void (**)(...))0x0096017c)(uGpffffb9b8);

  uGpffffb9b8 = 0;

  return;

}

// FUN_00421FE0 NONMATCHING


float FUN_00421fe0(char param_1,int param_2,int param_3,int param_4,short param_5)



{

  short sVar1;

  short sVar2;

  float fVar3;

  

  if ((short)param_4 == param_5) {

    fVar3 = (float)param_3;

  }

  else {

    sVar2 = (short)param_3;

    sVar1 = (short)param_2;

    if (param_1 == '\x02') {

      fVar3 = (float)cosf((float)param_4 * (fGpffff8248 / (float)((int)param_5 << 1)));

      fVar3 = ((float)param_3 + 0.0) - (float)((int)sVar2 - (int)sVar1) * fVar3;

    }

    else if (param_1 == '\x01') {

      fVar3 = (float)sinf((float)param_4 * (fGpffff8248 / (float)((int)param_5 << 1)));

      fVar3 = (float)((int)sVar2 - (int)sVar1) * fVar3 + (float)param_2 + 0.0;

    }

    else if (param_1 == '\0') {

      fVar3 = (float)((int)sVar1 + ((int)(short)param_4 * ((int)sVar2 - (int)sVar1)) / (int)param_5)

      ;

    }

    else {

      fVar3 = -1.0;

    }

  }

  return fVar3;

}

// FUN_004221A0 NONMATCHING


float FUN_004221a0(float param_1,float param_2,float param_3,float param_4,char param_5)



{

  float fVar1;

  

  if (param_3 != param_4) {

    if (param_5 == '\x02') {

      fVar1 = (float)cosf((fGpffff8248 / (param_4 * 2.0)) * param_3);

      param_2 = (param_2 + 0.0) - (param_2 - param_1) * fVar1;

    }

    else if (param_5 == '\x01') {

      fVar1 = (float)sinf((fGpffff8248 / (param_4 * 2.0)) * param_3);

      param_2 = (param_2 - param_1) * fVar1 + param_1 + 0.0;

    }

    else if (param_5 == '\0') {

      param_2 = param_1 + (param_3 * (param_2 - param_1)) / param_4;

    }

    else {

      param_2 = -1.0;

    }

  }

  return param_2;

}

// FUN_004222D0 NONMATCHING


void FUN_004222d0(float *param_1,char param_2,int param_3,int param_4,int param_5,int param_6,

                 int param_7,short param_8)



{

  short sVar1;

  short sVar2;

  int iVar3;

  short sVar4;

  float fVar5;

  float fVar6;

  

  sVar4 = (short)param_7;

  iVar3 = (int)param_8;

  if (sVar4 == param_8) {

    fVar5 = (float)param_4;

  }

  else {

    sVar2 = (short)param_4;

    sVar1 = (short)param_3;

    if (param_2 == '\x02') {

      fVar5 = (float)cosf((float)param_7 * (fGpffff8248 / (float)(iVar3 << 1)));

      fVar5 = ((float)param_4 + 0.0) - (float)((int)sVar2 - (int)sVar1) * fVar5;

    }

    else if (param_2 == '\x01') {

      fVar5 = (float)sinf((float)param_7 * (fGpffff8248 / (float)(iVar3 << 1)));

      fVar5 = (float)((int)sVar2 - (int)sVar1) * fVar5 + (float)param_3 + 0.0;

    }

    else if (param_2 == '\0') {

      fVar5 = (float)((int)sVar1 + ((int)sVar4 * ((int)sVar2 - (int)sVar1)) / iVar3);

    }

    else {

      fVar5 = -1.0;

    }

  }

  if (sVar4 == param_8) {

    fVar6 = (float)param_6;

  }

  else {

    sVar2 = (short)param_6;

    sVar1 = (short)param_5;

    if (param_2 == '\x02') {

      fVar6 = (float)cosf((float)param_7 * (fGpffff8248 / (float)(iVar3 << 1)));

      fVar6 = ((float)param_6 + 0.0) - (float)((int)sVar2 - (int)sVar1) * fVar6;

    }

    else if (param_2 == '\x01') {

      fVar6 = (float)sinf((float)param_7 * (fGpffff8248 / (float)(iVar3 << 1)));

      fVar6 = (float)((int)sVar2 - (int)sVar1) * fVar6 + (float)param_5 + 0.0;

    }

    else if (param_2 == '\0') {

      fVar6 = (float)((int)sVar1 + ((int)sVar4 * ((int)sVar2 - (int)sVar1)) / iVar3);

    }

    else {

      fVar6 = -1.0;

    }

  }

  *param_1 = fVar5;

  param_1[1] = fVar6;

  return;

}

// FUN_00422670 NONMATCHING


u32 FUN_00422670(int param_1)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  u32 uVar4;

  float fVar5;

  

  pcVar2 = *(char **)(param_1 + 0x3c);

  (*DAT_00960090)(6,1);

  (*DAT_00960090)(7,2);

  (*DAT_00960090)(8,1);

  (*DAT_00960090)(10,5);

  (*DAT_00960090)(0xb,6);

  (*DAT_00960090)(9,2);

  (*DAT_00960090)(0xc,1);

  (*DAT_00960090)(1,0);

  if (pcVar2[0x13e] == '\x01') {

    uVar4 = 0;

  }

  else {

    cVar1 = *pcVar2;

    if (cVar1 == '\x02') {

      uVar4 = 0xffffffff;

    }

    else {

      if ((cVar1 == '\x01') || (cVar1 == '\0')) {

        iVar3 = kwlnGetMainCamera();

        fVar5 = *(float *)(iVar3 + 0x80);

        for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

          *(float *)(pcVar2 + iVar3 * 0x40 + 0x18) = (u32)DAT_00960088 - *(float *)(pcVar2 + 0x130);

          *(float *)(pcVar2 + iVar3 * 0x40 + 0x28) = 1.0 / fVar5;

          *(float *)(pcVar2 + iVar3 * 0x40 + 0x30) = (float)(u8)pcVar2[iVar3 * 4 + 0x110];

          *(float *)(pcVar2 + iVar3 * 0x40 + 0x34) = (float)(u8)pcVar2[iVar3 * 4 + 0x111];

          *(float *)(pcVar2 + iVar3 * 0x40 + 0x38) = (float)(u8)pcVar2[iVar3 * 4 + 0x112];

          *(float *)(pcVar2 + iVar3 * 0x40 + 0x3c) = (float)(u8)pcVar2[iVar3 * 4 + 0x113];

        }

        *(u32 *)(pcVar2 + 0x10) = *(u32 *)(pcVar2 + 0x134);

        *(u32 *)(pcVar2 + 0x14) = *(u32 *)(pcVar2 + 0x138);

        *(float *)(pcVar2 + 0x50) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128);

        *(u32 *)(pcVar2 + 0x54) = *(u32 *)(pcVar2 + 0x138);

        *(u32 *)(pcVar2 + 0x90) = *(u32 *)(pcVar2 + 0x134);

        *(float *)(pcVar2 + 0x94) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);

        *(float *)(pcVar2 + 0xd0) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128);

        *(float *)(pcVar2 + 0xd4) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);

        (*DAT_009600a0)(4,pcVar2 + 0x10,4);

        *pcVar2 = '\x01';

      }

      uVar4 = 0;

    }

  }

  return uVar4;

}

// FUN_004229A0


void FUN_004229a0(int param_1)



{

  (*(void (**)(u32))0x0096017c)(*(u32 *)(param_1 + 0x3c));

  return;

}

// FUN_004229D0 NONMATCHING


u64 FUN_004229d0(u64 param_1,u64 param_2,char param_3)



{

  u32 uVar1;

  int iVar2;

  long lVar3;

  short sVar4;

  u8 *puVar5;

  u64 uVar6;

  u32 uStack_8;

  u32 uStack_4;

  

  uStack_4 = (u32)((u32)param_2 >> 0x20);

  uVar6 = 0;

  lVar3 = (*DAT_00960184)(1,0x140,0x40000);

  if (lVar3 == 0) {

    uVar6 = 0;

  }

  else {

    if (param_3 == '\x03') {

      uVar6 = kwlnTaskCreate(param_1,0x6b43d8,0x18a6,0x422670,0x4229a0,lVar3);

    }

    else if (param_3 == '\x02') {

      uVar6 = kwlnTaskCreate(param_1,0x6b43d8,0x18a7,0x422670,0x4229a0,lVar3);

    }

    else if (param_3 == '\x01') {

      uVar6 = kwlnTaskCreate(param_1,0x6b43d8,0x1065,0x422670,0x4229a0,lVar3);

    }

    else if (param_3 == '\0') {

      uVar6 = kwlnTaskCreateWithAutoPriority(param_1,0x106f,0x6b43d8,0x422670,0x4229a0,lVar3);

    }

    puVar5 = (u8 *)lVar3;

    *puVar5 = 0;

    for (sVar4 = 0; sVar4 < 4; sVar4 = sVar4 + 1) {

      puVar5[sVar4 * 4 + 0x111] = 0xff;

      puVar5[sVar4 * 4 + 0x112] = 0xff;

      puVar5[sVar4 * 4 + 0x110] = 0xff;

      puVar5[sVar4 * 4 + 0x113] = 0x80;

    }

    *(u32 *)(puVar5 + 0x130) = 0x3f800000;

    uVar1 = FUN_003b35c0(1);

    *(u32 *)(puVar5 + 300) = uVar1;

    iVar2 = FUN_003b35c0(1);

    *(int *)(puVar5 + 0x128) = iVar2 << 3;

    uStack_8 = (u32)param_2;

    *(u32 *)(puVar5 + 0x134) = uStack_8;

    *(u32 *)(puVar5 + 0x138) = uStack_4;

    *(u16 *)(puVar5 + 0x13c) = 0;

    puVar5[0x13e] = 0;

  }

  return uVar6;

}

// FUN_00422C10


void FUN_00422c10(int param_1,int param_2)



{

  *(float *)(*(int *)(param_1 + 0x3c) + 0x130) = (float)param_2;

  return;

}

// FUN_00422C30


void FUN_00422c30(int param_1,u64 param_2,int param_3)
{
  typedef struct McVec4 {
    float f0;
    float f1;
    float f2;
    float f3;
  } McVec4;
  typedef struct McScratch {
    u64 pair;
    McVec4 vec;
  } McScratch;
  typedef struct McFrame {
    u64 pad;
    McScratch scratch;
  } McFrame;
  McFrame frame;
  int *work;

  frame.scratch.pair = param_2;
  frame.scratch.vec = *(McVec4 *)param_3;
  work = *(int **)(param_1 + 0x3c);
  *(float *)((u8 *)work + 0x134) = *(float *)((u8 *)&frame.scratch + 0);
  *(float *)((u8 *)work + 0x138) = *(float *)((u8 *)&frame.scratch + 4);
  *(u32 *)((u8 *)work + 0x12c) = ((u32 *)&frame.scratch.vec)[3];
  *(u32 *)((u8 *)work + 0x128) = ((u32 *)&frame.scratch.vec)[2];
}

// FUN_00422C90


void FUN_00422c90(int param_1,u8 param_2,u8 param_3,u8 param_4,

                 u8 param_5)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

    iVar2 = iVar1 + iVar3 * 4;

    *(u8 *)(iVar2 + 0x110) = param_2;

    *(u8 *)(iVar2 + 0x111) = param_3;

    *(u8 *)(iVar2 + 0x112) = param_4;

    *(u8 *)(iVar2 + 0x113) = param_5;

  }

  return;

}

// FUN_00422CD0


void FUN_00422cd0(int param_1,u8 param_2)



{

  *(u8 *)(*(int *)(param_1 + 0x3c) + 0x13e) = param_2;

  return;

}

// FUN_00422CE0 NONMATCHING


u32 FUN_00422ce0(u64 param_1)



{

  u16 uVar1;

  u8 *puVar2;

  bool bVar3;

  short sVar4;

  u32 *puVar5;

  int iVar6;

  u64 uVar7;

  int iVar8;

  int iVar9;

  long lVar10;

  u16 uVar11;

  float fVar12;

  float fVar13;

  u32 uVar14;

  u32 uVar15;

  u8 auStack_4 [4];

  

  puVar2 = *(u8 **)((int)param_1 + 0x3c);

  switch(*puVar2) {

  case 0:

    puVar5 = (u32 *)FUN_00421760();

    uVar7 = FUN_00421f10(*puVar5);

    uVar7 = H_Cdvd_ArchiveGetFile(uVar7,0xc,auStack_4);

    uVar14 = func_00112420(uVar7);

    *(u32 *)(puVar2 + 200) = uVar14;

    *puVar2 = 1;

  case 1:

    lVar10 = H_Maestro_00111f30(*(u32 *)(puVar2 + 200));

    if (lVar10 == 1) {

      for (iVar8 = 0; iVar8 < 0x18; iVar8 = iVar8 + 1) {

        if (iVar8 == 5) {

          for (iVar9 = 0; iVar9 < 6; iVar9 = iVar9 + 1) {

            iVar6 = FUN_001158b0(0,*(u32 *)(puVar2 + 200),6);

            *(int *)(puVar2 + iVar9 * 4 + 0x130) = iVar6;

            *(u8 *)(iVar6 + 0x18) = 0xff;

          }

        }

        else if (iVar8 == 6) {

          for (iVar9 = 0; iVar9 < 6; iVar9 = iVar9 + 1) {

            iVar6 = FUN_001158b0(0,*(u32 *)(puVar2 + 200),7);

            *(int *)(puVar2 + iVar9 * 4 + 0x148) = iVar6;

            *(u8 *)(iVar6 + 0x18) = 0xff;

          }

        }

        else if (iVar8 != 0x17) {

          iVar9 = FUN_001158b0(0,*(u32 *)(puVar2 + 200));

          *(int *)(puVar2 + iVar8 * 4 + 0xd0) = iVar9;

          *(u8 *)(iVar9 + 0x18) = 0xff;

        }

      }

      for (iVar8 = 0; iVar8 < 6; iVar8 = iVar8 + 1) {

        *(u32 *)(puVar2 + iVar8 * 8 + 0x18c) = 0xc35b0000;

        *(float *)(puVar2 + iVar8 * 8 + 400) = (float)(iVar8 * 0x21 + 0xe9);

      }

      uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 200),0x18);

      iVar8 = (int)uVar7;

      *(u32 *)(iVar8 + 0x10) = 0x42a20000;

      *(u32 *)(iVar8 + 0x14) = 0;

      *(u32 *)(iVar8 + 0x2c) = 0x41200000;

      *(u8 *)(iVar8 + 0x18) = 0;

      func_001127d0(uVar7,1);

      FUN_00115980(uVar7);

      *puVar2 = 2;

    }

    break;

  case 2:

    *(u16 *)(puVar2 + 0x160) = 0;

    *(u16 *)(puVar2 + 0x164) = 0;

    *(u16 *)(puVar2 + 0x162) = 0;

    for (iVar8 = 0; iVar8 < 6; iVar8 = iVar8 + 1) {

      *(u16 *)(puVar2 + iVar8 * 6 + 0x166) = 0;

      *(u16 *)(puVar2 + iVar8 * 6 + 0x16a) = 0;

      *(u16 *)(puVar2 + iVar8 * 6 + 0x168) = 0;

      puVar2[iVar8 + 0x1bc] = (char)(iVar8 << 2) + (char)iVar8;

    }

    uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 200),0x18);

    iVar8 = (int)uVar7;

    *(u32 *)(iVar8 + 0x10) = 0x42a20000;

    *(u32 *)(iVar8 + 0x14) = 0;

    *(u32 *)(iVar8 + 0x2c) = 0x41200000;

    *(u8 *)(iVar8 + 0x18) = 0;

    func_001127d0(uVar7,1);

    FUN_00115980(uVar7);

    *puVar2 = 3;

    break;

  case 3:

    uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 200),0x18);

    iVar8 = (int)uVar7;

    *(u32 *)(iVar8 + 0x10) = 0x42a20000;

    *(u32 *)(iVar8 + 0x14) = 0;

    *(u32 *)(iVar8 + 0x2c) = 0x41200000;

    *(u8 *)(iVar8 + 0x18) = 0;

    func_001127d0(uVar7,1);

    FUN_00115980(uVar7);

    if (puVar2[0x95] == '\0') {

      return 0;

    }

    *(u32 *)(*(int *)(puVar2 + 0xd0) + 0x10) = 0x43d50000;

    *(u32 *)(*(int *)(puVar2 + 0xd0) + 0x14) = 0x43cb0000;

    *(char *)(*(int *)(puVar2 + 0xd0) + 0x18) = -1 - (char)*(u16 *)(puVar2 + 0x164);

    if (*(short *)(puVar2 + 0x160) == (short)((char)puVar2[0x8e] * 5)) {

      fVar12 = 255.0;

    }

    else {

      fVar12 = (float)((*(short *)(puVar2 + 0x160) * 0xff) / (int)(short)((char)puVar2[0x8e] * 5));

    }

    if (fVar12 < 2.1474836e+09) {

      uVar11 = (u16)(int)fVar12;

    }

    else {

      uVar11 = (u16)(int)(fVar12 - 2.1474836e+09);

    }

    *(u16 *)(puVar2 + 0x164) = uVar11 & 0xff;

    bVar3 = (long)*(short *)(puVar2 + 0x160) < (long)((char)puVar2[0x8e] * 5);

    if (bVar3) {

      *(short *)(puVar2 + 0x160) = *(short *)(puVar2 + 0x160) + 1;

    }

    else {

      *(short *)(puVar2 + 0x160) = (short)((char)puVar2[0x8e] * 5);

    }

    lVar10 = 0;

    while (lVar10 < (char)puVar2[0x8e]) {

      iVar8 = (int)lVar10;

      if ((char)puVar2[iVar8 + 0x1bc] < '\x01') {

        uVar1 = *(u16 *)(puVar2 + iVar8 * 6 + 0x168);

        fVar12 = *(float *)(puVar2 + iVar8 * 8 + 400);

        uVar14 = FUN_00421fe0(1,0xffffffffffffff25,0x13,uVar1,0xf);

        uVar15 = FUN_00421fe0(1,(short)(int)fVar12,(short)(int)fVar12,uVar1,0xf);

        *(u32 *)(puVar2 + iVar8 * 8 + 0x18c) = uVar14;

        *(u32 *)(puVar2 + iVar8 * 8 + 400) = uVar15;

        sVar4 = *(short *)(puVar2 + iVar8 * 6 + 0x168);

        if (sVar4 < 0xf) {

          *(short *)(puVar2 + iVar8 * 6 + 0x168) = sVar4 + 1;

          bVar3 = true;

        }

      }

      else {

        puVar2[iVar8 + 0x1bc] = puVar2[iVar8 + 0x1bc] + -1;

        bVar3 = true;

      }

      lVar10 = (long)(iVar8 + 1);

    }

    if (!bVar3) {

      *puVar2 = 4;

      for (lVar10 = 0; lVar10 < (char)puVar2[0x8e]; lVar10 = (long)((int)lVar10 + 1)) {

        *(u32 *)(puVar2 + (int)lVar10 * 8 + 0x18c) = 0x41980000;

      }

      for (iVar8 = 0; iVar8 < 6; iVar8 = iVar8 + 1) {

        *(u16 *)(puVar2 + iVar8 * 6 + 0x166) = 0;

        *(u16 *)(puVar2 + iVar8 * 6 + 0x16a) = 0;

        *(u16 *)(puVar2 + iVar8 * 6 + 0x168) = 0;

      }

    }

    break;

  case 4:

    FUN_00423cd0(0);

    uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 200),0x18);

    iVar8 = (int)uVar7;

    *(u32 *)(iVar8 + 0x10) = 0x42a20000;

    *(u32 *)(iVar8 + 0x14) = 0;

    *(u32 *)(iVar8 + 0x2c) = 0x41200000;

    *(u8 *)(iVar8 + 0x18) = 0;

    func_001127d0(uVar7,1);

    FUN_00115980(uVar7);

    *puVar2 = 5;

    break;

  case 5:

    if (*(char *)(iGpffffb9b8 + 9) != '\x01') {

      if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {

        if (((DAT_007e0952 & 0x4000) == 0) && ((DAT_007e095a & 0x4000) == 0)) {

          if ((DAT_007e0952 & 0x40) != 0) {

            for (lVar10 = 0; lVar10 < (char)puVar2[0x8e]; lVar10 = (long)((int)lVar10 + 1)) {

              *(u16 *)(puVar2 + (int)lVar10 * 6 + 0x52) = 0;

            }

            *puVar2 = 6;

            func_0010a4e0(0,0,0,1);

          }

        }

        else {

          if ((long)(char)puVar2[0x96] < (long)((char)puVar2[0x8e] + -1)) {

            puVar2[0x96] = puVar2[0x96] + '\x01';

          }

          else {

            puVar2[0x96] = 0;

          }

          func_0010a4e0(0,0,0,0);

        }

      }

      else {

        if ((char)puVar2[0x96] < '\x01') {

          puVar2[0x96] = puVar2[0x8e] + -1;

        }

        else {

          puVar2[0x96] = puVar2[0x96] + -1;

        }

        func_0010a4e0(0,0,0,0);

      }

    }

    FUN_00423cd0(param_1);

    uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 200),0x18);

    iVar8 = (int)uVar7;

    *(u32 *)(iVar8 + 0x10) = 0x42a20000;

    *(u32 *)(iVar8 + 0x14) = 0;

    *(u32 *)(iVar8 + 0x2c) = 0x41200000;

    *(u8 *)(iVar8 + 0x18) = 0;

    func_001127d0(uVar7,1);

    FUN_00115980(uVar7);

    break;

  case 6:

    lVar10 = 0;

    while (lVar10 < (char)puVar2[0x8e]) {

      iVar8 = (int)lVar10;

      uVar1 = *(u16 *)(puVar2 + iVar8 * 6 + 0x168);

      fVar12 = *(float *)(puVar2 + (char)puVar2[0x96] * 8 + 400);

      fVar13 = *(float *)(puVar2 + iVar8 * 8 + 400);

      uVar14 = FUN_00421fe0(1,(short)(int)*(float *)(puVar2 + iVar8 * 8 + 0x18c),

                            (short)(int)*(float *)(puVar2 + iVar8 * 8 + 0x18c),uVar1,0xf);

      uVar15 = FUN_00421fe0(1,(short)(int)fVar13,(short)(int)fVar12,uVar1,0xf);

      *(u32 *)(puVar2 + iVar8 * 8 + 0x18c) = uVar14;

      *(u32 *)(puVar2 + iVar8 * 8 + 400) = uVar15;

      sVar4 = *(short *)(puVar2 + iVar8 * 6 + 0x168) + 1;

      *(short *)(puVar2 + iVar8 * 6 + 0x168) = sVar4;

      if (0xe < sVar4) {

        *(u32 *)(puVar2 + iVar8 * 8 + 400) =

             *(u32 *)(puVar2 + (char)puVar2[0x96] * 8 + 400);

      }

      lVar10 = (long)(iVar8 + 1);

    }

    if (10 < *(short *)(puVar2 + 0x168)) {

      for (lVar10 = 0; lVar10 < (char)puVar2[0x8e]; lVar10 = (long)((int)lVar10 + 1)) {

        *(u32 *)(puVar2 + (int)lVar10 * 8 + 400) =

             *(u32 *)(puVar2 + (char)puVar2[0x96] * 8 + 400);

      }

      for (iVar8 = 0; iVar8 < 6; iVar8 = iVar8 + 1) {

        *(u16 *)(puVar2 + iVar8 * 6 + 0x166) = 0;

        *(u16 *)(puVar2 + iVar8 * 6 + 0x16a) = 0;

        *(u16 *)(puVar2 + iVar8 * 6 + 0x168) = 0;

      }

      *puVar2 = 0xc;

    }

    FUN_00423cd0(param_1);

    uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 200),0x18);

    iVar8 = (int)uVar7;

    *(u32 *)(iVar8 + 0x10) = 0x42a20000;

    *(u32 *)(iVar8 + 0x14) = 0;

    *(u32 *)(iVar8 + 0x2c) = 0x41200000;

    *(u8 *)(iVar8 + 0x18) = 0;

    func_001127d0(uVar7,1);

    FUN_00115980(uVar7);

    break;

  case 0xc:

    FUN_00423cd0(0);

    uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 200),0x18);

    iVar8 = (int)uVar7;

    *(u32 *)(iVar8 + 0x10) = 0x42a20000;

    *(u32 *)(iVar8 + 0x14) = 0;

    *(u32 *)(iVar8 + 0x2c) = 0x41200000;

    *(u8 *)(iVar8 + 0x18) = 0;

    func_001127d0(uVar7,1);

    FUN_00115980(uVar7);

    break;

  case 0xd:

    return 0xffffffff;

  }

  return 0;

}

// FUN_00423790 NONMATCHING


void FUN_00423790(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  for (iVar2 = 0; iVar2 < 0x19; iVar2 = iVar2 + 1) {

    iVar3 = iVar1 + iVar2 * 4;

    if (*(int *)(iVar3 + 0xcc) != 0) {

      FUN_00115980();

      *(u32 *)(iVar3 + 0xcc) = 0;

    }

  }

  for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {

    iVar3 = iVar1 + iVar2 * 4;

    if (*(int *)(iVar3 + 0x130) != 0) {

      FUN_00115980();

      *(u32 *)(iVar3 + 0x130) = 0;

    }

    if (*(int *)(iVar3 + 0x148) != 0) {

      FUN_00115980();

      *(u32 *)(iVar1 + iVar2 * 4 + 0x148) = 0;

    }

  }

  if (*(int *)(iVar1 + 200) != 0) {

    func_001124b0();

    *(u32 *)(iVar1 + 200) = 0;

  }

  (*DAT_0096017c)(*(u32 *)(param_1 + 0x3c));

  return;

}

// FUN_004238B0 NONMATCHING


u64

FUN_004238b0(u64 param_1,char param_2,char param_3,char param_4,char param_5,char param_6,

            char param_7,char param_8)



{

  long lVar1;

  u64 uVar2;

  short sVar3;

  u8 *puVar4;

  

  lVar1 = (*DAT_00960184)(1,0x1c4,0x40000);

  if (lVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = kwlnTaskCreateWithAutoPriority(param_1,0x106f,0x6b43f0,0x422ce0,0x423790,lVar1);

    puVar4 = (u8 *)lVar1;

    *puVar4 = 0;

    puVar4[0x96] = 0;

    for (sVar3 = 0; sVar3 < 6; sVar3 = sVar3 + 1) {

      *(u32 *)(puVar4 + sVar3 * 4 + 0x74) = 0xffffffff;

    }

    *(u16 *)(puVar4 + 0x8c) = 0;

    puVar4[0xc4] = 0;

    puVar4[0x95] = 0;

    puVar4[0x8e] = 0;

    if (param_2 == '\x01') {

      puVar4[(char)puVar4[0x8e] + 0x8f] = 0;

      puVar4[0x8e] = puVar4[0x8e] + '\x01';

    }

    if (param_3 == '\x01') {

      puVar4[(char)puVar4[0x8e] + 0x8f] = 1;

      puVar4[0x8e] = puVar4[0x8e] + '\x01';

    }

    if (param_4 == '\x01') {

      puVar4[(char)puVar4[0x8e] + 0x8f] = 2;

      puVar4[0x8e] = puVar4[0x8e] + '\x01';

    }

    if (param_5 == '\x01') {

      puVar4[(char)puVar4[0x8e] + 0x8f] = 3;

      puVar4[0x8e] = puVar4[0x8e] + '\x01';

    }

    if (param_6 == '\x01') {

      puVar4[(char)puVar4[0x8e] + 0x8f] = 4;

      puVar4[0x8e] = puVar4[0x8e] + '\x01';

    }

    if (param_7 == '\x01') {

      puVar4[(char)puVar4[0x8e] + 0x8f] = 5;

      puVar4[0x8e] = puVar4[0x8e] + '\x01';

    }

    for (sVar3 = 0; (long)sVar3 < (long)(char)puVar4[0x8e]; sVar3 = sVar3 + 1) {

      if (puVar4[sVar3 + 0x8f] == param_8) {

        puVar4[0x96] = (char)sVar3;

        sVar3 = (short)(char)puVar4[0x8e];

      }

    }

  }

  return uVar2;

}


// FUN_00423B50

char FUN_00423b50(int param_1)



{

  return *(u8 *)

          ((int)*(char *)(*(int *)(param_1 + 0x3c) + 0x96) + *(int *)(param_1 + 0x3c) + 0x8f);

}

// FUN_00423B70
bool FUN_00423b70(int param_1)
{
  char value;

  value = **(char **)(param_1 + 0x3c);
  if (value == 6) {
    return true;
  }
  return value == 0xc;
}

// FUN_00423BA0
void FUN_00423ba0(int param_1)
{
  u8 *puVar1;
  int i;

  puVar1 = *(u8 **)(param_1 + 0x3c);
  for (i = 0; i < (char)puVar1[0x8e]; i++) {
    *(u16 *)(puVar1 + i * 6 + 0x52) = 0;
  }
  *puVar1 = 10;
}

// FUN_00423BF0
int FUN_00423bf0(int param_1)
{
  return **(char**)(param_1 + 0x3c) > 1;
}

// FUN_00423C10 NONMATCHING


void FUN_00423c10(int param_1,char param_2)



{

  u8 *puVar1;

  bool bVar2;

  long lVar3;

  

  puVar1 = *(u8 **)(param_1 + 0x3c);

  bVar2 = false;

  for (lVar3 = 0; lVar3 < (char)puVar1[0x8e]; lVar3 = (long)((int)lVar3 + 1)) {

    if (puVar1[(int)lVar3 + 0x8f] == param_2) {

      puVar1[0x96] = (char)lVar3;

      lVar3 = (long)(char)puVar1[0x8e];

      bVar2 = true;

    }

  }

  if (bVar2) {

    for (lVar3 = 0; lVar3 < (char)puVar1[0x8e]; lVar3 = (long)((int)lVar3 + 1)) {

      *(u16 *)(puVar1 + (int)lVar3 * 6 + 0x52) = 0;

    }

    *puVar1 = 6;

    *(u8 *)(iGpffffb9b8 + 7) = 1;

  }

  return;

}

// FUN_00423CD0 NONMATCHING


void FUN_00423cd0(int param_1)



{

  int iVar1;

  int iVar2;

  long lVar3;

  int iVar4;

  int iVar5;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  lVar3 = 0;

  while (lVar3 < *(char *)(iVar1 + 0x8e)) {

    iVar2 = (int)lVar3;

    if (lVar3 == *(char *)(iVar1 + 0x96)) {

      iVar5 = iVar1 + (*(char *)(iVar1 + iVar2 + 0x8f) * 2 + 0xc) * 4;

      *(u8 *)(*(int *)(iVar5 + 0xcc) + 0x18) = 0;

      *(u32 *)(*(int *)(iVar5 + 0xcc) + 0x2c) = 0x41200000;

      iVar4 = iVar1 + iVar2 * 8;

      *(float *)(*(int *)(iVar5 + 0xcc) + 0x10) = *(float *)(iVar4 + 0x18c) + 13.0;

      *(float *)(*(int *)(iVar5 + 0xcc) + 0x14) = *(float *)(iVar4 + 400) + 3.0;

      iVar5 = iVar1 + (*(char *)(iVar1 + iVar2 + 0x8f) * 2 + 0xb) * 4;

      *(u8 *)(*(int *)(iVar5 + 0xcc) + 0x18) = 0xff;

      *(u32 *)(*(int *)(iVar5 + 0xcc) + 0x2c) = 0x41200000;

      *(float *)(*(int *)(iVar5 + 0xcc) + 0x10) = *(float *)(iVar4 + 0x18c) + 13.0;

      *(float *)(*(int *)(iVar5 + 0xcc) + 0x14) = *(float *)(iVar4 + 400) + 3.0;

      *(u8 *)(*(int *)(iVar1 + 0xec) + 0x18) = 0;

      *(u32 *)(*(int *)(iVar1 + 0xec) + 0x2c) = 0x41300000;

      *(u32 *)(*(int *)(iVar1 + 0xec) + 0x10) = *(u32 *)(iVar4 + 0x18c);

      *(u32 *)(*(int *)(iVar1 + 0xec) + 0x14) = *(u32 *)(iVar4 + 400);

      *(u8 *)(*(int *)(iVar1 + 0xf0) + 0x18) = 0;

      *(u32 *)(*(int *)(iVar1 + 0xf0) + 0x2c) = 0x41300000;

      *(float *)(*(int *)(iVar1 + 0xf0) + 0x10) = *(float *)(iVar4 + 0x18c) + 181.0;

      *(u32 *)(*(int *)(iVar1 + 0xf0) + 0x14) = *(u32 *)(iVar4 + 400);

      *(u8 *)(*(int *)(iVar1 + 0xdc) + 0x18) = 0;

      *(u32 *)(*(int *)(iVar1 + 0xdc) + 0x2c) = 0x41300000;

      *(float *)(*(int *)(iVar1 + 0xdc) + 0x10) = *(float *)(iVar4 + 0x18c) + 4.0;

      *(float *)(*(int *)(iVar1 + 0xdc) + 0x14) = *(float *)(iVar4 + 400) + 19.0;

      *(u8 *)(*(int *)(iVar1 + 0xe0) + 0x18) = 0;

      *(u32 *)(*(int *)(iVar1 + 0xe0) + 0x2c) = 0x41300000;

      *(float *)(*(int *)(iVar1 + 0xe0) + 0x10) = *(float *)(iVar4 + 0x18c) + 183.0;

      *(float *)(*(int *)(iVar1 + 0xe0) + 0x14) = *(float *)(iVar4 + 400) + 19.0;

    }

    else {

      iVar4 = iVar1 + (*(char *)(iVar1 + iVar2 + 0x8f) * 2 + 0xb) * 4;

      *(u8 *)(*(int *)(iVar4 + 0xcc) + 0x18) = 0;

      *(u32 *)(*(int *)(iVar4 + 0xcc) + 0x2c) = 0x41400000;

      iVar5 = iVar1 + iVar2 * 8;

      *(float *)(*(int *)(iVar4 + 0xcc) + 0x10) = *(float *)(iVar5 + 0x18c) + 13.0;

      *(float *)(*(int *)(iVar4 + 0xcc) + 0x14) = *(float *)(iVar5 + 400) + 3.0;

      iVar4 = iVar1 + (*(char *)(iVar1 + iVar2 + 0x8f) * 2 + 0xc) * 4;

      *(u8 *)(*(int *)(iVar4 + 0xcc) + 0x18) = 0xff;

      *(u32 *)(*(int *)(iVar4 + 0xcc) + 0x2c) = 0x41400000;

      *(float *)(*(int *)(iVar4 + 0xcc) + 0x10) = *(float *)(iVar5 + 0x18c) + 13.0;

      *(float *)(*(int *)(iVar4 + 0xcc) + 0x14) = *(float *)(iVar5 + 400) + 3.0;

    }

    iVar5 = iVar1 + iVar2 * 4;

    *(u8 *)(*(int *)(iVar5 + 0x130) + 0x18) = 0;

    *(u32 *)(*(int *)(iVar5 + 0x130) + 0x2c) = 0x41400000;

    iVar4 = iVar1 + iVar2 * 8;

    *(u32 *)(*(int *)(iVar5 + 0x130) + 0x10) = *(u32 *)(iVar4 + 0x18c);

    *(u32 *)(*(int *)(iVar5 + 0x130) + 0x14) = *(u32 *)(iVar4 + 400);

    *(u8 *)(*(int *)(iVar5 + 0x148) + 0x18) = 0;

    *(u32 *)(*(int *)(iVar5 + 0x148) + 0x2c) = 0x41400000;

    *(float *)(*(int *)(iVar5 + 0x148) + 0x10) = *(float *)(iVar4 + 0x18c) + 181.0;

    *(u32 *)(*(int *)(iVar5 + 0x148) + 0x14) = *(u32 *)(iVar4 + 400);

    lVar3 = (long)(iVar2 + 1);

  }

  *(u32 *)(*(int *)(iVar1 + 0xd0) + 0x2c) = 0x41200000;

  *(u32 *)(*(int *)(iVar1 + 0xd0) + 0x10) = 0x43d50000;

  *(u32 *)(*(int *)(iVar1 + 0xd0) + 0x14) = 0x43cb0000;

  return;

}

// FUN_00423FC0


void FUN_00423fc0(int param_1)



{

  *(u8 *)(*(int *)(param_1 + 0x3c) + 0x95) = 1;

  return;

}

// FUN_00423FE0 NONMATCHING


void FUN_00423fe0(float *param_1,char param_2,short param_3,short param_4,short param_5,

                 short param_6)



{

  int iVar1;

  int iVar2;

  float fStack_8;

  float fStack_4;

  

  if (param_2 == '\0') {

    iVar1 = (int)param_3;

    if (param_3 < 0) {

      iVar1 = iVar1 + 1;

    }

    fStack_8 = (float)(iVar1 >> 1);

    iVar1 = (int)param_4;

    if (param_4 < 0) {

      iVar1 = iVar1 + 1;

    }

    fStack_4 = (float)(iVar1 >> 1);

  }

  else if (param_2 == '\x01') {

    iVar1 = (int)param_5;

    iVar2 = param_3 - iVar1;

    if (iVar2 < 0) {

      iVar2 = iVar2 + 1;

    }

    if (param_5 < 0) {

      iVar1 = param_5 + 1;

    }

    fStack_8 = (float)((iVar1 >> 1) + (iVar2 >> 1));

    iVar1 = (int)param_6;

    iVar2 = param_4 - iVar1;

    if (iVar2 < 0) {

      iVar2 = iVar2 + 1;

    }

    if (param_6 < 0) {

      iVar1 = param_6 + 1;

    }

    fStack_4 = (float)((iVar1 >> 1) + (iVar2 >> 1));

  }

  else if (param_2 == '\x02') {

    iVar1 = (int)param_3;

    if (param_3 < 0) {

      iVar1 = iVar1 + 1;

    }

    iVar2 = (int)param_5;

    if (param_5 < 0) {

      iVar2 = iVar2 + 1;

    }

    fStack_8 = (float)((iVar1 >> 1) - (iVar2 >> 1));

    iVar1 = (int)param_4;

    if (param_4 < 0) {

      iVar1 = iVar1 + 1;

    }

    iVar2 = (int)param_6;

    if (param_6 < 0) {

      iVar2 = iVar2 + 1;

    }

    fStack_4 = (float)((iVar1 >> 1) - (iVar2 >> 1));

  }

  *param_1 = fStack_8;

  param_1[1] = fStack_4;

  return;

}


