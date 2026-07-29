#ifndef Y_RUNTIME_H
#define Y_RUNTIME_H

#include "Utils.h"

typedef struct YRuntimeUnitRow {
  u8 pad_000[0x48];
  void *unk_048;
  u8 pad_04c[0x8];
  void *unk_054;
  u8 pad_058[0x114];
  void *unit;
  u8 pad_170[0x38];
  u16 unit_id;
  u8 pad_1aa[0x16];
} YRuntimeUnitRow;

#endif
