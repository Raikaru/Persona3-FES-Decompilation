#include "mw_harvest_compat.h"
#include "sce/sifrpc.h"

/* auto-extern (generated) */
extern u32 register0x00000050;
extern u32 register0x00000060;
extern u32 register0x00000070;
extern u32 DAT_009695c0;
extern u32 DAT_20969144;
extern u32 DAT_0077f4b0;
extern u32 DAT_0077f4b8;
extern u32 DAT_0077f538;
extern u32 DAT_0077f53c;
#pragma alias DAT_0077f53c_abs DAT_0077f53c
extern u8 DAT_0077f53c_abs[];
extern u32 DAT_0077f540;
extern u32 DAT_0077f544;
#pragma alias DAT_0077f544_abs DAT_0077f544
extern u8 DAT_0077f544_abs[];
extern u32 DAT_0077f548;
extern u32 DAT_0077f54c;
extern u32 DAT_009684c0;
extern u32 DAT_009684c4;
extern u32 DAT_009684c8;
extern u32 DAT_00968500;
#pragma alias DAT_00968500_abs DAT_00968500
extern u8 DAT_00968500_abs[];
extern u32 DAT_00968504;
extern u32 DAT_00968508;
extern u32 DAT_0096850c;
extern u32 DAT_00968510;
extern u32 DAT_00968514;
extern u32 DAT_00968518;
extern u32 DAT_0096851c;
extern u32 DAT_0096852c;
extern u32 DAT_0096854c;
extern u32 DAT_0096890b;
extern u32 DAT_0096890c;
extern u32 DAT_0096890f;
extern u32 DAT_00968913;
extern u32 DAT_00968914;
extern u32 DAT_00968918;
extern u32 DAT_0096891c;
extern u32 DAT_0096894f;
extern u32 DAT_00968d0b;
extern u32 DAT_00968d0c;
extern u32 DAT_00968d10;
extern u32 DAT_00968d14;
extern u32 DAT_00968d18;
extern u32 DAT_0096910c;
extern u32 DAT_00969110;
extern u32 DAT_00969180;
extern u32 DAT_00969a00;
extern u32 DAT_00969a04;
extern u32 DAT_00969c00;
extern u32 DAT_00969c24;
extern u32 DAT_00969c28;
extern u32 DAT_00969c80;
extern u32 DAT_00969c84;
#pragma alias DAT_00969c80_abs DAT_00969c80
extern u8 DAT_00969c80_abs[];
#pragma alias DAT_00969c84_abs DAT_00969c84
extern u8 DAT_00969c84_abs[];
extern u32 DAT_00969cc0;
extern u32 FUN_00508170(void);
extern u32 DAT_20969140;
extern void* PTR_DAT_0077f550;
extern u32 _DAT_00968510;
extern u32 _DAT_00968514;
extern u32 _DAT_00968518;
extern u32 _DAT_00968520;
extern u32 _DAT_00968530;
extern char s_SceStdioIobSema_007bdd40[];
extern char s_SceStdioQueSema_007bdd50[];
extern char s_SceStdioFioSema_007bddc8[];
extern char s_SceStdioOpenSema_007bdde0[];
extern char s_SceStdioCloseSema_007bddf8[];
extern char s_SceStdioLseekSema_007bde10[];
extern char s_SceStdioReadSema_007bde28[];
extern char s_SceStdioWriteSema_007bde40[];
extern char s_SceStdioIoctlSema_007bde58[];
extern char s_SceStdioIoctl2Sema_007bde70[];
extern char s_SceStdioCCodeSema_007bde88[];
extern char s_SceStdioMkdirSema_007bdea0[];
extern char s_SceStdioFormatSema_007bdeb8[];
extern char s_SceStdioAddDrvSema_007bded0[];
extern char s_SceStdioDcloseSema_007bdee8[];
extern char s_SceStdioDreadSema_007bdf00[];
extern char s_SceStdioGetstatSema_007bdf18[];
extern char s_SceStdioChstatSema_007bdf30[];
extern char s_SceStdioRenameSema_007bdf48[];
extern char s_SceStdioSyncSema_007bdf60[];
extern char s_SceStdioMountSema_007bdf78[];
extern char s_SceStdioLseek64Sema_007bdf90[];
extern char s_SceStdioDevctlSema_007bdfa8[];
extern char s_SceStdioSymlinkSema_007bdfc0[];
extern char s_SceStdioReadlinkSema_007bdfd8[];

#define SIF_RPC_PACKET_SIZE 64
#define SIF_RPC_PACKET_BUSY 1
#define SIF_RPC_MODE_NOWAIT 1
#define SIF_RPC_MODE_NO_CACHE 2
#define SIF_CMD_RPC_END 0x80000008
#define SIF_CMD_RPC_BIND 0x80000009
#define SIF_CMD_RPC_CALL 0x8000000A
#define SIF_CMD_RPC_RDATA 0x8000000C

typedef struct SifRpcPacket
{
    int command;
    int packet_size;
    void* destination;
    int data_size;
    int record_id;
    void* packet;
    int rpc_id;
} SifRpcPacket_t;

typedef struct SifRpcBindPacket
{
    SifRpcPacket_t header;
    SifRpcClientData_t* client;
    int server_id;
} SifRpcBindPacket_t;

typedef struct SifRpcCallPacket
{
    SifRpcPacket_t header;
    SifRpcClientData_t* client;
    int function;
    int send_size;
    void* receive_buffer;
    int receive_size;
    int receive_mode;
    void* server;
} SifRpcCallPacket_t;

typedef struct SifRpcOtherPacket
{
    SifRpcPacket_t header;
    SifRpcReceiveData_t* receive;
    void* source;
    void* destination;
    int size;
} SifRpcOtherPacket_t;

typedef struct SifRpcEndPacket
{
    SifRpcPacket_t header;
    SifRpcClientData_t* client;
    int command;
    void* server;
    void* buffer;
    void* callback_buffer;
} SifRpcEndPacket_t;

typedef struct SifRpcState
{
    int next_rpc_id;
    SifRpcPacket_t* packets;
    int packet_count;
    SifRpcPacket_t* receive_packets;
    int receive_packet_count;
    int receive_packet_index;
    SifRpcDataQueue_t* queues;
} SifRpcState_t;

static SifRpcPacket_t sRpcPackets[32] __attribute__((aligned(64)));
static SifRpcPacket_t sRpcReceivePackets[32] __attribute__((aligned(64)));
static SifRpcState_t sRpcState;
static int sRpcInitialized;

extern void func_00506148(void);
extern void FUN_005063c8(void);
extern int func_00506430(int command, void (*handler)(void*, void*), void* data);
extern int func_00506630(int command, void* packet, int packet_size, void* source, void* destination, int size);
extern void func_0050d3a0(void);
extern void func_0050d3f0(void);
extern int func_00503160(void* parameters);
extern void func_00503170(int semaphore);
extern void func_00503190(int semaphore);
extern void func_005031a0(int semaphore);

static void sif_rpc_release_packet(SifRpcPacket_t* packet)
{
    packet->rpc_id = 0;
    packet->record_id &= ~SIF_RPC_PACKET_BUSY;
}

static SifRpcPacket_t* sif_rpc_allocate_packet(void)
{
    int index;
    SifRpcPacket_t* packet;

    func_0050d3a0();
    for (index = 0, packet = sRpcState.packets; index < sRpcState.packet_count; index++, packet++)
    {
        if ((packet->record_id & SIF_RPC_PACKET_BUSY) == 0)
        {
            if (sRpcState.next_rpc_id == 0)
            {
                sRpcState.next_rpc_id = 2;
                packet->rpc_id = 1;
            }
            else
            {
                packet->rpc_id = sRpcState.next_rpc_id++;
            }
            packet->record_id = (index << 16) | 5;
            packet->packet = packet;
            func_0050d3f0();
            return packet;
        }
    }
    func_0050d3f0();
    return 0;
}

static SifRpcPacket_t* sif_rpc_allocate_receive_packet(void)
{
    int index;

    index = sRpcState.receive_packet_index % sRpcState.receive_packet_count;
    sRpcState.receive_packet_index = index + 1;
    return &sRpcState.receive_packets[index];
}

static int sif_rpc_send(int command, void* packet, void* source, void* destination, int size)
{
    return func_00506630(command, packet, SIF_RPC_PACKET_SIZE, source, destination, size);
}

static void sif_rpc_end(void* packet, void* data)
{
    SifRpcEndPacket_t* end;
    SifRpcClientData_t* client;

    (void)data;
    end = (SifRpcEndPacket_t*)packet;
    client = end->client;
    if (end->command == SIF_CMD_RPC_CALL)
    {
        if (client->end_function != 0)
        {
            client->end_function(client->end_parameter);
        }
    }
    else if (end->command == SIF_CMD_RPC_BIND)
    {
        client->server = end->server;
        client->buffer = end->buffer;
        client->callback_buffer = end->callback_buffer;
    }
    if (client->header.semaphore >= 0)
    {
        func_005031a0(client->header.semaphore);
    }
    if (client->header.packet != 0)
    {
        sif_rpc_release_packet((SifRpcPacket_t*)client->header.packet);
        client->header.packet = 0;
    }
}

static void sif_rpc_request_bind(void* packet, void* data)
{
    SifRpcBindPacket_t* bind;
    SifRpcEndPacket_t* end;
    SifRpcDataQueue_t* queue;
    SifRpcServerData_t* server;

    bind = (SifRpcBindPacket_t*)packet;
    end = (SifRpcEndPacket_t*)sif_rpc_allocate_receive_packet();
    end->header.packet = bind->header.packet;
    end->client = bind->client;
    end->command = SIF_CMD_RPC_BIND;
    server = 0;
    for (queue = (SifRpcDataQueue_t*)data; queue != 0 && server == 0; queue = queue->next)
    {
        for (server = queue->servers; server != 0; server = server->link)
        {
            if (server->server_id == bind->server_id)
            {
                break;
            }
        }
    }
    end->server = server;
    end->buffer = server != 0 ? server->buffer : 0;
    end->callback_buffer = server != 0 ? server->callback_buffer : 0;
    sif_rpc_send(SIF_CMD_RPC_END, end, 0, 0, 0);
}

static void sif_rpc_request_call(void* packet, void* data)
{
    SifRpcCallPacket_t* call;
    SifRpcServerData_t* server;
    SifRpcDataQueue_t* queue;

    (void)data;
    call = (SifRpcCallPacket_t*)packet;
    server = (SifRpcServerData_t*)call->server;
    if (server == 0)
    {
        return;
    }
    queue = server->queue;
    if (queue->request_head != 0)
    {
        queue->request_tail->next = server;
    }
    else
    {
        queue->request_head = server;
    }
    queue->request_tail = server;
    server->next = 0;
    server->packet = call->header.packet;
    server->client = call->client;
    server->rpc_number = call->function;
    server->size = call->send_size;
    server->receive_buffer = call->receive_buffer;
    server->receive_size = call->receive_size;
    server->receive_mode = call->receive_mode;
    server->receive_id = call->header.record_id;
}

static void sif_rpc_request_other_data(void* packet, void* data)
{
    SifRpcOtherPacket_t* other;
    SifRpcEndPacket_t* end;

    (void)data;
    other = (SifRpcOtherPacket_t*)packet;
    end = (SifRpcEndPacket_t*)sif_rpc_allocate_receive_packet();
    end->header.packet = other->header.packet;
    end->client = (SifRpcClientData_t*)other->receive;
    end->command = SIF_CMD_RPC_RDATA;
    sif_rpc_send(SIF_CMD_RPC_END, end, other->source, other->destination, other->size);
}

// FUN_005068A8 NONMATCHING
void sceSifInitRpc(unsigned int mode)
{
    int index;

    (void)mode;
    if (sRpcInitialized)
    {
        return;
    }
    sRpcInitialized = 1;
    func_00506148();
    func_0050d3a0();
    sRpcState.next_rpc_id = 1;
    sRpcState.packets = sRpcPackets;
    sRpcState.packet_count = 32;
    sRpcState.receive_packets = sRpcReceivePackets;
    sRpcState.receive_packet_count = 32;
    sRpcState.receive_packet_index = 0;
    sRpcState.queues = 0;
    for (index = 0; index < sRpcState.packet_count; index++)
    {
        sif_rpc_release_packet(&sRpcState.packets[index]);
    }
    func_00506430(SIF_CMD_RPC_END, sif_rpc_end, &sRpcState);
    func_00506430(SIF_CMD_RPC_BIND, sif_rpc_request_bind, &sRpcState);
    func_00506430(SIF_CMD_RPC_CALL, sif_rpc_request_call, &sRpcState);
    func_00506430(SIF_CMD_RPC_RDATA, sif_rpc_request_other_data, &sRpcState);
    func_0050d3f0();
}

// FUN_00506A48
asm void sceSifExitRpc(void)
{
    .set noreorder
    addiu $sp, $sp, -0x10
    sd $ra, 0($sp)
    .word 0x0c1418f2
    nop
    lui $v0, 0x78
    ld $ra, 0($sp)
    sw $zero, -0xb50($v0)
    jr $ra
    addiu $sp, $sp, 0x10
}


// FUN_00506A70 NONMATCHING
int FUN_00506a70(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_0050d3a0();
  iVar1 = 0;
  iVar3 = param_1[1];
  if (0 < param_1[2]) {
    do {
      if ((*(u32 *)(iVar3 + 0x10) & 1) == 0) {
        *(u32 *)(iVar3 + 0x10) = iVar1 << 0x10 | 5;
        iVar1 = *param_1;
        iVar2 = iVar1 + 1;
        *param_1 = iVar2;
        if (iVar2 == 1) {
          iVar2 = 1;
          *param_1 = iVar1 + 2;
        }
        *(int *)(iVar3 + 0x14) = iVar3;
        *(int *)(iVar3 + 0x18) = iVar2;
        FUN_0050d3f0();
        return iVar3;
      }
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x40;
    } while (iVar1 < param_1[2]);
  }
  FUN_0050d3f0();
  return 0;
}
// FUN_00506B18 NONMATCHING
void FUN_00506b18(int param_1)

{
  u32 uVar1;
  u32 uVar2;
  
  uVar1 = *(u32 *)(param_1 + 0x10);
  uVar2 = 0xfffffffe;
  *(u32 *)(param_1 + 0x18) = 0;
  *(u32 *)(param_1 + 0x10) = uVar1 & uVar2;
  return;
}
// FUN_00506B38 NONMATCHING
int FUN_00506b38(u64 param_1)

{

  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x24) % *(int *)(param_1 + 0x18);
  if (*(int *)(param_1 + 0x18) == 0) {
    trap(7);
  }
  *(int *)(param_1 + 0x24) = iVar1 + 1;
  return *(int *)(param_1 + 0x14) + iVar1 * 0x40;
}
// FUN_00506B68 NONMATCHING
int FUN_00506b68(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 < 0) || (*(int *)(param_1 + 0x20) <= param_2)) {
    iVar1 = FUN_00506b38(0);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1c) + param_2 * 0x40;
  }
  return iVar1;
}
// FUN_00506BA8 NONMATCHING
void FUN_00506ba8(int param_1)

{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  
  uVar1 = *(u32 *)(param_1 + 0x20);
  if (uVar1 == 0x8000000a) {
    puVar3 = *(u32 **)(param_1 + 0x1c);
    if (puVar3[7] == 0) {
      iVar2 = puVar3[2];
      goto LAB_00506c40;
    }
    (*(code *)puVar3[7])(puVar3[8]);
    puVar3 = *(u32 **)(param_1 + 0x1c);
  }
  else {
    puVar3 = *(u32 **)(param_1 + 0x1c);
    if (uVar1 < 0x8000000b) {
      if (uVar1 != 0x80000009) {
        iVar2 = puVar3[2];
        goto LAB_00506c40;
      }
      puVar3[9] = *(u32 *)(param_1 + 0x24);
      puVar3[5] = *(u32 *)(param_1 + 0x28);
    }
  }
  iVar2 = puVar3[2];
LAB_00506c40:
  if (-1 < iVar2) {
    iSignalSema();
  }
  FUN_00506b18(*puVar3);
  *puVar3 = 0;
  return;
}
// FUN_00506C78 NONMATCHING
u32 FUN_00506c78(void)

{
  long lVar1;
  u32 uVar2;
  int iVar3;
  u64 in_a3;
  
  iVar3 = (int)in_a3;
  lVar1 = FUN_00506670(0xffffffff80000008,in_a3,0x40,*(u32 *)(iVar3 + 0x24),
                       *(u32 *)(iVar3 + 0x28),*(u32 *)(iVar3 + 0x2c));
  uVar2 = 0x800;
  if (lVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}
// FUN_00506CB8 NONMATCHING
void FUN_00506cb8(int param_1,u64 param_2)

{
  u32 uVar1;
  u64 uVar2;
  long lVar3;
  int iVar4;
  
  if ((*(u32 *)(param_1 + 0x10) & 4) == 0) {
    uVar2 = FUN_00506b38(param_2);
  }
  else {
    uVar2 = FUN_00506b68(param_2,*(u32 *)(param_1 + 0x10) >> 0x10);
  }
  uVar1 = *(u32 *)(param_1 + 0x1c);
  iVar4 = (int)uVar2;
  *(u32 *)(iVar4 + 0x14) = *(u32 *)(param_1 + 0x14);
  *(u32 *)(iVar4 + 0x1c) = uVar1;
  *(u32 *)(iVar4 + 0x20) = 0x8000000c;
  *(u32 *)(iVar4 + 0x24) = *(u32 *)(param_1 + 0x20);
  *(u32 *)(iVar4 + 0x28) = *(u32 *)(param_1 + 0x24);
  *(u32 *)(iVar4 + 0x2c) = *(u32 *)(param_1 + 0x28);
  lVar3 = FUN_00506670(0xffffffff80000008,uVar2,0x40,*(u32 *)(param_1 + 0x20),
                       *(u32 *)(param_1 + 0x24),*(u32 *)(param_1 + 0x28));
  if (lVar3 == 0) {
    FUN_0050f1c0(0x800,0x506c78,uVar2);
    return;
  }
  return;
}
// FUN_00506D88 NONMATCHING
int sceSifBindRpc(SifRpcClientData_t* client, int server_id, int mode)
{
    SifRpcBindPacket_t* bind;
    int semaphore_parameters[3];

    bind = (SifRpcBindPacket_t*)sif_rpc_allocate_packet();
    if (bind == 0)
    {
        return -1;
    }
    client->header.packet = bind;
    client->header.rpc_id = bind->header.rpc_id;
    bind->server_id = server_id;
    bind->client = client;
    bind->header.packet = bind;
    if (mode & SIF_RPC_MODE_NOWAIT)
    {
        client->header.semaphore = -1;
        if (!sif_rpc_send(SIF_CMD_RPC_BIND, bind, 0, 0, 0))
        {
            sif_rpc_release_packet(&bind->header);
            return -2;
        }
        return 0;
    }
    semaphore_parameters[0] = 1;
    semaphore_parameters[1] = 0;
    semaphore_parameters[2] = 0;
    client->header.semaphore = func_00503160(semaphore_parameters);
    if (client->header.semaphore < 0)
    {
        sif_rpc_release_packet(&bind->header);
        return -3;
    }
    if (!sif_rpc_send(SIF_CMD_RPC_BIND, bind, 0, 0, 0))
    {
        sif_rpc_release_packet(&bind->header);
        func_00503170(client->header.semaphore);
        return -2;
    }
    func_00503190(client->header.semaphore);
    func_00503170(client->header.semaphore);
    return 0;
}


// FUN_00506EF0 NONMATCHING
int * FUN_00506ef0(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x28);
  if (iVar3 != 0) {
    piVar2 = *(int **)(iVar3 + 8);
    while( true ) {
      if (piVar2 == (int *)0x0) {
        iVar3 = *(int *)(iVar3 + 0x14);
      }
      else {
        iVar1 = *piVar2;
        while( true ) {
          if (iVar1 == param_1) {
            return piVar2;
          }
          piVar2 = (int *)piVar2[0xe];
          if (piVar2 == (int *)0x0) break;
          iVar1 = *piVar2;
        }
        iVar3 = *(int *)(iVar3 + 0x14);
      }
      if (iVar3 == 0) break;
      piVar2 = *(int **)(iVar3 + 8);
    }
  }
  return (int *)0x0;
}
// FUN_00506F40 NONMATCHING
u32 FUN_00506f40(void)

{
  long lVar1;
  u32 uVar2;
  u64 in_a3;
  
  lVar1 = FUN_00506670(0xffffffff80000008,in_a3,0x40,0,0,0);
  uVar2 = 0x800;
  if (lVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}
// FUN_00506F80 NONMATCHING
void FUN_00506f80(int param_1,u64 param_2)

{
  u32 uVar1;
  u64 uVar2;
  long lVar3;
  int iVar4;
  
  uVar2 = FUN_00506b38(param_2);
  uVar1 = *(u32 *)(param_1 + 0x14);
  iVar4 = (int)uVar2;
  *(u32 *)(iVar4 + 0x1c) = *(u32 *)(param_1 + 0x1c);
  *(u32 *)(iVar4 + 0x14) = uVar1;
  *(u32 *)(iVar4 + 0x20) = 0x80000009;
  lVar3 = (long)(FUN_00506ef0(*(u32 *)(param_1 + 0x20),param_2));
  if (lVar3 == 0) {
    *(u32 *)(iVar4 + 0x24) = 0;
    *(u32 *)(iVar4 + 0x28) = 0;
  }
  else {
    *(int *)(iVar4 + 0x24) = (int)lVar3;
    *(u32 *)(iVar4 + 0x28) = *(u32 *)((int)lVar3 + 8);
  }
  lVar3 = FUN_00506670(0xffffffff80000008,uVar2,0x40,0,0,0);
  if (lVar3 == 0) {
    FUN_0050f1c0(0x800,0x506f40,uVar2);
    return;
  }
  return;
}
// FUN_00507050 NONMATCHING
int sceSifGetOtherData(SifRpcReceiveData_t* receive, void* source, void* destination, int size, int mode)
{
    SifRpcOtherPacket_t* other;
    int semaphore_parameters[3];

    other = (SifRpcOtherPacket_t*)sif_rpc_allocate_packet();
    if (other == 0)
    {
        return -1;
    }
    receive->header.packet = other;
    receive->header.rpc_id = other->header.rpc_id;
    receive->header.semaphore = -1;
    other->source = source;
    other->destination = destination;
    other->size = size;
    other->receive = receive;
    other->header.packet = other;
    if (mode & SIF_RPC_MODE_NOWAIT)
    {
        if (!sif_rpc_send(SIF_CMD_RPC_RDATA, other, 0, 0, 0))
        {
            sif_rpc_release_packet(&other->header);
            return -2;
        }
        return 0;
    }
    semaphore_parameters[0] = 1;
    semaphore_parameters[1] = 0;
    semaphore_parameters[2] = 0;
    receive->header.semaphore = func_00503160(semaphore_parameters);
    if (receive->header.semaphore < 0)
    {
        sif_rpc_release_packet(&other->header);
        return -3;
    }
    if (!sif_rpc_send(SIF_CMD_RPC_RDATA, other, 0, 0, 0))
    {
        sif_rpc_release_packet(&other->header);
        func_00503170(receive->header.semaphore);
        return -2;
    }
    func_00503190(receive->header.semaphore);
    func_00503170(receive->header.semaphore);
    return 0;
}

// FUN_00507230 NONMATCHING
int sceSifCallRpc(SifRpcClientData_t* client, int function, int mode, void* send_buffer, int send_size, void* receive_buffer, int receive_size, SifRpcEndFunc_t callback, void* callback_data)
{
    SifRpcCallPacket_t* call;
    int semaphore_parameters[3];

    call = (SifRpcCallPacket_t*)sif_rpc_allocate_packet();
    if (call == 0)
    {
        return -1;
    }
    client->header.packet = call;
    client->header.rpc_id = call->header.rpc_id;
    client->header.semaphore = -1;
    client->end_function = callback;
    client->end_parameter = callback_data;
    call->function = function;
    call->send_size = send_size;
    call->receive_buffer = receive_buffer;
    call->receive_size = receive_size;
    call->receive_mode = 1;
    call->header.packet = call;
    call->client = client;
    call->server = client->server;
    if ((mode & SIF_RPC_MODE_NO_CACHE) == 0)
    {
        if (send_size > 0)
        {
            sceSifWriteBackDCache(send_buffer, send_size);
        }
        if (receive_size > 0)
        {
            sceSifWriteBackDCache(receive_buffer, receive_size);
        }
    }
    if (mode & SIF_RPC_MODE_NOWAIT)
    {
        if (callback == 0)
        {
            call->receive_mode = 0;
        }
        if (!sif_rpc_send(SIF_CMD_RPC_CALL, call, send_buffer, client->buffer, send_size))
        {
            sif_rpc_release_packet(&call->header);
            return -2;
        }
        return 0;
    }
    semaphore_parameters[0] = 1;
    semaphore_parameters[1] = 0;
    semaphore_parameters[2] = 0;
    client->header.semaphore = func_00503160(semaphore_parameters);
    if (client->header.semaphore < 0)
    {
        sif_rpc_release_packet(&call->header);
        return -3;
    }
    if (!sif_rpc_send(SIF_CMD_RPC_CALL, call, send_buffer, client->buffer, send_size))
    {
        sif_rpc_release_packet(&call->header);
        func_00503170(client->header.semaphore);
        return -2;
    }
    func_00503190(client->header.semaphore);
    func_00503170(client->header.semaphore);
    return 0;
}

// FUN_00507430 NONMATCHING
int sceSifCheckStatRpc(SifRpcClientData_t* client)
{
    SifRpcPacket_t* packet;

    packet = (SifRpcPacket_t*)client->header.packet;
    if (packet == 0)
        goto fail;
    if (client->header.rpc_id != (u_int)packet->rpc_id)
        goto fail;
    if (packet->record_id & SIF_RPC_PACKET_BUSY)
        goto success;
fail:
    return 0;
success:
    return 1;
}

// FUN_00507470 NONMATCHING
void sceSifSetRpcQueue(SifRpcDataQueue_t* queue, int thread_id)
{
    SifRpcDataQueue_t* tail;

    func_0050d3a0();
    queue->thread_id = thread_id;
    queue->active = 0;
    queue->servers = 0;
    queue->request_head = 0;
    queue->request_tail = 0;
    queue->next = 0;
    if (sRpcState.queues == 0)
    {
        sRpcState.queues = queue;
    }
    else
    {
        tail = sRpcState.queues;
        while (tail->next != 0)
        {
            tail = tail->next;
        }
        tail->next = queue;
    }
    func_0050d3f0();
}

// FUN_00507508 NONMATCHING
void sceSifRegisterRpc(SifRpcServerData_t* server, int server_id, SifRpcFunc_t function, void* buffer, SifRpcFunc_t callback_function, void* callback_buffer, SifRpcDataQueue_t* queue)
{
    SifRpcServerData_t* tail;

    func_0050d3a0();
    server->server_id = server_id;
    server->function = function;
    server->buffer = buffer;
    server->callback_function = callback_function;
    server->callback_buffer = callback_buffer;
    server->queue = queue;
    server->link = 0;
    server->next = 0;
    if (queue->servers == 0)
    {
        queue->servers = server;
    }
    else
    {
        tail = queue->servers;
        while (tail->link != 0)
        {
            tail = tail->link;
        }
        tail->link = server;
    }
    func_0050d3f0();
}

// FUN_005075D8 NONMATCHING
SifRpcServerData_t* sceSifRemoveRpc(SifRpcServerData_t* server, SifRpcDataQueue_t* queue)
{
    SifRpcServerData_t* previous;

    func_0050d3a0();
    previous = queue->servers;
    if (previous == server)
    {
        queue->servers = server->link;
    }
    else
    {
        while (previous != 0 && previous->link != server)
        {
            previous = previous->link;
        }
        if (previous != 0)
        {
            previous->link = server->link;
        }
    }
    func_0050d3f0();
    return previous;
}

// FUN_00507670 NONMATCHING
SifRpcDataQueue_t* sceSifRemoveRpcQueue(SifRpcDataQueue_t* queue)
{
    SifRpcDataQueue_t* previous;

    func_0050d3a0();
    previous = sRpcState.queues;
    if (previous == queue)
    {
        sRpcState.queues = queue->next;
    }
    else
    {
        while (previous != 0 && previous->next != queue)
        {
            previous = previous->next;
        }
        if (previous != 0)
        {
            previous->next = queue->next;
        }
    }
    func_0050d3f0();
    return previous;
}

// FUN_00507700 NONMATCHING
SifRpcServerData_t* sceSifGetNextRequest(SifRpcDataQueue_t* queue)
{
    SifRpcServerData_t* server;

    func_0050d3a0();
    server = queue->request_head;
    if (server != 0)
    {
        queue->active = 1;
        queue->request_head = server->next;
        if (queue->request_head == 0)
        {
            queue->request_tail = 0;
        }
    }
    else
    {
        queue->active = 0;
    }
    func_0050d3f0();
    return server;
}

// FUN_00507758 NONMATCHING
void sceSifExecRequest(SifRpcServerData_t* server)
{
    SifRpcEndPacket_t* end;
    void* result;

    result = server->function(server->rpc_number, server->buffer, server->size);
    if (server->size > 0)
    {
        sceSifWriteBackDCache(server->buffer, server->size);
    }
    if (server->receive_size > 0)
    {
        sceSifWriteBackDCache(result, server->receive_size);
    }
    func_0050d3a0();
    end = (SifRpcEndPacket_t*)sif_rpc_allocate_receive_packet();
    func_0050d3f0();
    end->client = server->client;
    end->command = SIF_CMD_RPC_CALL;
    if (server->receive_mode)
    {
        sif_rpc_send(SIF_CMD_RPC_END, end, result, server->receive_buffer, server->receive_size);
    }
    end->header.rpc_id = 0;
    end->header.record_id = 0;
}

// FUN_00507920 NONMATCHING
void sceSifRpcLoop(SifRpcDataQueue_t* queue)
{
    SifRpcServerData_t* server;

    for (;;)
    {
        while ((server = sceSifGetNextRequest(queue)) != 0)
        {
            sceSifExecRequest(server);
        }
    }
}

// FUN_00507960 NONMATCHING
void FUN_00507960(void)

{
  u8 auStack_40 [4];
  u32 uStack_3c;
  u32 uStack_38;
  char *pcStack_2c;
  
  if (DAT_0077f548 == -1) {
    uStack_3c = 1;
    pcStack_2c = s_SceStdioIobSema_007bdd40;
    uStack_38 = 1;
    DAT_0077f548 = CreateSema(auStack_40);
    pcStack_2c = s_SceStdioQueSema_007bdd50;
    DAT_0077f54c = CreateSema(auStack_40);
  }
  return;
}
// FUN_005079D0 NONMATCHING
int FUN_005079d0(void)

{
  int *piVar1;
  u8 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  FUN_00507960();
  WaitSema(DAT_0077f548);
  puVar2 = (u8 *)(&DAT_00969a00);
  do {
    piVar1 = (int *)(puVar2 + 4);
    puVar2 = puVar2 + 0x10;
    if (*piVar1 != 0) {
      iVar3 = iVar3 + 1;
    }
  } while (puVar2 < (u8 *)&DAT_00969c00);
  SignalSema(DAT_0077f548);
  return iVar3;
}
// FUN_00507A50 NONMATCHING
u8 * FUN_00507a50(void)

{
  u32 uVar1;
  int iVar2;
  u8 *puVar3;
  
  FUN_00507960();
  WaitSema(DAT_0077f548);
  uVar1 = DAT_0077f548;
  puVar3 = (u8 *)(&DAT_00969a00);
  iVar2 = DAT_00969a04;
  while( true ) {
    if (iVar2 == 0) {
      *(u32 *)(puVar3 + 4) = 0x10000000;
      SignalSema(uVar1);
      return puVar3;
    }
    if ((u8 *)0x969bff < puVar3 + 0x10) break;
    iVar2 = *(int *)(puVar3 + 0x14);
    puVar3 = puVar3 + 0x10;
  }
  SignalSema(DAT_0077f548);
  return (u8 *)0x0;
}
// FUN_00507AD8 NONMATCHING
int FUN_00507ad8(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
                u32 param_5,u32 param_6,u32 param_7,u32 param_8)


{
  int param_10 = 0;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 1;
  while( true ) {
    iVar1 = FUN_00507230(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    iVar1 = -(iVar1 >> 0x1f);
    if (iVar1 == 0) {
      return 0;
    }
    if (param_10 != 0) break;
    FUN_005041d8(iVar2 * 1000);
    if (iVar2 < 0x7f) {
      iVar2 = iVar2 << 1;
    }
    iVar3 = iVar3 + 1;
    if (100 < iVar3) {
      return iVar1;
    }
  }
  return iVar1;
}
// FUN_00507BC8 NONMATCHING
u8 * FUN_00507bc8(void)

{
  u32 param_1 = 0;
  u8 *puVar1;
  
  FUN_00507960();
  WaitSema(DAT_0077f548);
  if (param_1 < 0x20) {
    puVar1 = (u8 *)(&DAT_00969a00 + (int)param_1 * 0x10);
    SignalSema(DAT_0077f548);
  }
  else {
    SignalSema(DAT_0077f548);
    puVar1 = (u8 *)0x0;
  }
  return puVar1;
}
// FUN_00507C38 NONMATCHING
void FUN_00507c38(int param_1)

{
  int iVar1;
  u64 *puVar2;
  int iVar3;
  int *piVar4;
  u8 *puVar5;
  int *piVar6;
  u64 uVar7;
  u8 *puVar8;
  u64 uVar9;
  u32 uVar10;
  int iVar11;
  u64 uVar12;
  int *piVar13;
  
  iVar1 = 0;
  if (DAT_0077f540 != 0) {
    iVar1 = *(int *)(param_1 + 0xc);
  }
  DAT_0077f538 = iVar1;
  piVar13 = (int *)((u32)((u8 *)&DAT_00969180 + iVar1 * 0x440) | 0x20000000);
  iVar1 = *piVar13;
  iVar11 = piVar13[1];
  piVar4 = (int *)piVar13[2];
  if (-1 < iVar1) {
    FUN_00521250(piVar4,piVar13 + 4,piVar13[3]);
  }
  switch(iVar11) {
  case 2:
    if (0 < piVar13[5]) {
      uVar10 = piVar13[7];
      iVar11 = 0;
      if (0 < piVar13[5]) {
        piVar4 = piVar13 + 9;
        do {
          puVar8 = (u8 *)((uVar10 | 0x20000000) + iVar11);
          iVar3 = *piVar4;
          puVar5 = (u8 *)(uVar10 + iVar11);
          iVar11 = iVar11 + 1;
          *puVar8 = (char)iVar3;
          *puVar5 = (char)iVar3;
          piVar4 = (int *)((int)(piVar13 + 9) + iVar11);
        } while (iVar11 < piVar13[5]);
      }
    }
    if (0 < piVar13[6]) {
      uVar10 = piVar13[8];
      iVar11 = 0;
      if (0 < piVar13[6]) {
        piVar4 = piVar13 + 0x19;
        do {
          puVar8 = (u8 *)((uVar10 | 0x20000000) + iVar11);
          iVar3 = *piVar4;
          puVar5 = (u8 *)(uVar10 + iVar11);
          iVar11 = iVar11 + 1;
          *puVar8 = (char)iVar3;
          *puVar5 = (char)iVar3;
          piVar4 = (int *)((int)(piVar13 + 0x19) + iVar11);
        } while (iVar11 < piVar13[6]);
        goto LAB_00507f6c;
      }
    }
    break;
  case 0xb:
    if (*piVar4 < 1) goto LAB_00507f6c;
    piVar4 = (int *)piVar13[5];
    piVar6 = piVar13 + 6;
    if (((u32)piVar4 & 7) == 0) {
      do {
        uVar7 = *(u64 *)(piVar6 + 2);
        uVar9 = *(u64 *)(piVar6 + 4);
        uVar12 = *(u64 *)(piVar6 + 6);
        *(u64 *)piVar4 = *(u64 *)piVar6;
        *(u64 *)(piVar4 + 2) = uVar7;
        *(u64 *)(piVar4 + 4) = uVar9;
        *(u64 *)(piVar4 + 6) = uVar12;
        piVar6 = piVar6 + 8;
        piVar4 = piVar4 + 8;
      } while (piVar6 != piVar13 + 0x56);
    }
    else {
      do {
        uVar7 = *(u64 *)(piVar6 + 2);
        uVar9 = *(u64 *)(piVar6 + 4);
        uVar12 = *(u64 *)(piVar6 + 6);
        *(u64 *)piVar4 = *(u64 *)piVar6;
        *(u64 *)(piVar4 + 2) = uVar7;
        *(u64 *)(piVar4 + 4) = uVar9;
        *(u64 *)(piVar4 + 6) = uVar12;
        piVar6 = piVar6 + 8;
        piVar4 = piVar4 + 8;
      } while (piVar6 != piVar13 + 0x56);
    }
    *piVar4 = *piVar6;
    break;
  case 0xc:
    puVar2 = (u64 *)piVar13[5];
    uVar7 = *(u64 *)(piVar13 + 8);
    uVar9 = *(u64 *)(piVar13 + 10);
    uVar12 = *(u64 *)(piVar13 + 0xc);
    *puVar2 = *(u64 *)(piVar13 + 6);
    puVar2[1] = uVar7;
    puVar2[2] = uVar9;
    puVar2[3] = uVar12;
    uVar7 = *(u64 *)(piVar13 + 0x10);
    uVar9 = *(u64 *)(piVar13 + 0x12);
    uVar12 = *(u64 *)(piVar13 + 0x14);
    puVar2[4] = *(u64 *)(piVar13 + 0xe);
    puVar2[5] = uVar7;
    puVar2[6] = uVar9;
    puVar2[7] = uVar12;
    goto LAB_00507f6c;
  case 0x17:
  case 0x19:
  case 0x1a:
    uVar10 = piVar13[6];
    if (0x400 < uVar10) {
      uVar10 = 0x400;
    }
    FUN_00521250(piVar13[5],piVar13 + 7,uVar10);
  }
LAB_00507f6c:
  if (iVar1 < 0) {
    if (DAT_0077f4b8 == -iVar1) {
      DAT_0077f4b8 = -1;
    }
    else {
      iVar11 = 1;
      do {
        if (0x1f < iVar11) {
          return;
        }
        piVar4 = (int *)(&DAT_0077f4b8 + iVar11);
        iVar11 = iVar11 + 1;
      } while (*piVar4 != -iVar1);
      *piVar4 = -1;
    }
  }
  else {
    iSignalSema();
  }
  return;
}
// FUN_00507FF0 NONMATCHING
void FUN_00507ff0(void)

{
  u8 auStack_40 [4];
  u32 uStack_3c;
  u32 uStack_38;
  char *pcStack_2c;
  
  if (DAT_0077f544 == -1) {
    uStack_3c = 1;
    pcStack_2c = s_SceStdioFioSema_007bddc8;
    uStack_38 = 1;
    DAT_0077f544 = CreateSema(auStack_40);
  }
  return;
}
#pragma schedule on
// FUN_00508048
u64 FUN_00508048(u32 param_1)

{
  FUN_00507ff0();
  WaitSema(*(u32 *)DAT_0077f544_abs);
  return 0;
}
#pragma schedule off
#pragma schedule on
#pragma tailcall on
// FUN_00508078
void FUN_00508078(void)

{
  SignalSema(*(u32 *)DAT_0077f544_abs);
  return;
}
#pragma tailcall off
#pragma schedule off
#pragma schedule on
// FUN_00508088 NONMATCHING
u32 FUN_00508088(u32 param_1,u32 param_2)
{
  u32 result;
  u32 *base;

  base = (u32 *)DAT_00969c80_abs;
  FUN_00508048(0x1b);
  if (*(u32 *)DAT_0077f53c_abs == 0) {
    FUN_00508170();
  }
  result = base[0];
  base[1] = param_2;
  base[0] = param_1;
  if (FUN_0050d3a0() != 0) {
    FUN_0050d3f0();
  }
  FUN_00508078();
  return result;
}
#pragma schedule off
// FUN_00508128 NONMATCHING
void FUN_00508128(u64 param_1,u32 *param_2)

{
  void (*callback)(u32);
  
  callback = (void (*)(u32))*param_2;
  if (callback != (void (*)(u32))0) {
    (*callback)(param_2[1]);
  }
  SYNC(0);
  EI();
  return;
}
// FUN_00508170 NONMATCHING
u32 FUN_00508170(void)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  u8 *puVar4;
  
  FUN_005068a8(0);
  DAT_00969c80 = 0;
  DAT_00969c84 = 0;
  lVar3 = FUN_0050d3a0();
  FUN_00506430(0xffffffff80000011,0x507c38,0x969c40);
  FUN_00506430(0xffffffff80000013,0x508128,0x969c80);
  if (lVar3 != 0) {
    FUN_0050d3f0();
  }
  while( true ) {
    lVar3 = FUN_00507050(0x969c00,0xffffffff80000001,0);
    if (lVar3 < 0) {
      return 0xffffffea;
    }
    iVar1 = 0x100000;
    if (DAT_00969c24 != 0) break;
    do {
      iVar1 = iVar1 + -1;
    } while (iVar1 != -1);
  }
  FUN_00507960();
  WaitSema(DAT_0077f548);
  puVar4 = (u8 *)(&DAT_00969a00);
  do {
    *(u32 *)(puVar4 + 4) = 0;
    puVar4 = puVar4 + 0x10;
  } while (puVar4 < (u8 *)&DAT_00969c00);
  SignalSema(DAT_0077f548);
  DAT_009684c0 = (u32)(&DAT_00969180);
  DAT_009684c4 = (u32)(&DAT_009695c0);
  lVar3 = FUN_00507ad8(0x969c00,0xff,0,0x9684c0,8,0x969140,8,0);
  if (lVar3 < 0) {
    uVar2 = 0xfffeffff;
  }
  else {
    DAT_00969c28 = DAT_20969140;
    DAT_0077f53c = 1;
    uVar2 = 0;
    DAT_0077f540 = (u32)(DAT_20969144 == 2);
  }
  return uVar2;
}
// FUN_00508378 NONMATCHING
bool FUN_00508378(void)

{
  long lVar1;
  bool bVar2;
  
  bVar2 = false;
  lVar1 = FUN_005211b8(0x969c28,0x77f48c,4);
  if (lVar1 != 0) {
    lVar1 = FUN_005211b8(0x969c28,PTR_DAT_0077f550,4);
    if (lVar1 != 0) {
      lVar1 = FUN_005211b8(0x77f48c,PTR_DAT_0077f550,4);
      bVar2 = lVar1 != 0;
    }
  }
  return bVar2;
}
// FUN_00508408 NONMATCHING
u64 FUN_00508408(void)

{
  DAT_0077f53c = 0;
  FUN_00521408(0x969c28,0,4);
  return 0;
}
// FUN_00508440 NONMATCHING
u32 FUN_00508440(u32 param_1,u32 param_2)

{
  u32 uVar1;
  long lVar2;
  
  FUN_00508048(0xfe);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
  }
  lVar2 = FUN_00508378();
  if (lVar2 == 0) {
    lVar2 = FUN_005079d0();
    if (lVar2 == 0) {
      if (((((param_1 & 0x3fff) == 0) && (param_1 != 0)) && (param_1 < 0x100000)) &&
         ((param_2 != 0 && (param_2 < 0x21)))) {
        DAT_00968504 = (u32)param_2;
        DAT_00968500 = param_1;
        lVar2 = FUN_00507ad8(0x969c00,0xfe,0,0x968500,8,0x969140,4,0);
        uVar1 = DAT_20969140;
        if (lVar2 < 0) {
          FUN_00508078();
          uVar1 = 0xfffffff5;
        }
        else {
          FUN_00508078();
        }
      }
      else {
        FUN_00508078();
        uVar1 = 0xffffffea;
      }
    }
    else {
      FUN_00508078();
      uVar1 = 0xfffffff0;
    }
  }
  else {
    FUN_00508078();
    uVar1 = 0xfffefffc;
  }
  return uVar1;
}
// FUN_00508580 NONMATCHING
u32 FUN_00508580(u32 param_1)

{
  u32 uVar1;
  long lVar2;
  
  FUN_00508048(0xfd);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
  }
  lVar2 = FUN_00508378();
  if (lVar2 == 0) {
    lVar2 = FUN_005079d0();
    if (lVar2 == 0) {
      DAT_00968500 = param_1;
      lVar2 = FUN_00507ad8(0x969c00,0xfd,0,0x968500,8,0x969140,4,0);
      uVar1 = DAT_20969140;
      if (lVar2 < 0) {
        FUN_00508078();
        uVar1 = 0xfffffff5;
      }
      else {
        FUN_00508078();
      }
    }
    else {
      FUN_00508078();
      uVar1 = 0xfffffff0;
    }
  }
  else {
    FUN_00508078();
    uVar1 = 0xfffefffc;
  }
  return uVar1;
}
// FUN_00508670 NONMATCHING
int FUN_00508670(char *param_1,u32 param_2,u32 param_3)

{
  char cVar1;
  u32 uVar2;
  int iVar3;
  long lVar4;
  u64 uVar5;
  int iVar6;
  int *piVar7;
  u8 auStack_140 [4];
  u32 uStack_13c;
  u32 uStack_138;
  char *pcStack_12c;
  int aiStack_120 [4];
  
  FUN_00508048(0);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
  }
  lVar4 = FUN_00508378();
  if (lVar4 == 0) {
    lVar4 = (long)(FUN_00507a50());
    if (lVar4 == 0) {
      FUN_00508078();
      iVar6 = -0x13;
    }
    else {
      DAT_00968514 = *param_1;
      iVar6 = 0;
      if (DAT_00968514 != '\0') {
        for (iVar6 = 1;
            (iVar6 < 0x400 &&
            (cVar1 = param_1[iVar6], (&DAT_00968514)[iVar6] = cVar1, cVar1 != '\0'));
            iVar6 = iVar6 + 1) {
        }
      }
      if (iVar6 == 0x400) {
        DAT_00968913 = 0;
      }
      piVar7 = (int *)lVar4;
      iVar6 = (int)(piVar7 + -0x25a680) >> 4;
      DAT_0096850c = param_2 & 0x7fffffff;
      uStack_13c = 1;
      pcStack_12c = s_SceStdioOpenSema_007bdde0;
      uStack_138 = 0;
      DAT_00968510 = param_3;
      DAT_00968914 = iVar6;
      uVar5 = CreateSema(auStack_140);
      DAT_00968500 = (u32)uVar5;
      DAT_00968508 = 4;
      DAT_00968504 = (u32)(aiStack_120);
      lVar4 = FUN_00507ad8(0x969c00,0,0,0x968500,0x418,0x969140,4,0);
      iVar3 = DAT_20969140;
      if (lVar4 < 0) {
        DeleteSema(uVar5);
        FUN_00508078();
        iVar6 = -0xb;
      }
      else {
        FUN_00508078();
        if (iVar3 == 0) {
          DeleteSema(uVar5);
          iVar6 = -0xb;
        }
        else {
          WaitSema(uVar5);
          DeleteSema(uVar5);
          if (aiStack_120[0] < 0) {
            WaitSema(DAT_0077f548);
            piVar7[1] = 0;
            SignalSema(DAT_0077f548);
            iVar6 = aiStack_120[0];
          }
          else {
            WaitSema(DAT_0077f548);
            uVar2 = DAT_0077f548;
            piVar7[1] = piVar7[1] | param_2;
            *piVar7 = aiStack_120[0];
            SignalSema(uVar2);
          }
        }
      }
    }
  }
  else {
    FUN_00508078();
    iVar6 = -0x10004;
  }
  return iVar6;
}
// FUN_00508900 NONMATCHING
int FUN_00508900(void)

{
  int iVar1;
  long lVar2;
  u64 uVar3;
  u32 *puVar4;
  u8 auStack_90 [4];
  u32 uStack_8c;
  u32 uStack_88;
  char *pcStack_7c;
  int aiStack_70 [4];
  
  lVar2 = (long)FUN_00507bc8();
  FUN_00508048(1);
  if (((DAT_0077f53c == 0) || (lVar2 == 0)) || (puVar4 = (u32 *)lVar2, puVar4[1] == 0)) {
    FUN_00508078();
    aiStack_70[0] = -9;
  }
  else {
    DAT_0096850c = *puVar4;
    DAT_00968510 = (int)(puVar4 + -0x25a680) >> 4;
    uStack_8c = 1;
    pcStack_7c = s_SceStdioCloseSema_007bddf8;
    uStack_88 = 0;
    uVar3 = CreateSema(auStack_90);
    DAT_00968504 = (u32)(aiStack_70);
    DAT_00968500 = (u32)uVar3;
    DAT_00968508 = 4;
    lVar2 = FUN_00507ad8(0x969c00,1,0,0x968500,0x14,0x969140,4,0);
    if (lVar2 < 0) {
      DeleteSema(uVar3);
      FUN_00508078();
      aiStack_70[0] = -0xb;
    }
    else {
      puVar4[1] = 0;
      iVar1 = DAT_20969140;
      FUN_00508078();
      if (iVar1 == 0) {
        DeleteSema(uVar3);
        aiStack_70[0] = -0xb;
      }
      else {
        WaitSema(uVar3);
        DeleteSema(uVar3);
        if (-1 < aiStack_70[0]) {
          aiStack_70[0] = 0;
        }
      }
    }
  }
  return aiStack_70[0];
}
// FUN_00508A78 NONMATCHING
u32 FUN_00508a78(u64 param_1,u32 param_2,u32 param_3)

{
  long lVar1;
  u64 uVar2;
  int *piVar3;
  int iVar4;
  u32 *puVar5;
  u32 uVar6;
  u8 auStack_b0 [4];
  u32 uStack_ac;
  u32 uStack_a8;
  char *pcStack_9c;
  u32 auStack_90 [4];
  
  lVar1 = (long)FUN_00507bc8();
  FUN_00508048(4);
  if ((DAT_0077f53c != 0) && (lVar1 != 0)) {
    puVar5 = (u32 *)lVar1;
    if (puVar5[1] != 0) {
      DAT_0096850c = *puVar5;
      DAT_00968518 = (int)(puVar5 + -0x25a680) >> 4;
      uStack_ac = 1;
      pcStack_9c = s_SceStdioLseekSema_007bde10;
      uVar6 = puVar5[1] & 0x8000;
      uStack_a8 = 0;
      DAT_00968510 = param_2;
      _DAT_00968514 = param_3;
      uVar2 = CreateSema(auStack_b0);
      DAT_00968504 = (u32)(auStack_90);
      DAT_00968508 = 4;
      DAT_00968500 = (int)uVar2;
      if (uVar6 == 0) {
        uVar6 = 0;
      }
      else {
        WaitSema(DAT_0077f54c);
        if (DAT_0077f4b8 == -1) {
          DAT_0077f4b8 = DAT_00968500;
          DAT_00968500 = -DAT_00968500;
        }
        else {
          iVar4 = 1;
          do {
            if (0x1f < iVar4) goto LAB_00508bd0;
            piVar3 = (int *)(&DAT_0077f4b8 + iVar4);
            iVar4 = iVar4 + 1;
          } while (*piVar3 != -1);
          *piVar3 = DAT_00968500;
          DAT_00968500 = -DAT_00968500;
        }
LAB_00508bd0:
        SignalSema(DAT_0077f54c);
      }
      lVar1 = FUN_00507ad8(0x969c00,4,0,0x968500,0x1c,0x969140,4,0);
      iVar4 = DAT_20969140;
      if (lVar1 < 0) {
        DeleteSema(uVar2);
        FUN_00508078();
        return 0xfffffff5;
      }
      FUN_00508078();
      if (iVar4 == 0) {
        DeleteSema(uVar2);
        return 0xfffffff5;
      }
      if (uVar6 != 0) {
        DeleteSema(uVar2);
        return 0;
      }
      WaitSema(uVar2);
      DeleteSema(uVar2);
      return auStack_90[0];
    }
  }
  FUN_00508078();
  return 0xfffffff7;
}
// FUN_00508CB8 NONMATCHING
u32 FUN_00508cb8(u64 param_1,u64 param_2,u64 param_3)

{
  u32 uVar1;
  long lVar2;
  u64 uVar3;
  int *piVar4;
  int iVar5;
  u32 *puVar6;
  u32 uVar7;
  u8 auStack_d0 [4];
  u32 uStack_cc;
  u32 uStack_c8;
  char *pcStack_bc;
  u32 auStack_b0 [4];
  
  lVar2 = (long)FUN_00507bc8();
  FUN_00508048(2);
  if ((DAT_0077f53c != 0) && (lVar2 != 0)) {
    puVar6 = (u32 *)lVar2;
    uVar1 = puVar6[1];
    if (uVar1 != 0) {
      DAT_0096850c = *puVar6;
      DAT_0096851c = (int)(puVar6 + -0x25a680) >> 4;
      uStack_cc = 1;
      pcStack_bc = s_SceStdioReadSema_007bde28;
      uVar7 = uVar1 & 0x8000;
      DAT_00968510 = (u32)param_2;
      _DAT_00968514 = (u32)param_3;
      uStack_c8 = 0;
      uVar3 = CreateSema(auStack_d0);
      DAT_00968504 = (u32)(auStack_b0);
      DAT_00968508 = 4;
      DAT_00968500 = (int)uVar3;
      if (uVar7 == 0) {
        uVar7 = 0;
      }
      else {
        WaitSema(DAT_0077f54c);
        if (DAT_0077f4b8 == -1) {
          DAT_0077f4b8 = DAT_00968500;
          DAT_00968500 = -DAT_00968500;
        }
        else {
          iVar5 = 1;
          do {
            if (0x1f < iVar5) goto LAB_00508e14;
            piVar4 = (int *)(&DAT_0077f4b8 + iVar5);
            iVar5 = iVar5 + 1;
          } while (*piVar4 != -1);
          *piVar4 = DAT_00968500;
          DAT_00968500 = -DAT_00968500;
        }
LAB_00508e14:
        SignalSema(DAT_0077f54c);
      }
      if ((uVar1 & 0x20000000) == 0) {
        FUN_005067f8(param_2,param_3);
      }
      FUN_005067f8(0x968500,0x20);
      lVar2 = FUN_00507ad8(0x969c00,2,0,0x968500,0x20,0x969140,4,0);
      iVar5 = DAT_20969140;
      if (lVar2 < 0) {
        DeleteSema(uVar3);
        FUN_00508078();
        return 0xfffffff5;
      }
      FUN_00508078();
      if (iVar5 == 0) {
        DeleteSema(uVar3);
        return 0xfffffff5;
      }
      if (uVar7 != 0) {
        DeleteSema(uVar3);
        return 0;
      }
      WaitSema(uVar3);
      DeleteSema(uVar3);
      return auStack_b0[0];
    }
  }
  FUN_00508078();
  return 0xfffffff7;
}
// FUN_00508F28 NONMATCHING
u32 FUN_00508f28(u64 param_1,u32 param_2,int param_3)

{
  u32 uVar1;
  u8 *puVar2;
  long lVar3;
  u64 uVar4;
  u8 *puVar5;
  int *piVar6;
  int iVar7;
  u32 *puVar8;
  u32 uVar9;
  int iVar10;
  u32 uVar11;
  u8 auStack_d0 [4];
  u32 uStack_cc;
  u32 uStack_c8;
  char *pcStack_bc;
  u32 auStack_b0 [4];
  
  lVar3 = (long)FUN_00507bc8();
  FUN_00508048(3);
  if ((*(u32 *)DAT_0077f53c_abs != 0) && (lVar3 != 0)) {
    puVar8 = (u32 *)lVar3;
    uVar1 = puVar8[1];
    if (uVar1 != 0) {
      DAT_0096850c = *puVar8;
      DAT_0096852c = (int)(puVar8 + -0x25a680) >> 4;
      uStack_cc = 1;
      pcStack_bc = s_SceStdioWriteSema_007bde40;
      uVar9 = uVar1 & 0x8000;
      uVar11 = (u32)param_2;
      uStack_c8 = 0;
      DAT_00968510 = uVar11;
      _DAT_00968514 = param_3;
      uVar4 = CreateSema(auStack_d0);
      DAT_00968504 = (u32)(auStack_b0);
      DAT_00968508 = 4;
      DAT_00968500 = (int)uVar4;
      if (uVar9 == 0) {
        uVar9 = 0;
      }
      else {
        WaitSema(DAT_0077f54c);
        if (DAT_0077f4b8 == -1) {
          DAT_0077f4b8 = DAT_00968500;
          DAT_00968500 = -DAT_00968500;
        }
        else {
          iVar10 = 1;
          do {
            if (0x1f < iVar10) goto LAB_00509084;
            piVar6 = (int *)(&DAT_0077f4b8 + iVar10);
            iVar10 = iVar10 + 1;
          } while (*piVar6 != -1);
          *piVar6 = DAT_00968500;
          DAT_00968500 = -DAT_00968500;
        }
LAB_00509084:
        SignalSema(DAT_0077f54c);
      }
      if ((param_2 & 0xf) == 0) {
        iVar10 = 0;
      }
      else {
        iVar10 = (uVar11 & 0xfffffff0) - (uVar11 - 0x10);
      }
      if (param_3 < iVar10) {
        iVar10 = param_3;
      }
      if ((uVar1 & 0x20000000) == 0) {
        FUN_005067f8(param_2,param_3);
      }
      iVar7 = 0;
      DAT_00968518 = iVar10;
      if (0 < iVar10) {
        do {
          puVar2 = (u8 *)((uVar11 | 0x20000000) + iVar7);
          puVar5 = (u8 *)((int)&DAT_0096851c + iVar7);
          iVar7 = iVar7 + 1;
          *puVar5 = *puVar2;
        } while (iVar7 < iVar10);
      }
      lVar3 = FUN_00507ad8(0x969c00,3,0,0x968500,0x30,0x969140,4,0);
      iVar10 = DAT_20969140;
      if (lVar3 < 0) {
        DeleteSema(uVar4);
        FUN_00508078();
        return 0xfffffff5;
      }
      FUN_00508078();
      if (iVar10 == 0) {
        DeleteSema(uVar4);
        return 0xfffffff5;
      }
      if (uVar9 != 0) {
        DeleteSema(uVar4);
        return 0;
      }
      WaitSema(uVar4);
      DeleteSema(uVar4);
      return auStack_b0[0];
    }
  }
  FUN_00508078();
  return 0xfffffff7;
}
// FUN_005091E8 NONMATCHING
u32 FUN_005091e8(u64 param_1,long param_2,u64 *param_3)

{
  u64 *puVar1;
  long lVar2;
  u64 uVar3;
  int *piVar4;
  int iVar5;
  u64 *puVar6;
  u64 uVar7;
  u64 uVar8;
  u32 *puVar9;
  u8 auStack_b0 [4];
  u32 uStack_ac;
  u32 uStack_a8;
  char *pcStack_9c;
  u32 auStack_90 [4];
  
  lVar2 = (long)FUN_00507bc8();
  FUN_00508048(5);
  DAT_009684c8 = (u32)(param_3);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
  }
  if ((lVar2 == 0) || (puVar9 = (u32 *)lVar2, puVar9[1] == 0)) {
    FUN_00508078();
    return 0xfffffff7;
  }
  DAT_00968914 = 0;
  DAT_00968918 = 0;
  if (param_2 == 2) {
    *(u32 *)param_3 = *(u32 *)(DAT_0077f538 * 0x440 + 0x969190U | 0x20000000);
  }
  else if (param_2 < 3) {
    if (param_2 != 1) {
      DAT_0096850c = *puVar9;
LAB_00509388:
      DAT_00968510 = (u32)param_2;
      if (param_3 == (u64 *)0x0) {
        DAT_0096891c = 0;
      }
      else {
        puVar6 = (u64 *)&DAT_00968514;
        DAT_0096891c = 0x400;
        if ((((u32)param_3 | 0x968514) & 7) == 0) {
          puVar1 = param_3 + 0x80;
          do {
            uVar3 = param_3[1];
            uVar7 = param_3[2];
            uVar8 = param_3[3];
            *puVar6 = *param_3;
            puVar6[1] = uVar3;
            puVar6[2] = uVar7;
            puVar6[3] = uVar8;
            param_3 = param_3 + 4;
            puVar6 = puVar6 + 4;
          } while (param_3 != puVar1);
        }
        else {
          puVar1 = param_3 + 0x80;
          do {
            uVar3 = param_3[1];
            uVar7 = param_3[2];
            uVar8 = param_3[3];
            *puVar6 = *param_3;
            puVar6[1] = uVar3;
            puVar6[2] = uVar7;
            puVar6[3] = uVar8;
            param_3 = param_3 + 4;
            puVar6 = puVar6 + 4;
          } while (param_3 != puVar1);
        }
      }
      uStack_ac = 1;
      pcStack_9c = s_SceStdioIoctlSema_007bde58;
      uStack_a8 = 0;
      uVar3 = CreateSema(auStack_b0);
      DAT_00968508 = 4;
      DAT_00968500 = (u32)uVar3;
      DAT_00968504 = (u32)(auStack_90);
      FUN_005067f8(0x968500,0x420);
      lVar2 = FUN_00507ad8(0x969c00,5,0,0x968500,0x420,0x969140,4,0);
      iVar5 = DAT_20969140;
      if (lVar2 < 0) {
        DeleteSema(uVar3);
        FUN_00508078();
        return 0xfffffff5;
      }
      FUN_00508078();
      if (iVar5 == 0) {
        DeleteSema(uVar3);
        return 0xfffffff5;
      }
      WaitSema(uVar3);
      DeleteSema(uVar3);
      return auStack_90[0];
    }
    WaitSema(DAT_0077f54c);
    iVar5 = 0;
    if (DAT_0077f4b8 == -1) {
      piVar4 = (int *)(&DAT_0077f4b8);
      iVar5 = 1;
      while ((piVar4 = piVar4 + 1, iVar5 < 0x20 && (*piVar4 == -1))) {
        iVar5 = iVar5 + 1;
      }
    }
    if (iVar5 == 0x20) {
      *(u32 *)DAT_009684c8 = 0;
    }
    else {
      *(u32 *)DAT_009684c8 = 1;
    }
    SignalSema(DAT_0077f54c);
  }
  else {
    if (param_2 != 3) {
      DAT_0096850c = *puVar9;
      goto LAB_00509388;
    }
    *param_3 = *(u64 *)(DAT_0077f538 * 0x440 + 0x969190U | 0x20000000);
  }
  FUN_00508078();
  return 0;
}

// FUN_00509570 NONMATCHING
u32
FUN_00509570(u64 param_1,u32 param_2,long param_3,u32 param_4,u32 param_5,
            u32 param_6)

{
  int iVar1;
  long lVar2;
  u64 uVar3;
  u8 auStack_c0 [4];
  u32 uStack_bc;
  u32 uStack_b8;
  char *pcStack_ac;
  u32 auStack_a0 [4];
  
  lVar2 = (long)FUN_00507bc8();
  FUN_00508048(0x1a);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
  }
  if (lVar2 != 0) {
    if (((u32 *)lVar2)[1] != 0) {
      if ((0x400 < param_4) || (0x400 < param_6)) {
        FUN_00508078();
        return 0xffffffea;
      }
      if (param_3 != 0) {
        FUN_00521250(0x968514,param_3,param_4);
      }
      DAT_0096850c = *(u32 *)lVar2;
      DAT_0096891c = (u32)param_4;
      uStack_bc = 1;
      pcStack_ac = s_SceStdioIoctl2Sema_007bde70;
      uStack_b8 = 0;
      DAT_00968510 = param_2;
      uVar3 = CreateSema(auStack_c0);
      DAT_00968504 = (u32)(auStack_a0);
      DAT_00968918 = (u32)param_6;
      DAT_00968508 = 4;
      DAT_00968500 = (u32)uVar3;
      DAT_00968914 = param_5;
      FUN_005067f8(0x968500,0x420);
      lVar2 = FUN_00507ad8(0x969c00,0x1a,0,0x968500,0x420,0x969140,4,0);
      iVar1 = DAT_20969140;
      if (lVar2 < 0) {
        DeleteSema(uVar3);
        FUN_00508078();
        return 0xfffffff5;
      }
      FUN_00508078();
      if (iVar1 == 0) {
        DeleteSema(uVar3);
        return 0xfffffff5;
      }
      WaitSema(uVar3);
      DeleteSema(uVar3);
      return auStack_a0[0];
    }
  }
  FUN_00508078();
  return 0xfffffff7;
}
// FUN_00509758 NONMATCHING
u32 FUN_00509758(char *param_1,u32 param_2)

{
  char cVar1;
  u64 uVar2;
  long lVar3;
  int iVar4;
  u8 auStack_c0 [4];
  u32 uStack_bc;
  u32 uStack_b8;
  char *pcStack_ac;
  u32 auStack_a0 [4];
  
  FUN_00508048(param_2);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
    (*(u8*)((u8*)&DAT_0096850c + 0)) = *param_1;
  }
  else {
    (*(u8*)((u8*)&DAT_0096850c + 0)) = *param_1;
  }
  iVar4 = 0;
  if ((char)DAT_0096850c != '\0') {
    for (iVar4 = 1;
        (iVar4 < 0x400 &&
        (cVar1 = param_1[iVar4], *(char *)((int)&DAT_0096850c + iVar4) = cVar1, cVar1 != '\0'));
        iVar4 = iVar4 + 1) {
    }
  }
  if (iVar4 == 0x400) {
    DAT_0096890b = 0;
    iVar4 = 0x3ff;
  }
  uStack_bc = 1;
  pcStack_ac = s_SceStdioCCodeSema_007bde88;
  uStack_b8 = 0;
  uVar2 = CreateSema(auStack_c0);
  DAT_00968500 = (u32)uVar2;
  DAT_00968508 = 4;
  DAT_00968504 = (u32)(auStack_a0);
  lVar3 = FUN_00507ad8(0x969c00,param_2,0,0x968500,iVar4 + 0xd,0x969140,4,0);
  iVar4 = DAT_20969140;
  if (lVar3 < 0) {
    DeleteSema(uVar2);
    FUN_00508078();
    auStack_a0[0] = 0xfffffff5;
  }
  else {
    FUN_00508078();
    if (iVar4 == 0) {
      DeleteSema(uVar2);
      auStack_a0[0] = 0xfffffff5;
    }
    else {
      WaitSema(uVar2);
      DeleteSema(uVar2);
    }
  }
  return auStack_a0[0];
}
#pragma schedule on
// FUN_00509908
void FUN_00509908(char *param_1)

{
  FUN_00509758(param_1,6);
  return;
}
#pragma schedule off
// FUN_00509928 NONMATCHING
u32 FUN_00509928(char *param_1,u32 param_2)

{
  char cVar1;
  u64 uVar2;
  long lVar3;
  int iVar4;
  u8 auStack_c0 [4];
  u32 uStack_bc;
  u32 uStack_b8;
  char *pcStack_ac;
  u32 auStack_a0 [4];
  
  FUN_00508048(7);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
    (*(u8*)((u8*)&DAT_00968510 + 0)) = *param_1;
  }
  else {
    (*(u8*)((u8*)&DAT_00968510 + 0)) = *param_1;
  }
  iVar4 = 0;
  if ((char)DAT_00968510 != '\0') {
    for (iVar4 = 1;
        (iVar4 < 0x400 &&
        (cVar1 = param_1[iVar4], *(char *)((int)&DAT_00968510 + iVar4) = cVar1, cVar1 != '\0'));
        iVar4 = iVar4 + 1) {
    }
  }
  if (iVar4 == 0x400) {
    DAT_0096890f = 0;
    iVar4 = 0x3ff;
  }
  uStack_bc = 1;
  pcStack_ac = s_SceStdioMkdirSema_007bdea0;
  uStack_b8 = 0;
  DAT_0096850c = param_2;
  uVar2 = CreateSema(auStack_c0);
  DAT_00968500 = (u32)uVar2;
  DAT_00968508 = 4;
  DAT_00968504 = (u32)(auStack_a0);
  lVar3 = FUN_00507ad8(0x969c00,7,0,0x968500,iVar4 + 0x11,0x969140,4,0);
  iVar4 = DAT_20969140;
  if (lVar3 < 0) {
    DeleteSema(uVar2);
    FUN_00508078();
    auStack_a0[0] = 0xfffffff5;
  }
  else {
    FUN_00508078();
    if (iVar4 == 0) {
      DeleteSema(uVar2);
      auStack_a0[0] = 0xfffffff5;
    }
    else {
      WaitSema(uVar2);
      DeleteSema(uVar2);
    }
  }
  return auStack_a0[0];
}
#pragma schedule on
// FUN_00509AE0
void FUN_00509ae0(char *param_1)

{
  FUN_00509758(param_1,8);
  return;
}
#pragma schedule off
// FUN_00509B00 NONMATCHING
u32 FUN_00509b00(char *param_1,long param_2,int param_3,int param_4)

{
  char cVar1;
  u8 *puVar2;
  u64 uVar3;
  long lVar4;
  u8 *puVar5;
  int iVar6;
  u8 auStack_c0 [4];
  u32 uStack_bc;
  u32 uStack_b8;
  char *pcStack_ac;
  u32 auStack_a0 [4];
  
  FUN_00508048(0xe);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
    (*(u8*)((u8*)&DAT_0096850c + 0)) = *param_1;
  }
  else {
    (*(u8*)((u8*)&DAT_0096850c + 0)) = *param_1;
  }
  iVar6 = 0;
  if ((char)DAT_0096850c != '\0') {
    for (iVar6 = 1;
        (iVar6 < 0x400 &&
        (cVar1 = param_1[iVar6], *(char *)((int)&DAT_0096850c + iVar6) = cVar1, cVar1 != '\0'));
        iVar6 = iVar6 + 1) {
    }
  }
  if (iVar6 == 0x400) {
    DAT_0096890b = 0;
  }
  if (param_2 == 0) {
    DAT_0096890c = '\0';
  }
  else {
    DAT_0096890c = *(char *)param_2;
    iVar6 = 0;
    if (DAT_0096890c != '\0') {
      for (iVar6 = 1;
          (iVar6 < 0x400 &&
          (cVar1 = ((char *)param_2)[iVar6], (&DAT_0096890c)[iVar6] = cVar1, cVar1 != '\0'));
          iVar6 = iVar6 + 1) {
      }
    }
    if (iVar6 == 0x400) {
      DAT_00968d0b = 0;
    }
  }
  if (param_4 < 0x401) {
    iVar6 = 0;
    if (0 < param_4) {
      do {
        puVar2 = (u8 *)(param_3 + iVar6);
        puVar5 = (u8 *)((int)&DAT_00968d0c + iVar6);
        iVar6 = iVar6 + 1;
        *puVar5 = *puVar2;
      } while (iVar6 < param_4);
    }
    uStack_bc = 1;
    pcStack_ac = s_SceStdioFormatSema_007bdeb8;
    uStack_b8 = 0;
    DAT_0096910c = param_4;
    uVar3 = CreateSema(auStack_c0);
    DAT_00968508 = 4;
    DAT_00968500 = (u32)uVar3;
    DAT_00968504 = (u32)(auStack_a0);
    FUN_005067f8(0x968500,0xc10);
    lVar4 = FUN_00507ad8(0x969c00,0xe,0,0x968500,0xc10,0x969140,4,0);
    iVar6 = DAT_20969140;
    if (lVar4 < 0) {
      DeleteSema(uVar3);
      FUN_00508078();
      auStack_a0[0] = 0xfffffff5;
    }
    else {
      FUN_00508078();
      if (iVar6 == 0) {
        DeleteSema(uVar3);
        auStack_a0[0] = 0xfffffff5;
      }
      else {
        WaitSema(uVar3);
        DeleteSema(uVar3);
      }
    }
  }
  else {
    FUN_00508078();
    auStack_a0[0] = 0xfffffff9;
  }
  return auStack_a0[0];
}
// FUN_00509D80 NONMATCHING
u32 FUN_00509d80(u32 param_1)

{
  int iVar1;
  u64 uVar2;
  long lVar3;
  u8 auStack_80 [4];
  u32 uStack_7c;
  u32 uStack_78;
  char *pcStack_6c;
  u32 auStack_60 [4];
  
  FUN_00508048(0xf);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
  }
  uStack_7c = 1;
  pcStack_6c = s_SceStdioAddDrvSema_007bded0;
  uStack_78 = 0;
  DAT_0096850c = param_1;
  uVar2 = CreateSema(auStack_80);
  DAT_00968504 = (u32)(auStack_60);
  DAT_00968500 = (u32)uVar2;
  DAT_00968508 = 4;
  lVar3 = FUN_00507ad8(0x969c00,0xf,0,0x968500,0x10,0x969140,4,0);
  iVar1 = DAT_20969140;
  if (lVar3 < 0) {
    DeleteSema(uVar2);
    FUN_00508078();
    auStack_60[0] = 0xfffffff5;
  }
  else {
    FUN_00508078();
    if (iVar1 == 0) {
      DeleteSema(uVar2);
      auStack_60[0] = 0xfffffff5;
    }
    else {
      WaitSema(uVar2);
      DeleteSema(uVar2);
    }
  }
  return auStack_60[0];
}
#pragma schedule on
// FUN_00509EB0
void FUN_00509eb0(char *param_1)

{
  FUN_00509758(param_1,0x10);
  return;
}
#pragma schedule off
// FUN_00509ED0 NONMATCHING
int FUN_00509ed0(u64 param_1)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  
  FUN_00508048(9);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
  }
  FUN_00508078();
  lVar2 = (long)(FUN_00507a50());
  if (lVar2 == 0) {
    iVar1 = -0x13;
  }
  else {
    iVar1 = (int)(FUN_00509758((char *)param_1,9));
    piVar3 = (int *)lVar2;
    if (iVar1 < 0) {
      WaitSema(DAT_0077f548);
      piVar3[1] = 0;
    }
    else {
      WaitSema(DAT_0077f548);
      *piVar3 = iVar1;
      iVar1 = (int)(piVar3 + -0x25a680) >> 4;
    }
    SignalSema(DAT_0077f548);
  }
  return iVar1;
}
// FUN_00509F98 NONMATCHING
int FUN_00509f98(void)

{
  int iVar1;
  long lVar2;
  u64 uVar3;
  u32 *puVar4;
  u8 auStack_90 [4];
  u32 uStack_8c;
  u32 uStack_88;
  char *pcStack_7c;
  int aiStack_70 [4];
  
  lVar2 = (long)FUN_00507bc8();
  FUN_00508048(10);
  if (((DAT_0077f53c == 0) || (lVar2 == 0)) || (puVar4 = (u32 *)lVar2, puVar4[1] == 0)) {
    FUN_00508078();
    aiStack_70[0] = -9;
  }
  else {
    DAT_0096850c = *puVar4;
    uStack_8c = 1;
    pcStack_7c = s_SceStdioDcloseSema_007bdee8;
    uStack_88 = 0;
    uVar3 = CreateSema(auStack_90);
    DAT_00968504 = (u32)(aiStack_70);
    DAT_00968500 = (u32)uVar3;
    DAT_00968508 = 4;
    lVar2 = FUN_00507ad8(0x969c00,10,0,0x968500,0x14,0x969140,4,0);
    if (lVar2 < 0) {
      DeleteSema(uVar3);
      FUN_00508078();
      aiStack_70[0] = -0xb;
    }
    else {
      puVar4[1] = 0;
      iVar1 = DAT_20969140;
      FUN_00508078();
      if (iVar1 == 0) {
        DeleteSema(uVar3);
        aiStack_70[0] = -0xb;
      }
      else {
        WaitSema(uVar3);
        DeleteSema(uVar3);
        if (-1 < aiStack_70[0]) {
          aiStack_70[0] = 0;
        }
      }
    }
  }
  return aiStack_70[0];
}
// FUN_0050A100 NONMATCHING
u32 FUN_0050a100(u64 param_1,u32 param_2)

{
  int iVar1;
  long lVar2;
  u64 uVar3;
  u8 auStack_80 [4];
  u32 uStack_7c;
  u32 uStack_78;
  char *pcStack_6c;
  u32 auStack_60 [4];
  
  lVar2 = (long)FUN_00507bc8();
  FUN_00508048(0xb);
  if (((DAT_0077f53c == 0) || (lVar2 == 0)) || (((u32 *)lVar2)[1] == 0)) {
    FUN_00508078();
    auStack_60[0] = 0xfffffff7;
  }
  else {
    DAT_0096850c = *(u32 *)lVar2;
    uStack_7c = 1;
    pcStack_6c = s_SceStdioDreadSema_007bdf00;
    uStack_78 = 0;
    DAT_00968510 = param_2;
    uVar3 = CreateSema(auStack_80);
    DAT_00968504 = (u32)(auStack_60);
    DAT_00968500 = (u32)uVar3;
    DAT_00968508 = 4;
    lVar2 = FUN_00507ad8(0x969c00,0xb,0,0x968500,0x20,0x969140,4,0);
    iVar1 = DAT_20969140;
    if (lVar2 < 0) {
      WaitSema(uVar3);
      FUN_00508078();
      auStack_60[0] = 0xfffffff5;
    }
    else {
      FUN_00508078();
      if (iVar1 == 0) {
        DeleteSema(uVar3);
        auStack_60[0] = 0xfffffff5;
      }
      else {
        WaitSema(uVar3);
        DeleteSema(uVar3);
      }
    }
  }
  return auStack_60[0];
}
// FUN_0050A258 NONMATCHING
u32 FUN_0050a258(char *param_1,u32 param_2)

{
  char cVar1;
  int iVar2;
  u64 uVar3;
  long lVar4;
  int iVar5;
  u8 auStack_c0 [4];
  u32 uStack_bc;
  u32 uStack_b8;
  char *pcStack_ac;
  u32 auStack_a0 [4];
  
  FUN_00508048(0xc);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
    (*(u8*)((u8*)&DAT_00968510 + 0)) = *param_1;
  }
  else {
    (*(u8*)((u8*)&DAT_00968510 + 0)) = *param_1;
  }
  iVar2 = 0;
  cVar1 = (char)DAT_00968510;
  while (iVar5 = iVar2, cVar1 != '\0') {
    iVar5 = iVar2 + 1;
    if (0x3ff < iVar5) break;
    cVar1 = param_1[iVar5];
    *(char *)((int)&DAT_00968510 + iVar2 + 1) = cVar1;
    iVar2 = iVar5;
  }
  if (iVar5 == 0x400) {
    DAT_0096890f = 0;
    iVar5 = 0x3ff;
  }
  uStack_bc = 1;
  pcStack_ac = s_SceStdioGetstatSema_007bdf18;
  uStack_b8 = 0;
  DAT_0096850c = param_2;
  uVar3 = CreateSema(auStack_c0);
  DAT_00968500 = (u32)uVar3;
  DAT_00968508 = 4;
  DAT_00968504 = (u32)(auStack_a0);
  lVar4 = FUN_00507ad8(0x969c00,0xc,0,0x968500,iVar5 + 0x11,0x969140,4,0);
  iVar2 = DAT_20969140;
  if (lVar4 < 0) {
    DeleteSema(uVar3);
    FUN_00508078();
    auStack_a0[0] = 0xfffffff5;
  }
  else {
    FUN_00508078();
    if (iVar2 == 0) {
      DeleteSema(uVar3);
      auStack_a0[0] = 0xfffffff5;
    }
    else {
      WaitSema(uVar3);
      DeleteSema(uVar3);
    }
  }
  return auStack_a0[0];
}
// FUN_0050A410 NONMATCHING
u32 FUN_0050a410(char *param_1,u64 *param_2,u32 param_3)

{
  char cVar1;
  int iVar2;
  u64 uVar3;
  long lVar4;
  int iVar5;
  u8 auStack_d0 [4];
  u32 uStack_cc;
  u32 uStack_c8;
  char *pcStack_bc;
  u32 auStack_b0 [4];
  
  FUN_00508048(0xd);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
    (*(u8*)((u8*)&DAT_0096854c + 4)) = *param_1;
  }
  else {
    (*(u8*)((u8*)&DAT_0096854c + 4)) = *param_1;
  }
  iVar2 = 0;
  cVar1 = (*(u8*)((u8*)&DAT_0096854c + 4));
  while (iVar5 = iVar2, cVar1 != '\0') {
    iVar5 = iVar2 + 1;
    if (0x3ff < iVar5) break;
    cVar1 = param_1[iVar5];
    *(char *)((int)&DAT_0096854c + iVar2 + 5) = cVar1;
    iVar2 = iVar5;
  }
  if (iVar5 == 0x400) {
    DAT_0096894f = 0;
    iVar5 = 0x3ff;
  }
  _DAT_00968510 = *param_2;
  _DAT_00968518 = param_2[1];
  _DAT_00968520 = param_2[2];
  register0x00000070 = param_2[3];
  _DAT_00968530 = param_2[4];
  register0x00000050 = param_2[5];
  register0x00000060 = param_2[6];
  register0x00000070 = param_2[7];
  uStack_cc = 1;
  pcStack_bc = s_SceStdioChstatSema_007bdf30;
  uStack_c8 = 0;
  DAT_0096850c = param_3;
  uVar3 = CreateSema(auStack_d0);
  DAT_00968508 = 4;
  DAT_00968500 = (u32)uVar3;
  DAT_00968504 = (u32)(auStack_b0);
  FUN_005067f8(0x968500,0x450);
  lVar4 = FUN_00507ad8(0x969c00,0xd,0,0x968500,iVar5 + 0x51,0x969140,4,0);
  iVar2 = DAT_20969140;
  if (lVar4 < 0) {
    DeleteSema(uVar3);
    FUN_00508078();
    auStack_b0[0] = 0xfffffff5;
  }
  else {
    FUN_00508078();
    if (iVar2 == 0) {
      DeleteSema(uVar3);
      auStack_b0[0] = 0xfffffff5;
    }
    else {
      WaitSema(uVar3);
      DeleteSema(uVar3);
    }
  }
  return auStack_b0[0];
}
// FUN_0050A660 NONMATCHING
u32 FUN_0050a660(char *param_1,char *param_2)

{
  char cVar1;
  u64 uVar2;
  long lVar3;
  int iVar4;
  u8 auStack_b0 [4];
  u32 uStack_ac;
  u32 uStack_a8;
  char *pcStack_9c;
  u32 auStack_90 [4];
  
  FUN_00508048(0x11);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
    (*(u8*)((u8*)&DAT_0096850c + 0)) = *param_1;
  }
  else {
    (*(u8*)((u8*)&DAT_0096850c + 0)) = *param_1;
  }
  iVar4 = 0;
  if ((char)DAT_0096850c != '\0') {
    for (iVar4 = 1;
        (iVar4 < 0x400 &&
        (cVar1 = param_1[iVar4], *(char *)((int)&DAT_0096850c + iVar4) = cVar1, cVar1 != '\0'));
        iVar4 = iVar4 + 1) {
    }
  }
  if (iVar4 == 0x400) {
    DAT_0096890b = 0;
  }
  DAT_0096890c = *param_2;
  iVar4 = 0;
  if (DAT_0096890c != '\0') {
    for (iVar4 = 1;
        (iVar4 < 0x400 && (cVar1 = param_2[iVar4], (&DAT_0096890c)[iVar4] = cVar1, cVar1 != '\0'));
        iVar4 = iVar4 + 1) {
    }
  }
  if (iVar4 == 0x400) {
    DAT_00968d0b = 0;
  }
  uStack_ac = 1;
  pcStack_9c = s_SceStdioRenameSema_007bdf48;
  uStack_a8 = 0;
  uVar2 = CreateSema(auStack_b0);
  DAT_00968508 = 4;
  DAT_00968500 = (u32)uVar2;
  DAT_00968504 = (u32)(auStack_90);
  FUN_005067f8(0x968500,0x80c);
  lVar3 = FUN_00507ad8(0x969c00,0x11,0,0x968500,0x80c,0x969140,4,0);
  iVar4 = DAT_20969140;
  if (lVar3 < 0) {
    DeleteSema(uVar2);
    FUN_00508078();
    auStack_90[0] = 0xfffffff5;
  }
  else {
    FUN_00508078();
    if (iVar4 == 0) {
      DeleteSema(uVar2);
      auStack_90[0] = 0xfffffff5;
    }
    else {
      WaitSema(uVar2);
      DeleteSema(uVar2);
    }
  }
  return auStack_90[0];
}
#pragma schedule on
// FUN_0050A868
void FUN_0050a868(char *param_1)

{
  FUN_00509758(param_1,0x12);
  return;
}
#pragma schedule off
// FUN_0050A888 NONMATCHING
u32 FUN_0050a888(char *param_1,u32 param_2)

{
  char cVar1;
  u64 uVar2;
  long lVar3;
  int iVar4;
  u8 auStack_b0 [4];
  u32 uStack_ac;
  u32 uStack_a8;
  char *pcStack_9c;
  u32 auStack_90 [4];
  
  FUN_00508048(0x13);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
    DAT_00968514 = *param_1;
  }
  else {
    DAT_00968514 = *param_1;
  }
  iVar4 = 0;
  if (DAT_00968514 != '\0') {
    for (iVar4 = 1;
        (iVar4 < 0x400 && (cVar1 = param_1[iVar4], (&DAT_00968514)[iVar4] = cVar1, cVar1 != '\0'));
        iVar4 = iVar4 + 1) {
    }
  }
  if (iVar4 == 0x400) {
    DAT_00968913 = 0;
  }
  uStack_ac = 1;
  pcStack_9c = s_SceStdioSyncSema_007bdf60;
  uStack_a8 = 0;
  DAT_00968510 = param_2;
  uVar2 = CreateSema(auStack_b0);
  DAT_00968500 = (u32)uVar2;
  DAT_00968508 = 4;
  DAT_00968504 = (u32)(auStack_90);
  lVar3 = FUN_00507ad8(0x969c00,0x13,0,0x968500,0x414,0x969140,4,0);
  iVar4 = DAT_20969140;
  if (lVar3 < 0) {
    DeleteSema(uVar2);
    FUN_00508078();
    auStack_90[0] = 0xfffffff5;
  }
  else {
    FUN_00508078();
    if (iVar4 == 0) {
      DeleteSema(uVar2);
      auStack_90[0] = 0xfffffff5;
    }
    else {
      WaitSema(uVar2);
      DeleteSema(uVar2);
    }
  }
  return auStack_90[0];
}
// FUN_0050AA38 NONMATCHING
u32 FUN_0050aa38(char *param_1,char *param_2,u32 param_3,int param_4,int param_5)

{
  char cVar1;
  u8 *puVar2;
  u64 uVar3;
  long lVar4;
  u8 *puVar5;
  int iVar6;
  u8 auStack_d0 [4];
  u32 uStack_cc;
  u32 uStack_c8;
  char *pcStack_bc;
  u32 auStack_b0 [4];
  
  FUN_00508048(0x14);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
    (*(u8*)((u8*)&DAT_0096850c + 0)) = *param_1;
  }
  else {
    (*(u8*)((u8*)&DAT_0096850c + 0)) = *param_1;
  }
  iVar6 = 0;
  if ((char)DAT_0096850c != '\0') {
    for (iVar6 = 1;
        (iVar6 < 0x400 &&
        (cVar1 = param_1[iVar6], *(char *)((int)&DAT_0096850c + iVar6) = cVar1, cVar1 != '\0'));
        iVar6 = iVar6 + 1) {
    }
  }
  if (iVar6 == 0x400) {
    DAT_0096890b = 0;
  }
  DAT_0096890c = *param_2;
  iVar6 = 0;
  if (DAT_0096890c != '\0') {
    for (iVar6 = 1;
        (iVar6 < 0x400 && (cVar1 = param_2[iVar6], (&DAT_0096890c)[iVar6] = cVar1, cVar1 != '\0'));
        iVar6 = iVar6 + 1) {
    }
  }
  if (iVar6 == 0x400) {
    DAT_00968d0b = 0;
  }
  if (param_5 < 0x401) {
    iVar6 = 0;
    if (0 < param_5) {
      do {
        puVar2 = (u8 *)(param_4 + iVar6);
        puVar5 = (u8 *)((int)&DAT_00968d0c + iVar6);
        iVar6 = iVar6 + 1;
        *puVar5 = *puVar2;
      } while (iVar6 < param_5);
    }
    uStack_cc = 1;
    pcStack_bc = s_SceStdioMountSema_007bdf78;
    uStack_c8 = 0;
    DAT_0096910c = param_3;
    DAT_00969110 = param_5;
    uVar3 = CreateSema(auStack_d0);
    DAT_00968508 = 4;
    DAT_00968500 = (u32)uVar3;
    DAT_00968504 = (u32)(auStack_b0);
    FUN_005067f8(0x968500,0xc14);
    lVar4 = FUN_00507ad8(0x969c00,0x14,0,0x968500,0xc14,0x969140,4,0);
    iVar6 = DAT_20969140;
    if (lVar4 < 0) {
      DeleteSema(uVar3);
      FUN_00508078();
      auStack_b0[0] = 0xfffffff5;
    }
    else {
      FUN_00508078();
      if (iVar6 == 0) {
        DeleteSema(uVar3);
        auStack_b0[0] = 0xfffffff5;
      }
      else {
        WaitSema(uVar3);
        DeleteSema(uVar3);
      }
    }
  }
  else {
    FUN_00508078();
    auStack_b0[0] = 0xfffffff9;
  }
  return auStack_b0[0];
}
#pragma schedule on
// FUN_0050ACB8
void FUN_0050acb8(char *param_1)

{
  FUN_00509758(param_1,0x15);
  return;
}
#pragma schedule off
// FUN_0050ACD8 NONMATCHING
u64 FUN_0050acd8(u64 param_1,u64 param_2,u32 param_3)

{
  long lVar1;
  u64 uVar2;
  int *piVar3;
  int iVar4;
  u32 *puVar5;
  u32 uVar6;
  u8 auStack_b0 [4];
  u32 uStack_ac;
  u32 uStack_a8;
  char *pcStack_9c;
  u64 auStack_90 [2];
  
  lVar1 = (long)FUN_00507bc8();
  FUN_00508048(0x16);
  if ((DAT_0077f53c != 0) && (lVar1 != 0)) {
    puVar5 = (u32 *)lVar1;
    if (puVar5[1] != 0) {
      DAT_0096850c = *puVar5;
      DAT_0096851c = (int)(puVar5 + -0x25a680) >> 4;
      uStack_ac = 1;
      pcStack_9c = s_SceStdioLseek64Sema_007bdf90;
      uVar6 = puVar5[1] & 0x8000;
      uStack_a8 = 0;
      _DAT_00968510 = param_2;
      DAT_00968518 = param_3;
      uVar2 = CreateSema(auStack_b0);
      DAT_00968504 = (u32)(auStack_90);
      DAT_00968508 = 8;
      DAT_00968500 = (int)uVar2;
      if (uVar6 == 0) {
        uVar6 = 0;
      }
      else {
        WaitSema(DAT_0077f54c);
        if (DAT_0077f4b8 == -1) {
          DAT_0077f4b8 = DAT_00968500;
          DAT_00968500 = -DAT_00968500;
        }
        else {
          iVar4 = 1;
          do {
            if (0x1f < iVar4) goto LAB_0050ae30;
            piVar3 = (int *)(&DAT_0077f4b8 + iVar4);
            iVar4 = iVar4 + 1;
          } while (*piVar3 != -1);
          *piVar3 = DAT_00968500;
          DAT_00968500 = -DAT_00968500;
        }
LAB_0050ae30:
        SignalSema(DAT_0077f54c);
      }
      lVar1 = FUN_00507ad8(0x969c00,0x16,0,0x968500,0x20,0x969140,4,0);
      iVar4 = DAT_20969140;
      if (lVar1 < 0) {
        DeleteSema(uVar2);
        FUN_00508078();
        return 0xfffffffffffffff5;
      }
      FUN_00508078();
      if (iVar4 == 0) {
        DeleteSema(uVar2);
        return 0xfffffffffffffff5;
      }
      if (uVar6 != 0) {
        DeleteSema(uVar2);
        return 0;
      }
      WaitSema(uVar2);
      DeleteSema(uVar2);
      return auStack_90[0];
    }
  }
  FUN_00508078();
  return 0xfffffffffffffff7;
}
// FUN_0050AF18 NONMATCHING
u32
FUN_0050af18(char *param_1,long param_2,int param_3,u32 param_4,u32 param_5,u32 param_6)

{
  char cVar1;
  u8 *puVar2;
  u64 uVar3;
  long lVar4;
  u8 *puVar5;
  int iVar6;
  u32 uVar7;
  u32 uVar8;
  u8 auStack_d0 [4];
  u32 uStack_cc;
  u32 uStack_c8;
  char *pcStack_bc;
  u32 uStack_b0;
  u32 uStack_ac;
  
  uStack_ac = param_5;
  FUN_00508048(0x17);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
    (*(u8*)((u8*)&DAT_0096850c + 0)) = *param_1;
  }
  else {
    (*(u8*)((u8*)&DAT_0096850c + 0)) = *param_1;
  }
  iVar6 = 0;
  if ((char)DAT_0096850c != '\0') {
    for (iVar6 = 1;
        (iVar6 < 0x400 &&
        (cVar1 = param_1[iVar6], *(char *)((int)&DAT_0096850c + iVar6) = cVar1, cVar1 != '\0'));
        iVar6 = iVar6 + 1) {
    }
  }
  if (iVar6 == 0x400) {
    DAT_0096890b = 0;
  }
  if ((param_4 < 0x401) && (param_6 < 0x401)) {
    if (param_2 == 0x4601) {
      if (*(int *)(param_3 + 4) == 0) {
        FUN_00508078();
        return 0;
      }
      if (*(int *)(param_3 + 0xc) == 0) goto LAB_0050b018;
    }
    uVar7 = 0;
    if (param_4 != 0) {
      do {
        puVar2 = (u8 *)(param_3 + uVar7);
        puVar5 = (u8 *)(&DAT_0096890c + uVar7);
        uVar7 = uVar7 + 1;
        *puVar5 = *puVar2;
      } while (uVar7 < param_4);
    }
    pcStack_bc = s_SceStdioDevctlSema_007bdfa8;
    uStack_cc = 1;
    DAT_00968d0c = (u32)param_2;
    uStack_c8 = 0;
    DAT_00968d10 = param_4;
    uVar3 = CreateSema(auStack_d0);
    DAT_00968d18 = (u32)param_6;
    DAT_00968508 = 4;
    DAT_00968d14 = uStack_ac;
    DAT_00968500 = (u32)uVar3;
    DAT_00968504 = (u32)(&uStack_b0);
    if (param_2 == 0x4601) {
      uVar8 = 0x1c;
      FUN_005067f8(*(u32 *)(param_3 + 8),*(int *)(param_3 + 4) * *(int *)(param_3 + 0xc));
    }
    else {
      uVar8 = 0x17;
    }
    FUN_005067f8(0x968500,0x81c);
    lVar4 = FUN_00507ad8(0x969c00,uVar8,0,0x968500,0x81c,0x969140,4,0);
    iVar6 = DAT_20969140;
    if (lVar4 < 0) {
      DeleteSema(uVar3);
      FUN_00508078();
      uStack_b0 = 0xfffffff5;
    }
    else {
      FUN_00508078();
      if (iVar6 == 0) {
        DeleteSema(uVar3);
        uStack_b0 = 0xfffffff5;
      }
      else {
        WaitSema(uVar3);
        DeleteSema(uVar3);
      }
    }
  }
  else {
LAB_0050b018:
    FUN_00508078();
    uStack_b0 = 0xffffffea;
  }
  return uStack_b0;
}
// FUN_0050B1C0 NONMATCHING
u32 FUN_0050b1c0(char *param_1,char *param_2)

{
  char cVar1;
  u64 uVar2;
  long lVar3;
  int iVar4;
  u8 auStack_b0 [4];
  u32 uStack_ac;
  u32 uStack_a8;
  char *pcStack_9c;
  u32 auStack_90 [4];
  
  FUN_00508048(0x11);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
    (*(u8*)((u8*)&DAT_0096850c + 0)) = *param_1;
  }
  else {
    (*(u8*)((u8*)&DAT_0096850c + 0)) = *param_1;
  }
  iVar4 = 0;
  if ((char)DAT_0096850c != '\0') {
    for (iVar4 = 1;
        (iVar4 < 0x400 &&
        (cVar1 = param_1[iVar4], *(char *)((int)&DAT_0096850c + iVar4) = cVar1, cVar1 != '\0'));
        iVar4 = iVar4 + 1) {
    }
  }
  if (iVar4 == 0x400) {
    DAT_0096890b = 0;
  }
  DAT_0096890c = *param_2;
  iVar4 = 0;
  if (DAT_0096890c != '\0') {
    for (iVar4 = 1;
        (iVar4 < 0x400 && (cVar1 = param_2[iVar4], (&DAT_0096890c)[iVar4] = cVar1, cVar1 != '\0'));
        iVar4 = iVar4 + 1) {
    }
  }
  if (iVar4 == 0x400) {
    DAT_00968d0b = 0;
  }
  uStack_ac = 1;
  pcStack_9c = s_SceStdioSymlinkSema_007bdfc0;
  uStack_a8 = 0;
  uVar2 = CreateSema(auStack_b0);
  DAT_00968500 = (u32)uVar2;
  DAT_00968508 = 4;
  DAT_00968504 = (u32)(auStack_90);
  lVar3 = FUN_00507ad8(0x969c00,0x18,0,0x968500,0x80c,0x969140,4,0);
  iVar4 = DAT_20969140;
  if (lVar3 < 0) {
    DeleteSema(uVar2);
    FUN_00508078();
    auStack_90[0] = 0xfffffff5;
  }
  else {
    FUN_00508078();
    if (iVar4 == 0) {
      DeleteSema(uVar2);
      auStack_90[0] = 0xfffffff5;
    }
    else {
      WaitSema(uVar2);
      DeleteSema(uVar2);
    }
  }
  return auStack_90[0];
}
// FUN_0050B3B8 NONMATCHING
u32 FUN_0050b3b8(char *param_1,u64 param_2,u32 param_3)

{
  char cVar1;
  u64 uVar2;
  long lVar3;
  int iVar4;
  u8 auStack_d0 [4];
  u32 uStack_cc;
  u32 uStack_c8;
  char *pcStack_bc;
  u32 auStack_b0 [4];
  
  FUN_00508048(0x11);
  if (DAT_0077f53c == 0) {
    FUN_00508170();
    DAT_00968514 = *param_1;
  }
  else {
    DAT_00968514 = *param_1;
  }
  iVar4 = 0;
  if (DAT_00968514 != '\0') {
    for (iVar4 = 1;
        (iVar4 < 0x400 && (cVar1 = param_1[iVar4], (&DAT_00968514)[iVar4] = cVar1, cVar1 != '\0'));
        iVar4 = iVar4 + 1) {
    }
  }
  if (iVar4 == 0x400) {
    DAT_00968913 = 0;
  }
  if (0x3ff < param_3) {
    param_3 = 0x3ff;
  }
  DAT_00968510 = (u32)param_2;
  DAT_0096850c = (u32)param_3;
  FUN_005067f8(param_2,param_3);
  uStack_cc = 1;
  pcStack_bc = s_SceStdioReadlinkSema_007bdfd8;
  uStack_c8 = 0;
  uVar2 = CreateSema(auStack_d0);
  DAT_00968500 = (u32)uVar2;
  DAT_00968508 = 4;
  DAT_00968504 = (u32)(auStack_b0);
  lVar3 = FUN_00507ad8(0x969c00,0x19,0,0x968500,0x80c,0x969140,4,0);
  iVar4 = DAT_20969140;
  if (lVar3 < 0) {
    DeleteSema(uVar2);
    FUN_00508078();
    auStack_b0[0] = 0xfffffff5;
  }
  else {
    FUN_00508078();
    if (iVar4 == 0) {
      DeleteSema(uVar2);
      auStack_b0[0] = 0xfffffff5;
    }
    else {
      WaitSema(uVar2);
      DeleteSema(uVar2);
    }
  }
  return auStack_b0[0];
}
