#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Result/bp_ifont.h"

extern void* H_Maestro_001120a0(s32 font);
extern void* kwlnGetMainCamera(void);
extern void func_0021d8e0(void* panel, const float* rect);
extern int sprintf(char* buffer, const char* format, ...);
extern u32 strlen(const char* string);
extern char D_00960088[];


// FUN_00238980
void bpIFont00238980(void* glyphs, s32 capacity, s32 value, s32 style)
{
    char digits[0x100];
    s32 i;
    s32 length;

    sprintf(digits, "%d", value);
    length = (s32)strlen(digits);
    K_ASSERT(capacity >= length, 0x25);
    for (i = 0; i < length; i++) {
        bpIFont00238fd0((u8*)glyphs + i * 0x100, digits[length - 1 - i] - '0', style);
    }
}

// FUN_00238a50
void bpIFont00238a50(void* glyphs, s32 capacity, s32 value, s32 font, const float* origin)
{
    float rect[4];
    char digits[0x100];
    void* fontData;
    u8* character;
    s32 i;
    u32 length;

    fontData = H_Maestro_001120a0(font);
    sprintf(digits, "%d", value);
    length = strlen(digits);
    K_ASSERT(capacity >= (s32)length, 0x38);
    for (i = 0; i < (s32)length; i++) {
        s32 index = length - 1 - i;

        character = *(u8**)((u8*)fontData + 0x184) + (digits[index] - 0x25) * 0x80;
        rect[0] = origin[0] + (float)(index * 15);
        rect[1] = origin[1];
        rect[2] = (float)(*(s32*)(character + 0x5c) - *(s32*)(character + 0x54));
        rect[3] = (float)(*(s32*)(character + 0x60) - *(s32*)(character + 0x58));
        func_0021d8e0((u8*)glyphs + i * 0x100, rect);
    }
    for (; (s32)length < capacity; length++) {
        rect[0] = origin[0];
        rect[1] = origin[1];
        rect[2] = 0.0f;
        rect[3] = 0.0f;
        func_0021d8e0((u8*)glyphs + length * 0x100, rect);
    }
}

// FUN_00238bf0
void bpIFont00238bf0(void* glyphs, s32 capacity, const char* text, s32 font, const float* origin)
{
    float rect[4];
    char digits[0x100];
    void* fontData;
    u8* character;
    s32 i;
    s32 length;
    s32 offset;
    float x;

    fontData = H_Maestro_001120a0(font);
    sprintf(digits, "%s", text);
    length = (s32)strlen(digits);
    K_ASSERT(capacity >= length, 0x59);
    i = 0;
    offset = (capacity - length) * 15;
    for (; i < length; i++) {
        s32 index = length - 1 - i;

        character = *(u8**)((u8*)fontData + 0x184) + (digits[index] - 0x25) * 0x80;
        x = origin[0] + (float)(index * 15);
        rect[0] = x + (float)offset;
        rect[1] = origin[1];
        rect[2] = (float)(*(s32*)(character + 0x5c) - *(s32*)(character + 0x54));
        rect[3] = (float)(*(s32*)(character + 0x60) - *(s32*)(character + 0x58));
        func_0021d8e0((u8*)glyphs + i * 0x100, rect);
    }
    for (; length < capacity; length++) {
        rect[0] = origin[0];
        rect[1] = origin[1];
        rect[2] = 0.0f;
        rect[3] = 0.0f;
        func_0021d8e0((u8*)glyphs + length * 0x100, rect);
    }
}

// FUN_00238dc0
void bpIFont00238dc0(void* glyphs, s32 capacity, const char* text, s32 font, const float* origin)
{
    float rect[4];
    char buffer[0x100];
    void* fontData;
    u8* character;
    s32 i;
    u32 length;
    s32 leftOffset;
    s32 textOffset;

    fontData = H_Maestro_001120a0(font);
    sprintf(buffer, "%s", text);
    length = strlen(buffer);
    K_ASSERT(capacity >= (s32)length, 0x7a);
    i = 0;
    leftOffset = capacity * 15 / 2;
    textOffset = (s32)length * 15 / 2;
    for (; i < (s32)length; i++) {
        s32 index = length - 1 - i;

        character = *(u8**)((u8*)fontData + 0x184) + (buffer[index] - 0x25) * 0x80;
        rect[0] = (float)leftOffset + (origin[0] + (float)(index * 15)) - (float)textOffset;
        rect[1] = origin[1];
        rect[2] = (float)(*(s32*)(character + 0x5c) - *(s32*)(character + 0x54));
        rect[3] = (float)(*(s32*)(character + 0x60) - *(s32*)(character + 0x58));
        func_0021d8e0((u8*)glyphs + i * 0x100, rect);
    }
    for (; (s32)length < capacity; length++) {
        rect[0] = origin[0];
        rect[1] = origin[1];
        rect[2] = 0.0f;
        rect[3] = 0.0f;
        func_0021d8e0((u8*)glyphs + length * 0x100, rect);
    }
}

// FUN_00238fd0
void bpIFont00238fd0(void* glyph, s32 character, s32 style)
{
    void* camera;
    void* fontData;
    u8* source;
    u8* texture;
    s32 textureAddress;
    float inverseScale;
    float x0;
    float y0;
    float x1;
    float y1;
    float* vertex;
    float* depth;

    camera = kwlnGetMainCamera();
    inverseScale = 1.0f / *(float*)((u8*)camera + 0x80);
    fontData = H_Maestro_001120a0(style);
    source = *(u8**)((u8*)fontData + 0x184) + (character + 0xb) * 0x80;
    textureAddress = *(s32*)(source + 0x14) * 4;
    textureAddress += (s32)fontData;
    texture = *(u8**)(textureAddress + 0x104);
    x0 = (float)*(s32*)(source + 0x54) / (float)*(s32*)(texture + 0xc);
    y0 = (float)*(s32*)(source + 0x58) / (float)*(s32*)(texture + 0x10);
    x1 = (float)*(s32*)(source + 0x5c) / (float)*(s32*)(texture + 0xc);
    y1 = (float)*(s32*)(source + 0x60) / (float)*(s32*)(texture + 0x10);

    vertex = (float*)glyph;
    vertex[4] = x0;
    vertex[5] = y0;
    vertex[6] = inverseScale;
    depth = (float*)D_00960088;
    vertex[2] = *depth;
    vertex[8] = 255.0f;
    vertex[9] = 255.0f;
    vertex[10] = 255.0f;
    vertex[11] = 255.0f;

    vertex = (float*)((u8*)glyph + 0x40);
    vertex[4] = x1;
    vertex[5] = y0;
    vertex[6] = inverseScale;
    vertex[2] = *depth;
    vertex[8] = 255.0f;
    vertex[9] = 255.0f;
    vertex[10] = 255.0f;
    vertex[11] = 255.0f;

    vertex = (float*)((u8*)glyph + 0x80);
    vertex[4] = x1;
    vertex[5] = y1;
    vertex[6] = inverseScale;
    vertex[2] = *depth;
    vertex[8] = 255.0f;
    vertex[9] = 255.0f;
    vertex[10] = 255.0f;
    vertex[11] = 255.0f;

    vertex = (float*)((u8*)glyph + 0xc0);
    vertex[4] = x0;
    vertex[5] = y1;
    vertex[6] = inverseScale;
    vertex[2] = *depth;
    vertex[8] = 255.0f;
    vertex[9] = 255.0f;
    vertex[10] = 255.0f;
    vertex[11] = 255.0f;
}
