#include "Battle/btlFormation.h"
#include "Battle/btlAction.h"
#include "Battle/btlFade.h"
#include "Battle/btlUnit.h"
#include "Battle/battle.h"
#include "Battle/btlVoice.h"
#include "Battle/btlBoss.h"

#pragma alias func_002fc520_y2 func_002fc520_y2
#pragma alias FUN_002c09f0_y2 FUN_002c09f0_y2


extern u32 btlFormation002b8c00(void* work);
extern u32 btlFormation002b8dc0(void* work);


typedef u8 undefined1;
typedef u8 bool;
typedef u16 undefined2;
typedef u32 undefined4;
typedef u64 undefined8;
typedef void undefined;
typedef int (*code)(...);
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
extern u64 func_00100ec0();
extern u64 func_001016b0();
extern u32 func_001016b0_u32(u32 param_1);
extern u64 func_00102100();
extern u64 func_001021c0();
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
extern u32 func_0021c3f0(s32 param_1);
extern u32 func_0021c3f0_u32(u32 param_1);
extern u32 func_0021cca0_u32(u32 param_1,u32 param_2);
extern void* func_0021cca0(void* texture, s32 index);
extern u32 func_0021cce0(void* frameData);
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
extern u32 func_002d4e10();
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
extern int func_002f2510(int param_1);
extern void func_002f5030(int param_1);
extern u64 func_002f5320();
extern void func_002f6bf0(u32 param_1);
extern u64 func_002f6c20();
extern u64 func_002fd820();
extern u64 func_002ffbc0();
extern u16 func_002ffbc0_u16(u32 max);
extern u16 func_002ffbc0_noarg(void);
extern u32 func_002ffbc0_noarg_u32(void);
extern u64 func_002ffcc0();
extern u16 func_002ffd70(u32 unit);
extern u16 func_002ffd80(u32 unit);
extern u16 func_002ffdf0(u32 unit);
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
extern u32 func_00306e80();
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
extern void func_003176c0(Model* mdl);
extern u64 func_00317730();
extern void FUN_00317a20(Model* param_1);
extern u64 func_00318ad0();
extern u32 func_00318b90(u32 param_1);
extern u64 func_00318d10();
extern bool func_00318ed0(u8* param_1, u32 param_2, RwV3d* param_3);
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
extern void func_0035c1a0(KwlnTask* task, s32 value);
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
extern u64 func_00523ac8();
extern u32 func_00524270();
extern u32 func_00524388();
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
extern u8* DAT_007ce3ec;
extern u8* DAT_007ce3f8;
extern u8* DAT_007ce41c;
extern u8* DAT_007ce4cc;
extern u8* DAT_007ce4d0;
extern u8* DAT_007ce4e8;
extern u8* DAT_007ce4ec;
extern u32 DAT_007e094e;
extern u32 DAT_007e0952;
extern u32 DAT_007e0958;
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
extern code DAT_00960178_abs[];
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
extern code PTR_FUN_0069721c[];
extern u32 PTR_FUN_00697294[];
extern code PTR_FUN_006972a0[];
extern code PTR_FUN_006972ac[];
extern code PTR_FUN_00697390[];
extern code PTR_FUN_0069739c[];
extern code PTR_FUN_006973a8[];
extern code PTR_FUN_006973cc[];
extern code PTR_FUN_006973d8[];
extern code PTR_FUN_006974d4[];
extern code PTR_FUN_006974e0[];
extern code PTR_FUN_006974ec[];
extern code PTR_FUN_006975e0[];
extern code PTR_FUN_006975e0_abs[];
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
extern u8* iGpffffb6fc;
extern u8* iGpffffb708;
extern u8* iGpffffb7b8;
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
#include "Battle/btlCamera.h"
#include "Kosaka/k_view.h"
#include "Kernel/Kwln/kwln.h"
#include "Main/Battle/Data/datUnit.h"
#include "Graphics/primitive.h"
#include "libm.h"
typedef int (*code)(...);
typedef union Local128 { u64 d[2]; u32 w[4]; } Local128;
typedef struct LocalCameraPacket {
  Local128 flag80;
  Local128 flag20;
  Local128 flag8;
  Local128 flag2;
  Local128 flag1;
  f32 f100;
  f32 f104;
  f32 f108;
  f32 f10c;
  f32 f110;
  f32 f114;
  f32 f118;
  f32 f11c;
  RwV3d center;
} LocalCameraPacket;
extern void FUN_002b0280_legacy(float param_1,u64 param_2,long param_3,long param_4);
u32 FUN_002a32f0(int param_1);
u32 FUN_002a3380(u8* camera);
u32 FUN_002a3420(int param_1);
u8 FUN_002a3520(int param_1);
u64 FUN_002a3550(u8* camera);
u32 FUN_002a3590(float *param_1, float *param_2);
s32 FUN_002a3750(BtlCamera* camera,u32 unit);
extern s16 btlUnit00282c30(BtlUnit* unit);
extern s16 func_002835e0(BtlUnit* unit,u16 id,f32 scale);
extern s16 btlUnitGetAnimFrame(BtlUnit* unit);
u8 FUN_002a3820(int param_1);
extern u32 FUN_002a3820_u32(int param_1);
extern void FUN_004c31b0_typed(RwMatrix *matrix, const RwV3d *axis, f32 angle, s32 mode);
u32 FUN_002a3850(int param_1);
u16 FUN_002a3a80(void);
void FUN_002a3a90(int param_1);
void FUN_002a3e80(float param_1,u8* param_2,u8* param_3,u8* param_4,u32 param_5);
 extern void FUN_002a3e80_ab330(BtlAction* action, RwV3d* unitPos,
                                 f32* targetPos, s32 mode, f32 distance);
extern void FUN_002a3e80_side(BtlAction* action, RwV3d* unitPos,
                              f32* targetPos, f32 distance, s32 mode);
extern u64 FUN_00280050();
extern void FUN_00280050_typed(BtlUnit* unit, RwV3d* out);
extern f32 gp0xffff80e0;
u64 FUN_0027ffb0();
u32 FUN_002a3520_result(int param_1);
extern u32 FUN_002fdbb0_result(BtlAction* action, BtlUnit* persona);
extern f32 fGpffff8090;
extern s32 FUN_002a3520_s32(void);
extern s32 FUN_002a3550_s32(u8* camera);
extern void FUN_002a3e80_action(void* action, u32 arg_1, u32 arg_2, u32 arg_3, u32 arg_4);
void FUN_002a42a0(void);
void FUN_002a4470(f32 *param_1, f32 *param_2);
void FUN_002a44b0(f32 *param_1, f32 *param_2);
void FUN_002a44f0(f32 *param_1, f32 *param_2);
void FUN_002a4530(float *param_1,float *param_2,float *param_3,float *param_4);
void FUN_002a4690(void* out, const void* first, const void* second, const void* config);
void FUN_002a4a70(void);
void FUN_002a4c20(void);
extern f32 DAT_007cae38;
extern f32 DAT_007caf3c;
extern f32 DAT_007caf40;
extern f32 DAT_007caf44;
extern f32 DAT_007caf48;
extern f32 DAT_007caf4c;
extern f32 DAT_007caf50;
extern f32 DAT_007caf54;
extern int iGpffffb710;
extern u16 (*gp0xffffb710)[14];
extern u8 DAT_006941d4[];
extern u8 DAT_00694c90[];
void FUN_002a42a0(void);
void FUN_002a4470(f32 *param_1, f32 *param_2);
void FUN_002a44b0(f32 *param_1, f32 *param_2);
void FUN_002a44f0(f32 *param_1, f32 *param_2);
void FUN_002a4530(float *param_1,float *param_2,float *param_3,float *param_4);
void FUN_002a4690(void* out, const void* first, const void* second, const void* config);
extern u32 FUN_00300580_b6070(void* unitData, u32 flags);
extern void FUN_00280130_b6070(BtlUnit* unit, RwV3d* out);
extern void FUN_004be1e0_b6070(RwV3d* out, const RwV3d* basis, s32 count, const void* source);
extern void FUN_004c31b0_b6070(RwMatrix* matrix, const RwV3d* axis, f32 angle, s32 mode);
extern f32 FUN_004c69f0_b6070(RwV3d* out, const RwV3d* in);
extern void FUN_004c6c60_b6070(RwV3d* out, const RwV3d* in, const RwMatrix* matrix);
extern void FUN_002a4690_b6070(void* out, const void* first, const void* second, const void* config);
extern void FUN_002a2290_b6070(BtlCamera* camera, const RwV3d* start, const RwV3d* end, s32 mode);
extern void FUN_002a3110_b6070(BtlCamera* camera, f32 step);
extern void FUN_002a3160_typed(BtlCamera* camera, f32 step);
void FUN_002a4a70(void);
void FUN_002a4c20(void);
extern f32 DAT_007cae38;
extern f32 DAT_007caf3c;
extern f32 DAT_007caf40;
extern f32 DAT_007caf44;
extern f32 DAT_007caf48;
extern f32 DAT_007caf4c;
extern f32 DAT_007caf50;
extern f32 DAT_007caf54;
extern int iGpffffb710;
extern u16 (*gp0xffffb710)[14];
extern u8 DAT_006941d4[];
extern u8 DAT_00694c90[];
void FUN_002a4a70(void);
void FUN_002a4c20(void);
extern f32 DAT_007cae38;
extern f32 DAT_007caf3c;
extern f32 DAT_007caf40;
extern f32 DAT_007caf44;
extern f32 DAT_007caf48;
extern f32 DAT_007caf4c;
extern f32 DAT_007caf50;
extern f32 DAT_007caf54;
extern int iGpffffb710;
extern u16 (*gp0xffffb710)[14];
extern u8 DAT_006941d4[];
extern u8 DAT_00694c90[];
extern f32 FUN_002d21e0(f32 target, f32* motion);
extern f32 fGpffff807c;
extern f32 fGpffff80e8;
extern u64 FUN_004c6c60(RwV3d* out, RwV3d* in, RwMatrix* matrix);
extern void FUN_002d1de0(void* task, const RwV3d* from, const RwV3d* to);
extern f32 fGpffff83cc;
extern void FUN_002a3010(BtlCamera* camera, f32 step);
extern u32 FUN_002a2ed0(u8* param_1, f32* param_2, f32* param_3);
extern RwV3d D_00697880;
extern RwV3d D_006978A0;
typedef struct F32Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} F32Vec4;
extern RwV3d D_00697870;
extern f32 FUN_002d1fd0(f32* from, f32* to, f32* eye, f32* out);
extern f32 FUN_002d1f30_b21f0v2(RtQuat *first, RtQuat *second);
extern void FUN_00280130_b21f0v2(BtlUnit *unit, RwV3d *out);
extern f32 FUN_004c69f0_b21f0v2(RwV3d *out, RwV3d *in);
extern void FUN_004c6b20_b21f0v2(RwV3d *out, RwV3d *in);
extern void func_002af960(BtlCamera* camera);
extern f32 fGpffff8060;
extern f32 fGpffff8030;
extern f32 fGpffff8134;
extern u8* iGpffffb73c;
extern f32 fGpffff80c0;
extern u32 effMiscRand(void* state);
extern int FUN_00198590();
extern void FUN_004c9d70(int handle, f32 value);
extern void FUN_001a4580(int handle, f32 value);
extern u32 FUN_0048dab0(int, int, u32);
extern f32 fGpffff8064;
extern f32 fGpffff8078;
extern f32 fGpffff8080;
extern f32 fGpffff8084;
extern f32 fGpffff8088;
extern f32 fGpffff80c4;
extern f32 fGpffff811c;
extern void btlUnit002880e0(BtlUnit* unit, u16 param_2);
extern RwV3d D_00697890;
extern u8 D_00697898[];
extern float gp0xffff8070;
extern f32 gp0xffff8030;
extern f32 gp0xffff8094;
extern f32 fGpffff82c8;
extern f32 fGpffff805c;
extern u32 FUN_002a2050(u16* camera, f32* pos, f32* rot);
extern void FUN_002a1e00(f32* out, f32* start, f32* end, f32 t);
extern f32 FUN_00280870(u32 param_1, u32 param_2, void* param_3, void* param_4, void* param_5, u32 param_6);
extern f32 tanf(f32 angle);
extern f32 fGpffff8098;
extern f32 func_00280870_ae740(u32 mode, u32 enabled,
                                f32* start, f32* end, f32* extra,
                                u32 include);
extern void *FUN_002c0880_ae740(u8* data);
extern u32 FUN_002a3850_ae740(BtlCamera* camera);
extern void FUN_004be310_ae740(const RtQuat* first, const RtQuat* second, RwV3d* out);
extern void FUN_004c6b20_ae740(f32* out, f32* in);
extern void FUN_004be1e0_ae740(RwV3d* out, const RwV3d* basis, u32 mode, const void* source);
extern f32 FUN_004c69f0_ae740(RwV3d* out, RwV3d* in);
extern void FUN_00280050_ae740(BtlUnit* unit, RwV3d* out);
extern void FUN_002a2170_ae740(BtlCamera* camera, void* out);
extern void FUN_004be1e0_typed(RwV3d *out, const RwV3d *basis, s32 mode, const void *source);
extern void FUN_004be310_typed(const void *first, const void *second, void *out);
extern void FUN_004c6b20_typed(f32 *out, f32 *in);
extern u8 DAT_006978A0[];
extern u8 DAT_006978A0_arr[];
extern u8 DAT_00697880_arr[];
extern f32 FUN_002d1f30_typed(const f32 *first, const f32 *second);
extern void FUN_002a5430(BtlCamera* camera);
extern void FUN_002a5460(BtlCamera* camera);
extern void btlCameraFrameActionDefault(BtlCamera* camera);
extern void btlCameraFrameActionClose(BtlCamera* camera);
extern void btlCameraFrameActionPair(BtlCamera* camera);
extern void btlCameraFrameActionQuarter(BtlCamera* camera);
extern void btlCameraFrameActionDuel(BtlCamera* camera);
extern void FUN_002a6ed0(void);
extern void btlCameraFrameActionSide(BtlCamera* camera);
extern void func_002a7380(void);
extern void btlCameraFrameActionTarget(BtlCamera* camera);
extern void func_002a7820(void);
extern void func_002ac540(BtlCamera* camera);
extern void func_002ac6e0(BtlCamera* camera);
extern void func_002ad680(BtlCamera* camera);
extern void func_002ad770(BtlCamera* camera);
extern void func_002adc30(BtlCamera* camera);
extern void btlCameraNoop002adc70(void);
extern void func_002adc80(BtlCamera* camera);
extern void btlCameraNoop002adcc0(void);
extern void func_002adcd0(BtlCamera* camera);
extern void func_002ADD00(void);
extern void func_002ae150(BtlCamera* camera);
extern void func_002ae250(void);
extern void func_002ae260(BtlCamera* camera);
extern void func_002ae4c0(void);
extern void func_002ae4d0(BtlCamera* camera);
extern void func_002ae730(void);
extern void func_002af7f0(BtlCamera* camera);
extern void func_002af850(BtlCamera* camera);
extern void func_002af960(BtlCamera* camera);
extern void FUN_002b0210(int param_1);
extern void FUN_002b1020(u64 param_1);
extern void btlCameraNoOp(void);
extern void FUN_002b1bc0(int param_1);
extern void FUN_002b1cf0(int param_1);
extern void FUN_002b1e00(int param_1);
extern void FUN_002b2060(int param_1);
extern void FUN_002b2800(BtlCamera *camera);
extern void FUN_002b2880(int param_1);
extern void FUN_002b2940(void *arg0);
extern void FUN_002b2ea0(void);
extern void FUN_002b32c0(u16* camera);
extern void func_002b3330(void);
extern void FUN_002b3340(BtlCamera* camera);
extern void FUN_002b3680(void);
extern void FUN_002b3690(BtlCamera* camera);
extern void FUN_002b3980(BtlCamera* camera);
extern void FUN_002b3c60(BtlCamera* camera);
extern void FUN_002b3f80(BtlCamera* camera);
extern void FUN_002b41e0(BtlCamera* camera);
extern void FUN_002b4720(int param_1);
extern void FUN_002b47b0(BtlCamera* camera);
extern void FUN_002b4bc0(int param_1);
extern void FUN_002b4c00(int param_1);
extern void FUN_002b4f40(int param_1);
extern void FUN_002b4fd0(void);
extern void FUN_002b5000(int param_1);
extern void FUN_002b5240(BtlCamera* camera);
extern void FUN_002b55d0(void);
extern void FUN_002b5600(void* param_1);
extern void FUN_002b5650(int param_1);
extern void FUN_002b56e0(u8* param_1);
extern void FUN_002b58f0(BtlCamera* param_1);
extern void FUN_002b5cd0(BtlCamera* camera);
extern void FUN_002b6460(BtlCamera* camera);
static const BtlCameraStateEntry sCameraStateEntries[] =
{
    {NULL, NULL, 0, 0, NULL}, // BTLCAMERA_STATE_NULL
    {NULL, NULL, 1, 0, "NOP"}, // NOP
    {FUN_002b3690, NULL, 1, 1, "ENCOUNT"}, // ENCOUNT
    {FUN_002b47b0, NULL, 1, 1, "ANALYZE"}, // ANALYZE
    {(void(*)(BtlCamera*))FUN_002b4bc0, (void(*)(BtlCamera*))FUN_002b4c00, 1, 1, "ASSIST"}, // ASSIST
    {FUN_002b41e0, (void(*)(BtlCamera*))FUN_002b4720, 1, 1, "REINFORCE"}, // REINFORCE
    {(void(*)(BtlCamera*))FUN_002b4f40, (void(*)(BtlCamera*))FUN_002b4fd0, 1, 1, "ROUNDUP"}, // ROUNDUP
    {(void(*)(BtlCamera*))FUN_002b5000, NULL, 1, 1, "ESCAPE"}, // ESCAPE
    {FUN_002b5240, NULL, 1, 1, "ESCAPE_MES"}, // ESCAPE_MES
    {FUN_002a5430, FUN_002a5460, 1, 1, "OWN"}, // OWN
    {func_002af960, (void(*)(BtlCamera*))FUN_002b0210, 1, 1, "ATTACK_SHORT"}, // ATTACK_SHORT
    {(void(*)(BtlCamera*))FUN_002b1020, (void(*)(BtlCamera*))btlCameraNoOp, 1, 1, "ATTACK_LONG"}, // ATTACK_LONG
    {(void(*)(BtlCamera*))FUN_002b1e00, (void(*)(BtlCamera*))FUN_002b2060, 1, 1, "ATTACK_DOWN_P"}, // ATTACK_DOWN_P
    {FUN_002b2800, (void(*)(BtlCamera*))FUN_002b2880, 1, 1, "ATTACK_DOWN_E"}, // ATTACK_DOWN_E
    {(void(*)(BtlCamera*))FUN_002b2940, (void(*)(BtlCamera*))FUN_002b2ea0, 1, 1, "ATTACK_SLIP"}, // ATTACK_SLIP
    {(void(*)(BtlCamera*))FUN_002b1bc0, (void(*)(BtlCamera*))FUN_002b1cf0, 1, 1, "ATTACK_COMB"}, // ATTACK_COMB
    {btlCameraFrameActionDefault, btlCameraFrameActionClose, 1, 1, "SKILL_RECITE_P"}, // SKILL_RECITE_P
    {btlCameraFrameActionPair, btlCameraFrameActionQuarter, 1, 1, "SKILL_RECITE_E"}, // SKILL_RECITE_E
    {btlCameraFrameActionDuel, (void(*)(BtlCamera*))FUN_002a6ed0, 1, 1, "MOVE_TARGET"}, // MOVE_TARGET
    {btlCameraFrameActionSide, (void(*)(BtlCamera*))func_002a7380, 1, 1, "MOVE_TARGET_A"}, // MOVE_TARGET_A
    {btlCameraFrameActionTarget, (void(*)(BtlCamera*))func_002a7820, 1, 1, "MOVE_HOME"}, // MOVE_HOME
    {func_002ac540, func_002ac6e0, 1, 1, "SKILL_EXEC_PC"}, // SKILL_EXEC_PC
    {func_002ad680, func_002ad770, 1, 1, "SKILL_EXEC_EC"}, // SKILL_EXEC_EC
    {func_002adc30, (void(*)(BtlCamera*))btlCameraNoop002adc70, 1, 0, "SKILL_EXEC_ONE"}, // SKILL_EXEC_ONE
    {func_002adc80, (void(*)(BtlCamera*))btlCameraNoop002adcc0, 1, 0, "SKILL_EXEC_REC"}, // SKILL_EXEC_REC
    {func_002adcd0, (void(*)(BtlCamera*))func_002ADD00, 1, 1, "SKILL_EXEC_PS"}, // SKILL_EXEC_PS
    {func_002ae260, (void(*)(BtlCamera*))func_002ae4c0, 1, 1, "PERSONA"}, // PERSONA
    {func_002ae4d0, (void(*)(BtlCamera*))func_002ae730, 1, 1, "OVERLIMIT"}, // OVERLIMIT
    {func_002ae150, (void(*)(BtlCamera*))func_002ae250, 0, 1, "COMMAND"}, // COMMAND
    {func_002af7f0, func_002af850, 0, 1, "TARGET"}, // TARGET
    {(void(*)(BtlCamera*))FUN_002b32c0, (void(*)(BtlCamera*))func_002b3330, 0, 1, "FREE"}, // FREE
    {FUN_002b3340, (void(*)(BtlCamera*))FUN_002b3680, 0, 1, "RESET"}, // RESET
    {FUN_002b3980, NULL, 1, 0, "WIN"}, // WIN
    {FUN_002b3c60, NULL, 1, 0, "CONDITION"}, // CONDITION
    {FUN_002b3f80, NULL, 1, 1, "ORDER"}, // ORDER
    {(void(*)(BtlCamera*))FUN_002b55d0, (void(*)(BtlCamera*))FUN_002b5600, 0, 1, "CHANGE FORM"}, // CHANGE FORM
    {(void(*)(BtlCamera*))FUN_002b5650, (void(*)(BtlCamera*))FUN_002b56e0, 0, 1, "NYX FEATHER"}, // NYX FEATHER
    {FUN_002b58f0, NULL, 1, 0, "ALL"}, // ALL
    {FUN_002b5cd0, NULL, 1, 0, "ENEMY_ALL"}, // ENEMY_ALL
    {FUN_002b6460, NULL, 1, 0, "TARGET_ONLY"}, // TARGET_ONLY
};
extern void FUN_002a2290(u16* camera, RwV3d* first, RwV3d* second, int mode);
extern void FUN_002a3110(u16* camera, f32 param_1);
extern f32 FUN_002d1f30(f32* left, f32* right);
extern u32 FUN_00351bb0(u16 param_1);
extern void FUN_004be310(float *param_1, float *param_2, float *param_3);
extern float FUN_004c6b20(float *param_1, float *param_2);
extern f32 FUN_0052e930(f32 x);
extern void FUN_002b6460(BtlCamera* camera);
extern f32 fGpffff812c;
typedef struct BtlCameraQuatBlend
{
    RtQuat first;
    RtQuat second;
    f32 scalar;
    s32 flag;
} BtlCameraQuatBlend;
extern void FUN_0027f7c0(BtlUnit* unit, RwV3d* out, void* p3, void* p4);
extern RwV3d D_00697880;
extern float fGpffff8094;
extern float fGpffff8070;
extern void FUN_004bdde0(f32* quat, const f32* axis, f32 angle, s32 mode);
extern RwV3d D_006978A0;
extern f32 fGpffff80f0;
extern f32 fGpffff80f4;
extern f32 fGpffff80f8;
extern f32 fGpffff8138;
extern f32 fGpffff8130;
extern f32 fGpffff8048;
extern f32 fGpffff8118;
extern f32 fGpffff8050;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern u16 FUN_002d1600(int);
extern u32 FUN_002d6290(int);
extern u32 FUN_002d62d0(int);
extern u32 FUN_002d6370(s16);
extern u32 FUN_002d63b0(int, s16, int);
typedef struct BtlCameraTargetingWork
{
    BtlCameraKeyFrame first;
    RwV3d secondPos;
    RtQuat secondRot;
    u8 pad_38[8];
    RwMatrix matrix;
    u8 pad_7c[4];
    u8 pad_80[4];
    struct
    {
        u64 xy;
        f32 y;
        f32 z;
    } targetPos;
    f32 horiz[2];
    RwV3d candidate;
    u8 pad_9c[4];
    RwV3d sidePoint;
    u8 pad_ac[4];
    RwV3d diff;
    u8 pad_bc[4];
    RwV3d direction;
    u8 pad_cc[4];
    RwV3d desired;
    u8 pad_dc[4];
    RwV3d generated;
    u8 pad_ec[4];
    RwV3d sphereCenter;
    f32 radius;
} BtlCameraTargetingWork;
typedef u8 undefined1;
typedef u16 undefined2;
typedef u32 undefined4;
typedef u64 undefined8;
typedef void undefined;
#define CONCAT44(hi, lo) ((((u64)(hi)) << 32) | (u32)(lo))
extern u64 FUN_0019d400();
extern u32 FUN_0027ec10();
extern u64 FUN_0027f650();
extern u64 FUN_0027f680();
extern u64 FUN_0027f940();
extern u64 FUN_00280050();
extern u64 FUN_00280130();
extern u64 FUN_00280200();
extern u64 FUN_002802d0();
extern u64 FUN_00280390();
extern u64 FUN_00281270();
extern u64 FUN_00281290();
extern u64 FUN_002812b0();
extern s16 FUN_002835e0(BtlUnit* unit, u16 id, f32 scale);
extern s16 FUN_00284040();
extern void FUN_00288110(BtlUnit* unit);
extern int FUN_00288da0(int param_1, short param_2);
extern u64 FUN_0029a1d0();
extern void FUN_002a2170(u16 *param_1, f32 *param_2);
extern void FUN_002a2660(BtlCamera* camera, BtlCameraKeyFrame* first,
                         BtlCameraKeyFrame* second, BtlCameraKeyFrame* third,
                         BtlCameraKeyFrame* fourth, int mode);
extern u64 FUN_002add10();
extern void FUN_002d1de0(void* task, const RwV3d* from, const RwV3d* to);
extern f32 FUN_002d1f30(f32* left, f32* right);
extern void FUN_002d2280(s16* outX, s16* outZ, f32* position);
extern u32 FUN_002d4040(BtlUnit* unit);
extern u16 FUN_002d4e10(u16 mask, u32 badStatus);
extern u32 FUN_002d5bf0(BtlUnit* unit);
extern s16 FUN_002f8eb0(BtlUnit* unit, s16 index);
extern u64 FUN_002fa240();
extern u32 FUN_002fdcf0(int param_1, int param_2);
extern u32 FUN_002ffbc0();
extern u64 FUN_00300580();
extern u8 FUN_00308c60();
extern u64 FUN_00308a50(u16 param_1);
extern u8 FUN_003093a0(u16 *param_1);
extern u64 FUN_0030b5a0();
extern u32 FUN_0030c3a0(u16 *param_1);
extern u64 FUN_004be1e0();
extern u64 FUN_004c31b0();
extern float FUN_004c69f0();
extern float FUN_004c6ac0();
extern float FUN_004c6af0(float *param_1);
extern u64 FUN_004c6c60();
extern u64 FUN_00521250();
extern u64 FUN_00521408();
extern u64 FUN_00523ac8();
extern u32 DAT_007ce404;
extern void LAB_002b8970(u32 *work);
extern void LAB_002b8b50(u32 *work);
extern u8 DAT_006944b0[];
extern u8 DAT_006945b0[];
extern u8 DAT_006946a4[];
extern u8 DAT_00694798[];
extern u8 DAT_00694890[];
extern u8 DAT_00694990[];
extern u8 DAT_00694a90[];
extern u8 DAT_00694b90[];
extern u8 DAT_00694c90[];
extern u8 DAT_00694d90[];
extern RwV3d D_00694E90;
extern f32 D_00694E9C[3];
extern RwV3d D_00694EA0;
extern RwV3d D_00694EA4;
extern RwV3d D_00694ED0;
extern RwV3d D_00694ED4;
extern RwV3d D_00694ED8;
extern RwV3d D_00694EDC;
extern RwV3d D_00694EE0;
extern RwV3d D_00694EE4;
extern u8 DAT_00694fe8;
extern u8 D_00694F10[];
extern u8 D_00696410[];
extern u8 D_00696430[];
extern u8 DAT_00694fea;
extern u8 DAT_00694fec;
extern u32 DAT_00697880;
extern f32 DAT_00697888;
extern float DAT_007cad20;
extern float DAT_007cad38;
extern float DAT_007cad40;
extern float DAT_007cad44;
extern float DAT_007cad48;
extern float DAT_007cad5c;
extern float DAT_007cad60;
extern float DAT_007cad64;
extern float DAT_007cad68;
extern float DAT_007cad6c;
extern float DAT_007cad74;
extern float DAT_007cad7c;
extern float DAT_007cad84;
extern float DAT_007cad88;
extern float DAT_007cad94;
extern float DAT_007cada4;
extern float DAT_007cadb4;
extern float DAT_007cadc4;
extern float DAT_007cadd0;
extern float DAT_007cadf0;
extern float DAT_007cadf4;
extern float DAT_007cae08;
extern float DAT_007cae20;
extern float DAT_007cae2c;
extern float fGpffff8048;
extern float fGpffff8050;
extern float fGpffff8054;
extern float fGpffff8058;
extern float fGpffff806c;
extern float fGpffff8070;
extern float fGpffff8088;
extern float fGpffff8094;
extern float fGpffff8098;
extern float fGpffff809c;
extern float fGpffff80b4;
extern float fGpffff80c4;
extern float fGpffff80d4;
extern f32 fGpffff80b4;
extern float fGpffff8114;
extern float fGpffff8118;
extern f32 uGpffff808c;
extern f32 uGpffff80fc;
extern f32 uGpffff8100;
extern u32 uGpffff8140;
extern f32 fGpffff80e0;
extern f32 fGpffff813c;
extern u8 D_00694EB0[];
extern u8 D_00694EBC[];
extern u8 D_00694EF0[];
extern u8 D_00694EFC[];
extern u32 FUN_002b64d0(BtlCamera* camera, struct B64CameraWork* work);
extern u32 FUN_002b6bd0(int param_1);
extern void FUN_002b6bf0(undefined4 *param_1, undefined4 param_2, undefined4 param_3, u32 param_4, u16 param_5);
extern u8* FUN_002b6cd0(int param_1);
extern void FUN_002b6de0(unsigned short *param_1);
typedef struct BtlCameraPoseLocal {
  RwV3d pos;
  RtQuat rot;
} BtlCameraPoseLocal;
extern void FUN_002a4470_b280(BtlCameraPoseLocal* dst,
                              const BtlCameraPoseLocal* src);
extern void FUN_0027ffb0_b280(BtlUnit* unit, RwV3d* dst);
extern void FUN_002a4690_b280(RtQuat* out, const RwV3d* first,
                              const RwV3d* second, const RwV3d* config);
extern void FUN_004be1e0_b280(RwV3d* out, const RwV3d* basis,
                              s32 count, const RtQuat* source);
extern f32 FUN_004c69f0_b280(RwV3d* out, const RwV3d* in);
extern void FUN_004c6b20_b280(f32* out, const f32* in);
extern f32 FUN_002d1fd0_b280(f32* from, f32* to, f32* point, f32* projected);
extern f32 FUN_002d1f30_b280(RtQuat* first, RtQuat* second);
extern void FUN_002a2170_b280(BtlCamera* camera, RwV3d* out);
extern void FUN_002a2290_b280(BtlCamera* camera, RwV3d* start,
                              RwV3d* end, s32 mode);
extern void FUN_002a3110_b280(BtlCamera* camera, f32 step);
extern void FUN_002a3e80_b280(f32 distance, u8* scene, u8* unit,
                              u8* center, u32 mode);
extern s32 FUN_002d5bf0_b280(BtlUnit* unit);
extern s32 FUN_003093a0_b280(u32 data);
extern f32 FUN_0052e930_b280(f32 angle);
extern u8 DAT_00693d10[];
extern void FUN_002b4db0_float(float);
#undef sp40
#undef sp44
#undef sp48
#undef sp4C
#undef sp50
#undef sp54
#undef sp58
#undef sp5C
#undef sp60
#undef sp64
#undef sp68
#undef sp80
#undef spC8
#undef spCC
#undef spD0
#undef spD4
#undef spD8
#undef spE0
#undef spE4
#undef spE8
#undef spF0
#undef spF4
#undef spF8
#undef sp100
#undef sp104
#undef sp108
#undef sp110
#undef sp114
#undef sp118
typedef struct B64CameraWork {
  BtlAction *firstAction;
  BtlAction *secondAction;
  u16 unk_08;
  s16 index;
  u16 frame;
  u16 flags;
  u16 *entries;
} B64CameraWork;
typedef struct B64CameraEntry {
  s16 duration;
  u16 mode;
  f32 firstX;
  f32 firstY;
  f32 firstZ;
  f32 firstX2;
  f32 firstY2;
  f32 firstZ2;
  u16 targetMode;
  u16 pad_1e;
  f32 secondX;
  f32 secondY;
  f32 secondZ;
  f32 secondX2;
  f32 secondY2;
  f32 secondZ2;
  f32 angle;
} B64CameraEntry;
typedef struct B64CameraScratch {
  RwV3d firstOut;
  RwV3d secondOut;
  u8 pad_18[8];
  RwV3d rotatedFirst;
  RwV3d rotatedSecond;
  u8 pad_38[8];
  RtQuat rotation;
  RwMatrix matrix;
  RwV3d firstPos;
  u8 firstResult[16];
  RwV3d secondPos;
  u8 secondResult[24];
  RwV3d relativeSecond;
  u8 pad_dc[4];
  RwV3d relativeFirst;
  u8 pad_ec[4];
  u64 matrixLow;
  f32 matrixHigh;
  u8 pad_fc[4];
  RwV3d firstVector;
  u8 pad_10c[4];
  RwV3d secondVector;
  u8 pad_11c[4];
  RwV3d sphereBase;
  u8 pad_12c[4];
  RwV3d sphereVector;
  u8 pad_13c[4];
} B64CameraScratch;
extern void FUN_002d1de0_b64d0(RtQuat *out, const RwV3d *from, const RwV3d *to);
extern void FUN_002802d0_b64d0(BtlUnit *first, BtlUnit *second, RwV3d *out);
extern void FUN_004be1e0_b64d0(RwV3d *out, const RwV3d *in, s32 count, const RtQuat *rotation);
extern void FUN_00280130_b64d0(BtlUnit *unit, RwV3d *out);
extern void FUN_00280200_b64d0(BtlUnit *unit, BtlUnitAnimBounds *bounds, RwV3d *out);
extern void FUN_004c6c60_b64d0(void *out, const RwV3d *in, const RwMatrix *matrix);
extern BtlUnitAnimBounds *func_002fc520_y2(BtlUnit *unit);
extern u32 FUN_002b6bd0_b64d0(struct B64CameraWork* work);
extern void FUN_002a2290_b64d0(BtlCamera* camera, RwV3d* first,
                                RwV3d* second, s32 mode);
extern void FUN_002a3110_b64d0(BtlCamera* camera, f32 step);
#define BTLCAMERA_GHIDRA_PAIR
typedef u8 u8;
typedef u8 byte;
typedef unsigned short ushort;
typedef union BtlCameraGhidraPair
{
    struct { f32 _0_4_; f32 _4_4_; } f;
    u64 raw;
} BtlCameraGhidraPair;
#define GhidraPair BtlCameraGhidraPair
#define PAIR44(hi, lo) ((GhidraPair){{(lo), (hi)}})
extern f32 DAT_007cad3c;
extern f32 DAT_007cad54;
extern f32 DAT_007cad98;
extern f32 DAT_007cadb0;
extern f32 DAT_007caddc;
extern f32 DAT_007cade0;
extern f32 DAT_007cade4;
extern f32 DAT_007cade8;
extern f32 DAT_007cadfc;
extern f32 DAT_007cae00;
extern f32 DAT_007cae04;
extern f32 DAT_007cae0c;
extern f32 DAT_007cae10;
extern f32 DAT_007cae14;
extern f32 DAT_007cae18;
extern f32 DAT_007cae24;
extern f32 fGpffff8030;
extern f32 fGpffff807c;
extern f32 fGpffff80a0;
extern f32 fGpffff80a4;
extern f32 fGpffff80a8;
extern f32 fGpffff80b0;
extern f32 fGpffff80b8;
extern f32 fGpffff80bc;
extern u32 uGpffff8074;
extern u32 uGpffff809c;
extern u32 uGpffff80ac;
extern void func_00280050(void* param_1, RwV3d* param_2);
extern u8* iGpffffb73c;
typedef struct BtlCameraC920Pose
{
    RwV3d pos;
    RtQuat rot;
} BtlCameraC920Pose;
typedef struct BtlCameraC920Pair
{
    f32 first;
    f32 second;
} BtlCameraC920Pair;
typedef struct BtlCameraC920Work
{
    BtlCameraC920Pose cameraPose;
    BtlCameraC920Pose desiredPose;
    RwV3d sourceCenter;
    RwV3d targetCenter;
    RwV3d direction;
    RwV3d firstPoint;
    RwV3d secondPoint;
    RwV3d basePoint;
    BtlCameraC920Pair cameraHorizontal;
    BtlCameraC920Pair projectionFrom;
    BtlCameraC920Pair projectionTo;
    BtlCameraC920Pair projectionOutput;
    f32 f2;
    f32 f7;
    f32 f8;
    f32 f9;
    f32 f11;
    f32 f12;
    f32 f13;
    f32 projectionDistance;
    f32 step;
} BtlCameraC920Work;
extern void FUN_002a4470_c920(BtlCameraC920Pose* dst,
                               const BtlCameraC920Pose* src);
extern void FUN_002a44f0_c920(BtlCameraC920Pose* dst,
                               const BtlCameraC920Pose* src);
extern void FUN_002a2290_c920(BtlCamera* camera, const RwV3d* start,
                               const RwV3d* end, s32 mode);
extern void FUN_002a3110_c920(BtlCamera* camera, f32 step);
typedef struct BtlCameraFramingPoseLocal {
  RwV3d pos;
  RtQuat rot;
} BtlCameraFramingPoseLocal;
typedef struct BtlCameraFramingWork {
  f32 fStack_140;
  f32 fStack_13c;
  f32 fStack_138;
  f32 fStack_134;
  f32 fStack_130;
  f32 fStack_12c;
  f32 fStack_128;
  f32 fStack_124;
  f32 fStack_120;
  int iStack_11c;
  f32 fStack_110;
  f32 fStack_10c;
  f32 fStack_108;
  Local128 auStack_104;
  f32 fStack_f4;
  f32 fStack_f0;
  f32 fStack_ec;
  struct {
    Local128 quat;
    f32 aux0;
    f32 aux1;
  } auStack_e8;
  BtlCameraFramingPoseLocal auStack_d0;
  f32 fStack_b4;
  f32 fStack_b0;
  f32 fStack_ac;
  f32 fStack_a8;
  f32 fStack_a4;
  f32 fStack_a0;
  f32 fStack_9c;
  f32 fStack_90;
  f32 fStack_8c;
  f32 fStack_88;
  f32 fStack_80;
  f32 fStack_7c;
  f32 fStack_78;
  f32 fStack_70;
  f32 fStack_6c;
  f32 fStack_68;
  f32 fStack_64;
  f32 fStack_60;
  f32 fStack_58;
  f32 fStack_54;
  f32 fStack_50;
  f32 fStack_48;
  f32 fStack_44;
  f32 fStack_40;
  f32 fStack_38;
  f32 fStack_34;
  f32 fStack_30;
  f32 fStack_28;
  f32 fStack_24;
  f32 fStack_20;
  f32 fStack_18;
  f32 fStack_14;
  f32 fStack_10;
  f32 auStack_8;
  f32 fStack_4;
} BtlCameraFramingWork;
extern u16 FUN_002bff60(int action, int target, u16 commandId, u32 param_4);
extern u16 FUN_002c09f0_y2(int target);

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
static BtlUnit* btlCameraRangeUnit(BtlCamera* camera)
{
    if (camera == NULL || camera->action == NULL)
    {
        return NULL;
    }
    return camera->action->unit;
}
static BtlUnit* btlCameraRangeTarget(BtlCamera* camera)
{
    BtlAction* target;
    if (camera == NULL || camera->action == NULL)
    {
        return NULL;
    }
    target = camera->action->target.targetedActions[0];
    return target != NULL ? target->unit : NULL;
}
static void btlCameraRangeCross(RwV3d* out, const RwV3d* a, const RwV3d* b)
{
    out->x = a->y * b->z - a->z * b->y;
    out->y = a->z * b->x - a->x * b->z;
    out->z = a->x * b->y - a->y * b->x;
}
static void btlCameraRangeLookAt(BtlCamera* camera, const RwV3d* eye,
                                 const RwV3d* target)
{
    RwV3d at;
    RwV3d upAxis;
    RwV3d right;
    RwV3d up;
    RwMatrix matrix;

    at.x = target->x - eye->x;
    at.y = target->y - eye->y;
    at.z = target->z - eye->z;
    if (RwV3dNormalize(&at, &at) <= 0.0001f)
    {
        at.x = 0.0f;
        at.y = 0.0f;
        at.z = 1.0f;
    }
    upAxis.x = 0.0f;
    upAxis.y = 1.0f;
    upAxis.z = 0.0f;
    btlCameraRangeCross(&right, &upAxis, &at);
    if (RwV3dNormalize(&right, &right) <= 0.0001f)
    {
        upAxis.x = 0.0f;
        upAxis.y = 0.0f;
        upAxis.z = 1.0f;
        btlCameraRangeCross(&right, &upAxis, &at);
        RwV3dNormalize(&right, &right);
    }
    btlCameraRangeCross(&up, &at, &right);
    RwV3dNormalize(&up, &up);
    matrix.right = right;
    matrix.up = up;
    matrix.at = at;
    matrix.pos = *eye;
    matrix.pad1 = matrix.pad2 = matrix.pad3 = 0;
    rwMatrixSetFlags(&matrix, rwMATRIXTYPEORTHONORMAL);
    camera->pos = *eye;
    RtQuatConvertFromMatrix(&camera->rot, &matrix);
}
static void btlCameraRangeFrame(BtlCamera* camera, const RwV3d* first,
                                const RwV3d* second, f32 margin, f32 minimum)
{
    RwV3d center;
    RwV3d delta;
    RwV3d direction;
    RwV3d eye;
    f32 radius;
    f32 distance;

    if (camera == NULL || first == NULL)
    {
        return;
    }
    if (second != NULL)
    {
        center.x = (first->x + second->x) * 0.5f;
        center.y = (first->y + second->y) * 0.5f;
        center.z = (first->z + second->z) * 0.5f;
        delta.x = second->x - first->x;
        delta.y = second->y - first->y;
        delta.z = second->z - first->z;
        radius = RwV3dLength(&delta) * 0.5f;
    }
    else
    {
        center = *first;
        radius = 0.0f;
    }
    radius += 100.0f;
    distance = radius * (margin < 1.0f ? 1.0f : margin);
    if (distance < minimum)
    {
        distance = minimum;
    }
    direction.x = camera->pos.x - center.x;
    direction.y = camera->pos.y - center.y;
    direction.z = camera->pos.z - center.z;
    if (RwV3dNormalize(&direction, &direction) <= 0.0001f)
    {
        direction.x = 0.0f;
        direction.y = 0.25f;
        direction.z = 1.0f;
        RwV3dNormalize(&direction, &direction);
    }
    eye.x = center.x + direction.x * distance;
    eye.y = center.y + direction.y * distance;
    eye.z = center.z + direction.z * distance;
    btlCameraRangeLookAt(camera, &eye, &center);
    camera->keyFrameIdx = 0;
    camera->keyFrames[0].pos = eye;
    camera->keyFrames[0].rot = camera->rot;
    camera->framesUntilUpdate = 0;
    if (camera->fovRad <= 0.01f)
    {
        camera->fovRad = 0.7853982f;
    }
}
static void btlCameraRangeActionFrame(BtlCamera* camera, f32 margin,
                                      f32 minimum, u32 includeTarget)
{
    BtlUnit* unit;
    BtlUnit* target;
    RwV3d first;
    RwV3d second;

    unit = btlCameraRangeUnit(camera);
    if (unit == NULL)
    {
        return;
    }
    btlUnitGetSphereWorldCenter(unit, (RwV3d*)&first);
    target = includeTarget != 0 ? btlCameraRangeTarget(camera) : NULL;
    if (target != NULL && target != unit)
    {
        btlUnitGetSphereWorldCenter(target, (RwV3d*)&second);
        btlCameraRangeFrame(camera, &first, &second, margin, minimum);
    }
    else
    {
        btlCameraRangeFrame(camera, &first, NULL, margin, minimum);
    }
}

// FUN_002b7060
#pragma opt_loop_invariants on
s16 FUN_002b7060(void)
{
  u16 vals[3];
  char buf[264];
  u16 candidateIdx;
  u16 selectedIdx;
  u32 entryIdx;
  u8 *entry;

  if (FUN_002fa240() == 1) {
    return -1;
  }
  FUN_002b6de0(vals);
  if (((3 < vals[2]) || ((vals[2] == 3 && ((0 < vals[1] || (0 < vals[0])))))) ||
     ((vals[2] == 2 && ((1 < vals[1] || (2 < vals[0])))))) {
    FUN_00523ac8(buf,D_00696410,*(u16 *)(*(int *)(iGpffffb6fc + 0xbbc) + 8),vals[2]
                 ,vals[1],vals[0]);
    FUN_0019d400(buf,D_00696430,0x16e);
  }
  for (entryIdx = 0; (u32)(u16)entryIdx < 0x18;
       entryIdx = (u16)(entryIdx + 1)) {
    candidateIdx = (u16)entryIdx;
    entry = D_00694F10 + (u16)candidateIdx * 0xe0;
    if (vals[0] > *(u16 *)(entry + 0xd8)) continue;
    if (vals[1] > *(u16 *)(entry + 0xda)) continue;
    if (vals[2] > *(u16 *)(entry + 0xdc)) continue;
    selectedIdx = candidateIdx;
    goto done;
  }
  selectedIdx = 0x17;
done:
  return (s16)selectedIdx;
}

#pragma opt_loop_invariants off


/* W367 measured: opt_lifetimes on nd639 -> 635, object 1484/1484; baseline object 1484/1484. */
#pragma opt_lifetimes on
// FUN_002b71e0 NONMATCHING

void FUN_002b71e0(void)
{
    struct
    {
        s8 message[0x100];
        RtQuat quat;
        u32 used[5];
        u8 pad1[4];
        u16 vals[4];
        RwV3d worldA;
        u8 pad2[4];
        RwV3d worldB;
        u8 pad3[4];
        f32 tmp[4];
    } work;
    u16 selected;
    u16 nextSlot;
    BtlUnit* iter;
    BtlUnit* iter2;
    u16 slot;
    s64 result;
    u8* table;
    u16 battleId;
    BtlUnit* unit;
    u32 i;
    f32 minX;
    f32 minZ;
    f32 dx;
    f32 dz;
    f32 scale;

    work.tmp[1] = 0.0f;
    *(s16*)(DAT_007ce3ec + 0xa38) = -1;
    if (FUN_002fa240() == 1)
    {
        result = -1;
    }
    else
    {
        FUN_002b6de0(work.vals);
        if (work.vals[2] > 3 ||
            (work.vals[2] == 3 && ((s32)work.vals[1] > 0 || (s32)work.vals[0] > 0)) ||
            (work.vals[2] == 2 && (work.vals[1] > 1 || work.vals[0] > 2)))
        {
            battleId = *(u16*)(*(u8**)(DAT_007ce3ec + 0xbbc) + 8);
            FUN_00523ac8(work.message, D_00696410,
                         battleId, work.vals[2], work.vals[1], work.vals[0]);
            FUN_0019d400_b71e0(work.message, D_00696430, 0x16e);
        }
        result = (s16)FUN_002b6f70(work.vals);
    }
    if ((s64)(s16)result != -1)
    {
        FUN_00521408_b71e0(DAT_007ce3ec + 0xa3c, 0, 0x24);
        slot = 1;
        iter = *(BtlUnit**)(DAT_007ce3ec + 0x150);
        table = D_00694F10 + (s16)result * 0xe0;
        for (; iter != NULL; iter = iter->next)
        {
                unit = *(BtlUnit**)(*(u8**)(DAT_007ce3ec + 0x148) + 0x30);
                if (unit == iter)
                {
                    nextSlot = slot;
                    slot = 0;
                }
                else
                {
                    while (*(u8*)(table + (u32)slot * 0x18) == 0 && slot < 4)
                    {
                        slot = (u16)(slot + 1);
                    }
                    nextSlot = (u16)(slot + 1);
                }
                selected = slot;
                work.tmp[0] = *(f32*)(table + (u32)selected * 0x18 + 4);
                work.tmp[2] = *(f32*)(table + (u32)selected * 0x18 + 8);
                FUN_002d2280_b71e0(&iter->unk_94, &iter->unk_96, (RwV3d*)work.tmp);
                work.tmp[0] = (f32)(iter->unk_94 * 0x19 - 0x6d6);
                work.tmp[2] = (f32)(iter->unk_96 * 0x19 - 0x6d6);
                FUN_0027f650_b71e0(iter, (RwV3d*)work.tmp);
                if (iter->genus == 1)
                {
                    *(u32*)(DAT_007ce3ec + (u32)selected * 4 + 0xa4c) = 1;
                }
                else if (iter->genus == 0)
                {
                    *(u32*)(DAT_007ce3ec + (u32)selected * 4 + 0xa3c) = 1;
                }
                iter->unk_9f0 = (s8)slot;
                slot = nextSlot;
            }
        iter2 = *(BtlUnit**)(DAT_007ce3ec + 0x158);
        FUN_00521408_b71e0(work.used, 0, 0x14);
            for (; iter2 != NULL; iter2 = iter2->next)
            {
                if (FUN_0030b5a0_b71e0(iter2->datUnit, 0) == 0)
                {
                    selected = 5;
                    minX = 100000000.0f;
                    minZ = minX;
                    scale = iter2->scale;
                    for (i = 0; i < 5; i = (i + 1) & 0xffff)
                    {
                        if (work.used[i] != 1 &&
                            *(u8*)(table + i * 0x18 + 0x60) != 0)
                        {
                            dx = *(f32*)(table + i * 0x18 + 0x70) -
                                 iter2->sphereRadius * scale;
                            dz = *(f32*)(table + i * 0x18 + 0x74) -
                                 iter2->unk_8c * scale;
                            if (dx < minX || dz < minZ)
                            {
                                minX = dx;
                                minZ = dz;
                                selected = (u16)i;
                            }
                        }
                    }
                    work.used[selected] = 1;
                    work.tmp[0] = *(f32*)(table + (u32)selected * 0x18 + 0x64);
                    work.tmp[2] = *(f32*)(table + (u32)selected * 0x18 + 0x68);
                    FUN_002d2280_b71e0(&iter2->unk_94, &iter2->unk_96, (RwV3d*)work.tmp);
                    work.tmp[0] = (f32)(iter2->unk_94 * 0x19 - 0x6d6);
                    work.tmp[2] = (f32)(iter2->unk_96 * 0x19 - 0x6d6);
                    FUN_0027f650_b71e0(iter2, (RwV3d*)work.tmp);
                    if (iter2->genus == 1)
                    {
                        *(u32*)(DAT_007ce3ec + (u32)selected * 4 + 0xa4c) = 1;
                    }
                    else if (iter2->genus == 0)
                    {
                        *(u32*)(DAT_007ce3ec + (u32)selected * 4 + 0xa3c) = 1;
                    }
                    iter2->unk_9f0 = (s8)selected;
                }
            }
        FUN_00280870(2, 1, &work.worldA, 0, 0, 1);
        FUN_0027ffb0_b71e0(*(BtlUnit**)(*(u8**)(DAT_007ce3ec + 0x148) + 0x30),
                     &work.worldB);
        iter = *(BtlUnit**)(DAT_007ce3ec + 0x154);
        for (; iter != NULL; iter = iter->prev)
        {
            FUN_0027ffb0_b71e0(iter, (RwV3d*)work.tmp);
            FUN_002d1de0_b71e0(&work.quat, (RwV3d*)work.tmp, &work.worldA);
            FUN_0027f680_b71e0(iter, &work.quat);
        }
        iter = *(BtlUnit**)(DAT_007ce3ec + 0x15c);
        for (; iter != NULL; iter = iter->prev)
        {
            FUN_0027ffb0_b71e0(iter, (RwV3d*)work.tmp);
            FUN_002d1de0_b71e0(&work.quat, (RwV3d*)work.tmp, &work.worldB);
            FUN_0027f680_b71e0(iter, &work.quat);
        }
        *(s16*)(DAT_007ce3ec + 0xa38) = (s16)result;
        *(s16*)(DAT_007ce3ec + 0xa3a) = FUN_002d4e10_b71e0(2, 0x80000);
    }
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
#pragma alias DAT_00960178_abs DAT_00960178
#pragma alias DAT_0096017c_abs DAT_0096017c
#pragma alias PTR_DAT_00696f30_abs PTR_DAT_00696f30
#pragma alias PTR_s_battle_effect_ATC_D_BED_abs PTR_s_battle_effect_ATC_D_BED_00696c80
#pragma alias PTR_FUN_006975e0_abs PTR_FUN_006975e0


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

// FUN_002b77ac
void FUN_002b77ac(void)
{
}

// FUN_002b77c0 NONMATCHING


void FUN_002b77c0(int param_1)
{
  int iVar1;
  int iVar3;
  u32 uVar4;
  u16 uVar3;
  u32 uVar5;
  u8 uVar6;
  u8 *base;
  float afStack_10 [3];
  undefined1 auStack_20 [16];
  undefined1 auStack_30 [16];

  if (*(char *)(param_1 + 0x9f0) < '\0') {
    base = DAT_007ce3ec;
    uVar5 = (u32)*(u16 *)(base + 0xa38);
    uVar6 = *(u8 *)(param_1 + 0xa2);
    switch (uVar6) {
    case 0:
      uVar3 = 0;
      iVar3 = uVar5 * 0xe0 + 0x694f10;
      goto cond;
inc:
      uVar3 = uVar3 + 1;
cond:
      uVar4 = (u32)uVar3;
      if (*(u8 *)(iVar3 + uVar4 * 0x18) != '\0') {
        switch (uVar6) {
        case 0:
          iVar1 = *(int *)(base + uVar4 * 4 + 0xa3c);
          break;
        case 1:
          iVar1 = *(int *)(base + uVar4 * 4 + 0xa4c);
          break;
        }
        if (iVar1 != 1) goto found;
      }
      if (uVar3 < 4) goto inc;
found:
      iVar3 = (u32)uVar3 * 0x18;
      iVar1 = (uVar5 & 0xffff) * 0xe0;
      afStack_10[0] = *(float *)(iVar3 + iVar1 + 0x694f14);
      afStack_10[2] = *(float *)(iVar3 + iVar1 + 0x694f18);
      FUN_002d2280((s16 *)(param_1 + 0x94),(s16 *)(param_1 + 0x96),afStack_10);
      FUN_0027f650(param_1,afStack_10);
      switch (*(u8 *)(param_1 + 0xa2)) {
      case 0:
        *(undefined4 *)(uVar4 * 4 + (int)DAT_007ce3ec + 0xa3c) = 1;
        break;
      case 1:
        *(undefined4 *)(uVar4 * 4 + (int)DAT_007ce3ec + 0xa4c) = 1;
        break;
      }
      *(char *)(param_1 + 0x9f0) = (char)uVar3;
      FUN_00280870(2,1,auStack_20,0,0,1);
      FUN_0027ffb0(param_1,afStack_10);
      FUN_002d1de0(auStack_30,(const RwV3d*)afStack_10,(const RwV3d*)auStack_20);
      FUN_0027f680(param_1,auStack_30);
      break;
    case 1:
      break;
    }
  }
  return;
}

// FUN_002b79d4
void FUN_002b79d4(void)
{
}

// FUN_002b79e0

undefined4 FUN_002b79e0(int *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  RwV3d diff;
  RwV3d pos;
  f32 out[3];

  iVar1 = *param_1;
  iVar2 = param_1[1];
  FUN_00280390(iVar2,iVar1,out);
  diff.x = *(float *)(iVar1 + 4) - out[0];
  diff.y = 0.0f;
  diff.z = *(float *)(iVar1 + 0xc) - out[2];
  FUN_004c69f0(&diff,&diff);
  if ((diff.x == 0.0f) && (diff.z == 0.0f)) {
    return 1;
  }
  {
    iVar3 = FUN_00288da0(iVar2,9);
    fVar4 = (*(float *)(param_1 + 2)) - (float)(int)*(short *)(iVar3 + 4) * *(float *)(iVar2 + 0x2c);
    diff.x = diff.x * fVar4;
    diff.y = diff.y * fVar4;
    diff.z = diff.z * fVar4;
    if ((*(u16 *)(param_1 + 3) & 1) != 0) {
      pos.x = *(float *)(iVar1 + 4) + diff.x;
      pos.y = *(float *)(iVar1 + 8) + diff.y;
      pos.z = *(float *)(iVar1 + 0xc) + diff.z;
      FUN_0027f650(iVar1,&pos);
      iVar1 = *(int *)(iVar1 + 0xa00);
      if (iVar1 != 0) {
        pos.x = *(float *)(iVar1 + 4) + diff.x;
        pos.y = *(float *)(iVar1 + 8) + diff.y;
        pos.z = *(float *)(iVar1 + 0xc) + diff.z;
        FUN_0027f650(iVar1,&pos);
      }
    }
    if ((*(u16 *)(param_1 + 3) & 2) != 0) {
      pos.x = *(float *)(iVar2 + 4) + diff.x;
      pos.y = *(float *)(iVar2 + 8) + diff.y;
      pos.z = *(float *)(iVar2 + 0xc) + diff.z;
      FUN_0027f650(iVar2,&pos);
    }
  }
  return 1;
}

// FUN_002b7bd0

void FUN_002b7bd0(u32 param_1,u32 param_2,float param_3,u16 param_4)
{
  u32 *work;
  u32 packet;

  packet = FUN_0027ec10(0xb00,0x10);
  *(code **)(packet + 0x6c) = (code *)FUN_002b79e0;
  work = *(u32 **)(packet + 0x78);
  work[0] = param_1;
  work[1] = param_2;
  *(float *)(work + 2) = param_3;
  *(u16 *)(work + 3) = param_4;
}

#pragma opt_propagation off
#pragma opt_lifetimes reset
// FUN_002b7c50 NONMATCHING

u32 FUN_002b7c50(u32 *work)
{
    u32 *work_p = work;
    BtlAction *action;
    BtlAction *targetAction;
    BtlUnit *source;
    BtlUnit *unit;
    BtlUnit *target;
    BtlUnit *persona;
    BtlUnit *iter;
    BtlUnit *next;
    u16 specificId;
    u32 index;
    s32 moved;
    s32 relation;
    s16 tableIndex;
    s16 relation2;
    s32 result;
    f32 radius;
    f32 radius2;
    f32 distance;
    f32 distance2;
    f32 limit;
    f32 scale;
    f32 factor;
    RwV3d center;
    RwV3d targetCenter;
    f32 centerY;
    RwV3d direction;
    RwV3d transformed;
    RwV3d delta;
    RwV3d candidate;
    RwV3d iterCenter;
    RwV3d nearestCenter;
    f32 candidateY;
    RwV3d workPos;
    f32 query2[2];
    f32 source2[2];
    f32 projected2[2];
    f32 offset2[2];
    RtQuat rotation;

    action = *(BtlAction **)work_p;
    specificId = action->target.specificId;
    switch (action->unit->genus)
    {
    case 0:
        unit = action->unit;
        FUN_002d6370((s16)specificId);
        if (FUN_002d6290((int)unit) == 1)
        {
            targetAction = action->target.targetedActions[0];
            if (action == targetAction)
            {
                return 1;
            }
            source = action->unit;
            target = targetAction->unit;
            persona = source->personaUnit;
            if (FUN_002fdd40(source, target) != 0)
            {
                *(u32 *)(DAT_007ce3ec + 0xc) |= 0x400000;
                *(u16 *)(DAT_007ce3ec + 0x18) |= 0xe;
            }
            btlUnitGetSphereWorldCenter(source, &center);
            FUN_002802d0_b64d0(target, source, &targetCenter);
            centerY = source->pos.y;
            center.y = centerY;
            if ((work_p[2] == 1) && (target != source) &&
                (FUN_002fdcf0((int)(uintptr_t)source, (int)(uintptr_t)target) != 0))
            {
                if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0)
                {
                    btlUnitGetSphereWorldCenter(target, &candidate);
                    FUN_002d1de0(&rotation, &candidate, &center);
                    scale = target->scale;
                    workPos.x = target->sphereCenter.x * scale;
                    workPos.y = target->sphereCenter.y * scale;
                    workPos.z = target->sphereCenter.z * scale;
                    FUN_004be1e0(&transformed, &workPos, 1, &rotation);
                    workPos.x = candidate.x - transformed.x;
                    workPos.y = candidate.y - transformed.y;
                    workPos.z = candidate.z - transformed.z;
                    candidateY = target->pos.y;
                    workPos.y = candidateY;
                    candidate.y = candidateY;
                    btlUnitSetPos(target, &workPos);
                    FUN_002d1de0(&rotation, &workPos, &source->pos);
                    btlUnitSetRot(target, &rotation);
                    nearestCenter = candidate;
                }
                else
                {
                    FUN_002d1de0(&rotation, &targetCenter, &center);
                    btlUnitSetRot(target, &rotation);
                }
                btlUnitStopRotating(target);
                FUN_00288110(target);
            }
            if (work_p[1] == 1)
            {
                direction.x = center.x - targetCenter.x;
                direction.z = center.z - targetCenter.z;
                direction.y = 0.0f;
                radius = RwV3dNormalize(&direction, &direction);
                radius2 = source->sphereRadius * source->scale;
                factor = 0.0f;
                moved = 0;
                if (persona != NULL)
                {
                    tableIndex = (s16)specificId;
                    moved = FUN_002d63b0((int)(uintptr_t)persona,
                                         (s16)tableIndex, 1);
                    relation = (s16)FUN_00284040(persona, source,
                                                 (s64)tableIndex, 1);
                    radius = radius - radius2;
                    if (moved == 0)
                    {
                        relation2 = FUN_00284040(persona, source,
                                                 (s64)(s16)specificId, 1);
                        if ((relation2 == 3) || (relation2 == 1))
                        {
                            FUN_0027f940(persona, source, target,
                                         (s64)(s16)relation,
                                         &workPos, 0, 1);
                        }
                        else if ((relation2 == 2) || (relation2 == 0))
                        {
                            FUN_0027f940(persona, source, target,
                                         (s64)(s16)relation,
                                         &workPos, 0, 0);
                        }
                    }
                    else
                    {
                        FUN_0027f940(persona, source, target,
                                     (s64)(s16)relation,
                                     &workPos, 0, 2);
                    }
                    direction.x = workPos.x - targetCenter.x;
                    direction.z = workPos.z - targetCenter.z;
                    direction.y = 0.0f;
                    radius2 = persona->sphereRadius * persona->scale;
                    distance = RwV3dNormalize(&direction, &direction) - radius2;
                    if (moved == 0)
                    {
                        if ((distance + radius2) <=
                            source->sphereRadius * source->scale + radius)
                        {
                            delta.x = center.x - workPos.x;
                            delta.y = center.y - workPos.y;
                            delta.z = center.z - workPos.z;
                            factor = RwV3dNormalize(&delta, &delta);
                            radius2 = distance;
                            radius = distance;
                        }
                    }
                    else
                    {
                        radius2 = persona->sphereRadius * persona->scale;
                        FUN_0027f940(persona, source, NULL, -1,
                                     &workPos, 0, 0);
                        workPos.x = center.x;
                        workPos.y = center.y;
                        delta.x = center.x - center.x;
                        delta.y = center.y - center.y;
                        delta.z = workPos.z - targetCenter.z;
                        factor = RwV3dLength(&delta);
                        radius = distance;
                        if ((factor + distance + radius2) <= radius)
                        {
                            factor = 0.0f;
                            radius = radius;
                        }
                        else
                        {
                            radius = distance;
                        }
                    }
                }
                limit = target->sphereRadius * target->scale;
                radius = radius - limit;
                if (radius < 300.0f)
                {
                    radius = 300.0f;
                    moved = 1;
                }
                if (moved != 0)
                {
                    factor = radius + radius2 + limit + factor;
                    direction.x = direction.x * factor;
                    direction.y = direction.y * factor;
                    direction.z = direction.z * factor;
                    workPos.x = targetCenter.x + direction.x;
                    workPos.y = centerY + direction.y;
                    workPos.z = targetCenter.z + direction.z;
                    btlUnitSetPos(source, &workPos);
                }
            }
        }
        else if ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0)
        {
            source = action->unit;
            if (work_p[2] == 1)
            {
                index = 0;
                while ((index & 0xffff) < action->target.targetedCount)
                {
                    targetAction = action->target.targetedActions[index & 0xffff];
                    if ((targetAction->unk_1a & 1) != 0 && targetAction != action)
                    {
                        target = targetAction->unit;
                        FUN_002d1de0(&rotation, &target->pos,
                                     &source->pos);
                        btlUnitSetRot(target, &rotation);
                        btlUnitStopRotating(target);
                        FUN_00288110(target);
                    }
                    index = (index + 1) & 0xffff;
                }
            }
            btlUnitGetSphereWorldCenter(source, &center);
            FUN_00280870(2, 0, &targetCenter, 0, 0, 1);
            centerY = source->pos.y;
            center.y = centerY;
            nearestCenter = targetCenter;
            factor = 0.0f;
            moved = 1;
            workPos = targetCenter;
            workPos.y = centerY;
            iter = *(BtlUnit **)(DAT_007ce3ec + 0x15c);
            while (iter != NULL)
            {
                if ((iter->flags3 & 8) != 0)
                {
                    FUN_002802d0_b64d0(iter, source, &iterCenter);
                    query2[0] = iterCenter.x;
                    query2[1] = iterCenter.z;
                    source2[0] = targetCenter.x;
                    source2[1] = targetCenter.z;
                    FUN_002d1fd0(query2, source2, query2, projected2);
                    offset2[0] = query2[0] - projected2[0];
                    offset2[1] = query2[1] - projected2[1];
                    distance = RwV2dLength((RwV2d *)offset2);
                    if ((distance < factor) || (moved != 0))
                    {
                        nearestCenter.x = projected2[0];
                        nearestCenter.z = projected2[1];
                        factor = distance;
                        moved = 0;
                    }
                }
                iter = iter->prev;
            }
            if (factor - source->sphereRadius * source->scale < 300.0f)
            {
                direction.x = center.x - nearestCenter.x;
                direction.y = center.y - nearestCenter.y;
                direction.z = center.z - nearestCenter.z;
                RwV3dNormalize(&direction, &direction);
                limit = factor + source->sphereRadius * source->scale + 300.0f;
                direction.x = direction.x * limit;
                direction.y = direction.y * limit;
                direction.z = direction.z * limit;
                workPos.x = nearestCenter.x + direction.x;
                workPos.y = nearestCenter.y + direction.y;
                workPos.z = nearestCenter.z + direction.z;
                btlUnitSetPos(source, &workPos);
            }
        }
        else if ((*(u32 *)(DAT_007ce3ec + 0x10) & 0x80) != 0)
        {
            iter = *(BtlUnit **)(DAT_007ce3ec + 0x154);
            while (iter != NULL)
            {
                if ((iter->flags3 & 8) != 0)
                {
                    FUN_0027f7c0(iter, &workPos, 0, 0);
                    workPos.z += 200.0f;
                    btlUnitSetPos(iter, &workPos);
                }
                iter = iter->prev;
            }
            *(u32 *)(DAT_007ce3ec + 0xc) |= 0x400000;
            *(u16 *)(DAT_007ce3ec + 0x18) |= 6;
        }
        break;
    default:
        break;
    case 1:
        if ((action->target.targetedCount != 1) &&
            ((*(u32 *)(DAT_007ce3ec + 0xc) & 0x200000) == 0) &&
            ((result = FUN_002d1600((int)&action->target)) & 0xffff) == 1)
        {
            moved = 0;
            source = action->unit;
            btlUnitGetSphereWorldCenter(source, &center);
            radius = source->sphereRadius * source->scale;
            if (work_p[2] == 1)
            {
                FUN_00280870(result, 1, &targetCenter, 0, 0, 1);
                nearestCenter = targetCenter;
                factor = 0.0f;
                index = 0;
                while ((index & 0xffff) < action->target.targetedCount)
                {
                    targetAction = action->target.targetedActions[index & 0xffff];
                    if ((targetAction->unk_1a & 1) != 0)
                    {
                        target = targetAction->unit;
                        FUN_00280050_typed(target, &candidate);
                        direction.x = targetCenter.x - candidate.x;
                        direction.y = center.y - candidate.y;
                        direction.z = targetCenter.z - candidate.z;
                        distance = RwV3dLength(&direction);
                        if (!(distance <= factor))
                        {
                            nearestCenter = candidate;
                            factor = distance;
                        }
                    }
                    index = (index + 1) & 0xffff;
                }
                FUN_002d1de0(&rotation, &center, &nearestCenter);
                btlUnitSetRot(source, &rotation);
                btlUnitStopRotating(source);
                FUN_00288110(source);
            }
            iter = *(BtlUnit **)(DAT_007ce3ec + 0x154);
            while (iter != NULL)
            {
                if ((iter->flags3 & 8) != 0)
                {
                    FUN_002802d0_b64d0(iter, source, &iterCenter);
                    direction.x = iterCenter.x - center.x;
                    direction.z = iterCenter.z - center.z;
                    direction.y = 0.0f;
                    distance = RwV3dNormalize(&direction, &direction);
                    limit = gp0xffff80e0 * (distance - radius) + radius;
                    if ((limit < distance) && !(limit <= 300.0f))
                    {
                        workPos.x = direction.x * limit;
                        workPos.y = direction.y * limit;
                        workPos.z = direction.z * limit;
                        workPos.x = center.x + workPos.x;
                        workPos.y = center.y + workPos.y;
                        workPos.z = center.z + workPos.z;
                        workPos.y = 0.0f;
                        btlUnitSetPos(iter, &workPos);
                        moved = 1;
                    }
                }
                iter = iter->prev;
            }
            if (moved != 0)
            {
                *(u32 *)(DAT_007ce3ec + 0xc) |= 0x400000;
                *(u16 *)(DAT_007ce3ec + 0x18) |= 0x1e;
            }
        }
        break;
    }
    return 1;
}

// FUN_002b8900

void FUN_002b8900(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = FUN_0027ec10(0xb01,0xc);
  *(code **)(iVar2 + 0x6c) = (code *)FUN_002b7c50;
  puVar1 = *(undefined4 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_3;
  return;
}

// FUN_002b8970
void LAB_002b8970(u32 *work)
{
  u8 *unit;

  unit = (u8 *)*work;
  (*(u16 *)(unit + 0xa0))++;
}

// FUN_002b8990 NONMATCHING

undefined4 FUN_002b8990(undefined4 *param_1)
{
  undefined4 uVar2;
  undefined4 uVar3;
  s16 uVar1;
  int bVar4;
  s16 uVar5;
  short sVar6;
  u32 lVar7;
  undefined1 auStack_20 [16];
  undefined1 auStack_10 [16];
  
  uVar2 = *param_1;
  uVar3 = *(undefined4 *)(param_1[1] + 0x30);
  uVar1 = *(s16 *)(param_1 + 3);
  bVar4 = param_1[2] != 0;
  uVar5 = FUN_00284040(uVar2,uVar3,uVar1,bVar4);
  lVar7 = FUN_002d63b0(uVar2,uVar1,bVar4);
  if (lVar7 == 0) {
    sVar6 = FUN_00284040(uVar2,uVar3,uVar1,bVar4);
    if ((sVar6 == 3) || (sVar6 == 1)) {
      FUN_0027f940(uVar2,uVar3,0,uVar5,auStack_20,auStack_10,1);
    }
    else if ((sVar6 == 2) || (sVar6 == 0)) {
      FUN_0027f940(uVar2,uVar3,0,uVar5,auStack_20,auStack_10,0);
    }
    FUN_0027f680(uVar2,auStack_10);
    FUN_0027f650(uVar2,auStack_20);
  }
  else {
    FUN_0027f940(uVar2,uVar3,*(undefined4 *)(param_1[2] + 0x30),uVar5,auStack_20,auStack_10,2);
    FUN_0027f680(uVar2,auStack_10);
    FUN_0027f650(uVar2,auStack_20);
  }
  return 1;
}

// FUN_002b8b50
void LAB_002b8b50(u32 *work)
{
  u8 *unit;

  unit = (u8 *)*work;
  (*(u16 *)(unit + 0xa0))--;
}

// FUN_002b8b70

void FUN_002b8b70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = FUN_0027ec10(0xb02,0x10);
  *(undefined1 **)(iVar2 + 0x68) = (undefined1*)LAB_002b8970;
  *(code **)(iVar2 + 0x6c) = (code *)FUN_002b8990;
  *(undefined1 **)(iVar2 + 0x70) = (undefined1*)LAB_002b8b50;
  puVar1 = *(undefined4 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_3;
  *(undefined2 *)(puVar1 + 3) = param_4;
  return;
}


// FUN_002b8c00

undefined4 FUN_002b8c00(u16 *param_1)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  u32 m1;
  u32 b1;
  u32 b2;
  u32 uVar5;
  undefined1 auStack_10 [16];
  undefined1 auStack_20 [16];

  uVar1 = *param_1;
  uVar2 = param_1[1];
  uVar5 = 0;
  m1 = uVar2 & 0x8000;
  b1 = uVar2 & 1;
  b2 = uVar2 & 2;

  for (; uVar5 < 4; uVar5 = uVar5 + 1) {
    if ((uVar1 & (1 << uVar5)) != 0) {
      for (iVar3 = *(int *)(iGpffffb6fc + uVar5 * 8 + 0x150); iVar3 != 0;
          iVar3 = *(int *)(iVar3 + 0xa34)) {
        if (((*(u32 *)(iVar3 + 0x9c) & 4) != 0) &&
           ((m1 == 0) || (FUN_00281270(iVar3) == 0))) {
          FUN_0027f7c0((BtlUnit*)(uintptr_t)iVar3,(RwV3d*)auStack_10,(void*)auStack_20,0);
          if (b1 != 0) {
            FUN_0027f650(iVar3,auStack_10);
            FUN_00281290(iVar3);
            FUN_002d4040((BtlUnit*)(uintptr_t)iVar3);
          }
          if (b2 != 0) {
            FUN_0027f680(iVar3,auStack_20);
            FUN_002812b0(iVar3);
            FUN_00288110((BtlUnit*)(uintptr_t)iVar3);
          }
        }
      }
    }
  }
  return 1;
}
#pragma opt_loop_invariants reset

// FUN_002b8d60
BtlPacket* btlFormation002b8d60(s32 param_1, u32 flags)
{
    BtlPacket* packet;
    BtlFormationPacket002b8d60* work;

    packet = btlPacketCreate(BTLFORMATION_PACKET_UNK03, sizeof(BtlFormationPacket002b8d60));

    packet->updateFunc = btlFormation002b8c00;

    work = (BtlFormationPacket002b8d60*)packet->workData;

    work->unk_00 = param_1;
    work->flags = flags;

    return packet;
}
#pragma opt_propagation reset

// FUN_002b8dc0 MATCHING

u32 func_002b8dc0(u16* flags)
{
  BtlAction* currentAction;
  BtlUnit* unit;
  float distance;
  RwV3d position;
  RwV3d reference;
  RwV3d direction;

  currentAction = (BtlAction*)func_0029ad20_u32();
  func_002b71e0();
  if ((*flags & 1) != 0) {
    for (unit = *(BtlUnit **)(iGpffffb6fc + 0x150); unit != NULL; unit = unit->next) {
      if (func_00300580_u32((u32)unit->datUnit, 0x180271) == 0 &&
          func_0030b5a0_u32((u32)unit->datUnit, 0) == 0) {
        if (currentAction->unit == unit) {
          distance = 250.0f;
        } else {
          distance = 350.0f;
        }
        btlUnit0027f7c0(unit, &position, NULL, &reference);
        reference.y = position.y;
        direction.x = position.x - reference.x;
        direction.y = position.y - reference.y;
        direction.z = position.z - reference.z;
        RwV3dNormalize(&direction, &direction);
        direction.x *= distance;
        direction.y *= distance;
        direction.z *= distance;
        position.x += direction.x;
        position.y += direction.y;
        position.z += direction.z;
        btlUnitSetPos(unit, &position);
      }
    }
  }
  return 1;
}

// FUN_002b8f40
BtlPacket* btlFormation002b8f40(s32 param_1)
{
    BtlPacket* packet;
    BtlFormationPacket002b8f40* work;

    packet = btlPacketCreate(BTLFORMATION_PACKET_UNK04, sizeof(BtlFormationPacket002b8f40));

    packet->updateFunc = btlFormation002b8dc0;

    work = (BtlFormationPacket002b8f40*)packet->workData;

    work->unk_00 = param_1;

    return packet;
}

// FUN_002b8f90

u32 func_002b8f90(u16 param_1)
{
  BtlFormationState *state;

  state = (BtlFormationState *)(*DAT_00960178_abs)(0x638,0x40000);
  switch (param_1) {
  case 0:
    state->flags = 0;
    break;
  case 1:
    state->flags = 0;
    break;
  case 2:
    state->flags = 8;
    break;
  }
  state->counter = 1;
  state->value = 0;
  return (u32)state;
}

// FUN_002b9030

void func_002b9030(u32 param_1)
{
  BtlFormationState *state;

  state = (BtlFormationState *)param_1;
  state->counter--;
  if (((state->flags & 8) != 0) && (state->counter == 1)) {
    func_002b9220((int)state);
  }
  if (state->counter == 0) {
    if ((state->flags & 2) != 0) {
      func_002b9220((int)state);
    }
    (*DAT_0096017c)(state);
  }
  return;
}

#pragma alias func_0027ffb0_v3d func_0027ffb0
#pragma alias func_00318ed0_v3d func_00318ed0

// FUN_002b90d0

void func_002b90d0(int destination, u32 source)
{
  u16 outer;
  u16 index;
  s32 count;
  u8* entry;
  int block;
  u8* referencedEntry;
  u32 packed;
  u32 resource;
  u32 continueLoop;

  func_00521250(destination, source, 0x630);
  outer = 0;
  while ((s32)(continueLoop = outer) < 2) {
    block = destination + (outer & 0xffff) * 0x314;
    count = *(u16 *)(block + 0x10);
    entry = (u8 *)(block + 0x1c);
    for (index = 0; index < count; index++) {
      if (entry[0] != 0xfe) {
        if (entry[0] == 0xff) {
          packed = *(u32 *)(entry + 4);
          referencedEntry = (u8 *)(destination + (packed >> 5) * 0x314 +
                                      (packed & 0x1f) * 0x18 + 0x1c);
          resource = func_00325920_u32(*(u32 *)(referencedEntry + 4));
          entry[0] = referencedEntry[0];
        } else {
          resource = func_00324bd0_u32(source + *(u32 *)(entry + 4));
        }
        *(u32 *)(entry + 4) = resource;
      }
      entry += 0x18;
    }
    outer++;
  }
  *(u16 *)(destination + 0x630) |= 2;
}

// FUN_002b9220

void func_002b9220(int state)
{
  u16 outer;
  u16 index;
  int count;
  u8 *entry;
  int block;
  u32 continueLoop;

  outer = 0;
  while ((s32)(continueLoop = outer) < 2) {
    block = state + (outer & 0xffff) * 0x314;
    count = *(u16 *)(block + 0x10);
    entry = (u8 *)(block + 0x1c);
    index = 0;
    while (index < count) {
      if (*entry != 0xfe && *entry != 0xfd) {
        func_003257e0(*(u32 *)(entry + 4));
      }
      entry += 0x18;
      index++;
    }
    outer++;
  }
  *(u16 *)(state + 0x630) &= 0xfffd;
}

// FUN_002b9300

void func_002b9300(int param_1)
{
  extern void func_002b90d0(int,u32);
  BtlFormationState *state;

  state = (BtlFormationState *)param_1;
  state->counter++;
  if (((state->flags & 8) != 0) && (state->counter == 2)) {
    func_002b90d0(param_1,state->value);
  }
  return;
}

// FUN_002b9350

bool func_002b9350(int param_1)

{
  return (*(u16 *)(param_1 + 0x630) & 2) != 0;
}

// FUN_002b9370

u32 func_002b9370(int param_1,u16 param_2)
{
  u32 result;

  switch (param_2) {
  case 0:
    result = *(u32 *)(param_1 + 8);
    break;
  case 1:
    result = *(u32 *)(param_1 + 0x328);
    break;
  default:
    result = 0;
    break;
  }
  return result;
}

// FUN_002b93c0

u32 func_002b93c0(int param_1,u16 param_2)

{
  int iVar1 = (param_2 & 0xffff) * 0x314;
  return *(u32 *)(iVar1 + param_1 + 0xc);
}
// FUN_002b93e0

u32 func_002b93e0(u32 param_1,u16 param_2,u32 param_3,u32 param_4,u32 param_5)
{
  extern void func_00521408(void *,u32,u32);
  u8 random;
  u32 result;
  u32 size;
  BtlFormationWork *work;

  size = *(u16 *)((u8 *)(uintptr_t)((u32)param_2 * 0x314) +
                  (uintptr_t)param_1 + 0x10) * 4 + 0x5c;
  result = (*DAT_00960178_abs)(size,0x40000);
  func_00521408((void *)result,0,size);
  work = (BtlFormationWork *)result;
  work->state = param_1;
  work->list = (u32)(uintptr_t)((u8 *)(uintptr_t)param_1 +
                                (u32)param_2 * 0x314 + 8);
  work->count = *(u16 *)((u8 *)(uintptr_t)work->list + 8);
  work->items = (u32)((u8 *)work + 0x5c);
  work->sentinel = -1;
  work->argument3 = param_3;
  work->argument4 = param_4;
  work->argument5 = param_5;
  if (param_2 == 1) {
    random = func_002ffbc0(100);
    work->random = random;
  }
  return result;
}


/* W322 probe: func_002ba0f0 with opt_common_subs off improved normalized_diff 389 -> 372 (object 680/688). */
// FUN_002b94f0

void func_002b94f0(BtlFormationWork *work)
{
  s32 count;
  u16 index;
  u32 *items;

  count = work->count;
  items = (u32 *)(uintptr_t)work->items;
  index = 0;
  while (index < count) {
    if (*items != 0) {
      func_003257e0(*items);
    }
    items++;
    index++;
  }
  (*DAT_0096017c)(work);
}

// FUN_002b9590 MATCHING

float func_002b9590(int param_1)
{
  float fVar1 = 0;

  fVar1 = fGpffff8398 * ((*(float *)(param_1 + 0x90) * *(float *)(param_1 + 0x2c) +
          *(float *)(param_1 + 0x8c) * *(float *)(param_1 + 0x2c) * 0.5f) * 0.5f);
  if (fVar1 > 2.5f) {
    fVar1 = 2.5f;
  }
  else if (fVar1 < fGpffff839c) {
    fVar1 = fGpffff839c;
  }
  return fVar1;
}

// FUN_002b9600

void func_002b9600(u32 *param_1)

{
  u32 uVar1 = 0;
  u32 uVar2 = 0;
  u32 *puVar4;
  int iVar3 = 0;
  
  puVar4 = (u32 *)(uintptr_t)DAT_00957100_abs;
  iVar3 = 8;
  do {
    uVar1 = *param_1;
    uVar2 = param_1[1];
    param_1 = param_1 + 2;
    iVar3 = iVar3 + -1;
    *puVar4 = uVar1;
    puVar4[1] = uVar2;
    puVar4 = puVar4 + 2;
  } while (0 < iVar3);
  return;
}

// FUN_002b9640

u32 func_002b9640(int param_1)

{
  u16 uVar1 = 0;
  u32 uVar2 = 0;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    uVar2 = uVar2 | 0x80;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    uVar2 = uVar2 | 1;
  }
  uVar1 = *(u16 *)(param_1 + 4);
  if ((uVar1 & 0x400) != 0) {
    uVar2 = uVar2 | 2;
  }
  if ((uVar1 & 0x100) != 0) {
    uVar2 = uVar2 | 4;
  }
  if ((uVar1 & 4) != 0) {
    uVar2 = uVar2 | 0x10;
  }
  if ((uVar1 & 2) != 0) {
    uVar2 = uVar2 | 8;
  }
  if ((*(u16 *)(param_1 + 6) & 2) != 0) {
    uVar2 = uVar2 | 0x20;
  }
  if ((*(u16 *)(param_1 + 6) & 4) != 0) {
    uVar2 = uVar2 | 0x40;
  }
  return uVar2;
}


// FUN_002b96e0

void func_002b96e0(int param_1,u32 param_2)

{
  *(u32 *)(param_1 + 0x634) = param_2;
  return;
}

// FUN_002b96f0 NONMATCHING

void func_002b96f0(float param_1,float param_2,float *param_3,u32 *param_4,int param_5,
                   u32 param_6)
{
  u8 bVar1 = *(u8 *)(param_5 + 2);
  float fVar3 = 0.0f;
  float fStack_10[4];
  float uStack_20[4];
  float vectorWork[4];
  float origin[4];
  u8 *out = (u8 *)(u32)param_6;

  if (*(u8 *)(param_5 + 1) == 4) {
    if (bVar1 == 8) {
      fVar3 = param_1;
      if (*(short *)(param_5 + 4) == 0) {
        fVar3 = 2.0f;
      }
    }
    else {
      fVar3 = 2.0f;
    }
  }
  else {
    fVar3 = param_2 * *(float *)(&DAT_00696440 + (u32)*(u8 *)(param_5 + 1) * 4) +
            param_3[1] + 0.0f;
    if ((bVar1 == 8) && (*(short *)(param_5 + 4) != 0)) {
      fVar3 += param_1;
    }
  }

  if ((bVar1 == 10) || (bVar1 == 9)) {
    float scale;
    u32 scaleBits;

    func_003297a0(origin);
    __asm__ volatile (
        ".set noreorder          \n"
        "lqc2 vf10, 0(%0)        \n"
        ".set reorder"
        :
        : "r" (origin)
        : "vf10", "memory"
    );
    if (param_1 >= param_2) {
      param_2 = param_1;
    }
    scale = -param_2;
    *(RwV4d*)origin = *(RwV4d*)param_3;
    if (bVar1 != 9) {
      origin[1] = fVar3;
    }
    __asm__ volatile (
        ".set noreorder          \n"
        "lqc2 vf11, 0(%0)        \n"
        "vsub.xyz vf11, vf11, vf10\n"
        ".set reorder"
        :
        : "r" (origin)
        : "vf11", "memory"
    );
    if (bVar1 == 10) {
      __asm__ volatile (
          ".set noreorder          \n"
          "sqc2 vf11, 0(%0)        \n"
          ".set reorder"
          :
          : "r" (vectorWork)
          : "memory"
      );
      *(u32 *)&vectorWork[1] = 0;
      __asm__ volatile (
          ".set noreorder          \n"
          "lqc2 vf11, 0(%0)        \n"
          ".set reorder"
          :
          : "r" (vectorWork)
          : "vf11", "memory"
      );
    }
    __asm__ volatile (
        ".set noreorder             \n"
        "vmul.xyz vf2, vf11, vf11   \n"
        "vmulax.w ACC, vf0, vf2x    \n"
        "vmadday.w ACC, vf0, vf2y   \n"
        "vmaddz.w vf2, vf0, vf2z    \n"
        "vrsqrt Q, vf0w, vf2w       \n"
        "vwaitq                     \n"
        "vmulq.xyz vf11, vf11, Q    \n"
        "mfc1 %0, %1                \n"
        "nop                        \n"
        "qmtc2.ni %0, vf2           \n"
        "vmulx.xyzw vf11, vf11, vf2x\n"
        "lqc2 vf10, 0(%2)           \n"
        "vadd.xyzw vf10, vf10, vf11 \n"
        "sqc2 vf10, 0(%3)           \n"
        ".set reorder"
        : "=r" (scaleBits)
        : "f" (scale), "r" (origin), "r" (out)
        : "vf2", "vf10", "vf11", "ACC", "Q", "memory"
    );
  }
  else if (bVar1 == 8) {
    *(float *)out = *param_3;
    *(float *)(out + 4) = fVar3;
    *(float *)(out + 8) = param_3[2];
  }
  else {
    uStack_20[0] = *(float *)param_4;
    uStack_20[1] = *((float *)param_4 + 1);
    uStack_20[2] = *((float *)param_4 + 2);
    uStack_20[3] = *((float *)param_4 + 3);
    func_004bdde0(*(float *)(&DAT_00696460 + (u32)bVar1 * 4),uStack_20,(const void *)0x697880,2);
    func_004be1e0(fStack_10,(const void *)0x697890,1,uStack_20);
    *(float *)out = *param_3 + fStack_10[0] * param_1;
    *(float *)(out + 4) = fVar3 + fStack_10[1] * param_1;
    *(float *)(out + 8) = param_3[2] + fStack_10[2] * param_1;
  }
  *(u32 *)(out + 0xc) = 0;
}

// FUN_002b99d0

void func_002b99d0(u8 *param_1,int param_2,u16 *param_3,u32 *param_4)

{
  s32 uVar1;
  u32 param3Local, param4Local;
  float fVar2;
  float fVar3;
  RwV3d output;
  RwV3d scaled;
  RwV3d transformed;
  
  param3Local = (u32)param_3;
  param4Local = (u32)param_4;
  uVar1 = *(u16 *)((int)param3Local + 4);
  if (uVar1 == 0) {
    fVar2 = *(float *)(param_1 + 0x30) * *(float *)(param_2 + 0x2c);
  }
  else {
    fVar2 = (float)uVar1;
  }
  fVar3 = *(float *)(param_1 + 0x2c) * *(float *)(param_2 + 0x2c) * 0.5f;
  scaled.x = *(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x50);
  scaled.y = *(float *)(param_1 + 0x24) * *(float *)(param_1 + 0x50);
  scaled.z = *(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x50);
  func_004be1e0(&transformed,&scaled,1,(u8 *)param_1 + 0x40);
  output.x = transformed.x + *(float *)(param_1 + 0x34);
  output.y = transformed.y + *(float *)(param_1 + 0x38);
  output.z = transformed.z + *(float *)(param_1 + 0x3c);
  func_002b96f0(fVar2,fVar3,(float *)&output,(u32 *)(param_1 + 0x40),(int)param3Local,param4Local);
  return;
}

// FUN_002b9b00

void func_002b9b00(u8 *param_1, int param_2, int param_3, float *param_4)
{
  s32 result;
  u16 index;
  RwV3d position;
  RwV3d scaled;
  RwV3d transformed;

  if ((*(u32*)(param_2 + 0x98) & 2) == 0) {
    func_0027ffb0_v3d(param_2, &position);
  }
  else {
    index = *(u16*)(param_3 + 4);
    result = func_00318ed0_v3d(
        *(u32*)(param_2 + 0x9f4), index, &position);
    if (result == 0) {
      scaled.x = *(f32*)(param_1 + 0x20) * *(f32*)(param_1 + 0x50);
      scaled.y = *(f32*)(param_1 + 0x24) * *(f32*)(param_1 + 0x50);
      scaled.z = *(f32*)(param_1 + 0x28) * *(f32*)(param_1 + 0x50);
      func_004be1e0(&transformed, &scaled, 1, param_1 + 0x40);
      position.x = transformed.x + *(f32*)(param_1 + 0x34);
      position.y = transformed.y + *(f32*)(param_1 + 0x38);
      position.z = transformed.z + *(f32*)(param_1 + 0x3c);
    }
  }
  param_4[0] = position.x;
  param_4[1] = position.y;
  param_4[2] = position.z;
}

// FUN_002b9c00

void func_002b9c00(int param_1,int param_2,int param_3,float *param_4)

{
  s32 result;
  u16 index;
  u32 model;
  u32 model_variant;
  RwV3d position;
  RwV3d scaled;
  RwV3d transformed;

  if ((*(u32*)(param_2 + 0x98) & 2) == 0) {
    func_0027ffb0_v3d(param_2, &position);
  }
  else {
    model = *(u32*)(param_2 + 0x9f4);
    model_variant = *(u32*)(model + 0x3c4);
    if (model_variant == 0) {
      model_variant = model;
    }
    func_003176c0((Model*)model_variant);
    func_00318b90(model_variant);
    index = *(u16*)(param_3 + 4);
    result = func_00318ed0_v3d(model_variant, index, &position);
    if (result == 0) {
      scaled.x = *(f32*)(param_1 + 0x20) * *(f32*)(param_1 + 0x50);
      scaled.y = *(f32*)(param_1 + 0x24) * *(f32*)(param_1 + 0x50);
      scaled.z = *(f32*)(param_1 + 0x28) * *(f32*)(param_1 + 0x50);
      func_004be1e0(&transformed, &scaled, 1,
          (void*)((u8*)param_1 + 0x40));
      position.x = transformed.x + *(f32*)(param_1 + 0x34);
      position.y = transformed.y + *(f32*)(param_1 + 0x38);
      position.z = transformed.z + *(f32*)(param_1 + 0x3c);
    }
  }
  param_4[0] = position.x;
  param_4[1] = position.y;
  param_4[2] = position.z;
}

// FUN_002b9d40

void func_002b9d40(int param_1,int param_2,int param_3,float *param_4)
{
  s32 result;
  u16 index;
  u32 model;
  u32 model_variant;
  RwV3d position;
  RwV3d scaled;
  RwV3d transformed;

  if ((*(u32*)(param_2 + 0x98) & 2) == 0) {
    func_0027ffb0_v3d(param_2, &position);
  }
  else {
    model = *(u32*)(param_2 + 0x9f4);
    model_variant = *(u32*)(model + 0x3b8);
    if (model_variant == 0) {
      model_variant = model;
    }
    func_003176c0((Model*)model_variant);
    func_00318b90(model_variant);
    index = *(u16*)(param_3 + 4);
    result = func_00318ed0_v3d(model_variant, index, &position);
    if (result == 0) {
      scaled.x = *(f32*)(param_1 + 0x20) * *(f32*)(param_1 + 0x50);
      scaled.y = *(f32*)(param_1 + 0x24) * *(f32*)(param_1 + 0x50);
      scaled.z = *(f32*)(param_1 + 0x28) * *(f32*)(param_1 + 0x50);
      func_004be1e0(&transformed, &scaled, 1,
          (void*)((u8*)param_1 + 0x40));
      position.x = transformed.x + *(f32*)(param_1 + 0x34);
      position.y = transformed.y + *(f32*)(param_1 + 0x38);
      position.z = transformed.z + *(f32*)(param_1 + 0x3c);
    }
  }
  param_4[0] = position.x;
  param_4[1] = position.y;
  param_4[2] = position.z;
}

// FUN_002b9e80

void func_002b9e80(u64 param_1,u64 param_2,u32 param_3,u32 param_4)

{
  s32 uVar1;
  float fVar2;
  struct {
    u32 uStack_20;
    u32 uStack_1c;
    u32 uStack_18;
    u32 uStack_14;
    float auStack_10[3];
    float fStack_4;
  } work;
  
  fVar2 = func_00280870_btlFormation_f32(3,0,work.auStack_10,&work.fStack_4,0,0);
  uVar1 = *(u16 *)((int)param_3 + 4);
  if (uVar1 == 0) {
    __asm__ ("" : "+f"(fVar2));
  }
  else {
    fVar2 = (float)uVar1;
  }
  work.uStack_14 = 0x3f800000;
  work.uStack_20 = 0;
  work.uStack_1c = 0;
  work.uStack_18 = 0;
  func_002b96f0(fVar2,work.fStack_4 * 0.5f,work.auStack_10,&work.uStack_20,param_3,param_4);
  return;
}

// FUN_002b9f30

void func_002b9f30(u64 param_1,int param_2,u32 param_3,u32 param_4)

{
  s32 uVar1;
  u16 uVar2;
  float fVar3;
  struct {
    u32 uStack_20;
    u32 uStack_1c;
    u32 uStack_18;
    u32 uStack_14;
    float auStack_10[3];
    float fStack_4;
  } work;
  
  if (*(u8 *)(param_2 + 0xa2) == '\0') {
    uVar2 = 1;
  }
  else {
    uVar2 = 2;
  }
  fVar3 = func_00280870_btlFormation_f32(uVar2,0,work.auStack_10,&work.fStack_4,0,0);
  uVar1 = *(u16 *)((int)param_3 + 4);
  if (uVar1 == 0) {
    __asm__ ("" : "+f"(fVar3));
  }
  else {
    fVar3 = (float)uVar1;
  }
  work.uStack_14 = 0x3f800000;
  work.uStack_20 = 0;
  work.uStack_1c = 0;
  work.uStack_18 = 0;
  func_002b96f0(fVar3,work.fStack_4 * 0.5f,work.auStack_10,&work.uStack_20,param_3,param_4);
  return;
}

// FUN_002ba000

void func_002ba000(u64 param_1,int param_2,u32 param_3,u32 param_4)

{
  s32 uVar1;
  u16 uVar2;
  float fVar3;
  struct {
    u32 uStack_20;
    u32 uStack_1c;
    u32 uStack_18;
    u32 uStack_14;
    float auStack_10[3];
    float fStack_4;
  } work;
  
  if (*(u8 *)(param_2 + 0xa2) == '\0') {
    uVar2 = 2;
  }
  else {
    uVar2 = 1;
  }
  fVar3 = func_00280870_btlFormation_f32(uVar2,0,work.auStack_10,&work.fStack_4,0,0);
  uVar1 = *(u16 *)((int)param_3 + 4);
  if (uVar1 == 0) {
    __asm__ ("" : "+f"(fVar3));
  }
  else {
    fVar3 = (float)uVar1;
  }
  work.uStack_14 = 0x3f800000;
  work.uStack_20 = 0;
  work.uStack_1c = 0;
  work.uStack_18 = 0;
  func_002b96f0(fVar3,work.fStack_4 * 0.5f,work.auStack_10,&work.uStack_20,param_3,param_4);
  return;
}

// FUN_002ba0d0
void func_002ba0d0(u32 param_1,u32 param_2,u32 param_3,u32 *param_4)
{
  param_4[0] = 0;
  param_4[1] = 0;
  param_4[2] = 0;
  param_4[3] = 0;
}

#pragma opt_common_subs off
// FUN_002ba0f0 NONMATCHING

void func_002ba0f0(int param_1,int param_2,u8 *param_3,u8 (*param_4) [16])

{
  int iVar1 = 0;
  long lVar3 = 0;
  u32 uVar4 = 0;
  RwV4d transform[4];
  RwV4d source[4];
  RwV3d direction;
  
  switch(*param_3) {
  case '\0':
    func_004be1e0(&direction,(const void *)0x697890,1,(const void *)(param_1 + 0x40));
    if ((direction.x == 0.0f) && (direction.z == 0.0f)) {
      __asm__ volatile (
          ".set noreorder          \n"
          "sqc2 vf0, 0(%0)         \n"
          ".set reorder"
          :
          : "r" (param_4)
          : "memory"
      );
    }
    else {
      uVar4 = func_0052ea18(direction.x,direction.z);
      func_00357ea0(0,uVar4,0);
      __asm__ volatile (
          ".set noreorder          \n"
          "sqc2 vf10, 0(%0)         \n"
          ".set reorder"
          :
          : "r" (param_4)
          : "memory"
      );
    }
    break;
  case '\x01':
    if ((*(u32 *)(param_2 + 0x98) & 2) == 0) {
      __asm__ volatile (
          ".set noreorder          \n"
          "sqc2 vf0, 0(%0)         \n"
          ".set reorder"
          :
          : "r" (param_4)
          : "memory"
      );
    }
    else {
      lVar3 = func_00318d10(*(u32 *)(param_2 + 0x9f4),*(u16 *)(param_3 + 4),source);
      if (lVar3 == 0) {
        __asm__ volatile (
            ".set noreorder          \n"
            "sqc2 vf0, 0(%0)         \n"
            ".set reorder"
            :
            : "r" (param_4)
            : "memory"
        );
      }
      else {
        transform[0].x = source[0].x;
        transform[0].y = source[0].y;
        transform[0].z = source[0].z;
        transform[0].w = 0.0f;
        transform[1].x = source[1].x;
        transform[1].y = source[1].y;
        transform[1].z = source[1].z;
        transform[1].w = 0.0f;
        transform[2].x = source[2].x;
        transform[2].y = source[2].y;
        transform[2].z = source[2].z;
        transform[2].w = 0.0f;
        transform[3].x = source[3].x;
        transform[3].y = source[3].y;
        transform[3].z = source[3].z;
        transform[3].w = 0.0f;
        func_00329ed0(transform);
        __asm__ volatile (
            ".set noreorder          \n"
            "sqc2 vf10, 0(%0)         \n"
            ".set reorder"
            :
            : "r" (param_4)
            : "memory"
        );
      }
    }
    break;
  case '\x02':
  case '\x03':
  case '\x04':
  case '\f':
    __asm__ volatile (
        ".set noreorder          \n"
        "sqc2 vf0, 0(%0)         \n"
        ".set reorder"
        :
        : "r" (param_4)
        : "memory"
    );
    break;
  case '\a':
  case '\n':
  case '\v':
    __asm__ volatile (
        ".set noreorder          \n"
        "sqc2 vf0, 0(%0)         \n"
        ".set reorder"
        :
        : "r" (param_4)
        : "memory"
    );
    break;
  case '\b':
  case '\t':
    if ((*(u32 *)(param_2 + 0x98) & 2) == 0) {
      __asm__ volatile (
          ".set noreorder          \n"
          "sqc2 vf0, 0(%0)         \n"
          ".set reorder"
          :
          : "r" (param_4)
          : "memory"
      );
    }
    else {
      iVar1 = *(int *)(*(int *)(param_2 + 0x9f4) + 0x3b8 + (u32)(*param_3 == '\b') * 0xc);
      if (iVar1 != 0) {
        lVar3 = func_00318d10(iVar1,*(u16 *)(param_3 + 4),source);
        if (lVar3 == 0) {
          __asm__ volatile (
              ".set noreorder          \n"
              "sqc2 vf0, 0(%0)         \n"
              ".set reorder"
              :
              : "r" (param_4)
              : "memory"
          );
        }
        else {
          transform[0].x = source[0].x;
          transform[0].y = source[0].y;
          transform[0].z = source[0].z;
          transform[0].w = 0.0f;
          transform[1].x = source[1].x;
          transform[1].y = source[1].y;
          transform[1].z = source[1].z;
          transform[1].w = 0.0f;
          transform[2].x = source[2].x;
          transform[2].y = source[2].y;
          transform[2].z = source[2].z;
          transform[2].w = 0.0f;
          transform[3].x = source[3].x;
          transform[3].y = source[3].y;
          transform[3].z = source[3].z;
          transform[3].w = 0.0f;
          func_00329ed0(transform);
          __asm__ volatile (
              ".set noreorder          \n"
              "sqc2 vf10, 0(%0)         \n"
              ".set reorder"
              :
              : "r" (param_4)
              : "memory"
          );
        }
      }
    }
  }
  return;
}
#pragma opt_common_subs reset





























































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







































/* Recovered battle-misc support prelude */
#pragma alias FUN_002b0280_legacy FUN_002b0280
#pragma alias FUN_002a3820_u32 FUN_002a3820
#pragma alias FUN_004c31b0_typed FUN_004c31b0
 #pragma alias FUN_002a3e80_ab330 FUN_002a3e80
#pragma alias FUN_002a3e80_side FUN_002a3e80
#pragma alias FUN_00280050_typed FUN_00280050
#pragma alias FUN_002a3520_result FUN_002a3520
#pragma alias FUN_002fdbb0_result FUN_002fdbb0
#pragma alias FUN_002a3520_s32 FUN_002a3520
#pragma alias FUN_002a3550_s32 FUN_002a3550
/* Target-local ABI aliases for FUN_002b3980. */
#pragma alias FUN_002a3e80_action FUN_002a3e80
/* b6070 exact call signatures */
#pragma alias FUN_00300580_b6070 FUN_00300580
#pragma alias FUN_00280130_b6070 FUN_00280130
#pragma alias FUN_004be1e0_b6070 FUN_004be1e0
#pragma alias FUN_004c31b0_b6070 FUN_004c31b0
#pragma alias FUN_004c69f0_b6070 FUN_004c69f0
#pragma alias FUN_004c6c60_b6070 FUN_004c6c60
#pragma alias FUN_002a4690_b6070 FUN_002a4690
#pragma alias FUN_002a2290_b6070 FUN_002a2290
#pragma alias FUN_002a3110_b6070 FUN_002a3110
#pragma alias FUN_002a3160_typed FUN_002a3160

#pragma alias FUN_002d1f30_b21f0v2 FUN_002d1f30
#pragma alias FUN_00280130_b21f0v2 FUN_00280130
#pragma alias FUN_004c69f0_b21f0v2 FUN_004c69f0
#pragma alias FUN_004c6b20_b21f0v2 FUN_004c6b20
#pragma alias func_00280870_ae740 func_00280870
#pragma alias FUN_002c0880_ae740 FUN_002c0880
#pragma alias FUN_002a3850_ae740 FUN_002a3850
#pragma alias FUN_004be310_ae740 FUN_004be310
#pragma alias FUN_004c6b20_ae740 FUN_004c6b20
#pragma alias FUN_004be1e0_ae740 FUN_004be1e0
#pragma alias FUN_004c69f0_ae740 FUN_004c69f0
#pragma alias FUN_00280050_ae740 FUN_00280050
#pragma alias FUN_002a2170_ae740 FUN_002a2170
#pragma alias FUN_004be1e0_typed FUN_004be1e0
#pragma alias FUN_004be310_typed FUN_004be310
#pragma alias FUN_004c6b20_typed FUN_004c6b20
#pragma alias FUN_002d1f30_typed FUN_002d1f30














/* This no-argument declaration is caller-specific; the state-table callback uses a camera pointer. */






/* Retail camera callbacks for the 0x2A4C70-0x2A95D0 window.  The original
 * routines share the same unit framing and look-at path; the callbacks keep
 * that state typed while remaining NONMATCHING until instruction scheduling
 * is tuned against the retail object. */

























// The near-window candidate still differs in saved-register layout and long-lived
// temporary coloring; declaration and access-order probes were codegen-neutral.
// Keep this marker NONMATCHING until those register lifetimes are reconstructed.
/* W367 measured: opt_dead_assignments off + opt_lifetimes on nd2376 -> 2221, object 3276/3296; baseline object 3288/3296. */



/* Retail camera recovery for the 0x2b02xx-0x2b8cxx slice.  The bodies below
 * retain the complete branch/data flow recovered from the executable; all
 * entries remain NONMATCHING until instruction scheduling is cleaned up. */

#ifndef CONCAT44
#endif
/* Broad K&R declarations preserve this function's retail call ABI; typed callers below narrow them locally. */

#pragma alias FUN_002a4470_b280 FUN_002a4470
#pragma alias FUN_0027ffb0_b280 FUN_0027ffb0
#pragma alias FUN_002a4690_b280 FUN_002a4690
#pragma alias FUN_004be1e0_b280 FUN_004be1e0
#pragma alias FUN_004c69f0_b280 FUN_004c69f0
#pragma alias FUN_004c6b20_b280 FUN_004c6b20
#pragma alias FUN_002d1fd0_b280 FUN_002d1fd0
#pragma alias FUN_002d1f30_b280 FUN_002d1f30
#pragma alias FUN_002a2170_b280 FUN_002a2170
#pragma alias FUN_002a2290_b280 FUN_002a2290
#pragma alias FUN_002a3110_b280 FUN_002a3110
#pragma alias FUN_002a3e80_b280 FUN_002a3e80
#pragma alias FUN_002d5bf0_b280 FUN_002d5bf0
#pragma alias FUN_003093a0_b280 FUN_003093a0
#pragma alias FUN_0052e930_b280 FUN_0052e930

#pragma opt_lifetimes reset
#pragma opt_dead_assignments reset
/* W367 measured: opt_propagation off nd2626 -> 2579, object 3264/3488; baseline object 3364/3488. */



#pragma opt_dead_assignments off
#pragma opt_propagation reset

#pragma opt_dead_assignments reset









/* W383 floor, measured.  The whole nd12 residual is three adjacent lwc1 pairs at
 * +284/+300/+316: retail loads the SUBTRAHEND (scratch.targetCenter, sp+0xF0) before
 * the minuend (scratch.sourceCenter, sp+0xE0) in each component; we emit them the
 * other way round.  Registers and every other word are identical, so this is the
 * classic reordered-adjacent-loads case.  The volatile-cast technique needs a staging
 * temporary to express the order, and that temporary costs 12 bytes: both variants
 * (subtrahend-only volatile, and both-operands volatile) measured 1384/1376 nd653 --
 * OVER the 1376-byte window.  Plain non-volatile temporaries are byte-neutral (the
 * load sinks back to its use), a whole-vector temp gives 1408/1376 nd782, and all of
 * scheduling on/off, optimize_for_size and the six opt_* knobs are neutral or worse
 * (common_subs off 1616/nd1145, propagation off and dead_assignments off both nd796).
 * Window-blocked: there is no room to buy the ordering.  Keep 1372/1376 nd12. */



















#pragma alias FUN_002b4db0_float FUN_002b4db0

















#pragma alias FUN_002d1de0_b64d0 FUN_002d1de0
#pragma alias FUN_002802d0_b64d0 FUN_002802d0
#pragma alias FUN_004be1e0_b64d0 FUN_004be1e0
#pragma alias FUN_00280130_b64d0 FUN_00280130
#pragma alias FUN_00280200_b64d0 FUN_00280200
#pragma alias FUN_004c6c60_b64d0 FUN_004c6c60
#pragma alias FUN_002b6bd0_b64d0 FUN_002b6bd0
#pragma alias FUN_002a2290_b64d0 FUN_002a2290
#pragma alias FUN_002a3110_b64d0 FUN_002a3110











/* Removing this loses FUN_002b7060 (MATCH nd0 -> MISMATCH nd81) - measured W161. */
// FUN_002ba3a0 NONMATCHING

void func_002ba3a0(int param_1)

{
  char cVar1;
  u32 uVar2;
  int iVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  bool bVar7;
  short *psVar8;
  int *piVar10;
  char *pcVar11;
  int *piVar12;
  u32 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  float fVar17;
  float fVar18;
  u8 auStack_40[16];
  u8 auStack_30[16];
  u8 auStack_20[16];
  u8 auStack_10[16];
  
  piVar10 = (int *)param_1;
  iVar3 = piVar10[6];
  uVar4 = piVar10[4];
  uVar5 = piVar10[2];
  if (((uVar5 & 0x800) == 0) && ((uVar4 & 0xff000000) != 0)) {
    uVar6 = piVar10[3];
    if ((uVar6 == 0) ||
       ((((uVar5 & 0x1000) != 0 && (uVar6 == *(u32 *)(*piVar10 + 800))) || ((uVar5 & 0x100) != 0)))
       ) {
      psVar8 = (short *)func_002fc520((BtlUnit *)iVar3);
      if (psVar8 != 0) {
        *(float *)(piVar10 + 8) = (float)*psVar8;
        *(float *)(piVar10 + 9) = (float)psVar8[1];
        *(float *)(piVar10 + 10) = (float)psVar8[2];
        *(float *)(piVar10 + 0xb) = (float)(u16)psVar8[3];
        *(float *)(piVar10 + 0xc) = (float)(u16)psVar8[4];
      }
      else {
        iVar14 = *(int *)(iVar3 + 0x84);
        iVar15 = *(int *)(iVar3 + 0x88);
        *(RwV3d*)(piVar10 + 8) = *(RwV3d*)(iVar3 + 0x80);
        piVar10[0xb] = *(int *)(iVar3 + 0x8c);
        piVar10[0xc] = *(int *)(iVar3 + 0x90);
      }
      *(RwV3d*)(piVar10 + 0xd) = *(RwV3d*)(iVar3 + 4);
      if (iVar3 == piVar10[7]) {
        *(RwV4d*)(piVar10 + 0x10) = *(RwV4d*)(iVar3 + 0x1c);
      }
      else if ((*(char *)(iVar3 + 0xa2) == *(char *)(piVar10[7] + 0xa2)) &&
              (*(char *)(iVar3 + 0xa2) == '\x01')) {
        *(RwV4d*)(piVar10 + 0x10) = *(RwV4d*)(iVar3 + 0x1c);
      }
      else {
        func_0027ffb0(iVar3,auStack_10);
        func_0027ffb0(piVar10[7],auStack_20);
        func_002d1de0(piVar10 + 0x10,auStack_10,auStack_20);
      }
      piVar10[0x14] = *(int *)(iVar3 + 0x2c);
    }
    func_00352c30(piVar10[6],piVar10[7]);
    piVar12 = (int *)piVar10[0x16];
    uVar2 = *(u16 *)(piVar10 + 0x15);
    pcVar11 = (char *)(piVar10[1] + 0x14);
    for (uVar13 = 0; uVar13 < uVar2; uVar13 = uVar13 + 1) {
      if ((*(u32 *)(pcVar11 + 0x10) < uVar6) && (*pcVar11 != -2)) {
        if (*piVar12 == 0) {
          if (((*(u16 *)(*piVar10 + 0x630) & 4) == 0) || (*pcVar11 == -3)) {
            iVar14 = func_00325920_u32(*(u32 *)(pcVar11 + 4));
            *piVar12 = iVar14;
            bVar7 = true;
          }
          else {
            *piVar12 = *(int *)(pcVar11 + 4);
            bVar7 = false;
            *pcVar11 = -3;
          }
          if (((*(char *)(piVar10[1] + 0x10) != '\0') && (iVar3 != 0)) &&
             ((cVar1 = pcVar11[8], cVar1 == '\a' ||
              (((cVar1 == '\x06' || (cVar1 == '\x01')) || (cVar1 == '\0')))))) {
            fVar18 = fGpffff839c;
            if (*(char *)(piVar10[1] + 0x10) == '\x01') {
              fVar17 = fGpffff8398 *
                       (*(float *)(iVar3 + 0x90) * *(float *)(iVar3 + 0x2c) +
                       *(float *)(iVar3 + 0x8c) * *(float *)(iVar3 + 0x2c) * 0.5f) * 0.5f;
              if (2.5f < fVar17) {
                fVar18 = 2.5f;
              }
              else if (fGpffff839c <= fVar17) {
                fVar18 = fVar17;
              }
            }
            else {
              iVar14 = piVar10[7];
              fVar17 = fGpffff8398 *
                       (*(float *)(iVar14 + 0x90) * *(float *)(iVar14 + 0x2c) +
                       *(float *)(iVar14 + 0x8c) * *(float *)(iVar14 + 0x2c) * 0.5f) * 0.5f;
              if (2.5f < fVar17) {
                fVar18 = 2.5f;
              }
              else if (fGpffff839c <= fVar17) {
                fVar18 = fVar17;
              }
            }
            func_00325e40(fVar18,*piVar12);
          }
          if (bVar7) goto LAB_002ba8a0;
        }
        if ((*(short *)(pcVar11 + 0xe) == 0) ||
           (((piVar10[2] & 0x1eU) == 0 && (0x31 < *(u8 *)(piVar10 + 5))))) {
          (*(PTR_FUN_00696490)[(u8)pcVar11[8]])(param_1,iVar3,pcVar11 + 8,auStack_30);
          func_00325c10(*piVar12,auStack_30);
          func_002ba0f0(param_1,iVar3,(u8 *)pcVar11 + 8,&auStack_40);
          func_00325d60(*piVar12,auStack_40);
          func_00326030(*piVar12,uVar4);
          func_003252a0(*piVar12);
        }
      }
LAB_002ba8a0:
      pcVar11 = pcVar11 + 0x18;
      piVar12 = piVar12 + 1;
    }
    piVar10[3] = piVar10[3] + 1;
  }
  return;
}
// FUN_002ba900

void func_002ba900(int param_1)
{
  extern u16 func_00321130(void);
  u16 count;
  u32 savedState;
  int *entries;
  s32 limit;

  if ((*(u32 *)(param_1 + 8) & 0x400) == 0) {
    entries = *(int **)(param_1 + 0x58);
    count = *(u16 *)(param_1 + 0x54);
    if ((*(u32 *)(param_1 + 8) & 0x8000) == 0) {
      u16 index;
      index = 0;
      limit = count;
      while (index < limit) {
        if (*entries != 0) func_00325500(*entries);
        index++;
        entries++;
      }
    } else {
      u16 index;
      savedState = func_00321130();
      func_00321320(DAT_00957100_abs);
      func_00321120(4);
      index = 0;
      limit = count;
      while (index < limit) {
        if (*entries != 0) func_00325500(*entries);
        index++;
        entries++;
      }
      func_00321120(savedState);
    }
  }
}

// FUN_002baa20

void func_002baa20(int *param_1)
{
  extern void func_002b90d0(int,u32);
  extern u32 func_00100d80(u32,u32);
  BtlFormationState *state;

  state = (BtlFormationState *)*param_1;
  state->counter++;
  if (((state->flags & 8) != 0) && (state->counter == 2)) {
    func_002b90d0((int)state,state->value);
  }
  if ((*(u16 *)(param_1 + 3) & 1) == 0) {
    param_1[1] = func_00100d80(param_1[2],0);
  } else {
    param_1[1] = 0;
  }
  state->flags |= 1;
  return;
}

// FUN_002baad0 MATCHING

u32 func_002baad0(int* data)
{
  FormationLoadWork* work;
  BtlFormationState* state;
  u32 result;
  u32 resource;
  u8 output[4];

  work = (FormationLoadWork*)data;
  state = work->state;
  if (work->request == 0) {
    work->request = func_00100d80_u32(work->source, 0);
  }
  if (func_001016b0_u32(work->request) != 0) {
    resource = func_001021c0_u32(work->source, output);
    func_002b90d0((int)state, resource);
    func_00100ec0(work->request);
    state->flags &= 0xfffe;
    state->flags |= 2;
    state->counter--;
    if ((state->flags & 8) != 0 && state->counter == 1) {
      func_002b9220((int)state);
    }
    if (state->counter == 0) {
      if ((state->flags & 2) != 0) {
        func_002b9220((int)state);
      }
      (*DAT_0096017c_abs)(state);
    }
    result = 1;
  } else {
    result = 0;
  }
  return result;
}

// FUN_002bac00 MATCHING

u32 func_002bac00(u32 param_1,u32 param_2,u16 param_3)
{
  typedef struct FormationStringWork {
    u32 value;
    u32 unused;
    char *text;
    u16 field;
    u16 padding;
  } FormationStringWork;
  BtlPacket *packet;
  FormationStringWork *work;

  packet = btlPacketCreate(0x400, func_00524388(param_2) + sizeof(FormationStringWork));
  packet->unk_47 &= 0xfe;
  packet->initFunc = (BtlPacketInitFunc)func_002baa20;
  packet->updateFunc = (BtlPacketUpdateFunc)func_002baad0;
  work = packet->workData;
  work->value = param_1;
  work->text = (char *)(work + 1);
  work->field = param_3;
  func_00524270(work->text, param_2);
  return (u32)packet;
}

// FUN_002bacb0

void func_002bacb0(u32 *param_1)

{
  u32 uVar1 = 0;
  
  param_1[6] = 0;
  func_002b9300(*param_1);
  *(u16 *)(param_1[1] + 0xa0) = *(u16 *)(param_1[1] + 0xa0) + 1;
  *(u16 *)(param_1[2] + 0xa0) = *(u16 *)(param_1[2] + 0xa0) + 1;
  switch (*(short *)(param_1 + 3)) {
  case 0:
    param_1[5] = *(u32 *)(param_1[1] + 0x9fc);
    break;
  case 1:
    param_1[5] = *(u32 *)(param_1[2] + 0x9fc);
    break;
  }
  uVar1 = (u32)func_002bb9c0(param_1[5]);
  param_1[4] = uVar1;
  return;
}

/* W421 classification: baseline verify nd3 at 344/352 (rate 0.008721).
 * At +180 ours lw $v0,0x1c($s3) versus retail lw $t0,0x1c($s3);
 * at +184 ours andi $v1,$v0,0xc00 versus retail andi $v1,$t0,0xc00.
 * These are load-destination/register-role differences, not an operand
 * swap.  Flag aliases measured nd11 at 344/352 (rate 0.031977);
 * pointer/volatile variants measured nd126 at 348/352 (rate 0.362069)
 * and nd127 at 352/352 (rate 0.360795); declaration-only variants stayed
 * nd3. */
// FUN_002bad60 NONMATCHING

u32 func_002bad60(u32 *param_1)

{
  short sVar1;
  u16 *puVar2;
  int iVar3;
  u16 functionIndex;
  u32 unaff_s2_lo;
  u32 unaff_s1_lo;
  
  if (func_002b9350_u32(*param_1) == 0)
    return 0;
  puVar2 = (u16 *)param_1[4];
    if ((*(u32 *)(puVar2 + 2) & 0xff000000) == 0) {
      return 1;
    }
    else {
      functionIndex = *(volatile u16 *)(param_1 + 3);
      iVar3 = func_002b9370(*param_1,functionIndex);
      if ((*puVar2 & 0x40) == 0) {
        if ((int)param_1[6] >= iVar3 * 2 + -0xd) {
          *puVar2 = *puVar2 | 0x100;
          return 0;
        }
        if (param_1[6] == 0) {
          u32 flags = param_1[7];
          if ((flags & 0xc00) != 0xc00) {
          sVar1 = *(short *)(param_1 + 3);
          switch (sVar1) {
          case 0:
            unaff_s2_lo = param_1[1];
            unaff_s1_lo = param_1[2];
            break;
          case 1:
            unaff_s2_lo = param_1[2];
            unaff_s1_lo = param_1[1];
            break;
          }
          *(u32 *)(puVar2 + 8) =
              func_002b93e0_4arg(*param_1,sVar1,unaff_s2_lo,unaff_s1_lo);
          *puVar2 = *puVar2 | 0x30;
        }
          }
        param_1[6] = param_1[6] + 2;
      }
    }
  return 0;
}

#pragma opt_lifetimes reset
/* W367 measured: opt_propagation off nd2117 -> 2094, object 3236/3248; baseline object 3248/3248. */
// FUN_002baec0

bool func_002baec0(u32 *param_1)
{
  int iVar2;
  u16 index;
  u32 value;
  volatile /* Removing this function's qualifier batch loses func_002baec0 (MATCH nd0 -> MISMATCH nd6, size 112 -> 112) - measured W170. */ u16 *index_ptr;
  volatile /* Removing this function's qualifier batch loses func_002baec0 (MATCH nd0 -> MISMATCH nd6, size 112 -> 112) - measured W170. */ u32 *value_ptr;
  
  if (!func_002b9350(*param_1)) {
    return false;
  }
  index_ptr = (volatile /* Removing this function's qualifier batch loses func_002baec0 (MATCH nd0 -> MISMATCH nd6, size 112 -> 112) - measured W170. */ u16 *)(param_1 + 3);
  value_ptr = (volatile /* Removing this function's qualifier batch loses func_002baec0 (MATCH nd0 -> MISMATCH nd6, size 112 -> 112) - measured W170. */ u32 *)param_1;
  iVar2 = (index = *index_ptr,
           value = *value_ptr,
           func_002b93c0(value,index));
  iVar2 <<= 1;
  if (iVar2 < 1) {
    iVar2 = 2;
  }
  return iVar2 <= (int)param_1[6];
}

// FUN_002baf30

void func_002baf30(u32 *param_1)

{
  func_002bbac0(param_1[5],(u16 *)param_1[4]);
  func_002b9030(*(int *)param_1);
  *(u16 *)(param_1[1] + 0xa0) = *(u16 *)(param_1[1] + 0xa0) + -1;
  *(u16 *)(param_1[2] + 0xa0) = *(u16 *)(param_1[2] + 0xa0) + -1;
  return;
}

// FUN_002baf90

void func_002baf90(u32 param_1,u32 param_2,u32 param_3,u16 param_4,
                 u32 param_5)

{
  u32 *puVar1;
  int iVar2 = 0;
  
  iVar2 = func_0027ec10(0x301,0x20);
  *(u8 *)(iVar2 + 0x47) = *(u8 *)(iVar2 + 0x47) & 0xef;
  *(code *)(iVar2 + 0x68) = (code)func_002bacb0;
  *(code *)(iVar2 + 0x6c) = (code)func_002bad60;
  *(code *)(iVar2 + 0x74) = (code)func_002baec0;
  *(code *)(iVar2 + 0x70) = (code)func_002baf30;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_3;
  *(u16 *)(puVar1 + 3) = param_4;
  puVar1[7] = param_5;
  return;
}

#pragma opt_propagation reset
// FUN_002bb050

void func_002bb050(u32 *param_1)

{
  u32 uVar1 = 0;
  
  param_1[7] = 0;
  func_002b9300(*param_1);
  *(u16 *)(param_1[1] + 0xa0) = *(u16 *)(param_1[1] + 0xa0) + 1;
  uVar1 = (u32)func_002bb9c0(*(u32 *)(param_1[1] + 0x9fc));
  param_1[6] = uVar1;
  return;
}

// FUN_002bb0b0 NONMATCHING

u32 func_002bb0b0(u32 *param_1)

{
  u16 *puVar1;
  int iVar2 = 0;
  u32 uVar3 = 0;
  long lVar4 = 0;
  
  if (func_002b9350(*param_1) == 0) {
    uVar3 = 0;
  }
  else {
    puVar1 = (u16 *)param_1[6];
    if ((*(u32 *)(puVar1 + 2) & 0xff000000) == 0) {
      uVar3 = 1;
    }
    else {
      if ((*puVar1 & 0x40) == 0) {
        if ((*(u16 *)(param_1 + 8) & 0x4000) != 0) {
          iVar2 = param_1[7] + 1;
        }
        else {
          iVar2 = func_002b9370(*param_1,0);
          iVar2 = iVar2 << 1;
        }
        if ((((param_1[2] != 0) && (param_1[2] * 2 + -0xd <= (int)param_1[7])) ||
            ((*(long *)(param_1 + 4) != 0 &&
             (lVar4 = func_0027e310(*(long *)(param_1 + 4),0x3fffffffffffffff), lVar4 == 0)))) ||
           ((iVar2 != 0 && (iVar2 <= (int)param_1[7])))) {
          if ((*(u16 *)(param_1 + 8) & 0x2000) != 0) {
            *(u8 *)(param_1[6] + 8) = 4;
          }
          *(u16 *)param_1[6] = *(u16 *)param_1[6] | 0x100;
          return 0;
        }
        if (param_1[7] == 0) {
          uVar3 = func_002b93e0(*param_1,0,param_1[1],param_1[1],*(u16 *)(param_1 + 8));
          *(u32 *)(puVar1 + 8) = uVar3;
        }
        else if (param_1[7] == 2) {
          *puVar1 = *puVar1 | 0xb0;
          *(u32 *)(puVar1 + 2) = (u32)((u32)((long)*(int *)(puVar1 + 2) << 0x28) >> 0x28);
        }
        param_1[7] = param_1[7] + 2;
      }
      uVar3 = 0;
    }
  }
  return uVar3;
}

// FUN_002bb290

void func_002bb290(u32 *param_1)

{
  func_002bbac0(*(u32 *)(param_1[1] + 0x9fc),(u16 *)param_1[6]);
  func_002b9030(*(int *)param_1);
  *(u16 *)(param_1[1] + 0xa0) = *(u16 *)(param_1[1] + 0xa0) + -1;
  return;
}

// FUN_002bb2f0

void func_002bb2f0(u32 param_1,u32 param_2,u32 param_3,u64 param_4,
                 u16 param_5)

{
  u32 *puVar1;
  int iVar2 = 0;
  
  iVar2 = func_0027ec10(0x302,0x28);
  *(u8 *)(iVar2 + 0x47) = *(u8 *)(iVar2 + 0x47) & 0xef;
  *(code *)(iVar2 + 0x68) = (code)func_002bb050;
  *(code *)(iVar2 + 0x6c) = (code)func_002bb0b0;
  *(code *)(iVar2 + 0x70) = (code)func_002bb290;
  puVar1 = *(u32 **)(iVar2 + 0x78);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_3;
  *(u64 *)(puVar1 + 4) = param_4;
  *(u16 *)(puVar1 + 8) = param_5;
  return;
}

/* Camera-state work records use the retail 64-bit pair layout. */
#ifndef BTLCAMERA_GHIDRA_PAIR
#endif


// Restored five retail camera-frame quaternion calls omitted by the raw decompilation.
// These calls update the frame orientation in each camera-state path before final setup.
// The surrounding scalar temporaries remain structurally incomplete and are retained.
// The resulting object is intentionally still NONMATCHING while this reconstruction continues.
//


/* W367 measured: opt_lifetimes on + opt_propagation off nd3478 -> 3394, object 4308/4624; baseline object 4464/4624. */



/* Retail 0x2AC920 recovery: frame slots 0x20-0x158 hold the camera/target
 * poses, six world vectors, four 2-D helper pairs, and scalar intermediates.
 * Restored retail calls are at 0x4d8, 0x514, 0x52c, 0x604, 0x61c, and 0x62c. */



#pragma alias FUN_002a4470_c920 FUN_002a4470
#pragma alias FUN_002a44f0_c920 FUN_002a44f0
#pragma alias FUN_002a2290_c920 FUN_002a2290
#pragma alias FUN_002a3110_c920 FUN_002a3110

#pragma opt_propagation reset
#pragma opt_lifetimes reset
/* W367 measured: opt_propagation off nd1247 -> 1240, object 1632/1648; baseline object 1648/1648. */

/* W331: removing the immediately overwritten local store and disabling dead-assignment folding measured 1780B/nd889 baseline; 1772B/nd965 without the pragma; 1768B/nd551 with it (window 1776B). */
#pragma opt_dead_assignments off
#pragma opt_dead_assignments reset
#pragma opt_propagation reset











/* W367 measured: opt_propagation off nd797 -> 635, object 1044/1088; baseline object 1068/1088. */







/* W367 measured: opt_lifetimes on nd849 -> 848, object 2108/2112; baseline object 2108/2112. */

/* Retail 0x2AEF80-0x2AF7E0: retain the measured framing frame slots as real aggregates. */

#pragma opt_lifetimes reset
/* W367 measured: opt_lifetimes on + opt_propagation off nd1499 -> 1485, object 2060/2160; baseline object 2100/2160. */





#pragma opt_propagation reset

/* Recovered battle-misc harvest: 0x002A3A80-0x002A4C20 */






/* Recovered battle-misc harvest: 0x002A32F0-0x002A4690 */












/* W367 measured: opt_loop_invariants on nd279 -> 211, object 1052/1056; baseline object 1052/1056. */
