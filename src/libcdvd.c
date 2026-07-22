#include "mw_harvest_compat.h"
#include "sce/libcdvd.h"
#include "sce/sifrpc.h"

/* auto-extern (generated) */
extern u32 ram0x00782748;
extern code ram0x007827a0;
extern char s_SceSdrCallbackThread_007be4b0[];
extern u32 register0x000001c0;
u32 FUN_005112d0(void);
void FUN_00512f80(void);
u32 FUN_00512640(void);
extern u32 DAT_0078274c;
extern code DAT_00782750;
extern u32 DAT_00782754;
extern u32 DAT_00782788;
extern u32 DAT_0078278c;
extern code DAT_007827a4;
extern code DAT_007827a8;
extern u32* DAT_007827ac;
extern u32* DAT_007827b0;
extern u32* DAT_007827b4;
extern u32 DAT_007827b8;
extern u32 DAT_007827bc;
extern u32 DAT_007827c0;
extern s32 DAT_007827c4;
extern u32 DAT_0096dce4;
extern u32 DAT_0096dd0c;
extern u32 DAT_0096dd10;
extern u32 DAT_0096dd14;
extern u32 DAT_0096dd18;
extern u32 DAT_0096dd1c;
extern u32 DAT_0096dd20;
extern u32 DAT_0096dd94;
extern u32 DAT_0096df00;
extern u32 DAT_0096df04;
extern u32 DAT_0096df08;
extern u32 DAT_0096df0c;
extern u32 DAT_0096df10;
extern u32 DAT_0096df14;
extern u32 DAT_0096df1c;
extern u32 DAT_0096df80;
extern u32 DAT_0096dfc0;
extern u32 DAT_0096dfc4;
extern u32 DAT_0096dfc8;
extern u32 DAT_0096dfcc;
extern u32 DAT_0096e000;
extern u32 DAT_0096e004;
extern u32 DAT_0096e008;
extern u32* DAT_0096e00c;
extern u32 DAT_0096e010;
extern u32 DAT_0096e014;
extern u32 DAT_0096e064;
extern u32 DAT_0096e080;
extern u32 _DAT_0096df0c;
#pragma alias DAT_0096dd10_abs DAT_0096dd10
extern u8 DAT_0096dd10_abs[];
extern u32 DAT_007c0000;
#pragma alias DAT_007c0000_abs DAT_007c0000
extern u8 DAT_007c0000_abs[];

#define SCE_CDVD_RPC_INIT             0x80000592
#define SCE_CDVD_RPC_DISK_READY_OLD   0x8000059A
#define SCE_CDVD_RPC_DISK_READY       0x8000059C
#define SCE_CDVD_RPC_NOWAIT           1

#define SCE_CDVD_NCMD_READ             1
#define SCE_CDVD_NCMD_SEEK             5
#define SCE_CDVD_SCMD_BOOT_CERTIFY     0x1E
#define SCE_CDVD_SCMD_MMODE            0x22

/* 0x00510460–0x00511040 contains contiguous code only: no data entries or link veneers. */

/* These routines are the earlier libcdvd synchronization and RPC helpers. */
extern int func_0050d3a0(void);
extern void func_0050d3f0(void);
extern void func_0050f960(void);
extern void func_0050fbc0(void);
extern int func_0050ff58(int command);
extern int func_005100b0(void);
extern int func_005101e8(int mode);
extern int func_00510258(int command);
extern int PollSema(int sema_id);
extern int SignalSema(int sema_id);
extern void func_0050f698(void* callback_data);
extern void func_0050f8a8(void* callback_data);

typedef struct sceCdNcmdReadPacket
{
    u_int lbn;
    u_int sectors;
    void* buffer;
    sceCdRMode mode;
    void (*callback)(void* callback_data);
    void* callback_data;
} sceCdNcmdReadPacket;

/* The retail clients expose their server pointer at +0x24. */
static SifRpcClientData_t sInitClient;
static SifRpcClientData_t sLegacyDiskReadyClient;
static SifRpcClientData_t sDiskReadyClient;
static SifRpcClientData_t sNcmdClient;
static SifRpcClientData_t sScmdClient;

static int sScmdSemaId;
static int sDiskReadySemaId;
static int sNcmdCallbackNumber;
static int sScmdBusy;
static int sInitMode;
static int sInitReply[4];
static int sLegacyDiskReadyMode;
static int sLegacyDiskReadyReply;
static int sDiskReadyMode;
static int sDiskReadyReply;
static int sScmdArgument;
static int sScmdReply;
static u_int sSeekLbn;
static sceCdNcmdReadPacket sReadPacket;

static void sceCdBindClient(SifRpcClientData_t* client, int server_id)
{
    client->server = NULL;

    while (sceSifBindRpc(client, server_id, 0) < 0 || client->server == NULL)
    {
    }
}

static int sceCdDiskReadyFailure(int mode)
{
    if (mode == 8)
    {
        return -1;
    }
    return SCECdNotReady;
}

static int sceCdSubmitNCmd(int check_command)
{
    if (func_005100b0() == SCECdNotReady)
    {
        return 0;
    }

    return func_0050ff58(check_command);
}


// FUN_00510460 NONMATCHING
int sceCdInit(int init_mode)
{
    int result;
    int smaller_version;

    if (func_005101e8(1))
    {
        return 0;
    }

    sceSifInitRpc(0);
    sInitMode = init_mode;
    sceCdBindClient(&sInitClient, SCE_CDVD_RPC_INIT);
    sceSifWriteBackDCache(&sInitMode, 4);

    if (sceSifCallRpc(&sInitClient, 0, 0, &sInitMode, 4, sInitReply, 16, NULL, NULL) < 0)
    {
        return 0;
    }

    result = 1;
    if (sInitReply[3] != 0xFF && sInitReply[3] != 0xFE)
    {
        smaller_version = sInitReply[3] < sInitReply[1] ? sInitReply[3] : sInitReply[1];
        if (((smaller_version + 0xFF) >> 8) < 2)
        {
            result = 2;
        }
        else
        {
            smaller_version = sInitReply[3] < sInitReply[2] ? sInitReply[3] : sInitReply[2];
            if (((smaller_version + 0xFF) >> 8) < 2)
            {
                result = 2;
            }
        }
    }

    if (init_mode == SCECdEXIT)
    {
        sNcmdCallbackNumber = -1;
        sScmdBusy = 0;
    }
    else
    {
        func_0050f960();
        func_0050fbc0();
    }

    return result;
}

/* Internal legacy disk-ready RPC path. It is code, not a linker veneer. */
// FUN_00510748 NONMATCHING
int func_00510748(int mode)
{
    int result;

    func_0050f960();
    if (PollSema(sDiskReadySemaId) != sDiskReadySemaId)
    {
        return sceCdDiskReadyFailure(mode);
    }

    if (func_005101e8(1))
    {
        SignalSema(sDiskReadySemaId);
        return sceCdDiskReadyFailure(mode);
    }

    sceSifInitRpc(0);
    if (func_0050d3a0())
    {
        func_0050d3f0();
    }

    if (sLegacyDiskReadyClient.server == NULL)
    {
        sceCdBindClient(&sLegacyDiskReadyClient, SCE_CDVD_RPC_DISK_READY_OLD);
    }

    sLegacyDiskReadyMode = mode;
    sceSifWriteBackDCache(&sLegacyDiskReadyMode, 4);
    if (sceSifCallRpc(&sLegacyDiskReadyClient, 0, 0, &sLegacyDiskReadyMode, 4, &sLegacyDiskReadyReply, 4, NULL, NULL) < 0)
    {
        SignalSema(sDiskReadySemaId);
        return sceCdDiskReadyFailure(mode);
    }

    result = sLegacyDiskReadyReply;
    SignalSema(sDiskReadySemaId);
    return result;
}

// FUN_00510960 NONMATCHING
int sceCdDiskReady(int mode)
{
    int tries;
    int result;

    func_0050f960();
    if (PollSema(sDiskReadySemaId) != sDiskReadySemaId)
    {
        return sceCdDiskReadyFailure(mode);
    }

    sceSifInitRpc(0);
    if (sDiskReadyClient.server == NULL)
    {
        for (tries = 0; tries < 0x11; tries++)
        {
            if (sceSifBindRpc(&sDiskReadyClient, SCE_CDVD_RPC_DISK_READY, 0) >= 0 && sDiskReadyClient.server != NULL)
            {
                break;
            }
        }

        if (sDiskReadyClient.server == NULL)
        {
            SignalSema(sDiskReadySemaId);
            return func_00510748(mode);
        }
    }

    if (func_0050d3a0())
    {
        func_0050d3f0();
    }

    sDiskReadyMode = mode;
    sceSifWriteBackDCache(&sDiskReadyMode, 4);
    if (sceSifCallRpc(&sDiskReadyClient, 4, 0, &sDiskReadyMode, 4, &sDiskReadyReply, 4, NULL, NULL) < 0)
    {
        SignalSema(sDiskReadySemaId);
        return sceCdDiskReadyFailure(mode);
    }

    result = sDiskReadyReply;
    SignalSema(sDiskReadySemaId);
    return result;
}

// FUN_00510B80 NONMATCHING
int sceCdRead(u_int lbn, u_int sectors, void* buffer, sceCdRMode* mode)
{
    u_int sector_size;

    if (!sceCdSubmitNCmd(4))
    {
        return 0;
    }

    sReadPacket.lbn = lbn;
    sReadPacket.sectors = sectors;
    sReadPacket.buffer = buffer;
    sReadPacket.mode.trycount = mode->trycount;
    sReadPacket.mode.spindlctrl = mode->spindlctrl;
    sReadPacket.mode.datapattern = mode->datapattern;
    sReadPacket.callback = func_0050f8a8;
    sReadPacket.callback_data = &sNcmdCallbackNumber;

    if (mode->datapattern == 1)
    {
        sector_size = 2328;
    }
    else if (mode->datapattern == 2)
    {
        sector_size = 2340;
    }
    else
    {
        sector_size = 2048;
    }

    sceSifWriteBackDCache(buffer, sectors * sector_size);
    sceSifWriteBackDCache(&sReadPacket, 24);
    sNcmdCallbackNumber = SCE_CDVD_NCMD_READ;

    if (sceSifCallRpc(&sNcmdClient, SCE_CDVD_NCMD_READ, SCE_CDVD_RPC_NOWAIT, &sReadPacket, 24, NULL, 0, func_0050f8a8, &sNcmdCallbackNumber) < 0)
    {
        sNcmdCallbackNumber = 0;
        return 0;
    }

    return 1;
}

// FUN_00510D60 NONMATCHING
int sceCdSeek(u_int lbn)
{
    if (!sceCdSubmitNCmd(9))
    {
        return 0;
    }

    sSeekLbn = lbn;
    sceSifWriteBackDCache(&sSeekLbn, 4);
    sNcmdCallbackNumber = 4;
    if (sceSifCallRpc(&sNcmdClient, SCE_CDVD_NCMD_SEEK, SCE_CDVD_RPC_NOWAIT, &sSeekLbn, 4, NULL, 0, func_0050f698, &sNcmdCallbackNumber) < 0)
    {
        sNcmdCallbackNumber = 0;
        return 0;
    }

    return 1;
}

/* Internal command-1 SCMD RPC. No retail symbol evidence gives it a public name. */
#pragma optimization_level 3
// FUN_00510E30 NONMATCHING
int func_00510e30(void)
{
    int result;

    if (func_00510258(1))
    {
        if (sceSifCallRpc(&sScmdClient, 1, 0, NULL, 0, &sScmdReply, 4, NULL, NULL) >= 0)
        {
            result = sScmdReply;
            SignalSema(sScmdSemaId);
            return result;
        }

        SignalSema(sScmdSemaId);
    }

    return -1;
}

/* This is a code wrapper around func_00510e30, not a data entry or veneer. */
#pragma optimization_level 3
// FUN_00510EC8 NONMATCHING
int func_00510ec8(void)
{
    int result;
    result = func_00510e30();
    if (result < 0) {
        result = 0;
    }
    return result;
}
#pragma optimization_level 2

/* Internal command-3 SCMD RPC. No retail symbol evidence gives it a public name. */
#pragma optimization_level 3
// FUN_00510EF0 NONMATCHING
int func_00510ef0(void)
{
    int result;

    if (func_00510258(3))
    {
        if (sceSifCallRpc(&sScmdClient, 3, 0, NULL, 0, &sScmdReply, 4, NULL, NULL) >= 0)
        {
            result = sScmdReply;
            SignalSema(sScmdSemaId);
            return result;
        }

        SignalSema(sScmdSemaId);
    }

    return -1;
}
#pragma optimization_level 2

/* Internal command-0x1e SCMD dispatch with an asynchronous completion state. */
// FUN_00510F88 NONMATCHING
int func_00510f88(void)
{
    if (!func_00510258(SCE_CDVD_SCMD_BOOT_CERTIFY))
    {
        return 0;
    }

    sScmdArgument = 0;
    sScmdBusy = 8;
    sceSifWriteBackDCache(&sScmdArgument, 4);
    if (sceSifCallRpc(&sScmdClient, SCE_CDVD_SCMD_BOOT_CERTIFY, 0, &sScmdArgument, 4, &sScmdReply, 4, NULL, NULL) < 0)
    {
        sScmdBusy = 0;
        SignalSema(sScmdSemaId);
        return 0;
    }

    sScmdBusy = 0;
    SignalSema(sScmdSemaId);
    return 1;
}

// FUN_00511040 NONMATCHING
int sceCdMmode(int media)
{
    int result;

    if (!func_00510258(SCE_CDVD_SCMD_MMODE))
    {
        return 0;
    }

    sScmdArgument = media;
    sceSifWriteBackDCache(&sScmdArgument, 4);
    if (sceSifCallRpc(&sScmdClient, SCE_CDVD_SCMD_MMODE, 0, &sScmdArgument, 4, &sScmdReply, 4, NULL, NULL) < 0)
    {
        SignalSema(sScmdSemaId);
        return 0;
    }

    result = sScmdReply;
    SignalSema(sScmdSemaId);
    return result;
}

#pragma push
#pragma optimization_level 3
#pragma opt_propagation off
// FUN_00511110 MATCHING
u32 FUN_00511110(void)
{
  FUN_00505e48((u8*)DAT_007c0000_abs - 0x1cd0);
  return 2;
}
#pragma pop
// FUN_00511138 NONMATCHING
u64 FUN_00511138(u64 param_1)

{
  int iVar1;
  u32 uVar2;
  u64 uVar3;
  
  if (ram0x00782748 == 0) {
    while( true ) {
      FUN_00507050(0x96dcc0,0xffffffff80000100,0);
      iVar1 = 0x10000;
      if (DAT_0096dce4 != 0) break;
      do {
        iVar1 = iVar1 + -1;
      } while (iVar1 != -1);
    }
    while( true ) {
      FUN_00507050(0x96dce8,0xffffffff80000101,0);
      iVar1 = 0x10000;
      if (DAT_0096dd0c != 0) break;
      do {
        iVar1 = iVar1 + -1;
      } while (iVar1 != -1);
    }
    uVar2 = FUN_00512640();
    if ((int)uVar2 >> 8 != 4) {
      if (DAT_0078274c != 0) {
        FUN_00505e48(0x7be358);
        FUN_00505e48(0x7be380,4,0,(int)uVar2 >> 8,uVar2 & 0xff);
      }
      return 0;
    }
  }
  uVar3 = FUN_005112d0();
  ram0x00782748 = 1;
  return uVar3;
}
// FUN_00511288 NONMATCHING
void FUN_00511288(int param_1)

{
  if (DAT_00782750 != (code)0) {
    (*DAT_00782750)(*(u32 *)(param_1 + 0xc));
  }
  SYNC(0);
  EI();
  return;
}
// FUN_005112D0 NONMATCHING
u32 FUN_005112d0(void)

{
  u32 *puVar1;
  u32 uVar2;
  long lVar3;
  int iVar4;

  puVar1 = &DAT_0096dd94;
  iVar4 = 3;
  do {
    puVar1[-0x1d] = 0;
    iVar4 = iVar4 + -1;
    puVar1[-0x1b] = 0;
    puVar1[-0x1c] = 0;
    puVar1[-1] = 0;
    puVar1[1] = 0;
    *puVar1 = 0;
    puVar1 = puVar1 + 7;
  } while (-1 < iVar4);
  DAT_0096df10 = 0;
  DAT_0096df00 = 0x10;
  DAT_0096df14 = DAT_00782754;
  lVar3 = FUN_00507230(0x96dcc0,1,0,0x96df00,0x80,0x96df00,0x80,0);
  if (lVar3 < 0) {
    uVar2 = 0;
  }
  else {
    DAT_00782750 = 0;
    lVar3 = FUN_0050d3a0();
    FUN_00506430(0xffffffff80000019,0x511288,0);
    uVar2 = DAT_0096df0c;
    if (lVar3 == 1) {
      FUN_0050d3f0();
      uVar2 = DAT_0096df0c;
    }
  }
  return uVar2;
}
// FUN_005113C8 NONMATCHING
int FUN_005113c8(void)

{
  int iVar1;
  long lVar2;
  
  if (ram0x00782748 == 0) {
    iVar1 = 1;
  }
  else {
    FUN_00512710(0);
    DAT_0096df00 = 0xf;
    lVar2 = FUN_00507230(0x96dcc0,1,0,0x96df00,0x80,0x96df00,0x80,0);
    iVar1 = 0;
    if (-1 < lVar2) {
      FUN_005064a8(0xffffffff80000019);
      if (DAT_0096df0c == 1) {
        ram0x00782748 = 0;
      }
      DAT_00782754 = 0;
      iVar1 = DAT_0096df0c;
    }
  }
  return iVar1;
}
// FUN_00511478 NONMATCHING
u32 FUN_00511478(int param_1,int param_2)

{
  u32 *puVar1;
  u32 uVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  u32 *puStack_150;
  int iStack_14c;
  u32 uStack_148;
  u32 uStack_144;
  
  iVar4 = param_2 * 0x1c + param_1 * 0x70;
  puVar1 = *(u32 **)(&DAT_0096dd14 + iVar4);
  if ((*(int *)(&DAT_0096dd1c + iVar4) == 0) || (lVar3 = sceSifDmaStat(), lVar3 < 0)) {
    uVar2 = *puVar1;
    iVar5 = param_2 * 0x1c + param_1 * 0x70;
    iVar4 = *(int *)(&DAT_0096dd18 + iVar5);
    *puVar1 = uVar2 + 1;
    FUN_00503a58(puVar1,(int)puVar1 + 0x1f);
    uStack_148 = 0x20;
    uStack_144 = 0;
    puStack_150 = puVar1;
    iStack_14c = iVar4 + (uVar2 + 1 & 1) * 0x20;
    lVar3 = FUN_00506088(&puStack_150,1);
    if (lVar3 != 0) {
      *(int *)(&DAT_0096dd1c + iVar5) = (int)lVar3;
      return 1;
    }
  }
  if (DAT_0078274c != 0) {
    FUN_00505e48(0x7be3a8);
  }
  return 0;
}
// FUN_00511590 NONMATCHING
u32 FUN_00511590(u64 param_1,u64 param_2,u32 param_3)

{
  u32 uVar1;
  long lVar2;
  u32 *puVar3;
  u32 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((param_3 & 0x3f) == 0) {
    iVar7 = (int)param_1;
    iVar6 = (int)param_2;
    if ((&DAT_0096dd20)[iVar7 * 0x1c + iVar6 * 7] == 1) {
      if (DAT_0078274c != 0) {
        FUN_00505e48(0x7be3f8,param_1,param_2);
        return 0;
      }
    }
    else {
      iVar5 = 1;
      uVar4 = param_3;
      do {
        *(u32 *)(uVar4 + 0x58) = 0;
        *(u8 *)(uVar4 + 0x70) = 5;
        *(u8 *)(uVar4 + 0x71) = 2;
        *(u8 *)(uVar4 + 0x67) = 0;
        iVar5 = iVar5 + -1;
        FUN_00521408(uVar4,0xff,0x20);
        *(u32 *)(uVar4 + 0x60) = 0;
        uVar4 = uVar4 + 0x80;
      } while (-1 < iVar5);
      DAT_0096df00 = 1;
      DAT_0096df04 = iVar7;
      DAT_0096df08 = iVar6;
      DAT_0096df10 = param_3;
      lVar2 = FUN_00507230(0x96dcc0,1,0,0x96df00,0x80,0x96df00,0x80,0);
      uVar1 = DAT_0096df14;
      if (-1 < lVar2) {
        iVar5 = iVar6 * 0x1c + iVar7 * 0x70;
        puVar3 = (u32 *)(iVar7 * 0x80 + iVar6 * 0x20 + 0x96de00);
        (&DAT_0096dd20)[iVar7 * 0x1c + iVar6 * 7] = 1;
        *puVar3 = 0;
        *(u32 *)(&DAT_0096dd1c + iVar5) = 0;
        *(u32 *)(&DAT_0096dd18 + iVar5) = uVar1;
        *(u32 *)(&DAT_0096dd10 + iVar5) = param_3;
        *(u32 **)(&DAT_0096dd14 + iVar5) = puVar3;
        return DAT_0096df0c;
      }
    }
  }
  else if (DAT_0078274c != 0) {
    FUN_00505e48(0x7be3c8,param_3);
    return 0;
  }
  return 0;
}
// FUN_00511830 NONMATCHING
int FUN_00511830(int param_1,int param_2,u64 *param_3)

{
  int iVar1;
  u64 *puVar2;
  long lVar3;
  u32 uVar4;
  u64 *puVar5;
  u64 uVar6;
  u64 uVar7;
  u64 uVar8;
  int iVar9;
  
  lVar3 = FUN_0050d3a0();
  iVar1 = *(int *)(&DAT_0096dd10 + param_2 * 0x1c + param_1 * 0x70);
  FUN_00503a58(iVar1,iVar1 + 0xff);
  uVar4 = (u32)(*(int *)(iVar1 + 0x58) < *(int *)(iVar1 + 0xd8));
  if (param_3 == (u64 *)0x0) {
    iVar9 = uVar4 << 7;
  }
  else {
    iVar9 = uVar4 * 0x80;
    puVar5 = (u64 *)(iVar9 + iVar1);
    puVar2 = puVar5 + 0x10;
    if ((((u32)puVar5 | (u32)param_3) & 7) == 0) {
      do {
        uVar6 = puVar5[1];
        uVar7 = puVar5[2];
        uVar8 = puVar5[3];
        *param_3 = *puVar5;
        param_3[1] = uVar6;
        param_3[2] = uVar7;
        param_3[3] = uVar8;
        puVar5 = puVar5 + 4;
        param_3 = param_3 + 4;
      } while (puVar5 != puVar2);
    }
    else {
      do {
        uVar6 = puVar5[1];
        uVar7 = puVar5[2];
        uVar8 = puVar5[3];
        *param_3 = *puVar5;
        param_3[1] = uVar6;
        param_3[2] = uVar7;
        param_3[3] = uVar8;
        puVar5 = puVar5 + 4;
        param_3 = param_3 + 4;
      } while (puVar5 != puVar2);
    }
  }
  if (lVar3 == 1) {
    FUN_0050d3f0();
  }
  return iVar1 + iVar9;
}
// FUN_005119E0 NONMATCHING
u32 FUN_005119e0(u64 param_1,u64 param_2,u64 param_3)

{
  u8 auStack_a0 [96];
  u32 uStack_40;
  
  if ((&DAT_0096dd20)[(int)param_1 * 0x1c + (int)param_2 * 7] == 0) {
    uStack_40 = 0;
  }
  else {
    FUN_00511830(param_1,param_2,(u64 *)auStack_a0);
    FUN_00521250(param_3,auStack_a0,uStack_40);
  }
  return uStack_40;
}
// FUN_00511A58 NONMATCHING
char FUN_00511a58(u64 param_1,int param_2)

{
  u8 auStack_90 [112];
  char cStack_20;
  char cStack_1f;
  
  if ((&DAT_0096dd20)[(int)param_1 * 0x1c + param_2 * 7] == 0) {
    cStack_20 = 'c';
  }
  else {
    FUN_00511830(param_1,param_2,(u64 *)auStack_90);
    if ((cStack_20 == '\x06') && (cStack_1f == '\x02')) {
      cStack_20 = '\x05';
    }
  }
  return cStack_20;
}
// FUN_00511B08 NONMATCHING
u64 FUN_00511b08(int param_1,int param_2,u8 param_3)

{
  u64 uVar1;
  long lVar2;
  
  if ((&DAT_0096dd20)[param_1 * 0x1c + param_2 * 7] == 0) {
    uVar1 = 0;
  }
  else {
    lVar2 = FUN_0050d3a0();
    uVar1 = FUN_00511830(param_1,param_2,0);
    *(u8 *)((int)uVar1 + 0x71) = param_3;
    FUN_00503a58(uVar1,(int)uVar1 + 0x7f);
    uVar1 = 1;
    if (lVar2 == 1) {
      FUN_0050d3f0();
      uVar1 = 1;
    }
  }
  return uVar1;
}
// FUN_00511BC0 NONMATCHING
u8 FUN_00511bc0(u64 param_1,int param_2)

{
  u8 uVar1;
  int iVar2;
  
  if ((&DAT_0096dd20)[(int)param_1 * 0x1c + param_2 * 7] == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = FUN_00511830(param_1,param_2,0);
    uVar1 = *(u8 *)(iVar2 + 0x71);
  }
  return uVar1;
}
// FUN_00511C50 NONMATCHING
u32 FUN_00511c50(u64 param_1,int param_2,int param_3,long param_4)
{
  u8 auStack_b0[0x80];
  u8 *puVar1;
  u32 *puVar2;
  u8 *data;

  puVar2 = (u32 *)(DAT_0096dd10_abs +
                   (int)param_1 * 0x70 + param_2 * 0x1c);
  if (puVar2[4] == 0) {
    return 0;
  }
  data = auStack_b0 - 0x40;
  FUN_00511830(param_1,param_2,(u64 *)data);
  if (data[0x72] != 1) {
    return 0;
  }
  if (data[0x64] < 2) {
    return 0;
  }
  if (param_3 < data[0x6a]) {
    if (param_3 == -1) {
      return (u32)data[0x6a];
    }
    puVar1 = data + (param_3 * 4);
    if (param_4 == param_1) {
      return (u32)puVar1[0x30];
    }
    if (param_4 < 3) {
      return 0;
    }
    if (param_4 == 3) {
      return (u32)puVar1[0x32];
    }
    if (param_4 == 4) {
      return (u32)puVar1[0x33];
    }
    if (param_4 == (param_3 * 4)) {
      return (u32)puVar1[0x31];
    }
  }
  return 0;
}
// FUN_00511FB8 NONMATCHING
int FUN_00511fb8(u64 param_1,u64 param_2,u32 param_3,u32 param_4)

{
  int iVar1;
  long lVar2;
  
  DAT_0096df00 = 6;
  DAT_0096df04 = (u32)param_1;
  DAT_0096df08 = (u32)param_2;
  DAT_0096df0c = param_3;
  DAT_0096df10 = param_4;
  lVar2 = FUN_00507230(0x96dcc0,1,0,0x96df00,0x80,0x96df00,0x80,0);
  if (lVar2 < 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = DAT_0096df14;
    if (DAT_0096df14 == 1) {
      FUN_00511b08(param_1,param_2,2);
      iVar1 = DAT_0096df14;
    }
  }
  return iVar1;
}
// FUN_00512070 NONMATCHING
bool FUN_00512070(u64 param_1,u64 param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  u8 *puVar3;
  long lVar4;
  u8 *puVar5;
  int iVar6;
  u8 auStack_c0 [114];
  char cStack_4e;
  
  FUN_00511830(param_1,param_2,(u64 *)auStack_c0);
  bVar2 = false;
  if (cStack_4e == '\x01') {
    iVar6 = 0;
    iVar1 = *(int *)(&DAT_0096dd14 + (int)param_2 * 0x1c + (int)param_1 * 0x70);
    do {
      puVar3 = (u8 *)(param_3 + iVar6);
      puVar5 = (u8 *)(iVar1 + 0xc + iVar6);
      iVar6 = iVar6 + 1;
      *puVar5 = *puVar3;
    } while (iVar6 < 6);
    *(u32 *)(iVar1 + 4) = 1;
    *(u32 *)(iVar1 + 8) = 6;
    lVar4 = FUN_00511478(param_1,param_2);
    bVar2 = lVar4 == 1;
  }
  return bVar2;
}
// FUN_00512138 NONMATCHING
int FUN_00512138(int param_1,int param_2,int param_3)

{
  u8 *puVar1;
  long lVar2;
  u8 *puVar3;
  int iVar4;
  
  DAT_0096df00 = 8;
  DAT_0096df04 = (u32)param_1;
  iVar4 = 0;
  DAT_0096df08 = (u32)param_2;
  do {
    puVar1 = (u8 *)(param_3 + iVar4);
    puVar3 = (u8 *)((int)&DAT_0096df0c + iVar4);
    iVar4 = iVar4 + 1;
    *puVar3 = *puVar1;
  } while (iVar4 < 6);
  lVar2 = FUN_00507230(0x96dcc0,1,0,0x96df00,0x80,0x96df00,0x80,0);
  if (lVar2 < 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = DAT_0096df14;
    if (DAT_0096df14 == 1) {
      FUN_00511b08(param_1,param_2,2);
      iVar4 = DAT_0096df14;
    }
  }
  return iVar4;
}
// FUN_005122C0 NONMATCHING
int FUN_005122c0(u64 param_1,u64 param_2,u32 param_3)

{
  int iVar1;
  long lVar2;
  
  DAT_0096df00 = 10;
  DAT_0096df04 = (u32)param_1;
  DAT_0096df08 = (u32)param_2;
  DAT_0096df0c = param_3;
  lVar2 = FUN_00507230(0x96dcc0,1,0,0x96df00,0x80,0x96df00,0x80,0);
  if (lVar2 < 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = DAT_0096df10;
    if (DAT_0096df10 == 1) {
      FUN_00511b08(param_1,param_2,2);
      iVar1 = DAT_0096df10;
    }
  }
  return iVar1;
}
// FUN_005124A0 NONMATCHING
int FUN_005124a0(u64 param_1,u64 param_2,u64 *param_3)

{
  int iVar1;
  long lVar2;
  
  DAT_0096df04 = (u32)param_1;
  DAT_0096df00 = 0xb;
  DAT_0096df08 = (u32)param_2;
  _DAT_0096df0c = *param_3;
  DAT_0096df14 = *(u32 *)(param_3 + 1);
  lVar2 = FUN_00507230(0x96dcc0,1,0,0x96df00,0x80,0x96df00,0x80,0);
  if (lVar2 < 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = DAT_0096df1c;
    if (DAT_0096df1c == 1) {
      FUN_00511b08(param_1,param_2,2);
      iVar1 = DAT_0096df1c;
    }
  }
  return iVar1;
}
// FUN_00512570 NONMATCHING
u32 FUN_00512570(void)
{
  u32 uVar1;
  long lVar2;
  
  DAT_0096df00 = 0xc;
  lVar2 = FUN_00507230(0x96dcc0,1,0,0x96df00,0x80,0x96df00,0x80,0);
  uVar1 = DAT_0096df0c;
  if (lVar2 < 0) {
    uVar1 = 0;
  }
  return uVar1;
}
// FUN_005125D8 NONMATCHING
u32 FUN_005125d8(u32 param_1)

{
  u32 uVar1;
  long lVar2;
  
  DAT_0096df00 = 0xd;
  DAT_0096df04 = param_1;
  lVar2 = FUN_00507230(0x96dcc0,1,0,0x96df00,0x80,0x96df00,0x80,0);
  uVar1 = DAT_0096df0c;
  if (lVar2 < 0) {
    uVar1 = 0;
  }
  return uVar1;
}
// FUN_00512640 NONMATCHING
u32 FUN_00512640(void)

{
  u32 uVar1;
  long lVar2;
  
  DAT_0096df00 = 0x12;
  lVar2 = FUN_00507230(0x96dcc0,1,0,0x96df00,0x80,0x96df00,0x80,0);
  uVar1 = DAT_0096df0c;
  if (lVar2 < 0) {
    uVar1 = 0;
  }
  return uVar1;
}
// FUN_005126A8 NONMATCHING
u32 FUN_005126a8(u32 param_1)

{
  u32 uVar1;
  long lVar2;
  
  DAT_0096df00 = 0x14;
  DAT_0096df04 = param_1;
  lVar2 = FUN_00507230(0x96dcc0,1,0,0x96df00,0x80,0x96df00,0x80,0);
  uVar1 = DAT_0096df08;
  if (lVar2 < 0) {
    uVar1 = 0;
  }
  return uVar1;
}
// FUN_00512710 NONMATCHING
int FUN_00512710(long param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = (int)(DAT_00782750);
  if (param_1 == 0) {
    DAT_0096df00 = 0x18;
    DAT_00782750 = 0;
    DAT_0096df04 = 0;
    do {
      lVar2 = FUN_00507230(0x96dcc0,1,0,0x96df00,0x80,0x96df00,0x80,0);
    } while (lVar2 < 0);
  }
  else {
    if (DAT_00782750 == 0) {
      DAT_0096df00 = 0x18;
      DAT_0096df04 = 1;
      do {
        lVar2 = FUN_00507230(0x96dcc0,1,0,0x96df00,0x80,0x96df00,0x80,0);
      } while (lVar2 < 0);
    }
    lVar2 = FUN_0050d3a0();
    DAT_00782750 = (code)((int)param_1);
    DAT_0096df80 = (u32)((u8 *)register0x000001c0);
    if (lVar2 == 1) {
      FUN_0050d3f0();
    }
  }
  return iVar1;
}
// FUN_00512868 NONMATCHING
u32 FUN_00512868(void)

{
  int iVar1;
  long lVar2;
  
  FUN_005068a8(0);
  do {
    lVar2 = FUN_00507050(0x96e040,0xffffffff80000701,0);
    iVar1 = 10000;
    if (lVar2 < 0) {
      FUN_00505e48(0x7be488);
      return 0xffffffff;
    }
    do {
      iVar1 = iVar1 + -1;
    } while (iVar1 != -1);
  } while (DAT_0096e064 == 0);
  DAT_00782788 = 0;
  DAT_0078278c = 0;
  FlushCache(0);
  return 0;
}
// FUN_00512918 NONMATCHING
u32 FUN_00512918(u32 param_1,u32 param_2,u32 param_3,long param_4)

{
  long lVar1;
  long lVar2;
  
  if (param_4 != 0) {
    DAT_0096dfcc = 0;
    DAT_0096dfc0 = param_1;
    DAT_0096dfc4 = param_2;
    DAT_0096dfc8 = param_3;
    lVar1 = FUN_00506088(0x96dfc0,1);
    if (lVar1 != 0) {
      if (param_4 != 1) {
        return 0;
      }
      do {
        lVar2 = sceSifDmaStat(lVar1);
      } while (-1 < lVar2);
      return 0;
    }
  }
  return 0xffffffff;
}
#pragma schedule on
// FUN_005129C0 NONMATCHING
u32 *
FUN_005129c0(long param_1,u32 param_2,u64 param_3,u64 param_4,u64 param_5,
            u64 param_6,u64 param_7,u64 param_8)
{
  bool bVar1;
  u32 *puVar2;
  u32 *puVar3;
  u64 *puVar4;
  int iVar5;
  u32 uVar6;
  u32 *puVar7;
  u32 *puVar8;
  u32 **ppuVar9;
  u32 uVar10;
  u32 uVar11;
  u32 *puVar12;
  u32 *apuStack_f0[4];
  u64 uStack_30;
  u64 uStack_28;
  u64 uStack_20;
  u64 uStack_18;
  u64 uStack_10;
  u64 uStack_8;

  uStack_30 = param_3;
  puVar7 = &DAT_0096e004;
  uStack_28 = param_4;
  iVar5 = 5;
  uStack_20 = param_5;
  uStack_18 = param_6;
  uStack_10 = param_7;
  uStack_8 = param_8;
  DAT_0096e000 = (u32)(&DAT_0096e000);
  puVar4 = &uStack_30;
  do {
    iVar5 = iVar5 + -1;
    *puVar7 = *(u32 *)puVar4;
    puVar3 = (u32 *)(DAT_0096e004);
    puVar2 = (u32 *)(u32)DAT_007827a8;
    puVar12 = (u32 *)(u32)DAT_007827a4;
    puVar8 = (u32 *)(u32)ram0x007827a0;
    puVar7 = puVar7 + 1;
    puVar4 = puVar4 + 1;
  } while (-1 < iVar5);
  bVar1 = param_1 == 0;
  uVar11 = 0;
  if (bVar1) {
    uVar11 = DAT_00782788;
  }
  if (param_2 == 0x8160) {
    if (DAT_0096e004 == 0) {
      ram0x007827a0 = (code)(u32)DAT_0096e008;
      DAT_007827ac = DAT_0096e00c;
      puVar12 = puVar8;
      DAT_007827b8 = (u32)((u8 *)register0x000001c0);
    }
    else {
      DAT_007827a4 = (code)(u32)DAT_0096e008;
      DAT_007827b0 = DAT_0096e00c;
      DAT_007827bc = (u32)((u8 *)register0x000001c0);
    }
  }
  else {
    puVar12 = (u32 *)0x0;
    if (param_2 == 0x8170) {
      DAT_007827a8 = (code)(u32)DAT_0096e004;
      DAT_007827b4 = (u32 *)(u32)DAT_0096e008;
      puVar12 = puVar2;
      DAT_007827c0 = (u32)((u8 *)register0x000001c0);
    }
  }
  apuStack_f0[0] = (u32 *)0x0;
  if (((param_2 == 0x8130) || (param_2 == 0x81a0)) || (param_2 == 0x81b0)) {
    puVar7 = (u32 *)0x40;
    uVar10 = 0x40;
    uVar6 = param_2 | (u32)DAT_0096e004;
    puVar8 = (u32 *)(u32)DAT_0096e008;
  }
  else {
    if (param_2 == 0x8140) {
      FUN_00507230(0x96e040,(u32)DAT_0096e004 | 0x8140,bVar1,0x96e000,0x40,DAT_0096e008,0x40,uVar11);
      goto LAB_00512d10;
    }
    if ((param_2 == 0x81c0) || (param_2 == 0x81d0)) {
      *(u16 *)((int)DAT_0096e004 + 2) = (*(u16*)((u8*)&DAT_0096e008 + 0));
      if (param_2 == 0x81d0) {
        puVar3[1] = DAT_0096e014;
      }
      uVar10 = DAT_0096e010;
      ppuVar9 = (u32 **)(u32 *)DAT_0096e00c;
      if (DAT_0096e00c == 0) {
        ppuVar9 = apuStack_f0;
        uVar10 = 4;
      }
      FUN_00507230(0x96e040,param_2,bVar1,DAT_0096e004,((int)DAT_0096e008 + 1) * 8,ppuVar9,uVar10,
                   uVar11);
      if (DAT_0096e00c != 0) {
        apuStack_f0[0] = (u32 *)(*DAT_0096e00c);
      }
      goto LAB_00512d10;
    }
    puVar7 = (u32 *)(u32)DAT_0096e008;
    puVar8 = (u32 *)(u32)DAT_0096e004;
    if (0xf0 < param_2 - 0x9000) {
      puVar7 = (u32 *)0x40;
      puVar8 = &DAT_0096e000;
    }
    uVar10 = 0x10;
    uVar6 = param_2;
  }
  FUN_00507230(0x96e040,uVar6,bVar1,puVar8,puVar7,0x96e000,uVar10,uVar11);
  apuStack_f0[0] = (u32 *)(u32)DAT_0096e000;
LAB_00512d10:
  if ((param_2 == 0x8160) || (param_2 == 0x8170)) {
    apuStack_f0[0] = puVar12;
  }
  return apuStack_f0[0];
}
#pragma schedule off
// FUN_00512D48 NONMATCHING
int FUN_00512d48(u32 param_1)

{
  long lVar1;
  u8 auStack_60 [4];
  code *pcStack_5c;
  u8 *puStack_58;
  u32 uStack_54;
  u8 *puStack_50;
  u32 uStack_4c;
  char *pcStack_40;
  
  if (DAT_007827c4 < 0) {
    DAT_007827a8 = 0;
    ram0x007827a0 = 0;
    DAT_007827a4 = 0;
    DAT_007827ac = 0;
    DAT_007827b0 = 0;
    DAT_007827b4 = 0;
    DAT_007827b8 = 0;
    DAT_007827bc = 0;
    DAT_007827c0 = 0;
    FUN_005129c0(1,0xe620,0,0,0,0,0,0);
    pcStack_5c = (code *)(FUN_00512f80);
    puStack_58 = (u8 *)(&DAT_0096e080);
    uStack_54 = 0x1000;
    pcStack_40 = s_SceSdrCallbackThread_007be4b0;
    puStack_50 = (u8 *)(&_mips_gp0_value);
    uStack_4c = param_1;
    lVar1 = CreateThread(auStack_60);
    DAT_007827c4 = (int)lVar1;
    if (-1 < lVar1) {
      pcStack_40 = (char *)DAT_007827c4;
      lVar1 = FUN_005042a0(lVar1,0);
      if (-1 < lVar1) {
        return (int)pcStack_40;
      }
      FUN_00505e48(0x7be4c8);
    }
  }
  return -1;
}
// FUN_00512E48 NONMATCHING
u64 FUN_00512e48(void)

{
  long lVar1;
  u64 uVar2;
  u64 uVar3;
  
  if (DAT_007827c4 < 0) {
    uVar3 = 0xffffffffffffffff;
  }
  else {
    FUN_005129c0(1,0x8170,0,0,0,0,0,0);
    uVar3 = 0xffffffffffffffff;
    FUN_005129c0(1,0x8160,0,0,0,0,0,0);
    FUN_005129c0(1,0x8160,1,0,0,0,0,0);
    FUN_005129c0(1,0xe630,0,0,0,0,0,0);
    ram0x007827a0 = 0;
    DAT_007827a4 = 0;
    DAT_007827a8 = 0;
    DAT_007827ac = 0;
    DAT_007827b0 = 0;
    DAT_007827b4 = 0;
    DAT_007827b8 = 0;
    DAT_007827bc = 0;
    DAT_007827c0 = 0;
    lVar1 = FUN_005075d8(0x96f0d8,0x96f0c0);
    uVar2 = 0;
    if (lVar1 == 0) {
      uVar2 = uVar3;
    }
    lVar1 = FUN_00507670(0x96f0c0);
    if (lVar1 == 0) {
      uVar2 = uVar3;
    }
    lVar1 = TerminateThread(DAT_007827c4);
    if (lVar1 < 0) {
      uVar2 = uVar3;
    }
    lVar1 = DeleteThread(DAT_007827c4);
    DAT_007827c4 = -1;
    if (-1 < lVar1) {
      uVar3 = uVar2;
    }
  }
  return uVar3;
}
// FUN_00512F80 NONMATCHING
void FUN_00512f80(void)

{
  u64 uVar1;
  
  FUN_005068a8(0);
  uVar1 = GetThreadId();
  FUN_00507470(0x96f0c0,uVar1);
  FUN_00507508(0x96f0d8,0xffffffff80000704,0x512ff0,0x96f080,0,0,0x96f0c0);
  FUN_00507920(0x96f0c0);
  return;
}
// FUN_00512FF0 NONMATCHING
u64 FUN_00512ff0(u64 param_1,u32 *param_2)

{
  u32 uVar1;
  
  uVar1 = *param_2;
  if (((uVar1 & 0x100) != 0) && (ram0x007827a0 != (code)0)) {
    (*ram0x007827a0)(0,DAT_007827ac);
    uVar1 = *param_2;
  }
  if (((uVar1 & 0x200) != 0) && (DAT_007827a4 != (code)0)) {
    (*DAT_007827a4)(1,DAT_007827b0);
    uVar1 = *param_2;
  }
  if (((uVar1 & 0x400) != 0) && (DAT_007827a8 != (code)0)) {
    (*DAT_007827a8)(param_2[1],DAT_007827b4);
  }
  return 0;
}
