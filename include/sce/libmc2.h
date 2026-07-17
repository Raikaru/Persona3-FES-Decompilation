#ifndef LIBMC2_H
#define LIBMC2_H

#include "sce/eetypes.h"

#define SCE_MC2_DMA_BUFFER_MAX  (16)
#define SCE_MC2_MAX_DEVICE_NAME (16)
#define SCE_MC2_PORT_1          (2)
#define SCE_MC2_PORT_2          (3)

// 32 bytes
typedef struct 
{
    unsigned int option;
    int port;
    int slot;
    int number;
    char name[SCE_MC2_MAX_DEVICE_NAME];
} SceMc2SocketParam;

#define SCE_MC2_TYPE_PS2 (2)
#define SCE_MC2_ERROR_NOT_INITIALIZED  ((int)0x81018001)
#define SCE_MC2_ERROR_INIT_FAILED      ((int)0x81018003)
#define SCE_MC2_ERROR_THREAD_FAILED    ((int)0x81018004)
#define SCE_MC2_ERROR_INVALID_SOCKET   ((int)0x81010016)
#define SCE_MC2_ERROR_SOCKET_UNAVAIL   ((int)0x81010017)


int sceMc2Init(int mode);
int sceMc2CreateSocket(SceMc2SocketParam* psocket, u_long128* paddr);

#endif