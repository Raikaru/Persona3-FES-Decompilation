#include "temporary.h"

/* Retail startup stubs at the head of the text segment (0x100008/0x100218).
 * The entry function is handwritten MMI assembly in retail; the C forms stay
 * NONMATCHING and exist so every executable byte has a C-owned home. */

extern u8 D_007CDE80[];
extern u8 D_009ACC80[];
extern u32 D_0095C280[];
extern void func_0050d658(...);
extern void func_005033e0(...);
extern void func_0051f6a0(...);
extern void func_0050da58(s32 status);
extern void FlushCache(s32 mode);
extern int main(int argc, char* argv[]);

// FUN_00100008 NONMATCHING
void func_00100008(void)
{
    u8* cursor;

    cursor = D_007CDE80;
    while (((uintptr_t)cursor & 0xf) != 0)
    {
        *cursor++ = 0;
    }
    while (cursor + 0x10 <= D_009ACC80)
    {
        memset(cursor, 0, 0x10);
        cursor += 0x10;
    }
    while (cursor < D_009ACC80)
    {
        *cursor++ = 0;
    }

    func_0050d658(0, 0, 0, 0, 0, 0, (void*)0x009ACC80,
                  (void*)-1, (void*)0x000A0000, (void*)0x0095C280,
                  (void*)0x00100220, 0, 0, 0, 0);
    FlushCache(0);
    func_005033e0(0);
    func_0051f6a0((void*)(uintptr_t)main(
        (s32)D_0095C280[0], (char**)&D_0095C280[1]));
}

// FUN_00100218 NONMATCHING
void func_00100218(s32 status)
{
    func_0050da58(status);
}
