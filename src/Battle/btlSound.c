#include "Battle/btlSound.h"
#include "Battle/battle.h"
#include "Battle/btlAction.h"
#include "Battle/btlUnit.h"
#include "Battle/btlPacket.h"
#include "Main/g_data.h"
#include "Main/Battle/Data/datCalc.h"
#include "h_snd.h"
#include "h_cdvd.h"
#include "temporary.h"

#pragma alias FUN_002ffd70_y2 FUN_002ffd70
#pragma alias FUN_002ffdf0_y2 FUN_002ffdf0
#pragma alias FUN_00300580_y2 FUN_00300580
#pragma alias func_001016b0_y2 func_001016b0
#pragma alias func_002ffbc0_y2 func_002ffbc0
#pragma alias func_00300580_y2 func_00300580
#pragma alias func_0030b5a0_y2 func_0030b5a0
#pragma alias DAT_00960178_y2 DAT_00960178
#pragma alias iGpffffb6fc_y2 iGpffffb6fc_y2
#pragma alias FUN_0016f190_y2 FUN_0016f190_y2
#pragma alias FUN_0027ec10_y2 FUN_0027ec10_y2
#pragma alias func_002ddc10_y2 func_002ddc10_y2
#pragma alias FUN_002ffbc0_y2 FUN_002ffbc0_y2
#pragma alias FUN_0030b5a0_y2 FUN_0030b5a0_y2
#pragma alias func_00100ec0_y2 func_00100ec0_y2
#pragma alias func_00102100_y2 func_00102100_y2
#pragma alias func_002d4e10_y2 func_002d4e10_y2
#pragma alias func_002ffd70_y2 func_002ffd70_y2
#pragma alias func_002ffdf0_y2 func_002ffdf0_y2
#pragma alias func_00523ac8_y2 func_00523ac8_y2
#pragma alias func_00524388_y2 func_00524388_y2



/* Recovered battle-misc support prelude */
typedef int (*code)(...);
extern s32 FUN_0010a500(s16 param);
void FUN_002dd8e0(u32 param_1);
void FUN_002dd960(u32 param_1);
u32 FUN_002dddc0(int param_1);
u32 FUN_002ddf10(int param_1);
u32 FUN_002de030(int param_1);
u32 FUN_002de150(int param_1);
u32 FUN_002de2a0(int param_1);
u32 FUN_002de3c0(int param_1);
u32 FUN_002de4e0(int param_1);
u32 FUN_002ded60(int param_1);
u32 FUN_002defe0(int param_1);
u32 FUN_002e0350(int param_1);
u32 FUN_002e0540(int param_1);
int FUN_002e0620(int param_1,int param_2);
u32 FUN_002e0f70(int param_1, int param_2, int param_3);
u32 FUN_002e12d0(int param_1);
u32 FUN_002e1500(int param_1,u32 param_2);
u32 FUN_002e1bf0(int param_1);
u32 FUN_002e1cd0(int param_1);
u32 FUN_002e1df0(int param_1);
u32 FUN_002e1f10(int param_1);
u32 FUN_002e2030(int param_1);
u32 FUN_002e2110(int param_1);
u32 FUN_002e22a0(int param_1);
u32 FUN_002e2410(int param_1);
u32 FUN_002e2560(int param_1);
u32 FUN_002e2630(int param_1);
u32 FUN_002e2680(int param_1);
u32 FUN_002e2920(int *param_1);
void FUN_002e2a10(void);
u32 FUN_002e2a60(int *param_1);
extern char gp0xffff9c90[5];
extern char DAT_00697bb0[15];
extern char DAT_00697bc0[];
extern u32 DAT_00697be0;
extern u32 DAT_00697be4;
extern u32 DAT_00697be8;
extern u8 DAT_00697BE0_abs[];
#pragma alias DAT_00697BE0_abs DAT_00697BE0
extern u8 DAT_00697BE8_abs[];
#pragma alias DAT_00697BE8_abs DAT_00697BE8
extern u8 DAT_00697BEC_abs[];
#pragma alias DAT_00697BEC_abs DAT_00697BEC
extern u8 DAT_00697BF4_abs[];
#pragma alias DAT_00697BF4_abs DAT_00697BF4
extern u8 DAT_00697BF8_abs[];
#pragma alias DAT_00697BF8_abs DAT_00697BF8
extern u8 DAT_00697BFC_abs[];
#pragma alias DAT_00697BFC_abs DAT_00697BFC
extern u8 DAT_00697be4_abs[];
#pragma alias DAT_00697be4_abs DAT_00697be4
extern u32 DAT_00697bec;
extern u32 DAT_00697bf4;
extern u32 DAT_00697bf8;
extern u32 DAT_00697bfc;
extern u32 DAT_00697c00;
extern u8 DAT_00697c00_abs[];
#pragma alias DAT_00697c00_abs DAT_00697c00
extern code DAT_00697c10[];
extern u8* DAT_007ce3ec;
extern code DAT_00960178_y2;
#pragma alias DAT_00960178_abs DAT_00960178_y2
extern code DAT_00960178_abs[];
extern char LAB_002dd8b0[];
extern char LAB_002dd930[];
extern code* PTR_LAB_007b87e0;
extern int iGpffffb6fc;

extern u32 func_00523ac8(void* buffer, const void* format, ...);
extern u32 func_00524388(const char* text);
extern u32 func_0053c268(s32 channel);
extern void* (*jtbl_00960178)(u32 size, u32 heap);
extern s32 func_0016f190(u32 flag);
extern u32 func_00357fd0(void* state);
extern u32 func_00300580_y2(void* unit, u32 flags);
extern u32 func_0030b5a0_y2(void* unit, u32 flags);
extern u32 func_002ffd70(void* unit);
extern u32 func_0017d800(void);
extern u32 func_002ffbc0_y2(u32 max);
extern u32 func_002ffdf0(void* unit);
extern u32 func_002d4e10(u32 genusMask, u32 flags);
extern void func_0031f6d0(void* model, u16 a, u16 b, u16 c);
extern void func_001024a0(void* source, const char* path, s32 flags, void* callback);
extern void* func_001016b0_y2(void* resource);
extern void* func_00102100(void* resource, s32 index, u32* size);
extern void func_00100ec0(void* resource);
extern u32 effMiscRand(void* state);
extern s32 DAT_00697BE0;
extern s32 DAT_00697BE4;
extern s32 DAT_00697BE8;
extern s32 DAT_00697BEC;
extern s32 DAT_00697BF4;
extern s32 DAT_00697BF8;
extern s32 DAT_00697BFC;
extern s32 DAT_00697C00;
extern s32 DAT_00697C10[];
extern s32 DAT_00697BD8[];
extern s32 DAT_007CE4FC;
extern s32 DAT_007CE500;
extern s32 iGpffffb80c;

typedef struct BtlSoundThreeCueWork
{
    u16 channel;
    u16 pad;
    u32 streamData;
    u32 parameter;
} BtlSoundThreeCueWork;
typedef struct BtlSoundThreeCueWorkView
{
    s16 channel;
    void* streamData;
    s16 parameter;
} BtlSoundThreeCueWorkView;
#include "Battle/btlTarget.h"
#include "rw/rtquat.h"
#include "Script/scrScriptProcess.h"
#include "Script/scr.h"
#include "Kernel/Kwln/kwln.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Battle/btlVoice.h"
#include "Battle/btlBoss.h"
#include "Main/Battle/Data/datPersona.h"
#include "Kosaka/k_assert.h"
#include "libm.h"
extern u32 func_002e4910();
#define BTLT_A8(ptr, offset) (*(u8*)((u8*)(ptr) + (offset)))
#define BTLT_A16(ptr, offset) (*(u16*)((u8*)(ptr) + (offset)))
#define BTLT_AS16(ptr, offset) (*(s16*)((u8*)(ptr) + (offset)))
#define BTLT_A32(ptr, offset) (*(u32*)((u8*)(ptr) + (offset)))
#define BTLT_D16(ptr, offset) (*(u16*)((u8*)(ptr) + (offset)))
#define BTLT_T8(base, offset) (*(u8*)(DAT_007ce3f8 + (base) + (offset)))
#define BTLT_T32(base, offset) (*(u32*)(DAT_007ce3f8 + (base) + (offset)))
#define BTLT_B32(offset) (*(u32*)(DAT_007ce3ec + (offset)))
#define BTLT_BS16(offset) (*(s16*)(DAT_007ce3ec + (offset)))
typedef struct BtlTargetPacketWork
{
    BtlAction *source;
    BtlAction *action;
    u8 data[0x1c];
    u16 effect;
    u16 targetFlags;
} BtlTargetPacketWork;
typedef struct BtlTargetScriptWork
{
    BtlAction* action;
    s32 procedureIndex;
    u32 started;
    ScrHeader* script;
} BtlTargetScriptWork;
typedef struct BtlTargetStatePacketWork
{
    BtlAction* action;
    u8 flags;
} BtlTargetStatePacketWork;
typedef struct BtlTargetActionPacketWork
{
    BtlAction* action;
} BtlTargetActionPacketWork;
void FUN_002dc550(BtlAction* action, u32 flags);
extern u16 FUN_002bff60(BtlAction* action, BtlTarget* target,
                         u16 commandId, u32 flags);
extern u8* iGpffffb6fc_y2;
extern f32 fGpffff827c;
extern u8 DAT_00697880[];
extern f32 DAT_006978c0[];
extern u8* DAT_007ce42c;
extern BtlCommandRecord* iGpffffb710;
extern u32 DAT_007e094e;
extern u32 DAT_007e0958;
extern u16 DAT_007e094e_u16[];
extern u16 DAT_007e0958_u16[];
extern u8* gp0xffff9c60;
extern u8* gp0xffff9c68;
extern u8* gp0xffff9c70;
extern u8* gp0xffff9c78;
extern u32 uGpffffb7dc;
extern u32 uGpffffb7e0;
extern f32 fGpffff80d0;
extern void FUN_00521408(void* dst, s32 value, u32 size);
extern void FUN_0010A4E0(s32, s32, s32, s32);
extern void FUN_001FF310(void);
extern void FUN_001FF330(void);
extern s32 FUN_002FD7C0(void);
extern void FUN_002C6A00(void*, void*, u16);
extern s32 FUN_002FFBC0(s32);
extern void FUN_004C6AC0(f32*);
extern f32 FUN_004c6af0(f32*);
extern f32 FUN_004C6B20(RwV2d* dst, const RwV2d* src);
extern void FUN_004C6BE0(f32*, u64, s32);
extern f32 FUN_0052E9E8(f32);
extern f32 FUN_0052EA18(f32, f32);
extern void FUN_004BDDE0(u64, const void*, f32, s32);
extern void* FUN_0027EC10(s32, s32);
extern u32 FUN_0035C090(u32, u64);
extern s32 FUN_00195460();
extern s32 FUN_00198590(void);
extern u16 FUN_002d4cf0(u16 mask, u32 badStatus);
extern u16 FUN_002d4e10(u16 mask, u32 badStatus);
extern u32 FUN_002db480(void);
extern u32 FUN_002db690(void);
extern void FUN_002db650(u32 value);
extern u32 FUN_002db9f0(u16 command, u32 param);
extern void FUN_002dba80(void);
extern u8* iGpffffb720;
extern const char D_00697B18[];
extern const char* D_00697B90[];
extern s32 FUN_002daa20(BtlAction*, u16, s32, s32, s32);
typedef s32 (*BtlTargetEffectFn)(BtlAction*, s32, s32, s32);
extern u8* iGpffffb7b8;
extern BtlTargetEffectFn D_006978F0[];
void FUN_002db2a0(u32 param_1);
extern u8 D_00697980[];
extern u8 D_00697A50[];
extern u64 FUN_002FF790(void* genusBase);
extern u32 FUN_0030FC40(u32 command, DatUnit* unit_a, DatUnit* unit_b,
                        u32 param_4, u32 param_5);
extern void func_003c8f20(void);
extern void func_003c8f40(void);
extern void func_003c8f70(void);
extern void func_003c8fa0(void);
extern void func_003c8da0(u32 flags);
extern u32 func_00306e80(DatUnit* unit, u16 mode);
extern u8 DAT_00697730[];
extern u8 DAT_006977D0[];
extern s32 (*PTR_FUN_0069721c)(void*, s32);
extern s32 (*PTR_FUN_00697294)(void*, s32);
extern s32 (*PTR_FUN_006973cc)(void*, s32);
extern s32 (*PTR_FUN_006975e0[])(void*, u32);
extern s32 (*PTR_FUN_0069721c_abs[])(void*, s32);
extern s32 (*PTR_FUN_00697294_abs[])(void*, s32);
extern s32 (*PTR_FUN_006973cc_abs[])(void*, s32);
extern u8* DAT_007ce484;
extern u8* DAT_007ce488;
extern void btlTargetBuildBounds(u8* work, s16 start, s16 end, f32 distance);
extern s32 FUN_002d2470_call(f32 tolerance, const f32* a, const f32* b,
                             const f32* point);
typedef u8 undefined1;
typedef u16 ushort;
typedef u8 byte;
typedef u32 uint;
typedef u16 undefined2;
typedef u32 undefined4;
typedef u64 undefined8;
typedef u64 ulong;
typedef u8 bool;
#define false 0
#define true 1
extern u64 FUN_0016c4f0();
extern u64 FUN_0016c5f0();
extern u64 FUN_0016c920();
extern u64 FUN_0016c970();
extern u64 FUN_0016dd60();
extern u64 FUN_0016f190_y2();
extern u64 FUN_00170670();
extern u64 FUN_001706c0();
extern u64 FUN_00170710();
extern u64 FUN_00170760();
extern u64 FUN_00170860();
extern u64 FUN_00174800();
extern u64 FUN_00174a90();
extern u64 FUN_00175360();
extern u64 FUN_00175ca0();
extern u64 FUN_0017b170();
extern u64 FUN_0027ec10_y2();
extern u64 FUN_0029a1d0();
extern u64 FUN_002ddc10();
extern u32 func_002ddc10_y2(u32 unitId);
extern u64 FUN_002ffbc0_y2();
extern u64 FUN_002ffcc0();
extern u32 FUN_002ffcc0_u32(u32 unit);
extern u64 FUN_002ffd70();
extern u64 FUN_002ffdf0();
extern u64 FUN_00300410();
extern u64 FUN_00300480();
extern u64 FUN_00300580();
extern u32 FUN_00300580_u32(u32 unit, u32 status);
extern u64 FUN_003005e0();
extern u64 FUN_00301ca0();
extern void FUN_00302c50(u32 datUnit);
extern u32 FUN_003083f0(u32 param_1, u32 param_2);
extern u64 FUN_0030b5a0_y2();
extern u64 FUN_0030b5e0();
extern u8* DAT_007ce3f8;
extern u8* DAT_007ce410;
extern u8* iGpffffb6fc_y2;
extern u8* iGpffffb720;
extern u16 FUN_001706c0_u16(s16 pcId, s16 index);
extern void FUN_00170710_void(s16 pcId, s16 index, s16 value);
extern u16 FUN_00170760_u16(s16 pcId, s16 index);
extern void FUN_00170860_void(s16 pcId, s16 index, u16 value);
extern void FUN_00300410_void(DatUnit* unit, s32 delta);
extern void FUN_00300480_void(DatUnit* unit, s32 delta);
typedef struct BtlTargetMessage
{
    s16 messageId;
    s16 unitId;
} BtlTargetMessage;
typedef struct BtlTargetActionWork
{
    BtlAction* action;
    u16 command;
    u16 pad_06;
    s32 param_3;
    s32 param_4;
    s32 param_5;
    s32 result;
} BtlTargetActionWork;
typedef struct BtlTargetSimpleWork
{
    u16 command;
    u16 pad_02;
    u32 param;
} BtlTargetSimpleWork;
typedef struct BtlTargetCdWork
{
    u8 unk_00[4];
    u16 resource;
    u16 state;
} BtlTargetCdWork;
#include "Battle/btlFormation.h"
#include "Battle/btlFade.h"
extern u32 btlFormation002b8c00(void* work);
extern u32 btlFormation002b8dc0(void* work);
typedef u8 undefined1;
typedef u8 bool;
typedef u16 undefined2;
typedef u32 undefined4;
typedef u64 undefined8;
typedef void undefined;
typedef struct BtlFormationState {
  u8 padding[0x630];
  u16 flags;
  u16 counter;
  u32 value;
} BtlFormationState;
typedef struct FormationMenuState {
  s16 x;
  s16 y;
  s16 firstEntry;
  s16 selectedEntry;
  s16 unk8;
  s16 visibleEntries;
  s16 entryCount;
} FormationMenuState;
typedef struct BtlFormationWork {
  u32 state;
  u32 list;
  u32 argument5;
  u8 padding0c[4];
  s32 sentinel;
  u8 random;
  u8 padding15[3];
  u32 argument3;
  u32 argument4;
  u8 padding20[0x34];
  u16 count;
  u16 padding56;
  u32 items;
} BtlFormationWork;
#define CONCAT44(hi, lo) ((((u64)(hi)) << 32) | (u32)(lo))
extern u64 func_00100d80();
extern u32 func_00100d80_u32(u32 param_1,u32 param_2);
extern u64 func_00100ec0_y2();
extern u64 func_001016b0();
extern u32 func_001016b0_u32(u32 param_1);
extern u64 func_00102100_y2();
extern u64 func_001021c0();
extern u32 func_001021c0_u32(u32 param_1,u8* output);
extern u64 func_001023a0();
extern u64 func_00108570();
extern u64 func_00108670();
extern u64 func_00108680();
extern u64 func_001086a0();
extern u64 func_0016f1f0();
extern u64 func_00170670();
extern u64 func_001706c0();
extern const char* func_00171110(s16 id, s16 field);
extern u64 func_00173220();
extern u64 func_001778b0();
extern u64 func_0017b220();
extern u64 func_0017b260();
extern u64 func_00194b20();
extern u64 func_00195020();
extern u64 func_00195340();
extern char D_00696f50[];
extern char D_006964D0[];
extern char D_006964E8[];
extern u64 func_00195460();
extern u64 func_00195540();
extern u32 func_00195340_u32();
extern u32 func_00195540_u32();
extern u64 func_00195550();
extern u32 func_00198590();
extern u64 func_0019d3f0();
extern u64 func_001fdd60();
extern u64 func_001fdda0();
extern u64 func_001fddf0();
extern u64 func_001fdec0();
extern u64 func_001fdf10();
typedef struct FormationUpdateResult {
  u32 flags;
  s32 state;
  u16 value0;
  u16 value1;
  u16 value2;
  u16 value3;
  u32 value4;
} FormationUpdateResult;
extern void func_001fdf10_btlFormation_result(FormationUpdateResult *result);
extern u64 func_001fe3b0();
extern u64 func_001fe430();
extern u64 func_001fe5f0();
extern u64 func_001fe630();
extern u64 func_001fe650();
extern u64 func_001fe9b0();
extern u64 func_001fea10();
extern u64 func_001fea90();
extern u64 func_001feab0();
extern u64 func_001feb30();
extern u64 func_001feb50();
extern u64 func_001fece0();
extern u64 func_001fed00();
extern u64 func_001fed20();
extern u64 func_001fed40();
extern u64 func_001fed60();
extern u64 func_001fed80();
extern u64 func_001feda0();
extern u64 func_001fedc0();
extern u64 func_001fede0();
extern u64 func_001fee00();
extern u64 func_001fee40();
extern u64 func_001fee80();
extern u64 func_001fef10();
extern u64 func_001ff350();
extern u64 func_001ff370();
extern u64 func_001ff390();
extern u64 func_001ff3b0();
extern u64 func_0021c3f0();
extern u32 func_0021c3f0_u32(u32 param_1);
extern u32 func_0021cca0_u32(u32 param_1,u32 param_2);
extern u64 func_0021cca0();
extern u64 func_0021cce0();
extern u64 func_0027e310();
extern u32 func_0027ec10();
extern u64 func_0027ed20();
extern u64 func_0027f650();
extern u64 func_0027f7c0();
extern u64 func_0027ffb0();
extern u64 func_00280870();
extern s32 func_00280870_btlFormation_s32(u32 mode, u32 enabled,
                                          void *out, void *end, void *extra,
                                          u32 include);
extern f32 func_00280870_btlFormation_f32(u32 mode, u32 enabled,
                                          void *out, void *end, void *extra,
                                          u32 include);
extern void func_002b96f0_btlFormation_u64(float param_1,float param_2,
                                           float *param_3,u32 *param_4,
                                           int param_5,u64 param_6);
extern u64 func_00288f80();
extern u64 func_00289030();
extern u64 func_0028a780();
extern u64 func_0029a1d0();
extern u64 func_0029a210();
extern u32 func_0029a210_u32(u32 param_1);
extern u64 func_0029ad20();
extern u32 func_0029ad20_u32(void);
extern u64 func_0029ad60();
extern u64 func_002a3b40();
extern u64 func_002a3d70();
extern u64 func_002b71e0();
extern u64 func_002b8d60();
extern u64 func_002d15a0();
extern u64 func_002d1a10();
extern u64 func_002d1a70();
extern u64 func_002d1de0();
extern u64 func_002d1fd0();
extern f32 func_002d1fd0_c0070();
extern u32 func_002d4cf0();
extern u32 func_002d4e10_y2();
extern u64 func_002d5550();
extern u64 func_002db650();
extern u64 func_002db800();
extern u64 func_002db890();
extern u64 func_002e3350();
extern u64 func_002eab70();
extern u64 func_002eabb0();
extern u64 func_002ec560();
extern u64 func_002ec590();
extern u64 func_002ecb30();
extern void func_002efc90(u32 param_1);
extern void func_002efcd0(u32 param_1);
extern u64 func_002efd10();
extern void func_002f2450(u32 param_1);
extern void func_002f2490(u32 param_1);
extern u64 func_002f24d0();
extern u64 func_002f2510();
extern u64 func_002f5030();
extern u64 func_002f5320();
extern u64 func_002f6bf0();
extern u64 func_002f6c20();
extern u64 func_002fd820();
extern u64 func_002ffbc0();
extern u16 func_002ffbc0_u16(u32 max);
extern u16 func_002ffbc0_noarg(void);
extern u32 func_002ffbc0_noarg_u32(void);
extern u64 func_002ffcc0();
extern u16 func_002ffd70_y2(u32 unit);
extern u16 func_002ffd80(u32 unit);
extern u16 func_002ffdf0_y2(u32 unit);
extern u16 func_00300100(u32 unit);
extern u64 func_00300530();
extern u32 func_00300530_u32(u32 unit);
extern u64 func_00300550();
extern u32 func_00300550_u32(u32 param_1);
extern u64 func_00300580();
extern u32 func_00300580_u32(u32 param_1,u32 param_2);
extern u64 func_003005e0();
extern u32 func_003005e0_u32(u32 param_1,u32 param_2);
extern u64 func_00301540();
extern u64 func_00301750();
extern u64 func_00301870();
extern u64 func_00301ca0();
extern u64 func_00303130();
extern s32 func_00303130_s32(s32,s32,s32,s32,s32,s32,s32,s32);
extern u32 func_00306e80_y2();
extern u64 func_003080c0();
extern u64 func_003082f0();
extern u64 func_003086f0();
extern u32 func_003086f0_u32(u32 param_1,u32 param_2);
extern u64 func_00308860();
extern u64 func_00308930();
extern u64 func_00308a80();
extern u64 func_00308ba0();
extern u64 func_00308bb0();
extern u32 func_00308ba0_u32(u32 param_1);
extern u32 func_00308bb0_u32(u32 param_1);
extern u32 func_00308860_u32(void);
extern u32 func_0035f160_u32(void);
extern u32 func_0029ad60_u32(u16 param_1);
extern void func_0035f060_u32(u32 param_1);
extern u32 func_0035ed20_u32(u32 param_1);
extern u64 func_002a3d70_f32(float param_1,u32 param_2,void *param_3,void *param_4,void *param_5,void *param_6);
extern u32 func_002a3d70_move(u32 action,RwV3d *startPos,RwV3d *startTarget,RwV3d *endPos,RwV3d *endTarget,float duration);
extern u32 func_002b8d60_u32(s32 param_1,u32 param_2);
extern float func_0035ee60_f32(u32 param_1);
extern u64 func_0030b4b0();
extern u32 func_0030b4b0_u32(u32 param_1,u32 param_2);
extern u32 func_0030b5a0_u32(u32,u32);
extern u64 func_0030b5a0();
extern u64 func_0030bc20();
extern u32 func_0030bc20_u32(u16 param_1);
extern u64 func_003174e0();
extern u64 func_003176c0();
extern u64 func_00317730();
extern u64 FUN_00317a20();
extern u64 func_00318ad0();
extern u64 func_00318b90();
extern u64 func_00318d10();
extern u64 func_00318ed0();
extern u64 func_00321120();
extern u64 func_00321130();
extern u64 func_00321320();
extern u64 func_00324bd0();
extern u32 func_00324bd0_u32(u32 param_1);
extern u64 func_003252a0();
extern u64 func_00325500();
extern u64 func_003257e0();
extern u64 func_00325920();
extern u32 func_00325920_u32(u32 param_1);
extern u64 func_00325c10();
extern u64 func_00325d60();
extern void func_00325e40(float param_1, int param_2);
extern u64 func_00326030();
extern void func_003297a0(float *position);
extern u64 func_00329ed0();
extern u64 func_00351bb0();
extern u64 func_00352c30();
extern u64 func_00352c50();
extern u64 func_00357ea0();
extern u64 func_0035ae10();
extern u64 func_0035bb40();
extern u64 func_0035c090();
extern u64 func_0035ed20();
extern u64 func_0035ee60();
extern u64 func_0035f060();
extern u64 func_0035f160();
extern u64 func_003a4220();
extern u64 func_003b2cb0();
extern void func_003b2cb0_typed(f32 scale, s32 x, s32 y, u32 color, u32 font,
                                u32 align, const void *text, u32 width, u32 flags);
extern u64 func_0045a430();
extern u64 func_0045af40();
extern u64 func_0045af70();
extern void func_004bdde0(float angle, void *frame, const void *vector, u32 mode);
extern void func_004be1e0(void *out, const void *in, s32 count, const void *matrix);
extern u64 func_004c69f0();
extern u64 func_004c6b20();
extern u64 func_0051e0e0();
extern u64 func_00521250();
extern u64 func_00521408();
extern u64 func_00523ac8_y2();
extern u32 func_00524270();
extern u32 func_00524388_y2();
extern u32 func_0052ea18(float param_1, float param_2);
extern u8 DAT_00696440;
extern u8 DAT_00696460;
extern u8 DAT_00696d70;
extern u8 DAT_00696d70_abs[];
extern u8 DAT_00696e10;
extern u32 DAT_00696e30;
extern u32 DAT_00696e34;
extern u8 DAT_00696fb0;
extern u8 DAT_00696fb0_abs[];
extern u32 DAT_006971b0;
extern code gFormationDispatchTable[];
extern code gFormationActionTable[];
extern u8 DAT_007cc740;
extern u8 DAT_007cc970;
extern u8 DAT_007cc971;
extern u8 DAT_007cc972;
extern u8 DAT_007cc973;
extern u8* DAT_007ce41c;
extern u8* DAT_007ce4cc;
extern u8* DAT_007ce4d0;
extern u8* DAT_007ce4e8;
extern u8* DAT_007ce4ec;
extern u32 DAT_007e0952;
extern u32 DAT_007e095a;
extern u8 DAT_007e094e_abs[];
extern u8 DAT_007e0952_abs[];
extern u8 DAT_007e0958_abs[];
extern u8 DAT_007e095a_abs[];
extern u32 DAT_00957100;
extern u32 DAT_00957140;
extern u32 DAT_00957144;
extern u32 DAT_00957148;
extern u8 DAT_00957100_abs[];
extern u8 DAT_00957140_abs[];
extern u8 DAT_00957150_abs[];
extern u8 DAT_00957160_abs[];
extern u8 DAT_00957170_abs[];
extern u32 DAT_00957150;
extern u32 DAT_00957154;
extern u32 DAT_00957158;
extern u32 DAT_00957160;
extern u32 DAT_00957164;
extern u32 DAT_00957168;
extern u32 DAT_00957170;
extern u32 DAT_00957174;
extern u32 DAT_00957178;
extern float DAT_00960088;
extern float DAT_00960088_abs[];
extern u64 (*DAT_00960090)();
extern u64 (*DAT_00960090_abs)();
extern u64 (*DAT_009600a4_abs)();
extern u64 (*DAT_00960178)();
extern u32 (*DAT_00960178_u32_abs[])(...);
extern void (*DAT_0096017c[])(...);
extern code DAT_0096017c_abs[];
extern u32* PTR_DAT_00696f30;
extern u32* PTR_DAT_00696f30_abs[];
extern code pcRam006971bc;
extern code pcRam006971c8;
extern code pcRam006971d4;
extern code pcRam006971e0;
extern code pcRam006971ec;
extern code pcRam006971f8;
extern code pcRam00697204;
extern code pcRam00697210;
extern code pcRam00697228;
extern code pcRam00697234;
extern code pcRam00697240;
extern code pcRam0069724c;
extern code pcRam00697258;
extern code pcRam00697264;
extern code pcRam00697270;
extern code pcRam0069727c;
extern code pcRam00697288;
extern code pcRam006972b8;
extern code pcRam006972c4;
extern code pcRam006972d0;
extern code pcRam006972dc;
extern code pcRam006972e8;
extern code pcRam006972f4;
extern code pcRam00697300;
extern code pcRam0069730c;
extern code pcRam00697318;
extern code pcRam00697324;
extern code pcRam00697330;
extern code pcRam0069733c;
extern code pcRam00697348;
extern code pcRam00697354;
extern code pcRam00697360;
extern code pcRam0069736c;
extern code pcRam00697378;
extern code pcRam00697384;
extern code pcRam006973b4;
extern code pcRam006973c0;
extern code pcRam006973e4;
extern code pcRam006973f0;
extern code pcRam006973fc;
extern code pcRam00697408;
extern code pcRam00697414;
extern code pcRam00697420;
extern code pcRam0069742c;
extern code pcRam00697438;
extern code pcRam00697450;
extern code pcRam0069745c;
extern code pcRam00697468;
extern code pcRam00697474;
extern code pcRam00697480;
extern code pcRam0069748c;
extern code pcRam00697498;
extern code pcRam006974a4;
extern code pcRam006974b0;
extern code pcRam006974bc;
extern code pcRam006974c8;
extern code pcRam006974f8;
extern code pcRam00697504;
extern void LAB_002bd060(u32 **param_1);
extern void LAB_002bd210(u32 **param_1);
extern char* PTR_s_N_00646555_0x12_00696dcc[];
extern char* PTR_s_battle_effect_ATC_D_BED_00696c80;
extern char *PTR_s_battle_effect_ATC_D_BED_abs[];
extern char* PTR_s_battle_effect_SHADOW_S_BED_007cc6f0;
extern u32 _DAT_007ce4f4;
extern u8 gp0xffff99f8;
extern code PTR_FUN_00696490[];
extern code PTR_FUN_006972a0[];
extern code PTR_FUN_006972ac[];
extern code PTR_FUN_00697390[];
extern code PTR_FUN_0069739c[];
extern code PTR_FUN_006973a8[];
extern code PTR_FUN_006973d8[];
extern code PTR_FUN_006974d4[];
extern code PTR_FUN_006974e0[];
extern code PTR_FUN_006974ec[];
extern code PTR_FUN_006975e8[];
extern code PTR_FUN_006975f0[];
extern code PTR_FUN_006975f8[];
extern code PTR_FUN_00697600[];
extern code PTR_FUN_00697608[];
extern code PTR_FUN_00697610[];
extern code PTR_FUN_00697618[];
extern code PTR_FUN_00697620[];
extern code PTR_FUN_00697628[];
extern code PTR_FUN_00697630[];
extern code PTR_FUN_00697638[];
extern code PTR_FUN_00697640[];
extern code PTR_FUN_00697648[];
extern code PTR_FUN_00697650[];
extern code PTR_FUN_00697658[];
extern code PTR_FUN_00697660[];
extern code PTR_FUN_00697670[];
extern code PTR_FUN_00697678[];
extern code PTR_FUN_00697680[];
extern code PTR_FUN_00697688[];
extern code PTR_FUN_00697690[];
extern code PTR_FUN_00697698[];
extern code PTR_FUN_006976a0[];
extern code PTR_FUN_006976a8[];
extern code PTR_FUN_006976b0[];
extern code PTR_FUN_006976b8[];
extern code PTR_FUN_006976c0[];
extern code PTR_FUN_006976e8[];
extern code PTR_FUN_006976f0[];
extern code PTR_FUN_006976f8[];
extern code PTR_FUN_00697700[];
extern float fGpffff8398;
extern float fGpffff839c;
extern u8* iGpffffb708;
extern u32 func_002b8dc0(u16 *param_1);
extern u32 func_002b8f90(u16 param_1);
extern void func_002b9030(u32 param_1);
extern void func_002b90d0(int param_1,u32 param_2);
extern void func_002b9220(int param_1);
extern void func_002b9300(int param_1);
extern bool func_002b9350(int param_1);
extern u32 func_002b9350_u32(int param_1);
extern u32 func_002b9370(int param_1,u16 param_2);
extern u32 func_002b93c0(int param_1,u16 param_2);
extern u32 func_002b93e0(u32 param_1,u16 param_2,u32 param_3,u32 param_4,u32 param_5);
extern u32 func_002b93e0_4arg(u32 param_1,u16 param_2,u32 param_3,u32 param_4);
extern void func_002b94f0(BtlFormationWork *param_1);
extern void func_002b96f0(float param_1,float param_2,float *param_3,u32 *param_4,int param_5,
                          u32 param_6);
extern void func_002b9600(u32 *param_1);
extern u32 func_002b9640(int param_1);
extern void func_002b96e0(int param_1,u32 param_2);
extern void func_002b99d0(u8 *param_1,int param_2,u16 *param_3,u32 *param_4);
extern void func_002b9b00(u8 *param_1,int param_2,int param_3,float *param_4);
extern void func_002b9c00(int param_1,int param_2,int param_3,float *param_4);
extern void func_002b9d40(int param_1,int param_2,int param_3,float *param_4);
extern void func_002b9e80(u64 param_1,u64 param_2,u32 param_3,u32 param_4);
extern void func_002b9f30(u64 param_1,int param_2,u32 param_3,u32 param_4);
extern void func_002ba000(u64 param_1,int param_2,u32 param_3,u32 param_4);
extern void func_002ba0f0(int param_1,int param_2,u8 *param_3,u8 (*param_4) [16]);
extern void func_002ba3a0(int param_1);
extern void func_002ba3a0_void(void);
extern void func_002ba900(int param_1);
extern void func_002baa20(int *param_1);
extern u32 func_002baad0(int *param_1);
extern u32 func_002bac00(u32 param_1,u32 param_2,u16 param_3);
extern void func_002bacb0(u32 *param_1);
extern u32 func_002bad60(u32 *param_1);
extern bool func_002baec0(u32 *param_1);
extern void func_002baf30(u32 *param_1);
extern void func_002baf90(u32 param_1,u32 param_2,u32 param_3,u16 param_4, u32 param_5);
extern void func_002bb050(u32 *param_1);
extern u32 func_002bb0b0(u32 *param_1);
extern void func_002bb290(u32 *param_1);
extern void func_002bb2f0(u32 param_1,u32 param_2,u32 param_3,u64 param_4, u16 param_5);
extern void func_002bb3a0(void);
extern void func_002bb580(u16 *param_1);
extern void func_002bb610(u32 param_1);
extern void func_002bb6f0(u16 param_1,u64 param_2);
extern void func_002bb760(void);
extern void func_002bb770(void);
extern void *func_002bb7d0(void);
extern void func_002bb8f0(u32 param_1);
extern u16 * func_002bb9c0(int param_1);
extern u32 func_002bbac0(int param_1,u16 *param_2);
extern void func_002bbbc0(int param_1);
extern void* func_002bbc00(void* owner);
extern void func_002bbd00(u32 param_1);
extern void func_002bbdc0(u8 *param_1,short param_2);
extern short func_002bbdf0(int param_1);
extern void func_002bbe00(u8 *param_1);
extern void func_002bbf80(int param_1,u32 param_2);
extern u32 func_002bbfa0(int param_1);
extern void func_002bc0e0(int param_1,u8 *param_2);
extern void func_002bc2f0(void);
extern void func_002bc420(void);
extern u32 func_002bc480(void);
extern void func_002bc680(void);
extern void func_002bc6d0(void);
extern u32 func_002bc7b0(u16 *param_1);
extern void func_002bc7e0(u16 param_1);
extern u32 func_002bc830(u8 *param_1);
extern void func_002bc890(u8 *param_1,u16 param_2);
extern u32 func_002bc910(u32 *param_1);
extern void func_002bc950(u32 param_1,u32 param_2,u32 param_3);
extern void func_002bc9c0(float param_1,float param_2,float param_3,float param_4,float param_5, float param_6,u32 param_7,int param_8);
extern void func_002bc9c0_long(float param_1,float param_2,float param_3,float param_4,float param_5, float param_6,u32 param_7,long param_8);
extern void func_002bccd0(u32 param_1, u32 param_2);
extern void func_002bcde0(u64 param_1,u32 *param_2);
extern void func_002bce10(float param_1,float param_2,u8* param_3,int param_4,float *param_5);
extern void func_002bce10_reordered(int param_3,float param_1,float param_2,
                                    int param_4,float *param_5);
extern u32 func_002bd080(int *param_1);
extern void func_002bd230(u32 param_1,u8 param_2,u16 param_3);
extern u32 func_002bd2e0(int *param_1);
extern void func_002bd480(u32 param_1);
extern u32 func_002bd4f0(int param_1);
extern void func_002bd590(u32 param_1,u16 param_2);
extern u32 func_002bd5f0(int param_1);
extern void func_002bd690(u32 param_1,u16 param_2);
extern u32 func_002bd6f0(int param_1);
extern void func_002bd780(u32 param_1,u16 param_2);
extern bool func_002bd7e0(u32 *param_1);
extern void func_002bd850(u32 param_1,u32 param_2);
extern u32 func_002bd8e0(int *param_1);
extern int func_002bdbd0(u32 param_1,u32 param_2,u32 param_3,u16 param_4, u16 param_5,u16 param_6,u16 param_7,u64 param_8);
extern u32 func_002bdcd0(u16 *param_1);
extern void func_002bddd0(void);
extern u16 func_002bde10(int param_1,u16 *param_2);
static u32 func_002bdfb0(int param_1);
extern u32 func_002be2f0(int param_1);
extern void func_002be390(short *param_1,int param_2,int param_3);
extern u32 func_002be580(u64 param_1,int param_2);
extern u32 func_002BE5D0(u64 param_1,int param_2);
extern u32 func_002BE5F0(u64 param_1,int param_2);
extern void func_002BE610(int param_1);
extern u64 func_002be620(int param_1,int param_2);
extern void func_002be720(short *param_1,short param_2,short param_3,int param_4);
extern u64 func_002be9e0(int param_1,int param_2);
extern void func_002bea80(short *param_1,short param_2,short param_3);
extern u16 func_002becc0(void);
extern void func_002bed10(void);
extern void func_002bedd0(int param_1);
extern u64 func_002bef20(u64 param_1);
extern u32 func_002bf2b0(u32 param_1);
extern void func_002bf370(u64 param_1);
extern u32 func_002bf3f0(int param_1);
extern void func_002bf650(void);
extern void func_002bf690(short param_1);
extern void func_002bf850(void);
extern void func_002bf880(void);
extern void func_002bf8b0(void);
extern void func_002bf8e0(void);
extern void func_002bf910(void);
extern void func_002bf940(void);
extern void func_002bf970(void);
extern void func_002bf980(void);
extern void func_002bf990(void);
extern void func_002bf9a0(void);
extern void func_002bf9b0(void);
extern u32 func_002bfab0(void);
extern void func_002bfae0(void);
extern u32 func_002bfb20(void);
extern void func_002bfb50(void);
extern u32 func_002bfb90(int *param_1);
extern void func_002bfc00(void);
extern void func_002bfc50(void);
extern void func_002bfc70(void);
extern void func_002bfc90(void);
extern void func_002bfcb0(int param_1,void *param_2,u32 param_3,u32 param_4,int param_5);
extern void func_002bfcb0_ptr(int param_1,void *param_2,u32 param_3,u32 param_4,long param_5);
extern void func_002bfcb0_u64call(u64 param_1,u64 param_2,u32 param_3,u32 param_4,long param_5);
extern u8 func_002bff60(u64 param_1,long param_2,u32 param_3,long param_4);
extern u16 func_002bff60_u16(u32 param_1,u32 param_2,u16 param_3,u32 param_4);
extern void func_002c0070(int param_1,int param_2);
extern u32 func_002c0880(int param_1);
extern void func_002c08a0(int param_1,u64 *param_2);
extern void func_002c08b0(int param_1,int param_2);
extern long * func_002c08c0(int param_1);
extern u32 func_002c0970(int param_1);
extern u32 func_002c09f0(int param_1);
extern void func_002c0a50(u32 param_1,u16 param_2);
extern void func_002c0ac0(int param_1,int param_2);
extern int func_002c0e30(short param_1,u32 param_2,u32 param_3);
typedef u32 (*FormationPredicate)(int unit,u32 selector);
extern u16 func_002c0f40(int param_1,u32 param_2,u32 param_3,u32 param_4,
                         u32 param_5,FormationPredicate param_6,int *param_7);
extern u32 func_002c0f40_call(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                              long param_5,code *param_6,long param_7);
extern u32 func_002c1080(int param_1,u32 param_2,u32 param_3,u32 param_4,u16 param_5, code *param_6);
extern bool func_002c12f0(int param_1,int param_2);
extern bool func_002c22d0(int param_1,int param_2);
extern bool func_002c28a0(int param_1,int param_2);
extern u32 func_002c1360(int param_1,int param_2);
extern bool func_002c13d0(int param_1,int param_2);
extern void func_002c1440(int param_1,u32 param_2);
extern void func_002c1490(int param_1,u32 param_2);
extern void func_002c14f0(int param_1,u32 param_2);
extern bool func_002c1550(int param_1,u32 param_2);
extern bool func_002c1590(int param_1,u32 param_2);
extern bool func_002c15e0(int param_1,u32 param_2);
extern bool func_002c1650(int param_1,u32 param_2);
extern bool func_002c16a0(int param_1,u32 param_2);
extern void func_002c1710(int param_1);
extern void func_002c1740(int param_1,u32 param_2);
extern void func_002c17b0(int param_1,u32 param_2);
extern bool func_002c1850(int param_1,u64 param_2);
extern u32 func_002c1960(int param_1,u32 param_2);
extern u32 func_002c1a30(int param_1,u32 param_2);
extern u32 func_002c1b10(int param_1,u32 param_2);
extern u32 func_002c1bf0(int param_1,u32 param_2);
extern bool func_002c1ce0(int param_1,int param_2);
extern u64 func_002c1d80(void);
extern bool func_002c1d90(int param_1);
extern bool func_002c1e10(int param_1,short param_2);
extern bool func_002c1e50(int param_1,short param_2);
extern bool func_002c1e90(int param_1,short param_2);
extern bool func_002c1ed0(int param_1,short param_2);
extern void func_002c1f10(int param_1,u32 param_2);
extern void func_002c1f60(int param_1,u32 param_2);
extern void func_002c1fc0(int param_1,u32 param_2);
extern void func_002c2010(int param_1,u32 param_2);
extern void func_002c2070(int param_1,u32 param_2);
extern void func_002c20c0(int param_1,u32 param_2);
extern void func_002c2120(int param_1,u32 param_2);
extern void func_002c2170(int param_1,u32 param_2);
extern bool func_002c21d0(int param_1,int param_2);
extern void func_002c2220(int param_1,u32 param_2);
extern void func_002c2270(int param_1,u32 param_2);
extern void func_002c2310(int param_1,u32 param_2);
extern void func_002c2360(int param_1,u32 param_2);
extern u32 func_002c23c0(int param_1);
extern void func_002c2420(int param_1,u32 param_2);
extern void func_002c2470(int param_1,u32 param_2);
extern u32 func_002c2510(int param_1);
extern bool func_002c25d0(int param_1);
extern void func_002c25e0(int param_1,u32 param_2);
extern void func_002c2630(int param_1,u32 param_2);
extern void func_002c2690(int param_1,u32 param_2);
extern void func_002c26e0(int param_1,u32 param_2);
extern void func_002c2740(int param_1,u32 param_2);
extern void func_002c2790(int param_1,u32 param_2);
extern void func_002c27f0(int param_1,u32 param_2);
extern void func_002c2840(int param_1,u32 param_2);
extern bool func_002c28c0(int param_1,int param_2);
extern bool func_002c29e0(int param_1,int param_2);
extern bool func_002c2b20(int param_1,u16 param_2);
extern void func_002c2be0(int param_1,u32 param_2);
extern void func_002c2c40(int param_1,u32 param_2);
extern void func_002c2ca0(int param_1,u32 param_2);
extern u32 func_002c2d00(int param_1,u32 param_2);
extern bool func_002c2ed0(int param_1,u16 param_2,int param_3);
extern void func_002c30f0(int param_1,u16 param_2);
extern void func_002c3120(int param_1,u16 param_2);
extern void func_002c3150(int param_1,u32 param_2);
extern void func_002c31b0(int param_1,u32 param_2);
extern void func_002c3210(int param_1,u32 param_2);
extern bool func_002c3270(int param_1);
extern u32 func_002c32c0(int param_1);
extern u32 func_002c32e0(int param_1);
extern u32 func_002c3300(int param_1,u32 param_2);
extern bool func_002c3400(int param_1);
extern u64 func_002c3430(u64 param_1,u64 param_2,u32 param_3,u16 param_4,int param_5,code *param_6);
extern u32 func_002c3770(u32 param_1,u32 param_2);
extern u32 func_002c3770_u32(u32 param_1,u32 param_2);
extern u32 func_002c3be0(u32 param_1);
extern u32 func_002c3ce0(u32 param_1);
extern u64 func_002c3e10(void);
extern void func_002c3e20(u64 param_1,u64 param_2);
extern void func_002c3e60(u64 param_1,u64 param_2);
extern void func_002c3ea0(u64 param_1,u64 param_2);
extern u32 func_002c3ee0(int param_1);
extern u32 func_002c3f00(int param_1);
extern void func_002c4000(u64 param_1,u64 param_2);
extern void func_002c4040(u64 param_1,u64 param_2);
extern void func_002c4080(u64 param_1,u64 param_2);
extern void func_002c40c0(u64 param_1,u64 param_2);
extern void func_002c4100(u64 param_1,u64 param_2);
extern void func_002c4140(u64 param_1,u64 param_2);
extern void func_002c4180(u64 param_1,u64 param_2);
extern void func_002c41c0(u64 param_1,u64 param_2);
extern u32 func_002c4200(u32 param_1);
extern u32 func_002c42c0(u32 param_1,u32 param_2);
extern void func_002c43a0(u64 param_1);
extern void func_002c43e0(u64 param_1);
extern void func_002c4420(u64 param_1,u64 param_2);
extern void func_002c4460(u64 param_1,u64 param_2);
extern void func_002c44a0(u64 param_1,u64 param_2);
extern void func_002c44e0(u64 param_1,u64 param_2);
extern void func_002c4520(u64 param_1,u64 param_2);
extern void func_002c4560(u64 param_1,u64 param_2);
extern void func_002c45a0(u64 param_1,u64 param_2);
extern void func_002c45e0(u64 param_1,u64 param_2);
extern void func_002c4620(u64 param_1,u64 param_2);
extern void func_002c4660(u64 param_1,u64 param_2);
extern void func_002c46a0(u64 param_1,u64 param_2);
extern void func_002c46e0(u64 param_1,u64 param_2);
extern void func_002c4720(u64 param_1,u64 param_2);
extern u32 func_002c4760(u32 param_1);
extern void func_002c4820(u64 param_1,u64 param_2);
extern void func_002c4860(u64 param_1,u64 param_2);
extern u32 func_002c48a0(int param_1,int param_2,u16 *param_3,u16 param_4,u16 param_5);
extern u32 func_002c4a90(int param_1,int param_2,u16 *param_3,u32 param_4,short param_5);
extern u32 func_002c4c80(int param_1,int param_2,u16 *param_3,u32 param_4,int param_5);
extern u32 func_002c4e50(int param_1,int param_2,u16 *param_3,u32 param_4,int param_5);
extern s32 func_002c5030(u32 param_1,u32 param_2,s32 param_3,int param_4);
extern u32 func_002c5380(int param_1,int param_2,u16 *param_3,int param_4);
extern u32 func_002c5380_noargs();
extern u32 func_002c59d0(int param_1,int param_2,int param_3,long param_4);
extern s32 func_002c5fc0(u32 param_1,u32 param_2,short param_3,int param_4);
extern s32 func_002c6300(u32 param_1,u32 param_2,u16 param_3,s32 param_4);
extern long func_002c6300_s32(u32 context, u32 actor, s16 value, s32 mode);
extern u32 func_002c65d0(int param_1);
extern void func_002c6a00(int param_1,int param_2,u16 param_3);
extern u16 func_002c6ba0(int param_1);
extern undefined * func_002c6e30(int param_1,u32 param_2);
extern u32 func_002c6f50(u32 param_1,int param_2,u32 param_3,u32 param_4);
extern u32 func_002c6f50_u32(u32 param_1,int param_2,u32 param_3,u32 param_4);
extern void func_002c70d0(int param_1,int param_2);
extern bool func_002c7250(int param_1);
extern u32 func_002c7280(int param_1);
extern u32 func_002c7300(void);
extern u32 func_002c7340(void);
extern u32 func_002c73e0(void);
extern u32 func_002c7460(void);
extern u32 func_002c74a0(void);
extern u32 func_002c74e0(void);
extern u32 func_002c7540(void);
extern u32 func_002c75d0(void);
extern u32 func_002c7670(void);
extern u32 func_002c76b0(void);
extern u32 func_002c7760(void);
extern u32 func_002c7810(void);
extern u32 func_002c78c0(void);
extern u32 func_002c7970(void);
extern u32 func_002c7a20(void);
extern u32 func_002c7ad0(void);
extern u32 func_002c7b80(void);
extern u32 func_002c7c30(void);
extern u32 func_002c7ce0(void);
extern u32 func_002c7d90(void);
extern u32 func_002c7e40(void);
extern u32 func_002c7ef0(void);
extern u32 func_002c7fa0(void);
extern u32 func_002c8050(void);
extern u32 func_002c8100(void);
extern u32 func_002c81b0(void);
extern u32 func_002c8260(void);
extern u32 func_002c8310(void);
extern u32 func_002c8360(void);
extern u32 func_002c83b0(void);
extern u32 func_002c8400(void);
extern u32 func_002c84b0(void);
extern u32 func_002c8560(void);
extern u32 func_002c8610(void);
extern u32 func_002c86c0(void);
extern u32 func_002c8770(void);
extern u32 func_002c8820(void);
extern u32 func_002c88d0(void);
extern u32 func_002c8980(void);
extern u32 func_002c8a30(void);
extern u32 func_002c8ae0(void);
extern u32 func_002c8b90(void);
extern u32 func_002c8c40(void);
extern u32 func_002c8cf0(void);
extern u32 func_002c8da0(void);
extern u32 func_002c8e50(void);
extern u32 func_002c8f00(void);
extern u32 func_002c8fb0(void);
extern u32 func_002c9060(void);
extern u32 func_002c90b0(void);
extern u32 func_002c9100(void);
extern u32 func_002c9150(void);
extern u32 func_002c9200(void);
extern u32 func_002c92b0(void);
extern u32 func_002c9300(void);
extern u32 func_002c9350(void);
extern u32 func_002c9400(void);
extern u32 func_002c94b0(void);
extern u32 func_002c9560(void);
extern u32 func_002c9610(void);
extern u32 func_002c96c0(void);
extern u32 func_002c9770(void);
extern u32 func_002c9820(void);
extern u32 func_002c98d0(void);
extern u32 func_002c99c0(void);
extern u32 func_002c9ab0(void);
extern u32 func_002c9ba0(void);
extern u32 func_002c9ce0(void);
extern u32 func_002c9da0(void);
extern u32 func_002c9e90(void);
extern u32 func_002c9f80(void);
extern u32 func_002ca070(void);
extern u32 func_002ca160(void);
extern u32 func_002ca250(void);
extern u32 func_002ca340(void);
extern u32 func_002ca3e0(void);
extern u32 func_002ca480(void);
extern u32 func_002ca590(void);
extern u32 func_002ca6a0(void);
extern u32 func_002ca7b0(void);
extern u32 func_002ca900(void);
extern u32 func_002ca9d0(void);
extern u32 func_002caae0(void);
extern u32 func_002cabf0(void);
extern u32 func_002cad00(void);
extern u32 func_002cae10(void);
extern u32 func_002caf20(void);
extern u32 func_002cb030(void);
extern u32 func_002cb0e0(void);
extern u32 func_002cb190(void);
extern u32 func_002cb270(void);
extern u32 func_002cb320(void);
extern u32 func_002cb3d0(void);
extern u32 func_002cb480(void);
extern u32 func_002cb530(void);
extern u32 func_002cb5e0(void);
extern u32 func_002cb690(void);
extern u32 func_002cb740(void);
extern u32 func_002cb7f0(void);
extern u32 func_002cb8a0(void);
extern u32 func_002cb950(void);
extern u32 func_002cba00(void);
extern u32 func_002cba50(void);
extern u32 func_002cbaa0(void);
extern u32 func_002cbaf0(void);
extern u32 func_002cbba0(void);
extern u32 func_002cbcd0(void);
extern u32 func_002cbd90(void);
extern u32 func_002cbe50(void);
extern u32 func_002cbf10(void);
extern u32 func_002cbfd0(void);
extern u32 func_002cc0a0(void);
extern u32 func_002cc190(void);
extern u32 func_002cc240(void);
extern u32 func_002cc330(void);
extern u32 func_002cc3e0(void);
extern u32 func_002cc450(void);
extern u32 func_002cc4c0(void);
extern u32 func_002cc530(void);
extern u32 func_002cc5a0(void);
extern u32 func_002cc650(void);
extern u32 func_002cc700(void);
extern u32 func_002cc7b0(void);
extern u32 func_002cc820(void);
extern u32 func_002cc890(void);
extern u32 func_002cc940(void);
extern u32 func_002cc9f0(void);
extern u32 func_002ccaa0(void);
extern u32 func_002ccb50(void);
extern u32 func_002ccc00(void);
extern u32 func_002cccb0(void);
extern u32 func_002ccd60(void);
extern u32 func_002cce10(void);
extern u32 func_002cce80(void);
extern u32 func_002ccef0(void);
extern u32 func_002ccf60(void);
extern u32 func_002cd010(void);
extern u32 func_002cd0c0(void);
extern u32 func_002cd170(void);
extern u32 func_002cd220(void);
extern u32 func_002cd2d0(void);
extern u32 func_002cd380(void);
extern u32 func_002cd430(void);
extern u32 func_002cd4e0(void);
extern u32 func_002cd570(void);
extern u32 func_002cd620(void);
extern u32 func_002cd690(void);
extern u32 func_002cd740(void);
extern u32 func_002cd7f0(void);
extern u32 func_002cd8c0(void);
extern u32 func_002cd940(void);
extern u32 func_002cd9c0(void);
extern u32 func_002cda10(void);
extern u32 func_002cda50(void);
extern u32 func_002cdad0(void);
extern u32 func_002cdb70(void);
extern u32 func_002cdbe0(void);
extern u32 func_002cdc50(void);
extern u32 func_002cdcc0(void);
extern u32 func_002cdd30(void);
extern u32 func_002cdda0(void);
extern u32 func_002cde10(void);
extern u32 func_002cde60(void);
extern u32 func_002cded0(void);
extern u32 func_002cdf40(void);
extern u32 func_002ce010(void);
extern u32 func_002ce090(void);
extern u32 func_002ce170(void);
extern u32 func_002ce210(void);
extern u32 func_002ce2b0(void);
extern u32 func_002ce380(void);
extern u32 func_002ce440(void);
extern u32 func_002ce4e0(void);
extern u32 func_002ce5c0(void);
extern u32 func_002ce6c0(void);
extern u32 func_002ce7a0(void);
extern u32 func_002ce880(void);
extern u32 func_002ce960(void);
extern u32 func_002cea40(void);
extern u32 func_002ceb20(void);
extern u32 func_002cec30(void);
extern u32 func_002ced60(void);
extern u32 func_002cef10(void);
extern u32 func_002cf070(void);
extern u32 func_002cf1d0(void);
extern u32 func_002cf340(void);
extern u32 func_002cf450(void);
extern u32 func_002cf580(void);
extern u32 func_002cf6b0(void);
extern u32 func_002cf7e0(void);
extern u32 func_002cf890(void);
extern u32 func_002cf940(void);
extern u32 func_002cf9f0(void);
extern u32 func_002cfa40(void);
extern u32 func_002cfb20(void);
extern u32 func_002cfc50(void);
extern u32 func_002cfd80(void);
extern u32 func_002cfeb0(void);
extern u32 func_002cffc0(void);
extern u32 func_002d0150(void);
extern u32 func_002d0270(void);
extern u32 func_002d03e0(void);
extern u32 func_002d05c0(void);
extern u32 func_002d06e0(void);
extern u32 func_002d0720(void);
extern u32 func_002d0760(void);
extern u32 func_002d0860(void);
extern u32 func_002d08e0(void);
extern u32 func_002d0970(void);
extern u32 func_002d09d0(void);
extern u32 func_002d0a30(void);
extern u32 func_002d0ac0(void);
extern u32 func_002d0af0(void);
extern u32 func_002d0b90(void);
extern u32 func_002d0bd0(void);
extern u32 func_002d0c10(void);
extern u32 func_002d0c50(void);
extern u32 func_002d0c80(void);
extern u32 func_002d0cb0(void);
extern u32 func_002d0d00(void);
extern u32 func_002d0d70(void);
extern u32 func_002d0de0(void);
extern u32 func_002d0ef0(void);
extern u32 func_002d0f90(void);
extern u32 func_002d1030(void);
extern u32 func_002d10f0(void);
extern u32 func_002d1180(void);
extern u32 func_002d11d0(void);
extern u32 func_002d1210(void);
extern u32 func_002d1260(void);
extern u32 func_002d12a0(void);
extern u32 func_002d12e0(void);
extern u32 func_002d13c0(void);
extern u32 func_002d1490(void);
extern u32 func_002d14d0(void);
extern u32 func_002d1510(void);
extern void func_0027ffb0_v3d(int unit, RwV3d* out);
extern s32 func_00318ed0_v3d(u32 model, u32 index, RwV3d* out);
typedef struct FormationLoadWork {
  BtlFormationState* state;
  u32 request;
  u32 source;
  u16 flags;
  u16 padding;
} FormationLoadWork;
extern u32 func_002c1ce0_u32(int param_1, int param_2);

static u8 btlSoundHasFlag(s32 flag)
{
    return flag != -1 && datGetFlag(flag) != 0;
}
static BtlUnit* btlSoundActionUnit(const BtlAction* action)
{
    return action == NULL ? NULL : action->unit;
}
static s32 btlSoundActionGenus(const BtlAction* action)
{
    BtlUnit* unit = btlSoundActionUnit(action);
    return unit == NULL ? -1 : unit->genus;
}
static s32 btlSoundActionCharId(const BtlAction* action)
{
    BtlUnit* unit = btlSoundActionUnit(action);
    return unit == NULL ? -1 : unit->charId;
}
static inline f32 btlTargetV2dLength(const RwV2d* v)
{
    return sqrtf(v->x * v->x + v->y * v->y);
}
static inline u16 btlTargetRandomDelay(u16 base, u32 limit)
{
    return (u16)(base + (u16)datCalcRand(limit));
}
static inline void btlTargetWorldToTile(s16* outX, s16* outZ, f32* position)
{
    s32 x = (s32)(position[0] + 1750.0f);
    s32 z = (s32)(position[2] + 1750.0f);
    s16 tileX = (s16)(x / 0x19);
    s16 tileZ = (s16)(z / 0x19);
    if (x % 0x19 > 0x0C) tileX++;
    if (z % 0x19 > 0x0C) tileZ++;
    if (outX != NULL) *outX = tileX;
    if (outZ != NULL) *outZ = tileZ;
}
static inline u16 btlFormationGetOpposingGenus(u32 unit)
{
  u32 side;
  if (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) != 0)
    goto nonzero;
  side = 1;
  goto done;
nonzero:
  side = 0;
done:
  return side;
}

// FUN_002dbb00 NONMATCHING
u32 FUN_002dbb00(BtlUnit* param_1)
{
    u16 candidates[16];
    u16 count = 0;
    u16 firstCount = 0;
    u16 slot;
    u8* encounter = *(u8**)(iGpffffb6fc_y2 + 0xbbc);
    u8* table;
    u32 result;

    if (datGetScenarioMode() != 0)
    {
        u32 encounterId = FUN_002d5550();
        if (encounterId == 0x1b3 || encounterId == 0x1b2 || encounterId == 0x1b1)
        {
            return 0xffffffff;
        }
    }
    if (param_1->charId > 0x14f)
    {
        K_Assert(D_00697B18, 0x96f);
    }
    if ((((BtlEnemyData*)iGpffffb720)[param_1->charId].analyzeFlags & 0x20) != 0)
    {
        return 0xffffffff;
    }
    table = (datGetFlag(0x141) != 0) ? D_00697980 : D_00697A50;
    for (slot = 0; slot < 10; slot++)
    {
        u8* entry = table + (u32)slot * 0x12;
        if (entry[6] != 0 &&
            (func_00306e80(param_1->datUnit, slot) & 0x08000000) != 0)
        {
            if (*(u16*)(encounter + 8) == 0x1a1)
            {
                candidates[count] = *(u16*)(entry + 8);
            }
            else
            {
                candidates[count] = *(u16*)(entry + datCalcRand(entry[6]) * 2);
            }
            count++;
            firstCount++;
        }
    }
    if (count == 0)
    {
        count = 0;
        for (slot = 0; slot < 10; slot++)
        {
            u8* entry = table + (u32)slot * 0x12;
            if (entry[0x10] != 0 &&
                (func_00306e80(param_1->datUnit, slot) & 0x07000000) != 0)
            {
                candidates[count] = *(u16*)(entry + datCalcRand(entry[0x10]) * 2 + 0x0a);
                count++;
            }
        }
        switch (count)
        {
        case 0:
            if (*(u16*)(encounter + 8) == 0x1a1)
                result = *(u16*)(table + 0xbc);
            else
                result = *(u16*)(table + datCalcRand(*(u8*)(table + 0xba)) * 2 + 0xb4);
            break;
        default:
            result = candidates[datCalcRand(count)];
            break;
        }
    }
    else if (firstCount < 2)
    {
        result = candidates[datCalcRand(firstCount)];
    }
    else
    {
        result = (datGetFlag(0x141) == 0) ? 0x3d4 : 0x209;
    }
    return result;
}

// FUN_002dbeb0
u32 FUN_002dbeb0(void* param_1)
{
    BtlTargetCdWork* work = (BtlTargetCdWork*)param_1;

    switch (work->state)
    {
    case 0:
        *(u16*)(iGpffffb6fc_y2 + 0xa14) = (work->resource == 0) ? 4 : 6;
    case 1:
        *(HCdvd**)(iGpffffb6fc_y2 + 0xa1c) = H_Cdvd_Request(D_00697B90[work->resource], 0);
        work->state = 2;
        goto zero;
    case 2:
        if (H_Cdvd_IsFileLoaded(*(HCdvd**)(iGpffffb6fc_y2 + 0xa1c)) == 0)
            goto zero;
    case 3:
        func_003c8da0((1u << *(u16*)(iGpffffb6fc_y2 + 0xa14)) | 1);
        work->state = 4;
    case 4:
        *(u32*)(iGpffffb6fc_y2 + 0x0c) |= 0x01000000;
        goto one;
    default:
        goto zero;
    }
one:
    return 1;
zero:
    return 0;
}

// FUN_002dbfe0
BtlPacket* FUN_002dbfe0(u16 param_1)
{
    BtlPacket* packet = btlPacketCreate(0x803, 8);
    BtlTargetCdWork* work;
    packet->unk_47 &= (u8)~BTLPACKET_FLAG_AUTO_DESTROY;
    packet->updateFunc = FUN_002dbeb0;
    work = (BtlTargetCdWork*)packet->workData;
    work->resource = (datGetScenarioMode() != 0) ? 2 : param_1;
    work->state = 0;
    return packet;
}

// FUN_002dc070
u32 FUN_002dc070(BtlAction* action)
{
    DatUnit* datUnit = action->unit->datUnit;
    u16 chance;

    if (datCalcChkBadStatus(datUnit, 0x100000) != 0)
    {
        return 1;
    }
    if (datCalcChkBadStatus(datUnit, 0x10037f) == 0)
    {
        return 0;
    }
    chance = 100;
    switch (datCalcGetBadStatusNoDown(datUnit))
    {
    case 8:
        chance = 50;
        break;
    default:
        break;
    }
    return datCalcRand(100) < chance;
}
/* The following packet producers share the battle sound channel table at
 * Battle+0xa90.  Keep the work layouts byte-oriented: these packets are
 * allocated by the retail scheduler and are not C structs elsewhere. */





// FUN_002dc130
u32 FUN_002dc130(BtlAction* action)
{
    DatUnit* datUnit = action->unit->datUnit;
    if ((action->unk_18 & 4) != 0)
    {
        return 0;
    }
    return datCalcChkBadStatus(datUnit, 0x80) != 0;
}

// FUN_002dc180 NONMATCHING
u32 FUN_002dc180(BtlAction* action)
{
    BtlUnit* unit = action->unit;
    u32 status = datCalcGetBadStatus(unit->datUnit);
    u32 result = 0;
    u32 index;

    for (index = 0; index < 0x18; index++)
    {
        u32 bit = 1u << index;
        u32 chance = 0;
        u32 threshold = 0;
        u32 useCounter = 1;
        u32 reduceBySkills = 0;

        if ((status & bit) == 0)
        {
            continue;
        }
        switch (bit)
        {
        case 1:
            chance = FUN_0030FC40(8, unit->datUnit, unit->datUnit, 0, 1);
            threshold = 4;
            reduceBySkills = 1;
            break;
        case 2:
            chance = FUN_0030FC40(9, unit->datUnit, unit->datUnit, 0, 2);
            threshold = 3;
            reduceBySkills = 1;
            break;
        case 4:
            chance = FUN_0030FC40(0xa, unit->datUnit, unit->datUnit, 0, 4);
            threshold = 3;
            reduceBySkills = 1;
            break;
        case 8:
            chance = FUN_0030FC40(0xb, unit->datUnit, unit->datUnit, 0, 8);
            threshold = 3;
            reduceBySkills = 1;
            break;
        case 0x10:
            if (*(u8*)((u8*)action + 0x28) == 0 &&
                *(u8*)((u8*)action + 0x29) == 0)
            {
                chance = FUN_0030FC40(0xc, unit->datUnit, unit->datUnit, 0, 0x10);
                threshold = 4;
                reduceBySkills = 1;
            }
            break;
        case 0x20:
            chance = FUN_0030FC40(0xd, unit->datUnit, unit->datUnit, 0, 0x20);
            threshold = 2;
            useCounter = 0;
            reduceBySkills = 1;
            break;
        case 0x40:
            chance = FUN_0030FC40(0xe, unit->datUnit, unit->datUnit, 0, 0x40);
            threshold = 2;
            useCounter = 0;
            reduceBySkills = 1;
            break;
        case 0x200:
            threshold = 3;
            useCounter = 1;
            break;
        case 0x100:
            threshold = (datGetScenarioMode() != 0) ? 5 : 4;
            useCounter = 1;
            break;
        default:
            break;
        }
        if (reduceBySkills && threshold != 0)
        {
            if (datCalcHasSkill(unit->datUnit, 0x262) != 0)
            {
                threshold >>= 1;
                if (threshold == 0)
                    threshold = 1;
            }
            if (datCalcHasSkill(unit->datUnit, 0x263) != 0)
                threshold = 1;
        }
        if (useCounter == 0 || *((u8*)action + index + 0x462) > 1)
        {
            u8 counter = *((u8*)action + index + 0x462);
            if (counter < threshold || threshold == 0)
            {
                if (datCalcRand(100) < chance)
                    result |= bit;
            }
            else
            {
                result |= bit;
            }
        }
    }
    return result;
}

#pragma opt_loop_invariants on
// FUN_002dc550
void FUN_002dc550(BtlAction* action, u32 flags)
{
    if (flags != 0)
    {
        u32 badStatus = datCalcGetBadStatus(action->unit->datUnit);
        u32 i;
        u32 bit;

        i = 0;
        bit = 1;
        for (; i < 0x18; i++)
        {
            u32 mask = bit << i;
            if ((flags & mask) != 0 && (badStatus & mask) == 0)
            {
                *((u8*)action + 0x462 + i) = 0;
            }
        }
    }
}

#pragma opt_loop_invariants off

/* Removing this loses FUN_002dc5e0 (MATCH nd0 -> MISMATCH nd14) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002dc5e0
void FUN_002dc5e0(BtlAction* action)
{
    u32 badStatus = datCalcGetBadStatus(action->unit->datUnit);
    u32 i;
    u32 bit;

    i = 0;
    bit = 1;
    for (; i < 0x18; i++)
    {
        if ((badStatus & (bit << i)) != 0)
        {
            u8* counter = (u8*)action + 0x462 + i;
            if (*counter < 0xff)
            {
                (*counter)++;
            }
        }
    }
}

#pragma opt_loop_invariants off

// FUN_002dc670
s32 FUN_002dc670(BtlAction* action)
{
    DatUnit* datUnit = action->unit->datUnit;
    s32 result = 0;

    switch (datCalcGetBadStatusNoDown(datUnit))
    {
    case 0x80:
        {
            u16 maxHp = datCalcGetMaxHp(datUnit);

            if ((datUnit->flags & UNIT_FLAG_ENEMY) == 0)
            {
                result = (s16)(-((s32)maxHp * 100) / 500);
            }
            else
            {
                u16 tableFlags = *(u16*)(DAT_007ce410 + (u32)datUnit->id * 0x3e);
                if ((tableFlags & 0x400) != 0)
                {
                    result = -0x32;
                }
                else if ((tableFlags & 0x800) != 0)
                {
                    result = -100;
                }
                else if ((tableFlags & 0x1000) != 0)
                {
                    result = -0x96;
                }
                else if ((tableFlags & 0x2000) != 0)
                {
                    result = -0xc8;
                }
                else
                {
                    result = (s16)(-((s32)maxHp * 100) / 0x14d);
                }

                if ((s16)result > 999)
                {
                    result = 999;
                }
            }
            break;
        }
    }

    if (datCalcIsDead(datUnit, (s16)result) != 0)
    {
        u16 hp = datCalcGetHp(datUnit);
        return (s16)(-((s32)hp - 1));
    }
    return result;

}

// FUN_002dc830
s32 FUN_002dc830(BtlAction* action)
{
    BtlUnit* unit;
    s32 result;
    u32 status;

    if ((action->unk_1a & 1) == 0)
    {
        return -1;
    }

    unit = action->unit;
    result = -1;
    status = datCalcGetBadStatusNoDown(unit->datUnit);

    switch (status)
    {
    case 1:
        switch (action->target.commandId)
        {
        case 1:
            result = 6;
            break;
        default:
            result = 8;
            break;
        }
        break;
    case 2:
        break;
    case 4:
        break;
    case 8:
        switch (action->target.commandId)
        {
        case 6:
        case 0xc:
            result = 0xe;
            break;
        case 7:
        case 8:
        case 0xb:
            result = 0x10;
            break;
        }
        break;
    case 0x10:
        if (*(u8*)((u8*)action + 0x28) == 0 &&
            *(u8*)((u8*)action + 0x29) == 0)
            result = 0x12;
        break;
    case 0x20:
        switch (action->target.commandId)
        {
        case 0xb:
            result = 10;
            break;
        }
        break;
    case 0x40:
        switch (action->target.commandId)
        {
        case 0xb:
            result = 0xc;
            break;
        }
        break;
    case 0x80:
        break;
    case 0x200:
        switch (action->target.commandId)
        {
        case 7:
        case 8:
        case 0xb:
            result = 0x14;
            break;
        }
        break;
    }

    if (result < 0)
    {
        return -1;
    }
    if (unit->genus == 0)
    {
        return result;
    }
    result++;
    return result;
}

// FUN_002dca60
s32 FUN_002dca60(BtlAction* action)
{
    BtlUnit* unit;
    s32 result;

    if ((action->unk_1a & 1) == 0)
    {
        return -1;
    }

    unit = action->unit;
    result = -1;
    switch (datCalcGetBadStatusNoDown(unit->datUnit))
    {
        case 1: result = 0x28; break;
        case 2: result = 0x2a; break;
        case 4: result = 0x2c; break;
        case 8: result = 0x2e; break;
        case 0x10: result = 0x30; break;
        case 0x20: result = 0x32; break;
        case 0x40: result = 0x34; break;
        case 0x100: result = 0x36; break;
        case 0x200: result = 0x38; break;
        default: break;
    }

    if (result < 0)
    {
        return -1;
    }
    if (unit->genus == 0)
    {
        return result;
    }
    result++;
    return result;
}

#pragma opt_loop_invariants on
// FUN_002dcbc0
void FUN_002dcbc0(void)
{
    u16 i;
    s32 empty;
    u8 state;

    *(u16*)((u8*)gBtl + 0xa90) = 5;
    empty = -1;
    *(s8*)((u8*)gBtl + 0xa92) = empty;
    i = 0;
    state = 3;
    for (; i < 0x10; i++)
    {
        u32 offset = ((u32)i & 0xffff) * 6;
        *(s16*)((u8*)gBtl + 0xa94 + offset) = empty;
        *(s16*)((u8*)gBtl + 0xa96 + offset) = empty;
        *(u8*)((u8*)gBtl + 0xa98 + offset) = state;
    }
}

#pragma opt_loop_invariants off

/* Removing this loses FUN_002dcc40 (MATCH nd0 -> MISMATCH nd72) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002dcc40
void FUN_002dcc40(void)
{
    s8* counter;
    u16 i;

    counter = (s8*)((u8*)gBtl + 0xa92);
    if (*counter >= 0)
    {
        (*counter)++;
        if (*counter >= 3)
        {
            *(s8*)((u8*)gBtl + 0xa92) = -1;
        }
    }

    for (i = 0; i < 0x10; i++)
    {
        counter = (s8*)gBtl;
        {
            u32 offset = ((u32)i & 0xffff) * 6;
            u8* slot = (u8*)counter + offset;
            counter = (s8*)(slot + 0xa98);

            if (*counter >= 0)
            {
                (*counter)++;
                if (*counter >= 3)
                {
                    *(s16*)((u8*)gBtl + 0xa94 + offset) = -1;
                    *(s16*)((u8*)gBtl + 0xa96 + offset) = -1;
                    *(s8*)((u8*)gBtl + 0xa98 + offset) = -1;
                }
            }
        }
    }
}
#pragma opt_loop_invariants reset

// FUN_002dcd20
void FUN_002dcd20(void)
{
}

// FUN_002dcd30
void btlSoundPlayBgm()
{
    BtlEncountTable* encount;

    if (gBtl->flags & BTL_FLAG_UNK40)
    {
        encount = &gEncountTbl[gBtl->startInfo.enmUnits->encountId];

        switch (encount->bgm)
        {
            case BTLENCOUNT_BGM_FULLMOON:     H_Snd_PlayBgm(HSND_BGM_MASTER_OF_SHADOW, 1);    break;
            case BTLENCOUNT_BGM_STREGA:       H_Snd_PlayBgm(HSND_BGM_UNAVOIDABLE_BATTLE, 1);  break;
            case BTLENCOUNT_BGM_TARTARUSBOSS: H_Snd_PlayBgm(HSND_BGM_MASTER_OF_TARTARUS, 1);  break;
            case BTLENCOUNT_BGM_NYX:          H_Snd_PlayBgm(HSND_BGM_BURN_MY_DREAD_LAST, 1);  break;
            case BTLENCOUNT_BGM_NYXAVATAR:    H_Snd_PlayBgm(HSND_BGM_BATTLE_HYMN_OF_SOUL, 1); break;
            case BTLENCOUNT_BGM_SEES:         H_Snd_PlayBgm(HSND_BGM_HEARTFUL_CRY, 1);        break;
            case BTLENCOUNT_BGM_EREBUS:       H_Snd_PlayBgm(HSND_BGM_DARKNESS, 1);            break;

            default:
                if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
                {
                    H_Snd_PlayBgm(HSND_BGM_MASS_DESTRUCTION, 1);
                }
                else
                {
                    H_Snd_PlayBgm(HSND_BGM_MASS_DESTRUCTION_FES, 1);
                }
        }
    }
}

// FUN_002dce90
void func_002dce90(void)
{
    if ((gBtl->flags & BTL_FLAG_UNK40) != 0)
    {
        H_Snd_StopBgm();
    }
}

// FUN_002dced0
void btlSound002dced0(u16 fadeDuration)
{
    if ((gBtl->flags & BTL_FLAG_UNK40) != 0)
    {
        H_Snd_StopBgmFade(fadeDuration);
    }
}

// FUN_002dcf10
void FUN_002dcf10(void)
{
    if ((gBtl->flags & BTL_FLAG_UNK40) != 0)
    {
        func_00109f60(2, 0);
        func_00109f60(3, 0);
        func_00109f60(4, 0);
        H_Snd_StopBgm();
    }
}

// FUN_002dcf80
void btlSound002dcf80(s16 channel, s32 fadeFrames)
{
    func_0010a100(channel, 0, (u16)fadeFrames);
}

// FUN_002dcfb0
void func_002dcfb0(u16* work)
{
    uintptr_t address;
    u8* slot;

    address = (u32)work[0] * 6;
    address += (uintptr_t)gBtl;
    slot = (u8*)address;
    if (*(s16*)(slot + 0xa94) != work[1] || *(s16*)(slot + 0xa96) != work[2])
    {
        H_Snd_FUN_0010a0e0(1, (s16)work[0]);
    }
}

// FUN_002dd020
u32 func_002dd020(u16* work)
{
    u16 channel;
    u16 expectedCue;
    uintptr_t address;
    u8* slot;
    expectedCue = work[1];
    channel = work[0];
    address = (u32)channel * 6;
    address += (uintptr_t)gBtl;
    slot = (u8*)address;
    if (*(s16*)(slot + 0xa94) != expectedCue || *(s16*)(slot + 0xa96) != work[2])
    {
        func_0010a4e0(1, (s16)channel, (s16)expectedCue, (s16)work[2]);
        {
            u16 value;
            u32 base;

            value = work[1];
            base = (u32)gBtl;
            ((u16*)((u8*)base + 0xa94))[work[0] * 3] = value;
        }
        {
            u16 value;
            u32 base;

            value = work[2];
            base = (u32)gBtl;
            ((u16*)((u8*)base + 0xa96))[work[0] * 3] = value;
        }
        {
            u32 base;

            base = (u32)gBtl;
            ((u8*)((u8*)base + 0xa98))[work[0] * 6] = 0;
        }
    }
    return 1;
}

// FUN_002dd100
void func_002dd100(u16 channel, u16 cue, u16 variant)
{
    BtlPacket* packet = btlPacketCreate(0x902, 6);
    u16* work;

    packet->initFunc = (BtlPacketInitFunc)func_002dcfb0;
    packet->updateFunc = (BtlPacketUpdateFunc)func_002dd020;
    work = (u16*)packet->workData;
    work[0] = channel;
    work[1] = cue;
    work[2] = variant;
}

// FUN_002dd180
void func_002dd180(u16* work)
{
    H_Snd_FUN_0010a0e0(0, (s16)*work);
}
// FUN_002dd1b0
u32 func_002dd1b0(s16* work)
{
    func_0010a4e0(0, work[0], work[1], work[2]);
    return 1;
}

// FUN_002dd1f0
void func_002dd1f0(u16 channel, u16 cue, u16 variant)
{
    BtlPacket* packet = btlPacketCreate(0x901, 6);
    u16* work;

    packet->initFunc = (BtlPacketInitFunc)func_002dd180;
    packet->updateFunc = (BtlPacketUpdateFunc)func_002dd1b0;
    work = (u16*)packet->workData;
    work[0] = channel;
    work[1] = cue;
    work[2] = variant;
}

// FUN_002dd270
void btlSoundInitSkillSEPacket(void* work)
{
    BtlSoundPacketSkillSE* packet;
    char buffer[128];

    packet = (BtlSoundPacketSkillSE*)work;

    if (!(packet->flags & BTLSOUND_SKILLSE_FLAG_UNK01))
    {
        sprintf(buffer, "%s%03X.se", "skill/", packet->skillId);
        packet->cdvd = H_Cdvd_Request(buffer, HCDVD_FILENORMAL);
    }
    else
    {
        packet->cdvd = NULL;
    }

    packet->state = 1;
    packet->timer = 0;
}

// FUN_002dd2f0
u32 btlSoundUpdateSkillSEPacket(void* work)
{
    BtlSoundPacketSkillSE* packet = (BtlSoundPacketSkillSE*)work;
    char buffer[128];
    void* file1;
    void* file2;
    void* file3;
    u32 file1Size;
    u32 file2Size;
    u32 file3Size;
    s32 i;

    if (packet->cdvd == NULL)
    {
        sprintf(buffer, "%s%03X.se", "skill/", packet->skillId);
        packet->cdvd = H_Cdvd_Request(buffer, HCDVD_FILENORMAL);
    }

    switch (packet->state)
    {
    case 1:
        if (!H_Cdvd_IsFileLoaded(packet->cdvd))
        {
            return 0;
        }

        H_Snd_FUN_0010a0e0(2, 4);
        for (i = 5; i <= 9; i++)
        {
            H_Snd_FUN_0010a0e0(2, (s16)i);
        }

        file1 = H_Cdvd_ArchiveGetFile(packet->cdvd, 0, &file1Size);
        file2 = H_Cdvd_ArchiveGetFile(packet->cdvd, 1, &file2Size);
        file3 = H_Cdvd_ArchiveGetFile(packet->cdvd, 2, &file3Size);
        H_Snd_FUN_00109ae0(2, file1, file1Size, file2, file2Size, file3, file3Size);
        packet->state = 2;
        break;
    case 2:
        if (!H_Snd_FUN_00109df0(2))
        {
            return 0;
        }

        H_Cdvd_Destroy(packet->cdvd);
        return 1;
    }

    packet->timer++;
    return 0;
}

// FUN_002dd4a0
BtlPacket* btlSoundCreateSkillSEPacket(u16 skillId, u16 flags)
{
    BtlPacket* packet;
    BtlSoundPacketSkillSE* work;

    packet = btlPacketCreate(BTLSOUND_PACKET_SKILLSE, sizeof(BtlSoundPacketSkillSE));
    packet->unk_47 &= ~(1 << 0);
    packet->initFunc = btlSoundInitSkillSEPacket;
    packet->updateFunc = btlSoundUpdateSkillSEPacket;
    work = (BtlSoundPacketSkillSE*)packet->workData;
    work->skillId = skillId;
    work->flags = flags;
    return packet;
}

/* Recovered battle-misc harvest: 0x002DD8E0-0x002E2A60 */
// FUN_002dd510
u32 func_002dd510(u16* work)
{
    u16 state = *work;

    switch (state)
    {
    case 0:
        func_0010a4e0(2, 4, 0, (s16)state);
        break;
    case 1:
        if (*(s8*)((u8*)gBtl + 0xa92) == -1)
        {
            u16 nextState;
            func_0010a4e0(2, *(s16*)((u8*)gBtl + 0xa90), 0, (s16)state);
            *(u8*)((u8*)gBtl + 0xa92) = 0;
            nextState = ++(*(u16*)((u8*)gBtl + 0xa90));
            if (nextState >= 9)
            {
                *(u16*)((u8*)gBtl + 0xa90) = 5;
            }
        }
        break;
    default:
        break;
    }
    return 1;
}

// FUN_002dd5e0
void func_002dd5e0(u16 state)
{
    BtlPacket* packet = btlPacketCreate(0x904, 2);
    packet->updateFunc = (BtlPacketUpdateFunc)func_002dd510;
    *(u16*)packet->workData = state;
}

// FUN_002dd630
u32 func_002dd630(u16* work)
{
    char path[512];
    func_00523ac8(path, gp0xffff9c90, DAT_00697bb0,
                  *(u32*)(work + 2));
    func_0010a370((s16)*work, path);
    return 1;
}

// FUN_002dd690
BtlPacket* func_002dd690(u16 channel, const char* streamName)
{
    u32 length = func_00524388(streamName);
    BtlPacket* packet = btlPacketCreate(0x905, length + 8);
    u8* work;
    packet->updateFunc = (BtlPacketUpdateFunc)func_002dd630;
    work = (u8*)packet->workData;
    *(u16*)work = channel;
    *(char**)(work + 4) = (char*)(work + 8);
    strcpy((char*)work + 8, streamName);
    return packet;
}

// FUN_002dd720
u32 func_002dd720(BtlSoundThreeCueWorkView* work)
{
    volatile /* Removing this qualifier loses func_002dd720 (MATCH nd0 -> MISMATCH nd8, size 52 -> 52) - measured W170. */ s16* parameterPtr = &work->parameter;
    func_0010a240(work->channel, work->streamData, *parameterPtr);
    return 1;
}

// FUN_002dd760
void func_002dd760(u16 channel, void* streamData, u32 parameter)
{
    BtlPacket* packet = btlPacketCreate(0x907, 0xc);
    BtlSoundThreeCueWork* work;

    packet->updateFunc = (BtlPacketUpdateFunc)func_002dd720;
    work = (BtlSoundThreeCueWork*)packet->workData;
    work->channel = channel;
    work->streamData = (u32)(uintptr_t)streamData;
    work->parameter = parameter;
}

// FUN_002dd7d0
u32 func_002dd7d0(u16* work)
{
    BtlUnit* unit = *(BtlUnit**)work;
    if ((unit->flags2 & BTLUNIT_FLAG2_UPDATE) == 0)
    {
        return 1;
    }
    func_0031f6d0((u8*)unit->mdl + 0x3f8,
                  work[2], work[3], work[4]);
    return 1;
}

// FUN_002dd830
void func_002dd830(BtlUnit* unit, u16 a, u16 b, u16 c)
{
    BtlPacket* packet = btlPacketCreate(0x908, 0xc);
    void* work;

    packet->updateFunc = (BtlPacketUpdateFunc)func_002dd7d0;
    work = packet->workData;
    *(BtlUnit**)work = unit;
    *(u16*)((u8*)work + 4) = a;
    *(u16*)((u8*)work + 6) = b;
    *(u16*)((u8*)work + 8) = c;
}

// FUN_002DD8B0 (retail callback; no standalone inventory marker)
u32 func_002DD8B0(void** work)
{
    BtlUnit* unit = (BtlUnit*)work[0];
    if ((unit->flags2 & BTLUNIT_FLAG2_UPDATE) != 0)
    {
        u16* flags = (u16*)((u8*)unit->mdl + 0x3fe);
        *flags |= 0x20;
    }
    return 1;
}

// FUN_002DD8E0


void FUN_002dd8e0(u32 param_1)



{

  int iVar1;

  

  iVar1 = FUN_0027ec10(0x909,4);

  *(u8 **)(iVar1 + 0x6c) = (u8 *)LAB_002dd8b0;

  **(u32 **)(iVar1 + 0x78) = param_1;

  return;

}



// FUN_002DD930
int func_002DD930(int* param_1)
{
    int battleWork;

    if ((*(u32*)(*param_1 + 0x98) & 2) != 0)
    {
        battleWork = *(int*)(*param_1 + 0x9f4);
        *(u16*)(battleWork + 0x3fe) &= 0xffdf;
    }

    return 1;
}

// FUN_002DD960


void FUN_002dd960(u32 param_1)



{

  int iVar1;

  

  iVar1 = FUN_0027ec10(0x90a,4);

  *(u8 **)(iVar1 + 0x6c) = (u8 *)LAB_002dd930;

  **(u32 **)(iVar1 + 0x78) = param_1;

  return;

}

// FUN_002dd9b0
void func_002dd9b0(void)
{
    char path[256];
    void* (**allocate)(u32 size, u32 heap);
    u32 state;
    void* memory;

    allocate = (void* (**)(u32, u32))DAT_00960178_abs;
    memory = (*allocate)(0xacc, 0x40000);
    func_00523ac8(path, DAT_00697bc0, 0x1c2, 1);
    func_001024a0((void*)(uintptr_t)3, path, 0, memory);
    goto btlSound_status1;
btlSound_retry1:
    if (state == 4)
    {
        func_001024a0((void*)(uintptr_t)3, path, 0, memory);
    }
btlSound_status1:
    state = func_0053c268(3);
    if (state != 3)
    {
        goto btlSound_retry1;
    }
    DAT_007CE4FC = 1;

    memory = (*allocate)(0x540, 0x40000);
    func_00523ac8(path, DAT_00697bc0, 0x1c3, 1);
    func_001024a0((void*)(uintptr_t)4, path, 0, memory);
    goto btlSound_status2;
btlSound_retry2:
    if (state == 4)
    {
        func_001024a0((void*)(uintptr_t)4, path, 0, memory);
    }
btlSound_status2:
    state = func_0053c268(4);
    if (state != 3)
    {
        goto btlSound_retry2;
    }

    allocate = (void* (**)(u32, u32))(*allocate)(0xa0c, 0x40000);
    func_00523ac8(path, DAT_00697bc0, 0x1c4, 1);
    func_001024a0((void*)(uintptr_t)5, path, 0, allocate);
    goto btlSound_status3;
btlSound_retry3:
    if (state == 4)
    {
        func_001024a0((void*)(uintptr_t)5, path, 0, allocate);
    }
btlSound_status3:
    state = func_0053c268(5);
    if (state != 3)
    {
        goto btlSound_retry3;
    }
    DAT_007CE500 = 1;
}

// FUN_002ddba0
void func_002ddba0(u32 id)
{
    func_0010a2e0((void*)(uintptr_t)*(u16*)((u8*)gBtl + 0xaf8), 4, id);
}

// FUN_002ddbe0
void func_002ddbe0(void)
{
    func_0010a100(4, 0, 8);
}

// FUN_002ddc10
u32 func_002ddc10(u32 unitId)
{
    u16 id;
    s32 flag;

    id = unitId;
    if (id < 2)
    {
        return 0;
    }
    flag = DAT_00697BD8[id];
    if (flag == -1)
    {
        return 0;
    }
    return datGetFlag(flag);
}

// FUN_002ddc80
u32 func_002ddc80(u16 charId)
{
    u32 result;

    switch (charId)
    {
    case 1:
        result = 0;
        break;
    case 2:
        result = datGetFlag(0x1357) == 0;
        break;
    case 3:
        result = datGetFlag(0x1358) == 0;
        break;
    case 4:
        result = datGetFlag(0x1359) == 0;
        break;
    case 5:
        result = datGetFlag(0x135a) == 0;
        break;
    case 7:
        result = datGetFlag(0x135b) == 0;
        break;
    case 8:
        result = datGetFlag(0x135c) == 0;
        break;
    case 9:
        result = datGetFlag(0x135d) == 0;
        break;
    case 10:
        result = datGetFlag(0x135e) == 0;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}

// FUN_002DDDC0


u32 FUN_002dddc0(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    lVar2 = FUN_0016f190(0x184);
    if (lVar2 == 0) {
        return 0xffffffff;
    }

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0x92;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0xdc : 0xdb;
        break;
    case 4:
        uVar1 = 0x148;
        break;
    case 5:
        uVar1 = 0x191;
        break;
    case 7:
        uVar1 = 0x1da;
        break;
    case 8:
        uVar1 = 0x223;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x45d : 0x26c;
        break;
    case 10:
        uVar1 = 0x2ad;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}

// FUN_002DDF10


u32 FUN_002ddf10(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0x93;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0xde : 0xdd;
        break;
    case 4:
        uVar1 = 0x149;
        break;
    case 5:
        uVar1 = 0x192;
        break;
    case 7:
        uVar1 = 0x1db;
        break;
    case 8:
        uVar1 = 0x224;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x45e : 0x26d;
        break;
    case 10:
        uVar1 = 0x2ae;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}

// FUN_002DE030


u32 FUN_002de030(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0x94;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0xe0 : 0xdf;
        break;
    case 4:
        uVar1 = 0x14a;
        break;
    case 5:
        uVar1 = 0x193;
        break;
    case 7:
        uVar1 = 0x1dc;
        break;
    case 8:
        uVar1 = 0x225;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x45f : 0x26e;
        break;
    case 10:
        uVar1 = 0x2af;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}

// FUN_002DE150


u32 FUN_002de150(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    lVar2 = FUN_0016f190(0x184);
    if (lVar2 == 0) {
        return 0xffffffff;
    }

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0xae;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0x100 : 0xff;
        break;
    case 4:
        uVar1 = 0x164;
        break;
    case 5:
        uVar1 = 0x1ad;
        break;
    case 7:
        uVar1 = 0x1f6;
        break;
    case 8:
        uVar1 = 0x23f;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x471 : 0x280;
        break;
    case 10:
        uVar1 = 0x2c8;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}

// FUN_002DE2A0


u32 FUN_002de2a0(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0xb0;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0x104 : 0x103;
        break;
    case 4:
        uVar1 = 0x166;
        break;
    case 5:
        uVar1 = 0x1af;
        break;
    case 7:
        uVar1 = 0x20b;
        break;
    case 8:
        uVar1 = 0x233;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x473 : 0x282;
        break;
    case 10:
        uVar1 = 0xffffffff;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}

// FUN_002DE3C0


u32 FUN_002de3c0(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0xaf;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0x102 : 0x101;
        break;
    case 4:
        uVar1 = 0x165;
        break;
    case 5:
        uVar1 = 0x1ae;
        break;
    case 7:
        uVar1 = 0x1f7;
        break;
    case 8:
        uVar1 = 0x240;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x472 : 0x281;
        break;
    case 10:
        uVar1 = 0x2c9;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}

// FUN_002DE4E0


u32 FUN_002de4e0(int param_1)



{

  u32 uVar1;

  s32 uVar2;

  s32 uVar3;

  s32 lVar4;

  

  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != '\0') {

    return 0xffffffff;

  }

  if (*(int *)(DAT_007ce3ec + 0x148) == param_1) {
    return 0xffffffff;
  }

  uVar1 = *(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c);

    uVar2 = (u16)FUN_002ffd70_y2(uVar1);

    uVar3 = (u16)FUN_002ffdf0_y2(uVar1);

    uVar2 = ((uVar2 & 0xffff) * 100) / (uVar3 & 0xffff);

    if ((uVar2 > 0x46) && (*(int *)(param_1 + 0x20) < 3)) {
      switch(*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {

      case 2:

        if (*(s32 *)DAT_00697BE0_abs == -1) {

          lVar4 = 0;

        }

        else {

          lVar4 = FUN_0016f190(*(s32 *)DAT_00697BE0_abs);

        }

        return lVar4 != 0 ? 0x9f : 0x9c;

      case 3:

        if (*(s32 *)DAT_00697be4_abs == -1) {

          lVar4 = 0;

        }

        else {

          lVar4 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);

        }

        if (lVar4 != 0) {
          uVar1 = 0xf0;
        }
        else {
          uVar1 = 0xed;
        }
        return uVar1;

      case 4:

        if (*(s32 *)DAT_00697BE8_abs == -1) {

          lVar4 = 0;

        }

        else {

          lVar4 = FUN_0016f190(*(s32 *)DAT_00697BE8_abs);

        }

        if (lVar4 != 0) {
          uVar1 = 0x155;
        }
        else {
          uVar1 = 0x152;
        }
        return uVar1;

      case 5:

        if (*(s32 *)DAT_00697BEC_abs == -1) {

          lVar4 = 0;

        }

        else {

          lVar4 = FUN_0016f190(*(s32 *)DAT_00697BEC_abs);

        }

        if (lVar4 != 0) {
          uVar1 = 0x19e;
        }
        else {
          uVar1 = 0x19b;
        }
        return uVar1;

      case 7:

        if (*(s32 *)DAT_00697BF4_abs == -1) {

          lVar4 = 0;

        }

        else {

          lVar4 = FUN_0016f190(*(s32 *)DAT_00697BF4_abs);

        }

        if (lVar4 != 0) {
          uVar1 = 0x1e7;
        }
        else {
          uVar1 = 0x1e4;
        }
        return uVar1;

      case 8:

        if (*(s32 *)DAT_00697BF8_abs == -1) {

          lVar4 = 0;

        }

        else {

          lVar4 = FUN_0016f190(*(s32 *)DAT_00697BF8_abs);

        }

        if (lVar4 != 0) {
          uVar1 = 0x230;
        }
        else {
          uVar1 = 0x22d;
        }
        return uVar1;

      case 9:

        lVar4 = FUN_0017d800();

        if (lVar4 == 0) {

          if (*(s32 *)DAT_00697BFC_abs != -1) {

            FUN_0016f190(*(s32 *)DAT_00697BFC_abs);

          }

          return 0x276;

        }

        if (*(s32 *)DAT_00697BFC_abs != -1) {

          FUN_0016f190(*(s32 *)DAT_00697BFC_abs);

        }

        return 0x467;

      case 10:

        if (*(s32 *)DAT_00697c00_abs == -1) {

          lVar4 = 0;

        }

        else {

          lVar4 = FUN_0016f190(*(s32 *)DAT_00697c00_abs);

        }

        if (lVar4 != 0) {
          uVar1 = 0x2ba;
        }
        else {
          uVar1 = 0x2b7;
        }
        return uVar1;

      }
    }
    else {

      if (uVar2 > 0x1e) {
        switch(*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {

        case 2:

        if (*(s32 *)DAT_00697BE0_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BE0_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0xa0;
          }
          else {
            uVar1 = 0x9d;
          }
          return uVar1;

        case 3:

        if (*(s32 *)DAT_00697be4_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0xf1;
          }
          else {
            uVar1 = 0xee;
          }
          return uVar1;

        case 4:

        if (*(s32 *)DAT_00697BE8_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BE8_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0x156;
          }
          else {
            uVar1 = 0x153;
          }
          return uVar1;

        case 5:

        if (*(s32 *)DAT_00697BEC_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BEC_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0x19f;
          }
          else {
            uVar1 = 0x19c;
          }
          return uVar1;

        case 7:

        if (*(s32 *)DAT_00697BF4_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BF4_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0x1e8;
          }
          else {
            uVar1 = 0x1e5;
          }
          return uVar1;

        case 8:

        if (*(s32 *)DAT_00697BF8_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BF8_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0x231;
          }
          else {
            uVar1 = 0x22e;
          }
          return uVar1;

        case 9:

          lVar4 = FUN_0017d800();

          if (lVar4 == 0) {

          if (*(s32 *)DAT_00697BFC_abs != -1) {

              FUN_0016f190(*(s32 *)DAT_00697BFC_abs);

            }

            return 0x277;

          }

        if (*(s32 *)DAT_00697BFC_abs != -1) {

            FUN_0016f190(*(s32 *)DAT_00697BFC_abs);

          }

          return 0x468;

        case 10:

        if (*(s32 *)DAT_00697c00_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697c00_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 699;
          }
          else {
            uVar1 = 0x2b8;
          }
          return uVar1;

        }
      }
      else {

        switch(*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {

        case 2:

          if (*(s32 *)DAT_00697BE0_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BE0_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0xa1;
          }
          else {
            uVar1 = 0x9e;
          }
          return uVar1;

        case 3:

          if (*(s32 *)DAT_00697be4_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0xf2;
          }
          else {
            uVar1 = 0xef;
          }
          return uVar1;

        case 4:

          if (*(s32 *)DAT_00697BE8_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BE8_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0x157;
          }
          else {
            uVar1 = 0x154;
          }
          return uVar1;

        case 5:

          if (*(s32 *)DAT_00697BEC_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BEC_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0x1a0;
          }
          else {
            uVar1 = 0x19d;
          }
          return uVar1;

        case 7:

          if (*(s32 *)DAT_00697BF4_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BF4_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0x1e9;
          }
          else {
            uVar1 = 0x1e6;
          }
          return uVar1;

        case 8:

          if (*(s32 *)DAT_00697BF8_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697BF8_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 0x232;
          }
          else {
            uVar1 = 0x22f;
          }
          return uVar1;

        case 9:

          lVar4 = FUN_0017d800();

          if (lVar4 == 0) {

            if (*(s32 *)DAT_00697BFC_abs != -1) {

              FUN_0016f190(*(s32 *)DAT_00697BFC_abs);

            }

            return 0x278;

          }

          if (*(s32 *)DAT_00697BFC_abs != -1) {

            FUN_0016f190(*(s32 *)DAT_00697BFC_abs);

          }

          return 0x469;

        case 10:

          if (*(s32 *)DAT_00697c00_abs == -1) {

            lVar4 = 0;

          }

          else {

            lVar4 = FUN_0016f190(*(s32 *)DAT_00697c00_abs);

          }

          if (lVar4 != 0) {
            uVar1 = 700;
          }
          else {
            uVar1 = 0x2b9;
          }
          return uVar1;

        }

      }


    }

    return 0xffffffff;


  return 0xffffffff;

}

// FUN_002DED60
u32 FUN_002ded60(int param_1)
{
    u32 uVar1;
    s32 lVar2;
    u8* unit;

    unit = *(u8**)(param_1 + 0x30);
    if (unit[0xa2] != 0)
    {
        return 0xffffffff;
    }

    switch (*(u16*)(unit + 0xa4))
    {
    case 2:
        if (*(s32*)DAT_00697BE0_abs == -1)
        {
            lVar2 = 0;
        }
        else
        {
            lVar2 = FUN_0016f190(*(s32*)DAT_00697BE0_abs);
        }
        uVar1 = (lVar2 != 0) ? 0xa5 : 0xa4;
        break;
    case 3:
        if (*(s32*)DAT_00697be4_abs == -1)
        {
            lVar2 = 0;
        }
        else
        {
            lVar2 = FUN_0016f190(*(s32*)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0xf6 : 0xf5;
        break;
    case 4:
        if (*(s32*)DAT_00697BE8_abs == -1)
        {
            lVar2 = 0;
        }
        else
        {
            lVar2 = FUN_0016f190(*(s32*)DAT_00697BE8_abs);
        }
        uVar1 = (lVar2 != 0) ? 0x15b : 0x15a;
        break;
    case 5:
        if (*(s32*)DAT_00697BEC_abs == -1)
        {
            lVar2 = 0;
        }
        else
        {
            lVar2 = FUN_0016f190(*(s32*)DAT_00697BEC_abs);
        }
        uVar1 = (lVar2 != 0) ? 0x1a4 : 0x1a3;
        break;
    case 7:
        if (*(s32*)DAT_00697BF4_abs == -1)
        {
            lVar2 = 0;
        }
        else
        {
            lVar2 = FUN_0016f190(*(s32*)DAT_00697BF4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0x1ed : 0x1ec;
        break;
    case 8:
        if (*(s32*)DAT_00697BF8_abs == -1)
        {
            lVar2 = 0;
        }
        else
        {
            lVar2 = FUN_0016f190(*(s32*)DAT_00697BF8_abs);
        }
        uVar1 = (lVar2 != 0) ? 0x236 : 0x235;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        if (lVar2 == 0)
        {
            if (*(s32*)DAT_00697BFC_abs != -1)
            {
                FUN_0016f190(*(s32*)DAT_00697BFC_abs);
            }
            uVar1 = 0x27a;
        }
        else
        {
            if (*(s32*)DAT_00697BFC_abs != -1)
            {
                FUN_0016f190(*(s32*)DAT_00697BFC_abs);
            }
            uVar1 = 0x46a;
        }
        break;
    case 10:
        uVar1 = 0xffffffff;
        break;
    default:
        uVar1 = 0xffffffff;
        break;
    }

    return uVar1;
}

// FUN_002DEFE0


u32 FUN_002defe0(int param_1)



{

  int iVar1;

  s32 lVar2;

  u32 uVar3;

  u32 uVar4;

  int aiStack_30 [12];
  
  lVar2 = FUN_0010a500(4);
  if (lVar2 == 1) {
    return 0xffffffff;
  }

  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {

    return 0xffffffff;

  }

  lVar2 = FUN_00300580_y2(*(u32 *)(*(int *)(param_1 + 0x30) + 0xa2c), 1);

  if (lVar2 != 0) {

    return 0xffffffff;

  }

  uVar4 = 0;

  for (iVar1 = *(int *)(DAT_007ce3ec + 0x150); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xa34)) {

    lVar2 = FUN_0030b5a0(*(u32 *)(iVar1 + 0xa2c),0);

    if (((lVar2 == 0) && (lVar2 = FUN_00300580_y2(*(u32 *)(iVar1 + 0xa2c),0x180375), lVar2 == 0)

        ) && (*(u16 *)(iVar1 + 0xa4) != 1)) {

      aiStack_30[uVar4 & 0xffff] = iVar1;

      uVar4 = uVar4 + 1 & 0xffff;

    }

  }

  if ((uVar4 & 0xffff) == 0) {
    return -1;
  }


  {

    iVar1 = FUN_002ffbc0(uVar4 & 0xffff);

    iVar1 = aiStack_30[iVar1];

    if (iVar1 == 0) {

      return 0xffffffff;

    }

    switch(*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {

    case 1:

      switch(*(u16 *)(iVar1 + 0xa4)) {

      case 2:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0xb1 : 0xb2;
        return uVar3;

      case 3:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x10f : 0x110;
        return uVar3;

      case 4:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x167 : 0x168;
        return uVar3;

      case 5:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x1b0 : 0x1b1;
        return uVar3;

      case 7:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x1f9 : 0x1fa;
        return uVar3;

      case 8:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x242 : 0x243;
        return uVar3;

      case 9:

        lVar2 = FUN_0017d800();

        if (lVar2 == 0) {
        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x283 : 0x284;
        return uVar3;
        } else {

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x47e : 0x47f;
          return uVar3;

        }

      case 10:

        return 0xffffffff;

      }

      break;

    case 2:

      switch(*(u16 *)(iVar1 + 0xa4)) {

      case 2:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0xb3 : 0xb4;
        return uVar3;

      case 3:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x111 : 0x112;
        return uVar3;

      case 4:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x169 : 0x16a;
        return uVar3;

      case 5:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x1b2 : 0x1b3;
        return uVar3;

      case 7:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x1fb : 0x1fc;
        return uVar3;

      case 8:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x244 : 0x245;
        return uVar3;

      case 9:

        lVar2 = FUN_0017d800();

        if (lVar2 == 0) {
        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x285 : 0x286;
        return uVar3;
        } else {

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x480 : 0x481;
          return uVar3;

        }

      case 10:

        return 0xffffffff;

      }

      break;

    case 3:

      switch(*(u16 *)(iVar1 + 0xa4)) {

      case 2:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0xb5 : 0xb6;
        return uVar3;

      case 3:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x113 : 0x114;
        return uVar3;

      case 4:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x16b : 0x16c;
        return uVar3;

      case 5:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x1b4 : 0x1b5;
        return uVar3;

      case 7:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x1fd : 0x1fe;
        return uVar3;

      case 8:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x246 : 0x247;
        return uVar3;

      case 9:

        lVar2 = FUN_0017d800();

        if (lVar2 == 0) {
        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x287 : 0x288;
        return uVar3;
        } else {

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x482 : 0x483;
          return uVar3;

        }

      case 10:

        return 0xffffffff;

      }

      break;

    case 4:

      switch(*(u16 *)(iVar1 + 0xa4)) {

      case 2:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0xb7 : 0xb8;
        return uVar3;

      case 3:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x115 : 0x116;
        return uVar3;

      case 4:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x16d : 0x16e;
        return uVar3;

      case 5:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x1b6 : 0x1b7;
        return uVar3;

      case 7:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x1ff : 0x200;
        return uVar3;

      case 8:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x248 : 0x249;
        return uVar3;

      case 9:

        lVar2 = FUN_0017d800();

        if (lVar2 == 0) {
        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x289 : 0x28a;
        return uVar3;
        } else {

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x484 : 0x485;
          return uVar3;

        }

      case 10:

        return 0xffffffff;

      }

      break;

    case 5:

      switch(*(u16 *)(iVar1 + 0xa4)) {

      case 2:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0xb9 : 0xba;
        return uVar3;

      case 3:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x117 : 0x118;
        return uVar3;

      case 4:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x16f : 0x170;
        return uVar3;

      case 5:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x1b8 : 0x1b9;
        return uVar3;

      case 7:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x201 : 0x202;
        return uVar3;

      case 8:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x24a : 0x24b;
        return uVar3;

      case 9:

        lVar2 = FUN_0017d800();

        if (lVar2 == 0) {
        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x28b : 0x28c;
        return uVar3;
        } else {

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x486 : 0x487;
          return uVar3;

        }

      case 10:

        return 0xffffffff;

      }

      break;

    case 7:

      switch(*(u16 *)(iVar1 + 0xa4)) {

      case 2:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0xbb : 0xbc;
        return uVar3;

      case 3:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x119 : 0x11a;
        return uVar3;

      case 4:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x171 : 0x172;
        return uVar3;

      case 5:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x1ba : 0x1bb;
        return uVar3;

      case 7:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x203 : 0x204;
        return uVar3;

      case 8:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x24c : 0x24d;
        return uVar3;

      case 9:

        lVar2 = FUN_0017d800();

        if (lVar2 == 0) {
        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x28d : 0x28e;
        return uVar3;
        } else {

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x488 : 0x489;
          return uVar3;

        }

      case 10:

        return 0xffffffff;

      }

      break;

    case 8:

      switch(*(u16 *)(iVar1 + 0xa4)) {

      case 2:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0xbd : 0xbe;
        return uVar3;

      case 3:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x11b : 0x11c;
        return uVar3;

      case 4:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x173 : 0x174;
        return uVar3;

      case 5:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x1bc : 0x1bd;
        return uVar3;

      case 7:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x205 : 0x206;
        return uVar3;

      case 8:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x24e : 0x24f;
        return uVar3;

      case 9:

        lVar2 = FUN_0017d800();

        if (lVar2 == 0) {
        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x28f : 0x290;
        return uVar3;
        } else {

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x488 : 0x489;
          return uVar3;

        }

      case 10:

        return 0xffffffff;

      }

      break;

    case 9:

      lVar2 = FUN_0017d800();

      if (lVar2 == 0) {

        switch(*(u16 *)(iVar1 + 0xa4)) {

        case 2:

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0xbf : 0xc0;
          return uVar3;

        case 3:

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x11d : 0x11e;
          return uVar3;

        case 4:

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x175 : 0x176;
          return uVar3;

        case 5:

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x1be : 0x1bf;
          return uVar3;

        case 7:

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x207 : 0x208;
          return uVar3;

        case 8:

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x250 : 0x251;
          return uVar3;

        case 9:

          lVar2 = FUN_0017d800();

          if (lVar2 == 0) {
          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x291 : 0x292;
          return uVar3;
          } else {

            uVar3 = FUN_002ffbc0(100);

            uVar3 = uVar3 >= 0x32 ? 0x48a : 0x48b;
            return uVar3;

          }

        case 10:

          return 0xffffffff;

        }

      }

      else {

        switch(*(u16 *)(iVar1 + 0xa4)) {

        case 2:

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0xc3 : 0xc4;
          return uVar3;

        case 3:

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x121 : 0x122;
          return uVar3;

        case 4:

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x179 : 0x17a;
          return uVar3;

        case 5:

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x1c2 : 0x1c3;
          return uVar3;

        case 7:

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x20b : 0x20c;
          return uVar3;

        case 8:

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x254 : 0x255;
          return uVar3;

        case 9:

          lVar2 = FUN_0017d800();

          if (lVar2 == 0) {
          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x295 : 0x296;
          return uVar3;
          } else {

            uVar3 = FUN_002ffbc0(100);

            uVar3 = uVar3 >= 0x32 ? 0x480 : 0x481;
            return uVar3;

          }

        case 10:

          return 0xffffffff;

        }

      }

      break;

    case 10:

      switch(*(u16 *)(iVar1 + 0xa4)) {

      case 2:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0xc1 : 0xc2;
        return uVar3;

      case 3:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x11f : 0x120;
        return uVar3;

      case 4:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x177 : 0x178;
        return uVar3;

      case 5:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x1c0 : 0x1c1;
        return uVar3;

      case 7:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x209 : 0x20a;
        return uVar3;

      case 8:

        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x252 : 0x253;
        return uVar3;

      case 9:

        lVar2 = FUN_0017d800();

        if (lVar2 == 0) {
        uVar3 = FUN_002ffbc0(100);

        uVar3 = uVar3 >= 0x32 ? 0x293 : 0x294;
        return uVar3;
        } else {

          uVar3 = FUN_002ffbc0(100);

          uVar3 = uVar3 >= 0x32 ? 0x48c : 0x48d;
          return uVar3;

        }

      case 10:

        return 0xffffffff;

      }

    }

    return 0xffffffff;

  }

  return 0xffffffff;

}

// FUN_002E0350
u32 FUN_002e0350(int param_1)
{
    u32 result;
    BtlUnit* unit;

    unit = *(BtlUnit**)(param_1 + 0x30);
    if (unit->genus != 0)
    {
        result = 0xffffffff;
    }
    else
    {
        switch (unit->charId)
        {
        case 2:
            result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0xd7 : 0xd8;
            break;
        case 3:
            result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x135 : 0x136;
            break;
        case 4:
            result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x18d : 0x18e;
            break;
        case 5:
            result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x1d6 : 0x1d7;
            break;
        case 7:
            result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x21f : 0x220;
            break;
        case 8:
            result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x268 : 0x269;
            break;
        case 9:
            if (FUN_0017d800() == 0)
            {
                result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x2a9 : 0x2aa;
            }
            else
            {
                FUN_002ffbc0(100);
                result = 0x4a3;
            }
            break;
        case 10:
            result = 0xffffffff;
            break;
        default:
            result = 0xffffffff;
        }
    }
    return result;
}

// FUN_002E0540


u32 FUN_002e0540(int param_1)
{
  u32 result;
  BtlUnit* unit;

  unit = *(BtlUnit**)(param_1 + 0x30);
  if (unit->genus != 0) {
    result = 0xffffffff;
  } else {
    switch (unit->charId) {
    case 2:
      result = 0xd9;
      break;
    case 3:
      result = 0x146;
      break;
    case 4:
      result = 399;
      break;
    case 5:
      result = 0x1d8;
      break;
    case 7:
      result = 0x221;
      break;
    case 8:
      result = 0x26a;
      break;
    case 9:
      result = FUN_0017d800() != 0 ? 0x4b2 : 0x2ab;
      break;
    case 10:
      result = 0xffffffff;
      break;
    default:
      result = 0xffffffff;
    }
  }
  return result;
}

 
// FUN_002E0620


int FUN_002e0620(int param_1,int param_2)



{

  u16 sVar1;

  int iVar2;

  u32 lVar3;

  u32 uVar4;

  

  iVar2 = *(int *)(param_1 + 0x30);

  if (*(int *)(iVar2 + 0xa00) == 0) {

    return -1;

  }

  if (*(u8 *)(iVar2 + 0xa2) == 1) {
    sVar1 = *(u16 *)(iVar2 + 0xa4);
    switch (sVar1) {
    case 0x10b: return 0x2f7;
    case 0x10c: return 0x30b;
    case 0x110: return 0x2f8;
    case 0x10f: return 0x30c;
    case 0x108: return 0x321;
    case 0xe9: return 0x46e;
    case 0xea:
      switch (param_2) {
      case 0xc0: return 0x377;
      case 0xc1: return 0x378;
      case 0xc2: return 0x379;
      case 0xc3: return 0x37a;
      case 0xc4: return 0x37b;
      case 0xc5: return 0x37c;
      case 0xc6: return 0x37d;
      case 0xc7: return 0x37e;
      case 0xc8: return 0x37f;
      case 0xc9: return 0x380;
      case 0xca: return 0x381;
      case 0xcb: return 0x382;
      case 0xcc: return 0x383;
      case 0xcd: return 0x384;
      case 0xce: return 0x385;
      case 0xcf: return 0x386;
      case 0xd3: return 0x387;
      default: goto outer_default;
      }
    case 0xeb: return 0x1f2;
    case 0xec: return 0x23b;
    case 0xed: return 0x1a9;
    case 0xee: return 0x2c4;
    case 0xef: return 0xaa;
    case 0xf0: return 0x160;
    default:
outer_default:
      return -1;
    }
  } else {
    if (*(int *)(DAT_007ce3ec + 0x148) == param_1) {
      lVar3 = FUN_0017d800();
      if (lVar3 != 0)
        goto journey_true;
      if (param_2 == 0xa9)
        return 1;
      if (param_2 < 0x92)
        return param_2;
      return param_2 + 0x2ce;
journey_true:
      if (param_2 == 0xa9)
        return 0x388;
      return param_2 + 0x387;
    }
      
      switch(*(u16 *)(iVar2 + 0xa4)) {
      
      
      case 2:
    
        lVar3 = FUN_0016f190(0x1357);
    
        if (lVar3 == 0) {
    
          FUN_0016f1f0(0x1357,1);
    
          return 0xa8;
    
        }
    
        uVar4 = FUN_002ffbc0(100);
    
        if (uVar4 >= 0x32) {
    
          if (*(s32 *)DAT_00697BE0_abs == -1) {
    
            lVar3 = 0;
    
          }
    
          else {
    
            lVar3 = FUN_0016f190(*(s32 *)DAT_00697BE0_abs);
    
          }
    
          if (lVar3 != 0) {
    
            lVar3 = 0xa7;
    
          }
    
          else {
    
            lVar3 = 0xa6;
    
          }
    
          return lVar3;
    
        }
    
        if (*(u16 *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa00) + 0xa4) == 0xc0) {
    
          return 0xa9;
    
        }
    
        return 0xaa;
      
      case 3:
      
        lVar3 = FUN_0016f190(0x1358);
      
        if (lVar3 == 0) {
      
          FUN_0016f1f0(0x1358,1);
      
          return 0xf9;
      
        }
      
        uVar4 = FUN_002ffbc0(100);
      
        if (uVar4 >= 0x32) {
      
          if (*(s32 *)DAT_00697be4_abs == -1) {
      
            lVar3 = 0;
      
          }
      
          else {
      
            lVar3 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
      
          }
      
          if (lVar3 != 0) {
      
            lVar3 = 0xf8;
      
          }
      
          else {
      
            lVar3 = 0xf7;
      
          }
      
          return lVar3;
      
        }
      
        if (*(u16 *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa00) + 0xa4) == 0xc2) {
      
          return 0xfa;
      
        }
      
        return 0xfb;
      
      case 4:
      
        lVar3 = FUN_0016f190(0x1359);
      
        if (lVar3 == 0) {
      
          FUN_0016f1f0(0x1359,1);
      
          return 0x15e;
      
        }
      
        uVar4 = FUN_002ffbc0(100);
      
        if (uVar4 >= 0x32) {
      
          if (*(s32 *)DAT_00697BE8_abs == -1) {
      
            lVar3 = 0;
      
          }
      
          else {
      
            lVar3 = FUN_0016f190(*(s32 *)DAT_00697BE8_abs);
      
          }
      
          if (lVar3 != 0) {
      
            lVar3 = 0x15d;
      
          }
      
          else {
      
            lVar3 = 0x15c;
      
          }
      
          return lVar3;
      
        }
      
        if (*(u16 *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa00) + 0xa4) == 0xc4) {
      
          return 0x15f;
      
        }
      
        return 0x160;
      
      case 5:
      
        lVar3 = FUN_0016f190(0x135a);
      
        if (lVar3 == 0) {
      
          FUN_0016f1f0(0x135a,1);
      
          return 0x1a7;
      
        }
      
        uVar4 = FUN_002ffbc0(100);
      
        if (uVar4 >= 0x32) {
      
          if (*(s32 *)DAT_00697BEC_abs == -1) {
      
            lVar3 = 0;
      
          }
      
          else {
      
            lVar3 = FUN_0016f190(*(s32 *)DAT_00697BEC_abs);
      
          }
      
          if (lVar3 != 0) {
      
            lVar3 = 0x1a6;
      
          }
      
          else {
      
            lVar3 = 0x1a5;
      
          }
      
          return lVar3;
      
        }
      
        if (*(u16 *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa00) + 0xa4) == 0xc6) {
      
          return 0x1a8;
      
        }
      
        return 0x1a9;
      
      case 7:
      
        lVar3 = FUN_0016f190(0x135b);
      
        if (lVar3 == 0) {
      
          FUN_0016f1f0(0x135b,1);
      
          return 0x1f0;
      
        }
      
        uVar4 = FUN_002ffbc0(100);
      
        if (uVar4 >= 0x32) {
      
          if (*(s32 *)DAT_00697BF4_abs == -1) {
      
            lVar3 = 0;
      
          }
      
          else {
      
            lVar3 = FUN_0016f190(*(s32 *)DAT_00697BF4_abs);
      
          }
      
          if (lVar3 != 0) {
      
            lVar3 = 0x1ef;
      
          }
      
          else {
      
            lVar3 = 0x1ee;
      
          }
      
          return lVar3;
      
        }
      
        if (*(u16 *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa00) + 0xa4) == 0xca) {
      
          return 0x1f1;
      
        }
      
        return 0x1f2;
      
      case 8:
      
        lVar3 = FUN_0016f190(0x135c);
      
        if (lVar3 == 0) {
      
          FUN_0016f1f0(0x135c,1);
      
          return 0x239;
      
        }
      
        uVar4 = FUN_002ffbc0(100);
      
        if (uVar4 >= 0x32) {
      
          if (*(s32 *)DAT_00697BF8_abs == -1) {
      
            lVar3 = 0;
      
          }
      
          else {
      
            lVar3 = FUN_0016f190(*(s32 *)DAT_00697BF8_abs);
      
          }
      
          if (lVar3 != 0) {
      
            lVar3 = 0x238;
      
          }
      
          else {
      
            lVar3 = 0x237;
      
          }
      
          return lVar3;
      
        }
      
        if (*(u16 *)(*(int *)(*(int *)(param_1 + 0x30) + 0xa00) + 0xa4) == 0xcc) {
      
          return 0x23a;
      
        }
      
        return 0x23b;
      
      case 9:
      
        lVar3 = FUN_0016f190(0x135d);
      
        if (lVar3 == 0) {
      
          FUN_0016f1f0(0x135d,1);
      
          lVar3 = FUN_0017d800();
      
          if (lVar3 != 0) {
      
            return 0x46d;
      
          }
      
          return 0x27c;
      
        }
      
        uVar4 = FUN_002ffbc0(100);
      
        if (uVar4 >= 0x32) {
      
          lVar3 = FUN_0017d800();
      
          if (lVar3 == 0) {
      
            if (*(s32 *)DAT_00697BFC_abs != -1) {
      
              FUN_0016f190(*(s32 *)DAT_00697BFC_abs);
      
            }
      
            return 0x27b;
      
          }
      
          if (*(s32 *)DAT_00697BFC_abs != -1) {
      
            FUN_0016f190(*(s32 *)DAT_00697BFC_abs);
      
          }
      
          return 0x46c;
      
        }
      
        lVar3 = FUN_0017d800();
      
        if (lVar3 != 0) {
      
          return 0x46e;
      
        }
      
        return 0x27d;
      
      case 10:
      
        lVar3 = FUN_0016f190(0x135e);
      
        if (lVar3 == 0) {
      
          FUN_0016f1f0(0x135e,1);
      
          return 0x2c3;
      
        }
      
        uVar4 = FUN_002ffbc0(100);
      
        if (uVar4 >= 0x32) {
      
          if (*(s32 *)DAT_00697c00_abs == -1) {
      
            lVar3 = 0;
      
          }
      
          else {
      
            lVar3 = FUN_0016f190(*(s32 *)DAT_00697c00_abs);
      
          }
      
          if (lVar3 != 0) {
      
            lVar3 = 0x2c2;
      
          }
      
          else {
      
            lVar3 = 0x2c1;
      
          }
      
          return lVar3;
      
        }
      
        return 0x2c4;
      
      default:
      
        return -1;
      
      } }
}

// FUN_002E0F70


u32 FUN_002e0f70(int param_1, int param_2, int param_3)
{
    u32 category;

    if (*(u8*)(*(int*)(param_1 + 0x30) + 0xa2) != 0)
        return 0xffffffff;
    if (*(int*)(DAT_007ce3ec + 0x148) == param_1)
        return 0xffffffff;

    category = func_002d4e10(2, 0x80000) & 0xffff;
    switch (category)
    {
    case 4:
        switch (*(u16*)(*(int*)(param_1 + 0x30) + 0xa4))
        {
        case 2: return 0xc5;
        case 3: return 0x123;
        case 4: return 0x17b;
        case 5: return 0x1c4;
        case 7: return 0x20d;
        case 8: return 0x256;
        case 9:
            if (FUN_0017d800() != 0) return 0x490;
            return 0x297;
        case 10: return 0xffffffff;
        }
        break;
    case 3:
        switch (*(u16*)(*(int*)(param_1 + 0x30) + 0xa4))
        {
        case 2: return 0xc6;
        case 3: return 0x124;
        case 4: return 0x17c;
        case 5: return 0x1c5;
        case 7: return 0x20e;
        case 8: return 0x257;
        case 9:
            if (FUN_0017d800() != 0) return 0x491;
            return 0x298;
        case 10: return 0xffffffff;
        }
        break;
    case 2:
        switch (*(u16*)(*(int*)(param_1 + 0x30) + 0xa4))
        {
        case 2: return 0xc7;
        case 3: return 0x125;
        case 4: return 0x17d;
        case 5: return 0x1c6;
        case 7: return 0x20f;
        case 8: return 0x258;
        case 9:
            if (FUN_0017d800() != 0) return 0x492;
            return 0x299;
        case 10: return 0xffffffff;
        }
        break;
    case 1:
        switch (*(u16*)(*(int*)(param_1 + 0x30) + 0xa4))
        {
        case 2: return 0xc8;
        case 3: return 0x126;
        case 4: return 0x17e;
        case 5: return 0x1c7;
        case 7: return 0x210;
        case 8: return 0x259;
        case 9:
            if (FUN_0017d800() != 0) return 0x493;
            return 0x29a;
        case 10: return 0xffffffff;
        }
        break;
    }
    return 0xffffffff;
}

// FUN_002E12D0
u32 FUN_002e12d0(int param_1)
{
  u32 uVar1;
  u32 lVar2;
  u32 uVar3;

  if ((*(u32 *)(iGpffffb6fc + 0xc) & 0x200000) != 0) {
    return 0xffffffff;
  }

  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != '\0') {
    return 0xffffffff;
  }

  switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
  case 2:
    uVar3 = FUN_002ffbc0(100);
    uVar1 = uVar3 >= 0x32 ? 0xd5 : 0xd6;
    break;
  case 3:
    uVar3 = FUN_002ffbc0(100);
    uVar1 = uVar3 >= 0x32 ? 0x133 : 0x134;
    break;
  case 4:
    uVar3 = FUN_002ffbc0(100);
    uVar1 = uVar3 >= 0x32 ? 0x18b : 0x18c;
    break;
  case 5:
    uVar3 = FUN_002ffbc0(100);
    uVar1 = uVar3 >= 0x32 ? 0x1d4 : 0x1d5;
    break;
  case 7:
    uVar3 = FUN_002ffbc0(100);
    uVar1 = uVar3 >= 0x32 ? 0x21d : 0x21e;
    break;
  case 8:
    uVar3 = FUN_002ffbc0(100);
    uVar1 = uVar3 >= 0x32 ? 0x266 : 0x267;
    break;
  case 9:
    lVar2 = FUN_0017d800();
    if (lVar2 == 0) {
      uVar3 = FUN_002ffbc0(100);
      uVar1 = uVar3 >= 0x32 ? 0x2a7 : 0x2a8;
    } else {
      uVar3 = FUN_002ffbc0(100);
      uVar1 = uVar3 >= 0x32 ? 0x4a0 : 0x4a1;
    }
    break;
  case 10:
    uVar1 = 0xffffffff;
    break;
  default:
    uVar1 = 0xffffffff;
  }

  return uVar1;
}

// FUN_002E1500


u32 FUN_002e1500(int param_1, u32 param_2)
{
    BtlUnit* unit = *(BtlUnit**)(param_1 + 0x30);

    if (unit->genus != 0)
    {
        return 0xffffffff;
    }

    switch (param_2)
    {
        case 0:
            switch (unit->charId)
            {
            case 2:
                return 0xcb;
            case 3:
                return 0x129;
            case 4:
                return 0x181;
            case 5:
                return 0x1ca;
            case 7:
                return 0x213;
            case 8:
                return 0x25c;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x496;
                }
                return 0x29d;
            case 10:
                return 0xffffffff;
            }
            break;
        case 1:
            switch (unit->charId)
            {
            case 2:
                return 0xcc;
            case 3:
                return 0x12a;
            case 4:
                return 0x182;
            case 5:
                return 0x1cb;
            case 7:
                return 0x214;
            case 8:
                return 0x25d;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x497;
                }
                return 0x29e;
            case 10:
                return 0xffffffff;
            }
            break;
        case 2:
            switch (unit->charId)
            {
            case 2:
                return 0xcd;
            case 3:
                return 0x12b;
            case 4:
                return 0x183;
            case 5:
                return 0x1cc;
            case 7:
                return 0x215;
            case 8:
                return 0x25e;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x498;
                }
                return 0x29f;
            case 10:
                return 0xffffffff;
            }
            break;
        case 3:
            switch (unit->charId)
            {
            case 2:
                return 0xce;
            case 3:
                return 0x12c;
            case 4:
                return 0x184;
            case 5:
                return 0x1cd;
            case 7:
                return 0x216;
            case 8:
                return 0x25f;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x499;
                }
                return 0x2a0;
            case 10:
                return 0xffffffff;
            }
            break;
        case 4:
            switch (unit->charId)
            {
            case 2:
                return 0xcf;
            case 3:
                return 0x12d;
            case 4:
                return 0x185;
            case 5:
                return 0x1ce;
            case 7:
                return 0x217;
            case 8:
                return 0x260;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x49a;
                }
                return 0x2a1;
            case 10:
                return 0xffffffff;
            }
            break;
        case 5:
            switch (unit->charId)
            {
            case 2:
                return 0xd1;
            case 3:
                return 0x12f;
            case 4:
                return 0x187;
            case 5:
                return 0x1d0;
            case 7:
                return 0x219;
            case 8:
                return 0x262;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x49c;
                }
                return 0x2a3;
            case 10:
                return 0xffffffff;
            }
            break;
        case 6:
            switch (unit->charId)
            {
            case 2:
                return 0xd0;
            case 3:
                return 0x12e;
            case 4:
                return 0x186;
            case 5:
                return 0x1cf;
            case 7:
                return 0x218;
            case 8:
                return 0x261;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x49b;
                }
                return 0x2a2;
            case 10:
                return 0xffffffff;
            }
            break;
        case 7:
            switch (unit->charId)
            {
            case 2:
                return 0xd4;
            case 3:
                return 0x132;
            case 4:
                return 0x18a;
            case 5:
                return 0x1d3;
            case 7:
                return 0x21c;
            case 8:
                return 0x265;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x49f;
                }
                return 0x2a6;
            case 10:
                return 0xffffffff;
            }
            break;
        case 8:
            switch (unit->charId)
            {
            case 2:
                return 0xd2;
            case 3:
                return 0x130;
            case 4:
                return 0x188;
            case 5:
                return 0x1d1;
            case 7:
                return 0x21a;
            case 8:
                return 0x263;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x49d;
                }
                return 0x2a4;
            case 10:
                return 0xffffffff;
            }
            break;
        case 9:
            switch (unit->charId)
            {
            case 2:
                return 0xd3;
            case 3:
                return 0x131;
            case 4:
                return 0x189;
            case 5:
                return 0x1d2;
            case 7:
                return 0x21b;
            case 8:
                return 0x264;
            case 9:
                if (datGetScenarioMode() != SCENARIO_MODE_JOURNEY)
                {
                    return 0x49e;
                }
                return 0x2a5;
            case 10:
                return 0xffffffff;
            }
            break;
        }

    return 0xffffffff;
}


#pragma alias func_00306e80_y2 func_00306e80_y2








#pragma alias DAT_007e094e_u16 DAT_007e094e
#pragma alias DAT_007e0958_u16 DAT_007e0958

#pragma alias PTR_FUN_0069721c_abs PTR_FUN_0069721c
#pragma alias PTR_FUN_00697294_abs PTR_FUN_00697294
#pragma alias PTR_FUN_006973cc_abs PTR_FUN_006973cc




/* Removing this loses FUN_002d1600 (MATCH nd0 -> MISMATCH nd28) - measured W161. */











#pragma alias btlTargetBuildBounds FUN_002d2340

#pragma alias FUN_002d2470_call FUN_002d2470






#ifndef false
#endif

/* Declaration notes: these raw FUN/LAB/DAT symbols are retained where no canonical
 * target-module API has been established.  FUN_0027ec10_y2 is btlPacketCreate;
 * FUN_00300580/FUN_0030b5a0_y2/FUN_0030b5e0/FUN_003005e0 are datCalc status/dead,
 * low-HP, and skill queries; FUN_002ffcc0/FUN_002ffd70/FUN_002ffdf0 are the
 * datCalc level/HP/max-HP queries.  FUN_00174800/FUN_00174a90 map to the
 * persona getters, FUN_0016c4f0/FUN_0016c5f0/FUN_0016c970/FUN_0016c920/
 * FUN_0016dd60/FUN_0017b170 map to datGetHp/datGetMaxHp/
 * datGetBadStatusNoDown/datGetPhysicalCondition/datGetPartyId/datGetTotalBtl.
 * iGpffffb6fc_y2 is the battle-work base (gBtl/DAT_007ce3ec alias); iGpffffb720
 * is the enemy-data table (DAT_007ce410 alias).  Retail ABI arguments omitted by
 * Ghidra are explicit in FUN_002d9d70: party slot, persona pc-id, and random-list
 * count.  FUN_002d8390 uses the retail slti/xori inversion (difference >= 4). */
#pragma alias FUN_002ffcc0_u32 FUN_002ffcc0
#pragma alias FUN_00300580_u32 FUN_00300580
/* Narrow ABI aliases used by FUN_002d8110; the raw declarations above serve
 * other decompiler-style callers in this translation unit. */
#pragma alias FUN_001706c0_u16 FUN_001706c0
#pragma alias FUN_00170710_void FUN_00170710
#pragma alias FUN_00170760_u16 FUN_00170760
#pragma alias FUN_00170860_void FUN_00170860
#pragma alias FUN_00300410_void FUN_00300410
#pragma alias FUN_00300480_void FUN_00300480



































// Retail VA range: 0x002d9aa0-0x002d9b1f (128 bytes)

// Retail VA range: 0x002d9b20-0x002d9bdf (192 bytes)

// Retail VA range: 0x002d9be0-0x002d9c9f (192 bytes)

// Retail VA range: 0x002d9ca0-0x002d9d5f (192 bytes)

// Retail VA range: 0x002d9d60-0x002d9d6f (16 bytes)









/* Caveats:
 * - iGpffffb6fc_y2, fGpffff827c, and DAT_006978c0 are raw retail globals; no stable named API was established.
 * - FUN_002d2470, FUN_002d25c0, and FUN_004C6B20 are raw helper declarations; FUN_004C6B20 is the retail 2-D normalize helper.
 */


















/* Removing this loses FUN_002d5e10 (MATCH nd0 -> MISMATCH nd1) - measured W161. */





/* Retail initializes the target-loop result state before dispatch.
 * Keep these aggregate values live across each target's slot loop.
 * The original reconstruction left successfulTargets/finalFlags indeterminate.
 * Retail also selects the nonnegative HP path before the negative callback.
 * This source follows that state transition order intentionally.
 */





/* Required existing declarations/notes:
 * - DAT_007ce3ec is the battle-global base; DAT_007ce3f8 is the 0x2c-byte
 *   attack/effect table, DAT_007ce410 is the 0x3e-byte character table, and
 *   DAT_007ce484 is the weapon-type x three-column scale table.
 * - FUN_002d6460 is the preceding target-slot helper.  All other raw FUN_/DAT_
 *   names above remain unnamed because no canonical public API was established.
 */



























// FUN_002E1BF0


u32 FUN_002e1bf0(int param_1)
{
  u32 result;
  BtlUnit* unit;

  unit = *(BtlUnit**)(param_1 + 0x30);
  if (unit->genus != 0) {
    result = 0xffffffff;
  } else {
    switch (unit->charId) {
    case 2:
      result = 0x9a;
      break;
    case 3:
      result = 0xea;
      break;
    case 4:
      result = 0x150;
      break;
    case 5:
      result = 0x199;
      break;
    case 7:
      result = 0x1e2;
      break;
    case 8:
      result = 0x22b;
      break;
    case 9:
      result = FUN_0017d800() != 0 ? 0x465 : 0x274;
      break;
    case 10:
      result = 0x2b5;
      break;
    default:
      result = 0xffffffff;
    }
  }
  return result;
}

// FUN_002E1CD0


u32 FUN_002e1cd0(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0x9b;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0xec : 0xeb;
        break;
    case 4:
        uVar1 = 0x151;
        break;
    case 5:
        uVar1 = 0x19a;
        break;
    case 7:
        uVar1 = 0x1e3;
        break;
    case 8:
        uVar1 = 0x22c;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x466 : 0x275;
        break;
    case 10:
        uVar1 = 0x2b6;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}

// FUN_002E1DF0


u32 FUN_002e1df0(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0x96;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0xe3 : 0xe2;
        break;
    case 4:
        uVar1 = 0x14c;
        break;
    case 5:
        uVar1 = 0x195;
        break;
    case 7:
        uVar1 = 0x1de;
        break;
    case 8:
        uVar1 = 0x227;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x461 : 0x270;
        break;
    case 10:
        uVar1 = 0x2b1;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}
// FUN_002E1F10


u32 FUN_002e1f10(int param_1)
{
    u32 uVar1;
    s32 lVar2;

    if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
        return 0xffffffff;
    }

    switch (*(u16 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    case 2:
        uVar1 = 0x98;
        break;
    case 3:
        if (*(s32 *)DAT_00697be4_abs == -1) {
            lVar2 = 0;
        } else {
            lVar2 = FUN_0016f190(*(s32 *)DAT_00697be4_abs);
        }
        uVar1 = (lVar2 != 0) ? 0xe7 : 0xe6;
        break;
    case 4:
        uVar1 = 0x14e;
        break;
    case 5:
        uVar1 = 0x197;
        break;
    case 7:
        uVar1 = 0x1e0;
        break;
    case 8:
        uVar1 = 0x229;
        break;
    case 9:
        lVar2 = FUN_0017d800();
        uVar1 = (lVar2 != 0) ? 0x463 : 0x272;
        break;
    case 10:
        uVar1 = 0x2b3;
        break;
    default:
        uVar1 = 0xffffffff;
    }

    return uVar1;
}

// FUN_002E2030


u32 FUN_002e2030(int param_1)
{
  u32 result;
  BtlUnit* unit;

  unit = *(BtlUnit**)(param_1 + 0x30);
  if (unit->genus != 0) {
    result = 0xffffffff;
  } else {
    switch (unit->charId) {
    case 2:
      result = 0x95;
      break;
    case 3:
      result = 0xe1;
      break;
    case 4:
      result = 0x14b;
      break;
    case 5:
      result = 0x194;
      break;
    case 7:
      result = 0x1dd;
      break;
    case 8:
      result = 0x226;
      break;
    case 9:
      result = FUN_0017d800() != 0 ? 0x460 : 0x26f;
      break;
    case 10:
      result = 0x2b0;
      break;
    default:
      result = 0xffffffff;
    }
  }
  return result;
}

// FUN_002E2110


u32 FUN_002e2110(int param_1)
{
    u8* unit = *(u8**)(param_1 + 0x30);

    if (unit[0xa2] != 0)
    {
        return 0xffffffff;
    }

    if (datGetScenarioMode() == 0)
    {
        switch (effMiscRand(0) % 9)
        {
        case 0: return 0x137;
        case 1: return 0x138;
        case 2: return 0x139;
        case 3: return 0x13a;
        case 4: return 0x13b;
        case 5: return 0x13c;
        case 6: return 0x13d;
        case 7: return 0x13e;
        case 8: return 0x13f;
        }
    }
    else
    {
        switch (effMiscRand(0) & 7)
        {
        case 0: return 0x4a4;
        case 1: return 0x4a5;
        case 2: return 0x4a6;
        case 3: return 0x4a7;
        case 4: return 0x4a8;
        case 5: return 0x4a9;
        case 6: return 0x4aa;
        case 7: return 0x4ab;
        }
    }

    return 0xffffffff;
}

/* Required symbol/type notes:
 * - The canonical TU must provide iGpffffb6fc_y2 (Battle work base), iGpffffb7b8
 *   (the 0x1c-byte effect-flag table base), and D_006978F0, an array of
 *   four-argument effect callbacks returning signed 64-bit values.
 * - Existing headers provide BtlAction/BtlTarget/BtlUnit, datCalcRand,
 *   datCalcChkBadStatus, datCalcIsDead, datGetFlag, datGetScenarioMode, and
 *   btlUnitFindFromId. If the TU keeps raw retail aliases instead, map these
 *   to FUN_002FFBC0, FUN_00300580, FUN_0030B5A0, FUN_0016F190,
 *   FUN_0017D800, and FUN_00289030 respectively.
 * - Unresolved retail helpers required by these bodies are FUN_002d1600,
 *   FUN_00308860, FUN_002db9f0, FUN_002dba80, FUN_002db690, FUN_002db650,
 *   FUN_002ff790, FUN_002d5550, FUN_003a3010, FUN_003c8dd0,
 *   FUN_003c8de0, FUN_003c8ea0, FUN_0029adf0, FUN_0029a380,
 *   FUN_00289650, FUN_001fdd40, and the recursive FUN_002daa20/FUN_002db2a0.
 * - FUN_002db2a0 intentionally leaves threshold unchanged when both 0x140
 *   and 0x141 are clear, matching retail's uninitialized saved-register path;
 *   normal retail call paths select one of those flags.
 */

/* Removing this loses FUN_002dc550 (MATCH nd0 -> MISMATCH nd52) - measured W161. */
// FUN_002E22A0


u32 FUN_002e22a0(int param_1)
{
  u32 iVar1;
  u32 lVar2;

  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != '\0') {
    return 0xffffffff;
  }

  lVar2 = FUN_0017d800();
  if (lVar2 == 0) {
    iVar1 = FUN_00357fd0(0);
    switch (iVar1 % 5) {
    case 0:
      return 0x140;
    case 1:
      return 0x141;
    case 2:
      return 0x142;
    case 3:
      return 0x143;
    case 4:
      return 0x144;
    default:
      break;
    }
  } else {
    iVar1 = FUN_00357fd0(0);
    switch (iVar1 % 5) {
    case 0:
      return 0x4ac;
    case 1:
      return 0x4ad;
    case 2:
      return 0x4ae;
    case 3:
      return 0x4af;
    case 4:
      return 0x4b0;
    default:
      break;
    }
  }
  return 0xffffffff;
}
// FUN_002E2410


u32 FUN_002e2410(int param_1)
{
  int iVar1;
  int iVar2;
  u32 lVar4;
  u32 uVar5;
  int aiStack_30[12];

  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != '\0') {
    return 0xffffffff;
  }

  uVar5 = 0;
  for (iVar2 = *(int *)(iGpffffb6fc + 0x14c); iVar2 != 0;
       iVar2 = *(int *)(iVar2 + 0x4a8)) {
    if ((*(u16 *)(iVar2 + 0x1a) & 1) == 0) {
      continue;
    }
    iVar1 = *(int *)(iVar2 + 0x30);
    if (*(u8 *)(iVar1 + 0xa2) != '\0') {
      continue;
    }
    if (*(int *)(iGpffffb6fc + 0x148) == iVar2) {
      continue;
    }
    if (param_1 == iVar2) {
      continue;
    }
    lVar4 = FUN_0030b5a0(*(u32 *)(iVar1 + 0xa2c), 0);
    if (lVar4 != 0) {
      continue;
    }
    lVar4 = FUN_00300580_y2(*(u32 *)(iVar1 + 0xa2c), 0x180375);
    if (lVar4 != 0) {
      continue;
    }
    if (*(u16 *)(iVar1 + 0xa4) == 10) {
      continue;
    }
    aiStack_30[uVar5 & 0xffff] = iVar2;
    uVar5 = uVar5 + 1 & 0xffff;
  }
  if ((u16)uVar5 == 0) {
    return 0xffffffff;
  }
  iVar2 = aiStack_30[FUN_002ffbc0((u16)uVar5)];
  return FUN_002e0f70(iVar2, 0, 0);
}
// FUN_002E2560


u32 FUN_002e2560(int param_1)
{
  u32 result;
  BtlUnit* unit;

  if (FUN_0010a500(4) == 1) {
    result = 0xffffffff;
  } else {
    unit = *(BtlUnit**)(param_1 + 0x30);
    if (unit->genus != 0) {
      result = 0xffffffff;
    } else {
      switch (unit->charId) {
      case 2:
        result = (u32)FUN_002ffbc0(100) >= 50 ? 0xd7 : 0xd8;
        break;
      case 3:
        result = 0x136;
        break;
      default:
        result = 0xffffffff;
        break;
      }
    }
  }
  return result;
}
// FUN_002E2630
u32 FUN_002e2630(int param_1)
{
  u32 result;
  BtlUnit* unit;

  unit = *(BtlUnit**)(param_1 + 0x30);
  if (unit->genus != 1) {
    goto default_case;
  }
  switch (unit->charId) {
  case 0x126:
    result = 0x33c;
    break;
default_case:
  default:
    result = 0xffffffff;
    break;
  }
  return result;
}

// FUN_002E2680


u32 FUN_002e2680(int param_1)
{
    u32 result;
    u32 rand;
    s32 flagResult;
    u8* unit;
    s8* record;

    unit = *(u8**)(param_1 + 0x30);
    if (unit[0xa2] != 0)
    {
        return 0xffffffff;
    }
    record = *(s8**)(unit + 0xa2c);
    if (record == 0)
    {
        return 0xffffffff;
    }
    if (record[0x10] == 9)
    {
        return 0xffffffff;
    }

    switch (*(u16*)(unit + 0xa4))
    {
    case 2:
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x443 : 0x444;
        break;
    case 3:
        if (*(s32*)DAT_00697be4_abs == -1)
            flagResult = 0;
        else
            flagResult = FUN_0016f190(*(s32*)DAT_00697be4_abs);
        if (flagResult == 0)
            goto c3_zero;
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x449 : 0x44a;
        goto c3_done;
c3_zero:
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x447 : 0x448;
c3_done:
        break;
    case 4:
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x44d : 0x44e;
        break;
    case 5:
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x451 : 0x452;
        break;
    case 7:
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x453 : 0x454;
        break;
    case 8:
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x459 : 0x45a;
        break;
    case 9:
        if (FUN_0017d800() != 0)
            goto c9_fes;
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x45b : 0x45c;
        goto c9_done;
c9_fes:
        result = (u32)FUN_002ffbc0(100) >= 0x32 ? 0x4b3 : 0x4b4;
c9_done:
        break;
    case 10:
        result = 0xffffffff;
        break;
    default:
        result = 0xffffffff;
        break;
    }

    return result;
}

/* Removing this loses FUN_002dcbc0 (MATCH nd0 -> MISMATCH nd64) - measured W161. */
// FUN_002E2920


u32 FUN_002e2920(int *param_1)
{
    u32 uVar1;
    int iVar2;
    s32 lVar3;

    if (param_1[1] == 0)
    {
        if (iGpffffb80c == 0)
        {
            uVar1 = (*DAT_00960178_abs)(0xacc, 0x40000);
            *(u32*)(iGpffffb6fc + 0xafc) = uVar1;
            iVar2 = FUN_0010a770(
                *(u32*)(iGpffffb6fc + 0xd18),
                *(u16*)(iGpffffb6fc + 0xaf8),
                *(u32*)(iGpffffb6fc + 0xafc),
                4, 0x1c2, 1);
            *param_1 = iVar2;
        }
        else
        {
            *param_1 = 0;
        }
        param_1[1] = 1;
    }

    if (*param_1 != 0)
    {
        lVar3 = FUN_0010a720(*param_1);
        if (lVar3 != 0)
        {
            *(u16*)(iGpffffb6fc + 0xaf6) |= 1;
            uVar1 = 1;
        }
        else
        {
            goto sound_failed;
        }
    }
    else
    {
        *(u16*)(iGpffffb6fc + 0xaf6) |= 1;
        uVar1 = 1;
    }
    goto sound_done;

sound_failed:
    uVar1 = 0;

sound_done:
    return uVar1;
}
// FUN_002E2A10
void FUN_002e2a10(void)
{
    BtlPacket* packet;
    void* work;

    packet = btlPacketCreate(0xa00, 8);
    packet->unk_47 &= 0xfe;
    packet->updateFunc = (BtlPacketUpdateFunc)FUN_002e2920;
    work = packet->workData;
    *(u32*)work = 0;
    *(u32*)((u8*)work + 4) = 0;
}

// FUN_002E2A60


u32 FUN_002e2a60(int *param_1)



{

  int iVar1;

  u32 uVar2;

s32 lVar3;

  

  if ((*(u16 *)(iGpffffb6fc + 0xaf6) & 1) == 0) {

    return 1;

  }

  iVar1 = *param_1;

  if (param_1[5] == 0) {

    if ((iVar1 != 0) && ((*(u16 *)(iVar1 + 0x1a) & 1) == 0)) {

      return 1;

    }

    uVar2 = DAT_00697c10[*(u16 *)(param_1 + 1)]
             (iVar1,param_1[2],param_1[3]);

    if (uVar2 == 0xffffffff) {

      return 1;

    }

    FUN_0010a2e0(*(u16 *)(iGpffffb6fc + 0xaf8),4,uVar2 & 0xffff);

    param_1[5] = 1;

  }

  else {

    lVar3 = FUN_0010a500(4);

    if (lVar3 != 1) {

      if ((iVar1 != 0) && ((*(u32 *)(*(int *)(iVar1 + 0x30) + 0x98) & 2) != 0)) {

        iVar1 = *(int *)(*(int *)(iVar1 + 0x30) + 0x9f4);

        *(u16 *)(iVar1 + 0x3fe) = *(u16 *)(iVar1 + 0x3fe) | 0x20;

      }

      return 1;

    }

  }

  if (((param_1[5] == 1) && (iVar1 != 0)) && ((*(u32 *)(*(int *)(iVar1 + 0x30) + 0x98) & 2) != 0))

  {

    iVar1 = *(int *)(*(int *)(iVar1 + 0x30) + 0x9f4);

    *(u16 *)(iVar1 + 0x3fe) = *(u16 *)(iVar1 + 0x3fe) & 0xffdf;

  }

  return 0;

}



















/* Retail formation reference recovery, retained NONMATCHING until codegen cleanup. */


#ifndef CONCAT44
#endif
#pragma alias func_00100d80_u32 func_00100d80
#pragma alias func_001016b0_u32 func_001016b0
#pragma alias func_001021c0_u32 func_001021c0
#pragma alias func_00195340_u32 func_00195340
#pragma alias func_00195540_u32 func_00195540
#pragma alias func_001fdf10_btlFormation_result func_001fdf10
#pragma alias func_0021c3f0_u32 func_0021c3f0
#pragma alias func_0021cca0_u32 func_0021cca0
#pragma alias func_00280870_btlFormation_s32 func_00280870
#pragma alias func_00280870_btlFormation_f32 func_00280870
#pragma alias func_002b96f0_btlFormation_u64 func_002b96f0
#pragma alias func_0029a210_u32 func_0029a210
#pragma alias func_0029ad20_u32 func_0029ad20
#pragma alias func_002d1fd0_c0070 func_002d1fd0
#pragma alias func_002ffbc0_u16 func_002ffbc0
#pragma alias func_002ffbc0_noarg func_002ffbc0
#pragma alias func_002ffbc0_noarg_u32 func_002ffbc0
#pragma alias func_00300530_u32 func_00300530
#pragma alias func_00300550_u32 func_00300550
#pragma alias func_00300580_u32 func_00300580
#pragma alias func_003005e0_u32 func_003005e0
#pragma alias func_00303130_s32 func_00303130
#pragma alias func_003086f0_u32 func_003086f0
#pragma alias func_00308ba0_u32 func_00308ba0
#pragma alias func_00308bb0_u32 func_00308bb0
#pragma alias func_00308860_u32 func_00308860
#pragma alias func_0035f160_u32 func_0035f160
#pragma alias func_0029ad60_u32 func_0029ad60
#pragma alias func_0035f060_u32 func_0035f060
#pragma alias func_0035ed20_u32 func_0035ed20
#pragma alias func_002a3d70_f32 func_002a3d70
#pragma alias func_002a3d70_move func_002a3d70
#pragma alias func_002b8d60_u32 func_002b8d60
#pragma alias func_0035ee60_f32 func_0035ee60
#pragma alias func_0030b4b0_u32 func_0030b4b0
#pragma alias func_0030b5a0_u32 func_0030b5a0
#pragma alias func_0030bc20_u32 func_0030bc20
#pragma alias func_00324bd0_u32 func_00324bd0
#pragma alias func_00325920_u32 func_00325920
#pragma alias func_003b2cb0_typed func_003b2cb0
#pragma alias DAT_00696d70_abs DAT_00696d70
#pragma alias DAT_00696fb0_abs DAT_00696fb0
#pragma alias DAT_007e094e_abs DAT_007e094e
#pragma alias DAT_007e0952_abs DAT_007e0952
#pragma alias DAT_007e0958_abs DAT_007e0958
#pragma alias DAT_007e095a_abs DAT_007e095a
#pragma alias DAT_00957100_abs DAT_00957100
#pragma alias DAT_00957140_abs DAT_00957140
#pragma alias DAT_00957150_abs DAT_00957150
#pragma alias DAT_00957160_abs DAT_00957160
#pragma alias DAT_00957170_abs DAT_00957170
#pragma alias DAT_00960088_abs DAT_00960088
#pragma alias DAT_00960090_abs DAT_00960090
#pragma alias DAT_009600a4_abs DAT_009600a4
#pragma alias DAT_00960178_u32_abs DAT_00960178
#pragma alias DAT_0096017c_abs DAT_0096017c
#pragma alias PTR_DAT_00696f30_abs PTR_DAT_00696f30
#pragma alias PTR_s_battle_effect_ATC_D_BED_abs PTR_s_battle_effect_ATC_D_BED_00696c80


/* Target forward declarations. */
#pragma alias func_002b9350_u32 func_002b9350
#pragma alias func_002b93e0_4arg func_002b93e0
#pragma alias func_002ba3a0_void func_002ba3a0
#pragma alias func_002bc9c0_long func_002bc9c0
#pragma alias func_002bce10_reordered func_002bce10
#pragma alias func_002bfcb0_ptr func_002bfcb0
#pragma alias func_002bfcb0_u64call func_002bfcb0
// Typed alias for callers that consume the helper's full 16-bit result.
#pragma alias func_002bff60_u16 func_002bff60
#pragma alias func_002c0f40_call func_002c0f40
#pragma alias func_002c3770_u32 func_002c3770
#pragma alias func_002c5380_noargs func_002c5380
#pragma alias func_002c6300_s32 func_002c6300
// The caller passes two 32-bit resource identifiers.
#pragma alias func_002c6f50_u32 func_002c6f50



















#pragma alias func_0027ffb0_v3d func_0027ffb0
#pragma alias func_00318ed0_v3d func_00318ed0








/* W322 probe: func_002ba0f0 with opt_common_subs off improved normalized_diff 389 -> 372 (object 680/688). */












































































/* Removing this loses FUN_002bde10 (MATCH nd0 -> MISMATCH nd119) - measured W161. */

/* W322 probe: func_002bdfb0 with opt_loop_invariants on improved normalized_diff 431 -> 373 (object 796/816). */










































/* W322 probe: func_002bfcb0 with opt_loop_invariants on improved normalized_diff 479 -> 446 (object 688/688). */

/* W322 probe: func_002c0070 with opt_loop_invariants on improved normalized_diff 1574 -> 1570 (object 1988/2064). */





/* Removing this loses func_002c0970 (MATCH nd0 -> MISMATCH nd12) - measured W161. */
/* Removing this loses FUN_002c09f0 (MATCH nd0 -> MISMATCH nd50) - measured W161. */










/* Removing this loses FUN_002c1490 (MATCH nd0 -> MISMATCH nd44) - measured W161. */
/* Removing this loses FUN_002c14f0 (MATCH nd0 -> MISMATCH nd44) - measured W161. */


/* Removing this loses FUN_002c15e0 (MATCH nd0 -> MISMATCH nd49) - measured W161. */


/* Removing this loses FUN_002c16a0 (MATCH nd0 -> MISMATCH nd49) - measured W161. */



/* Removing this loses FUN_002c17b0 (MATCH nd0 -> MISMATCH nd86) - measured W161. */
/* Removing this loses FUN_002c1850 (MATCH nd0 -> MISMATCH nd153) - measured W161. */

/* Removing this loses FUN_002c1a30 (MATCH nd0 -> MISMATCH nd124) - measured W161. */

/* Removing this loses FUN_002c1bf0 (MATCH nd0 -> MISMATCH nd135) - measured W161. */








/* Removing this loses FUN_002c1f60 (MATCH nd0 -> MISMATCH nd44) - measured W161. */

/* Removing this loses FUN_002c2010 (MATCH nd0 -> MISMATCH nd44) - measured W161. */

/* Removing this loses FUN_002c20c0 (MATCH nd0 -> MISMATCH nd44) - measured W161. */

/* Removing this loses FUN_002c2170 (MATCH nd0 -> MISMATCH nd44) - measured W161. */


/* Removing this loses FUN_002c2270 (MATCH nd0 -> MISMATCH nd44) - measured W161. */


/* Removing this loses FUN_002c2360 (MATCH nd0 -> MISMATCH nd44) - measured W161. */


/* Removing this loses FUN_002c2470 (MATCH nd0 -> MISMATCH nd44) - measured W161. */





/* Removing this loses FUN_002c2630 (MATCH nd0 -> MISMATCH nd44) - measured W161. */

/* Removing this loses FUN_002c26e0 (MATCH nd0 -> MISMATCH nd44) - measured W161. */

/* Removing this loses FUN_002c2790 (MATCH nd0 -> MISMATCH nd44) - measured W161. */

/* Removing this loses FUN_002c2840 (MATCH nd0 -> MISMATCH nd44) - measured W161. */


/* Removing this loses FUN_002c29e0 (MATCH nd0 -> MISMATCH nd175) - measured W161. */

/* Removing this loses FUN_002c2be0 (MATCH nd0 -> MISMATCH nd43) - measured W161. */
/* Removing this loses FUN_002c2c40 (MATCH nd0 -> MISMATCH nd43) - measured W161. */
/* Removing this loses FUN_002c2ca0 (MATCH nd0 -> MISMATCH nd43) - measured W161. */


/* W322 probe: func_002c2ed0 with opt_loop_invariants on improved normalized_diff 178 -> 158 (object 540/544). */


/* Removing this loses FUN_002c3150 (MATCH nd0 -> MISMATCH nd43) - measured W161. */
/* Removing this loses FUN_002c31b0 (MATCH nd0 -> MISMATCH nd43) - measured W161. */
/* Removing this loses FUN_002c3210 (MATCH nd0 -> MISMATCH nd43) - measured W161. */



/* Removing this loses FUN_002c3300 (MATCH nd0 -> MISMATCH nd148) - measured W161. */



/* W322 probe: func_002c3770 with opt_loop_invariants on improved normalized_diff 817 -> 808 (object 1056/1136). */





































/* W322 probe: func_002c48a0 with opt_loop_invariants on improved normalized_diff 206 -> 48 (object 484/496). */

/* W322 probe: func_002c4a90 with opt_loop_invariants on improved normalized_diff 206 -> 56 (object 492/496). */

/* W322 probe: func_002c4c80 with opt_loop_invariants on improved normalized_diff 239 -> 19 (object 460/464). */

/* W322 probe: func_002c4e50 with opt_common_subs off improved normalized_diff 288 -> 210 (object 472/480). */

/* W322 probe: func_002c5030 with opt_loop_invariants on improved normalized_diff 534 -> 533 (object 840/848). */




/* W322 probe: func_002c6300 with opt_common_subs off improved normalized_diff 457 -> 456 (object 664/720). */

/* W322 rerun probe: func_002c65d0 with opt_loop_invariants on improved normalized_diff 191 -> 125 (object 1068/1072). */



















































































/* Removing this loses FUN_002ca480 (MATCH nd0 -> MISMATCH nd158) - measured W161. */
/* Removing this loses FUN_002ca590 (MATCH nd0 -> MISMATCH nd158) - measured W161. */
/* Removing this loses FUN_002ca6a0 (MATCH nd0 -> MISMATCH nd158) - measured W161. */
/* Removing this loses FUN_002ca7b0 (MATCH nd0 -> MISMATCH nd202) - measured W161. */
/* Removing this loses FUN_002ca900 (MATCH nd0 -> MISMATCH nd113) - measured W161. */
/* Removing this loses FUN_002ca9d0 (MATCH nd0 -> MISMATCH nd158) - measured W161. */
/* Removing this loses FUN_002caae0 (MATCH nd0 -> MISMATCH nd158) - measured W161. */
/* Removing this loses FUN_002cabf0 (MATCH nd0 -> MISMATCH nd158) - measured W161. */
/* Removing this loses FUN_002cad00 (MATCH nd0 -> MISMATCH nd158) - measured W161. */
/* Removing this loses FUN_002cae10 (MATCH nd0 -> MISMATCH nd158) - measured W161. */
/* Removing this loses FUN_002caf20 (MATCH nd0 -> MISMATCH nd158) - measured W161. */
/* Removing this loses FUN_002cb030 (MATCH nd0 -> MISMATCH nd89) - measured W161. */
/* Removing this loses FUN_002cb0e0 (MATCH nd0 -> MISMATCH nd89) - measured W161. */

































































/* Removing this loses FUN_002cdad0 (MATCH nd0 -> MISMATCH nd74) - measured W161. */







/* Removing this loses FUN_002cde60 (MATCH nd0 -> MISMATCH nd42) - measured W161. */


















/* Removing this loses FUN_002ced60 (MATCH nd0 -> MISMATCH nd263) - measured W161. */
#pragma opt_rebuildconditionals off
#pragma opt_rebuildconditionals reset




















/* W322 probe: func_002d03e0 with opt_loop_invariants on improved normalized_diff 190 -> 188 (object 472/480). */
