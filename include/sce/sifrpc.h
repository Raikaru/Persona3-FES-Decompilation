#ifndef SIFRPC_H
#define SIFRPC_H

#include "sce/eetypes.h"

typedef void* (*SifRpcFunc_t)(int function, void* buffer, int size);
typedef void (*SifRpcEndFunc_t)(void* callback_data);

typedef struct SifRpcHeader
{
    void* packet;
    u_int rpc_id;
    int semaphore;
    u_int mode;
} SifRpcHeader_t;

typedef struct SifRpcClientData
{
    SifRpcHeader_t header;
    int command;
    void* buffer;
    void* callback_buffer;
    SifRpcEndFunc_t end_function;
    void* end_parameter;
    void* server;
} SifRpcClientData_t;

typedef struct SifRpcReceiveData
{
    SifRpcHeader_t header;
    void* source;
    void* destination;
    int size;
} SifRpcReceiveData_t;

typedef struct SifRpcServerData
{
    int server_id;
    SifRpcFunc_t function;
    void* buffer;
    int size;
    SifRpcFunc_t callback_function;
    void* callback_buffer;
    int callback_size;
    SifRpcClientData_t* client;
    void* packet;
    int rpc_number;
    void* receive_buffer;
    int receive_size;
    int receive_mode;
    int receive_id;
    struct SifRpcServerData* link;
    struct SifRpcServerData* next;
    struct SifRpcDataQueue* queue;
} SifRpcServerData_t;

typedef struct SifRpcDataQueue
{
    int thread_id;
    int active;
    SifRpcServerData_t* servers;
    SifRpcServerData_t* request_head;
    SifRpcServerData_t* request_tail;
    struct SifRpcDataQueue* next;
} SifRpcDataQueue_t;

void sceSifInitRpc(unsigned int mode);
void sceSifExitRpc(void);
int sceSifBindRpc(SifRpcClientData_t* client, int server_id, int mode);
int sceSifCallRpc(SifRpcClientData_t* client, int function, int mode, void* send_buffer, int send_size, void* receive_buffer, int receive_size, SifRpcEndFunc_t callback, void* callback_data);
int sceSifGetOtherData(SifRpcReceiveData_t* receive, void* source, void* destination, int size, int mode);
int sceSifCheckStatRpc(SifRpcClientData_t* client);
void sceSifRegisterRpc(SifRpcServerData_t* server, int server_id, SifRpcFunc_t function, void* buffer, SifRpcFunc_t callback_function, void* callback_buffer, SifRpcDataQueue_t* queue);
SifRpcServerData_t* sceSifRemoveRpc(SifRpcServerData_t* server, SifRpcDataQueue_t* queue);
void sceSifSetRpcQueue(SifRpcDataQueue_t* queue, int thread_id);
SifRpcDataQueue_t* sceSifRemoveRpcQueue(SifRpcDataQueue_t* queue);
SifRpcServerData_t* sceSifGetNextRequest(SifRpcDataQueue_t* queue);
void sceSifExecRequest(SifRpcServerData_t* server);
void sceSifRpcLoop(SifRpcDataQueue_t* queue);
void sceSifWriteBackDCache(void* buffer, int size);

#endif