#ifndef CRI_ADXF_H
#define CRI_ADXF_H

#include "Utils.h"

/**
 * Opaque ADX filesystem handle. CD/DVD code only depends on the byte-size
 * field populated by the filesystem open routine.
 */
typedef struct ADX_FS
{
    u8 unk_00[0x10];
    u32 fileSize;
} ADX_FS;

typedef ADX_FS* ADXF;

#endif
