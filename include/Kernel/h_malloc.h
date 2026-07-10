#ifndef H_MALLOC_H
#define H_MALLOC_H

#include "Utils.h"
typedef struct HHeapAlloc
{
    void* memory;
    u32 size;
} HHeapAlloc;

typedef void (*HFreeCallback)(void* memory);


void H_Free(void* memory);
void* H_Malloc(size_t size);
void* H_Calloc(u32 count, size_t size);
void H_Malloc_Init(void* memory, u32 size);

#endif