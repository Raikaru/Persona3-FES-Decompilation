#include "mw_harvest_compat.h"
#include "sce/sifdev.h"
#include "sce/sifrpc.h"

/* auto-extern (generated) */
void FUN_0050b788(void);
extern u32 DAT_0077f558;
extern u32 DAT_00969d40;
extern u32 DAT_00969d80;
extern u32 DAT_00969d84;
extern u32 DAT_00969d88;

typedef union SifIopHeapValue
{
    int result;
    int size;
    void* address;
} SifIopHeapValue_t;

typedef struct SifIopHeapLoadRequest
{
    void* address;
    char path[252];
} SifIopHeapLoadRequest_t;

static SifRpcClientData_t sIopHeapClient;

static int sif_copy_path(char* destination, const char* source, int capacity)
{
    int length;

    length = 0;
    if (source != 0)
    {
        while (length + 1 < capacity && source[length] != '\0')
        {
            destination[length] = source[length];
            length++;
        }
    }
    destination[length] = '\0';
    return length;
}

// FUN_0050B598 NONMATCHING
int sceSifInitIopHeap(void)
{
    int result;

    sceSifInitRpc(0);
    do
    {
        result = sceSifBindRpc(&sIopHeapClient, 0x80000003, 0);
    }
    while (result >= 0 && sIopHeapClient.server == 0);
    return result < 0 ? -1 : 0;
}

// FUN_0050B620 NONMATCHING

// FUN_0050B690 NONMATCHING
u32 FUN_0050b690(u32 param_1,u32 param_2,u32 param_3)

{
  u32 uVar1;
  long lVar2;
  
  uVar1 = 0;
  if (-1 < DAT_0077f558) {
    DAT_00969d80 = param_2;
    DAT_00969d84 = param_1;
    DAT_00969d88 = param_3;
    lVar2 = FUN_00507230(0x969d00,4,0,0x969d80,0xc,0x969d40,4,0);
    uVar1 = DAT_00969d40;
    if (lVar2 < 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}
// FUN_0050B710 NONMATCHING

// FUN_0050B788 NONMATCHING
void FUN_0050b788(void)

{
  FUN_0050b710();
  return;
}
// FUN_0050B7A8 NONMATCHING
int sceSifLoadIopHeap(const char* path, void* address)
{
    SifIopHeapLoadRequest_t request;
    int request_size;

    if (sceSifInitIopHeap() < 0)
    {
        return -1;
    }
    request.address = address;
    request_size = sif_copy_path(request.path, path, sizeof(request.path));
    if (sceSifCallRpc(&sIopHeapClient, 3, 0, &request, request_size + 5, &request, 4, 0, 0) < 0)
    {
        return -1;
    }
    return *(int*)&request;
}

// FUN_0050B898 NONMATCHING
u32 FUN_0050b898(void)

{
  u32 uVar1;
  long lVar2;
  
  if (DAT_0077f558 < 0) {
    uVar1 = 0;
  }
  else {
    lVar2 = FUN_00507230(0x969d00,5,0,0,0,0x969d40,4,0);
    uVar1 = DAT_00969d40;
    if (lVar2 < 0) {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}
// FUN_0050B908 NONMATCHING
u32 FUN_0050b908(void)

{
  u32 uVar1;
  long lVar2;
  
  if (DAT_0077f558 < 0) {
    uVar1 = 0;
  }
  else {
    lVar2 = FUN_00507230(0x969d00,6,0,0,0,0x969d40,4,0);
    uVar1 = DAT_00969d40;
    if (lVar2 < 0) {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}
// FUN_0050B978 NONMATCHING
u32 FUN_0050b978(void)

{
  u32 uVar1;
  long lVar2;
  
  if (DAT_0077f558 < 0) {
    uVar1 = 0;
  }
  else {
    lVar2 = FUN_00507230(0x969d00,7,0,0,0,0x969d40,4,0);
    uVar1 = DAT_00969d40;
    if (lVar2 < 0) {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}
// FUN_0050B9E8 NONMATCHING
u32 FUN_0050b9e8(u32 param_1)

{
  u32 uVar1;
  long lVar2;
  
  if (DAT_0077f558 < 0) {
    uVar1 = 0;
  }
  else {
    DAT_00969d80 = param_1;
    lVar2 = FUN_00507230(0x969d00,8,0,0x969d80,4,0x969d40,4,0);
    uVar1 = DAT_00969d40;
    if (lVar2 < 0) {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}
// FUN_0050BA68 NONMATCHING
u32 FUN_0050ba68(u32 param_1)

{
  u32 uVar1;
  long lVar2;
  
  if (DAT_0077f558 < 0) {
    uVar1 = 0;
  }
  else {
    DAT_00969d80 = param_1;
    lVar2 = FUN_00507230(0x969d00,9,0,0x969d80,4,0x969d40,4,0);
    uVar1 = DAT_00969d40;
    if (lVar2 < 0) {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}
