#include "Battle/btlTarget.h"
#include "rw/rtquat.h"
#include "Script/scrScriptProcess.h"
#include "Script/scr.h"
#include "Kernel/Kwln/kwln.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Battle/btlPacket.h"
#include "Battle/btlAction.h"
#include "Battle/battle.h"
#include "Battle/btlUnit.h"
#include "Battle/btlVoice.h"
#include "Battle/btlBoss.h"
#include "Main/Battle/Data/datCalc.h"
#include "Main/Battle/Data/datPersona.h"
#include "Main/g_data.h"
#include "h_cdvd.h"
#include "Kosaka/k_assert.h"
#include "libm.h"
extern u32 func_002e4910();
#include "temporary.h"

void FUN_002dc550(BtlAction* action, u32 flags);
extern u16 FUN_002bff60(BtlAction* action, BtlTarget* target,
                         u16 commandId, u32 flags);
extern u8* iGpffffb6fc;
extern f32 fGpffff827c;
extern u8 DAT_00697880[];
extern f32 DAT_006978c0[];
extern u8* DAT_007ce42c;
extern BtlCommandRecord* iGpffffb710;
extern u32 DAT_007e094e;
extern u32 DAT_007e0958;
#pragma alias DAT_007e094e_u16 DAT_007e094e
#pragma alias DAT_007e0958_u16 DAT_007e0958
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
#pragma alias PTR_FUN_0069721c_abs PTR_FUN_0069721c
#pragma alias PTR_FUN_00697294_abs PTR_FUN_00697294
#pragma alias PTR_FUN_006973cc_abs PTR_FUN_006973cc
extern s32 (*PTR_FUN_0069721c_abs[])(void*, s32);
extern s32 (*PTR_FUN_00697294_abs[])(void*, s32);
extern s32 (*PTR_FUN_006973cc_abs[])(void*, s32);
extern u8* DAT_007ce484;
extern u8* DAT_007ce488;
#pragma alias btlTargetBuildBounds FUN_002d2340
extern void btlTargetBuildBounds(u8* work, s16 start, s16 end, f32 distance);
#pragma alias FUN_002d2470_call FUN_002d2470
extern s32 FUN_002d2470_call(f32 tolerance, const f32* a, const f32* b,
                             const f32* point);
typedef u8 undefined1;
typedef u16 ushort;
typedef u8 byte;
typedef u32 uint;
typedef void (*code)();
typedef u16 undefined2;
typedef u32 undefined4;
typedef u64 undefined8;
typedef u64 ulong;
typedef u8 bool;
#ifndef false
#define false 0
#define true 1
#endif
extern u64 FUN_0016c4f0();
extern u64 FUN_0016c5f0();
extern u64 FUN_0016c920();
extern u64 FUN_0016c970();
extern u64 FUN_0016dd60();
extern u64 FUN_0016f190();
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
extern u64 FUN_0027ec10();
extern u64 FUN_0029a1d0();
extern u64 FUN_002ddc10();
extern u32 func_002ddc10(u32 unitId);
extern u64 FUN_002ffbc0();
extern u64 FUN_002ffcc0();
#pragma alias FUN_002ffcc0_u32 FUN_002ffcc0
extern u32 FUN_002ffcc0_u32(u32 unit);
extern u64 FUN_002ffd70();
extern u64 FUN_002ffdf0();
extern s32 FUN_00300410(DatUnit* unit, s32 hpDelta);
extern s32 FUN_00300480(DatUnit* unit, s32 spDelta);
extern u64 FUN_00300580();
#pragma alias FUN_00300580_u32 FUN_00300580
extern u32 FUN_00300580_u32(u32 unit, u32 status);
extern u64 FUN_003005e0();
extern u64 FUN_00301ca0();
extern void FUN_00302c50(u32 datUnit);
extern u32 FUN_003083f0(u32 param_1, u32 param_2);
extern u64 FUN_0030b5a0();
extern u64 FUN_0030b5e0();
extern u8* DAT_007ce3ec;
extern u8* DAT_007ce3f8;
extern u8* DAT_007ce410;
extern u8* iGpffffb6fc;
extern u8* iGpffffb720;
#pragma alias FUN_001706c0_u16 FUN_001706c0
extern u16 FUN_001706c0_u16(s16 pcId, s16 index);
#pragma alias FUN_00170710_void FUN_00170710
extern void FUN_00170710_void(s16 pcId, s16 index, s16 value);
#pragma alias FUN_00170760_u16 FUN_00170760
extern u16 FUN_00170760_u16(s16 pcId, s16 index);
#pragma alias FUN_00170860_void FUN_00170860
extern void FUN_00170860_void(s16 pcId, s16 index, u16 value);
#pragma alias FUN_00300410_void FUN_00300410
extern void FUN_00300410_void(DatUnit* unit, s32 delta);
#pragma alias FUN_00300480_void FUN_00300480
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
#pragma alias func_002d4e10_y2 func_002d4e10
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
#ifndef CONCAT44
#define CONCAT44(hi, lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif
extern u64 func_00100d80();
#pragma alias func_00100d80_u32 func_00100d80
extern u32 func_00100d80_u32(u32 param_1,u32 param_2);
extern u64 func_00100ec0();
extern u64 func_001016b0();
#pragma alias func_001016b0_u32 func_001016b0
extern u32 func_001016b0_u32(u32 param_1);
extern u64 func_00102100();
extern u64 func_001021c0();
#pragma alias func_001021c0_u32 func_001021c0
extern u32 func_001021c0_u32(u32 param_1,u8* output);
extern u64 func_001023a0();
extern u64 func_00108570();
extern u64 func_00108670();
extern u64 func_00108680();
extern u64 func_001086a0();
extern u64 func_0016f1f0();
extern u16 func_00170670(s16 pcId, s16 index);
extern s16 func_001706c0(s16 pcId, s16 index);
extern const char* func_00171110(s16 id, s16 field);
extern u64 func_00173220();
extern u8* func_001778b0(s16 param_1);
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
#pragma alias func_00195340_u32 func_00195340
#pragma alias func_00195540_u32 func_00195540
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
#pragma alias func_001fdf10_btlFormation_result func_001fdf10
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
extern u32 func_0021c3f0(s32 param_1);
#pragma alias func_0021c3f0_u32 func_0021c3f0
extern u32 func_0021c3f0_u32(u32 param_1);
#pragma alias func_0021cca0_u32 func_0021cca0
extern u32 func_0021cca0_u32(u32 param_1,u32 param_2);
extern void* func_0021cca0(void* texture, s32 index);
extern u32 func_0021cce0(void* frameData);
extern BtlPacket* func_0027e310(u64 uid, u64 mask);
extern u32 func_0027ec10();
extern u64 func_0027ed20();
extern u64 func_0027f650();
extern u64 func_0027f7c0();
extern u64 func_0027ffb0();
extern u64 func_00280870();
#pragma alias func_00280870_btlFormation_s32 func_00280870
extern s32 func_00280870_btlFormation_s32(u32 mode, u32 enabled,
                                          void *out, void *end, void *extra,
                                          u32 include);
#pragma alias func_00280870_btlFormation_f32 func_00280870
extern f32 func_00280870_btlFormation_f32(u32 mode, u32 enabled,
                                          void *out, void *end, void *extra,
                                          u32 include);
#pragma alias func_002b96f0_btlFormation_u64 func_002b96f0
extern void func_002b96f0_btlFormation_u64(float param_1,float param_2,
                                           float *param_3,u32 *param_4,
                                           int param_5,u64 param_6);
extern u64 func_00288f80();
extern u64 func_00289030();
extern u64 func_0028a780();
extern u64 func_0029a1d0();
extern u64 func_0029a210();
#pragma alias func_0029a210_u32 func_0029a210
extern u32 func_0029a210_u32(u32 param_1);
extern u64 func_0029ad20();
#pragma alias func_0029ad20_u32 func_0029ad20
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
#pragma alias func_002d1fd0_c0070 func_002d1fd0
extern f32 func_002d1fd0_c0070();
extern u32 func_002d4cf0();
extern u32 func_002d4e10_y2();
extern u64 func_002d5550();
extern u64 func_002db650();
extern u64 func_002db800();
extern u64 func_002db890();
extern u64 func_002e3350(BtlAction* action, s16 index);
extern u64 func_002eab70();
extern u64 func_002eabb0();
extern void func_002ec560(u32 param_1);
extern u64 func_002ec590();
extern u32 func_002ecb30(BtlAction* action, s16 selection);
extern void func_002efc90(u32 param_1);
extern void func_002efcd0(u32 param_1);
extern u64 func_002efd10();
extern void func_002f2450(u32 param_1);
extern void func_002f2490(u32 param_1);
extern u64 func_002f24d0();
extern u64 func_002f2510();
extern void func_002f5030(int param_1);
extern u64 func_002f5320();
extern void func_002f6bf0(u32 param_1);
extern u64 func_002f6c20();
extern u64 func_002fd820();
extern u64 func_002ffbc0();
#pragma alias func_002ffbc0_u16 func_002ffbc0
extern u16 func_002ffbc0_u16(u32 max);
#pragma alias func_002ffbc0_noarg func_002ffbc0
extern u16 func_002ffbc0_noarg(void);
#pragma alias func_002ffbc0_noarg_u32 func_002ffbc0
extern u32 func_002ffbc0_noarg_u32(void);
extern u64 func_002ffcc0();
extern u16 func_002ffd70(u32 unit);
extern u16 func_002ffd80(u32 unit);
extern u16 func_002ffdf0(u32 unit);
extern u16 func_00300100(u32 unit);
extern u64 func_00300530();
#pragma alias func_00300530_u32 func_00300530
extern u32 func_00300530_u32(u32 unit);
extern u64 func_00300550();
#pragma alias func_00300550_u32 func_00300550
extern u32 func_00300550_u32(u32 param_1);
extern u64 func_00300580();
#pragma alias func_00300580_u32 func_00300580
extern u32 func_00300580_u32(u32 param_1,u32 param_2);
extern u64 func_003005e0();
#pragma alias func_003005e0_u32 func_003005e0
extern u32 func_003005e0_u32(u32 param_1,u32 param_2);
extern u64 func_00301540();
extern u64 func_00301750();
extern u64 func_00301870();
extern u64 func_00301ca0();
extern u64 func_00303130();
#pragma alias func_00303130_s32 func_00303130
extern s32 func_00303130_s32(s32,s32,s32,s32,s32,s32,s32,s32);
extern u32 func_00306e80_y2();
extern u64 func_003080c0();
extern u64 func_003082f0();
extern u64 func_003086f0();
#pragma alias func_003086f0_u32 func_003086f0
extern u32 func_003086f0_u32(u32 param_1,u32 param_2);
extern u64 func_00308860();
extern u64 func_00308930();
extern u64 func_00308a80();
extern u64 func_00308ba0();
extern u64 func_00308bb0();
#pragma alias func_00308ba0_u32 func_00308ba0
#pragma alias func_00308bb0_u32 func_00308bb0
#pragma alias func_00308860_u32 func_00308860
extern u32 func_00308ba0_u32(u32 param_1);
extern u32 func_00308bb0_u32(u32 param_1);
extern u32 func_00308860_u32(void);
#pragma alias func_0035f160_u32 func_0035f160
#pragma alias func_0029ad60_u32 func_0029ad60
#pragma alias func_0035f060_u32 func_0035f060
extern u32 func_0035f160_u32(void);
extern u32 func_0029ad60_u32(u16 param_1);
extern void func_0035f060_u32(u32 param_1);
#pragma alias func_0035ed20_u32 func_0035ed20
extern u32 func_0035ed20_u32(u32 param_1);
#pragma alias func_002a3d70_f32 func_002a3d70
extern u64 func_002a3d70_f32(float param_1,u32 param_2,void *param_3,void *param_4,void *param_5,void *param_6);
#pragma alias func_002a3d70_move func_002a3d70
extern u32 func_002a3d70_move(u32 action,RwV3d *startPos,RwV3d *startTarget,RwV3d *endPos,RwV3d *endTarget,float duration);
#pragma alias func_002b8d60_u32 func_002b8d60
extern u32 func_002b8d60_u32(s32 param_1,u32 param_2);
#pragma alias func_0035ee60_f32 func_0035ee60
extern float func_0035ee60_f32(u32 param_1);
extern u64 func_0030b4b0();
#pragma alias func_0030b4b0_u32 func_0030b4b0
extern u32 func_0030b4b0_u32(u32 param_1,u32 param_2);
#pragma alias func_0030b5a0_u32 func_0030b5a0
extern u32 func_0030b5a0_u32(u32,u32);
extern u64 func_0030b5a0();
extern u64 func_0030bc20();
#pragma alias func_0030bc20_u32 func_0030bc20
extern u32 func_0030bc20_u32(u16 param_1);
extern u64 func_003174e0();
extern void func_003176c0(Model* mdl);
extern u64 func_00317730();
extern void FUN_00317a20(Model* param_1);
extern u64 func_00318ad0();
extern u32 func_00318b90(u32 param_1);
extern u32 func_00318d10(u8* param_1, u32 param_2, u32* param_3);
extern bool func_00318ed0(u8* param_1, u32 param_2, RwV3d* param_3);
extern u64 func_00321120();
extern u64 func_00321130();
extern u64 func_00321320();
extern u64 func_00324bd0();
#pragma alias func_00324bd0_u32 func_00324bd0
extern u32 func_00324bd0_u32(u32 param_1);
extern u64 func_003252a0();
extern u64 func_00325500();
extern u64 func_003257e0();
extern u64 func_00325920();
#pragma alias func_00325920_u32 func_00325920
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
extern void func_00357ea0(f32 angleX, f32 angleY, f32 angleZ);
extern u64 func_0035ae10();
extern u64 func_0035bb40();
extern u64 func_0035c090();
extern u64 func_0035ed20();
extern u64 func_0035ee60();
extern u64 func_0035f060();
extern u64 func_0035f160();
extern u64 func_003a4220();
extern u64 func_003b2cb0();
#pragma alias func_003b2cb0_typed func_003b2cb0
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
extern u64 func_00523ac8();
extern u32 func_00524270();
extern u32 func_00524388();
extern u32 func_0052ea18(float param_1, float param_2);
extern u8 DAT_00696440;
extern u8 DAT_00696460;
extern u8 DAT_00696d70;
#pragma alias DAT_00696d70_abs DAT_00696d70
extern u8 DAT_00696d70_abs[];
extern u8 DAT_00696e10;
extern u32 DAT_00696e30;
extern u32 DAT_00696e34;
extern u8 DAT_00696fb0;
#pragma alias DAT_00696fb0_abs DAT_00696fb0
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
#pragma alias DAT_007e094e_abs DAT_007e094e
#pragma alias DAT_007e0952_abs DAT_007e0952
#pragma alias DAT_007e0958_abs DAT_007e0958
#pragma alias DAT_007e095a_abs DAT_007e095a
extern u8 DAT_007e094e_abs[];
extern u8 DAT_007e0952_abs[];
extern u8 DAT_007e0958_abs[];
extern u8 DAT_007e095a_abs[];
extern u32 DAT_00957100;
extern u32 DAT_00957140;
extern u32 DAT_00957144;
extern u32 DAT_00957148;
#pragma alias DAT_00957100_abs DAT_00957100
#pragma alias DAT_00957140_abs DAT_00957140
#pragma alias DAT_00957150_abs DAT_00957150
#pragma alias DAT_00957160_abs DAT_00957160
#pragma alias DAT_00957170_abs DAT_00957170
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
#pragma alias DAT_00960088_abs DAT_00960088
extern float DAT_00960088_abs[];
extern u64 (*DAT_00960090)();
#pragma alias DAT_00960090_abs DAT_00960090
extern u64 (*DAT_00960090_abs)();
#pragma alias DAT_009600a4_abs DAT_009600a4
extern u64 (*DAT_009600a4_abs)();
extern u64 (*DAT_00960178)();
#pragma alias DAT_00960178_u32_abs DAT_00960178
extern u32 (*DAT_00960178_u32_abs[])(...);
#pragma alias DAT_00960178_abs DAT_00960178
extern code DAT_00960178_abs[];
extern void (*DAT_0096017c[])(...);
#pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];
extern u32* PTR_DAT_00696f30;
#pragma alias PTR_DAT_00696f30_abs PTR_DAT_00696f30
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
#pragma alias PTR_s_battle_effect_ATC_D_BED_abs PTR_s_battle_effect_ATC_D_BED_00696c80
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
#pragma alias func_002b9350_u32 func_002b9350
extern u32 func_002b9350_u32(int param_1);
extern u32 func_002b9370(int param_1,u16 param_2);
extern u32 func_002b93c0(int param_1,u16 param_2);
extern u32 func_002b93e0(u32 param_1,u16 param_2,u32 param_3,u32 param_4,u32 param_5);
#pragma alias func_002b93e0_4arg func_002b93e0
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
#pragma alias func_002ba3a0_void func_002ba3a0
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
#pragma alias func_002bc9c0_long func_002bc9c0
extern void func_002bc9c0_long(float param_1,float param_2,float param_3,float param_4,float param_5, float param_6,u32 param_7,long param_8);
extern void func_002bccd0(u32 param_1, u32 param_2);
extern void func_002bcde0(u64 param_1,u32 *param_2);
extern void func_002bce10(float param_1,float param_2,u8* param_3,int param_4,float *param_5);
#pragma alias func_002bce10_reordered func_002bce10
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
#pragma alias func_002bfcb0_ptr func_002bfcb0
extern void func_002bfcb0_ptr(int param_1,void *param_2,u32 param_3,u32 param_4,long param_5);
#pragma alias func_002bfcb0_u64call func_002bfcb0
extern void func_002bfcb0_u64call(u64 param_1,u64 param_2,u32 param_3,u32 param_4,long param_5);
extern u8 func_002bff60(u64 param_1,long param_2,u32 param_3,long param_4);
#pragma alias func_002bff60_u16 func_002bff60
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
#pragma alias func_002c0f40_call func_002c0f40
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
#pragma alias func_002c3770_u32 func_002c3770
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
#pragma alias func_002c5380_noargs func_002c5380
extern u32 func_002c5380_noargs();
extern u32 func_002c59d0(int param_1,int param_2,int param_3,long param_4);
extern s32 func_002c5fc0(u32 param_1,u32 param_2,short param_3,int param_4);
extern s32 func_002c6300(u32 param_1,u32 param_2,u16 param_3,s32 param_4);
#pragma alias func_002c6300_s32 func_002c6300
extern long func_002c6300_s32(u32 context, u32 actor, s16 value, s32 mode);
extern u32 func_002c65d0(int param_1);
extern void func_002c6a00(int param_1,int param_2,u16 param_3);
extern u16 func_002c6ba0(int param_1);
extern undefined * func_002c6e30(int param_1,u32 param_2);
extern u32 func_002c6f50(u32 param_1,int param_2,u32 param_3,u32 param_4);
#pragma alias func_002c6f50_u32 func_002c6f50
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
#pragma alias func_0027ffb0_v3d func_0027ffb0
extern void func_0027ffb0_v3d(int unit, RwV3d* out);
#pragma alias func_00318ed0_v3d func_00318ed0
extern s32 func_00318ed0_v3d(u32 model, u32 index, RwV3d* out);
typedef struct FormationLoadWork {
  BtlFormationState* state;
  u32 request;
  u32 source;
  u16 flags;
  u16 padding;
} FormationLoadWork;
extern u32 func_002c1ce0_u32(int param_1, int param_2);
#include "Battle/btlEfficacy.h"
#include "Main/Battle/Data/datUnit.h"
extern int func_002d4e10(u32 genusMask, u32 excludedBadStatus);
enum
{
    BTL_EFFICACY_ENEMY_GENUS_MASK = 1 << UNIT_GENUS_EC,
    BTL_EFFICACY_NO_RESULT = -1,
    BTL_EFFICACY_ONE_TO_FOUR_ENEMY_COUNT_END = 5,
    BTL_EFFICACY_TWO_TO_FIVE_ENEMY_COUNT_START = 2,
    BTL_EFFICACY_TWO_TO_FIVE_ENEMY_COUNT_END = 6,
    BTL_EFFICACY_ONE_TO_FOUR_RESULT_BASE = 0x6C,
    BTL_EFFICACY_TWO_TO_FIVE_RESULT_BASE = 0x72
};

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


#pragma alias func_00306e80_y2 func_00306e80_y2

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

// FUN_002d0a30

u32 func_002d0a30(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern void func_0019d3f0(char *,u32);
  extern char D_00697720[];
  u8* unit;
  u32 index = 0;
  u8 flags;

  unit = (u8*)func_0035f160();
  index = func_0035ed20(0);
  flags = iGpffffb708[index * 0x2c];
  if ((flags & 2) == 0) {
    func_0019d3f0(D_00697720,0x118b);
  }
  *(u16 *)(unit + 0x6c) = 1;
  *(u16 *)(unit + 0x6e) = index;
  return 1;
}

// FUN_002d0ac0

u32 func_002d0ac0(void)

{
  long lVar1 = 0;
  
  lVar1 = func_002efd10();
  func_0035f060(lVar1 != 0);
  return 1;
}





// FUN_002d0af0

u32 func_002d0af0(void)
{
  extern u32 func_0035f160(void);
  extern u32 func_0035ed20(u32);
  extern s32 func_002ecb30(u32,s16);
  u32 unit;
  s16 selector;
  s32 result;

  unit = func_0035f160();
  selector = func_0035ed20(0);
  result = func_002ecb30(unit,selector);
  if (result != 0) {
    *(u16 *)(unit + 0x6c) = 8;
    result = (*(s32 (**)(u32,u32))PTR_FUN_00697620)(unit,0);
    if (result == 0) {
      (*(s32 (**)(u32,u32))PTR_FUN_006975e0)(unit,0);
    }
  }
  return 1;
}

// FUN_002d0b90

u32 func_002d0b90(void)

{
  extern u32 func_0035f160(void);
  u32 uVar1 = 0;
  
  uVar1 = func_0035f160();
  *(u16 *)(uVar1 + 0x6c) = 8;
  func_002f2450(uVar1);
  return 1;
}
// FUN_002d0bd0

u32 func_002d0bd0(void)

{
  extern u32 func_0035f160(void);
  u32 uVar1 = 0;
  
  uVar1 = func_0035f160();
  *(u16 *)(uVar1 + 0x6c) = 8;
  func_002f2490(uVar1);
  return 1;
}

/* Removing this loses FUN_002d1600 (MATCH nd0 -> MISMATCH nd28) - measured W161. */
// FUN_002d0c10

u32 func_002d0c10(void)

{
  u64 uVar1 = 0;
  
  uVar1 = func_0035f160();
  uVar1 = func_002f2510(uVar1);
  func_0035f060(uVar1);
  return 1;
}
// FUN_002d0c50

u32 func_002d0c50(void)

{
  long lVar1 = 0;
  
  lVar1 = func_002f24d0();
  func_0035f060(lVar1 != 0);
  return 1;
}

// FUN_002d0c80

u32 func_002d0c80(void)

{
  func_002f39b0(gBtl->actionList.head);
  return 1;
}

// FUN_002d0cb0

u32 func_002d0cb0(void)

{
  func_0035f060((*(u32 *)(iGpffffb7b8 + (u32)*(u16 *)(*(int *)(iGpffffb6fc + 0xbbc) + 8) * 0x1c)
               & 0x20) != 0);
  return 1;
}

// FUN_002d0d00

u32 func_002d0d00(void)

{
  u64 uVar1 = 0;
  
  func_0028a780(*(u32 *)(iGpffffb6fc + 0x148));
  uVar1 = func_002b8d60(3,0xfff);
  func_0027ed20(uVar1,0);
  uVar1 = func_002a3b40(*(u32 *)(iGpffffb6fc + 0x148),0x1c);
  func_0027ed20(uVar1,0);
  return 1;
}

// FUN_002d0d70

u32 func_002d0d70(void)

{
  u64 uVar1 = 0;
  
  func_0028a780(*(u32 *)(iGpffffb6fc + 0x148));
  uVar1 = func_002b8d60(3,0xfff);
  func_0027ed20(uVar1,0);
  uVar1 = func_002a3b40(*(u32 *)(iGpffffb6fc + 0x148),0x25);
  func_0027ed20(uVar1,0);
  return 1;
}
// FUN_002d0de0

u32 func_002d0de0(void)
{
  RwV3d start;
  RwV3d startCopy;
  RwV3d end;
  RwV3d endCopy;
  u32 packet;

  func_0028a780(*(u32 *)(iGpffffb6fc + 0x148));
  packet = func_002b8d60_u32(3,0xfff);
  func_0027ed20(packet,0);

  start.x = func_0035ee60_f32(0);
  start.y = func_0035ee60_f32(1);
  start.z = func_0035ee60_f32(2);
  end.x = func_0035ee60_f32(3);
  end.y = func_0035ee60_f32(4);
  end.z = func_0035ee60_f32(5);
  startCopy = start;
  endCopy = end;
  packet = func_002a3d70_move(*(u32 *)(iGpffffb6fc + 0x148),
                              &start,&end,&startCopy,&endCopy,1.0f);
  func_0027ed20(packet,0);
  return 1;
}

// FUN_002d0ef0

u32 func_002d0ef0(void)
{
  *(float *)(DAT_00957170_abs + 0) = func_0035ee60_f32(0);
  *(float *)(DAT_00957170_abs + 4) = func_0035ee60_f32(1);
  *(float *)(DAT_00957170_abs + 8) = func_0035ee60_f32(2);
  *(float *)(DAT_00957150_abs + 0) = func_0035ee60_f32(3);
  *(float *)(DAT_00957150_abs + 4) = func_0035ee60_f32(4);
  *(float *)(DAT_00957150_abs + 8) = func_0035ee60_f32(5);
  return 1;
}

// FUN_002d0f90

u32 func_002d0f90(void)
{
  *(float *)(DAT_00957160_abs + 0) = func_0035ee60_f32(0);
  *(float *)(DAT_00957160_abs + 4) = func_0035ee60_f32(1);
  *(float *)(DAT_00957160_abs + 8) = func_0035ee60_f32(2);
  *(float *)(DAT_00957140_abs + 0) = func_0035ee60_f32(3);
  *(float *)(DAT_00957140_abs + 4) = func_0035ee60_f32(4);
  *(float *)(DAT_00957140_abs + 8) = func_0035ee60_f32(5);
  return 1;
}

// FUN_002d1030

u32 func_002d1030(void)

{
  int iVar1 = 0;
  u64 uVar2 = 0;
  
  func_0028a780(*(u32 *)(iGpffffb6fc + 0x148));
  uVar2 = func_002b8d60(3,0xfff);
  func_0027ed20(uVar2,0);
  iVar1 = func_0035ed20_u32(0);
  uVar2 = func_002a3d70_f32((float)iVar1 / 30.0f,*(u32 *)(iGpffffb6fc + 0x148),
                           &DAT_00957170_abs,&DAT_00957150_abs,&DAT_00957160_abs,&DAT_00957140_abs);
  func_0027ed20(uVar2,0);
  return 1;
}

// FUN_002d10f0

u32 func_002d10f0(void)
{
  extern u32 func_0035ed20(u32);
  extern u32 func_002db890(void);
  extern u32 func_002db800(u32,u32);
  u32 selector;
  u32 value;
  u32 effect;

  selector = func_0035ed20(0);
  value = func_0035ed20(1);
  effect = func_002db890();
  *(u16 *)(effect + 0x48) = value;
  func_0027ed20(effect,1);
  effect = func_002db800(0x20,selector);
  *(u16 *)(effect + 0x48) = value;
  func_0027ed20(effect,1);
  return 1;
}

// FUN_002d1180

u32 func_002d1180(void)
{
  extern u32 func_0035ed20(u32);
  extern u32 func_002db890(void);
  u32 value;
  u32 effect;

  value = func_0035ed20(0);
  effect = func_002db890();
  *(u16 *)(effect + 0x48) = value;
  func_0027ed20(effect,1);
  return 1;
}


// FUN_002d11d0

u32 func_002d11d0(void)

{
  long lVar1 = 0;
  
  lVar1 = func_002d1a70();
  if (lVar1 == 1) {
    *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) | 0x4000;
  }
  return 1;
}

// FUN_002d1210

u32 func_002d1210(void)

{
  long lVar1 = 0;
  
  lVar1 = func_002d1a70();
  if (lVar1 == 1) {
    *(u32 *)(iGpffffb6fc + 0xc) = *(u32 *)(iGpffffb6fc + 0xc) & 0xffffbfff;
    func_002d1a10();
  }
  return 1;
}
// FUN_002d1260

u32 func_002d1260(void)

{
  long lVar1 = 0;
  
  func_001ff3b0();
  lVar1 = func_002d1a70();
  if (lVar1 == 1) {
    func_001ff370();
  }
  return 1;
}

// FUN_002d12a0

u32 func_002d12a0(void)

{
  long lVar1 = 0;
  
  func_001ff390();
  lVar1 = func_002d1a70();
  if (lVar1 == 1) {
    func_001ff350();
  }
  return 1;
}

// FUN_002d12e0

u32 func_002d12e0(void)
{
  extern u32 func_0029ad20(void);
  extern u32 func_0035ed20(u32);
  u32 unit;
  u16 side;
  u16 expectedId;
  u32 valid;

  unit = func_0029ad20();
  side = func_0035ed20(0);
  expectedId = func_0035ed20(1);
  valid = 1;
  switch (side) {
  case 0:
    if (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) != 0) {
      valid = 0;
    }
    break;
  case 1:
    if (*(u8 *)(*(int *)(unit + 0x30) + 0xa2) != 1) {
      valid = 0;
    }
    break;
  }
  if ((valid == 1) && (*(u16 *)(*(int *)(unit + 0x30) + 0xa4) != expectedId)) {
    valid = 0;
  }
  func_0035f060(valid != 0);
  return 1;
}

// FUN_002d13c0

u32 func_002d13c0(void)
{
  extern u32 func_0035f160(void);
  extern u16 func_002c6ba0(void *);
  extern void *func_002c6e30(void *,u16);
  extern void func_002c6a00(void *,void *,u16);
  char *unit;
  char *action;
  u16 selector;
  u32 actionWord;
  s32 result;

  unit = (char *)func_0035f160();
  selector = func_002c6ba0(unit);
  action = (char *)func_002c6e30(unit,selector);
  func_002c6a00(unit,unit + 0x38,*(u16 *)(action + 2));
  actionWord = *(u32 *)(action + 4);
  result = (*(s32 (**)(void *,u32))
      &PTR_FUN_006975e0[((actionWord & 0xff000000) >> 24) * 2])(unit,actionWord & 0xffffff);
  if (result == 0) {
    (*(s32 (**)(void *,u32))PTR_FUN_006975e0)(unit,0);
  }
  return 1;
}

// FUN_002d1490

u32 func_002d1490(void)

{
  u64 uVar1 = 0;
  
  uVar1 = func_0035ed20(0);
  uVar1 = func_002ffbc0(uVar1);
  func_0035f060(uVar1);
  return 1;
}

// FUN_002d14d0

u32 func_002d14d0(void)
{
  extern u32 func_0035ed20(s32);
  u32 index;
  u32 base;

  index = func_0035ed20(0);
  base = (u32)*(u8* volatile /* Removing this qualifier loses func_002d14d0 (MATCH nd0 -> MISMATCH nd7, size 64 -> 64) - measured W170. */ *)&iGpffffb6fc;
  index <<= 2;
  func_0035f060(*(u32 *)(index + base + 0xd30));
  return 1;
}


/* Declaration notes: these raw FUN/LAB/DAT symbols are retained where no canonical
 * target-module API has been established.  FUN_0027ec10 is btlPacketCreate;
 * FUN_00300580/FUN_0030b5a0/FUN_0030b5e0/FUN_003005e0 are datCalc status/dead,
 * low-HP, and skill queries; FUN_002ffcc0/FUN_002ffd70/FUN_002ffdf0 are the
 * datCalc level/HP/max-HP queries.  FUN_00174800/FUN_00174a90 map to the
 * persona getters, FUN_0016c4f0/FUN_0016c5f0/FUN_0016c970/FUN_0016c920/
 * FUN_0016dd60/FUN_0017b170 map to datGetHp/datGetMaxHp/
 * datGetBadStatusNoDown/datGetPhysicalCondition/datGetPartyId/datGetTotalBtl.
 * iGpffffb6fc is the battle-work base (gBtl/DAT_007ce3ec alias); iGpffffb720
 * is the enemy-data table (DAT_007ce410 alias).  Retail ABI arguments omitted by
 * Ghidra are explicit in FUN_002d9d70: party slot, persona pc-id, and random-list
 * count.  FUN_002d8390 uses the retail slti/xori inversion (difference >= 4). */
/* Narrow ABI aliases used by FUN_002d8110; the raw declarations above serve
 * other decompiler-style callers in this translation unit. */

// FUN_002d1510

u32 func_002d1510(void)

{
  extern u32 func_0035ed20(s32);
  u32 iVar1 = 0;
  u32 uVar2 = 0;
  u32 base;
  
  iVar1 = func_0035ed20(0);
  uVar2 = func_0035ed20(1);
  base = (u32)*(u8* volatile /* Removing this qualifier loses func_002d1510 (MATCH nd0 -> MISMATCH nd7, size 80 -> 80) - measured W170. */ *)&iGpffffb6fc;
  iVar1 <<= 2;
  *(u32 *)(iVar1 + base + 0xd30) = uVar2;
  return 1;
}

// FUN_002d1560
u32 func_002d1560(void)
{
  return 1;
}

// FUN_002d1570
void btlTargetInit(BtlTarget* target)
{
    memset(target, 0, sizeof(BtlTarget));
}

// FUN_002d15a0
void btlTargetReset(BtlTarget* target)
{
    target->targetedCount = 0;
    target->specificId = 0;
    target->unk_38 = 0;
    target->commandId = 0;

    memset(target->unk_3e, 0, sizeof(target->unk_3e));
}


// FUN_002d15e0
void FUN_002d15e0(BtlTarget* target)
{
    target->oldCommandId = target->commandId;
    target->oldSpecificId = target->specificId;
}

#pragma opt_loop_invariants on
// FUN_002d1600
u16 FUN_002d1600(BtlTarget* target)
{
    u16 mask = 0;
    u16 i = 0;
    u16 bit = 1;
    s32 count = target->targetedCount;

    for (; i < count; i++) {
        mask |= bit << target->targetedActions[i]->unit->genus;
    }
    return mask;
}
#pragma opt_loop_invariants off
// FUN_002d1660 NONMATCHING
void FUN_002d1660(void* source, BtlTarget* target, u64 mask)
{
    u8* selected = NULL;
    u32 state = 0;
    u16 total = 0;
    u16 roll;
    u16 i;

    target->targetedCount = 0;
    target->specificId = 0;
    target->unk_38 = 0;
    target->commandId = 0;
    FUN_00521408(target->unk_3e, 0, 6);
    mask &= 0xFFFFFu;
    switch (mask) {
    case 1:
    {
        s32 first = PTR_FUN_006973cc_abs[0](source, 0);
        s32 second = PTR_FUN_0069721c_abs[0](source, 1);
        if (first == 1) {
            if (second == 0) {
                state = 0;
            } else {
                state = 1;
            }
        } else if (first == 0) {
            if (second == 0) {
                state = 2;
            } else {
                state = 3;
            }
        }
        selected = DAT_00697730;
        break;
    }
    case 8:
    {
        u8* work = *(u8**)((u8*)source + 0x30);
        if (work[0xA2] == 0 && *(u16*)(work + 0xA4) == 1) {
            state = 1;
        } else {
            state = PTR_FUN_00697294_abs[0](source, 0) == 0;
        }
        selected = DAT_006977D0;
        break;
    }
    case 0x10:
        selected = gp0xffff9c60;
        break;
    case 0x20:
        selected = gp0xffff9c68;
        break;
    case 0x40:
        selected = gp0xffff9c70;
        break;
    case 0x200:
        selected = gp0xffff9c78;
        break;
    default:
        break;
    }
    if (selected == DAT_00697730 || selected == DAT_006977D0) {
        selected += (state & 0xFFFFu) * 0x28;
        for (i = 0, total = 0; i < 5; i++) {
            total = (u16)(total + selected[i * 8]);
        }
        roll = (u16)FUN_002FFBC0(total);
        total = 0;
        for (i = 0; i < 5; i++) {
            u8 weight = selected[i * 8];
            total = (u16)(total + weight);
            if (roll <= total && weight != 0) {
                break;
            }
        }
        selected += i * 8;
    }
    FUN_002C6A00(source, target, *(u16*)(selected + 2));
    {
        u32 callback = *(u32*)(selected + 4);
        s32 result = PTR_FUN_006975e0[(callback >> 24) * 2](
            source, callback & 0xFFFFFFu);
        if (result == 0) {
            PTR_FUN_006975e0[0](source, 0);
        }
    }
}



// FUN_002d19b0
void FUN_002d19b0(void)
{
    if ((*(u32*)(iGpffffb6fc + 0x0C) & 0x2000) == 0) {
        *(u32*)(iGpffffb6fc + 0x0C) |= 0x2000;
        FUN_0010A4E0(0, 0x0F, 0, 3);
        FUN_001FF310();
    }
}

// FUN_002d1a10
void FUN_002d1a10(void)
{
    if ((*(u32*)(iGpffffb6fc + 0x0C) & 0x2000) != 0) {
        *(u32*)(iGpffffb6fc + 0x0C) &= ~0x2000u;
        FUN_0010A4E0(0, 0x0F, 0, 4);
        FUN_001FF330();
    }
}

// FUN_002d1a70
s32 FUN_002d1a70(void)
{
    if ((*(u32*)(iGpffffb6fc + 0x0C) & 0x80) != 0) {
        return 0;
    }
    return FUN_002FD7C0() != 0;
}

// FUN_002d1ac0
void FUN_002d1ac0(void)
{
    s32 canToggle;
    u32* flags;
    u32 flagsValue;
    u32 mode;

    flags = (u32*)(iGpffffb6fc + 0x0c);
    if ((*flags & 0x80) != 0) {
        canToggle = 0;
    } else {
        if (FUN_002FD7C0() != 0)
            goto canToggleActive;
        canToggle = 0;
        goto canToggleDone;
    canToggleActive:
        canToggle = 1;
    canToggleDone:
        ;
    }
    if (canToggle == 0)
        goto done;
    flags = (u32*)(iGpffffb6fc + 0x0c);
    flagsValue = *flags;
    if ((flagsValue & 0x4000) == 0)
        goto done;
    mode = flagsValue & 0x2000;
    if (mode == 0)
        goto enableChecks;
    if ((DAT_007e094e_u16[0] & 0x10) != 0)
        goto disable;
    if ((DAT_007e0958_u16[0] & 0x10) != 0)
        goto disable;
    if ((DAT_007e094e_u16[0] & 0x20) != 0)
        goto disable;
    if ((DAT_007e0958_u16[0] & 0x20) == 0)
        goto done;
disable:
    if (mode == 0)
        goto done;
    *flags &= ~0x2000u;
    FUN_0010A4E0(0, 0x0f, 0, 4);
    FUN_001FF330();
    goto done;
enableChecks:
    if ((DAT_007e094e_u16[0] & 0x10) != 0)
        goto enable;
    if ((DAT_007e0958_u16[0] & 0x10) == 0)
        goto done;
enable:
    if (mode != 0)
        goto done;
    *flags |= 0x2000;
    FUN_0010A4E0(0, 0x0f, 0, 3);
    FUN_001FF310();
done:
    ;
}

// FUN_002d1c20
u32 FUN_002d1c20(void* data)
{
    u8* state = (u8*)data;
    u32 result;

    if (((BtlTargetScriptWork*)state)->started == 0)
    {
        BtlTargetScriptWork* work = (BtlTargetScriptWork*)state;

        FUN_002C6F50(work->action, &work->action->target,
                     work->script, work->procedureIndex);
        *((u8*)work->action + 0x68) = 1;
        work->started = 1;
        goto return_zero;
    }
    else
    {
        state = (u8*)&((BtlTargetScriptWork*)state)->action->target;
        if (state[0x30] == 0)
        {
            result = 1;
        }
        else
        {
            KwlnTask* task = *(KwlnTask**)(state + 0x4c);

            if (task == NULL)
            {
                result = 1;
            }
            else
            {
                result = FUN_00195460(task);
                if (result == 0)
                {
                    state[0x30] = 0;
                    *(u32*)(state + 0x4c) = 0;
                    result = 1;
                }
                else
                {
                    result = 0;
                }
            }
        }
    }

    if (result == 0)
    {
        goto return_zero;
    }
    return 1;

return_zero:
    return 0;
}


// FUN_002d1d00
BtlPacket* FUN_002d1d00(BtlAction* action, u16 mode,
                         const char* procedureName)
{
    BtlPacket* packet = FUN_0027EC10(0xd00, 0x10);
    BtlTargetScriptWork* work;

    packet->unk_47 &= 0xee;
    packet->updateFunc = FUN_002d1c20;
    work = (BtlTargetScriptWork*)packet->workData;
    switch (mode)
    {
        case 1:
            work->script = (ScrHeader*)(uintptr_t)uGpffffb7dc;
            break;
        case 2:
            work->script = (ScrHeader*)(uintptr_t)uGpffffb7e0;
            break;
    }
    work->action = action;
    work->procedureIndex = scrFindPrcdIdxByName(work->script, procedureName);
    work->started = 0;
    return packet;
}

// FUN_002d1de0
void FUN_002d1de0(u64 task, const RwV3d* from, const RwV3d* to)
{
    f32 deltaX;
    f32 deltaZ;
    f32 angle;

    deltaX = to->x - from->x;
    deltaZ = to->z - from->z;
    angle = 0.0f;
    if (deltaX != 0.0f || deltaZ != 0.0f) {
        angle = fGpffff80d0 * FUN_0052EA18(deltaX, deltaZ);
    }
    FUN_004BDDE0(task, DAT_00697880, angle, 0);
}

// FUN_002d1e70
void FUN_002d1e70(f32* from, f32* to)
{
    f32 delta[3];
    delta[0] = from[0] - to[0];
    delta[1] = from[1] - to[1];
    delta[2] = from[2] - to[2];
    FUN_004C6AC0(delta);
}
// FUN_002d1ed0
void FUN_002d1ed0(f32* from, f32* to)
{
    f32 delta[4];
    delta[0] = from[0] - to[0];
    delta[1] = from[1] - to[1];
    delta[2] = from[2] - to[2];
    delta[1] = 0.0f;
    FUN_004C6AC0(delta);
}


// FUN_002d1f30
f32 FUN_002d1f30(f32* left, f32* right)
{
    f32 dot = left[0] * right[0] + left[1] * right[1] +
              left[2] * right[2];
    dot += left[3] * right[3];

    if (dot < 0.0f)
    {
        dot = left[0] * -right[0] + left[1] * -right[1] +
              left[2] * -right[2];
        dot += left[3] * -right[3];
    }
    return FUN_0052E9E8(dot) * 2.0f;
}

// FUN_002d1fd0
f32 FUN_002d1fd0(f32* a, f32* b, f32* point, f32* projected)
{
    f32 result;
    RwV2d axis;
    f32 distance;
    f32* pointAlias;
    f32 axisY;
    f32 dx;
    f32 dy;

    axis.x = a[0] - b[0];
    axis.y = a[1] - b[1];
    FUN_004C6B20(&axis, &axis);
    dx = point[0] - a[0];
    axisY = axis.y;
    distance = a[1];
    pointAlias = point;
    dy = point[1] - distance;
    result = dx * axisY + dy * -axis.x;
    distance = result;
    if (projected != NULL) {
        projected[0] = pointAlias[0] - distance * axisY;
        projected[1] = point[1] - distance * -axis.x;
    }
    return fabsf(distance);
}

// FUN_002d20a0
u32 FUN_002d20a0(const RwV3d* projected, f32* screen)
{
    RwCamera* camera;
    RwV3d cameraPoint;
    f32 nearPlane;
    f32 farPlane;
    f32 x;
    f32 y;

    camera = kwlnGetMainCamera();
    RwV3dTransformPoint(&cameraPoint, projected,
                        (RwMatrix*)((uintptr_t)camera + 0x20));

    camera = kwlnGetMainCamera();
    nearPlane = camera->nearPlane;
    camera = kwlnGetMainCamera();
    farPlane = camera->farPlane;

    if ((cameraPoint.z <= nearPlane) || !(cameraPoint.z < farPlane))
    {
        return 0;
    }

    x = (cameraPoint.x / cameraPoint.z) * 640.0f;
    y = (cameraPoint.y / cameraPoint.z) * 448.0f;
    if ((x < -640.0f) || !(x <= 1280.0f) ||
        (y < -448.0f) || !(y <= 896.0f))
    {
        return 0;
    }

    screen[0] = x;
    screen[1] = y;
    return 1;
}

// FUN_002d21e0
f32 FUN_002d21e0(f32 value, volatile /* Removing this qualifier loses FUN_002d21e0 (MATCH nd0 -> MISMATCH nd6, size 148 -> 148) - measured W170. */ f32* state)
{
    f32 current;
    f32 slopeBase;
    f32 remaining;
    f32 resultBase;
    f32 slope;
    f32 result;

    current = state[1];
    slopeBase = state[3];
    resultBase = state[4];
    remaining = current - value;

    if (remaining <= 0.0f)
    {
        return 1.0f;
    }
    if (remaining < state[0] * 0.5f)
    {
        slope = slopeBase - state[2] * value;
    }
    else
    {
        slope = state[2] * value + slopeBase;
    }
    result = slope * value + resultBase;
    state[1] = remaining;
    state[3] = slope;
    state[4] = result;
    return result;
}

// FUN_002d2280
void FUN_002d2280(s16* outX, s16* outZ, f32* position)
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

#pragma push
#pragma opt_propagation off
// FUN_002d2340
void FUN_002d2340(f32 distance, u8* work, s32 start, s32 end)
{
    s32 tiles;
    s16 leftTile;
    s16 rightTile;
    s16 span;
    s16 topTile;
    s16 bottomTile;
    f32 left;
    f32 right;
    f32 top;
    f32 bottom;

    tiles = (s16)((s32)distance / 0x19);
    if ((s32)distance % 0x19 != 0)
        tiles = (s16)(tiles + 1);
    leftTile = start - tiles;
    rightTile = end - tiles;
    left = (f32)(leftTile * 0x19 - 0x6d6);
    right = (f32)(rightTile * 0x19 - 0x6d6);
    span = (s16)tiles * 2;
    topTile = leftTile + span;
    bottomTile = rightTile + span;
    top = (f32)(topTile * 0x19 - 0x6d6);
    bottom = (f32)(bottomTile * 0x19 - 0x6d6);
    *(f32*)(work + 0x504) = left;
    *(f32*)(work + 0x508) = right;
    *(f32*)(work + 0x634) = top;
    *(f32*)(work + 0x638) = right;
    *(f32*)(work + 0x764) = top;
    *(f32*)(work + 0x768) = bottom;
    *(f32*)(work + 0x894) = left;
    *(f32*)(work + 0x898) = bottom;
}
#pragma pop

// FUN_002d2470
s32 FUN_002d2470(const f32* a, const f32* b, const f32* point, f32 tolerance)
{
    RwV2d axis;
    f32 projected[2];
    f32 dy;
    f32 dx;
    f32 axisX;
    f32 axisY;
    axis.x = a[0] - b[0];
    axis.y = a[1] - b[1];
    FUN_004C6B20(&axis, &axis);
    dx = point[0] - a[0];
    dy = point[1] - a[1];
    axisX = -axis.x;
    axisY = axis.y;
    dy = dy * axisX;
    dx = dx * axisY + dy;
    projected[0] = point[0] - dx * axisY;
    projected[1] = point[1] - dx * axisX;
    if (((a[0] < projected[0] || b[0] > projected[0]) &&
         (a[0] > projected[0] || b[0] < projected[0])) ||
        ((a[1] < projected[1] || b[1] > projected[1]) &&
         (a[1] > projected[1] || b[1] < projected[1]))) {
        return 0;
    }
    return fabsf(dx) < tolerance;
}

// FUN_002d25c0 NONMATCHING
s32 FUN_002d25c0(const u8* param_1, const u8* param_2)
{
    s32 result;
    s32 i;
    u8* list;

    result = 0;
    list = *(u8**)(iGpffffb6fc + 0x2cc);
    do
    {

        if ((list == NULL) || (result != 0))
        {
            return result;
        }
        for (i = 0; i < 4; i++)
        {
            u8* cell = list + i * 0x130;
            const f32* cellPoint = (const f32*)(cell + 8);

            if ((0.0f < *(f32*)(cell + 0x1c)) &&
                ((const u8*)cellPoint != param_1) &&
                ((const u8*)cellPoint != param_2))
            {
                RwV2d delta;
                const f32* otherPoint;
                const f32* cellX = (const f32*)(cell + 0x10);
                const f32* cellY = (const f32*)(cell + 0x14);
                s32 side1;
                s32 side2;
                s32 intersects;

                delta.x = *cellX - *(const f32*)(param_1 + 8);
                delta.y = *cellY - *(const f32*)(param_1 + 0xc);
                if (!(FUN_004c6af0((f32*)&delta) < 1.0f))
                {
                    delta.x = *cellX - *(const f32*)(param_2 + 8);
                    delta.y = *cellY - *(const f32*)(param_2 + 0xc);
                    if (!(FUN_004c6af0((f32*)&delta) < 1.0f))
                    {
                        otherPoint = *(const f32**)(cell + 0x18);
                        side1 = FUN_002d2990(cellPoint, otherPoint,
                                             (const f32*)(param_1 + 8));
                        side2 = FUN_002d2990(cellPoint, otherPoint,
                                             (const f32*)(param_2 + 8));
                        if (side1 != side2)
                        {
                            side1 = FUN_002d2990((const f32*)(param_1 + 8),
                                                 (const f32*)(param_2 + 8),
                                                 cellPoint);
                            side2 = FUN_002d2990((const f32*)(param_1 + 8),
                                                 (const f32*)(param_2 + 8),
                                                 otherPoint);
                            if (side1 != side2)
                            {
                                intersects = 1;
                            }
                            else
                            {
                                intersects = 0;
                            }
                        }
                        else
                        {
                            intersects = 0;
                        }
                        if (intersects != 0)
                        {
                            result = 1;
                            break;
                        }
                    }
                }
            }
        }

        if (result == 0)
        {
            if ((((*(const f32*)(param_1 + 8) <= *(f32*)(list + 8)) ||
                  (*(const f32*)(param_1 + 0xc) <= *(f32*)(list + 0xc))) ||
                 ((*(f32*)(list + 0x268) <= *(const f32*)(param_1 + 8)) ||
                  (*(f32*)(list + 0x26c) <= *(const f32*)(param_1 + 0xc)))) &&
                (((*(const f32*)(param_2 + 8) <= *(f32*)(list + 8)) ||
                  (*(const f32*)(param_2 + 0xc) <= *(f32*)(list + 0xc))) ||
                 ((*(f32*)(list + 0x268) <= *(const f32*)(param_2 + 8)) ||
                  (*(f32*)(list + 0x26c) <= *(const f32*)(param_2 + 0xc)))))
            {
                for (i = 0; i < 4; i++)
                {
                    const f32* edgeA =
                        (const f32*)(list + (((i + 1U) & 3) * 0x130) + 8);
                    const f32* edgeB = (const f32*)(list + i * 0x130 + 8);
                    s32 side1 = FUN_002d2990(edgeB, edgeA,
                                             (const f32*)(param_1 + 8));
                    s32 side2 = FUN_002d2990(edgeB, edgeA,
                                             (const f32*)(param_2 + 8));
                    s32 intersects;

                    if (side1 != side2)
                    {
                        side1 = FUN_002d2990((const f32*)(param_1 + 8),
                                             (const f32*)(param_2 + 8), edgeB);
                        side2 = FUN_002d2990((const f32*)(param_1 + 8),
                                             (const f32*)(param_2 + 8), edgeA);
                        if (side1 != side2)
                        {
                            intersects = 1;
                        }
                        else
                        {
                            intersects = 0;
                        }
                    }
                    else
                    {
                        intersects = 0;
                    }
                    if (intersects != 0)
                    {
                        result = 1;
                        break;
                    }
                }
            }
        }

        list = *(u8**)(list + 0x4cc);
    } while (1);
    return result;
}

// FUN_002d2990
int FUN_002d2990(const float *param_1, const float *param_2, const float *param_3)
{
    float cross = (param_2[0] - param_1[0]) * (param_3[1] - param_1[1]) -
                  (param_2[1] - param_1[1]) * (param_3[0] - param_1[0]);

    if (cross <= 0.0f)
    {
        goto nonpositive;
    }
    return 1;

nonpositive:
    return -(cross < 0.0f);
}

// FUN_002d2a00 NONMATCHING
int FUN_002d2a00(float param_1, float *param_2, float *param_3)
{
    u8 *node;

    for (node = *(u8 **)(iGpffffb6fc + 0x2cc); node != NULL; node = *(u8 **)(node + 0x4cc))
    {
        if (((param_2[0] <= *(float *)(node + 0x08)) ||
             (param_2[1] <= *(float *)(node + 0x0c)) ||
             (*(float *)(node + 0x268) <= param_2[0]) ||
             (*(float *)(node + 0x26c) <= param_2[1])) &&
            ((param_3[0] <= *(float *)(node + 0x08)) ||
             (param_3[1] <= *(float *)(node + 0x0c)) ||
             (*(float *)(node + 0x268) <= param_3[0]) ||
             (*(float *)(node + 0x26c) <= param_3[1])))
        {
            int i;
            for (i = 0; i < 4; ++i)
            {
                int side_a;
                int side_b;

                side_a = FUN_002d2990(
                    (float *)(node + i * 0x130 + 0x08),
                    (float *)(node + (((i + 1) & 3) * 0x130) + 0x08),
                    param_2);
                side_b = FUN_002d2990(
                    (float *)(node + i * 0x130 + 0x08),
                    (float *)(node + (((i + 1) & 3) * 0x130) + 0x08),
                    param_3);

                if (side_a != side_b)
                {
                    side_a = FUN_002d2990(
                        param_2, param_3,
                        (float *)(node + i * 0x130 + 0x08));
                    side_b = FUN_002d2990(
                        param_2, param_3,
                        (float *)(node + (((i + 1) & 3) * 0x130) + 0x08));
                    if (side_a != side_b)
                    {
                        return 1;
                    }
                }
                if (FUN_002d2470_call(
                        param_1, param_2, param_3,
                        (float *)(node + i * 0x130 + 0x08)) != 0)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

/* W419 negative: split/reordered the second-loop index declaration in FUN_002d2c10; nd15 -> 22/23 at object 712/720. */
/* W421 classification: baseline verify nd15 at 712/720 (rate 0.021067).
 * The second-loop residual is saved-register role coloring, not argument
 * setup or a commutative swap: +376 ours lw $s5,0x2cc($v0) versus retail
 * lw $s1,0x2cc($v0); +388 move $s1,$zero versus move $s0,$zero;
 * +400 sll $v0,$s1,3 versus sll $v0,$s0,3; +404 and +412 addu
 * $v0,$v0,$s1 versus addu $v0,$v0,$s0; +420 addu $v0,$s5,$v0 versus
 * addu $v0,$s1,$v0; +472 lw $s0,0x18($v0) versus lw $s5,0x18($v0);
 * +476 beqz $s0 versus beqz $s5; +488/+512 move $a1,$s0 versus move
 * $a1,$s5; +568 move $a2,$s0 versus move $a2,$s5; +636 addiu $s1,$s1,1
 * versus addiu $s0,$s0,1; +640 slti uses $s1 versus $s0; +652 lw
 * $s5,0x4cc($s5) versus lw $s1,0x4cc($s1); +656 bnez $s5 versus bnez
 * $s1.  Declaration reorder measured nd22 at 712/720 (rate 0.030899);
 * formal-parameter flip measured nd34 at 712/720 (rate 0.047753). */
// FUN_002d2c10
int FUN_002d2c10(float *param_1, float *param_2)
{
    u8 *node;
    int i;

    if (*(u8 **)((u8 *)param_2 + 0x10) == (u8 *)param_1)
    {
        return 1;
    }

    for (node = *(u8 **)(iGpffffb6fc + 0x2cc); node != NULL; node = *(u8 **)(node + 0x4cc))
    {
        for (i = 0; i < 4; ++i)
        {
            int wrap = (i + 1) & 3;
            float *edge = (float *)(node + i * 0x130 + 0x08);
            float *next;

            if ((edge == param_1) || (edge == param_2))
            {
                continue;
            }
            next = (float *)(node + wrap * 0x130 + 0x08);
            if ((next == param_1) || (next == param_2))
            {
                continue;
            }
            else
            {
                int intersects;
                int side_a = FUN_002d2ee0(edge, next, param_1);
                int side_b = FUN_002d2ee0(edge, next, param_2);
                if (side_a != side_b)
                {
                    side_a = FUN_002d2ee0(param_1, param_2, edge);
                    side_b = FUN_002d2ee0(param_1, param_2, next);
                    if (side_a != side_b)
                    {
                        intersects = 1;
                    }
                    else
                    {
                        intersects = 0;
                    }
                }
                else
                {
                    intersects = 0;
                }
                if (intersects != 0)
                {
                    return 1;
                }
            }
        }
    }

    {
        u8 *record;
        float *next;
        float *edge;
        u8 *node2;
        int j;
        for (node2 = *(u8 **)(iGpffffb6fc + 0x2cc); node2 != NULL; node2 = *(u8 **)(node2 + 0x4cc))
        for (j = 0; j < 4; ++j)
        {
            record = node2 + j * 0x130;
            edge = (float *)(record + 0x08);

            if (edge == param_1)
            {
                return 0;
            }
            if (*(float *)(record + 0x1c) <= 0.0f)
            {
                continue;
            }
            next = *(float **)(record + 0x18);
            if (next != NULL)
            {
                int intersects;
                int side_a = FUN_002d2ee0(edge, next, param_1);
                int side_b = FUN_002d2ee0(edge, next, param_2);
                if (side_a != side_b)
                {
                    side_a = FUN_002d2ee0(param_1, param_2, edge);
                    side_b = FUN_002d2ee0(param_1, param_2, next);
                    if (side_a != side_b)
                    {
                        intersects = 1;
                    }
                    else
                    {
                        intersects = 0;
                    }
                }
                else
                {
                    intersects = 0;
                }
                if (intersects != 0)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// FUN_002d2ee0
int FUN_002d2ee0(const float *param_1, const float *param_2, const float *param_3)
{
    int side;
    float cross;

    cross = (param_2[0] - param_1[0]) * (param_3[1] - param_1[1]) -
            (param_2[1] - param_1[1]) * (param_3[0] - param_1[0]);
    if (cross >= 0.0f)
    {
        side = 1;
    }
    else
    {
        side = -(cross < 0.0f);
    }
    return side;
}

// FUN_002d2f50 NONMATCHING
u32 FUN_002d2f50(float param_1, u8 *param_2)
{
    u16 count = 0;
    u16 i;
    u8 *node;

    for (node = *(u8 **)(iGpffffb6fc + 0x2cc); node != NULL; node = *(u8 **)(node + 0x4cc))
    {
        for (i = 0; i < 4; ++i)
        {
            float *point = (float *)(node + i * 0x130 + 0x08);

            if ((point != (float *)param_2) &&
                (0.0f < *(float *)(node + i * 0x130 + 0x1c)) &&
                (param_1 <= *(float *)(node + i * 0x130 + 0x20)) &&
                (FUN_002d25c0(param_2, (const u8*)point) == 0))
            {
                RwV2d delta;
                float length;
                delta.x = *(float *)(param_2 + 0x08) - *(float *)(node + i * 0x130 + 0x10);
                delta.y = *(float *)(param_2 + 0x0c) - *(float *)(node + i * 0x130 + 0x14);
                length = FUN_004c6af0((f32*)&delta);
                *(float *)(param_2 + 0xb0 + ((u32)count * 4)) = length;
                *(u8 **)(param_2 + 0x30 + ((u32)count * 4)) = (u8 *)point;
                count = (u16)(count + 1);
            }
        }
    }

    for (i = 0; i < 4; ++i)
    {
        float *point = (float *)(iGpffffb6fc + i * 0x130 + 0x2d0);

        if ((point != (float *)param_2) &&
            (0.0f < *(float *)(iGpffffb6fc + i * 0x130 + 0x2e4)) &&
            (FUN_002d25c0(param_2, (const u8*)point) == 0))
        {
            RwV2d delta;
            float length;
            delta.x = *(float *)(param_2 + 0x08) - *(float *)(iGpffffb6fc + i * 0x130 + 0x2d8);
            delta.y = *(float *)(param_2 + 0x0c) - *(float *)(iGpffffb6fc + i * 0x130 + 0x2dc);
            length = FUN_004c6af0((f32*)&delta);
            *(float *)(param_2 + 0xb0 + ((u32)count * 4)) = length;
            *(u8 **)(param_2 + 0x30 + ((u32)count * 4)) = (u8 *)point;
            count = (u16)(count + 1);
        }
    }

    if ((iGpffffb6fc + 0x790 != param_2) && (FUN_002d25c0(param_2, iGpffffb6fc + 0x790) == 0))
    {
        RwV2d delta;
        float length;
        delta.x = *(float *)(param_2 + 0x08) - *(float *)(iGpffffb6fc + 0x798);
        delta.y = *(float *)(param_2 + 0x0c) - *(float *)(iGpffffb6fc + 0x79c);
        length = FUN_004c6af0((f32*)&delta);
        *(float *)(param_2 + 0xb0 + ((u32)count * 4)) = length;
        *(u8 **)(param_2 + 0x30 + ((u32)count * 4)) = iGpffffb6fc + 0x790;
        count = (u16)(count + 1);
    }

    if ((iGpffffb6fc + 0x8c0 != param_2) && (FUN_002d25c0(param_2, iGpffffb6fc + 0x8c0) == 0))
    {
        RwV2d delta;
        float length;
        delta.x = *(float *)(param_2 + 0x08) - *(float *)(iGpffffb6fc + 0x8c8);
        delta.y = *(float *)(param_2 + 0x0c) - *(float *)(iGpffffb6fc + 0x8cc);
        length = FUN_004c6af0((f32*)&delta);
        *(float *)(param_2 + 0xb0 + ((u32)count * 4)) = length;
        *(u8 **)(param_2 + 0x30 + ((u32)count * 4)) = iGpffffb6fc + 0x8c0;
        count = (u16)(count + 1);
    }

    *(u8 **)(param_2 + 0x30 + ((u32)count * 4)) = NULL;
    return count;
}

// FUN_002d32b0 NONMATCHING
void FUN_002d32b0(float param_1)
{
    u8* other;
    int j;
    int haveBounds = 0;
    s16 corners[8];
    float extent[4];
    int i;
    u8 *node;

    for (node = *(u8 **)(iGpffffb6fc + 0x2cc); node != NULL; node = *(u8 **)(node + 0x4cc))
    {
        if (haveBounds == 0)
        {
            s16 tileX = *(s16 *)(node + 0x00);
            s16 tileY = *(s16 *)(node + 0x02);
            float z = *(float *)(node + 0x04);
            corners[6] = tileX;
            corners[4] = tileX;
            corners[2] = tileX;
            corners[0] = tileX;
            corners[7] = tileY;
            corners[5] = tileY;
            corners[3] = tileY;
            corners[1] = tileY;
            extent[3] = z;
            extent[2] = z;
            extent[1] = z;
            extent[0] = z;
            haveBounds = 1;
        }
        else
        {
            s16 tileX = *(s16 *)(node + 0x00);
            s16 tileY = *(s16 *)(node + 0x02);
            float z = *(float *)(node + 0x04);
            if ((tileX <= corners[0]) && (tileY <= corners[1]))
            {
                corners[0] = tileX;
                corners[1] = tileY;
                extent[0] = z;
            }
            if ((corners[2] <= tileX) && (tileY <= corners[3]))
            {
                corners[2] = tileX;
                corners[3] = tileY;
                extent[1] = z;
            }
            if ((corners[4] <= tileX) && (corners[5] <= tileY))
            {
                corners[4] = tileX;
                corners[5] = tileY;
                extent[2] = z;
            }
            if ((tileX <= corners[6]) && (corners[7] <= tileY))
            {
                corners[6] = tileX;
                corners[7] = tileY;
                extent[3] = z;
            }
        }
    }

    for (i = 0; i < 4; ++i)
    {
        s32 whole = (s32)(extent[i] + 500.0f);
        s16 margin = (s16)(whole / 0x19);
        s16 x;
        s16 y;

        if ((whole % 0x19) != 0)
        {
            margin = (s16)(margin + 1);
        }

        if (i == 3)
        {
            x = (s16)(corners[6] - margin);
            y = (s16)(margin + corners[7]);
            if (x < 0)
            {
                x = 0;
            }
        }
        else if (i == 2)
        {
            x = (s16)(margin + corners[4]);
            y = (s16)(margin + corners[5]);
        }
        else if (i == 1)
        {
            x = (s16)(margin + corners[2]);
            y = (s16)(corners[3] - margin);
            if (y < 0)
            {
                y = 0;
            }
        }
        else
        {
            x = (s16)(corners[0] - margin);
            y = (s16)(corners[1] - margin);
            if (x < 0)
            {
                x = 0;
            }
            if (y < 0)
            {
                y = 0;
            }
        }

        *(float *)(iGpffffb6fc + i * 0x130 + 0x2d0) = (float)((s32)x * 0x19 - 0x6d6);
        *(float *)(iGpffffb6fc + i * 0x130 + 0x2d4) = (float)((s32)y * 0x19 - 0x6d6);
    }

    for (node = *(u8 **)(iGpffffb6fc + 0x2cc); node != NULL; node = *(u8 **)(node + 0x4cc))
    {
        for (i = 0; i < 4; ++i)
        {
            u8 *record = node + i * 0x130;
            float *point = (float *)(record + 0x08);
            float bestDistance = 7000.0f;
            RwV2d bestDirection;
            float candidateX = 0.0f;
            float candidateY = 0.0f;
            float candidateZ = 0.0f;
            u8 *bestPoint = NULL;

            for (other = *(u8 **)(iGpffffb6fc + 0x2cc); other != NULL; other = *(u8 **)(other + 0x4cc))
            {
                if (node != other)
                {
                    for (j = 0; j < 4; ++j)
                    {
                        float *candidate = (float *)(other + j * 0x130 + 0x08);
                        RwV2d delta;
                        RwV2d direction;
                        float distance;

                        delta.x = candidate[0] - point[0];
                        delta.y = candidate[1] - point[1];
                        distance = FUN_004C6B20(&direction, &delta);
                        if ((fGpffff827c < direction.x * DAT_006978c0[i * 2] +
                                           direction.y * DAT_006978c0[i * 2 + 1]) &&
                            (distance < bestDistance) &&
                            (FUN_002d2c10(point, candidate) == 0))
                        {
                            bestDirection.x = direction.x;
                            bestDirection.y = direction.y;
                            candidateX = (float)((s32)*(s16 *)(other + 0x00) * 0x19 - 0x6d6);
                            candidateY = (float)((s32)*(s16 *)(other + 0x02) * 0x19 - 0x6d6);
                            candidateZ = *(float *)(other + 0x04);
                            bestDistance = distance;
                            bestPoint = (u8 *)candidate;
                        }
                    }
                }
            }

            for (j = 0; j < 4; ++j)
            {
                u8 *playerRecord = iGpffffb6fc + j * 0x130;
                float *candidate = (float *)(playerRecord + 0x2d0);
                RwV2d delta;
                RwV2d direction;
                float distance;

                delta.x = candidate[0] - point[0];
                delta.y = candidate[1] - point[1];
                distance = FUN_004C6B20(&direction, &delta);
                if ((fGpffff827c < direction.x * DAT_006978c0[i * 2] +
                                   direction.y * DAT_006978c0[i * 2 + 1]) &&
                    (distance < bestDistance) &&
                    (FUN_002d2c10(point, candidate) == 0))
                {
                    bestDirection.x = direction.x;
                    bestDirection.y = direction.y;
                    bestPoint = (u8 *)candidate;
                    candidateX = candidate[0];
                    candidateY = candidate[1];
                    candidateZ = 0.0f;
                    bestDistance = distance;
                }
            }

            if (bestPoint == NULL)
            {
                *(float *)(record + 0x1c) = -1.0f;
            }
            else
            {
                *(float *)(record + 0x10) = point[0] + bestDirection.x * bestDistance * 0.5f;
                *(float *)(record + 0x14) = point[1] + bestDirection.y * bestDistance * 0.5f;
                *(u8 **)(record + 0x18) = bestPoint;
                *(float *)(record + 0x1c) = bestDistance;

                {
                    RwV2d centerDelta;
                    float centerDistance;
                    centerDelta.x = (float)((s32)*(s16 *)node * 0x19 - 0x6d6) - candidateX;
                    centerDelta.y = (float)((s32)*(s16 *)(node + 0x02) * 0x19 - 0x6d6) - candidateY;
                    centerDistance = FUN_004c6af0((f32*)&centerDelta);
                    *(float *)(record + 0x20) = centerDistance - (*(float *)(node + 0x04) + candidateZ);
                }
            }
        }
    }

    for (i = 0; i < 4; ++i)
    {
        u8 *playerRecord = iGpffffb6fc + i * 0x130;
        float *start = (float *)(playerRecord + 0x2d0);
        float *bestPoint = NULL;
        RwV2d bestDirection;
        float bestDistance = 7000.0f;
        for (other = *(u8 **)(iGpffffb6fc + 0x2cc); other != NULL; other = *(u8 **)(other + 0x4cc))
        {
            for (j = 0; j < 4; ++j)
            {
                float *candidate = (float *)(other + j * 0x130 + 0x08);
                RwV2d delta;
                float distance;

                delta.x = candidate[0] - start[0];
                delta.y = candidate[1] - start[1];
                distance = FUN_004c6af0((f32*)&delta);
                if (distance < bestDistance)
                {
                    FUN_004C6B20(&bestDirection, &delta);
                    bestPoint = candidate;
                    bestDistance = distance;
                }
            }
        }

        if ((bestPoint == NULL) ||
            (*(float **)((u8 *)bestPoint + 0x10) == (float *)(playerRecord + 0x2d0)))
        {
            *(float *)(playerRecord + 0x2e4) = -1.0f;
        }
        else
        {
            *(float *)(playerRecord + 0x2d8) = start[0] + bestDirection.x * bestDistance * 0.5f;
            *(float *)(playerRecord + 0x2dc) = start[1] + bestDirection.y * bestDistance * 0.5f;
            *(float **)(playerRecord + 0x2e0) = bestPoint;
            *(float *)(playerRecord + 0x2e4) = bestDistance;
            *(float *)(playerRecord + 0x2e8) = 500.0f;
        }
    }

    for (node = *(u8 **)(iGpffffb6fc + 0x2cc); node != NULL; node = *(u8 **)(node + 0x4cc))
    {
        for (i = 0; i < 4; ++i)
        {
            u8 *record = node + i * 0x130;
            if ((*(float *)(record + 0x1c) <= 0.0f) ||
                (*(float *)(record + 0x20) < param_1))
            {
                *(u32 *)(record + 0x38) = 0;
            }
            else
            {
                FUN_002d2f50(param_1, record + 0x08);
            }
        }
    }

    for (i = 0; i < 4; ++i)
    {
        u8 *playerRecord = iGpffffb6fc + i * 0x130;
        if (0.0f < *(float *)(playerRecord + 0x2e4))
        {
            FUN_002d2f50(param_1, playerRecord + 0x2d0);
        }
        else
        {
            *(u32 *)(playerRecord + 0x300) = 0;
        }
    }

    FUN_002d2f50(param_1, iGpffffb6fc + 0x790);
    FUN_002d2f50(param_1, iGpffffb6fc + 0x8c0);
}

// FUN_002d3d70
void FUN_002d3d70(void)
{
    *(u32*)(iGpffffb6fc + 0x2cc) = 0;
    *(f32*)(iGpffffb6fc + 0x7a4) = -1.0f;
    *(f32*)(iGpffffb6fc + 0x8d4) = -1.0f;
    *(f32*)(iGpffffb6fc + 0x2d0) = -1750.0f;
    *(f32*)(iGpffffb6fc + 0x2d4) = -1750.0f;
    *(f32*)(iGpffffb6fc + 0x400) = -1750.0f;
    *(f32*)(iGpffffb6fc + 0x404) = 1750.0f;
    *(f32*)(iGpffffb6fc + 0x530) = 1750.0f;
    *(f32*)(iGpffffb6fc + 0x534) = -1750.0f;
    *(f32*)(iGpffffb6fc + 0x660) = 1750.0f;
    *(f32*)(iGpffffb6fc + 0x664) = 1750.0f;
}

// FUN_002d3e00
void FUN_002d3e00(BtlUnit* unit, RwV3d* outPos)
{
    RwV3d center;
    f32 radius;
    s16 tileX;
    s16 tileZ;
    u8* raw = (u8*)unit;

    btlUnitGetSphereWorldCenter(unit, &center);
    radius = unit->sphereRadius * unit->scale;
    btlTargetWorldToTile(&tileX, &tileZ, (f32*)&center);
    btlTargetBuildBounds(raw, tileX, tileZ, radius);

    if (outPos != NULL)
    {
        outPos->x = (f32)((s32)tileX * 0x19 - 0x6d6);
        outPos->y = 0.0f;
        outPos->z = (f32)((s32)tileZ * 0x19 - 0x6d6);
    }
    *(s16*)(raw + 0x4fc) = tileX;
    *(s16*)(raw + 0x4fe) = tileZ;
    *(f32*)(raw + 0x500) = radius;
    unit->flags3 |= 4;
    *(u32*)(raw + 0x9c4) = 0;

    if (*(u8**)(iGpffffb6fc + 0x2cc) != NULL)
    {
        *(u8**)(*(u8**)(iGpffffb6fc + 0x2cc) + 0x4c8) = raw + 0x4fc;
        *(u8**)(raw + 0x9c8) = *(u8**)(iGpffffb6fc + 0x2cc);
    }
    else
    {
        *(u8**)(raw + 0x9c8) = NULL;
    }
    *(u8**)(iGpffffb6fc + 0x2cc) = raw + 0x4fc;
}

// Retail VA range: 0x002d9aa0-0x002d9b1f (128 bytes)
// FUN_002d3fe0
void FUN_002d3fe0(BtlUnit* unit)
{
    u8* raw = (u8*)unit;
    u8* next;
    u8* prev;

    if ((unit->flags3 & 4) == 0)
    {
        return;
    }
    unit->flags3 &= ~4u;
    next = *(u8**)(raw + 0x9c8);
    if (next != NULL)
    {
        *(u8**)(next + 0x4c8) = *(u8**)(raw + 0x9c4);
    }
    prev = *(u8**)(raw + 0x9c4);
    if (prev != NULL)
    {
        *(u8**)(prev + 0x4cc) = *(u8**)(raw + 0x9c8);
    }
    else
    {
        *(u8**)(iGpffffb6fc + 0x2cc) = *(u8**)(raw + 0x9c8);
    }
}

// Retail VA range: 0x002d9b20-0x002d9bdf (192 bytes)
// FUN_002d4040
u32 FUN_002d4040(BtlUnit* unit)
{
    RwV3d center;
    f32 radius;
    s16 tileX;
    s16 tileZ;
    u8* raw = (u8*)unit;

    if ((unit->flags3 & 4) == 0)
    {
        return 0;
    }
    btlUnitGetSphereWorldCenter(unit, &center);
    radius = unit->sphereRadius * unit->scale;
    btlTargetWorldToTile(&tileX, &tileZ, (f32*)&center);
    if (*(s16*)(raw + 0x4fc) != tileX ||
        *(s16*)(raw + 0x4fe) != tileZ ||
        *(f32*)(raw + 0x500) != radius)
    {
        btlTargetBuildBounds(raw, tileX, tileZ, radius);
        *(s16*)(raw + 0x4fc) = tileX;
        *(s16*)(raw + 0x4fe) = tileZ;
        *(f32*)(raw + 0x500) = radius;
        return 1;
    }
    return 0;
}

// Retail VA range: 0x002d9be0-0x002d9c9f (192 bytes)
// FUN_002d41c0 NONMATCHING
u32 FUN_002d41c0(RwV2d* output, f32 radius)
{
    RwV2d points[130];
    RwV2d previousDelta;
    RwV2d currentDelta;
    RwV2d previousUnit;
    RwV2d currentUnit;
    RwV2d p0;
    RwV2d p1;
    RwV2d p2;
    RwV2d p3;
    u8* node;
    u8* chosen;
    u16 count;
    u16 i;
    f32 previousLength;
    f32 currentLength;
    f32 halfRadius;
    f32 dot;

    count = 0;
    halfRadius = radius * 0.5f;
    if (FUN_002d2a00(halfRadius,
                     (f32*)(iGpffffb6fc + 0x798),
                     (f32*)(iGpffffb6fc + 0x8c8)) == 0)
    {
        points[0].x = *(f32*)(iGpffffb6fc + 0x8c8);
        points[0].y = *(f32*)(iGpffffb6fc + 0x8cc);
        points[1].x = *(f32*)(iGpffffb6fc + 0x798);
        points[1].y = *(f32*)(iGpffffb6fc + 0x79c);
        count = 2;
    }
    else
    {
        node = iGpffffb6fc + 0x8c0;
        while (node != NULL)
        {
            chosen = node;
            if (count > 0)
            {
                while (node != NULL)
                {
                    if (FUN_002d2a00(halfRadius,
                                     (f32*)&points[count - 1],
                                     (f32*)(node + 8)) != 0)
                    {
                        break;
                    }
                    chosen = node;
                    node = *(u8**)(node + 0x2c);
                }
            }
            points[count].x = *(f32*)(chosen + 8);
            points[count].y = *(f32*)(chosen + 0xc);
            if (count >= 2)
            {
                previousDelta.x = points[count - 1].x -
                                  points[count - 2].x;
                previousDelta.y = points[count - 1].y -
                                  points[count - 2].y;
                currentDelta.x = points[count].x -
                                 points[count - 1].x;
                currentDelta.y = points[count].y -
                                 points[count - 1].y;
                dot = previousDelta.x * currentDelta.x +
                      previousDelta.y * currentDelta.y;
                if (dot > 0.0f)
                {
                    previousLength =
                        FUN_004C6B20(&previousUnit, &previousDelta);
                    currentLength =
                        FUN_004C6B20(&currentUnit, &currentDelta);
                    if (previousLength < 250.0f &&
                        currentLength < 250.0f)
                    {
                        count--;
                        node = chosen;
                        continue;
                    }
                    points[count - 1].x =
                        points[count - 2].x +
                        currentUnit.x * currentLength * 0.65f;
                    points[count - 1].y =
                        points[count - 2].y +
                        currentUnit.y * currentLength * 0.65f;
                }
            }
            count++;
            node = *(u8**)(chosen + 0x2c);
            if (count >= 0x7f)
                break;
        }
    }

    if (count < 2)
    {
        *(u16*)((u8*)output + 0x400) = 0;
        return 0;
    }
    if (count < 3)
    {
        output[0] = points[1];
        output[1] = points[0];
        *(u16*)((u8*)output + 0x400) = 2;
        return 1;
    }

    i = 0;
    while (count - 1 > 0)
    {
        u16 index = count - 1;
        if ((u16)(index + 1) < count)
            p0 = points[index + 1];
        else
            p0 = points[count - 1];
        p1 = points[index];
        if (index == 0)
        {
            p2 = points[0];
            previousDelta.x = points[0].x - p1.x;
            previousDelta.y = points[0].y - p1.y;
            FUN_004C6B20(&previousUnit, &previousDelta);
            p2.x = points[0].x + previousUnit.x * 300.0f;
            p2.y = points[0].y + previousUnit.y * 300.0f;
        }
        else
        {
            p2 = points[index - 1];
        }
        if (index < count - 1)
        {
            p3 = points[index + 1];
        }
        else
        {
            p3 = points[count - 1];
        }
        if (index < 2)
        {
            previousDelta.x = points[0].x - p1.x;
            previousDelta.y = points[0].y - p1.y;
            FUN_004C6B20(&previousUnit, &previousDelta);
            p3.x = points[0].x + previousUnit.x * 500.0f;
            p3.y = points[0].y + previousUnit.y * 500.0f;
        }

        output[i] = p1;
        output[i + 1].x = 0.8671875f * p1.x -
                          0.0703125f * p0.x +
                          0.226563f * p2.x -
                          0.0234375f * p3.x;
        output[i + 1].y = 0.8671875f * p1.y -
                          0.0703125f * p0.y +
                          0.226563f * p2.y -
                          0.0234375f * p3.y;
        output[i + 2].x = -0.0625f * p1.x +
                          0.5625f * p0.x +
                          0.5625f * p2.x -
                          0.0625f * p3.x;
        output[i + 2].y = -0.0625f * p1.y +
                          0.5625f * p0.y +
                          0.5625f * p2.y -
                          0.0625f * p3.y;
        output[i + 3].x = 0.226563f * p1.x -
                          0.0234375f * p0.x +
                          0.8671875f * p2.x -
                          0.0703125f * p3.x;
        output[i + 3].y = 0.226563f * p1.y -
                          0.0234375f * p0.y +
                          0.8671875f * p2.y -
                          0.0703125f * p3.y;
        i += 4;
        count--;
    }
    output[i] = points[0];
    *(u16*)((u8*)output + 0x400) = i + 1;
    return 1;
}

// Retail VA range: 0x002d9ca0-0x002d9d5f (192 bytes)
// FUN_002d4800
void FUN_002d4800(void* work)
{
    *(u16*)((u8*)work + 0x400) = 0;
    *(u16*)((u8*)work + 0x402) = 0;
}

// Retail VA range: 0x002d9d60-0x002d9d6f (16 bytes)
// FUN_002d4810
void* FUN_002d4810(void)
{
    f32 bestDistance = 350000.0f;
    u8* node;
    u8* current;
    u8* best;
    u8* prev;
    u8** head = (u8**)(iGpffffb6fc + 0x9f0);

    current = *head;
    node = current;
    while (node != NULL)
    {
        f32 distance = *(f32*)(node + 0x20);
        if (bestDistance > distance)
        {
            best = node;
            bestDistance = distance;
        }
        node = *(u8**)(node + 0x24);
    }

    prev = NULL;
    while (current != NULL)
    {
        if (current == best)
        {
            break;
        }
        prev = current;
        current = *(u8**)(current + 0x24);
    }
    if (current != NULL)
    {
        if (prev != NULL)
        {
            *(u8**)(prev + 0x24) = *(u8**)(current + 0x24);
        }
        else
        {
            *head = *(u8**)(current + 0x24);
        }
    }
    return best;
}


// FUN_002d48c0 NONMATCHING
u32 FUN_002d48c0(void* work, const RwV2d* start, const RwV2d* end, f32 radius)
{
    u8* selected;
    u8* current;
    u8* previous;
    u8* record;
    u8* slot;
    u16 index;
    u32 inFirst;
    u32 inSecond;
    u32 result;
    f32 score;
    RwV2d delta;

    *(u8*)((u8*)work + 0x404) = 1;
    if (FUN_002d2a00(radius * 0.5f, (f32*)start, (f32*)end) == 0)
    {
        *(f32*)((u8*)work + 0x00) = start->x;
        *(f32*)((u8*)work + 0x04) = start->y;
        *(f32*)((u8*)work + 0x08) = end->x;
        *(f32*)((u8*)work + 0x0c) = end->y;
        *(u16*)((u8*)work + 0x400) = 2;
        *(u8*)((u8*)work + 0x404) = 2;
        return 1;
    }
    *(u16*)((u8*)work + 0x400) = 0;

    *(f32*)(iGpffffb6fc + 0x798) = start->x;
    *(f32*)(iGpffffb6fc + 0x79c) = start->y;
    *(f32*)(iGpffffb6fc + 0x8c8) = end->x;
    *(f32*)(iGpffffb6fc + 0x8cc) = end->y;
    FUN_002d32b0(radius);
    if (*(u32*)(iGpffffb6fc + 0x7c0) == 0 ||
        *(u32*)(iGpffffb6fc + 0x8f0) == 0)
    {
        *(u8*)((u8*)work + 0x404) = 3;
        return 0;
    }

    *(u32*)(iGpffffb6fc + 0x9f0) = 0;
    *(u32*)(iGpffffb6fc + 0x9f4) = 0;
    *(u32*)(iGpffffb6fc + 0x7ac) = 0;
    delta.x = *(f32*)(iGpffffb6fc + 0x798) -
              *(f32*)(iGpffffb6fc + 0x8c8);
    delta.y = *(f32*)(iGpffffb6fc + 0x79c) -
              *(f32*)(iGpffffb6fc + 0x8cc);
    *(f32*)(iGpffffb6fc + 0x7b0) = FUN_004c6af0((f32*)&delta);
    *(u32*)(iGpffffb6fc + 0x7bc) = 0;
    *(u32*)(iGpffffb6fc + 0x7b4) = *(u32*)(iGpffffb6fc + 0x9f0);
    *(u32*)(iGpffffb6fc + 0x9f0) = (u32)(iGpffffb6fc + 0x790);

    result = 0;
    for (;;)
    {
        selected = (u8*)FUN_002d4810();
        if (selected == iGpffffb6fc + 0x8c0)
        {
            result = 1;
            break;
        }

        index = 0;
        while (*(u8**)(selected + 0x30 + index * 4) != NULL)
        {
            score = *(f32*)(selected + 0x1c) +
                    *(f32*)(selected + 0xb0 + index * 4);
            slot = selected + 0x30 + index * 4;
            record = *(u8**)slot;
            inFirst = 0;
            for (current = *(u8**)(iGpffffb6fc + 0x9f0);
                 current != NULL;
                 current = *(u8**)(current + 0x24))
            {
                if (current == record)
                {
                    inFirst = 1;
                    break;
                }
            }
            inSecond = 0;
            for (current = *(u8**)(iGpffffb6fc + 0x9f4);
                 current != NULL;
                 current = *(u8**)(current + 0x28))
            {
                if (current == record)
                {
                    inSecond = 1;
                    break;
                }
            }
            if ((inFirst == 0 && inSecond == 0) ||
                *(f32*)(selected + 0x1c) > score)
            {
                *(f32*)(record + 0x1c) = score;
                *(f32*)(record + 0x20) = score;
                delta.x = *(f32*)(record + 0x08) -
                          *(f32*)(iGpffffb6fc + 0x8c8);
                delta.y = *(f32*)(record + 0x0c) -
                          *(f32*)(iGpffffb6fc + 0x8cc);
                *(f32*)(record + 0x20) +=
                    FUN_004c6af0((f32*)&delta);
                *(u8**)(record + 0x2c) = selected;
                if (inSecond != 0)
                {
                    previous = NULL;
                    current = *(u8**)(iGpffffb6fc + 0x9f4);
                    while (current != NULL)
                    {
                        if (current == record)
                        {
                            break;
                        }
                        previous = current;
                        current = *(u8**)(current + 0x28);
                    }
                    if (current != NULL)
                    {
                        if (previous != NULL)
                            *(u8**)(previous + 0x28) =
                                *(u8**)(current + 0x28);
                        else
                            *(u8**)(iGpffffb6fc + 0x9f4) =
                                *(u8**)(current + 0x28);
                    }
                }
                if (inFirst == 0)
                {
                    *(u8**)(record + 0x24) =
                        *(u8**)(iGpffffb6fc + 0x9f0);
                    *(u8**)(iGpffffb6fc + 0x9f0) = record;
                }
            }
            index++;
        }
        if (*(u8**)(selected + 0x30 + index * 4) == NULL)
        {
            *(u8**)(selected + 0x28) =
                *(u8**)(iGpffffb6fc + 0x9f4);
            *(u8**)(iGpffffb6fc + 0x9f4) = selected;
        }
        if (*(u8**)(iGpffffb6fc + 0x9f0) == NULL)
            break;
    }
    if (result != 0)
    {
        FUN_002d41c0(work, radius);
        *(u8*)((u8*)work + 0x404) = 2;
    }
    else
    {
        *(u8*)((u8*)work + 0x404) = 3;
    }
    return result;
}

// FUN_002d4cc0
u32 FUN_002d4cc0(u16 index)
{
    u32 value = *((u8*)iGpffffb6fc + index * 0x1c);

    if (value == 0)
    {
        return 1;
    }
    return value;
}

// FUN_002d4cf0
u16 FUN_002d4cf0(u16 mask, u32 badStatus)
{
    u8* node;
    u32 total;
    u16 count;
    u32 targetMask;
    u16 average;

    total = 0;
    count = 0;
    node = *(u8**)(iGpffffb6fc + 0x14c);
    targetMask = mask;
    for (; node != NULL;
         node = *(u8**)(node + 0x4a8))
    {
        BtlUnit* unit;

        if ((*(u16*)(node + 0x1a) & 1) == 0)
        {
            continue;
        }
        unit = *(BtlUnit**)(node + 0x30);
        if ((targetMask & (1u << unit->genus)) == 0)
        {
            continue;
        }
        if (badStatus != 0 &&
            datCalcChkBadStatus(unit->datUnit, badStatus) != 0)
        {
            continue;
        }
        total = (u16)(total + datCalcGetLevel(unit->datUnit));
        count++;
    }
    if (count == 0)
    {
        return 1;
    }
    average = (u16)((s32)(u16)total / (s32)(u16)count);
    if (average == 0)
    {
        return 1;
    }
    return average;
}

// FUN_002d4e10
u16 FUN_002d4e10(u16 mask, u32 badStatus)
{
    u32 status;
    u8* node;
    u16 count;
    u32 targetMask;

    status = badStatus;
    count = 0;
    node = *(u8**)(iGpffffb6fc + 0x14c);
    targetMask = mask;
    for (; node != NULL;
         node = *(u8**)(node + 0x4a8))
    {
        BtlUnit* unit;
        u16 flags = *(u16*)(node + 0x1a);

        if ((flags & 1) == 0)
        {
            continue;
        }
        if ((flags & 8) == 0)
        {
            continue;
        }
        unit = *(BtlUnit**)(node + 0x30);
        if ((targetMask & (1u << unit->genus)) == 0)
        {
            continue;
        }
        if (datCalcChkBadStatus(unit->datUnit, status) != 0)
        {
            continue;
        }
        count++;
    }
    return count;
}

// FUN_002d4ed0
u32 FUN_002d4ed0(s32 param_1)
{
    BtlEncountTable* encount;
    u16 encountId;
    u16 chance;

    encountId = gBtl->startInfo.enmUnits->encountId;
    encount = &gEncountTbl[encountId];
    switch (encountId)
    {
    case 0x1d4:
        return 1;
    case 0x1d5:
        {
            s32 count = FUN_001756f0() & 0xffff;
            s32 i;

            for (i = 0; i < count; i++)
            {
                DatPersonaWork* persona = datPersonaGetHeroPersona(i);
                if (persona->id == 0x4c)
                {
                    break;
                }
            }
            if (i == count)
            {
                return 1;
            }
            return 0;
        }
    }
    {
        u16 startValue = *(u16*)((u8*)gBtl + 0xb9a);
        u16 index;

        if (startValue == 0)
        {
            return 0;
        }
        if ((*(u32*)encount & 2) != 0)
        {
            return 0;
        }
        if ((*(u32*)encount & 4) != 0)
        {
            return 1;
        }
        if ((u32)(uintptr_t)gBtl->actionList.head == (u32)param_1)
        {
            return 1;
        }
        chance = 0;
        if (startValue > 0)
        {
            index = startValue - 1;
            if (index >= 9)
            {
                index = 8;
            }
            chance += DAT_007ce488[index];
        }
    }
    {
        u16 startValue = *(u16*)((u8*)gBtl + 0xb9c);
        u16 index;

        if (startValue > 0)
        {
            index = startValue - 1;
            if (index >= 6)
            {
                index = 5;
            }
            chance += DAT_007ce488[index + 9];
        }
    }
    if (datCalcRand(100) < chance)
    {
        return 1;
    }
    return 0;
}

// FUN_002d50c0 NONMATCHING
u16 FUN_002d50c0(void)
{
    u16 encountId = gBtl->startInfo.enmUnits->encountId;
    u16 value1;
    u16 value2;
    u16 chance;
    u32 hasSpecialSkill = 0;
    BtlUnit* unit;

    if (encountId == 0x1fa && datGetFlag(0x1319) != 0)
    {
        return 2;
    }

    {
        u32 encountFlags = *(u32*)((u8*)gEncountTbl + (u32)encountId * 0x1c);
        if ((encountFlags & 8) != 0)
        {
            return 0;
        }
        if ((encountFlags & 0x10) != 0)
        {
            return 2;
        }
        if ((encountFlags & 0x800) != 0)
        {
            return 1;
        }
    }

    if ((*(u16*)(iGpffffb6fc + 0xba8) & 4) != 0)
    {
        return 0;
    }

    for (unit = gBtl->unitLists[UNIT_GENUS_PC].head;
         unit != NULL;
         unit = unit->next)
    {
        if (unit->datUnit != NULL && datCalcHasSkill(unit->datUnit, 0x230) != 0)
        {
            hasSpecialSkill = 1;
            break;
        }
    }

    value1 = (u16)FUN_002d4cf0(1, 0);
    value2 = (u16)FUN_002d4cf0(2, 0);

    if ((*(u16*)(iGpffffb6fc + 0xba8) & 1) == 0)
    {
        if ((*(u16*)(iGpffffb6fc + 0xba8) & 2) == 0)
        {
            return 1;
        }
        if (datGetFlag(0x1319) == 0 || ((*(u16*)(iGpffffb6fc + 0xba8) & 8) != 0))
        {
            return 0;
        }

        chance = (u16)(((f32)value2 / (f32)value1) * 20.0f);
        return datCalcRand(100) < chance ? 2 : 0;
    }

    chance = (u16)(((f32)value1 / (f32)value2) * 20.0f);
    if (hasSpecialSkill != 0)
    {
        chance = (u16)((f32)chance * 0.5f);
    }
    if (datGetFlag(0x1319) != 0)
    {
        return 2;
    }
    return datCalcRand(100) < chance ? 2 : 0;
}

// FUN_002d5550
u16 FUN_002d5550(void)
{
    return gBtl->startInfo.enmUnits->encountId;
}

/* Caveats:
 * - iGpffffb6fc, fGpffff827c, and DAT_006978c0 are raw retail globals; no stable named API was established.
 * - FUN_002d2470, FUN_002d25c0, and FUN_004C6B20 are raw helper declarations; FUN_004C6B20 is the retail 2-D normalize helper.
 */
// FUN_002d5570
s32 FUN_002d5570(s32 param_1)
{
    s16 result;

    if (param_1 < 0x110 || param_1 > 0x130)
    {
        return -1;
    }
    result = -1;
    switch (param_1)
    {
    case 0x115:
        goto random8;
    default:
        break;
    }
    switch (param_1)
    {
    case 0x112:
        goto random100;
    default:
        goto done;
    }
random100:
    if ((s32)datCalcRand(100) < 5)
    {
        result = 0x122;
    }
    goto done;
random8:
    switch (datCalcRand(8))
    {
        case 0: return 0x100;
        case 1: return 0x101;
        case 2: return 0x102;
        case 3: return 0x103;
        case 4: return 0x104;
        case 5: return 0x105;
        case 6: return 0x106;
        case 7: return 0x109;
    }
done:
    return result;
}

// FUN_002d56a0
u32 FUN_002d56a0(s32 param_1)
{
    switch (param_1)
    {
        case 0xd6:
        case 0xd7:  return 0x48;
        case 0xd8:
        case 0xd9:  return 0x4a;
        case 0xda:
        case 0xdb:  return 0x4c;
        case 0xdf:  return 0x9a;
        case 0xce:
        case 0xcf:  return 0x8a;
        case 0xd0:
        case 0xd1:  return 0x8c;
        case 0xd2:
        case 0xd3:  return 0x8e;
        case 0xd4:  return 0x9c;
        case 0xe2:  return 0x4e;
        case 0xe3:  return 0x50;
        case 0xdc:  return 0x9e;
        case 0xdd:  return 0xa0;
        case 0x49:
        case 0x4a:  return 0x52;
        case 0x113: return 0x54;
        case 0x114: return 0x56;
        case 0x117: return 0x58;
        case 0xe5:  return 0xa6;
        case 0xe6:  return 0xa8;
        case 0xe7:  return 0xac;
        case 0xe8:  return 0xaa;
        case 0x100: return 0x64;
        case 0x101: return 0x66;
        case 0x102: return 0x68;
        case 0x103: return 0x6a;
        case 0x104: return 0x6c;
        case 0x105: return 0x6e;
        case 0x106: return 0x70;
        case 0x107: return 0x72;
        case 0x108: return 0x74;
        case 0x109: return 0x76;
        case 0x10a: return 0x7a;
        case 0x10b: return 0x7c;
        case 0x10c: return 0x7e;
        case 0x10d: return 0x80;
        case 0x10e: return 0x82;
        case 0x120: return 0xae;
        case 0x122: return 0x84;
        case 0x134: return 0x86;
        case 0x170: return 0xa4;
        case 0x66:
        case 0x67:  return 0x44;
        case 0x147: return 0x90;
        case 0x148: return 0x92;
        case 0x149: return 0x94;
        case 0x14a: return 0x96;
        case 0x14b: return 0x98;
        default:    return 0;
    }
}

// FUN_002d5b50
s32 FUN_002d5b50(s32 param_1)
{
    s32 result;

    if (param_1 == 0x14b) goto return_13;
    if (param_1 == 0x14a) goto return_12;
    if (param_1 == 0x149) goto return_12;
    if (param_1 == 0x148) goto return_12;

    switch (param_1)
    {
    case 0x147:
        goto return_12;
    default:
        goto return_default;
    }

return_12:
    result = 0xc;
    goto end;
return_13:
    result = 0xd;
    goto end;
return_default:
    result = -1;
    goto end;
end:
    return result;
}

// FUN_002d5bc0
s32 FUN_002d5bc0(void)
{
    return (s32)datCalcRand(5) + 0x147;
}

// FUN_002d5bf0
u32 FUN_002d5bf0(BtlUnit* unit)
{
    if (datGetScenarioMode() == 0)
    {
        return 0;
    }
    if (unit->datUnit == NULL)
    {
        return 0;
    }
    if (unit->datUnit->id != 1)
    {
        return 0;
    }
    return unit->genus == 0;
}

// FUN_002d5c70
u32 FUN_002d5c70(BtlUnit* unit)
{
    if (datGetScenarioMode() == 0)
    {
        return 0;
    }
    if (unit->datUnit == NULL)
    {
        return 0;
    }
    if (unit->datUnit->id != 9)
    {
        return 0;
    }
    return unit->genus == 0;
}

// FUN_002d5cf0
u32 FUN_002d5cf0(BtlUnit* unit)
{
    s16 equipmentIdx;
    u16 equipmentType;
    s16 equipmentId;

    if (unit->genus != 0)
    {
        return 0;
    }
    if (unit->datUnit == NULL)
    {
        return 0;
    }

    equipmentType = unit->datUnit->id;
    switch (equipmentType)
    {
        case 2:
        case 4:
            break;
        default:
            goto return_zero;
    }

    equipmentIdx = datGetEquipmentIdx((s16)equipmentType, 1);
    equipmentId =
        datGetEquipmentId((s16)unit->datUnit->id, equipmentIdx);
    if (equipmentId != 0x41e)
    {
        goto return_zero;
    }
    return 1;

return_zero:
    return 0;
}

// FUN_002d5dc0
void FUN_002d5dc0(void* param_1)
{
    memset(param_1, 0, 0x1c);
    ((s8*)param_1)[0x19] = -1;
}

// FUN_002d5e00
void FUN_002d5e00(void* param_1)
{
    *(u16*)((u8*)param_1 + 0x14) = 0;
}

#pragma opt_loop_invariants on
// FUN_002d5e10
u32 FUN_002d5e10(BtlAction* action)
{
    BtlAction* target;
    s32 targetCount;
    s32 resultCount;
    s32 targetIndex;
    s32 resultIndex;

    targetIndex = 0;
    targetCount = action->target.targetedCount;
    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        target = action->target.targetedActions[(u16)targetIndex];
        resultIndex = 0;
        resultCount = *(u8*)((u8*)target + 0xc8);
        for (; (u16)resultIndex < resultCount;
             resultIndex = (u16)(resultIndex + 1))
        {
            u8* result = (u8*)target + ((u32)resultIndex & 0xffff) * 0x1c;
            if ((*(u16*)(result + 0xfa) & 4) != 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

#pragma opt_loop_invariants off

/* Removing this loses FUN_002d5eb0 (MATCH nd0 -> MISMATCH nd66) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002d5eb0
u32 FUN_002d5eb0(BtlAction* action)
{
    BtlAction* target;
    s32 targetCount;
    s32 resultCount;
    u32 statusMask;
    s32 targetIndex;
    s32 resultIndex;

    targetIndex = 0;
    targetCount = action->target.targetedCount;
    statusMask = 0x100000;
    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        target = action->target.targetedActions[(u16)targetIndex];
        resultIndex = 0;
        resultCount = *(u8*)((u8*)target + 0xc8);
        for (; (u16)resultIndex < resultCount;
             resultIndex = (u16)(resultIndex + 1))
        {
            u8* result = (u8*)target + ((u32)resultIndex & 0xffff) * 0x1c;
            if ((*(u32*)(result + 0xe8) & statusMask) != 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

#pragma opt_loop_invariants off

/* Removing this loses FUN_002d5f50 (MATCH nd0 -> MISMATCH nd1) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002d5f50
u32 FUN_002d5f50(BtlAction* action)
{
    s32 targetIndex = 0;
    s32 targetCount = action->target.targetedCount;

    while ((u16)targetIndex < targetCount)
    {
        BtlAction* target = action->target.targetedActions[(u16)targetIndex];
        if (*(s32*)((u8*)target + 0xd4) != 0)
        {
            return 1;
        }
        targetIndex = (u16)(targetIndex + 1);
    }
    return 0;
}

#pragma opt_loop_invariants off

/* Removing this loses FUN_002d5fb0 (MATCH nd0 -> MISMATCH nd156) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002d5fb0
s32 FUN_002d5fb0(BtlAction* action)
{
    BtlAction* target;
    s32 resultCount;
    s32 resultIndex;
    s32 result = 0;
    s32 targetIndex = 0;
    s32 targetCount = action->target.targetedCount;
    s32 one = 1;
    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        target = action->target.targetedActions[(u16)targetIndex];
        if (target != action)
        {
            if (action->unit->genus != target->unit->genus)
            {
                return 0;
            }
            if (result == 0)
            {
                resultIndex = 0;
                resultCount = *(u8*)((u8*)target + 0xc8);
                for (; (u16)resultIndex < resultCount;
                     resultIndex = (u16)(resultIndex + 1))
                {
                    u8* resultData =
                        (u8*)target + ((u32)resultIndex & 0xffff) * 0x1c;
                    if (*(s32*)(resultData + 0xe0) > 0)
                    {
                        result = one;
                    }
                    if (*(s32*)(resultData + 0xec) != 0)
                    {
                        result = one;
                    }
                }
            }
        }
    }
    return result;
}

#pragma opt_loop_invariants off

/* Removing this loses FUN_002d6090 (MATCH nd0 -> MISMATCH nd66) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002d6090
u32 FUN_002d6090(BtlAction* action)
{
    BtlAction* target;
    s32 targetCount;
    s32 resultCount;
    u32 statusMask;
    s32 targetIndex;
    s32 resultIndex;

    targetIndex = 0;
    targetCount = action->target.targetedCount;
    statusMask = 0x80000;
    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        target = action->target.targetedActions[(u16)targetIndex];
        resultIndex = 0;
        resultCount = *(u8*)((u8*)target + 0xc8);
        for (; (u16)resultIndex < resultCount;
             resultIndex = (u16)(resultIndex + 1))
        {
            u8* result = (u8*)target + ((u32)resultIndex & 0xffff) * 0x1c;
            if ((*(u32*)(result + 0xec) & statusMask) != 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

#pragma opt_loop_invariants off

/* Removing this loses FUN_002d6130 (MATCH nd0 -> MISMATCH nd159) - measured W161. */
#pragma opt_loop_invariants on
// FUN_002d6130
s32 FUN_002d6130(BtlAction* action)
{
    BtlAction* target;
    s32 resultCount;
    s32 resultIndex;
    s32 result = 0;
    s32 targetIndex = 0;
    s32 targetCount = action->target.targetedCount;
    s32 one = 1;

    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        target = action->target.targetedActions[(u16)targetIndex];
        if (*(s32*)((u8*)target + 0xd4) != 0)
        {
            return 0;
        }
        if ((*(u16*)((u8*)target + 0xcc) & 0x500) != 0)
        {
            return 0;
        }
        if (result == 0)
        {
            resultCount = *(u8*)((u8*)target + 0xc8);
            resultIndex = 0;
            for (; (u16)resultIndex < resultCount;
                 resultIndex = (u16)(resultIndex + 1))
            {
                u8* resultData =
                    (u8*)target + ((u32)resultIndex & 0xffff) * 0x1c;
                if (*(s32*)(resultData + 0xe0) < 0)
                {
                    result = one;
                    break;
                }
            }
        }
    }
    return result;
}

#pragma opt_loop_invariants off

// FUN_002d6210
u32 FUN_002d6210(BtlAction* action)
{
    BtlAction* target;
    s32 targetCount;
    s32 targetIndex;

    targetIndex = 0;
    targetCount = action->target.targetedCount;
    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        target = *(BtlAction **)((u8 *)action + 0x38 + (u32)(u16)targetIndex * 4);
        if (*(s32*)((u8*)target + 0xd4) != 0)
        {
            return 1;
        }
        if ((*(u16*)((u8*)target + 0xcc) & 0x500) != 0)
        {
            return 1;
        }
    }
    return 0;
}

// FUN_002d6290
u32 FUN_002d6290(BtlAction* action)
{
    s16 specificId = action->target.specificId;
    return FUN_002bff60(action, NULL, specificId, 0) == 0;
}

// FUN_002d62d0
u32 FUN_002d62d0(BtlAction* action)
{
    s32 genus = action->unit->genus;
    s32 targetCount = action->target.targetedCount;
    s32 targetIndex;

    if (targetCount < 2)
    {
        return 0;
    }

    targetIndex = 0;
    genus = (u8)genus;
    for (; (u16)targetIndex < targetCount;
         targetIndex = (u16)(targetIndex + 1))
    {
        BtlAction* target = *(BtlAction **)((u8 *)action + 0x38 + (u32)(u16)targetIndex * 4);
        if ((target->unk_1a & 1) != 0 && target->unit->genus != genus)
        {
            return 0;
        }
    }
    return 1;
}

/* Removing this loses FUN_002d5e10 (MATCH nd0 -> MISMATCH nd1) - measured W161. */
// FUN_002d6370
u32 FUN_002d6370(u16 commandId)
{
    u8* units = (u8*)DAT_007ce3f8;
    s32 id = (s32)(s16)commandId;
    return units[id * 0x2c + 2] == 1;
}
// FUN_002d63b0
u32 FUN_002d63b0(BtlUnit* unit, s16 commandId, s32 param_3)
{
    u8* commandTable = (u8*)DAT_007ce3f8;
    s32 id = (s32)commandId;
    u8 commandType;
    s32 result;

    commandType = commandTable[id * 0x2c + 2];
    if (commandType != 1)
    {
        result = 0;
    }
    else
    {
        result = 1;
        if (param_3 == 0 ||
            ((*(u16*)(DAT_007ce42c + (u32)unit->charId * 0x58) & 0x10) != 0) ||
            ((iGpffffb710[id].flags & 1) == 0))
        {
            result = 0;
        }
    }
    return result;
}
// FUN_002d6460
s32 FUN_002d6460(BtlAction* action, s32* param_2, u32 param_3,
                 u64 param_4, s32 param_5)
{
    s32 result = -1;
    u32 flags = (u32)param_2[2];
    u32 mode;

    if (flags != 0 || ((u32)param_2[4] & 0x3c02aaU) != 0)
    {
        result = -2;
    }

    if ((flags & 0x100000U) != 0)
    {
        result = 8;
    }
    else if (param_2[0] < 0 || (flags & 0x80000U) != 0)
    {
        result = 2;
    }
    else if (((u32)param_2[3] & 0x100000U) != 0)
    {
        result = 10;
    }
    mode = param_3 & 0xffff;

    switch (mode)
    {
    case 4:
    case 2:
        result = (s8)((action->unit->flags3 & 0x80U) != 0 ? 0x16 : -4);
        break;
    default:
        break;
    }
    if ((*(u16*)((u8*)param_2 + 0x1a) & 4) != 0)
    {
        result = (s8)((action->unit->flags3 & 0x80U) != 0 ? 0x16 : -3);
    }
    if (param_5 != 0)
    {
        result = (s8)((action->unit->flags3 & 0x20U) != 0 ? 0x12 : 2);
    }
    if ((((u32)param_2[3] & 0x80000U) != 0) &&
        datCalcChkBadStatus(action->unit->datUnit, UNIT_BADSTATUS_DEAD) != 0 &&
        (action->unit->flags3 & 0x200U) != 0)
    {
        result = 0x13;
    }
    return result;
}
// FUN_002d6620 NONMATCHING
void FUN_002d6620(BtlAction *action)
{
    volatile /* Removing this qualifier worsens FUN_002d6620 (NONMATCHING nd2980 -> NONMATCHING nd3061, size 3880 -> 3868) - measured W170. */ u16 inherited = 0;
    DatUnit *selfDat;
    u16 specificId;
    s32 mappedId;
    u32 id;
    u32 tableOffset;
    u8 attackType;
    u8 datType;
    u32 specialFlags = 0;
    u16 successfulTargets;
    u8 finalFlags;
    u16 targetIndex;

    specificId = action->target.specificId;
    action->target.originalSpecificId = action->target.specificId;
    mappedId = FUN_002d5570(specificId);
    if (mappedId != -1)
    {
        id = (u32)mappedId & 0xffff;
        action->target.specificId = (u16)mappedId;
        FUN_002c3770(action, 0);
    }
    else
    {
        id = specificId;
    }

    if (action->target.commandId == 3)
        specialFlags |= 1;

    tableOffset = id * 0x2c;
    attackType = BTLT_T8(tableOffset, 0x11);
    selfDat = action->unit->datUnit;
    *(u16 *)((u8 *)selfDat + 0x38) = 0;
    if ((action->target.commandId == 3) && (action->target.unk_38 > 0))
        specialFlags |= 1;
    datType = (u8)FUN_003082f0(selfDat, id);

    BTLT_A8(action, 0xc8) = 0;
    BTLT_A16(action, 0xcc) = 0;
    BTLT_A32(action, 0xd0) = 0;
    BTLT_A32(action, 0xd4) = 0;
    BTLT_A8(action, 0xca) = 0;
    BTLT_A8(action, 0xc9) = 0;
    BTLT_A32(action, 0xd8) = 0;
    BTLT_A16(action, 0xdc) = 0;
    BTLT_AS16(action, 0xde) = -1;

    if ((specialFlags == 0) && (FUN_003088b0(id) == 0))
    {
        u32 tacticResult = FUN_003086f0(selfDat, id);
        if (tacticResult == 2)
        {
            BTLT_A32(action, 0xd8) = 1;
            BTLT_A16(action, 0xdc) = action->unit->genus == 0 ? 0x3c : 0x3d;
        }
        else if (tacticResult == 1)
        {
            BTLT_A32(action, 0xd8) = 1;
            BTLT_A16(action, 0xdc) = action->unit->genus == 0 ? 0x3a : 0x3b;
        }
        if ((action->unit->genus == 1) && (datCalcChkBadStatus(selfDat, 4) != 0))
        {
            BTLT_A32(action, 0xd8) = 1;
            BTLT_A16(action, 0xdc) = action->unit->genus == 0 ? 0x3e : 0x3f;
        }
    }

    if (BTLT_A32(action, 0xd8) == 1)
    {
        BTLT_A8(action, 0xca) = 0;
    }
    else
    {
        u16 targetCount = action->target.targetedCount;
        successfulTargets = 0;
        finalFlags = 0;
        if (targetCount > 1)
        {
            u16 index = 0;
            while ((index < targetCount) && (action->target.targetedActions[index] != action))
                index++;
            if (index != targetCount)
            {
                for (; index < (u16)(targetCount - 1); index++)
                    action->target.targetedActions[index] = action->target.targetedActions[index + 1];
                action->target.targetedActions[index] = action;
            }
        }

        for (targetIndex = 0; targetIndex < targetCount; targetIndex++)
        {
            BtlAction *target = action->target.targetedActions[targetIndex];
            DatUnit *targetDat = target->unit->datUnit;
            DatUnit *candidateDat = targetDat;
            BtlAction *candidateAction = target;
            u16 efficacy;
            u8 slotCount;
            u8 chance;
            u8 slotIndex;
            u32 weaponType;
            f32 scale = 1.0f;
            s32 total = 0;
            s32 resultA;
            s32 resultB;
            u32 slotStatus;
            u32 slotOtherStatus;
            u32 baseValue;
            u32 targetSpecial;
            u8 terminate;

            *(u16 *)((u8 *)targetDat + 0x38) = 0;
            BTLT_A8(target, 0xc8) = 0;
            BTLT_A16(target, 0xcc) = 0;
            BTLT_A32(target, 0xd0) = 0;
            BTLT_A32(target, 0xd4) = 0;
            BTLT_A8(target, 0xca) = 0;
            BTLT_A8(target, 0xc9) = 0;
            BTLT_A32(target, 0xd8) = 0;
            BTLT_A16(target, 0xdc) = 0;
            BTLT_AS16(target, 0xde) = -1;

            efficacy = (u16)FUN_00309490(selfDat, targetDat, id, specialFlags);
            if (efficacy == 0x200)
            {
                efficacy = (u16)FUN_00309490(selfDat, selfDat, id, specialFlags | 2);
                if ((efficacy == 4) || (efficacy == 2))
                    efficacy = 1;
                else if (efficacy == 0x200)
                    efficacy = 0x100;
                BTLT_A32(target, 0xd4) = 1;
                candidateDat = selfDat;
                candidateAction = action;
            }

            if (BTLT_A32(target, 0xd4) == 0)
                targetSpecial = (u16)FUN_0030a740(selfDat, candidateDat, id, efficacy, specialFlags);
            else
                targetSpecial = ((s8)FUN_00301750(targetDat, 0xb) < 1) ? 1 : 0x10;

            if (FUN_003088b0(id) == 0)
            {
                slotCount = (u8)FUN_0030b9a0(selfDat, id, targetSpecial);
                chance = 1;
            }
            else
            {
                slotCount = 1;
                weaponType = (u32)FUN_00308c60(selfDat) & 0xff;
                chance = (u8)FUN_00308fd0(selfDat, targetSpecial);
                scale = (f32)DAT_007ce484[(weaponType & 0xff) * 3 + (u32)chance - 1] / 100.0f;
            }

            if ((BTLT_A32(target, 0xd4) == 0) &&
                ((efficacy == 0x100) || (efficacy == 4) || (efficacy == 2) ||
                 (efficacy == 0x400) || (efficacy == 0x200)))
            {
                slotCount = 1;
                chance = 1;
            }
            else if (BTLT_A32(target, 0xd4) != 0)
            {
                slotCount = 1;
                chance = 1;
            }

            if (BTLT_A32(target, 0xd4) == 0)
            {
                resultA = (s32)FUN_0030b130(selfDat, candidateDat, id, efficacy, targetSpecial, specialFlags);
                resultB = (s32)FUN_0030b210(selfDat, targetDat, id, efficacy, targetSpecial, specialFlags);
                if ((resultA != 1) && (resultB != 1))
                    resultA = (s32)FUN_002fd220(action, target);
            }
            else
            {
                resultA = 0;
                resultB = 0;
            }

            slotStatus = (u32)FUN_00306020(id, selfDat, candidateDat, efficacy, targetSpecial, specialFlags);
            slotOtherStatus = (u32)FUN_00306510(id, selfDat, candidateDat, efficacy, targetSpecial, specialFlags);
            if ((BTLT_T8(tableOffset, 0x18) == 1) &&
                ((BTLT_T32(tableOffset, 0x1c) & 0x80000) != 0) &&
                ((slotStatus & 0x80000) == 0))
                resultA = 0;
            if ((BTLT_A32(target, 0xd4) != 0) ||
                ((BTLT_D16(selfDat, 0) & 4) == (BTLT_D16(candidateDat, 0) & 4)))
                slotStatus &= 0xffffff9f;
            if (slotStatus == 0x80000)
                BTLT_A32(target, 0xd0) = 1;

            if ((efficacy == 1) && (BTLT_A32(target, 0xd4) == 0) &&
                ((s16)func_002e4910(target, id, specialFlags) == 0))
                baseValue = BTLT_T32(tableOffset, 0x20);
            else
                baseValue = 0;

            BTLT_A16(target, 0xcc) = efficacy;
            BTLT_A16(target, 0xce) = (u16)targetSpecial;
            if ((BTLT_A32(target, 0xd4) == 1) || ((efficacy & 0x500) != 0))
                func_002e32a0(action, target, id);

            for (slotIndex = 0; slotIndex < slotCount; slotIndex++)
            {
                u32 slotOffset = (u32)slotIndex * 0x1c;
                u8 *slotPtr = (u8 *)target + slotOffset;
                s32 amountA;
                s32 amountB;
                u8 callbackResult;

                *(u16 *)(slotPtr + 0xfa) = 0;
                *(u16 *)(slotPtr + 0xf4) = 0;
                *(u16 *)(slotPtr + 0xf6) = 0;
                amountA = (s32)FUN_00303130(id, selfDat, candidateDat, 1, efficacy, targetSpecial, specialFlags, 1);
                amountB = (s32)FUN_00303130(id, selfDat, candidateDat, 1, efficacy, targetSpecial, specialFlags, 2);
                amountA = (s32)((f32)amountA * scale);
                *(u32 *)(slotPtr + 0xe8) = slotStatus;
                *(u32 *)(slotPtr + 0xec) = slotOtherStatus;
                if ((attackType == 0xd) || (attackType == 0xc))
                    *(u16 *)(slotPtr + 0xf4) = (u16)FUN_0051e0e0(amountA);
                if ((BTLT_T8(tableOffset, 0x14) == 0xd) || (BTLT_T8(tableOffset, 0x14) == 0xc))
                    *(u16 *)(slotPtr + 0xf6) = (u16)FUN_0051e0e0(amountB);
                *(u32 *)(slotPtr + 0xf0) = baseValue;
                *(u8 *)(slotPtr + 0xf9) = datType;
                *(s32 *)(slotPtr + 0xe0) = amountA;
                *(s32 *)(slotPtr + 0xe4) = amountB;
                total += amountA;

                if (BTLT_T8(tableOffset, 0x24) == 9)
                    *(u16 *)(slotPtr + 0xfa) |= 0x80;
                else if (BTLT_T8(tableOffset, 0x24) == 6)
                    *(u16 *)(slotPtr + 0xfa) |= 0x20;
                if (id == 0x126)
                    *(u16 *)(slotPtr + 0xfa) |= 0x200;
                else if ((id == 0x128) || (id == 0x127) || (id == 0x125))
                    *(u16 *)(slotPtr + 0xfa) |= 0x100;
                if ((BTLT_T8(tableOffset, 0) & 1) != 0)
                    *(u16 *)(slotPtr + 0xfa) |= 0x40;
                if (attackType == 0x10)
                    *(u16 *)(slotPtr + 0xfa) |= 8;

                terminate = (datCalcIsDead(candidateDat, total) != 0);
                if ((terminate == 0) && ((slotStatus & 0x80000) != 0))
                    terminate = ((slotOtherStatus & 0x80000) == 0);
                if (((slotIndex + 1) == slotCount) || (terminate != 0))
                {
                    if (resultA != 0)
                    {
                        *(u32 *)(slotPtr + 0xe8) |= 0x100000;
                    }
                    else
                    {
                        u8 forceFlag = 0;
                        if (((total < 0) || (efficacy == 0x100) || (efficacy == 0x400)) &&
                            (datCalcChkBadStatus(candidateDat, 0x100000) != 0))
                            forceFlag = 1;
                        if ((BTLT_A32(target, 0xd4) == 1) &&
                            (datCalcChkBadStatus(targetDat, 0x100000) != 0))
                            forceFlag = 1;
                        if (forceFlag != 0)
                        {
                            *(u16 *)(slotPtr + 0xfa) |= 1;
                            if ((BTLT_A32(target, 0xd4) == 1) ||
                                (efficacy == 0x100) || (efficacy == 0x400))
                                *(u16 *)(slotPtr + 0xfa) |= 2;
                        }
                    }
                    if (resultB != 0)
                        *(u16 *)(slotPtr + 0xfa) |= 4;
                    if ((efficacy != 1) || (BTLT_A32(target, 0xd4) == 1) || (resultB == 1))
                        finalFlags |= 2;
                    else if (resultA != 0)
                        successfulTargets++;
                }

                if (terminate != 0)
                {
                    s16 hpDelta = (s16)FUN_0030b640(candidateAction->unit->datUnit, id);
                    if (hpDelta >= 0)
                    {
                        BTLT_AS16(target, 0x460) = hpDelta;
                        *(u16 *)(slotPtr + 0xfa) |= 0x10;
                        callbackResult = (u8)FUN_002d6460(candidateAction, (int *)(slotPtr + 0xe0), efficacy, targetSpecial, 0);
                        BTLT_A8(target, 0xf8 + slotOffset) = callbackResult;
                    }
                    else
                    {
                        callbackResult = (u8)FUN_002d6460(candidateAction, (int *)(slotPtr + 0xe0), efficacy, targetSpecial, 1);
                        BTLT_A32(target, 0xd0) = 1;
                        BTLT_A8(target, 0xf8 + slotOffset) = callbackResult;
                        if (action == candidateAction)
                            *(u16 *)(slotPtr + 0xf4) = 0;
                    }
                    slotCount = (u8)(slotIndex + 1);
                    break;
                }

                callbackResult = (u8)FUN_002d6460(candidateAction, (int *)(slotPtr + 0xe0), efficacy, targetSpecial, 0);
                BTLT_A8(target, 0xf8 + slotOffset) = callbackResult;
            }

            {
                u16 targetValue = BTLT_D16(selfDat, 0x38);
                if (targetValue == 0)
                    targetValue = BTLT_D16(targetDat, 0x38);
                inherited = targetValue;
            }
            {
                s16 overrideValue = (s16)FUN_002d56a0(id);
                if (overrideValue != 0)
                    BTLT_AS16(target, 0xdc) = overrideValue;
                else if (inherited != 0)
                    BTLT_A16(target, 0xdc) = inherited;
            }
            BTLT_A8(target, 0xc8) = slotCount;
            BTLT_A8(target, 0xc9) = chance;
        }

        if (action->target.targetedCount == successfulTargets)
            finalFlags |= 1;
        if (BTLT_AS16(action, 0xde) == -1)
            BTLT_A16(action, 0xde) = (u16)FUN_002d5b50(id);
        if (((s16)FUN_002e47a0(action, id, specialFlags) != 0) && (BTLT_A32(action, 0xd8) != 1))
            BTLT_A16(action, 0xdc) = (u16)FUN_002e4720();
        BTLT_A8(action, 0xca) = finalFlags;
    }
}
// FUN_002d7560 NONMATCHING
void FUN_002d7560(BtlAction *action)
{
    extern f32 FUN_001c0070(void);
    extern u32 FUN_0030bc50(DatUnit *);
    extern u16 FUN_0030bde0(DatUnit *, s32 *);
    extern void FUN_0019d3f0(const char *, s32);
    struct BtlRewardPersona {
        u16 personaId;
        u16 pad;
        u32 count;
    };
    BtlUnit *unit;

    if ((action->unk_1a & 1) != 0)
    {
        unit = action->unit;
        if (unit->genus == 1)
        {
            s32 outFlag;
            if (unit->charId >= 0x150)
                FUN_0019d3f0((const char *)DAT_00697880 + 0x60, 0x37e);
            if ((action->unk_1a & 0x20) == 0)
            {
                u32 rawValue;
                f32 timeScale;
                f32 value;
                u32 amount;
                u16 personaId;
                int found;
                action->unk_1a |= 0x20;
                rawValue = FUN_0030bc50(unit->datUnit);
                timeScale = FUN_001c0070();
                value = (f32)rawValue;
                amount = (u32)(value * timeScale);
                BTLT_B32(0xbfc) += amount;

                personaId = FUN_0030bde0(unit->datUnit, &outFlag);
                if ((outFlag != 1) && (action->target.rewardPersonaId != 0) &&
                    ((u8)FUN_002ffbc0(100) < action->target.rewardPersonaChance))
                    personaId = action->target.rewardPersonaId;
                if (personaId != 0)
                {
                    u16 i;
                    u8 *rewards;
                    found = 0;
                    i = 0;
                    rewards = DAT_007ce3ec;
                    for (; i <= (u16)2; i++)
                    {
                        u16 rewardId = *(u16 *)(rewards + i * 8 + 0xbe0);
                        if (rewardId != personaId)
                            continue;
                        (*(u32 *)(rewards + i * 8 + 0xbe4))++;
                        found = 1;
                        break;
                    }
                    if (found == 0)
                    {
                        rewards = DAT_007ce3ec;
                        for (i = 0; i < 3; i++)
                        {
                            if (*(u16 *)(rewards + i * 8 + 0xbe0) == 0)
                            {
                                *(u16 *)(rewards + i * 8 + 0xbe0) = personaId;
                                *(u32 *)(rewards + i * 8 + 0xbe4) = 1;
                                BTLT_B32(0xbf8) = i + 1;
                                break;
                            }
                        }
                    }
                }
                if ((((BtlEnemyData*)DAT_007ce410)[unit->charId].flags & 0x40) != 0)
                    BTLT_B32(0xbdc) |= 2;
                switch (BTLT_D16(unit->datUnit, 2))
                {
                case 0xc1: BTLT_B32(0xc20) |= 1; break;
                case 0xc2: BTLT_B32(0xc20) |= 2; break;
                case 0xc3: BTLT_B32(0xc20) |= 4; break;
                case 0xc4: BTLT_B32(0xc20) |= 8; break;
                default: break;
                }
            }
        }
    }
}
// FUN_002d7890
void FUN_002d7890(BtlAction* action, u64 mode)
{
    BtlUnit* unit = action->unit;
    u32 flags;

    FUN_002fa510(action, mode);
    if (mode == 1)
    {
        if (BTLT_A16(action, 0x460) != 0x1b6)
        {
            datCalcSetHp(unit->datUnit, 1);
        }
        FUN_00300560(unit->datUnit, 0x80000);
        unit->flags3 |= 0x10;
    }
    else
    {
        FUN_002ffd90(unit->datUnit, 0);
        FUN_00300560(unit->datUnit, 0xffffff);
        FUN_003004f0(unit->datUnit, 0x80000);
        flags = unit->flags3 | 1;
        unit->flags3 = flags;
        unit->flags3 = flags & 0xffffffef;
    }
}
// FUN_002d7970
void FUN_002D7970(void* arg)
{
    BtlTargetPacketWork* work = (BtlTargetPacketWork*)arg;
    work->source->unit->packetCount++;
    work->action->unit->packetCount++;
}

/* W415: swapped mutually exclusive low-HP branch layout; final call census matches retail (nd 374 -> 373, object 1100/1104). */
// FUN_002d79a0 NONMATCHING
u32 FUN_002d79a0(void *arg)
{
    BtlTargetPacketWork *work = (BtlTargetPacketWork *)arg;
    BtlAction *action = work->action;
    BtlUnit *unit;
    u32 oldDead;
    u32 oldLowHp;
    u32 oldDown;

    if ((action->unk_1a & 1) == 0)
        return 1;
    unit = action->unit;
    oldDead = datCalcIsDead(unit->datUnit, 0);
    oldLowHp = datCalcIsLowHp(unit->datUnit);
    oldDown = datCalcChkBadStatus(unit->datUnit, 0x200);

    if ((work->targetFlags & 2) != 0)
        action->unk_18 |= 0x1000;
    if ((work->targetFlags & 4) != 0)
        action->unk_18 |= 0x800;
    if ((*(u32 *)(work->data + 8) & 0x100000) != 0)
        action->unk_18 |= 0x2000;

    if ((BTLT_B32(0xc) & 0x10) != 0)
    {
        FUN_00300410(unit->datUnit, *(s32 *)(work->data + 0));
        FUN_00300480(unit->datUnit, *(s32 *)(work->data + 4));
        if (((*(s32 *)(work->data + 0) < 0) || (*(s32 *)(work->data + 4) < 0)) && (unit->genus == 0))
            FUN_001feea0(unit->charId);
    }
    if ((BTLT_B32(0xc) & 0x20) != 0)
    {
        FUN_002dc550(action, *(u32 *)(work->data + 8));
        FUN_003004f0(unit->datUnit, *(u32 *)(work->data + 8));
        FUN_00300560(unit->datUnit, *(u32 *)(work->data + 12));
    }
    if (*(u32 *)(work->data + 16) != 0)
        FUN_00302380(unit->datUnit, *(u32 *)(work->data + 16), 1);

    {
        u32 currentDead = datCalcIsDead(unit->datUnit, 0);
        if ((currentDead != 0) && (oldDead == 0))
        {
            if (unit->genus == 1)
            {
                BTLT_BS16(0xb9a)++;
                if ((*(u16 *)(work->data + 0x1a) & 8) != 0)
                    BTLT_BS16(0xb9c)++;
                {
                    u32 level = (u32)datCalcGetLevel(unit->datUnit) & 0xff;
                    BTLT_B32(0xc14) += level;
                    if ((s32)BTLT_B32(0xc10) < (s32)level)
                        BTLT_B32(0xc10) = level;
                }
            }
            {
                u8 rumble = ((*(u16 *)(work->data + 0x1a) & 0x10) != 0);
                FUN_002fa510(action, rumble);
                if (rumble != 0)
                {
                    if (BTLT_A16(action, 0x460) != 0x1b6)
                        datCalcSetHp(unit->datUnit, 1);
                    FUN_00300560(unit->datUnit, 0x80000);
                    unit->flags3 |= 0x10;
                }
                else
                {
                    u32 oldFlags;
                    FUN_002ffd90(unit->datUnit, 0);
                    FUN_00300560(unit->datUnit, 0xffffff);
                    FUN_003004f0(unit->datUnit, 0x80000);
                    oldFlags = unit->flags3 | 1;
                    unit->flags3 = oldFlags;
                    unit->flags3 = oldFlags & 0xffffffef;
                }
            }
            if ((u32)datCalcIsDead(unit->datUnit, 0) != 0)
            {
                if (BTLT_B32(0x148) == (u32)(uintptr_t)action)
                {
                    FUN_00103c30(0x19, 0x96, 0x19, 0);
                    FUN_002daa20(action, 0x13, ((*(u32 *)(work->data + 8) & 0x80000) != 0), 0, 2);
                }
                else
                    FUN_002daa20(action, 0x1b, 0, 0, 0);
            }
        }
        else
        {
            u32 currentLowHp = datCalcIsLowHp(unit->datUnit);
            if ((currentLowHp != 0) && (oldLowHp == 0))
                FUN_002daa20(action, 0x1a, 0, 0, 0);
            else
            {
                u32 currentDown = datCalcChkBadStatus(unit->datUnit, 0x200);
                if ((currentDown != 0) && (oldDown == 0))
                    FUN_002daa20(action, 0x1c, 0, 0, 0);
            }
        }
    }
    func_002faa50(work->source, action, (BtlTargetResult*)work->data);
    FUN_002831c0(unit, 6);
    return 1;
}

// FUN_002d7df0
void FUN_002D7DF0(void* arg)
{
    BtlTargetPacketWork* work = (BtlTargetPacketWork*)arg;
    work->source->unit->packetCount--;
    work->action->unit->packetCount--;
}

// FUN_002d7e20
BtlPacket *FUN_002d7e20(BtlAction *source, BtlAction *action, const void *data, u16 effect, u16 targetFlags)
{
    BtlPacket *packet = btlPacketCreate(0x700, 0x28);
    BtlTargetPacketWork *work;
    packet->initFunc = FUN_002D7970;
    packet->updateFunc = FUN_002d79a0;
    packet->destroyFunc = FUN_002D7DF0;
    work = (BtlTargetPacketWork *)packet->workData;
    work->source = source;
    work->action = action;
    memcpy(work->data, data, 0x1c);
    work->effect = effect;
    work->targetFlags = targetFlags;
    return packet;
}

// FUN_002d7ef0
void func_002d7ef0(void* arg)
{
    BtlTargetStatePacketWork* work = (BtlTargetStatePacketWork*)arg;
    work->action->unit->packetCount++;
}
// FUN_002d7f10
u32 func_002d7f10(void* arg)
{
    BtlTargetStatePacketWork* work = (BtlTargetStatePacketWork*)arg;
    u8 value;

    if ((work->flags & 2) != 0)
    {
        work->action->unk_28 = 0;
    }
    else if ((work->flags & 1) != 0)
    {
        work->action->unk_28++;
    }
    else
    {
        value = work->action->unk_28;
        if (value > 0)
        {
            if (value > 1)
            {
                value = 1;
            }
            work->action->unk_28 = value - 1;
        }
    }
    return 1;
}

/* Retail initializes the target-loop result state before dispatch.
 * Keep these aggregate values live across each target's slot loop.
 * The original reconstruction left successfulTargets/finalFlags indeterminate.
 * Retail also selects the nonnegative HP path before the negative callback.
 * This source follows that state transition order intentionally.
 */
// FUN_002d7f90
void func_002d7f90(void* arg)
{
    BtlTargetStatePacketWork* work = (BtlTargetStatePacketWork*)arg;
    work->action->unit->packetCount--;
}

// FUN_002d7fb0
void FUN_002d7fb0(BtlAction* action, u8 flags)
{
    BtlPacket* packet = btlPacketCreate(0x701, sizeof(BtlTargetStatePacketWork));
    BtlTargetStatePacketWork* work;

    packet->initFunc = func_002d7ef0;
    packet->updateFunc = func_002d7f10;
    packet->destroyFunc = func_002d7f90;
    work = (BtlTargetStatePacketWork*)packet->workData;
    work->action = action;
    work->flags = flags;
}

// FUN_002d8020
void func_002d8020(void* arg)
{
    BtlTargetActionPacketWork* work = (BtlTargetActionPacketWork*)arg;
    work->action->unit->packetCount++;
}

// FUN_002d8040
u32 FUN_002d8040(void* arg)
{
    BtlTargetActionPacketWork* work = (BtlTargetActionPacketWork*)arg;
    FUN_00302c50((u32)(uintptr_t)work->action->unit->datUnit);
    return 1;
}

// FUN_002d8070
void FUN_002d8070(void* arg)
{
    BtlTargetActionPacketWork* work = (BtlTargetActionPacketWork*)arg;
    work->action->unit->packetCount--;
}

/* Required existing declarations/notes:
 * - DAT_007ce3ec is the battle-global base; DAT_007ce3f8 is the 0x2c-byte
 *   attack/effect table, DAT_007ce410 is the 0x3e-byte character table, and
 *   DAT_007ce484 is the weapon-type x three-column scale table.
 * - FUN_002d6460 is the preceding target-slot helper.  All other raw FUN_/DAT_
 *   names above remain unnamed because no canonical public API was established.
 */

// FUN_002d8090
void FUN_002d8090(BtlAction* action)
{
    BtlPacket* packet = btlPacketCreate(0x703, sizeof(BtlTargetActionPacketWork));
    BtlTargetActionPacketWork* work;

    packet->initFunc = func_002d8020;
    packet->updateFunc = FUN_002d8040;
    packet->destroyFunc = FUN_002d8070;
    work = (BtlTargetActionPacketWork*)packet->workData;
    work->action = action;
}

// FUN_002d80f0
void func_002d80f0(void* arg)
{
    BtlTargetActionPacketWork* work = (BtlTargetActionPacketWork*)arg;
    work->action->unit->packetCount++;
}

// FUN_002d8110
u32 FUN_002d8110(BtlAction **param_1)
{
    BtlAction *action;
    BtlUnit *unit;
    u32 command;
    action = *param_1;
    unit = action->unit;
    command = action->target.commandId;
    switch (command)
    {
    case 2:
    {
        u16 personaId = action->target.specificId;
        u32 amount = FUN_003083f0((u32)(uintptr_t)unit->datUnit, personaId);
        if (amount != 0)
        {
            u8 *table = DAT_007ce3f8;
            u32 tableIndex = (u32)personaId & 0xffff;
            u8 effect = table[tableIndex * 44 + 3];
            switch (effect)
            {
            case 1:
                FUN_00300410_void(unit->datUnit, -(s32)amount);
                break;
            case 2:
                FUN_00300480_void(unit->datUnit, -(s32)amount);
                break;
            default:
                break;
            }
        }
        break;
    }
    case 3:
        if (unit->genus == 0)
        {
            u16 state = action->target.unk_38;
            if (unit->datUnit->id == 1)
            {
                u16 value = FUN_00170760_u16((s16)unit->datUnit->id,
                                             (s16)state);
                FUN_00170860_void((s16)unit->datUnit->id, (s16)state,
                                  (u16)(value - 1));
            }
            else
            {
                u16 i;
                u32 stateMasked;
                u16 value;
                i = 0;
                stateMasked = (u32)state & 0xffff;
                for (; i < 0xc; i++)
                {
                    value = FUN_00170670_u16((s16)unit->datUnit->id,
                                             (s16)i);
                    if (stateMasked == value)
                        break;
                }
                value = FUN_001706c0_u16((s16)unit->datUnit->id, (s16)i);
                FUN_00170710_void((s16)unit->datUnit->id, (s16)i,
                                  (s32)value - 1);
        }
        }
        break;
    case 9:
    case 1:
        break;
    default:
        break;
    }
    return 1;
}

// FUN_002d8310
void func_002d8310(void* arg)
{
    BtlTargetActionPacketWork* work = (BtlTargetActionPacketWork*)arg;
    work->action->unit->packetCount--;
}

// FUN_002d8330

void FUN_002d8330(BtlAction* action)
{
    BtlPacket* packet = btlPacketCreate(0x702, sizeof(BtlTargetActionPacketWork));
    BtlTargetActionPacketWork* work;

    packet->initFunc = func_002d80f0;
    packet->updateFunc = (BtlPacketUpdateFunc)FUN_002d8110;
    packet->destroyFunc = func_002d8310;
    work = (BtlTargetActionPacketWork*)packet->workData;
    work->action = action;
}

// FUN_002d8390

int FUN_002d8390(void)
{
  u16 selector;
  u32 comparison;
  u32 level;
  u32 unit;
  u16 *enemyEntry;
  u16 enemyFlags;
  u16 state;
  int difference;
  int hasStatus;
  int hasFlag40;
  int hasFlag80;

  selector = FUN_002d4e10(2, 0x80000);
  if (selector > 5) {
    return -1;
  }
  comparison = FUN_002d4cf0(2, 0x80000);
  level = FUN_002ffcc0_u32(*(u32 *)(*(u32 *)(*(u32 *)(DAT_007ce3ec + 0x148) + 0x30) + 0xa2c));
  difference = (s32)(comparison - (level & 0xff)) >= 4;
  hasStatus = 0;
  hasFlag40 = 0;
  hasFlag80 = 0;
  for (unit = *(u32 *)(DAT_007ce3ec + 0x158); unit != 0;
       unit = *(u32 *)(unit + 0xa34)) {
    if (FUN_00300580_u32(*(u32 *)(unit + 0xa2c), 2) != 0) {
      hasStatus = 1;
    }
    enemyEntry = (u16 *)DAT_007ce410;
    enemyEntry = (u16 *)((u8 *)enemyEntry + (u32)*(u16 *)(unit + 0xa4) * 0x3e);
    enemyFlags = *enemyEntry;
    if ((enemyFlags & 0x40) != 0) {
      hasFlag40 = 1;
    }
    if ((enemyFlags & 0x80) != 0) {
      hasFlag80 = 1;
    }
  }
  state = *(u16 *)(DAT_007ce3ec + 0x1a);
  switch (state) {
  case 0:
    if (hasFlag80) {
      return 10;
    }
    if (hasFlag40) {
      return 0xb;
    }
    if (difference) {
      return selector + 4;
    }
    return selector - 1;
  case 1:
    if (hasFlag80) {
      return 0x50;
    }
    if (hasFlag40) {
      return 0x51;
    }
    if (difference) {
      return selector + 0x45 + (hasStatus ? 5 : 0);
    }
    return selector + 0x3b + (hasStatus ? 5 : 0);
  case 2:
    if (hasFlag80) {
      return 0x5c;
    }
    if (hasFlag40) {
      return 0x5d;
    }
    if (difference) {
      return selector + 0x56;
    }
    return selector + 0x51;
  default:
    return -1;
  }
}



// FUN_002D8610

undefined4 FUN_002d8610(void)

{
  ushort uVar1;
  undefined4 uVar2;
  
  if (*(int *)(DAT_007ce3ec + 0xa20) == 0x5e) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar1 = FUN_002d4e10(1,0x80000);
    if (uVar1 < 2) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0x5e;
    }
  }
  return uVar2;
}

// FUN_002D8680
int func_002D8680(u64 param_1, int param_2)
{
    int result = 1;

    (void)param_1;
    if (param_2 == 1)
    {
        goto one;
    }
    switch (param_2)
    {
    case 0:
        result = 0x5f;
        goto done;
    default:
        goto default_case;
    }
one:
    result = -1;
    goto done;
default_case:
    result = -1;
done:
    return result;
}

// FUN_002D86C0
int func_002D86C0(int param_1)
{
    int action = *(int*)(param_1 + 0x30);

    if (*(u8*)(action + 0xa2) != 0)
    {
        return -1;
    }

    switch (*(u16*)(action + 0xa4))
    {
        case 2: return 0x60;
        case 3: return 0x61;
        case 4: return 0x62;
        case 5: return 0x63;
        case 7: return 0x64;
        case 8: return 0x65;
        case 9: return 0x66;
        case 10: return 0x67;
        default: return -1;
    }
}

// FUN_002d8780
int btlEfficacyGetResultIndexForOneToFourEnemies(void)
{
    int activeEnemyCount;

    activeEnemyCount = func_002d4e10(BTL_EFFICACY_ENEMY_GENUS_MASK, UNIT_BADSTATUS_DEAD) & 0xffff;
    if (activeEnemyCount >= BTL_EFFICACY_ONE_TO_FOUR_ENEMY_COUNT_END)
    {
        return BTL_EFFICACY_NO_RESULT;
    }
    if (activeEnemyCount == 0)
    {
        return BTL_EFFICACY_NO_RESULT;
    }
    return BTL_EFFICACY_ONE_TO_FOUR_RESULT_BASE - activeEnemyCount;
}

// FUN_002d87e0
int btlEfficacyGetResultIndexForTwoToFiveEnemies(void)
{
    int activeEnemyCount;

    activeEnemyCount = func_002d4e10(BTL_EFFICACY_ENEMY_GENUS_MASK, UNIT_BADSTATUS_DEAD) & 0xffff;
    // Keep the retail comparison forms: this callback accepts enemy counts [2, 5].
    if (activeEnemyCount > 5)
    {
        return BTL_EFFICACY_NO_RESULT;
    }
    if (activeEnemyCount < 2)
    {
        return BTL_EFFICACY_NO_RESULT;
    }
    return BTL_EFFICACY_TWO_TO_FIVE_RESULT_BASE - activeEnemyCount;
}

// FUN_002d8850 MATCHING
s32 FUN_002d8850(s32 param_1)
{
    bool noRandom;
    if (*(u8*)(*(u8**)(param_1 + 0x30) + 0xa2) != 0) {
        return -1;
    }
    noRandom = (u16)FUN_002db480() == 0;
    switch (*(u16*)(*(u8**)(param_1 + 0x30) + 0xa4)) {
    case 2:
        if (noRandom) return 0x72;
        return 0x71;
    case 3:
        if (noRandom) return 0x74;
        return 0x73;
    case 4:
        if (noRandom) return 0x76;
        return 0x75;
    case 5:
        if (noRandom) return 0x78;
        return 0x77;
    case 7:
        if (noRandom) return 0x7a;
        return 0x79;
    case 8:
        if (noRandom) return 0x7c;
        return 0x7b;
    case 9:
        if (noRandom) return 0x7e;
        return 0x7d;
    case 10:
        if (noRandom) return 0x80;
        return 0x7f;
    default:
        return -1;
    }
}

// FUN_002d89e0 MATCHING
s32 func_002d89e0(u64 param_1, s32 param_2)
{
    (void)param_1;
    switch (param_2)
    {
    case 2:
        return 0xbf;
    case 3:
        return 0xc0;
    case 4:
        return 0xc1;
    case 5:
        return 0xc2;
    case 7:
        return 0xc3;
    case 8:
        return 0xc4;
    case 9:
        return 0xc5;
    case 10:
        return 0xc6;
    default:
        return -1;
    }
}

// FUN_002d8a80 MATCHING
s32 func_002d8a80(void)
{
    s32 result;

    switch (*(u16*)(*(u8**)(DAT_007ce3ec + 0xbbc) + 8))
    {
    case 0x1a1:
        result = 0x88;
        break;
    default:
        result = 0x87;
        break;
    }
    return result;
}

// FUN_002d8ac0 MATCHING
s32 func_002d8ac0(void)
{
    s32 result;

    switch (*(u16*)(*(u8**)(DAT_007ce3ec + 0xbbc) + 8))
    {
    case 0x1a1:
        result = 0x84;
        break;
    default:
        result = 0x83;
        break;
    }
    return result;
}

// FUN_002d8b00 MATCHING
s32 func_002d8b00(void)
{
    return 0x8f;
}

// FUN_002d8b10 MATCHING
s32 func_002d8b10(void)
{
    return 0xb6;
}

// FUN_002d8b20 MATCHING
s32 func_002d8b20(void)
{
    return 0xb1;
}

// FUN_002d8b30 MATCHING
s32 func_002d8b30(void)
{
    return 0xb2;
}

// FUN_002d8b40

s32 FUN_002d8b40(s32 param_1)
{
    u32 personaId;
    u16 hp;
    u16 maxHp;
    s32 hpPercent;

    if (*(s32*)(iGpffffb6fc + 0x148) != param_1)
    {
        return -1;
    }
    if (FUN_0016f190(0x1362) != 0)
    {
        if (FUN_0016f190(0x1361) != 0)
        {
            return 0x1ba;
        }
        if (FUN_0016f190(0x1360) != 0)
        {
            return 0x1bc;
        }
    }
    if (*(u16*)(iGpffffb6fc + 0xb9a) == 0)
    {
        return 0x6c;
    }

    personaId = *(u32*)(*(s32*)(param_1 + 0x30) + 0xa2c);
    hp = (u16)FUN_002ffd70(personaId);
    maxHp = (u16)FUN_002ffdf0(personaId);
    hpPercent = hp * 100 / maxHp;
    if (hpPercent > 0x46)
    {
        if (*(s32*)(*(s32*)(iGpffffb6fc + 0x148) + 0x20) < 3)
        {
            if (FUN_002ddc10(6) == 0)
            {
                return 0xce;
            }
            return 0xd1;
        }
    }
    if (hpPercent <= 0x1e)
    {
        goto criticalHp;
    }
    if (FUN_002ddc10(6) == 0)
    {
        return 0xcf;
    }
    return 0xd2;
criticalHp:
    if (FUN_002ddc10(6) == 0)
    {
        return 0xd0;
    }
    return 0xd3;
}

// FUN_002d8cf0 MATCHING
s32 func_002d8cf0(s32 param_1)
{
    s32 action;

    action = *(s32*)(param_1 + 0x30);
    if (*(u8*)(action + 0xa2) != 0)
    {
        return -1;
    }

    switch (*(u16*)(action + 0xa4))
    {
    case 1:
        return 0xd4;
    case 2:
        return 0xd5;
    case 3:
        return 0xd6;
    case 4:
        return 0xd7;
    case 5:
        return 0xd8;
    case 7:
        return 0xd9;
    case 8:
        return 0xda;
    case 9:
        return 0xdb;
    case 10:
        return 0xdc;
    default:
        return -1;
    }
}

// FUN_002d8db0 MATCHING
s32 func_002d8db0(void)
{
    return -1;
}

// FUN_002d8dc0 MATCHING
s32 func_002d8dc0(s32 param_1)
{
    s32 action;

    action = *(s32*)(param_1 + 0x30);
    if (*(u8*)(action + 0xa2) != 0)
    {
        return -1;
    }

    switch (*(u16*)(action + 0xa4))
    {
    case 1:
        return 0xdd;
    case 2:
        return 0xde;
    case 3:
        return 0xdf;
    case 4:
        return 0xe0;
    case 5:
        return 0xe1;
    case 7:
        return 0xe2;
    case 8:
        return 0xe3;
    case 9:
        return 0xe4;
    case 10:
        return 0xe5;
    default:
        return -1;
    }
}

// FUN_002d8e80

s32 FUN_002d8e80(BtlAction* action, s32 mode)
{
    s32 result;

    if (mode != 0)
    {
        result = 0xe8;
    }
    else if ((action->unk_18 & 0x1800) != 0)
    {
        result = 0xe9;
    }
    else
    {
        if (func_002ddc10(6) == 0)
        {
            result = 0xe6;
        }
        else
        {
            result = 0xe7;
        }
    }
    return result;
}






/* Required symbol/type notes:
 * - The canonical TU must provide iGpffffb6fc (Battle work base), iGpffffb7b8
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


/* Removing this loses FUN_002dcbc0 (MATCH nd0 -> MISMATCH nd64) - measured W161. */


// FUN_002d8ef0
s32 FUN_002d8ef0(BtlAction* action)
{
    s32 result;

    if (gBtl->actionList.head == action)
    {
        result = 0xea;
    }
    else if (action->unit->genus == UNIT_GENUS_EC)
    {
        result = 0xeb;
    }
    else
    {
        result = -1;
    }
    return result;
}


// FUN_002d8f40
s32 FUN_002d8f40(BtlAction* action)
{
    s32 result;

    if (gBtl->actionList.head == action)
    {
        result = 0x18e;
    }
    else
    {
        result = -1;
    }
    return result;
}


// FUN_002d8f70 NONMATCHING

int FUN_002d8f70(int param_1)

{
  byte bVar1;
  ushort uVar2;
  int uVar3;
  int iVar4;
  
  switch (*(u8 *)(*(u32 *)(param_1 + 0x30) + 0xa2)) {
  default:
    iVar4 = -1;
    break;
  case 0:
    uVar3 = FUN_002d4e10(2,0x80000);
    uVar2 = *(ushort *)(param_1 + 0x1a);
    *(ushort *)(param_1 + 0x1a) = uVar2 | 0x40;
    switch(*(undefined2 *)(*(int *)(param_1 + 0x30) + 0xa4)) {
    default:
      iVar4 = -1;
      break;
    case 1:
      bVar1 = *(byte *)(param_1 + 0x28);
      if ((bVar1 < 2) || ((uVar2 & 0x40) == 0)) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0xf0 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0xf3 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 0xf5 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0xf6 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
      break;
    case 2:
      bVar1 = *(byte *)(param_1 + 0x28);
      if (bVar1 < 2) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0xfb - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0xfe - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 0x100 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0x101 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 5) {
        if (uVar3 == 0) {
          iVar4 = 0x101;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
      break;
    case 3:
      bVar1 = *(byte *)(param_1 + 0x28);
      if (bVar1 < 2) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0x106 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0x109 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 0x10b - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0x10c - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 5) {
        if (uVar3 == 0) {
          iVar4 = 0x10c;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
      break;
    case 4:
      bVar1 = *(byte *)(param_1 + 0x28);
      if (bVar1 < 2) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0x111 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0x114 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 0x116 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0x117 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 5) {
        if (uVar3 == 0) {
          iVar4 = 0x117;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
      break;
    case 5:
      bVar1 = *(byte *)(param_1 + 0x28);
      if (bVar1 < 2) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0x11c - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0x11f - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 0x121 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0x122 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 5) {
        if (uVar3 == 0) {
          iVar4 = 0x122;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
      break;
    case 7:
      bVar1 = *(byte *)(param_1 + 0x28);
      if (bVar1 < 2) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0x127 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0x12a - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 300 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0x12d - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 5) {
        if (uVar3 == 0) {
          iVar4 = 0x12d;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
      break;
    case 8:
      bVar1 = *(byte *)(param_1 + 0x28);
      if (bVar1 < 2) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0x132 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0x135 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 0x137 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0x138 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 5) {
        if (uVar3 == 0) {
          iVar4 = 0x138;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
      break;
    case 9:
      bVar1 = *(byte *)(param_1 + 0x28);
      if (bVar1 < 2) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0x13d - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0x140 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 0x142 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0x143 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 5) {
        if (uVar3 == 0) {
          iVar4 = 0x143;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
      break;
    case 10:
      bVar1 = *(byte *)(param_1 + 0x28);
      if (bVar1 < 2) {
        if ((uVar3 < 5) && (uVar3 != 0)) {
          iVar4 = 0x148 - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 2) {
        if ((uVar3 < 4) && (uVar3 != 0)) {
          iVar4 = 0x14b - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 3) {
        if ((uVar3 < 3) && (uVar3 != 0)) {
          iVar4 = 0x14d - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 4) {
        if ((uVar3 < 2) && (uVar3 != 0)) {
          iVar4 = 0x14e - uVar3;
        }
        else {
          iVar4 = -1;
        }
      }
      else if (bVar1 == 5) {
        if (uVar3 == 0) {
          iVar4 = 0x14e;
        }
        else {
          iVar4 = -1;
        }
      }
      else {
        iVar4 = -1;
      }
  }
    break;
  }
  return iVar4;
}


// FUN_002d9aa0
s32 FUN_002d9aa0(BtlAction* action, u32 flags)
{
    if (action->unit->genus != 0)
    {
        return -1;
    }
    if (*(BtlAction**)(iGpffffb6fc + 0x148) != action)
    {
        return -1;
    }
    if ((flags & 2) != 0)
    {
        return 0x150;
    }
    if ((flags & 4) != 0)
    {
        return 0x14f;
    }
    return -1;
}















/* Retail formation reference recovery, retained NONMATCHING until codegen cleanup. */




/* Target forward declarations. */
// Typed alias for callers that consume the helper's full 16-bit result.
// The caller passes two 32-bit resource identifiers.



























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










// FUN_002d9b20
s32 FUN_002d9b20(BtlAction* action)
{
    if (action->unit->genus != 0)
    {
        return -1;
    }
    switch (action->unit->charId)
    {
    case 1:
        return 0x151;
    case 2:
        return 0x152;
    case 3:
        return 0x153;
    case 4:
        return 0x154;
    case 5:
        return 0x155;
    case 7:
        return 0x156;
    case 8:
        return 0x157;
    case 9:
        return 0x158;
    case 10:
        return 0x159;
    case 0:
    case 6:
    default:
        return -1;
    }
}

// FUN_002d9be0
s32 FUN_002d9be0(BtlAction* action)
{
    if (action->unit->genus != 0)
    {
        return -1;
    }
    switch (action->unit->charId)
    {
    case 1:
        return 0x15a;
    case 2:
        return 0x15b;
    case 3:
        return 0x15c;
    case 4:
        return 0x15d;
    case 5:
        return 0x15e;
    case 7:
        return 0x15f;
    case 8:
        return 0x160;
    case 9:
        return 0x161;
    case 10:
        return 0x162;
    case 0:
    case 6:
    default:
        return -1;
    }
}

// FUN_002d9ca0
s32 FUN_002d9ca0(BtlAction* action)
{
    if (action->unit->genus != 0)
    {
        return -1;
    }
    switch (action->unit->charId)
    {
    case 1:
        return -1;
    case 2:
        return 0x163;
    case 3:
        return 0x165;
    case 4:
        return 0x167;
    case 5:
        return 0x169;
    case 7:
        return 0x16b;
    case 8:
        return 0x16d;
    case 9:
        return 0x16f;
    case 10:
        return 0x171;
    case 0:
    case 6:
    default:
        return -1;
    }
}

// FUN_002d9d60
s32 FUN_002d9d60(BtlAction* action)
{
    return -1;
}

// FUN_002d9d70 NONMATCHING

short FUN_002d9d70(int param_1)

{
  short sVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  u32 uVar9;
  ulong uVar10;
  short sVar11;
  bool bVar12;
  BtlTargetMessage *entry;
  BtlTargetMessage entries[64];
  
  if (*(u8 *)(*(int *)(param_1 + 0x30) + 0xa2) != 0) {
    return -1;
  }
    uVar7 = 0;
    uVar4 = 0;
    for (iVar2 = *(int *)(iGpffffb6fc + 0x150); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa34)) {
      lVar8 = FUN_0030b5a0(*(undefined4 *)(iVar2 + 0xa2c),0);
      if ((lVar8 == 0) &&
         ((lVar8 = FUN_0029a1d0(iVar2), lVar8 == 0 || ((*(ushort *)((int)lVar8 + 0x18) & 0x20) == 0)
          ))) {
        lVar8 = FUN_0030b5e0(*(undefined4 *)(iVar2 + 0xa2c));
        if (lVar8 != 0) {
          entries[uVar7].messageId = 0x174;
          entries[uVar7].unitId = *(short *)(iVar2 + 0xa4);
          uVar7 = uVar7 + 1 & 0xffff;
          uVar4 = uVar4 + 1;
        }
        lVar8 = FUN_00300580(*(undefined4 *)(iVar2 + 0xa2c),1);
        if (lVar8 == 0) {
          lVar8 = FUN_00300580(*(undefined4 *)(iVar2 + 0xa2c),4);
          if (lVar8 == 0) {
            lVar8 = FUN_00300580(*(undefined4 *)(iVar2 + 0xa2c),8);
            if (lVar8 == 0) {
              lVar8 = FUN_00300580(*(undefined4 *)(iVar2 + 0xa2c),0x10);
              if (lVar8 == 0) {
                lVar8 = FUN_00300580(*(undefined4 *)(iVar2 + 0xa2c),0x20);
                if (lVar8 == 0) {
                  lVar8 = FUN_00300580(*(undefined4 *)(iVar2 + 0xa2c),0x40);
                  if (lVar8 != 0) {
                    entries[uVar7].messageId = 0x1c6;
                    entries[uVar7].unitId = *(short *)(iVar2 + 0xa4);
                    uVar7 = uVar7 + 1 & 0xffff;
                  }
                }
                else {
                  entries[uVar7].messageId = 0x1bd;
                  entries[uVar7].unitId = *(short *)(iVar2 + 0xa4);
                  uVar7 = uVar7 + 1 & 0xffff;
                }
              }
              else {
                entries[uVar7].messageId = 0x1ac;
                entries[uVar7].unitId = *(short *)(iVar2 + 0xa4);
                uVar7 = uVar7 + 1 & 0xffff;
              }
            }
            else {
              entries[uVar7].messageId = 0x1a3;
              entries[uVar7].unitId = *(short *)(iVar2 + 0xa4);
              uVar7 = uVar7 + 1 & 0xffff;
            }
          }
          else {
            entries[uVar7].messageId = 0x19a;
            entries[uVar7].unitId = *(short *)(iVar2 + 0xa4);
            uVar7 = uVar7 + 1 & 0xffff;
          }
        }
        else {
          entries[uVar7].messageId = 399;
          entries[uVar7].unitId = *(short *)(iVar2 + 0xa4);
          uVar7 = uVar7 + 1 & 0xffff;
        }
        if ((*(ushort *)(iVar2 + 0xa4) != 1) && (*(ushort *)(iVar2 + 0xa4) < 0xb)) {
          uVar9 = FUN_00174800(*(undefined2 *)(iVar2 + 0xa4));
          FUN_00175ca0(uVar9);
        }
        if ((*(short *)(iVar2 + 0xa4) == 1) && (lVar8 = FUN_0017b170(), lVar8 < 2)) {
          entry = &entries[uVar7];
          entry->messageId = -1;
          sVar11 = FUN_0016c920(*(undefined2 *)(iVar2 + 0xa4));
          if (sVar11 == 5) {
            entry->messageId = 0x188;
          }
          else if (sVar11 == 4) {
            entry->messageId = -1;
          }
          else if (sVar11 == 3) {
            entry->messageId = 0x187;
          }
          else if (sVar11 == 1) {
            entry->messageId = -1;
          }
          else if (sVar11 == 2) {
            entry->messageId = 0x186;
          }
          if (-1 < entry->messageId) {
            entries[uVar7].unitId = -1;
            uVar7 = uVar7 + 1 & 0xffff;
          }
        }
        else if ((*(short *)(iVar2 + 0xa4) == 3) &&
                (lVar8 = FUN_00300580(*(undefined4 *)(iVar2 + 0xa2c),0x200), lVar8 != 0)) {
          entries[uVar7].messageId = 0x1b5;
          entries[uVar7].unitId = -1;
          uVar7 = uVar7 + 1 & 0xffff;
        }
      }
    }
    if (2 < uVar4) {
      entries[uVar7].messageId = 0x17d;
      entries[uVar7].unitId = -1;
      uVar7 = uVar7 + 1 & 0xffff;
    }
    for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 1) {
      uVar3 = FUN_0016dd60(uVar4);
      if (((uVar3 != 0) && (uVar3 < 0xb)) && (FUN_00288fe0(0, uVar3) == NULL)) {
        uVar5 = 0;
        while ((uVar5 < 4 &&
               (((iVar2 = *(int *)(iGpffffb6fc + uVar5 * 4 + 0xbac), iVar2 == 0 ||
                 (iVar2 = *(int *)(iVar2 + 4), iVar2 == 0)) || (*(ushort *)(iVar2 + 2) != uVar3)))))
        {
          uVar5 = uVar5 + 1 & 0xffff;
        }
        if (uVar5 == 4) {
          uVar5 = 0;
          while ((uVar5 < 3 &&
                 (((iVar2 = *(int *)(iGpffffb6fc + uVar5 * 8 + 0xbc4), iVar2 == 0 ||
                   (iVar2 = *(int *)(iVar2 + 4), iVar2 == 0)) || (*(ushort *)(iVar2 + 2) != uVar3)))
                 )) {
            uVar5 = uVar5 + 1 & 0xffff;
          }
          if (uVar5 == 3) {
            uVar5 = FUN_0016c4f0(uVar3);
            uVar10 = FUN_0016c970(uVar3);
            if ((((uVar5 & 0xffff) != 0) && ((uVar10 & 0x80000) == 0)) &&
               (uVar6 = FUN_0016c5f0(uVar3), ((uVar5 & 0xffff) * 100) / (uVar6 & 0xffff) < 0x1f)) {
              switch(uVar3) {
              case 2:
                entries[uVar7].messageId = 0x17e;
                break;
              case 3:
                entries[uVar7].messageId = 0x17f;
                break;
              case 4:
                entries[uVar7].messageId = 0x180;
                break;
              case 5:
                entries[uVar7].messageId = 0x181;
                break;
              case 7:
                entries[uVar7].messageId = 0x182;
                break;
              case 8:
                entries[uVar7].messageId = 0x183;
                break;
              case 9:
                entries[uVar7].messageId = 0x184;
                break;
              case 10:
                entries[uVar7].messageId = 0x185;
              }
              entries[uVar7].unitId = -1;
              uVar7 = uVar7 + 1 & 0xffff;
            }
          }
        }
      }
    }
    bVar12 = false;
    for (iVar2 = *(int *)(iGpffffb6fc + 0x158); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xa34)) {
      if ((((BtlEnemyData*)iGpffffb720)[*(u16 *)(iVar2 + 0xa4)].flags & 0x40) != 0) {
        bVar12 = true;
      }
    }
    if (bVar12) {
      entries[uVar7].messageId = 0x18d;
      entries[uVar7].unitId = -1;
      uVar7 = uVar7 + 1 & 0xffff;
    }
    uVar4 = FUN_002d4e10(2,0x80000);
    uVar10 = (ulong)uVar4;
    if ((long)*(short *)(iGpffffb6fc + 0xa34) == uVar10) {
      if ((uVar10 < 5) && (uVar10 != 0)) {
        entries[uVar7].messageId = uVar4 + 0x188;
        entries[uVar7].unitId = -1;
        uVar7 = uVar7 + 1 & 0xffff;
      }
    }
    else {
      *(ushort *)(iGpffffb6fc + 0xa34) = uVar4;
    }
    lVar8 = FUN_00301ca0(*(undefined4 *)(*(int *)(*(int *)(iGpffffb6fc + 0x148) + 0x30) + 0xa2c),10)
    ;
    if (lVar8 != 0) {
      entries[uVar7].messageId = 0x1b6;
      entries[uVar7].unitId = -1;
      uVar7 = uVar7 + 1 & 0xffff;
    }
    lVar8 = FUN_00301ca0(*(undefined4 *)(*(int *)(*(int *)(iGpffffb6fc + 0x148) + 0x30) + 0xa2c),
                         0x80);
    if (lVar8 != 0) {
      entries[uVar7].messageId = 0x1b7;
      entries[uVar7].unitId = -1;
      uVar7 = uVar7 + 1 & 0xffff;
    }
    lVar8 = FUN_00301ca0(*(undefined4 *)(*(int *)(*(int *)(iGpffffb6fc + 0x148) + 0x30) + 0xa2c),
                         0x220);
    if (lVar8 != 0) {
      entries[uVar7].messageId = 0x1b8;
      entries[uVar7].unitId = -1;
      uVar7 = uVar7 + 1 & 0xffff;
    }
    uVar9 = FUN_00175360();
    uVar9 = FUN_00174a90(uVar9);
    lVar8 = FUN_002d5550();
    if ((lVar8 == 0x1ad) ||
       ((*(short *)((int)uVar9 + 2) != 0xbf &&
        (lVar8 = FUN_003005e0(*(undefined4 *)
                               (*(int *)(*(int *)(iGpffffb6fc + 0x148) + 0x30) + 0xa2c),0x261),
        lVar8 == 0)))) {
      FUN_00175ca0(uVar9);
    }
    if (uVar7 != 0) {
      uVar7 = FUN_002ffbc0(uVar7);
      sVar11 = entries[uVar7 & 0xffff].messageId;
      if ((long)*(int *)(iGpffffb6fc + 0xa30) == (long)sVar11) {
        sVar11 = -1;
      }
      else {
        *(int *)(iGpffffb6fc + 0xa30) = (int)sVar11;
        sVar1 = entries[uVar7 & 0xffff].unitId;
        if (-1 < sVar1) {
          if ((long)sVar11 == 399) {
            if (sVar1 == 1) {
              sVar11 = -1;
            }
            else {
              sVar11 = sVar11 + 2;
            }
          }
          switch(sVar1) {
          case 2:
            sVar11 = sVar11 + 1;
            break;
          case 3:
            sVar11 = sVar11 + 2;
            break;
          case 4:
            sVar11 = sVar11 + 3;
            break;
          case 5:
            sVar11 = sVar11 + 4;
            break;
          case 7:
            sVar11 = sVar11 + 5;
            break;
          case 8:
            sVar11 = sVar11 + 6;
            break;
          case 9:
            sVar11 = sVar11 + 7;
            break;
          case 10:
            sVar11 = sVar11 + 8;
          }
        }
      }
    }
    else {
      sVar11 = -1;
    }
  return sVar11;
}

// FUN_002da810
s32 FUN_002da810(BtlAction* action)
{
    if (*(BtlAction**)(iGpffffb6fc + 0x148) != action)
    {
        return -1;
    }
    if (datCalcChkBadStatus(action->unit->datUnit, 1) == 0)
    {
        return -1;
    }

    switch (action->target.commandId)
    {
        case 1:
            if (FUN_002d1600(&action->target) == 1)
            {
                return 0x18f;
            }
            break;
        case 2:
            if (FUN_002d1600(&action->target) == 2 &&
                FUN_00308860(action->target.specificId) != 0)
            {
                return 0x190;
            }
            break;
        case 0xb:
            if (datGetScenarioMode() == 0)
            {
                return 0x191;
            }
            break;
        default:
            break;
    }

    return -1;
}

// FUN_002da930
u64 FUN_002da930(u64 param_1, u64 command, u64 param_3, u64 param_4)
{
    switch (command)
    {
        case 0x1cf:
            *(u16*)(iGpffffb6fc + 0xa14) = 2;
            break;
        case 0x1d0:
            *(u16*)(iGpffffb6fc + 0xa14) = 3;
            break;
        case 0x1d1:
            *(u16*)(iGpffffb6fc + 0xa14) = 4;
            break;
        case 0x1d2:
            *(u16*)(iGpffffb6fc + 0xa14) = 5;
            break;
        case 0x1d3:
            *(u16*)(iGpffffb6fc + 0xa14) = 7;
            break;
        case 0x1d4:
            *(u16*)(iGpffffb6fc + 0xa14) = 8;
            break;
        case 0x1d5:
            *(u16*)(iGpffffb6fc + 0xa14) = 9;
            break;
        case 0x1d6:
            *(u16*)(iGpffffb6fc + 0xa14) = 10;
            break;
        case 0x1d7:
            *(u16*)(iGpffffb6fc + 0xa14) = 6;
            break;
        default:
            break;
    }
    return command;
}

// FUN_002daa20 NONMATCHING
s32 FUN_002daa20(BtlAction* param_1, u16 param_2, s32 param_3, s32 param_4, s32 param_5)
{
    u32* effectFlags;
    u8* resourceTable;
    u8* resultTable;
    u8* resultRecord;
    BtlTargetEffectFn effect;
    s32 result;


    if ((*(u32*)(iGpffffb6fc + 0xc) & 0x01000000) == 0)
    {
        return 1;
    }
    if (*(u16*)(iGpffffb6fc + 0xa18) != 0)
    {
        return 0;
    }
    if (datGetFlag(0x1317) != 0)
    {
        return 1;
    }
    if ((param_5 & 6) == 0 && (*(u16*)(iGpffffb6fc + 0xa16) & 1) != 0)
    {
        return 1;
    }

    effectFlags = (u32*)(iGpffffb7b8 +
        (u32)*(u16*)(*(u8**)(iGpffffb6fc + 0xbbc) + 8) * 0x1c);
    if (param_2 != 0x1f && (*effectFlags & 0x400) != 0)
    {
        return 1;
    }
    if ((*(u16*)(iGpffffb6fc + 0xa16) & 1) != 0)
    {
        if ((s32)*(s16*)(iGpffffb6fc + 0xa24) == (s32)param_2)
        {
            return 1;
        }
        if ((s32)*(s16*)(iGpffffb6fc + 0xa2c) == (s32)param_2)
        {
            return 1;
        }
    }

    effect = D_006978F0[param_2];
    if (effect == NULL)
    {
        return 1;
    }
    result = effect(param_1, param_3, param_4, 0);
    if (result < 0)
    {
        return 1;
    }

    resourceTable = *(u8**)(iGpffffb6fc + 0xa1c);
    resultTable = *(u8**)(resourceTable + 0x110);
    resultRecord = resultTable + ((u32)result & 0xffff) * 0xc;
    if ((*effectFlags & 0x1000) != 0 && *resultRecord != 0)
    {
        return 1;
    }

    if (datGetScenarioMode() != 0)
    {
        switch ((u32)FUN_002d5550())
        {
        case 0x1b1:
        case 0x1b2:
        case 0x1b3:
            if ((*(u16*)resultRecord >> 8) != 0)
            {
                return 1;
            }
            break;
        default:
            break;
        }
    }

    if ((param_5 & 2) != 0)
    {
        FUN_002dba80();
        *(u16*)(iGpffffb6fc + 0xa36) = 2;
    }
    else
    {
        *(u16*)(iGpffffb6fc + 0xa36) = 0;
    }

    return FUN_002db9f0(param_2, result);
}

// FUN_002dad00
void FUN_002dad00(void)
{
    u8* base;
    u16* modePtr;
    u16 mode;
    s16* counter;
    u8* resourceTable;
    u8* record;
    s32 offset;
    u32 recordOffset;
    u32 randomValue;

    base = iGpffffb6fc;
    modePtr = (u16*)(base + 0xa18);
    mode = *modePtr;
    switch (mode) {
    case 0:
        goto updateFlag;
    case 1:
        counter = (s16*)(base + 0xa36);
        if (*counter > 0) {
            *counter = *counter - 1;
            goto updateFlag;
        }
        *modePtr = 2;
    case 2:
        break;
    default:
        goto updateFlag;
    }
    resourceTable = *(u8**)(iGpffffb6fc + 0xa1c);
    record = *(u8**)(resourceTable + 0x110);
    recordOffset = (u32)*(u16*)(iGpffffb6fc + 0xa28) * 0xc;
    recordOffset += (u32)record;
    offset = *(u32*)(recordOffset + 4);
    record += offset;
    FUN_003c8dd0(record);
    randomValue = datCalcRand((u32)FUN_003a3010(record));
    FUN_003c8de0(*(u16*)(iGpffffb6fc + 0xa14), randomValue, 0, 0);
    *(u32*)(iGpffffb6fc + 0xa20) = *(u32*)(iGpffffb6fc + 0xa28);
    *(u16*)(iGpffffb6fc + 0xa24) = *(s16*)(iGpffffb6fc + 0xa2c);
    *(u16*)(iGpffffb6fc + 0xa16) |= 1;
    *(u16*)(iGpffffb6fc + 0xa18) = 0;
updateFlag:
    if (FUN_003c8ea0() == 0)
        *(u16*)(iGpffffb6fc + 0xa16) &= (u16)~1;
}

// FUN_002dae30 NONMATCHING
void FUN_002dae30(u64 param_1)
{
    u32 stop;
    u32 slotIndex;

    stop = 0;
    slotIndex = 0;
    while (slotIndex < 3 && stop == 0)
    {
        u32 bit = (1u << (slotIndex & 0x1f)) & 0xffff;
        if ((*(u16*)(iGpffffb6fc + 0xa04) & bit) != 0)
        {
            if (param_1 != 0)
            {
                u8* slot = iGpffffb6fc + slotIndex * 4;
                *(u16*)(slot + 0x9f8) = *(u16*)(slot + 0x9f8) + 1;
            }

            switch (bit)
            {
            case 1:
                if (*(u32*)(iGpffffb6fc + 0xa10) == 0 &&
                    FUN_0029adf0(*(BtlAction**)(iGpffffb6fc + 0x148)) == 0)
                {
                    u8* candidates[3];
                    u32 candidateCount = 0;
                    u32 i;
                    for (i = 0; i < 3; i++)
                    {
                        u8* candidate = *(u8**)(iGpffffb6fc + 0xbc4 + i * 8);
                        if (candidate != NULL &&
                            (*(u16*)(candidate + 0xa) & 1) == 0 &&
                            FUN_002ff790(candidate) == 0)
                        {
                            candidates[candidateCount] = candidate;
                            candidateCount = (candidateCount + 1) & 0xffff;
                        }
                    }
                    if (candidateCount == 0)
                    {
                        *(u16*)(iGpffffb6fc + 0xa04) &= (u16)~1;
                    }
                    else
                    {
                        u8* selected = candidates[datCalcRand(candidateCount)];
                        *(u8**)(iGpffffb6fc + 0xa10) = selected;
                        FUN_002daa20(0, 7, *(u16*)(*(u8**)(selected + 4) + 2), 0, 4);
                    }
                }
                break;
            case 4:
            {
                u16 currentId = FUN_002db690();
                u8* currentUnit = (u8*)btlUnitFindFromId(currentId);
                if (currentUnit == NULL ||
                    datCalcIsDead(*(DatUnit**)(currentUnit + 0xa2c), 0) != 0)
                {
                    BtlUnit* unit;
                    unit = *(BtlUnit**)(iGpffffb6fc + 0x158);
                    while (unit != NULL &&
                           (((unit->flags3 & 8) == 0 ||
                             datCalcIsDead(unit->datUnit, 0) != 0) ||
                            unit->charId != *(u16*)(iGpffffb6fc + 0xa0c)))
                    {
                        unit = unit->next;
                    }
                    if (unit == NULL)
                    {
                        u8* slot = iGpffffb6fc + slotIndex * 4;
                        *(u16*)(slot + 0x9f8) = *(u16*)(slot + 0x9fa);
                    }
                    else
                    {
                        FUN_002db650(*(u32*)((u8*)unit + 0xa8));
                    }
                }
                break;
            }
            }

            {
                u8* slot = iGpffffb6fc + slotIndex * 4;
                if (*(u16*)(slot + 0x9fa) <= *(u16*)(slot + 0x9f8))
                {
                    switch (bit)
                    {
                    case 1:
                        if ((*(u16*)(iGpffffb6fc + 0xa06) & 1) == 0 &&
                            FUN_0029adf0(*(BtlAction**)(iGpffffb6fc + 0x148)) == 0)
                        {
                            if (FUN_002db480() == 0 && *(u32*)(iGpffffb6fc + 0xa10) != 0)
                            {
                                u8* selected = *(u8**)(iGpffffb6fc + 0xa10);
                                BtlAction* action = (BtlAction*)FUN_00289650(
                                    0, *(u16*)(*(u8**)(selected + 4) + 2));
                                *(u16*)(selected + 0xa) |= 1;
                                FUN_001fdd40();
                                action->unk_16 = 0x11;
                                FUN_0029a380(action);
                                *(u16*)(iGpffffb6fc + 0xa06) |= 1;
                                stop = 1;
                                FUN_002db2a0(0);
                            }
                            else
                            {
                                *(u16*)(iGpffffb6fc + 0xa04) &= (u16)~1;
                            }
                        }
                        break;
                    case 2:
                    {
                        BtlAction* action = *(BtlAction**)(iGpffffb6fc + 0x148);
                        if (FUN_0029adf0(action) == 0)
                        {
                            action->unk_16 = 0x13;
                            FUN_0029a380(action);
                            stop = 1;
                            *(u16*)(iGpffffb6fc + 0xa04) &= (u16)~2;
                        }
                        break;
                    }
                    case 4:
                    {
                        BtlAction* action = *(BtlAction**)(iGpffffb6fc + 0x148);
                        if (FUN_0029adf0(action) == 0)
                        {
                            action->unk_16 = 7;
                            FUN_0029a380(action);
                            stop = 1;
                            *(u16*)(iGpffffb6fc + 0xa04) &= (u16)~4;
                        }
                        break;
                    }
                    default:
                        break;
                    }
                }
            }
        }
        slotIndex = (slotIndex + 1) & 0xffff;
    }
}

// FUN_002db2a0 NONMATCHING
void FUN_002db2a0(u32 param_1)
{
    u16 threshold;
    u32 index;

    index = param_1 & 0xffff;
    *(u16*)(iGpffffb6fc + 0xa04) |=
        (u16)(1u << index);
    switch (index)
    {
    case 0:
        threshold = (u16)(datCalcRand(2) + 2);
        *(u16*)(iGpffffb6fc + (param_1 & 0xffff) * 4 + 0x9f8) = 0;
        *(u16*)(iGpffffb6fc + (param_1 & 0xffff) * 4 + 0x9fa) = threshold;
        *(u32*)(iGpffffb6fc + 0xa10) = 0;
        break;
    case 1:
        threshold = (u16)(datCalcRand(1) + 2);
        *(u16*)(iGpffffb6fc + (param_1 & 0xffff) * 4 + 0x9f8) = 0;
        *(u16*)(iGpffffb6fc + (param_1 & 0xffff) * 4 + 0x9fa) = threshold;
        break;
    case 2:
        if (datGetFlag(0x140) != 0)
        {
            threshold = (u16)(datCalcRand(2) + 2);
        }
        else if (datGetFlag(0x141) != 0)
        {
            threshold = (u16)(datCalcRand(2) + 3);
        }
        *(u16*)(iGpffffb6fc + (param_1 & 0xffff) * 4 + 0x9f8) = 0;
        *(u16*)(iGpffffb6fc + (param_1 & 0xffff) * 4 + 0x9fa) = threshold;
        break;
    default:
        break;
    }
}

// FUN_002db420
void FUN_002db420(u32 param_1)
{
    u16* flags = (u16*)(iGpffffb6fc + 0xa04);
    *flags &= (u16)~(1u << (param_1 & 0xffff));
}

// FUN_002db450
u32 FUN_002db450(u32 param_1)
{
    return ((u32)*(u16*)(iGpffffb6fc + 0xa04) &
            (1u << (param_1 & 0xffff))) != 0;
}

/* W419 negative: moved FUN_002db480 partySlot before the other u16 locals; nd7 -> 15 at object 456/464 (rate .015351 -> .032895). */
/* W421 classification: baseline verify nd7 at 456/464 (rate 0.015351).
 * These are saved-register role differences, not a commutative swap:
 * +220 ours move $s1,$zero versus retail move $s0,$zero; +232 move
 * $a0,$s0 versus move $a0,$s1; +356 addiu $v0,$s1,1 versus addiu
 * $v0,$s0,1; +360 andi $s1,$v0,0xffff versus andi $s0,$v0,0xffff;
 * +364 andi $s0,$s1,0xffff versus andi $s1,$s0,0xffff; +368 slti
 * $v0,$s0,4 versus slti $v0,$s1,4; +396 bne $s0,$v0 versus bne
 * $s1,$v0.  Scope reorder measured nd16 at 456/464 (rate 0.035088);
 * party-first declaration measured nd15 at 456/464 (rate 0.032895);
 * unit-first variant measured nd118 at 432/464 (rate 0.273148). */
/* W422 split probes: second/first-loop while and party-index alias forms held nd7 at 456/464; first-call pointer alias nd282 at 448/464, shortened missingCount lifetime nd28 at 456/464, early party init nd305 at 456/464, dual-counter typed split nd80 at 448/464. All reverted. */
// FUN_002db480 NONMATCHING
u32 FUN_002db480(void)
{
    u16 enemySlot;
    u16 disabledCount;
    u16 activeCount;
    u16 missingCount;
    u16 partySlot;
    activeCount = 0;
    disabledCount = 0;
    missingCount = 0;
    {

        for (enemySlot = 0; (u32)enemySlot < 3; enemySlot++)
        {
            u8* battle = (u8*)iGpffffb6fc;
            if (*(u8**)(battle + (enemySlot & 0xffff) * 8 + 0xbc4) != NULL &&
                FUN_002FF790(*(u8**)(battle + (enemySlot & 0xffff) * 8 + 0xbc4)) == 0)
            {
                activeCount++;
                if ((*(u16*)(*(u8**)(iGpffffb6fc + (enemySlot & 0xffff) * 8 + 0xbc4) + 0x0a) & 1) != 0)
                {
                    disabledCount++;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    if (activeCount != 0 && activeCount == disabledCount)
    {
        return 2;
    }
    {

        for (partySlot = 0; partySlot < 4; partySlot++)
        {
            s16 pcId = datGetPartyId(partySlot);
            if (pcId != 0)
            {
                BtlUnit* unit = *(BtlUnit**)(iGpffffb6fc + 0x150);
                while (unit != NULL)
                {
                    if (unit->charId == pcId)
                    {
                        break;
                    }
                    unit = unit->next;
                }
                if (unit == NULL)
                {
                    DatUnit* datUnit = datGetUnit(pcId);
                    missingCount++;
                    if (datCalcIsDead(datUnit, 0) == 0)
                    {
                        break;
                    }
                }
            }
        }
        if (missingCount > 0 && partySlot == 4)
        {
            return 3;
        }
    }
    return 1;
}

// FUN_002db650
void FUN_002db650(u32 param_1)
{
    BtlUnit* unit;
    *(u32*)(iGpffffb6fc + 0xa08) = param_1;
    unit = btlUnitFindFromId((u16)param_1);
    *(u16*)(iGpffffb6fc + 0xa0c) = unit->charId;
}

// FUN_002db690
u32 FUN_002db690(void)
{
    return *(u32*)(iGpffffb6fc + 0xa08);
}

// FUN_002db6a0
u32 FUN_002db6a0(void* param_1)
{
    BtlTargetActionWork* work = (BtlTargetActionWork*)param_1;
    s32 result;
    if (work->result == 0)
    {
        work->result = FUN_002daa20(work->action, work->command,
                                    work->param_3, work->param_4,
                                    work->param_5);
    }
    result = work->result;
    if (result == 1 && (work->param_5 & 1) != 0 &&
        ((*(u16*)(iGpffffb6fc + 0xa16) & 1) != 0 ||
         *(u16*)(iGpffffb6fc + 0xa18) != 0))
    {
        result = 0;
    }
    return result;
}

// FUN_002db740
BtlPacket* FUN_002db740(BtlAction* action, u16 command, u32 param_3,
                        u32 param_4, u32 param_5)
{
    BtlPacket* packet = btlPacketCreate(0x800, 0x18);
    BtlTargetActionWork* work;
    packet->updateFunc = FUN_002db6a0;
    work = (BtlTargetActionWork*)packet->workData;
    work->action = action;
    work->command = command;
    work->param_3 = param_3;
    work->param_4 = param_4;
    work->param_5 = param_5;
    work->result = 0;
    return packet;
}

// FUN_002db7d0
u32 FUN_002db7d0(void* param_1)
{
    BtlTargetSimpleWork* work = (BtlTargetSimpleWork*)param_1;
    FUN_002db9f0(work->command, work->param);
    return 1;
}

// FUN_002db800
BtlPacket* FUN_002db800(u16 command, u32 param)
{
    BtlPacket* packet = btlPacketCreate(0x801, 8);
    BtlTargetSimpleWork* work;

    packet->updateFunc = FUN_002db7d0;
    work = (BtlTargetSimpleWork*)packet->workData;
    work->command = command;
    work->param = param;
    return packet;
}

// FUN_002db860
u32 FUN_002db860(void* param_1)
{
    (void)param_1;
    FUN_002dba80();
    return 1;
}

// FUN_002db890
BtlPacket* FUN_002db890(void)
{
    BtlPacket* packet = btlPacketCreate(0x802, 0);
    packet->updateFunc = FUN_002db860;
    return packet;
}

// FUN_002db8d0
void FUN_002db8d0(void)
{
    s32 empty;

    FUN_00521408(iGpffffb6fc + 0x9f8, 0, 0x40);
    *(u32*)(iGpffffb6fc + 0xa1c) = 0;
    empty = -1;
    *(u32*)(iGpffffb6fc + 0xa20) = empty;
    *(s16*)(iGpffffb6fc + 0xa24) = empty;
    *(u32*)(iGpffffb6fc + 0xa28) = empty;
    *(s16*)(iGpffffb6fc + 0xa2c) = empty;
    *(u32*)(iGpffffb6fc + 0xa30) = empty;
    *(s16*)(iGpffffb6fc + 0xa34) = empty;
    *(u16*)(iGpffffb6fc + 0xa18) = 0;
    *(u16*)(iGpffffb6fc + 0xa16) = 0;
    *(u16*)(iGpffffb6fc + 0xa14) = 6;
    *(u16*)(iGpffffb6fc + 0xa36) = 0;
}

// FUN_002db960
void FUN_002db960(void)
{
    FUN_002dad00();
}

// FUN_002db980
void FUN_002db980(void)
{
    HCdvd* cdvd = *(HCdvd**)(iGpffffb6fc + 0xa1c);
    if (cdvd != NULL)
    {
        H_Cdvd_Destroy(cdvd);
        *(HCdvd**)(iGpffffb6fc + 0xa1c) = NULL;
        *(u32*)(iGpffffb6fc + 0x0c) &= 0xfeffffff;
    }
    *(u16*)(iGpffffb6fc + 0xa16) &= (u16)~1;
    func_003c8f20();
}

// FUN_002db9f0
u32 FUN_002db9f0(u16 param_1, u32 param_2)
{
    u32 result;
    u8* base = iGpffffb6fc;
    if ((*(u16*)(base + 0xa16) & 1) != 0)
    {
        if (*(u32*)(base + 0xa20) == param_2)
        {
            result = 1;
            goto done;
        }
        if (*(u32*)(base + 0xa28) == param_2)
        {
            result = 1;
            goto done;
        }
    }
    *(u16*)(base + 0xa2c) = param_1;
    base = iGpffffb6fc;
    *(u32*)(base + 0xa28) = param_2;
    result = 1;
    *(u16*)(iGpffffb6fc + 0xa18) = (u16)result;
done:
    return result;
}

// FUN_002dba60
u32 FUN_002dba60(void)
{
    return (*(u16*)(iGpffffb6fc + 0xa16) & 1) != 0;
}





// FUN_002dba80
void FUN_002dba80(void)
{
    func_003c8f40();
    func_003c8f70();
    *(u16*)(iGpffffb6fc + 0xa18) = 0;
    *(u16*)(iGpffffb6fc + 0xa16) &= (u16)~1;
}

// FUN_002dbac0
void FUN_002dbac0(void)
{
    func_003c8f40();
    func_003c8fa0();
    *(u16*)(iGpffffb6fc + 0xa18) = 0;
    *(u16*)(iGpffffb6fc + 0xa16) &= (u16)~1;
}
#pragma opt_loop_invariants reset
