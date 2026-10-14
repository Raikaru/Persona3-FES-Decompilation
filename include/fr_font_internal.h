#ifndef FR_FONT_INTERNAL_H
#define FR_FONT_INTERNAL_H

#include "Utils.h"

// Glyph-quad draw for one font record. Defined in frFontRaster.c, called from frFont.c.
// drawState is the record node (byte-addressed by both callers).
u64 FUN_003b38f0(float depthBias, int xFixed, int yFixed, u8 *drawState, int cacheKey, int offsetX, int offsetY, u32 colour);

#endif
