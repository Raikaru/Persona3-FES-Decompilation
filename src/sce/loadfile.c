#include "mw_harvest_compat.h"
#include "sce/sifdev.h"
#include "sce/sifrpc.h"

/* auto-extern (generated) */
u32 FUN_0050dcb0(u32 param_1);
void FUN_0050da58(int param_1);
u64 FUN_0050efe0(void);
u8 * FUN_0050f588(long param_1,u64 param_2);
u32 FUN_00510148(long param_1);
u32 FUN_0050fbc0(void);
long FUN_0050e508(void);
void FUN_0050e000(long param_1);
void FUN_0050f3d0(void);
void FUN_0050d780(void);
u32 FUN_0050def0(void);
long FUN_0050ce40(void);
void FUN_0050db38(void);
extern u32 ram0x00780b90;
extern u32 DAT_0077f8f4;
extern u32 DAT_0078038c;
extern u32 DAT_00780b14;
extern u32 DAT_0096b3c0;
extern u32 DAT_0096da80;
extern void* PTR_LAB_0077f8ec;
extern void* PTR_LAB_0077f8fc;
extern void* PTR_LAB_0077fbc4;
extern void* PTR_LAB_0077fbcc;
extern void* PTR_LAB_00780384;
extern void* PTR_LAB_0078039c;
extern void* PTR_LAB_00780b0c;
extern u32 DAT_0077f560;
extern u32 DAT_0077f898;
extern u32 DAT_0077f8e0;
extern u32 DAT_0077f8e8;
extern u32 DAT_0077f8f0;
extern u32 DAT_0077f8f8;
extern u32 DAT_0077f900;
extern u32 DAT_0077fb98;
extern u32 DAT_0077fb9c;
extern u32 DAT_0077fba0;
extern u32 DAT_0077fba4;
extern u32 DAT_0077fbb8;
extern u32 DAT_0077fbc0;
extern u32 DAT_0077fbc8;
extern u32 DAT_0077fbd0;
extern u32 DAT_0077fbd4;
extern u32 DAT_00780380;
extern u32 DAT_00780388;
extern u32 DAT_00780390;
extern u32 DAT_00780398;
extern u32 DAT_00780b08;
extern u32 DAT_00780b10;
extern u32 DAT_00780b18;
extern u32 DAT_00780b48;
extern u32 DAT_00780b50;
extern u32 DAT_00780b54;
extern u32 DAT_00780b58;
extern u32* DAT_00780b5c;
extern u32* DAT_00780b60;
extern u32 DAT_00780b64;
extern u32 DAT_00780b68;
extern u32 DAT_00780b70;
extern u32 DAT_00780b74;
extern u32 DAT_00780b94;
extern u32 DAT_00780b98;
extern u32 DAT_00780b9c;
extern u32 DAT_00780ba0;
extern u32 DAT_00780ba4;
extern u32 DAT_00780ba8;
extern u32 DAT_00780bac;
extern u32 DAT_00780bb0;
extern u32 DAT_00780bb4;
extern u32 DAT_00780bbc;
extern u32 DAT_00780bc8;
extern u32 DAT_00780bcc;
extern u32 DAT_00780bd4;
extern u32 DAT_00780be0;
extern u32* DAT_00780be4;
extern u32 DAT_00781d74;
extern u32 DAT_00782724;
extern u32 DAT_007be000;
extern u32 DAT_00969ec0;
extern u32 DAT_00969ec4;
extern u32 DAT_00969ec8;
extern u32 DAT_00969fc3;
extern u32 DAT_00969fc4;
extern u32 DAT_0096a0bf;
extern u32 DAT_0096a100;
extern u32 DAT_0096a108;
extern u32 DAT_0096a110;
extern u32 DAT_0096a114;
extern u32 DAT_0096a118;
extern u32 DAT_0096d380;
extern u32 DAT_0096d3c0;
extern u32 DAT_0096d7b0;
extern u32* DAT_0096d7c0;
extern u32 DAT_0096d7c8;
extern u32* DAT_0096da00;
extern u32 DAT_0096da04;
extern u32* DAT_0096da08;
extern u32 DAT_0096da0c;
extern u32* DAT_0096da10;
extern u32 DAT_0096da14;
extern u32 DAT_0096daa4;
extern u32 DAT_0096dba3;
extern u32 DAT_0096dba4;
extern u32 DAT_0096dba8;
extern u32 DAT_0096dc24;
extern u32 DAT_20780c00;
extern u32 DAT_2096da80;
extern u32 DAT_2096da88;
extern u32 DAT_2096da90;
extern u32 DAT_2096da98;
extern u32 DAT_2096daa0;
extern u32 DAT_2096dbc0;
extern void* PTR_DAT_0077f564;
extern void* PTR_DAT_0077fba8;
extern void* PTR_DAT_0077fbac;
extern void* PTR_DAT_0077fbb0;
extern u32 _DAT_0096a100;
extern int Wired;
extern int Status;
extern int ErrorPC;
extern char s_SceKernelLibc_007be0b0[];
extern char s_SceKernelLibcEh_007be0c0[];
extern u32 REG_RCNT2_MODE;
extern u32 REG_RCNT2_COUNT;
extern u32 REG_RCNT3_MODE;
extern char s_SceCdNcmdSema_007be118[];
extern char s_SceCdScmdSema_007be128[];
extern char s_SceCdRcmdSema_007be138[];
extern char s_SceCdCallbackSema_007be148[];

#define SIF_LOADFILE_SERVER 0x80000006
#define SIF_LOADFILE_MODULE 0
#define SIF_LOADFILE_MODULE_BUFFER 1
#define SIF_LOADFILE_PATH_LIMIT 252
#define SIF_LOADFILE_ARGS_LIMIT 252

typedef struct SifLoadModuleRequest
{
    int result;
    int module_result;
    int argument_length;
    char path[SIF_LOADFILE_PATH_LIMIT];
    char arguments[SIF_LOADFILE_ARGS_LIMIT];
} SifLoadModuleRequest_t;

static SifRpcClientData_t sLoadFileClient;
static int sLoadFileInitialized;

static int sif_copy_bytes(char* destination, const char* source, int length, int capacity)
{
    int count;

    count = 0;
    if (source != 0)
    {
        while (count < length && count < capacity)
        {
            destination[count] = source[count];
            count++;
        }
    }
    return count;
}

static int sif_copy_string(char* destination, const char* source, int capacity)
{
    int count;

    count = 0;
    if (source != 0)
    {
        while (count + 1 < capacity && source[count] != '\0')
        {
            destination[count] = source[count];
            count++;
        }
    }
    destination[count] = '\0';
    return count;
}

// FUN_0050BAE8 NONMATCHING

// FUN_0050BBE8 NONMATCHING
bool FUN_0050bbe8(void)

{
  long lVar1;
  bool bVar2;
  
  bVar2 = false;
  lVar1 = FUN_005211b8(0x96a0e8,0x77f48c,4);
  if (lVar1 != 0) {
    lVar1 = FUN_005211b8(0x96a0e8,PTR_DAT_0077f564,4);
    if (lVar1 != 0) {
      lVar1 = FUN_005211b8(0x77f48c,PTR_DAT_0077f564,4);
      bVar2 = lVar1 != 0;
    }
  }
  return bVar2;
}
// FUN_0050BC78 NONMATCHING
u64 FUN_0050bc78(void)

{
  DAT_0077f560 = 0xffffffff;
  FUN_00521408(0x96a0e8,0,4);
  return 0;
}
// FUN_0050BCB0 NONMATCHING
u32 FUN_0050bcb0(void)

{
  u32 param_1;
  long param_2;
  u64 *param_3;
  u32 *param_4;
  u32 uVar1;
  u64 *puVar2;
  long lVar3;
  u64 *puVar4;
  u64 uVar5;
  u64 uVar6;
  u64 uVar7;
  
  lVar3 = FUN_0050bae8();
  uVar1 = 0xffff0000;
  if (-1 < lVar3) {
    lVar3 = FUN_0050bbe8();
    if (lVar3 == 0) {
      DAT_00969ec0 = param_1;
      if (param_3 == (u64 *)0x0) {
        DAT_00969ec4 = 0;
      }
      else if (param_2 < 0xfd) {
        FUN_00521250(0x969fc4,param_3,param_2);
        DAT_00969ec4 = (u32)param_2;
      }
      else {
        puVar4 = (u64 *)&DAT_00969fc4;
        if ((((u32)param_3 | 0x969fc4) & 7) == 0) {
          puVar2 = param_3 + 0x1c;
          do {
            uVar5 = param_3[1];
            uVar6 = param_3[2];
            uVar7 = param_3[3];
            *puVar4 = *param_3;
            puVar4[1] = uVar5;
            puVar4[2] = uVar6;
            puVar4[3] = uVar7;
            param_3 = param_3 + 4;
            puVar4 = puVar4 + 4;
          } while (param_3 != puVar2);
        }
        else {
          puVar2 = param_3 + 0x1c;
          do {
            uVar5 = param_3[1];
            uVar6 = param_3[2];
            uVar7 = param_3[3];
            *puVar4 = *param_3;
            puVar4[1] = uVar5;
            puVar4[2] = uVar6;
            puVar4[3] = uVar7;
            param_3 = param_3 + 4;
            puVar4 = puVar4 + 4;
          } while (param_3 != puVar2);
        }
        uVar6 = param_3[1];
        uVar5 = param_3[2];
        uVar1 = *(u32 *)(param_3 + 3);
        *puVar4 = *param_3;
        puVar4[1] = uVar6;
        puVar4[2] = uVar5;
        *(u32 *)(puVar4 + 3) = uVar1;
        DAT_00969ec4 = 0xfc;
      }
      lVar3 = FUN_00507230(0x96a0c0,6,0,0x969ec0,0x200,0x969ec0,8,0);
      uVar1 = DAT_00969ec0;
      if (lVar3 < 0) {
        uVar1 = 0xfffeffff;
      }
      else {
        *param_4 = DAT_00969ec4;
      }
    }
    else {
      uVar1 = 0xfffefffc;
    }
  }
  return uVar1;
}
// FUN_0050BEB8 NONMATCHING
u32 FUN_0050beb8(u32 param_1,long param_2,u64 *param_3,u32 *param_4)

{
  u32 uVar1;
  u64 *puVar2;
  long lVar3;
  u64 *puVar4;
  u64 uVar5;
  u64 uVar6;
  u64 uVar7;
  
  lVar3 = FUN_0050bae8();
  uVar1 = 0xffff0000;
  if (-1 < lVar3) {
    lVar3 = FUN_0050bbe8();
    if (lVar3 == 0) {
      DAT_00969ec0 = param_1;
      if (param_3 == (u64 *)0x0) {
        DAT_00969ec4 = 0;
      }
      else if (param_2 < 0xfd) {
        FUN_00521250(0x969fc4,param_3,param_2);
        DAT_00969ec4 = (u32)param_2;
      }
      else {
        puVar4 = (u64 *)&DAT_00969fc4;
        if ((((u32)param_3 | 0x969fc4) & 7) == 0) {
          puVar2 = param_3 + 0x1c;
          do {
            uVar5 = param_3[1];
            uVar6 = param_3[2];
            uVar7 = param_3[3];
            *puVar4 = *param_3;
            puVar4[1] = uVar5;
            puVar4[2] = uVar6;
            puVar4[3] = uVar7;
            param_3 = param_3 + 4;
            puVar4 = puVar4 + 4;
          } while (param_3 != puVar2);
        }
        else {
          puVar2 = param_3 + 0x1c;
          do {
            uVar5 = param_3[1];
            uVar6 = param_3[2];
            uVar7 = param_3[3];
            *puVar4 = *param_3;
            puVar4[1] = uVar5;
            puVar4[2] = uVar6;
            puVar4[3] = uVar7;
            param_3 = param_3 + 4;
            puVar4 = puVar4 + 4;
          } while (param_3 != puVar2);
        }
        uVar6 = param_3[1];
        uVar5 = param_3[2];
        uVar1 = *(u32 *)(param_3 + 3);
        *puVar4 = *param_3;
        puVar4[1] = uVar6;
        puVar4[2] = uVar5;
        *(u32 *)(puVar4 + 3) = uVar1;
        DAT_00969ec4 = 0xfc;
      }
      lVar3 = FUN_00507230(0x96a0c0,7,0,0x969ec0,0x200,0x969ec0,8,0);
      uVar1 = DAT_00969ec0;
      if (lVar3 < 0) {
        uVar1 = 0xfffeffff;
      }
      else {
        *param_4 = DAT_00969ec4;
      }
    }
    else {
      uVar1 = 0xfffefffc;
    }
  }
  return uVar1;
}
// FUN_0050C0C0 NONMATCHING
u32 FUN_0050c0c0(u32 param_1)

{
  u32 uVar1;
  long lVar2;
  
  lVar2 = FUN_0050bae8();
  uVar1 = 0xffff0000;
  if (-1 < lVar2) {
    lVar2 = FUN_0050bbe8();
    if (lVar2 == 0) {
      DAT_00969ec0 = param_1;
      lVar2 = FUN_00507230(0x96a0c0,8,0,0x969ec0,4,0x969ec0,4,0);
      uVar1 = DAT_00969ec0;
      if (lVar2 < 0) {
        uVar1 = 0xfffeffff;
      }
    }
    else {
      uVar1 = 0xfffefffc;
    }
  }
  return uVar1;
}
// FUN_0050C150 NONMATCHING
u32 FUN_0050c150(u64 param_1)

{
  u32 uVar1;
  long lVar2;
  
  lVar2 = FUN_0050bae8();
  uVar1 = 0xffff0000;
  if (-1 < lVar2) {
    lVar2 = FUN_0050bbe8();
    if (lVar2 == 0) {
      FUN_00524828(0x969ec8,param_1,0xfc);
      DAT_00969fc3 = 0;
      lVar2 = FUN_00507230(0x96a0c0,9,0,0x969ec0,0x200,0x969ec0,4,0);
      uVar1 = DAT_00969ec0;
      if (lVar2 < 0) {
        uVar1 = 0xfffeffff;
      }
    }
    else {
      uVar1 = 0xfffefffc;
    }
  }
  return uVar1;
}
// FUN_0050C1F0 NONMATCHING
u32 FUN_0050c1f0(u32 param_1)

{
  u32 uVar1;
  long lVar2;
  
  lVar2 = FUN_0050bae8();
  uVar1 = 0xffff0000;
  if (-1 < lVar2) {
    lVar2 = FUN_0050bbe8();
    if (lVar2 == 0) {
      DAT_00969ec0 = param_1;
      lVar2 = FUN_00507230(0x96a0c0,10,0,0x969ec0,4,0x969ec0,4,0);
      uVar1 = DAT_00969ec0;
      if (lVar2 < 0) {
        uVar1 = 0xfffeffff;
      }
    }
    else {
      uVar1 = 0xfffefffc;
    }
  }
  return uVar1;
}
// FUN_0050C280 NONMATCHING
void FUN_0050c280(void)

{
  FUN_0050bcb0();
  return;
}
// FUN_0050C2A0 NONMATCHING
void FUN_0050c2a0(void)

{
  FUN_0050bcb0();
  return;
}
// FUN_0050C2C0 NONMATCHING
static int sif_load_module_request(const char* path, int argument_length, const char* arguments, int* module_result, int function)
{
    SifLoadModuleRequest_t request;
    int copied_length;

    if (sif_loadfile_init() < 0)
    {
        return -0x10000;
    }
    request.result = 0;
    request.module_result = 0;
    request.argument_length = 0;
    sif_copy_string(request.path, path, sizeof(request.path));
    if (arguments != 0 && argument_length > 0)
    {
        copied_length = argument_length;
        if (copied_length > SIF_LOADFILE_ARGS_LIMIT)
        {
            copied_length = SIF_LOADFILE_ARGS_LIMIT;
        }
        request.argument_length = sif_copy_bytes(request.arguments, arguments, copied_length, sizeof(request.arguments));
    }
    if (sceSifCallRpc(&sLoadFileClient, function, 0, &request, sizeof(request), &request, 8, 0, 0) < 0)
    {
        return -0x10001;
    }
    if (module_result != 0)
    {
        *module_result = request.module_result;
    }
    return request.result;
}

// FUN_0050C4E8 NONMATCHING
int sceSifLoadModule(const char* filename, int args, const char* argp)
{
    int module_result;

    return sif_load_module_request(filename, args, argp, &module_result, SIF_LOADFILE_MODULE);
}

// FUN_0050C508 NONMATCHING
int sceSifLoadStartModule(const char* filename, int args, const char* argp, int* result)
{
    return sif_load_module_request(filename, args, argp, result, SIF_LOADFILE_MODULE);
}

// FUN_0050C528 NONMATCHING
u32 FUN_0050c528(void)

{
  u64 param_1;
  u64 param_2;
  int *param_3;
  u64 param_4;
  u32 uVar1;
  long lVar2;
  
  lVar2 = FUN_0050bae8();
  uVar1 = 0xffff0000;
  if (-1 < lVar2) {
    lVar2 = FUN_0050bbe8();
    if (lVar2 == 0) {
      FUN_00524828(0x969ec8,param_1,0xfc);
      DAT_00969fc3 = 0;
      FUN_00524828(0x969fc4,param_2,0xfc);
      DAT_0096a0bf = 0;
      lVar2 = FUN_00507230(0x96a0c0,param_4,0,0x969ec0,0x200,0x969ec0,0x10,0);
      if (lVar2 < 0) {
        uVar1 = 0xfffeffff;
      }
      else if (DAT_00969ec0 == 0) {
        uVar1 = 0xfffefffd;
      }
      else {
        *param_3 = DAT_00969ec0;
        uVar1 = 0;
        param_3[1] = DAT_00969ec4;
      }
    }
    else {
      uVar1 = 0xfffefffc;
    }
  }
  return uVar1;
}
// FUN_0050C630 NONMATCHING
void FUN_0050c630(void)

{
  FUN_0050c528();
  return;
}
// FUN_0050C678 NONMATCHING
u32 FUN_0050c678(u32 param_1,u32 *param_2,u32 param_3)

{
  u32 uVar1;
  long lVar2;
  
  lVar2 = FUN_0050bae8();
  if (lVar2 < 0) {
    return 0xffff0000;
  }
  if (param_3 < 3) {
    DAT_00969ec4 = (u32)param_3;
    DAT_00969ec0 = param_1;
    lVar2 = FUN_00507230(0x96a0c0,3,0,0x969ec0,0x20,0x969ec0,0x20,0);
    if (lVar2 < 0) {
      return 0xfffeffff;
    }
    if (param_3 == 0) {
      *(u8 *)param_2 = (u8)DAT_00969ec0;
    }
    else if (param_3 == 1) {
      *(u16 *)param_2 = (u16)DAT_00969ec0;
    }
    else {
      if (param_3 != 2) goto LAB_0050c734;
      *param_2 = DAT_00969ec0;
    }
    uVar1 = 0;
  }
  else {
LAB_0050c734:
    uVar1 = 0xfffefffe;
  }
  return uVar1;
}
// FUN_0050C768 NONMATCHING
u32 FUN_0050c768(u32 param_1,u32 *param_2,long param_3)

{
  u32 uVar1;
  long lVar2;
  
  lVar2 = FUN_0050bae8();
  if (lVar2 < 0) {
    uVar1 = 0xffff0000;
  }
  else {
    DAT_00969ec4 = (u32)param_3;
    if (param_3 == 0) {
      DAT_00969ec8 = CONCAT31((*(u32 *)((u8 *)&DAT_00969ec8 + 1) & 0x00FFFFFF),*(u8 *)param_2);
    }
    else if (param_3 == 1) {
      DAT_00969ec8 = CONCAT22((*(u16*)((u8*)&DAT_00969ec8 + 2)),*(u16 *)param_2);
    }
    else {
      if (param_3 != 2) {
        DAT_00969ec0 = param_1;
        return 0xfffefffe;
      }
      DAT_00969ec8 = *param_2;
    }
    DAT_00969ec0 = param_1;
    lVar2 = FUN_00507230(0x96a0c0,2,0,0x969ec0,0x20,0x969ec0,0x10,0);
    uVar1 = 0xfffeffff;
    if (-1 < lVar2) {
      uVar1 = 0;
    }
  }
  return uVar1;
}
// FUN_0050C848 NONMATCHING
bool FUN_0050c848(char *param_1,u32 param_2)

{
  long lVar1;
  char cVar2;
  int iVar3;
  u8 *puStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  
  FUN_0050f588(1,0);
  sceSifStopDma();
  uStack_3c = sceSifGetReg(0xffffffff80000000);
  DAT_0096a110 = 0;
  DAT_0096a114 = param_2;
  if (*param_1 != '\0') {
    cVar2 = *param_1;
    iVar3 = DAT_0096a110;
    while( true ) {
      DAT_0096a110 = iVar3 + 1;
      (&DAT_0096a118)[iVar3] = cVar2;
      if (param_1[DAT_0096a110] == '\0') break;
      cVar2 = param_1[DAT_0096a110];
      iVar3 = DAT_0096a110;
    }
  }
  DAT_0096a108 = 0x80000003;
  _DAT_0096a100 = 0x68;
  uStack_38 = 0x68;
  uStack_34 = 0x44;
  puStack_40 = (u8 *)(&DAT_0096a100);
  FUN_005067f8(0x96a100,0x68);
  sceSifSetReg(4,0x40000);
  lVar1 = sceSifSetDma(&puStack_40,1);
  if (lVar1 != 0) {
    sceSifSetReg(4,0x10000);
    sceSifSetReg(4,0x20000);
    sceSifSetReg(0xffffffff80000002,0);
    sceSifSetReg(0xffffffff80000000,0);
  }
  return lVar1 != 0;
}
// FUN_0050C9A0 NONMATCHING
bool FUN_0050c9a0(void)

{
  u32 uVar1;
  
  uVar1 = sceSifGetReg(4);
  return (uVar1 & 0x10000) != 0;
}
// FUN_0050C9C8 NONMATCHING
bool FUN_0050c9c8(void)

{
  bool bVar1;
  u32 uVar2;
  
  uVar2 = sceSifGetReg(4);
  bVar1 = (uVar2 & 0x40000) != 0;
  if (bVar1) {
    FUN_005035e0();
    FUN_0050f588(1,1);
    FUN_0050f588(0,1);
  }
  return bVar1;
}
// FUN_0050CA18 NONMATCHING
u64 FUN_0050ca18(u8 *param_1)

{
  u8 bVar1;
  u32 uVar2;
  u64 uVar3;
  char *pcVar4;
  char cVar5;
  u8 *pbVar6;
  u32 uVar7;
  char *pcVar8;
  char acStack_80 [80];
  
  pcVar4 = acStack_80;
  pcVar8 = (char *)(&DAT_007be000);
  if (*param_1 == 0) {
    uVar2 = 0xb;
  }
  else {
    pbVar6 = param_1;
    do {
      pbVar6 = pbVar6 + 1;
    } while (*pbVar6 != 0);
    uVar2 = (int)pbVar6 - (int)(param_1 + -0xb);
  }
  if (uVar2 < 0x51) {
    FUN_005068a8(0);
    FUN_00506a48();
    if (DAT_007be000 == '\0') {
      bVar1 = *param_1;
      pcVar4 = acStack_80;
    }
    else {
      bVar1 = *param_1;
      cVar5 = DAT_007be000;
      do {
        *pcVar4 = cVar5;
        pcVar8 = pcVar8 + 1;
        pcVar4 = pcVar4 + 1;
        cVar5 = *pcVar8;
      } while (*pcVar8 != '\0');
    }
    uVar7 = (u32)bVar1;
    if (uVar7 == 0) {
      *pcVar4 = '\0';
    }
    else {
      do {
        *pcVar4 = (char)uVar7;
        param_1 = param_1 + 1;
        pcVar4 = pcVar4 + 1;
        uVar7 = (u32)(char)*param_1;
      } while (uVar7 != 0);
      *pcVar4 = '\0';
    }
    uVar3 = FUN_0050c848(acStack_80,0);
  }
  else {
    FUN_00505e48(0x7be010,param_1);
    uVar3 = 0;
  }
  return uVar3;
}
// FUN_0050CB28 NONMATCHING
u64 FUN_0050cb28(u64 param_1)

{
  DAT_0077f898 = (u32)param_1;
  SetVTLBRefillHandler(1,0x50d040);
  SetVTLBRefillHandler(2,0x50d040);
  SetVTLBRefillHandler(3,0x50d040);
  return param_1;
}
// FUN_0050CC10 NONMATCHING
void FUN_0050cc10(u32 param_1,u32 param_2,u32 param_3)

{
  syscall(0x5a);
  return;
}



// FUN_0050CC58 RFU091

u64 RFU091(u64 param_1)

{
  syscall(0x5b);
  return 0;
}



// FUN_0050CC68 RFU116_SetSyscall

void RFU116_SetSyscall(void)

{
  syscall(0x74);
  return;
}
// FUN_0050CC78 NONMATCHING
void FUN_0050cc78(void)

{
  u32 uVar1;
  u64 uVar2;
  u32 *puVar3;
  u32 uVar4;
  
  uVar4 = 3;
  puVar3 = &DAT_0077f900;
  FUN_0050cc10(0xffffffff80075000,0x77f568,0x330);
  FlushCache(0);
  FlushCache(2);
  uVar1 = DAT_0077f900;
  while( true ) {
    uVar4 = uVar4 + 1;
    uVar2 = RFU091(uVar1);
    uVar1 = *puVar3;
    puVar3 = puVar3 + 2;
    if (7 < uVar4) break;
    uVar1 = *puVar3;
  }
  DAT_0077f8e0 = RFU091(3);
  return;
}



// FUN_0050CD60 RFU086_WaitEvnetFlag

u64 RFU086_WaitEvnetFlag(u64 param_1,u64 param_2,u64 param_3,u64 param_4,u64 param_5)

{
  syscall(0x56);
  return 0;
}
// FUN_0050CD70 NONMATCHING
u64 FUN_0050cd70(int param_1)

{
  u64 uVar1;
  
  if (param_1 - 0xdU < 0x23) {
    uVar1 = RFU086_WaitEvnetFlag(0,0,0,0,0);
  }
  else {
    uVar1 = 0xffffffffffffffff;
  }
  return uVar1;
}
// FUN_0050CE00 NONMATCHING
void FUN_0050ce00(void)

{
  long lVar1;
  
  lVar1 = GetMemorySize();
  if (lVar1 == 0x2000000) {
  }
  else {
    _InitTLB();
  }
  return;
}
// FUN_0050CE40 NONMATCHING
long FUN_0050ce40(void)

{
  u32 *puVar1;
  u32 *puVar2;
  u32 *puVar3;
  u32 uVar4;
  int iVar5;
  u32 *puVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  
  iVar5 = DAT_0077fb98 + DAT_0077fb9c;
  FUN_00505ec8(0x7be030,DAT_0077fb98 + -1,DAT_0077fb98,iVar5 + -1,iVar5,iVar5 + DAT_0077fba0 + -1);
  Wired = 0;
  SYNC(0x10);
  lVar8 = (long)DAT_0077fb98;
  lVar9 = 0;
  if (0x30 < lVar8) {
    FUN_00505ec8(0x7be068);
  }
  if (lVar9 < lVar8) {
    uVar4 = *(u32 *)PTR_DAT_0077fba8;
    puVar6 = (u32 *)PTR_DAT_0077fba8;
    while( true ) {
      puVar1 = puVar6 + 1;
      puVar2 = puVar6 + 2;
      puVar3 = puVar6 + 3;
      puVar6 = puVar6 + 4;
      RFU086_WaitEvnetFlag(lVar9,uVar4,*puVar1,*puVar2,*puVar3);
      lVar9 = (long)((int)lVar9 + 1);
      if (lVar8 <= lVar9) break;
      uVar4 = *puVar6;
    }
  }
  lVar8 = (long)((int)lVar9 + DAT_0077fb9c);
  if (0x30 < lVar8) {
    FUN_00505ec8(0x7be080);
    FUN_0050da58(1);
  }
  if (lVar9 < lVar8) {
    uVar4 = *(u32 *)PTR_DAT_0077fbac;
    puVar6 = (u32 *)PTR_DAT_0077fbac;
    while( true ) {
      puVar1 = puVar6 + 1;
      puVar2 = puVar6 + 2;
      puVar3 = puVar6 + 3;
      puVar6 = puVar6 + 4;
      RFU086_WaitEvnetFlag(lVar9,uVar4,*puVar1,*puVar2,*puVar3);
      lVar9 = (long)((int)lVar9 + 1);
      if (lVar8 <= lVar9) break;
      uVar4 = *puVar6;
    }
  }
  Wired = (int)lVar9;
  SYNC(0x10);
  DAT_0077fba4 = Wired;
  if (0 < DAT_0077fba0) {
    lVar8 = (long)(Wired + DAT_0077fba0);
    if (0x30 < lVar8) {
      FUN_00505ec8(0x7be098);
      FUN_0050da58(1);
    }
    if (lVar9 < lVar8) {
      uVar4 = *(u32 *)PTR_DAT_0077fbb0;
      puVar6 = (u32 *)PTR_DAT_0077fbb0;
      while( true ) {
        puVar1 = puVar6 + 1;
        puVar2 = puVar6 + 2;
        puVar3 = puVar6 + 3;
        puVar6 = puVar6 + 4;
        RFU086_WaitEvnetFlag(lVar9,uVar4,*puVar1,*puVar2,*puVar3);
        lVar9 = (long)((int)lVar9 + 1);
        if (lVar8 <= lVar9) break;
        uVar4 = *puVar6;
      }
    }
  }
  iVar5 = (int)lVar9 * 0x2000;
  lVar8 = (long)iVar5;
  if (lVar9 < 0x30) {
    iVar5 = iVar5 + -0x20000000;
    do {
      lVar7 = (long)((int)lVar9 + 1);
      RFU086_WaitEvnetFlag(lVar9,0,iVar5,0,0);
      iVar5 = iVar5 + 0x2000;
      lVar9 = lVar7;
    } while (lVar7 < 0x30);
  }
  return lVar8;
}
// FUN_0050D3A0 NONMATCHING
bool FUN_0050d3a0(void)

{
  if ((Status & 0x10000) != 0) {
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    return (Status & 0x10000) != 0;
  }
  return false;
}
// FUN_0050D3F0 NONMATCHING
bool FUN_0050d3f0(void)

{
  EI();
  return (Status & 0x10000) != 0;
}
// FUN_0050D408 NONMATCHING
void FUN_0050d408(void)

{
  u8 auStack_50 [4];
  u32 uStack_4c;
  u32 uStack_48;
  char *pcStack_3c;
  u8 auStack_30 [4];
  u32 uStack_2c;
  u32 uStack_28;
  char *pcStack_1c;
  
  pcStack_3c = s_SceKernelLibc_007be0b0;
  uStack_28 = 1;
  pcStack_1c = s_SceKernelLibcEh_007be0c0;
  uStack_4c = 1;
  uStack_48 = 1;
  uStack_2c = 1;
  DAT_0077fbd0 = CreateSema(auStack_50);
  DAT_0077fbd4 = CreateSema(auStack_30);
  return;
}
// FUN_0050D478 NONMATCHING
void FUN_0050d478(u32 *param_1,u32 param_2,u32 param_3)

{
  syscall(0x5a);
  return;
}
// FUN_0050D500 NONMATCHING
int FUN_0050d500(u32 param_1,u32 param_2,u32 param_3)

{
  syscall(0x83);
  return 0;
  return;
}
// FUN_0050D510 NONMATCHING
u32 FUN_0050d510(int param_1)

{
  u32 auStack_20 [4];
  
  FUN_0050d478(auStack_20,DAT_0077fbb8 + param_1 * 4,4);
  return auStack_20[0];
}
// FUN_0050D548 NONMATCHING
void FUN_0050d548(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  u32 uVar4;
  u32 uVar5;
  
  iVar2 = FUN_0050d500(0xffffffff80000000,0xffffffff80080000,0x50d4c0);
  iVar3 = FUN_0050d500(0xffffffff80000000,0xffffffff80080000,0x50d488);
  uVar5 = iVar2 - 0x20c;
  uVar4 = iVar3 - 0x168;
  if (uVar5 != uVar4) {
    bVar1 = uVar5 < uVar4;
    do {
      if (bVar1) {
        iVar2 = FUN_0050d500(iVar2 + 4,0xffffffff80080000,0x50d4c0);
        uVar5 = iVar2 - 0x20c;
      }
      else {
        iVar3 = FUN_0050d500(iVar3 + 4,0xffffffff80080000,0x50d488);
        uVar4 = iVar3 - 0x168;
      }
      bVar1 = uVar5 < uVar4;
    } while (uVar5 != uVar4);
  }
  DAT_0077fbb8 = uVar5;
  return;
}

// FUN_0050D648 RFU116_SetSyscall
void FUN_0050d648(void) { syscall(0x74); return; }

// FUN_0050D658 NONMATCHING
void FUN_0050d658(void)

{
  FUN_0050d408();
  FUN_0050d548();
  FUN_00503f38();
  FUN_0050cc78();
  return;
}

// FUN_0050D6B0 RFU116_SetSyscall
void FUN_0050d6b0(void) { syscall(0x74); return; }

// FUN_0050D6C0 NONMATCHING
void FUN_0050d6c0(u32 param_1,u32 param_2,u32 param_3)

{
  syscall(0x5a);
  return;
}

// FUN_0050D708 RFU091
u64 FUN_0050d708(u64 param_1) { syscall(0x5b); return 0; }

// FUN_0050D718 NONMATCHING
bool FUN_0050d718(void)

{
  u32 uStack_30;
  u32 auStack_2c [3];
  
  GetOsdConfigParam(&uStack_30);
  auStack_2c[0] = uStack_30 & 0xffff1fff | 0x2000;
  SetOsdConfigParam(auStack_2c);
  GetOsdConfigParam(auStack_2c);
  SetOsdConfigParam(&uStack_30);
  return (auStack_2c[0] >> 0xd & 7) == 0;
}
// FUN_0050D780 NONMATCHING
void FUN_0050d780(void)

{
  u32 uVar1;
  long lVar2;
  u64 uVar3;
  u32 *puVar4;
  u32 uVar5;
  
  lVar2 = FUN_0050d718();
  if (lVar2 != 0) {
    uVar5 = 2;
    puVar4 = &DAT_00780390;
    FUN_0050d6c0(0xffffffff80074000,0x77fbd8,0x7a8);
    FlushCache(0);
    FlushCache(2);
    uVar1 = DAT_00780390;
    while( true ) {
      uVar5 = uVar5 + 1;
      uVar3 = RFU091(uVar1);
      uVar1 = *puVar4;
      puVar4 = puVar4 + 2;
      if (2 < uVar5) break;
      uVar1 = *puVar4;
    }
  }
  return;
}
// FUN_0050D830 NONMATCHING
void FUN_0050d830(u32 param_1,u32 param_2,u32 param_3)

{
  syscall(0x5a);
  return;
}

// FUN_0050D870 RFU116_SetSyscall
void FUN_0050d870(void) { syscall(0x74); return; }

// FUN_0050D880 NONMATCHING
int FUN_0050d880(void)

{
  u64 param_1;
  int param_2;
  u32 *param_3;
  u32 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int aiStack_80 [4];
  
  iVar4 = DAT_0077f8e0;
  iVar2 = DAT_0077f8e0 + 0x40;
  aiStack_80[0] = iVar2;
  if (0xf < param_2) {
    param_2 = 0xf;
  }
  FUN_0050d830((u32)iVar4,(u32)aiStack_80,4);
  iVar3 = FUN_00524388(param_1);
  FUN_0050d830((u32)aiStack_80[0],(u32)param_1,(u32)(iVar3 + 1));
  aiStack_80[0] = aiStack_80[0] + iVar3 + 1;
  if (0 < param_2) {
    do {
      iVar4 = iVar4 + 4;
      FUN_0050d830((u32)iVar4,(u32)aiStack_80,4);
      param_2 = param_2 + -1;
      iVar3 = FUN_00524388(*param_3);
      uVar1 = *param_3;
      param_3 = param_3 + 1;
      FUN_0050d830((u32)aiStack_80[0],(u32)uVar1,(u32)(iVar3 + 1));
      aiStack_80[0] = aiStack_80[0] + iVar3 + 1;
    } while (param_2 != 0);
  }
  return iVar2;
}



// FUN_0050D998 thunk_FUN_0050ce00

void thunk_FUN_0050ce00(void)

{
  long lVar1;
  
  lVar1 = GetMemorySize();
  if (lVar1 == 0x2000000) {
    FUN_0050ce40();
  }
  else {
    _InitTLB();
  }
  return;
}
// FUN_0050DA10 NONMATCHING
void FUN_0050da10(u64 param_1,u64 param_2)

{
  u64 uVar1;
  
  uVar1 = FUN_0050d880();
  thunk_FUN_0050ce00();
  _LoadExecPS2(uVar1,param_2,DAT_0077f8e0 + 4);
  return;
}
// FUN_0050DA58 NONMATCHING
void FUN_0050da58(int param_1)

{
  thunk_FUN_0050ce00();
  _Exit(param_1);
  return;
}
// FUN_0050DA80 NONMATCHING
void FUN_0050da80(u64 param_1,u64 param_2)

{
  FUN_0050d880();
  thunk_FUN_0050ce00();
  _ExecOSD(param_1,DAT_0077f8e0 + 4);
  return;
}

// FUN_0050DAD0 RFU116_SetSyscall
void FUN_0050dad0(void) { syscall(0x74); return; }

// FUN_0050DAE0 NONMATCHING
void FUN_0050dae0(u32 param_1,u32 param_2,u32 param_3)

{
  syscall(0x5a);
  return;
}

// FUN_0050DB28 RFU091
u64 FUN_0050db28(u64 param_1) { syscall(0x5b); return 0; }

// FUN_0050DB38 NONMATCHING
void FUN_0050db38(void)

{
  u32 uVar1;
  u64 uVar2;
  u32 *puVar3;
  u32 uVar4;
  
  uVar4 = REG_RCNT3_MODE;
  if ((uVar4 & 0x100) == 0) {
    uVar4 = 2;
    puVar3 = &DAT_00780b18;
    FUN_0050dae0(0xffffffff80076000,0x7803a0,0x740);
    FUN_0050dae0(0x82000,0x780ae0,0x28);
    FlushCache(0);
    FlushCache(2);
    uVar1 = DAT_00780b18;
    while( true ) {
      uVar4 = uVar4 + 1;
      uVar2 = RFU091(uVar1);
      uVar1 = *puVar3;
      puVar3 = puVar3 + 2;
      if (7 < uVar4) break;
      uVar1 = *puVar3;
    }
  }
  return;
}
// FUN_0050DC10 NONMATCHING
void FUN_0050dc10(u64 param_1,u64 param_2)

{
  u32 unaff_retaddr;
  
  while ((Status & 0x10000) != 0) {
    DI();
    SYNC(0x10);
  }
  SYNC(0x10);
  Status = (Status | 6) ^ 2 | Status & 0x10000;
  SYNC(0x10);
  *(u32 *)param_1 = (u32)param_2;
  ErrorPC = unaff_retaddr;
  SYNC(0x10);
  return;
}
// FUN_0050DC80 NONMATCHING
void FUN_0050dc80(u64 param_1)

{
  FUN_0050dc10(0xffffffffb0001000,param_1);
  return;
}
// FUN_0050DC90 NONMATCHING
void FUN_0050dc90(u64 param_1)

{
  FUN_0050dc10(0xffffffffb0001010,param_1);
  return;
}
// FUN_0050DCA0 NONMATCHING
void FUN_0050dca0(u64 param_1)

{
  FUN_0050dc10(0xffffffffb0001020,param_1);
  return;
}
// FUN_0050DCB0 NONMATCHING
u32 FUN_0050dcb0(u32 param_1)

{
  u32 uVar1;
  int iVar2;
  long lVar3;
  u8 *puVar4;
  u32 *puVar5;
  u32 uVar6;
  
  if (DAT_00780b50 < 0) {
    DAT_00780b48 = 0;
    DAT_00780b58 = 0;
    FUN_00521408(0x96b3c0,0,0x2000);
    DAT_00780b5c = (u32 *)((u32)(&DAT_0096b3c0));
    puVar4 = (u8 *)(&DAT_0096d3c0);
    iVar2 = 0x7f;
    puVar5 = &DAT_0096d380;
    do {
      *puVar5 = (u32)(puVar4);
      iVar2 = iVar2 + -1;
      puVar5 = puVar5 + -0x10;
      puVar4 = puVar4 + -0x40;
    } while (-1 < iVar2);
    DAT_0096d380 = 0;
    lVar3 = AddIntcHandler(0xb,0x50e250,0,0);
    if (lVar3 < 0) {
      uVar1 = 0x80009021;
    }
    else {
      DAT_00780b50 = (int)lVar3;
      lVar3 = FUN_0050d3a0();
      uVar6 = REG_RCNT2_MODE;
      param_1 = uVar6 & 0xfffffffc | param_1;
      uVar6 = param_1 | 0x300;
      if ((param_1 & 0x80) == 0) {
        uVar6 = param_1 | 0xf80;
        FUN_0050dc80(0);
        FUN_0050dca0(0xffff);
      }
      FUN_0050dc90(uVar6);
      FUN_00503ca8(0xb);
      uVar1 = 0;
      if (lVar3 != 0) {
        FUN_0050d3f0();
        uVar1 = 0;
      }
    }
  }
  else {
    uVar1 = 0x80008001;
  }
  return uVar1;
}
// FUN_0050DE08 NONMATCHING
u32 FUN_0050de08(void)

{
  u32 uVar1;
  long lVar2;
  long lVar3;
  
  if (DAT_00780b50 < 0) {
    uVar1 = 0x80008001;
  }
  else if (DAT_00780b58 == 0) {
    lVar2 = FUN_0050d3a0();
    lVar3 = RemoveIntcHandler(0xb,DAT_00780b50);
    if (lVar3 == 0) {
      FUN_00503c40(0xb);
      FUN_0050dc90(0xc00);
      FUN_0050dc80(0);
    }
    DAT_00780b48 = 0;
    DAT_00780b50 = -1;
    if (lVar2 != 0) {
      FUN_0050d3f0();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80000010;
  }
  return uVar1;
}
// FUN_0050DEF0 NONMATCHING
u32 FUN_0050def0(void)

{
  u32 uVar1;
  u32 uVar2;
  long lVar3;
  u64 uVar4;
  
  lVar3 = FUN_0050d3a0();
  uVar1 = REG_RCNT2_MODE;
  if ((uVar1 & 0x80) == 0) {
    FUN_0050dc90(uVar1 & 0xfffff3ff | 0x80);
    uVar4 = FUN_0050e508();
    uVar2 = 0;
    if (lVar3 != 0) {
      FUN_0050d3f0();
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 1;
    if (lVar3 != 0) {
      FUN_0050d3f0();
      uVar2 = 1;
    }
  }
  return uVar2;
}
// FUN_0050DF80 NONMATCHING
u32 FUN_0050df80(void)

{
  u32 uVar1;
  u32 uVar2;
  long lVar3;
  
  lVar3 = FUN_0050d3a0();
  uVar1 = REG_RCNT2_MODE;
  if ((uVar1 & 0x80) == 0) {
    uVar2 = 0;
    if (lVar3 != 0) {
      FUN_0050d3f0();
      uVar2 = 0;
    }
  }
  else {
    FUN_0050dc90(uVar1 & 0xfffff37f);
    uVar2 = 1;
    if (lVar3 != 0) {
      FUN_0050d3f0();
      uVar2 = 1;
    }
  }
  return uVar2;
}
// FUN_0050E000 NONMATCHING
void FUN_0050e000(long param_1)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  int *piVar4;
  u32 uVar5;
  
  if (-1 < DAT_00780b64) {
    return;
  }
  uVar2 = REG_RCNT2_MODE;
  if (DAT_00780b60 == (u32 *)0x0) {
    FUN_0050dca0(0);
    FUN_0050dc90(uVar2 & 0xfffff7ff);
    return;
  }
  piVar4 = (int *)*DAT_00780b60;
  uVar5 = (*(long *)(DAT_00780b60 + 8) + *(long *)(DAT_00780b60 + 4)) - *(long *)(DAT_00780b60 + 6);
  if ((piVar4 == (int *)0x0) ||
     (uVar3 = (*(long *)(piVar4 + 8) + *(long *)(piVar4 + 4)) - *(long *)(piVar4 + 6),
     uVar5 + 0x7333 <= uVar3)) {
LAB_0050e0e8:
    param_1 = uVar5 - param_1;
  }
  else {
    do {
      uVar5 = uVar3;
      piVar4 = (int *)*piVar4;
      if (piVar4 == (int *)0x0) goto LAB_0050e0e8;
      uVar3 = (*(long *)(piVar4 + 8) + *(long *)(piVar4 + 4)) - *(long *)(piVar4 + 6);
    } while (uVar3 < uVar5 + 0x7333);
    param_1 = uVar5 - param_1;
  }
  if (0x7332 < param_1) {
    FUN_0050dc90(uVar2 & 0xfffff7ff);
    FUN_0050dca0((int)(uVar5 >> (long)(int)((uVar2 & 3) << 2)));
    return;
  }
  iVar1 = REG_RCNT2_COUNT;
  FUN_0050dca0(iVar1 + (int)(0x7333L >> (long)(int)((uVar2 & 3) << 2)));
  FUN_0050dc90(uVar2 & 0xfffff7ff);
  return;
}
// FUN_0050E190 NONMATCHING
void FUN_0050e190(u32 *param_1)

{
  u32 *puVar1;
  u32 *puVar2;
  
  puVar2 = (u32 *)0x0;
  puVar1 = (u32 *)(DAT_00780b60);
  do {
    if (puVar1 == (u32 *)0x0) {
      param_1[1] = (u32)(puVar2);
LAB_0050e1f0:
      *param_1 = (u32)(puVar1);
      if (puVar1 != (u32 *)0x0) {
        puVar1[1] = (u32)(param_1);
      }
      if (puVar2 != (u32 *)0x0) {
        *puVar2 = (u32)(param_1);
        return;
      }
      DAT_00780b60 = (u32 *)((u32)(param_1));
      return;
    }
    if ((u32)((*(long *)(param_1 + 8) + *(long *)(param_1 + 4)) - *(long *)(param_1 + 6)) <
        (u32)((*(long *)(puVar1 + 8) + *(long *)(puVar1 + 4)) - *(long *)(puVar1 + 6))) {
      param_1[1] = (u32)(puVar2);
      goto LAB_0050e1f0;
    }
    puVar2 = puVar1;
    puVar1 = (u32 *)*puVar1;
  } while( true );
}
// FUN_0050E218 NONMATCHING
int FUN_0050e218(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = iVar1;
  if ((int *)param_1[1] != (int *)0x0) {
    *(int *)param_1[1] = iVar1;
    iVar2 = (int)(DAT_00780b60);
  }
  DAT_00780b60 = (u32 *)(iVar2);
  if (iVar1 == 0) {
    param_1[1] = 0;
  }
  else {
    *(int *)(iVar1 + 4) = param_1[1];
    param_1[1] = 0;
  }
  return iVar1;
}
// FUN_0050E250 NONMATCHING
u64 FUN_0050e250(u64 param_1,u64 param_2,u64 param_3)

{
  u32 uVar1;
  u32 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  u32 *puVar6;
  u32 uVar7;
  
  uVar1 = REG_RCNT2_MODE;
  if (((uVar1 & 0x400) != 0) && (DAT_00780b60 != (u32 *)0x0)) {
    puVar6 = (u32 *)(DAT_00780b60);
    do {
      uVar1 = REG_RCNT2_COUNT;
      uVar2 = REG_RCNT2_MODE;
      lVar5 = *(long *)(puVar6 + 8);
      lVar3 = *(long *)(puVar6 + 4);
      lVar4 = *(long *)(puVar6 + 6);
      if ((uVar2 & 0x800) != 0) {
        DAT_00780b48 = DAT_00780b48 + 1;
        FUN_0050dc90(uVar2 & 0xfffffbff);
        uVar1 = REG_RCNT2_COUNT;
      }
      uVar7 = (DAT_00780b48 << 0x10 | (u32)uVar1) << (long)(int)((uVar2 & 3) << 2);
      if (uVar7 < (u32)((lVar5 + lVar3) - lVar4)) break;
    DAT_00780b68 = (u32)FUN_0050e218((int *)puVar6);
      DAT_00780b64 = (int)puVar6 << 4 | puVar6[2];
      uVar7 = (*(code *)puVar6[10])
                        ((int)puVar6 << 4 | puVar6[2],*(u64 *)(puVar6 + 8),
                         (uVar7 + *(long *)(puVar6 + 6)) - *(long *)(puVar6 + 4),puVar6[0xc],param_3
                        );
      if (uVar7 == 0) {
        puVar6[3] = puVar6[3] & 0xfffffffd;
      }
      else if (uVar7 == 0xffffffffffffffff) {
        puVar6[2] = 0;
        puVar6[3] = 0;
        *puVar6 = (u32)(DAT_00780b5c);
        DAT_00780b58 = DAT_00780b58 + -1;
        DAT_00780b5c = (u32 *)((u32)(puVar6));
      }
      else {
        if (uVar7 < 0x3999) {
          uVar7 = 0x3999;
        }
        *(u32 *)(puVar6 + 8) = *(long *)(puVar6 + 8) + uVar7;
        FUN_0050e190(puVar6);
      }
      puVar6 = (u32 *)(DAT_00780b68);
    } while (DAT_00780b68 != 0);
  }
  DAT_00780b64 = 0xffffffff;
  uVar1 = REG_RCNT2_COUNT;
  uVar2 = REG_RCNT2_MODE;
  DAT_00780b68 = (u32)((u32 *)0x0);
  if ((uVar2 & 0x800) != 0) {
    DAT_00780b48 = DAT_00780b48 + 1;
    FUN_0050dc90(uVar2 & 0xfffffbff);
    uVar1 = REG_RCNT2_COUNT;
  }
  FUN_0050e000((DAT_00780b48 << 0x10 | (u32)uVar1) << (long)(int)((uVar2 & 3) << 2));
  uVar1 = REG_RCNT2_MODE;
  if ((uVar1 & 0x800) != 0) {
    DAT_00780b48 = DAT_00780b48 + 1;
    FUN_0050dc90(uVar1 & 0xfffffbff);
  }
  SYNC(0);
  EI();
  return 0;
}
// FUN_0050E508 NONMATCHING
long FUN_0050e508(void)

{
  u32 uVar1;
  int iVar2;
  u32 uVar3;
  long lVar4;
  long lVar5;
  
  uVar1 = REG_RCNT2_COUNT;
  iVar2 = REG_RCNT2_MODE;
  lVar4 = 2;
  lVar5 = DAT_00780b48;
  if (((long)iVar2 & 0x800U) != 0) {
    uVar1 = REG_RCNT2_COUNT;
    lVar5 = DAT_00780b48 + 1;
  }
  uVar3 = (long)iVar2 & 3;
  if (uVar3 == 0) {
    lVar4 = 0;
  }
  return ((u32)uVar1 | lVar5 << 0x10) << (lVar4 << uVar3);
}
// FUN_0050E558 NONMATCHING
long FUN_0050e558(void)

{
  u32 uVar1;
  int iVar2;
  long lVar3;
  u32 uVar4;
  long lVar5;
  long lVar6;
  
  lVar3 = FUN_0050d3a0();
  uVar1 = REG_RCNT2_COUNT;
  iVar2 = REG_RCNT2_MODE;
  lVar5 = 2;
  lVar6 = DAT_00780b48;
  if (((long)iVar2 & 0x800U) != 0) {
    uVar1 = REG_RCNT2_COUNT;
    lVar6 = DAT_00780b48 + 1;
  }
  uVar4 = (long)iVar2 & 3;
  if (uVar4 == 0) {
    lVar5 = 0;
  }
  if (lVar3 != 0) {
    FUN_0050d3f0();
  }
  return ((u32)uVar1 | lVar6 << 0x10) << (lVar5 << uVar4);
}
// FUN_0050E5D8 NONMATCHING
u32 FUN_0050e5d8(void)

{
  u64 *puVar1;
  u32 *puVar2;
  u32 uVar3;
  
  puVar2 = (u32 *)(DAT_00780b5c);
  if (DAT_00780b5c == (u32 *)0x0) {
    return 0x80008005;
  }
  uVar3 = (int)DAT_00780b5c << 4;
  DAT_00780b58 = DAT_00780b58 + 1;
  DAT_00780b5c[10] = 0;
  DAT_00780b5c[3] = 0;
  puVar1 = (u64 *)(DAT_00780b5c + 6);
  DAT_00780b5c = (u32 *)*DAT_00780b5c;
  *puVar1 = 0;
  DAT_00780b54 = DAT_00780b54 + 1;
  puVar2[2] = (DAT_00780b54 & 0x1ff) << 1 | 1;
  return uVar3 | puVar2[2];
}
// FUN_0050E648 NONMATCHING
u64 FUN_0050e648(void)

{
  long lVar1;
  u64 uVar2;
  
  lVar1 = FUN_0050d3a0();
  uVar2 = FUN_0050e5d8();
  if (lVar1 != 0) {
    FUN_0050d3f0();
  }
  return uVar2;
}
// FUN_0050E690 NONMATCHING
u32 FUN_0050e690(u32 param_1)

{
  u32 uVar1;
  u32 *puVar2;
  u32 *puVar3;
  
  puVar3 = (u32 *)((param_1 >> 10) * 0x40);
  if (((int)param_1 < 0) || ((param_1 & 0x3ff) != puVar3[2])) {
    uVar1 = 0x80008002;
  }
  else if (DAT_00780b64 == param_1) {
    uVar1 = 0x80000010;
  }
  else {
    if (((puVar3[3] & 2) != 0) &&
       (puVar2 = (u32 *)(u32)FUN_0050e218((int *)puVar3), (u32 *)DAT_00780b68 == puVar3)) {
      DAT_00780b68 = (u32)(puVar2);
    }
    puVar3[2] = 0;
    puVar3[3] = 0;
    uVar1 = 0;
    *puVar3 = (u32)(DAT_00780b5c);
    DAT_00780b58 = DAT_00780b58 + -1;
    DAT_00780b5c = (u32 *)((u32)(puVar3));
  }
  return uVar1;
}
// FUN_0050E750 NONMATCHING
u64 FUN_0050e750(u64 param_1)

{
  long lVar1;
  u64 uVar2;
  
  lVar1 = FUN_0050d3a0();
  uVar2 = FUN_0050e690(param_1);
  if (lVar1 != 0) {
    FUN_0050d3f0();
  }
  return uVar2;
}
// FUN_0050E7A0 NONMATCHING
u32 FUN_0050e7a0(long param_1,long param_2)

{
  if (DAT_00780b50 < 0) {
    return 0x80008001;
  }
  if (param_1 != 0) {
    *(int *)param_1 = DAT_00780b58;
  }
  if (param_2 != 0) {
    *(int *)param_2 = 0x80 - DAT_00780b58;
  }
  return 0;
}
// FUN_0050E7F0 NONMATCHING
u64 FUN_0050e7f0(u64 param_1,u64 param_2)

{
  long lVar1;
  u64 uVar2;
  
  lVar1 = FUN_0050d3a0();
  uVar2 = FUN_0050e7a0(param_1,param_2);
  if (lVar1 != 0) {
    FUN_0050d3f0();
  }
  return uVar2;
}
// FUN_0050E850 NONMATCHING
u32 FUN_0050e850(u32 param_1)

{
  u32 uVar1;
  u32 uVar2;
  u64 uVar3;
  int iVar4;
  
  iVar4 = (param_1 >> 10) * 0x40;
  if (((int)param_1 < 0) || ((param_1 & 0x3ff) != *(u32 *)(iVar4 + 8))) {
    uVar2 = 0x80008002;
  }
  else if (DAT_00780b64 == param_1) {
    uVar2 = 0x80000010;
  }
  else {
    uVar2 = 1;
    if ((*(u32 *)(iVar4 + 0xc) & 1) == 0) {
      uVar3 = FUN_0050e508();
      uVar1 = *(u32 *)(iVar4 + 0xc);
      *(u64 *)(iVar4 + 0x10) = uVar3;
      *(u32 *)(iVar4 + 0xc) = uVar1 | 1;
      if ((uVar1 & 2) != 0) {
        FUN_0050e190((u32 *)(int)iVar4);
        FUN_0050e000(uVar3);
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}
// FUN_0050E900 NONMATCHING
u64 FUN_0050e900(u64 param_1)

{
  long lVar1;
  u64 uVar2;
  
  lVar1 = FUN_0050d3a0();
  uVar2 = FUN_0050e850(param_1);
  if (lVar1 != 0) {
    FUN_0050d3f0();
  }
  return uVar2;
}
// FUN_0050E950 NONMATCHING
u32 FUN_0050e950(u32 param_1)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  
  iVar5 = (param_1 >> 10) * 0x40;
  if (((int)param_1 < 0) || ((param_1 & 0x3ff) != *(u32 *)(iVar5 + 8))) {
    uVar2 = 0x80008002;
  }
  else if (DAT_00780b64 == param_1) {
    uVar2 = 0x80000010;
  }
  else {
    uVar2 = 0;
    if ((*(u32 *)(iVar5 + 0xc) & 1) != 0) {
      lVar4 = FUN_0050e508();
      uVar1 = *(u32 *)(iVar5 + 0xc);
      *(long *)(iVar5 + 0x18) = *(long *)(iVar5 + 0x18) + (lVar4 - *(long *)(iVar5 + 0x10));
      *(u32 *)(iVar5 + 0xc) = uVar1 & 0xfffffffe;
      if ((uVar1 & 2) != 0) {
        iVar3 = (int)FUN_0050e218((int *)iVar5);
        if (DAT_00780b68 == iVar5) {
          DAT_00780b68 = iVar3;
        }
        FUN_0050e000(lVar4);
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}
// FUN_0050EA30 NONMATCHING
u64 FUN_0050ea30(u64 param_1)

{
  long lVar1;
  u64 uVar2;
  
  lVar1 = FUN_0050d3a0();
  uVar2 = FUN_0050e950(param_1);
  if (lVar1 != 0) {
    FUN_0050d3f0();
  }
  return uVar2;
}
// FUN_0050EA80 NONMATCHING
long FUN_0050ea80(u32 param_1,u64 param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  
  iVar4 = (param_1 >> 10) * 0x40;
  lVar1 = FUN_0050d3a0();
  if ((((int)param_1 < 0) || ((param_1 & 0x3ff) != *(u32 *)(iVar4 + 8))) ||
     (DAT_00780b64 == param_1)) {
    lVar5 = -1;
    if (lVar1 != 0) {
      FUN_0050d3f0();
      lVar5 = -1;
    }
  }
  else {
    lVar5 = *(long *)(iVar4 + 0x18);
    if ((*(u32 *)(iVar4 + 0xc) & 1) == 0) {
      *(u64 *)(iVar4 + 0x18) = param_2;
    }
    else {
      lVar2 = FUN_0050e508();
      lVar3 = *(long *)(iVar4 + 0x10);
      *(u64 *)(iVar4 + 0x18) = param_2;
      *(long *)(iVar4 + 0x10) = lVar2;
      lVar5 = lVar5 + (lVar2 - lVar3);
    }
    if (lVar1 != 0) {
      FUN_0050d3f0();
    }
  }
  return lVar5;
}
// FUN_0050EB50 NONMATCHING
long FUN_0050eb50(u32 param_1)

{
  int iVar1;
  
  iVar1 = (param_1 >> 10) * 0x40;
  if ((-1 < (int)param_1) && ((param_1 & 0x3ff) == *(u32 *)(iVar1 + 8))) {
    if ((*(u32 *)(iVar1 + 0xc) & 1) != 0) {
      return *(long *)(iVar1 + 0x10) - *(long *)(iVar1 + 0x18);
    }
    return 0;
  }
  return -1;
}
// FUN_0050EB98 NONMATCHING
u64 FUN_0050eb98(u64 param_1)

{
  long lVar1;
  u64 uVar2;
  
  lVar1 = FUN_0050d3a0();
  uVar2 = FUN_0050eb50(param_1);
  if (lVar1 != 0) {
    FUN_0050d3f0();
  }
  return uVar2;
}
// FUN_0050EBE8 NONMATCHING
long FUN_0050ebe8(u32 param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = (param_1 >> 10) * 0x40;
  if (((int)param_1 < 0) || ((param_1 & 0x3ff) != *(u32 *)(iVar3 + 8))) {
    lVar2 = -1;
  }
  else {
    lVar2 = *(long *)(iVar3 + 0x18);
    if ((*(u32 *)(iVar3 + 0xc) & 1) != 0) {
      lVar1 = FUN_0050e508();
      lVar2 = lVar2 + (lVar1 - *(long *)(iVar3 + 0x10));
    }
  }
  return lVar2;
}
// FUN_0050EC58 NONMATCHING
u64 FUN_0050ec58(u64 param_1)

{
  long lVar1;
  u64 uVar2;
  
  lVar1 = FUN_0050d3a0();
  uVar2 = FUN_0050ebe8(param_1);
  if (lVar1 != 0) {
    FUN_0050d3f0();
  }
  return uVar2;
}
// FUN_0050ECA8 NONMATCHING
u32 FUN_0050eca8(u32 param_1,u64 param_2,long param_3,u32 param_4)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  u64 uVar4;
  int iVar5;
  
  iVar5 = (param_1 >> 10) * 0x40;
  if (((int)param_1 < 0) || ((param_1 & 0x3ff) != *(u32 *)(iVar5 + 8))) {
    uVar2 = 0x80008002;
  }
  else if (DAT_00780b64 == param_1) {
    uVar2 = 0x80000010;
  }
  else {
    uVar1 = *(u32 *)(iVar5 + 0xc);
    if ((uVar1 & 2) != 0) {
      iVar3 = (int)FUN_0050e218((int *)iVar5);
      if (DAT_00780b68 == iVar5) {
        DAT_00780b68 = iVar3;
      }
      uVar1 = *(u32 *)(iVar5 + 0xc);
    }
    *(int *)(iVar5 + 0x28) = (int)param_3;
    if (param_3 == 0) {
      *(u32 *)(iVar5 + 0xc) = uVar1 & 0xfffffffd;
    }
    else {
      *(u64 *)(iVar5 + 0x20) = param_2;
      *(u32 *)(iVar5 + 0xc) = uVar1 | 2;
      *(u8 **)(iVar5 + 0x2c) = (u8 *)&_mips_gp0_value;
      *(u32 *)(iVar5 + 0x30) = param_4;
      if ((*(u32 *)(iVar5 + 0xc) & 1) != 0) {
        FUN_0050e190((u32 *)(int)iVar5);
      }
    }
    uVar4 = FUN_0050e508();
    FUN_0050e000(uVar4);
    uVar2 = 0;
  }
  return uVar2;
}
// FUN_0050EDB8 NONMATCHING
u64 FUN_0050edb8(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  long lVar1;
  u64 uVar2;
  
  lVar1 = FUN_0050d3a0();
  uVar2 = FUN_0050eca8(param_1,param_2,param_3,param_4);
  if (lVar1 != 0) {
    FUN_0050d3f0();
  }
  return uVar2;
}
// FUN_0050EE38 NONMATCHING
void FUN_0050ee38(long param_1,long param_2,long param_3)

{
  u32 uVar1;
  u32 uVar2;
  
  uVar1 = FUN_0052fe98(param_1,0x8ca0000);
  if (param_2 != 0) {
    *(u32 *)param_2 = uVar1;
  }
  if (param_3 != 0) {
    uVar2 = FUN_0052fe98((param_1 -
                         ((long)(int)((u32)uVar1 * 0x8ca0000 >> 0x20) << 0x20 |
                         (u32)uVar1 * 0x8ca0000 & 0xffffffff)) * 1000000,0x8ca0000);
    *(u32 *)param_3 = uVar2;
  }
  return;
}
// FUN_0050EEE0 NONMATCHING
long FUN_0050eee0(int param_1,u32 param_2)

{
  u32 uVar1;
  long lVar2;
  
  uVar1 = (param_2 & 0xffffffff) * 0x8ca0000;
  lVar2 = FUN_0052fe98((long)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff,1000000);
  return (u32)(u32)(param_1 * 0x8ca0000) + lVar2;
}
// FUN_0050EF50 NONMATCHING
float FUN_0050ef50(u32 param_1)

{
  float fVar1;
  
  if ((long)param_1 < 0) {
    fVar1 = (float)FUN_0052eb60(param_1 & 1 | param_1 >> 1);
    fVar1 = fVar1 + fVar1;
  }
  else {
    fVar1 = (float)FUN_0052eb60();
  }
  return 1.47456e+08 / fVar1;
}
// FUN_0050EFE0 NONMATCHING
u64 FUN_0050efe0(void)

{
  u32 *puVar1;
  u32 *puVar2;
  int iVar3;
  
  iVar3 = 0x3f;
  DAT_0096d7c0 = (u32 *)((u32)(&DAT_0096d3c0));
  puVar2 = (u32 *)(&DAT_0096d7c0);
  puVar1 = &DAT_0096d7b0;
  do {
    *puVar1 = (u32)(puVar2);
    iVar3 = iVar3 + -1;
    puVar1 = puVar1 + -4;
    puVar2 = puVar2 + -4;
  } while (-1 < iVar3);
  DAT_0096d7b0 = 0;
  return 0;
}
// FUN_0050F030 NONMATCHING
long FUN_0050f030(u32 param_1,u64 param_2,u64 param_3,u32 *param_4)

{
  u32 *puVar1;
  long lVar2;
  
  lVar2 = (*(code *)param_4[2])((int)param_4 << 4 | param_1 & 0xfe | 1,param_2,param_3,param_4[3]);
  if (lVar2 == 0) {
    lVar2 = -1;
    puVar1 = param_4;
    *param_4 = (u32)(DAT_0096d7c0);
    DAT_0096d7c0 = (u32 *)((u32)(puVar1));
    param_4[1] = 0;
  }
  return lVar2;
}
// FUN_0050F090 NONMATCHING
u32 FUN_0050f090(u64 param_1,long param_2,u32 param_3)

{
  u32 *puVar1;
  u32 *puVar2;
  u32 uVar3;
  long lVar4;
  
  if (param_2 == 0) {
    uVar3 = 0x80000016;
  }
  else {
    lVar4 = FUN_0050d3a0();
    puVar1 = (u32 *)(DAT_0096d7c0);
    if (DAT_0096d7c0 == (u32 *)0x0) {
      if (lVar4 != 0) {
        FUN_0050d3f0();
      }
      uVar3 = 0x80008005;
    }
    else {
      DAT_0096d7c0 = (u32 *)*DAT_0096d7c0;
      uVar3 = FUN_0050e648();
      if ((int)uVar3 < 0) {
        puVar2 = puVar1;
        *puVar1 = (u32)(DAT_0096d7c0);
        DAT_0096d7c0 = (u32 *)((u32)(puVar2));
        puVar1[1] = 0;
        if (lVar4 != 0) {
          FUN_0050d3f0();
        }
      }
      else {
        puVar1[2] = (int)param_2;
        puVar1[3] = param_3;
        puVar1[1] = uVar3;
        FUN_0050edb8((u64)uVar3,(u64)param_1,(u64)0x50f030,(u64)(u32)puVar1);
        FUN_0050e900(uVar3);
        if (lVar4 != 0) {
          FUN_0050d3f0();
        }
        uVar3 = (int)puVar1 << 4 | uVar3 & 0xfe | 1;
      }
    }
  }
  return uVar3;
}
// FUN_0050F1C0 NONMATCHING
u32 FUN_0050f1c0(u64 param_1,long param_2,u32 param_3)

{
  u32 *puVar1;
  u32 *puVar2;
  u32 uVar3;
  
  puVar1 = (u32 *)(DAT_0096d7c0);
  if (param_2 == 0) {
    uVar3 = 0x80000016;
  }
  else if (DAT_0096d7c0 == (u32 *)0x0) {
    uVar3 = 0x80008005;
  }
  else {
    DAT_0096d7c0 = (u32 *)*DAT_0096d7c0;
    uVar3 = FUN_0050e5d8();
    if ((int)uVar3 < 0) {
      puVar2 = puVar1;
      *puVar1 = (u32)(DAT_0096d7c0);
      DAT_0096d7c0 = (u32 *)((u32)(puVar2));
      puVar1[1] = 0;
    }
    else {
      puVar1[2] = (int)param_2;
      puVar1[3] = param_3;
      puVar1[1] = uVar3;
      FUN_0050eca8((u32)uVar3,(u64)param_1,(long)0x50f030,(u32)(u32)puVar1);
      FUN_0050e850(uVar3);
      uVar3 = (int)puVar1 << 4 | uVar3 & 0xfe | 1;
    }
  }
  return uVar3;
}
// FUN_0050F2B0 NONMATCHING
u32 FUN_0050f2b0(u32 param_1)

{
  u32 *puVar1;
  u32 uVar2;
  long lVar3;
  u32 *puVar4;
  
  puVar4 = (u32 *)((param_1 >> 8) * 0x10);
  lVar3 = FUN_0050d3a0();
  if (((int)param_1 < 0) || (((param_1 ^ puVar4[1]) & 0xff) != 0)) {
    if (lVar3 != 0) {
      FUN_0050d3f0();
    }
    uVar2 = 0x80008002;
  }
  else {
    FUN_0050e750(puVar4[1]);
    puVar1 = puVar4;
    *puVar4 = (u32)(DAT_0096d7c0);
    DAT_0096d7c0 = (u32 *)((u32)(puVar1));
    puVar4[1] = 0;
    uVar2 = 0;
    if (lVar3 != 0) {
      FUN_0050d3f0();
      uVar2 = 0;
    }
  }
  return uVar2;
}
// FUN_0050F358 NONMATCHING
long FUN_0050f358(u32 param_1)

{
  u32 *puVar1;
  long lVar2;
  u32 *puVar3;
  
  puVar3 = (u32 *)((param_1 >> 8) * 0x10);
  if (((int)param_1 < 0) || (((param_1 ^ puVar3[1]) & 0xff) != 0)) {
    lVar2 = -0x7fff7ffe;
  }
  else {
    lVar2 = FUN_0050e690(puVar3[1]);
    if (lVar2 == 0) {
      puVar1 = puVar3;
      *puVar3 = (u32)(DAT_0096d7c0);
      DAT_0096d7c0 = (u32 *)((u32)(puVar1));
      puVar3[1] = 0;
    }
  }
  return lVar2;
}
// FUN_0050F3D0 NONMATCHING
void FUN_0050f3d0(void)

{
  DAT_00780b70 = 0;
  DAT_00780b74 = 0;
  FUN_00521408(0x96d7c8,0,0x200);
  return;
}
// FUN_0050F478 NONMATCHING
u32 FUN_0050f478(u32 param_1,u32 param_2,u32 param_3)

{
  u32 uVar1;
  u32 uVar2;
  long lVar3;
  u32 *puVar4;
  
  puVar4 = (u32 *)(DAT_00780b70);
  uVar1 = DAT_00780b74;
  if ((int)param_1 < 0) {
    param_1 = param_1 & 0x7fffffff;
    puVar4 = &DAT_0096d7c8;
    uVar1 = 0x20;
  }
  if (param_1 < uVar1) {
    lVar3 = FUN_0050d3a0();
    puVar4 = puVar4 + param_1 * 4;
    *puVar4 = param_2;
    puVar4[1] = param_3;
    puVar4[2] = (u32)((u8 *)&_mips_gp0_value);
    if (lVar3 != 0) {
      FUN_0050d3f0();
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80000069;
  }
  return uVar2;
}
// FUN_0050F588 NONMATCHING
u8 * FUN_0050f588(long param_1,u64 param_2)

{
  int *piVar1;
  int iVar2;
  u8 *puVar3;
  
  puVar3 = (u8 *)((u8 *)&_mips_gp0_value);
  iVar2 = DAT_00780b74;
  piVar1 = (int *)(DAT_00780b70);
  if (param_1 != 0) {
    iVar2 = 0x20;
    piVar1 = (int *)(&DAT_0096d7c8);
  }
  if (0 < iVar2) {
    do {
      if (*piVar1 != 0) {
        puVar3 = (u8 *)piVar1[2];
        (*(code *)*piVar1)(param_2,piVar1[1]);
      }
      iVar2 = iVar2 + -1;
      piVar1 = piVar1 + 4;
    } while (iVar2 != 0);
  }
  return puVar3;
}
// FUN_0050F630 NONMATCHING
u32 FUN_0050f630(u32 param_1)

{
  u32 uVar1;
  long lVar2;
  
  lVar2 = FUN_00510148(1);
  uVar1 = 0;
  if (lVar2 == 0) {
    lVar2 = FUN_0050d3a0();
    uVar1 = (u32)(DAT_0096da00);
    DAT_0096da04 = (u32)((u8 *)&_mips_gp0_value);
    DAT_0096da00 = (u32 *)(param_1);
    if (lVar2 != 0) {
      FUN_0050d3f0();
    }
  }
  return uVar1;
}
// FUN_0050F698 NONMATCHING
void FUN_0050f698(int *param_1)

{
  DAT_00780be0 = *param_1;
  DAT_00780be4 = (u32 *)(DAT_00780be0);
  if (DAT_00780be0 == 0xb) {
    DAT_00780bb4 = 0;
  }
  else {
    iSignalSema(DAT_00780ba8);
    if ((DAT_00780b94 == 0) || (DAT_0096da00 == 0)) {
      DAT_00780bb4 = 0;
    }
    else {
      iSignalSema(DAT_00780ba0);
    }
  }
  DAT_00780be0 = 0;
  return;
}
// FUN_0050F738 NONMATCHING
void FUN_0050f738(void)

{
  do {
    WaitSema(DAT_00780ba0);
    if (DAT_00780be0 == -1) {
      DAT_00780bb4 = 0;
      DAT_00780be0 = 0;
      DAT_00780b94 = 0;
      DAT_0096da14 = 0;
      ExitDeleteThread();
    }
    if (0 < ram0x00780b90) {
      FUN_00505e48(0x7be0d8,DAT_0096da00,DAT_00780be4);
    }
    if ((DAT_0096da00 != (u32 *)0x0) && (DAT_00780be4 != 0)) {
      (*(code)DAT_0096da00)(DAT_00780be4);
    }
    DAT_00780bb4 = 0;
  } while( true );
}
// FUN_0050F960 NONMATCHING
void FUN_0050f960(void)

{
  u8 auStack_60 [4];
  u32 uStack_5c;
  u32 uStack_58;
  char *pcStack_4c;
  
  if (((DAT_00780ba8 == -1) || (DAT_00780bac == -1)) || (DAT_00780bb0 == -1)) {
    uStack_5c = 1;
    pcStack_4c = s_SceCdNcmdSema_007be118;
    uStack_58 = 1;
    DAT_00780ba8 = CreateSema(auStack_60);
    pcStack_4c = s_SceCdScmdSema_007be128;
    DAT_00780bac = CreateSema(auStack_60);
    pcStack_4c = s_SceCdRcmdSema_007be138;
    DAT_00780bb0 = CreateSema(auStack_60);
    pcStack_4c = s_SceCdCallbackSema_007be148;
    uStack_58 = 0;
    DAT_00780ba0 = CreateSema(auStack_60);
    DAT_00780bb4 = 0;
  }
  return;
}
// FUN_0050FA48 NONMATCHING
void FUN_0050fa48(void)

{
  long lVar1;
  
  if (DAT_00780b94 != 0) {
    DAT_00780be0 = 0xffffffff;
    SignalSema(DAT_00780ba0);
  }
  DeleteSema(DAT_00780ba8);
  DeleteSema(DAT_00780bac);
  DeleteSema(DAT_00780bb0);
  DeleteSema(DAT_00780ba0);
  lVar1 = FUN_0050d3a0();
  FUN_005064a8(0xffffffff80000012);
  if (lVar1 == 0) {
    return;
  }
  FUN_0050d3f0();
  return;
}
// FUN_0050FAE8 NONMATCHING
u32 FUN_0050fae8(u32 param_1,u32 param_2)

{
  u32 uVar1;
  long lVar2;
  
  if (DAT_00780bc8 < 0) {
  }
  lVar2 = FUN_0050d3a0();
  uVar1 = (u32)(DAT_0096da08);
  DAT_0096da0c = (u32)((u8 *)&_mips_gp0_value);
  DAT_0096da08 = (u32 *)(param_1);
  DAT_0096da10 = (u32 *)(param_2);
  if (lVar2 != 0) {
    FUN_0050d3f0();
  }
  return uVar1;
}
// FUN_0050FB68 NONMATCHING
void FUN_0050fb68(void)

{
  if ((DAT_0096da08 != (u32 *)0x0) && (DAT_00780ba4 == 0)) {
    (*(void (*)(u32 *))DAT_0096da08)(DAT_0096da10);
  }
  return;
}
// FUN_0050FBC0 NONMATCHING
u32 FUN_0050fbc0(void)

{
  long lVar1;
  
  DAT_00780ba4 = 1;
  lVar1 = FUN_0050d3a0();
  FUN_00506430(0xffffffff80000012,0x50fb68,0);
  if (lVar1 != 0) {
    FUN_0050d3f0();
  }
  DAT_00780ba4 = 0;
  DAT_00780bc8 = 1;
  return 1;
}
// FUN_0050FC38 NONMATCHING
u32 FUN_0050fc38(u64 *param_1,char *param_2,u32 param_3)

{
  char cVar1;
  u64 uVar2;
  u64 uVar3;
  u64 uVar4;
  u32 uVar5;
  int iVar6;
  long lVar7;
  
  FUN_0050f960();
  iVar6 = PollSema(DAT_00780ba8);
  if (DAT_00780ba8 == iVar6) {
    DAT_00780b9c = 1;
    lVar7 = FUN_00510148(1);
    if (lVar7 == 0) {
      FUN_005068a8(0);
      if (DAT_00780bcc < 0) {
        while( true ) {
          while (lVar7 = FUN_00507050(0x96dc00,0xffffffff80000597,0), lVar7 < 0) {
            if (0 < ram0x00780b90) {
              FUN_00505e48(0x7be160);
            }
            iVar6 = 0x100000;
            do {
              iVar6 = iVar6 + -1;
            } while (iVar6 != -1);
          }
          iVar6 = 0x100000;
          if (DAT_0096dc24 != 0) break;
          do {
            iVar6 = iVar6 + -1;
          } while (iVar6 != -1);
        }
        DAT_00780bcc = 0;
      }
      DAT_0096daa4 = *param_2;
      iVar6 = 0;
      if (DAT_0096daa4 != '\0') {
        for (iVar6 = 1;
            (iVar6 < 0x100 &&
            (cVar1 = param_2[iVar6], (&DAT_0096daa4)[iVar6] = cVar1, cVar1 != '\0'));
            iVar6 = iVar6 + 1) {
        }
      }
      if (iVar6 == 0x100) {
        DAT_0096dba3 = 0;
      }
      if (0 < ram0x00780b90) {
        FUN_00505e48(0x7be180,0x96daa4);
      }
      DAT_0096dba4 = (u32)(&DAT_0096da80);
      DAT_0096dba8 = param_3;
      FUN_005067f8(0x96da80,300);
      lVar7 = FUN_00507230(0x96dc00,0,0,0x96da80,300,0x96dbc0,4,0);
      uVar4 = DAT_2096da98;
      uVar3 = DAT_2096da90;
      uVar2 = DAT_2096da88;
      if (-1 < lVar7) {
        *param_1 = DAT_2096da80;
        param_1[1] = uVar2;
        param_1[2] = uVar3;
        param_1[3] = uVar4;
        *(u32 *)(param_1 + 4) = DAT_2096daa0;
        if (((0 < ram0x00780b90) && (FUN_00505e48(0x7be198,param_1 + 1), 0 < ram0x00780b90)) &&
           (FUN_00505e48(0x7be1a8,*(u32 *)((int)param_1 + 4)), 0 < ram0x00780b90)) {
          FUN_00505e48(0x7be1b8,*(u32 *)param_1);
        }
        uVar5 = DAT_2096dbc0;
        SignalSema(DAT_00780ba8);
        return uVar5;
      }
    }
    SignalSema(DAT_00780ba8);
  }
  return 0;
}
// FUN_0050FF38 NONMATCHING
void FUN_0050ff38(u64 param_1,u64 param_2)

{
  FUN_0050fc38((u64 *)param_1,(char *)param_2,0);
  return;
}
// FUN_0050FF58 NONMATCHING
u32 FUN_0050ff58(u64 param_1)

{
  int iVar1;
  long lVar2;
  
  FUN_0050f960();
  iVar1 = PollSema(DAT_00780ba8);
  if (DAT_00780ba8 == iVar1) {
    DAT_00780b9c = (u32)param_1;
    lVar2 = FUN_00510148(1);
    if (lVar2 == 0) {
      FUN_005068a8(0);
      if (-1 < DAT_00780bbc) {
        return 1;
      }
      while( true ) {
        while (lVar2 = FUN_00507050(0x781d50,0xffffffff80000595,0), lVar2 < 0) {
          if (0 < ram0x00780b90) {
            FUN_00505e48(0x7be1f8);
          }
          iVar1 = 0x100000;
          do {
            iVar1 = iVar1 + -1;
          } while (iVar1 != -1);
        }
        if (DAT_00781d74 != 0) break;
        iVar1 = 0x100000;
        do {
          iVar1 = iVar1 + -1;
        } while (iVar1 != -1);
      }
      DAT_00780bbc = 0;
      return 1;
    }
    SignalSema(DAT_00780ba8);
  }
  else if (0 < ram0x00780b90) {
    FUN_00505e48(0x7be1d0,param_1,DAT_00780b9c);
    return 0;
  }
  return 0;
}
// FUN_005100B0 NONMATCHING
u32 FUN_005100b0(void)

{
  u32 uVar1;
  long lVar2;
  
  lVar2 = FUN_0050ff58(2);
  if (lVar2 == 0) {
    uVar1 = 0;
  }
  else {
    lVar2 = FUN_00507230(0x781d50,0xe,0,0,0,0x780c00,4,0);
    uVar1 = DAT_20780c00;
    if (lVar2 < 0) {
      SignalSema(DAT_00780ba8);
      uVar1 = 0;
    }
    else {
      SignalSema(DAT_00780ba8);
    }
  }
  return uVar1;
}
// FUN_00510148 NONMATCHING
u32 FUN_00510148(long param_1)

{
  u32 uVar1;
  long lVar2;
  
  if (param_1 == 0) {
    if (0 < ram0x00780b90) {
      FUN_00505e48(0x7be210);
    }
    while ((DAT_00780bb4 != 0 || (lVar2 = FUN_00507430(0x781d50), lVar2 != 0))) {
      FUN_005041d8(4000);
    }
    return 0;
  }
  uVar1 = 1;
  if (DAT_00780bb4 == 0) {
    lVar2 = FUN_00507430(0x781d50);
    uVar1 = 1;
    if (lVar2 == 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}
// FUN_005101E8 NONMATCHING
u64 FUN_005101e8(long param_1)

{
  long lVar1;
  u64 uVar2;
  
  if (param_1 == 0) {
    if (0 < ram0x00780b90) {
      FUN_00505e48(0x7be220);
    }
    while( true ) {
      lVar1 = FUN_00507430(0x782700);
      uVar2 = 0;
      if (lVar1 == 0) break;
      FUN_005041d8(4000);
    }
  }
  else {
    uVar2 = FUN_00507430(0x782700);
  }
  return uVar2;
}
// FUN_00510258 NONMATCHING
u32 FUN_00510258(u64 param_1)

{
  int iVar1;
  long lVar2;
  
  FUN_0050f960();
  iVar1 = PollSema(DAT_00780bac);
  if (DAT_00780bac == iVar1) {
    DAT_00780b98 = (u32)param_1;
    lVar2 = FUN_005101e8(1);
    if (lVar2 == 0) {
      FUN_005068a8(0);
      if (-1 < DAT_00780bd4) {
        return 1;
      }
      while( true ) {
        while (lVar2 = FUN_00507050(0x782700,0xffffffff80000593,0), lVar2 < 0) {
          if (0 < ram0x00780b90) {
            FUN_00505e48(0x7be258);
          }
          iVar1 = 0x100000;
          do {
            iVar1 = iVar1 + -1;
          } while (iVar1 != -1);
        }
        if (DAT_00782724 != 0) break;
        iVar1 = 0x100000;
        do {
          iVar1 = iVar1 + -1;
        } while (iVar1 != -1);
      }
      DAT_00780bd4 = 0;
      return 1;
    }
    SignalSema(DAT_00780bac);
  }
  else if (0 < ram0x00780b90) {
    FUN_00505e48(0x7be230,param_1,DAT_00780b98);
    return 0;
  }
  return 0;
}
