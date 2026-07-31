#include "Battle/btlFormation.h"
#include "Battle/btlAction.h"
#include "Battle/btlFade.h"
#include "Battle/btlUnit.h"
#include "Battle/battle.h"
#include "Battle/btlVoice.h"
#include "Battle/btlBoss.h"

extern u32 btlFormation002b8c00(void* work);
extern u32 btlFormation002b8dc0(void* work);

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







/* Retail formation reference recovery, retained NONMATCHING until codegen cleanup. */
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
extern u64 func_0021c3f0();
#pragma alias func_0021c3f0_u32 func_0021c3f0
extern u32 func_0021c3f0_u32(u32 param_1);
#pragma alias func_0021cca0_u32 func_0021cca0
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
extern u32 func_002d4e10();
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
extern u32 func_00306e80();
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
extern u64 func_00357ea0();
extern u64 func_0035ae10();
extern u64 func_0035bb40();
extern u64 func_0035c090();
extern u64 func_0035c1a0();
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
#pragma alias PTR_FUN_006975e0_abs PTR_FUN_006975e0
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


/* Target forward declarations. */
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
// Typed alias for callers that consume the helper's full 16-bit result.
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
// The caller passes two 32-bit resource identifiers.
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

#pragma alias func_0027ffb0_v3d func_0027ffb0
extern void func_0027ffb0_v3d(int unit, RwV3d* out);
#pragma alias func_00318ed0_v3d func_00318ed0
extern s32 func_00318ed0_v3d(u32 model, u32 index, RwV3d* out);

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
    func_003176c0(model_variant);
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
    func_003176c0(model_variant);
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


/* W322 probe: func_002ba0f0 with opt_common_subs off improved normalized_diff 389 -> 372 (object 680/688). */
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

typedef struct FormationLoadWork {
  BtlFormationState* state;
  u32 request;
  u32 source;
  u16 flags;
  u16 padding;
} FormationLoadWork;

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

// FUN_002bad60 NONMATCHING

u32 func_002bad60(u32 *param_1)

{
  short sVar1;
  u16 *puVar2;
  int iVar3;
  u16 functionIndex;
  u32 unaff_s2_lo;
  u32 unaff_s1_lo;
  u32 flags;
  u32 mask;
  
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
          flags = *(u32 *)(param_1 + 7);
          mask = flags & 0xc00;
          if (mask != 0xc00) {
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





























































/* Removing this loses FUN_002bde10 (MATCH nd0 -> MISMATCH nd119) - measured W161. */

/* W322 probe: func_002bdfb0 with opt_loop_invariants on improved normalized_diff 431 -> 373 (object 796/816). */





















extern u32 func_002c1ce0_u32(int param_1, int param_2);





















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
#pragma opt_rebuildconditionals reset




















/* W322 probe: func_002d03e0 with opt_loop_invariants on improved normalized_diff 190 -> 188 (object 472/480). */










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
