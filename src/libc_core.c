#include "mw_harvest_compat.h"
#include "temporary.h"
// Stub VU intrinsics not covered by mw_harvest_compat.h (for compile-clean only, not matching)
#define _pnot(a) mwVecKeep(a)
#define _psubb(a,b) mwVecZero()
#define _psubw(a,b) mwVecZero()
#define _pand(a,b) mwVecZero()
#define _pcpyud(a,b) mwVecZero()
#define _pcpyld(a,b) mwVecZero()
#define _pcpyh(a) mwVecZero()
#define _ctc2(a) ((u32)0)
#define _vnop() ((void)0)
/* auto-extern (generated) */

// Fix return types for EE math functions (declared void but used as expressions)
#define FUN_00531170_real FUN_00531170
#define FUN_00531170(a,b) ((unsigned long long (*)(unsigned long long, unsigned long long))FUN_00531170_real)(a,b)
#define FUN_005311c8_real FUN_005311c8
#define FUN_005311c8(a,b) ((unsigned long long (*)(unsigned long long, unsigned long long))FUN_005311c8_real)(a,b)
#define FUN_00531230_real FUN_00531230
#define FUN_00531230(a,b) ((unsigned long long (*)(unsigned long long, unsigned long long))FUN_00531230_real)(a,b)
#define FUN_00531480_real FUN_00531480
#define FUN_00531480(a,b) ((unsigned long long (*)(unsigned long long, unsigned long long))FUN_00531480_real)(a,b)
#define FUN_005316d0_real FUN_005316d0
#define FUN_005316d0(a,b) ((long long (*)(unsigned long long, unsigned long long))FUN_005316d0_real)(a,b)

// Declare string constants from Ghidra dumps
extern char s_0000000000000000bug_in_vfprintf__007bedb0[];
extern char s_0123456789ABCDEF_007bee00[];
extern char s_0123456789abcdef_007bee28[];
extern char s__null__007bee40[];
extern char s_camp_commu_card_i_s_card0d_tmx_005db3d0[];
extern u32 _PTR_DAT_007bf4c8;
extern u32 _PTR_DAT_007bf558;
extern u32 UNK_317fffff;

u32 FUN_0052a8c8(u32 param_1);
float FUN_0052c398(float param_1);
u32 FUN_005289d0(u64 param_1);
int FUN_00526238(void *param_1);
char * FUN_005287d8(int param_1,char *param_2);
u64 FUN_005279b8(u8 *param_1, int param_2, s64 param_3);
u32 FUN_0052d428(float *param_1,u64 param_2,int param_3,int param_4,int param_5,int param_6);
u32 FUN_0052e148(u32 param_1);
u32 FUN_0052e118(u32 param_1);
u64 FUN_00527810(u64 param_1,long param_2,int param_3,u32 param_4,u8 *param_5,
            u64 param_6,long param_7,int *param_8);
u32 FUN_0052c6d0(u64 *param_1,u64 *param_2,int param_3,int param_4,int param_5,
                 int param_6);
extern u32 DAT_007bfb20;
extern u32 DAT_007bfb24;
extern u32 DAT_007bfbbc;
extern u32 DAT_007bfbe8;
extern u32 DAT_007bfc28;
extern u32 DAT_007c019c;
extern u32 DAT_007c0234;
extern u32 DAT_007c02c8;
extern u32 DAT_00782f38;
extern u32 DAT_007bf9f4;
extern u32 DAT_007bfa08;
extern u32 DAT_007bfa18;
extern u32 DAT_007bfa64;
extern u32 DAT_007bfa74;
extern u32 DAT_007bfa78;
extern u32 DAT_007bfa8c;
extern u32 DAT_007bfa94;
extern u32 DAT_007bfb04;
extern u32 DAT_007bfb18;
extern u32 DAT_007bfb1c;
extern u32 DAT_007bfbc8;
extern u32 DAT_007bfbdc;
extern u32 DAT_007bfbe4;
extern u32 DAT_007bfbf0;
extern u32 DAT_007bfc10;
extern u32 DAT_007bfc1c;
extern u32 DAT_007bfc24;
extern u32 DAT_007c0004;
extern u32 DAT_007c0198;
extern u32 DAT_007c0230;
extern u32 DAT_007c023c;
extern u32 DAT_007c0298;
extern u32 DAT_007c02b0;
extern u32 DAT_007c02b4;
extern u32 DAT_007c02c0;
extern u32 DAT_007c02c4;
extern u32 DAT_007beb78;
extern u32 DAT_007bec40;
extern u32 DAT_007bec68;
extern u32 DAT_007bec90;
extern u32 DAT_007bece0;
extern u32 DAT_007bece8;
extern u32 DAT_007becf0;
extern u32 DAT_007bedf0;
extern u32 DAT_007bedf8;
extern u32 DAT_007bf470;
extern u32 DAT_007bf478;
extern u32 DAT_007bf480;
extern u32 DAT_007bf488;
extern u32 DAT_007bf490;
extern u32 DAT_007bf498;
extern u32 DAT_007bf4a0;
extern u32 DAT_007bf4a8;
extern u32 DAT_007bf4b0;
extern u32 DAT_007bf4b8;
extern u32 DAT_007bf4c0;
extern u32 DAT_007bf4d0;
extern u32 DAT_007bf530;
extern u32 DAT_007bf538;
extern u32 DAT_007bf540;
extern u32 DAT_007bf548;
extern u32 DAT_007bf550;
extern u32 DAT_007bf560;
extern u32 DAT_007bf568;
extern u32 DAT_007bf570;
extern u32 DAT_007bf578;
extern u32 DAT_007bf580;
extern u32 DAT_007bf5b0;
extern u32 DAT_007bf5b8;
extern u32 DAT_007bf5c0;
extern u32 DAT_007bf5c8;
extern u32 DAT_007bf5d0;
extern u32 DAT_007bf5e0;
extern u32 DAT_007bf6d8;
extern u32 DAT_007bf6e0;
extern u32 DAT_007bf6e8;
extern u32 DAT_007bf6f0;
extern u32 DAT_007bf6f8;
extern u32 DAT_007bf700;
extern u32 DAT_007bf708;
extern u32 DAT_007bf710;
extern u32 DAT_007bf718;
extern u32 DAT_007bf720;
extern u32 DAT_007bf728;
extern u32 DAT_007bf730;
extern u32 DAT_007bf738;
extern u32 DAT_007bf740;
extern u32 DAT_007bf748;
extern u32 DAT_007bf750;
extern u32 DAT_007bf758;
extern u32 DAT_007bf760;
extern u32 DAT_007bf768;
extern u32 DAT_007bf770;
extern u32 DAT_007bf778;
extern u32 DAT_007bf780;
extern u32 DAT_007bf788;
extern u32 DAT_007bf790;
extern u32 DAT_007bf89c;
extern u32 DAT_007bf970;
extern u32 DAT_007bf978;
extern u32 DAT_007bf980;
extern u32 DAT_007bf988;
extern u32 DAT_007bf990;
extern u32 DAT_007bf998;
extern u32 DAT_007bf9a0;
extern u32 DAT_007bf9e0;
extern u32 DAT_007bf9e4;
extern u32 DAT_007bf9e8;
extern u32 DAT_007bf9ec;
extern u32 DAT_007bf9f0;
extern u32 DAT_007bf9f8;
extern u32 DAT_007bf9fc;
extern u32 DAT_007bfa00;
extern u32 DAT_007bfa04;
extern u32 DAT_007bfa0c;
extern u32 DAT_007bfa10;
extern u32 DAT_007bfa14;
extern u32 DAT_007bfa5c;
extern u32 DAT_007bfa60;
extern u32 DAT_007bfa68;
extern u32 DAT_007bfa6c;
extern u32 DAT_007bfa70;
extern u32 DAT_007bfa7c;
extern u32 DAT_007bfa80;
extern u32 DAT_007bfa84;
extern u32 DAT_007bfa88;
extern u32 DAT_007bfa90;
extern u32 DAT_007bfa98;
extern u32 DAT_007bfab8;
extern u32 DAT_007bfabc;
extern u32 DAT_007bfac0;
extern u32 DAT_007bfaf4;
extern u32 DAT_007bfaf8;
extern u32 DAT_007bfafc;
extern u32 DAT_007bfb00;
extern u32 DAT_007bfb08;
extern u32 DAT_007bfb0c;
extern u32 DAT_007bfb10;
extern u32 DAT_007bfb14;
extern u32 DAT_007bfb28;
extern u32 DAT_007bfb30;
extern u32 DAT_007bfb38;
extern u32 DAT_007bfb40;
extern u32 DAT_007bfbb4;
extern u32 DAT_007bfbb8;
extern u32 DAT_007bfbc0;
extern u32 DAT_007bfbc4;
extern u32 DAT_007bfbcc;
extern u32 DAT_007bfbd0;
extern u32 DAT_007bfbd4;
extern u32 DAT_007bfbd8;
extern u32 DAT_007bfbe0;
extern u32 DAT_007bfbec;
extern u32 DAT_007bfbf4;
extern u32 DAT_007bfbf8;
extern u32 DAT_007bfbfc;
extern u32 DAT_007bfc00;
extern u32 DAT_007bfc04;
extern u32 DAT_007bfc08;
extern u32 DAT_007bfc0c;
extern u32 DAT_007bfc14;
extern u32 DAT_007bfc18;
extern u32 DAT_007bfc20;
extern u32 DAT_007bfc2c;
extern u32 DAT_007bff44;
extern u32 DAT_007bfff0;
extern u32 DAT_007bfff4;
extern u32 DAT_007bfff8;
extern u32 DAT_007bfffc;
extern u32 DAT_007c0000;
extern u32 DAT_007c0008;
extern u32 DAT_007c000c;
extern u32 DAT_007c0010;
extern u32 DAT_007c0060;
extern u32 DAT_007c0068;
extern u32 DAT_007c0070;
extern u32 DAT_007c0078;
extern u32 DAT_007c0080;
extern u32 DAT_007c0088;
extern u32 DAT_007c0090;
extern u32 DAT_007c00a0;
extern u32 DAT_007c0138;
extern u32 DAT_007c0140;
extern u32 DAT_007c0148;
extern u32 DAT_007c0150;
extern u32 DAT_007c0158;
extern u32 DAT_007c0160;
extern u32 DAT_007c0184;
extern u32 DAT_007c0188;
extern u32 DAT_007c0190;
extern u32 DAT_007c0194;
extern u32 DAT_007c01a0;
extern u32 DAT_007c01a8;
extern u32 DAT_007c01b8;
extern u32 DAT_007c01f4;
extern u32 DAT_007c01f8;
extern u32 DAT_007c01fc;
extern u32 DAT_007c0200;
extern u32 DAT_007c0204;
extern u32 DAT_007c0208;
extern u32 DAT_007c022c;
extern u32 DAT_007c0238;
extern u32 DAT_007c0240;
extern u32 DAT_007c0244;
extern u32 DAT_007c028c;
extern u32 DAT_007c0290;
extern u32 DAT_007c0294;
extern u32 DAT_007c029c;
extern u32 DAT_007c02a0;
extern u32 DAT_007c02a4;
extern u32 DAT_007c02a8;
extern u32 DAT_007c02ac;
extern u32 DAT_007c02b8;
extern u32 DAT_007c02bc;
extern u32 DAT_007c02cc;
extern u32 DAT_007c02d8;
extern void* PTR_DAT_00782f30;
extern void* PTR_DAT_007be9c8;
extern void* PTR_DAT_007beb30;
extern void* PTR_DAT_007c018c;
extern void* PTR_LAB_007bf1c4;

typedef char* va_list;
#define va_start(ap, last) (ap = ((va_list)__builtin_next_arg(last) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8)))

typedef struct Bigint {
    struct Bigint* next;
    s32 k;
    s32 maxwds;
    s32 sign;
    s32 wds;
    u32 x[1];
} Bigint;

typedef struct DtoaContext {
    u8 unused[0x48];
    Bigint* p5s;
    Bigint** freelist;
} DtoaContext;

typedef union DoubleBits { f64 value; u32 word[2]; } DoubleBits;
typedef union FloatBits { f32 value; u32 word; } FloatBits;

typedef s32 (*StreamWriteProc)(void*, const void*, u32);

extern s32 func_00503c30(void);
extern s32 func_0050d3a0(void);
extern void func_0050d3f0(void);
extern void* func_0051e178(void*, s32, u32);
extern void* func_005209c0(void*, u32);
extern void func_0051fbb0(void*, void*);
extern s32 func_005037a8(s32, const void*, u32);
extern void* func_00503860(u32);
extern s32 func_00520580(void*, s32, void*, u32);
extern s32 func_00526238(void*, const char*, va_list);
extern s32 func_00527b48(void*, void*, const char*, va_list);
extern u8 DAT_00782f30[];
extern s32 DAT_009acc20[];
void* __pool_realloc(void* pool, void* block, u32 size);
s32 __write(s32* error, s32 descriptor, const void* buffer, u32 count);

static s32 sAllocLockDepth;
static s32 sAllocLockHandle;

static void copy_bytes(u8* dst, const u8* src, u32 size)
{
    while (size-- != 0) *dst++ = *src++;
}

// FUN_00521250 NONMATCHING
void* memcpy(void* dst, const void* src, u32 size)
{
    copy_bytes((u8*)dst, (const u8*)src, size);
    return dst;
}

// FUN_00521300 NONMATCHING
void* memmove(void* dst, const void* src, u32 size)
{
    u8* out = dst;
    const u8* in = src;
    if (out > in && out < in + size) {
        out += size;
        in += size;
        while (size-- != 0) *--out = *--in;
    } else {
        copy_bytes(out, in, size);
    }
    return dst;
}

// FUN_00521408 NONMATCHING
void* memset(void* dst, u8 value, u32 size)
{
    u8* out = dst;
    while (size-- != 0) *out++ = value;
    return dst;
}

// FUN_005214c8 NONMATCHING
void __alloc_lock(void)
{
    if (func_00503c30() != 1) {
        if (sAllocLockDepth == 0) sAllocLockHandle = func_0050d3a0();
        sAllocLockDepth++;
    }
}

// FUN_00521520 NONMATCHING
void __alloc_unlock(void)
{
    if (func_00503c30() != 1 && --sAllocLockDepth == 0 && sAllocLockHandle != 0) {
        sAllocLockHandle = 0;
        func_0050d3f0();
    }
}

// FUN_00521578 NONMATCHING
Bigint* __dtoa_Balloc(DtoaContext* context, s32 k)
{
    Bigint* value;
    Bigint** freeList;
    if (context->freelist == NULL) {
        context->freelist = func_0051e178(context, 4, 0x10);
        if (context->freelist == NULL) return NULL;
    }
    freeList = context->freelist + k;
    value = *freeList;
    if (value != NULL) {
        *freeList = value->next;
    } else {
        value = func_0051e178(context, 1, (1U << (k + 2)) + 0x14);
        if (value == NULL) return NULL;
        value->k = k;
        value->maxwds = 1 << k;
    }
    value->sign = 0;
    value->wds = 0;
    return value;
}

// FUN_00521620 NONMATCHING
void __dtoa_Bfree(DtoaContext* context, Bigint* value)
{
    if (value != NULL) {
        value->next = context->freelist[value->k];
        context->freelist[value->k] = value;
    }
}

// FUN_00521650 NONMATCHING
Bigint* __dtoa_multadd(DtoaContext* context, Bigint* value, s32 multiplier, s32 addend)
{
    u64 carry = (u32)addend;
    s32 i;
    for (i = 0; i < value->wds; i++) {
        carry += (u64)value->x[i] * (u32)multiplier;
        value->x[i] = (u32)carry;
        carry >>= 32;
    }
    if (carry != 0) {
        if (value->wds == value->maxwds) {
            Bigint* grown = __dtoa_Balloc(context, value->k + 1);
            if (grown == NULL) return NULL;
            grown->wds = value->wds;
            copy_bytes((u8*)grown->x, (const u8*)value->x, value->wds * 4);
            __dtoa_Bfree(context, value);
            value = grown;
        }
        value->x[value->wds++] = (u32)carry;
    }
    return value;
}

// FUN_00521758 NONMATCHING
Bigint* __dtoa_s2b(DtoaContext* context, const char* digits, s32 firstCount, s32 digitCount, s32 firstNineDigits)
{
    Bigint* value;
    s32 k = 0;
    s32 capacity = 1;
    s32 index;
    while (capacity < (digitCount + 8) / 9) { capacity <<= 1; k++; }
    value = __dtoa_Balloc(context, k);
    if (value == NULL) return NULL;
    value->x[0] = firstNineDigits;
    value->wds = 1;
    if (firstCount < 10) {
        digits += 10;
    } else {
        digits += 9;
        for (index = 9; index < firstCount; index++) {
            value = __dtoa_multadd(context, value, 10, *digits++ - '0');
            if (value == NULL) return NULL;
        }
        digits += 2;
    }
    for (index = firstCount; index < digitCount; index++) {
        value = __dtoa_multadd(context, value, 10, *digits++ - '0');
        if (value == NULL) return NULL;
    }
    return value;
}

// FUN_00521888 NONMATCHING
s32 __dtoa_hi0bits(u32 value)
{
    s32 count = 0;
    if ((value & 0xffff0000) == 0) { count = 16; value <<= 16; }
    if ((value & 0xff000000) == 0) { count += 8; value <<= 8; }
    if ((value & 0xf0000000) == 0) { count += 4; value <<= 4; }
    if ((value & 0xc0000000) == 0) { count += 2; value <<= 2; }
    if ((s32)value >= 0) { count++; if ((value & 0x40000000) == 0) return 32; }
    return count;
}

// FUN_00521908 NONMATCHING
s32 __dtoa_lo0bits(u32* value)
{
    u32 word = *value;
    s32 count = 0;
    if ((word & 7) != 0) {
        if (word & 1) return 0;
        if (word & 2) { *value = word >> 1; return 1; }
        *value = word >> 2;
        return 2;
    }
    if ((word & 0xffff) == 0) { count = 16; word >>= 16; }
    if ((word & 0xff) == 0) { count += 8; word >>= 8; }
    if ((word & 0xf) == 0) { count += 4; word >>= 4; }
    if ((word & 3) == 0) { count += 2; word >>= 2; }
    if ((word & 1) == 0) {
        count++;
        if ((word >> 1) == 0) return 32;
        word >>= 1;
    }
    *value = word;
    return count;
}

// FUN_005219c8 NONMATCHING
Bigint* __dtoa_i2b(DtoaContext* context, s32 input)
{
    Bigint* value = __dtoa_Balloc(context, 1);
    if (value != NULL) {
        value->x[0] = input;
        value->wds = 1;
    }
    return value;
}

// FUN_00521a00 NONMATCHING
Bigint* __dtoa_mult(DtoaContext* context, Bigint* left, Bigint* right)
{
    Bigint* result;
    s32 i, j, words = left->wds + right->wds, k = left->k;
    while ((1 << k) < words) k++;
    result = __dtoa_Balloc(context, k);
    if (result == NULL) return NULL;
    memset(result->x, 0, result->maxwds * 4);
    for (i = 0; i < left->wds; i++) {
        u64 carry = 0;
        for (j = 0; j < right->wds; j++) {
            u64 product = (u64)left->x[i] * right->x[j] + result->x[i + j] + carry;
            result->x[i + j] = product;
            carry = product >> 32;
        }
        result->x[i + right->wds] = carry;
    }
    while (words > 1 && result->x[words - 1] == 0) words--;
    result->wds = words;
    return result;
}

// FUN_00521c08 NONMATCHING
Bigint* __dtoa_pow5mult(DtoaContext* context, Bigint* value, s32 power)
{
    static const s32 smallPowers[] = { 1, 5, 25, 125 };
    Bigint* p5;
    if (power & 3) {
        value = __dtoa_multadd(context, value, smallPowers[power & 3], 0);
        if (value == NULL) return NULL;
    }
    power >>= 2;
    if (power == 0) return value;
    p5 = context->p5s;
    if (p5 == NULL) { p5 = __dtoa_i2b(context, 625); context->p5s = p5; }
    while (power != 0) {
        if (power & 1) { value = __dtoa_mult(context, value, p5); if (value == NULL) return NULL; }
        power >>= 1;
        if (power != 0) {
            if (p5->next == NULL) p5->next = __dtoa_mult(context, p5, p5);
            p5 = p5->next;
        }
    }
    return value;
}

// FUN_00521d10 NONMATCHING
Bigint* __dtoa_lshift(DtoaContext* context, Bigint* value, s32 shift)
{
    Bigint* result;
    s32 wordShift = shift >> 5, bitShift = shift & 31, i;
    s32 words = value->wds + wordShift + 1, k = value->k;
    u32 carry = 0;
    while ((1 << k) < words) k++;
    result = __dtoa_Balloc(context, k);
    if (result == NULL) return NULL;
    for (i = 0; i < wordShift; i++) result->x[i] = 0;
    for (i = 0; i < value->wds; i++) {
        u32 word = value->x[i];
        result->x[i + wordShift] = (word << bitShift) | carry;
        carry = bitShift == 0 ? 0 : word >> (32 - bitShift);
    }
    result->wds = value->wds + wordShift;
    if (carry != 0) result->x[result->wds++] = carry;
    __dtoa_Bfree(context, value);
    return result;
}

// FUN_00521e70 NONMATCHING
s32 __dtoa_cmp(const Bigint* left, const Bigint* right)
{
    s32 i;
    if (left->wds != right->wds) return left->wds - right->wds;
    for (i = left->wds - 1; i >= 0; i--) if (left->x[i] != right->x[i]) return left->x[i] > right->x[i] ? 1 : -1;
    return 0;
}

// FUN_00521ed8 NONMATCHING
Bigint* __dtoa_diff(DtoaContext* context, Bigint* left, Bigint* right)
{
    Bigint* result;
    Bigint* large = left;
    Bigint* small = right;
    s32 comparison = __dtoa_cmp(left, right), i;
    u64 borrow = 0;
    if (comparison == 0) return __dtoa_i2b(context, 0);
    if (comparison < 0) { large = right; small = left; }
    result = __dtoa_Balloc(context, large->k);
    if (result == NULL) return NULL;
    result->sign = comparison < 0;
    result->wds = large->wds;
    for (i = 0; i < large->wds; i++) {
        u64 amount = (i < small->wds ? small->x[i] : 0) + borrow;
        result->x[i] = large->x[i] - amount;
        borrow = large->x[i] < amount;
    }
    while (result->wds > 1 && result->x[result->wds - 1] == 0) result->wds--;
    return result;
}

// FUN_00522058 NONMATCHING
f64 __dtoa_ulp(f64 value)
{
    DoubleBits bits;
    s32 exponent;
    u64 fraction;

    bits.value = value;
    exponent = (bits.word[1] >> 20) & 0x7ff;
    if (exponent > 52) {
        bits.word[0] = 0;
        bits.word[1] = (u32)(exponent - 52) << 20;
    } else {
        fraction = exponent == 0 ? 1 : (u64)1 << (exponent - 1);
        bits.word[0] = (u32)fraction;
        bits.word[1] = (u32)(fraction >> 32);
    }
    return bits.value;
}

// FUN_00522118 NONMATCHING
f64 __dtoa_b2d(const Bigint* value, s32* exponent)
{
    u32 top = value->x[value->wds - 1];
    u32 next = value->wds > 1 ? value->x[value->wds - 2] : 0;
    s32 leading = __dtoa_hi0bits(top);
    DoubleBits result;

    *exponent = value->wds * 32 - leading;
    if (leading < 11) {
        result.word[1] = 0x3ff00000 | (top >> (11 - leading));
        result.word[0] = (top << (leading + 21)) | (next >> (11 - leading));
    } else if (leading == 11) {
        result.word[1] = 0x3ff00000 | top;
        result.word[0] = next;
    } else {
        s32 shift = leading - 11;
        result.word[1] = 0x3ff00000 | (top << shift) | (next >> (32 - shift));
        result.word[0] = next << shift;
    }
    return result.value;
}

// FUN_005222c0 NONMATCHING
Bigint* __dtoa_d2b(DtoaContext* context, f64 input, s32* exponent, s32* bits)
{
    DoubleBits source;
    Bigint* result;
    u32 high;
    u32 low;
    s32 trailing;

    source.value = input;
    high = source.word[1] & 0xfffff;
    low = source.word[0];
    if ((source.word[1] & 0x7ff00000) != 0) high |= 0x100000;
    result = __dtoa_Balloc(context, 1);
    if (result == NULL) return NULL;
    if (low == 0) {
        trailing = __dtoa_lo0bits(&high);
        result->x[0] = high;
        result->wds = 1;
        *exponent = ((source.word[1] >> 20) & 0x7ff) - 0x432 + trailing;
        *bits = 32 - trailing;
    } else {
        trailing = __dtoa_lo0bits(&low);
        result->x[0] = low;
        result->x[1] = high >> trailing;
        result->wds = result->x[1] == 0 ? 1 : 2;
        *exponent = ((source.word[1] >> 20) & 0x7ff) - 0x433 + trailing;
        *bits = result->wds * 32 - __dtoa_hi0bits(result->x[result->wds - 1]);
    }
    return result;
}

// FUN_00522440 NONMATCHING
f64 __dtoa_ratio(const Bigint* numerator, const Bigint* denominator)
{
    s32 leftExponent, rightExponent;
    f64 left = __dtoa_b2d(numerator, &leftExponent);
    f64 right = __dtoa_b2d(denominator, &rightExponent);
    s32 adjustment = leftExponent - rightExponent + (numerator->wds - denominator->wds) * 32;
    if (adjustment < 1) left = ldexp(left, -adjustment); else right = ldexp(right, adjustment);
    return left / right;
}

// FUN_005225a8 NONMATCHING
int printf(const char* fmt, ...)
{
    va_list args;
    void* stream = *(void**)(DAT_00782f30 + 8);
    va_start(args, fmt);
    *(void**)((u8*)stream + 0x54) = DAT_00782f30;
    return func_00526238(stream, fmt, args);
}

static void qsort_swap(u8* left, u8* right, u32 width)
{
    while (width-- != 0) { u8 value = *left; *left++ = *right; *right++ = value; }
}

static void qsort_partition(u8* base, s32 first, s32 last, u32 width, int (*compare)(const void*, const void*))
{
    s32 left = first, right = last;
    u8* pivot = base + ((first + last) >> 1) * width;
    while (left <= right) {
        while (compare(base + left * width, pivot) < 0) left++;
        while (compare(base + right * width, pivot) > 0) right--;
        if (left <= right) { qsort_swap(base + left * width, base + right * width, width); left++; right--; }
    }
    if (first < right) qsort_partition(base, first, right, width, compare);
    if (left < last) qsort_partition(base, left, last, width, compare);
}

// FUN_005225f8 NONMATCHING
void qsort(void* base, u32 count, u32 width, int (*compare)(const void*, const void*))
{
    u8* elements = (u8*)base;
    u32 index;

    if (elements == NULL || compare == NULL || width == 0) return;
    for (index = 1; index < count; index++) {
        u32 cursor = index;
        while (cursor > 0 && compare(elements + (cursor - 1) * width, elements + cursor * width) > 0) {
            qsort_swap(elements + (cursor - 1) * width, elements + cursor * width, width);
            cursor--;
        }
    }
}

// FUN_00522f38 NONMATCHING
s32 __write(s32* error, s32 descriptor, const void* buffer, u32 count)
{
    s32 result;
    DAT_009acc20[0] = 0;
    result = func_005037a8(descriptor, buffer, count);
    if (result == -1 && DAT_009acc20[0] != 0) *error = DAT_009acc20[0];
    return result;
}

// FUN_00522f98 NONMATCHING
void* realloc(void* block, u32 size)
{
    return __pool_realloc(DAT_00782f30, block, size);
}

// FUN_00522fc0 NONMATCHING
void* __pool_realloc(void* pool, void* block, u32 size)
{
    u32 oldSize;
    void* replacement;
    if (block == NULL) return func_005209c0(pool, size);
    if (size == 0) { func_0051fbb0(pool, block); return NULL; }
    oldSize = (*(u32*)((u8*)block - 4) & ~3U) - 8;
    if (oldSize >= size) return block;
    replacement = func_005209c0(pool, size);
    if (replacement != NULL) { copy_bytes(replacement, block, oldSize); func_0051fbb0(pool, block); }
    return replacement;
}

// FUN_00523580 NONMATCHING
s32 __flush_buffer(void* stream)
{
    u8* file = stream;
    u16 flags = *(u16*)(file + 0xc);
    s32 written;
    if (flags & 0x20) return -1;
    if ((flags & 4) == 0) { flags |= 4; *(u16*)(file + 0xc) = flags; }
    if (*(u32*)(file + 0x10) == 0) return -1;
    written = (*(StreamWriteProc*)(file + 0x20))(*(void**)(file + 0x1c), *(void**)(file + 0x10), *(u32*)(file + 0x14));
    *(u32*)file = *(u32*)(file + 0x10);
    *(s32*)(file + 4) = written;
    if (written < 1) { *(s32*)(file + 4) = 0; *(u16*)(file + 0xc) = flags | (written == 0 ? 0x20 : 0x40); return -1; }
    return 0;
}

// FUN_005236f0 NONMATCHING
f64 copysign(f64 value, f64 sign)
{
    DoubleBits result, signBits;
    result.value = value; signBits.value = sign;
    result.word[1] = (result.word[1] & 0x7fffffff) | (signBits.word[1] & 0x80000000);
    return result.value;
}

// FUN_00523730 NONMATCHING
s32 __isinf(u64 value)
{
    s32 low = (s32)value;
    s32 high = (s32)(value >> 32);
    u32 aggregate;
    u32 difference;

    aggregate = (u32)high & 0x7fffffff;
    aggregate |= (u32)(low | -low) >> 31;
    difference = 0x7ff00000 - aggregate;
    return 1 - ((difference | -difference) >> 31);
}

// FUN_00523778 NONMATCHING
s32 __isnan(u64 value)
{
    s32 low = (s32)value;
    s32 high = (s32)(value >> 32);
    u32 aggregate;

    aggregate = (u32)high & 0x7fffffff;
    aggregate |= (u32)(low | -low) >> 31;
    return (0x7ff00000 - aggregate) >> 31;
}

// FUN_005237b0 NONMATCHING
f64 ldexp(f64 value, s32 exponent)
{
    DoubleBits bits;
    s32 oldExponent, newExponent;
    bits.value = value;
    oldExponent = (bits.word[1] >> 20) & 0x7ff;
    if (oldExponent == 0) {
        if ((bits.word[1] & 0x7fffffff) == 0 && bits.word[0] == 0) return value;
        value *= 18014398509481984.0;
        bits.value = value;
        oldExponent = ((bits.word[1] >> 20) & 0x7ff) - 54;
    }
    if (oldExponent == 0x7ff) return value + value;
    newExponent = oldExponent + exponent;
    if (newExponent > 0 && newExponent < 0x7ff) { bits.word[1] = (bits.word[1] & 0x800fffff) | (newExponent << 20); return bits.value; }
    if (newExponent <= 0) {
        if (newExponent < -54) return copysign(0.0, value);
        bits.word[1] = (bits.word[1] & 0x800fffff) | ((newExponent + 54) << 20);
        return bits.value * 5.5511151231257827e-17;
    }
    return copysign(8.988465674311579e307, value) * 8.988465674311579e307;
}

// FUN_00523930 NONMATCHING
void* __sbrk(s32* error, u32 increment)
{
    void* result;
    DAT_009acc20[0] = 0;
    result = func_00503860(increment);
    if (result == (void*)-1 && DAT_009acc20[0] != 0) *error = DAT_009acc20[0];
    return result;
}

// FUN_00523980 NONMATCHING
f32 copysignf(f32 value, f32 sign)
{
    FloatBits result;
    FloatBits signBits;

    result.value = value;
    signBits.value = sign;
    result.word = (result.word & 0x7fffffff) | (signBits.word & 0x80000000);
    return result.value;
}

// FUN_005239a8 NONMATCHING
f32 scalbnf(f32 value, s32 exponent)
{
    FloatBits bits;
    s32 oldExponent, newExponent;
    bits.value = value;
    oldExponent = (bits.word >> 23) & 0xff;
    if (oldExponent == 0) {
        if ((bits.word & 0x7fffffff) == 0) return value;
        value *= 16777216.0f;
        bits.value = value;
        oldExponent = ((bits.word >> 23) & 0xff) - 24;
    }
    newExponent = oldExponent + exponent;
    if (newExponent > 0 && newExponent < 0xff) { bits.word = (bits.word & 0x807fffff) | (newExponent << 23); return bits.value; }
    if (newExponent <= 0) {
        if (newExponent < -24) return copysignf(0.0f, value);
        bits.word = (bits.word & 0x807fffff) | ((newExponent + 24) << 23);
        return bits.value * 5.960464477539063e-8f;
    }
    return copysignf(1.7014118e38f, value) * 1.7014118e38f;
}

// FUN_00523ac8 NONMATCHING
int sprintf(char* buffer, const char* fmt, ...)
{
    u8 stream[0x58];
    va_list args;
    s32 result;
    *(char**)(stream + 0) = buffer;
    *(u32*)(stream + 8) = 0x7fffffff;
    *(u16*)(stream + 0xc) = 0x208;
    *(char**)(stream + 0x10) = buffer;
    *(u32*)(stream + 0x14) = 0x7fffffff;
    *(void**)(stream + 0x54) = DAT_00782f30;
    va_start(args, fmt);
    result = func_00526238(stream, fmt, args);
    **(char**)(stream + 0) = '\0';
    return result;
}

// FUN_00523B38
asm void* __string_scan_callback(void)
{
    .set noreorder
    jr $ra
    daddu $v0, $zero, $zero
}

static void init_string_scan_stream(u8* stream, const char* input)
{
    u32 length = strlen(input);
    *(const char**)(stream + 0) = input;
    *(u32*)(stream + 4) = length;
    *(u16*)(stream + 0xc) = 4;
    *(const char**)(stream + 0x10) = input;
    *(u32*)(stream + 0x14) = length;
    *(void**)(stream + 0x20) = __string_scan_callback;
    *(u32*)(stream + 0x30) = 0;
    *(u32*)(stream + 0x44) = 0;
    *(void**)(stream + 0x54) = DAT_00782f30;
}

// FUN_00523b40 NONMATCHING
int sscanf(const char* input, const char* fmt, ...)
{
    u8 stream[0x58];
    va_list args;
    init_string_scan_stream(stream, input);
    va_start(args, fmt);
    return func_00527b48(DAT_00782f30, stream, fmt, args);
}

// FUN_00523bc8 NONMATCHING
int __scan_string_with_context(void* context, const char* input, const char* fmt, ...)
{
    u8 stream[0x58];
    va_list args;
    init_string_scan_stream(stream, input);
    va_start(args, fmt);
    return func_00527b48(context, stream, fmt, args);
}

// FUN_00523c60 NONMATCHING
void __stream_write_callback(void* stream, const void* buffer, u32 count)
{
    u8* file = stream;
    s32 written = __write((s32*)(file + 0x54), *(s16*)(file + 0xe), buffer, count);
    if (written < 0) *(u16*)(file + 0xc) &= 0xefff;
    else *(s32*)(file + 0x50) += written;
}

// FUN_00523d40 NONMATCHING
void __stream_read_callback(void* stream, void* buffer, u32 count)
{
    u8* file = stream;
    s32 read = func_00520580(*(void**)(file + 0x54), *(s16*)(file + 0xe), buffer, count);
    if (read == -1) *(u16*)(file + 0xc) &= 0xefff;
    else { *(s32*)(file + 0x50) = read; *(u16*)(file + 0xc) |= 0x1000; }
}

// FUN_00523dc8 NONMATCHING
int strcasecmp(const char* left, const char* right)
{
    u8 a, b;
    do {
        a = *left++; b = *right++;
        if (a >= 'A' && a <= 'Z') a += 'a' - 'A';
        if (b >= 'A' && b <= 'Z') b += 'a' - 'A';
    } while (a == b && a != 0);
    return (s32)a - (s32)b;
}

// FUN_00523e68 NONMATCHING
char* strcat(char* dst, const char* src)
{
    char* result = dst;
    while (*dst != '\0') dst++;
    strcpy(dst, src);
    return result;
}

// FUN_00523f98 NONMATCHING
char* strchr(const char* string, int character)
{
    u8 target = character;
    do { if ((u8)*string == target) return (char*)string; } while (*string++ != '\0');
    return NULL;
}

// FUN_00524128 NONMATCHING
int strcmp(const char* left, const char* right)
{
    u8 a, b;
    do { a = *left++; b = *right++; } while (a == b && a != 0);
    return (s32)a - (s32)b;
}

// FUN_00524270 NONMATCHING
char* strcpy(char* dst, const char* src)
{
    char* result = dst;
    do { *dst++ = *src++; } while (dst[-1] != '\0');
    return result;
}

// FUN_00524388 NONMATCHING
size_t strlen(const char* string)
{
    const char* end = string;
    while (*end != '\0') end++;
    return end - string;
}

// FUN_005244C0 NONMATCHING
u32 FUN_005244c0(u32 param_1,char *param_2,int param_3)

{
  Vec128 auVar1;
  char cVar2;
  u32 uVar3;
  Vec128 auVar4;
  Vec128 auVar5;
  Vec128 auVar6;
  u8 (*pauVar7) [16];
  u64 in_a0_udw;
  u64 in_a3_udw;
  Vec128 auVar8;
  Vec128 auVar9;
  
  pauVar7 = (u8 (*) [16])param_1;
  if ((param_1 & 7) == 0) {
    if ((param_1 & 0xf) == 0) {
      auVar8._8_8_ = in_a3_udw;
      auVar8._0_8_ = 0x101010101010101;
      auVar9._8_8_ = in_a3_udw;
      auVar9._0_8_ = 0x101010101010101;
      auVar8 = _pcpyld(auVar8,auVar9);
      *(__int128 *)&auVar4 = _psubb(*(__int128 *)pauVar7, *(__int128 *)&auVar8);
      auVar5._8_8_ = in_a0_udw;
      auVar5._0_8_ = 0x8080808080808080;
      auVar6._8_8_ = in_a0_udw;
      auVar6._0_8_ = 0x8080808080808080;
      auVar9 = _pcpyld(auVar5,auVar6);
      *(__int128 *)&auVar5 = _pand(*(__int128 *)&auVar4, _pnot(*(__int128 *)pauVar7));
      *(__int128 *)&auVar6 = _pand(*(__int128 *)&auVar5, *(__int128 *)&auVar9);
      auVar4._8_8_ = in_a0_udw;
      auVar4._0_8_ = 0x8080808080808080;
      *(__int128 *)&auVar5 = _pcpyud(*(__int128 *)&auVar6, *(__int128 *)&auVar4);
      if (auVar6._0_8_ == 0 && auVar5._0_8_ == 0) {
        do {
          pauVar7 = pauVar7 + 1;
          *(__int128 *)&auVar5 = _psubb(*(__int128 *)pauVar7, *(__int128 *)&auVar8);
          *(__int128 *)&auVar5 = _pand(*(__int128 *)&auVar5, _pnot(*(__int128 *)pauVar7));
          *(__int128 *)&auVar5 = _pand(*(__int128 *)&auVar5, *(__int128 *)&auVar9);
          auVar1._8_8_ = in_a0_udw;
          auVar1._0_8_ = 0x8080808080808080;
          *(__int128 *)&auVar6 = _pcpyud(*(__int128 *)&auVar5, *(__int128 *)&auVar1);
        } while (auVar5._0_8_ == 0 && auVar6._0_8_ == 0);
      }
    }
    else {
      uVar3 = *(u32 *)*pauVar7 + 0xfefefefefefefeff & ~*(u32 *)*pauVar7;
      while ((uVar3 & 0x8080808080808080) == 0) {
        pauVar7 = (u8 (*) [16])(*pauVar7 + 8);
        uVar3 = *(u32 *)*pauVar7 + 0xfefefefefefefeff & ~*(u32 *)*pauVar7;
      }
    }
    cVar2 = (*pauVar7)[0];
  }
  else {
    cVar2 = (*pauVar7)[0];
  }
  param_3 = param_3 + -1;
  while (cVar2 != '\0') {
    pauVar7 = (u8 (*) [16])(*pauVar7 + 1);
    cVar2 = (*pauVar7)[0];
  }
  if (param_3 != -1) {
    cVar2 = *param_2;
    (*pauVar7)[0] = cVar2;
    while (cVar2 != '\0') {
      param_2 = param_2 + 1;
      pauVar7 = (u8 (*) [16])(*pauVar7 + 1);
      if (param_3 == 0) {
        (*pauVar7)[0] = 0;
      }
      param_3 = param_3 + -1;
      if (param_3 == -1) {
        return param_1;
      }
      cVar2 = *param_2;
      (*pauVar7)[0] = cVar2;
    }
  }
  return param_1;
}
// FUN_00524670 NONMATCHING
int FUN_00524670(u64 param_1,u8 (*param_2) [16],u32 param_3)

{
  Vec128 auVar1;
  Vec128 auVar2;
  u8 *puVar3;
  Vec128 auVar4;
  char cVar5;
  Vec128 auVar6;
  Vec128 auVar7;
  u8 (*pauVar8) [16];
  u64 in_a0_udw;
  u64 in_t0_udw;
  u64 in_t1_udw;
  Vec128 auVar9;
  Vec128 auVar10;
  
  pauVar8 = (u8 (*) [16])param_1;
  if (param_3 == 0) {
    return 0;
  }
  if ((((u32)pauVar8 | (u32)param_2) & 7) == 0) {
    auVar4._8_8_ = in_t1_udw;
    auVar4._0_8_ = 0x101010101010101;
    if ((((u32)pauVar8 | (u32)param_2) & 0xf) == 0 && 0xf < param_3) {
      auVar10 = _pcpyld(auVar4,auVar4);
      *(__int128 *)&auVar6 = _psubw(*(__int128 *)pauVar8, *(__int128 *)param_2);
      auVar9._8_8_ = in_t0_udw;
      auVar9._0_8_ = 0x8080808080808080;
      auVar2._8_8_ = in_t0_udw;
      auVar2._0_8_ = 0x8080808080808080;
      auVar9 = _pcpyld(auVar9,auVar2);
      auVar7._8_8_ = in_a0_udw;
      auVar7._0_8_ = param_1;
      *(__int128 *)&auVar4 = _pcpyud(*(__int128 *)&auVar6, *(__int128 *)&auVar7);
      if (auVar4._0_8_ == 0 && auVar6._0_8_ == 0) {
        do {
          param_3 = param_3 - 0x10;
          if (param_3 == 0) {
            return 0;
          }
          *(__int128 *)&auVar4 = _psubb(*(__int128 *)pauVar8, *(__int128 *)&auVar10);
          *(__int128 *)&auVar4 = _pand(*(__int128 *)&auVar4, _pnot(*(__int128 *)pauVar8));
          *(__int128 *)&auVar7 = _pand(*(__int128 *)&auVar4, *(__int128 *)&auVar9);
          auVar6._8_8_ = in_a0_udw;
          auVar6._0_8_ = param_1;
          *(__int128 *)&auVar4 = _pcpyud(*(__int128 *)&auVar7, *(__int128 *)&auVar6);
          pauVar8 = pauVar8 + 1;
          if (auVar4._0_8_ != 0 || auVar7._0_8_ != 0) {
            return 0;
          }
          param_2 = param_2 + 1;
          if (param_3 < 0x10) break;
          *(__int128 *)&auVar7 = _psubw(*(__int128 *)pauVar8, *(__int128 *)param_2);
          auVar1._8_8_ = in_a0_udw;
          auVar1._0_8_ = param_1;
          *(__int128 *)&auVar4 = _pcpyud(*(__int128 *)&auVar7, *(__int128 *)&auVar1);
        } while (auVar4._0_8_ == 0 && auVar7._0_8_ == 0);
      }
    }
    else if ((7 < param_3) && (*(long *)*pauVar8 == *(long *)*param_2)) {
      do {
        param_3 = param_3 - 8;
        if (param_3 == 0) {
          return 0;
        }
        puVar3 = *pauVar8;
        pauVar8 = (u8 (*) [16])(*pauVar8 + 8);
        if ((*(u32 *)puVar3 + 0xfefefefefefefeff & ~*(u32 *)puVar3 & 0x8080808080808080) != 0) {
          return 0;
        }
        param_2 = (u8 (*) [16])(*param_2 + 8);
      } while ((7 < param_3) && (*(long *)*pauVar8 == *(long *)*param_2));
    }
  }
  if (param_3 != 0) {
    cVar5 = (*pauVar8)[0];
    while( true ) {
      param_3 = param_3 - 1;
      puVar3 = *pauVar8;
      if (cVar5 != (*param_2)[0]) break;
      if (param_3 == 0) {
        return 0;
      }
      pauVar8 = (u8 (*) [16])(*pauVar8 + 1);
      if (*puVar3 == '\0') {
        return 0;
      }
      param_2 = (u8 (*) [16])(*param_2 + 1);
      cVar5 = (*pauVar8)[0];
    }
  }
  return (u32)(u8)(*pauVar8)[0] - (u32)(u8)(*param_2)[0];
}
// FUN_00524828 NONMATCHING
u64 FUN_00524828(u64 param_1,u8 (*param_2) [16],u32 param_3)

{
  char cVar1;
  Vec128 auVar2;
  Vec128 auVar3;
  Vec128 auVar4;
  Vec128 auVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  u8 *puVar10;
  Vec128 auVar11;
  Vec128 auVar12;
  u64 uVar13;
  u64 in_a0_udw;
  u32 uVar14;
  char *pcVar15;
  u64 in_a3_udw;
  u32 uVar16;
  u64 in_t1_udw;
  Vec128 auVar17;
  u64 in_t2_udw;
  Vec128 auVar18;
  
  pcVar15 = (char *)param_1;
  uVar14 = (u32)param_2 | (u32)pcVar15;
  if ((uVar14 & 7) != 0) goto LAB_00524990;
  uVar16 = 8;
  if ((uVar14 & 0xf) == 0) {
    uVar16 = 0x10;
  }
  if ((uVar14 & 0xf) == 0) {
    if (param_3 < uVar16) goto LAB_00524990;
    auVar12._8_8_ = in_a3_udw;
    auVar12._0_8_ = 0x101010101010101;
    auVar3._8_8_ = in_a3_udw;
    auVar3._0_8_ = 0x101010101010101;
    auVar17 = _pcpyld(auVar12,auVar3);
      *(__int128 *)&auVar11 = _psubb(_pnot(*(__int128 *)param_2), *(__int128 *)&auVar17);
    auVar4._8_8_ = in_a3_udw;
    auVar4._0_8_ = 0x8080808080808080;
    auVar5._8_8_ = in_a3_udw;
    auVar5._0_8_ = 0x8080808080808080;
    auVar18 = _pcpyld(auVar4,auVar5);
      *(__int128 *)&auVar11 = _pand(*(__int128 *)&auVar11, _pnot(*(__int128 *)param_2));
      *(__int128 *)&auVar12 = _pand(*(__int128 *)&auVar11, *(__int128 *)&auVar18);
    auVar11._8_8_ = in_a0_udw;
    auVar11._0_8_ = param_1;
      *(__int128 *)&auVar11 = _pcpyud(*(__int128 *)&auVar12, *(__int128 *)&auVar11);
    if (auVar12._0_8_ != 0 || auVar11._0_8_ != 0) goto LAB_00524990;
    puVar10 = *param_2;
    uVar6 = *(u32 *)(*param_2 + 4);
    uVar7 = *(u32 *)(*param_2 + 8);
    uVar8 = *(u32 *)(*param_2 + 0xc);
    param_3 = param_3 - 0x10;
    param_2 = param_2 + 1;
    *(u32 *)pcVar15 = *(u32 *)puVar10;
    *(u32 *)(pcVar15 + 4) = uVar6;
    *(u32 *)(pcVar15 + 8) = uVar7;
    *(u32 *)(pcVar15 + 0xc) = uVar8;
    pcVar15 = pcVar15 + 0x10;
    if (param_3 < 0x10) goto LAB_00524990;
      *(__int128 *)&auVar11 = _psubb(*(__int128 *)param_2, *(__int128 *)&auVar17);
      *(__int128 *)&auVar11 = _pand(*(__int128 *)&auVar11, _pnot(*(__int128 *)param_2));
      *(__int128 *)&auVar11 = _pand(*(__int128 *)&auVar11, *(__int128 *)&auVar18);
    auVar2._8_8_ = in_a0_udw;
    auVar2._0_8_ = param_1;
      *(__int128 *)&auVar12 = _pcpyud(*(__int128 *)&auVar11, *(__int128 *)&auVar2);
    if (auVar11._0_8_ != 0 || auVar12._0_8_ != 0) goto LAB_00524990;
    uVar13 = *(u64 *)*param_2;
  }
  else {
    if (param_3 < uVar16) goto LAB_00524990;
    auVar17._8_8_ = in_t1_udw;
    auVar17._0_8_ = 0x101010101010101;
    auVar18._8_8_ = in_t2_udw;
    auVar18._0_8_ = 0x8080808080808080;
    if ((*(u32 *)*param_2 + 0xfefefefefefefeff & ~*(u32 *)*param_2 & 0x8080808080808080) != 0)
    goto LAB_00524990;
    uVar13 = *(u64 *)*param_2;
  }
  while( true ) {
    param_3 = param_3 - 8;
    param_2 = (u8 (*) [16])(*param_2 + 8);
    *(u64 *)pcVar15 = uVar13;
    pcVar15 = pcVar15 + 8;
    if ((param_3 < 8) ||
       ((*(u32 *)*param_2 - auVar17._0_8_ & ~*(u32 *)*param_2 & auVar18._0_8_) != 0)) break;
    uVar13 = *(u64 *)*param_2;
  }
LAB_00524990:
  do {
    uVar14 = param_3;
    if (uVar14 == 0) {
      return param_1;
    }
    cVar1 = (*param_2)[0];
    param_2 = (u8 (*) [16])(*param_2 + 1);
    *pcVar15 = cVar1;
    pcVar15 = pcVar15 + 1;
    param_3 = uVar14 - 1;
  } while (cVar1 != '\0');
  uVar16 = uVar14 - 2;
  uVar14 = uVar14 - 1;
  while (uVar9 = uVar16, uVar14 != 0) {
    *pcVar15 = '\0';
    pcVar15 = pcVar15 + 1;
    uVar16 = uVar9 - 1;
    uVar14 = uVar9;
  }
  return param_1;
}
// FUN_005249E8 NONMATCHING
long FUN_005249e8(int param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  lVar2 = 0;
  if (param_2 == 0) {
    lVar2 = FUN_00523f98();
  }
  else {
    while (lVar1 = FUN_00523f98(param_1,param_2), lVar1 != 0) {
      param_1 = (int)lVar1 + 1;
      lVar2 = lVar1;
    }
  }
  return lVar2;
}
// FUN_00524A50 NONMATCHING
char * FUN_00524a50(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  if (*param_1 == '\0') {
    if (*param_2 != '\0') {
      param_1 = (char *)0x0;
    }
    return param_1;
  }
  iVar1 = 0;
  while( true ) {
    do {
      pcVar3 = param_2 + iVar1;
      pcVar2 = param_1 + iVar1;
      if (*pcVar3 == '\0') {
        return param_1;
      }
      iVar1 = iVar1 + 1;
    } while (*pcVar3 == *pcVar2);
    param_1 = param_1 + 1;
    if (*param_1 == '\0') break;
    iVar1 = 0;
  }
  return (char *)0x0;
}
// FUN_00524AA8 NONMATCHING
u32 FUN_00524aa8(u64 param_1,u64 param_2,u64 param_3)

{
  int iVar1;
  int iVar2;
  u32 uVar3;
  u64 uVar4;
  u64 uVar5;
  u64 uVar6;
  long lVar7;
  int iVar8;
  bool bVar9;
  long lVar10;
  long lVar11;
  bool bVar12;
  u32 uVar13;
  char cVar14;
  int iVar15;
  int iVar16;
  long lVar17;
  char *pcVar18;
  u32 uVar19;
  u64 *puVar20;
  u32 uVar21;
  u32 uVar22;
  int iVar23;
  u64 unaff_s4;
  u32 uVar24;
  u64 unaff_s7;
  char *pcVar25;
  char *pcVar26;
  int iStack_b0;
  int iStack_ac;
  u32 *puStack_a8;
  int iStack_a4;
  int iStack_a0;
  long lStack_98;
  char *pcStack_90;
  u32 uStack_80;
  u32 uStack_70;
  u32 uStack_68;
  int iStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  
  lVar10 = 0;
  bVar9 = false;
  uVar24 = 0;
  iStack_a0 = 0;
  pcVar18 = (char *)(u32)param_2;
LAB_00524af0:
  cVar14 = *pcVar18;
  puStack_a8 = (u32 *)(u32)param_3;
  switch(cVar14) {
  case '\0':
switchD_00524b18_caseD_0:
    pcVar18 = (char *)(u32)param_2;
LAB_00524b48:
    if (puStack_a8 != (u32 *)0x0) {
      *puStack_a8 = (u32)(pcVar18);
    }
    if (iStack_a0 != 0) {
      uVar24 = FUN_005311c8(0,uVar24);
    }
    return uVar24;
  default:
    goto LAB_00524b9c;
  case '\t':
  case '\n':
  case '\v':
  case '\f':
  case '\r':
  case ' ':
    goto switchD_00524b18_caseD_9;
  case '+':
    goto switchD_00524b18_caseD_2b;
  case '-':
    break;
  }
  iStack_a0 = 1;
switchD_00524b18_caseD_2b:
  pcVar18 = pcVar18 + 1;
  cVar14 = *pcVar18;
  if (cVar14 == '\0') goto switchD_00524b18_caseD_0;
LAB_00524b9c:
  if (cVar14 == '0') {
    bVar9 = true;
    do {
      pcVar18 = pcVar18 + 1;
      cVar14 = *pcVar18;
    } while (cVar14 == '0');
    if (cVar14 == '\0') goto LAB_00524b48;
  }
  lVar7 = (long)(int)cVar14;
  uStack_80 = 0;
  uVar22 = 0;
  lVar17 = 0;
  iStack_a4 = 0;
  pcVar25 = pcVar18;
  if ((0x2f < lVar7) && (lVar7 < 0x3a)) {
    bVar12 = true;
    do {
      if (bVar12) {
        uStack_80 = (uStack_80 * 10 + (int)lVar7) - 0x30;
      }
      else if (iStack_a4 < 0x10) {
        uVar22 = (lVar7 + uVar22 * 10) - 0x30;
      }
      pcVar25 = pcVar25 + 1;
      lVar7 = (long)*pcVar25;
      iStack_a4 = iStack_a4 + 1;
    } while ((0x2f < lVar7) && (bVar12 = iStack_a4 < 9, lVar7 < 0x3a));
  }
  iVar8 = iStack_a4;
  pcStack_90 = pcVar18;
  if (lVar7 == 0x2e) {
    pcVar25 = pcVar25 + 1;
    lVar7 = (long)*pcVar25;
    iVar15 = (int)*pcVar25;
    lVar11 = lVar10;
    if (iStack_a4 != 0) goto joined_r0x005258c0;
    if (lVar7 == 0x30) {
      do {
        pcVar25 = pcVar25 + 1;
        lVar7 = (long)*pcVar25;
        lVar10 = (long)((int)lVar10 + 1);
      } while (lVar7 == 0x30);
      iVar15 = (int)*pcVar25;
    }
    if (iVar15 - 0x31U < 9) {
      uVar13 = (u32)((int)lVar7 + -0x30);
      lVar11 = 0;
      lVar17 = lVar10;
      pcStack_90 = pcVar25;
      do {
        iVar15 = (int)lVar11;
        lVar11 = (long)(iVar15 + 1);
        if (uVar13 != 0) {
          lVar17 = (long)((int)lVar17 + iVar15 + 1);
          if (1 < lVar11) {
            do {
              bVar12 = iVar8 < 9;
              iVar8 = iVar8 + 1;
              if (bVar12) {
                uStack_80 = uStack_80 * 10;
              }
              else if (iVar8 < 0x11) {
                uVar22 = uVar22 * 10;
              }
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
          }
          bVar12 = iVar8 < 9;
          iVar8 = iVar8 + 1;
          if (bVar12) {
            uStack_80 = uStack_80 * 10 + (int)uVar13;
          }
          else if (iVar8 < 0x11) {
            uVar22 = uVar13 + uVar22 * 10;
          }
          lVar11 = 0;
        }
        pcVar25 = pcVar25 + 1;
        lVar7 = (long)*pcVar25;
        iVar15 = (int)*pcVar25;
joined_r0x005258c0:
        uVar13 = (u32)(iVar15 + -0x30);
        lVar10 = lVar11;
      } while (uVar13 < 10);
    }
  }
  lStack_98 = 0;
  if ((lVar7 == 0x65) || (pcVar18 = pcVar25, lVar7 == 0x45)) {
    if ((iVar8 == 0) && ((lVar10 == 0 && (pcVar18 = (char *)(u32)param_2, !bVar9)))) goto LAB_00524b48;
    pcVar26 = pcVar25 + 1;
    cVar14 = *pcVar26;
    lVar7 = (long)cVar14;
    bVar12 = false;
    if (lVar7 == 0x2b) {
LAB_00524d9c:
      pcVar26 = pcVar25 + 2;
      cVar14 = *pcVar26;
      lVar7 = (long)cVar14;
    }
    else if (lVar7 == 0x2d) {
      bVar12 = true;
      goto LAB_00524d9c;
    }
    pcVar18 = pcVar25;
    param_2 = (u64)(u32)pcVar25;
    if ((int)cVar14 - 0x30U < 10) {
      iVar15 = (int)lVar7;
      if (lVar7 == 0x30) {
        do {
          pcVar26 = pcVar26 + 1;
          lVar7 = (long)*pcVar26;
        } while (lVar7 == 0x30);
        iVar15 = (int)*pcVar26;
      }
      if (iVar15 - 0x31U < 9) {
        lStack_98 = (long)((int)lVar7 + -0x30);
        pcVar18 = pcVar26 + 1;
        lVar7 = (long)*pcVar18;
        iVar15 = (int)pcVar18 - (int)pcVar26;
        if ((0x2f < lVar7) && (iVar15 = (int)pcVar18 - (int)pcVar26, lVar7 < 0x3a)) {
          do {
            pcVar18 = pcVar18 + 1;
            lStack_98 = lVar7 + lStack_98 * 10;
            lVar7 = (long)*pcVar18;
            lStack_98 = lStack_98 + -0x30;
            if (lVar7 < 0x30) break;
          } while (lVar7 < 0x3a);
          iVar15 = (int)pcVar18 - (int)pcVar26;
        }
        if (8 < iVar15) {
          lStack_98 = 9999999;
        }
        if (bVar12) {
          lStack_98 = -lStack_98;
        }
      }
      else {
        lStack_98 = 0;
        pcVar18 = pcVar26;
      }
    }
  }
  if (iVar8 == 0) {
    if ((lVar10 == 0) && (!bVar9)) {
      pcVar18 = (char *)(u32)param_2;
    }
    goto LAB_00524b48;
  }
  lStack_98 = lStack_98 - lVar17;
  iVar15 = 0x10;
  if (iVar8 < 0x11) {
    iVar15 = iVar8;
  }
  iStack_5c = (int)lStack_98;
  uVar24 = FUN_00531720(uStack_80);
  iVar1 = iStack_5c;
  if (iStack_a4 == 0) {
    iStack_a4 = iVar8;
  }
  if ((int)uStack_80 < 0) {
    uVar24 = FUN_00531170(uVar24,0x41f0000000000000);
  }
  if (9 < iVar15) {
    uVar4 = FUN_00531230(*(u64 *)(&PTR_DAT_007beb30 + iVar15 * 2),uVar24);
    if ((long)uVar22 < 0) {
      uVar5 = FUN_0052eac8(uVar22 & 1 | uVar22 >> 1);
      uVar5 = FUN_00531170(uVar5,uVar5);
    }
    else {
      uVar5 = FUN_0052eac8(uVar22);
    }
    uVar24 = FUN_00531170(uVar4,uVar5);
  }
  uVar19 = iVar1 + (iVar8 - iVar15);
  iStack_60 = 0;
  if (0 < (int)uVar19) {
    if ((uVar19 & 0xf) != 0) {
      uVar24 = FUN_00531230(*(u64 *)(&DAT_007beb78 + (uVar19 & 0xf) * 8),uVar24);
    }
    if ((uVar19 & 0xfffffff0) == 0) goto LAB_005250c4;
    if ((int)(uVar19 & 0xfffffff0) < 0x135) {
      uVar19 = (int)uVar19 >> 4;
      if (uVar19 != 0) {
        iVar15 = 0;
        if (1 < (int)uVar19) {
          iVar15 = 0;
          puVar20 = (u64 *)&DAT_007bec40;
          do {
            uVar21 = uVar19 & 1;
            uVar19 = (int)uVar19 >> 1;
            if (uVar21 != 0) {
              uVar24 = FUN_00531230(*puVar20,uVar24);
            }
            puVar20 = puVar20 + 1;
            iVar15 = iVar15 + 1;
          } while (1 < (int)uVar19);
        }
        uVar24 = FUN_00531230((&DAT_007bec40)[iVar15],
                              uVar24 & 0xffffffff |
                              (long)((int)(uVar24 >> 0x20) + -0x3500000) << 0x20);
        uVar22 = (long)uVar24 >> 0x20 & 0x7ff00000;
        if (0x7ca00000 < uVar22) goto LAB_00524f90;
        if (uVar22 < 0x7c900001) {
          uVar24 = uVar24 & 0xffffffff | (long)((int)(uVar24 >> 0x20) + 0x3500000) << 0x20;
        }
        else {
          uVar24 = 0x7fefffffffffffff;
        }
      }
      goto LAB_005250c4;
    }
LAB_00524f90:
    *(u32 *)param_1 = 0x22;
    uVar24 = DAT_007bec90;
joined_r0x00524f9c:
    if (iStack_60 == 0) goto LAB_00524b48;
LAB_00524fa8:
    FUN_00521620(param_1,uStack_68);
    FUN_00521620(param_1,iStack_64);
    FUN_00521620(param_1,unaff_s7);
    FUN_00521620(param_1,iStack_60);
    FUN_00521620(param_1,unaff_s4);
    goto LAB_00524b48;
  }
  if ((int)uVar19 < 0) {
    uVar19 = -uVar19;
    if ((uVar19 & 0xf) != 0) {
      uVar24 = FUN_00531480(uVar24,*(u64 *)(&DAT_007beb78 + (uVar19 & 0xf) * 8));
    }
    uVar21 = (int)uVar19 >> 4;
    if ((uVar19 & 0xfffffff0) == 0) goto LAB_005250c4;
    if ((int)uVar21 < 0x20) {
      iVar15 = 0;
      if (1 < (int)uVar21) {
        iVar15 = 0;
        puVar20 = (u64 *)&DAT_007bec68;
        do {
          uVar19 = uVar21 & 1;
          uVar21 = (int)uVar21 >> 1;
          if (uVar19 != 0) {
            uVar24 = FUN_00531230(*puVar20,uVar24);
          }
          puVar20 = puVar20 + 1;
          iVar15 = iVar15 + 1;
        } while (1 < (int)uVar21);
      }
      uVar4 = *(u64 *)(&DAT_007bec68 + iVar15 * 8);
      uStack_70 = uVar24;
      uVar24 = FUN_00531230(uVar4,uVar24);
      lVar10 = FUN_005316d0(uVar24,0);
      if (lVar10 == 0) {
        uVar5 = FUN_00531170(uStack_70,uStack_70);
        uVar4 = FUN_00531230(uVar4,uVar5);
        lVar10 = FUN_005316d0(uVar4,0);
        uVar24 = 1;
        if (lVar10 == 0) goto LAB_005253a0;
      }
      goto LAB_005250c4;
    }
LAB_005253a0:
    *(u32 *)param_1 = 0x22;
    uVar24 = 0;
    goto joined_r0x00524f9c;
  }
LAB_005250c4:
  iStack_60 = FUN_00521758(param_1,pcStack_90,iStack_a4,iVar8,uStack_80);
  iStack_58 = iStack_60 + 0xc;
  do {
    iStack_64 = FUN_00521578(param_1,*(u32 *)(iStack_60 + 4));
    FUN_00521250(iStack_64 + 0xc,iStack_58,*(int *)(iStack_60 + 0x10) * 4 + 8);
    uStack_68 = FUN_005222c0(param_1,uVar24,&iStack_b0,&iStack_ac);
    unaff_s7 = FUN_005219c8(param_1,1);
    if (lStack_98 < 0) {
      iVar15 = 0;
      iVar8 = -iStack_5c;
    }
    else {
      iVar8 = 0;
      iVar15 = iStack_5c;
    }
    if (iStack_b0 < 0) {
      iVar1 = iVar15 - iStack_b0;
      iVar23 = iVar8;
    }
    else {
      iVar23 = iVar8 + iStack_b0;
      iVar1 = iVar15;
    }
    iVar16 = iStack_b0 + 0x433;
    if (-0x3ff < iStack_b0 + iStack_ac + -1) {
      iVar16 = 0x36 - iStack_ac;
    }
    iVar1 = iVar1 + iVar16;
    iVar16 = iVar23 + iVar16;
    iVar2 = iVar1;
    if (iVar16 < iVar1) {
      iVar2 = iVar16;
    }
    if (iVar23 < iVar2) {
      iVar2 = iVar23;
    }
    if (0 < iVar2) {
      iVar23 = iVar23 - iVar2;
      iVar16 = iVar16 - iVar2;
      iVar1 = iVar1 - iVar2;
    }
    if (0 < iVar8) {
      unaff_s7 = FUN_00521c08(param_1,unaff_s7);
      uVar3 = FUN_00521a00(param_1,unaff_s7,uStack_68);
      FUN_00521620(param_1,uStack_68);
      uStack_68 = uVar3;
    }
    if (0 < iVar16) {
      uStack_68 = FUN_00521d10(param_1,uStack_68,iVar16);
    }
    if (0 < iVar15) {
      iStack_64 = FUN_00521c08(param_1,iStack_64,iVar15);
    }
    if (0 < iVar1) {
      iStack_64 = FUN_00521d10(param_1,iStack_64,iVar1);
    }
    if (0 < iVar23) {
      unaff_s7 = FUN_00521d10(param_1,unaff_s7,iVar23);
    }
    unaff_s4 = FUN_00521ed8(param_1,uStack_68,iStack_64);
    iVar8 = *(int *)((int)unaff_s4 + 0xc);
    *(u32 *)((int)unaff_s4 + 0xc) = 0;
    lVar10 = FUN_00521e70(unaff_s4,unaff_s7);
    uVar19 = (u32)(uVar24 >> 0x20);
    if (lVar10 < 0) {
      if ((iVar8 == 0) && ((uVar24 & 0xfffffffffffff) == 0)) {
        unaff_s4 = FUN_00521d10(param_1,unaff_s4,1);
        lVar10 = FUN_00521e70(unaff_s4,unaff_s7);
        if (0 < lVar10) {
LAB_005252c0:
          uVar24 = uVar24 & 0xffffffff |
                   ((u32)((uVar19 & 0x7ff00000) - 0x100000) | 0xfffff) << 0x20 | 0xffffffff;
        }
      }
      goto LAB_00524fa8;
    }
    if (lVar10 == 0) {
      if (iVar8 == 0) {
        if ((uVar24 & 0xfffffffffffff) == 0) goto LAB_005252c0;
      }
      else if ((uVar24 & 0xfffffffffffff) == 0xfffffffffffff) {
        uVar24 = (u32)((uVar19 & 0x7ff00000) + 0x100000) << 0x20;
        goto LAB_00524fa8;
      }
      if ((uVar24 & 1) != 0) {
        if (iVar8 == 0) {
          uVar4 = FUN_00522058(uVar24,uStack_68);
          uVar24 = FUN_005311c8(uVar24,uVar4);
          lVar10 = FUN_005316d0(uVar24,0);
          if (lVar10 == 0) goto LAB_005253a0;
        }
        else {
          uVar4 = FUN_00522058(uVar24,uStack_68);
          uVar24 = FUN_00531170(uVar4,uVar24);
        }
      }
      goto LAB_00524fa8;
    }
    uVar4 = FUN_00522440(unaff_s4,unaff_s7);
    lVar10 = FUN_005316d0(uVar4,0x4000000000000000);
    if (lVar10 < 1) {
      if (iVar8 == 0) {
        if ((uVar24 & 0xfffffffffffff) == 0) {
          lVar10 = FUN_005316d0(uVar4,0x3ff0000000000000);
          if (lVar10 < 0) {
            uVar4 = 0x3fe0000000000000;
          }
          else {
            uVar4 = FUN_00531230(uVar4,0x3fe0000000000000);
          }
          uVar5 = FUN_005311c8(0,uVar4);
        }
        else {
          if (uVar24 == 1) goto LAB_005253a0;
          uVar4 = 0x3ff0000000000000;
          uVar5 = 0xbff0000000000000;
        }
      }
      else {
        uVar4 = 0x3ff0000000000000;
        uVar5 = uVar4;
      }
    }
    else {
      uVar4 = FUN_00531230(uVar4,0x3fe0000000000000);
      uVar5 = uVar4;
      if (iVar8 == 0) {
        uVar5 = FUN_005311c8(0,uVar4);
      }
      uVar5 = FUN_00531170(uVar5,0x3fe0000000000000);
    }
    uStack_80 = uVar19 & 0x7ff00000;
    if (uStack_80 == 0x7fe00000) {
      uVar22 = uVar24 & 0xffffffff | (long)(int)(uVar19 + 0xfcb00000) << 0x20;
      uStack_70 = uVar24;
      uVar6 = FUN_00522058(uVar22);
      uVar5 = FUN_00531230(uVar5,uVar6);
      uVar24 = FUN_00531170(uVar5,uVar22);
      if (((long)uVar24 >> 0x20 & 0x7ff00000U) < 0x7ca00000) {
        uVar24 = uVar24 & 0xffffffff | (long)((int)(uVar24 >> 0x20) + 0x3500000) << 0x20;
        goto LAB_00525530;
      }
      if (uStack_70 == 0x7fefffffffffffff) goto LAB_00524f90;
      uVar24 = 0x7fefffffffffffff;
    }
    else {
      if ((uStack_80 < 0x3400001) && (lVar10 = FUN_005316d0(0x3ff0000000000000,uVar4), lVar10 < 1))
      {
        uVar5 = FUN_00531170(uVar4,0x3fe0000000000000);
        uVar5 = FUN_005317d0(uVar5);
        uVar5 = FUN_00531720(uVar5);
        if (iVar8 == 0) {
          uVar5 = FUN_005311c8(0,uVar5);
        }
      }
      uVar6 = FUN_00522058(uVar24);
      uVar5 = FUN_00531230(uVar5,uVar6);
      uVar24 = FUN_00531170(uVar5,uVar24);
LAB_00525530:
      if ((u32)uStack_80 == ((long)uVar24 >> 0x20 & 0x7ff00000U)) {
        uVar5 = FUN_0052ed30(uVar4,uStack_68);
        uVar5 = FUN_0052eac8(uVar5);
        uVar4 = FUN_005311c8(uVar4,uVar5);
        if ((((iVar8 != 0) || (uVar5 = uVar4, uVar6 = DAT_007becf0, (uVar24 & 0xfffffffffffff) != 0)
             ) && (lVar10 = FUN_005316d0(uVar4,DAT_007bece0), uVar5 = DAT_007bece8, uVar6 = uVar4,
                  lVar10 < 0)) || (lVar10 = FUN_005316d0(uVar5,uVar6), lVar10 < 0))
        goto LAB_00524fa8;
      }
    }
    FUN_00521620(param_1,uStack_68);
    FUN_00521620(param_1,iStack_64);
    FUN_00521620(param_1,unaff_s7);
    FUN_00521620(param_1,unaff_s4);
  } while( true );
switchD_00524b18_caseD_9:
  pcVar18 = pcVar18 + 1;
  goto LAB_00524af0;
}
// FUN_00525920 NONMATCHING
void FUN_00525920(u64 param_1,u64 param_2)

{
  u64 uVar1;
  
  uVar1 = (u64)(u32)FUN_00524aa8((u64)(u32)PTR_DAT_00782f30,param_1,param_2);
  FUN_005318a0(uVar1);
  return;
}
// FUN_00525958 NONMATCHING
char * FUN_00525958(char *param_1,char *param_2)

{
  char *pcVar1;
  char *pcVar2;
  u32 *puVar3;
  char cVar4;
  char *pcVar5;
  char cVar6;
  
  puVar3 = (u32 *)((u8 *)PTR_DAT_00782f30 + 0x5c);
  if (param_1 == (char *)0x0) {
    param_1 = (char *)*puVar3;
    if (param_1 == (char *)0x0) {
      return (char *)0x0;
    }
    cVar4 = *param_1;
  }
  else {
    cVar4 = *param_1;
  }
  do {
    cVar6 = *param_2;
    pcVar1 = param_1 + 1;
    pcVar5 = param_2;
    while( true ) {
      if (cVar6 == '\0') {
        if (cVar4 == '\0') {
          *puVar3 = 0;
          return (char *)0x0;
        }
        cVar4 = *pcVar1;
        do {
          pcVar2 = pcVar1 + 1;
          cVar6 = *param_2;
          pcVar5 = param_2;
          while( true ) {
            pcVar5 = pcVar5 + 1;
            if (cVar6 == cVar4) {
              if (cVar6 == '\0') {
                pcVar2 = (char *)0x0;
              }
              else {
                *pcVar1 = '\0';
              }
              *puVar3 = (u32)(pcVar2);
              return param_1;
            }
            if (cVar6 == '\0') break;
            cVar6 = *pcVar5;
          }
          cVar4 = *pcVar2;
          pcVar1 = pcVar2;
        } while( true );
      }
      pcVar5 = pcVar5 + 1;
      if (cVar4 == cVar6) break;
      cVar6 = *pcVar5;
    }
    cVar4 = *pcVar1;
    param_1 = pcVar1;
  } while( true );
}
// FUN_00525A10 NONMATCHING
u32 FUN_00525a10(u32 *param_1,char *param_2,u32 *param_3,long param_4)

{
  char cVar1;
  u8 bVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  u32 uVar6;
  u32 uVar7;
  long lVar8;
  int iVar9;
  long lVar10;
  char *pcVar11;
  char *pcVar12;
  u64 uVar13;
  int iVar14;
  
  bVar4 = false;
  pcVar12 = param_2;
  do {
    pcVar11 = pcVar12;
    lVar10 = (long)*pcVar11;
    pcVar12 = pcVar11 + 1;
  } while ((*(u8 *)((int)&PTR_DAT_007be9c8 + (int)*pcVar11) & 8) != 0);
  if (lVar10 == 0x2d) {
    cVar1 = *pcVar12;
    bVar4 = true;
  }
  else {
    if (lVar10 != 0x2b) goto LAB_00525a94;
    cVar1 = *pcVar12;
  }
  lVar10 = (long)cVar1;
  pcVar12 = pcVar11 + 2;
LAB_00525a94:
  if ((((param_4 == 0) || (param_4 == 0x10)) && (lVar10 == 0x30)) &&
     ((*pcVar12 == 'x' || (*pcVar12 == 'X')))) {
    lVar10 = (long)pcVar12[1];
    param_4 = 0x10;
    pcVar12 = pcVar12 + 2;
  }
  if (param_4 == 0) {
    param_4 = 8;
    if (lVar10 != 0x30) {
      param_4 = 10;
    }
  }
  uVar13 = 0x8000000000000000;
  if (!bVar4) {
    uVar13 = 0x7fffffffffffffff;
  }
  iVar14 = 0;
  iVar5 = FUN_00530578(uVar13,param_4);
  uVar6 = FUN_0052fe98(uVar13,param_4);
  uVar7 = 0;
  do {
    iVar9 = (int)lVar10;
    bVar2 = *(u8 *)((int)&PTR_DAT_007be9c8 + iVar9);
    if ((bVar2 & 4) == 0) {
      if ((bVar2 & 3) == 0) {
LAB_00525ba4:
        if (iVar14 < 0) {
          *param_1 = 0x22;
          uVar7 = 0x8000000000000000;
          if (!bVar4) {
            uVar7 = 0x7fffffffffffffff;
          }
        }
        else if (bVar4) {
          uVar7 = -uVar7;
        }
        if (param_3 != (u32 *)0x0) {
          if (iVar14 != 0) {
            param_2 = pcVar12 + -1;
          }
          *param_3 = (u32)(param_2);
        }
        return uVar7;
      }
      iVar3 = iVar9 + -0x37;
      if ((bVar2 & 1) == 0) {
        iVar3 = iVar9 + -0x57;
      }
    }
    else {
      iVar3 = iVar9 + -0x30;
    }
    lVar10 = (long)iVar3;
    if (param_4 <= lVar10) goto LAB_00525ba4;
    if (iVar14 < 0) {
LAB_00525b80:
      iVar14 = -1;
    }
    else if (uVar6 < uVar7) {
      iVar14 = -1;
    }
    else {
      if ((uVar7 == uVar6) && (iVar5 < lVar10)) goto LAB_00525b80;
      lVar8 = FUN_0052ea78(uVar7,param_4);
      iVar14 = 1;
      uVar7 = lVar10 + lVar8;
    }
    lVar10 = (long)*pcVar12;
    pcVar12 = pcVar12 + 1;
  } while( true );
}
// FUN_00525C50 NONMATCHING
void FUN_00525c50(char *param_1,u32 *param_2,long param_3)
{
  FUN_00525a10(PTR_DAT_00782f30,param_1,param_2,param_3);
  return;
}
// FUN_00525C80 NONMATCHING
u32 FUN_00525c80(u32 *param_1,char *param_2,u32 *param_3,long param_4)

{
  char cVar1;
  u8 bVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  u32 uVar6;
  u32 uVar7;
  long lVar8;
  int iVar9;
  long lVar10;
  char *pcVar11;
  char *pcVar12;
  int iVar13;
  
  bVar4 = false;
  pcVar12 = param_2;
  do {
    pcVar11 = pcVar12;
    lVar10 = (long)*pcVar11;
    pcVar12 = pcVar11 + 1;
  } while ((*(u8 *)((int)&PTR_DAT_007be9c8 + (int)*pcVar11) & 8) != 0);
  if (lVar10 == 0x2d) {
    cVar1 = *pcVar12;
    bVar4 = true;
  }
  else {
    if (lVar10 != 0x2b) goto LAB_00525d04;
    cVar1 = *pcVar12;
  }
  lVar10 = (long)cVar1;
  pcVar12 = pcVar11 + 2;
LAB_00525d04:
  if ((((param_4 == 0) || (param_4 == 0x10)) && (lVar10 == 0x30)) &&
     ((*pcVar12 == 'x' || (*pcVar12 == 'X')))) {
    lVar10 = (long)pcVar12[1];
    param_4 = 0x10;
    pcVar12 = pcVar12 + 2;
  }
  if (param_4 == 0) {
    param_4 = 8;
    if (lVar10 != 0x30) {
      param_4 = 10;
    }
  }
  iVar13 = 0;
  uVar6 = FUN_0052fe98(0xffffffffffffffff,param_4);
  iVar5 = FUN_00530578(0xffffffffffffffff,param_4);
  uVar7 = 0;
  do {
    iVar9 = (int)lVar10;
    bVar2 = *(u8 *)((int)&PTR_DAT_007be9c8 + iVar9);
    if ((bVar2 & 4) == 0) {
      if ((bVar2 & 3) == 0) {
LAB_00525dfc:
        if (iVar13 < 0) {
          *param_1 = 0x22;
          uVar7 = 0xffffffffffffffff;
        }
        else if (bVar4) {
          uVar7 = -uVar7;
        }
        if (param_3 != (u32 *)0x0) {
          if (iVar13 != 0) {
            param_2 = pcVar12 + -1;
          }
          *param_3 = (u32)(param_2);
        }
        return uVar7;
      }
      iVar3 = iVar9 + -0x37;
      if ((bVar2 & 1) == 0) {
        iVar3 = iVar9 + -0x57;
      }
    }
    else {
      iVar3 = iVar9 + -0x30;
    }
    lVar10 = (long)iVar3;
    if (param_4 <= lVar10) goto LAB_00525dfc;
    if (iVar13 < 0) {
LAB_00525dd8:
      iVar13 = -1;
    }
    else if (uVar6 < uVar7) {
      iVar13 = -1;
    }
    else {
      if ((uVar7 == uVar6) && (iVar5 < lVar10)) goto LAB_00525dd8;
      lVar8 = FUN_0052ea78(uVar7,param_4);
      iVar13 = 1;
      uVar7 = lVar10 + lVar8;
    }
    lVar10 = (long)*pcVar12;
    pcVar12 = pcVar12 + 1;
  } while( true );
}
// FUN_00525E98 NONMATCHING
void FUN_00525e98(char *param_1,u32 *param_2,long param_3)
{
  FUN_00525c80(PTR_DAT_00782f30,param_1,param_2,param_3);
  return;
}
// FUN_00525EC8 NONMATCHING
u32 FUN_00525ec8(u32 *param_1)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  u8 *puVar4;
  int iVar5;
  int iVar6;
  
  if ((int *)param_1[0xc] == (int *)((u32)param_1 + 0x10)) {
    lVar3 = FUN_005209c0(param_1[0x15],0x400);
    uVar2 = 0xffffffff;
    if (lVar3 != 0) {
      param_1[0xc] = (int)lVar3;
      param_1[0xd] = 0x400;
      iVar6 = 2;
      iVar5 = (int)lVar3 + 0x3fd;
      do {
        puVar4 = (u8 *)(iVar5 + iVar6);
        iVar1 = iVar6 + 0x40;
        iVar6 = iVar6 + -1;
        *puVar4 = *(u8 *)((int)param_1 + iVar1);
      } while (-1 < iVar6);
      *param_1 = iVar5;
      uVar2 = 0;
    }
  }
  else {
    iVar5 = param_1[0xd];
    lVar3 = FUN_00522fc0(param_1[0x15],(int *)param_1[0xc],iVar5 << 1);
    uVar2 = 0xffffffff;
    if (lVar3 != 0) {
      iVar6 = (int)lVar3 + iVar5;
      FUN_00521250(iVar6,lVar3,iVar5);
      param_1[0xd] = iVar5 << 1;
      uVar2 = 0;
      *param_1 = iVar6;
      param_1[0xc] = (int)lVar3;
    }
  }
  return uVar2;
}
// FUN_00525FB0 NONMATCHING
u32 FUN_00525fb0(u32 param_1,u64 param_2)

{
  u8 *puVar1;
  long lVar2;
  u32 *puVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u16 uVar7;
  int iVar8;
  
  puVar1 = PTR_DAT_00782f30;
  puVar3 = (u32 *)param_2;
  uVar4 = 0xffffffffffffffff;
  if (param_1 != 0xffffffffffffffff) {
    if (puVar3[0x15] == 0) {
      puVar3[0x15] = (u32)PTR_DAT_00782f30;
      iVar8 = *(int *)(puVar1 + 0x38);
    }
    else {
      iVar8 = *(int *)(puVar3[0x15] + 0x38);
    }
    if (iVar8 == 0) {
      FUN_0051fa20();
      uVar7 = (u16)puVar3[3];
    }
    else {
      uVar7 = (u16)puVar3[3];
    }
    *(u16 *)(puVar3 + 3) = uVar7 & 0xffdf;
    if ((uVar7 & 4) == 0) {
      if ((uVar7 & 0x10) == 0) {
        return 0xffffffffffffffff;
      }
      if ((uVar7 & 8) == 0) {
        uVar7 = (u16)puVar3[3];
      }
      else {
        lVar2 = FUN_0051f728(param_2);
        if (lVar2 != 0) {
          return 0xffffffffffffffff;
        }
        puVar3[2] = 0;
        puVar3[6] = 0;
        *(u16 *)(puVar3 + 3) = (u16)puVar3[3] & 0xfff7;
        uVar7 = (u16)puVar3[3];
      }
      *(u16 *)(puVar3 + 3) = uVar7 | 4;
    }
    uVar4 = param_1 & 0xff;
    if (puVar3[0xc] == 0) {
      uVar5 = *puVar3;
      if (puVar3[4] == 0) {
        uVar6 = puVar3[1];
      }
      else {
        uVar6 = puVar3[1];
        if ((puVar3[4] < uVar5) && (*(u8 *)(uVar5 - 1) == uVar4)) {
          *puVar3 = uVar5 - 1;
          puVar3[1] = uVar6 + 1;
          return uVar4;
        }
      }
      puVar3[0xe] = uVar5;
      puVar3[1] = 1;
      puVar3[0xf] = uVar6;
      puVar3[0xc] = (u32)(puVar3 + 0x10);
      puVar3[0xd] = 3;
      *puVar3 = (int)puVar3 + 0x42;
      *(char *)((int)puVar3 + 0x42) = (char)param_1;
    }
    else {
      if ((int)puVar3[1] < (int)puVar3[0xd]) {
        uVar5 = *puVar3;
      }
      else {
        lVar2 = (long)FUN_00525ec8((u32 *)(u32)param_2);
        if (lVar2 != 0) {
          return 0xffffffffffffffff;
        }
        uVar5 = *puVar3;
      }
      *puVar3 = uVar5 - 1;
      *(char *)(uVar5 - 1) = (char)param_1;
      puVar3[1] = puVar3[1] + 1;
    }
  }
  return uVar4;
}
// FUN_00526140 NONMATCHING
u64 FUN_00526140(int param_1, int **param_2)
{
  u64 uVar1;
  
  if (*(int *)((char *)param_2 + 8) == 0) {
    *(u32 *)((char *)param_2 + 4) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00520048();
    *(u32 *)((char *)param_2 + 4) = 0;
    *(u32 *)((char *)param_2 + 8) = 0;
  }
  return uVar1;
}
// FUN_00526188 NONMATCHING
int FUN_00526188(int param_1, char *param_2, unsigned int *param_3)

{
  long lVar1;
  long lVar2;
  u8 *apuStack_480 [2];
  u32 uStack_478;
  u16 uStack_474;
  u16 uStack_472;
  u8 *puStack_470;
  u32 uStack_46c;
  u32 uStack_468;
  u32 uStack_464;
  u32 uStack_45c;
  u32 uStack_42c;
  u8 auStack_420 [1024];
  
  apuStack_480[0] = auStack_420;
  uStack_42c = *(u32 *)(param_1 + 0x54);
  uStack_472 = *(u16 *)(param_1 + 0xe);
  uStack_474 = *(u16 *)(param_1 + 0xc) & 0xfffd;
  uStack_464 = *(u32 *)(param_1 + 0x1c);
  uStack_45c = *(u32 *)(param_1 + 0x24);
  uStack_46c = 0x400;
  uStack_478 = 0x400;
  uStack_468 = 0;
  puStack_470 = apuStack_480[0];
  lVar1 = (u64)(FUN_00526238(apuStack_480));
  if ((-1 < lVar1) && (lVar2 = FUN_0051f728(apuStack_480), lVar2 != 0)) {
    lVar1 = -1;
  }
  if ((uStack_474 & 0x40) != 0) {
    *(u16 *)(param_1 + 0xc) = *(u16 *)(param_1 + 0xc) | 0x40;
  }
  return lVar1;
}
// FUN_00526238 NONMATCHING
int FUN_00526238(void *param_1)
{
  u32 uVar1;
  u8 *puVar2;
  int iVar3;
  u8 *puVar4;
  
  puVar2 = PTR_DAT_00782f30;
  iVar3 = (int)param_1;
  puVar4 = *(u8 **)(iVar3 + 0x54);
  if (*(u8 **)(iVar3 + 0x54) == (u8 *)0x0) {
    *(u8 **)(iVar3 + 0x54) = PTR_DAT_00782f30;
    puVar4 = puVar2;
  }
  if (*(int *)(puVar4 + 0x38) == 0) {
    FUN_0051fa20();
    uVar1 = *(u32 *)(iVar3 + 0x54);
  }
  else {
    uVar1 = *(u32 *)(iVar3 + 0x54);
  }
  FUN_005262b0(uVar1,(int)param_1,0,0);
  return 0;
}
// FUN_005262B0 NONMATCHING
int FUN_005262b0(u32 param_1,int param_2,char *param_3,u32 *param_4)

{
  u16 uVar1;
  u32 uVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  long lVar7;
  long lVar8;
  u32 uVar9;
  char cVar10;
  int iVar11;
  char *pcVar12;
  char *pcVar13;
  char *pcVar14;
  char acStack_280 [16];
  u8 auStack_270 [608];
  int *piStack_260;
  int iStack_25c;
  int iStack_258;
  int aiStack_250 [16];
  char acStack_210 [347];
  char cStack_b5;
  char acStack_b4 [4];
  char cStack_b0;
  u8 uStack_af;
  int iStack_a0;
  u32 uStack_9c;
  char *pcStack_98;
  int iStack_94;
  u32 uStack_90;
  int iStack_8c;
  u32 *puStack_88;
  u32 uStack_84;
  int iStack_80;
  char *pcStack_7c;
  int iStack_78;
  u32 uStack_70;
  int iStack_68;
  char *pcStack_64;
  char *pcStack_60;
  u32 uStack_5c;
  
  uStack_90 = param_1;
  iStack_8c = param_2;
  puStack_88 = param_4;
  piVar4 = (int *)FUN_00520560();
  iStack_78 = *piVar4;
  uVar1 = *(u16 *)(iStack_8c + 0xc);
  uStack_70 = 0;
  iStack_68 = 0;
  pcStack_60 = (char *)0x0;
  uStack_9c = 0;
  if (((uVar1 & 8) == 0) || (*(int *)(iStack_8c + 0x10) == 0)) {
    lVar7 = FUN_005289d0(iStack_8c);
    if (lVar7 != 0) {
      return -1;
    }
    uVar1 = *(u16 *)(iStack_8c + 0xc);
  }
  piStack_260 = aiStack_250;
  if (((uVar1 & 0x1a) == 10) && (-1 < *(short *)(iStack_8c + 0xe))) {
    iVar5 = FUN_00526188(iStack_8c,param_3,puStack_88);
    return iVar5;
  }
  iStack_258 = 0;
  iStack_25c = 0;
  iStack_80 = 0;
  pcVar12 = param_3;
  piVar4 = piStack_260;
LAB_005263c4:
  lVar7 = FUN_005210a8(PTR_DAT_00782f30,&iStack_a0,param_3,DAT_00782f38,&uStack_9c);
  if (0 < lVar7) goto LAB_005277f8;
  goto LAB_005263e4;
LAB_005277f8:
  param_3 = param_3 + (int)lVar7;
  if (iStack_a0 == 0x25) {
    param_3 = param_3 + -1;
LAB_005263e4:
    iVar5 = (int)param_3 - (int)pcVar12;
    if (iVar5 != 0) {
      piVar4[1] = iVar5;
      *piVar4 = (int)pcVar12;
      piVar4 = piVar4 + 2;
      iStack_25c = iStack_25c + 1;
      iStack_258 = iStack_258 + iVar5;
      if (7 < iStack_25c) {
        lVar8 = (int)(FUN_00526140(iStack_8c,&piStack_260));
        piVar4 = aiStack_250;
        if (lVar8 != 0) goto LAB_005267b0;
      }
      iStack_80 = iStack_80 + iVar5;
    }
    param_3 = param_3 + 1;
    if (0 < lVar7) {
      acStack_280[0] = '\0';
      uStack_84 = 0;
      pcStack_64 = (char *)0x0;
      cVar10 = *param_3;
      pcStack_7c = (char *)0x0;
LAB_00526458:
      pcVar6 = (char *)0xffffffff;
      do {
        param_3 = param_3 + 1;
        lVar7 = (long)(int)cVar10;
LAB_00526468:
        pcVar12 = param_3;
        switch((int)lVar7) {
        case 0x20:
          cVar10 = ' ';
          if (acStack_280[0] == '\0') {
LAB_005264a4:
            acStack_280[0] = cVar10;
          }
LAB_0052649c:
          cVar10 = *param_3;
          break;
        default:
          pcVar13 = acStack_210;
          if (lVar7 == 0) goto LAB_005277c4;
          acStack_210[0] = (char)lVar7;
          acStack_280[0] = '\0';
          pcVar6 = (char *)0x1;
          goto LAB_00526664;
        case 0x23:
          cVar10 = *param_3;
          uStack_84 = uStack_84 | 1;
          break;
        case 0x2a:
          pcStack_7c = *(char **)puStack_88;
          puStack_88 = puStack_88 + 1;
          if (-1 < (int)pcStack_7c) goto LAB_0052649c;
          pcStack_7c = (char *)-(int)pcStack_7c;
        case 0x2d:
          cVar10 = *param_3;
          uStack_84 = uStack_84 | 4;
          break;
        case 0x2b:
          cVar10 = '+';
          goto LAB_005264a4;
        case 0x2e:
          cVar10 = *param_3;
          lVar7 = (long)cVar10;
          param_3 = param_3 + 1;
          if (lVar7 == 0x2a) {
            pcVar6 = *(char **)puStack_88;
            puStack_88 = puStack_88 + 1;
            if (-2 < (int)pcVar6) goto LAB_0052649c;
            cVar10 = *param_3;
            goto LAB_00526458;
          }
          pcVar6 = (char *)0x0;
          while ((int)cVar10 - 0x30U < 10) {
            iVar5 = (int)lVar7;
            cVar10 = *param_3;
            lVar7 = (long)cVar10;
            pcVar6 = (char *)(((int)pcVar6 * 10 + iVar5) - 0x30);
            param_3 = param_3 + 1;
          }
          if ((int)pcVar6 < -1) {
            pcVar6 = (char *)0xffffffff;
          }
          goto LAB_00526468;
        case 0x30:
          cVar10 = *param_3;
          uStack_84 = uStack_84 | 0x80;
          break;
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x39:
          goto switchD_00526488_caseD_31;
        case 0x44:
          uStack_84 = uStack_84 | 0x10;
        case 100:
        case 0x69:
          if ((uStack_84 & 0x10) == 0) {
            if ((uStack_84 & 0x40) == 0) {
              uVar9 = (u32)(int)(u32)*puStack_88;
            }
            else {
              uVar9 = (u32)(short)(u16)*puStack_88;
            }
          }
          else {
            uVar9 = *puStack_88;
          }
          iVar5 = 1;
          if ((long)uVar9 < 0) {
            uVar9 = -uVar9;
            acStack_280[0] = '-';
          }
LAB_00526604:
          puStack_88 = puStack_88 + 1;
          if (-1 < (int)pcVar6) {
            uStack_84 = uStack_84 & 0xffffff7f;
          }
          pcVar13 = acStack_b4;
          pcStack_64 = pcVar6;
          if ((uVar9 == 0) && (pcVar6 == (char *)0x0)) {
            pcVar6 = acStack_280 + -(int)pcVar13;
            if (iVar5 != 0) goto LAB_00527234;
            if ((uStack_84 & 1) != 0) {
              pcVar13 = &cStack_b5;
              cStack_b5 = '0';
            }
            goto LAB_00527230;
          }
          if (iVar5 == 1) goto joined_r0x00527284;
          if (iVar5 == 0) goto LAB_00527240;
          if (iVar5 == 2) goto LAB_0052720c;
          pcVar13 = s_0000000000000000bug_in_vfprintf__007bedb0 + 0x20;
          pcVar6 = (char *)FUN_00524388(0x7bedd0);
          goto LAB_00526664;
        case 0x45:
        case 0x47:
        case 0x65:
        case 0x66:
        case 0x67:
          if (pcVar6 == (char *)0xffffffff) {
            pcVar14 = (char *)0x6;
          }
          else {
            pcVar14 = pcVar6;
            if (((lVar7 == 0x67) || (lVar7 == 0x47)) && (pcVar6 == (char *)0x0)) {
              pcVar14 = (char *)0x1;
            }
          }
          if ((uStack_84 & 8) == 0) {
            uStack_70 = *puStack_88;
          }
          else {
            uStack_70 = *puStack_88;
          }
          puStack_88 = puStack_88 + 1;
          lVar8 = FUN_00523730(uStack_70);
          if (lVar8 == 0) {
            lVar8 = FUN_00523778(uStack_70);
            if (lVar8 == 0) {
              uStack_84 = uStack_84 | 0x100;
              pcVar13 = (char *)FUN_00527810(uStack_90,uStack_70,(int)(u32)pcVar14,uStack_84,(u8 *)(acStack_280 + 1),
                                             (u64)(u32)&pcStack_98,lVar7,&iStack_94);
              if (((lVar7 == 0x67) || (lVar8 = lVar7, lVar7 == 0x47)) &&
                 (((int)pcStack_98 < -3 || (lVar8 = 0x67, (int)pcVar14 < (int)pcStack_98)))) {
                lVar8 = 0x65;
                if (lVar7 != 0x67) {
                  lVar8 = 0x45;
                }
              }
              if (lVar8 < 0x66) {
                pcStack_98 = pcStack_98 + -1;
                iStack_68 = (int)FUN_005279b8(auStack_270,(int)(u32)pcStack_98,lVar8);
                if ((1 < iStack_94) ||
                   (pcVar6 = (char *)(iStack_68 + iStack_94), (uStack_84 & 1) != 0)) {
                  pcVar6 = (char *)(iStack_68 + iStack_94) + 1;
                }
              }
              else if (lVar8 == 0x66) {
                pcVar6 = pcVar14 + 2;
                if ((0 < (int)pcStack_98) &&
                   ((pcVar14 != (char *)0x0 || (pcVar6 = pcStack_98, (uStack_84 & 1) != 0)))) {
                  pcVar6 = pcStack_98 + (int)pcVar14 + 1;
                }
              }
              else if ((int)pcStack_98 < iStack_94) {
                if ((int)pcStack_98 < 1) {
                  pcVar6 = (char *)((iStack_94 - (int)pcStack_98) + 2);
                }
                else {
                  pcVar6 = (char *)(iStack_94 + 1);
                }
              }
              else {
                pcVar6 = pcStack_98;
                if ((uStack_84 & 1) != 0) {
                  pcVar6 = pcStack_98 + 1;
                }
              }
              lVar7 = lVar8;
              if (acStack_280[1] != '\0') {
                acStack_280[0] = '-';
              }
            }
            else {
              pcVar6 = (char *)0x3;
              pcVar13 = (char *)0x7bee20;
            }
          }
          else {
            lVar8 = FUN_005316d0(uStack_70,0);
            if (lVar8 < 0) {
              acStack_280[0] = '-';
            }
            pcVar6 = (char *)0x3;
            pcVar13 = (char *)0x7bee18;
          }
          goto LAB_00526664;
        case 0x4c:
          cVar10 = *param_3;
          uStack_84 = uStack_84 | 8;
          break;
        case 0x4f:
          uStack_84 = uStack_84 | 0x10;
        case 0x6f:
          if ((uStack_84 & 0x10) == 0) {
            if ((uStack_84 & 0x40) == 0) {
              uVar9 = (u32)(u32)*puStack_88;
            }
            else {
              uVar9 = (u32)(u16)*puStack_88;
            }
          }
          else {
            uVar9 = *puStack_88;
          }
          iVar5 = 0;
LAB_0052735c:
          acStack_280[0] = '\0';
          goto LAB_00526604;
        case 0x55:
          uStack_84 = uStack_84 | 0x10;
        case 0x75:
          if ((uStack_84 & 0x10) == 0) {
            if ((uStack_84 & 0x40) == 0) {
              uVar9 = (u32)(u32)*puStack_88;
            }
            else {
              uVar9 = (u32)(u16)*puStack_88;
            }
          }
          else {
            uVar9 = *puStack_88;
          }
          iVar5 = 1;
          goto LAB_0052735c;
        case 0x58:
          pcStack_60 = s_0123456789ABCDEF_007bee00;
          goto LAB_005273e4;
        case 99:
          pcVar13 = acStack_210;
          pcVar6 = (char *)0x1;
          acStack_210[0] = (char)*puStack_88;
          puStack_88 = puStack_88 + 1;
          acStack_280[0] = '\0';
          goto LAB_00526664;
        case 0x68:
          cVar10 = *param_3;
          uStack_84 = uStack_84 | 0x40;
          break;
        case 0x6c:
          cVar10 = *param_3;
          if (cVar10 != 'l') {
            uStack_84 = uStack_84 | 0x10;
            break;
          }
          param_3 = param_3 + 1;
          uStack_84 = uStack_84 | 0x10;
          goto LAB_0052649c;
        case 0x6e:
          if ((uStack_84 & 0x10) == 0) {
            if ((uStack_84 & 0x40) == 0) {
              **(int **)puStack_88 = iStack_80;
            }
            else {
              **(u16 **)puStack_88 = (short)iStack_80;
            }
          }
          else {
            **(long **)puStack_88 = (long)iStack_80;
          }
          puStack_88 = puStack_88 + 1;
          goto LAB_005263c4;
        case 0x70:
          lVar7 = 0x78;
          uVar9 = (u32)(int)(u32)*puStack_88;
          pcStack_60 = s_0123456789abcdef_007bee28;
          iVar5 = 2;
          uStack_84 = uStack_84 | 2;
          goto LAB_0052735c;
        case 0x71:
          cVar10 = *param_3;
          uStack_84 = uStack_84 | 0x10;
          break;
        case 0x73:
          pcVar13 = *(char **)puStack_88;
          if (pcVar13 == (char *)0x0) {
            pcVar13 = s__null__007bee40;
          }
          if ((int)pcVar6 < 0) {
            puStack_88 = puStack_88 + 1;
            pcVar6 = (char *)FUN_00524388(pcVar13,0);
          }
          else {
            puStack_88 = puStack_88 + 1;
            lVar8 = FUN_005210d8(pcVar13,0,pcVar6);
            if ((lVar8 != 0) &&
               (pcVar14 = (char *)((int)lVar8 - (int)pcVar13), (int)pcVar14 <= (int)pcVar6)) {
              acStack_280[0] = '\0';
              pcVar6 = pcVar14;
              goto LAB_00526664;
            }
          }
          acStack_280[0] = '\0';
          goto LAB_00526664;
        case 0x78:
          pcStack_60 = s_0123456789abcdef_007bee28;
LAB_005273e4:
          if ((uStack_84 & 0x10) == 0) {
            if ((uStack_84 & 0x40) == 0) {
              uVar9 = (u32)(u32)*puStack_88;
            }
            else {
              uVar9 = (u32)(u16)*puStack_88;
            }
          }
          else {
            uVar9 = *puStack_88;
          }
          iVar5 = 2;
          if (((uStack_84 & 1) != 0) && (iVar5 = 2, uVar9 != 0)) {
            uStack_84 = uStack_84 | 2;
          }
          goto LAB_0052735c;
        }
      } while( true );
    }
LAB_005277c4:
    if (iStack_258 != 0) {
      FUN_00526140(iStack_8c,&piStack_260);
    }
LAB_005267b0:
    iVar5 = -1;
    if ((*(u16 *)(iStack_8c + 0xc) & 0x40) == 0) {
      iVar5 = iStack_80;
    }
    return iVar5;
  }
  goto LAB_005263c4;
joined_r0x00527284:
  while (9 < uVar9) {
    cVar10 = FUN_00530578(uVar9,10);
    pcVar13 = pcVar13 + -1;
    *pcVar13 = cVar10 + '0';
    uVar9 = FUN_0052fe98(uVar9,10);
  }
  pcVar13 = pcVar13 + -1;
  *pcVar13 = (char)uVar9 + '0';
LAB_00527230:
  pcVar6 = acStack_280 + -(int)pcVar13;
LAB_00527234:
  pcVar6 = pcVar6 + 0x1cc;
LAB_00526664:
  pcVar14 = pcVar6;
  if ((int)pcVar6 < (int)pcStack_64) {
    pcVar14 = pcStack_64;
  }
  if (acStack_280[0] == '\0') {
    if ((uStack_84 & 2) != 0) {
      pcVar14 = pcVar14 + 2;
    }
  }
  else {
    pcVar14 = pcVar14 + 1;
  }
  uStack_5c = uStack_84 & 0x84;
  if (uStack_5c == 0) {
    iVar5 = (int)pcStack_7c - (int)pcVar14;
    if (0 < iVar5) {
      if (0x10 < iVar5) {
        piVar4[1] = 0x10;
        while( true ) {
          *piVar4 = (int)s_0000000000000000bug_in_vfprintf__007bedb0;
          piVar4 = piVar4 + 2;
          iStack_25c = iStack_25c + 1;
          iStack_258 = iStack_258 + 0x10;
          if (7 < iStack_25c) {
            lVar8 = (int)(FUN_00526140(iStack_8c,&piStack_260));
            piVar4 = aiStack_250;
            if (lVar8 != 0) goto LAB_005267b0;
          }
          iVar5 = iVar5 + -0x10;
          if (iVar5 < 0x11) break;
          piVar4[1] = 0x10;
        }
      }
      piVar4[1] = iVar5;
      *piVar4 = (int)s_0000000000000000bug_in_vfprintf__007bedb0;
      iStack_258 = iStack_258 + iVar5;
      iStack_25c = iStack_25c + 1;
      piVar4 = piVar4 + 2;
      if (7 < iStack_25c) {
        lVar8 = (int)(FUN_00526140(iStack_8c,&piStack_260));
        if (lVar8 != 0) goto LAB_005267b0;
        piVar4 = aiStack_250;
      }
    }
  }
  if (acStack_280[0] == '\0') {
    if ((uStack_84 & 2) != 0) {
      uStack_af = (u8)lVar7;
      cStack_b0 = '0';
      piVar4[1] = 2;
      *piVar4 = (int)&cStack_b0;
      iStack_258 = iStack_258 + 2;
      iStack_25c = iStack_25c + 1;
      piVar4 = piVar4 + 2;
      if (7 < iStack_25c) {
        lVar8 = (int)(FUN_00526140(iStack_8c,&piStack_260));
        goto joined_r0x005271e0;
      }
    }
  }
  else {
    *piVar4 = (int)acStack_280;
    piVar4[1] = 1;
    piVar4 = piVar4 + 2;
    iStack_25c = iStack_25c + 1;
    iStack_258 = iStack_258 + 1;
    if (7 < iStack_25c) {
      lVar8 = (int)(FUN_00526140(iStack_8c,&piStack_260));
joined_r0x005271e0:
      piVar4 = aiStack_250;
      if (lVar8 != 0) goto LAB_005267b0;
    }
  }
  if (uStack_5c == 0x80) {
    iVar5 = (int)pcStack_7c - (int)pcVar14;
    if (0 < iVar5) {
      if (0x10 < iVar5) {
        piVar4[1] = 0x10;
        while( true ) {
          *piVar4 = (int)(s_0000000000000000bug_in_vfprintf__007bedb0 + 0x10);
          piVar4 = piVar4 + 2;
          iStack_25c = iStack_25c + 1;
          iStack_258 = iStack_258 + 0x10;
          if (7 < iStack_25c) {
            lVar8 = (int)(FUN_00526140(iStack_8c,&piStack_260));
            piVar4 = aiStack_250;
            if (lVar8 != 0) goto LAB_005267b0;
          }
          iVar5 = iVar5 + -0x10;
          if (iVar5 < 0x11) break;
          piVar4[1] = 0x10;
        }
      }
      piVar4[1] = iVar5;
      *piVar4 = (int)(s_0000000000000000bug_in_vfprintf__007bedb0 + 0x10);
      iStack_258 = iStack_258 + iVar5;
      iStack_25c = iStack_25c + 1;
      piVar4 = piVar4 + 2;
      if (7 < iStack_25c) {
        lVar8 = (int)(FUN_00526140(iStack_8c,&piStack_260));
        piVar4 = aiStack_250;
        if (lVar8 != 0) goto LAB_005267b0;
      }
    }
  }
  iVar5 = (int)pcStack_64 - (int)pcVar6;
  if (0 < iVar5) {
    if (0x10 < iVar5) {
      piVar4[1] = 0x10;
      while( true ) {
        *piVar4 = (int)(s_0000000000000000bug_in_vfprintf__007bedb0 + 0x10);
        piVar4 = piVar4 + 2;
        iStack_25c = iStack_25c + 1;
        iStack_258 = iStack_258 + 0x10;
        if (7 < iStack_25c) {
          lVar8 = (int)(FUN_00526140(iStack_8c,&piStack_260));
          piVar4 = aiStack_250;
          if (lVar8 != 0) goto LAB_005267b0;
        }
        iVar5 = iVar5 + -0x10;
        if (iVar5 < 0x11) break;
        piVar4[1] = 0x10;
      }
    }
    piVar4[1] = iVar5;
    *piVar4 = (int)(s_0000000000000000bug_in_vfprintf__007bedb0 + 0x10);
    iStack_258 = iStack_258 + iVar5;
    iStack_25c = iStack_25c + 1;
    piVar4 = piVar4 + 2;
    if (7 < iStack_25c) {
      lVar8 = (int)(FUN_00526140(iStack_8c,&piStack_260));
      piVar4 = aiStack_250;
      if (lVar8 != 0) goto LAB_005267b0;
    }
  }
  if ((uStack_84 & 0x100) == 0) {
    piVar4[1] = (int)pcVar6;
    *piVar4 = (int)pcVar13;
    piVar4 = piVar4 + 2;
    iStack_258 = iStack_258 + (int)pcVar6;
LAB_00526978:
    iStack_25c = iStack_25c + 1;
    if (iStack_25c < 8) goto LAB_005269a4;
    lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
  }
  else {
    if (0x65 < lVar7) {
      lVar7 = FUN_005316d0(uStack_70,0);
      iVar5 = iStack_94;
      pcVar6 = pcStack_98;
      if (lVar7 == 0) {
        piVar4[1] = 1;
        *piVar4 = (int)&DAT_007bedf0;
        iStack_258 = iStack_258 + 1;
        iStack_25c = iStack_25c + 1;
        piVar4 = piVar4 + 2;
        if (7 < iStack_25c) {
          lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
          piVar4 = aiStack_250;
          if (lVar7 != 0) goto LAB_005267b0;
        }
        iVar5 = iStack_78;
        if ((iStack_94 <= (int)pcStack_98) && ((uStack_84 & 1) == 0)) goto LAB_005269a4;
        piVar4[1] = 1;
        *piVar4 = iVar5;
        piVar4 = piVar4 + 2;
        iStack_25c = iStack_25c + 1;
        iStack_258 = iStack_258 + 1;
        if (7 < iStack_25c) {
          lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
          piVar4 = aiStack_250;
          if (lVar7 != 0) goto LAB_005267b0;
        }
        iVar5 = iStack_94 + -1;
        if (iVar5 < 1) goto LAB_005269a4;
        if (0x10 < iVar5) {
          piVar4[1] = 0x10;
          while( true ) {
            *piVar4 = (int)(s_0000000000000000bug_in_vfprintf__007bedb0 + 0x10);
            piVar4 = piVar4 + 2;
            iStack_25c = iStack_25c + 1;
            iStack_258 = iStack_258 + 0x10;
            if (7 < iStack_25c) {
              lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
              piVar4 = aiStack_250;
              if (lVar7 != 0) goto LAB_005267b0;
            }
            iVar5 = iVar5 + -0x10;
            if (iVar5 < 0x11) break;
            piVar4[1] = 0x10;
          }
        }
        piVar4[1] = iVar5;
        *piVar4 = (int)(s_0000000000000000bug_in_vfprintf__007bedb0 + 0x10);
        piVar4 = piVar4 + 2;
        iStack_258 = iStack_258 + iVar5;
      }
      else {
        if ((int)pcStack_98 < 1) {
          piVar4[1] = 1;
          *piVar4 = (int)&DAT_007bedf0;
          iStack_258 = iStack_258 + 1;
          iStack_25c = iStack_25c + 1;
          piVar4 = piVar4 + 2;
          if (7 < iStack_25c) {
            lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
            piVar4 = aiStack_250;
            if (lVar7 != 0) goto LAB_005267b0;
          }
          iVar5 = iStack_78;
          if ((pcStack_98 == (char *)0x0) && (iStack_94 == 0)) goto LAB_005269a4;
          piVar4[1] = 1;
          *piVar4 = iVar5;
          iStack_258 = iStack_258 + 1;
          iStack_25c = iStack_25c + 1;
          piVar4 = piVar4 + 2;
          if (7 < iStack_25c) {
            lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
            piVar4 = aiStack_250;
            if (lVar7 != 0) goto LAB_005267b0;
          }
          iVar5 = -(int)pcStack_98;
          if (0 < iVar5) {
            if (0x10 < iVar5) {
              piVar4[1] = 0x10;
              while( true ) {
                *piVar4 = (int)(s_0000000000000000bug_in_vfprintf__007bedb0 + 0x10);
                piVar4 = piVar4 + 2;
                iStack_25c = iStack_25c + 1;
                iStack_258 = iStack_258 + 0x10;
                if (7 < iStack_25c) {
                  lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
                  piVar4 = aiStack_250;
                  if (lVar7 != 0) goto LAB_005267b0;
                }
                iVar5 = iVar5 + -0x10;
                if (iVar5 < 0x11) break;
                piVar4[1] = 0x10;
              }
            }
            piVar4[1] = iVar5;
            *piVar4 = (int)(s_0000000000000000bug_in_vfprintf__007bedb0 + 0x10);
            iStack_258 = iStack_258 + iVar5;
            iStack_25c = iStack_25c + 1;
            piVar4 = piVar4 + 2;
            if (7 < iStack_25c) {
              lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
              piVar4 = aiStack_250;
              if (lVar7 != 0) goto LAB_005267b0;
            }
          }
          iVar5 = iStack_94;
          *piVar4 = (int)pcVar13;
        }
        else {
          if (iStack_94 <= (int)pcStack_98) {
            piVar4[1] = iStack_94;
            *piVar4 = (int)pcVar13;
            piVar4 = piVar4 + 2;
            iStack_25c = iStack_25c + 1;
            iStack_258 = iStack_258 + iVar5;
            if (7 < iStack_25c) {
              lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
              if (lVar7 != 0) goto LAB_005267b0;
              piVar4 = aiStack_250;
              iVar5 = iStack_94;
            }
            iVar5 = (int)pcStack_98 - iVar5;
            if (0 < iVar5) {
              if (0x10 < iVar5) {
                piVar4[1] = 0x10;
                while( true ) {
                  *piVar4 = (int)(s_0000000000000000bug_in_vfprintf__007bedb0 + 0x10);
                  piVar4 = piVar4 + 2;
                  iStack_25c = iStack_25c + 1;
                  iStack_258 = iStack_258 + 0x10;
                  if (7 < iStack_25c) {
                    lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
                    piVar4 = aiStack_250;
                    if (lVar7 != 0) goto LAB_005267b0;
                  }
                  iVar5 = iVar5 + -0x10;
                  if (iVar5 < 0x11) break;
                  piVar4[1] = 0x10;
                }
              }
              piVar4[1] = iVar5;
              *piVar4 = (int)(s_0000000000000000bug_in_vfprintf__007bedb0 + 0x10);
              iStack_258 = iStack_258 + iVar5;
              iStack_25c = iStack_25c + 1;
              piVar4 = piVar4 + 2;
              if (7 < iStack_25c) {
                lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
                piVar4 = aiStack_250;
                if (lVar7 != 0) goto LAB_005267b0;
              }
            }
            if ((uStack_84 & 1) == 0) goto LAB_005269a4;
            piVar4[1] = 1;
            *piVar4 = (int)&DAT_007bedf8;
            piVar4 = piVar4 + 2;
            iStack_258 = iStack_258 + 1;
            goto LAB_00526978;
          }
          piVar4[1] = (int)pcStack_98;
          *piVar4 = (int)pcVar13;
          piVar4 = piVar4 + 2;
          iStack_25c = iStack_25c + 1;
          iStack_258 = iStack_258 + (int)pcVar6;
          if (7 < iStack_25c) {
            lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
            if (lVar7 != 0) goto LAB_005267b0;
            piVar4 = aiStack_250;
            pcVar6 = pcStack_98;
          }
          piVar4[1] = 1;
          *piVar4 = (int)&DAT_007bedf8;
          iStack_258 = iStack_258 + 1;
          iStack_25c = iStack_25c + 1;
          piVar4 = piVar4 + 2;
          if (7 < iStack_25c) {
            lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
            piVar4 = aiStack_250;
            if (lVar7 != 0) goto LAB_005267b0;
          }
          iVar5 = iStack_94;
          pcVar3 = pcStack_98;
          *piVar4 = (int)(pcVar13 + (int)pcVar6);
          iVar5 = iVar5 - (int)pcVar3;
        }
        piVar4[1] = iVar5;
        piVar4 = piVar4 + 2;
        iStack_258 = iStack_258 + iVar5;
      }
      goto LAB_00526978;
    }
    if ((iStack_94 < 2) && ((uStack_84 & 1) == 0)) {
      *piVar4 = (int)pcVar13;
      piVar4[1] = 1;
      piVar4 = piVar4 + 2;
      iStack_25c = iStack_25c + 1;
      iStack_258 = iStack_258 + 1;
      if (7 < iStack_25c) {
        lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
joined_r0x00527038:
        piVar4 = aiStack_250;
        if (lVar7 != 0) goto LAB_005267b0;
      }
    }
    else {
      cStack_b0 = *pcVar13;
      uStack_af = 0x2e;
      piVar4[1] = 2;
      *piVar4 = (int)&cStack_b0;
      iStack_258 = iStack_258 + 2;
      iStack_25c = iStack_25c + 1;
      piVar4 = piVar4 + 2;
      if (7 < iStack_25c) {
        lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
        piVar4 = aiStack_250;
        if (lVar7 != 0) goto LAB_005267b0;
      }
      lVar7 = FUN_005316d0(uStack_70,0);
      iVar5 = iStack_94;
      if (lVar7 == 0) {
        iVar5 = iStack_94 + -1;
        if (iVar5 < 1) goto LAB_00527044;
        if (0x10 < iVar5) {
          piVar4[1] = 0x10;
          while( true ) {
            *piVar4 = (int)(s_0000000000000000bug_in_vfprintf__007bedb0 + 0x10);
            piVar4 = piVar4 + 2;
            iStack_25c = iStack_25c + 1;
            iStack_258 = iStack_258 + 0x10;
            if (7 < iStack_25c) {
              lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
              piVar4 = aiStack_250;
              if (lVar7 != 0) goto LAB_005267b0;
            }
            iVar5 = iVar5 + -0x10;
            if (iVar5 < 0x11) break;
            piVar4[1] = 0x10;
          }
        }
        piVar4[1] = iVar5;
        *piVar4 = (int)(s_0000000000000000bug_in_vfprintf__007bedb0 + 0x10);
        iStack_258 = iStack_258 + iVar5;
      }
      else {
        *piVar4 = (int)(pcVar13 + 1);
        piVar4[1] = iVar5 + -1;
        iStack_258 = iStack_258 + iVar5 + -1;
      }
      iStack_25c = iStack_25c + 1;
      piVar4 = piVar4 + 2;
      if (7 < iStack_25c) {
        lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
        goto joined_r0x00527038;
      }
    }
LAB_00527044:
    iVar5 = iStack_68;
    piVar4[1] = iStack_68;
    *piVar4 = (int)(u32)(auStack_270);
    iStack_258 = iStack_258 + iVar5;
    iStack_25c = iStack_25c + 1;
    piVar4 = piVar4 + 2;
    if (iStack_25c < 8) goto LAB_005269a4;
    lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
  }
  piVar4 = aiStack_250;
  if (lVar7 != 0) goto LAB_005267b0;
LAB_005269a4:
  if ((uStack_84 & 4) != 0) {
    iVar5 = (int)pcStack_7c - (int)pcVar14;
    if (0 < iVar5) {
      if (iVar5 < 0x11) {
        piVar4[1] = iVar5;
      }
      else {
        piVar4[1] = 0x10;
        while( true ) {
          *piVar4 = (int)s_0000000000000000bug_in_vfprintf__007bedb0;
          piVar4 = piVar4 + 2;
          iStack_25c = iStack_25c + 1;
          iStack_258 = iStack_258 + 0x10;
          if (7 < iStack_25c) {
            lVar7 = (int)(FUN_00526140(iStack_8c,&piStack_260));
            piVar4 = aiStack_250;
            if (lVar7 != 0) goto LAB_005267b0;
          }
          iVar5 = iVar5 + -0x10;
          if (iVar5 < 0x11) break;
          piVar4[1] = 0x10;
        }
        piVar4[1] = iVar5;
      }
      iStack_25c = iStack_25c + 1;
      *piVar4 = (int)s_0000000000000000bug_in_vfprintf__007bedb0;
      iStack_258 = iStack_258 + iVar5;
      if ((7 < iStack_25c) && (lVar7 = FUN_00526140(iStack_8c,&piStack_260), lVar7 != 0))
      goto LAB_005267b0;
    }
  }
  pcVar6 = pcStack_7c;
  if ((int)pcStack_7c <= (int)pcVar14) {
    pcVar6 = pcVar14;
  }
  iStack_80 = iStack_80 + (int)pcVar6;
  if ((iStack_258 != 0) && (lVar7 = FUN_00526140(iStack_8c,&piStack_260), lVar7 != 0))
  goto LAB_005267b0;
  iStack_25c = 0;
  piVar4 = aiStack_250;
  goto LAB_005263c4;
LAB_00527240:
  do {
    pcVar14 = pcVar13;
    pcVar13 = pcVar14 + -1;
    cVar10 = ((u8)uVar9 & 7) + 0x30;
    uVar9 = uVar9 >> 3;
    *pcVar13 = cVar10;
  } while (uVar9 != 0);
  if ((uStack_84 & 1) == 0) goto LAB_00527230;
  pcVar6 = acStack_280 + -(int)pcVar13;
  if (cVar10 != '0') {
    pcVar13 = pcVar14 + -2;
    *pcVar13 = '0';
    goto LAB_00527230;
  }
  goto LAB_00527234;
LAB_0052720c:
  do {
    uVar2 = (u32)uVar9;
    pcVar13 = pcVar13 + -1;
    uVar9 = uVar9 >> 4;
    *pcVar13 = pcStack_60[uVar2 & 0xf];
  } while (uVar9 != 0);
  goto LAB_00527230;
switchD_00526488_caseD_31:
  iVar5 = 0;
  while( true ) {
    iVar11 = (int)lVar7;
    cVar10 = *param_3;
    lVar7 = (long)cVar10;
    pcStack_7c = (char *)((iVar5 + iVar11) - 0x30);
    param_3 = param_3 + 1;
    if (9 < (int)cVar10 - 0x30U) break;
    iVar5 = (int)pcStack_7c * 10;
  }
  goto LAB_00526468;
}
// FUN_00527810 NONMATCHING
u64
FUN_00527810(u64 param_1,long param_2,int param_3,u32 param_4,u8 *param_5,
            u64 param_6,long param_7,int *param_8)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  u64 uVar5;
  int *piVar6;
  u8 auStack_60 [4];
  char *apcStack_5c [3];
  
  uVar5 = 3;
  if ((param_7 != 0x66) && ((param_7 == 0x65 || (uVar5 = 2, param_7 == 0x45)))) {
    param_3 = param_3 + 1;
    uVar5 = 2;
  }
  if (param_2 >> 0x20 < 0) {
    param_2 = FUN_005311c8(0,param_2);
    *param_5 = 0x2d;
  }
  else {
    *param_5 = 0;
  }
  uVar5 = FUN_0051e4b0(param_1,param_2,uVar5,param_3,param_6,auStack_60,apcStack_5c);
  pcVar4 = (char *)uVar5;
  if (((param_7 != 0x67) && (param_7 != 0x47)) || ((param_4 & 1) != 0)) {
    pcVar3 = pcVar4 + param_3;
    if (param_7 == 0x66) {
      piVar6 = (int *)param_6;
      if (*pcVar4 == '0') {
        lVar1 = FUN_005316d0(param_2,0);
        if (lVar1 != 0) {
          *piVar6 = 1 - param_3;
        }
        iVar2 = *piVar6;
      }
      else {
        iVar2 = *piVar6;
      }
      pcVar3 = pcVar3 + iVar2;
    }
    lVar1 = FUN_005316d0(param_2,0);
    if (lVar1 == 0) {
      apcStack_5c[0] = pcVar3;
    }
    for (; apcStack_5c[0] < pcVar3; apcStack_5c[0] = apcStack_5c[0] + 1) {
      *apcStack_5c[0] = '0';
    }
  }
  *param_8 = (int)apcStack_5c[0] - (int)pcVar4;
  return uVar5;
}
// FUN_005279B8 NONMATCHING
u64 FUN_005279b8(u8 *param_1, int param_2, s64 param_3)
{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char acStack_a [10];
  int iParam_2;
  
  iParam_2 = (int)(long)param_2;
  *param_1 = (u8)param_3;
  if (iParam_2 < 0) {
    iParam_2 = -iParam_2;
    param_1[1] = 0x2d;
  }
  else {
    param_1[1] = 0x2b;
  }
  pcVar2 = (char *)(param_1 + 2);
  pcVar3 = acStack_a + 2;
  if (iParam_2 < 10) {
    *pcVar2 = '0';
    param_1[3] = (char)iParam_2 + '0';
    pcVar2 = (char *)(param_1 + 4);
  }
  else {
    do {
      pcVar4 = pcVar3;
      iVar1 = iParam_2 / 10;
      pcVar3 = pcVar4 + -1;
      *pcVar3 = (char)(iParam_2 % 10) + '0';
      iParam_2 = iVar1;
    } while (9 < iVar1);
    pcVar4 = pcVar4 + -2;
    *pcVar4 = (char)iVar1 + '0';
    for (; pcVar4 < acStack_a + 2; pcVar4 = pcVar4 + 1) {
      *pcVar2 = *pcVar4;
      pcVar2 = pcVar2 + 1;
    }
  }
  return (int)pcVar2 - (int)param_1;
}
int FUN_00527b48(u32 param_1,u64 param_2,char *param_3,u32 *param_4);
#pragma optimization_level 3
#pragma tailcall off
#pragma schedule on
// FUN_00527B30 NONMATCHING
int FUN_00527b30(u32 param_1,u64 param_2,char *param_3,u32 *param_4)
{
  return FUN_00527b48(param_1,param_2,param_3,param_4);
}
#pragma tailcall on
#pragma schedule off
#pragma optimization_level 2
// FUN_00527B48 NONMATCHING
int FUN_00527b48(u32 param_1,u64 param_2,char *param_3,u32 *param_4)

{
  u16 *puVar1;
  long *plVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  u8 *pbVar8;
  long lVar9;
  char *pcVar10;
  u32 uVar11;
  u32 *puVar12;
  long lVar13;
  u8 auStack_2e0 [608];
  u32 uStack_80;
  u32 *puStack_7c;
  int iStack_78;
  code *pcStack_74;
  
  lVar13 = 0;
  pcStack_74 = (code *)0x0;
  iStack_78 = 0;
  uStack_80 = param_1;
  puStack_7c = param_4;
LAB_00527b94:
  lVar9 = (long)*param_3;
  pcVar10 = param_3;
LAB_00527b98:
  do {
    param_3 = pcVar10 + 1;
    if (lVar9 == 0) {
      return iStack_78;
    }
    puVar12 = (u32 *)param_2;
    if ((*(u8 *)((int)&PTR_DAT_007be9c8 + (int)lVar9) & 8) != 0) {
      do {
        if ((int)puVar12[1] < 1) {
          lVar9 = FUN_00523580(param_2);
          if (lVar9 != 0) goto code_r0x00527be0;
          pbVar8 = (u8 *)*puVar12;
        }
        else {
          pbVar8 = (u8 *)*puVar12;
        }
        if ((*(u8 *)((int)&PTR_DAT_007be9c8 + (u32)*pbVar8) & 8) == 0) goto LAB_00527b94;
        *puVar12 = (u32)(pbVar8 + 1);
        lVar13 = (long)((int)lVar13 + 1);
        puVar12[1] = puVar12[1] + -1;
      } while( true );
    }
    if (lVar9 == 0x25) {
      bVar6 = false;
      bVar5 = false;
      bVar4 = false;
      pcVar10 = param_3;
LAB_00527c34:
      bVar3 = false;
      param_3 = pcVar10 + 1;
      switch(*pcVar10) {
      case '\0':
        return -1;
      default:
        goto switchD_00527c58_caseD_1;
      case '%':
        goto LAB_00527c64;
      case '*':
        bVar4 = true;
        pcVar10 = param_3;
        goto LAB_00527c34;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        pcVar10 = param_3;
        goto LAB_00527c34;
      case 'D':
      case 'd':
        pcStack_74 = (code *)(FUN_00525a10);
        goto LAB_00527d38;
      case 'E':
      case 'G':
      case 'e':
      case 'f':
      case 'g':
        uVar11 = 4;
        goto LAB_00527d40;
      case 'L':
        pcVar10 = param_3;
        goto LAB_00527c34;
      case 'O':
      case 'o':
        pcStack_74 = (code *)(FUN_00525c80);
        break;
      case 'X':
      case 'x':
        goto LAB_00528774;
      case '[':
        param_3 = FUN_005287d8((int)(u32)auStack_2e0,param_3);
        bVar3 = true;
        uVar11 = 1;
        goto LAB_00527d40;
      case 'c':
        bVar3 = true;
        uVar11 = 0;
        goto LAB_00527d40;
      case 'h':
        bVar5 = true;
        pcVar10 = param_3;
        goto LAB_00527c34;
      case 'i':
        pcStack_74 = (code *)(FUN_00525a10);
        break;
      case 'l':
        goto switchD_00527c58_caseD_6c;
      case 'n':
        if (bVar4) {
          lVar9 = (long)*param_3;
          pcVar10 = param_3;
          goto LAB_00527b98;
        }
        if (bVar5) {
          puVar1 = (u16 *)*puStack_7c;
          puStack_7c = puStack_7c + 2;
          *puVar1 = (short)lVar13;
        }
        else if (bVar6) {
          plVar2 = (long *)*puStack_7c;
          puStack_7c = puStack_7c + 2;
          *plVar2 = lVar13;
        }
        else {
          puVar12 = (u32 *)*puStack_7c;
          puStack_7c = puStack_7c + 2;
          *puVar12 = (int)lVar13;
        }
        goto LAB_00527b94;
      case 'p':
LAB_00528774:
        pcStack_74 = (code *)(FUN_00525c80);
        break;
      case 's':
        uVar11 = 2;
        goto LAB_00527d40;
      case 'u':
        pcStack_74 = (code *)(FUN_00525c80);
LAB_00527d38:
        bVar3 = false;
        uVar11 = 3;
        goto LAB_00527d40;
      }
      uVar11 = 3;
      goto LAB_00527d40;
    }
LAB_00527c64:
    iVar7 = 0;
    do {
      if ((int)puVar12[1] < 1) {
        lVar9 = FUN_00523580(param_2);
        if (lVar9 != 0) goto LAB_00527cf8;
        pbVar8 = (u8 *)*puVar12;
      }
      else {
        pbVar8 = (u8 *)*puVar12;
      }
      if ((u32)*pbVar8 != (long)*pcVar10) {
        return iStack_78;
      }
      *puVar12 = (u32)(pbVar8 + 1);
      lVar13 = (long)((int)lVar13 + 1);
      pcVar10 = pcVar10 + 1;
      iVar7 = iVar7 + 1;
      puVar12[1] = puVar12[1] + -1;
    } while (iVar7 < 1);
    lVar9 = (long)*param_3;
    pcVar10 = param_3;
  } while( true );
code_r0x00527be0:
  lVar9 = (long)*param_3;
  pcVar10 = param_3;
  goto LAB_00527b98;
switchD_00527c58_caseD_6c:
  bVar6 = true;
  pcVar10 = param_3;
  goto LAB_00527c34;
switchD_00527c58_caseD_1:
  pcStack_74 = (code *)(FUN_00525a10);
  uVar11 = 3;
LAB_00527d40:
  if (((int)puVar12[1] < 1) && (lVar9 = FUN_00523580(param_2), lVar9 != 0)) {
LAB_00527cf8:
    iVar7 = -1;
    if (iStack_78 != 0) {
      iVar7 = iStack_78;
    }
    return iVar7;
  }
  if ((!bVar3) &&
     (pbVar8 = (u8 *)*puVar12, (*(u8 *)((int)&PTR_DAT_007be9c8 + (u32)*pbVar8) & 8) != 0)) {
    iVar7 = puVar12[1];
    while( true ) {
      lVar13 = (long)((int)lVar13 + 1);
      puVar12[1] = iVar7 + -1;
      if (iVar7 + -1 < 1) {
        lVar9 = FUN_00523580(param_2);
        if (lVar9 != 0) goto LAB_00527cf8;
        pbVar8 = (u8 *)*puVar12;
      }
      else {
        *puVar12 = (u32)(pbVar8 + 1);
        pbVar8 = (u8 *)*puVar12;
      }
      if ((*(u8 *)((int)&PTR_DAT_007be9c8 + (u32)*pbVar8) & 8) == 0) break;
      iVar7 = puVar12[1];
    }
  }
  if (uVar11 < 5) {
                    /* WARNING: Could not recover jumptable at 0x00527de4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar7 = (*(code *)(&PTR_LAB_007bf1c4)[uVar11])();
    return iVar7;
  }
  lVar9 = (long)*param_3;
  pcVar10 = param_3;
  goto LAB_00527b98;
}
// FUN_005287D8 NONMATCHING
char * FUN_005287d8(int param_1,char *param_2)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  
  lVar6 = (long)*param_2;
  bVar1 = lVar6 == 0x5e;
  pcVar3 = (char *)(param_2 + 1);
  if (bVar1) {
    lVar6 = (long)*pcVar3;
    pcVar3 = (char *)(param_2 + 2);
  }
  iVar7 = 0;
  iVar8 = param_1;
  do {
    *(bool *)iVar8 = bVar1;
    iVar7 = iVar7 + 1;
    iVar8 = param_1 + iVar7;
  } while (iVar7 < 0x100);
  if (lVar6 == 0) {
    return pcVar3 + -1;
  }
LAB_00528834:
  do {
    *(char *)(param_1 + (int)lVar6) = '\x01' - bVar1;
    cVar2 = *pcVar3;
    pcVar4 = pcVar3;
    while( true ) {
      lVar5 = (long)cVar2;
      pcVar3 = pcVar4 + 1;
      if (lVar5 != 0x2d) break;
      lVar5 = (long)*pcVar3;
      if ((lVar5 == 0x5d) || (lVar5 < lVar6)) {
        lVar6 = 0x2d;
        goto LAB_00528834;
      }
      pcVar4 = pcVar4 + 2;
      do {
        iVar8 = (int)lVar6 + 1;
        lVar6 = (long)iVar8;
        *(char *)(param_1 + iVar8) = '\x01' - bVar1;
      } while (lVar6 < lVar5);
      cVar2 = *pcVar4;
    }
    lVar6 = lVar5;
    if (lVar5 < 0x2e) {
      if (lVar5 == 0) {
        return pcVar4;
      }
    }
    else if (lVar5 == 0x5d) {
      return pcVar3;
    }
  } while( true );
}
// FUN_005288C8 NONMATCHING
void FUN_005288c8(u8 *param_1)
{
  u8 *apuStack_70 [2];
  u32 uStack_68;
  u16 uStack_64;
  u8 *puStack_60;
  u32 uStack_5c;
  u8 *puStack_1c;
  
  uStack_5c = 0x7fffffff;
  uStack_64 = 0x208;
  puStack_1c = PTR_DAT_00782f30;
  uStack_68 = 0x7fffffff;
  apuStack_70[0] = param_1;
  puStack_60 = param_1;
  *apuStack_70[0] = 0;
  return;
}
// FUN_00528920 NONMATCHING
void FUN_00528920(u32 param_1,u8 *param_2)

{
  u8 *apuStack_70 [2];
  u32 uStack_68;
  u16 uStack_64;
  u8 *puStack_60;
  u32 uStack_5c;
  u32 uStack_1c;
  
  uStack_5c = 0x7fffffff;
  uStack_64 = 0x208;
  uStack_68 = 0x7fffffff;
  apuStack_70[0] = param_2;
  puStack_60 = param_2;
  uStack_1c = param_1;
  FUN_005262b0(param_1,(int)(u32)(u8 **)apuStack_70,0,0);
  *apuStack_70[0] = 0;
  return;
}
// FUN_00528970 NONMATCHING
long FUN_00528970(int *param_1,u64 param_2,u64 param_3,u64 param_4)

{
  long lVar1;
  
  DAT_009acc20[0] = 0;
  lVar1 = FUN_00503728(param_2,param_3,param_4);
  if ((lVar1 == -1) && (DAT_009acc20 != 0)) {
    *param_1 = (int)(DAT_009acc20);
  }
  return lVar1;
}
// FUN_005289D0 NONMATCHING
u32 FUN_005289d0(u64 param_1)

{
  u8 *puVar1;
  int *piVar2;
  u16 uVar3;
  int iVar4;
  
  puVar1 = PTR_DAT_00782f30;
  piVar2 = (int *)param_1;
  if (piVar2[0x15] == 0) {
    piVar2[0x15] = (int)PTR_DAT_00782f30;
    iVar4 = *(int *)(puVar1 + 0x38);
  }
  else {
    iVar4 = *(int *)(piVar2[0x15] + 0x38);
  }
  if (iVar4 == 0) {
    FUN_0051fa20();
    uVar3 = *(u16 *)(piVar2 + 3);
  }
  else {
    uVar3 = *(u16 *)(piVar2 + 3);
  }
  if ((uVar3 & 8) == 0) {
    if ((uVar3 & 0x10) == 0) {
      return 0xffffffff;
    }
    if ((uVar3 & 4) == 0) {
      iVar4 = piVar2[4];
    }
    else {
      if ((int *)piVar2[0xc] != (int *)0x0) {
        if ((int *)piVar2[0xc] == piVar2 + 0x10) {
          piVar2[0xc] = 0;
        }
        else {
          FUN_0051fbb0(piVar2[0x15]);
          uVar3 = *(u16 *)(piVar2 + 3);
          piVar2[0xc] = 0;
        }
      }
      iVar4 = piVar2[4];
      uVar3 = uVar3 & 0xffdb;
      piVar2[1] = 0;
      *(u16 *)(piVar2 + 3) = uVar3;
      *piVar2 = iVar4;
    }
    *(u16 *)(piVar2 + 3) = uVar3 | 8;
  }
  else {
    iVar4 = piVar2[4];
  }
  if (iVar4 == 0) {
    FUN_005205d8(param_1);
    uVar3 = *(u16 *)(piVar2 + 3);
  }
  else {
    uVar3 = *(u16 *)(piVar2 + 3);
  }
  if ((uVar3 & 1) == 0) {
    iVar4 = 0;
    if ((uVar3 & 2) == 0) {
      iVar4 = piVar2[5];
    }
    piVar2[2] = iVar4;
  }
  else {
    piVar2[2] = 0;
    piVar2[6] = -piVar2[5];
  }
  return 0;
}
// FUN_00528AE0 NONMATCHING
u64 FUN_00528ae0(long param_1)

{
  u64 uVar1;
  u64 uVar2;
  u64 uVar3;
  u64 uVar4;
  u32 uVar5;
  u32 uVar6;
  
  uVar5 = param_1 >> 0x20;
  uVar6 = uVar5 & 0x7fffffff;
  if (uVar6 < 0x3ff00000) {
    if (uVar6 < 0x3fe00000) {
      if (uVar6 < 0x3c600001) {
        return DAT_007bf478;
      }
      uVar1 = FUN_00531230(param_1,param_1);
      uVar2 = FUN_00531230(uVar1,DAT_007bf480);
      uVar2 = FUN_00531170(uVar2,DAT_007bf488);
      uVar2 = FUN_00531230(uVar1,uVar2);
      uVar2 = FUN_00531170(uVar2,DAT_007bf490);
      uVar2 = FUN_00531230(uVar1,uVar2);
      uVar2 = FUN_00531170(uVar2,DAT_007bf498);
      uVar2 = FUN_00531230(uVar1,uVar2);
      uVar2 = FUN_00531170(uVar2,DAT_007bf4a0);
      uVar2 = FUN_00531230(uVar1,uVar2);
      uVar2 = FUN_00531170(uVar2,DAT_007bf4a8);
      uVar2 = FUN_00531230(uVar1,uVar2);
      uVar3 = FUN_00531230(uVar1,DAT_007bf4b0);
      uVar3 = FUN_00531170(uVar3,DAT_007bf4b8);
      uVar3 = FUN_00531230(uVar1,uVar3);
      uVar3 = FUN_00531170(uVar3,DAT_007bf4c0);
      uVar3 = FUN_00531230(uVar1,uVar3);
      uVar3 = FUN_00531170(uVar3,_PTR_DAT_007bf4c8);
      uVar1 = FUN_00531230(uVar1,uVar3);
      uVar1 = FUN_00531170(uVar1,0x3ff0000000000000);
      uVar1 = FUN_00531480(uVar2,uVar1);
      uVar1 = FUN_00531230(param_1,uVar1);
      uVar1 = FUN_005311c8(DAT_007bf4d0,uVar1);
      uVar2 = FUN_005311c8(param_1,uVar1);
      uVar1 = DAT_007bf478;
    }
    else {
      if (-1 < (long)uVar5) {
        uVar1 = FUN_005311c8(0x3ff0000000000000,param_1);
        uVar1 = FUN_00531230(uVar1,0x3fe0000000000000);
        uVar5 = FUN_0052a8c8(uVar1);
        uVar6 = uVar5 & 0xffffffff00000000;
        uVar2 = FUN_00531230(uVar6,uVar6);
        uVar2 = FUN_005311c8(uVar1,uVar2);
        uVar3 = FUN_00531170(uVar5,uVar6);
        uVar2 = FUN_00531480(uVar2,uVar3);
        uVar3 = FUN_00531230(uVar1,DAT_007bf480);
        uVar3 = FUN_00531170(uVar3,DAT_007bf488);
        uVar3 = FUN_00531230(uVar1,uVar3);
        uVar3 = FUN_00531170(uVar3,DAT_007bf490);
        uVar3 = FUN_00531230(uVar1,uVar3);
        uVar3 = FUN_00531170(uVar3,DAT_007bf498);
        uVar3 = FUN_00531230(uVar1,uVar3);
        uVar3 = FUN_00531170(uVar3,DAT_007bf4a0);
        uVar3 = FUN_00531230(uVar1,uVar3);
        uVar3 = FUN_00531170(uVar3,DAT_007bf4a8);
        uVar3 = FUN_00531230(uVar1,uVar3);
        uVar4 = FUN_00531230(uVar1,DAT_007bf4b0);
        uVar4 = FUN_00531170(uVar4,DAT_007bf4b8);
        uVar4 = FUN_00531230(uVar1,uVar4);
        uVar4 = FUN_00531170(uVar4,DAT_007bf4c0);
        uVar4 = FUN_00531230(uVar1,uVar4);
        uVar4 = FUN_00531170(uVar4,_PTR_DAT_007bf4c8);
        uVar1 = FUN_00531230(uVar1,uVar4);
        uVar1 = FUN_00531170(uVar1,0x3ff0000000000000);
        uVar1 = FUN_00531480(uVar3,uVar1);
        uVar1 = FUN_00531230(uVar1,uVar5);
        uVar1 = FUN_00531170(uVar1,uVar2);
        uVar1 = FUN_00531170(uVar6,uVar1);
        uVar1 = FUN_00531170(uVar1,uVar1);
        return uVar1;
      }
      uVar1 = FUN_00531170(param_1,0x3ff0000000000000);
      uVar1 = FUN_00531230(uVar1,0x3fe0000000000000);
      uVar2 = FUN_00531230(uVar1,DAT_007bf480);
      uVar2 = FUN_00531170(uVar2,DAT_007bf488);
      uVar2 = FUN_00531230(uVar1,uVar2);
      uVar2 = FUN_00531170(uVar2,DAT_007bf490);
      uVar2 = FUN_00531230(uVar1,uVar2);
      uVar2 = FUN_00531170(uVar2,DAT_007bf498);
      uVar2 = FUN_00531230(uVar1,uVar2);
      uVar2 = FUN_00531170(uVar2,DAT_007bf4a0);
      uVar2 = FUN_00531230(uVar1,uVar2);
      uVar2 = FUN_00531170(uVar2,DAT_007bf4a8);
      uVar2 = FUN_00531230(uVar1,uVar2);
      uVar3 = FUN_00531230(uVar1,DAT_007bf4b0);
      uVar3 = FUN_00531170(uVar3,DAT_007bf4b8);
      uVar3 = FUN_00531230(uVar1,uVar3);
      uVar3 = FUN_00531170(uVar3,DAT_007bf4c0);
      uVar3 = FUN_00531230(uVar1,uVar3);
      uVar3 = FUN_00531170(uVar3,_PTR_DAT_007bf4c8);
      uVar3 = FUN_00531230(uVar1,uVar3);
      uVar3 = FUN_00531170(uVar3,0x3ff0000000000000);
      uVar1 = FUN_0052a8c8(uVar1);
      uVar2 = FUN_00531480(uVar2,uVar3);
      uVar2 = FUN_00531230(uVar2,uVar1);
      uVar2 = FUN_005311c8(uVar2,DAT_007bf4d0);
      uVar1 = FUN_00531170(uVar1,uVar2);
      uVar2 = FUN_00531170(uVar1,uVar1);
      uVar1 = DAT_007bf470;
    }
    uVar1 = FUN_005311c8(uVar1,uVar2);
  }
  else if ((int)uVar6 == 0x3ff00000 && (int)param_1 == 0) {
    uVar1 = 0;
    if ((long)uVar5 < 1) {
      uVar1 = DAT_007bf470;
    }
  }
  else {
    uVar1 = FUN_005311c8(param_1,param_1);
    uVar2 = FUN_005311c8(param_1,param_1);
    uVar1 = FUN_00531480(uVar1,uVar2);
  }
  return uVar1;
}
// FUN_005290A0 NONMATCHING
u64 FUN_005290a0(u32 param_1)

{
  u64 uVar1;
  long lVar2;
  u64 uVar3;
  u64 uVar4;
  u64 uVar5;
  u64 uVar6;
  u64 uVar7;
  u64 uVar8;
  int iVar9;
  u32 uVar10;
  u32 uVar11;
  int iVar12;
  
  uVar10 = (long)param_1 >> 0x20;
  iVar12 = 0;
  if ((long)uVar10 < 0x100000) {
    if ((uVar10 & 0x7fffffff) == 0 && (int)param_1 == 0) {
      return DAT_007bf530;
    }
    if ((long)uVar10 < 0) {
      uVar1 = FUN_005311c8(param_1,param_1);
      uVar1 = FUN_00531480(uVar1,0);
      return uVar1;
    }
    iVar12 = -0x36;
    param_1 = FUN_00531230(param_1,0x4350000000000000);
    uVar10 = (long)param_1 >> 0x20;
  }
  uVar11 = param_1;
  if (0x7fefffff < (long)uVar10) {
LAB_00529180:
    uVar1 = FUN_00531170(param_1,uVar11);
    return uVar1;
  }
  iVar9 = (int)(uVar10 & 0xfffff);
  uVar11 = (long)(iVar9 + 0x95f64) & 0x100000;
  iVar12 = iVar12 + ((int)uVar10 >> 0x14) + -0x3ff + ((int)uVar11 >> 0x14);
  uVar1 = FUN_005311c8(param_1 & 0xffffffff | (uVar10 & 0xfffff | uVar11 ^ 0x3ff00000) << 0x20,
                       0x3ff0000000000000);
  if ((iVar9 + 2U & 0xfffff) < 3) {
    lVar2 = FUN_005316d0(uVar1,0);
    if (lVar2 != 0) {
      uVar3 = FUN_00531230(uVar1,uVar1);
      uVar4 = FUN_00531230(uVar1,DAT_007bf548);
      uVar4 = FUN_005311c8(0x3fe0000000000000,uVar4);
      uVar3 = FUN_00531230(uVar3,uVar4);
      if (iVar12 != 0) {
        uVar4 = FUN_00531720(iVar12);
        uVar5 = FUN_00531230(uVar4,DAT_007bf538);
        uVar4 = FUN_00531230(uVar4,DAT_007bf540);
        uVar3 = FUN_005311c8(uVar3,uVar4);
        uVar3 = FUN_005311c8(uVar3,uVar1);
        uVar1 = uVar5;
      }
      goto LAB_005292b0;
    }
    if (iVar12 == 0) {
      return 0;
    }
    uVar1 = FUN_00531720(iVar12);
    param_1 = FUN_00531230(uVar1,DAT_007bf538);
    uVar11 = FUN_00531230(uVar1,DAT_007bf540);
    goto LAB_00529180;
  }
  uVar3 = FUN_00531170(uVar1,0x4000000000000000);
  uVar3 = FUN_00531480(uVar1,uVar3);
  uVar4 = FUN_00531720(iVar12);
  uVar5 = FUN_00531230(uVar3,uVar3);
  uVar6 = FUN_00531230(uVar5,uVar5);
  uVar7 = FUN_00531230(uVar6,DAT_007bf550);
  uVar7 = FUN_00531170(uVar7,_PTR_DAT_007bf558);
  uVar7 = FUN_00531230(uVar6,uVar7);
  uVar7 = FUN_00531170(uVar7,DAT_007bf560);
  uVar7 = FUN_00531230(uVar6,uVar7);
  uVar8 = FUN_00531230(uVar6,DAT_007bf568);
  uVar8 = FUN_00531170(uVar8,DAT_007bf570);
  uVar8 = FUN_00531230(uVar6,uVar8);
  uVar8 = FUN_00531170(uVar8,DAT_007bf578);
  uVar6 = FUN_00531230(uVar6,uVar8);
  uVar6 = FUN_00531170(uVar6,DAT_007bf580);
  uVar5 = FUN_00531230(uVar5,uVar6);
  uVar5 = FUN_00531170(uVar5,uVar7);
  if ((int)(iVar9 - 0x6147aU | 0x6b851U - iVar9) < 1) {
    if (iVar12 == 0) {
      uVar4 = FUN_005311c8(uVar1,uVar5);
      uVar3 = FUN_00531230(uVar3,uVar4);
      goto LAB_005292b0;
    }
    uVar7 = FUN_00531230(uVar4,DAT_007bf538);
    uVar5 = FUN_005311c8(uVar1,uVar5);
    uVar6 = FUN_00531230(uVar3,uVar5);
    uVar3 = FUN_00531230(uVar4,DAT_007bf540);
  }
  else {
    uVar6 = FUN_00531230(uVar1,0x3fe0000000000000);
    uVar6 = FUN_00531230(uVar6,uVar1);
    if (iVar12 == 0) {
      uVar4 = FUN_00531170(uVar6,uVar5);
      uVar3 = FUN_00531230(uVar3,uVar4);
      uVar3 = FUN_005311c8(uVar6,uVar3);
      goto LAB_005292b0;
    }
    uVar7 = FUN_00531230(uVar4,DAT_007bf538);
    uVar5 = FUN_00531170(uVar6,uVar5);
    uVar3 = FUN_00531230(uVar3,uVar5);
    uVar4 = FUN_00531230(uVar4,DAT_007bf540);
    uVar3 = FUN_00531170(uVar3,uVar4);
  }
  uVar3 = FUN_005311c8(uVar6,uVar3);
  uVar3 = FUN_005311c8(uVar3,uVar1);
  uVar1 = uVar7;
LAB_005292b0:
  uVar1 = FUN_005311c8(uVar1,uVar3);
  return uVar1;
}
// FUN_00529578 NONMATCHING
u64 FUN_00529578(u32 param_1)

{
  u64 uVar1;
  u64 uVar2;
  u64 uVar3;
  u32 uVar4;
  u32 uVar5;
  int iVar6;
  int iVar7;
  
  uVar5 = (long)param_1 >> 0x20;
  iVar6 = 0;
  if ((long)uVar5 < 0x100000) {
    if ((uVar5 & 0x7fffffff) == 0 && (int)param_1 == 0) {
      return DAT_007bf5b0;
    }
    if ((long)uVar5 < 0) {
      uVar1 = FUN_005311c8(param_1,param_1);
      uVar1 = FUN_00531480(uVar1,0);
      return uVar1;
    }
    iVar6 = -0x36;
    param_1 = FUN_00531230(param_1,0x4350000000000000);
    uVar5 = (long)param_1 >> 0x20;
  }
  uVar4 = param_1;
  if ((long)uVar5 < 0x7ff00000) {
    iVar7 = iVar6 + ((int)uVar5 >> 0x14) + -0x3ff;
    iVar6 = iVar7 >> 0x1f;
    uVar1 = FUN_00531720(iVar7 - iVar6);
    uVar2 = FUN_00531230(uVar1,DAT_007bf5b8);
    uVar3 = FUN_005290a0(param_1 & 0xffffffff |
                         (uVar5 & 0xfffff | (u32)(u32)((iVar6 + 0x3ff) * 0x100000)) << 0x20);
    uVar3 = FUN_00531230(uVar3,DAT_007bf5c0);
    param_1 = FUN_00531170(uVar2,uVar3);
    uVar4 = FUN_00531230(uVar1,DAT_007bf5c8);
  }
  uVar1 = FUN_00531170(param_1,uVar4);
  return uVar1;
}
// FUN_005296F0 NONMATCHING
u32 FUN_005296f0(u32 param_1,u32 param_2)

{
  u32 uVar1;
  u64 uVar2;
  u64 uVar3;
  u64 uVar4;
  long lVar5;
  u64 uVar6;
  u32 uVar7;
  u32 uVar8;
  int iVar9;
  u32 uVar10;
  u64 uVar11;
  u32 uVar12;
  u32 uVar13;
  u32 uVar14;
  int iVar15;
  u32 uStack_80;
  int iStack_68;
  int iStack_64;
  int iStack_60;
  
  uVar7 = (u32)param_2;
  uVar12 = (long)param_2 >> 0x20;
  uVar10 = uVar12 & 0x7fffffff;
  uVar13 = (long)param_1 >> 0x20;
  iVar15 = (int)param_1;
  uVar14 = uVar13 & 0x7fffffff;
  if (uVar10 == 0 && uVar7 == 0) {
    return 0x3ff0000000000000;
  }
  if (((0x7ff00000 < uVar14) || (((uVar14 == 0x7ff00000 && (iVar15 != 0)) || (0x7ff00000 < uVar10)))
      ) || ((uVar10 == 0x7ff00000 && (uVar7 != 0)))) {
    uVar10 = FUN_00531170(param_1,param_2);
    return uVar10;
  }
  iStack_64 = 0;
  if ((long)uVar13 < 0) {
    if (0x433fffff < uVar10) {
      iStack_64 = 2;
      goto LAB_005297f0;
    }
    if (uVar10 < 0x3ff00000) goto LAB_005297f0;
    iVar9 = ((int)uVar10 >> 0x14) + -0x3ff;
    if (0x14 < iVar9) {
      uVar8 = uVar7 >> (0x34U - iVar9 & 0x1f);
      if (uVar8 << (0x34U - iVar9 & 0x1f) == uVar7) {
LAB_0052a3bc:
        iStack_64 = 2 - (uVar8 & 1);
      }
      goto LAB_005297f0;
    }
    if (uVar7 == 0) {
      uVar8 = (int)uVar10 >> (0x14U - iVar9 & 0x1f);
      if ((long)(int)(uVar8 << (0x14U - iVar9 & 0x1f)) == uVar10) goto LAB_0052a3bc;
      goto LAB_005297f0;
    }
  }
  else {
LAB_005297f0:
    if (uVar7 == 0) {
      if (uVar10 == 0x7ff00000) {
        uVar10 = param_2;
        if ((int)uVar14 != 0x3ff00000 || iVar15 != 0) {
          if (0x3fefffff < uVar14) {
            if ((long)uVar12 < 0) {
              return 0;
            }
            return param_2;
          }
          if (-1 < (long)uVar12) {
            return 0;
          }
          uVar10 = 0;
        }
        uVar10 = FUN_005311c8(uVar10,param_2);
        return uVar10;
      }
      if (uVar10 == 0x3ff00000) {
        if (-1 < (long)uVar12) {
          return param_1;
        }
        uVar10 = 0x3ff0000000000000;
        goto LAB_0052987c;
      }
      uVar1 = param_1;
      if (uVar12 == 0x40000000) goto LAB_005298a4;
      if ((uVar12 == 0x3fe00000) && (-1 < (long)uVar13)) {
        uVar10 = FUN_0052a8c8(param_1);
        return uVar10;
      }
    }
  }
  uVar1 = FUN_0052e118(param_1);
  if ((iVar15 == 0) && (((uVar14 == 0x7ff00000 || (uVar14 == 0)) || (uVar14 == 0x3ff00000)))) {
    if ((long)uVar12 < 0) {
      uVar1 = FUN_00531480(0x3ff0000000000000,uVar1);
    }
    if (-1 < (long)uVar13) {
      return uVar1;
    }
    if ((int)uVar14 == 0x3ff00000 && iStack_64 == 0) {
      uVar2 = FUN_005311c8(uVar1,uVar1);
      uVar10 = FUN_00531480(uVar2,uVar2);
      return uVar10;
    }
    if (iStack_64 == 1) {
      uVar10 = FUN_005311c8(0,uVar1);
      return uVar10;
    }
    return uVar1;
  }
  if ((long)param_1 < 0 && iStack_64 == 0) {
    uVar10 = FUN_005311c8(param_1,param_1);
    param_1 = uVar10;
LAB_0052987c:
    uVar10 = FUN_00531480(uVar10,param_1);
    return uVar10;
  }
  if (uVar10 < 0x41e00001) {
    iStack_60 = 0;
    if (uVar14 < 0x100000) {
      iStack_60 = -0x35;
      uVar1 = FUN_00531230(uVar1,0x4340000000000000);
      uVar14 = (long)uVar1 >> 0x20;
    }
    iStack_68 = 0;
    iVar15 = iStack_60 + ((int)uVar14 >> 0x14);
    uVar14 = uVar14 & 0xfffff;
    iStack_60 = iVar15 + -0x3ff;
    uVar10 = uVar14 | 0x3ff00000;
    if ((0x3988e < uVar14) && (iStack_68 = 1, 0xbb679 < uVar14)) {
      iStack_60 = iVar15 + -0x3fe;
      iStack_68 = 0;
      uVar10 = (u32)((int)uVar10 + -0x100000);
    }
    iVar15 = iStack_68 * 8;
    uVar13 = uVar1 & 0xffffffff | uVar10 << 0x20;
    uVar4 = *(u64 *)(&DAT_007bf5d0 + iVar15);
    uVar2 = FUN_005311c8(uVar13,uVar4);
    uVar3 = FUN_00531170(uVar13,uVar4);
    uVar3 = FUN_00531480(0x3ff0000000000000,uVar3);
    uVar12 = FUN_00531230(uVar2,uVar3);
    uVar14 = uVar12 & 0xffffffff00000000;
    lVar5 = (long)(int)(((int)uVar10 >> 1 | 0x20000000U) + iStack_68 * 0x40000 + 0x80000) << 0x20;
    uVar4 = FUN_005311c8(lVar5,uVar4);
    uVar4 = FUN_005311c8(uVar13,uVar4);
    uVar6 = FUN_00531230(uVar14,lVar5);
    uVar2 = FUN_005311c8(uVar2,uVar6);
    uVar4 = FUN_00531230(uVar14,uVar4);
    uVar2 = FUN_005311c8(uVar2,uVar4);
    uVar2 = FUN_00531230(uVar3,uVar2);
    uVar3 = FUN_00531230(uVar12,uVar12);
    uVar4 = FUN_00531230(uVar3,uVar3);
    uVar6 = FUN_00531230(uVar3,DAT_007bf700);
    uVar6 = FUN_00531170(uVar6,DAT_007bf708);
    uVar6 = FUN_00531230(uVar3,uVar6);
    uVar6 = FUN_00531170(uVar6,DAT_007bf710);
    uVar6 = FUN_00531230(uVar3,uVar6);
    uVar6 = FUN_00531170(uVar6,DAT_007bf718);
    uVar6 = FUN_00531230(uVar3,uVar6);
    uVar6 = FUN_00531170(uVar6,DAT_007bf720);
    uVar3 = FUN_00531230(uVar3,uVar6);
    uVar3 = FUN_00531170(uVar3,DAT_007bf728);
    uVar3 = FUN_00531230(uVar4,uVar3);
    uVar4 = FUN_00531170(uVar14,uVar12);
    uVar4 = FUN_00531230(uVar2,uVar4);
    uVar3 = FUN_00531170(uVar3,uVar4);
    uVar4 = FUN_00531230(uVar14,uVar14);
    uVar6 = FUN_00531170(uVar4,0x4008000000000000);
    uVar10 = FUN_00531170(uVar6,uVar3);
    uVar10 = uVar10 & 0xffffffff00000000;
    uVar6 = FUN_005311c8(uVar10,0x4008000000000000);
    uVar4 = FUN_005311c8(uVar6,uVar4);
    uVar3 = FUN_005311c8(uVar3,uVar4);
    uVar4 = FUN_00531230(uVar14,uVar10);
    uVar2 = FUN_00531230(uVar2,uVar10);
    uVar3 = FUN_00531230(uVar3,uVar12);
    uVar2 = FUN_00531170(uVar2,uVar3);
    uVar10 = FUN_00531170(uVar4,uVar2);
    uVar10 = uVar10 & 0xffffffff00000000;
    uVar3 = FUN_005311c8(uVar10,uVar4);
    uVar2 = FUN_005311c8(uVar2,uVar3);
    uVar3 = FUN_00531230(uVar10,DAT_007bf730);
    uVar4 = FUN_00531230(uVar10,DAT_007bf738);
    uVar2 = FUN_00531230(uVar2,DAT_007bf740);
    uVar2 = FUN_00531170(uVar4,uVar2);
    uVar2 = FUN_00531170(uVar2,*(u64 *)(iVar15 + 0x7bf5f0));
    uVar4 = FUN_00531720(iStack_60);
    uVar6 = FUN_00531170(uVar3,uVar2);
    uVar11 = *(u64 *)(&DAT_007bf5e0 + iVar15);
    uVar6 = FUN_00531170(uVar6,uVar11);
    uVar10 = FUN_00531170(uVar6,uVar4);
    uVar10 = uVar10 & 0xffffffff00000000;
    uVar4 = FUN_005311c8(uVar10,uVar4);
    uVar4 = FUN_005311c8(uVar4,uVar11);
    uVar3 = FUN_005311c8(uVar4,uVar3);
  }
  else {
    if (0x43f00000 < uVar10) {
      if (0x3fefffff < uVar14) {
        if ((long)uVar12 < 1) {
          return 0;
        }
        return DAT_007bf6d8;
      }
LAB_00529a10:
      if (-1 < (long)uVar12) {
        return 0;
      }
      return DAT_007bf6d8;
    }
    if (uVar14 < 0x3fefffff) goto LAB_00529a10;
    if (0x3ff00000 < uVar14) {
      if ((long)uVar12 < 1) {
        return 0;
      }
      return DAT_007bf6d8;
    }
    uVar2 = FUN_005311c8(param_1,0x3ff0000000000000);
    uVar3 = FUN_00531230(uVar2,uVar2);
    uVar4 = FUN_00531230(uVar2,0x3fd0000000000000);
    uVar4 = FUN_005311c8(DAT_007bf6e0,uVar4);
    uVar4 = FUN_00531230(uVar2,uVar4);
    uVar4 = FUN_005311c8(0x3fe0000000000000,uVar4);
    uVar3 = FUN_00531230(uVar3,uVar4);
    uVar4 = FUN_00531230(uVar2,DAT_007bf6e8);
    uVar2 = FUN_00531230(uVar2,DAT_007bf6f0);
    uVar3 = FUN_00531230(uVar3,DAT_007bf6f8);
    uVar2 = FUN_005311c8(uVar2,uVar3);
    uVar10 = FUN_00531170(uVar4,uVar2);
    uVar10 = uVar10 & 0xffffffff00000000;
    uVar3 = FUN_005311c8(uVar10,uVar4);
  }
  uVar2 = FUN_005311c8(uVar2,uVar3);
  uStack_80 = 0x3ff0000000000000;
  if ((long)param_1 < 0 && iStack_64 == 1) {
    uStack_80 = 0xbff0000000000000;
  }
  uVar3 = FUN_005311c8(param_2,param_2 & 0xffffffff00000000);
  uVar3 = FUN_00531230(uVar3,uVar10);
  uVar2 = FUN_00531230(param_2,uVar2);
  uVar2 = FUN_00531170(uVar3,uVar2);
  uVar3 = FUN_00531230(param_2 & 0xffffffff00000000,uVar10);
  lVar5 = FUN_00531170(uVar2,uVar3);
  uVar10 = lVar5 >> 0x20;
  iVar15 = (int)((u32)lVar5 >> 0x20);
  if ((long)uVar10 < 0x40900000) {
    if ((uVar10 & 0x7fffffff) < 0x4090cc00) {
LAB_00529c58:
      iStack_60 = 0;
      if (0x3fe00000 < (uVar10 & 0x7fffffff)) {
        uVar7 = iVar15 + (0x100000 >> (((int)(uVar10 & 0x7fffffff) >> 0x14) - 0x3feU & 0x1f));
        uVar8 = ((int)(uVar7 & 0x7fffffff) >> 0x14) - 0x3ff;
        iStack_60 = (int)(uVar7 & 0xfffff | 0x100000) >> (0x14 - uVar8 & 0x1f);
        if ((long)uVar10 < 0) {
          iStack_60 = -iStack_60;
        }
        uVar3 = FUN_005311c8(uVar3,((long)(int)uVar7 & ~(long)(0xfffff >> (uVar8 & 0x1f))) << 0x20);
      }
      uVar10 = FUN_00531170(uVar2,uVar3);
      uVar10 = uVar10 & 0xffffffff00000000;
      uVar4 = FUN_00531230(uVar10,0x3fe62e4300000000);
      uVar3 = FUN_005311c8(uVar10,uVar3);
      uVar2 = FUN_005311c8(uVar2,uVar3);
      uVar2 = FUN_00531230(uVar2,DAT_007bf760);
      uVar3 = FUN_00531230(uVar10,DAT_007bf768);
      uVar2 = FUN_00531170(uVar2,uVar3);
      uVar3 = FUN_00531170(uVar4,uVar2);
      uVar4 = FUN_005311c8(uVar3,uVar4);
      uVar2 = FUN_005311c8(uVar2,uVar4);
      uVar4 = FUN_00531230(uVar3,uVar3);
      uVar6 = FUN_00531230(uVar4,DAT_007bf770);
      uVar6 = FUN_00531170(uVar6,DAT_007bf778);
      uVar6 = FUN_00531230(uVar4,uVar6);
      uVar6 = FUN_00531170(uVar6,DAT_007bf780);
      uVar6 = FUN_00531230(uVar4,uVar6);
      uVar6 = FUN_00531170(uVar6,DAT_007bf788);
      uVar6 = FUN_00531230(uVar4,uVar6);
      uVar6 = FUN_00531170(uVar6,DAT_007bf790);
      uVar4 = FUN_00531230(uVar4,uVar6);
      uVar4 = FUN_005311c8(uVar3,uVar4);
      uVar6 = FUN_00531230(uVar3,uVar4);
      uVar4 = FUN_005311c8(uVar4,0x4000000000000000);
      uVar4 = FUN_00531480(uVar6,uVar4);
      uVar6 = FUN_00531230(uVar3,uVar2);
      uVar2 = FUN_00531170(uVar2,uVar6);
      uVar2 = FUN_005311c8(uVar4,uVar2);
      uVar2 = FUN_005311c8(uVar2,uVar3);
      uVar10 = FUN_005311c8(0x3ff0000000000000,uVar2);
      uVar7 = (int)(uVar10 >> 0x20) + iStack_60 * 0x100000;
      param_1 = uStack_80;
      if ((int)uVar7 >> 0x14 < 1) {
        uVar1 = FUN_005237b0(uVar10,iStack_60);
      }
      else {
        uVar1 = uVar10 & 0xffffffff | (u32)uVar7 << 0x20;
      }
      goto LAB_005298a4;
    }
    uVar1 = DAT_007bf758;
    if (iVar15 == -0x3f6f3400 && (int)lVar5 == 0) {
      uVar4 = FUN_005311c8(lVar5,uVar3);
      lVar5 = FUN_005316d0(uVar2,uVar4);
      uVar1 = DAT_007bf758;
      if (0 < lVar5) goto LAB_00529c58;
    }
  }
  else {
    uVar1 = DAT_007bf748;
    if (iVar15 == 0x40900000 && (int)lVar5 == 0) {
      uVar4 = FUN_00531170(uVar2,DAT_007bf750);
      uVar6 = FUN_005311c8(lVar5,uVar3);
      lVar5 = FUN_005316d0(uVar6,uVar4);
      uVar1 = DAT_007bf748;
      if (-1 < lVar5) goto LAB_00529c58;
    }
  }
  param_1 = FUN_00531230(uStack_80,uVar1);
LAB_005298a4:
  uVar10 = FUN_00531230(param_1,uVar1);
  return uVar10;
}
// FUN_0052A3F0 NONMATCHING
int FUN_0052a3f0(long param_1, long *param_2)
{
  int iVar1;
  u64 uVar2;
  u64 uVar3;
  u64 uVar4;
  u64 uVar5;
  u64 uVar6;
  long lVar7;
  int iVar8;
  u32 *puVar9;
  u32 uVar10;
  u32 *puVar11;
  u64 *puVar12;
  u32 uVar13;
  u32 uVar14;
  u64 auStack_80 [2];
  u32 auStack_70 [4];
  
  puVar12 = auStack_80;
  uVar14 = param_1 >> 0x20;
  uVar10 = uVar14 & 0x7fffffff;
  puVar11 = (u32 *)param_2;
  if (uVar10 < 0x3fe921fc) {
    *puVar11 = (u32)param_1;
    puVar11[1] = 0;
    return 0;
  }
  if (uVar10 < 0x4002d97c) {
    if (0 < (long)uVar14) {
      uVar2 = FUN_005311c8(param_1,DAT_007bf970);
      uVar3 = DAT_007bf978;
      if (uVar10 == 0x3ff921fb) {
        uVar2 = FUN_005311c8(uVar2,DAT_007bf980);
        uVar3 = DAT_007bf988;
      }
      uVar10 = FUN_005311c8(uVar2,uVar3);
      *puVar11 = uVar10;
      uVar2 = FUN_005311c8(uVar2,uVar10);
      uVar10 = FUN_005311c8(uVar2,uVar3);
      puVar11[1] = uVar10;
      return 1;
    }
    uVar2 = FUN_00531170(param_1,DAT_007bf970);
    uVar3 = DAT_007bf978;
    if (uVar10 == 0x3ff921fb) {
      uVar2 = FUN_00531170(uVar2,DAT_007bf980);
      uVar3 = DAT_007bf988;
    }
    uVar10 = FUN_00531170(uVar2,uVar3);
    *puVar11 = uVar10;
    uVar2 = FUN_005311c8(uVar2,uVar10);
    uVar10 = FUN_00531170(uVar2,uVar3);
    puVar11[1] = uVar10;
    return -1;
  }
  iVar8 = (int)uVar10 >> 0x14;
  if (0x413921fb < uVar10) {
    if (0x7fefffff < uVar10) {
      uVar10 = FUN_005311c8(param_1,param_1);
      *puVar11 = uVar10;
      puVar11[1] = uVar10;
      return 0;
    }
    uVar10 = (u32)(param_1 & 0xffffffff | (long)((int)uVar10 + (iVar8 + -0x416) * -0x100000) << 0x20);
    iVar1 = 1;
    do {
      iVar1 = iVar1 + -1;
      uVar3 = FUN_005317d0(uVar10);
      uVar3 = FUN_00531720(uVar3);
      *puVar12 = uVar3;
      uVar3 = FUN_005311c8(uVar10,uVar3);
      puVar12 = puVar12 + 1;
      uVar10 = FUN_00531230(uVar3,0x4170000000000000);
    } while (-1 < iVar1);
    auStack_70[0] = uVar10;
    iVar1 = 3;
    puVar9 = auStack_70;
    while( true ) {
      uVar10 = *puVar9;
      puVar9 = puVar9 + -1;
      lVar7 = FUN_005316d0(uVar10,0);
      if (lVar7 != 0) break;
      iVar1 = iVar1 + -1;
    }
    iVar1 = FUN_0052c6d0(auStack_80,(u64 *)param_2,iVar8 + -0x416,iVar1,2,0x7bf798);
    if (-1 < (long)uVar14) {
      return iVar1;
    }
    uVar14 = FUN_005311c8(0,*puVar11);
    uVar10 = puVar11[1];
    *puVar11 = uVar14;
    goto LAB_0052a7a4;
  }
  uVar3 = FUN_0052e118(0);
  uVar2 = FUN_00531230(uVar3,DAT_007bf990);
  uVar2 = FUN_00531170(uVar2,0x3fe0000000000000);
  iVar1 = FUN_005317d0(uVar2);
  uVar2 = FUN_00531720(iVar1);
  uVar4 = FUN_00531230(uVar2,DAT_007bf970);
  uVar3 = FUN_005311c8(uVar3,uVar4);
  uVar4 = FUN_00531230(uVar2,DAT_007bf978);
  if ((iVar1 < 0x20) && (uVar10 != (long)*(int *)(&DAT_007bf89c + iVar1 * 4))) {
LAB_0052a754:
    uVar10 = FUN_005311c8(uVar3,uVar4);
    *puVar11 = uVar10;
  }
  else {
    uVar10 = FUN_005311c8(uVar3,uVar4);
    *puVar11 = uVar10;
    if (0x10 < (int)(iVar8 - ((u32)(uVar10 >> 0x34) & 0x7ff))) {
      uVar4 = FUN_00531230(uVar2,DAT_007bf980);
      uVar5 = FUN_005311c8(uVar3,uVar4);
      auStack_70[2] = uVar5;
      uVar6 = FUN_00531230(uVar2,DAT_007bf988);
      uVar3 = FUN_005311c8(uVar3,uVar5);
      uVar3 = FUN_005311c8(uVar3,uVar4);
      uVar4 = FUN_005311c8(uVar6,uVar3);
      uVar10 = FUN_005311c8(uVar5,uVar4);
      *puVar11 = uVar10;
      uVar3 = uVar5;
      if (0x31 < (int)(iVar8 - ((u32)(uVar10 >> 0x34) & 0x7ff))) {
        uVar4 = FUN_00531230(uVar2,DAT_007bf998);
        uVar3 = FUN_005311c8(uVar5,uVar4);
        uVar2 = FUN_00531230(uVar2,DAT_007bf9a0);
        uVar5 = FUN_005311c8(auStack_70[2],uVar3);
        uVar4 = FUN_005311c8(uVar5,uVar4);
        uVar4 = FUN_005311c8(uVar2,uVar4);
        goto LAB_0052a754;
      }
    }
  }
  uVar13 = *puVar11;
  uVar3 = FUN_005311c8(uVar3,uVar13);
  uVar10 = FUN_005311c8(uVar3,uVar4);
  puVar11[1] = uVar10;
  if (-1 < (long)uVar14) {
    return iVar1;
  }
  uVar14 = FUN_005311c8(0,uVar13);
  *puVar11 = uVar14;
LAB_0052a7a4:
  uVar10 = FUN_005311c8(0,uVar10);
  puVar11[1] = uVar10;
  return -iVar1;
}
// FUN_0052A8C8 NONMATCHING
u32 FUN_0052a8c8(u32 param_1)

{
  bool bVar1;
  u64 uVar2;
  u64 uVar3;
  long lVar4;
  int iVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  int iVar10;
  u32 uVar11;
  u32 uVar12;
  int iVar13;
  u32 uVar14;
  int iVar15;
  u32 uVar16;
  
  uVar11 = (long)param_1 >> 0x20;
  uVar8 = (u32)param_1;
  if ((uVar11 & 0x7ff00000) == 0x7ff00000) {
    uVar2 = FUN_00531230(param_1,param_1);
    uVar11 = FUN_00531170(uVar2,param_1);
    return uVar11;
  }
  iVar15 = (int)((long)param_1 >> 0x34);
  if ((long)uVar11 < 1) {
    if ((uVar11 & 0x7fffffff) == 0 && uVar8 == 0) {
      return param_1;
    }
    if ((long)uVar11 < 0) {
      uVar2 = FUN_005311c8(param_1,param_1);
      uVar3 = FUN_005311c8(param_1,param_1);
      uVar11 = FUN_00531480(uVar2,uVar3);
      return uVar11;
    }
  }
  if (iVar15 == 0) {
    iVar15 = 0;
    if (uVar11 == 0) {
      iVar15 = 0;
      do {
        uVar11 = (u32)(int)(uVar8 >> 0xb);
        iVar15 = iVar15 + -0x15;
        uVar8 = uVar8 << 0x15;
      } while (uVar11 == 0);
    }
    uVar6 = 0;
    for (; (uVar11 & 0x100000) == 0; uVar11 = (u32)((int)uVar11 << 1)) {
      uVar6 = uVar6 + 1;
    }
    iVar15 = (iVar15 - uVar6) + 1;
    uVar11 = uVar11 | (long)(int)(uVar8 >> (-uVar6 & 0x1f));
    uVar8 = uVar8 << (uVar6 & 0x1f);
  }
  uVar6 = (u32)uVar11 & 0xfffff | 0x100000;
  if ((iVar15 - 0x3ffU & 1) != 0) {
    iVar5 = (int)uVar8 >> 0x1f;
    uVar8 = uVar8 << 1;
    uVar6 = uVar6 * 2 - iVar5;
  }
  uVar12 = uVar8 << 1;
  iVar13 = uVar6 * 2 - ((int)uVar8 >> 0x1f);
  uVar6 = 0;
  iVar5 = 0;
  uVar16 = 0;
  uVar8 = 0;
  uVar7 = 0x200000;
  do {
    iVar10 = iVar5 + uVar7;
    if (iVar10 <= iVar13) {
      iVar13 = iVar13 - iVar10;
      iVar5 = iVar10 + uVar7;
      uVar8 = uVar8 + uVar7;
    }
    uVar7 = uVar7 >> 1;
    iVar10 = (int)uVar12 >> 0x1f;
    uVar12 = uVar12 << 1;
    iVar13 = iVar13 * 2 - iVar10;
  } while (uVar7 != 0);
  uVar7 = 0x80000000;
  do {
    uVar9 = uVar6 + uVar7;
    bVar1 = uVar12 < uVar9;
    if ((iVar5 < iVar13) || ((uVar14 = uVar12 & 0x80000000, iVar5 == iVar13 && (!bVar1)))) {
      uVar6 = uVar9 + uVar7;
      iVar10 = iVar5;
      if (((uVar9 & 0x80000000) == 0x80000000) && ((uVar6 & 0x80000000) == 0)) {
        iVar10 = iVar5 + 1;
      }
      uVar12 = uVar12 - uVar9;
      uVar16 = uVar16 + uVar7;
      iVar13 = (iVar13 - iVar5) - (u32)bVar1;
      uVar14 = uVar12 & 0x80000000;
      iVar5 = iVar10;
    }
    uVar7 = uVar7 >> 1;
    uVar12 = uVar12 << 1;
    iVar13 = iVar13 * 2 - ((int)uVar14 >> 0x1f);
  } while (uVar7 != 0);
  if ((iVar13 != 0 || uVar12 != 0) &&
     (lVar4 = FUN_005316d0(0x3ff0000000000000,0x3ff0000000000000), lVar4 < 1)) {
    if (uVar16 == 0xffffffff) {
      uVar16 = 0;
      uVar8 = uVar8 + 1;
    }
    else {
      lVar4 = FUN_005316d0(0x3ff0000000000000,0x3ff0000000000000);
      if (lVar4 < 0) {
        if (uVar16 == 0xfffffffe) {
          uVar8 = uVar8 + 1;
        }
        uVar16 = uVar16 + 2;
      }
      else {
        uVar16 = uVar16 + (uVar16 & 1);
      }
    }
  }
  uVar11 = (long)(int)(uVar16 >> 1);
  if ((uVar8 & 1) != 0) {
    uVar11 = (long)(int)(uVar16 >> 1) | 0xffffffff80000000;
  }
  return (long)(((int)uVar8 >> 1) + 0x3fe00000 + ((int)(iVar15 - 0x3ffU) >> 1) * 0x100000) << 0x20 |
         uVar11 & 0xffffffff;
}
// FUN_0052ABD8 NONMATCHING
float FUN_0052abd8(float param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar2 = DAT_007bfa0c;
  fVar3 = ABS(param_1);
  if (fVar3 == 1.0) {
    fVar2 = 0.0;
    if ((int)param_1 < 1) {
      fVar2 = DAT_007bf9e0;
    }
  }
  else if ((u32)fVar3 < 0x3f800001) {
    if ((u32)fVar3 < 0x3f000000) {
      if ((u32)fVar3 < 0x23000001) {
        return DAT_007bf9e4;
      }
      fVar2 = param_1 * param_1;
      pfVar1 = (float *)&DAT_007bf9e4;
      param_1 = param_1 - (DAT_007bfa14 -
                          param_1 * ((fVar2 * (fVar2 * (fVar2 * (fVar2 * (fVar2 * (fVar2 * 
                                                  DAT_007bf9e8 + DAT_007bf9f0) + DAT_007bf9f8) +
                                                  DAT_007bfa00) + DAT_007bfa08) + DAT_007bfa10)) /
                                    (fVar2 * (fVar2 * (fVar2 * (fVar2 * DAT_007bf9ec + DAT_007bf9f4)
                                                      + DAT_007bf9fc) + DAT_007bfa04) + DAT_007bfa0c
                                    )));
    }
    else {
      if (-1 < (int)param_1) {
        fVar4 = (DAT_007bfa0c - param_1) * DAT_007bfa18;
        fVar5 = (float)FUN_0052c398(fVar4);
        fVar3 = (float)((u32)fVar5 & 0xfffff000);
        fVar3 = fVar3 + ((fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * DAT_007bf9e8 +
                                                                      DAT_007bf9f0) + DAT_007bf9f8)
                                                    + DAT_007bfa00) + DAT_007bfa08) + DAT_007bfa10))
                        / (fVar4 * (fVar4 * (fVar4 * (fVar4 * DAT_007bf9ec + DAT_007bf9f4) +
                                            DAT_007bf9fc) + DAT_007bfa04) + fVar2)) * fVar5 +
                        (fVar4 - fVar3 * fVar3) / (fVar5 + fVar3);
        return fVar3 + fVar3;
      }
      fVar3 = (param_1 + DAT_007bfa0c) * DAT_007bfa18;
      fVar5 = fVar3 * (fVar3 * (fVar3 * (fVar3 * DAT_007bf9ec + DAT_007bf9f4) + DAT_007bf9fc) +
                      DAT_007bfa04) + DAT_007bfa0c;
      fVar2 = fVar3 * (fVar3 * (fVar3 * (fVar3 * (fVar3 * DAT_007bf9e8 + DAT_007bf9f0) +
                                        DAT_007bf9f8) + DAT_007bfa00) + DAT_007bfa08) + DAT_007bfa10
      ;
      param_1 = (float)FUN_0052c398(fVar3);
      pfVar1 = (float *)&DAT_007bf9e0;
      param_1 = param_1 + (((fVar3 * fVar2) / fVar5) * param_1 - DAT_007bfa14);
      param_1 = param_1 + param_1;
    }
    fVar2 = *pfVar1 - param_1;
  }
  else {
    fVar2 = (param_1 - param_1) / (param_1 - param_1);
  }
  return fVar2;
}
// FUN_0052AFE8 NONMATCHING
float FUN_0052afe8(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar2 = ABS(param_1);
  if (fVar2 == 1.0) {
    fVar2 = param_1 * DAT_007bfa60 + param_1 * DAT_007bfa5c;
  }
  else if ((u32)fVar2 < 0x3f800001) {
    if ((u32)fVar2 < 0x3f000000) {
      if (0x31ffffff < (u32)fVar2) {
        fVar2 = param_1 * param_1;
        return param_1 + param_1 * ((fVar2 * (fVar2 * (fVar2 * (fVar2 * (fVar2 * (fVar2 * 
                                                  DAT_007bfa6c + DAT_007bfa74) + DAT_007bfa7c) +
                                                  DAT_007bfa84) + DAT_007bfa8c) + DAT_007bfa90)) /
                                   (fVar2 * (fVar2 * (fVar2 * (fVar2 * DAT_007bfa70 + DAT_007bfa78)
                                                     + DAT_007bfa80) + DAT_007bfa88) + DAT_007bfa68)
                                   );
      }
      if (DAT_007bfa68 < param_1 + DAT_007bfa64) {
        return param_1;
      }
    }
    fVar1 = (float)FUN_0052e788();
    fVar4 = (DAT_007bfa68 - fVar1) * DAT_007bfa94;
    fVar5 = fVar4 * (fVar4 * (fVar4 * (fVar4 * DAT_007bfa70 + DAT_007bfa78) + DAT_007bfa80) +
                    DAT_007bfa88) + DAT_007bfa68;
    fVar3 = fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * DAT_007bfa6c + DAT_007bfa74) +
                                               DAT_007bfa7c) + DAT_007bfa84) + DAT_007bfa8c) +
                    DAT_007bfa90);
    fVar1 = (float)FUN_0052c398(fVar4);
    if ((u32)fVar2 < 0x3f79999a) {
      fVar2 = (float)((u32)fVar1 & 0xfffff000);
      fVar4 = (fVar4 - fVar2 * fVar2) / (fVar1 + fVar2);
      fVar2 = DAT_007bfa98 -
              (((fVar1 + fVar1) * (fVar3 / fVar5) - (DAT_007bfa60 - (fVar4 + fVar4))) -
              (DAT_007bfa98 - (fVar2 + fVar2)));
    }
    else {
      fVar1 = fVar1 + fVar1 * (fVar3 / fVar5);
      fVar2 = DAT_007bfa5c - ((fVar1 + fVar1) - DAT_007bfa60);
    }
    if ((int)param_1 < 1) {
      fVar2 = -fVar2;
    }
  }
  else {
    fVar2 = (param_1 - param_1) / (param_1 - param_1);
  }
  return fVar2;
}
// FUN_0052B380 NONMATCHING
float FUN_0052b380(float param_1,float param_2)

{
  int iVar1;
  u64 uVar2;
  u32 uVar3;
  float fVar4;
  u32 uVar5;
  
  if (param_2 == 1.0) {
    fVar4 = (float)FUN_0052e408();
    return fVar4;
  }
  uVar3 = (u32)param_1 >> 0x1f | (int)param_2 >> 0x1e & 2U;
  if ((0x7fffff < (u32)ABS(param_1)) ||
     (((fVar4 = 3.1415925, uVar3 != 2 && (fVar4 = param_1, 2 < uVar3)) &&
      (fVar4 = -3.1415925, uVar3 != 3)))) {
    if ((u32)ABS(param_2) < 0x800000) {
      uVar5 = _ctc2(0xbfc90fda);
      _vnop();
      if (-1 < (int)param_1) {
        uVar5 = _ctc2(0x3fc90fda);
        _vnop();
      }
      _vwaitq();
      uVar2 = _cfc2(uVar5);
      _vnop();
      fVar4 = (float)uVar2;
    }
    else {
      iVar1 = (int)ABS(param_1) - (int)ABS(param_2) >> 0x17;
      fVar4 = DAT_007bfab8;
      if ((iVar1 < 0x3d) && ((-1 < (int)param_2 || (fVar4 = 0.0, -0x3d < iVar1)))) {
        uVar5 = FUN_0052e788(param_1 / param_2);
        fVar4 = (float)FUN_0052e408(uVar5);
      }
      if (uVar3 == 1) {
        fVar4 = -fVar4;
      }
      else {
        if (uVar3 < 2) {
          if (uVar3 == 0) {
            return fVar4;
          }
        }
        else if (uVar3 == 2) {
          return DAT_007bfac0 - (fVar4 - DAT_007bfabc);
        }
        fVar4 = (fVar4 - DAT_007bfabc) - DAT_007bfac0;
      }
    }
  }
  return fVar4;
}
// FUN_0052B548 NONMATCHING
float FUN_0052b548(float param_1)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  if ((u32)ABS(param_1) < 0x800000) {
    return DAT_007bfaf4;
  }
  if ((int)param_1 < 0) {
    fVar4 = (param_1 - param_1) / 0.0;
  }
  else {
    uVar2 = (u32)param_1 & 0x7fffff;
    uVar1 = uVar2 + 0x4afb20 & 0x800000;
    fVar8 = (float)(uVar2 | uVar1 ^ 0x3f800000) - DAT_007bfaf8;
    iVar3 = ((int)param_1 >> 0x17) + -0x7f + ((int)uVar1 >> 0x17);
    if (0xf < (uVar2 + 0xf & 0x7fffff)) {
      fVar7 = (float)iVar3;
      fVar6 = fVar8 / (fVar8 + DAT_007bfb0c);
      fVar4 = fVar6 * fVar6;
      fVar5 = fVar4 * fVar4;
      fVar4 = fVar4 * (fVar5 * (fVar5 * (fVar5 * DAT_007bfb10 + DAT_007bfb18) + DAT_007bfb20) +
                      DAT_007bfb28) +
              fVar5 * (fVar5 * (fVar5 * DAT_007bfb14 + DAT_007bfb1c) + DAT_007bfb24);
      if ((int)(uVar2 - 0x30a3d0 | 0x35c288 - uVar2) < 1) {
        if (iVar3 != 0) {
          return fVar7 * DAT_007bfafc - ((fVar6 * (fVar8 - fVar4) - fVar7 * DAT_007bfb00) - fVar8);
        }
        fVar5 = fVar6 * (fVar8 - fVar4);
      }
      else {
        fVar5 = fVar8 * DAT_007bfb08 * fVar8;
        if (iVar3 != 0) {
          fVar5 = fVar5 - (fVar7 * DAT_007bfb00 + fVar6 * (fVar5 + fVar4));
          goto LAB_0052b688;
        }
        fVar5 = fVar5 - fVar6 * (fVar5 + fVar4);
      }
      return fVar8 - fVar5;
    }
    fVar4 = 0.0;
    if (fVar8 != 0.0) {
      fVar5 = fVar8 * fVar8 * (DAT_007bfb08 - fVar8 * DAT_007bfb04);
      if (iVar3 == 0) {
        return fVar8 - fVar5;
      }
      fVar5 = fVar5 - (float)iVar3 * DAT_007bfb00;
LAB_0052b688:
      return (float)iVar3 * DAT_007bfafc - (fVar5 - fVar8);
    }
    if (iVar3 != 0) {
      return (float)iVar3 * DAT_007bfb00 + (float)iVar3 * DAT_007bfafc;
    }
  }
  return fVar4;
}
// FUN_0052B800 NONMATCHING
float FUN_0052b800(float param_1,float param_2)

{
  u32 uVar1;
  int iVar2;
  int iVar3;
  u32 uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  float *pfVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  
  fVar9 = ABS(param_2);
  fVar14 = ABS(param_1);
  if ((u32)fVar9 < 0x800000) {
    return DAT_007bfbb8;
  }
  iVar2 = 0;
  if ((int)param_1 < 0) {
    if ((u32)fVar9 < 0x4b800000) {
      if ((0x3f7fffff < (u32)fVar9) &&
         (uVar4 = 0x96 - ((int)fVar9 >> 0x17), uVar1 = (int)fVar9 >> (uVar4 & 0x1f),
         (float)(uVar1 << (uVar4 & 0x1f)) == fVar9)) {
        iVar2 = 2 - (uVar1 & 1);
      }
    }
    else {
      iVar2 = 2;
    }
  }
  if (fVar9 == 1.0) {
    if ((int)param_2 < 0) {
      return DAT_007bfbb8 / param_1;
    }
    return param_1;
  }
  if (param_2 == 2.0) {
    return param_1 * param_1;
  }
  if ((param_2 == 0.5) && (-1 < (int)param_1)) {
    fVar9 = (float)FUN_0052c398(param_1);
    return fVar9;
  }
  fVar11 = param_2;
  fVar10 = (float)FUN_0052e788(param_1);
  if (((u32)fVar14 < 0x800000) || (fVar14 == 1.0)) {
    if ((int)param_2 < 0) {
      fVar10 = DAT_007bfbb8 / fVar10;
    }
    if (-1 < (int)param_1) {
      return fVar10;
    }
    if (fVar14 == 1.0 && iVar2 == 0) {
      return (fVar10 - fVar10) / (fVar10 - fVar10);
    }
    if (iVar2 == 1) {
      return -fVar10;
    }
    return fVar10;
  }
  if ((int)param_1 < 0 && iVar2 == 0) {
    return (param_1 - param_1) / (param_1 - param_1);
  }
  if ((u32)fVar9 < 0x4d000001) {
    pcVar6 = (char *)((u32)param_1 & 0x7fffff);
    fVar9 = (float)((u32)pcVar6 | 0x3f800000);
    iVar3 = ((int)fVar14 >> 0x17) + -0x7f;
    iVar5 = 0;
    if (("" < pcVar6) && (iVar5 = 1, s_camp_commu_card_i_s_card0d_tmx_005db3d0 + 6 < pcVar6)) {
      iVar3 = ((int)fVar14 >> 0x17) + -0x7e;
      fVar9 = (float)((int)fVar9 - 0x800000);
      iVar5 = 0;
    }
    iVar7 = iVar5 * 4;
    fVar10 = *(float *)(&DAT_007bfb30 + iVar7);
    fVar15 = DAT_007bfbb8 / (fVar9 + fVar10);
    fVar14 = (float)(((int)fVar9 >> 1 | 0x20000000U) + iVar5 * 0x200000 + 0x40000);
    fVar16 = (fVar9 - fVar10) * fVar15;
    fVar13 = fVar16 * fVar16;
    fVar12 = (float)((u32)fVar16 & 0xfffff000);
    fVar15 = fVar15 * (((fVar9 - fVar10) - fVar12 * fVar14) - fVar12 * (fVar9 - (fVar14 - fVar10)));
    fVar14 = fVar15 * (fVar12 + fVar16) +
             fVar13 * fVar13 *
             (fVar13 * (fVar13 * (fVar13 * (fVar13 * (fVar13 * DAT_007bfbd8 + DAT_007bfbdc) +
                                           DAT_007bfbe0) + DAT_007bfbe4) + DAT_007bfbe8) +
             DAT_007bfbec);
    fVar9 = (float)((u32)(fVar12 * fVar12 + DAT_007bfbd4 + fVar14) & 0xfffff000);
    fVar14 = (fVar14 - ((fVar9 - DAT_007bfbd4) - fVar12 * fVar12)) * fVar16 + fVar15 * fVar9;
    fVar10 = (float)((u32)(fVar12 * fVar9 + fVar14) & 0xfffff000);
    fVar14 = (fVar14 - (fVar10 - fVar12 * fVar9)) * DAT_007bfbf8 + fVar10 * DAT_007bfbf0 +
             *(float *)(&DAT_007bfb40 + iVar7);
    fVar9 = (float)((u32)(fVar10 * DAT_007bfbf4 + fVar14 + *(float *)(&DAT_007bfb38 + iVar7) +
                          (float)iVar3) & 0xfffff000);
    fVar14 = fVar14 - (((fVar9 - (float)iVar3) - *(float *)(&DAT_007bfb38 + iVar7)) -
                      fVar10 * DAT_007bfbf4);
  }
  else {
    if ((u32)fVar14 < 0x3f7ffff8) {
      if (-1 < (int)param_2) {
        return 0.0;
      }
      return DAT_007bfbb4;
    }
    if (0x3f800007 < (u32)fVar14) {
      if ((int)param_2 < 1) {
        return 0.0;
      }
      return DAT_007bfbb4;
    }
    fVar10 = param_1 - DAT_007bfbb8;
    fVar14 = fVar10 * DAT_007bfbc0 -
             fVar10 * fVar10 * (DAT_007bfbcc - fVar10 * (DAT_007bfbc8 - fVar10 * DAT_007bfbbc)) *
             DAT_007bfbd0;
    fVar9 = (float)((u32)(fVar10 * DAT_007bfbc4 + fVar14) & 0xfffff000);
    fVar14 = fVar14 - (fVar9 - fVar10 * DAT_007bfbc4);
  }
  fVar10 = DAT_007bfbb8;
  if ((int)param_1 < 0 && iVar2 == 1) {
    fVar10 = DAT_007bfbfc;
  }
  fVar12 = (float)((u32)fVar11 & 0xfffff000) * fVar9;
  fVar11 = fVar11 * fVar14 + (fVar11 - (float)((u32)fVar11 & 0xfffff000)) * fVar9;
  fVar9 = fVar11 + fVar12;
  fVar14 = ABS(fVar9);
  if ((int)fVar9 < 1) {
    fVar15 = DAT_007bfc08;
    if (0x42fc0000 < (u32)fVar14) goto LAB_0052bb6c;
    if ((fVar14 != 126.0) || (fVar9 - fVar12 < fVar11)) goto LAB_0052bb7c;
    pfVar8 = (float *)&DAT_007bfc08;
  }
  else {
    if (((u32)fVar14 < 0x43010001) &&
       ((fVar14 != 129.0 || (fVar11 + DAT_007bfc04 <= fVar9 - fVar12)))) {
LAB_0052bb7c:
      iVar2 = 0;
      if (0x3f000000 < (u32)fVar14) {
        uVar1 = (int)fVar9 + (0x800000 >> (((int)fVar14 >> 0x17) - 0x7eU & 0x1f));
        uVar4 = (uVar1 >> 0x17 & 0xff) - 0x7f;
        iVar2 = (int)(uVar1 & 0x7fffff | 0x800000) >> (0x17 - uVar4 & 0x1f);
        fVar12 = fVar12 - (float)(uVar1 & ~(0x7fffff >> (uVar4 & 0x1f)));
        if ((int)fVar9 < 0) {
          iVar2 = -iVar2;
        }
        fVar9 = fVar11 + fVar12;
      }
      fVar9 = (float)((u32)fVar9 & 0xfffff000);
      fVar11 = fVar9 * DAT_007bfc14 + (fVar11 - (fVar9 - fVar12)) * DAT_007bfc10;
      fVar12 = fVar9 * DAT_007bfc0c + fVar11;
      fVar14 = fVar12 * fVar12;
      fVar11 = fVar11 - (fVar12 - fVar9 * DAT_007bfc0c);
      fVar9 = fVar12 - fVar14 * (fVar14 * (fVar14 * (fVar14 * (fVar14 * DAT_007bfc18 + DAT_007bfc1c)
                                                    + DAT_007bfc20) + DAT_007bfc24) + DAT_007bfc28);
      fVar9 = (float)((int)(DAT_007bfbb8 -
                           (((fVar12 * fVar9) / (fVar9 - DAT_007bfc2c) - (fVar11 + fVar12 * fVar11))
                           - fVar12)) + iVar2 * 0x800000);
      if ((int)fVar9 >> 0x17 < 1) {
        fVar9 = (float)FUN_005239a8();
      }
      return fVar10 * fVar9;
    }
    pfVar8 = (float *)&DAT_007bfc00;
  }
  fVar15 = *pfVar8;
LAB_0052bb6c:
  return fVar10 * fVar15 * fVar15;
}
// FUN_0052C000 NONMATCHING
int FUN_0052c000(float param_1,u64 param_2)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fStack_30;
  float afStack_2c [3];
  
  fVar6 = DAT_007c0010;
  pfVar2 = &fStack_30;
  afStack_2c[1] = ABS(param_1);
  pfVar3 = (float *)param_2;
  if ((u32)afStack_2c[1] < 0x3f490fd9) {
    *pfVar3 = param_1;
    pfVar3[1] = 0.0;
    return 0;
  }
  if ((u32)afStack_2c[1] < 0x4016cbe4) {
    if ((int)param_1 < 1) {
      fVar4 = param_1 + DAT_007bfff0;
      fVar6 = DAT_007bfff4;
      if (((u32)param_1 & 0x7ffffff0) == 0x3fc90fd0) {
        fVar4 = fVar4 + DAT_007bfffc;
        fVar6 = DAT_007bfff8;
      }
      iVar5 = -1;
      *pfVar3 = fVar4 + fVar6;
      fVar6 = (fVar4 - (fVar4 + fVar6)) + fVar6;
    }
    else {
      fVar4 = param_1 - DAT_007bfff0;
      fVar6 = DAT_007bfff4;
      if (((u32)param_1 & 0x7ffffff0) == 0x3fc90fd0) {
        fVar4 = fVar4 - DAT_007bfffc;
        fVar6 = DAT_007bfff8;
      }
      iVar5 = 1;
      *pfVar3 = fVar4 - fVar6;
      fVar6 = (fVar4 - (fVar4 - fVar6)) - fVar6;
    }
  }
  else {
    iVar1 = (int)afStack_2c[1] >> 0x17;
    if ((u32)afStack_2c[1] < 0x43490f81) {
      fVar7 = (float)FUN_0052e788();
      iVar5 = (int)(fVar7 * DAT_007c0000 + DAT_007c0004);
      fVar4 = (float)iVar5;
      fVar6 = fVar4 * DAT_007bfff4;
      fVar7 = fVar7 - fVar4 * DAT_007bfff0;
      if ((iVar5 < 0x20) && (((u32)param_1 & 0x7fffff00) != *(u32 *)(&DAT_007bff44 + iVar5 * 4)))
      {
        *pfVar3 = fVar7 - fVar6;
      }
      else {
        *pfVar3 = fVar7 - fVar6;
        if (8 < (int)(iVar1 - ((u32)(fVar7 - fVar6) >> 0x17 & 0xff))) {
          fVar8 = fVar7 - fVar4 * DAT_007bfffc;
          fVar6 = fVar4 * DAT_007bfff8 - ((fVar7 - fVar8) - fVar4 * DAT_007bfffc);
          *pfVar3 = fVar8 - fVar6;
          fVar7 = fVar8;
          if (0x19 < (int)(iVar1 - ((u32)(fVar8 - fVar6) >> 0x17 & 0xff))) {
            fVar7 = fVar8 - fVar4 * DAT_007c0008;
            fVar6 = fVar4 * DAT_007c000c - ((fVar8 - fVar7) - fVar4 * DAT_007c0008);
            *pfVar3 = fVar7 - fVar6;
          }
        }
      }
      fVar4 = *pfVar3;
      fVar6 = (fVar7 - fVar4) - fVar6;
      pfVar3[1] = fVar6;
      if (-1 < (int)param_1) {
        return iVar5;
      }
    }
    else {
      afStack_2c[1] = (float)((int)afStack_2c[1] + (iVar1 + -0x86) * -0x800000);
      iVar5 = 1;
      do {
        iVar5 = iVar5 + -1;
        *pfVar2 = (float)(int)afStack_2c[1];
        pfVar2 = pfVar2 + 1;
        afStack_2c[1] = (afStack_2c[1] - (float)(int)afStack_2c[1]) * fVar6;
      } while (-1 < iVar5);
      iVar5 = 3;
      if (afStack_2c[1] == 0.0) {
        pfVar2 = afStack_2c + 1;
        do {
          pfVar2 = pfVar2 + -1;
          iVar5 = iVar5 + -1;
        } while (*pfVar2 == 0.0);
      }
      iVar5 = FUN_0052d428(&fStack_30,param_2,iVar1 + -0x86,iVar5,2,0x7bfc30);
      if (-1 < (int)param_1) {
        return iVar5;
      }
      fVar4 = *pfVar3;
      fVar6 = pfVar3[1];
    }
    iVar5 = -iVar5;
    fVar6 = -fVar6;
    *pfVar3 = -fVar4;
  }
  pfVar3[1] = fVar6;
  return iVar5;
}
// FUN_0052C398 NONMATCHING
float FUN_0052c398(float param_1)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  u32 uVar4;
  int iVar5;
  int iVar6;
  
  if (0x7fffff < (u32)ABS(param_1)) {
    if ((int)param_1 < 0) {
      param_1 = (param_1 - param_1) / (param_1 - param_1);
    }
    else {
      uVar1 = ((int)param_1 >> 0x17) - 0x7f;
      iVar3 = 0;
      uVar2 = 0;
      iVar6 = (((u32)param_1 & 0x7fffff | 0x800000) << (uVar1 & 1)) << 1;
      uVar4 = 0x1000000;
      do {
        iVar5 = iVar3 + uVar4;
        if (iVar5 <= iVar6) {
          iVar6 = iVar6 - iVar5;
          iVar3 = iVar5 + uVar4;
          uVar2 = uVar2 + uVar4;
        }
        uVar4 = uVar4 >> 1;
        iVar6 = iVar6 << 1;
      } while (uVar4 != 0);
      if (iVar6 != 0) {
        uVar2 = uVar2 + (uVar2 & 1);
      }
      param_1 = (float)(((int)uVar2 >> 1) + 0x3f000000 + ((int)uVar1 >> 1) * 0x800000);
    }
  }
  return param_1;
}
// FUN_0052C478 NONMATCHING
u64 FUN_0052c478(long param_1,u64 param_2)

{
  long lVar1;
  u64 uVar2;
  u64 uVar3;
  u64 uVar4;
  u64 uVar5;
  u32 uVar6;
  
  uVar6 = param_1 >> 0x20 & 0x7fffffff;
  if ((uVar6 < 0x3e400000) && (lVar1 = FUN_005317d0(0ULL), lVar1 == 0)) {
    return 0x3ff0000000000000;
  }
  uVar2 = FUN_00531230(param_1,param_1);
  uVar3 = FUN_00531230(uVar2,DAT_007c0060);
  uVar3 = FUN_00531170(uVar3,DAT_007c0068);
  uVar3 = FUN_00531230(uVar2,uVar3);
  uVar3 = FUN_00531170(uVar3,DAT_007c0070);
  uVar3 = FUN_00531230(uVar2,uVar3);
  uVar3 = FUN_00531170(uVar3,DAT_007c0078);
  uVar3 = FUN_00531230(uVar2,uVar3);
  uVar3 = FUN_00531170(uVar3,DAT_007c0080);
  uVar3 = FUN_00531230(uVar2,uVar3);
  uVar3 = FUN_00531170(uVar3,DAT_007c0088);
  uVar3 = FUN_00531230(uVar2,uVar3);
  if (uVar6 < 0x3fd33333) {
    uVar4 = FUN_00531230(uVar2,0x3fe0000000000000);
    uVar2 = FUN_00531230(uVar2,uVar3);
    uVar3 = FUN_00531230(param_1,param_2);
    uVar2 = FUN_005311c8(uVar2,uVar3);
    uVar2 = FUN_005311c8(uVar4,uVar2);
    uVar5 = 0x3ff0000000000000;
  }
  else {
    lVar1 = 0x3fd2000000000000;
    if (uVar6 < 0x3fe90001) {
      lVar1 = (long)((int)uVar6 + -0x200000) << 0x20;
    }
    uVar4 = FUN_00531230(uVar2,0x3fe0000000000000);
    uVar4 = FUN_005311c8(uVar4,lVar1);
    uVar5 = FUN_005311c8(0x3ff0000000000000,lVar1);
    uVar2 = FUN_00531230(uVar2,uVar3);
    uVar3 = FUN_00531230(param_1,param_2);
    uVar2 = FUN_005311c8(uVar2,uVar3);
    uVar2 = FUN_005311c8(uVar4,uVar2);
  }
  uVar2 = FUN_005311c8(uVar5,uVar2);
  return uVar2;
}
// FUN_0052C6D0 NONMATCHING
u32 FUN_0052c6d0(u64 *param_1,u64 *param_2,int param_3,int param_4,int param_5,
                 int param_6)

{
  bool bVar1;
  u32 uVar2;
  u64 uVar3;
  u64 uVar4;
  long lVar5;
  u64 uVar6;
  int iVar7;
  u32 *puVar8;
  int iVar9;
  u32 uVar10;
  u32 *puVar11;
  u64 *puVar12;
  int iVar13;
  u64 *puVar14;
  u64 *puVar15;
  u64 *puVar16;
  u64 *puVar17;
  int iVar18;
  u32 auStack_2c4 [21];
  u64 auStack_270 [20];
  u64 auStack_1d0 [19];
  u64 auStack_138 [21];
  u64 *puStack_90;
  u64 *puStack_8c;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  int iStack_78;
  u32 uStack_74;
  int iStack_70;
  int iStack_6c;
  u32 uStack_68;
  int iStack_64;
  u32 uStack_60;
  
  iStack_7c = (param_3 + -3) / 0x18;
  iStack_80 = param_4 + -1;
  iStack_88 = param_5;
  iStack_78 = *(int *)(&DAT_007c0090 + param_5 * 4);
  iVar7 = iStack_80 + *(int *)(&DAT_007c0090 + param_5 * 4);
  puStack_90 = param_1;
  puStack_8c = param_2;
  iStack_84 = param_6;
  if (iStack_7c < 0) {
    iStack_7c = 0;
  }
  iVar9 = iStack_7c - iStack_80;
  iStack_70 = param_3 + iStack_7c * -0x18 + -0x18;
  if (-1 < iVar7) {
    iVar7 = iVar7 + 1;
    puVar11 = (u32 *)(iVar9 * 4 + param_6);
    puVar14 = auStack_270;
    do {
      uVar3 = 0;
      if (-1 < iVar9) {
        uVar3 = FUN_00531720(*puVar11);
      }
      *puVar14 = uVar3;
      iVar7 = iVar7 + -1;
      puVar11 = puVar11 + 1;
      iVar9 = iVar9 + 1;
      puVar14 = puVar14 + 1;
    } while (iVar7 != 0);
  }
  iVar9 = 0;
  uStack_68 = (u32)(iStack_78 < 0);
  iVar7 = iStack_78;
  if (iStack_78 >= 0) {
    puVar14 = auStack_138;
    uStack_60 = (u32)(iStack_80 < 0);
    puVar17 = auStack_270 + iStack_80 + -10;
    do {
      puVar14 = puVar14 + 1;
      uVar3 = 0;
      if (uStack_60 == 0) {
        uVar3 = 0;
        puVar15 = puVar17 + 10;
        iVar7 = iStack_80 + 1;
        puVar12 = puStack_90;
        do {
          uVar6 = *puVar12;
          iVar7 = iVar7 + -1;
          puVar12 = puVar12 + 1;
          uVar6 = FUN_00531230(uVar6,*puVar15);
          puVar15 = puVar15 + -1;
          uVar3 = FUN_00531170(uVar3,uVar6);
        } while (iVar7 != 0);
      }
      *puVar14 = uVar3;
      iVar9 = iVar9 + 1;
      puVar17 = puVar17 + 1;
      iVar7 = iStack_78;
    } while (iVar9 <= iStack_78);
  }
  do {
    iVar9 = iVar7;
    uVar3 = auStack_138[iVar9 + 1];
    if (0 < iVar9) {
      puVar14 = auStack_138 + iVar9;
      iVar7 = iVar9;
      puVar8 = auStack_2c4;
      do {
        puVar8 = puVar8 + 1;
        iVar7 = iVar7 + -1;
        uVar6 = FUN_00531230(uVar3,0x3e70000000000000);
        uVar6 = FUN_005317d0(uVar6);
        uVar6 = FUN_00531720(uVar6);
        uVar4 = FUN_00531230(uVar6,0x4170000000000000);
        uVar3 = FUN_005311c8(uVar3,uVar4);
        uVar2 = FUN_005317d0(uVar3);
        uVar3 = *puVar14;
        *puVar8 = uVar2;
        puVar14 = puVar14 + -1;
        uVar3 = FUN_00531170(uVar3,uVar6);
      } while (0 < iVar7);
    }
    uVar3 = FUN_005237b0(uVar3,iStack_70);
    uVar6 = FUN_00531230(uVar3,0x3fc0000000000000);
    uVar6 = FUN_0052e148(uVar6);
    uVar6 = FUN_00531230(uVar6,0x4020000000000000);
    uVar3 = FUN_005311c8(uVar3,uVar6);
    uStack_74 = FUN_005317d0(uVar3);
    uVar6 = FUN_00531720(uStack_74);
    uVar3 = FUN_005311c8(uVar3,uVar6);
    if (iStack_70 < 1) {
      if (iStack_70 == 0) {
        iStack_6c = (int)auStack_2c4[iVar9] >> 0x17;
      }
      else {
        iStack_6c = 2;
        lVar5 = FUN_005316d0(0x3fe0000000000000,uVar3);
        if (0 < lVar5) {
          iStack_6c = 0;
        }
      }
    }
    else {
      iVar7 = (int)auStack_2c4[iVar9] >> (0x18U - iStack_70 & 0x1f);
      uVar2 = 0x17 - iStack_70;
      uVar10 = auStack_2c4[iVar9] - (iVar7 << (0x18U - iStack_70 & 0x1f));
      auStack_2c4[iVar9] = uVar10;
      iStack_6c = (int)uVar10 >> (uVar2 & 0x1f);
      uStack_74 = uStack_74 + iVar7;
    }
    if (0 < iStack_6c) {
      bVar1 = false;
      uStack_74 = uStack_74 + 1;
      iVar7 = iVar9;
      puVar8 = auStack_2c4;
      if (0 < iVar9) {
        do {
          puVar8 = puVar8 + 1;
          uVar2 = *puVar8;
          uVar10 = 0xffffff - uVar2;
          if (bVar1) {
LAB_0052c9cc:
            *puVar8 = uVar10;
          }
          else {
            uVar10 = 0x1000000 - uVar2;
            if (uVar2 != 0) {
              bVar1 = true;
              goto LAB_0052c9cc;
            }
          }
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      if (0 < iStack_70) {
        if (iStack_70 == 1) {
          uVar2 = 0x7f0000;
        }
        else {
          if (iStack_70 != 2) goto LAB_0052c9f8;
          uVar2 = 0x3f0000;
        }
        auStack_2c4[iVar9] = auStack_2c4[iVar9] & (uVar2 | 0xffff);
      }
LAB_0052c9f8:
      if ((iStack_6c == 2) && (uVar3 = FUN_005311c8(0x3ff0000000000000,uVar3), bVar1)) {
        uVar6 = FUN_005237b0(0x3ff0000000000000,iStack_70);
        uVar3 = FUN_005311c8(uVar3,uVar6);
      }
    }
    lVar5 = FUN_005316d0(uVar3,0);
    if (lVar5 != 0) {
LAB_0052cbd0:
      lVar5 = FUN_005316d0(uVar3,0);
      if (lVar5 == 0) {
        puVar8 = auStack_2c4 + iVar9;
        iStack_70 = iStack_70 + -0x18;
        uVar2 = *puVar8;
        while (iVar9 = iVar9 + -1, uVar2 == 0) {
          puVar8 = puVar8 + -1;
          uVar2 = *puVar8;
          iStack_70 = iStack_70 + -0x18;
        }
      }
      else {
        uVar3 = FUN_005237b0(uVar3,-iStack_70);
        lVar5 = FUN_005316d0(0x4170000000000000,uVar3);
        if (lVar5 < 1) {
          iStack_70 = iStack_70 + 0x18;
          iVar7 = iVar9 + 1;
          iVar9 = iVar9 + 1;
          uVar6 = FUN_00531230(uVar3,0x3e70000000000000);
          uVar6 = FUN_005317d0(uVar6);
          uVar6 = FUN_00531720(uVar6);
          uVar4 = FUN_00531230(uVar6,0x4170000000000000);
          uVar3 = FUN_005311c8(uVar3,uVar4);
          uVar2 = FUN_005317d0(uVar3);
          auStack_2c4[iVar7] = uVar2;
          uVar3 = uVar6;
        }
        uVar2 = FUN_005317d0(uVar3);
        auStack_2c4[iVar9 + 1] = uVar2;
      }
      uVar3 = FUN_005237b0(0x3ff0000000000000,iStack_70);
      if (-1 < iVar9) {
        puVar8 = auStack_2c4 + iVar9 + 1;
        puVar14 = auStack_138 + iVar9 + 1;
        iVar7 = iVar9;
        do {
          iVar7 = iVar7 + -1;
          uVar6 = FUN_00531720(*puVar8);
          puVar8 = puVar8 + -1;
          uVar6 = FUN_00531230(uVar3,uVar6);
          *puVar14 = uVar6;
          uVar3 = FUN_00531230(uVar3,0x3e70000000000000);
          puVar14 = puVar14 + -1;
        } while (-1 < iVar7);
        if (-1 < iVar9) {
          puVar14 = auStack_270 + iVar9 + -10;
          iVar7 = iVar9;
          do {
            uVar3 = 0;
            iVar13 = 0;
            if (uStack_68 == 0) {
              iVar18 = iVar9 - iVar7;
              if (-1 < iVar18) {
                puVar12 = puVar14 + 0x32;
                puVar17 = (u64 *)&DAT_007c00a0;
                uVar6 = DAT_007c00a0;
                while( true ) {
                  iVar13 = iVar13 + 1;
                  puVar17 = puVar17 + 1;
                  uVar6 = FUN_00531230(uVar6,*puVar12);
                  puVar12 = puVar12 + 1;
                  uVar3 = FUN_00531170(uVar3,uVar6);
                  if ((iStack_78 < iVar13) || (iVar18 < iVar13)) break;
                  uVar6 = *puVar17;
                }
              }
            }
            else {
              iVar18 = iVar9 - iVar7;
            }
            puVar14 = puVar14 + -1;
            iVar7 = iVar7 + -1;
            auStack_1d0[iVar18] = uVar3;
          } while (-1 < iVar7);
        }
      }
      if (iStack_88 < 3) {
        if (iStack_88 < 1) {
          if (iStack_88 == 0) {
            uVar3 = 0;
            if (-1 < iVar9) {
              puVar14 = auStack_1d0 + iVar9;
              do {
                iVar9 = iVar9 + -1;
                uVar3 = FUN_00531170(uVar3,*puVar14);
                puVar14 = puVar14 + -1;
              } while (-1 < iVar9);
            }
            if (iStack_6c != 0) {
              uVar3 = FUN_005311c8(0,uVar3);
            }
            *puStack_8c = uVar3;
          }
        }
        else {
          uVar3 = 0;
          if (-1 < iVar9) {
            puVar14 = auStack_1d0 + iVar9;
            iVar7 = iVar9;
            do {
              iVar7 = iVar7 + -1;
              uVar3 = FUN_00531170(uVar3,*puVar14);
              puVar14 = puVar14 + -1;
            } while (-1 < iVar7);
          }
          uVar6 = uVar3;
          if (iStack_6c != 0) {
            uVar6 = FUN_005311c8(0,uVar3);
          }
          *puStack_8c = uVar6;
          uVar3 = FUN_005311c8(auStack_1d0[0],uVar3);
          if (0 < iVar9) {
            puVar14 = auStack_1d0;
            do {
              puVar14 = puVar14 + 1;
              iVar9 = iVar9 + -1;
              uVar3 = FUN_00531170(uVar3,*puVar14);
            } while (iVar9 != 0);
          }
          if (iStack_6c != 0) {
            uVar3 = FUN_005311c8(0,uVar3);
          }
          puStack_8c[1] = uVar3;
        }
      }
      else if (iStack_88 == 3) {
        if (0 < iVar9) {
          puVar14 = auStack_270 + iVar9 + -10;
          iVar7 = iVar9;
          do {
            uVar6 = puVar14[0x1d];
            iVar7 = iVar7 + -1;
            uVar4 = puVar14[0x1e];
            uVar3 = FUN_00531170(uVar6,uVar4);
            uVar6 = FUN_005311c8(uVar6,uVar3);
            uVar6 = FUN_00531170(uVar4,uVar6);
            puVar14[0x1e] = uVar6;
            puVar14[0x1d] = uVar3;
            puVar14 = puVar14 + -1;
          } while (0 < iVar7);
        }
        if (1 < iVar9) {
          puVar14 = auStack_270 + iVar9 + -10;
          iVar7 = iVar9;
          do {
            uVar6 = puVar14[0x1d];
            iVar7 = iVar7 + -1;
            uVar4 = puVar14[0x1e];
            uVar3 = FUN_00531170(uVar6,uVar4);
            uVar6 = FUN_005311c8(uVar6,uVar3);
            uVar6 = FUN_00531170(uVar4,uVar6);
            puVar14[0x1e] = uVar6;
            puVar14[0x1d] = uVar3;
            puVar14 = puVar14 + -1;
          } while (1 < iVar7);
        }
        uVar3 = 0;
        if (1 < iVar9) {
          puVar14 = auStack_1d0 + iVar9;
          do {
            iVar9 = iVar9 + -1;
            uVar3 = FUN_00531170(uVar3,*puVar14);
            puVar14 = puVar14 + -1;
          } while (1 < iVar9);
        }
        if (iStack_6c == 0) {
          puStack_8c[2] = uVar3;
          *puStack_8c = auStack_1d0[0];
          puStack_8c[1] = auStack_1d0[1];
        }
        else {
          uVar6 = FUN_005311c8(0,auStack_1d0[0]);
          *puStack_8c = uVar6;
          uVar6 = FUN_005311c8(0,auStack_1d0[1]);
          puStack_8c[1] = uVar6;
          uVar3 = FUN_005311c8(0,uVar3);
          puStack_8c[2] = uVar3;
        }
      }
      return uStack_74 & 7;
    }
    iVar7 = iVar9 + -1;
    uVar2 = 0;
    if (iStack_78 <= iVar7) {
      uVar2 = 0;
      puVar8 = auStack_2c4 + iVar9;
      do {
        iVar7 = iVar7 + -1;
        uVar2 = uVar2 | *puVar8;
        puVar8 = puVar8 + -1;
      } while (iStack_78 <= iVar7);
    }
    if (uVar2 != 0) goto LAB_0052cbd0;
    iVar13 = 1;
    if (auStack_2c4[iStack_78] == 0) {
      puVar8 = auStack_2c4 + iStack_78;
      do {
        puVar8 = puVar8 + -1;
        iVar13 = iVar13 + 1;
      } while (*puVar8 == 0);
    }
    iVar18 = iVar9 + 1;
    iStack_64 = iVar9 + iVar13;
    iVar7 = iStack_64;
    if (iVar18 <= iVar9 + iVar13) {
      puVar17 = auStack_270 + iStack_80 + iVar18;
      puVar14 = auStack_138 + iVar9 + 2;
      uStack_60 = (u32)(iStack_80 < 0);
      puVar11 = (u32 *)((iStack_7c + iVar18) * 4 + iStack_84);
      puVar12 = auStack_270 + iStack_80 + iVar18 + -10;
      do {
        uVar3 = FUN_00531720(*puVar11);
        *puVar17 = uVar3;
        if (uStack_60 == 0) {
          uVar3 = 0;
          puVar16 = puVar12 + 10;
          iVar7 = iStack_80 + 1;
          puVar15 = puStack_90;
          do {
            uVar6 = *puVar15;
            iVar7 = iVar7 + -1;
            puVar15 = puVar15 + 1;
            uVar6 = FUN_00531230(uVar6,*puVar16);
            puVar16 = puVar16 + -1;
            uVar3 = FUN_00531170(uVar3,uVar6);
          } while (iVar7 != 0);
          *puVar14 = uVar3;
        }
        else {
          *puVar14 = 0;
        }
        iVar18 = iVar18 + 1;
        puVar17 = puVar17 + 1;
        puVar11 = puVar11 + 1;
        puVar14 = puVar14 + 1;
        puVar12 = puVar12 + 1;
        iVar7 = iStack_64;
      } while (iVar18 <= iStack_64);
    }
  } while( true );
}
// FUN_0052D108 NONMATCHING
long FUN_0052d108(long param_1,u64 param_2,long param_3)

{
  long lVar1;
  u64 uVar2;
  u64 uVar3;
  u64 uVar4;
  u64 uVar5;
  
  if ((0x3e3fffff < (param_1 >> 0x20 & 0x7fffffffU)) || (lVar1 = FUN_005317d0(0ULL), lVar1 != 0)) {
    uVar2 = FUN_00531230(param_1,param_1);
    uVar3 = FUN_00531230(uVar2,param_1);
    uVar4 = FUN_00531230(uVar2,DAT_007c0138);
    uVar4 = FUN_00531170(uVar4,DAT_007c0140);
    uVar4 = FUN_00531230(uVar2,uVar4);
    uVar4 = FUN_00531170(uVar4,DAT_007c0148);
    uVar4 = FUN_00531230(uVar2,uVar4);
    uVar4 = FUN_00531170(uVar4,DAT_007c0150);
    uVar4 = FUN_00531230(uVar2,uVar4);
    uVar4 = FUN_00531170(uVar4,DAT_007c0158);
    if (param_3 == 0) {
      uVar2 = FUN_00531230(uVar2,uVar4);
      uVar2 = FUN_00531170(uVar2,DAT_007c0160);
      uVar2 = FUN_00531230(uVar3,uVar2);
      param_1 = FUN_00531170(param_1,uVar2);
    }
    else {
      uVar5 = FUN_00531230(param_2,0x3fe0000000000000);
      uVar4 = FUN_00531230(uVar3,uVar4);
      uVar4 = FUN_005311c8(uVar5,uVar4);
      uVar2 = FUN_00531230(uVar2,uVar4);
      uVar2 = FUN_005311c8(uVar2,param_2);
      uVar3 = FUN_00531230(uVar3,DAT_007c0160);
      uVar2 = FUN_005311c8(uVar2,uVar3);
      param_1 = FUN_005311c8(param_1,uVar2);
    }
  }
  return param_1;
}
// FUN_0052D2D8 NONMATCHING
float FUN_0052d2d8(float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = ABS(param_1);
  if ((0x31ffffff < (u32)fVar1) || (fVar3 = DAT_007c0184, (int)param_1 != 0)) {
    fVar4 = param_1 * param_1;
    fVar3 = fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * DAT_007c0188 +
                                                        *((float *)&PTR_DAT_007c018c) + DAT_007c0190) +
                                      DAT_007c0194) + DAT_007c0198) + DAT_007c019c));
    if ((u32)fVar1 < 0x3e99999a) {
      return DAT_007c0184 - (fVar4 * DAT_007c01a0 - (fVar4 * fVar3 - param_1 * param_2));
    }
    fVar2 = 0.28125;
    if ((u32)fVar1 < 0x3f480001) {
      fVar2 = (float)((int)fVar1 - 0x1000000);
    }
    fVar3 = (DAT_007c0184 - fVar2) -
            ((fVar4 * DAT_007c01a0 - fVar2) - (fVar4 * fVar3 - param_1 * param_2));
  }
  return fVar3;
}
// FUN_0052D428 NONMATCHING
u32 FUN_0052d428(float *param_1,u64 param_2,int param_3,int param_4,int param_5,int param_6)
{
  int iVar1;
  bool bVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  u32 uVar6;
  u32 *puVar7;
  int iVar8;
  float *pfVar9;
  float *pfVar10;
  int *piVar11;
  float *pfVar12;
  u32 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  u32 uVar21;
  u32 uStack_1b4;
  u32 auStack_1b0 [20];
  float afStack_160 [20];
  float afStack_110 [19];
  float afStack_c4 [21];
  float *pfStack_70;
  int iStack_6c;
  int iStack_68;
  u32 uStack_64;
  
  iVar17 = param_3 + -3;
  if (param_3 + -3 < 0) {
    iVar17 = param_3 + 4;
  }
  iVar17 = iVar17 >> 3;
  if (iVar17 < 0) {
    iVar17 = 0;
  }
  iVar15 = param_4 + -1;
  iStack_6c = param_5;
  iVar14 = *(int *)(&DAT_007c01a8 + param_5 * 4);
  param_3 = param_3 + iVar17 * -8;
  pfStack_70 = (float *)param_2;
  iStack_68 = param_6;
  iVar16 = param_3 + -8;
  iVar8 = iVar17 - iVar15;
  if (-1 < iVar15 + iVar14) {
    iVar4 = iVar15 + iVar14 + 1;
    piVar11 = (int *)(iVar8 * 4 + param_6);
    pfVar9 = afStack_160;
    do {
      fVar19 = 0.0;
      if (-1 < iVar8) {
        fVar19 = (float)*piVar11;
      }
      *pfVar9 = fVar19;
      iVar4 = iVar4 + -1;
      piVar11 = piVar11 + 1;
      iVar8 = iVar8 + 1;
      pfVar9 = pfVar9 + 1;
    } while (iVar4 != 0);
  }
  iVar4 = 0;
  uStack_64 = (u32)(iVar14 < 0);
  iVar8 = iVar14;
  if (iVar14 >= 0) {
    iVar1 = (int)auStack_1b0 + iVar15 * 4;
    pfVar9 = afStack_c4;
    do {
      pfVar9 = pfVar9 + 1;
      fVar19 = 0.0;
      if (-1 < iVar15) {
        pfVar10 = (float *)(iVar1 + 0x50);
        iVar5 = param_4;
        pfVar12 = param_1;
        do {
          fVar20 = *pfVar12;
          iVar5 = iVar5 + -1;
          fVar18 = *pfVar10;
          pfVar12 = pfVar12 + 1;
          pfVar10 = pfVar10 + -1;
          fVar19 = fVar19 + fVar20 * fVar18;
        } while (iVar5 != 0);
      }
      *pfVar9 = fVar19;
      iVar4 = iVar4 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar4 <= iVar14);
  }
LAB_0052d560:
  iVar4 = iVar8;
  fVar19 = afStack_c4[iVar4 + 1];
  if (0 < iVar4) {
    pfVar9 = afStack_c4 + iVar4;
    puVar7 = auStack_1b0;
    iVar8 = iVar4;
    do {
      iVar8 = iVar8 + -1;
      fVar18 = *pfVar9;
      pfVar9 = pfVar9 + -1;
      fVar20 = fVar19 - (float)(int)(fVar19 * DAT_007c01f4) * DAT_007c01f8;
      fVar19 = fVar18 + (float)(int)(fVar19 * DAT_007c01f4);
      *puVar7 = (int)fVar20;
      puVar7 = puVar7 + 1;
    } while (0 < iVar8);
  }
  iVar8 = 0;
  fVar19 = (float)FUN_005239a8(fVar19,iVar16);
  fVar18 = (float)FUN_0052e7a0(fVar19 * DAT_007c01fc);
  fVar19 = fVar19 - fVar18 * DAT_007c0200;
  uVar21 = (u32)fVar19;
  fVar19 = fVar19 - (float)(int)uVar21;
  if (iVar16 < 1) {
    if (iVar16 == 0) {
      iVar8 = (int)(&uStack_1b4)[iVar4] >> 8;
    }
    else if (DAT_007c0204 <= fVar19) {
      iVar8 = 2;
    }
  }
  else {
    iVar8 = (int)(&uStack_1b4)[iVar4] >> (8U - iVar16 & 0x1f);
    uVar21 = uVar21 + iVar8;
    uVar6 = (&uStack_1b4)[iVar4] - (iVar8 << (8U - iVar16 & 0x1f));
    (&uStack_1b4)[iVar4] = uVar6;
    iVar8 = (int)uVar6 >> (7U - iVar16 & 0x1f);
  }
  if (0 < iVar8) {
    uVar21 = uVar21 + 1;
    bVar2 = false;
    puVar7 = auStack_1b0;
    iVar1 = iVar4;
    if (0 < iVar4) {
      do {
        uVar6 = *puVar7;
        uVar13 = 0xff - uVar6;
        if (bVar2) {
LAB_0052d694:
          *puVar7 = uVar13;
        }
        else {
          uVar13 = 0x100 - uVar6;
          if (uVar6 != 0) {
            bVar2 = true;
            goto LAB_0052d694;
          }
        }
        iVar1 = iVar1 + -1;
        puVar7 = puVar7 + 1;
      } while (iVar1 != 0);
    }
    if (0 < iVar16) {
      if (iVar16 == 1) {
        uVar6 = (&uStack_1b4)[iVar4] & 0x7f;
      }
      else {
        if (iVar16 != 2) goto LAB_0052d6c0;
        uVar6 = (&uStack_1b4)[iVar4] & 0x3f;
      }
      (&uStack_1b4)[iVar4] = uVar6;
    }
LAB_0052d6c0:
    if ((iVar8 == 2) && (fVar19 = DAT_007c0208 - fVar19, bVar2)) {
      fVar18 = (float)FUN_005239a8(iVar16);
      fVar19 = fVar19 - fVar18;
    }
  }
  iVar1 = iVar4 + -1;
  if (fVar19 != 0.0) goto LAB_0052db6c;
  uVar6 = 0;
  if (iVar14 <= iVar1) {
    uVar6 = 0;
    puVar7 = (u32 *)((int)auStack_1b0 + iVar1 * 4);
    do {
      iVar1 = iVar1 + -1;
      uVar6 = uVar6 | *puVar7;
      puVar7 = puVar7 + -1;
    } while (iVar14 <= iVar1);
  }
  if (uVar6 == 0) {
    iVar8 = 1;
    if (*(int *)((int)auStack_1b0 + (iVar14 + -1) * 4) == 0) {
      puVar7 = &uStack_1b4 + iVar14;
      do {
        puVar7 = puVar7 + -1;
        iVar8 = iVar8 + 1;
      } while (*puVar7 == 0);
    }
    iVar8 = iVar4 + iVar8;
    iVar1 = iVar4 + 1;
    if (iVar1 <= iVar8) {
      pfVar9 = afStack_160 + iVar15 + iVar1;
      iVar5 = (int)auStack_1b0 + (iVar15 + iVar1) * 4;
      pfVar12 = afStack_c4 + iVar4 + 2;
      piVar11 = (int *)((iVar17 + iVar1) * 4 + iStack_68);
      do {
        fVar19 = 0.0;
        *pfVar9 = (float)*piVar11;
        if (-1 < iVar15) {
          pfVar3 = (float *)(iVar5 + 0x50);
          pfVar10 = param_1;
          iVar4 = param_4;
          do {
            fVar20 = *pfVar10;
            iVar4 = iVar4 + -1;
            fVar18 = *pfVar3;
            pfVar10 = pfVar10 + 1;
            pfVar3 = pfVar3 + -1;
            fVar19 = fVar19 + fVar20 * fVar18;
          } while (iVar4 != 0);
        }
        *pfVar12 = fVar19;
        iVar1 = iVar1 + 1;
        pfVar9 = pfVar9 + 1;
        piVar11 = piVar11 + 1;
        pfVar12 = pfVar12 + 1;
        iVar5 = iVar5 + 4;
      } while (iVar1 <= iVar8);
    }
    goto LAB_0052d560;
  }
  if (fVar19 == 0.0) {
    iVar4 = iVar4 + -1;
    piVar11 = (int *)((int)auStack_1b0 + iVar4 * 4);
    param_3 = param_3 + -0x10;
    iVar17 = *piVar11;
    while (iVar17 == 0) {
      piVar11 = piVar11 + -1;
      iVar4 = iVar4 + -1;
      param_3 = param_3 + -8;
      iVar17 = *piVar11;
    }
  }
  else {
LAB_0052db6c:
    fVar19 = (float)FUN_005239a8(fVar19,-iVar16);
    if (DAT_007c01f8 <= fVar19) {
      iVar17 = iVar4 * 4;
      iVar4 = iVar4 + 1;
      *(int *)((int)auStack_1b0 + iVar17) =
           (int)(fVar19 - (float)(int)(fVar19 * DAT_007c01f4) * DAT_007c01f8);
      *(int *)((int)auStack_1b0 + iVar4 * 4) = (int)(float)(int)(fVar19 * DAT_007c01f4);
    }
    else {
      *(int *)((int)auStack_1b0 + iVar4 * 4) = (int)fVar19;
      param_3 = iVar16;
    }
  }
  fVar19 = (float)FUN_005239a8(DAT_007c0208,param_3);
  if (-1 < iVar4) {
    piVar11 = (int *)((int)auStack_1b0 + iVar4 * 4);
    iVar17 = iVar4;
    do {
      iVar17 = iVar17 + -1;
      fVar18 = fVar19 * (float)*piVar11;
      fVar19 = fVar19 * DAT_007c01f4;
      piVar11[0x3c] = (int)fVar18;
      piVar11 = piVar11 + -1;
    } while (-1 < iVar17);
    if (-1 < iVar4) {
      iVar15 = (int)auStack_1b0 + iVar4 * 4;
      iVar17 = iVar4;
      do {
        fVar19 = 0.0;
        iVar16 = 0;
        if (uStack_64 == 0) {
          iVar1 = iVar4 - iVar17;
          if (-1 < iVar1) {
            pfVar12 = (float *)(iVar15 + 0xf0);
            fVar18 = DAT_007c01b8;
            pfVar9 = (float *)&DAT_007c01b8;
            while( true ) {
              iVar16 = iVar16 + 1;
              fVar20 = *pfVar12;
              pfVar9 = pfVar9 + 1;
              pfVar12 = pfVar12 + 1;
              fVar19 = fVar19 + fVar18 * fVar20;
              if ((iVar14 < iVar16) || (iVar1 < iVar16)) break;
              fVar18 = *pfVar9;
            }
          }
        }
        else {
          iVar1 = iVar4 - iVar17;
        }
        iVar15 = iVar15 + -4;
        iVar17 = iVar17 + -1;
        afStack_110[iVar1] = fVar19;
      } while (-1 < iVar17);
    }
  }
  if (iStack_6c < 3) {
    if (iStack_6c < 1) {
      if (iStack_6c == 0) {
        fVar19 = 0.0;
        if (-1 < iVar4) {
          pfVar9 = afStack_110 + iVar4;
          do {
            iVar4 = iVar4 + -1;
            fVar19 = fVar19 + *pfVar9;
            pfVar9 = pfVar9 + -1;
          } while (-1 < iVar4);
        }
        if (iVar8 != 0) {
          fVar19 = -fVar19;
        }
        *pfStack_70 = fVar19;
      }
      goto LAB_0052d974;
    }
    afStack_110[1] = 0.0;
    if (-1 < iVar4) {
      pfVar9 = afStack_110 + iVar4;
      iVar17 = iVar4;
      do {
        iVar17 = iVar17 + -1;
        afStack_110[1] = afStack_110[1] + *pfVar9;
        pfVar9 = pfVar9 + -1;
      } while (-1 < iVar17);
    }
    fVar19 = afStack_110[1];
    if (iVar8 != 0) {
      fVar19 = -afStack_110[1];
    }
    *pfStack_70 = fVar19;
    afStack_110[1] = afStack_110[0] - afStack_110[1];
    if (0 < iVar4) {
      pfVar9 = afStack_110;
      do {
        pfVar9 = pfVar9 + 1;
        iVar4 = iVar4 + -1;
        afStack_110[1] = afStack_110[1] + *pfVar9;
      } while (iVar4 != 0);
    }
    if (iVar8 != 0) {
      afStack_110[1] = -afStack_110[1];
    }
  }
  else {
    if (iStack_6c != 3) goto LAB_0052d974;
    if (0 < iVar4) {
      iVar14 = (int)auStack_1b0 + iVar4 * 4;
      iVar17 = iVar4;
      do {
        fVar19 = *(float *)(iVar14 + 0x9c);
        iVar17 = iVar17 + -1;
        fVar18 = fVar19 + *(float *)(iVar14 + 0xa0);
        *(float *)(iVar14 + 0x9c) = fVar18;
        *(float *)(iVar14 + 0xa0) = *(float *)(iVar14 + 0xa0) + (fVar19 - fVar18);
        iVar14 = iVar14 + -4;
      } while (0 < iVar17);
    }
    if (1 < iVar4) {
      iVar14 = (int)auStack_1b0 + iVar4 * 4;
      iVar17 = iVar4;
      do {
        fVar19 = *(float *)(iVar14 + 0x9c);
        iVar17 = iVar17 + -1;
        fVar18 = fVar19 + *(float *)(iVar14 + 0xa0);
        *(float *)(iVar14 + 0x9c) = fVar18;
        *(float *)(iVar14 + 0xa0) = *(float *)(iVar14 + 0xa0) + (fVar19 - fVar18);
        iVar14 = iVar14 + -4;
      } while (1 < iVar17);
    }
    fVar19 = 0.0;
    if (1 < iVar4) {
      pfVar9 = afStack_110 + iVar4;
      do {
        iVar4 = iVar4 + -1;
        fVar19 = fVar19 + *pfVar9;
        pfVar9 = pfVar9 + -1;
      } while (1 < iVar4);
    }
    if (iVar8 == 0) {
      pfStack_70[2] = fVar19;
      *pfStack_70 = afStack_110[0];
      pfStack_70[1] = afStack_110[1];
      goto LAB_0052d974;
    }
    afStack_110[1] = -afStack_110[1];
    pfStack_70[2] = -fVar19;
    *pfStack_70 = -afStack_110[0];
  }
  pfStack_70[1] = afStack_110[1];
LAB_0052d974:
  return uVar21 & 7;
}
// FUN_0052DC48 NONMATCHING
float FUN_0052dc48(float param_1,float param_2,long param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  if ((0x31ffffff < (u32)ABS(param_1)) || ((int)param_1 != 0)) {
    fVar3 = param_1 * param_1;
    fVar2 = fVar3 * param_1;
    fVar1 = fVar3 * (fVar3 * (fVar3 * (fVar3 * DAT_007c022c + DAT_007c0230) + DAT_007c0234) +
                    DAT_007c0238) + DAT_007c023c;
    if (param_3 == 0) {
      return param_1 + fVar2 * (fVar3 * fVar1 + DAT_007c0240);
    }
    param_1 = param_1 - ((fVar3 * (param_2 * DAT_007c0244 - fVar2 * fVar1) - param_2) -
                        fVar2 * DAT_007c0240);
  }
  return param_1;
}
// FUN_0052DD40 NONMATCHING
float FUN_0052dd40(float param_1,float param_2,long param_3)

{
  u8 *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  puVar1 = (u8 *)((u32)param_1 & 0x7fffffff);
  if (((u8 *)&DAT_007c0234 < puVar1) || ((int)param_1 != 0)) {
    if (puVar1 < (u8 *)0x3f2ca140) {
      fVar3 = param_1 * param_1;
      fVar2 = param_1;
    }
    else {
      fVar2 = param_1;
      if ((int)param_1 < 0) {
        fVar2 = -param_1;
        param_2 = -param_2;
      }
      fVar2 = (DAT_007c0294 - fVar2) + (DAT_007c0298 - param_2);
      param_2 = 0.0;
      fVar3 = fVar2 * fVar2;
    }
    fVar4 = fVar3 * fVar3;
    fVar4 = fVar3 * fVar2 * DAT_007c02cc +
            param_2 + fVar3 * (fVar3 * fVar2 *
                               (fVar3 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * DAT_007c029c +
                                                                            DAT_007c02a4) +
                                                                   DAT_007c02ac) + DAT_007c02b4) +
                                                 DAT_007c02bc) + DAT_007c02c4) +
                               fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * DAT_007c02a0 +
                                                                  DAT_007c02a8) + DAT_007c02b0) +
                                                DAT_007c02b8) + DAT_007c02c0) + DAT_007c02c8) +
                              param_2);
    fVar3 = fVar2 + fVar4;
    if (puVar1 < (u8 *)0x3f2ca140) {
      param_1 = fVar3;
      if (param_3 != 1) {
        param_1 = (float)((u32)(DAT_007c0290 / fVar3) & 0xfffff000);
        param_1 = param_1 + (DAT_007c0290 / fVar3) *
                            (param_1 * (fVar4 - ((float)((u32)fVar3 & 0xfffff000) - fVar2)) +
                            param_1 * (float)((u32)fVar3 & 0xfffff000) + DAT_007c028c);
      }
    }
    else {
      fVar5 = (float)(int)param_3;
      fVar2 = fVar2 - ((fVar3 * fVar3) / (fVar3 + fVar5) - fVar4);
      param_1 = (float)(int)(1 - ((int)param_1 >> 0x1e & 2U)) * (fVar5 - (fVar2 + fVar2));
    }
  }
  else if (puVar1 == (u8 *)0x0 && (int)param_3 == -1) {
    fVar2 = (float)FUN_0052e788();
    param_1 = DAT_007c028c / fVar2;
  }
  else if (param_3 != 1) {
    param_1 = DAT_007c0290 / param_1;
  }
  return param_1;
}
// FUN_0052E038 NONMATCHING
void FUN_0052e038(long param_1)

{
  long lVar1;
  u32 uVar2;
  long lStack_20;
  u64 uStack_18;
  
  uVar2 = param_1 >> 0x20 & 0x7fffffff;
  if (uVar2 < 0x3fe921fc) {
    uStack_18 = 0;
LAB_0052e068:
    FUN_0052c478(param_1,uStack_18);
    return;
  }
  lVar1 = param_1;
  if (uVar2 < 0x7ff00000) {
    uVar2 = (u64)(FUN_0052a3f0(param_1,&lStack_20));
    uVar2 = uVar2 & 3;
    if (uVar2 == 1) {
      lVar1 = FUN_0052d108(lStack_20,uStack_18,1);
    }
    else {
      if (uVar2 < 2) {
        param_1 = lStack_20;
        if (uVar2 == 0) goto LAB_0052e068;
LAB_0052e0b8:
        FUN_0052d108(lStack_20,uStack_18,1);
        return;
      }
      if (uVar2 != 2) goto LAB_0052e0b8;
      lVar1 = FUN_0052c478(lStack_20,uStack_18);
    }
    param_1 = 0;
  }
  FUN_005311c8(param_1,lVar1);
  return;
}
// FUN_0052E118 NONMATCHING
u32 FUN_0052e118(u32 param_1)
{
  return param_1;
}
// FUN_0052E148 NONMATCHING
u32 FUN_0052e148(u32 param_1)
{
  u64 uVar1;
  long lVar2;
  u32 uVar3;
  u32 uVar4;
  int iVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  u32 uVar10;
  
  uVar6 = (long)param_1 >> 0x20;
  iVar5 = (int)(param_1 >> 0x20);
  uVar9 = iVar5 >> 0x14 & 0x7ff;
  uVar7 = (u32)param_1;
  uVar4 = uVar9 - 0x3ff;
  uVar8 = (u32)(int)uVar7;
  if ((int)uVar4 < 0x14) {
    if ((int)uVar4 < 0) {
      uVar1 = FUN_00531170(param_1,DAT_007c02d8);
      lVar2 = FUN_005316d0(0,uVar1);
      uVar3 = uVar6 << 0x20;
      if (-1 < lVar2) goto LAB_0052e1c4;
      if ((long)uVar6 < 0) {
        uVar3 = uVar6 << 0x20;
        if ((uVar6 & 0x7fffffff) == 0 && uVar8 == 0) goto LAB_0052e1c4;
        uVar6 = 0xffffffffbff00000;
        uVar8 = 0;
      }
      else {
        uVar8 = 0;
        uVar6 = 0;
      }
    }
    else {
      uVar10 = (u32)(0xfffff >> (uVar4 & 0x1f));
      if ((uVar6 & uVar10) == 0 && uVar8 == 0) {
        return param_1;
      }
      uVar1 = FUN_00531170(param_1,DAT_007c02d8);
      lVar2 = FUN_005316d0(0,uVar1);
      uVar3 = uVar6 << 0x20;
      if (-1 < lVar2) goto LAB_0052e1c4;
      if ((long)uVar6 < 0) {
        uVar6 = (u32)(iVar5 + (0x100000 >> (uVar4 & 0x1f)));
      }
      uVar8 = 0;
      uVar6 = uVar6 & ~uVar10;
    }
  }
  else {
    if (0x33 < (int)uVar4) {
      if (uVar4 != 0x400) {
        return param_1;
      }
      uVar6 = FUN_00531170(param_1,param_1);
      return uVar6;
    }
    uVar9 = 0xffffffff >> (uVar9 - 0x413 & 0x1f);
    if ((uVar7 & uVar9) == 0) {
      return param_1;
    }
    uVar1 = FUN_00531170(param_1,DAT_007c02d8);
    lVar2 = FUN_005316d0(0,uVar1);
    uVar3 = uVar6 << 0x20;
    if (-1 < lVar2) goto LAB_0052e1c4;
    uVar3 = uVar8;
    if ((long)uVar6 < 0) {
      if (uVar4 == 0x14) {
        iVar5 = iVar5 + 1;
      }
      else {
        uVar3 = (u32)(int)(uVar7 + (1 << (0x34 - uVar4 & 0x1f)));
        iVar5 = iVar5 + (u32)(uVar3 < uVar8);
      }
      uVar6 = (u32)iVar5;
    }
    uVar8 = uVar3 & ~(long)(int)uVar9;
  }
  uVar3 = uVar6 << 0x20;
LAB_0052e1c4:
  return uVar3 | uVar8 & 0xffffffff;
}
// FUN_0052E328 NONMATCHING
void FUN_0052e328(long param_1)

{
  long lVar1;
  u64 uVar2;
  u32 uVar3;
  long lStack_20;
  u64 uStack_18;
  
  uVar3 = param_1 >> 0x20 & 0x7fffffff;
  if (uVar3 < 0x3fe921fc) {
    uStack_18 = 0;
    uVar2 = 0;
LAB_0052e35c:
    FUN_0052d108(param_1,uStack_18,uVar2);
    return;
  }
  lVar1 = param_1;
  if (0x7fefffff < uVar3) goto LAB_0052e3bc;
  uVar3 = (u64)(FUN_0052a3f0(param_1,&lStack_20));
  uVar3 = uVar3 & 3;
  if (uVar3 == 1) {
    FUN_0052c478(lStack_20,uStack_18);
    return;
  }
  if (uVar3 < 2) {
    if (uVar3 == 0) {
      uVar2 = 1;
      param_1 = lStack_20;
      goto LAB_0052e35c;
    }
LAB_0052e3ac:
    lVar1 = FUN_0052c478(lStack_20,uStack_18);
  }
  else {
    if (uVar3 != 2) goto LAB_0052e3ac;
    lVar1 = FUN_0052d108(lStack_20,uStack_18,1);
  }
  param_1 = 0;
LAB_0052e3bc:
  FUN_005311c8(param_1,lVar1);
  return;
}
extern u32 FUN_00530598(long param_1, long param_2, long param_3);
// FUN_00530578 NONMATCHING
u64 FUN_00530578(u64 param_1, u64 param_2)
{
  u64 auStack_20[2];
  FUN_00530598(param_1, param_2, (long)auStack_20);
  return auStack_20[0];
}
