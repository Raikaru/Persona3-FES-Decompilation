#ifndef BP_IFONT_H
#define BP_IFONT_H

#include "Utils.h"

void bpIFont00238980(void* glyphs, s32 capacity, s32 value, s32 style);
void bpIFont00238a50(void* glyphs, s32 capacity, s32 value, s32 font, const float* origin);
void bpIFont00238bf0(void* glyphs, s32 capacity, const char* text, s32 font, const float* origin);
void bpIFont00238dc0(void* glyphs, s32 capacity, const char* text, s32 font, const float* origin);
void bpIFont00238fd0(void* glyph, s32 character, s32 style);

#endif