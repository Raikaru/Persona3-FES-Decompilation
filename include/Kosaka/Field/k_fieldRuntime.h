#ifndef K_FIELDRUNTIME_H
#define K_FIELDRUNTIME_H

#include "Utils.h"

typedef struct FieldModelMetadata
{
    s32 sourceType;
    void* source;
    s32 recordIndex;
    u8 unk_0c[4];
    u32 sourceIndex;
    u8 unk_14[0x10];
} FieldModelMetadata;

#endif
