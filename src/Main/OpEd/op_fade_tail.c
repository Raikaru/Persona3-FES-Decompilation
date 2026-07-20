#include "Utils.h"
#include "Kosaka/k_assert.h"
#include "Main/OpEd/op_fade_mid.h"
#include "Kernel/Kwln/kwlnTask.h"

/* GP-owned work records are shared with the adjacent opening/ending TU. */
extern u32* DAT_007ce3d0;
#define sOpTailA DAT_007ce3d0
extern u32* DAT_007ce3d4;
#define sOpTailB DAT_007ce3d4
#define sOpTailC DAT_007ce3d8
extern u32* DAT_007ce3dc;
#define sOpTailD DAT_007ce3dc
extern u32* DAT_007ce3e0;
#define sOpTailE DAT_007ce3e0
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
extern volatile s32 iGpffff97f0;
extern f32 fGpffff80d8;
extern f32 fGpffff82bc;
extern f32 fGpffff82c0;
extern f32 fGpffff82c4;
extern u8 DAT_007cc4e8[1];
#define OP_F82FC (*(volatile float*)(uintptr_t)0x007cafec)
#define OP_F839C (*(volatile float*)(uintptr_t)0x007cb08c)

extern void func_003b0170(u32 resource);
extern u32 func_003b0970(const char* text, s32 mode, s32 group, s32 a, s32 b);
extern void func_003b0d70(u32 resource, s32 x, s32 y);
extern void func_003b0e54(u32 resource, u32 color);
extern void func_003b2c60(u32 resource, f32 angle);
extern void func_003b0e70(s32 mode);
extern void* (*DAT_00960178[])(u32 size, u32 heap);
extern void (*DAT_0096017c[])(void* memory);
extern void func_003b1360(u32 resource, s32 visible, s32 flags);
extern s32 func_003b19d0(u32 resource);
extern u8* DAT_007ce4ec;
extern void func_00521250(void* dst, const void* src, u32 size);
extern s32 func_00524388(const char* text);
extern void func_00524828(char* dst, const char* src, s32 size);
extern void func_005225a8(const void* text, ...);
extern u32 func_0016f190(s32 id);
extern void func_001985b0(u8 r, u8 g, u8 b, u8 a);
extern u32 func_0017d800(void);
extern void* func_001016b0(void* resource);
extern void* func_00102100(void* resource, s32 index, s32* size);
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
extern void (*DAT_00960090[])(s32 state, u32 value);
extern void (*DAT_00960094[])(s32 state, void* value);
extern void (*DAT_0096009c[])(void* vertices, s32 stride, s32 mode, s32 a, s32 b);
extern void func_00521408(void* dst, s32 value, u32 size);

void func_0027a3b0(void);
u32* func_0027a4a0(void);
void func_0027a560(u32* work);
void func_0027a5d0(void);
void func_0027a6a0(u32* work, char* text, s32 align);
void func_0027a930(u32* work, const float* pos);
void func_0027aa00(u32* work, const u8* color);
u32 func_0027aaa0(void);
s32 func_0027ab10(void);
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
typedef struct OpTailPosition {
    f32 x;
    f32 y;
} OpTailPosition;
void func_0027bae0(const OpTailPosition* value);

// FUN_00279120
void func_00279120(void)
{
    s32 i;
    u32* work;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = sOpTailA;
    for (i = 0; i < (s32)work[0x3738 / 4]; i++) {
        func_003b0170(*(u32*)((u8*)work + i * 0x110 + 0x110));
    }
    work[0x3738 / 4] = 0;
}

// FUN_002791b0
void func_002791b0(u32 id)
{
    u32* root;
    u32* work;
    u32 handle;

    K_ASSERT(sOpTailA != NULL, 0x61);
    root = sOpTailA;
    work = (u32*)((u8*)root + root[0x3738 / 4] * 0x110 + 0x10);
    func_003b0e70(1);
    func_003b0e90(2);
    handle = func_003b0970(
        (const char*)(DAT_007ce4ec + (id & 0xffff) * 0x13), 1, 6, 0, 0);
    func_003b0d70(handle, 0x640, 0x320);
    func_003b2c60(handle, 0.0f);
    work[0x100 / 4] = handle;
    func_003b0e90(1);
    func_003b0e70(2);
    root[0x3738 / 4]++;
}

// FUN_002792c0
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

// FUN_00279330
void func_00279330(u32 id)
{
    u32* work;
    u32 handle;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = sOpTailA;
    if ((~work[0] & 2) == 0) {
        K_Assert("brp_param.c", 0x3e0);
    }
    func_003b0e70(1);
    func_003b0e90(2);
    handle = func_003b0970(
        (const char*)(DAT_007ce4ec + (id & 0xffff) * 0x13), 1, 6, 0, 0);
    func_003b0d70(handle, 0x640, 0x320);
    func_003b2c60(handle, 0.0f);
    work[0xe54] = handle;
    func_003b0e90(1);
    func_003b0e70(2);
    work[0] |= 2;
}


// FUN_00279510
void func_00279510(s32 index, u32 value)
{
    u8* work;
    s32 byteOffset;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = (u8*)sOpTailA;
    byteOffset = index * 0x720;
    work = (u8*)((uintptr_t)byteOffset + (uintptr_t)work);
    *(u32*)(work + 0x890) = value;
}

// FUN_00279580
void func_00279580(s32 index, u32 value)
{
    u8* work;
    s32 byteOffset;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = (u8*)sOpTailA;
    byteOffset = index * 0x720;
    work = (u8*)((uintptr_t)byteOffset + (uintptr_t)work);
    *(u32*)(work + 0xaa0) = value;
}

// FUN_002795f0
void func_002795f0(s32 index, u32 value)
{
    u8* work;
    s32 byteOffset;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = (u8*)sOpTailA;
    byteOffset = index * 0x720;
    work = (u8*)((uintptr_t)byteOffset + (uintptr_t)work);
    *(u32*)(work + 0xaa4) = value;
}

// FUN_00279660
void func_00279660(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    sOpTailA[0] |= 8;
}

// FUN_002796b0
void func_002796b0(void)
{
    u32* work;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = sOpTailA;
    work[0xdcf] = 0;
    work[0] |= 4;
}

// FUN_00279700
u32 func_00279700(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    return sOpTailA[0] & 4;
}

// FUN_00279750
void func_00279750(void)
{
    u32* work;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = sOpTailA;
    work[0xdd1] = 0;
    work[0] |= 0x10;
}

// FUN_002797a0
u32 func_002797a0(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    return sOpTailA[0] & 0x10;
}

// FUN_002797f0
void func_002797f0(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    sOpTailA[0] |= 0x20;
}

// FUN_00279840
void func_00279840(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    sOpTailA[0] &= ~0x20u;
}

// FUN_00279890
void func_00279890(u32 a, u32 b)
{
    u32* work;

    K_ASSERT(sOpTailA != NULL, 0x61);
    work = sOpTailA;
    work[0x3b60 / 4] = a;
    work[0x3b64 / 4] = b;
}

// FUN_002798f0
void func_002798f0(void)
{
    K_ASSERT(sOpTailA != NULL, 0x61);
    sOpTailA[0] |= 0x40;
}
// FUN_00279940
u32* func_00279940(const u32* header)
{
    u32 size;
    u32* out;
    u32* data;
    u32 cursor;
    u32 i;
    u8* bytes;

    size = 0x14;
    size += header[3] * 4;
    if ((size & 3) != 0) {
        size += 4 - (size & 3);
    }
    size += header[6];
    if ((size & 3) != 0) {
        size += 4 - (size & 3);
    }
    size += header[2];
    data = out = (u32*)(*DAT_00960178)(size, 0x40000);
    data += 5;
    out[2] = (u32)data;
    /* Preserve the retail accumulator through both 4-byte alignment joins. */
    __asm__ volatile (
        "lw $v0, 0xc(%2)\n"
        "sll $v0, $v0, 2\n"
        "addu $v0, %3, $v0\n"
        "andi $a0, $v0, 3\n"
        "beqz $a0, 1f\n"
        "addiu $v1, $zero, 4\n"
        "subu $v1, $v1, $a0\n"
        "addu $v0, $v0, $v1\n"
        "1:\n"
        "sw $v0, 0xc(%1)\n"
        "lw $v1, 0x18(%2)\n"
        "addu $v0, $v0, $v1\n"
        "andi $a0, $v0, 3\n"
        "beqz $a0, 2f\n"
        "addiu $v1, $zero, 4\n"
        "subu $v1, $v1, $a0\n"
        "addu $v0, $v0, $v1\n"
        "2:\n"
        "sw $v0, 0x10(%1)"
        : "=r"(size) : "r"(out), "r"(header), "r"(data) : "memory");
    out[1] = header[3];
    out[0] = header[0];
    func_00521250((void*)out[3], (const u8*)header + header[5], header[6]);
    func_00521250((void*)out[4], (const u8*)header + header[1], header[2]);
    bytes = (u8*)header + header[4];
    cursor = out[3];
    for (i = 0; i < header[3]; i++, bytes++) {
        ((u32*)out[2])[i] = cursor;
        cursor += *bytes;
    }
    return out;
}

// FUN_00279ac0
void func_00279ac0(u32 value)
{
    (*DAT_0096017c)((void*)(uintptr_t)value);
}

// FUN_00279AF0
u32 func_00279af0(const u32* work, u32 index)
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

// FUN_00279b30
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
    if (dark != 0) {
        func_001985b0(0xff, 0xff, 0xff, 0xff);
    } else {
        func_001985b0(0xf, 0x1f, 0x28, 0xff);
    }
    for (i = 0; i < 0x20; i++) {
        *(u32*)((u8*)work + i * 0x90 + 4) = 0;
    }
    sOpTailB = work;
}

// FUN_00279bf0
void func_00279bf0(void)
{
    s32 i;
    u32* work;

    K_ASSERT(sOpTailB != NULL, 0x58);
    work = sOpTailB;
    for (i = 0; i < 0x20; i++) {
        u32* record = work + i * 0x24 + 1;
        if ((~record[0] & 1) == 0) {
            func_0027a560(record);
        }
    }
    sOpTailB = NULL;
}

// FUN_00279c90
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

// FUN_00279d10
u32 func_00279d10(void)
{
    K_ASSERT(sOpTailB != NULL, 0x58);
    return sOpTailB[0] & 1;
}

// FUN_00279d60
void func_00279d60(void)
{
    u32* work;
    u32* entry;
    u32 text;
    u32 stream;
    u32 frame;
    s32 i;
    s32 segmentFrames;
    s32 phaseEnd;
    s32 parse;
    s32 align;
    u32 type;
    f32 step;
    f32 drift;
    f32 height;
    f32 fade;

    K_ASSERT(sOpTailB != NULL, 0x58);
    work = sOpTailB;
    if ((~work[0] & 1) == 0) {
        if ((work[0] & 4) != 0) {
            *(f32*)(work + 0x48a) = *(f32*)((u8*)(uintptr_t)work[0x488] + 0x8c);
            work[0x481] = 0;
            work[0x489] = 1;
            work[0] &= ~4u;
            func_001985b0(0, 0, 0, 0xff);
        }
        if (func_0017d800() == 0) {
            iGpffff97f0 = 0x1e;
        } else {
            iGpffff97f0 = 0x3c;
        }
        switch (work[0x489]) {
        case 0:
            if (func_0017d800() == 0) {
                drift = fGpffff80d8;
            } else {
                drift = fGpffff82bc;
            }
            break;
        case 1:
            if (func_0017d800() == 0) {
                step = fGpffff82c0 / ((*(f32*)(work + 0x48a) - 208.0f) * 2.0f);
                segmentFrames = (s32)(fGpffff80d8 / step);
            } else {
                step = fGpffff82c4 / ((*(f32*)(work + 0x48a) - 208.0f) * 2.0f);
                segmentFrames = (s32)(fGpffff82bc / step);
            }
            frame = work[0x481];
            if ((s32)frame < segmentFrames) {
                work[0x481] = frame + 1;
                if (func_0017d800() == 0) {
                    f32 elapsed = (f32)(s32)work[0x481];
                    drift = fGpffff80d8 - step * elapsed;
                    *(f32*)((u8*)(uintptr_t)work[0x488] + 0x8c) =
                        *(f32*)(work + 0x48a) -
                        (fGpffff80d8 * elapsed - (step * 0.5f) * elapsed * elapsed);
                } else {
                    f32 elapsed = (f32)(s32)work[0x481];
                    drift = fGpffff82bc - step * elapsed;
                    *(f32*)((u8*)(uintptr_t)work[0x488] + 0x8c) =
                        *(f32*)(work + 0x48a) -
                        (fGpffff82bc * elapsed - (step * 0.5f) * elapsed * elapsed);
                }
            } else {
                phaseEnd = segmentFrames + iGpffff97f0;
                if ((s32)frame < phaseEnd) {
                    work[0x481] = frame + 1;
                    drift = 0.0f;
                    *(f32*)((u8*)(uintptr_t)work[0x488] + 0x8c) = 208.0f;
                } else if ((s32)frame < phaseEnd + 0x2d) {
                    work[0x481] = frame + 1;
                    fade = ((f32)(segmentFrames + iGpffff97f0 + 0x2d -
                                  (s32)(frame + 1)) *
                            255.0f) /
                           45.0f;
                    ((u8*)work)[0x122f] = (u8)fade;
                    drift = 0.0f;
                    *(f32*)((u8*)(uintptr_t)work[0x488] + 0x8c) = 208.0f;
                } else {
                    drift = 0.0f;
                    *(f32*)((u8*)(uintptr_t)work[0x488] + 0x8c) = 208.0f;
                    work[0] &= ~1u;
                }
            }
            break;
        default:
            break;
        }
        stream = func_0027b070();
        if ((~work[0] & 2) != 0) {
            height = *(f32*)(work + 0x487) - drift;
            parse = 1;
            align = 0;
            while ((!(height < 448.0f)) == 0 && parse != 0) {
                type = func_0027aaa0();
                switch (type) {
                case 0:
                    work[0] |= 2;
                    parse = 0;
                    *(f32*)(work + 0x487) += drift;
                    break;
                case 1:
                {
                    entry = func_0027a4a0();
                    align = align != 0;
                    text = func_00279af0((const u32*)(uintptr_t)stream, work[0x482]);
                    func_0027a6a0(entry, (char*)(uintptr_t)text, align);
                    frame = work[0x482];
                    work[0x482] = frame + 1;
                    if (frame + 1 == func_00279b20((const u32*)(uintptr_t)stream)) {
                        work[0x488] = (u32)entry;
                        work[0] |= 4;
                    }
                    *(f32*)((u8*)entry + 0x8c) = *(f32*)(work + 0x487);
                    *(f32*)(work + 0x487) += 24.0f;
                    align = 0;
                    func_005225a8("regist string\n");
                    break;
                }
                case 2:
                    align = 1;
                    func_005225a8("caption\n");
                    break;
                case 3:
                    *(f32*)(work + 0x487) =
                        (f32)func_0027ab10() * 24.0f +
                        *(f32*)(work + 0x487) + 0.0f;
                    func_005225a8("empty line\n");
                    break;
                case 4:
                    *(f32*)(work + 0x487) += 12.0f;
                    func_005225a8(DAT_007cc4e8);
                    break;
                default:
                    break;
                }
                func_0027ab80();
                height = *(f32*)(work + 0x487) - drift;
            }
        }
        for (i = 0; i < 0x20; i++) {
            u32* record = work + i * 0x24 + 1;
            if ((~record[0] & 1) == 0) {
                if ((*(f32*)(record + 0x23) - drift) + 24.0f < 0.0f) {
                    func_0027a560(record);
                }
                *(f32*)(record + 0x23) -= drift;
            }
        }
        *(f32*)(work + 0x487) -= drift;
        func_0027a5d0();
    }
}

// FUN_0027a3b0
void func_0027a3b0(void)
{
    s32 i;
    s32 j;
    u32* work;

    K_ASSERT(sOpTailB != NULL, 0x58);
    work = sOpTailB;
    if ((~work[0] & 1) != 0) {
        return;
    }
    for (i = 0; i < 0x20; i++) {
        u32* record = work + i * 0x24 + 1;
        if ((~record[0] & 1) == 0) {
            for (j = 0; j < (s32)record[0x21]; j++) {
                func_003b1360(*(u32*)((u8*)record + j * 8 + 8), 1, 0);
            }
        }
    }
}

// FUN_0027a4a0
u32* func_0027a4a0(void)
{
    s32 i;
    u32* work;
    u32* record;

    K_ASSERT(sOpTailB != NULL, 0x58);
    work = sOpTailB;
    for (i = 0; i < 0x20; i++) {
        record = work + i * 0x24 + 1;
        if ((record[0] & 1) == 0) {
            break;
        }
    }
    K_ASSERT(i < 0x20, 0x197);
    record[0] |= 1;
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

// FUN_0027a5d0
void func_0027a5d0(void)
{
    u32* work;
    u32* record;
    s32 i;
    f32 pos[2];

    K_ASSERT(sOpTailB != NULL, 0x58);
    work = sOpTailB;
    for (i = 0; i < 0x20; i++) {
        record = work + i * 0x24 + 1;
        if ((~record[0] & 1) == 0) {
            pos[0] = 57.0f;
            pos[1] = *(f32*)((u8*)record + 0x8c);
            func_0027a930(record, pos);
            func_0027aa00(record, (const u8*)((u8*)work + 0x122c));
        }
    }
}
// FUN_0027a6a0
void func_0027a6a0(u32* work, char* text, s32 align)
{
    char* cursor;
    s32 length;
    char* start;
    s32 count;
    s32 tokenLength;
    f32 width;
    s32 i;
    s32 inToken;
    char style;
    s32 mode;
    char token[256];

    cursor = text;
    start = text;
    length = func_00524388(text);
    count = 0;
    func_003b0e70(1);
    func_003b0e90(2);
    inToken = 0;
    width = 0.0f;
    for (i = 0; i < length + 1; i++, cursor++) {
        char c = *cursor;
        switch (c) {
        case ' ':
        case '\0':
        case '\t':
            if (inToken != 0) {
                tokenLength = (s32)(cursor - start);
                func_00524828(token, start, tokenLength);
                token[tokenLength] = 0;
                switch (align) {
                case 0:
                    style = 6;
                    mode = 0;
                    break;
                case 1:
                    style = 7;
                    mode = 1;
                    break;
                default:
                    break;
                }
                {
                    u32 handle = func_003b0970(token, style, (s8)mode, 0, 0);
                    func_003b2c60(handle, 0.0f);
                    func_003b0e54(handle, 0xffffffff);
                    *(u32*)((u8*)work + count * 8 + 8) = handle;
                    *(f32*)((u8*)work + 4 + count * 8) = width;
                    count++;
                    start += tokenLength;
                    width += (f32)func_003b19d0(handle);
                    inToken = 0;
                }
            }
            break;
        default:
            inToken = 1;
            break;
        }
        c = *cursor;
        switch (c) {
        case '\0':
            break;
        case ' ':
            width += 10.0f;
            break;
        case '\t':
            width += 40.0f;
            break;
        default:
            break;
        }
        switch (c) {
        case '\0':
            break;
        case ' ':
            start++;
            break;
        case '\t':
            start++;
            break;
        default:
            break;
        }
    }
    func_003b0e90(1);
    func_003b0e70(2);
    work[0x84 / 4] = count;
}

// FUN_0027a930
void func_0027a930(u32* work, const f32* pos)
{
    s32 i;

    for (i = 0; i < (s32)work[0x84 / 4]; i++) {
        f32* entry = (f32*)((u8*)work + i * 8 + 4);
        func_003b0d70(*(u32*)(entry + 1), (s32)((pos[0] + entry[0]) * 16.0f),
                      (s32)(pos[1] * 8.0f));
        func_003b2c60(*(u32*)(entry + 1), 0.0f);
    }
}

// FUN_0027aa00
void func_0027aa00(u32* work, const u8* color)
{
    s32 i;
    u32 packed;

    packed = (u32)color[0] << 24 | (u32)color[1] << 16 |
             (u32)color[2] << 8 | (u32)color[3];
    for (i = 0; i < (s32)work[0x84 / 4]; i++) {
        func_003b0e54(*(u32*)((u8*)work + i * 8 + 8), packed);
    }
}

// FUN_0027aaa0
u32 func_0027aaa0(void)
{
    u32* work;
    u32 stream;
    u32 base;

    K_ASSERT(sOpTailB != NULL, 0x58);
    work = sOpTailB;
    stream = func_0027b070();
    base = func_00279b10((const u32*)(uintptr_t)stream);
    return *(u8*)(uintptr_t)(base + work[0x120c / 4]);
}

// FUN_0027ab10
s32 func_0027ab10(void)
{
    u32* work;
    u32 stream;
    u32 base;

    K_ASSERT(sOpTailB != NULL, 0x58);
    work = sOpTailB;
    stream = func_0027b070();
    base = func_00279b10((const u32*)(uintptr_t)stream);
    return *(u8*)(uintptr_t)(work[0x120c / 4] + base + 1);
}

// FUN_0027ab80
void func_0027ab80(void)
{
    u32* work;
    u32 stream;
    u32 base;
    s32 offset;
    u8 command;

    K_ASSERT(sOpTailB != NULL, 0x58);
    work = sOpTailB;
    stream = func_0027b070();
    base = func_00279b10((const u32*)(uintptr_t)stream);
    offset = work[0x120c / 4];
    command = *(u8*)(uintptr_t)(base + offset);
    switch (command) {
    case 0:
        break;
    case 1:
        work[0x120c / 4] = offset + 1;
        break;
    case 2:
        work[0x120c / 4] = offset + 1;
        break;
    case 3:
        work[0x120c / 4] = offset + 2;
        break;
    case 4:
        work[0x120c / 4] = offset + 1;
        break;
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

// FUN_0027ace0
void func_0027ace0(void)
{
    u32* work;
    s32 size;
    s32 i;
    void* data;
    void* copy;

    if (sOpTailC == NULL) {
        K_Assert("ed_res.c", 0x31);
    }
    work = sOpTailC;
    if ((work[0] & 1) != 0 && func_001016b0((void*)(uintptr_t)work[2]) != NULL) {
        for (i = 0; i < 3; i++) {
            data = func_00102100((void*)(uintptr_t)work[2], i, &size);
            switch (i) {
            case 0:
                work[3] = (u32)func_00279940((const u32*)data);
                break;
            case 1:
                copy = (*DAT_00960178)(size, 0x40000);
                func_00521250(copy, data, size);
                func_003af770(6, copy);
                break;
            case 2:
                copy = (*DAT_00960178)(size, 0x40000);
                func_00521250(copy, data, size);
                func_003af770(7, copy);
                break;
            }
        }
        work[1] |= 1;
        func_00100ec0((void*)(uintptr_t)work[2]);
        work[0] &= ~1u;
    }
}

// FUN_0027ae90
void func_0027ae90(void)
{
    u32* work;

    if (sOpTailC == NULL) {
        K_Assert("ed_res.c", 0x31);
    }
    work = sOpTailC;
    if ((~work[0] & 1) == 0) {
        K_Assert("ed_res.c", 0x76);
    }
    if ((~work[1] & 1) == 0) {
        K_Assert("ed_res.c", 0x77);
    }
    if (func_0017d800() == 0) {
        work[2] = (u32)func_00100d80("oped/ed_sr.bin", 1);
    } else {
        work[2] = (u32)func_00100d80("oped/ed_sr_f.bin", 1);
    }
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

// FUN_0027b0b0
void func_0027b0b0(void)
{
    u32* work;
    u32 state;

    if (sOpTailD == NULL) {
        K_Assert("ed_sr.c", 0x3d);
    }
    work = sOpTailD;
    if ((~work[0] & 1) != 0) {
        return;
    }
    state = work[0x493];
    switch (state) {
    case 0:
        if (func_0027af80() == 0) {
            func_001085c0();
            work[0x493] = 1;
        }
        break;
    case 1:
        if (func_00108710() != 0) {
            func_0027b200();
        }
        break;
    case 2:
        work[0x495]++;
        if (func_00279d10() == 0 &&
            kwlnTaskExists((KwlnTask*)(uintptr_t)work[0x494]) == 0) {
            func_00108570();
            work[0x493] = 3;
        }
        break;
    case 3:
        if (func_00108710() != 0) {
            work[0] &= ~1u;
        }
        break;
    }
    func_0027ace0();
    func_00279d60();
}

// FUN_0027b200
void func_0027b200(void)
{
    u32* work;
    u32 id;
    void* task;

    if (sOpTailD == NULL) {
        K_Assert("ed_sr.c", 0x3d);
    }
    work = sOpTailD;
    if (func_0017d800() == 0) {
        if (func_0016f190(0xb8e) != 0) {
            id = 0x20;
        } else {
            id = 0x21;
        }
    } else {
        id = 0x2a;
    }
    func_00279c90();
    task = func_0010bce0((void*)(uintptr_t)work[1], id);
    *(u32*)((u8*)work + 0x1250) = (u32)task;
    *(u32*)((u8*)work + 0x1254) = 0;
    *(u32*)((u8*)work + 0x124c) = 2;
}

// FUN_0027b2b0
u32 func_0027b2b0(void)
{
    func_0027b0b0();
    if (sOpTailD == NULL) {
        K_Assert("ed_sr.c", 0x3d);
    }
    return (sOpTailD[0] & 1) != 0 ? 0 : (u32)-1;
}

// FUN_0027b310
u32 func_0027b310(void)
{
    void (* volatile *stateSetter)(s32 state, u32 value);
    u32 saved;

    if (func_004c9d10(func_00198590()) != 0) {
        (*DAT_00960094)(0xe, &saved);
        stateSetter = DAT_00960090;
        (*stateSetter)(0xe, 0);
        if (sOpTailD == NULL) {
            K_Assert("ed_sr.c", 0x3d);
        }
        if ((~sOpTailD[0] & 1) == 0) {
            func_0027a3b0();
        }
        (*stateSetter)(0xe, saved);
        func_004c9d00(func_00198590());
    }
    return 0;
}

// FUN_0027b3f0
void func_0027b3f0(s32 param)
{
    if (sOpTailD == NULL) {
        K_Assert("ed_sr.c", 0x3d);
    }
    func_00279bf0();
    func_0027ac80();
    (*DAT_0096017c)(*(void**)((u8*)(uintptr_t)param + 0x3c));
}

// FUN_0027b460
u32 func_0027b460(void)
{
    u32* root;
    void* task;
    void* resource;

    if (sOpTailE == NULL) {
        root = (*DAT_00960178)(0x1258, 0x40000);
        task = kwlnTaskCreateWithAutoPriority(NULL, 10, "edsr",
                                              (KwlnTaskUpdateFunc)func_0027b2b0,
                                              (KwlnTaskDestroyFunc)func_0027b3f0, root);
        resource = kwlnTaskInitEx("edsr draw", 0x1cd8, 1, 2,
                                  (KwlnTaskUpdateFunc)func_0027b310, NULL, NULL);
        root[2] = (u32)resource;
        kwlnTaskAddChild(task, resource);
        root[0] = 0;
        func_0027ac60(root + 3);
        func_00279b30(root + 7);
        root[1] = (u32)task;
        sOpTailD = root;
        if (root == NULL) {
            K_Assert("ed_sr.c", 0x3d);
        }
        root = sOpTailD;
        func_0027ae90();
        root[0x493] = 0;
        root[0] |= 1;
        sOpTailE = (u32*)task;
        return 0;
    }
    if (kwlnTaskExists((KwlnTask*)sOpTailE) == 0) {
        sOpTailE = NULL;
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

// FUN_0027b610
void func_0027b610(void)
{
    u32* work;
    u32 flags;

    K_ASSERT(sOpTailF != NULL, 0x27);
    work = sOpTailF;
    flags = work[0];
    if ((~flags & 1) == 0) {
        if ((flags & 2) != 0) {
            if (*(s32*)((u8*)work + 0x110) < 0x14) {
                work[0x44]++;
            } else {
                work[0] = flags & ~1u;
            }
        } else if (*(s32*)((u8*)work + 0x110) < 0x14) {
            work[0x44]++;
        }
        func_0027b6c0();
    }
}

// FUN_0027b6c0
void func_0027b6c0(void)
{
    typedef struct {
        u8 scratch[0x1c];
        u8 rgba[4];
    } ColorWorkspace;
    u32* work;
    u32 texture;
    u32 descriptor;
    ColorWorkspace color;
    f32 values[4];
    f32 alpha;

    K_ASSERT(sOpTailF != NULL, 0x27);
    work = sOpTailF;
    texture = func_0021c3f0(2);
    descriptor = func_0021cca0(texture, 0x3a);
    values[0] = *(f32*)((u8*)work + 0x114);
    values[1] = *(f32*)((u8*)work + 0x118);
    values[2] = (f32)*(s32*)((u8*)(uintptr_t)descriptor + 0xc);
    values[3] = (f32)*(s32*)((u8*)(uintptr_t)descriptor + 0x10);
    func_0021d8e0(work + 4, values);
    if ((work[0] & 2) != 0) {
        if (*(s32*)((u8*)work + 0x110) < 0x14) {
            alpha = 1.0f - (f32)*(s32*)((u8*)work + 0x110) / 20.0f;
        } else {
            alpha = 0.0f;
        }
    } else if (*(s32*)((u8*)work + 0x110) < 0x14) {
        alpha = (f32)*(s32*)((u8*)work + 0x110) / 20.0f;
    } else {
        alpha = 1.0f;
    }
    color.rgba[0] = 0xff;
    color.rgba[1] = 0xff;
    color.rgba[2] = 0xff;
    color.rgba[3] = (u8)(alpha * 255.0f);
    func_0021d950(work + 4, color.rgba);
}

// FUN_0027b880
void func_0027b880(void)
{
    void (* volatile *stateSetter)(s32 state, u32 value);
    void (* volatile *draw)(void* vertices, s32 stride, s32 mode, s32 a, s32 b);
    u32* work;
    u32 texture;
    u32 descriptor;

    K_ASSERT(sOpTailF != NULL, 0x27);
    work = sOpTailF;
    texture = func_0021c3f0(2);
    if ((~work[0] & 1) == 0) {
        stateSetter = DAT_00960090;
        (*stateSetter)(9, 2);
        (*stateSetter)(0x14, 2);
        (*stateSetter)(8, 0);
        (*stateSetter)(6, 0);
        descriptor = func_0021cce0(func_0021cca0(texture, 0x3a));
        (*stateSetter)(1, descriptor);
        func_004d7f60(3, 0x717fb);
        func_004d7f60(2, 0x44);
        draw = DAT_0096009c;
        (*draw)(work + 4, 4, 0, 1, 2);
        (*draw)(work + 4, 4, 0, 2, 3);
    }
}

// FUN_0027b9f0
void func_0027b9f0(void)
{
    u32* work;
    u32 texture;

    K_ASSERT(sOpTailF != NULL, 0x27);
    work = sOpTailF;
    texture = func_0021cca0(func_0021c3f0(2), 0x3a);
    func_0021d3b0(work + 4, texture);
    work[0x44] = 0;
    work[0] &= ~2u;
    func_0027b6c0();
    work[0] |= 1;
}

// FUN_0027ba90
void func_0027ba90(void)
{
    u32* work;

    K_ASSERT(sOpTailF != NULL, 0x27);
    work = sOpTailF;
    work[0x44] = 0;
    work[0] |= 2;
}

// FUN_0027bae0
void func_0027bae0(const OpTailPosition* value)
{
    u32* work;

    K_ASSERT(sOpTailF != NULL, 0x27);
    work = sOpTailF;
    *(OpTailPosition*)((u8*)work + 0x114) = *value;
    if ((work[0] & 1) != 0) {
        func_0027b6c0();
    }
}
