#ifndef SIFDEV_H
#define SIFDEV_H

#include "sce/eetypes.h"

int sceSifInitIopHeap(void);
void* sceSifAllocIopHeap(int size);
int sceSifFreeIopHeap(void* address);
int sceSifLoadIopHeap(const char* path, void* address);

int sceSifLoadModule(const char* filename, int args, const char* argp);
int sceSifLoadStartModule(const char* filename, int args, const char* argp, int* result);
int sceSifSyncIop(void);
int sceSifRebootIop(const char* image);

#define IOP_IMAGE_FILE "IOPRP310.IMG"

#endif