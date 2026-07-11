#include "Utils.h"
#include "Kosaka/k_assert.h"
#include "Main/OpEd/op_fade_mid.h"
#include "Kernel/Kwln/kwlnTask.h"

/* GP-owned work records are shared with the adjacent opening/ending TU. */
#define sOpTailA gOpWorkD0
#define sOpTailB (*(u32 **)(uintptr_t)0x007ce3d4)
#define sOpTailC DAT_007ce3d8
#define sOpTailD (*(u32 **)(uintptr_t)0x007ce3dc)
#define sOpTailE (*(u32 **)(uintptr_t)0x007ce3e0)
extern u32 *DAT_007ce3d8;
extern u32 *DAT_007ce3e4;
#define sOpTailF DAT_007ce3e4
#define sOpTailG (*(u32 **)(uintptr_t)0x007ce3e8)
#define OP_F80BC (*(volatile float*)(uintptr_t)0x007cadac)
#define OP_F80D8 (*(volatile float*)(uintptr_t)0x007cadc8)
#define OP_F81F8 (*(volatile float*)(uintptr_t)0x007caee8)
#define OP_F82BC (*(volatile float*)(uintptr_t)0x007cafac)
#define OP_F82C0 (*(volatile float*)(uintptr_t)0x007cafb0)
#define OP_F82C4 (*(volatile float*)(uintptr_t)0x007cafb4)
#define OP_F82FC (*(volatile float*)(uintptr_t)0x007cafec)
#define OP_F839C (*(volatile float*)(uintptr_t)0x007cb08c)

extern void func_003b0170(u32 resource);
extern u32 func_003b0970(u32 resource, s32 mode, s32 group, s32 a, s32 b);
extern void func_003b0d70(u32 resource, s32 x, s32 y);
extern void func_003b0e54(u32 resource, u32 color);
extern void func_003b0e70(s32 mode);
extern void* (*DAT_00960178)(u32 size, u32 heap);
extern void (*DAT_0096017c)(void* memory);
extern void func_003b1360(u32 resource, s32 visible, s32 flags);
extern s32 func_003b19d0(u32 resource);
extern void func_00521250(void* dst, const void* src, u32 size);
extern s32 func_00524388(const char* text);
extern void func_00524828(char* dst, const char* src, s32 size);
extern void func_005225a8(const void* text, ...);
extern u32 func_0016f190(s32 id);
extern void func_001985b0(u8 r, u8 g, u8 b, u8 a);
extern u32 func_0017d800(void);
extern void* func_001016b0(void* resource);
extern void* func_00102100(void* resource, s32 index, u32* size);
extern void func_00100ec0(void* resource);
extern void* func_00100d80(const void* descriptor, s32 flags);
extern void func_003af770(s32 slot, void* data);
extern void func_003afc30(s32 slot);
extern void* func_00194b80(void* parent, u32 priority, const char* name,
                           void* update, void* destroy, void* work);
extern void* func_00194e10(const char* name, u32 size, u32 a, u32 b, void* update,
                           void* destroy, u32 flags);
extern void func_00195550(void* task, void* resource);
extern s32 func_00195460(void* task, ...);
extern void func_00108570(void);
extern void func_001085c0(void);
extern u32 func_00108710(void);
extern void* func_0010bce0(void* task, u32 id);
extern void func_00195020(u32 resource);
extern void func_001749a0(u32 id);
extern void func_00176680(void* dst, u32 id);
extern void func_003c9850(s32 a, s32 b, s32 c, s32 d);
extern void func_003c9b00(u32 resource, const void* data, s32 mode);
extern void func_003c9cd0(u32 resource, s32 value);
extern void func_003c9d00(u32 resource, s32 value);
extern void func_003c9e00(u32 resource, s32 value);
extern s32 func_003c9ab0(u32 resource);
extern void func_00238980(void* dst, s32 count, u32 value, s32 mode);
extern u32 func_0021c3f0(s32 id);
extern u32 func_0021cca0(u32 resource, s32 id);
extern u32 func_0021cce0(u32 resource);
extern void func_0021d3b0(void* dst, u32 resource);
extern void func_0021d8e0(void* dst, const void* value);
extern void func_0021d950(void* dst, const void* value);
extern s32 func_004c9d10(u32 value);
extern void func_004c9d00(u32 value);
extern void func_004d7f60(s32 a, u32 b);
extern u32 func_00198590(void);
extern void (*DAT_00960090)(s32 state, u32 value);
extern void (*DAT_00960094)(s32 state, void* value);
extern void (*DAT_0096009c)(void* vertices, s32 stride, s32 mode, s32 a, s32 b);
extern void func_00521408(void* dst, s32 value, u32 size);

void func_0027a3b0(void);
u32* func_0027a4a0(void);
void func_0027a560(u32* work);
void func_0027a5d0(void);
void func_0027a6a0(u32* work, char* text, s32 align);
void func_0027a930(u32* work, const float* pos);
void func_0027aa00(u32* work, const u8* color);
u8 func_0027aaa0(void);
u8 func_0027ab10(void);
void func_0027ab80(void);
u32 func_0027b070(void);
void func_0027b200(void);
void func_0027ace0(void);
u32 func_0027b310(void);
void func_0027b3f0(s32 param);
void func_0027b6c0(void);
void func_0027bdf0(void);
void func_0027ac60(u32* work);
void func_0027ac80(void);
void func_0027ace0(void);
void func_0027ae90(void);
u32 func_0027af80(void);
void func_0027afd0(void);
void func_0027b0b0(void);
u32 func_0027b2b0(void);
u32 func_0027b460(void);
void func_0027b5b0(u32* work);
void func_0027b5d0(void);
void func_0027b610(void);
void func_0027b6c0(void);
void func_0027b880(void);
void func_0027b9f0(void);
void func_0027ba90(void);
void func_0027bae0(const u32* value);

// FUN_00279120 NONMATCHING
void func_00279120(void)
{
    s32 i;
    u32* work;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = sOpTailA;
    for (i = 0; i < (s32)work[0x3738 / 4]; i++) {
        func_003b0170(work[0x110 / 4 + i * (0x110 / 4)]);
    }
    work[0x3738 / 4] = 0;
}

// FUN_002791b0 NONMATCHING
void func_002791b0(u32 id)
{
    u32* work;
    u32 handle;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = sOpTailA + sOpTailA[0x3738 / 4] * (0x110 / 4);
    func_003b0e70(1);
    func_003b0e90(2);
    handle = func_003b0970((u32)(uintptr_t)0 + (id & 0xffff) * 0x13, 1, 6, 0, 0);
    func_003b0d70(handle, 0x640, 0x320);
    func_003b2c60(handle, 0.0f);
    work[0x100 / 4] = handle;
    func_003b0e90(1);
    func_003b0e70(2);
    sOpTailA[0x3738 / 4]++;
}

// FUN_002792c0 NONMATCHING
void func_002792c0(void)
{
    u32* work;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = sOpTailA;
    if ((work[0] & 2) != 0) {
        func_003b0170(work[0xe54]);
    }
    work[0] &= ~2u;
}

// FUN_00279330 NONMATCHING
void func_00279330(u32 id)
{
    u32* work;
    u32 handle;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = sOpTailA;
    K_ASSERT((work[0] & 2) != 0, 0x3e0);
    func_003b0e70(1);
    func_003b0e90(2);
    handle = func_003b0970((u32)(uintptr_t)0 + (id & 0xffff) * 0x13, 1, 6, 0, 0);
    func_003b0d70(handle, 0x640, 0x320);
    func_003b2c60(handle, 0.0f);
    work[0xe54] = handle;
    func_003b0e90(1);
    func_003b0e70(2);
    work[0] |= 2;
}


// FUN_00279510 NONMATCHING
void func_00279510(s32 index, u32 value)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    *(u32*)((u8*)sOpTailA + index * 0x720 + 0x890) = value;
}

// FUN_00279580 NONMATCHING
void func_00279580(s32 index, u32 value)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    *(u32*)((u8*)sOpTailA + index * 0x720 + 0xaa0) = value;
}

// FUN_002795f0 NONMATCHING
void func_002795f0(s32 index, u32 value)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    *(u32*)((u8*)sOpTailA + index * 0x720 + 0xaa4) = value;
}

// FUN_00279660 NONMATCHING
void func_00279660(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    sOpTailA[0] |= 8;
}

// FUN_002796b0 NONMATCHING
void func_002796b0(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    sOpTailA[0xdcf] = 0;
    sOpTailA[0] |= 4;
}

// FUN_00279700 NONMATCHING
u32 func_00279700(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    return sOpTailA[0] & 4;
}

// FUN_00279750 NONMATCHING
void func_00279750(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    sOpTailA[0xdd1] = 0;
    sOpTailA[0] |= 0x10;
}

// FUN_002797a0 NONMATCHING
u32 func_002797a0(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    return sOpTailA[0] & 0x10;
}

// FUN_002797f0 NONMATCHING
void func_002797f0(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    sOpTailA[0] |= 0x20;
}

// FUN_00279840 NONMATCHING
void func_00279840(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    sOpTailA[0] &= ~0x20u;
}

// FUN_00279890 NONMATCHING
void func_00279890(u32 a, u32 b)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    sOpTailA[0x3b60 / 4] = a;
    sOpTailA[0x3b64 / 4] = b;
}

// FUN_002798f0 NONMATCHING
void func_002798f0(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    sOpTailA[0] |= 0x40;
}
// FUN_00279940 NONMATCHING
u32* func_00279940(const u32* header)
{
    u32 i;
    u32 span;
    u8* bytes;
    u32* out;
    u32* table;
    u32 cursor;

    span = header[3] * 4 + 0x14 + header[6];
    if ((span & 3) != 0) {
        span += 4 - (span & 3);
    }
    out = (u32*)(*DAT_00960178)(span + header[2], 0x40000);
    out[2] = (u32)(out + 5);
    table = out + 5 + header[3];
    if (((u32)table & 3) != 0) {
        table = (u32*)((u8*)table + (4 - ((u32)table & 3)));
    }
    out[3] = (u32)table;
    span = (u32)table + header[6];
    if ((span & 3) != 0) {
        span += 4 - (span & 3);
    }
    out[4] = span;
    out[1] = header[3];
    out[0] = header[0];
    func_00521250((void*)out[3], (const u8*)header + header[5], header[6]);
    func_00521250((void*)out[4], (const u8*)header + header[1], header[2]);
    bytes = (u8*)header + header[4];
    cursor = out[3];
    for (i = 0; i < header[3]; i++) {
        out[2 + i] = cursor;
        cursor += *bytes++;
    }
    return out;
}

// FUN_00279ac0 NONMATCHING
void func_00279ac0(u32 value)
{
    ((void (*)(void*))DAT_0096017c)((void*)(uintptr_t)value);
}

// FUN_00279AF0
u32 func_00279af0(const u32* work, s32 index)
{
    return *(const u32 *)(index * sizeof(u32) + work[2]);
}

// FUN_00279b10
u32 func_00279b10(const u32* work)
{
    return work[4];
}

// FUN_00279b20
u32 func_00279b20(const u32* work)
{
    return work[1];
}

// FUN_00279b30 NONMATCHING
void func_00279b30(u32* work)
{
    s32 i;
    u32 dark;

    work[0] = 0;
    ((u8*)work)[0x122c] = 0xff;
    ((u8*)work)[0x122d] = 0xff;
    ((u8*)work)[0x122e] = 0xff;
    ((u8*)work)[0x122f] = 0xff;
    dark = func_0016f190(0xb8e);
    if (dark == 0) {
        func_001985b0(0xf, 0x1f, 0x28, 0xff);
    } else {
        func_001985b0(0xff, 0xff, 0xff, 0xff);
    }
    for (i = 0; i < 0x20; i++) {
        work[i * 0x24 + 1] = 0;
    }
    sOpTailB = work;
}

// FUN_00279bf0 NONMATCHING
void func_00279bf0(void)
{
    s32 i;
    u32* work;

    K_ASSERT(sOpTailB != NULL, 0x58);
    work = sOpTailB;
    for (i = 0; i < 0x20; i++) {
        u32* record = work + i * 0x24 + 1;
        if ((record[0] & 1) != 0) {
            func_0027a560(record);
        }
    }
    sOpTailB = NULL;
}

// FUN_00279c90 NONMATCHING
void func_00279c90(void)
{
    u32* work;

    K_ASSERT(sOpTailB != NULL, 0x58);
    work = sOpTailB;
    work[0x484] = 0;
    work[0x485] = 0;
    work[0x486] = 0x43e00000;
    work[0x487] = 0x43e00000;
    work[0x481] = 0;
    work[0x482] = 0;
    work[0x483] = 0;
    func_0027a5d0();
    work[0] |= 1;
    work[0x489] = 0;
}

// FUN_00279d10 NONMATCHING
u32 func_00279d10(void)
{
    K_ASSERT(sOpTailB != NULL, 0x58);
    return sOpTailB[0] & 1;
}

// FUN_00279d60 NONMATCHING
void func_00279d60(void)
{
    u32* work;
    u32 stream;
    u32 frame;
    s32 phase;
    s32 i;
    s32 frameRate;
    f32 step;
    f32 drift;
    f32 height;
    s32 segmentFrames;
    u8 alpha;
    u32 parse;
    u32 align;

    K_ASSERT(sOpTailB != NULL, 0x58);
    work = sOpTailB;
    if ((work[0] & 1) == 0) {
        return;
    }
    if ((work[0] & 4) != 0) {
        work[0x48a] = *(u32*)((u8*)(uintptr_t)work[0x488] + 0x8c);
        work[0x481] = 0;
        work[0x489] = 1;
        work[0] &= ~4u;
        func_001985b0(0, 0, 0, 0xff);
    }
    frameRate = func_0017d800() == 0 ? 0x1e : 0x3c;
    drift = func_0017d800() == 0 ? OP_F80D8 : OP_F82BC;
    if (work[0x489] == 1) {
        if (func_0017d800() == 0) {
            step = OP_F82C0 / (((f32)work[0x48a] - 208.0f) * 2.0f);
            segmentFrames = (s32)(OP_F80D8 / step);
        } else {
            step = OP_F82C4 / (((f32)work[0x48a] - 208.0f) * 2.0f);
            segmentFrames = (s32)(OP_F82BC / step);
        }
        frame = work[0x481];
        phase = segmentFrames;
        if ((s32)frame < phase) {
            work[0x481] = frame + 1;
            if (func_0017d800() == 0) {
                drift = OP_F80D8 - step * (f32)(s32)work[0x481];
                *(f32*)((u8*)(uintptr_t)work[0x488] + 0x8c) =
                    (f32)work[0x48a] -
                    (OP_F80D8 * (f32)(s32)work[0x481] -
                     (f32)(s32)work[0x481] * step * 0.5f *
                         (f32)(s32)work[0x481]);
            } else {
                drift = OP_F82BC - step * (f32)(s32)work[0x481];
                *(f32*)((u8*)(uintptr_t)work[0x488] + 0x8c) =
                    (f32)work[0x48a] -
                    (OP_F82BC * (f32)(s32)work[0x481] -
                     (f32)(s32)work[0x481] * step * 0.5f *
                         (f32)(s32)work[0x481]);
            }
        } else if ((s32)frame < phase + frameRate) {
            work[0x481] = frame + 1;
            drift = 0.0f;
            *(f32*)((u8*)(uintptr_t)work[0x488] + 0x8c) = 208.0f;
        } else if ((s32)frame < phase + frameRate + 0x2d) {
            work[0x481] = frame + 1;
            alpha = (u8)(((phase + frameRate + 0x2d - (s32)(frame + 1)) * 255) / 45);
            ((u8*)work)[0x122f] = alpha;
            drift = 0.0f;
            *(f32*)((u8*)(uintptr_t)work[0x488] + 0x8c) = 208.0f;
        } else {
            drift = 0.0f;
            *(f32*)((u8*)(uintptr_t)work[0x488] + 0x8c) = 208.0f;
            work[0] &= ~1u;
        }
    }
    stream = func_0027b070();
    if ((work[0] & 2) == 0) {
        parse = 1;
        align = 0;
        while ((f32)work[0x487] - drift < 448.0f && parse != 0) {
            u8 type = func_0027aaa0();
            if (type == 4) {
                work[0x487] = (u32)((f32)work[0x487] + 12.0f);
                func_005225a8((const void*)0x68ef78);
            } else if (type == 3) {
                work[0x487] = (u32)((f32)func_0027ab10() * 24.0f + (f32)work[0x487]);
                func_005225a8((const void*)0x68ef70);
            } else if (type == 2) {
                align = 1;
                func_005225a8((const void*)0x68ef60);
            } else if (type == 1) {
                u32* entry = func_0027a4a0();
                u32 text = func_00279af0((const u32*)(uintptr_t)stream, work[0x482]);
                func_0027a6a0(entry, (char*)(uintptr_t)text, align);
                work[0x482]++;
                if (work[0x482] == func_00279b20((const u32*)(uintptr_t)stream)) {
                    work[0x488] = (u32)entry;
                    work[0] |= 4;
                }
                *(u32*)((u8*)entry + 0x8c) = work[0x487];
                work[0x487] = (u32)((f32)work[0x487] + 24.0f);
                align = 0;
                func_005225a8((const void*)0x68ef50);
            } else if (type == 0) {
                work[0] |= 2;
                parse = 0;
                work[0x487] = (u32)((f32)work[0x487] + drift);
            }
            func_0027ab80();
        }
    }
    for (i = 0; i < 0x20; i++) {
        u32* record = work + i * 0x24 + 1;
        if ((record[0] & 1) != 0) {
            if (((f32)record[0x24] - drift) + 24.0f < 0.0f) {
                func_0027a560(record);
            }
            record[0x24] = (u32)((f32)record[0x24] - drift);
        }
    }
    work[0x487] = (u32)((f32)work[0x487] - drift);
    func_0027a5d0();
}

// FUN_0027a3b0 NONMATCHING
void func_0027a3b0(void)
{
    s32 i;
    s32 j;
    u32* work;

    K_ASSERT(sOpTailB != NULL, 0x58);
    work = sOpTailB;
    if ((work[0] & 1) == 0) {
        return;
    }
    for (i = 0; i < 0x20; i++) {
        u32* record = work + i * 0x24 + 1;
        if ((record[0] & 1) != 0) {
            for (j = 0; j < (s32)record[0x22]; j++) {
                func_003b1360(record[j * 2 + 2], 1, 0);
            }
        }
    }
}

// FUN_0027a4a0 NONMATCHING
u32* func_0027a4a0(void)
{
    s32 i;
    u32* record;

    K_ASSERT(sOpTailB != NULL, 0x58);
    for (i = 0; i < 0x20; i++) {
        record = sOpTailB + i * 0x24 + 1;
        if ((record[0] & 1) == 0) {
            record[0] |= 1;
            return record;
        }
    }
    K_ASSERT(false, 0x197);
    return record;
}

// FUN_0027a560
void func_0027a560(u32* record)
{
    s32 i;

    for (i = 0; i < (s32)record[0x21]; i++) {
        func_003b0170(*(u32*)((u8*)record + i * 8 + 8));
    }
    record[0] &= ~1u;
}

// FUN_0027a5d0 NONMATCHING
void func_0027a5d0(void)
{
    s32 i;
    u32* work;
    u32 pos[2];

    K_ASSERT(sOpTailB != NULL, 0x58);
    work = sOpTailB;
    for (i = 0; i < 0x20; i++) {
        u32* record = work + i * 0x24 + 1;
        if ((record[0] & 1) != 0) {
            pos[0] = 0x42640000;
            pos[1] = record[0x23];
            func_0027a930(record, (const float*)pos);
            func_0027aa00(record, (const u8*)(work + 0x122c / 4));
        }
    }
}
// FUN_0027a6a0 NONMATCHING
void func_0027a6a0(u32* work, char* text, s32 align)
{
    s32 length;
    s32 i;
    s32 count;
    s32 tokenLength;
    s32 width;
    char* cursor;
    u8 inToken;
    u8 style;
    u8 mode;
    char token[256];

    length = func_00524388(text);
    count = 0;
    width = 0;
    inToken = 0;
    cursor = text;
    func_003b0e70(1);
    func_003b0e90(2);
    for (i = 0; i < length + 1; i++) {
        char c = *cursor;
        if (c == '\t' || c == '\0' || c == ' ') {
            if (inToken != 0) {
                tokenLength = (s32)(cursor - text);
                func_00524828(token, text, tokenLength);
                token[tokenLength] = 0;
                if (align == 1) {
                    style = 7;
                    mode = 1;
                } else {
                    style = 6;
                    mode = 0;
                }
                {
                    u32 handle = func_003b0970((u32)(uintptr_t)token, style, mode, 0, 0);
                    func_003b2c60(handle, 0.0f);
                    func_003b0e54(handle, 0xffffffff);
                    work[2 + count * 2] = handle;
                    *(f32*)((u8*)work + 4 + count * 8) = (f32)width;
                    count++;
                    text += tokenLength;
                    width += func_003b19d0(handle);
                    inToken = 0;
                }
            }
        } else {
            inToken = 1;
        }
        if (c == '\t') {
            width += 40;
            text++;
        } else if (c == ' ') {
            width += 10;
            text++;
        }
        cursor++;
    }
    func_003b0e90(1);
    func_003b0e70(2);
    work[0x84 / 4] = count;
}

// FUN_0027a930 NONMATCHING
void func_0027a930(u32* work, const f32* pos)
{
    s32 i;

    for (i = 0; i < (s32)work[0x84 / 4]; i++) {
        u32* entry = (u32*)((u8*)work + i * 8);
        func_003b0d70(entry[2], (s32)((pos[0] + *(f32*)((u8*)entry + 4)) * 16.0f),
                      (s32)(pos[1] * 8.0f));
        func_003b2c60(entry[2], 0.0f);
    }
}

// FUN_0027aa00 NONMATCHING
void func_0027aa00(u32* work, const u8* color)
{
    u32 packed;
    s32 i;

    packed = (u32)color[3] | (u32)color[2] << 8 | (u32)color[0] << 24 |
             (u32)color[1] << 16;
    for (i = 0; i < (s32)work[0x84 / 4]; i++) {
        func_003b0e54(work[2 + i * 2], packed);
    }
}

// FUN_0027aaa0 NONMATCHING
u8 func_0027aaa0(void)
{
    u32 stream;
    u32 base;

    K_ASSERT(sOpTailB != NULL, 0x58);
    stream = func_0027b070();
    base = func_00279b10((const u32*)(uintptr_t)stream);
    return *(u8*)(uintptr_t)(base + sOpTailB[0x120c / 4]);
}

// FUN_0027ab10 NONMATCHING
u8 func_0027ab10(void)
{
    u32 stream;
    u32 base;

    K_ASSERT(sOpTailB != NULL, 0x58);
    stream = func_0027b070();
    base = func_00279b10((const u32*)(uintptr_t)stream);
    return *(u8*)(uintptr_t)(base + sOpTailB[0x120c / 4] + 1);
}

// FUN_0027ab80 NONMATCHING
void func_0027ab80(void)
{
    u32 stream;
    u32 base;
    s32 offset;
    u8 command;

    K_ASSERT(sOpTailB != NULL, 0x58);
    stream = func_0027b070();
    base = func_00279b10((const u32*)(uintptr_t)stream);
    offset = sOpTailB[0x120c / 4];
    command = *(u8*)(uintptr_t)(base + offset);
    if (command == 4 || command == 2 || command == 1) {
        sOpTailB[0x120c / 4] = offset + 1;
    } else if (command == 3) {
        sOpTailB[0x120c / 4] = offset + 2;
    }
}
// FUN_0027AC60
void func_0027ac60(u32* work)
{
    work[0] = 0;
    work[1] = 0;
    sOpTailC = work;
}

// FUN_0027ac80
void func_0027ac80(void)
{
    K_ASSERT(sOpTailC != NULL, 0x31);
    if ((sOpTailC[1] & 1) != 0) {
        func_0027afd0();
    }
    sOpTailC = NULL;
}

// FUN_0027ace0 NONMATCHING
void func_0027ace0(void)
{
    u32* work;
    u32 size;
    s32 i;
    void* data;
    void* copy;

    K_ASSERT(sOpTailC != NULL, 0x31);
    work = sOpTailC;
    if ((work[0] & 1) != 0 && func_001016b0((void*)(uintptr_t)work[2]) != NULL) {
        for (i = 0; i < 3; i++) {
            data = func_00102100((void*)(uintptr_t)work[2], i, &size);
            if (i == 2) {
                copy = (*DAT_00960178)(size, 0x40000);
                func_00521250(copy, data, size);
                func_003af770(7, copy);
            } else if (i == 1) {
                copy = (*DAT_00960178)(size, 0x40000);
                func_00521250(copy, data, size);
                func_003af770(6, copy);
            } else {
                work[3] = (u32)func_00279940((const u32*)data);
            }
        }
        work[1] |= 1;
        func_00100ec0((void*)(uintptr_t)work[2]);
        work[0] &= ~1u;
    }
}

// FUN_0027ae90 NONMATCHING
void func_0027ae90(void)
{
    u32* work;
    void* resource;

    K_ASSERT(sOpTailC != NULL, 0x31);
    work = sOpTailC;
    K_ASSERT((work[0] & 1) != 0, 0x76);
    K_ASSERT((work[1] & 1) != 0, 0x77);
    if (func_0017d800() == 0) {
        resource = func_00100d80((const void*)0x68ef90, 1);
    } else {
        resource = func_00100d80((const void*)0x68efa0, 1);
    }
    work[2] = (u32)resource;
    work[0] |= 1;
}

// FUN_0027af80
u32 func_0027af80(void)
{
    K_ASSERT(sOpTailC != NULL, 0x31);
    return sOpTailC[0] & 1;
}

// FUN_0027afd0
void func_0027afd0(void)
{
    u32* work;

    K_ASSERT(sOpTailC != NULL, 0x31);
    work = sOpTailC;
    K_ASSERT((work[1] & 1) != 0, 0x8e);
    func_00279ac0(work[3]);
    func_003afc30(6);
    func_003afc30(7);
    work[1] &= ~1u;
}

// FUN_0027b070
u32 func_0027b070(void)
{
    K_ASSERT(sOpTailC != NULL, 0x31);
    return sOpTailC[3];
}

// FUN_0027b0b0 NONMATCHING
void func_0027b0b0(void)
{
    u32* work;
    u32 state;

    K_ASSERT(sOpTailD != NULL, 0x3d);
    work = sOpTailD;
    if ((work[0] & 1) == 0) {
        return;
    }
    state = work[0x493];
    if (state == 3) {
        if (func_00108710() != 0) {
            work[0] &= ~1u;
        }
    } else if (state == 2) {
        work[0x495]++;
        if (func_00279d10() == 0 &&
            kwlnTaskExists((KwlnTask*)(uintptr_t)work[0x494]) == 0) {
            func_00108570();
            work[0x493] = 3;
        }
    } else if (state == 1) {
        if (func_00108710() != 0) {
            func_0027b200();
        }
    } else if (state == 0 && func_0027af80() == 0) {
        func_001085c0();
        work[0x493] = 1;
    }
    func_0027ace0();
    func_00279d60();
}

// FUN_0027b200 NONMATCHING
void func_0027b200(void)
{
    u32* work;
    u32 id;
    void* task;

    K_ASSERT(sOpTailD != NULL, 0x3d);
    work = sOpTailD;
    if (func_0017d800() == 0) {
        id = func_0016f190(0xb8e) == 0 ? 0x21 : 0x20;
    } else {
        id = 0x2a;
    }
    func_00279c90();
    task = func_0010bce0((void*)(uintptr_t)work[1], id);
    work[0x1250] = (u32)task;
    work[0x1254] = 0;
    work[0x124c] = 2;
}

// FUN_0027b2b0 NONMATCHING
u32 func_0027b2b0(void)
{
    func_0027b0b0();
    K_ASSERT(sOpTailD != NULL, 0x3d);
    return (sOpTailD[0] & 1) != 0 ? 0 : (u32)-1;
}

// FUN_0027b310 NONMATCHING
u32 func_0027b310(void)
{
    u32 context;
    u32 saved;

    context = func_00198590();
    if (func_004c9d10(context) != 0) {
        (*DAT_00960094)(0xe, &saved);
        (*DAT_00960090)(0xe, 0);
        K_ASSERT(sOpTailD != NULL, 0x3d);
        if ((sOpTailD[0] & 1) != 0) {
            func_0027a3b0();
        }
        (*DAT_00960090)(0xe, saved);
        context = func_00198590();
        func_004c9d00(context);
    }
    return 0;
}

// FUN_0027b3f0 NONMATCHING
void func_0027b3f0(s32 param)
{
    K_ASSERT(sOpTailD != NULL, 0x3d);
    func_00279bf0();
    func_0027ac80();
    ((void (*)(void*))DAT_0096017c)(*(void**)((u8*)(uintptr_t)param + 0x3c));
}

// FUN_0027b460 NONMATCHING
u32 func_0027b460(void)
{
    u32* work;
    void* task;
    void* resource;
    void* memory;
    u32* root;

    if (*(u32*)(uintptr_t)0x007ce3e0 == 0) {
        memory = (*DAT_00960178)(0x1258, 0x40000);
        task = kwlnTaskCreateWithAutoPriority(NULL, 10, (const char*)(uintptr_t)0x007cc4f8,
                                              (KwlnTaskUpdateFunc)func_0027b2b0,
                                              (KwlnTaskDestroyFunc)func_0027b3f0, memory);
        resource = kwlnTaskInitEx((const char*)0x68efb8, 0x1cd8, 1, 2,
                                  (KwlnTaskUpdateFunc)func_0027b310, NULL, NULL);
        root = (u32*)memory;
        root[2] = (u32)resource;
        kwlnTaskAddChild(task, resource);
        root[0] = 0;
        func_0027ac60(root + 3);
        func_00279b30(root + 7);
        root[1] = (u32)task;
        sOpTailD = root;
        K_ASSERT(memory != NULL, 0x3d);
        func_0027ae90();
        sOpTailD[0x493] = 0;
        sOpTailD[0] |= 1;
        *(u32*)(uintptr_t)0x007ce3e0 = (u32)task;
        return 0;
    }
    if (kwlnTaskExists((KwlnTask*)(uintptr_t)*(u32*)(uintptr_t)0x007ce3e0) == 0) {
        *(u32*)(uintptr_t)0x007ce3e0 = 0;
        return 1;
    }
    return 0;
}

// FUN_0027B5B0
void func_0027b5b0(u32* work)
{
    work[0] = 0;
    work[0x114 / 4] = 0x42c80000;
    work[0x118 / 4] = 0x42c80000;
    sOpTailF = work;
}

// FUN_0027b5d0
void func_0027b5d0(void)
{
    K_ASSERT(sOpTailF != NULL, 0x27);
    sOpTailF = NULL;
}

// FUN_0027b610 NONMATCHING
void func_0027b610(void)
{
    u32 flags;

    K_ASSERT(sOpTailF != NULL, 0x27);
    flags = sOpTailF[0];
    if ((flags & 1) != 0) {
        if ((flags & 2) == 0) {
            if (sOpTailF[0x44] < 0x14) {
                sOpTailF[0x44]++;
            }
        } else if (sOpTailF[0x44] < 0x14) {
            sOpTailF[0x44]++;
        } else {
            sOpTailF[0] = flags & ~1u;
        }
        func_0027b6c0();
    }
}

// FUN_0027b6c0 NONMATCHING
void func_0027b6c0(void)
{
    u32 texture;
    u32 descriptor;
    u32 values[2];
    u8 color[4];
    f32 alpha;
    f32 width;
    f32 height;

    K_ASSERT(sOpTailF != NULL, 0x27);
    texture = func_0021c3f0(2);
    descriptor = func_0021cca0(texture, 0x3a);
    values[0] = sOpTailF[0x45];
    values[1] = sOpTailF[0x46];
    width = (f32)*(s32*)((u8*)(uintptr_t)descriptor + 0xc);
    height = (f32)*(s32*)((u8*)(uintptr_t)descriptor + 0x10);
    values[0] = (u32)width;
    values[1] = (u32)height;
    func_0021d8e0(sOpTailF + 4, values);
    if ((sOpTailF[0] & 2) == 0) {
        alpha = sOpTailF[0x44] < 0x14 ? (f32)sOpTailF[0x44] / 20.0f : 1.0f;
    } else {
        alpha = sOpTailF[0x44] < 0x14 ? 1.0f - (f32)sOpTailF[0x44] / 20.0f : 0.0f;
    }
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(alpha * 255.0f);
    func_0021d950(sOpTailF + 4, color);
}

// FUN_0027b880 NONMATCHING
void func_0027b880(void)
{
    u32 texture;
    u32 descriptor;

    K_ASSERT(sOpTailF != NULL, 0x27);
    texture = func_0021c3f0(2);
    if ((sOpTailF[0] & 1) != 0) {
        (*DAT_00960090)(9, 2);
        (*DAT_00960090)(0x14, 2);
        (*DAT_00960090)(8, 0);
        (*DAT_00960090)(6, 0);
        descriptor = func_0021cce0(func_0021cca0(texture, 0x3a));
        (*DAT_00960090)(1, descriptor);
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        (*DAT_0096009c)(sOpTailF + 4, 4, 0, 1, 2);
        (*DAT_0096009c)(sOpTailF + 4, 4, 0, 2, 3);
    }
}

// FUN_0027b9f0 NONMATCHING
void func_0027b9f0(void)
{
    u32 texture;

    K_ASSERT(sOpTailF != NULL, 0x27);
    texture = func_0021cca0(func_0021c3f0(2), 0x3a);
    func_0021d3b0(sOpTailF + 4, texture);
    sOpTailF[0x44] = 0;
    sOpTailF[0] &= ~2u;
    func_0027b6c0();
    sOpTailF[0] |= 1;
}

// FUN_0027ba90 NONMATCHING
void func_0027ba90(void)
{
    K_ASSERT(sOpTailF != NULL, 0x27);
    sOpTailF[0x44] = 0;
    sOpTailF[0] |= 2;
}

// FUN_0027bae0 NONMATCHING
void func_0027bae0(const u32* value)
{
    K_ASSERT(sOpTailF != NULL, 0x27);
    sOpTailF[0x45] = value[0];
    sOpTailF[0x46] = value[1];
    if ((sOpTailF[0] & 1) != 0) {
        func_0027b6c0();
    }
}
