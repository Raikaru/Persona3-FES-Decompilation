#ifndef OP_FADE_MID_H
#define OP_FADE_MID_H

#include "Utils.h"

/* These GP slots contain the live work pointers used by the opening/ending
 * result flow.  Keeping them as lvalues preserves the retail ownership when
 * the state is shared by separate translation units. */
#define gOpWorkC0 (*(u32 **)(uintptr_t)0x007ce3c0)
#define gOpWorkC4 (*(u32 **)(uintptr_t)0x007ce3c4)
#define gOpWorkC8 (*(u32 **)(uintptr_t)0x007ce3c8)
#define gOpWorkCC (*(u32 **)(uintptr_t)0x007ce3cc)
#define gOpWorkD0 (*(u32 **)(uintptr_t)0x007ce3d0)

void func_00275050(s32 index);
s32 func_002751e0(void);
u32 func_00275370(void);
void func_002753c0(void);
void func_00275440(void);
void func_00275520(void);
void func_002755d0(u64 value);
u32 func_00275670(void);
u64 func_002756c0(void);
u64 func_002757a0(void);
void func_002757e0(void *resource);
void func_002758e0(u32 arg0, u16 arg1);
void func_00275a70(u32 *work);
void func_00275a80(void);
void func_00275a90(void);
void func_00275bc0(void);
void func_00275cb0(void);
void func_002760f0(void);
void brLvpnlStartEntranceAnimation(void);
void brLvpnlDisableDrawing(void);
void brLvpnlEnableDrawing(void);
void func_00276910(u32 *work);
void func_00276920(void);
void func_00276930(void);
void func_002769c0(u32 arg0, u16 arg1);
void func_00276a80(void);
void func_00276b10(void);
void func_00276ba0(void);
void func_00276c30(void);
u32 func_00276cc0(void);
void func_00276d10(u32 *work);
void func_00276d30(void);
void func_00276d90(void);
void func_00277070(void);
void func_002770f0(void);
void func_002771f0(void);
void func_00278550(void);

#endif
