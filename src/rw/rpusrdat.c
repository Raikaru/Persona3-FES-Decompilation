#include "rw/rpusrdat.h"

extern RwInt32 rpMaterialUserDataOffset;

typedef struct RpUserDataList
{
    RwInt32 numElements;
    RpUserDataArray* userData;
} RpUserDataList;
extern RwInt32 _rpUserDataArrayAdd(RpUserDataList* userDataList, RwChar* name, RpUserDataFormat format, RwInt32 numElements);

// FUN_0048ee70
#pragma optimization_level 3
RwInt32 RpMaterialAddUserDataArray(RpMaterial* material, RwChar* name, RpUserDataFormat format, RwInt32 numElements)
{
    return _rpUserDataArrayAdd((RpUserDataList*)((RwUInt8*)material + rpMaterialUserDataOffset), name, format, numElements);
}
#pragma optimization_level 2

// FUN_0048ee80
RwInt32 RpMaterialGetUserDataArrayCount(const RpMaterial* material)
{
    // TODO

    return 0;  
}

// FUN_0048eed0
RpUserDataArray* RpMaterialGetUserDataArray(const RpMaterial* material, RwInt32 data)
{
    // TODO

    return NULL;
}

// FUN_0048ef10
#pragma optimization_level 3
RwChar* RpUserDataArrayGetName(RpUserDataArray* userData)
{
    return userData->name;
}
#pragma optimization_level 2

// FUN_0048ef20
#pragma optimization_level 3
RpUserDataFormat RpUserDataArrayGetFormat(RpUserDataArray* userData)
{
    return userData->format;
}
#pragma optimization_level 2

// FUN_0048ef40
#pragma optimization_level 3
RwInt32 RpUserDataArrayGetInt(RpUserDataArray* userData, RwInt32 index)
{
    return ((RwInt32*)userData->data)[index];
}
#pragma optimization_level 2