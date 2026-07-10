#include "mw_harvest_compat.h"
#include "sce/libmc2.h"
#include "Utils.h"

/* auto-extern (generated) */
extern char s_MC2SOCKET_007be690[];
extern u32 DAT_007827d8;

// Fix EE math function return types
#define FUN_00531170_real FUN_00531170
#define FUN_00531170(a,b) ((unsigned long long (*)(unsigned long long, unsigned long long))FUN_00531170_real)(a,b)
#define FUN_005311c8_real FUN_005311c8
#define FUN_005311c8(a,b) ((unsigned long long (*)(unsigned long long, unsigned long long))FUN_005311c8_real)(a,b)
#define FUN_00531230_real FUN_00531230
#define FUN_00531230(a,b) ((unsigned long long (*)(unsigned long long, unsigned long long))FUN_00531230_real)(a,b)
#define FUN_00531480_real FUN_00531480
#define FUN_00531480(a,b) ((unsigned long long (*)(unsigned long long, unsigned long long))FUN_00531480_real)(a,b)
#define FUN_005316d0_real FUN_005316d0
#define FUN_005316d0(a,b) ((long long (*)(unsigned long long, unsigned long long))FUN_005316d0_real)(a,b)
// Helper function to read a u32 from an absolute address
static u32 read_u32(unsigned long addr) { return *(volatile u32 *)addr; }

u32 FUN_00516a48(u64 param_1);
u32 FUN_0051d308(u32 param_1,u32 param_2,int *param_3,u8 *param_4,
            u64 param_5);
u32 FUN_0051c700(u32 param_1);
u32 FUN_0051aa90(u64 param_1,u64 param_2,int param_3,int param_4);
u32 FUN_0051b1b0(int param_1);
u64 FUN_0051aa48(int param_1,u64 param_2,int param_3,int param_4);
u32 FUN_0051ab98(u32 param_1,int *param_2,int *param_3);
u32 FUN_0051bd10(int param_1,int param_2,int param_3,int param_4);
u32 FUN_0051a180(u64 param_1, int *param_2);
u32 FUN_0051c770(u32 *param_1,u32 param_2,u32 param_3);
u64 FUN_0051a418(int param_1,u64 param_2,int param_3,int param_4);
u64 FUN_0051a458(int param_1,u64 param_2,int param_3,int param_4);
long FUN_00519ef8(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_0051cad0(int param_1);
u64 FUN_0051bf40(int param_1,u64 param_2,u32 param_3,u64 param_4);
u32 FUN_0051cdd8(int param_1);
void FUN_0051e118(u8 *param_1,int param_2);
u64 FUN_0051aa00(int param_1,u64 param_2,int param_3,int param_4);
bool FUN_0051b2c0(int param_1);
bool FUN_0051b3b0(int param_1);
u32 FUN_0051fe90(u64 param_1,u32 param_2);
u32 FUN_0051b4a0(int param_1);
u64 FUN_0051a1a0(u64 param_1);
u64 FUN_0051a1c0(u64 param_1);
u32 FUN_0051ab50(int param_1,int param_2);
bool FUN_0051c280(int param_1);
bool FUN_0051c0c0(int param_1);
u32 FUN_0051b5f0(int param_1,u64 *param_2);
u32 FUN_0051a1e0(u64 param_1);
u32 FUN_0051fa20(u64 param_1);
void FUN_0051d588(int param_1,...);
u32 FUN_0051afd8(int param_1,u64 *param_2);
u32 FUN_0051ab08(int param_1,int param_2);
long FUN_00519728(u64 param_1,u64 param_2,long param_3);
long FUN_00517be8(u64 param_1,u64 param_2,long param_3);
long FUN_00519d70(u64 param_1,u64 param_2,u16 param_3);
u64 FUN_005210d8(u32 param_1,u32 param_2,u32 param_3);
bool FUN_0051a2f8(u64 param_1);
u64 FUN_0051b8f0(int param_1,u64 param_2,u32 param_3,u64 param_4);
long FUN_0051e178(u64 param_1,int param_2,int param_3);
u32 FUN_0051af70(int param_1,u32 param_2,u32 param_3);
u32 * FUN_005209c0(u64 param_1,int param_2);
bool FUN_0051bbd8(int param_1,u32 param_2);
u64 FUN_0051a498(int param_1);
u32 FUN_0051af98(int param_1,u64 *param_2);
u64 FUN_0051b8d0(int param_1,u64 param_2,u32 param_3,u32 param_4);
u32 FUN_00520410(int param_1,code *param_2);
u32 FUN_0051c8a0(u32 param_1);
u64 FUN_0051a9e0(u64 param_1,int param_2,u64 param_3,int param_4);
extern u32 ram0x007827d8;
extern u32 ram0x00782b00;
extern u32 *ram0x00782b18;
extern u32 register0x00000020;
extern char s_dbcman___SendData2_BUSY_007be898[];
extern char s_sceDbcSendData2__rpc_error_007be8b8[];
extern char s_Infinity_007beac8[];
extern char s_sceMc2_sema_subs_007be668[];
extern char s_sceDbc_sema_007be710[];
extern u32 DAT_007827fe;
extern u32 DAT_007be5f0;
extern u32 DAT_007be5f1;
extern u32 DAT_007be5f8;
extern u32 DAT_007be5f9;
extern u32 DAT_007be5fa;
extern u32 DAT_00996f40;
extern u32 DAT_00996f48;
extern u32 DAT_00996f50;
extern u32 DAT_00996f58;
extern u32 DAT_00996f60;
extern u32 DAT_00996f68;
extern u32 DAT_00996f70;
extern u32 DAT_00996f78;
extern void* PTR_DAT_007be628;
extern u32 DAT_007827e0;
extern u32 DAT_007827e8;
extern u32 DAT_007827f0;
extern u32 DAT_007827f8;
extern u32 DAT_007827fc;
extern u32 DAT_00782808;
extern u32 DAT_0078280a;
extern u32 DAT_0078280c;
extern u32 DAT_0078280e;
extern u32 DAT_00782810;
extern u32 DAT_00782814;
extern u32 DAT_00782818;
extern u32 DAT_0078281c;
extern u32 DAT_00782820;
extern u32 DAT_00782824;
extern u32 DAT_00782828;
extern u32 DAT_0078282c;
extern u32 DAT_007828b0;
extern u32 DAT_0078292c;
extern u32 DAT_00782930;
extern u32 DAT_00782931;
extern u32 DAT_00782934;
extern u32 DAT_00782938;
extern u32 DAT_0078293c;
extern u32 DAT_00782944;
extern u32 DAT_00782948;
extern u32 DAT_0078294c;
extern u32 DAT_00782950;
extern u32 DAT_00782954;
extern u32 DAT_00782958;
extern u32 DAT_0078295c;
extern u32 DAT_00782960;
extern u32 DAT_00782ae8;
extern u32 DAT_00782aec;
extern u32 DAT_00782b04;
extern u32 DAT_00782b1c;
extern u32 DAT_00782b20;
extern u32 DAT_00782b24;
extern u32 DAT_00782b28;
extern u32 DAT_00782b2c;
extern u32 DAT_00782b30;
extern u32 DAT_00782b38;
extern u32 DAT_00782b3c;
extern u32 DAT_00782b80;
extern u32 DAT_00782b84;
extern u32 DAT_00782b88;
extern u32 DAT_00782b8c;
extern u32 DAT_00782b90;
extern u32 DAT_00782b94;
extern u32 DAT_00782b98;
extern u32 DAT_00782bc0;
extern u32 DAT_00782bc4;
extern u32 DAT_00782bc8;
extern u32 DAT_00782bcc;
extern u32 DAT_00782bd0;
extern u32 DAT_00782bd4;
extern u32 DAT_00782bd8;
extern u32 DAT_00782bdc;
extern u32 DAT_00782c00;
extern u32 DAT_00782c04;
extern u32 DAT_00782c08;
extern u32 DAT_00782c0c;
extern u32 DAT_00782c10;
extern u32 DAT_00782c14;
extern u32 DAT_00782c18;
extern u32 DAT_00782f40;
extern u32 DAT_00782f44;
extern u32 DAT_00783348;
extern u32 DAT_00783350;
extern u32 DAT_00783358;
extern u32 DAT_00783360;
extern u32 DAT_00783368;
extern u32 DAT_00783370;
extern u32 DAT_007be608;
extern u32 DAT_007be609;
extern u32 DAT_007be610;
extern u32 DAT_007be618;
extern u32 DAT_007be620;
extern u32 DAT_007beae0;
extern u32 DAT_007beae1;
extern u32 DAT_007beae8;
extern u32 DAT_007beaf0;
extern u32 DAT_007beaf8;
extern u32 DAT_007beb60;
extern u32 DAT_007beb78;
extern u32 DAT_007bec40;
extern u32 DAT_007bec60;
extern u32 DAT_0096f140;
extern u32 DAT_0096f144;
extern u32 DAT_0096f148;
extern u32 DAT_0096f14c;
extern u32 DAT_0096f150;
extern u32 DAT_0096f154;
extern u32 DAT_0096f158;
extern u32 DAT_0096f660;
extern u32 DAT_0096f664;
extern u32 DAT_0096f668;
extern u32 DAT_0096f66c;
extern u32* DAT_0097b680;
extern u32 DAT_0097b688;
extern u32 DAT_0097b788;
extern u32 DAT_0097bb84;
extern u32 DAT_0097bb88;
extern u32 DAT_0097bf84;
extern u32 DAT_0097bf88;
extern u32 DAT_0097bf8c;
extern u32 DAT_0097bf90;
extern u32 DAT_0097bf91;
extern u32 DAT_0097c010;
extern u32 DAT_0097c014;
extern u32 DAT_0097c018;
extern u32 DAT_0097c01c;
extern u32 DAT_0097c8c0;
extern u32 DAT_0097c8c2;
extern u32 DAT_0097c8c4;
extern u32 DAT_0097c8c8;
extern u32 DAT_0097c8d0;
extern u32 DAT_0097c8d4;
extern u32 DAT_0097c8d8;
extern u32 DAT_0097c8e0;
extern u32 DAT_0097c900;
extern u32 DAT_0097c901;
extern u32 DAT_0097cac0;
extern u32 DAT_0097cac2;
extern u32 DAT_0097cac4;
extern u32 DAT_0097cac8;
extern u32 DAT_0097cad0;
extern u32 DAT_0097cad4;
extern u32 DAT_0097cad8;
extern u32 DAT_0097cae0;
extern u32 DAT_0097cb00;
extern u32 DAT_0097cb01;
extern u32 DAT_0097cb02;
extern u32 DAT_0097ccc0;
extern u32 DAT_0097ccc4;
extern u32 DAT_0097ccc8;
extern u32 DAT_0097cccc;
extern u32 DAT_0097ccd0;
extern u32 DAT_00984d00;
extern u32 DAT_00985500;
extern u32 DAT_00985508;
extern u32 DAT_0098550c;
extern u32 DAT_00985510;
extern u32 DAT_00985514;
extern u32 DAT_00985518;
extern u32 DAT_0098551c;
extern u32 DAT_00985524;
extern u32 DAT_00985580;
extern u32 DAT_00985584;
extern u32 DAT_00985588;
extern u32 DAT_0098558c;
extern u32 DAT_00985590;
extern u32 DAT_00985594;
extern u32 DAT_00985598;
extern u32 DAT_0098559c;
extern u32 DAT_009855a0;
extern u32 DAT_009855a4;
extern u32 DAT_009855a8;
extern u32 DAT_009855ac;
extern u32 DAT_009855c0;
extern u32 DAT_009855c8;
extern u32 DAT_00985640;
extern u32 DAT_00985ec0;
extern u32 DAT_00996764;
extern u32 DAT_009967b4;
extern u32 DAT_009967dc;
extern u32 DAT_00996840;
extern u32 DAT_00996844;
extern u32 DAT_00996848;
extern u32 DAT_0099684c;
extern u32 DAT_00996850;
extern u32 DAT_00996854;
extern u32 DAT_00996864;
extern u32 DAT_00996868;
extern u32 DAT_0099686c;
extern u32 DAT_009968cc;
extern u32 DAT_009968d0;
extern u32 DAT_00996900;
extern u32 DAT_00996904;
extern u32 DAT_00996908;
extern u32 DAT_0099690c;
extern u32 DAT_00996950;
extern u32 DAT_00996dc0;
extern u32 DAT_00996dc4;
extern u32 DAT_00996dc8;
extern u32 DAT_00996fc0;
extern u32 DAT_00996fc8;
extern u32 DAT_00996fd0;
extern u32 DAT_00996fd8;
extern u32 DAT_00996fe0;
extern u32 DAT_00996fe8;
extern u32 DAT_00996ff0;
extern u32 DAT_00996ffc;
extern u32 DAT_00997000;
extern u32 DAT_009acc20;
extern u64 FUN_00523c60();
extern u64 FUN_00523d40();
extern u8 LAB_0051f9e0;
extern u8 LAB_00523cc0;
extern u8 LAB_00523da8;
extern void* PTR_DAT_00782f30;
extern void* PTR_DAT_00782f48;
extern void* PTR_DAT_00782f4c;
extern void* PTR_DAT_007beb30;
extern void* PTR_PTR_00782f50;
extern void* PTR_PTR_00782f54;
extern u32 _DAT_00783350;
extern u32 _DAT_00996ff8;

typedef struct SceMc2SemaParam
{
    s32 count;
    s32 maxCount;
    s32 initCount;
    s32 waitThreads;
    u32 attributes;
    u32 option;
} SceMc2SemaParam;

typedef struct SceMc2ThreadParam
{
    s32 status;
    void (*function)(void*);
    void* stack;
    s32 stackSize;
    void* gpReg;
    s32 initialPriority;
    s32 currentPriority;
    u32 attributes;
    u32 option;
} SceMc2ThreadParam;

extern s32 func_00502f60(SceMc2ThreadParam* thread);
extern void func_00502f70(s32 threadId);
extern s32 func_00502fb0(s32 threadId);
extern s32 func_00503160(SceMc2SemaParam* semaphore);
extern void func_00503170(s32 semaphoreId);
extern void func_005042a0(s32 threadId, void* arg);
extern void func_00505e48(const char* message);
extern void func_005145f8(void* arg);
extern void func_00514928(s32 arg0, s32 arg1);
extern void func_005153a0(void);
extern void func_00515400(s32 socketId);
extern void func_0051a140(void);
extern s32 func_0051ae68(void);
extern void func_0051aef8(void);
extern s32 func_0051c130(void);
extern s32 func_0051c330(s32 socketId);
extern s32 D_007827D8[];
extern s32 D_0096F144[];
extern s32 D_0096F660[];
extern u8 D_0096F680[];
extern u8 D_007BE4F0[];
extern char D_007BE548[];

int func_00513290(void);

// FUN_005130e8 NONMATCHING
int sceMc2Init(int mode)
{
    SceMc2SemaParam semaphore;
    SceMc2ThreadParam thread;

    if (D_007827D8[0] == 1)
    {
        func_00513290();
    }

    D_0096F660[0] = -1;
    D_0096F660[1] = -1;
    D_0096F660[2] = -1;
    D_0096F660[3] = -1;

    semaphore.maxCount = 0x7f;
    semaphore.initCount = 1;
    semaphore.option = (u32)D_007BE4F0;
    D_0096F660[3] = func_00503160(&semaphore);
    if (D_0096F660[3] < 0)
    {
        goto init_failed;
    }

    semaphore.option = (u32)&D_007BE4F0[0x18];
    D_0096F660[1] = func_00503160(&semaphore);
    if (D_0096F660[1] < 0)
    {
        goto init_failed;
    }

    semaphore.option = (u32)&D_007BE4F0[0x30];
    D_0096F660[2] = func_00503160(&semaphore);
    if (D_0096F660[2] < 0)
    {
        goto init_failed;
    }

    D_0096F144[0] = 0;
    thread.function = func_005145f8;
    thread.stack = D_0096F680;
    thread.stackSize = 0xc000;
    thread.gpReg = (void*)0x007d2cf0;
    thread.initialPriority = 1;
    thread.option = (u32)&D_007BE4F0[0x40];
    D_0096F660[0] = func_00502f60(&thread);
    if (D_0096F660[0] < 0)
    {
        func_00513290();
        return SCE_MC2_ERROR_THREAD_FAILED;
    }

    if (func_0051ae68() == 0)
    {
        goto init_failed;
    }

    func_0051a140();
    func_005153a0();
    func_005042a0(D_0096F660[0], NULL);
    D_007827D8[0] = 1;

    (void)mode;
    return 0;

init_failed:
    func_00513290();
    return SCE_MC2_ERROR_INIT_FAILED;
}

// FUN_00513290 NONMATCHING
int func_00513290(void)
{
    s32 result;

    if (D_007827D8[0] == 0)
    {
        return SCE_MC2_ERROR_NOT_INITIALIZED;
    }

    if (D_0096F144[0] != 0)
    {
        func_00514928(0, 0);
    }

    if (D_0096F660[0] >= 0)
    {
        result = func_00502fb0(D_0096F660[0]);
        if (result < 0)
        {
            func_00505e48(D_007BE548);
        }

        func_00502f70(D_0096F660[0]);
    }

    if (D_0096F660[1] >= 0)
    {
        func_00503170(D_0096F660[1]);
    }

    if (D_0096F660[2] >= 0)
    {
        func_00503170(D_0096F660[2]);
    }

    if (D_0096F660[3] >= 0)
    {
        func_00503170(D_0096F660[3]);
    }

    func_0051aef8();
    D_007827D8[0] = 0;
    return 0;
}

// FUN_00513368 NONMATCHING
int sceMc2CreateSocket(SceMc2SocketParam* psocket, u_long128* paddr)
{
    s32 socketId;

    if (D_007827D8[0] == 0)
    {
        return SCE_MC2_ERROR_NOT_INITIALIZED;
    }

    if (((u32)(psocket->port - SCE_MC2_PORT_1) >= 2) || (psocket->slot == 0))
    {
        return SCE_MC2_ERROR_INVALID_SOCKET;
    }

    socketId = func_0051c130();
    if (socketId < 0)
    {
        return SCE_MC2_ERROR_SOCKET_UNAVAIL;
    }

    func_00515400(socketId);
    (void)paddr;
    return func_0051c330(socketId);
}

// FUN_005133F8 NONMATCHING
u32 FUN_005133f8(void)

{
  u32 uVar1;
  long lVar2;
  
  lVar2 = FUN_0051c2e8();
  if (lVar2 < 0) {
    uVar1 = 0x81018002;
  }
  else if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else if (DAT_0096f144 == 0) {
    lVar2 = FUN_0051c280(0);
    uVar1 = 0x81018002;
    if (lVar2 != 0) {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x81010010;
  }
  return uVar1;
}
// FUN_00513478 NONMATCHING
long FUN_00513478(u32 param_1,u32 param_2)

{
  long lVar1;
  u8 auStack_70 [8];
  u32 uStack_68;
  u32 uStack_64;
  
  if (ram0x007827d8 == 0) {
    lVar1 = -0x7efe7fff;
  }
  else if (DAT_0096f144 == 0) {
    WaitSema(DAT_0096f66c);
    uStack_68 = param_1;
    uStack_64 = param_2;
    lVar1 = (int)(FUN_0051cdd8((int)(u32)auStack_70));
    if (lVar1 < 0) {
      SignalSema(DAT_0096f66c);
      lVar1 = -0x7efe7ffe;
    }
    else {
      SignalSema(DAT_0096f66c);
    }
  }
  else {
    lVar1 = -0x7efefff0;
  }
  return lVar1;
}
// FUN_00513528 NONMATCHING
u32 FUN_00513528(long param_1)

{
  u32 uVar1;
  
  if (param_1 < 1) {
    uVar1 = 0x81010016;
  }
  else {
    ChangeThreadPriority(DAT_0096f660,param_1);
    uVar1 = 0;
  }
  return uVar1;
}
// FUN_00513560 NONMATCHING
u32 FUN_00513560(long param_1)

{
  u32 uVar1;
  
  if (param_1 < 1) {
    uVar1 = 0x81010016;
  }
  else {
    iChangeThreadPriority(DAT_0096f660,param_1);
    uVar1 = 0;
  }
  return uVar1;
}
// FUN_00513598 NONMATCHING
u32 FUN_00513598(u64 param_1)

{
  u32 uVar1;
  long lVar2;
  
  if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else {
    lVar2 = FUN_0051c2e8(param_1);
    if (lVar2 < 0) {
      uVar1 = 0x81018002;
    }
    else {
      WaitSema(DAT_0096f66c);
      if (DAT_0096f144 == 0) {
        DAT_0096f140 = (u32)lVar2;
        DAT_0096f144 = 3;
        SignalSema(DAT_0096f664);
        SignalSema(DAT_0096f66c);
        uVar1 = 0;
      }
      else {
        SignalSema(DAT_0096f66c);
        uVar1 = 0x81010010;
      }
    }
  }
  return uVar1;
}
// FUN_00513648 NONMATCHING
u32 FUN_00513648(u64 param_1)

{
  u32 uVar1;
  long lVar2;
  
  if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else {
    lVar2 = FUN_0051c2e8(param_1);
    if (lVar2 < 0) {
      uVar1 = 0x81018002;
    }
    else {
      WaitSema(DAT_0096f66c);
      if (DAT_0096f144 == 0) {
        DAT_0096f140 = (u32)lVar2;
        DAT_0096f144 = 4;
        SignalSema(DAT_0096f664);
        SignalSema(DAT_0096f66c);
        uVar1 = 0;
      }
      else {
        SignalSema(DAT_0096f66c);
        uVar1 = 0x81010010;
      }
    }
  }
  return uVar1;
}
// FUN_005136F8 NONMATCHING
u32 FUN_005136f8(u64 param_1,u32 param_2)

{
  u32 uVar1;
  long lVar2;
  
  if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else {
    lVar2 = FUN_0051c2e8(param_1);
    if (lVar2 < 0) {
      uVar1 = 0x81018002;
    }
    else {
      WaitSema(DAT_0096f66c);
      if (DAT_0096f144 == 0) {
        DAT_0096f140 = (u32)lVar2;
        DAT_0096f144 = 2;
        DAT_0096f14c = param_2;
        SignalSema(DAT_0096f664);
        SignalSema(DAT_0096f66c);
        uVar1 = 0;
      }
      else {
        SignalSema(DAT_0096f66c);
        uVar1 = 0x81010010;
      }
    }
  }
  return uVar1;
}
// FUN_005137B8 NONMATCHING
u32 FUN_005137b8(u64 param_1,u64 param_2,u32 param_3)

{
  u32 uVar1;
  long lVar2;
  u32 uVar3;
  
  if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else {
    lVar2 = FUN_0051c2e8(param_1);
    if (lVar2 < 0) {
      uVar1 = 0x81018002;
    }
    else {
      uVar3 = FUN_00524388(param_2);
      if (uVar3 < 0x80) {
        WaitSema(DAT_0096f66c);
        if (DAT_0096f144 == 0) {
          DAT_0096f140 = (u32)lVar2;
          DAT_0096f144 = 0xe;
          FUN_00524270(0x96f55c,param_2);
          DAT_0096f14c = param_3;
          SignalSema(DAT_0096f664);
          SignalSema(DAT_0096f66c);
          uVar1 = 0;
        }
        else {
          SignalSema(DAT_0096f66c);
          uVar1 = 0x81010010;
        }
      }
      else {
        uVar1 = 0x8101005b;
      }
    }
  }
  return uVar1;
}
// FUN_005138B8 NONMATCHING
u32 FUN_005138b8(u64 param_1)

{
  u32 uVar1;
  long lVar2;
  
  if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else {
    lVar2 = FUN_0051c2e8(param_1);
    if (lVar2 < 0) {
      uVar1 = 0x81018002;
    }
    else {
      WaitSema(DAT_0096f66c);
      if (DAT_0096f144 == 0) {
        DAT_0096f140 = (u32)lVar2;
        DAT_0096f144 = 100;
        SignalSema(DAT_0096f664);
        SignalSema(DAT_0096f66c);
        uVar1 = 0;
      }
      else {
        SignalSema(DAT_0096f66c);
        uVar1 = 0x81010010;
      }
    }
  }
  return uVar1;
}
// FUN_00513968 NONMATCHING
u32
FUN_00513968(u64 param_1,u64 param_2,u32 param_3,u32 param_4,
            u32 param_5)

{
  u32 uVar1;
  long lVar2;
  u32 uVar3;
  
  if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else {
    lVar2 = FUN_0051c2e8(param_1);
    if (lVar2 < 0) {
      uVar1 = 0x81018002;
    }
    else {
      uVar3 = FUN_00524388(param_2);
      if (uVar3 < 0x80) {
        WaitSema(DAT_0096f66c);
        if (DAT_0096f144 == 0) {
          DAT_0096f140 = (u32)lVar2;
          DAT_0096f144 = 5;
          FUN_00524270(0x96f55c,param_2);
          DAT_0096f14c = param_3;
          DAT_0096f150 = param_4;
          DAT_0096f154 = param_5;
          SignalSema(DAT_0096f664);
          SignalSema(DAT_0096f66c);
          uVar1 = 0;
        }
        else {
          SignalSema(DAT_0096f66c);
          uVar1 = 0x81010010;
        }
      }
      else {
        uVar1 = 0x8101005b;
      }
    }
  }
  return uVar1;
}
// FUN_00513A88 NONMATCHING
u32
FUN_00513a88(u64 param_1,u64 param_2,u32 param_3,u32 param_4,
            u32 param_5)

{
  u32 uVar1;
  long lVar2;
  u32 uVar3;
  
  if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else {
    lVar2 = FUN_0051c2e8(param_1);
    if (lVar2 < 0) {
      uVar1 = 0x81018002;
    }
    else {
      uVar3 = FUN_00524388(param_2);
      if (uVar3 < 0x80) {
        WaitSema(DAT_0096f66c);
        if (DAT_0096f144 == 0) {
          DAT_0096f140 = (u32)lVar2;
          DAT_0096f144 = 0x20;
          FUN_00524270(0x96f55c,param_2);
          DAT_0096f14c = param_3;
          DAT_0096f150 = param_4;
          DAT_0096f154 = param_5;
          SignalSema(DAT_0096f664);
          SignalSema(DAT_0096f66c);
          uVar1 = 0;
        }
        else {
          SignalSema(DAT_0096f66c);
          uVar1 = 0x81010010;
        }
      }
      else {
        uVar1 = 0x8101005b;
      }
    }
  }
  return uVar1;
}
// FUN_00513BA8 NONMATCHING
u32
FUN_00513ba8(u64 param_1,u64 param_2,u32 param_3,u32 param_4,
            u32 param_5)

{
  u32 uVar1;
  long lVar2;
  u32 uVar3;
  
  if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else {
    lVar2 = FUN_0051c2e8(param_1);
    if (lVar2 < 0) {
      uVar1 = 0x81018002;
    }
    else {
      uVar3 = FUN_00524388(param_2);
      if (uVar3 < 0x80) {
        WaitSema(DAT_0096f66c);
        if (DAT_0096f144 == 0) {
          DAT_0096f140 = (u32)lVar2;
          DAT_0096f144 = 0x21;
          FUN_00524270(0x96f55c,param_2);
          DAT_0096f14c = param_3;
          DAT_0096f150 = param_4;
          DAT_0096f154 = param_5;
          SignalSema(DAT_0096f664);
          SignalSema(DAT_0096f66c);
          uVar1 = 0;
        }
        else {
          SignalSema(DAT_0096f66c);
          uVar1 = 0x81010010;
        }
      }
      else {
        uVar1 = 0x8101005b;
      }
    }
  }
  return uVar1;
}
// FUN_00513CC8 NONMATCHING
u32
FUN_00513cc8(u64 param_1,u64 param_2,u32 param_3,u32 param_4,
            u32 param_5)

{
  u32 uVar1;
  long lVar2;
  u32 uVar3;
  
  if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else {
    lVar2 = FUN_0051c2e8(param_1);
    if (lVar2 < 0) {
      uVar1 = 0x81018002;
    }
    else {
      uVar3 = FUN_00524388(param_2);
      if (uVar3 < 0x80) {
        WaitSema(DAT_0096f66c);
        if (DAT_0096f144 == 0) {
          DAT_0096f140 = (u32)lVar2;
          DAT_0096f144 = 6;
          FUN_00524270(0x96f55c,param_2);
          DAT_0096f14c = param_3;
          DAT_0096f150 = param_4;
          DAT_0096f154 = param_5;
          SignalSema(DAT_0096f664);
          SignalSema(DAT_0096f66c);
          uVar1 = 0;
        }
        else {
          SignalSema(DAT_0096f66c);
          uVar1 = 0x81010010;
        }
      }
      else {
        uVar1 = 0x8101005b;
      }
    }
  }
  return uVar1;
}
// FUN_00513DE8 NONMATCHING
u32 FUN_00513de8(u64 param_1,u64 param_2)

{
  u32 uVar1;
  long lVar2;
  u32 uVar3;
  
  if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else {
    lVar2 = FUN_0051c2e8(param_1);
    if (lVar2 < 0) {
      uVar1 = 0x81018002;
    }
    else {
      uVar3 = FUN_00524388(param_2);
      if (uVar3 < 0x80) {
        WaitSema(DAT_0096f66c);
        if (DAT_0096f144 == 0) {
          DAT_0096f140 = (u32)lVar2;
          DAT_0096f144 = 7;
          FUN_00524270(0x96f55c,param_2);
          DAT_0096f14c = 0x8417;
          SignalSema(DAT_0096f664);
          SignalSema(DAT_0096f66c);
          uVar1 = 0;
        }
        else {
          SignalSema(DAT_0096f66c);
          uVar1 = 0x81010010;
        }
      }
      else {
        uVar1 = 0x8101005b;
      }
    }
  }
  return uVar1;
}
// FUN_00513EE0 NONMATCHING
u32 FUN_00513ee0(u64 param_1,u64 param_2)

{
  u32 uVar1;
  long lVar2;
  u32 uVar3;
  
  if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else {
    lVar2 = FUN_0051c2e8(param_1);
    if (lVar2 < 0) {
      uVar1 = 0x81018002;
    }
    else {
      uVar3 = FUN_00524388(param_2);
      if (uVar3 < 0x80) {
        WaitSema(DAT_0096f66c);
        if (DAT_0096f144 == 0) {
          DAT_0096f140 = (u32)lVar2;
          DAT_0096f144 = 8;
          FUN_00524270(0x96f55c,param_2);
          SignalSema(DAT_0096f664);
          SignalSema(DAT_0096f66c);
          uVar1 = 0;
        }
        else {
          SignalSema(DAT_0096f66c);
          uVar1 = 0x81010010;
        }
      }
      else {
        uVar1 = 0x8101005b;
      }
    }
  }
  return uVar1;
}
// FUN_00513FC8 NONMATCHING
u32
FUN_00513fc8(u64 param_1,u64 param_2,u32 param_3,u32 param_4,
            u32 param_5,u32 param_6)

{
  u32 uVar1;
  long lVar2;
  u32 uVar3;
  
  if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else {
    lVar2 = FUN_0051c2e8(param_1);
    if (lVar2 < 0) {
      uVar1 = 0x81018002;
    }
    else {
      uVar3 = FUN_00524388(param_2);
      if (uVar3 < 0x80) {
        WaitSema(DAT_0096f66c);
        if (DAT_0096f144 == 0) {
          DAT_0096f140 = (u32)lVar2;
          DAT_0096f144 = 10;
          FUN_00524270(0x96f55c,param_2);
          DAT_0096f14c = param_3;
          DAT_0096f150 = param_4;
          DAT_0096f154 = param_5;
          DAT_0096f158 = param_6;
          SignalSema(DAT_0096f664);
          SignalSema(DAT_0096f66c);
          uVar1 = 0;
        }
        else {
          SignalSema(DAT_0096f66c);
          uVar1 = 0x81010010;
        }
      }
      else {
        uVar1 = 0x8101005b;
      }
    }
  }
  return uVar1;
}
// FUN_005140F8 NONMATCHING
u32 FUN_005140f8(u64 param_1,u64 param_2)

{
  u32 uVar1;
  long lVar2;
  u32 uVar3;
  
  if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else {
    lVar2 = FUN_0051c2e8(param_1);
    if (lVar2 < 0) {
      uVar1 = 0x81018002;
    }
    else {
      uVar3 = FUN_00524388(param_2);
      if (uVar3 < 0x80) {
        WaitSema(DAT_0096f66c);
        if (DAT_0096f144 == 0) {
          DAT_0096f140 = (u32)lVar2;
          DAT_0096f144 = 0xb;
          FUN_00524270(0x96f55c,param_2);
          DAT_0096f14c = 0x8427;
          SignalSema(DAT_0096f664);
          SignalSema(DAT_0096f66c);
          uVar1 = 0;
        }
        else {
          SignalSema(DAT_0096f66c);
          uVar1 = 0x81010010;
        }
      }
      else {
        uVar1 = 0x8101005b;
      }
    }
  }
  return uVar1;
}
// FUN_005141F0 NONMATCHING
u32 FUN_005141f0(u64 param_1,u64 param_2,u32 param_3)

{
  u32 uVar1;
  long lVar2;
  u32 uVar3;
  
  if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else {
    lVar2 = FUN_0051c2e8(param_1);
    if (lVar2 < 0) {
      uVar1 = 0x81018002;
    }
    else {
      uVar3 = FUN_00524388(param_2);
      if (uVar3 < 0x80) {
        WaitSema(DAT_0096f66c);
        if (DAT_0096f144 == 0) {
          DAT_0096f140 = (u32)lVar2;
          DAT_0096f144 = 0xc;
          FUN_00524270(0x96f55c,param_2);
          DAT_0096f14c = param_3;
          SignalSema(DAT_0096f664);
          SignalSema(DAT_0096f66c);
          uVar1 = 0;
        }
        else {
          SignalSema(DAT_0096f66c);
          uVar1 = 0x81010010;
        }
      }
      else {
        uVar1 = 0x8101005b;
      }
    }
  }
  return uVar1;
}
// FUN_005142F0 NONMATCHING
u32 FUN_005142f0(u64 param_1,u64 param_2,u32 param_3)

{
  u32 uVar1;
  long lVar2;
  u32 uVar3;
  
  if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else {
    lVar2 = FUN_0051c2e8(param_1);
    if (lVar2 < 0) {
      uVar1 = 0x81018002;
    }
    else {
      uVar3 = FUN_00524388(param_2);
      if (uVar3 < 0x80) {
        WaitSema(DAT_0096f66c);
        if (DAT_0096f144 == 0) {
          DAT_0096f140 = (u32)lVar2;
          DAT_0096f144 = 0xd;
          FUN_00524270(0x96f55c,param_2);
          DAT_0096f14c = param_3 & 0xffff;
          SignalSema(DAT_0096f664);
          SignalSema(DAT_0096f66c);
          uVar1 = 0;
        }
        else {
          SignalSema(DAT_0096f66c);
          uVar1 = 0x81010010;
        }
      }
      else {
        uVar1 = 0x8101005b;
      }
    }
  }
  return uVar1;
}
// FUN_005143F0 NONMATCHING
u32 FUN_005143f0(u64 param_1,u64 param_2,u64 param_3)

{
  u32 uVar1;
  long lVar2;
  u32 uVar3;
  
  if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else {
    lVar2 = FUN_0051c2e8(param_1);
    if (lVar2 < 0) {
      uVar1 = 0x81018002;
    }
    else {
      uVar3 = FUN_00524388(param_2);
      if ((uVar3 < 0x80) && (uVar3 = FUN_00524388(param_3), uVar3 < 0x80)) {
        WaitSema(DAT_0096f66c);
        if (DAT_0096f144 == 0) {
          DAT_0096f140 = (u32)lVar2;
          DAT_0096f144 = 9;
          FUN_00524270(0x96f55c,param_2);
          FUN_00524270(0x96f5dc,param_3);
          SignalSema(DAT_0096f664);
          SignalSema(DAT_0096f66c);
          uVar1 = 0;
        }
        else {
          SignalSema(DAT_0096f66c);
          uVar1 = 0x81010010;
        }
      }
      else {
        uVar1 = 0x8101005b;
      }
    }
  }
  return uVar1;
}
// FUN_00514510 NONMATCHING
u32 FUN_00514510(u64 param_1,u64 param_2)

{
  u32 uVar1;
  long lVar2;
  u32 uVar3;
  
  if (ram0x007827d8 == 0) {
    uVar1 = 0x81018001;
  }
  else {
    lVar2 = FUN_0051c2e8(param_1);
    if (lVar2 < 0) {
      uVar1 = 0x81018002;
    }
    else {
      uVar3 = FUN_00524388(param_2);
      if (uVar3 < 0x80) {
        WaitSema(DAT_0096f66c);
        if (DAT_0096f144 == 0) {
          DAT_0096f140 = (u32)lVar2;
          DAT_0096f144 = 0xf;
          FUN_00524270(0x96f55c,param_2);
          SignalSema(DAT_0096f664);
          SignalSema(DAT_0096f66c);
          uVar1 = 0;
        }
        else {
          SignalSema(DAT_0096f66c);
          uVar1 = 0x81010010;
        }
      }
      else {
        uVar1 = 0x8101005b;
      }
    }
  }
  return uVar1;
}
// FUN_005145F8 NONMATCHING
void FUN_005145f8(void)

{
  do {
    WaitSema(DAT_0096f664);
    switch(DAT_0096f144) {
    case 2:
      DAT_0096f148 = FUN_00515d80(DAT_0096f140,DAT_0096f14c);
      break;
    case 3:
      DAT_0096f148 = FUN_00516118(DAT_0096f140);
      break;
    case 4:
      DAT_0096f148 = FUN_00516a48(DAT_0096f140);
      break;
    case 5:
      DAT_0096f148 = FUN_00518268(DAT_0096f140,0x96f55c,DAT_0096f14c,DAT_0096f150,DAT_0096f154);
      break;
    case 6:
      DAT_0096f148 = FUN_005187c0(DAT_0096f140,0x96f55c,DAT_0096f14c,DAT_0096f150,DAT_0096f154);
      break;
    case 7:
      DAT_0096f148 = FUN_00517cd8(DAT_0096f140,0x96f55c,DAT_0096f14c);
      break;
    case 8:
      DAT_0096f148 = FUN_005194f8(DAT_0096f140,0x96f55c);
      break;
    case 9:
      DAT_0096f148 = FUN_00519ef8(DAT_0096f140,0x96f55c,0x96f5dc);
      break;
    case 10:
      DAT_0096f148 = FUN_00519850(DAT_0096f140,0x96f55c,DAT_0096f14c,DAT_0096f150,DAT_0096f154,
                                  DAT_0096f158);
      break;
    case 0xb:
      DAT_0096f148 = FUN_00517cd8(DAT_0096f140,0x96f55c,DAT_0096f14c);
      break;
    case 0xc:
      DAT_0096f148 = FUN_00519728(DAT_0096f140,0x96f55c,DAT_0096f14c);
      break;
    case 0xd:
      DAT_0096f148 = FUN_00519d70(DAT_0096f140,0x96f55c,(u16)DAT_0096f14c);
      break;
    case 0xe:
      DAT_0096f148 = FUN_00517be8(DAT_0096f140,0x96f55c,DAT_0096f14c);
      break;
    case 0xf:
      DAT_0096f148 = FUN_0051a078(DAT_0096f140,0x96f55c);
      break;
    case 0x20:
      DAT_0096f148 = FUN_00518470(DAT_0096f140,0x96f55c,DAT_0096f14c,DAT_0096f150,DAT_0096f154);
      break;
    case 0x21:
      DAT_0096f148 = FUN_00518e70(DAT_0096f140,0x96f55c,DAT_0096f14c,DAT_0096f150,DAT_0096f154);
    }
    if (DAT_0096f148 == -0x7efe6001) {
      DAT_0096f148 = -0x7efefffe;
    }
    SignalSema(DAT_0096f668);
  } while( true );
}
// FUN_00514858 NONMATCHING
u32 FUN_00514858(long param_1,long param_2,long param_3)

{
  u32 uVar1;
  long lVar2;
  
  if (DAT_0096f144 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    if (param_2 != 0) {
      *(int *)param_2 = DAT_0096f144;
    }
    if (param_1 == 0) {
      WaitSema(DAT_0096f668);
    }
    else {
      lVar2 = PollSema(DAT_0096f668);
      if (lVar2 < 0) {
        return 0;
      }
    }
    if (param_3 != 0) {
      *(u32 *)param_3 = DAT_0096f148;
    }
    if (param_2 != 0) {
      *(int *)param_2 = DAT_0096f144;
    }
    DAT_0096f144 = 0;
    uVar1 = 1;
  }
  return uVar1;
}
// FUN_00514900 NONMATCHING
void FUN_00514900(u64 param_1,u64 param_2)

{
  FUN_00514858(1,param_1,param_2);
  return;
}
// FUN_00514928 NONMATCHING
void FUN_00514928(u64 param_1,u64 param_2)

{
  FUN_00514858(0,param_1,param_2);
  return;
}
// FUN_00514950 NONMATCHING
int FUN_00514950(void)

{
  int aiStack_20 [4];
  
  aiStack_20[0] = FUN_005136f8(0,0);
  if (aiStack_20[0] == 0) {
    FUN_00514858(0,0,(long)(u32)aiStack_20);
  }
  return aiStack_20[0];
}
// FUN_00514990 NONMATCHING
int FUN_00514990(void)

{
  int aiStack_20 [4];
  
  aiStack_20[0] = FUN_00513598(0);
  if (aiStack_20[0] == 0) {
    FUN_00514858(0,0,(long)(u32)aiStack_20);
  }
  return aiStack_20[0];
}
// FUN_005149D0 NONMATCHING
int FUN_005149d0(void)

{
  int aiStack_20 [4];
  
  aiStack_20[0] = FUN_00513648(0);
  if (aiStack_20[0] == 0) {
    FUN_00514858(0,0,(long)(u32)aiStack_20);
  }
  return aiStack_20[0];
}
// FUN_00514A10 NONMATCHING
int FUN_00514a10(void)

{
  int aiStack_20 [4];
  
  aiStack_20[0] = FUN_00513968(0,0,0,0,0);
  if (aiStack_20[0] == 0) {
    FUN_00514858(0,0,(long)(u32)aiStack_20);
  }
  return aiStack_20[0];
}
// FUN_00514A50 NONMATCHING
int FUN_00514a50(void)

{
  int aiStack_20 [4];
  
  aiStack_20[0] = FUN_00513cc8(0,0,0,0,0);
  if (aiStack_20[0] == 0) {
    FUN_00514858(0,0,(long)(u32)aiStack_20);
  }
  return aiStack_20[0];
}
// FUN_00514A90 NONMATCHING
int FUN_00514a90(void)

{
  int aiStack_20 [4];
  
  aiStack_20[0] = FUN_00513a88(0,0,0,0,0);
  if (aiStack_20[0] == 0) {
    FUN_00514858(0,0,(long)(u32)aiStack_20);
  }
  return aiStack_20[0];
}
// FUN_00514AD0 NONMATCHING
int FUN_00514ad0(void)

{
  int aiStack_20 [4];
  
  aiStack_20[0] = FUN_00513ba8(0,0,0,0,0);
  if (aiStack_20[0] == 0) {
    FUN_00514858(0,0,(long)(u32)aiStack_20);
  }
  return aiStack_20[0];
}
// FUN_00514B10 NONMATCHING
int FUN_00514b10(void)

{
  int aiStack_20 [4];
  
  aiStack_20[0] = FUN_00513de8(0,0);
  if (aiStack_20[0] == 0) {
    FUN_00514858(0,0,(long)(u32)aiStack_20);
  }
  return aiStack_20[0];
}
// FUN_00514B50 NONMATCHING
int FUN_00514b50(void)

{
  int aiStack_20 [4];
  
  aiStack_20[0] = FUN_00513ee0(0,0);
  if (aiStack_20[0] == 0) {
    FUN_00514858(0,0,(long)(u32)aiStack_20);
  }
  return aiStack_20[0];
}
// FUN_00514B90 NONMATCHING
int FUN_00514b90(void)

{
  int aiStack_20 [4];
  
  aiStack_20[0] = FUN_005143f0(0,0,0);
  if (aiStack_20[0] == 0) {
    FUN_00514858(0,0,(long)(u32)aiStack_20);
  }
  return aiStack_20[0];
}
// FUN_00514BD0 NONMATCHING
int FUN_00514bd0(void)

{
  int aiStack_20 [4];
  
  aiStack_20[0] = FUN_005140f8(0,0);
  if (aiStack_20[0] == 0) {
    FUN_00514858(0,0,(long)(u32)aiStack_20);
  }
  return aiStack_20[0];
}
// FUN_00514C10 NONMATCHING
int FUN_00514c10(void)

{
  int aiStack_20 [4];
  
  aiStack_20[0] = FUN_005141f0(0,0,0);
  if (aiStack_20[0] == 0) {
    FUN_00514858(0,0,(long)(u32)aiStack_20);
  }
  return aiStack_20[0];
}
// FUN_00514C50 NONMATCHING
int FUN_00514c50(void)

{
  int aiStack_20 [4];
  
  aiStack_20[0] = FUN_00513fc8(0,0,0,0,0,0);
  if (aiStack_20[0] == 0) {
    FUN_00514858(0,0,(long)(u32)aiStack_20);
  }
  return aiStack_20[0];
}
// FUN_00514C90 NONMATCHING
int FUN_00514c90(u64 param_1,u64 param_2,u16 param_3)

{
  int aiStack_20 [4];
  
  aiStack_20[0] = FUN_005142f0(param_1,param_2,param_3);
  if (aiStack_20[0] == 0) {
    FUN_00514858(0,0,(long)(u32)aiStack_20);
  }
  return aiStack_20[0];
}
// FUN_00514CD0 NONMATCHING
int FUN_00514cd0(void)

{
  int aiStack_20 [4];
  
  aiStack_20[0] = FUN_005137b8(0,0,0);
  if (aiStack_20[0] == 0) {
    FUN_00514858(0,0,(long)(u32)aiStack_20);
  }
  return aiStack_20[0];
}
// FUN_00514D10 NONMATCHING
int FUN_00514d10(void)

{
  int aiStack_20 [4];
  
  aiStack_20[0] = FUN_00514510(0,0);
  if (aiStack_20[0] == 0) {
    FUN_00514858(0,0,(long)(u32)aiStack_20);
  }
  return aiStack_20[0];
}
// FUN_00514D50 NONMATCHING
int FUN_00514d50(char *param_1,char param_2)

{
  char cVar1;
  long lVar2;
  char *pcVar3;
  
  cVar1 = *param_1;
  lVar2 = (long)(int)param_2;
  pcVar3 = param_1;
  if ((long)*param_1 != 0) {
    if (*param_1 == lVar2) goto LAB_00514d9c;
    do {
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
      if ((long)*pcVar3 == 0) break;
    } while (*pcVar3 != lVar2);
  }
  if ((int)cVar1 != lVar2) {
    return -1;
  }
LAB_00514d9c:
  return (int)pcVar3 - (int)param_1;
}
// FUN_00514DB0 NONMATCHING
u32 FUN_00514db0(u64 param_1)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  u32 uVar4;
  
  lVar3 = FUN_00523f98(param_1,0x2f);
  if (lVar3 == 0) {
    uVar4 = FUN_00524388(param_1);
    uVar2 = 0;
    if (uVar4 < 0x20) {
      uVar2 = 1;
    }
  }
  else {
    iVar1 = FUN_005249e8(param_1,0x2f);
    uVar4 = FUN_00524388(iVar1 + 1);
    uVar2 = 1;
    if (0x1f < uVar4) {
      uVar2 = 0;
    }
  }
  return uVar2;
}
// FUN_00514E20 NONMATCHING
u32 FUN_00514e20(char *param_1)

{
  char cVar1;
  char cVar2;
  
  cVar1 = *param_1;
  cVar2 = *param_1;
  while( true ) {
    if (cVar1 == '\0') {
      return 1;
    }
    if (((cVar2 == '?') || (cVar2 == '*')) || (param_1 = param_1 + 1, cVar2 < ' ')) break;
    cVar1 = *param_1;
    cVar2 = *param_1;
  }
  return 0;
}
// FUN_00514E78 NONMATCHING
u32 FUN_00514e78(u64 param_1)

{
  int iVar1;
  long lVar2;
  u32 uVar3;
  u8 auStack_40 [32];
  
  lVar2 = FUN_00523f98(param_1,0x2f);
  if (lVar2 == 0) {
    uVar3 = FUN_00524388(param_1);
    if (0x1f < uVar3) {
      return 0;
    }
    FUN_00524270(auStack_40,param_1);
  }
  else {
    iVar1 = FUN_005249e8(param_1,0x2f);
    uVar3 = FUN_00524388(iVar1 + 1);
    if (0x1f < uVar3) {
      return 0;
    }
    iVar1 = FUN_005249e8(param_1,0x2f);
    FUN_00524270(auStack_40,iVar1 + 1);
  }
  lVar2 = FUN_00524128(auStack_40,0x7be5f0);
  if ((lVar2 != 0) && (lVar2 = FUN_00524128(auStack_40,0x7be5f8), lVar2 != 0)) {
    return 1;
  }
  return 0;
}
// FUN_00514F30 NONMATCHING
bool FUN_00514f30(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  do {
    lVar4 = FUN_00514d50(param_2,0x3f);
    lVar5 = FUN_00514d50(param_2,0x2a);
    if ((lVar4 < 0) && (lVar5 < 0)) {
      lVar4 = FUN_00524128(param_2,param_1);
      return lVar4 == 0;
    }
    lVar6 = lVar5;
    if (((-1 < lVar4) && (lVar6 = lVar4, -1 < lVar5)) && (lVar5 <= lVar4)) {
      lVar6 = lVar5;
    }
    lVar4 = FUN_00524670(param_2,param_1,lVar6);
    if (lVar4 != 0) {
      return false;
    }
    param_2 = param_2 + (int)lVar6;
    param_1 = param_1 + (int)lVar6;
    cVar2 = *param_2;
    cVar1 = *param_2;
    while (cVar1 == '?') {
      param_2 = param_2 + 1;
      if (*param_1 == '\0') goto LAB_0051502c;
      param_1 = param_1 + 1;
      cVar2 = *param_2;
      cVar1 = *param_2;
    }
  } while (cVar2 != '*');
  do {
    do {
      param_2 = param_2 + 1;
      cVar1 = *param_2;
      cVar2 = *param_2;
    } while (cVar1 == '*');
  } while (cVar1 == '?');
  if (cVar1 == '\0') {
LAB_0051502c:
    bVar3 = true;
  }
  else {
    while( true ) {
      lVar4 = FUN_00514d50(param_1,cVar2);
      if (lVar4 < 0) break;
      lVar5 = FUN_00514f30(param_1 + (int)lVar4,param_2);
      if (lVar5 == 1) goto LAB_0051502c;
      cVar2 = *param_2;
      param_1 = param_1 + (int)lVar4 + 1;
    }
    bVar3 = false;
  }
  return bVar3;
}
// FUN_005150B0 NONMATCHING
char * FUN_005150b0(long param_1,u64 param_2)

{
  char cVar1;
  char cVar2;
  long lVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_1 == 0) {
    if ((char *)(u32)(char *)(u32)DAT_0097b680 == (char *)0x0) {
      return (char *)0x0;
    }
    cVar2 = *DAT_0097b680;
    pcVar4 = (char *)(DAT_0097b680);
  }
  else {
    FUN_00524270(0x97b688,param_1);
    cVar2 = DAT_0097b688;
    pcVar4 = (char *)(&DAT_0097b688);
  }
  cVar1 = *pcVar4;
  if (cVar2 == '\0') {
    pcVar4 = (char *)0x0;
  }
  else {
    while( true ) {
      pcVar5 = pcVar4 + 1;
      lVar3 = FUN_00523f98(param_2,cVar1);
      if (lVar3 == 0) break;
      if (*pcVar4 == '\0') {
        return (char *)0x0;
      }
      cVar1 = *pcVar5;
      pcVar4 = pcVar5;
    }
    if (*pcVar4 == '\"') {
      cVar2 = *pcVar5;
      pcVar4 = pcVar5;
      while( true ) {
        pcVar6 = pcVar4 + 1;
        lVar3 = FUN_00523f98(0x7be600,cVar2);
        if (lVar3 != 0) break;
        cVar2 = *pcVar6;
        pcVar4 = pcVar6;
      }
      cVar2 = *pcVar4;
      pcVar4 = pcVar5;
    }
    else {
      cVar2 = *pcVar5;
      while( true ) {
        pcVar6 = pcVar5 + 1;
        lVar3 = FUN_00523f98(param_2,cVar2);
        if (lVar3 != 0) break;
        cVar2 = *pcVar6;
        pcVar5 = pcVar6;
      }
      cVar2 = *pcVar5;
    }
    DAT_0097b680 = (u32 *)((u32)(pcVar6));
    if (cVar2 == '\0') {
      DAT_0097b680 = (u32)((char *)0x0);
    }
    pcVar6[-1] = '\0';
  }
  return pcVar4;
}
// FUN_005151D0 NONMATCHING
int FUN_005151d0(char *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = 0;
  cVar1 = *param_1;
  cVar2 = *param_1;
  while (cVar1 != '\0') {
    param_1 = param_1 + 1;
    cVar1 = *param_1;
    if (cVar2 == '/') {
      iVar3 = iVar3 + 1;
    }
    cVar2 = *param_1;
  }
  return iVar3;
}
// FUN_00515218 NONMATCHING
u32 FUN_00515218(int param_1,u64 param_2,u64 param_3)

{
  u8 uVar1;
  int iVar2;
  u8 *puVar3;
  u32 uVar4;
  u32 uVar5;
  long lVar6;
  long lVar7;
  
  uVar5 = FUN_00524388(param_2);
  if (uVar5 < 0x80) {
    FUN_00524270(param_3,&DAT_0097bf90 + param_1 * 0x898);
    uVar1 = DAT_007be609;
    puVar3 = (u8 *)param_3;
    if (*(char *)param_2 == '/') {
      *puVar3 = DAT_007be608;
      puVar3[1] = uVar1;
      lVar6 = (long)(u32)FUN_005150b0((long)(u32)((char *)param_2 + 1),0x7be608);
    }
    else {
      lVar6 = (long)(FUN_005150b0(param_2,0x7be608));
    }
    while (lVar6 != 0) {
      lVar7 = FUN_00524128(lVar6,0x7be5f0);
      if (lVar7 != 0) {
        lVar7 = FUN_00524128(lVar6,0x7be5f8);
        if (lVar7 == 0) {
          iVar2 = FUN_00524388(param_3);
          puVar3[iVar2 + -1] = 0;
          lVar6 = FUN_005249e8(param_3,0x2f);
          if (lVar6 == 0) goto LAB_00515250;
          *(u8 *)((int)lVar6 + 1) = 0;
        }
        else {
          FUN_00523e68(param_3,lVar6);
          FUN_00523e68(param_3,0x7be608);
        }
      }
      lVar6 = (long)(FUN_005150b0(0,0x7be608));
    }
    lVar6 = FUN_00524128(param_3,0x7be608);
    if (lVar6 != 0) {
      puVar3 = (u8 *)FUN_005249e8(param_3,0x2f);
      *puVar3 = 0;
    }
    uVar4 = 1;
  }
  else {
LAB_00515250:
    uVar4 = 0;
  }
  return uVar4;
}
// FUN_005153A0 NONMATCHING
u32 FUN_005153a0(void)

{
  u8 uVar1;
  u8 *puVar2;
  int iVar3;
  
  puVar2 = (u8 *)(&DAT_0097bf90);
  iVar3 = 1;
  do {
    *(u32 *)(puVar2 + -8) = 0xffffffff;
    iVar3 = iVar3 + -1;
    *(u32 *)(puVar2 + -4) = 0xffffffff;
    *(u32 *)(puVar2 + 0x8c) = 0;
    *(u32 *)(puVar2 + 0x80) = 1;
    *(u32 *)(puVar2 + 0x84) = 0;
    *(u32 *)(puVar2 + 0x88) = 0;
    uVar1 = DAT_007be609;
    *puVar2 = DAT_007be608;
    puVar2[1] = uVar1;
    puVar2 = puVar2 + 0x898;
  } while (-1 < iVar3);
  return 1;
}
// FUN_00515400 NONMATCHING
u32 FUN_00515400(int param_1)

{
  u8 uVar1;
  
  (&DAT_0097bf88)[param_1 * 0x226] = 0xffffffff;
  (&DAT_0097bf8c)[param_1 * 0x226] = 0xffffffff;
  (&DAT_0097c01c)[param_1 * 0x226] = 0;
  (&DAT_0097c010)[param_1 * 0x226] = 1;
  (&DAT_0097c014)[param_1 * 0x226] = 0;
  (&DAT_0097c018)[param_1 * 0x226] = 0;
  uVar1 = DAT_007be609;
  (&DAT_0097bf90)[param_1 * 0x898] = DAT_007be608;
  (&DAT_0097bf91)[param_1 * 0x898] = uVar1;
  return 1;
}
// FUN_00515468 NONMATCHING
int FUN_00515468(u64 param_1,int param_2,u32 *param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  u32 uVar5;
  
  iVar4 = (int)param_1;
  iVar3 = param_2;
  if (param_2 < 0) {
    iVar3 = param_2 + 0xffff;
  }
  iVar2 = param_2 + 0xff;
  if (-1 < param_2) {
    iVar2 = param_2;
  }
  iVar3 = iVar3 >> 0x10;
  if ((&DAT_0097bf8c)[iVar4 * 0x226] != iVar3) {
    uVar5 = iVar4 * 0x184 + iVar3 * 4 + 0x782830;
    lVar1 = FUN_0051a418(param_1,(u64)(u32)(&DAT_0097b788 + iVar4 * 0x898),
                         read_u32(uVar5),1);
    if (lVar1 == 0) {
      *param_3 = 0x8101006f;
      return 0;
    }
    (&DAT_0097bf8c)[iVar4 * 0x226] = iVar3;
  }
  iVar3 = *(int *)(&DAT_0097b788 + ((iVar2 >> 8) + iVar3 * -0x100) * 4 + iVar4 * 0x898);
  if (iVar3 < 0) {
    iVar3 = 0;
    *param_3 = 0x81019001;
  }
  else {
    *param_3 = 0;
  }
  return iVar3;
}
// FUN_00515588 NONMATCHING
u32 FUN_00515588(u64 param_1)

{
  u32 uVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = (int)param_1;
  if ((((int)(&DAT_0097bf88)[iVar3 * 0x226] < 1) || ((&DAT_0097c01c)[iVar3 * 0x226] != 1)) ||
     (lVar2 = FUN_0051a458(param_1,(u64)(u32)(&DAT_0097bb88 + iVar3 * 0x898),(u64)(u32)((&DAT_0097bf88)[iVar3 * 0x226]),1),
     lVar2 != 0)) {
    uVar1 = 1;
    (&DAT_0097c01c)[iVar3 * 0x226] = 0;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
// FUN_00515618 NONMATCHING
u32 FUN_00515618(u64 param_1,int param_2,int *param_3)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_2 + 0xff;
  if (-1 < param_2) {
    iVar4 = param_2;
  }
  iVar1 = FUN_00515468(0,0,0);
  uVar2 = 0;
  if (*param_3 == 0) {
    iVar5 = (int)param_1;
    if ((&DAT_0097bf88)[iVar5 * 0x226] != iVar1) {
      lVar3 = FUN_00515588(param_1);
      if ((lVar3 == 0) ||
         (lVar3 = FUN_0051a418(param_1,(u64)(u32)(&DAT_0097bb88 + iVar5 * 0x898),iVar1,1), lVar3 == 0)) {
        *param_3 = -0x7efeff91;
        return 0;
      }
      (&DAT_0097bf88)[iVar5 * 0x226] = iVar1;
    }
    uVar2 = *(u32 *)(&DAT_0097bb88 + (param_2 + (iVar4 >> 8) * -0x100) * 4 + iVar5 * 0x898);
    *param_3 = 0;
  }
  return uVar2;
}
// FUN_00515730 NONMATCHING
long FUN_00515730(u64 param_1,u64 param_2,u32 *param_3)

{
  long lVar1;
  
  lVar1 = FUN_00515618(0,0,0);
  if (lVar1 == 0x7fffffff) {
    *param_3 = 0x81019002;
  }
  return lVar1;
}
// FUN_00515778 NONMATCHING
u32 FUN_00515778(u64 param_1,u64 param_2,int *param_3)

{
  u32 uVar1;
  u32 uVar2;
  
  uVar1 = FUN_00515730(0,0,0);
  uVar2 = 0;
  if (*param_3 == 0) {
    if (uVar1 == 0xffffffffffffffff) {
      uVar2 = 0xffffffffffffffff;
      *param_3 = -0x7efeffa7;
    }
    else {
      uVar2 = uVar1 & 0x7fffffff;
    }
  }
  return uVar2;
}
// FUN_005157E0 NONMATCHING
u32 FUN_005157e0(u64 param_1,int param_2,u32 param_3,u64 param_4)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar4 = param_2 + 0xff;
  if (-1 < param_2) {
    iVar4 = param_2;
  }
  iVar1 = FUN_00515468(param_1,param_2,(u32 *)(u32)param_4);
  piVar6 = (int *)param_4;
  uVar2 = 0;
  if (*piVar6 == 0) {
    iVar5 = (int)param_1;
    if ((&DAT_0097bf88)[iVar5 * 0x226] != iVar1) {
      lVar3 = FUN_00515588(param_1);
      if ((lVar3 == 0) ||
         (lVar3 = FUN_0051a418(param_1,(u64)(u32)(&DAT_0097bb88 + iVar5 * 0x898),iVar1,1), lVar3 == 0)) {
        *piVar6 = -0x7efeff91;
        return 0;
      }
      (&DAT_0097bf88)[iVar5 * 0x226] = iVar1;
    }
    uVar2 = 1;
    *(u32 *)(&DAT_0097bb88 + (param_2 + (iVar4 >> 8) * -0x100) * 4 + iVar5 * 0x898) = param_3
    ;
    (&DAT_0097c01c)[iVar5 * 0x226] = 1;
    *piVar6 = 0;
  }
  return uVar2;
}
// FUN_00515910 NONMATCHING
int FUN_00515910(u64 param_1,u64 param_2)

{
  u32 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = (int)param_1;
  piVar4 = (int *)param_2;
  *piVar4 = 0;
  iVar2 = *(int *)(&DAT_00782950 + iVar5 * 0x184);
  do {
    iVar3 = (&DAT_0097c018)[iVar5 * 0x226];
    if (iVar3 < iVar2) {
      do {
        uVar1 = (u32)FUN_00515618(param_1,iVar3,(int *)(u32)param_2);
        if (*piVar4 != 0) {
          return 0;
        }
        if ((uVar1 & 0xffffffff80000000) == 0) {
          *piVar4 = 0;
          (&DAT_0097c018)[iVar5 * 0x226] = iVar3;
          return iVar3;
        }
        iVar2 = *(int *)(&DAT_00782950 + iVar5 * 0x184);
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
    }
    if ((&DAT_0097c018)[iVar5 * 0x226] == 0) {
      *piVar4 = -0x7efeffe4;
      return 0;
    }
    (&DAT_0097c018)[iVar5 * 0x226] = 0;
  } while( true );
}
// FUN_00515A40 NONMATCHING
int FUN_00515a40(u64 param_1,u64 param_2)

{
  int iVar1;
  u32 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = (int)param_1 * 0x184;
  *(int *)param_2 = 0;
  iVar3 = (&DAT_0097c018)[(int)param_1 * 0x226];
  iVar4 = 0;
  if (iVar3 < *(int *)(&DAT_00782950 + iVar1)) {
    do {
      uVar2 = (u32)FUN_00515618(param_1,iVar3,(int *)(u32)param_2);
      if (*(int *)param_2 != 0) {
        return 0;
      }
      iVar3 = iVar3 + 1;
      if ((uVar2 & 0xffffffff80000000) == 0) {
        iVar4 = iVar4 + 1;
      }
    } while (iVar3 < *(int *)(&DAT_00782950 + iVar1));
  }
  return iVar4;
}
// FUN_00515B18 NONMATCHING
int FUN_00515b18(u64 param_1,u64 *param_2,u64 param_3,int param_4)

{
  int iVar1;
  long lVar2;
  u64 *puVar3;
  u64 *puVar4;
  u64 uVar5;
  u64 uVar6;
  u64 uVar7;
  int aiStack_70 [4];
  
  aiStack_70[0] = 0;
  while( true ) {
    if (param_4 < 2) {
      lVar2 = FUN_0051a9e0(param_1,0x97c8c0,param_3,1);
      if (lVar2 == 0) {
        iVar1 = -0x7efeff91;
      }
      else {
        puVar3 = (u64 *)(&DAT_0097c8c0 + param_4 * 0x100);
        if (((u32)param_2 & 7) == 0) {
          puVar4 = param_2;
          do {
            uVar5 = puVar3[1];
            uVar6 = puVar3[2];
            uVar7 = puVar3[3];
            *puVar4 = *puVar3;
            puVar4[1] = uVar5;
            puVar4[2] = uVar6;
            puVar4[3] = uVar7;
            puVar3 = puVar3 + 4;
            puVar4 = puVar4 + 4;
          } while (puVar3 != (u64 *)(&DAT_0097cac0 + param_4 * 0x100));
          *(u8 *)((int)param_2 + 0x5f) = 0;
        }
        else {
          puVar4 = param_2;
          do {
            uVar5 = puVar3[1];
            uVar6 = puVar3[2];
            uVar7 = puVar3[3];
            *puVar4 = *puVar3;
            puVar4[1] = uVar5;
            puVar4[2] = uVar6;
            puVar4[3] = uVar7;
            puVar3 = puVar3 + 4;
            puVar4 = puVar4 + 4;
          } while (puVar3 != (u64 *)(&DAT_0097cac0 + param_4 * 0x100));
          *(u8 *)((int)param_2 + 0x5f) = 0;
        }
        iVar1 = 0;
      }
      return iVar1;
    }
    param_3 = FUN_00515778(param_1,param_3,aiStack_70);
    if (aiStack_70[0] == -0x7efeffa7) break;
    if (aiStack_70[0] != 0) {
      return aiStack_70[0];
    }
    param_4 = param_4 + -2;
  }
  return -0x7efefffe;
}
// FUN_00515C98 NONMATCHING
int FUN_00515c98(u64 param_1,u32 param_2)

{
  int iVar1;
  int aiStack_40 [4];
  
  if (param_2 == 0xffffffffffffffff) {
    iVar1 = 0;
  }
  else {
    iVar1 = 1;
    while( true ) {
      param_2 = (u64)(u32)FUN_00515730(param_1,param_2,(u32 *)(u32)aiStack_40);
      if (aiStack_40[0] != 0) {
        return aiStack_40[0];
      }
      if (param_2 == 0xffffffffffffffff) {
        return iVar1;
      }
      if (-1 < (long)param_2) break;
      iVar1 = iVar1 + 1;
      param_2 = param_2 & 0x7fffffff;
    }
    iVar1 = -0x7efe6ffe;
  }
  return iVar1;
}
// FUN_00515D28 NONMATCHING: O2 keeps the recovered four-word argument block but differs only in its stack/register schedule (80 bytes versus retail 88).
void FUN_00515d28(int param_1,int param_2)
{
  u32 auStack_20[4];
  u16 uVar1;

  uVar1 = *(u16 *)(param_2 + 0x28);
  auStack_20[0] = (u32)uVar1;
  auStack_20[1] = (u32)*(u16 *)(param_2 + 0x2c);
  auStack_20[2] = (*(int *)(param_2 + 0x30) << 10) / (int)(u32)uVar1;
  auStack_20[3] = 1;
  FUN_0051af98(param_1,(u64 *)auStack_20);
}
// FUN_00515D80 NONMATCHING
int FUN_00515d80(u64 param_1,long param_2)

{
  int iVar1;
  int iVar2;
  u8 uVar3;
  u32 uVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  u32 *puVar10;
  int aiStack_2c0 [4];
  u16 auStack_2b0 [32];
  u8 auStack_270 [448];
  int aiStack_b0 [4];
  
  iVar8 = (int)param_1;
  iVar2 = iVar8 * 0x184;
  lVar5 = FUN_0051c0c0(0);
  if (lVar5 == 0) {
    return -0x7efeffed;
  }
  puVar10 = (u32 *)param_2;
  if (param_2 != 0) {
    puVar10[1] = 0;
    *puVar10 = 0;
    puVar10[2] = 0;
  }
  lVar5 = FUN_0051a1a0(param_1);
  if (lVar5 == 0) {
    return -0x7efeffed;
  }
  if (lVar5 == 2) {
    (&DAT_0097c010)[iVar8 * 0x226] = 1;
  }
  if ((&DAT_0097c010)[iVar8 * 0x226] != 0) {
    lVar5 = FUN_0051a180(param_1,(int *)(u32)(int *)(u32)aiStack_2c0);
    if ((lVar5 == 0) || (aiStack_2c0[0] == 0)) {
      return -0x7efeff91;
    }
    (&DAT_0097c01c)[iVar8 * 0x226] = 0;
    (&DAT_0097bf88)[iVar8 * 0x226] = 0xffffffff;
    (&DAT_0097bf8c)[iVar8 * 0x226] = 0xffffffff;
    (&DAT_0097c018)[iVar8 * 0x226] = 0;
    uVar3 = DAT_007be609;
    (&DAT_0097bf90)[iVar8 * 0x898] = DAT_007be608;
    (&DAT_0097bf91)[iVar8 * 0x898] = uVar3;
    lVar5 = FUN_0051a1e0(param_1);
    if (lVar5 == 0) {
      return -0x7efeff91;
    }
    if (param_2 != 0) {
      *puVar10 = 2;
    }
    lVar5 = FUN_00524670(&DAT_007827e0 + iVar2,0x7be610,0x1b);
    if (lVar5 != 0) {
      if (param_2 == 0) {
        return -0x7efeffd1;
      }
      puVar10[1] = 0;
      return -0x7efeffd1;
    }
    if (((char)(&DAT_007827fc)[iVar2] + -0x30) * 10 + -0x30 + (int)(char)(&DAT_007827fe)[iVar2] <
        0xb) {
      return -0x7efeff7a;
    }
    FUN_00515d28(param_1,(int)(u32)((int)(u32)(&DAT_007827e0 + iVar2)));
    iVar9 = 0;
    iVar7 = 0;
    FUN_0051af70(param_1,*(u32 *)(&DAT_00782824 + iVar2),
                 *(u32 *)(&DAT_00782820 + iVar2));
    iVar1 = *(int *)(&DAT_00782810 + iVar2);
    iVar6 = *(int *)(&DAT_00782814 + iVar2);
    if (*(int *)(&DAT_00782818 + iVar2) < 1) {
      uVar4 = *(u32 *)(&DAT_0078281c + iVar2);
    }
    else {
      do {
        if (iVar9 == (iVar1 / 1000) * 1000 + 1) {
          *(int *)(&DAT_00782950 + iVar2) = iVar6 - *(int *)(&DAT_00782814 + iVar2);
        }
        lVar5 = FUN_0051ab50(param_1,iVar6);
        iVar7 = iVar7 + 1;
        if (lVar5 == 0) {
          iVar9 = iVar9 + 1;
        }
        iVar6 = iVar6 + 1;
      } while (iVar7 < *(int *)(&DAT_00782818 + iVar2));
      uVar4 = *(u32 *)(&DAT_0078281c + iVar2);
    }
    aiStack_b0[0] = FUN_00515b18(param_1,(u64 *)(u32)auStack_2b0,uVar4,0);
    if (aiStack_b0[0] != 0) {
      return aiStack_b0[0];
    }
    if ((auStack_2b0[0] & 0x8000) == 0) {
      return -0x7efeffd1;
    }
    lVar5 = FUN_00524128(auStack_270,0x7be5f0);
    if (lVar5 != 0) {
      return -0x7efeffd1;
    }
    aiStack_b0[0] = FUN_00515b18(param_1,(u64 *)(u32)auStack_2b0,*(u32 *)(&DAT_0078281c + iVar2),1);
    if (aiStack_b0[0] != 0) {
      return aiStack_b0[0];
    }
    if ((auStack_2b0[0] & 0x8000) == 0) {
      return -0x7efeffd1;
    }
    lVar5 = FUN_00524128(auStack_270,0x7be5f8);
    if (lVar5 != 0) {
      return -0x7efeffd1;
    }
    (&DAT_0097c014)[iVar8 * 0x226] = 1;
  }
  if ((&DAT_0097c014)[iVar8 * 0x226] == 0) {
    return -0x7efeffd1;
  }
  if (param_2 != 0) {
    uVar4 = (u64)(FUN_00515a40(param_1,(u64)(u32)aiStack_b0));
    if (aiStack_b0[0] != 0) {
      return aiStack_b0[0];
    }
    iVar2 = (&DAT_0097c014)[iVar8 * 0x226];
    *puVar10 = 2;
    puVar10[1] = iVar2;
    puVar10[2] = uVar4;
  }
  if ((&DAT_0097c010)[iVar8 * 0x226] != 0) {
    (&DAT_0097c010)[iVar8 * 0x226] = 0;
    return -0x7efe6ffd;
  }
  return 0;
}
// FUN_00516118 NONMATCHING
int FUN_00516118(u64 param_1)

{
  u16 uVar1;
  u8 uVar2;
  u64 uVar3;
  u64 uVar4;
  u32 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  int iVar10;
  int iVar11;
  u64 *puVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iStack_e0;
  int iStack_dc;
  int iStack_d8;
  u8 uStack_d0;
  u8 bStack_cf;
  u8 bStack_ce;
  u8 bStack_cd;
  u8 bStack_cb;
  u8 bStack_ca;
  u8 bStack_c9;
  int iStack_b0;
  int iStack_ac;
  
  iVar15 = (int)param_1;
  iVar8 = iVar15 * 0x184;
  puVar12 = (u64 *)(&DAT_007827e0 + iVar8);
  lVar9 = FUN_0051c0c0(0);
  if (lVar9 == 0) {
    return -0x7efeffed;
  }
  (&DAT_0097c01c)[iVar15 * 0x226] = 0;
  (&DAT_0097bf88)[iVar15 * 0x226] = 0xffffffff;
  (&DAT_0097bf8c)[iVar15 * 0x226] = 0xffffffff;
  (&DAT_0097c018)[iVar15 * 0x226] = 0;
  uVar2 = DAT_007be609;
  (&DAT_0097bf90)[iVar15 * 0x898] = DAT_007be608;
  (&DAT_0097bf91)[iVar15 * 0x898] = uVar2;
  lVar9 = FUN_0051a180(param_1,(int *)(u32)(int *)(u32)&iStack_e0);
  if ((lVar9 == 0) || (lVar9 = FUN_0051a1e0(param_1), lVar9 == 0)) {
LAB_005169c4:
    iVar8 = -0x7efeff91;
  }
  else {
    lVar9 = FUN_00524670(puVar12,0x7be610,0x1b);
    if (lVar9 != 0) {
      iVar13 = 0x1f;
      puVar5 = (u32 *)(&DAT_0078292c + iVar8);
      do {
        *puVar5 = 0xffffffff;
        iVar13 = iVar13 + -1;
        puVar5 = puVar5 + -1;
      } while (-1 < iVar13);
      lVar9 = (long)(FUN_0051ab98(param_1,&iStack_e0,(int *)(u32)(&DAT_007828b0 + iVar8)));
      if (lVar9 == 0) goto LAB_005169c4;
    }
    FUN_00521408(puVar12,0,0x28);
    uVar4 = DAT_007be620;
    uVar3 = DAT_007be618;
    *puVar12 = DAT_007be610;
    *(u64 *)(&DAT_007827e8 + iVar8) = uVar3;
    *(u64 *)(&DAT_007827f0 + iVar8) = uVar4;
    *(u8 **)(&DAT_007827f8 + iVar8) = PTR_DAT_007be628;
    FUN_00523e68(puVar12,0x7be630);
    *(u16 *)(&DAT_00782808 + iVar8) = (u16)iStack_e0;
    if (iStack_e0 == 0) {
      trap(7);
    }
    *(u16 *)(&DAT_0078280e + iVar8) = 0xff00;
    *(u16 *)(&DAT_0078280c + iVar8) = (u16)iStack_dc;
    *(short *)(&DAT_0078280a + iVar8) = (short)(0x400 / iStack_e0);
    *(u32 *)(&DAT_00782934 + iVar8) = 0x400;
    (&DAT_00782930)[iVar8] = 2;
    (&DAT_00782931)[iVar8] = 0x2b;
    *(u32 *)(&DAT_00782938 + iVar8) = 0x100;
    *(u32 *)(&DAT_0078281c + iVar8) = 0;
    *(u32 *)(&DAT_00782828 + iVar8) = 0;
    *(u32 *)(&DAT_0078282c + iVar8) = 0;
    *(u32 *)(&DAT_00782950 + iVar8) = 0;
    *(int *)(&DAT_00782810 + iVar8) = iStack_d8 / (int)(0x400 / iStack_e0 & 0xffffU);
    *(u32 *)(&DAT_00782960 + iVar8) = 0xffffffff;
    *(u32 *)(&DAT_00782944 + iVar8) = 0;
    *(u32 *)(&DAT_00782948 + iVar8) = 0;
    *(u32 *)(&DAT_0078294c + iVar8) = 0;
    *(u32 *)(&DAT_00782954 + iVar8) = 0xffffffff;
    *(u32 *)(&DAT_00782958 + iVar8) = 0xffffffff;
    *(u32 *)(&DAT_0078295c + iVar8) = 0xffffffff;
    *(u32 *)(&DAT_0078293c + iVar8) =
         (u32)*(u16 *)(&DAT_0078280c + iVar8) / (u32)*(u16 *)(&DAT_0078280a + iVar8);
    *(int *)(&DAT_00782820 + iVar8) = iStack_d8 / iStack_dc + -1;
    iStack_ac = iVar8 + 0x782830;
    while( true ) {
      lVar9 = FUN_0051ab08(param_1,*(u32 *)(&DAT_00782820 + iVar8));
      iVar13 = *(int *)(&DAT_00782820 + iVar8);
      if (lVar9 == 0) break;
      *(int *)(&DAT_00782820 + iVar8) = iVar13 + -1;
    }
    while( true ) {
      *(int *)(&DAT_00782824 + iVar8) = iVar13 + -1;
      lVar9 = FUN_0051ab08(param_1,*(u32 *)(&DAT_00782824 + iVar8));
      if (lVar9 == 0) break;
      iVar13 = *(int *)(&DAT_00782824 + iVar8);
    }
    FUN_0051af70(param_1,*(u32 *)(&DAT_00782824 + iVar8),
                 *(u32 *)(&DAT_00782820 + iVar8));
    iVar10 = *(int *)(&DAT_00782810 + iVar8) * 4 + -1;
    iVar13 = *(int *)(&DAT_00782810 + iVar8) * 4 + 0x3fe;
    if (-1 < iVar10) {
      iVar13 = iVar10;
    }
    iStack_dc = iStack_dc * iStack_e0;
    iVar10 = (iVar13 >> 10) + 1;
    iVar11 = iVar10 * 4 + -1;
    iVar13 = iVar10 * 4 + 0x3fe;
    if (-1 < iVar11) {
      iVar13 = iVar11;
    }
    iVar11 = iStack_dc + 0x3ff;
    if (-1 < iStack_dc) {
      iVar11 = iStack_dc;
    }
    iVar11 = iVar11 >> 10;
    iVar13 = (iVar13 >> 10) + 1;
    if (0x20 < iVar13) {
      iVar13 = 0x20;
      iVar10 = 0x2000;
    }
    FUN_00521408(iStack_ac,0,0x80);
    iVar7 = 0;
    if (0 < iVar13) {
      do {
        iVar14 = iVar7 + 1;
        do {
          lVar9 = FUN_0051ab50(param_1,iVar11);
          if (lVar9 == 1) {
            iVar11 = iVar11 + 1;
          }
        } while (lVar9 != 0);
        *(int *)(iStack_ac + iVar7 * 4) = iVar11;
        iVar11 = iVar11 + 1;
        iVar7 = iVar14;
      } while (iVar14 < iVar13);
    }
    iVar10 = iVar10 + -1;
    iVar14 = 0;
    iVar7 = 0;
    iVar13 = 0xff;
    puVar5 = (u32 *)(&DAT_0097bb84 + iVar15 * 0x898);
    do {
      *puVar5 = 0xffffffff;
      iVar13 = iVar13 + -1;
      puVar5 = puVar5 + -1;
    } while (-1 < iVar13);
    iVar13 = 0xff;
    puVar5 = (u32 *)(&DAT_0097bf84 + iVar15 * 0x898);
    do {
      *puVar5 = 0xffffffff;
      iVar13 = iVar13 + -1;
      puVar5 = puVar5 + -1;
    } while (-1 < iVar13);
    if (iVar10 < 0) {
      uVar1 = *(u16 *)(&DAT_0078280a + iVar8);
    }
    else {
      do {
        while (lVar9 = FUN_0051ab50(param_1,iVar11), lVar9 != 0) {
          iVar11 = iVar11 + 1;
        }
        iVar13 = iVar15 * 0x898;
        lVar9 = (u64)(FUN_0051a458(param_1,(u64)(u32)(&DAT_0097bb88 + iVar13),iVar11,1));
        if (lVar9 == 0) goto LAB_005169c4;
        iVar6 = iVar7 * 4;
        iVar7 = iVar7 + 1;
        *(int *)(&DAT_0097b788 + iVar6 + iVar13) = iVar11;
        if ((0xff < iVar7) || (iVar10 == 0)) {
          iVar7 = iVar14 * 4;
          iVar14 = iVar14 + 1;
          lVar9 = (u64)(FUN_0051a458(param_1,(u64)(u32)(&DAT_0097b788 + iVar13),*(u32 *)(iStack_ac + iVar7),1));
          if (lVar9 == 0) goto LAB_005169c4;
          puVar5 = (u32 *)(&DAT_0097bb84 + iVar13);
          iVar13 = 0xff;
          do {
            *puVar5 = 0xffffffff;
            iVar13 = iVar13 + -1;
            puVar5 = puVar5 + -1;
          } while (-1 < iVar13);
          iVar7 = 0;
        }
        iVar11 = iVar11 + 1;
        iVar10 = iVar10 + -1;
      } while (-1 < iVar10);
      uVar1 = *(u16 *)(&DAT_0078280a + iVar8);
    }
    *(int *)(&DAT_00782814 + iVar8) = iVar11;
    iVar13 = 0;
    if (uVar1 == 0) {
      trap(7);
    }
    iVar10 = 0;
    iVar7 = (int)(*(int *)(&DAT_00782824 + iVar8) * (u32)*(u16 *)(&DAT_0078280c + iVar8)) /
            (int)(u32)uVar1 - iVar11;
    *(int *)(&DAT_00782818 + iVar8) = iVar7;
    iVar14 = (*(int *)(&DAT_00782810 + iVar8) / 1000) * 1000 + 1;
    if (0 < iVar7) {
      iVar7 = iStack_b0;
      do {
        iStack_b0 = iVar7;
        if (iVar10 == iVar14) {
          *(int *)(&DAT_00782950 + iVar8) = iVar11 - *(int *)(&DAT_00782814 + iVar8);
        }
        lVar9 = FUN_0051ab50(param_1,iVar11);
        if (lVar9 == 1) {
          FUN_005157e0(param_1,iVar13,0xfffffffffffffffd,(u64)(u32)&iStack_b0);
          iVar7 = iStack_b0;
        }
        else {
          if (iVar10 == 0) {
            *(int *)(&DAT_00782814 + iVar8) = iVar11;
          }
          FUN_005157e0(param_1,iVar13,0x7fffffff,(u64)(u32)&iStack_b0);
          iVar10 = iVar10 + 1;
          iVar7 = iStack_b0;
        }
        if (iVar7 != 0) {
          return iVar7;
        }
        iVar13 = iVar13 + 1;
        iVar11 = iVar11 + 1;
        iStack_b0 = 0;
      } while (iVar13 < *(int *)(&DAT_00782818 + iVar8));
    }
    if (iVar14 <= iVar10) {
      if (*(u16 *)(&DAT_0078280a + iVar8) == 0) {
        trap(7);
      }
      *(int *)(&DAT_00782818 + iVar8) =
           (int)(*(int *)(&DAT_00782824 + iVar8) * (u32)*(u16 *)(&DAT_0078280c + iVar8)) /
           (int)(u32)*(u16 *)(&DAT_0078280a + iVar8) - *(int *)(&DAT_00782814 + iVar8);
      lVar9 = (u64)(FUN_00515910(param_1,(u64)(u32)&iStack_b0));
      if (iStack_b0 != 0) {
        return iStack_b0;
      }
      if (lVar9 == 0) {
        FUN_00521408(0x97c8c0,0,0x200);
        DAT_0097c8c0 = 0x8427;
        (*(u16*)((u8*)&DAT_0097c8c8 + 6)) = (u16)(bStack_c9 >> 4) * 10 + (bStack_c9 & 0xf) + 2000;
        (*(u8*)((u8*)&DAT_0097c8c8 + 5)) = (bStack_ca >> 4) * '\n' + (bStack_ca & 0xf);
        (*(u8*)((u8*)&DAT_0097c8c8 + 1)) = (bStack_cf >> 4) * '\n' + (bStack_cf & 0xf);
        (*(u8*)((u8*)&DAT_0097c8c8 + 4)) = (bStack_cb >> 4) * '\n' + (bStack_cb & 0xf);
        (*(u8*)((u8*)&DAT_0097c8c8 + 3)) = (bStack_cd >> 4) * '\n' + (bStack_cd & 0xf);
        (*(u8*)((u8*)&DAT_0097c8c8 + 2)) = (bStack_ce >> 4) * '\n' + (bStack_ce & 0xf);
        DAT_0097c8c4 = 2;
        DAT_0097c8c2 = 0;
        (*(u8*)((u8*)&DAT_0097c8c8 + 0)) = 0;
        DAT_0097c8d0 = 0;
        DAT_0097c8d4 = 0;
        DAT_0097c8d8 = (u32)CONCAT25((*(u16*)((u8*)&DAT_0097c8c8 + 6)),
                                       CONCAT14((*(u8*)((u8*)&DAT_0097c8c8 + 5)),
                                                CONCAT13((*(u8*)((u8*)&DAT_0097c8c8 + 4)),
                                                         CONCAT12((*(u8*)((u8*)&DAT_0097c8c8 + 3)),
                                                                  CONCAT11((*(unsigned char *)((unsigned char *)&DAT_0097c8c8 + 2)),
                                                                           (*(u8*)((u8*)&DAT_0097c8c8 + 1)))))))
                       << 8;
        DAT_0097c8e0 = 0;
        DAT_0097c900 = DAT_007be5f0;
        DAT_0097c901 = DAT_007be5f1;
        FUN_00521408(0x97cac0,0,0x200);
        (*(u8*)((u8*)&DAT_0097cac8 + 1)) = (bStack_cf >> 4) * '\n' + (bStack_cf & 0xf);
        (*(u8*)((u8*)&DAT_0097cac8 + 3)) = (bStack_cd >> 4) * '\n' + (bStack_cd & 0xf);
        (*(u16*)((u8*)&DAT_0097cac8 + 6)) = (u16)(bStack_c9 >> 4) * 10 + (bStack_c9 & 0xf) + 2000;
        (*(u8*)((u8*)&DAT_0097cac8 + 5)) = (bStack_ca >> 4) * '\n' + (bStack_ca & 0xf);
        (*(u8*)((u8*)&DAT_0097cac8 + 4)) = (bStack_cb >> 4) * '\n' + (bStack_cb & 0xf);
        (*(u8*)((u8*)&DAT_0097cac8 + 2)) = (bStack_ce >> 4) * '\n' + (bStack_ce & 0xf);
        DAT_0097cac0 = 0xa426;
        DAT_0097cac4 = 0;
        DAT_0097cac2 = 0;
        (*(u8*)((u8*)&DAT_0097cac8 + 0)) = 0;
        DAT_0097cad0 = 0;
        DAT_0097cad4 = 0;
        DAT_0097cad8 = (u32)CONCAT25((*(u16*)((u8*)&DAT_0097cac8 + 6)),
                                       CONCAT14((*(u8*)((u8*)&DAT_0097cac8 + 5)),
                                                CONCAT13((*(u8*)((u8*)&DAT_0097cac8 + 4)),
                                                         CONCAT12((*(u8*)((u8*)&DAT_0097cac8 + 3)),
                                                                  CONCAT11((*(unsigned char *)((unsigned char *)&DAT_0097cac8 + 2)),
                                                                           (*(u8*)((u8*)&DAT_0097cac8 + 1)))))))
                       << 8;
        DAT_0097cae0 = 0;
        DAT_0097cb00 = DAT_007be5f8;
        DAT_0097cb01 = DAT_007be5f9;
        DAT_0097cb02 = DAT_007be5fa;
        lVar9 = FUN_0051aa90(param_1,0x97c8c0,0,1);
        if (lVar9 != 0) {
          FUN_005157e0(param_1,0,0xffffffffffffffff,(u64)(u32)&iStack_b0);
          if (iStack_b0 != 0) {
            return iStack_b0;
          }
          lVar9 = FUN_0051a498(param_1);
          if (((lVar9 != 0) && (lVar9 = FUN_00515588(param_1), lVar9 != 0)) &&
             (lVar9 = FUN_0051a2f8(param_1), lVar9 != 0)) {
            (&DAT_0097c010)[iVar15 * 0x226] = 1;
            iVar8 = FUN_00515d80(param_1,0);
            if (iVar8 != -0x7efe6ffd) {
              return iVar8;
            }
            return 0;
          }
        }
        goto LAB_005169c4;
      }
      FUN_00505e48(0x7be640,lVar9);
    }
    iVar8 = -0x7efe6fff;
  }
  return iVar8;
}
// FUN_00516A48 NONMATCHING
u32 FUN_00516a48(u64 param_1)

{
  u8 uVar1;
  u32 uVar2;
  long lVar3;
  int iVar4;
  u8 auStack_50 [4];
  int iStack_4c;
  int iStack_48;
  
  lVar3 = FUN_0051c0c0(0);
  if (lVar3 == 0) {
    uVar2 = 0x81010013;
  }
  else {
    lVar3 = FUN_0051a180(param_1,(int *)(u32)(int *)(u32)auStack_50);
    if (lVar3 == 0) {
LAB_00516a88:
      uVar2 = 0x8101006f;
    }
    else {
      iVar4 = (int)param_1;
      (&DAT_0097c01c)[iVar4 * 0x226] = 0;
      (&DAT_0097bf88)[iVar4 * 0x226] = 0xffffffff;
      (&DAT_0097bf8c)[iVar4 * 0x226] = 0xffffffff;
      (&DAT_0097c018)[iVar4 * 0x226] = 0;
      (&DAT_0097c014)[iVar4 * 0x226] = 0;
      uVar1 = DAT_007be609;
      (&DAT_0097bf90)[iVar4 * 0x898] = DAT_007be608;
      (&DAT_0097bf91)[iVar4 * 0x898] = uVar1;
      if (iStack_4c == 0) {
        trap(7);
      }
      iVar4 = 0;
      if (0 < iStack_48 / iStack_4c) {
        do {
          lVar3 = FUN_0051bbd8(param_1,iVar4);
          iVar4 = iVar4 + 1;
          if (lVar3 == 0) goto LAB_00516a88;
        } while (iVar4 < iStack_48 / iStack_4c);
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}
// FUN_00516B48 NONMATCHING
u32 FUN_00516b48(u64 param_1)

{
  long lVar1;
  
  lVar1 = FUN_0051c0c0(0);
  if (((lVar1 != 0) && (lVar1 = FUN_0051a1a0(param_1), lVar1 != 2)) &&
     ((&DAT_0097c010)[(int)param_1 * 0x226] != 1)) {
    if ((&DAT_0097c014)[(int)param_1 * 0x226] == 0) {
      return 0x8101002f;
    }
    lVar1 = FUN_0051a1c0(param_1);
    if (lVar1 != 0) {
      FUN_0051b4a0(param_1);
      return 0;
    }
  }
  return 0x81010013;
}
// FUN_00516BE8 NONMATCHING
u32 FUN_00516be8(u64 param_1,u64 param_2,u64 param_3)

{
  u32 uVar1;
  long lVar2;
  
  lVar2 = FUN_00515218(0,0,0);
  if ((lVar2 == 0) || (lVar2 = FUN_00514e20((char *)(u32)param_3), lVar2 == 0)) {
    uVar1 = 0x81010016;
  }
  else {
    lVar2 = FUN_00514db0(param_3);
    uVar1 = 0x8101005b;
    if (lVar2 != 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}
// FUN_00516C48 NONMATCHING
int FUN_00516c48(u64 param_1,u64 *param_2,long param_3,u64 param_4,
                u32 param_5,int param_6)

{
  u16 uVar1;
  u16 *puVar2;
  long lVar3;
  u32 uVar4;
  u16 *puVar5;
  u64 uVar6;
  u64 uVar7;
  u64 uVar8;
  int iVar9;
  int iVar10;
  u16 auStack_4b0 [32];
  u8 auStack_470 [512];
  u8 auStack_270 [448];
  int iStack_b0;
  int iStack_ac;
  
  iVar10 = 0;
  iStack_b0 = 0;
  iStack_ac = 1;
  do {
    lVar3 = FUN_0051a9e0(param_1,(u64)(u32)auStack_4b0,param_5,1);
    if (lVar3 == 0) {
      return -0x7efeff91;
    }
    if (iStack_ac != 0) {
      iStack_ac = 0;
      uVar4 = FUN_00524388(auStack_470);
      if (0x1f < uVar4) {
        return -0x7efe6ffe;
      }
      lVar3 = FUN_00524128(auStack_470,0x7be5f0);
      if (lVar3 != 0) {
        return -0x7efe6ffe;
      }
      uVar4 = FUN_00524388(auStack_270);
      if (0x1f < uVar4) {
        return -0x7efe6ffe;
      }
      lVar3 = FUN_00524128(auStack_270,0x7be5f8);
      if (lVar3 != 0) {
        return -0x7efe6ffe;
      }
    }
    iVar9 = 0;
    uVar1 = auStack_4b0[0];
    puVar5 = auStack_4b0;
    if (param_6 != 0) {
      while( true ) {
        if ((uVar1 & 0x8000) != 0) {
          *(u8 *)((int)puVar5 + 0x5f) = 0;
          lVar3 = FUN_00524128(param_4,puVar5 + 0x20);
          if (lVar3 == 0) {
            if (param_2 != (u64 *)0x0) {
              if (((u32)param_2 & 7) == 0) {
                puVar2 = puVar5 + 0x100;
                do {
                  uVar6 = *(u64 *)(puVar5 + 4);
                  uVar7 = *(u64 *)(puVar5 + 8);
                  uVar8 = *(u64 *)(puVar5 + 0xc);
                  *param_2 = *(u64 *)puVar5;
                  param_2[1] = uVar6;
                  param_2[2] = uVar7;
                  param_2[3] = uVar8;
                  puVar5 = puVar5 + 0x10;
                  param_2 = param_2 + 4;
                } while (puVar5 != puVar2);
              }
              else {
                puVar2 = puVar5 + 0x100;
                do {
                  uVar6 = *(u64 *)(puVar5 + 4);
                  uVar7 = *(u64 *)(puVar5 + 8);
                  uVar8 = *(u64 *)(puVar5 + 0xc);
                  *param_2 = *(u64 *)puVar5;
                  param_2[1] = uVar6;
                  param_2[2] = uVar7;
                  param_2[3] = uVar8;
                  puVar5 = puVar5 + 0x10;
                  param_2 = param_2 + 4;
                } while (puVar5 != puVar2);
              }
            }
            if (param_3 != 0) {
              *(int *)param_3 = iVar10;
            }
            return 0;
          }
        }
        iVar9 = iVar9 + 1;
        param_6 = param_6 - (u32)(0 < param_6);
        iVar10 = iVar10 + 1;
        if ((1 < iVar9) || (param_6 == 0)) break;
        uVar1 = puVar5[0x100];
        puVar5 = puVar5 + 0x100;
      }
    }
    param_5 = (u64)(u32)FUN_00515730(param_1,param_5,(u32 *)(u32)&iStack_b0);
    if (iStack_b0 != 0) {
      return iStack_b0;
    }
    if (param_5 == 0xffffffffffffffff) {
      return -0x7efefffe;
    }
    param_5 = param_5 & 0x7fffffff;
  } while( true );
}
// FUN_00516EC0 NONMATCHING
long FUN_00516ec0(u64 param_1,u64 param_2,u64 *param_3,u32 *param_4,
                 u32 *param_5)

{
  bool bVar1;
  long lVar2;
  u32 uVar3;
  long lVar4;
  u16 *puVar5;
  u16 *puVar6;
  u64 *puVar7;
  u16 *puVar8;
  u16 *puVar9;
  u64 *puVar10;
  u64 uVar11;
  u64 uVar12;
  u64 uVar13;
  u16 auStack_4d0 [32];
  u8 auStack_490 [448];
  u64 uStack_2d0;
  u32 uStack_2c0;
  u64 auStack_d0 [4];
  u32 uStack_b0;
  u32 *puStack_ac;
  u32 *puStack_a8;
  u32 *puStack_a4;
  
  puVar5 = auStack_4d0;
  puVar6 = auStack_4d0;
  puVar8 = auStack_4d0;
  puVar9 = auStack_4d0;
  bVar1 = false;
  puStack_ac = param_4;
  puStack_a8 = param_5;
  lVar2 = FUN_00515b18(param_1,(u64 *)(u32)auStack_4d0,*(u32 *)(&DAT_0078281c + (int)param_1 * 0x184),0);
  if (lVar2 == 0) {
    uVar3 = FUN_00524388(auStack_490);
    if ((uVar3 < 0x20) && (lVar2 = FUN_00524128(auStack_490,0x7be5f0), lVar2 == 0)) {
      lVar2 = FUN_00524128(param_2,0x7be608);
      if (lVar2 == 0) {
        if (((u32)param_3 & 7) == 0) {
          do {
            uVar11 = *(u64 *)((int)puVar6 + 8);
            uVar12 = *(u64 *)((int)puVar6 + 0x10);
            uVar13 = *(u64 *)((int)puVar6 + 0x18);
            *param_3 = *(u64 *)puVar6;
            param_3[1] = uVar11;
            param_3[2] = uVar12;
            param_3[3] = uVar13;
            puVar6 = (u16 *)((int)puVar6 + 0x20);
            param_3 = param_3 + 4;
          } while (puVar6 != (u16 *)&uStack_2d0);
        }
        else {
          do {
            uVar11 = *(u64 *)((int)puVar5 + 8);
            uVar12 = *(u64 *)((int)puVar5 + 0x10);
            uVar13 = *(u64 *)((int)puVar5 + 0x18);
            *param_3 = *(u64 *)puVar5;
            param_3[1] = uVar11;
            param_3[2] = uVar12;
            param_3[3] = uVar13;
            puVar5 = (u16 *)((int)puVar5 + 0x20);
            param_3 = param_3 + 4;
          } while (puVar5 != (u16 *)&uStack_2d0);
        }
      }
      else {
        lVar2 = (long)(FUN_005150b0(param_2,0x7be608));
        puStack_a4 = &uStack_b0;
        puVar10 = &uStack_2d0;
        while( true ) {
          FUN_00524270(auStack_d0,lVar2);
          lVar2 = (long)(FUN_005150b0(0,0x7be608));
          puVar5 = auStack_4d0;
          puVar7 = puVar10;
          if (lVar2 == 0) {
            bVar1 = true;
            puVar5 = auStack_4d0;
          }
          do {
            uVar13 = *(u64 *)((int)puVar5 + 8);
            uVar11 = *(u64 *)((int)puVar5 + 0x10);
            uVar12 = *(u64 *)((int)puVar5 + 0x18);
            *puVar7 = *(u64 *)puVar5;
            puVar7[1] = uVar13;
            puVar7[2] = uVar11;
            puVar7[3] = uVar12;
            puVar5 = (u16 *)((int)puVar5 + 0x20);
            puVar7 = puVar7 + 4;
          } while (puVar5 != (u16 *)puVar10);
          lVar4 = FUN_00516c48(param_1,(u64 *)(unsigned long)auStack_4d0,(long)(unsigned long)puStack_a4,(u64)(unsigned long)auStack_d0,uStack_2c0,(u32)(uStack_2d0 >> 32)
                              );
          if ((auStack_4d0[0] & 0x2000) != 0) {
            return -0x7efefff3;
          }
          if (bVar1) break;
          if (lVar4 != 0) {
            if (lVar4 == -0x7efefffe) {
              return -0x7efe6001;
            }
            return lVar4;
          }
        }
        if (lVar4 != 0) {
          if (lVar4 != -0x7efefffe) {
            return lVar4;
          }
          if (param_3 != (u64 *)0x0) {
            if (((u32)param_3 & 7) == 0) {
              do {
                uVar11 = puVar10[1];
                uVar12 = puVar10[2];
                uVar13 = puVar10[3];
                *param_3 = *puVar10;
                param_3[1] = uVar11;
                param_3[2] = uVar12;
                param_3[3] = uVar13;
                puVar10 = puVar10 + 4;
                param_3 = param_3 + 4;
              } while (puVar10 != auStack_d0);
            }
            else {
              do {
                uVar12 = puVar10[1];
                uVar13 = puVar10[2];
                uVar11 = puVar10[3];
                *param_3 = *puVar10;
                param_3[1] = uVar12;
                param_3[2] = uVar13;
                param_3[3] = uVar11;
                puVar10 = puVar10 + 4;
                param_3 = param_3 + 4;
              } while (puVar10 != auStack_d0);
            }
          }
          if (puStack_a8 != (u32 *)0x0) {
            *puStack_a8 = 0;
          }
          if (puStack_ac != (u32 *)0x0) {
            *puStack_ac = uStack_2c0;
          }
          return -0x7efefffe;
        }
        if (param_3 != (u64 *)0x0) {
          if (((u32)param_3 & 7) == 0) {
            do {
              uVar12 = *(u64 *)((int)puVar9 + 8);
              uVar13 = *(u64 *)((int)puVar9 + 0x10);
              uVar11 = *(u64 *)((int)puVar9 + 0x18);
              *param_3 = *(u64 *)puVar9;
              param_3[1] = uVar12;
              param_3[2] = uVar13;
              param_3[3] = uVar11;
              puVar9 = (u16 *)((int)puVar9 + 0x20);
              param_3 = param_3 + 4;
            } while (puVar9 != (u16 *)puVar10);
          }
          else {
            do {
              uVar13 = *(u64 *)((int)puVar8 + 8);
              uVar11 = *(u64 *)((int)puVar8 + 0x10);
              uVar12 = *(u64 *)((int)puVar8 + 0x18);
              *param_3 = *(u64 *)puVar8;
              param_3[1] = uVar13;
              param_3[2] = uVar11;
              param_3[3] = uVar12;
              puVar8 = (u16 *)((int)puVar8 + 0x20);
              param_3 = param_3 + 4;
            } while (puVar8 != (u16 *)puVar10);
          }
        }
        if (puStack_a8 != (u32 *)0x0) {
          *puStack_a8 = uStack_b0;
        }
        if (puStack_ac != (u32 *)0x0) {
          *puStack_ac = uStack_2c0;
        }
      }
      lVar2 = -0x7efeffef;
    }
    else {
      lVar2 = -0x7efe6ffe;
    }
  }
  return lVar2;
}
// FUN_00517310 NONMATCHING
int FUN_00517310(u64 param_1,u64 *param_2,u32 param_3,int param_4)

{
  u64 *puVar1;
  long lVar2;
  u32 uVar3;
  u64 *puVar4;
  u64 uVar5;
  u64 uVar6;
  u64 uVar7;
  int iVar8;
  int aiStack_90 [4];
  
  aiStack_90[0] = 0;
  iVar8 = -0x7efeff91;
  for (; 1 < param_4; param_4 = param_4 + -2) {
    uVar3 = (u32)FUN_00515730(param_1,param_3,(u32 *)(u32)aiStack_90);
    if (aiStack_90[0] != 0) {
      return aiStack_90[0];
    }
    param_3 = uVar3 & 0x7fffffff;
    if (uVar3 == 0xffffffffffffffff) goto LAB_00517484;
  }
  lVar2 = FUN_0051a9e0(param_1,0x97c8c0,param_3,1);
  if (lVar2 == 0) {
LAB_00517484:
    iVar8 = -0x7efeff91;
  }
  else {
    puVar4 = (u64 *)(&DAT_0097c8c0 + param_4 * 0x100);
    puVar1 = param_2 + 0x40;
    if (((u32)param_2 & 7) == 0) {
      do {
        uVar5 = param_2[1];
        uVar6 = param_2[2];
        uVar7 = param_2[3];
        *puVar4 = *param_2;
        puVar4[1] = uVar5;
        puVar4[2] = uVar6;
        puVar4[3] = uVar7;
        param_2 = param_2 + 4;
        puVar4 = puVar4 + 4;
      } while (param_2 != puVar1);
    }
    else {
      do {
        uVar5 = param_2[1];
        uVar6 = param_2[2];
        uVar7 = param_2[3];
        *puVar4 = *param_2;
        puVar4[1] = uVar5;
        puVar4[2] = uVar6;
        puVar4[3] = uVar7;
        param_2 = param_2 + 4;
        puVar4 = puVar4 + 4;
      } while (param_2 != puVar1);
    }
    lVar2 = FUN_0051aa90(param_1,0x97c8c0,param_3,1);
    if (lVar2 != 0) {
      iVar8 = 0;
    }
  }
  return iVar8;
}
// FUN_005174B8 NONMATCHING
int FUN_005174b8(u64 param_1,u32 param_2,int param_3,u64 param_4)

{
  long lVar1;
  u32 uVar2;
  u16 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar5 = 0;
  piVar6 = (int *)param_4;
  *piVar6 = 0;
  do {
    lVar1 = FUN_0051a9e0(param_1,0x97c8c0,param_2,1);
    iVar4 = 0;
    puVar3 = (u16 *)(&DAT_0097c8c0);
    if (lVar1 == 0) {
      *piVar6 = -0x7efeff91;
      return -1;
    }
    do {
      param_3 = param_3 + -1;
      if ((*puVar3 & 0x8000) == 0) {
        iVar5 = iVar5 + 1;
      }
      if (param_3 == 0) {
        if (iVar4 == 0) {
          return iVar5 + 1;
        }
        return iVar5;
      }
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 0x100;
    } while (iVar4 < 2);
    uVar2 = (u32)FUN_00515730(param_1,param_2,(u32 *)(u32)param_4);
    if (*piVar6 != 0) {
      return -1;
    }
    param_2 = uVar2 & 0x7fffffff;
  } while (uVar2 != 0xffffffffffffffff);
  return iVar5;
}
// FUN_005175E8 NONMATCHING
int FUN_005175e8(u64 param_1,u64 *param_2,u32 param_3,int param_4,u64 param_5
                )

{
  u16 uVar1;
  long lVar2;
  u32 uVar3;
  u16 *puVar4;
  u64 *puVar5;
  u64 uVar6;
  u64 uVar7;
  u64 uVar8;
  u16 *puVar9;
  u64 *puVar10;
  int *piVar11;
  int iVar12;
  u8 auStack_4b0 [4];
  int iStack_4ac;
  u64 auStack_2b0 [2];
  int iStack_2a0;
  u32 uStack_29c;
  u64 auStack_298 [61];
  int iStack_b0;
  u32 uStack_ac;
  
  iStack_2a0 = -1;
  uStack_ac = (u32)(param_3 == 0);
  iStack_b0 = 0;
  do {
    lVar2 = FUN_0051a9e0(param_1,0x97c8c0,param_3,1);
    iVar12 = 0;
    piVar11 = (int *)param_5;
    if (lVar2 == 0) goto LAB_00517a7c;
    puVar9 = (u16 *)(&DAT_0097c8c0);
    do {
      if ((*puVar9 & 0x8000) == 0) {
LAB_0051775c:
        if (((u32)param_2 & 7) == 0) {
          puVar10 = param_2 + 0x40;
          do {
            uVar7 = param_2[1];
            uVar8 = param_2[2];
            uVar6 = param_2[3];
            *(u64 *)puVar9 = *param_2;
            *(u64 *)(puVar9 + 4) = uVar7;
            *(u64 *)(puVar9 + 8) = uVar8;
            *(u64 *)(puVar9 + 0xc) = uVar6;
            param_2 = param_2 + 4;
            puVar9 = puVar9 + 0x10;
          } while (param_2 != puVar10);
        }
        else {
          puVar10 = param_2 + 0x40;
          do {
            uVar8 = param_2[1];
            uVar6 = param_2[2];
            uVar7 = param_2[3];
            *(u64 *)puVar9 = *param_2;
            *(u64 *)(puVar9 + 4) = uVar8;
            *(u64 *)(puVar9 + 8) = uVar6;
            *(u64 *)(puVar9 + 0xc) = uVar7;
            param_2 = param_2 + 4;
            puVar9 = puVar9 + 0x10;
          } while (param_2 != puVar10);
        }
        lVar2 = FUN_0051aa90(param_1,0x97c8c0,param_3,1);
        if (lVar2 == 0) {
          *piVar11 = -0x7efeff91;
          return -1;
        }
        if (param_4 != 0) {
          *piVar11 = 0;
          return iStack_b0;
        }
        if (iStack_2a0 == -1) {
          *piVar11 = -0x7efe6ffe;
          return -1;
        }
        goto LAB_00517a18;
      }
      lVar2 = FUN_00524128(puVar9 + 0x20,0x7be5f0);
      if (lVar2 == 0) {
        puVar10 = auStack_2b0;
        puVar4 = puVar9;
        do {
          uVar6 = *(u64 *)(puVar4 + 4);
          uVar7 = *(u64 *)(puVar4 + 8);
          uVar8 = *(u64 *)(puVar4 + 0xc);
          *puVar10 = *(u64 *)puVar4;
          puVar10[1] = uVar6;
          puVar10[2] = uVar7;
          puVar10[3] = uVar8;
          puVar4 = puVar4 + 0x10;
          puVar10 = puVar10 + 4;
        } while (puVar4 != puVar9 + 0x100);
        uVar1 = *puVar9;
      }
      else {
        uVar1 = *puVar9;
      }
      if (((uVar1 & 0x8000) == 0) || (param_4 == 0)) goto LAB_0051775c;
      iVar12 = iVar12 + 1;
      param_4 = param_4 - (u32)(0 < param_4);
      iStack_b0 = iStack_b0 + 1;
      puVar9 = puVar9 + 0x100;
    } while (iVar12 < 2);
    if ((uStack_ac == 0) && (0x13 < iStack_b0)) {
      *piVar11 = -0x7efeffe9;
      return -1;
    }
    uVar3 = (u32)FUN_00515730(param_1,param_3,(u32 *)(u32)param_5);
    if (*piVar11 != 0) {
      return -1;
    }
    if (uVar3 == 0xffffffffffffffff) {
      uVar3 = FUN_00515910(param_1,param_5);
      if (*piVar11 != 0) {
        return -1;
      }
      FUN_005157e0(param_1,param_3,uVar3 | 0xffffffff80000000,param_5);
      if (*piVar11 != 0) {
        return -1;
      }
      FUN_005157e0(param_1,uVar3,0xffffffffffffffff,param_5);
      if (*piVar11 != 0) {
        return -1;
      }
      puVar10 = (u64 *)&DAT_0097c8c0;
      if (((u32)param_2 & 7) == 0) {
        puVar5 = param_2 + 0x40;
        do {
          uVar6 = param_2[1];
          uVar7 = param_2[2];
          uVar8 = param_2[3];
          *puVar10 = *param_2;
          puVar10[1] = uVar6;
          puVar10[2] = uVar7;
          puVar10[3] = uVar8;
          param_2 = param_2 + 4;
          puVar10 = puVar10 + 4;
        } while (param_2 != puVar5);
      }
      else {
        puVar5 = param_2 + 0x40;
        do {
          uVar6 = param_2[1];
          uVar7 = param_2[2];
          uVar8 = param_2[3];
          *puVar10 = *param_2;
          puVar10[1] = uVar6;
          puVar10[2] = uVar7;
          puVar10[3] = uVar8;
          param_2 = param_2 + 4;
          puVar10 = puVar10 + 4;
        } while (param_2 != puVar5);
      }
      DAT_0097cac0 = 0;
      lVar2 = FUN_0051aa90(param_1,0x97c8c0,uVar3,1);
      if (lVar2 == 0) {
LAB_00517a7c:
        *piVar11 = -0x7efeff91;
      }
      else {
        if (iStack_2a0 == -1) {
          return -0x7efe6ffe;
        }
LAB_00517a18:
        lVar2 = FUN_00515b18(param_1,(u64 *)(u32)auStack_4b0,iStack_2a0,uStack_29c);
        *piVar11 = (int)lVar2;
        if (lVar2 == 0) {
          iStack_4ac = iStack_4ac + 1;
          lVar2 = FUN_00517310(param_1,(u64 *)(u32)auStack_4b0,iStack_2a0,uStack_29c);
          *piVar11 = (int)lVar2;
          if (lVar2 == 0) {
            *piVar11 = 0;
            return iStack_b0;
          }
        }
      }
      return -1;
    }
    param_3 = uVar3 & 0x7fffffff;
  } while( true );
}
// FUN_00517AB8 NONMATCHING
long FUN_00517ab8(u64 param_1,u64 param_2,int param_3)

{
  long lVar1;
  u8 auStack_430 [25];
  char cStack_417;
  char cStack_416;
  char cStack_415;
  char cStack_414;
  char cStack_413;
  short sStack_412;
  Vec128 auStack_230;
  u32 uStack_220;
  u32 uStack_21c;
  u8 auStack_1f0 [448];
  
  lVar1 = FUN_00515b18(param_1,(u64 *)(u32)(&auStack_230),param_2,0);
  if (lVar1 == 0) {
    lVar1 = FUN_00524128(auStack_1f0,0x7be5f0);
    if (lVar1 == 0) {
      lVar1 = FUN_00515b18(param_1,(u64 *)(u32)auStack_430,uStack_220,uStack_21c);
      if (lVar1 == 0) {
        cStack_415 = (*(u8 *)(param_3 + 3) >> 4) * '\n' + (*(u8 *)(param_3 + 3) & 0xf);
        cStack_416 = (*(u8 *)(param_3 + 2) >> 4) * '\n' + (*(u8 *)(param_3 + 2) & 0xf);
        cStack_413 = (*(u8 *)(param_3 + 6) >> 4) * '\n' + (*(u8 *)(param_3 + 6) & 0xf);
        cStack_414 = (*(u8 *)(param_3 + 5) >> 4) * '\n' + (*(u8 *)(param_3 + 5) & 0xf);
        cStack_417 = (*(u8 *)(param_3 + 1) >> 4) * '\n' + (*(u8 *)(param_3 + 1) & 0xf);
        sStack_412 = (u16)(*(u8 *)(param_3 + 7) >> 4) * 10 + (*(u8 *)(param_3 + 7) & 0xf) +
                     2000;
        lVar1 = FUN_00517310(param_1,(u64 *)(u32)auStack_430,uStack_220,uStack_21c);
      }
    }
    else {
      lVar1 = -0x7efe6ffe;
    }
  }
  return lVar1;
}
// FUN_00517BE8 NONMATCHING
long FUN_00517be8(u64 param_1,u64 param_2,long param_3)

{
  long lVar1;
  long lVar2;
  u64 *puVar3;
  u16 auStack_300 [2];
  u32 uStack_2fc;
  u64 uStack_2f8;
  u64 uStack_2e8;
  u8 auStack_2c0 [480];
  u8 auStack_e0 [128];
  
  lVar1 = FUN_00516b48(0);
  if (lVar1 == 0) {
    lVar1 = (u64)(FUN_00516be8(param_1,param_2,(u64)(u32)auStack_e0));
    if (lVar1 == 0) {
      lVar2 = (u64)(FUN_00516ec0(param_1,(u64)(u32)auStack_e0,(u64 *)(u32)auStack_300,0,0));
      lVar1 = 0;
      if (lVar2 != -0x7efeffef) {
        lVar1 = lVar2;
      }
      if ((param_3 != 0) && (lVar1 == 0)) {
        puVar3 = (u64 *)param_3;
        FUN_00524270(puVar3 + 3,auStack_2c0);
        *puVar3 = uStack_2f8;
        puVar3[1] = uStack_2e8;
        *(u16 *)((int)puVar3 + 0x14) = auStack_300[0];
        *(u32 *)(puVar3 + 2) = uStack_2fc;
      }
    }
  }
  return lVar1;
}
// FUN_00517CD8 NONMATCHING
int FUN_00517cd8(u64 param_1,u64 param_2,u32 param_3)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int unaff_s3_lo;
  u32 uVar4;
  u32 uVar5;
  u64 unaff_s8;
  u8 auStack_540 [4];
  int iStack_53c;
  u32 uStack_530;
  u16 uStack_340;
  u16 uStack_33e;
  u32 uStack_33c;
  u8 uStack_338;
  char cStack_337;
  char cStack_336;
  char cStack_335;
  char cStack_334;
  char cStack_333;
  short sStack_332;
  u32 uStack_330;
  u32 uStack_32c;
  long lStack_328;
  u32 uStack_320;
  u64 uStack_300;
  u64 uStack_2f8;
  u64 uStack_2f0;
  u64 uStack_2e8;
  u8 auStack_140 [128];
  u8 uStack_c0;
  u8 bStack_bf;
  u8 bStack_be;
  u8 bStack_bd;
  u8 bStack_bb;
  u8 bStack_ba;
  u8 bStack_b9;
  int iStack_b0;
  u8 *puStack_ac;
  
  iStack_b0 = FUN_00516b48(0);
  if (iStack_b0 != 0) {
    return iStack_b0;
  }
  iStack_b0 = (u64)(FUN_00516be8(param_1,param_2,(u64)(u32)auStack_140));
  if (iStack_b0 != 0) {
    return iStack_b0;
  }
  if (param_3 == 0) {
    param_3 = 0x8417;
  }
  uVar4 = param_3 & 0x20;
  if ((uVar4 != 0) && (lVar2 = FUN_005151d0((char *)(u32)auStack_140), 1 < lVar2)) {
    return -0x7efe6ffc;
  }
  lVar2 = FUN_005151d0((char *)(u32)auStack_140);
  iStack_b0 = (u64)(FUN_00516ec0(param_1,(u64)(u32)auStack_140,(u64 *)(u32)auStack_540,0,0));
  if (iStack_b0 != -0x7efefffe) {
    return iStack_b0;
  }
  if ((lVar2 != 1) && (0x13 < iStack_53c - unaff_s3_lo)) {
    return -0x7efeffe9;
  }
  iVar1 = (u64)(FUN_00515a40(param_1,(u64)(u32)&iStack_b0));
  if (iStack_b0 != 0) {
    return iStack_b0;
  }
  lVar2 = (u64)(FUN_005174b8(param_1,uStack_530,iStack_53c,(u64)(u32)&iStack_b0));
  if (iStack_b0 != 0) {
    return iStack_b0;
  }
  iVar3 = 1;
  if (uVar4 != 0) {
    iVar3 = 2;
  }
  if ((int)((u32)(0 < lVar2) + iVar1) < iVar3) {
    return -0x7efeffe4;
  }
  if (uVar4 != 0) {
    unaff_s8 = (u64)(FUN_00515910(param_1,(u64)(u32)&iStack_b0));
    if (iStack_b0 != 0) {
      return iStack_b0;
    }
    FUN_005157e0(param_1,unaff_s8,0xffffffffffffffff,(u64)(u32)&iStack_b0);
    if (iStack_b0 != 0) {
      return iStack_b0;
    }
  }
  uVar5 = (u32)unaff_s8;
  puStack_ac = &uStack_c0;
  FUN_0051b5f0(param_1,(u64 *)(u32)puStack_ac);
  FUN_00521408(&uStack_340,0,0x200);
  uStack_33c = 2;
  cStack_334 = (bStack_bb >> 4) * '\n' + (bStack_bb & 0xf);
  cStack_335 = (bStack_bd >> 4) * '\n' + (bStack_bd & 0xf);
  cStack_336 = (bStack_be >> 4) * '\n' + (bStack_be & 0xf);
  cStack_337 = (bStack_bf >> 4) * '\n' + (bStack_bf & 0xf);
  cStack_333 = (bStack_ba >> 4) * '\n' + (bStack_ba & 0xf);
  if (uVar4 == 0) {
    uStack_33c = 0;
    uVar5 = 0xffffffff;
  }
  sStack_332 = (u16)(bStack_b9 >> 4) * 10 + (bStack_b9 & 0xf) + 2000;
  uStack_340 = (u16)param_3;
  uStack_33e = 0;
  uStack_338 = 0;
  uStack_32c = 0;
  lStack_328 = (u32)CONCAT25(sStack_332,
                               CONCAT14(cStack_333,
                                        CONCAT13(cStack_334,
                                                 CONCAT12(cStack_335,CONCAT11(cStack_336,cStack_337)
                                                         )))) << 8;
  uStack_320 = 0;
  uStack_330 = uVar5;
  iVar1 = FUN_005249e8(auStack_140,0x2f);
  uStack_300 = *(u64 *)(iVar1 + 1);
  uStack_2f8 = *(u64 *)(iVar1 + 9);
  uStack_2f0 = *(u64 *)(iVar1 + 0x11);
  uStack_2e8 = *(u64 *)(iVar1 + 0x19);
  lVar2 = FUN_005175e8(param_1,(u64 *)(u32)&uStack_340,uStack_530,iStack_53c,(u64)(u32)&iStack_b0);
  if (lVar2 < 0) {
    return iStack_b0;
  }
  if (uVar4 != 0) {
    FUN_00521408(0x97c8c0,0,0x200);
    DAT_0097c8c0 = 0x8427;
    (*(u8*)((u8*)&DAT_0097c8c8 + 4)) = (bStack_bb >> 4) * '\n' + (bStack_bb & 0xf);
    (*(u8*)((u8*)&DAT_0097c8c8 + 3)) = (bStack_bd >> 4) * '\n' + (bStack_bd & 0xf);
    (*(u8*)((u8*)&DAT_0097c8c8 + 1)) = (bStack_bf >> 4) * '\n' + (bStack_bf & 0xf);
    (*(u8*)((u8*)&DAT_0097c8c8 + 2)) = (bStack_be >> 4) * '\n' + (bStack_be & 0xf);
    (*(u16*)((u8*)&DAT_0097c8c8 + 6)) = (u16)(bStack_b9 >> 4) * 10 + (bStack_b9 & 0xf) + 2000;
    (*(u8*)((u8*)&DAT_0097c8c8 + 5)) = (bStack_ba >> 4) * '\n' + (bStack_ba & 0xf);
    DAT_0097c8d4 = (u32)lVar2;
    DAT_0097c8c4 = 0;
    DAT_0097c8c2 = 0;
    DAT_0097c8d0 = 0;
    DAT_0097c8d8 = CONCAT26((*(u16*)((u8*)&DAT_0097c8c8 + 6)),
                            CONCAT15((*(u8*)((u8*)&DAT_0097c8c8 + 5)),
                                     CONCAT14((*(u8*)((u8*)&DAT_0097c8c8 + 4)),
                                              CONCAT13((*(u8*)((u8*)&DAT_0097c8c8 + 3)),
                                                       CONCAT12((*(u8*)((u8*)&DAT_0097c8c8 + 2)),
                                                                CONCAT11(((u8 *)&DAT_0097c8c8)[1],
                                                                         (u8)DAT_0097c8c8)))
                                             )));
    DAT_0097c900 = DAT_007be5f0;
    DAT_0097c901 = DAT_007be5f1;
    FUN_00521408(0x97cac0,0,0x200);
    (*(u8*)((u8*)&DAT_0097cac8 + 1)) = (bStack_bf >> 4) * '\n' + (bStack_bf & 0xf);
    (*(u8*)((u8*)&DAT_0097cac8 + 4)) = (bStack_bb >> 4) * '\n' + (bStack_bb & 0xf);
    (*(u16*)((u8*)&DAT_0097cac8 + 6)) = (u16)(bStack_b9 >> 4) * 10 + (bStack_b9 & 0xf) + 2000;
    (*(u8*)((u8*)&DAT_0097cac8 + 5)) = (bStack_ba >> 4) * '\n' + (bStack_ba & 0xf);
    (*(u8*)((u8*)&DAT_0097cac8 + 2)) = (bStack_be >> 4) * '\n' + (bStack_be & 0xf);
    (*(u8*)((u8*)&DAT_0097cac8 + 3)) = (bStack_bd >> 4) * '\n' + (bStack_bd & 0xf);
    DAT_0097cac0 = 0x8427;
    DAT_0097cac4 = 0;
    DAT_0097cac2 = 0;
    (*(u8*)((u8*)&DAT_0097cac8 + 0)) = 0;
    DAT_0097cad0 = 0;
    DAT_0097cad4 = 0;
    DAT_0097cad8 = (u32)CONCAT25((*(u16*)((u8*)&DAT_0097cac8 + 6)),
                                   CONCAT14((*(u8*)((u8*)&DAT_0097cac8 + 5)),
                                            CONCAT13((*(u8*)((u8*)&DAT_0097cac8 + 4)),
                                                     CONCAT12((*(u8*)((u8*)&DAT_0097cac8 + 3)),
                                                              CONCAT11((*(unsigned char *)((unsigned char *)&DAT_0097cac8 + 2)),
                                                                       (*(u8*)((u8*)&DAT_0097cac8 + 1))))))) << 8;
    DAT_0097cae0 = 0;
    DAT_0097cb00 = DAT_007be5f8;
    DAT_0097cb01 = DAT_007be5f9;
    DAT_0097cb02 = DAT_007be5fa;
    lVar2 = FUN_0051aa90(param_1,0x97c8c0,uStack_330,1);
    if (lVar2 == 0) {
      return -0x7efeff91;
    }
  }
  iStack_b0 = (int)(FUN_00517ab8(param_1,uStack_530,(int)(u32)puStack_ac));
  if (iStack_b0 == 0) {
    lVar2 = FUN_00515588(param_1);
    if ((lVar2 != 0) && (lVar2 = FUN_0051a498(param_1), lVar2 != 0)) {
      return iStack_b0;
    }
    return -0x7efeff91;
  }
  return iStack_b0;
}
// FUN_00518268 NONMATCHING
int FUN_00518268(u64 param_1,u64 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  int iVar4;
  u32 uVar5;
  u16 auStack_330 [2];
  int iStack_32c;
  u32 uStack_320;
  u8 auStack_130 [128];
  int aiStack_b0 [4];
  
  iVar1 = FUN_00516b48(0);
  if (iVar1 == 0) {
    iVar1 = (u64)(FUN_00516be8(param_1,param_2,(u64)(u32)auStack_130));
    if ((iVar1 == 0) &&
       (iVar1 = FUN_00516ec0(param_1,(u64)(u32)auStack_130,(u64 *)(u32)auStack_330,0,0), iVar1 == -0x7efeffef)) {
      if (((auStack_330[0] & 1) == 0) || ((auStack_330[0] & 0x2000) != 0)) {
        iVar1 = -0x7efefff3;
      }
      else if ((auStack_330[0] & 0x20) == 0) {
        iVar4 = iStack_32c - param_4;
        if (iStack_32c < param_4) {
          iVar1 = -0x7efeffea;
        }
        else {
          if (param_5 == 0) {
            param_5 = iVar4;
          }
          uVar5 = uStack_320;
          iVar1 = param_5;
          if (iStack_32c < param_5 + param_4) {
            param_5 = iVar4;
            iVar1 = iVar4;
          }
          while (param_5 != 0) {
            if (param_4 < 0x400) {
              lVar3 = FUN_0051a9e0(param_1,0x97c8c0,uVar5,1);
              aiStack_b0[0] = (int)lVar3;
              if (lVar3 == 0) {
                return -0x7efeff91;
              }
              if (param_5 <= 0x400 - param_4) {
                FUN_00521250(param_3,(int)&DAT_0097c8c0 + param_4,param_5);
                return iVar1;
              }
              FUN_00521250(param_3,(int)&DAT_0097c8c0 + param_4);
              param_5 = param_5 + -0x400 + param_4;
              param_3 = (param_3 + 0x400) - param_4;
              param_4 = 0;
            }
            uVar2 = (u32)FUN_00515730(param_1,uVar5,(u32 *)(u32)aiStack_b0);
            if (aiStack_b0[0] != 0) {
              return aiStack_b0[0];
            }
            uVar5 = uVar2 & 0x7fffffff;
            if (uVar2 == 0xffffffff) {
              return -0x7efe6ffe;
            }
            aiStack_b0[0] = 0;
            if (param_4 != 0) {
              param_4 = param_4 + -0x400;
            }
          }
        }
      }
      else {
        iVar1 = -0x7efefffe;
      }
    }
  }
  return iVar1;
}
// FUN_00518470 NONMATCHING
int FUN_00518470(u64 param_1,u64 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  u16 auStack_320 [2];
  int iStack_31c;
  int iStack_310;
  u8 auStack_120 [128];
  int aiStack_a0 [4];
  
  aiStack_a0[0] = FUN_00516b48(0);
  if (aiStack_a0[0] != 0) {
    return aiStack_a0[0];
  }
  aiStack_a0[0] = (u64)(FUN_00516be8(param_1,param_2,(u64)(u32)auStack_120));
  if (aiStack_a0[0] != 0) {
    return aiStack_a0[0];
  }
  iVar1 = (u64)(FUN_00516ec0(param_1,(u64)(u32)auStack_120,(u64 *)(u32)auStack_320,0,0));
  if (iVar1 != -0x7efeffef) {
    return iVar1;
  }
  if (((auStack_320[0] & 1) == 0) || ((auStack_320[0] & 0x2000) != 0)) {
    return -0x7efefff3;
  }
  if ((auStack_320[0] & 0x20) != 0) {
    return -0x7efefffe;
  }
  if (iStack_31c < param_4) {
    return -0x7efeffea;
  }
  if (param_5 == 0) {
    param_5 = iStack_31c - param_4;
  }
  if (iStack_31c < param_5 + param_4) {
    param_5 = iStack_31c - param_4;
  }
  aiStack_a0[0] = -0x7efeffef;
  iVar1 = iStack_310;
  if (0x3ff < param_4) {
    do {
      iVar1 = FUN_00515778(param_1,iVar1,aiStack_a0);
      if (aiStack_a0[0] == -0x7efeffa7) {
        return -0x7efe6ffe;
      }
      param_4 = param_4 + -0x400;
      if (aiStack_a0[0] != 0) {
        return aiStack_a0[0];
      }
    } while (0x3ff < param_4);
  }
  iVar5 = param_5;
  if (0 < param_4) {
    lVar2 = FUN_0051a9e0(param_1,0x97c8c0,iVar1,1);
    if (lVar2 == 0) {
      return -0x7efeff91;
    }
    if (param_5 <= 0x400 - param_4) {
      FUN_00521250(param_3,(int)&DAT_0097c8c0 + param_4,param_5);
      return param_5;
    }
    FUN_00521250(param_3,(int)&DAT_0097c8c0 + param_4);
    param_3 = (param_3 + 0x400) - param_4;
    iVar1 = FUN_00515778(param_1,iVar1,aiStack_a0);
    if (aiStack_a0[0] == -0x7efeffa7) {
      return -0x7efe6ffe;
    }
    iVar5 = param_5 + -0x400 + param_4;
    if (aiStack_a0[0] != 0) {
      return aiStack_a0[0];
    }
  }
  iVar4 = 0;
  iVar3 = 0;
  for (; 0x3ff < iVar5; iVar5 = iVar5 + -0x400) {
    if (iVar4 == 0) {
      iVar3 = 1;
      iVar4 = iVar1;
    }
    else {
      iVar1 = FUN_00515778(param_1,iVar1,aiStack_a0);
      if (aiStack_a0[0] == -0x7efeffa7) {
        return -0x7efe6ffe;
      }
      if (aiStack_a0[0] != 0) {
        return aiStack_a0[0];
      }
      if (iVar4 + iVar3 == iVar1) {
        iVar3 = iVar3 + 1;
      }
      else {
        lVar2 = FUN_0051aa00(param_1,param_3,iVar4,iVar3);
        if (lVar2 == 0) {
          return -0x7efeff91;
        }
        param_3 = param_3 + iVar3 * 0x400;
        iVar3 = 1;
        iVar4 = iVar1;
      }
    }
  }
  if (0 < iVar3) {
    lVar2 = FUN_0051aa00(param_1,param_3,iVar4,iVar3);
    param_3 = param_3 + iVar3 * 0x400;
    if (lVar2 == 0) {
      return -0x7efeff91;
    }
    if (iVar5 < 1) {
      return param_5;
    }
    iVar1 = FUN_00515778(param_1,iVar1,aiStack_a0);
    if (aiStack_a0[0] == -0x7efeffa7) {
      return -0x7efe6ffe;
    }
  }
  if (iVar5 < 1) {
    return param_5;
  }
  lVar2 = FUN_0051a9e0(param_1,0x97c8c0,iVar1,1);
  if (lVar2 == 0) {
    return -0x7efeff91;
  }
  FUN_00521250(param_3,0x97c8c0,iVar5);
  return param_5;
}
// FUN_005187C0 NONMATCHING
int FUN_005187c0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  u32 uVar2;
  u64 uVar3;
  long lVar4;
  int iVar5;
  u32 uVar6;
  int unaff_s5_lo;
  int iVar7;
  u16 auStack_350 [2];
  int iStack_34c;
  u32 uStack_340;
  char cStack_337;
  char cStack_336;
  char cStack_335;
  char cStack_334;
  char cStack_333;
  short sStack_332;
  char cStack_2f0;
  u8 auStack_150 [128];
  u8 uStack_d0;
  u8 bStack_cf;
  u8 bStack_ce;
  u8 bStack_cd;
  u8 bStack_cb;
  u8 bStack_ca;
  u8 bStack_c9;
  u32 uStack_c0;
  u32 uStack_bc;
  int iStack_b8;
  int iStack_b4;
  int iStack_b0;
  
  iStack_b8 = FUN_00516b48(0);
  iVar5 = iStack_b8;
  if (iStack_b8 == 0) {
    iStack_b8 = (u64)(FUN_00516be8(param_1,param_2,(u64)(u32)auStack_150));
    iVar5 = iStack_b8;
    if ((iStack_b8 == 0) &&
       (iStack_b8 = FUN_00516ec0(param_1,(u64)(u32)auStack_150,(u64 *)(u32)auStack_350,&uStack_c0,&uStack_bc),
       iVar5 = iStack_b8, iStack_b8 == -0x7efeffef)) {
      if (((cStack_2f0 == '\0') &&
          (((auStack_350[0] & 0xf000) == 0x8000 || ((auStack_350[0] & 0xf000) == 0xa000)))) &&
         (((auStack_350[0] & 0xf00) == 0x400 || ((auStack_350[0] & 0xf00) == 0)))) {
        if ((auStack_350[0] & 2) == 0) {
          iVar5 = -0x7efefff3;
        }
        else if ((auStack_350[0] & 0x20) == 0) {
          if (iStack_34c < param_4) {
            iVar5 = -0x7efeffea;
          }
          else {
            iVar5 = param_4 + param_5 + 0x3ff;
            iVar7 = param_4 + param_5 + 0x7fe;
            if (-1 < iVar5) {
              iVar7 = iVar5;
            }
            iVar5 = FUN_00515c98(param_1,uStack_340);
            if (-1 < iVar5) {
              if (iVar5 < iVar7 >> 10) {
                iVar1 = (u64)(FUN_00515a40(param_1,(u64)(u32)&iStack_b8));
                if (iStack_b8 != 0) {
                  return iStack_b8;
                }
                if (iVar1 < (iVar7 >> 10) - iVar5) {
                  return -0x7efeffe4;
                }
              }
              iVar7 = param_4;
              iStack_b0 = param_5;
              uVar6 = uStack_340;
              if (uStack_340 != 0xffffffff) {
LAB_00518ac0:
                do {
                  if (param_4 < 0x400) {
                    if ((0 < param_4) || ((param_4 + param_5 < 0x400 && (iVar7 < iStack_34c)))) {
                      lVar4 = FUN_0051a9e0(param_1,0x97c8c0,uVar6,1);
                      iStack_b4 = (int)lVar4;
                      if (lVar4 == 0) goto LAB_00518d40;
                    }
                    if (param_5 <= 0x400 - param_4) {
                      FUN_00521250((int)&DAT_0097c8c0 + param_4,param_3,param_5);
                      lVar4 = FUN_0051aa90(param_1,0x97c8c0,uVar6,1);
                      iStack_b4 = (int)lVar4;
                      if (lVar4 != 0) {
                        FUN_0051b5f0(param_1,(u64 *)(u32)&uStack_d0);
                        if (iStack_34c < iVar7 + param_5) {
                          iStack_34c = iVar7 + param_5;
                        }
                        cStack_336 = (bStack_ce >> 4) * '\n' + (bStack_ce & 0xf);
                        cStack_337 = (bStack_cf >> 4) * '\n' + (bStack_cf & 0xf);
                        cStack_333 = (bStack_ca >> 4) * '\n' + (bStack_ca & 0xf);
                        cStack_334 = (bStack_cb >> 4) * '\n' + (bStack_cb & 0xf);
                        cStack_335 = (bStack_cd >> 4) * '\n' + (bStack_cd & 0xf);
                        auStack_350[0] = auStack_350[0] | 0x80;
                        sStack_332 = (u16)(bStack_c9 >> 4) * 10 + (bStack_c9 & 0xf) + 2000;
                        iStack_b8 = FUN_00517310(param_1,(u64 *)(u32)auStack_350,uStack_c0,uStack_bc);
                        if (iStack_b8 != 0) {
                          return iStack_b8;
                        }
                        iStack_b8 = (int)(FUN_00517ab8(param_1,uStack_c0,(int)(u32)&uStack_d0));
                        if (iStack_b8 != 0) {
                          return iStack_b8;
                        }
                        lVar4 = FUN_00515588(param_1);
                        iStack_b4 = (int)lVar4;
                        if (lVar4 != 0) {
                          lVar4 = FUN_0051a498(param_1);
                          if (lVar4 != 0) {
                            return iStack_b0;
                          }
                          return -0x7efeff91;
                        }
                      }
                      goto LAB_00518d40;
                    }
                    FUN_00521250((int)&DAT_0097c8c0 + param_4,param_3);
                    lVar4 = FUN_0051aa90(param_1,0x97c8c0,uVar6,1);
                    iStack_b4 = (int)lVar4;
                    if (lVar4 == 0) goto LAB_00518d40;
                    iVar7 = (iVar7 + 0x400) - param_4;
                    param_5 = param_5 + -0x400 + param_4;
                    param_3 = (param_3 + 0x400) - param_4;
                    param_4 = 0;
                  }
                  uVar2 = (u32)FUN_00515730(param_1,uVar6,(u32 *)(u32)&iStack_b4);
                  if (iStack_b4 != 0) {
                    return iStack_b4;
                  }
                  if (uVar2 == 0xffffffff) {
                    uVar2 = (u64)(FUN_00515910(param_1,(u64)(u32)&iStack_b8));
                    if (iStack_b8 != 0) {
                      return iStack_b8;
                    }
                    FUN_005157e0(param_1,uVar2,0xffffffffffffffff,(u64)(u32)&iStack_b8);
                    if (iStack_b8 != 0) {
                      return iStack_b8;
                    }
                    FUN_005157e0(param_1,uVar6,uVar2 | 0x80000000,(u64)(u32)&iStack_b8);
                    if (iStack_b8 != 0) {
                      return iStack_b8;
                    }
                  }
                  if (param_4 != 0) {
                    param_4 = param_4 + -0x400;
                  }
                  uVar6 = uVar2 & 0x7fffffff;
                } while( true );
              }
              uVar3 = (u64)(FUN_00515910(param_1,(u64)(u32)&iStack_b8));
              iVar5 = iStack_b8;
              if ((iStack_b8 == 0) &&
                 (FUN_005157e0(param_1,uVar3,0xffffffffffffffff,(u64)(u32)&iStack_b8), iVar5 = iStack_b8,
                 iStack_b8 == 0)) {
                FUN_0051b5f0(param_1,(u64 *)(u32)&uStack_d0);
                uStack_340 = (u32)uVar3;
                if (iStack_34c < unaff_s5_lo) {
                  iStack_34c = unaff_s5_lo;
                }
                cStack_336 = (bStack_ce >> 4) * '\n' + (bStack_ce & 0xf);
                cStack_337 = (bStack_cf >> 4) * '\n' + (bStack_cf & 0xf);
                cStack_333 = (bStack_ca >> 4) * '\n' + (bStack_ca & 0xf);
                cStack_334 = (bStack_cb >> 4) * '\n' + (bStack_cb & 0xf);
                cStack_335 = (bStack_cd >> 4) * '\n' + (bStack_cd & 0xf);
                sStack_332 = (u16)(bStack_c9 >> 4) * 10 + (bStack_c9 & 0xf) + 2000;
                iStack_b8 = FUN_00517310(param_1,(u64 *)(u32)auStack_350,uStack_c0,uStack_bc);
                iVar5 = iStack_b8;
                if (iStack_b8 == 0) {
                  lVar4 = FUN_00515588(param_1);
                  iStack_b4 = (int)lVar4;
                  if (lVar4 != 0) {
                    lVar4 = FUN_0051a498(param_1);
                    iStack_b4 = (int)lVar4;
                    uVar6 = uStack_340;
                    if (lVar4 != 0) goto LAB_00518ac0;
                  }
LAB_00518d40:
                  iVar5 = -0x7efeff91;
                }
              }
            }
          }
        }
        else {
          iVar5 = -0x7efefffe;
        }
      }
      else {
        iVar5 = -0x7efe6ffe;
      }
    }
  }
  return iVar5;
}
// FUN_00518DA0 NONMATCHING
u32 FUN_00518da0(u64 param_1,u64 param_2,u64 param_3)

{
  u32 uVar1;
  int *piVar2;
  
  uVar1 = FUN_00515778(param_1,param_2,0);
  piVar2 = (int *)param_3;
  if (*piVar2 != -0x7efeffa7) {
    *piVar2 = 0;
    return uVar1;
  }
  uVar1 = FUN_00515910(param_1,param_3);
  if (*piVar2 == 0) {
    FUN_005157e0(param_1,uVar1,0xffffffffffffffff,param_3);
    if (*piVar2 != 0) {
      return 0xffffffffffffffff;
    }
    FUN_005157e0(param_1,param_2,uVar1 | 0xffffffff80000000,param_3);
    if (*piVar2 == 0) {
      *piVar2 = 0;
      return uVar1;
    }
  }
  return 0xffffffffffffffff;
}
// FUN_00518E70 NONMATCHING
int FUN_00518e70(u64 param_1,u64 param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  u64 uVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  int unaff_s5_lo;
  u16 auStack_340 [2];
  int iStack_33c;
  int iStack_330;
  char cStack_327;
  char cStack_326;
  char cStack_325;
  char cStack_324;
  char cStack_323;
  short sStack_322;
  char cStack_2e0;
  u8 auStack_140 [128];
  u8 uStack_c0;
  u8 bStack_bf;
  u8 bStack_be;
  u8 bStack_bd;
  u8 bStack_bb;
  u8 bStack_ba;
  u8 bStack_b9;
  u32 uStack_b0;
  u32 uStack_ac;
  int aiStack_a8 [2];
  
  aiStack_a8[0] = FUN_00516b48(0);
  if (aiStack_a8[0] != 0) {
    return aiStack_a8[0];
  }
  aiStack_a8[0] = (u64)(FUN_00516be8(param_1,param_2,(u64)(u32)auStack_140));
  if (aiStack_a8[0] != 0) {
    return aiStack_a8[0];
  }
  aiStack_a8[0] = (u64)(FUN_00516ec0(param_1,(u64)(u32)auStack_140,(u64 *)(u32)auStack_340,&uStack_b0,&uStack_ac));
  if (aiStack_a8[0] != -0x7efeffef) {
    return aiStack_a8[0];
  }
  if (((cStack_2e0 != '\0') ||
      (((auStack_340[0] & 0xf000) != 0x8000 && ((auStack_340[0] & 0xf000) != 0xa000)))) ||
     (((auStack_340[0] & 0xf00) != 0x400 && ((auStack_340[0] & 0xf00) != 0)))) {
    return -0x7efe6ffe;
  }
  if ((auStack_340[0] & 2) == 0) {
    return -0x7efefff3;
  }
  if ((auStack_340[0] & 0x20) != 0) {
    return -0x7efefffe;
  }
  if (iStack_33c < param_4) {
    return -0x7efeffea;
  }
  iVar5 = param_4 + param_5 + 0x3ff;
  iVar2 = param_4 + param_5 + 0x7fe;
  if (-1 < iVar5) {
    iVar2 = iVar5;
  }
  iVar5 = FUN_00515c98(param_1,iStack_330);
  if (iVar5 < 0) {
    return iVar5;
  }
  if (iVar5 < iVar2 >> 10) {
    iVar1 = (u64)(FUN_00515a40(param_1,(u64)(u32)aiStack_a8));
    if (aiStack_a8[0] != 0) {
      return aiStack_a8[0];
    }
    if (iVar1 < (iVar2 >> 10) - iVar5) {
      return -0x7efeffe4;
    }
  }
  if (iStack_330 == -1) {
    uVar3 = (u64)(FUN_00515910(param_1,(u64)(u32)aiStack_a8));
    if (aiStack_a8[0] != 0) {
      return aiStack_a8[0];
    }
    FUN_005157e0(param_1,uVar3,0xffffffffffffffff,(u64)(u32)aiStack_a8);
    if (aiStack_a8[0] != 0) {
      return aiStack_a8[0];
    }
    FUN_0051b5f0(param_1,(u64 *)(u32)&uStack_c0);
    iStack_330 = (int)uVar3;
    if (iStack_33c < unaff_s5_lo) {
      iStack_33c = unaff_s5_lo;
    }
    cStack_326 = (bStack_be >> 4) * '\n' + (bStack_be & 0xf);
    cStack_327 = (bStack_bf >> 4) * '\n' + (bStack_bf & 0xf);
    cStack_323 = (bStack_ba >> 4) * '\n' + (bStack_ba & 0xf);
    cStack_324 = (bStack_bb >> 4) * '\n' + (bStack_bb & 0xf);
    cStack_325 = (bStack_bd >> 4) * '\n' + (bStack_bd & 0xf);
    sStack_322 = (u16)(bStack_b9 >> 4) * 10 + (bStack_b9 & 0xf) + 2000;
    aiStack_a8[0] = FUN_00517310(param_1,(u64 *)(u32)auStack_340,uStack_b0,uStack_ac);
    if (aiStack_a8[0] != 0) {
      return aiStack_a8[0];
    }
    lVar4 = FUN_00515588(param_1);
    if (lVar4 == 0) {
      return -0x7efeff91;
    }
    lVar4 = FUN_0051a498(param_1);
    if (lVar4 == 0) {
      return -0x7efeff91;
    }
  }
  iVar5 = param_4;
  iVar2 = iStack_330;
  if (0x3ff < param_4) {
    do {
      iVar2 = (u64)(FUN_00518da0(param_1,iVar2,(u64)(u32)aiStack_a8));
      if (aiStack_a8[0] != 0) {
        return aiStack_a8[0];
      }
      iVar5 = iVar5 + -0x400;
    } while (0x3ff < iVar5);
  }
  iVar1 = param_5;
  if (0 < iVar5) {
    if (aiStack_a8[0] == -0x7efeffa7) {
      return -0x7efe6ffe;
    }
    lVar4 = FUN_0051a9e0(param_1,0x97c8c0,iVar2,1);
    if (lVar4 == 0) {
      return -0x7efeff91;
    }
    if (0x400 - iVar5 < param_5) {
      FUN_00521250((int)&DAT_0097c8c0 + iVar5,param_3);
      lVar4 = FUN_0051aa90(param_1,0x97c8c0,iVar2,1);
      if (lVar4 == 0) {
        return -0x7efeff91;
      }
      param_4 = (param_4 + 0x400) - iVar5;
      iVar1 = param_5 + -0x400 + iVar5;
      param_3 = (param_3 + 0x400) - iVar5;
    }
    else {
      FUN_00521250((int)&DAT_0097c8c0 + iVar5,param_3,param_5);
      lVar4 = FUN_0051aa90(param_1,0x97c8c0,iVar2,1);
      param_4 = param_4 + param_5;
      if (lVar4 == 0) {
        return -0x7efeff91;
      }
      iVar1 = 0;
    }
    iVar2 = (u64)(FUN_00518da0(param_1,iVar2,(u64)(u32)aiStack_a8));
    if (aiStack_a8[0] != 0) {
      return aiStack_a8[0];
    }
  }
  iVar5 = 0;
  if (0 < iVar1) {
    iVar6 = 0;
    for (; 0x3ff < iVar1; iVar1 = iVar1 + -0x400) {
      if (iVar5 == 0) {
        iVar6 = 1;
        iVar5 = iVar2;
      }
      else {
        iVar2 = (u64)(FUN_00518da0(param_1,iVar2,(u64)(u32)aiStack_a8));
        if (aiStack_a8[0] != 0) {
          return aiStack_a8[0];
        }
        if (iVar5 + iVar6 == iVar2) {
          iVar6 = iVar6 + 1;
        }
        else {
          lVar4 = FUN_0051aa48(param_1,param_3,iVar5,iVar6);
          if (lVar4 == 0) {
            return -0x7efeff91;
          }
          param_4 = param_4 + iVar6 * 0x400;
          param_3 = param_3 + iVar6 * 0x400;
          iVar6 = 1;
          iVar5 = iVar2;
        }
      }
    }
    if (0 < iVar6) {
      lVar4 = FUN_0051aa48(param_1,param_3,iVar5,iVar6);
      if (lVar4 == 0) {
        return -0x7efeff91;
      }
      param_4 = param_4 + iVar6 * 0x400;
      param_3 = param_3 + iVar6 * 0x400;
      if (iVar1 < 1) goto LAB_0051939c;
      iVar2 = (u64)(FUN_00518da0(param_1,iVar2,(u64)(u32)aiStack_a8));
      if (aiStack_a8[0] != 0) {
        return aiStack_a8[0];
      }
    }
    if (0 < iVar1) {
      lVar4 = FUN_0051a9e0(param_1,0x97c8c0,iVar2,1);
      if (lVar4 == 0) {
        return -0x7efeff91;
      }
      FUN_00521250(0x97c8c0,param_3,iVar1);
      lVar4 = FUN_0051aa90(param_1,0x97c8c0,iVar2,1);
      param_4 = param_4 + iVar1;
      if (lVar4 == 0) {
        return -0x7efeff91;
      }
    }
  }
LAB_0051939c:
  FUN_0051b5f0(param_1,(u64 *)(u32)&uStack_c0);
  if (iStack_33c < param_4) {
    iStack_33c = param_4;
  }
  cStack_326 = (bStack_be >> 4) * '\n' + (bStack_be & 0xf);
  cStack_327 = (bStack_bf >> 4) * '\n' + (bStack_bf & 0xf);
  cStack_323 = (bStack_ba >> 4) * '\n' + (bStack_ba & 0xf);
  cStack_324 = (bStack_bb >> 4) * '\n' + (bStack_bb & 0xf);
  cStack_325 = (bStack_bd >> 4) * '\n' + (bStack_bd & 0xf);
  auStack_340[0] = auStack_340[0] | 0x80;
  sStack_322 = (u16)(bStack_b9 >> 4) * 10 + (bStack_b9 & 0xf) + 2000;
  aiStack_a8[0] = FUN_00517310(param_1,(u64 *)(u32)auStack_340,uStack_b0,uStack_ac);
  if (aiStack_a8[0] != 0) {
    return aiStack_a8[0];
  }
  aiStack_a8[0] = (int)(FUN_00517ab8(param_1,uStack_b0,(int)(u32)&uStack_c0));
  if (aiStack_a8[0] != 0) {
    return aiStack_a8[0];
  }
  lVar4 = FUN_00515588(param_1);
  if (lVar4 == 0) {
    return -0x7efeff91;
  }
  lVar4 = FUN_0051a498(param_1);
  if (lVar4 != 0) {
    return param_5;
  }
  return -0x7efeff91;
}
// FUN_005194F8 NONMATCHING
int FUN_005194f8(u64 param_1,u64 param_2)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  u32 uVar4;
  u16 auStack_370 [8];
  u32 uStack_360;
  u8 auStack_160 [128];
  u8 auStack_e0 [128];
  u32 uStack_60;
  u32 uStack_5c;
  int iStack_58;
  int iStack_54;
  
  iStack_54 = FUN_00516b48(0);
  if (iStack_54 == 0) {
    iStack_54 = (u64)(FUN_00516be8(param_1,param_2,(u64)(u32)auStack_160));
    if ((iStack_54 == 0) &&
       (iStack_54 = FUN_00516ec0(param_1,(u64)(u32)auStack_160,(u64 *)(u32)auStack_370,&uStack_60,&uStack_5c),
       iStack_54 == -0x7efeffef)) {
      if ((auStack_370[0] & 2) == 0) {
        iStack_54 = -0x7efefff3;
      }
      else {
        iVar1 = -0x7efeffef;
        if ((auStack_370[0] & 0x20) != 0) {
          FUN_00524270(auStack_e0,auStack_160);
          FUN_00523e68(auStack_e0,0x7be660);
          iVar1 = FUN_00519850(param_1,auStack_e0,0,0xffffffffffffffff,0,&iStack_58);
          if (iVar1 != 0) {
            return iVar1;
          }
          iVar1 = 0;
          if (2 < iStack_58) {
            return -0x7efeffa6;
          }
        }
        iStack_54 = iVar1;
        auStack_370[0] = auStack_370[0] ^ 0x8000;
        iStack_54 = FUN_00517310(param_1,(u64 *)(u32)auStack_370,uStack_60,uStack_5c);
        if (iStack_54 == 0) {
          lVar3 = FUN_0051a498(param_1);
          if (lVar3 == 0) {
LAB_005196e0:
            iStack_54 = -0x7efeff91;
          }
          else if (uStack_360 == 0xffffffff) {
            iStack_54 = 0;
          }
          else {
            uVar4 = uStack_360;
            while (uVar2 = FUN_00515730(param_1,uVar4,(u32 *)(u32)&iStack_54), iStack_54 == 0) {
              if ((uVar2 == 0xfffffffd) || (-1 < (int)uVar2)) {
LAB_005196c0:
                lVar3 = FUN_00515588(param_1);
                if ((lVar3 != 0) && (lVar3 = FUN_0051a498(param_1), lVar3 != 0)) {
                  (&DAT_0097c018)[(int)param_1 * 0x226] = 0;
                  return 0;
                }
                goto LAB_005196e0;
              }
              FUN_005157e0(param_1,uVar4,uVar2 ^ 0x80000000,(u64)(u32)&iStack_54);
              if (iStack_54 != 0) {
                return iStack_54;
              }
              if (uVar2 == 0xffffffff) goto LAB_005196c0;
              uVar4 = uVar2 & 0x7fffffff;
            }
          }
        }
      }
    }
  }
  return iStack_54;
}
// FUN_00519728 NONMATCHING
long FUN_00519728(u64 param_1,u64 param_2,long param_3)

{
  long lVar1;
  u16 auStack_2e0 [256];
  u8 auStack_e0 [128];
  
  lVar1 = (u64)(FUN_00516be8(param_1,param_2,(u64)(u32)auStack_e0));
  if (lVar1 != 0) {
    return lVar1;
  }
  lVar1 = FUN_00524128(auStack_e0,0x7be608);
  if (lVar1 == 0) {
    FUN_00524270(&DAT_0097bf90 + (int)param_1 * 0x898,auStack_e0);
  }
  else {
    lVar1 = FUN_00516b48(param_1);
    if (lVar1 != 0) {
      return lVar1;
    }
    lVar1 = (u64)(FUN_00516ec0(param_1,(u64)(u32)auStack_e0,(u64 *)(u32)auStack_2e0,0,0));
    if (lVar1 != -0x7efeffef) {
      return lVar1;
    }
    if ((auStack_2e0[0] & 0x20) == 0) {
      return -0x7efeffec;
    }
    FUN_00524270(&DAT_0097bf90 + (int)param_1 * 0x898,auStack_e0);
    FUN_00523e68(&DAT_0097bf90 + (int)param_1 * 0x898,0x7be608);
  }
  if (param_3 != 0) {
    FUN_00524270(param_3,auStack_e0);
  }
  return 0;
}
// FUN_00519850 NONMATCHING
int FUN_00519850(u64 param_1,u64 param_2,int param_3,int param_4,u64 *param_5,
                int *param_6)

{
  u8 *puVar1;
  int iVar2;
  u32 uVar3;
  long lVar4;
  long lVar5;
  u64 *puVar6;
  u16 *puVar7;
  u8 *puVar8;
  u64 uVar9;
  u64 uVar10;
  u64 uVar11;
  u64 *puVar12;
  u64 *puVar13;
  int iVar14;
  u8 auStack_600 [128];
  u8 auStack_580 [128];
  u8 auStack_500 [64];
  u16 auStack_4c0 [2];
  u32 uStack_4bc;
  u64 uStack_4b8;
  u64 uStack_4a8;
  u8 auStack_480 [31];
  u8 uStack_461;
  u16 auStack_2c0 [2];
  int iStack_2bc;
  u32 uStack_2b0;
  int iStack_c0;
  int iStack_bc;
  int *piStack_b8;
  int iStack_b4;
  u8 *puStack_b0;
  u16 *puStack_ac;
  
  iStack_b4 = 0;
  iStack_bc = param_4;
  piStack_b8 = param_6;
  lVar4 = FUN_0051c0c0(0);
  if (lVar4 == 0) {
    return -0x7efeffed;
  }
  if ((&DAT_0097c014)[(int)param_1 * 0x226] == 0) {
    return -0x7efeff91;
  }
  lVar4 = (u64)(FUN_00515218(param_1,param_2,(u64)(u32)auStack_600));
  if (lVar4 != 0) {
    lVar4 = FUN_00524128(auStack_600,0x7be608);
    puVar8 = auStack_580;
    if (lVar4 != 0) {
      FUN_00524270(puVar8,auStack_600);
      puVar1 = (u8 *)FUN_005249e8(puVar8,0x2f);
      puStack_b0 = auStack_500;
      *puVar1 = 0;
      iVar2 = FUN_00524388(puVar8);
      FUN_00524270(puStack_b0,puVar8 + iVar2 + 1);
      lVar4 = FUN_00524388(puVar8);
      if (lVar4 == 0) {
        puVar8 = (u8 *)(&DAT_007be608);
      }
      iStack_c0 = (u64)(FUN_00516ec0(param_1,(u64)(u32)puVar8,(u64 *)(u32)auStack_2c0,0,0));
      if (iStack_c0 != -0x7efeffef) {
        return iStack_c0;
      }
      puStack_ac = auStack_4c0;
      if ((auStack_2c0[0] & 0x20) == 0) {
        return -0x7efeffec;
      }
      lVar5 = FUN_00515b18(param_1,(u64 *)(u32)puStack_ac,uStack_2b0,0);
      iStack_c0 = (int)lVar5;
      if (lVar5 != 0) {
LAB_00519a1c:
        if (lVar5 == -0x7efefffe) {
          return -0x7efe6ffe;
        }
        return iStack_c0;
      }
      if (((auStack_4c0[0] & 0x8000) != 0) &&
         (lVar5 = FUN_00524128(auStack_480,0x7be5f0), lVar5 == 0)) {
        lVar5 = FUN_00515b18(param_1,(u64 *)(u32)puStack_ac,uStack_2b0,1);
        iStack_c0 = (int)lVar5;
        if (lVar5 != 0) goto LAB_00519a1c;
        if ((((auStack_4c0[0] & 0x8000) != 0) &&
            (lVar5 = FUN_00524128(auStack_480,0x7be5f8), lVar5 == 0)) && (1 < iStack_2bc)) {
          iVar2 = 0;
          if (param_3 < iStack_2bc) {
            uVar3 = uStack_2b0;
            if (lVar4 == 0) {
              iStack_2bc = iStack_2bc + -2;
              if (iStack_2bc == 0) {
                if (piStack_b8 != (int *)0x0) {
                  *piStack_b8 = 0;
                  return 0;
                }
                return 0;
              }
              uVar3 = FUN_00515778(param_1,uStack_2b0,&iStack_c0);
              if (iStack_c0 == -0x7efeffa7) {
                return -0x7efe6ffe;
              }
              if (iStack_c0 != 0) {
                return iStack_c0;
              }
            }
            do {
              if (iStack_2bc == 0) break;
              puVar12 = (u64 *)&DAT_0097c8c0;
              puVar13 = (u64 *)&DAT_0097c8c0;
              lVar4 = FUN_0051a9e0(param_1,0x97c8c0,uVar3,1);
              if (lVar4 == 0) {
                return -0x7efeff91;
              }
              iVar14 = 0;
              do {
                puVar12 = puVar12 + 0x40;
                puVar7 = puStack_ac;
                puVar6 = puVar13;
                do {
                  uVar9 = puVar6[1];
                  uVar10 = puVar6[2];
                  uVar11 = puVar6[3];
                  *(u64 *)puVar7 = *puVar6;
                  *(u64 *)(puVar7 + 4) = uVar9;
                  *(u64 *)(puVar7 + 8) = uVar10;
                  *(u64 *)(puVar7 + 0xc) = uVar11;
                  puVar6 = puVar6 + 4;
                  puVar7 = puVar7 + 0x10;
                } while (puVar6 != puVar12);
                uStack_461 = 0;
                if ((((auStack_4c0[0] & 0x8000) != 0) && ((auStack_4c0[0] & 0x2000) == 0)) &&
                   (lVar4 = FUN_00514f30((char *)(u32)auStack_480,(char *)puStack_b0), lVar4 == 1)) {
                  if (param_3 == 0) {
                    if ((param_5 != (u64 *)0x0) && (0 < iStack_bc)) {
                      *param_5 = uStack_4b8;
                      param_5[1] = uStack_4a8;
                      *(u32 *)(param_5 + 2) = uStack_4bc;
                      *(u16 *)((int)param_5 + 0x14) = auStack_4c0[0];
                      FUN_00524270(param_5 + 3,auStack_480);
                      lVar4 = FUN_00524128(auStack_480,0x7be5f0);
                      if (lVar4 == 0) {
                        *(u16 *)((int)param_5 + 0x14) = auStack_2c0[0];
                      }
                      param_5 = param_5 + 7;
                      FUN_00524128(auStack_480,0x7be5f8);
                    }
                    iVar2 = iVar2 + 1;
                    if ((0 < iStack_bc) && (iStack_bc <= iVar2)) {
                      iStack_b4 = 1;
                      break;
                    }
                  }
                  else {
                    param_3 = param_3 + -1;
                  }
                }
                iStack_2bc = iStack_2bc + -1;
                if (iStack_2bc == 0) {
                  iStack_b4 = 1;
                  break;
                }
                iVar14 = iVar14 + 1;
                puVar13 = puVar13 + 0x40;
              } while (iVar14 < 2);
              if (iStack_b4 == 1) break;
              uVar3 = FUN_00515778(param_1,uVar3,&iStack_c0);
              if (iStack_c0 == -0x7efeffa7) {
                return -0x7efe6ffe;
              }
              if (iStack_c0 != 0) {
                return iStack_c0;
              }
            } while (iStack_b4 == 0);
            if (piStack_b8 != (int *)0x0) {
              *piStack_b8 = iVar2;
            }
          }
          else {
            if (piStack_b8 == (int *)0x0) {
              return 0;
            }
            *piStack_b8 = 0;
          }
          return 0;
        }
      }
      return -0x7efe6ffe;
    }
  }
  return -0x7efeffea;
}
// FUN_00519D70 NONMATCHING
long FUN_00519d70(u64 param_1,u64 param_2,u16 param_3)

{
  long lVar1;
  long lVar2;
  u8 auStack_2e0 [128];
  u16 auStack_260 [12];
  char cStack_247;
  char cStack_246;
  char cStack_245;
  char cStack_244;
  char cStack_243;
  short sStack_242;
  u8 uStack_60;
  u8 bStack_5f;
  u8 bStack_5e;
  u8 bStack_5d;
  u8 bStack_5b;
  u8 bStack_5a;
  u8 bStack_59;
  u32 uStack_50;
  u32 auStack_4c [3];
  
  lVar1 = FUN_00516b48(0);
  if ((lVar1 == 0) && (lVar1 = FUN_00516be8(param_1,param_2,(u64)(u32)auStack_2e0), lVar1 == 0)) {
    lVar1 = (u64)(FUN_00516ec0(param_1,(u64)(u32)auStack_2e0,(u64 *)(u32)auStack_260,&uStack_50,auStack_4c));
    if (lVar1 == -0x7efeffef) {
      if ((auStack_260[0] & 0x20) == 0) {
        lVar1 = -0x7efeffec;
      }
      else {
        auStack_260[0] = auStack_260[0] & 0xe7f0 | param_3 & 0x180f;
        FUN_0051b5f0(param_1,(u64 *)(u32)&uStack_60);
        cStack_246 = (bStack_5e >> 4) * '\n' + (bStack_5e & 0xf);
        cStack_247 = (bStack_5f >> 4) * '\n' + (bStack_5f & 0xf);
        cStack_243 = (bStack_5a >> 4) * '\n' + (bStack_5a & 0xf);
        cStack_244 = (bStack_5b >> 4) * '\n' + (bStack_5b & 0xf);
        cStack_245 = (bStack_5d >> 4) * '\n' + (bStack_5d & 0xf);
        sStack_242 = (u16)(bStack_59 >> 4) * 10 + (bStack_59 & 0xf) + 2000;
        lVar1 = FUN_00517310(param_1,(u64 *)(u32)auStack_260,uStack_50,auStack_4c[0]);
        if (lVar1 == 0) {
          lVar2 = FUN_0051a498(param_1);
          lVar1 = -0x7efeff91;
          if (lVar2 != 0) {
            lVar1 = 0;
          }
        }
      }
    }
  }
  return lVar1;
}
// FUN_00519EF8 NONMATCHING
long FUN_00519ef8(u64 param_1,u64 param_2,u64 param_3)

{
  int iVar1;
  long lVar2;
  u8 auStack_380 [64];
  u8 auStack_340 [448];
  u8 auStack_180 [128];
  u8 auStack_100 [128];
  u32 uStack_80;
  u32 auStack_7c [3];
  
  lVar2 = FUN_00516b48(0);
  if (lVar2 == 0) {
    lVar2 = (u64)(FUN_00516be8(param_1,param_2,(u64)(u32)auStack_180));
    if (lVar2 == 0) {
      lVar2 = FUN_00523f98(param_3,0x2f);
      if (lVar2 == 0) {
        FUN_00524270(auStack_100,auStack_180);
        iVar1 = FUN_005249e8(auStack_100,0x2f);
        FUN_00524270(iVar1 + 1,param_3);
        lVar2 = FUN_00514e20((char *)(u32)param_3);
        if (lVar2 != 0) {
          lVar2 = FUN_00514db0(param_3);
          if (lVar2 == 0) {
            return -0x7efeffa5;
          }
          lVar2 = (u64)(FUN_00516ec0(param_1,(u64)(u32)auStack_100,(u64 *)(u32)auStack_380,&uStack_80,auStack_7c));
          if (lVar2 != -0x7efefffe) {
            return lVar2;
          }
          lVar2 = (u64)(FUN_00516ec0(param_1,(u64)(u32)auStack_180,(u64 *)(u32)auStack_380,&uStack_80,auStack_7c));
          if (lVar2 != -0x7efeffef) {
            return lVar2;
          }
          FUN_00524270(auStack_340,param_3);
          lVar2 = FUN_00517310(param_1,(u64 *)(u32)auStack_380,uStack_80,auStack_7c[0]);
          if (lVar2 != 0) {
            return lVar2;
          }
          lVar2 = FUN_0051a498(param_1);
          if (lVar2 == 0) {
            return -0x7efeff91;
          }
          return 0;
        }
      }
      lVar2 = -0x7efeffea;
    }
  }
  return lVar2;
}
// FUN_0051A078 NONMATCHING
int FUN_0051a078(u64 param_1,u64 param_2)

{
  int iVar1;
  u16 auStack_2d0 [2];
  u32 uStack_2cc;
  u32 uStack_2c0;
  u8 auStack_d0 [128];
  int aiStack_50 [4];
  
  aiStack_50[0] = FUN_00516b48(0);
  iVar1 = aiStack_50[0];
  if (aiStack_50[0] == 0) {
    aiStack_50[0] = (u64)(FUN_00516be8(param_1,param_2,(u64)(u32)auStack_d0));
    iVar1 = aiStack_50[0];
    if (aiStack_50[0] == 0) {
      aiStack_50[0] = (u64)(FUN_00516ec0(param_1,(u64)(u32)auStack_d0,(u64 *)(u32)auStack_2d0,0,0));
      iVar1 = aiStack_50[0];
      if (aiStack_50[0] == -0x7efeffef) {
        if ((auStack_2d0[0] & 0x20) == 0) {
          iVar1 = -0x7efeffec;
        }
        else {
          iVar1 = (u64)(FUN_005174b8(param_1,uStack_2c0,uStack_2cc,(u64)(u32)aiStack_50));
          if (aiStack_50[0] != 0) {
            iVar1 = aiStack_50[0];
          }
        }
      }
    }
  }
  return iVar1;
}
// FUN_0051A140 NONMATCHING
u32 FUN_0051a140(void)

{
  u32 *puVar1;
  
  puVar1 = &DAT_0097ccc0;
  do {
    *puVar1 = 0xffffffff;
    puVar1[3] = 0;
    puVar1 = puVar1 + 0x1004;
  } while ((int)puVar1 < 0x984ce0);
  return 1;
}
// FUN_0051A180
asm u32 FUN_0051a180(u64 param_1, int *param_2)
{
  .set noreorder
  addiu $sp, $sp, -0x10
  sd $ra, 0($sp)
  .word 0x0c146bf6
  nop
  ld $ra, 0($sp)
  jr $ra
  addiu $sp, $sp, 0x10
}
// FUN_0051A1A0
asm u64 FUN_0051a1a0(u64 param_1)
{
  .set noreorder
  addiu $sp, $sp, -0x10
  sd $ra, 0($sp)
  .word 0x0c146c6c
  nop
  ld $ra, 0($sp)
  jr $ra
  addiu $sp, $sp, 0x10
}
// FUN_0051A1C0
asm u64 FUN_0051a1c0(u64 param_1)
{
  .set noreorder
  addiu $sp, $sp, -0x10
  sd $ra, 0($sp)
  .word 0x0c146cec
  nop
  ld $ra, 0($sp)
  jr $ra
  addiu $sp, $sp, 0x10
}
// FUN_0051A1E0 NONMATCHING
u32 FUN_0051a1e0(u64 param_1)

{
  u32 uVar1;
  long lVar2;
  u64 *puVar3;
  u64 *puVar4;
  u64 uVar5;
  u64 uVar6;
  u64 uVar7;
  
  puVar4 = (u64 *)&DAT_00984d00;
  lVar2 = FUN_0051b708(param_1,0x984d00,0,1,0);
  if (lVar2 == 0) {
    uVar1 = 0;
  }
  else {
    puVar3 = (u64 *)(&DAT_007827e0 + (int)param_1 * 0x184);
    if (((u32)puVar3 & 7) == 0) {
      do {
        uVar5 = puVar4[1];
        uVar6 = puVar4[2];
        uVar7 = puVar4[3];
        *puVar3 = *puVar4;
        puVar3[1] = uVar5;
        puVar3[2] = uVar6;
        puVar3[3] = uVar7;
        puVar4 = puVar4 + 4;
        puVar3 = puVar3 + 4;
      } while (puVar4 != (u64 *)0x984e80);
    }
    else {
      do {
        uVar5 = puVar4[1];
        uVar6 = puVar4[2];
        uVar7 = puVar4[3];
        *puVar3 = *puVar4;
        puVar3[1] = uVar5;
        puVar3[2] = uVar6;
        puVar3[3] = uVar7;
        puVar4 = puVar4 + 4;
        puVar3 = puVar3 + 4;
      } while (puVar4 != (u64 *)0x984e80);
      puVar4 = (u64 *)0x984e80;
    }
    *(u32 *)puVar3 = *(u32 *)puVar4;
    uVar1 = 1;
  }
  return uVar1;
}
// FUN_0051A2F8 NONMATCHING
bool FUN_0051a2f8(u64 param_1)

{
  int iVar1;
  long lVar2;
  u64 *puVar3;
  u64 uVar4;
  u64 uVar5;
  u64 uVar6;
  u64 *puVar7;
  
  puVar7 = (u64 *)&DAT_00984d00;
  FUN_00521408(0x984d00,0xff,0x800);
  iVar1 = (int)param_1 * 0x184;
  puVar3 = (u64 *)(&DAT_007827e0 + iVar1);
  if (((u32)puVar3 & 7) == 0) {
    do {
      uVar5 = puVar3[1];
      uVar6 = puVar3[2];
      uVar4 = puVar3[3];
      *puVar7 = *puVar3;
      puVar7[1] = uVar5;
      puVar7[2] = uVar6;
      puVar7[3] = uVar4;
      puVar3 = puVar3 + 4;
      puVar7 = puVar7 + 4;
    } while (puVar3 != (u64 *)(&DAT_00782960 + iVar1));
  }
  else {
    do {
      uVar4 = puVar3[1];
      uVar5 = puVar3[2];
      uVar6 = puVar3[3];
      *puVar7 = *puVar3;
      puVar7[1] = uVar4;
      puVar7[2] = uVar5;
      puVar7[3] = uVar6;
      puVar3 = puVar3 + 4;
      puVar7 = puVar7 + 4;
    } while (puVar3 != (u64 *)(&DAT_00782960 + iVar1));
  }
  *(u32 *)puVar7 = *(u32 *)puVar3;
  lVar2 = FUN_0051b8f0(param_1,0x984d00,0,1);
  return lVar2 != 0;
}
// FUN_0051A418 NONMATCHING
u64 FUN_0051a418(int param_1,u64 param_2,int param_3,int param_4)
{
  return FUN_0051b8d0(param_1,param_2,param_3 * (u32)*(u16 *)(&DAT_0078280a + param_1 * 0x184),
               (u32)*(u16 *)(&DAT_0078280a + param_1 * 0x184) * param_4);
}
// FUN_0051A458 NONMATCHING
u64 FUN_0051a458(int param_1,u64 param_2,int param_3,int param_4)
{
  return FUN_0051b8f0(param_1,param_2,param_3 * (u32)*(u16 *)(&DAT_0078280a + param_1 * 0x184),
               (u32)*(u16 *)(&DAT_0078280a + param_1 * 0x184) * param_4);
}
// FUN_0051A498 NONMATCHING
u64 FUN_0051a498(int param_1)

{
  int iVar1;
  u64 uVar2;
  u32 uVar3;
  
  iVar1 = (&DAT_0097ccc0)[param_1 * 0x1004];
  uVar2 = 1;
  if (iVar1 != -1) {
    uVar3 = (&DAT_0097cccc)[param_1 * 0x1004];
    uVar2 = FUN_0051a458(param_1,(u64)(u32)(&DAT_0097ccd0 + param_1 * 0x4010),iVar1,
                         (u64)uVar3);
    (&DAT_0097ccc0)[param_1 * 0x1004] = -1;
    (&DAT_0097cccc)[param_1 * 0x1004] = 0;
  }
  return uVar2;
}
// FUN_0051A508 NONMATCHING
u64 FUN_0051a508(u64 param_1,u64 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  u64 *puVar3;
  u64 *puVar4;
  u64 uVar5;
  u64 uVar6;
  u64 uVar7;
  u64 uVar8;
  int iVar9;
  
  iVar9 = (int)param_1;
  iVar1 = iVar9 * 0x184;
  iVar2 = iVar9 * 0x4010;
  param_3 = param_3 + *(int *)(&DAT_00782814 + iVar1);
  if (*(u16 *)(&DAT_0078280c + iVar1) == 0) {
    trap(7);
  }
  iVar1 = (int)(param_3 * (u32)*(u16 *)(&DAT_0078280a + iVar1)) /
          (int)(u32)*(u16 *)(&DAT_0078280c + iVar1);
  if ((&DAT_0097ccc0)[iVar9 * 0x1004] == -1) {
    (&DAT_0097ccc0)[iVar9 * 0x1004] = param_3;
    puVar4 = (u64 *)(&DAT_0097ccd0 + iVar2);
    *(int *)(&DAT_0097ccc4 + iVar2) = param_3;
    *(int *)(&DAT_0097ccc8 + iVar2) = iVar1;
    (&DAT_0097cccc)[iVar9 * 0x1004] = 0;
    if (((u32)param_2 & 7) == 0) {
      puVar3 = param_2 + 0x80;
      do {
        uVar5 = param_2[1];
        uVar6 = param_2[2];
        uVar7 = param_2[3];
        *puVar4 = *param_2;
        puVar4[1] = uVar5;
        puVar4[2] = uVar6;
        puVar4[3] = uVar7;
        param_2 = param_2 + 4;
        puVar4 = puVar4 + 4;
      } while (param_2 != puVar3);
    }
    else {
      puVar3 = param_2 + 0x80;
      do {
        uVar5 = param_2[1];
        uVar6 = param_2[2];
        uVar7 = param_2[3];
        *puVar4 = *param_2;
        puVar4[1] = uVar5;
        puVar4[2] = uVar6;
        puVar4[3] = uVar7;
        param_2 = param_2 + 4;
        puVar4 = puVar4 + 4;
      } while (param_2 != puVar3);
    }
    uVar5 = 1;
  }
  else if (((param_3 == *(int *)(&DAT_0097ccc4 + iVar2) + 1) &&
           ((int)(&DAT_0097cccc)[iVar9 * 0x1004] < 0x10)) &&
          (*(int *)(&DAT_0097ccc8 + iVar2) == iVar1)) {
    *(int *)(&DAT_0097ccc4 + iVar2) = param_3;
    puVar4 = (u64 *)(&DAT_0097ccd0 + iVar2 + (&DAT_0097cccc)[iVar9 * 0x1004] * 0x400);
    if (((u32)param_2 & 7) == 0) {
      puVar3 = param_2 + 0x80;
      do {
        uVar6 = param_2[1];
        uVar7 = param_2[2];
        uVar5 = param_2[3];
        *puVar4 = *param_2;
        puVar4[1] = uVar6;
        puVar4[2] = uVar7;
        puVar4[3] = uVar5;
        param_2 = param_2 + 4;
        puVar4 = puVar4 + 4;
      } while (param_2 != puVar3);
    }
    else {
      puVar3 = param_2 + 0x80;
      do {
        uVar7 = param_2[1];
        uVar5 = param_2[2];
        uVar6 = param_2[3];
        *puVar4 = *param_2;
        puVar4[1] = uVar7;
        puVar4[2] = uVar5;
        puVar4[3] = uVar6;
        param_2 = param_2 + 4;
        puVar4 = puVar4 + 4;
      } while (param_2 != puVar3);
    }
    uVar5 = 1;
  }
  else {
    uVar5 = FUN_0051a498(param_1);
    iVar2 = iVar9 * 0x4010;
    (&DAT_0097ccc0)[iVar9 * 0x1004] = param_3;
    puVar4 = (u64 *)(&DAT_0097ccd0 + iVar2);
    *(int *)(&DAT_0097ccc4 + iVar2) = param_3;
    *(int *)(&DAT_0097ccc8 + iVar2) = iVar1;
    (&DAT_0097cccc)[iVar9 * 0x1004] = 0;
    if (((u32)param_2 & 7) == 0) {
      puVar3 = param_2 + 0x80;
      do {
        uVar7 = param_2[1];
        uVar8 = param_2[2];
        uVar6 = param_2[3];
        *puVar4 = *param_2;
        puVar4[1] = uVar7;
        puVar4[2] = uVar8;
        puVar4[3] = uVar6;
        param_2 = param_2 + 4;
        puVar4 = puVar4 + 4;
      } while (param_2 != puVar3);
    }
    else {
      puVar3 = param_2 + 0x80;
      do {
        uVar7 = param_2[1];
        uVar8 = param_2[2];
        uVar6 = param_2[3];
        *puVar4 = *param_2;
        puVar4[1] = uVar7;
        puVar4[2] = uVar8;
        puVar4[3] = uVar6;
        param_2 = param_2 + 4;
        puVar4 = puVar4 + 4;
      } while (param_2 != puVar3);
    }
  }
  (&DAT_0097cccc)[iVar9 * 0x1004] = (&DAT_0097cccc)[iVar9 * 0x1004] + 1;
  return uVar5;
}
// FUN_0051A8A0 NONMATCHING
u64 FUN_0051a8a0(u64 param_1,u64 *param_2,int param_3)

{
  int iVar1;
  u64 *puVar2;
  u64 uVar3;
  u64 *puVar4;
  int iVar5;
  u64 uVar6;
  u64 uVar7;
  
  iVar5 = (int)param_1;
  iVar1 = (&DAT_0097ccc0)[iVar5 * 0x1004];
  param_3 = param_3 + *(int *)(&DAT_00782814 + iVar5 * 0x184);
  if ((param_3 < iVar1) || (iVar1 + (&DAT_0097cccc)[iVar5 * 0x1004] <= param_3)) {
    uVar3 = (u64)FUN_0051a418(param_1,(u64)(u32)param_2,(int)(u32)param_3,1);
  }
  else {
    iVar1 = iVar5 * 0x4010 + (param_3 - iVar1) * 0x400;
    puVar2 = (u64 *)(&DAT_0097ccd0 + iVar1);
    puVar4 = (u64 *)(iVar1 + 0x97d0d0);
    if (((u32)param_2 & 7) == 0) {
      do {
        uVar3 = puVar2[1];
        uVar6 = puVar2[2];
        uVar7 = puVar2[3];
        *param_2 = *puVar2;
        param_2[1] = uVar3;
        param_2[2] = uVar6;
        param_2[3] = uVar7;
        puVar2 = puVar2 + 4;
        param_2 = param_2 + 4;
      } while (puVar2 != puVar4);
      uVar3 = 1;
    }
    else {
      do {
        uVar3 = puVar2[1];
        uVar6 = puVar2[2];
        uVar7 = puVar2[3];
        *param_2 = *puVar2;
        param_2[1] = uVar3;
        param_2[2] = uVar6;
        param_2[3] = uVar7;
        puVar2 = puVar2 + 4;
        param_2 = param_2 + 4;
      } while (puVar2 != puVar4);
      uVar3 = 1;
    }
  }
  return uVar3;
}
// FUN_0051A9E0 NONMATCHING
u64 FUN_0051a9e0(u64 param_1,int param_2,u64 param_3,int param_4)
{
  FUN_0051a8a0(0,0,0);
  return 0;
}
// FUN_0051AA00 NONMATCHING
u64 FUN_0051aa00(int param_1,u64 param_2,int param_3,int param_4)
{
  return FUN_0051bd10(param_1,param_2,
               (param_3 + *(int *)(&DAT_00782814 + param_1 * 0x184)) *
               (u32)*(u16 *)(&DAT_0078280a + param_1 * 0x184),
               (u32)*(u16 *)(&DAT_0078280a + param_1 * 0x184) * param_4);
}
// FUN_0051AA48 NONMATCHING
u64 FUN_0051aa48(int param_1,u64 param_2,int param_3,int param_4)
{
  return FUN_0051bf40(param_1,param_2,
               (param_3 + *(int *)(&DAT_00782814 + param_1 * 0x184)) *
               (u32)*(u16 *)(&DAT_0078280a + param_1 * 0x184),
               (u32)*(u16 *)(&DAT_0078280a + param_1 * 0x184) * param_4);
}
// FUN_0051AA90 NONMATCHING
u32 FUN_0051aa90(u64 param_1,u64 param_2,int param_3,int param_4)

{
  long lVar1;
  
  while( true ) {
    if (param_4 < 1) {
      return 1;
    }
    lVar1 = (long)FUN_0051a508(param_1,(u64 *)(u64)param_2,param_3);
    param_4 = param_4 + -1;
    if (lVar1 == 0) break;
    param_3 = param_3 + 1;
  }
  return 0;
}
// FUN_0051AB08 NONMATCHING
u32 FUN_0051ab08(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(&DAT_007828b0 + param_1 * 0x184);
  do {
    iVar1 = iVar1 + 1;
    if (*piVar2 == param_2) {
      return 1;
    }
    piVar2 = piVar2 + 1;
  } while (iVar1 < 0x20);
  return 0;
}
// FUN_0051AB50 NONMATCHING
u32 FUN_0051ab50(int param_1,int param_2)

{
  if (*(u16 *)(&DAT_0078280c + param_1 * 0x184) == 0) {
    trap(7);
  }
  return FUN_0051ab08(param_1,(int)(param_2 * (u32)*(u16 *)(&DAT_0078280a + param_1 * 0x184)) /
                       (int)(u32)*(u16 *)(&DAT_0078280c + param_1 * 0x184));
}
// FUN_0051AB98 NONMATCHING
u32 FUN_0051ab98(u32 param_1,int *param_2,int *param_3)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  u32 uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  if (param_2[1] == 0) {
    trap(7);
  }
  iVar1 = param_2[2] / param_2[1];
  if (1 < iVar1) {
    bVar2 = true;
    iVar5 = 1;
    do {
      if (!bVar2) {
        return 1;
      }
      iVar3 = 0x800 / *param_2;
      if (*param_2 == 0) {
        trap(7);
      }
      bVar2 = false;
      FUN_0051b708(param_1,0x984d00,iVar5 * param_2[1],iVar3,0);
      uVar4 = 0;
      if ((u32)(*param_2 * iVar3) >> 2 != 0) {
        if ((int)DAT_00984d00 == -1) {
          do {
            uVar4 = uVar4 + 1;
            if ((u32)(*param_2 * iVar3) >> 2 <= uVar4) goto LAB_0051acb4;
          } while (*(int *)((int)&DAT_00984d00 + uVar4 * 4) == -1);
          bVar2 = true;
        }
        else {
          bVar2 = true;
        }
      }
LAB_0051acb4:
      iVar3 = iVar5 + 1;
      if (bVar2) {
        *param_3 = iVar5;
        iVar6 = iVar6 + 1;
        param_3 = param_3 + 1;
      }
      bVar2 = iVar6 < 0x10;
      iVar5 = iVar3;
    } while (iVar3 < iVar1);
  }
  return 1;
}
// FUN_0051AD10 NONMATCHING
u64 FUN_0051ad10(void)

{
  u64 uVar1;
  
  uVar1 = 0x9855c0;
  DAT_00782ae8 = 0;
  WaitSema(DAT_00985500);
  FUN_00503b98(0x9855c0,0x9856bf);
  if ((DAT_00782ae8 < DAT_009855c0) && (DAT_00985640 < DAT_009855c0)) {
    DAT_00782ae8 = DAT_009855c0;
  }
  else if (DAT_00782ae8 < DAT_00985640) {
    if (DAT_009855c0 < DAT_00985640) {
      DAT_00782ae8 = DAT_00985640;
      uVar1 = 0x985640;
    }
    else {
      DAT_009855c8 = 0;
    }
  }
  else {
    DAT_009855c8 = 0;
  }
  return uVar1;
}
// FUN_0051ADE0 NONMATCHING
u64 FUN_0051ade0(void)

{
  WaitSema(DAT_00985500);
  FUN_00503b98(0x9855c0,0x98563f);
  if (DAT_009855c0 < 1) {
    DAT_009855c8 = 0;
  }
  return 0x9855c0;
}
// FUN_0051AE38 NONMATCHING
void FUN_0051ae38(void)

{
  iSignalSema(DAT_00985500);
  SYNC(0);
  EI();
  return;
}
// FUN_0051AE68 NONMATCHING
u32 FUN_0051ae68(void)

{
  u32 uVar1;
  long lVar2;
  u32 *puVar3;
  u8 auStack_30 [4];
  u32 uStack_2c;
  u32 uStack_28;
  char *pcStack_1c;
  
  DAT_00782ae8 = 0;
  uStack_2c = 0x7f;
  pcStack_1c = s_sceMc2_sema_subs_007be668;
  uStack_28 = 0;
  lVar2 = CreateSema(auStack_30);
  DAT_00985500 = (u32)lVar2;
  if (lVar2 < 0) {
    uVar1 = 0;
  }
  else {
    puVar3 = &DAT_00985508;
    do {
      *puVar3 = 0;
      puVar3[2] = 0x200;
      puVar3[3] = 0x10;
      puVar3[4] = 0x4000;
      puVar3 = puVar3 + 9;
    } while ((int)puVar3 < 0x985550);
    uVar1 = 1;
  }
  return uVar1;
}
// FUN_0051AEF8 NONMATCHING
u32 FUN_0051aef8(void)

{
  int iVar1;
  int *piVar2;
  
  if (-1 < DAT_00985500) {
    DeleteSema();
  }
  piVar2 = (int *)(&DAT_00985508);
  iVar1 = DAT_00985508;
  while( true ) {
    if (iVar1 != 0) {
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 9;
    if (0x98554f < (int)piVar2) break;
    iVar1 = *piVar2;
  }
  return 1;
}
// FUN_0051AF70 NONMATCHING
u32 FUN_0051af70(int param_1,u32 param_2,u32 param_3)

{
  *(u32 *)(&DAT_00985524 + param_1 * 0x24) = param_2;
  *(u32 *)(param_1 * 0x24 + 0x985528) = param_3;
  return 1;
}
// FUN_0051AF98 NONMATCHING
u32 FUN_0051af98(int param_1,u64 *param_2)

{
  u64 uVar1;
  
  uVar1 = param_2[1];
  *(u64 *)(&DAT_00985510 + param_1 * 9) = *param_2;
  *(u64 *)(&DAT_00985518 + param_1 * 9) = uVar1;
  return 1;
}
// FUN_0051AFD8 NONMATCHING
u32 FUN_0051afd8(int param_1,u64 *param_2)

{
  u32 uVar1;
  int iVar2;
  long lVar3;
  u64 uVar4;
  u32 *puVar5;
  u32 uStack_b0;
  u64 *puStack_ac;
  
  puVar5 = (u32 *)(&DAT_0098550c + param_1 * 0x24);
  puStack_ac = param_2;
  lVar3 = FUN_0051cad0(*puVar5);
  if (lVar3 != 3) {
    DAT_009855a4 = 0;
    uStack_b0 = 0x30;
    DAT_00985588 = 0;
    DAT_0098558c = 0;
    DAT_00985590 = 0;
    DAT_00985594 = 0;
    DAT_00985598 = 0;
    DAT_0098559c = 0;
    DAT_009855a0 = 0;
    FUN_00521408(0x9855c0,0,0x100);
    FUN_00503a58(0x9855c0,0x9856bf);
    DAT_00782aec = 3;
    uVar1 = *puVar5;
    while (lVar3 = FUN_0051d308(uVar1,DAT_00782aec,(int *)(u32)&uStack_b0,(u8 *)0x985580,0x51ae38), lVar3 != 1) {
      uVar1 = *puVar5;
    }
    iVar2 = FUN_0051ad10();
    if (*(int *)(iVar2 + 8) == 1) {
      (&DAT_00985510)[param_1 * 9] =
           (u32)*(u8 *)(iVar2 + 0xc) + (u32)*(u8 *)(iVar2 + 0xd) * 0x100;
      (&DAT_00985514)[param_1 * 9] =
           (u32)*(u8 *)(iVar2 + 0xe) + (u32)*(u8 *)(iVar2 + 0xf) * 0x100;
      (&DAT_00985518)[param_1 * 9] =
           (u32)*(u8 *)(iVar2 + 0x10) + (u32)*(u8 *)(iVar2 + 0x13) * 0x1000000 +
           (u32)*(u8 *)(iVar2 + 0x12) * 0x10000 + (u32)*(u8 *)(iVar2 + 0x11) * 0x100;
      *(u32 *)(&DAT_0098551c + param_1 * 0x24) = 1;
      uVar4 = *(u64 *)(&DAT_00985518 + param_1 * 9);
      *puStack_ac = *(u64 *)(&DAT_00985510 + param_1 * 9);
      puStack_ac[1] = uVar4;
      return 1;
    }
  }
  return 0;
}
// FUN_0051B1B0 NONMATCHING
u32 FUN_0051b1b0(int param_1)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  u32 *puVar4;
  u32 auStack_70 [4];
  
  puVar4 = (u32 *)(&DAT_0098550c + param_1 * 0x24);
  lVar3 = FUN_0051cad0(*puVar4);
  if (lVar3 == 3) {
    uVar2 = 0;
  }
  else {
    DAT_00985588 = (&DAT_00985510)[param_1 * 9];
    DAT_0098558c = (&DAT_00985514)[param_1 * 9];
    DAT_00985590 = (&DAT_00985518)[param_1 * 9];
    DAT_00985598 = 0;
    auStack_70[0] = 0x30;
    DAT_00985594 = 0;
    FUN_00521408(0x9855c0,0,0x100);
    FUN_00503a58(0x9855c0,0x9856bf);
    DAT_00782aec = 4;
    uVar2 = *puVar4;
    while (lVar3 = FUN_0051d308(uVar2,DAT_00782aec,(int *)(u32)auStack_70,(u8 *)0x985580,0x51ae38), lVar3 != 1) {
      uVar2 = *puVar4;
    }
    iVar1 = FUN_0051ad10();
    uVar2 = *(u32 *)(iVar1 + 8);
  }
  return uVar2;
}
// FUN_0051B2C0 NONMATCHING
bool FUN_0051b2c0(int param_1)

{
  u32 uVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  u32 *puVar5;
  u32 auStack_70 [4];
  
  puVar5 = (u32 *)(&DAT_0098550c + param_1 * 0x24);
  lVar4 = FUN_0051cad0(*puVar5);
  if (lVar4 == 3) {
    bVar2 = false;
  }
  else {
    DAT_00985598 = 0;
    auStack_70[0] = 0x30;
    DAT_00985594 = 0;
    FUN_00521408(0x9855c0,0,0x100);
    FUN_00503a58(0x9855c0,0x9856bf);
    DAT_00782aec = 0xd;
    uVar1 = *puVar5;
    while (lVar4 = FUN_0051d308(uVar1,DAT_00782aec,(int *)(u32)auStack_70,(u8 *)0x985580,0x51ae38), lVar4 != 1) {
      uVar1 = *puVar5;
    }
    iVar3 = FUN_0051ad10();
    bVar2 = *(int *)(iVar3 + 8) == 1;
  }
  return bVar2;
}
// FUN_0051B3B0 NONMATCHING
bool FUN_0051b3b0(int param_1)

{
  u32 uVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  u32 *puVar5;
  u32 auStack_70 [4];
  
  puVar5 = (u32 *)(&DAT_0098550c + param_1 * 0x24);
  lVar4 = FUN_0051cad0(*puVar5);
  if (lVar4 == 3) {
    bVar2 = false;
  }
  else {
    DAT_00985598 = 0;
    auStack_70[0] = 0x30;
    DAT_00985594 = 0;
    FUN_00521408(0x9855c0,0,0x100);
    FUN_00503a58(0x9855c0,0x9856bf);
    DAT_00782aec = 0xc;
    uVar1 = *puVar5;
    while (lVar4 = FUN_0051d308(uVar1,DAT_00782aec,(int *)(u32)auStack_70,(u8 *)0x985580,0x51ae38), lVar4 != 1) {
      uVar1 = *puVar5;
    }
    iVar3 = FUN_0051ad10();
    bVar2 = *(int *)(iVar3 + 8) == 1;
  }
  return bVar2;
}
// FUN_0051B4A0 NONMATCHING
u32 FUN_0051b4a0(int param_1)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  u32 *puVar4;
  u32 auStack_80 [4];
  
  iVar1 = param_1 * 0x24;
  puVar4 = (u32 *)(&DAT_0098550c + iVar1);
  lVar3 = FUN_0051cad0(*puVar4);
  if (lVar3 == 3) {
    uVar2 = 0;
  }
  else if (((&DAT_00985510)[param_1 * 9] == 0) || ((&DAT_00985514)[param_1 * 9] == 0)) {
    FUN_00505e48(0x7be680);
    uVar2 = 0;
  }
  else {
    DAT_00985594 = *(u32 *)(iVar1 + 0x985528);
    DAT_00985598 = *(u32 *)(&DAT_00985524 + iVar1);
    DAT_009855a4 = *(u32 *)(&DAT_0098551c + iVar1);
    DAT_00985590 = (&DAT_00985518)[param_1 * 9];
    auStack_80[0] = 0x30;
    DAT_00985588 = (&DAT_00985510)[param_1 * 9];
    DAT_0098558c = (&DAT_00985514)[param_1 * 9];
    FUN_00521408(0x9855c0,0,0x100);
    FUN_00503a58(0x9855c0,0x9856bf);
    DAT_00782aec = 6;
    uVar2 = *puVar4;
    while (lVar3 = FUN_0051d308(uVar2,DAT_00782aec,(int *)(u32)auStack_80,(u8 *)0x985580,0x51ae38), lVar3 != 1) {
      uVar2 = *puVar4;
    }
    iVar1 = FUN_0051ad10();
    uVar2 = *(u32 *)(iVar1 + 8);
  }
  return uVar2;
}
// FUN_0051B5F0 NONMATCHING
u32 FUN_0051b5f0(int param_1,u64 *param_2)

{
  u32 uVar1;
  int iVar2;
  long lVar3;
  u32 *puVar4;
  u32 auStack_80 [4];
  
  puVar4 = (u32 *)(&DAT_0098550c + param_1 * 0x24);
  lVar3 = FUN_0051cad0(*puVar4);
  if (lVar3 != 3) {
    DAT_00985598 = 0;
    auStack_80[0] = 0x30;
    DAT_00985594 = 0;
    FUN_00521408(0x9855c0,0,0x100);
    FUN_00503a58(0x9855c0,0x9856bf);
    DAT_00782aec = 10;
    uVar1 = *puVar4;
    while (lVar3 = FUN_0051d308(uVar1,DAT_00782aec,(int *)(u32)auStack_80,(u8 *)0x985580,0x51ae38), lVar3 != 1) {
      uVar1 = *puVar4;
    }
    iVar2 = FUN_0051ad10();
    if (*(int *)(iVar2 + 8) != 0) {
      *param_2 = *(u64 *)(iVar2 + 0xc);
      return *(u32 *)(iVar2 + 8);
    }
  }
  return 0;
}
// FUN_0051B708 NONMATCHING
int FUN_0051b708(int param_1,int param_2,u32 param_3,int param_4,u32 param_5)

{
  u32 uVar1;
  int iVar2;
  long lVar3;
  u32 *puVar4;
  u32 auStack_a0 [4];
  
  puVar4 = (u32 *)(&DAT_0098550c + param_1 * 0x24);
  lVar3 = FUN_0051cad0(*puVar4);
  if (lVar3 != 3) {
    DAT_00985590 = (&DAT_00985518)[param_1 * 9];
    DAT_00985588 = (&DAT_00985510)[param_1 * 9];
    DAT_0098558c = (&DAT_00985514)[param_1 * 9];
    auStack_a0[0] = 0x30;
    DAT_00985594 = 0;
    DAT_00985598 = 0;
    DAT_0098559c = 0;
    DAT_009855a0 = 0;
    DAT_00985580 = param_3;
    DAT_00985584 = param_4;
    DAT_009855a4 = param_5;
    FUN_00521408(0x9855c0,0,0x100);
    FUN_00503a58(0x9855c0,0x9856bf);
    DAT_00782aec = 1;
    uVar1 = *puVar4;
    while (lVar3 = FUN_0051d308(uVar1,DAT_00782aec,(int *)(u32)auStack_a0,(u8 *)0x985580,0x51ae38), lVar3 != 1) {
      uVar1 = *puVar4;
    }
    iVar2 = FUN_0051ade0();
    if (*(int *)(iVar2 + 8) == 1) {
      puVar4 = &DAT_00985640;
      iVar2 = param_4;
      if (param_4 < 1) {
        return param_4;
      }
      do {
        iVar2 = iVar2 + -1;
        FUN_00503b98(puVar4,(int)puVar4 + DAT_00985588 + -1);
        FUN_00503a58(param_2,param_2 + DAT_00985588 + -1);
        FUN_00521250(param_2,puVar4,DAT_00985588);
        param_2 = param_2 + DAT_00985588;
        puVar4 = (u32 *)((int)puVar4 + DAT_00985588);
      } while (iVar2 != 0);
      return param_4;
    }
  }
  return 0;
}
// FUN_0051B8D0 NONMATCHING
u64 FUN_0051b8d0(int param_1,u64 param_2,u32 param_3,u32 param_4)

{
  FUN_0051b708(0,0,0,0,0);
  return 0;
}
// FUN_0051B8F0 NONMATCHING
u64 FUN_0051b8f0(int param_1,u64 param_2,u32 param_3,u64 param_4)

{
  u32 uVar1;
  int iVar2;
  long lVar3;
  u64 uVar4;
  u32 *puVar5;
  u32 auStack_b0 [4];
  
  iVar2 = param_1 * 0x24;
  puVar5 = (u32 *)(&DAT_0098550c + iVar2);
  lVar3 = FUN_0051cad0(*puVar5);
  if (lVar3 == 3) {
    uVar4 = 0;
  }
  else {
    DAT_00985590 = (&DAT_00985518)[param_1 * 9];
    DAT_00985594 = *(u32 *)(iVar2 + 0x985528);
    DAT_00985598 = *(u32 *)(&DAT_00985524 + iVar2);
    DAT_009855a4 = *(u32 *)(&DAT_0098551c + iVar2);
    DAT_00985588 = (&DAT_00985510)[param_1 * 9];
    DAT_0098558c = (&DAT_00985514)[param_1 * 9];
    auStack_b0[0] = 0x30;
    DAT_0098559c = 0;
    DAT_009855a0 = 0;
    DAT_00985580 = param_3;
    DAT_00985584 = (int)param_4;
    DAT_009855a8 = (int)param_2;
    FUN_00521408(0x9855c0,0,0x100);
    FUN_00503a58(0x9855c0,0x9856bf);
    FUN_00503a58(param_2,(&DAT_00985510)[param_1 * 9] * (int)param_4 + (int)param_2 + -1);
    DAT_00782aec = 2;
    uVar1 = *puVar5;
    while (lVar3 = FUN_0051d308(uVar1,DAT_00782aec,(int *)(u32)auStack_b0,(u8 *)0x985580,0x51ae38), lVar3 != 1) {
      uVar1 = *puVar5;
    }
    iVar2 = FUN_0051ad10();
    uVar4 = 0;
    if (*(int *)(iVar2 + 8) == 1) {
      uVar4 = param_4;
    }
  }
  return uVar4;
}
// FUN_0051BA88 NONMATCHING
u64 FUN_0051ba88(int param_1,u32 param_2,u64 param_3)

{
  u32 uVar1;
  int iVar2;
  long lVar3;
  u64 uVar4;
  u32 *puVar5;
  u32 auStack_90 [4];
  
  puVar5 = (u32 *)(&DAT_0098550c + param_1 * 0x24);
  lVar3 = FUN_0051cad0(*puVar5);
  if (lVar3 == 3) {
    uVar4 = 0;
  }
  else {
    DAT_0098558c = (&DAT_00985514)[param_1 * 9];
    DAT_00985590 = (&DAT_00985518)[param_1 * 9];
    DAT_009855a4 = *(u32 *)(&DAT_0098551c + param_1 * 0x24);
    DAT_00985588 = (&DAT_00985510)[param_1 * 9];
    auStack_90[0] = 0x30;
    DAT_00985584 = (u32)param_3;
    DAT_00985594 = 0;
    DAT_00985598 = 0;
    DAT_0098559c = 0;
    DAT_009855a0 = 0;
    DAT_00985580 = param_2;
    FUN_00521408(0x9855c0,0,0x100);
    FUN_00503a58(0x9855c0,0x9856bf);
    DAT_00782aec = 0xb;
    uVar1 = *puVar5;
    while (lVar3 = FUN_0051d308(uVar1,DAT_00782aec,(int *)(u32)auStack_90,(u8 *)0x985580,0x51ae38), lVar3 != 1) {
      uVar1 = *puVar5;
    }
    iVar2 = FUN_0051ad10();
    uVar4 = 0;
    if (*(int *)(iVar2 + 8) == 1) {
      uVar4 = param_3;
    }
  }
  return uVar4;
}
// FUN_0051BBD8 NONMATCHING
bool FUN_0051bbd8(int param_1,u32 param_2)

{
  u32 uVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  u32 *puVar5;
  u32 auStack_80 [4];
  
  puVar5 = (u32 *)(&DAT_0098550c + param_1 * 0x24);
  lVar4 = FUN_0051cad0(*puVar5);
  if (lVar4 == 3) {
    bVar2 = false;
  }
  else {
    DAT_00985590 = (&DAT_00985518)[param_1 * 9];
    DAT_00985588 = (&DAT_00985510)[param_1 * 9];
    DAT_0098558c = (&DAT_00985514)[param_1 * 9];
    DAT_00985584 = 1;
    auStack_80[0] = 0x30;
    DAT_00985580 = 0;
    DAT_00985594 = 0;
    DAT_00985598 = 0;
    DAT_0098559c = 0;
    DAT_009855a0 = param_2;
    FUN_00521408(0x9855c0,0,0x100);
    FUN_00503a58(0x9855c0,0x9856bf);
    DAT_00782aec = 9;
    uVar1 = *puVar5;
    while (lVar4 = FUN_0051d308(uVar1,DAT_00782aec,(int *)(u32)auStack_80,(u8 *)0x985580,0x51ae38), lVar4 != 1) {
      uVar1 = *puVar5;
    }
    iVar3 = FUN_0051ad10();
    bVar2 = *(int *)(iVar3 + 8) == 1;
  }
  return bVar2;
}
// FUN_0051BD10 NONMATCHING
u32 FUN_0051bd10(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  u8 *puVar4;
  int iVar5;
  u32 uStack_b0;
  int iStack_ac;
  int iStack_a8;
  
  iStack_ac = param_1;
  lVar3 = FUN_0051cad0(*(u32 *)(&DAT_0098550c + param_1 * 0x24));
  if (lVar3 == 3) {
LAB_0051bd74:
    uVar2 = 0;
  }
  else {
    iStack_a8 = 0x10000 / (int)(&DAT_00985510)[param_1 * 9];
    if ((&DAT_00985510)[param_1 * 9] == 0) {
      trap(7);
    }
    for (; 0 < param_4; param_4 = param_4 - iVar5) {
      iVar1 = iStack_ac * 0x24;
      iVar5 = iStack_a8;
      if (param_4 < iStack_a8) {
        iVar5 = param_4;
      }
      DAT_00985588 = (&DAT_00985510)[iStack_ac * 9];
      DAT_0098558c = (&DAT_00985514)[iStack_ac * 9];
      DAT_00985590 = (&DAT_00985518)[iStack_ac * 9];
      DAT_009855a4 = *(u32 *)(&DAT_0098551c + iVar1);
      uStack_b0 = 0x30;
      DAT_00985594 = 0;
      DAT_00985598 = 0;
      DAT_0098559c = 0;
      DAT_009855a0 = 0;
      DAT_009855a8 = (u32)(&DAT_00985ec0);
      DAT_00985580 = param_3;
      DAT_00985584 = iVar5;
      FUN_00521408(0x9855c0,0,0x80);
      FUN_00503a58(0x9855c0,0x98563f);
      DAT_00782aec = 0x11;
      FUN_0051d308(*(u32 *)(&DAT_0098550c + iVar1),0x11,(int *)&uStack_b0,(u8 *)0x985580,0x51ae38);
      iVar1 = FUN_0051ade0();
      if (*(int *)(iVar1 + 8) != 1) goto LAB_0051bd74;
      puVar4 = (u8 *)(&DAT_00985ec0);
      FUN_00503b98(0x985ec0,0x99673f);
      iVar1 = 0;
      if (0 < iVar5) {
        do {
          iVar1 = iVar1 + 1;
          FUN_00521250(param_2,puVar4,DAT_00985588);
          FUN_00503a58(param_2,param_2 + DAT_00985588 + -1);
          param_2 = param_2 + DAT_00985588;
          puVar4 = puVar4 + DAT_00985588;
        } while (iVar1 < iVar5);
      }
      param_3 = param_3 + iVar5;
    }
    uVar2 = 1;
  }
  return uVar2;
}
// FUN_0051BF40 NONMATCHING
u64 FUN_0051bf40(int param_1,u64 param_2,u32 param_3,u64 param_4)

{
  int iVar1;
  long lVar2;
  u64 uVar3;
  u32 auStack_90 [4];
  
  iVar1 = param_1 * 0x24;
  lVar2 = FUN_0051cad0(*(u32 *)(&DAT_0098550c + iVar1));
  if (lVar2 == 3) {
    uVar3 = 0;
  }
  else {
    DAT_0098558c = (&DAT_00985514)[param_1 * 9];
    DAT_00985590 = (&DAT_00985518)[param_1 * 9];
    DAT_00985594 = *(u32 *)(iVar1 + 0x985528);
    DAT_00985598 = *(u32 *)(&DAT_00985524 + iVar1);
    DAT_009855a4 = *(u32 *)(&DAT_0098551c + iVar1);
    DAT_00985588 = (&DAT_00985510)[param_1 * 9];
    DAT_009855ac = (u32)(&DAT_00985ec0);
    auStack_90[0] = 0x30;
    DAT_0098559c = 0;
    DAT_009855a0 = 0;
    DAT_00985580 = param_3;
    DAT_00985584 = (int)param_4;
    DAT_009855a8 = (int)param_2;
    FUN_00521408(0x9855c0,0,0x100);
    FUN_00503a58(0x9855c0,0x98563f);
    FUN_00503a58(param_2,(&DAT_00985510)[param_1 * 9] * (int)param_4 + (int)param_2 + -1);
    DAT_00782aec = 0x10;
    FUN_0051d308(*(u32 *)(&DAT_0098550c + iVar1),0x10,(int *)(u32)auStack_90,(u8 *)0x985580,0x51ae38);
    iVar1 = FUN_0051ade0();
    uVar3 = 0;
    if (*(int *)(iVar1 + 8) == 1) {
      uVar3 = param_4;
    }
  }
  return uVar3;
}
// FUN_0051C0C0 NONMATCHING
bool FUN_0051c0c0(int param_1)

{
  long lVar1;
  
  lVar1 = FUN_0051cad0(*(u32 *)(&DAT_0098550c + param_1 * 0x24));
  return lVar1 != 3;
}
// FUN_0051C0F8 NONMATCHING
int FUN_0051c0f8(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(&DAT_00985508);
  do {
    if (*piVar2 == 0) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 9;
  } while (iVar1 < 2);
  return -1;
}
// FUN_0051C130 NONMATCHING
long FUN_0051c130(u32 *param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  u32 auStack_70 [3];
  u32 uStack_64;
  u32 uStack_60;
  char acStack_5c [8];
  char acStack_54 [20];
  
  lVar2 = FUN_0051c0f8();
  lVar3 = -1;
  if (-1 < lVar2) {
    uStack_64 = param_1[2];
    uStack_60 = param_1[3];
    auStack_70[2] = param_1[1];
    acStack_5c[0] = s_MC2SOCKET_007be690[0];
    acStack_5c[1] = s_MC2SOCKET_007be690[1];
    acStack_5c[2] = s_MC2SOCKET_007be690[2];
    acStack_5c[3] = s_MC2SOCKET_007be690[3];
    acStack_5c[4] = s_MC2SOCKET_007be690[4];
    acStack_5c[5] = s_MC2SOCKET_007be690[5];
    acStack_5c[6] = s_MC2SOCKET_007be690[6];
    acStack_5c[7] = s_MC2SOCKET_007be690[7];
    acStack_54[0] = s_MC2SOCKET_007be690[8];
    acStack_54[1] = s_MC2SOCKET_007be690[9];
    auStack_70[1] = 2;
    auStack_70[0] = *param_1 | 1;
    FUN_00521408(0x9855c0,0,0x100);
    lVar3 = FUN_0051c770(auStack_70,0x9855c0,0x985640);
    iVar4 = (int)lVar2;
    iVar1 = iVar4 * 0x24;
    *(int *)(&DAT_0098550c + iVar1) = (int)lVar3;
    if (lVar3 < 0) {
      lVar3 = -1;
    }
    else {
      (&DAT_00985508)[iVar4 * 9] = 1;
      *(u32 *)(&DAT_00985524 + iVar1) = 0;
      *(u32 *)(iVar1 + 0x985528) = 0;
      (&DAT_00985510)[iVar4 * 9] = 0x200;
      (&DAT_00985514)[iVar4 * 9] = 0x10;
      (&DAT_00985518)[iVar4 * 9] = 0x4000;
      lVar3 = lVar2;
    }
  }
  return lVar3;
}
// FUN_0051C250 NONMATCHING
bool FUN_0051c250(u32 param_1)

{
  if (1 < param_1) {
    return false;
  }
  return (&DAT_00985508)[(int)param_1 * 9] != 0;
}
// FUN_0051C280 NONMATCHING
bool FUN_0051c280(int param_1)

{
  long lVar1;
  
  lVar1 = FUN_0051c250(param_1);
  if (lVar1 != 0) {
    FUN_0051c8a0(*(u32 *)(&DAT_0098550c + param_1 * 0x24));
    (&DAT_00985508)[param_1 * 9] = 0;
  }
  return lVar1 != 0;
}
// FUN_0051C2E8 NONMATCHING
int FUN_0051c2e8(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(&DAT_00985508);
  while ((*piVar2 == 0 || (piVar2[1] != param_1))) {
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 9;
    if (1 < iVar1) {
      return -1;
    }
  }
  return iVar1;
}
// FUN_0051C330 NONMATCHING
u32 FUN_0051c330(int param_1)

{
  if ((&DAT_00985508)[param_1 * 9] == 0) {
    return 0xffffffff;
  }
  return *(u32 *)(&DAT_0098550c + param_1 * 0x24);
}
// FUN_0051C360 NONMATCHING
u32 FUN_0051c360(void)

{
  FUN_00507230(0x996740,0xffffffff80001363,0,0x996840,0x90,0x996840,0x90,0);
  return DAT_00996840;
}
// FUN_0051C3B8 NONMATCHING
u32 FUN_0051c3b8(void)

{
  u32 uVar1;
  u32 *puVar2;
  u32 uVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  u8 auStack_c0 [4];
  u32 uStack_bc;
  u32 uStack_b8;
  char *pcStack_ac;
  
  if (ram0x00782b00 == 1) {
    return 1;
  }
  DAT_00997000 = 0;
  FUN_005068a8(0);
  while (lVar4 = FUN_00507050(0x996740,0xffffffff80001300,0), -1 < lVar4) {
    iVar6 = 0x10000;
    if (DAT_00996764 != 0) {
      uVar1 = FUN_0051c360();
      if ((int)uVar1 >> 4 != 0x32) {
        FUN_00505e48(0x7be6b8);
        FUN_00505e48(0x7be6e0,3,0x20,(int)uVar1 >> 8,uVar1 & 0xff);
        return 0;
      }
      goto LAB_0051c4dc;
    }
    do {
      iVar6 = iVar6 + -1;
    } while (iVar6 != -1);
  }
LAB_0051c5c0:
  return 0;
LAB_0051c4dc:
  lVar4 = FUN_00507050(0x996790,0xffffffff8000131c,0);
  if (lVar4 < 0) goto LAB_0051c5c0;
  if (DAT_009967b4 != 0) {
    iVar6 = 0;
    piVar8 = (int *)(&DAT_009967dc);
    iVar7 = 0;
    while (lVar4 = FUN_00507050(iVar7 + 0x9967b8,iVar6 + -0x7fffece2,0), -1 < lVar4) {
      iVar5 = 0x10000;
      if (*piVar8 == 0) {
        do {
          iVar5 = iVar5 + -1;
        } while (iVar5 != -1);
      }
      else {
        iVar6 = iVar6 + 1;
        piVar8 = piVar8 + 10;
        iVar7 = iVar7 + 0x28;
        if (1 < iVar6) {
          uStack_b8 = 1;
          uStack_bc = 0x7f;
          pcStack_ac = s_sceDbc_sema_007be710;
          lVar4 = CreateSema(auStack_c0);
          DAT_00997000 = (u32)lVar4;
          if (lVar4 < 0) {
            uVar3 = 0;
          }
          else {
            iVar6 = 0xf;
            puVar2 = (u32 *)&DAT_00996ffc;
            do {
              *puVar2 = 0;
              iVar6 = iVar6 + -1;
              puVar2 = puVar2 + -1;
            } while (-1 < iVar6);
            FUN_0051d588(0x7be720,0x996f40);
            uVar3 = 1;
            ram0x00782b00 = 1;
          }
          return uVar3;
        }
      }
    }
    goto LAB_0051c5c0;
  }
  iVar6 = 0x10000;
  do {
    iVar6 = iVar6 + -1;
  } while (iVar6 != -1);
  goto LAB_0051c4dc;
}
// FUN_0051C658 NONMATCHING
u32 FUN_0051c658(void)

{
  u32 uVar1;
  
  if (ram0x00782b00 == 0) {
    uVar1 = 0;
  }
  else {
    ram0x00782b00 = 0;
    uVar1 = 1;
    if (-1 < DAT_00997000) {
      DeleteSema();
      uVar1 = 1;
    }
  }
  return uVar1;
}
// FUN_0051C6A0 NONMATCHING
u32 FUN_0051c6a0(void)

{
  u32 uVar1;
  long lVar2;
  
  lVar2 = FUN_00507230(0x996740,0xffffffff80001305,0,0x996840,0x90,0x996840,0x90,0);
  uVar1 = DAT_00996844;
  if (lVar2 < 0) {
    uVar1 = 0;
  }
  return uVar1;
}
// FUN_0051C700 NONMATCHING
u32 FUN_0051c700(u32 param_1)

{
  u32 uVar1;
  long lVar2;
  
  DAT_00996844 = param_1;
  lVar2 = FUN_00507230(0x996740,0xffffffff80001304,0,0x996840,0x90,0x996840,0x90,0);
  uVar1 = DAT_00996840;
  if (lVar2 < 0) {
    FUN_0051d588(0x7be740);
    uVar1 = 0;
  }
  return uVar1;
}
// FUN_0051C770 NONMATCHING
u32 FUN_0051c770(u32 *param_1,u32 param_2,u32 param_3)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  u8 *puVar4;
  int iVar5;
  
  if (ram0x00782b00 == 0) {
    uVar2 = 0;
  }
  else {
    WaitSema(DAT_00997000);
    DAT_00996840 = *param_1;
    iVar5 = 0;
    DAT_00996844 = param_1[1];
    DAT_00996848 = param_1[2];
    DAT_0099684c = param_1[3];
    DAT_00996850 = param_1[4];
    DAT_00996868 = param_2;
    DAT_0099686c = param_3;
    do {
      iVar1 = iVar5 + 0x14;
      puVar4 = (u8 *)((int)&DAT_00996854 + iVar5);
      iVar5 = iVar5 + 1;
      *puVar4 = *(u8 *)((int)param_1 + iVar1);
    } while (iVar5 < 0x10);
    lVar3 = FUN_00507230(0x996740,0xffffffff80001301,0,0x996840,0x90,0x996840,0x90,0);
    uVar2 = DAT_00996864;
    if (lVar3 < 0) {
      FUN_0051d588(0x7be760);
      SignalSema(DAT_00997000);
      uVar2 = 0;
    }
    else {
      SignalSema(DAT_00997000);
    }
  }
  return uVar2;
}
// FUN_0051C8A0 NONMATCHING
u32 FUN_0051c8a0(u32 param_1)

{
  u32 uVar1;
  long lVar2;
  
  if (ram0x00782b00 == 0) {
    uVar1 = 0;
  }
  else {
    WaitSema(DAT_00997000);
    DAT_00996840 = param_1;
    lVar2 = FUN_00507230(0x996740,0xffffffff80001302,0,0x996840,0x90,0x996840,0x90,0);
    uVar1 = DAT_00996844;
    if (lVar2 < 0) {
      FUN_0051d588(0x7be780);
      SignalSema(DAT_00997000);
      uVar1 = 0;
    }
    else {
      SignalSema(DAT_00997000);
    }
  }
  return uVar1;
}
// FUN_0051C960 NONMATCHING
u32 FUN_0051c960(int param_1)

{
  u32 uVar1;
  long lVar2;
  
  FUN_00503a58(0x996f40,0x996fc0);
  FUN_0050d3a0();
  DAT_00996fc0 = DAT_00996f40;
  DAT_00996fc8 = DAT_00996f48;
  DAT_00996fd0 = DAT_00996f50;
  DAT_00996fd8 = DAT_00996f58;
  DAT_00996fe0 = DAT_00996f60;
  DAT_00996fe8 = DAT_00996f68;
  DAT_00996ff0 = DAT_00996f70;
  _DAT_00996ff8 = DAT_00996f78;
  FUN_0050d3f0();
  uVar1 = 0xfffffff4;
  if (*(int *)((int)&DAT_00996fc0 + param_1 * 4) == 1) {
    WaitSema(DAT_00997000);
    DAT_00996840 = param_1;
    lVar2 = FUN_00507230(0x996740,0xffffffff80001303,0,0x996840,0x90,0x996840,0x90,0);
    uVar1 = DAT_00996844;
    if (lVar2 < 0) {
      FUN_0051d588(0x7be7a0);
      SignalSema(DAT_00997000);
      uVar1 = 0;
    }
    else {
      SignalSema(DAT_00997000);
    }
  }
  return uVar1;
}
// FUN_0051CAD0 NONMATCHING
u32 FUN_0051cad0(int param_1)

{
  u32 uVar1;
  
  FUN_00503a58(0x996f40,0x996fc0);
  FUN_0050d3a0();
  DAT_00996fc0 = DAT_00996f40;
  DAT_00996fc8 = DAT_00996f48;
  DAT_00996fd0 = DAT_00996f50;
  DAT_00996fd8 = DAT_00996f58;
  DAT_00996fe0 = DAT_00996f60;
  DAT_00996fe8 = DAT_00996f68;
  DAT_00996ff0 = DAT_00996f70;
  _DAT_00996ff8 = DAT_00996f78;
  FUN_0050d3f0();
  uVar1 = 3;
  if (*(int *)((int)&DAT_00996fc0 + param_1 * 4) == 1) {
    uVar1 = 1;
  }
  return uVar1;
}
// FUN_0051CBC8 NONMATCHING
u32 FUN_0051cbc8(u32 param_1)

{
  u32 uVar1;
  long lVar2;
  
  WaitSema(DAT_00997000);
  DAT_00996840 = param_1;
  lVar2 = FUN_00507230(0x996740,0xffffffff80001315,0,0x996840,0x90,0x996840,0x90,0);
  uVar1 = DAT_00996844;
  if (lVar2 < 0) {
    FUN_0051d588(0x7be7c0);
    SignalSema(DAT_00997000);
    uVar1 = 0;
  }
  else {
    SignalSema(DAT_00997000);
  }
  return uVar1;
}
// FUN_0051CC78 NONMATCHING
u32 FUN_0051cc78(u32 param_1)

{
  u32 uVar1;
  long lVar2;
  
  WaitSema(DAT_00997000);
  DAT_00996840 = param_1;
  lVar2 = FUN_00507230(0x996740,0xffffffff80001316,0,0x996840,0x90,0x996840,0x90,0);
  uVar1 = DAT_00996844;
  if (lVar2 < 0) {
    FUN_0051d588(0x7be7e0);
    SignalSema(DAT_00997000);
    uVar1 = 0;
  }
  else {
    SignalSema(DAT_00997000);
  }
  return uVar1;
}
// FUN_0051CD28 NONMATCHING
u32 FUN_0051cd28(u32 param_1)

{
  u32 uVar1;
  long lVar2;
  
  WaitSema(DAT_00997000);
  DAT_00996840 = param_1;
  lVar2 = FUN_00507230(0x996740,0xffffffff80001317,0,0x996840,0x90,0x996840,0x90,0);
  uVar1 = DAT_00996844;
  if (lVar2 < 0) {
    FUN_0051d588(0x7be800);
    SignalSema(DAT_00997000);
    uVar1 = 0;
  }
  else {
    SignalSema(DAT_00997000);
  }
  return uVar1;
}
// FUN_0051CDD8 NONMATCHING
u32 FUN_0051cdd8(int param_1)

{
  u32 uVar1;
  long lVar2;
  
  WaitSema(DAT_00997000);
  DAT_00996848 = 2;
  DAT_00996850 = *(u32 *)(param_1 + 8);
  DAT_00996854 = *(u32 *)(param_1 + 0xc);
  lVar2 = FUN_00507230(0x996740,0xffffffff8000131d,0,0x996840,0x90,0x996840,0x90,0);
  uVar1 = DAT_00996844;
  if (lVar2 < 0) {
    FUN_0051d588(0x7be800);
    SignalSema(DAT_00997000);
    uVar1 = 0xffffffff;
  }
  else {
    SignalSema(DAT_00997000);
  }
  return uVar1;
}
// FUN_0051CE98 NONMATCHING
int FUN_0051ce98(u32 param_1,u32 param_2,int *param_3,u8 *param_4,int *param_5
                ,int param_6)

{
  u8 *puVar1;
  u8 *puVar2;
  long lVar3;
  u8 *puVar4;
  int iVar5;
  int iVar6;
  
  WaitSema(DAT_00997000);
  DAT_00996848 = *param_3;
  DAT_0099684c = *param_5;
  iVar5 = 0;
  puVar1 = param_4;
  DAT_00996840 = param_1;
  DAT_00996844 = param_2;
  if (0 < *param_3) {
    do {
      puVar4 = (u8 *)((int)&DAT_00996850 + iVar5);
      iVar5 = iVar5 + 1;
      *puVar4 = *puVar1;
      puVar1 = param_4 + iVar5;
    } while (iVar5 < *param_3);
  }
  lVar3 = FUN_00507230(0x996740,0xffffffff80001318,0,0x996840,0x90,0x996840,0x90,0);
  if (lVar3 < 0) {
    FUN_0051d588(0x7be828);
    SignalSema(DAT_00997000);
    iVar5 = 0;
  }
  else {
    if (-1 < DAT_00996950) {
      *param_3 = DAT_00996848;
      *param_5 = DAT_0099684c;
      if (0 < DAT_0099684c) {
        puVar2 = (u8 *)(&DAT_009968d0);
        iVar5 = 0;
        do {
          iVar6 = iVar5 + 1;
          *(u8 *)(param_6 + iVar5) = *puVar2;
          puVar2 = (u8 *)(iVar5 + 0x9968d1);
          iVar5 = iVar6;
        } while (iVar6 < DAT_0099684c);
      }
    }
    iVar5 = DAT_00996950;
    SignalSema(DAT_00997000);
  }
  return iVar5;
}
// FUN_0051D028 NONMATCHING
int FUN_0051d028(u32 param_1,u32 param_2,int *param_3,u8 *param_4)

{
  u8 *puVar1;
  long lVar2;
  u8 *puVar3;
  int iVar4;
  
  WaitSema(DAT_00997000);
  DAT_00996848 = *param_3;
  iVar4 = 0;
  puVar1 = param_4;
  DAT_00996840 = param_1;
  DAT_00996844 = param_2;
  if (0 < *param_3) {
    do {
      puVar3 = (u8 *)((int)&DAT_0099684c + iVar4);
      iVar4 = iVar4 + 1;
      *puVar3 = *puVar1;
      puVar1 = param_4 + iVar4;
    } while (iVar4 < *param_3);
  }
  lVar2 = FUN_00507230(0x996740,0xffffffff80001319,0,0x996840,0x90,0x996840,0x90,0);
  if (lVar2 < 0) {
    FUN_0051d588(0x7be848);
    SignalSema(DAT_00997000);
    iVar4 = 0;
  }
  else {
    if (-1 < DAT_009968cc) {
      *param_3 = DAT_00996848;
    }
    iVar4 = DAT_009968cc;
    SignalSema(DAT_00997000);
  }
  return iVar4;
}
// FUN_0051D158 NONMATCHING
u32 FUN_0051d158(u32 param_1,u32 param_2,int *param_3,u8 *param_4)

{
  int iVar1;
  u8 *puVar2;
  long lVar3;
  u8 *puVar4;
  char *pcVar5;
  int iVar6;
  
  if (*param_3 < 0x81) {
    WaitSema(DAT_00997000);
    DAT_00782b04 = DAT_00782b04 + 1;
    if (1 < DAT_00782b04) {
      DAT_00782b04 = 0;
    }
    iVar1 = DAT_00782b04 * 0xc0;
    *(u32 *)(&DAT_00996dc0 + iVar1) = param_1;
    *(u32 *)(&DAT_00996dc4 + iVar1) = param_2;
    *(int *)(&DAT_00996dc8 + iVar1) = *param_3;
    iVar6 = 0;
    if (0 < *param_3) {
      puVar2 = param_4;
      do {
        puVar4 = (u8 *)(iVar1 + 0x996dcc + iVar6);
        iVar6 = iVar6 + 1;
        *puVar4 = *puVar2;
        puVar2 = param_4 + iVar6;
      } while (iVar6 < *param_3);
    }
    lVar3 = FUN_00507430(DAT_00782b04 * 0x28 + 0x9967b8);
    if (lVar3 == 1) {
      pcVar5 = s_dbcman___SendData2_BUSY_007be898;
    }
    else {
      lVar3 = FUN_00507230(DAT_00782b04 * 0x28 + 0x9967b8,DAT_00782b04,1,
                           &DAT_00996dc0 + DAT_00782b04 * 0xc0,0x90,
                           &DAT_00996dc0 + DAT_00782b04 * 0xc0,0x90,0);
      if (-1 < lVar3) {
        SignalSema(DAT_00997000);
        return 1;
      }
      pcVar5 = s_sceDbcSendData2__rpc_error_007be8b8;
    }
    FUN_0051d588((int)(u32)pcVar5);
    SignalSema(DAT_00997000);
  }
  else {
    FUN_0051d588(0x7be868,*param_3);
  }
  return 0;
}
// FUN_0051D308 NONMATCHING
u32
FUN_0051d308(u32 param_1,u32 param_2,int *param_3,u8 *param_4,
            u64 param_5)

{
  u8 *puVar1;
  long lVar2;
  u8 *puVar3;
  int iVar4;
  
  if (*param_3 < 0x481) {
    WaitSema(DAT_00997000);
    lVar2 = FUN_00507430(0x996790);
    if (lVar2 == 1) {
      FUN_0051d588(0x7be908);
    }
    else {
      DAT_00996908 = *param_3;
      iVar4 = 0;
      puVar1 = param_4;
      DAT_00996900 = param_1;
      DAT_00996904 = param_2;
      if (0 < *param_3) {
        do {
          puVar3 = (u8 *)(&DAT_0099690c + iVar4);
          iVar4 = iVar4 + 1;
          *puVar3 = *puVar1;
          puVar1 = param_4 + iVar4;
        } while (iVar4 < *param_3);
      }
      lVar2 = FUN_00507230(0x996790,0xffffffff8000131c,1,0x996900,0x490,0x996900,0x490,param_5);
      if (-1 < lVar2) {
        SignalSema(DAT_00997000);
        return 1;
      }
    }
    SignalSema(DAT_00997000);
  }
  else {
    FUN_0051d588(0x7be8d8,*param_3);
  }
  return 0;
}
// FUN_0051D460 NONMATCHING
int FUN_0051d460(u32 param_1,u32 param_2,int *param_3,int param_4)

{
  u32 *puVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  
  WaitSema(DAT_00997000);
  DAT_00996848 = *param_3;
  DAT_00996840 = param_1;
  DAT_00996844 = param_2;
  lVar3 = FUN_00507230(0x996740,0xffffffff8000131a,0,0x996840,0x90,0x996840,0x90,0);
  if (lVar3 < 0) {
    FUN_0051d588(0x7be928);
    SignalSema(DAT_00997000);
    iVar2 = 0;
  }
  else {
    if (-1 < DAT_009968cc) {
      *param_3 = DAT_00996848;
      if (0 < DAT_00996848) {
        puVar1 = &DAT_0099684c;
        iVar2 = 0;
        do {
          iVar4 = iVar2 + 1;
          *(u8 *)(param_4 + iVar2) = *(u8 *)puVar1;
          puVar1 = (u32 *)((int)&DAT_0099684c + iVar2 + 1);
          iVar2 = iVar4;
        } while (iVar4 < DAT_00996848);
      }
    }
    iVar2 = DAT_009968cc;
    SignalSema(DAT_00997000);
  }
  return iVar2;
}
// FUN_0051D588 NONMATCHING
void FUN_0051d588(int param_1,...)

{
  return;
}
// FUN_0051D5B0 NONMATCHING
u32 FUN_0051d5b0(long param_1,int param_2,int param_3)

{
  u32 *puVar1;
  int iVar2;
  u32 uVar3;
  
  DAT_00782b24 = param_2 + 1;
  DAT_00782b28 = param_3;
  if (param_1 == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    register0x00000020 = (u32)((u32 *)param_1);
    puVar1 = (u32 *)(ram0x00782b18);
    *ram0x00782b18 = 0x80005010;
    DAT_00782b30 = 0x1c0000;
    DAT_00782b2c = 0x1baff0;
    if (DAT_00782b28 != 0) {
      DAT_00782b30 = 0x200000;
      DAT_00782b2c = 0x1faff0;
    }
    puVar1[1] = DAT_00782b2c;
    iVar2 = DAT_00782b24;
    DAT_00782b38 = 0x5010;
    DAT_00782b1c = (u32)(puVar1);
    uVar3 = 0;
    DAT_00782b3c = DAT_00782b2c;
    puVar1[2] = 0;
    DAT_00782b20 = (u32)(puVar1 + iVar2 * 3 + -3);
  }
  return uVar3;
}
// FUN_0051D6F8 NONMATCHING
u32 FUN_0051d6f8(int param_1)

{
  u32 *puVar1;
  u32 uVar2;
  u32 uVar3;
  u32 *puVar4;
  u32 uVar5;
  int iVar6;
  u32 *puVar7;
  u32 *puVar8;
  int iVar9;
  
  uVar5 = param_1 + 0xfU & 0xfffffff0;
  puVar7 = (u32 *)0x0;
  puVar4 = (u32 *)(ram0x00782b18);
  do {
    puVar1 = puVar4;
    puVar8 = puVar7;
    if ((int)*puVar1 < 0) {
      uVar2 = puVar1[1];
      puVar8 = puVar1;
      if ((uVar2 != uVar5) && (puVar8 = puVar7, uVar5 < uVar2)) {
        iVar6 = 0;
        iVar9 = -1;
        if (0 < DAT_00782b24 + -1) {
          if (*ram0x00782b18 == 0) {
            iVar9 = 0;
          }
          else {
            do {
              iVar6 = iVar6 + 1;
              iVar9 = -1;
              if (DAT_00782b24 + -1 <= iVar6) break;
              iVar9 = iVar6;
            } while (ram0x00782b18[iVar6 * 3] != 0);
          }
        }
        if (iVar9 < 0) {
          puVar1[1] = uVar5;
          puVar8 = puVar1;
        }
        else {
          uVar3 = puVar1[2];
          puVar7 = (u32 *)(ram0x00782b18 + iVar9 * 3);
          *puVar7 = *puVar1 + uVar5 | 0x80000000;
          puVar7[1] = uVar2 - uVar5;
          puVar7[2] = uVar3;
          puVar1[2] = (u32)puVar7;
          puVar1[1] = uVar5;
          puVar8 = puVar1;
        }
      }
    }
    uVar2 = DAT_00782b38;
  } while ((puVar8 == (u32 *)0x0) &&
          (puVar7 = puVar8, puVar4 = (u32 *)puVar1[2], (u32 *)puVar1[2] != (u32 *)0x0));
  if (puVar8 != (u32 *)0x0) {
    uVar5 = *puVar8;
LAB_0051d8c4:
    *puVar8 = uVar5 & 0x7fffffff;
    uVar5 = (uVar5 & 0x7fffffff) + puVar8[1];
    if (DAT_00782b38 < uVar5) {
      DAT_00782b3c = DAT_00782b30 - uVar5;
      DAT_00782b38 = uVar5;
    }
    return *puVar8;
  }
  if (uVar5 <= DAT_00782b3c) {
    iVar6 = 0;
    iVar9 = -1;
    if (0 < DAT_00782b24 + -1) {
      if (*ram0x00782b18 == 0) {
        iVar9 = 0;
      }
      else {
        do {
          iVar6 = iVar6 + 1;
          iVar9 = -1;
          if (DAT_00782b24 + -1 <= iVar6) break;
          iVar9 = iVar6;
        } while (ram0x00782b18[iVar6 * 3] != 0);
      }
    }
    if (-1 < iVar9) {
      puVar8 = (u32 *)(ram0x00782b18 + iVar9 * 3);
      puVar8[2] = 0;
      *puVar8 = uVar2;
      puVar8[1] = uVar5;
      puVar1[2] = (u32)puVar8;
      uVar5 = *puVar8;
      goto LAB_0051d8c4;
    }
  }
  return 0xffffffff;
}
// FUN_0051DA48
asm u64 FUN_0051da48(void)
{
  .set noreorder
  jr $ra
  daddu $v0, $zero, $zero
}
// FUN_0051DA50 NONMATCHING
u64 FUN_0051da50(u64 param_1)

{
  u64 uVar1;
  
  FUN_00512868();
  uVar1 = FUN_00512d48(param_1);
  FUN_005129c0(1,0x8010,0x980,0x3fff);
  FUN_005129c0(1,0x8010,0xa80,0x3fff);
  FUN_005129c0(1,0x8010,0x981,0);
  FUN_005129c0(1,0x8010,0xa81,0);
  return uVar1;
}
// FUN_0051DAE0 NONMATCHING
u64 FUN_0051dae0(void)

{
  FUN_00512e48();
  return 0;
}
// FUN_0051DB00 NONMATCHING
void FUN_0051db00(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
                 u32 param_5)

{
  FUN_00521408(0x782b80,0,0x40);
  DAT_00782b80 = 0;
  DAT_00782b84 = 2;
  DAT_00782b88 = param_1;
  DAT_00782b8c = param_2;
  DAT_00782b90 = param_3;
  DAT_00782b94 = param_4;
  DAT_00782b98 = param_5;
  FUN_005129c0(1,0x90f0,0x782b80,0x40);
  return;
}
// FUN_0051DBC0 NONMATCHING
void FUN_0051dbc0(u32 param_1,u32 param_2,u32 param_3,u32 param_4)

{
  FUN_00521408(0x782b80,0,0x40);
  DAT_00782b80 = 0;
  DAT_00782b84 = 10;
  DAT_00782b88 = param_1;
  DAT_00782b8c = param_2;
  DAT_00782b90 = param_3;
  DAT_00782b94 = param_4;
  FUN_005129c0(1,0x90f0,0x782b80,0x40);
  return;
}
// FUN_0051DC70 NONMATCHING
void FUN_0051dc70(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
                 u32 param_5,u32 param_6)

{
  FUN_00521408(0x782bc0,0,0x40);
  DAT_00782bc0 = 0x1000000;
  DAT_00782bc4 = 0;
  DAT_00782bc8 = param_1;
  DAT_00782bcc = param_2;
  DAT_00782bd0 = param_3;
  DAT_00782bd4 = param_4;
  DAT_00782bd8 = param_5;
  DAT_00782bdc = param_6;
  FUN_005129c0(1,0x90f0,0x782bc0,0x40);
  return;
}
// FUN_0051DD48 NONMATCHING
void FUN_0051dd48(u32 param_1,u32 param_2)

{
  FUN_00521408(0x782bc0,0,0x40);
  DAT_00782bc0 = 0x1000000;
  DAT_00782bc4 = 1;
  DAT_00782bc8 = param_1;
  DAT_00782bcc = param_2;
  FUN_005129c0(1,0x90f0,0x782bc0,0x40);
  return;
}
// FUN_0051DDF0 NONMATCHING
void FUN_0051ddf0(u32 param_1,u32 param_2,u32 param_3,u32 param_4)

{
  FUN_00521408(0x782c00,0,0x40);
  DAT_00782c00 = 0x4000000;
  DAT_00782c04 = 0;
  DAT_00782c08 = param_1;
  DAT_00782c0c = param_2;
  DAT_00782c10 = param_3;
  DAT_00782c14 = param_4;
  FUN_005129c0(1,0x90f0,0x782c00,0x40);
  return;
}
// FUN_0051DEB0 NONMATCHING
void FUN_0051deb0(u32 param_1,u32 param_2)

{
  FUN_00521408(0x782c00,0,0x40);
  DAT_00782c00 = 0x4000000;
  DAT_00782c04 = 1;
  DAT_00782c08 = param_1;
  DAT_00782c0c = param_2;
  FUN_005129c0(1,0x90f0,0x782c00,0x40);
  return;
}
// FUN_0051DF58 NONMATCHING
void FUN_0051df58(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
                 u32 param_5)

{
  FUN_00521408(0x782c00,0,0x40);
  DAT_00782c00 = 0x4000000;
  DAT_00782c04 = 2;
  DAT_00782c08 = param_1;
  DAT_00782c0c = param_2;
  DAT_00782c10 = param_3;
  DAT_00782c14 = param_4;
  DAT_00782c18 = param_5;
  FUN_005129c0(1,0x90f0,0x782c00,0x40);
  return;
}
// FUN_0051E028 NONMATCHING
void FUN_0051e028(u32 param_1,u32 param_2,u32 param_3)

{
  FUN_00521408(0x782c00,0,0x40);
  DAT_00782c00 = 0x4000000;
  DAT_00782c04 = 3;
  DAT_00782c08 = param_1;
  DAT_00782c0c = param_2;
  DAT_00782c10 = param_3;
  FUN_005129c0(1,0x90f0,0x782c00,0x40);
  return;
}
// FUN_0051E0E0
asm int FUN_0051e0e0(int param_1)
{
  .set noreorder
  bltzl $a0, 1f
  subu $a0, $zero, $a0
1:
  jr $ra
  daddu $v0, $a0, $zero
}
// FUN_0051E0F0 NONMATCHING
u32 FUN_0051e0f0(u64 param_1)

{
  u32 uVar1;
  
  uVar1 = FUN_00525c50(param_1,0,10);
  return uVar1;
}
// FUN_0051E118 NONMATCHING
void FUN_0051e118(u8 *param_1,int param_2)

{
  while (param_2 = param_2 + -1, param_2 != -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  return;
}
// FUN_0051E150 NONMATCHING: recovered forwarding call; MWCC O2 emits a call/return sequence (48 bytes) instead of the retail 40-byte tail transfer.
void FUN_0051e150(int param_1,int param_2)
{
  FUN_0051e178((u64)(u32)PTR_DAT_00782f30,param_1,param_2);
}
// FUN_0051E178 NONMATCHING
long FUN_0051e178(u64 param_1,int param_2,int param_3)

{
  long lVar1;
  long lVar2;
  u32 uVar3;
  u32 *puVar4;
  u32 *puVar5;
  
  lVar1 = (long)(FUN_005209c0(param_1,param_2 * param_3));
  lVar2 = 0;
  if (lVar1 != 0) {
    puVar5 = (u32 *)lVar1;
    uVar3 = (puVar5[-1] & 0xfffffffc) - 4;
    lVar2 = lVar1;
    if (uVar3 < 0x25) {
      puVar4 = puVar5;
      if (0x13 < uVar3) {
        *puVar5 = 0;
        puVar4 = puVar5 + 2;
        puVar5[1] = 0;
        if (0x1b < uVar3) {
          puVar5[2] = 0;
          puVar5[3] = 0;
          puVar4 = puVar5 + 4;
          if (0x23 < uVar3) {
            puVar5[4] = 0;
            puVar4 = puVar5 + 6;
            puVar5[5] = 0;
          }
        }
      }
      *puVar4 = 0;
      puVar4[2] = 0;
      puVar4[1] = 0;
    }
    else {
      FUN_00521408(lVar1,0,uVar3);
    }
  }
  return lVar2;
}
// FUN_0051E280 NONMATCHING
int FUN_0051e280(u64 param_1,int param_2)

{
  u32 uVar1;
  u32 uVar2;
  long lVar3;
  int iVar4;
  u32 *puVar5;
  u32 *puVar6;
  u32 *puVar7;
  u32 *puVar8;
  u32 uVar9;
  int iVar10;
  u32 uVar11;
  u32 *puVar12;
  int iVar13;
  u32 *puVar14;
  int iVar15;
  
  iVar15 = 0;
  iVar4 = (int)param_1;
  if (*(int *)(param_2 + 0x10) <= *(int *)(iVar4 + 0x10)) {
    iVar13 = *(int *)(param_2 + 0x10) + -1;
    puVar6 = (u32 *)(param_2 + 0x14);
    puVar14 = (u32 *)(iVar4 + 0x14);
    puVar12 = puVar6 + iVar13;
    puVar5 = puVar14 + iVar13;
    uVar1 = *puVar5;
    iVar15 = (int)uVar1 / (int)(*puVar12 + 1);
    if (*puVar12 + 1 == 0) {
      trap(7);
    }
    if (iVar15 != 0) {
      iVar10 = 0;
      uVar11 = 0;
      puVar7 = puVar6;
      puVar8 = puVar14;
      do {
        uVar9 = *puVar7;
        uVar2 = *puVar8;
        puVar7 = puVar7 + 1;
        uVar11 = (uVar9 & 0xffff) * iVar15 + uVar11;
        uVar9 = (uVar9 >> 0x10) * iVar15 + (uVar11 >> 0x10);
        iVar10 = ((uVar2 & 0xffff) - (uVar11 & 0xffff)) + iVar10;
        *(short *)puVar8 = (short)iVar10;
        iVar10 = ((uVar2 >> 0x10) - (uVar9 & 0xffff)) + (iVar10 >> 0x10);
        uVar11 = uVar9 >> 0x10;
        *(short *)((int)puVar8 + 2) = (short)iVar10;
        iVar10 = iVar10 >> 0x10;
        puVar8 = puVar8 + 1;
      } while (puVar7 <= puVar12);
      if (uVar1 == 0) {
        if (puVar14 < puVar5 + -1) {
          if (puVar5[-1] == 0) {
            puVar5 = puVar5 + -2;
            do {
              iVar13 = iVar13 + -1;
              if (puVar5 <= puVar14) break;
              uVar1 = *puVar5;
              puVar5 = puVar5 + -1;
            } while (uVar1 == 0);
            *(int *)(iVar4 + 0x10) = iVar13;
          }
          else {
            *(int *)(iVar4 + 0x10) = iVar13;
          }
        }
        else {
          *(int *)(iVar4 + 0x10) = iVar13;
        }
      }
    }
    lVar3 = FUN_00521e70(param_1);
    if (-1 < lVar3) {
      iVar15 = iVar15 + 1;
      iVar10 = 0;
      puVar5 = puVar14;
      do {
        uVar1 = *puVar6;
        uVar11 = *puVar5;
        puVar6 = puVar6 + 1;
        iVar10 = ((uVar11 & 0xffff) - (uVar1 & 0xffff)) + iVar10;
        *(short *)puVar5 = (short)iVar10;
        iVar10 = ((uVar11 >> 0x10) - (uVar1 >> 0x10)) + (iVar10 >> 0x10);
        *(short *)((int)puVar5 + 2) = (short)iVar10;
        iVar10 = iVar10 >> 0x10;
        puVar5 = puVar5 + 1;
      } while (puVar6 <= puVar12);
      puVar5 = puVar14 + iVar13;
      if (*puVar5 == 0) {
        if (puVar14 < puVar5 + -1) {
          if (puVar5[-1] == 0) {
            for (puVar5 = puVar5 + -2; (iVar13 = iVar13 + -1, puVar14 < puVar5 && (*puVar5 == 0));
                puVar5 = puVar5 + -1) {
            }
            *(int *)(iVar4 + 0x10) = iVar13;
          }
          else {
            *(int *)(iVar4 + 0x10) = iVar13;
          }
        }
        else {
          *(int *)(iVar4 + 0x10) = iVar13;
        }
      }
    }
  }
  return iVar15;
}
// FUN_0051E4B0 NONMATCHING
char * FUN_0051e4b0(u64 param_1,u32 param_2,u32 param_3,u32 param_4,int *param_5,
                   u32 *param_6,int *param_7)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  u64 uVar5;
  u64 uVar6;
  u64 uVar7;
  u32 uVar8;
  long lVar9;
  u64 uVar10;
  char cVar11;
  int iVar12;
  u32 uVar13;
  u32 uVar14;
  int iVar15;
  u64 *puVar16;
  u32 uVar17;
  int iVar18;
  char *pcVar19;
  char *pcVar20;
  char *pcVar21;
  int iStack_b0;
  int iStack_ac;
  u32 uStack_a8;
  u32 uStack_a4;
  int *piStack_a0;
  int *piStack_9c;
  int iStack_98;
  int iStack_94;
  u32 uStack_90;
  u32 uStack_8c;
  u32 uStack_88;
  u32 uStack_84;
  u32 uStack_80;
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  u32 uStack_70;
  int iStack_6c;
  int iStack_68;
  int iStack_64;
  int iStack_60;
  
  iVar3 = (int)param_1;
  iVar15 = *(int *)(iVar3 + 0x40);
  iStack_68 = 0;
  uStack_a8 = param_3;
  uStack_a4 = param_4;
  piStack_a0 = param_5;
  piStack_9c = param_7;
  if (iVar15 != 0) {
    *(u32 *)(iVar15 + 4) = *(u32 *)(iVar3 + 0x44);
    *(int *)(iVar15 + 8) = 1 << (*(u32 *)(iVar3 + 0x44) & 0x1f);
    FUN_00521620(param_1,iVar15);
    *(u32 *)(iVar3 + 0x40) = 0;
  }
  uVar13 = (u32)(int)(param_2 >> 0x20);
  if ((long)uVar13 < 0) {
    *param_6 = 1;
    param_2 = param_2 & 0xffffffff | (uVar13 & 0x7fffffff) << 0x20;
  }
  else {
    *param_6 = 0;
  }
  uVar14 = (u32)(param_2 >> 0x20);
  if ((uVar14 & 0x7ff00000) == 0x7ff00000) {
    *piStack_a0 = 9999;
    if ((param_2 & 0xfffffffffffff) == 0) {
      pcVar19 = s_Infinity_007beac8;
    }
    else {
      pcVar19 = (char *)0x7bead8;
    }
    if (piStack_9c == (int *)0x0) {
      return pcVar19;
    }
    pcVar21 = pcVar19 + 8;
    if (pcVar19[3] == '\0') {
      pcVar21 = pcVar19 + 3;
    }
    *piStack_9c = (int)pcVar21;
    return pcVar19;
  }
  lVar4 = FUN_005316d0(param_2,0);
  if (lVar4 == 0) {
    *piStack_a0 = 1;
    if (piStack_9c == (int *)0x0) {
      return (char *)&DAT_007beae0;
    }
    *piStack_9c = (int)&DAT_007beae1;
    return (char *)&DAT_007beae0;
  }
  uVar5 = FUN_005222c0(param_1,param_2,&iStack_b0,&iStack_ac);
  iVar15 = iStack_ac;
  uVar17 = uVar14 >> 0x14 & 0x7ff;
  if (uVar17 == 0) {
    iVar12 = iStack_ac + iStack_b0;
    iVar18 = iVar12 + 0x432;
    if (iVar18 < 0x21) {
      uVar14 = (u32)param_2 << (-iVar18 & 0x1fU);
    }
    else {
      uVar14 = uVar14 << (-iVar18 & 0x1fU) | (u32)param_2 >> (iVar12 + 0x412U & 0x1f);
    }
    uVar13 = FUN_00531720(uVar14);
    if ((int)uVar14 < 0) {
      uVar13 = FUN_00531170(uVar13,0x41f0000000000000);
    }
    iStack_6c = 1;
    uVar17 = iVar12 - 1;
    uVar13 = uVar13 & 0xffffffff | (long)((int)(uVar13 >> 0x20) + -0x1f00000) << 0x20;
  }
  else {
    iStack_6c = 0;
    uVar17 = uVar17 - 0x3ff;
    uVar13 = param_2 & 0xffffffff |
             ((long)(param_2 & 0xffffffff | ((long)param_2 >> 0x20 & 0xfffffU) << 0x20) >> 0x20 |
             0x3ff00000U) << 0x20;
  }
  uVar6 = FUN_005311c8(uVar13,0x3ff8000000000000);
  uVar6 = FUN_00531230(uVar6,DAT_007beae8);
  uVar6 = FUN_00531170(uVar6,DAT_007beaf0);
  uVar7 = FUN_00531720(uVar17);
  uVar7 = FUN_00531230(uVar7,DAT_007beaf8);
  uVar6 = FUN_00531170(uVar6,uVar7);
  uStack_84 = FUN_005317d0(uVar6);
  lVar4 = FUN_005316d0(uVar6,0);
  if (lVar4 < 0) {
    uVar7 = FUN_00531720(uStack_84);
    lVar4 = FUN_005316d0(uVar6,uVar7);
    if (lVar4 != 0) {
      uStack_84 = uStack_84 - 1;
    }
  }
  iStack_7c = 1;
  if (uStack_84 < 0x17) {
    iStack_7c = 0;
    lVar4 = FUN_005316d0(param_2,*(u64 *)(&DAT_007beb78 + uStack_84 * 8));
    if (lVar4 < 0) {
      uStack_84 = uStack_84 - 1;
    }
  }
  iStack_74 = (iVar15 - uVar17) + -1;
  if (iStack_74 < 0) {
    iStack_98 = -iStack_74;
    iStack_74 = 0;
  }
  else {
    iStack_98 = 0;
  }
  if ((int)uStack_84 < 0) {
    uStack_70 = 0;
    iStack_98 = iStack_98 - uStack_84;
    iStack_94 = -uStack_84;
  }
  else {
    iStack_94 = 0;
    iStack_74 = iStack_74 + uStack_84;
    uStack_70 = uStack_84;
  }
  if (9 < uStack_a8) {
    uStack_a8 = 0;
  }
  bVar1 = 5 < (int)uStack_a8;
  if (bVar1) {
    uStack_a8 = uStack_a8 - 4;
  }
  uStack_88 = 0xffffffff;
  uStack_90 = 0xffffffff;
  iStack_78 = 1;
  uVar14 = uStack_a4;
  switch(uStack_a8) {
  case 0:
  case 1:
    uStack_a4 = 0;
    uVar17 = 0x12;
    uVar14 = uStack_a4;
    break;
  case 2:
    iStack_78 = 0;
  case 4:
    uStack_90 = 1;
    uVar17 = uStack_90;
    uVar14 = uStack_90;
    uStack_88 = uStack_90;
    if (0 < (int)uStack_a4) {
      uVar17 = uStack_a4;
      uVar14 = uStack_a4;
      uStack_90 = uStack_a4;
      uStack_88 = uStack_a4;
    }
    break;
  case 3:
    iStack_78 = 0;
  case 5:
    uStack_88 = uStack_a4 + uStack_84;
    uStack_90 = uStack_88 + 1;
    uVar17 = uStack_90;
    if ((int)uStack_90 < 1) {
      uVar17 = 1;
    }
  }
  uStack_a4 = uVar14;
  *(u32 *)(iVar3 + 0x44) = 0;
  iVar15 = 4;
  if (0x17 < uVar17) {
    iVar12 = 0;
    do {
      iVar15 = iVar15 * 2;
      iVar12 = iVar12 + 1;
    } while (iVar15 + 0x14U <= uVar17);
    *(int *)(iVar3 + 0x44) = iVar12;
  }
  pcVar19 = (char *)FUN_00521578(param_1,*(u32 *)(iVar3 + 0x44));
  *(char **)(iVar3 + 0x40) = pcVar19;
  if ((0xe < uStack_90) || (bVar1)) {
LAB_0051ea44:
    if ((iStack_b0 < 0) || (0xe < (int)uStack_84)) {
      iStack_68 = 0;
      iStack_64 = 0;
      bVar1 = 1 < (int)uStack_a8;
      iVar15 = iStack_98;
      iVar3 = iStack_94;
      if (iStack_78 != 0) {
        if (bVar1) {
          iVar12 = uStack_90 - 1;
          iVar3 = iStack_94 - iVar12;
          if (iStack_94 < iVar12) {
            iVar12 = iVar12 - iStack_94;
            iStack_94 = iStack_94 + iVar12;
            iVar3 = 0;
            uStack_70 = uStack_70 + iVar12;
          }
          uVar14 = uStack_90;
          if ((int)uStack_90 < 0) {
            uVar14 = 0;
            iVar15 = iStack_98 - uStack_90;
          }
        }
        else {
          uVar14 = iStack_b0 + 0x433;
          if (iStack_6c == 0) {
            uVar14 = 0x36 - iStack_ac;
          }
        }
        iStack_74 = iStack_74 + uVar14;
        iStack_64 = FUN_005219c8(param_1,1);
        iStack_98 = iStack_98 + uVar14;
      }
      if ((0 < iVar15) && (0 < iStack_74)) {
        iVar12 = iStack_74;
        if (iVar15 < iStack_74) {
          iVar12 = iVar15;
        }
        iStack_74 = iStack_74 - iVar12;
        iStack_98 = iStack_98 - iVar12;
        iVar15 = iVar15 - iVar12;
      }
      if (0 < iStack_94) {
        iVar12 = iStack_94;
        if (iStack_78 != 0) {
          if (0 < iVar3) {
            iStack_64 = FUN_00521c08(param_1,iStack_64,iVar3);
            uVar6 = FUN_00521a00(param_1,iStack_64,uVar5);
            FUN_00521620(param_1,uVar5);
            uVar5 = uVar6;
          }
          iVar12 = iStack_94 - iVar3;
          if (iVar12 == 0) goto LAB_0051ed8c;
        }
        uVar5 = FUN_00521c08(param_1,uVar5,iVar12);
      }
LAB_0051ed8c:
      iStack_60 = FUN_005219c8(param_1,1);
      if (0 < (int)uStack_70) {
        iStack_60 = FUN_00521c08(param_1,iStack_60,uStack_70);
      }
      bVar2 = false;
      if (((!bVar1) && ((param_2 & 0xfffffffffffff) == 0)) &&
         (((long)param_2 >> 0x20 & 0x7ff00000U) != 0)) {
        bVar2 = true;
        iStack_98 = iStack_98 + 1;
        iStack_74 = iStack_74 + 1;
      }
      if (uStack_70 == 0) {
        uVar14 = iStack_74 + 1;
      }
      else {
        iVar3 = FUN_00521888(*(u32 *)(*(int *)(iStack_60 + 0x10) * 4 + iStack_60 + 0x10));
        uVar14 = iStack_74 - iVar3;
      }
      iVar3 = 0;
      if ((uVar14 & 0x1f) != 0) {
        iVar3 = 0x20 - (uVar14 & 0x1f);
      }
      if (iVar3 < 5) {
        if (iVar3 < 4) {
          iVar3 = iVar3 + 0x1c;
          goto LAB_0051ee60;
        }
      }
      else {
        iVar3 = iVar3 + -4;
LAB_0051ee60:
        iStack_74 = iStack_74 + iVar3;
        iStack_98 = iStack_98 + iVar3;
        iVar15 = iVar15 + iVar3;
      }
      if (0 < iStack_98) {
        uVar5 = FUN_00521d10(param_1,uVar5,iStack_98);
      }
      if (0 < iStack_74) {
        iStack_60 = FUN_00521d10(param_1,iStack_60,iStack_74);
      }
      if ((iStack_7c != 0) && (lVar4 = FUN_00521e70(uVar5,iStack_60), lVar4 < 0)) {
        uVar5 = FUN_00521650(param_1,uVar5,10,0);
        uStack_84 = uStack_84 - 1;
        if (iStack_78 != 0) {
          iStack_64 = FUN_00521650(param_1,iStack_64,10,0);
        }
        uStack_90 = uStack_88;
      }
      if ((0 < (int)uStack_90) || ((int)uStack_a8 < 3)) {
        iVar3 = 1;
        pcVar21 = pcVar19;
        if (iStack_78 != 0) {
          if (0 < iVar15) {
            iStack_64 = FUN_00521d10(param_1,iStack_64,iVar15);
          }
          iStack_68 = iStack_64;
          if (bVar2) {
            iStack_64 = FUN_00521578(param_1,*(u32 *)(iStack_64 + 4));
            FUN_00521250(iStack_64 + 0xc,iStack_68 + 0xc,*(int *)(iStack_68 + 0x10) * 4 + 8);
            iStack_64 = FUN_00521d10(param_1,iStack_64,1);
          }
          uVar14 = 1;
          do {
            iVar15 = FUN_0051e280(uVar5,iStack_60);
            uVar17 = iVar15 + 0x30;
            lVar4 = FUN_00521e70(uVar5,iStack_68);
            uVar6 = FUN_00521ed8(param_1,iStack_60,iStack_64);
            if (*(int *)((int)uVar6 + 0xc) == 0) {
              lVar9 = FUN_00521e70(uVar5,uVar6);
            }
            else {
              lVar9 = 1;
            }
            FUN_00521620(param_1,uVar6);
            if (((lVar9 == 0) && (uStack_a8 == 0)) && ((param_2 & 1) == 0)) {
              if (uVar17 != 0x39) {
                uVar17 = uVar17 + (0 < lVar4);
LAB_0051f05c:
                *pcVar21 = (char)uVar17;
                goto LAB_0051f060;
              }
LAB_0051f06c:
              *pcVar21 = '9';
              goto LAB_0051f078;
            }
            cVar11 = (char)uVar17;
            if ((lVar4 < 0) || (((lVar4 == 0 && (uStack_a8 == 0)) && ((param_2 & 1) == 0)))) {
              if (lVar9 < 1) goto LAB_0051f05c;
              uVar5 = FUN_00521d10(param_1,uVar5,1);
              lVar4 = FUN_00521e70(uVar5,iStack_60);
              if (lVar4 < 1) {
                if (lVar4 != 0) {
                  *pcVar21 = cVar11;
                  goto LAB_0051f060;
                }
                if ((uVar17 & 1) == 0) {
                  *pcVar21 = cVar11;
                  goto LAB_0051f060;
                }
              }
              if (iVar15 + 0x31 == 0x3a) goto LAB_0051f06c;
              *pcVar21 = (char)(iVar15 + 0x31);
              goto LAB_0051f060;
            }
            if (0 < lVar9) {
              if (uVar17 == 0x39) goto LAB_0051f06c;
              *pcVar21 = cVar11 + '\x01';
              goto LAB_0051f060;
            }
            *pcVar21 = cVar11;
            pcVar21 = pcVar21 + 1;
            if (uVar14 == uStack_90) goto LAB_0051f1fc;
            uVar5 = FUN_00521650(param_1,uVar5,10,0);
            if (iStack_68 == iStack_64) {
              iStack_68 = FUN_00521650(param_1,iStack_64,10,0);
              iStack_64 = iStack_68;
            }
            else {
              iStack_68 = FUN_00521650(param_1,iStack_68,10,0);
              iStack_64 = FUN_00521650(param_1,iStack_64,10,0);
            }
            uVar14 = uVar14 + 1;
          } while( true );
        }
        while( true ) {
          iVar15 = FUN_0051e280(uVar5,iStack_60);
          uVar17 = iVar15 + 0x30;
          *pcVar21 = (char)uVar17;
          pcVar21 = pcVar21 + 1;
          if ((int)uStack_90 <= iVar3) break;
          uVar5 = FUN_00521650(param_1,uVar5,10,0);
          iVar3 = iVar3 + 1;
        }
LAB_0051f1fc:
        uVar5 = FUN_00521d10(param_1,uVar5,1);
        lVar4 = FUN_00521e70(uVar5,iStack_60);
        if (lVar4 < 1) {
          if ((lVar4 != 0) || ((uVar17 & 1) == 0)) {
            do {
              pcVar20 = pcVar21;
              pcVar21 = pcVar20 + -1;
            } while (pcVar20[-1] == '0');
            goto LAB_0051ead0;
          }
          pcVar21 = pcVar21 + -1;
        }
        else {
          pcVar21 = pcVar21 + -1;
        }
LAB_0051f078:
        cVar11 = *pcVar21;
        while (cVar11 == '9') {
          if (pcVar21 == pcVar19) {
            uStack_84 = uStack_84 + 1;
            pcVar20 = pcVar19 + 1;
            *pcVar19 = '1';
            goto LAB_0051ead0;
          }
          pcVar21 = pcVar21 + -1;
          cVar11 = *pcVar21;
        }
        *pcVar21 = cVar11 + '\x01';
LAB_0051f060:
        pcVar20 = pcVar21 + 1;
        goto LAB_0051ead0;
      }
      if (-1 < (int)uStack_90) {
        iStack_60 = FUN_00521650(param_1,iStack_60,5,0);
        lVar4 = FUN_00521e70(uVar5,iStack_60);
        goto joined_r0x0051ef4c;
      }
    }
    else {
      uVar6 = *(u64 *)(&DAT_007beb78 + uStack_84 * 8);
      if ((-1 < (int)uStack_a4) || (0 < (int)uStack_90)) {
        uVar14 = 1;
        pcVar20 = pcVar19;
        do {
          uVar7 = FUN_00531480(param_2,uVar6);
          uVar13 = FUN_005317d0(uVar7);
          uVar7 = FUN_00531720(uVar13);
          uVar7 = FUN_00531230(uVar7,uVar6);
          uVar7 = FUN_005311c8(param_2,uVar7);
          *pcVar20 = (char)uVar13 + '0';
          pcVar20 = pcVar20 + 1;
          if (uVar14 == uStack_90) {
            uVar7 = FUN_00531170(uVar7,uVar7);
            lVar4 = FUN_005316d0(uVar6,uVar7);
            if (lVar4 < 0) goto LAB_0051ebdc;
            lVar4 = FUN_005316d0(uVar6,uVar7);
            if ((lVar4 == 0) && ((uVar13 & 1) != 0)) goto LAB_0051ebdc;
            break;
          }
          uVar14 = uVar14 + 1;
          param_2 = FUN_00531230(0x4024000000000000,uVar7);
          lVar4 = FUN_005316d0(param_2,0);
        } while (lVar4 != 0);
        goto LAB_0051eb14;
      }
      iStack_64 = 0;
      iStack_60 = 0;
      if (-1 < (int)uStack_90) {
        uVar6 = FUN_00531230(uVar6,0x4014000000000000);
        lVar4 = FUN_005316d0(param_2,uVar6);
joined_r0x0051ef4c:
        if (0 < lVar4) goto LAB_0051eab8;
      }
    }
LAB_0051eb48:
    uStack_84 = ~uStack_a4;
    pcVar20 = pcVar19;
  }
  else {
    uStack_8c = uStack_90;
    iVar15 = 2;
    uStack_80 = uStack_84;
    if ((int)uStack_84 < 1) {
      uVar14 = -uStack_84;
      uVar13 = param_2;
      if (uVar14 != 0) {
        uVar17 = (int)uVar14 >> 4;
        uVar13 = FUN_00531230(*(u64 *)(&DAT_007beb78 + (uVar14 & 0xf) * 8),param_2);
        if (uVar17 != 0) {
          puVar16 = (u64 *)&DAT_007bec40;
          do {
            if ((uVar17 & 1) != 0) {
              iVar15 = iVar15 + 1;
              uVar13 = FUN_00531230(*puVar16,uVar13);
            }
            uVar17 = (int)uVar17 >> 1;
            puVar16 = puVar16 + 1;
          } while (uVar17 != 0);
        }
      }
    }
    else {
      uVar14 = (int)uStack_84 >> 4;
      uVar6 = *(u64 *)(&DAT_007beb78 + (uStack_84 & 0xf) * 8);
      uVar13 = param_2;
      if ((uVar14 & 0x10) != 0) {
        uVar14 = uVar14 & 0xf;
        iVar15 = 3;
        uVar13 = FUN_00531480(param_2,DAT_007bec60);
      }
      if (uVar14 != 0) {
        puVar16 = (u64 *)&DAT_007bec40;
        do {
          if ((uVar14 & 1) != 0) {
            iVar15 = iVar15 + 1;
            uVar6 = FUN_00531230(uVar6,*puVar16);
          }
          uVar14 = (int)uVar14 >> 1;
          puVar16 = puVar16 + 1;
        } while (uVar14 != 0);
      }
      uVar13 = FUN_00531480(uVar13,uVar6);
    }
    if (((iStack_7c != 0) && (lVar4 = FUN_005316d0(uVar13,0x3ff0000000000000), lVar4 < 0)) &&
       (0 < (int)uStack_90)) {
      if (0 < (int)uStack_88) {
        uStack_90 = uStack_88;
        uVar13 = FUN_00531230(0x4024000000000000,uVar13);
        iVar15 = iVar15 + 1;
        uStack_84 = uStack_84 - 1;
        goto LAB_0051e998;
      }
LAB_0051ea2c:
      uStack_84 = uStack_80;
      uStack_90 = uStack_8c;
      goto LAB_0051ea44;
    }
LAB_0051e998:
    uVar6 = FUN_00531720(iVar15);
    uVar6 = FUN_00531230(uVar6,uVar13);
    uVar8 = FUN_00531170(uVar6,0x401c000000000000);
    uVar8 = uVar8 & 0xffffffff | (long)((int)(uVar8 >> 0x20) + -0x3400000) << 0x20;
    if (uStack_90 != 0) {
      if (iStack_78 != 0) {
        iVar15 = 0;
        uVar6 = FUN_00531480(0x3fe0000000000000,*(u64 *)(uStack_90 * 8 + 0x7beb70));
        uVar6 = FUN_005311c8(uVar6,uVar8);
        pcVar20 = pcVar19;
        while( true ) {
          uVar7 = FUN_005317d0(uVar13);
          uVar10 = FUN_00531720(uVar7);
          uVar10 = FUN_005311c8(uVar13,uVar10);
          *pcVar20 = (char)uVar7 + '0';
          lVar4 = FUN_005316d0(uVar10,uVar6);
          pcVar20 = pcVar20 + 1;
          if (lVar4 < 0) break;
          uVar7 = FUN_005311c8(0x3ff0000000000000,uVar10);
          lVar4 = FUN_005316d0(uVar7,uVar6);
          if (lVar4 < 0) goto LAB_0051ebdc;
          iVar15 = iVar15 + 1;
          if ((int)uStack_90 <= iVar15) goto LAB_0051ea2c;
          uVar6 = FUN_00531230(0x4024000000000000,uVar6);
          uVar13 = FUN_00531230(0x4024000000000000,uVar10);
        }
        goto LAB_0051eb14;
      }
      uVar14 = 1;
      uVar6 = FUN_00531230(*(u64 *)(uStack_90 * 8 + 0x7beb70),uVar8);
      pcVar21 = pcVar19;
      while( true ) {
        uVar7 = FUN_005317d0(uVar13);
        uVar10 = FUN_00531720(uVar7);
        uVar10 = FUN_005311c8(uVar13,uVar10);
        *pcVar21 = (char)uVar7 + '0';
        pcVar20 = pcVar21 + 1;
        if (uVar14 == uStack_90) break;
        uVar14 = uVar14 + 1;
        uVar13 = FUN_00531230(0x4024000000000000,uVar10);
        pcVar21 = pcVar20;
      }
      uVar7 = FUN_00531170(0x3fe0000000000000,uVar6);
      lVar4 = FUN_005316d0(uVar7,uVar10);
      if (lVar4 < 0) {
LAB_0051ebdc:
        pcVar20 = pcVar20 + -1;
        cVar11 = *pcVar20;
        while (cVar11 == '9') {
          if (pcVar20 == pcVar19) {
            uStack_84 = uStack_84 + 1;
            *pcVar19 = '0';
            cVar11 = '0';
            break;
          }
          pcVar20 = pcVar20 + -1;
          cVar11 = *pcVar20;
        }
        *pcVar20 = cVar11 + '\x01';
        pcVar20 = pcVar20 + 1;
        goto LAB_0051eb14;
      }
      uVar6 = FUN_005311c8(0x3fe0000000000000,uVar6);
      lVar4 = FUN_005316d0(uVar10,uVar6);
      if (lVar4 < 0) {
        for (; *pcVar21 == '0'; pcVar21 = pcVar21 + -1) {
        }
        pcVar20 = pcVar21 + 1;
        goto LAB_0051eb14;
      }
      goto LAB_0051ea2c;
    }
    iStack_64 = 0;
    uVar6 = FUN_005311c8(uVar13,0x4014000000000000);
    iStack_60 = 0;
    lVar4 = FUN_005316d0(uVar8,uVar6);
    if (-1 < lVar4) {
      uVar7 = FUN_005311c8(0,uVar8);
      lVar4 = FUN_005316d0(uVar6,uVar7);
      if (-1 < lVar4) goto LAB_0051ea2c;
      goto LAB_0051eb48;
    }
LAB_0051eab8:
    *pcVar19 = '1';
    uStack_84 = uStack_84 + 1;
    pcVar20 = pcVar19 + 1;
  }
LAB_0051ead0:
  FUN_00521620(param_1,iStack_60);
  if (iStack_64 != 0) {
    if ((iStack_68 != 0) && (iStack_68 != iStack_64)) {
      FUN_00521620(param_1,iStack_68);
    }
    FUN_00521620(param_1,iStack_64);
  }
LAB_0051eb14:
  FUN_00521620(param_1,uVar5);
  *pcVar20 = '\0';
  *piStack_a0 = uStack_84 + 1;
  if (piStack_9c != (int *)0x0) {
    *piStack_9c = (int)pcVar20;
  }
  return pcVar19;
}
// FUN_0051F690
asm u8 * FUN_0051f690(void)
{
  .set noreorder
  lui $t7, 0x78
  jr $ra
  lw $v0, 0x2f30($t7)
}
// FUN_0051F6A0 NONMATCHING
u64 FUN_0051f6a0(u64 param_1)

{
  u16 uVar1;
  u8 *puVar2;
  code *pcVar3;
  u64 uVar4;
  long lVar5;
  int *piVar6;
  long extraout_a0;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  
  piVar6 = *(int **)((u8 *)PTR_DAT_00782f30 + 0x148);
  if (piVar6 != (int *)0x0) {
    iVar10 = piVar6[1];
    while( true ) {
      iVar9 = iVar10 + -1;
      if (-1 < iVar9) {
        piVar8 = piVar6 + iVar10 + 1;
        do {
          iVar9 = iVar9 + -1;
          (*(code *)*piVar8)();
          piVar8 = piVar8 + -1;
        } while (-1 < iVar9);
      }
      piVar6 = (int *)*piVar6;
      if (piVar6 == (int *)0x0) break;
      iVar10 = piVar6[1];
    }
  }
  if (*(code **)((u8 *)PTR_DAT_00782f30 + 0x3c) != (code *)0x0) {
    (**(code **)((u8 *)PTR_DAT_00782f30 + 0x3c))();
  }
  thunk_FUN_0050da58(param_1);
  puVar2 = PTR_DAT_00782f30;
  if (extraout_a0 == 0) {
    uVar4 = (int)(FUN_00520410((int)(u32)PTR_DAT_00782f30,(code *)0x51f728));
    return uVar4;
  }
  piVar6 = (int *)extraout_a0;
  if (piVar6[0x15] == 0) {
    piVar6[0x15] = (int)PTR_DAT_00782f30;
    iVar10 = *(int *)(puVar2 + 0x38);
  }
  else {
    iVar10 = *(int *)(piVar6[0x15] + 0x38);
  }
  if (iVar10 == 0) {
    uVar1 = *(u16 *)(piVar6 + 3);
  }
  else {
    uVar1 = *(u16 *)(piVar6 + 3);
  }
  if ((uVar1 & 8) != 0) {
    iVar10 = piVar6[4];
    if (iVar10 != 0) {
      iVar9 = *piVar6;
      iVar7 = 0;
      *piVar6 = iVar10;
      iVar9 = iVar9 - iVar10;
      if ((uVar1 & 3) == 0) {
        iVar7 = piVar6[5];
      }
      piVar6[2] = iVar7;
      if (0 < iVar9) {
        pcVar3 = (code *)piVar6[9];
        while( true ) {
          lVar5 = (*pcVar3)(piVar6[7],iVar10,iVar9);
          iVar9 = iVar9 - (int)lVar5;
          iVar10 = iVar10 + (int)lVar5;
          if (lVar5 < 1) {
            *(u16 *)(piVar6 + 3) = *(u16 *)(piVar6 + 3) | 0x40;
            return 0xffffffffffffffff;
          }
          if (iVar9 < 1) break;
          pcVar3 = (code *)piVar6[9];
        }
      }
    }
  }
  return 0;
}
// FUN_0051F728 NONMATCHING
u64 FUN_0051f728(long param_1)

{
  u16 uVar1;
  u8 *puVar2;
  code *pcVar3;
  u64 uVar4;
  long lVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  puVar2 = PTR_DAT_00782f30;
  if (param_1 == 0) {
    uVar4 = (int)(FUN_00520410((int)(u32)PTR_DAT_00782f30,(code *)0x51f728));
    return uVar4;
  }
  piVar6 = (int *)param_1;
  if (piVar6[0x15] == 0) {
    piVar6[0x15] = (int)PTR_DAT_00782f30;
    iVar9 = *(int *)(puVar2 + 0x38);
  }
  else {
    iVar9 = *(int *)(piVar6[0x15] + 0x38);
  }
  if (iVar9 == 0) {
    FUN_0051fa20(0);
    uVar1 = *(u16 *)(piVar6 + 3);
  }
  else {
    uVar1 = *(u16 *)(piVar6 + 3);
  }
  if ((uVar1 & 8) != 0) {
    iVar9 = piVar6[4];
    if (iVar9 != 0) {
      iVar8 = *piVar6;
      iVar7 = 0;
      *piVar6 = iVar9;
      iVar8 = iVar8 - iVar9;
      if ((uVar1 & 3) == 0) {
        iVar7 = piVar6[5];
      }
      piVar6[2] = iVar7;
      if (0 < iVar8) {
        pcVar3 = (code *)piVar6[9];
        while( true ) {
          lVar5 = (*pcVar3)(piVar6[7],iVar9,iVar8);
          iVar8 = iVar8 - (int)lVar5;
          iVar9 = iVar9 + (int)lVar5;
          if (lVar5 < 1) {
            *(u16 *)(piVar6 + 3) = *(u16 *)(piVar6 + 3) | 0x40;
            return 0xffffffffffffffff;
          }
          if (iVar8 < 1) break;
          pcVar3 = (code *)piVar6[9];
        }
      }
    }
  }
  return 0;
}
// FUN_0051F838 NONMATCHING
void FUN_0051f838(u32 *param_1,u16 param_2,u16 param_3,u32 param_4)

{
  param_1[0x15] = param_4;
  *(u16 *)(param_1 + 3) = param_2;
  *(u16 *)((int)param_1 + 0xe) = param_3;
  param_1[8] = (u32)(FUN_00523c60);
  param_1[9] = (u32)(&LAB_00523cc0);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[10] = (u32)(FUN_00523d40);
  param_1[0xb] = (u32)(&LAB_00523da8);
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = (u32)(param_1);
  return;
}
// FUN_0051F898 NONMATCHING
long FUN_0051f898(u64 param_1,int param_2)

{
  u32 *puVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = (long)(FUN_005209c0(param_1,param_2 * 0x58 + 0xc));
  puVar1 = (u32 *)lVar2;
  lVar3 = 0;
  if (lVar2 != 0) {
    puVar1[1] = param_2;
    *puVar1 = 0;
    puVar1[2] = (u32)(puVar1 + 3);
    FUN_00521408(puVar1 + 3,0,param_2 * 0x58);
    lVar3 = lVar2;
  }
  return lVar3;
}
// FUN_0051F908 NONMATCHING
u32 * FUN_0051f908(u64 param_1)

{
  int iVar1;
  u32 *puVar2;
  u32 *puVar3;
  u32 *puVar4;
  
  puVar3 = (u32 *)param_1;
  if (puVar3[0xe] == 0) {
    FUN_0051fa20(0);
  }
  puVar2 = puVar3 + 0x76;
  do {
    do {
      puVar4 = puVar2;
      iVar1 = puVar4[1];
      puVar2 = (u32 *)puVar4[2];
      while (iVar1 = iVar1 + -1, -1 < iVar1) {
        if (*(short *)(puVar2 + 3) == 0) {
          puVar2[0x15] = (u32)(puVar3);
          *(u16 *)(puVar2 + 3) = 1;
          *puVar2 = 0;
          puVar2[2] = 0;
          *(u16 *)((int)puVar2 + 0xe) = 0xffff;
          puVar2[1] = 0;
          puVar2[4] = 0;
          puVar2[5] = 0;
          puVar2[6] = 0;
          puVar2[0xc] = 0;
          puVar2[0xd] = 0;
          puVar2[0x11] = 0;
          puVar2[0x12] = 0;
          return puVar2;
        }
        puVar2 = puVar2 + 0x16;
      }
      puVar2 = (u32 *)*puVar4;
    } while ((u32 *)*puVar4 != (u32 *)0x0);
    puVar2 = (u32 *)FUN_0051f898(param_1,4);
    *puVar4 = (u32)(puVar2);
  } while (puVar2 != (u32 *)0x0);
  *puVar3 = 0xc;
  return (u32 *)0x0;
}
// FUN_0051FA20 NONMATCHING
u32 FUN_0051fa20(u64 param_1)
{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(u32 *)(iVar1 + 0x1d8) = 0;
  *(u8 **)(iVar1 + 0x3c) = &LAB_0051f9e0;
  *(u32 *)(iVar1 + 0x38) = 1;
  *(int *)(iVar1 + 0x1e0) = iVar1 + 0x1e4;
  *(u32 *)(iVar1 + 0x1dc) = 3;
  FUN_0051f838((u32 *)(iVar1 + 4),4,0,(u32)param_1);
  FUN_0051f838((u32 *)(iVar1 + 8),9,1,(u32)param_1);
  FUN_0051f838((u32 *)(iVar1 + 0xc),10,2,(u32)param_1);
  return 0;
}
// FUN_0051FAA0 NONMATCHING
int FUN_0051faa0(int param_1,long param_2,int param_3,u64 param_4)

{
  u32 uVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  u32 uVar5;
  u32 uVar6;
  
  piVar4 = (int *)param_4;
  uVar1 = param_3 * (int)param_2;
  iVar2 = 0;
  if (uVar1 != 0) {
    uVar5 = piVar4[1];
    if ((int)uVar5 < 0) {
      piVar4[1] = 0;
      uVar5 = 0;
    }
    uVar6 = uVar1;
    if (uVar5 < uVar1) {
      iVar2 = *piVar4;
      while( true ) {
        uVar6 = uVar6 - uVar5;
        FUN_00521250(param_1,iVar2,uVar5);
        param_1 = param_1 + uVar5;
        *piVar4 = *piVar4 + uVar5;
        lVar3 = FUN_00523580(param_4);
        if (lVar3 != 0) break;
        uVar5 = piVar4[1];
        if (uVar6 <= uVar5) goto LAB_0051fb48;
        iVar2 = *piVar4;
      }
      iVar2 = (int)(uVar1 - uVar6) / (int)param_2;
      if (param_2 == 0) {
        trap(7);
      }
    }
    else {
LAB_0051fb48:
      FUN_00521250(param_1,*piVar4,uVar6);
      piVar4[1] = piVar4[1] - uVar6;
      *piVar4 = *piVar4 + uVar6;
      iVar2 = param_3;
    }
  }
  return iVar2;
}
// FUN_0051FBB0 NONMATCHING
void FUN_0051fbb0(u64 param_1,long param_2)

{
  int iVar1;
  bool bVar2;
  u8 *puVar3;
  u32 uVar4;
  u8 *puVar5;
  u8 *puVar6;
  u32 uVar7;
  u32 uVar8;
  u8 **ppuVar9;
  int iVar10;
  
  if (param_2 == 0) {
    return;
  }
  FUN_005214c8();
  iVar10 = (int)param_2;
  puVar3 = (u8 *)(iVar10 + -8);
  uVar7 = *(u32 *)(iVar10 + -4);
  uVar4 = uVar7 & 0xfffffffe;
  puVar6 = puVar3 + uVar4;
  uVar8 = *(u32 *)(puVar6 + 4) & 0xfffffffc;
  if (puVar6 == PTR_DAT_00782f48) {
    uVar4 = uVar4 + uVar8;
    if ((uVar7 & 1) == 0) {
      puVar3 = puVar3 + -*(int *)(iVar10 + -8);
      uVar4 = uVar4 + *(int *)(iVar10 + -8);
      iVar10 = *(int *)(puVar3 + 0xc);
      iVar1 = *(int *)(puVar3 + 8);
      *(int *)(iVar10 + 8) = iVar1;
      *(int *)(iVar1 + 0xc) = iVar10;
    }
    bVar2 = DAT_00783348 <= uVar4;
    PTR_DAT_00782f48 = puVar3;
    *(u32 *)(puVar3 + 4) = uVar4 | 1;
    if (bVar2) {
    }
    goto LAB_0051fc60;
  }
  *(u32 *)(puVar6 + 4) = uVar8;
  bVar2 = false;
  if ((uVar7 & 1) == 0) {
    puVar3 = puVar3 + -*(int *)(iVar10 + -8);
    ppuVar9 = *(u8 ***)(puVar3 + 8);
    uVar4 = uVar4 + *(int *)(iVar10 + -8);
    if (ppuVar9 == &PTR_DAT_00782f48) {
      bVar2 = true;
    }
    else {
      puVar5 = *(u8 **)(puVar3 + 0xc);
      *(u8 ***)(puVar5 + 8) = ppuVar9;
      ppuVar9[3] = puVar5;
    }
  }
  if ((*(u32 *)(puVar6 + uVar8 + 4) & 1) == 0) {
    uVar4 = uVar4 + uVar8;
    if (bVar2) {
      ppuVar9 = *(u8 ***)(puVar6 + 8);
      puVar6 = *(u8 **)(puVar6 + 0xc);
    }
    else {
      ppuVar9 = *(u8 ***)(puVar6 + 8);
      if (ppuVar9 == &PTR_DAT_00782f48) {
        bVar2 = true;
        PTR_PTR_00782f50 = puVar3;
        PTR_PTR_00782f54 = puVar3;
        *(u8 ***)(puVar3 + 0xc) = (u8 **)&PTR_DAT_00782f48;
        *(u8 ***)(puVar3 + 8) = (u8 **)(u32)&PTR_DAT_00782f48;
        goto LAB_0051fcec;
      }
      puVar6 = *(u8 **)(puVar6 + 0xc);
    }
    *(u8 ***)(puVar6 + 8) = ppuVar9;
    ppuVar9[3] = puVar6;
  }
LAB_0051fcec:
  *(u32 *)(puVar3 + 4) = uVar4 | 1;
  *(u32 *)(puVar3 + uVar4) = uVar4;
  if (!bVar2) {
    uVar7 = uVar4 >> 3;
    if (uVar4 < 0x200) {
      puVar5 = (u8 *)(&DAT_00782f40 + uVar7 * 8);
      puVar6 = (&PTR_DAT_00782f48)[uVar7 * 2];
      *(u8 **)(puVar3 + 0xc) = puVar5;
      *(u8 **)(puVar3 + 8) = puVar6;
      *(u8 **)(puVar6 + 0xc) = puVar3;
      DAT_00782f44 = DAT_00782f44 | (u32)(1L << (long)(int)(uVar4 >> 5));
    }
    else {
      uVar8 = uVar4 >> 9;
      if (uVar8 != 0) {
        if (uVar8 < 5) {
          uVar7 = (uVar4 >> 6) + 0x38;
        }
        else {
          uVar7 = uVar8 + 0x5b;
          if (0x14 < uVar8) {
            if (uVar8 < 0x55) {
              uVar7 = (uVar4 >> 0xc) + 0x6e;
            }
            else if (uVar8 < 0x155) {
              uVar7 = (uVar4 >> 0xf) + 0x77;
            }
            else if (uVar8 < 0x555) {
              uVar7 = (uVar4 >> 0x12) + 0x7c;
            }
            else {
              uVar7 = 0x7e;
            }
          }
        }
      }
      puVar5 = (u8 *)(&DAT_00782f40 + uVar7 * 8);
      puVar6 = (&PTR_DAT_00782f48)[uVar7 * 2];
      if (puVar6 == puVar5) {
        DAT_00782f44 = DAT_00782f44 | (u32)(1L << (long)((int)uVar7 >> 2));
      }
      else if (uVar4 < (*(u32 *)(puVar6 + 4) & 0xfffffffc)) {
        for (puVar6 = *(u8 **)(puVar6 + 8); puVar6 != puVar5;
            puVar6 = *(u8 **)(puVar6 + 8)) {
          if ((*(u32 *)(puVar6 + 4) & 0xfffffffc) <= uVar4) {
            puVar5 = *(u8 **)(puVar6 + 0xc);
            goto LAB_0051fdb0;
          }
        }
        puVar5 = *(u8 **)(puVar6 + 0xc);
      }
      else {
        puVar5 = *(u8 **)(puVar6 + 0xc);
      }
LAB_0051fdb0:
      *(u8 **)(puVar3 + 0xc) = puVar5;
      *(u8 **)(puVar3 + 8) = puVar6;
      *(u8 **)(puVar6 + 0xc) = puVar3;
    }
    *(u8 **)(puVar5 + 8) = puVar3;
  }
LAB_0051fc60:
  FUN_00521520(param_1);
  return;
}
// FUN_0051FE90 NONMATCHING
u32 FUN_0051fe90(u64 param_1,u32 param_2)

{
  u32 uVar1;
  u8 *puVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  
  FUN_005214c8();
  uVar1 = *(u32 *)((u8 *)PTR_DAT_00782f48 + 4) & 0xfffffffc;
  lVar5 = (((u32)uVar1 - (param_2 & 0xffffffff)) + 0xfef >> 0xc) - 1;
  if ((0xfff < lVar5 * 0x1000) &&
     (puVar2 = (u8 *)FUN_00523930(param_1,0), puVar2 == (u8 *)PTR_DAT_00782f48 + uVar1)) {
    iVar3 = (int)((u32)(lVar5 << 0x2c) >> 0x20);
    lVar4 = FUN_00523930(param_1,-iVar3);
    if (lVar4 != -1) {
      *(u32 *)((u8 *)PTR_DAT_00782f48 + 4) = uVar1 + (int)lVar5 * -0x1000 | 1;
      DAT_00783370 = DAT_00783370 - iVar3;
      FUN_00521520(param_1,0);
      return 1;
    }
    iVar3 = FUN_00523930(param_1);
    if (0xf < iVar3 - (int)PTR_DAT_00782f48) {
      DAT_00783370 = iVar3 - DAT_00783358;
      *(u32 *)((u8 *)PTR_DAT_00782f48 + 4) = iVar3 - (int)PTR_DAT_00782f48 | 1;
    }
  }
  FUN_00521520(param_1);
  return 0;
}
// FUN_0051FFF0 NONMATCHING
void FUN_0051fff0(int *param_1,u64 param_2,u64 param_3)

{
  long lVar1;
  
  DAT_009acc20 = 0;
  lVar1 = FUN_00503918(param_2,param_3);
  if ((lVar1 == -1) && (DAT_009acc20 != 0)) {
    *param_1 = DAT_009acc20;
  }
  return;
}
// FUN_00520048 NONMATCHING
u32 FUN_00520048(u64 param_1,u32 *param_2)

{
  u32 *puVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  u32 uVar5;
  long lVar6;
  u32 *puVar7;
  u16 uVar8;
  u32 uVar9;
  u32 uVar10;
  int *piVar11;
  u32 uVar12;
  int unaff_s4_lo;
  u32 unaff_s6_lo;
  
  if (param_2[2] == 0) {
    return 0;
  }
  puVar7 = (u32 *)param_1;
  uVar8 = (u16)puVar7[3];
  if (((uVar8 & 8) == 0) || (puVar7[4] == 0)) {
    lVar6 = FUN_005289d0();
    if (lVar6 != 0) {
      return 0xffffffff;
    }
    uVar8 = (u16)puVar7[3];
    piVar11 = (int *)*param_2;
  }
  else {
    piVar11 = (int *)*param_2;
  }
  uVar12 = 0;
  if ((uVar8 & 2) != 0) {
    while( true ) {
      while (uVar12 == 0) {
        unaff_s4_lo = *piVar11;
        puVar1 = (u32 *)(piVar11 + 1);
        piVar11 = piVar11 + 2;
        uVar12 = *puVar1;
      }
      uVar5 = 0x400;
      if (uVar12 < 0x401) {
        uVar5 = uVar12;
      }
      lVar6 = (*(code *)puVar7[9])(puVar7[7],unaff_s4_lo,uVar5);
      iVar4 = (int)lVar6;
      unaff_s4_lo = unaff_s4_lo + iVar4;
      if (lVar6 < 1) break;
      iVar2 = param_2[2];
      uVar12 = uVar12 - iVar4;
      param_2[2] = iVar2 - iVar4;
      if (iVar2 - iVar4 == 0) {
        return 0;
      }
    }
LAB_0052015c:
    uVar8 = (u16)puVar7[3];
LAB_00520160:
    *(u16 *)(puVar7 + 3) = uVar8 | 0x40;
    return 0xffffffff;
  }
  bVar3 = false;
  if ((uVar8 & 1) != 0) {
    do {
      if (uVar12 == 0) {
        bVar3 = false;
        do {
          unaff_s4_lo = *piVar11;
          uVar12 = piVar11[1];
          piVar11 = piVar11 + 2;
        } while (uVar12 == 0);
      }
      if (!bVar3) {
        lVar6 = FUN_005210d8(unaff_s4_lo,10,uVar12);
        uVar5 = uVar12;
        if (lVar6 != 0) {
          uVar5 = (int)lVar6 - unaff_s4_lo;
        }
        unaff_s6_lo = uVar5 + 1;
        bVar3 = true;
      }
      uVar5 = puVar7[5];
      uVar10 = uVar12;
      if (unaff_s6_lo <= uVar12) {
        uVar10 = unaff_s6_lo;
      }
      uVar9 = puVar7[2] + uVar5;
      if ((puVar7[4] < *puVar7) && ((int)uVar9 < (int)uVar10)) {
        FUN_00521300(*puVar7,unaff_s4_lo,uVar9);
        *puVar7 = *puVar7 + uVar9;
        lVar6 = FUN_0051f728(param_1);
        uVar10 = uVar9;
        if (lVar6 != 0) {
          uVar8 = (u16)puVar7[3];
          goto LAB_00520160;
        }
      }
      else if ((int)uVar10 < (int)uVar5) {
        FUN_00521300(*puVar7,unaff_s4_lo,uVar10);
        puVar7[2] = puVar7[2] - uVar10;
        *puVar7 = *puVar7 + uVar10;
      }
      else {
        lVar6 = (*(code *)puVar7[9])(puVar7[7],unaff_s4_lo,uVar5);
        uVar10 = (u32)lVar6;
        if (lVar6 < 1) {
          uVar8 = (u16)puVar7[3];
          goto LAB_00520160;
        }
      }
      unaff_s6_lo = unaff_s6_lo - uVar10;
      if (unaff_s6_lo == 0) {
        lVar6 = FUN_0051f728(param_1);
        bVar3 = false;
        if (lVar6 != 0) goto LAB_0052015c;
        iVar4 = param_2[2];
      }
      else {
        iVar4 = param_2[2];
      }
      unaff_s4_lo = unaff_s4_lo + uVar10;
      uVar12 = uVar12 - uVar10;
      param_2[2] = iVar4 - uVar10;
      if (iVar4 - uVar10 == 0) {
        return 0;
      }
    } while( true );
  }
joined_r0x00520184:
  while (uVar12 == 0) {
    unaff_s4_lo = *piVar11;
    puVar1 = (u32 *)(piVar11 + 1);
    piVar11 = piVar11 + 2;
    uVar12 = *puVar1;
  }
  uVar5 = puVar7[2];
  if ((uVar8 & 0x200) == 0) {
    if ((puVar7[4] < *puVar7) && (uVar5 < uVar12)) {
      FUN_00521300(*puVar7,unaff_s4_lo,uVar5);
      *puVar7 = *puVar7 + uVar5;
      lVar6 = FUN_0051f728(param_1);
      if (lVar6 != 0) {
        uVar8 = (u16)puVar7[3];
        goto LAB_00520160;
      }
      iVar4 = param_2[2];
      goto LAB_005201f0;
    }
    if (puVar7[5] <= uVar12) {
      uVar5 = (*(code *)puVar7[9])(puVar7[7],unaff_s4_lo,puVar7[5]);
      if (0 < (int)uVar5) goto LAB_005201ec;
      uVar8 = (u16)puVar7[3];
      goto LAB_00520160;
    }
    FUN_00521300(*puVar7,unaff_s4_lo,uVar12);
    puVar7[2] = puVar7[2] - uVar12;
    *puVar7 = *puVar7 + uVar12;
    uVar5 = uVar12;
  }
  else {
    if (uVar12 < uVar5) {
      uVar5 = uVar12;
    }
    FUN_00521300(*puVar7,unaff_s4_lo,uVar5);
    puVar7[2] = puVar7[2] - uVar5;
    *puVar7 = *puVar7 + uVar5;
    uVar5 = uVar12;
  }
LAB_005201ec:
  iVar4 = param_2[2];
LAB_005201f0:
  unaff_s4_lo = unaff_s4_lo + uVar5;
  uVar12 = uVar12 - uVar5;
  param_2[2] = iVar4 - uVar5;
  if (iVar4 - uVar5 == 0) {
    return 0;
  }
  uVar8 = (u16)puVar7[3];
  goto joined_r0x00520184;
}
// FUN_00520410 NONMATCHING
u32 FUN_00520410(int param_1,code *param_2)

{
  u32 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  u32 uVar5;
  
  piVar4 = (int *)(param_1 + 0x1d8);
  uVar5 = 0;
  if (piVar4 != (int *)0x0) {
    iVar3 = *(int *)(param_1 + 0x1dc);
    while( true ) {
      iVar2 = piVar4[2];
      while (iVar3 = iVar3 + -1, -1 < iVar3) {
        if (*(short *)(iVar2 + 0xc) != 0) {
          uVar1 = (*param_2)(iVar2);
          uVar5 = uVar5 | uVar1;
        }
        iVar2 = iVar2 + 0x58;
      }
      piVar4 = (int *)*piVar4;
      if (piVar4 == (int *)0x0) break;
      iVar3 = piVar4[1];
    }
  }
  return uVar5;
}
// FUN_005204A0 NONMATCHING
u8 * FUN_005204a0(int param_1,u32 param_2,long param_3)

{
  long lVar1;
  
  if (param_3 != 0) {
    lVar1 = FUN_00524128(param_3,0x7beb60);
    if ((lVar1 != 0) && (lVar1 = FUN_00524128(param_3,0x7beb28), lVar1 != 0)) {
      return (u8 *)0x0;
    }
    *(int *)(param_1 + 0x34) = (int)param_3;
    *(u32 *)(param_1 + 0x30) = param_2;
  }
  return (u8 *)&DAT_007beb60;
}
// FUN_00520528
asm u8 ** FUN_00520528(void)
{
  .set noreorder
  lui $v0, 0x7c
  jr $ra
  addiu $v0, $v0, -0x14d0
}
// FUN_00520538 NONMATCHING
void FUN_00520538(u64 param_1,u64 param_2)

{
  FUN_005204a0((int)(u32)PTR_DAT_00782f30,param_1,param_2);
  return;
}
// FUN_00520560 NONMATCHING
void FUN_00520560(void)

{
  FUN_00520528();
  return;
}
// FUN_00520580 NONMATCHING
void FUN_00520580(int *param_1,u64 param_2,u64 param_3,u64 param_4)

{
  long lVar1;
  
  DAT_009acc20 = 0;
  lVar1 = FUN_00503858(param_2,param_3,param_4);
  if ((lVar1 == -1) && (DAT_009acc20 != 0)) {
    *param_1 = DAT_009acc20;
  }
  return;
}
// FUN_005205D8 NONMATCHING
void FUN_005205d8(int *param_1)

{
  bool bVar1;
  int extraout_v0_hi;
  long lVar2;
  u16 uVar3;
  u8 auStack_90 [4];
  u32 uStack_8c;
  
  uVar3 = *(u16 *)(param_1 + 3);
  if ((uVar3 & 2) != 0) {
    param_1[5] = 1;
    param_1[4] = (int)param_1 + 0x43;
    *param_1 = (int)param_1 + 0x43;
    return;
  }
  if (-1 < *(short *)((int)param_1 + 0xe)) {
    FUN_0051fff0((int *)(u32)param_1[0x15],*(short *)((int)param_1 + 0xe),(u64)(u32)auStack_90);
    if (-1 < extraout_v0_hi) {
      bVar1 = (uStack_8c & 0xf000) == 0x2000;
      if ((uStack_8c & 0xf000) == 0x8000) {
        uVar3 = *(u16 *)(param_1 + 3);
        if ((code *)(u64)param_1[10] != (code *)FUN_00523d40) goto LAB_0052071c;
        param_1[0x13] = 0x400;
        uVar3 = uVar3 | 0x400;
      }
      else {
        uVar3 = *(u16 *)(param_1 + 3);
LAB_0052071c:
        uVar3 = uVar3 | 0x800;
      }
      *(u16 *)(param_1 + 3) = uVar3;
      goto LAB_0052065c;
    }
    uVar3 = *(u16 *)(param_1 + 3);
  }
  bVar1 = false;
  *(u16 *)(param_1 + 3) = uVar3 | 0x800;
LAB_0052065c:
  lVar2 = (long)(FUN_005209c0(param_1[0x15],0x400));
  uVar3 = *(u16 *)(param_1 + 3);
  if (lVar2 == 0) {
    param_1[4] = (int)param_1 + 0x43;
    param_1[5] = 1;
    *(u16 *)(param_1 + 3) = uVar3 | 2;
    *param_1 = (int)param_1 + 0x43;
  }
  else {
    param_1[4] = (int)lVar2;
    *(u8 **)(param_1[0x15] + 0x3c) = &LAB_0051f9e0;
    *(u16 *)(param_1 + 3) = uVar3 | 0x80;
    param_1[5] = 0x400;
    *param_1 = (int)lVar2;
    if ((bVar1) && (lVar2 = FUN_00503910(*(u16 *)((int)param_1 + 0xe)), lVar2 != 0)) {
      *(u16 *)(param_1 + 3) = *(u16 *)(param_1 + 3) | 1;
    }
  }
  return;
}
// FUN_00520728 NONMATCHING: recovered allocator wrapper; MWCC O2 emits a 40-byte call/return sequence rather than retail's 32-byte tail transfer.
void FUN_00520728(int param_1)
{
  FUN_005209c0((u64)(u32)PTR_DAT_00782f30,param_1);
}
// FUN_00520748 NONMATCHING
void FUN_00520748(u64 param_1)

{
  FUN_0051fbb0((u64)(u32)PTR_DAT_00782f30,param_1);
  return;
}
// FUN_00520768 NONMATCHING
void FUN_00520768(u64 param_1,int param_2)

{
  u8 *puVar1;
  u8 *puVar2;
  u8 *puVar3;
  u32 uVar4;
  u8 *puVar5;
  int iVar6;
  u32 uVar7;
  u32 uVar8;
  
  puVar1 = PTR_DAT_00782f48;
  param_2 = param_2 + (int)_DAT_00783350;
  uVar8 = *(u32 *)((u8 *)PTR_DAT_00782f48 + 4) & 0xfffffffc;
  uVar7 = param_2 + 0x10;
  puVar5 = (u8 *)PTR_DAT_00782f48 + uVar8;
  if (DAT_00783358 != 0xffffffff) {
    uVar7 = param_2 + 0x100fU & 0xfffff000;
  }
  puVar3 = (u8 *)FUN_00523930(param_1,uVar7);
  if ((puVar3 != (u8 *)0xffffffff) && ((puVar5 <= puVar3 || (puVar1 == (u8 *)&DAT_00782f40)))) {
    DAT_00783370 = DAT_00783370 + uVar7;
    if ((puVar3 == puVar5) && (((u32)puVar3 & 0xfff) == 0)) {
      *(u32 *)((u8 *)PTR_DAT_00782f48 + 4) = uVar7 + uVar8 | 1;
    }
    else {
      puVar2 = puVar3;
      if (DAT_00783358 != 0xffffffff) {
        DAT_00783370 = (u32)(puVar3 + ((int)DAT_00783370 - (int)puVar5));
        puVar2 = (u8 *)(DAT_00783358);
      }
      DAT_00783358 = (u32)(puVar2);
      if (((u32)(puVar3 + 8) & 0xf) == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = 0x10 - ((u32)(puVar3 + 8) & 0xf);
        puVar3 = puVar3 + iVar6;
      }
      iVar6 = iVar6 + (0x1000 - ((u32)(puVar3 + uVar7) & 0xfff));
      puVar5 = (u8 *)FUN_00523930(param_1,iVar6);
      if (puVar5 == (u8 *)0xffffffff) {
        iVar6 = 0;
        puVar5 = puVar3;
      }
      DAT_00783370 = DAT_00783370 + iVar6;
      PTR_DAT_00782f48 = puVar3;
      *(u32 *)(puVar3 + 4) = (u32)(puVar5 + (iVar6 - (int)puVar3)) | 1;
      if (puVar1 != (u8 *)&DAT_00782f40) {
        if (uVar8 < 0x10) {
          *(u32 *)(puVar3 + 4) = 1;
          return;
        }
        uVar7 = uVar8 - 0xc & 0xfffffff0;
        *(u32 *)(puVar1 + 4) = *(u32 *)(puVar1 + 4) & 1 | uVar7;
        *(u32 *)(puVar1 + uVar7 + 8) = 5;
        *(u32 *)(puVar1 + uVar7 + 4) = 5;
        if (0xf < uVar7) {
          FUN_0051fbb0(param_1,(long)(puVar1 + 8));
        }
      }
    }
    uVar4 = (u32)(int)DAT_00783370;
    if (DAT_00783360 < uVar4) {
      DAT_00783360 = uVar4;
    }
    if (DAT_00783368 < uVar4) {
      DAT_00783368 = uVar4;
    }
  }
  return;
}
// FUN_005209C0 NONMATCHING
u32 * FUN_005209c0(u64 param_1,int param_2)

{
  u8 *puVar1;
  u32 uVar2;
  u32 uVar3;
  int iVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 *puVar8;
  u32 uVar9;
  u8 *puVar10;
  u32 uVar11;
  int iVar12;
  u32 *puVar13;
  u32 *puVar14;
  u32 uVar15;
  
  if (param_2 + 0x13U < 0x1f) {
    uVar15 = 0x10;
  }
  else {
    uVar15 = param_2 + 0x13U & 0xfffffff0;
  }
  FUN_005214c8(param_1);
  puVar13 = (u32 *)PTR_PTR_00782f50;
  if (uVar15 < 0x1f8) {
    puVar14 = *(u32 **)((int)&PTR_DAT_00782f4c + uVar15);
    if (puVar14 == (u32 *)(&DAT_00782f40 + uVar15)) {
      uVar2 = (uVar15 >> 3) + 2;
      goto LAB_00520a7c;
    }
    iVar12 = puVar14[3];
    iVar4 = puVar14[2];
    puVar10 = (u8 *)((int)puVar14 + (puVar14[1] & 0xfffffffc));
    uVar15 = *(u32 *)(puVar10 + 4);
    *(int *)(iVar12 + 8) = iVar4;
    *(int *)(iVar4 + 0xc) = iVar12;
    puVar13 = puVar14;
LAB_00520a44:
    *(u32 *)(puVar10 + 4) = uVar15 | 1;
  }
  else {
    uVar3 = uVar15 >> 9;
    uVar2 = uVar15 >> 3;
    if (uVar3 != 0) {
      if (uVar3 < 5) {
        uVar2 = (uVar15 >> 6) + 0x38;
      }
      else {
        uVar2 = uVar3 + 0x5b;
        if (0x14 < uVar3) {
          if (uVar3 < 0x55) {
            uVar2 = (uVar15 >> 0xc) + 0x6e;
          }
          else if (uVar3 < 0x155) {
            uVar2 = (uVar15 >> 0xf) + 0x77;
          }
          else if (uVar3 < 0x555) {
            uVar2 = (uVar15 >> 0x12) + 0x7c;
          }
          else {
            uVar2 = 0x7e;
          }
        }
      }
    }
    puVar14 = (u32 *)(&PTR_DAT_00782f4c)[uVar2 * 2];
    if (puVar14 == (u32 *)(&DAT_00782f40 + uVar2 * 8)) {
      uVar2 = uVar2 + 1;
    }
    else {
      uVar3 = puVar14[1];
      while( true ) {
        uVar3 = uVar3 & 0xfffffffc;
        uVar5 = (u32)(uVar3 - uVar15);
        if (uVar3 < uVar15) {
          uVar5 = -(u32)(uVar15 - uVar3);
        }
        if (0xf < (long)uVar5) break;
        if (-1 < (long)uVar5) {
          iVar12 = puVar14[3];
          uVar15 = *(u32 *)((int)puVar14 + uVar3 + 4);
          iVar4 = puVar14[2];
          *(int *)(iVar12 + 8) = iVar4;
          *(u32 *)((int)puVar14 + uVar3 + 4) = uVar15 | 1;
          puVar13 = puVar14;
LAB_00520e3c:
          *(int *)(iVar4 + 0xc) = iVar12;
          goto LAB_00520a4c;
        }
        puVar14 = (u32 *)puVar14[3];
        if (puVar14 == (u32 *)(&DAT_00782f40 + uVar2 * 8)) goto LAB_00521028;
        uVar3 = puVar14[1];
      }
      uVar2 = uVar2 - 1;
LAB_00521028:
      uVar2 = uVar2 + 1;
    }
LAB_00520a7c:
    if ((u8 **)PTR_PTR_00782f50 != &PTR_DAT_00782f48) {
      uVar3 = *(u32 *)((u8 *)PTR_PTR_00782f50 + 4);
      uVar6 = uVar3 & 0xfffffffc;
      if (uVar6 < uVar15) {
        uVar5 = -(u32)(uVar15 - uVar6);
      }
      else {
        uVar5 = (u32)(uVar6 - uVar15);
      }
      if (0xf < (long)uVar5) {
        *(u32 *)((u8 *)PTR_PTR_00782f50 + 4) = uVar15 | 1;
        puVar10 = (u8 *)PTR_PTR_00782f50 + uVar15;
        uVar15 = (u32)uVar5;
        PTR_PTR_00782f50 = puVar10;
        PTR_PTR_00782f54 = puVar10;
        *(u8 ***)(puVar10 + 8) = (u8 **)&PTR_DAT_00782f48;
        *(u32 *)(puVar10 + 4) = uVar15 | 1;
        *(u32 *)(puVar10 + uVar15) = uVar15;
LAB_00520b00:
        *(u8 ***)(puVar10 + 0xc) = (u8 **)&PTR_DAT_00782f48;
        goto LAB_00520a4c;
      }
      PTR_PTR_00782f54 = (u8 *)&PTR_DAT_00782f48;
      PTR_PTR_00782f50 = (u8 *)&PTR_DAT_00782f48;
      if (-1 < (long)uVar5) {
        puVar10 = (u8 *)((int)puVar13 + uVar6);
        uVar15 = *(u32 *)(puVar10 + 4);
        goto LAB_00520a44;
      }
      uVar7 = uVar3 >> 3;
      if (uVar6 < 0x200) {
        puVar1 = (u8 *)(&DAT_00782f40 + uVar7 * 8);
        puVar10 = (&PTR_DAT_00782f48)[uVar7 * 2];
        *(u8 **)((int)puVar13 + 0xc) = puVar1;
        *(u8 **)((int)puVar13 + 8) = puVar10;
        *(u32 **)(puVar10 + 0xc) = puVar13;
        DAT_00782f44 = DAT_00782f44 | (u32)(1L << (long)(int)(uVar3 >> 5));
      }
      else {
        uVar11 = uVar3 >> 9;
        if (uVar11 != 0) {
          if (uVar11 < 5) {
            uVar7 = (uVar3 >> 6) + 0x38;
          }
          else {
            uVar7 = uVar11 + 0x5b;
            if (0x14 < uVar11) {
              if (uVar11 < 0x55) {
                uVar7 = (uVar3 >> 0xc) + 0x6e;
              }
              else if (uVar11 < 0x155) {
                uVar7 = (uVar3 >> 0xf) + 0x77;
              }
              else if (uVar11 < 0x555) {
                uVar7 = (uVar3 >> 0x12) + 0x7c;
              }
              else {
                uVar7 = 0x7e;
              }
            }
          }
        }
        puVar1 = (u8 *)(&DAT_00782f40 + uVar7 * 8);
        puVar10 = (&PTR_DAT_00782f48)[uVar7 * 2];
        if (puVar10 == puVar1) {
          DAT_00782f44 = DAT_00782f44 | (u32)(1L << (long)((int)uVar7 >> 2));
        }
        else if (uVar6 < (*(u32 *)(puVar10 + 4) & 0xfffffffc)) {
          for (puVar10 = *(u8 **)(puVar10 + 8); puVar10 != puVar1;
              puVar10 = *(u8 **)(puVar10 + 8)) {
            if ((*(u32 *)(puVar10 + 4) & 0xfffffffc) <= uVar6) {
              puVar1 = *(u8 **)(puVar10 + 0xc);
              goto LAB_00520ef4;
            }
          }
          puVar1 = *(u8 **)(puVar10 + 0xc);
        }
        else {
          puVar1 = *(u8 **)(puVar10 + 0xc);
        }
LAB_00520ef4:
        *(u8 **)((int)puVar13 + 0xc) = puVar1;
        *(u8 **)((int)puVar13 + 8) = puVar10;
        *(u32 **)(puVar10 + 0xc) = puVar13;
      }
      *(u32 **)(puVar1 + 8) = puVar13;
    }
    uVar3 = uVar2 + 3;
    if (-1 < (int)uVar2) {
      uVar3 = uVar2;
    }
    uVar9 = (u32)DAT_00782f44;
    uVar5 = 1L << (long)((int)uVar3 >> 2);
    if (uVar5 <= uVar9) {
      if ((uVar5 & uVar9) == 0) {
        uVar2 = uVar2 & 0xfffffffc;
        do {
          uVar5 = uVar5 << 1;
          uVar2 = uVar2 + 4;
        } while ((uVar5 & uVar9) == 0);
      }
      iVar12 = uVar2 << 3;
      do {
        puVar13 = *(u32 **)((int)&PTR_DAT_00782f4c + iVar12);
        puVar14 = (u32 *)(&DAT_00782f40 + iVar12);
        uVar3 = uVar2;
        while( true ) {
          if (puVar13 != puVar14) {
            uVar6 = puVar13[1];
            while( true ) {
              uVar6 = uVar6 & 0xfffffffc;
              uVar9 = (u32)(uVar6 - uVar15);
              if (uVar6 < uVar15) {
                uVar9 = -(u32)(uVar15 - uVar6);
              }
              if (0xf < (long)uVar9) {
                iVar12 = puVar13[2];
                iVar4 = puVar13[3];
                puVar10 = (u8 *)((int)puVar13 + uVar15);
                puVar13[1] = uVar15 | 1;
                *(int *)(iVar4 + 8) = iVar12;
                *(int *)(iVar12 + 0xc) = iVar4;
                uVar15 = (u32)uVar9;
                PTR_PTR_00782f50 = puVar10;
                PTR_PTR_00782f54 = puVar10;
                *(u8 ***)(puVar10 + 8) = (u8 **)&PTR_DAT_00782f48;
                *(u32 *)(puVar10 + uVar15) = uVar15;
                *(u32 *)(puVar10 + 4) = uVar15 | 1;
                goto LAB_00520b00;
              }
              if (-1 < (long)uVar9) {
                iVar12 = puVar13[3];
                iVar4 = puVar13[2];
                *(u32 *)((int)puVar13 + uVar6 + 4) = *(u32 *)((int)puVar13 + uVar6 + 4) | 1;
                *(int *)(iVar12 + 8) = iVar4;
                goto LAB_00520e3c;
              }
              puVar13 = (u32 *)puVar13[3];
              if (puVar13 == puVar14) break;
              uVar6 = puVar13[1];
            }
          }
          puVar13 = puVar14 + 2;
          if ((int)uVar3 < 0x3f) {
            uVar3 = uVar3 + 1;
            puVar13 = puVar14 + 4;
          }
          puVar14 = puVar13;
          uVar3 = uVar3 + 1;
          if ((uVar3 & 3) == 0) break;
          puVar13 = (u32 *)puVar14[3];
        }
        puVar13 = (u32 *)(&DAT_00782f40 + iVar12);
        do {
          uVar6 = uVar2 & 3;
          uVar2 = uVar2 - 1;
          if (uVar6 == 0) {
            DAT_00782f44 = DAT_00782f44 & ~(u32)uVar5;
            break;
          }
          puVar8 = puVar13 + -2;
          puVar14 = (u32 *)*puVar13;
          puVar13 = puVar8;
        } while (puVar14 == puVar8);
        uVar5 = uVar5 << 1;
        if ((DAT_00782f44 < uVar5) || (uVar5 == 0)) break;
        iVar12 = uVar3 * 8;
        uVar2 = uVar3;
        if ((uVar5 & DAT_00782f44) == 0) {
          do {
            uVar5 = uVar5 << 1;
            uVar2 = uVar2 + 4;
          } while ((uVar5 & DAT_00782f44) == 0);
          iVar12 = uVar2 * 8;
        }
      } while( true );
    }
    uVar2 = *(u32 *)((u8 *)PTR_DAT_00782f48 + 4) & 0xfffffffc;
    if (uVar2 < uVar15) {
      uVar5 = -(u32)(uVar15 - uVar2);
    }
    else {
      uVar5 = (u32)(uVar2 - uVar15);
    }
    if (((*(u32 *)((u8 *)PTR_DAT_00782f48 + 4) & 0xfffffffc) < uVar15) || ((long)uVar5 < 0x10)) {
      FUN_00520768(param_1,uVar15);
      uVar2 = *(u32 *)((u8 *)PTR_DAT_00782f48 + 4) & 0xfffffffc;
      if (uVar2 < uVar15) {
        uVar5 = -(u32)(uVar15 - uVar2);
      }
      else {
        uVar5 = (u32)(uVar2 - uVar15);
      }
      if (((*(u32 *)((u8 *)PTR_DAT_00782f48 + 4) & 0xfffffffc) < uVar15) || ((long)uVar5 < 0x10)) {
        FUN_00521520(param_1);
        return (u32 *)0x0;
      }
    }
    puVar13 = (u32 *)PTR_DAT_00782f48;
    *(u32 *)((u8 *)PTR_DAT_00782f48 + 4) = uVar15 | 1;
    PTR_DAT_00782f48 = (u8 *)PTR_DAT_00782f48 + uVar15;
    *(u32 *)((u8 *)PTR_DAT_00782f48 + 4) = (u32)uVar5 | 1;
  }
LAB_00520a4c:
  FUN_00521520(param_1);
  return puVar13 + 2;
}
// FUN_005210A8 NONMATCHING
u32 FUN_005210a8(u64 param_1,u32 *param_2,long param_3,long param_4)

{
  u32 uVar1;
  u32 auStack_10 [4];
  
  uVar1 = 0;
  if (param_2 == (u32 *)0x0) {
    param_2 = auStack_10;
  }
  if ((param_3 != 0) && (uVar1 = 0xffffffff, param_4 != 0)) {
    *param_2 = (u32)*(u8 *)param_3;
    uVar1 = (u32)(*(u8 *)param_3 != 0);
  }
  return uVar1;
}
// FUN_005210D8 NONMATCHING
u64 FUN_005210d8(u32 param_1,u32 param_2,u32 param_3)
{
  u64 in_t2_udw;
  u64 in_v1_udw;
  u64 in_a0_udw;
  Vec128 auVar1;
  Vec128 auVar2;
  int iVar3;
  u8 (*pauVar4) [16];
  Vec128 auVar5;
  Vec128 auVar6;
  Vec128 auVar7;
  u64 uTmp0, uTmp1, uTmp6;
  
  iVar3 = (int)(param_1 >> 0x20);
  pauVar4 = (u8 (*) [16])param_1;
  if ((0xf < param_3) && ((param_1 & 0xf) == 0)) {
    auVar5._8_8_ = in_t2_udw;
    auVar5._0_8_ = (param_2 & 0xff) * 0x101;
    auVar6._8_8_ = in_v1_udw;
    auVar6._0_8_ = 0x8080808080808080;
    /* emulate _pcpyh: replicate lower 16-bit to all halfwords */
    uTmp0 = (auVar5._0_8_ & 0xFFFF);
    uTmp0 = uTmp0 * 0x0001000100010001ULL; /* use u64 to avoid __int128 */
    auVar5._0_8_ = uTmp0;
    auVar5._8_8_ = uTmp0;
    /* _pcpyld(auVar5,auVar5): lower halves -> same value */
    /* already in auVar5 */
    /* _pcpyld(auVar6,auVar6): same */
    uTmp1 = (auVar6._0_8_ & 0xFFFF);
    uTmp1 = uTmp1 * 0x0001000100010001ULL;
    auVar6._0_8_ = uTmp1;
    auVar6._8_8_ = uTmp1;
    do {
      pauVar4 = (u8 (*) [16])param_1;
      /* _pxor(*pauVar4, auVar5): XOR both halves */
      auVar1._0_8_ = (*(u64 *)pauVar4) ^ auVar5._0_8_;
      auVar1._8_8_ = (*(u64 *)(pauVar4 + 1)) ^ auVar5._8_8_;
      auVar7._8_8_ = in_a0_udw;
      auVar7._0_8_ = 0x101010101010101;
      auVar2._8_8_ = in_a0_udw;
      auVar2._0_8_ = 0x101010101010101;
      /* _pcpyld(auVar7,auVar2): lower halves */
      /* auVar7 already has correct values */
      /* _psubb(auVar1,auVar7): regular subtract for NONMATCHING */
      auVar7._0_8_ = auVar1._0_8_ - auVar7._0_8_;
      auVar7._8_8_ = auVar1._8_8_ - auVar7._8_8_;
      /* _pnot(auVar1): bitwise NOT */
      uTmp0 = ~auVar1._0_8_;
      uTmp6 = ~auVar1._8_8_;
      /* _pand(auVar7, not(auVar1)): AND with NOT */
      auVar7._0_8_ = auVar7._0_8_ & uTmp0;
      auVar7._8_8_ = auVar7._8_8_ & uTmp6;
      /* _pand(auVar7,auVar6) */
      auVar7._0_8_ = auVar7._0_8_ & auVar6._0_8_;
      auVar7._8_8_ = auVar7._8_8_ & auVar6._8_8_;
      /* _pcpyud(auVar7,auVar5): upper halves */
      auVar2._0_8_ = auVar7._8_8_;
      auVar2._8_8_ = auVar5._8_8_;
      if (auVar7._0_8_ != 0 || auVar2._0_8_ != 0) {
        iVar3 = (int)(param_1 >> 0x20);
        goto joined_r0x00521184;
      }
      param_3 = param_3 - 0x10;
      pauVar4 = pauVar4 + 1;
      param_1 = (u32)(int)pauVar4;
    } while (0xf < param_3);
    iVar3 = (int)pauVar4 >> 0x1f;
  }
joined_r0x00521184:
  while( true ) {
    param_3 = param_3 - 1;
    if (param_3 == 0xffffffff) {
      return 0;
    }
    if ((u32)(u8)(*pauVar4)[0] == (param_2 & 0xff)) break;
    pauVar4 = (u8 (*) [16])(*pauVar4 + 1);
    iVar3 = (int)pauVar4 >> 0x1f;
  }
  return CONCAT44(iVar3,pauVar4);
}
// FUN_005211B8 NONMATCHING
int FUN_005211b8(u8 (*param_1) [16],u8 (*param_2) [16],u32 param_3)
{
  u8 (*pauVar1) [16];
  u8 (*pauVar2) [16];
  u32 uVar3;
  u64 in_a3_udw;
  Vec128 auVar4;
  Vec128 auVar5;
  
  if ((0xf < param_3) && ((((u32)param_1 | (u32)param_2) & 0xf) == 0)) {
    do {
      uVar3 = CONCAT71(0,param_3 < 0x20);
      pauVar2 = param_1 + 1;
      /* _pxor(*param_2, *param_1): XOR both halves */
      auVar4._0_8_ = (*(u64 *)param_2) ^ (*(u64 *)param_1);
      auVar4._8_8_ = (*(u64 *)(param_2 + 1)) ^ (*(u64 *)(param_1 + 1));
      pauVar1 = param_2 + 1;
      auVar5._8_8_ = in_a3_udw;
      auVar5._0_8_ = uVar3;
      /* _pcpyud(auVar4,auVar5): upper halves */
      auVar5._0_8_ = auVar4._8_8_;
      /* auVar5._8_8_ stays as in_a3_udw (already the upper) */
      if (auVar5._0_8_ != 0 || auVar4._0_8_ != 0) break;
      param_3 = param_3 - 0x10;
      param_1 = pauVar2;
      param_2 = pauVar1;
    } while (uVar3 == 0);
  }
  while( true ) {
    param_3 = param_3 - 1;
    if (param_3 == 0xffffffff) {
      return 0;
    }
    if ((u32)(u8)(*param_1)[0] != (u32)(u8)(*param_2)[0]) break;
    param_1 = (u8 (*) [16])(*param_1 + 1);
    param_2 = (u8 (*) [16])(*param_2 + 1);
  }
  return (u32)(u8)(*param_1)[0] - (u32)(u8)(*param_2)[0];
}