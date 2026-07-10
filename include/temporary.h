/**
* This file contains functions, structs, enums and macros that have been identified,
* but i don't have enough informations to put them in their proper files yet.
*/

#ifndef TEMPORARY_H
#define TEMPORARY_H

#include "Utils.h"
#include "rw/rwcore.h"

#define QUARTER_PI ((PI) / 4)

// CodeWarrior libc core
void* memcpy(void* dst, const void* src, u32 size);
void* memmove(void* dst, const void* src, u32 size);
void* memset(void* dst, u8 value, u32 size);
int printf(const char* fmt, ...);
int sprintf(char* buffer, const char* fmt, ...);
int sscanf(const char* input, const char* fmt, ...);
void qsort(void* base, u32 count, u32 width, int (*compare)(const void*, const void*));
void* realloc(void* block, u32 size);
char* strcat(char* dst, const char* src);
char* strchr(const char* string, int character);
int strcasecmp(const char* left, const char* right);
int strcmp(const char* left, const char* right);
char* strcpy(char* dst, const char* src);
size_t strlen(const char* string);
f64 copysign(f64 value, f64 sign);
f32 copysignf(f32 value, f32 sign);
f64 ldexp(f64 value, s32 exponent);
f32 scalbnf(f32 value, s32 exponent);


float sqrtf(float x);

void kwlnSetDrawLayer(s32 layer);
void btlUnitDrawAll();
void btlEffectDrawAll();
void btl002d1ac0();
void btlOrder0029ae40();
void btlMain0029e420();
void btlUnit00286540();
void btlMsg002db960();
void btlFormation002bf990();
void btlAction002891e0();
void btlMain0029e4b0();
void btlFormation002bf9a0();
void btlVoice002e2f20();
void btlSound002dcc40();

typedef struct BmdHeader BmdHeader;

extern BmdHeader* gBtlMessageBmd;
s32 itfMesMngInitialize(BmdHeader* bmdHeader);

void btlLoadResource(s32 resId);
void btlTarget002d3d70();
void btlPacket0027edf0();
void btlCamera002a4a70();
void btlSound002dcbc0();
void btlVoice002e2f30();
void btlFormation002bb760();
void btlMsg002db8d0();
void btlFormation002bf970();


#endif