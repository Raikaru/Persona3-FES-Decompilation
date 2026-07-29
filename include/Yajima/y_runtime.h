#ifndef Y_RUNTIME_H
#define Y_RUNTIME_H

#include "Utils.h"

/* Runtime unit row, stride 0x1c0. Retail forms the element address as (i * 7) << 6.
 * Three bases are known to hold arrays of this record: DAT_008717a0, DAT_0086e6a0,
 * and DAT_008717f0. Field offsets are proven by address subtraction against the
 * per-field DAT_ symbols the decompiler invented for them (e.g. 0x8717e8 - 0x8717a0
 * = 0x48, 0x8717f4 -> 0x54, 0x87190c -> 0x16c, 0x871948 -> 0x1a8). */
typedef struct YRuntimeUnitRow {
  u8 pad_000[0x48];
  void *unk_048;
  u8 pad_04c[0x4];
  void *unk_050;
  void *unk_054;
  u8 pad_058[0x114];
  void *unit;
  u8 pad_170[0x38];
  u16 unit_id;
  u8 pad_1aa[0x16];
} YRuntimeUnitRow;

#endif
