#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Result/bp_ifont.h"

extern void* H_Maestro_001120a0(s32 font);
extern void* kwlnGetMainCamera(void);
extern void func_0021d8e0(void* panel, const float* rect);
extern int sprintf(char* buffer, const char* format, ...);
extern u32 strlen(const char* string);

static void bpIFontPlace(void* glyph, void* fontData, s32 code, float x, float y)
{
    u8* character;
    float rect[4];

    character = *(u8**)((u8*)fontData + 0x184) + code * 0x80;
    rect[0] = x;
    rect[1] = y;
    rect[2] = (float)(*(s32*)(character + 0x5c) - *(s32*)(character + 0x54));
    rect[3] = (float)(*(s32*)(character + 0x60) - *(s32*)(character + 0x58));
    func_0021d8e0(glyph, rect);
}

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

// FUN_00238a50 NONMATCHING
void bpIFont00238a50(void* glyphs, s32 capacity, s32 value, s32 font, const float* origin)
{
    float rect[4];
    char digits[0x100];
    void* fontData;
    u8* character;
    s32 i;
    s32 length;

    fontData = H_Maestro_001120a0(font);
    sprintf(digits, "%d", value);
    K_ASSERT(capacity >= length, 0x38);
    for (i = 0; i < length; i++) {
        s32 index = length - 1 - i;

        character = *(u8**)((u8*)fontData + 0x184) + (digits[index] - 0x25) * 0x80;
        rect[0] = origin[0] + (float)(index * 15);
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

// FUN_00238dc0 NONMATCHING
void bpIFont00238dc0(void* glyphs, s32 capacity, const char* text, s32 font, const float* origin)
{
    void* fontData;
    s32 i;
    s32 length;
    float start;

    fontData = H_Maestro_001120a0(font);
    length = (s32)strlen(text);
    K_ASSERT(capacity >= length, 0x7a);
    start = origin[0] + (capacity * 15.0f - length * 15.0f) * 0.5f;
    for (i = 0; i < length; i++) {
        bpIFontPlace((u8*)glyphs + i * 0x100, fontData, text[length - i - 1] - 0x25,
                      start + i * 15.0f, origin[1]);
    }
    for (; i < capacity; i++) {
        bpIFontPlace((u8*)glyphs + i * 0x100, fontData, 0, origin[0], origin[1]);
    }
}

// FUN_00238fd0 NONMATCHING
void bpIFont00238fd0(void* glyph, s32 character, s32 style)
{
    void* camera;
    void* fontData;
    u8* source;
    float inverseScale;
    float x0;
    float y0;
    float x1;
    float y1;
    s32 i;

    camera = kwlnGetMainCamera();
    inverseScale = 1.0f / *(float*)((u8*)camera + 0x80);
    fontData = H_Maestro_001120a0(style);
    source = *(u8**)((u8*)fontData + 0x184) + (character + 0xb) * 0x80;
    x0 = (float)*(s32*)(source + 0x54) / (float)*(s32*)(source + 0xc);
    y0 = (float)*(s32*)(source + 0x58) / (float)*(s32*)(source + 0x10);
    x1 = (float)*(s32*)(source + 0x5c) / (float)*(s32*)(source + 0xc);
    y1 = (float)*(s32*)(source + 0x60) / (float)*(s32*)(source + 0x10);
    for (i = 0; i < 4; i++) {
        float* quad = (float*)((u8*)glyph + i * 0x40);
        quad[2] = inverseScale;
        quad[8] = 255.0f;
        quad[9] = 255.0f;
        quad[10] = 255.0f;
        quad[11] = 255.0f;
    }
    ((float*)((u8*)glyph + 0x00))[4] = x0;
    ((float*)((u8*)glyph + 0x00))[5] = y0;
    ((float*)((u8*)glyph + 0x40))[4] = x1;
    ((float*)((u8*)glyph + 0x40))[5] = y0;
    ((float*)((u8*)glyph + 0x80))[4] = x0;
    ((float*)((u8*)glyph + 0x80))[5] = y1;
    ((float*)((u8*)glyph + 0xc0))[4] = x1;
    ((float*)((u8*)glyph + 0xc0))[5] = y1;
}
